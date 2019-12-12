#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x46daa30L;
		static const uint64 FUObjectArray = 0x4513CD0;
		//GNames
		static const uint64 chunksize = 0x40e0;
		static const uint64 static_gnames = 0xFFFFFFFFFFECB538;
		// UObject
		static const uint64 ulcass = 0x28;
		static const uint64 internal_id = 0x10;
		static const uint64 name = 0x8;
		static const uint64 outer = 0x18;
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
			LODWORD(v17) = __ROL4__(__ROL4__(v7, 16) + 2096893124, 16) ^ 0x7CFC0CC4;
			HIDWORD(v17) = __ROR4__(__ROR4__(HIDWORD(v7), 8) + 2068020036, 8) ^ 0x84BC84BC;
			return v17;
		}
		static int32 internal_id(uint32 v248)
		{
			return __ROL4__(v248 ^ 0x4DD4BB1D, 1) ^ (__ROL4__(v248 ^ 0x4DD4BB1D, 1) << 16) ^ 0xC9F69B5F;
		}
		static uint64 uclass(uint64 v6)
		{
			return __ROR8__(v6 ^ 0xC31F8BC077812E5i64, 9) ^ (__ROR8__(v6 ^ 0xC31F8BC077812E5i64, 9) << 32) ^ 0xBA2A0887923CD98Eui64;
		}
		static uint64 outer(uint64 v17)
		{
			return v17 ^ 0x1A68193902D7654Ai64 ^ ((v17 ^ 0x1A68193902D7654Ai64) << 32) ^ 0xE6629481E8442DAAui64;
		}
		//FName
		static int32 comparison_id(uint32 v10)
		{
			return  __ROR4__(v10 ^ 0x5B827462, 4) ^ (__ROR4__(v10 ^ 0x5B827462, 4) << 16) ^ 0x68B90FAD;
		}
		static int32 number(uint32 v6)
		{
			return __ROR4__(v6 ^ 0xFB43D094, 8) ^ (__ROR4__(v6 ^ 0xFB43D094, 8) << 16) ^ 0xC1DC4D68;
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