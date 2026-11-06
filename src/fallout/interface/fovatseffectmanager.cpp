// fallout/interface/fovatseffectmanager.cpp: FOHUDEffectManager, EffectSetting (4 functions)

#include "../../../include/NiPoint2.h"
#include "../../../include/NiColorA.h"
#include "../../../include/FOHUDEffectManager.h"

extern unsigned __int64 selected_target_masks[43];

#include "fovatseffectmanager_targets.h"

// Stores targetMask at selected_target_masks[selectedIndex] and sets or clears the selectedIndex bit in each of the 43 mask words according to targetMask.
// @fnv 0x00c82870
void SetTargetMaskForSelection(unsigned int selectedIndex, unsigned __int64 ullTargetMask)
{
    unsigned __int64 ullSelectedBit = ((unsigned __int64)1) << selectedIndex;
    selected_target_masks[selectedIndex] = ullTargetMask;

    unsigned __int64 ullTestBit = 1;
    unsigned int byteOffset = 0;
    do
    {
        unsigned __int64* pullMaskWord = (unsigned __int64*)((unsigned char*)selected_target_masks + byteOffset);
        if (ullTargetMask & ullTestBit)
            *pullMaskWord |= ullSelectedBit;
        else
            *pullMaskWord &= ~ullSelectedBit;
        ullTestBit <<= 1;
        byteOffset += 8;
    } while (byteOffset < 0x158);
}

#pragma optimize("", off)
#include "fovatseffectmanager_perks.h"

// Applies the perk entry-point functions for an actor's entry point, validating filter parameters and function arguments first.
// @fnv 0x005e58f0
void ApplyPerkModifiers(int entryPoint, Actor* actor, ...)
{
    if (!actor || entryPoint >= 74)
        return;
    bool bUsePlayer = false;
    Actor* pOriginalActor = actor;
    if (actor != (Actor*)g_thePlayer && actor->IsPlayerTeammate())
    {
        bUsePlayer = true;
        actor = (Actor*)g_thePlayer;
    }
    BSSimpleList<BGSPerkEntry*>* pList = actor->GetPerkEntriesForEntryPoint((unsigned char)entryPoint, bUsePlayer);
    if (pList && pList->GetItem())
    {
        actor = pOriginalActor;
        void* pEntryPointArguments[10];
        void* pParameters[10];
        struct PerkArgumentValidation
        {
            bool validArguments;
            unsigned char argumentCount;
            unsigned char parameterCount;
            bool validParameters;
        } argumentValidation;
        struct PerkArgumentCursor
        {
            BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE type;
            char* current;
        } kArgumentPosition;
        argumentValidation.parameterCount = EntryPointFunctionDispatcher::ms_kEntryPointTable[entryPoint].filterCount;
        kArgumentPosition.type = (BGSEntryPointFunction::ENTRY_POINT_FUNCTION_TYPE)
                                     EntryPointFunctionDispatcher::ms_kEntryPointTable[entryPoint]
                                         .functionType;
        argumentValidation.argumentCount = BGSEntryPointFunction::GetArgumentCount(kArgumentPosition.type);
        pParameters[0] = actor;
        kArgumentPosition.current = (char*)(&actor + 1);
        argumentValidation.validParameters = true;
        for (unsigned int i = 1; i < argumentValidation.parameterCount; ++i)
        {
            pParameters[i] = *(void**)((kArgumentPosition.current += 4) - 4);
            if (!pParameters[i])
                argumentValidation.validParameters = false;
        }
        argumentValidation.validArguments = true;
        for (unsigned int i = 0; i < argumentValidation.argumentCount; ++i)
        {
            pEntryPointArguments[i] = *(void**)((kArgumentPosition.current += 4) - 4);
            if (!pEntryPointArguments[i])
                argumentValidation.validArguments = false;
        }
        kArgumentPosition.current = 0;
        if (argumentValidation.validParameters && argumentValidation.validArguments)
        {
            while (pList)
            {
                BGSPerkEntry* pPerkEntry = pList->GetItem();
                if (pPerkEntry && pPerkEntry->CheckConditionFilters(argumentValidation.parameterCount, reinterpret_cast<TESForm**>(pParameters)))
                    BGSEntryPointFunction::ApplyFunction(
                        (BGSEntryPointFunction::ENTRY_POINT_FUNCTION)pPerkEntry->GetFunction(), actor,
                        kArgumentPosition.type, argumentValidation.argumentCount, pEntryPointArguments,
                        pPerkEntry->GetFunctionData());
                pList = pList->GetNext();
            }
        }
        else
        {
            Warning(g_entryPointArgumentErrorFormat,
                    argumentValidation.validParameters ? g_entryPointFunctionArgumentName
                                                       : g_entryPointFilterParameterName,
                    EntryPointFunctionDispatcher::ms_kEntryPointTable[entryPoint].name,
                    argumentValidation.validParameters ? argumentValidation.parameterCount
                                                       : argumentValidation.argumentCount);
        }
    }
}

#include "fovatseffectmanager_effects.h"

// Initializes the EffectSetting data fields to defaults, reads two game-setting floats, and sets the form type to 0x10.
// @fnv 0x00407020
EffectSetting::EffectSetting()
{
    data.iFlags = 0;
    data.m_fBaseCost = 0.0f;
    data.m_pAssociatedForm = 0;
    data.m_iAssociatedActorValue = -1;
    data.m_iAssociatedSkill = -1;
    data.m_iResistanceActorValue = -1;
    data.m_sCounterEffectCount = 0;
    data.apTargetLight = 0;
    data.m_pEffectShader = 0;
    data.m_pEnchantEffectShader = 0;
    data.fSpeed = 1.0f;
    data.m_pCastSound = 0;
    data.m_pBoltSound = 0;
    data.m_pContactSound = 0;
    data.m_pAreaEffectSound = 0;
    data.m_fEnchantmentFactor = ((SettingT_GameSettingCollection_&)g_011c36c0).Float()->f;
    data.m_fBarterFactor = ((SettingT_GameSettingCollection_&)g_011c37e8).Float()->f;
    data.m_eEffectTypeItem = (EffectArchetypes__ArchetypeID)0;
    m_iActorValue = 0;
    m_iEffectID = 0;
    m_pEffectSettingCallback = 0;
    m_pPredicateData = 0;
    SetFormType((ENUM_FORM_ID)0x10);
}

// @fnv 0x007f7610
FOHUDEffectManager::FOHUDEffectManager() : spEffect(0)
{
    pShaderParam = new ImageSpaceShaderParam;
    pShaderParam->AllocateShaderConstants(0, 0);
    pShaderParam->m_bTextureFlags[1] = false;
    pShaderParam->m_bTextureFlags[2] = false;
    pShaderParam->m_eShaderFilterMode = (NiTexturingProperty::FilterMode)1;
    spEffect = 0;
    bShudderActive = false;
    kShudderOffset = DAT_011f4980;
    bFlag54 = false;
    fScanlineFrequency = ((SettingT_GameSettingCollection_&)g_011db25c).Float()->f;
    fBlurIntensity = ((SettingT_GameSettingCollection_&)g_011db238).Float()->f;
    fBlurRadius = ((SettingT_GameSettingCollection_&)g_011db200).Float()->f;
}
