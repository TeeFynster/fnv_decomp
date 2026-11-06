#include "../../../../../include/hkArray.h"

// src/havok/common/base/reflection/hkclassmemberaccessor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassmemberaccessor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/Pair.h"

struct FUN_00d87210_class
{
    char* m_p;
    char* __thiscall FUN_00d87210(int index);
};

// @fnv 0x00d87210
char* __thiscall FUN_00d87210_class::FUN_00d87210(int index)
{
    return m_p + index * 4;
}

// @fnv 0x00d87220
char* __fastcall FUN_00d87220(char* self, int edx, int index)
{
    return *(char**)self + index * 4;
}

struct FUN_00d87260_cls
{
    char* __thiscall FUN_00d87260(int a);
};

// @fnv 0x00d87260
char* __thiscall FUN_00d87260_cls::FUN_00d87260(int a)
{
    return *reinterpret_cast<char**>(this) + a * 2;
}

// @fnv 0x00d87290
const void* __fastcall FUN_00d87290(const void* pThis, int, int index)
{
    return (const char*)(*(const char**)pThis) + index * 8;
}

struct FUN_00d872a0_t
{
    void* __thiscall FUN_00d872a0(int arg);
};

// @fnv 0x00d872a0
void* __thiscall FUN_00d872a0_t::FUN_00d872a0(int arg)
{
    return (char*)*(void**)this + 8 * arg;
}

// @fnv 0x00d872c0
int __fastcall FUN_00d872c0(int* self, int edx, int offset)
{
    int base = *self;
    return base + offset * 2;
}

struct FUN_00d87300_class
{
    int* FUN_00d87300(int index);
};

// @fnv 0x00d87300
int* FUN_00d87300_class::FUN_00d87300(int index)
{
    return *(int**)this + index * 4;
}

// @fnv 0x00d87310
void* __fastcall FUN_00d87310(void* self, int, int index)
{
    return (char*)*(void**)self + index * 3 * 16;
}

// @fnv 0x00d87350
int __fastcall FUN_00d87350(int* self, int, int idx)
{
    int base = *self;
    return base + idx * 12;
}

struct IntArrayView
{
    int* data;
    int* FUN_00d87270(int index);
};
// @fnv 0x00d87270
int* IntArrayView::FUN_00d87270(int index)
{
    return data + index;
}

struct FUN_00d87280_class
{
    int* m_p;
    int* __thiscall FUN_00d87280(int index);
};

// @fnv 0x00d87280
int* __thiscall FUN_00d87280_class::FUN_00d87280(int index)
{
    return m_p + index;
}

struct FUN_00d872b0_class
{
    int* data;
    int* FUN_00d872b0(int index);
};

// @fnv 0x00d872b0
int* FUN_00d872b0_class::FUN_00d872b0(int index)
{
    return &data[index];
}

struct FUN_00d872d0_class
{
    char* m_p;
    char* __thiscall FUN_00d872d0(int index);
};

// @fnv 0x00d872d0
char* __thiscall FUN_00d872d0_class::FUN_00d872d0(int index)
{
    return m_p + index * 2;
}

struct CpuObject
{
    int value;
    int FUN_00d872e0(int amount);
};
// @fnv 0x00d872e0
int CpuObject::FUN_00d872e0(int amount)
{
    return value + amount;
}

struct FUN_00d87360_class
{
    char* m_p;
    char* FUN_00d87360(int index);
};
// @fnv 0x00d87360
char* FUN_00d87360_class::FUN_00d87360(int index)
{
    return m_p + index * 8;
}

// @fnv 0x00d873d0
Pair& Pair::FUN_00d873d0(const Pair& other)
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
    D871A0Buffer& FUN_00d871a0(const D871A0Array& a, int flags);
};

// Appends the array's data buffer with its size and flags to this buffer, then returns this buffer.
// @fnv 0x00d871a0
D871A0Buffer& D871A0Buffer::FUN_00d871a0(const D871A0Array& apArray, int flags)
{
    append(apArray.m_data, apArray.m_iElementCount, flags);
    return *this;
}

struct TargetClass
{
    void* ptr;
    bool* __thiscall FUN_00d871e0(bool* out);
};

// @fnv 0x00d871e0
bool* __thiscall TargetClass::FUN_00d871e0(bool* out)
{
    *out = (this->ptr != 0);
    return out;
}

typedef hkArrayBase<char> D87240Array;

// @fnv 0x00d87240
template<> char& hkArrayBase<char>::FUN_00d87240(int i)
{
    return m_data[i];
}

typedef hkArrayBase<int> D87250Array;

// @fnv 0x00d87250
template<> int& hkArrayBase<int>::FUN_00d87250(int i)
{
    return m_data[i];
}

struct FUN_00d872f0_class
{
    int m_uiFilterValue;
    int __thiscall FUN_00d872f0(int offset);
};

// @fnv 0x00d872f0
int __thiscall FUN_00d872f0_class::FUN_00d872f0(int offset)
{
    return m_uiFilterValue + offset;
}

struct SearchObject
{
    unsigned int field00;
    int FUN_00d87320(unsigned int arg0);
};
// @fnv 0x00d87320
int SearchObject::FUN_00d87320(unsigned int arg0)
{
    return (int)((arg0 << (6u & 31u)) + field00);
}

struct FUN_00d87330_class
{
    char* m_p;
    char* FUN_00d87330(int index);
};

// @fnv 0x00d87330
char* FUN_00d87330_class::FUN_00d87330(int index)
{
    return m_p + index * 0x30;
}

struct FUN_00d87340_cls
{
    Pair* m_p;

    Pair* FUN_00d87340(int index);
};

// @fnv 0x00d87340
Pair* FUN_00d87340_cls::FUN_00d87340(int index)
{
    return m_p + index;
}

struct FnvCpu_FUN_00d871f0_CpuObject
{
    int value;
    int FUN_00d871f0();
};
// @fnv 0x00d871f0
int FnvCpu_FUN_00d871f0_CpuObject::FUN_00d871f0()
{
    return value;
}

struct FUN_00d87200_cls
{
    void* m_data;
    void* FUN_00d87200();
};

// @fnv 0x00d87200
void* FUN_00d87200_cls::FUN_00d87200()
{
    return m_data;
}

struct D87370Obj
{
    void* unk00;
    int unk04;
    int __thiscall FUN_00d87370();
};

// @fnv 0x00d87370
int __thiscall D87370Obj::FUN_00d87370()
{
    return unk04;
}

struct StringMemberAccessor
{
    int* values;
    int* FUN_00d87230(int index);
};

// @fnv 0x00d87230
int* StringMemberAccessor::FUN_00d87230(int index)
{
    return values + index;
}
