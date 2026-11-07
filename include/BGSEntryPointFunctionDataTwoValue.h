#pragma once

#include "BGSEntryPointFunctionData.h"

class BGSEntryPointFunctionDataTwoValue : public BGSEntryPointFunctionData
{
public:
    BGSEntryPointFunctionDataTwoValue();

    float EntryPointTwoValueFunctionData;
    float fSecondFunctionValue;

    float ReadValueA();
    float ReadValueB();

    BGSEntryPointFunctionDataTwoValue* Duplicate_005e67f0();
    bool Compare_005e6890(BGSEntryPointFunctionData* apCompare);
    void Save_005e6900();
    bool Load_005e6970(TESFile* apFile);
    void FUN_005e6490();
    void* FUN_005e64e0(unsigned int flags);
};
