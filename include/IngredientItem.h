#pragma once

#include "MagicItemObject.h"
#include "TESModelTextureSwap.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#include "TESWeightForm.h"
#include "BGSEquipType.h"
#include "BGSDestructibleObjectForm.h"

class IngredientItem : public MagicItemObject,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public TESScriptableForm,
                       public TESWeightForm,
                       public BGSEquipType,
                       public BGSDestructibleObjectForm
{
public:
    struct EffectIndexRecord
    {
        int m_iEffectIndex;
        unsigned char m_ucEntryType;
        unsigned char unkA1[3];
    };

    IngredientItem();
    virtual ~IngredientItem();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual void InitItem();

    void ResetFormData();

    EffectIndexRecord data;
};
