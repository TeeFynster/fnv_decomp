#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "ByteFlags.h"

class TESRecipeCategory : public TESForm, public TESFullName
{
public:
    ByteFlags data;
    unsigned char layoutPadding25[3];

    virtual bool LoadForm(TESFile* file);
    bool Load(TESFile* file);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);
};
