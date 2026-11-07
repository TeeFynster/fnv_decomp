// havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp: AdjDerived (12 functions)

#include "fnv_asm_helpers.h"
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkTransform.h"
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpieceshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010c6fb0;
extern int DAT_010ece2c;
extern int DAT_010ece08;

struct FUN_00e607c0
{
    void* m_p00;            // +0x00
    short m_s04;            // +0x04
    short m_s06;            // +0x06
    int   m_i08;            // +0x08
    int   m_i0C;            // +0x0c
    float m_f10;            // +0x10
    void* volatile m_p14;   // +0x14

    FUN_00e607c0(float arg);
};

// Initializes the object's fields from a float argument and assigns fixed globals to its pointers.
// @fnv 0x00e607c0
FUN_00e607c0::FUN_00e607c0(float afValue)
{
    m_f10 = afValue;
    m_s06 = 1;
    m_i08 = 0;
    m_i0C = 0x14;
    m_p14 = &DAT_010c6fb0;
    m_p00 = &DAT_010ece2c;
    m_p14 = &DAT_010ece08;
}

struct FUN_00e60680_class {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int capacity;
    int __thiscall GetNextIndex(int index);
};
// @fnv 0x00e60680
int __thiscall FUN_00e60680_class::GetNextIndex(int index) {
    int next = index + 1;
    if (next < capacity) return next;
    return -1;
}

struct InnerDispatch {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void run(int,int);
};
struct Dispatch { int x0,x4,x8,xc; InnerDispatch inner; };
struct FUN_00e60690_owner { int unk00; int unk04; int unk08; Dispatch* unk0c; int* unk10; void DispatchToInner(int index,int value); };
// Calls run on the inner dispatcher with the value from unk10 at index and the given value.
// @fnv 0x00e60690
void FUN_00e60690_owner::DispatchToInner(int index,int value) { unk0c->inner.run(unk10[index],value); }

extern int DAT_010c6fb0;
extern int DAT_0102e388;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00e60c30_cls {
    int m_vptr;
    unsigned short m_uSize;
    unsigned short m_u06;
    int unk08;
    int unk0c;
    int unk10;
    void* volatile m_p14;

    FUN_00e60c30_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Sets the vtable and a global pointer, then, if acFlags has bit 0 set, frees this object through the allocator obtained from FUN_00c85750.
// @fnv 0x00e60c30
FUN_00e60c30_cls* FUN_00e60c30_cls::Destroy(unsigned char acFlags)
{
    m_p14 = (void*)&DAT_010c6fb0;
    m_vptr = (int)&DAT_0102e388;
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, m_uSize);
    }
    return this;
}

// @fnv 0x00e60670
// src: GUESS 0x00e60670 (confidence: high)
int Hkpconvexpieceshape_ReturnZero()
{
    return 0;
}

#include <xmmintrin.h>
struct FUN_00e606c0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    __m128* m_pSrc;

    void Copy(__m128* apDst);
};

// @fnv 0x00e606c0
void FUN_00e606c0_cls::Copy(__m128* apDst)
{
    *apDst = *m_pSrc;
}

struct E606E0Shape {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fSphereRadius;
    int unk14;
    Vec4* m_kVertices;
    int m_iStridedVertexCount;

    Vec4* CopyVerticesWithRadius(Vec4* vertices) const;
};

// @fnv 0x00e606e0
Vec4* E606E0Shape::CopyVerticesWithRadius(Vec4* apDestVertices) const
{
    Vec4* pDest = apDestVertices;
    for (int i = 0; i < m_iStridedVertexCount; i++) {
        pDest->m_vComponents = m_kVertices[i].m_vComponents;
        pDest->m_vComponents.m128_f32[3] = m_fSphereRadius;
        pDest++;
    }
    return apDestVertices;
}

struct Mat {
    Vec4 rows[8];
};

struct __declspec(align(16)) Scratch {
    float data[128];
};

struct Sub {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual Mat* GetMat(void* apKey, Scratch* apScratch);
};

struct Holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Sub sub10;
};

struct FUN_00e60730_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Holder* m_p20;
    void** m_p24;
    void hkpConvexPieceShape_GetRTTI(const unsigned short* apIndices, int aiCount, Vec4* apOut);
};

// @fnv 0x00e60730
// src: COMMUNITY 0x00e60730
void FUN_00e60730_cls::hkpConvexPieceShape_GetRTTI(const unsigned short* apIndices, int aiCount, Vec4* apOut)
{
    Scratch scratch;
    for (int i = aiCount - 1; i >= 0; i--) {
        int iIndex = *apIndices;
        Mat* pMatrix = m_p20->sub10.GetMat(m_p24[iIndex / 3], &scratch);
        apIndices++;
        apOut->v = pMatrix->rows[iIndex % 3 + 2].v;
        *((unsigned int*)apOut + 3) = iIndex | 0x3f000000;
        apOut++;
    }
}

inline __m128 TransformedPos_e608(const hkTransform& a, const __m128& b)
{
    const __m128 xb = _mm_shuffle_ps(b, b, 0x00);
    const __m128 yb = _mm_shuffle_ps(b, b, 0x55);
    const __m128 zb = _mm_shuffle_ps(b, b, 0xaa);
    __m128 t0 = _mm_mul_ps(xb, a.m_kColumn0);
    __m128 t1 = _mm_mul_ps(yb, a.m_kColumn1);
    __m128 t2 = _mm_mul_ps(zb, a.m_kColumn2);
    return _mm_add_ps(_mm_add_ps(t0, t1), _mm_add_ps(t2, a.m_vTranslation));
}

struct Aabb_e608 {
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

class Shape_e608 {
public:
    int unk00, unk04, unk08, unk0c;
    float m_fSphereRadius;
    int unk14;
    __m128* m_kVertices;
    int m_iStridedVertexCount;

    void GetExpandedWorldVertexBounds(const hkTransform& kLocalToWorld, float fTolerance, Aabb_e608& kOut) const;
};

// Computes the world-space AABB of the shape's vertices via kLocalToWorld, then expands it by m_fSphereRadius plus fTolerance into kOut.
// @fnv 0x00e60800
// src: GUESS 0x00e60800 (confidence: medium)
void Shape_e608::GetExpandedWorldVertexBounds(const hkTransform& kLocalToWorld, float fTolerance, Aabb_e608& kOut) const
{
    kOut.m_kMinimumCorner = _mm_set1_ps(3.40282e+38f);
    kOut.m_kMaximumCorner = _mm_set1_ps(-3.40282e+38f);
    for (int i = 0; i < m_iStridedVertexCount; i++) {
        __m128 world = TransformedPos_e608(kLocalToWorld, m_kVertices[i]);
        kOut.m_kMinimumCorner = _mm_min_ps(kOut.m_kMinimumCorner, world);
        kOut.m_kMaximumCorner = _mm_max_ps(kOut.m_kMaximumCorner, world);
    }
    float fRadius = m_fSphereRadius + fTolerance;
    __m128 r = _mm_load1_ps(&fRadius);
    kOut.m_kMinimumCorner = _mm_sub_ps(kOut.m_kMinimumCorner, r);
    kOut.m_kMaximumCorner = _mm_add_ps(kOut.m_kMaximumCorner, r);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
#include "../../../../../../../include/hkBool.h"
extern DWORD hkMonitorStreamTls;

static inline void S_00e609c0_Timer(const char* name, int& t) {
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.val();
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        t = (int)__rdtsc();
        h->m_time0 = *(volatile unsigned int*)&t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

struct S_00e609c0_Bool {
    char m_cBooleanValue;
    S_00e609c0_Bool() {}
    S_00e609c0_Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct __declspec(align(16)) S_00e609c0_ShapeBuffer {
    unsigned int m_data[128];
};

struct S_00e609c0_RayInput;

struct S_00e609c0_RayOutput {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void changeLevel(int delta) { m_uiShapeKeyIndex += delta; }
    void setKey(unsigned int key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};

struct S_00e609c0_Shape {
    virtual ~S_00e609c0_Shape();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual S_00e609c0_Bool RayCast(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const;
    int unk04_;
    int unk08_;
    int unk0C_;
};

struct S_00e609c0_ShapeContainer {
    virtual ~S_00e609c0_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00e609c0_Shape* GetShapeForKey(unsigned int key, S_00e609c0_ShapeBuffer& buffer) const;
};

struct S_00e609c0_ShapeCollection : S_00e609c0_Shape, S_00e609c0_ShapeContainer {
};

struct S_00e609c0_RayShapeCollectionFilter {
    virtual S_00e609c0_Bool IsCollisionEnabled(const S_00e609c0_RayInput& input, const S_00e609c0_Shape& shape,
        const S_00e609c0_ShapeContainer& container, unsigned int key) const = 0;
};

struct S_00e609c0_RayInput {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    const S_00e609c0_RayShapeCollectionFilter* m_pRayShapeCollectionFilter;
};

struct S_00e609c0_ConvexPieceShape : S_00e609c0_Shape {
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    const S_00e609c0_ShapeCollection* m_pShapeCollection;
    unsigned int* m_keys;
    int m_numKeys;

    S_00e609c0_Bool hkpConvexPieceShape_castRayImpl(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const;
};

// Ray-casts each child shape whose filter allows it and, if any hit, sets results' key to the last hit index; returns whether any child was hit.
// @fnv 0x00e609c0
// src: HAVOK_LIB 0x00e609c0
S_00e609c0_Bool S_00e609c0_ConvexPieceShape::hkpConvexPieceShape_castRayImpl(const S_00e609c0_RayInput& input, S_00e609c0_RayOutput& results) const
{
    int hitIndex;
    S_00e609c0_Timer("TtrcConvxPiece", hitIndex);
    results.changeLevel(1);
    hitIndex = -1;
    for (int i = 0; i < m_numKeys; i++)
    {
        if (!input.m_pRayShapeCollectionFilter ||
            input.m_pRayShapeCollectionFilter->IsCollisionEnabled(input, *m_pShapeCollection,
                *static_cast<const S_00e609c0_ShapeContainer*>(m_pShapeCollection), m_keys[i]))
        {
            S_00e609c0_ShapeBuffer buffer;
            const S_00e609c0_Shape* child = m_pShapeCollection->GetShapeForKey(m_keys[i], buffer);
            S_00e609c0_Bool hit = child->RayCast(input, results);
            if (hit)
            {
                hitIndex = i;
            }
        }
    }
    results.changeLevel(-1);
    if (hitIndex != -1)
    {
        results.setKey(hitIndex);
    }
    int endTicks;
    S_00e609c0_Timer("Et", endTicks);
    return hitIndex != -1;
}

extern unsigned int DAT_0126835c;

inline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}

// The original's timer helpers (expansions of Havok's timer macros), kept as members of a unit-local view so the
// inlined code keeps its shape.
struct StringCursor_hkpconvexpieceshape : hkMonitorStream
{
    void timerBegin(const char* name);
    void timerBegin(const char* name1, const char* name2);
    void timerEnd(const char* name);
};
inline void StringCursor_hkpconvexpieceshape::timerBegin(const char* name)
{
    char* cur = m_end.m_storage;
    if (cur < m_capacityMinus16.m_storage) {
        *(const char**)cur = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = t;
        cur += 12;
        m_end.m_storage = cur;
    }
}

inline void StringCursor_hkpconvexpieceshape::timerEnd(const char* name)
{
    char* cur = m_end.m_storage;
    if (cur < m_capacityMinus16.m_storage) {
        *(const char**)cur = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(cur + 4) = t;
        cur += 12;
        m_end.m_storage = cur;
    }
}


struct BodyA {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20;
    struct Filter* m_iFilter;
};

struct ShapeBase;
struct ShapeDerived;

struct Filter {
    virtual hkBool IsCollisionEnabled(const BodyA* bodyA, const ShapeDerived* shapeD, const ShapeBase* shapeB, int key);
};

struct ChildShape {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void func24(const BodyA* bodyA, const struct CdBody* bodyB, void* input);
};

struct ShapeBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual ChildShape* GetShapeForKey(int key, void* buffer);
};

struct ShapeDerived {
    int unk00; int unk04; int unk08; int unk0c;
    ShapeBase m_base;
};

struct BodyB {
    int unk00; int unk04;
    void* m_kMotionState;
};

struct CdBody {
    ChildShape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_kMotionState;
    const BodyB* m_parent;
};

struct FUN_00e60b00_cls {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    ShapeDerived* m_pCollisionShape;
    int* m_keys;
    int m_uiItemCount;

    void ProcessCollisionShapes(const BodyA* bodyA, const BodyB* bodyB, void* input);
};

// For each key passing bodyA's filter, gets the child shape and calls its func24 with bodyA, a CdBody built from bodyB, and input, between profiler timers.
// @fnv 0x00e60b00
void FUN_00e60b00_cls::ProcessCollisionShapes(const BodyA* bodyA, const BodyB* bodyB, void* input) {
    static_cast<StringCursor_hkpconvexpieceshape&>(hkMonitorStream::getInstance()).timerBegin("TtrcConvxPiece");

    for (int i = 0; i < this->m_uiItemCount; ++i) {
        if (bodyA->m_iFilter) {
            const ShapeBase* pShapeBase = this->m_pCollisionShape ? &this->m_pCollisionShape->m_base : 0;
            if (!bodyA->m_iFilter->IsCollisionEnabled(bodyA, this->m_pCollisionShape, pShapeBase, this->m_keys[i]))
                continue;
        }

        __declspec(align(16)) int buffer[128];
        ChildShape* child = this->m_pCollisionShape->m_base.GetShapeForKey(this->m_keys[i], buffer);
        CdBody body;
        body.m_parent = bodyB;
        body.m_kMotionState = bodyB->m_kMotionState;
        body.m_pCollisionShape = child;
        body.m_uiCollisionShapeKey = i;
        child->func24(bodyA, &body, input);
    }

    static_cast<StringCursor_hkpconvexpieceshape&>(hkMonitorStream::getInstance()).timerEnd("Et");
}

// sub ecx,0x14; jmp Destroy == MSVC adjustor thunk (Derived overrides a virtual both bases declare).
struct AdjPrimaryBase
{
    virtual void AdjustThisAndForward_00e60c20();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct AdjSecondaryBase
{
    virtual void AdjustThisAndForward_00e60c20();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00e60c20
// src: GUESS 0x00e60c20 (confidence: low)
    virtual void AdjustThisAndForward_00e60c20();
};

AdjDerived::AdjDerived()
{
}
