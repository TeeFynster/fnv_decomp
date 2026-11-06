#pragma once

#include "TESForm.h"

class TESLoadScreenType : public TESForm
{
public:
    TESLoadScreenType();
    virtual ~TESLoadScreenType();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    bool Load(TESFile* file);

    unsigned char formData[0x58];
};
