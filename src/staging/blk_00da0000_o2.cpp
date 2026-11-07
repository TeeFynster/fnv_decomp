#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../include/hkArray.h"
// staging/blk_00da0000_o2.cpp: Holder, MapHolder, SpawnedOuter, SearchObject and more (113 functions)

#include <windows.h>
#include "../../include/hkResult.h"
// src/staging/blk_00da0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/BSAudio.h"
#include "../../include/hkVector4.h"
#include "../../include/hkBool.h"
#include "../../include/hkMemoryAllocator.h"

extern "C" void __cdecl ReturnSelf(void*);
extern int DAT_010d461c;

struct FUN_00da07b0_class
{
    void __thiscall ReturnSelf(void*);
};

// @fnv 0x00da07b0
// src: HAVOK_LIB 0x00da07b0
void __cdecl finishLoadedObjecthkSimpleLocalFrame(void* apObject, void* b)
{
    if (apObject)
    {
        *(int*)apObject = (int)&DAT_010d461c;
        ((FUN_00da07b0_class*)((char*)apObject + 0x64))->ReturnSelf(b);
    }
}

void __cdecl InitBlockPool(void*);

// @fnv 0x00da6fa0
void* __cdecl InitAndReturnTail(void* apUnused1, void* apUnused2, void* apStruct)
{
    if (apStruct)
    {
        *(int*)apStruct = 0;
        *(int*)((char*)apStruct + 4) = 0;
        *(int*)((char*)apStruct + 8) = 0x80000000;
    }
    InitBlockPool(apStruct);
    return (char*)apStruct + 16;
}

// @fnv 0x00da08c0
// src: GUESS 0x00da08c0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00da08c0(void** a)
{
    (**(void(__thiscall**)(void*, int))(*a))(a, 0);
}

extern int DAT_010c59f4;
extern int DAT_010c6bec;

// If a is non-null, sets its vtable pointer to DAT_010c59f4, optionally writes a 16-bit value at offset 0x11e, then sets the vtable to DAT_010c6bec.
// @fnv 0x00da08e0
// src: GUESS 0x00da08e0 (confidence: low)
void __cdecl Object_UpdateFields_00da08e0(void* pObject, int bSetField)
{
    if (pObject)
    {
        *(void**)pObject = &DAT_010c59f4;
        if (bSetField)
        {
            float f = 1.0f;
            *(float*)&f = f;
            *(unsigned short*)((char*)pObject + 0x11e) = (unsigned short)(*(int*)&f >> 0x10);
        }
        *(void**)pObject = &DAT_010c6bec;
    }
}

extern int DAT_010c6fd0;
// @fnv 0x00da0b10
// src: GUESS 0x00da0b10 (confidence: low)
void __cdecl Runtime_UpdateState_00da0b10(int* p)
{
    if (p)
        *p = (int)&DAT_010c6fd0;
}

extern int DAT_010d6014;

struct FUN_00db7ab0_class
{
    void* __thiscall SetVtableAndProcessState_00db7ab0(void* a, void* b, void* c);
};

// @fnv 0x00db7ab0
// src: GUESS 0x00db7ab0 (confidence: low)
void* __thiscall FUN_00db7ab0_class::SetVtableAndProcessState_00db7ab0(void* a, void* b, void* c)
{
    *(short*)((char*)this + 6) = 1;
    *(int*)((char*)this + 12) = (int)a;
    *(int*)this = (int)&DAT_010d6014;
    *(int*)((char*)this + 16) = (int)b;
    *(int*)((char*)this + 20) = 1;
    *(int*)((char*)this + 8) = (int)c;
    return this;
}

// @fnv 0x00db7790
int __cdecl Crc32ShiftRight8(unsigned int uiValue)
{
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    if (uiValue & 1)
        uiValue = (uiValue >> 1) ^ 0xedb88320;
    else
        uiValue >>= 1;
    return uiValue;
}

void __cdecl Object_HkAgent1nMachine_Destroy_Thunk(void*);
void __cdecl hkListAgent3_ProcessAndReturnValue_00da6de0(void*);
void __cdecl Hkplistagent3_HkAgent1nMachine_WarpTime_Thunk(void*);
void __cdecl Object_UpdateFields_00da6e60(void*);
void __cdecl BuildEventIndex(void);
void* __cdecl InitAndReturnTail(void* a, void* b, void* c);
void* __cdecl Runtime_ForwardCall_00da6e10(void* a, void* b, void* c);

// Fills the object at p with function pointers at fixed offsets, zeroes several pointer slots and sets the byte at offset 0x30 to 1.
// @fnv 0x00da6fd0
// src: GUESS 0x00da6fd0 (confidence: medium)
void __cdecl Object_InitializeDispatchFunctionTable(void* apObject)
{
    char* b = (char*)apObject;
    *(void**)(b + 0) = &InitAndReturnTail;
    *(void**)(b + 0x2c) = &BuildEventIndex;
    *(void**)(b + 0x28) = 0;
    *(void**)(b + 0x8) = 0;
    *(void**)(b + 0xc) = 0;
    *(void**)(b + 0x10) = 0;
    *(void**)(b + 0x14) = 0;
    *(void**)(b + 0x18) = &Object_UpdateFields_00da6e60;
    *(void**)(b + 0x1c) = &hkListAgent3_ProcessAndReturnValue_00da6de0;
    *(void**)(b + 0x20) = &Runtime_ForwardCall_00da6e10;
    *(void**)(b + 0x24) = &Hkplistagent3_HkAgent1nMachine_WarpTime_Thunk;
    *(void**)(b + 0x4) = &Object_HkAgent1nMachine_Destroy_Thunk;
    *(unsigned char*)(b + 0x30) = 1;
}

// @fnv 0x00da0680
// src: HAVOK_LIB 0x00da0680
void __cdecl finishLoadedObjecthkpLinkedCollidable(char* pObject, int bReset)
{
    if (pObject != 0)
    {
        if (bReset != 0)
        {
            *(short*)(pObject + 0x40) = 0;
            *(short*)(pObject + 0x42) = 0;
            char* ecx = pObject + 0x14;
            *(int*)(pObject + 0x44) = 0;
            *(int*)(pObject + 0x48) = 0;
            *(int*)(pObject + 0x20) = 1;
            *(int*)(pObject + 0x30) = 0;
            *(char*)(ecx + 5) = (char)((char)(unsigned char)(unsigned int)pObject - (char)(unsigned int)ecx);
        }
        *(int*)(pObject + 0x50) = 0;
        *(int*)(pObject + 0x54) = 0;
        *(int*)(pObject + 0x58) = (int)0x80000000;
    }
}

struct FUN_00da0740_vt
{
    virtual void v0(int);
};
// @fnv 0x00da0740
// src: GUESS 0x00da0740 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00da0740(FUN_00da0740_vt* p)
{
    p->v0(0);
}

struct FUN_00cb0a70_class
{
    void __thiscall ReturnSelf(int);
};
// @fnv 0x00da0760
// src: GUESS 0x00da0760 (confidence: low)
void __cdecl Object_UpdateFields_00da0760(void* pObject, void* b)
{
    if (pObject)
    {
        *(void**)((char*)pObject + 0) = (void*)0x010d460c;
        ((FUN_00cb0a70_class*)((char*)pObject + 8))->ReturnSelf((int)b);
    }
}

struct FUN_00db7cf0_class
{
    int __thiscall hkVersionPatchManager_UidFromClassVersion_getName(int a, int b);
};
// @fnv 0x00db7cf0
// src: HAVOK_LIB 0x00db7cf0
int __thiscall FUN_00db7cf0_class::hkVersionPatchManager_UidFromClassVersion_getName(int a, int b)
{
    return ((int*)(*(int**)(this + 0x10)))[a];
}

extern int g_unk0126958c;

// @fnv 0x00da0610
// src: GUESS 0x00da0610 (confidence: low)
void* __cdecl Runtime_GetUnk0126958cAddress()
{
    return &g_unk0126958c;
}

extern char DAT_012695bc;

// @fnv 0x00da0630
// src: GUESS 0x00da0630 (confidence: low)
char* __cdecl Runtime_GetDAT012695bcAddress(void)
{
    return &DAT_012695bc;
}

extern int DAT_012695ec;

// @fnv 0x00da0660
// src: GUESS 0x00da0660 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00da0660(void)
{
    return &DAT_012695ec;
}

extern int g_unk0126961c;

// @fnv 0x00da0670
// src: GUESS 0x00da0670 (confidence: low)
int* __cdecl Runtime_GetUnk0126961cAddress()
{
    return &g_unk0126961c;
}

struct FUN_00da0720_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00da0720
// src: GUESS 0x00da0720 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00da0720(FUN_00da0720_Class* param_1)
{
    param_1->vf00(0);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126967c;
// @fnv 0x00da0730
// src: GUESS 0x00da0730 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126967cAddress()
{
    return &DAT_0126967c;
}

extern int DAT_012696c4;

// @fnv 0x00da0750
// src: GUESS 0x00da0750 (confidence: low)
int* __cdecl Runtime_GetDAT012696c4Address()
{
    return &DAT_012696c4;
}

// FUN_00da08a0 : cdecl, 13 bytes
//   mov ecx, [esp+4]
//   mov eax, [ecx]
//   mov edx, [eax]
//   push 0
//   call edx
//   ret
// Calls slot 0 of the object's vtable with the argument 0.

struct FUN_00da08a0_cls
{
    virtual int v00(int a);
};

// @fnv 0x00da08a0
// src: GUESS 0x00da08a0 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00da08a0(FUN_00da08a0_cls* pObj)
{
    return pObj->v00(0);
}

extern int DAT_0126970c;

// @fnv 0x00da08b0
// src: GUESS 0x00da08b0 (confidence: low)
int* __cdecl Runtime_GetDAT0126970cAddress()
{
    return &DAT_0126970c;
}

extern int DAT_01269754;

// @fnv 0x00da08d0
// src: GUESS 0x00da08d0 (confidence: low)
void* __cdecl Runtime_GetDAT01269754Address(void)
{
    return &DAT_01269754;
}

extern int DAT_010c6bec;

// @fnv 0x00da0910
// src: GUESS 0x00da0910 (confidence: low)
void* __cdecl Runtime_GetDAT010c6becAddress(void)
{
    return &DAT_010c6bec;
}

struct DA0920FinishFlag
{
    int m_bFinishing;
};

class DA0920Half
{
  public:
    short m_uiFilterValue;

    void operator=(float f)
    {
        int t = *reinterpret_cast<int*>(&f);
        m_uiFilterValue = static_cast<short>(t >> 16);
    }
};

class DA0920Base
{
  public:
    short unk004;
    short unk006;
    short unk008;
    short unk00A;
    short unk00C;
    short unk00E;
    short unk010;
    short unk012;
    short unk014;
    short unk016;
    short unk018;
    short unk01A;
    short unk01C;
    short unk01E;
    short unk020;
    short unk022;
    short unk024;
    short unk026;
    short unk028;
    short unk02A;
    short unk02C;
    short unk02E;
    short unk030;
    short unk032;
    short unk034;
    short unk036;
    short unk038;
    short unk03A;
    short unk03C;
    short unk03E;
    short unk040;
    short unk042;
    short unk044;
    short unk046;
    short unk048;
    short unk04A;
    short unk04C;
    short unk04E;
    short unk050;
    short unk052;
    short unk054;
    short unk056;
    short unk058;
    short unk05A;
    short unk05C;
    short unk05E;
    short unk060;
    short unk062;
    short unk064;
    short unk066;
    short unk068;
    short unk06A;
    short unk06C;
    short unk06E;
    short unk070;
    short unk072;
    short unk074;
    short unk076;
    short unk078;
    short unk07A;
    short unk07C;
    short unk07E;
    short unk080;
    short unk082;
    short unk084;
    short unk086;
    short unk088;
    short unk08A;
    short unk08C;
    short unk08E;
    short unk090;
    short unk092;
    short unk094;
    short unk096;
    short unk098;
    short unk09A;
    short unk09C;
    short unk09E;
    short unk0A0;
    short unk0A2;
    short unk0A4;
    short unk0A6;
    short unk0A8;
    short unk0AA;
    short unk0AC;
    short unk0AE;
    short unk0B0;
    short unk0B2;
    short unk0B4;
    short unk0B6;
    short unk0B8;
    short unk0BA;
    short unk0BC;
    short unk0BE;
    short unk0C0;
    short unk0C2;
    short unk0C4;
    short unk0C6;
    short unk0C8;
    short unk0CA;
    short unk0CC;
    short unk0CE;
    short unk0D0;
    short unk0D2;
    short unk0D4;
    short unk0D6;
    short unk0D8;
    short unk0DA;
    short unk0DC;
    short unk0DE;
    short unk0E0;
    short unk0E2;
    short unk0E4;
    short unk0E6;
    short unk0E8;
    short unk0EA;
    short unk0EC;
    short unk0EE;
    short unk0F0;
    short unk0F2;
    short unk0F4;
    short unk0F6;
    short unk0F8;
    short unk0FA;
    short unk0FC;
    short unk0FE;
    short unk100;
    short unk102;
    short unk104;
    short unk106;
    short unk108;
    short unk10A;
    short unk10C;
    short unk10E;
    short unk110;
    short unk112;
    short unk114;
    short unk116;
    short unk118;
    short unk11A;
    short unk11C;
    DA0920Half m_fWeight;

    DA0920Base(DA0920FinishFlag flag)
    {
        if (flag.m_bFinishing)
            m_fWeight = 1.0f;
    }
    virtual void vfunc00();

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

class DA0920Object : public DA0920Base
{
  public:
    DA0920Object(DA0920FinishFlag flag) : DA0920Base(flag)
    {}
    virtual void vfunc00();
};

// Place-constructs a DA0920Object at p with a DA0920FinishFlag built from finishing, when p is non-null.
// @fnv 0x00da0920
void ConstructDA0920Object(void* apMemory, int finishing)
{
    if (apMemory)
    {
        DA0920FinishFlag flag;
        flag.m_bFinishing = finishing;
        new (apMemory) DA0920Object(flag);
    }
}

extern int g_unk010c6c64;

// @fnv 0x00da0950
// src: GUESS 0x00da0950 (confidence: low)
void* __cdecl Runtime_GetUnk010c6c64Address()
{
    return &g_unk010c6c64;
}

extern int DAT_0126979c;

// @fnv 0x00da0970
// src: GUESS 0x00da0970 (confidence: low)
void* __cdecl Runtime_GetDAT0126979cAddress()
{
    return &DAT_0126979c;
}

extern void* DAT_012697cc;

// @fnv 0x00da09a0
// src: GUESS 0x00da09a0 (confidence: low)
void* Object_GetGlobalObjectAddress_00da09a0()
{
    return &DAT_012697cc;
}

struct CpuOpaque;
extern CpuOpaque DAT_012697fc;
// @fnv 0x00da09c0
// src: GUESS 0x00da09c0 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00da09c0()
{
    return &DAT_012697fc;
}

extern int DAT_0126982c;

// @fnv 0x00da09e0
// src: GUESS 0x00da09e0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00da09e0()
{
    return &DAT_0126982c;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126985c;
// @fnv 0x00da0a00
// src: GUESS 0x00da0a00 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00da0a00()
{
    return &DAT_0126985c;
}

extern int DAT_0126988c;

// @fnv 0x00da0a20
// src: GUESS 0x00da0a20 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00da0a20()
{
    return &DAT_0126988c;
}

// FUN_00da0a40 : a one-line function - getter
extern int g_target_00da0a40;
// @fnv 0x00da0a40
// src: GUESS 0x00da0a40 (confidence: low)
void* Object_GetGlobalObjectAddress_00da0a40()
{
    return &g_target_00da0a40;
}

extern int DAT_012698ec;

// @fnv 0x00da0a60
// src: GUESS 0x00da0a60 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00da0a60()
{
    return &DAT_012698ec;
}

// FUN_00da0a80 : returns the address of a global data object.
extern int DAT_0126991c;

// @fnv 0x00da0a80
// src: GUESS 0x00da0a80 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00da0a80(void)
{
    return &DAT_0126991c;
}

extern int DAT_0126994c;

// @fnv 0x00da0aa0
// src: GUESS 0x00da0aa0 (confidence: low)
int __cdecl Object_ComputeValue_00da0aa0()
{
    return reinterpret_cast<int>(&DAT_0126994c);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126997c;
// @fnv 0x00da0ac0
// src: GUESS 0x00da0ac0 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00da0ac0()
{
    return &DAT_0126997c;
}

extern int DAT_012699ac;

// @fnv 0x00da0ae0
// src: GUESS 0x00da0ae0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00da0ae0(void)
{
    return &DAT_012699ac;
}

struct FUN_00da0af0_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00da0af0
// src: GUESS 0x00da0af0 (confidence: low)
void __cdecl Runtime_ForwardCall_00da0af0(FUN_00da0af0_Class* param_1)
{
    param_1->vf00(0);
}

extern int DAT_01269a0c;

// @fnv 0x00da0b00
// src: GUESS 0x00da0b00 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00da0b00()
{
    return &DAT_01269a0c;
}

extern int DAT_010c6fd0;

// @fnv 0x00da0b20
// src: GUESS 0x00da0b20 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00da0b20()
{
    return &DAT_010c6fd0;
}

// Compares the first three ints in values and writes 1 to result if any two are equal, otherwise 0.
// @fnv 0x00da0ba0
unsigned char* __cdecl CheckDuplicateValues(unsigned char* result, int* values)
{
    unsigned char flag;
    if (values[0] == values[1] || values[0] == values[2] || values[1] == values[2])
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    *result = flag;
    return result;
}

struct FUN_00db0060_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    void __thiscall hk1AxisSweep_AabbInt_set(int* param_2, int param_3);
};

// @fnv 0x00db0060
// src: HAVOK_LIB 0x00db0060
void __thiscall FUN_00db0060_class::hk1AxisSweep_AabbInt_set(int* aiValues, int param_3)
{
    int value;

    value = aiValues[0];
    unk00 = (((value >> 31) | 0x80000001) ^ value) >> 1;

    value = aiValues[1];
    unk04 = (((value >> 31) | 0x80000001) ^ value) >> 1;

    value = aiValues[2];
    unk08 = (((value >> 31) | 0x80000001) ^ value) >> 1;

    unk0C = param_3;

    value = aiValues[4];
    unk10 = ((((value >> 31) | 0x80000001) ^ value) >> 1) + 1;

    value = aiValues[5];
    unk14 = ((((value >> 31) | 0x80000001) ^ value) >> 1) + 1;

    value = aiValues[6];
    unk18 = ((((value >> 31) | 0x80000001) ^ value) >> 1) + 1;
}

struct DB7570Pair
{
    unsigned int m_key;
    unsigned int m_uiFilterValue;
};


class DB7570Map
{
  public:
    int unk00;
    DB7570Pair* m_data;
    int m_iElementCount;

    hkResult Lookup(unsigned int key, unsigned int& valueOut) const;
};

// Searches m_data for an entry whose m_key equals key; on a match stores its value in valueOut and returns HK_SUCCESS, otherwise HK_FAILURE.
// @fnv 0x00db7570
hkResult DB7570Map::Lookup(unsigned int key, unsigned int& valueOut) const
{
    for (int i = 0; i < m_iElementCount; i++)
    {
        if (m_data[i].m_key == key)
        {
            valueOut = m_data[i].m_uiFilterValue;
            return HK_SUCCESS;
        }
    }
    return HK_FAILURE;
}

extern "C" int __cdecl CompareStringsCaseInsensitive(int a1, int a2);

struct FUN_00db75b0_entry
{
    int unk00;
    int unk04;
};

struct FUN_00db75b0_class
{
    int unk00;
    FUN_00db75b0_entry* unk04;
    int unk08;

    unsigned int __thiscall hkClassEnum_getValueOfName(int a1, unsigned int* a2);
};

// @fnv 0x00db75b0
// src: HAVOK_LIB 0x00db75b0
unsigned int __thiscall FUN_00db75b0_class::hkClassEnum_getValueOfName(int a1, unsigned int* a2)
{
    for (int index = 0; index < unk08; ++index)
    {
        unsigned int value = unk04[index].unk04;
        if (CompareStringsCaseInsensitive(a1, value) == 0)
        {
            unsigned int result = unk04[index].unk00;
            *a2 = result;
            return 0;
        }
    }
    return 1;
}

struct FUN_00db78a0_item
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
};

class FUN_00db78a0_cls
{
  public:
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0c(void* field, void* item);
    void hkVtableClassRegistry_registerList(FUN_00db78a0_item** a, void** b);
};

// @fnv 0x00db78a0
// src: HAVOK_LIB 0x00db78a0
void FUN_00db78a0_cls::hkVtableClassRegistry_registerList(FUN_00db78a0_item** apItems, void** apValues)
{
    FUN_00db78a0_item** p = apItems;
    if (*p == 0)
        return;
    do
    {
        void* item = *(void**)((char*)apValues + ((char*)p - (char*)apItems));
        if (item == 0)
            break;
        void* field = (*p)->m_0c;
        if (field != 0)
            this->vSlot0c(field, item);
        p++;
    } while (*p != 0);
}

BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

struct MapPair
{
    unsigned int key;
    unsigned int val;
};

struct HashEntryTable
{
    MapPair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int GetFirstIterator() const
    {
        int i;
        for (i = 0; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    int getNext(int it) const
    {
        int i;
        for (i = it + 1; i <= m_iPairCount; ++i)
        {
            if (m_kPrimitiveElement[i].key != (unsigned int)-1)
                break;
        }
        return i;
    }
    bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
    unsigned int GetIteratorKey(int it) const
    {
        return m_kPrimitiveElement[it].key;
    }
    unsigned int getValue(int it) const
    {
        return m_kPrimitiveElement[it].val;
    }

    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(hkMemoryAllocator& alloc, unsigned int key, unsigned int val);
};

struct MapHolder
{
    int unk00, unk04;
    HashEntryTable m_map;

    void CopyMapEntries(const MapHolder& other);
};

// Copies each valid key/value pair from other's map into this map, allocating from the audio heap.
// @fnv 0x00db78e0
void MapHolder::CopyMapEntries(const MapHolder& other)
{
    for (int it = other.m_map.GetFirstIterator(); other.m_map.isValid(it); it = other.m_map.getNext(it))
        m_map.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(audio()->heap(), other.m_map.GetIteratorKey(it), other.m_map.getValue(it));
}

namespace fnv_00db7960 {
extern "C" void* __cdecl hkMemoryRouter_getInstance();
extern int DAT_010cf844;

struct FUN_00db7960_Data
{
    void __thiscall EnsureCapacity(void* a, int b);
};

struct FUN_00db7960_Result
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
};

// Allocates a 0x14-byte result via the audio target's vf04, initialises its header and data fields, then calls EnsureCapacity on the data and returns it.
// @fnv 0x00db7960
void* __cdecl CreateAudioResult()
{
    hkMemoryRouter* audio = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    hkMemoryAllocator* target = audio->m_heap;

    void* allocated = target->blockAlloc(0x14);
    FUN_00db7960_Result* result = reinterpret_cast<FUN_00db7960_Result*>(allocated);

    result->unk04 = 0x14;
    result->unk06 = 1;
    result->unk00 = &DAT_010cf844;

    int* data = reinterpret_cast<int*>(reinterpret_cast<char*>(allocated) + 8);
    data[0] = 0;
    data[1] = 0;
    data[2] = -1;

    hkMemoryRouter* audio2 = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    void* target2 = audio2->m_heap;

    FUN_00db7960_Data* dataObject = reinterpret_cast<FUN_00db7960_Data*>(reinterpret_cast<char*>(allocated) + 8);
    dataObject->EnsureCapacity(target2, 0);

    return allocated;
}
}  // namespace fnv_00db7960

namespace fnv_00db7a20 {

__declspec(nothrow) BSAudio* __cdecl hkMemoryRouter_getInstance();

// This constructor takes the original one-word POD hkBool argument. The shared
// hkBool has a user-declared copy constructor, so pass the legacy ABI slot directly.
inline unsigned int MakeBool(bool b)
{
    unsigned int slot;
    reinterpret_cast<hkBool*>(&slot)->m_cBooleanValue = (char)b;
    return slot;
}

class RefObj
{
  public:
    RefObj()
    {
        m_sReferenceCount = 1;
    }
    virtual ~RefObj();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        RefObj* b = (RefObj*)((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap().blockAlloc(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void __cdecl operator delete(void* p);
};

struct Inner
{
    __declspec(nothrow) Inner(unsigned int bFlag);
    int m_data[4];
};

class Thing : public RefObj
{
  public:
    Thing() : m_kInner(MakeBool(false))
    {
        m_iFadeIndex = 1;
    }
    virtual ~Thing();
    Inner m_kInner;
    int m_iFadeIndex;
};

// Allocates and constructs a new Thing object and returns it.
// @fnv 0x00db7a20
Thing* __cdecl CreateThing()
{
    return new Thing();
}
}  // namespace fnv_00db7a20

// ForwardToInner: forwards a 64-bit value to a member function held at this->m_08.
struct SpawnedInner
{
    void GetB(__int64 v);
};

struct SpawnedOuter
{
    int unk00;
    int unk04;
    SpawnedInner* m_08;

    void ForwardToInner(__int64 v);
};

// @fnv 0x00db7c90
void SpawnedOuter::ForwardToInner(__int64 v)
{
    m_08->GetB(v);
}

struct CallTarget_00dba270
{
    int Splice(int, int, int, int, int);
};
struct SearchObject
{
    int ProcessAndReturnValue_00dba320(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00dba320
// src: GUESS 0x00dba320 (confidence: low)
int SearchObject::ProcessAndReturnValue_00dba320(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00dba270*)this)->Splice((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)callResult0;
}

class DBA340Object
{
  public:
    int ProcessAndReturnValue_00dba320(void* pvA, void* pvB, void* pvC, int iFlag);
    int ForwardCall_00dba340(void* pvA, void* pvB, void* pvC);
};

// @fnv 0x00dba340
// src: GUESS 0x00dba340 (confidence: low)
int DBA340Object::ForwardCall_00dba340(void* pvA, void* pvB, void* pvC)
{
    return ProcessAndReturnValue_00dba320(pvA, pvB, pvC, 1);
}

namespace fnv_00dba3d0 {

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

struct DBA3D0Pair
{
    int m_iKey;
    int m_iValue;
};

template <class T>
static __forceinline void DBA3D0Array_destroy(hkArrayBase<T>& self) throw()
{
        hkMemoryAllocator& alloc = hkMemoryRouter_getInstance().heap();
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(self.m_data, self.getCapacity() * sizeof(T));
        self.m_iCapacityState = 0x80000000;
        self.m_data = 0;
    }

struct DBA3D0ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { DBA3D0Array_destroy(self); }
};

class DBA3D0MapBase
{
  public:
    ~DBA3D0MapBase() throw();

    void ClearAndRelease(hkMemoryAllocator& alloc) throw();

    int unk00;
    int unk04;
};

class DBA3D0Map : public DBA3D0MapBase
{
  public:
    ~DBA3D0Map() throw()
    {
        ClearAndRelease(hkMemoryRouter_getInstance().heap());
    }
};

class FUN_00dba3d0
{
  public:
    ~FUN_00dba3d0() throw();

    hkArray<DBA3D0Pair, DBA3D0ArrayPolicy> m_kPairs;
    DBA3D0Map m_kFormatEntries;
};

// Destructor: destroys the pair array and map members, which free their storage through the heap allocator.
// @fnv 0x00dba3d0
FUN_00dba3d0::~FUN_00dba3d0() throw()
{}
}  // namespace fnv_00dba3d0

struct DBB100Class
{
    const char* getName() const;
};

struct DBB100Registry
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual const DBB100Class* getClassByObject(const void* object) const;
};

struct DBB100Writer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void WriteCString(const char* s);
};

// @fnv 0x00dbb100
// src: GUESS 0x00dbb100 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00dbb100(const DBB100Registry* registry, const void* object, DBB100Writer* writer)
{
    const DBB100Class* pClass = registry->getClassByObject(object);
    if (pClass)
        writer->WriteCString(pClass->getName());
}

// Caller so the file-static helper is emitted with its register calling convention.
void DBB100WriteClassNames(const DBB100Registry* registry, const void** objects, DBB100Writer* writer)
{
    Object_UpdateFields_00dbb100(registry, objects[0], writer);
    Object_UpdateFields_00dbb100(registry, objects[1], writer);
}

hkMemoryRouter* __cdecl da06d0_getRouter();
struct Elem
{
    int unk00;
    int unk04;
};
struct Buffer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    Elem* m_ppData;
    int m_iElementCount;
    int m_pRayCursor;
};
// @fnv 0x00da06d0
// src: HAVOK_LIB 0x00da06d0
void __cdecl cleanupLoadedObjecthkpLinkedCollidable(Buffer* self)
{
    int* pSize = &self->m_iElementCount;
    int* piCapacity = &self->m_pRayCursor;
    hkMemoryRouter* router = da06d0_getRouter();
    hkMemoryAllocator* alloc = router->m_heap;
    int iCapacity = self->m_pRayCursor;
    *pSize = 0;
    if ((iCapacity & (int)0x80000000) == 0)
        alloc->bufFree(self->m_ppData, (iCapacity & 0x3fffffff) * sizeof(Elem));
    *piCapacity = (int)0x80000000;
    self->m_ppData = 0;
}

struct SweepBounds
{
    unsigned int minX, minY, minZ, key;
    unsigned int maxX, maxY, maxZ, reserved;
};
struct SweepPair
{
    unsigned int first, second;
};

inline unsigned int separatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxY - b.minY) | (a.maxZ - b.minZ) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}
inline SweepPair* emitPair(const SweepBounds& a, const SweepBounds& b, SweepPair* out, SweepPair* end, int& skipped)
{
    if (out < end)
    {
        out->first = a.key;
        out->second = b.key;
        ++out;
    }
    else
        ++skipped;
    return out;
}

__forceinline SweepPair* collideOne(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                    int& skipped)
{
    const unsigned int maxX = bounds->maxX;

    while (scan->minX < maxX)
    {
        unsigned int d0 = separatedYZ(*bounds, scan[0]);
        unsigned int d1 = separatedYZ(*bounds, scan[1]);
        unsigned int d2 = separatedYZ(*bounds, scan[2]);
        unsigned int d3 = separatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}

// For each of count-1 consecutive bounds, emits overlapping pairs into pairs up to capacity, counts skipped, and returns the number written.
// @fnv 0x00db04a0
int __cdecl SweepCollidePairs(const SweepBounds* bounds, int count, SweepPair* pairs, int capacity, int& skipped)
{
    SweepPair* end = pairs + capacity;
    SweepPair* out = pairs;
    skipped = 0;
    for (--count; count > 0; --count)
    {
        out = collideOne(bounds, bounds + 1, out, end, skipped);
        ++bounds;
    }
    return int(out - pairs);
}

struct DBA430Inner
{
    void __thiscall Sync(hkMemoryAllocator* listener);
    void __thiscall Mark();
};

struct DBA430Owner
{
    int m_00;
    int m_04;
    int m_08;
    DBA430Inner m_0C;

    void Reset();
};

// @fnv 0x00dba430
void DBA430Owner::Reset()
{
    DBA430Inner* p = &m_0C;
    p->Sync(reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->pListener));
    p->Mark();
    BSAudio* audio = hkMemoryRouter_getInstance();
    hkMemoryAllocator* listener = reinterpret_cast<hkMemoryAllocator*>(audio->pListener);
    m_04 = 0;
    if (!(m_08 & (int)0x80000000))
    {
        int n = m_08 & 0x3fffffff;
        n = n + n;
        n = n + n;
        n = n + n;
        listener->bufFree(reinterpret_cast<void*>(m_00), n);
    }
    m_08 = (int)0x80000000;
    m_00 = 0;
}

union FeaturePair
{
    unsigned short pair;
    struct
    {
        unsigned char first;
        unsigned char second;
        unsigned char detail;
        unsigned char flags;
    };
};
struct FeatureCache
{
    FeaturePair entries[8];
    unsigned char dimension;
    unsigned char count;
    bool result;
};
__forceinline int excludedAxis(int flags)
{
    signed char bits = static_cast<signed char>(flags >> 4);
    return (bits & 1) ? 0 : ((bits & 2) ? 1 : 2);
}
__forceinline void addCell(int& mask, int cell)
{
    int bit = 1 << (cell * 2);
    if (!(mask & (bit * 2)))
        mask += bit;
}
__forceinline void UpdateAxisMask(int& mask, unsigned char value, int axis)
{
    unsigned int bits = value >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis != 0)
        addCell(mask, y + 2 * z);
    if (axis != 1)
        addCell(mask, x + 2 * z + 4);
    if (axis != 2)
        addCell(mask, x + 2 * y + 8);
}
__forceinline void addEdge(int& mask, int value)
{
    int axis = value & 15;
    unsigned int bits = value >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis == 0)
        addCell(mask, y + 2 * z);
    else if (axis == 1)
        addCell(mask, x + 2 * z + 4);
    else
        addCell(mask, x + 2 * y + 8);
}
// Returns early if count < 3; if dimension >= 4 sets result true, otherwise builds masks from entries and sets result to whether neither mask has occupied cells.
// @fnv 0x00db0b00
void __stdcall CheckFeatureCacheCoverage(FeatureCache* cache, int firstFlags, int secondFlags)
{
    if (cache->count < 3)
        return;
    if (cache->dimension >= 4)
    {
        cache->result = true;
        return;
    }
    int firstAxis = excludedAxis(firstFlags);
    secondFlags = excludedAxis(secondFlags);
    int firstMask = 0;
    int secondMask = 0;
    for (int i = 0; i < cache->count; ++i)
    {
        unsigned char first = cache->entries[i].first;
        if (first <= 2)
            UpdateAxisMask(secondMask, cache->entries[i].second, secondFlags);
        else if (first <= 6)
            UpdateAxisMask(firstMask, cache->entries[i].second, firstAxis);
        else
        {
            addEdge(firstMask, first);
            addEdge(secondMask, static_cast<unsigned char>(cache->entries[i].pair >> 8));
        }
    }
    bool occupied = (firstMask & 0x555555) > 0 || (secondMask & 0x555555) > 0;
    cache->result = !occupied;
}

// @fnv 0x00da0600
// src: COMMUNITY 0x00da0600
void __cdecl nullsub_104()
{}

// @fnv 0x00da0620
// src: COMMUNITY 0x00da0620
void __cdecl nullsub_106(void)
{}

// @fnv 0x00da0640
// src: COMMUNITY 0x00da0640
void nullsub_105()
{}

// @fnv 0x00da0650
// src: COMMUNITY 0x00da0650
void nullsub_107()
{}

// @fnv 0x00da0960
// src: COMMUNITY 0x00da0960
void __cdecl nullsub_109()
{}

// @fnv 0x00da0980
// src: COMMUNITY 0x00da0980
void __cdecl nullsub_108()
{}

// @fnv 0x00da0990
// src: COMMUNITY 0x00da0990
void __cdecl nullsub_110()
{}

// @fnv 0x00da09b0
// src: COMMUNITY 0x00da09b0
void __cdecl nullsub_111()
{}

// @fnv 0x00da09d0
// src: COMMUNITY 0x00da09d0
void __cdecl nullsub_112()
{}

// @fnv 0x00da09f0
// src: COMMUNITY 0x00da09f0
void __cdecl nullsub_113()
{}

// @fnv 0x00da0a10
// src: COMMUNITY 0x00da0a10
void nullsub_114()
{}

// @fnv 0x00da0a30
// src: COMMUNITY 0x00da0a30
void __cdecl nullsub_115()
{}

// @fnv 0x00da0a50
// src: COMMUNITY 0x00da0a50
void __cdecl nullsub_116()
{}

// @fnv 0x00da0a70
// src: COMMUNITY 0x00da0a70
void __cdecl nullsub_117()
{}

// @fnv 0x00da0a90
// src: COMMUNITY 0x00da0a90
void __cdecl nullsub_118()
{}

// @fnv 0x00da0ab0
// src: COMMUNITY 0x00da0ab0
void __cdecl nullsub_119()
{}

// @fnv 0x00da0ad0
// src: COMMUNITY 0x00da0ad0
void __cdecl nullsub_120()
{}

struct CallbackHolder
{
    int unk00;
    int unk04;
    int unk08;
    void(__stdcall* callback)(void* argument);
};

extern void*(__stdcall* DAT_00fdf110)();

struct FUN_00da2b30_Class
{
    int unk00;
    int unk04;
    CallbackHolder* holder;

    void InvokeCallback();
};

// @fnv 0x00da2b30
void FUN_00da2b30_Class::InvokeCallback()
{
    CallbackHolder* value = holder;
    if (value->callback)
    {
        value->callback(DAT_00fdf110());
    }
}

extern int DAT_010d4de4;
extern int DAT_01269a9c;

struct FUN_00da2840_Obj
{
    void __thiscall hkStackTracerWin32Data_init();
};

struct FUN_00da2b90_Obj
{
    int unk00;
    short unk04;
    short unk06;
    int* unk08;

    unsigned int* __thiscall Initialize();
};

// Sets unk06 to 1, stores pointers to DAT_010d4de4 and DAT_01269a9c, calls FUN_00da2840 on DAT_01269a9c, and returns this.
// @fnv 0x00da2b90
unsigned int* __thiscall FUN_00da2b90_Obj::Initialize()
{
    unk06 = 1;
    unk00 = reinterpret_cast<int>(&DAT_010d4de4);
    unk08 = &DAT_01269a9c;

    reinterpret_cast<FUN_00da2840_Obj*>(&DAT_01269a9c)->hkStackTracerWin32Data_init();

    return reinterpret_cast<unsigned int*>(this);
}

struct DA2D70Object
{
    int unk00;
    unsigned short unk04;

    void __thiscall ReleaseStackTraceModule();
    void* __thiscall NotifyAudioListener(int flags);
};

// @fnv 0x00da2d70
void* DA2D70Object::NotifyAudioListener(int flags)
{
    ReleaseStackTraceModule();

    if (flags & 1)
    {
        BSAudio* audio = hkMemoryRouter_getInstance();
        hkMemoryAllocator* listener = reinterpret_cast<hkMemoryAllocator*>(audio->pListener);
        listener->blockFree(this, static_cast<int>(unk04));
    }

    return this;
}

// @fnv 0x00da2da0
// src: COMMUNITY 0x00da2da0
void __cdecl nullsub_21()
{}

void __cdecl hkAgent1nMachine_VisitAllAgents(int a, int b, void* pvCallback);
void __cdecl ProcessCollisionEntry();

// @fnv 0x00da4900
// src: GUESS 0x00da4900 (confidence: medium)
void __cdecl Object_HkAgent1nMachine_VisitAllAgents_Thunk(int a, int b)
{
    hkAgent1nMachine_VisitAllAgents(a, b, reinterpret_cast<void*>(&ProcessCollisionEntry));
}

void* __cdecl hkpAgent1nSector_ProcessEntries_00da3510(void*, void*);
// @fnv 0x00da6e10
// src: GUESS 0x00da6e10 (confidence: low)
void* __cdecl Runtime_ForwardCall_00da6e10(void* apUnused, void* b, void* c)
{
    return hkpAgent1nSector_ProcessEntries_00da3510(b, c);
}

extern int DAT_010cf7d4;
extern int DAT_010cf804;
extern char str_010cf830[];

struct SubObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00d87790(int flags);
};

struct CreatedObject
{
    void* vtable;
    unsigned short allocatedSize;
    unsigned short enabled;
    const char* typeName;
    SubObject base;

    void Init()
    {
        union Flag
        {
            unsigned char byte;
            unsigned int word;
        } flag;

        allocatedSize = 0x20;
        enabled = 1;
        flag.byte = 0;
        unsigned int arg = flag.word;

        vtable = &DAT_010cf7d4;
        typeName = str_010cf830;
        base.FUN_00d87790(arg);
        vtable = &DAT_010cf804;
    }
};

// Allocates a 0x20-byte object from the manager's heap, initializes it, and returns it.
// @fnv 0x00db79c0
// src: HAVOK_LIB 0x00db79c0
void* __cdecl hkDefaultClassNameRegistrycreate()
{
    hkMemoryRouter* manager = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    CreatedObject* object = (CreatedObject*)manager->heap().blockAlloc(0x20);
    object->Init();
    return object;
}

struct FUN_00db7c00_obj
{
    virtual void vslot00(int value);
};

// @fnv 0x00db7c00
// src: GUESS 0x00db7c00 (confidence: medium)
void __cdecl Object_Vslot00_Thunk(FUN_00db7c00_obj* p)
{
    p->vslot00(0);
}

// 0x00db7c10  /MT /O2 /GS /EHsc /Gy   target: B8 28 9B 26 01 C3  (mov eax, offset DAT_01269b28; ret)
extern int DAT_01269b28;

// @fnv 0x00db7c10
// src: GUESS 0x00db7c10 (confidence: low)
int* Runtime_GetDAT01269b28Address()
{
    return &DAT_01269b28;
}

extern int DAT_010cce28;

struct hkLoadedObjectDB7C
{
    int* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    FUN_00cb0a70_class m_name;
};

// @fnv 0x00db7c20
void __cdecl InitLoadedObject(void* pvObject, int iFinishing)
{
    if (pvObject)
    {
        hkLoadedObjectDB7C* pkObject = static_cast<hkLoadedObjectDB7C*>(pvObject);
        pkObject->m_ppVirtualMethodTable = &DAT_010cce28;
        pkObject->m_name.ReturnSelf(iFinishing);
    }
}

extern "C" void __cdecl FUN_00ec658f(const void*);
extern unsigned char DAT_01269b80;
extern void* DAT_010d6260;
extern void* DAT_01269b78;
extern void* FUN_00fde2a0;
extern unsigned short DAT_01269b7e;
// @fnv 0x00dba610
// src: HAVOK_LIB 0x00dba610
void* __cdecl hkLogger_nullLogger()
{
    int iInitFlag = 1;
    if (!(DAT_01269b80 & iInitFlag))
    {
        *(unsigned int*)&DAT_01269b80 |= iInitFlag;
        DAT_01269b7e = iInitFlag;
        DAT_01269b78 = &DAT_010d6260;
        FUN_00ec658f(&FUN_00fde2a0);
    }
    return &DAT_01269b78;
}

typedef void(__cdecl* FuncDA34)();

void __cdecl ExecuteMoppAabbQuery();
void __cdecl hkCpuPairGetClosestPointsJob();
void __cdecl hkCpuWorldGetClosestPointsJob();
void __cdecl hkCpuPairLinearCastJob();
void __cdecl hkCpuWorldLinearCastJob();
void __cdecl ProcessWorkQueue();
void __cdecl ProcessAabbTree();
void __cdecl SplitJob();
void __cdecl hkpCollisionQueryJobQueueUtils_finishCollisionJob();

struct FuncTableDA34
{
    FuncDA34 m_func0;
    FuncDA34 m_func1;
    FuncDA34 m_func2;
    FuncDA34 m_func3;
    FuncDA34 m_func4;
    FuncDA34 m_func5;
    FuncDA34 m_func6;
};

extern FuncTableDA34 DAT_01269af0;

struct RegisterInfoDA34
{
    FuncTableDA34* m_table;
    int m_numFuncs;
    FuncDA34 m_funcA;
    FuncDA34 m_funcB;
};

class DispatcherDA34
{
  public:
    void SetEntry(int type, RegisterInfoDA34 info);
};

// Populates the DAT_01269af0 function table with seven handlers and registers it with dispatcher type 2 via SetEntry.
// @fnv 0x00da3400
// src: HAVOK_LIB 0x00da3400
void __cdecl hkpCollisionQueryJobQueueUtils_registerWithJobQueue(DispatcherDA34* dispatcher)
{
    DAT_01269af0.m_func3 = hkCpuPairLinearCastJob;
    DAT_01269af0.m_func4 = hkCpuWorldLinearCastJob;
    DAT_01269af0.m_func0 = ExecuteMoppAabbQuery;
    DAT_01269af0.m_func1 = hkCpuPairGetClosestPointsJob;
    DAT_01269af0.m_func2 = hkCpuWorldGetClosestPointsJob;
    DAT_01269af0.m_func5 = ProcessWorkQueue;
    DAT_01269af0.m_func6 = ProcessAabbTree;
    RegisterInfoDA34 info;
    info.m_funcA = SplitJob;
    info.m_funcB = hkpCollisionQueryJobQueueUtils_finishCollisionJob;
    info.m_table = &DAT_01269af0;
    info.m_numFuncs = 7;
    dispatcher->SetEntry(2, info);
}

namespace fnv_00da3480 {
void __cdecl hkCpuShapeRayCastJob();
void __cdecl hkCpuWorldRayCastJob();
void __cdecl FinishJobWithPair();
void __cdecl BuildKdTreeDistributed();
void __cdecl hkCpuKdTreeBuildFastDistributedSubJob();
void __cdecl hkCpuKdTreeBuildSetupJob();
void __cdecl hkCpuKdTreeBuildCoordinatorJob();
void __cdecl ExecuteJob();
void __cdecl CopyAndAdvance();
void __cdecl hkpRayCastQueryJobQueueUtils_finishRayCastQueryJob();

typedef void(__cdecl* AgentFuncDA34)();

struct AgentTableDA34
{
    AgentFuncDA34 m_apfnFuncs[8];
};

extern AgentTableDA34 DAT_01269ad0;

struct AgentInfoDA34
{
    AgentTableDA34* m_pkTable;
    int m_iNumFuncs;
    AgentFuncDA34 m_pfnCreate;
    AgentFuncDA34 m_pfnDestroy;
};

struct DispatcherDA34
{
    void SetEntry(int iType, AgentInfoDA34 kInfo);
};

// Populates DAT_01269ad0 with eight agent functions, builds kInfo, and registers it with pkDispatcher->SetEntry(3, kInfo).
// @fnv 0x00da3480
// src: HAVOK_LIB 0x00da3480
void __cdecl hkpRayCastQueryJobQueueUtils_registerWithJobQueue(DispatcherDA34* pkDispatcher)
{
    AgentInfoDA34 kInfo;
    kInfo.m_pfnCreate = CopyAndAdvance;
    kInfo.m_pfnDestroy = hkpRayCastQueryJobQueueUtils_finishRayCastQueryJob;
    kInfo.m_pkTable = &DAT_01269ad0;
    kInfo.m_iNumFuncs = 8;
    DAT_01269ad0.m_apfnFuncs[0] = hkCpuShapeRayCastJob;
    DAT_01269ad0.m_apfnFuncs[1] = hkCpuWorldRayCastJob;
    DAT_01269ad0.m_apfnFuncs[2] = FinishJobWithPair;
    DAT_01269ad0.m_apfnFuncs[3] = BuildKdTreeDistributed;
    DAT_01269ad0.m_apfnFuncs[4] = hkCpuKdTreeBuildFastDistributedSubJob;
    DAT_01269ad0.m_apfnFuncs[5] = hkCpuKdTreeBuildSetupJob;
    DAT_01269ad0.m_apfnFuncs[6] = hkCpuKdTreeBuildCoordinatorJob;
    DAT_01269ad0.m_apfnFuncs[7] = ExecuteJob;
    pkDispatcher->SetEntry(3, kInfo);
}
}  // namespace fnv_00da3480

// @fnv 0x00da82d0
// src: GUESS 0x00da82d0 (confidence: high)
void Runtime_DoNothing_00da82d0()
{}

inline unsigned int mySeparatedYZ(const SweepBounds& a, const SweepBounds& b)
{
    return ((a.maxZ - b.minZ) | (a.maxY - b.minY) | (b.maxY - a.minY) | (b.maxZ - a.minZ)) & 0x80000000u;
}

template <bool swapPairs>
__forceinline SweepPair* collideOneT(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out, SweepPair* end,
                                     int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0 = mySeparatedYZ(*bounds, scan[0]);
        unsigned int d1 = mySeparatedYZ(*bounds, scan[1]);
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (swapPairs)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (swapPairs)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}

template <>
__forceinline SweepPair* collideOneT<false>(const SweepBounds* bounds, const SweepBounds* scan, SweepPair* out,
                                            SweepPair* end, int& skipped)
{
    const unsigned int maxX = bounds->maxX;
    while (scan->minX < maxX)
    {
        unsigned int d0;
        unsigned int d1 = (d0 = mySeparatedYZ(*bounds, scan[0]), mySeparatedYZ(*bounds, scan[1]));
        unsigned int d2 = mySeparatedYZ(*bounds, scan[2]);
        unsigned int d3 = mySeparatedYZ(*bounds, scan[3]);
        if (!(d0 & d1 & d2 & d3))
        {
            if (!d0)
            {
                if (false)
                    out = emitPair(scan[0], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[0], out, end, skipped);
            }
            if (!d1 && scan[1].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[1], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[1], out, end, skipped);
            }
            if (!d2 && scan[2].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[2], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[2], out, end, skipped);
            }
            if (!d3 && scan[3].minX <= maxX)
            {
                if (false)
                    out = emitPair(scan[3], *bounds, out, end, skipped);
                else
                    out = emitPair(*bounds, scan[3], out, end, skipped);
            }
        }
        scan += 4;
    }
    return out;
}

// Performs a sweep-and-prune collision test between two sorted SweepBounds arrays, emitting overlapping pairs into a buffer and returning the pair count.
// @fnv 0x00db00f0
int __cdecl CollideSweepBounds(const SweepBounds* apBoundsA, int aiCountA, const SweepBounds* apBoundsB, int aiCountB,
                               SweepPair* __restrict pairs, int capacity, int& skipped)
{
    SweepPair* out = pairs;
    SweepPair* end = pairs + capacity;
    skipped = 0;

    for (;;)
    {
        if (apBoundsA->minX > apBoundsB->minX)
        {
            out = collideOneT<true>(apBoundsB, apBoundsA, out, end, skipped);
            ++apBoundsB;
            if (--aiCountB <= 0)
                break;
        }
        else
        {
            out = collideOneT<false>(apBoundsA, apBoundsB, out, end, skipped);
            ++apBoundsA;
            if (--aiCountA <= 0)
                break;
        }
    }

    return (int)(out - pairs);
}

// @fnv 0x00db09f0
// src: HAVOK_LIB 0x00db09f0
static __declspec(noinline) float getNormalSignFromFeatureBitSet(unsigned short arg)
{
    union
    {
        float f;
        unsigned int i;
    } u;
    u.f = 1.0f;
    u.i |= ((unsigned int)arg & 0xfffffff8u) << 28;
    return u.f;
}

unsigned short volatile g_in_db09f0;
float volatile g_out_db09f0;

void drive_db09f0(void)
{
    g_out_db09f0 = getNormalSignFromFeatureBitSet(g_in_db09f0);
}

extern int DAT_010d52d0;
extern "C" unsigned int stub_val(void);

// @fnv 0x00db0db0
// src: GUESS 0x00db0db0 (confidence: low)
static __declspec(noinline) int* Runtime_GetMaskedValue_00db0db0(unsigned int a)
{
    return (int*)((a & 0x70) + (unsigned int)&DAT_010d52d0);
}

int stub_caller(void)
{
    return (int)Runtime_GetMaskedValue_00db0db0(stub_val());
}

struct FUN_00db7c80_class
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int* Get0cAddress_00db7c80();
};

// @fnv 0x00db7c80
// src: GUESS 0x00db7c80 (confidence: low)
int* FUN_00db7c80_class::Get0cAddress_00db7c80()
{
    return &m_0c;
}

#include <xmmintrin.h>
struct RadixRecord
{
    unsigned int key;
    unsigned int value;
};
// Sorts RadixRecord entries by key using four passes of LSD radix sort, alternating between records and scratch buffers.
// @fnv 0x00da0010
void __cdecl RadixSort(RadixRecord* records, int count, RadixRecord* scratch)
{
    __declspec(align(16)) unsigned int histogram0[256];
    __declspec(align(16)) unsigned int histogram1[256];
    __declspec(align(16)) unsigned int histogram2[256];
    __declspec(align(16)) unsigned int histogram3[256];
    RadixRecord* cursor0[256];
    RadixRecord* cursor1[256];
    RadixRecord* cursor2[256];
    RadixRecord* cursor3[256];
    for (unsigned int* p = histogram0; p < histogram0 + 256; p += 4)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
    for (unsigned int* p = histogram1; p < histogram1 + 256; p += 4)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
    for (unsigned int* p = histogram2; p < histogram2 + 256; p += 4)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
    for (unsigned int* p = histogram3; p < histogram3 + 256; p += 4)
    {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
    if (count > 0)
    {
        const unsigned char* key = reinterpret_cast<const unsigned char*>(records) + 2;
        int diff = reinterpret_cast<const char*>(scratch) - reinterpret_cast<const char*>(records);
        unsigned int blocks = (static_cast<unsigned int>(count - 1) >> 2) + 1;
        do
        {
            {
                unsigned int byte0 = key[-2];
                unsigned int byte1 = key[-1];
                unsigned int byte2 = key[0];
                unsigned int byte3 = key[1];
                ++histogram0[byte0];
                ++histogram1[byte1];
                ++histogram2[byte2];
                ++histogram3[byte3];
            }
            {
                unsigned int byte0 = key[6];
                unsigned int byte1 = key[7];
                unsigned int byte2 = key[8];
                unsigned int byte3 = key[9];
                ++histogram0[byte0];
                ++histogram1[byte1];
                ++histogram2[byte2];
                ++histogram3[byte3];
            }
            const char* ahead = reinterpret_cast<const char*>(key) + 1022;
            _mm_prefetch(ahead + diff, 0);
            _mm_prefetch(ahead, 0);
            {
                unsigned int byte0 = key[14];
                unsigned int byte1 = key[15];
                unsigned int byte2 = key[16];
                unsigned int byte3 = key[17];
                ++histogram0[byte0];
                ++histogram1[byte1];
                ++histogram2[byte2];
                ++histogram3[byte3];
            }
            {
                unsigned int byte0 = key[22];
                unsigned int byte1 = key[23];
                unsigned int byte2 = key[24];
                unsigned int byte3 = key[25];
                ++histogram0[byte0];
                ++histogram1[byte1];
                ++histogram2[byte2];
                ++histogram3[byte3];
            }
            key += 32;
        } while (--blocks);
    }
    cursor0[0] = scratch;
    cursor1[0] = records;
    cursor2[0] = scratch;
    cursor3[0] = records;
    for (int i = 0; i < 255; ++i)
    {
        cursor0[i + 1] = histogram0[i] + cursor0[i];
        cursor1[i + 1] = histogram1[i] + cursor1[i];
        cursor2[i + 1] = histogram2[i] + cursor2[i];
        cursor3[i + 1] = histogram3[i] + cursor3[i];
    }
    for (int i = 0; i < count; i += 4)
    {
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 0].key)[0];
            *cursor0[bucket] = records[i + 0];
            cursor0[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 1].key)[0];
            *cursor0[bucket] = records[i + 1];
            cursor0[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 2].key)[0];
            *cursor0[bucket] = records[i + 2];
            cursor0[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 3].key)[0];
            *cursor0[bucket] = records[i + 3];
            cursor0[bucket] += 1;
        }
    }
    for (int i = 0; i < count; i += 4)
    {
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 0].key)[1];
            *cursor1[bucket] = scratch[i + 0];
            cursor1[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 1].key)[1];
            *cursor1[bucket] = scratch[i + 1];
            cursor1[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 2].key)[1];
            *cursor1[bucket] = scratch[i + 2];
            cursor1[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 3].key)[1];
            *cursor1[bucket] = scratch[i + 3];
            cursor1[bucket] += 1;
        }
    }
    for (int i = 0; i < count; i += 4)
    {
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 0].key)[2];
            *cursor2[bucket] = records[i + 0];
            cursor2[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 1].key)[2];
            *cursor2[bucket] = records[i + 1];
            cursor2[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 2].key)[2];
            *cursor2[bucket] = records[i + 2];
            cursor2[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&records[i + 3].key)[2];
            *cursor2[bucket] = records[i + 3];
            cursor2[bucket] += 1;
        }
    }
    for (int i = 0; i < count; i += 4)
    {
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 0].key)[3];
            *cursor3[bucket] = scratch[i + 0];
            cursor3[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 1].key)[3];
            *cursor3[bucket] = scratch[i + 1];
            cursor3[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 2].key)[3];
            *cursor3[bucket] = scratch[i + 2];
            cursor3[bucket] += 1;
        }
        {
            unsigned int bucket = reinterpret_cast<const unsigned char*>(&scratch[i + 3].key)[3];
            *cursor3[bucket] = scratch[i + 3];
            cursor3[bucket] += 1;
        }
    }
}

extern double DAT_01034208;

struct TriIndexRec_b4046
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct TriIndexSet_b4046
{
    __m128* m_00;
    int unk04;
    int unk08;
    TriIndexRec_b4046* m_0c;
    int m_10;
};

// @fnv 0x00da0c30
// src: GUESS 0x00da0c30 (confidence: low)
float __cdecl Object_ProcessEntries_00da0c30(TriIndexSet_b4046* self)
{
    float sum = 0.0f;
    int count = self->m_10;

    if (count > 0)
    {
        __m128* vertices = self->m_00;
        TriIndexRec_b4046* record = self->m_0c;

        do
        {
            const __m128& a = vertices[record->m_08];
            const __m128& b = vertices[record->m_04];
            const __m128& c = vertices[record->m_00];

            __m128 ad = _mm_shuffle_ps(a, a, 0xd2);
            __m128 bc = _mm_shuffle_ps(b, b, 0xc9);
            __m128 first = _mm_mul_ps(bc, ad);

            __m128 ac = _mm_shuffle_ps(a, a, 0xc9);
            __m128 bd = _mm_shuffle_ps(b, b, 0xd2);
            __m128 second = _mm_mul_ps(ac, bd);

            __m128 product = _mm_mul_ps(_mm_sub_ps(first, second), c);

            float value;
            _mm_store_ss(&value, _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa),
                                            _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product)));

            sum = sum + value;
            ++record;
            --count;
        } while (count != 0);
    }

    float result = (float)(sum / DAT_01034208);
    return result;
}

struct ArgObj
{
    int hkStackTracer_getStackTrace(int* buffer, int size);
};

struct Holder
{
    int FindOrAddCallTrace(int* buffer, int count);
    int hkStackTracer_CallTree_insertCallStack(ArgObj* param);
};

// src: XBOX_PDB 0x00da2b20
__declspec(noinline) int ArgObj::hkStackTracer_getStackTrace(int* buffer, int size)
{
    return 0;
}

__declspec(noinline) int Holder::FindOrAddCallTrace(int* buffer, int count)
{
    return 0;
}

// Fills a 0x40-word buffer via param->FUN_00da2b20 and, if it returned a positive count, forwards buffer+1 and count-1 to FindOrAddCallTrace.
// @fnv 0x00da2d20
// src: HAVOK_LIB 0x00da2d20
int Holder::hkStackTracer_CallTree_insertCallStack(ArgObj* param)
{
    int buffer[0x40];
    int count = param->hkStackTracer_getStackTrace(buffer, 0x40);
    if (count > 0)
        return FindOrAddCallTrace(buffer + 1, count - 1);
    return 0;
}

namespace sda3740 {

struct Record
{
    unsigned char m_ucType;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char m_ucSize;
    int m_iKey1;
    int m_iKey2;
};

struct Block
{
    int m_uiLogicalSize;
};

// Searches blocks for a record matching iKey1 and iKey2, sets *ppvData to the record data, and returns the record or null.
// @fnv 0x00da3740
Record* FindRecordByKey(Block*** pppBlocks, int iKey1, int iKey2, void** ppvData)
{
    Block** ppBlock = *pppBlocks;
    Block* pkBlock = *ppBlock;
    Record* pkRecord = (Record*)((char*)pkBlock + 0x10);
    Record* pkEnd = (Record*)((char*)pkBlock + pkBlock->m_uiLogicalSize + 0x10);
    ++ppBlock;
    for (;;)
    {
        void* pvData;
        switch (pkRecord->m_ucType)
        {
        case 0:
            break;
        case 2:
        case 3:
        case 6:
        case 10:
        case 11:
        case 14:
            pvData = (char*)pkRecord + 0x10;
            if (pkRecord->m_iKey2 == iKey2 && pkRecord->m_iKey1 == iKey1)
            {
                *ppvData = pvData;
                return pkRecord;
            }
            break;
        case 4:
        case 5:
        case 12:
        case 13:
            pvData = (char*)pkRecord + 0x20;
            if (pkRecord->m_iKey2 == iKey2 && pkRecord->m_iKey1 == iKey1)
            {
                *ppvData = pvData;
                return pkRecord;
            }
            break;
        case 1:
            return 0;
        default:
            goto check;
        }
        pkRecord = (Record*)((char*)pkRecord + pkRecord->m_ucSize);
    check:
        if (pkRecord >= pkEnd)
        {
            pkBlock = *ppBlock;
            pkRecord = (Record*)((char*)pkBlock + 0x10);
            pkEnd = (Record*)((char*)pkBlock + pkBlock->m_uiLogicalSize + 0x10);
            ++ppBlock;
        }
    }
}

}

void __cdecl hkAgent1nMachine_Destroy(void* a, void* b, void* c, void* d);

// Calls FUN_00da42b0 with arg2, arg5, arg3 and arg4; arg1 is unused.
// @fnv 0x00da6dc0
// src: GUESS 0x00da6dc0 (confidence: medium)
void __cdecl Object_HkAgent1nMachine_Destroy_Thunk(void* aUnused, void* arg2, void* arg3, void* arg4, void* arg5)
{
    hkAgent1nMachine_Destroy(arg2, arg5, arg3, arg4);
}

// @fnv 0x00da82c0
// src: GUESS 0x00da82c0 (confidence: high)
void __cdecl Object_DoNothing_00da82c0()
{}

template <class T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& num)
{
    int bytes = num * (int)sizeof(T);
    T* p = static_cast<T*>(bufAlloc(bytes));
    num = bytes / (int)sizeof(T);
    return p;
}
inline hkMemoryRouter* s06c0_mgr()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
struct S06c0_Key
{
    unsigned int key;
    int index;
};
struct S06c0_Quad
{
    unsigned int x, y, z, w;
};
struct S06c0_Rec
{
    S06c0_Quad first, second;
};
void __cdecl RadixSort(S06c0_Key* keys, int count, S06c0_Key* scratch);

template <class T> __forceinline void s06c0_allocArray(int n, int& capacity, T*& data)
{
    hkMemoryAllocator& a = s06c0_mgr()->temp();
    int num;
    if (n)
    {
        num = n;
        data = a._bufAlloc<T>(num);
    }
    else
    {
        num = 0;
        data = 0;
    }
    capacity = num ? num : 0x80000000;
}
template <class T> __forceinline void s06c0_freeArray(T* data, int capacity)
{
    hkMemoryAllocator& a = s06c0_mgr()->temp();
    if (!(capacity & 0x80000000))
        a.bufFree(data, (capacity & 0x3fffffff) * sizeof(T));
}
inline void s06c0_memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}
inline void s06c0_memCpy16(void* dst, const void* src, int numQuads)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    for (int i = 0; i < numQuads; i++)
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    }
}
// Sorts an array of S06c0_Rec in place by their first.x field using a scratch-key sort and a temporary copy.
// @fnv 0x00db06c0
void __cdecl SortRecordsByKey(S06c0_Rec* records, int count)
{
    int iRoundedCount = (count + 3) & ~3;
    S06c0_Key* keys;
    int keyCapacity;
    s06c0_allocArray(iRoundedCount, keyCapacity, keys);
    for (int i = 0; i < iRoundedCount; ++i)
    {
        keys[i].key = records[i].first.x;
        keys[i].index = i;
    }
    {
        S06c0_Key* scratch;
        int scratchCapacity;
        s06c0_allocArray(iRoundedCount, scratchCapacity, scratch);
        RadixSort(keys, iRoundedCount, scratch);
        s06c0_freeArray(scratch, scratchCapacity);
    }
    S06c0_Rec* sorted;
    int sortedCapacity;
    s06c0_allocArray(count, sortedCapacity, sorted);
    for (int i = 0; i < count; ++i)
        s06c0_memCpy16NonEmpty(&sorted[i], &records[keys[i].index], 2);
    s06c0_memCpy16(records, sorted, (unsigned int)(count * sizeof(S06c0_Rec)) / 16);
    s06c0_freeArray(sorted, sortedCapacity);
    s06c0_freeArray(keys, keyCapacity);
}

struct MaskArg
{
    unsigned int* ptr;
};
// Sets specific bits in the mask word pointed to by mask.ptr based on key and flag.
// @fnv 0x00db0a10
static __declspec(noinline) void SetMaskBits(int key, MaskArg mask, int flag)
{
    unsigned int* __restrict p = mask.ptr;
    int s = key >> 4;
    unsigned int u = (unsigned int)s;
    int x = ~u & 1;
    int y = ~(u >> 1) & 1;
    int z = ~(u >> 2) & 1;
    unsigned int bit;
    if (flag != 0)
    {
        bit = 1u << (2 * (y + 2 * z));
        if (!(*p & (bit * 2)))
            *p += bit;
    }
    if (flag != 1)
    {
        bit = 1u << (2 * (x + 2 * z + 4));
        if (!(*p & (bit * 2)))
            *p += bit;
    }
    if (flag != 2)
    {
        bit = 1u << (2 * (x + 2 * y + 8));
        if (!(*p & (bit * 2)))
            *p += bit;
    }
}

void unit_helper(int key, unsigned int* p, int flag)
{
    MaskArg mask = {p};
    SetMaskBits(key, mask, flag);
}

extern int g_00db0aa0_maskvar;

static __forceinline void db0aa0_addCell(int& mask, int cell)
{
    int bit = 1 << (cell * 2);
    if (!(mask & (bit * 2)))
        mask += bit;
}

// Decodes a packed axis and bit flags from value and sets the corresponding cell bit in mask via db0aa0_addCell.
// @fnv 0x00db0aa0
// src: GUESS 0x00db0aa0 (confidence: medium)
static __declspec(noinline) void Object_SetPackedCellMaskBit(int& mask, int packedValue)
{
    int axis = packedValue & 15;
    unsigned int bits = packedValue >> 4;
    int x = (~bits) & 1;
    int y = (~(bits >> 1)) & 1;
    int z = (~(bits >> 2)) & 1;
    if (axis == 0)
        db0aa0_addCell(mask, y + 2 * z);
    else if (axis == 1)
        db0aa0_addCell(mask, x + 2 * z + 4);
    else
        db0aa0_addCell(mask, x + 2 * y + 8);
}

extern "C" void __cdecl S00db0aa0_Entry(void)
{
    Object_SetPackedCellMaskBit(g_00db0aa0_maskvar, stub_val());
}

namespace fnv_00db0e50 {
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" int _mm_movemask_ps(__m128);

struct VectorFlags
{
    unsigned int value;
};

// Returns the sign bits of the vector's x, y and z shifted left 4, ORed with bit 31 of flags.value moved to bit 3.
// @fnv 0x00db0e50
static __declspec(noinline) unsigned int GetSignMask(const __m128* vector, VectorFlags flags)
{
    unsigned int signs = _mm_movemask_ps(_mm_cmplt_ps(*vector, _mm_setzero_ps()));
    return ((signs & 7) << 4) | ((flags.value >> 28) & 8);
}

extern "C" const __m128* getVector_db0e50();
extern VectorFlags getFlags_db0e50();
volatile unsigned int g_out;
void CallTarget_db0e50()
{
    g_out = GetSignMask(getVector_db0e50(), getFlags_db0e50());
}
}  // namespace fnv_00db0e50

// Finds the index of the largest value among v[0], v[1], v[2], stores it in out, and returns a bitmask flag for the winning component.
// @fnv 0x00db0e80
static __declspec(noinline) unsigned int FindMaxComponent(const float* apValues, int* piIndex)
{
    int idx;
    unsigned int uiFlag;
    if (apValues[0] > apValues[1])
    {
        idx = 0;
        uiFlag = 0x10;
    }
    else
    {
        idx = 1;
        uiFlag = 0x20;
    }
    if (apValues[2] > apValues[idx])
    {
        idx = 2;
        uiFlag = 0x40;
    }
    *piIndex = idx;
    return uiFlag;
}
volatile int g_a;
float* volatile g_v;
int* volatile g_o;
void CallTarget_a()
{
    g_a = FindMaxComponent(g_v, g_o);
}

struct S_00db7c70_class
{
    int unk0c;
    int __thiscall GetB(int a, int b);
    int __thiscall Get0cAddress_00db7c80();
};

// @fnv 0x00db7c70
// src: GUESS 0x00db7c70 (confidence: low)
int __thiscall S_00db7c70_class::GetB(int a, int b)
{
    return b;
}

// src: GUESS 0x00db7c80 (confidence: low)
int __thiscall S_00db7c70_class::Get0cAddress_00db7c80()
{
    return unk0c;
}

struct DBBCBC0Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    int NiRenderTargetGroup_GetRendererData();
};

// @fnv 0x00dbbc00
// src: COMMUNITY 0x00dbbc00
int DBBCBC0Target::NiRenderTargetGroup_GetRendererData()
{
    return unk24;
}

namespace fnv_00da2840 {
extern char* DAT_011b76d0;
extern void*(__stdcall* DAT_00fdf0b0)(const char*);
extern void*(__stdcall* DAT_00fdf0ac)(void*, const char*);
extern void(__stdcall* DAT_00fdf16c)(const char*);
extern HANDLE(__stdcall* DAT_00fdf110)(int, int);

extern char str_010d4da0[];
extern char str_010d4d90[];
extern char str_010d4d78[];
extern char str_010d4cf8[];
extern char str_010d4ce4[];
extern char str_010d4cd4[];
extern char str_010d4cc0[];
extern char str_010d4cb4[];
extern char str_010d4c98[];
extern char str_010d4c84[];
extern char str_010d4c6c[];
extern char str_010d4c60[];

typedef void(__stdcall* DA2840_OutputDebugString)(const char*);
typedef void*(__stdcall* DA2840_GetProcAddress)(void*, const char*);
typedef int(__stdcall* DA2840_SymInitialize)(HANDLE);
typedef int(__stdcall* DA2840_SymRefreshModuleList)(void);
typedef DWORD(__stdcall* DA2840_SymGetOptions)(void);
typedef DWORD(__stdcall* DA2840_SymSetOptions)(DWORD);
typedef void*(__stdcall* DA2840_SymGetSymFromAddr)(void*, void*, void*);
typedef int(__stdcall* DA2840_StackWalk64)(void*, void*, void*, void*, void*, void*, void*, void*);
typedef void*(__stdcall* DA2840_SymFunctionTableAccess64)(void*, void*, void*);
typedef void*(__stdcall* DA2840_SymGetModuleBase64)(void*, void*);
typedef int(__stdcall* DA2840_SymGetLineFromAddr64)(void*, void*, void*, void*);
typedef BOOL(__stdcall* DA2840_SymCleanup)(void*);

struct DA2840Object
{
    HMODULE m_module;
    int m_sState;
    DA2840_SymInitialize m_symInitialize;
    DA2840_SymRefreshModuleList m_symRefreshModuleList;
    DA2840_SymGetOptions m_symGetOptions;
    DA2840_SymSetOptions m_symSetOptions;
    DA2840_SymGetSymFromAddr m_symGetSymFromAddr;
    DA2840_StackWalk64 m_stackWalk64;
    DA2840_SymFunctionTableAccess64 m_symFunctionTableAccess64;
    DA2840_SymGetModuleBase64 m_symGetModuleBase64;
    DA2840_SymGetLineFromAddr64 m_symGetLineFromAddr64;
    DA2840_SymCleanup m_symCleanup;

    void hkStackTracerWin32Data_init();
};

// @fnv 0x00da2840
// src: HAVOK_LIB 0x00da2840
void DA2840Object::hkStackTracerWin32Data_init()
{
    HMODULE module = (HMODULE)DAT_00fdf0b0(DAT_011b76d0);
    DA2840_OutputDebugString outputDebugString = DAT_00fdf16c;
    m_module = module;

    if (!module)
    {
        outputDebugString(str_010d4da0);
        if (!m_module)
            return;
    }

    DA2840_GetProcAddress getProcAddress = DAT_00fdf0ac;

    m_sState = 1;

    m_symInitialize = (DA2840_SymInitialize)getProcAddress(m_module, str_010d4d90);
    m_symRefreshModuleList = (DA2840_SymRefreshModuleList)getProcAddress(m_module, str_010d4d78);

    if (!m_symRefreshModuleList)
        outputDebugString(str_010d4cf8);

    m_symGetOptions = (DA2840_SymGetOptions)getProcAddress(m_module, str_010d4ce4);
    m_symSetOptions = (DA2840_SymSetOptions)getProcAddress(m_module, str_010d4cd4);
    m_symGetSymFromAddr = (DA2840_SymGetSymFromAddr)getProcAddress(m_module, str_010d4cc0);
    m_stackWalk64 = (DA2840_StackWalk64)getProcAddress(m_module, str_010d4cb4);
    m_symFunctionTableAccess64 = (DA2840_SymFunctionTableAccess64)getProcAddress(m_module, str_010d4c98);
    m_symGetModuleBase64 = (DA2840_SymGetModuleBase64)getProcAddress(m_module, str_010d4c84);
    m_symGetLineFromAddr64 = (DA2840_SymGetLineFromAddr64)getProcAddress(m_module, str_010d4c6c);
    m_symCleanup = (DA2840_SymCleanup)getProcAddress(m_module, str_010d4c60);

    m_symSetOptions(m_symGetOptions() | 0x80000010);
    m_symInitialize(DAT_00fdf110(0, 1));
}
}  // namespace fnv_00da2840

struct S00da6eb0_Entry
{
    const char* m_pName;
    unsigned int m_uiEventId;
    unsigned int unk08;
};

struct S00da6eb0_Buf
{
    unsigned int unk00;
    S00da6eb0_Entry* m_pCur;
    unsigned int unk08;
    S00da6eb0_Entry* m_pRecordEnd;
};

struct S00da6eb0_Head
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct S00da6eb0_Sub
{
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    int m_uiSize;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int m_uiHash[32];
};

struct S00da6eb0_List : S00da6eb0_Head, S00da6eb0_Sub
{
};

struct S00da6eb0_Router
{
    S00da6eb0_List* m_pEntries;
};

struct S00da6eb0_Ctx
{
    unsigned int unk00;
    S00da6eb0_Router* m_pRouter;
};

extern unsigned long DAT_0126835c;
extern char str_010d50b8[];
extern char str_010c41f8[];

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

void __cdecl hkAgent1nMachine_Process(void* a, void* b, S00da6eb0_Sub* c, unsigned int* d, void* e);

inline void S00da6eb0_TimerMark(const char* pName)
{
    S00da6eb0_Buf* pBuf = static_cast<S00da6eb0_Buf*>(TlsGetValue(DAT_0126835c));
    S00da6eb0_Entry* pCur = pBuf->m_pCur;

    if (pCur < pBuf->m_pRecordEnd)
    {
        pCur->m_pName = pName;
        _ReadWriteBarrier();
        volatile unsigned int t = __rdtsc();
        pCur->m_uiEventId = t;
        ++pCur;
        pBuf->m_pCur = pCur;
    }
}

inline void* S00da6eb0_ListData(S00da6eb0_List* pList)
{
    return &pList->unk10;
}

// Builds an index array from set bits in the router's hash table, passes it to FUN_00da4aa0, and returns an offset from a3.
// @fnv 0x00da6eb0
void* __cdecl BuildEventIndex(void* apCtx, void* apUnused, void* apOut, void* apUnused2, void* a5)
{
    S00da6eb0_TimerMark(str_010d50b8);

    S00da6eb0_List* pList = static_cast<S00da6eb0_Ctx*>(apCtx)->m_pRouter->m_pEntries;
    int iSize = pList->m_uiSize;

    hkMemoryRouter* pAlloc = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    unsigned int* pEventIndex = reinterpret_cast<unsigned int*>(pAlloc->m_stack.m_next.m_storage);

    pAlloc->m_stack.m_next.m_storage = (char*)pAlloc->m_stack.m_next.m_storage + ((iSize * 4 + 0x83) & 0xffffff80);

    unsigned int iIndexCount = 0;
    unsigned int uiBitMask = 1;

    for (unsigned int i = 0; (int)i < iSize; ++i)
    {
        unsigned int uiBit = (i < 256) ? (pList->m_uiHash[i >> 5] & uiBitMask) : 1;

        if (uiBit)
            pEventIndex[iIndexCount++] = i;

        uiBitMask = _rotl(uiBitMask, 1);
    }

    pEventIndex[iIndexCount] = 0xffffffff;

    hkAgent1nMachine_Process(apOut, apCtx, pList, pEventIndex, a5);

    S00da6eb0_TimerMark(str_010c41f8);

    reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->m_stack.m_next.m_storage = (void*)(reinterpret_cast<int>(pEventIndex));

    return reinterpret_cast<char*>(apOut) + 0x10;
}

namespace CleanSimd {
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float lane[4];
    unsigned int bits[4];
} __m128, LocalM128;
extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    int _mm_movemask_ps(__m128);
}

extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
extern __m128 DAT_010c44d0;

// Keep the original inline SIMD operations and intrinsic type on shared hkVector4 storage.
static __forceinline __m128& packet(hkVector4& v) { return reinterpret_cast<__m128&>(v.m_vComponents); }
static __forceinline const __m128& packet(const hkVector4& v) { return reinterpret_cast<const __m128&>(v.m_vComponents); }
__forceinline void vectorNegate(hkVector4& out, const hkVector4& a)
{
    packet(out) = _mm_xor_ps(packet(a), DAT_010c44d0);
}
__forceinline void vectorSub(hkVector4& out, const hkVector4& a, const hkVector4& b)
{
    packet(out) = _mm_sub_ps(packet(a), packet(b));
}
__forceinline void vectorCross(hkVector4& out, const hkVector4& a, const hkVector4& b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(packet(a), packet(a), 0xc9), _mm_shuffle_ps(packet(b), packet(b), 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(packet(a), packet(a), 0xd2), _mm_shuffle_ps(packet(b), packet(b), 0xc9));
    packet(out) = _mm_sub_ps(first, second);
}
__forceinline __m128 vectorDot(const hkVector4& out, const hkVector4& a)
{
    __m128 sq = _mm_mul_ps(packet(out), packet(a));
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xy);
}
__forceinline void vectorNormalize(hkVector4& out)
{
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 len = vectorDot(out, out);
    __m128 eq = _mm_cmpeq_ss(len, zero);
    __m128 rs = _mm_rsqrt_ss(len);
    __m128 refine = _mm_mul_ss(_mm_mul_ss(half, rs), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, rs), rs)));
    __m128 inv = _mm_andnot_ps(eq, refine);
    packet(out) = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), packet(out));
}
__forceinline void vectorAddMul(hkVector4& out, const hkVector4& a, __m128 scale, const hkVector4& b)
{
    packet(out) = _mm_add_ps(packet(a), _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), packet(b)));
}

struct Indices
{
    unsigned int flags;
    unsigned char b, c, d, a;
};
struct Output
{
    hkVector4 origin, direction, normal;
};
struct VertexBlock
{
    hkVector4 vertices[16];
    hkVector4 direction;
};
inline __forceinline void fourDots(const hkVector4& n, const hkVector4& a, const hkVector4& b, const hkVector4& c, const hkVector4& d,
                                   hkVector4& out)
{
    __m128 x = _mm_mul_ps(packet(a), packet(n));
    __m128 y = _mm_mul_ps(packet(b), packet(n));
    __m128 z = _mm_mul_ps(packet(c), packet(n));
    __m128 w = _mm_mul_ps(packet(d), packet(n));
    __m128 xylo = _mm_shuffle_ps(x, y, 0x44);
    __m128 xyhi = _mm_shuffle_ps(x, y, 0xee);
    __m128 zwlo = _mm_shuffle_ps(z, w, 0x44);
    __m128 zwhi = _mm_shuffle_ps(z, w, 0xee);
    __m128 r0 = _mm_shuffle_ps(xylo, zwlo, 0x88);
    __m128 r1 = _mm_shuffle_ps(xylo, zwlo, 0xdd);
    __m128 r2 = _mm_shuffle_ps(xyhi, zwhi, 0x88);
    packet(out) = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
// Builds out origin, direction and normal from four vertices at idx offsets in base, negating the normal if the fourth dot is negative; returns ~mask & 7.
// @fnv 0x00dad110
// src: GUESS 0x00dad110 (confidence: low)
static __declspec(noinline) int hkVector4_UpdateState_00dad110(const Indices* idx, const char* apVertexBlock, Output* out)
{
    const hkVector4* pVertexB = (const hkVector4*)(apVertexBlock + idx->b);
    const hkVector4* pVertexC = (const hkVector4*)(apVertexBlock + idx->c);
    const hkVector4* pVertexD = (const hkVector4*)(apVertexBlock + idx->d);
    const hkVector4* pVertexA = (const hkVector4*)(apVertexBlock + idx->a);
    packet(out->origin) = packet(*pVertexA);
    vectorSub(out->direction, *pVertexB, *pVertexA);
    hkVector4 vEdge0, e1, e2;
    vectorSub(vEdge0, *pVertexD, *pVertexC);
    vectorSub(e1, *pVertexB, *pVertexD);
    vectorSub(e2, *pVertexC, *pVertexB);
    hkVector4 normal;
    vectorCross(normal, vEdge0, e1);
    vectorNormalize(normal);
    hkVector4 a0, a1, a2;
    vectorSub(a0, *pVertexA, *pVertexC);
    vectorSub(a1, *pVertexA, *pVertexD);
    vectorSub(a2, *pVertexA, *pVertexB);
    hkVector4 pt0, pt1, pt2;
    vectorCross(pt0, a0, vEdge0);
    vectorCross(pt1, a1, e1);
    vectorCross(pt2, a2, e2);
    hkVector4 dots;
    fourDots(normal, pt0, pt1, pt2, ((const VertexBlock*)apVertexBlock)->direction, dots);
    __m128 dist = vectorDot(out->direction, normal);
    vectorAddMul(out->origin, *pVertexA, dist, normal);
    packet(out->normal) = packet(normal);
    int mask = _mm_movemask_ps(_mm_cmplt_ps(packet(dots), _mm_setzero_ps()));
    if (mask & 8)
        vectorNegate(out->normal, normal);
    return ~mask & 7;
}
const Indices* volatile inputIndices;
const char* volatile inputBase;
Output* volatile inputOutput;
volatile int g_iFunctionResult;
void caller_dad110()
{
    g_iFunctionResult = hkVector4_UpdateState_00dad110(inputIndices, inputBase, inputOutput);
}
}


// @fnv 0x00da8340
// src: GUESS 0x00da8340 (confidence: high)
void __cdecl Object_DoNothing_00da8340()
{}

namespace N {
extern "C" void _ReadWriteBarrier();
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    int _mm_movemask_ps(__m128);
}
extern const __m128 DAT_010c44d0;
class Scalar
{
    __m128 data;

  public:
    __forceinline Scalar(__m128 x) : data(x)
    {}
    __forceinline __m128 get() const
    {
        return data;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(data, data, 0);
    }
};
// hkVector4 of the GSK vertex rows (16 vertices + separating normal) with the unit's own inline SIMD forms (setSub4, setCross, normalize3, setNeg4).
class GskVector4
{
    __m128 data;

  public:
    __forceinline operator __m128() const
    {
        return data;
    }
    __forceinline void operator=(const GskVector4& x)
    {
        data = x.data;
    }
    __forceinline void operator=(const __m128& x)
    {
        data = x;
    }
    __forceinline void difference(const GskVector4& a, const GskVector4& b)
    {
        data = _mm_sub_ps(a.data, b.data);
    }
    __forceinline void cross(const GskVector4& a, const GskVector4& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 201), _mm_shuffle_ps(b.data, b.data, 210));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.data, a.data, 210), _mm_shuffle_ps(b.data, b.data, 201));
        data = _mm_sub_ps(p, q);
    }
    __forceinline Scalar squared() const
    {
        __m128 q = _mm_mul_ps(data, data);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(q, q, 85), q);
        return _mm_add_ss(_mm_shuffle_ps(q, q, 170), y);
    }
    __forceinline Scalar inverseLength() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        __m128 len = squared().get();
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 square = _mm_mul_ss(_mm_mul_ss(len, approx), approx);
        __m128 refine = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, square));
        return _mm_andnot_ps(eq, refine);
    }
    __forceinline void normalize()
    {
        data = _mm_mul_ps(inverseLength().splat(), data);
    }
    __forceinline void negate(const GskVector4& v)
    {
        data = _mm_xor_ps(v.data, DAT_010c44d0);
    }
};
struct Desc
{
    unsigned char dimA, dimB;
    unsigned short id;
    unsigned char offsets[4];
};
struct Rows
{
    GskVector4 vertices[16];
    GskVector4 separating;
};
struct Out
{
    GskVector4 point, delta, normal;
};
static __forceinline const GskVector4& vertex(const Rows* p, int offset)
{
    return *(const GskVector4*)((const char*)p->vertices + offset);
}
static __forceinline __m128 fourDots(const GskVector4& a, const GskVector4& b, const GskVector4& c, const GskVector4& d, const GskVector4& n)
{
    __m128 p = _mm_mul_ps(a, n), q = _mm_mul_ps(b, n), r = _mm_mul_ps(c, n), s = _mm_mul_ps(d, n);
    __m128 pq = _mm_shuffle_ps(p, q, 68), rs = _mm_shuffle_ps(r, s, 68);
    __m128 x = _mm_shuffle_ps(pq, rs, 136), y = _mm_shuffle_ps(pq, rs, 221);
    __m128 z = _mm_shuffle_ps(_mm_shuffle_ps(p, q, 238), _mm_shuffle_ps(r, s, 238), 136);
    return _mm_add_ps(z, _mm_add_ps(y, x));
}
}
// @fnv 0x00dacf10
// src: GUESS 0x00dacf10 (confidence: low)
static __declspec(noinline) int Runtime_UpdateState_00dacf10(const N::Rows* rows, const N::Desc* desc, N::Out* out)
{
    const N::GskVector4& a = N::vertex(rows, desc->offsets[0]);
    const N::GskVector4& b = N::vertex(rows, desc->offsets[1]);
    const N::GskVector4& c = N::vertex(rows, desc->offsets[2]);
    const N::GskVector4& d = N::vertex(rows, desc->offsets[3]);
    out->point = a;
    out->delta.difference(a, b);
    N::GskVector4 u, v, w, n;
    u.difference(d, c);
    v.difference(b, d);
    w.difference(c, b);
    n.cross(u, v);
    n.normalize();
    N::GskVector4 ac, ad, ab, p, q, r;
    ac.difference(a, c);
    ad.difference(a, d);
    ab.difference(a, b);
    p.cross(ac, u);
    q.cross(ad, v);
    r.cross(ab, w);
    N::__m128 dots = N::fourDots(p, q, r, rows->separating, n);
    unsigned mask = N::_mm_movemask_ps(N::_mm_cmplt_ps(dots, N::_mm_setzero_ps()));
    out->normal = n;
    if (mask & 8)
        out->normal.negate(n);
    return ~mask & 7;
}
N::Rows* g_rows;
N::Desc* g_desc;
N::Out* g_output;
volatile int g_sink;
void callPlane()
{
    g_sink = Runtime_UpdateState_00dacf10(g_rows, g_desc, g_output);
}

#include <xmmintrin.h>
namespace fnv_00db47a0 {
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" float _mm_cvtss_f32(__m128);

struct S00db47a0_Obj
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    float unk74;
    float unk78;
    float unk7C;
    float unk80;
    float unk84;
    float unk88;
    float unk8C;
    float unk90;
    float unk94;
    float unk98;
    float unk9C;
    float unkA0;
};

struct SmallReal
{
    __m128 value;
    SmallReal(__m128 v) : value(v)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};
struct SmallVec
{
    __m128 value;
    void cross(const SmallVec& x, const SmallVec& y)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(x.value, x.value, 0xc9), _mm_shuffle_ps(y.value, y.value, 0xd2));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(x.value, x.value, 0xd2), _mm_shuffle_ps(y.value, y.value, 0xc9));
        value = _mm_sub_ps(p, q);
    }
    SmallReal dot(const SmallVec& y) const
    {
        __m128 p = _mm_mul_ps(value, y.value);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return SmallReal(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    }
    SmallReal length() const
    {
        return SmallReal(_mm_sqrt_ss(dot(*this).value));
    }
};
struct S00db47a0_Pair
{
    SmallVec b, d;
};
struct S00db47a0_Cls
{
    SmallVec a;
};
// Computes weighted cross product lengths of pr->b and pr->d with self->a, stores their sum in out1 and the dot product of self->a with q in out2.
// @fnv 0x00db47a0
// src: GUESS 0x00db47a0 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00db47a0(S00db47a0_Cls* self, S00db47a0_Pair* apPair, S00db47a0_Obj* apObjA,
                                              S00db47a0_Obj* apObjB, const SmallVec* apVec, float* apOutDot,
                                              float* apOutSum)
{
    SmallVec crossA, crossB;
    crossA.cross(apPair->b, self->a);
    crossB.cross(apPair->d, self->a);
    float first = apObjA->unkA0 * float(crossA.length());
    float second = apObjB->unkA0 * float(crossB.length());
    *apOutSum = first + second;
    *apOutDot = self->a.dot(*apVec);
}

extern "C" S00db47a0_Pair* pair_input();
S00db47a0_Cls* volatile g_self;
S00db47a0_Obj* volatile g_o;
S00db47a0_Obj* volatile g_p;
const SmallVec* volatile g_q;
float* volatile g_out2;
float* volatile g_out1;
void drive()
{
    Object_UpdateFields_00db47a0(g_self, pair_input(), g_o, g_p, g_q, g_out2, g_out1);
}
}  // namespace fnv_00db47a0

#include <xmmintrin.h>
namespace fnv_00db48a0 {
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);

union __declspec(align(16)) SlabVec
{
    __m128 v;
    float f[4];
};
struct __declspec(align(16)) SlabObj
{
    __m128 v00;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    SlabVec v40;
    SlabVec v50;
};

struct __declspec(align(16)) VecHolder
{
    __m128 v00;
};

extern const __m128 DAT_010ec7f0;
extern const __m128 DAT_010c44d0;

struct SlabMath
{
    union
    {
        __m128 q;
        __m128 m_vComponents;
        float lane[4];
    };
    SlabMath()
    {}
    SlabMath(__m128 v) : q(v)
    {}
    SlabMath(float v) : q(_mm_set_ps1(v))
    {}
    __forceinline void sub(const SlabMath& a, const SlabMath& b)
    {
        q = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add(const SlabMath& a, const SlabMath& b)
    {
        q = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul(const SlabMath& a, const SlabMath& b)
    {
        q = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void cross(const SlabMath& a, const SlabMath& b)
    {
        __m128 bc = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xC9);
        __m128 ad = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xD2);
        __m128 bd = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xD2);
        __m128 ac = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xC9);
        q = _mm_sub_ps(_mm_mul_ps(ad, bc), _mm_mul_ps(ac, bd));
    }
    __forceinline void interpolate(const SlabObj* a, const SlabMath& t)
    {
        q = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t.q), a->v40.v), _mm_mul_ps(a->v50.v, t.q));
    }
    __forceinline SlabMath operator-(const SlabMath& b) const
    {
        return SlabMath(_mm_sub_ps(q, b.m_vComponents));
    }
    __forceinline SlabMath operator+(const SlabMath& b) const
    {
        return SlabMath(_mm_add_ps(q, b.m_vComponents));
    }
    __forceinline SlabMath operator*(const SlabMath& b) const
    {
        return SlabMath(_mm_mul_ps(q, b.m_vComponents));
    }
};
struct W_a
{
    const SlabObj* p;
    W_a(const SlabObj* v) : p(v)
    {}
};
struct W_b
{
    const VecHolder* p;
    W_b(const VecHolder* v) : p(v)
    {}
};
struct W_c
{
    const SlabObj* p;
    W_c(const SlabObj* v) : p(v)
    {}
};

// Returns dot(b, cross(pv-LA, pe[0]) - c - cross(pv-LC, pe[1])), where LA and LC interpolate a's and q's v40/v50 at times derived from d.
// @fnv 0x00db48a0
// src: GUESS 0x00db48a0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00db48a0(const VecHolder* pv, const VecHolder* pe, const SlabObj* q, W_a a, W_b b,
                                               W_c c, float d)
{
    float t0 = (d - a.p->v40.f[3]) * a.p->v50.f[3];
    SlabMath v(pv->v00);
    SlabMath T0(t0);
    SlabMath vInterpA;
    vInterpA.interpolate(a.p, T0);
    SlabMath A;
    A.sub(v, vInterpA);

    float t1 = (d - q->v40.f[3]) * q->v50.f[3];
    SlabMath T1(t1);
    SlabMath vInterpC;
    vInterpC.interpolate(q, T1);
    SlabMath C;
    C.sub(v, vInterpC);

    SlabMath e1(pe[0].v00), r1;
    r1.cross(A, e1);
    SlabMath e2(pe[1].v00), r2;
    r2.cross(C, e2);
    SlabMath vNegC(_mm_xor_ps(c.p->v00, DAT_010c44d0));
    SlabMath r, delta, dot;
    r.add(r1, vNegC);
    delta.sub(r, r2);
    dot.mul(delta, SlabMath(b.p->v00));
    __m128 h = _mm_add_ss(_mm_shuffle_ps(dot.q, dot.q, 0x55), dot.q);
    h = _mm_add_ss(_mm_shuffle_ps(dot.q, dot.q, 0xAA), h);
    float out;
    _mm_store_ss(&out, h);
    return out;
}

const VecHolder* volatile in_v;
const VecHolder* volatile in_e;
const SlabObj* volatile in_q;
const SlabObj* volatile in_a;
const VecHolder* volatile in_b;
const SlabObj* volatile in_c;
float volatile in_d;
float volatile result;
void drive_slab()
{
    result = Object_ProcessAndReturnValue_00db48a0(in_v, in_e, in_q, W_a(in_a), W_b(in_b), W_c(in_c), in_d);
}
}  // namespace fnv_00db48a0

extern int DAT_010d4de4;

extern int DAT_0102e388;

struct StackTraceModule
{

    HMODULE hModule;

    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;

    void(__stdcall* releaseProcess)(void*);
};

struct StackTraceOwner
{

    void* vtable;

    int unk04;

    StackTraceModule* loader;

    void ReleaseStackTraceModule();
};

// Sets the vtable and, if loader->hModule is set, calls releaseProcess(GetCurrentProcess()), zeroes the loader fields, frees the library and clears hModule.
// @fnv 0x00da2930
// src: GUESS 0x00da2930 (confidence: medium)
void StackTraceOwner::ReleaseStackTraceModule()
{

    StackTraceModule* p = loader;

    vtable = &DAT_010d4de4;

    if (p->hModule)
    {

        p->releaseProcess(GetCurrentProcess());

        HMODULE module = p->hModule;

        p->unk08 = 0;
        p->unk0c = 0;
        p->unk10 = 0;
        p->unk14 = 0;
        p->unk18 = 0;

        p->unk1c = 0;
        p->unk20 = 0;
        p->unk24 = 0;
        p->unk28 = 0;

        p->releaseProcess = 0;

        FreeLibrary(module);

        p->hModule = 0;
    }

    vtable = &DAT_0102e388;
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    A::destroy(*this);
}
