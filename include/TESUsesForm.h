#pragma once

#include "BaseFormComponent.h"

class TESForm;

class TESUsesForm : public BaseFormComponent
{
public:
    ~TESUsesForm();

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static int GetFormUses(TESForm* form);
    int GetFormUses();
    void SetFormUses(int uses);

    unsigned char m_ucUses;
    char _pad_5[3];
};
