// fallout_shared/tesconditionitem.cpp: TESConditionItem, ConditionSerializer (11 functions)

#include "layout_support.h"
#include "../../include/Actor.h"
#include "../../include/NiPointer.h"
#include "../../include/TESConditionItem.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/TESTopic.h"
#include "../../include/TESTopicInfo.h"
#include "../../include/TESTopicInfoData.h"
#include "tesconditionitem_packet.h"

enum
{
    kConditionDataChunk = 0x41445443
};

#include <cstring>

// Zero-initialises the condition item and sets its function code to 0x1048.
// @fnv 0x006811e0
TESConditionItem::TESConditionItem()
{
    memset(this, 0, sizeof(TESConditionItem));
    m_objectRef = 0;
    SetFunction(0x1048);
}

// @fnv 0x00681490
float TESConditionItem::GetConditionValue()
{
    float value = 0.0f;
    if (GetParamCount())
    {
        if (m_comparisonGlobal)
            value = m_comparisonGlobal->GetValue();
    }
    else
    {
        value = m_comparisonValue;
    }
    return value;
}

// Loads a TESConditionItem from a TESFile chunk, applies endian fixup, and derives the object type from m_flags bits 2 and 8.
// @fnv 0x00681950
void TESConditionItem::Load(TESFile* file)
{
    if (file && file->GetChunkID() == kConditionDataChunk)
    {
        file->GetChunkData(this, sizeof(TESConditionItem));
        if (file->IsEndianConversionRequired())
            FixupAfterLoad();
    }
    if (m_flags & 2)
    {
        SetObjectType(1);
        m_flags &= ~2;
    }
    if (m_flags & 8)
    {
        SetObjectType(2);
        m_flags &= ~8;
    }
}

// Local spellings are retained for MSVC9 stack-home ordering.
// pData is the boolean result, pParam the evaluated number, pTarget the
// selected subject, pSubject the other reference, bResult the first parameter,
// and dValue the function data.
// Evaluates the condition item's script function against the subject/target references and compares the result to the comparison value.
// @fnv 0x00681600
bool TESConditionItem::ContainsTrait(TESObjectREFR* pSubjectRef, TESObjectREFR* target, bool& special)
{
    bool pData = false;
    double pParam = 0.0;
    TESObjectREFR* pTarget = pSubjectRef;
    TESObjectREFR* pSubject = target;
    special = false;
    switch (((TimeGlobal*)this)->GetTimeStamp())
    {
    case 0:
        break;
    case 1:
        pTarget = pSubject;
        pSubject = pSubjectRef;
        break;
    case 2:
        pTarget = m_objectRef;
        break;
    case 3:
        pTarget = 0;
        pSubject = pSubjectRef;
        if (pSubjectRef && pSubjectRef->IsActor())
        {
            Actor* pActor = (Actor*)pSubjectRef;
            pTarget = pActor->GetCombatTarget();
        }
        break;
    case 4:
        pTarget = 0;
        pSubject = 0;
        if (pSubjectRef)
            pTarget = pSubjectRef->GetLinkedRef();
        break;
    }
    FUNCTION_DATA* dValue = (FUNCTION_DATA*)((TESTopicInfoData*)this)->GetLinkToList();
    TESObjectREFR* bResult = dValue->param;
    if (!bResult && ScriptFunctionData::GetParamIsReference(dValue, 0))
        bResult = pSubject;
    if (g_scriptCommands[dValue->function].eval && (!g_scriptCommands[dValue->function].needsRef || pTarget))
    {
        if (g_scriptCommands[dValue->function].eval(pTarget, bResult, dValue->param2, pParam))
        {
            float fComparison;
            if (m_comparisonGlobal && GetParamCount())
                fComparison = m_comparisonGlobal->GetValue();
            else
                fComparison = m_comparisonValue;
            pData = ::Compare(GetComparisonCondition(), (float)pParam, fComparison);
            if (!pData)
            {
                unsigned int uiFunction = GetConditionFunction() + 0x1000;
                switch (uiFunction)
                {
                case 0x104c:
                    if (GetComparisonCondition() == 2 || GetComparisonCondition() == 3)
                        special = true;
                    break;
                case 0x1193:
                    special = true;
                    break;
                }
            }
        }
    }
    return pData;
}

// In the diagnostic scopes, info holds display text, topic holds the topic
// info form, quest holds its topic, and text holds its quest. These spellings
// preserve the original compiler allocation order.
// @fnv 0x006819e0
void TESConditionItem::InitItem(TESForm* owner)
{
    ScriptFunctionData::InitItem(owner, (FUNCTION_DATA*)((TESTopicInfoData*)this)->GetLinkToList());
    unsigned int referenceID = (unsigned int)m_objectRef;
    if (referenceID)
    {
        TESForm::RemapFormIDForFile(referenceID, owner->GetFile(-1));
        m_objectRef = dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(referenceID));
        if (!m_objectRef)
        {
            if (owner)
                Warning(DAT_010694b0, referenceID, owner->TESForm_GetFormTypeString(), owner->GetName(), owner->GetFormID());
            else
                Warning(DAT_01069458, referenceID);
        }
    }
    if (!g_scriptCommands[GetConditionFunction()].eval)
    {
        char buffer[0x410];
        if (((const TESForm*)owner)->GetFormType() == 0x46)
        {
            TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(owner);
            TESTopic* quest = TESTopic::GetTopicFromInfo(topic);
            TESQuest* text = 0;
            if (quest)
                text = quest->GetParentQuest(topic);
            BSStringT<char> info;
            topic->FormatDebugInfo(info, false);
            sprintf(buffer, DAT_0104cae0, topic->GetFormID(), ((NiPointer<NiNode>*)&info)->operator->(),
                    text ? text->GetEditorName() : g_011c72c0_arg1, text ? text->GetFormID() : 0,
                    quest ? quest->GetName() : g_011c72c0_arg1, quest ? quest->GetFormID() : 0);
        }
        else
        {
            sprintf(buffer, DAT_01069440, owner->TESForm_GetFormTypeString(), owner->GetName(), owner->GetFormID());
        }
        Warning(DAT_010693d8, buffer, ((TESDataHandler*)owner->GetFile(-1))->GetTESImageSpaceList(),
                g_scriptCommands[GetConditionFunction()].name);
    }
    if (GetParamCount() && m_comparisonGlobal)
    {
        unsigned int globalID = (unsigned int)m_comparisonGlobal;
        TESForm::RemapFormIDForFile(globalID, owner->GetFile(-1));
        m_comparisonGlobal = dynamic_cast<TESGlobal*>(TESForm::GetFormByID(globalID));
        if (!m_comparisonGlobal)
        {
            char buffer[0x410];
            if (((const TESForm*)owner)->GetFormType() == 0x46)
            {
                TESTopicInfo* topic = dynamic_cast<TESTopicInfo*>(owner);
                TESTopic* quest = TESTopic::GetTopicFromInfo(topic);
                TESQuest* text = 0;
                if (quest)
                    text = quest->GetParentQuest(topic);
                BSStringT<char> info;
                topic->FormatDebugInfo(info, false);
                FUN_00eca38d(buffer, 0x410, DAT_0104cae0, topic->GetFormID(), ((NiPointer<NiNode>*)&info)->operator->(),
                             text ? text->GetEditorName() : g_011c72c0_arg1, text ? text->GetFormID() : 0,
                             quest ? quest->GetName() : g_011c72c0_arg1, quest ? quest->GetFormID() : 0);
            }
            else
            {
                FUN_00eca38d(buffer, 0x410, DAT_01069440, owner->TESForm_GetFormTypeString(), owner->GetName(),
                             owner->GetFormID());
            }
            Warning(DAT_01069378, globalID, buffer);
        }
    }
}

// @fnv 0x00600ab0
void TESConditionItem::SetObjectType(int aeCheck)
{
    m_objectType = aeCheck;
}

// The approved TESConditionItem header does not yet declare ClearAndSetFunctionCode.
struct FUN_00681460_helper : public TESConditionItem
{
    void ClearAndSetFunctionCode(int functionCode);
};

// @fnv 0x00681460
void FUN_00681460_helper::ClearAndSetFunctionCode(int functionCode)
{
    memset(&m_usFunctionCode, 0, 0x0C);
    m_usFunctionCode = functionCode;
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(int*, EndianSizeTag<3>);
void __cdecl BSEndian(unsigned int*, EndianSizeTag<2>);
// FUNCTION_DATA has no shared header yet; this is its endian-fixup entry point.
struct FUN_00681110_shell
{
    void ClearFields();
};
// @fnv 0x00681170
void TESConditionItem::FixupAfterLoad()
{
    BSEndian(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4), EndianSizeTag<2>());
    BSEndian(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x18), EndianSizeTag<2>());
    BSEndian(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14), EndianSizeTag<2>());
    reinterpret_cast<FUN_00681110_shell*>(reinterpret_cast<char*>(this) + 8)->ClearFields();
}

// The approved TESConditionItem header does not yet declare its 0x006815c0 data accessor.
struct S_006815c0
{
    void* _ref_006815c0();
};
int __cdecl _memcmp(const void*, const void*, int);
// Compares 0x1C bytes of apCompare's referenced data against this object and returns true if they differ.
// @fnv 0x006815d0
bool TESConditionItem::IsDifferentFrom(TESConditionItem* apCompare)
{
    if (_memcmp(((S_006815c0*)apCompare)->_ref_006815c0(), this, 0x1C))
        return true;
    return false;
}

// The approved TESConditionItem header does not yet declare the serialization entry point.
struct SavedCondition
{
    unsigned int flags;
    unsigned int comparison;
    unsigned int function;
    unsigned int params[2];
    int objectType;
    unsigned int reference;
    void SwapEndianAndProcess();
};
struct ConditionSerializer
{
    unsigned int flags;
    TESForm* comparison;
    unsigned int function;
    unsigned int params[2];
    int objectType;
    TESForm* reference;
    int FUN_00413f40();
    bool FUN_006814e0();
    void SerializeCondition();
};
void FUN_00401460(void*, const void*, unsigned int);
int FUN_00682270(int);
bool FUN_006822a0(int, int);
bool TESForm_QEndianSwapOnSave();
void AppendChunk(unsigned int, const void*, unsigned int);
// @fnv 0x00681840
void ConditionSerializer::SerializeCondition()
{
    SavedCondition savedCondition;
    FUN_00401460(&savedCondition, this, 0x1c);
    int functionCode = FUN_00413f40();
    int count = FUN_00682270(functionCode);
    for (int index = 0; index < count; index++)
    {
        if (FUN_006822a0(functionCode, index))
        {
            TESForm* form = reinterpret_cast<TESForm*>(savedCondition.params[index]);
            if (form)
                savedCondition.params[index] = form->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        }
    }
    if (FUN_006814e0() && comparison)
        savedCondition.comparison = comparison->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    if (reference)
        savedCondition.reference = reference->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    if (TESForm_QEndianSwapOnSave())
        savedCondition.SwapEndianAndProcess();
    AppendChunk(0x41445443, &savedCondition, 0x1c);
    if (TESForm_QEndianSwapOnSave())
        savedCondition.SwapEndianAndProcess();
}

namespace fnv_00681220 {
// These setters are absent from the approved TESConditionItem header.
struct FUN_00681500_class
{
    void SetValueIfNoParams(float value);
};

struct FUN_00681530_class
{
    void TESConditionItem_SetComparisonCondition(int count);
};

}  // namespace fnv_00681220

// Normalizes functionCode into the 0x280 range, applies it via ClearAndSetFunctionCode, then sets count and value based on the function code.
// @fnv 0x00681220
void TESConditionItem::SetFunction(int functionCode)
{
    int iNormalizedFunction = functionCode;
    if (functionCode >= 0x1000 && functionCode < 0x1280)
    {
        iNormalizedFunction -= 0x1000;
    }
    else if (functionCode >= 0 && functionCode < 0x280)
    {
        functionCode += 0x1000;
    }
    if (iNormalizedFunction >= 0 && iNormalizedFunction < 0x280)
    {
        ((FUN_00681460_helper*)this)->ClearAndSetFunctionCode(iNormalizedFunction);

        switch (functionCode)
        {
        case 0x103E:
        case 0x1040:
        case 0x1043:
        case 0x1044:
        case 0x1045:
        case 0x1046:
        case 0x1047:
        case 0x1048:
        case 0x105B:
        case 0x1065:
        case 0x1066:
        case 0x1067:
        case 0x106A:
        case 0x106F:
        case 0x1070:
        case 0x1136:
            ((fnv_00681220::FUN_00681530_class*)this)->TESConditionItem_SetComparisonCondition(0);
            ((fnv_00681220::FUN_00681500_class*)this)->SetValueIfNoParams(1.0f);
            break;
        case 0x1001:
            ((fnv_00681220::FUN_00681530_class*)this)->TESConditionItem_SetComparisonCondition(4);
            ((fnv_00681220::FUN_00681500_class*)this)->SetValueIfNoParams(100.0f);
            break;
        case 0x106B:
            ((fnv_00681220::FUN_00681530_class*)this)->TESConditionItem_SetComparisonCondition(1);
            ((fnv_00681220::FUN_00681500_class*)this)->SetValueIfNoParams(0.0f);
            break;
        case 0x10F7:
            m_data0C = 0x28;
            ((fnv_00681220::FUN_00681530_class*)this)->TESConditionItem_SetComparisonCondition(0);
            ((fnv_00681220::FUN_00681500_class*)this)->SetValueIfNoParams(1.0f);
            break;
        }
    }
}
