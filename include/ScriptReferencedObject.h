#pragma once

#include "TESFullName.h"

class TESForm;

class ScriptReferencedObject
{
public:
    BSStringT<char> m_kFormName;
    TESForm* pForm;
    unsigned int m_uiFormID;

    ScriptReferencedObject();
    ScriptReferencedObject(ScriptReferencedObject* source);
    ~ScriptReferencedObject();
};
