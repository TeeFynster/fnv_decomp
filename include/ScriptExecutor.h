#pragma once

class Script;
class ScriptLocals;
class ScriptRunner;
class TESObjectREFR;

class ScriptExecutor
{
public:
    ScriptRunner* m_pReusableScriptRunner;
    ScriptRunner* m_pActiveScriptRunner;

    ScriptExecutor();
    ~ScriptExecutor();
    static ScriptExecutor* Instance();
    bool ScriptRunManager_InitActionList(Script* script, TESObjectREFR* ref, ScriptLocals* locals); // returns bool (body in tesscriptrunmanager.cpp)
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target,
             bool arg5, bool arg6, bool arg7, float arg8);
};
