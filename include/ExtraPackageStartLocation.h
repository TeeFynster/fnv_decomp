#pragma once

#include "BSExtraData.h"

class NiPoint3;
class TESObjectCELL;
class TESWorldSpace;

namespace extra_save
{
    class SForm;
}

class ExtraPackageStartLocation : public BSExtraData
{
public:
    virtual ~ExtraPackageStartLocation();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraPackageStartLocation();
    ExtraPackageStartLocation(unsigned char aEtype);
    ExtraPackageStartLocation(TESWorldSpace* apWorld, TESObjectCELL* apIntCell,
                              const NiPoint3* aPt, float afzrotation);
    bool Compare_00432770(BSExtraData* apCompare);

    extra_save::SForm* loc;
    float pos[3];
    int unk1C;
};
