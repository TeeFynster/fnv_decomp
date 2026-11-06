#pragma once

#include "BaseFormComponent.h"

class TESForm;
class TESRace;

class TESRaceForm : public BaseFormComponent
{
public:
    TESRaceForm();

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void InitItem(TESForm* owner);
    void Initialize(unsigned int flags);
    static TESRace* GetFormRace(TESForm* form);
    TESRace* GetFormRace();
    TESRace* GetFormRace() const;
    static char* GetFormRaceEditorID(TESForm* form);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace* race);

    TESRace* m_pRace;
};
