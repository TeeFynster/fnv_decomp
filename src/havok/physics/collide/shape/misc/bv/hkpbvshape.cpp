
// src/havok/physics/collide/shape/misc/bv/hkpbvshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/bv/hkpbvshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"

struct C9D8F0Callback;

// No approved include/hkpBvShape.h exists yet; retain the reflected layout here.
class hkpBvShape : public hkpShape
{
public:
    hkpShape* m_pBvShapeReference;
    hkpSingleShapeContainer m_pContainedShape;

    __declspec(noinline) void ReleaseReference_00c9d930();
    hkpBvShape* Destroy(int flags);
    void CalculateAabb(const hkTransform& transform, float tolerance, hkAabb& out) const;
    hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    void CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& parent, hkpRayHitCollector& collector) const;
    hkpSingleShapeContainer* GetContainer();
    void hkReferencedObject_calcContentStatistics(C9D8F0Callback* callback, void* typeInfo);
    void NotifyCallback(C9D8F0Callback* callback, int flags);
};

extern int DAT_010c6fb0;
extern int DAT_010c6fd0;
// @fnv 0x00c9d8c0
hkpSingleShapeContainer* __fastcall ReleaseSingleShapeContainer(hkpSingleShapeContainer* self, void*, int flags)
{
    const hkpShape* pOldWorld = self->m_pContainedShape;
    *(int**)self = (int*)&DAT_010c6fd0;
    if (pOldWorld)
        pOldWorld->removeReference();
    *(int**)self = (int*)&DAT_010c6fb0;
    return self;
}

// @fnv 0x00c9d970
void hkpBvShape::CalculateAabb(const hkTransform& transform, float tolerance, hkAabb& out) const
{
    m_pBvShapeReference->CalculateAabb(transform, tolerance, out);
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

// Calls FUN_00c9d930 on this, then if flags has bit 0 set, frees this through the memory router's manager using the object flags at offset 4, and returns this.
// @fnv 0x00c9db30
hkpBvShape* hkpBvShape::Destroy(int flags)
{
    ReleaseReference_00c9d930();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short objectFlags = m_usMemSizeAndFlags;
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(this, objectFlags);
    }

    return this;
}

// @fnv 0x00c9d8b0
// src: HAVOK_SRC 0x00c9d8b0
int __stdcall hkpSingleShapeContainer_getNextKey(int a1)
{
    return -1;
}

extern int DAT_010c6fec;
extern int DAT_01268910;

struct C9D8F0Callback
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3(void* context, void* childShape, int flags);
};

// @fnv 0x00c9d8f0
void hkpBvShape::NotifyCallback(C9D8F0Callback* callback, int flags)
{
    callback->method3(&DAT_010c6fec, (void*)m_pContainedShape.m_pContainedShape, 0);
    hkReferencedObject_calcContentStatistics(callback, &DAT_01268910);
}

// @fnv 0x00c9d920
hkpSingleShapeContainer* hkpBvShape::GetContainer()
{
    return &m_pContainedShape;
}

extern int DAT_010c6ff8;
extern int DAT_010c6fd0;
// Explicit constructor entry: initialize the existing storage without calling shared base constructors.
// @fnv 0x00c9d990
hkpBvShape* __fastcall ConstructBvShape(hkpBvShape* self, void*, hkpShape* apBoundingVolume, hkpShape* childShape)
{
    self->m_sReferenceCount = 1;
    self->m_pBvShapeReference = apBoundingVolume;
    self->m_ulUserData = 0;
    *reinterpret_cast<unsigned int*>(&self->m_type) = 27;
    *(void**)self = &DAT_010c6ff8;
    *(void**)&self->m_pContainedShape = &DAT_010c6fd0;
    self->m_pContainedShape.m_pContainedShape = childShape;
    childShape->addReference();
    self->m_pBvShapeReference->addReference();
    return self;
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010c7024[];
extern const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

static __forceinline void TimerCommand(hkMonitorStream* stream, const char* name)
{
    if (stream->m_end.m_storage < stream->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* c = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
        c->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        c->m_time0 = t;
        stream->m_end.m_storage = reinterpret_cast<char*>(c + 1);
    }
}

struct ShapeRayCastOutput
{
    int unk00[16];
    int m_iShapeKeyIndex;
};

// @fnv 0x00c9d9e0
hkBool hkpBvShape::IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    TimerCommand(static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c)), str_010c7024);
    output.m_iShapeKeyIndex++;
    hkBool hit = m_pContainedShape.m_pContainedShape->IntersectRayWithShape(input, output);
    output.m_iShapeKeyIndex--;
    if (hit.m_cBooleanValue)
        output.unk00[output.m_iShapeKeyIndex + 8] = 0;
    TimerCommand(static_cast<hkMonitorStream*>(TlsGetValue(DAT_0126835c)), str_010c41f8);
    return hit;
}

extern unsigned long DAT_0126835c;
static inline void TimerCommand_c9da80(const char* pName)
{
    hkMonitorStream* pkStream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* pkCommand = (hkMonitorStream::TimerCommand*)pkStream->m_end.m_storage;
    if (pkCommand < (hkMonitorStream::TimerCommand*)pkStream->m_capacityMinus16.m_storage)
    {
        pkCommand->m_commandAndMonitor = pName;
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        pkCommand->m_time0 = uiTicks;
        pkStream->m_end.m_storage = (char*)(pkCommand + 1);
    }
}
// Wraps the contained shape in a child collision body and forwards the ray cast.
// @fnv 0x00c9da80
void hkpBvShape::CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& kParent, hkpRayHitCollector& collector) const
{
    TimerCommand_c9da80("TtrcBvShape");
    // The original initializes these four fields directly, without calling the out-of-line default constructor.
    unsigned int bodyStorage[sizeof(hkpCdBody) / sizeof(unsigned int)];
    hkpCdBody& kBody = *reinterpret_cast<hkpCdBody*>(bodyStorage);
    kBody.m_parent = &kParent;
    kBody.m_pMotionState = kParent.m_pMotionState;
    kBody.m_pCollisionShape = m_pContainedShape.m_pContainedShape;
    kBody.m_uiCollisionShapeKey = 0;
    m_pContainedShape.m_pContainedShape->CastRayWithCollector(input, kBody, collector);
    TimerCommand_c9da80("Et");
}

extern int DAT_0102e388;

// Releases the held shape reference and the contained shape (if non-null), rewriting the object's two vtable pointers to fixed addresses around the calls.
// @fnv 0x00c9d930
// src: GUESS 0x00c9d930 (confidence: medium)
void hkpBvShape::ReleaseReference_00c9d930()
{
    hkpBvShape* self = (hkpBvShape*)this;

    hkpShape* bv = self->m_pBvShapeReference;
    *(void**)self = &DAT_010c6ff8;
    bv->removeReference();

    hkpShape* child = const_cast<hkpShape*>(self->m_pContainedShape.m_pContainedShape);
    *(void**)&self->m_pContainedShape = &DAT_010c6fd0;
    if (child)
        child->removeReference();

    *(void**)self = &DAT_0102e388;
    *(void**)&self->m_pContainedShape = &DAT_010c6fb0;
}
