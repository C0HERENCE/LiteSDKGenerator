#pragma once
#include "SDKTypes.h"

#pragma region EngineTypes
bool operator&(UEPropertyFlags lhs, UEPropertyFlags rhs)
{
	return (static_cast<std::underlying_type_t<UEPropertyFlags>>(lhs)& static_cast<std::underlying_type_t<UEPropertyFlags>>(rhs)) == static_cast<std::underlying_type_t<UEPropertyFlags>>(rhs);
}

std::string StringifyFlags(const UEPropertyFlags flags)
{
	std::vector<const char*> buffer;

	if (flags & UEPropertyFlags::Edit) { buffer.push_back("Edit"); }
	if (flags & UEPropertyFlags::ConstParm) { buffer.push_back("ConstParm"); }
	if (flags & UEPropertyFlags::BlueprintVisible) { buffer.push_back("BlueprintVisible"); }
	if (flags & UEPropertyFlags::ExportObject) { buffer.push_back("ExportObject"); }
	if (flags & UEPropertyFlags::BlueprintReadOnly) { buffer.push_back("BlueprintReadOnly"); }
	if (flags & UEPropertyFlags::Net) { buffer.push_back("Net"); }
	if (flags & UEPropertyFlags::EditFixedSize) { buffer.push_back("EditFixedSize"); }
	if (flags & UEPropertyFlags::Parm) { buffer.push_back("Parm"); }
	if (flags & UEPropertyFlags::OutParm) { buffer.push_back("OutParm"); }
	if (flags & UEPropertyFlags::ZeroConstructor) { buffer.push_back("ZeroConstructor"); }
	if (flags & UEPropertyFlags::ReturnParm) { buffer.push_back("ReturnParm"); }
	if (flags & UEPropertyFlags::DisableEditOnTemplate) { buffer.push_back("DisableEditOnTemplate"); }
	if (flags & UEPropertyFlags::Transient) { buffer.push_back("Transient"); }
	if (flags & UEPropertyFlags::Config) { buffer.push_back("Config"); }
	if (flags & UEPropertyFlags::DisableEditOnInstance) { buffer.push_back("DisableEditOnInstance"); }
	if (flags & UEPropertyFlags::EditConst) { buffer.push_back("EditConst"); }
	if (flags & UEPropertyFlags::GlobalConfig) { buffer.push_back("GlobalConfig"); }
	if (flags & UEPropertyFlags::InstancedReference) { buffer.push_back("InstancedReference"); }
	if (flags & UEPropertyFlags::DuplicateTransient) { buffer.push_back("DuplicateTransient"); }
	if (flags & UEPropertyFlags::SubobjectReference) { buffer.push_back("SubobjectReference"); }
	if (flags & UEPropertyFlags::SaveGame) { buffer.push_back("SaveGame"); }
	if (flags & UEPropertyFlags::NoClear) { buffer.push_back("NoClear"); }
	if (flags & UEPropertyFlags::ReferenceParm) { buffer.push_back("ReferenceParm"); }
	if (flags & UEPropertyFlags::BlueprintAssignable) { buffer.push_back("BlueprintAssignable"); }
	if (flags & UEPropertyFlags::Deprecated) { buffer.push_back("Deprecated"); }
	if (flags & UEPropertyFlags::IsPlainOldData) { buffer.push_back("IsPlainOldData"); }
	if (flags & UEPropertyFlags::RepSkip) { buffer.push_back("RepSkip"); }
	if (flags & UEPropertyFlags::RepNotify) { buffer.push_back("RepNotify"); }
	if (flags & UEPropertyFlags::Interp) { buffer.push_back("Interp"); }
	if (flags & UEPropertyFlags::NonTransactional) { buffer.push_back("NonTransactional"); }
	if (flags & UEPropertyFlags::EditorOnly) { buffer.push_back("EditorOnly"); }
	if (flags & UEPropertyFlags::NoDestructor) { buffer.push_back("NoDestructor"); }
	if (flags & UEPropertyFlags::AutoWeak) { buffer.push_back("AutoWeak"); }
	if (flags & UEPropertyFlags::ContainsInstancedReference) { buffer.push_back("ContainsInstancedReference"); }
	if (flags & UEPropertyFlags::AssetRegistrySearchable) { buffer.push_back("AssetRegistrySearchable"); }
	if (flags & UEPropertyFlags::SimpleDisplay) { buffer.push_back("SimpleDisplay"); }
	if (flags & UEPropertyFlags::AdvancedDisplay) { buffer.push_back("AdvancedDisplay"); }
	if (flags & UEPropertyFlags::Protected) { buffer.push_back("Protected"); }
	if (flags & UEPropertyFlags::BlueprintCallable) { buffer.push_back("BlueprintCallable"); }
	if (flags & UEPropertyFlags::BlueprintAuthorityOnly) { buffer.push_back("BlueprintAuthorityOnly"); }
	if (flags & UEPropertyFlags::TextExportTransient) { buffer.push_back("TextExportTransient"); }
	if (flags & UEPropertyFlags::NonPIEDuplicateTransient) { buffer.push_back("NonPIEDuplicateTransient"); }
	if (flags & UEPropertyFlags::ExposeOnSpawn) { buffer.push_back("ExposeOnSpawn"); }
	if (flags & UEPropertyFlags::PersistentInstance) { buffer.push_back("PersistentInstance"); }
	if (flags & UEPropertyFlags::UObjectWrapper) { buffer.push_back("UObjectWrapper"); }
	if (flags & UEPropertyFlags::HasGetValueTypeHash) { buffer.push_back("HasGetValueTypeHash"); }
	if (flags & UEPropertyFlags::NativeAccessSpecifierPublic) { buffer.push_back("NativeAccessSpecifierPublic"); }
	if (flags & UEPropertyFlags::NativeAccessSpecifierProtected) { buffer.push_back("NativeAccessSpecifierProtected"); }
	if (flags & UEPropertyFlags::NativeAccessSpecifierPrivate) { buffer.push_back("NativeAccessSpecifierPrivate"); }

	switch (buffer.size())
	{
	case 0:
		return std::string();
	case 1:
		return std::string(buffer[0]);
	default:
		std::ostringstream os;
		std::copy(buffer.begin(), buffer.end() - 1, std::ostream_iterator<const char*>(os, ", "));
		os << *buffer.rbegin();
		return os.str();
	}
}

bool operator&(UEFunctionFlags lhs, UEFunctionFlags rhs)
{
	return (static_cast<std::underlying_type_t<UEFunctionFlags>>(lhs)& static_cast<std::underlying_type_t<UEFunctionFlags>>(rhs)) == static_cast<std::underlying_type_t<UEFunctionFlags>>(rhs);
}

std::string StringifyFlags(const UEFunctionFlags flags)
{
	std::vector<const char*> buffer;

	if (flags & UEFunctionFlags::Final) { buffer.push_back("Final"); }
	if (flags & UEFunctionFlags::RequiredAPI) { buffer.push_back("RequiredAPI"); }
	if (flags & UEFunctionFlags::BlueprintAuthorityOnly) { buffer.push_back("BlueprintAuthorityOnly"); }
	if (flags & UEFunctionFlags::BlueprintCosmetic) { buffer.push_back("BlueprintCosmetic"); }
	if (flags & UEFunctionFlags::Net) { buffer.push_back("Net"); }
	if (flags & UEFunctionFlags::NetReliable) { buffer.push_back("NetReliable"); }
	if (flags & UEFunctionFlags::NetRequest) { buffer.push_back("NetRequest"); }
	if (flags & UEFunctionFlags::Exec) { buffer.push_back("Exec"); }
	if (flags & UEFunctionFlags::Native) { buffer.push_back("Native"); }
	if (flags & UEFunctionFlags::Event) { buffer.push_back("Event"); }
	if (flags & UEFunctionFlags::NetResponse) { buffer.push_back("NetResponse"); }
	if (flags & UEFunctionFlags::Static) { buffer.push_back("Static"); }
	if (flags & UEFunctionFlags::NetMulticast) { buffer.push_back("NetMulticast"); }
	if (flags & UEFunctionFlags::MulticastDelegate) { buffer.push_back("MulticastDelegate"); }
	if (flags & UEFunctionFlags::Public) { buffer.push_back("Public"); }
	if (flags & UEFunctionFlags::Private) { buffer.push_back("Private"); }
	if (flags & UEFunctionFlags::Protected) { buffer.push_back("Protected"); }
	if (flags & UEFunctionFlags::Delegate) { buffer.push_back("Delegate"); }
	if (flags & UEFunctionFlags::NetServer) { buffer.push_back("NetServer"); }
	if (flags & UEFunctionFlags::HasOutParms) { buffer.push_back("HasOutParms"); }
	if (flags & UEFunctionFlags::HasDefaults) { buffer.push_back("HasDefaults"); }
	if (flags & UEFunctionFlags::NetClient) { buffer.push_back("NetClient"); }
	if (flags & UEFunctionFlags::DLLImport) { buffer.push_back("DLLImport"); }
	if (flags & UEFunctionFlags::BlueprintCallable) { buffer.push_back("BlueprintCallable"); }
	if (flags & UEFunctionFlags::BlueprintEvent) { buffer.push_back("BlueprintEvent"); }
	if (flags & UEFunctionFlags::BlueprintPure) { buffer.push_back("BlueprintPure"); }
	if (flags & UEFunctionFlags::Const) { buffer.push_back("Const"); }
	if (flags & UEFunctionFlags::NetValidate) { buffer.push_back("NetValidate"); }

	switch (buffer.size())
	{
	case 0:
		return std::string();
	case 1:
		return std::string(buffer[0]);
	default:
		std::ostringstream os;
		std::copy(buffer.begin(), buffer.end() - 1, std::ostream_iterator<const char*>(os, ", "));
		os << *buffer.rbegin();
		return os.str();
	}
}
#pragma endregion

#pragma region NameValidator
std::string MakeValidName(std::string&& name)
{
	std::string valid(name);

	for (auto i = 0u; i < name.length(); ++i)
	{
		if (valid[i] == ' '
			|| valid[i] == '?'
			|| valid[i] == '+'
			|| valid[i] == '-'
			|| valid[i] == ':'
			|| valid[i] == '/'
			|| valid[i] == '^'
			|| valid[i] == '('
			|| valid[i] == ')'
			|| valid[i] == '['
			|| valid[i] == ']'
			|| valid[i] == '<'
			|| valid[i] == '>'
			|| valid[i] == '&'
			|| valid[i] == '.'
			|| valid[i] == '#'
			|| valid[i] == '\''
			|| valid[i] == '"'
			|| valid[i] == '%')
		{
			valid[i] = '_';
		}
	}

	if (!valid.empty())
	{
		if (std::isdigit(valid[0]))
		{
			valid = '_' + valid;
		}
	}

	return valid;
}

template<typename T>
std::string MakeUniqueCppNameImpl(const T& t)
{
	std::string name;
	//if (Global::Objects->CountObjects<T>(t.GetName()) > 1)
	//{
	//	name += MakeValidName(t.GetOuter().GetName()) + "_";
	//}
	return name + MakeValidName(t.GetName());
}

std::string MakeUniqueCppName(const UEConst& c)
{
	return MakeUniqueCppNameImpl(c);
}

std::string MakeUniqueCppName(const UEEnum& e)
{
	auto name = MakeUniqueCppNameImpl(e);
	if (!name.empty() && name[0] != 'E')
	{
		name = 'E' + name;
	}
	return name;
}

std::string MakeUniqueCppName(const UEStruct& ss)
{
	std::string name;
	//if (Global::Objects->CountObjects<UEStruct>(ss.GetName()) > 1)
	//{
	//	name += MakeValidName(ss.GetOuter().GetNameCPP()) + "_";
	//}
	return name + MakeValidName(ss.GetNameCPP());
}
#pragma endregion

#pragma region EngineTypes

FName::FName()
{
	base = 0;
}
FName::FName(uint64 _base)
{
	base = _base;
}
int FName::GetComparisonIndex() const
{
	return Updates::Dec::comparison_id(Global::GameMemory->Read32(base + Updates::Off::comparison_id));
}

int FName::GetNumber() const
{
	return Updates::Dec::number(Global::GameMemory->Read32(base + Updates::Off::number));
}

std::string FString::ToString() const
{
	wchar_t Name[64];
	Global::GameMemory->ReadWString(m_Data, Name, m_nCount * sizeof(wchar_t));
	char text[60];
	sprintf_s(text, "%ls", Name);
	return text;
}
#pragma endregion

#pragma region GenericTypes


int UEObject::GetIndex() const
{
	return uobject.GetInternalIndex();
}

UEClass UEObject::GetClass() const
{
	return UEClass(uobject.GetClass());
}

UEObject UEObject::GetOuter() const
{
	return UEObject(uobject.GetOuter());
}

std::string UEObject::GetName() const
{
	UObject uobj = uobject;
	auto name = Global::Names->GetById(uobj.GetFName().GetComparisonIndex());
	if (uobj.GetFName().GetNumber() > 0)
	{
		name += '_' + std::to_string(uobj.GetFName().GetNumber());
	}
	auto pos = name.rfind('/');
	if (pos == std::string::npos)
	{
		return name;
	}

	return name.substr(pos + 1);
}

uint64 UEObject::GetAddress() const
{
	return object;
}

UEObject UEObject::GetPackageObject() const
{
	UEObject package(0);

	for (auto outer = GetOuter(); outer.IsValid(); outer = outer.GetOuter())
	{
		package = outer;
	}

	return package;
}

std::string UEObject::GetFullName() const
{
	if (GetClass().IsValid())
	{
		std::string temp;

		for (auto outer = GetOuter(); outer.IsValid(); outer = outer.GetOuter())
		{
			temp = outer.GetName() + "." + temp;
		}

		std::string name = GetClass().GetName();
		name += " ";
		name += temp;
		name += GetName();

		return name;
	}

	return std::string("(null)");
}

std::string UEObject::GetNameCPP() const
{
	std::string name;

	if (IsA<UEClass>())
	{
		auto c = Cast<UEClass>();
		while (c.IsValid())
		{
			const auto className = c.GetName();
			if (className == "Actor")
			{
				name += "A";
				break;
			}
			if (className == "Object")
			{
				name += "U";
				break;
			}

			c = c.GetSuper().Cast<UEClass>();
		}
	}
	else
	{
		name += "F";
	}

	name += GetName();

	return name;
}

UEClass UEObject::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Object");
	return c;
}

UEField UEField::GetNext() const
{
	return UEField(UField(object).Next());
}

UEClass UEField::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Field");
	return c;
}

std::vector<std::string> UEEnum::GetNames() const
{
	std::vector<std::string> buffer;
	auto names = UEnum(object).Names();

	for (auto i = 0; i < names.Length(); ++i)
	{
		buffer.push_back(Global::Names->GetById(Global::GameMemory->Read32(names.GetAddress() + i * 0x10 + Updates::Off::comparison_id)));
	}

	return buffer;
}

int UEObject::GetComparisonIndex() const
{
	return uobject.GetFName().GetComparisonIndex();
}

UEClass UEEnum::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Enum");
	return c;
}

std::string UEConst::GetValue() const
{
	throw;
}

UEClass UEConst::StaticClass()
{
	return 0;
}

UEStruct UEStruct::GetSuper() const
{
	return UEStruct(UStruct(object).SuperField());
}

UEField UEStruct::GetChildren() const
{
	return UEField(UStruct(object).Children());
}

size_t UEStruct::GetPropertySize() const
{
	return UStruct(object).PropertySize();
}

UEClass UEStruct::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Struct");
	return c;
}

UEClass UEScriptStruct::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.ScriptStruct");
	return c;
}

//---------------------------------------------------------------------------
//UEFunction
//---------------------------------------------------------------------------
UEFunctionFlags UEFunction::GetFunctionFlags() const
{
	return static_cast<UEFunctionFlags>(UFunction(object).FunctionFlags());
}
uint64 UEFunction::GetFunc() const
{
	return UFunction(object).Func();
}
//---------------------------------------------------------------------------
UEClass UEFunction::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Function");
	return c;
}
//---------------------------------------------------------------------------
//UEClass
//---------------------------------------------------------------------------
UEClass UEClass::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Class");
	return c;
}
//---------------------------------------------------------------------------
//UEProperty
//---------------------------------------------------------------------------
size_t UEProperty::GetArrayDim() const
{
	return UProperty(object).ArrayDim();
}

size_t UEProperty::GetElementSize() const
{
	return UProperty(object).ElementSize();
}

UEPropertyFlags UEProperty::GetPropertyFlags() const
{
	return static_cast<UEPropertyFlags>(UProperty(object).PropertyFlags().A);
}

size_t UEProperty::GetOffset() const
{
	return UProperty(object).Offset();
}

UEClass UEProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Property");
	return c;
}

UEProperty::Info UEProperty::GetInfo() const
{
	if (IsValid())
	{
		std::string className = GetClass().GetName();
		if (className == "BoolProperty")
		{
			return Cast<UEBoolProperty>().GetInfo();
		}
		if (className == "ClassProperty")
		{
			return Cast<UEClassProperty>().GetInfo();
		}
		if (className == "ObjectProperty")
		{
			return Cast<UEObjectProperty>().GetInfo();
		}
		if (className == "EnumProperty")
		{
			return Cast<UEEnumProperty>().GetInfo();
		}
		if (className == "IntProperty")
		{
			return Cast<UEIntProperty>().GetInfo();
		}
		if (className == "FloatProperty")
		{
			return Cast<UEFloatProperty>().GetInfo();
		}
		if (className == "ByteProperty")
		{
			return Cast<UEByteProperty>().GetInfo();
		}
		if (className == "UInt16Property")
		{
			return Cast<UEUInt16Property>().GetInfo();
		}
		if (className == "UInt32Property")
		{
			return Cast<UEUInt32Property>().GetInfo();
		}
		if (className == "UInt64Property")
		{
			return Cast<UEUInt64Property>().GetInfo();
		}
		if (className == "Int8Property")
		{
			return Cast<UEInt8Property>().GetInfo();
		}
		if (className == "Int16Property")
		{
			return Cast<UEInt16Property>().GetInfo();
		}
		if (className == "Int64Property")
		{
			return Cast<UEInt64Property>().GetInfo();
		}
		if (className == "DoubleProperty")
		{
			return Cast<UEDoubleProperty>().GetInfo();
		}
		if (className == "InterfaceProperty")
		{
			return Cast<UEInterfaceProperty>().GetInfo();
		}
		if (className == "WeakObjectProperty")
		{
			return Cast<UEWeakObjectProperty>().GetInfo();
		}
		if (className == "LazyObjectProperty")
		{
			return Cast<UELazyObjectProperty>().GetInfo();
		}
		if (className == "EncryptedObjectProperty")
		{
			return Cast<UEEncryptedObjectProperty>().GetInfo();
		}
		if (className == "NameProperty")
		{
			return Cast<UENameProperty>().GetInfo();
		}
		if (className == "StructProperty")
		{
			return Cast<UEStructProperty>().GetInfo();
		}
		if (className == "StrProperty")
		{
			return Cast<UEStrProperty>().GetInfo();
		}
		if (className == "TextProperty")
		{
			return Cast<UETextProperty>().GetInfo();
		}
		if (className == "ArrayProperty")
		{
			return Cast<UEArrayProperty>().GetInfo();
		}
		if (className == "MapProperty")
		{
			return Cast<UEMapProperty>().GetInfo();
		}
		if (className == "DelegateProperty")
		{
			return Cast<UEDelegateProperty>().GetInfo();
		}
		if (className == "MulticastDelegateProperty")
		{
			return Cast<UEMulticastDelegateProperty>().GetInfo();
		}
	}
	return { PropertyType::Unknown };
}
//---------------------------------------------------------------------------
//UENumericProperty
//---------------------------------------------------------------------------
UEClass UENumericProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.NumericProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEByteProperty
//---------------------------------------------------------------------------
bool UEByteProperty::IsEnum() const
{
	return GetEnum().IsValid();
}
UEEnum UEByteProperty::GetEnum() const
{
	return UEEnum(UByteProperty(object).Enum());
}
//---------------------------------------------------------------------------
UEProperty::Info UEByteProperty::GetInfo() const
{
	if (IsEnum())
	{
		return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, "TEnumAsByte<" + MakeUniqueCppName(GetEnum()) + ">");
	}
	return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, "unsigned char");
}
//---------------------------------------------------------------------------
UEClass UEByteProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.ByteProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEUInt16Property
//---------------------------------------------------------------------------
UEProperty::Info UEUInt16Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint16_t), false, "uint16_t");
}
//---------------------------------------------------------------------------
UEClass UEUInt16Property::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.UInt16Property");
	return c;
}
//---------------------------------------------------------------------------
//UEUInt32Property
//---------------------------------------------------------------------------
UEProperty::Info UEUInt32Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint32_t), false, "uint32_t");
}
//---------------------------------------------------------------------------
UEClass UEUInt32Property::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.UInt32Property");
	return c;
}

//---------------------------------------------------------------------------
//UEUInt64Property
//---------------------------------------------------------------------------
UEProperty::Info UEUInt64Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint64_t), false, "uint64_t");
}
//---------------------------------------------------------------------------
UEClass UEUInt64Property::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.UInt64Property");
	return c;
}
//---------------------------------------------------------------------------
//UEInt8Property
//---------------------------------------------------------------------------
UEProperty::Info UEInt8Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int8_t), false, "int8_t");
}
//---------------------------------------------------------------------------
UEClass UEInt8Property::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Int8Property");
	return c;
}
//---------------------------------------------------------------------------
//UEInt16Property
//---------------------------------------------------------------------------
UEProperty::Info UEInt16Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int16_t), false, "int16_t");
}
//---------------------------------------------------------------------------
UEClass UEInt16Property::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Int16Property");
	return c;
}
//---------------------------------------------------------------------------
//UEIntProperty
//---------------------------------------------------------------------------
UEProperty::Info UEIntProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int), false, "int");
}
//---------------------------------------------------------------------------
UEClass UEIntProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.IntProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEInt64Property
//---------------------------------------------------------------------------
UEProperty::Info UEInt64Property::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(int64_t), false, "int64_t");
}
//---------------------------------------------------------------------------
UEClass UEInt64Property::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.Int64Property");
	return c;
}
//---------------------------------------------------------------------------
//UEFloatProperty
//---------------------------------------------------------------------------
UEProperty::Info UEFloatProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(float), false, "float");
}
//---------------------------------------------------------------------------
UEClass UEFloatProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.FloatProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEDoubleProperty
//---------------------------------------------------------------------------
UEProperty::Info UEDoubleProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(double), false, "double");
}
//---------------------------------------------------------------------------
UEClass UEDoubleProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.DoubleProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEBoolProperty
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetFieldSize() const
{
	return UBoolProperty(object).FieldSize();
}
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetByteOffset() const
{
	return UBoolProperty(object).ByteOffset();
}
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetByteMask() const
{
	return UBoolProperty(object).ByteMask();
}
//---------------------------------------------------------------------------
uint8_t UEBoolProperty::GetFieldMask() const
{
	return UBoolProperty(object).FieldMask();
}
//---------------------------------------------------------------------------
UEProperty::Info UEBoolProperty::GetInfo() const
{
	if (IsNativeBool())
	{
		return Info::Create(PropertyType::Primitive, sizeof(bool), false, "bool");
	}
	return Info::Create(PropertyType::Primitive, sizeof(unsigned char), false, "unsigned char");
}
//---------------------------------------------------------------------------
UEClass UEBoolProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.BoolProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEObjectPropertyBase
//---------------------------------------------------------------------------
UEClass UEObjectPropertyBase::GetPropertyClass() const
{
	return UEClass(UObjectPropertyBase(object).PropertyClass());
}
//---------------------------------------------------------------------------
UEClass UEObjectPropertyBase::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.ObjectPropertyBase");
	return c;
}

//---------------------------------------------------------------------------
//UEObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(void*), false, "class " + MakeValidName(GetPropertyClass().GetNameCPP()) + "*");
}
//---------------------------------------------------------------------------
UEClass UEObjectProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.ObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEEncryptedObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEEncryptedObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(void*), false, "class " + MakeValidName(GetPropertyClass().GetNameCPP()) + "*");
}
//---------------------------------------------------------------------------
UEClass UEEncryptedObjectProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.EncryptedObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEClassProperty
//---------------------------------------------------------------------------
UEClass UEClassProperty::GetMetaClass() const
{
	return UEClass(UClassProperty(object).MetaClass());
}
//---------------------------------------------------------------------------
UEProperty::Info UEClassProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(void*), false, "class " + MakeValidName(GetMetaClass().GetNameCPP()) + "*");
}
//---------------------------------------------------------------------------
UEClass UEClassProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.ClassProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEInterfaceProperty
//---------------------------------------------------------------------------
UEClass UEInterfaceProperty::GetInterfaceClass() const
{
	return UEClass(UInterfaceProperty(object).InterfaceClass());
}
//---------------------------------------------------------------------------
UEProperty::Info UEInterfaceProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FScriptInterface), true, "TScriptInterface<class " + MakeValidName(GetInterfaceClass().GetNameCPP()) + ">");
}
//---------------------------------------------------------------------------
UEClass UEInterfaceProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.InterfaceProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEWeakObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEWeakObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Container, sizeof(FWeakObjectPtr), false, "TWeakObjectPtr<class " + MakeValidName(GetPropertyClass().GetNameCPP()) + ">");
}
//---------------------------------------------------------------------------
UEClass UEWeakObjectProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.WeakObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UELazyObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UELazyObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Container, sizeof(FLazyObjectPtr), false, "TLazyObjectPtr<class " + MakeValidName(GetPropertyClass().GetNameCPP()) + ">");
}
//---------------------------------------------------------------------------
UEClass UELazyObjectProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.LazyObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEAssetObjectProperty
//---------------------------------------------------------------------------
UEProperty::Info UEAssetObjectProperty::GetInfo() const
{
	return Info::Create(PropertyType::Container, sizeof(FAssetPtr), false, "TAssetPtr<class >");
}
//---------------------------------------------------------------------------
UEClass UEAssetObjectProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.AssetObjectProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEAssetClassProperty
//---------------------------------------------------------------------------
UEClass UEAssetClassProperty::GetMetaClass() const
{
	return UEClass(UAssetClassProperty(object).MetaClass());
}
//---------------------------------------------------------------------------
UEProperty::Info UEAssetClassProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, "");
}
//---------------------------------------------------------------------------
UEClass UEAssetClassProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.AssetClassProperty");
	return c;
}
//---------------------------------------------------------------------------
//UENameProperty
//---------------------------------------------------------------------------
UEProperty::Info UENameProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FName), true, "struct FName");
}
//---------------------------------------------------------------------------
UEClass UENameProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.NameProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEStructProperty
//---------------------------------------------------------------------------
UEScriptStruct UEStructProperty::GetStruct() const
{
	return UEScriptStruct(UStructProperty(object).Struct());
}
//---------------------------------------------------------------------------
UEProperty::Info UEStructProperty::GetInfo() const
{
	return Info::Create(PropertyType::CustomStruct, GetElementSize(), true, "struct " + MakeUniqueCppName(GetStruct()));
}
//---------------------------------------------------------------------------
UEClass UEStructProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.StructProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEStrProperty
//---------------------------------------------------------------------------
UEProperty::Info UEStrProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FString), true, "struct FString");
}
//---------------------------------------------------------------------------
UEClass UEStrProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.StrProperty");
	return c;
}
//---------------------------------------------------------------------------
//UETextProperty
//---------------------------------------------------------------------------
UEProperty::Info UETextProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FText), true, "struct FText");
}
//---------------------------------------------------------------------------
UEClass UETextProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.TextProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEArrayProperty
//---------------------------------------------------------------------------
UEProperty UEArrayProperty::GetInner() const
{
	return UEProperty(UArrayProperty(object).Inner());
}
//---------------------------------------------------------------------------
UEProperty::Info UEArrayProperty::GetInfo() const
{
	auto inner = GetInner().GetInfo();
	if (inner.Type != PropertyType::Unknown)
	{
		return Info::Create(PropertyType::Container, sizeof(TArray<void*>), false, "TArray<" + inner.CppType + ">");
	}

	return { PropertyType::Unknown };
}
//---------------------------------------------------------------------------
UEClass UEArrayProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.ArrayProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEMapProperty
//---------------------------------------------------------------------------
UEProperty UEMapProperty::GetKeyProperty() const
{
	return UEProperty(UMapProperty(object).KeyProp());
}
//---------------------------------------------------------------------------
UEProperty UEMapProperty::GetValueProperty() const
{
	return UEProperty(UMapProperty(object).ValueProp());
}
//---------------------------------------------------------------------------
UEProperty::Info UEMapProperty::GetInfo() const
{
	auto key = GetKeyProperty().GetInfo();
	auto value = GetValueProperty().GetInfo();
	if (key.Type != PropertyType::Unknown && value.Type != PropertyType::Unknown)
	{
		return Info::Create(PropertyType::Container, 0x50, false, "TMap<" + key.CppType + ", " + value.CppType + ">");
	}

	return { PropertyType::Unknown };
}
//---------------------------------------------------------------------------
UEClass UEMapProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.MapProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEDelegateProperty
//---------------------------------------------------------------------------
UEFunction UEDelegateProperty::GetSignatureFunction() const
{
	return UEFunction(UDelegateProperty(object).SignatureFunction());
}
//---------------------------------------------------------------------------
UEProperty::Info UEDelegateProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FScriptDelegate), true, "struct FScriptDelegate");
}
//---------------------------------------------------------------------------
UEClass UEDelegateProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.DelegateProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEMulticastDelegateProperty
//---------------------------------------------------------------------------
UEFunction UEMulticastDelegateProperty::GetSignatureFunction() const
{
	return UEFunction(UDelegateProperty(object).SignatureFunction());
}
//---------------------------------------------------------------------------
UEProperty::Info UEMulticastDelegateProperty::GetInfo() const
{
	return Info::Create(PropertyType::PredefinedStruct, sizeof(FScriptMulticastDelegate), true, "struct FScriptMulticastDelegate");
}
//---------------------------------------------------------------------------
UEClass UEMulticastDelegateProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.MulticastDelegateProperty");
	return c;
}
//---------------------------------------------------------------------------
//UEEnumProperty
//---------------------------------------------------------------------------
UENumericProperty UEEnumProperty::GetUnderlyingProperty() const
{
	return UENumericProperty(UEnumProperty(object).UnderlyingProp());
}
//---------------------------------------------------------------------------
UEEnum UEEnumProperty::GetEnum() const
{
	return UEEnum(UEnumProperty(object).Enum());
}
//---------------------------------------------------------------------------
UEProperty::Info UEEnumProperty::GetInfo() const
{
	return Info::Create(PropertyType::Primitive, sizeof(uint8_t), false, MakeUniqueCppName(GetEnum()));
}
//---------------------------------------------------------------------------
UEClass UEEnumProperty::StaticClass()
{
	static auto c = Global::Objects->FindClass("Class CoreUObject.EnumProperty");
	return c;
}
//---------------------------------------------------------------------------
int GetBitPosition(uint8_t value)
{
	int i4 = !(value & 0xf) << 2;
	value >>= i4;

	int i2 = !(value & 0x3) << 1;
	value >>= i2;

	int i1 = !(value & 0x1);

	int i0 = (value >> i1) & 1 ? 0 : -8;

	return i4 + i2 + i1 + i0;
}

std::array<int, 2> UEBoolProperty::GetMissingBitsCount(const UEBoolProperty& other) const
{
	if (!other.IsValid())
	{
		return { GetBitPosition(GetByteMask()), -1 };
	}

	if (GetOffset() == other.GetOffset())
	{
		return { GetBitPosition(GetByteMask()) - GetBitPosition(other.GetByteMask()) - 1, -1 };
	}
	return { std::numeric_limits<uint8_t>::digits - GetBitPosition(other.GetByteMask()) - 1, GetBitPosition(GetByteMask()) };
}
#pragma endregion
