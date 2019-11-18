#pragma once
#include <Windows.h>
#include <Psapi.h>
#include <string>
#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Diagnostics;

ref class Memory
{
public:
	bool Memory::Init(String^, String^);

	void Close();

	uint64_t GetBase();

	template<class T>
	T Read(uint64_t address)
	{
		T buff;
		ReadProcessMemory(hProcess, (LPCVOID)address, &buff, sizeof(T), NULL);
		return buff;
	}

	uint64_t Read64(uint64_t address);

	uint32_t Read32(uint64_t address);

	bool ReadWString(SIZE_T address, wchar_t* buff, DWORD bufSize);

	bool Memory::ReadString(SIZE_T address, char* buff, DWORD bufSize);

private:
	HANDLE hProcess;

	uint64_t Base;
};