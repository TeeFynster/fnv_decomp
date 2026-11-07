#include "../../../include/Sky.h"
#include "../../../include/TESObjectCELL.h"

// src/fallout_shared/region system/tesregionobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/region system/tesregionobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DoorH
{
    void* GetParentWorldSpace();
};
float DAT_01015f5c;
double _DAT_010231b0;

struct FUN_005471e0_shell
{
    float TESObjectCELL_GetWaterHeight();
};

// @fnv 0x005471e0
// src: XBOX_PDB 0x005471e0
float FUN_005471e0_shell::TESObjectCELL_GetWaterHeight()
{
    if (!((TESObjectCELL*)this)->HasWater() || ((TESObjectCELL*)this)->IsInterior())
    {
        return DAT_01015f5c;
    }
    if (*(float*)((char*)this + 0x50) != 3.4028234663852886e+38f)
    {
        return *(float*)((char*)this + 0x50);
    }
    void* m_pContainingWorldspace = ((DoorH*)this)->GetParentWorldSpace();
    if (m_pContainingWorldspace)
    {
        return ((Sky*)m_pContainingWorldspace)->GetFieldCC();
    }
    return 0.0f;
}
