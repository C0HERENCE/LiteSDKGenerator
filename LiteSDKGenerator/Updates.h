#pragma once
#include "UtilsDefs.h"
#include "Memory.h"

namespace Updates
{
	class Off
	{
	public:
		// Main
		static const uint64 GNames = 0x470c7d0;
		static const uint64 ObjObjects = 0x4594d00;
		//GNames
		static const uint64 chunksize = 0x4100;
		static const uint64 static_gnames = 0xFFFFFFFFFFEFE4B8;
		// UObject
		static const uint64 ulcass = 0x28;
		static const uint64 internal_id = 0x20;
		static const uint64 name = 0xc;
		static const uint64 outer = 0x18;
		// FName
		static const uint64 number = 0x4;
		static const uint64 comparison_id = 0x0;
		// UField
		static const uint64 next = 0x30;
		// UEnum
		static const uint64 enumNames = 0x48;
		// UStruct
		static const uint64 superfield = 0x38;
		static const uint64 property_size = 0x80;
		static const uint64 children = 0x68;
		// UFunction
		static const uint64 func = 0xD0;
		static const uint64 function_flags = 0x98;
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
			auto v9 = ((unsigned __int16)v7 ^ ((unsigned int)v7 >> 16) | ((unsigned __int16)__ROL2__(WORD1(v7), 8) << 16)) - 2094852339;
			__int64 v19 = 0;
			LODWORD(v19) = (v9 & 0xFFFF0000 | (unsigned __int16)((v7 ^ WORD1(v7)) + 5901) ^ (v9 >> 16)) ^ 0x8323170D;
			HIDWORD(v19) = ((unsigned __int16)__ROR2__(
				(__ROR2__(WORD2(v7) ^ HIWORD(v7), 8) + 557) ^ (((HIDWORD(v7) & 0xFFFF0000 | (unsigned __int16)__ROR2__(WORD2(v7) ^ HIWORD(v7), 8))
					+ 49021485) >> 16),
				8) | ((unsigned __int16)__ROL2__(
				((HIDWORD(v7) & 0xFFFF0000 | (unsigned __int16)__ROR2__(WORD2(v7) ^ HIWORD(v7), 8))
					+ 49021485) >> 16,
					8) << 16)) ^ 0xFD13FDD3;
			HIDWORD(v19) = 0x1f9;
			// edit here
			return v19;
		}
		static int32 internal_id(uint32 v2)
		{
			return __ROL4__(v2 ^ 0x3724B00F, 6) ^ (__ROL4__(v2 ^ 0x3724B00F, 6) << 16) ^ 0x2B87CB84;
		}
		static uint64 uclass(uint64 v6)
		{
			return __ROL8__(v6 ^ 0x9808D4BF5051AF1Cui64, 16) ^ (__ROL8__(v6 ^ 0x9808D4BF5051AF1Cui64, 16) << 32) ^ 0x94F86D957C715572ui64;
		}
		static uint64 outer(uint64 v18)
		{
			return __ROR8__(v18 ^ 0x98AE43538294AE59ui64, 25) ^ (__ROR8__(v18 ^ 0x98AE43538294AE59ui64, 25) << 32) ^ 0x7FF84E835C4C905Fi64;
		}
		//FName
		static int32 comparison_id(uint32 v10)
		{
			return __ROR4__(v10 ^ 0x9573A54F, 15) ^ (__ROR4__(v10 ^ 0x9573A54F, 15) << 16) ^ 0xFEFD1DCA;
		}
		static int32 number(uint32 v6)
		{
			return __ROR4__(v6 ^ 0x1DCAE337, 1) ^ (__ROR4__(v6 ^ 0x1DCAE337, 1) << 16) ^ 0x303C9573;
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

static const uint64 uproperty_size = 0x{11:X};)";
}