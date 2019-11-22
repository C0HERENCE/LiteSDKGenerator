#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x46216b0;
		static const uint64 FUObjectArray = 0x446DB80-0x10;
		//GNames
		static const uint64 chunksize = 0x40c4;
		static const uint64 static_gnames = 0x632B0;
		// UObject
		static const uint64 ulcass = 0x10;
		static const uint64 internal_id = 0x24;
		static const uint64 name = 0x8;
		static const uint64 outer = 0x18;
		// FName
		static const uint64 number = 0x0;
		static const uint64 comparison_id = 0x4;
		// UField
		static const uint64 next = 0x28;
		// UEnum
		static const uint64 enumNames = 0x40;
		// UStruct
		static const uint64 superfield = 0x78;
		static const uint64 property_size = 0x40;
		static const uint64 children = 0x58;
		// UFunction
		static const uint64 func = 0xD0;
		static const uint64 function_flags = 0xC4;
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
			LODWORD(v17) = __ROL4__(__ROL4__(v7 - 1369635907, 16) + 1397148004, 16) ^ 0x9E9C5A7;
			HIDWORD(v17) = __ROR4__(__ROR4__(HIDWORD(v7) + 327993064, 8) + 919817967, 8) ^ 0x77B977F9;
			return v17;
		}
		static int32 internal_id(uint32 v2)
		{
			return __ROL4__(v2 ^ 0xE882B26A, 3) ^ (__ROL4__(v2 ^ 0xE882B26A, 3) << 16) ^ 0xE85ADD15;
		}
		static uint64 uclass(uint64 v6)
		{
			return __ROR8__(v6 ^ 0xFDD4DDB937875595ui64, 11) ^ (__ROR8__(v6 ^ 0xFDD4DDB937875595ui64, 11) << 32) ^ 0x26C7FBC969BB61A5i64;
		}
		static uint64 outer(uint64 v18)
		{
			return __ROL8__(v18 ^ 0xA47650BD9B4D3DFBui64, 2) ^ (__ROL8__(v18 ^ 0xA47650BD9B4D3DFBui64, 2) << 32) ^ 0x1AAAD97F047CB5FFi64;
		}
		//FName
		static int32 comparison_id(uint32 v6)
		{
			return __ROR4__(v6 ^ 0x6C1E4D14, 1) ^ (__ROR4__(v6 ^ 0x6C1E4D14, 1) << 16) ^ 0x210A6C1E;
		}
		static int32 number(uint32 v10)
		{
			return __ROR4__(v10 ^ 0x37875594, 11) ^ (__ROR4__(v10 ^ 0x37875594, 11) << 16) ^ 0x81F61A4;
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