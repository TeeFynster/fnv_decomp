#pragma once

#include "hkpPhantom.h"
#include "hkAabb.h"
#include "hkBool.h"
#include "hkaAnimation.h"

union hkAabbQ;
struct LinCastInputS;
struct WorldRayCastInput;
struct WorldRayCastOutput;
class hkpRayHitCollector;

class hkpAabbPhantom : public hkpPhantom
{
public:
    virtual ~hkpAabbPhantom() throw();

    hkpAabbPhantom(const hkAabb& aabb, unsigned int collisionFilterInfo);
    hkpAabbPhantom* initialize(const hkAabb& aabb, unsigned int collisionFilterInfo);
    void setAabb(const hkAabbQ& aabb);
    void __thiscall castRay(void* input, void* output);
    void hkpAabbPhantom_setAabb(const hkAabbQ& aabb);
    void __thiscall hkpAabbPhantom_setAabb(const hkAabb& aabb);
    hkpAabbPhantom* FUN_00cf2cb0(const hkAabb& aabb, unsigned int collisionFilterInfo);
    void __thiscall hkpAabbPhantom_castRay_00cf26b0(void* input, void* output);
    void hkpAabbPhantom_castRay_00cf26b0(const WorldRayCastInput& input, WorldRayCastOutput& output) const;
    void hkpAabbPhantom_linearCast(const hkpCollidable* collA, const LinCastInputS& input, void* castCollector, void* startCollector);
    void hkpAabbPhantom_castRay(const WorldRayCastInput& input, hkpRayHitCollector& collector) const;

    char padA4[0xC];
    hkAabb m_kBounds;
    hkArray<void*> m_ppOverlappingCollidables;
    hkBool m_bOrderDirty;
    char padDD[0x3];
};
