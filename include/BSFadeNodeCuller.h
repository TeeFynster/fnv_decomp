#pragma once

#include "NiCullingProcess.h"

class BSFadeNodeCuller : public NiCullingProcess
{
public:
    virtual void* GetRTTI();
    virtual void vfn_40();

    ~BSFadeNodeCuller();
    void* DeleteThis(unsigned int flags);
};
