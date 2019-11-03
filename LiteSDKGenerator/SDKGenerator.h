#pragma once
#include "TinyFormat.h"
#include <fstream>
#include <unordered_map>
#include <unordered_set>

class UEObject;
class UEEnum;
class UEClass;
class UEScriptStruct;
class UEStruct;
class UEProperty;
enum class UEPropertyFlags : uint64_t;

ref class SDKGenerator
{
public:
	void DumpObjectsTxt(std::string path);
	void DumpSDK(std::string path, bool OneFile);
};

class Package
{
public:
	Package() { packageObj = 0; }

	Package(uint64_t address)
	{
		packageObj = address;
	}

	void Process(UEObject obj);

	bool Save(std::ofstream& o);

	struct Enum
	{
		std::string Name;
		std::string FullName;
		std::vector<std::string> Values;
	};

	struct Member
	{
		std::string Name;
		std::string Type;

		size_t Offset;
		size_t Size;

		size_t Flags;
		std::string FlagsString;

		std::string Comment;
	};

	struct ScriptStruct
	{
		std::string Name;
		std::string FullName;
		std::string NameCpp;
		std::string NameCppFull;

		size_t Size;
		size_t InheritedSize;

		std::vector<Member> Members;
	};

	struct Method
	{
		struct Parameter
		{
			enum class Type
			{
				Default,
				Out,
				Return
			};

			Type ParamType;
			bool PassByReference;
			std::string CppType;
			std::string Name;
			std::string FlagsString;
			static bool MakeType(UEPropertyFlags flags, Type& type);
		};

		std::string FuncAddr;
		size_t Index;
		std::string Name;
		std::string FullName;
		std::vector<Parameter> Parameters;
		std::string FlagsString;
		bool IsNative;
		bool IsStatic;
	};

	struct Class : ScriptStruct
	{
		std::vector<std::string> VirtualFunctions;
		std::vector<Method> Methods;
	};

	void GenerateEnum(UEEnum enumObj);

	void GenerateClass(UEClass obj);

	void GenerateScriptStruct(UEScriptStruct obj);

	void GenerateMethods(const UEClass& classObj, std::vector<Method>& methods);

	void GenerateMembers(const UEStruct& structObj, size_t offset, const std::vector<UEProperty>& properties, std::vector<Member>& members);

	std::string GetPackageName();
private:
	uint64_t packageObj;
	std::vector<Enum> enums; 
	std::vector<ScriptStruct> scriptStructs;
	std::vector<Class> classes;
};