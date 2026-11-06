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

    BGSEntryPointFunctionDataTwoValue* FUN_005e67f0();
    bool FUN_005e6890(BGSEntryPointFunctionData* apCompare);
    void FUN_005e6900();
    bool FUN_005e6970(TESFile* apFile);
    void FUN_005e6490();
    void* FUN_005e64e0(unsigned int flags);
};
