
// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl InitAndReturnTail(void*, void*, void*);
extern "C" void __cdecl hkpCollectionCollectionAgent3_updateFilter(void*, void*, void*);
extern "C" void __cdecl hkpCollectionCollectionAgent3_calcStatistics(void*, void*, void*);
extern "C" void __cdecl ForwardCall(void*, void*, void*);
extern "C" void __cdecl Object__hkAgent1nMachine_WarpTime_Thunk_00d34d80(void*, void*, void*);
extern "C" void __cdecl process_00d35770(void*, void*, void*);
extern "C" void __cdecl Object_HkAgent1nMachine_Destroy_Thunk(void*, void*, void*);

struct FUN_00d36270_s {
    void* m_vt;
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
    void* m_k;
    unsigned char m_flag;
};

// Initializes the object's vtable and function pointers, clears several pointer fields to zero, and sets m_flag to 1.
// @fnv 0x00d36270
// src: GUESS 0x00d36270 (confidence: low)
void hkpCollectionCollectionAgent3_updateFilter_UpdateState_00d36270(FUN_00d36270_s* self)
{
    self->m_vt = &InitAndReturnTail;
    self->m_k = &process_00d35770;
    self->m_iUnknownValue = 0;
    self->m_kPointB = 0;
    self->m_iThirdValue = 0;
    self->m_iFourthElementInteger = 0;
    self->m_usTrailingValue = 0;
    self->m_f = &hkpCollectionCollectionAgent3_updateFilter;
    self->m_g = &hkpCollectionCollectionAgent3_calcStatistics;
    self->m_h = &ForwardCall;
    self->m_i = &Object__hkAgent1nMachine_WarpTime_Thunk_00d34d80;
    self->m_kPointA = &Object_HkAgent1nMachine_Destroy_Thunk;
    self->m_flag = 1;
}

void __cdecl _hkAgent1nMachine_WarpTime(void*, float, float, void*);

// Calls FUN_00da35f0 with b, c, d and e, ignoring a.
// @fnv 0x00d34d80
// src: GUESS 0x00d34d80 (confidence: medium)
void __cdecl Object__hkAgent1nMachine_WarpTime_Thunk_00d34d80(void* apUnused, void* b, float afValue1, float afValue2, void* e)
{
    _hkAgent1nMachine_WarpTime(b, afValue1, afValue2, e);
}

struct FUN_00cf5830_cls {
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int unk10;
    unsigned short unk14;
    unsigned short m_16;

    int hkpListShape_getNumChildShapes();
};

// @fnv 0x00cf5830
// src: HAVOK_LIB 0x00cf5830
int FUN_00cf5830_cls::hkpListShape_getNumChildShapes() {
    return m_0c - m_16;
}

struct __declspec(align(16)) D36270Data {
    void* vtable;
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
    void* g;
    void* h;
    void* i;
    void* j;
    void* k;
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
};
void hkpCollectionCollectionAgent3_updateFilter_UpdateState_00d36270(D36270Data*);
struct D362Script {
    void AddEntry(D36270Data*, int row, int column);
};
extern unsigned char DAT_01268ad5;
// @fnv 0x00d362c0
// src: HAVOK_LIB 0x00d362c0
void hkpCollectionCollectionAgent3_registerAgent3(D362Script* script) {
    D36270Data data;
    data.flag0 = 0; data.flag1 = 0; data.flag2 = 0;
    data.f = 0; data.g = 0; data.h = 0; data.i = 0; data.j = 0;
    hkpCollectionCollectionAgent3_updateFilter_UpdateState_00d36270(&data);
    script->AddEntry(&data, 8, 8);
    data.flag1 = 1; data.flag2 = 1;
    script->AddEntry(&data, 7, 8);
    script->AddEntry(&data, 8, 7);
    script->AddEntry(&data, 7, 7);
    *(unsigned char*)((char*)script + 0x1e22) = 1;
    DAT_01268ad5 = 1;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern "C" void __cdecl hkpAgentMachineUtil_calc1nStatistics(void*, void*, void*);
extern "C" const char str_010ceca8[];

struct S00d34d30_Obj
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(const char* s);
    virtual void m7();
};

// @fnv 0x00d34d30
// src: XBOX_PDB 0x00d34d30
void __cdecl hkpCollectionCollectionAgent3_calcStatistics(void* a, void* b, void* c, void* d)
{
    S00d34d30_Obj* obj = (S00d34d30_Obj*)d;
    obj->m6(str_010ceca8);
    hkpAgentMachineUtil_calc1nStatistics(b, c, d);
    obj->m7();
}

struct Obj {
    virtual void* m00();
    virtual void* m04();
    virtual void* m08();
    virtual void* m0c();
    virtual void* m10();
};

struct Local {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    void* f4;
    void* f5;
    void* f6;
    void* f7;
};

extern "C" void __cdecl Object_HkAgent1nMachine_VisitAllAgents_Thunk(void*, void*);

// Fills a Local struct with a3 through a7 and the m10() results of the objects at a3 and a4, then calls FUN_00da4900 with a2 and the struct.
// @fnv 0x00d34db0
// src: HAVOK_LIB 0x00d34db0
void __cdecl hkpCollectionCollectionAgent3_updateFilter(void* apUnused, void* a2, void* apFirstObj, void* apSecondObj, void* a5, void* a6, void* a7)
{
    Local s;
    void* pFirstObj = *(void**)apFirstObj;
    void* pSecondObj = *(void**)apSecondObj;

    s.f0 = apFirstObj;
    s.f1 = apSecondObj;
    s.f4 = a5;
    s.f5 = a6;
    s.f6 = a7;
    s.f2 = ((Obj*)pFirstObj)->m10();
    s.f3 = ((Obj*)pSecondObj)->m10();

    Object_HkAgent1nMachine_VisitAllAgents_Thunk(a2, &s);
}

// Keep the intrinsic vector free of byte-array aliases, which add /GS checks absent from this unit.
#define _INCLUDED_MM2
// Exe 0x00d34e10 FUN_00d34e10: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;

extern "C" {
LocalM128 _mm_load_ps(const float* p);
void _mm_store_ps(float* p, LocalM128 v);
LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
LocalM128 _mm_sqrt_ss(LocalM128 a);
LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm8);
LocalM128 _mm_set_ps1(float a);
}

extern LocalM128 DAT_010ec7f0;
extern const LocalM128 DAT_011b6d70;  // AABB quantization clip max
extern LocalM128 DAT_01267e30;

typedef unsigned int hkpShapeKey;

struct hkFloat4
{
    float x;
    float y;
    float z;
    float w;
};

#include "../../../../../../include/hkSimdRealq.h"

#include "../../../../../../include/hkVector4q.h"

__forceinline void hkVector4q::setAdd4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4q::setMin4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4q::setMax4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }

__forceinline void hkVector4q::setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
{
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(DAT_010ec7f0.m128_f32), t.m_vComponents), a.m_vComponents), _mm_mul_ps(t.m_vComponents, b.m_vComponents));
}

__forceinline void hkVector4q::setAddMul4(const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& r)
{
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents), a.m_vComponents);
}

__forceinline hkSimdRealq hkVector4q::getSimdAt3() const
{
    hkSimdRealq r;
    r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    return r;
}

__forceinline hkSimdRealq hkVector4q::length3Simd() const
{
    const LocalM128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
    const LocalM128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    hkSimdRealq r;
    r.m_vValue = _mm_sqrt_ss(s);
    return r;
}

// A float4 copied through integer registers, then read as a vector (hkVector4q has a copy constructor, so it
// cannot be a union member itself).
union hkVector4u
{
    hkFloat4 m_f;
    LocalM128 m_q;
    __forceinline const hkVector4q& v() const { return *reinterpret_cast<const hkVector4q*>(&m_q); }
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

__forceinline void SetTransformedPoint(hkVector4q& out, const hkTransformq& t, const hkVector4q& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(b0, t.m_kColumn0.m_vComponents);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(b1, t.m_kColumn1.m_vComponents);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(b2, t.m_kColumn2.m_vComponents);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct hkMotionStateq
{
    hkTransformq m_kMotionTransform;
    hkVector4q m_vCenterOfMass0;
    hkVector4q m_vCenterOfMass1;
    hkVector4q m_qRotation0;
    hkVector4q m_qRotation1;
    hkFloat4 m_vCenterOfMassLocal;
    hkVector4q m_kDeltaAngle;
};

struct SweptTransformSamples
{
    const hkMotionStateq* m_kMotionState;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformq m_kTransforms[4];
    int m_numQsTransforms;
    int unk114;
    int unk118;
    int unk11C;
    hkTransformq m_kMotionTransform;
    hkTransformq m_shapeToMotion;
};

void __cdecl hkMotionStateq_SampleSweptMotionTransforms(const hkMotionStateq* motionState, SweptTransformSamples* out);

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

#include "../../../../../../include/hkAabbUint32.h"
typedef hkAabbUint32 hkAabbUint32Key;

struct hkpShapeBufferq
{
    int m_data[128];
};

class hkpShapeq
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, hkAabbq& out) const;
};

class hkpShapeContainerq
{
public:
    virtual void v00();
    virtual void v04();
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual void v10();
    virtual const hkpShapeq* GetShapeForKey(hkpShapeKey key, hkpShapeBufferq& buffer) const;
};

struct hkpCdBodyq
{
    const hkpShapeq* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyq* m_parent;

    __forceinline const hkpCdBodyq* getRootCollidable() const
    {
        const hkpCdBodyq* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return body;
    }
};

struct hkpCollisionQualityInfoq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iQualityInfoValue10;
};

struct hkpProcessCollisionInputq
{
    int unk00;
    int unk04;
    float m_fScalar;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4q m_kAabbMin;
    hkVector4q m_kAabbMaximum;
    hkVector4q m_kAabbScale;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkpCollisionQualityInfoq* m_pCollisionQualityInfo;
};


union hkVec4F
{
    LocalM128 m_vComponents;
    float m_f[4];
    __forceinline float operator()(int i) const { return m_f[i]; }
};

static __forceinline void convertToUint32WithClip(const hkVector4q& a, const hkVector4q& b, const hkVector4q& scale,
                                                  const LocalM128& maxVal, const LocalM128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}


struct BoundingVolumeData : hkAabbUint32
{
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    hkAabbUint32* m_pChildShapeAabbs;
    hkpShapeKey* m_pChildShapeKeys;

    __forceinline bool isValid() const { return m_kMinimumCorner[0] <= m_kMaximumCorner[0]; }
};

struct hkpCollidableq : hkpCdBodyq
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BoundingVolumeData m_kBoundingVolumeData;
};

void __cdecl FUN_00cf8690(hkAabbUint32Key* out, const hkAabbUint32* in);

struct hkAabbUint32Less
{
    unsigned char m_unused;
};

void __cdecl hkAlgorithm_quickSortRecursive_struct_hk1AxisSweep_AabbInt_class_hkAlgorithm_less_struct_hk1AxisSweep_AabbInt(hkAabbUint32Key* arr, int iStart, int iEnd, hkAabbUint32Less cmp);

static __forceinline void expandAabbUint32(hkAabbUint32Key* out, const hkAabbUint32* in)
{
    int shift = in->m_ucExpansionShift;
    unsigned int x = in->m_kMinimumCorner[0] - (in->m_ucExpansionMin[0] << shift);
    unsigned int y = in->m_kMinimumCorner[1] - (in->m_ucExpansionMin[1] << shift);
    unsigned int z = in->m_kMinimumCorner[2] - (in->m_ucExpansionMin[2] << shift);
    out->m_kMinimumCorner[0] = x;
    out->m_kMinimumCorner[1] = y;
    out->m_kMinimumCorner[2] = z;
    unsigned int maxX = in->m_kMaximumCorner[0] + (in->m_ucExpansionMax[0] << shift);
    unsigned int maxY = in->m_kMaximumCorner[1] + (in->m_ucExpansionMax[1] << shift);
    unsigned int maxZ = in->m_kMaximumCorner[2] + (in->m_ucExpansionMax[2] << shift);
    out->m_kMaximumCorner[0] = maxX;
    out->m_kMaximumCorner[1] = maxY;
    out->m_kMaximumCorner[2] = maxZ;
}

static __forceinline void copyCachedAabbs(const BoundingVolumeData& bvd, int useContinuous, hkAabbUint32Key* aabbsOut, int& numAabbs)
{
    const hkAabbUint32* childAabbs = bvd.m_pChildShapeAabbs;
            const hkpShapeKey* keys = bvd.m_pChildShapeKeys;
            hkAabbUint32Key* out = aabbsOut;
            for (int i = 0; i < bvd.m_uiNumChildShapeAabbs; i++)
            {
                if (useContinuous)
                {
                    expandAabbUint32(out, childAabbs);
                }
                else
                {
                    FUN_00cf8690(out, childAabbs);
                }
                numAabbs++;
                out->m_uiCollisionShapeKey = *keys++;
                childAabbs++;
                out++;
            }
}

// @fnv 0x00d351c0
// src: XBOX_PDB 0x00d351c0
int __cdecl hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(const hkpCdBodyq* body, int useCache, const hkpShapeContainerq* container,
                         const hkpProcessCollisionInputq* input, hkAabbUint32Key* aabbsOut)
{
    SweptTransformSamples samples;
    hkpShapeBufferq shapeBuffer;

    const hkpCollisionQualityInfoq* quality = input->m_pCollisionQualityInfo;
    int useContinuous = quality->m_iQualityInfoValue10;
    int numAabbs = 0;

    if (!body->m_parent)
    {
        const hkpCdBodyq* rootBody = body;
        const hkpCollidableq* collidable = (const hkpCollidableq*)rootBody;
        const BoundingVolumeData& bvd = collidable->m_kBoundingVolumeData;
        const hkAabbUint32* childAabbs = bvd.m_pChildShapeAabbs;
        if (childAabbs && bvd.isValid())
        {
            if (!bvd.m_uiNumChildShapeAabbs)
            {
                return 0;
            }
            copyCachedAabbs(bvd, useContinuous, aabbsOut, numAabbs);
            if (!useContinuous)
            {
                goto done;
            }
            goto sortAabbs;
        }

        if (bvd.isValid() && useCache)
        {
            if (useContinuous)
            {
                expandAabbUint32(aabbsOut, &bvd);
                aabbsOut->m_uiCollisionShapeKey = 0;
                numAabbs = 1;
                goto done;
            }
            hkAabbUint32Key* volatile& rootOut = aabbsOut;
            FUN_00cf8690(rootOut, &bvd);
            volatile hkAabbUint32Key* output = rootOut;
            volatile int& resultCount = numAabbs;
            resultCount = 1;
            output->m_uiCollisionShapeKey = 0;
            return resultCount;
        }
    }

    if (useContinuous)
    {
        const hkpCdBodyq* root = body->getRootCollidable();
        const hkMotionStateq* motion = (const hkMotionStateq*)root->m_pMotionState;
        hkMotionStateq_SampleSweptMotionTransforms(motion, &samples);
    }

    {
        hkpShapeKey key = container->GetFirstKey();
        if (key != hkpShapeKey(-1))
        {
        hkAabbUint32Key* out = aabbsOut;
        do
        {
            const hkpShapeq* child = container->GetShapeForKey(key, shapeBuffer);

            hkAabbq aabb;
            hkVector4q& boundMinimum = aabb.m_kMinimumCorner;
            hkVector4q& boundMaximum = aabb.m_kMaximumCorner;
            const void* motion = body->m_pMotionState;
            float tolerance = input->m_fScalar;
            child->getAabb(motion, tolerance, aabb);

            if (useContinuous)
            {
                hkVector4q minimum;
                minimum.m_vComponents = _mm_load_ps(boundMinimum.m_vComponents.m128_f32);
                hkVector4q half;
                half.m_vComponents = _mm_set_ps1(0.5f);

                hkVector4q halfExtents;
                halfExtents.setSub4(boundMaximum, minimum);
                halfExtents.mul4(half);

                hkVector4q center;
                center.setInterpolate4(boundMaximum, minimum, half);

                hkVector4q centerMotion;
                SetTransformedPoint(centerMotion, samples.m_shapeToMotion, center);
                hkVector4q centerWorld;
                SetTransformedPoint(centerWorld, samples.m_kMotionTransform, centerMotion);

                hkVector4q sweptMin;
                sweptMin.setMin4(center, centerWorld);
                hkVector4q sweptMax;
                sweptMax.setMax4(center, centerWorld);

                const hkMotionStateq* motionState = samples.m_kMotionState;
                hkVector4u comLocal;
                comLocal.m_f = motionState->m_vCenterOfMassLocal;

                for (int k = 0; k < samples.m_numQsTransforms; k++)
                {
                    hkVector4q relCenter;
                    relCenter.setSub4(centerMotion, comLocal.v());
                    hkVector4q p;
                    p.setAddMul4(comLocal.v(), relCenter, samples.m_kTransforms[k].m_vTranslation.getSimdAt3());
                    hkVector4q pWorld;
                    SetTransformedPoint(pWorld, samples.m_kTransforms[k], p);
                    sweptMin.setMin4(sweptMin, pWorld);
                    sweptMax.setMax4(sweptMax, pWorld);
                }

                hkSimdRealq len = halfExtents.length3Simd();
                hkVector4q radius;
                radius.m_vComponents = _mm_shuffle_ps(len.m_vValue, len.m_vValue, 0);
                hkVector4q expand;
                expand.setAddMul4(halfExtents, radius, motionState->m_kDeltaAngle.getSimdAt3());
                radius.setMin4(radius, expand);

                sweptMin.setSub4(sweptMin, radius);
                sweptMax.setAdd4(sweptMax, radius);
                boundMinimum.setMin4(sweptMin, sweptMin);
                boundMaximum.setMax4(sweptMax, sweptMax);
            }

            hkAabbUint32Key* cur = out++;
            LocalM128 maxVal = DAT_011b6d70;
            numAabbs++;
            const hkVector4q& scale = input->m_kAabbScale;
            const hkVector4q& offsetMin = input->m_kAabbMin;
            const hkVector4q& offsetMax = input->m_kAabbMaximum;
            hkVec4F convertedMin;
            convertedMin.m_vComponents = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(offsetMin.m_vComponents, boundMinimum.m_vComponents), scale.m_vComponents), maxVal), DAT_01267e30);
            cur->m_kMinimumCorner[0] = fnv_FloatToInt(convertedMin(0));
            cur->m_kMinimumCorner[1] = fnv_FloatToInt(convertedMin(1));
            cur->m_kMinimumCorner[2] = fnv_FloatToInt(convertedMin(2));
            cur->m_uiCollisionShapeKey = fnv_FloatToInt(convertedMin(3));

            hkVec4F convertedMax;
            convertedMax.m_vComponents = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(boundMaximum.m_vComponents, offsetMax.m_vComponents), scale.m_vComponents), maxVal), DAT_01267e30);
            cur->m_kMaximumCorner[0] = fnv_FloatToInt(convertedMax(0));
            cur->m_kMaximumCorner[1] = fnv_FloatToInt(convertedMax(1));
            cur->m_kMaximumCorner[2] = fnv_FloatToInt(convertedMax(2));
            cur->m_kMaximumCorner[3] = fnv_FloatToInt(convertedMax(3));


            cur->m_uiCollisionShapeKey = key;
            key = container->GetNextShapeKey(key);
        } while (key != hkpShapeKey(-1));
        }
    }

sortAabbs:
    hkAabbUint32Less comparator = {0};
    if (numAabbs > 1)
    {
        hkAlgorithm_quickSortRecursive_struct_hk1AxisSweep_AabbInt_class_hkAlgorithm_less_struct_hk1AxisSweep_AabbInt(aabbsOut, 0, numAabbs - 1, comparator);
    }
done:
    return numAabbs;
}

typedef unsigned int hkUint32;

// The shared headers have no hkString declaration; retain its inline block-copy operation without a class copy.
static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        dst32 += 4;
        src32 += 4;
    } while (--numQuads > 0);
}

struct __declspec(align(16)) SortEntry {
    hkUint32 m_key;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkUint32 unk10;
    hkUint32 unk14;
    hkUint32 unk18;
    hkUint32 unk1C;
    SortEntry() {}
    SortEntry(const SortEntry& o) { memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
    void operator=(const SortEntry& o) { memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
};

struct SortEntryLess {
    bool operator()(const SortEntry& a, const SortEntry& b) const { return a.m_key < b.m_key; }
};

template <typename T>
__forceinline void hkSwap(T& x, T& y)
{
    T t(y);
    y = x;
    x = t;
}

// Sorts pArr[d..h] in place with quicksort, using the middle element as pivot and the cmpLess comparator.
// @fnv 0x00d36360
// src: HAVOK_LIB 0x00d36360
void __cdecl hkAlgorithm_quickSortRecursive_struct_hk1AxisSweep_AabbInt_class_hkAlgorithm_less_struct_hk1AxisSweep_AabbInt(SortEntry* pArr, int aiLow, int aiHigh, SortEntryLess cmpLess)
{
    int i, j;
    SortEntry strPivot;
begin:
    j = aiHigh;
    i = aiLow;
    strPivot = pArr[(aiLow + aiHigh) >> 1];
    do
    {
        while (cmpLess(pArr[i], strPivot)) { i++; }
        while (cmpLess(strPivot, pArr[j])) { j--; }
        if (j >= i)
        {
            if (j != i)
            {
                hkSwap(pArr[i], pArr[j]);
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (aiLow < j) hkAlgorithm_quickSortRecursive_struct_hk1AxisSweep_AabbInt_class_hkAlgorithm_less_struct_hk1AxisSweep_AabbInt(pArr, aiLow, j, cmpLess);
    if (i < aiHigh) { aiLow = i; goto begin; }
}

extern "C" LocalM128 _mm_set_ss(float);
struct hkpAgent3ProcessInputq
{
    const hkpCdBodyq* m_pBodyA;
    const hkpCdBodyq* m_pBodyB;
    void* m_pContactManager;
    const hkpProcessCollisionInputq* m_pRayCastInput;
};
static __forceinline void interpolateCenter(hkVector4q& out, const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& t)
{
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, _mm_shuffle_ps(t.m_vValue,t.m_vValue,0)), a.m_vComponents), _mm_mul_ps(b.m_vComponents, _mm_shuffle_ps(t.m_vValue,t.m_vValue,0)));
}
static __forceinline void convertLowerCurrent(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                  const LocalM128& maxVal, const LocalM128& minVal, hkAabbUint32Key* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(offset.m_vComponents, in.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out->m_kMinimumCorner[0] = fnv_FloatToInt(x(0));
    out->m_kMinimumCorner[1] = fnv_FloatToInt(x(1));
    out->m_kMinimumCorner[2] = fnv_FloatToInt(x(2));
    out->m_ucExpansionShift = fnv_FloatToInt(x(3));
}
static __forceinline void convertUpperCurrent(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                  const LocalM128& maxVal, const LocalM128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(offset.m_vComponents, _mm_load_ps(in.m_vComponents.m128_f32));
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}

static __forceinline void quantizeAabb(const hkAabbq& aabb, const hkpProcessCollisionInputq* in, hkAabbUint32Key* out) {
 LocalM128 maxVal=DAT_011b6d70;
 convertLowerCurrent(aabb.m_kMinimumCorner,in->m_kAabbMin,in->m_kAabbScale,maxVal,DAT_01267e30,out);
 convertUpperCurrent(aabb.m_kMaximumCorner,in->m_kAabbMaximum,in->m_kAabbScale,maxVal,DAT_01267e30,out->m_kMaximumCorner);
}

// @fnv 0x00d34e10
// src: GUESS 0x00d34e10 (confidence: low)
void __cdecl hkpAgent3ProcessInputq_ProcessEntries_00d34e10(const hkpAgent3ProcessInputq& input, const hkpShapeContainerq* container, const hkpCdBodyq* body,
                          const hkpShapeKey* keys, int numKeys, hkAabbUint32Key* __restrict aabbsOut)
{
    SweptTransformSamples samples;
    hkpShapeBufferq shapeBuffer;

    int useContinuous = input.m_pRayCastInput->m_pCollisionQualityInfo->m_iQualityInfoValue10;
    if (useContinuous)
    {
        hkMotionStateq_SampleSweptMotionTransforms((const hkMotionStateq*)body->getRootCollidable()->m_pMotionState, &samples);
    }

    for (int i = 0; i < numKeys; i++)
    {
        hkpShapeKey key = keys[i];
        const hkpShapeq* child = container->GetShapeForKey(key, shapeBuffer);

        hkAabbq aabb;
        child->getAabb(body->m_pMotionState, input.m_pRayCastInput->m_fScalar, aabb);

        if (useContinuous)
        {
            hkSimdRealq half;
            half.m_vValue = _mm_set_ss(0.5f);

            hkVector4q halfExtents;
            halfExtents.setSub4(aabb.m_kMaximumCorner, aabb.m_kMinimumCorner);
            halfExtents.m_vComponents = _mm_mul_ps(halfExtents.m_vComponents, _mm_shuffle_ps(half.m_vValue,half.m_vValue,0));

            hkVector4q center;
            interpolateCenter(center, aabb.m_kMaximumCorner, aabb.m_kMinimumCorner, half);

            hkVector4q centerMotion;
            SetTransformedPoint(centerMotion, samples.m_shapeToMotion, center);
            hkVector4q centerWorld;
            SetTransformedPoint(centerWorld, samples.m_kMotionTransform, centerMotion);

            hkVector4q sweptMin;
            sweptMin.setMin4(center, centerWorld);
            hkVector4q sweptMax;
            sweptMax.setMax4(center, centerWorld);

            const hkMotionStateq* motionState = samples.m_kMotionState;
            hkVector4u comLocal;
            comLocal.m_f = motionState->m_vCenterOfMassLocal;

            for (int k = 0; k < samples.m_numQsTransforms; k++)
            {
                hkVector4q relCenter;
                relCenter.setSub4(centerMotion, comLocal.v());
                hkVector4q p;
                p.setAddMul4(comLocal.v(), relCenter, samples.m_kTransforms[k].m_vTranslation.getSimdAt3());
                hkVector4q pWorld;
                SetTransformedPoint(pWorld, samples.m_kTransforms[k], p);
                sweptMin.setMin4(sweptMin, pWorld);
                sweptMax.setMax4(sweptMax, pWorld);
            }

            hkSimdRealq len = halfExtents.length3Simd();
            hkVector4q radius;
            radius.m_vComponents = _mm_shuffle_ps(len.m_vValue, len.m_vValue, 0);
            hkVector4q expand;
            expand.setAddMul4(halfExtents, radius, motionState->m_kDeltaAngle.getSimdAt3());
            radius.setMin4(radius, expand);

            sweptMin.setSub4(sweptMin, radius);
            sweptMax.setAdd4(sweptMax, radius);
            aabb.m_kMinimumCorner.setMin4(sweptMin, sweptMin);
            aabb.m_kMaximumCorner.setMax4(sweptMax, sweptMax);
        }

        const hkpProcessCollisionInputq* in = input.m_pRayCastInput;
        hkAabbUint32Key* out = &aabbsOut[i];
        quantizeAabb(aabb,in,out);
        out->m_uiCollisionShapeKey = key;
    }
}
