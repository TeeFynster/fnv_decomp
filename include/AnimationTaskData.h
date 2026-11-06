#pragma once

#include "MobileObjectTaskletData.h"

class AnimationTaskData : public MobileObjectTaskletData
{
public:
    AnimationTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual void ProcessMobileObject(MobileObject* apMob);
};
