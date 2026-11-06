#pragma once

#include "BaseFormComponent.h"

class MagicItemForm;
class TESForm;

class BGSTouchSpellForm : public BaseFormComponent
{
public:
    BGSTouchSpellForm();
    BGSTouchSpellForm& operator=(const BGSTouchSpellForm&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void InitItem(TESForm* owner);
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Initialize(unsigned int value);
    void FUN_00483170(unsigned short value);
    static MagicItemForm* GetFormTouchSpell(TESForm* form);
    MagicItemForm* GetFormTouchSpell();
    void SetFormTouchSpell(MagicItemForm* magicItem);
    static unsigned short GetFormTouchSpellAnimation(TESForm* form);
    unsigned short GetFormTouchSpellAnimation();
    void SetFormTouchSpellAnimation(unsigned short animation);

    MagicItemForm* m_pMagicItem;
    unsigned short m_usTouchSpellType;
    unsigned char layoutPaddingA[2];
};
