#pragma once

#include "TESBoundObject.h"
#include "TESModel.h"
#include "TESGrass__GRASS_DATA.h"
#include <stddef.h>

class TESGrass : public TESBoundObject, public TESModel
{
public:
    enum GRASS_WATER_STATE
    {
        GWS_ABOVE_ONLY_ATLEAST,
        GWS_ABOVE_ONLY_ATMOST,
        GWS_BELOW_ONLY_ATLEAST,
        GWS_BELOW_ONLY_ATMOST,
        GWS_BOTH_ATLEAST,
        GWS_BOTH_ATMOST,
        GWS_BOTH_ATMOST_ABOVE,
        GWS_BOTH_ATMOST_BELOW,
        GWS_COUNT
    };

    TESGrass();
    virtual ~TESGrass();
    virtual void InitItem();

    virtual char GetByteAtOffset48();
    virtual bool FUN_00509d30(unsigned char value);
    virtual unsigned char GetMinimumSlopeDegrees();
    virtual bool FUN_00509d60(unsigned char value);
    virtual unsigned char FUN_00509aa0();
    virtual bool SetSlope(unsigned char slope);
    virtual float FUN_00509ac0();
    virtual float GetFloatValue();
    virtual unsigned short GetUnitsFromSurface();
    virtual void FUN_00509b20(unsigned short state);
    virtual TESGrass* GetGrass();
    virtual void SetUnderwater(GRASS_WATER_STATE state);
    virtual float GetField54Float();
    virtual bool FUN_00509de0(float value);
    virtual float GetFloatAtOffset58();
    virtual bool FUN_00509e20(float value);
    virtual float GetLowestAllowedSlope();
    virtual bool FUN_00509e60(float value);
    virtual float GetField60Float();
    virtual bool FUN_00509ea0(float value);
    virtual bool IsFlagSet();
    virtual void SetFlag(bool value);
    virtual bool IsFlag2Set();
    virtual void SetFlag2(bool value);
    virtual bool IsFlag4Set();
    virtual void FUN_00509c40(bool value);

    void ResetFormData();
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x102814c slot 8 = 0x509f80)
    bool LoadForm(TESFile* file);

    TESGrass__GRASS_DATA Data;
};

typedef char TESGrass_Data_offset_check[offsetof(TESGrass, Data) == 0x48 ? 1 : -1];
