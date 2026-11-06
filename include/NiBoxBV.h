#pragma once

#include "NiBoundingVolume.h"

class NiBoxBV : public NiBoundingVolume
{
public:
    NiBoxBV();

    void __thiscall SaveBinary(NiStream& kStream);
    void Copy(const NiBoundingVolume& kABV);
};
