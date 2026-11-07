#pragma once

class TESWaterForm;

class PlaceableWaterData
{
public:
    unsigned int flags;
    // BGSPlaceableWater is 0x50 bytes (allocation): TESBoundObject 0x30 + TESModel 0x18 + this 8-byte DNAM record
    TESWaterForm* m_pOwningWater;

    void Reinitialize();
    void Reset();
    void FUN_004019f0();
    void OBJ_WEAP_CRITICAL_Endian();
    void TwoValues_Endian();
};
