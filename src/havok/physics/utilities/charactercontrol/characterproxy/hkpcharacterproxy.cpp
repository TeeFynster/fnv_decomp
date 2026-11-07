// Keep the original intrinsic storage: additional union aliases change MSVC's alias analysis.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00cacaa0 FUN_00cacaa0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" {
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*,LocalM128);
LocalM128 _mm_set_ss(float);
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_setr_ps(float,float,float,float);
LocalM128 _mm_setzero_ps();
LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,unsigned int);
LocalM128 _mm_mul_ps(LocalM128,LocalM128);
LocalM128 _mm_mul_ss(LocalM128,LocalM128);
LocalM128 _mm_add_ps(LocalM128,LocalM128);
LocalM128 _mm_add_ss(LocalM128,LocalM128);
LocalM128 _mm_sub_ps(LocalM128,LocalM128);
LocalM128 _mm_sub_ss(LocalM128,LocalM128);
LocalM128 _mm_rcp_ps(LocalM128);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128,LocalM128);
LocalM128 _mm_cmple_ps(LocalM128,LocalM128);
LocalM128 _mm_and_ps(LocalM128,LocalM128);
LocalM128 _mm_andnot_ps(LocalM128,LocalM128);
int _mm_movemask_ps(LocalM128);
}
#endif
#include "../../../../../../include/hkVector4.h"

// Inline vector operations used by this translation unit.
__forceinline float& hkVector4::operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
__forceinline const float& hkVector4::operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
__forceinline void hkVector4::set(LocalM128 v) { m_vComponents = v; }
__forceinline void hkVector4::set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a,b,c,d); }
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline void hkVector4::SetAllComponents(float v) { m_vComponents = _mm_set_ps1(v); }
__forceinline void hkVector4::setAll3(float v) { m_vComponents = _mm_set_ps1(v); }
__forceinline hkSimdReal::hkSimdReal(const LocalM128& v) : m_vValue(v) {}
__forceinline hkSimdReal::hkSimdReal(float v) { m_vValue = _mm_load_ss(&v); }
__forceinline hkSimdReal::operator float() const { float s; _mm_store_ss(&s,m_vValue); return s; }
__forceinline LocalM128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
__forceinline const LocalM128& hkSimdReal::getQuad() const { return m_vValue; }
__forceinline void hkVector4::mul4(const float& s) { mul4(hkSimdReal(s)); }
__forceinline void hkVector4::setMul4(float s,const hkVector4& v) { m_vComponents = _mm_mul_ps(hkSimdReal(s).broadcast(),v.m_vComponents); }
__forceinline void hkVector4::addMul4(const hkSimdReal& s,const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents,_mm_mul_ps(s.broadcast(),v.m_vComponents)); }
__forceinline void hkVector4::setAddMul4(const hkVector4& a,const hkVector4& b,float s) { m_vComponents = _mm_add_ps(a.m_vComponents,_mm_mul_ps(hkSimdReal(s).broadcast(),b.m_vComponents)); }
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const {
    LocalM128 x2 = _mm_mul_ps(m_vComponents,a.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
    return _mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xy);
}
__forceinline float hkVector4::dot3scalar(const hkVector4& a) const { return dot3(a); }
__forceinline hkSimdReal hkVector4::lengthSquared3() const { return dot3(*this); }
__forceinline void hkVector4::normalize3() {
    const LocalM128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
    const LocalM128 len2 = dot3(*this).getQuad();
    const LocalM128 mask = _mm_cmpeq_ss(len2,zero);
    const LocalM128 approx = _mm_rsqrt_ss(len2);
    const LocalM128 refined = _mm_mul_ss(_mm_mul_ss(half,approx),_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
    const LocalM128 inv = _mm_andnot_ps(mask,refined);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv,inv,0),m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& a,const hkVector4& b) {
    LocalM128 p = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xc9),_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xd2));
    LocalM128 q = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents,a.m_vComponents,0xd2),_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,0xc9));
    m_vComponents = _mm_sub_ps(p,q);
}
extern const LocalM128 DAT_01017d10;
static __forceinline int VectorEquals3(const hkVector4& a,const hkVector4& b,float epsilon) {
    LocalM128 delta = _mm_sub_ps(a.m_vComponents,b.m_vComponents);
    LocalM128 magnitude = _mm_and_ps(delta,DAT_01017d10);
    return (_mm_movemask_ps(_mm_cmple_ps(magnitude,_mm_set_ps1(epsilon))) & 7) == 7;
}

#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/ContactArray289.h"
#include "../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../include/hkpAllCdPointCollector.h"


// src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cad480_Class {
    void __thiscall hkpCharacterProxy_fireContactAdded(void* arg);
};

// Iterates the proxy list at this+0x80 in reverse and calls each proxy's third virtual method with this and arg.
// @fnv 0x00cad480
// src: HAVOK_LIB 0x00cad480
void __thiscall FUN_00cad480_Class::hkpCharacterProxy_fireContactAdded(void* arg)
{
    int count = *(int*)((char*)this + 0x84);
    for (--count; count >= 0; --count) {
        void* proxy = *(void**)((char*)*(void**)((char*)this + 0x80) + count * 4);
        (*(void (__stdcall **)(void*, void*))(*(void***)proxy + 2))(this, arg);
    }
}

struct S_00cad440;

struct S_00cad440_Listener {
    virtual void unk0();
    virtual void Notify(S_00cad440* src, void* a, void* b);
};

struct S_00cad440 {
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
    S_00cad440_Listener** unk80;
    int unk84;
    void hkpCharacterProxy_fireConstraintsProcessed(void* a, void* b);
};

// Iterates the listener array backwards from unk84 and calls Notify(this, a, b) on each listener.
// @fnv 0x00cad440
// src: HAVOK_LIB 0x00cad440
void S_00cad440::hkpCharacterProxy_fireConstraintsProcessed(void* a, void* b)
{
    for (int i = unk84 - 1; i >= 0; i--)
        unk80[i]->Notify(this, a, b);
}

struct CAD4C0Owner;

struct CAD4C0Listener {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void notify(CAD4C0Owner* owner, void* data);
};

struct CAD4C0Owner {
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
    CAD4C0Listener** m_kListeners;
    int m_numListeners;

    void hkpCharacterProxy_fireContactRemoved(void* data);
};

// Calls notify(this, data) on each listener in reverse order, from the last index down to zero.
// @fnv 0x00cad4c0
// src: HAVOK_LIB 0x00cad4c0
void CAD4C0Owner::hkpCharacterProxy_fireContactRemoved(void* data)
{
    for (int i = m_numListeners - 1; i >= 0; i--)
        m_kListeners[i]->notify(this, data);
}

struct FUN_00cad6f0_class
{
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    void** items;
    volatile int itemCount;
    void __thiscall RemoveItem(void* item);
};
// Finds item in items, decrements itemCount, and moves the last entry into the removed slot.
// @fnv 0x00cad6f0
void FUN_00cad6f0_class::RemoveItem(void* item)
{
    int index = 0;
    int count = itemCount;
    if (count <= 0)
        goto notFound;
    void** entry = items;
    do
    {
        if (*entry == item)
            goto found;
        ++index;
        ++entry;
    } while (index < count);
notFound:
    index = -1;
found:
    --itemCount;
    int newCount = itemCount;
    if (newCount != index)
    {
        void** entry2 = items;
        entry2[index] = entry2[newCount];
    }
}

struct FUN_00cade20_Class
{
    void __thiscall hkpCharacterProxy_integrateImplementation(int, int, int, int, int, int);
};

struct FUN_00cafbd0_Class
{
    void __thiscall hkpCharacterProxy_integrateWithCollectors(int first, int second, int third, int fourth);
};

// Forwards the four arguments to FUN_00cade20 with two trailing zero arguments.
// @fnv 0x00cafbd0
// src: HAVOK_LIB 0x00cafbd0
void __thiscall FUN_00cafbd0_Class::hkpCharacterProxy_integrateWithCollectors(int first, int second, int third, int fourth)
{
    ((FUN_00cade20_Class*)this)->hkpCharacterProxy_integrateImplementation(first, second, third, fourth, 0, 0);
}

struct FNVAllocator {
    virtual void Release();
    virtual void* Allocate(unsigned int bytes);
};
struct FNVMemoryManager {
    FNVAllocator* GetAllocator() {
        return *reinterpret_cast<FNVAllocator**>(reinterpret_cast<char*>(this) + 0x10);
    }
};
FNVMemoryManager* __cdecl hkMemoryRouter_getInstance();

struct FNVArray {
    int* values;
    unsigned short size;
    unsigned short flags;
    FNVArray() : values(0), size(0), flags(0x8000) {}
};
struct FNVBuffers {
    FNVArray spare;
    FNVArray elements;
    static void* operator new(unsigned int bytes) {
        return hkMemoryRouter_getInstance()->GetAllocator()->Allocate(bytes);
    }
};
void __cdecl hkSmallArrayUtil__reserveMore(FNVArray*, unsigned int);
struct FNVOwner {
    FNVBuffers*& Buffers() {
        return *reinterpret_cast<FNVBuffers**>(reinterpret_cast<char*>(this) + 0x214);
    }
    void hkpEntity_addEntityListener(int value);
};
// Ensures the buffers exist, stores value into the first empty element slot or appends it, growing the array when full.
// @fnv 0x00c9c5b0
// src: HAVOK_LIB 0x00c9c5b0
void FNVOwner::hkpEntity_addEntityListener(int value) {
    if (Buffers() == 0) {
        Buffers() = new FNVBuffers;
    }
    FNVArray& array = Buffers()->elements;
    for (int i = 0; i < array.size; ++i) {
        if (!array.values[i]) {
            if (i >= 0) {
                array.values[i] = value;
                return;
            }
            break;
        }
    }
    if (array.size == (array.flags & 0x3fff)) {
        hkSmallArrayUtil__reserveMore(&array, sizeof(int));
    }
    array.values[array.size] = value;
    ++array.size;
}

namespace fnv_00cac120 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00cac120_cls {
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00cadb00();

    FUN_00cac120_cls* FUN_00cac120(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00cadb00, then if bit 0 of acFlags is set frees this through the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00cac120
FUN_00cac120_cls* FUN_00cac120_cls::FUN_00cac120(unsigned char acFlags)
{
    FUN_00cadb00();
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00cac120

extern __declspec(thread) int g_tlsMemContext;

struct S_00cac150_Scope {
    int m_oldContext;
    S_00cac150_Scope(int ctx) {
        m_oldContext = g_tlsMemContext;
        g_tlsMemContext = ctx;
    }
    ~S_00cac150_Scope() {
        g_tlsMemContext = m_oldContext;
    }
};

struct S_00cac150_Item1 {
    void removeEntityListener_00c9c670(void* arg);
};

struct S_00cac150_Item2 {
    void RemoveListener(void* arg);
};

struct S_00cac150 {
    int unk00;
    int unk04;
    int m_arg1;
    int m_arg2;
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
    S_00cac150_Item1** m_items1;
    int m_count1;
    int unk94;
    S_00cac150_Item2** m_items2;
    int m_count2;

    void ClearItems();
};

// Runs each item's callback with m_arg1/m_arg2, then resets m_count1 and m_count2 to zero.
// @fnv 0x00cac150
void S_00cac150::ClearItems() {
    S_00cac150_Scope scope(16);
    for (int i = 0; i < m_count1; ++i) {
        m_items1[i]->removeEntityListener_00c9c670(&m_arg1);
    }
    m_count1 = 0;

    for (int i = 0; i < m_count2; ++i) {
        m_items2[i]->RemoveListener(&m_arg2);
    }
    m_count2 = 0;
}

struct CpuScalar {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int value;
};
struct CpuObject {
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
    CpuScalar* value;
    unsigned int hkpCharacterProxy_getPosition();
};
// @fnv 0x00cac910
// src: XBOX_PDB 0x00cac910
unsigned int CpuObject::hkpCharacterProxy_getPosition()
{
    return value->value + 48u;
}

extern float DAT_0101e2bc;

struct FUN_00cacf10_cls {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70;
    int m_74;
    int m_78;

    float hkpCharacterProxy_surfaceDistance(void* a, void* b);
    int hkpCharacterProxy_findSurface(void* arg);
};

struct ArgminState {
    volatile float best;
    volatile int idx;
};

// @fnv 0x00cacf10
// src: COMMUNITY 0x00cacf10
int FUN_00cacf10_cls::hkpCharacterProxy_findSurface(void* arg) {
    ArgminState s;
    s.best = DAT_0101e2bc;
    s.idx = -1;
    int i = 0;
    if (m_78 <= 0) {
        return -1;
    }
    do {
        float d = hkpCharacterProxy_surfaceDistance(arg, (void*)(m_74 + i * 0x70));
        if (d < s.best) {
            s.best = d;
            s.idx = i;
        }
    } while (++i < m_78);
    return s.idx;
}

// Stand-in model for the object whose method RemoveTarget is being rebuilt.
// Layout is taken from the original disassembly, not from the pack's unit file.

struct BhkShape {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    char unk14;
    char unk15;
    char unk16;
    char unk17;
    unsigned char unk18;
};

// 0x70 bytes; the pointer to the shape sits at +0x48.
struct BhkElem {
    __int64 q00;
    __int64 q08;
    __int64 q10;
    __int64 q18;
    __int64 q20;
    __int64 q28;
    __int64 q30;
    __int64 q38;
    __int64 q40;
    BhkShape* p;
    __int64 q50;
    __int64 q58;
    __int64 q60;
    __int64 q68;
};

struct BhkTarget {
    void removeEntityListener_00c9c670(void* v);
};

struct BhkProxy {
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
    volatile BhkElem* m_elements;
    int m_uiItemCount;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    BhkTarget** m_ids;
    volatile int m_idcount;

    void RemoveTarget(BhkTarget* arg1);
};

// Notifies arg1, then removes matching elements and the id entry from the proxy's arrays, compacting both.
// @fnv 0x00cad740
void BhkProxy::RemoveTarget(BhkTarget* pTarget)
{
    void* pProxy;
    if ((char*)this - 8)
        pProxy = (void*)this;
    else
        pProxy = (void*)0;
    pTarget->removeEntityListener_00c9c670(pProxy);

    for (int i = m_uiItemCount - 1; i >= 0; i--) {
        BhkShape* p = m_elements[i].p;
        char* key;
        if (p->unk18 == 1)
            key = (char*)p + p->unk10;
        else
            key = 0;
        if (key == (char*)pTarget) {
            m_uiItemCount--;
            if (m_uiItemCount != i) {
                __int64* src = (__int64*)&m_elements[m_uiItemCount];
                __int64* dst = (__int64*)&m_elements[i];
                for (int k = 0; k < 14; k++)
                    dst[k] = src[k];
            }
        }
    }

    int n = m_idcount;
    int idx = 0;
    bool found = false;
    while (idx < n) {
        if (m_ids[idx] == pTarget) {
            found = true;
            break;
        }
        idx++;
    }
    if (!found)
        idx = -1;
    int c = --m_idcount;
    if (c != idx)
        m_ids[idx] = m_ids[c];
}

struct FUN_00cad900_arg {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int code, const char* name, int a, int b, int c);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned char flag10;
};

extern "C" int __cdecl hkStatisticsCollector_getAllocatedSize(int ptr, int size);
extern "C" char str_010c8444[];
extern "C" char str_010c8450[];
extern "C" char str_010c8460[];

struct FUN_00cad900_cls {
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
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;

    void hkpCharacterProxy_calcContentStatistics(FUN_00cad900_arg* a1, int a2);
};

// @fnv 0x00cad900
// src: XBOX_PDB 0x00cad900
void FUN_00cad900_cls::hkpCharacterProxy_calcContentStatistics(FUN_00cad900_arg* apReporter, int aiUnused) {
    if ((m7c & 0x80000000u) == 0 || apReporter->flag10 != 0) {
        int p = m74;
        int r = hkStatisticsCollector_getAllocatedSize(p, (m7c & 0x3fffffff) * 0x70);
        apReporter->v05(3, (const char*)str_010c8460, m74, m78 * 0x70, r);
    }
    if ((m94 & 0x80000000u) == 0 || apReporter->flag10 != 0) {
        int p = m8c;
        int r = hkStatisticsCollector_getAllocatedSize(p, (m94 & 0x3fffffff) * 4);
        apReporter->v05(3, (const char*)str_010c8450, m8c, m90 * 4, r);
    }
    if ((ma0 & 0x80000000u) == 0 || apReporter->flag10 != 0) {
        int p = m98;
        int r = hkStatisticsCollector_getAllocatedSize(p, (ma0 & 0x3fffffff) * 4);
        apReporter->v05(3, (const char*)str_010c8460, m98, m9c * 4, r);
    }
    if ((m88 & 0x80000000u) == 0 || apReporter->flag10 != 0) {
        int p = m80;
        int r = hkStatisticsCollector_getAllocatedSize(p, (m88 & 0x3fffffff) * 4);
        apReporter->v05(3, (const char*)str_010c8444, m80, m84 * 4, r);
    }
}

namespace fnv_00cada30 {

struct PtrList {
    void** m_data;
    int m_uiItemCount;
    unsigned int m_capBits;
};

hkMemoryRouter* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* allocator, PtrList* list, unsigned int elemSize);

struct FUN_00cada30_cls {
    int unk00;

    void AppendPointer(void* value);
};

// Appends value to the pointer list at this+0x80, growing it via ResizeAudioStream when full, then increments the count.
// @fnv 0x00cada30
void FUN_00cada30_cls::AppendPointer(void* value)
{
    PtrList* list = (PtrList*)((char*)this + 0x80);
    hkMemoryRouter* pAllocHolder = hkMemoryRouter_getInstance();
    if (list->m_uiItemCount == (int)(list->m_capBits & 0x3fffffffu)) {
        ResizeAudioStream(pAllocHolder->m_heap, list, 4);
    }
    void** slot = &list->m_data[list->m_uiItemCount];
    *slot = value;
    if (slot == 0) {
        ResizeAudioStream(pAllocHolder->m_heap, list, 4);
    }
    list->m_uiItemCount++;
}
}  // namespace fnv_00cada30

extern char str_0102f13c[];
extern char DAT_0104e3d0[];
extern char DAT_010c84a4[];
extern char DAT_010c8488[];
extern char DAT_010c8470[];

struct FUN_00cad500_Class
{
    void __thiscall hkpCharacterProxy_updateFromCinfo(void* arg);
};

struct FUN_00cada70_cls
{
    void* m_vtbl;
    unsigned char unk04[2];
    unsigned short m_06;
    void* m_08;
    void* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
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
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9c;
    unsigned int m_a0;

    FUN_00cada70_cls* Construct(void* a1);
};

// Initialises the object's vtable, pointers and numeric fields, then calls FUN_00cad500 with a1 and returns this.
// @fnv 0x00cada70
FUN_00cada70_cls* FUN_00cada70_cls::Construct(void* a1)
{
    *(unsigned short volatile*)&m_06 = 1;
    *(void* volatile*)&m_08 = str_0102f13c;
    *(void* volatile*)&m_0c = DAT_0104e3d0;
    *(void* volatile*)&m_vtbl = DAT_010c84a4;
    *(void* volatile*)&m_08 = DAT_010c8488;
    *(void* volatile*)&m_0c = DAT_010c8470;
    *(unsigned int volatile*)&m_30 = 0;
    *(unsigned int volatile*)&m_74 = 0;
    *(unsigned int volatile*)&m_78 = 0;
    *(unsigned int volatile*)&m_7c = 0x80000000u;
    *(unsigned int volatile*)&m_88 = 0x80000000u;
    *(unsigned int volatile*)&m_80 = 0;
    *(unsigned int volatile*)&m_84 = 0;
    *(unsigned int volatile*)&m_94 = 0x80000000u;
    *(unsigned int volatile*)&m_8c = 0;
    *(unsigned int volatile*)&m_90 = 0;
    *(unsigned int volatile*)&m_a0 = 0x80000000u;
    FUN_00cad500_Class* self = (FUN_00cad500_Class*)this;
    m_98 = 0;
    m_9c = 0;
    self->hkpCharacterProxy_updateFromCinfo(a1);
    return this;
}

extern float DAT_0104da48;


namespace Memory289 {extern "C" hkMemoryRouter* hkMemoryRouter_getInstance() throw();}


// Keep these implementations inline while using the shared class layouts.
__declspec(nothrow) __forceinline hkpCdPointCollector::hkpCdPointCollector()
    : m_fEarlyOutDistance(DAT_0104da48) {}
__declspec(nothrow) __forceinline hkpCdPointCollector::~hkpCdPointCollector() {}
__forceinline void hkpCdPointCollector::reset() { m_fEarlyOutDistance=DAT_0104da48; }
__declspec(nothrow) __forceinline ContactArray289::ContactArray289()
    : data(local), count(0), capacity(0x80000008) {}
__declspec(nothrow) __forceinline ContactArray289::~ContactArray289() {
    hkMemoryAllocator* alloc=reinterpret_cast<hkMemoryAllocator*>((&Memory289::hkMemoryRouter_getInstance()->heap()));
    count=0;
    if((capacity&0x80000000)==0) alloc->bufFree(data,(capacity&0x3fffffff)*sizeof(RootContact289));
    data=0;capacity=0x80000000;
}

__declspec(nothrow) inline hkpAllCdPointCollector::hkpAllCdPointCollector() {}
__declspec(nothrow) __forceinline hkpAllCdPointCollector::~hkpAllCdPointCollector() {}
inline void hkpAllCdPointCollector::reset() {contacts.count=0;m_fEarlyOutDistance=DAT_0104da48;}
struct Query289 {
 __declspec(nothrow) void hkpCharacterProxy_integrateImplementation(void*,void*,hkpCdPointCollector*,hkpCdPointCollector*,unsigned,unsigned) throw();
 void CollectAllContactPoints(void*,void*);
};
// Runs a collision query between a and b, gathering all contact points into two hkpAllCdPointCollector instances.
// @fnv 0x00cafad0
void Query289::CollectAllContactPoints(void* a,void* b) {
 hkpAllCdPointCollector c2,c1;
 hkpCharacterProxy_integrateImplementation(a,b,&c2,&c1,0,0);
}

extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128 a);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

extern float DAT_0104da4c;



struct S00cacaa0_Base {
    unsigned int f00, f04, f08, f0c, f10, f14;
    hkVector4 v20;
    hkVector4 v30;
    hkVector4 v40;
};

struct S00cacaa0_Src : S00cacaa0_Base {
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5c; unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6c;
    unsigned int f70;
};

struct S00cacaa0_Input : S00cacaa0_Base {
    hkVector4 v50;
    float f60;
    float f64;
    unsigned int f68;
    S00cacaa0_Input() { f04 = 0; f60 = DAT_0104da4c; }
};

struct S00cacaa0_Shape {
    unsigned int unk00, unk04, unk08;
    unsigned int m_type;
};

struct S00cacaa0_Coll {
    S00cacaa0_Shape* m_pCollisionShape;
};

typedef void (__cdecl *S00cacaa0_Fn)(S00cacaa0_Coll* a, S00cacaa0_Coll* b, S00cacaa0_Input* in, void* c, void* d);

struct S00cacaa0_Entry {
    S00cacaa0_Fn m_fn;
    unsigned int unk04, unk08, unk0c, unk10;
};

struct S00cacaa0_Disp {
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c; unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17c; unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18c; unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19c;
    unsigned char m_table[64][32];
};

struct S00cacaa0_World {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c; unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2c; unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3c; unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4c; unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5c; unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6c; unsigned int unk70; unsigned int unk74;
    S00cacaa0_Src* m_src;
    unsigned int unk7c;
    S00cacaa0_Disp* m_disp;
    void hkpWorld_linearCast(S00cacaa0_Coll* a, float* b, void* c, void* d);
};

struct S00cacaa0_Agent {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(S00cacaa0_Coll* a, S00cacaa0_Coll* b, S00cacaa0_Input* in, void* c, void* d);
};

struct S00cacaa0_Pair {
    S00cacaa0_Agent* m_pCollisionAgent;
    S00cacaa0_Coll* m_coll;
};

struct S00cacaa0_Arr {
    void* m_data;
    int m_iElementCount;
};

struct S00cacaa0_Phantom {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int v14();
    unsigned int unk04;
    S00cacaa0_World* m_pOwningWorld;
    unsigned int unk0c;
    S00cacaa0_Coll m_coll;
    unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c;
    S00cacaa0_Arr m_aiIndexedValues;
};

struct S00cacaa0_cls {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0c; unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1c;
    hkVector4 m_v20;
    S00cacaa0_Phantom* m_pPhantom;
    void hkpCharacterProxy_linearCast(bool flag, float* a2, void* a3, void* a4);
};

// With flag set calls the world's FUN_00c92430; otherwise builds an input and dispatches it to each indexed entry via the dispatch table or collision agents.
// @fnv 0x00cacaa0
// src: COMMUNITY 0x00cacaa0
void S00cacaa0_cls::hkpCharacterProxy_linearCast(bool flag, float* a2, void* a3, void* a4)
{
    S00cacaa0_Phantom* pPhantom = m_pPhantom;
    S00cacaa0_World* world = pPhantom->m_pOwningWorld;
    S00cacaa0_Coll* coll = &pPhantom->m_coll;
    if (flag) {
        world->hkpWorld_linearCast(coll, a2, a3, a4);
        return;
    }

    S00cacaa0_Input in;
    S00cacaa0_Src* src = world->m_src;
    in.f00 = src->f00;
    in.f04 = src->f04;
    in.f08 = src->f08;
    in.f0c = src->f0c;
    in.f10 = src->f10;
    in.f14 = src->f14;
    in.v20.m_vComponents = src->v20.m_vComponents;
    in.v30.m_vComponents = src->v30.m_vComponents;
    in.v40.m_vComponents = src->v40.m_vComponents;
    in.f68 = src->f70;
    LocalM128 v = m_v20.m_vComponents;
    in.v50.m_vComponents = v;
    LocalM128 vSquared = _mm_mul_ps(v, v);
    LocalM128 t = _mm_add_ss(_mm_shuffle_ps(vSquared, vSquared, 0x55), vSquared);
    t = _mm_add_ss(_mm_shuffle_ps(vSquared, vSquared, 0xaa), t);
    t = _mm_sqrt_ss(t);
    float norm;
    _mm_store_ss(&norm, t);
    in.f64 = norm;
    *(float*)&in.f08 = a2[5];
    in.f60 = a2[4];

    if (pPhantom->v14() == 1) {
        S00cacaa0_Arr& arr = m_pPhantom->m_aiIndexedValues;
        S00cacaa0_Disp* disp = world->m_disp;
        for (int i = arr.m_iElementCount - 1; i >= 0; --i) {
            S00cacaa0_Coll* const& other = ((S00cacaa0_Coll**)arr.m_data)[i];
            unsigned char k = disp->m_table[coll->m_pCollisionShape->m_type][other->m_pCollisionShape->m_type];
            ((S00cacaa0_Entry*)((char*)disp + 0x9ac))[k].m_fn(coll, other, &in, a3, a4);
        }
    } else {
        S00cacaa0_Arr& arr = m_pPhantom->m_aiIndexedValues;
        for (int i = arr.m_iElementCount - 1; i >= 0; --i) {
            S00cacaa0_Pair& p = ((S00cacaa0_Pair*)arr.m_data)[i];
            p.m_pCollisionAgent->v14(coll, p.m_coll, &in, a3, a4);
        }
    }
}

namespace fnv_00cacf80 {
// Exe 0x00cacaa0 FUN_00cacaa0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { struct {float x,y,z,w;}; } __m128, LocalM128;
extern "C" {
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*,LocalM128);
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_setzero_ps();
LocalM128 _mm_shuffle_ps(LocalM128,LocalM128,int);
LocalM128 _mm_mul_ps(LocalM128,LocalM128);
LocalM128 _mm_add_ps(LocalM128,LocalM128);
LocalM128 _mm_sub_ps(LocalM128,LocalM128);
LocalM128 _mm_add_ss(LocalM128,LocalM128);
}
static inline const LocalM128& contactQuad(const hkVector4& v) { return reinterpret_cast<const LocalM128&>(v.m_vComponents); }
static inline ::LocalM128 sharedQuad(LocalM128 v) { return reinterpret_cast<const ::LocalM128&>(v); }

static float readStep(const float* p,int i){return p[i];}
struct FloatMatrix3;

struct FloatMatrix3 { hkVector4 rows[3]; };
struct ContactShape {
    int unk00,unk04,unk08,unk0c;
    signed char childOffset;
    char unk11,unk12,unk13,unk14,unk15,unk16,unk17;
    unsigned char active;
};
struct PropertyValue {unsigned __int64 data; unsigned int get() const {return (unsigned int)data;} };
struct ShapeAttribute {unsigned int kind,arg04; PropertyValue value;};
struct Motion {
    void** vtable;
    unsigned int unk04;
    unsigned char kind;
    unsigned char unk09,unk0a,unk0b;
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
    hkVector4 reference;
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
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    hkVector4 inertiaAndMass;
    hkVector4 translation;
    hkVector4 angular;
};
struct ShapeData {
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
    ShapeAttribute* attrs;
    int attrCount;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    Motion motion;
    bool hasProperty(unsigned int k) const {
        for (int i=0;i<attrCount;++i) if(attrs[i].kind==k) return true;
        return false;
    }
    __forceinline PropertyValue getProperty(unsigned int k) const {
        for (int i=0;i<attrCount;++i) if(attrs[i].kind==k) return attrs[i].value;
        PropertyValue z={0};return z;
    }
    void activate_00c9c1d0();
};
struct ContactBlock {
    hkVector4 position,normalAndDepth;
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
    ContactShape* shape;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};
struct ContactSolver;
struct ContactListener {
    virtual void v0();virtual void v1();virtual void v2();virtual void v3();
    virtual void Begin(ContactSolver*,unsigned int,ContactBlock*);
    virtual void Post(ContactSolver*,hkVector4*,hkVector4*);
};
struct Output {hkVector4 impulse,location;ShapeData* body;unsigned int unk24,unk28,unk2c;};
struct Response {hkVector4 impulse,location;};
struct Work {hkVector4 point,normal;float factor,velocityScale,velocity,mass;ShapeData* body;};
template<class T> struct ArrayBase {T* data;int size;unsigned int capacityFlags;T& operator[](int i) {return *reinterpret_cast<T*>(i * sizeof(T) + reinterpret_cast<size_t>(data));}};
template<class T> struct Array: ArrayBase<T> {};
struct ContactSolver {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkVector4 localOrigin;
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
    float minSpeed,correctionScale;
    Array<ContactBlock> contacts;
    ContactListener** listeners;
    int listenerCount;
    ContactListener*& listenerAt(int i) {return listeners[i];}
    void ahkpCharacterProxy_ResolveContacts(const float*,const hkVector4*,Output**,int);
};
extern float DAT_010c8440;
static LocalM128 cross(LocalM128 a,LocalM128 b) {
    LocalM128 ayzx=_mm_shuffle_ps(a,a,0xc9);
    LocalM128 bzxy=_mm_shuffle_ps(b,b,0xd2);
    LocalM128 azxy=_mm_shuffle_ps(a,a,0xd2);
    LocalM128 byzx=_mm_shuffle_ps(b,b,0xc9);
    return _mm_sub_ps(_mm_mul_ps(ayzx,bzxy),_mm_mul_ps(azxy,byzx));
}
static float laneW(const hkVector4& v) {float result;_mm_store_ss(&result,_mm_shuffle_ps(contactQuad(v),contactQuad(v),0xff));return result;}
static float dot(LocalM128 a,LocalM128 b) {
    LocalM128 t=_mm_mul_ps(a,b);
    LocalM128 y=_mm_shuffle_ps(t,t,0x55);
    LocalM128 z=_mm_shuffle_ps(t,t,0xaa);
    float result; _mm_store_ss(&result,_mm_add_ss(z,_mm_add_ss(y,t))); return result;
}
static LocalM128 scale(LocalM128 a,float s) {LocalM128 v=_mm_load_ss(&s);return _mm_mul_ps(_mm_shuffle_ps(v,v,0),a);}
static LocalM128 scaleAccel(LocalM128 a,float s) {LocalM128 v=_mm_load_ss(&s);return _mm_mul_ps(_mm_shuffle_ps(v,v,0),a);}
static LocalM128 scaleExtra(LocalM128 a,float s) {LocalM128 v=_mm_load_ss(&s);return _mm_mul_ps(_mm_shuffle_ps(v,v,0),a);}
// Iterates active contacts, computes impulse responses using body inertia and correction, notifies listeners, and applies or collects results.
// @fnv 0x00cacf80
// src: COMMUNITY 0x00cacf80
void ContactSolver::ahkpCharacterProxy_ResolveContacts(const float* step,const hkVector4* acceleration,Output** output,int outputCapacity) {
    Work work;
    work.velocityScale=readStep(step,2);
    Output* destination=0;
    bool collect=output!=0;
    int count=contacts.size;
    if(collect) {
        if(outputCapacity<count)count=outputCapacity;
        destination=*output;
    }
    for(int index=0;index<count;++index) {
        ShapeData* body=reinterpret_cast<ShapeData*>(reinterpret_cast<char*>(contacts[index].shape)+contacts[index].shape->childOffset);
        if(body->hasProperty(0x1300)) {
            PropertyValue value=body->getProperty(0x1300);
            for(int c=listenerCount-1;c>=0;--c)
                if(listenerAt(c))listenerAt(c)->Begin(this,value.get(),&contacts[index]);
        }
        ContactShape* shape=contacts[index].shape;
        if(shape->active!=1)continue;
        body=reinterpret_cast<ShapeData*>(reinterpret_cast<char*>(shape)+shape->childOffset);
        if(!body || body->motion.kind==5 || body->motion.kind==4)continue;
        work.point.set(sharedQuad(contactQuad(contacts[index].position)));
        work.point.w=contacts[index].normalAndDepth.w;
        work.normal.set(sharedQuad(contactQuad(contacts[index].normalAndDepth)));
        work.body=body;
        Motion* motion=&body->motion;
        hkVector4 surfaceVec;
        surfaceVec.setSub4(work.point,motion->reference);
        surfaceVec.setCross(motion->angular,surfaceVec);
        surfaceVec.add4(motion->translation);
        surfaceVec.sub4(localOrigin);
        float velocity=surfaceVec.dot3scalar(work.normal);
        work.velocity=velocity;
        float impulse=(float)(-velocity*0.9f);
        if(work.point.w<0.0f)impulse=(float)(work.point.w*readStep(step,3)*0.4f+impulse);
        Response response;
        response.location.set(sharedQuad(contactQuad(work.point)));
        response.impulse.set(sharedQuad(_mm_setzero_ps()));
        LocalM128 normal=contactQuad(work.normal);
        if(impulse<0.0f) {
            FloatMatrix3 inertia;
            ((void (__thiscall*)(Motion*,FloatMatrix3*))motion->vtable[10])(motion,&inertia);
            hkVector4 transformed,torque;
            torque.set(sharedQuad(cross(_mm_sub_ps(contactQuad(work.point),contactQuad(body->motion.reference)),contactQuad(work.normal))));
            transformed.hkVector4_setMul3(reinterpret_cast<const hkMatrix3&>(inertia),torque);
            float mass=transformed.dot3scalar(torque);
            work.mass=mass;
            mass+=laneW(body->motion.inertiaAndMass);
            work.mass=mass;
            work.factor=impulse/work.mass;
            float cutoff=-minSpeed*readStep(step,2);
            if(work.factor<cutoff)work.factor=cutoff;
            normal=contactQuad(work.normal);
            response.impulse.set(sharedQuad(scale(normal,work.factor)));
        }else {
            work.factor=0.0f;
            work.mass=laneW(body->motion.inertiaAndMass);
        }
        float incoming=dot(scaleAccel(contactQuad(*acceleration),readStep(step,2)),normal);
        if(work.velocity<0.0f)incoming-=work.velocity;
        if(DAT_010c8440>incoming)response.impulse.set(sharedQuad(_mm_add_ps(scaleExtra(normal,incoming*correctionScale),contactQuad(response.impulse))));
        for(int c=listenerCount-1;c>=0;--c)
            if(listenerAt(c))listenerAt(c)->Post(this,&work.point,&response.impulse);
        if(collect) {
            destination->body=body;
            destination->location.set(sharedQuad(contactQuad(response.location)));
            destination->impulse.set(sharedQuad(contactQuad(response.impulse)));
            ++destination;
        }else {
            body->activate_00c9c1d0();
            ((void (__thiscall*)(Motion*,const hkVector4*,const hkVector4*))motion->vtable[20])(motion,&response.impulse,&response.location);
        }
    }
    if(collect && destination-*output<outputCapacity)destination->body=0;
}
}  // namespace fnv_00cacf80

struct HkEntity289 {
    void removeEntityListener_00c9c670(void* listener) throw();
};
struct HkPhantom289 {
    void RemoveListener(void* listener) throw();
};
struct HkWorldLock289 {
    int unk00;
    int unk04;
};
struct HkWorld289 {
    void hkpWorldObject_removeProperty(HkWorldLock289* apOut, unsigned int auiFlags) throw();
    void FUN_00c905b0() throw();
};

template <class T> struct HkArray289 {
    T* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;

    void clear() { m_iElementCount = 0; }
    ~HkArray289() throw() {
        hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>((&Memory289::hkMemoryRouter_getInstance()->heap()));
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc->bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct HkBaseObject289 {
    virtual ~HkBaseObject289() {}
};
struct HkReferencedObject289 : HkBaseObject289 {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct HkEntityListener289 {
    virtual ~HkEntityListener289() {}
};
struct HkPhantomListener289 {
    virtual ~HkPhantomListener289() {}
};

struct FUN_00cadb00 : HkReferencedObject289, HkEntityListener289, HkPhantomListener289 {
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    HkWorld289* m_pOwningWorld;
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
    HkArray289<BhkElem> m_elements;
    HkArray289<int> m_ids;
    HkArray289<HkEntity289*> m_kActorEntries;
    HkArray289<HkPhantom289*> m_kPhantoms;

    virtual ~FUN_00cadb00();
};

// Removes this listener from every entity and phantom, clears both arrays, then calls FUN_00cd2a50 and FUN_00c905b0 on m_pOwningWorld.
// @fnv 0x00cadb00
FUN_00cadb00::~FUN_00cadb00()
{
    for (int i = 0; i < m_kActorEntries.m_iElementCount; i++) {
        m_kActorEntries.m_data[i]->removeEntityListener_00c9c670(static_cast<HkEntityListener289*>(this));
    }
    m_kActorEntries.clear();

    for (int i = 0; i < m_kPhantoms.m_iElementCount; i++) {
        m_kPhantoms.m_data[i]->RemoveListener(static_cast<HkPhantomListener289*>(this));
    }
    m_kPhantoms.clear();

    HkWorldLock289 lock;
    m_pOwningWorld->hkpWorldObject_removeProperty(&lock, 0x1300);
    m_pOwningWorld->FUN_00c905b0();
}

extern float DAT_0104da48;

struct S_Heap {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n) throw();
};



struct __declspec(align(16)) S_Contact {
    int c00; int c04; int c08; int c0C; int c10; int c14; int c18;
    int c1C; int c20; int c24; int c28; int c2C; int c30; int c34;
    int c38; int c3C; int c40; int c44; int c48; int c4C; int c50;
    int c54; int c58; int c5C; int c60; int c64; int c68; int c6C;
};

struct S_CdBase {
    float m_eps;
    S_CdBase() throw() { m_eps = DAT_0104da48; }
    virtual ~S_CdBase() throw() {}
    virtual void v1();
};

struct S_Arr {
    S_Contact* m_data;
    int m_iElementCount;
    int m_cap;
    void _clearAndDeallocate(S_Heap& h) throw() {
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0) {
            h.ReturnMemory(m_data, (m_cap & 0x3fffffff) * (int)sizeof(S_Contact));
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    ~S_Arr() throw() {
        _clearAndDeallocate(reinterpret_cast<S_Heap&>(((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap()));
    }
};

struct S_InplArr : S_Arr {
    int unk0C;
    S_Contact m_store[8];
    S_InplArr() throw() {
        m_data = m_store;
        m_iElementCount = 0;
        m_cap = 0x80000008;
    }
};

struct S_Collector : S_CdBase {
    int unk08, unk0C;
    S_InplArr m_kHits;
    S_Collector() throw() { m_kHits.m_iElementCount = 0; }
    virtual ~S_Collector() throw() {}
};

struct S00cafbf0_Obj {
    void hkpCharacterProxy_integrateImplementation(int, int, S_Collector*, S_Collector*, int, int) throw();
    void hkpCharacterProxy_integrateMultithreaded(int a, int b, int c, int d) throw();
};

// Creates two S_Collector objects and passes them with a, b, c and d to FUN_00cade20.
// @fnv 0x00cafbf0
// src: COMMUNITY 0x00cafbf0
void S00cafbf0_Obj::hkpCharacterProxy_integrateMultithreaded(int a, int b, int c, int d) throw() {
    S_Collector first;
    S_Collector second;
    hkpCharacterProxy_integrateImplementation(a, b, &first, &second, c, d);
}

// fires added/removed notifications and keeps entity/phantom listeners attached to the touched objects.

struct S_00caf4d0_Heap {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct S_00caf4d0_Stack {
    char* m_next;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw() { m_next = (char*)p; }
};
static __forceinline hkMemoryRouter* GetRouter37() throw() { return reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance()); }
void ResizeAudioStream(S_00caf4d0_Heap& alloc, void* array, int elemSize) throw();

inline void* __cdecl operator new(unsigned int, void* where) throw() { return where; }



struct S_00caf4d0_Collidable {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset; // 0x10
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;               // 0x18
    void* getOwner() const throw() { return (void*)((char*)this + m_iOwnerOffset); }
};

struct S_00caf4d0_Point {
    hkVector4 m_vContactPosition;            // 0x00
    hkVector4 m_vSeparatingNormal;    // 0x10 (w = distance)
    int m_pCollidableA;                        // 0x20
    int m_uiShapeKeyA;                          // 0x24
    int m_kContactPointB[8];                      // 0x28
    S_00caf4d0_Collidable* m_pCollidableB;     // 0x48
    int m_uiShapeKeyB;                          // 0x4c
    int m_kContactPointC[8];                      // 0x50

    S_00caf4d0_Point& operator=(const S_00caf4d0_Point& other) throw();
    float getDistance() const throw() { return m_vSeparatingNormal.w; }
};

static __forceinline void memCpy8(void* dst, const void* src, int n) throw()
{
    const unsigned __int64* s = (const unsigned __int64*)src;
    unsigned __int64* d = (unsigned __int64*)dst;
    for (int i = 0; i < n; i++)
        d[i] = s[i];
}

template <class T> __forceinline void constructWithCopy(T* p, const T& t) throw()
{
    new (p) T(t);
}
template <class T> __forceinline void constructWithCopy(T** p, T* const& t) throw()
{
    for (int k = 0; k < 1; k++)
        p[k] = t;
}

template <class T>
struct S_00caf4d0_Array { // local form of hkArrayBase: 0x00caf4d0 needs the local helper split; the shared form changes extent from 1535 to 1539 bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const throw() { return m_iElementCount; }
    T& operator[](int i) throw() { return m_data[i]; }
    const T& operator[](int i) const throw() { return m_data[i]; }
    void clear() throw() { m_iElementCount = 0; }
    int indexOf(const T& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void AddBack(const T& t) throw()
    {
        hkMemoryRouter* router = GetRouter37();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(reinterpret_cast<S_00caf4d0_Heap&>(router->heap()), this, sizeof(T));
        constructWithCopy(m_data + m_iElementCount, t);
        m_iElementCount++;
    }
    void removeAt(int index) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy8(m_data + index, m_data + m_iElementCount, sizeof(T) / 8);
    }
};

template <class T> struct S_00caf4d0_LocalArray : S_00caf4d0_Array<T> {
    T* m_pStackAllocation;
    __forceinline S_00caf4d0_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)reinterpret_cast<S_00caf4d0_Stack*>(&GetRouter37()->m_stack.m_next.m_storage)->allocateStack(capacity * sizeof(T));
        this->m_iElementCount = 0;
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00caf4d0_LocalArray() throw()
    {
        reinterpret_cast<S_00caf4d0_Stack*>(&GetRouter37()->m_stack.m_next.m_storage)->deallocateStack(m_pStackAllocation);
        S_00caf4d0_Heap& heap = reinterpret_cast<S_00caf4d0_Heap&>(GetRouter37()->heap());
        if ((this->m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
};

struct S_00caf4d0_Collector {
    void* m_vt;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    S_00caf4d0_Array<S_00caf4d0_Point> m_kHits; // 0x10
};

struct S_00caf4d0_EntityListener { virtual void elUnk00(); };
struct S_00caf4d0_PhantomListener { virtual void plUnk00(); };
struct S_00caf4d0_TrackerBase { virtual void tbUnk00(); int unk04; };

struct S_00caf4d0_Entity {
    void hkpEntity_addEntityListener(S_00caf4d0_EntityListener* l) throw();
    void removeEntityListener_00c9c670(S_00caf4d0_EntityListener* l) throw();
};
struct S_00caf4d0_Phantom {
    void AddItem(S_00caf4d0_PhantomListener* l) throw();
    void RemoveListener(S_00caf4d0_PhantomListener* l) throw();
};

extern float DAT_0104da48;
extern const float g_011dd8bc_arg1;

static inline S_00caf4d0_Entity* getRigidBody_caf(const S_00caf4d0_Collidable* c) throw()
{
    if (c->m_type == 1)
        return (S_00caf4d0_Entity*)c->getOwner();
    return 0;
}
static inline S_00caf4d0_Phantom* getPhantom_caf(const S_00caf4d0_Collidable* c) throw()
{
    if (c->m_type == 2)
        return (S_00caf4d0_Phantom*)c->getOwner();
    return 0;
}

struct S_00caf4d0_Tracker : S_00caf4d0_TrackerBase, S_00caf4d0_EntityListener, S_00caf4d0_PhantomListener {
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
    float unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    S_00caf4d0_Array<S_00caf4d0_Point> m_kPoints;      // 0x74
    S_00caf4d0_Array<void*> m_kListeners;              // 0x80
    S_00caf4d0_Array<S_00caf4d0_Entity*> m_kActorEntries;  // 0x8c
    S_00caf4d0_Array<S_00caf4d0_Phantom*> m_kPhantoms; // 0x98

    float hkpCharacterProxy_surfaceDistance(const S_00caf4d0_Point* a, const S_00caf4d0_Point* b) throw();
    void hkpCharacterProxy_fireContactRemoved(const S_00caf4d0_Point* p) throw();
    void hkpCharacterProxy_fireContactAdded(const S_00caf4d0_Point* p) throw();
    int hkpCharacterProxy_findSurface(const S_00caf4d0_Point* p) throw();

    void hkpCharacterProxy_updateManifold(const S_00caf4d0_Collector* input, const S_00caf4d0_Collector* extra, bool keepListeners) throw();
};

// Merges input and extra hit points into m_kPoints, deduplicates close points, and updates entity/phantom listener lists.
// @fnv 0x00caf4d0
// src: XBOX_PDB 0x00caf4d0
void S_00caf4d0_Tracker::hkpCharacterProxy_updateManifold(const S_00caf4d0_Collector* input, const S_00caf4d0_Collector* extra, bool keepListeners) throw()
{
    if (!keepListeners)
    {
        for (int i = 0; i < m_kActorEntries.GetLogicalSize(); i++)
            m_kActorEntries[i]->removeEntityListener_00c9c670(this);
        for (int i = 0; i < m_kPhantoms.GetLogicalSize(); i++)
            m_kPhantoms[i]->RemoveListener(this);
    }

    float minDistance = DAT_0104da48;
    m_kActorEntries.clear();
    m_kPhantoms.clear();

    S_00caf4d0_LocalArray<S_00caf4d0_Point> hits(input->m_kHits.GetLogicalSize());
    hits.m_iElementCount = input->m_kHits.GetLogicalSize();
    for (int i = 0; i < hits.GetLogicalSize(); i++)
    {
        S_00caf4d0_Point& p = hits[i];
        p = input->m_kHits[i];
        if (p.getDistance() < minDistance)
            minDistance = p.getDistance();
    }

    for (int j = m_kPoints.GetLogicalSize() - 1; j >= 0; j--)
    {
        S_00caf4d0_Point& old = m_kPoints[j];
        float best = 1.1f;
        int bestIndex = -1;
        for (int k = 0; k < hits.GetLogicalSize(); k++)
        {
            float d = hkpCharacterProxy_surfaceDistance(&hits[k], &old);
            if (d < best)
            {
                best = d;
                bestIndex = k;
            }
        }
        if (bestIndex >= 0)
        {
            S_00caf4d0_Point& hit = hits[bestIndex];
            if (hit.m_pCollidableB != old.m_pCollidableB)
            {
                hkpCharacterProxy_fireContactRemoved(&old);
                hkpCharacterProxy_fireContactAdded(&hit);
            }
            old = hit;
            hits.removeAt(bestIndex);
        }
        else
        {
            hkpCharacterProxy_fireContactRemoved(&m_kPoints[j]);
            m_kPoints.removeAt(j);
        }
    }

    for (int k = 0; k < hits.GetLogicalSize(); k++)
    {
        S_00caf4d0_Point& hit = hits[k];
        if (hit.getDistance() == minDistance)
        {
            int index = hkpCharacterProxy_findSurface(&hit);
            if (index >= 0)
            {
                S_00caf4d0_Point& old = m_kPoints[index];
                if (hit.m_pCollidableB != old.m_pCollidableB)
                {
                    hkpCharacterProxy_fireContactRemoved(&old);
                    hkpCharacterProxy_fireContactAdded(&hit);
                }
                old = hit;
            }
            else
            {
                hkpCharacterProxy_fireContactAdded(&hit);
                m_kPoints.AddBack(hit);
            }
        }
    }

    if (extra->m_kHits.GetLogicalSize() > 0)
    {
        const S_00caf4d0_Point& hit = extra->m_kHits[0];
        if (hkpCharacterProxy_findSurface(&hit) == -1)
        {
            hkpCharacterProxy_fireContactAdded(&hit);
            m_kPoints.AddBack(hit);
        }
    }

    for (int i = m_kPoints.GetLogicalSize() - 1; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            S_00caf4d0_Array<S_00caf4d0_Point>& pts = m_kPoints;
            if (hkpCharacterProxy_surfaceDistance(&pts[i], &pts[j]) < 0.1f)
            {
                hkpCharacterProxy_fireContactRemoved(&m_kPoints[i]);
                m_kPoints.m_iElementCount--;
                if (m_kPoints.m_iElementCount != i)
                    memCpy8(&m_kPoints[i], &m_kPoints[m_kPoints.m_iElementCount], sizeof(S_00caf4d0_Point) / 8);
                break;
            }
        }
    }

    for (int i = 0; i < m_kPoints.GetLogicalSize(); i++)
    {
        if (m_kPoints[i].m_pCollidableB->m_type == 1)
        {
            S_00caf4d0_Entity* entity = getRigidBody_caf(m_kPoints[i].m_pCollidableB);
            if (entity && m_kActorEntries.indexOf(entity) == -1)
            {
                if (!keepListeners)
                    entity->hkpEntity_addEntityListener(this);
                m_kActorEntries.AddBack(entity);
            }
        }
        if (m_kPoints[i].m_pCollidableB->m_type == 2)
        {
            S_00caf4d0_Phantom* phantom = getPhantom_caf(m_kPoints[i].m_pCollidableB);
            if (phantom && m_kPhantoms.indexOf(phantom) == -1)
            {
                if (!keepListeners)
                    phantom->AddItem(this);
                m_kPhantoms.AddBack(phantom);
            }
        }
    }
}

struct ContactQuery {
    void ahkpCharacterProxy_checkSupportWithCollector(void*, unsigned, S_Collector*) throw();
    void ahkpCharacterProxy_checkSupport(void*, unsigned);
};
// Creates a local S_Collector and calls FUN_00cae900 with a, b and the collector.
// @fnv 0x00cafd00
// src: COMMUNITY 0x00cafd00
void ContactQuery::ahkpCharacterProxy_checkSupport(void* a, unsigned b) {
    S_Collector collector;
    ahkpCharacterProxy_checkSupportWithCollector(a,b,&collector);
}

struct CadColl {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    signed char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    unsigned char m_type;
    void* getOwner() const throw() { return (void*)((char*)this + m_iOwnerOffset); }
};
static inline S_00caf4d0_Phantom* getPhantom_cad(const CadColl* c) throw()
{
    if (c->m_type == 2)
        return (S_00caf4d0_Phantom*)c->getOwner();
    return 0;
}
struct CadPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    int m_pCollidableA;
    int m_uiShapeKeyA;
    int m_kContactPointB[8];
    CadColl* m_pCollidableB;
    int m_uiShapeKeyB;
    int m_kContactPointC[8];
};

struct CadPhantomListener {
    virtual void plUnk00();
    virtual void hkpPhantomListener_phantomRemovedCallback(struct CadPhantom* p) throw();
};
struct CadPhantom {
    void RemoveListener(CadPhantomListener* l) throw();
};
// local form of hkArrayBase: 0x00cad820 needs the local one-argument indexOf/removeAt helpers; the shared form changes extent from 212 to 187 bytes.
struct CadPtrArray {
    CadPhantom** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const throw() { return m_iElementCount; }
    CadPhantom*& operator[](int i) throw() { return m_data[i]; }
    int indexOf(CadPhantom* const& t) const throw()
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index) throw()
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};
struct Cad820Cls : S_00caf4d0_TrackerBase, S_00caf4d0_EntityListener, CadPhantomListener {
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
    float unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    S_00caf4d0_Array<CadPoint> m_kPoints;
    S_00caf4d0_Array<void*> m_kListeners;
    S_00caf4d0_Array<S_00caf4d0_Entity*> m_kActorEntries;
    CadPtrArray m_kPhantoms;

    void hkpPhantomListener_phantomRemovedCallback(CadPhantom* phantom) throw();
};
// Calls phantom->RemoveListener(this), removes m_kPoints entries whose collidable B belongs to the phantom, and removes phantom from m_kPhantoms.
// @fnv 0x00cad820
// src: COMMUNITY 0x00cad820
void Cad820Cls::hkpPhantomListener_phantomRemovedCallback(CadPhantom* phantom) throw()
{
    phantom->RemoveListener(this);
    for (int i = m_kPoints.GetLogicalSize() - 1; i >= 0; --i)
    {
        if (getPhantom_cad(m_kPoints[i].m_pCollidableB) == (S_00caf4d0_Phantom*)phantom)
            m_kPoints.removeAt(i);
    }
    m_kPhantoms.removeAt(m_kPhantoms.indexOf(phantom));
}

extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_setzero_ps(void);



struct S00cafd90_Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char unk10;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char unk18;
};

struct S00cafd90_Body;

struct S00cafd90_Conv {
    __declspec(noalias) void hkpRigidBody_getPointVelocity(S00cafd90_Body* body, LocalM128* out);
};

struct S00cafd90_Body {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 unk10;
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
    S00cafd90_Info* unk48;
};

extern double DAT_0101ffa0;
extern double DAT_01020758;

static __forceinline S00cafd90_Conv* S00cafd90_ConvOf(S00cafd90_Body* b)
{
    S00cafd90_Info* info = b->unk48;
    if (info->unk18 != 1)
        return 0;
    return (S00cafd90_Conv*)((char*)info + info->unk10);
}

static __forceinline hkVector4 S00cafd90_Pos(S00cafd90_Body* b)
{
    hkVector4 r;
    r.m_vComponents = _mm_setzero_ps();
    if (S00cafd90_Conv* c = S00cafd90_ConvOf(b))
        c->hkpRigidBody_getPointVelocity(b, &r.m_vComponents);
    return r;
}

static __forceinline float S00cafd90_Dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 prod = _mm_mul_ps(a, b);
    LocalM128 s1 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
    LocalM128 s2 = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), s1);
    float r;
    _mm_store_ss(&r, s2);
    return r;
}

// Returns |pa-pb|^2 * DAT_0101ffa0 + unk60^2 * (1 - dot of the unk10 vectors) * DAT_01020758 + the squared difference of their w components.
// @fnv 0x00cafd90
// src: COMMUNITY 0x00cafd90
float FUN_00cacf10_cls::hkpCharacterProxy_surfaceDistance(void* a_, void* b_)
{
    S00cafd90_Body* a = (S00cafd90_Body*)a_;
    S00cafd90_Body* b = (S00cafd90_Body*)b_;
    float t = 1.0f - S00cafd90_Dot3(a->unk10.m_vComponents, b->unk10.m_vComponents);
    float c = *(float*)&unk60 * *(float*)&unk60 * t;
    float dw = a->unk10.m_vComponents.m128_f32[3] - b->unk10.m_vComponents.m128_f32[3];
    dw = dw * dw;
    hkVector4 vPosA = S00cafd90_Pos(a);
    hkVector4 vPosB = S00cafd90_Pos(b);
    float e = S00cafd90_Dot3(_mm_sub_ps(vPosA.m_vComponents, vPosB.m_vComponents), _mm_sub_ps(vPosA.m_vComponents, vPosB.m_vComponents));
    return e * DAT_0101ffa0 + c * DAT_01020758 + dw;
}

extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_load_ss(const float* p);
typedef float S00cacd60_Real;

class S00cacd60_SimdReal {
public:
    S00cacd60_SimdReal(const LocalM128& x) : m_vValue(x) {}
    S00cacd60_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    operator float() const { float s; _mm_store_ss(&s,m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
private:
    LocalM128 m_vValue;
};
static __forceinline S00cacd60_SimdReal S00cacd60_dot3(const hkVector4& v,const hkVector4& a) {
    LocalM128 x2 = _mm_mul_ps(v.m_vComponents,a.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
    return _mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xy);
}
typedef const S00cacd60_SimdReal& S00cacd60_SimdParam;

class S00cacd60_Bool {
public:
    __forceinline S00cacd60_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};
struct S00cacd60_Swept {
    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    __forceinline S00cacd60_Real getInvDeltaTime() const { return m_vCenterOfMass1(3); }
};
enum S00cacd60_MotionType { S00cacd60_KEYFRAMED = 4, S00cacd60_FIXED = 5 };
struct S00cacd60_MotionState {
    hkVector4 m_t0; hkVector4 m_t1; hkVector4 m_t2; hkVector4 m_t3;
    S00cacd60_Swept m_kSweptTransform;
    hkVector4 m_qRotation0; hkVector4 m_qRotation1; hkVector4 m_vCenterOfMassLocal;
    hkVector4 m_kDeltaAngle;
    __forceinline const S00cacd60_Swept& getSweptTransform() const { return m_kSweptTransform; }
};
struct S00cacd60_Motion {
    void* vtbl;
    int m_refs;
    signed char m_type;
    int unk0c;
    S00cacd60_MotionState m_kMotionState;
    __forceinline S00cacd60_MotionType getType() const { return static_cast<S00cacd60_MotionType>(m_type); }
    __forceinline S00cacd60_MotionState* GetMotionState() { return &m_kMotionState; }
};
struct S00cacd60_Collidable {
    int m_pCollisionShape; int m_uiCollisionShapeKey; int m_pMotionState; int m_parent;
    signed char m_iOwnerOffset;
    int m_iOwnerObjectOffset;
    signed char m_type;
    __forceinline int getType() const { return m_type; }
    __forceinline void* getOwner() const { return const_cast<char*>(reinterpret_cast<const char*>(this) + m_iOwnerOffset); }
};
class S00cacd60_Body {
public:
    S00cacd60_Collidable m_coll;
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
    S00cacd60_Motion m_pMotionState;
    __forceinline S00cacd60_Motion* getRigidMotion() const { return const_cast<S00cacd60_Motion*>(&m_pMotionState); }
    __forceinline S00cacd60_MotionType getMotionType() const { return getRigidMotion()->getType(); }
    __forceinline S00cacd60_Bool isFixedOrKeyframed() const { return (m_pMotionState.m_type == S00cacd60_FIXED) || (m_pMotionState.m_type == S00cacd60_KEYFRAMED); }
    __forceinline const hkVector4& getCenterOfMassInWorld() const { return getRigidMotion()->GetMotionState()->getSweptTransform().m_vCenterOfMass1; }
    void hkpRigidBody_getPointVelocity(const hkVector4& p, hkVector4& vel) const;
};
__forceinline S00cacd60_Body* S00cacd60_GetRigidBody(const S00cacd60_Collidable* c) {
    if (c->getType() == 1) {
        return static_cast<S00cacd60_Body*>(c->getOwner());
    }
    return 0;
}
__forceinline void S00cacd60_getVelocity(const S00cacd60_MotionState& ms, hkVector4& linearVelOut, hkVector4& angularVelOut) {
    linearVelOut.setSub4(ms.getSweptTransform().m_vCenterOfMass1, ms.getSweptTransform().m_vCenterOfMass0);
    linearVelOut.mul4(ms.getSweptTransform().getInvDeltaTime());
    angularVelOut.setMul4(ms.getSweptTransform().getInvDeltaTime(), ms.m_kDeltaAngle);
}
struct S00cacd60_Contact {
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    __forceinline const hkVector4& getPosition() const { return m_vContactPosition; }
    __forceinline const hkVector4& getNormal() const { return m_vSeparatingNormal; }
    __forceinline const hkVector4& getSeparatingNormal() const { return m_vSeparatingNormal; }
};
struct S00cacd60_Hit {
    S00cacd60_Contact m_kPoint;
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
    const S00cacd60_Collidable* m_pRootCollidableB;
};
struct S00cacd60_Surface {
    hkVector4 m_kTriangleNormal;
    hkVector4 m_fVelocity;
    float m_fStaticFriction;
    float m_fExtraUpStaticFriction;
    float m_fExtraDownStaticFriction;
    float m_fDynamicFriction;
    int m_priority;
};
class S00cacd60_Proxy {
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
    int unk28;
    int unk2c;
    int unk30;
    float m_dynamicFriction34;
    float m_staticFriction38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    float m_extraUp50;
    float m_extraDown54;
    float m_fKeepDistance;
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
    float m_fPenetrationRecoverySpeed;
    void hkpCharacterProxy_extractSurfaceConstraintInfo(const S00cacd60_Hit& hit, S00cacd60_Surface& surface, float timeTravelled) const;
};
// Populates a Surface with friction, velocity and priority from a Hit and the proxy's friction and penetration recovery fields.
// @fnv 0x00cacd60
// src: COMMUNITY 0x00cacd60
void S00cacd60_Proxy::hkpCharacterProxy_extractSurfaceConstraintInfo(const S00cacd60_Hit& hit, S00cacd60_Surface& surface, float timeTravelled) const {
    surface.m_kTriangleNormal = hit.m_kPoint.getSeparatingNormal();
    surface.m_kTriangleNormal(3) -= static_cast<S00cacd60_Real>(m_fKeepDistance);
    surface.m_fStaticFriction = m_staticFriction38;
    surface.m_fDynamicFriction = m_dynamicFriction34;
    surface.m_fExtraUpStaticFriction = m_extraUp50;
    surface.m_fExtraDownStaticFriction = m_extraDown54;
    surface.m_fVelocity.setZero4();
    surface.m_priority = 0;
    S00cacd60_Body* body = S00cacd60_GetRigidBody(hit.m_pRootCollidableB);
    if (body) {
        if (body->isFixedOrKeyframed()) {
            body->hkpRigidBody_getPointVelocity(hit.m_kPoint.getPosition(), surface.m_fVelocity);
        } else {
            hkVector4 linear;
            hkVector4 angular;
            S00cacd60_getVelocity(*body->getRigidMotion()->GetMotionState(), linear, angular);
            hkVector4 r;
            r.setSub4(hit.m_kPoint.getPosition(), body->getCenterOfMassInWorld());
            surface.m_fVelocity.setCross(angular, r);
            surface.m_fVelocity.add4(linear);
        }
        surface.m_kTriangleNormal(3) -= S00cacd60_dot3(surface.m_fVelocity, surface.m_kTriangleNormal) * timeTravelled;
        if (body->getMotionType() == S00cacd60_FIXED) {
            surface.m_priority = 2;
        }
        if (body->getMotionType() == S00cacd60_KEYFRAMED) {
            surface.m_priority = 1;
        }
    }
    if (surface.m_kTriangleNormal(3) < -1.1920928955078125e-07) {
        surface.m_fVelocity.addMul4(hkSimdReal(-surface.m_kTriangleNormal(3) * m_fPenetrationRecoverySpeed), hit.m_kPoint.getNormal());
        surface.m_kTriangleNormal(3) = 0.0f;
    }
}

extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

struct __declspec(align(16)) Contact {
    LocalM128 normal;
    LocalM128 tangent;
    float distance;
    float friction;
    float restitution;
    float bias;
    unsigned int identifier;
    unsigned int contactFlags;
    float accumulatedImpulse;
    float reservedWeight;
};

struct ContactBuffer {
    Contact* entries;
    unsigned int count;
    unsigned int capacityFlags;
};

extern float DAT_01013ea4;

static __forceinline LocalM128 Set1(float w) { LocalM128 r = _mm_load_ss(&w); return _mm_shuffle_ps(r, r, 0); }

static __forceinline LocalM128 NormalizeSafe(LocalM128 projected)
{
    LocalM128 squares = _mm_mul_ps(projected, projected);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares));
    LocalM128 rs = _mm_rsqrt_ss(sum);
    LocalM128 mask = _mm_cmpeq_ss(sum, _mm_set_ss(0.0f));
    LocalM128 t = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, rs), rs));
    LocalM128 refined = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), rs), t);
    refined = _mm_andnot_ps(mask, refined);
    return _mm_mul_ps(_mm_shuffle_ps(refined, refined, 0), projected);
}

// If dot(normal at index, planev) is between DAT_01013ea4 and maximumDistance, appends a copy with a re-projected, normalized normal and returns 1, else 0.
// @fnv 0x00cadca0
// src: XBOX_PDB 0x00cadca0
__declspec(noinline) static unsigned char addMaxSlopePlane(ContactBuffer* buffer, unsigned int index, float maximumDistance, const LocalM128& planev)
{
    LocalM128 scaled = _mm_mul_ps(buffer->entries[index].normal, planev);
    float depth;
    _mm_store_ss(&depth, _mm_add_ss(_mm_shuffle_ps(scaled, scaled, 0xaa), _mm_add_ss(_mm_shuffle_ps(scaled, scaled, 0x55), scaled)));
    if (DAT_01013ea4 < depth && maximumDistance > depth)
    {
        hkMemoryRouter* router = GetRouter37();
        if (buffer->count == (buffer->capacityFlags & 0x3fffffffu))
            ResizeAudioStream(reinterpret_cast<S_00caf4d0_Heap&>(router->heap()), buffer, 64);
        Contact& destination = buffer->entries[buffer->count++];
        const Contact& original = buffer->entries[index];
        destination.normal = original.normal;
        destination.tangent = original.tangent;
        destination.distance = original.distance;
        destination.friction = original.friction;
        destination.restitution = original.restitution;
        destination.bias = original.bias;
        destination.identifier = original.identifier;

        LocalM128 projected = _mm_add_ps(_mm_mul_ps(planev, Set1(-depth)), destination.normal);
        destination.normal = NormalizeSafe(projected);
        return 1;
    }
    return 0;
}

volatile unsigned g_i; ContactBuffer* volatile g_b; volatile float g_d; const LocalM128* volatile g_p; volatile int g_o;
void CallTarget_cadca0() { ContactBuffer* b=g_b; unsigned i=g_i; float d=g_d; const LocalM128* p=g_p; g_o=addMaxSlopePlane(b,i,d,*p); g_o=addMaxSlopePlane(b,i,d,*p); }

static __forceinline LocalM128 CaccSplat(float value) { LocalM128 scalar = _mm_load_ss(&value); return _mm_shuffle_ps(scalar, scalar, 0); }
extern "C" void _mm_store_ps(float*, LocalM128);



template<class T> struct S_Pad { T* p; T* val() const { return p; } };
struct S_Inner { int unk0; int unk4; int unk8; float m0c; hkVector4 m10; };
struct S_B { int unk0; int unk4; int unk8; int unkc; S_Inner* m10; };
struct S_A { hkVector4 v; float m10; float m14; float m18; float m1c; float m20; };

extern const hkVector4 DAT_010ec7f0;

static inline float Mn(float a, float b) { return a < b ? a : b; }
static inline float Mx(float a, float b) { return a > b ? a : b; }
static __forceinline LocalM128 Dot3(LocalM128 x, LocalM128 y) {
    LocalM128 p = _mm_mul_ps(x, y);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
struct S_00cacc50 {
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
    float m58;
    float hkpCharacterProxy_moveToLinearCastHitPosition(const S_A& a, S_B* b, S_Pad<hkVector4> c, S_Pad<hkVector4> d);
};

// Computes a clamped scalar parameter from a dot product and length, then blends two vectors and returns the scaled result.
// @fnv 0x00cacc50
// src: COMMUNITY 0x00cacc50
float S_00cacc50::hkpCharacterProxy_moveToLinearCastHitPosition(const S_A& a, S_B* b, S_Pad<hkVector4> c, S_Pad<hkVector4> d) {
    const S_A* ap = &a;
    LocalM128 v = ap->v.m_vComponents;
    S_Inner* q = b->m10;
    float qc = q->m0c;
    float f58 = m58;
    float len;
    float fDot;
    _mm_store_ss(&len, _mm_sqrt_ss(Dot3(v, v)));
    _mm_store_ss(&fDot, Dot3(q->m10.m_vComponents, v));
    float t1 = fDot / len;
    float u = f58 / -t1;
    float r = qc - u / len;
    r = Mx(0.0f, Mn(r, 1.0f));
    LocalM128 t = CaccSplat(r);
    _mm_store_ps(&d.val()->x, _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0.m_vComponents, t), d.val()->m_vComponents), _mm_mul_ps(c.val()->m_vComponents, t)));
    return ap->m20 * r;
}

#include <math.h>
extern "C" void _ReadWriteBarrier(void);

extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);

extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;



struct S_00cad500_Elem16 {
    int m_iOwnerObjectOffset;
    int unk04;
    int unk08;
    int unk0C;
};

struct S_00cad500_This;

struct S_00cad500_Pair {
    S_00cad500_This* a;
    int b;
    S_00cad500_Pair(S_00cad500_This* a_, int b_) { a = a_; b = b_; }
    S_00cad500_Pair(const S_00cad500_Pair& o) { a = o.a; b = o.b; }
};

struct S_00cad500_Ref {
    int unk00;
    int unk04;
    int m_08;
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
    S_00cad500_Elem16* m_78;
    int m_7c;
    void FUN_00c90510();
    void FUN_00c905b0();
    void AddEntry(int id, S_00cad500_Pair p);
};

struct S_00cad500_E1 {
    void removeEntityListener_00c9c670(void* p);
};
struct S_00cad500_E2 {
    void RemoveListener(void* p);
};


struct S_00cad500_Src {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_10;
    float m_20;
    float m_24;
    float m_28;
    int unk2C;
    hkVector4 m_30;
    float m_40;
    float m_44;
    S_00cad500_Ref* m_48;
    float m_4c;
    float m_50;
    int m_54;
    float m_58;
    float m_5c;
    float m_60;
    float m_64;
    float m_68;
    int m_6c;
    char m_70;
    int unk71;
};

struct S_00cad500_This {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_10;
    hkVector4 m_20;
    S_00cad500_Ref* m_30;
    float m_34;
    float m_38;
    int unk3C;
    hkVector4 m_40;
    float m_50;
    float m_54;
    float m_58;
    float m_5c;
    float m_60;
    int m_64;
    float m_68;
    float m_6c;
    float m_70;
    int unk74;
    int m_78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    S_00cad500_E1** m_8c;
    int m_90;
    int unk94;
    S_00cad500_E2** m_98;
    int m_9c;
    int unkA0;
    float m_a4;
    float m_a8;
    int m_ac;
    char m_b0;
    int unkB1;
    void hkpCharacterProxy_updateFromCinfo(S_00cad500_Src* a);
    void hkpCharacterProxy_setPosition(S_00cad500_Src* a);
};

__forceinline void S_00cad500_Normalize3(hkVector4& v, float zero, float three, float half)
{
    LocalM128 q = reinterpret_cast<LocalM128&>(v);
    LocalM128 t = _mm_mul_ps(q, q);
    LocalM128 l = _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t);
    l = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), l);
    LocalM128 r = _mm_rsqrt_ss(l);
    LocalM128 mask = _mm_cmpeq_ss(l, _mm_set_ss(zero));
    LocalM128 lrr = _mm_mul_ss(_mm_mul_ss(l, r), r);
    LocalM128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(half), r), _mm_sub_ss(_mm_set_ss(three), lrr));
    inv = _mm_andnot_ps(mask, inv);
    inv = _mm_shuffle_ps(inv, inv, 0);
    reinterpret_cast<LocalM128&>(v) = _mm_mul_ps(inv, q);
}

// Copies fields from a, normalizes m_40, zeroes m_20, runs FUN_00c9c670/FUN_00d07c10 over the m_8c and m_98 entries, then registers 0x1300 on m_30 unless present.
// @fnv 0x00cad500
// src: XBOX_PDB 0x00cad500
void S_00cad500_This::hkpCharacterProxy_updateFromCinfo(S_00cad500_Src* apSrc)
{
    apSrc->m_48->FUN_00c90510();
    if (m_30) {
        m_30->FUN_00c905b0();
    }
    reinterpret_cast<LocalM128&>(m_10) = reinterpret_cast<LocalM128&>(apSrc->m_10);
    m_34 = apSrc->m_20;
    m_38 = apSrc->m_24;
    m_5c = apSrc->m_28;
    m_50 = apSrc->m_40;
    m_54 = apSrc->m_44;
    m_58 = apSrc->m_4c;
    m_30 = apSrc->m_48;
    m_60 = apSrc->m_50;
    m_64 = apSrc->m_54;
    m_68 = apSrc->m_58;
    m_6c = apSrc->m_5c;
    m_70 = apSrc->m_60;
    float c = (float)cos(apSrc->m_64);
    m_a4 = c;
    m_a8 = apSrc->m_68;
    m_ac = apSrc->m_6c;
    m_b0 = apSrc->m_70;
    reinterpret_cast<LocalM128&>(m_40) = reinterpret_cast<LocalM128&>(apSrc->m_30);
    S_00cad500_Normalize3(m_40, 0.0f, 3.0f, DAT_01016248);
    if (m_30->m_08 != 0) {
        hkpCharacterProxy_setPosition(apSrc);
    }
    reinterpret_cast<LocalM128&>(m_20) = _mm_setzero_ps();
    for (int i = 0; i < m_90; i++) {
        m_8c[i]->removeEntityListener_00c9c670(&unk08);
    }
    m_90 = 0;
    for (int j = 0; j < m_9c; j++) {
        m_98[j]->RemoveListener(&unk0C);
    }
    m_9c = 0;
    m_78 = 0;
    _ReadWriteBarrier();
    for (int k = 0, n = m_30->m_7c; k < n; k++) {
        if (m_30->m_78[k].m_iOwnerObjectOffset == 0x1300) {
            return;
        }
    }
    m_30->AddEntry(0x1300, S_00cad500_Pair(this, 0));
}

typedef float hkReal;



struct hkpCharacterProxyCinfo {
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    hkReal m_fDynamicFriction;
    hkReal m_fStaticFriction;
    hkReal m_fKeepContactTolerance;
    int m_2c;
    hkVector4 m_vStart;
    hkReal m_fExtraUpStaticFriction;
    hkReal m_fExtraDownStaticFriction;
    void* m_pCharacterPhantom;
    hkReal m_fKeepDistance;
    hkReal m_fContactAngleSensitivity;
    int m_uiUserPlanes;
    hkReal m_fMaxCharacterSpeedForSolver;
    hkReal m_fCharacterStrength;
    hkReal m_fCharacterMass;
    hkReal m_fMaximumSlope;
    hkReal m_fPenetrationRecoverySpeed;
    int m_iMaxCastIterations;
    bool m_bRefreshManifoldInCheckSupport;
};

namespace MathUtilities {
    inline hkReal fabs(hkReal r) { return hkReal(::fabs(r)); }
    inline hkReal acos(hkReal r)
    {
        if (MathUtilities::fabs(r) >= 1.0f)
        {
            r = (r > 0) ? 0 : 3.14159265358979f;
            return r;
        }
        return hkReal(::acos(r));
    }
}

struct hkpCharacterProxy {
    int m_00, m_04, m_08, m_0c;
    hkVector4 m_fVelocity;
    int m_20, m_24, m_28, m_2c;
    void* m_pCharacterPhantom;
    hkReal m_fDynamicFriction;
    hkReal m_fStaticFriction;
    int m_3c;
    hkVector4 m_vStart;
    hkReal m_fExtraUpStaticFriction;
    hkReal m_fExtraDownStaticFriction;
    hkReal m_fKeepDistance;
    hkReal m_fKeepContactTolerance;
    hkReal m_fContactAngleSensitivity;
    int m_uiUserPlanes;
    hkReal m_fMaxCharacterSpeedForSolver;
    hkReal m_fCharacterStrength;
    hkReal m_fCharacterMass;
    int m_74, m_78, m_7c, m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0;
    hkReal m_fMaximumSlopeAngle;
    hkReal m_fPenetrationRecoverySpeed;
    int m_iMaxCastIterations;
    bool m_bRefreshManifoldInCheckSupport;

    const hkVector4& getPosition() const;
    void getCinfo(hkpCharacterProxyCinfo& info) const;
};

// @fnv 0x00cac9a0
// src: XBOX_PDB 0x00cac9a0
void hkpCharacterProxy::getCinfo(hkpCharacterProxyCinfo& info) const
{
    info.m_vContactPosition = getPosition();
    info.m_fVelocity = m_fVelocity;
    info.m_pCharacterPhantom = m_pCharacterPhantom;
    info.m_fDynamicFriction = m_fDynamicFriction;
    info.m_fStaticFriction = m_fStaticFriction;
    info.m_fKeepContactTolerance = m_fKeepContactTolerance;
    info.m_vStart = m_vStart;
    info.m_fExtraUpStaticFriction = m_fExtraUpStaticFriction;
    info.m_fExtraDownStaticFriction = m_fExtraDownStaticFriction;
    info.m_fKeepDistance = m_fKeepDistance;
    info.m_fContactAngleSensitivity = m_fContactAngleSensitivity;
    info.m_uiUserPlanes = m_uiUserPlanes;
    info.m_fMaxCharacterSpeedForSolver = m_fMaxCharacterSpeedForSolver;
    info.m_fCharacterStrength = m_fCharacterStrength;
    info.m_fCharacterMass = m_fCharacterMass;
    info.m_fMaximumSlope = MathUtilities::acos(m_fMaximumSlopeAngle);
    info.m_fPenetrationRecoverySpeed = m_fPenetrationRecoverySpeed;
    info.m_iMaxCastIterations = m_iMaxCastIterations;
    info.m_bRefreshManifoldInCheckSupport = m_bRefreshManifoldInCheckSupport;
}

namespace sse_ca0c40 {
// Exe 0x00cacaa0 FUN_00cacaa0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ps(float* p, LocalM128 a);
}

struct CharProxy_ca0c40 {
    sse_ca0c40::LocalM128 unk000;
    sse_ca0c40::LocalM128 unk010;
    sse_ca0c40::LocalM128 unk020;
    sse_ca0c40::LocalM128 unk030;
    sse_ca0c40::LocalM128 unk040;
    sse_ca0c40::LocalM128 unk050;
    sse_ca0c40::LocalM128 unk060;
    sse_ca0c40::LocalM128 unk070;
    sse_ca0c40::LocalM128 unk080;
    sse_ca0c40::LocalM128 unk090;
    sse_ca0c40::LocalM128 unk0a0;
    sse_ca0c40::LocalM128 unk0b0;
    sse_ca0c40::LocalM128 unk0c0;
    sse_ca0c40::LocalM128 unk0d0;
    sse_ca0c40::LocalM128 unk0e0;
    sse_ca0c40::LocalM128 unk0f0;
    sse_ca0c40::LocalM128 unk100;
    sse_ca0c40::LocalM128 unk110;
    sse_ca0c40::LocalM128 unk120;
    sse_ca0c40::LocalM128 unk130;
    sse_ca0c40::LocalM128 m_140;
    sse_ca0c40::LocalM128 unk150;
    sse_ca0c40::LocalM128 unk160;
    sse_ca0c40::LocalM128 unk170;
    sse_ca0c40::LocalM128 unk180;
    sse_ca0c40::LocalM128 unk190;
    sse_ca0c40::LocalM128 unk1a0;
    sse_ca0c40::LocalM128 m_1b0;
    sse_ca0c40::LocalM128 m_1c0;

    sse_ca0c40::LocalM128* hkpRigidBody_getPointVelocity(const sse_ca0c40::LocalM128* a, sse_ca0c40::LocalM128* out);
};

// Stores m_1b0 plus the cross product of m_1c0 with (*a - m_140) in out and returns out.
// @fnv 0x00ca0c40
// src: XBOX_PDB 0x00ca0c40
sse_ca0c40::LocalM128* CharProxy_ca0c40::hkpRigidBody_getPointVelocity(const sse_ca0c40::LocalM128* a, sse_ca0c40::LocalM128* out) {
    sse_ca0c40::LocalM128 d = sse_ca0c40::_mm_sub_ps(*a, m_140);
    sse_ca0c40::LocalM128 b = m_1c0;
    sse_ca0c40::LocalM128 t1 = sse_ca0c40::_mm_mul_ps(sse_ca0c40::_mm_shuffle_ps(b, b, 0xc9), sse_ca0c40::_mm_shuffle_ps(d, d, 0xd2));
    sse_ca0c40::LocalM128 vTerm2 = sse_ca0c40::_mm_mul_ps(sse_ca0c40::_mm_shuffle_ps(b, b, 0xd2), sse_ca0c40::_mm_shuffle_ps(d, d, 0xc9));
    sse_ca0c40::LocalM128 c;
    c = sse_ca0c40::_mm_sub_ps(t1, vTerm2);
    sse_ca0c40::_mm_store_ps((float*)out, c);
    sse_ca0c40::_mm_store_ps((float*)out, sse_ca0c40::_mm_add_ps(m_1b0, c));
    return out;
}

struct S00cae900_Listeners { void hkpCharacterProxy_fireConstraintsProcessed(void*, void*); };
static const float DAT_010c851c = -0.08f;
extern const LocalM128 DAT_01017d10;
typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
LocalM128 _mm_and_ps(LocalM128, LocalM128);
LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
int _mm_movemask_ps(LocalM128);
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_setr_ps(float, float, float, float);
}
extern DWORD DAT_0126835c;
typedef LocalM128 S00cae900_Quad;
typedef float S00cae900_Real;


class S00cae900_SimdReal {
public:
    S00cae900_SimdReal(const LocalM128& x) : m_vValue(x) {}
    S00cae900_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    operator float() const { float s; _mm_store_ss(&s,m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
private:
    LocalM128 m_vValue;
};
static __forceinline S00cae900_SimdReal S00cae900_dot3(const hkVector4& v,const hkVector4& a) {
    LocalM128 x2 = _mm_mul_ps(v.m_vComponents,a.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
    return _mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xy);
}
typedef const S00cae900_SimdReal& S00cae900_SimdParam;

class S00cae900_Comparison {
public:
    enum Mask { MASK_XYZ = 7 };
    __forceinline int allAreSet(Mask m) const { return (_mm_movemask_ps(m_uiMask) & m) == m; }
    S00cae900_Quad m_uiMask;
};

// hkVector4


// hkBool
class S00cae900_Bool {
public:
    __forceinline S00cae900_Bool() {}
    __forceinline S00cae900_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    __forceinline void operator=(bool b) { m_cBooleanValue = static_cast<char>(b); }
    char m_cBooleanValue;
};

struct S00cae900_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE>
    __forceinline void _bufFree(void* p, int numElem) {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
__forceinline void* S00cae900_addByteOffset(void* base, int offset) { return reinterpret_cast<char*>(base) + offset; }
class S00cae900_Stack {
public:
    __forceinline void* allocateStack(int numBytes, const char* what) {
        void* current = m_next;
        m_next = S00cae900_addByteOffset(current, numBytes);
        return current;
    }
    __forceinline void* allocateStackRoundSizeTo128(int numBytes, const char* what) {
        int allocationSize = (numBytes + 127) & ~127;
        return allocateStack(allocationSize, what);
    }
    __forceinline void deallocateStack(void* p) { m_next = p; }
    void* m_next;
    int unk04;
    int unk08;
    int unk0c;
};
__forceinline hkMemoryRouter& S00cae900_getRouter() { return *reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance()); }

template <typename T>
__forceinline T* S00cae900_allocateStack(int n, const char* what = 0) {
    hkMemoryRouter& mem = S00cae900_getRouter();
    return static_cast<T*>(reinterpret_cast<S00cae900_Stack*>(&mem.m_stack.m_next.m_storage)->allocateStack((n * sizeof(T) + 127) & ~127, what));
}
template <typename T>
__forceinline void S00cae900_deallocateStack(T* ptr) { reinterpret_cast<S00cae900_Stack*>(&S00cae900_getRouter().m_stack.m_next.m_storage)->deallocateStack(static_cast<void*>(ptr)); }

// The router getter here goes through a forceinline heap accessor over a one-pointer holder (the original's
// inlining shape for this unit).
struct S00cae900_HeapHolder { hkMemoryAllocator* value; };
__forceinline hkMemoryAllocator& S00cae900_getHeap(hkMemoryRouter& r) { return *reinterpret_cast<S00cae900_HeapHolder*>(&r.m_heap)->value; }
struct S00cae900_HeapAllocator {
    __forceinline S00cae900_Alloc& get(const void*) { return reinterpret_cast<S00cae900_Alloc&>(S00cae900_getHeap(S00cae900_getRouter())); }
};
template <bool N> struct S00cae900_TraitBool { typedef S00cae900_TraitBool<N> type; };
typedef S00cae900_TraitBool<true> S00cae900_TypeIsPod;
typedef S00cae900_TraitBool<false> S00cae900_TypeIsClass;
template <typename T> struct S00cae900_IsPodType : public S00cae900_TraitBool<false> {};
template <> struct S00cae900_IsPodType<hkVector4> : public S00cae900_TraitBool<true> {};
struct S00cae900_PlacementNewArg;
inline void* operator new(unsigned int, S00cae900_PlacementNewArg* p) { return p; }
template <typename T> __forceinline void S00cae900_construct(T* t, int n, S00cae900_TypeIsPod) {}
template <typename T> __forceinline void S00cae900_construct(T* t, int n, S00cae900_TypeIsClass) {
    for (int i = 0; i < n; ++i) {
        ::new (reinterpret_cast<S00cae900_PlacementNewArg*>(t + i)) T;
    }
}
template <typename T> __forceinline void S00cae900_destruct(T* t, int n, S00cae900_TypeIsPod) {}
template <typename T> __forceinline void S00cae900_destruct(T* t, int n, S00cae900_TypeIsClass) {
    for (int i = 0; i < n; ++i) {
        static_cast<T*>(t)[i].~T();
    }
}

struct S00cae900_ArrRaw;
extern "C" void __cdecl ResizeAudioStream(S00cae900_Alloc& alloc, S00cae900_ArrRaw* arr, int elemSize);
extern "C" void __cdecl hkArrayUtil__reserve(S00cae900_Alloc& alloc, S00cae900_ArrRaw* arr, int newCap, int elemSize);

template <typename T>
// local form of hkArrayBase: 0x00cae900 needs local construction and helper inlining; the shared form changes extent from 1738 to 1768 bytes.
class S00cae900_ArrayBase {
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    __forceinline S00cae900_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG) {}
    __forceinline void destroyBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & CAPACITY_MASK; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline void _clearAndDeallocate(S00cae900_Alloc& alloc) {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void clear() {
        S00cae900_destruct(m_data, m_iElementCount, typename S00cae900_IsPodType<T>::type());
        m_iElementCount = 0;
    }
    __forceinline void setSizeUnchecked(int n) {
        S00cae900_destruct(m_data + n, m_iElementCount - n, typename S00cae900_IsPodType<T>::type());
        S00cae900_construct(m_data + m_iElementCount, n - m_iElementCount, typename S00cae900_IsPodType<T>::type());
        m_iElementCount = n;
    }
    __forceinline void GrowArrayCapacity(S00cae900_Alloc& alloc, int n) {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, reinterpret_cast<S00cae900_ArrRaw*>(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S00cae900_Alloc& alloc, int n) {
        GrowArrayCapacity(alloc, n);
        S00cae900_destruct(m_data + n, m_iElementCount - n, typename S00cae900_IsPodType<T>::type());
        S00cae900_construct(m_data + m_iElementCount, n - m_iElementCount, typename S00cae900_IsPodType<T>::type());
        m_iElementCount = n;
    }
    __forceinline T& _expandOne(S00cae900_Alloc& alloc) {
        if (m_iElementCount == getCapacity()) {
            ResizeAudioStream(alloc, reinterpret_cast<S00cae900_ArrRaw*>(this), sizeof(T));
        }
        S00cae900_construct(m_data + m_iElementCount, 1, typename S00cae900_IsPodType<T>::type());
        return m_data[m_iElementCount++];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
class S00cae900_Array : public S00cae900_ArrayBase<T> {
public:
    __forceinline S00cae900_Array() {}
    __forceinline void reserve(int n) { this->GrowArrayCapacity(S00cae900_HeapAllocator().get(this), n); }
    __forceinline void SetSizeAndGrow(int n) { this->_setSize(S00cae900_HeapAllocator().get(this), n); }
    __forceinline T& AllocatePair() { return this->_expandOne(S00cae900_HeapAllocator().get(this)); }
    __forceinline void ClearAndRelease() { this->_clearAndDeallocate(S00cae900_HeapAllocator().get(this)); }
    __forceinline void destroyArray() {
        ClearAndRelease();
        this->destroyBase();
    }
};

template <typename T>
class S00cae900_LocalArray : public S00cae900_Array<T> {
public:
    __forceinline S00cae900_LocalArray(int capacity) {
        this->m_data = S00cae900_allocateStack<T>(capacity);
        this->m_iCapacityState = capacity | S00cae900_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline S00cae900_Bool wasReallocated() const { return m_pStackAllocation != this->m_data; }
    __forceinline void destruct() {
        if (!wasReallocated()) {
            this->clear();
        }
        S00cae900_deallocateStack<T>(m_pStackAllocation);
        this->destroyArray();
    }
    T* m_pStackAllocation;
};

struct S00cae900_ConstraintInfo {
    hkVector4 m_kTriangleNormal;
    hkVector4 m_fVelocity;
    float m_fStaticFriction;
    float m_fExtraUpStaticFriction;
    float m_fExtraDownStaticFriction;
    float m_fDynamicFriction;
    int m_priority;
};
struct S00cae900_Interaction {
    unsigned char m_ucByte0;
    unsigned char m_ucByte1;
    float m_fValue0;
    float m_fValue1;
    int m_iResultCode;
};
struct S00cae900_SolverInput {
    __forceinline S00cae900_SolverInput() {
        m_vFourthInputVector.set(0, 1, 0);
        m_vThirdInputVector.setAll3(1.192092896e-07f);
        m_vContactPosition.setZero4();
    }
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    hkVector4 m_vThirdInputVector;
    hkVector4 m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    S00cae900_ConstraintInfo* m_ppConstraints;
    int m_iConstraintCount;
};
struct S00cae900_SolverOutput {
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    float m_fTimeStep;
    S00cae900_Interaction* m_pPlaneStatuses;
};
// hkpSurfaceInfo
struct S00cae900_SurfaceInfo {
    enum SupportedState { UNSUPPORTED = 0, SLIDING = 1, SUPPORTED = 2 };
    SupportedState m_eSupportedState;
    hkVector4 m_vNormal;
    hkVector4 m_vSurfaceVelocity;
    float m_fSurfaceDistance;
};
class S00cae900_Collector;
struct S00cae900_RootPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 r20;
    hkVector4 r30;
    hkVector4 r40;
    hkVector4 r50;
    hkVector4 r60;
};

extern "C" void __cdecl hkSimplexSolverSolve(const S00cae900_SolverInput& input, S00cae900_SolverOutput& output);



// src: XBOX_PDB 0x00cadca0
static bool addMaxSlopePlane(float maxSlopeCos, const hkVector4& up, int index, S00cae900_Array<S00cae900_ConstraintInfo>& surfaceConstraintsInOut)
{
    const float surfaceVerticalComponent = S00cae900_dot3(surfaceConstraintsInOut[index].m_kTriangleNormal, up);
    if (surfaceVerticalComponent > 0.01f && surfaceVerticalComponent < maxSlopeCos)
    {
        S00cae900_ConstraintInfo& newConstraint = surfaceConstraintsInOut.AllocatePair();
        newConstraint = surfaceConstraintsInOut[index];
        newConstraint.m_kTriangleNormal.addMul4(-surfaceVerticalComponent, up);
        newConstraint.m_kTriangleNormal.normalize3();
        return true;
    }
    return false;
}

class S00cae900_PadPtr {
public:
    __forceinline void operator=(char* e) { m_kStorage = e; }
    __forceinline char* val() const { return m_kStorage; }
    char* m_kStorage;
};
__forceinline void hkMonitorStream::TimerCommand::setTime() {
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_time0 = ticks;
}

class S00cae900_Monitor {
public:
    static __forceinline S00cae900_Monitor& GetMonitorStream() { return *static_cast<S00cae900_Monitor*>(TlsGetValue(DAT_0126835c)); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S00cae900_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
    S00cae900_PadPtr m_kRayStart;
    S00cae900_PadPtr m_kRayEnd;
    S00cae900_PadPtr m_pRayCursor;
    S00cae900_PadPtr m_pCurrentCommand;
};
__forceinline void S00cae900_timer(const char* name) {
    S00cae900_Monitor& mStream = S00cae900_Monitor::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.GetStreamEnd());
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}

// hkpCharacterProxy
class S00cae900_Proxy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void GetSurfaceConstraintInfo(const S00cae900_RootPoint& hit, S00cae900_ConstraintInfo& surface, float timeTravelled) const;
    hkVector4 m_fVelocity;
    hkVector4 m_vCurrentPosition;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_vStart;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int m_uiUserPlanes;
    float m_fMaxCharacterSpeedForSolver;
    int unk6c;
    int unk70;
    S00cae900_Array<S00cae900_RootPoint> m_kContactManifold;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    float m_fMaximumSlopeAngle;
    int unka8;
    int unkac;
    bool m_bRefreshManifoldInCheckSupport;
    void AllocateStorage_00cae7f0(S00cae900_Collector& collector);
    void ahkpCharacterProxy_checkSupportWithCollector(const hkVector4& direction, S00cae900_SurfaceInfo& ground, S00cae900_Collector& startPointCollector);
};

// @fnv 0x00cae900
// src: COMMUNITY 0x00cae900
void S00cae900_Proxy::ahkpCharacterProxy_checkSupportWithCollector(const hkVector4& direction, S00cae900_SurfaceInfo& ground, S00cae900_Collector& startPointCollector)
{
    S00cae900_timer("TtcheckSupport");
    if (m_bRefreshManifoldInCheckSupport)
    {
        AllocateStorage_00cae7f0(startPointCollector);
    }
    S00cae900_LocalArray<S00cae900_ConstraintInfo> surfaceConstraints(m_kContactManifold.GetLogicalSize() + m_uiUserPlanes + 10);
    surfaceConstraints.setSizeUnchecked(m_kContactManifold.GetLogicalSize());
    for (int i = 0; i < m_kContactManifold.GetLogicalSize(); i++)
    {
        S00cae900_RootPoint& hit = m_kContactManifold[i];
        S00cae900_ConstraintInfo& constraint = *reinterpret_cast<S00cae900_ConstraintInfo*>(i * sizeof(S00cae900_ConstraintInfo) + reinterpret_cast<size_t>(surfaceConstraints.begin()));
        GetSurfaceConstraintInfo(hit, constraint, 0.0f);
        addMaxSlopePlane(m_fMaximumSlopeAngle, m_vStart, i, surfaceConstraints);
    }
    if (surfaceConstraints.getCapacity() - surfaceConstraints.GetLogicalSize() < m_uiUserPlanes)
    {
        surfaceConstraints.reserve(surfaceConstraints.GetLogicalSize() + m_uiUserPlanes);
    }
    S00cae900_LocalArray<S00cae900_Interaction> surfaceConstraintInteractions(surfaceConstraints.GetLogicalSize() + m_uiUserPlanes);
    S00cae900_LocalArray<hkVector4> actualSurfaceVelocities(surfaceConstraints.GetLogicalSize() + m_uiUserPlanes);

    S00cae900_SolverInput input;
    S00cae900_SolverOutput output;
    input.m_vContactPosition.setZero4();
    input.m_ppConstraints = surfaceConstraints.begin();
    input.m_iConstraintCount = surfaceConstraints.GetLogicalSize();
    input.m_fVelocity = direction;
    input.m_fTimeStep = 1.0f / 60.0f;
    input.m_fConstraintParameter = 1.0f / 60.0f;
    input.m_vFourthInputVector = m_vStart;
    input.m_vThirdInputVector.SetAllComponents(m_fMaxCharacterSpeedForSolver);
    output.m_pPlaneStatuses = surfaceConstraintInteractions.begin();
    reinterpret_cast<S00cae900_Listeners*>(this)->hkpCharacterProxy_fireConstraintsProcessed(&m_kContactManifold, &input);

    actualSurfaceVelocities.SetSizeAndGrow(input.m_iConstraintCount);
    surfaceConstraintInteractions.SetSizeAndGrow(input.m_iConstraintCount);
    surfaceConstraints.SetSizeAndGrow(input.m_iConstraintCount);
    for (int j = 0; j < input.m_iConstraintCount; j++)
    {
        actualSurfaceVelocities[j] = surfaceConstraints[j].m_fVelocity;
        surfaceConstraints[j].m_fVelocity.setZero4();
    }
    hkSimplexSolverSolve(input, output);

    ground.m_vSurfaceVelocity.setZero4();
    ground.m_vNormal.setZero4();
    if (VectorEquals3(output.m_fVelocity, direction, 1e-3f))
    {
        ground.m_eSupportedState = S00cae900_SurfaceInfo::UNSUPPORTED;
    }
    else if (S00cae900_dot3(output.m_fVelocity, output.m_fVelocity) < 0.001f)
    {
        ground.m_eSupportedState = S00cae900_SurfaceInfo::SUPPORTED;
    }
    else
    {
        output.m_fVelocity.normalize3();
        const float angleSin = S00cae900_dot3(output.m_fVelocity, direction);
        float cosSqr = 1.0f - angleSin * angleSin;
        if (cosSqr < m_fMaximumSlopeAngle * m_fMaximumSlopeAngle)
        {
            ground.m_eSupportedState = S00cae900_SurfaceInfo::SLIDING;
        }
        else
        {
            ground.m_eSupportedState = S00cae900_SurfaceInfo::SUPPORTED;
        }
    }
    if (ground.m_eSupportedState != S00cae900_SurfaceInfo::UNSUPPORTED)
    {
        int numTouching = 0;
        for (int k = 0; k < input.m_iConstraintCount; k++)
        {
            if (surfaceConstraintInteractions[k].m_ucByte0 && S00cae900_dot3(surfaceConstraints[k].m_kTriangleNormal, direction) < DAT_010c851c)
            {
                ground.m_vNormal.add4(surfaceConstraints[k].m_kTriangleNormal);
                ground.m_vSurfaceVelocity.m_vComponents = _mm_add_ps(ground.m_vSurfaceVelocity.m_vComponents, actualSurfaceVelocities[k].m_vComponents);
                numTouching++;
            }
        }
        if (numTouching > 0)
        {
            ground.m_vNormal.normalize3();
            ground.m_vSurfaceVelocity.mul4(1.0f / numTouching);
        }
        else
        {
            ground.m_eSupportedState = S00cae900_SurfaceInfo::UNSUPPORTED;
        }
    }
    ground.m_fSurfaceDistance = 0.0f;
    S00cae900_timer("Et");
    actualSurfaceVelocities.destruct();
    surfaceConstraintInteractions.destruct();
    surfaceConstraints.destruct();
}

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
extern "C" {
LocalM128 _mm_set_ps1(float);
LocalM128 _mm_setr_ps(float, float, float, float);
}
extern DWORD DAT_0126835c;
static const float kInvSixtySV = 1.0f / 60.0f;
static const float kMinSurfaceDotSV = -0.08f;
typedef LocalM128 S00caefd0_Quad;
typedef float S00caefd0_Real;


class S00caefd0_SimdReal {
public:
    S00caefd0_SimdReal(const LocalM128& x) : m_vValue(x) {}
    S00caefd0_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    operator float() const { float s; _mm_store_ss(&s,m_vValue); return s; }
    __forceinline LocalM128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
    __forceinline const LocalM128& getQuad() const { return m_vValue; }
private:
    LocalM128 m_vValue;
};
static __forceinline S00caefd0_SimdReal S00caefd0_dot3(const hkVector4& v,const hkVector4& a) {
    LocalM128 x2 = _mm_mul_ps(v.m_vComponents,a.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
    return _mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),xy);
}
typedef const S00caefd0_SimdReal& S00caefd0_SimdParam;

// hkVector4


// hkBool
class S00caefd0_Bool {
public:
    __forceinline S00caefd0_Bool() {}
    __forceinline S00caefd0_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    __forceinline void operator=(bool b) { m_cBooleanValue = static_cast<char>(b); }
    char m_cBooleanValue;
};

struct S00caefd0_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename TYPE>
    __forceinline void _bufFree(void* p, int numElem) {
        const int SIZE_ELEM = sizeof(TYPE);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
__forceinline void* S00caefd0_addByteOffset(void* base, int offset) { return reinterpret_cast<char*>(base) + offset; }
class S00caefd0_Stack {
public:
    __forceinline void* allocateStack(int numBytes, const char* what) {
        void* current = m_next;
        m_next = S00caefd0_addByteOffset(current, numBytes);
        return current;
    }
    __forceinline void* allocateStackRoundSizeTo128(int numBytes, const char* what) {
        int allocationSize = (numBytes + 127) & ~127;
        return allocateStack(allocationSize, what);
    }
    __forceinline void deallocateStack(void* p) { m_next = p; }
    void* m_next;
    int unk04;
    int unk08;
    int unk0c;
};
__forceinline hkMemoryRouter& S00caefd0_getRouter() { return *reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance()); }

template <typename T>
__forceinline T* S00caefd0_allocateStack(int n, const char* what = 0) {
    hkMemoryRouter& mem = S00caefd0_getRouter();
    return static_cast<T*>(reinterpret_cast<S00caefd0_Stack*>(&mem.m_stack.m_next.m_storage)->allocateStack((n * sizeof(T) + 127) & ~127, what));
}
template <typename T>
__forceinline void S00caefd0_deallocateStack(T* ptr) { reinterpret_cast<S00caefd0_Stack*>(&S00caefd0_getRouter().m_stack.m_next.m_storage)->deallocateStack(static_cast<void*>(ptr)); }

struct S00caefd0_HeapAllocator {
    __forceinline S00caefd0_Alloc& get(const void*) { return reinterpret_cast<S00caefd0_Alloc&>(S00caefd0_getRouter().heap()); }
};
struct S00caefd0_PodTag {};
__forceinline void S00caefd0_construct(void*, int, S00caefd0_PodTag) {}
__forceinline void S00caefd0_destruct(void*, int, S00caefd0_PodTag) {}

struct S00caefd0_ArrRaw;
void __cdecl ResizeAudioStream(S00caefd0_Alloc& alloc, S00caefd0_ArrRaw* arr, int elemSize);
void __cdecl hkArrayUtil__reserve(S00caefd0_Alloc& alloc, S00caefd0_ArrRaw* arr, int newCap, int elemSize);

template <typename T>
// local form of hkArrayBase: 0x00caefd0 needs local construction and helper inlining; the shared form changes extent from 1266 to 1286 bytes.
class S00caefd0_ArrayBase {
public:
    enum { CAPACITY_MASK = 0x3fffffff, DONT_DEALLOCATE_FLAG = 0x80000000 };
    __forceinline S00caefd0_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG) {}
    __forceinline void destroyBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & CAPACITY_MASK; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T* begin() { return m_data; }
    __forceinline void _clearAndDeallocate(S00caefd0_Alloc& alloc) {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void clear() {
        S00caefd0_destruct(m_data, m_iElementCount, S00caefd0_PodTag());
        m_iElementCount = 0;
    }
    __forceinline void setSizeUnchecked(int n) {
        S00caefd0_destruct(m_data + n, m_iElementCount - n, S00caefd0_PodTag());
        S00caefd0_construct(m_data + m_iElementCount, n - m_iElementCount, S00caefd0_PodTag());
        m_iElementCount = n;
    }
    __forceinline void GrowArrayCapacity(S00caefd0_Alloc& alloc, int n) {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, reinterpret_cast<S00caefd0_ArrRaw*>(this), newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S00caefd0_Alloc& alloc, int n) {
        GrowArrayCapacity(alloc, n);
        S00caefd0_destruct(m_data + n, m_iElementCount - n, S00caefd0_PodTag());
        S00caefd0_construct(m_data + m_iElementCount, n - m_iElementCount, S00caefd0_PodTag());
        m_iElementCount = n;
    }
    __forceinline T& _expandOne(S00caefd0_Alloc& alloc) {
        if (m_iElementCount == getCapacity()) {
            ResizeAudioStream(alloc, reinterpret_cast<S00caefd0_ArrRaw*>(this), sizeof(T));
        }
        S00caefd0_construct(m_data + m_iElementCount, 1, S00caefd0_PodTag());
        return m_data[m_iElementCount++];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
class S00caefd0_Array : public S00caefd0_ArrayBase<T> {
public:
    __forceinline S00caefd0_Array() {}
    __forceinline void reserve(int n) { this->GrowArrayCapacity(S00caefd0_HeapAllocator().get(this), n); }
    __forceinline void SetSizeAndGrow(int n) { this->_setSize(S00caefd0_HeapAllocator().get(this), n); }
    __forceinline T& AllocatePair() { return this->_expandOne(S00caefd0_HeapAllocator().get(this)); }
    __forceinline void ClearAndRelease() { this->_clearAndDeallocate(S00caefd0_HeapAllocator().get(this)); }
    __forceinline void destroyArray() {
        ClearAndRelease();
        this->destroyBase();
    }
};

template <typename T>
class S00caefd0_LocalArray : public S00caefd0_Array<T> {
public:
    __forceinline S00caefd0_LocalArray(int capacity) {
        this->m_data = S00caefd0_allocateStack<T>(capacity);
        this->m_iCapacityState = capacity | S00caefd0_ArrayBase<T>::DONT_DEALLOCATE_FLAG;
        m_pStackAllocation = this->m_data;
    }
    __forceinline S00caefd0_Bool wasReallocated() const { return m_pStackAllocation != this->m_data; }
    __forceinline void destruct() {
        if (!wasReallocated()) {
            this->clear();
        }
        S00caefd0_deallocateStack<T>(m_pStackAllocation);
        this->destroyArray();
    }
    T* m_pStackAllocation;
};

struct S00caefd0_ConstraintInfo {
    hkVector4 m_kTriangleNormal;
    hkVector4 m_fVelocity;
    float m_fStaticFriction;
    float m_fExtraUpStaticFriction;
    float m_fExtraDownStaticFriction;
    float m_fDynamicFriction;
    int m_priority;
};
struct S00caefd0_Interaction {
    unsigned char m_ucByte0;
    unsigned char m_ucByte1;
    float m_fValue0;
    float m_fValue1;
    int m_iResultCode;
};
struct S00caefd0_SolverInput {
    __forceinline S00caefd0_SolverInput() {
        m_vFourthInputVector.set(0, 1, 0);
        m_vThirdInputVector.setAll3(1.192092896e-07f);
        m_vContactPosition.setZero4();
    }
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    hkVector4 m_vThirdInputVector;
    hkVector4 m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    S00caefd0_ConstraintInfo* m_ppConstraints;
    int m_iConstraintCount;
};
struct S00caefd0_SolverOutput {
    hkVector4 m_vContactPosition;
    hkVector4 m_fVelocity;
    float m_fTimeStep;
    S00caefd0_Interaction* m_pPlaneStatuses;
};
struct S00caefd0_SurfaceInfo {
    S00caefd0_Bool m_bSliding;
    S00caefd0_Bool m_bSupported;
    hkVector4 m_vNormal;
    hkVector4 m_vSurfaceVelocity;
};
struct S00caefd0_RootPoint {
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 r20;
    hkVector4 r30;
    hkVector4 r40;
    hkVector4 r50;
    hkVector4 r60;
};

void __cdecl hkSimplexSolverSolve(const S00caefd0_SolverInput& input, S00caefd0_SolverOutput& output);



// src: XBOX_PDB 0x00cadca0
static bool addMaxSlopePlane(float maxSlopeCos, const hkVector4& up, int index, S00caefd0_Array<S00caefd0_ConstraintInfo>& surfaceConstraintsInOut)
{
    const float surfaceVerticalComponent = S00caefd0_dot3(surfaceConstraintsInOut[index].m_kTriangleNormal, up);
    if (surfaceVerticalComponent > 0.01f && surfaceVerticalComponent < maxSlopeCos)
    {
        S00caefd0_ConstraintInfo& newConstraint = surfaceConstraintsInOut.AllocatePair();
        newConstraint = surfaceConstraintsInOut[index];
        newConstraint.m_kTriangleNormal.addMul4(-surfaceVerticalComponent, up);
        newConstraint.m_kTriangleNormal.normalize3();
        return true;
    }
    return false;
}

class S00caefd0_PadPtr {
public:
    __forceinline void operator=(char* e) { m_kStorage = e; }
    __forceinline char* val() const { return m_kStorage; }
    char* m_kStorage;
};
class S00caefd0_Monitor {
public:
    static __forceinline S00caefd0_Monitor& GetMonitorStream() { return *static_cast<S00caefd0_Monitor*>(TlsGetValue(DAT_0126835c)); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline S00caefd0_Bool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
    S00caefd0_PadPtr m_kRayStart;
    S00caefd0_PadPtr m_kRayEnd;
    S00caefd0_PadPtr m_pRayCursor;
    S00caefd0_PadPtr m_pCurrentCommand;
};
__forceinline void S00caefd0_timer(const char* name) {
    S00caefd0_Monitor& mStream = S00caefd0_Monitor::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.GetStreamEnd());
        h->m_commandAndMonitor = name;
        h->setTime();
        mStream.setEnd(reinterpret_cast<char*>(h + 1));
    }
}

// hkpCharacterProxy
class S00caefd0_Proxy {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void GetSurfaceConstraintInfo(const S00caefd0_RootPoint& hit, S00caefd0_ConstraintInfo& surface, float timeTravelled) const;
    hkVector4 m_fVelocity;
    hkVector4 m_vCurrentPosition;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_vStart;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int m_uiUserPlanes;
    float m_fMaxCharacterSpeedForSolver;
    int unk6c;
    int unk70;
    S00caefd0_Array<S00caefd0_RootPoint> m_kContactManifold;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    float m_fMaximumSlopeAngle;
    void hkpCharacterProxy_fireConstraintsProcessed(void* manifold, void* input);
    void ProcessEntries_00caefd0(const hkVector4& direction, S00caefd0_SurfaceInfo& ground) const;
};

// @fnv 0x00caefd0
// src: GUESS 0x00caefd0 (confidence: low)
void S00caefd0_Proxy::ProcessEntries_00caefd0(const hkVector4& direction, S00caefd0_SurfaceInfo& ground) const
{
    S00caefd0_timer("TtcheckSupport");
    S00caefd0_LocalArray<S00caefd0_ConstraintInfo> surfaceConstraints(m_kContactManifold.GetLogicalSize() + m_uiUserPlanes + 10);
    surfaceConstraints.setSizeUnchecked(m_kContactManifold.GetLogicalSize());
    for (int i = 0; i < m_kContactManifold.GetLogicalSize(); i++)
    {
        GetSurfaceConstraintInfo(m_kContactManifold[i], surfaceConstraints[i], 0.0f);
        addMaxSlopePlane(m_fMaximumSlopeAngle, m_vStart, i, surfaceConstraints);
    }
    if (surfaceConstraints.getCapacity() - surfaceConstraints.GetLogicalSize() < m_uiUserPlanes)
    {
        surfaceConstraints.reserve(surfaceConstraints.GetLogicalSize() + m_uiUserPlanes);
    }
    S00caefd0_LocalArray<S00caefd0_Interaction> surfaceConstraintInteractions(surfaceConstraints.GetLogicalSize() + m_uiUserPlanes);
    surfaceConstraintInteractions.SetSizeAndGrow(surfaceConstraints.GetLogicalSize() + m_uiUserPlanes);

    S00caefd0_SolverInput input;
    S00caefd0_SolverOutput output;
    input.m_vContactPosition.setZero4();
    input.m_ppConstraints = surfaceConstraints.begin();
    input.m_iConstraintCount = m_kContactManifold.GetLogicalSize();
    input.m_fVelocity.setAdd4(m_fVelocity, direction);
    input.m_fTimeStep = kInvSixtySV;
    input.m_fConstraintParameter = kInvSixtySV;
    input.m_vFourthInputVector = m_vStart;
    input.m_vThirdInputVector.SetAllComponents(m_fMaxCharacterSpeedForSolver);
    output.m_pPlaneStatuses = surfaceConstraintInteractions.begin();
    const_cast<S00caefd0_Proxy*>(this)->hkpCharacterProxy_fireConstraintsProcessed(const_cast<S00caefd0_Array<S00caefd0_RootPoint>*>(&m_kContactManifold), &input);
    hkSimplexSolverSolve(input, output);

    output.m_fVelocity.sub4(m_fVelocity);
    const float projectedVelocity = S00caefd0_dot3(output.m_fVelocity, direction);
    ground.m_bSliding = projectedVelocity < 0.99f;
    hkVector4 outputSlidingVelocity;
    outputSlidingVelocity.setAddMul4(output.m_fVelocity, direction, -projectedVelocity);
    ground.m_bSupported = S00caefd0_dot3(outputSlidingVelocity, outputSlidingVelocity) > 0.01f;
    ground.m_vSurfaceVelocity.setZero4();
    ground.m_vNormal.setZero4();
    int numTouching = 0;
    for (int j = 0; j < input.m_iConstraintCount; j++)
    {
        if (surfaceConstraintInteractions[j].m_ucByte0 && S00caefd0_dot3(surfaceConstraints[j].m_kTriangleNormal, direction) < kMinSurfaceDotSV)
        {
            ground.m_vNormal.add4(surfaceConstraints[j].m_kTriangleNormal);
            ground.m_vSurfaceVelocity.add4(surfaceConstraints[j].m_fVelocity);
            numTouching++;
        }
    }
    if (numTouching > 0)
    {
        ground.m_vNormal.normalize3();
        ground.m_vSurfaceVelocity.mul4(1.0f / numTouching);
    }
    else
    {
        ground.m_bSliding = false;
    }
    S00caefd0_timer("Et");
    surfaceConstraintInteractions.destruct();
    surfaceConstraints.destruct();
}
