#include "../../include/hkArray.h"

// src/staging/blk_00de0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkReferencedObject.h"


#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/V4.h"
#include "../../include/Vec4.h"
#include "../../include/hkMatrix3.h"
#include "../../include/hkVector4.h"

struct Allocator
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int size);
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

__forceinline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}
__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
__forceinline hkMatrix3::hkMatrix3() {}
__forceinline void hkMatrix3::setIdentity()
{
    hkVector4 zero;
    zero.setZero4();
    const float one = 1.0f;
    m_kColumn0 = zero;
    m_kColumn1 = zero;
    m_kColumn2 = zero;
    m_kColumn0(0) = one;
    m_kColumn1(1) = one;
    m_kColumn2(2) = one;
}
__forceinline Vec4::Vec4(const Vec4& vector)
{
    xb = vector.xb;
    yb = vector.yb;
    zb = vector.zb;
    wb = vector.wb;
}

// If p is non-null and b is set, zeroes the fields at offsets 0x20, 0x22, 0x24, 0x28, 0x10 and sets the int at offset 0 to 1.
// @fnv 0x00df64d0
// src: HAVOK_LIB 0x00df64d0
void __cdecl finishLoadedObjecthkpCollidableBoundingVolumeData(void* p, int b)
{
    if (p && b)
    {
        *(unsigned short*)((char*)p + 0x20) = 0;
        *(unsigned short*)((char*)p + 0x22) = 0;
        *(int*)((char*)p + 0x24) = 0;
        *(int*)((char*)p + 0x28) = 0;
        *(int*)p = 1;
        *(int*)((char*)p + 0x10) = 0;
    }
}

struct FUN_00cb0c00_class
{
    void __thiscall Object_UpdateFields_00cb0c00();
};

// @fnv 0x00dfb490
// src: GUESS 0x00dfb490 (confidence: low)
void Object_ProcessState_00dfb490(FUN_00cb0c00_class* self)
{
    reinterpret_cast<FUN_00cb0c00_class*>(reinterpret_cast<char*>(self) + 4)->Object_UpdateFields_00cb0c00();
    self->Object_UpdateFields_00cb0c00();
}

// @fnv 0x00dfb9d0
// src: HAVOK_LIB 0x00dfb9d0
void cleanupLoadedObjecthkaSkeletonLocalFrameOnBone(hkReferencedObject** p)
{
    if (*p)
        (*p)->removeReference();
    *p = 0;
}

extern int DAT_010cc2fc;
extern int DAT_010df34c;

struct FUN_00dfbdf0_class
{
    void __thiscall ReturnSelf(int a);
};

// @fnv 0x00dfbdf0
// src: GUESS 0x00dfbdf0 (confidence: low)
void Runtime_UpdateState_00dfbdf0(void* p, int a)
{
    if (p)
    {
        *(int*)p = (int)&DAT_010cc2fc;
        ((FUN_00dfbdf0_class*)((char*)p + 0x14))->ReturnSelf(a);
        *(int*)p = (int)&DAT_010df34c;
    }
}

extern void* DAT_010d77d8;

struct FUN_00d21de0_Class
{
    void __thiscall hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(void*);
};

// @fnv 0x00dfc3e0
// src: HAVOK_LIB 0x00dfc3e0
void __cdecl finishLoadedObjecthkpSerializedAgentNnEntry(void** ppObject, void* a2)
{
    if (ppObject)
    {
        *ppObject = &DAT_010d77d8;
        ((FUN_00d21de0_Class*)(ppObject + 8))->hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(a2);
    }
}

extern "C" void* DAT_010305a8;
extern "C" void* DAT_010e222c;

// @fnv 0x00dfd0f0
// src: GUESS 0x00dfd0f0 (confidence: low)
void Object_UpdateState_00dfd0f0(void* pObject, int b)
{
    if (pObject)
    {
        *reinterpret_cast<void**>(pObject) = &DAT_010305a8;
        if (b)
            *reinterpret_cast<int*>(reinterpret_cast<char*>(pObject) + 0xc) = 0;
        *reinterpret_cast<void**>(pObject) = &DAT_010e222c;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pObject) + 0xc) = 0x18;
    }
}

struct FUN_00cb0a70_class
{
    void __thiscall ReturnSelf(int);
};

// @fnv 0x00dfd770
// src: GUESS 0x00dfd770 (confidence: low)
void __cdecl Object_ProcessState_00dfd770(void* pObject, void* arg2)
{
    if (pObject)
        ((FUN_00cb0a70_class*)((char*)pObject + 4))->ReturnSelf((int)arg2);
}

namespace fnv_00dfd970 {

// @fnv 0x00dfd970
// src: HAVOK_LIB 0x00dfd970
void __cdecl cleanupLoadedObjecthkaSkeletonLocalFrameOnBone_00dfd970(hkReferencedObject** p)
{
    if (*p)
        (*p)->removeReference();
    *p = 0;
}
}  // namespace fnv_00dfd970

struct FUN_00cb0a70_cls
{
    void __thiscall ReturnSelf(char*);
};

// If b is non-null, calls FUN_00cb0a70 on b and on b+4 with a as the argument.
// @fnv 0x00dfda10
// src: GUESS 0x00dfda10 (confidence: low)
void Object_UpdateState_00dfda10(char* pObject, char* a)
{
    if (pObject)
    {
        char* c = a;
        ((FUN_00cb0a70_cls*)pObject)->ReturnSelf(c);
        ((FUN_00cb0a70_cls*)(pObject + 4))->ReturnSelf(c);
    }
}

extern int DAT_010d3cc0;

// @fnv 0x00dfde30
// src: GUESS 0x00dfde30 (confidence: low)
void Object_UpdateState_00dfde30(void* apObject)
{
    if (apObject)
    {
        *(unsigned short*)((char*)apObject + 6) = 1;
        *(int**)(char*)apObject = &DAT_010d3cc0;
    }
}

extern int DAT_010cc2fc;
extern int DAT_010d08f4;

struct FUN_00cb0a70_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    void __thiscall ReturnSelf(int a);
};

// @fnv 0x00dfef50
// src: GUESS 0x00dfef50 (confidence: low)
void Object_UpdateState_00dfef50(int* pObject, int aiValue)
{
    if (pObject)
    {
        pObject[0] = (int)&DAT_010cc2fc;
        ((FUN_00cb0a70_Class*)((char*)pObject + 0x14))->ReturnSelf(aiValue);
        pObject[0] = (int)&DAT_010d08f4;
    }
}

extern int DAT_010cc2fc;
extern int DAT_010e6834;

struct FUN_00dff0f0_class
{
    int m;
    void ReturnSelf(int);
};

// If p is non-null, sets p->m to &DAT_010cc2fc, calls FUN_00cb0a70 on the object at p+0x14 with a, then sets p->m to &DAT_010e6834.
// @fnv 0x00dff0f0
// src: GUESS 0x00dff0f0 (confidence: low)
void Runtime_UpdateState_00dff0f0(FUN_00dff0f0_class* p, int aiValue)
{
    if (p)
    {
        p->m = (int)&DAT_010cc2fc;
        ((FUN_00dff0f0_class*)((char*)p + 0x14))->ReturnSelf(aiValue);
        p->m = (int)&DAT_010e6834;
    }
}

extern int DAT_010cce28;
extern int DAT_010d07f4;
struct FUN_00cb0a70
{
    void __thiscall m_00cb0a70(int);
};

// @fnv 0x00dff1f0
// src: HAVOK_LIB 0x00dff1f0
void __cdecl finishLoadedObjecthkpPhysicsSystemWithContacts(int* pObject, int iValue)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010cce28;
        ((FUN_00cb0a70*)(pObject + 14))->m_00cb0a70(iValue);
        *pObject = (int)&DAT_010d07f4;
    }
}

struct FUN_00dff340_Class
{
    void* m_p;
    void ReturnSelf(void* arg);
};

extern int DAT_010cc2fc;
extern int DAT_010d0944;

// @fnv 0x00dff340
// src: GUESS 0x00dff340 (confidence: low)
void __cdecl Object_UpdateFields_00dff340(void* apObject, void* arg)
{
    if (apObject)
    {
        ((FUN_00dff340_Class*)apObject)->m_p = &DAT_010cc2fc;
        ((FUN_00dff340_Class*)((char*)apObject + 0x14))->ReturnSelf(arg);
        ((FUN_00dff340_Class*)apObject)->m_p = &DAT_010d0944;
    }
}

namespace fnv_00dffbe0 {
struct FUN_00cb0a70_class
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    int m_g;
    int m_h;
    int m_i;
    int m_iUnknownValue;
    int m_k;
    int m_l;
    int m_iUnknownValue2;
    int m_uiValueCount;
    int m_o;
    int m_p;
    int m_q;
    int m_r;
    int m_s;
    int m_t;
    int m_u;
    int m_v;
    int m_w;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    void ReturnSelf(int a);
};

extern int DAT_010cc2fc;
extern int DAT_010d09f4;

// @fnv 0x00dffbe0
// src: GUESS 0x00dffbe0 (confidence: low)
void __cdecl Object_UpdateFields_00dffbe0(int* pObject, int aiValue)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010cc2fc;
        ((FUN_00cb0a70_class*)(pObject + 5))->ReturnSelf(aiValue);
        *pObject = (int)&DAT_010d09f4;
    }
}
}  // namespace fnv_00dffbe0

// Copies twelve int fields at fixed offsets from the source object to the destination object.
// @fnv 0x00df7d00
void CopyFields(void* pSource, void* pDest)
{
    char* s = (char*)pSource;
    char* d = (char*)pDest;
    *(int*)(d + 0x14) = *(int*)(s + 0x14);
    *(int*)(d + 0x1c) = *(int*)(s + 0x1c);
    *(int*)(d + 0x10) = *(int*)(s + 0x10);
    *(int*)(d + 0x20) = *(int*)(s + 0x20);
    *(int*)(d + 0x24) = *(int*)(s + 0x24);
    *(int*)(d + 0x38) = *(int*)(s + 0x38);
    *(int*)(d + 0x28) = *(int*)(s + 0x28);
    *(int*)(d + 0x2c) = *(int*)(s + 0x2c);
    *(int*)(d + 0x30) = *(int*)(s + 0x30);
    *(int*)(d + 0x3c) = *(int*)(s + 0x3c);
    *(int*)(d + 0x34) = *(int*)(s + 0x34);
    *(int*)(d + 0x40) = *(int*)(s + 0x40);
}

// @fnv 0x00dfbc70
// src: GUESS 0x00dfbc70 (confidence: low)
void Object_ForwardCall_00dfbc70(FUN_00cb0c00_class* self)
{
    ((FUN_00cb0c00_class*)((char*)self + 4))->Object_UpdateFields_00cb0c00();
}

extern int DAT_010df89c;
// @fnv 0x00dfbf50
// src: GUESS 0x00dfbf50 (confidence: low)
void __cdecl Runtime_UpdateState_00dfbf50(int* p)
{
    if (p)
        *p = (int)&DAT_010df89c;
}

extern int DAT_010df9f4;

// @fnv 0x00dfc060
// src: GUESS 0x00dfc060 (confidence: low)
void Object_UpdateFields_00dfc060(int* p)
{
    if (p)
        *p = (int)&DAT_010df9f4;
}

extern int DAT_010dff44;
// @fnv 0x00dfc130
// src: GUESS 0x00dfc130 (confidence: low)
void __cdecl Runtime_UpdateState_00dfc130(int* p)
{
    if (p)
        *p = (int)&DAT_010dff44;
}

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dfc230
// src: GUESS 0x00dfc230 (confidence: low)
void __cdecl Runtime_Helper_00dfc230(void** p)
{
    ((VTable0*)(*(void***)(p)))[0](p, 0);
}

// @fnv 0x00dfc250
// src: GUESS 0x00dfc250 (confidence: low)
void __cdecl Runtime_UpdateState_00dfc250(void** p)
{
    void(__thiscall * fn)(void*, int) = *(void(__thiscall**)(void*, int)) * p;
    fn(p, 0);
}

extern int DAT_010e00cc;
// @fnv 0x00dfc280
// src: GUESS 0x00dfc280 (confidence: low)
void __cdecl Object_UpdateFields_00dfc280(int* p)
{
    if (p)
        *p = (int)&DAT_010e00cc;
}

extern int DAT_010e00dc;
// @fnv 0x00dfc2a0
// src: GUESS 0x00dfc2a0 (confidence: low)
void Object_UpdateFields_00dfc2a0(int* p)
{
    if (p)
        *p = (int)&DAT_010e00dc;
}

// @fnv 0x00dfc380
// src: GUESS 0x00dfc380 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfc380(void** p)
{
    (**(void(__thiscall**)(void*, int))(*p))(p, 0);
}

extern int DAT_010e04ac;
// @fnv 0x00dfc470
// src: GUESS 0x00dfc470 (confidence: low)
void __cdecl Runtime_UpdateState_00dfc470(int* p)
{
    if (p)
        *p = (int)&DAT_010e04ac;
}

// @fnv 0x00dfc500
// src: GUESS 0x00dfc500 (confidence: low)
void __cdecl Object_ProcessAndTransformResult_00dfc500(void* p)
{
    ((void(__thiscall*)(void*, int)) * (void**)*(void**)p)(p, 0);
}

extern int DAT_010e0654;
// @fnv 0x00dfc520
// src: GUESS 0x00dfc520 (confidence: low)
void __cdecl Object_UpdateFields_00dfc520(int* a)
{
    if (a)
        *a = (int)&DAT_010e0654;
}

extern int DAT_0102e368;

// @fnv 0x00dfc620
// src: GUESS 0x00dfc620 (confidence: low)
void __cdecl Object_UpdateFields_00dfc620(int* p)
{
    if (p)
        *p = (int)&DAT_0102e368;
}

extern int DAT_010d0a64;
// @fnv 0x00dfc6c0
// src: GUESS 0x00dfc6c0 (confidence: low)
void __cdecl Object_UpdateFields_00dfc6c0(int* p)
{
    if (p)
        *p = (int)&DAT_010d0a64;
}

// @fnv 0x00dfc700
// src: GUESS 0x00dfc700 (confidence: low)
void __cdecl Object_ProcessAndTransformResult_00dfc700(void* p)
{
    ((void(__thiscall*)(void*, int))(*(void**)*(void**)p))(p, 0);
}

extern int DAT_010d0aac;
// @fnv 0x00dfc730
// src: GUESS 0x00dfc730 (confidence: low)
void Runtime_UpdateState_00dfc730(int* p)
{
    if (p)
        *p = (int)&DAT_010d0aac;
}

extern int DAT_010e11ec;
// @fnv 0x00dfc900
// src: GUESS 0x00dfc900 (confidence: low)
void __cdecl Object_UpdateFields_00dfc900(int* p)
{
    if (p)
        *p = (int)&DAT_010e11ec;
}

extern int DAT_010da04c;
// @fnv 0x00dfca90
// src: GUESS 0x00dfca90 (confidence: low)
void __cdecl Runtime_UpdateState_00dfca90(int* p)
{
    if (p)
        *p = (int)&DAT_010da04c;
}

// @fnv 0x00dfcad0
// src: GUESS 0x00dfcad0 (confidence: low)
void __cdecl Runtime_Helper_00dfcad0(void** p)
{
    ((void(__thiscall*)(void*, int))(**(void***)(p)))(p, 0);
}

extern int DAT_010d0b3c;
// @fnv 0x00dfcb00
// src: GUESS 0x00dfcb00 (confidence: low)
void Object_UpdateFields_00dfcb00(int* p)
{
    if (p)
        *p = (int)&DAT_010d0b3c;
}

extern void* DAT_010d37e4;
// @fnv 0x00dfcbf0
// src: GUESS 0x00dfcbf0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfcbf0(void** p)
{
    if (p)
        *p = &DAT_010d37e4;
}

extern int DAT_010c89e4;
// @fnv 0x00dfcc60
// src: GUESS 0x00dfcc60 (confidence: low)
void __cdecl Object_UpdateFields_00dfcc60(int* p)
{
    if (p)
        *p = (int)&DAT_010c89e4;
}

extern int DAT_010d0be4;
// @fnv 0x00dfccd0
// src: GUESS 0x00dfccd0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfccd0(int* p)
{
    if (p)
        *p = (int)&DAT_010d0be4;
}

typedef int(__thiscall* VFunc0)(void*, int);
// @fnv 0x00dfcd10
// src: GUESS 0x00dfcd10 (confidence: low)
int __cdecl Object_EvaluateValue_00dfcd10(void* self)
{
    return ((VFunc0*)*(void**)self)[0](self, 0);
}

extern int DAT_010c91ec;
// @fnv 0x00dfcd40
// src: GUESS 0x00dfcd40 (confidence: low)
void __cdecl Object_UpdateFields_00dfcd40(int* p)
{
    if (p)
        *p = (int)&DAT_010c91ec;
}

extern int DAT_010d0cd4;

// @fnv 0x00dfce90
// src: GUESS 0x00dfce90 (confidence: low)
void __cdecl Runtime_UpdateState_00dfce90(int* a)
{
    if (a)
        *a = (int)&DAT_010d0cd4;
}

struct FUN_00dfd7a0_vt
{
    virtual void v0(int);
    virtual void v1(int);
};
// @fnv 0x00dfd7a0
// src: GUESS 0x00dfd7a0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfd7a0(FUN_00dfd7a0_vt* p)
{
    p->v0(0);
}

// @fnv 0x00dfd7c0
// src: GUESS 0x00dfd7c0 (confidence: low)
void __cdecl Object_ForwardCall_00dfd7c0(void* arg)
{
    ((FUN_00cb0c00_class*)((char*)arg + 4))->Object_UpdateFields_00cb0c00();
}

struct FUN_00dfd940_vt
{
    virtual void __thiscall Object_ForwardCall_00dfd940(int);
};
// @fnv 0x00dfd940
// src: GUESS 0x00dfd940 (confidence: low)
void __cdecl Object_ForwardCall_00dfd940(FUN_00dfd940_vt* p)
{
    p->Object_ForwardCall_00dfd940(0);
}

// @fnv 0x00dfdb40
// src: GUESS 0x00dfdb40 (confidence: low)
void __cdecl Object_ForwardCall_00dfdb40(void* p)
{
    ((FUN_00cb0c00_class*)((char*)p + 4))->Object_UpdateFields_00cb0c00();
}

extern int DAT_010e351c;
// @fnv 0x00dfdb50
// src: GUESS 0x00dfdb50 (confidence: low)
void __cdecl Runtime_UpdateState_00dfdb50(int* p)
{
    if (p)
        *p = (int)&DAT_010e351c;
}

extern "C" void* DAT_010e352c;
// @fnv 0x00dfdb70
// src: GUESS 0x00dfdb70 (confidence: low)
void __cdecl Runtime_UpdateState_00dfdb70(void** p)
{
    if (p)
        *p = &DAT_010e352c;
}

// @fnv 0x00dfdf90
// src: GUESS 0x00dfdf90 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfdf90(int a, int b)
{
    ((FUN_00cb0c00_class*)(a + 8))->Object_UpdateFields_00cb0c00();
}

extern int DAT_010e3e5c;

// @fnv 0x00dfdfb0
// src: GUESS 0x00dfdfb0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfdfb0(int* p)
{
    if (p)
        *p = (int)&DAT_010e3e5c;
}

extern int DAT_010e5474;
// @fnv 0x00dfe340
// src: GUESS 0x00dfe340 (confidence: low)
void __cdecl Object_UpdateFields_00dfe340(void* p)
{
    if (p)
        *reinterpret_cast<int*>(p) = reinterpret_cast<int>(&DAT_010e5474);
}

struct FUN_00dfe430_class
{
    virtual int __thiscall ReturnSelf(int a);
};
// @fnv 0x00dfe430
// src: GUESS 0x00dfe430 (confidence: low)
int __cdecl Runtime_ForwardCall_00dfe430(FUN_00dfe430_class* p)
{
    return p->ReturnSelf(0);
}

extern int DAT_010e56d4;
// @fnv 0x00dfe490
// src: GUESS 0x00dfe490 (confidence: low)
void __cdecl Runtime_UpdateState_00dfe490(int* p)
{
    if (p)
        *p = (int)&DAT_010e56d4;
}

extern int DAT_010e57a4;
// @fnv 0x00dfe500
// src: GUESS 0x00dfe500 (confidence: low)
void __cdecl Object_UpdateFields_00dfe500(int* p)
{
    if (p)
        *p = (int)&DAT_010e57a4;
}

struct FUN_00dfe670_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dfe670
// src: GUESS 0x00dfe670 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfe670(FUN_00dfe670_vt* p)
{
    p->m_iWordAt00(0);
}

extern int DAT_010e58c8;

// @fnv 0x00dfe690
// src: GUESS 0x00dfe690 (confidence: low)
void __cdecl Runtime_UpdateState_00dfe690(int** p)
{
    if (p)
        *p = &DAT_010e58c8;
}

extern int DAT_010e59ac;
// @fnv 0x00dfe700
// src: GUESS 0x00dfe700 (confidence: low)
void Object_UpdateFields_00dfe700(int* p)
{
    if (p)
        *p = (int)&DAT_010e59ac;
}

// @fnv 0x00dfeaa0
// src: GUESS 0x00dfeaa0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfeaa0(void** p)
{
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(p))[0])(p, 0);
}

extern int DAT_010e5b68;

// @fnv 0x00dfeb60
// src: GUESS 0x00dfeb60 (confidence: low)
void __cdecl Object_UpdateFields_00dfeb60(int* p)
{
    if (p)
        *p = (int)&DAT_010e5b68;
}

extern int DAT_010e5b4c;

// @fnv 0x00dfebd0
// src: GUESS 0x00dfebd0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfebd0(int* p)
{
    if (p)
        *p = (int)&DAT_010e5b4c;
}

extern int DAT_010e5bfc;
// @fnv 0x00dfec10
// src: GUESS 0x00dfec10 (confidence: low)
void __cdecl Runtime_UpdateState_00dfec10(int* p)
{
    if (p)
        *p = (int)&DAT_010e5bfc;
}

extern int DAT_010e5d94;

// @fnv 0x00dfec70
// src: GUESS 0x00dfec70 (confidence: low)
void __cdecl Runtime_UpdateState_00dfec70(int* p)
{
    if (p)
        *p = (int)&DAT_010e5d94;
}

extern int DAT_010e5da8;
// @fnv 0x00dfec90
// src: GUESS 0x00dfec90 (confidence: low)
void __cdecl Runtime_UpdateState_00dfec90(int** p)
{
    if (p)
        *p = &DAT_010e5da8;
}

// @fnv 0x00dfecb0
// src: GUESS 0x00dfecb0 (confidence: low)
void __cdecl Runtime_Helper_00dfecb0(int* p)
{
    ((void(__thiscall*)(void*, int))(*(int*)p[0]))(p, 0);
}

extern int DAT_010e5e9c;

// @fnv 0x00dfecd0
// src: GUESS 0x00dfecd0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfecd0(int* p)
{
    if (p)
        *p = (int)&DAT_010e5e9c;
}

extern int DAT_010e5ff4;
// @fnv 0x00dfed10
// src: GUESS 0x00dfed10 (confidence: low)
void Runtime_UpdateState_00dfed10(int* p)
{
    if (p)
        *p = (int)&DAT_010e5ff4;
}

extern int DAT_010e60c4;

// @fnv 0x00dfee00
// src: GUESS 0x00dfee00 (confidence: low)
void __cdecl Object_UpdateFields_00dfee00(int* p)
{
    if (p)
        *p = (int)&DAT_010e60c4;
}

extern int DAT_010e62a4;
// @fnv 0x00dfeea0
// src: GUESS 0x00dfeea0 (confidence: low)
void __cdecl Object_UpdateFields_00dfeea0(int* p)
{
    if (p)
        *p = (int)&DAT_010e62a4;
}

extern int DAT_010e6394;

// @fnv 0x00dfeee0
// src: GUESS 0x00dfeee0 (confidence: low)
void __cdecl Object_UpdateFields_00dfeee0(int* p)
{
    if (p)
        *p = (int)&DAT_010e6394;
}

extern int DAT_010e66fc;
// @fnv 0x00dfeff0
// src: GUESS 0x00dfeff0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfeff0(int* p)
{
    if (p)
        *p = (int)&DAT_010e66fc;
}

extern int DAT_010e676c;
// @fnv 0x00dff0d0
// src: GUESS 0x00dff0d0 (confidence: low)
void __cdecl Runtime_UpdateState_00dff0d0(int* p)
{
    if (p)
        *p = (int)&DAT_010e676c;
}

extern int DAT_010cc2fc;
extern int DAT_010c8e94;
struct FUN_00cb0a70_m_helper
{
    void __thiscall m(int);
};
// @fnv 0x00dff270
// src: HAVOK_LIB 0x00dff270
void __cdecl finishLoadedObjecthkpMouseSpringAction(void* pObject, void* b)
{
    if (pObject)
    {
        *(int*)pObject = (int)&DAT_010cc2fc;
        ((FUN_00cb0a70_m_helper*)((char*)pObject + 0x14))->m((int)b);
        *(int*)pObject = (int)&DAT_010c8e94;
        *(int*)((char*)pObject + 0x54) = 0;
        *(int*)((char*)pObject + 0x58) = 0;
        *(int*)((char*)pObject + 0x5c) = 0x80000000;
    }
}

typedef void(__thiscall* VTableFn)(void*, int);
// @fnv 0x00dff3c0
// src: GUESS 0x00dff3c0 (confidence: low)
void __cdecl Object_ProcessState_00dff3c0(void* p)
{
    ((VTableFn*)*(void**)p)[0](p, 0);
}

extern int DAT_010e75cc;
// @fnv 0x00dff5e0
// src: GUESS 0x00dff5e0 (confidence: low)
void Object_UpdateFields_00dff5e0(int* p)
{
    if (p)
        *p = (int)&DAT_010e75cc;
}

extern int DAT_010e75dc;
// @fnv 0x00dff600
// src: GUESS 0x00dff600 (confidence: low)
void __cdecl Object_UpdateFields_00dff600(int* p)
{
    if (p)
        *p = (int)&DAT_010e75dc;
}

extern int DAT_010e75ec;
// @fnv 0x00dff620
// src: GUESS 0x00dff620 (confidence: low)
void __cdecl Object_UpdateFields_00dff620(int** p)
{
    if (p)
        *p = &DAT_010e75ec;
}

// @fnv 0x00dff9e0
// src: GUESS 0x00dff9e0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dff9e0(void** p)
{
    (**(void(__thiscall**)(void*, int))(*p))(p, 0);
}

typedef int(__thiscall* Vfn)(void*, int);
// @fnv 0x00dffa30
// src: GUESS 0x00dffa30 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dffa30(void* obj)
{
    return reinterpret_cast<Vfn>(**reinterpret_cast<void***>(obj))(obj, 0);
}

extern int DAT_010e7c24;
// @fnv 0x00dffc80
// src: GUESS 0x00dffc80 (confidence: low)
void __cdecl Object_UpdateFields_00dffc80(int* p)
{
    if (p)
        *p = (int)&DAT_010e7c24;
}

extern int DAT_010cc0d8;
// @fnv 0x00dffda0
// src: GUESS 0x00dffda0 (confidence: low)
void __cdecl Object_UpdateFields_00dffda0(int* p)
{
    if (p)
        *p = (int)&DAT_010cc0d8;
}

struct FUN_00dffdc0_vt
{
    virtual void m0(int);
};
// @fnv 0x00dffdc0
// src: GUESS 0x00dffdc0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dffdc0(FUN_00dffdc0_vt* p)
{
    p->m0(0);
}

extern int DAT_010d3838;
// @fnv 0x00dffe40
// src: GUESS 0x00dffe40 (confidence: low)
void __cdecl Object_UpdateFields_00dffe40(int* p)
{
    if (p)
        *p = (int)&DAT_010d3838;
}

extern int DAT_010cb798;

// @fnv 0x00dffee0
// src: GUESS 0x00dffee0 (confidence: low)
void Object_UpdateFields_00dffee0(int* p)
{
    if (p)
        *p = (int)&DAT_010cb798;
}

struct FUN_00dfff60_vt
{
    virtual int __thiscall v0(int);
};
// @fnv 0x00dfff60
// src: GUESS 0x00dfff60 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00dfff60(FUN_00dfff60_vt* p)
{
    return p->v0(0);
}

struct FUN_00dfffc0_VT
{
    virtual void m0(int);
};
// @fnv 0x00dfffc0
// src: GUESS 0x00dfffc0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfffc0(FUN_00dfffc0_VT* p)
{
    p->m0(0);
}

extern void* DAT_010e80b4;
// @fnv 0x00dfffe0
// src: GUESS 0x00dfffe0 (confidence: low)
void __cdecl Object_UpdateFields_00dfffe0(void** p)
{
    if (p)
        *p = &DAT_010e80b4;
}

struct FUN_00de87c0_class
{
    float m_iWordAt00;
    float m_iWordAt04;
    float m_8;
    float m_iThirdValue;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    float m_30;
    float m_34;
    float m_38;
    void SwapFields();
};

// Swaps several pairs of float fields on this object using a temporary variable.
// @fnv 0x00de87c0
void FUN_00de87c0_class::SwapFields()
{
    float t;
    t = m_10;
    m_10 = m_iWordAt04;
    m_iWordAt04 = t;
    t = m_20;
    m_20 = m_8;
    m_8 = t;
    t = m_30;
    m_30 = m_iThirdValue;
    m_iThirdValue = t;
    t = m_24;
    m_24 = m_18;
    m_18 = t;
    t = m_34;
    m_34 = m_1c;
    m_1c = t;
    t = m_38;
    m_38 = m_2c;
    m_2c = t;
}

// @fnv 0x00de81a0
// src: GUESS 0x00de81a0 (confidence: low)
void __cdecl Object_ProcessState_00de81a0(void* pObject, void* arg)
{
    if (pObject)
        ((FUN_00d21de0_Class*)pObject)->hkpSimpleContactConstraintAtom_hkpSimpleContactConstraintAtom(arg);
}

struct FUN_00d21ce0_cls
{
    void __thiscall hkpBridgeConstraintAtom_init(void*);
};
struct FUN_00de8550_t
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
};
// @fnv 0x00de8550
// src: GUESS 0x00de8550 (confidence: low)
void __cdecl hkpBridgeConstraintAtom_init_ProcessState_00de8550(FUN_00de8550_t* pObject, int iValue)
{
    if (pObject && iValue)
        ((FUN_00d21ce0_cls*)pObject)->hkpBridgeConstraintAtom_init(pObject->m_8);
}

struct FUN_00de8830_Class
{
    void CopyTransposedMatrix(float* src);
};

// Copies 16 floats from src into this, keeping the diagonal and swapping the off-diagonal pairs to transpose the 4x4 matrix.
// @fnv 0x00de8830
void FUN_00de8830_Class::CopyTransposedMatrix(float* afMatrix)
{
    float* dst = (float*)this;
    dst[0] = afMatrix[0];
    dst[5] = afMatrix[5];
    dst[10] = afMatrix[10];
    dst[15] = afMatrix[15];
    dst[1] = afMatrix[4];
    dst[4] = afMatrix[1];
    dst[2] = afMatrix[8];
    dst[8] = afMatrix[2];
    dst[3] = afMatrix[12];
    dst[12] = afMatrix[3];
    dst[6] = afMatrix[9];
    dst[9] = afMatrix[6];
    dst[7] = afMatrix[13];
    dst[13] = afMatrix[7];
    dst[11] = afMatrix[14];
    dst[14] = afMatrix[11];
}

// @fnv 0x00df3250
// src: HAVOK_LIB 0x00df3250
int __cdecl _nlz(int arg)
{
    unsigned int edx = (unsigned int)arg;
    int eax;

    unsigned int t = (unsigned short)edx;
    eax = ((int)(t - 0x100)) >> 16;
    eax &= 8;
    edx <<= eax;

    t = (unsigned short)edx;
    int ecx = ((int)(t - 0x1000)) >> 16;
    ecx &= 4;
    edx <<= ecx;
    eax += ecx;

    t = (unsigned short)edx;
    ecx = ((int)(t - 0x4000)) >> 16;
    ecx &= 2;
    edx <<= ecx;
    eax += ecx;

    t = (unsigned short)edx;
    ecx = t >> 14;
    int edx2 = ecx;
    edx2 >>= 1;
    edx2 = ~edx2;
    edx2 &= ecx;
    eax -= edx2;

    return eax + 2;
}

typedef void(__thiscall* Vfn0)(void*, int);
// @fnv 0x00df6460
// src: GUESS 0x00df6460 (confidence: low)
void __cdecl Object_ProcessState_00df6460(void** p)
{
    ((Vfn0) * (void**)*p)(p, 0);
}

typedef int(__thiscall* VFunc_00dfb270)(void*, int);
// @fnv 0x00dfb270
// src: GUESS 0x00dfb270 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfb270(void* p)
{
    return ((VFunc_00dfb270*)*(void**)p)[0](p, 0);
}

// If a is non-null, calls m(v) on a and on the helper at a+4.
// @fnv 0x00dfb390
void __cdecl CallMethodOnBothHelpers(FUN_00cb0a70_m_helper* pHelper, int iValue)
{
    if (pHelper)
    {
        pHelper->m(iValue);
        ((FUN_00cb0a70_m_helper*)((char*)pHelper + 4))->m(iValue);
    }
}

typedef void(__thiscall* VFunc00dfb3f0)(void*, int);
// @fnv 0x00dfb3f0
// src: GUESS 0x00dfb3f0 (confidence: low)
void __cdecl Runtime_Helper_00dfb3f0(void** p)
{
    ((VFunc00dfb3f0) * ((void***)p)[0])(p, 0);
}

struct FUN_00dfb450_vt
{
    virtual void m0(int);
};
// @fnv 0x00dfb450
// src: GUESS 0x00dfb450 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfb450(FUN_00dfb450_vt* p)
{
    p->m0(0);
}

struct FUN_00dfb890_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfb890
// src: GUESS 0x00dfb890 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfb890(FUN_00dfb890_vt* p)
{
    p->v0(0);
}

extern int DAT_010c4dec;

// @fnv 0x00dfb9f0
// src: GUESS 0x00dfb9f0 (confidence: low)
void Runtime_UpdateState_00dfb9f0(int* pTarget, int iValue)
{
    if (pTarget)
    {
        *pTarget = (int)&DAT_010c4dec;
        ((FUN_00cb0a70_m_helper*)(pTarget + 2))->m(iValue);
    }
}

typedef void(__thiscall* VTable0_00dfba70)(void*, int);
// @fnv 0x00dfba70
// src: GUESS 0x00dfba70 (confidence: low)
void __cdecl Runtime_Helper_00dfba70(void* p)
{
    ((VTable0_00dfba70**)(void**)p)[0][0](p, 0);
}

typedef void(__thiscall* VFn0)(void*, int);
// @fnv 0x00dfbb30
// src: GUESS 0x00dfbb30 (confidence: low)
void __cdecl Runtime_UpdateState_00dfbb30(void* p)
{
    VFn0 f = (VFn0) * (void**)*(void**)p;
    f(p, 0);
}

// @fnv 0x00dfbbf0
// src: GUESS 0x00dfbbf0 (confidence: low)
void __cdecl Object_ProcessState_00dfbbf0(void* pObject, int a)
{
    if (pObject)
        ((FUN_00cb0a70_m_helper*)pObject)->m(a);
}

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
// @fnv 0x00dfbc20
// src: GUESS 0x00dfbc20 (confidence: medium)
void __cdecl Object_DestroyFields(S_00d49310_Lock* self)
{
    self->S_00d49310_Lock::~S_00d49310_Lock();
}

// @fnv 0x00dfbc30
// src: GUESS 0x00dfbc30 (confidence: low)
void __cdecl Runtime_ProcessState_00dfbc30(void* pTarget, void* b)
{
    if (pTarget)
        ((FUN_00cb0a70_m_helper*)((char*)pTarget + 4))->m((int)b);
}

// @fnv 0x00dfbc80
void __cdecl DispatchToHelper(void* pHelper, int iValue)
{
    if (pHelper)
        reinterpret_cast<FUN_00cb0a70_m_helper*>(pHelper)->m(iValue);
}

struct S_00dfb720_Elem
{
    ~S_00dfb720_Elem();
};

// @fnv 0x00dfbca0
// src: GUESS 0x00dfbca0 (confidence: medium)
void __cdecl Object_DestroyFields_00dfbca0(S_00dfb720_Elem* p)
{
    p->S_00dfb720_Elem::~S_00dfb720_Elem();
}

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dfbcd0
// src: GUESS 0x00dfbcd0 (confidence: low)
void __cdecl Runtime_Helper_00dfbcd0(void* p)
{
    ((VTable0*)*(void**)p)[0](p, 0);
}

typedef void(__thiscall* VFunc1)(void*, int);
// @fnv 0x00dfbdd0
// src: GUESS 0x00dfbdd0 (confidence: low)
void __cdecl Runtime_Helper_00dfbdd0(void* p)
{
    ((VFunc1*)*(void**)p)[0](p, 0);
}

struct FUN_00dfc040_vt
{
    virtual void __thiscall Object_ForwardCall_00dfc040(int);
};
// @fnv 0x00dfc040
// src: GUESS 0x00dfc040 (confidence: low)
void __cdecl Object_ForwardCall_00dfc040(FUN_00dfc040_vt* p)
{
    p->Object_ForwardCall_00dfc040(0);
}

typedef void(__thiscall* V00dfc790)(void*, int);
// @fnv 0x00dfc790
// src: GUESS 0x00dfc790 (confidence: low)
void __cdecl Runtime_Helper_00dfc790(void** p)
{
    ((V00dfc790)(*(void**)*p))(p, 0);
}

// @fnv 0x00dfc7f0
// src: GUESS 0x00dfc7f0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfc7f0(int* p)
{
    int* vt = (int*)(*(void**)p);
    ((void(__thiscall*)(void*, int))(*vt))((void*)p, 0);
}

// @fnv 0x00dfc8d0
// src: GUESS 0x00dfc8d0 (confidence: low)
void __cdecl Runtime_UpdateState_00dfc8d0(void** p)
{
    void** vt = (void**)*p;
    reinterpret_cast<VTable0>(vt[0])(p, 0);
}

typedef void(__thiscall* Vfn_00dfcb60)(void*, int);
// @fnv 0x00dfcb60
// src: GUESS 0x00dfcb60 (confidence: low)
void __cdecl Object_UpdateFields_00dfcb60(void* p)
{
    Vfn_00dfcb60 fn = ((Vfn_00dfcb60*)*(void**)p)[0];
    fn(p, 0);
}

struct FUN_00dfcc30_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfcc30
// src: GUESS 0x00dfcc30 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfcc30(FUN_00dfcc30_vt* p)
{
    p->v0(0);
}

struct FUN_00dd0420_Class
{
    FUN_00dd0420_Class* __thiscall hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(int);
};
// @fnv 0x00dfcd80
// src: GUESS 0x00dfcd80 (confidence: low)
void __cdecl Object_ProcessState_00dfcd80(FUN_00dd0420_Class* self, int a)
{
    if (self)
        self->hkpGenericConstraintDataScheme_hkpGenericConstraintDataScheme(a);
}

struct FUN_00dfce00_vt
{
    virtual void __thiscall v0(int);
};
// @fnv 0x00dfce00
// src: GUESS 0x00dfce00 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfce00(FUN_00dfce00_vt* p)
{
    p->v0(0);
}

struct FUN_00dfcf00_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dfcf00
// src: GUESS 0x00dfcf00 (confidence: medium)
void __cdecl Object_M_iWordAt00_Thunk(FUN_00dfcf00_vt* p)
{
    p->m_iWordAt00(0);
}

struct FUN_00dfd240_vt
{
    virtual void __thiscall Object_ForwardCall_00dfd240(int);
};
// @fnv 0x00dfd240
// src: GUESS 0x00dfd240 (confidence: low)
void __cdecl Object_ForwardCall_00dfd240(FUN_00dfd240_vt* p)
{
    p->Object_ForwardCall_00dfd240(0);
}

typedef void(__thiscall* Vfn_00dfd620)(void*, int);
// @fnv 0x00dfd620
// src: GUESS 0x00dfd620 (confidence: low)
void __cdecl Object_ProcessState_00dfd620(void* p)
{
    ((Vfn_00dfd620*)*(void**)p)[0](p, 0);
}

struct DFD680MeshData
{
    void ReleaseMeshArrays_00dfd680();
};
// @fnv 0x00dfd670
// src: GUESS 0x00dfd670 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfd670(DFD680MeshData* p)
{
    p->ReleaseMeshArrays_00dfd680();
}

extern int DAT_010e311c;
// If p is non-null, stores &DAT_010e311c at p[0] and calls m(a) on the helper objects at p+5 and p+16.
// @fnv 0x00dfd7d0
// src: GUESS 0x00dfd7d0 (confidence: low)
void Object_UpdateState_00dfd7d0(int* pObject, int aiValue)
{
    if (pObject)
    {
        pObject[0] = (int)&DAT_010e311c;
        ((FUN_00cb0a70_m_helper*)(pObject + 5))->m(aiValue);
        ((FUN_00cb0a70_m_helper*)(pObject + 16))->m(aiValue);
    }
}

// @fnv 0x00dfda70
// src: GUESS 0x00dfda70 (confidence: low)
void __cdecl Runtime_UpdateState_00dfda70(void* p)
{
    void(__thiscall * fn)(void*, int) = ((void(__thiscall*)(void*, int)) * (*(void***)p));
    fn(p, 0);
}

// @fnv 0x00dfdad0
// src: GUESS 0x00dfdad0 (confidence: low)
void Runtime_ProcessState_00dfdad0(int* a, int iValue)
{
    if (a)
        ((FUN_00cb0a70_m_helper*)(a + 1))->m(iValue);
}

// @fnv 0x00dfdb00
// src: GUESS 0x00dfdb00 (confidence: low)
void __cdecl Object_ProcessState_00dfdb00(void* p)
{
    ((VFunc0*)*(void**)p)[0](p, 0);
}

struct FUN_00dfdb20_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfdb20
// src: GUESS 0x00dfdb20 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfdb20(FUN_00dfdb20_vt* p)
{
    p->v0(0);
}

// @fnv 0x00dfdd30
void __cdecl CallHelperMethod(FUN_00cb0a70_m_helper* apHelper, int aiValue)
{
    if (apHelper)
        apHelper->m(aiValue);
}

struct S_00e3eaa0_Elem
{
    ~S_00e3eaa0_Elem();
};
// @fnv 0x00dfdd50
// src: GUESS 0x00dfdd50 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfdd50(S_00e3eaa0_Elem* p)
{
    p->S_00e3eaa0_Elem::~S_00e3eaa0_Elem();
}

struct FUN_00e3f900_class
{
    int ProcessAndReturnValue_00e3f900(int);
};
// @fnv 0x00dfdd60
// src: GUESS 0x00dfdd60 (confidence: low)
void __cdecl Object_ProcessState_00dfdd60(FUN_00e3f900_class* p, int a)
{
    if (p)
        p->ProcessAndReturnValue_00e3f900(a);
}

// @fnv 0x00dfdf70
void CallHelperWithInt(FUN_00cb0a70_m_helper* pHelper, int aiValue)
{
    if (pHelper)
        pHelper->m(aiValue);
}

namespace fnv_00dfdfa0 {
struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};
// @fnv 0x00dfdfa0
// src: GUESS 0x00dfdfa0 (confidence: medium)
void __cdecl Object_DestroyFields_00dfdfa0(S_00d49310_Lock* p)
{
    p->S_00d49310_Lock::~S_00d49310_Lock();
}
}  // namespace fnv_00dfdfa0

struct ArrayPair
{
    ~ArrayPair();
};
// @fnv 0x00dfe0c0
// src: GUESS 0x00dfe0c0 (confidence: medium)
void __cdecl Object_DestroyFields_00dfe0c0(ArrayPair* p)
{
    p->ArrayPair::~ArrayPair();
}

typedef void(__thiscall* Vfn_00dfe270)(void*, int);
// @fnv 0x00dfe270
// src: GUESS 0x00dfe270 (confidence: low)
void __cdecl Runtime_UpdateState_00dfe270(void* p)
{
    Vfn_00dfe270 fn = *(Vfn_00dfe270*)*(void**)p;
    fn(p, 0);
}

// @fnv 0x00dfe2b0
// src: GUESS 0x00dfe2b0 (confidence: low)
void __cdecl Runtime_Helper_00dfe2b0(void* p)
{
    ((void(__thiscall*)(void*, int)) * (*(void***)p))(p, 0);
}

extern int DAT_010cb864;
struct FUN_00ce5360_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int ComputeValue_00ce5360(int a);
};
// @fnv 0x00dfe2d0
// src: HAVOK_LIB 0x00dfe2d0
void __cdecl finishLoadedObjecthkaSkeletonMapper(FUN_00ce5360_class* pObject, int iValue)
{
    if (pObject)
    {
        int* p = (int*)pObject;
        *p = (int)&DAT_010cb864;
        ((FUN_00ce5360_class*)((char*)pObject + 0x10))->ComputeValue_00ce5360(iValue);
    }
}

struct FUN_00dfe320_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dfe320
// src: GUESS 0x00dfe320 (confidence: medium)
void __cdecl Object_M_iWordAt00_Thunk_00dfe320(FUN_00dfe320_vt* p)
{
    p->m_iWordAt00(0);
}

extern int DAT_010e56d4;
// @fnv 0x00dfe4a0
// src: GUESS 0x00dfe4a0 (confidence: low)
int* Object_GetGlobalObjectAddress_00dfe4a0()
{
    return &DAT_010e56d4;
}

struct FUN_00dfe4e0_vt
{
    virtual void m0(int);
};
// @fnv 0x00dfe4e0
// src: GUESS 0x00dfe4e0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfe4e0(FUN_00dfe4e0_vt* p)
{
    p->m0(0);
}

// @fnv 0x00dfe590
// src: GUESS 0x00dfe590 (confidence: low)
void __cdecl Runtime_UpdateState_00dfe590(void* p)
{
    void(__thiscall * fn)(void*, int);
    fn = (void(__thiscall*)(void*, int)) * ((void**)*((void**)p));
    fn(p, 0);
}

extern int DAT_010e587c;

// If a is non-null, stores &DAT_010e587c at its start and calls m(b) on the helper objects at offsets 8 and 0x54.
// @fnv 0x00dfe5b0
// src: HAVOK_LIB 0x00dfe5b0
void __cdecl finishLoadedObjecthkaBoneAttachment(void* pObject, int iValue)
{
    if (pObject)
    {
        *(int*)pObject = (int)&DAT_010e587c;
        ((FUN_00cb0a70_m_helper*)((char*)pObject + 8))->m(iValue);
        ((FUN_00cb0a70_m_helper*)((char*)pObject + 0x54))->m(iValue);
    }
}

extern int DAT_010e5a58;
// @fnv 0x00dfe990
// src: GUESS 0x00dfe990 (confidence: low)
void __cdecl Object_UpdateState_00dfe990(void* apObject, int aiValue)
{
    if (apObject)
    {
        *(void**)(char*)apObject = (void*)&DAT_010e5a58;
        ((FUN_00cb0a70_m_helper*)((char*)apObject + 8))->m(aiValue);
    }
}

// @fnv 0x00dfeb40
// src: GUESS 0x00dfeb40 (confidence: low)
void __cdecl Object_UpdateFields_00dfeb40(void* p)
{
    void(__thiscall * fn)(void*, int);
    fn = *reinterpret_cast<void(__thiscall**)(void*, int)>(*reinterpret_cast<void**>(p));
    fn(p, 0);
}

// @fnv 0x00dfebb0
// src: GUESS 0x00dfebb0 (confidence: low)
void __cdecl Runtime_Helper_00dfebb0(void** p)
{
    ((void(__thiscall*)(void*, int))(**(void****)p))(p, 0);
}

typedef void(__thiscall* Vfn0)(void*, int);
// @fnv 0x00dfebf0
// src: GUESS 0x00dfebf0 (confidence: low)
void __cdecl Runtime_Helper_00dfebf0(void* p)
{
    ((Vfn0*)*(void**)p)[0](p, 0);
}

struct FUN_00dfec30_vt
{
    virtual void m0(int);
};
// @fnv 0x00dfec30
// src: GUESS 0x00dfec30 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfec30(FUN_00dfec30_vt* p)
{
    p->m0(0);
}

struct FUN_00dfecf0_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfecf0
// src: GUESS 0x00dfecf0 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfecf0(FUN_00dfecf0_vt* p)
{
    p->v0(0);
}

struct FUN_00dfede0_vt
{
    virtual void v0(int);
};
// @fnv 0x00dfede0
// src: GUESS 0x00dfede0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfede0(FUN_00dfede0_vt* p)
{
    p->v0(0);
}

typedef int(__thiscall* Vfn_00dfeec0)(void*, int);
// @fnv 0x00dfeec0
// src: GUESS 0x00dfeec0 (confidence: low)
int __cdecl Object_GetIndexedValue_00dfeec0(void* p)
{
    return ((Vfn_00dfeec0*)*(void**)p)[0](p, 0);
}

struct FUN_00dfef00_vt
{
    virtual void __thiscall m0(int);
};
// @fnv 0x00dfef00
// src: GUESS 0x00dfef00 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfef00(FUN_00dfef00_vt* p)
{
    p->m0(0);
}

struct FUN_00dff1d0_vt
{
    virtual void m0(int);
};
// @fnv 0x00dff1d0
// src: GUESS 0x00dff1d0 (confidence: low)
void __cdecl Runtime_ForwardCall_00dff1d0(FUN_00dff1d0_vt* p)
{
    p->m0(0);
}

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dff300
// src: GUESS 0x00dff300 (confidence: low)
void __cdecl Object_ProcessState_00dff300(void** p)
{
    ((VTable0)(*(void**)*p))(p, 0);
}

struct FUN_00dff370_vt
{
    virtual void __thiscall Runtime_ForwardCall_00dff370(int);
};
// @fnv 0x00dff370
// src: GUESS 0x00dff370 (confidence: low)
void __cdecl Runtime_ForwardCall_00dff370(FUN_00dff370_vt* p)
{
    p->Runtime_ForwardCall_00dff370(0);
}

// @fnv 0x00dff540
// src: GUESS 0x00dff540 (confidence: low)
void __cdecl Object_ProcessState_00dff540(void** p)
{
    ((Vfn)(*(void**)*p))(p, 0);
}

typedef void(__thiscall* VTable0)(void*, int);
// @fnv 0x00dff580
// src: GUESS 0x00dff580 (confidence: low)
void __cdecl Object_ProcessState_00dff580(void** p)
{
    ((VTable0)(*(VTable0*)*p))(p, 0);
}

typedef void(__thiscall* VTable0)(void*, int);

// @fnv 0x00dff5c0
// src: GUESS 0x00dff5c0 (confidence: low)
void __cdecl Object_ProcessState_00dff5c0(void* p)
{
    ((VTable0*)*(void**)p)[0](p, 0);
}

extern int DAT_010cc2fc;
extern int DAT_010d0994;
struct FUN_00dff9b0_m : FUN_00cb0a70
{
    void __thiscall m(int);
};
// @fnv 0x00dff9b0
// src: GUESS 0x00dff9b0 (confidence: low)
void __cdecl Object_UpdateState_00dff9b0(FUN_00dff9b0_m* pObject, int aiValue)
{
    if (pObject)
    {
        *reinterpret_cast<void**>(pObject) = &DAT_010cc2fc;
        reinterpret_cast<FUN_00dff9b0_m*>(reinterpret_cast<char*>(pObject) + 0x14)->m(aiValue);
        *reinterpret_cast<void**>(pObject) = &DAT_010d0994;
    }
}

typedef void(__thiscall* VTblFn0)(void*, int);
// @fnv 0x00dffc10
// src: GUESS 0x00dffc10 (confidence: low)
void __cdecl Runtime_Helper_00dffc10(void* p)
{
    ((VTblFn0*)*(void**)p)[0](p, 0);
}

struct FUN_00dffc60_vt
{
    virtual void m0(int);
};
// @fnv 0x00dffc60
// src: GUESS 0x00dffc60 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dffc60(FUN_00dffc60_vt* p)
{
    p->m0(0);
}

struct FUN_00dffd80_vt
{
    virtual void __thiscall ReturnSelf(int);
};
// @fnv 0x00dffd80
// src: GUESS 0x00dffd80 (confidence: low)
void __cdecl Object_ForwardCall_00dffd80(FUN_00dffd80_vt* p)
{
    p->ReturnSelf(0);
}

typedef void(__thiscall* VTableFn)(void*, int);
// @fnv 0x00dffe20
// src: GUESS 0x00dffe20 (confidence: low)
void __cdecl Object_ProcessState_00dffe20(void* p)
{
    ((VTableFn*)*(void**)p)[0](p, 0);
}

struct FUN_00dffe60_vt
{
    virtual void m_iWordAt00(int);
};
// @fnv 0x00dffe60
// src: GUESS 0x00dffe60 (confidence: medium)
void __cdecl Object_M_iWordAt00_Thunk_00dffe60(FUN_00dffe60_vt* p)
{
    p->m_iWordAt00(0);
}

typedef void(__thiscall* Vfn0)(void*, int);
// @fnv 0x00dfff00
// src: GUESS 0x00dfff00 (confidence: low)
void __cdecl Object_ProcessState_00dfff00(void* p)
{
    ((Vfn0*)*((void**)p))[0](p, 0);
}

extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00de10e0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    void* m_p08;
    int m_0c;
    int m_10;

    FUN_00de10e0_cls* FUN_00de10e0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00de10e0
FUN_00de10e0_cls* FUN_00de10e0_cls::FUN_00de10e0(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    int count = m_10;
    m_0c = 0;
    if (((unsigned int)count & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_p08, (count & 0x3fffffff) * 8);
    }
    m_p08 = 0;
    m_10 = 0x80000000;
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}

extern float DAT_01017d00;

struct FUN_00de3050
{
    float m_iWordAt00;
    FUN_00de3050();
};

// @fnv 0x00de3050
FUN_00de3050::FUN_00de3050() : m_iWordAt00(DAT_01017d00)
{}

extern int DAT_010d8214;

class FUN_00de3060
{
  public:
    void* m_00;
    unsigned short m_04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int m_0c;

    FUN_00de3060(const unsigned int* src);
};

// Initializes the object: sets m_06 to 1, points m_00 at DAT_010d8214, copies *src into m_08 and zeroes m_0c.
// @fnv 0x00de3060
FUN_00de3060::FUN_00de3060(const unsigned int* src)
{
    m_06 = 1;
    m_00 = (void*)&DAT_010d8214;
    m_08 = *src;
    m_0c = 0;
}

class FUN_00de3090_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void ClearField0c();
};

// @fnv 0x00de3090
// src: GUESS 0x00de3090 (confidence: low)
void FUN_00de3090_cls::ClearField0c()
{
    m_0c = 0;
}

namespace fnv_00de43e0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

__forceinline Allocator& HeapAllocator(hkMemoryRouter* holder)
{
    return *reinterpret_cast<Allocator*>(holder->m_heap);
}

class BDE43E0ReferencedObject
{
  public:
    static void* operator new(unsigned int uiSize)
    {
        BDE43E0ReferencedObject* pkObject =
            static_cast<BDE43E0ReferencedObject*>(HeapAllocator(hkMemoryRouter_getInstance()).AllocateMemoryBlock(uiSize));
        pkObject->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return pkObject;
    }
    static void operator delete(void* pvMem);

    BDE43E0ReferencedObject() throw() : m_sReferenceCount(1)
    {}
    virtual ~BDE43E0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};



class BDE43E0Shape : public BDE43E0ReferencedObject
{
  public:
    BDE43E0Shape() throw()
    {}
    virtual ~BDE43E0Shape();

    hkArrayBase<void*> m_kChildList;
};

// Allocates and constructs a new BDE43E0Shape via its overloaded operator new and returns it as a BDE43E0ReferencedObject pointer.
// @fnv 0x00de43e0
BDE43E0ReferencedObject* __cdecl CreateShape()
{
    return new BDE43E0Shape;
}
}  // namespace fnv_00de43e0

struct Quad16
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};

class FUN_00de48a0_cls
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
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    Quad16 GetQuad16();
};

// @fnv 0x00de48a0
Quad16 FUN_00de48a0_cls::GetQuad16()
{
    Quad16 r;
    r.x = m_60;
    r.y = m_64;
    r.z = m_68;
    r.w = m_6c;
    return r;
}

// CopyStatsTo
// thiscall member of a game object class: copies the 16 bytes of the
// trailing "m_stats" block (this+0x70..0x7c) into the caller's output
// buffer and returns. One stack argument (the output pointer), callee-cleared.

struct StatsBlock
{
    int m_iStat00;
    int m_iStat04;
    int m_iStat08;
    int m_iStat0c;
};

struct GameObject
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
    StatsBlock m_stats;

    void CopyStatsTo(int* __restrict pOut);
};

// @fnv 0x00de48c0
void GameObject::CopyStatsTo(int* __restrict pOut)
{
    pOut[0] = m_stats.m_iStat00;
    pOut[1] = m_stats.m_iStat04;
    pOut[2] = m_stats.m_iStat08;
    pOut[3] = m_stats.m_iStat0c;
}

class FNVFloatGetter_cls
{
  public:
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
    float m_90;
    float GetField90_00de48e0();
};

// @fnv 0x00de48e0
// src: GUESS 0x00de48e0 (confidence: low)
float FNVFloatGetter_cls::GetField90_00de48e0()
{
    return m_90;
}

struct FUN_00de48f0_cls
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
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    float m_94;
    float GetField94();
};

// @fnv 0x00de48f0
// src: GUESS 0x00de48f0 (confidence: low)
float FUN_00de48f0_cls::GetField94()
{
    return m_94;
}

struct CpuObject
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
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    float value;
    float GetValue_00de4900();
};
// @fnv 0x00de4900
// src: GUESS 0x00de4900 (confidence: high)
float CpuObject::GetValue_00de4900()
{
    return value;
}

struct FUN_00de4910_cls
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
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int GetField9c();
};

// @fnv 0x00de4910
// src: GUESS 0x00de4910 (confidence: low)
int FUN_00de4910_cls::GetField9c()
{
    return m_9c;
}

// CopyVec4ToBuffer: copies the 16-byte vector stored at this+0x80 into the
// 4-int block pointed to by the stack parameter.

struct FUN_00de4920_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    Vec4 m_v80;
    void CopyVec4ToBuffer(int* volatile pOut);
};

// Copies the four components of m_v80 into the four ints pointed to by pOut, reading the last two as one 64-bit value.
// @fnv 0x00de4920
void FUN_00de4920_cls::CopyVec4ToBuffer(int* volatile pOut)
{
    int* out = pOut;
    out[0] = m_v80.xb;
    out[1] = m_v80.yb;
    __int64 tail = *(__int64*)&m_v80.zb;
    int* t = (int*)&tail;
    out[2] = t[0];
    out[3] = t[1];
}

namespace fnv_00de4e00 {
struct CpuObject
{
    char* ComputeValue_00de4e00();
};
// @fnv 0x00de4e00
// src: GUESS 0x00de4e00 (confidence: low)
char* CpuObject::ComputeValue_00de4e00()
{
    return reinterpret_cast<char*>(this) + 128;
}
}  // namespace fnv_00de4e00

struct FUN_00de4e10_cls
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

    char* GetFieldAtOffset90();
};

// @fnv 0x00de4e10
// src: GUESS 0x00de4e10 (confidence: low)
char* FUN_00de4e10_cls::GetFieldAtOffset90()
{
    return (char*)this + 0x90;
}

class FUN_00de5320_cls
{
  public:
    Vec4 GetVec4At70();
};

// @fnv 0x00de5320
Vec4 FUN_00de5320_cls::GetVec4At70()
{
    Vec4* src = (Vec4*)((char*)this + 0x70);
    return *src;
}

namespace fnv_00de5340 {
struct CpuObject
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
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    float value;
    float GetValue_00de5340();
};
// @fnv 0x00de5340
// src: GUESS 0x00de5340 (confidence: high)
float CpuObject::GetValue_00de5340()
{
    return value;
}
}  // namespace fnv_00de5340

struct FUN_00de5350_cls
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
    float m_84;
    float GetField84();
};
// @fnv 0x00de5350
// src: GUESS 0x00de5350 (confidence: low)
float FUN_00de5350_cls::GetField84()
{
    return m_84;
}

class FUN_00de5360_cls
{
  public:
    void* GetFieldAtOffset80_00de5360();
};

// @fnv 0x00de5360
// src: GUESS 0x00de5360 (confidence: low)
void* FUN_00de5360_cls::GetFieldAtOffset80_00de5360()
{
    return *(void**)((char*)this + 0x80);
}

extern void* DAT_01269ce8;

// @fnv 0x00de8150
// src: GUESS 0x00de8150 (confidence: low)
int __cdecl Runtime_EvaluateValue_00de8150()
{
    return reinterpret_cast<int>(&DAT_01269ce8);
}

extern int DAT_01269d18;

// @fnv 0x00de8170
// src: GUESS 0x00de8170 (confidence: low)
int* __cdecl Runtime_GetDAT01269d18Address()
{
    return &DAT_01269d18;
}

extern int DAT_01269d48;

// @fnv 0x00de8190
// src: GUESS 0x00de8190 (confidence: low)
void* Runtime_GetDAT01269d48Address()
{
    return &DAT_01269d48;
}

extern int g_unk01269d78;

// @fnv 0x00de81d0
// src: GUESS 0x00de81d0 (confidence: low)
void* __cdecl Runtime_GetUnk01269d78Address()
{
    return &g_unk01269d78;
}

struct CpuOpaque;
extern CpuOpaque DAT_01269da8;
// @fnv 0x00de81f0
// src: GUESS 0x00de81f0 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT01269da8Address()
{
    return &DAT_01269da8;
}

extern int DAT_01269dd8;

// @fnv 0x00de8210
// src: GUESS 0x00de8210 (confidence: low)
void* __cdecl Runtime_GetDAT01269dd8Address()
{
    return &DAT_01269dd8;
}

extern int g_unk01269e08;

// @fnv 0x00de8230
// src: GUESS 0x00de8230 (confidence: low)
int* Runtime_GetUnk01269e08Address()
{
    return &g_unk01269e08;
}

struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00de8250
// src: GUESS 0x00de8250 (confidence: high)
GlobalObject* __cdecl Runtime_GetGlobalAddress()
{
    return &g_global;
}

struct CpuOpaque;
extern CpuOpaque DAT_01269e68;
// @fnv 0x00de8270
// src: GUESS 0x00de8270 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT01269e68Address()
{
    return &DAT_01269e68;
}

extern int g_unk01269e98;

// @fnv 0x00de8290
// src: GUESS 0x00de8290 (confidence: low)
void* __cdecl Runtime_GetUnk01269e98Address()
{
    return &g_unk01269e98;
}

extern int g_unk01269ec8;

// @fnv 0x00de82b0
// src: GUESS 0x00de82b0 (confidence: low)
void* __cdecl Runtime_GetUnk01269ec8Address()
{
    return &g_unk01269ec8;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269ef8;
// @fnv 0x00de82d0
// src: GUESS 0x00de82d0 (confidence: low)
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField01269ef8Address()
{
    return &g_01269ef8;
}

extern int DAT_01269f28;

// @fnv 0x00de82f0
// src: GUESS 0x00de82f0 (confidence: low)
void* __cdecl Runtime_GetDAT01269f28Address()
{
    return &DAT_01269f28;
}

extern int g_unkGlobal01269f58;

// @fnv 0x00de8310
// src: GUESS 0x00de8310 (confidence: low)
void* __cdecl Runtime_GetUnkGlobal01269f58Address()
{
    return &g_unkGlobal01269f58;
}

extern int DAT_01269f88;

// @fnv 0x00de8330
// src: GUESS 0x00de8330 (confidence: low)
void* __cdecl Runtime_GetDAT01269f88Address()
{
    return &DAT_01269f88;
}

// FUN_00de8350 : a one-line function - getter
extern int g_target_00de8350;
// @fnv 0x00de8350
// src: GUESS 0x00de8350 (confidence: low)
void* Runtime_GetTarget00de8350Address()
{
    return &g_target_00de8350;
}

extern int DAT_0126a018;

// @fnv 0x00de8390
// src: GUESS 0x00de8390 (confidence: low)
void* __cdecl Runtime_GetDAT0126a018Address()
{
    return &DAT_0126a018;
}

extern int DAT_0126a048;
// @fnv 0x00de83b0
// src: GUESS 0x00de83b0 (confidence: low)
int* Runtime_GetDAT0126a048Address()
{
    return &DAT_0126a048;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126a078;
// @fnv 0x00de83d0
// src: GUESS 0x00de83d0 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126a078Address()
{
    return &DAT_0126a078;
}

extern int DAT_0126a0a8;

// @fnv 0x00de83f0
// src: GUESS 0x00de83f0 (confidence: low)
void* __cdecl Runtime_GetDAT0126a0a8Address()
{
    return &DAT_0126a0a8;
}

extern int DAT_0126a0d8;

// @fnv 0x00de8410
// src: GUESS 0x00de8410 (confidence: low)
void* __cdecl Runtime_GetDAT0126a0d8Address()
{
    return &DAT_0126a0d8;
}

extern int DAT_0126a108;
// @fnv 0x00de8430
// src: GUESS 0x00de8430 (confidence: low)
int* __cdecl Runtime_GetDAT0126a108Address()
{
    return &DAT_0126a108;
}

extern int DAT_0126a138;

// @fnv 0x00de8450
// src: GUESS 0x00de8450 (confidence: low)
void* __cdecl Runtime_GetDAT0126a138Address()
{
    return &DAT_0126a138;
}

extern int DAT_0126a168;

// @fnv 0x00de8470
// src: GUESS 0x00de8470 (confidence: low)
void* __cdecl Runtime_GetDAT0126a168Address()
{
    return &DAT_0126a168;
}

extern int DAT_0126a198;

// @fnv 0x00de8490
// src: GUESS 0x00de8490 (confidence: low)
int* __cdecl Runtime_GetDAT0126a198Address()
{
    return &DAT_0126a198;
}

extern int DAT_0126a1c8;

// @fnv 0x00de84b0
// src: GUESS 0x00de84b0 (confidence: low)
void* __cdecl Runtime_GetDAT0126a1c8Address()
{
    return &DAT_0126a1c8;
}

extern FUN_00de87c0_class DAT_0126a1f8;

// @fnv 0x00de84d0
// src: GUESS 0x00de84d0 (confidence: low)
FUN_00de87c0_class* __cdecl Runtime_GetDAT0126a1f8Address()
{
    return &DAT_0126a1f8;
}

// FUN_00de84f0 : returns the address of a global data object.
// Original: mov eax, offset DAT_0126a228 ; ret
extern int DAT_0126a228;

// @fnv 0x00de84f0
// src: GUESS 0x00de84f0 (confidence: low)
int* __cdecl Runtime_GetDAT0126a228Address()
{
    return &DAT_0126a228;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126a258;
// @fnv 0x00de8510
// src: GUESS 0x00de8510 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126a258Address()
{
    return &DAT_0126a258;
}

extern int g_0126a288;

// @fnv 0x00de8530
// src: GUESS 0x00de8530 (confidence: low)
int* __cdecl Runtime_GetField0126a288Address()
{
    return &g_0126a288;
}

struct FUN_00de8570_cls
{
    int m_00;
    int m_04;
    int m_08;
    void __thiscall hkpBridgeConstraintAtom_init(int value);
};

// @fnv 0x00de8570
// src: GUESS 0x00de8570 (confidence: low)
void __cdecl hkpBridgeConstraintAtom_init_ProcessState_00de8570(FUN_00de8570_cls* pTarget, int nIndex)
{
    if (pTarget != 0)
    {
        if (nIndex != 0)
        {
            pTarget->hkpBridgeConstraintAtom_init(pTarget->m_08);
        }
    }
}

extern int DAT_0126a378;

// @fnv 0x00de8750
// src: GUESS 0x00de8750 (confidence: low)
void* __cdecl Runtime_GetDAT0126a378Address()
{
    return &DAT_0126a378;
}

extern int g_unk126a3a8;

// @fnv 0x00de8770
// src: GUESS 0x00de8770 (confidence: low)
void* __cdecl Runtime_GetUnk126a3a8Address()
{
    return &g_unk126a3a8;
}

class FUN_00de8780_cls
{
  public:
    float m_fValues[16];

    unsigned char* HasNoNaNOrInf(unsigned char* pResult);
};

// Checks all 16 floats for NaN or infinity via exponent bits and writes 0 to pResult if any is found, otherwise 1.
// @fnv 0x00de8780
unsigned char* FUN_00de8780_cls::HasNoNaNOrInf(unsigned char* pResult)
{
    for (int i = 0; i < 16; ++i)
    {
        float f = m_fValues[i];
        unsigned int bits = *(unsigned int*)&f;
        if ((bits & 0x7f800000) == 0x7f800000)
        {
            *pResult = 0;
            return pResult;
        }
    }
    *pResult = 1;
    return pResult;
}

struct JacRow
{
    float x;
    float y;
    float z;
    float w;
};
struct JacBlock
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
    JacRow rows[6];
};

// @fnv 0x00df06a0
void __cdecl ResetJacobianRows(unsigned char* flags, bool both, JacBlock* pJacA, JacBlock* pJacB)
{
    if (*flags)
    {
        if (*flags & 3)
        {
            for (int i = 0; i < 6; i++)
                pJacA->rows[i].x = 0.0f;
            pJacA->rows[3].x = 1.0f;
            if (both)
            {
                for (int i = 0; i < 6; i++)
                    pJacB->rows[i].x = 0.0f;
            }
        }
        if (*flags & 0xc)
        {
            for (int i = 0; i < 6; i++)
                pJacA->rows[i].y = 0.0f;
            pJacA->rows[4].y = 1.0f;
            if (both)
            {
                for (int i = 0; i < 6; i++)
                    pJacB->rows[i].y = 0.0f;
            }
        }
        if (*flags & 0x30)
        {
            for (int i = 0; i < 6; i++)
                pJacA->rows[i].z = 0.0f;
            pJacA->rows[5].z = 1.0f;
            if (both)
            {
                for (int i = 0; i < 6; i++)
                    pJacB->rows[i].z = 0.0f;
            }
        }
    }
}

struct DF25D0State
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    short unk10;
    unsigned char m_ucFlags;
};

struct DF25D0Owner
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
    DF25D0State* m_pkState;
};

void __cdecl hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(void* pkItem, DF25D0Owner* pkOwner);

// @fnv 0x00df25d0
static __declspec(noinline) void SetOwnerStateFlags(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType)
{
    hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(pkItem, pkOwner);
    pkOwner->m_pkState->m_ucFlags |= m_ucEntryType;
}

// Caller so the file-static helper is emitted with its register calling convention.
void DF25D0Attach(void* pkItem, DF25D0Owner* pkOwner, unsigned char m_ucEntryType)
{
    SetOwnerStateFlags(pkItem, pkOwner, m_ucEntryType);
    SetOwnerStateFlags(pkOwner, pkOwner, m_ucEntryType);
}

class FUN_00df3110
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
    int m_iArrayLength;

    FUN_00df3110();
};

// @fnv 0x00df3110
FUN_00df3110::FUN_00df3110()
{
    m_iArrayLength = 0;
}

struct FUN_00df3140_pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

// @fnv 0x00df3140
void __stdcall CopyPairToIndex(FUN_00df3140_pair* dst, unsigned int auiIndex, FUN_00df3140_pair* src)
{
    dst[auiIndex] = *src;
}

struct Handler_cls
{
    void __thiscall Handle(int value);
};

// @fnv 0x00df6440
// src: GUESS 0x00df6440 (confidence: low)
void __cdecl Object_ProcessState_00df6440(Handler_cls* pHandler, int value)
{
    if (pHandler != 0)
        pHandler->Handle(value);
}

extern int g_0126a430;

// @fnv 0x00df6490
// src: GUESS 0x00df6490 (confidence: low)
int* __cdecl Runtime_GetField0126a430Address()
{
    return &g_0126a430;
}

extern int DAT_0126a478;

// @fnv 0x00df64b0
// src: GUESS 0x00df64b0 (confidence: low)
void* __cdecl Runtime_GetDAT0126a478Address()
{
    return &DAT_0126a478;
}

extern "C" int DAT_0126a4a8;

// @fnv 0x00df64c0
// src: GUESS 0x00df64c0 (confidence: low)
extern "C" void* __cdecl Object_GetGlobalObjectAddress_00df64c0()
{
    return &DAT_0126a4a8;
}

struct FUN_00df7a60_class
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    void* m_p10;
    int unk14;
    int unk18;
    void* m_p1c;

    void __thiscall hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd(volatile long* value, long increment);

void __cdecl hkSemaphoreBusyWait_release(void* object, int value);

// @fnv 0x00df7a60
// src: HAVOK_LIB 0x00df7a60
void FUN_00df7a60_class::hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore()
{
    if (m_p1c != 0)
    {
        InterlockedExchangeAdd(static_cast<volatile long*>(m_p1c), 1);
    }

    if (m_p10 != 0)
    {
        hkSemaphoreBusyWait_release(m_p10, 1);
    }
}

extern float DAT_010dbb3c;
extern float DAT_0104da48;
struct ParserContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, result44;
    int __thiscall ClipRangeByPlane(int, void*, float*);
};
struct FloatPair
{
    float first, second;
    int __thiscall TraverseNode(ParserContext*, int, int*, ParserContext**);
    int __thiscall hkWingedEdge_findVisibilityBoundaryEdges(ParserContext*, int, int*, ParserContext**);
};
// Initialises first/second from constants, calls ctx->FUN_00e63af0 and, if it returns 1, delegates to TraverseNode; otherwise returns 2.
// @fnv 0x00dfb040
// src: HAVOK_LIB 0x00dfb040
int __thiscall FloatPair::hkWingedEdge_findVisibilityBoundaryEdges(ParserContext* ctx, int input, int* outA, ParserContext** outB)
{
    double initial = DAT_010dbb3c;
    *outB = 0;
    *outA = 0;
    first = (float)initial;
    second = DAT_0104da48;
    ctx->result44 = ctx->ClipRangeByPlane(input, this, &second);
    if (ctx->result44 == 1)
        return TraverseNode(ctx, input, outA, outB);
    return 2;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126a5f8;
// @fnv 0x00dfb260
// src: GUESS 0x00dfb260 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfb260()
{
    return &DAT_0126a5f8;
}

extern int g_unk0126aa18;

// @fnv 0x00dfb280
// src: GUESS 0x00dfb280 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfb280()
{
    return &g_unk0126aa18;
}

struct FUN_00dfb2d0_class
{
    void __thiscall FUN_00dfb2d0(int a);
};

// @fnv 0x00dfb290
// src: GUESS 0x00dfb290 (confidence: low)
void __cdecl Object_ProcessState_00dfb290(FUN_00dfb2d0_class* pObject, int a)
{
    if (pObject)
        pObject->FUN_00dfb2d0(a);
}

extern int DAT_0126aac0;

// @fnv 0x00dfb360
// src: GUESS 0x00dfb360 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfb360()
{
    return &DAT_0126aac0;
}

extern int DAT_0126aaf0;

// @fnv 0x00dfb380
// src: GUESS 0x00dfb380 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfb380()
{
    return &DAT_0126aaf0;
}

extern int DAT_0126abe0;

// @fnv 0x00dfb3c0
// src: GUESS 0x00dfb3c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfb3c0(void)
{
    return &DAT_0126abe0;
}

// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (ecx = object, one stack argument).
struct FUN_00dfb3d0_cls
{
    void __thiscall hkaMeshBinding_hkaMeshBinding(int a1);
};

// @fnv 0x00dfb3d0
// src: GUESS 0x00dfb3d0 (confidence: low)
void __cdecl Object_ProcessState_00dfb3d0(FUN_00dfb3d0_cls* pObject, int a1)
{
    if (pObject != 0)
    {
        pObject->hkaMeshBinding_hkaMeshBinding(a1);
    }
}

extern unsigned char DAT_0126ac10;

// @fnv 0x00dfb420
// src: GUESS 0x00dfb420 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfb420()
{
    return &DAT_0126ac10;
}

struct FUN_00e2ebc0_cls
{
    void __thiscall Init(void* a);
};

// @fnv 0x00dfb430
// src: GUESS 0x00dfb430 (confidence: low)
void __cdecl Object_ProcessState_00dfb430(FUN_00e2ebc0_cls* pObject, void* pArg)
{
    if (pObject != 0)
        pObject->Init(pArg);
}

extern "C" int DAT_0126ac58;
// @fnv 0x00dfb480
// src: GUESS 0x00dfb480 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfb480(void)
{
    return &DAT_0126ac58;
}

extern int DAT_0126acd0;

// @fnv 0x00dfb4d0
// src: GUESS 0x00dfb4d0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfb4d0()
{
    return reinterpret_cast<int>(&DAT_0126acd0);
}

extern int DAT_0126ad00;
// @fnv 0x00dfb4f0
// src: GUESS 0x00dfb4f0 (confidence: low)
void* __cdecl Runtime_GetDAT0126ad00Address()
{
    return &DAT_0126ad00;
}

extern int DAT_0126ad30;

// @fnv 0x00dfb510
// src: GUESS 0x00dfb510 (confidence: low)
void* __cdecl Runtime_GetDAT0126ad30Address()
{
    return &DAT_0126ad30;
}

extern void* DAT_0126ad60;

// @fnv 0x00dfb540
// src: GUESS 0x00dfb540 (confidence: low)
int __cdecl Object_ComputeValue_00dfb540()
{
    return reinterpret_cast<int>(&DAT_0126ad60);
}

class DFB550Object
{
  public:
    virtual ~DFB550Object();
};

// @fnv 0x00dfb550
// src: GUESS 0x00dfb550 (confidence: low)
void Runtime_DestroySubobject_00dfb550(DFB550Object* pkObject)
{
    pkObject->~DFB550Object();
}

extern int DAT_0126ad90;

// @fnv 0x00dfb560
// src: GUESS 0x00dfb560 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfb560()
{
    return &DAT_0126ad90;
}

inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

struct DFB570FinishFlag
{
    int m_bFinishing;
};

class DFB570Object
{
  public:
    DFB570Object(DFB570FinishFlag flag)
    {
        if (flag.m_bFinishing)
            finishInit();
    }

    virtual void vfunc00();

    void finishInit();
};

// @fnv 0x00dfb570
// src: GUESS 0x00dfb570 (confidence: low)
void Runtime_AllocateStorage_00dfb570(void* apMemory, int finishing)
{
    DFB570FinishFlag flag;
    flag.m_bFinishing = finishing;
    new (apMemory) DFB570Object(flag);
}

extern int DAT_010ddc5c;

// @fnv 0x00dfb590
// src: GUESS 0x00dfb590 (confidence: low)
void* __cdecl Runtime_GetDAT010ddc5cAddress()
{
    return &DAT_010ddc5c;
}

extern int DAT_0126add8;

// @fnv 0x00dfb860
// src: GUESS 0x00dfb860 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfb860()
{
    return &DAT_0126add8;
}

extern unsigned char g_fnvDat0126ae08;

// @fnv 0x00dfb880
// src: GUESS 0x00dfb880 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfb880()
{
    return &g_fnvDat0126ae08;
}

// FUN_00dfb8a0 : a one-line function - getter
extern int g_target_00dfb8a0;
// @fnv 0x00dfb8a0
// src: GUESS 0x00dfb8a0 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfb8a0()
{
    return &g_target_00dfb8a0;
}

// ResetVTable -- installs a fixed vtable on an object and, when the second
// argument is set, runs the object's update step afterwards.

extern int DAT_010de0ec;  // vtable that gets installed

struct ResetVTableObj
{
    void* m_vptr;  // virtual table pointer, offset 0
};

struct ResetVTableTarget
{
    void __thiscall m_update();
};

// @fnv 0x00dfb8b0
void __cdecl ResetVTable(ResetVTableObj* pObj, int bUpdate)
{
    if (pObj != 0)
    {
        pObj->m_vptr = reinterpret_cast<void*>(&DAT_010de0ec);
        if (bUpdate != 0)
        {
            reinterpret_cast<ResetVTableTarget*>(pObj)->m_update();
        }
    }
}

extern int DAT_010de0ec;

// @fnv 0x00dfb8d0
// src: GUESS 0x00dfb8d0 (confidence: low)
void* Runtime_GetDAT010de0ecAddress()
{
    return &DAT_010de0ec;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126ae80;
// @fnv 0x00dfb920
// src: GUESS 0x00dfb920 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfb920()
{
    return &DAT_0126ae80;
}

extern int DAT_0126aeb0;

// @fnv 0x00dfb940
// src: GUESS 0x00dfb940 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfb940()
{
    return &DAT_0126aeb0;
}

class CalleeObj
{
  public:
    void ComputeValue_00ce5360(void* pParam);
};

// @fnv 0x00dfb950
// src: GUESS 0x00dfb950 (confidence: low)
void __cdecl Runtime_ProcessState_00dfb950(CalleeObj* pCallee, void* pSecond)
{
    if (pCallee != 0)
    {
        pCallee->ComputeValue_00ce5360(pSecond);
    }
}

extern int DAT_0126aee0;

// @fnv 0x00dfb970
// src: GUESS 0x00dfb970 (confidence: low)
int* __cdecl Runtime_GetDAT0126aee0Address()
{
    return &DAT_0126aee0;
}

struct FUN_00ce5370_cls
{
    void __thiscall UpdateState_00ce5370();
};

// @fnv 0x00dfb980
// src: GUESS 0x00dfb980 (confidence: low)
void __cdecl Object_ForwardCall_00dfb980(FUN_00ce5370_cls* p)
{
    p->UpdateState_00ce5370();
}

extern int DAT_0126af10;

// @fnv 0x00dfb990
// src: GUESS 0x00dfb990 (confidence: low)
int* __cdecl Runtime_GetDAT0126af10Address()
{
    return &DAT_0126af10;
}

// FUN_00dfb9a0 : __cdecl, 13 bytes
//   mov ecx, dword ptr [esp + 4]
//   mov eax, dword ptr [ecx]
//   mov edx, dword ptr [eax]
//   push 0
//   call edx
//   ret
// Calls vtable slot 0 of the object passed in, with the argument 0.

struct FUN_00dfb9a0_cls
{
    virtual int v00(int a);
};

// @fnv 0x00dfb9a0
// src: GUESS 0x00dfb9a0 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00dfb9a0(FUN_00dfb9a0_cls* pObj)
{
    return pObj->v00(0);
}

extern int DAT_0126af40;
// @fnv 0x00dfb9b0
// src: GUESS 0x00dfb9b0 (confidence: low)
int* __cdecl Runtime_GetDAT0126af40Address(void)
{
    return &DAT_0126af40;
}

extern int DAT_0126af88;
// @fnv 0x00dfba40
// src: GUESS 0x00dfba40 (confidence: low)
int* Object_GetGlobalObjectAddress_00dfba40()
{
    return &DAT_0126af88;
}

// FUN_00dfba50: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfba50_cls
{
  public:
    void FUN_00e34800(int a1);
};

// @fnv 0x00dfba50
// src: GUESS 0x00dfba50 (confidence: low)
void __cdecl Object_ProcessState_00dfba50(FUN_00dfba50_cls* pObject, int a1)
{
    if (pObject != 0)
    {
        pObject->FUN_00e34800(a1);
    }
}

extern int g_unk0126afb8;

// @fnv 0x00dfbaa0
// src: GUESS 0x00dfbaa0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfbaa0()
{
    return &g_unk0126afb8;
}

namespace fnv_00dfbac0 {
struct FreeAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct FreeHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FreeAllocator* m_pAllocator;
};

FreeHolder* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfbac0_cls
{
    void* m_pData;
    int m_04;
    unsigned int m_flags;
};

// @fnv 0x00dfbac0
// src: HAVOK_LIB 0x00dfbac0
void __cdecl cleanupLoadedObjecthkaMeshBindingMapping(FUN_00dfbac0_cls* apBuffer)
{
    FreeHolder* holder = hkMemoryRouter_getInstance();
    FreeAllocator* alloc = holder->m_pAllocator;
    unsigned int flags = apBuffer->m_flags;
    apBuffer->m_04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(apBuffer->m_pData, (flags & 0x3fffffffu) * 2);
    }
    apBuffer->m_pData = 0;
    apBuffer->m_flags = 0x80000000u;
}
}  // namespace fnv_00dfbac0

struct CpuOpaque;
extern CpuOpaque DAT_0126b000;
// @fnv 0x00dfbb20
// src: GUESS 0x00dfbb20 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfbb20()
{
    return &DAT_0126b000;
}

extern int DAT_0126b030;

// @fnv 0x00dfbb40
// src: GUESS 0x00dfbb40 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfbb40()
{
    return &DAT_0126b030;
}

// FUN_00dfbb50 : installs the class vtable into the object and, when the
// second argument is non-zero, tail-calls the routine at FUN_00e35050 with
// the object as 'this'.

extern int DAT_010de90c;

struct FUN_00dfbb50_cls
{
    void* m_vtbl;
    void __thiscall hkaDeltaCompressedAnimation_handleEndian();
};

// @fnv 0x00dfbb50
// src: GUESS 0x00dfbb50 (confidence: low)
void __cdecl Object_UpdateState_00dfbb50(FUN_00dfbb50_cls* apObject, int a)
{
    if (apObject)
    {
        apObject->m_vtbl = (void*)&DAT_010de90c;
        if (a)
        {
            apObject->hkaDeltaCompressedAnimation_handleEndian();
        }
    }
}

extern int DAT_010de90c;

// @fnv 0x00dfbb70
// src: GUESS 0x00dfbb70 (confidence: low)
void* __cdecl Runtime_GetDAT010de90cAddress()
{
    return &DAT_010de90c;
}

extern "C" int DAT_0126b078;

// @fnv 0x00dfbc10
// src: GUESS 0x00dfbc10 (confidence: low)
extern "C" void* __cdecl Runtime_GetGlobal0126B078Address()
{
    return &DAT_0126b078;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126b0a8;
// @fnv 0x00dfbc50
// src: GUESS 0x00dfbc50 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126b0a8Address()
{
    return &DAT_0126b0a8;
}

extern int DAT_0126b0d8;

// @fnv 0x00dfbc60
// src: GUESS 0x00dfbc60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfbc60()
{
    return &DAT_0126b0d8;
}

namespace fnv_00dfbcc0 {
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00dfbcc0
// src: GUESS 0x00dfbcc0 (confidence: low)
GlobalObject* __cdecl Object_GetGlobalObjectAddress_00dfbcc0()
{
    return &g_global;
}
}  // namespace fnv_00dfbcc0

extern int DAT_0126b138;

// @fnv 0x00dfbce0
// src: GUESS 0x00dfbce0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfbce0()
{
    return &DAT_0126b138;
}

// InitVTable : __cdecl initializer for an object with several vtable slots.
// The first vtable is installed, a flag byte at +9 is cleared when the flag is
// set, then the second vtable is installed along with two secondary vtables
// at +0x24 and +0x1c. Finally the flag byte is set to 2 when the flag is set.

extern int DAT_010dec04;
extern int DAT_010dec3c;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;

struct FUN_00dfbcf0_obj
{
    void* m_pVTable00;
    int m_iValue04;
    unsigned char m_bValue08;
    unsigned char m_bFlag09;
    unsigned short m_wValue0a;
    int m_iValue0c;
    int m_iValue10;
    int m_iValue14;
    int m_iValue18;
    void* m_pVTable1c;
    int m_iValue20;
    void* m_pVTable24;
};

// If self is non-null, assigns the vtable pointers and, when flag is set, sets m_bFlag09 to 0 then 2.
// @fnv 0x00dfbcf0
void __cdecl InitVTable(FUN_00dfbcf0_obj* self, int flag)
{
    if (self != 0)
    {
        self->m_pVTable00 = (void*)&DAT_010dec04;
        if (flag != 0)
        {
            self->m_bFlag09 = 0;
        }
        self->m_pVTable00 = (void*)&DAT_010dec3c;
        *(void* volatile*)&self->m_pVTable24 = (void*)&DAT_010c925c;
        self->m_pVTable1c = (void*)&DAT_010debf4;
        self->m_pVTable24 = (void*)&DAT_010debe4;
        if (flag != 0)
        {
            self->m_bFlag09 = 2;
        }
    }
}

extern int DAT_010dec3c;

// @fnv 0x00dfbd30
// src: GUESS 0x00dfbd30 (confidence: low)
void* __cdecl Runtime_GetDAT010dec3cAddress()
{
    return &DAT_010dec3c;
}

extern int DAT_0126b180;

// @fnv 0x00dfbdc0
// src: GUESS 0x00dfbdc0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfbdc0()
{
    return &DAT_0126b180;
}

extern int DAT_0126b1b0;

// @fnv 0x00dfbde0
// src: GUESS 0x00dfbde0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfbde0()
{
    return &DAT_0126b1b0;
}

extern int DAT_0126b1f8;

// @fnv 0x00dfbe90
// src: GUESS 0x00dfbe90 (confidence: low)
void* __cdecl Runtime_GetDAT0126b1f8Address()
{
    return &DAT_0126b1f8;
}

extern unsigned char DAT_0126b228;

// @fnv 0x00dfbeb0
// src: GUESS 0x00dfbeb0 (confidence: low)
void* __cdecl Runtime_GetDAT0126b228Address()
{
    return &DAT_0126b228;
}

extern int DAT_0126b258;

// @fnv 0x00dfbed0
// src: GUESS 0x00dfbed0 (confidence: low)
void* __cdecl Runtime_GetDAT0126b258Address()
{
    return &DAT_0126b258;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126b288;
// @fnv 0x00dfbef0
// src: GUESS 0x00dfbef0 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126b288Address()
{
    return &DAT_0126b288;
}

extern int DAT_0126b2b8;

// @fnv 0x00dfbf20
// src: GUESS 0x00dfbf20 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfbf20()
{
    return &DAT_0126b2b8;
}

struct FUN_00dfbf30_class
{
    virtual void m0(int);
};

// @fnv 0x00dfbf30
// src: GUESS 0x00dfbf30 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfbf30(void* p)
{
    ((FUN_00dfbf30_class*)p)->m0(0);
}

extern int DAT_0126b2e8;

// @fnv 0x00dfbf40
// src: GUESS 0x00dfbf40 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfbf40()
{
    return &DAT_0126b2e8;
}

// @fnv 0x00dfbf60
// src: GUESS 0x00dfbf60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfbf60()
{
    return &DAT_010df89c;
}

extern int DAT_0126b330;

// @fnv 0x00dfc030
// src: GUESS 0x00dfc030 (confidence: low)
void* __cdecl Runtime_GetDAT0126b330Address()
{
    return &DAT_0126b330;
}

// FUN_00dfc050 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfc050;

// @fnv 0x00dfc050
// src: GUESS 0x00dfc050 (confidence: low)
void* __cdecl Runtime_GetTargetFUN00dfc050Address()
{
    return &g_target_FUN_00dfc050;
}

// FUN_00dfc070 : a one-line function - getter
extern int g_target_00dfc070;
// @fnv 0x00dfc070
// src: GUESS 0x00dfc070 (confidence: low)
void* Runtime_GetTarget00dfc070Address()
{
    return &g_target_00dfc070;
}

extern int DAT_0126b3a8;

// @fnv 0x00dfc100
// src: GUESS 0x00dfc100 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc100()
{
    return &DAT_0126b3a8;
}

struct S_00dfc110_vt
{
    virtual void m0(int);
};

void __thiscall S_00dfc110_vt::m0(int)
{}

// @fnv 0x00dfc110
// src: GUESS 0x00dfc110 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfc110(void* p)
{
    ((S_00dfc110_vt*)p)->m0(0);
}

extern int g_0126b3d8;

// @fnv 0x00dfc120
// src: GUESS 0x00dfc120 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc120()
{
    return &g_0126b3d8;
}

extern int DAT_010dff44;

// @fnv 0x00dfc140
// src: GUESS 0x00dfc140 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc140()
{
    return &DAT_010dff44;
}

namespace fnv_00dfc150 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct BufferBase
{
    virtual ~BufferBase()
    {}
};

struct FUN_00dfc150_cls : public BufferBase
{
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
    void* m_pData2;
    unsigned int m_count2;
    unsigned int m_cap2;
    void* m_pData1;
    unsigned int m_count1;
    unsigned int m_cap1;

    void FreeOwnedBuffersAndDestroyBase();
};

// Frees both owned buffers through the global allocator, resets their data pointers, counts and capacities, then destroys the base object.
// @fnv 0x00dfc150
// src: GUESS 0x00dfc150 (confidence: medium)
void FUN_00dfc150_cls::FreeOwnedBuffersAndDestroyBase()
{
    hkMemoryRouter* h = hkMemoryRouter_getInstance();
    Allocator* alloc = reinterpret_cast<Allocator*>(h->m_heap);
    unsigned int cap = m_cap1;
    m_count1 = 0;
    if ((cap & 0x80000000u) == 0)
    {
        alloc->Free(m_pData1, cap & 0x3fffffffu);
    }
    m_pData1 = 0;
    m_cap1 = 0x80000000u;

    h = hkMemoryRouter_getInstance();
    alloc = reinterpret_cast<Allocator*>(h->m_heap);
    cap = m_cap2;
    m_count2 = 0;
    if ((cap & 0x80000000u) == 0)
    {
        alloc->Free(m_pData2, (cap & 0x3fffffffu) * 40);
    }
    m_pData2 = 0;
    unsigned int* puiCapacity2 = &m_cap2;
    *puiCapacity2 = 0x80000000u;
    this->BufferBase::~BufferBase();
}
}  // namespace fnv_00dfc150

extern unsigned char DAT_0126b420;

// @fnv 0x00dfc220
// src: GUESS 0x00dfc220 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfc220()
{
    return &DAT_0126b420;
}

namespace fnv_00dfc240 {
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00dfc240
// src: GUESS 0x00dfc240 (confidence: low)
GlobalObject* __cdecl Object_GetGlobalObjectAddress_00dfc240()
{
    return &g_global;
}
}  // namespace fnv_00dfc240

extern char DAT_0126b498;
// @fnv 0x00dfc260
// src: GUESS 0x00dfc260 (confidence: low)
char* __cdecl Object_GetGlobalObjectAddress_00dfc260()
{
    return &DAT_0126b498;
}

extern int DAT_010e00cc;

// @fnv 0x00dfc290
// src: GUESS 0x00dfc290 (confidence: low)
void* Runtime_GetDAT010e00ccAddress()
{
    return &DAT_010e00cc;
}

extern int DAT_010e00dc;

// @fnv 0x00dfc2b0
// src: GUESS 0x00dfc2b0 (confidence: low)
int* __cdecl Runtime_GetDAT010e00dcAddress()
{
    return &DAT_010e00dc;
}

// FUN_00dfc360: cdecl no-arg getter returning the address of a global.
extern int DAT_0126b528;

// @fnv 0x00dfc360
// src: GUESS 0x00dfc360 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc360()
{
    return &DAT_0126b528;
}

extern int g_unk0126b4e0;

// @fnv 0x00dfc370
// src: GUESS 0x00dfc370 (confidence: low)
void* __cdecl Runtime_GetUnk0126b4e0Address()
{
    return &g_unk0126b4e0;
}

extern void* DAT_0126b558;

// @fnv 0x00dfc390
// src: GUESS 0x00dfc390 (confidence: low)
void* Runtime_GetDAT0126b558Address()
{
    return &DAT_0126b558;
}

struct FUN_00e05c20_class
{
    void __thiscall ReleaseSectorAndSubtrackArrays();
};

// @fnv 0x00dfc3a0
// src: GUESS 0x00dfc3a0 (confidence: low)
void __cdecl Object_ForwardCall_00dfc3a0(FUN_00e05c20_class* p)
{
    p->ReleaseSectorAndSubtrackArrays();
}

struct FUN_00dfc3b0_target
{
    void Run();
};

// @fnv 0x00dfc3b0
// src: GUESS 0x00dfc3b0 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfc3b0(FUN_00dfc3b0_target* pTarget)
{
    pTarget->Run();
}

// FUN_00dfc440 : a one-line function - getter
extern int g_target_00dfc440;
// @fnv 0x00dfc440
// src: GUESS 0x00dfc440 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfc440()
{
    return &g_target_00dfc440;
}

class VirtualDispatchObj
{
  public:
    virtual void Invoke0(int arg);
};

// @fnv 0x00dfc450
// src: GUESS 0x00dfc450 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfc450(VirtualDispatchObj* p)
{
    p->Invoke0(0);
}

extern void* DAT_0126b588;

// @fnv 0x00dfc460
// src: GUESS 0x00dfc460 (confidence: low)
int __cdecl Object_ComputeValue_00dfc460()
{
    return reinterpret_cast<int>(&DAT_0126b588);
}

extern int DAT_010e04ac;

// @fnv 0x00dfc480
// src: GUESS 0x00dfc480 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfc480()
{
    return &DAT_010e04ac;
}

extern int g_unk0126b678;

// @fnv 0x00dfc4d0
// src: GUESS 0x00dfc4d0 (confidence: low)
void* __cdecl Runtime_GetUnk0126b678Address()
{
    return &g_unk0126b678;
}

extern int DAT_0126b648;

// @fnv 0x00dfc4f0
// src: GUESS 0x00dfc4f0 (confidence: low)
int* __cdecl Runtime_GetDAT0126b648Address()
{
    return &DAT_0126b648;
}

extern int DAT_0126b600;

// @fnv 0x00dfc510
// src: GUESS 0x00dfc510 (confidence: low)
int* __cdecl Runtime_GetDAT0126b600Address()
{
    return &DAT_0126b600;
}

extern int DAT_010e0654;

// @fnv 0x00dfc530
// src: GUESS 0x00dfc530 (confidence: low)
int* __cdecl Runtime_GetDAT010e0654Address()
{
    return &DAT_010e0654;
}

extern int DAT_0126b6a8;

// @fnv 0x00dfc590
// src: GUESS 0x00dfc590 (confidence: low)
int* __cdecl Runtime_GetDAT0126b6a8Address(void)
{
    return &DAT_0126b6a8;
}

// FUN_00dfc5b0 : a one-line function - getter
extern int g_target_00dfc5b0;
// @fnv 0x00dfc5b0
// src: GUESS 0x00dfc5b0 (confidence: low)
void* Runtime_GetTarget00dfc5b0Address()
{
    return &g_target_00dfc5b0;
}

extern int DAT_0126b708;

// @fnv 0x00dfc5d0
// src: GUESS 0x00dfc5d0 (confidence: low)
int* __cdecl Runtime_GetDAT0126b708Address()
{
    return &DAT_0126b708;
}

extern int DAT_0126b738;

// @fnv 0x00dfc5f0
// src: GUESS 0x00dfc5f0 (confidence: low)
void* __cdecl Runtime_GetDAT0126b738Address()
{
    return &DAT_0126b738;
}

struct FUN_00dfc600_vt
{
    virtual void __thiscall m0(int);
};
// @fnv 0x00dfc600
// src: GUESS 0x00dfc600 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfc600(FUN_00dfc600_vt* p)
{
    p->m0(0);
}

extern unsigned char DAT_0126b768;

// @fnv 0x00dfc610
// src: GUESS 0x00dfc610 (confidence: low)
void* __cdecl Runtime_GetDAT0126b768Address()
{
    return &DAT_0126b768;
}

extern int DAT_0102e368;

// @fnv 0x00dfc630
// src: GUESS 0x00dfc630 (confidence: low)
int* __cdecl Runtime_GetDAT0102e368Address()
{
    return &DAT_0102e368;
}

extern int DAT_0126b7b0;

// @fnv 0x00dfc660
// src: GUESS 0x00dfc660 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc660()
{
    return &DAT_0126b7b0;
}

// FUN_00dfc680 : a one-line function - getter
extern int g_target_00dfc680;
// @fnv 0x00dfc680
// src: GUESS 0x00dfc680 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfc680()
{
    return &g_target_00dfc680;
}

struct FUN_00dfc690_vt
{
    virtual void m0(int);
};

// @fnv 0x00dfc690
// src: GUESS 0x00dfc690 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfc690(FUN_00dfc690_vt* p)
{
    p->m0(0);
}

extern int DAT_0126b810;

// @fnv 0x00dfc6a0
// src: GUESS 0x00dfc6a0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfc6a0()
{
    return &DAT_0126b810;
}

extern int DAT_010d0a64;

// @fnv 0x00dfc6d0
// src: GUESS 0x00dfc6d0 (confidence: low)
int* __cdecl Runtime_GetDAT010d0a64Address()
{
    return &DAT_010d0a64;
}

extern char DAT_0126b858;

// @fnv 0x00dfc6f0
// src: GUESS 0x00dfc6f0 (confidence: low)
void* Runtime_GetDAT0126b858Address()
{
    return &DAT_0126b858;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126b888;
// @fnv 0x00dfc710
// src: GUESS 0x00dfc710 (confidence: low)
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField0126b888Address()
{
    return &g_0126b888;
}

extern int DAT_010d0aac;

// @fnv 0x00dfc740
// src: GUESS 0x00dfc740 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc740()
{
    return &DAT_010d0aac;
}

extern int g_unk0126b8d0;

// @fnv 0x00dfc760
// src: GUESS 0x00dfc760 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc760()
{
    return &g_unk0126b8d0;
}

namespace fnv_00dfc770 {
struct Handler_cls
{
    void __thiscall Handle(int value);
};

// @fnv 0x00dfc770
// src: GUESS 0x00dfc770 (confidence: low)
void __cdecl Runtime_ProcessState_00dfc770(Handler_cls* pHandler, int value)
{
    if (pHandler != 0)
        pHandler->Handle(value);
}
}  // namespace fnv_00dfc770

extern int g_0126b900;

// @fnv 0x00dfc7c0
// src: GUESS 0x00dfc7c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc7c0()
{
    return &g_0126b900;
}

extern int DAT_0126b948;

// @fnv 0x00dfc7e0
// src: GUESS 0x00dfc7e0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc7e0()
{
    return &DAT_0126b948;
}

extern int DAT_0126b978;

// @fnv 0x00dfc800
// src: GUESS 0x00dfc800 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfc800()
{
    return &DAT_0126b978;
}

class DFC810Object
{
  public:
    void Process(void* pvData);
};

// @fnv 0x00dfc810
// src: GUESS 0x00dfc810 (confidence: low)
void __cdecl Runtime_ProcessState_00dfc810(DFC810Object* pkObject, void* pvData)
{
    if (pkObject)
        pkObject->Process(pvData);
}

class SpawnedBase
{
  public:
    virtual ~SpawnedBase();
    virtual void Tick();
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
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    SpawnedBase(int a);
};

class SpawnedMid
{
  public:
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    SpawnedMid()
    {
        *(volatile int*)&m_8c = 0;
        *(volatile int*)&m_90 = 0;
        *(volatile int*)&m_94 = (int)0x80000000;
        *(volatile int*)&m_98 = 0;
        *(volatile int*)&m_9c = 0;
        *(volatile int*)&m_a0 = (int)0x80000000;
    }
};

class FUN_00dfc850 : public SpawnedBase, public SpawnedMid
{
  public:
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    int m_e0;
    int m_e4;
    int m_e8;
    int m_ec;
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fc;
    int m_100;
    int m_104;
    int m_108;
    int m_10c;
    int m_110;
    int m_114;
    int m_118;
    int m_11c;
    int m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    int m_138;
    int m_13c;
    int m_140;
    int m_144;
    int m_148;
    int m_14c;
    int m_150;
    int m_154;
    int m_158;
    int m_15c;
    int m_160;
    int m_164;
    int m_168;
    virtual ~FUN_00dfc850();
    FUN_00dfc850(int a1);
};

// @fnv 0x00dfc850
FUN_00dfc850::FUN_00dfc850(int aiValue) : SpawnedBase(aiValue)
{
    *(volatile int*)&m_160 = 0;
    *(volatile int*)&m_164 = 0;
    *(volatile int*)&m_168 = (int)0x80000000;
}

extern int DAT_0126b9c0;

// @fnv 0x00dfc8c0
// src: GUESS 0x00dfc8c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc8c0()
{
    return &DAT_0126b9c0;
}

extern int g_unk0126b9f0;

// @fnv 0x00dfc8e0
// src: GUESS 0x00dfc8e0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc8e0()
{
    return &g_unk0126b9f0;
}

extern int DAT_010e11ec;
// @fnv 0x00dfc910
// src: GUESS 0x00dfc910 (confidence: low)
int* __cdecl Runtime_GetDAT010e11ecAddress()
{
    return &DAT_010e11ec;
}

extern int g_0126ba38;

// @fnv 0x00dfc930
// src: GUESS 0x00dfc930 (confidence: low)
int* __cdecl Runtime_GetField0126ba38Address()
{
    return &g_0126ba38;
}

struct FUN_00dfc940_class
{
    virtual void m0(int);
};

// @fnv 0x00dfc940
// src: GUESS 0x00dfc940 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfc940(FUN_00dfc940_class* p)
{
    p->m0(0);
}

extern int DAT_0126ba68;

// @fnv 0x00dfc950
// src: GUESS 0x00dfc950 (confidence: low)
void* __cdecl Runtime_GetDAT0126ba68Address()
{
    return &DAT_0126ba68;
}

extern int DAT_010d0af4;

struct S_00dfc970_Flag
{
    char v;
    S_00dfc970_Flag(char c)
    {
        v = c;
    }
    S_00dfc970_Flag(const S_00dfc970_Flag& o)
    {
        v = o.v;
    }
};

struct S_00dfc970_Obj
{
    void* vptr;
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
    short unk98;
    char unk9a;
    void hkpRagdollLimitsData_setConeLimitStabilization(S_00dfc970_Flag f);
};

// Sets the object's vtable pointer and, when flag and unk9a are set, calls FUN_00d4f270 with a flag value of 1.
// @fnv 0x00dfc970
// src: HAVOK_LIB 0x00dfc970
void __cdecl finishLoadedObjecthkpRagdollLimitsData(S_00dfc970_Obj* pObj, int flag)
{
    if (pObj)
    {
        pObj->vptr = &DAT_010d0af4;
        if (flag && pObj->unk9a)
        {
            pObj->hkpRagdollLimitsData_setConeLimitStabilization(S_00dfc970_Flag(1));
        }
    }
}

extern int DAT_010d0af4;

// @fnv 0x00dfc9a0
// src: GUESS 0x00dfc9a0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc9a0()
{
    return &DAT_010d0af4;
}

extern int DAT_0126bab0;

// @fnv 0x00dfc9c0
// src: GUESS 0x00dfc9c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc9c0()
{
    return &DAT_0126bab0;
}

class DFC9D0Object
{
  public:
    virtual ~DFC9D0Object();
};

// @fnv 0x00dfc9d0
// src: GUESS 0x00dfc9d0 (confidence: low)
void Runtime_DestroySubobject_00dfc9d0(DFC9D0Object* pkObject)
{
    pkObject->~DFC9D0Object();
}

extern int DAT_0126bae0;

// @fnv 0x00dfc9e0
// src: GUESS 0x00dfc9e0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfc9e0()
{
    return &DAT_0126bae0;
}

extern int DAT_010cb71c;

// @fnv 0x00dfca30
// src: GUESS 0x00dfca30 (confidence: low)
void* __cdecl Runtime_GetDAT010cb71cAddress()
{
    return &DAT_010cb71c;
}

extern int DAT_0126bb28;

// @fnv 0x00dfca50
// src: GUESS 0x00dfca50 (confidence: low)
void* __cdecl Runtime_GetDAT0126bb28Address()
{
    return &DAT_0126bb28;
}

class DFCA60Object
{
  public:
    virtual ~DFCA60Object();
};

// @fnv 0x00dfca60
// src: GUESS 0x00dfca60 (confidence: low)
void Object_InvokeVirtualMethod_00dfca60(DFCA60Object* pkObject)
{
    pkObject->~DFCA60Object();
}

extern char g_unk0126bb58;

// @fnv 0x00dfca70
// src: GUESS 0x00dfca70 (confidence: low)
void* __cdecl Runtime_GetUnk0126bb58Address()
{
    return &g_unk0126bb58;
}

extern int DAT_010da04c;

// @fnv 0x00dfcaa0
// src: GUESS 0x00dfcaa0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfcaa0()
{
    return &DAT_010da04c;
}

extern int DAT_0126bba0;

// @fnv 0x00dfcac0
// src: GUESS 0x00dfcac0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfcac0()
{
    return &DAT_0126bba0;
}

extern void* DAT_0126bbd0;

// @fnv 0x00dfcae0
// src: GUESS 0x00dfcae0 (confidence: low)
int __cdecl Object_ComputeValue_00dfcae0()
{
    return reinterpret_cast<int>(&DAT_0126bbd0);
}

extern int DAT_010d0b3c;
// @fnv 0x00dfcb10
// src: GUESS 0x00dfcb10 (confidence: low)
int* __cdecl Runtime_GetDAT010d0b3cAddress()
{
    return &DAT_010d0b3c;
}

extern int DAT_0126bc18;
// @fnv 0x00dfcb30
// src: GUESS 0x00dfcb30 (confidence: low)
void* __cdecl Runtime_GetDAT0126bc18Address()
{
    return &DAT_0126bc18;
}

namespace fnv_00dfcb40 {
struct Handler_cls
{
    void __thiscall Handle(int value);
};

// @fnv 0x00dfcb40
// src: GUESS 0x00dfcb40 (confidence: low)
void __cdecl Object_ProcessState_00dfcb40(Handler_cls* pHandler, int value)
{
    if (pHandler != 0)
        pHandler->Handle(value);
}
}  // namespace fnv_00dfcb40

extern int DAT_0126bc48;
// @fnv 0x00dfcb90
// src: GUESS 0x00dfcb90 (confidence: low)
int* __cdecl Runtime_GetDAT0126bc48Address()
{
    return &DAT_0126bc48;
}

extern int DAT_0126bc90;

// @fnv 0x00dfcbb0
// src: GUESS 0x00dfcbb0 (confidence: low)
int* __cdecl Runtime_GetDAT0126bc90Address()
{
    return &DAT_0126bc90;
}

// Stand-in for the object whose virtual slot 0 is invoked with argument 0.
struct FUN_00dfcbc0_vt
{
    virtual void m0(int a);
};

// Calls the first virtual of the object passed in as the only argument.
// @fnv 0x00dfcbc0
// src: GUESS 0x00dfcbc0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfcbc0(FUN_00dfcbc0_vt* pObject)
{
    pObject->m0(0);
}

extern int DAT_0126bcc0;

// @fnv 0x00dfcbd0
// src: GUESS 0x00dfcbd0 (confidence: low)
void* __cdecl Runtime_GetDAT0126bcc0Address()
{
    return &DAT_0126bcc0;
}

extern void* DAT_010d37e4;
// @fnv 0x00dfcc00
// src: GUESS 0x00dfcc00 (confidence: low)
void** __cdecl Object_GetGlobalObjectAddress_00dfcc00()
{
    return &DAT_010d37e4;
}

// FUN_00dfcc20 : a one-line function - getter
extern int g_target_00dfcc20;
// @fnv 0x00dfcc20
// src: GUESS 0x00dfcc20 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfcc20()
{
    return &g_target_00dfcc20;
}

struct S_00dfcc40_Obj
{
    int unk00;
};
extern S_00dfcc40_Obj DAT_0126bd38;
// @fnv 0x00dfcc40
// src: GUESS 0x00dfcc40 (confidence: low)
S_00dfcc40_Obj* __cdecl Object_GetGlobalObjectAddress_00dfcc40()
{
    return &DAT_0126bd38;
}

// FUN_00dfcc70 : a one-line function - getter
extern int g_target_00dfcc70;
// @fnv 0x00dfcc70
// src: GUESS 0x00dfcc70 (confidence: low)
void* Runtime_GetTarget00dfcc70Address()
{
    return &g_target_00dfcc70;
}

extern int DAT_0126bd80;

// @fnv 0x00dfcc90
// src: GUESS 0x00dfcc90 (confidence: low)
int* __cdecl Runtime_GetDAT0126bd80Address()
{
    return &DAT_0126bd80;
}

// Forwarder: takes the object pointer, calls its first virtual slot with a
// literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00dfcca0
// src: GUESS 0x00dfcca0 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00dfcca0(VtblForwarder* p)
{
    return p->v0(0);
}

// FUN_00dfccb0 : a one-line function - getter
extern int g_target_00dfccb0;
// @fnv 0x00dfccb0
// src: GUESS 0x00dfccb0 (confidence: low)
void* Runtime_GetTarget00dfccb0Address()
{
    return &g_target_00dfccb0;
}

extern int DAT_010d0be4;

// @fnv 0x00dfcce0
// src: GUESS 0x00dfcce0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfcce0()
{
    return &DAT_010d0be4;
}

extern int DAT_0126bdf8;

// @fnv 0x00dfcd00
// src: GUESS 0x00dfcd00 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfcd00()
{
    return &DAT_0126bdf8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126be28;
// @fnv 0x00dfcd20
// src: GUESS 0x00dfcd20 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfcd20()
{
    return &DAT_0126be28;
}

extern int DAT_010c91ec;

// @fnv 0x00dfcd50
// src: GUESS 0x00dfcd50 (confidence: low)
int* Runtime_GetDAT010c91ecAddress()
{
    return &DAT_010c91ec;
}

extern int DAT_0126be70;

// @fnv 0x00dfcd70
// src: GUESS 0x00dfcd70 (confidence: low)
int* __cdecl Runtime_GetDAT0126be70Address()
{
    return &DAT_0126be70;
}

extern int DAT_0126bea0;

// @fnv 0x00dfcda0
// src: GUESS 0x00dfcda0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfcda0()
{
    return &DAT_0126bea0;
}

struct FUN_00dfcdb0_target
{
    void Run();
};

// @fnv 0x00dfcdb0
// src: GUESS 0x00dfcdb0 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfcdb0(FUN_00dfcdb0_target* pTarget)
{
    pTarget->Run();
}

extern char DAT_0126bed0;

// @fnv 0x00dfcdd0
// src: GUESS 0x00dfcdd0 (confidence: low)
void* __cdecl Runtime_GetDAT0126bed0Address()
{
    return &DAT_0126bed0;
}

struct DFD5E0
{
    void __thiscall FUN_00d53df0(void* p);
};
// @fnv 0x00dfcde0
// src: GUESS 0x00dfcde0 (confidence: low)
void __cdecl Object_ProcessState_00dfcde0(void* pTarget, void* b)
{
    if (pTarget != 0)
    {
        ((DFD5E0*)pTarget)->FUN_00d53df0(b);
    }
}

extern int DAT_0126bf00;

// @fnv 0x00dfce30
// src: GUESS 0x00dfce30 (confidence: low)
void* __cdecl Runtime_GetDAT0126bf00Address()
{
    return &DAT_0126bf00;
}

extern int DAT_0126bf48;

// @fnv 0x00dfce50
// src: GUESS 0x00dfce50 (confidence: low)
int* __cdecl Runtime_GetDAT0126bf48Address()
{
    return &DAT_0126bf48;
}

namespace fnv_00dfce60 {
// Forwarder: takes the object pointer from the stack, then calls its first
// virtual slot with a literal 0 argument (push 0; call through the vtable entry).
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00dfce60
// src: GUESS 0x00dfce60 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00dfce60(VtblForwarder* p)
{
    return p->v0(0);
}
}  // namespace fnv_00dfce60

extern int DAT_0126bf78;

// @fnv 0x00dfce70
// src: GUESS 0x00dfce70 (confidence: low)
void* __cdecl Runtime_GetDAT0126bf78Address()
{
    return &DAT_0126bf78;
}

extern int DAT_010d0cd4;
// @fnv 0x00dfcea0
// src: GUESS 0x00dfcea0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfcea0()
{
    return &DAT_010d0cd4;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126bfc0;
// @fnv 0x00dfcec0
// src: GUESS 0x00dfcec0 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfcec0()
{
    return &DAT_0126bfc0;
}

extern int DAT_0126bff0;

// @fnv 0x00dfcef0
// src: GUESS 0x00dfcef0 (confidence: low)
void* __cdecl Runtime_GetDAT0126bff0Address()
{
    return &DAT_0126bff0;
}

extern int DAT_0126c020;

// @fnv 0x00dfcf10
// src: GUESS 0x00dfcf10 (confidence: low)
void* __cdecl Runtime_GetDAT0126c020Address()
{
    return &DAT_0126c020;
}

struct FUN_00dfcf20_cls
{
    void __thiscall InitializeVtables(int a);
};

// @fnv 0x00dfcf20
// src: GUESS 0x00dfcf20 (confidence: low)
void __cdecl Object_ProcessState_00dfcf20(FUN_00dfcf20_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->InitializeVtables(aiValue);
    }
}

extern "C" void* DAT_010305a8;
extern "C" void* DAT_010c6fb0;
extern "C" void* DAT_010cc364;
extern "C" void* DAT_010cc344;
extern "C" void* DAT_010e2144;
extern "C" void* DAT_010e2124;

struct FUN_00dfcf60_cls
{
    void* m_vptr00;
    int m_04;
    int m_08;
    int m_0c;
    void* m_vptr10;
    char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;

    FUN_00dfcf60_cls* InitializeVtables(int flag);
};

// @fnv 0x00dfcf60
FUN_00dfcf60_cls* FUN_00dfcf60_cls::InitializeVtables(int flag)
{
    *(void* volatile*)&m_vptr00 = (void*)&DAT_010305a8;
    if (flag != 0)
    {
        *(int volatile*)&m_0c = 0;
    }
    *(void* volatile*)&m_vptr10 = (void*)&DAT_010c6fb0;
    *(void* volatile*)&m_vptr00 = (void*)&DAT_010cc364;
    *(void* volatile*)&m_vptr10 = (void*)&DAT_010cc344;
    if (flag != 0)
    {
        *(int volatile*)&m_0c = 7;
        *(unsigned char volatile*)&m_15 = 3;
    }
    *(void* volatile*)&m_vptr00 = (void*)&DAT_010e2144;
    *(void* volatile*)&m_vptr10 = (void*)&DAT_010e2124;
    if (flag != 0)
    {
        *(int volatile*)&m_0c = 0x17;
        *(unsigned char volatile*)&m_15 = 4;
    }
    return this;
}

extern int DAT_0126c068;

// @fnv 0x00dfd0c0
// src: GUESS 0x00dfd0c0 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfd0c0()
{
    return &DAT_0126c068;
}

struct FUN_00dfd0d0_cls
{
    virtual void Call(int a);
};

// @fnv 0x00dfd0d0
// src: GUESS 0x00dfd0d0 (confidence: low)
void Runtime_ForwardCall_00dfd0d0(FUN_00dfd0d0_cls* pTarget)
{
    pTarget->Call(0);
}

extern int DAT_0126c098;

// @fnv 0x00dfd0e0
// src: GUESS 0x00dfd0e0 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfd0e0()
{
    return &DAT_0126c098;
}

extern "C" void* DAT_010e222c;

// @fnv 0x00dfd120
// src: GUESS 0x00dfd120 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfd120()
{
    return &DAT_010e222c;
}

namespace fnv_00dfd130 {
extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfd130_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int m_08;
    int m_0c;
    void* m_pData;
    int m_14;
    int m_uiItemCount;

    FUN_00dfd130_cls* FUN_00dfd130(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Frees the data array through the audio allocator, resets the object's fields and vtable, and frees the object itself when acFlags bit 0 is set.
// @fnv 0x00dfd130
FUN_00dfd130_cls* FUN_00dfd130_cls::FUN_00dfd130(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    int count = m_uiItemCount;
    m_14 = 0;
    if (((unsigned int)count & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData, (count & 0x3fffffff) * 32);
    }
    m_pData = 0;
    m_uiItemCount = 0x80000000;
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
        pAllocator2->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00dfd130

extern unsigned char DAT_0126c0e0;
// @fnv 0x00dfd1b0
// src: GUESS 0x00dfd1b0 (confidence: low)
unsigned char* __cdecl Runtime_GetDAT0126c0e0Address()
{
    return &DAT_0126c0e0;
}

// @fnv 0x00dfd1c0
// src: GUESS 0x00dfd1c0 (confidence: low)
void __cdecl Object_ProcessAndTransformResult_00dfd1c0(void* p)
{
    (*(void(__thiscall**)(void*, int)) * (int*)p)(p, 0);
}

extern int DAT_0126c110;

// @fnv 0x00dfd1d0
// src: GUESS 0x00dfd1d0 (confidence: low)
void* __cdecl Runtime_GetDAT0126c110Address()
{
    return &DAT_0126c110;
}

// FUN_00dfd1e0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfd1e0_cls
{
  public:
    void Forward(int a1);
};

// @fnv 0x00dfd1e0
// src: GUESS 0x00dfd1e0 (confidence: low)
void __cdecl Object_ProcessState_00dfd1e0(FUN_00dfd1e0_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->Forward(aiValue);
    }
}

extern int DAT_0126c158;

// @fnv 0x00dfd230
// src: GUESS 0x00dfd230 (confidence: low)
int* __cdecl Runtime_GetDAT0126c158Address()
{
    return &DAT_0126c158;
}

// FUN_00dfd250 : a one-line function - getter
extern int g_target_00dfd250;
// @fnv 0x00dfd250
// src: GUESS 0x00dfd250 (confidence: low)
void* Runtime_GetTarget00dfd250Address()
{
    return &g_target_00dfd250;
}

struct S_00dfd260_Foo
{
    void __thiscall FUN_00d59830(int arg);
};

// @fnv 0x00dfd260
// src: GUESS 0x00dfd260 (confidence: low)
void __cdecl Object_ProcessState_00dfd260(S_00dfd260_Foo* pFoo, int arg)
{
    if (pFoo)
    {
        pFoo->FUN_00d59830(arg);
    }
}

extern int DAT_0126c1d0;

// @fnv 0x00dfd2a0
// src: GUESS 0x00dfd2a0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfd2a0()
{
    return &DAT_0126c1d0;
}

extern int DAT_0126c200;

// @fnv 0x00dfd2c0
// src: GUESS 0x00dfd2c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfd2c0()
{
    return &DAT_0126c200;
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126c230;
// @fnv 0x00dfd2d0
// src: GUESS 0x00dfd2d0 (confidence: low)
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField0126c230Address()
{
    return &g_0126c230;
}

struct FUN_00dfd2e0_Class
{
    virtual void VF00(int value);
};

// @fnv 0x00dfd2e0
// src: GUESS 0x00dfd2e0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfd2e0(FUN_00dfd2e0_Class* param_1)
{
    param_1->VF00(0);
}

// FUN_00dfd2f0 : a one-line function - getter
extern int g_target_00dfd2f0;
// @fnv 0x00dfd2f0
// src: GUESS 0x00dfd2f0 (confidence: low)
void* Runtime_GetTarget00dfd2f0Address()
{
    return &g_target_00dfd2f0;
}

struct FUN_00e3dbd0_class
{
    void __thiscall FUN_00e3dbd0(int value);
};

// @fnv 0x00dfd300
// src: GUESS 0x00dfd300 (confidence: low)
void __cdecl Object_ProcessState_00dfd300(FUN_00e3dbd0_class* object, int value)
{
    if (object != 0)
        object->FUN_00e3dbd0(value);
}

struct FUN_00dfd380_Class
{
    void __thiscall ReleaseFourArrays();
};

// @fnv 0x00dfd360
// src: GUESS 0x00dfd360 (confidence: low)
void __cdecl Object_ForwardCall_00dfd360(int* param_1)
{
    reinterpret_cast<FUN_00dfd380_Class*>(param_1)->ReleaseFourArrays();
}

struct FnvCpu_FUN_00dfd370_CpuTarget
{
    void ReleaseThreeArrays();
};
// @fnv 0x00dfd370
// src: GUESS 0x00dfd370 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfd370(FnvCpu_FUN_00dfd370_CpuTarget* target)
{
    target->ReleaseThreeArrays();
}

// FUN_00dfd4e0 : a one-line function - getter
extern int g_target_00dfd4e0;
// @fnv 0x00dfd4e0
// src: GUESS 0x00dfd4e0 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfd4e0()
{
    return &g_target_00dfd4e0;
}

extern int DAT_0126c2d8;

// @fnv 0x00dfd500
// src: GUESS 0x00dfd500 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfd500()
{
    return &DAT_0126c2d8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126c308;
// @fnv 0x00dfd540
// src: GUESS 0x00dfd540 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfd540()
{
    return &DAT_0126c308;
}

extern int DAT_0126c338;

// @fnv 0x00dfd560
// src: GUESS 0x00dfd560 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfd560()
{
    return &DAT_0126c338;
}

// FUN_00dfd570: null-guarded forwarder. The first argument (an object
// pointer) is loaded and tested; when it is not null the second argument
// is passed on to a non-virtual member function of that object.
class FUN_00dfd570_cls
{
  public:
    void ReturnSelf(int a1);
};

// @fnv 0x00dfd570
// src: GUESS 0x00dfd570 (confidence: low)
void __cdecl Object_ProcessState_00dfd570(FUN_00dfd570_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->ReturnSelf(aiValue);
    }
}

extern int DAT_0126c368;

// @fnv 0x00dfd590
// src: GUESS 0x00dfd590 (confidence: low)
int* __cdecl Runtime_GetDAT0126c368Address()
{
    return &DAT_0126c368;
}

namespace fnv_00dfd5a0 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct FUN_00dfd5a0_cls
{
    void* m_pData;
    int m_04;
    unsigned int m_08;
};

// @fnv 0x00dfd5a0
void __cdecl ClearAndFreeData(FUN_00dfd5a0_cls* obj)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    Allocator* alloc = reinterpret_cast<Allocator*>(holder->m_heap);
    unsigned int flags = obj->m_08;
    obj->m_04 = 0;
    if ((flags & 0x80000000u) == 0)
    {
        alloc->Free(obj->m_pData, (flags & 0x3fffffffu) * 12);
    }
    *(volatile unsigned int*)&obj->m_08 = 0x80000000u;
    *(void* volatile*)&obj->m_pData = 0;
}
}  // namespace fnv_00dfd5a0

extern int DAT_0126c398;

// @fnv 0x00dfd5f0
// src: GUESS 0x00dfd5f0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfd5f0()
{
    return reinterpret_cast<int>(&DAT_0126c398);
}

class FUN_00dfd600_cls
{
  public:
    void Callee(unsigned int value);
};

// @fnv 0x00dfd600
// src: GUESS 0x00dfd600 (confidence: low)
void __cdecl Object_ProcessState_00dfd600(FUN_00dfd600_cls* target, unsigned int value)
{
    if (target != 0)
    {
        target->Callee(value);
    }
}

// FUN_00dfd650 : a one-line function - getter
extern int g_target_00dfd650;
// @fnv 0x00dfd650
// src: GUESS 0x00dfd650 (confidence: low)
void* Runtime_GetTarget00dfd650Address()
{
    return &g_target_00dfd650;
}

extern int DAT_0126c410;

// @fnv 0x00dfd790
// src: GUESS 0x00dfd790 (confidence: low)
int* __cdecl Runtime_GetDAT0126c410Address()
{
    return &DAT_0126c410;
}

extern int DAT_0126c440;

// @fnv 0x00dfd7b0
// src: GUESS 0x00dfd7b0 (confidence: low)
void* __cdecl Runtime_GetDAT0126c440Address()
{
    return &DAT_0126c440;
}

extern int DAT_0126c488;

// @fnv 0x00dfd930
// src: GUESS 0x00dfd930 (confidence: low)
void* __cdecl Runtime_GetDAT0126c488Address()
{
    return &DAT_0126c488;
}

extern int DAT_0126c4b8;

// @fnv 0x00dfd950
// src: GUESS 0x00dfd950 (confidence: low)
int* __cdecl Runtime_GetDAT0126c4b8Address()
{
    return &DAT_0126c4b8;
}

extern int DAT_010e33dc;
struct FUN_00dfd990_class
{
    void* vtable;
    int field04;
    int field08;
    int field0c;
    int field10;
    FUN_00cb0a70_class field14;
};
// @fnv 0x00dfd990
// src: GUESS 0x00dfd990 (confidence: low)
void __cdecl Runtime_SetVtableAndProcessState_00dfd990(FUN_00dfd990_class* object, int value)
{
    if (object)
    {
        object->vtable = &DAT_010e33dc;
        object->field14.ReturnSelf(value);
    }
}

extern int DAT_0126c500;

// @fnv 0x00dfda40
// src: GUESS 0x00dfda40 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfda40()
{
    return &DAT_0126c500;
}

struct S_00e3f510_Foo
{
    void __thiscall SetVptr_00e3f510(int);
};

// @fnv 0x00dfda50
// src: GUESS 0x00dfda50 (confidence: low)
void __cdecl Object_ProcessState_00dfda50(void* pObject, int aiValue)
{
    if (pObject)
    {
        ((S_00e3f510_Foo*)pObject)->SetVptr_00e3f510(aiValue);
    }
}

extern int DAT_0126c530;

// @fnv 0x00dfdaa0
// src: GUESS 0x00dfdaa0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfdaa0()
{
    return &DAT_0126c530;
}

struct AdjacentObjects
{
    FUN_00cb0c00_class first;
    __declspec(align(4)) FUN_00cb0c00_class second;
};

// @fnv 0x00dfdab0
// src: GUESS 0x00dfdab0 (confidence: low)
void __cdecl Runtime_ProcessState_00dfdab0(AdjacentObjects* objects)
{
    objects->second.Object_UpdateFields_00cb0c00();
    objects->first.Object_UpdateFields_00cb0c00();
}

extern int DAT_0126c578;

// @fnv 0x00dfdaf0
// src: GUESS 0x00dfdaf0 (confidence: low)
void* __cdecl Runtime_GetDAT0126c578Address()
{
    return &DAT_0126c578;
}

// FUN_00dfdb10 : a one-line function - getter
extern int g_target_00dfdb10;
// @fnv 0x00dfdb10
// src: GUESS 0x00dfdb10 (confidence: low)
void* Runtime_GetTarget00dfdb10Address()
{
    return &g_target_00dfdb10;
}

extern int DAT_0126c5f0;

// @fnv 0x00dfdb30
// src: GUESS 0x00dfdb30 (confidence: low)
void* __cdecl Runtime_GetDAT0126c5f0Address()
{
    return &DAT_0126c5f0;
}

extern int DAT_010e351c;
// @fnv 0x00dfdb60
// src: GUESS 0x00dfdb60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfdb60()
{
    return &DAT_010e351c;
}

extern "C" void* DAT_010e352c;

// @fnv 0x00dfdb80
// src: GUESS 0x00dfdb80 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfdb80()
{
    return &DAT_010e352c;
}

extern int DAT_0126c638;

// @fnv 0x00dfdd20
// src: GUESS 0x00dfdd20 (confidence: low)
int* Object_GetGlobalObjectAddress_00dfdd20()
{
    return &DAT_0126c638;
}

extern int DAT_0126c668;

// @fnv 0x00dfdd80
// src: GUESS 0x00dfdd80 (confidence: low)
int __cdecl Object_ComputeValue_00dfdd80()
{
    return reinterpret_cast<int>(&DAT_0126c668);
}

extern int DAT_0126c698;

// @fnv 0x00dfddc0
// src: GUESS 0x00dfddc0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfddc0()
{
    return &DAT_0126c698;
}

extern int DAT_0126c6c8;

// @fnv 0x00dfdde0
// src: GUESS 0x00dfdde0 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfdde0()
{
    return &DAT_0126c6c8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126c6f8;
// @fnv 0x00dfde00
// src: GUESS 0x00dfde00 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfde00()
{
    return &DAT_0126c6f8;
}

struct FUN_00dfde10_vtable
{
    virtual void __thiscall slot0(int value)
    {}
};

// @fnv 0x00dfde10
// src: GUESS 0x00dfde10 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfde10(void* p)
{
    reinterpret_cast<FUN_00dfde10_vtable*>(p)->slot0(0);
}

extern int DAT_0126c728;

// @fnv 0x00dfde20
// src: GUESS 0x00dfde20 (confidence: low)
int __cdecl Object_ComputeValue_00dfde20()
{
    return reinterpret_cast<int>(&DAT_0126c728);
}

extern int DAT_010d3cc0;
// @fnv 0x00dfde50
// src: GUESS 0x00dfde50 (confidence: low)
int* __cdecl Runtime_GetDAT010d3cc0Address()
{
    return &DAT_010d3cc0;
}

extern char DAT_0126c770;
// @fnv 0x00dfde70
// src: GUESS 0x00dfde70 (confidence: low)
char* __cdecl Runtime_GetDAT0126c770Address(void)
{
    return &DAT_0126c770;
}

extern int DAT_0126c7a0;

// @fnv 0x00dfde90
// src: GUESS 0x00dfde90 (confidence: low)
void* __cdecl Runtime_GetDAT0126c7a0Address()
{
    return &DAT_0126c7a0;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126c7d0;
// @fnv 0x00dfdeb0
// src: GUESS 0x00dfdeb0 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126c7d0Address()
{
    return &DAT_0126c7d0;
}

// FUN_00dfdec0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdec0_cls
{
  public:
    void hkMonitorStreamStringMap_StringMap_StringMap(int a1);
};

// @fnv 0x00dfdec0
// src: GUESS 0x00dfdec0 (confidence: low)
void __cdecl Object_ProcessState_00dfdec0(FUN_00dfdec0_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->hkMonitorStreamStringMap_StringMap_StringMap(aiValue);
    }
}

extern unsigned char DAT_0126c800;

// @fnv 0x00dfdee0
// src: GUESS 0x00dfdee0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfdee0()
{
    return &DAT_0126c800;
}

// FUN_00dfdef0: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00dfdef0_cls
{
  public:
    void GetSelf_00e0f700(int a1);
};

// @fnv 0x00dfdef0
// src: GUESS 0x00dfdef0 (confidence: low)
void __cdecl Object_ProcessState_00dfdef0(FUN_00dfdef0_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->GetSelf_00e0f700(aiValue);
    }
}

extern int g_unk0126c830;

// @fnv 0x00dfdf10
// src: GUESS 0x00dfdf10 (confidence: low)
void* __cdecl Runtime_GetUnk0126c830Address()
{
    return &g_unk0126c830;
}

extern int DAT_0126c860;

// @fnv 0x00dfdf30
// src: GUESS 0x00dfdf30 (confidence: low)
int* __cdecl Runtime_GetDAT0126c860Address()
{
    return &DAT_0126c860;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126c890;
// @fnv 0x00dfdf40
// src: GUESS 0x00dfdf40 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfdf40()
{
    return &DAT_0126c890;
}

class DFDF50Object
{
  public:
    virtual ~DFDF50Object();
};

// @fnv 0x00dfdf50
// src: GUESS 0x00dfdf50 (confidence: low)
void __cdecl Runtime_DestroySubobject_00dfdf50(DFDF50Object* pkObject)
{
    pkObject->~DFDF50Object();
}

extern int DAT_0126c8c0;

// @fnv 0x00dfdf60
// src: GUESS 0x00dfdf60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfdf60()
{
    return &DAT_0126c8c0;
}

extern int DAT_010e3e5c;

// @fnv 0x00dfdfc0
// src: GUESS 0x00dfdfc0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfdfc0()
{
    return &DAT_010e3e5c;
}

struct FUN_00ddc870_class
{
    void __thiscall ProcessEntries_00ddc870();
};

// @fnv 0x00dfdfd0
// src: GUESS 0x00dfdfd0 (confidence: low)
void __cdecl Object_ForwardCall_00dfdfd0(FUN_00ddc870_class* self)
{
    self->ProcessEntries_00ddc870();
}

namespace fnv_00dfdfe0 {
struct EngineHeap
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual void Unknown3();
    virtual void Free(void* memory, unsigned int bytes);
};
struct EngineMemoryManager
{
    void* unknown00;
    void* unknown04;
    void* unknown08;
    void* unknown0C;
    EngineHeap* heap;
};
EngineMemoryManager* __cdecl hkMemoryRouter_getInstance();
struct ArrayEntry
{
    unsigned int index;
    unsigned int value;
};
struct ArrayBase
{
    virtual void UnknownVirtual();
    unsigned int unknown04;
    ~ArrayBase()
    {}
};
struct ArrayStorage
{
    ArrayEntry* entries;
    int length;
    int allocationFlags;
    __forceinline void Reset(EngineHeap* heap)
    {
        ArrayEntry* current = entries;
        if (length > 0)
        {
            int remaining = length;
            do
            {
                reinterpret_cast<FUN_00cb0c00_class*>(current)->Object_UpdateFields_00cb0c00();
                ++current;
            } while (--remaining != 0);
        }
        length = 0;
        if (!(allocationFlags & 0x80000000))
            heap->Free(entries, (allocationFlags & 0x3fffffff) * sizeof(ArrayEntry));
        entries = 0;
        allocationFlags = 0x80000000;
    }
};
struct ArrayContainer : ArrayBase
{
    ArrayStorage contents;
    void ResetAndDestroy();
};
// Resets the contents array using the engine heap, then destroys the ArrayBase subobject.
// @fnv 0x00dfdfe0
void ArrayContainer::ResetAndDestroy()
{
    EngineHeap* heap = hkMemoryRouter_getInstance()->heap;
    contents.Reset(heap);
    ArrayBase::~ArrayBase();
}
}  // namespace fnv_00dfdfe0

extern int DAT_0126c908;

// @fnv 0x00dfe090
// src: GUESS 0x00dfe090 (confidence: low)
int* __cdecl Runtime_GetDAT0126c908Address()
{
    return &DAT_0126c908;
}

extern int DAT_0126c938;

// @fnv 0x00dfe0a0
// src: GUESS 0x00dfe0a0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe0a0()
{
    return &DAT_0126c938;
}

extern int DAT_0126c968;

// @fnv 0x00dfe0e0
// src: GUESS 0x00dfe0e0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe0e0()
{
    return &DAT_0126c968;
}

extern int DAT_0126c998;

// @fnv 0x00dfe100
// src: GUESS 0x00dfe100 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe100()
{
    return &DAT_0126c998;
}

// FUN_00dfe120 : a one-line function - getter
extern int g_target_00dfe120;
// @fnv 0x00dfe120
// src: GUESS 0x00dfe120 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfe120()
{
    return &g_target_00dfe120;
}

extern int DAT_0126c9f8;

// @fnv 0x00dfe140
// src: GUESS 0x00dfe140 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe140()
{
    return &DAT_0126c9f8;
}

// FUN_00dfe160 : a one-line function - getter
extern int g_target_00dfe160;
// @fnv 0x00dfe160
// src: GUESS 0x00dfe160 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfe160()
{
    return &g_target_00dfe160;
}

extern int DAT_0126ca58;

// @fnv 0x00dfe180
// src: GUESS 0x00dfe180 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfe180()
{
    return &DAT_0126ca58;
}

extern int DAT_0126ca88;

// @fnv 0x00dfe1a0
// src: GUESS 0x00dfe1a0 (confidence: low)
int __cdecl Object_ComputeValue_00dfe1a0()
{
    return reinterpret_cast<int>(&DAT_0126ca88);
}

extern int DAT_0126cab8;

// @fnv 0x00dfe1c0
// src: GUESS 0x00dfe1c0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfe1c0()
{
    return &DAT_0126cab8;
}

extern int DAT_0126cae8;

// @fnv 0x00dfe1e0
// src: GUESS 0x00dfe1e0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe1e0()
{
    return &DAT_0126cae8;
}

extern int DAT_0126cb18;

// @fnv 0x00dfe1f0
// src: GUESS 0x00dfe1f0 (confidence: low)
void* __cdecl Runtime_GetDAT0126cb18Address()
{
    return &DAT_0126cb18;
}

namespace fnv_00dfe210 {

extern hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

// @fnv 0x00dfe210
void __cdecl ClearArray(int* array)
{
    hkMemoryRouter* manager = hkMemoryRouter_getInstance();
    Allocator* allocator = reinterpret_cast<Allocator*>(manager->m_heap);
    int capacity = array[2];

    array[1] = 0;
    if ((capacity & 0x80000000) == 0)
        allocator->Free((void*)array[0], (unsigned int)(capacity & 0x3fffffff) * 4);

    ((volatile int*)array)[2] = 0x80000000;
    ((volatile int*)array)[0] = 0;
}
}  // namespace fnv_00dfe210

// FUN_00dfe250: null-guarded forwarding of a second argument to a
// non-virtual member function of the first (object) argument.
class FUN_00dfe250_cls
{
  public:
    void Forward(int a1);
};

// @fnv 0x00dfe250
// src: GUESS 0x00dfe250 (confidence: low)
void __cdecl Object_ProcessState_00dfe250(FUN_00dfe250_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->Forward(aiValue);
    }
}

// FUN_00dfe2a0: cdecl, returns the address of a global object.
extern char g_unk0126cb48;

// @fnv 0x00dfe2a0
// src: GUESS 0x00dfe2a0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe2a0()
{
    return &g_unk0126cb48;
}

extern void* DAT_0126cb90;

// @fnv 0x00dfe2c0
// src: GUESS 0x00dfe2c0 (confidence: low)
int __cdecl Object_ComputeValue_00dfe2c0()
{
    return reinterpret_cast<int>(&DAT_0126cb90);
}

// FUN_00dfe330 : a one-line function - getter
extern int g_target_00dfe330;
// @fnv 0x00dfe330
// src: GUESS 0x00dfe330 (confidence: low)
void* Runtime_GetTarget00dfe330Address()
{
    return &g_target_00dfe330;
}

extern int DAT_010e5474;

// @fnv 0x00dfe350
// src: GUESS 0x00dfe350 (confidence: low)
unsigned int __cdecl Runtime_EvaluateValue_00dfe350()
{
    return reinterpret_cast<unsigned int>(&DAT_010e5474);
}

// Helper object whose virtual-like member performs the work.
struct FUN_00cb0a70_obj
{
    void __thiscall m_00cb0a70(int value);
};

// @fnv 0x00dfe410
// src: GUESS 0x00dfe410 (confidence: low)
void __cdecl Object_ProcessState_00dfe410(FUN_00cb0a70_obj* pObject, int value)
{
    if (pObject)
    {
        pObject->m_00cb0a70(value);
    }
}

// FUN_00dfe460 : a one-line function - getter
extern int g_target_00dfe460;
// @fnv 0x00dfe460
// src: GUESS 0x00dfe460 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfe460()
{
    return &g_target_00dfe460;
}

// @fnv 0x00dfe470
// src: GUESS 0x00dfe470 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfe470(FUN_00dfe430_class* p)
{
    p->ReturnSelf(0);
}

extern int DAT_0126cc68;

// @fnv 0x00dfe480
// src: GUESS 0x00dfe480 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe480()
{
    return &DAT_0126cc68;
}

// FUN_00dfe4f0: cdecl, returns the address of a global object.
extern char g_unk0126ccb0;

// @fnv 0x00dfe4f0
// src: GUESS 0x00dfe4f0 (confidence: low)
void* __cdecl Runtime_GetUnk0126ccb0Address()
{
    return &g_unk0126ccb0;
}

extern int DAT_010e57a4;

// @fnv 0x00dfe510
// src: GUESS 0x00dfe510 (confidence: low)
int* Runtime_GetDAT010e57a4Address()
{
    return &DAT_010e57a4;
}

// FUN_00dfe5a0: cdecl, returns the address of a global object.
extern char g_unk0126ccf8;

// @fnv 0x00dfe5a0
// src: GUESS 0x00dfe5a0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe5a0()
{
    return &g_unk0126ccf8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126cd40;
// @fnv 0x00dfe680
// src: GUESS 0x00dfe680 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00dfe680()
{
    return &DAT_0126cd40;
}

extern int DAT_010e58c8;
// @fnv 0x00dfe6a0
// src: GUESS 0x00dfe6a0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfe6a0()
{
    return &DAT_010e58c8;
}

struct FUN_00dfe6e0_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00dfe6e0
// src: GUESS 0x00dfe6e0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfe6e0(FUN_00dfe6e0_Class* param_1)
{
    param_1->vf00(0);
}

extern unsigned char DAT_0126cd88;

// @fnv 0x00dfe6f0
// src: GUESS 0x00dfe6f0 (confidence: low)
void* __cdecl Runtime_GetDAT0126cd88Address()
{
    return &DAT_0126cd88;
}

extern int DAT_010e59ac;

// @fnv 0x00dfe710
// src: GUESS 0x00dfe710 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfe710()
{
    return reinterpret_cast<int>(&DAT_010e59ac);
}

struct FUN_00dfe970_class
{
    virtual void __thiscall m_iWordAt00(int);
};

// @fnv 0x00dfe970
// src: GUESS 0x00dfe970 (confidence: low)
void __cdecl Runtime_ForwardCall_00dfe970(FUN_00dfe970_class* p)
{
    p->m_iWordAt00(0);
}

extern int g_unk0126cdd0;

// @fnv 0x00dfe980
// src: GUESS 0x00dfe980 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfe980()
{
    return &g_unk0126cdd0;
}

extern int DAT_0126ce18;

// @fnv 0x00dfeab0
// src: GUESS 0x00dfeab0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfeab0()
{
    return reinterpret_cast<int>(&DAT_0126ce18);
}

extern int DAT_010dec04;
extern int DAT_010e5ae4;
extern int DAT_010c925c;
extern int DAT_010debf4;
extern int DAT_010debe4;

// @fnv 0x00dfeac0
void __cdecl InitObjectVtables(int* pObject, int bFlag)
{
    if (pObject == 0)
        return;

    volatile int* vp = (volatile int*)pObject;

    *vp = (int)&DAT_010dec04;

    if (bFlag != 0)
        ((unsigned char*)pObject)[9] = 0;

    *vp = (int)&DAT_010e5ae4;
    *(volatile int*)((unsigned char*)pObject + 0x1c) = (int)&DAT_010c925c;
    *(int*)((unsigned char*)pObject + 0x14) = (int)&DAT_010debf4;
    *(volatile int*)((unsigned char*)pObject + 0x1c) = (int)&DAT_010debe4;

    if (bFlag != 0)
        ((unsigned char*)pObject)[9] = 1;
}

extern int DAT_010e5ae4;
// @fnv 0x00dfeb00
// src: GUESS 0x00dfeb00 (confidence: low)
int* Object_GetGlobalObjectAddress_00dfeb00()
{
    return &DAT_010e5ae4;
}

extern int DAT_0126ce60;

// @fnv 0x00dfeb50
// src: GUESS 0x00dfeb50 (confidence: low)
int* __cdecl Runtime_GetDAT0126ce60Address()
{
    return &DAT_0126ce60;
}

extern int DAT_010e5b68;

// @fnv 0x00dfeb70
// src: GUESS 0x00dfeb70 (confidence: low)
int* __cdecl Runtime_GetDAT010e5b68Address()
{
    return &DAT_010e5b68;
}

namespace fnv_00dfeb80 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00dfeb80_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00e42740();
    FnvCpu_FUN_00dfeb80_CpuObject* FUN_00dfeb80(unsigned int flags);
};
// Calls FUN_00e42740, and if bit 0 of flags is set, frees this through the allocator using size, then returns this.
// @fnv 0x00dfeb80
FnvCpu_FUN_00dfeb80_CpuObject* FnvCpu_FUN_00dfeb80_CpuObject::FUN_00dfeb80(unsigned int flags)
{
    FUN_00e42740();
    if (flags & 1)
    {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00dfeb80

extern int DAT_0126cea8;

// @fnv 0x00dfebc0
// src: GUESS 0x00dfebc0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfebc0()
{
    return &DAT_0126cea8;
}

extern int DAT_010e5b4c;
// @fnv 0x00dfebe0
// src: GUESS 0x00dfebe0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfebe0()
{
    return &DAT_010e5b4c;
}

extern int DAT_0126cef0;

// Returns the address of a global object (mov eax, offset global; ret).
// @fnv 0x00dfec00
// src: GUESS 0x00dfec00 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfec00()
{
    return &DAT_0126cef0;
}

extern int DAT_010e5bfc;

// @fnv 0x00dfec20
// src: GUESS 0x00dfec20 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfec20()
{
    return &DAT_010e5bfc;
}

// FUN_00dfec40 : a constant getter - MSVC emits mov eax, OFFSET <global> ; ret.
// The global is declared extern so the store becomes a relocation; the checker
// binds it to the original's own immediate.
extern int g_target_FUN_00dfec40;

// @fnv 0x00dfec40
// src: GUESS 0x00dfec40 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfec40()
{
    return &g_target_FUN_00dfec40;
}

class DFEC50Object
{
  public:
    virtual ~DFEC50Object();
};

// @fnv 0x00dfec50
// src: GUESS 0x00dfec50 (confidence: low)
void __cdecl Runtime_DestroySubobject_00dfec50(DFEC50Object* pkObject)
{
    pkObject->~DFEC50Object();
}

// FUN_00dfec60 : a one-line function - getter
extern int g_target_00dfec60;
// @fnv 0x00dfec60
// src: GUESS 0x00dfec60 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfec60()
{
    return &g_target_00dfec60;
}

// FUN_00dfec80: cdecl, returns the address of a global data symbol.
extern int DAT_010e5d94;

// @fnv 0x00dfec80
// src: GUESS 0x00dfec80 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfec80()
{
    return &DAT_010e5d94;
}

extern int DAT_010e5da8;

// @fnv 0x00dfeca0
// src: GUESS 0x00dfeca0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfeca0()
{
    return &DAT_010e5da8;
}

extern int DAT_0126cfc8;

// @fnv 0x00dfecc0
// src: GUESS 0x00dfecc0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfecc0()
{
    return &DAT_0126cfc8;
}

extern int DAT_010e5e9c;

// @fnv 0x00dfece0
// src: GUESS 0x00dfece0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dfece0()
{
    return &DAT_010e5e9c;
}

// FUN_00dfed00 : a one-line function - getter
extern int g_target_00dfed00;
// @fnv 0x00dfed00
// src: GUESS 0x00dfed00 (confidence: low)
void* Object_GetGlobalObjectAddress_00dfed00()
{
    return &g_target_00dfed00;
}

// @fnv 0x00dfed20
// src: GUESS 0x00dfed20 (confidence: low)
int* Object_GetGlobalObjectAddress_00dfed20()
{
    return &DAT_010e5ff4;
}

extern int DAT_0126d058;

// @fnv 0x00dfedf0
// src: GUESS 0x00dfedf0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfedf0()
{
    return reinterpret_cast<int>(&DAT_0126d058);
}

extern int DAT_010e60c4;

// @fnv 0x00dfee10
// src: GUESS 0x00dfee10 (confidence: low)
int* __cdecl Runtime_GetDAT010e60c4Address()
{
    return &DAT_010e60c4;
}

extern int DAT_0126d0a0;

// @fnv 0x00dfee90
// src: GUESS 0x00dfee90 (confidence: low)
int* __cdecl Runtime_GetDAT0126d0a0Address()
{
    return &DAT_0126d0a0;
}

extern int DAT_010e62a4;

// @fnv 0x00dfeeb0
// src: GUESS 0x00dfeeb0 (confidence: low)
void* __cdecl Runtime_GetDAT010e62a4Address()
{
    return &DAT_010e62a4;
}

extern int DAT_0126d0e8;

// @fnv 0x00dfeed0
// src: GUESS 0x00dfeed0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfeed0()
{
    return reinterpret_cast<int>(&DAT_0126d0e8);
}

extern int DAT_010e6394;

// @fnv 0x00dfeef0
// src: GUESS 0x00dfeef0 (confidence: low)
int* __cdecl Runtime_GetDAT010e6394Address()
{
    return &DAT_010e6394;
}

extern int DAT_0126d130;

// @fnv 0x00dfef10
// src: GUESS 0x00dfef10 (confidence: low)
void* __cdecl Runtime_GetDAT0126d130Address()
{
    return &DAT_0126d130;
}

namespace fnv_00dfef20 {
struct HavokObject
{
    void* volatile primaryVtable;
    unsigned int referenceCount;
    void* volatile secondaryVtable;
};
extern unsigned char DAT_010c925c;
extern unsigned char DAT_010debf4;
extern unsigned char DAT_010debe4;

// @fnv 0x00dfef20
void __cdecl ResetVtables(HavokObject* object)
{
    if (object)
    {
        object->secondaryVtable = &DAT_010c925c;
        object->primaryVtable = &DAT_010debf4;
        object->secondaryVtable = &DAT_010debe4;
    }
}
}  // namespace fnv_00dfef20

extern int DAT_010debf4;

// @fnv 0x00dfef40
// src: GUESS 0x00dfef40 (confidence: low)
int __cdecl Object_ComputeValue_00dfef40()
{
    return reinterpret_cast<int>(&DAT_010debf4);
}

class DFEF80Object
{
  public:
    virtual ~DFEF80Object();
};

// @fnv 0x00dfef80
// src: GUESS 0x00dfef80 (confidence: low)
void Object_InvokeVirtualMethod_00dfef80(DFEF80Object* pkObject)
{
    pkObject->~DFEF80Object();
}

// FUN_00dfefc0: returns the address of the global object at DAT_0126d190.
extern int DAT_0126d190;

// @fnv 0x00dfefc0
// src: GUESS 0x00dfefc0 (confidence: low)
int* Object_GetGlobalObjectAddress_00dfefc0()
{
    return &DAT_0126d190;
}

// FUN_00dfefd0 : cdecl, 13 bytes
// Calls slot 0 of the object's vtable with the argument 0 and returns the result.

struct FUN_00dfefd0_cls
{
    virtual int v00(int a);
};

// @fnv 0x00dfefd0
// src: GUESS 0x00dfefd0 (confidence: low)
int __cdecl Runtime_ForwardCall_00dfefd0(FUN_00dfefd0_cls* pObj)
{
    return pObj->v00(0);
}

extern int DAT_0126d1d8;

// @fnv 0x00dfefe0
// src: GUESS 0x00dfefe0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dfefe0()
{
    return &DAT_0126d1d8;
}

extern int DAT_010e66fc;

// @fnv 0x00dff000
// src: GUESS 0x00dff000 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dff000()
{
    return &DAT_010e66fc;
}

struct FUN_00dff0b0_class
{
    virtual void m0(int);
};

// @fnv 0x00dff0b0
// src: GUESS 0x00dff0b0 (confidence: low)
void __cdecl Runtime_ForwardCall_00dff0b0(FUN_00dff0b0_class* p)
{
    p->m0(0);
}

extern int DAT_0126d220;

// @fnv 0x00dff0c0
// src: GUESS 0x00dff0c0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dff0c0()
{
    return &DAT_0126d220;
}

extern int DAT_010e676c;

// @fnv 0x00dff0e0
// src: GUESS 0x00dff0e0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dff0e0()
{
    return &DAT_010e676c;
}

struct FUN_00dff120_Class
{
    virtual void vf00(int value);
};

// @fnv 0x00dff120
// src: GUESS 0x00dff120 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dff120(FUN_00dff120_Class* param_1)
{
    param_1->vf00(0);
}

// Getter returning the address of a global object.
extern int DAT_0126d268;

// @fnv 0x00dff160
// src: GUESS 0x00dff160 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dff160()
{
    return &DAT_0126d268;
}

// Null-guarded forwarder: the first argument is an object pointer; when it is
// non-null the second argument is passed to a member function of that object.
struct FUN_00dff170_cls
{
    void __thiscall FUN_00e45010(int a1);
};

// @fnv 0x00dff170
// src: GUESS 0x00dff170 (confidence: low)
void __cdecl Object_ProcessState_00dff170(FUN_00dff170_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->FUN_00e45010(aiValue);
    }
}

struct FUN_00dff190_cls
{
    virtual void m_v00(int arg);
};

// @fnv 0x00dff190
// src: GUESS 0x00dff190 (confidence: low)
void __cdecl Object_ForwardCall_00dff190(FUN_00dff190_cls* pObject)
{
    pObject->m_v00(0);
}

extern int DAT_0126d298;

// @fnv 0x00dff1c0
// src: GUESS 0x00dff1c0 (confidence: low)
int __cdecl Object_ComputeValue_00dff1c0()
{
    return reinterpret_cast<int>(&DAT_0126d298);
}

extern int DAT_0126d2f8;

// @fnv 0x00dff1e0
// src: GUESS 0x00dff1e0 (confidence: low)
int __cdecl Object_ComputeValue_00dff1e0()
{
    return reinterpret_cast<int>(&DAT_0126d2f8);
}

struct FUN_00dff250_class
{
    virtual void m0(int);
};

// @fnv 0x00dff250
// src: GUESS 0x00dff250 (confidence: low)
void __cdecl Runtime_ForwardCall_00dff250(FUN_00dff250_class* p)
{
    p->m0(0);
}

extern int DAT_0126d328;

// @fnv 0x00dff260
// src: GUESS 0x00dff260 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dff260()
{
    return &DAT_0126d328;
}

struct DFF2E0FinishFlag
{
    int m_bFinishing;
};

class DFF2E0Object
{
  public:
    DFF2E0Object(DFF2E0FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

// @fnv 0x00dff2e0
// src: GUESS 0x00dff2e0 (confidence: medium)
void Object_ConstructInPlace(void* apMemory, int finishing)
{
    if (apMemory)
    {
        DFF2E0FinishFlag flag;
        flag.m_bFinishing = finishing;
        new (apMemory) DFF2E0Object(flag);
    }
}

extern int DAT_0126d370;

// @fnv 0x00dff330
// src: GUESS 0x00dff330 (confidence: low)
int* __cdecl Runtime_GetDAT0126d370Address()
{
    return &DAT_0126d370;
}

extern int DAT_0126d3d0;

// @fnv 0x00dff3b0
// src: GUESS 0x00dff3b0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dff3b0()
{
    return reinterpret_cast<int>(&DAT_0126d3d0);
}

extern int DAT_0126d418;

// @fnv 0x00dff3d0
// src: GUESS 0x00dff3d0 (confidence: low)
int* __cdecl Runtime_GetDAT0126d418Address()
{
    return &DAT_0126d418;
}

namespace fnv_00dff3e0 {
inline void* operator new(unsigned int, void* where) throw()
{
    return where;
}

class SpawnPrimaryBase
{
  public:
    virtual void v0();
    int m_i04;
};

class SpawnSecondaryBase0
{
  public:
    virtual void v0();
};

class SpawnSecondaryBase1
{
  public:
    virtual void v0();
};

class SpawnSecondaryBase2
{
  public:
    virtual void v0();
};

class SpawnSecondaryBase3
{
  public:
    virtual void v0();
};

class SpawnedObject : public SpawnPrimaryBase,
                      public SpawnSecondaryBase0,
                      public SpawnSecondaryBase1,
                      public SpawnSecondaryBase2,
                      public SpawnSecondaryBase3
{
  public:
    __forceinline SpawnedObject()
    {}
    virtual void v0();
};

// If p is non-null, placement-constructs a SpawnedObject at p.
// @fnv 0x00dff3e0
void __cdecl ConstructSpawnedObject(void* apMemory)
{
    if (apMemory != 0)
    {
        new (apMemory) SpawnedObject();
    }
}
}  // namespace fnv_00dff3e0

struct CpuOpaque;
extern CpuOpaque DAT_010e6dec;
// @fnv 0x00dff430
// src: GUESS 0x00dff430 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT010e6decAddress()
{
    return &DAT_010e6dec;
}

namespace fnv_00dff470 {

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct SpawnedBase0
{
    virtual ~SpawnedBase0()
    {}
    unsigned short m_uSize;
    unsigned short m_u06;
};

struct SpawnedBase1
{
    virtual ~SpawnedBase1()
    {}
};

struct SpawnedBase2
{
    virtual ~SpawnedBase2()
    {}
};

struct SpawnedBase3
{
    virtual ~SpawnedBase3()
    {}
};

struct SpawnedBase4
{
    virtual ~SpawnedBase4()
    {}
};

struct FUN_00dff470_cls : SpawnedBase0, SpawnedBase1, SpawnedBase2, SpawnedBase3, SpawnedBase4
{
    FUN_00dff470_cls* DestroySelf(unsigned char acFlags);
};

// Runs the base-class destructors, then, if acFlags has bit 0 set, frees this object through the audio allocator using m_uSize.
// @fnv 0x00dff470
FUN_00dff470_cls* FUN_00dff470_cls::DestroySelf(unsigned char acFlags)
{
    this->SpawnedBase4::~SpawnedBase4();
    this->SpawnedBase3::~SpawnedBase3();
    this->SpawnedBase2::~SpawnedBase2();
    this->SpawnedBase1::~SpawnedBase1();
    this->SpawnedBase0::~SpawnedBase0();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00dff470

struct FUN_00e46300_class
{
    void __thiscall FUN_00e46300(int);
};

// @fnv 0x00dff4c0
// src: GUESS 0x00dff4c0 (confidence: low)
void __cdecl Object_ProcessState_00dff4c0(FUN_00e46300_class* pObject, int aiValue)
{
    if (pObject)
        pObject->FUN_00e46300(aiValue);
}

struct DFF4E0Object
{
    virtual void Destroy(bool bFree);
};

// @fnv 0x00dff4e0
// src: GUESS 0x00dff4e0 (confidence: medium)
void Object_Destroy_Thunk(DFF4E0Object* pkObject)
{
    pkObject->Destroy(false);
}

extern unsigned char DAT_0126d448;

// @fnv 0x00dff510
// src: GUESS 0x00dff510 (confidence: low)
void* __cdecl Runtime_GetDAT0126d448Address()
{
    return &DAT_0126d448;
}

struct DFF520FinishFlag
{
    int m_bFinishing;
};

class DFF520Object
{
  public:
    DFF520Object(DFF520FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

// @fnv 0x00dff520
// src: GUESS 0x00dff520 (confidence: medium)
void Object_ConstructInPlace_00dff520(void* apMemory, int finishing)
{
    if (apMemory)
    {
        DFF520FinishFlag flag;
        flag.m_bFinishing = finishing;
        new (apMemory) DFF520Object(flag);
    }
}

extern int DAT_0126d490;

// @fnv 0x00dff570
// src: GUESS 0x00dff570 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dff570()
{
    return reinterpret_cast<int>(&DAT_0126d490);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126d4d8;
// @fnv 0x00dff590
// src: GUESS 0x00dff590 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126d4d8Address()
{
    return &DAT_0126d4d8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126d508;
// @fnv 0x00dff5b0
// src: GUESS 0x00dff5b0 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126d508Address()
{
    return &DAT_0126d508;
}

extern int DAT_0126d550;

// @fnv 0x00dff5d0
// src: GUESS 0x00dff5d0 (confidence: low)
void* __cdecl Runtime_GetDAT0126d550Address()
{
    return &DAT_0126d550;
}

extern int DAT_010e75cc;
// @fnv 0x00dff5f0
// src: GUESS 0x00dff5f0 (confidence: low)
int* __cdecl Runtime_GetDAT010e75ccAddress()
{
    return &DAT_010e75cc;
}

extern int DAT_010e75dc;
// @fnv 0x00dff610
// src: GUESS 0x00dff610 (confidence: low)
int* __cdecl Runtime_GetDAT010e75dcAddress()
{
    return &DAT_010e75dc;
}

extern int DAT_010e75ec;

// @fnv 0x00dff630
// src: GUESS 0x00dff630 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dff630()
{
    return reinterpret_cast<int>(&DAT_010e75ec);
}

// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dff870_cls
{
  public:
    virtual int v0(int a) = 0;
};

// Calls the first virtual of the object passed in, with argument 0.
// @fnv 0x00dff870
// src: GUESS 0x00dff870 (confidence: low)
int __cdecl Runtime_ForwardCall_00dff870(FUN_00dff870_cls* p)
{
    return p->v0(0);
}

extern int DAT_0126d5c8;

// @fnv 0x00dff880
// src: GUESS 0x00dff880 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00dff880()
{
    return &DAT_0126d5c8;
}

// FUN_00dff890: forwards a second argument to a method of the first argument
// when that pointer is non-null.
struct FUN_00dff890_cls
{
    void __thiscall InitializeRecordPointers(int a);
};

// @fnv 0x00dff890
// src: GUESS 0x00dff890 (confidence: low)
void __cdecl Object_ProcessState_00dff890(FUN_00dff890_cls* pObject, int aValue)
{
    if (pObject != 0)
        pObject->InitializeRecordPointers(aValue);
}

extern "C" char DAT_010c3b80;
extern "C" char DAT_010c3b98;
extern "C" char DAT_010c3bac;
extern "C" char DAT_010c3b8c;
extern "C" char str_0102f13c[];
extern "C" char DAT_010e7700;
extern "C" char DAT_010e76f4;
extern "C" char DAT_010e76e0;
extern "C" char DAT_010e76d4;
extern "C" char DAT_010e76c8;
extern "C" char DAT_010e76ac;
struct FNVRecordPointers
{
    void* volatile m00;
    void* m04;
    void* volatile m08;
    void* volatile m0c;
    void* volatile m10;
    void* volatile m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    void* volatile m30;
    FNVRecordPointers* __thiscall InitializeRecordPointers(int unused);
};
// Assigns a sequence of global addresses to the record pointer fields m00, m08, m0c, m10, m14 and m30, then returns this.
// @fnv 0x00dff8d0
FNVRecordPointers* __thiscall FNVRecordPointers::InitializeRecordPointers(int unused)
{
    m08 = &DAT_010c3b80;
    m0c = &DAT_010c3b98;
    m10 = &DAT_010c3bac;
    m14 = &DAT_010c3b8c;
    m30 = &str_0102f13c;
    m00 = &DAT_010e7700;
    m08 = &DAT_010e76f4;
    m0c = &DAT_010e76e0;
    m10 = &DAT_010e76d4;
    m14 = &DAT_010e76c8;
    m30 = &DAT_010e76ac;
    return this;
}

extern int DAT_0126d610;

// @fnv 0x00dffa20
// src: GUESS 0x00dffa20 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dffa20()
{
    return &DAT_0126d610;
}

extern int g_unk0126d658;

// @fnv 0x00dffa40
// src: GUESS 0x00dffa40 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00dffa40()
{
    return &g_unk0126d658;
}

// FUN_00dffa50: forwards a value to a helper on the passed-in object
// when that object is present.
struct FUN_00dffa50_cls
{
    void __thiscall FUN_00dffa90(int value);
};

// @fnv 0x00dffa50
// src: GUESS 0x00dffa50 (confidence: low)
void __cdecl Object_ProcessState_00dffa50(FUN_00dffa50_cls* pObject, int value)
{
    if (pObject != 0)
    {
        pObject->FUN_00dffa90(value);
    }
}

struct DFFA90FinishFlag
{
    int m_bFinishing;
};

class DFFA90ReferencedObject
{
  public:
    DFFA90ReferencedObject(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DFFA90ListenerA
{
  public:
    DFFA90ListenerA(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerA();
};

class DFFA90ListenerB
{
  public:
    DFFA90ListenerB(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerB();
};

class DFFA90ListenerC
{
  public:
    DFFA90ListenerC(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerC();
};

class DFFA90ListenerD
{
  public:
    DFFA90ListenerD(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerD();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class DFFA90ListenerE
{
  public:
    DFFA90ListenerE(DFFA90FinishFlag)
    {}
    virtual ~DFFA90ListenerE();
};

class FUN_00dffa90 : public DFFA90ReferencedObject,
                     public DFFA90ListenerA,
                     public DFFA90ListenerB,
                     public DFFA90ListenerC,
                     public DFFA90ListenerD,
                     public DFFA90ListenerE
{
  public:
    FUN_00dffa90(DFFA90FinishFlag flag);
    virtual ~FUN_00dffa90();
};

// Empty constructor that initializes the referenced object and all five listener base classes with the given flag.
// @fnv 0x00dffa90
FUN_00dffa90::FUN_00dffa90(DFFA90FinishFlag flag)
    : DFFA90ReferencedObject(flag), DFFA90ListenerA(flag), DFFA90ListenerB(flag), DFFA90ListenerC(flag),
      DFFA90ListenerD(flag), DFFA90ListenerE(flag)
{}

namespace fnv_00dffb80 {
// Forwarder: calls a handler object with one int argument, but only if the
// handler pointer is non-null.
struct Handler_cls
{
    void __thiscall Handle(int value);
};

// @fnv 0x00dffb80
// src: GUESS 0x00dffb80 (confidence: low)
void __cdecl Object_ProcessState_00dffb80(Handler_cls* pHandler, int value)
{
    if (pHandler != 0)
        pHandler->Handle(value);
}
}  // namespace fnv_00dffb80

class FUN_00dffba0_cls
{
  public:
    virtual void v0(int arg);
};

// @fnv 0x00dffba0
// src: GUESS 0x00dffba0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dffba0(FUN_00dffba0_cls* p)
{
    p->v0(0);
}

extern int DAT_0126d688;

// @fnv 0x00dffbd0
// src: GUESS 0x00dffbd0 (confidence: low)
int* __cdecl Runtime_GetDAT0126d688Address()
{
    return &DAT_0126d688;
}

extern int DAT_0126d6e8;

// @fnv 0x00dffc50
// src: GUESS 0x00dffc50 (confidence: low)
void* __cdecl Runtime_GetDAT0126d6e8Address()
{
    return &DAT_0126d6e8;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126d718;
// @fnv 0x00dffc70
// src: GUESS 0x00dffc70 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126d718Address()
{
    return &DAT_0126d718;
}

extern int DAT_010e7c24;

// @fnv 0x00dffc90
// src: GUESS 0x00dffc90 (confidence: low)
int* __cdecl Runtime_GetDAT010e7c24Address()
{
    return &DAT_010e7c24;
}

extern int DAT_0126d760;

// @fnv 0x00dffd90
// src: GUESS 0x00dffd90 (confidence: low)
void* Runtime_GetDAT0126d760Address()
{
    return &DAT_0126d760;
}

extern int DAT_010cc0d8;
// @fnv 0x00dffdb0
// src: GUESS 0x00dffdb0 (confidence: low)
int* __cdecl Runtime_GetDAT010cc0d8Address()
{
    return &DAT_010cc0d8;
}

// FUN_00dffdd0 : a one-line function - getter
extern int g_target_00dffdd0;
// @fnv 0x00dffdd0
// src: GUESS 0x00dffdd0 (confidence: low)
void* Runtime_GetTarget00dffdd0Address()
{
    return &g_target_00dffdd0;
}

namespace fnv_00dffde0 {
struct SpawnedObject
{
    virtual void Vt0();
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
    unsigned short unk11C;
    short m_11E;
    SpawnedObject(int flag)
    {
        if (flag != 0)
        {
            float one = 1.0f;
            m_11E = (short)(*(int*)&one >> 16);
        }
    }
};

struct SpawnedDerived : SpawnedObject
{
    virtual void Vt1();
    SpawnedDerived(int flag) : SpawnedObject(flag)
    {}
};

inline void* operator new(unsigned int, void* where)
{
    return where;
}

// Placement-constructs a SpawnedDerived at p when p is non-null, forwarding flag to the constructor.
// @fnv 0x00dffde0
void ConstructSpawnedDerived(SpawnedObject* apObject, int flag)
{
    if (apObject != 0)
    {
        new (apObject) SpawnedDerived(flag);
    }
}
}  // namespace fnv_00dffde0

extern int DAT_010c6e34;

// @fnv 0x00dffe10
// src: GUESS 0x00dffe10 (confidence: low)
void* Runtime_GetDAT010c6e34Address()
{
    return &DAT_010c6e34;
}

extern int DAT_0126d7f0;

// @fnv 0x00dffe30
// src: GUESS 0x00dffe30 (confidence: low)
void* __cdecl Runtime_GetDAT0126d7f0Address()
{
    return &DAT_0126d7f0;
}

extern int DAT_010d3838;

// @fnv 0x00dffe50
// src: GUESS 0x00dffe50 (confidence: low)
void* __cdecl Runtime_GetDAT010d3838Address()
{
    return &DAT_010d3838;
}

extern char g_unk0126d838;

// @fnv 0x00dffe70
// src: GUESS 0x00dffe70 (confidence: low)
void* __cdecl Runtime_GetUnk0126d838Address()
{
    return &g_unk0126d838;
}

extern void* DAT_010c59f4;
extern void* DAT_010c6d54;

// @fnv 0x00dffe80
// src: GUESS 0x00dffe80 (confidence: low)
void __cdecl Object_UpdateFields_00dffe80(void* apObject, int b)
{
    if (apObject != 0)
    {
        *reinterpret_cast<int*>(apObject) = reinterpret_cast<int>(&DAT_010c59f4);

        if (b != 0)
        {
            float value = 1.0f;
            int bits = *reinterpret_cast<int*>(&value);
            *reinterpret_cast<unsigned short*>(static_cast<char*>(apObject) + 0x11e) =
                static_cast<unsigned short>(bits >> 16);
        }

        *reinterpret_cast<int*>(apObject) = reinterpret_cast<int>(&DAT_010c6d54);
    }
}

namespace fnv_00dffeb0 {
// FUN_00dffeb0
//
// Returns the address of the shared virtual table located at 0x010C6D54
// (its entries point at the implementation functions 0x00DE10B0, 0x00C90350,
// ... ).  The original code is simply:
//
//     mov eax, offset DAT_010c6d54
//     ret
//
// so the global is declared as an extern and its address is returned.

extern int DAT_010c6d54;

// @fnv 0x00dffeb0
// src: GUESS 0x00dffeb0 (confidence: low)
int* __cdecl Runtime_GetDAT010c6d54Address()
{
    return &DAT_010c6d54;
}
}  // namespace fnv_00dffeb0

// Helper class: the object's first virtual slot takes a single int argument.
class FUN_00dffec0_cls
{
  public:
    virtual int v0(int a) = 0;
};

// Calls the first virtual of the object passed in, with argument 0.
// @fnv 0x00dffec0
// src: GUESS 0x00dffec0 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00dffec0(FUN_00dffec0_cls* p)
{
    return p->v0(0);
}

extern int DAT_0126d880;

// @fnv 0x00dffed0
// src: GUESS 0x00dffed0 (confidence: low)
void* __cdecl Runtime_GetDAT0126d880Address()
{
    return &DAT_0126d880;
}

extern int DAT_010cb798;

// @fnv 0x00dffef0
// src: GUESS 0x00dffef0 (confidence: low)
int* __cdecl Runtime_GetDAT010cb798Address()
{
    return &DAT_010cb798;
}

extern int DAT_0126d8c8;

// @fnv 0x00dfff10
// src: GUESS 0x00dfff10 (confidence: low)
int __cdecl Runtime_EvaluateValue_00dfff10()
{
    return reinterpret_cast<int>(&DAT_0126d8c8);
}

extern int DAT_010da004;

struct SpawnedSub
{
    int unk00;
    int unk04;
    unsigned int unk08;
    void __thiscall Notify(unsigned int value);
};

struct SpawnedObject
{
    int* vptr;
    int unk04;
    int unk08;
    SpawnedSub m_0c;
};

// Sets the object's vtable pointer and, when flag is non-zero, notifies the sub-object with its stored value.
// @fnv 0x00dfff20
void __cdecl InitSpawnedObject(SpawnedObject* pObject, int iNotifyFlag)
{
    if (pObject != 0)
    {
        pObject->vptr = &DAT_010da004;
        SpawnedSub* sub = &pObject->m_0c;
        if (iNotifyFlag != 0)
            sub->Notify(sub->unk08);
    }
}

extern int DAT_010da004;

// @fnv 0x00dfff50
// src: GUESS 0x00dfff50 (confidence: low)
int* __cdecl Runtime_GetDAT010da004Address()
{
    return &DAT_010da004;
}

extern int DAT_0126d910;

// @fnv 0x00dfff70
// src: GUESS 0x00dfff70 (confidence: low)
int* __cdecl Runtime_GetDAT0126d910Address()
{
    return &DAT_0126d910;
}

struct S_00dfff80_Foo
{
    void __thiscall FUN_00cdf760(int a);
};

// @fnv 0x00dfff80
void __cdecl CallFooMethodIfNotNull(S_00dfff80_Foo* pFoo, int aiValue)
{
    if (pFoo != 0)
    {
        pFoo->FUN_00cdf760(aiValue);
    }
}

// FUN_00dfffd0 : a one-line function - getter
extern int g_target_00dfffd0;
// @fnv 0x00dfffd0
// src: GUESS 0x00dfffd0 (confidence: low)
void* Runtime_GetTarget00dfffd0Address()
{
    return &g_target_00dfffd0;
}

extern void* DAT_010e80b4;
// @fnv 0x00dffff0
// src: GUESS 0x00dffff0 (confidence: low)
void** __cdecl Runtime_GetDAT010e80b4Address()
{
    return &DAT_010e80b4;
}

extern "C" __m128 _mm_setzero_ps(void);


class Base_de1210 : public hkReferencedObject
{
  public:
    int m_iUnk08;
    hkMatrix3 m_kRotationMatrix;
    hkVector4 m_kVec40;
    int m_iUnk50;

    Base_de1210()
    {
        m_iUnk08 = 0;
        m_iUnk50 = 3;
        m_kRotationMatrix.setIdentity();
        m_kVec40.setZero4();
    }
    virtual void v00();
};

class FUN_00de1210 : public Base_de1210
{
  public:
    hkVector4 m_kVec60;
    hkVector4 m_kVec70;

    FUN_00de1210();
    virtual void v00();
};

// Initializes the two hkVector4 members m_kVec60 and m_kVec70 to zero.
// @fnv 0x00de1210
FUN_00de1210::FUN_00de1210()
{
    m_kVec60.setZero4();
    m_kVec70.setZero4();
}

class DE1FC0ReferencedObject
{
  public:
    DE1FC0ReferencedObject()
    {
        m_sReferenceCount = 1;
    }
    virtual void vfunc00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DE1FC0Transform : public DE1FC0ReferencedObject
{
  public:
    DE1FC0Transform()
    {
        m_ulUserData = 0;
        m_type = 2;
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }

    int m_ulUserData;
    int unk0C;
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};

class FUN_00de1fc0 : public DE1FC0Transform
{
  public:
    FUN_00de1fc0();
    virtual void vfunc01();

    hkVector4 m_extra;
};

// Constructs the transform, zeroing the extra vector member.
// @fnv 0x00de1fc0
FUN_00de1fc0::FUN_00de1fc0()
{
    m_extra.setZero4();
}

// Return a copy of the stored 4-float value.

class DE5300Object
{
  public:
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
    Vec4 m_kValue;

    Vec4 GetValue() const;
};

// @fnv 0x00de5300
Vec4 DE5300Object::GetValue() const
{
    return m_kValue;
}

struct DE5450Transform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};

class DE5450ReferencedObject
{
  public:
    DE5450ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DE5450Shape : public DE5450ReferencedObject
{
  public:
    DE5450Shape() : m_ulUserData(0), m_type(4)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE5450Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};

class FUN_00de5450 : public DE5450Shape
{
  public:
    FUN_00de5450();
    virtual void unk00();

    hkVector4 m_vecA;
    hkVector4 m_vecB;
    int m_uiItemCount;
    float m_valueA;
    float m_valueB;
};

// @fnv 0x00de5450
FUN_00de5450::FUN_00de5450()
{
    m_valueA = 0.0f;
    m_uiItemCount = 0;
    m_valueB = 0.0f;
    m_vecA.setZero4();
    m_vecB.setZero4();
}

struct Matrix64
{
    // Serialized matrices may be unaligned and are copied as a 64-byte record.
    float values[16];
};
struct Input
{
    int count;
    float a, b;
    // The serialized vector is unaligned at offset 0x0c.
    float vector[4];
    unsigned* values;
    void* source;
    Matrix64* matrices;
    float scale;
    unsigned flags;
};
struct Header
{
    union
    {
        float epsilon;
        unsigned char type;
    };
    unsigned short count, pad06;
    unsigned flags, unk0c, size;
    float scale, a, b;
};
void Object_ProcessEntries_00df19e0(int, hkVector4*, Matrix64*, void*, void*, void*, void*, void*, int);
// @fnv 0x00df21c0
void WriteInputHeader(Input* input, void*, Header** ppCursor)
{
    float a = input->a;
    float b = input->b;
    int count = input->count;
    unsigned* values = input->values;
    Matrix64* matrices = input->matrices;
    unsigned flags = input->flags;
    Header* header = *ppCursor;
    header->flags = flags;
    header->epsilon += 1.1920928955078125e-7;
    unsigned short shortCount = (unsigned short)count;
    header->a = a;
    header->b = b;
    header->size = (shortCount * 0x534 + 0x53) & ~15;
    header->type = 0x1f;
    header->count = shortCount;
    unsigned* dst = (unsigned*)((char*)header + 0x40 + shortCount * 0x4f0);
    for (int i = 0; i < count + 1; ++i)
        *dst++ = *values++;
    Matrix64* matrixDst = (Matrix64*)((char*)header + 0x44 + header->count * 0x4f4);
    for (int j = 0; j < count; ++j)
        *matrixDst++ = *matrices++;
    header->scale = input->scale;
    header->flags = input->flags;
    Object_ProcessEntries_00df19e0(input->count, reinterpret_cast<hkVector4*>(input->vector), input->matrices, (char*)*ppCursor + 0x20,
                 (char*)*ppCursor + 0x20 + count * 0x90, (char*)header + 0x40 + header->count * 0x4f0, input->source,
                 (char*)header + 0x20 + header->count * 0xf0, count * 0x3c0);
    *ppCursor = (Header*)((char*)*ppCursor + header->size);
}

extern "C" const __m128 DAT_011b9490;

// @fnv 0x00df2740
// src: GUESS 0x00df2740 (confidence: low)
extern "C" __m128 __cdecl Object_GetDAT_011b9490_00df2740()
{
    return DAT_011b9490;
}

// which resets the runtime caches and re-links the embedded collidable to its owner.
struct DF6500FinishFlag
{
    int m_bFinishing;
};
struct DF6500Collidable
{
    int m_pCollisionShape;
    char m_type;
    signed char m_iOwnerOffset;
    short m_pad06;
    int m_unk08;
    void SetOwnerPointer(void* owner)
    {
        m_iOwnerOffset = (signed char)((unsigned int)owner - (unsigned int)this);
    }
};
struct DF6500Object
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    DF6500Collidable m_kCollidable;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    short m_unk40;
    short m_unk42;
    int m_unk44;
    int m_unk48;

    DF6500Object(DF6500FinishFlag flag)
    {
        if (flag.m_bFinishing)
        {
            m_unk40 = 0;
            m_unk42 = 0;
            m_unk44 = 0;
            m_unk48 = 0;
            m_unk30 = 0;
            m_unk20 = 1;
            m_kCollidable.SetOwnerPointer(this);
        }
    }
};

// @fnv 0x00df6500
// src: HAVOK_LIB 0x00df6500
void finishLoadedObjecthkpCollidable(void* p, int finishing)
{
    DF6500FinishFlag flag;
    flag.m_bFinishing = finishing;
    new (p) DF6500Object(flag);
}

struct BDFCA00FinishFlag
{
    int m_bFinishing;
};
struct BDFCA00UpdateFlag
{
    BDFCA00UpdateFlag(char cValue) : m_cValue(cValue)
    {}
    BDFCA00UpdateFlag(const BDFCA00UpdateFlag& kOther) : m_cValue(kOther.m_cValue)
    {}

    char m_cValue;
};
class BDFCA00Object
{
  public:
    __forceinline BDFCA00Object(BDFCA00FinishFlag kFlag)
    {
        if (kFlag.m_bFinishing && m_bModifierActive)
        {
            Recalculate(BDFCA00UpdateFlag(1));
        }
    }
    virtual ~BDFCA00Object();

    void Recalculate(BDFCA00UpdateFlag kFlag);

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
    short unk114;
    bool m_bModifierActive;
};
// Placement-constructs a BDFCA00Object at pvObject, passing iFinishing as the finish flag.
// @fnv 0x00dfca00
// src: HAVOK_LIB 0x00dfca00
void __cdecl finishLoadedObjecthkpRagdollConstraintData(void* pvObject, int iFinishing)
{
    if (pvObject)
    {
        BDFCA00FinishFlag kFlag;
        kFlag.m_bFinishing = iFinishing;
        new (pvObject) BDFCA00Object(kFlag);
    }
}

struct FnvCpu_FUN_00de1150_CpuObject
{
    char* EvaluateValue_00de1150();
};
// @fnv 0x00de1150
// src: GUESS 0x00de1150 (confidence: low)
char* FnvCpu_FUN_00de1150_CpuObject::EvaluateValue_00de1150()
{
    return reinterpret_cast<char*>(this) + 96;
}

struct FnvCpu_FUN_00de1160_CpuObject
{
    char* ComputeValue_00de1160();
};
// @fnv 0x00de1160
// src: GUESS 0x00de1160 (confidence: low)
char* FnvCpu_FUN_00de1160_CpuObject::ComputeValue_00de1160()
{
    return reinterpret_cast<char*>(this) + 112;
}

struct FnvCpu_FUN_00de4de0_CpuObject
{
    char* ComputeValue_00de4de0();
};
// @fnv 0x00de4de0
// src: GUESS 0x00de4de0 (confidence: low)
char* FnvCpu_FUN_00de4de0_CpuObject::ComputeValue_00de4de0()
{
    return reinterpret_cast<char*>(this) + 96;
}

// @fnv 0x00de4df0
// src: GUESS 0x00de4df0 (confidence: low)
void* __fastcall Object_EvaluateValue_00de4df0(char* self, int)
{
    return self + 0x70;
}

// @fnv 0x00de8140
// src: COMMUNITY 0x00de8140
void __cdecl nullsub_124()
{}

// @fnv 0x00de8160
// src: COMMUNITY 0x00de8160
void __cdecl nullsub_125()
{}

// @fnv 0x00de8180
// src: COMMUNITY 0x00de8180
void __cdecl nullsub_126(void)
{}

// @fnv 0x00de81c0
// src: COMMUNITY 0x00de81c0
void nullsub_127()
{}

// @fnv 0x00de81e0
// src: COMMUNITY 0x00de81e0
void nullsub_129()
{}

// @fnv 0x00de8200
// src: COMMUNITY 0x00de8200
void __cdecl nullsub_131()
{}

// @fnv 0x00de8220
// src: COMMUNITY 0x00de8220
void nullsub_133()
{}

// @fnv 0x00de8240
// src: COMMUNITY 0x00de8240
void __cdecl nullsub_135()
{}

// @fnv 0x00de8260
// src: COMMUNITY 0x00de8260
void __cdecl nullsub_137()
{}

// @fnv 0x00de8280
// src: COMMUNITY 0x00de8280
void __cdecl nullsub_139()
{}

// @fnv 0x00de82a0
// src: COMMUNITY 0x00de82a0
void __cdecl nullsub_141()
{}

// @fnv 0x00de82c0
// src: COMMUNITY 0x00de82c0
void __cdecl nullsub_143()
{}

// @fnv 0x00de82e0
// src: COMMUNITY 0x00de82e0
void __cdecl nullsub_145()
{}

// @fnv 0x00de8300
// src: COMMUNITY 0x00de8300
void __cdecl nullsub_147()
{}

// @fnv 0x00de8320
// src: COMMUNITY 0x00de8320
void __cdecl nullsub_149()
{}

// @fnv 0x00de8340
// src: COMMUNITY 0x00de8340
void __cdecl nullsub_151()
{}

// @fnv 0x00de8360
// src: COMMUNITY 0x00de8360
void __cdecl nullsub_153()
{}

// @fnv 0x00de8380
// src: COMMUNITY 0x00de8380
void __cdecl nullsub_155(void)
{}

// @fnv 0x00de83a0
// src: COMMUNITY 0x00de83a0
void __cdecl nullsub_157()
{}

// @fnv 0x00de83c0
// src: COMMUNITY 0x00de83c0
void __cdecl nullsub_159()
{}

// @fnv 0x00de83e0
// src: COMMUNITY 0x00de83e0
void nullsub_161()
{}

// @fnv 0x00de8400
// src: COMMUNITY 0x00de8400
void nullsub_163()
{}

// @fnv 0x00de8420
// src: COMMUNITY 0x00de8420
void __cdecl nullsub_165()
{}

// @fnv 0x00de8440
// src: COMMUNITY 0x00de8440
void nullsub_167()
{}

// @fnv 0x00de8460
// src: COMMUNITY 0x00de8460
void nullsub_169()
{}

// @fnv 0x00de8480
// src: COMMUNITY 0x00de8480
void __cdecl nullsub_171()
{}

// @fnv 0x00de84a0
// src: COMMUNITY 0x00de84a0
void nullsub_173()
{}

// @fnv 0x00de84c0
// src: COMMUNITY 0x00de84c0
void __cdecl nullsub_175()
{}

// @fnv 0x00de84e0
// src: COMMUNITY 0x00de84e0
void __cdecl nullsub_177()
{}

// @fnv 0x00de8500
// src: COMMUNITY 0x00de8500
void nullsub_179()
{}

// @fnv 0x00de8520
// src: COMMUNITY 0x00de8520
void nullsub_181()
{}

// @fnv 0x00de8540
// src: COMMUNITY 0x00de8540
void nullsub_123()
{}

// @fnv 0x00de8590
// src: COMMUNITY 0x00de8590
void nullsub_128()
{}

// @fnv 0x00de85a0
// src: COMMUNITY 0x00de85a0
void nullsub_130()
{}

// @fnv 0x00de85b0
// src: COMMUNITY 0x00de85b0
void nullsub_134()
{}

// @fnv 0x00de85c0
// src: COMMUNITY 0x00de85c0
void nullsub_136()
{}

// @fnv 0x00de85d0
// src: COMMUNITY 0x00de85d0
void __cdecl nullsub_138()
{}

// @fnv 0x00de85e0
// src: COMMUNITY 0x00de85e0
void nullsub_140()
{}

// @fnv 0x00de85f0
// src: COMMUNITY 0x00de85f0
void __cdecl nullsub_142()
{}

// @fnv 0x00de8600
// src: COMMUNITY 0x00de8600
void __cdecl nullsub_144(void)
{}

// @fnv 0x00de8610
// src: COMMUNITY 0x00de8610
void __cdecl nullsub_146()
{}

// @fnv 0x00de8620
// src: COMMUNITY 0x00de8620
void __cdecl nullsub_148()
{}

// @fnv 0x00de8630
// src: COMMUNITY 0x00de8630
void __cdecl nullsub_150()
{}

// @fnv 0x00de8640
// src: COMMUNITY 0x00de8640
void __cdecl nullsub_152()
{}

// @fnv 0x00de8650
// src: COMMUNITY 0x00de8650
void __cdecl nullsub_154()
{}

// @fnv 0x00de8660
// src: COMMUNITY 0x00de8660
void __cdecl nullsub_156()
{}

// @fnv 0x00de8670
// src: COMMUNITY 0x00de8670
void nullsub_158()
{}

// @fnv 0x00de8680
// src: COMMUNITY 0x00de8680
void __cdecl nullsub_160()
{}

// @fnv 0x00de8690
// src: COMMUNITY 0x00de8690
void nullsub_162()
{}

// @fnv 0x00de86a0
// src: COMMUNITY 0x00de86a0
void nullsub_164()
{}

// @fnv 0x00de86b0
// src: COMMUNITY 0x00de86b0
void nullsub_166()
{}

// @fnv 0x00de86c0
// src: COMMUNITY 0x00de86c0
void __cdecl nullsub_168()
{}

// @fnv 0x00de86d0
// src: COMMUNITY 0x00de86d0
void nullsub_170()
{}

// @fnv 0x00de86e0
// src: COMMUNITY 0x00de86e0
void __cdecl nullsub_172()
{}

// @fnv 0x00de86f0
// src: COMMUNITY 0x00de86f0
void nullsub_174()
{}

// @fnv 0x00de8700
// src: COMMUNITY 0x00de8700
void __cdecl nullsub_176()
{}

// @fnv 0x00de8710
// src: COMMUNITY 0x00de8710
void nullsub_178()
{}

// @fnv 0x00de8720
// src: COMMUNITY 0x00de8720
void nullsub_180()
{}

// @fnv 0x00de8730
// src: COMMUNITY 0x00de8730
void __cdecl nullsub_132()
{}

// @fnv 0x00de8740
// src: COMMUNITY 0x00de8740
void __cdecl nullsub_182()
{}

// @fnv 0x00de8760
// src: COMMUNITY 0x00de8760
void __cdecl nullsub_183()
{}

struct stub_cls
{
    int unk00;
};

// @fnv 0x00df30c0
// src: GUESS 0x00df30c0 (confidence: low)
static __declspec(noinline) void Object_SetUnk00_00df30c0(stub_cls* self, int v)
{
    self->unk00 = v;
}

extern "C" int stub_val(void);

void stub_caller(stub_cls* self)
{
    Object_SetUnk00_00df30c0(self, stub_val());
}

struct DF30D0Pair
{
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

// @fnv 0x00df30d0
static __declspec(noinline) void CopyPairAtIndex(DF30D0Pair* dst, unsigned int uiIndex, const DF30D0Pair* src)
{
    dst[uiIndex] = *src;
}

void DF30D0Caller(DF30D0Pair* dst, unsigned int idx, const DF30D0Pair* src)
{
    CopyPairAtIndex(dst, idx, src);
}

// @fnv 0x00df3160
// src: XBOX_PDB 0x00df3160
void hkKdTreeBuilderSparseWriter_flush()
{}

// @fnv 0x00df64a0
// src: COMMUNITY 0x00df64a0
void nullsub_184()
{}

// @fnv 0x00df6540
// src: COMMUNITY 0x00df6540
void __cdecl nullsub_185()
{}

struct FUN_00df7210_Inner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m14;
};
struct FUN_00df7210_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00df7210_Inner* m10;
    char* __thiscall hkCpuWorldLinearCastCollector_hasHit(char* out);
};
// @fnv 0x00df7210
// src: HAVOK_LIB 0x00df7210
char* FUN_00df7210_Class::hkCpuWorldLinearCastCollector_hasHit(char* out)
{
    *out = m10->m14 > 0;
    return out;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern unsigned long DAT_0126835c;
extern char DAT_010dba3c[];
extern char DAT_010c41f8[];

struct MonitorStreamKd
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_capacityEnd;
};
struct TimerCommandKd
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};
static inline void TimerCommandKdWrite(const char* name)
{
    MonitorStreamKd* s = (MonitorStreamKd*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_capacityEnd)
    {
        TimerCommandKd* h = (TimerCommandKd*)s->m_kRayEnd;
        h->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
struct KdPair
{
    int m_kPointA;
    int m_kPointB;
};
struct KdJob
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int* m_2c;
    int m_30;
    int m_34;
    KdPair m_38;
};
struct KdQueue
{
    int FinishJob(const KdJob* a, const KdJob* b, int flag);
};
void __cdecl MixChannels(KdPair* p, int a2, int a3, int a4, int a5, int a6, int* out);
// @fnv 0x00df7d60
int __cdecl FinishJobWithPair(KdQueue* queue, KdJob* job)
{
    TimerCommandKdWrite(DAT_010dba3c);
    KdPair pair = job->m_38;
    int out = 0;
    MixChannels(&pair, job->m_24, job->m_28, job->m_30, job->m_20, job->m_34, &out);
    *job->m_2c = out;
    TimerCommandKdWrite(DAT_010c41f8);
    return queue->FinishJob(job, job, 0);
}

struct FnvCpu_FUN_00df8920_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float value;
    float GetValue_00df8920();
};
// @fnv 0x00df8920
// src: GUESS 0x00df8920 (confidence: high)
float FnvCpu_FUN_00df8920_CpuObject::GetValue_00df8920()
{
    return value;
}

// @fnv 0x00df9870
// src: GUESS 0x00df9870 (confidence: high)
void __cdecl Runtime_DoNothing_00df9870()
{}

// @fnv 0x00df9b10
// src: GUESS 0x00df9b10 (confidence: high)
void Runtime_DoNothing_00df9b10()
{}

// @fnv 0x00dfb250
// src: COMMUNITY 0x00dfb250
void __cdecl nullsub_186()
{}

// @fnv 0x00dfb350
// src: COMMUNITY 0x00dfb350
void nullsub_187()
{}

// @fnv 0x00dfb370
// src: COMMUNITY 0x00dfb370
void nullsub_188()
{}

// @fnv 0x00dfb4b0
// src: COMMUNITY 0x00dfb4b0
void nullsub_189()
{}

// @fnv 0x00dfb4c0
// src: COMMUNITY 0x00dfb4c0
void __cdecl nullsub_190()
{}

// @fnv 0x00dfb4e0
// src: COMMUNITY 0x00dfb4e0
void __cdecl nullsub_191()
{}

// @fnv 0x00dfb500
// src: COMMUNITY 0x00dfb500
void __cdecl nullsub_192(void)
{}

// @fnv 0x00dfb520
// src: COMMUNITY 0x00dfb520
void __cdecl nullsub_193()
{}

// @fnv 0x00dfb530
// src: COMMUNITY 0x00dfb530
void nullsub_194()
{}

// @fnv 0x00dfb850
// src: COMMUNITY 0x00dfb850
void __cdecl nullsub_195()
{}

// @fnv 0x00dfb870
// src: COMMUNITY 0x00dfb870
void __cdecl nullsub_196()
{}

// @fnv 0x00dfb910
// src: COMMUNITY 0x00dfb910
void __cdecl nullsub_197()
{}

// @fnv 0x00dfb930
// src: COMMUNITY 0x00dfb930
void nullsub_198(void)
{}

// @fnv 0x00dfb9c0
// src: COMMUNITY 0x00dfb9c0
void __cdecl nullsub_199()
{}

// @fnv 0x00dfbab0
// src: COMMUNITY 0x00dfbab0
void __cdecl nullsub_200()
{}

// @fnv 0x00dfbb00
// src: COMMUNITY 0x00dfbb00
void nullsub_201()
{}

// @fnv 0x00dfbb10
// src: COMMUNITY 0x00dfbb10
void __cdecl nullsub_202()
{}

// @fnv 0x00dfbcb0
// src: COMMUNITY 0x00dfbcb0
void __cdecl nullsub_203()
{}

// @fnv 0x00dfbdb0
// src: COMMUNITY 0x00dfbdb0
void __cdecl nullsub_204()
{}

// @fnv 0x00dfbe80
// src: COMMUNITY 0x00dfbe80
void __cdecl nullsub_205()
{}

// @fnv 0x00dfbea0
// src: COMMUNITY 0x00dfbea0
void nullsub_206()
{}

// @fnv 0x00dfbec0
// src: COMMUNITY 0x00dfbec0
void nullsub_207()
{}

// @fnv 0x00dfbee0
// src: COMMUNITY 0x00dfbee0
void nullsub_209()
{}

// @fnv 0x00dfbf00
// src: COMMUNITY 0x00dfbf00
void __cdecl nullsub_208()
{}

// @fnv 0x00dfbf10
// src: COMMUNITY 0x00dfbf10
void __cdecl nullsub_210()
{}

// @fnv 0x00dfc020
// src: COMMUNITY 0x00dfc020
void nullsub_211()
{}

// @fnv 0x00dfc0f0
// src: COMMUNITY 0x00dfc0f0
void nullsub_212()
{}

// @fnv 0x00dfc210
// src: COMMUNITY 0x00dfc210
void nullsub_214()
{}

// @fnv 0x00dfc270
// src: COMMUNITY 0x00dfc270
void __cdecl nullsub_213()
{}

// @fnv 0x00dfc3c0
// src: COMMUNITY 0x00dfc3c0
void nullsub_215()
{}

// @fnv 0x00dfc3d0
// src: COMMUNITY 0x00dfc3d0
void __cdecl nullsub_216()
{}

// @fnv 0x00dfc430
// src: COMMUNITY 0x00dfc430
void __cdecl nullsub_217(void)
{}

// @fnv 0x00dfc4c0
// src: COMMUNITY 0x00dfc4c0
void __cdecl nullsub_218()
{}

// @fnv 0x00dfc4e0
// src: COMMUNITY 0x00dfc4e0
void __cdecl nullsub_219()
{}

// @fnv 0x00dfc570
// src: COMMUNITY 0x00dfc570
void nullsub_220()
{}

// @fnv 0x00dfc580
// src: COMMUNITY 0x00dfc580
void nullsub_221()
{}

// @fnv 0x00dfc5a0
// src: COMMUNITY 0x00dfc5a0
void __cdecl nullsub_222()
{}

// @fnv 0x00dfc5c0
// src: COMMUNITY 0x00dfc5c0
void nullsub_223()
{}

// @fnv 0x00dfc5e0
// src: COMMUNITY 0x00dfc5e0
void __cdecl nullsub_224()
{}

// @fnv 0x00dfc640
// src: COMMUNITY 0x00dfc640
void nullsub_225()
{}

// @fnv 0x00dfc650
// src: COMMUNITY 0x00dfc650
void __cdecl nullsub_226()
{}

// @fnv 0x00dfc670
// src: COMMUNITY 0x00dfc670
void nullsub_228()
{}

// @fnv 0x00dfc6b0
// src: COMMUNITY 0x00dfc6b0
void nullsub_227()
{}

// @fnv 0x00dfc6e0
// src: COMMUNITY 0x00dfc6e0
void __cdecl nullsub_230()
{}

// @fnv 0x00dfc720
// src: COMMUNITY 0x00dfc720
void __cdecl nullsub_229(void)
{}

// @fnv 0x00dfc750
// src: COMMUNITY 0x00dfc750
void __cdecl nullsub_231()
{}

// @fnv 0x00dfc7d0
// src: COMMUNITY 0x00dfc7d0
void __cdecl nullsub_232()
{}

// @fnv 0x00dfc8b0
// src: COMMUNITY 0x00dfc8b0
void __cdecl nullsub_234()
{}

// @fnv 0x00dfc8f0
// src: COMMUNITY 0x00dfc8f0
void __cdecl nullsub_233()
{}

// @fnv 0x00dfc920
// src: COMMUNITY 0x00dfc920
void nullsub_236()
{}

// @fnv 0x00dfc960
// src: COMMUNITY 0x00dfc960
void nullsub_235()
{}

// @fnv 0x00dfc9b0
// src: COMMUNITY 0x00dfc9b0
void __cdecl nullsub_238()
{}

// @fnv 0x00dfc9f0
// src: COMMUNITY 0x00dfc9f0
void nullsub_237()
{}

// @fnv 0x00dfca40
// src: COMMUNITY 0x00dfca40
void __cdecl nullsub_240()
{}

// @fnv 0x00dfca80
// src: COMMUNITY 0x00dfca80
void __cdecl nullsub_239()
{}

// @fnv 0x00dfcab0
// src: COMMUNITY 0x00dfcab0
void __cdecl nullsub_242()
{}

// @fnv 0x00dfcaf0
// src: COMMUNITY 0x00dfcaf0
void nullsub_241()
{}

// @fnv 0x00dfcb20
// src: COMMUNITY 0x00dfcb20
void __cdecl nullsub_243(void)
{}

// @fnv 0x00dfcba0
// src: COMMUNITY 0x00dfcba0
void nullsub_245()
{}

// @fnv 0x00dfcbe0
// src: COMMUNITY 0x00dfcbe0
void __cdecl nullsub_244()
{}

// @fnv 0x00dfcc10
// src: COMMUNITY 0x00dfcc10
void __cdecl nullsub_247()
{}

// @fnv 0x00dfcc50
// src: COMMUNITY 0x00dfcc50
void __cdecl nullsub_246()
{}

// @fnv 0x00dfcc80
// src: COMMUNITY 0x00dfcc80
void __cdecl nullsub_249()
{}

// @fnv 0x00dfccc0
// src: COMMUNITY 0x00dfccc0
void nullsub_248()
{}

// @fnv 0x00dfccf0
// src: COMMUNITY 0x00dfccf0
void __cdecl nullsub_251()
{}

// @fnv 0x00dfcd30
// src: COMMUNITY 0x00dfcd30
void __cdecl nullsub_250()
{}

// @fnv 0x00dfcd60
// src: COMMUNITY 0x00dfcd60
void nullsub_252()
{}

// @fnv 0x00dfcdc0
// src: COMMUNITY 0x00dfcdc0
void nullsub_253()
{}

// @fnv 0x00dfce40
// src: COMMUNITY 0x00dfce40
void nullsub_255()
{}

// @fnv 0x00dfce80
// src: COMMUNITY 0x00dfce80
void nullsub_254()
{}

// @fnv 0x00dfceb0
// src: COMMUNITY 0x00dfceb0
void __cdecl nullsub_257()
{}

// @fnv 0x00dfced0
// src: COMMUNITY 0x00dfced0
void nullsub_256()
{}

// @fnv 0x00dfcee0
// src: COMMUNITY 0x00dfcee0
void __cdecl nullsub_258()
{}

// @fnv 0x00dfd0b0
// src: COMMUNITY 0x00dfd0b0
void __cdecl nullsub_259()
{}

// @fnv 0x00dfd1a0
// src: COMMUNITY 0x00dfd1a0
void __cdecl nullsub_260()
{}

// @fnv 0x00dfd220
// src: COMMUNITY 0x00dfd220
void __cdecl nullsub_261()
{}

// @fnv 0x00dfd2b0
// src: COMMUNITY 0x00dfd2b0
void __cdecl nullsub_263()
{}

// @fnv 0x00dfd340
// src: COMMUNITY 0x00dfd340
void __cdecl nullsub_262()
{}

// @fnv 0x00dfd350
// src: COMMUNITY 0x00dfd350
void nullsub_264()
{}

// @fnv 0x00dfd4d0
// src: COMMUNITY 0x00dfd4d0
void __cdecl nullsub_265()
{}

// @fnv 0x00dfd4f0
// src: COMMUNITY 0x00dfd4f0
void __cdecl nullsub_267()
{}

// @fnv 0x00dfd510
// src: COMMUNITY 0x00dfd510
void __cdecl nullsub_266()
{}

// @fnv 0x00dfd520
// src: COMMUNITY 0x00dfd520
void __cdecl nullsub_268()
{}

// @fnv 0x00dfd530
// src: COMMUNITY 0x00dfd530
void __cdecl nullsub_269()
{}

// @fnv 0x00dfd550
// src: COMMUNITY 0x00dfd550
void __cdecl nullsub_270()
{}

// @fnv 0x00dfd660
// src: COMMUNITY 0x00dfd660
void __cdecl nullsub_271()
{}

// @fnv 0x00dfd960
// src: COMMUNITY 0x00dfd960
void nullsub_272()
{}

// @fnv 0x00dfddd0
// src: COMMUNITY 0x00dfddd0
void nullsub_274()
{}

// @fnv 0x00dfddf0
// src: COMMUNITY 0x00dfddf0
void nullsub_275()
{}

// @fnv 0x00dfde60
// src: COMMUNITY 0x00dfde60
void __cdecl nullsub_276()
{}

// @fnv 0x00dfde80
// src: COMMUNITY 0x00dfde80
void __cdecl nullsub_277()
{}

// @fnv 0x00dfdea0
// src: COMMUNITY 0x00dfdea0
void __cdecl nullsub_278()
{}

// @fnv 0x00dfdf20
// src: COMMUNITY 0x00dfdf20
void __cdecl nullsub_279()
{}

// @fnv 0x00dfe080
// src: COMMUNITY 0x00dfe080
void __cdecl nullsub_280()
{}

// @fnv 0x00dfe0b0
// src: COMMUNITY 0x00dfe0b0
void __cdecl nullsub_281()
{}

// @fnv 0x00dfe0d0
// src: COMMUNITY 0x00dfe0d0
void __cdecl nullsub_282(void)
{}

// @fnv 0x00dfe0f0
// src: COMMUNITY 0x00dfe0f0
void nullsub_283()
{}

// @fnv 0x00dfe110
// src: COMMUNITY 0x00dfe110
void nullsub_284()
{}

// @fnv 0x00dfe130
// src: COMMUNITY 0x00dfe130
void nullsub_285()
{}

// @fnv 0x00dfe150
// src: COMMUNITY 0x00dfe150
void nullsub_286()
{}

// @fnv 0x00dfe170
// src: COMMUNITY 0x00dfe170
void nullsub_287()
{}

// @fnv 0x00dfe190
// src: COMMUNITY 0x00dfe190
void nullsub_288()
{}

// @fnv 0x00dfe1b0
// src: COMMUNITY 0x00dfe1b0
void nullsub_289()
{}

// @fnv 0x00dfe1d0
// src: COMMUNITY 0x00dfe1d0
void __cdecl nullsub_290()
{}

// @fnv 0x00dfe200
// src: COMMUNITY 0x00dfe200
void __cdecl nullsub_291()
{}

struct FnvCpu_FUN_00dfee80_CpuInterface
{
    virtual void Invoke(int value);
};
// @fnv 0x00dfee80
// src: GUESS 0x00dfee80 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00dfee80(FnvCpu_FUN_00dfee80_CpuInterface* object)
{
    object->Invoke(0);
}

struct DestructibleDFF
{
    virtual ~DestructibleDFF();
};
// @fnv 0x00dff5a0
// src: GUESS 0x00dff5a0 (confidence: medium)
void __cdecl Object_DestructibleDFF_Thunk(DestructibleDFF* pkObject)
{
    pkObject->~DestructibleDFF();
}

struct S00de0fe0_Element
{
    virtual void vf00(int value);
};

struct S00de0fe0_Arr
{
    S00de0fe0_Element** data;
    int count;
    int cap;
    void __thiscall hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
};

struct S00de0fe0_Obj10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void __thiscall hkpShapeDisplayBuilder_hkpShapeDisplayBuilder(int* value);
    void __thiscall UpdateState_00de0f90(int count, S00de0fe0_Element*** array);
};

struct S00de0fe0_Local
{
    S00de0fe0_Arr arr;
    S00de0fe0_Obj10 o;
};

struct S00de0fe0_C983Obj
{
    void __thiscall ForEachCall(int* a, int b, int c, int d, int e);
};

extern void* DAT_012681e0;

// src: HAVOK_LIB 0x00ddfb70
__declspec(noinline) void S00de0fe0_Arr::hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment()
{
    count = 0;
}

// Fills a local pointer array, calls ForEachCall on DAT_012681e0 with it, calls vf00(1) on each element, then frees the array buffer.
// @fnv 0x00de0fe0
// src: HAVOK_LIB 0x00de0fe0
void __cdecl hkpShapeDisplayBuilder_addObjectToDebugDisplay(int arg1, int arg2, int arg3, int arg4)
{
    S00de0fe0_Local local;

    local.arr.hkpShapeDisplayBuilder_hkpShapeDisplayBuilderEnvironment_hkpShapeDisplayBuilderEnvironment();
    local.o.hkpShapeDisplayBuilder_hkpShapeDisplayBuilder((int*)&local.arr);

    local.arr.data = 0;
    local.arr.count = 0;
    local.arr.cap = 0x80000000;
    local.o.UpdateState_00de0f90(arg1, &local.arr.data);

    ((S00de0fe0_C983Obj*)DAT_012681e0)->ForEachCall((int*)&local.arr, arg2, arg3, 0, arg1);

    if (local.arr.count != 0)
    {
        do
        {
            if (local.arr.data[0] != 0)
            {
                local.arr.data[0]->vf00(1);
            }

            --local.arr.count;
            if (local.arr.count == 0)
            {
                break;
            }

            local.arr.data[0] = local.arr.data[local.arr.count];
        } while (local.arr.count != 0);
    }

    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
    local.arr.count = 0;
    if ((local.arr.cap & 0x80000000) == 0)
    {
        alloc->bufFree(local.arr.data, (local.arr.cap & 0x3fffffff) * 4);
    }
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269fe8;

// @fnv 0x00de8370
// src: GUESS 0x00de8370 (confidence: low)
GlobalObjectO2_00d472a0* __cdecl Runtime_GetField01269fe8Address()
{
    return &g_01269fe8;
}

struct cls_d530
{
    int unk00;
    float m_04;
};

extern "C" cls_d530* d530_target(void);

// @fnv 0x00def530
// src: GUESS 0x00def530 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00def530(float value, cls_d530* target)
{
    target->m_04 = value;
}

void d530_caller(cls_d530* self, float f)
{
    Runtime_UpdateState_00def530(f, d530_target());
}

struct d540_cls
{
    float unk00;
    float unk04;
};
extern "C" d540_cls* d540_target(void);
// @fnv 0x00def540
// src: GUESS 0x00def540 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00def540(float a, float b, d540_cls* t)
{
    t->unk00 = a;
    t->unk04 = b;
}
void d540_caller(float fa, float fb)
{
    Object_UpdateFields_00def540(fa, fb, d540_target());
}

extern "C" Vec4* def550_target(void);

// @fnv 0x00def550
static __declspec(noinline) void SetVec4(float afX, float afY, float afZ, float afW, Vec4* apVec)
{
    apVec->x = afX;
    apVec->y = afY;
    apVec->z = afZ;
    apVec->w = afW;
}

void def550_caller(float a, float b, float c, float d)
{
    SetVec4(a, b, c, d, def550_target());
}

// @fnv 0x00df0690
// src: GUESS 0x00df0690 (confidence: high)
void Runtime_DoNothing_00df0690()
{}

// @fnv 0x00df30a0
// src: GUESS 0x00df30a0 (confidence: low)
__declspec(noinline) static void Object_UpdateFields_00df30a0(int* piTarget, int iValue)
{
    *piTarget = iValue;
}

void E30A0Store(int* piTarget, int iValue)
{
    Object_UpdateFields_00df30a0(piTarget, iValue);
}

struct ProfileEvent
{
    const void* volatile label;
    unsigned int cycles;
    unsigned int extra;
};
struct ThreadProfile
{
    void* owner;
    ProfileEvent* next;
    unsigned int capacity;
    ProfileEvent* end;
};
struct WorkItem
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    int remaining;
    unsigned int value;
    int processed;
    unsigned int unk2c;
};
struct WorkQueue
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20;
    WorkItem* tasks;
    int taskCount;
    int processorCount;
    void* processors[1];
};
struct ExecutionContext
{
    void ProcessCallback(WorkQueue* source, WorkQueue* target, int flags);
};
extern unsigned long DAT_0126835c;
extern "C" const char str_010db918[];
extern "C" const char str_010c41f8[];
int __cdecl hkKdTreeAabbQueryUtils_queryAabbIterative_00d1b930(void* processor, WorkItem* item, unsigned int* value, int remaining);
// Records a profile event, dispatches each WorkItem in queue to its processors via FUN_00d1b930, records a closing event, then calls context->ProcessCallback.
// @fnv 0x00df6950
void __cdecl ProcessWorkQueue(ExecutionContext* context, WorkQueue* queue)
{
    ThreadProfile* trace = (ThreadProfile*)TlsGetValue(DAT_0126835c);
    ProfileEvent* entry = trace->next;
    if (entry < trace->end)
    {
        entry->label = str_010db918;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        entry->cycles = ticks;
        trace->next = entry + 1;
    }
    int count = queue->taskCount;
    WorkItem* item = queue->tasks;
    if (count > 0)
    {
        int work = count;
        do
        {
            unsigned int value = item->value;
            int remaining = item->remaining;
            int n = 0;
            item->processed = 0;
            if (queue->processorCount > 0)
            {
                do
                {
                    void* processor = queue->processors[n];
                    if (processor)
                    {
                        int consumed = hkKdTreeAabbQueryUtils_queryAabbIterative_00d1b930(processor, item, &value, remaining);
                        item->processed += consumed;
                        remaining -= consumed;
                    }
                    ++n;
                } while (n < queue->processorCount);
            }
            ++item;
        } while (--work != 0);
    }
    trace = (ThreadProfile*)TlsGetValue(DAT_0126835c);
    entry = trace->next;
    if (entry < trace->end)
    {
        entry->label = str_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        entry->cycles = ticks;
        trace->next = entry + 1;
    }
    context->ProcessCallback(queue, queue, 0);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}

static inline void TimerMark(const char* name)
{
    hkMonitorStream* s = &hkMonitorStream::getInstance();
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

struct Key
{
    unsigned char m_type;
    unsigned char m_slot;
};

struct Job
{
    unsigned char m_type;
    unsigned char m_slot;
    unsigned char m_gap[0x16];
    int m_18;
    unsigned char m_gap2[0xc];
    int m_28;
    int m_2c;
};

void __cdecl hkCpuPairGetClosestPointsImplementation(Job* job, int a, int b, int c);

struct Scheduler
{
    int ProcessCallback(Key* key, int b, int a);
};

// Records a timer mark, calls FUN_00df6e00 with job's m_18, m_28 and m_2c, records a second mark, then calls self->ProcessCallback with the job.
// @fnv 0x00df6f80
// src: HAVOK_LIB 0x00df6f80
void __cdecl hkCpuPairGetClosestPointsJob(Scheduler* self, Job* job)
{
    TimerMark("TtCollQueryPairGetClosestPoints");
    hkCpuPairGetClosestPointsImplementation(job, job->m_18, job->m_28, job->m_2c);
    TimerMark("Et");
    self->ProcessCallback((Key*)job, (int)job, 0);
}

struct FUN_00df9840_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* member10;
    int unk14;
    volatile long* member18;
    void ProcessState_00df9840();
};
// Atomically adds 1 to *member18 if set, then calls FUN_00d043c0(member10, 1) if member10 is set.
// @fnv 0x00df9840
// src: GUESS 0x00df9840 (confidence: low)
void FUN_00df9840_Class::ProcessState_00df9840()
{
    if (member18)
    {
        InterlockedExchangeAdd(member18, 1);
    }
    if (member10)
    {
        hkSemaphoreBusyWait_release(member10, 1);
    }
}

extern double DAT_010229b8;

extern "C" unsigned int df9ae0_val(void);

// @fnv 0x00df9ae0
// src: HAVOK_LIB 0x00df9ae0
static __declspec(noinline) float rand01(unsigned int state)
{
    unsigned int t = 0x3039u - state * 0x3e39b193u;
    t &= 0x7fffffffu;
    return (float)((double)(int)t * DAT_010229b8);
}

volatile float df9ae0_sink;
void q_call_df9ae0(void)
{
    df9ae0_sink = rand01(df9ae0_val());
}

static int g_w1 = 1;
static int g_ws = 3;
static float g_wv = 1.0f;

// in-file stand-in for the random-float helper: must kill eax+ecx and
// preserve edx so the out pointer's private-convention home is edx
// src: HAVOK_LIB 0x00df9ae0
static __declspec(noinline) float rand01(void)
{
    g_w1 = (g_w1 * 3) << (g_ws & 31);
    return g_wv;
}

// Calls FUN_00df9ae0, computes (t + a) * (b - a), and stores the result into out[0], out[1], and out[2].
// @fnv 0x00df9b20
static __declspec(noinline) void WriteFloatToVector(float a, float b, float* out)
{
    float t = rand01();
    a = (t + a) * (b - a);
    out[0] = a;
    out[1] = a;
    out[2] = a;
}

void dummy_caller(void)
{
    WriteFloatToVector(g_wv, g_wv, &g_wv);
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dfb5a0_cls
{
    int unk00;
    char* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void UpdateFields_00dfb5a0();
};

template <class T> inline void DestructElementsDFB5A0(T* p, int n)
{
    for (int i = 0; i < n; ++i)
    {
        p[i].Object_UpdateFields_00cb0c00();
    }
}
struct ElemDFB5A0
{
    int unk00;
    FUN_00cb0c00_class m_04;
// src: GUESS 0x00cb0c00 (confidence: low)
    void Object_UpdateFields_00cb0c00()
    {
        m_04.Object_UpdateFields_00cb0c00();
    }
};
// Destructs the array elements, frees m_pData unless the top capacity bit is set, resets it to empty, then calls FUN_00cb0c00 on this.
// @fnv 0x00dfb5a0
// src: GUESS 0x00dfb5a0 (confidence: low)
void FUN_00dfb5a0_cls::UpdateFields_00dfb5a0()
{
    hkMemoryAllocator* pAlloc = reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap);
    DestructElementsDFB5A0((ElemDFB5A0*)m_pData, m_iArrayLength);
    m_iArrayLength = 0;
    if ((m_uCap & 0x80000000u) == 0)
    {
        pAlloc->bufFree(m_pData, (m_uCap & 0x3fffffffu) * 8);
    }
    m_pData = 0;
    m_uCap = 0x80000000u;
    ((FUN_00cb0c00_class*)this)->Object_UpdateFields_00cb0c00();
}

void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int sizeOfElement);

// 0x00de30a0 stores a pointer payload and an integer lookup key; Pair.h stores two integer handles.
struct RegistryValueKey
{
    void* m_uiFilterValue;
    int m_key;
    RegistryValueKey(void* value, int key) : m_uiFilterValue(value), m_key(key)
    {}
};

// Keep the router lookup before the capacity test and read its allocator only when growth is needed.
template <class T>
__forceinline void AppendRegistryValue(hkArray<T>& array, const T& t)
{
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(router->m_heap), &array, sizeof(T));
    new (&array.m_data[array.m_iElementCount]) T(t);
    array.m_iElementCount++;
}

struct Registry_de30
{
    int unk00, unk04;
    hkArray<RegistryValueKey> m_pairs;
    void hkpUserConvexRadiusBuilder_registerUserConvexRadiusDisplayBuilder(void* value, int key);
};

// Adds a value/key pair to m_pairs if no existing pair has the same key.
// @fnv 0x00de30a0
// src: XBOX_PDB 0x00de30a0
void Registry_de30::hkpUserConvexRadiusBuilder_registerUserConvexRadiusDisplayBuilder(void* value, int key)
{
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_key == key)
            return;
    }
    AppendRegistryValue(m_pairs, RegistryValueKey(value, key));
}

// @fnv 0x00de9b00
// src: GUESS 0x00de9b00 (confidence: high)
void __cdecl Object_DoNothing_00de9b00()
{}

namespace fnv_00df2640 {
void __cdecl ResizeAudioStream(hkMemoryAllocator* pAllocator, void* pArray, unsigned int auiNewSize);

struct S00df2640_list
{
    void** data;
    int size;
    unsigned int capBits;
};

struct S00df2640_owner
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
    S00df2640_list m_28;
};

struct S00df2640_mid
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    S00df2640_owner* m_18;
};

struct S00df2640_a2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S00df2640_mid* m_14;
    int unk18;
    int unk1C;
    unsigned short m_20;
};

struct S00df2640_a1
{
    int unk00;
    unsigned short m_04;
};

struct S00df2640_item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short m_20;
};

struct S00df2640_P
{
    int unk00;
    int unk04;
    int unk08;
    int m_0C;
    int m_10;
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
    void** m_5C;
    int m_60;
    unsigned int m_64;
};

struct S00df2640_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short m_10;
    unsigned short unk12;
    int unk14;
    S00df2640_P* m_18;
    int unk1C;
    unsigned short m_20;

    int hkpBroadPhaseJob_popJobTask(S00df2640_a1* a1, S00df2640_a2* a2);
};

// If m_18 has pending entries, appends them to a2's list and frees its array; otherwise decrements m_20 when above 1; returns 1 on either, else 0.
// @fnv 0x00df2640
// src: HAVOK_LIB 0x00df2640
int S00df2640_cls::hkpBroadPhaseJob_popJobTask(S00df2640_a1* a1, S00df2640_a2* a2)
{
    S00df2640_P* p = m_18;
    if (p != 0)
    {
        int count = p->m_60;
        if (count != 0)
        {
            p->m_0C += count;
            p->m_10 += count;
            m_10 = a1->m_04;
            m_20 = (unsigned short)count;

            S00df2640_list* list = &a2->m_14->m_18->m_28;
            for (int i = 0; i < count; i++)
            {
                S00df2640_item* item = (S00df2640_item*)p->m_5C[i];
                item->m_20 = (unsigned short)list->size;
                hkMemoryRouter* holder = hkMemoryRouter_getInstance();
                if (list->size == (int)(list->capBits & 0x3fffffffu))
                {
                    ResizeAudioStream(reinterpret_cast<hkMemoryAllocator*>(holder->m_heap), list, 4);
                }
                void** slot = list->data + list->size;
                __assume(slot != 0);
                *slot = item;
                list->size++;
            }

            hkMemoryRouter* holder = hkMemoryRouter_getInstance();
            hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
            unsigned int cap = p->m_64;
            p->m_60 = 0;
            if ((cap & 0x80000000u) == 0)
            {
                alloc->bufFree(p->m_5C, (cap & 0x3fffffffu) * 4);
            }
            p->m_5C = 0;
            p->m_64 = 0x80000000u;
            return 1;
        }
    }

    unsigned short ax = m_20;
    if (ax > 1)
    {
        ax--;
        m_20 = ax;
        m_10++;
        a2->m_20 = 1;
        return 1;
    }
    return 0;
}
}  // namespace fnv_00df2640

// @fnv 0x00df30b0
// src: GUESS 0x00df30b0 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00df30b0(stub_cls* target, int value)
{
    target->unk00 = value;
}

void df30b0_caller(stub_cls* target)
{
    Runtime_UpdateState_00df30b0(target, stub_val());
}

// FUN_00df30f0: store the 16-byte vector *s into element idx of the array d.
//
// The helper has internal linkage (unit-local), so the compiler is free to
// choose its own register convention for it; hcaller keeps an out-of-line,
// separately-scheduled copy of the helper in the object file.
// @fnv 0x00df30f0
// src: GUESS 0x00df30f0 (confidence: high)
static void Runtime_SetVectorArrayElement(__m128* apDest, int aiIndex, const __m128* apSource)
{
    apDest[aiIndex] = *apSource;
}
void hcaller(__m128* d, int idx, const __m128* s)
{
    Runtime_SetVectorArrayElement(d, idx, s);
}

struct FNVVec16
{
    unsigned int m_u0;
    unsigned int m_u1;
    unsigned int m_u2;
    unsigned int m_u3;
};

__declspec(align(16)) struct FNVQuad
{
    unsigned int m_u0;
    unsigned int m_u1;
    unsigned int m_u2;
    unsigned int m_u3;
};

struct FNVPair8
{
    unsigned int m_uiKey;
    int m_iArrayLength;
};

// @fnv 0x00df3330
// src: GUESS 0x00df3330 (confidence: low)
int Runtime_ProcessEntries_00df3330(FNVPair8* out, FNVVec16* src, __m128* dst, unsigned int index, unsigned int n, int count)
{
    src += n;
    out[index].m_uiKey = n & 0x7fffffffu;
    out[index].m_iArrayLength = count;
    for (int i = 0; i < count; i++)
    {
        FNVQuad t;
        FNVVec16* s = src;
        t.m_u0 = s->m_u0;
        t.m_u1 = s->m_u1;
        t.m_u2 = s->m_u2;
        t.m_u3 = s->m_u3;
        dst[n + i] = *(__m128*)&t;
        src++;
    }
    return count + count - 2;
}

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);

__forceinline void SetMatrixProduct(__m128& out, const hkMatrix3& m, __m128 v)
{
    const __m128 v0 = _mm_shuffle_ps(v, v, 0x00);
    const __m128 v1 = _mm_shuffle_ps(v, v, 0x55);
    const __m128 v2 = _mm_shuffle_ps(v, v, 0xaa);
    const __m128 r0 = _mm_mul_ps(m.m_kColumn0.m_vComponents, v0);
    const __m128 r1 = _mm_mul_ps(m.m_kColumn1.m_vComponents, v1);
    const __m128 r2 = _mm_mul_ps(m.m_kColumn2.m_vComponents, v2);
    out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void SetInverseMatrixProduct(__m128& out, const hkMatrix3& m, __m128 v)
{
    __m128 c0 = m.m_kColumn0.m_vComponents;
    __m128 c1 = m.m_kColumn1.m_vComponents;
    __m128 c2 = m.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    tmp = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    const __m128 b0 = _mm_shuffle_ps(v, v, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(v, v, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(v, v, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct OutRef
{
    hkVector4* p;
    hkVector4* operator->() const
    {
        return p;
    }
};
struct Jac
{
    hkMatrix3 m0;     // 0x00
    char m0Padding[16];
    hkMatrix3 unk40;  // 0x40
    char unk40Padding[16];
    hkMatrix3 m1;     // 0x80
    char m1Padding[16];
    hkMatrix3 unkC0;  // 0xC0
    char unkC0Padding[16];
    hkMatrix3 rot;    // 0x100
};

// Stores into out: (a[0]-b[0]) rotated by the inverse of j->rot, plus m0 times a[1] minus m1 times b[1].
// @fnv 0x00df5e80
// src: GUESS 0x00df5e80 (confidence: low)
void __cdecl hkVector4_UpdateFields_00df5e80(const Jac* j, const hkVector4* a, const hkVector4* b, OutRef out)
{
    __m128 d = _mm_sub_ps(a[0].m_vComponents, b[0].m_vComponents);
    __m128 ang;
    SetInverseMatrixProduct(ang, j->rot, d);
    const __m128 a1 = a[1].m_vComponents;
    const __m128 b1 = b[1].m_vComponents;
    __m128 lb;
    SetMatrixProduct(lb, j->m1, b1);
    __m128 la;
    SetMatrixProduct(la, j->m0, a1);
    __m128 lin = _mm_sub_ps(la, lb);
    out->m_vComponents = _mm_add_ps(lin, ang);
}

struct Obj_df7a90
{
    unsigned char m_ucType;
    char unk01;
    char unk02;
    char unk03;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int* m_piRefCount;
    void hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
};

// Decrements the object's reference count and calls FUN_00df7a60 when it reaches zero, then returns 1.
// @fnv 0x00df7a90
// src: HAVOK_LIB 0x00df7a90
int __cdecl hkpCollisionQueryJobQueueUtils_finishCollisionJob(int iArg0, int iArg1, Obj_df7a90* pkObj)
{
    int* piRefCount = pkObj->m_piRefCount;
    switch (pkObj->m_ucType)
    {
    case 0:
        if (--*piRefCount == 0)
            pkObj->hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
        break;
    case 1:
        if (--*piRefCount == 0)
            pkObj->hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
        break;
    case 2:
        if (--*piRefCount == 0)
            pkObj->hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
        break;
    case 3:
        if (--*piRefCount == 0)
            pkObj->hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
        break;
    case 4:
        if (--*piRefCount == 0)
            pkObj->hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
        break;
    case 5:
        if (--*piRefCount == 0)
            pkObj->hkpCollisionQueryJob_atomicIncrementAndReleaseSemaphore();
        break;
    }
    return 1;
}

struct SDF7_Cmd16
{
    int a;
    int b;
    int c;
    int d;
};
struct SDF7_Cmd32
{
    SDF7_Cmd16 lo;
    SDF7_Cmd16 hi;
};
struct SDF7_Cmd48
{
    SDF7_Cmd16 a;
    SDF7_Cmd16 b;
    SDF7_Cmd16 c;
};
struct SDF7_Cmd64
{
    SDF7_Cmd32 lo;
    SDF7_Cmd32 hi;
};

struct SDF7_Job
{
    unsigned char m_ucSubType;
    unsigned char m_type;
    unsigned short m_iElementCount;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SDF7_Job4 : SDF7_Job
{
    int m_iCommandCapacity;
    SDF7_Cmd48* m_pCommands;
    int m_iCommandCount;
};

struct SDF7_Job1 : SDF7_Job
{
    int unk20;
    int m_iCommandCapacity;
    SDF7_Cmd32* m_pCommands;
    int m_iCommandCount;
};

struct SDF7_Job2 : SDF7_Job
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_iCommandCapacity;
    SDF7_Cmd16* m_pCommands;
    int m_iCommandCount;
};

struct SDF7_Job3 : SDF7_Job
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int m_iCommandCapacity;
    SDF7_Cmd64* m_pCommands;
    int m_iCommandCount;
};

struct SDF7_Job0 : SDF7_Job
{
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int m_iCommandCapacity;
    SDF7_Cmd48* m_pCommands;
    int m_iCommandCount;
};

struct SDF7_JobQueueEntry : SDF7_Job
{
    int m_data[24];
};

__forceinline void SDF7_memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* src32 = (const unsigned int*)src;
    unsigned int* dst32 = (unsigned int*)dst;
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        src32 += 4;
        dst32 += 4;
    } while (--numQuads > 0);
}

template <class T> __forceinline int SDF7_split(SDF7_JobQueueEntry& jobIn, SDF7_JobQueueEntry& jobOut)
{
    T& onQueue = static_cast<T&>(static_cast<SDF7_Job&>(jobIn));
    T& out = static_cast<T&>(static_cast<SDF7_Job&>(jobOut));
    if (onQueue.m_iCommandCount > onQueue.m_iCommandCapacity)
    {
        out.m_iCommandCount = onQueue.m_iCommandCapacity;
        onQueue.m_iCommandCount -= onQueue.m_iCommandCapacity;
        onQueue.m_pCommands += onQueue.m_iCommandCapacity;
        return 1;
    }
    return 0;
}

// Copies jobIn into jobOut, then splits the command array when the count exceeds the capacity, returning 1 if a split occurred.
// @fnv 0x00df7ad0
int __cdecl SplitJob(void* queue, void* data, SDF7_JobQueueEntry& jobIn, SDF7_JobQueueEntry& jobOut)
{
    SDF7_memCpy16NonEmpty(&jobOut, &jobIn, sizeof(SDF7_JobQueueEntry) >> 4);
    switch (jobIn.m_ucSubType)
    {
    case 3:
        return SDF7_split<SDF7_Job3>(jobIn, jobOut);
    case 4:
        return SDF7_split<SDF7_Job4>(jobIn, jobOut);
    case 0:
        return SDF7_split<SDF7_Job0>(jobIn, jobOut);
    case 1:
        return SDF7_split<SDF7_Job1>(jobIn, jobOut);
    case 2:
        return SDF7_split<SDF7_Job2>(jobIn, jobOut);
    }
    return 0;
}

extern char DAT_010dba24[];
struct KdJob2
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    float m_38;
    float m_3c;
    KdPair m_40;
    int m_48;
    int m_4c;
    int m_50;
};
struct KdQueue2
{
    int ProcessCallback(const KdJob2* a, const KdJob2* b, int flag);
};
void __cdecl hkTreeBundleRayCastUtil_autoBundleFromList(int, int, int, int, int, float, float, KdPair, int*, int, int*);
void __cdecl hkTreeBundleRayCastUtil_autoBundleScanAll(int, int, int, int, float, float, KdPair, int*, int, int*);
// Runs FUN_00e29cd0 if job->m_20 is nonzero, else FUN_00e2a010, between timer markers, then returns queue->ProcessCallback(job, job, 0).
// @fnv 0x00df7c00
int __cdecl ExecuteJob(KdQueue2* queue, KdJob2* job)
{
    TimerCommandKdWrite(DAT_010dba24);
    job->m_48 = 0;
    job->m_50 = 0;
    if (job->m_20)
        hkTreeBundleRayCastUtil_autoBundleFromList(job->m_20, job->m_28, job->m_2c, job->m_30, job->m_34, job->m_38, job->m_3c, job->m_40, &job->m_48,
                     job->m_4c, &job->m_50);
    else
        hkTreeBundleRayCastUtil_autoBundleScanAll(job->m_24, job->m_2c, job->m_30, job->m_34, job->m_38, job->m_3c, job->m_40, &job->m_48, job->m_4c,
                     &job->m_50);
    TimerCommandKdWrite(DAT_010c41f8);
    return queue->ProcessCallback(job, job, 0);
}

struct InDF8800
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
    void** m_ppGeometries;  // 0x50
    int m_i0x54;
    int m_i0x58;
    int m_iArrayLength;  // 0x5c
};

struct ArrDF8800
{
    ~ArrDF8800()
    {
        hkMemoryAllocator* pkAllocator = reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap);
        int iCapacityAndFlags = m_iCapacityAndFlags;
        m_uiLogicalSize = 0;
        if ((iCapacityAndFlags & 0x80000000) == 0)
            pkAllocator->bufFree(m_ppGeometries, (iCapacityAndFlags & 0x3fffffff) * 4);
        m_ppGeometries = 0;
        m_iCapacityAndFlags = 0x80000000;
    }
    void** m_ppGeometries;    // 0x00
    int m_uiLogicalSize;              // 0x04
    int m_iCapacityAndFlags;  // 0x08
};

struct CollDF8800
{
    CollDF8800(ArrDF8800& kArray, int iFlags) throw();
    virtual ~CollDF8800()
    {}
    ArrDF8800* m_pkArray;  // 0x04
    int m_iFlags;          // 0x08
};

void __cdecl FillAabbArray(CollDF8800* pkCollector, int i0x58, int iCount, int i0x54) throw();

struct WorldDF8800
{
    void* ProcessCallback(InDF8800* pkSource, InDF8800* pkTarget, int iFlags) throw();
};

// Logs a TtCpuKdTreeBuildSetup timer entry, runs FillAabbArray and pkWorld->ProcessCallback, logs an Et entry, and returns the ProcessCallback result.
// @fnv 0x00df8800
// src: HAVOK_LIB 0x00df8800
void* hkCpuKdTreeBuildSetupJob(WorldDF8800* pkWorld, InDF8800* pkInput)
{
    {
        MonitorStreamKd* pkStream = (MonitorStreamKd*)TlsGetValue(DAT_0126835c);
        if (pkStream->m_kRayEnd < pkStream->m_capacityEnd)
        {
            TimerCommandKd* pkCommand = (TimerCommandKd*)pkStream->m_kRayEnd;
            pkCommand->m_name = "TtCpuKdTreeBuildSetup";
            _ReadWriteBarrier();
            volatile unsigned int uiTicks = (unsigned int)__rdtsc();
            pkCommand->m_uiCommandId = uiTicks;
            pkStream->m_kRayEnd = (char*)(pkCommand + 1);
        }
    }

    void* pvResult;
    {
        ArrDF8800 kItems;
        kItems.m_ppGeometries = pkInput->m_ppGeometries;
        kItems.m_uiLogicalSize = pkInput->m_iArrayLength;
        kItems.m_iCapacityAndFlags = pkInput->m_iArrayLength | 0x80000000;
        CollDF8800 kCollector(kItems, 0);
        FillAabbArray(&kCollector, pkInput->m_i0x58, pkInput->m_iArrayLength, pkInput->m_i0x54);
        pvResult = pkWorld->ProcessCallback(pkInput, pkInput, 0);
    }

    {
        MonitorStreamKd* pkStream = (MonitorStreamKd*)TlsGetValue(DAT_0126835c);
        if (pkStream->m_kRayEnd < pkStream->m_capacityEnd)
        {
            TimerCommandKd* pkCommand = (TimerCommandKd*)pkStream->m_kRayEnd;
            pkCommand->m_name = "Et";
            _ReadWriteBarrier();
            volatile unsigned int uiTicks = (unsigned int)__rdtsc();
            pkCommand->m_uiCommandId = uiTicks;
            pkStream->m_kRayEnd = (char*)(pkCommand + 1);
        }
    }
    return pvResult;
}

struct Param3Struct
{
    unsigned char unk00;
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
};

// Copies 128 bytes from param_3 to param_4, then for types 0 and 1 takes unk20 elements of 80 or 64 bytes from the range and returns 1, else 0.
// @fnv 0x00df9880
unsigned int __cdecl CopyAndAdvance(unsigned int uiUnused, unsigned int param_2, char* param_3, int* param_4)
{
    int* src = reinterpret_cast<int*>(param_3);
    int* dst = param_4;
    int i = 8;
    do
    {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        src += 4;
        dst += 4;
    } while (--i > 0);

    Param3Struct* p3 = reinterpret_cast<Param3Struct*>(param_3);

    switch (p3->unk00)
    {
    case 0:
        if (p3->unk28 > p3->unk20)
        {
            param_4[0x28 / 4] = p3->unk20;
            p3->unk28 -= p3->unk20;
            p3->unk24 += p3->unk20 * 80;
            return 1;
        }
        return 0;
    case 1:
        if (p3->unk28 > p3->unk20)
        {
            param_4[0x28 / 4] = p3->unk20;
            p3->unk28 -= p3->unk20;
            p3->unk24 += p3->unk20 * 64;
            p3->unk30 = 0;
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}

struct DFB0B0_Entry
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
    float distance;
    int unk44;
    int unk48;
    int unk4c;
};

struct DFB0B0_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int numEntries;
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
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    int unkc10;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int unkc24;
    int unkc28;
    int unkc2c;
    int unkc30;
    int unkc34;
    int unkc38;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    int unke50;
    int unke54;
    int unke58;
    int unke5c;
    int unke60;
    int unke64;
    int unke68;
    int unke6c;
    int unke70;
    int unke74;
    int unke78;
    int unke7c;
    int unke80;
    int unke84;
    int unke88;
    int unke8c;
    int unke90;
    int unke94;
    int unke98;
    int unke9c;
    int unkea0;
    int unkea4;
    int unkea8;
    int unkeac;
    int unkeb0;
    int unkeb4;
    int unkeb8;
    int unkebc;
    int unkec0;
    int unkec4;
    int unkec8;
    int unkecc;
    int unked0;
    int unked4;
    int unked8;
    int unkedc;
    int unkee0;
    int unkee4;
    int unkee8;
    int unkeec;
    int unkef0;
    int unkef4;
    int unkef8;
    int unkefc;
    int unkf00;
    int unkf04;
    int unkf08;
    int unkf0c;
    int unkf10;
    int unkf14;
    int unkf18;
    int unkf1c;
    int unkf20;
    int unkf24;
    int unkf28;
    int unkf2c;
    int unkf30;
    int unkf34;
    int unkf38;
    int unkf3c;
    int unkf40;
    int unkf44;
    int unkf48;
    int unkf4c;
    int unkf50;
    int unkf54;
    int unkf58;
    int unkf5c;
    int unkf60;
    int unkf64;
    int unkf68;
    int unkf6c;
    DFB0B0_Entry entries;
    DFB0B0_Entry* GetNearestEntry();
};

// Scans the entries array and returns a pointer to the DFB0B0_Entry with the smallest distance value.
// @fnv 0x00dfb0b0
DFB0B0_Entry* DFB0B0_Owner::GetNearestEntry()
{
    DFB0B0_Entry* e = &entries;
    DFB0B0_Entry* best = e;
    float bestDist = e->distance;
    int i = numEntries - 2;
    __assume(i >= 0);
    for (; i >= 0; i--)
    {
        e++;
        float d = e->distance;
        if (d < bestDist)
        {
            bestDist = d;
            best = e;
        }
    }
    return best;
}

// FUN_00dfdd90 : releases the owned sub-object at +4, clears the field and
// tail-calls the base destructor of the object itself.
struct SubObject
{
    void __thiscall FUN_00c905b0();
};

struct FUN_00dfdd90_cls
{
    int unk00;
    SubObject* m_pSub;
    void __thiscall Object_UpdateFields_00cb0c00();
};

// Calls FUN_00c905b0 on m_pSub if set, clears m_pSub, then calls FUN_00cb0c00 on p.
// @fnv 0x00dfdd90
// src: GUESS 0x00dfdd90 (confidence: medium)
void __cdecl Runtime_ReleaseSubobjectAndClear(FUN_00dfdd90_cls* p)
{
    if (p->m_pSub != 0)
        p->m_pSub->FUN_00c905b0();
    p->m_pSub = 0;
    p->Object_UpdateFields_00cb0c00();
}

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00de10b0_cls
{
    virtual ~FUN_00de10b0_cls();
    unsigned short m_uSize;
    unsigned short m_u06;

    static void operator delete(void* apMemory) throw()
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(apMemory, ((FUN_00de10b0_cls*)apMemory)->m_uSize);
    }
};

// Empty virtual destructor; the class operator delete frees the object through the allocator using m_uSize.
// @fnv 0x00de10b0
FUN_00de10b0_cls::~FUN_00de10b0_cls()
{}

// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00de3040();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00de3040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00de3040
// src: GUESS 0x00de3040 (confidence: low)
    virtual void AdjustThisAndForward_00de3040();
};

Derived::Derived()
{}

namespace fnv_00dfed30 {
// Declares a Heap interface with four unnamed virtual methods and a virtual release(void*, unsigned int).
// @fnv 0x00dfed30
struct Heap
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void release(void*, unsigned int);
};
struct Manager
{
    int unk00, unk04, unk08, unk0c;
    Heap* volatile heap;
};
extern "C" Manager* __cdecl hkMemoryRouter_getInstance();
extern "C" int DAT_0102e388;
struct Holder
{
    void* volatile vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    void* data1;
    int size1;
    int cap1;
    void* data2;
    int size2;
    int cap2;
    void __thiscall SetVtableAndProcessState_00dfed30();
};
// src: GUESS 0x00dfed30 (confidence: low)
void Holder::SetVtableAndProcessState_00dfed30()
{
    Manager* mgr = hkMemoryRouter_getInstance();
    Heap* mem = mgr->heap;
    size2 = 0;
    if ((cap2 & 0x80000000) == 0)
        mem->release(data2, (cap2 & 0x3fffffff) * 4);
    data2 = 0;
    cap2 = 0x80000000;
    Manager* mgr2 = hkMemoryRouter_getInstance();
    Heap* mem2 = mgr2->heap;
    size1 = 0;
    if ((cap1 & 0x80000000) == 0)
        mem2->release(data1, (cap1 & 0x3fffffff) * 4);
    data1 = 0;
    cap1 = 0x80000000;
    vtable = &DAT_0102e388;
}
}  // namespace fnv_00dfed30

namespace fnv_00dff440 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk (multiple inheritance, second base at +8).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00dff440();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00dff440();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff440
// src: GUESS 0x00dff440 (confidence: low)
    virtual void AdjustThisAndForward_00dff440();
};

Derived::Derived()
{}
}  // namespace fnv_00dff440

// 00dff450: compiler-generated thiscall adjustor thunk (sub ecx,0xc; jmp DestroySelf).
// Reproduce via MI dual-slot override: the override lands in both the primary vftable
// and the secondary vftable (which sits at offset 0xc), so VC9 emits the adjustor thunk.
struct AdjPrim
{
    virtual void FUN_00dff450();
    int p04;
    int p08;
};

struct AdjSec
{
    virtual void FUN_00dff450();
};

struct AdjDerived : AdjPrim, AdjSec
{
// @fnv 0x00dff450
    virtual void FUN_00dff450();
};

static AdjDerived g_adjThunk;

namespace fnv_00dff460 {
// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk (second base of multiple inheritance).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00dff460();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00dff460();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00dff460
// src: GUESS 0x00dff460 (confidence: low)
    virtual void AdjustThisAndForward_00dff460();
};

Derived::Derived()
{}
}  // namespace fnv_00dff460

struct S00de9bd0_Edge
{
    int edge;
    union
    {
        float fraction;
        unsigned fractionBits;
    };
    S00de9bd0_Edge()
    {}
    S00de9bd0_Edge(int e, float f) : edge(e), fraction(f)
    {}
};
static inline void S00de9bd0_swap(S00de9bd0_Edge& a, S00de9bd0_Edge& b)
{
    S00de9bd0_Edge t = a;
    a = b;
    b = t;
}
static inline float S00de9bd0_clamp(float t)
{
    float result;
    if (t < 0.0f)
        result = 0.0f;
    else if (t > 1.0f)
        result = 1.0f;
    else
        result = t;
    return result;
}

// Finds sign changes between the three d values, writes two edge/fraction entries to out ordered by orientation, and returns the edge mask (0 if not two).
// @fnv 0x00de9bd0
// src: GUESS 0x00de9bd0 (confidence: medium)
int __cdecl Runtime_FindTriangleEdgeSignChanges(const float* d, S00de9bd0_Edge* apEdges, float orientation)
{
    float t[3];
    t[0] = 0.0f;
    t[1] = 0.0f;
    t[2] = 0.0f;

    float ratio;
    int mask = 0;
    int prev = 2;
    for (int i = 0; i < 3; i++)
    {
        if (d[prev] != d[i] && d[prev] * d[i] <= 0.0f)
        {
            mask |= 1 << prev;
            ratio = d[prev] / (d[prev] - d[i]);
            t[prev] = S00de9bd0_clamp(ratio);
        }
        prev = i;
    }
    double side;
    S00de9bd0_Edge first;
    switch (mask)
    {
    case 6:
        first = S00de9bd0_Edge(1, t[1]);
        apEdges[0] = first;
        apEdges[1] = S00de9bd0_Edge(2, t[2]);
        side = d[2];
        if (side * orientation < 0.0f)
        {
            {
                S00de9bd0_Edge& a = apEdges[0];
                S00de9bd0_Edge& b = apEdges[1];
                S00de9bd0_Edge tmp = a;
                a = b;
                b = tmp;
            }
        }
        break;
    case 5:
        first = S00de9bd0_Edge(2, t[2]);
        apEdges[0] = first;
        apEdges[1] = S00de9bd0_Edge(0, t[0]);
        side = d[0];
        if (side * orientation < 0.0f)
        {
            {
                S00de9bd0_Edge& a = apEdges[0];
                S00de9bd0_Edge& b = apEdges[1];
                S00de9bd0_Edge tmp = a;
                a = b;
                b = tmp;
            }
        }
        break;
    case 3:
        first = S00de9bd0_Edge(0, t[0]);
        apEdges[0] = first;
        apEdges[1] = S00de9bd0_Edge(1, t[1]);
        side = d[1];
        if (side * orientation < 0.0f)
        {
            {
                S00de9bd0_Edge& a = apEdges[0];
                S00de9bd0_Edge& b = apEdges[1];
                S00de9bd0_Edge tmp = a;
                a = b;
                b = tmp;
            }
        }
        break;
    default:
        mask = 0;
    }
    return mask;
}

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
struct VelocityVector
{
    union
    {
        __m128 q;
        float lanes[4];
    };
    __forceinline void subtract(const VelocityVector& x, const VelocityVector& y)
    {
        q = _mm_sub_ps(x.q, y.q);
    }
    __forceinline void add(const VelocityVector& x)
    {
        q = _mm_add_ps(q, x.q);
    }
    __forceinline void cross(const VelocityVector& x, const VelocityVector& y)
    {
        __m128 positive = _mm_mul_ps(_mm_shuffle_ps(x.q, x.q, 0xc9), _mm_shuffle_ps(y.q, y.q, 0xd2));
        __m128 negative = _mm_mul_ps(_mm_shuffle_ps(x.q, x.q, 0xd2), _mm_shuffle_ps(y.q, y.q, 0xc9));
        q = _mm_sub_ps(positive, negative);
    }
    __forceinline float dot(const VelocityVector& x) const
    {
        __m128 terms = _mm_mul_ps(q, x.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_cvtss_f32(_mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), xy));
    }
};
struct VelocityBody
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
    VelocityVector linear;
    VelocityVector angular;
    __forceinline void pointVelocity(const VelocityVector& position, const VelocityVector& center,
                                     VelocityVector& result) const
    {
        VelocityVector arm;
        arm.subtract(position, center);
        result.cross(angular, arm);
        result.add(linear);
    }
};
struct ContactVectors
{
    VelocityVector position;
    VelocityVector normal;
};
// Computes the relative velocity of two bodies at a contact point and returns its projection onto the contact normal.
// @fnv 0x00df2510
// src: COMMUNITY 0x00df2510
float __cdecl hkpSimpleContactConstraintUtil_calculateSeparatingVelocity(const VelocityBody* a, const VelocityBody* b, const VelocityVector* centerA,
                           const VelocityVector* centerB, const ContactVectors* contact)
{
    VelocityVector velocityA;
    a->pointVelocity(contact->position, *centerA, velocityA);
    VelocityVector velocityB;
    b->pointVelocity(contact->position, *centerB, velocityB);
    VelocityVector relative;
    relative.subtract(velocityA, velocityB);
    return relative.dot(contact->normal);
}

extern "C"
{
    void _ReadWriteBarrier();
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_rcp_ps(__m128);
    __m128 _mm_add_ss(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

__forceinline V4::V4() {}
__forceinline void V4::setMul4(const V4& a, const V4& b)
{
        q = _mm_mul_ps(a.q, b.q);
    }
__forceinline void V4::mul4(const V4& a)
{
        q = _mm_mul_ps(q, a.q);
    }
__forceinline void V4::mul4(__m128 s)
{
        q = _mm_mul_ps(q, s);
    }
__forceinline void V4::add4(const V4& a)
{
        q = _mm_add_ps(q, a.q);
    }
__forceinline void V4::setMax4(const V4& a, const V4& b)
{
        q = _mm_max_ps(a.q, b.q);
    }
__forceinline void V4::setReciprocal4(const V4& d)
{
        __m128 r = _mm_rcp_ps(d.q);
        q = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, d.q), r));
    }
__forceinline __m128 V4::getW() const
{
        return _mm_shuffle_ps(q, q, 0xff);
    }
__forceinline float V4::horizontalAdd3() const
{
        __m128 s = _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q));
        float out;
        _mm_store_ss(&out, s);
        return out;
    }

struct Rot3
{
    V4 c0;
    V4 c1;
    V4 c2;
};
__forceinline void transpose3(__m128& c0, __m128& c1, __m128& c2)
{
    {
        __m128 lo = _mm_unpacklo_ps(c0, c1);
        __m128 hi = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(lo, c2);
        c1 = _mm_movehl_ps(c0, lo);
        c1 = _mm_shuffle_ps(c1, c2, 0xd4);
        c2 = _mm_shuffle_ps(hi, c2, 0xe4);
    }
}
__forceinline void setRotatedInverseDir(V4& out, const Rot3& r, const V4& vin)
{
    __m128 c0 = r.c0.q;
    __m128 c1 = r.c1.q;
    __m128 c2 = r.c2.q;
    transpose3(c0, c1, c2);
    const __m128 b = vin.q;
    out.q =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(c0, _mm_shuffle_ps(b, b, 0x00)), _mm_mul_ps(c1, _mm_shuffle_ps(b, b, 0x55))),
                   _mm_mul_ps(c2, _mm_shuffle_ps(b, b, 0xaa)));
}
struct Pair4
{
    V4 a;
    V4 b;
};
extern "C" const V4 DAT_010c7200;

struct InertiaHolder
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
    V4 m_invMass;  // 0x60
    int unk70;
    Rot3* m_pRot;  // 0x74
    float ProcessAndReturnValue_00df6380(const Pair4* p);
};

// Returns the x+y+z sum of squared p->a and squared, m_pRot-rotated p->b, each scaled by the reciprocal of m_invMass clamped with DAT_010c7200.
// @fnv 0x00df6380
// src: GUESS 0x00df6380 (confidence: low)
float InertiaHolder::ProcessAndReturnValue_00df6380(const Pair4* p)
{
    V4 v;
    setRotatedInverseDir(v, *m_pRot, p->b);
    V4 d;
    d.setMax4(m_invMass, DAT_010c7200);
    V4 inv;
    inv.setReciprocal4(d);
    v.mul4(v);
    v.mul4(inv);
    V4 lin;
    lin.setMul4(p->a, p->a);
    inv.q = _mm_shuffle_ps(inv.q, inv.q, 0xff);
    _ReadWriteBarrier();
    inv.q = _mm_shuffle_ps(inv.q, inv.q, 0);
    lin.mul4(inv);
    lin.add4(v);
    return lin.horizontalAdd3();
}

extern "C" void _ReadWriteBarrier();

struct JobSrc
{
    unsigned char m_type, m_01, m_02, m_03;
    int m_04, m_08, m_0c, m_10;
    int* m_pCounter;
    int m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34;
    int m_i38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54;
    int* m_p58;
    int m_5c, m_60, m_64, m_68, m_6c;
    void ProcessState_00df9840();
};

struct EnumU8
{
    unsigned char m_kStorage;
    EnumU8()
    {}
    EnumU8(int value) : m_kStorage((unsigned char)value)
    {}
    EnumU8& operator=(int value)
    {
        m_kStorage = (unsigned char)value;
        return *this;
    }
};

struct JobBase
{
    unsigned char m_type, m_b1;
    EnumU8 m_b2;
    unsigned char m_b3;
    unsigned short m_w4;
    short m_w6;
    int m_8, m_iThirdValue, m_10;
    int* m_p14;
    int m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40;

    __forceinline JobBase(unsigned char type, int value)
        : m_type(type), m_b1(3), m_b2(2), m_w4(0x50), m_w6(-1), m_10(value)
    {
        m_18 = 0;
        m_b2 = 1;
    }
    __forceinline void initHead(unsigned char type)
    {
        m_type = type;
        m_b1 = 3;
        m_b2 = 2;
        m_w4 = 0x50;
        m_w6 = -1;
    }
    __forceinline JobBase(unsigned char type, int value, int a54, int a44)
    {
        _ReadWriteBarrier();
        initHead(type);
        m_1c = a54;
        m_10 = value;
        m_24 = a44;
        m_18 = 0;
        m_b2 = 1;
    }
};

struct JobA : JobBase
{
    __forceinline JobA(int* counter) : JobBase(3, 0)
    {
        m_30 = 0;
        m_p14 = counter;
    }
};

struct JobValues
{
    int first, second;
    JobValues(int a, int b) : first(a), second(b)
    {}
};

struct JobB : JobBase
{
    __forceinline JobB(int a54, int* counter, int a44, int a48, int a60, int a5c) : JobBase(1, a5c, a54, a44)
    {
        m_p14 = counter;
        m_20 = 0x40;
        m_28 = a48;
        m_34 = a60;
        *counter = a48 == 0 ? 1 : (a48 - 1) / 64 + 1;
        m_38 = 0;
        m_3c = 0;
        m_40 = 0;
        m_2c = 0;
        m_30 = 0;
    }
};

struct JobOut
{
    int m_iWordAt00, m_iWordAt04, m_8;
    unsigned char m_iThirdValue, m_iFourthElementInteger, m_usTrailingValue, m_f;
    unsigned char m_10, m_11, m_12, m_13;
    int m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30;
    int m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50;
};

void CopyFields(void*, void*);

// Switches on src->m_type: decrements the counter or calls FUN_00df9840, and for types 5 and 7 builds a JobA or JobB in out and returns 0, else returns 1.
// @fnv 0x00df9920
// src: HAVOK_LIB 0x00df9920
int __cdecl hkpRayCastQueryJobQueueUtils_finishRayCastQueryJob(void* a1, void* a2, JobSrc* src, JobOut* out)
{
    int* counter = src->m_pCounter;
    switch (src->m_type)
    {
    case 0:
    case 1:
    case 4:
        if (--*counter == 0)
            src->ProcessState_00df9840();
        break;
    case 2:
        src->ProcessState_00df9840();
        break;
    case 5:
        if (counter)
            --*counter;
        if (!src->m_60)
        {
            src->ProcessState_00df9840();
            break;
        }
        if (*counter)
            break;
        new (&out->m_10) JobA(src->m_pCounter);
        out->m_iWordAt00 = 0;
        CopyFields(src, &out->m_10);
        return 0;
    case 3:
        if (src->m_i38 < 8)
            src->ProcessState_00df9840();
        break;
    case 6:
        if (*counter == 0)
            src->ProcessState_00df9840();
        break;
    case 7: {
        new (&out->m_10) JobB(src->m_54, src->m_p58, src->m_44, src->m_48, src->m_60, src->m_5c);
        JobB* job = (JobB*)&out->m_10;
        job->m_38 = src->m_64;
        job->m_3c = src->m_68;
        job->m_40 = src->m_6c;
        job->m_2c = src->m_4c;
        job->m_30 = src->m_50;
        out->m_iWordAt00 = 1;
        out->m_12 = 1;
        return 0;
    }
    }
    return 1;
}

// @fnv 0x00df9ad0
// src: GUESS 0x00df9ad0 (confidence: high)
void Runtime_DoNothing_00df9ad0()
{}

class SolBool
{
    char value;

  public:
    inline SolBool()
    {}
    inline SolBool(bool b)
    {
        value = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return value != 0;
    }
    inline SolBool& operator=(bool b)
    {
        value = static_cast<char>(b);
        return *this;
    }
};
typedef __m128 Bndm128;
struct __declspec(align(16)) BndBounds
{
    unsigned short minimum[3];
    unsigned short idHigh;
    unsigned short maximum[3];
    unsigned short idLow;
    void operator=(const BndBounds& v)
    {
        *(Bndm128*)this = *(const Bndm128*)&v;
    }
};
struct BndBuffers
{
    BndBounds* source;
    BndBounds* destination;
};
struct BndSplit
{
    int axis;
    int middle;
    unsigned short rightMinimum;
    unsigned short leftMaximum;
};
// Partitions BndBounds entries into left/right destination buffers using the longest axis mean, fills BndSplit, and swaps source/destination pointers.
// @fnv 0x00df33b0
// src: GUESS 0x00df33b0 (confidence: medium)
int __cdecl Runtime_PartitionBoundsOnLongestAxis(const BndBuffers* buffers, int begin, int end, BndSplit* split, BndBuffers* swapped,
                         const BndBounds* bounds)
{
    int rightCount;
    const BndBounds* input = buffers->source + begin;
    int count = end - begin;
    unsigned short extentX = bounds->maximum[0] - bounds->minimum[0];
    unsigned short extentY = bounds->maximum[1] - bounds->minimum[1];
    unsigned short extentZ = bounds->maximum[2] - bounds->minimum[2];
    unsigned int axis;
    if (extentX > extentY)
        axis = extentZ < extentX ? 0 : 2;
    else
        axis = extentZ < extentY ? 1 : 2;
    int leftCount;
    leftCount = 0;
    rightCount = 0;
    int sum = 0;
    const BndBounds* entry;
    entry = input;
    for (int i = 0; i < count; i++, entry++)
        sum += (entry->minimum[(short)axis] + entry->maximum[(short)axis]) >> 1;
    int mean = sum / count;
    entry = input;
    for (int i = 0; i < count; i++, entry++)
    {
        leftCount += entry->minimum[(short)axis] <= mean;
        rightCount += entry->maximum[(short)axis] >= mean;
    }
    SolBool degenerate = leftCount == 0 || rightCount == 0;
    if (leftCount == rightCount && leftCount == count)
        return 1;
    unsigned short rightMinimum = bounds->maximum[(short)axis];
    unsigned short leftMaximum = bounds->minimum[(short)axis];
    int middle;
    BndBounds* __restrict left = buffers->destination + begin;
    entry = input;
    if (degenerate)
    {
        middle = begin + (count >> 1);
        int i;
        for (i = 0; i < (count >> 1); ++i, ++entry, ++left)
        {
            *left = *entry;
            leftMaximum = leftMaximum > entry->maximum[(short)axis] ? leftMaximum : entry->maximum[(short)axis];
        }
        for (; i < count; ++i, ++entry, ++left)
        {
            *left = *entry;
            rightMinimum = rightMinimum < entry->minimum[(short)axis] ? rightMinimum : entry->minimum[(short)axis];
        }
    }
    else if (leftCount < rightCount)
    {
        middle = begin + leftCount;
        BndBounds* __restrict right;
        right = middle + buffers->destination;
        for (int i = 0; i < count; i++, entry++)
        {
            unsigned short minimum = entry->minimum[(short)axis];
            unsigned short maximum;
            maximum = entry->maximum[(short)axis];
            if (minimum > mean)
            {
                *right = *entry;
                right++;
                if (rightMinimum >= minimum)
                    rightMinimum = minimum;
            }
            else
            {
                *left = *entry;
                ++left;
                if (leftMaximum <= maximum)
                    leftMaximum = maximum;
            }
        }
    }
    else
    {
        middle = begin + (count - rightCount);
        BndBounds* __restrict right = buffers->destination + middle;
        for (int i = 0; i < count; i++, entry++)
        {
            unsigned short minimum = entry->minimum[(short)axis];
            unsigned short maximum = entry->maximum[(short)axis];
            if (maximum >= mean)
            {
                *right = *entry;
                right++;
                if (rightMinimum >= minimum)
                    rightMinimum = minimum;
            }
            else
            {
                *left = *entry;
                left++;
                if (leftMaximum <= maximum)
                    leftMaximum = maximum;
            }
        }
    }
    split->rightMinimum = rightMinimum;
    split->leftMaximum = leftMaximum;
    split->axis = axis;
    split->middle = middle;
    swapped->destination = buffers->source;
    swapped->source = buffers->destination;
    return 0;
}

extern "C" void _ReadWriteBarrier(void);
// Today's tree (blk_00de0000_o2.cpp) has no windows.h; declare the Win32 pieces the
// way the unit itself does (see the TlsGetValue profile macro users in the file).
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);

extern unsigned long DAT_0126835c;

class TaskTarget
{
  public:
    unsigned long unk00, unk04, unk08, unk0C, unk10, unk14;
    unsigned long m_18;
    unsigned long unk1C, unk20, unk24, unk28, unk2C;
    unsigned long unk30;
    unsigned long m_34;
    unsigned long m_38;
};

void __cdecl hkCpuPairLinearCastImplementation(void* a, void* b, void* c, void* d);
struct FUN_00d04e80_cls
{
    void ProcessCallback(void* b, void* c, unsigned int d);
};

typedef void*(__stdcall* PFN_TlsGetValue)(unsigned long dwTlsIndex);

// Records a TtCollQueryPairLinearCast profiler tick, calls FUN_00df7760 on a2's fields, records an Et tick, then calls ProcessCallback on a1.
// @fnv 0x00df79d0
// src: HAVOK_LIB 0x00df79d0
void __cdecl hkCpuPairLinearCastJob(void* a1, TaskTarget* a2)
{
    PFN_TlsGetValue pfnTls = TlsGetValue;
    hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtCollQueryPairLinearCast";
        _ReadWriteBarrier();
        volatile unsigned long ticks = (unsigned long)__rdtsc();
        pRec->m_time0 = ticks;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    hkCpuPairLinearCastImplementation(a2, (void*)a2->m_18, (void*)a2->m_34, (void*)a2->m_38);

    pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        volatile unsigned long ticks = (unsigned long)__rdtsc();
        pRec->m_time0 = ticks;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    ((FUN_00d04e80_cls*)a1)->ProcessCallback(a2, a2, 0);
}

extern "C" void _mm_store_ps(float*, __m128);
struct PulleyObjectBase
{
    int* vtable;
    unsigned short unk04;
    volatile unsigned short referenceCount;
    volatile unsigned int userData;

    PulleyObjectBase()
    {
        referenceCount = 1;
        userData = 0;
    }
};

struct FUN_00deefd0 : PulleyObjectBase
{
    unsigned int unk0c;
    unsigned short translationType;
    __m128 translationA;
    __m128 translationB;
    unsigned short pulleyType;
    __m128 fixedPivotA;
    __m128 fixedPivotB;
    volatile float ropeLength;
    volatile float leverage;

    FUN_00deefd0();
};

// Default-constructs a pulley: sets translationType to 3, pulleyType to 0x14, ropeLength to 0.0, leverage to 1.0, and zeroes the translation and pivot vectors.
// @fnv 0x00deefd0
FUN_00deefd0::FUN_00deefd0()
{
    vtable = &DAT_010da04c;
    translationType = 3;
    pulleyType = 0x14;
    ropeLength = 0.0f;
    leverage = 1.0f;
    _mm_store_ps(reinterpret_cast<float*>(&translationA), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&translationB), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&fixedPivotA), _mm_setzero_ps());
    _mm_store_ps(reinterpret_cast<float*>(&fixedPivotB), _mm_setzero_ps());
}

template <class T>
static __forceinline void SuspensionArray_destroy(hkArrayBase<T>& self) throw()
{
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        hkMemoryAllocator& allocator = *reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            allocator.bufFree(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct SuspensionArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { SuspensionArray_destroy(self); }
};

struct SuspensionWheel
{
    __m128 m_hardpoint;
    __m128 m_direction;
    float m_fRestLength;
};

struct SuspensionSpring
{
    float m_fSpringStrength;
    float m_compression;
    float m_relaxation;
};

class SuspensionObject
{
  public:
    ~SuspensionObject() throw()
    {
        m_ppVirtualMethodTable = &DAT_0102e388;
    }
    int* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00dfbf70 : public SuspensionObject
{
  public:
    ~FUN_00dfbf70() throw();
    hkArray<SuspensionWheel, SuspensionArrayPolicy> m_wheels;
    hkArray<SuspensionSpring, SuspensionArrayPolicy> m_springs;
};

// Destructor for the suspension object that owns m_wheels and m_springs arrays.
// @fnv 0x00dfbf70
FUN_00dfbf70::~FUN_00dfbf70() throw()
{}

extern "C" void _mm_store_ps(float*, __m128);

extern "C" int DAT_010d8274;

struct FUN_00de4a80
{
    unsigned int unk00;
    unsigned short unk04;
    volatile unsigned short m_06;
    volatile unsigned int m_08;
    unsigned int unk0c;
    volatile float m_10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    volatile float m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    volatile float m_38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    volatile int m_50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    volatile float m_90;
    volatile float m_94;
    volatile float m_98;
    volatile int m_9c;

    FUN_00de4a80();
};

// Stores &DAT_010d8274 at offset 0, sets m_06=1, m_50=5, m_10/m_24/m_38=1.0f, and zeroes m_08, m_90-m_9c and several 16-byte blocks.
// @fnv 0x00de4a80
FUN_00de4a80::FUN_00de4a80()
{
    int zero = 0;
    m_06 = 1;
    m_50 = 5;
    m_08 = zero;
    _mm_store_ps((float*)((char*)this + 0x10), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x20), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x30), _mm_setzero_ps());
    m_10 = 1.0f;
    m_24 = 1.0f;
    m_38 = 1.0f;
    _mm_store_ps((float*)((char*)this + 0x40), _mm_setzero_ps());
    *(int**)this = &DAT_010d8274;
    m_90 = 0.0f;
    m_9c = zero;
    m_94 = 0.0f;
    _mm_store_ps((float*)((char*)this + 0x60), _mm_setzero_ps());
    m_98 = 0.0f;
    _mm_store_ps((float*)((char*)this + 0x80), _mm_setzero_ps());
    _mm_store_ps((float*)((char*)this + 0x70), _mm_setzero_ps());
}

extern char str_010dba74[];
typedef __m128 S00df8440_V;
extern S00df8440_V DAT_012684d0;

struct S00df8440_Job
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int unk3c;
    S00df8440_V m_40;
    int* m_50;
    int m_54;
    int m_58;
};

struct S00df8440_Pair
{
    int m_kPointA;
    int m_kPointB;
};

// same layout as the unit's FUN_00df3110; its constructor is only declared here, so this function is compiled
// without knowing what that constructor clobbers (the original was compiled before it)
struct S00df8440_BuilderBase
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
    int m_iArrayLength;
    S00df8440_BuilderBase();
};

struct __declspec(align(16)) S00df8440_Builder : S00df8440_BuilderBase
{
    void hkKdTreeBuilderSparseWriter_flush();
};

struct S00df8440_Desc
{
    S00df8440_Pair* m_pPair;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int unk14;
    int unk18;
    int unk1c;
    union
    {
        S00df8440_V m_20;
    };
    S00df8440_Builder* m_pDescriptionBuilder;
    int unk34;
    int unk38;
    int unk3c;
    union
    {
        S00df8440_V m_40;
    };
};

int __cdecl hkKdTreeBuilder_hkKdTreeProjectedEntry_const_hkKdTreeProjectedEntry_restrict_0_buildTreeRecursive(S00df8440_Desc* desc, int* a, int b, int* c, int* d);

struct S00df8440_Owner
{
    int ProcessCallback(S00df8440_Job* a, S00df8440_Job* b, int c);
};

static inline void S00df8440_TimerEnd(const char* name)
{
    MonitorStreamKd* s = (MonitorStreamKd*)TlsGetValue(DAT_0126835c);
    TimerCommandKd* h = (TimerCommandKd*)s->m_kRayEnd;
    if ((char*)h < s->m_capacityEnd)
    {
        h->m_name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
// Builds a Desc from job fields, calls FUN_00df56a0, stores 2 plus its result through job->m_50, then calls owner->ProcessCallback and returns its result.
// @fnv 0x00df8440
// src: XBOX_PDB 0x00df8440
int __cdecl hkCpuKdTreeBuildFastDistributedSubJob(S00df8440_Owner* owner, S00df8440_Job* job)
{
    TimerCommandKdWrite(str_010dba74);
    S00df8440_Pair pair;
    pair.m_kPointA = job->m_2c;
    pair.m_kPointB = job->m_30;
    S00df8440_Desc desc;
    desc.m_pPair = &pair;
    desc.m_04 = job->m_28;
    desc.m_40 = DAT_012684d0;
    desc.m_0c = job->m_34;
    desc.m_10 = job->m_38;
    desc.m_20 = job->m_40;
    desc.m_08 = job->m_54;
    S00df8440_Builder q;
    desc.m_pDescriptionBuilder = &q;
    int res = job->m_58;
    int d = res;
    int x = 1;
    int obj = job->m_20;
    int tmp3 = hkKdTreeBuilder_hkKdTreeProjectedEntry_const_hkKdTreeProjectedEntry_restrict_0_buildTreeRecursive(&desc, &obj, job->m_24, &x, &d);
    *job->m_50 = 2 + tmp3;
    int result = owner->ProcessCallback(job, job, 0);
    q.hkKdTreeBuilderSparseWriter_flush();
    S00df8440_TimerEnd(DAT_010c41f8);
    return result;
}

extern double DAT_01032980;
namespace SimpleQuad {
// Exe 0x00df2750 _FUN_00df2750: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef struct __declspec(intrin_type) __declspec(align(16)) {
    float x, y, z, w;
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps();
extern "C"
{
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_rcp_ps(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_or_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    void _mm_store_ss(float*, LocalM128);
    extern const LocalM128 DAT_010c7170;
    extern const LocalM128 DAT_010c4c10;
    extern const int DAT_010c92e0[];
}
struct __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int x, y, z, w;
};
extern "C"
{
    __m128i _mm_setzero_si128();
    __m128i _mm_unpacklo_epi16(__m128i, __m128i);
    __m128i _mm_unpackhi_epi16(__m128i, __m128i);
    __m128i _mm_slli_epi32(__m128i, int);
    __m128i _mm_srli_epi32(__m128i, int);
    LocalM128 _mm_cvtepi32_ps(__m128i);
}
class ByteAnswer
{
    char value;

  public:
    __forceinline ByteAnswer()
    {}
    __forceinline ByteAnswer(bool b) : value((char)b)
    {}
    __forceinline operator bool() const
    {
        return value != 0;
    }
};
class ScalarValue
{
    LocalM128 value;

  public:
    __forceinline ScalarValue()
    {}
    __forceinline ScalarValue(LocalM128 v) : value(v)
    {}
    __forceinline const LocalM128& quad() const
    {
        return value;
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline operator float() const
    {
        float r;
        _mm_store_ss(&r, value);
        return r;
    }
};
class PVec;
class MaskCell
{
    union
    {
        LocalM128 bits;
    };

  public:
    __forceinline operator const LocalM128&() const
    {
        return bits;
    }
    __forceinline void operator=(const LocalM128& x)
    {
        bits = x;
    }
};
class PMask
{
    MaskCell value;
    friend class PVec;

  public:
    enum Bits
    {
        None = 0,
        X = 1,
        Y = 2,
        Z = 4,
        W = 8,
        XYZ = 7
    };
    __forceinline int tracked(Bits m, int& out) const
    {
        out = _mm_movemask_ps(value);
        return (out & m) == m;
    }
    __forceinline void both(const PMask& a, const PMask& b)
    {
        value = _mm_and_ps(a.value, b.value);
    }
    __forceinline void pick(const PMask& a, const PMask& b, const PMask& m)
    {
        value = _mm_or_ps(_mm_and_ps(m.value, b.value), _mm_andnot_ps(m.value, a.value));
    }
    __forceinline int all(const Bits& m) const
    {
        return (_mm_movemask_ps(value) & m) == m;
    }
};
class PVec
{
    LocalM128 value;

  public:
    __forceinline void operator=(const PVec& v)
    {
        value = v.value;
    }
    __forceinline void operator=(const LocalM128& v)
    {
        value = v;
    }
    __forceinline LocalM128& quad()
    {
        return value;
    }
    __forceinline const LocalM128& quad() const
    {
        return value;
    }
    __forceinline float& at(int i)
    {
        return ((float*)&value)[i];
    }
    __forceinline const float& at(int i) const
    {
        return ((const float*)&value)[i];
    }
    __forceinline void zero()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void uniform(float x)
    {
        value = _mm_set_ps1(x);
    }
    __forceinline void sub(const PVec& a, const PVec& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void sub(const PVec& a)
    {
        value = _mm_sub_ps(value, a.value);
    }
    __forceinline void add(const PVec& a)
    {
        value = _mm_add_ps(value, a.value);
    }
    __forceinline void mul(const PVec& a)
    {
        value = _mm_mul_ps(value, a.value);
    }
    __forceinline void mul(const PVec& a, const PVec& b)
    {
        value = _mm_mul_ps(a.value, b.value);
    }
    __forceinline void min(const PVec& a, const PVec& b)
    {
        value = _mm_min_ps(a.quad(), b.quad());
    }
    __forceinline void max(const PVec& a, const PVec& b)
    {
        value = _mm_max_ps(a.quad(), b.quad());
    }
    __forceinline void broadcast(const PVec& a, int lane)
    {
        if (lane == 0)
            value = _mm_shuffle_ps(a.value, a.value, 0);
        else if (lane == 1)
            value = _mm_shuffle_ps(a.value, a.value, 85);
        else if (lane == 2)
            value = _mm_shuffle_ps(a.value, a.value, 170);
        else if (lane == 3)
            value = _mm_shuffle_ps(a.value, a.value, 255);
    }
    __forceinline void pick(const PVec& a, const PVec& b, const PMask& m)
    {
        value = _mm_or_ps(_mm_and_ps(m.value, b.value), _mm_andnot_ps(m.value, a.value));
    }
    __forceinline PMask equal(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmpeq_ps(value, a.value);
        return r;
    }
    __forceinline PMask ge(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmple_ps(a.value, value);
        return r;
    }
    __forceinline PMask le(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmple_ps(value, a.value);
        return r;
    }
    __forceinline PMask lt(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmplt_ps(value, a.value);
        return r;
    }
    __forceinline PMask gt(const PVec& a) const
    {
        PMask r;
        r.value = _mm_cmplt_ps(a.value, value);
        return r;
    }
    __forceinline ScalarValue dot3(const PVec& a) const
    {
        LocalM128 p = _mm_mul_ps(value, a.value);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 85), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 170), xy);
    }
    __forceinline ScalarValue invLength() const
    {
        LocalM128 half = _mm_set_ss(.5f), three = _mm_set_ss(3.f), z = _mm_set_ss(0.f);
        LocalM128 l = dot3(*this).quad(), eq = _mm_cmpeq_ss(l, z), r = _mm_rsqrt_ss(l);
        LocalM128 n = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(l, r), r)));
        return _mm_andnot_ps(eq, n);
    }
    __forceinline ScalarValue normalize()
    {
        LocalM128 l = dot3(*this).quad();
        LocalM128 r = invLength().broadcast();
        value = _mm_mul_ps(r, value);
        return _mm_mul_ss(l, r);
    }
    __forceinline void inverse3(const PVec& a)
    {
        LocalM128 b = _mm_shuffle_ps(a.value, _mm_unpackhi_ps(a.value, DAT_010c7170), 196);
        LocalM128 r = _mm_rcp_ps(b);
        value = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, b), r));
    }
    __forceinline void xyz0(const PVec& a)
    {
        value = _mm_and_ps(a.value, DAT_010c4c10);
    }
    __forceinline void addMul(const PVec& origin, const PVec& scale, const PVec& v)
    {
        value = _mm_add_ps(origin.value, _mm_mul_ps(scale.value, v.value));
    }
};
struct PBox
{
    PVec lo, hi;
};
class PInts
{
    __m128i value;

  public:
    __forceinline void zero()
    {
        value = _mm_setzero_si128();
    }
    __forceinline void first(const PInts& a, const PInts& b)
    {
        value = _mm_unpacklo_epi16(a.value, b.value);
    }
    __forceinline void second(const PInts& a, const PInts& b)
    {
        value = _mm_unpackhi_epi16(a.value, b.value);
    }
    __forceinline void toFloat(PVec& out) const
    {
        const LocalM128 factor = {1.0e16f, 1.0e16f, 1.0e16f, 1.0e16f};
        __m128i v = value;
        {
            __m128i high = _mm_srli_epi32(v, 16);
            __m128i low = _mm_srli_epi32(_mm_slli_epi32(v, 16), 16);
            LocalM128 h = _mm_mul_ps(_mm_cvtepi32_ps(high), factor);
            LocalM128 l = _mm_cvtepi32_ps(low);
            out.quad() = _mm_add_ps(h, l);
        }
    }
};
struct PEntry
{
    union Id
    {
        unsigned value;
        unsigned short halves[2];
        __forceinline const unsigned& get() const
        {
            return value;
        }
    };
    __declspec(align(16)) unsigned short lo[3];
    unsigned short firstId;
    unsigned short hi[3];
    unsigned short secondId;
    __forceinline Id id() const
    {
        Id r;
        r.halves[0] = firstId;
        r.halves[1] = secondId;
        return r;
    }
};
class PNode
{
  public:
    int children;
    union
    {
        int bounds;
        struct
        {
            unsigned short lower, upper;
        };
    };
    __forceinline PNode() : children(0x7fffffff), bounds(0)
    {}
    __forceinline ~PNode()
    {}
    __forceinline int leaf() const
    {
        return ~(children >> 31);
    }
    __forceinline int empty() const
    {
        return ~(children ^ 0x7fffffff);
    }
    __forceinline int axis() const
    {
        return children & 3;
    }
    __forceinline unsigned short min() const
    {
        return lower;
    }
    __forceinline unsigned short max() const
    {
        return upper;
    }
    __forceinline unsigned id() const
    {
        return children & 0x7fffffff;
    }
    __forceinline unsigned count() const
    {
        return bounds;
    }
    __forceinline PNode* left() const
    {
        return (PNode*)((unsigned)this + (children & 0x7ffffffc));
    }
    __forceinline PNode* right() const
    {
        return left() + 1;
    }
};
struct PTree
{
    PNode* root;
    int unk04, unk08, depth;
    int unk10, unk14, unk18;
    PEntry* leaves;
    int unk20, unk24, unk28, unk2c;
    PBox bounds;
};
struct PCast
{
    PVec from, to, half;
};
struct PCollector
{
    virtual ~PCollector()
    {}
    virtual ByteAnswer process(unsigned) = 0;
    virtual ByteAnswer finish() = 0;
    virtual float fraction() = 0;
};
struct PState
{
    __declspec(align(16)) const PNode* node;
    float nearD, farD;
    unsigned unused;
    __forceinline void set(const PNode* n, float a, float b)
    {
        node = n;
        nearD = a;
        farD = b;
    }
};
template <class T> static __forceinline T* reserveStack(int count)
{
    hkMemoryRouter* p = hkMemoryRouter_getInstance();
    T* r = (T*)p->m_stack.m_next.m_storage;
    p->m_stack.m_next.m_storage = (char*)p->m_stack.m_next.m_storage + (((sizeof(T) * count + 127) & ~127));
    return r;
}
template <class T> static __forceinline void restoreStack(T* p)
{
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage =(void*)( (void*)((int)p));
}
static __forceinline float pmin(float a, float b)
{
    return a < b ? a : b;
}
static __forceinline float pmax(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline void swapFloat(float& a, float& b)
{
    float t = a;
    a = b;
    b = t;
}
static __forceinline float splitReal(unsigned short q, float origin, float span)
{
    return float(q) / 65535.0f * span + origin;
}
static __forceinline const PNode* getNode(const PNode* p, ByteAnswer)
{
    return p;
}
static __forceinline const PNode* leftNode(const PNode&, const PNode* p)
{
    return p->left();
}
static __forceinline const PNode* rightNode(const PNode&, const PNode* p)
{
    return p->right();
}
static __forceinline const PEntry* projectedNode(const PNode& n, const PEntry* base, int i)
{
    const int first = n.id();
    const PEntry* const r = base + first + i;
    return r;
}
static __forceinline int flatAxis(const PVec& v, int axis, int& out)
{
    PVec z;
    z.zero();
    PMask m = v.equal(z);
    return m.tracked((PMask::Bits)DAT_010c92e0[axis], out);
}
static __forceinline int positiveAxis(const PVec& v, int axis)
{
    PVec z;
    z.zero();
    PMask m = v.gt(z);
    return m.all((PMask::Bits)DAT_010c92e0[axis]);
}
static __forceinline void broadcastMax(PVec& v, const PMask& ignore)
{
    LocalM128 k = {-3.40282e38f, -3.40282e38f, -3.40282e38f, -3.40282e38f};
    PVec x, y, z, t;
    PVec bound;
    bound.quad() = k;
    v.pick(v, bound, ignore);
    x.broadcast(v, 0);
    y.broadcast(v, 1);
    t.max(x, y);
    z.broadcast(v, 2);
    v.max(t, z);
}
static __forceinline void broadcastMin(PVec& v, const PMask& ignore)
{
    LocalM128 k = {3.40282e38f, 3.40282e38f, 3.40282e38f, 3.40282e38f};
    PVec x, y, z, t;
    PVec bound;
    bound.quad() = k;
    v.pick(v, bound, ignore);
    x.broadcast(v, 0);
    y.broadcast(v, 1);
    t.min(x, y);
    z.broadcast(v, 2);
    v.min(t, z);
}
static __forceinline int hitsBox(const PVec& origin, const PVec& inverse, float nearD, float farD, const PBox& box)
{
    PVec a;
    a = box.lo;
    PVec b;
    b = box.hi;
    a.sub(origin);
    b.sub(origin);
    a.mul(inverse);
    b.mul(inverse);
    PVec zero;
    zero.zero();
    PMask sign = inverse.ge(zero);
    PVec lower, upper;
    lower.pick(b, a, sign);
    upper.pick(a, b, sign);
    PVec nearV, farV;
    nearV.uniform(nearD);
    farV.uniform(farD);
    PMask flat;
    flat = inverse.equal(zero);
    PMask inside = origin.ge(box.lo);
    inside.both(inside, origin.le(box.hi));
    broadcastMax(lower, flat);
    broadcastMin(upper, flat);
    nearV.max(nearV, lower);
    farV.min(farV, upper);
    PMask valid = nearV.lt(farV);
    PMask result;
    result.pick(valid, inside, flat);
    return result.all(PMask::XYZ);
}
static __forceinline void decodeEntry(const PEntry* entry, PBox& box, const PVec& origin, const PVec& range)
{
    PVec scale;
    scale.quad() = *(const LocalM128*)&::DAT_011b9490;
    scale.mul(range);
    PInts packed = *(PInts*)entry;
    PInts zero;
    zero.zero();
    PInts lower, upper;
    lower.first(packed, zero);
    upper.second(packed, zero);
    PVec lo, hi;
    lower.toFloat(lo);
    upper.toFloat(hi);
    box.lo.addMul(origin, scale, lo);
    box.hi.addMul(origin, scale, hi);
}
}
using namespace SimpleQuad;
struct TraversalCursor
{
    float nearD;
    PState* stack;
};
struct PhaseVector
{
    SimpleQuad::LocalM128 value;
};
struct LeafCursor
{
    const PEntry* leaves;
    int mask;
    LeafCursor(const PEntry* p) : leaves(p)
    {}
};
// Traverses a PTree with a cast ray, testing leaf bounding boxes against the ray and passing hits to the sink.
// @fnv 0x00df2750
// src: XBOX_PDB 0x00df2750
extern "C" ByteAnswer __cdecl hkKdTreeAabbCastUtils_castAabb(const PTree* tree, PCast& input, PCollector* sink, float margin)
{
    const PNode* node = tree->root;
    const PEntry* leaves = tree->leaves;
    int mask;
    const PVec offset = tree->bounds.lo;
    PVec scale;
    scale.sub(tree->bounds.hi, tree->bounds.lo);
    int capacity = tree->depth > 0 ? tree->depth : 128;
    PNode nodeCopy = *getNode(node, true);
    PState* base = reserveStack<PState>(capacity);
    TraversalCursor traversal;
    traversal.stack = base;
    PVec start = input.from;
    PVec inverse;
    PhaseVector phase = *(const PhaseVector*)&input.to;
    PVec dir;
    dir.sub(*(const PVec*)&phase, start);
    float length = dir.normalize();
    phase = *(const PhaseVector*)&input.half;
    PVec tolerance;
    tolerance.uniform(margin);
    tolerance.add(*(const PVec*)&phase);
    traversal.nearD = 0;
    float farD = length;
    PVec origin = start;
    PMask flat;
    PVec persistentZero;
    persistentZero.quad() = SimpleQuad::_mm_setzero_ps();
    {
        PVec one;
        one.quad() = DAT_010c7170;
        const PVec& zero = persistentZero;
        flat = dir.equal(zero);
        PVec safe;
        safe.pick(dir, one, flat);
        inverse.inverse3(safe);
        inverse.xyz0(inverse);
        inverse.pick(inverse, zero, flat);
    }
    float limit = pmin(sink->fraction() * length, farD);

    if (!flat.all(PMask::XYZ))
    {
        for (;;)
        {
            while (~nodeCopy.leaf())
            {
                const PNode* left = leftNode(nodeCopy, node);
                const PNode* right = rightNode(nodeCopy, node);
                int axis = nodeCopy.axis();
                if (flatAxis(dir, axis, mask))
                {
                    float work =
                        splitReal(nodeCopy.min(), offset.at(axis), scale.at(axis)) - ((const PVec*)&phase)->at(axis);
                    float high =
                        splitReal(nodeCopy.max(), offset.at(axis), scale.at(axis)) + ((const PVec*)&phase)->at(axis);
                    int goLeft = origin.at(axis) <= (float)(high + DAT_01032980);
                    int goRight = origin.at(axis) >= (float)(work - DAT_01032980);
                    if (goLeft && goRight)
                    {
                        node = left;
                        traversal.stack->set(right, traversal.nearD, farD);
                        ++traversal.stack;
                    }
                    else if (goLeft || goRight)
                        node = goLeft ? left : right;
                    else
                        goto pop;
                    nodeCopy = *getNode(node, true);
                    continue;
                }
                else
                {
                    float low =
                        splitReal(nodeCopy.min(), offset.at(axis), scale.at(axis)) - ((const PVec*)&phase)->at(axis);
                    float high =
                        splitReal(nodeCopy.max(), offset.at(axis), scale.at(axis)) + ((const PVec*)&phase)->at(axis);
                    float enter = (low - origin.at(axis)) * inverse.at(axis);
                    float leave = (high - origin.at(axis)) * inverse.at(axis);
                    const PNode* first;
                    const PNode* second;
                    if (positiveAxis(dir, axis))
                    {
                        first = left;
                        second = right;
                    }
                    else
                    {
                        first = right;
                        second = left;
                        swapFloat(enter, leave);
                    }
                    if (traversal.nearD > leave)
                        node = second;
                    else if (enter > limit)
                        node = first;
                    else
                    {
                        traversal.stack->set(second, pmax(enter, traversal.nearD), farD);
                        ++traversal.stack;
                        node = first;
                        farD = pmin(leave, farD);
                        limit = pmin(sink->fraction() * length, farD);
                    }
                    nodeCopy = *getNode(node, true);
                }
            }
            if (~nodeCopy.empty())
            {
                int count = nodeCopy.count();
                for (int i = 0; i < count; ++i)
                {
                    const PEntry* entry = projectedNode(nodeCopy, leaves, i);
                    PEntry::Id id = entry->id();
                    PBox box;
                    decodeEntry(entry, box, offset, scale);
                    box.hi.add(tolerance);
                    box.lo.sub(tolerance);
                    if (hitsBox(origin, inverse, traversal.nearD, limit, box))
                    {
                        ByteAnswer hit = sink->process(id.get());
                    }
                }
            }
        pop:
            if (traversal.stack == base)
                break;
            --traversal.stack;
            node = traversal.stack->node;
            nodeCopy = *getNode(node, true);
            farD = traversal.stack->farD;
            traversal.nearD = traversal.stack->nearD;
            limit = pmin(sink->fraction() * length, farD);
            if (limit <= traversal.nearD)
                goto pop;
        }
    }
    restoreStack(base);
    return sink->finish();
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    A::destroy(*this);
}
