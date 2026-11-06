#pragma once

#include "BaseFormComponent.h"

class TESForm;

class TESHealthForm : public BaseFormComponent
{
public:
    unsigned int m_uiHealthValue;

    TESHealthForm();
    ~TESHealthForm();

    virtual unsigned int GetHealth();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    unsigned int GetBaseHealth();
    static TESHealthForm* GetFormAsHealthForm(TESForm* form);
    static unsigned int GetBaseHealth(TESForm* form);
    void SetFormHealth(unsigned int health);
};
