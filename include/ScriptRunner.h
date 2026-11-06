#pragma once

#include "ExpressionEvaluator.h"
#include "ScriptFunctionInfo.h"

class TESObjectREFR;
class TESObject;
class ScriptLocals;
class TESTopicInfo;
class TESGlobal;
class Script;

#include "SCRIPT_ERROR.h"

class ScriptRunner
{
public:
    TESObjectREFR* m_pReference;
    TESObject* m_pScriptObject;
    ScriptLocals* m_pScriptLocals;
    TESTopicInfo* m_pTopicInfo;
    TESGlobal* m_pGlobal;
    Script* m_pScript;
    SCRIPT_ERROR m_eScriptError;
    EXPRESSION_ERROR m_eExpressionError;
    int m_iIfStackDepth;
    int m_aiIfStack[10];
    int m_iBlockStackDepth;
    int m_aiBlockOffsets[10];
    int m_aiBlockSizes[10];
    bool m_bScriptCompileFailed;
    bool m_bExecutionFlagSet;

    ScriptRunner();
    bool ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                     TESObjectREFR** reference, bool skipReference);
    void SetErrorMessage(Script* script, char* message, ...);
    bool ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                    const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber,
                    bool skip, bool skipBlock);
    void SetError(Script* script, SCRIPT_ERROR error);
    bool SetScriptLocalsFromExtraData(Script* script, TESObjectREFR* reference, ScriptLocals* locals);
    bool RunScript(Script* script, TESObjectREFR* reference, ScriptLocals* locals);
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target,
             bool arg5, bool arg6, bool arg7, float arg8);
};
