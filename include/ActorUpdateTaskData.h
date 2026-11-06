#pragma once

#include "MobileObjectTaskletData.h"

class MobileObject;

class ActorUpdateTaskData : public MobileObjectTaskletData
{
public:
    ActorUpdateTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);

    unsigned int uiRunCount;

    void UpdateActorTask(MobileObject* apMob);
};
