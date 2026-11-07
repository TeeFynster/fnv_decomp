#pragma once

#include "BSExtraData.h"

class CollisionData;

class ExtraCollisionData : public BSExtraData
{
public:
    virtual ~ExtraCollisionData();
    virtual bool Compare(BSExtraData* apCompare);

    void* ScalarDeletingDestructor(unsigned int flags);
    void Destroy();
    bool Compare_004210c0(BSExtraData* apCompare);
    void* FUN_00421130(unsigned int flags);
    void ReleaseStorage();

    CollisionData* m_pCollisionData;
};
