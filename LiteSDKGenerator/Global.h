#pragma once
#include "Main.h"
#include "Memory.h"
#include "SDKGenerator.h"
#include "Updates.h"
#include <unordered_map>

class UEObject;
class UEClass;

ref class NamesStore
{
public:
	void Init(uint64 address);

	std::string GetById(int);

	uint64 GetAddress();

	int GetNamesNum();

	void SetBase(uint64 address);
private:
	uint64 baseAddress;
	int count;
};

ref class ObjectsStore
{
public:
	void Init(uint64 address);

	UEClass FindClass(std::string);

	uint64 GetAddress();

	int GetObjectsNum();

	UEObject GetById(int id);

	template<typename T>
	int CountObjects(const std::string& name)
	{
		static std::unordered_map<std::string, int> cache;

		auto it = cache.find(name);
		if (it != std::end(cache))
		{
			return it->second;
		}

		int count = 0;
		for (int i = 0; i < GetObjectsNum(); i++)
		{
			auto obj = GetById(i);
			if (obj.IsValid() && obj.IsA<T>()&& obj.GetName() == name)
			{
				++count;
			}
		}
		cache[name] = count;
		return count;
	}
private:
	uint64 objObjects;
	int objCounts;
};

ref class Global
{
public:
	static LiteSDKGenerator::Main^ MainForm = gcnew LiteSDKGenerator::Main;
	static Memory^ GameMemory = gcnew Memory;
	static NamesStore^ Names = gcnew NamesStore();
	static ObjectsStore^ Objects = gcnew ObjectsStore();
	static SDKGenerator^ Generator = gcnew SDKGenerator();
};
