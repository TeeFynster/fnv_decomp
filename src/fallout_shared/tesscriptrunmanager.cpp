#include "../../include/ScriptExecutor.h"
// fallout_shared/tesscriptrunmanager.cpp: ScriptRunner, ScriptExecutor (11 functions)

#include "../../include/BSStringT.h"
#include "../../include/ScriptRunner.h"
#include "../../include/Script.h"
#include "../../include/ScriptReferencedObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESObjectCELL.h"
#include "../../include/ScriptLocals.h"
#include "../../include/TESQuest.h"
#include "../../include/TESGlobal.h"
#include "game_constants.h"
#include <new>



ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);
int Warning(const char* format, ...);
bool ExtractArgs(const ScriptParameter* parameters, const char* data, unsigned int* offset,
                 TESObjectREFR* reference, TESObjectREFR* container, Script* script, ScriptLocals* locals, ...);
extern "C" const char g_nestedScriptRunFormat[];
extern "C" char g_scriptRunLock;
extern int __cdecl InitScriptRunLock(void* lock);
extern void __cdecl FinishScriptRunLock(void* lock);
extern ScriptFunctionInfo g_scriptBlocks[kScriptBlockCount];
extern const char* g_expressionErrorStrings[];
extern void DebugLog(const char* format, ...);
extern bool IsScriptDebuggingEnabled();
extern const char* PrepareScriptMessage(const char* message, bool localized);

// Reads the output opcode, optional reference ID and line size from the script data at offset, resolving the reference and reporting an error if it is unknown.
// @fnv 0x005e13a0
bool ScriptRunner::ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                               TESObjectREFR** ppReference, bool skipReference)
{
    lineSize = 0;
    output = static_cast<SCRIPT_OUTPUT>(*reinterpret_cast<short*>(script->GetData() + offset));
    offset += 2;
    if (output == SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION)
    {
        bool isVariable = false;
        unsigned int referenceID = *reinterpret_cast<short*>(script->GetData() + offset);
        offset += 2;
        if (!skipReference)
        {
            ScriptReferencedObject* object = script->GetReferencedForm(referenceID, m_pScriptLocals);
            if (object)
            {
                isVariable = object->m_uiFormID > 0;
                if (object->pForm)
                {
                    *ppReference = dynamic_cast<TESObjectREFR*>(object->pForm);
                }
            }
        }
        output = static_cast<SCRIPT_OUTPUT>(*reinterpret_cast<short*>(script->GetData() + offset));
        offset += 2;
        if (!skipReference && !*ppReference && !isVariable)
        {
            ScriptFunctionInfo* function = GetFunctionByOpcode(output);
            if (function)
            {
                SetErrorMessage(script,
                                "Unknown reference object for function '%s'.  Execution of script '%s' stopped.",
                                function->pFunctionName, script->GetName());
            }
            else
            {
                SetErrorMessage(script, "Unknown reference object.  Execution of script '%s' stopped.",
                                script->GetName());
            }
            return false;
        }
    }
    else
    {
        *ppReference = 0;
    }
    lineSize = *reinterpret_cast<short*>(script->GetData() + offset);
    offset += 2;
    return true;
}

// Executes one script command at the given offset, handling BEGIN blocks, SET, IF/ELSEIF/ELSE/ENDIF and function calls, updating blockSize and lineOffset.
// @fnv 0x005e1550
bool ScriptRunner::ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                              const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber,
                              bool skip, bool skipBlock)
{
    unsigned int offset = inputOffset;
    const char* data = script->GetData();
    if (output == SCRIPT_OUTPUT_FLOW_BEGIN)
    {
        int blockID = *reinterpret_cast<const short*>(data + offset);
        offset += 2;
        if (blockID < 0 || blockID >= kScriptBlockCount)
        {
            Warning("Invalid script block for BEGIN on line %i of script '%s' (%08X).", lineNumber, script->GetName(),
                    script->GetFormID());
            return false;
        }
        int skipSize = *reinterpret_cast<const int*>(data + offset);
        offset += 4;
        const ScriptParameter* blockParams = g_scriptBlocks[blockID].pParameters;
        FNVScriptExecuteFunction blockExecute = g_scriptBlocks[blockID].m_pfnExecute;
        if (skip)
        {
            if (blockParams && blockSize)
                ExtractArgs(blockParams, data, &offset, reference, m_pReference, script, m_pScriptLocals);
        }
        else
        {
            if (g_scriptBlocks[blockID].m_bRequiresReference && !reference)
            {
                Warning("SCRIPTS: Script '%s', line %d: Null for a required ref pointer.", script->GetName(),
                        lineNumber);
                return false;
            }
            double result;
            if (!blockExecute ||
                !blockExecute(blockParams, data, reference, m_pReference, script, m_pScriptLocals, result, offset))
            {
                Warning("SCRIPTS: Script '%s', line %d: Error Executing line (Offset %d).", script->GetName(),
                        lineNumber, offset);
                return false;
            }
            if (!result || skipBlock)
                blockSize += skipSize;
        }
    }
    else if (!skipBlock)
    {
        const ScriptFunctionInfo* function;
        switch (output)
        {
        case SCRIPT_OUTPUT_FLOW_SCRIPTNAME:
            break;
        case SCRIPT_OUTPUT_FLOW_BEGIN:
            break;
        case SCRIPT_OUTPUT_FLOW_END:
            break;
        case SCRIPT_OUTPUT_FLOW_SET: {
            char varType = data[offset];
            offset++;
            short variableID = 0;
            ScriptLocals* currentPScriptVariables = m_pScriptLocals;
            ScriptReferencedObject* referencedObject = 0;
            switch (varType)
            {
            case kScriptGlobalVariable:
            case kScriptReferenceVariable: {
                short referenceID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
                if (varType == kScriptReferenceVariable)
                {
                    varType = data[offset];
                    offset++;
                }
                referencedObject = script->GetReferencedForm(referenceID, m_pScriptLocals);
                if (!skip)
                {
                    if (varType != kScriptReferenceVariable && referencedObject && referencedObject->pForm)
                    {
                        TESObjectREFR* object = dynamic_cast<TESObjectREFR*>(referencedObject->pForm);
                        if (object)
                            currentPScriptVariables = object->GetReferenceLocals();
                        else
                        {
                            TESQuest* quest = dynamic_cast<TESQuest*>(referencedObject->pForm);
                            if (quest)
                                currentPScriptVariables = quest->GetScriptLocalData();
                        }
                        if (!currentPScriptVariables)
                        {
                            Warning("Missing script variables on object for SET on line %i of script '%s' (%08X).",
                                    lineNumber, script->GetName(), script->GetFormID());
                            return false;
                        }
                    }
                    else
                    {
                        Warning("Missing ref object in SET on line %i of script '%s' (%08X).", lineNumber,
                                script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
            break;
            }
            switch (varType)
            {
            case kScriptGlobalVariable:
                break;
            default: {
                variableID = *reinterpret_cast<const short*>(data + offset);
                offset += 2;
            }
            break;
            }
            short expressionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator variableExpression;
            double expressionValue = variableExpression.Eval(data + offset, reference, m_pReference, script,
                                                             m_pScriptLocals, expressionSize, skip);
            offset += expressionSize;
            if (variableExpression.ExpressionError())
            {
                Warning("SCRIPTS: Script '%s', line %d: Set expression returned an error: %s.\r\n", script->GetName(),
                        lineNumber, g_expressionErrorStrings[variableExpression.ExpressionError()]);
                script->GetHeader()->dataSize = 0;
                return false;
            }
            if (!skip)
            {
                if (varType == kScriptGlobalVariable)
                {
                    if (referencedObject && referencedObject->pForm)
                    {
                        if (!skip)
                        {
                            static_cast<TESGlobal*>(referencedObject->pForm)
                                ->SetValue(static_cast<float>(expressionValue));
                            if (IsScriptDebuggingEnabled())
                                DebugLog("set global >> %0.2f", static_cast<float>(expressionValue));
                        }
                    }
                    else
                    {
                        Warning("Invalid variable type for SET on line %i of script '%s' (%08X).", lineNumber,
                                script->GetName(), script->GetFormID());
                        return false;
                    }
                }
                else
                {
                    if (currentPScriptVariables)
                    {
                        switch (varType)
                        {
                        case kScriptLongVariable:
                        case kScriptShortVariable:
                            currentPScriptVariables->SetVariable(variableID, static_cast<int>(expressionValue));
                            if (IsScriptDebuggingEnabled())
                                DebugLog("set %s >> %i",
                                         currentPScriptVariables->m_pOwnerScript->GetVariableName(variableID),
                                         static_cast<int>(expressionValue));
                            break;
                        case kScriptFloatVariable:
                            currentPScriptVariables->SetVariable(variableID, expressionValue);
                            if (IsScriptDebuggingEnabled())
                                DebugLog("set %s >> %.2f",
                                         currentPScriptVariables->m_pOwnerScript->GetVariableName(variableID),
                                         expressionValue);
                            break;
                        }
                        if ((referencedObject && referencedObject->pForm) || reference)
                        {
                            TESObjectREFR* changedReference = 0;
                            if (referencedObject)
                            {
                                if (referencedObject->pForm && referencedObject->pForm->GetIsReference())
                                    changedReference = static_cast<TESObjectREFR*>(referencedObject->pForm);
                            }
                            else
                                changedReference = reference;
                            if (changedReference && !changedReference->IsTemporary())
                            {
                                if (!changedReference->GetParentCell() ||
                                    !changedReference->GetParentCell()->IsOutdoorCell())
                                    changedReference->MarkAsModified(TESObjectREFR::CHANGE_SCRIPT_VARIABLES);
                            }
                        }
                    }
                    else
                    {
                        Warning("Missing scriptvariables for object in SET on line %i of script '%s' (%08X).",
                                lineNumber, script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
            break;
        }
        case SCRIPT_OUTPUT_FLOW_IF:
            if (m_aiIfStack[m_iIfStackDepth])
                m_iIfStackDepth++;
            m_aiIfStack[m_iIfStackDepth] = kScriptIfActiveFlag;
        case SCRIPT_OUTPUT_FLOW_ELSEIF: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            short conditionSize = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            ExpressionEvaluator condition;
            if (skip)
            {
                condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize, skip);
                m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
            }
            else
            {
                if (!(m_aiIfStack[m_iIfStackDepth] & kScriptIfConditionPassedFlag) &&
                    condition.Eval(data + offset, reference, m_pReference, script, m_pScriptLocals, conditionSize,
                                   skip))
                    m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
                else
                    lineOffset += skipCount;
            }
            if (condition.ExpressionError())
            {
                SetError(script, SCRIPT_ERROR_ERROR_SCRIPT_EXPRESSION);
                Warning("SCRIPTS: Script '%s', line %d: failed to evaluate expression.", script->GetName(), lineNumber);
                script->GetHeader()->dataSize = 0;
                m_eExpressionError = condition.ExpressionError();
                return false;
            }
            offset += conditionSize;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ELSE: {
            short skipCount = *reinterpret_cast<const short*>(data + offset);
            offset += 2;
            if (!(m_aiIfStack[m_iIfStackDepth] & kScriptIfConditionPassedFlag))
                m_aiIfStack[m_iIfStackDepth] |= kScriptIfConditionPassedFlag;
            else if (!skip)
                lineOffset += skipCount;
            break;
        }
        case SCRIPT_OUTPUT_FLOW_ENDIF:
            m_aiIfStack[m_iIfStackDepth] = 0;
            if (m_iIfStackDepth)
                m_iIfStackDepth--;
            break;
        case SCRIPT_OUTPUT_FLOW_REFERENCE_FUNCTION:
            break;
        case SCRIPT_OUTPUT_FLOW_RETURN:
            if (skip)
                break;
        default: {
            function = GetFunctionByOpcode(output);
            if (!function)
            {
                BSStringT<char> message;
                message.PrintfString("SCRIPTS: Unable to find function definition for command %d in script '%s'.", output,
                                script->GetName());
                if (IsScriptDebuggingEnabled())
                    DebugLog(PrepareScriptMessage(message.String(), false));
                else
                    Warning(PrepareScriptMessage(message.String(), false));
                return false;
            }
            else
            {
                const ScriptParameter* blockParams = function->pParameters;
                if (function->m_bRequiresReference && !reference && !skip)
                {
                    BSStringT<char> message;
                    message.PrintfString("SCRIPTS: Script '%s', line %d: Function '%s' requires a reference.",
                                    script->GetName(), lineNumber, function->pFunctionName);
                    if (IsScriptDebuggingEnabled())
                        DebugLog(PrepareScriptMessage(message.String(), false));
                    else
                        Warning(PrepareScriptMessage(message.String(), false));
                    return false;
                }
                if (skip)
                {
                    if (blockParams && blockSize)
                    {
                        ExtractArgs(blockParams, data, &offset, reference, m_pReference, script, m_pScriptLocals);
                        switch (output)
                        {
                        case SCRIPT_OUTPUT_FUNCTION_MESSAGE: {
                            short valueCount = *reinterpret_cast<const short*>(data + offset);
                            offset += 2;
                            for (short valueIndex = 0; valueIndex < valueCount; valueIndex++)
                            {
                                double expressionValue;
                                Script::GetValue(expressionValue, data, offset, reference, m_pReference, script,
                                                 m_pScriptLocals, true);
                            }
                            offset += 4;
                            break;
                        }
                        }
                    }
                }
                else
                {
                    FNVScriptExecuteFunction blockExecute = function->m_pfnExecute;
                    if (function->m_bSetsExecutionFlag)
                        m_bExecutionFlagSet = true;
                    double result;
                    if (!blockExecute || !blockExecute(blockParams, data, reference, m_pReference, script,
                                                       m_pScriptLocals, result, offset))
                    {
                        Warning("Failed to execute function '%s' on line %i of script '%s' (%08X).",
                                function->pFunctionName, lineNumber, script->GetName(), script->GetFormID());
                        return false;
                    }
                }
            }
        }
        }
    }
    return true;
}

// Returns a pointer to the function-local static instance of the class.
// @fnv 0x005e24d0
ScriptExecutor* ScriptExecutor::Instance()
{
    static ScriptExecutor manager;
    return &manager;
}

// Acquires the script run lock, runs the script through a shared or temporary ScriptRunner, then releases the lock and returns the result.
// @fnv 0x005e2590
bool ScriptExecutor::Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target,
                         bool arg5, bool arg6, bool arg7, float arg8)
{
    bool result = false;
    if (InitScriptRunLock(&g_scriptRunLock) == 1)
    {
        if (!m_pReusableScriptRunner)
            m_pReusableScriptRunner = new ScriptRunner;
        m_pActiveScriptRunner = m_pReusableScriptRunner;
        result = m_pReusableScriptRunner->Run(script, reference, locals, target, arg5, arg6, arg7, arg8);
        m_pActiveScriptRunner = 0;
    }
    else
    {
        ScriptRunner* runner = new ScriptRunner;
        ScriptRunner* previousRunner = m_pActiveScriptRunner;
        m_pActiveScriptRunner = runner;
        result = runner->Run(script, reference, locals, target, arg5, arg6, arg7, arg8);
        m_pActiveScriptRunner = previousRunner;
        delete runner;
    }
    FinishScriptRunLock(&g_scriptRunLock);
    return result;
}

void* __cdecl memset(void*, int, unsigned int);

// Initializes the runner's script state and execution stacks.
// @fnv 0x005e0c60
ScriptRunner::ScriptRunner()
{
    m_iIfStackDepth = 0;
    m_iBlockStackDepth = 0;
    m_eScriptError = SCRIPT_ERROR_ERROR_SCRIPT_NOERROR;
    m_eExpressionError = EXPRESSION_ERROR_ERROR_EXPRESSION_NOERROR;
    memset(m_aiIfStack, 0, sizeof(m_aiIfStack));
    memset(m_aiBlockOffsets, 0, sizeof(m_aiBlockOffsets));
    memset(m_aiBlockSizes, 0, sizeof(m_aiBlockSizes));
    m_pReference = 0;
    m_pScriptObject = 0;
    m_pScriptLocals = 0;
    m_pTopicInfo = 0;
    m_pGlobal = 0;
    m_pScript = 0;
    m_bScriptCompileFailed = false;
    m_bExecutionFlagSet = false;
}

struct TLSData_005e23f0
{
    char pad[0x268];
    bool bVal;
};

static __declspec(thread) TLSData_005e23f0 s_tlsData_005e23f0;

// @fnv 0x005e23f0
bool __cdecl GetThreadLocalValue()
{
    return s_tlsData_005e23f0.bVal;
}

int __cdecl BSvsprintf(char* buffer, char const* format, char* varArgs);

// Formats a message into a local buffer, logs it via DebugLog or Warning, then zeroes the script header size and flags the runner as failed.
// @fnv 0x005e2410
void ScriptRunner::SetErrorMessage(Script* apScript, char* apFormat, ...)
{
    char buffer[260];
    char* varArgs;

    varArgs = (char*)(&apFormat + 1);
    BSvsprintf(buffer, apFormat, varArgs);
    varArgs = 0;

    if (IsScriptDebuggingEnabled())
    {
        DebugLog(PrepareScriptMessage(buffer, false));
    }
    else
    {
        Warning(PrepareScriptMessage(buffer, false));
    }

    apScript->GetHeader()->dataSize = 0;
    m_bScriptCompileFailed = true;
}

// @fnv 0x005e24b0
void ScriptRunner::SetError(Script* script, SCRIPT_ERROR error)
{
    m_eScriptError = error;
}

extern void __cdecl _Deallocate(void*);

// Releases the reusable runner and clears the active runner.
// @fnv 0x005e2550
ScriptExecutor::~ScriptExecutor()
{
    void* tmp;
    if (m_pReusableScriptRunner)
    {
        tmp = m_pReusableScriptRunner;
        _Deallocate(tmp);
        m_pReusableScriptRunner = 0;
    }
    m_pActiveScriptRunner = 0;
}

// The shared runner header does not yet declare the active-state query.
extern bool __fastcall IsScriptRunnerActive(ScriptRunner* runner);

// Creates a ScriptRunner if needed, then calls RunScript on either it or a temporary runner.
// @fnv 0x005e2730
// src: XBOX_PDB 0x005e2730
bool ScriptExecutor::ScriptRunManager_InitActionList(Script* apScript, TESObjectREFR* apOwnerObject, ScriptLocals* apOwnerVars)
{
    if (!m_pReusableScriptRunner)
        m_pReusableScriptRunner = new ScriptRunner;
    if (IsScriptRunnerActive(m_pReusableScriptRunner))
    {
        ScriptRunner* pTempScriptRunner = new ScriptRunner;
        pTempScriptRunner->RunScript(apScript, apOwnerObject, apOwnerVars);
        delete pTempScriptRunner;
    }
    else
    {
        m_pReusableScriptRunner->RunScript(apScript, apOwnerObject, apOwnerVars);
    }
    return true;
}

// Parses script output blocks, updates m_pScriptObject and m_pScriptLocals, and returns true after the loop.
// @fnv 0x005e1160
bool ScriptRunner::RunScript(Script* script, TESObjectREFR* reference, ScriptLocals* locals)
{
    if (!script || !script->GetInitialized())
        return false;
    if (m_pScript)
    {
        Warning(g_nestedScriptRunFormat, m_pScript->GetName(), script->GetName());
        return false;
    }
    m_pScript = script;
    ExpressionEvaluator j;
    SCRIPT_OUTPUT k = (SCRIPT_OUTPUT)0xffff;
    unsigned int c = 0;
    if (reference)
        m_pScriptObject = reference->GetObjectReference();
    else
        m_pScriptObject = 0;
    m_pScriptLocals = locals;
    int q = 0;
    TESObjectREFR* b = 0;
    unsigned int f = 0;
    bool l = false;
    unsigned int e = 0;
    while (c < script->GetHeader()->dataSize)
    {
        e += 1;
        m_pGlobal = 0;
        q = 0;
        if (!ParseOutput(script, k, c, q, &b, f != 0))
        {
            script->GetHeader()->dataSize = 0;
            break;
        }
        if (f != 0)
        {
            f -= 1;
        }
        else
        {
            if (!b)
                b = reference;
            if (!ParseBlock(script, k, b, q, c, f, e, false, true))
            {
                l = true;
                break;
            }
        }
        c += q;
    }
    m_pScript = 0;
    return true;
}
