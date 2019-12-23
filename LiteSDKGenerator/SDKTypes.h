#pragma once
#include "Global.h"
#include <vector>
#include <array>

#pragma region EngineFlags
enum class UEPropertyFlags : uint64_t
{
	Edit = 0x0000000000000001,
	ConstParm = 0x0000000000000002,
	BlueprintVisible = 0x0000000000000004,
	ExportObject = 0x0000000000000008,
	BlueprintReadOnly = 0x0000000000000010,
	Net = 0x0000000000000020,
	EditFixedSize = 0x0000000000000040,
	Parm = 0x0000000000000080,
	OutParm = 0x0000000000000100,
	ZeroConstructor = 0x0000000000000200,
	ReturnParm = 0x0000000000000400,
	DisableEditOnTemplate = 0x0000000000000800,
	Transient = 0x0000000000002000,
	Config = 0x0000000000004000,
	DisableEditOnInstance = 0x0000000000010000,
	EditConst = 0x0000000000020000,
	GlobalConfig = 0x0000000000040000,
	InstancedReference = 0x0000000000080000,
	DuplicateTransient = 0x0000000000200000,
	SubobjectReference = 0x0000000000400000,
	SaveGame = 0x0000000001000000,
	NoClear = 0x0000000002000000,
	ReferenceParm = 0x0000000008000000,
	BlueprintAssignable = 0x0000000010000000,
	Deprecated = 0x0000000020000000,
	IsPlainOldData = 0x0000000040000000,
	RepSkip = 0x0000000080000000,
	RepNotify = 0x0000000100000000,
	Interp = 0x0000000200000000,
	NonTransactional = 0x0000000400000000,
	EditorOnly = 0x0000000800000000,
	NoDestructor = 0x0000001000000000,
	AutoWeak = 0x0000004000000000,
	ContainsInstancedReference = 0x0000008000000000,
	AssetRegistrySearchable = 0x0000010000000000,
	SimpleDisplay = 0x0000020000000000,
	AdvancedDisplay = 0x0000040000000000,
	Protected = 0x0000080000000000,
	BlueprintCallable = 0x0000100000000000,
	BlueprintAuthorityOnly = 0x0000200000000000,
	TextExportTransient = 0x0000400000000000,
	NonPIEDuplicateTransient = 0x0000800000000000,
	ExposeOnSpawn = 0x0001000000000000,
	PersistentInstance = 0x0002000000000000,
	UObjectWrapper = 0x0004000000000000,
	HasGetValueTypeHash = 0x0008000000000000,
	NativeAccessSpecifierPublic = 0x0010000000000000,
	NativeAccessSpecifierProtected = 0x0020000000000000,
	NativeAccessSpecifierPrivate = 0x0040000000000000
};

bool operator&(UEPropertyFlags lhs, UEPropertyFlags rhs);

std::string StringifyFlags(const UEPropertyFlags flags);

enum class UEFunctionFlags : uint32_t
{
	Final = 0x00000001,
	RequiredAPI = 0x00000002,
	BlueprintAuthorityOnly = 0x00000004,
	BlueprintCosmetic = 0x00000008,
	Net = 0x00000040,
	NetReliable = 0x00000080,
	NetRequest = 0x00000100,
	Exec = 0x00000200,
	Native = 0x00000400,
	Event = 0x00000800,
	NetResponse = 0x00001000,
	Static = 0x00002000,
	NetMulticast = 0x00004000,
	MulticastDelegate = 0x00010000,
	Public = 0x00020000,
	Private = 0x00040000,
	Protected = 0x00080000,
	Delegate = 0x00100000,
	NetServer = 0x00200000,
	HasOutParms = 0x00400000,
	HasDefaults = 0x00800000,
	NetClient = 0x01000000,
	DLLImport = 0x02000000,
	BlueprintCallable = 0x04000000,
	BlueprintEvent = 0x08000000,
	BlueprintPure = 0x10000000,
	Const = 0x40000000,
	NetValidate = 0x80000000
};

bool operator&(UEFunctionFlags lhs, UEFunctionFlags rhs);

std::string StringifyFlags(const UEFunctionFlags flags);

#pragma endregion

#pragma region EngineTypes
class FName
{
public:
	FName();

	FName(uint64 _base);

	int GetComparisonIndex() const;

	int GetNumber() const;

private:
	uint64 base;
};

template<class T>
class TArray
{
	friend struct FString;

public:
	int Length() const
	{
		return m_nCount;
	}

	bool IsValid() const
	{
		if (m_nCount > m_nMax)
			return false;
		if (!m_Data)
			return false;
		return true;
	}

	uint64 GetAddress() const
	{
		return m_Data;
	}

	T operator[](size_t i)
	{
		return Global::GameMemory->Read<T>(m_Data + i * sizeof(T));
	};

	const T operator[](size_t i) const
	{
		return Global::GameMemory->Read<T>(m_Data + i * sizeof(T));
	};

	T GetById(int i)
	{
		return T(Global::GameMemory->Read64(m_Data + i * 8));
	}

protected:
	uint64 m_Data;
	uint32 m_nCount;
	uint32 m_nMax;
};

struct FPointer
{
	uintptr_t Dummy;
};

struct FQWord
{
	int A;
	int B;
};

template<typename KeyType, typename ValueType>
class TPair
{
public:
	KeyType   Key;
	ValueType Value;
};

struct FString : public TArray<wchar_t>
{
	std::string ToString() const;
};

struct FText
{
	char UnknownData[0x18];
};

class FScriptInterface
{
private:
	uint64* ObjectPointer;
	void* InterfacePointer;

public:
	uint64* GetObject() const
	{
		return ObjectPointer;
	}

	uint64*& GetObjectRef()
	{
		return ObjectPointer;
	}

	void* GetInterface() const
	{
		return ObjectPointer != nullptr ? InterfacePointer : nullptr;
	}
};

struct FWeakObjectPtr
{
	int32_t ObjectIndex;
	int32_t ObjectSerialNumber;
};

struct FStringAssetReference
{
	FString AssetLongPathname;
};

template<typename TObjectID>
class TPersistentObjectPtr
{
public:
	FWeakObjectPtr WeakPtr;
	int32_t TagAtLastTest;
	TObjectID ObjectID;
};

class FAssetPtr : public TPersistentObjectPtr<FStringAssetReference>
{

};

struct FGuid
{
	uint32_t A;
	uint32_t B;
	uint32_t C;
	uint32_t D;
};

struct FUniqueObjectGuid
{
	FGuid Guid;
};

class FLazyObjectPtr : public TPersistentObjectPtr<FUniqueObjectGuid>
{

};

struct FScriptDelegate
{
	unsigned char UnknownData[20];
};

struct FScriptMulticastDelegate
{
	unsigned char UnknownData[16];
};
#pragma endregion

#pragma region EngineClasses

class UObject
{
protected:
	uint64 base;
public:
	UObject(uint64 _base)
	{
		base = _base;
	}
	UObject()
	{

	}
	int32 GetInternalIndex() const
	{
		return Updates::Dec::internal_id(Global::GameMemory->Read32(base + Updates::Off::internal_id));
	}

	uint64 GetClass() const
	{
		return Updates::Dec::uclass(Global::GameMemory->Read64(base + Updates::Off::ulcass));
	}

	uint64 GetOuter() const
	{
		return Updates::Dec::outer(Global::GameMemory->Read64(base + Updates::Off::outer));
	}

	FName GetFName() const
	{
		return FName(base + Updates::Off::name);
	}
};

class UField : public UObject
{
	using UObject::UObject;
public:
	uint64 Next() const
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::next);//Vector
	}
};

class UEnum : public UField
{
	using UField::UField;
public:
	TArray<TPair<FName, uint64_t>> Names()
	{
		return Global::GameMemory->Read<TArray<TPair<FName, uint64_t>>>(UObject::base + Updates::Off::enumNames);
	}
};

class UStruct : public UField
{
	using UField::UField;
public:
	uint64_t SuperField()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::superfield);  //Engine.Pawn Engine.Actor
	}
	uint32_t PropertySize()
	{
		return Global::GameMemory->Read32(UObject::base + Updates::Off::property_size); // Vector
	}
	uint64_t Children()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::children); // Vector
	}
};

class UScriptStruct : public UStruct
{
public:
};

class UFunction : public UStruct
{
	using UStruct::UStruct;
public:
	uint64_t Func()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::func);
	}
	uint32_t FunctionFlags()
	{
		return Global::GameMemory->Read32(UObject::base + Updates::Off::function_flags);
	}
};

class UClass : public UStruct
{
public:
};

class UProperty : public UField
{
	using UField::UField;
public:
	uint32_t ArrayDim()
	{
		return Global::GameMemory->Read32(UObject::base + Updates::Off::array_dim); // Vector.X=1
	}
	uint32_t ElementSize()
	{
		return Global::GameMemory->Read32(UObject::base + Updates::Off::element_size); // Vector.X = 4
	}
	uint32_t Offset()
	{
		return Global::GameMemory->Read32(UObject::base + Updates::Off::offset); // Vector.Z = 8
	}
	FQWord PropertyFlags()
	{
		return Global::GameMemory->Read<FQWord>(UObject::base + Updates::Off::property_flag);
	}
};


class UNumericProperty : public UProperty
{
	using UProperty::UProperty;
public:

};

class UByteProperty : public UNumericProperty
{
	using UNumericProperty::UNumericProperty;
public:
	uint64 Enum()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UUInt16Property : public UNumericProperty
{
public:

};

class UUInt32Property : public UNumericProperty
{
public:

};

class UUInt64Property : public UNumericProperty
{
public:

};

class UInt8Property : public UNumericProperty
{
public:

};

class UInt16Property : public UNumericProperty
{
public:

};

class UIntProperty : public UNumericProperty
{
public:

};

class UInt64Property : public UNumericProperty
{
public:

};

class UFloatProperty : public UNumericProperty
{
public:

};

class UDoubleProperty : public UNumericProperty
{
public:

};

class UBoolProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint8_t FieldSize()
	{
		return Global::GameMemory->Read<uint8_t>(UObject::base + Updates::Off::uproperty_size);
	}
	uint8_t ByteOffset()
	{
		return Global::GameMemory->Read<uint8_t>(UObject::base + Updates::Off::uproperty_size + 0x2);
	}
	uint8_t ByteMask()
	{
		return Global::GameMemory->Read<uint8_t>(UObject::base + Updates::Off::uproperty_size + 0x4);
	}
	uint8_t FieldMask()
	{
		return Global::GameMemory->Read<uint8_t>(UObject::base + Updates::Off::uproperty_size + 0x6);
	}
};

class UObjectPropertyBase : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 PropertyClass()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UObjectProperty : public UObjectPropertyBase
{
	using UObjectPropertyBase::UObjectPropertyBase;
public:

};

class UClassProperty : public UObjectProperty
{
	using UObjectProperty::UObjectProperty;
public:
	uint64 MetaClass()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size + 0x8);
	}
};

class UInterfaceProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 InterfaceClass()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UWeakObjectProperty : public UObjectPropertyBase
{
public:

};

class ULazyObjectProperty : public UObjectPropertyBase
{
public:

};

class UAssetObjectProperty : public UObjectPropertyBase
{
	using UObjectPropertyBase::UObjectPropertyBase;
public:

};

class UAssetClassProperty : public UAssetObjectProperty
{
	using UAssetObjectProperty::UAssetObjectProperty;
public:
	uint64 MetaClass()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size + 0x8);
	}
};

class UNameProperty : public UProperty
{
public:

};

class UStructProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 Struct()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UStrProperty : public UProperty
{
public:

};

class UTextProperty : public UProperty
{
public:

};

class UArrayProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 Inner()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UMapProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 KeyProp()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
	uint64 ValueProp()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size + 0x8);
	}
};

class UDelegateProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 SignatureFunction()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UMulticastDelegateProperty : public UProperty
{
public:
	uint64 SignatureFunction()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
};

class UEnumProperty : public UProperty
{
	using UProperty::UProperty;
public:
	uint64 UnderlyingProp()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size);
	}
	uint64 Enum()
	{
		return Global::GameMemory->Read64(UObject::base + Updates::Off::uproperty_size + 0x8);
	}
};
#pragma endregion

#pragma region GenericTypes
class UEClass;

class UEObject
{
public:
	UEObject()
	{
		object = 0;
	}
	UEObject(uint64 _object)
	{
		object = _object;
		uobject = UObject(_object);
	}

	bool IsValid() const
	{
		return object != 0;
	}

	int GetIndex() const;

	UEClass GetClass() const;

	UEObject GetOuter() const;

	std::string GetName() const;

	std::string GetFullName() const;

	std::string GetFullPath() const;

	std::string GetNameCPP() const;

	UEObject GetPackageObject() const;

	int GetComparisonIndex() const;

	uint64 GetAddress() const;

	bool operator!=(UEObject b)
	{
		return object != b.object;
	}

	template<typename Type>
	Type Cast() const
	{
		return Type(object);
	}

	template<typename T> bool IsA() const
	{
		auto cmp = T::StaticClass();
		if (!cmp.IsValid())
		{
			return false;
		}
		for (auto super = GetClass(); super.IsValid(); super = super.GetSuper().Cast<UEClass>())
		{
			if (super.object == cmp.object)
			{
				return true;
			}
		}

		return false;
	}

	static UEClass StaticClass();

protected:
	uint64 object;
	UObject uobject;
};

class UEField : public UEObject
{
public:
	using UEObject::UEObject;

	UEField GetNext() const;

	static UEClass StaticClass();
};
class UEEnum : public UEField
{
public:
	using UEField::UEField;

	std::vector<std::string> GetNames() const;
	static UEClass StaticClass();
};

class UEConst : public UEField
{
public:
	using UEField::UEField;

	std::string GetValue() const;

	static UEClass StaticClass();
};

class UEStruct : public UEField
{
public:
	using UEField::UEField;

	UEStruct GetSuper() const;

	UEField GetChildren() const;

	size_t GetPropertySize() const;

	static UEClass StaticClass();
};

class UEProperty : public UEField
{
public:
	using UEField::UEField;

	size_t GetArrayDim() const;

	size_t GetElementSize() const;

	UEPropertyFlags GetPropertyFlags() const;

	size_t GetOffset() const;

	enum class PropertyType
	{
		Unknown,
		Primitive,
		PredefinedStruct,
		CustomStruct,
		Container
	};

	struct Info
	{
		PropertyType Type;
		size_t Size;
		bool CanBeReference;
		std::string CppType;
		static Info Create(PropertyType type, size_t size, bool reference, std::string&& cppType)
		{
			return { type, size, reference, cppType };
		}
	};


	Info GetInfo() const;

	static UEClass StaticClass();
};

/*
UEStruct:
		UEScriptStruct
		UEClass
*/

class UEFunction : public UEStruct
{
public:
	using UEStruct::UEStruct;

	UEFunctionFlags GetFunctionFlags() const;

	uint64 GetFunc() const;

	static UEClass StaticClass();
};

class UEScriptStruct : public UEStruct
{
public:
	using UEStruct::UEStruct;

	static UEClass StaticClass();
};

class UEClass : public UEStruct
{
public:
	using UEStruct::UEStruct;

	static UEClass StaticClass();
};

class UENumericProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	static UEClass StaticClass();
};

class UEByteProperty : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	bool IsEnum() const;

	UEEnum GetEnum() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEUInt16Property : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEUInt32Property : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEUInt64Property : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEInt8Property : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEInt16Property : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEIntProperty : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEInt64Property : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEFloatProperty : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEDoubleProperty : public UENumericProperty
{
public:
	using UENumericProperty::UENumericProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEBoolProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	bool IsNativeBool() const { return GetFieldMask() == 0xFF; }

	bool IsBitfield() const { return !IsNativeBool(); }

	uint8_t GetFieldSize() const;

	uint8_t GetByteOffset() const;

	uint8_t GetByteMask() const;

	uint8_t GetFieldMask() const;

	std::array<int, 2> GetMissingBitsCount(const UEBoolProperty& other) const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

inline bool operator<(const UEBoolProperty& lhs, const UEBoolProperty& rhs)
{
	if (lhs.GetByteOffset() == rhs.GetByteOffset())
	{
		return lhs.GetByteMask() < rhs.GetByteMask();
	}
	return lhs.GetByteOffset() < rhs.GetByteOffset();
}

class UEObjectPropertyBase : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEClass GetPropertyClass() const;

	static UEClass StaticClass();
};

class UEObjectProperty : public UEObjectPropertyBase
{
public:
	using UEObjectPropertyBase::UEObjectPropertyBase;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEEncryptedObjectProperty : public UEObjectPropertyBase
{
public:
	using UEObjectPropertyBase::UEObjectPropertyBase;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEClassProperty : public UEObjectProperty
{
public:
	using UEObjectProperty::UEObjectProperty;

	UEClass GetMetaClass() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEInterfaceProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEClass GetInterfaceClass() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEWeakObjectProperty : public UEObjectPropertyBase
{
public:
	using UEObjectPropertyBase::UEObjectPropertyBase;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UELazyObjectProperty : public UEObjectPropertyBase
{
public:
	using UEObjectPropertyBase::UEObjectPropertyBase;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEAssetObjectProperty : public UEObjectPropertyBase
{
public:
	using UEObjectPropertyBase::UEObjectPropertyBase;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEAssetClassProperty : public UEAssetObjectProperty
{
public:
	using UEAssetObjectProperty::UEAssetObjectProperty;

	UEClass GetMetaClass() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UENameProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEStructProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEScriptStruct GetStruct() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEStrProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UETextProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEArrayProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEProperty GetInner() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEMapProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEProperty GetKeyProperty() const;
	UEProperty GetValueProperty() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEDelegateProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEFunction GetSignatureFunction() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEMulticastDelegateProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UEFunction GetSignatureFunction() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

class UEEnumProperty : public UEProperty
{
public:
	using UEProperty::UEProperty;

	UENumericProperty GetUnderlyingProperty() const;
	UEEnum GetEnum() const;

	UEProperty::Info GetInfo() const;

	static UEClass StaticClass();
};

#pragma endregion

#pragma region NameValidator
std::string MakeValidName(std::string&& name);

template<typename T>
std::string MakeUniqueCppNameImpl(const T& t);

std::string MakeUniqueCppName(const UEEnum& e);

std::string MakeUniqueCppName(const UEStruct& ss);

#pragma endregion