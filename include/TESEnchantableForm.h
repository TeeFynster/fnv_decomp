#pragma once

#include "BaseFormComponent.h"

class EnchantmentItem;
class TESForm;

#ifndef FNV64_MAGICSYSTEM_CASTINGTYPE_DEFINED
#define FNV64_MAGICSYSTEM_CASTINGTYPE_DEFINED
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
};
#endif

class TESEnchantableForm : public BaseFormComponent
{
public:
    TESEnchantableForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
    virtual int GetCastingType();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void SetCastingType(MagicSystem__CastingType type);
    void SetCastingType(int type);
    void Save();
    void InitItem(TESForm* form);
    static EnchantmentItem* FindFormEnchantment(TESForm* form);
    EnchantmentItem* FindFormEnchantment();
    EnchantmentItem* GetEnchantment();
    void SetFormEnchanting(EnchantmentItem* enchantment);
    static unsigned short GetFormEnchantmentAmount(TESForm* form);
    unsigned short GetFormEnchantmentAmount();
    void SetFormEnchantmentAmount(unsigned short amount);
    void FUN_00483170(unsigned short amount);
    EnchantmentItem* FUN_00726070();

    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;
};
