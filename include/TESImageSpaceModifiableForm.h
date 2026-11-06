#pragma once

#include "BaseFormComponent.h"

class TESForm;
class TESImageSpaceModifier;

class TESImageSpaceModifiableForm : public BaseFormComponent
{
public:
    TESImageSpaceModifiableForm();
    // no user destructor: BGSExplosion::BGSExplosion (0x004fabf0) keeps no unwind state for this base
    TESImageSpaceModifiableForm& operator=(const TESImageSpaceModifiableForm&);

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void InitItem(TESForm* form);
    TESImageSpaceModifier* GetFormImageSpaceModifying();
    void SetFormImageSpaceModifying(TESImageSpaceModifier* modifier);

    TESImageSpaceModifier* m_pImageSpaceModifier;
};
