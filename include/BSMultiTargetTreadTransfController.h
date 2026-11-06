#pragma once

#include "NiInterpController.h"

class TreadEntry;

class BSMultiTargetTreadTransfController : public NiInterpController
{
public:
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;

    TreadEntry* entries;
};
