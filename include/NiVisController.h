#pragma once

#include "NiBoolInterpController.h"

class NiVisController : public NiBoolInterpController
{
public:
    void GetVisibility(bool& bValue);

    NiBoolInterpController* m_pkBoolInterpController;
};
