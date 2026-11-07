#include "../../../../../include/hkArray.h"

// src/havok/common/base/reflection/hkclassmemberaccessor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassmemberaccessor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/Pair.h"

struct FUN_00d87210_class
{
    char* m_p;
    char* __thiscall hkClassMemberAccessor_asPointer(int index);
};

// @fnv 0x00d87210
// src: XBOX_PDB 0x00d87210
char* __thiscall FUN_00d87210_class::hkClassMemberAccessor_asPointer(int index)
{
    return m_p + index * 4;
}

// @fnv 0x00d87220
// src: XBOX_PDB 0x00d87220
char* __fastcall hkClassMemberAccessor_asCstring(char* self, int edx, int index)
{
    return *(char**)self + index * 4;
}

struct FUN_00d87260_cls
{
    char* __thiscall hkClassMemberAccessor_asHalf(int a);
};

// @fnv 0x00d87260
// src: XBOX_PDB 0x00d87260
char* __thiscall FUN_00d87260_cls::hkClassMemberAccessor_asHalf(int a)
{
    return *reinterpret_cast<char**>(this) + a * 2;
}

// @fnv 0x00d87290
// src: GUESS 0x00d87290 (confidence: medium)
const void* __fastcall Hkclassmemberaccessor_GetElementPointer8(const void* pThis, int, int index)
{
    return (const char*)(*(const char**)pThis) + index * 8;
}

struct FUN_00d872a0_t
{
    void* __thiscall ComputeValue_00d872a0(int arg);
};

// @fnv 0x00d872a0
// src: GUESS 0x00d872a0 (confidence: low)
void* __thiscall FUN_00d872a0_t::ComputeValue_00d872a0(int arg)
{
    return (char*)*(void**)this + 8 * arg;
}

// @fnv 0x00d872c0
// src: GUESS 0x00d872c0 (confidence: low)
int __fastcall Object_ComputeValue_00d872c0(int* self, int edx, int offset)
{
    int base = *self;
    return base + offset * 2;
}

struct FUN_00d87300_class
{
    int* GetElementAddress_00d87300(int index);
};

// @fnv 0x00d87300
// src: GUESS 0x00d87300 (confidence: low)
int* FUN_00d87300_class::GetElementAddress_00d87300(int index)
{
    return *(int**)this + index * 4;
}

// @fnv 0x00d87310
// src: GUESS 0x00d87310 (confidence: medium)
void* __fastcall Hkclassmemberaccessor_GetElementPointer48(void* self, int, int index)
{
    return (char*)*(void**)self + index * 3 * 16;
}

// @fnv 0x00d87350
// src: XBOX_PDB 0x00d87350
int __fastcall hkClassMemberAccessor_asHomogeneousArray(int* self, int, int idx)
{
    int base = *self;
    return base + idx * 12;
}

struct IntArrayView
{
    int* data;
    int* GetElementPointer_00d87270(int index);
};
// @fnv 0x00d87270
// src: GUESS 0x00d87270 (confidence: medium)
int* IntArrayView::GetElementPointer_00d87270(int index)
{
    return data + index;
}

struct FUN_00d87280_class
{
    int* m_p;
    int* __thiscall ComputeValue_00d87280(int index);
};

// @fnv 0x00d87280
// src: GUESS 0x00d87280 (confidence: low)
int* __thiscall FUN_00d87280_class::ComputeValue_00d87280(int index)
{
    return m_p + index;
}

struct FUN_00d872b0_class
{
    int* data;
    int* GetElementPointer_00d872b0(int index);
};

// @fnv 0x00d872b0
// src: GUESS 0x00d872b0 (confidence: medium)
int* FUN_00d872b0_class::GetElementPointer_00d872b0(int index)
{
    return &data[index];
}

struct FUN_00d872d0_class
{
    char* m_p;
    char* __thiscall GetElementPointer2(int index);
};

// @fnv 0x00d872d0
// src: GUESS 0x00d872d0 (confidence: medium)
char* __thiscall FUN_00d872d0_class::GetElementPointer2(int index)
{
    return m_p + index * 2;
}

struct CpuObject
{
    int value;
    int ComputeValue_00d872e0(int amount);
};
// @fnv 0x00d872e0
// src: GUESS 0x00d872e0 (confidence: low)
int CpuObject::ComputeValue_00d872e0(int amount)
{
    return value + amount;
}

struct FUN_00d87360_class
{
    char* m_p;
    char* hkClassMemberAccessor_asVariant(int index);
};
// @fnv 0x00d87360
// src: XBOX_PDB 0x00d87360
char* FUN_00d87360_class::hkClassMemberAccessor_asVariant(int index)
{
    return m_p + index * 8;
}

// @fnv 0x00d873d0
// src: GAMEBRYO_LIB 0x00d873d0
Pair& Pair::Imath_Vec2_int_Vec2_int(const Pair& other)
{
    a = other.a;
    b = other.b;
    return *this;
}

struct D871A0Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct D871A0Buffer
{
    void append(const void* data, int size, int flags);
    D871A0Buffer& ProcessAndReturnValue_00d871a0(const D871A0Array& a, int flags);
};

// Appends the array's data buffer with its size and flags to this buffer, then returns this buffer.
// @fnv 0x00d871a0
// src: GUESS 0x00d871a0 (confidence: low)
D871A0Buffer& D871A0Buffer::ProcessAndReturnValue_00d871a0(const D871A0Array& apArray, int flags)
{
    append(apArray.m_data, apArray.m_iElementCount, flags);
    return *this;
}

struct TargetClass
{
    void* ptr;
    bool* __thiscall ComputeValue_00d871e0(bool* out);
};

// @fnv 0x00d871e0
// src: GUESS 0x00d871e0 (confidence: low)
bool* __thiscall TargetClass::ComputeValue_00d871e0(bool* out)
{
    *out = (this->ptr != 0);
    return out;
}

typedef hkArrayBase<char> D87240Array;

// @fnv 0x00d87240
// src: GUESS 0x00d87240 (confidence: low)
template<> char& hkArrayBase<char>::GetIndexedValue_00d87240(int i)
{
    return m_data[i];
}

typedef hkArrayBase<int> D87250Array;

// @fnv 0x00d87250
// src: XBOX_PDB 0x00d87250
template<> int& hkArrayBase<int>::hkClassMemberAccessor_asReal(int i)
{
    return m_data[i];
}

struct FUN_00d872f0_class
{
    int m_uiFilterValue;
    int __thiscall GetFilterValueWithOffset(int offset);
};

// @fnv 0x00d872f0
// src: GUESS 0x00d872f0 (confidence: medium)
int __thiscall FUN_00d872f0_class::GetFilterValueWithOffset(int offset)
{
    return m_uiFilterValue + offset;
}

struct SearchObject
{
    unsigned int field00;
    int ComputeShiftedFieldValue_00d87320(unsigned int arg0);
};
// @fnv 0x00d87320
// src: GUESS 0x00d87320 (confidence: low)
int SearchObject::ComputeShiftedFieldValue_00d87320(unsigned int arg0)
{
    return (int)((arg0 << (6u & 31u)) + field00);
}

struct FUN_00d87330_class
{
    char* m_p;
    char* GetElementPointer48(int index);
};

// @fnv 0x00d87330
// src: GUESS 0x00d87330 (confidence: medium)
char* FUN_00d87330_class::GetElementPointer48(int index)
{
    return m_p + index * 0x30;
}

struct FUN_00d87340_cls
{
    Pair* m_p;

    Pair* hkClassMemberAccessor_asSimpleArray(int index);
};

// @fnv 0x00d87340
// src: XBOX_PDB 0x00d87340
Pair* FUN_00d87340_cls::hkClassMemberAccessor_asSimpleArray(int index)
{
    return m_p + index;
}

struct FnvCpu_FUN_00d871f0_CpuObject
{
    int value;
    int GetValue();
};
// @fnv 0x00d871f0
// src: GUESS 0x00d871f0 (confidence: low)
int FnvCpu_FUN_00d871f0_CpuObject::GetValue()
{
    return value;
}

struct FUN_00d87200_cls
{
    void* m_data;
    void* hkClassMemberAccessor_getAddress();
};

// @fnv 0x00d87200
// src: XBOX_PDB 0x00d87200
void* FUN_00d87200_cls::hkClassMemberAccessor_getAddress()
{
    return m_data;
}

struct D87370Obj
{
    void* unk00;
    int unk04;
    int __thiscall hkClassMemberAccessor_getClassMember();
};

// @fnv 0x00d87370
// src: XBOX_PDB 0x00d87370
int __thiscall D87370Obj::hkClassMemberAccessor_getClassMember()
{
    return unk04;
}

struct StringMemberAccessor
{
    int* values;
    int* hkClassMemberAccessor_asStringPtr(int index);
};

// @fnv 0x00d87230
// src: XBOX_PDB 0x00d87230
int* StringMemberAccessor::hkClassMemberAccessor_asStringPtr(int index)
{
    return values + index;
}
