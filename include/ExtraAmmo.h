#pragma once

#include "BSExtraData.h"

class TESAmmo;

// Type 0x6e, vftable 0x01015998, allocation 0x14 (0x0042eb60).
class ExtraAmmo : public BSExtraData
{
public:
    ExtraAmmo(TESAmmo* apAmmo, int aiCount);  // 0x0042ec30: BSExtraData(0x6e), stores +0x0c and +0x10
    virtual bool Compare(BSExtraData* apCompare);
    bool Compare_004373c0(BSExtraData* apCompare);

    TESAmmo* pAmmo;  // +0x0c, passed to SetAmmoExtra as the form
    int iCount;      // +0x10, passed to SetAmmoExtra as the count
};
