#pragma once

#include "BaseFormComponent.h"

class TESForm;

class TESQualityForm : public BaseFormComponent
{
public:
    ~TESQualityForm();

    void InitializeComponent();
    void ClearComponent();
    void Save();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    static unsigned char GetFormQuality(TESForm* form);
    unsigned char GetFormQuality();
    void SetFormQuality(unsigned char quality);

    unsigned char m_ucFormQuality;
    char _pad_5[3];
};
