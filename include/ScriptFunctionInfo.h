#pragma once

class ScriptParameter;
class TESObjectREFR;
class Script;
class ScriptLocals;
class ScriptCallbackContext;
class CStringArgument;

#include "SCRIPT_OUTPUT.h"

typedef bool(__cdecl* FNVScriptExecuteFunction)(const ScriptParameter*, const char*, TESObjectREFR*, TESObjectREFR*,
                                               Script*, ScriptLocals*, double&, unsigned int&);
typedef bool(__cdecl* FNVScriptCompileFunction)(const unsigned short, const ScriptParameter*, ScriptCallbackContext*,
                                               CStringArgument*);
typedef bool(__cdecl* FNVScriptConditionFunction)(TESObjectREFR*, void*, void*, double&);

class ScriptFunctionInfo
{
public:
    char* pFunctionName;
    char* m_pShortName;
    SCRIPT_OUTPUT m_eOutputType;
    char* m_pDescription;
    bool m_bRequiresReference;
    unsigned char layoutPadding11;
    unsigned short m_usParameterCount;
    ScriptParameter* pParameters;
    FNVScriptExecuteFunction m_pfnExecute;
    FNVScriptCompileFunction m_pfnCompile;
    FNVScriptConditionFunction m_pfnCondition;
    bool m_bFunctionFlag;
    bool m_bSetsExecutionFlag;
    unsigned short layoutPadding26;
};
