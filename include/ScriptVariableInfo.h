#pragma once

#include "TESFullName.h"
#include "ScriptLocalVariable.h"

class TESFile;

class ScriptVariableInfo
{
public:
    union
    {
        struct
        {
            ScriptLocalVariable data;
        };
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0c;
            int unk10;
            int unk14;
        };
    };
    BSStringT<char> name;

    __declspec(property(get=GetNameStorage, put=SetNameStorage)) BSStringT<char> m_kName;
    __declspec(property(get=GetNameStorage, put=SetNameStorage)) BSStringT<char> m_name;

    ScriptVariableInfo();

    BSStringT<char>& GetNameStorage() { return name; }
    const BSStringT<char>& GetNameStorage() const { return name; }
    void SetNameStorage(const BSStringT<char>& value) { name = value; }

    void Load(TESFile* file);
};
