#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"

inline hkpShapeType hkpShape::getType() const
{
    return reinterpret_cast<const hkpShapeType&>(m_type);
}


// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreeworldlinearcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/kdtreecollector/hkpkdtreeworldlinearcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ThresholdRecord
{
    unsigned int unk00;
    float value;
};
struct ThresholdHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ThresholdRecord* record;
    unsigned char* WriteThresholdFlag(unsigned char* output);
};
// Writes 1 to output when record->value is below 1.0f, otherwise 0, and returns output.
// @fnv 0x00d983f0
unsigned char* ThresholdHolder::WriteThresholdFlag(unsigned char* pucOutput)
{
    unsigned char result;
    if (record->value < 1.0f)
        result = 1;
    else
        result = 0;
    *pucOutput = result;
    return pucOutput;
}

struct CpuScalar
{
    unsigned int unk00;
    float value;
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    CpuScalar* value;
    float hkpKdTreeWorldLinearCaster_getHitFraction();
};
// @fnv 0x00d98420
// src: HAVOK_SRC 0x00d98420
float CpuObject::hkpKdTreeWorldLinearCaster_getHitFraction()
{
    return value->value;
}

// Only the dispatch pointer at +0 is read here; no shared linear-cast input header exists yet.
struct LinearCastInputPrefix
{
    hkpCollisionDispatcher* m_pCollisionDispatcher;
};

class hkpKdTreeWorldLinearCaster
{
  public:
    int unk00, unk04;
    // The original calls vtable slot 1, the hkpCollidableCollidableFilter interface.
    hkpCollidableCollidableFilter* m_iFilter;
    hkpCdPointCollector* m_kCollector;
    hkpCdPointCollector* m_startCollector;
    const hkpCollidable* m_pBodyA;
    int m_iAgentTypeA;
    int unk1C;
    LinearCastInputPrefix m_pRayCastInput;

    hkBool QueryPenetrations(const hkpCollidable& bodyB);
};

// Checks the collidable filter, then dispatches the five-argument linear cast at agent-table offset +0x0c.
// @fnv 0x00d98430
hkBool hkpKdTreeWorldLinearCaster::QueryPenetrations(const hkpCollidable& bodyB)
{
    const hkpShape* shapeB = bodyB.m_pCollisionShape;
    if (shapeB && m_pBodyA != &bodyB && m_iFilter->IsCollisionEnabled(*m_pBodyA, bodyB))
    {
        hkpCollisionDispatcher* pDispatcher = m_pRayCastInput.m_pCollisionDispatcher;
        pDispatcher->m_agent2Funcs[pDispatcher->m_agent2TypeMap[m_iAgentTypeA][shapeB->getType()]]
            .m_pLinearCastFunc(reinterpret_cast<const hkpCdBody&>(*m_pBodyA),
                              reinterpret_cast<const hkpCdBody&>(bodyB),
                              reinterpret_cast<const ShapeSweepParameters&>(m_pRayCastInput),
                              *m_kCollector, m_startCollector);
        return true;
    }
    return false;
}
