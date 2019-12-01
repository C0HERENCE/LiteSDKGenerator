#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x4669C10;
		static const uint64 FUObjectArray = 0x454ea60-0x10;
		//GNames
		static const uint64 chunksize = 0x3F94;
		static const uint64 static_gnames = 0x8BC30;
		// UObject
		static const uint64 ulcass = 0x8;
		static const uint64 internal_id = 0x18;
		static const uint64 name = 0x10;
		static const uint64 outer = 0x20;
		// FName
		static const uint64 number = 0x0;
		static const uint64 comparison_id = 0x4;
		// UField
		static const uint64 next = 0x30;
		// UEnum
		static const uint64 enumNames = 0x48;
		// UStruct
		static const uint64 superfield = 0x88;
		static const uint64 property_size = 0x38;
		static const uint64 children = 0x58;
		// UFunction
		static const uint64 func = 0xB0;
		static const uint64 function_flags = 0xD0;
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
			uint64 v17;
			LODWORD(v17) = (~(v7 - 1539350684) + 1755220623) ^ 0x8222160C;
			HIDWORD(v17) = (~(~HIDWORD(v7) + 1245697400) + 584263515) ^ 0x3ED032D;
			return v17;
		}
		static int32 internal_id(uint32 v256)
		{
			return __ROL4__(v256 ^ 0x9B04FC7F, 10) ^ (__ROL4__(v256 ^ 0x9B04FC7F, 10) << 16) ^ 0x7B67D5A7;
		}
		static uint64 uclass(uint64 v24)
		{
			return __ROL8__(v24 ^ 0x389317838CF0AC9Ei64, 28) ^ (__ROL8__(v24 ^ 0x389317838CF0AC9Ei64, 28) << 32) ^ 0x8289130F79D4E572ui64;
		}
		static uint64 outer(uint64 v30)
		{
			return __ROR8__(v30 ^ 0x7CBA09BDCD309DC3i64, 21) ^ (__ROR8__(v30 ^ 0x7CBA09BDCD309DC3i64, 21) << 32) ^ 0xB41286678E61FB0Aui64;
		}
		//FName
		static int32 comparison_id(uint32 v252)
		{
			return __ROL4__(v252 ^ 0xE570B9D4, 16) ^ (__ROL4__(v252 ^ 0xE570B9D4, 16) << 16) ^ 0xE06F4CF0;
		}
		static int32 number(uint32 v249)
		{
			return __ROR4__(v249 ^ 0x4CF0AC9F, 4) ^ (__ROR4__(v249 ^ 0x4CF0AC9F, 4) << 16) ^ 0x5CA4E570;
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
	static std::string AuthorNotes = "By COHERENCE";
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

static const uint64 uproperty_size = 0x{11:X};)";
}