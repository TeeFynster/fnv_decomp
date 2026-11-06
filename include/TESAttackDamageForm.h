#pragma once

#include "BaseFormComponent.h"

class TESForm;

class TESAttackDamageForm : public BaseFormComponent
{
public:
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    TESAttackDamageForm& operator=(const TESAttackDamageForm&);

    virtual void Free();
    virtual unsigned short GetAttackDamage();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static unsigned short GetAttackDamage(TESForm* form);
    void SetAttackDamage(unsigned short damage);
    unsigned short GetDamage();
    int GetResult();

    unsigned short m_usAttackDamage;
    unsigned char layoutPadding6[2];
};
