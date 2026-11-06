#pragma once

#include "TESForm.h"
#include "TESModelTextureSwap.h"

class TESObjectANIO : public TESForm, public TESModelTextureSwap
{
public:
    TESObjectANIO();

    virtual bool LoadForm(TESFile* file);
    virtual void InitItem();

    bool Load(TESFile* file);

    TESObjectANIO* pObject;
};
