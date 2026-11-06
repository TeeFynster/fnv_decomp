#pragma once

#include "NiFloatInterpController.h"

class NiAlphaController : public NiFloatInterpController
{
public:
    void CopyMemberData(NiAlphaController* clone, CloningProcess& process);
};
