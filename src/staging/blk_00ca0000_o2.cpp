#include "../../include/NiTLargeArray.h"
#include "../../include/NiTArray.h"
#include "../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// SSE_DECLARATIONS_DEFER_TO_SDK
#include <windows.h>
// src/staging/blk_00ca0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

// Keep the legacy support templates distinct from the shared scene graph templates.
#include "../../include/layout_support.h"
#include "../../include/MemoryManager.h"
#include "../../include/AutoMemContext.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiPointer.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"

// 0x00c85750 returns the router; its heap allocator is at +0x10,
// unlike hkThreadMemory, which derives from hkMemoryAllocator.
__forceinline hkMemoryAllocator& GetRouterHeap(hkMemoryRouter* router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
}

// Both former context guards used this same TLS memory-context word.
extern __declspec(thread) unsigned int t_uiMemContextC5E0;
__forceinline AutoMemContext::AutoMemContext(int context)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(t_uiMemContextC5E0);
    t_uiMemContextC5E0 = context;
}
__forceinline AutoMemContext::~AutoMemContext()
{
    t_uiMemContextC5E0 = m_eMemoryContext;
}

__forceinline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}

// BaseCinfo_blk_00ca0000_o2: local type (was include/BaseCinfo.h, which had no evidence of one real class); no method of it is bound to a named game function
#include <stddef.h>

class NiStream;

class BaseCinfo_blk_00ca0000_o2
{
public:
    unsigned int unk00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;

    static void* operator new(size_t size) throw();
    static void operator delete(void*);

    __forceinline BaseCinfo_blk_00ca0000_o2()
        : m_iWordAt04(0), m_8(1), m_iThirdValue(0), m_10(0)
    {}

    void v00();
    void v04();
    void LoadBinary(NiStream& kStream);
};
#include "../../include/LandTextureParameters.h"
#include "../../include/NiRTTI.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/CA0E60Array.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
// Keep this unit's existing SIMD type; the SDK's unused inline MMX helpers
// change VC9's register calling conventions for the static string helpers.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00cb0ad0 FUN_00cb0ad0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#endif
#include "../../include/hkVector4.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiGlobalStringTable.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiStream.h"
#include "../../include/NiTMapBase.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTriStrips.h"
#include "../../include/NiTriStripsData.h"
#include "../../include/StrArr.h"
#include "../../include/bhkRagdollTemplateData.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkSerializable.h"
#include "../../include/bhkCharacterPointCollector.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/bhkNiTriStripsShape.h"
#include "../../include/hkBool.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/bhkCapsuleShape.h"
#include "../../include/bhkConstraint.h"
#include "../../include/bhkPackedNiTriStripsShape.h"
#include "../../include/hkpShapePhantom.h"


__forceinline void** CA0E60Array::Allocate(unsigned int count)
{
    return ((void**(__thiscall*)(CA0E60Array*, unsigned int))(*(void***)this)[1])(this, count);
}

__forceinline void CA0E60Array::Free(void** buffer)
{
    ((void(__thiscall*)(CA0E60Array*, void**))(*(void***)this)[2])(this, buffer);
}


void __cdecl ReleaseStorage_00ca3570(void);

void __cdecl _delete(void* p, int);

struct FUN_00ca3980_class
{
    FUN_00ca3980_class* __thiscall FUN_00ca3980(int);
};

// Calls FUN_00ca3570, then if bit 0 of a is set frees this with size 0x30, and returns this.
// @fnv 0x00ca3980
FUN_00ca3980_class* __thiscall FUN_00ca3980_class::FUN_00ca3980(int aiFlags)
{
    ReleaseStorage_00ca3570();
    if (aiFlags & 1)
        _delete(this, 0x30);
    return this;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c759c;

struct FUN_00ca4470_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall UpdateState_00ca4470();
};

// @fnv 0x00ca4470
// src: GUESS 0x00ca4470 (confidence: low)
void __thiscall FUN_00ca4470_Class::UpdateState_00ca4470()
{
    void* p = m_iWordAt04;
    m_iWordAt00 = &DAT_010c759c;
    NiFreeAlias(p);
}

struct FUN_00ca5310_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    void* m_p;
};

// Returns element 0x24 of the float array at m_p when a and m_p are non-null, otherwise 1.0f.
// @fnv 0x00ca5310
float __fastcall GetField24Float(struct FUN_00ca5310_class* pClass)
{
    float result;
    if (pClass && pClass->m_p)
        result = ((float*)pClass->m_p)[0x24];
    else
        result = 1.0f;
    return result;
}

struct FUN_00ca6590_t
{
    int __thiscall ProcessState_00ca6590();
    FUN_00ca6590_t* __thiscall FUN_00ca6650(int flags);
};
void __cdecl _delete(void* p, unsigned int size);

// Calls FUN_00ca6590, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00ca6650
FUN_00ca6590_t* __thiscall FUN_00ca6590_t::FUN_00ca6650(int flags)
{
    ProcessState_00ca6590();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_00ca9840_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void SetFieldValue(float v);
};

// @fnv 0x00ca9840
void FUN_00ca9840_Class::SetFieldValue(float afValue)
{
    if (m_iWordAt04)
        *(float*)((char*)m_iWordAt04 + 0x1c) = afValue;
}

extern int DAT_010c8288;

struct FUN_00ca9a80
{
    int a, b, c, d, e;
    FUN_00ca9a80();
};

// @fnv 0x00ca9a80
FUN_00ca9a80::FUN_00ca9a80()
{
    b = 0;
    c = 1;
    d = 0;
    e = 0;
    a = (int)&DAT_010c8288;
}

extern "C" int __cdecl hkString_strLen(int);

struct FUN_00cb0a80_class
{
    int __thiscall hkStringPtr_getLength();
};

// @fnv 0x00cb0a80
// src: XBOX_PDB 0x00cb0a80
int __thiscall FUN_00cb0a80_class::hkStringPtr_getLength()
{
    int v = *(int*)this;
    v &= 0xfffffffe;
    if (v)
        return hkString_strLen(v);
    return 0;
}

// @fnv 0x00cb0f10
char ToUpperAscii(char acChar)
{
    char r = acChar;
    if (acChar >= 'a' && acChar <= 'z')
        r = acChar - 0x20;
    return r;
}

// @fnv 0x00cb0f30
char ToLowerAscii(char acChar)
{
    if (acChar >= 'A' && acChar <= 'Z')
        acChar += ' ';
    return acChar;
}

void __cdecl FUN_00cc9640();
extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00cb9b60_class
{
    FUN_00cb9b60_class* DestroyIfFlagged(int flag);
};

// Calls FUN_00cc9640, deletes this with size 0x10 when flag has bit 0 set, and returns this.
// @fnv 0x00cb9b60
FUN_00cb9b60_class* FUN_00cb9b60_class::DestroyIfFlagged(int aiFlags)
{
    FUN_00cc9640();
    if (aiFlags & 1)
        operator delete(this, 0x10);
    return this;
}

namespace fnv_00cbc720 {

extern void* NiFreeAlias(void*);

}  // namespace fnv_00cbc720

class bhkLiquidAction;
typedef NiTMapBase<DFALL<NiTMapItem<NiAVObject*, BSSimpleList<bhkLiquidAction*>*> >,
    NiAVObject*, BSSimpleList<bhkLiquidAction*>*> LiquidActionMapBase;

// @fnv 0x00cbc720
template <>
LiquidActionMapBase::~NiTMapBase()
{
    RemoveAll();
    fnv_00cbc720::NiFreeAlias(m_ppkHashTable);
}

struct FUN_00cbc8f0_cls
{
    void hkpSimpleContactConstraintData_getContactPointIdAt(int arg);
};

// Scans the byte buffer at this+0xc backwards from this+0x10-1 and stops at the last index whose byte equals arg.
// @fnv 0x00cbc8f0
// src: HAVOK_LIB 0x00cbc8f0
void FUN_00cbc8f0_cls::hkpSimpleContactConstraintData_getContactPointIdAt(int aiValue)
{
    int count = *(int*)((char*)this + 0x10) - 1;
    if (count >= 0)
    {
        const unsigned char* data = (const unsigned char*)(*(int*)((char*)this + 0xc));
        int val;
        do
        {
            val = data[count];
            if (val == aiValue)
                break;
            --count;
        } while (count >= 0);
    }
}

struct GlobalObject_0045cfe0
{
    GlobalObject_0045cfe0(const char* name, int flags);
    void* m_vtbl;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
};

struct FUN_00cbf400_class : GlobalObject_0045cfe0
{
    FUN_00cbf400_class();
};

// Constructs the "iNumThreads:HAVOK" setting object with flags 1 and zeroes its four trailing fields.
// @fnv 0x00cbf400
FUN_00cbf400_class::FUN_00cbf400_class() : GlobalObject_0045cfe0("iNumThreads:HAVOK", 1)
{
    m_iThirdValue = 0;
    m_iFourthElementInteger = 0;
    m_usTrailingValue = 0;
    m_f = 0;
}

extern int DAT_010c7310;
struct FUN_00ca0d40_class
{
    void __thiscall UpdateFields_00ca0d40();
};
// Sets the vtable pointer to DAT_010c7310 and, if the pointer at offset 4 is set, calls the function at DAT_010c7310+8 on it and clears offsets 4, 8 and 12.
// @fnv 0x00ca0d40
// src: GUESS 0x00ca0d40 (confidence: low)
void __thiscall FUN_00ca0d40_class::UpdateFields_00ca0d40()
{
    void* p = *(void**)((char*)this + 4);
    *(void**)((char*)this + 0) = &DAT_010c7310;
    if (p)
    {
        ((void(__stdcall*)(void*)) * (void**)((char*)&DAT_010c7310 + 8))(p);
        *(int**)((char*)this + 4) = 0;
        *(int**)((char*)this + 12) = 0;
        *(int**)((char*)this + 8) = 0;
    }
}

void __cdecl FUN_00ca4490();
extern MemoryManager _g_memoryManager;
struct FUN_00ca4a90_Class
{
    FUN_00ca4a90_Class* __thiscall FUN_00ca4a90(int flags);
};
// Calls FUN_00ca4490, then if flags bit 0 is set and this is non-null, deallocates the block preceding this via _g_memoryManager, and returns this.
// @fnv 0x00ca4a90
FUN_00ca4a90_Class* __thiscall FUN_00ca4a90_Class::FUN_00ca4a90(int flags)
{
    FUN_00ca4490();
    if ((flags & 1) && this)
        _g_memoryManager.Deallocate((char*)this - *(unsigned char*)((char*)this - 1));
    return this;
}



extern int DAT_01030a24;
extern int DAT_01030b0c;
extern int DAT_01030bf4;
extern int DAT_01066e2c;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268324;

// @fnv 0x00caad90
int __thiscall bhkCapsuleShape::InitializeCapsuleShape()
{
    Initialize();
    m_0c = 0;
    m_10 = 0;
    *reinterpret_cast<int**>(this) = &DAT_01030bf4;
    ++DAT_012680f8;
    *reinterpret_cast<int**>(this) = &DAT_01030b0c;
    ++DAT_01268274;
    *reinterpret_cast<int**>(this) = &DAT_01030a24;
    ++DAT_01268250;
    *reinterpret_cast<int**>(this) = &DAT_01066e2c;
    ++DAT_01268324;
    return (int)this;
}

namespace fnv_00cbc550 {
extern int DAT_01268118;
extern int DAT_01268154;
extern int DAT_0126841c;
extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_0108f1bc;
extern int _NiPoint3_ZERO;
extern int _DAT_011f4270;
extern int _DAT_011f4274;



struct FUN_00cbc550_cls : public bhkRefObject
{
    int m_iThirdValue;
    int m_10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    char m_3c;
    FUN_00cbc550_cls* __thiscall UpdateState_00cbc550();
};

// @fnv 0x00cbc550
// src: GUESS 0x00cbc550 (confidence: low)
FUN_00cbc550_cls* __thiscall FUN_00cbc550_cls::UpdateState_00cbc550()
{
    Initialize();
    *(int*)this = (int)&DAT_0102016c;
    m_iThirdValue = 0;
    ++DAT_01268154;
    *(int*)this = (int)&DAT_0102009c;
    ++DAT_01268118;
    m_f14 = 0.0f;
    m_f18 = 0.0f;
    m_10 = 0;
    m_f1c = 0.0f;
    *(int*)this = (int)&DAT_0108f1bc;
    m_f20 = 0.0f;
    m_24 = _NiPoint3_ZERO;
    m_28 = _DAT_011f4270;
    m_2c = _DAT_011f4274;
    m_30 = _NiPoint3_ZERO;
    m_34 = _DAT_011f4270;
    m_38 = _DAT_011f4274;
    m_3c = 1;
    ++DAT_0126841c;
    return this;
}
}  // namespace fnv_00cbc550

namespace fnv_00cbc8b0 {
extern MemoryManager g_memoryManager;

}  // namespace fnv_00cbc8b0

// Sets the vtable, clears the map and conditionally deallocates it.
// @fnv 0x00cbc8b0
// The shared base has no class-specific operator delete; keep the game's
// deleting-destructor entry point with its original ECX / stack argument ABI.
void* __fastcall DeleteLiquidActionMap(LiquidActionMapBase* map, void*, unsigned int flags)
{
    map->LiquidActionMapBase::~NiTMapBase();
    if (flags & 1)
        fnv_00cbc8b0::g_memoryManager.Deallocate(map);
    return map;
}

void __cdecl RegisterStaticCollisionAgent(void*);
void __cdecl hkPredGskAgent3_registerAgent3(void*, int, int);
void __cdecl RegisterScriptHandlers(void*);
void __cdecl hkpBoxBoxAgent_registerAgent(void*);
void __cdecl hkBoxBoxAgent3_registerAgent3(void*);
void __cdecl Object_UpdateFields_00d3fd00(void*);
void __cdecl hkpSphereCapsuleAgent_registerAgent(void*);
void __cdecl Object_UpdateFields_00d3dca0(void*);
void __cdecl hkpSphereBoxAgent_registerAgent(void*);
void __cdecl RegisterHandlers(void*);
void __cdecl Object_UpdateFields_00d3abc0(void*);
void __cdecl hkCapsuleTriangleAgent3_registerAgent3(void*);
void __cdecl hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(void*);
void __cdecl hkpMultiRayConvexAgent_registerAgent(void*);
void __cdecl hkpBvTreeStreamAgent_registerMultiRayAgent(void*);

// @fnv 0x00cbfcb0
// src: HAVOK_LIB 0x00cbfcb0
void __cdecl hkpAgentRegisterUtil__registerTerminalAgents(void* pObject)
{
    RegisterStaticCollisionAgent(pObject);
    hkPredGskAgent3_registerAgent3(pObject, 0x12, 0x12);
    RegisterScriptHandlers(pObject);
    hkpBoxBoxAgent_registerAgent(pObject);
    hkBoxBoxAgent3_registerAgent3(pObject);
    Object_UpdateFields_00d3fd00(pObject);
    hkpSphereCapsuleAgent_registerAgent(pObject);
    Object_UpdateFields_00d3dca0(pObject);
    hkpSphereBoxAgent_registerAgent(pObject);
    RegisterHandlers(pObject);
    Object_UpdateFields_00d3abc0(pObject);
    hkCapsuleTriangleAgent3_registerAgent3(pObject);
    hkpMultiSphereTriangleAgent_staticGetPenetrations_UpdateState_00d389f0(pObject);
    hkpMultiRayConvexAgent_registerAgent(pObject);
    hkpBvTreeStreamAgent_registerMultiRayAgent(pObject);
}

struct FUN_00cbbfa0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cbbfa0_class();
};

// @fnv 0x00cbbfa0
FUN_00cbbfa0_class::FUN_00cbbfa0_class()
{
    m_iWordAt00 = 0x32000;
    m_iWordAt04 = 0x600000;
}

struct FUN_00ca5540_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_p;
    int GetEntryValue(int i);
};

// @fnv 0x00ca5540
int FUN_00ca5540_Class::GetEntryValue(int i)
{
    unsigned char* p = (unsigned char*)(this ? *(unsigned int*)((char*)this + 8) : 0);
    unsigned int uiIndex = (unsigned int)i >> 24;
    if (i != -1 && (int)uiIndex < (int)*(unsigned short*)(*(unsigned int*)(p + 0x84) + 0x10))
    {
        p = *(unsigned char**)(*(unsigned int*)(p + 0x84) + 0x24);
        return *(unsigned int*)(p + uiIndex * 12 + 8);
    }
    return *(unsigned int*)((char*)this + 0x10) & 0x1f;
}

extern int DAT_010c8d14;
struct FUN_00cba080_class
{
    int m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    FUN_00cba080_class* __thiscall FUN_00cba080(int flag);
};
// @fnv 0x00cba080
FUN_00cba080_class* FUN_00cba080_class::FUN_00cba080(int flag)
{
    void* old = m_data;
    m_vtbl = (int)&DAT_010c8d14;
    if (old)
    {
        ((void(__stdcall*)(void*)) * (void**)((char*)&DAT_010c8d14 + 8))(old);
        m_data = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
    if (flag & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

extern int DAT_010c8d00;
extern void(__cdecl* DAT_010c8d08)(void*);

struct FUN_00cba030_class
{
    int m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    FUN_00cba030_class* __thiscall FUN_00cba030(int flag);
};

// @fnv 0x00cba030
FUN_00cba030_class* __thiscall FUN_00cba030_class::FUN_00cba030(int flag)
{
    m_vtbl = (int)&DAT_010c8d00;
    if (m_iWordAt04)
    {
        ((void(__stdcall*)(void*))DAT_010c8d08)(m_iWordAt04);
        m_iWordAt04 = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
    if (flag & 1)
    {
        _g_memoryManager.Deallocate(this);
    }
    return this;
}

struct FUN_00ca2020_Class
{
    void FUN_00ca2020();
};

struct FUN_00ca20e0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void ClearAndFreeEntries();
};

// @fnv 0x00ca20e0
void FUN_00ca20e0_Class::ClearAndFreeEntries()
{
    unsigned int i;
    for (i = 0; i < (unsigned int)m_iThirdValue; i++)
    {
        FUN_00ca2020_Class* p = *(FUN_00ca2020_Class**)(m_8 + i * 4);
        if (p)
        {
            p->FUN_00ca2020();
            _g_memoryManager.Deallocate(p);
        }
    }
    void** arr = (void**)((char*)this + 4);
    int* pCount = (int*)((char*)this + 8);
    if (*pCount)
    {
        void* vtbl = arr[0];
        ((void(__thiscall*)(void**, void*)) * (void**)((char*)vtbl + 8))(arr, (void*)*pCount);
        arr[1] = 0;
        arr[3] = 0;
        arr[2] = 0;
    }
    *(int*)((char*)this + 0x28) = 0;
    *(int*)((char*)this + 0x2c) = 0;
}

void __cdecl _NiFree(void*);
struct FUN_00ca4440_Class
{
    void* m_vtbl;
    void* m_data;
    FUN_00ca4440_Class* __thiscall FUN_00ca4440(unsigned int flags);
};
// @fnv 0x00ca4440
FUN_00ca4440_Class* __thiscall FUN_00ca4440_Class::FUN_00ca4440(unsigned int flags)
{
    void* old = m_data;
    m_vtbl = (void*)&DAT_010c759c;
    _NiFree(old);
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

extern int(__stdcall* DAT_00fdf1c4)(void*);
extern void(__stdcall* DAT_00fdf1c0)(void*);

struct FUN_00ca47a0_Class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    FUN_00ca47a0_Class* __thiscall AssignFrom(FUN_00ca47a0_Class* other);
};

// @fnv 0x00ca47a0
FUN_00ca47a0_Class* __thiscall FUN_00ca47a0_Class::AssignFrom(FUN_00ca47a0_Class* other)
{
    void* p = m_iWordAt00;
    if (p != other->m_iWordAt00)
    {
        if (p)
        {
            if (!DAT_00fdf1c4((char*)p + 4))
            {
                (*(void(__thiscall**)(void*))(*(int*)p + 4))(p);
            }
        }
        m_iWordAt00 = other->m_iWordAt00;
        if (m_iWordAt00)
        {
            DAT_00fdf1c0((char*)m_iWordAt00 + 4);
        }
    }
    m_iWordAt04 = other->m_iWordAt04;
    return this;
}

struct FUN_00ca5340_class
{
    int __thiscall FUN_00ca5290();
    FUN_00ca5340_class* __thiscall FUN_00ca5340(int flags);
};

// Calls FUN_00ca5290, and if flags has bit 0 set, frees this with size 0x14; returns this.
// @fnv 0x00ca5340
FUN_00ca5340_class* FUN_00ca5340_class::FUN_00ca5340(int flags)
{
    FUN_00ca5290();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

extern int _data_011c16bc;
extern int DAT_010c44e4;
extern int DAT_010c761c;
extern int DAT_012682d8;
extern int DAT_012686d0;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};


// Free an allocation if initialization throws before the factory returns it.
struct ConstructionAllocation
{
    void* memory;
    ConstructionAllocation(void* value) : memory(value) {}
    ~ConstructionAllocation()
    {
        if (memory)
            ::operator delete(memory);
    }
    void Release() { memory = 0; }
};

// Allocates and constructs a new bhkPackedNiTriStripsShape and returns it.
// @fnv 0x00ca53b0
bhkPackedNiTriStripsShape* CreatePackedNiTriStripsShape()
{
    bhkPackedNiTriStripsShape* shape = (bhkPackedNiTriStripsShape*)
        bhkPackedNiTriStripsShape::operator new(sizeof(bhkPackedNiTriStripsShape));
    ConstructionAllocation allocation(shape);
    if (shape)
    {
        shape->Initialize();
        int count = 1;
        *(void**)shape = &DAT_01030bf4;
        shape->m_0c = 0;
        shape->m_10 = 0;
        DAT_012680f8 += count;
        *(void**)shape = &DAT_010c44e4;
        DAT_012686d0 += count;
        *(void**)shape = &DAT_010c761c;
        DAT_012682d8 += count;
        allocation.Release();
        return shape;
    }
    return 0;
}


// Keep this helper: the approved shared header does not declare its methods.
struct HC1Base
{
    bool BSPackedAdditionalGeometryData_RegisterStreamables(NiStream*);
    bool bhkPackedNiTriStripsShape_RegisterStreamables(NiStream*);
};
// @fnv 0x00ca54c0
// src: XBOX_PDB 0x00ca54c0
bool HC1Base::bhkPackedNiTriStripsShape_RegisterStreamables(NiStream* stream)
{
    NiStream* s = this ? *(NiStream**)((char*)this + 8) : 0;
    NiObject* object = *(NiObject**)((char*)s + 0x84);
    ((void(__thiscall*)(NiObject*, NiStream*))(*(void***)object)[21])(object, stream);
    return BSPackedAdditionalGeometryData_RegisterStreamables(stream);
}

// Returns the float at offset 0x80 of the object stored at p+8, or 1.0f if p or that object is null.
// @fnv 0x00ca6620
// src: GUESS 0x00ca6620 (confidence: low)
float __fastcall Object_GetNestedFloatOrOne_00ca6620(void* p, int)
{
    float v;
    if (p && *(void**)((char*)p + 8))
        v = *(float*)((char*)*(void**)((char*)p + 8) + 0x80);
    else
        v = 1.0f;
    return v;
}

// @fnv 0x00ca98e0
// src: COMMUNITY 0x00ca98e0
float __cdecl hkpConstraintData_getMaxLinearImpulse()
{
    return 3.402820018375656e+38;
}

extern int DAT_0102e388;
// @fnv 0x00ca9900
// src: GUESS 0x00ca9900 (confidence: low)
void __fastcall Object_SetVirtualTable_00ca9900(int* p)
{
    *p = (int)&DAT_0102e388;
}

void __cdecl _delete(void* p, int size);

struct FUN_00ca9920_class
{
    void __thiscall FUN_00ca9860();
    FUN_00ca9920_class* __thiscall FUN_00ca9920(int flags);
};

// @fnv 0x00ca9920
FUN_00ca9920_class* __thiscall FUN_00ca9920_class::FUN_00ca9920(int flags)
{
    FUN_00ca9860();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_00ca99f0 {
extern int _data_011c16bc;
extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;


// Allocates and constructs a new bhkConstraint, returning the pointer.
// @fnv 0x00ca99f0
// src: EXE 0x00ca99f0
bhkConstraint* bhkMalleableConstraint_CreateObject()
{
    bhkConstraint* constraint = (bhkConstraint*)
        bhkConstraint::operator new(sizeof(bhkConstraint));
    ConstructionAllocation allocation(constraint);
    if (constraint)
    {
        constraint->Initialize();
        *(int**)constraint = (int*)&DAT_0108febc;
        constraint->m_iThirdValue = 0;
        ++DAT_01268188;
        *(int**)constraint = &DAT_010c81ac;
        ++DAT_0126830c;
        allocation.Release();
        return constraint;
    }
    return 0;
}
}  // namespace fnv_00ca99f0

namespace fnv_00caa1c0 {


extern int _data_011c16bc;
extern char DAT_0108febc[];
extern char DAT_010c5ce4[];
extern int DAT_01268188;
extern int DAT_01268318;


// Allocates and constructs a new bhkConstraint object, returning the pointer.
// @fnv 0x00caa1c0
// src: EXE 0x00caa1c0
bhkConstraint* __cdecl bhkLimitedHingeConstraint_CreateObject()
{
    bhkConstraint* constraint = (bhkConstraint*)
        bhkConstraint::operator new(sizeof(bhkConstraint));
    ConstructionAllocation allocation(constraint);
    if (constraint)
    {
        constraint->Initialize();
        *(int**)constraint = (int*)&DAT_0108febc;
        constraint->m_iThirdValue = 0;
        ++DAT_01268188;
        *(void**)constraint = (void*)&DAT_010c5ce4;
        ++DAT_01268318;
        allocation.Release();
        return constraint;
    }
    return 0;
}
}  // namespace fnv_00caa1c0

struct FUN_00cac980_Holder
{
    void* hkpCharacterProxy_getShapePhantom();
};
struct BaseThunk
{
    bool BSTextureSet_RegisterStreamables(NiStream&);
    int m_iWordAt00;
    int m_iWordAt04;
    FUN_00cac980_Holder* m_8;
};
struct FUN_00cac070_Stub : BaseThunk
{
    void bhkCharacterProxy_RegisterStreamables(NiStream&);
};
// @fnv 0x00cac070
// src: XBOX_PDB 0x00cac070
void FUN_00cac070_Stub::bhkCharacterProxy_RegisterStreamables(NiStream& stream)
{
    if (m_8)
    {
        void* r = m_8->hkpCharacterProxy_getShapePhantom();
        if (r)
        {
            void* obj = *(void**)((char*)r + 0xc);
            if (obj)
                ((void(__thiscall*)(void*, NiStream&))(*(void***)obj)[21])(obj, stream);
        }
    }
    BSTextureSet_RegisterStreamables(stream);
}


struct FUN_00cac920_Class
{
    char pad[0x30];
    void* m_30;
    char pad2[0x24];
    float m_58;
    float m_5c;
    void __thiscall hkpCharacterProxy_setPosition(void* body);
};

// Computes pos as m_5c + m_58 and passes it with body to the phantom's method at m_30.
// @fnv 0x00cac920
// src: HAVOK_LIB 0x00cac920
void __thiscall FUN_00cac920_Class::hkpCharacterProxy_setPosition(void* body)
{
    float pos = m_5c + m_58;
    ((hkpShapePhantom*)m_30)->SetWorldPosition(body, pos);
}

extern int DAT_010c8b0c;
extern int DAT_01268648;
struct FUN_00cb99a0_class
{
    void __thiscall FUN_00cb99a0(int a);
};
struct FUN_00cb9b30_class : FUN_00cb99a0_class
{
    int m_vtbl;
    FUN_00cb9b30_class(int a);
};
// @fnv 0x00cb9b30
FUN_00cb9b30_class::FUN_00cb9b30_class(int aiValue)
{
    FUN_00cb99a0_class::FUN_00cb99a0(aiValue);
    m_vtbl = (int)&DAT_010c8b0c;
    DAT_01268648++;
}

struct FUN_00cc66b0
{
    virtual ~FUN_00cc66b0();
};

struct FUN_00cb9c10_class : FUN_00cc66b0
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c10_class* __thiscall FUN_00cb9c10(int flags);
};

// Calls the base destructor and, when flags has bit 0 set, frees this with size 0x10; returns this.
// @fnv 0x00cb9c10
FUN_00cb9c10_class* FUN_00cb9c10_class::FUN_00cb9c10(int flags)
{
    this->FUN_00cc66b0::~FUN_00cc66b0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern int DAT_010c8cc8;

struct FUN_00cb9c30_class
{
    int m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c30_class();
};

// @fnv 0x00cb9c30
FUN_00cb9c30_class::FUN_00cb9c30_class()
{
    m_iWordAt04 = 0;
    m_8 = 1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_vtbl = (int)&DAT_010c8cc8;
}

extern int DAT_010c8ce4;
struct FUN_00cb9c50_class
{
    int m_vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00cb9c50_class();
};
// @fnv 0x00cb9c50
FUN_00cb9c50_class::FUN_00cb9c50_class()
{
    m_iWordAt04 = 0;
    m_8 = 1;
    m_iThirdValue = 0;
    m_10 = 0;
    m_vtbl = (int)&DAT_010c8ce4;
}

struct MemoryManagerReallocateHelper
{
    void* __thiscall Reallocate(void* p, unsigned int size);
};

struct FUN_00cb9cc0_class
{
    void* __thiscall ReallocateArray(void* p, unsigned int count);
};

// @fnv 0x00cb9cc0
void* FUN_00cb9cc0_class::ReallocateArray(void* pBuffer, unsigned int count)
{
    return ((MemoryManagerReallocateHelper*)&_g_memoryManager)->Reallocate(pBuffer, count * 4);
}

// Sets each of the n ints pointed to by p to 0, skipping null p and advancing the pointer.
// @fnv 0x00cb9d50
// src: GUESS 0x00cb9d50 (confidence: low)
void __stdcall Runtime_ProcessEntries_00cb9d50(int* paiValues, unsigned int n)
{
    while (n > 0)
    {
        if (paiValues)
            *paiValues = 0;
        ++paiValues;
        --n;
    }
}

struct FUN_00cba000_class
{
    int m_vtbl;
    void* m_data;
    int m_8;
    int m_iThirdValue;
    ~FUN_00cba000_class();
};

extern void(__stdcall* DAT_010c8d1c)(void*);

// @fnv 0x00cba000
FUN_00cba000_class::~FUN_00cba000_class()
{
    m_vtbl = (int)&DAT_010c8d14;
    if (m_data)
    {
        DAT_010c8d1c(m_data);
        m_data = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
}

void __cdecl FUN_00cba1d0();

struct FUN_00cba6d0_class
{
    FUN_00cba6d0_class* __thiscall FUN_00cba6d0(int flags);
};

// @fnv 0x00cba6d0
FUN_00cba6d0_class* __thiscall FUN_00cba6d0_class::FUN_00cba6d0(int flags)
{
    FUN_00cba1d0();
    if (flags & 1)
        _delete(this, 0x40);
    return this;
}

namespace fnv_00cbdae0 {
extern int _data_011c16bc;
extern int DAT_0108febc;
extern int DAT_0108fddc;
extern int DAT_01268188;
extern int DAT_01268434;


// Allocates and constructs a new bhkConstraint object, returning the pointer.
// @fnv 0x00cbdae0
// src: EXE 0x00cbdae0
bhkConstraint* __cdecl bhkHingeConstraint_CreateObject()
{
    bhkConstraint* constraint = (bhkConstraint*)
        bhkConstraint::operator new(sizeof(bhkConstraint));
    ConstructionAllocation allocation(constraint);
    if (constraint)
    {
        constraint->Initialize();
        *(int**)constraint = (int*)&DAT_0108febc;
        constraint->m_iThirdValue = 0;
        ++DAT_01268188;
        *(void**)constraint = (void*)&DAT_0108fddc;
        ++DAT_01268434;
        allocation.Release();
        return constraint;
    }
    return 0;
}
}  // namespace fnv_00cbdae0

extern float g_fCA0CD0StepTime;
extern float DAT_011ac39c;

__int64 CA0CD0GetPerformanceCounter();

class CA0CD0World
{
  public:
    void Reset();
};

struct CA0CD0Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CA0CD0World* m_pkWorld;
    int unk14;
    int unk18;
    int unk1C;
    bool m_bValueAt0C;
};

class CA0CD0Manager
{
  public:
    int unk00;
    int unk04;
    CA0CD0Entry** m_ppkEntries;
    unsigned int m_uiCount;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __int64 m_i64StartTime;
    __int64 m_i64Duration;

    void ResetEntries();
};

// @fnv 0x00ca0cd0
void CA0CD0Manager::ResetEntries()
{
    for (unsigned int i = 0; i < m_uiCount; i++)
    {
        m_ppkEntries[i]->m_bValueAt0C = true;
        m_ppkEntries[i]->m_pkWorld->Reset();
    }
    float fStepMilliseconds = g_fCA0CD0StepTime * 1000.0;
    m_i64StartTime = CA0CD0GetPerformanceCounter();
    m_i64Duration = (__int64)(DAT_011ac39c * fStepMilliseconds);
}

extern int DAT_010c7310;
extern void(__stdcall* DAT_010c7318)(void*);

extern MemoryManager _g_memoryManager;

struct FUN_00ca0d70_Class
{
    int m_vtbl;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* __thiscall FUN_00ca0d70(unsigned char flag);
};

// @fnv 0x00ca0d70
void* __thiscall FUN_00ca0d70_Class::FUN_00ca0d70(unsigned char flag)
{
    void* v = m_iWordAt04;
    m_vtbl = (int)&DAT_010c7310;
    if (v != 0)
    {
        DAT_010c7318(v);
        m_iWordAt04 = 0;
        m_iThirdValue = 0;
        m_8 = 0;
    }
    if (flag & 1)
    {
        _g_memoryManager.Deallocate(this);
    }
    return this;
}

struct SubObject04
{
    virtual ~SubObject04();
    virtual void Slot1();
    virtual void Free(void* apPtr);
    int unk04;
    int unk08;
    int unk0c;

    SubObject04();
};

struct Flag18
{
    unsigned char m_v;
    Flag18()
    {
        m_v = 0;
    }
    ~Flag18();
};

SubObject04::SubObject04()
{
    unk04 = 0;
    unk08 = 0;
    unk0c = 0;
}

struct GuardBase04
{
    GuardBase04()
    {}
    ~GuardBase04();
};

struct FUN_00ca0dc0_cls : GuardBase04
{
    virtual ~FUN_00ca0dc0_cls();
    SubObject04 m_sub04;
    int unk14;
    unsigned char m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;

    FUN_00ca0dc0_cls();
};

// Constructor that zeroes m_18 through m_2c and frees m_sub04's unk04 pointer if set, resetting its fields.
// @fnv 0x00ca0dc0
FUN_00ca0dc0_cls::FUN_00ca0dc0_cls() : m_sub04()
{
    SubObject04* pSubObject = &m_sub04;
    m_18 = 0;
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    m_28 = 0;
    m_2c = 0;
    if (pSubObject->unk04 != 0)
    {
        pSubObject->Free((void*)pSubObject->unk04);
        pSubObject->unk04 = 0;
        pSubObject->unk0c = 0;
        pSubObject->unk08 = 0;
    }
    m_28 = 0;
    m_2c = 0;
}

// BSSimpleArray-style container of pointer-sized elements.
__forceinline void CA0E60Array::SetSize(unsigned int uiSize)
{
    if (uiSize == 0)
    {
        if (m_pBuffer)
        {
            Free(m_pBuffer);
            m_pBuffer = 0;
            m_uiCapacity = 0;
            m_uiSize = 0;
        }
    }
    else if (uiSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
            m_pBuffer = Allocate(uiSize);
        else
            Reallocate(uiSize, m_uiSize);
        m_uiCapacity = uiSize;
        m_uiSize = uiSize;
    }
    else if (uiSize < m_uiSize)
    {
        m_uiSize = uiSize;
        if (uiSize <= m_uiCapacity >> 2)
        {
            Reallocate(uiSize, uiSize);
            m_uiCapacity = uiSize;
        }
    }
    else
    {
        m_uiSize = uiSize;
    }
}



// Resizes the destination array to this array's size and copies each element pointer into it.
// @fnv 0x00ca0e60
void CA0E60Array::CopyTo(CA0E60Array& kDest) const
{
    kDest.SetSize(m_uiSize);
    for (unsigned int i = 0; i < m_uiSize; i++)
        kDest.m_pBuffer[i] = m_pBuffer[i];
}

struct CA1080_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};

struct CA1080_Holder
{
    int unk00;
    int unk04;
    int unk08;
    CA1080_Shape* shape;
};

struct CA1080_Entry
{
    CA1080_Holder* holder;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct CA1080_Node
{
    int unk00;
    int unk04;
    int unk08;
    void* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    CA1080_Entry* entries;
    unsigned short entryCount;
    unsigned short unkb2;
    CA1080_Holder** holders;
    int holderCount;
};

struct CA1080_NodeList
{
    CA1080_Node** data;
    int count;
    CA1080_Node* GetAt(int i) const
    {
        return data[i];
    }
};

struct CA1080_PtrArray
{
    virtual void v00();
    virtual void** Allocate(unsigned int count);
    virtual void v08();
    virtual void** Reallocate(void** data, unsigned int count);

    void** data;
    unsigned int size;
    unsigned int capacity;

    void Add(void* item)
    {
        if (size == capacity)
        {
            if (capacity == 0)
            {
                data = Allocate(4);
                capacity = 4;
            }
            else
            {
                unsigned int newCap = capacity > 0x400 ? capacity + 0x400 : capacity * 2;
                if (data)
                {
                    data = Reallocate(data, newCap);
                }
                else
                {
                    data = Allocate(newCap);
                    capacity = newCap;
                }
                capacity = newCap;
            }
        }
        size++;
        data[size - 1] = item;
    }
};

// For each node in list, adds node->m_0c to out when its entries are not all type 11 and its holders are not all non-type-11.
// @fnv 0x00ca1080
void __stdcall CollectMixedTypeNodes(CA1080_NodeList* list, CA1080_PtrArray* out)
{
    for (int i = 0; i < list->count; i++)
    {
        bool bAllEntriesType11 = true;
        for (int j = 0; j < list->GetAt(i)->entryCount && bAllEntriesType11; j++)
        {
            bAllEntriesType11 = list->GetAt(i)->entries[j].holder->shape->GetType() == 11;
        }
        bool other = false;
        for (int k = 0; k < list->GetAt(i)->holderCount && !other; k++)
        {
            other = list->GetAt(i)->holders[k]->shape->GetType() != 11;
        }
        if (!bAllEntriesType11 && !other)
        {
            CA1080_Node* node = list->GetAt(i);
            out->Add(node ? node->m_0c : 0);
        }
    }
}

extern int DAT_01267e64;
extern int DAT_012681c0;
extern int DAT_011f4428;

struct SceneLookupBase_cls
{
    void* Find(const void* key);
};

struct SceneHost_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    SceneHost_cls* m_10;
};

struct SceneLeaf_cls : SceneLookupBase_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual int v37();
};

struct SceneNode_cls : SceneLookupBase_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    SceneHost_cls* m_1c;
    unsigned int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    SceneNode_cls** m_a0;
    unsigned short unkA4;
    unsigned short m_a6;
};

struct SceneWalker_cls
{
    void TraverseSceneNode(SceneNode_cls* node, int a2, int a3);
    void CollectLeafObjects(SceneLeaf_cls* leaf, int a2, int a3);
};

// @fnv 0x00ca1f00
void SceneWalker_cls::TraverseSceneNode(SceneNode_cls* node, int a2, int a3)
{
    if (node == 0)
        return;
    if (node->m_1c != 0)
    {
        SceneHost_cls* h2 = (SceneHost_cls*)node->m_1c->Find(&DAT_01267e64);
        if (h2 != 0 && h2->m_10 != 0)
        {
            SceneLeaf_cls* leaf = (SceneLeaf_cls*)h2->m_10->Find(&DAT_012681c0);
            if (leaf != 0 && leaf->v37() != 0)
            {
                CollectLeafObjects(leaf, a2, a3);
            }
        }
    }
    SceneNode_cls* arr = (SceneNode_cls*)node->Find(&DAT_011f4428);
    if (arr != 0)
    {
        for (unsigned int i = 0; i < arr->m_a6; i++)
        {
            TraverseSceneNode(arr->m_a0[i], a2, a3);
        }
    }
}

struct FNVTaskElement
{
};
extern "C" void __fastcall nullsub_14(FNVTaskElement* element);
struct FNVTaskAllocator
{
    virtual void fn00();
    virtual void fn04();
    virtual void fn08();
    virtual void fn0c();
    virtual void Free(void* memory, unsigned int byteCount);
};
struct FNVTaskMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FNVTaskAllocator* allocator;
};
extern "C" FNVTaskMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FNVTaskDynamicBuffer
{
    void* entries;
    int elementCount;
    unsigned int capacityAndFlags;
    void __thiscall Clear();
};

// @fnv 0x00ca1fb0
void FNVTaskDynamicBuffer::Clear()
{
    FNVTaskAllocator* allocator = hkMemoryRouter_getInstance()->allocator;
    char* entry = (char*)entries;
    if (elementCount > 0)
    {
        int remaining = elementCount;
        do
        {
            nullsub_14((FNVTaskElement*)entry);
            entry += 48;
        } while (--remaining);
    }
    elementCount = 0;
    if ((capacityAndFlags & 0x80000000u) == 0)
        allocator->Free(entries, (capacityAndFlags & 0x3fffffffu) * 48);
    capacityAndFlags = 0x80000000u;
    entries = 0;
}

extern __declspec(thread) int g_iCA2020AllocTag;

struct CA2020AllocTagScope
{
    int m_iSaved;

    CA2020AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA2020AllocTag;
        g_iCA2020AllocTag = aiAllocationTag;
    }
    ~CA2020AllocTagScope()
    {
        g_iCA2020AllocTag = m_iSaved;
    }
};

class CA2020Object
{
  public:
    virtual ~CA2020Object();
};

class CA2020Referenced
{
  public:
    void removeReference();
};

class CA2020Array
{
  public:
    ~CA2020Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
};

class FUN_00ca2020_Holder
{
  public:
    ~FUN_00ca2020_Holder();

    int unk00;
    CA2020Referenced* m_pkShape;
    CA2020Object* m_pkFirst;
    CA2020Object* m_pkSecond;
    CA2020Referenced* m_pkBody;
    CA2020Array m_kEntries;
};

// Destructor: deletes m_pkFirst and m_pkSecond, removes references from m_pkShape and m_pkBody, under an alloc-tag scope of 0x10.
// @fnv 0x00ca2020
FUN_00ca2020_Holder::~FUN_00ca2020_Holder()
{
    CA2020AllocTagScope kScope(0x10);
    if (m_pkFirst)
        delete m_pkFirst;
    if (m_pkShape)
        m_pkShape->removeReference();
    if (m_pkBody)
        m_pkBody->removeReference();
    if (m_pkSecond)
        delete m_pkSecond;
}

struct FUN_00a5d3d0_class
{
    void __thiscall FUN_00a5d3d0();
};

struct FUN_00ca3570_class : FUN_00a5d3d0_class
{
    void* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;

    void __thiscall ReleaseStorage_00ca3570();
};

extern "C" char DAT_010c740c[];
extern MemoryManager _g_memoryManager;

// @fnv 0x00ca3570
// src: GUESS 0x00ca3570 (confidence: low)
void __thiscall FUN_00ca3570_class::ReleaseStorage_00ca3570()
{
    m_vtbl = DAT_010c740c;

    if (unk14)
        _g_memoryManager.Deallocate(unk14);

    if (unk18)
        _g_memoryManager.Deallocate(unk18);

    if (unk24)
        _g_memoryManager.Deallocate(unk24);

    if (unk20)
        _g_memoryManager.Deallocate(unk20);

    FUN_00a5d3d0_class::FUN_00a5d3d0();
}

struct Record
{
    int m_iValue;
    int m_iField04;
    int m_iField08;
};

struct Table
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int* m_pValues;
};

struct Owner
{
    int unk00[29];
    Table* m_pTable;

    int GetValueByIndex(unsigned int a1);
};

// Extracts a 24-bit-shifted index from a1, bounds-checks it against m_pTable->unk10, and returns the value at that index times 3 from m_pValues.
// @fnv 0x00ca3670
int Owner::GetValueByIndex(unsigned int a1)
{
    Table* pSearchEntries = m_pTable;
    int iIndex = (int)(a1 >> 24);
    if (iIndex >= (int)pSearchEntries->unk10)
    {
        return 0;
    }
    return pSearchEntries->m_pValues[iIndex * 3];
}

struct FUN_00ca3b10_cls
{
    int m_iWordAt00;
    unsigned char m_iWordAt04;
    int m_8;

    bool hkpMeshShape_isWeldingEnabled();
};

// @fnv 0x00ca3b10
// src: COMMUNITY 0x00ca3b10
bool FUN_00ca3b10_cls::hkpMeshShape_isWeldingEnabled()
{
    return m_iWordAt04 == 0;
}

namespace fnv_00ca40f0 {




hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00ca40f0_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00ca3b90();

    FUN_00ca40f0_cls* FUN_00ca40f0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00ca3b90, then if bit 0 of acFlags is set frees this through the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00ca40f0
FUN_00ca40f0_cls* FUN_00ca40f0_cls::FUN_00ca40f0(unsigned char acFlags)
{
    FUN_00ca3b90();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00ca40f0

void __cdecl _NiFree_00aa10f0(void*);
struct PrimaryPart
{
    virtual ~PrimaryPart()
    {}
    unsigned int unknown_04, unknown_08, unknown_0c;
};
struct SecondaryPart
{
    virtual ~SecondaryPart()
    {}
    unsigned int unknown_14;
    unsigned int unknown_18;
    unsigned int unknown_1c;
    unsigned int unknown_20;
    unsigned int unknown_24;
    unsigned int unknown_28;
    unsigned int unknown_2c;
    unsigned int unknown_30;
    unsigned int unknown_34;
    unsigned int unknown_38;
    unsigned int unknown_3c;
    unsigned int unknown_40;
    unsigned int unknown_44;
    unsigned int unknown_48;
    unsigned int unknown_4c;
    unsigned int unknown_50;
    unsigned int unknown_54;
    unsigned int unknown_58;
    unsigned int unknown_5c;
    unsigned int unknown_60;
    unsigned int unknown_64;
    unsigned int unknown_68;
    unsigned int unknown_6c;
    unsigned int unknown_70;
    unsigned int unknown_74;
    unsigned int unknown_78;
    unsigned int unknown_7c;
    unsigned int unknown_80;
    unsigned int unknown_84;
    unsigned int unknown_88;
    unsigned int unknown_8c;
    unsigned int unknown_90;
};
struct CombinedBase : PrimaryPart, SecondaryPart
{
    virtual ~CombinedBase()
    {}
};
struct ResourceMember
{
    virtual ~ResourceMember()
    {
        _NiFree_00aa10f0(data);
    }
    void* data;
};
struct FUN_00ca4490 : CombinedBase
{
    ResourceMember resource;
    virtual ~FUN_00ca4490();
};
// @fnv 0x00ca4490
FUN_00ca4490::~FUN_00ca4490()
{}

struct FUN_00ca4780_tableEntry
{
    unsigned int m_iIndex;
    void* m_pIntegerData;
};

struct FUN_00ca4780_cls
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    int unk18;
    int unk19;
    int unk20;
    int unk21;
    int unk22;
    int unk23;
    int unk24;
    int unk25;
    int unk26;
    int unk27;
    int unk28;
    int unk29;
    int unk30;
    int unk31;
    int unk32;
    int unk33;
    FUN_00ca4780_tableEntry* m_pTable;
    void* hkNiTriStripsShape_getCollisionFilterInfo(unsigned int a1);
};

// @fnv 0x00ca4780
// src: COMMUNITY 0x00ca4780
void* FUN_00ca4780_cls::hkNiTriStripsShape_getCollisionFilterInfo(unsigned int a1)
{
    FUN_00ca4780_tableEntry* pSearchEntries = m_pTable;
    unsigned int iIndex = a1 >> 20;
    return pSearchEntries[iIndex].m_pIntegerData;
}

struct S_00ca49a0_Obj
{
    long m_refs;
    virtual void vfn0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_refs);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_refs))
            DeleteThis();
    }
};

struct S_00ca49a0_Ptr
{
    S_00ca49a0_Obj* m_p;
    S_00ca49a0_Ptr(S_00ca49a0_Obj* p = 0)
    {
        m_p = p;
        if (m_p)
            m_p->IncRefCount();
    }
    S_00ca49a0_Ptr(const S_00ca49a0_Ptr& o)
    {
        m_p = o.m_p;
        if (m_p)
            m_p->IncRefCount();
    }
    ~S_00ca49a0_Ptr()
    {
        if (m_p)
            m_p->DecRefCount();
    }
    S_00ca49a0_Ptr& operator=(const S_00ca49a0_Ptr& o)
    {
        if (m_p != o.m_p)
        {
            if (m_p)
                m_p->DecRefCount();
            m_p = o.m_p;
            if (m_p)
                m_p->IncRefCount();
        }
        return *this;
    }
};

struct S_00ca49a0_Elem
{
    S_00ca49a0_Ptr obj;
    int unk04;
    S_00ca49a0_Elem(int v = 0) : obj(0)
    {
        unk04 = v;
    }
    bool operator==(const S_00ca49a0_Elem& o) const
    {
        return obj.m_p == o.obj.m_p && unk04 == o.unk04;
    }
    bool operator!=(const S_00ca49a0_Elem& o) const
    {
        return !(*this == o);
    }
};

struct S_00ca49a0_Array
{
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    int unk08;
    unsigned int m_uiESize;
    unsigned int m_uiCount;
    void NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(unsigned int idx, const S_00ca49a0_Elem& e);
};

// Stores element e at index idx, growing m_uiESize and adjusting m_uiCount when the slot's empty/non-empty state changes.
// @fnv 0x00ca49a0
// src: XBOX_PDB 0x00ca49a0
void S_00ca49a0_Array::NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(unsigned int uiIndex, const S_00ca49a0_Elem& arElem)
{
    if (uiIndex >= m_uiESize)
    {
        m_uiESize = uiIndex + 1;
        if ((arElem != S_00ca49a0_Elem(0)))
            m_uiCount++;
    }
    else
    {
        if ((arElem != S_00ca49a0_Elem(0)))
        {
            if (m_pBase[uiIndex] == S_00ca49a0_Elem(0))
                m_uiCount++;
        }
        else if (m_pBase[uiIndex] != S_00ca49a0_Elem(0))
        {
            m_uiCount--;
        }
    }
    m_pBase[uiIndex] = arElem;
}

struct HandlePage
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    unsigned short m_40;
};

struct HandleSlot
{
    HandlePage* m_pHandlePage;
    int m_04;
};

struct HandleOwner
{
    bool __thiscall IsDegenerate(unsigned int handle);
};

class HandleManager
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    HandleSlot* m_88;
    int m_8C;
    int m_90;

    int __thiscall hkNiTriStripsShape_getNextKey(int handle);
};

// @fnv 0x00ca4ac0
// src: COMMUNITY 0x00ca4ac0
int HandleManager::hkNiTriStripsShape_getNextKey(int handle)
{
    unsigned int cur = (unsigned int)handle;
    for (;;)
    {
        cur++;
        unsigned int page = cur >> 0x14;
        int lo = (int)(cur & 0xfffff);
        int iPageCount = (int)m_88[page].m_pHandlePage->m_40;
        if (lo >= iPageCount)
        {
            cur = (page + 1) << 0x14;
        }
        int iPageIndex = (int)(cur >> 0x14);
        if (iPageIndex >= m_90)
        {
            return -1;
        }
        HandleOwner* owner = (HandleOwner*)((char*)this - 0x10);
        if (!owner->IsDegenerate(cur))
        {
            return (int)cur;
        }
    }
}

struct RefEntryObject
{
    virtual void Unknown();
    virtual void Release();
    volatile long referenceCount;
    void IncRefCount()
    {
        InterlockedIncrement(&referenceCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&referenceCount) == 0)
            Release();
    }
};
struct RecordEntry
{
    NiPointer<RefEntryObject> object;
    unsigned int value;
    RecordEntry() : object(), value(0)
    {}
};
struct RecordArray
{
    void* vtable;
    RecordEntry* records;
    unsigned int capacity;
    unsigned int count;
    unsigned int elementSize;
    void ClearRecords();
};
// Resets every record in the array to a default RecordEntry, then sets count and elementSize to zero.
// @fnv 0x00ca4b20
void RecordArray::ClearRecords()
{
    for (unsigned int i = 0; i < count; ++i)
    {
        records[i] = RecordEntry();
    }
    count = 0;
    elementSize = 0;
}

class FUN_00ca4d20_cls;
class FNVSub3Blob
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVSub4
{
  public:
    void Attach(void* p);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
class FNVEntry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
};
class FNVSub2
{
  public:
    void Reset();
    void Grow(void* p);
    void Store(unsigned int index, FNVEntry* entry);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    void* m_14;
};
class FNVArg
{
  public:
    unsigned int unk00;
    float m_04;
    FNVSub2 m_08;
    FNVSub4 m_20;
};
class FUN_00ca4d20_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    FNVSub3Blob m_80;
    float m_90;
    unsigned int unk94;
    FNVEntry* m_98;
    unsigned int unk9c;
    int m_a0;
    void CopyEntriesToArg(FNVArg* a1);
};

// Copies m_90 into the arg's m_04, resets and fills its m_08 sub-list from m_98 entries, and attaches m_80 to its m_20 sub-object.
// @fnv 0x00ca4d20
void FUN_00ca4d20_cls::CopyEntriesToArg(FNVArg* apArg)
{
    FNVSub2* s = &apArg->m_08;
    apArg->m_04 = m_90;
    s->Reset();
    apArg->m_20.Attach(&m_80);
    for (int i = 0; i < m_a0; ++i)
    {
        FNVEntry* e = &m_98[i];
        unsigned int idx = s->m_0c;
        if (idx >= s->m_08)
        {
            s->Grow((char*)s->m_14 + idx);
        }
        s->Store(idx, e);
    }
}

struct S_00ca4e10_T
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00ca4e10_Out
{
    int unk00;
    void* unk04;
};

struct S_00ca4e10_Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual char* v10();
};

struct S_00ca4e10_Cls
{
    int unk00;
    int unk04;
    S_00ca4e10_Obj* unk08;
    void bhkShape_CopyCinfo(S_00ca4e10_Out* out);
    char* bhkBvTreeShape_CopyCinfo(S_00ca4e10_Out* out);
};

// Calls FUN_00c84e20 on out, then stores the object's v10() result minus 0x10 (or null) into out->unk04 and returns it.
// @fnv 0x00ca4e10
// src: XBOX_PDB 0x00ca4e10
char* S_00ca4e10_Cls::bhkBvTreeShape_CopyCinfo(S_00ca4e10_Out* out)
{
    bhkShape_CopyCinfo(out);
    char* r;
    char* p;
    S_00ca4e10_Obj* o;
    if (this && (o = unk08) != 0 && (p = o->v10()) != 0)
        r = p - 0x10;
    else
        r = 0;
    out->unk04 = r;
    return r;
}

extern int DAT_012682d8;
struct FUN_00cd2de0
{
    virtual ~FUN_00cd2de0();
};
struct FUN_00ca5290 : FUN_00cd2de0
{
    virtual ~FUN_00ca5290();
    void bhkSerializable_Kill();
};
// Calls FUN_00c876a0 then decrements the global counter DAT_012682d8.
// @fnv 0x00ca5290
FUN_00ca5290::~FUN_00ca5290()
{
    bhkSerializable_Kill();
    --DAT_012682d8;
}

extern int DAT_012682dc;

// @fnv 0x00ca5300
// src: COMMUNITY 0x00ca5300
int* __cdecl bhkPackedNiTriStripsShape_GetRTTI()
{
    return &DAT_012682dc;
}

struct MatchData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int value84;
};
struct MatchObject
{
    int unk00;
    int unk04;
    MatchData* data;
    bool __thiscall bhkShape_IsEqual(MatchObject* rhs);
    bool __thiscall Equals(MatchObject* rhs);
};
// Calls FUN_00c84dc0(rhs); if it returns true, also compares value84 of this->data and rhs->data and returns that result.
// @fnv 0x00ca54f0
bool __thiscall MatchObject::Equals(MatchObject* rhs)
{
    bool result = bhkShape_IsEqual(rhs);
    if (result)
    {
        MatchData* right = rhs ? rhs->data : 0;
        MatchData* left = this ? this->data : 0;
        result = left->value84 == right->value84;
    }
    return result;
}

struct S_00ca59d0_Out;
struct S_00ca59d0_Bin
{
    int unk00;
    unsigned int unk04;
    unsigned int(__cdecl* unk08)(S_00ca59d0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* unk0C)(S_00ca59d0_Bin*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* buf, unsigned int bytes, unsigned int* compSize, unsigned int n)
    {
        unk04 += unk0C(this, buf, bytes, compSize, n);
    }
};
template <class T> inline void S_00ca59d0_Save(S_00ca59d0_Bin& bin, const T* p, unsigned int n)
{
    unsigned int uiSize = sizeof(T);
    bin.Write(p, n * sizeof(T), &uiSize, 1);
}
struct S_00ca59d0_Stream
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12(int link);
    int unk4;
    int unk8;
    int unkC;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    S_00ca59d0_Bin* unk250;
};
struct S_00ca59d0_Vec4
{
    float unk0;
    float unk4;
    float unk8;
    float unkC;
};
struct S_00ca59d0_Member
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    S_00ca59d0_Vec4 unk90;
    float unkA0;
};
struct S_00ca59d0_Self
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41(int out);
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(int* out);
    int unk04;
    S_00ca59d0_Member* unk08;
    void bhkShape_SaveBinary(S_00ca59d0_Stream* s);
    void bhkPackedNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* s);
};
// @fnv 0x00ca59d0
// src: XBOX_PDB 0x00ca59d0
void S_00ca59d0_Self::bhkPackedNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* pStream)
{
    int out;
    v45(&out);
    S_00ca59d0_Member* m = unk08;
    bhkShape_SaveBinary(pStream);
    float f = m->unkA0;
    S_00ca59d0_Save(*pStream->unk250, &f, 1);
    S_00ca59d0_Save(*pStream->unk250, &m->unk90, 1);
    pStream->v12(m->unk84);
    v41(out);
}

struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct Owned_t
{
    void Destroy();
};

struct PoolFree_t
{
    void Free(void* p);
};

extern PoolFree_t DAT_011f6238;

struct FUN_00ca5a80_cls
{
    int unk00;
    int unk04;
    int unk08;
    Owned_t* m_0c;

    void ReleaseOwned(bool flag);
};

// If flag is set, destroys the owned object at m_0c, frees its allocation via DAT_011f6238.Free, and clears m_0c.
// @fnv 0x00ca5a80
void FUN_00ca5a80_cls::ReleaseOwned(bool abRelease)
{
    TlsGuard_t guard;
    unsigned int unkLocal = 0;
    if (abRelease)
    {
        Owned_t* p = m_0c;
        if (p)
        {
            p->Destroy();
            unsigned char n = ((unsigned char*)p)[-1];
            DAT_011f6238.Free((char*)p - n);
        }
        m_0c = 0;
    }
}

// FUN_00ca6600 : a one-line function - getter
extern int g_target_00ca6600;
// @fnv 0x00ca6600
// src: COMMUNITY 0x00ca6600
void* bhkNiTriStripsShape_GetRTTI()
{
    return &g_target_00ca6600;
}

extern int DAT_012680f8;
extern int DAT_012686d0;
extern int DAT_012682e4;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012686d0 += 1;
    }
};

struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    SpawnedObject()
    {
        DAT_012682e4 += 1;
    }
};

// Allocates and constructs a SpawnedObject, returning the new instance.
// @fnv 0x00ca6670
// src: EXE 0x00ca6670
SpawnedObject* bhkNiTriStripsShape_CreateObject()
{
    return new SpawnedObject();
}

struct ArgB
{
    unsigned int unk00, unk04, unk08, unk0c;
    float f10;
};
struct ca6720Target
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    float f20, f24, f28, f2c;
};

// Scales the target's four floats by a2->f10, then calls FUN_00c84df0 with a1 and a2.
// @fnv 0x00ca6720
void bhkSphereShape::ScaleTarget(void* apArg, ArgB* apArgB)
{
    unsigned char c;
    ca6720Target* r = (ca6720Target*)this->slotB4((char*)&c);
    float v = apArgB->f10;
    volatile float* first = &r->f20;
    *first = *first * v;
    r->f24 = r->f24 * v;
    volatile float* third = &r->f28;
    *third = *third * v;
    r->f2c = r->f2c * v;
    this->bhkSphereShape::bhkShape_CopyMembers(apArg, apArgB);
}

struct S_00ca6810_Callable
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54(int arg);
};

struct S_00ca6810_Entry
{
    S_00ca6810_Callable* callable;
    int unk04;
};

struct S_00ca6810_Inner
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_00ca6810_Entry* unk98;
    int unk9c;
    int unkA0;
};

extern S_00ca6810_Callable* DAT_012682f0;

struct S_00ca6810_Class
{
    void* unk00;
    int unk04;
    S_00ca6810_Inner* unk08;

    void __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(int arg);
    void __thiscall bhkNiTriStripsShape_RegisterStreamables(int arg);
};

// Calls slot54(arg) on each callable in unk08->unk98 up to unk08->unkA0 entries, then calls FUN_00aa0ad0(arg).
// @fnv 0x00ca6810
// src: XBOX_PDB 0x00ca6810
void S_00ca6810_Class::bhkNiTriStripsShape_RegisterStreamables(int aiValue)
{
    int count;

    if (this != 0 && this->unk08 != 0)
        count = this->unk08->unkA0;
    else
        count = 0;

    for (int i = 0; i < count; ++i)
    {
        S_00ca6810_Callable** slot;

        if (this != 0 && this->unk08 != 0)
        {
            S_00ca6810_Entry& entry = this->unk08->unk98[i];
            slot = &entry.callable;
        }
        else
        {
            slot = &DAT_012682f0;
        }

        S_00ca6810_Callable* callable = *slot;
        if (callable != 0)
            callable->slot54(aiValue);
    }

    this->BSPackedAdditionalGeometryData_RegisterStreamables(aiValue);
}

struct S_00ca6880_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
};

struct S_00ca6880_Class
{
    int unk00;
    int unk04;
    S_00ca6880_Node* unk08;
    char __thiscall bhkShape_IsEqual(S_00ca6880_Class* arg);
    char __thiscall IsEquivalent(S_00ca6880_Class* arg);
};

static inline int Val(S_00ca6880_Class* o)
{
    if (o && o->unk08)
        return o->unk08->unka0;
    return 0;
}
// Calls FUN_00c84dc0 on arg; if it returns true, returns whether Val(this) equals Val(arg).
// @fnv 0x00ca6880
char S_00ca6880_Class::IsEquivalent(S_00ca6880_Class* pOther)
{
    char r = bhkShape_IsEqual(pOther);
    if (r)
    {
        r = Val(this) == Val(pOther);
    }
    return r;
}

namespace fnv_00ca68d0 {
// GetFieldValue: thiscall, one stack arg (table index selector)
struct FUN_00ca68d0_rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned short m_0c;
};

struct FUN_00ca68d0_entry
{
    FUN_00ca68d0_rec* m_pAssociatedRecord;
    unsigned int m_04;
};

struct FUN_00ca68d0_owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    FUN_00ca68d0_entry* m_98;
};

extern FUN_00ca68d0_entry DAT_012682f0;

class FUN_00ca68d0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00ca68d0_owner* m_08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int GetFieldValue(unsigned int a1);
};

// @fnv 0x00ca68d0
unsigned int FUN_00ca68d0_cls::GetFieldValue(unsigned int auiIndex)
{
    if (auiIndex == 0xffffffff)
    {
        return m_10 & 0x1f;
    }
    FUN_00ca68d0_entry* e;
    if (this != 0 && m_08 != 0)
    {
        e = m_08->m_98 + (auiIndex >> 20);
    }
    else
    {
        e = &DAT_012682f0;
    }
    FUN_00ca68d0_rec* rec = e->m_pAssociatedRecord;
    if (rec != 0)
    {
        return (rec->m_0c >> 6) & 0x1f;
    }
    return 0;
}
}  // namespace fnv_00ca68d0

namespace fnv_00ca6920 {
struct S_00ca6920_Rec
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
};

struct S_00ca6920_RecB
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
};

struct S_00ca6920_Ent
{
    S_00ca6920_Rec* rec;
    int unk04;
};

struct S_00ca6920_Mgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_00ca6920_Ent* unk98;
};

extern S_00ca6920_Ent DAT_012682f0;

struct S_00ca6920_Cls
{
    int unk00;
    int unk04;
    S_00ca6920_Mgr* unk08;
    int unk0c;
    unsigned unk10;
    unsigned char GetFlag(unsigned id, unsigned mask);
};

// @fnv 0x00ca6920
unsigned char S_00ca6920_Cls::GetFlag(unsigned id, unsigned mask)
{
    if (id == 0xffffffff)
        return (unk10 & mask) != 0;
    S_00ca6920_Ent* pEntry;
    if (this && unk08)
        pEntry = unk08->unk98 + (id >> 20);
    else
        pEntry = &DAT_012682f0;
    unsigned char r = 0;
    S_00ca6920_Rec* rec = pEntry->rec;
    if (rec)
    {
        switch (mask)
        {
        case 0x20:
            r = (((S_00ca6920_RecB*)rec)->unk0c >> 5) & 1;
            break;
        case 0x40:
            r = (rec->unk0c >> 11) & 1;
            break;
        }
    }
    return r;
}
}  // namespace fnv_00ca6920

extern __declspec(thread) int g_threadAllocationContext;
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
extern int DAT_010c771c;
extern int DAT_012682e4;

struct AllocationContextGuard
{
    int previous;
    AllocationContextGuard()
    {
        previous = g_threadAllocationContext;
        g_threadAllocationContext = 16;
    }
    ~AllocationContextGuard()
    {
        g_threadAllocationContext = previous;
    }
};

struct FNVShape : A51BF0Base
{
    void* m_vptr;
    char m_iWordAt04[8];
    int m_iThirdValue;
    int m_10;

    FNVShape()
    {
        ((bhkRefObject*)this)->Initialize();
        m_vptr = &DAT_01030bf4;
        m_iThirdValue = 0;
        m_10 = 0;
        ++DAT_012680f8;
        m_vptr = &DAT_010c44e4;
        ++DAT_012686d0;
        m_vptr = &DAT_010c771c;
        ++DAT_012682e4;
    }
};

struct FNVShapeHost
{
    virtual void Slot00() = 0;
    virtual void Slot04() = 0;
    virtual void Slot08() = 0;
    virtual void Slot0c() = 0;
    virtual void Slot10() = 0;
    virtual void Slot14() = 0;
    virtual void Slot18() = 0;
    virtual void Slot1c() = 0;
    virtual void Slot20() = 0;
    virtual void Slot24() = 0;
    virtual void Slot28() = 0;
    virtual void Slot2c() = 0;
    virtual void Slot30() = 0;
    virtual void Slot34() = 0;
    virtual void Slot38() = 0;
    virtual void Slot3c() = 0;
    virtual void Slot40() = 0;
    virtual void Slot44() = 0;
    virtual void Slot48() = 0;
    virtual void Slot4c() = 0;
    virtual void Slot50() = 0;
    virtual void Slot54() = 0;
    virtual void Slot58() = 0;
    virtual void Slot5c() = 0;
    virtual void Slot60() = 0;
    virtual void Slot64() = 0;
    virtual void Slot68() = 0;
    virtual void Slot6c() = 0;
    virtual void Slot70() = 0;
    virtual void Slot74() = 0;
    virtual void Slot78() = 0;
    virtual void Slot7c() = 0;
    virtual void Slot80() = 0;
    virtual void Slot84() = 0;
    virtual void Slot88() = 0;
    virtual void Slot8c() = 0;
    virtual void Slot90() = 0;
    virtual void Slot94() = 0;
    virtual void Slot98() = 0;
    virtual void Slot9c() = 0;
    virtual void Slota0() = 0;
    virtual void Slota4() = 0;
    virtual void Slota8() = 0;
    virtual void Slotac() = 0;
    virtual void Slotb0() = 0;
    virtual void Slotb4() = 0;
    virtual void Slotb8() = 0;
    virtual void Slotbc() = 0;
    virtual void Slotc0() = 0;
    virtual void AssignShape(FNVShape* shape, int flags) = 0;
    FNVShape* CreateShape(int flags);
};

// Creates a new FNVShape, assigns it via AssignShape with the given flags, and returns it.
// @fnv 0x00ca6990
FNVShape* FNVShapeHost::CreateShape(int flags)
{
    AllocationContextGuard allocationScope;
    bhkSerializable_CloneCritLock();
    FNVShape* shape = new FNVShape();
    AssignShape(shape, flags);
    bhkSerializable_CloneCritUnlock();
    return shape;
}

namespace fnv_00ca6a80 {
struct TlsBlock
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock g_tls;

struct TlsFlagGuard
{
    unsigned int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tls.m_2b4 = m_saved;
    }
};

struct FUN_00aa3e40_alloc
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};
extern FUN_00aa3e40_alloc DAT_011f6238;

struct FUN_00ca4bc0_obj
{
    static void* operator new(unsigned int size)
    {
        unsigned char* a = (unsigned char*)DAT_011f6238.Game_DoHeapAlloc(size);
        unsigned char pad = (unsigned char)(0x10 - ((unsigned int)a & 0xf));
        a += pad;
        a[-1] = pad;
        return a;
    }
    static void operator delete(void*)
    {}
    FUN_00ca4bc0_obj(int arg);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
};

struct FUN_00c905b0_obj
{
    void __thiscall FUN_00c905b0();
};

class FUN_00ca6a80_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(void* obj);
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc(int arg);
    void InitWithArg(int arg);
};

// Allocates a FUN_00ca4bc0_obj with arg, passes it to vfn_8c, calls FUN_00c905b0 on it, then calls vfn_bc(arg) under a TLS flag guard.
// @fnv 0x00ca6a80
void FUN_00ca6a80_cls::InitWithArg(int arg)
{
    TlsFlagGuard guard;
    FUN_00ca4bc0_obj* obj = new FUN_00ca4bc0_obj(arg);
    vfn_8c(obj);
    reinterpret_cast<FUN_00c905b0_obj*>(obj)->FUN_00c905b0();
    vfn_bc(arg);
}
}  // namespace fnv_00ca6a80

struct S_00ca7310_Arr
{
    int* m_data;
    int m_iElementCount;
    unsigned int m_pRayCursor;
    S_00ca7310_Arr() : m_data(0), m_iElementCount(0), m_pRayCursor(0x80000000)
    {}
};
struct S_00ca7310_Root
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00ca7310_Root()
    {
        unk00 = 0;
    }
};
struct S_00ca7310_Vec
{
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    S_00ca7310_Vec()
    {
        unk10 = 0.0f;
        unk14 = 0.0f;
        unk18 = 0.0f;
        unk1C = 0.0f;
    }
};
struct FUN_00ca7310 : S_00ca7310_Root
{
    S_00ca7310_Vec vec;
    int unk20;
    S_00ca7310_Arr unk24;
    S_00ca7310_Arr unk30;
    S_00ca7310_Arr unk3C;
    S_00ca7310_Arr unk48;
    S_00ca7310_Arr unk54;
    S_00ca7310_Arr unk60;
    S_00ca7310_Arr unk6C;
    S_00ca7310_Arr unk78;
    S_00ca7310_Arr unk84;
    S_00ca7310_Arr unk90;
    S_00ca7310_Arr unk9C;
    S_00ca7310_Arr unkA8;
    FUN_00ca7310();
};
// @fnv 0x00ca7310
FUN_00ca7310::FUN_00ca7310()
{}

struct MotionByte
{
    void FindFloatTableIndex(const float*);
};
struct MotionInstance
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void SetMass(float);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void SetInertia(const float*);
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void SetGridPosition(const void*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    MotionByte linearDamping;
    MotionByte angularDamping;
};
struct MotionStorage
{
    MotionInstance* FUN_00ca9270(const void*, const void*);
    MotionInstance* FUN_00d1e690(const void*, const void*);
    MotionInstance* FUN_00d21930(const void*, const void*);
    MotionInstance* FUN_00d1dfa0(const void*, const void*);
    MotionInstance* FUN_00ca9240(const void*, const void*);
    MotionInstance* InitFixedRigidMotion(const void*, const void*);
};
float NiMin(float, float);
float NiMax(float, float);
// Selects a motion instance from storage by type, sets inertia, center and mass unless type is 4, then applies linear and angular damping.
// @fnv 0x00ca8240
// src: HAVOK_LIB 0x00ca8240
void hkpRigidBody_createDynamicRigidMotion(int type, const void* position, const void* rotation, float mass, const float* inertia,
                  const void* center, float linearDamping, float angularDamping, MotionStorage* storage)
{
    MotionInstance* motion;
    switch (type)
    {
    case 2:
        motion = storage ? storage->FUN_00ca9270(position, rotation) : 0;
        break;
    case 3:
        motion = storage ? storage->FUN_00d1e690(position, rotation) : 0;
        break;
    case 6:
        motion = storage ? storage->FUN_00d21930(position, rotation) : 0;
        break;
    case 1: {
        float x = inertia[0], y = inertia[5], z = inertia[10];
        float fMinInertia = NiMin(x, NiMin(y, z));
        if ((double)0.8f * NiMax(x, NiMax(y, z)) < fMinInertia)
            motion = storage ? storage->FUN_00ca9270(position, rotation) : 0;
        else
            motion = storage ? storage->FUN_00d1e690(position, rotation) : 0;
        break;
    }
    case 4:
        angularDamping = linearDamping = 1000000.0f;
        motion = storage ? storage->FUN_00d1dfa0(position, rotation) : 0;
        break;
    case 7:
        motion = storage ? storage->FUN_00ca9240(position, rotation) : 0;
        break;
    default:
        motion = storage ? storage->InitFixedRigidMotion(position, rotation) : 0;
        break;
    }
    if (type != 4)
    {
        motion->SetInertia(inertia);
        motion->SetGridPosition(center);
        motion->SetMass(mass);
    }
    motion->linearDamping.FindFloatTableIndex(&linearDamping);
    motion->angularDamping.FindFloatTableIndex(&angularDamping);
}

struct Ctx
{
    void* pThis;
    int a1;
    char a2;
};
struct Obj
{
    virtual void v0();
    virtual void v1(Ctx*);
};
struct C
{
    char pad[0x8c];
    Obj** m8c;
    int m90;
    void NotifyAll(int a1, char a2);
};
// Iterates m8c backwards from m90-1 and calls v1 on each non-null entry with a context holding a1, this and a2.
// @fnv 0x00ca9520
void C::NotifyAll(int aiValue, char a2)
{
    Ctx ctx;
    ctx.a1 = aiValue;
    ctx.pThis = this;
    ctx.a2 = a2;
    for (int i = this->m90 - 1; i >= 0; --i)
    {
        if (this->m8c[i])
        {
            Obj* p = this->m8c[i];
            p->v1(&ctx);
        }
    }
}

extern int DAT_0126830c;

class FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_base();
};

class FUN_00ca9860_cls : public FUN_00ca9860_base
{
  public:
    virtual ~FUN_00ca9860_cls();
    void bhkSerializable_Kill();
};

// Calls FUN_00c876a0 and decrements the global counter DAT_0126830c.
// @fnv 0x00ca9860
FUN_00ca9860_cls::~FUN_00ca9860_cls()
{
    bhkSerializable_Kill();
    --DAT_0126830c;
}

extern int DAT_01268310;

// @fnv 0x00ca9910
// src: GUESS 0x00ca9910 (confidence: low)
int __cdecl Runtime_EvaluateValue_00ca9910()
{
    return reinterpret_cast<int>(&DAT_01268310);
}

struct S_00ca9940_Child
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual unsigned int vfn_20();
};
struct S_00ca9940_Obj
{
    int unk00;
    int unk04;
    int unk08;
    S_00ca9940_Child* m_pChildObject;
};
void __cdecl hkBallAndSocketConstraintCinfo_ApplyScale(float f, S_00ca9940_Child* c);
void __cdecl hkHingeConstraintCinfo_ApplyScale(float f, S_00ca9940_Child* c);

// If o and its child are non-null and f is not 1.0, dispatches on the child's vfn_20 result to call FUN_00cc96b0 or FUN_00cbd9e0 with f.
// @fnv 0x00ca9940
// src: COMMUNITY 0x00ca9940
void __cdecl hkMalleableConstraintCinfo_ApplyScale(float afValue, S_00ca9940_Obj* pObj)
{
    S_00ca9940_Child* c;
    if (pObj && (c = pObj->m_pChildObject) != 0 && afValue != 1.0f)
    {
        switch (c->vfn_20())
        {
        case 0:
            hkBallAndSocketConstraintCinfo_ApplyScale(afValue, pObj->m_pChildObject);
            break;
        case 1: {
            S_00ca9940_Child* p = pObj->m_pChildObject;
            hkHingeConstraintCinfo_ApplyScale(afValue, p);
        }
        break;
        case 2: {
            S_00ca9940_Child* q = pObj->m_pChildObject;
            hkHingeConstraintCinfo_ApplyScale(afValue, q);
        }
        break;
        case 7: {
            S_00ca9940_Child* r = pObj->m_pChildObject;
            hkHingeConstraintCinfo_ApplyScale(afValue, r);
        }
        break;
        }
    }
}

struct FUN_00ca9aa0;
struct State
{
    unsigned int value;
    State() : value(0)
    {}
};
struct BaseOwner
{
    virtual void Act();
    unsigned short unk04;
    unsigned short unk06;
    State unk08;
    BaseOwner() : unk06(1), unk08()
    {}
};
struct InternalPart
{
    unsigned short mode;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    InternalPart() : mode(1)
    {}
    ~InternalPart();
};
void __fastcall hkpBridgeConstraintAtom_init(InternalPart* part, unsigned int command, FUN_00ca9aa0* parent);
struct FUN_00ca9aa0 : BaseOwner
{
    virtual void Act();
    unsigned int unk0c;
    InternalPart part;
    float value;
    FUN_00ca9aa0();
};
// Constructor: initializes unk0c to 0, calls FUN_00d21ce0 on part with command 1, and sets value to 0.01f.
// @fnv 0x00ca9aa0
FUN_00ca9aa0::FUN_00ca9aa0() : BaseOwner(), part()
{
    unk0c = 0;
    hkpBridgeConstraintAtom_init(&part, 1, this);
    value = 0.01f;
}

namespace fnv_00ca9b10 {
struct FnvCpu_FUN_00ca9b10_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00ca9b10_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ca9b10_CpuAllocator* allocator;
};
FnvCpu_FUN_00ca9b10_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00ca9b10_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void UpdateFields_00cdf7a0();
    FnvCpu_FUN_00ca9b10_CpuObject* FUN_00ca9b10(unsigned int flags);
};
// Calls FUN_00cdf7a0, then if bit 0 of flags is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00ca9b10
FnvCpu_FUN_00ca9b10_CpuObject* FnvCpu_FUN_00ca9b10_CpuObject::FUN_00ca9b10(unsigned int flags)
{
    UpdateFields_00cdf7a0();
    if (flags & 1)
    {
        FnvCpu_FUN_00ca9b10_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00ca9b10

class BCA9D50BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCA9D50BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCA9D50BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCA9D50Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCA9D50BinaryStream* m_pUnderlyingStream;
    BCA9D50BinaryStream* m_pBackingStream;
};

template <class T>
inline void BCA9D50BinaryStreamSave(BCA9D50BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCA9D50SaveBinary(BCA9D50Stream& kStream, const T& value)
{
    BCA9D50BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BCA9D50Object;

void __cdecl bhkConstraintManager_SaveBinary(BCA9D50Stream& kStream, BCA9D50Object* pkObject);

struct BCA9D50Data
{
    int unk00;
    int unk04;
    int unk08;
    BCA9D50Object* m_pPointer;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
};

class BCA9D50Base
{
  public:
    void SaveBinary(BCA9D50Stream& kStream);
};

class BCA9D50Wrapper : public BCA9D50Base
{
  public:
    int unk00;
    BCA9D50Data* m_pUserData;

    void hkMalleableConstraintCinfo_SaveBinary(BCA9D50Stream& kStream);
};

// @fnv 0x00ca9d50
// src: XBOX_PDB 0x00ca9d50
void BCA9D50Wrapper::hkMalleableConstraintCinfo_SaveBinary(BCA9D50Stream& kStream)
{
    BCA9D50Base::SaveBinary(kStream);
    BCA9D50Data* pkData = m_pUserData;
    bhkConstraintManager_SaveBinary(kStream, pkData->m_pPointer);
    BCA9D50SaveBinary(kStream, pkData->m_fValue);
}

namespace fnv_00ca9da0 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct SlotAllocator
{
    virtual void vSlot00();
    virtual void* vSlot04(unsigned int size);
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual void vSlot10(unsigned int a, unsigned int b);
};



hkMemoryRouter* hkMemoryRouter_getInstance();

struct SpawnedBase
{
    virtual void vSlot00()
    {}
    unsigned short m_size04;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    SpawnedBase();
};

struct SpawnedObject : SpawnedBase
{
    SpawnedObject() : SpawnedBase()
    {}
    void* operator new(unsigned int size) throw()
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        void* p = ((SlotAllocator*)holder->m_heap)->vSlot04(size);
        ((SpawnedBase*)p)->m_size04 = (unsigned short)size;
        return p;
    }
};

struct FUN_00ca9da0_cls
{
    int unk00;
    int m_04;
    int EnsureSpawnedObject();
};

// Allocates a SpawnedObject into m_04 if it is null, then returns 0x20.
// @fnv 0x00ca9da0
int FUN_00ca9da0_cls::EnsureSpawnedObject()
{
    TlsGuard_t guard;
    if (this->m_04 == 0)
    {
        SpawnedObject* p = new SpawnedObject();
        this->m_04 = (int)p;
    }
    return 0x20;
}
}  // namespace fnv_00ca9da0

struct FUN_00ca9b40_Obj
{
    void __thiscall UpdateFields_00ca9b40(int value);
};

struct FUN_00ca9e50_Obj
{
    int unk00;
    FUN_00ca9b40_Obj* unk04;

    void __thiscall ProcessState_00ca9e50(int value);
};

// @fnv 0x00ca9e50
// src: GUESS 0x00ca9e50 (confidence: low)
void __thiscall FUN_00ca9e50_Obj::ProcessState_00ca9e50(int value)
{
    if (this->unk04 != 0)
    {
        this->unk04->UpdateFields_00ca9b40(value);
    }
}

namespace fnv_00ca9f40 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard
{
    int m_saved;
    TlsGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct S_ca9f40_Pool
{
    void* Game_DoHeapAlloc(unsigned int n);
};
extern S_ca9f40_Pool DAT_011f6238;
extern int DAT_010c8288;
struct S_ca9f40_Base
{
    int unk04;
};
struct S_ca9f40_Counters
{
    int* unk00;
    S_ca9f40_Base base;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Game_DoHeapAlloc(n);
    }
};
struct S_ca9f40
{
    int unk00;
    int unk04;
    int unk08;
    S_ca9f40_Base* unk0c;
    void CopyFromSource(S_ca9f40_Counters* c);
    S_ca9f40_Base* GetOrCreateBase(bool* created);
};
// Returns unk0c, allocating and initialising a new S_ca9f40_Counters (setting *created) when unk0c is null, then calling CopyFromSource if unk08 is set.
// @fnv 0x00ca9f40
S_ca9f40_Base* S_ca9f40::GetOrCreateBase(bool* created)
{
    TlsGuard guard;
    bool b = (unk0c == 0);
    *created = b;
    if (b)
    {
        S_ca9f40_Counters* c = new S_ca9f40_Counters;
        S_ca9f40_Base* r;
        if (c)
        {
            S_ca9f40_Base* bp = &c->base;
            c->unk08 = 1;
            c->unk0c = 0;
            c->unk10 = 0;
            c->unk00 = &DAT_010c8288;
            bp->unk04 = 0;
            r = bp;
        }
        else
        {
            r = 0;
        }
        unk0c = r;
        if (unk08)
            CopyFromSource(unk0c ? (S_ca9f40_Counters*)((char*)unk0c - 4) : 0);
    }
    return unk0c;
}
}  // namespace fnv_00ca9f40

extern int DAT_01268318;

class PolyBase
{
  public:
    virtual ~PolyBase();
};

class FUN_00caa140_cls : public PolyBase
{
  public:
    virtual ~FUN_00caa140_cls();
    void bhkSerializable_Kill();
};

// @fnv 0x00caa140
FUN_00caa140_cls::~FUN_00caa140_cls()
{
    bhkSerializable_Kill();
    --DAT_01268318;
}

// Allocates and constructs a bhkCapsuleShape.
// @fnv 0x00caae30
NiObject* __cdecl bhkCapsuleShape::CreateObject()
{
    return new bhkCapsuleShape();
}

// Packs four bytes into an unsigned int, shifting in d first, then a, b and c, and returns it.
// @fnv 0x00cabb00
unsigned int __cdecl PackBytesBigEndian(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    unsigned int result = d;
    result = (result << 8) + a;
    result = (result << 8) + b;
    result = (result << 8) + c;
    return result;
}

struct FUN_00cac9a0_Obj
{
    void __thiscall getCinfo(int value);
};

struct FUN_00cabfd0_Obj
{
    int unk00;
    int unk04;
    FUN_00cac9a0_Obj* unk08;

    void __thiscall bhkCharacterProxy_GetCinfo(int value);
};

// @fnv 0x00cabfd0
// src: COMMUNITY 0x00cabfd0
void __thiscall FUN_00cabfd0_Obj::bhkCharacterProxy_GetCinfo(int value)
{
    if (this != 0 && this->unk08 != 0)
    {
        this->unk08->getCinfo(value);
    }
}

struct FUN_00cabff0_res
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
};

struct FUN_00cabff0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual FUN_00cabff0_res* SlotB4(int* p);
    void FUN_00c87650(int a);
    void bhkCharacterProxy_LoadBinary(int a);
};

void __fastcall ReadLinkID(int a);

// @fnv 0x00cabff0
// src: XBOX_PDB 0x00cabff0
void FUN_00cabff0_cls::bhkCharacterProxy_LoadBinary(int a)
{
    int b = *(volatile int*)&a;
    ReadLinkID(b);
    FUN_00c87650(b);
    FUN_00cabff0_res* r = SlotB4(&a);
    r->m_48 = 0;
}

struct S_00cac0b0_Arg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c(int value);
};

struct S_00cac0b0_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_00cac0b0_Obj
{
    int unk00;
    int unk04;
    S_00cac0b0_Inner* unk08;
    S_00cac0b0_Inner* hkpCharacterProxy_getShapePhantom();
};

struct S_00cac0b0_cls
{
    int unk00;
    int unk04;
    S_00cac0b0_Obj* unk08;
    void bhkCharacterProxy_SaveBinary(S_00cac0b0_Arg* a);
    void SaveSerializeData(S_00cac0b0_Arg* a);
};

// @fnv 0x00cac0b0
// src: XBOX_PDB 0x00cac0b0
void S_00cac0b0_cls::bhkCharacterProxy_SaveBinary(S_00cac0b0_Arg* a)
{
    S_00cac0b0_Inner* node = 0;
    if (unk08)
        node = unk08->hkpCharacterProxy_getShapePhantom();
    a->v0c(node ? node->unk0c : 0);
    SaveSerializeData(a);
}

struct FUN_00cac110_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void bhkCharacterController_UnMarkWrite();
};

// @fnv 0x00cac110
// src: COMMUNITY 0x00cac110
void __thiscall FUN_00cac110_Class::bhkCharacterController_UnMarkWrite()
{
    this->bhkCharacterController_UnMarkWrite();
}

namespace fnv_00cac250 {
struct FUN_00cac250_tls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int m_2b4;
};
extern __declspec(thread) FUN_00cac250_tls g_tls;

struct FUN_00cac250_obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    FUN_00cac250_obj();
    static void* __cdecl operator new(unsigned int size);
};

struct TlsGuard_b9283
{
    int m_saved;
    TlsGuard_b9283()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~TlsGuard_b9283()
    {
        g_tls.m_2b4 = m_saved;
    }
};

extern "C" void __cdecl bhkSerializable_CloneCritLock(void);
extern "C" void __cdecl bhkSerializable_CloneCritUnlock(void);

struct FUN_00cac250_cls
{
    void bhkSerializable_CopyMembers(FUN_00cac250_obj* o, int a1);
    FUN_00cac250_obj* CreateObject(int a1);
};

// @fnv 0x00cac250
FUN_00cac250_obj* FUN_00cac250_cls::CreateObject(int a1)
{
    TlsGuard_b9283 guard;
    FUN_00cac250_obj* obj = 0;
    bhkSerializable_CloneCritLock();
    obj = new FUN_00cac250_obj();
    bhkSerializable_CopyMembers(obj, a1);
    bhkSerializable_CloneCritUnlock();
    return obj;
}
}  // namespace fnv_00cac250

class CAC680World
{
  public:
    void Update();
};

class CAC680Listener
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void OnUpdate();

    int unk04;
};

class CAC680Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void Toggle();

    int unk04;
    CAC680World* m_pkWorld;
    int unk0C;
    CAC680Listener m_kListener;

    void ToggleAndUpdate();
};

// Toggles the object, updates m_pkWorld, toggles again, then calls OnUpdate on m_kListener.
// @fnv 0x00cac680
void CAC680Object::ToggleAndUpdate()
{
    Toggle();
    m_pkWorld->Update();
    Toggle();
    m_kListener.OnUpdate();
}

namespace fnv_00cb0ad0 {
struct CB0AD0Allocator;

struct CB0AD0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CB0AD0Allocator* m_pStreamAllocator;
};

extern "C" CB0AD0MemoryRouter& __cdecl hkMemoryRouter_getInstance();
char* AllocateWithHeader(CB0AD0Allocator* pkHeap, int iSize);
void CopyIfNonEmpty(char* pcDst, const char* pcSrc, int iCount);

static inline char* CB0AD0AllocateChars(int iCount)
{
    CB0AD0Allocator* pkHeap = hkMemoryRouter_getInstance().m_pStreamAllocator;
    return AllocateWithHeader(pkHeap, iCount);
}

// @fnv 0x00cb0ad0
// src: HAVOK_LIB 0x00cb0ad0
static __declspec(noinline) char* strNdup(const char* pcSrc, int iMaxChars)
{
    int iLen = hkString_strLen((int)pcSrc);
    if (iLen > iMaxChars)
        iLen = iMaxChars;
    char* pcCopy = CB0AD0AllocateChars(iLen + 1);
    CopyIfNonEmpty(pcCopy, pcSrc, iLen);
    pcCopy[iLen] = 0;
    return pcCopy;
}

char* CB0AD0Dup(const char* pcSrc, int iMaxChars)
{
    return strNdup(pcSrc, iMaxChars);
}
}  // namespace fnv_00cb0ad0

// Rect-like record used by InitRect and its helper.
struct FUN_00cb0ed0_rect
{
    volatile int m_fMinimumU;
    volatile int m_fMinimumV;
    volatile int m_fMaximumU;
    volatile int m_fMaximumV;
    volatile bool m_bValueAt0C;
};

void __cdecl ResizeBuffer(FUN_00cb0ed0_rect* pRect, int aFlag);

// Resets the rect: clears its flag (calling ResizeBuffer if set), then sets its four bounds from nLeft and nSize.
// @fnv 0x00cb0ed0
void __cdecl InitRect(FUN_00cb0ed0_rect* pRect, int nLeft, int nSize)
{
    if (pRect->m_bValueAt0C)
    {
        ResizeBuffer(pRect, 0);
    }
    pRect->m_bValueAt0C = false;
    pRect->m_fMinimumU = nLeft;
    pRect->m_fMinimumV = nLeft;
    pRect->m_fMaximumU = nLeft + nSize;
    pRect->m_fMaximumV = nLeft + nSize - 0x20;
}

// File-static helper (reconstructed separately at its own address).
static __declspec(noinline) char CB1030ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}

// Exported elsewhere through a function pointer, which keeps the helper's cdecl stack arguments.
char(__cdecl* g_pfnCB1030ToLower)(char) = CB1030ToLower;

// @fnv 0x00cb1030
int __cdecl CompareCaseInsensitive(const char* pcA, const char* pcB, int n)
{
    int i = 0;
    while ((pcA[i] || pcB[i]) && i < n)
    {
        char cA = CB1030ToLower(pcA[i]);
        char cCharB = CB1030ToLower(pcB[i]);
        if (cA < cCharB)
            return -1;
        if (cA > cCharB)
            return 1;
        ++i;
    }
    return 0;
}

// FUN_00cb75d0 : default constructor of the object whose first member holds
// the class table pointer.  The constructor clears three trailing dword
// members, sets a byte flag to 1 and installs the table pointer last.

extern int DAT_010c88b8;

struct FUN_00cb75d0_cls
{
    void* m_pVTable;
    int m_iValue04;
    unsigned char m_bValue08;
    int m_iValue0c;
    int m_iValue10;

    FUN_00cb75d0_cls();
};

// @fnv 0x00cb75d0
FUN_00cb75d0_cls::FUN_00cb75d0_cls()
{
    m_iValue0c = 0;
    m_iValue10 = 0;
    m_iValue04 = 0;
    m_bValue08 = 1;
    m_pVTable = (void*)&DAT_010c88b8;
}

static float DAT_010c8ae4 = 0.016f;
extern double DAT_010241b0;

struct S_00cb9770_Foo
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual float V41(float value);

    int unk04;
    unsigned short unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    float unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    float unk50;

    void __thiscall bhkForceController_ApplyForce();
    bool GetActive()
    {
        return ((this->unk08 >> 3) & 1) != 0;
    }
    void __thiscall UpdateActiveState(float* param);
};

// @fnv 0x00cb9770
void __thiscall S_00cb9770_Foo::UpdateActiveState(float* pfValue)
{
    this->unk50 = DAT_010c8ae4;

    if (this->GetActive() && this->unk2c != 0)
    {
        if (this->unk20 != DAT_010241b0)
        {
            float fDiff = *pfValue - this->unk20;
            this->unk50 = fDiff;
            if (fDiff < 0.0f)
                this->unk50 = DAT_010c8ae4;
        }
        float fResult = this->V41(*pfValue);
        this->bhkForceController_ApplyForce();
        if (fResult == this->unk18)
            this->unk08 &= 0xfff7;
    }
}

extern int DAT_01268188;
extern int DAT_0108febc;
struct FUN_00c87c30
{
    void* vtable;
    int unk04;
    int unk08;
    FUN_00c87c30();
};
struct InitializedField
{
    int value;
    InitializedField() : value(0)
    {}
    ~InitializedField();
};
struct FUN_00cb99a0 : FUN_00c87c30
{
    InitializedField unk0c;
    FUN_00cb99a0(char* source);
    void SpawnAndAttach(char* source);
};
// Sets the vtable, initializes unk0c, calls SpawnAndAttach with source+4 (or null), and increments DAT_01268188.
// @fnv 0x00cb99a0
FUN_00cb99a0::FUN_00cb99a0(char* source) : FUN_00c87c30(), unk0c()
{
    vtable = &DAT_0108febc;
    SpawnAndAttach(source ? source + 4 : 0);
    ++DAT_01268188;
}

extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_01268324;

struct S_cb9a90_Base
{
    int unk04;
    int unk08;
    S_cb9a90_Base();
    virtual ~S_cb9a90_Base();
};

struct S_cb9a90_A : S_cb9a90_Base
{
    int unk0c;
    int unk10;
    S_cb9a90_A()
    {
        unk0c = 0;
        unk10 = 0;
        DAT_012680f8++;
    }
};

struct S_cb9a90_B : S_cb9a90_A
{
    S_cb9a90_B()
    {
        DAT_01268274++;
    }
};

struct S_cb9a90_C : S_cb9a90_B
{
    S_cb9a90_C()
    {
        DAT_01268250++;
    }
};

struct FUN_00cb9a90 : S_cb9a90_C
{
    void bhkCapsuleShape_Init(int a, int b, float c);
    FUN_00cb9a90(int a, int b, float c);
    virtual ~FUN_00cb9a90();
};

// Increments DAT_01268324 and forwards the three constructor arguments to FUN_00cab0e0.
// @fnv 0x00cb9a90
FUN_00cb9a90::FUN_00cb9a90(int aiParam1, int aiParam2, float afValue)
{
    DAT_01268324++;
    bhkCapsuleShape_Init(aiParam1, aiParam2, afValue);
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_0126864c;

// @fnv 0x00cb9b50
// src: COMMUNITY 0x00cb9b50
GlobalObjectO2_00a7b610* __cdecl bhkBallAndSocketConstraint_GetRTTI()
{
    return &g_0126864c;
}

struct CB9B80Header
{
    int unk00;
};

struct CB9B80BaseInfo
{
    int unk00;
};

struct CB9B80Info : CB9B80Header, CB9B80BaseInfo
{
};

class CB9B80RefObject
{
  public:
    CB9B80RefObject();
    virtual ~CB9B80RefObject();

    int unk04;
    int unk08;
};

class CB9B80SerializableObject : public CB9B80RefObject
{
  public:
    CB9B80SerializableObject() : m_pkWorld(0)
    {}

    void* m_pkWorld;
};

class CB9B80WorldObject : public CB9B80SerializableObject
{
  public:
    CB9B80WorldObject()
    {
        ++ms_uiCount;
    }
    virtual ~CB9B80WorldObject();

    static unsigned int ms_uiCount;
};

class FUN_00cb9b80 : public CB9B80WorldObject
{
  public:
    FUN_00cb9b80(CB9B80Info* pkInfo);
    virtual ~FUN_00cb9b80();

    void Init(CB9B80BaseInfo* pkInfo);

    static unsigned int ms_uiCount;
};

// Initializes the object from pkInfo and increments the static instance count.
// @fnv 0x00cb9b80
FUN_00cb9b80::FUN_00cb9b80(CB9B80Info* pkInfo)
{
    Init(pkInfo);
    ++ms_uiCount;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268610;
// @fnv 0x00cb9c00
// src: GUESS 0x00cb9c00 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00cb9c00()
{
    return &DAT_01268610;
}

class FUN_00cb9c70_item
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a1);
};

class FUN_00cb9c70_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00cb9c70_item** m_ppItems;
    unsigned int m_uiCount;
    bool Check(int a1);
    bool bhkRagdollTemplate_RegisterStreamables(int a1);
};

// Calls Check(a1); if it returns true, calls v21(a1) on each of the m_uiCount items in m_ppItems and returns the Check result.
// @fnv 0x00cb9c70
// src: XBOX_PDB 0x00cb9c70
bool FUN_00cb9c70_cls::bhkRagdollTemplate_RegisterStreamables(int aiValue)
{
    bool result = Check(aiValue);
    if (result)
    {
        unsigned int count = m_uiCount;
        for (unsigned int i = 0; i < count; i++)
        {
            m_ppItems[i]->v21(aiValue);
        }
    }
    return result;
}

namespace fnv_00cb9cb0 {
struct S_00aa4060_Class
{
    void __thiscall MemoryManager_Deallocate();
};

extern int DAT_011f6238;

// @fnv 0x00cb9cb0
// src: GUESS 0x00cb9cb0 (confidence: low)
void __cdecl Runtime_ForwardCall_00cb9cb0()
{
    ((S_00aa4060_Class*)&DAT_011f6238)->MemoryManager_Deallocate();
}
}  // namespace fnv_00cb9cb0

struct RefCountedStandIn
{
    virtual void Unk0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

struct ArgStandIn
{
    RefCountedStandIn* FUN_00a63430();
};

class FUN_00cb9ee0_cls
{
  public:
    void AssignRefCountedArray(ArgStandIn* arg);
    void FUN_00a7b3b0(ArgStandIn* arg);

    char unk00[0x10];
    RefCountedStandIn** m_10;
    unsigned int m_14;
};

// Calls FUN_00a7b3b0, then for each of m_14 slots swaps in arg->FUN_00a63430(), releasing the old ref and retaining the new one.
// @fnv 0x00cb9ee0
void FUN_00cb9ee0_cls::AssignRefCountedArray(ArgStandIn* arg)
{
    FUN_00a7b3b0(arg);
    for (unsigned int i = 0; i < m_14; i++)
    {
        RefCountedStandIn** slot = &m_10[i];
        RefCountedStandIn* pNew = arg->FUN_00a63430();
        RefCountedStandIn* old = *slot;
        if (old != pNew)
        {
            if (old != 0)
            {
                if (InterlockedDecrement(&old->m_uiRefCount) == 0)
                {
                    old->DeleteThis();
                }
            }
            *slot = pNew;
            if (pNew != 0)
            {
                InterlockedIncrement(&pNew->m_uiRefCount);
            }
        }
    }
}

class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BCB9F60Stream
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void SaveLinkID(void* pkObject);

  public:
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BCB9F60BinaryStream* m_pUnderlyingStream;
    BCB9F60BinaryStream* m_pBackingStream;
};

template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BCB9F60ExtraData
{
  public:
    void SaveBinary(BCB9F60Stream& kStream);
};

class BCB9F60LinkData : public BCB9F60ExtraData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppkObjects;
    unsigned int m_uiCount;

    void bhkRagdollTemplate_SaveBinary(BCB9F60Stream& kStream);
};

// Saves the base extra data, writes m_uiCount, then saves each link ID from m_ppkObjects.
// @fnv 0x00cb9f60
// src: XBOX_PDB 0x00cb9f60
void BCB9F60LinkData::bhkRagdollTemplate_SaveBinary(BCB9F60Stream& kStream)
{
    BCB9F60ExtraData::SaveBinary(kStream);
    unsigned int ItemUpdateArray = m_uiCount;
    BCB9F60SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        kStream.SaveLinkID(m_ppkObjects[i]);
}

// Releases the resource held by the object and resets it to its empty state.
typedef void(__stdcall* FreeFn)(void*);

struct FUN_00cb9fd0_cls
{
    void* m_ppVirtualMethodTable;
    void* m_pData;
    int m_i08;
    int m_i0c;
    void ResetAndFreeData();
};

// Sets the first pointer to DAT_010c8d00 and, if m_pData is non-null, frees it via DAT_010c8d08 and clears m_pData, m_i0c and m_i08.
// @fnv 0x00cb9fd0
void FUN_00cb9fd0_cls::ResetAndFreeData()
{
    void* pData = m_pData;
    m_ppVirtualMethodTable = (void*)&DAT_010c8d00;
    if (pData != 0)
    {
        FreeFn pFree = (FreeFn)DAT_010c8d08;
        pFree(pData);
        m_pData = 0;
        m_i0c = 0;
        m_i08 = 0;
    }
}

class FUN_00cba0d0_cls
{
  public:
    virtual void v0();
    virtual void v1();
    long m_04;
};

// For each of count items, decrements the reference count and calls v1() when it reaches zero.
// @fnv 0x00cba0d0
void __stdcall ReleaseItems(FUN_00cba0d0_cls** items, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        FUN_00cba0d0_cls* p = items[i];
        if (p != 0 && InterlockedDecrement(&p->m_04) == 0)
        {
            p->v1();
        }
    }
}

extern int(__stdcall* DAT_00fdf1c4)(void*);
void* __cdecl FUN_00a5b690(int flag);

class CBaseOwner
{
  public:
    virtual void unk00();
    unsigned int unk04;
    CBaseOwner();
    ~CBaseOwner();
};

class CSubA
{
  public:
    virtual void unkA00();
    unsigned int unkA04;
    unsigned int unkA08;
    unsigned int unkA0c;
    CSubA()
    {
        unkA04 = 0;
        unkA08 = 0;
        unkA0c = 0;
    }
    ~CSubA();
};

class CSubB
{
  public:
    virtual void unkB00();
    unsigned int unkB04;
    unsigned int unkB08;
    unsigned int unkB0c;
    CSubB()
    {
        unkB04 = 0;
        unkB08 = 0;
        unkB0c = 0;
    }
    ~CSubB();
};

class FUN_00cba110 : public CBaseOwner
{
  public:
    NiFixedString m_08;
    CSubA m_0c;
    CSubB m_1c;
    FUN_00cba110();
};

// @fnv 0x00cba110
FUN_00cba110::FUN_00cba110()
{
    char* p = m_08.m_kHandle;
    if (p != 0)
    {
        m_08.m_kHandle = (char*)FUN_00a5b690(0);
        if (p != NiGlobalStringTable::ms_pcEmptyString)
        {
            DAT_00fdf1c4((char*)p - 8);
        }
    }
}

extern int DAT_01268400;

// @fnv 0x00cba1c0
// src: COMMUNITY 0x00cba1c0
void* __cdecl bhkRagdollTemplateData_GetRTTI()
{
    return &DAT_01268400;
}

extern unsigned int DAT_01268418;

// @fnv 0x00cbbfb0
// src: COMMUNITY 0x00cbbfb0
void hkMemorySystem_replaceInstance(unsigned int a1)
{
    DAT_01268418 = a1;
}

namespace fnv_00cbc5e0 {
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);

struct FUN_00cbc550
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    static void* __cdecl operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    FUN_00cbc550();
};
// Allocates and constructs a new FUN_00cbc550 object, returning its pointer.
// @fnv 0x00cbc5e0
FUN_00cbc550* __cdecl CreateFUN_00cbc550()
{
    return new FUN_00cbc550;
}
}  // namespace fnv_00cbc5e0

namespace fnv_00cbc7b0 {
struct FUN_00aa3e40_class
{
    void* __thiscall Game_DoHeapAlloc(unsigned int size);
};

extern FUN_00aa3e40_class DAT_011f6238;

struct FUN_00cbc7b0_cls
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void __thiscall PushItem(void** pItem);
};

// @fnv 0x00cbc7b0
void FUN_00cbc7b0_cls::PushItem(void** pItem)
{
    void* item = *pItem;
    if (item)
    {
        if (m_iWordAt00)
        {
            void** n = (void**)DAT_011f6238.Game_DoHeapAlloc(8);
            if (n)
            {
                n[0] = m_iWordAt00;
                n[1] = 0;
            }
            else
            {
                n = 0;
            }
            n[1] = m_iWordAt04;
            m_iWordAt04 = n;
            item = *pItem;
        }
        m_iWordAt00 = item;
    }
}
}  // namespace fnv_00cbc7b0

// FUN_00cbd960 registers the 0x00cbd7a0 comparison helper in the global
// callback slot at 0x01268430, which is later called indirectly with two
// arguments (see the indirect call through 0x01268430).
extern void(__cdecl* DAT_01268430)(void*, void*);

void __cdecl InsertIntoContext(void* pList, void* pContext);

// @fnv 0x00cbd960
// src: COMMUNITY 0x00cbd960
void __cdecl hkpFixedBufferCdPointCollector_registerDefaultAddCdPointFunction(void)
{
    DAT_01268430 = &InsertIntoContext;
}

extern int DAT_01268434;

struct PrimaryBase
{
    virtual ~PrimaryBase();
};

struct HolderBase
{
    void Release();
};

struct FUN_00cbd970 : PrimaryBase
{
    int unk04;
    virtual ~FUN_00cbd970();
};

// Releases the holder and decrements the global counter DAT_01268434.
// @fnv 0x00cbd970
FUN_00cbd970::~FUN_00cbd970()
{
    ((HolderBase*)this)->Release();
    DAT_01268434--;
}

namespace fnv_00cbdcb0 {
struct CBDCB0Allocator
{
    virtual void vfunc00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct CBDCB0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBDCB0Allocator* m_pStreamAllocator;

    CBDCB0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CBDCB0MemoryRouter& __cdecl hkMemoryRouter_getInstance();

extern __declspec(thread) int g_CBDCB0AllocTag;

struct CBDCB0AllocTagScope
{
    int m_iSaved;

    CBDCB0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CBDCB0AllocTag;
        g_CBDCB0AllocTag = aiAllocationTag;
    }
    ~CBDCB0AllocTagScope()
    {
        g_CBDCB0AllocTag = m_iSaved;
    }
};

class CBDCB0Child
{
  public:
    CBDCB0Child();
    virtual ~CBDCB0Child();

    static void* operator new(unsigned int uiSize)
    {
        void* p = hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(uiSize);
        static_cast<CBDCB0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
};

class CBDCB0Owner
{
  public:
    int unk00;
    CBDCB0Child* m_pkChild;

    int EnsureChild();
};

// Creates m_pkChild with a new CBDCB0Child if it is null, then returns sizeof(CBDCB0Child).
// @fnv 0x00cbdcb0
int CBDCB0Owner::EnsureChild()
{
    CBDCB0AllocTagScope kScope(0x10);
    if (!m_pkChild)
        m_pkChild = new CBDCB0Child();
    return sizeof(CBDCB0Child);
}
}  // namespace fnv_00cbdcb0

struct WriteStream
{
    void* unk00;
    unsigned int transferred;
    void* unk08;
    int(__cdecl* write)(WriteStream*, const void*, unsigned int, unsigned int*, int);
};
struct BufferOwner
{
    void* unk00;
    unsigned char* buffer;
    void __thiscall hkConstraintCinfo_SaveBinary(void*);
    void __thiscall WriteToStream(void*);
};
// Calls FUN_00c8a280 on source, then writes two 64-byte blocks from buffer+0x20 and buffer+0x60 to the stream at source+0x250, accumulating transferred bytes.
// @fnv 0x00cbdf10
void BufferOwner::WriteToStream(void* source)
{
    hkConstraintCinfo_SaveBinary(source);
    unsigned char* data = buffer;
    WriteStream* __restrict stream = *(WriteStream**)((unsigned char*)source + 0x250);
    unsigned int length = 64;
    stream->transferred += stream->write(stream, data + 0x20, 64, &length, 1);
    stream = *(WriteStream**)((unsigned char*)source + 0x250);
    length = 64;
    stream->transferred += stream->write(stream, data + 0x60, 64, &length, 1);
}

extern "C" void _ReadWriteBarrier(void);
extern float DAT_0104da48;

struct FUN_00cbe820_sub
{
    void Init(float* value);
};

struct FUN_00cbe820_cls
{
    short m_00;
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84, m_88, m_8c;
    short m_90;
    short m_92;
    short m_94;
    unsigned char m_96;
    FUN_00cbe820_sub m_97;
    float m_98;

    FUN_00cbe820_cls* hkpHingeConstraintData_Atoms_Atoms();
};

// Initialises the object: sets m_00 to 2, m_90 to 0xc, m_94 to 5, m_96 to 0, calls m_97.Init with 1.0f, sets m_98 to DAT_0104da48, and returns this.
// @fnv 0x00cbe820
// src: HAVOK_LIB 0x00cbe820
FUN_00cbe820_cls* FUN_00cbe820_cls::hkpHingeConstraintData_Atoms_Atoms()
{
    float one = 1.0f;
    *(volatile short*)&m_00 = 2;
    _ReadWriteBarrier();
    *(volatile short*)&m_90 = 0xc;
    _ReadWriteBarrier();
    float* pOne = &one;
    m_94 = 5;
    m_96 = 0;
    m_97.Init(pOne);
    m_98 = DAT_0104da48;
    return this;
}

struct FUN_00cbe880_Class
{
    int m_iWordAt00;
    void __thiscall UpdateFields_00cbe880();
};

extern "C" void __cdecl FUN_00c9eec0();

// @fnv 0x00cbe880
// src: GUESS 0x00cbe880 (confidence: low)
void __thiscall FUN_00cbe880_Class::UpdateFields_00cbe880()
{
    this->m_iWordAt00 = 0x10c477c;
    FUN_00c9eec0();
}

unsigned char __stdcall bhkWorldObject_Add(void*);
void* __cdecl PackBytesBigEndian(int, int, int, int);
struct FUN_00c68e30_cls
{
    void __thiscall bhkWorld_SetDebugObjectColor(void* a, void* b);
};
struct FUN_00cbe890_cls
{
    int m_auiShapeKeys[7];
    unsigned char m_1c;
    unsigned char __thiscall bhkCollisionBox_Add(void* a);
};
// @fnv 0x00cbe890
// src: XBOX_PDB 0x00cbe890
unsigned char FUN_00cbe890_cls::bhkCollisionBox_Add(void* a)
{
    unsigned char r = 0;
    if (m_1c == 0)
    {
        unsigned char b = bhkWorldObject_Add(a);
        if (b)
        {
            void* p = PackBytesBigEndian(0x1e, 0x82, 0, 0x14);
            ((FUN_00c68e30_cls*)a)->bhkWorld_SetDebugObjectColor(this, p);
        }
        r = b;
    }
    return r;
}

namespace fnv_00cbf2d0 {
// FUN_00cbf2d0 : cdecl one-arg entry point.  When the argument is non null the
// game allocator is fetched from the global allocator holder and its virtual
// slot 2 is asked to release/store the block with a fixed 0x1c0 byte size.

struct AllocClass
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, unsigned int size);
};

struct HolderClass
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    AllocClass* m_pAllocator;
};

HolderClass* hkMemoryRouter_getInstance();

// If p is non-null, gets the holder from FUN_00c85750 and calls its allocator's v2 with p and size 0x1c0.
// @fnv 0x00cbf2d0
// src: GUESS 0x00cbf2d0 (confidence: low)
void __cdecl hkMemoryRouter_getInstance_UpdateState_00cbf2d0(void* p)
{
    if (p)
    {
        HolderClass* holder = hkMemoryRouter_getInstance();
        AllocClass* allocator = holder->m_pAllocator;
        allocator->v2(p, 0x1c0);
    }
}
}  // namespace fnv_00cbf2d0

namespace fnv_00cbf2f0 {
__declspec(thread) int fnvThreadMemoryBase;
__forceinline int& threadMemoryMode()
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(&fnvThreadMemoryBase) + 0x2b4);
}
struct MemoryContextScope
{
    int savedMode;
    __forceinline explicit MemoryContextScope(int n)
    {
        savedMode = threadMemoryMode();
        threadMemoryMode() = n;
    }
    __forceinline ~MemoryContextScope()
    {
        threadMemoryMode() = savedMode;
    }
};
struct ResourceOne
{
    void __thiscall ProcessEntries_00d055c0();
};
struct ResourceTwo
{
    void __thiscall FUN_00c905b0();
};
struct ResourceDisposer
{
    virtual void reserved0();
    virtual void reserved1();
    virtual void dispose(ResourceOne*, int);
};
struct ResourceService
{
    int unk00, unk04, unk08, unk0c;
    ResourceDisposer* disposer;
};
extern "C" ResourceService* __cdecl hkMemoryRouter_getInstance();
struct FUN_00cbf2f0_class
{
    int unk00, unk04, unk08;
    int active;
    int unk10;
    ResourceOne* first;
    ResourceTwo* second;
    void __thiscall bhkMultithreadedSystem_QuitMTSystem();
};
// @fnv 0x00cbf2f0
// src: COMMUNITY 0x00cbf2f0
void FUN_00cbf2f0_class::bhkMultithreadedSystem_QuitMTSystem()
{
    MemoryContextScope m_uiMemoryContext(0x10);
    if (active != 0)
    {
        ResourceOne* owned = first;
        if (owned != 0)
        {
            owned->ProcessEntries_00d055c0();
            ResourceService* s = hkMemoryRouter_getInstance();
            ResourceDisposer* p = s->disposer;
            p->dispose(owned, 0x1c0);
        }
        first = 0;
        if (second != 0)
            second->FUN_00c905b0();
        second = 0;
    }
    active = 0;
}
}  // namespace fnv_00cbf2f0

namespace fnv_00cbf3c0 {
struct SpawnedAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* p, unsigned int size);
};



hkMemoryRouter* hkMemoryRouter_getInstance();

struct FUN_00cbf3c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pData;
    int m_14;
    unsigned int m_18;

    void FreeData();
};

// @fnv 0x00cbf3c0
void FUN_00cbf3c0_cls::FreeData()
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    SpawnedAllocator* alloc = (SpawnedAllocator*)holder->m_heap;
    unsigned int flags = m_18;
    m_14 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(m_pData, (flags & 0x3fffffffu) * 4);
    }
    m_pData = 0;
    m_18 = 0x80000000u;
}
}  // namespace fnv_00cbf3c0

// Release the per-body lists: destroy every inner array, then free the outer array.

struct CBF490Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct CBF490MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CBF490Allocator* m_pStreamAllocator;

    CBF490Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" CBF490MemoryRouter& __cdecl CBF490GetMemoryRouter() throw();

template <class T> inline void CBF490Deallocate(CBF490Allocator& alloc, T* p, int numElem)
{
    alloc.ReturnMemory(p, numElem * sizeof(T));
}

template <class T> __forceinline void CBF490Destruct(T* p, int n)
{
    for (int i = 0; i < n; ++i)
        p[i].~T();
}

template <class T>
static __forceinline void CBF490Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void CBF490Array_ClearAndRelease(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void CBF490Array_destroy(hkArrayBase<T>& self) throw()
{
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, self.getCapacity() * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void CBF490Array_ClearAndRelease(hkArrayBase<T>& self) throw()
{
        CBF490Allocator& alloc = CBF490GetMemoryRouter().heap();
        CBF490Destruct(self.m_data, self.m_iElementCount);
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            CBF490Deallocate(alloc, self.m_data, self.getCapacity());
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct CBF490ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { CBF490Array_destroy(self); }
};

class CBF490Lists
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<hkArray<int, CBF490ArrayPolicy>, CBF490ArrayPolicy> m_kLists;

    void ClearLists();
};

// Clears the m_kLists array by destroying its elements and releasing its storage.
// @fnv 0x00cbf490
void CBF490Lists::ClearLists()
{
    CBF490Array_ClearAndRelease(m_kLists);
}




class CBFC60Dispatcher
{
  public:
    void SetEnableChecks(hkBool bEnable);
};

void __cdecl hkpListAgent_registerAgent(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpCollectionAgent3_registerAgent3(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpCollectionCollectionAgent3_registerAgent3(CBFC60Dispatcher* pkDispatcher);
void __cdecl RegisterConvexListAgentCollisionFuncs(CBFC60Dispatcher* pkDispatcher);
void __cdecl RegisterAgent3Entries(CBFC60Dispatcher* pkDispatcher);
void __cdecl hkpHeightFieldAgent_registerAgent(CBFC60Dispatcher* pkDispatcher);

// @fnv 0x00cbfc60
// src: HAVOK_LIB 0x00cbfc60
void __cdecl hkpAgentRegisterUtil__registerListAgents(CBFC60Dispatcher* pkDispatcher)
{
    hkpListAgent_registerAgent(pkDispatcher);
    pkDispatcher->SetEnableChecks(false);
    hkpCollectionAgent3_registerAgent3(pkDispatcher);
    hkpCollectionCollectionAgent3_registerAgent3(pkDispatcher);
    pkDispatcher->SetEnableChecks(true);
    RegisterConvexListAgentCollisionFuncs(pkDispatcher);
    RegisterAgent3Entries(pkDispatcher);
    hkpHeightFieldAgent_registerAgent(pkDispatcher);
}

struct TypedObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetKind();
};

struct PropHolder
{
    int unk00;
    int unk04;
    int unk08;
    TypedObj* pObj;
};

struct PassEntry
{
    PropHolder* pHolder;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct ShaderData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    PassEntry* pPasses;
    unsigned short usPassCount;
    unsigned short unkb2;
    PropHolder** ppExtra;
    int iExtraCount;
};

struct ShaderProp
{
    int unk00;
    int unk04;
    ShaderData* pData;
};

struct CastResult
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShaderProp* pShader;
};

struct RttiObject
{
    CastResult* DynamicCast(const void* type);
};

extern const int g_kShaderRtti;

struct GeomNode;

struct ChildNode
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    GeomNode** ppChildren;
    unsigned short unka4;
    unsigned short usChildCount;
};

struct GeomNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual ChildNode* GetAsNode();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    RttiObject* pProp;
};

struct GeomArray
{
    virtual void v00();
    virtual GeomNode** Allocate(unsigned int count);
    GeomNode** pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    void Grow(unsigned int newCap, unsigned int size);

    __forceinline void Add(GeomNode* p)
    {
        if (uiSize == uiCapacity)
        {
            if (uiCapacity == 0)
            {
                pData = Allocate(4);
                uiCapacity = 4;
            }
            else
            {
                unsigned int newCap = uiCapacity > 0x400 ? uiCapacity + 0x400 : uiCapacity * 2;
                Grow(newCap, uiSize);
                uiCapacity = newCap;
            }
        }
        pData[++uiSize - 1] = p;
    }
};

struct GeomCollector
{
    void CollectShaderNodes(GeomNode* pObj, GeomArray* pArray);
};

// Recursively collects GeomNodes whose shader has all passes of kind 11 and at least one extra of another kind into pArray, then descends into child nodes.
// @fnv 0x00ca0f00
void GeomCollector::CollectShaderNodes(GeomNode* pObj, GeomArray* pArray)
{
    if (!pObj)
        return;
    if (pObj->pProp)
    {
        CastResult* pCastResult = pObj->pProp->DynamicCast(&g_kShaderRtti);
        if (pCastResult && pCastResult->pShader)
        {
            ShaderData* pData = pCastResult->pShader->pData;
            if (pData)
            {
                bool bAllPassesKind11 = true;
                for (int i = 0; i < pData->usPassCount; i++)
                {
                    if (!bAllPassesKind11)
                        break;
                    TypedObj* pPassObj = pData->pPasses[i].pHolder->pObj;
                    bAllPassesKind11 = pPassObj->GetKind() == 11;
                }
                bool bAnyExtraOtherKind = false;
                for (int j = 0; j < pData->iExtraCount; j++)
                {
                    if (bAnyExtraOtherKind)
                        break;
                    bAnyExtraOtherKind = pData->ppExtra[j]->pObj->GetKind() != 11;
                }
                if (bAllPassesKind11 && bAnyExtraOtherKind)
                    pArray->Add(pObj);
            }
        }
    }
    ChildNode* pChildNode = pObj->GetAsNode();
    if (pChildNode)
    {
        for (unsigned int k = 0; k < pChildNode->usChildCount; k++)
            CollectShaderNodes(pChildNode->ppChildren[k], pArray);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);


class PrimaryCA3
{
  public:
    virtual ~PrimaryCA3()
    {}

    int unk04, unk08, unk0C;
};
class SecondaryCA3
{
  public:
    virtual ~SecondaryCA3()
    {}
};
class BaseCA3 : public PrimaryCA3, public SecondaryCA3
{
  public:
    virtual ~BaseCA3()
    {}

    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50;
    int unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70;
    int unk74, unk78, unk7C, unk80;
};
class FUN_00ca3b90 : public BaseCA3
{
  public:
    virtual ~FUN_00ca3b90();

    NiPointer<NiRefObject> m_pReferencedObject;
};
// Destructor that releases the held reference by assigning null to the NiPointer, decrementing the object's ref count.
// @fnv 0x00ca3b90
FUN_00ca3b90::~FUN_00ca3b90()
{
    m_pReferencedObject = 0;
}
// The pack prelude keeps only the declaration of this file-static helper (used by a
// neighbouring function's function-pointer table); provide its body so the unit links.

void* NiMalloc(unsigned int size);
void NiFree(void* p);

struct RefCounted
{
    virtual ~RefCounted();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct PtrEntry
{
    NiPointer<RefCounted> m_pReferencedObject;
    int m_iValue;
    PtrEntry() : m_pReferencedObject(0), m_iValue(0)
    {}
    bool operator==(const PtrEntry& other) const
    {
        return m_pReferencedObject == other.m_pReferencedObject && m_iValue == other.m_iValue;
    }
    bool operator!=(const PtrEntry& other) const
    {
        return !(*this == other);
    }
};

typedef NiTLargeArray<PtrEntry, NiTMallocInterface<PtrEntry> > PtrEntryArray;


// Resizes the array to uiMaxSize: clears and shrinks the size if smaller, reallocates the buffer, copies existing entries and default-initialises the rest.
// @fnv 0x00ca47f0
template <> void NiTLargeArray<PtrEntry, NiTMallocInterface<PtrEntry> >::SetSize(unsigned int uiNewMaxSize)
{
    if (uiNewMaxSize == m_uiMaxSize)
        return;

    unsigned int i;
    if (uiNewMaxSize < m_uiSize)
    {
        for (i = uiNewMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != PtrEntry())
            {
                m_pBase[i] = PtrEntry();
                m_uiESize--;
            }
        }
        m_uiSize = uiNewMaxSize;
    }

    PtrEntry* pOldEntries = m_pBase;
    m_uiMaxSize = uiNewMaxSize;
    if (uiNewMaxSize > 0)
    {
        m_pBase = (PtrEntry*)NiMalloc(sizeof(PtrEntry) * m_uiMaxSize);
        for (i = 0; i < m_uiSize; i++)
            m_pBase[i] = pOldEntries[i];
        for (i = m_uiSize; i < m_uiMaxSize; i++)
            m_pBase[i] = PtrEntry();
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pOldEntries);
}

// Prelude helper whose body the unit prelude omits.
// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.
extern __declspec(thread) int g_iCA56B0AllocTag;
struct CA56B0AllocTagScope
{
    int m_iSaved;

    CA56B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA56B0AllocTag;
        g_iCA56B0AllocTag = aiAllocationTag;
    }
    ~CA56B0AllocTagScope()
    {
        g_iCA56B0AllocTag = m_iSaved;
    }
};
void CA56B0Lock();
void CA56B0Unlock();
class CA56B0RefObject
{
  public:
    CA56B0RefObject();
    virtual ~CA56B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};
class CA56B0Shape : public CA56B0RefObject
{
  public:
    CA56B0Shape() : m_pUserData(0), m_pkExtra(0)
    {
        ++ms_iCount;
    }
    virtual ~CA56B0Shape();

    void* m_pUserData;
    void* m_pkExtra;

    static int ms_iCount;
};
class CA56B0MidShape : public CA56B0Shape
{
  public:
    CA56B0MidShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0MidShape();

    static int ms_iCount;
};
class CA56B0ListShape : public CA56B0MidShape
{
  public:
    CA56B0ListShape()
    {
        ++ms_iCount;
    }
    virtual ~CA56B0ListShape();

    static int ms_iCount;
};
class CA56B0Owner
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual void Unk5C();
    virtual void Unk60();
    virtual void Unk64();
    virtual void Unk68();
    virtual void Unk6C();
    virtual void Unk70();
    virtual void Unk74();
    virtual void Unk78();
    virtual void Unk7C();
    virtual void Unk80();
    virtual void Unk84();
    virtual void Unk88();
    virtual void Unk8C();
    virtual void Unk90();
    virtual void Unk94();
    virtual void Unk98();
    virtual void Unk9C();
    virtual void UnkA0();
    virtual void UnkA4();
    virtual void UnkA8();
    virtual void UnkAC();
    virtual void UnkB0();
    virtual void UnkB4();
    virtual void UnkB8();
    virtual void UnkBC();
    virtual void UnkC0();
    virtual void AddShape(CA56B0Shape* pkShape, int iIndex);

    CA56B0Shape* CreateListShape(int iIndex);
};
// Allocates a CA56B0ListShape under an alloc tag and lock, adds it to the owner at iIndex, unlocks, and returns the shape.
// @fnv 0x00ca56b0
CA56B0Shape* CA56B0Owner::CreateListShape(int iIndex)
{
    CA56B0AllocTagScope kScope(0x10);
    CA56B0Lock();
    CA56B0Shape* pkShape = new CA56B0ListShape;
    AddShape(pkShape, iIndex);
    CA56B0Unlock();
    return pkShape;
}

struct ReadBin
{
    int unk00;
    unsigned int position;
    unsigned int(__cdecl* read)(ReadBin*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes, unsigned int* sizes, unsigned int n)
    {
        position += read(this, data, bytes, sizes, n);
    }
};
template <class T> inline void Load(ReadBin& bin, T* data, unsigned int n)
{
    unsigned int size = sizeof(T);
    bin.Read(data, n * sizeof(T), &size, 1);
}
struct ReadStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    ReadBin* binary;
    void ReadLinkID();
};
struct ReadData
{
    int unk00, unk04;
    int value08;
    int unk0c;
    float vector10[4];
};
struct CA5940
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual ReadData* GetData(char* out);
    void bhkShape_LoadBinary(ReadStream* stream);
    void ReadDataFromStream(ReadStream* stream);
};
// Reads a value and a 4-float vector from the stream into the object's ReadData, then calls FUN_00a645b0.
// @fnv 0x00ca5940
void CA5940::ReadDataFromStream(ReadStream* stream)
{
    char temporary;
    ReadData* data = GetData(&temporary);
    bhkShape_LoadBinary(stream);
    Load(*stream->binary, &data->value08, 1);
    unsigned int size2 = 4;
    stream->binary->Read(data->vector10, 16, &size2, 1);
    stream->ReadLinkID();
}

extern __declspec(thread) int g_CA6E60AllocTag;
struct CA6E60AllocTagScope
{
    int m_iSaved;

    CA6E60AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_CA6E60AllocTag;
        g_CA6E60AllocTag = aiAllocationTag;
    }
    ~CA6E60AllocTagScope()
    {
        g_CA6E60AllocTag = m_iSaved;
    }
};
class CA6E60Buffer
{
  public:
    virtual ~CA6E60Buffer()
    {
        NiFreeAlias(m_pResource);
    }

    void* m_pResource;
};
class CA6E60Data
{
  public:
    static void operator delete(void* pvMem)
    {
        unsigned char ucOffset = static_cast<unsigned char*>(pvMem)[-1];
        _g_memoryManager.Deallocate(static_cast<char*>(pvMem) - ucOffset);
    }

    int unk00;
    int unk04;
    CA6E60Buffer m_kBuffer;
};
class CA6E60Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    CA6E60Data* m_pUserData;

    void ReleaseData(bool bRelease);
};
// Sets the thread-local allocation tag to 0x10 and, when bRelease is true, deletes the owned data object and clears the pointer.
// @fnv 0x00ca6e60
void CA6E60Owner::ReleaseData(bool bRelease)
{
    CA6E60AllocTagScope kScope(0x10);
    if (bRelease)
    {
        delete m_pUserData;
        m_pUserData = 0;
    }
}

inline void StrArr::AppendReference(char*& value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, value);
}
__forceinline void StrArr::Append(char* value)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value)
            ++m_usESize;
    }
    else if (value)
    {
        if (!m_pBase[index])
            ++m_usESize;
    }
    else if (m_pBase[index])
    {
        m_usESize += (unsigned short)-1;
    }
    m_pBase[index] = value;
}

extern char* DAT_012682e8;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char*);
char* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
struct PartFlags
{
    void* vtable;
    int references;
    int unk08;
    unsigned short flags;
};
struct PartValue
{
    int value;
    void AppendToViewerStrings(StrArr* output);
};
struct DiagnosticShape : S_00ca6810_Class
{
    void bhkShapeCollection_GetViewerStrings(StrArr* output);
    void AppendSubpartDiagnostics(StrArr* output);
    unsigned int Count() const
    {
        return this && unk08 ? (unsigned int)unk08->unkA0 : 0;
    }
    S_00ca6810_Entry& Part(unsigned int index) const
    {
        if (this && unk08)
            return unk08->unk98[index];
        return *reinterpret_cast<S_00ca6810_Entry*>(&DAT_012682f0);
    }
};
// Appends a name, a Subparts count, then MATERIAL and value entries for up to the first 5 parts and the last 3 parts when the count exceeds 5.
// @fnv 0x00ca6f10
void DiagnosticShape::AppendSubpartDiagnostics(StrArr* output)
{
    unsigned int count;
    TlsGuard_t guard;
    bhkShapeCollection_GetViewerStrings(output);
    {
        char* name = NiViewerStrings_NiGetViewerString_Title(DAT_012682e8);
        output->AppendReference(name);
    }
    unsigned int leadingCount = Count();
    count = leadingCount;
    {
        char* countText = NiGetViewerString_00a7d510("Subparts", count);
        output->AppendReference(countText);
    }
    unsigned int trailingCount = 0;
    if (leadingCount > 5)
    {
        leadingCount = 5;
        trailingCount = count - leadingCount;
        if (trailingCount > 3)
            trailingCount = 3;
    }
    for (unsigned int index = 0; index < leadingCount; ++index)
    {
        output->Append(NiGetViewerString_00a7d510("Part", index));
        S_00ca6810_Entry& part = Part(index);
        PartFlags* flags = reinterpret_cast<PartFlags*>(part.callable);
        output->Append(NiGetViewerString_00a7d4d0("MATERIAL", flags ? (flags->flags >> 6) & 31 : 0));
        PartValue value;
        value.value = part.unk04;
        value.AppendToViewerStrings(output);
    }
    for (unsigned int index = 0; index < trailingCount; ++index)
    {
        unsigned int partIndex = count - index - 1;
        output->Append(NiGetViewerString_00a7d510("Part", partIndex));
        S_00ca6810_Entry& part = Part(partIndex);
        PartFlags* flags = reinterpret_cast<PartFlags*>(part.callable);
        output->Append(NiGetViewerString_00a7d4d0("MATERIAL", flags ? (flags->flags >> 6) & 31 : 0));
        PartValue value;
        value.value = part.unk04;
        value.AppendToViewerStrings(output);
    }
}

struct LockFlag_t
{
    bool m_kPointB;
    LockFlag_t(bool b) : m_kPointB(b)
    {}
    LockFlag_t(const LockFlag_t& o) : m_kPointB(o.m_kPointB)
    {}
};

struct WorldLock_t
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Mark(unsigned int id, LockFlag_t flag);
};
extern WorldLock_t* g_pWorldLock_01268360;

struct CAC300Allocator
{
    virtual void fn00();
    virtual void* Alloc(unsigned int size);
};

struct CharacterProxyObject : public hkReferencedObject
{
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;

    CharacterProxyObject(int arg);

    static void* operator new(unsigned int size)
    {
        FNVTaskMemoryRouter* router = hkMemoryRouter_getInstance();
        CharacterProxyObject* p = (CharacterProxyObject*)((CAC300Allocator*)router->allocator)->Alloc(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};

struct CAC300Owner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void SetObject(hkReferencedObject* obj);
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void Apply(int arg);

    void bhkCharacterProxy_Init(int arg);
};

// Marks the world lock, allocates an hkReferencedObject with arg, hands it to SetObject, releases it, then calls Apply(arg).
// @fnv 0x00cac300
// src: XBOX_PDB 0x00cac300
void CAC300Owner::bhkCharacterProxy_Init(int arg)
{
    TlsGuard_t guard;
    WorldLock_t* lock = g_pWorldLock_01268360;
    lock->Mark(0x6cee9071, LockFlag_t(false));
    hkReferencedObject* obj = new CharacterProxyObject(arg);
    lock->Mark(0x6cee9071, LockFlag_t(true));
    SetObject(obj);
    obj->removeReference();
    Apply(arg);
}

// Prelude helper whose body the unit prelude omits.
// Factory: create a new 0x40-byte object.
class BA2D0Object
{
  public:
    BA2D0Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

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
};
// Allocates and constructs a new BA2D0Object, returning the pointer.
// @fnv 0x00cba2d0
BA2D0Object* CreateBA2D0Object()
{
    return new BA2D0Object;
}

// Destructor that calls RemoveAll to clear the map's entries.
// @fnv 0x00cbc740
template <>
NiTMap<NiAVObject*, BSSimpleList<bhkLiquidAction*>*>::~NiTMap()
{
    RemoveAll();
}

namespace fnv_00cbdf80 {


NiPoint3& __cdecl HK2NINS(NiPoint3& result, const hkVector4& value);

struct ConstraintVectors
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    hkVector4 perpendicular1;
    hkVector4 perpendicular2;
    hkVector4 pivotA;
    hkVector4 axleB;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    hkVector4 pivotB;
};
struct ConstraintOwner
{
    void* vtable;
    ConstraintVectors* data;
    void hkConstraintCinfo_GetViewerStrings(StrArr* output);
    void AppendConstraintVectors(StrArr* output);
};
// @fnv 0x00cbdf80
void ConstraintOwner::AppendConstraintVectors(StrArr* output)
{
    TlsGuard_t context;
    hkConstraintCinfo_GetViewerStrings(output);
    ConstraintVectors* vectors = data;
    if (vectors)
    {
        NiPoint3 point;
        HK2NINS(point, vectors->pivotA);
        char* text = ((const NiPoint3&)point).FormatToBuffer("PivotInA");
        output->AppendReference(text);
        HK2NINS(point, vectors->pivotB);
        text = ((const NiPoint3&)point).FormatToBuffer("PivotInB");
        output->AppendReference(text);
        HK2NINS(point, vectors->axleB);
        text = ((const NiPoint3&)point).FormatToBuffer("AxleInB");
        output->AppendReference(text);
        HK2NINS(point, vectors->perpendicular1);
        text = ((const NiPoint3&)point).FormatToBuffer("Perp2AxleInA1");
        output->AppendReference(text);
        HK2NINS(point, vectors->perpendicular2);
        text = ((const NiPoint3&)point).FormatToBuffer("Perp2AxleInA2");
        output->AppendReference(text);
    }
}
}  // namespace fnv_00cbdf80

extern __declspec(thread) int g_iCBEA40AllocTag;
struct BCBEA40AllocTagScope
{
    int m_iSaved;

    BCBEA40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCBEA40AllocTag;
        g_iCBEA40AllocTag = aiAllocationTag;
    }
    ~BCBEA40AllocTagScope()
    {
        g_iCBEA40AllocTag = m_iSaved;
    }
};
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > BCBEA40StringArray;
extern const char* g_pcCBEA40Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class BCBEA40Owner
{
  public:
    void bhkSimpleShapePhantom_GetViewerStrings(BCBEA40StringArray* pkArray);
    void AddNameToArray(BCBEA40StringArray* pkArray);
};
// Sets an allocation tag scope, calls FUN_00c9f270 on the array, then appends the string from g_pcCBEA40Name to it.
// @fnv 0x00cbea40
void BCBEA40Owner::AddNameToArray(BCBEA40StringArray* pkArray)
{
    BCBEA40AllocTagScope kScope(0x10);
    bhkSimpleShapePhantom_GetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCBEA40Name);
    pkArray->Add(pcName);
}

namespace fnv_00cbf540 {




hkMemoryRouter* hkMemoryRouter_getInstance();

inline void* hkAllocateChunkStub(int nbytes)
{
    return GetRouterHeap(hkMemoryRouter_getInstance()).blockAlloc(nbytes);
}

inline void hkDeallocateChunkStub(void* p, int nbytes)
{
    GetRouterHeap(hkMemoryRouter_getInstance()).bufFree(p, nbytes);
}

extern __declspec(thread) int g_tlsScopeValue;

struct TlsScopeGuard
{
    int m_saved;
    TlsScopeGuard()
    {
        m_saved = g_tlsScopeValue;
        g_tlsScopeValue = 0x10;
    }
    ~TlsScopeGuard()
    {
        g_tlsScopeValue = m_saved;
    }
};

static __forceinline void hkPtrArrayStub_destroy(hkArrayBase<void*>& self);

static __forceinline void hkPtrArrayStub_destroy(hkArrayBase<void*>& self)
{
        hkMemoryRouter* mem = hkMemoryRouter_getInstance();
        hkMemoryAllocator* alloc = &GetRouterHeap(mem);
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc->bufFree(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(void*));
    }

struct hkPtrArrayStubPolicy
{
    static __forceinline void destroy(hkArrayBase<void*>& self) { hkPtrArrayStub_destroy(self); }
};

struct CinfoA
{
    int m_iWordAt00;
    int unk04;
    int unk08;
    int unk0c;
    hkArray<void*, hkPtrArrayStubPolicy> m_ppData;
    int unk1c;
    CinfoA();
};

struct ObjB
{
    int unk000;
    unsigned short m_usMemSizeAndFlags;
    unsigned short unk006;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;

    static void* operator new(unsigned int nbytes)
    {
        ObjB* b = (ObjB*)hkAllocateChunkStub(nbytes);
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        GetRouterHeap(hkMemoryRouter_getInstance()).bufFree(p, ((ObjB*)p)->m_usMemSizeAndFlags);
    }
    ObjB(CinfoA* info);
};

struct CinfoCBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    CinfoCBase();
};

struct CinfoC : CinfoCBase
{
    CinfoC()
    {
        m_18 = 10;
    }
    ~CinfoC();
};

struct ObjD
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;

    static void* operator new(unsigned int nbytes)
    {
        return hkAllocateChunkStub(nbytes);
    }
    static void operator delete(void* p, unsigned int nbytes)
    {
        hkDeallocateChunkStub(p, nbytes);
    }
    ObjD(CinfoC* info);
};

void __cdecl InitHookTable(ObjD* d);

struct FUN_00cbf540_Owner
{
    int unk00;
    int m_iWordAt04;
    int unk08;
    int m_iThirdValue;
    int unk10;
    ObjD* m_14;
    ObjB* m_18;
    void Setup();
    void CreateObjects(int* key, int unused);
};

// @fnv 0x00cbf540
void FUN_00cbf540_Owner::CreateObjects(int* key, int unused)
{
    TlsScopeGuard guard;
    Setup();
    m_iThirdValue = *key;
    CinfoA a;
    a.m_iWordAt00 = m_iWordAt04;
    m_18 = new ObjB(&a);
    CinfoC c;
    m_14 = new ObjD(&c);
    InitHookTable(m_14);
}
}  // namespace fnv_00cbf540

// Registers a batch of classes with the registry while it is temporarily locked.
class CBFC10Bool
{
  public:
    CBFC10Bool(bool b)
    {
        m_cBool = (char)b;
    }
    char m_cBool;
};
class CBFC10Registry
{
  public:
    void Set(CBFC10Bool bLocked);
};
void __cdecl CBFC10RegisterA(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterB(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterC(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterD(CBFC10Registry* pkRegistry);
void __cdecl CBFC10RegisterE(CBFC10Registry* pkRegistry);
// @fnv 0x00cbfc10
void __cdecl RegisterAll(CBFC10Registry* pkRegistry)
{
    pkRegistry->Set(false);
    CBFC10RegisterA(pkRegistry);
    CBFC10RegisterB(pkRegistry);
    CBFC10RegisterC(pkRegistry);
    CBFC10RegisterD(pkRegistry);
    CBFC10RegisterE(pkRegistry);
    pkRegistry->Set(true);
}

extern unsigned int DAT_011b1730;
extern unsigned int DAT_011b1734;

struct FUN_00ca3dc0_cls
{
    int unk00;
    int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned short m_10;
    unsigned short unk12;
    void* m_14;
    void* m_18;
    int unk1C;
    void* m_20;
    void* m_24;
    void __thiscall hkPackedNiTriStripsData_SaveBinary(S_00ca59d0_Stream* s);
};

// Serializes m_08, m_0c, a flag for m_20, m_10 and their buffers to the stream via S_00ca59d0_Save and Write.
// @fnv 0x00ca3dc0
// src: XBOX_PDB 0x00ca3dc0
void __thiscall FUN_00ca3dc0_cls::hkPackedNiTriStripsData_SaveBinary(S_00ca59d0_Stream* pStream)
{
    S_00ca59d0_Save(*pStream->unk250, &m_08, 1);
    pStream->unk250->Write(m_14, m_08 * 8, &DAT_011b1734, 4);
    S_00ca59d0_Save(*pStream->unk250, &m_0c, 1);
    bool v = m_20 != 0;
    S_00ca59d0_Save(*pStream->unk250, &v, 1);
    if (!v)
    {
        pStream->unk250->Write(m_18, m_0c * 12, &DAT_011b1730, 1);
    }
    else
    {
        unsigned int cs = 2;
        pStream->unk250->Write(m_20, m_0c * 6, &cs, 1);
    }
    S_00ca59d0_Save(*pStream->unk250, &m_10, 1);
    pStream->unk250->Write(m_24, m_10 * 12, &DAT_011b1730, 1);
}

struct SArr046
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char*& value);
    void AppendReference(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, value);
    }
    __forceinline void Append(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
        {
            m_usESize += (unsigned short)-1;
        }
        m_pBase[index] = value;
    }
};

struct InnerEntry046
{
    void* f0;
    int f4;
    void* f8;
};
struct Inner046
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short m_uiItemCount;
    unsigned short unk12;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    InnerEntry046* m_entries;
};
struct SubObj046
{
    int unk00[0x21];
    Inner046* m_84;
};
struct NodePtr046
{
    void* m_p;
    void AppendToViewerStrings(SArr046* arr);
};

extern int DAT_012682dc;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* a);
char* __cdecl NiGetViewerString_00a7d510(const char* s, unsigned int n);
char* __cdecl NiGetViewerString_00a7d4d0(const char* s, int n);

struct ThisCls046
{
    int unk00;
    int unk04;
    SubObj046* m_8;
    void bhkShapeCollection_GetViewerStrings(SArr046* arr);
    void AppendSubpartNames(SArr046* arr);
};

// @fnv 0x00ca5b20
void ThisCls046::AppendSubpartNames(SArr046* arr)
{
    TlsGuard_t guard;
    bhkShapeCollection_GetViewerStrings(arr);
    char* v1 = NiViewerStrings_NiGetViewerString_Title((char*)DAT_012682dc);
    arr->AppendReference(v1);
    SubObj046* sub = this ? m_8 : 0;
    unsigned int n = sub->m_84->m_uiItemCount;
    char* v2 = NiGetViewerString_00a7d510("Subparts", n);
    arr->AppendReference(v2);
    if (n > 5)
        n = 5;
    for (unsigned int i = 0; i < n; ++i)
    {
        char* p = NiGetViewerString_00a7d510("Part", i);
        arr->Append(p);
        NodePtr046 nodePtr;
        nodePtr.m_p = sub->m_84->m_entries[i].f0;
        nodePtr.AppendToViewerStrings(arr);
        Inner046* pInner = sub->m_84;
        char* m = NiGetViewerString_00a7d4d0("MATERIAL", (int)pInner->m_entries[i].f8);
        arr->Append(m);
    }
}





// Storage for an existing collector. The shared collector is abstract, so its
// complete destructor is called explicitly rather than instantiating it here.
struct CharacterCollectorStorage
{
    unsigned char storage[sizeof(bhkCharacterPointCollector)];

    ~CharacterCollectorStorage()
    {
        ((bhkCharacterPointCollector*)this)->bhkCharacterPointCollector::~bhkCharacterPointCollector();
    }
};

extern int DAT_01268340;

class FUN_00cabf50 : public bhkSerializable
{
  public:
    virtual ~FUN_00cabf50();
    int m_0c;
    CharacterCollectorStorage m_kCollector;
    void bhkSerializable_Kill();
};

// @fnv 0x00cabf50
FUN_00cabf50::~FUN_00cabf50()
{
    ((bhkSerializable*)this)->v37();
    bhkSerializable_Kill();
    --DAT_01268340;
}

struct LinkedObject
{
    int unk00[2];
    int m_iValue;  // +0x08
};

struct LinkStream
{
    LinkedObject* FUN_00a63430();
};

class LinkBase
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual LandTextureParameters* GetHavokData(char& rcFlag);  // +0xb4
    void bhkSerializable_LinkObject(LinkStream& kStream);                     // base LinkObject
};

class LinkWrapper : public LinkBase
{
  public:
    void CopyHavokValueFromStream(LinkStream& kStream);
};

// @fnv 0x00cac030
void LinkWrapper::CopyHavokValueFromStream(LinkStream& kStream)
{
    LinkedObject* pkObject = kStream.FUN_00a63430();
    char cFlag;
    LandTextureParameters* pkData = GetHavokData(cFlag);
    if (pkObject)
        pkData->m_iValue = pkObject->m_iValue;
    LinkBase::bhkSerializable_LinkObject(kStream);
}

struct FUN_00cb9d80_child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(void* context);
};

typedef int(__cdecl* FUN_00cb9d80_read_fn)(void* stream, void* data, unsigned int size, void* result, int flag);

struct FUN_00cb9d80_stream
{
    int unk00;
    int position;
    int unk08;
    FUN_00cb9d80_read_fn read;
};

struct FUN_00a641f0_class
{
    void __thiscall WriteObjectLink(void* object);
};

void __stdcall nullsub_3(void* context);

struct FUN_00cb9d80_class
{
    int unk00;
    int unk04;
    int* unk08;
    int unk0c;
    FUN_00cb9d80_child** unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int* unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;

    void __thiscall ReadFromStream(void* context);
};

// @fnv 0x00cb9d80
void __thiscall FUN_00cb9d80_class::ReadFromStream(void* context)
{
    nullsub_3(context);
    unsigned int count = unk14;
    ((FUN_00a641f0_class*)context)->WriteObjectLink(&unk08);

    unsigned int size = 4;

    FUN_00cb9d80_stream* stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk2c, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk30, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk34, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk38, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &unk3c, size, &temp, 1);
    }
    stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
    {
        int temp = size;
        stream->position += stream->read(stream, &count, size, &temp, 1);
    }

    for (unsigned int i = 0; i < count; ++i)
    {
        unsigned int value = unk20[i];
        stream = *(FUN_00cb9d80_stream**)((char*)context + 0x250);
        {
            int temp = size;
            stream->position += stream->read(stream, &value, size, &temp, 1);
        }
    }

    for (unsigned int i = 0; i < count; ++i)
    {
        unk10[i]->v0c(context);
    }
}

struct StandInBinaryStream
{
    int m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(StandInBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void BinaryStreamLoad(StandInBinaryStream& kIs, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kIs.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

template <class T> inline void StreamRead(NiStream& kStream, T& val)
{
    BinaryStreamLoad(**(StandInBinaryStream**)((char*)&kStream + 0x24c), &val, 1);
}

struct MemoryManager_t
{
    void* Game_DoHeapAlloc(unsigned int size);
};

__forceinline void* BaseCinfo_blk_00ca0000_o2::operator new(size_t size) throw()
{
    return ((MemoryManager_t*)&DAT_011f6238)->Game_DoHeapAlloc(size);
}

__forceinline void BaseCinfo_blk_00ca0000_o2::operator delete(void*)
{}

__forceinline void BaseCinfo_blk_00ca0000_o2::LoadBinary(NiStream& kStream)
{
    ((void(__thiscall*)(BaseCinfo_blk_00ca0000_o2*, NiStream&))(*(void***)this)[2])(this, kStream);
}

extern int DAT_0108ff98;
extern int DAT_010c5dc0;
extern int DAT_010c8288;
extern int DAT_010c8cc8;
extern int DAT_010c8ce4;

struct Cinfo_13 : public BaseCinfo_blk_00ca0000_o2
{
    __forceinline Cinfo_13()
    {
        unk00 = (unsigned int)&DAT_010c8288;
    }
    void LoadBinary(NiStream& kStream);
};
struct Cinfo_0 : public BaseCinfo_blk_00ca0000_o2
{
    __forceinline Cinfo_0()
    {
        unk00 = (unsigned int)&DAT_010c8cc8;
    }
    void LoadBinary(NiStream& kStream);
};
struct Cinfo_1 : public BaseCinfo_blk_00ca0000_o2
{
    __forceinline Cinfo_1()
    {
        unk00 = (unsigned int)&DAT_0108ff98;
    }
    void LoadBinary(NiStream& kStream);
};
struct Cinfo_2 : public BaseCinfo_blk_00ca0000_o2
{
    __forceinline Cinfo_2()
    {
        unk00 = (unsigned int)&DAT_010c5dc0;
    }
    void LoadBinary(NiStream& kStream);
};
struct Cinfo_7 : public BaseCinfo_blk_00ca0000_o2
{
    __forceinline Cinfo_7()
    {
        unk00 = (unsigned int)&DAT_010c8ce4;
    }
    void LoadBinary(NiStream& kStream);
};




// Loads the ragdoll template data: name link, five ints, a count, type array, then allocates and loads a Cinfo per type.
// @fnv 0x00cba340
void bhkRagdollTemplateData::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    kStream.ReadStringTableEntry(*(NiFixedString*)&m_kName);

    StreamRead(kStream, m_2c);
    StreamRead(kStream, m_30);
    StreamRead(kStream, m_34);
    StreamRead(kStream, m_38);
    StreamRead(kStream, m_3c);

    unsigned int ItemUpdateArray = 0;
    StreamRead(kStream, ItemUpdateArray);

    m_kArray1.SetSize(ItemUpdateArray);
    m_kArray2.SetSize(ItemUpdateArray);

    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiType;
        StreamRead(kStream, uiType);
        ((unsigned int*)m_kArray2.m_pBuffer)[i] = uiType;
    }

    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        unsigned int uiType = ((unsigned int*)m_kArray2.m_pBuffer)[i];
        BaseCinfo_blk_00ca0000_o2* pCinfo = 0;
        switch (uiType)
        {
        case 13:
            pCinfo = new Cinfo_13();
            m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        case 0:
            m_kArray1.m_pBuffer[i] = new Cinfo_0();
            break;
        case 1:
            pCinfo = new Cinfo_1();
            m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        case 2:
            m_kArray1.m_pBuffer[i] = new Cinfo_2();
            break;
        case 7:
            pCinfo = new Cinfo_7();
            m_kArray1.m_pBuffer[i] = pCinfo;
            break;
        }
        BaseCinfo_blk_00ca0000_o2* pObj = (BaseCinfo_blk_00ca0000_o2*)m_kArray1.m_pBuffer[i];
        pObj->LoadBinary(kStream);
    }
}

struct FUN_00ca0ca0_Class
{
    void* m_vtbl;
    FUN_00ca0ca0_Class* __thiscall FUN_00ca0ca0(int flags);
};

struct MemMgr_00aa4060
{
    void __thiscall MemoryManager_Deallocate(FUN_00ca0ca0_Class* p);
};

extern int DAT_010c7304;

// Sets the vtable pointer and, when flags has bit 0 set, passes this to FUN_00aa4060 on DAT_011f6238, then returns this.
// @fnv 0x00ca0ca0
FUN_00ca0ca0_Class* __thiscall FUN_00ca0ca0_Class::FUN_00ca0ca0(int flags)
{
    m_vtbl = &DAT_010c7304;
    if (flags & 1)
        ((MemMgr_00aa4060*)&DAT_011f6238)->MemoryManager_Deallocate(this);
    return this;
}

struct WalkPlacement
{
};
inline void* operator new(unsigned int, WalkPlacement, void* p)
{
    return p;
}
struct WalkRTTI
{
    const char* name;
    WalkRTTI* parent;
};
extern WalkRTTI DAT_01267b70, DAT_0126817c;
extern int DAT_0126818c;
struct WalkObject
{
    virtual void v0();
    virtual void v4();
    virtual WalkRTTI* GetRTTI();
    int ref;
    struct WalkBody* body;
    struct WalkType* fallback;
    WalkObject* FUN_00653290(const WalkRTTI*);
    __forceinline WalkObject* AsItem()
    {
        if (!this)
            return 0;
        return IsKind(&DAT_0126818c) ? this : 0;
    }
    bool IsKind(const void* type)
    {
        for (WalkRTTI* r = GetRTTI(); r; r = r->parent)
            if (r == type)
                return true;
        return false;
    }
};
inline WalkObject* KindCast(WalkObject* item)
{
    if (!item)
        return 0;
    return item->IsKind(&DAT_0126818c) ? item : 0;
}
struct WalkType
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int GetType();
};
struct WalkBody
{
    int unk, unkCur, unkValue;
    WalkType* type;
};
struct WalkLink
{
    WalkObject* item;
    WalkLink* next;
    WalkObject* GetItem()
    {
        return item;
    }
    WalkLink* Next()
    {
        return next;
    }
};
struct WalkLeaf
{
    int unk, unkCur;
    void* object;
    int unk0c, uNewnk;
    WalkLink links;
};
class NiRTTI;
class GarbageCollectorObjectPtr
{
  public:
    WalkObject* object;
    int high;
};
GarbageCollectorObjectPtr* __cdecl bhkWorldObject_GetProperty(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
struct WalkAlloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Free(void*, int) throw();
};
struct WalkRouter
{
    int unk, unkCur, unkValue, unk0c;
    WalkAlloc* heap;
    WalkAlloc& Heap()
    {
        return *heap;
    }
};

void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> __forceinline void WalkDestruct(T* ptr, int count)
{
    for (int i = 0; i < count; ++i)
        ptr[i].~T();
}
template <class T> inline void WalkDeallocate(WalkAlloc& alloc, T* ptr, int count)
{
    alloc.Free(ptr, count * int(sizeof(T)));
}
struct WalkArray
{
    void** data;
    int size;
    int capacity;
    WalkArray() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~WalkArray()
    {
        WalkAlloc& alloc = ((WalkRouter*)hkMemoryRouter_getInstance())->Heap();
        ClearAndRelease(alloc);
    }
    void ClearAndRelease(WalkAlloc& alloc)
    {
        WalkDestruct(data, size);
        size = 0;
        if ((capacity & 0x80000000) == 0)
            WalkDeallocate(alloc, data, capacity & 0x3fffffff);
        data = 0;
        capacity = 0x80000000;
    }

    __forceinline void Add(void* const& value)
    {
        FNVTaskAllocator* alloc = hkMemoryRouter_getInstance()->allocator;
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(alloc, this, 4);
        *new (WalkPlacement(), &data[size]) void* = value;
        ++size;
    }
};
inline WalkObject* GetRoot(void* obj)
{
    GarbageCollectorObjectPtr temp;
    return bhkWorldObject_GetProperty(&temp, (NiAVObject*)obj, (const NiRTTI*)&DAT_01267b70)->object;
}
// @fnv 0x00ca11e0
void __stdcall CollectLeafObjects(WalkLeaf* leaf, WalkArray* outObjects, WalkArray* outBodies)
{
    if (!leaf)
        return;
    WalkObject* cast;
    {
        WalkObject* root = GetRoot(leaf->object);
        if (!root)
            cast = 0;
        else
            cast = root->FUN_00653290(&DAT_0126817c);
    }
    WalkLink* link = &leaf->links;
    bool found = false;
    WalkArray bodyArray;
    for (; link && (link->GetItem() != 0) && !found; link = link->Next())
    {
        WalkObject* item = link->item;
        WalkObject* body = item->AsItem();
        if (body)
        {
            WalkType* type = body->body ? body->body->type : (body->fallback ? *(WalkType**)body->fallback : 0);
            if (type->GetType() == 12)
                found = true;
            else
            {
                void* value = body->body;
                FNVTaskAllocator* alloc = hkMemoryRouter_getInstance()->allocator;
                if (bodyArray.size == (bodyArray.capacity & 0x3fffffff))
                    ResizeAudioStream(alloc, &bodyArray, 4);
                bodyArray.data[bodyArray.size++] = value;
            }
        }
    }
    if ((!cast || bodyArray.size > 0) && !found)
    {
        void* object = leaf->object;
        outObjects->Add(object);
        for (int index = 0; index < bodyArray.size; ++index)
            outBodies->Add(bodyArray.data[index]);
    }
}

struct TlsBlock_ca57
{
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_ca57 g_tls;
struct TlsFlagGuard_ca57
{
    unsigned int m_saved;
    TlsFlagGuard_ca57()
    {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 16;
    }
    ~TlsFlagGuard_ca57()
    {
        g_tls.m_2b4 = m_saved;
    }
};
class Pool_ca57
{
  public:
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
class Node_ca57
{
  public:
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Node_ca57();
    static void operator delete(void*) throw()
    {}
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((Pool_ca57*)&DAT_011f6238)->Game_DoHeapAlloc(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
};
class Owner_ca57
{
  public:
    unsigned int unk00, unk04, m_08;
    unsigned int* m_0c;
    void bhkPackedNiTriStripsShape_CopyCinfo(unsigned int*);
    unsigned int* GetOrCreateNode(bool*);
};
// Sets *out to whether m_0c is null; if so allocates a Node_ca57, stores it in m_0c, and calls FUN_00ca5360 when m_08 is nonzero; returns m_0c.
// @fnv 0x00ca57a0
unsigned int* Owner_ca57::GetOrCreateNode(bool* pbWasNull)
{
    TlsFlagGuard_ca57 guard;
    *pbWasNull = (m_0c == 0);
    if (*pbWasNull)
    {
        pbWasNull = (bool*)new Node_ca57();
        m_0c = (unsigned int*)pbWasNull;
        if (m_08 != 0)
            bhkPackedNiTriStripsShape_CopyCinfo(m_0c);
    }
    return m_0c;
}

int __cdecl bhkShape_CanShare(int param_1);
// @fnv 0x00ca6610
// src: XBOX_PDB 0x00ca6610
int __cdecl bhkExtendedMeshShape_CanShare(int param_1)
{
    return bhkShape_CanShare(param_1);
}

struct FNVHeapAllocator : FNVTaskAllocator
{
    template <typename T> void _bufFree(void* p, int numElem)
    {
        Free(p, numElem * sizeof(T));
    }
};

struct FNVHeapRouter : FNVTaskMemoryRouter
{
    FNVHeapAllocator& heap()
    {
        return *(FNVHeapAllocator*)allocator;
    }
};

template <class T>
static __forceinline void FNVArray__clearAndDeallocate(hkArrayBase<T>& self, FNVHeapAllocator& alloc);

template <class T>
static __forceinline void FNVArray_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void FNVArray__clearAndDeallocate(hkArrayBase<T>& self, FNVHeapAllocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(self.m_data, self.m_iCapacityState & 0x3fffffff);
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void FNVArray_destroy(hkArrayBase<T>& self)
{
        FNVArray__clearAndDeallocate(self, ((FNVHeapRouter*)hkMemoryRouter_getInstance())->heap());
    }

struct FNVArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { FNVArray_destroy(self); }
};

struct FUN_00ca73c0
{
    int unk00[9];
    hkArray<int, FNVArrayPolicy> unk24;
    hkArray<int, FNVArrayPolicy> unk30;
    hkArray<int, FNVArrayPolicy> unk3C;
    hkArray<int, FNVArrayPolicy> unk48;
    hkArray<char, FNVArrayPolicy> unk54;
    hkArray<int, FNVArrayPolicy> unk60;
    hkArray<int, FNVArrayPolicy> unk6C;
    hkArray<int, FNVArrayPolicy> unk78;
    hkArray<int, FNVArrayPolicy> unk84;
    hkArray<int, FNVArrayPolicy> unk90;
    hkArray<int, FNVArrayPolicy> unk9C;
    hkArray<int, FNVArrayPolicy> unkA8;
    ~FUN_00ca73c0();
};

// Destroys the object; the member arrays are released by their own destructors after this body runs.
// @fnv 0x00ca73c0
FUN_00ca73c0::~FUN_00ca73c0()
{}

struct PositionCommand
{
    unsigned char opcode;
    void* sender;
    float x;
    float y;
    float z;
};

struct PositionQueue
{
    void hkpWorld_queueOperation(PositionCommand* command);
};

struct PositionOwner
{
    int unk00;
    int unk04;
    PositionQueue* queue;

    void OnTrigger(float* position);
    void SendPositionCommand(float* position);
};

// @fnv 0x00ca89e0
void PositionOwner::SendPositionCommand(float* position)
{
    PositionQueue* active = queue;
    if (active && *(int*)((char*)active + 0x94))
    {
        PositionCommand command;
        command.sender = this;
        command.opcode = 0x19;
        command.x = position[0];
        command.y = position[1];
        command.z = position[2];
        active->hkpWorld_queueOperation(&command);
    }
    else
    {
        OnTrigger(position);
    }
}

void __cdecl bhkConstraint_LoadBinary();
// @fnv 0x00ca98d0
// src: XBOX_PDB 0x00ca98d0
void __cdecl bhkBallAndSocketConstraint_LoadBinary()
{
    bhkConstraint_LoadBinary();
}

// @fnv 0x00ca98f0
// src: GUESS 0x00ca98f0 (confidence: high)
char Runtime_ReturnConstant_0xff()
{
    return 0xff;
}

unsigned int __cdecl PackColorBigEndian(float, float, float, float);

struct RNG_cabbd0
{
    int unk00;
    unsigned int m_uiState;

    unsigned int Next()
    {
        m_uiState = m_uiState * 1664525 + 1013904223;
        return m_uiState;
    }
};

// @fnv 0x00cabbd0
// src: HAVOK_LIB 0x00cabbd0
unsigned int __cdecl hkColor_getRandomColor(RNG_cabbd0* rng)
{
    float min = 0.0f;
    float max = 1.0f;
    unsigned int uRand1 = rng->Next();
    unsigned int uRand2 = rng->Next();
    unsigned int uRand3 = rng->Next();
    return PackColorBigEndian((float)(min + (max - min) * (float)((float)uRand1 * 2.3283064365386963e-10)),
                              (float)(min + (max - min) * (float)((float)uRand2 * 2.3283064365386963e-10)),
                              (float)(min + (max - min) * (float)((float)uRand3 * 2.3283064365386963e-10)), 1.0f);
}

extern int DAT_011b1a58[8];
extern char DAT_00ffffff;
// @fnv 0x00cabcb0
int __cdecl CombineIndexedMaskAndShift(int aiIndex, int aiHighByte)
{
    return (DAT_011b1a58[aiIndex & 0x1F] & (int)&DAT_00ffffff) | (aiHighByte << 0x18);
}

struct SomeClass
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
};

// @fnv 0x00cac900
// src: COMMUNITY 0x00cac900
int* __fastcall ahkpCharacterProxy_GetCdPoints(SomeClass* pThis)
{
    return (int*)((char*)pThis + 0x74);
}

struct FnvCpu_FUN_00cac950_CpuObject
{
    char* hkpCharacterProxy_getLinearVelocity();
};
// @fnv 0x00cac950
// src: XBOX_PDB 0x00cac950
char* FnvCpu_FUN_00cac950_CpuObject::hkpCharacterProxy_getLinearVelocity()
{
    return reinterpret_cast<char*>(this) + 16;
}

struct FUN_00CAFEC0_This
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    void** unk60;
    int unk64;
    float unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
};
struct FUN_00CAFEC0_Class
{
    float __thiscall GetTableValue(int param_2, int param_3);
};
// Reads a float from the table at unk60 using an index computed from param_2, param_3, unk64 and unk10, and adds unk68.
// @fnv 0x00cafec0
float FUN_00CAFEC0_Class::GetTableValue(int param_2, int param_3)
{
    int v0_64 = ((FUN_00CAFEC0_This*)this)->unk64;
    int v0_10 = ((FUN_00CAFEC0_This*)this)->unk10;

    int diff = v0_64 - param_3;
    int product = diff * v0_10;
    int index = product + param_2;

    float* pfTable = (float*)((FUN_00CAFEC0_This*)this)->unk60;
    float val = pfTable[2 + index * 3];

    return val + ((FUN_00CAFEC0_This*)this)->unk68;
}

struct FUN_00cb0a70_Class
{
    void* ReturnSelf(int a);
};

// @fnv 0x00cb0a70
// src: GUESS 0x00cb0a70 (confidence: high)
void* FUN_00cb0a70_Class::ReturnSelf(int a)
{
    return this;
}

int __cdecl FUN_00ec6cc4(char*, const char*, char*);
// @fnv 0x00cb0f80
// src: HAVOK_LIB 0x00cb0f80
void __cdecl hkString_sprintf(char* a, const char* b, char* c)
{
    FUN_00ec6cc4(a, b, (char*)&c);
}

extern "C" int __cdecl FUN_00ec8a19(const char*, const char*, unsigned int);

// @fnv 0x00cb0fd0
// src: COMMUNITY 0x00cb0fd0
int __cdecl j_strncmp(const char* s1, const char* s2, unsigned int count)
{
    return FUN_00ec8a19(s1, s2, count);
}

namespace fnv_00cb0fe0 {
__declspec(noinline) char ToLowerAscii(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (char)(c - 'A' + 'a');
    return c;
}

char(__cdecl* g_pfnCB0FE0ToLower)(char) = ToLowerAscii;

// @fnv 0x00cb0fe0
int CompareStringsCaseInsensitive(const char* pStringA, const char* pStringB)
{
    int off = (int)(pStringA - pStringB);
    for (;;)
    {
        if (pStringB[off] == 0)
        {
            if (*pStringB == 0)
            {
                return 0;
            }
        }
        char x = ToLowerAscii(pStringB[off]);
        char y = ToLowerAscii(*pStringB);
        if (x < y)
        {
            return -1;
        }
        if (x > y)
        {
            return 1;
        }
        pStringB++;
    }
}
}  // namespace fnv_00cb0fe0

void __stdcall isOk_00cd4af0(int a1);
// @fnv 0x00cb2d70
// src: COMMUNITY 0x00cb2d70
unsigned int __stdcall hkRotation_isOk(unsigned int uiValue)
{
    isOk_00cd4af0((int)uiValue);
    return uiValue;
}

void __cdecl bhkPCollisionObject_LoadBinary(void);
// @fnv 0x00cb75f0
// src: XBOX_PDB 0x00cb75f0
void __cdecl bhkSPCollisionObject_LoadBinary(void)
{
    bhkPCollisionObject_LoadBinary();
}

void __cdecl bhkPCollisionObject_LinkObject();
// @fnv 0x00cb7600
// src: XBOX_PDB 0x00cb7600
void __cdecl bhkSPCollisionObject_LinkObject()
{
    bhkPCollisionObject_LinkObject();
}

void __cdecl bhkCollisionObject_RegisterStreamables();

// @fnv 0x00cb7610
// src: XBOX_PDB 0x00cb7610
void __cdecl bhkBlendCollisionObject_RegisterStreamables()
{
    bhkCollisionObject_RegisterStreamables();
}

bool __cdecl bhkCollisionObject_IsEqual(int param_1, int param_2);
// @fnv 0x00cb7630
// src: XBOX_PDB 0x00cb7630
bool __cdecl bhkSPCollisionObject_IsEqual(int param_1, int param_2)
{
    return bhkCollisionObject_IsEqual(param_1, param_2);
}

extern int DAT_012683e8;

struct FUN_00c86720
{
    virtual ~FUN_00c86720();
};

struct FUN_00cb83f0 : FUN_00c86720
{
    void bhkSerializable_Kill();
    virtual ~FUN_00cb83f0();
};

// @fnv 0x00cb83f0
FUN_00cb83f0::~FUN_00cb83f0()
{
    bhkSerializable_Kill();
    --DAT_012683e8;
}

struct CpuOpaque;
extern CpuOpaque DAT_012683ec;
// @fnv 0x00cb8460
// src: COMMUNITY 0x00cb8460
CpuOpaque* __cdecl bhkOrientHingedBodyAction_GetRTTI()
{
    return &DAT_012683ec;
}

void __cdecl bhkUnaryAction_CopyMembers();
// @fnv 0x00cb8470
// src: XBOX_PDB 0x00cb8470
void __cdecl bhkOrientHingedBodyAction_CopyMembers()
{
    bhkUnaryAction_CopyMembers();
}

extern "C" void __cdecl FUN_00aa1460(void* self, int size);

struct FUN_00cb8480_class
{
    void FUN_00cb83f0();
    FUN_00cb8480_class* FUN_00cb8480(char flag);
};

// @fnv 0x00cb8480
FUN_00cb8480_class* FUN_00cb8480_class::FUN_00cb8480(char flag)
{
    FUN_00cb83f0();
    if (flag & 1)
    {
        FUN_00aa1460(this, 0x10);
    }
    return this;
}

struct FUN_00d2acf0
{
    void* vtable;
    unsigned short memorySizeAndFlags;
    unsigned short referenceCount;
    unsigned int unk08, unk0C, unk10, unk14;
    unsigned int unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34;
    unsigned int unk38, unk3C, unk40, unk44;
    unsigned int unk48, unk4C, unk50, unk54;
    unsigned int unk58, unk5C;

    FUN_00d2acf0(void* source, void* start, void* end, float nearValue, float farValue, int flags);
    void FUN_00c905b0();

    static void* operator new(unsigned int bytes)
    {
        FNVTaskMemoryRouter* router = hkMemoryRouter_getInstance();
        FUN_00d2acf0* object = (FUN_00d2acf0*)((CAC300Allocator*)router->allocator)->Alloc(bytes);
        object->memorySizeAndFlags = (unsigned short)bytes;
        return object;
    }
    static void operator delete(void* object);
};

struct FUN_00cb88d0_owner : CAC300Owner
{
    void __thiscall CreateShapeAndApply(void* parameters);
};

// Allocates a FUN_00d2acf0 from the parameters block, sets it as the object, calls FUN_00c905b0, then applies the parameters.
// @fnv 0x00cb88d0
void FUN_00cb88d0_owner::CreateShapeAndApply(void* pParams)
{
    CA2020AllocTagScope allocationTag(16);
    FUN_00d2acf0* shape = new FUN_00d2acf0(*(void**)((char*)pParams + 4), (char*)pParams + 0x10, (char*)pParams + 0x20,
                                           *(float*)((char*)pParams + 0x30), *(float*)((char*)pParams + 0x34), 0);
    SetObject((hkReferencedObject*)shape);
    shape->FUN_00c905b0();
    Apply((int)pParams);
}

extern GlobalObjectO2_00a7b610 g_012683ec;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(GlobalObjectO2_00a7b610* p);
struct FUN_00cb89c0_cls
{
    void bhkUnaryAction_GetViewerStrings(SArr046* arr);
    void AppendGlobalReference(SArr046* arr);
};
// Calls FUN_00c86b80 on arr, then appends the reference returned by FUN_00a7d330 for g_012683ec to arr.
// @fnv 0x00cb89c0
void FUN_00cb89c0_cls::AppendGlobalReference(SArr046* pArray)
{
    TlsGuard_t guard;
    char* value = 0;
    bhkUnaryAction_GetViewerStrings(pArray);
    value = NiViewerStrings_NiGetViewerString_Title(*reinterpret_cast<GlobalObjectO2_00a7b610**>(&g_012683ec));
    pArray->AppendReference(value);
}

struct CpuOpaque;
extern CpuOpaque DAT_012683f4;
// @fnv 0x00cb9250
// src: COMMUNITY 0x00cb9250
CpuOpaque* __cdecl bhkForceController_GetRTTI()
{
    return &DAT_012683f4;
}

void __cdecl FUN_00a7b3d0();

// @fnv 0x00cb9920
// src: XBOX_PDB 0x00cb9920
void __cdecl bhkExtraData_IsEqual()
{
    FUN_00a7b3d0();
}

class CBADDynamicArray : public CA0E60Array
{
  public:
    void Runtime_ProcessEntries_00cb9d50(void** elements, unsigned int count);
    void ReleaseItems(void** elements, unsigned int count);
    void BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int requestedSize, bool compact);
};

// @fnv 0x00cbadf0
// src: XBOX_PDB 0x00cbadf0
void CBADDynamicArray::BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int requestedSize, bool compact)
{
    if (requestedSize == 0)
    {
        if (m_pBuffer != 0)
        {
            ReleaseItems(m_pBuffer, m_uiSize);
            if (compact)
            {
                Free(m_pBuffer);
                m_pBuffer = 0;
                m_uiCapacity = 0;
            }
            m_uiSize = 0;
        }
        return;
    }

    if (requestedSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(requestedSize);
        }
        else
        {
            Reallocate(requestedSize, m_uiSize);
        }
        unsigned int oldSize = m_uiSize;
        m_uiCapacity = requestedSize;
        Runtime_ProcessEntries_00cb9d50(m_pBuffer + oldSize, requestedSize - oldSize);
        m_uiSize = requestedSize;
    }
    else if (requestedSize < m_uiSize)
    {
        ReleaseItems(m_pBuffer + requestedSize, m_uiSize - requestedSize);
        m_uiSize = requestedSize;
        if (compact && requestedSize <= m_uiCapacity / 4)
        {
            Reallocate(requestedSize, requestedSize);
            m_uiCapacity = requestedSize;
        }
    }
    else
    {
        unsigned int oldSize = m_uiSize;
        Runtime_ProcessEntries_00cb9d50(m_pBuffer + oldSize, requestedSize - oldSize);
        m_uiSize = requestedSize;
    }
}

class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01268408;

// @fnv 0x00cbaf80
// src: COMMUNITY 0x00cbaf80
GlobalObjectO2_00a7b610* __cdecl bhkRagdollTemplate_GetRTTI()
{
    return &g_01268408;
}

struct FUN_00cbaf90_Obj
{
    void FUN_00cbaf90();
};
void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct FUN_00cbb130_Class : FUN_00cbaf90_Obj
{
    unsigned int __thiscall FUN_00cbb130(unsigned char flag);
};
// @fnv 0x00cbb130
unsigned int __thiscall FUN_00cbb130_Class::FUN_00cbb130(unsigned char flag)
{
    FUN_00cbaf90();
    if ((flag & 1) != 0)
    {
        FUN_00aa1460(this, 0x1c);
    }
    return reinterpret_cast<unsigned int>(this);
}

extern int DAT_010c9194;

struct FUN_00cbc460
{
    void* m_ppVirtualMethodTable;
    unsigned short m_04;
    unsigned short m_w06;
    // volatile keeps the vptr store ahead of the zero stores, as in the original
    void* volatile m_p08;
    void* volatile m_p0c;
    void* volatile m_p10;
    void* volatile m_p14;
    void* volatile m_p18;
    void* volatile m_p1c;
    void* volatile m_p20;
    void* volatile m_p24;
    void* volatile m_p28;
    void* volatile m_p2c;
    void* volatile m_p30;
    FUN_00cbc460();
};

// @fnv 0x00cbc460
FUN_00cbc460::FUN_00cbc460()
{
    m_ppVirtualMethodTable = &DAT_010c9194;
    m_w06 = 1;
    m_p08 = 0;
    m_p0c = 0;
    m_p10 = 0;
    m_p14 = 0;
    m_p18 = 0;
    m_p1c = 0;
    m_p20 = 0;
    m_p24 = 0;
    m_p28 = 0;
    m_p2c = 0;
    m_p30 = 0;
}

void __cdecl ClearLists();

// @fnv 0x00cbf530
// src: GUESS 0x00cbf530 (confidence: medium)
void __cdecl Runtime_ClearLists_Thunk()
{
    ClearLists();
}

struct HeapAllocator
{
    void* Allocate(unsigned int size);
    void Deallocate(void* p);
};
extern HeapAllocator g_heapAllocator;

struct RefStub
{
    void IncRefCount();
    void DecRefCount();
};

struct RefHolder
{
    RefStub* object;
    RefHolder()
    {}
    ~RefHolder()
    {
        if (object)
            object->DecRefCount();
    }
};

struct ThreadLocalData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int heapIndex;
};
extern __declspec(thread) ThreadLocalData g_threadLocalData;

struct HeapIndexGuard
{
    int saved;
    HeapIndexGuard(int index)
    {
        saved = g_threadLocalData.heapIndex;
        g_threadLocalData.heapIndex = index;
    }
    ~HeapIndexGuard()
    {
        g_threadLocalData.heapIndex = saved;
    }
};

extern int DAT_010c7600;

struct ShapePrefix
{
    int unk00;
    float unk04;
    ShapePrefix() : unk00(0), unk04(0.0f)
    {}
};

struct ShapeStrips
{
    void* vtbl;
    void* pBase;
    unsigned int maxSize;
    unsigned int size;
    unsigned int eSize;
    unsigned int growBy;

    ShapeStrips(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        maxSize = uiMaxSize;
        growBy = uiGrowBy;
        size = 0;
        eSize = 0;
        if (uiMaxSize > 0)
            pBase = g_heapAllocator.Allocate(uiMaxSize);
        else
            pBase = 0;
        vtbl = &DAT_010c7600;
    }
};

struct ShapeVector
{
    float x;
    float y;
    float z;
    float w;
    ShapeVector()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
};

struct ShapeData : ShapePrefix
{
    ShapeStrips strips;
    ShapeVector scale;

    static void* operator new(unsigned int size)
    {
        char* p = (char*)g_heapAllocator.Allocate(size + 16);
        unsigned char off = (unsigned char)(16 - ((unsigned char)(unsigned int)p & 15));
        p += off;
        p[-1] = off;
        return p;
    }
    static void operator delete(void* p)
    {
        if (p)
        {
            unsigned char off = ((unsigned char*)p)[-1];
            g_heapAllocator.Deallocate((char*)p - off);
        }
    }

    ShapeData()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
    void SetScale()
    {
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;
    }
};
struct ShapeOwnerTarget
{
    void CopyEntriesToArg(ShapeData* data);
};

struct MyObj
{
    int unk00;
    int unk04;
    ShapeOwnerTarget* unk08;
    ShapeData* unk0c;

    void bhkShape_CopyCinfo(ShapeData* data);
    ShapeData* GetOrCreateShapeData(bool* created);
};

// Creates a ShapeData on first call, copies entries from unk08 or resets scale, and returns the stored ShapeData pointer.
// @fnv 0x00ca6d40
ShapeData* MyObj::GetOrCreateShapeData(bool* created)
{
    HeapIndexGuard guard(16);
    if ((*created = (unk0c == 0)) != false)
    {
        ShapeData* data = new ShapeData;
        unk0c = data;
        if (unk08)
        {
            bhkShape_CopyCinfo(data);
            if (unk08)
                unk08->CopyEntriesToArg(data);
            else
                data->SetScale();
        }
    }
    return unk0c;
}

struct FNV_InnerObject
{
    virtual void __fastcall Call0(int);
    virtual void __fastcall Call1(int);
    virtual void __fastcall Call2(int);
    virtual void __fastcall Call3(int);
    virtual void __fastcall Call4(int);
    virtual void __fastcall Call5(int);
    virtual void __fastcall Call6(int);
    virtual void __fastcall Call7(int);
    virtual void __fastcall Call8(int);
};
struct FNV_OwnerObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    FNV_InnerObject inner;
    void __fastcall hkpRigidBody_setInertiaInvLocal(int);
};
// @fnv 0x00ca8940
// src: HAVOK_LIB 0x00ca8940
void __fastcall FNV_OwnerObject::hkpRigidBody_setInertiaInvLocal(int forwarded)
{
    inner.Call8(forwarded);
}


struct CA8B80Command;
struct CA8B80Queue
{
    void __thiscall Push(CA8B80Command*);
};
struct FUN_00ca8a30_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    CA8B80Queue* m_8;
    void __thiscall PushCommand(NiPoint3*);
    void __thiscall hkpRigidBody_setAngularVelocity(NiPoint3*);
};
struct FUN_00ca8a30_Local
{
    unsigned char m_kPointB;
    FUN_00ca8a30_Class* m_p;
    float m_uiX;
    float m_uiY;
    float m_uiZ;
};
// If m_8 is set and its field at 0x94 is nonzero, pushes a command holding this and the coordinates onto m_8; otherwise calls FUN_00561800(p).
// @fnv 0x00ca8a30
void __thiscall FUN_00ca8a30_Class::PushCommand(NiPoint3* apPoint)
{
    if (m_8 && *(int*)((char*)m_8 + 0x94))
    {
        FUN_00ca8a30_Local localCmd;
        localCmd.m_p = this;
        localCmd.m_uiX = apPoint->x;
        localCmd.m_kPointB = 0x1a;
        localCmd.m_uiY = apPoint->y;
        localCmd.m_uiZ = apPoint->z;
        m_8->Push((CA8B80Command*)&localCmd);
    }
    else
    {
        hkpRigidBody_setAngularVelocity(apPoint);
    }
}

extern int DAT_0108febc;
extern int DAT_010c81ac;
extern int DAT_01268188;
extern int DAT_0126830c;
extern __declspec(thread) int tls_memContext;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl _delete(void* p, int size);

struct ScopedMemContext_ca9e60
{
    int m_iOld;
    ScopedMemContext_ca9e60(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext_ca9e60()
    {
        tls_memContext = m_iOld;
    }
};

struct Holder_ca9e60
{
    void* p;
    Holder_ca9e60(void* q) : p(q)
    {}
    ~Holder_ca9e60()
    {
        if (p)
            _delete(p, 0x10);
    }
};

struct Host_ca9e60
{
    void* __thiscall bhkMalleableConstraint_Clone(void* arg);
    void __thiscall bhkConstraint_CopyMembers(void* a, void* b);
};

// Allocates a bhkRefObject, initializes it, increments two global counters, passes it and arg to FUN_00c89730, and returns it.
// @fnv 0x00ca9e60
// src: COMMUNITY 0x00ca9e60
void* Host_ca9e60::bhkMalleableConstraint_Clone(void* arg)
{
    ScopedMemContext_ca9e60 context(0x10);
    bhkSerializable_CloneCritLock();
    bhkRefObject* obj;
    void* p = Object_DispatchCommandFour(0x10);
    {
        Holder_ca9e60 h(p);
        if (p)
        {
            ((bhkRefObject*)p)->Initialize();
            *(void**)p = &DAT_0108febc;
            int one = 1;
            *((int*)p + 3) = 0;
            DAT_01268188 += one;
            *(void**)p = &DAT_010c81ac;
            DAT_0126830c += one;
            obj = (bhkRefObject*)p;
        }
        else
        {
            obj = NULL;
        }
        h.p = 0;
    }
    this->bhkConstraint_CopyMembers(obj, arg);
    bhkSerializable_CloneCritUnlock();
    return obj;
}

void __cdecl DispatchToTarget();
// @fnv 0x00caa1b0
// src: XBOX_PDB 0x00caa1b0
void __cdecl bhkHingeLimitsConstraint_SetEntityB()
{
    DispatchToTarget();
}

extern int DAT_01268334;
extern int DAT_01268338;
extern int DAT_0126833c;
unsigned int __cdecl hkColor_getRandomColor(int*);

// @fnv 0x00cabe90
// src: HAVOK_LIB 0x00cabe90
unsigned int __cdecl hkColor_getRandomColor_00cabe90()
{
    if (!(DAT_0126833c & 1))
    {
        DAT_0126833c |= 1;
        DAT_01268334 = 0;
        DAT_01268338 = 0;
    }
    return hkColor_getRandomColor(&DAT_01268334);
}

struct CA0F0Result
{
    int unk00;
    int unk04;
    int m_8;
};
struct CA0F0Object : BaseThunk
{
    int __thiscall GetResultValue();
};
// @fnv 0x00cac0f0
int CA0F0Object::GetResultValue()
{
    int value = 0;
    if (m_8)
    {
        CA0F0Result* result = static_cast<CA0F0Result*>(m_8->hkpCharacterProxy_getShapePhantom());
        if (result)
            value = result->m_8;
    }
    return value;
}

struct RefCountedCAC4B0
{
    int unk00;
    long m_iRefCount;
};
struct ShapeHolderCAC4B0
{
    int unk00;
    int unk04;
    int unk08;
    RefCountedCAC4B0* m_pkShape;
};
struct WorldObjectCAC4B0
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    void* m_pkUserData;
    ShapeHolderCAC4B0* hkpCharacterProxy_getShapePhantom();
};
void __cdecl bhkCharacterProxy_RembhkRefs();
struct RefObjectCAC4B0
{
    void UpdateReference(bool bAdd);
    int unk00;
    int unk04;
    WorldObjectCAC4B0* m_pkHavokObject;
    WorldObjectCAC4B0* GetHavokObject()
    {
        return this ? m_pkHavokObject : 0;
    }
};
struct ShapeRefCAC4B0 : public RefObjectCAC4B0
{
    void bhkCharacterProxy_Link(bool bAdd);
};

// If bAdd, calls DAT_00fdf1c0 on the shape's refcount, else FUN_00cac410(); sets the Havok object's user data to this or null, then calls UpdateReference(bAdd).
// @fnv 0x00cac4b0
// src: XBOX_PDB 0x00cac4b0
void ShapeRefCAC4B0::bhkCharacterProxy_Link(bool bAdd)
{
    WorldObjectCAC4B0* pkObject = GetHavokObject();
    if (bAdd)
    {
        if (m_pkHavokObject)
        {
            ShapeHolderCAC4B0* pkHolder = m_pkHavokObject->hkpCharacterProxy_getShapePhantom();
            if (pkHolder && pkHolder->m_pkShape)
                DAT_00fdf1c0(&pkHolder->m_pkShape->m_iRefCount);
        }
    }
    else
    {
        bhkCharacterProxy_RembhkRefs();
    }
    if (pkObject)
        pkObject->m_pkUserData = bAdd ? this : 0;
    RefObjectCAC4B0::UpdateReference(bAdd);
}

hkMemoryRouter* __cdecl GetMemoryRouterC5E0();

class BufferOwnerC5E0
{
  public:
    void FreeBuffer(bool bFree);

    int unk00;
    int unk04;
    int unk08;
    void* pvContextData;
};

// If bFree is set, releases the pvContextData buffer through the memory router heap and nulls the pointer.
// @fnv 0x00cac5e0
void BufferOwnerC5E0::FreeBuffer(bool bFree)
{
    AutoMemContext kContext(0x10);
    if (bFree)
    {
        void* pvBuffer = pvContextData;
        if (pvBuffer)
            GetRouterHeap(GetMemoryRouterC5E0()).blockFree(pvBuffer, 0x80);
        pvContextData = 0;
    }
}

namespace fnv_00cac6b0 {
// ---- FUN_00cac6b0 candidate ----

extern const NiRTTI g_01268344;

extern float DAT_01267e30;
extern "C" void __cdecl FUN_00458620(void* pvOut, const void* pkObj);



struct FUN_00cac910_shell
{
    void* hkpCharacterProxy_getPosition();
};
struct ProxyHolder
{
    const char* hkpCharacterProxy_getLinearVelocity();
};

struct ProxyOwner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();

    int unk04;
    FUN_00cac910_shell* m_8;

    void bhkSerializable_GetViewerStrings(SArr046* pkStrings);
    void bhkCharacterProxy_GetViewerStrings(SArr046* pkStrings);
};

static const char kCac6b0Pos[] = "Pos";
static const char kCac6b0Vel[] = "Vel";

// Appends to pkStrings the class name, then the Pos and Vel vectors read from the proxy m_8 when it is present.
// @fnv 0x00cac6b0
// src: XBOX_PDB 0x00cac6b0
void ProxyOwner::bhkCharacterProxy_GetViewerStrings(SArr046* pkStrings)
{
    TlsGuard_t guard;

    this->bhkSerializable_GetViewerStrings(pkStrings);

    char* pcStr = NiViewerStrings_NiGetViewerString_Title(g_01268344.m_pcName);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->FUN_0096ad30(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->FUN_0096ae90(uiIndex, pcStr);

    NiPoint3 kVec;
    FUN_00cac910_shell* pkProxy = this->m_8;
    const void* pvSrc = &DAT_01267e30;
    if (pkProxy)
    {
        this->v37();
        pvSrc = pkProxy->hkpCharacterProxy_getPosition();
        this->v37();
    }
    FUN_00458620(&kVec, pvSrc);
    pcStr = ((const NiPoint3&)kVec).FormatToBuffer(kCac6b0Pos);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->FUN_0096ad30(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->FUN_0096ae90(uiIndex, pcStr);

    FUN_00cac910_shell* pkProxy2 = this->m_8;
    if (pkProxy2)
    {
        this->v37();
        FUN_00458620(&kVec, ((ProxyHolder*)pkProxy2)->hkpCharacterProxy_getLinearVelocity());
        this->v37();
    }
    pcStr = ((const NiPoint3&)kVec).FormatToBuffer(kCac6b0Vel);
    uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->FUN_0096ad30(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->FUN_0096ae90(uiIndex, pcStr);
}
}  // namespace fnv_00cac6b0

extern "C" int DAT_0126834c;
struct CAFBase
{
    virtual ~CAFBase();
};
struct FUN_00caff80 : CAFBase
{
    virtual ~FUN_00caff80();
    void bhkSerializable_Kill();
};
// @fnv 0x00caff80
FUN_00caff80::~FUN_00caff80()
{
    bhkSerializable_Kill();
    --DAT_0126834c;
}

// FUN_00cb0aa0: allocator-backed string dup. Takes the source string in the
// caller's edi (private convention derived for this static noinline helper):
// length via FUN_00cb10d0 (+1 for the NUL), block allocated through the task
// memory router's allocator, contents filled by FUN_00cb1090.

struct FNVTaskMemoryRouter;

extern "C" int __cdecl hkString_strLen(int);
extern "C" FNVTaskMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" void* __cdecl AllocateWithHeader(void* allocator, unsigned int count);
extern "C" void __cdecl hkString_strCpy(void* block, int value);

struct CbobRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* allocator;
};

// Allocates a block of FUN_00cb10d0(s) + 1 units from the router's allocator, fills it from s via FUN_00cb1090, and returns it.
// @fnv 0x00cb0aa0
// src: HAVOK_LIB 0x00cb0aa0
static __declspec(noinline) void* strDup(char* s)
{
    unsigned int count = (unsigned int)(hkString_strLen((int)s) + 1);
    CbobRouter* router = (CbobRouter*)hkMemoryRouter_getInstance();
    void* block = AllocateWithHeader(router->allocator, count);
    hkString_strCpy(block, (int)s);
    return block;
}

void zz_probe_call(char* s)
{
    strDup(s);
}

namespace fnv_00cb1200 {
__declspec(noinline) char ToLowerAscii(char c)
{
    if ((unsigned char)(c - 'A') <= 'Z' - 'A')
        c += 'a' - 'A';
    return c;
}

// Converts every character in pcString to its lowercase ASCII equivalent in place and returns pcString.
// @fnv 0x00cb1200
// src: GUESS 0x00cb1200 (confidence: high)
char* String_ToLowerASCII(char* pcString)
{
    if (*pcString)
    {
        char* pc = pcString;
        do
        {
            *pc = ToLowerAscii(*pc);
            pc++;
        } while (*pc);
    }
    return pcString;
}
}  // namespace fnv_00cb1200

namespace fnv_00cb1230 {
char __declspec(noinline) ToUpperAscii(char c)
{
    if ((unsigned char)(c - 'a') <= 25u)
        c -= 32;
    return c;
}

// Converts every character of the null-terminated string s to uppercase in place and returns s.
// @fnv 0x00cb1230
char* __cdecl MakeUpperAscii(char* apString)
{
    if (*apString)
    {
        char* p = apString;
        do
        {
            *p = ToUpperAscii(*p);
            ++p;
        } while (*p);
    }
    return apString;
}
}  // namespace fnv_00cb1230

struct Cb1b80Arr
{
    int* m_data;
    int m_flags;
    int m_uiItemCount;
    Cb1b80Arr* hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator_hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator(void* data, unsigned int size);
};

// @fnv 0x00cb1b80
// src: HAVOK_LIB 0x00cb1b80
Cb1b80Arr* Cb1b80Arr::hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator_hkMultiMap_unsigned_int64_unsigned_int64_struct_hkMultiMapOperations_unsigned_int64_struct_hkContainerHeapAllocator(void* data, unsigned int size)
{
    int n = size >> 4;
    m_data = (int*)data;
    m_flags = 0x80000000;
    m_uiItemCount = n - 1;
    for (int i = 0; i < n; ++i)
    {
        int* q = m_data;
        q[4 * i] = -1;
        q[4 * i + 1] = -1;
    }
    return this;
}

void __cdecl bhkCollisionObject_SaveBinary(void);
// @fnv 0x00cb7620
// src: XBOX_PDB 0x00cb7620
void __cdecl bhkSPCollisionObject_SaveBinary(void)
{
    bhkCollisionObject_SaveBinary();
}

extern int DAT_0102009c;
extern int DAT_0102016c;
extern int DAT_010c8914;
extern int DAT_01268118;
extern int DAT_01268154;

struct S00cb84f0_Obj : FUN_00c87c30
{
    int unk0c;
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    S00cb84f0_Obj()
    {
        *(void**)this = (void*)&DAT_0102016c;
        unk0c = 0;
        DAT_01268154 += 1;
        *(void**)this = (void*)&DAT_0102009c;
        DAT_01268118 += 1;
        *(void**)this = (void*)&DAT_010c8914;
    }
};

// Allocates a new S00cb84f0_Obj instance and returns its pointer, or null if allocation fails.
// @fnv 0x00cb84f0
// src: EXE 0x00cb84f0
void* __cdecl bhkOrientHingedBodyAction_CreateObject()
{
    S00cb84f0_Obj* p = new S00cb84f0_Obj;
    if (p)
    {
        return p;
    }
    return 0;
}

void __cdecl FUN_00a6d290(void);
struct FUN_00aa4060_Class
{
    void __thiscall MemoryManager_Deallocate(void* p);
};
struct FUN_00cb9260_Class
{
    int __thiscall FUN_00cb9260(unsigned char flags);
};
// Calls FUN_00a6d290, then if flags bit 0 is set and this is non-null passes the block before this to FUN_00aa4060; returns this.
// @fnv 0x00cb9260
int __thiscall FUN_00cb9260_Class::FUN_00cb9260(unsigned char flags)
{
    unsigned char* object = reinterpret_cast<unsigned char*>(this);
    int result = reinterpret_cast<int>(this);

    FUN_00a6d290();

    if ((flags & 1) != 0 && object != 0)
    {
        unsigned int size = *(object - 1);
        void* p = object - size;
        reinterpret_cast<FUN_00aa4060_Class*>(&DAT_011f6238)->MemoryManager_Deallocate(p);
    }

    return result;
}

extern "C" void __cdecl CopyMembers_00a7b330();
// @fnv 0x00cb9910
// src: XBOX_PDB 0x00cb9910
void __cdecl bhkRagdollTemplate_CopyMembers()
{
    CopyMembers_00a7b330();
}

struct FUN_00cbadb0_Dispatch
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
};
struct FUN_00cbadb0_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void releaseItem(void* item);
    virtual ~FUN_00cbadb0_Obj();

    void* m_items;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;

    void ReleaseItems(void* items, unsigned int count);
};
// Destructor that releases the m_items array via ReleaseItems and releaseItem, then nulls m_items and the two counters.
// @fnv 0x00cbadb0
FUN_00cbadb0_Obj::~FUN_00cbadb0_Obj()
{
    if (m_items)
    {
        ReleaseItems(m_items, m_uiItemCount);
        reinterpret_cast<FUN_00cbadb0_Dispatch*>(this)->releaseItem(m_items);
        m_items = 0;
        m_pRayCursor = 0;
        m_uiItemCount = 0;
    }
}

extern int DAT_010c8d28;
struct FUN_00cbaec0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* data);
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;
    void __thiscall ReleaseItems(void* data, unsigned int size);
    FUN_00cbaec0_Obj* __thiscall ReleaseAndDestroy(unsigned char flags);
};
// Releases the held items, optionally deallocates this object when flags bit 0 is set, and returns this.
// @fnv 0x00cbaec0
FUN_00cbaec0_Obj* __thiscall FUN_00cbaec0_Obj::ReleaseAndDestroy(unsigned char flags)
{
    void* oldData = m_pData;
    *reinterpret_cast<int**>(this) = &DAT_010c8d28;
    if (oldData)
    {
        ReleaseItems(oldData, m_uiSize);
        vf08(m_pData);
        m_pData = 0;
        m_uiReservedSize = 0;
        m_uiSize = 0;
    }
    if (flags & 1)
        _g_memoryManager.Deallocate(this);
    return this;
}

struct ArrayCBAF90
{
    virtual __forceinline ~ArrayCBAF90()
    {
        RemoveAll();
    }
    virtual void v04();
    virtual void Deallocate(void* pvBase);
    void ReleaseItems(void* pvBase, unsigned int ItemUpdateArray);
    __forceinline void RemoveAll()
    {
        if (m_pBase)
        {
            ReleaseItems(m_pBase, m_uiSize);
            Deallocate(m_pBase);
            m_pBase = 0;
            m_uiAllocated = 0;
            m_uiSize = 0;
        }
    }
    void* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiAllocated;
};
struct ObjectCBAF90
{
    virtual ~ObjectCBAF90();
    int unk04;
    int unk08;
};
struct FUN_00cbaf90 : public ObjectCBAF90
{
    virtual ~FUN_00cbaf90();
    ArrayCBAF90 m_kArray;
};

// Destructor that releases all items in m_kArray by calling RemoveAll.
// @fnv 0x00cbaf90
FUN_00cbaf90::~FUN_00cbaf90()
{
    m_kArray.RemoveAll();
}

struct CBB050Array
{
    void BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(unsigned int count, bool enabled);
};
struct CBB050Object
{
    int unk00;
    int unk04;
    int unk08;
    CBB050Array array;
    void FUN_00a7b4a0(ReadStream* stream);
    void bhkRagdollTemplate_LoadBinary(ReadStream* stream);
};
// Calls FUN_00a7b4a0, loads a count from the stream, passes it to the array's FUN_00cbadf0, then calls stream->FUN_00a645b0 count times.
// @fnv 0x00cbb050
// src: XBOX_PDB 0x00cbb050
void CBB050Object::bhkRagdollTemplate_LoadBinary(ReadStream* stream)
{
    FUN_00a7b4a0(stream);
    unsigned int count = 0;
    Load(*stream->binary, &count, 1);
    array.BSSimpleArray_NiPointer_bhkRagdollTemplateData_1024_SetSize(count, true);
    for (unsigned int i = 0; i < count; ++i)
        stream->ReadLinkID();
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_011f49e0;

struct FUN_00cbaf20_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    FUN_00cbaf20_class();
    void AssignFixedString(const NiFixedString& name);
};

// Allocates a FUN_00cbaf20_class instance and assigns it the fixed string stored at DAT_011f49e0.
// @fnv 0x00cbb0c0
FUN_00cbaf20_class* CreateNamedObject()
{
    FUN_00cbaf20_class* obj = new FUN_00cbaf20_class();
    obj->AssignFixedString(*(const NiFixedString*)&DAT_011f49e0);
    return obj;
}

struct FUN_00cbf540_class
{
    void __thiscall CreateObjects(int* a, int b);
};

struct FUN_00cbf6b0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void __thiscall EnsureObjectsCreated(int v);
};

extern int(__stdcall* DAT_00fdf1d0)();

// @fnv 0x00cbf6b0
void __thiscall FUN_00cbf6b0_class::EnsureObjectsCreated(int v)
{
    int r = DAT_00fdf1d0();
    if (m_iThirdValue != r)
    {
        ((FUN_00cbf540_class*)this)->CreateObjects(&r, v);
    }
}

extern int DAT_010c925c;

struct FUN_00cbf6e0_cls
{
    void* m_ppVirtualMethodTable;
    FUN_00cbf6e0_cls* FUN_00cbf6e0(unsigned int flags);
};

// @fnv 0x00cbf6e0
FUN_00cbf6e0_cls* FUN_00cbf6e0_cls::FUN_00cbf6e0(unsigned int flags)
{
    m_ppVirtualMethodTable = &DAT_010c925c;
    if ((flags & 1) != 0)
        DAT_011f6238.Free(this);
    return this;
}

struct FUN_00ca5620
{
    unsigned int m_00;
    NiPointer<RefCounted> m_pReferencedObject;
    ~FUN_00ca5620();
};

// Destructor that releases the held RefCounted object by nulling m_pReferencedObject.
// @fnv 0x00ca5620
FUN_00ca5620::~FUN_00ca5620()
{
    m_pReferencedObject = (RefCounted*)0;
}

#include <math.h>
namespace fnv_00ca6b60 {
extern __declspec(thread) int tls_memContext;

struct ScopedMemContext
{
    int m_iOld;
    ScopedMemContext(int context)
    {
        m_iOld = tls_memContext;
        tls_memContext = context;
    }
    ~ScopedMemContext()
    {
        tls_memContext = m_iOld;
    }
};

}  // namespace fnv_00ca6b60




namespace fnv_00ca6b60 {
void __cdecl SetupCollisionGeometry(NiTriStrips* strips, NiNode* parent, int layer, int arg);

struct ShapeEntry
{
    NiObject* m_pData;
    int unk04;
};

extern ShapeEntry DAT_012682f0;

struct StripsShape
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    ShapeEntry* m_pEntries;
    int unk9C;
    int m_iNumEntries;
};



// The backing Havok shape is stored in the inherited reference-object member.
static inline int GetNumStrips(bhkNiTriStripsShape* shape)
{
    return (shape && shape->m_pHavokObject) ? ((StripsShape*)shape->m_pHavokObject)->m_iNumEntries : 0;
}

static inline ShapeEntry& GetStrip(bhkNiTriStripsShape* shape, int i)
{
    return (shape && shape->m_pHavokObject) ? ((StripsShape*)shape->m_pHavokObject)->m_pEntries[i] : DAT_012682f0;
}

static inline bool IsTriStripsData(NiObject* obj)
{
    for (const NiRTTI* rtti = obj->GetRTTI(); rtti; rtti = rtti->m_pBaseRTTI)
    {
        if (rtti == &NiTriStripsData::ms_kRTTI)
            return true;
    }
    return false;
}

}  // namespace fnv_00ca6b60

// For each strip entry with NiTriStripsData, creates a NiTriStrips, sets its scale, calls SetupCollisionGeometry, and attaches it to parent.
// @fnv 0x00ca6b60
// src: XBOX_PDB 0x00ca6b60
void bhkNiTriStripsShape::BuildDisplayGeometry_00ca6b60(NiNode* parent, int arg)
{
    using namespace fnv_00ca6b60;
    ScopedMemContext context(0x10);
    int count = GetNumStrips(this);
    for (int i = 0; i < count; i++)
    {
        ShapeEntry& entry = GetStrip(this, i);
        NiObject* obj = entry.m_pData;
        if (obj)
        {
            NiTriStripsData* data = IsTriStripsData(obj) ? (NiTriStripsData*)obj : 0;
            if (data)
            {
                NiTriStrips* strips = new NiTriStrips(data);
                strips->SetName(NiFixedString("bhkNiTriStripsShape"));
                strips->m_kLocal.m_fScale = fabs(GetScaleValue());
                int layer = entry.m_pData ? (((NiTriStripsData*)entry.m_pData)->m_usDataFlags >> 6) & 0x1f : 0;
                SetupCollisionGeometry(strips, parent, layer, arg);
                parent->AttachChildInAvailableSlot(strips, true);
            }
        }
    }
}

hkMemoryRouter* __cdecl GetMemoryRouterC520();

class BufferC520
{
  public:
    static void* operator new(unsigned int uiSize) throw()
    {
        return GetRouterHeap(GetMemoryRouterC520()).blockAlloc(uiSize);
    }
    BufferC520() throw()
    {
        Init();
    }
    void Init() throw();
    int m_aiData0;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
};

class ConsumerC520
{
  public:
    void SetBuffer(BufferC520* pkBuffer);
};

class BufferOwnerC520
{
  public:
    BufferC520* GetBuffer(bool* pbCreated);

    int unk00;
    int unk04;
    ConsumerC520* m_pkConsumer;
    BufferC520* m_pCacheEntry;
};

// Sets *pbCreated if m_pCacheEntry was null; then creates a BufferC520 into it, passes it to m_pkConsumer if set, and returns m_pCacheEntry.
// @fnv 0x00cac520
BufferC520* BufferOwnerC520::GetBuffer(bool* pbCreated)
{
    AutoMemContext kContext(0x10);
    bool bCreate = m_pCacheEntry == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        BufferC520* pkBuffer = new BufferC520;
        m_pCacheEntry = pkBuffer;
        if (m_pkConsumer)
            m_pkConsumer->SetBuffer(pkBuffer);
    }
    return m_pCacheEntry;
}

// FUN_00cac980: __thiscall getter, 4 bytes: mov eax,[ecx+0x30]; ret
// Original index entry spans 0xcac980..0xcac993 (20 bytes): this 4-byte getter,
// 12 bytes of int3 COMDAT pad, then a byte-identical anonymous twin getter at
// 0xcac990 (mov eax,[ecx+0x30]; ret) that the pack does not index.
// Twin drafted below so a re-indexer has the neighbor shape.

struct FUN_00cac980_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* m_30;
    void* hkpCharacterProxy_getShapePhantom();
};

// @fnv 0x00cac980
// src: XBOX_PDB 0x00cac980
void* FUN_00cac980_class::hkpCharacterProxy_getShapePhantom()
{
    return m_30;
}

struct CAC980_Twin_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    void* m_30;
    void* TwinGet();
};

void* CAC980_Twin_class::TwinGet()
{
    return m_30;
}

struct GetterCAC990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_30;
    int Get();
};

// @fnv 0x00cac990
int GetterCAC990::Get()
{
    return m_30;
}

struct S00cafef0_Elem
{
    int e0;
    int e4;
    float ez;
};

struct S00cafef0_Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    float m_18;
    float m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    S00cafef0_Elem* m_30;
    float m_34;
    void UpdateBoundsFromElements();
};

// Computes min/max of element ez values over m_10*m_14 elements and stores them offset by m_34 into m_18 and m_1c.
// @fnv 0x00cafef0
void S00cafef0_Obj::UpdateBoundsFromElements()
{
    S00cafef0_Elem* p = m_30;
    if (p)
    {
        float a = p->ez;
        float b = p->ez;
        for (int i = 0; i < m_10; i++)
        {
            for (int j = 0; j < m_14; j++)
            {
                float c = p->ez;
                if (!(a < c))
                    a = c;
                if (!(b > c))
                    b = c;
                ++p;
            }
        }
        m_1c = m_34 + b;
        m_18 = m_34 + a;
    }
}

namespace fnv_00cb0b80 {
extern int DAT_01268358;
extern "C" void __cdecl hkMemoryRouter_easyFree(void*, void*);
extern "C" void __cdecl CopyIfNonEmpty(char*, const char*, int);
// src: HAVOK_LIB 0x00cb0ad0
static __declspec(noinline) char* strNdup(char* text, int count)
{
    int length = hkString_strLen((int)text);
    if (length > count)
        length = count;
    char* result = (char*)AllocateWithHeader(hkMemoryRouter_getInstance()->allocator, length + 1);
    CopyIfNonEmpty(result, text, length);
    result[length] = 0;
    return result;
}
// src: HAVOK_LIB 0x00cb0aa0
static __declspec(noinline) void* strDup(char* text)
{
    int length = hkString_strLen((int)text) + 1;
    void* result = AllocateWithHeader(hkMemoryRouter_getInstance()->allocator, length);
    hkString_strCpy(result, (int)text);
    return result;
}
struct StringSlot
{
    unsigned int* p;
};
// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(char* text, int count, StringSlot slot)
{
    unsigned int* out = slot.p;
    unsigned int old = *out;
    if ((old & ~1u) != (unsigned int)text)
    {
        if (old & 1)
        {
            hkMemoryRouter_easyFree(hkMemoryRouter_getInstance()->allocator, (void*)(old - 1));
        }
        if (text)
        {
            if (count == -1)
                *out = (unsigned int)strDup(text) + 1;
            else
                *out = (unsigned int)strNdup(text, count) + 1;
        }
        else
        {
            *out = DAT_01268358;
        }
    }
}
extern volatile int cbCount;
extern char* volatile cbText;
extern unsigned int* volatile cbOut;
void cbAssignProbe()
{
    StringSlot slot = {cbOut};
    assign_00cb0b10(cbText, cbCount, slot);
}
struct CBString
{
    unsigned int m_data;
    CBString* InitializeTextHandle(char* text);
};
// Sets m_data to the empty-string sentinel, then calls FUN_00cb0b10 to copy text into m_data and returns this.
// @fnv 0x00cb0b80
// src: GUESS 0x00cb0b80 (confidence: medium)
CBString* CBString::InitializeTextHandle(char* text)
{
    m_data = DAT_01268358;
    StringSlot slot = {&m_data};
    assign_00cb0b10(text, -1, slot);
    return this;
}
}  // namespace fnv_00cb0b80

namespace fnv_00cb0ba0 {
extern unsigned int DAT_01268358;
extern "C" void __cdecl hkMemoryRouter_easyFree(void* allocator, void* block);
extern "C" char* __cdecl strNdup(const char* text, int count);

// src: HAVOK_LIB 0x00cb0aa0
static __declspec(noinline) void* strDup(char* s)
{
    int n = hkString_strLen((int)s) + 1;
    void* block = AllocateWithHeader(hkMemoryRouter_getInstance()->allocator, n);
    hkString_strCpy(block, (int)s);
    return block;
}
void zz_probe_call(char* s)
{
    strDup(s);
}

struct StringStorageCB
{
    unsigned int handle;
    StringStorageCB* __thiscall InitializeTextHandle_00cb0ba0(const char* text, int count);
};

struct StringRefCB
{
    StringStorageCB* ptr;
};

__declspec(noinline) void AssignStringCB(StringRefCB ref, const char* text, int count)
{
    StringStorageCB* self = ref.ptr;
    unsigned int old = self->handle;
    if ((old & ~1u) == (unsigned int)text)
        return;
    if (old & 1)
        hkMemoryRouter_easyFree(hkMemoryRouter_getInstance()->allocator, (void*)(old - 1));
    if (text)
    {
        if (count == -1)
            self->handle = (unsigned int)strDup((char*)text) + 1;
        else
            self->handle = (unsigned int)strNdup(text, count) + 1;
    }
    else
    {
        self->handle = DAT_01268358;
    }
}

// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(StringRefCB ref, const char* text, int count)
{
    AssignStringCB(ref, text, count);
}

// Sets handle to DAT_01268358, then assigns text to handle via FUN_00cb0b10 and returns this.
// @fnv 0x00cb0ba0
// src: GUESS 0x00cb0ba0 (confidence: medium)
StringStorageCB* StringStorageCB::InitializeTextHandle_00cb0ba0(const char* text, int count)
{
    handle = DAT_01268358;
    StringRefCB ref = {this};
    assign_00cb0b10(ref, text, count);
    return this;
}
}  // namespace fnv_00cb0ba0

extern const LocalM128 DAT_01267e30;
extern float DAT_01016248;
extern float DAT_0101e2bc;
extern __declspec(thread) int DAT_012722b4;

struct S00cb87e0_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LocalM128 v10;
    LocalM128 v20;
    volatile float f30;
    float f34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    __forceinline S00cb87e0_Node()
    {
        f30 = DAT_01016248;
        unk00 = 0;
        unk04 = 0;
        v10 = DAT_01267e30;
        v20 = DAT_01267e30;
        f34 = DAT_0101e2bc;
    }
    void* operator new(unsigned int size) throw()
    {
        unsigned char* raw = (unsigned char*)((MemoryManager_t*)&DAT_011f6238)->Game_DoHeapAlloc(size);
        unsigned char lo = (unsigned char)raw;
        lo &= 0x0f;
        unsigned char pad = 0x10;
        pad -= lo;
        raw += pad;
        raw[-1] = pad;
        return raw;
    }
    void operator delete(void*) throw()
    {}
};

struct S00cb87e0_Guard
{
    int m_saved;
    S00cb87e0_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cb87e0_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};

struct S00cb87e0_Obj
{
    int unk00;
    int unk04;
    int m_08;
    S00cb87e0_Node* m_0c;
    void bhkOrientHingedBodyAction_CopyCinfo(S00cb87e0_Node* p);
    void* GetNode(bool* out);
};

// Ensures m_0c points to a valid S00cb87e0_Node, allocating and initializing one if null, and sets *out to true when a new node was created.
// @fnv 0x00cb87e0
void* S00cb87e0_Obj::GetNode(bool* abCreated)
{
    S00cb87e0_Guard guard;
    bool empty = (m_0c == 0);
    *abCreated = empty;
    if (empty)
    {
        unsigned char* raw = (unsigned char*)((MemoryManager_t*)&DAT_011f6238)->Game_DoHeapAlloc(sizeof(S00cb87e0_Node));
        double defaultScale = DAT_01016248;
        unsigned char low = (unsigned char)raw;
        low &= 0x0f;
        unsigned char padding = 0x10;
        padding -= low;
        raw += padding;
        raw[-1] = padding;
        S00cb87e0_Node* p = (S00cb87e0_Node*)raw;
        p->unk00 = 0;
        p->unk04 = 0;
        p->v10 = DAT_01267e30;
        p->v20 = DAT_01267e30;
        p->f30 = defaultScale;
        p->f34 = DAT_0101e2bc;
        m_0c = p;
        if (m_08)
            bhkOrientHingedBodyAction_CopyCinfo(p);
    }
    return m_0c;
}

namespace fnv_00cb96c0 {
// FUN_00cb96c0: CloneSpec::Clone(void* param) - allocate 0x70, 16-align with pad byte,
// construct, run base clone-into helper, copy cloneable fields, return the new object.

struct CloneableObj
{
    void FUN_00a6cfe0(CloneableObj* dst, void* param);
};

void __fastcall FUN_00a6d220(void* p);

extern unsigned int DAT_010c8a2c;
extern float DAT_01267e30;

struct CloneSpec : public CloneableObj
{
    unsigned int m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    LocalM128 m_u40;
    float m_f50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;

    __forceinline void* operator new(size_t size)
    {
        char* raw = (char*)((MemoryManager_t*)&_g_memoryManager)->Game_DoHeapAlloc((unsigned int)size);
        unsigned char pad = 0x10 - ((unsigned char)(unsigned int)raw & 0xF);
        raw += pad;
        raw[-1] = (char)pad;
        return raw;
    }

    __forceinline void operator delete(void* p)
    {
        unsigned char pad = ((unsigned char*)p)[-1];
        _g_memoryManager.Deallocate((char*)p - pad);
    }

    __forceinline CloneSpec()
    {
        FUN_00a6d220(this);
        m_vtbl = (unsigned int)&DAT_010c8a2c;
        m_u40 = *(const LocalM128*)&DAT_01267e30;
        m_f50 = 0.0f;
    }

    CloneSpec* bhkForceController_CreateClone(void* param);
};

// Allocates a new CloneSpec, calls FUN_00a6cfe0 on this with the new object and param, then copies m_u40 and m_f50 into it and returns it.
// @fnv 0x00cb96c0
// src: XBOX_PDB 0x00cb96c0
CloneSpec* CloneSpec::bhkForceController_CreateClone(void* param)
{
    CloneSpec* obj = new CloneSpec();
    FUN_00a6cfe0(obj, param);
    obj->m_u40 = m_u40;
    obj->m_f50 = m_f50;
    return obj;
}
}  // namespace fnv_00cb96c0

extern int DAT_010c81ac;

struct SpawnMidBase : FUN_00c87c30
{
    InitializedField unk0c;
    SpawnMidBase()
    {
        vtable = &DAT_0108febc;
        ++DAT_01268188;
    }
};

struct FUN_00cb9a10 : SpawnMidBase
{
    FUN_00cb9a10(char* source);
    void SpawnAndAttach(char* source);
};

// Sets the vtable, calls SpawnAndAttach with source+4 or 0, and increments DAT_0126830c.
// @fnv 0x00cb9a10
FUN_00cb9a10::FUN_00cb9a10(char* source)
{
    vtable = &DAT_010c81ac;
    SpawnAndAttach(source ? source + 4 : 0);
    ++DAT_0126830c;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

class CbaItem
{
  public:
    virtual ~CbaItem();
};

// Gamebryo-style array whose storage is released through its own virtual Free.
template <class T> class CbaArray
{
  public:
    virtual ~CbaArray()
    {
        RemoveAll();
    }
    virtual void* Allocate(unsigned int ItemUpdateArray);
    virtual void Free(void* pvMem);

    void RemoveAll()
    {
        if (m_pBase)
        {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }

    unsigned int GetSize() const
    {
        return m_uiSize;
    }
    T& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    T* m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
};

class CbaBase
{
  public:
    virtual ~CbaBase();  // FUN_00a5d3d0
    unsigned int unk04;
};

class FUN_00cba1d0 : public CbaBase
{
  public:
    virtual ~FUN_00cba1d0();

    NiFixedString m_kName;
    CbaArray<CbaItem*> m_kUnsortedGeometryList;
    CbaArray<void*> m_kOther;
};

// Deletes each CbaItem* in m_kUnsortedGeometryList and then releases the array's storage via RemoveAll.
// @fnv 0x00cba1d0
FUN_00cba1d0::~FUN_00cba1d0()
{
    for (unsigned int i = 0; i < m_kUnsortedGeometryList.GetSize(); i++)
        delete m_kUnsortedGeometryList.GetAt(i);
    m_kUnsortedGeometryList.RemoveAll();
}

// @fnv 0x00cbb920
// src: GUESS 0x00cbb920 (confidence: high)
void __cdecl Object_DoNothing_00cbb920()
{}

extern int DAT_0126841c;

struct CB920Entry
{
    void* m_uiFilterValue;
    CB920Entry* m_pNext;

    void Remove(void*& item);
    void Cleanup();
};

struct CB920Map
{
    void GetAt(void* key, void** out) const;
    void RemoveAt(void* key);
};

extern CB920Map DAT_011b2190;

struct CB920Base
{
    virtual ~CB920Base();
};

static void CB920SetTag(int aiAllocationTag)
{
    g_tlsBlock.m_2b4 = aiAllocationTag;
}

struct CB920Guard
{
    int m_saved;

    CB920Guard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    void Leave()
    {
        CB920SetTag(m_saved);
    }

    ~CB920Guard()
    {
        Leave();
    }
};

struct FUN_00cbc920 : CB920Base
{
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* m_name;

    void Cleanup();
    virtual ~FUN_00cbc920();
};

// Removes this object from the CB920Map entry for m_name, cleans up the entry if it becomes empty, calls Cleanup, and decrements DAT_0126841c.
// @fnv 0x00cbc920
FUN_00cbc920::~FUN_00cbc920()
{
    CB920Guard kGuard;
    if (m_name != 0)
    {
        void* pValue = 0;
        DAT_011b2190.GetAt(m_name, &pValue);
        if (pValue != 0)
        {
            CB920Entry* pEntry = (CB920Entry*)pValue;
            pValue = this;
            pEntry->Remove(pValue);
            if (pEntry->m_pNext == 0 && pEntry->m_uiFilterValue == 0)
            {
                void* key = m_name;
                DAT_011b2190.RemoveAt(key);
                pEntry->Cleanup();
                _g_memoryManager.Deallocate(pEntry);
            }
        }
    }
    Cleanup();
    --DAT_0126841c;
}

struct ChainNode
{
    int m_00;
    int m_04;
    int m_08;
    ChainNode* m_0c;
};

struct ChainSource
{
    LocalM128 m_00;
    LocalM128 m_10;
    ChainNode* m_20;
    ChainNode* m_24;
};

struct ChainDest
{
    LocalM128 m_00;
    LocalM128 m_10;
    ChainNode* m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    ChainNode* m_48;
    int m_4c;
    int m_50[1];
};

// Copies two vectors, stores the end node of each chain in dst, and writes the second chain's m_04 values to dst->m_50 followed by -1.
// @fnv 0x00cbd700
// src: COMMUNITY 0x00cbd700
static __declspec(noinline) void setHit(ChainSource* src, ChainDest* dst)
{
    dst->m_00 = src->m_00;
    dst->m_10 = src->m_10;

    ChainNode* node = src->m_20;
    while (node->m_0c)
        node = node->m_0c;
    dst->m_20 = node;

    node = src->m_24;
    while (node->m_0c)
        node = node->m_0c;
    dst->m_48 = node;

    dst->m_24 = src->m_20->m_04;
    dst->m_4c = src->m_24->m_04;

    int count = 0;
    ChainNode* n = src->m_24;
    while (n->m_0c)
    {
        n = n->m_0c;
        ++count;
    }

    ChainNode* cur = src->m_24;
    dst->m_50[count] = -1;
    for (int i = count - 1; i >= 0; i--)
    {
        dst->m_50[i] = cur->m_04;
        cur = cur->m_0c;
    }
}

void __cdecl InsertIntoContext(void* pList, void* pContext)
{
    setHit((ChainSource*)pList, (ChainDest*)pContext);
}

// @fnv 0x00cbf190
// src: GUESS 0x00cbf190 (confidence: high)
void __cdecl Runtime_DoNothing_00cbf190()
{}

// Floors a float (rounds toward negative infinity) using integer bit manipulation of its IEEE-754 representation.
// @fnv 0x00cbfd80
// src: HAVOK_LIB 0x00cbfd80
float __cdecl hkMath_hkFloor(float value)
{
    union
    {
        float f;
        int i;
    } u;
    u.f = value;
    int x = u.i;
    int e = (((unsigned)x >> 23) & 0xff) - 127;
    int t = 23 - e;
    int ns = ~(t >> 31);
    x &= ~(((x & 0x7fffffff) - 1) >> 31);
    int mask = ((int)0xff800000 >> ((ns & 23) - (ns & t))) | ~ns;
    int sign = x >> 31;
    int frac = ~((~mask & x) - 1) & (0x800000 >> e) & sign;
    int neg = e >> 31;
    u.i = ((frac + x) & ~neg & mask) | (neg & sign & 0xbf800000);
    return u.f;
}

extern double DAT_010c9300;
extern double DAT_010c92f8;
extern double DAT_010c92f0;
extern double DAT_01030f38;
extern double DAT_0101ff40;
// Polynomial approximation of atan2 with x as numerator and y as denominator, adjusted using the signs of y and x.
// @fnv 0x00cbff80
float __cdecl Atan2(float x, float y)
{
    float ax = (float)fabs(x);
    float ay = (float)fabs(y);
    float t, result;
    if (ax <= ay)
    {
        t = ax / (float)(ay + DAT_010c9300);
        float tCopy = t;
        float partial = tCopy - (t * DAT_010c92f8) * t;
        result = partial - t * (t * (t * DAT_010c92f0));
    }
    else
    {
        t = ay / (float)(ax + DAT_010c9300);
        float tCopy = t;
        float partial = tCopy - (t * DAT_010c92f8) * t;
        result = partial - t * (t * (t * DAT_010c92f0));
        result = (float)(DAT_01030f38 - result);
    }
    if (y < 0.0f)
        result = (float)(DAT_0101ff40 - result);
    if (x < 0.0f)
        result = -result;
    return result;
}

namespace fnv_00ca3b00 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00ca3b00();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00ca3b00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ca3b00
// src: GUESS 0x00ca3b00 (confidence: low)
    virtual void AdjustThisAndForward_00ca3b00();
};

Derived::Derived()
{}
}  // namespace fnv_00ca3b00

namespace fnv_00ca4510 {
// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00ca4510();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00ca4510();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ca4510
    virtual void FUN_00ca4510();
};

Derived::Derived()
{}
}  // namespace fnv_00ca4510

extern int DAT_010c771c;
extern int g_fnvDecompCounter;

struct ScopeHost_cls
{
    void* m_vptr;
    void bhkSerializable_Kill();
    void FUN_00cd2de0();
    void ProcessState_00ca6590();
};

struct OwnerGuard_cls
{
    ScopeHost_cls* m_pOwnerObject;
    OwnerGuard_cls(ScopeHost_cls* owner)
    {
        m_pOwnerObject = owner;
        owner->m_vptr = &DAT_010c771c;
    }
    ~OwnerGuard_cls()
    {
        m_pOwnerObject->FUN_00cd2de0();
    }
};

// Sets a guard on this (sets the vtable pointer, calls FUN_00cd2de0 on exit), calls FUN_00c876a0, and decrements g_fnvDecompCounter.
// @fnv 0x00ca6590
// src: GUESS 0x00ca6590 (confidence: low)
void ScopeHost_cls::ProcessState_00ca6590()
{
    OwnerGuard_cls guard(this);
    bhkSerializable_Kill();
    --g_fnvDecompCounter;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00ca6780_sub
{
    unsigned int unk00;
    int m_04;
    int(__cdecl* m_08)(void* a, volatile unsigned int* b, unsigned int c, unsigned int d, unsigned int e);
};

struct FUN_00ca6780_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned short unk1E6;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00ca6780_sub* m_24c;
};

struct FUN_00ca6780_cls
{
    virtual void v00();

    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual int v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* v2D(unsigned char* out);
    int bhkNiTriStripsShape_LoadCInfo(FUN_00ca6780_arg* a1);
};

// @fnv 0x00ca6780
// src: XBOX_PDB 0x00ca6780
int FUN_00ca6780_cls::bhkNiTriStripsShape_LoadCInfo(FUN_00ca6780_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = v2D((unsigned char*)&tmp + 3);
    int size = v2A();
    if (a1->unk04 < 4)
    {
        size -= 0x10;
    }
    FUN_00ca6780_sub* sub = a1->m_24c;
    sub->m_04 += sub->m_08(sub, p, size, 0, 0);
    if (a1->m_1e5 != 1 && a1->unk04 >= 4)
    {
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
    }
    return size;
}

struct BlockData
{
    LocalM128 position;
    LocalM128 rotation;
};
// Deferred physics command queued by EnqueueTransform (0x00ca8960): type byte (0x18 = set transform), owner,
// 32-byte BlockData payload; handed to the queue at 0x00c91160. Not the console-command Command.
struct DeferredPhysicsCommand
{
    unsigned char type;
    void* owner;
    BlockData* data;
};
struct QueueCA8960
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    void __thiscall hkpWorld_queueOperation(DeferredPhysicsCommand* cmd);
};
struct AllocCA8960
{
    virtual void v00();
    virtual BlockData* Allocate(unsigned int bytes);
};
struct FUN_00ca8960_Class
{
    int unk00;
    int unk04;
    QueueCA8960* queue08;
    void __thiscall hkpRigidBody_setPositionAndRotation(const LocalM128* position, const LocalM128* rotation);
    void EnqueueTransform(const LocalM128* position, const LocalM128* rotation);
};
// If queue08 is set and its unk94 is nonzero, queues a type 0x18 command holding position and rotation; otherwise calls FUN_00ca8860 with them.
// @fnv 0x00ca8960
void FUN_00ca8960_Class::EnqueueTransform(const LocalM128* position, const LocalM128* rotation)
{
    if (queue08 && queue08->unk94)
    {
        DeferredPhysicsCommand cmd;
        cmd.type = 0x18;
        cmd.owner = this;
        FNVTaskMemoryRouter* router = hkMemoryRouter_getInstance();
        cmd.data = ((AllocCA8960*)router->allocator)->Allocate(32);
        cmd.data->position = *position;
        cmd.data->rotation = *rotation;
        queue08->hkpWorld_queueOperation(&cmd);
    }
    else
        hkpRigidBody_setPositionAndRotation(position, rotation);
}

namespace fnv_00cabf30 {
// sub ecx,8; jmp FUN_00cac120  ==  MSVC adjustor thunk for a secondary base at offset 8.
struct PrimaryBase
{
    virtual void FUN_00cabf30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00cabf30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cabf30
    virtual void FUN_00cabf30();
};

Derived::Derived()
{}
}  // namespace fnv_00cabf30

// Adjustor thunk for FUN_00cabf40: sub ecx,0xc; jmp FUN_00cac120.
// Primary base sized 12 (vptr + 8 pad) so the secondary->primary
// this adjustment is exactly 0xc.

struct Prim_00cabf40
{
    virtual void AdjustThisAndForward_00cabf40();
    int m04;
    int m08;
};

struct Sec_00cabf40
{
    virtual void AdjustThisAndForward_00cabf40();
};

struct TO_00cabf40 : Prim_00cabf40, Sec_00cabf40
{
// @fnv 0x00cabf40
// src: GUESS 0x00cabf40 (confidence: low)
    virtual void AdjustThisAndForward_00cabf40();
};

// Forces vtable emission: the override lands in both the primary and the
// secondary vftable, so VC9 emits [thunk]:TO_00cabf40::FUN_00cabf40
// 'adjustor{12}' = sub ecx,0xc ; jmp TO_00cabf40::FUN_00cabf40.
static TO_00cabf40 g_thunk_00cabf40;

struct CAC410_TLSState
{
    char m_ucUnknownByte[0x2B4];
    int m_uiFilterValue;
};

__declspec(thread) CAC410_TLSState g_CAC410_TLSState;

struct CAC410_RefCounted
{
    virtual void Dummy();
    virtual void Release();
};

struct FUN_00cac980_Result
{
    void* m_vtbl;
    int m_iWordAt04;
    int m_8;
    CAC410_RefCounted* m_iThirdValue;
};

struct CAC410_ScopedValue
{
    int m_oldValue;

    CAC410_ScopedValue() : m_oldValue(g_CAC410_TLSState.m_uiFilterValue)
    {
        g_CAC410_TLSState.m_uiFilterValue = 0x10;
    }

    ~CAC410_ScopedValue()
    {
        g_CAC410_TLSState.m_uiFilterValue = m_oldValue;
    }
};

// Sets a scoped TLS value to 0x10, calls FUN_00cac980 on the holder at pThis+8, and drops one reference on the object in its result.
// @fnv 0x00cac410
// src: XBOX_PDB 0x00cac410
void __fastcall bhkCharacterProxy_RembhkRefs(void* pThis)
{
    CAC410_ScopedValue scopedValue;

    FUN_00cac980_Holder* holder = *reinterpret_cast<FUN_00cac980_Holder**>(reinterpret_cast<char*>(pThis) + 8);

    if (holder)
    {
        void* result = holder->hkpCharacterProxy_getShapePhantom();
        if (result)
        {
            CAC410_RefCounted* object = static_cast<FUN_00cac980_Result*>(result)->m_iThirdValue;

            if (object)
            {
                if (InterlockedDecrement(reinterpret_cast<LONG volatile*>(reinterpret_cast<char*>(object) + 4)) == 0)
                {
                    object->Release();
                }
            }
        }
    }
}

extern int DAT_01268358;
void CB0Free(void* p);
int CB0Len(const char* s);

struct CB0StringPtr
{
    int m_pcText;
    CB0StringPtr(const CB0StringPtr& other);
    const char* cString() const
    {
        return (const char*)(m_pcText & ~1);
    }
};

struct CB0SelfRef
{
    CB0StringPtr* p;
};
// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(CB0SelfRef selfRef, const char* s, int len)
{
    CB0StringPtr* self = selfRef.p;
    if (len == -1)
        len = CB0Len(s);
    self->m_pcText = (int)s + len;
}

// Sets m_pcText to DAT_01268358, then calls FUN_00cb0b10 with other's string and length -1, which stores the string's end pointer in m_pcText.
// @fnv 0x00cb0bd0
CB0StringPtr::CB0StringPtr(const CB0StringPtr& other)
{
    m_pcText = DAT_01268358;
    CB0SelfRef r;
    r.p = this;
    assign_00cb0b10(r, other.cString(), -1);
}

struct CC3320Info
{
    unsigned int unk00, unk04, unk08, unk0c;
    LocalM128 vec10, vec20;
    float out30, out34;
};
struct CC3320Source
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    LocalM128 vec20, vec30;
    unsigned int unk40, unk44, unk48, unk4c;
    float value50, value54;
};
struct CC3320Base
{
    int unk00;
    void __thiscall GetInfo(CC3320Info* info);
};
struct FUN_00cb84a0_cls : CC3320Base
{
    int unk04;
    CC3320Source* src08;
    void bhkOrientHingedBodyAction_CopyCinfo(CC3320Info* info);
};
// Calls GetInfo, then copies vec20, vec30, value50 and value54 from src08 into info's vec10, vec20, out30 and out34.
// @fnv 0x00cb84a0
// src: XBOX_PDB 0x00cb84a0
void FUN_00cb84a0_cls::bhkOrientHingedBodyAction_CopyCinfo(CC3320Info* info)
{
    GetInfo(info);
    CC3320Source* src = this ? src08 : 0;
    info->vec10 = src->vec20;
    info->vec20 = src->vec30;
    info->out30 = src->value50;
    info->out34 = src->value54;
}

struct S00cb8590_Out
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
};

struct S00cb8590_Obj
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    int unk01b0;
    int unk01b4;
    int unk01b8;
    int unk01bc;
    int unk01c0;
    int unk01c4;
    int unk01c8;
    int unk01cc;
    int unk01d0;
    int unk01d4;
    int unk01d8;
    int unk01dc;
    int unk1e0;
    unsigned char unk1e4;
    unsigned char unk1e5;
};

void __stdcall bhkUnaryAction_LoadBinary(S00cb8590_Obj* p);

struct S00cb8590_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v1a()
    {}
    virtual void v1b()
    {}
    virtual void v1c()
    {}
    virtual void v1d()
    {}
    virtual void v1e()
    {}
    virtual void v1f()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v2a()
    {}
    virtual void v2b()
    {}
    virtual void v2c()
    {}
    virtual S00cb8590_Out* vfn2d(S00cb8590_Obj** pp)
    {
        return 0;
    }
    void bhkOrientHingedBodyAction_LoadBinary(int a0);
};
static __forceinline void S00cb8590_swapAll(S00cb8590_Out* p)
{
    p->unk10 = _byteswap_ulong(p->unk10);
    _ReadWriteBarrier();
    p->unk14 = _byteswap_ulong(p->unk14);
    _ReadWriteBarrier();
    p->unk18 = _byteswap_ulong(p->unk18);
    _ReadWriteBarrier();
    p->unk1c = _byteswap_ulong(p->unk1c);
    _ReadWriteBarrier();
    p->unk20 = _byteswap_ulong(p->unk20);
    _ReadWriteBarrier();
    p->unk24 = _byteswap_ulong(p->unk24);
    _ReadWriteBarrier();
    p->unk28 = _byteswap_ulong(p->unk28);
    _ReadWriteBarrier();
    p->unk2c = _byteswap_ulong(p->unk2c);
    _ReadWriteBarrier();
    p->unk30 = _byteswap_ulong(p->unk30);
    _ReadWriteBarrier();
    p->unk34 = _byteswap_ulong(p->unk34);
    _ReadWriteBarrier();
}

// Calls FUN_00c86790 on the object; unless its unk1e5 is 1, byte-swaps the ten 32-bit fields at 0x10-0x34 of the vfn2d result.
// @fnv 0x00cb8590
// src: XBOX_PDB 0x00cb8590
void S00cb8590_cls::bhkOrientHingedBodyAction_LoadBinary(int apObj)
{
    S00cb8590_Obj* o = reinterpret_cast<S00cb8590_Obj*>(*(volatile int*)&apObj);
    bhkUnaryAction_LoadBinary(o);
    if (o->unk1e5 != 1)
    {
        S00cb8590_swapAll(vfn2d(reinterpret_cast<S00cb8590_Obj**>(&apObj)));
    }
}

struct FUN_00c868b0_Obj
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
};

struct FUN_00cb8610_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}

    virtual void bhkOrientHingedBodyAction_SaveBinary(void* arg);

    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}

    virtual FUN_00c868b0_Obj* vfB4(unsigned char* value);

    void bhkUnaryAction_SaveBinary(void* arg);
};

// If the byte at arg+0x1E4 is not 1, byte-swaps ten fields of the vfB4 result before and after calling FUN_00c868b0(arg).
// @fnv 0x00cb8610
// src: XBOX_PDB 0x00cb8610
void __thiscall FUN_00cb8610_Class::bhkOrientHingedBodyAction_SaveBinary(void* arg)
{
    unsigned char value;
    FUN_00c868b0_Obj* result = vfB4(&value);

    if (*((unsigned char*)arg + 0x1E4) != 1)
    {
        result->unk10 = _byteswap_ulong(result->unk10);
        _ReadWriteBarrier();
        result->unk14 = _byteswap_ulong(result->unk14);
        _ReadWriteBarrier();
        result->unk18 = _byteswap_ulong(result->unk18);
        _ReadWriteBarrier();
        result->unk1C = _byteswap_ulong(result->unk1C);
        _ReadWriteBarrier();
        result->unk20 = _byteswap_ulong(result->unk20);
        _ReadWriteBarrier();
        result->unk24 = _byteswap_ulong(result->unk24);
        _ReadWriteBarrier();
        result->unk28 = _byteswap_ulong(result->unk28);
        _ReadWriteBarrier();
        result->unk2C = _byteswap_ulong(result->unk2C);
        _ReadWriteBarrier();
        result->unk30 = _byteswap_ulong(result->unk30);
        _ReadWriteBarrier();
        result->unk34 = _byteswap_ulong(result->unk34);
    }

    bhkUnaryAction_SaveBinary(arg);

    if (*((unsigned char*)arg + 0x1E4) != 1)
    {
        result->unk10 = _byteswap_ulong(result->unk10);
        _ReadWriteBarrier();
        result->unk14 = _byteswap_ulong(result->unk14);
        _ReadWriteBarrier();
        result->unk18 = _byteswap_ulong(result->unk18);
        _ReadWriteBarrier();
        result->unk1C = _byteswap_ulong(result->unk1C);
        _ReadWriteBarrier();
        result->unk20 = _byteswap_ulong(result->unk20);
        _ReadWriteBarrier();
        result->unk24 = _byteswap_ulong(result->unk24);
        _ReadWriteBarrier();
        result->unk28 = _byteswap_ulong(result->unk28);
        _ReadWriteBarrier();
        result->unk2C = _byteswap_ulong(result->unk2C);
        _ReadWriteBarrier();
        result->unk30 = _byteswap_ulong(result->unk30);
        _ReadWriteBarrier();
        result->unk34 = _byteswap_ulong(result->unk34);
    }
}

// bhkRagdollTemplate::bhkRagdollTemplate @ 0xcbaf20 (84 bytes)
// ctor: NiExtraData base ctor (0xa7b2e0), derived vftable (0x10c8dcc), then member
// BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> (vftable 0x10c8d28 + three
// zero stores) constructed inline; returns this.
// The original carries a dead /GS+EH unwind-only registration frame (FuncInfo
// optimizer folded away, and the c1 EH scope (unwind funclet destroys the base
// subobject) survived as stale weight.

// base NiExtraData: named after its ctor's address so the implicit base-ctor
// call binds to 0xa7b2e0
struct FUN_00a7b2e0
{
    virtual void v0();
    unsigned int unk04;
    unsigned int unk08;
    FUN_00a7b2e0();
    ~FUN_00a7b2e0();
};

struct AryType
{  // BSSimpleArray<NiPointer<bhkRagdollTemplateData>,1024> stand-in
    virtual void v0();
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
    AryType();
};

class FUN_00cbaf20 : public FUN_00a7b2e0
{
  public:
    AryType m_data;
    FUN_00cbaf20();
};

AryType::AryType()
{
    if (0)
        throw 1;
    m_pData = 0;
    m_uiSize = 0;
    m_uiMaxSize = 0;
}

// Default constructor for FUN_00cbaf20; the body is empty and the base class and m_data member are default-constructed implicitly.
// @fnv 0x00cbaf20
FUN_00cbaf20::FUN_00cbaf20()
{}

struct SearchNodeCB
{
    int unk00;
    unsigned int id;
    int unk08;
    SearchNodeCB* parent;
};

struct InputCB
{
    LocalM128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* first;
    SearchNodeCB* second;
};

struct OutputCB
{
    LocalM128 point;
    float x;
    float y;
    float z;
    float score;
    SearchNodeCB* firstRoot;
    unsigned int firstId;
    int unk28_0;
    int unk28_1;
    int unk28_2;
    int unk28_3;
    int unk28_4;
    int unk28_5;
    int unk28_6;
    int unk28_7;
    SearchNodeCB* secondRoot;
    unsigned int secondId;
    unsigned int secondPath[8];
};

struct ContextCB
{
    int unk00;
    float limit;
    OutputCB* begin;
    OutputCB* next;
    int capacity;
    int size;
};

static __declspec(noinline) void CopyCB(OutputCB* dest, const InputCB* src)
{
    dest->point = src->point;
    *(LocalM128*)&dest->x = *(LocalM128 const*)&src->x;
    SearchNodeCB* c = src->first;
    while (c->parent)
        c = c->parent;
    dest->firstRoot = c;
    c = src->second;
    while (c->parent)
        c = c->parent;
    dest->secondRoot = c;
    dest->firstId = src->first->id;
    dest->secondId = src->second->id;
    SearchNodeCB* h = src->second;
    int count = 0;
    SearchNodeCB* n = h->parent;
    while (n)
    {
        n = n->parent;
        ++count;
    }
    dest->secondPath[count] = 0xffffffff;
    int i = count - 1;
    while (i >= 0)
    {
        dest->secondPath[i] = h->id;
        h = h->parent;
        --i;
    }
}

// Adds input to context, or when full replaces the highest-score entry if input's score is lower, then sets context->limit to the highest remaining score.
// @fnv 0x00cbd7a0
void __cdecl InsertIntoContext(const InputCB* input, ContextCB* context)
{
    if (context->capacity)
    {
        if (context->size < context->capacity)
        {
            CopyCB(context->next, input);
            ++context->size;
            ++context->next;
            return;
        }
        OutputCB* end = context->begin + context->size;
        OutputCB* cur = context->begin;
        OutputCB* best = cur++;
        __assume(cur < end);
        for (; cur < end; ++cur)
            if (cur->score > best->score)
                best = cur;
        if (input->score < best->score)
        {
            CopyCB(best, input);
            cur = context->begin;
            best = cur++;
            __assume(cur < end);
            for (; cur < end; ++cur)
                if (cur->score > best->score)
                    best = cur;
        }
        context->limit = best->score;
    }
}

struct FUN_00cbda30_io;

struct FUN_00cbda30_io
{
    unsigned int unk00;
    unsigned int m04;
    unsigned int(__cdecl* m08)(FUN_00cbda30_io*, void*, unsigned int, unsigned int, unsigned int);
};

struct FUN_00cbda30_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
    char unk1E6;
    char unk1E7;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    FUN_00cbda30_io* m24C;
};

struct FUN_00cbda30_rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00cbda30_cls
{
    virtual void v00()
    {}
    FUN_00cbda30_rec* m04;
    void hkConstraintCinfo_LoadBinary(FUN_00cbda30_arg* a);
    void ReadRecord(FUN_00cbda30_arg* a1);
};

void SwapEndianBlocks(void* p);

extern "C" void _ReadWriteBarrier(void);
unsigned int* __cdecl SwapEndianBlocks(unsigned int* arg);

// Calls FUN_00c8a230, reads two 0x40-byte blocks at offsets 0x20 and 0x60 of m04 via a1->m24C, and byte-swaps them unless a1->m1E5 is 1.
// @fnv 0x00cbda30
void FUN_00cbda30_cls::ReadRecord(FUN_00cbda30_arg* a1)
{
    hkConstraintCinfo_LoadBinary(a1);
    FUN_00cbda30_rec* p = m04;
    FUN_00cbda30_io* io = a1->m24C;
    FUN_00cbda30_rec* b = (FUN_00cbda30_rec*)((char*)p + 0x20);
    io->m04 += io->m08(io, b, 0x40, 0, 0);
    io = a1->m24C;
    FUN_00cbda30_rec* q = (FUN_00cbda30_rec*)((char*)p + 0x60);
    io->m04 += io->m08(io, q, 0x40, 0, 0);
    p = q;
    if (a1->m1E5 != 1)
    {
        b->m30 = _byteswap_ulong(b->m30);
        _ReadWriteBarrier();
        b->m34 = _byteswap_ulong(b->m34);
        _ReadWriteBarrier();
        b->m38 = _byteswap_ulong(b->m38);
        _ReadWriteBarrier();
        b->m3C = _byteswap_ulong(b->m3C);
        SwapEndianBlocks((unsigned int*)b);
        p->m30 = _byteswap_ulong(p->m30);
        _ReadWriteBarrier();
        p->m34 = _byteswap_ulong(p->m34);
        _ReadWriteBarrier();
        p->m38 = _byteswap_ulong(p->m38);
        _ReadWriteBarrier();
        p->m3C = _byteswap_ulong(p->m3C);
        SwapEndianBlocks((unsigned int*)p);
    }
}

struct CA3F10MemMgr
{
    void* Allocate(unsigned int size);
};
extern CA3F10MemMgr g_kCA3F10MemMgr;

struct CA3F10BinaryStream
{
    void* unk00;
    unsigned int m_uiStreamFlags;
    unsigned int (*m_pfnRead)(CA3F10BinaryStream* pkStream, void* pvBuffer, unsigned int uiBytes,
                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

struct CA3F10Stream
{
    void* unk00;
    unsigned int m_uiFormatVersion;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    CA3F10BinaryStream* m_pUnderlyingStream;
};

template <class T> inline unsigned int CA3F10LoadBinary(CA3F10BinaryStream& kStream, T& val)
{
    unsigned int uiSize = sizeof(T);
    return kStream.BinaryRead(&val, sizeof(T), &uiSize, 1);
}

extern unsigned int DAT_011b1750[];
extern unsigned int DAT_011b1754[];

struct CA3F10Triangle
{
    unsigned int uiVerts01;
    unsigned int uiVert2Welding;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};

struct CA3F10OldTriangle
{
    CA3F10Triangle kTri;
    float f08;
    float f0c;
    float f10;
};

struct CA3F10Vertex
{
    float x;
    float y;
    float z;
    CA3F10Vertex()
    {}
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};

struct CA3F10Normal
{
    float x;
    float y;
    float z;
    static void* operator new[](unsigned int size)
    {
        return g_kCA3F10MemMgr.Allocate(size);
    }
};

struct CA3F10Data
{
    int unk00;
    int unk04;
    unsigned int m_uiTriangles;
    unsigned int m_uiVertices;
    unsigned short m_usNormals;
    unsigned short unk12;
    CA3F10Triangle* m_pkTriangles;
    CA3F10Vertex* m_pkVertices;
    int unk1c;
    int unk20;
    CA3F10Normal* m_pkNormals;

    void hkPackedNiTriStripsData_LoadBinary(CA3F10Stream* pkStream);
};

// Reads triangle, vertex, and normal data from a CA3F10Stream, handling format version differences for triangle and vertex reading.
// @fnv 0x00ca3f10
// src: XBOX_PDB 0x00ca3f10
void CA3F10Data::hkPackedNiTriStripsData_LoadBinary(CA3F10Stream* pkStream)
{
    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_uiTriangles);
    m_pkTriangles = new CA3F10Triangle[m_uiTriangles];
    if (pkStream->m_uiFormatVersion < 0x21)
    {
        for (unsigned int i = 0; i < m_uiTriangles; i++)
        {
            CA3F10OldTriangle kOld;
            pkStream->m_pUnderlyingStream->BinaryRead(&kOld, sizeof(kOld), DAT_011b1754, 7);
            CA3F10Triangle& kTri = m_pkTriangles[i];
            kTri.uiVerts01 = kOld.kTri.uiVerts01;
            kTri.uiVert2Welding = kOld.kTri.uiVert2Welding;
        }
    }
    else
    {
        pkStream->m_pUnderlyingStream->BinaryRead(m_pkTriangles, m_uiTriangles * sizeof(CA3F10Triangle), DAT_011b1754,
                                                  4);
    }

    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_uiVertices);
    if (pkStream->m_uiFormatVersion >= 0x22)
    {
        CA3F10BinaryStream* pkIstr = pkStream->m_pUnderlyingStream;
        unsigned int (*pfnRead)(CA3F10BinaryStream*, void*, unsigned int, unsigned int*, unsigned int) =
            pkIstr->m_pfnRead;
        bool bUnused;
        unsigned int uiSize = 1;
        unsigned int uiRead = pfnRead(pkIstr, &bUnused, 1, &uiSize, 1);
        pkIstr->m_uiStreamFlags += uiRead;
        CA3F10Vertex* pkVerts = new CA3F10Vertex[m_uiVertices];
        unsigned int uiBytes = m_uiVertices * sizeof(CA3F10Vertex);
        m_pkVertices = pkVerts;
        pkStream->m_pUnderlyingStream->BinaryRead(pkVerts, uiBytes, DAT_011b1750, 1);
    }
    else
    {
        CA3F10Vertex* pkVerts = new CA3F10Vertex[m_uiVertices];
        unsigned int uiBytes = m_uiVertices * sizeof(CA3F10Vertex);
        m_pkVertices = pkVerts;
        pkStream->m_pUnderlyingStream->BinaryRead(pkVerts, uiBytes, DAT_011b1750, 1);
    }

    CA3F10LoadBinary(*pkStream->m_pUnderlyingStream, m_usNormals);
    m_pkNormals = new CA3F10Normal[m_usNormals];
    pkStream->m_pUnderlyingStream->BinaryRead(m_pkNormals, m_usNormals * sizeof(CA3F10Normal), DAT_011b1750, 1);
}


extern "C" int DAT_010c82ec;
struct Rec9bd0;

struct Sub9bd0
{
    int v;
    void hkpBridgeConstraintAtom_init(Rec9bd0*);
};
struct Item9bd0
{
    void FUN_00c905b0();
};
struct Rec9bd0
{
    void* vt;
    unsigned short cap, fl;
    int pad[2];
    Sub9bd0 sub;
    int pad2[2];
    float score;
    void UpdateFields_00ca9b40(Item9bd0*);
    void FUN_00ca9aa0();
    static void* operator new(unsigned int size)
    {
        Rec9bd0* m = (Rec9bd0*)GetRouterHeap((hkMemoryRouter*)hkMemoryRouter_getInstance()).blockAlloc(size);
        m->cap = (unsigned short)size;
        return m;
    }
    static void operator delete(void*);
    Rec9bd0()
    {
        FUN_00ca9aa0();
        vt = &DAT_010c82ec;
    }
};
struct Ctx9bd0
{
    int a, b, c;
    void* coll;
    int d[3];
    float score;
};
extern "C" Item9bd0* __cdecl CreateF4A30Result(void* c, int k);
struct Key9bd0
{
    int value;
};
struct Owner9bd0
{
    int u;
    Ctx9bd0* ctx;
    void ReleaseObject(Rec9bd0*, int);
    void hkMalleableConstraintCinfo_CloneData(Rec9bd0* r, Key9bd0 key);
};
extern "C" void _ReadWriteBarrier();
// Uses r or allocates a Rec9bd0, attaches an item made by CreateF4A30Result from ctx->coll and key, copies ctx->score, then calls ReleaseObject(rec, key).
// @fnv 0x00ca9bd0
// src: XBOX_PDB 0x00ca9bd0
void Owner9bd0::hkMalleableConstraintCinfo_CloneData(Rec9bd0* apRecord, Key9bd0 key)
{
    TlsGuard_t s;
    Ctx9bd0* c = ctx;
    Rec9bd0* rec = apRecord;
    if (rec == 0)
        rec = new Rec9bd0;
    void* coll = c->coll;
    int k = *(volatile int*)&key.value;
    _ReadWriteBarrier();
    Item9bd0* pItem = coll ? CreateF4A30Result(coll, k) : 0;
    if (pItem)
    {
        rec->UpdateFields_00ca9b40(pItem);
        pItem->FUN_00c905b0();
    }
    float sc = c->score;
    rec->score = sc;
    rec->sub.hkpBridgeConstraintAtom_init(rec);
    ReleaseObject(rec, k);
}

// 0x00cabcd0  340 B  /MT /O2 /GS /EHsc /Gy  - HSV ramp helper.
extern double FUN_00ec6940(double);
struct ColorOutput
{
    float* value;
};

// Converts HSV color components to RGB, writing the result to pR, pG, and out1, with a special case for zero saturation.
// @fnv 0x00cabcd0
static __declspec(noinline) void HsvToRgb(float* apRed, float afHue, float afSaturation, float afValue, float* apGreen,
                                          float* apBlue)
{
    (void)apBlue;
    (void)apGreen;
    float*& red = apRed;
    float p, q, t, f;
    int i;
    if (afSaturation == 0.0f)
    {
        *apBlue = afValue;
        *apGreen = afValue;
        *red = afValue;
        return;
    }
    if (afHue == 1.0f)
    {
        i = 5;
        afHue = 6.0f;
    }
    else
    {
        afHue = afHue * 6.0;
        i = (int)(float)FUN_00ec6940(afHue);
    }
    f = afHue - i;
    p = afValue * (1.0f - afSaturation);
    q = afValue * (1.0f - afSaturation * f);
    t = afValue * (1.0f - afSaturation * (1.0f - f));
    switch (i)
    {
    case 0:
        *red = afValue;
        *apGreen = t;
        *apBlue = p;
        break;
    case 1:
        *red = q;
        *apGreen = afValue;
        *apBlue = p;
        break;
    case 2:
        *red = p;
        *apGreen = afValue;
        *apBlue = t;
        break;
    case 3:
        *red = p;
        *apGreen = q;
        *apBlue = afValue;
        break;
    case 4:
        *red = t;
        *apGreen = p;
        *apBlue = afValue;
        break;
    default:
        *red = afValue;
        *apGreen = p;
        *apBlue = q;
        break;
    }
}

void CallerHsv9(float* a, float h, float s, float v, float* r, float* g)
{
    HsvToRgb(a, h, s, v, g, r);
}

static inline float hkFloor(float x)
{
    return (float)floor((double)x);
}

static __declspec(noinline) void S00cabcd0_HSV(float* b, float h, float s, float v, float* g, float* r)
{
    float* const* pb = &b;
    volatile float* vp = b;
    (void)vp;
    (void)pb;
    int i;
    float f, p, q, t;
    if (s == 0.0f)
    {
        *r = *g = *b = v;
        return;
    }
    if (h == 1.0f)
    {
        i = 5;
        h = 6.0f;
    }
    else
    {
        h = h * 6.0;
        i = (int)hkFloor(h);
    }
    f = h - i;
    p = v * (1.0f - s);
    q = v * (1.0f - s * f);
    t = v * (1.0f - s * (1.0f - f));
    switch (i)
    {
    case 0:
        *r = v;
        *g = t;
        *b = p;
        break;
    case 1:
        *r = q;
        *g = v;
        *b = p;
        break;
    case 2:
        *r = p;
        *g = v;
        *b = t;
        break;
    case 3:
        *r = p;
        *g = q;
        *b = v;
        break;
    case 4:
        *r = t;
        *g = p;
        *b = v;
        break;
    default:
        *r = v;
        *g = p;
        *b = q;
        break;
    }
}

// Converts h, s, v to RGB with S00cabcd0_HSV and returns PackColorBigEndian called with the three results (c.b, c.g, c.r) and a.
// @fnv 0x00cabe30
// src: GUESS 0x00cabe30 (confidence: low)
unsigned int __cdecl Runtime_EvaluateValue_00cabe30(float h, float s, float v, float afAlpha)
{
    struct C
    {
        float r, g, b;
    } c;
    S00cabcd0_HSV(&c.b, h, s, v, &c.g, &c.r);
    return PackColorBigEndian(c.b, c.g, c.r, afAlpha);
}

extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" void _ReadWriteBarrier();
void __cdecl hkMemoryRouter_easyFree(void*, void*);
extern "C" void __cdecl CopyIfNonEmpty(void*, int, int);
extern int DAT_01268358;
// src: HAVOK_LIB 0x00cb0ad0
static __declspec(noinline) void* strNdup(char* s, int maxLen)
{
    int len = hkString_strLen((int)s);
    if (len > maxLen)
        len = maxLen;
    char* p = (char*)AllocateWithHeader(hkMemoryRouter_getInstance()->allocator, len + 1);
    CopyIfNonEmpty(p, (int)s, len);
    p[len] = 0;
    return p;
}
struct StringSlot
{
    unsigned int* volatile p;
};
// Frees the slot's old string if its low bit is set, then stores a tagged copy of s (length-limited unless len is -1), or DAT_01268358 when s is null.
// @fnv 0x00cb0b10
// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(StringSlot slotRef, char* apString, int aiLength)
{
    unsigned int* slot = slotRef.p;
    unsigned int cur = *slot;
    if ((char*)(cur & ~1u) == apString)
        return;
    if (cur & 1)
    {
        char* old = (char*)(cur - 1);
        FNVTaskMemoryRouter* r = hkMemoryRouter_getInstance();
        if (old)
            _ReadWriteBarrier();
        else
            _ReadWriteBarrier();
        hkMemoryRouter_easyFree(r->allocator, old);
    }
    if (apString)
    {
        if (aiLength == -1)
        {
            *slot = (unsigned int)strDup(apString) + 1;
            return;
        }
        *slot = (unsigned int)strNdup(apString, aiLength) + 1;
        return;
    }
    *slot = DAT_01268358;
}
void StringSetCaller(unsigned int* slot, char* s, int len)
{
    StringSlot r = {slot};
    assign_00cb0b10(r, s, len);
}

struct S_ca4520_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    unsigned short count;
    unsigned short unk46;
    unsigned short* runs;
    unsigned short* lists;
    unsigned short GetCount() const
    {
        return count;
    }
    unsigned short* GetLengths() const
    {
        return runs;
    }
    unsigned short GetVertices() const
    {
        return (unsigned short)unk08;
    }
    unsigned short* FUN_00a75f10();
};
struct S_ca4520_Slot
{
    NiPointer<S_ca4520_Entry> entry;
    int unk04;
};
struct S_ca4520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    S_ca4520_Slot* slots;
    S_ca4520_Slot& GetPart(unsigned int n) const
    {
        return slots[n];
    }
    S_ca4520_Entry* GetData(unsigned int n) const
    {
        return GetPart(n).entry;
    }
    bool IsDegenerate(unsigned int key) const;
};

union HandleKey
{
    unsigned int raw;
    struct
    {
        unsigned int index : 20;
        unsigned int slot : 12;
    };
};

// Looks up the entry for the key's slot, walks its runs to the key's index, and returns true if any two of the three consecutive values there are equal.
// @fnv 0x00ca4520
bool S_ca4520::IsDegenerate(unsigned int key) const
{
    bool result = false;
    HandleKey k;
    k.raw = key;
    S_ca4520_Entry* e = GetData(k.slot);
    unsigned short count = e->GetCount();
    unsigned short* p = e->FUN_00a75f10();
    unsigned short* runs = e->GetLengths();
    unsigned short i = 0;
    unsigned int idx = k.index;
    while (i < count)
    {
        if (idx < (unsigned int)(runs[i] - 2))
            break;
        idx += 2 - runs[i];
        p += runs[i];
        ++i;
    }
    unsigned short* q = p + idx;
    unsigned short a = *q;
    q++;
    unsigned short b = *q;
    q++;
    unsigned short c = *q;
    if (a == b || a == c || b == c)
        result = true;
    return result;
}

static volatile int g_helperSink;
// src: HAVOK_LIB 0x00cb0b10
__declspec(noinline) static int assign_00cb0b10(int a, int b, int c)
{
    g_helperSink = a + b + c;
    return g_helperSink;
}
// @fnv 0x00cb0c00
// src: GUESS 0x00cb0c00 (confidence: low)
void __fastcall Object_UpdateFields_00cb0c00(int p)
{
    int x = assign_00cb0b10(0, -1, p);
    (void)x;
}

struct SStringPtr
{
    void* UpdateState_00cb0c10(const char* s);
};
struct SelfRef
{
    void* p;
};
static int g_sink;
// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (int)s + len;
    *(int*)self.p = g_sink;
}
// @fnv 0x00cb0c10
// src: GUESS 0x00cb0c10 (confidence: low)
void* SStringPtr::UpdateState_00cb0c10(const char* s)
{
    SelfRef ref;
    ref.p = this;
    assign_00cb0b10(ref, s, -1);
    return this;
}

struct Cb0StringCopy
{
    int m_pcText;
    Cb0StringCopy* UpdateState_00cb0c30(const CB0StringPtr& other);
};
// @fnv 0x00cb0c30
// src: GUESS 0x00cb0c30 (confidence: low)
Cb0StringCopy* Cb0StringCopy::UpdateState_00cb0c30(const CB0StringPtr& other)
{
    CB0SelfRef self = {(CB0StringPtr*)this};
    assign_00cb0b10(self, other.cString(), -1);
    return this;
}

namespace fnv_00cb0c50 {
struct SStringPtr
{
    void hkStringPtr_set(const char* s, int len);
};
struct SelfRef
{
    void* p;
};
static int g_sink;
// src: HAVOK_LIB 0x00cb0b10
static __declspec(noinline) void assign_00cb0b10(SelfRef self, const char* s, int len)
{
    g_sink = (int)s + len;
    *(int*)self.p = g_sink;
}
// @fnv 0x00cb0c50
// src: HAVOK_LIB 0x00cb0c50
void SStringPtr::hkStringPtr_set(const char* apStr, int len)
{
    SelfRef ref;
    ref.p = this;
    assign_00cb0b10(ref, apStr, len);
}
}  // namespace fnv_00cb0c50

template <typename KEY> struct MapOps
{
    static __forceinline unsigned hash(KEY key, unsigned mod)
    {
        return unsigned((unsigned long)(key) >> 4) * 2654435761U & mod;
    }
    static __forceinline int isValid(KEY key)
    {
        return key != KEY(-1);
    }
    static __forceinline int equal(KEY key0, KEY key1)
    {
        return key0 == key1;
    }
};

struct ProbeMap64
{
    // hkMapBase<hkUint64,hkUint64>::Pair (Havok hkMap.h: 64-bit key, val; 16 bytes per entry)
    struct KeyValue
    {
        unsigned __int64 key;
        unsigned __int64 val;
    };
    typedef MapOps<unsigned __int64> OPS;

    KeyValue* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    int hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(unsigned __int64 key);
};

// Searches the probe map for the given key and returns its index, or m_iPairCount + 1 if not found.
// @fnv 0x00cb1c60
// src: HAVOK_LIB 0x00cb1c60
int ProbeMap64::hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_findKey(unsigned __int64 key)
{
    if (m_iPairCount > 0)
    {
        for (unsigned i = OPS::hash(key, m_iPairCount); OPS::isValid(m_kPrimitiveElement[i].key);
             i = (i + 1) & m_iPairCount)
        {
            if (OPS::equal(m_kPrimitiveElement[i].key, key))
            {
                return i;
            }
        }
    }
    return m_iPairCount + 1;
}

namespace fnv_00ca2140 {
extern int DAT_010c7310;
struct ChildLayout;
typedef void (__thiscall ChildLayout::*ReleaseFunction)(void*);
extern ReleaseFunction DAT_010c7318;
struct BaseState
{
    virtual ~BaseState()
    {}
};
struct ChildLayout
{
    void* m_vptr;
    void* m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    ~ChildLayout()
    {
        m_vptr = &DAT_010c7310;
        if (m_iWordAt04 != 0)
        {
            (this->*DAT_010c7318)(m_iWordAt04);
            m_iWordAt04 = 0;
            m_iThirdValue = 0;
            m_8 = 0;
        }
    }
};
struct FUN_00ca2140 : BaseState
{
    ChildLayout child;
    ~FUN_00ca2140();
};
// Destructor that only calls FUN_00ca20e0 on this.
// @fnv 0x00ca2140
FUN_00ca2140::~FUN_00ca2140()
{
    ((FUN_00ca20e0_Class*)this)->ClearAndFreeEntries();
}
}  // namespace fnv_00ca2140

extern int DAT_010c7600;
extern float DAT_010c72c0;
struct ExtraArray
{
    ~ExtraArray()
    {
        _NiFree_00aa10f0(m_pBase);
    }
    int unk00;
    S_00ca49a0_Elem* m_pBase;
    unsigned int unk08, m_uiESize, m_uiCount, growBy;
    ExtraArray(unsigned int n = 0, unsigned int g = 1)
    {
        unk08 = n;
        growBy = g;
        m_uiESize = 0;
        m_uiCount = 0;
        m_pBase = 0;
        unk00 = (int)&DAT_010c7600;
    }
    __declspec(noinline) void SetSize(unsigned int capacity)
    {
        if (capacity == unk08)
            return;
        if (capacity < m_uiESize)
        {
            for (unsigned int i = capacity; i < m_uiESize; ++i)
            {
                if (m_pBase[i] != S_00ca49a0_Elem(0))
                {
                    m_pBase[i] = S_00ca49a0_Elem(0);
                    --m_uiCount;
                }
            }
            m_uiESize = capacity;
        }
        S_00ca49a0_Elem* old = m_pBase;
        unk08 = capacity;
        if (capacity)
        {
            m_pBase = (S_00ca49a0_Elem*)Object_DispatchCommandFour(capacity * sizeof(S_00ca49a0_Elem));
            for (unsigned int i = 0; i < m_uiESize; ++i)
                m_pBase[i] = old[i];
            for (unsigned int i = m_uiESize; i < unk08; ++i)
                m_pBase[i] = S_00ca49a0_Elem(0);
        }
        else
            m_pBase = 0;
        _NiFree_00aa10f0(old);
    }
    void ClearRecords();
// src: XBOX_PDB 0x00ca49a0
    __declspec(noinline) void NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= m_uiESize)
        {
            m_uiESize = i + 1;
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else if (m_pBase[i] == S_00ca49a0_Elem(0))
        {
            if (e != S_00ca49a0_Elem(0))
                ++m_uiCount;
        }
        else
        {
            if (e == S_00ca49a0_Elem(0))
                --m_uiCount;
        }
        m_pBase[i] = e;
    }
    const S_00ca49a0_Elem& GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    unsigned int Add(const S_00ca49a0_Elem& e)
    {
        return SetAtGrow(m_uiESize, e);
    }
    unsigned int SetAtGrow(unsigned int i, const S_00ca49a0_Elem& e)
    {
        if (i >= unk08)
            SetSize(i + growBy);
        NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(i, e);
        return i;
    }
};
inline void CopyEntry(ExtraArray& out, int i, const ExtraArray& source)
{
    const S_00ca49a0_Elem& e = source.m_pBase[i];
    unsigned at = out.m_uiESize;
    if (at >= out.unk08)
    {
        unsigned n = at + out.growBy;
        out.SetSize(n);
    }
    out.NiTLargeArray_hkNiTriStripsData_NiTMallocInterface_hkNiTriStripsData_SetAt(at, e);
}
struct SavedExtraArray : ExtraArray
{
    SavedExtraArray() : ExtraArray()
    {}
};
struct SerializedExtraBody
{
    unsigned int unk00;
    float scale;
    ExtraArray entries;
    unsigned int value20, value24, value28, value2c;
    static void Swap4(void* p)
    {
        *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
    }
    void Swap()
    {
        Swap4(&scale);
        Swap4(&value20);
        Swap4(&value24);
        Swap4(&value28);
        Swap4(&value2c);
    }
};
struct ExtraSerializer
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void Restore(int token);
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual SerializedExtraBody* Acquire(int* token);
    void bhkShape_SaveBinary(S_00ca59d0_Stream* stream);
    void bhkNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* stream);
};
inline void SaveR(S_00ca59d0_Bin& bin, const unsigned int* p)
{
    unsigned int uiSize = 4;
    unsigned int written = bin.unk0C(&bin, p, 4, &uiSize, 1);
    bin.unk04 += written;
}
inline void SaveRV(S_00ca59d0_Bin& bin, unsigned int value)
{
    SaveR(bin, &value);
}
// Copies the acquired body's entries, writes each entry's link via stream->v12 and its unk04 value, byte-swapping the body when unk1E4 is not 1.
// @fnv 0x00ca77f0
// src: XBOX_PDB 0x00ca77f0
void ExtraSerializer::bhkNiTriStripsShape_SaveBinary(S_00ca59d0_Stream* stream)
{
    TlsGuard_t heap;
    int token;
    SerializedExtraBody* raw = Acquire(&token);
    SavedExtraArray entries;
    int count = 0;
    count = (int)raw->entries.m_uiESize;
    SerializedExtraBody* body = raw;
    for (int i = 0; i < count; ++i)
        CopyEntry(entries, i, body->entries);
    body->entries.ClearRecords();
    body->entries.SetSize(0);
    body->scale = DAT_010c72c0;
    if (*(unsigned char*)&stream->unk1E4 != 1)
        body->Swap();
    bhkShape_SaveBinary(stream);
    S_00ca59d0_Save(*stream->unk250, &count, 1);
    for (int i = 0; i < count; ++i)
    {
        int link = (int)entries.m_pBase[i].obj.m_p;
        stream->v12(link);
    }
    S_00ca59d0_Save(*stream->unk250, &count, 1);
    for (int i = 0; i < count; ++i)
    {
        SaveRV(*stream->unk250, entries.GetAt(i).unk04);
    }
    if (*(unsigned char*)&stream->unk1E4 != 1)
        body->Swap();
    Restore(token);
}

extern int DAT_0102009c;
extern int DAT_01268154;
extern int DAT_01268118;

struct cb86f0_obj
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;

    cb86f0_obj()
    {
        ((bhkRefObject*)this)->Initialize();
        vtable = (void*)0x102016c;
        const int inc = 1;
        unk0c = 0;
        DAT_01268154 += inc;
        vtable = (void*)&DAT_0102009c;
        DAT_01268118 += inc;
        vtable = (void*)0x10c8914;
    }

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

struct FUN_00cb86f0_class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(void* obj, int param);
    cb86f0_obj* bhkOrientHingedBodyAction_CreateClone(int a1);
};

// Allocates a cb86f0_obj, calls v50 on it with a1, and returns the new object.
// @fnv 0x00cb86f0
// src: XBOX_PDB 0x00cb86f0
cb86f0_obj* FUN_00cb86f0_class::bhkOrientHingedBodyAction_CreateClone(int a1)
{
    TlsGuard_t guard;
    bhkSerializable_CloneCritLock();
    cb86f0_obj* p = new cb86f0_obj();
    v50(p, a1);
    bhkSerializable_CloneCritUnlock();
    return p;
}

class RagdollRaycastCleanup
{
  public:
    void* m_vtbl;
    void SetVtbl();
};

// @fnv 0x00ca0c30
// src: GUESS 0x00ca0c30 (confidence: low)
void RagdollRaycastCleanup::SetVtbl()
{
    m_vtbl = &DAT_010c7304;
}

struct S_ca5870_Alloc
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct S_ca5870_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_ca5870_Alloc* m_10;
};

struct S_ca5870_Obj
{
    S_ca5870_Obj(void* arg);
    int unk00;
    unsigned short m_04;
    unsigned short unk06;
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    void FUN_00c905b0();

    static void* operator new(unsigned int size) throw()
    {
        S_ca5870_Holder* h = (S_ca5870_Holder*)hkMemoryRouter_getInstance();
        void* p = h->m_10->Alloc(size);
        ((S_ca5870_Obj*)p)->m_04 = (unsigned short)size;
        return p;
    }
};

struct S_ca5870
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5C();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6C();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7C();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void SlotA(S_ca5870_Obj* obj);
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9C();
    virtual void unkA0();
    virtual void unkA4();
    virtual void unkA8();
    virtual void unkAC();
    virtual void unkB0();
    virtual void unkB4();
    virtual void unkB8();
    virtual void SlotB(void* arg);
    void bhkPackedNiTriStripsShape_Init(void* arg);
};

// Constructs a S_ca5870_Obj from arg, passes it to SlotA, calls FUN_00c905b0 on it, then calls SlotB with arg.
// @fnv 0x00ca5870
// src: XBOX_PDB 0x00ca5870
void S_ca5870::bhkPackedNiTriStripsShape_Init(void* arg)
{
    TlsGuard_t guard;
    S_ca5870_Obj* obj = new S_ca5870_Obj(arg);
    this->SlotA(obj);
    obj->FUN_00c905b0();
    this->SlotB(arg);
}

extern "C" void __cdecl _ReadWriteBarrier(void);

struct FUN_00cb1130_class
{
    static char* hkString_strStr(const char* str, const char* substr);
};

template <class T>
static __forceinline void MatchIndexArray_AddBack(hkArrayBase<T>& self, const T& val);

template <class T>
static __forceinline void MatchIndexArray_AddBack(hkArrayBase<T>& self, const T& val)
{
        FNVTaskMemoryRouter* router = hkMemoryRouter_getInstance();
        if (self.m_iElementCount == (self.m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(router->allocator, (&self), sizeof(T));
        }
        T* slot = self.m_data + self.m_iElementCount;
        _ReadWriteBarrier();
        *slot = val;
        self.m_iElementCount++;
    }

// Appends the offset of the first match of substr in str to indices, or of every match when findAll is nonzero; returns whether any match was found.
// @fnv 0x00cb1440
// src: HAVOK_LIB 0x00cb1440
hkBool hkString_findAllOccurrences(const char* str, const char* substr, hkArrayBase<int>& indices, int findAll)
{
    int len = (int)strlen(substr);
    char* match = FUN_00cb1130_class::hkString_strStr(str, substr);
    hkBool result = false;
    while (match != 0)
    {
        result.m_cBooleanValue = true;
        MatchIndexArray_AddBack(indices, (int)(match - str));
        if (!findAll)
            break;
        match = FUN_00cb1130_class::hkString_strStr(match + len, substr);
    }
    return result;
}

struct S_Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float unk18;
    int unk1c;
    LocalM128 unk20;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    float unk58;
    int unk5c;
    int unk60;
};

struct S_D26450
{
    S_Source* hkpTriSampledHeightFieldCollection_getHeightFieldShape();
};

struct S_00cb0030_Obj : S_00ca4e10_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_D26450* unk18;
};

struct S_00cb0030_Out : S_00ca4e10_Out
{
    int unk08;
    int unk0c;
    LocalM128 unk10;
    int unk20;
    int unk24;
    float unk28;
    float unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
};

struct S_00cb0030_Cls : S_00ca4e10_Cls
{
    void bhkBvTreeShape_CopyCinfo(S_00cb0030_Out* out);
    void UpdateState_00cb0030(S_00cb0030_Out* out);
};

// Calls FUN_00ca4e10, then if obj->unk18 yields a source, fills out unk10, unk20, unk24, unk28, unk2c and unk40 from its fields.
// @fnv 0x00cb0030
// src: GUESS 0x00cb0030 (confidence: low)
void S_00cb0030_Cls::UpdateState_00cb0030(S_00cb0030_Out* out)
{
    bhkBvTreeShape_CopyCinfo(out);
    S_00cb0030_Obj* obj = static_cast<S_00cb0030_Obj*>(unk08);
    if (obj && obj->unk18)
    {
        S_Source* src = obj->unk18->hkpTriSampledHeightFieldCollection_getHeightFieldShape();
        if (src)
        {
            out->unk2c = src->unk58 + src->unk18;
            out->unk28 = src->unk18 - src->unk58;
            out->unk10 = src->unk20;
            out->unk20 = src->unk10;
            out->unk24 = src->unk14;
            out->unk40 = src->unk60;
        }
    }
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
