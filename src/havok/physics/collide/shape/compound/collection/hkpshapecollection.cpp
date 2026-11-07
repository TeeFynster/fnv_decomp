
// src/havok/physics/collide/shape/compound/collection/hkpshapecollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/hkpshapecollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpShapeCollection.h"

// These constructors retain the original unit's uninitialized base storage.
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum() {}
inline hkpShape::hkpShape(hkpShapeType) {}

class hkpShapeCollection_L
{
  public:
    virtual ~hkpShapeCollection_L();
    virtual int hkpShapeCollection_getContainer();
};

// @fnv 0x00d213d0
// src: HAVOK_LIB 0x00d213d0
int hkpShapeCollection_L::hkpShapeCollection_getContainer()
{
    if (this != 0)
    {
        return reinterpret_cast<int>(this) + 0x10;
    }
    return 0;
}

extern char const* const DAT_01268910;
void __cdecl hkReferencedObject_calcContentStatistics(char const* const* first, char const* const* second);
// @fnv 0x00d213e0
// src: XBOX_PDB 0x00d213e0
void __cdecl hkpShapeCollection_calcContentStatistics(char const* const* first, char const* const* ignored)
{
    hkReferencedObject_calcContentStatistics(first, &DAT_01268910);
}

// @fnv 0x00d213f0
// src: COMMUNITY 0x00d213f0
void __stdcall nullsub_53(int, int)
{}

// @fnv 0x00d21400
// src: COMMUNITY 0x00d21400
void __stdcall nullsub_52(int a1)
{}

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
// Sets shapeVtable and vtable, then frees the object via the memory system allocator if the low bit of flags is set.
// @fnv 0x00cf57e0
Holder* __thiscall Holder::Destroy(unsigned char flags)
{
    shapeVtable = &DAT_010c6fb0;
    vtable = &DAT_0102e388;
    if ((flags & 1) != 0)
    {
        MemorySystem* memory = hkMemoryRouter_getInstance();
        memory->allocator->Free(this, memSizeAndFlags);
    }
    return this;
}

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

class FUN_00d21450_Class : public hkpShapeCollection
{
  public:
    hkBoolRet hkpShapeCollection_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
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

// Casts a ray against each filtered child and stores the last hit shape key in output.m_uiShapeKeys.
// @fnv 0x00d21450
// src: HAVOK_LIB 0x00d21450
hkBoolRet FUN_00d21450_Class::hkpShapeCollection_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    volatile unsigned int time;
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* current = stream->m_end.m_storage;
    if (current < stream->m_capacityMinus16.val())
    {
        *(const char**)current = "TtrcShpCollect";
        _ReadWriteBarrier();
        time = (unsigned int)__rdtsc();
        *(unsigned int*)(current + 4) = time;
        current += 12;
        stream->m_end.m_storage = current;
    }
    output.m_uiShapeKeyIndex++;
    const hkpShapeContainer* container =
        reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape));
    hkpShapeKey uiHitKey = 0xffffffff;
    __declspec(align(16)) hkUlong buffer[512 / sizeof(hkUlong)];
    hkBool hitResult;
    if (input.m_pRayShapeCollectionFilter == 0)
    {
        hkpShapeKey key = container->GetFirstKey();
        while (key != 0xffffffff)
        {
            const hkpShape* child = container->GetShapeForKey(key, *reinterpret_cast<hkpShapeBuffer*>(buffer));
            hitResult.hkBool::hkBool(child->IntersectRayWithShape(input, output));
            if (hitResult.m_cBooleanValue)
                uiHitKey = key;
            key = container->GetNextShapeKey(key);
        }
    }
    else
    {
        hkpShapeKey key = container->GetFirstKey();
        while (key != 0xffffffff)
        {
            if (input.m_pRayShapeCollectionFilter->IsCollisionEnabled(input, *this, *container, key).m_cBooleanValue)
            {
                const hkpShape* child = container->GetShapeForKey(key, *reinterpret_cast<hkpShapeBuffer*>(buffer));
                hitResult.hkBool::hkBool(child->IntersectRayWithShape(input, output));
                if (hitResult.m_cBooleanValue)
                    uiHitKey = key;
            }
            key = container->GetNextShapeKey(key);
        }
    }

    output.m_uiShapeKeyIndex--;
    if (uiHitKey != 0xffffffff)
    {
        output.m_uiShapeKeys[output.m_uiShapeKeyIndex] = uiHitKey;
    }
    hkMonitorStream* streamEnd = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* currentEnd = streamEnd->m_end.m_storage;
    if (currentEnd < streamEnd->m_capacityMinus16.val())
    {
        *(const char**)currentEnd = "Et";
        _ReadWriteBarrier();
        time = (unsigned int)__rdtsc();
        *(unsigned int*)(currentEnd + 4) = time;
        currentEnd += 12;
        streamEnd->m_end.m_storage = currentEnd;
    }
    return hkBoolRet(uiHitKey != 0xffffffff);
}

namespace fnv_00d217d0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwIndex);

extern "C" unsigned int DAT_0126835c;
extern "C" char str_010ce1f8[];
extern "C" char str_010c41f8[];

class Arg0_L;
class Arg1_L;
class Arg2_L;
struct ShapeBuf_L;
struct Ctx_L;
class Owner_L;

class Shape_L
{
  public:
    virtual ~Shape_L();
    virtual int s01();
    virtual int s02();
    virtual int s03();
    virtual int s04();
    virtual int s05();
    virtual int s06();
    virtual int s07();
    virtual int s08();
    virtual void process_L(Arg0_L* arg0, Ctx_L* ctx, Arg2_L* arg2);
};

class Arg0_L
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    const hkpRayShapeCollectionFilter* m_iFilter;
};

class Arg1_L
{
  public:
    void* unk00;
    void* unk04;
    int unk08;
};
class Arg2_L
{
  public:
    int dummy;
};

struct Ctx_L
{
    Shape_L* shape;
    int key;
    int unk08;
    Arg1_L* arg1;
};

struct __declspec(align(16)) ShapeBuf_L
{
    unsigned int data[128];
};

class Owner_L : public hkpShapeCollection
{
  public:
    void hkpShapeCollection_castRayWithCollectorImpl(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2);
};

// @fnv 0x00d217d0
// src: HAVOK_LIB 0x00d217d0
void Owner_L::hkpShapeCollection_castRayWithCollectorImpl(Arg0_L* arg0, Arg1_L* arg1, Arg2_L* arg2)
{
    volatile unsigned int uiTimestamp;
    hkMonitorStream* pProfSlot = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* pProfRec =
        reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfSlot->m_end.val());
    if (reinterpret_cast<char*>(pProfRec) < pProfSlot->m_capacityMinus16.val())
    {
        pProfRec->m_commandAndMonitor = str_010ce1f8;
        _ReadWriteBarrier();
        uiTimestamp = (unsigned int)__rdtsc();
        pProfRec->m_time0 = uiTimestamp;
        pProfSlot->m_end.m_storage = reinterpret_cast<char*>(pProfRec + 1);
    }
    ShapeBuf_L buffer;
    Ctx_L ctx;
    int key;
    if (arg0->m_iFilter == 0)
    {
        key = (reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape)))->GetFirstKey();
        if (key != -1)
        {
            do
            {
                ctx.shape = reinterpret_cast<Shape_L*>(const_cast<hkpShape*>((reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape)))->GetShapeForKey(key, reinterpret_cast<hkpShapeBuffer&>(buffer))));
                ctx.arg1 = arg1;
                ctx.unk08 = arg1->unk08;
                ctx.key = key;
                ctx.shape->process_L(arg0, &ctx, arg2);
                key = (reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape)))->GetNextShapeKey(key);
            } while (key != -1);
        }
    }
    else
    {
        key = (reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape)))->GetFirstKey();
        if (key != -1)
        {
            do
            {
                if (arg0->m_iFilter->IsCollisionEnabled(*reinterpret_cast<const ShapeRayCastQuery*>(arg0), *this, *(reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape))), key).m_cBooleanValue)
                {
                    ctx.shape = reinterpret_cast<Shape_L*>(const_cast<hkpShape*>((reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape)))->GetShapeForKey(key, reinterpret_cast<hkpShapeBuffer&>(buffer))));
                    ctx.arg1 = arg1;
                    ctx.unk08 = arg1->unk08;
                    ctx.key = key;
                    ctx.shape->process_L(arg0, &ctx, arg2);
                }
                key = (reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape)))->GetNextShapeKey(key);
            } while (key != -1);
        }
    }
    pProfSlot = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    pProfRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfSlot->m_end.val());
    if (reinterpret_cast<char*>(pProfRec) < pProfSlot->m_capacityMinus16.val())
    {
        pProfRec->m_commandAndMonitor = str_010c41f8;
        _ReadWriteBarrier();
        uiTimestamp = (unsigned int)__rdtsc();
        pProfRec->m_time0 = uiTimestamp;
        pProfSlot->m_end.m_storage = reinterpret_cast<char*>(pProfRec + 1);
    }
}
}  // namespace fnv_00d217d0

extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern float DAT_0104e148;
extern const char str_010ce228[];
extern const char str_010c41f8[];

__forceinline void S00d216e0_timer(const char* name)
{
    hkMonitorStream& kCtx = *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (kCtx.m_end.val() < kCtx.m_capacityMinus16.val())
    {
        hkMonitorStream::TimerCommand* h = reinterpret_cast<hkMonitorStream::TimerCommand*>(kCtx.m_end.val());
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        h->m_time0 = uiTicks;
        kCtx.m_end.m_storage = reinterpret_cast<char*>(h + 1);
    }
}

// 0x00d216e0 traverses the collection container at +0x10; it uses no packed-triangle members or methods.
class CollectionProjectionTraversal : public hkpShapeCollection
{
  public:
    virtual hkReal getMaximumProjection(const hkVector4& direction) const;
};

// Returns the largest child-shape projection, between two timer records.
// @fnv 0x00d216e0
hkReal CollectionProjectionTraversal::getMaximumProjection(const hkVector4& direction) const
{
    volatile float maxProj;
    __declspec(align(16)) float buf[125];

    S00d216e0_timer(str_010ce228);

    const hkpShapeContainer* iter =
        reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(this) + sizeof(hkpShape));

    maxProj = DAT_0104e148;
    int idx = iter->GetFirstKey();

    while (idx != -1)
    {
        const hkpShape* shape = iter->GetShapeForKey(idx, *reinterpret_cast<hkpShapeBuffer*>(buf));
        float currentProj = shape->getMaximumProjection(direction);

        if (!(maxProj > currentProj))
        {
            maxProj = currentProj;
        }

        idx = iter->GetNextShapeKey(idx);
    }

    S00d216e0_timer(str_010c41f8);

    return maxProj;
}

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

class hkpShape_ctor : public hkpShape
{
  public:
    hkpShape_ctor(int type) : hkpShape(static_cast<hkpShapeType>(type))
    {
        m_sReferenceCount = 1;
        m_ulUserData = 0;
        *reinterpret_cast<hkUint32*>(&m_type) = type;
    }
};

struct WeldingAndType
{
    char m_bDisableWelding;
    char m_eCollectionType;
    __forceinline WeldingAndType(char type)
    {
        m_bDisableWelding = 0;
        m_eCollectionType = type;
    }
};

class FUN_00d21410 : public hkpShape_ctor, public hkpShapeContainer
{
  public:
    WeldingAndType m_info;
    FUN_00d21410(int type, char collectionType);
    ~FUN_00d21410();
    virtual int hkpShapeCollection_getContainer();
};

// Constructs a shape object, initializing the reference count, user data, type, and collection type fields.
// @fnv 0x00d21410
FUN_00d21410::FUN_00d21410(int type, char collectionType)
    : hkpShape_ctor(type), hkpShapeContainer(), m_info(collectionType)
{}
