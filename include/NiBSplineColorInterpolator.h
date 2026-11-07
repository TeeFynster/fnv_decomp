#pragma once

#include "NiBSplineInterpolator.h"
#include "NiColorA.h"

class NiBSplineColorInterpolator : public NiBSplineInterpolator
{
public:
    unsigned int GetControlHandle(unsigned short usChannel);
    void CopyTo(NiBSplineColorInterpolator* source, CloningProcess& proc);

    NiColorA m_kDiffuseColor;
    unsigned int m_kColorACPHandle;
    unsigned int unk30;
};
