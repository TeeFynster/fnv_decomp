#define FNV64_HKARRAY_FINISH_SPEC throw() // Exe 0x00dfd800 has no array-construction unwind actions.
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form

// src/staging/blk_00de0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00de0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00de0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include "../../include/FinishingFlag.h"
#include "../../include/hkStringPtr.h"
#include "../../include/hkBaseObject.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkVector4.h"
#include "../../include/hkpCdBody.h"
#include "../../include/hkpFixedBufferCdPointCollector.h"
#include "../../include/hkpCollisionDispatcher.h"
#include "../../include/hkpShape.h"
#include "../../include/hkxAttributeHolder.h"
#include "../../include/hkxNode.h"
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;

extern hkReal DAT_0104da48;
extern hkReal DAT_0104da4c;
extern const void* DAT_0108f288[];

inline void* operator new(size_t, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}

inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
static inline hkReal length3(const hkVector4& vector)
{
    const __m128 sq = _mm_mul_ps(vector.m_vComponents, vector.m_vComponents);
    const __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    hkReal r;
    _mm_store_ss(&r, _mm_sqrt_ss(s));
    return r;
}
inline const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
inline hkpShapeType hkpShape::getType() const
{
    return *reinterpret_cast<const hkpShapeType*>(&m_type);
}
inline hkpCdPointCollector::hkpCdPointCollector()
{}
inline hkpCdPointCollector::~hkpCdPointCollector()
{}

#include "../../include/RootContactPoint.h"

inline hkpFixedBufferCdPointCollector::hkpFixedBufferCdPointCollector(RootContactPoint* buffer, int capacity)
{
    *reinterpret_cast<const void***>(this) = DAT_0108f288;
    m_fEarlyOutDistance = DAT_0104da48;
    m_pPointBuffer = buffer;
    m_pPointBufferEnd = buffer;
    m_pRayCursor = capacity;
    m_iPointCount = 0;
}

struct RealIntegerData
{
    hkReal m_fValue;
    int m_iValue;
    int m_unk08;
    int m_unk0c;
};

struct CollisionAgentContext
{
    hkpCollisionDispatcher* m_pCollisionDispatcher;
    int m_collisionQuality;
    hkReal m_fScalar;
    void* m_iFilter;
    int m_aiValues[16];
};

struct ShapeSweepParameters : public CollisionAgentContext
{
    hkVector4 m_path;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fStartPointTolerance;
    const RealIntegerData* m_pConfiguration;
};

struct CastSettings
{
    int m_unk00[8];
    hkReal m_fScalar;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fHitDistance;
    int m_maxIterations;
};

struct CastJob
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    RootContactPoint* m_hitsA;
    int m_capacityA;
    int m_numHitsA;
    RootContactPoint* m_hitsB;
    int m_capacityB;
    int m_numHitsB;
};

static inline void memCpy16(void* dst, const void* src, int numQuads)
{
    unsigned int* d = (unsigned int*)dst;
    const unsigned int* s = (const unsigned int*)src;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}

// @fnv 0x00df7760
// src: XBOX_PDB 0x00df7760
void hkCpuPairLinearCastImplementation(const CastSettings* settings, const CollisionAgentContext* in, CastJob* jobs, int numJobs)
{
    RootContactPoint shapeB[16];
    RootContactPoint idx[16];
    __declspec(align(4)) unsigned char storageA[sizeof(hkpFixedBufferCdPointCollector)];
    __declspec(align(4)) unsigned char storageB[sizeof(hkpFixedBufferCdPointCollector)];
    hkpFixedBufferCdPointCollector& collA = *::new (storageA) hkpFixedBufferCdPointCollector(idx, 16);
    hkpFixedBufferCdPointCollector& collB = *::new (storageB) hkpFixedBufferCdPointCollector(shapeB, 16);

    RealIntegerData disp;
    disp.m_iValue = settings->m_maxIterations;
    disp.m_fValue = settings->m_fHitDistance;

    ShapeSweepParameters bufB;
    bufB.m_fMaxExtraPenetration = DAT_0104da4c;
    bufB.m_fScalar = settings->m_fScalar;
    bufB.m_collisionQuality = 0;
    bufB.m_pCollisionDispatcher = in->m_pCollisionDispatcher;
    bufB.m_iFilter = in->m_iFilter;
    bufB.m_pConfiguration = &disp;

    for (int i = 0; i < numJobs; i++)
    {
        CastJob& p = jobs[i];
        const hkpShape* res = p.m_pBodyA->getShape();
        const hkpShape* input = p.m_pBodyB->getShape();
        bufB.m_path.setSub4(p.m_vTo, p.m_vFrom);
        bufB.m_fStartPointTolerance = length3(bufB.m_path);
        bufB.m_fScalar = settings->m_fScalar;
        bufB.m_fMaxExtraPenetration = settings->m_fMaxExtraPenetration;
        ::new (&collA) hkpFixedBufferCdPointCollector(idx, p.m_capacityA);
        if (p.m_hitsB)
        {
            ::new (&collB) hkpFixedBufferCdPointCollector(shapeB, p.m_capacityB);
        }
        hkpCollisionDispatcher* func = in->m_pCollisionDispatcher;
        hkpCollisionDispatcher::LinearCastFunc bodyA = func->m_agent2Funcs[func->m_agent2TypeMap[res->getType()][input->getType()]].m_pLinearCastFunc;
        bodyA(*p.m_pBodyA, *p.m_pBodyB, bufB, collA, p.m_hitsB ? &collB : 0);

        p.m_numHitsA = (hkUint16)collA.m_iPointCount;
        p.m_numHitsB = (hkUint16)collB.m_iPointCount;
        if (p.m_numHitsA > 0)
        {
            memCpy16(p.m_hitsA, idx, p.m_numHitsA * (sizeof(RootContactPoint) / 16));
        }
        if (p.m_hitsB && p.m_numHitsB > 0)
        {
            memCpy16(p.m_hitsB, shapeB, p.m_numHitsB * (sizeof(RootContactPoint) / 16));
        }
    }
}


inline hkxAttributeHolder::hkxAttributeHolder(FinishingFlag flag) throw()
    : hkReferencedObject(flag), attributes(flag)
{}
inline hkxNode::hkxNode(FinishingFlag flag) throw()
    : hkxAttributeHolder(flag), name(flag), keyFrames(flag), children(flag), annotations(flag), userProperties(flag)
{}

// @fnv 0x00dfd800
// src: GUESS 0x00dfd800 (confidence: low)
void* __cdecl Object_ProcessAndReturnValue_00dfd800()
{
    __declspec(align(16)) unsigned char storage[sizeof(hkxNode)];
    ::new (storage) hkxNode(FinishingFlag(0));
    return *reinterpret_cast<void**>(storage);
}
