#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x46386b0;
		static const uint64 FUObjectArray = 0x443e848-0x10;
		//GNames
		static const uint64 chunksize = 0x3e94;
		static const uint64 static_gnames = 0xffffffffffef8320;
		// UObject
		static const uint64 ulcass = 0x20;
		static const uint64 internal_id = 0x8;
		static const uint64 name = 0x10;
		static const uint64 outer = 0x18;
		// FName
		static const uint64 number = 0x4;
		static const uint64 comparison_id = 0x0;
		// UField
		static const uint64 next = 0x28;
		// UEnum
		static const uint64 enumNames = 0x40;
		// UStruct
		static const uint64 superfield = 0x50;
		static const uint64 property_size = 0x88;
		static const uint64 children = 0x30;
		// UFunction
		static const uint64 func = 0x98;
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
			uint64 v17;
			LODWORD(v17) = __ROL4__(__ROL4__(v7 - 829357123, 16) - 1835374268, 16) ^ 0x29096587;
			HIDWORD(v17) = __ROR4__(__ROR4__(HIDWORD(v7) + 868271848, 8) + 1994878927, 8) ^ 0x57D95719;
			return v17;
		}
		static int32 internal_id(uint32 v2)
		{
			return __ROR4__(v2 ^ 0x6FB32963, 15) ^ (__ROR4__(v2 ^ 0x6FB32963, 15) << 16) ^ 0xD046116B;
		}
		static uint64 uclass(uint64 v6)
		{
			return __ROL8__(v6 ^ 0xFD3D77B830EFBB79ui64, 7) ^ (__ROL8__(v6 ^ 0xFD3D77B830EFBB79ui64, 7) << 32) ^ 0x79B88A6A72CF924Ci64;
		}
		static uint64 outer(uint64 v18)
		{
			return __ROR8__(v18 ^ 0xE792E9D2E2F6655i64, 16) ^ (__ROR8__(v18 ^ 0xE792E9D2E2F6655i64, 16) << 32) ^ 0x74CF2AD3CCA793E3i64;
		}
		//FName
		static int32 comparison_id(uint32 v10)
		{
			return __ROL4__(v10 ^ 0x179C8BC9, 12) ^ (__ROL4__(v10 ^ 0x179C8BC9, 12) << 16) ^ 0x6BC4F232;
		}
		static int32 number(uint32 v6)
		{
			return __ROL4__(v6 ^ 0x8B6B3E42, 8) ^ (__ROL4__(v6 ^ 0x8B6B3E42, 8) << 16) ^ 0x877DA5AD;
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