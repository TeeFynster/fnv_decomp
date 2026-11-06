#pragma once

#include "TESForm.h"
#include "TESChildCell.h"

class LandscapeColorData;
class NiGeometry;
class NiPoint3;
class NiColorA;
class TESObjectCELL;
class NiPoint3;

class TESObjectLAND : public TESForm, public TESChildCell
{
public:
    unsigned char formData[0x10];

    TESObjectLAND();
    void InitializeForCell(TESObjectCELL* cell);
    bool GetLandHeightAtPosition(const NiPoint3& coord, float& height);
    void ResetFadeOutMultipliers();
    bool __thiscall FUN_0053b550(LandscapeColorData&, const LandscapeColorData&, int);
    bool __thiscall FUN_0053b550(LandscapeColorData*, const NiPoint3*, int);
    float __thiscall FUN_0053a550();
    bool __thiscall FUN_0053f1e0(LandscapeColorData&, float&);
    bool __thiscall FUN_0053f180(const LandscapeColorData&, float&);
    NiGeometry* __thiscall FUN_0053f120(LandscapeColorData*);
    NiGeometry* __thiscall FUN_0053f0e0(const NiPoint3&);
    void FUN_005345c0(int m_iGridX, int m_iGridY, NiColorA* color);
    bool FUN_0053fa10(const LandscapeColorData* cdata, NiColorA* color);
    void FUN_00534160(int);
    void FUN_005340e0(TESObjectCELL* apCell);
    void FUN_00539010(bool altered);
    NiPoint3* FUN_0053a5e0();
};
