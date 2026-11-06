#pragma once

#include "BGSEntryPointFunctionData.h"

class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionDataOneValue();
    virtual ~BGSEntryPointFunctionDataOneValue();

    virtual void Load(TESFile* file);

    float fValue;

    float FUN_006b9130();
    float GetValue() const { return fValue; }
    BGSEntryPointFunctionDataOneValue* FUN_005e6670();
    bool FUN_005e6700(BGSEntryPointFunctionData* apCompare);
    void FUN_005e6760();
    bool FUN_005e6790(TESFile* apFile);
    bool vf03(BGSEntryPointFunctionData* apCompare);
};
