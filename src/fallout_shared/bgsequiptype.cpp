// fallout_shared/bgsequiptype.cpp: BGSEquipType (8 functions)

#include "../../include/ENUM_FORM_ID.h"

#include "../../include/BGSMenuIcon.h"
#include "../../include/BGSEquipType.h"
#include "../../include/TESFullName.h"
#include "../../include/BaseFormComponent.h"

// @fnv 0x00479430
BGSEquipType::EQUIP_TYPE BGSEquipType::GetEquipType(TESForm* form)
{
    EQUIP_TYPE result = ET_NONE;
    if (form)
    {
        switch (static_cast<const TESForm*>(form)->GetFormType())
        {
        case 40:
            result = (EQUIP_TYPE)((BGSEquipType*)((char*)form + 0xc4))->GetEquipType();
            break;
        case 24:
            result = (EQUIP_TYPE)((BGSEquipType*)((char*)form + 0x154))->GetEquipType();
            break;
        case 26:
            result = (EQUIP_TYPE)((BGSEquipType*)((char*)form + 0x14c))->GetEquipType();
            break;
        case 47:
            result = (EQUIP_TYPE)((BGSEquipType*)((char*)form + 0x9c))->GetEquipType();
            break;
        case 29:
            result = (EQUIP_TYPE)((BGSEquipType*)((char*)form + 0x8c))->GetEquipType();
            break;
        }
    }
    return result;
}

// @fnv 0x00479320
BGSEquipType::BGSEquipType()
{
    BGSEquipType::InitializeComponent();
}

extern int DAT_011c4b54[14];

// Returns DAT_011c4b54[a1] when a1 is between 0 and 13, otherwise returns 0.
// @fnv 0x00479510
BGSMenuIcon* BGSEquipType::GetEquipTypeIcon(int aiIndex)
{
    BGSMenuIcon* iValue = 0;
    if (aiIndex > -1 && aiIndex < 14)
    {
        iValue = (BGSMenuIcon*)DAT_011c4b54[aiIndex];
    }
    return iValue;
}

// Looks up the BGSMenuIcon for aeType and returns its full name, or a fallback string when none exists.
// @fnv 0x00479540
char* BGSEquipType::GetEquipTypeName(int aeType)
{
    BGSMenuIcon* picon = GetEquipTypeIcon(aeType);
    if (picon)
        return reinterpret_cast<TESFullName*>((char*)picon + sizeof(TESForm))->GetFullName();
    return "";
}

struct FUN_004029d0_shell
{
    bool AlchemyItem_IsFlagSet(int);
};
struct S_004036b0
{
    int TES_QPlaceableWaterCount();
};
struct S_004063e0
{
    float GetTotalCost(int);
};
struct FUN_00403660_shell
{
    float GetValue(int);
};
// @fnv 0x00403660
float FUN_00403660_shell::GetValue(int)
{
    if (((FUN_004029d0_shell*)((char*)this - 0x3c))->AlchemyItem_IsFlagSet(1))
    {
        return (float)((S_004036b0*)((char*)this - 0x3c))->TES_QPlaceableWaterCount();
    }
    else
    {
        return ((S_004063e0*)this)->GetTotalCost(0);
    }
}

struct S_0040a0a0_Primary
{
    virtual void vfn_00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

struct S_0040a0a0_AVOwner
{
    virtual float IngredientItem_GetCost(int avCode);
    float GetTotalCost(int a);
};

struct S_0040a0a0_Actor : S_0040a0a0_Primary, S_0040a0a0_AVOwner
{
    bool IngredientItem_GetFlag(unsigned int flag);
    int CombatController_GetCombatState();
    virtual float IngredientItem_GetCost(int avCode);
};

// @fnv 0x0040a0a0
// src: COMMUNITY 0x0040a0a0
float S_0040a0a0_Actor::IngredientItem_GetCost(int avCode)
{
    if (IngredientItem_GetFlag(1))
    {
        return CombatController_GetCombatState();
    }
    else
    {
        return GetTotalCost(0);
    }
}

extern const char DAT_01183040[];
extern const char DAT_01183290[];
extern "C" void* __cdecl FUN_00ec43fb(int, int, const char*, const char*, int);
// @fnv 0x004793d0
bool BGSEquipType::CompareWithBase(BaseFormComponent* argument)
{
    void* found = FUN_00ec43fb((int)argument, 0, DAT_01183040, DAT_01183290, 0);
    if (found == 0)
        return true;
    if (GetEquipType() != ((BGSEquipType*)found)->GetEquipType())
        return true;
    return false;
}

// @fnv 0x00479380
void BGSEquipType::CopyFromBase(BaseFormComponent* a1)
{
    BGSEquipType* obj = (BGSEquipType*)FUN_00ec43fb((int)a1, 0, DAT_01183040, DAT_01183290, 0);
    if (obj == 0)
    {
    }
    else
    {
        this->SetEquipType(obj->GetEquipType());
    }
}
