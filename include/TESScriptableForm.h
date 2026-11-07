#pragma once

#include "BaseFormComponent.h"

class Script;
class TESForm;

class TESScriptableForm : public BaseFormComponent
{
public:
    TESScriptableForm();

    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);

    void InitializeComponent();
    void ClearComponent();
    void BaseFormRecord(BaseFormComponent* component);
    bool IsEqualToBase(BaseFormComponent* component);
    void Save();
    void Initialize(unsigned int);
    void FUN_006ecd40(unsigned int);
    void Save_0048cca0();
    void* FUN_00726070();
    void InitItem(TESForm* form);
    static Script* GetScriptForForm(TESForm* form);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm* form);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm* form, Script* script);
    void SetFormScript(Script* script);
    Script* GetScript();
    void SetScript(Script* script);

    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
};
