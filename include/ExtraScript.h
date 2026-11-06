#pragma once

#include "BSExtraData.h"

class Script;
class ScriptLocals;

class ExtraScript : public BSExtraData
{
public:
    ExtraScript();
    ExtraScript(Script* aScript);
    virtual ~ExtraScript();
    virtual bool Compare(BSExtraData* pkOther);

    bool BaseCompare(BSExtraData* pkOther);
    bool CompareScriptExtra(BSExtraData* pkOther);
    void FUN_00432040();

    Script* pScript;
    ScriptLocals* m_pLocals;
};
