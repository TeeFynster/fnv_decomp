#pragma once

#include "TESForm.h"
#include "InteriorData.h"

class BGSLightingTemplate : public TESForm
{
public:
    InteriorData Data;

    BGSLightingTemplate();
    virtual ~BGSLightingTemplate();

    void ResetFormData();
    bool Load(TESFile* file);
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
};
