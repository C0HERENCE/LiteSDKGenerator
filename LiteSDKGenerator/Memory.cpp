#include "Global.h"

bool Memory::Init(String^ ProcessName, String^ ModuleName)
{
	HWND hWnd = FindWindow("UnrealWindow", "PUBG LITE ");
	DWORD Pid = 0;
	GetWindowThreadProcessId(hWnd, &Pid);
	if (Pid == 0)
	{
		Console::WriteLine("Process not found");
		return false;
	}
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, Pid);
	HMODULE hMods[512];
	DWORD cb;
	if (EnumProcessModulesEx(hProcess, hMods, sizeof(hMods), &cb, LIST_MODULES_ALL))
	{
		char szModName[MAX_PATH] = { NULL };
		for (int i = 0; i < cb / sizeof(HMODULE); i++)
		{
			GetModuleBaseNameA(hProcess, hMods[i], szModName, MAX_PATH);
			if (!ModuleName->CompareTo(gcnew String(szModName)))
			{
				Global::MainForm->textBox3->Text = Pid.ToString();
				Global::MainForm->textBox4->Text = String::Format("{0:x}", (uint64_t)hMods[i]);
				Global::MainForm->textBox5->Text = ((uint64)hProcess).ToString();
				Base = (uint64_t)hMods[i];
				return true;
			}
		}
	}
	else
	{
		Console::WriteLine("EnumProcessModulesEx Error: " + (int)GetLastError());
	}
	Console::WriteLine("Module not found");
	return false;
}

uint64_t Memory::GetBase()
{
	return Base;
}

void Memory::Close()
{
	CloseHandle(hProcess);
}

uint64_t Memory::Read64(uint64_t address)
{
	return Read<uint64_t>(address);
}

uint32_t Memory::Read32(uint64_t address)
{
	return Read<uint32_t>(address);
}

bool Memory::ReadWString(SIZE_T address, wchar_t* buff, DWORD bufSize)
{
	return ReadProcessMemory(hProcess, (LPCVOID)address, buff, bufSize, NULL);
}

bool Memory::ReadString(SIZE_T address, char* buff, DWORD bufSize)
{
	return ReadProcessMemory(hProcess, (LPCVOID)address, buff, bufSize, NULL);
}