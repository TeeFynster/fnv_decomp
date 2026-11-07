#pragma once

#include "BGSEntryPointFunctionData.h"

class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionDataOneValue();
    virtual ~BGSEntryPointFunctionDataOneValue();

    virtual void Load(TESFile* file);

    float fValue;

    float CombatTimer_GetTargetTime();
    float GetValue() const { return fValue; }
    BGSEntryPointFunctionDataOneValue* Duplicate_005e6670();
    bool Compare_005e6700(BGSEntryPointFunctionData* apCompare);
    void Save_005e6760();
    bool Load_005e6790(TESFile* apFile);
    bool vf03(BGSEntryPointFunctionData* apCompare);
};
