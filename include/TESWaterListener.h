#pragma once

#include "bhkWaterListener.h"
#include "BGSZoneTargetListener.h"
#include "NiPoint3.h"

class TESWaterListener : public bhkWaterListener, public BGSZoneTargetListener
{
public:
    virtual ~TESWaterListener();

    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();

    static void UpdateWaterHeightAtPosition(float, NiPoint3);
};
