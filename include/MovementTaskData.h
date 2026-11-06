#pragma once

#include "MobileObjectTaskletData.h"

class HighProcess;

class MovementTaskData : public MobileObjectTaskletData
{
public:
    MovementTaskData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual ~MovementTaskData();
    virtual void SetMobileObjectCount(unsigned int auiObjectCount);
    virtual void ProcessMobileObject(MobileObject* apObject);
    virtual void SetThreadNumber(unsigned int auiThreadNumber);

    unsigned int uiRunCount;

    void UpdateMovementTask(HighProcess* apMob);
};
