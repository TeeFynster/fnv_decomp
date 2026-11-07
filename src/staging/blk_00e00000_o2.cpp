#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../include/hkArray.h"

// src/staging/blk_00e00000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/BSAudio.h"
#include "../../include/hkMemoryRouter.h"
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" float _mm_cvtss_f32(LocalM128 a);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
#define FNV_VECTOR_USE_LOCAL_SSE
#include "../../include/hkVector4.h"
#undef FNV_VECTOR_USE_LOCAL_SSE

#include "../../include/FinishingFlag.h"
#include "../../include/hkSmallArray.h"
#define FNV_VEC4_NO_SSE
#include "../../include/Vec4.h"
#undef FNV_VEC4_NO_SSE


template <class T> __forceinline T& GetRouterHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<T*>(router.m_heap);
}


inline hkMemoryAllocator& BSAudio::heap()
{
    return *reinterpret_cast<hkMemoryAllocator*>(pListener);
}

extern int DAT_010305a8;
extern int DAT_010c749c;

// If a is non-null, sets *a to DAT_010305a8, clears a[3] when b is set, then sets *a to DAT_010c749c and a[3] to 3.
// @fnv 0x00e00570
// src: HAVOK_LIB 0x00e00570
void __cdecl finishLoadedObjecthkpTriangleShape(int* pObject, int b)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (b)
            pObject[3] = 0;
        *pObject = (int)&DAT_010c749c;
        pObject[3] = 3;
    }
}

extern int DAT_010305a8;
extern int DAT_010cb5ac;

// @fnv 0x00e007b0
// src: HAVOK_LIB 0x00e007b0
void finishLoadedObjecthkpSphereShape(int* pObject, int flag)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (flag)
            pObject[3] = 0;
        *pObject = (int)&DAT_010cb5ac;
        pObject[3] = 1;
    }
}

namespace fnv_00e009e0 {
extern "C" void* DAT_010305a8;
extern "C" void* DAT_010d0e18;
struct FUN_00e009e0_T
{
    void* a;
    void* b;
    void* c;
    int d;
};
// If p is non-null, sets p->a to DAT_010305a8, optionally clears p->d, then sets p->a to DAT_010d0e18 and p->d to 0x1c.
// @fnv 0x00e009e0
// src: GUESS 0x00e009e0 (confidence: low)
void __cdecl Object_UpdateFields_00e009e0(FUN_00e009e0_T* pObject, int flag)
{
    if (pObject)
    {
        pObject->a = &DAT_010305a8;
        if (flag)
            pObject->d = 0;
        pObject->a = &DAT_010d0e18;
        pObject->d = 0x1c;
    }
}
}  // namespace fnv_00e009e0

extern int DAT_010305a8;
extern int DAT_010ce4bc;

// @fnv 0x00e00b00
// src: COMMUNITY 0x00e00b00
void hkpMultiSphereShape_hkpMultiSphereShape_0(int* pObject, int flag)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (flag)
            pObject[3] = 0;
        *pObject = (int)&DAT_010ce4bc;
        pObject[3] = 0x15;
    }
}

extern int DAT_010305a8;
extern int DAT_010ce25c;
// If a is non-null, sets *a to &DAT_010305a8, optionally clears a[3] when b is set, then sets *a to &DAT_010ce25c and a[3] to 5.
// @fnv 0x00e01340
// src: HAVOK_LIB 0x00e01340
void finishLoadedObjecthkpCapsuleShape(int* pObject, int b)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (b)
            pObject[3] = 0;
        *pObject = (int)&DAT_010ce25c;
        pObject[3] = 5;
    }
}

extern int DAT_010305a8;
extern int DAT_010c70b4;

// If p is non-null, sets p[0] to DAT_010305a8, clears p[3] when a is set, then sets p[0] to DAT_010c70b4 and p[3] to 4.
// @fnv 0x00e01410
// src: HAVOK_LIB 0x00e01410
void __cdecl finishLoadedObjecthkpBoxShape(int* pObject, int a)
{
    if (pObject)
    {
        pObject[0] = (int)&DAT_010305a8;
        if (a)
            pObject[3] = 0;
        pObject[0] = (int)&DAT_010c70b4;
        pObject[3] = 4;
    }
}

extern int DAT_010e99d8;
struct FUN_00cb0a70
{
    void __thiscall m(int);
};
// @fnv 0x00e01c30
// src: GUESS 0x00e01c30 (confidence: low)
void Object_UpdateState_00e01c30(void* apObject, void* aValue)
{
    if (apObject)
    {
        *(void**)((char*)apObject) = &DAT_010e99d8;
        ((FUN_00cb0a70*)((char*)apObject + 8))->m((int)aValue);
        ((FUN_00cb0a70*)((char*)apObject + 12))->m((int)aValue);
    }
}

extern int DAT_010c9314;

// @fnv 0x00e02780
// src: GUESS 0x00e02780 (confidence: low)
void Object_UpdateFields_00e02780(void* apObject)
{
    if (apObject)
    {
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(apObject) + 6) = 1;
        *reinterpret_cast<void**>(apObject) = &DAT_010c9314;
    }
}

// @fnv 0x00e030e0
int IsInRange(int aiValue, int aiLowerBound, int aiUpperBound)
{
    return (aiValue >= aiLowerBound && aiValue < aiUpperBound) ? 1 : 0;
}

// @fnv 0x00e04a60
// src: GUESS 0x00e04a60 (confidence: low)
void Object_UpdateFields_00e04a60(void* pData)
{
    if (*(char*)((char*)pData + 0xc) == 0x14 && *(char*)((char*)pData + 0xd) == 2)
    {
        *(char*)((char*)pData + 0xc) = 0x1d;
        *(char*)((char*)pData + 0xd) = 0;
    }
}

struct FUN_00e10740_a
{
    int a;
    float b;
};
struct FUN_00e10740_b
{
    int c;
    float d;
};

// Returns 1 if the float field of p is less than the float field of q, otherwise 0.
// @fnv 0x00e10740
// src: HAVOK_LIB 0x00e10740
int __cdecl hkCompareInfosBySize(const FUN_00e10740_a* pLeft, const FUN_00e10740_b* pRight)
{
    if (pLeft->b < pRight->d)
        return 1;
    return 0;
}

struct FUN_00e11960_cls
{
    int m_2c;
    int hkgpMesh_countParts();
};
// Walks the linked list at offset 0x2c, tracks the largest value at offset 0x30, and returns that maximum plus one.
// @fnv 0x00e11960
// src: HAVOK_LIB 0x00e11960
int FUN_00e11960_cls::hkgpMesh_countParts()
{
    int iMaxValue = -1;
    int* p = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x2c);
    while (p)
    {
        int v = *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x30);
        if (v > iMaxValue)
            iMaxValue = v;
        p = *reinterpret_cast<int**>(reinterpret_cast<char*>(p));
    }
    return iMaxValue + 1;
}

struct FUN_00e11d80_class
{
    void SetValueForAllNodes(int idx, float val);
};

// @fnv 0x00e11d80
void FUN_00e11d80_class::SetValueForAllNodes(int aiIndex, float afValue)
{
    int* p = *(int**)((char*)this + 0x14);
    if (p)
        for (;;)
        {
            *(float*)((char*)p + 0x30 + aiIndex * 4) = afValue;
            p = *(int**)p;
            if (!p)
                break;
        }
}

struct FUN_00e11da0_class
{
    void hkgpMesh_setVerticesTag(int value);
};

// @fnv 0x00e11da0
// src: HAVOK_LIB 0x00e11da0
void FUN_00e11da0_class::hkgpMesh_setVerticesTag(int value)
{
    int* pNode = *(int**)((char*)this + 0x14);
    if (pNode)
    {
        int* next = pNode;
        do
        {
            *(int*)((char*)next + 0x44) = value;
            next = *(int**)((char*)next);
        } while (next);
    }
}

struct FUN_00e000a0_vt
{
    virtual void m(int);
};
// @fnv 0x00e000a0
// src: GUESS 0x00e000a0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e000a0(FUN_00e000a0_vt* p)
{
    p->m(0);
}

extern int DAT_010c59f4;
extern int DAT_010c6cdc;
// @fnv 0x00e00120
// src: GUESS 0x00e00120 (confidence: low)
void __cdecl Object_UpdateFields_00e00120(int* pObject, int bSetHalf)
{
    if (pObject)
    {
        *(int*)pObject = (int)&DAT_010c59f4;
        if (bSetHalf)
        {
            float f = 1.0f;
            *(short*)((char*)pObject + 0x11e) = (short)(*(int*)&f >> 0x10);
        }
        *(int*)pObject = (int)&DAT_010c6cdc;
    }
}

extern int DAT_010e81a4;
// @fnv 0x00e00180
// src: GUESS 0x00e00180 (confidence: low)
void __cdecl Object_UpdateFields_00e00180(int* p)
{
    if (p)
        *p = (int)&DAT_010e81a4;
}

struct FUN_00e002d0_vt
{
    virtual void Runtime_ForwardCall_00e002d0(int);
};
// @fnv 0x00e002d0
// src: GUESS 0x00e002d0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e002d0(FUN_00e002d0_vt* p)
{
    p->Runtime_ForwardCall_00e002d0(0);
}

extern int DAT_010c59f4;
extern int DAT_010c6ea4;
// @fnv 0x00e002f0
// src: GUESS 0x00e002f0 (confidence: low)
void __cdecl Object_UpdateState_00e002f0(int* pObject, int bSetValue)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010c59f4;
        if (bSetValue)
        {
            float f = 1.0f;
            *(short*)((char*)pObject + 0x11e) = (short)(*(int*)&f >> 16);
        }
        *pObject = (int)&DAT_010c6ea4;
    }
}

extern int DAT_010e83b4;
// @fnv 0x00e00350
// src: GUESS 0x00e00350 (confidence: low)
void __cdecl Runtime_UpdateState_00e00350(int* a)
{
    if (a)
        *a = (int)&DAT_010e83b4;
}

// @fnv 0x00e00720
// src: GUESS 0x00e00720 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e00720(void* p)
{
    ((void(__thiscall*)(void*, int))(*((int**)p))[0])(p, 0);
}

extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010cc41c;

// @fnv 0x00e00740
// src: HAVOK_LIB 0x00e00740
void __cdecl finishLoadedObjecthkpTransformShape(int* pObject, int bClear)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (bClear)
            pObject[3] = 0;
        *pObject = (int)&DAT_010cc41c;
        pObject[4] = (int)&DAT_010c6fd0;
        pObject[3] = 15;
    }
}

extern int DAT_010e8824;
// @fnv 0x00e00810
// src: GUESS 0x00e00810 (confidence: low)
void __cdecl Runtime_UpdateState_00e00810(int* p)
{
    if (p)
        *p = (int)&DAT_010e8824;
}

struct FUN_00e00930_vt
{
    virtual void __thiscall m0(int);
};
// @fnv 0x00e00930
// src: GUESS 0x00e00930 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00930(FUN_00e00930_vt* p)
{
    p->m0(0);
}

// @fnv 0x00e00b40
// src: GUESS 0x00e00b40 (confidence: low)
void __cdecl Object_ProcessAndTransformResult_00e00b40(int* p)
{
    ((void(__thiscall*)(void*, int)) * (int*)*p)(p, 0);
}

struct FUN_00e00c70_vt
{
    virtual void __thiscall m0(int);
};
// @fnv 0x00e00c70
// src: GUESS 0x00e00c70 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00c70(FUN_00e00c70_vt* p)
{
    p->m0(0);
}

extern int DAT_010c63cc;

// @fnv 0x00e00d10
// src: GUESS 0x00e00d10 (confidence: low)
void __cdecl Runtime_UpdateState_00e00d10(int* p)
{
    if (p)
        *p = (int)&DAT_010c63cc;
}

// @fnv 0x00e00d30
// src: GUESS 0x00e00d30 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e00d30(int* p)
{
    return (*(int(__thiscall**)(int*, int))(*p))(p, 0);
}

extern int DAT_010e8d8c;

// @fnv 0x00e00db0
// src: GUESS 0x00e00db0 (confidence: low)
void __cdecl Runtime_UpdateState_00e00db0(int* a)
{
    if (a)
        *a = (int)&DAT_010e8d8c;
}

extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010d0e5c;

// @fnv 0x00e00e90
// src: HAVOK_LIB 0x00e00e90
void __cdecl finishLoadedObjecthkpConvexTranslateShape(int* pObject, int bClear)
{
    if (pObject)
    {
        *pObject = (int)&DAT_010305a8;
        if (bClear)
            pObject[3] = 0;
        pObject[5] = (int)&DAT_010c6fd0;
        *pObject = (int)&DAT_010d0e5c;
        pObject[3] = 11;
    }
}

extern int DAT_010305a8;
extern int DAT_010c6fd0;
extern int DAT_010d102c;

// If a is non-null, stores pointers to three globals into a and sets a[3] to 12 (or 0 first when b is set).
// @fnv 0x00e00f00
// src: HAVOK_LIB 0x00e00f00
void __cdecl finishLoadedObjecthkpConvexTransformShape(int** a, int abReset)
{
    if (a)
    {
        *a = &DAT_010305a8;
        if (abReset)
            a[3] = 0;
        a[5] = &DAT_010c6fd0;
        *a = &DAT_010d102c;
        a[3] = (int*)12;
    }
}

extern int DAT_010305a8;
extern int DAT_010ce31c;
extern int DAT_010e901c;
// @fnv 0x00e010e0
// src: GUESS 0x00e010e0 (confidence: low)
void __cdecl Object_UpdateFields_00e010e0(int* pObject, int abFlag)
{
    if (pObject)
    {
        pObject[0] = (int)&DAT_010305a8;
        if (abFlag)
            pObject[3] = 0;
        pObject[3] = 25;
        pObject[0] = (int)&DAT_010ce31c;
        if (abFlag)
            pObject[3] = 13;
        pObject[0] = (int)&DAT_010e901c;
        if (abFlag)
            *(char*)((char*)pObject + 0x1d) = 1;
    }
}

// @fnv 0x00e011f0
// src: GUESS 0x00e011f0 (confidence: low)
void __cdecl Runtime_Helper_00e011f0(void* a)
{
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(a))[0])(a, 0);
}

extern int DAT_010305a8;
extern int DAT_010c6ff8;
extern int DAT_010c6fd0;
// @fnv 0x00e013a0
// src: GUESS 0x00e013a0 (confidence: low)
void __cdecl Object_UpdateFields_00e013a0(int** p, int abClear)
{
    if (p)
    {
        *p = &DAT_010305a8;
        if (abClear)
            *(int*)(p + 3) = 0;
        *p = &DAT_010c6ff8;
        p[5] = &DAT_010c6fd0;
        *(int*)(p + 3) = 27;
    }
}

extern int DAT_010e9300;
// @fnv 0x00e01530
// src: GUESS 0x00e01530 (confidence: low)
void Runtime_UpdateState_00e01530(int* p)
{
    if (p)
        *p = (int)&DAT_010e9300;
}

extern int DAT_010e9358;
// @fnv 0x00e01570
// src: GUESS 0x00e01570 (confidence: low)
void Runtime_UpdateState_00e01570(int* p)
{
    if (p)
        *p = (int)&DAT_010e9358;
}

extern int DAT_010e93ac;
// @fnv 0x00e015b0
// src: GUESS 0x00e015b0 (confidence: low)
void Runtime_UpdateState_00e015b0(int** p)
{
    if (p)
        *p = &DAT_010e93ac;
}

typedef void(__thiscall* Fn)(void*, int);
// @fnv 0x00e01640
// src: GUESS 0x00e01640 (confidence: low)
void __cdecl Object_ProcessState_00e01640(int* p)
{
    (*(Fn**)p)[0](p, 0);
}

extern int DAT_010e943c;
// @fnv 0x00e01660
// src: GUESS 0x00e01660 (confidence: low)
void __cdecl Object_UpdateFields_00e01660(int* p)
{
    if (p)
        *p = (int)&DAT_010e943c;
}

extern int DAT_010e9494;
// @fnv 0x00e016a0
// src: GUESS 0x00e016a0 (confidence: low)
void __cdecl Object_UpdateFields_00e016a0(int* p)
{
    if (p)
        *p = (int)&DAT_010e9494;
}

struct FUN_00e017d0_vt
{
    virtual void Runtime_ForwardCall_00e017d0(int);
};

// @fnv 0x00e017d0
// src: GUESS 0x00e017d0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e017d0(FUN_00e017d0_vt* p)
{
    p->Runtime_ForwardCall_00e017d0(0);
}

extern int DAT_010e95b4;
// If a is non-null, stores &DAT_010e95b4 at its start and calls m(b) on the objects at offsets 8, 12 and 16.
// @fnv 0x00e017f0
// src: GUESS 0x00e017f0 (confidence: low)
void Object_UpdateState_00e017f0(FUN_00cb0a70** apObject, int aiValue)
{
    if (apObject)
    {
        *(int*)apObject = (int)&DAT_010e95b4;
        ((FUN_00cb0a70*)((char*)apObject + 8))->m(aiValue);
        ((FUN_00cb0a70*)((char*)apObject + 12))->m(aiValue);
        ((FUN_00cb0a70*)((char*)apObject + 16))->m(aiValue);
    }
}

extern int DAT_010e9614;
// @fnv 0x00e018e0
// src: GUESS 0x00e018e0 (confidence: low)
void Object_UpdateFields_00e018e0(int* a)
{
    if (a)
        *a = (int)&DAT_010e9614;
}

extern int DAT_010e350c;
// @fnv 0x00e019f0
// src: GUESS 0x00e019f0 (confidence: low)
void __cdecl Runtime_UpdateState_00e019f0(int* p)
{
    if (p)
        *p = (int)&DAT_010e350c;
}

extern int DAT_010e96c8;

// @fnv 0x00e01a30
// src: GUESS 0x00e01a30 (confidence: low)
void __cdecl Runtime_UpdateState_00e01a30(int* p)
{
    if (p)
        *p = (int)&DAT_010e96c8;
}

extern int DAT_010e977c;
// @fnv 0x00e01b10
// src: GUESS 0x00e01b10 (confidence: low)
void __cdecl Runtime_UpdateState_00e01b10(int* a)
{
    if (a)
        *a = (int)&DAT_010e977c;
}

extern int DAT_010e9b7c;
// @fnv 0x00e01f50
// src: GUESS 0x00e01f50 (confidence: low)
void __cdecl Runtime_UpdateState_00e01f50(int* p)
{
    if (p)
        *p = (int)&DAT_010e9b7c;
}

struct FUN_00e020e0_vt
{
    virtual int Object_ForwardCall_00e020e0(int);
};
// @fnv 0x00e020e0
// src: GUESS 0x00e020e0 (confidence: low)
int __cdecl Object_ForwardCall_00e020e0(FUN_00e020e0_vt* c)
{
    return c->Object_ForwardCall_00e020e0(0);
}

extern int DAT_010e9ccc;

// If a is non-null, stores the address of DAT_010e9ccc at a[0] and calls m(b) on the objects at a+2, a+4, a+5 and a+6.
// @fnv 0x00e02140
// src: GUESS 0x00e02140 (confidence: low)
void __cdecl Object_UpdateFields_00e02140(int* pObject, int iValue)
{
    if (pObject)
    {
        *(int*)pObject = (int)&DAT_010e9ccc;
        ((FUN_00cb0a70*)(pObject + 2))->m(iValue);
        ((FUN_00cb0a70*)(pObject + 4))->m(iValue);
        ((FUN_00cb0a70*)(pObject + 5))->m(iValue);
        ((FUN_00cb0a70*)(pObject + 6))->m(iValue);
    }
}

// @fnv 0x00e02260
// src: GUESS 0x00e02260 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e02260(int** p)
{
    ((void(__thiscall*)(void*, int))(*p)[0])(p, 0);
}

typedef int(__thiscall* FUN_00e02340_fn)(void*, int);
// @fnv 0x00e02340
// src: GUESS 0x00e02340 (confidence: low)
int __cdecl Object_GetIndexedValue_00e02340(void* obj)
{
    return ((FUN_00e02340_fn*)(*(int**)obj))[0](obj, 0);
}

extern int DAT_010e9e74;
// @fnv 0x00e02360
// src: GUESS 0x00e02360 (confidence: low)
void __cdecl Object_UpdateFields_00e02360(int* p)
{
    if (p)
        *p = (int)&DAT_010e9e74;
}

extern int DAT_010e9f48;
// @fnv 0x00e023a0
// src: GUESS 0x00e023a0 (confidence: low)
void Object_UpdateFields_00e023a0(int* p)
{
    if (p)
        *p = (int)&DAT_010e9f48;
}

extern int DAT_010e9fa4;

// @fnv 0x00e02480
// src: GUESS 0x00e02480 (confidence: low)
void Object_UpdateFields_00e02480(int* p)
{
    if (p)
        *p = (int)&DAT_010e9fa4;
}

extern int DAT_010ea0a4;
// @fnv 0x00e024c0
// src: GUESS 0x00e024c0 (confidence: low)
void __cdecl Object_UpdateFields_00e024c0(int* p)
{
    if (p)
        *p = (int)&DAT_010ea0a4;
}

typedef int(__thiscall* VFunc0)(void*, int);
// @fnv 0x00e024e0
// src: GUESS 0x00e024e0 (confidence: low)
int __cdecl Object_GetIndexedValue_00e024e0(void* p)
{
    return ((VFunc0*)*(void**)p)[0](p, 0);
}

extern int DAT_010e310c;
// @fnv 0x00e02500
// src: GUESS 0x00e02500 (confidence: low)
void Object_UpdateFields_00e02500(int* a)
{
    if (a)
        *a = (int)&DAT_010e310c;
}

extern int DAT_010ea10c;
// @fnv 0x00e02540
// src: GUESS 0x00e02540 (confidence: low)
void __cdecl Object_UpdateFields_00e02540(int** p)
{
    if (p)
        *p = &DAT_010ea10c;
}

extern int DAT_010ea154;
// @fnv 0x00e02580
// src: GUESS 0x00e02580 (confidence: low)
void __cdecl Object_UpdateFields_00e02580(int* a)
{
    if (a)
        *a = (int)&DAT_010ea154;
}

extern int DAT_010ea188;
// @fnv 0x00e02630
// src: GUESS 0x00e02630 (confidence: low)
void Runtime_UpdateState_00e02630(int* p)
{
    if (p)
        *p = (int)&DAT_010ea188;
}

struct FUN_00e026c0_vtbl
{
    virtual int v0(int);
};
// @fnv 0x00e026c0
// src: GUESS 0x00e026c0 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00e026c0(FUN_00e026c0_vtbl* p)
{
    return p->v0(0);
}

extern int DAT_010ea1ac;
// @fnv 0x00e026e0
// src: GUESS 0x00e026e0 (confidence: low)
void __cdecl Object_UpdateFields_00e026e0(int* p)
{
    if (p)
        *p = (int)&DAT_010ea1ac;
}

struct FUN_00e02720_vtbl
{
    virtual void m0(int);
};
// @fnv 0x00e02720
// src: GUESS 0x00e02720 (confidence: low)
void Object_InvokeVirtualMethod_00e02720(FUN_00e02720_vtbl* p)
{
    p->m0(0);
}

typedef void(__thiscall* vt)(void*, int);
// @fnv 0x00e02760
// src: GUESS 0x00e02760 (confidence: low)
void __cdecl Object_ProcessState_00e02760(void* p)
{
    ((vt*)(*(int*)p))[0](p, 0);
}

struct FUN_00e0bf20_s
{
    int a;
    int b;
    void __thiscall FUN_00cb0a60();
    FUN_00e0bf20_s();
};
// @fnv 0x00e0bf20
FUN_00e0bf20_s::FUN_00e0bf20_s()
{
    ((FUN_00e0bf20_s*)((char*)this + 8))->FUN_00cb0a60();
}

struct FUN_00e11dc0_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void __thiscall hkgpMesh_copyPartIdToVerticesW();
};

// @fnv 0x00e11dc0
// src: HAVOK_LIB 0x00e11dc0
void __thiscall FUN_00e11dc0_class::hkgpMesh_copyPartIdToVerticesW()
{
    int node = m_2c;
    if (!node)
        return;
    while (node)
    {
        int* cur = (int*)node;
        *(int*)((char*)(*(int*)((char*)cur + 8)) + 0x1c) = *(int*)((char*)cur + 0x30) | 0x3f000000;
        *(int*)((char*)(*(int*)((char*)cur + 0xc)) + 0x1c) = *(int*)((char*)cur + 0x30) | 0x3f000000;
        *(int*)((char*)(*(int*)((char*)cur + 0x10)) + 0x1c) = *(int*)((char*)cur + 0x30) | 0x3f000000;
        node = *(int*)cur;
    }
}

// @fnv 0x00e00100
// src: GUESS 0x00e00100 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00e00100(void* p)
{
    return ((int(__thiscall*)(void*, int))(*reinterpret_cast<void***>(p))[0])(p, 0);
}

// @fnv 0x00e00160
// src: GUESS 0x00e00160 (confidence: low)
void Object_InvokeVirtualMethod_00e00160(FUN_00e000a0_vt* p)
{
    ((void(__thiscall*)(void*, int))(*(void***)p)[0])(p, 0);
}

struct FUN_00e001a0_vt
{
    virtual void m(int);
};
// @fnv 0x00e001a0
// src: GUESS 0x00e001a0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e001a0(FUN_00e001a0_vt* p)
{
    p->m(0);
}

extern int DAT_010cc2fc;
extern int DAT_010d79c4;
// @fnv 0x00e001c0
// src: GUESS 0x00e001c0 (confidence: low)
void Object_UpdateFields_00e001c0(FUN_00cb0a70* obj, int aiValue)
{
    if (obj)
    {
        *(int*)obj = (int)&DAT_010cc2fc;
        ((FUN_00cb0a70*)((char*)obj + 0x14))->m(aiValue);
        *(int*)obj = (int)&DAT_010d79c4;
    }
}

// @fnv 0x00e00320
// src: GUESS 0x00e00320 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00320()
{
    return &DAT_010c6ea4;
}

struct FUN_00e00330_vt
{
    virtual void m(int);
};
// @fnv 0x00e00330
// src: GUESS 0x00e00330 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00330(FUN_00e00330_vt* p)
{
    p->m(0);
}

struct FUN_00e00370_vt
{
    virtual void m0(int);
};
// @fnv 0x00e00370
// src: GUESS 0x00e00370 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00370(FUN_00e00370_vt* p)
{
    p->m0(0);
}

struct FUN_00e00430_vt
{
    virtual void __thiscall m0(int);
};

// @fnv 0x00e00430
// src: GUESS 0x00e00430 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00430(FUN_00e00430_vt* p)
{
    p->m0(0);
}

extern int DAT_010c59f4;
extern int DAT_010c6dc4;
// @fnv 0x00e00450
// src: GUESS 0x00e00450 (confidence: low)
void __cdecl Object_UpdateState_00e00450(void* apObject, int flag)
{
    if (apObject)
    {
        *(int*)apObject = (int)&DAT_010c59f4;
        if (flag)
        {
            float f = 1.0f;
            *(unsigned short*)((char*)apObject + 0x11e) = (unsigned short)(*((int*)&f) >> 0x10);
        }
        *(int*)apObject = (int)&DAT_010c6dc4;
    }
}

typedef void(__thiscall* VFn)(void*, int);
// @fnv 0x00e00550
// src: GUESS 0x00e00550 (confidence: low)
void __cdecl Runtime_UpdateState_00e00550(void* p)
{
    VFn fn = ((VFn*)*(void**)p)[0];
    fn(p, 0);
}

struct FUN_00e005b0_vt
{
    virtual void m(int);
};
// @fnv 0x00e005b0
// src: GUESS 0x00e005b0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e005b0(FUN_00e005b0_vt* p)
{
    p->m(0);
}

struct FUN_00e00670_vt
{
    virtual void m0(int);
};
// @fnv 0x00e00670
// src: GUESS 0x00e00670 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00670(FUN_00e00670_vt* p)
{
    p->m0(0);
}

struct FUN_00e00790_vt
{
    virtual void __thiscall m(int);
};

// @fnv 0x00e00790
// src: GUESS 0x00e00790 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00790(FUN_00e00790_vt* p)
{
    p->m(0);
}

struct FUN_00e007f0_vt
{
    virtual void m0(int);
};
// @fnv 0x00e007f0
// src: GUESS 0x00e007f0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e007f0(FUN_00e007f0_vt* p)
{
    p->m0(0);
}

struct FUN_00e00a20_vt
{
    virtual void m0(int);
};
// @fnv 0x00e00a20
// src: GUESS 0x00e00a20 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e00a20(FUN_00e00a20_vt* p)
{
    p->m0(0);
}

// @fnv 0x00e00ae0
// src: GUESS 0x00e00ae0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e00ae0(FUN_00e00930_vt* p)
{
    p->m0(0);
}

struct FUN_00dcd380_cls
{
    void __thiscall FUN_00dcd380(int b);
};
extern int DAT_010e8a90;
extern int DAT_010e8ab0;
// @fnv 0x00e00c90
// src: GUESS 0x00e00c90 (confidence: low)
void __cdecl Object_UpdateState_00e00c90(void* pObject, int b)
{
    if (pObject)
    {
        ((FUN_00dcd380_cls*)pObject)->FUN_00dcd380(b);
        *(int**)pObject = &DAT_010e8ab0;
        *(int**)((char*)pObject + 0x10) = &DAT_010e8a90;
        if (b)
            *(int*)((char*)pObject + 0xc) = 0x17;
    }
}

struct FUN_00e00cf0_vt
{
    virtual void m(int);
};
// @fnv 0x00e00cf0
// src: GUESS 0x00e00cf0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00cf0(FUN_00e00cf0_vt* p)
{
    p->m(0);
}

struct FUN_00e00d90_vt
{
    virtual void m(int);
};
// @fnv 0x00e00d90
// src: GUESS 0x00e00d90 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00d90(FUN_00e00d90_vt* p)
{
    p->m(0);
}

struct FUN_00e00e70_vt
{
    virtual int Runtime_ForwardCall_00e00e70(int);
};
// @fnv 0x00e00e70
// src: GUESS 0x00e00e70 (confidence: low)
int __cdecl Runtime_ForwardCall_00e00e70(FUN_00e00e70_vt* p)
{
    return p->Runtime_ForwardCall_00e00e70(0);
}

// @fnv 0x00e010c0
// src: GUESS 0x00e010c0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e010c0(FUN_00e000a0_vt* p)
{
    ((void(__thiscall*)(void*, int))(*reinterpret_cast<void***>(p))[0])(p, 0);
}

struct FUN_00e01380_vt
{
    virtual void m(int);
};

// @fnv 0x00e01380
// src: GUESS 0x00e01380 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e01380(FUN_00e01380_vt* p)
{
    p->m(0);
}

typedef void(__thiscall* Fn0)(void*, int);
// @fnv 0x00e013f0
// src: GUESS 0x00e013f0 (confidence: low)
void __cdecl Runtime_UpdateState_00e013f0(void* p)
{
    Fn0 fn = *(Fn0*)*(void**)p;
    fn(p, 0);
}

typedef int(__thiscall* Vfn)(void*, int);
// @fnv 0x00e01450
// src: GUESS 0x00e01450 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e01450(void* p)
{
    return (*(Vfn*)*(void**)p)(p, 0);
}

extern int DAT_0126e330;

// @fnv 0x00e01460
// src: GUESS 0x00e01460 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01460()
{
    return &DAT_0126e330;
}

extern int DAT_010e929c;
struct FUN_00e01470_s
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    FUN_00cb0a70* m_2c;
};
// @fnv 0x00e01470
// src: GUESS 0x00e01470 (confidence: low)
void __cdecl Object_UpdateState_00e01470(FUN_00e01470_s* pObject, int iValue)
{
    if (pObject)
    {
        pObject->m_iWordAt00 = (int)&DAT_010e929c;
        ((FUN_00cb0a70*)&pObject->m_2c)->m(iValue);
    }
}

// @fnv 0x00e01510
// src: GUESS 0x00e01510 (confidence: low)
void __cdecl Runtime_Helper_00e01510(FUN_00cb0a70* p)
{
    ((Fn)(void**)(*(int**)p)[0])(p, 0);
}

struct FUN_00e01550_vt
{
    virtual void m0(int);
};
// @fnv 0x00e01550
// src: GUESS 0x00e01550 (confidence: low)
void __cdecl Runtime_ForwardCall_00e01550(FUN_00e01550_vt* p)
{
    p->m0(0);
}

// @fnv 0x00e018c0
// src: GUESS 0x00e018c0 (confidence: low)
void __cdecl Object_ProcessAndTransformResult_00e018c0(int* p)
{
    ((void(__thiscall*)(void*, int)) * (void**)*p)(p, 0);
}

typedef void(__thiscall* Fn)(void*, int);
// @fnv 0x00e019d0
// src: GUESS 0x00e019d0 (confidence: low)
void __cdecl Runtime_UpdateState_00e019d0(void* p)
{
    Fn fn = *(Fn*)(*(char**)p);
    fn(p, 0);
}

struct FUN_00e01a10_vt
{
    virtual void m0(int);
};
// @fnv 0x00e01a10
// src: GUESS 0x00e01a10 (confidence: low)
void __cdecl Runtime_ForwardCall_00e01a10(FUN_00e01a10_vt* p)
{
    p->m0(0);
}

typedef void(__thiscall* Fn)(void*, int);
// @fnv 0x00e01af0
// src: GUESS 0x00e01af0 (confidence: low)
void __cdecl Runtime_UpdateState_00e01af0(void* p)
{
    Fn* vt = (Fn*)*(void**)p;
    vt[0](p, 0);
}

struct FUN_00e01c10_vt
{
    virtual void m(int);
};
// @fnv 0x00e01c10
// src: GUESS 0x00e01c10 (confidence: low)
void __cdecl Runtime_ForwardCall_00e01c10(FUN_00e01c10_vt* p)
{
    p->m(0);
}

struct FUN_00e01cd0_vt
{
    virtual void m(int);
};
// @fnv 0x00e01cd0
// src: GUESS 0x00e01cd0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e01cd0(FUN_00e01cd0_vt* p)
{
    p->m(0);
}

extern int DAT_010e9a34;

// @fnv 0x00e01cf0
// src: HAVOK_LIB 0x00e01cf0
void finishLoadedObjecthkpSerializedAgentNnEntry_00e01cf0(void* pObject, void* b)
{
    if (pObject)
    {
        *(int*)pObject = (int)&DAT_010e9a34;
        ((FUN_00cb0a70*)((char*)pObject + 0x20))->m((int)b);
    }
}

struct FUN_00e01e40_vt
{
    virtual void m0(int);
};
// @fnv 0x00e01e40
// src: GUESS 0x00e01e40 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e01e40(FUN_00e01e40_vt* p)
{
    p->m0(0);
}

// @fnv 0x00e01f30
// src: GUESS 0x00e01f30 (confidence: low)
void __cdecl Runtime_Helper_00e01f30(int* p)
{
    ((void(__thiscall*)(void*, int))(*(*reinterpret_cast<void***>(p))))(p, 0);
}

extern int DAT_010e9dec;
struct FUN_00cb0a70_00e02280
{
    int* vt;
    int pad;
    int pad2;
    void __thiscall m(int);
};
// @fnv 0x00e02280
// src: GUESS 0x00e02280 (confidence: low)
void __cdecl Object_UpdateFields_00e02280(int* pObject, int iValue)
{
    if (pObject)
    {
        pObject[0] = (int)&DAT_010e9dec;
        ((FUN_00cb0a70_00e02280*)(pObject + 2))->m(iValue);
    }
}

typedef void(__thiscall* VFn)(void*, int);

// @fnv 0x00e02380
// src: GUESS 0x00e02380 (confidence: low)
void __cdecl Object_ProcessState_00e02380(void* p)
{
    ((VFn**)(void*)p)[0][0](p, 0);
}

typedef int(__thiscall* Vf0)(void*, int);
// @fnv 0x00e024a0
// src: GUESS 0x00e024a0 (confidence: low)
int __cdecl Object_ComputeValue_00e024a0(void* p)
{
    return (*(Vf0*)*(void**)p)(p, 0);
}

// @fnv 0x00e02510
// src: GUESS 0x00e02510 (confidence: low)
int* __cdecl Runtime_GetDAT010e310cAddress()
{
    return &DAT_010e310c;
}

struct FUN_00e02560_vt
{
    virtual int m(int);
};
// @fnv 0x00e02560
// src: GUESS 0x00e02560 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00e02560(FUN_00e02560_vt* p)
{
    return p->m(0);
}

// @fnv 0x00e02610
// src: GUESS 0x00e02610 (confidence: low)
int __cdecl Runtime_ForwardCall_00e02610(FUN_00e026c0_vtbl* p)
{
    return p->v0(0);
}

struct FUN_00e027b0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    void ApplyRelocations(int base);
};

// Applies two relocation tables to a base address: adds base to each first-table entry's offset, and writes second-table values directly.
// @fnv 0x00e027b0
void FUN_00e027b0_cls::ApplyRelocations(int base)
{
    int i = 0;
    while (i < m_iWordAt04)
    {
        int* entry = (int*)(m_iWordAt00 + i * 8);
        int off = entry[1] + base;
        *(int*)(base + entry[0]) = off;
        ++i;
    }
    i = 0;
    while (i < m_10)
    {
        int* entry = (int*)(m_iThirdValue + i * 0x10);
        *(int*)(base + entry[0]) = entry[1];
        ++i;
    }
}

struct FUN_00e0bf30_s
{
    int a;
    int b;
    FUN_00cb0a70 c;
    FUN_00e0bf30_s* __thiscall hkMonitorStreamStringMap_StringMap_StringMap(int v);
};
// @fnv 0x00e0bf30
// src: HAVOK_LIB 0x00e0bf30
FUN_00e0bf30_s* __thiscall FUN_00e0bf30_s::hkMonitorStreamStringMap_StringMap_StringMap(int aiValue)
{
    c.m(aiValue);
    return this;
}

void* __cdecl GetConvexHull();
struct FUN_00d752e0_cls
{
    void __thiscall hkgpConvexHull_getVolume();
};

// @fnv 0x00e114b0
// src: GUESS 0x00e114b0 (confidence: low)
void __cdecl Runtime_ForwardCall_00e114b0()
{
    ((FUN_00d752e0_cls*)GetConvexHull())->hkgpConvexHull_getVolume();
}

struct FUN_00e11d60_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int* m_2c;
    int m_30;
    void __thiscall hkgpMesh_setPartId(int val);
};

// @fnv 0x00e11d60
// src: HAVOK_LIB 0x00e11d60
void __thiscall FUN_00e11d60_class::hkgpMesh_setPartId(int val)
{
    int* p = m_2c;
    if (p)
    {
        do
        {
            *(p + 12) = val;
            p = (int*)*p;
        } while (p);
    }
}

BSAudio* __cdecl hkMemoryRouter_getInstance();

extern int DAT_0102e388;

struct FUN_00e00000_cls
{
    int m_vptr00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ReleaseBothArrays();
};

// Frees both allocated arrays through the audio allocator, resets their counts and capacity bits, and sets the vtable pointer.
// @fnv 0x00e00000
// src: GUESS 0x00e00000 (confidence: medium)
void FUN_00e00000_cls::ReleaseBothArrays()
{
    hkMemoryRouter* pHolder = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_pData1, (uCapBits1 & 0x3fffffffu) * 4);
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    hkMemoryRouter* pHolder2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(pHolder2->m_heap);
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0)
    {
        pAllocator2->bufFree(m_pData2, (uCapBits2 & 0x3fffffffu) * 16);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
    *(volatile int*)&m_vptr00 = (int)&DAT_0102e388;
}

extern int DAT_0126d9a0;

// @fnv 0x00e000b0
// src: GUESS 0x00e000b0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e000b0()
{
    return reinterpret_cast<int>(&DAT_0126d9a0);
}

// Forward a value to the owner object when the owner pointer is present.
struct FUN_00d50c00_cls
{
    void __thiscall FUN_00d50c00(int value);
};

// @fnv 0x00e000c0
// src: GUESS 0x00e000c0 (confidence: low)
void __cdecl Object_ProcessState_00e000c0(FUN_00d50c00_cls* pOwner, int value)
{
    if (pOwner != 0)
        pOwner->FUN_00d50c00(value);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126d9e8;
// @fnv 0x00e00110
// src: GUESS 0x00e00110 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126d9e8Address()
{
    return &DAT_0126d9e8;
}

extern int DAT_010c6cdc;

// @fnv 0x00e00150
// src: GUESS 0x00e00150 (confidence: low)
int* Runtime_GetDAT010c6cdcAddress()
{
    return &DAT_010c6cdc;
}

extern int DAT_0126da30;

// @fnv 0x00e00170
// src: GUESS 0x00e00170 (confidence: low)
int* __cdecl Runtime_GetDAT0126da30Address()
{
    return &DAT_0126da30;
}

extern int DAT_010e81a4;

// @fnv 0x00e00190
// src: GUESS 0x00e00190 (confidence: low)
void* __cdecl Runtime_GetDAT010e81a4Address()
{
    return &DAT_010e81a4;
}

extern int DAT_0126da78;

// @fnv 0x00e001b0
// src: GUESS 0x00e001b0 (confidence: low)
int* __cdecl Runtime_GetDAT0126da78Address()
{
    return &DAT_0126da78;
}

struct FUN_00e00220_Class
{
    virtual void VF00(int value);
};

// @fnv 0x00e00220
// src: GUESS 0x00e00220 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e00220(FUN_00e00220_Class* param_1)
{
    param_1->VF00(0);
}

extern int g_unk0126dac0;

// @fnv 0x00e00230
// src: GUESS 0x00e00230 (confidence: low)
void* __cdecl Runtime_GetUnk0126dac0Address()
{
    return &g_unk0126dac0;
}

// FUN_00e002e0 : a one-line function - getter
extern int g_target_00e002e0;
// @fnv 0x00e002e0
// src: GUESS 0x00e002e0 (confidence: low)
void* Object_GetGlobalObjectAddress_00e002e0()
{
    return &g_target_00e002e0;
}

extern int g_unk0126db50;

// @fnv 0x00e00340
// src: GUESS 0x00e00340 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e00340()
{
    return &g_unk0126db50;
}

extern int DAT_010e83b4;

// @fnv 0x00e00360
// src: GUESS 0x00e00360 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00360()
{
    return &DAT_010e83b4;
}

extern unsigned char DAT_0126db98;

// @fnv 0x00e00380
// src: GUESS 0x00e00380 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e00380()
{
    return &DAT_0126db98;
}

struct E00390FinishFlag
{
    int m_bFinishing;
};

class E00390Object
{
  public:
    E00390Object(E00390FinishFlag flag);

    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};

// @fnv 0x00e00390
// src: GUESS 0x00e00390 (confidence: low)
void Runtime_AllocateStorage_00e00390(void* apMemory, int aiFinishFlag)
{
    if (apMemory)
    {
        E00390FinishFlag flag;
        flag.m_bFinishing = aiFinishFlag;
        new (apMemory) E00390Object(flag);
    }
}

struct S_00e003d0_Arr
{
    int* data;
    int size;
    unsigned cap;
    S_00e003d0_Arr() : data(0), size(0), cap(0x80000000)
    {}
};
struct S_00e003d0_Base
{
    virtual void unk00();
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
    S_00e003d0_Base(int flag);
};
struct S_00e003d0_Arrs
{
    S_00e003d0_Arr arr8c;
    S_00e003d0_Arr arr98;
};
struct FUN_00e003d0 : S_00e003d0_Base, S_00e003d0_Arrs
{
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00e003d0_Arr arr160;
    FUN_00e003d0(int flag);
};
void S_00e003d0_Base::unk00()
{}
// Constructs the object by forwarding flag to the S_00e003d0_Base base constructor; the body is empty.
// @fnv 0x00e003d0
FUN_00e003d0::FUN_00e003d0(int flag) : S_00e003d0_Base(flag)
{}

extern int DAT_0126dbe0;

// @fnv 0x00e00440
// src: GUESS 0x00e00440 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00440(void)
{
    return &DAT_0126dbe0;
}

extern int DAT_010c6dc4;

// @fnv 0x00e00480
// src: GUESS 0x00e00480 (confidence: low)
void* Object_GetGlobalObjectAddress_00e00480()
{
    return &DAT_010c6dc4;
}

struct S_00e00490_vt
{
    virtual void m(int);
};
// @fnv 0x00e00490
// src: GUESS 0x00e00490 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00490(S_00e00490_vt* p)
{
    p->m(0);
}

extern int DAT_0126dc28;
// @fnv 0x00e004a0
// src: GUESS 0x00e004a0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e004a0()
{
    return &DAT_0126dc28;
}

struct FUN_00e004f0_class
{
    void __thiscall FUN_00e004f0(int value);
};

// @fnv 0x00e004b0
// src: GUESS 0x00e004b0 (confidence: low)
void __cdecl Runtime_ProcessState_00e004b0(FUN_00e004f0_class* object, int value)
{
    if (object != 0)
    {
        object->FUN_00e004f0(value);
    }
}

extern int DAT_0126dc70;

// @fnv 0x00e00560
// src: GUESS 0x00e00560 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00560()
{
    return &DAT_0126dc70;
}

extern int DAT_010c749c;

// @fnv 0x00e005a0
// src: GUESS 0x00e005a0 (confidence: low)
int* Object_GetGlobalObjectAddress_00e005a0()
{
    return &DAT_010c749c;
}

extern int DAT_0126dcb8;

// @fnv 0x00e005c0
// src: GUESS 0x00e005c0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e005c0()
{
    return &DAT_0126dcb8;
}

struct Handler_cls
{
    void __thiscall Handle(int value);
};

// @fnv 0x00e005d0
// src: GUESS 0x00e005d0 (confidence: low)
void __cdecl Runtime_ProcessState_00e005d0(Handler_cls* pHandler, int value)
{
    if (pHandler != 0)
        pHandler->Handle(value);
}

struct S_00e00610_P
{
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
    S_00e00610_P(int flag)
    {
        if (flag != 0)
            unk0c = 0;
    }
};
struct S_00e00610_S
{
    virtual void unk00();
    char unk04;
    char unk05;
    char unk06;
    char unk07;
    int unk18;
    int unk1c;
};
struct S_00e00610_Mid : S_00e00610_P, S_00e00610_S
{
    virtual void unk00();
    S_00e00610_Mid(int flag) : S_00e00610_P(flag)
    {
        if (flag != 0)
        {
            unk0c = 7;
            S_00e00610_S::unk05 = 3;
        }
    }
};
void S_00e00610_P::unk00()
{}
void S_00e00610_S::unk00()
{}
void S_00e00610_Mid::unk00()
{}
struct FUN_00e00610 : S_00e00610_Mid
{
    FUN_00e00610(int flag);
};
// Initializes the base with flag and, when flag is nonzero, sets unk0c to 7 and S_00e00610_S::unk05 to 2.
// @fnv 0x00e00610
FUN_00e00610::FUN_00e00610(int flag) : S_00e00610_Mid(flag)
{
    if (flag != 0)
    {
        unk0c = 7;
        S_00e00610_S::unk05 = 2;
    }
}

extern int DAT_0126dd00;

// @fnv 0x00e00680
// src: GUESS 0x00e00680 (confidence: low)
int* Object_GetGlobalObjectAddress_00e00680()
{
    return &DAT_0126dd00;
}

// FUN_00e00690: null-guarded forwarding of a second argument to a
// member function of the first (object) argument.
class FUN_00e00690_cls
{
  public:
    void FUN_00e006d0(int a1);
};

// @fnv 0x00e00690
// src: GUESS 0x00e00690 (confidence: low)
void __cdecl Object_ProcessState_00e00690(FUN_00e00690_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->FUN_00e006d0(aiValue);
    }
}

extern int DAT_010c6fd0;
struct S_00e006d0_A
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    char unk10;
    __forceinline S_00e006d0_A(int flag)
    {
        if (flag)
            unk0c = 0;
    }
};
struct S_00e006d0_B : S_00e006d0_A
{
    virtual void v0();
    __forceinline S_00e006d0_B(int flag) : S_00e006d0_A(flag)
    {
        if (flag)
        {
            unk0c = 8;
            unk10 = 2;
        }
    }
};
struct FUN_00e006d0 : S_00e006d0_B
{
    int* unk14;
    virtual void v0();
    FUN_00e006d0(int flag);
};
// Initializes the object: points unk14 at DAT_010c6fd0 and, when flag is set, sets unk0c to 8 and unk10 to 1.
// @fnv 0x00e006d0
FUN_00e006d0::FUN_00e006d0(int flag) : S_00e006d0_B(flag)
{
    unk14 = &DAT_010c6fd0;
    if (flag)
    {
        unk0c = 8;
        unk10 = 1;
    }
}

extern int DAT_0126dd48;

// @fnv 0x00e00730
// src: GUESS 0x00e00730 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e00730()
{
    return reinterpret_cast<int>(&DAT_0126dd48);
}

extern int DAT_010cc41c;
// @fnv 0x00e00780
// src: GUESS 0x00e00780 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00780()
{
    return &DAT_010cc41c;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126dd90;
// @fnv 0x00e007a0
// src: GUESS 0x00e007a0 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e007a0()
{
    return &DAT_0126dd90;
}

extern int DAT_010cb5ac;
// @fnv 0x00e007e0
// src: GUESS 0x00e007e0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e007e0()
{
    return &DAT_010cb5ac;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126ddd8;
// @fnv 0x00e00800
// src: GUESS 0x00e00800 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e00800()
{
    return &DAT_0126ddd8;
}

extern int DAT_010e8824;
// @fnv 0x00e00820
// src: GUESS 0x00e00820 (confidence: low)
int* Object_GetGlobalObjectAddress_00e00820()
{
    return &DAT_010e8824;
}

struct S_00e00830_Allocator
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void ReturnMemory(void* p, int nbytes);
};

struct S_00e00830_Ref
{
    void* m_ptr;
    void Object_UpdateFields_00cb0c00() throw();
    ~S_00e00830_Ref() throw()
    {
        Object_UpdateFields_00cb0c00();
    }
};

struct S_00e00830_Target
{
    void FUN_00c905b0() throw();
};

struct S_00e00830_Ptr
{
    S_00e00830_Target* m_p;
    ~S_00e00830_Ptr() throw()
    {
        if (m_p)
            m_p->FUN_00c905b0();
        m_p = 0;
    }
};

struct S_00e00830_Elem64
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
};

template <class T>
static __forceinline void S_00e00830_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00e00830_Allocator& alloc) throw();

template <class T>
static __forceinline void S_00e00830_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00e00830_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00e00830_Allocator& alloc) throw()
{
        T* p = self.m_data;
        int n = self.m_iElementCount;
        for (int i = 0; i < n; i++)
        {
            p[i].~T();
        }
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void S_00e00830_Array_destroy(hkArrayBase<T>& self) throw()
{
        S_00e00830_Array__clearAndDeallocate(self, GetRouterHeap<S_00e00830_Allocator>(hkMemoryRouter::getInstance()));
    }

struct S_00e00830_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00e00830_Array_destroy(self); }
};

struct S_00e00830_Base
{
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00e00830_Base() throw()
    {}
};

struct FUN_00e00830 : S_00e00830_Base
{
    S_00e00830_Ptr m_ptr;
    int unk0c;
    hkArray<S_00e00830_Ref, S_00e00830_ArrayPolicy> m_refs;
    hkArray<S_00e00830_Elem64, S_00e00830_ArrayPolicy> m_pElements;
    ~FUN_00e00830() throw();
};

// @fnv 0x00e00830
FUN_00e00830::~FUN_00e00830() throw()
{}

// FUN_00e00940 : a one-line function - getter
extern int g_target_00e00940;
// @fnv 0x00e00940
// src: GUESS 0x00e00940 (confidence: low)
void* Object_GetGlobalObjectAddress_00e00940()
{
    return &g_target_00e00940;
}

// Resets an object to the "script terminal" class layout: it installs the
// secondary base vtable, the primary vtable and finally the derived vtable.
extern int DAT_010e8894;
extern int DAT_010e88b4;
extern int DAT_010e88a4;

// @fnv 0x00e00950
// src: GUESS 0x00e00950 (confidence: low)
void __cdecl Object_UpdateState_00e00950(int* pObject)
{
    if (pObject)
    {
        *(volatile int*)&pObject[2] = (int)&DAT_010e8894;
        *(volatile int*)&pObject[0] = (int)&DAT_010e88b4;
        *(volatile int*)&pObject[2] = (int)&DAT_010e88a4;
    }
}

extern int DAT_010e88b4;

// @fnv 0x00e00970
// src: GUESS 0x00e00970 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e00970()
{
    return reinterpret_cast<int>(&DAT_010e88b4);
}

namespace fnv_00e00990 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e00990_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00e48740();

    FUN_00e00990_cls* DestroyIfFlagged(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00e48740, then if bit 0 of acFlags is set frees this through the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00e00990
FUN_00e00990_cls* FUN_00e00990_cls::DestroyIfFlagged(unsigned char acFlags)
{
    FUN_00e48740();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00e00990

extern "C" struct FUN_00e009c0_vt
{
    virtual void m0(int);
};

// @fnv 0x00e009c0
// src: GUESS 0x00e009c0 (confidence: low)
extern "C" void __cdecl Object_InvokeVirtualMethod_00e009c0(FUN_00e009c0_vt* p)
{
    p->m0(0);
}

struct CpuOpaque;
extern CpuOpaque DAT_0126de68;
// @fnv 0x00e009d0
// src: GUESS 0x00e009d0 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126de68Address()
{
    return &DAT_0126de68;
}

extern int DAT_010d0e18;
// @fnv 0x00e00a10
// src: GUESS 0x00e00a10 (confidence: low)
int* __cdecl Runtime_GetDAT010d0e18Address()
{
    return &DAT_010d0e18;
}

// FUN_00e00a30 : a one-line function - getter
extern int g_target_00e00a30;
// @fnv 0x00e00a30
// src: GUESS 0x00e00a30 (confidence: low)
void* Runtime_GetTarget00e00a30Address()
{
    return &g_target_00e00a30;
}

struct FUN_00e00a40_cls
{
    void __thiscall FUN_00e00a80(int a);
};

// @fnv 0x00e00a40
// src: GUESS 0x00e00a40 (confidence: low)
void __cdecl Object_ProcessState_00e00a40(FUN_00e00a40_cls* pObject, int a)
{
    if (pObject != 0)
        pObject->FUN_00e00a80(a);
}

class __declspec(novtable) BE00A80Base
{
  public:
    virtual ~BE00A80Base();

    int m_iRefCount;
};

class BE00A80InterfaceA
{
  public:
    virtual void OnA();
};

class BE00A80InterfaceB
{
  public:
    virtual void OnB();
};

class BE00A80InterfaceC
{
  public:
    virtual void OnC();
};

class BE00A80InterfaceD
{
  public:
    virtual void OnD();
};

class FUN_00e00a80_cls : public BE00A80Base,
                         public BE00A80InterfaceA,
                         public BE00A80InterfaceB,
                         public BE00A80InterfaceC,
                         public BE00A80InterfaceD
{
  public:
    FUN_00e00a80_cls(int iEnabled);
    virtual ~FUN_00e00a80_cls();
    virtual void OnA();
    virtual void OnB();
    virtual void OnC();
    virtual void OnD();

    int m_iFirst;
    int m_iSecond;
    int m_iEnabled;
};

// Initializes the object and sets m_iEnabled to 1 when iEnabled is nonzero.
// @fnv 0x00e00a80
FUN_00e00a80_cls::FUN_00e00a80_cls(int iEnabled)
{
    if (iEnabled)
        m_iEnabled = 1;
}

extern char DAT_0126def8;

// @fnv 0x00e00af0
// src: GUESS 0x00e00af0 (confidence: low)
char* __cdecl Runtime_GetDAT0126def8Address(void)
{
    return &DAT_0126def8;
}

extern int DAT_010ce4bc;

// @fnv 0x00e00b30
// src: GUESS 0x00e00b30 (confidence: low)
void* Runtime_GetDAT010ce4bcAddress()
{
    return &DAT_010ce4bc;
}

extern int g_unk0126df40;

// @fnv 0x00e00b50
// src: GUESS 0x00e00b50 (confidence: low)
void* __cdecl Runtime_GetUnk0126df40Address()
{
    return &g_unk0126df40;
}

inline void* operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

struct E00B60FinishFlag
{
    int m_bFinishing;
};

class E00B60Object
{
  public:
    E00B60Object(E00B60FinishFlag flag);

    int unk00;
};

// @fnv 0x00e00b60
void ConstructObjectWithFinishFlag(void* apMemory, int finishing)
{
    E00B60FinishFlag flag;
    flag.m_bFinishing = finishing;
    new (apMemory) E00B60Object(flag);
}

// FUN_00e00ba0: thiscall ctor-like (flag arg) storing a primary vtable at +0 and
// secondary vtables at +8, +0xc, +0x10, +0x14, then an optional int at +0x20.
struct E00ba0_b0
{
    virtual void unk00();
    int unk04;
};
struct E00ba0_b1
{
    virtual void unk00();
};
struct E00ba0_b2
{
    virtual void unk00();
};
struct E00ba0_b3
{
    virtual void unk00();
};
struct E00ba0_b4
{
    virtual void unk00();
};

class FUN_00e00ba0 : E00ba0_b0, E00ba0_b1, E00ba0_b2, E00ba0_b3, E00ba0_b4
{
  public:
    int unk18;
    int unk1c;
    int m_20;
    FUN_00e00ba0(int flag);
};

// Constructor that sets m_20 to 2 when flag is nonzero.
// @fnv 0x00e00ba0
FUN_00e00ba0::FUN_00e00ba0(int flag)
{
    if (flag != 0)
    {
        m_20 = 2;
    }
}

struct CpuOpaque;
extern CpuOpaque DAT_0126df88;
// @fnv 0x00e00c80
// src: GUESS 0x00e00c80 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e00c80()
{
    return &DAT_0126df88;
}

extern int DAT_0126dfd0;
// @fnv 0x00e00d00
// src: GUESS 0x00e00d00 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00d00()
{
    return &DAT_0126dfd0;
}

// FUN_00e00d20: cdecl, returns the address of a global object.
extern int DAT_010c63cc;

// @fnv 0x00e00d20
// src: GUESS 0x00e00d20 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00d20()
{
    return &DAT_010c63cc;
}

extern int DAT_0126e018;

// @fnv 0x00e00d40
// src: GUESS 0x00e00d40 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00d40()
{
    return &DAT_0126e018;
}

struct FUN_00d57b20_class
{
    void __thiscall hkpCylinderShape_hkpCylinderShape_00d57b20(int value);
};

// @fnv 0x00e00d50
// src: GUESS 0x00e00d50 (confidence: low)
void __cdecl hkpCylinderShape_hkpCylinderShape_00d57b20_ProcessState_00e00d50(FUN_00d57b20_class* pObject, int value)
{
    if (pObject)
        pObject->hkpCylinderShape_hkpCylinderShape_00d57b20(value);
}

extern int DAT_0126e060;

// @fnv 0x00e00da0
// src: GUESS 0x00e00da0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e00da0()
{
    return &DAT_0126e060;
}

extern int DAT_010e8d8c;

// @fnv 0x00e00dc0
// src: GUESS 0x00e00dc0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00dc0()
{
    return &DAT_010e8d8c;
}

extern int DAT_0126e0a8;

// @fnv 0x00e00e80
// src: GUESS 0x00e00e80 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e00e80()
{
    return &DAT_0126e0a8;
}

extern int DAT_010d0e5c;
// @fnv 0x00e00ed0
// src: GUESS 0x00e00ed0 (confidence: low)
int* __cdecl Runtime_GetDAT010d0e5cAddress()
{
    return &DAT_010d0e5c;
}

struct S_00e00ee0_vt
{
    virtual void m0(int a);
};
// @fnv 0x00e00ee0
// src: GUESS 0x00e00ee0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e00ee0(S_00e00ee0_vt* p)
{
    p->m0(0);
}

extern int DAT_0126e0f0;

// @fnv 0x00e00ef0
// src: GUESS 0x00e00ef0 (confidence: low)
void* __cdecl Runtime_GetDAT0126e0f0Address()
{
    return &DAT_0126e0f0;
}

extern int DAT_010d102c;

// @fnv 0x00e00f40
// src: GUESS 0x00e00f40 (confidence: low)
void* Object_GetGlobalObjectAddress_00e00f40()
{
    return &DAT_010d102c;
}

// FUN_00e00f50: calls the first virtual (slot 0) of the object passed in the
// first stack argument, with a single 0 argument.
struct FUN_00e00f50_cls
{
    virtual void m_fn(int aParam);
};

// @fnv 0x00e00f50
// src: GUESS 0x00e00f50 (confidence: low)
void __cdecl Runtime_ForwardCall_00e00f50(FUN_00e00f50_cls* pObj)
{
    pObj->m_fn(0);
}

extern int DAT_0126e138;
// @fnv 0x00e00f60
// src: GUESS 0x00e00f60 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e00f60()
{
    return &DAT_0126e138;
}

// FUN_00e00f70: forwards a value to a helper on the passed-in object
// when that object is present.
struct FUN_00e00f70_cls
{
    void __thiscall FUN_00e00fb0(int value);
};

// @fnv 0x00e00f70
// src: GUESS 0x00e00f70 (confidence: low)
void __cdecl Object_ProcessState_00e00f70(FUN_00e00f70_cls* pObject, int value)
{
    if (pObject != 0)
    {
        pObject->FUN_00e00fb0(value);
    }
}

extern int DAT_010305a8;
extern int DAT_010c6fb0;
extern int DAT_010cc364;
extern int DAT_010cc344;
extern int DAT_010e8e94;
extern int DAT_010e8e74;

class FUN_00e00fb0
{
  public:
    void* m_vptr;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void* m_10;
    unsigned char m_14;
    unsigned char m_15;

    FUN_00e00fb0(int flag);
};

// Constructor that installs successive vtable and member pointers and, when flag is non-zero, sets m_0c and m_15.
// @fnv 0x00e00fb0
FUN_00e00fb0::FUN_00e00fb0(int flag)
{
    *(void* volatile*)&m_vptr = &DAT_010305a8;
    if (flag != 0)
        *(volatile unsigned int*)&m_0c = 0;
    *(void* volatile*)&m_10 = &DAT_010c6fb0;
    *(void* volatile*)&m_vptr = &DAT_010cc364;
    *(void* volatile*)&m_10 = &DAT_010cc344;
    if (flag != 0)
    {
        *(volatile unsigned int*)&m_0c = 7;
        *(volatile unsigned char*)&m_15 = 3;
    }
    *(void* volatile*)&m_vptr = &DAT_010e8e94;
    *(void* volatile*)&m_10 = &DAT_010e8e74;
    if (flag != 0)
        *(volatile unsigned int*)&m_0c = 7;
}

struct VirtualSlotObject
{
    virtual void unk00(int arg);
};

// @fnv 0x00e01050
// src: GUESS 0x00e01050 (confidence: low)
void __cdecl Runtime_ForwardCall_00e01050(VirtualSlotObject* p)
{
    p->unk00(0);
}

extern int DAT_0126e180;

// @fnv 0x00e01060
// src: GUESS 0x00e01060 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01060()
{
    return &DAT_0126e180;
}

extern int DAT_010c6fb0;
extern int DAT_010d10c4;
extern int DAT_010d10a4;

struct InitObject
{
    void* m_pVTable;  // +0x00
    int m_i04;        // +0x04
    int m_i08;        // +0x08
    int m_i0C;        // +0x0C
    int m_i10;        // +0x10
    void* m_pSlot;    // +0x14
};

// @fnv 0x00e01070
void __cdecl InitObjectFields(volatile InitObject* pObject, int iFlag)
{
    if (pObject != 0)
    {
        pObject->m_pVTable = (void*)&DAT_010305a8;

        if (iFlag != 0)
            pObject->m_i0C = 0;

        pObject->m_pSlot = (void*)&DAT_010c6fb0;
        pObject->m_pVTable = (void*)&DAT_010d10c4;
        pObject->m_pSlot = (void*)&DAT_010d10a4;
        pObject->m_i0C = 0x16;
    }
}

extern int DAT_010d10c4;

// @fnv 0x00e010b0
// src: GUESS 0x00e010b0 (confidence: low)
void* __cdecl Runtime_GetDAT010d10c4Address()
{
    return &DAT_010d10c4;
}

extern int DAT_0126e1c8;

// @fnv 0x00e010d0
// src: GUESS 0x00e010d0 (confidence: low)
void* __cdecl Runtime_GetDAT0126e1c8Address(void)
{
    return &DAT_0126e1c8;
}

extern int DAT_010e901c;

// @fnv 0x00e01130
// src: GUESS 0x00e01130 (confidence: low)
void* __cdecl Runtime_GetDAT010e901cAddress()
{
    return &DAT_010e901c;
}

extern int DAT_0126e210;

// @fnv 0x00e01200
// src: GUESS 0x00e01200 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e01200()
{
    return &DAT_0126e210;
}

namespace fnv_00e01210 {
struct Handler_cls
{
    void __thiscall Handle(int value);
};

// @fnv 0x00e01210
void __cdecl DispatchToHandler(Handler_cls* pHandler, int value)
{
    if (pHandler != 0)
        pHandler->Handle(value);
}
}  // namespace fnv_00e01210

// FUN_00e01250: thiscall ctor (flag arg) storing secondary vtables at +8,+0xc,+0x10,+0x14
// from inline base ctors, then the primary vtable at +0, then the secondary vtables again,
// then an optional int at +0x20.
struct E01250_b0
{
    virtual void unk00();
    int unk04;
};
struct E01250_b1
{
    virtual void unk00();
};
struct E01250_b2
{
    virtual void unk00();
};
struct E01250_b3
{
    virtual void unk00();
};
struct E01250_b4
{
    virtual void unk00();
};

class FUN_00e01250 : E01250_b0, E01250_b1, E01250_b2, E01250_b3, E01250_b4
{
  public:
    int unk18;
    int unk1c;
    int m_20;
    FUN_00e01250(int flag);
};

// Constructor that sets m_20 to 3 when flag is nonzero.
// @fnv 0x00e01250
FUN_00e01250::FUN_00e01250(int flag)
{
    if (flag != 0)
    {
        m_20 = 3;
    }
}

struct FUN_00e01320_cls
{
    virtual void m_v00(int arg);
};

// @fnv 0x00e01320
// src: GUESS 0x00e01320 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e01320(FUN_00e01320_cls* pObject)
{
    pObject->m_v00(0);
}

extern int DAT_0126e258;
// @fnv 0x00e01330
// src: GUESS 0x00e01330 (confidence: low)
int* __cdecl Runtime_GetDAT0126e258Address(void)
{
    return &DAT_0126e258;
}

extern int DAT_010ce25c;
// @fnv 0x00e01370
// src: GUESS 0x00e01370 (confidence: low)
int* __cdecl Runtime_GetDAT010ce25cAddress()
{
    return &DAT_010ce25c;
}

extern int DAT_0126e2a0;

// @fnv 0x00e01390
// src: GUESS 0x00e01390 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e01390()
{
    return reinterpret_cast<int>(&DAT_0126e2a0);
}

// @fnv 0x00e013e0
// src: GUESS 0x00e013e0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e013e0()
{
    return &DAT_010c6ff8;
}

extern int DAT_0126e2e8;

// @fnv 0x00e01400
// src: GUESS 0x00e01400 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01400()
{
    return &DAT_0126e2e8;
}

extern int DAT_010c70b4;

// @fnv 0x00e01440
// src: GUESS 0x00e01440 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01440()
{
    return &DAT_010c70b4;
}

// FUN_00e01520 : a one-line function - getter
extern int g_target_00e01520;
// @fnv 0x00e01520
// src: GUESS 0x00e01520 (confidence: low)
void* Object_GetGlobalObjectAddress_00e01520()
{
    return &g_target_00e01520;
}

extern int DAT_010e9300;

// @fnv 0x00e01540
// src: GUESS 0x00e01540 (confidence: low)
int* Object_GetGlobalObjectAddress_00e01540()
{
    return &DAT_010e9300;
}

extern int DAT_0126e3c0;

// @fnv 0x00e01560
// src: GUESS 0x00e01560 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e01560()
{
    return &DAT_0126e3c0;
}

extern int DAT_010e9358;
// @fnv 0x00e01580
// src: GUESS 0x00e01580 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01580()
{
    return &DAT_010e9358;
}

struct FnvCpu_FUN_00e01590_CpuInterface
{
    virtual void Invoke(int value);
};
// @fnv 0x00e01590
// src: GUESS 0x00e01590 (confidence: low)
void __cdecl Runtime_ForwardCall_00e01590(FnvCpu_FUN_00e01590_CpuInterface* object)
{
    object->Invoke(0);
}

extern int DAT_0126e408;

// @fnv 0x00e015a0
// src: GUESS 0x00e015a0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e015a0()
{
    return &DAT_0126e408;
}

extern int DAT_010e93ac;

// @fnv 0x00e015c0
// src: GUESS 0x00e015c0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e015c0()
{
    return &DAT_010e93ac;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126e450;
// @fnv 0x00e01650
// src: GUESS 0x00e01650 (confidence: low)
CpuOpaque* __cdecl Runtime_GetDAT0126e450Address()
{
    return &DAT_0126e450;
}

extern int DAT_010e943c;

// @fnv 0x00e01670
// src: GUESS 0x00e01670 (confidence: low)
void* __cdecl Runtime_GetDAT010e943cAddress()
{
    return &DAT_010e943c;
}

struct CallerVtbl
{
    virtual int v0(int);
};

// @fnv 0x00e01680
// src: GUESS 0x00e01680 (confidence: low)
int __cdecl Object_InvokeVirtualMethod_00e01680(CallerVtbl* p)
{
    return p->v0(0);
}

extern int DAT_0126e498;

// @fnv 0x00e01690
// src: GUESS 0x00e01690 (confidence: low)
void* __cdecl Runtime_GetDAT0126e498Address()
{
    return &DAT_0126e498;
}

extern int DAT_010e9494;

// @fnv 0x00e016b0
// src: GUESS 0x00e016b0 (confidence: low)
int* __cdecl Runtime_GetDAT010e9494Address()
{
    return &DAT_010e9494;
}

// Stand-in for the object whose first virtual slot is invoked with the constant 0.
struct FUN_00e016c0_cls
{
    virtual void m0(int a);
};

// Calls the first virtual of the object passed in as the only argument,
// passing the literal 0 to it.
// @fnv 0x00e016c0
// src: GUESS 0x00e016c0 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e016c0(FUN_00e016c0_cls* pObject)
{
    pObject->m0(0);
}

extern int DAT_0126e4e0;

// @fnv 0x00e016d0
// src: GUESS 0x00e016d0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e016d0()
{
    return reinterpret_cast<int>(&DAT_0126e4e0);
}

struct EffectSubObject
{
    int unk00;
    void __thiscall Release(int flags);
};

struct EffectHolder
{
    virtual void Virt();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    EffectSubObject m_18;
    EffectSubObject m_1c;
    EffectHolder()
    {}
};

// If p is non-null, constructs the EffectHolder and releases its two sub-objects with the given flags.
// @fnv 0x00e016e0
// src: GUESS 0x00e016e0 (confidence: low)
void __cdecl Object_ProcessState_00e016e0(EffectHolder* apHolder, int flags)
{
    if (apHolder != 0)
    {
        apHolder->EffectHolder::EffectHolder();
        apHolder->m_18.Release(flags);
        apHolder->m_1c.Release(flags);
    }
}

namespace fnv_00e01750 {
struct S_Handle
{
    int unk0;
    void Object_UpdateFields_00cb0c00();
    ~S_Handle() throw()
    {
        Object_UpdateFields_00cb0c00();
    }
};
struct S_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* p, unsigned n);
};

struct S_00e01750_Array
{
    char* m_data;
    int m_iElementCount;
    unsigned m_cap;
    void ClearAndRelease(S_Alloc& a)
    {
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            a.v4(m_data, m_cap & 0x3fffffff);
        m_data = 0;
        m_cap = 0x80000000;
    }
    ~S_00e01750_Array() throw()
    {
        ClearAndRelease(GetRouterHeap<S_Alloc>(hkMemoryRouter::getInstance()));
    }
};
struct S_00e01750_Base
{
    int unk4;
    int unk8;
    virtual ~S_00e01750_Base() throw()
    {}
};
struct __declspec(novtable) FUN_00e01750 : S_00e01750_Base
{
    S_00e01750_Array arr;
    S_Handle h18;
    S_Handle h1c;
    ~FUN_00e01750() throw();
};
// Destroys the object, releasing its array and the two handles through their destructors.
// @fnv 0x00e01750
FUN_00e01750::~FUN_00e01750() throw()
{}
}  // namespace fnv_00e01750

extern int DAT_0126e528;

// @fnv 0x00e017e0
// src: GUESS 0x00e017e0 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e017e0()
{
    return &DAT_0126e528;
}

extern int DAT_0126e570;

// @fnv 0x00e018d0
// src: GUESS 0x00e018d0 (confidence: low)
int* __cdecl Runtime_GetDAT0126e570Address()
{
    return &DAT_0126e570;
}

extern int DAT_010e9614;

// @fnv 0x00e018f0
// src: GUESS 0x00e018f0 (confidence: low)
void* __cdecl Runtime_GetDAT010e9614Address()
{
    return &DAT_010e9614;
}

extern int DAT_0126e5b8;

// @fnv 0x00e019e0
// src: GUESS 0x00e019e0 (confidence: low)
int __cdecl Object_ComputeValue_00e019e0()
{
    return reinterpret_cast<int>(&DAT_0126e5b8);
}

extern int DAT_010e350c;
// @fnv 0x00e01a00
// src: GUESS 0x00e01a00 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01a00()
{
    return &DAT_010e350c;
}

struct CpuOpaque;
extern CpuOpaque DAT_0126e600;
// @fnv 0x00e01a20
// src: GUESS 0x00e01a20 (confidence: low)
CpuOpaque* __cdecl Object_GetGlobalObjectAddress_00e01a20()
{
    return &DAT_0126e600;
}

extern int DAT_010e96c8;

// @fnv 0x00e01a40
// src: GUESS 0x00e01a40 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e01a40()
{
    return &DAT_010e96c8;
}

namespace fnv_00e01a50 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct S_00e01a50_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};


template <class T>
static __forceinline void S_00e01a50_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00e01a50_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00e01a50_Heap& alloc) throw();

template <class T>
static __forceinline void S_00e01a50_Array_destroy(hkArrayBase<T>& self) throw()
{
        S_00e01a50_Array__clearAndDeallocate(self, GetRouterHeap<S_00e01a50_Heap>(*hkMemoryRouter_getInstance()));
    }

template <class T>
static __forceinline void S_00e01a50_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00e01a50_Heap& alloc) throw()
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct S_00e01a50_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00e01a50_Array_destroy(self); }
};

struct S_00e01a50_Base
{
    virtual ~S_00e01a50_Base() throw()
    {}
};

struct __declspec(novtable) FUN_00e01a50 : S_00e01a50_Base
{
    int unk04;
    hkArray<char, S_00e01a50_ArrayPolicy> m_bytes;
    hkArray<int, S_00e01a50_ArrayPolicy> m_auiHeaderValues;
    ~FUN_00e01a50() throw();
};

// Destructor that releases the char and int arrays through the router's heap allocator.
// @fnv 0x00e01a50
FUN_00e01a50::~FUN_00e01a50() throw()
{}
}  // namespace fnv_00e01a50

extern int g_unk0126e648;

// @fnv 0x00e01b00
// src: GUESS 0x00e01b00 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e01b00()
{
    return &g_unk0126e648;
}

extern int DAT_010e977c;

// @fnv 0x00e01b20
// src: GUESS 0x00e01b20 (confidence: low)
int* Object_GetGlobalObjectAddress_00e01b20()
{
    return &DAT_010e977c;
}

namespace fnv_00e01b30 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
extern int DAT_0102e388;
struct S_00e01b30_Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct S_00e01b30_Elem4
{
    int unk00;
    void __thiscall Object_UpdateFields_00cb0c00() throw();
};
struct S_00e01b30_Elem64
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
};
struct S_00e01b30_Target
{
    void __thiscall FUN_00c905b0() throw();
};
template <class T>
static __forceinline void S_00e01b30_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00e01b30_Allocator& alloc) throw();

template <class T>
static __forceinline void S_00e01b30_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00e01b30_Array__clearAndDeallocate(hkArrayBase<T>& self, S_00e01b30_Allocator& alloc) throw()
{
        int n = self.m_iElementCount;
        T* p = self.m_data;
        for (int i = 0; i < n; i++)
        {
            p->Object_UpdateFields_00cb0c00();
            ++p;
        }
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void S_00e01b30_Array_destroy(hkArrayBase<T>& self) throw()
{
        S_00e01b30_Array__clearAndDeallocate(self, GetRouterHeap<S_00e01b30_Allocator>(*hkMemoryRouter_getInstance()));
    }

struct S_00e01b30_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00e01b30_Array_destroy(self); }
};
template <>
__forceinline void S_00e01b30_Array__clearAndDeallocate<S_00e01b30_Elem64>(hkArrayBase<S_00e01b30_Elem64>& self, S_00e01b30_Allocator& alloc) throw()
{
    self.m_iElementCount = 0;
    if ((self.m_iCapacityState & 0x80000000) == 0)
        alloc.ReturnMemory(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(S_00e01b30_Elem64));
    self.m_data = 0;
    self.m_iCapacityState = 0x80000000;
}

struct S_00e01b30_RefPtr
{
    S_00e01b30_Target* m_pRetainedObject;
    __forceinline ~S_00e01b30_RefPtr() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};
struct S_00e01b30_Base
{
    virtual ~S_00e01b30_Base() throw()
    {}
    int unk04;
};
struct __declspec(novtable) FUN_00e01b30 : S_00e01b30_Base
{
    S_00e01b30_RefPtr m_ref;
    hkArray<S_00e01b30_Elem4, S_00e01b30_ArrayPolicy> m_kPointA;
    hkArray<S_00e01b30_Elem64, S_00e01b30_ArrayPolicy> m_kPointB;
    virtual ~FUN_00e01b30() throw();
};
// Destroys the object, releasing its reference-counted target and both arrays through their member destructors.
// @fnv 0x00e01b30
FUN_00e01b30::~FUN_00e01b30() throw()
{}
}  // namespace fnv_00e01b30

extern int DAT_0126e690;

// @fnv 0x00e01c20
// src: GUESS 0x00e01c20 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e01c20()
{
    return &DAT_0126e690;
}

extern int g_unkGlobal;

// @fnv 0x00e01ce0
// src: GUESS 0x00e01ce0 (confidence: low)
void* Object_GetGlobalObjectAddress_00e01ce0()
{
    return &g_unkGlobal;
}

struct FUN_00e01e00_vt
{
    virtual void m(int);
};

// @fnv 0x00e01e00
// src: GUESS 0x00e01e00 (confidence: low)
void __cdecl Object_InvokeVirtualMethod_00e01e00(FUN_00e01e00_vt* p)
{
    p->m(0);
}

extern int DAT_0126e720;

// @fnv 0x00e01e10
// src: GUESS 0x00e01e10 (confidence: low)
int* __cdecl Runtime_GetDAT0126e720Address()
{
    return &DAT_0126e720;
}

// Null-guarded forwarder: the first argument is an object pointer; when it
// is non-null the second argument is forwarded to a member function of that
// object (called with the object as 'this').
class FUN_00e01e20_cls
{
  public:
    void __thiscall Handle(int a1);
};

// @fnv 0x00e01e20
void __cdecl CallHandleIfNotNull(FUN_00e01e20_cls* pObject, int aiValue)
{
    if (pObject != 0)
    {
        pObject->Handle(aiValue);
    }
}

extern int DAT_0126e768;
// @fnv 0x00e01e70
// src: GUESS 0x00e01e70 (confidence: low)
int* __cdecl Runtime_GetDAT0126e768Address()
{
    return &DAT_0126e768;
}

extern int DAT_010e9acc;

struct FUN_00e01e80_obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

// If param_1 is non-null, stores the address of DAT_010e9acc in unk00 and calls m(param_2) on the objects at offsets 0x14 and 0x18.
// @fnv 0x00e01e80
// src: GUESS 0x00e01e80 (confidence: low)
void __cdecl Object_UpdateFields_00e01e80(FUN_00e01e80_obj* pObj, int aiValue)
{
    if (pObj != 0)
    {
        pObj->unk00 = reinterpret_cast<int>(&DAT_010e9acc);
        reinterpret_cast<FUN_00cb0a70*>(reinterpret_cast<char*>(pObj) + 0x14)->m(aiValue);
        reinterpret_cast<FUN_00cb0a70*>(reinterpret_cast<char*>(pObj) + 0x18)->m(aiValue);
    }
}

extern int DAT_0126e7b0;

// @fnv 0x00e01f40
// src: GUESS 0x00e01f40 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00e01f40()
{
    return &DAT_0126e7b0;
}

extern int DAT_010e9b7c;

// @fnv 0x00e01f60
// src: GUESS 0x00e01f60 (confidence: low)
unsigned int __cdecl Object_ComputeValue_00e01f60()
{
    return reinterpret_cast<unsigned int>(&DAT_010e9b7c);
}

struct FUN_00e4ae80_Obj
{
    void __thiscall FUN_00e4ae80(int value);
};

// @fnv 0x00e020c0
// src: GUESS 0x00e020c0 (confidence: low)
void __cdecl Object_ProcessState_00e020c0(FUN_00e4ae80_Obj* pObj, int iValue)
{
    if (pObj != 0)
    {
        pObj->FUN_00e4ae80(iValue);
    }
}

extern int g_unk0126e7f8;

// @fnv 0x00e02110
// src: GUESS 0x00e02110 (confidence: low)
void* __cdecl Runtime_GetUnk0126e7f8Address()
{
    return &g_unk0126e7f8;
}

// FUN_00e02120: cdecl, takes a pointer, calls virtual slot 0 with argument 0.

class FUN_00e02120_cls
{
  public:
    virtual int v00(int arg);
};

// @fnv 0x00e02120
// src: GUESS 0x00e02120 (confidence: low)
void Object_InvokeVirtualMethod_00e02120(FUN_00e02120_cls* obj)
{
    obj->v00(0);
}

extern int g_unk0126e840;

// @fnv 0x00e02130
// src: GUESS 0x00e02130 (confidence: low)
void* __cdecl Runtime_GetUnk0126e840Address()
{
    return &g_unk0126e840;
}

namespace fnv_00e021d0 {
struct FUN_00e021d0_allocator
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void Free(void* data, unsigned int size);
};


struct FUN_00cb0c00_class
{
    void __thiscall Object_UpdateFields_00cb0c00();
};

struct FUN_00e021d0_class
{
    int* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;

    void __thiscall ClearAndReset();
};

extern int DAT_0102e388;

// @fnv 0x00e021d0
void FUN_00e021d0_class::ClearAndReset()
{
    hkMemoryRouter& manager = hkMemoryRouter::getInstance();
    FUN_00e021d0_allocator* allocator = reinterpret_cast<FUN_00e021d0_allocator*>(manager.m_heap);

    unk20 = 0;
    if ((unk24 & 0x80000000) == 0)
        allocator->Free((void*)unk1C, (unsigned int)unk24 & 0x3fffffff);

    unk1C = 0;
    unk24 = 0x80000000;

    reinterpret_cast<FUN_00cb0c00_class*>(reinterpret_cast<char*>(this) + 0x18)->Object_UpdateFields_00cb0c00();
    reinterpret_cast<FUN_00cb0c00_class*>(reinterpret_cast<char*>(this) + 0x14)->Object_UpdateFields_00cb0c00();
    reinterpret_cast<FUN_00cb0c00_class*>(reinterpret_cast<char*>(this) + 0x10)->Object_UpdateFields_00cb0c00();
    reinterpret_cast<FUN_00cb0c00_class*>(reinterpret_cast<char*>(this) + 0x08)->Object_UpdateFields_00cb0c00();

    unk00 = &DAT_0102e388;
}
}  // namespace fnv_00e021d0

struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00e02270
// src: GUESS 0x00e02270 (confidence: high)
GlobalObject* __cdecl Runtime_GetGlobalAddress_00e02270()
{
    return &g_global;
}

struct Data_0126e8d0;
extern Data_0126e8d0 DAT_0126e8d0;

// @fnv 0x00e02350
// src: GUESS 0x00e02350 (confidence: low)
Data_0126e8d0* __cdecl Runtime_GetDAT0126e8d0Address()
{
    return &DAT_0126e8d0;
}

extern int DAT_010e9e74;

// @fnv 0x00e02370
// src: GUESS 0x00e02370 (confidence: low)
void* __cdecl Runtime_GetDAT010e9e74Address()
{
    return &DAT_010e9e74;
}

extern int DAT_0126e918;

// @fnv 0x00e02390
// src: GUESS 0x00e02390 (confidence: low)
int* __cdecl Runtime_GetDAT0126e918Address()
{
    return &DAT_0126e918;
}

extern int DAT_010e9f48;

// @fnv 0x00e023b0
// src: GUESS 0x00e023b0 (confidence: low)
int* __cdecl Runtime_GetDAT010e9f48Address()
{
    return &DAT_010e9f48;
}

namespace fnv_00e023c0 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct E023C0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};


template <class T>
struct E023C0Array
{ // local form of hkArrayBase: 0x00e023c0 needs the local member lifetime split; the shared form changes destructor extent from 111 to 175 bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~E023C0Array() throw()
    {
        E023C0Allocator& alloc = GetRouterHeap<E023C0Allocator>(*hkMemoryRouter_getInstance());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class E023C0BaseObject
{
  public:
    virtual ~E023C0BaseObject()
    {}
};

class __declspec(novtable) FUN_00e023c0 : public E023C0BaseObject
{
  public:
    virtual ~FUN_00e023c0();

    int m_usMemSizeAndFlags;
    int unk08;
    E023C0Array<unsigned short> m_ppIndices;
    E023C0Array<int> m_iSlotIds;
};

// Empty destructor for the object; member arrays are destroyed by their own destructors.
// @fnv 0x00e023c0
FUN_00e023c0::~FUN_00e023c0()
{}
}  // namespace fnv_00e023c0

struct E02460Object
{
    virtual void Destroy(bool bFree);
};

// @fnv 0x00e02460
// src: GUESS 0x00e02460 (confidence: medium)
void Object_Destroy_Thunk_00e02460(E02460Object* pkObject)
{
    pkObject->Destroy(false);
}

extern int DAT_0126e960;

// @fnv 0x00e02470
// src: GUESS 0x00e02470 (confidence: low)
int* __cdecl Runtime_GetDAT0126e960Address()
{
    return &DAT_0126e960;
}

extern int DAT_010e9fa4;

// @fnv 0x00e02490
// src: GUESS 0x00e02490 (confidence: low)
void* __cdecl Runtime_GetDAT010e9fa4Address()
{
    return &DAT_010e9fa4;
}

// FUN_00e024b0 : a one-line function - getter
extern int g_target_00e024b0;
// @fnv 0x00e024b0
// src: GUESS 0x00e024b0 (confidence: low)
void* Runtime_GetTarget00e024b0Address()
{
    return &g_target_00e024b0;
}

extern int DAT_010ea0a4;

// @fnv 0x00e024d0
// src: GUESS 0x00e024d0 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e024d0()
{
    return reinterpret_cast<int>(&DAT_010ea0a4);
}

extern int DAT_0126e9f0;

// @fnv 0x00e024f0
// src: GUESS 0x00e024f0 (confidence: low)
int* __cdecl Runtime_GetDAT0126e9f0Address()
{
    return &DAT_0126e9f0;
}

struct E02520Object
{
    virtual void Destroy(bool bFree);
};

// @fnv 0x00e02520
// src: GUESS 0x00e02520 (confidence: medium)
void Object_Destroy_Thunk_00e02520(E02520Object* pkObject)
{
    pkObject->Destroy(false);
}

namespace fnv_00e02530 {
struct GlobalObject
{
    int unk00;
};
extern GlobalObject g_global;

// @fnv 0x00e02530
// src: GUESS 0x00e02530 (confidence: high)
GlobalObject* __cdecl Runtime_GetGlobalAddress()
{
    return &g_global;
}
}  // namespace fnv_00e02530

extern int DAT_010ea10c;

// @fnv 0x00e02550
// src: GUESS 0x00e02550 (confidence: low)
void* Runtime_GetDAT010ea10cAddress()
{
    return &DAT_010ea10c;
}

extern unsigned char DAT_0126ea80;

// @fnv 0x00e02570
// src: GUESS 0x00e02570 (confidence: low)
void* __cdecl Runtime_GetDAT0126ea80Address()
{
    return &DAT_0126ea80;
}

extern int DAT_010ea154;

// @fnv 0x00e02590
// src: GUESS 0x00e02590 (confidence: low)
int __cdecl Runtime_EvaluateValue_00e02590()
{
    return reinterpret_cast<int>(&DAT_010ea154);
}

namespace fnv_00e025a0 {
extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e025a0_cls
{
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    void* m_p08;
    int m_0c;
    int m_10;

    FUN_00e025a0_cls* FUN_00e025a0(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Frees the array buffer via the audio allocator, resets the object's fields and vtable, and optionally frees the object itself when acFlags bit 0 is set.
// @fnv 0x00e025a0
FUN_00e025a0_cls* FUN_00e025a0_cls::FUN_00e025a0(unsigned char acFlags)
{
    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    int count = m_10;
    m_0c = 0;
    if (((unsigned int)count & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_p08, static_cast<unsigned int>((count & 0x3fffffff) * 16));
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
}  // namespace fnv_00e025a0

extern int DAT_0126eac8;

// @fnv 0x00e02620
// src: GUESS 0x00e02620 (confidence: low)
void* Object_GetGlobalObjectAddress_00e02620()
{
    return &DAT_0126eac8;
}

extern int DAT_010ea188;

// @fnv 0x00e02640
// src: GUESS 0x00e02640 (confidence: low)
int __cdecl Object_ComputeValue_00e02640()
{
    return reinterpret_cast<int>(&DAT_010ea188);
}

extern unsigned char DAT_0126eb10;
// @fnv 0x00e026d0
// src: GUESS 0x00e026d0 (confidence: low)
unsigned char* __cdecl Runtime_GetDAT0126eb10Address()
{
    return &DAT_0126eb10;
}

extern int DAT_010ea1ac;

// @fnv 0x00e026f0
// src: GUESS 0x00e026f0 (confidence: low)
int* Runtime_GetDAT010ea1acAddress()
{
    return &DAT_010ea1ac;
}

class E02700Object
{
  public:
    void Process(void* pvData);
};

// @fnv 0x00e02700
// src: GUESS 0x00e02700 (confidence: low)
void __cdecl Object_ProcessState_00e02700(E02700Object* pkObject, void* pvData)
{
    if (pkObject)
        pkObject->Process(pvData);
}

extern int g_0126eb58;

// @fnv 0x00e02750
// src: GUESS 0x00e02750 (confidence: low)
int* __cdecl Runtime_GetField0126eb58Address()
{
    return &g_0126eb58;
}

extern int DAT_0126eba0;

// @fnv 0x00e02770
// src: GUESS 0x00e02770 (confidence: low)
int* __cdecl Runtime_GetDAT0126eba0Address()
{
    return &DAT_0126eba0;
}

extern int DAT_010c9314;

// @fnv 0x00e027a0
// src: GUESS 0x00e027a0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00e027a0()
{
    return &DAT_010c9314;
}

// @fnv 0x00e030c0
int __cdecl ReadIntAtOffset(int index, int* data)
{
    int base = *data;
    *data = base + 4;
    return *(int*)(base + index);
}

// @fnv 0x00e04a80
void __cdecl UpdateStateFlags(void* pData)
{
    unsigned char* bytes = (unsigned char*)pData;
    unsigned short* flags = (unsigned short*)((unsigned char*)pData + 0x10);
    unsigned char state;

    if (bytes[0x0c] == 0x13)
    {
        unsigned char value = bytes[0x0d];
        unsigned short mask = 0x0400;
        bytes[0x0c] = value;
        bytes[0x0d] = 0;
        *flags |= mask;
    }

    state = bytes[0x0c];
    if (state == 0x18 || state == 0x1f)
    {
        unsigned char mask8 = 8;

        if ((*flags & mask8) != 0)
        {
            unsigned short mask = 0xfff7;
            bytes[0x0d] = 4;
            *flags &= mask;
        }

        if ((*flags & 0x10) != 0)
        {
            unsigned short mask = 0xffef;
            bytes[0x0d] = 6;
            *flags &= mask;
        }

        if ((*flags & 0x20) != 0)
        {
            bytes[0x0d] = mask8;
            *flags &= 0xffdf;
        }
    }
}

namespace fnv_00e05d10 {
extern int DAT_010d77d8;
extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __fastcall FUN_00c905b0(void* selfVal);

struct FUN_00e05d10_sub
{
    int unk00;
    void Release();
};

struct FUN_00e05d10_cls
{
    int m_vptr00;
    int unk04;
    void* m_p08;
    void* m_p0c;
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
    void* m_p50;
    int m_54;
    unsigned int m_58;
    void* m_p5c;
    int m_60;
    unsigned int m_64;
    void* m_p68;
    int m_6c;
    unsigned int m_70;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAc;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBc;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCc;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDc;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEc;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    FUN_00e05d10_sub m_114;

    void UpdateState_00e05d10();
};

// @fnv 0x00e05d10
// src: GUESS 0x00e05d10 (confidence: low)
void FUN_00e05d10_cls::UpdateState_00e05d10()
{
    m_vptr00 = (int)&DAT_010d77d8;
    if (m_p08 != 0)
    {
        FUN_00c905b0(m_p08);
    }
    if (m_p0c != 0)
    {
        FUN_00c905b0(m_p0c);
    }
    m_114.Release();

    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    unsigned int uCap = m_70;
    m_6c = 0;
    if ((uCap & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_p68, uCap & 0x3fffffffu);
    }
    m_p68 = 0;
    m_70 = 0x80000000u;

    pHolder = hkMemoryRouter_getInstance();
    pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    uCap = m_64;
    m_60 = 0;
    if ((uCap & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_p5c, (uCap & 0x3fffffffu) * 32);
    }
    m_p5c = 0;
    m_64 = 0x80000000u;

    pHolder = hkMemoryRouter_getInstance();
    pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
    uCap = m_58;
    m_54 = 0;
    if ((uCap & 0x80000000u) == 0)
    {
        pAllocator->bufFree(m_p50, uCap & 0x3fffffffu);
    }
    m_58 = 0x80000000u;
    m_p50 = 0;
    *(volatile int*)&m_vptr00 = (int)&DAT_0102e388;
}
}  // namespace fnv_00e05d10

void __cdecl ReverseBytesInGroupsOfFour(unsigned char* p);

// Swaps bytes at offsets 0x18/0x1b and 0x19/0x1a of p, then calls ReverseBytesInGroupsOfFour on p+0x20.
// @fnv 0x00e05e20
void __cdecl SwapHeaderBytesAndAdvance(unsigned char* pBuffer)
{
    volatile unsigned char* vp = (volatile unsigned char*)pBuffer;
    unsigned char a = pBuffer[0x1b];
    unsigned char b = pBuffer[0x18];
    vp[0x18] = a;
    vp[0x1b] = b;
    unsigned char* q = pBuffer + 0x1a;
    unsigned char c = *q;
    unsigned char d = pBuffer[0x19];
    pBuffer[0x19] = c;
    *q = d;
    pBuffer += 0x20;
    ReverseBytesInGroupsOfFour(pBuffer);
}

namespace std {
template <class T> inline void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
}

void __cdecl ReverseBytesInGroupsOfFour(unsigned char* p);

// Swaps byte pairs within three 4-byte groups of p, then calls ReverseBytesInGroupsOfFour on p + 16.
// @fnv 0x00e05e50
void __cdecl SwapQuadBytes(unsigned char* pData)
{
    std::swap(pData[4], pData[7]);
    std::swap(pData[5], pData[6]);
    std::swap(pData[8], pData[11]);
    std::swap(pData[9], pData[10]);
    std::swap(pData[12], pData[15]);
    std::swap(pData[13], pData[14]);

    return ReverseBytesInGroupsOfFour(pData + 16);
}

// Swaps byte pairs at offsets 4/7, 5/6, 8/11 and 9/10 of the buffer through a volatile pointer.
// @fnv 0x00e05eb0
// src: HAVOK_LIB 0x00e05eb0
void __cdecl hkpSaveContactPointsEndianUtil_swapEndianType(unsigned char* pBuffer)
{
    volatile unsigned char* v = (volatile unsigned char*)pBuffer;
    unsigned int a;
    unsigned char b;
    a = pBuffer[7];
    b = pBuffer[4];
    v[4] = (unsigned char)a;
    v[7] = b;
    b = pBuffer[5];
    a = v[6];
    v[5] = (unsigned char)a;
    v[6] = b;
    b = pBuffer[8];
    a = v[11];
    v[8] = (unsigned char)a;
    v[11] = b;
    b = pBuffer[9];
    a = v[10];
    v[9] = (unsigned char)a;
    v[10] = b;
}

inline void E05F60Swap(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}

inline void E05F60SwapBytes(void* pv, int iSize)
{
    char* pLo = static_cast<char*>(pv);
    char* pHi = pLo + iSize - 1;
    for (int j = 0; j < iSize / 2; j++)
        E05F60Swap(pLo[j], pHi[-j]);
}

struct E05F60Header
{
    unsigned short m_shorts[3];
    unsigned short unk06;
    unsigned int m_auiHeaderValues[3];
    unsigned int m_value0;
    unsigned int m_value1;
};

// Byte-swaps the three shorts, three ints and two trailing ints of the header to reverse endianness.
// @fnv 0x00e05f60
void __cdecl SwapHeaderEndianness(E05F60Header* pkHeader)
{
    int i = 0;
    do
    {
        E05F60SwapBytes(&pkHeader->m_shorts[i], 2);
        E05F60SwapBytes(&pkHeader->m_auiHeaderValues[i], 4);
    } while (++i < 3);
    E05F60SwapBytes(&pkHeader->m_value0, 4);
    E05F60SwapBytes(&pkHeader->m_value1, 4);
}

// @fnv 0x00e05fe0
// src: HAVOK_LIB 0x00e05fe0
void __cdecl hkpSaveContactPointsEndianUtil_swapEndianType_00e05fe0(unsigned char* pBuffer)
{
    for (int i = 0; i < 4; i++)
    {
        unsigned char hi = pBuffer[i * 2 + 1];
        unsigned char lo = pBuffer[i * 2];
        ((volatile unsigned char*)pBuffer)[i * 2] = hi;
        ((volatile unsigned char*)pBuffer)[i * 2 + 1] = lo;
    }
}

// @fnv 0x00e06010
// src: HAVOK_LIB 0x00e06010
void __cdecl hkpSaveContactPointsEndianUtil_swapEndianType_00e06010(unsigned char* pucBuffer)
{
    int i;
    unsigned char* e;
    unsigned char t;

    i = 0;
    if (pucBuffer[2] > 0)
    {
        e = pucBuffer + 6;
        do
        {
            t = e[0];
            e[0] = e[1];
            e[1] = t;
            e += 8;
            i++;
        } while (i < pucBuffer[2]);
    }

    {
        int n = pucBuffer[0] + pucBuffer[1];
        unsigned char* f = pucBuffer + pucBuffer[2] * 8 + 4;
        unsigned char* q;
        i = 0;
        if (n > 0)
        {
            do
            {
                unsigned char& x = f[i * 2];
                unsigned char& y = f[i * 2 + 1];
                t = x;
                x = y;
                y = t;
                i++;
            } while (i < n);
        }
    }
}

// @fnv 0x00e09620
// src: GUESS 0x00e09620 (confidence: low)
int __cdecl Object_ComputeValue_00e09620()
{
    return 13;
}

struct SearchItem
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C;
    double m_key;
    unsigned int unk48, unk4C, unk50;
    int m_type;
};

struct SearchContainer
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    SearchItem** m_items;
    int m_uiItemCount;
};

// @fnv 0x00e10820
// src: HAVOK_LIB 0x00e10820
SearchItem* findChildNode(SearchContainer* c, double key, int aiFieldIndex)
{
    int lo = 0;
    int hi = c->m_uiItemCount;
    if (hi > 2)
    {
        SearchItem** items = c->m_items;
        do
        {
            int mid = (hi + lo) >> 1;
            SearchItem* it = items[mid];
            if (it->m_type == 2)
            {
                break;
            }
            if (key < it->m_key)
            {
                hi = mid;
            }
            else
            {
                lo = mid;
            }
        } while (hi - lo > 2);
    }
    int i = lo;
    if (i >= hi)
    {
        return 0;
    }
    SearchItem** p = c->m_items + i;
    for (; i < hi; i++, p++)
    {
        SearchItem* it = *p;
        if (it->m_type == 2)
        {
            continue;
        }
        float f = ((float*)it)[aiFieldIndex];
        if ((double)f + it->m_key >= key)
        {
            if (key >= it->m_key)
            {
                return it;
            }
            break;
        }
    }
    return 0;
}

struct FUN_00e10a00_cls
{
    int m_00;

    FUN_00e10a00_cls* return_input_and_0_it_1();
};

// @fnv 0x00e10a00
// src: COMMUNITY 0x00e10a00
FUN_00e10a00_cls* FUN_00e10a00_cls::return_input_and_0_it_1()
{
    this->m_00 = 0;
    return this;
}

// FUN_00e114f0: thiscall, 3 unused stack params, sets a flag byte at +0x100.
class FUN_00e114f0_cls
{
  public:
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
    int m_a0;
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
    unsigned char m_100;
    void __thiscall SetField100(int a1, int a2, int a3);
};

// @fnv 0x00e114f0
// src: GUESS 0x00e114f0 (confidence: low)
void __thiscall FUN_00e114f0_cls::SetField100(int a1, int a2, int a3)
{
    m_100 = 1;
}

struct FlagObjectPad
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
    unsigned char m_flag100;
};

class FUN_00e11500_cls : public FlagObjectPad
{
  public:
    void SetFlag100_00e11500(int a1, int a2);
};

// @fnv 0x00e11500
// src: GUESS 0x00e11500 (confidence: medium)
void FUN_00e11500_cls::SetFlag100_00e11500(int a1, int a2)
{
    m_flag100 = 1;
}

struct FUN_00e11510_obj
{
    void __thiscall UpdateState_00e11510(int a, int b);
};

// @fnv 0x00e11510
// src: GUESS 0x00e11510 (confidence: low)
void FUN_00e11510_obj::UpdateState_00e11510(int a, int b)
{
    ((char*)this)[0x100] = 1;
}

struct FUN_00e11520_class
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    char flag100;
    void SetFlag100_00e11520(int a, int b);
};
// @fnv 0x00e11520
// src: GUESS 0x00e11520 (confidence: medium)
void FUN_00e11520_class::SetFlag100_00e11520(int a, int b)
{
    flag100 = 1;
}

class hkMemberE00
{
  public:
    hkMemberE00(FinishingFlag flag) throw();

    int unk00;
    int unk04;
    int unk08;
};
class hkBaseE00
{
  public:
    __forceinline hkBaseE00(FinishingFlag flag) : m_kMemberDescriptor(flag)
    {}
    virtual ~hkBaseE00();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkSmallArray<int> m_ppData;
    hkMemberE00 m_kMemberDescriptor;
};
class hkMidE00 : public hkBaseE00
{
  public:
    __forceinline hkMidE00(FinishingFlag flag) : hkBaseE00(flag)
    {
        m_iType = -16;
    }
    virtual ~hkMidE00();

    int m_iType;
};
class hkDerivedE00 : public hkMidE00
{
  public:
    __forceinline hkDerivedE00(FinishingFlag flag) : hkMidE00(flag)
    {}
    virtual ~hkDerivedE00();
};
// If pvObject is non-null, placement-constructs an hkDerivedE00 at that address using iFinishing as the finish-loaded flag.
// @fnv 0x00e00240
void __cdecl ConstructDerivedObject(void* pvObject, int iFinishing)
{
    if (pvObject)
    {
        FinishingFlag flag;
        flag.m_bFinishing = iFinishing;
        new (pvObject) hkDerivedE00(flag);
    }
}

// Returns the null-terminated string at base + *offset, advances *offset past the string plus padding to a 4-byte boundary.
// @fnv 0x00e02f30
char* __cdecl ReadPaddedString(char* base, int* piOffset)
{
    char* s = base + *piOffset;
    unsigned int n = 0;
    if (s[0] != 0)
    {
        do
        {
            ++n;
        } while (s[n] != 0);
    }
    ++n;
    while ((n & 3) != 0)
    {
        ++n;
    }
    *piOffset += n;
    return s;
}

class BE04D90Allocator;
hkMemoryRouter* BE04D90GetRouter() throw();


class BE04D90PointerMap
{
  public:
    BE04D90PointerMap() : m_pPointerArray(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~BE04D90PointerMap() throw();

    void Init(BE04D90Allocator* pkAlloc, int iCapacity) throw();
    void ClearAndDeallocate(BE04D90Allocator* pkAlloc) throw();

    void* m_pPointerArray;
    int m_iCapacityFlags;
    int m_iPairCount;
};

class BE04D90Object;

void __cdecl RegisterContextHandlers(BE04D90Object* pkObject, BE04D90PointerMap* pkMap, int iArg) throw();

// Initializes a pointer map, calls RegisterContextHandlers for each non-null object in ppkObjects, then clears and deallocates the map.
// @fnv 0x00e04d90
void __cdecl ProcessObjectArray(BE04D90Object** ppkObjects, int iArg)
{
    BE04D90PointerMap kMap;
    BE04D90Allocator* pkHeap = reinterpret_cast<BE04D90Allocator*>(BE04D90GetRouter()->m_heap);
    kMap.Init(pkHeap, 0);
    for (int i = 0; ppkObjects[i]; i++)
        RegisterContextHandlers(ppkObjects[i], &kMap, iArg);
    kMap.ClearAndDeallocate(reinterpret_cast<BE04D90Allocator*>(BE04D90GetRouter()->m_heap));
}

struct Payload
{
    float x, y;
    union
    {
        float z;
        unsigned int zbits;
        struct
        {
            unsigned char z0, z1, z2, z3;
        };
    };
    unsigned int flags;
};
struct Input
{
    unsigned char type, selector, unk02, component;
    unsigned int unk04, unk08, unk0c;
    Payload a, b, c;
};
struct Entry
{
    unsigned int key;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38,
        unk3c, unk40, unk44, unk48, unk4c;
};
struct Context
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    unsigned int unk0e48;
    unsigned int unk0e4c;
    unsigned int unk0e50;
    unsigned int unk0e54;
    unsigned int unk0e58;
    unsigned int unk0e5c;
    unsigned int unk0e60;
    unsigned int unk0e64;
    unsigned int unk0e68;
    unsigned int unk0e6c;
    unsigned int unk0e70;
    unsigned int unk0e74;
    unsigned int unk0e78;
    unsigned int unk0e7c;
    unsigned int unk0e80;
    unsigned int unk0e84;
    unsigned int unk0e88;
    unsigned int unk0e8c;
    unsigned int unk0e90;
    unsigned int unk0e94;
    unsigned int unk0e98;
    unsigned int unk0e9c;
    unsigned int unk0ea0;
    unsigned int unk0ea4;
    unsigned int unk0ea8;
    unsigned int unk0eac;
    unsigned int unk0eb0;
    unsigned int unk0eb4;
    unsigned int unk0eb8;
    unsigned int unk0ebc;
    unsigned int unk0ec0;
    unsigned int unk0ec4;
    unsigned int unk0ec8;
    unsigned int unk0ecc;
    unsigned int unk0ed0;
    unsigned int unk0ed4;
    unsigned int unk0ed8;
    unsigned int unk0edc;
    unsigned int unk0ee0;
    unsigned int unk0ee4;
    unsigned int unk0ee8;
    unsigned int unk0eec;
    unsigned int unk0ef0;
    unsigned int unk0ef4;
    unsigned int unk0ef8;
    unsigned int unk0efc;
    unsigned int unk0f00;
    unsigned int unk0f04;
    unsigned int unk0f08;
    unsigned int unk0f0c;
    unsigned int unk0f10;
    unsigned int unk0f14;
    unsigned int unk0f18;
    unsigned int unk0f1c;
    unsigned int unk0f20;
    unsigned int unk0f24;
    unsigned int unk0f28;
    unsigned int unk0f2c;
    unsigned int unk0f30;
    unsigned int unk0f34;
    unsigned int unk0f38;
    unsigned int unk0f3c;
    unsigned int unk0f40;
    unsigned int unk0f44;
    unsigned int unk0f48;
    unsigned int unk0f4c;
    unsigned int unk0f50;
    unsigned int unk0f54;
    unsigned int unk0f58;
    unsigned int unk0f5c;
    unsigned int unk0f60;
    unsigned int unk0f64;
    unsigned int unk0f68;
    unsigned int unk0f6c;
    unsigned int unk0f70;
    unsigned int unk0f74;
    unsigned int unk0f78;
    unsigned int unk0f7c;
    unsigned int unk0f80;
    unsigned int unk0f84;
    unsigned int unk0f88;
    unsigned int unk0f8c;
    unsigned int unk0f90;
    unsigned int unk0f94;
    unsigned int unk0f98;
    unsigned int unk0f9c;
    unsigned int unk0fa0;
    unsigned int unk0fa4;
    unsigned int unk0fa8;
    unsigned int unk0fac;
    unsigned int unk0fb0;
    unsigned int unk0fb4;
    unsigned int unk0fb8;
    unsigned int unk0fbc;
    unsigned int unk0fc0;
    unsigned int unk0fc4;
    unsigned int unk0fc8;
    unsigned int unk0fcc;
    unsigned int unk0fd0;
    unsigned int unk0fd4;
    unsigned int unk0fd8;
    unsigned int unk0fdc;
    unsigned int unk0fe0;
    unsigned int unk0fe4;
    unsigned int unk0fe8;
    unsigned int unk0fec;
    unsigned int unk0ff0;
    unsigned int unk0ff4;
    unsigned int unk0ff8;
    unsigned int unk0ffc;
    unsigned int unk1000;
    unsigned int unk1004;
    unsigned int unk1008;
    unsigned int unk100c;
    unsigned int unk1010;
    unsigned int unk1014;
    unsigned int unk1018;
    unsigned int unk101c;
    unsigned int unk1020;
    unsigned int unk1024;
    unsigned int unk1028;
    unsigned int unk102c;
    unsigned int unk1030;
    unsigned int unk1034;
    unsigned int unk1038;
    unsigned int unk103c;
    unsigned int unk1040;
    unsigned int unk1044;
    unsigned int unk1048;
    unsigned int unk104c;
    unsigned int unk1050;
    unsigned int unk1054;
    unsigned int unk1058;
    unsigned int unk105c;
    unsigned int unk1060;
    unsigned int unk1064;
    unsigned int unk1068;
    unsigned int unk106c;
    unsigned int unk1070;
    unsigned int unk1074;
    unsigned int unk1078;
    unsigned int unk107c;
    unsigned int unk1080;
    unsigned int unk1084;
    unsigned int unk1088;
    unsigned int unk108c;
    unsigned int unk1090;
    unsigned int unk1094;
    unsigned int unk1098;
    unsigned int unk109c;
    unsigned int unk10a0;
    unsigned int unk10a4;
    unsigned int unk10a8;
    unsigned int unk10ac;
    unsigned int unk10b0;
    unsigned int unk10b4;
    unsigned int unk10b8;
    unsigned int unk10bc;
    unsigned int unk10c0;
    unsigned int unk10c4;
    unsigned int unk10c8;
    unsigned int unk10cc;
    unsigned int unk10d0;
    unsigned int unk10d4;
    unsigned int unk10d8;
    unsigned int unk10dc;
    unsigned int unk10e0;
    unsigned int unk10e4;
    unsigned int unk10e8;
    unsigned int unk10ec;
    unsigned int unk10f0;
    unsigned int unk10f4;
    unsigned int unk10f8;
    unsigned int unk10fc;
    unsigned int unk1100;
    unsigned int unk1104;
    unsigned int unk1108;
    unsigned int unk110c;
    unsigned int unk1110;
    unsigned int unk1114;
    unsigned int unk1118;
    unsigned int unk111c;
    unsigned int unk1120;
    unsigned int unk1124;
    unsigned int unk1128;
    unsigned int unk112c;
    unsigned int unk1130;
    unsigned int unk1134;
    unsigned int unk1138;
    unsigned int unk113c;
    unsigned int unk1140;
    unsigned int unk1144;
    unsigned int unk1148;
    unsigned int unk114c;
    unsigned int unk1150;
    unsigned int unk1154;
    unsigned int unk1158;
    unsigned int unk115c;
    unsigned int unk1160;
    unsigned int unk1164;
    unsigned int unk1168;
    unsigned int unk116c;
    unsigned int unk1170;
    unsigned int unk1174;
    unsigned int unk1178;
    unsigned int unk117c;
    unsigned int unk1180;
    unsigned int unk1184;
    unsigned int unk1188;
    unsigned int unk118c;
    unsigned int unk1190;
    unsigned int unk1194;
    unsigned int unk1198;
    unsigned int unk119c;
    unsigned int unk11a0;
    unsigned int unk11a4;
    unsigned int unk11a8;
    unsigned int unk11ac;
    unsigned int unk11b0;
    unsigned int unk11b4;
    unsigned int unk11b8;
    unsigned int unk11bc;
    unsigned int unk11c0;
    unsigned int unk11c4;
    unsigned int unk11c8;
    unsigned int unk11cc;
    unsigned int unk11d0;
    unsigned int unk11d4;
    unsigned int unk11d8;
    unsigned int unk11dc;
    unsigned int unk11e0;
    unsigned int unk11e4;
    unsigned int unk11e8;
    unsigned int unk11ec;
    unsigned int unk11f0;
    unsigned int unk11f4;
    unsigned int unk11f8;
    unsigned int unk11fc;
    unsigned int unk1200;
    unsigned int unk1204;
    unsigned int unk1208;
    unsigned int unk120c;
    unsigned int unk1210;
    unsigned int unk1214;
    unsigned int unk1218;
    unsigned int unk121c;
    unsigned int unk1220;
    unsigned int unk1224;
    unsigned int unk1228;
    unsigned int unk122c;
    unsigned int unk1230;
    unsigned int unk1234;
    unsigned int unk1238;
    unsigned int unk123c;
    unsigned int unk1240;
    unsigned int unk1244;
    unsigned int unk1248;
    unsigned int unk124c;
    unsigned int unk1250;
    unsigned int unk1254;
    unsigned int unk1258;
    unsigned int unk125c;
    unsigned int unk1260;
    unsigned int unk1264;
    unsigned int unk1268;
    unsigned int unk126c;
    unsigned int unk1270;
    unsigned int unk1274;
    unsigned int unk1278;
    unsigned int unk127c;
    unsigned int unk1280;
    unsigned int unk1284;
    unsigned int unk1288;
    unsigned int unk128c;
    unsigned int unk1290;
    unsigned int unk1294;
    unsigned int unk1298;
    unsigned int unk129c;
    unsigned int unk12a0;
    unsigned int unk12a4;
    unsigned int unk12a8;
    unsigned int unk12ac;
    unsigned int unk12b0;
    unsigned int unk12b4;
    unsigned int unk12b8;
    unsigned int unk12bc;
    unsigned int unk12c0;
    unsigned int unk12c4;
    unsigned int unk12c8;
    unsigned int unk12cc;
    unsigned int unk12d0;
    unsigned int unk12d4;
    unsigned int unk12d8;
    unsigned int unk12dc;
    unsigned int unk12e0;
    unsigned int unk12e4;
    unsigned int unk12e8;
    unsigned int unk12ec;
    unsigned int unk12f0;
    unsigned int unk12f4;
    unsigned int unk12f8;
    unsigned int unk12fc;
    unsigned int unk1300;
    unsigned int unk1304;
    unsigned int unk1308;
    unsigned int unk130c;
    unsigned int unk1310;
    unsigned int unk1314;
    unsigned int unk1318;
    unsigned int unk131c;
    unsigned int unk1320;
    unsigned int unk1324;
    unsigned int unk1328;
    unsigned int unk132c;
    unsigned int unk1330;
    unsigned int unk1334;
    unsigned int unk1338;
    unsigned int unk133c;
    unsigned int unk1340;
    unsigned int unk1344;
    unsigned int unk1348;
    unsigned int unk134c;
    unsigned int unk1350;
    unsigned int unk1354;
    unsigned int unk1358;
    unsigned int unk135c;
    unsigned int unk1360;
    unsigned int unk1364;
    unsigned int unk1368;
    unsigned int unk136c;
    unsigned int unk1370;
    unsigned int unk1374;
    unsigned int unk1378;
    unsigned int unk137c;
    unsigned int unk1380;
    unsigned int unk1384;
    unsigned int unk1388;
    unsigned int unk138c;
    unsigned int unk1390;
    unsigned int unk1394;
    unsigned int unk1398;
    unsigned int unk139c;
    unsigned int unk13a0;
    unsigned int unk13a4;
    unsigned int unk13a8;
    unsigned int unk13ac;
    unsigned int unk13b0;
    unsigned int unk13b4;
    unsigned int unk13b8;
    unsigned int unk13bc;
    unsigned int unk13c0;
    unsigned int unk13c4;
    unsigned int unk13c8;
    unsigned int unk13cc;
    unsigned int unk13d0;
    unsigned int unk13d4;
    unsigned int unk13d8;
    unsigned int unk13dc;
    unsigned int unk13e0;
    unsigned int unk13e4;
    unsigned int unk13e8;
    unsigned int unk13ec;
    unsigned int unk13f0;
    unsigned int unk13f4;
    unsigned int unk13f8;
    unsigned int unk13fc;
    unsigned int unk1400;
    unsigned int unk1404;
    unsigned int unk1408;
    unsigned int unk140c;
    unsigned int unk1410;
    unsigned int unk1414;
    unsigned int unk1418;
    unsigned int unk141c;
    unsigned int unk1420;
    unsigned int unk1424;
    unsigned int unk1428;
    unsigned int unk142c;
    unsigned int unk1430;
    unsigned int unk1434;
    unsigned int unk1438;
    unsigned int unk143c;
    unsigned int unk1440;
    unsigned int unk1444;
    unsigned int unk1448;
    unsigned int unk144c;
    unsigned int unk1450;
    unsigned int unk1454;
    unsigned int unk1458;
    unsigned int unk145c;
    unsigned int unk1460;
    unsigned int unk1464;
    unsigned int unk1468;
    unsigned int unk146c;
    unsigned int unk1470;
    unsigned int unk1474;
    unsigned int unk1478;
    unsigned int unk147c;
    unsigned int unk1480;
    unsigned int unk1484;
    unsigned int unk1488;
    unsigned int unk148c;
    unsigned int unk1490;
    unsigned int unk1494;
    unsigned int unk1498;
    unsigned int unk149c;
    unsigned int unk14a0;
    unsigned int unk14a4;
    unsigned int unk14a8;
    unsigned int unk14ac;
    unsigned int unk14b0;
    unsigned int unk14b4;
    unsigned int unk14b8;
    unsigned int unk14bc;
    unsigned int unk14c0;
    unsigned int unk14c4;
    unsigned int unk14c8;
    unsigned int unk14cc;
    unsigned int unk14d0;
    unsigned int unk14d4;
    unsigned int unk14d8;
    unsigned int unk14dc;
    unsigned int unk14e0;
    unsigned int unk14e4;
    unsigned int unk14e8;
    unsigned int unk14ec;
    unsigned int unk14f0;
    unsigned int unk14f4;
    unsigned int unk14f8;
    unsigned int unk14fc;
    unsigned int unk1500;
    unsigned int unk1504;
    unsigned int unk1508;
    unsigned int unk150c;
    unsigned int unk1510;
    unsigned int unk1514;
    unsigned int unk1518;
    unsigned int unk151c;
    unsigned int unk1520;
    unsigned int unk1524;
    unsigned int unk1528;
    unsigned int unk152c;
    unsigned int unk1530;
    unsigned int unk1534;
    unsigned int unk1538;
    unsigned int unk153c;
    unsigned int unk1540;
    unsigned int unk1544;
    unsigned int unk1548;
    unsigned int unk154c;
    unsigned int unk1550;
    unsigned int unk1554;
    unsigned int unk1558;
    unsigned int unk155c;
    unsigned int unk1560;
    unsigned int unk1564;
    unsigned int unk1568;
    unsigned int unk156c;
    unsigned int unk1570;
    unsigned int unk1574;
    unsigned int unk1578;
    unsigned int unk157c;
    unsigned int unk1580;
    unsigned int unk1584;
    unsigned int unk1588;
    unsigned int unk158c;
    unsigned int unk1590;
    unsigned int unk1594;
    unsigned int unk1598;
    unsigned int unk159c;
    unsigned int unk15a0;
    unsigned int unk15a4;
    unsigned int unk15a8;
    unsigned int unk15ac;
    unsigned int unk15b0;
    unsigned int unk15b4;
    unsigned int unk15b8;
    unsigned int unk15bc;
    unsigned int unk15c0;
    unsigned int unk15c4;
    unsigned int unk15c8;
    unsigned int unk15cc;
    unsigned int unk15d0;
    unsigned int unk15d4;
    unsigned int unk15d8;
    unsigned int unk15dc;
    unsigned int unk15e0;
    unsigned int unk15e4;
    unsigned int unk15e8;
    unsigned int unk15ec;
    unsigned int unk15f0;
    unsigned int unk15f4;
    unsigned int unk15f8;
    unsigned int unk15fc;
    unsigned int unk1600;
    unsigned int unk1604;
    unsigned int unk1608;
    unsigned int unk160c;
    unsigned int unk1610;
    unsigned int unk1614;
    unsigned int unk1618;
    unsigned int unk161c;
    unsigned int unk1620;
    unsigned int unk1624;
    unsigned int unk1628;
    unsigned int unk162c;
    unsigned int unk1630;
    unsigned int unk1634;
    unsigned int unk1638;
    unsigned int unk163c;
    unsigned int unk1640;
    unsigned int unk1644;
    unsigned int unk1648;
    unsigned int unk164c;
    unsigned int unk1650;
    unsigned int unk1654;
    unsigned int unk1658;
    unsigned int unk165c;
    unsigned int unk1660;
    unsigned int unk1664;
    unsigned int unk1668;
    unsigned int unk166c;
    unsigned int unk1670;
    unsigned int unk1674;
    unsigned int unk1678;
    unsigned int unk167c;
    unsigned int unk1680;
    unsigned int unk1684;
    unsigned int unk1688;
    unsigned int unk168c;
    unsigned int unk1690;
    unsigned int unk1694;
    unsigned int unk1698;
    unsigned int unk169c;
    unsigned int unk16a0;
    unsigned int unk16a4;
    unsigned int unk16a8;
    unsigned int unk16ac;
    unsigned int unk16b0;
    unsigned int unk16b4;
    unsigned int unk16b8;
    unsigned int unk16bc;
    unsigned int unk16c0;
    unsigned int unk16c4;
    unsigned int unk16c8;
    unsigned int unk16cc;
    unsigned int unk16d0;
    unsigned int unk16d4;
    unsigned int unk16d8;
    Entry entries[256];
};
void SwapHeaderBytesAndAdvance(Input*);
void SwapQuadBytes(Input*);
void hkpSaveContactPointsEndianUtil_swapEndianType(Input*);
int hkpSaveContactPointsUtil_getSerializedAgentType(unsigned int);
void SwapHkHeaderE05E(Payload*);
void SwapHeaderEndianness(Payload*);
void hkpSaveContactPointsEndianUtil_swapEndianType_00e05fe0(Payload*);
void hkpSaveContactPointsEndianUtil_swapEndianType_00e06010(void*);
void ProcessListBlocks(Context**, void*);
// Dispatches input handling by input->type and reverse, selects a payload, then applies the operation from the context entry key to that payload.
// @fnv 0x00e06070
void ProcessInput(Context** context, Input* input, void* argument, bool reverse, int* type, bool* changed)
{
    *changed = false;
    Payload* payload;
    switch (input->type)
    {
    case 4:
    case 5:
    case 6:
    case 12:
    case 13:
    case 14:
        if (reverse)
        {
            payload = &input->c;
            SwapHeaderBytesAndAdvance(input);
        }
        else
        {
            payload = &input->b;
            SwapQuadBytes(input);
        }
        break;
    case 2:
    case 3:
    case 10:
    case 11:
        if (reverse)
            payload = &input->b;
        else
        {
            payload = &input->a;
            hkpSaveContactPointsEndianUtil_swapEndianType(input);
        }
        break;
    case 0:
    case 1:
        *type = 16;
        return;
    default:
        return;
    }
    int operation = hkpSaveContactPointsUtil_getSerializedAgentType((*context)->entries[input->selector].key);
    *type = input->component;
    switch (operation)
    {
    case 1:
        SwapHkHeaderE05E(payload);
        break;
    case 2:
        SwapHeaderEndianness(payload);
        break;
    case 3:
    case 4:
        hkpSaveContactPointsEndianUtil_swapEndianType_00e05fe0(payload);
        hkpSaveContactPointsEndianUtil_swapEndianType_00e06010(&payload->flags);
        break;
    case 5:
        if (payload->z3 & 0x20)
        {
            hkpSaveContactPointsEndianUtil_swapEndianType_00e05fe0(payload);
            hkpSaveContactPointsEndianUtil_swapEndianType_00e06010(&payload->flags);
        }
        else
        {
            ProcessListBlocks(context, argument);
            *changed = true;
        }
        break;
    case 6:
    case 7:
    case 8:
    case 9:
        ProcessListBlocks(context, argument);
        *changed = true;
        break;
    }
}

struct ListEntryE061
{
    int unk;
    int uTmpnk;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_18;
    int m_1c;
};

struct FlagE061
{
    unsigned char m_00;
    unsigned char unkCur;
    unsigned char unkValue;
    unsigned char uNewnk;
};

struct BlockE061
{
    int m_00;
};

struct ListE061
{
    BlockE061** m_00;
    int m_04;
    int unk08;
    ListEntryE061** m_0c;
    int m_10;
};

void __cdecl ProcessInput(int a1, char* pos, ListEntryE061* cur, FlagE061 flag, int* consumed, bool* pbOut);

// Iterates each block's payload, advancing a cursor entry and calling ProcessInput per chunk until the block end.
// @fnv 0x00e061c0
void __cdecl ProcessListBlocks(int a1, ListE061* list)
{
    ListEntryE061* cur;
    int j;
    if (list->m_10 != 0)
    {
        j = 0;
        cur = list->m_0c[0];
    }
    else
    {
        j = -1;
        cur = 0;
    }
    for (int i = 0; i < list->m_04; i++)
    {
        BlockE061* pBlock = list->m_00[i];
        char* end = (char*)pBlock + pBlock->m_00 + 0x10;
        char* pos = (char*)pBlock + 0x10;
        if (pos < end)
        {
            FlagE061 flag;
            flag.m_00 = 0;
            while (pos < end)
            {
                int consumed = 0;
                bool bOut;
                if (cur != 0 && (cur->m_18 != i || cur->m_1c < (int)(pos - (char*)pBlock - 0x10)))
                {
                    if (j + 1 < list->m_10)
                        cur = list->m_0c[++j];
                    else
                        cur = 0;
                }
                ProcessInput(a1, pos, cur, flag, &consumed, &bOut);
                pos += consumed;
            }
        }
    }
}

namespace fnv_00e18b70 {
struct Alloc
{
    virtual void v0();
    virtual void* alloc(int);
    virtual void free(void*, int);
    virtual void vC();
    virtual void ReturnMemory(void*, int);
};

struct Node
{
    Node* next;
    Node* prev;
    int u8, uC;
    int data10;
    int data14;
    int data18;
    int data1C;
    int data20;
    int data24;
    int data28;
    int data2C;
    int data30;
    int data34;
    int data38;
    int data3C;
    int data40;
    int data44;
};
struct Block
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
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    Node* freeHead;
    int used;
};
struct Pool
{
    Block** blocks;
    int count;
    int u8;
    Node* head;
    int size;
    Block* AllocateChainedSlotBlock();
    __forceinline Node* clone(Node* src)
    {
        Block* b;
        if (!count || !(b = *blocks)->freeHead)
            b = AllocateChainedSlotBlock();
        Node* n = b->freeHead;
        b->freeHead = n->next;
        ++b->used;
        n->data10 = src->data10;
        n->data14 = src->data14;
        n->data18 = src->data18;
        n->data1C = src->data1C;
        n->data20 = src->data20;
        n->data24 = src->data24;
        n->data28 = src->data28;
        n->data2C = src->data2C;
        n->data30 = src->data30;
        n->data34 = src->data34;
        n->data38 = src->data38;
        n->data3C = src->data3C;
        n->data40 = src->data40;
        n->data44 = src->data44;
        n->prev = 0;
        n->next = head;
        if (head)
            head->prev = n;
        ++size;
        head = n;
        return n;
    }
};
struct Array
{
    Node** data;
    int size;
    int capacity;
    Array() : data(0), size(0), capacity(0x80000000)
    {}
};
void __cdecl hkArrayUtil__reserve(Alloc*, Array*, int, int);
struct Entry
{
    Node* key;
    Array* value;
};
// distinct from NiTexturingProperty::Map: 0x00e18b70 uses entries/size/mask and open-address lookup; no vtable or texture-map state.
struct BlkMapView
{
    Entry* entries;
    int size;
    int mask;
    BlkMapView() : entries(0), size(0), mask(-1)
    {}
    void EnsureCapacity(Alloc*, int) throw();
    Array* LookupHashEntry(Node*, int) throw();
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Alloc*, Node*, Array*) throw();
    void ProcessArgument(Alloc*) throw();
    void Object_DoNothing() throw();
    int first()
    {
        int n = 0;
        while (n <= mask && entries[n].key == (Node*)-1)
            ++n;
        return n;
    }
    int next(int n)
    {
        ++n;
        while (n <= mask && entries[n].key == (Node*)-1)
            ++n;
        return n;
    }
};
struct Link
{
    Link* next;
    int u4;
    Node* nodes[3];
    int u14, u18, u1C, u20, u24, u28, u2C;
    int index;
};
struct Target
{
    int u0, u4;
    Pool pool;
    int u1C, u20, u24, u28;
    Link* links;
    int hkgpMesh_countParts();
    int ResolveLinkNodes();
};
// @fnv 0x00e18b70
int Target::ResolveLinkNodes()
{
    int total = hkgpMesh_countParts();
    int copies = 0;
    BlkMapView nodeMap;
    nodeMap.EnsureCapacity(&reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap()), 0);
    for (Link* link = links; link; link = link->next)
    {
        for (int j = 0; j < 3; ++j)
        {
            Node* search = link->nodes[j];
            Array* a = nodeMap.LookupHashEntry(search, 0);
            if (!a)
            {
                void* memory = reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap()).alloc(12);
                a = memory ? new (memory) Array : 0;
                Alloc* allocator = &reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap());
                int cap = a->capacity & 0x3fffffff;
                if (cap < total)
                {
                    int grown = cap * 2;
                    if (total >= grown)
                        grown = total;
                    hkArrayUtil__reserve(allocator, a, grown, 4);
                }
                int remaining = total - a->size;
                Node** end = a->data + a->size;
                for (; remaining > 0; --remaining)
                    *end++ = 0;
                a->size = total;
                Node* key = link->nodes[j];
                Alloc* heap = &reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap());
                nodeMap.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(heap, key, a);
            }
            a->data[link->index] = link->nodes[j];
        }
    }
    for (int it = nodeMap.first(); it <= nodeMap.mask; it = nodeMap.next(it))
    {
        Array* a = nodeMap.entries[it].value;
        Node* first = 0;
        for (int j = 0; j < a->size; ++j)
        {
            if (a->data[j])
            {
                if (first)
                {
                    a->data[j] = pool.clone(first);
                    ++copies;
                }
                else
                    first = a->data[j];
            }
        }
    }
    for (Link* link = links; link; link = link->next)
        for (int j = 0; j < 3; ++j)
        {
            Node* search = link->nodes[j];
            Array* a = nodeMap.LookupHashEntry(search, 0);
            link->nodes[j] = a->data[link->index];
        }
    for (int it = nodeMap.first(); it <= nodeMap.mask; it = nodeMap.next(it))
    {
        Array* a = nodeMap.entries[it].value;
        if (a)
        {
            Alloc* allocator = &reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap());
            a->size = 0;
            if ((a->capacity & 0x80000000) == 0)
                allocator->ReturnMemory(a->data, (a->capacity & 0x3fffffff) * 4);
            a->data = 0;
            a->capacity = 0x80000000;
            reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap()).free(a, 12);
        }
    }
    nodeMap.ProcessArgument(&reinterpret_cast<Alloc&>(hkMemoryRouter::getInstance().heap()));
    nodeMap.Object_DoNothing();
    return copies;
}
}  // namespace fnv_00e18b70

struct TimedEntry
{
    int field00, field04, field08;
    float time;
};
struct TimedEntryCollection
{
    int count;
    int capacity;
    TimedEntry** entries;
    TimedEntry* lastRemoved;
    void RemoveExpiredEntries(float threshold);
};
// Scans entries from the end and clears each whose time is below threshold, decrementing count and recording the last removed entry.
// @fnv 0x00e097a0
void TimedEntryCollection::RemoveExpiredEntries(float threshold)
{
    float limit = threshold;
    int iCount = count;
    int index = iCount - 1;
    if (index + 1 >= 4 && iCount - 1 == index)
    {
        do
        {
            if (!entries[index])
                return;
            TimedEntry* entry = entries[index];
            if (!(entry->time < limit))
                return;
            lastRemoved = entry;
            entries[index] = 0;
            --count;
            if (!entries[index - 1])
                return;
            entry = entries[index - 1];
            if (!(entry->time < limit))
                return;
            lastRemoved = entry;
            entries[index - 1] = 0;
            --count;
            if (!entries[index - 2])
                return;
            entry = entries[index - 2];
            if (!(entry->time < limit))
                return;
            lastRemoved = entry;
            entries[index - 2] = 0;
            --count;
            if (!entries[index - 3])
                return;
            entry = entries[index - 3];
            if (!(entry->time < limit))
                return;
            lastRemoved = entry;
            entries[index - 3] = 0;
            --count;
            index -= 4;
        } while (index >= 3);
    }
    if (index >= 0)
    {
    tail:
        if (!entries[index])
            return;
        if (!(entries[index]->time < limit))
            return;
        lastRemoved = entries[index];
        entries[index] = 0;
        --count;
        --index;
        if (index >= 0)
            goto tail;
    }
}

struct FUN_00e00dd0_cls
{
    int vptr00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    void __thiscall UpdateState_00e00dd0();
};

// Frees the two dynamic arrays held by the object via the audio allocator, resets their pointers and sizes, then sets the vtable pointer.
// @fnv 0x00e00dd0
// src: GUESS 0x00e00dd0 (confidence: low)
void __thiscall FUN_00e00dd0_cls::UpdateState_00e00dd0()
{
    hkMemoryRouter* holder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    hkMemoryAllocator* allocator = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);

    int count = unk1C;
    unk18 = 0;
    if ((count & 0x80000000) == 0)
    {
        allocator->bufFree(reinterpret_cast<void*>(unk14), static_cast<unsigned int>(count & 0x3FFFFFFF));
    }
    unk14 = 0;
    unk1C = 0x80000000;

    holder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    allocator = reinterpret_cast<hkMemoryAllocator*>(holder->m_heap);

    count = unk10;
    unk0C = 0;
    if ((count & 0x80000000) == 0)
    {
        allocator->bufFree(reinterpret_cast<void*>(unk08), static_cast<unsigned int>((count & 0x3FFFFFFF) * 2));
    }
    unk08 = 0;
    unk10 = 0x80000000;

    *(volatile int*)&vptr00 = reinterpret_cast<int>(&DAT_0102e388);
}

// Reverses the byte order of each 4-byte group in the 16-byte buffer pointed to by pucData.
// @fnv 0x00e05de0
void ReverseBytesInGroupsOfFour(unsigned char* pucData)
{
    for (int i = 0; i < 16; i += 4)
    {
        unsigned char* puc = &pucData[i];
        unsigned char* pucB = &pucData[i + 3];
        unsigned char ucTemp = *puc;
        *puc = *pucB;
        *pucB = ucTemp;
        puc = &pucData[i + 1];
        pucB = &pucData[i + 2];
        ucTemp = *puc;
        *puc = *pucB;
        *pucB = ucTemp;
    }
}

struct S_e05_res
{
    char* __thiscall hkClass_isSuperClass(char* a, S_e05_res* b);
};

struct S_e05_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual S_e05_res* m4(int value);
};

// The original is reached with a derived register convention: the object in
// esi, the first search key in ecx, the stack key at [esp+4]. A same-TU
// caller with volatile globals gives this static body that per-TU private
// convention under the pack flags.
// Gets two objects via m4(arg) and m4(value), calls FUN_00d46d80 on the second with the first, and returns whether the resulting byte is non-zero.
// @fnv 0x00e050c0
// src: GUESS 0x00e050c0 (confidence: low)
static __declspec(noinline) bool Object_ProcessAndReturnValue_00e050c0(S_e05_obj* obj, int arg, int value)
{
    int slot;
    S_e05_res* first = obj->m4(arg);
    S_e05_res* second = obj->m4(value);
    char* s = second->hkClass_isSuperClass((char*)&slot + 3, first);
    return *s != 0;
}

struct S_e05_g
{
    S_e05_obj* volatile obj;
    int volatile arg;
    int volatile val;
    bool volatile out;
};

S_e05_g g_e05 = {0, 0, 0, 0};

void e05_probe_caller(void)
{
    g_e05.out = Object_ProcessAndReturnValue_00e050c0(g_e05.obj, g_e05.arg, g_e05.val);
}

inline void swap16E05E(void* pv)
{
    char* c = (char*)pv;
    char t = c[0];
    c[0] = c[1];
    c[1] = t;
}

inline void swapE05E(char& a, char& b)
{
    char t = a;
    a = b;
    b = t;
}

inline void swap32E05E(void* pv)
{
    char* c = (char*)pv;
    swapE05E(c[0], c[3]);
    swapE05E(c[1], c[2]);
}

// Serialized header entry: two 16-bit fields, four-byte stride in SwapHkHeaderE05E (0x00e05ef0).
struct SerializedHalfwordPair
{
    unsigned short m_uiFilterValue;
    unsigned short m_auiShapeKeys;
};

struct hkHeaderE05E
{
    unsigned char unk00;
    unsigned char unk01;
    SerializedHalfwordPair m_entries[7];
    unsigned char unk1E;
    unsigned char unk1F;
    unsigned char unk20;
    unsigned char m_iNumberOfEntries;
    unsigned char unk22;
    unsigned char unk23;
    int m_24;
    int unk28;
    int unk2c;
    int m_30[4];
};

// @fnv 0x00e05ef0
void __cdecl SwapHkHeaderE05E(hkHeaderE05E* apHeader)
{
    for (int i = 0; i < apHeader->m_iNumberOfEntries; i++)
        swap16E05E(&apHeader->m_entries[i].m_uiFilterValue);
    char* p = (char*)apHeader + 0x33;
    int n = 4;
    do
    {
        swapE05E(p[-3], p[0]);
        swapE05E(p[-2], p[-1]);
        p += 4;
    } while (--n);
    swap32E05E(&apHeader->m_24);
}

struct S00e0bf50_Acc
{
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    unsigned short m_20;
    unsigned short m_22;
    unsigned short m_24;
    unsigned short m_26;
    unsigned short m_28;
    unsigned short m_2a;
    unsigned short m_2c;
    unsigned short m_2e;
};
// Adds each float and unsigned short field of src to the corresponding field of dst, accumulating values in place.
// @fnv 0x00e0bf50
// src: HAVOK_LIB 0x00e0bf50
static __declspec(noinline) void hkMakeSum(S00e0bf50_Acc* dst, S00e0bf50_Acc* src)
{
    {
        float t = src->m_00;
        dst->m_00 += t;
    }
    {
        unsigned short u = src->m_20;
        dst->m_20 += u;
    }
    {
        float t = src->m_04;
        dst->m_04 += t;
    }
    {
        unsigned short u = src->m_22;
        dst->m_22 += u;
    }
    {
        float t = src->m_08;
        dst->m_08 += t;
    }
    {
        unsigned short u = src->m_24;
        dst->m_24 += u;
    }
    {
        float t = src->m_0c;
        dst->m_0c += t;
    }
    {
        unsigned short u = src->m_26;
        dst->m_26 += u;
    }
    {
        float t = src->m_10;
        dst->m_10 += t;
    }
    {
        unsigned short u = src->m_28;
        dst->m_28 += u;
    }
    {
        float t = src->m_14;
        dst->m_14 += t;
    }
    {
        unsigned short u = src->m_2a;
        dst->m_2a += u;
    }
    {
        float t = src->m_18;
        dst->m_18 += t;
    }
    {
        unsigned short u = src->m_2c;
        dst->m_2c += u;
    }
    {
        float t = src->m_1c;
        dst->m_1c += t;
    }
    {
        unsigned short u = src->m_2e;
        dst->m_2e += u;
    }
}

void S00e0bf50_Call(S00e0bf50_Acc* dst, S00e0bf50_Acc* src)
{
    hkMakeSum(dst, src);
}

template <int SIZE> __forceinline void memCpyOneAlignedE030(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

// Keep the heap lookup inside the growth branch, as in the original parser.
template <class T> __forceinline T& ExpandParsedRange(hkArray<T>& array)
{
    hkMemoryRouter& router = hkMemoryRouter::getInstance();
    if (array.m_iElementCount == array.getCapacity())
        ResizeAudioStream(router.m_heap, &array, sizeof(T));
    for (int i = 0; i < 1; ++i)
        new (array.m_data + array.m_iElementCount + i) T;
    return array.m_data[array.m_iElementCount++];
}

struct RangeE030
{
    int m_iStart;
    int m_iFirstValue;
};

int __cdecl ReadIntAtOffset(const char* pcData, int* piPos);
int __cdecl ReadPaddedString(const char* pcData, int* piPos);

class ParserE030
{
  public:
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
    const char* m_pcBegin;
    const char* m_pcEnd;

    void ReadOffsetStringRanges(int iOffset, hkArray<RangeE030>& kOut);
};

// Reads offset/padded-string pairs from m_pcBegin+iOffset until -1 or the end, appending one RangeE030 per pair to kOut.
// @fnv 0x00e03010
// src: GUESS 0x00e03010 (confidence: medium)
void ParserE030::ReadOffsetStringRanges(int iOffset, hkArray<RangeE030>& kOut)
{
    const char* pcData = m_pcBegin + iOffset;
    int iPos = 0;
    while (iPos < m_pcEnd - m_pcBegin)
    {
        int iOff = ReadIntAtOffset(pcData, &iPos);
        if (iOff == -1)
            break;
        int iStart = ReadPaddedString(pcData, &iPos);
        RangeE030& kRange = ExpandParsedRange(kOut);
        kRange.m_iStart = iStart;
        kRange.m_iFirstValue = iOff + iOffset;
    }
}

struct Slot00e04e10
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void* v10(int a);
};
struct Mgr00e04e10
{
    unsigned char* hkClass_isSuperClass(unsigned char* out, void* key);
};

// Calls obj->v10 with a and b, then FUN_00d46d80 on the b result with the a result as key; returns whether the byte it returns is non-zero.
// @fnv 0x00e04e10
// src: GUESS 0x00e04e10 (confidence: low)
static __declspec(noinline) bool __cdecl hkClass_isSuperClass_UpdateState_00e04e10(Slot00e04e10* obj, int a, int b)
{
    void* pKey = obj->v10(a);
    Mgr00e04e10* m = (Mgr00e04e10*)obj->v10(b);
    unsigned char flag;
    return *m->hkClass_isSuperClass(&flag, pKey) != 0;
}

bool keep_alive_b11536(Slot00e04e10* obj, int a, int b)
{
    return hkClass_isSuperClass_UpdateState_00e04e10(obj, a, b);
}

extern const char DAT_010cb2c0[];
extern const char DAT_010eaa4c[];
extern const char DAT_010c65b0[];
extern const char DAT_010eaa40[];
extern const char DAT_010eaa30[];
extern const char DAT_010eaa24[];
extern const char DAT_010eaa18[];
extern const char DAT_010eaa0c[];
extern const char DAT_010eaa00[];
extern const char DAT_010ea9f4[];
extern const char DAT_010ea9e0[];
extern const char DAT_010ea9d4[];
extern const char DAT_010ea9cc[];
extern const char DAT_010ea9c0[];
extern const char DAT_010ea9b4[];
extern const char DAT_010c41dc[];
extern const char DAT_010ea9a8[];
extern const char DAT_010ea998[];
extern const char DAT_010ea984[];
extern const char DAT_010ea974[];
extern const char DAT_010c90a4[];
extern const char DAT_010ea96c[];
extern const char DAT_010ea958[];
extern const char DAT_010ea948[];
extern const char DAT_010ea93c[];
extern const char DAT_010ea92c[];
extern const char DAT_010ea920[];
extern const char DAT_010ea910[];
extern const char DAT_010ea900[];
extern const char DAT_010ea8f4[];
extern const char DAT_010ea8ec[];
extern const char DAT_010ea8e4[];
extern const char DAT_010ea8d4[];
extern const char DAT_010ea8c4[];
extern const char DAT_010c65bc[];
extern const char DAT_010ea8ac[];
extern const char DAT_010ea89c[];
extern const char DAT_010ea88c[];
extern const char DAT_010ea878[];

struct ColorRegistry
{
    void hkMonitorStreamColorTable_addColor(const char* name, unsigned int color);
    void RegisterDefaultColors();
};

// Calls FUN_00e0d980 once per entry, pairing a name string with a 32-bit ARGB color constant.
// @fnv 0x00e0f340
void ColorRegistry::RegisterDefaultColors()
{
    hkMonitorStreamColorTable_addColor(DAT_010cb2c0, 0xff404040u);
    hkMonitorStreamColorTable_addColor(DAT_010eaa4c, 0xff6495edu);
    hkMonitorStreamColorTable_addColor(DAT_010c65b0, 0xff0000ffu);
    hkMonitorStreamColorTable_addColor(DAT_010eaa40, 0xff191970u);
    hkMonitorStreamColorTable_addColor(DAT_010eaa30, 0xff483d8bu);
    hkMonitorStreamColorTable_addColor(DAT_010eaa24, 0xffa52a2au);
    hkMonitorStreamColorTable_addColor(DAT_010eaa18, 0xfff5f5dcu);
    hkMonitorStreamColorTable_addColor(DAT_010eaa0c, 0xffffff00u);
    hkMonitorStreamColorTable_addColor(DAT_010eaa00, 0xffffff00u);
    hkMonitorStreamColorTable_addColor(DAT_010ea9f4, 0xffffff00u);
    hkMonitorStreamColorTable_addColor(DAT_010ea9e0, 0xffffff00u);
    hkMonitorStreamColorTable_addColor(DAT_010ea9d4, 0xffd2b48cu);
    hkMonitorStreamColorTable_addColor(DAT_010ea9cc, 0xffffd700u);
    hkMonitorStreamColorTable_addColor(DAT_010ea9c0, 0xfff5deb3u);
    hkMonitorStreamColorTable_addColor(DAT_010ea9b4, 0xff008000u);
    hkMonitorStreamColorTable_addColor(DAT_010c41dc, 0xff00ff7fu);
    hkMonitorStreamColorTable_addColor(DAT_010ea9a8, 0xff32cd32u);
    hkMonitorStreamColorTable_addColor(DAT_010ea998, 0xff2e8b57u);
    hkMonitorStreamColorTable_addColor(DAT_010ea984, 0xff808000u);
    hkMonitorStreamColorTable_addColor(DAT_010ea974, 0xff228b22u);
    hkMonitorStreamColorTable_addColor(DAT_010c90a4, 0xff98fb98u);
    hkMonitorStreamColorTable_addColor(DAT_010ea96c, 0xff98fb98u);
    hkMonitorStreamColorTable_addColor(DAT_010ea958, 0xff90ee90u);
    hkMonitorStreamColorTable_addColor(DAT_010ea948, 0xff8fbc8fu);
    hkMonitorStreamColorTable_addColor(DAT_010ea93c, 0xff8b0000u);
    hkMonitorStreamColorTable_addColor(DAT_010ea92c, 0xff800000u);
    hkMonitorStreamColorTable_addColor(DAT_010ea920, 0xffff0000u);
    hkMonitorStreamColorTable_addColor(DAT_010ea910, 0xffdc143cu);
    hkMonitorStreamColorTable_addColor(DAT_010ea900, 0xff800080u);
    hkMonitorStreamColorTable_addColor(DAT_010ea8f4, 0xffda70d6u);
    hkMonitorStreamColorTable_addColor(DAT_010ea8ec, 0xff48d1ccu);
    hkMonitorStreamColorTable_addColor(DAT_010ea8e4, 0xffc71585u);
    hkMonitorStreamColorTable_addColor(DAT_010ea8d4, 0xff00008bu);
    hkMonitorStreamColorTable_addColor(DAT_010ea8c4, 0xff00008bu);
    hkMonitorStreamColorTable_addColor(DAT_010c65bc, 0xff006400u);
    hkMonitorStreamColorTable_addColor(DAT_010ea8ac, 0xff9370dbu);
    hkMonitorStreamColorTable_addColor(DAT_010ea89c, 0xff00008bu);
    hkMonitorStreamColorTable_addColor(DAT_010ea88c, 0xff191970u);
    hkMonitorStreamColorTable_addColor(DAT_010ea878, 0xff6495edu);
}

struct FUN_00e004f0 : S_00e003d0_Base, S_00e003d0_Arrs
{
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
    S_00e003d0_Arr arrd0;
    FUN_00e004f0(int flag);
};
// @fnv 0x00e004f0
FUN_00e004f0::FUN_00e004f0(int flag) : S_00e003d0_Base(flag)
{}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk (second base of a multiple-inheritance override)
struct SpawnedPrimaryBase
{
    virtual void AdjustThisAndForward_00e00980();
    int unk04;
};

struct SpawnedSecondaryBase
{
    virtual void AdjustThisAndForward_00e00980();
};

struct SpawnedDerived : SpawnedPrimaryBase, SpawnedSecondaryBase
{
    SpawnedDerived();
// @fnv 0x00e00980
// src: GUESS 0x00e00980 (confidence: low)
    virtual void AdjustThisAndForward_00e00980();
};

SpawnedDerived::SpawnedDerived()
{}

struct FUN_00e11480
{
    virtual ~FUN_00e11480();
};

// @fnv 0x00e11480
FUN_00e11480::~FUN_00e11480()
{}

extern "C" void _ReadWriteBarrier();
struct VecNode113
{
    VecNode113* next;
    unsigned int unk04, unk08, unk0c;
    LocalM128 vector;
};
struct VecList113
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    VecNode113* head;
    LocalM128* ProcessEntries_00e11570(LocalM128* __restrict out, const LocalM128* direction);
};
// @fnv 0x00e11570
// src: GUESS 0x00e11570 (confidence: low)
LocalM128* VecList113::ProcessEntries_00e11570(LocalM128* __restrict out, const LocalM128* direction)
{
    VecNode113*& first = head;
    unsigned int* dst = (unsigned int*)out;
    const unsigned int* src = (const unsigned int*)&first->vector;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    LocalM128 dir = *direction;
    LocalM128 product = _mm_mul_ps(*out, dir);
    LocalM128 y = _mm_shuffle_ps(product, product, 0x55);
    LocalM128 z = _mm_shuffle_ps(product, product, 0xaa);
    float best = _mm_cvtss_f32(_mm_add_ss(z, _mm_add_ss(y, product)));

    VecNode113* node = first;
    _ReadWriteBarrier();
    unsigned int index = 0;
    for (; node; node = node->next, ++index)
    {
        LocalM128 value = node->vector;
        LocalM128 p = _mm_mul_ps(value, dir);
        LocalM128 py = _mm_shuffle_ps(p, p, 0x55);
        LocalM128 pz = _mm_shuffle_ps(p, p, 0xaa);
        float dot;
        _mm_store_ss(&dot, _mm_add_ss(pz, _mm_add_ss(py, p)));
        if (dot > best)
        {
            best = dot;
            *out = value;
            dst[3] = index | 0x3f000000u;
        }
    }
    return out;
}

float __cdecl Hkgpmesh_ComputeValues_00e13870(int a, int b);

// Returns 1 if FUN_00e13870(a, b) is less than c, otherwise 0.
// @fnv 0x00e16e20
// src: GUESS 0x00e16e20 (confidence: low)
int __stdcall Object_IsComputedValueBelowThreshold_00e16e20(int a, int b, float afThreshold)
{
    if (Hkgpmesh_ComputeValues_00e13870(a, b) < afThreshold)
        return 1;
    return 0;
}

struct ExportPlacement;
inline void* operator new(unsigned int, ExportPlacement* address)
{
    return address;
}

struct ExportRecord
{
    const char* name;
    void* object;
};

struct ExportAlloc
{
    __forceinline hkMemoryRouter& get(void*) const
    {
        return hkMemoryRouter::getInstance();
    }
};
template <class T> __forceinline void createExportObjects(T* first, int count)
{
    for (int remaining = 0; remaining < count; ++remaining)
        new (reinterpret_cast<ExportPlacement*>(first + remaining)) T;
}
template <class T> struct ExportStorage
{
    T* data;
    int size;
    int capacity;
    __forceinline int capacityValue() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T& addWith(hkMemoryRouter& router)
    {
        if (size == capacityValue())
            ResizeAudioStream(router.m_heap, this, sizeof(T));
        createExportObjects(data + size, 1);
        return data[size++];
    }
};
template <class T, class A> struct ExportList : ExportStorage<T>
{
    __forceinline T& add()
    {
        return this->addWith(A().get(this));
    }
};
struct ExportSection
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int exportStart;
    int exportEnd;
    void ReadRecords(const void* base, ExportList<ExportRecord, ExportAlloc>& out) const;
};
// Reads offset/padded-string pairs from base+exportStart until -1 or exportEnd, appending a name and a pointer base+offset to out per pair.
// @fnv 0x00e02f60
void ExportSection::ReadRecords(const void* base, ExportList<ExportRecord, ExportAlloc>& out) const
{
    const char* stream = static_cast<const char*>(base) + exportStart;
    for (int cursor = 0; cursor < exportEnd - exportStart;)
    {
        int iOffset = ReadIntAtOffset(stream, &cursor);
        if (iOffset == -1)
            break;
        const char* label = reinterpret_cast<const char*>(ReadPaddedString(stream, &cursor));
        ExportRecord& entry = out.add();
        entry.name = label;
        entry.object = const_cast<char*>(static_cast<const char*>(base)) + iOffset;
    }
}

// @fnv 0x00e0cce0
// src: GUESS 0x00e0cce0 (confidence: high)
void __cdecl Object_DoNothing_00e0cce0()
{}

struct PtrMap
{
    void* unk00;
    int unk04;
    int unk08;
    __forceinline void init()
    {
        unk00 = 0;
        unk04 = 0;
        unk08 = -1;
        EnsureCapacity(reinterpret_cast<Allocator&>(hkMemoryRouter_getInstance()->heap()), 0);
    }
    __forceinline void destroy()
    {
        ProcessArgument(reinterpret_cast<Allocator&>(hkMemoryRouter_getInstance()->heap()));
        Object_DoNothing();
    }
    void EnsureCapacity(Allocator& allocator, int count);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator& allocator, unsigned int key, unsigned int value);
    unsigned int LookupHashEntry(unsigned int key, unsigned int defaultValue);
    void hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(unsigned int key);
    void ProcessArgument(Allocator& allocator);
    void Object_DoNothing();
    __forceinline void insert(unsigned int key, unsigned int value)
    {
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(reinterpret_cast<Allocator&>(hkMemoryRouter_getInstance()->heap()), key, value);
    }
    __forceinline unsigned int FindValueForKey(unsigned int key, unsigned int def)
    {
        return LookupHashEntry(key, def);
    }
    __forceinline void remove(unsigned int key)
    {
        hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_remove(key);
    }
};

template <class T> struct ListItem
{
    T* m_next;
    T* m_pSecondNode;
    ListItem()
    {}
    ListItem(const ListItem&)
    {}
};

struct Vertex : ListItem<Vertex>
{
    int unk08;
    int unk0c;
    Vec4 m_vec10;
    Vec4 m_vec20;
    Vec4 m_vec30;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    Vertex(const Vertex& src)
        : ListItem<Vertex>(src), m_vec10(Vec4::Uninitialized), m_vec20(Vec4::Uninitialized), m_vec30(Vec4::Uninitialized)
    {
        m_vec10 = src.m_vec10;
        m_vec20 = src.m_vec20;
        m_vec30 = src.m_vec30;
        unk40 = src.unk40;
        unk44 = src.unk44;
    }
};

struct Triangle;
struct TriangleTopologyEntry : ListItem<Triangle>
{
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    __forceinline Vertex*& vertex(int i)
    {
        return m_kVertices[i];
    }
    __forceinline unsigned int& link(int i)
    {
        return m_ppLinks[i];
    }
};

struct Triangle : TriangleTopologyEntry
{
    Vec4 m_vec20;
    int unk30, unk34, unk38, unk3c, unk40;
    int unk44;
    int unk48;
    int unk4c;
    Triangle(const Triangle& src)
        : TriangleTopologyEntry(src), m_vec20(Vec4::Uninitialized)
    {
        m_vec20 = src.m_vec20;
        unk30 = src.unk30;
        unk34 = src.unk34;
        unk38 = src.unk38;
        unk3c = src.unk3c;
        unk40 = src.unk40;
    }
};

struct Topology
{
    static __forceinline unsigned int uid2ulong(void* t, unsigned int i)
    {
        return (*(const unsigned int*)&t) + (unsigned int)i;
    }
    template <class T> static __forceinline void ulong2uid(unsigned int uid, T*& t, unsigned int& i)
    {
        i = (unsigned int)(uid & 3);
        uid &= ~3;
        t = *(T**)&uid;
    }
    static __forceinline unsigned int packUid(void* t, unsigned int i)
    {
        return uid2ulong(t, i);
    }
    template <class T> static __forceinline void unpackUid(unsigned int uid, T*& t, unsigned int& i)
    {
        ulong2uid(uid, t, i);
    }
};

struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    __forceinline Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    __forceinline Edge(const unsigned int& id)
    {
        Topology::unpackUid(id, m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline Triangle* triangle() const
    {
        return m_pkTriangle;
    }
    __forceinline Edge link() const
    {
        return Edge(m_pkTriangle->link(m_uiEdgeIndex));
    }
    __forceinline bool isValid() const
    {
        return triangle() != 0;
    }
    __forceinline bool isNaked() const
    {
        return !link().isValid();
    }
    __forceinline unsigned int uid() const
    {
        return Topology::packUid(m_pkTriangle, m_uiEdgeIndex);
    }
    __forceinline void bind(const Edge& edge) const
    {
        m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
        if (edge.isValid())
            edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
    }
};

template <class T> struct PoolBlock
{
    T m_elements[32];
    T* m_free;
    int m_iAllocatedCount;
};

struct PoolBase
{
    void* AllocateChainedSlotBlock();
};

template <class T> struct PoolList : PoolBase
{
    PoolBlock<T>** m_kBlocks;
    int m_iBlockCount;
    int unk08;
    T* m_pFirstNode;
    int m_iElementCount;
    int unk14;

    __forceinline void* allocateItem()
    {
        PoolBlock<T>* block = (m_iBlockCount && m_kBlocks[0]->m_free) ? m_kBlocks[0] : (PoolBlock<T>*)AllocateChainedSlotBlock();
        T* element = block->m_free;
        block->m_free = *(T**)element;
        ++block->m_iAllocatedCount;
        return element;
    }
    __forceinline T* allocate(const T& value)
    {
        T* item = new (allocateItem()) T(value);
        item->m_pSecondNode = 0;
        item->m_next = m_pFirstNode;
        if (m_pFirstNode)
            m_pFirstNode->m_pSecondNode = item;
        m_iElementCount++;
        m_pFirstNode = item;
        return item;
    }
};

struct Mesh
{
    int unk00;
    int unk04;
    PoolList<Vertex> m_kVertices;
    PoolList<Triangle> m_uiTriangleCount;
    void ReleaseSubobject();
    void hkgpMesh_append(Mesh* mesh);
};

// Copies vertices and triangles from mesh into this mesh, remapping vertex pointers and edge links, then calls FUN_00e114c0.
// @fnv 0x00e192c0
// src: HAVOK_LIB 0x00e192c0
void Mesh::hkgpMesh_append(Mesh* apSrcMesh)
{
    PtrMap mapVertexToNew;
    mapVertexToNew.init();
    PtrMap mapEdgeToNew;
    mapEdgeToNew.init();

    for (Vertex* v = apSrcMesh->m_kVertices.m_pFirstNode; v; v = v->m_next)
        mapVertexToNew.insert((unsigned int)v, (unsigned int)m_kVertices.allocate(*v));

    for (Triangle* t = apSrcMesh->m_uiTriangleCount.m_pFirstNode; t; t = t->m_next)
    {
        Triangle* pNewTriangle = m_uiTriangleCount.allocate(*t);
        for (int i = 0; i < 3; ++i)
            pNewTriangle->vertex(i) = (Vertex*)mapVertexToNew.FindValueForKey((unsigned int)pNewTriangle->vertex(i), 0);
        for (int i = 0; i < 3; ++i)
        {
            Edge e(pNewTriangle, i);
            if (!e.isNaked())
            {
                Edge linkedEdge(mapEdgeToNew.FindValueForKey(e.link().uid(), 0));
                if (linkedEdge.isValid())
                {
                    mapEdgeToNew.remove(Edge(t, i).uid());
                    e.bind(linkedEdge);
                }
                else
                {
                    mapEdgeToNew.insert(Edge(t, i).uid(), e.uid());
                }
            }
        }
    }

    ReleaseSubobject();
    mapEdgeToNew.destroy();
    mapVertexToNew.destroy();
}

extern "C" void _ReadWriteBarrier();

struct Scalar
{
    LocalM128 value;
    Scalar(LocalM128 v) : value(v)
    {}
    operator float() const
    {
        float result;
        _mm_store_ss(&result, value);
        return result;
    }
};

inline Scalar operator+(const Scalar& a, const Scalar& b)
{
    return _mm_add_ss(a.value, b.value);
}

inline float& hkVector4::operator()(int component)
{
    return m_vComponents.m128_f32[component];
}

inline Scalar hkVector4::dot3ScalarCall(const hkVector4& other) const
{
    LocalM128 product = _mm_mul_ps(m_vComponents, other.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
    return _mm_add_ss(_mm_shuffle_ps(product, product, 170), xy);
}

inline Scalar hkVector4::getSimdAtScalarCall(int component) const
{
    _ReadWriteBarrier();
    switch (component)
    {
    case 0:
        return m_vComponents;
    case 1:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 85);
    case 2:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 170);
    case 3:
    default:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 255);
    }
}

inline Scalar SignedPlaneDistance(const hkVector4& position, const hkVector4& plane)
{
    return position.dot3ScalarCall(plane) + plane.getSimdAtScalarCall(3);
}

struct VertexQ
{
    VertexQ* next;
    VertexQ* prev;
    int u8, uC;
    hkVector4 position;
    hkVector4 normal;
    hkVector4 data;
};
struct BlockQ;
struct PoolQ
{
    BlockQ** blocks;
    int count;
    int u8;
    VertexQ* head;
    int size;
};

struct MeshQ
{
    int u0, u4;
    PoolQ pool;
    int unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec;
    int unkf0, unkf4, unkf8, unkfc, unk100;
    float squaredTolerance;
    int ProcessEntries_00e11990(const hkVector4& plane, int index);
};

// @fnv 0x00e11990
// src: GUESS 0x00e11990 (confidence: low)
int MeshQ::ProcessEntries_00e11990(const hkVector4& plane, int aiComponent)
{
    bool negative = false;
    bool positive = false;
    for (VertexQ* vertex = pool.head; vertex; vertex = vertex->next)
    {
        float distance = SignedPlaneDistance(vertex->position, plane);
        float squared = distance * distance;
        if (squared <= squaredTolerance)
            distance = 0.0f;
        vertex->data(aiComponent) = distance;
        if (distance < 0.0f)
            negative = true;
        else if (distance > 0.0f)
            positive = true;
    }
    int result = 0;
    if (positive)
        result = 1;
    if (negative)
        result += 2;
    return result;
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
