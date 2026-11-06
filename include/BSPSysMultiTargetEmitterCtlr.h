#pragma once

#include "NiPSysEmitterCtlr.h"

class BSPSysMultiTargetEmitterCtlr : public NiPSysEmitterCtlr
{
public:
    virtual void LinkObject(NiStream& stream);
};
