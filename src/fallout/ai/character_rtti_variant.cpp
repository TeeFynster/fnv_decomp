// RTTI variants of the character equipment-weight functions.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/Character.h"
#include "../../../include/MiddleHighProcess.h"
#include "../../../include/NiCamera.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESObjectARMO.h"
#include "../../../include/TESObjectCLOT.h"
#include "../../../include/Setting.h"

namespace CharacterRTTIVariant
{
extern double _gModifierZero;

struct FUN_004bc5f0
{
    void* extraData;
    int count;
    TESBoundObject* object;
    ~FUN_004bc5f0();
    TESBoundObject* FUN_0044ddc0();
    float FUN_004be0b0(ActorValueOwner*);
};
struct EquipmentList536
{
    FUN_004bc5f0* FUN_004c8c10(int, bool);
};
struct ExtraList536
{
    EquipmentList536* FUN_00418520();
};
// These adapters declare unit-local entry points missing from the shared class;
// all object layout and base-class conversions come from Character.
struct CharacterEquipmentWeight : Character
{
    float FUN_008d2110();
};
// @fnv 0x008d2110
float CharacterEquipmentWeight::FUN_008d2110()
{
    int count = 0;
    ::TESObjectARMO* forms3[20];
    forms3[0] = 0;
    if (m_fSecondValue < _gModifierZero)
    {
        m_fSecondValue = 0.0f;
        EquipmentList536* list6 = static_cast<ExtraList536*>(Actor::FUN_005d43c0())->FUN_00418520();
        FUN_004bc5f0* item7 = 0;
        if (list6)
        {
            for (int index = 0; index < 20; ++index)
            {
                item7 = list6->FUN_004c8c10(index, false);
                if (item7)
                {
                    ::TESObjectARMO* armor = dynamic_cast<::TESObjectARMO*>(item7->FUN_0044ddc0());
                    if (armor)
                    {
                        bool found4 = false;
                        if (count != 0)
                        {
                            for (int scan5 = 0; scan5 < count && !found4; ++scan5)
                                found4 = forms3[scan5] == armor;
                        }
                        if (!found4)
                        {
                            m_fSecondValue += item7->FUN_004be0b0(static_cast<ActorValueOwner*>(this));
                            forms3[count] = armor;
                            ++count;
                        }
                    }
                    delete item7;
                    item7 = 0;
                }
            }
        }
    }
    return m_fSecondValue;
}

float __cdecl FUN_0040ebd0(float a, float b);

// Adapted from an unverified 2026-10-23 contribution by another contributor.

struct InventoryEntry_8d22b0
{
    ~InventoryEntry_8d22b0();
    TESBoundObject* GetBaseObject();
    float GetEntryWeight(ActorValueOwner* owner);
};
struct InventoryData_8d22b0
{
    InventoryEntry_8d22b0* GetEquippedEntry(int index, int flags);
};
struct ContainerChanges_8d22b0
{
    InventoryData_8d22b0* GetData();
};

extern ::Setting originalRuntimeFloatSetting1016;

struct CharacterArmorWeight : public Character
{
    float FUN_008d22b0();
};

// @fnv 0x008d22b0
float CharacterArmorWeight::FUN_008d22b0()
{
    int iCount = 0;
    ::TESObjectARMO* armors[20];
    armors[0] = 0;
    if (m_fFirstResetValue < 0.0)
    {
        m_fFirstResetValue = 0.0f;
        InventoryData_8d22b0* items = static_cast<ContainerChanges_8d22b0*>(Actor::FUN_005d43c0())->GetData();
        InventoryEntry_8d22b0* entry = 0;
        if (items)
        {
            for (int i = 0; i < 20; i++)
            {
                entry = items->GetEquippedEntry(i, 0);
                if (entry)
                {
                    ::TESObjectARMO* armor = dynamic_cast<::TESObjectARMO*>(entry->GetBaseObject());
                    if (armor)
                    {
                        bool found = false;
                        if (iCount)
                        {
                            for (int j = 0; j < iCount && !found; j++)
                            {
                                found = armors[j] == armor;
                            }
                        }
                        if (!found)
                        {
                            m_fFirstResetValue += entry->GetEntryWeight(this);
                            armors[iCount++] = armor;
                        }
                    }
                    delete entry;
                    entry = 0;
                }
            }
        }
    }
    return *originalRuntimeFloatSetting1016.GetFloat() > 0.0
               ? FUN_0040ebd0(m_fFirstResetValue, *originalRuntimeFloatSetting1016.GetFloat())
               : m_fFirstResetValue;
}

struct InventoryEntryWeight534
{
    double FUN_004bd400();
};
struct EquipmentList534
{
    FUN_004bc5f0* FUN_004c8c10(int, bool);
};
struct ExtraList534
{
    EquipmentList534* FUN_00418520();
};
extern ::Setting DAT_011d0ca8, DAT_011d1104, DAT_011d0d14, DAT_011d043c;
struct CharacterClothingWeight : Character
{
    float FUN_008d3110();
};
// @fnv 0x008d3110
float CharacterClothingWeight::FUN_008d3110()
{
    float weight = 0.0f;
    EquipmentList534* list = static_cast<ExtraList534*>(Actor::FUN_005d43c0())->FUN_00418520();
    FUN_004bc5f0* item9 = 0;
    int index2;
    ::TESObjectARMO* armor7;
    ::TESObjectCLOT* clothing;
    if (list)
    {
        for (index2 = 0; index2 < 20; ++index2)
        {
            item9 = list->FUN_004c8c10(index2, false);
            if (item9)
            {
                armor7 = dynamic_cast<::TESObjectARMO*>(item9->FUN_0044ddc0());
                clothing = dynamic_cast<::TESObjectCLOT*>(item9->FUN_0044ddc0());
                if (armor7)
                    weight +=
                        ((InventoryEntryWeight534*)item9)->FUN_004bd400() * *DAT_011d0ca8.GetFloat() + *DAT_011d1104.GetFloat();
                else if (clothing)
                    weight +=
                        ((InventoryEntryWeight534*)item9)->FUN_004bd400() * *DAT_011d0d14.GetFloat() + *DAT_011d043c.GetFloat();
                // GetEquippedItem returns an owned temporary inventory entry.
                delete item9;
                item9 = 0;
            }
        }
    }
    if (weight > 100.0)
        weight = 100.0f;
    return weight;
}

} // namespace CharacterRTTIVariant
