#include "Global.h"
#include "SDKTypes.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace LiteSDKGenerator;

using namespace Updates;
using namespace Settings;

std::string managedStrToNative(System::String^ sysstr);

std::string managedStrToNative(System::String^ sysstr)
{
	using System::IntPtr;
	using System::Runtime::InteropServices::Marshal;

	IntPtr ip = Marshal::StringToHGlobalAnsi(sysstr);
	std::string outString = static_cast<const char*>(ip.ToPointer());
	Marshal::FreeHGlobal(ip);
	return outString;
}

[STAThread]
void Main(array<String^>^ args)
{
	Application::Run(Global::MainForm);
}

System::Void Main::Main_Load(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = ManagedStr(ProcessName);
	textBox2->Text = ManagedStr(MoudleName);
	bool status = Global::GameMemory->Init();
	if (!status)
	{
		MessageBox::Show("Game not Found!");
		Application::Exit();
	}
	Global::Names->Init(Global::GameMemory->GetBase() + Off::GNames);
	Global::Objects->Init(Global::GameMemory->GetBase() + Off::FUObjectArray);
	Console::WriteLine("GNames: 0x{0:x}\nNamesNum: {1}", Global::Names->GetAddress(), Global::Names->GetNamesNum());
	Console::WriteLine("GObjects: 0x{0:x}\nObjectsNum: {1}", Global::Objects->GetAddress(), Global::Objects->GetObjectsNum());
}

System::Void Main::Main_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	Global::GameMemory->Close();
}

System::Void Main::btnDumpSDK_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!cbAll->Checked && !cbSDK->Checked && !cbGObj->Checked)
	{
		MessageBox::Show("Check at least one output type");
		return;
	}
	if (folderBrowserDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		std::string OutputDirectory = NativeStr(folderBrowserDialog1->SelectedPath + "\\");
		if (cbSDK->Checked)
		{
			String^ sdkdir = ManagedStr(OutputDirectory + SDKFolderName);
			if (!Directory::Exists(sdkdir))
				Directory::CreateDirectory(sdkdir);
			Global::Generator->DumpSDK(OutputDirectory + SDKFolderName + "\\", false);
		}
		if (cbAll->Checked)
		{
			Global::Generator->DumpSDK(OutputDirectory, true);
		}
		if (cbGObj->Checked)
		{
			Global::Generator->DumpObjectsTxt(OutputDirectory);
		}

		if (MessageBox::Show("Show Files In Explorer?", "Dump Finished", MessageBoxButtons::YesNo) == ::DialogResult::Yes)
		{
			Process::Start(ManagedStr(OutputDirectory));
		}
	}
}

System::Void Main::btnNamesDump_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (folderBrowserDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
	{
		std::string OutputDirectory = NativeStr(folderBrowserDialog1->SelectedPath + "\\");
		Global::Generator->DumpNamesTxt(OutputDirectory);
		if (MessageBox::Show("Show Files In Explorer?", "Dump Finished", MessageBoxButtons::YesNo) == ::DialogResult::Yes)
		{
			Process::Start(ManagedStr(OutputDirectory));
		}
	}
}

System::Void Main::btnTest_Click(System::Object^ sender, System::EventArgs^ e)
{
	Console::WriteLine(String::Format("Name 101: {0}", ManagedStr(Global::Names->GetById(101))));
	Console::WriteLine(String::Format("GObject Address : {0:X}", Global::Objects->GetAddress()));

	for (int i = 0; i < 5; i++)
	{
		Console::WriteLine("Object Address: {0:X}", Global::Objects->GetById(i).GetAddress());
		Console::WriteLine("Index ID: {0}", Global::Objects->GetById(i).GetIndex());
		Console::Write("Name ID: {0} ", Global::Objects->GetById(i).GetComparisonIndex());
		Console::WriteLine("Name: {0}", ManagedStr(Global::Names->GetById(Global::Objects->GetById(i).GetComparisonIndex())));
		Console::Write("Class ID: {0} ", Global::Objects->GetById(i).GetClass().GetIndex());
		Console::WriteLine("Name: {0}", ManagedStr(Global::Names->GetById(Global::Objects->GetById(Global::Objects->GetById(i).GetClass().GetIndex()).GetComparisonIndex())));
		Console::Write("Outer ID: {0} ", Global::Objects->GetById(i).GetOuter().GetIndex());
		Console::WriteLine("Name: {0}", ManagedStr(Global::Names->GetById(Global::Objects->GetById(Global::Objects->GetById(i).GetClass().GetIndex()).GetComparisonIndex())));
		Console::WriteLine("");
	}
}

Void Main::btnFindGName_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Make sure you've updated them in Updates.cpp:\n"
		+ "Off::GNames" + "\n"
		+ "Off::chunksize");
	Console::WriteLine("Finding static GNames from offset: {0:X}, chunksize = {1:X}", Global::GameMemory->GetBase() + Off::GNames, Off::chunksize);
	for (int i = -0x50000; i <= 0x50000; i++)
	{
		uint64 GNamesPtr = Global::GameMemory->Read64(Global::GameMemory->GetBase() + Off::GNames + i * 4);
		Global::Names->SetBase(GNamesPtr);
		if (Global::Names->GetById(1) == "ByteProperty")
		{
			Console::WriteLine(String::Format("Found static GNames at offset: {0:X} , step = {1}", i * 4 , i));
			return;
		}
	}
	Console::WriteLine("Couldn't found");
}


System::Void Main::btnAutoUpdate_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Make sure you've updated them in Updates.cpp:\n"
		+ "Off:\n"
		+ "\\\\Main" + "\n"
		+ "\\\\GNames" + "\n"
		+ "\\\\UObject" + "\n"
		+ "\\\\FName" + "\n"
		+ "Dec:\n"
		+ "\\\\UObject" + "\n"
		+ "\\\\FName" + "\n");
	std::unordered_map<std::string, uint64> searchingString;
	searchingString.insert(std::pair<std::string, int>{"ScriptStruct CoreUObject.Vector", 0});
	searchingString.insert(std::pair<std::string, int>("FloatProperty CoreUObject.Vector.X", 0));
	searchingString.insert(std::pair<std::string, int>("FloatProperty CoreUObject.Vector.Y", 0));
	searchingString.insert(std::pair<std::string, int>("FloatProperty CoreUObject.Vector.Z", 0));
	searchingString.insert(std::pair<std::string, int>("Class Engine.Actor", 0));
	searchingString.insert(std::pair<std::string, int>("Class Engine.Pawn", 0));
	searchingString.insert(std::pair<std::string, int>("Class CoreUObject.Property", 0));
	searchingString.insert(std::pair<std::string, int>("Function Engine.Actor.WasRecentlyRendered", 0));
	searchingString.insert(std::pair<std::string, int>("Enum Engine.ETextGender", 0));
	progressBar1->Maximum = 9;
	int count = 0;
	for (int i = 0; i < Global::Objects->GetObjectsNum(); i++)
	{
		auto obj = Global::Objects->GetById(i);
		if (searchingString.count(obj.GetFullName()) == 1)
		{
			searchingString[obj.GetFullName()] = Global::Objects->GetById(i).GetAddress();
			count++;
			progressBar1->Value = count;
			if (count == 9)
			{
				break;
			}
		}
	}
	Console::WriteLine("Auto Update Result:\n");
	int next, enumNames, array_dim, element_size, offset, property_flag, superfield, property_size, children, function_flags, func, uproperty_size;
	for (int i = 0x20; i < 0x50; i += 4)
	{
		uint64 nextPtr = Global::GameMemory->Read64(searchingString["FloatProperty CoreUObject.Vector.X"] + i);
		if (nextPtr == searchingString["FloatProperty CoreUObject.Vector.Y"] && Global::GameMemory->Read64(searchingString["FloatProperty CoreUObject.Vector.Y"] + i) == searchingString["FloatProperty CoreUObject.Vector.Z"])
		{
			next = i;
			break;
		}
	}
	for (int i = 0x30; i < 0xa0; i += 4)
	{
		if (Global::GameMemory->Read32(searchingString["Enum Engine.ETextGender"] + i + 0x8) == 0x4)
		{
			if (Global::GameMemory->Read32(searchingString["Enum Engine.ETextGender"] + i + 0xc) == 0x18)
			{
				enumNames = i;
				break;
			}
		}
	}
	for (int i = 0x28; i < 0xa0; i += 4)
	{
		if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.Z"] + i) == 1)
		{
			if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.Y"] + i) == 1)
			{
				if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.X"] + i) == 1)
				{
					array_dim = i;
					break;
				}
			}
		}
	}
	for (int i = 0x28; i < 0xa0; i += 4)
	{
		if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.Z"] + i) == 4)
		{
			if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.Y"] + i) == 4)
			{
				if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.X"] + i) == 4)
				{
					element_size = i;
					break;
				}
			}
		}
	}
	for (int i = 0x28; i < 0xa0; i += 4)
	{
		if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.Z"] + i) == 0x8)
		{
			if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.Y"] + i) == 0x4)
			{
				if (Global::GameMemory->Read32(searchingString["FloatProperty CoreUObject.Vector.X"] + i) == 0x0)
				{
					offset = i;
					break;
				}
			}
		}
	}
	for (int i = 0x30; i < 0xa0; i += 4)
	{
		if (StringifyFlags(static_cast<UEPropertyFlags>(Global::GameMemory->Read<FQWord>(searchingString["FloatProperty CoreUObject.Vector.Z"] + i).A)) == "Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData")
		{
			if (StringifyFlags(static_cast<UEPropertyFlags>(Global::GameMemory->Read<FQWord>(searchingString["FloatProperty CoreUObject.Vector.Y"] + i).A)) == "Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData")
			{
				if (StringifyFlags(static_cast<UEPropertyFlags>(Global::GameMemory->Read<FQWord>(searchingString["FloatProperty CoreUObject.Vector.X"] + i).A)) == "Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData")
				{
					property_flag = i;
					break;
				}
			}
		}
	}
	for (int i = 0x28; i < 0xa0; i += 4)
	{
		if (Global::GameMemory->Read64(searchingString["Class Engine.Pawn"] + i) == searchingString["Class Engine.Actor"])
		{
			superfield = i;
			break;
		}
	}
	for (int i = 0x24; i < 0xe0; i += 4)
	{
		if (Global::GameMemory->Read32(searchingString["ScriptStruct CoreUObject.Vector"] + i) == 12)
		{
			property_size = i;
			break;
		}
	}
	for (int i = 0x28; i < 0xa0; i += 4)
	{
		if (Global::GameMemory->Read64(searchingString["ScriptStruct CoreUObject.Vector"] + i) == searchingString["FloatProperty CoreUObject.Vector.X"])
		{
			children = i;
			break;
		}
	}
	for (int i = 0x70; i < 0xff; i += 4)
	{
		if (StringifyFlags(static_cast<UEFunctionFlags>(Global::GameMemory->Read64(searchingString["Function Engine.Actor.WasRecentlyRendered"] + i))) == "Final, Native, Public, BlueprintCallable, BlueprintPure, Const")
		{
			function_flags = i;
		}
	}
	for (int i = 0x70; i < 0xff; i += 4)
	{
		func = Global::GameMemory->Read32(searchingString["Function Engine.Actor.WasRecentlyRendered"] + i);
		if (func >= 0x7FF0 && func <= 0x7FFF)
		{
			func = i;
			func = i - 0x4;
			break;
		}
	}
	uproperty_size = Global::GameMemory->Read32(searchingString["Class CoreUObject.Property"] + property_size);
	Console::Write(ManagedStr(OutPutString),next,enumNames,superfield,property_size,children,func,function_flags,array_dim,element_size,offset,property_flag,uproperty_size);
}