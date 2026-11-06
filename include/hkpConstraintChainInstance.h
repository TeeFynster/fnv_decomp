#pragma once

#include "hkpConstraintInstance.h"
#include "hkaAnimation.h"

class hkpConstraintChainData;
class hkpConstraintChainInstanceAction;
class hkpEntity;

class hkpConstraintChainInstance : public hkpConstraintInstance
{
public:
    hkpConstraintChainInstance(hkpConstraintChainData* pkData);
    virtual ~hkpConstraintChainInstance() throw();

    void EntityRemovedCallback(void* entity);
    void AddReferencedObject(hkpEntity* entity);

    hkArray<hkpEntity*> m_ppRigidBodies;
    hkpConstraintChainInstanceAction* m_pAction;
};
