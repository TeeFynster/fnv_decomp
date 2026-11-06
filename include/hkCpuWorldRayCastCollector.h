#pragma once

#include "hkpBroadPhaseCastCollector.h"
#include "hkKdTreeCastCollector.h"
#include "hkAabbTreeQueryUtils.h"
#include "hkVector4.h"

class hkpFixedBufferRayHitCollector;

class hkCpuWorldRayCastCollector
    : public hkpBroadPhaseCastCollector,
      public hkKdTreeCastCollector,
      public hkAabbTreeQueryUtils<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Collector,
      public hkAabbTreeQueryUtils<hkAabbTreeData::hkAabbTreeAabb16, unsigned short>::Collector
{
public:
    int m_iFilter;
    float m_fHitFraction;
    int m_bHasHit;
    int m_iFieldAfterHasHit;
    int m_iFieldBeforeResult;
    int m_result;
    int m_iFieldAfterResult;
    int unk2c;
    hkVector4 m_workFrom;
    hkVector4 m_workTo;
    int m_workFilter;
    int m_workCollection;
    int unk58;
    int unk5c;
    hkpFixedBufferRayHitCollector* m_fixedBufferRayHitFilterCollector;
    int unk64;
    int unk68;
    int unk6c;
    hkVector4 m_fEarlyOutHitFraction;

    hkCpuWorldRayCastCollector();
    virtual float ReleaseCollector(const hkpBroadPhaseHandle*, int);
    virtual hkBool ReportHit(hkPrimitiveId);
    virtual hkBool DidHit();
    virtual hkReal GetHitFraction();
    virtual hkReal GetHitDistance(
        const hkAabbTree<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Node*);
    virtual hkReal GetHitDistance(
        const hkAabbTree<hkAabbTreeData::hkAabbTreeAabb16, unsigned short>::Node*);
};
