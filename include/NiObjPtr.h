#pragma once

#include "NiRefObject.h"

class NiObj;

class NiObjPtr
{
public:
    NiRefObject* m_pObject;

    NiObjPtr& operator=(const NiObjPtr& other);
    ~NiObjPtr();
    NiObj* Modelloader_GetReferencedThis();
};
