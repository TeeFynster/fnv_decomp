#pragma once

#include "BaseFormComponent.h"

class TESForm;

class TESWeightForm : public BaseFormComponent
{
public:
    TESWeightForm();
    ~TESWeightForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    static float GetWeightForForm(TESForm* form, bool useFormWeight);
    float GetWeightForForm();
    float GetWeightForForm() const;
    void SetFormWeight(float weight);

    float fWeight;
};
