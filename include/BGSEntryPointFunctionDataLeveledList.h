#pragma once

#include "BGSEntryPointFunctionData.h"

class TESLevItem;
struct TESFile_s;

class BGSEntryPointFunctionDataLeveledList : public BGSEntryPointFunctionData
{
public:
    TESLevItem* pLeveledList;

    BGSEntryPointFunctionDataLeveledList();

    BGSEntryPointFunctionDataLeveledList* FUN_005e69d0();
    bool FUN_005e6a60(BGSEntryPointFunctionData* apCompare);
    void FUN_005e6ab0();
    bool FUN_005e6b00(TESFile_s* apFile);
    void FUN_005e6b70(TESForm* apOwner);

    bool vf03(BGSEntryPointFunctionData* apCompare);
};
