#pragma once

#include "hkReferencedObject.h"
#include "hkaAnimation.h"

class hkpWorldCinfo;
class hkpPhysicsSystem;

class hkpPhysicsData : public hkReferencedObject
{
public:
    hkpWorldCinfo* m_pWorldCinfo;
    hkArray<hkpPhysicsSystem*> m_kPhysicsSystems;
};
