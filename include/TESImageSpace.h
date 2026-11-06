#pragma once

#include "TESForm.h"
#include "ImageSpaceModifierParameterData.h"

struct TESImageSpace : public TESForm
{
public:
    union
    {
        unsigned char formData[0x98];
        ImageSpaceModifierParameterData Data;
    };

    TESImageSpace();
    virtual ~TESImageSpace();
    virtual void InitializeComponent();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void InitDefaults();
    void ResetFormData();
    bool Load(TESFile* file);
    void Save();
    void Copy(TESForm* form);
    void* DestroyAndDeallocate(unsigned int flags);
};
