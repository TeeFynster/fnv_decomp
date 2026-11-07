#pragma once

#include "BGSEntryPointFunctionData.h"

class TESLevItem;
struct TESFile_s;

class BGSEntryPointFunctionDataLeveledList : public BGSEntryPointFunctionData
{
public:
    TESLevItem* pLeveledList;

    BGSEntryPointFunctionDataLeveledList();

    BGSEntryPointFunctionDataLeveledList* Duplicate_005e69d0();
    bool Compare_005e6a60(BGSEntryPointFunctionData* apCompare);
    void Save_005e6ab0();
    bool Load_005e6b00(TESFile_s* apFile);
    void InitItem_005e6b70(TESForm* apOwner);

    bool vf03(BGSEntryPointFunctionData* apCompare);
};
