#pragma once

#include "NiMaterialLibrary.h"

class NiMaterial;

class NiSingleShaderMaterialLibrary : public NiMaterialLibrary
{
public:
    NiSingleShaderMaterialLibrary();
    virtual ~NiSingleShaderMaterialLibrary();
    void* Destroy(unsigned int auiFlags);

    virtual NiMaterial* vf02(const NiFixedString* kName);
    virtual const char* GetShaderNameByIndex(unsigned int uiShaderIndex);
    virtual unsigned int vf04();
    virtual void* vf05();
    virtual void* vf06();

    int _c;
    int _d;
};
