// fallout_shared/magic/enchantmentitem.cpp: EnchantmentItem, MagicShaderHitEffect, SpellItem, Unnamed and more (11 functions)

#include "../../../include/MagicHitEffect.h"
#include "../../../include/MagicShaderHitEffect.h"
#include "../../../include/BGSAcousticSpace.h"
#include "../../../include/IngredientItem.h"
#include "../../../include/MagicItem.h"
#include "../../../include/TESActorBase.h"
#include "../../../include/TESTopicInfo.h"
#include "../../../include/EnchantmentItem.h"
#include "../../../include/SpellItem.h"
#include "../../../include/TES.h"

// @fnv 0x009d6b60
int MagicShaderHitEffect::GetType()
{
    return BSTempEffect::_Type::MAGIC_SHADER_HIT;
}


// @fnv 0x00409340
void SpellItem::ClearData()
{
    RemoveAllEffectItems();
}
// @fnv 0x00409310
void EnchantmentItem::ResetFormData()
{
    cost = 0xffffffff;
    charge = 0xffffffff;
    flags = 0;
    type = 2;
}

// @fnv 0x00409080
EnchantmentItem::EnchantmentItem()
{
    SetFormType((ENUM_FORM_ID)19);
    ResetFormData();
}

void __cdecl _Deallocate(void*);
struct FUN_00409160_Class
{
    void FUN_004092a0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004092a0, frees this when flags has bit 1 set, and returns this.
// @fnv 0x00409160
void* FUN_00409160_Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_004092a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Unnamed
{
    void __thiscall FUN_00409210();
    void* __thiscall FUN_00409270(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00409210, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00409270
void* __thiscall Unnamed::FUN_00409270(unsigned int flags)
{
    FUN_00409210();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct EP_008c48d0
{
    MagicItem* GetEntryPoint();
};
struct CP_008c48d0
{
    TESSound* GetPrevPath();
};
struct FUN_00409400_shell
{
    void CopySoundAndSpeakerData(MagicItem*);
};
// Casts actor to EnchantmentItem, then copies its conversation data, entry point, prev path and byte at 0x40 into fields of the object at this-0x18.
// @fnv 0x00409400
void FUN_00409400_shell::CopySoundAndSpeakerData(MagicItem* apItem)
{
    EnchantmentItem* info = dynamic_cast<EnchantmentItem*>(apItem);
    if (!info)
        return;
    ((BGSAcousticSpace*)((char*)this - 0x18))->SetNoonSound((TESSound*)((TESTopicInfo*)info)->GetConversationData());
    ((TESTopicInfo*)((char*)this - 0x18))->SetSpeaker(((EP_008c48d0*)info)->GetEntryPoint());
    ((TES*)((char*)this - 0x18))->SetDawnSound(((CP_008c48d0*)info)->GetPrevPath());
    ((char*)this)[0x28] = ((char*)info)[0x40];
}

namespace fnv_004094a0 {
struct FlaggedData
{
    bool ContainsAnyFlag(unsigned int);
};
struct EP_008c48d0
{
    void* GetEntryPoint();
};
struct S_004063e0
{
    float GetTotalCost(int);
};

struct FUN_004094a0_Class
{
    float EnchantmentItem_GetCost(int);
};

// Returns the entry point value as a float if the check on the object at this-0x24 passes, otherwise calls GetTotalCost(0).
// @fnv 0x004094a0
// src: COMMUNITY 0x004094a0
float FUN_004094a0_Class::EnchantmentItem_GetCost(int apActor)
{
    if (((FlaggedData*)((char*)this - 0x24))->ContainsAnyFlag(1))
    {
        return (float)(long)((EP_008c48d0*)((char*)this - 0x24))->GetEntryPoint();
    }
    else
    {
        return ((S_004063e0*)this)->GetTotalCost(0);
    }
}
}  // namespace fnv_004094a0

struct IMH
{
    int CombatController_GetCombatState(void);
};

struct FUN_00409fd0_shell : EnchantmentItem
{
    bool IngredientItem_CompareMagicItemData(MagicItem* apCompare);
};

// Returns true unless apCompare is an IngredientItem with the same FUN_00586150 value and matching byte at offset 0xa0 as this object.
// @fnv 0x00409fd0
// src: COMMUNITY 0x00409fd0
bool FUN_00409fd0_shell::IngredientItem_CompareMagicItemData(MagicItem* apCompare)
{
    EnchantmentItem* penchantment = (EnchantmentItem*)dynamic_cast<IngredientItem*>(apCompare);
    if (!penchantment)
        return true;
    if (((IMH*)((char*)penchantment))->CombatController_GetCombatState() != ((IMH*)((char*)this - 0x30))->CombatController_GetCombatState() ||
        *(unsigned char*)((char*)penchantment + 0xa0) != *(unsigned char*)((char*)this + 0x70))
        return true;
    return false;
}

struct PrimaryBase
{
    virtual ~PrimaryBase();
    unsigned int unk04, unk08, unk0c, unk10, unk14;
};
struct SecondaryBase
{
    virtual void access();
    unsigned int unk1c, unk20;
};
struct TertiaryBase
{
    virtual void access();
};
struct FUN_004092a0 : PrimaryBase, SecondaryBase, TertiaryBase
{
    void FUN_00409340();
    ~FUN_004092a0();
};
// Destructor that calls FUN_00409340 before the object is destroyed.
// @fnv 0x004092a0
FUN_004092a0::~FUN_004092a0()
{
    FUN_00409340();
}

struct EnchantmentComparison : PrimaryBase, MagicItem
{
    unsigned int type;
    unsigned int charge;
    unsigned int cost;
    unsigned char flags;
    unsigned int GetField38();
    unsigned int FUN_00639b40();
    unsigned int FUN_005f36f0();
    virtual bool IsMagicItemEqual(MagicItem* object);
};

// Returns true if the cast fails or any of three accessor results or flags differ; otherwise returns false.
// @fnv 0x00409360
bool EnchantmentComparison::IsMagicItemEqual(MagicItem* apMagicItem)
{
    EnchantmentItem* pEnchantmentItem = dynamic_cast<EnchantmentItem*>(apMagicItem);
    if (pEnchantmentItem == 0)
        return true;

    if (reinterpret_cast<EnchantmentComparison*>(pEnchantmentItem)->GetField38() != GetField38() ||
        reinterpret_cast<EnchantmentComparison*>(pEnchantmentItem)->FUN_00639b40() != FUN_00639b40() ||
        reinterpret_cast<EnchantmentComparison*>(pEnchantmentItem)->FUN_005f36f0() != FUN_005f36f0() ||
        pEnchantmentItem->flags != flags)
        return true;
    return false;
}
