#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// src/havok/common/base/system/io/ostream/hkostream_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/system/io/ostream/hkostream.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The VC9 intrinsic header's byte-array views cause /GS to instrument every
// local SIMD vector. Keep the original float-only compiler intrinsic type.
#define _INCLUDED_MM2
// Exe 0x00da71c0 FUN_00da71c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    extern LocalM128 _mm_add_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_sub_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_mul_ps(LocalM128 _A, LocalM128 _B);
    extern LocalM128 _mm_shuffle_ps(LocalM128 _A, LocalM128 _B, unsigned int _Imm8);
    extern LocalM128 _mm_set_ps1(float _A);
    extern LocalM128 _mm_setr_ps(float _A, float _B, float _C, float _D);
    extern LocalM128 _mm_load_ss(float const* _A);
};

#include "../../../../../../../include/CodeInfo.h"
#include "../../../../../../../include/bhkMoppBvTreeShape.h"
#include "../../../../../../../include/hkpMoppCode.h"
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/NiBinaryStream.h"
#include "../../../../../../../include/NiStream.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkError.h"
#include "../../../../../../../include/hkErrStream.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkSingleton.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMoppBvTreeShapeBase.h"
#include "../../../../../../../include/hkVector4_X.h"
#include "../../../../../../../include/hkpBvTreeShape.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCdPointCollector.h"
#include "../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../include/hkpMoppBvTreeShape.h"
#include "../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
typedef float hkReal_X;
typedef unsigned int hkUint32_X;
typedef LocalM128 hkQuadReal;
typedef const hkVector4_X& hkVector4Parameter;

typedef const hkSimdReal& hkSimdRealParameter;

__forceinline hkSimdReal::hkSimdReal() {}
__forceinline LocalM128 hkSimdReal::broadcast() const
{
    const LocalM128 value = *reinterpret_cast<const LocalM128*>(&x);
    return _mm_shuffle_ps(value, value, 0);
}
// Select the scalar representation without the shared float/const-float overload ambiguity.
__forceinline hkSimdReal ScalarValue(float x)
{
    hkSimdReal value;
    *reinterpret_cast<LocalM128*>(&value.x) = _mm_load_ss(&x);
    return value;
}
__forceinline hkVector4_X::operator LocalM128() const
{
    return m_vComponents;
}
template <typename T> __forceinline T& hkSingleton<T>::GetMonitorStream()
{
    return *s_instance;
}

__forceinline void hkVector4_X::operator=(const hkVector4_X& v)
{
    m_vComponents = v.m_vComponents;
}
__forceinline void hkVector4_X::set(hkReal_X a, hkReal_X b, hkReal_X c, hkReal_X d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
__forceinline void hkVector4_X::setAll3(hkReal_X a)
{
    m_vComponents = _mm_set_ps1(a);
}
__forceinline void hkVector4_X::setAdd4(const hkVector4_X& v0, const hkVector4_X& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void hkVector4_X::sub4(const hkVector4_X& v)
{
    const LocalM128 current = m_vComponents;
    const LocalM128 other = v.m_vComponents;
    m_vComponents = _mm_sub_ps(current, other);
}
__forceinline void hkVector4_X::setSub4(const hkVector4_X& v0, const hkVector4_X& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void hkVector4_X::mul4(const hkVector4_X& v)
{
    m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
}
__forceinline void hkVector4_X::setMul4(const hkVector4_X& a, const hkVector4_X& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4_X::mul4(hkSimdRealParameter s)
{
    m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
}
__forceinline void hkVector4_X::setInterpolate4(const hkVector4_X& v0, const hkVector4_X& v1, hkSimdRealParameter _t)
{
    static __declspec(align(16)) const float cw[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    hkQuadReal t = _t.broadcast();
    hkQuadReal s = _mm_sub_ps(*(const hkQuadReal*)&cw, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
__forceinline hkReal_X& hkVector4_X::operator()(int a)
{
    return reinterpret_cast<hkReal_X*>(&m_vComponents)[a];
}
__forceinline const hkReal_X& hkVector4_X::operator()(int a) const
{
    return reinterpret_cast<const hkReal_X*>(&m_vComponents)[a];
}

#include "../../../../../../../include/hkpBufferSize.h"
struct __declspec(align(16)) hkpShapeBuffer
{
    unsigned int w[HK_SHAPE_BUFFER_SIZE / 4];
};
class hkAabb;
typedef hkUint32_X hkpShapeKey;

__forceinline hkpShapeType hkpShape::getType() const
{
    return static_cast<hkpShapeType>(*reinterpret_cast<const unsigned int*>(&m_type));
}

__forceinline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
__forceinline hkpCdBody::hkpCdBody(const hkpCdBody* parent)
{
    m_parent = parent;
    m_pMotionState = parent->m_pMotionState;
}
__forceinline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, hkpShapeKey key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}
class hkpContactMgr;
class hkpCollisionAgent;
struct CollisionAgentContext
{
  public:
    hkReal_X getTolerance() const
    {
        return m_fScalar;
    }

  public:
    hkPadSpu<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    hkPadSpu<hkBool32> m_collisionQuality;
    hkPadSpu<hkReal_X> m_fScalar;
    hkPadSpu<const hkpCollisionFilter*> m_iFilter;
};
class hkpContactMgrFactory;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;

__forceinline hkpCollisionDispatcher::LinearCastFunc hkpCollisionDispatcher::getLinearCastFunc(hkpShapeType typeA,
                                                                                 hkpShapeType typeB) const
{
    ;
    ;
    int idx = m_agent2TypeMap[typeA][typeB];
    return m_agent2Funcs[idx].m_pLinearCastFunc;
}

__forceinline hkReal_X hkpCdPointCollector::getEarlyOutDistance() const
{
    return m_fEarlyOutDistance;
}
struct ShapeSweepParameters : public CollisionAgentContext
{
};

__forceinline const hkpShapeCollection* hkpMoppBvTreeShape::getShapeCollection() const
{
    return static_cast<const hkpShapeCollection*>(m_pChildAtom.getChild());
}

enum hkpMoppCommands
{
    HK_MOPP_RETURN = 0,
    HK_MOPP_SCALE1 = 1,
    HK_MOPP_SCALE2,
    HK_MOPP_SCALE3,
    HK_MOPP_SCALE4,
    HK_MOPP_JUMP8 = 5,
    HK_MOPP_JUMP16,
    HK_MOPP_JUMP24,
    HK_MOPP_JUMP_CHUNK = 0xc,
    HK_MOPP_JUMP_CHUNK32 = 0x70
};
class MoppPrimitiveQueryContext
{
  public:
    static int __cdecl read24(const unsigned char* pc)
    {
        return (pc[0] << 16) + (pc[1] << 8) + pc[2];
    }
    void* m_pPrimitiveInfoArray;
    int unk04;
    int unk08;
    int unk0C;
};
struct VectorPropertyRecord
{
    hkVector4_X m_kVectorBeforeIndex;
    hkVector4_X SetCenterPosition;
    float m_fValueAtOffset20;
    int m_iIndex;
    float m_kVectorAfterIndex;
    hkUint32_X m_uiPropertyCount;
    hkUint32_X m_kProperties[1];
    __declspec(noinline) VectorPropertyRecord& operator=(
        const VectorPropertyRecord& o)
    {
        m_kVectorBeforeIndex = o.m_kVectorBeforeIndex;
        SetCenterPosition = o.SetCenterPosition;
        m_fValueAtOffset20 = o.m_fValueAtOffset20;
        m_iIndex = o.m_iIndex;
        m_kVectorAfterIndex = o.m_kVectorAfterIndex;
        m_uiPropertyCount = o.m_uiPropertyCount;
        m_kProperties[0] = o.m_kProperties[0];
        return *this;
    }
};
struct TwoPointVectorBundles
{
    hkVector4_X m_kPointBundles[2];
};
class MoppCastMachine : public MoppPrimitiveQueryContext
{
  public:
    struct MoppCastQueryData
    {
        hkVector4_X m_vFrom;
        hkVector4_X m_vTo;
        hkVector4_X SetCenterPosition;
        const ShapeSweepParameters* m_pCollisionInput;
        const hkpCdBody* m_pFirstCastBody;
        const hkpCdBody* m_pSecondCastBody;
    };
    const hkpMoppCode* m_pMoppCode;
    float m_vRayDirectionVector;
    hkpShapeType m_iRayDirectionIndex;
    float m_fFirstRayCastValue;
    float m_fSecondRayCastValue;
    hkpCdPointCollector* m_pPointCollector;
    hkpCdPointCollector* m_pClosestPointCollector;
    const MoppCastQueryData* m_pRayCastInput;
    int m_iCurrentChunkId;

  protected:
    void AddHit(hkUint32_X id, const hkUint32_X properties[1], unsigned long extra);
    void ProcessMoppCommands_00da71c0(const VectorPropertyRecord* query, const unsigned char* PC,
                      TwoPointVectorBundles fQuery[1], int chunkOffset);
};
__forceinline void MoppCastMachine::AddHit(hkUint32_X key, const hkUint32_X properties[1],
                                           unsigned long chunkOffset_unused)
{
    const hkpShapeContainer* shapeContainer = 0;
    const hkpMoppBvTreeShape* moppBvTree =
        static_cast<const hkpMoppBvTreeShape*>(m_pRayCastInput->m_pSecondCastBody->getShape());
    shapeContainer = moppBvTree->getShapeCollection();
    hkpShapeBuffer shapeBuffer;
    const hkpShape* childShape = shapeContainer->GetShapeForKey(key, shapeBuffer);
    if (!m_pRayCastInput->m_pCollisionInput->m_iFilter->IsCollisionEnabled(
            *m_pRayCastInput->m_pCollisionInput, *m_pRayCastInput->m_pFirstCastBody,
            *m_pRayCastInput->m_pSecondCastBody, *shapeContainer, key))
    {
        return;
    }
    hkpCdBody childBodyB(m_pRayCastInput->m_pSecondCastBody);
    childBodyB.SetCollisionShapeAndKey(childShape, key);
    hkpShapeType typeB = childShape->getType();
    hkpCollisionDispatcher::LinearCastFunc linCastFunc =
        m_pRayCastInput->m_pCollisionInput->m_pCollisionDispatcher->getLinearCastFunc(m_iRayDirectionIndex, typeB);
    linCastFunc(*m_pRayCastInput->m_pFirstCastBody, childBodyB, *m_pRayCastInput->m_pCollisionInput, *m_pPointCollector,
                m_pClosestPointCollector);
    m_fFirstRayCastValue = m_pPointCollector->getEarlyOutDistance();
}
// @fnv 0x00da71c0
// src: GUESS 0x00da71c0 (confidence: low)
void MoppCastMachine::ProcessMoppCommands_00da71c0(const VectorPropertyRecord* query, const unsigned char* PC,
                                   TwoPointVectorBundles fQuery[1], int chunkOffset)
{
    VectorPropertyRecord scaledQuery;
    do
    {
        const hkpMoppCommands command = hkpMoppCommands(PC[0]);
        int tdir = 999;
        int offsetLB;
        int offsetRB;
        hkReal_X positionl;
        hkReal_X positionh;
        hkReal_X foffsetl;
        hkReal_X foffseth;
        int offsetl;
        int offseth;
        switch (command)
        {
        case 0x13: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x14: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(1) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2));
            positionh = (fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2));
            goto do_compareN4;
        }
        case 0x15: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = (fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](2));
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x16: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(2)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x17: {
            foffseth = hkReal_X(PC[1] * 2);
            foffsetl = hkReal_X(PC[2] * 2);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x18: {
            foffseth = hkReal_X(PC[1] * 2 - 255);
            foffsetl = hkReal_X(PC[2] * 2 - 255);
            const hkReal_X allExtents = (query->SetCenterPosition(0) + query->SetCenterPosition(1)) * 2.0;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1);
            goto do_compareN4;
        }
        case 0x19: {
            foffseth = hkReal_X(PC[1] * 3);
            foffsetl = hkReal_X(PC[2] * 3);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1a: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) + fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) + fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1b: {
            foffseth = hkReal_X(PC[1] * 3 - 255);
            foffsetl = hkReal_X(PC[2] * 3 - 255);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) + fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) + fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x1c: {
            foffseth = hkReal_X(PC[1] * 3 - 510);
            foffsetl = hkReal_X(PC[2] * 3 - 510);
            const hkReal_X allExtents = query->m_fValueAtOffset20;
            foffsetl -= allExtents;
            foffseth += allExtents;
            positionl = fQuery->m_kPointBundles[0](0) - fQuery->m_kPointBundles[0](1) - fQuery->m_kPointBundles[0](2);
            positionh = fQuery->m_kPointBundles[1](0) - fQuery->m_kPointBundles[1](1) - fQuery->m_kPointBundles[1](2);
            goto do_compareN4;
        }
        case 0x20:
        case 0x21:
        case 0x22:
            tdir = command - 0x20;
            foffsetl = hkReal_X(PC[1]);
            foffseth = foffsetl + 1.0;
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            PC += 3;
            offsetLB = 0;
            offsetRB = PC[-1];
            goto do_compare;
        case 0x23:
        case 0x24:
        case 0x25:
            tdir = command - 0x23;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
            offsetLB = (PC[3] << 8) + PC[4];
            PC += 7;
            offsetRB = (PC[-2] << 8) + PC[-1];
            goto do_compare;
        case 0x10:
        case 0x11:
        case 0x12:
            tdir = command - 0x10;
            foffseth = hkReal_X(PC[1]);
            foffsetl = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            positionl = (&fQuery->m_kPointBundles[0](0))[tdir];
            positionh = (&fQuery->m_kPointBundles[1](0))[tdir];
        do_compareN4:
            PC += 4;
            offsetLB = 0;
            offsetRB = PC[-1];
        do_compare:
            if (positionh < foffsetl && positionl < foffsetl)
            {
                PC += offsetLB;
                continue;
            }
            PC += offsetRB;
            if (positionl > foffseth && positionh > foffseth)
            {
                continue;
            }
            {
                const hkReal_X la = positionl - foffseth;
                const hkReal_X ha = positionl - foffsetl;
                const hkReal_X lb = positionh - foffseth;
                const hkReal_X hb = positionh - foffsetl;
                TwoPointVectorBundles leftFloat;
                leftFloat.m_kPointBundles[0] = fQuery->m_kPointBundles[0];
                leftFloat.m_kPointBundles[1] = fQuery->m_kPointBundles[1];
                if (la < lb)
                {
                    if (la * lb < 0.0)
                    {
                        const hkReal_X ratio = la / (la - lb);
                        leftFloat.m_kPointBundles[1].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], ScalarValue(ratio));
                    }
                    ProcessMoppCommands_00da71c0(query, PC - offsetRB + offsetLB, &leftFloat, chunkOffset);
                    if (ha * hb < 0.0)
                    {
                        const hkReal_X ratio = ha / (ha - hb);
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], ScalarValue(ratio));
                    }
                    if (m_fFirstRayCastValue < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = m_fFirstRayCastValue;
                        const hkReal_X fraction = m_fFirstRayCastValue;
                        hkVector4_X hitpoint;
                        hitpoint.setInterpolate4(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, ScalarValue(fraction));
                        fQuery->m_kPointBundles[1].setSub4(
                            hitpoint, reinterpret_cast<const hkVector4_X&>(m_pMoppCode->m_info.m_offset));
                        fQuery->m_kPointBundles[1].mul4(ScalarValue(query->m_kVectorAfterIndex));
                        fQuery->m_kPointBundles[1].m_vComponents = _mm_sub_ps(
                            fQuery->m_kPointBundles[1].m_vComponents, query->m_kVectorBeforeIndex.m_vComponents);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] < foffsetl)
                        {
                            goto end_of_function;
                        }
                    }
                    continue;
                }
                else
                {
                    if (ha * hb < 0.0)
                    {
                        const hkReal_X ratio = ha / (ha - hb);
                        leftFloat.m_kPointBundles[1].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                     fQuery->m_kPointBundles[1], ScalarValue(ratio));
                    }
                    ProcessMoppCommands_00da71c0(query, PC, &leftFloat, chunkOffset);
                    if (la * lb < 0.0)
                    {
                        const hkReal_X ratio = la / (la - lb);
                        fQuery->m_kPointBundles[0].setInterpolate4(fQuery->m_kPointBundles[0],
                                                                   fQuery->m_kPointBundles[1], ScalarValue(ratio));
                    }
                    if (m_fFirstRayCastValue < m_fSecondRayCastValue)
                    {
                        m_fSecondRayCastValue = m_fFirstRayCastValue;
                        const hkReal_X fraction = m_fFirstRayCastValue;
                        hkVector4_X hitpoint;
                        hitpoint.setInterpolate4(m_pRayCastInput->m_vFrom, m_pRayCastInput->m_vTo, ScalarValue(fraction));
                        fQuery->m_kPointBundles[1].setSub4(
                            hitpoint, reinterpret_cast<const hkVector4_X&>(m_pMoppCode->m_info.m_offset));
                        fQuery->m_kPointBundles[1].mul4(ScalarValue(query->m_kVectorAfterIndex));
                        fQuery->m_kPointBundles[1].sub4(query->m_kVectorBeforeIndex);
                        if (tdir < 3 && (&fQuery->m_kPointBundles[1](0))[tdir] > foffseth)
                        {
                            goto end_of_function;
                        }
                    }
                    PC = PC - offsetRB + offsetLB;
                    continue;
                }
            }
        case 0x29:
        case 0x2a:
        case 0x2b:
            tdir = command - 0x29;
            {
                foffsetl = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 1)) * m_vRayDirectionVector;
                foffseth = hkReal_X(MoppPrimitiveQueryContext::read24(PC + 4)) * m_vRayDirectionVector;
                foffsetl *= query->m_kVectorAfterIndex;
                foffseth *= query->m_kVectorAfterIndex;
                foffsetl -= query->m_kVectorBeforeIndex(tdir);
                foffseth -= query->m_kVectorBeforeIndex(tdir);
                foffsetl -= query->SetCenterPosition(tdir);
                foffseth += query->SetCenterPosition(tdir);
                PC += 7;
            }
            goto doCut;
        case 0x26:
        case 0x27:
        case 0x28:
            tdir = command - 0x26;
            foffsetl = hkReal_X(PC[1]);
            foffseth = hkReal_X(PC[2]);
            foffsetl -= query->SetCenterPosition(tdir);
            foffseth += query->SetCenterPosition(tdir);
            PC += 3;
        doCut:
            positionl = fQuery->m_kPointBundles[0](tdir);
            positionh = fQuery->m_kPointBundles[1](tdir);
            {
                int sign;
                if (positionl < positionh)
                {
                    if (positionh < foffsetl || positionl > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 0;
                }
                else
                {
                    if (positionl < foffsetl || positionh > foffseth)
                    {
                        goto end_of_function;
                    }
                    sign = 1;
                }
                const hkVector4_X rayStartPoint = fQuery->m_kPointBundles[0];
                const hkVector4_X rayEndPoint = fQuery->m_kPointBundles[1];
                {
                    const hkReal_X R0 = positionl - foffseth;
                    const hkReal_X R1 = positionh - foffseth;
                    if (R0 * R1 < 0.0)
                    {
                        const hkReal_X ratio = R0 / (R0 - R1);
                        fQuery->m_kPointBundles[1 - sign].setInterpolate4(rayStartPoint, rayEndPoint, ScalarValue(ratio));
                    }
                }
                {
                    const hkReal_X L0 = positionl - foffsetl;
                    const hkReal_X L1 = positionh - foffsetl;
                    if (L0 * L1 < 0.0)
                    {
                        const hkReal_X ratio = L0 / (L0 - L1);
                        fQuery->m_kPointBundles[sign].setInterpolate4(rayStartPoint, rayEndPoint, ScalarValue(ratio));
                    }
                }
            }
            continue;
        case 5:
            offsetl = PC[1];
            PC += 2;
            PC += offsetl;
            continue;
        case 6:
            offseth = PC[1];
            offsetl = PC[2];
            PC += 3;
            PC += (offseth << 8) + offsetl;
            continue;
        case 7: {
            offseth = PC[1];
            const hkUint32_X offsetm = PC[2];
            offsetl = PC[3];
            PC += 4;
            PC += (offseth << 16) + (offsetm << 8) + offsetl;
        }
            continue;
        case 0xc: {
            const int chunkId = (PC[1] << 8) | PC[2];
            chunkOffset = chunkId << 9;
            goto jumpRecheckCache;
        }
        case 0x70:
            chunkOffset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
        jumpRecheckCache: {
            const unsigned char* jumpAddress = m_pMoppCode->m_data.m_data + chunkOffset;
            PC = jumpAddress;
        }
            continue;
        case 0xd:
            PC += 5;
            continue;
        case 1:
        case 2:
        case 3:
        case 4: {
            const hkUint32_X shift = command;
            hkVector4_X extraOffset;
            extraOffset.set(hkReal_X(PC[1]), hkReal_X(PC[2]), hkReal_X(PC[3]), 0.0f);
            hkVector4_X f4;
            const hkReal_X f = hkReal_X(1 << shift);
            f4.setAll3(f);
            fQuery->m_kPointBundles[0].sub4(extraOffset);
            fQuery->m_kPointBundles[1].sub4(extraOffset);
            fQuery->m_kPointBundles[0].mul4(f4);
            fQuery->m_kPointBundles[1].mul4(f4);
            scaledQuery.m_kVectorBeforeIndex.setAdd4(query->m_kVectorBeforeIndex, extraOffset);
            scaledQuery.m_kVectorBeforeIndex.mul4(f4);
            scaledQuery.m_iIndex = query->m_iIndex + shift;
            scaledQuery.m_kVectorAfterIndex = query->m_kVectorAfterIndex * f;
            scaledQuery.SetCenterPosition.setMul4(f4, query->SetCenterPosition);
            scaledQuery.m_fValueAtOffset20 = query->m_fValueAtOffset20 * f;
            for (int p = 0; p < 1; p++)
            {
                scaledQuery.m_kProperties[p] = query->m_kProperties[p];
            }
            scaledQuery.m_uiPropertyCount = query->m_uiPropertyCount;
            query = &scaledQuery;
            PC += 4;
        }
            continue;
        case 0:
            goto end_of_function;
        case 0x50:
            offsetl = PC[1];
            goto add_Terminal;
        case 0x51:
            offseth = PC[1];
            offseth <<= 8;
            offsetl = PC[2];
            offsetl += offseth;
            goto add_Terminal;
        case 0x52:
            offsetl = PC[1];
            offsetl <<= 16;
            offseth = PC[2];
            offseth <<= 8;
            offseth += PC[3];
            offsetl += offseth;
            goto add_Terminal;
        case 0x53:
            offsetl = PC[1];
            offsetl <<= 24;
            offseth = PC[2];
            offseth <<= 16;
            offsetl += offseth;
            offseth = PC[3];
            offsetl += PC[4];
            offseth <<= 8;
            offsetl += offseth;
            goto add_Terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            offsetl = command - 0x30;
        add_Terminal:
            offsetl += query->m_uiPropertyCount;
            {
                hkUint32_X chunkId = chunkOffset >> 9;
                hkUint32_X keyRemap = ((chunkId << 8) & m_iCurrentChunkId) | offsetl;
                AddHit(keyRemap, query->m_kProperties, 0);
            }
            goto end_of_function;
        case 9: {
            const hkUint32_X offset = PC[1];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 2;
        }
            continue;
        case 0xa: {
            const hkUint32_X offset = (PC[1] << 8) + PC[2];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount += offset;
            PC += 3;
        }
            continue;
        case 0xb: {
            const hkUint32_X offset = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_uiPropertyCount = offset;
            PC += 5;
        }
            continue;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            hkUint32_X property;
            hkUint32_X value;
            property = PC[0] - 0x60;
            value = PC[1];
            PC += 2;
            scaledQuery.m_kProperties[property] = value;
        propertyCopy:
            const hkUint32_X v = scaledQuery.m_kProperties[0];
            if (query != &scaledQuery)
            {
                scaledQuery = *query;
                query = &scaledQuery;
            }
            scaledQuery.m_kProperties[0] = v;
        }
            continue;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67: {
            const hkUint32_X property = PC[0] - 0x64;
            const hkUint32_X value = (PC[1] << 8) + PC[2];
            scaledQuery.m_kProperties[property] = value;
            PC += 3;
            goto propertyCopy;
        }
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b: {
            const hkUint32_X property = PC[0] - 0x68;
            const hkUint32_X value = (PC[1] << 24) + (PC[2] << 16) + (PC[3] << 8) + PC[4];
            scaledQuery.m_kProperties[property] = value;
            PC += 5;
            goto propertyCopy;
        }
        default:
            do
            {
                unsigned int assertBuf[128];
                void* ostrStorage[sizeof(hkErrStream) / sizeof(void*)];
                hkErrStream& ostr = *reinterpret_cast<hkErrStream*>(ostrStorage);
                // VC9 supports a direct constructor call without automatic destruction.
                ostr.hkErrStream::hkErrStream(assertBuf, 512);
                ostr.hkOstream::operator<<(
                    "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
                if (hkError::GetMonitorStream().message(hkError::MESSAGE_ERROR, 0x1298fedd, (const char*)assertBuf,
                                                        ".\\Collide\\Mopp\\Machine\\hkpMoppAabbCastVirtualMachine.cpp",
                                                        521))
                {
                    __debugbreak();
                    ostr.hkOstream::~hkOstream();
                }
                else
                {
                    ostr.hkOstream::~hkOstream();
                }
            } while (0);
            continue;
        }
    } while (1);
end_of_function:;
}
