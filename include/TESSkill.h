#pragma once

#include "TESForm.h"
#include "TESDescription.h"
#include "TESTexture.h"

class TESSkill : public TESForm, public TESDescription, public TESTexture
{
public:
    TESSkill();
    virtual ~TESSkill();

    virtual void InitializeComponent();
    virtual bool __thiscall LoadForm(TESFile* file);
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void* DeleteThis(unsigned int flags);
    void ClearSourceFiles();
    void ResetData();
    void InitializeData_00617e80();

    unsigned char formData[0x34];
};
