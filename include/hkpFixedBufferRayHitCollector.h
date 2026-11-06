#pragma once

#include <cstddef>
#include "hkpRayHitCollector.h"
#include "hkMonitorStream.h"

struct WorldRayCastOutput;
class hkpCollidable;

class hkpFixedBufferRayHitCollector : public hkpRayHitCollector
{
public:
    hkpFixedBufferRayHitCollector(WorldRayCastOutput* buffer, int capacity);
    hkpFixedBufferRayHitCollector(int buffer, int capacity);

    static void* __cdecl operator new(std::size_t nbytes);
    static void __cdecl addRayHitImplementation(
        const hkpCdBody& cdBody,
        const RayCastHitResult& hitInfo,
        hkpFixedBufferRayHitCollector* collector);

    virtual void CollectRayHit(const hkpCdBody& cdBody, const RayCastHitResult& hitInfo);

    hkPadSpu<WorldRayCastOutput*> m_pRayHitBuffer;
    hkPadSpu<WorldRayCastOutput*> m_pHitBufferEnd;
    hkPadSpu<int> m_pRayCursor;
    hkPadSpu<int> m_iHitCount;
    hkPadSpu<const hkpCollidable*> m_pCollidable;
};
