#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x45e7420;
		static const uint64 ObjObjects = 0x45e8a00;
		//GNames
		static const uint64 chunksize = 0x40f0;
		static const uint64 static_gnames = 0x86AF8;
		// UObject
		static const uint64 ulcass = 0x10;
		static const uint64 internal_id = 0x20;
		static const uint64 name = 0x18;
		static const uint64 outer = 0x28;
		// FName
		static const uint64 number = 0x4;
		static const uint64 comparison_id = 0x0;
		// UField
		static const uint64 next = 0x30;
		// UEnum
		static const uint64 enumNames = 0x48;
		// UStruct
		static const uint64 superfield = 0x40;
		static const uint64 property_size = 0x48;
		static const uint64 children = 0x60;
		// UFunction
		static const uint64 func = 0x98;
		static const uint64 function_flags = 0xA0;
		// UProperty
		static const uint64 array_dim = 0x38;
		static const uint64 element_size = 0x3C;
		static const uint64 offset = 0x4C;
		static const uint64 property_flag = 0x40;

		static const uint64 uproperty_size = 0x78;
	};

	class Dec
	{
	public:
		// UObject
		static uint64 objobjects(uint64 v7)
		{
			uint64 v392;
			LODWORD(v392) = (v7 - 1524127531) ^ 0x95F5A15B;
			HIDWORD(v392) = (HIDWORD(v7) - 301227509) ^ 0xEB85EBC5;
			return v392;
		}
		static int32 internal_id(uint32 v248)
		{
			return __ROR4__(v248 ^ 0xF975671B, 5) ^ (__ROR4__(v248 ^ 0xF975671B, 5) << 16) ^ 0x6E9E74C0;;
		}
		static uint64 uclass(uint64 v6)
		{
			return __ROL8__(v6 ^ 0x28F17C97CE8EDCD2i64, 13) ^ (__ROL8__(v6 ^ 0x28F17C97CE8EDCD2i64, 13) << 32) ^ 0xCBE32EC1DB22E7ADui64;
		}
		static uint64 outer(uint64 v18)
		{
			return __ROR8__(v18 ^ 0x9E64E044D0CC1596ui64, 6) ^ (__ROR8__(v18 ^ 0x9E64E044D0CC1596ui64, 6) << 32) ^ 0xADA45B881BD3BC1Fui64;
		}
		//FName
		static int32 comparison_id(uint32 v10)
		{
			return __ROL4__(v10 ^ 0x6F08BDBC, 12) ^ (__ROL4__(v10 ^ 0x6F08BDBC, 12) << 16) ^ 0x5EA13260;
		}
		static int32 number(uint32 v6)
		{
			return __ROL4__(v6 ^ 0x216EDEF7, 8) ^ (__ROL4__(v6 ^ 0x216EDEF7, 8) << 16) ^ 0x20DF5F52;
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