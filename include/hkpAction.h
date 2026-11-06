#pragma once

#include "hkReferencedObject.h"
#include "hkStringPtr.h"

class hkpWorld;
class hkpSimulationIsland;
class hkpEntity;
struct ClassMemberDescriptor;

#include "hkArray.h"

typedef unsigned long hkUlong;

struct hkpAction : public hkReferencedObject
{
public:
    static const ClassMemberDescriptor Members[];

    hkpAction() throw();
    hkpAction(FinishingFlag flag);

    virtual void v0c();
    virtual void GetEntities(hkArray<hkpEntity*>& entitiesOut);
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();

    void FUN_00c90510();
    void FUN_00c905b0();

    hkpSimulationIsland* GetSimulationIsland();
    void setSimulationIsland(hkpSimulationIsland* island);

    hkpWorld* m_pOwningWorld;
    hkpSimulationIsland* m_pCurrentSimulationIsland;
    hkUlong m_ulUserData;
    hkStringPtr m_name;
};
