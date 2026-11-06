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
    PlaceableWaterData* FUN_00624700();
    void FUN_004fc360(bool value);
    void FUN_004fc380(bool value);
    void FUN_004fc3a0(bool value);
    void FUN_004fc3c0(bool value);
    void FUN_004fc3e0(bool value);
    void SetFlag800(bool value);
    void FUN_004fc420(bool value);
    void FUN_004fc450(bool value);
    void FUN_004fc470(bool value);
    void FUN_004fc490(bool value);
    void FUN_004fc990(int flag, bool value);
    void SetValue(bool value);
    void SetFlag80(bool value);
    void SetFlag100(bool value);
    void SetFlag8000000(bool value);
    bool HasFlags(unsigned int flags);
    bool IsRestricted();
    bool FUN_004ea8b0();
    bool FUN_004ea8d0();
    bool FUN_004ea8f0();
    bool FUN_004ea910();
    bool FUN_004e3c50();
    void FUN_004e3ca0();
    bool FUN_00452440();
};
