#include "SDKGenerator.h"
#include "Global.h"
#include "SDKTypes.h"
std::string GetTypeCppName(UEProperty prop);
void ProcessPackages(std::string path, bool oneFile);
bool ComparePropertyLess(const UEProperty& lhs, const UEProperty& rhs);
Package::Member CreateBitfieldPadding(size_t id, size_t offset, std::string type, size_t bits);
Package::Member CreatePadding(size_t id, size_t offset, size_t size, std::string reason);
std::string BuildMethodSignature(const Package::Method& m, const Package::Class& c, bool inHeader);


void SDKGenerator::DumpObjectsTxt(std::string path)
{
	Global::MainForm->progressBar1->Maximum = Global::Objects->GetObjectsNum();
	std::ofstream o(path + "ObjectsDump.txt");
	tfm::format(o, "%s\n", "By COHERENCE");
	for (int i = 0; i < Global::Objects->GetObjectsNum(); i++)
	{
		Global::MainForm->progressBar1->Value = i + 1;
		auto obj = Global::Objects->GetById(i);
		if (!obj.IsValid())
		{
			continue;
		}
		o << tfm::format("[%0x] %s\n", obj.GetAddress(), obj.GetFullName());
	}
	o.close();
}

void SDKGenerator::DumpSDK(std::string path,bool oneFile)
{
	ProcessPackages(path, oneFile);
}

void ProcessPackages(std::string path,bool oneFile)
{
	const auto sdkPath = path + "SDK";
	std::unordered_map<uint64_t, Package> packageObjects;
	Global::MainForm->progressBar1->Maximum = Global::Objects->GetObjectsNum();
	for (int i = 0; i < Global::Objects->GetObjectsNum(); i++)
	{
		auto obj = Global::Objects->GetById(i);
		Global::MainForm->progressBar1->Value = i + 1;
		if (obj.IsValid())
		{
			auto packageAddr = obj.GetPackageObject().GetAddress();
			packageObjects[packageAddr] = Package(packageAddr);
		}
	}
	Console::WriteLine("Packages Count: {0}", packageObjects.size());
	Global::MainForm->progressBar1->Maximum = Global::Objects->GetObjectsNum();
	for (int i = 0; i < Global::Objects->GetObjectsNum(); i++)
	{
		auto obj = Global::Objects->GetById(i);
		Global::MainForm->progressBar1->Value = i + 1;
		if (obj.IsValid())
		{
			auto packageAddr = obj.GetPackageObject().GetAddress();
			packageObjects[packageAddr].Process(obj);
		}
	}
	Global::MainForm->progressBar1->Maximum = (int)packageObjects.size();
	Global::MainForm->progressBar1->Value = 0;
	std::ofstream o;
	for (auto package : packageObjects)
	{
		if (oneFile&&!o.is_open())
		{
			o.open(path + "SDK_All.cpp", std::ofstream::out | std::ofstream::app);
		}
		if (!oneFile)
		{
			o.open(path + package.second.GetPackageName() + ".cpp", std::ofstream::out | std::ofstream::app);
		}
		package.second.Save(o);
		Global::MainForm->progressBar1->Value += 1;
		o.close();
	}
}

void Package::Process(UEObject obj)
{
	if (obj.IsA<UEEnum>())
	{
		GenerateEnum(obj.Cast<UEEnum>());
		return;
	}
	const auto isClass = obj.IsA<UEClass>();
	const auto isScriptStruct = obj.IsA<UEScriptStruct>();
	if (!isClass && !isScriptStruct)
	{
		return;
	}
	const auto name = obj.GetName();
	if (name.find("Default__") != std::string::npos || name.find("<uninitialized>") != std::string::npos || name.find("PLACEHOLDER-CLASS") != std::string::npos)
	{
		return;
	}
	if (obj.IsA<UEClass>())
	{
		GenerateClass(obj.Cast<UEClass>());
	}
	else if (obj.IsA<UEScriptStruct>())
	{
		GenerateScriptStruct(obj.Cast<UEScriptStruct>());
	}
}

bool Package::Save(std::ofstream& o)
{
	if (!enums.empty() || !scriptStructs.empty() || !classes.empty())
	{
		if (enums.size() > 0)
		{
			tfm::format(o, "// %s enums \n", enums.size());
			for (auto e:enums)
			{
				tfm::format(o, "// %s\nenum class %s : uint8_t\n{\n", e.FullName,e.Name);
				for (int i = 0; i < e.Values.size(); i++)
				{
					tfm::format(o, "\t%s = %d, \n", e.Values[i], i);
				}
				tfm::format(o, "\n};\n\n");
			}
		}
		if (scriptStructs.size() > 0)
		{
			tfm::format(o, "// %s structs\n", scriptStructs.size());
			for (auto ss:scriptStructs)
			{
				o << "// " << ss.FullName << "\n// ";
				if (ss.InheritedSize)
				{
					o << tfm::format("0x%04X (0x%04X - 0x%04X)\n", ss.Size - ss.InheritedSize, ss.Size, ss.InheritedSize);
				}
				else
				{
					o << tfm::format("0x%04X\n", ss.Size);
				}
				o << ss.NameCppFull << "\n{\n";
				for (auto m : ss.Members)
				{
					o << tfm::format("\t%-50s %-58s// 0x%04X(0x%04X)", m.Type, m.Name + ";", m.Offset, m.Size)
						+ (!m.Comment.empty() ? " " + m.Comment : "")
						+ (!m.FlagsString.empty() ? " (" + m.FlagsString + ")" : "") << "\n";
				}
				o << "};\n";
			}
		}
		if (!classes.empty())
		{
			tfm::format(o, "// %s class\n", classes.size());
			
			for (auto c:classes)
			{
				o << "// " << c.FullName << "\n// ";
				tfm::format(o, "//%s\n", c.FullName);
				if (c.InheritedSize)
				{
					tfm::format(o, "//0x%04X (0x%04X - 0x%04X)\n", c.Size - c.InheritedSize, c.Size, c.InheritedSize);
				}
				else
				{
					tfm::format(o, "0x%04X\n", c.Size);
				}
				o << c.NameCppFull << "\n{\npublic:\n";

				for (auto&& m : c.Members)
				{
					tfm::format(o, "\t%-50s %-58s// 0x%04X(0x%04X)", m.Type, m.Name + ";", m.Offset, m.Size);
					if (!m.Comment.empty())
					{
						o << " " << m.Comment;
					}
					if (!m.FlagsString.empty())
					{
						o << " (" << m.FlagsString << ")";
					}
					o << "\n";
				}
				if (!c.Methods.empty())
				{
					o << "\n";
					for (auto&& m : c.Methods)
					{
						o << "\t// " << m.FullName << "\n" << "\t// (" << m.FlagsString << ")\n";
						o << "\t" << BuildMethodSignature(m, {}, true) << ";" << "// " << m.FuncAddr << "\n\n";
					}
				}
				o << "\n}\n";
			}
		}
	}
	return true;
}

void Package::GenerateEnum(UEEnum enumObj)
{
	Enum e;
	e.Name = MakeUniqueCppName(enumObj);
	if (e.Name.find("Default__") != std::string::npos || e.Name.find("PLACEHOLDER-CLASS") != std::string::npos)
	{
		return;
	}
	e.FullName = enumObj.GetFullName();

	std::unordered_map<std::string, int> conflicts;
	for (auto&& s : enumObj.GetNames())
	{
		const auto clean = MakeValidName(std::move(s));

		const auto it = conflicts.find(clean);
		if (it == std::end(conflicts))
		{
			e.Values.push_back(clean);
			conflicts[clean] = 1;
		}
		else
		{
			e.Values.push_back(clean + tfm::format("%02d", it->second));
			conflicts[clean]++;
		}
	}
	enums.emplace_back(std::move(e));
}

void Package::GenerateClass(UEClass classObj)
{
	Class c;
	c.Name = classObj.GetName();
	c.FullName = classObj.GetFullName();
	c.NameCpp = MakeValidName(classObj.GetNameCPP());
	c.NameCppFull = "class " + c.NameCpp;
	c.Size = classObj.GetPropertySize();
	c.InheritedSize = 0;
	size_t offset = 0;
	auto super = classObj.GetSuper();
	if (super.IsValid() && super != classObj)
	{
		c.InheritedSize = offset = super.GetPropertySize();
		c.NameCppFull += " : public " + MakeValidName(super.GetNameCPP());
	}
	std::vector<UEProperty> properties;
	for (auto prop = classObj.GetChildren().Cast<UEProperty>(); prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
	{
		if (prop.GetElementSize() > 0 && !prop.IsA<UEScriptStruct>() && !prop.IsA<UEFunction>() && !prop.IsA<UEEnum>() && !prop.IsA<UEConst>() && (!super.IsValid()|| (super != classObj && prop.GetOffset() >= super.GetPropertySize())))
		{
			properties.push_back(prop);
		}
	}
	std::sort(std::begin(properties), std::end(properties), ComparePropertyLess);
	GenerateMethods(classObj, c.Methods);
	GenerateMembers(classObj, offset, properties, c.Members);
	classes.emplace_back(std::move(c));
}

void Package::GenerateScriptStruct(UEScriptStruct scriptStructObj)
{
	ScriptStruct ss;
	ss.Size = scriptStructObj.GetPropertySize();
	ss.Name = scriptStructObj.GetName();
	ss.FullName = scriptStructObj.GetFullName();
	ss.NameCpp = MakeValidName(scriptStructObj.GetNameCPP());
	ss.NameCppFull = "struct " + MakeUniqueCppName(scriptStructObj);
	ss.InheritedSize = 0;
	size_t offset = 0;
	auto super = scriptStructObj.GetSuper();
	if (super.IsValid() && super != scriptStructObj)
	{
		ss.InheritedSize = offset = super.GetPropertySize();
		ss.NameCppFull += " : public " + MakeUniqueCppName(super.Cast<UEScriptStruct>());
	}
	std::vector<UEProperty> properties;
	for (auto prop = scriptStructObj.GetChildren().Cast<UEProperty>(); prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
	{
		if (prop.GetElementSize() > 0	&& !prop.IsA<UEScriptStruct>() && !prop.IsA<UEFunction>() && !prop.IsA<UEEnum>() && !prop.IsA<UEConst>())
		{
			properties.push_back(prop);
		}
	}
	std::sort(std::begin(properties), std::end(properties), ComparePropertyLess);
	GenerateMembers(scriptStructObj, offset, properties, ss.Members);
	scriptStructs.emplace_back(std::move(ss));
}

void Package::GenerateMethods(const UEClass& classObj, std::vector<Method>& methods)
{
	std::unordered_set<std::string> uniqueMethods;
	for (auto prop = classObj.GetChildren().Cast<UEProperty>(); prop.IsValid(); prop = prop.GetNext().Cast<UEProperty>())
	{
		if (prop.IsA<UEFunction>())
		{
			auto function = prop.Cast<UEFunction>();
			Method m;
			m.FuncAddr = tfm::format("sub_%X()", function.GetFunc() - Global::GameMemory->GetBase());
			m.Index = function.GetIndex();
			m.FullName = function.GetFullName();
			m.Name = MakeValidName(function.GetName());
			if (uniqueMethods.find(m.FullName) != std::end(uniqueMethods))
			{
				continue;
			}
			uniqueMethods.insert(m.FullName);
			m.IsNative = function.GetFunctionFlags() & UEFunctionFlags::Native;
			m.IsStatic = function.GetFunctionFlags() & UEFunctionFlags::Static;
			m.FlagsString = StringifyFlags(function.GetFunctionFlags());

			std::vector<std::pair<UEProperty, Method::Parameter>> parameters;
			std::unordered_map<std::string, size_t> unique;
			for (auto param = function.GetChildren().Cast<UEProperty>(); param.IsValid(); param = param.GetNext().Cast<UEProperty>())
			{
				if (param.GetElementSize() == 0)
				{
					continue;
				}
				const auto info = param.GetInfo();
				if (info.Type != UEProperty::PropertyType::Unknown)
				{
					using Type = Method::Parameter::Type;
					Method::Parameter p;
					if (!Method::Parameter::MakeType(param.GetPropertyFlags(), p.ParamType))
					{
						continue;
					}
					p.PassByReference = false;
					p.Name = MakeValidName(param.GetName());
					const auto it = unique.find(p.Name);
					if (it == std::end(unique))
					{
						unique[p.Name] = 1;
					}
					else
					{
						++unique[p.Name];
						p.Name += tfm::format("%02d", it->second);
					}
					p.CppType = info.CppType;
					switch (p.ParamType)
					{
					case Type::Default:
						if (prop.GetArrayDim() > 1)
						{
							p.CppType = p.CppType + "*";
						}
						else if (info.CanBeReference)
						{
							p.PassByReference = true;
						}
						break;
					}

					parameters.emplace_back(std::make_pair(prop, std::move(p)));
				}
			}

			std::sort(std::begin(parameters), std::end(parameters), [](auto&& lhs, auto&& rhs) { return ComparePropertyLess(lhs.first, rhs.first); });

			for (auto& param : parameters)
			{
				m.Parameters.emplace_back(std::move(param.second));
			}

			methods.emplace_back(std::move(m));
		}
	}
}

void Package::GenerateMembers(const UEStruct& structObj, size_t offset, const std::vector<UEProperty>& properties, std::vector<Member>& members)
{
	std::unordered_map<std::string, size_t> uniqueMemberNames;
	UEBoolProperty previousBitfieldProperty;
	size_t unknownDataCounter = 0;
	for (auto&& prop : properties)
	{
		if (offset < prop.GetOffset())
		{
			previousBitfieldProperty = UEBoolProperty();
			const auto size = prop.GetOffset() - offset;
			members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "MISSED OFFSET"));
		}
		const auto info = prop.GetInfo();
		if (info.Type != UEProperty::PropertyType::Unknown)
		{
			Member sp;
			sp.Offset = prop.GetOffset();
			sp.Size = info.Size;
			sp.Type = info.CppType;
			sp.Name = MakeValidName(prop.GetName());
			const auto it = uniqueMemberNames.find(sp.Name);
			if (it == std::end(uniqueMemberNames))
			{
				uniqueMemberNames[sp.Name] = 1;
			}
			else
			{
				++uniqueMemberNames[sp.Name];
				sp.Name += tfm::format("%02d", it->second);
			}
			if (prop.GetArrayDim() > 1)
			{
				sp.Name += tfm::format("[0x%X]", prop.GetArrayDim());
			}
			if (prop.IsA<UEBoolProperty>() && prop.Cast<UEBoolProperty>().IsBitfield())
			{
				auto boolProp = prop.Cast<UEBoolProperty>();
				const auto missingBits = boolProp.GetMissingBitsCount(previousBitfieldProperty);
				if (missingBits[1] != -1)
				{
					if (missingBits[0] > 0)
					{
						members.emplace_back(CreateBitfieldPadding(unknownDataCounter++, previousBitfieldProperty.GetOffset(), info.CppType, missingBits[0]));
					}
					if (missingBits[1] > 0)
					{
						members.emplace_back(CreateBitfieldPadding(unknownDataCounter++, sp.Offset, info.CppType, missingBits[1]));
					}
				}
				else if (missingBits[0] > 0)
				{
					members.emplace_back(CreateBitfieldPadding(unknownDataCounter++, sp.Offset, info.CppType, missingBits[0]));
				}
				previousBitfieldProperty = boolProp;
				sp.Name += " : 1";
			}
			else
			{
				previousBitfieldProperty = UEBoolProperty();
			}
			sp.Flags = static_cast<size_t>(prop.GetPropertyFlags());
			sp.FlagsString = StringifyFlags(prop.GetPropertyFlags());
			members.emplace_back(std::move(sp));
			const auto sizeMismatch = static_cast<int>(prop.GetElementSize() * prop.GetArrayDim()) - static_cast<int>(info.Size * prop.GetArrayDim());
			if (sizeMismatch > 0)
			{
				members.emplace_back(CreatePadding(unknownDataCounter++, offset, sizeMismatch, "FIX WRONG TYPE SIZE OF PREVIOUS PROPERTY"));
			}
		}
		else
		{
			const auto size = prop.GetElementSize() * prop.GetArrayDim();
			members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "UNKNOWN PROPERTY: " + prop.GetFullName()));
		}
		offset = prop.GetOffset() + prop.GetElementSize() * prop.GetArrayDim();
	}
	if (offset < structObj.GetPropertySize())
	{
		const auto size = structObj.GetPropertySize() - offset;
		members.emplace_back(CreatePadding(unknownDataCounter++, offset, size, "MISSED OFFSET"));
	}
}

std::string Package::GetPackageName()
{
	return UEObject(packageObj).GetName();
}

bool Package::Method::Parameter::MakeType(UEPropertyFlags flags, Type& type)
{
	if (flags & UEPropertyFlags::ReturnParm)
	{
		type = Type::Return;
	}
	else if (flags & UEPropertyFlags::OutParm)
	{
		//if it is a const parameter make it a default parameter
		if (flags & UEPropertyFlags::ConstParm)
		{
			type = Type::Default;
		}
		else
		{
			type = Type::Out;
		}
	}
	else if (flags & UEPropertyFlags::Parm)
	{
		type = Type::Default;
	}
	else
	{
		return false;
	}

	return true;
}

std::string GetTypeCppName(UEProperty prop)
{
	std::string className = prop.GetClass().GetName();
	std::string cppType = "";
	if (className == "StructProperty")
	{
		cppType = "struct " + UEScriptStruct(UStructProperty(prop.GetAddress()).Struct()).GetNameCPP();
	}
	else if (className == "ByteProperty")
	{
		auto b = UEByteProperty(prop.GetAddress());
		if (b.IsEnum())
			cppType = "TEnumAsByte<" + b.GetEnum().GetNameCPP() + ">";
		else cppType = "unsigned char";

	}
	else if (className == "ObjectProperty" || className == "EncryptedObjectProperty")
	{
		auto b = UEObjectProperty(prop.GetAddress());
		cppType = "class " + b.GetPropertyClass().GetNameCPP() + "*";
	}
	else if (className == "ClassProperty")
	{
		cppType = "class " + UEClassProperty(prop.GetAddress()).GetMetaClass().GetNameCPP() + "*";
	}
	else if (className == "InterfaceProperty")
	{
		cppType = "TScriptInterface<class " + UEInterfaceProperty(prop.GetAddress()).GetInterfaceClass().GetNameCPP() + ">";
	}
	else if (className == "WeakObjectProperty")
	{
		cppType = "TWeakObjectPtr<class " + UEWeakObjectProperty(prop.GetAddress()).GetPropertyClass().GetNameCPP() + ">";
	}
	else if (className == "LazyObjectProperty")
	{
		cppType = "TLazyObjectPtr<class " + UELazyObjectProperty(prop.GetAddress()).GetPropertyClass().GetNameCPP() + ">";
	}
	else if (className == "BoolProperty")
	{
		auto b = UEBoolProperty(prop.GetAddress());
		if (b.IsNativeBool())
		{
			cppType = "bool";
		}
		cppType = "unsigned char";
	}
	else if (className == "UInt16Property")
	{
		cppType = "uint16_t";
	}
	else if (className == "UInt32Property")
	{
		cppType = "uint32_t";
	}
	else if (className == "UInt64Property")
	{
		cppType = "uint64_t";
	}
	else if (className == "Int8Property")
	{
		cppType = "int8_t";
	}
	else if (className == "Int16Property")
	{
		cppType = "int16_t";
	}
	else if (className == "IntProperty")
	{
		cppType = "int";
	}
	else if (className == "Int64Property")
	{
		cppType = "int64_t";
	}
	else if (className == "FloatProperty")
	{
		cppType = "float";
	}
	else if (className == "DoubleProperty")
	{
		cppType = "double";
	}
	else if (className == "AssetObjectProperty")
	{
		cppType = "TAssetPtr<class >";
	}
	else if (className == "AssetClassProperty")
	{
		cppType = "AssetClassProperty";
	}
	else if (className == "NameProperty")
	{
		cppType = "struct FName";
	}
	else if (className == "StrProperty")
	{
		cppType = "struct FString";
	}
	else if (className == "TextProperty")
	{
		cppType = "struct FText";
	}
	else if (className == "ArrayProperty")
	{
		auto b = UEArrayProperty(prop.GetAddress());
		cppType = "TArray<" + GetTypeCppName(b.GetInner()) + ">";
	}
	else if (className == "MapProperty")
	{
		auto key = GetTypeCppName(UEProperty(UMapProperty(prop.GetAddress()).KeyProp()));
		auto value = GetTypeCppName(UEProperty(UMapProperty(prop.GetAddress()).ValueProp()));
		cppType = "TMap<" + key + ", " + value + ">";
	}
	else if (className == "DelegateProperty")
	{
		cppType = "struct FScriptDelegate";
	}
	else if (className == "MulticastDelegateProperty")
	{
		cppType = "struct FScriptMulticastDelegate";
	}
	else if (className == "EnumProperty")
	{
		cppType = UEEnumProperty(prop.GetAddress()).GetEnum().GetNameCPP();
	}
	else
	{
		cppType = "UnknownProperty";
	}
	return cppType;
}

bool ComparePropertyLess(const UEProperty& lhs, const UEProperty& rhs)
{
	if (lhs.GetOffset() == rhs.GetOffset()
		&& lhs.IsA<UEBoolProperty>()
		&& rhs.IsA<UEBoolProperty>())
	{
		return lhs.Cast<UEBoolProperty>() < rhs.Cast<UEBoolProperty>();
	}

	return lhs.GetOffset() < rhs.GetOffset();
}

Package::Member CreatePadding(size_t id, size_t offset, size_t size, std::string reason)
{
	Package::Member ss;
	ss.Name = tfm::format("UnknownData%02d[0x%X]", id, size);
	ss.Type = "unsigned char";
	ss.Offset = offset;
	ss.Size = size;
	ss.Comment = std::move(reason);
	return ss;
}

Package::Member CreateBitfieldPadding(size_t id, size_t offset, std::string type, size_t bits)
{
	Package::Member ss;
	ss.Name = tfm::format("UnknownData%02d : %d", id, bits);
	ss.Type = std::move(type);
	ss.Offset = offset;
	ss.Size = 1;
	return ss;
}

std::string BuildMethodSignature(const Package::Method& m, const Package::Class& c, bool inHeader)
{
	using Type = Package::Method::Parameter::Type;

	std::ostringstream ss;

	if (m.IsStatic && inHeader)
	{
		ss << "static ";
	}
	std::string cpptype = "void";
	for (auto param : m.Parameters)
	{
		if (param.ParamType == Type::Return)
		{
			cpptype = param.CppType;
			break;
		}
	}
	ss << cpptype << " ";

	if (!inHeader)
	{
		ss << c.NameCpp << "::";
	}
	if (m.IsStatic)
	{
		ss << "STATIC_";
	}
	ss << m.Name;
	ss << "(";
	for (auto param: m.Parameters)
	{
		if (param.ParamType!=Type::Return)
		{
			ss << (param.PassByReference ? "const " : "") + param.CppType + (param.PassByReference ? "& " : param.ParamType == Type::Out ? "* " : " ") + param.Name;
		}
	}
	ss << ")";
	return ss.str();
}