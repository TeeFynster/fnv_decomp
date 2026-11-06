#pragma once

#include "BSExtraData.h"
#include "NiPoint3.h"

class TESObjectREFR;

class ExtraEditorRefMoveData : public BSExtraData
{
public:
    NiPoint3 kRealLocation;
    NiPoint3 kRealAngle;
    NiPoint3 kOldLocation;

    ExtraEditorRefMoveData(TESObjectREFR* apRef);
};
