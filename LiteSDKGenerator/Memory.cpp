#include "Global.h"

bool Memory::Init()
{
	HANDLE hToken = nullptr;
	LUID luid;

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken)) return FALSE;
	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid)) return FALSE;

	TOKEN_PRIVILEGES tokenPriv;
	tokenPriv.PrivilegeCount = 1;
	tokenPriv.Privileges[0].Luid = luid;
	tokenPriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!AdjustTokenPrivileges(hToken, FALSE, &tokenPriv, sizeof(TOKEN_PRIVILEGES), NULL, NULL))
	{
		Global::LogLine("SeDebugPrivilege Error: " + (int)GetLastError());
		return false;
	}

	HWND hWnd = FindWindow(Settings::WindowsClass.c_str(), Settings::WindowsCaption.c_str());
	DWORD Pid = 0;
	GetWindowThreadProcessId(hWnd, &Pid);
	if (Pid == 0)
	{
		Global::LogLine("GetWindowThreadProcessId Error: " + (int)GetLastError());
		return false;
	}
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, Pid);
	if (hProcess == 0)
	{
		Global::LogLine("OpenProcess Error: " + (int)GetLastError());
		return false;
	}

	HMODULE hMods[512];
	DWORD cb;
	if (EnumProcessModulesEx(hProcess, hMods, sizeof(hMods), &cb, LIST_MODULES_ALL))
	{
		char szModName[MAX_PATH] = { NULL };
		for (int i = 0; i < cb / sizeof(HMODULE); i++)
		{
			GetModuleBaseNameA(hProcess, hMods[i], szModName, MAX_PATH);
			if (!Settings::MoudleName.compare(szModName))
			{
				Global::LogLine("PID: " + Pid.ToString());
				Global::LogLine(String::Format("Base: {0:x}", (uint64_t)hMods[i]));
				Global::LogLine("Handle: " + ((uint64)hProcess).ToString());
				Base = (uint64_t)hMods[i];
				return true;
			}
		}
	}
	else
	{
		Global::LogLine("EnumProcessModulesEx Error: " + (int)GetLastError());
		return false;
	}
	Global::LogLine("Module not found");
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