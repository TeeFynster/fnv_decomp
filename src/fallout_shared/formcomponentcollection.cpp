// fallout_shared/formcomponentcollection.cpp: FormComponentArray, Holder (7 functions)

#include "FormComponentArray.h"
#include "formcomponents.h"
#include "layout_support.h"
#include "../../include/TESForm.h"
#include "../../include/BGSAmmoForm.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSEquipType.h"
#include "../../include/BGSIdleCollection.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/BGSRepairItemList.h"
#include "../../include/BGSTouchSpellForm.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimation.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESContainer.h"
#include "../../include/TESDescription.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESImageSpaceModifiableForm.h"
#include "../../include/TESLeveledList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelList.h"
#include "../../include/TESProduceForm.h"
#include "../../include/TESQualityForm.h"
#include "../../include/TESRaceForm.h"
#include "../../include/TESReactionForm.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSoundFile.h"
#include "../../include/TESSpellList.h"
#include "../../include/TESTexture.h"
#include "../../include/TESUsesForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"

// @fnv 0x0047c050
FormComponentArray::FormComponentArray()
{
    ClearDataAllComponents();
}

// Clears all component pointers, then stores form and dynamic_cast results for each supported component type into the component array.
// @fnv 0x0047c070
void FormComponentArray::InitializeFromForm(TESForm* form)
{
    ClearDataAllComponents();
    m_pComponents[0] = form;
    m_pComponents[1] = dynamic_cast<TESAIForm*>(form);
    m_pComponents[3] = dynamic_cast<TESActorBaseData*>(form);
    m_pComponents[4] = dynamic_cast<TESAttackDamageForm*>(form);
    m_pComponents[5] = dynamic_cast<TESAttributes*>(form);
    m_pComponents[6] = dynamic_cast<TESBipedModelForm*>(form);
    m_pComponents[7] = dynamic_cast<TESContainer*>(form);
    m_pComponents[8] = dynamic_cast<TESDescription*>(form);
    m_pComponents[9] = dynamic_cast<TESEnchantableForm*>(form);
    m_pComponents[10] = dynamic_cast<TESFullName*>(form);
    m_pComponents[11] = dynamic_cast<TESHealthForm*>(form);
    m_pComponents[12] = dynamic_cast<TESTexture*>(form);
    m_pComponents[13] = dynamic_cast<TESLeveledList*>(form);
    m_pComponents[14] = dynamic_cast<TESModel*>(form);
    m_pComponents[15] = dynamic_cast<TESProduceForm*>(form);
    m_pComponents[16] = dynamic_cast<TESQualityForm*>(form);
    m_pComponents[17] = dynamic_cast<TESRaceForm*>(form);
    m_pComponents[18] = dynamic_cast<TESScriptableForm*>(form);
    m_pComponents[19] = dynamic_cast<TESSpellList*>(form);
    m_pComponents[20] = dynamic_cast<TESUsesForm*>(form);
    m_pComponents[21] = dynamic_cast<TESValueForm*>(form);
    m_pComponents[22] = dynamic_cast<TESWeightForm*>(form);
    m_pComponents[23] = dynamic_cast<TESSoundFile*>(form);
    m_pComponents[24] = dynamic_cast<TESReactionForm*>(form);
    m_pComponents[2] = dynamic_cast<TESAnimation*>(form);
    m_pComponents[25] = dynamic_cast<TESModelList*>(form);
    m_pComponents[26] = dynamic_cast<BGSClipRoundsForm*>(form);
    m_pComponents[27] = dynamic_cast<BGSAmmoForm*>(form);
    m_pComponents[28] = dynamic_cast<BGSIdleCollection*>(form);
    m_pComponents[29] = dynamic_cast<BGSDestructibleObjectForm*>(form);
    m_pComponents[30] = dynamic_cast<BGSRepairItemList*>(form);
    m_pComponents[31] = dynamic_cast<BGSEquipType*>(form);
    m_pComponents[32] = dynamic_cast<BGSBipedModelList*>(form);
    m_pComponents[33] = dynamic_cast<TESImageSpaceModifiableForm*>(form);
    m_pComponents[34] = dynamic_cast<TESImageSpaceModifiableCountForm<6>*>(form);
    m_pComponents[35] = dynamic_cast<BGSMessageIcon*>(form);
    m_pComponents[36] = dynamic_cast<BGSTouchSpellForm*>(form);
    m_pComponents[37] = dynamic_cast<BGSPickupPutdownSounds*>(form);
}

struct FUN_0047c540_shell : public FormComponentArray
{
    void FormComponentCollection_ClearFormComponentArray();
};

void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x0047c540
// src: COMMUNITY 0x0047c540
void FUN_0047c540_shell::FormComponentCollection_ClearFormComponentArray()
{
    memset(this, 0, 0x98);
}

struct Elem
{
    virtual void foo();
};
struct Holder
{
    Elem* arr[0x26];
    void CallElements();
};
// Iterates over the 0x26 entries of arr and calls foo() on each non-null element.
// @fnv 0x0047c560
void Holder::CallElements()
{
    int i;
    for (i = 0; i < 0x26; i++)
    {
        if (arr[i] != 0)
            arr[i]->foo();
    }
}

struct Base_47c5b0
{
    virtual void f0();
    virtual void f1();
};
struct Holder_47c5b0
{
    Base_47c5b0* arr[38];
    void FormComponentCollection_ClearDataAllComponents();
};
// Iterates over the 38 pointers in arr and calls f1() on each non-null entry.
// @fnv 0x0047c5b0
// src: COMMUNITY 0x0047c5b0
void Holder_47c5b0::FormComponentCollection_ClearDataAllComponents()
{
    int i;
    for (i = 0; i < 38; i++)
    {
        if (arr[i] != 0)
            arr[i]->f1();
    }
}

struct BaseFormComponentInterface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Compare(BaseFormComponent*);
};

struct FUN_0047c670_shell : public FormComponentArray
{
    bool CompareComponents(FormComponentArray* other);
};

// @fnv 0x0047c670
bool FUN_0047c670_shell::CompareComponents(FormComponentArray* other)
{
    if (!other)
        return true;
    for (int i = 0; i < 0x26; ++i)
    {
        if (m_pComponents[i])
        {
            if (((BaseFormComponentInterface*)m_pComponents[i])->Compare(other->m_pComponents[i]))
                return true;
        }
        else if (other->m_pComponents[i])
            return true;
    }
    return false;
}

struct FUN_0047c600_cls : public FormComponentArray
{
    void FormComponentCollection_CopyAllComponents(FormComponentArray* other);
};

// Copies each non-null entry of the other object's array into this object's matching non-null entry, for 38 slots.
// @fnv 0x0047c600
// src: COMMUNITY 0x0047c600
void FUN_0047c600_cls::FormComponentCollection_CopyAllComponents(FormComponentArray* other)
{
    if (other == 0)
    {
        return;
    }
    for (int i = 0; i < 38; i++)
    {
        if (m_pComponents[i] != 0)
        {
            if (other->m_pComponents[i] != 0)
            {
                m_pComponents[i]->CopyFromBase(other->m_pComponents[i]);
            }
        }
    }
}
