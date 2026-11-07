#pragma once

#include "TESBoundObject.h"
#include "TESFullName.h"
#include "TESScriptableForm.h"
#include "TESEnchantableForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
#include "TESBipedModelForm.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"

class TESObjectCLOT : public TESBoundObject,
                      public TESFullName,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESBipedModelForm,
                      public BGSDestructibleObjectForm,
                      public BGSEquipType
{
public:
    TESObjectCLOT();
    virtual ~TESObjectCLOT();

    void InitializeData_005156b0();
    void Save_00515f40();
    void* DestroyIfFlagged(unsigned int flags);
};
