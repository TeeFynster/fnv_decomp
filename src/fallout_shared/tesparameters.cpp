// fallout_shared/tesparameters.cpp: ScriptFunctionData, TESConditionItem (5 functions)

#include "tesparameters.h"
#include "../../include/TESForm.h"
#include "../../include/TESConditionItem.h"
#include "../../include/BSStringT.h"
#include "../../include/Script.h"
#include "../../include/ScriptFunctionInfo.h"

// @fnv 0x006814e0
bool TESConditionItem::GetValueIsGlobal() const
{
    if (m_flags & 4)
        return true;
    return false;
}

// Returns the parameter count of the script command for apData's function, or 0 if apData is null.
// @fnv 0x00682270
unsigned int ScriptFunctionData::GetParamCount(const FunctionData* apData)
{
    unsigned int count = 0;
    if (apData)
        count = g_scriptCommands[apData->usFunction].m_usParameterCount;
    return count;
}

// Returns whether the given function parameter is a TESForm, checking the special function case and otherwise the command's parameter type table.
// @fnv 0x006822a0
bool ScriptFunctionData::IsParamTESForm(const FunctionData* apData, unsigned int auiParam)
{
    bool isTESForm = false;
    if (apData && apData->usFunction + 0x1000 == 0x1198)
        isTESForm = IsValidTypeValue(apData, auiParam);
    else if (apData && auiParam < GetParamCount(apData))
        isTESForm = DAT_0118cdd5[reinterpret_cast<ParamInfo*>(g_scriptCommands[apData->usFunction].pParameters)[auiParam].typeID].isTESForm;
    return isTESForm;
}

// Resolves each parameter of a script function data block to a form or script variable, warning when a form or variable cannot be found.
// @fnv 0x00681fb0
void ScriptFunctionData::InitItem(TESForm* apForm, FunctionData* apData)
{
    if (apForm)
    {
        if (apData)
        {
            unsigned int paramCount = GetParamCount(apData);
            TESFile* file = apForm ? apForm->GetFile(-1) : 0;
            for (unsigned int uiIndex = 0; uiIndex < paramCount; ++uiIndex)
            {
                if (IsParamTESForm(apData, uiIndex))
                {
                    unsigned int formID = apData->uParam[uiIndex].m_uiFormID;
                    if (formID)
                    {
                        TESForm::RemapFormIDForFile(formID, file);
                        apData->uParam[uiIndex].pPointer = TESForm::GetFormByID(formID);
                        if (!apData->uParam[uiIndex].pPointer)
                        {
                            BSStringT<char> strFormName;
                            apForm->GetDebugName(&strFormName);
                            Warning(DAT_01069608, formID, strFormName.String());
                        }
                        else if (DAT_0118cdd0[reinterpret_cast<ParamInfo*>(g_scriptCommands[apData->usFunction].pParameters)[uiIndex].typeID].type == 11)
                        {
                            apData->uParam[uiIndex].pPointer = __RTDynamicCast(
                                apData->uParam[uiIndex].pPointer, 0, (void*)&typeid(TESForm), DAT_01183140, 0);
                            if (!apData->uParam[uiIndex].pPointer)
                            {
                                BSStringT<char> strFormName;
                                apForm->GetDebugName(&strFormName);
                                Warning(DAT_010695a8, formID, strFormName.String());
                            }
                        }
                    }
                }
                else if (GetParamIsScriptVariable(apData, uiIndex))
                {
                    if (uiIndex > 0)
                    {
                        Script* script = GetScriptForParam(uiIndex - 1, apData);
                        if (script && !script->GetVariableName(apData->uParam[uiIndex].m_uiFormID))
                        {
                            BSStringT<char> strFormName;
                            apForm->GetDebugName(&strFormName);
                            Warning(DAT_01069540, apData->uParam[uiIndex].m_uiFormID,
                                    script->GetName(), strFormName.String());
                        }
                    }
                }
            }
        }
    }
}

// Returns true when the parameter at aiParam of apFuncData has type 4 or 6, after bounds-checking against the function's parameter count.
// @fnv 0x00682320
// src: COMMUNITY 0x00682320
bool __cdecl TESParameters_GetParamIsReference(const FunctionData* apFuncData, unsigned int aiParam)
{
    bool bretval = false;
    if (apFuncData && aiParam < ScriptFunctionData::GetParamCount(apFuncData))
    {
        switch (reinterpret_cast<ParamInfo*>(g_scriptCommands[apFuncData->usFunction].pParameters)[aiParam].typeID)
        {
        case 4:
        case 6:
            bretval = true;
            break;
        }
    }
    return bretval;
}
