#pragma once

#include "NiPSysModifier.h"
#include "NiColorA.h"

class ViewerStrings;

class BSPSysSimpleColorModifier : public NiPSysModifier
{
public:
    virtual void LinkObject(NiStream& stream);
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    void LinkObject_00c60910(NiStream& stream);
    void GetViewerStrings_00c60b20(ViewerStrings* strings);

    NiColorA color1;
    NiColorA color2;
    NiColorA color3;
    float fadeIn;
    float fadeOut;
    float color1End;
    float color2Start;
    float color2End;
    float color3Start;
};
