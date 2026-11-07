#pragma once

#include "TESBoundObject.h"
#include "TESModel.h"
#include "PlaceableWaterData.h"

class TESFile;

class BGSPlaceableWater : public TESBoundObject, public TESModel
{
public:
    PlaceableWaterData Data;  // +0x48, 8 bytes (flags, owning TESWaterForm); sizeof 0x50 = allocation size

    BGSPlaceableWater();
    virtual ~BGSPlaceableWater();

    virtual void InitItem(void);
    virtual bool LoadForm(TESFile* file);
    bool Load(TESFile* file);

    void ResetFormData();
    PlaceableWaterData* GetExtraPartList();
    void BGSPlaceableWater_SetReflectionEnabled(bool value);
    void BGSPlaceableWater_SetReflectsLand(bool value);
    void BGSPlaceableWater_SetReflectsLODLand(bool value);
    void BGSPlaceableWater_SetReflectsSky(bool value);
    void BGSPlaceableWater_SetRefractionEnabled(bool value);
    void SetFlag800(bool value);
    void BGSPlaceableWater_SetUnderwaterFog(bool value);
    void BGSPlaceableWater_SetAutomaticWater(bool value);
    void BGSPlaceableWater_SetObjectTexCoordsEnabled(bool value);
    void BGSPlaceableWater_SetDepthEnabled(bool value);
    void BGSPlaceableWater_SetFlag(int flag, bool value);
    void SetValue(bool value);
    void SetFlag80(bool value);
    void SetFlag100(bool value);
    void SetFlag8000000(bool value);
    bool HasFlags(unsigned int flags);
    bool IsRestricted();
    bool GetReflectsLand();
    bool GetReflectsLODLand();
    bool GetReflectsLODBuildings();
    bool GetReflectsLODTrees();
    bool GetReflectionEnabled();
    void GetObjectTexCoordsEnabled();
    bool BGSPlaceableWater_IsAutomaticWater();
};
