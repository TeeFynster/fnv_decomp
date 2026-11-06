#pragma once

#include "TESBoundObject.h"
#include "TESLeveledList.h"

class TESLevItem : public TESBoundObject, public TESLeveledList
{
public:
    TESLevItem();
    virtual ~TESLevItem();

    virtual void InitItem();

    int GetMaxLevelDifference();
    bool Load(TESFile* file);
    // TESForm vtable slot 8 (vftable 0x1028a64 slot 8 = 0x50b560)
    bool LoadForm(TESFile* file);
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    void RTTIAnchor();
};
