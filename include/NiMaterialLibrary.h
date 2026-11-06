#pragma once

#include "NiRefObject.h"
#include "NiFixedString.h"

class NiMaterialLibrary : public NiRefObject
{
public:
    __declspec(nothrow) NiMaterialLibrary(const NiFixedString& kName);
    virtual ~NiMaterialLibrary();

    NiFixedString m_kName;
};
