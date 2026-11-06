
// src/fallout_shared/tesland_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py (flags of tesland_od_variant.cpp) for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tesland.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "tesland_decls.h"
#include "../../include/TESForm.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/TESObjectLAND.h"
#pragma optimize("", off)
int TruncateFloatToInt(float value);

struct LandDuplicateCalls
{
    ::TESForm* FUN_004867a0(bool createEditorID, void* copyMap);
};
struct LandDuplicateEntry : LandDuplicateCalls
{
    ::TESForm* FUN_00534880(bool createEditorID, void* copyMap);
};
// @fnv 0x00534880
::TESForm* LandDuplicateEntry::FUN_00534880(bool createEditorID, void* copyMap)
{
    ::TESObjectLAND* duplicate;
    duplicate = dynamic_cast< ::TESObjectLAND*>(FUN_004867a0(false, copyMap));
    return duplicate;
}

extern void* DAT_01187020;

TESForm* FUN_004839c0(unsigned int auiFormId);

struct LandSaveGroup5391
{
    void* typeTag;
    unsigned int unk04;
    unsigned int formID;
    unsigned int groupType;
};

struct FUN_005391d0_class
{
    TESObjectCELL* __thiscall FUN_007af430();
    bool __thiscall FUN_005391d0(LandSaveGroup5391* apGroupFORM);
};

// @fnv 0x005391d0
bool FUN_005391d0_class::FUN_005391d0(LandSaveGroup5391* apGroupFORM)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->typeTag == DAT_01187020)
    {
        switch (apGroupFORM->groupType)
        {
        case 8:
        case 9: {
            void* found = dynamic_cast< ::TESObjectCELL*>(FUN_004839c0(apGroupFORM->formID));
            if (found && FUN_007af430() == found)
                bretval = false;
            break;
        }
        default: {
            TESObjectCELL* pCell = FUN_007af430();
            bretval = pCell->Unk_0E(apGroupFORM);
            break;
        }
        }
    }
    return bretval;
}
