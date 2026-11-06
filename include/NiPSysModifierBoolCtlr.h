#pragma once

#include "NiPSysModifierCtlr.h"
#include "StrArr.h"

class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysModifierBoolCtlr() throw();

    virtual void vf60(bool* value);
    virtual void vf61(int value);

    void AppendModifierInfo(StrArr* strings);
};
