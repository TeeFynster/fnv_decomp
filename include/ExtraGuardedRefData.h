#pragma once

#include "BSExtraData.h"
#ifndef FNV_LAYOUT_SUPPORT_H
#include "BSSimpleArray.h"
#endif

class Actor;
class NavMeshInfo;

class ExtraGuardedRefData : public BSExtraData
{
public:
    virtual ~ExtraGuardedRefData();
    virtual bool Compare(BSExtraData* extra);

    ExtraGuardedRefData();
    void AddGuardingActor(Actor*);
    template <class GuardActor> void AddGuardingActor(GuardActor*);

    union
    {
        char pad[0x10];
        struct
        {
            BSSimpleArray<unsigned int, 1024> guardActorIDs;
        };
    };

    BSSimpleArray<NavMeshInfo*, 1024>& GetGuards()
    {
        return reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>&>(guardActorIDs);
    }

    __declspec(property(get=GetGuards)) BSSimpleArray<NavMeshInfo*, 1024> guards;
};
