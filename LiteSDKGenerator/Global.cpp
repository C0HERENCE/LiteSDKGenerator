#include "Global.h"
#include "SDKTypes.h"

using namespace Updates;

void ObjectsStore::Init(uint64 address)
{
	objObjects = Dec::objobjects(Global::GameMemory->Read64(address));
	objCounts = Global::GameMemory->Read32(address + 0x10);
}

int ObjectsStore::GetObjectsNum()
{
	return objCounts;
}

UEObject ObjectsStore::GetById(int id)
{
	return UEObject(Global::GameMemory->Read64(objObjects + 0x18 * id));
}

UEClass ObjectsStore::FindClass(std::string className)
{
	for (int i = 0; i < GetObjectsNum(); i++)
	{
		UEObject obj = UEObject(GetById(i));
		if (obj.GetFullName() == className)
		{
			return obj.Cast<UEClass>();
		}
	}
	return UEClass(0);
}

uint64 ObjectsStore::GetAddress()
{
	return objObjects;
}

void NamesStore::Init(uint64 address)
{
	baseAddress = Global::GameMemory->Read64(address + Off::static_gnames);
	count = 100;
}

std::string NamesStore::GetById(int Index)
{
	int32_t ChunkIndex = Index / Off::chunksize;
	int32_t WithinChunkIndex = Index % Off::chunksize;
	uint64 Chunk = baseAddress + ChunkIndex * 0x8;
	uint64 Name = Global::GameMemory->Read64(Global::GameMemory->Read64(Chunk) + WithinChunkIndex*0x8);
	char name[100] = { NULL };
	if (Global::GameMemory->ReadString(Name + 0x10, name, 100) != 0)
	{
		std::string string = std::string(name);
		return string;
	}
	return std::string("NULL");
}

uint64 NamesStore::GetAddress()
{
	return baseAddress;
}

int NamesStore::GetNamesNum()
{
	return count;
}

void NamesStore::SetBase(uint64 address)
{
	baseAddress = address;
	count = 100;
}