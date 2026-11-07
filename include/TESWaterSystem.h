#pragma once

// TESWaterSystem: real name (was WaterZoneManager). All 5 bound methods are TESWaterSystem::* in the names DB; ctor 0x004e1650 is called after a 0xa0-byte allocation at 0x00450cb2 (this header covers only the first 72 bytes).

#include "NiAVObject.h"
#include "NiPoint3.h"

class TESObjectREFR;
class WaterSurface;
class BSFaceGenAnimationData;
class ShadowSceneNode;

class TESWaterSystem
{
  public:
    union
    {
        char layoutPadding00[0x3c];
        int m_uiPathPointIndex;
    };
    NiTPointerList<WaterSurface*> m_kWaterZoneList;

    void UpdateWaterZone(TESObjectREFR*, TESObjectREFR*, float); // @ref 0x004e5df0 UpdateWaterZone@TESWaterSystem
    WaterSurface* GetWaterZone(TESObjectREFR*, TESObjectREFR*, float); // @ref 0x004e59f0
    void TESWaterSystem_UpdateWaterSystem(BSFaceGenAnimationData* data, ShadowSceneNode* scene);
    static void TESWaterSystem_SetIsUnderWater(int index);
    void SetWaterHeight(TESObjectREFR*, TESObjectREFR*, float); // @ref 0x004e5c80 SetWaterHeight@TESWaterSystem
    void AddWaterRipple(NiPoint3, float); // @ref 0x004e8510 AddWaterRipple@TESWaterSystem
    void RemoveReferenceFromCell(TESObjectREFR*, WaterSurface*);
};
