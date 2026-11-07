
// src/havok/physics/collide/shape/compound/collection/hkpshapecollection_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/compound/collection/hkpshapecollection.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/compound/collection/hkpshapecollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/hkpshapecollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpShapeCollection.h"
class hkNiTriStripsShape;
class hkpListShape;
class hkpShapeCollection_L
{
  public:
    virtual ~hkpShapeCollection_L();
    virtual int hkpShapeCollection_getContainer();
};
extern char const* const DAT_01268910;
void __cdecl hkReferencedObject_calcContentStatistics(char const* const* first, char const* const* second);
void __cdecl hkpShapeCollection_calcContentStatistics(char const* const* first, char const* const* ignored);
void __stdcall nullsub_53(int, int);
void __stdcall nullsub_52(int a1);
struct Allocator
{
    virtual void vfn0();
    virtual void vfn4();
    virtual void Free(void* pointer, unsigned short size);
};
struct MemorySystem
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    Allocator* allocator;
};
extern char DAT_010c6fb0;
extern char DAT_0102e388;
struct Holder
{
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    unsigned int userData;
    unsigned int shapeType;
    void* shapeVtable;
    MemorySystem* __thiscall hkMemoryRouter_getInstance();
    Holder* __thiscall Destroy(unsigned char flags);
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;
struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet()
    {}
    hkBoolRet(char b) : m_cBooleanValue(b)
    {}
};
struct ShapeRayCastQuery
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
    const hkpRayShapeCollectionFilter* m_pRayShapeCollectionFilter;
};
struct ShapeRayCastOutput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkpShapeKey m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern float DAT_0104e148;
extern const char str_010ce228[];
extern const char str_010c41f8[];
class ShapeIterator
{
  public:
    virtual ~ShapeIterator();
    virtual void Unk04();
    virtual int First();
    virtual int Next(int idx);
    virtual void Unk10();
    virtual class hkShape_StandIn* GetShape(int idx, float* outBuf);
};
class hkShape_StandIn : public hkpShape
{
  public:
    virtual ~hkShape_StandIn();
    virtual void Unk04();
    virtual void Unk08();
    virtual float GetMaxProjection(int arg);
};
// sub ecx,0x10; jmp Destroy == MSVC adjustor thunk: Derived overrides a virtual that both
// bases declare; the second base's vtable gets a thunk that moves `this` back by sizeof(PrimaryBase) = 0x10.
struct PrimaryBase
{
    virtual void FUN_00cf57d0();
    int unk04;
    int unk08;
    int unk0C;
};
struct SecondaryBase
{
    virtual void FUN_00cf57d0();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cf57d0
    virtual void FUN_00cf57d0();
};
Derived::Derived()
{}

#include <xmmintrin.h>
struct Aabb
{
    __m128 minimum, maximum;
};
extern char DAT_010ce208;
extern char DAT_010c41f8;
class CollectionAabb : public hkpShapeCollection
{
  public:
    void hkpShapeCollection_getAabb(const hkTransform& transform, float tolerance, Aabb& out) const;
};
// @fnv 0x00d215d0
// src: EXE 0x00d215d0
void CollectionAabb::hkpShapeCollection_getAabb(const hkTransform& transform, float tolerance, Aabb& out) const
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* event = stream->m_end.m_storage;
    if (event < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)event = &DAT_010ce208;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        *(unsigned int*)(event + 4) = stamp;
        stream->m_end.m_storage = event + 12;
    }
    out.minimum = _mm_set1_ps(3.40282e38f);
    out.maximum = _mm_set1_ps(-3.40282e38f);
    hkpShapeKey key = GetFirstKey();
    while (key != (hkpShapeKey)-1)
    {
        __declspec(align(16)) char buffer[512];
        Aabb child;
        const hkpShape* shape = GetShapeForKey(key, reinterpret_cast<hkpShapeBuffer&>(buffer));
        shape->CalculateAabb(transform, tolerance, reinterpret_cast<hkAabb&>(child));
        out.minimum = _mm_min_ps(out.minimum, child.minimum);
        out.maximum = _mm_max_ps(out.maximum, child.maximum);
        key = GetNextShapeKey(key);
    }
    stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    event = stream->m_end.m_storage;
    if (event < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)event = &DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        *(unsigned int*)(event + 4) = stamp;
        stream->m_end.m_storage = event + 12;
    }
}
