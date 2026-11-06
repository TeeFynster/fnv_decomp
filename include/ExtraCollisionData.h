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
    bool FUN_004210c0(BSExtraData* apCompare);
    void* FUN_00421130(unsigned int flags);
    void FUN_00421160();

    CollisionData* m_pCollisionData;
};
