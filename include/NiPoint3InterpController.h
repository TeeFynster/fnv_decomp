#pragma once

#include "NiSingleInterpController.h"

class NiPoint3InterpController : public NiSingleInterpController
{
public:
    virtual void vf59();

    using NiSingleInterpController::m_uiObjectFlags;
};
