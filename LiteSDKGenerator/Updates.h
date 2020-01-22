#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x453B6F0;
		static const uint64 ObjObjects = 0x46BCDB0;
		//GNames
		static const uint64 chunksize = 0x4030;
		static const uint64 static_gnames = 0x11EA78;
		// UObject
		static const uint64 ulcass = 0x20;
		static const uint64 internal_id = 0x1c;
		static const uint64 name = 0x14;
		static const uint64 outer = 0x8;
		// FName
		static const uint64 number = 0x4;
		static const uint64 comparison_id = 0x0;
		// UField
		static const uint64 next = 0x28;
		// UEnum
		static const uint64 enumNames = 0x40;
		// UStruct
		static const uint64 superfield = 0x68;
		static const uint64 property_size = 0x88;
		static const uint64 children = 0x50;
		// UFunction
		static const uint64 func = 0x90;
		static const uint64 function_flags = 0xB8;
		// UProperty
		static const uint64 array_dim = 0x30;
		static const uint64 element_size = 0x34;
		static const uint64 offset = 0x44;
		static const uint64 property_flag = 0x38;

		static const uint64 uproperty_size = 0x70;
	};

	class Dec
	{
	public:
		// UObject
		static uint64 objobjects(uint64 v7)
		{
			uint64 add = ((v7 & 0x15151515 ^ v7 & 0xEAEAEAEA) - 1960050811) ^ 0x8B2BFF85;
			HIDWORD(add) = 0x0000021e; // manual edit here.
			return add;
		}
		static int32 internal_id(uint32 v248)
		{
			return __ROL4__(v248 ^ 0x3F134169, 5) ^ (__ROL4__(v248 ^ 0x3F134169, 5) << 16) ^ 0x7A7E1103;
		}
		static uint64 uclass(uint64 v14)
		{
			return __ROL8__(v14 ^ 0x6D93A24294179303i64, 19) ^ (__ROL8__(v14 ^ 0x6D93A24294179303i64, 19) << 32) ^ 0xE87A094B09D169B2ui64;
		}
		static uint64 outer(uint64 v30)
		{
			return __ROR8__(v30 ^ 0x6215B3BA387150AAi64, 28) ^ (__ROR8__(v30 ^ 0x6215B3BA387150AAi64, 28) << 32) ^ 0x479B8E128B695D5Ai64;
		}
		//FName
		static int32 comparison_id(uint32 v15)
		{
			return __ROR4__(v15 ^ 0x7766ED5E, 14) ^ (__ROR4__(v15 ^ 0x7766ED5E, 14) << 16) ^ 0xF159012D;
		}
		static int32 number(uint32 v6)
		{
			return __ROR4__(v6 ^ 0x12DF074, 4) ^ (__ROR4__(v6 ^ 0x12DF074, 4) << 16) ^ 0x9A387766;
		}
	};
}

namespace Settings
{
	static std::string ProcessName = "PUBGLite-Win64-Shipping";
	static std::string MoudleName = "PUBGLite-Win64-Shipping.exe";
	static std::string WindowsClass = "UnrealWindow";
	static std::string WindowsCaption = "PUBG LITE ";
	static std::string SDKFolderName = "PUBGLITE_SDK";
	static std::string SDKAllFileName = "SDK_All.cpp";
	static std::string GObjectsFileName = "ObjectsDump.txt";
	static std::string NamesFileName = "NamesDump.txt";
	static std::string AuthorNotes = "By COHERENCE\nSDK Generator: https://github.com/C0HERENCE/LiteSDKGenerator \n";
	static std::string OutPutString =
		R"(// UField
static const uint64 next = 0x{0:X};
// UEnum
static const uint64 enumNames = 0x{1:X};
// UStruct
static const uint64 superfield = 0x{2:X};
static const uint64 property_size = 0x{3:X};
static const uint64 children = 0x{4:X};
// UFunction
static const uint64 func = 0x{5:X};
static const uint64 function_flags = 0x{6:X};
// UProperty
static const uint64 array_dim = 0x{7:X};
static const uint64 element_size = 0x{8:X};
static const uint64 offset = 0x{9:X};
static const uint64 property_flag = 0x{10:X};

static const uint64 uproperty_size = 0x{11:X};\n)";
}