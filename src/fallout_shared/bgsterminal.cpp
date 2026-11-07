// fallout_shared/bgsterminal.cpp: BGSTerminal, TermHack, PlayerCharacter, TerminalCleanup and more (31 functions)

#include "../../include/BSStringT.h"

#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSNote.h"
#include "../../include/BGSTerminal.h"
#include "../../include/MessageHandler.h"
#include "../../include/PerkEntryConditionSet.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Script.h"
#include "../../include/ScriptHeaderData.h"
#include "../../include/ScriptReferencedObject.h"
#include "../../include/ScriptVariableInfo.h"
#include "../../include/TESBoundAnimObject.h"
// TESConditionSave_bgsterminal: local type (was include/TESConditionSave.h, which had no evidence of one real class); its methods are 0x00680910 TESCondition::Save
class TESConditionSave_bgsterminal
{
public:
    void ProcessItems();
};
#include "../../include/TESDescription.h"
#include "../../include/TESFile.h"
#include "../../include/TESFullName.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESObjectACTI.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TerminalCompareData.h"

#include "../../include/ExtraDataList.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/BaseExtraList.h"
#include "../../include/FormChangeMask.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/Setting.h"

// Unit-specific declarations; TESForm comes from the shared reference header.
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* _alloca(unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class TerminalMenuItem
{
  public:
    BSStringT<char> ResponseText, m_kMenuText;
    Script m_kScript;
    PerkEntryConditionSet Conditions;
    BGSNote* m_pNote;
    BGSTerminal* m_pTerminal;
    char cFlags;
    TerminalMenuItem();
    void TERMINAL_MENU_ITEM_RunResultScript(Script* script);
};
extern ScriptVariableInfo* DAT_011c83d4;
typedef char terminal_size_check[sizeof(BGSTerminal) == 0xa8 ? 1 : -1];
typedef char menu_item_size_check[sizeof(TerminalMenuItem) == 0x78 ? 1 : -1];
int Warning();
int Warning(const char*, ...);
unsigned int SetWarningState(bool);
// PC caller and note-list layout identify the covered 0x00966c10 span as
// PlayerCharacter::HasNote; the supplied BGSTerminal candidate is incorrect.

// Loads a terminal record from the file, dispatching each chunk to set the editor ID, model, script, menu items, sounds, and conditions.
// @fnv 0x00500000
bool BGSTerminal::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);
    TerminalMenuItem* current = 0;
    int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 'LDOM':
        case 'TDOM':
        case 'DDOM':
        case 'DSOM':
            TESModel::LoadModelData(this, file);
            break;
        case 'SDOM': {
            void* textureData;
            unsigned int textureSize = file->GetChunkSize();
            textureData = _alloca(textureSize);
            file->GetChunkData(textureData, textureSize);
            ParseTextureSwapData(textureData, textureSize, file->GetFormVersion());
            break;
        }
        case 'IRCS': {
            Script* script = 0;
            file->GetChunkData((unsigned int*)&script);
            SetScript(script);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 'CSED':
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 'DSLS':
        case 'RVCS': {
            if (file->GetChunkID() == 'DSLS')
            {
                DAT_011c83d4 = new ScriptVariableInfo;
                DAT_011c83d4->Load(file);
                current->m_kScript.GetVariableList()->AddTail(DAT_011c83d4);
            }
            else if (DAT_011c83d4)
            {
                char* variableName = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(variableName, 0x200);
                DAT_011c83d4->name.Set(variableName, 0);
            }
            break;
        }
        case 'RHCS':
            file->GetChunkData(current->m_kScript.GetHeader(), 0);
            if (file->IsEndianConversionRequired())
                current->m_kScript.GetHeader()->Endian();
            break;
        case 'ADCS': {
            unsigned int size = file->GetChunkSize();
            char* data = (char*)_alloca(size);
            memset(data, 0, size);
            file->GetChunkData(data, 0);
            current->m_kScript.SetScriptData(size, data);
            break;
        }
        case 'ORCS': {
            unsigned int formID;
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            reference->pForm = (TESForm*)formID;
            current->m_kScript.GetReferencedObjectList()->AddTail(reference);
            break;
        }
        case 'VRCS': {
            struct
            {
                ScriptReferencedObject* reference;
                unsigned int variableID;
            } loadedVariable;
            loadedVariable.reference = new ScriptReferencedObject;
            file->GetChunkData(&loadedVariable.variableID);
            loadedVariable.reference->m_uiFormID = loadedVariable.variableID;
            current->m_kScript.GetReferencedObjectList()->AddTail(loadedVariable.reference);
            break;
        }
        case 'MANS': {
            TESSound* sound = 0;
            file->GetChunkData((unsigned int*)&sound);
            SetLoopingSound(sound);
            break;
        }
        case 'MANP': {
            BGSNote* password = 0;
            file->GetChunkData((unsigned int*)&password);
            BGSTerminal_SetPassword(password);
            break;
        }
        case 'MAND':
            file->GetChunkData(&Data, 4);
            break;
        case 'TXTI': {
            char* text = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(text, 0);
            TerminalMenuItem* item = new TerminalMenuItem;
            item->ResponseText.Set(text, 0);
            AddMenuItem(item);
            current = item;
            break;
        }
        case 'MANR': {
            if (current)
            {
                char* text = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(text, 0);
                current->m_kMenuText.Set(text, 0);
            }
            break;
        }
        case 'MANI': {
            if (current)
            {
                BGSNote* note = 0;
                file->GetChunkData((unsigned int*)&note);
                current->m_pNote = note;
            }
            break;
        }
        case 'MANT': {
            if (current)
            {
                BGSTerminal* menu = 0;
                file->GetChunkData((unsigned int*)&menu);
                current->m_pTerminal = menu;
            }
            break;
        }
        case 'MANA':
            if (current)
                file->GetChunkData(&current->cFlags, 1);
            break;
        case 'ADTC':
            if (current)
                current->Conditions.Load(file);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the terminal's password and each menu item's note/submenu forms, runs their InitItem scripts and conditions, and warns on lookup or script errors.
// @fnv 0x004ffcb0
void BGSTerminal::InitItem()
{
    int count;
    if (IsFormInitialized())
        return;
    TESObjectACTI::InitItem();
    unsigned int formID = (unsigned int)pPassword;
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        pPassword = dynamic_cast<BGSNote*>(TESForm::GetFormByID(formID));
        if (!pPassword)
            Warning("MASTERFILE: Unable to find password (%08X) on terminal '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }
    count = 0;
    BSSimpleList<TerminalMenuItem*>* pList = FUN_00461150();
    while (pList && !pList->IsEmpty())
    {
        TerminalMenuItem* item = pList->GetItem();
        pList = pList->GetNext();
        if (item->m_pNote)
        {
            formID = (unsigned int)item->m_pNote;
            TESForm::RemapFormIDForFile(formID, GetFile(-1));
            item->m_pNote = dynamic_cast<BGSNote*>(TESForm::GetFormByID(formID));
            if (!item->m_pNote)
                Warning("MASTERFILE: Unable to find display note (%08X) for menu item %i on terminal '%s' (%08X).",
                        formID, count, GetName(), GetFormID());
        }
        if (item->m_pTerminal)
        {
            formID = (unsigned int)item->m_pTerminal;
            TESForm::RemapFormIDForFile(formID, GetFile(-1));
            item->m_pTerminal = dynamic_cast<BGSTerminal*>(TESForm::GetFormByID(formID));
            if (!item->m_pTerminal)
                Warning("MASTERFILE: Unable to find submenu (%08X) for menu item %i on terminal '%s' (%08X).", formID,
                        count, GetName(), GetFormID());
        }
        struct
        {
            int errors;
            int previous;
        } errors;
        errors.previous = Warning();
        SetWarningState(true);
        MessageHandler::SetWarningCount(0);
        item->m_kScript.InitItem(this);
        SetWarningState(false);
        errors.errors = Warning();
        MessageHandler::SetWarningCount(errors.previous);
        if (errors.errors)
            Warning(
                "MASTERFILE: Errors were encountered during InitItem for result script on menu item %d for terminal '%s' (%08X)\n\nSee Warnings file for more information.",
                count, GetName(), GetFormID());
        errors.previous = Warning();
        SetWarningState(true);
        MessageHandler::SetWarningCount(0);
        item->Conditions.InitItem(this);
        SetWarningState(false);
        errors.errors = Warning();
        MessageHandler::SetWarningCount(errors.previous);
        if (errors.errors)
            Warning(
                "MASTERFILE: Errors were encountered during InitItem for conditions on menu item %d for terminal '%s' (%08X)\n\nSee Warnings file for more information.",
                count, GetName(), GetFormID());
        ++count;
    }
    SetInitializationState(true);
}

// @fnv 0x004ffc50
void BGSTerminal::ResetFormData()
{
    TESObjectACTI::ResetFormData();
    pPassword = 0;
    memset(&Data, 0, sizeof(Data));
}

// Returns true if note is non-null and present in the notes list.
// @fnv 0x00966c10
bool PlayerCharacter::HasNote(BGSNote* note)
{
    return note && notes.IsInList(note);
}

// @fnv 0x00501a10
// src: COMMUNITY 0x00501a10
void __cdecl BGSTerminal_ResetState(Script* apScript)
{
    if (apScript)
        reinterpret_cast<BaseExtraList*>(apScript->GetReferencedObjectList())->RemoveExtra(static_cast<unsigned char>(0x50));
}

// @fnv 0x005012c0
// src: XBOX_PDB 0x005012c0
bool __cdecl BGSTerminal_IsTerminalRefInUse(TESObjectREFR* apRef)
{
    bool bretval = false;
    if (apRef)
    {
        TESObjectREFR* plinkedref = apRef->GetLinkedRef();
        if (plinkedref)
        {
            if (plinkedref->TESObjectREFR_IsFurniture())
            {
                if (!plinkedref->IsReferenceActive(true))
                    bretval = true;
            }
        }
    }
    return bretval;
}

// Terminal state accessors are not yet declared by the shared extra-data headers.
// These declarations carry no local ExtraDataList layout.
struct TerminalExtraDataAccess
{
    unsigned char __thiscall ExtraDataList_GetTerminalState();
    void __thiscall ExtraDataList_SetTerminalLockState(int state);
    char __thiscall ExtraDataList_GetTerminalLockState();
    void __thiscall SetExtraState(unsigned char state);
};

// State operations absent from BGSTerminal.h.  This extension has no data
// members or new virtual slots; its entire layout comes from the shared class.
struct TerminalStateAccess : BGSTerminal
{
    bool BGSTerminal_IsUnlocked();
    void BGSTerminal_SetUnlocked(Script* script);
    void TESObjectACTI_SaveGame(void* buffer);
    void BGSTerminal_SaveGame(void* buffer);
    int BGSTerminal_GetHackDifficultyLockLevel(TESObjectREFR* ref);
    unsigned int BGSTerminal_GetHackMiniGameValue(TESObjectREFR* ref);
    int BGSTerminal_GetRawDifficulty(Script* script);
    void BGSTerminal_SetRawDifficulty(Script* script, int value);
    bool BGSTerminal_IsUnlocked_00501ae0(TESObjectREFR* ref);
    void TESObjectACTI_LoadGame(BGSLoadFormBuffer* buffer);
    void BGSTerminal_LoadGame(BGSLoadFormBuffer* buffer);
    bool IsFlagSet();
    void BGSTerminal_ClearMenuItemList();
};

// @fnv 0x005015d0
// src: XBOX_PDB 0x005015d0
bool TerminalStateAccess::BGSTerminal_IsUnlocked()
{
    return Data.cFlags & 2;
}

// @fnv 0x00501b40
// src: COMMUNITY 0x00501b40
void TerminalStateAccess::BGSTerminal_SetUnlocked(Script* pScript)
{
    if (pScript)
    {
        if (BGSTerminal_IsUnlocked())
            ((TerminalExtraDataAccess*)pScript->GetReferencedObjectList())->ExtraDataList_SetTerminalLockState(-1);
        else
            ((TerminalExtraDataAccess*)pScript->GetReferencedObjectList())->ExtraDataList_SetTerminalLockState(-2);
    }
}

// src: XBOX_PDB 0x00511860
void __thiscall TerminalStateAccess::TESObjectACTI_SaveGame(void* apSaveGameBuffer)
{}

// @fnv 0x00501b90
// src: XBOX_PDB 0x00501b90
void __thiscall TerminalStateAccess::BGSTerminal_SaveGame(void* apSaveGameBuffer)
{
    this->TESObjectACTI_SaveGame(apSaveGameBuffer);
}

// @fnv 0x00501270
// src: XBOX_PDB 0x00501270
unsigned int TerminalStateAccess::BGSTerminal_GetHackMiniGameValue(TESObjectREFR* apRef)
{
    int ilockval;
    ilockval = BGSTerminal_GetHackDifficultyLockLevel(apRef);
    ilockval <<= 1;
    ilockval += GetFormID() & 1;
    ilockval += 4;
    if (ilockval > 12)
        ilockval = 12;
    return ilockval;
}

struct TermHack
{
    float __thiscall BGSTerminal_GetMinSkillRequiredToHack(TESObjectREFR* apItemActivated);
    bool __thiscall IsSkillSufficient(TESObjectREFR* apItemActivated, float afSkill);
};
// Returns whether the skill value returned by FUN_005017a0 for the activated reference is less than or equal to afSkill.
// @fnv 0x00501760
bool __thiscall TermHack::IsSkillSufficient(TESObjectREFR* apItemActivated, float afSkill)
{
    return BGSTerminal_GetMinSkillRequiredToHack(apItemActivated) <= afSkill;
}

// Returns true if apRef is non-null and the state byte from its referenced object list has bit 0x80 set.
// @fnv 0x00501870
// src: COMMUNITY 0x00501870
bool __cdecl BGSTerminal_IsHacked(TESObjectREFR* apRef)
{
    bool bretval;
    unsigned char cstate;
    bretval = false;
    if (apRef)
    {
        cstate = ((TerminalExtraDataAccess*)((Script*)apRef)->GetReferencedObjectList())->ExtraDataList_GetTerminalState();
        if (cstate & 0x80)
            bretval = true;
    }
    return bretval;
}

// @fnv 0x00501a30
// src: XBOX_PDB 0x00501a30
int __thiscall TerminalStateAccess::BGSTerminal_GetRawDifficulty(Script* apScript)
{
    char c = -1;
    if (apScript)
    {
        c = ((TerminalExtraDataAccess*)apScript->GetReferencedObjectList())->ExtraDataList_GetTerminalLockState();
    }
    if (c < 0)
    {
        c = Data.m_ucByte0;
    }
    return c;
}

// @fnv 0x00501a80
// src: XBOX_PDB 0x00501a80
void TerminalStateAccess::BGSTerminal_SetRawDifficulty(Script* apScript, int aiValue)
{
    if (apScript)
    {
        if (aiValue == Data.m_ucByte0 && !BGSTerminal_IsUnlocked())
            ((TerminalExtraDataAccess*)(apScript->GetReferencedObjectList()))->ExtraDataList_SetTerminalLockState(-1);
        else
            ((TerminalExtraDataAccess*)(apScript->GetReferencedObjectList()))->ExtraDataList_SetTerminalLockState((unsigned char)aiValue);
    }
}

// @fnv 0x00501ae0
// src: XBOX_PDB 0x00501ae0
bool TerminalStateAccess::BGSTerminal_IsUnlocked_00501ae0(TESObjectREFR* apRef)
{
    bool bunlocked;
    bunlocked = BGSTerminal_IsUnlocked();
    if (apRef)
    {
        char clock;
        clock = ((TerminalExtraDataAccess*)((Script*)apRef)->GetReferencedObjectList())->ExtraDataList_GetTerminalLockState();
        if (clock == -2)
            bunlocked = true;
        else if (clock != -1)
            bunlocked = false;
    }
    return bunlocked;
}

// @fnv 0x00501bb0
// src: XBOX_PDB 0x00501bb0
void TerminalStateAccess::BGSTerminal_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ucTempData;
    TESObjectACTI_LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x80000000).operator bool())
    {
        if (apLoadGameBuffer->GetVersion() < 13)
        {
            apLoadGameBuffer->ReadTypedData(&ucTempData, 1u);
        }
    }
}

// @fnv 0x00501250
bool __thiscall TerminalStateAccess::IsFlagSet()
{
    return (Data.cFlags & 1) ? true : false;
}

extern Setting g_011d961c;
extern Setting g_011d9660;
extern Setting g_011d9684;
extern Setting g_011d95d4;
extern Setting g_011d9640;

// @fnv 0x005017a0
// src: XBOX_PDB 0x005017a0
float TermHack::BGSTerminal_GetMinSkillRequiredToHack(TESObjectREFR* apItemActivated)
{
    switch (((TerminalStateAccess*)this)->BGSTerminal_GetHackDifficultyLockLevel(apItemActivated))
    {
    case 0:
        return *g_011d961c.Float();
    case 1:
        return *g_011d9660.Float();
    case 2:
        return *g_011d9684.Float();
    case 3:
        return *g_011d95d4.Float();
    case 4:
        return *g_011d9640.Float();
    default:
        return 3.402823466e+38F;
    }
}

extern "C" void ApplyPerkModifiers(int, void*, ...);
extern double _gModifierZero;
extern void* g_thePlayer;

// Checks the script's referenced object state: returns false for state 0, compares a perk modifier against _gModifierZero for state 1, and true otherwise.
// @fnv 0x00501990
// src: XBOX_PDB 0x00501990
bool __cdecl BGSTerminal_IsLockedOut(Script* apScript)
{
    if (apScript)
    {
        unsigned char cstate = reinterpret_cast<TerminalExtraDataAccess*>(apScript->GetReferencedObjectList())->ExtraDataList_GetTerminalState();
        switch (cstate & 0x7f)
        {
        case 0:
            return false;
        case 1: {
            float fPerkModifier = 0.0f;
            ApplyPerkModifiers(0x14, g_thePlayer, &fPerkModifier);
            return fPerkModifier == _gModifierZero;
        }
        default:
            return true;
        }
    }
    return false;
}

// @fnv 0x00501930
void __cdecl SetScriptLockState(Script* apRef, bool abLock)
{
    unsigned char cstate;
    if (apRef)
    {
        cstate = ((TerminalExtraDataAccess*)apRef->GetReferencedObjectList())->ExtraDataList_GetTerminalState();
        if (abLock)
            cstate++;
        else
            cstate = 0;
        ((TerminalExtraDataAccess*)apRef->GetReferencedObjectList())->SetExtraState(cstate);
        apRef->MarkAsModified(0x80000000);
    }
}

// @fnv 0x00501830
// src: XBOX_PDB 0x00501830
void TerminalMenuItem::TERMINAL_MENU_ITEM_RunResultScript(Script* apScript)
{
    m_kScript.GetHeader()->m_bQuest = false;

    m_kScript.FUN_005ac1e0(reinterpret_cast<TESObjectREFR*>(apScript),
                       reinterpret_cast<ExtraDataList*>(apScript->GetReferencedObjectList())->GetScriptLocalData(), 0,
                       true);
}

// @fnv 0x005018b0
// src: XBOX_PDB 0x005018b0
void BGSTerminal_SetHacked(Script* apRef, bool abVal)
{
    unsigned char cstate;
    unsigned char ucNewState;
    if (apRef != 0)
    {
        cstate = ((TerminalExtraDataAccess*)apRef->GetReferencedObjectList())->ExtraDataList_GetTerminalState();
        if (abVal)
        {
            cstate = cstate | 0x80;
            ucNewState = cstate;
        }
        else
        {
            cstate = cstate & 0xffffff7f;
            ucNewState = cstate;
        }
        ((TerminalExtraDataAccess*)apRef->GetReferencedObjectList())->SetExtraState(cstate);
        apRef->MarkAsModified(0x80000000);
    }
}

int __cdecl BSstricmp(const char* pcString1, const char* pcString2);
int __cdecl BSstrcmp(const char* pcString1, const char* pcString2);

// Compares this string's C string with pcOther, case-insensitively when bIgnoreCase is set, returning 0 when both are null.
// @fnv 0x00408a80
template <> int BSStringT<char>::StrCmp(const char* pcOther, bool bIgnoreCase) const
{
    int iResult;
    if (pcOther && String())
        iResult = bIgnoreCase ? BSstricmp(String(), pcOther) : BSstrcmp(String(), pcOther);
    else if (!pcOther && !String())
        iResult = 0;
    else
        iResult = pcOther ? -1 : 1;
    return iResult;
}

struct TerminalCleanup
{
    void FUN_00483710();
};

// @fnv 0x004ffc90
void BGSTerminal::ClearData()
{
    TESForm::ClearData();
    reinterpret_cast<TerminalStateAccess*>(this)->BGSTerminal_ClearMenuItemList();
}

extern "C" void* memcpy(void*, const void*, unsigned int);

struct TerminalPasswordAccess
{
    BGSNote* GetPassword();
};
struct ConditionCopy
{
    void CopyFrom(PerkEntryConditionSet* apConditions, bool abFlag);
};

// @fnv 0x00500cb0
void BGSTerminal::CopyFrom(const TESForm* apForm)
{
    BGSTerminal* pTerminal = dynamic_cast<BGSTerminal*>(const_cast<TESForm*>(apForm));
    if (!pTerminal)
        return;
    BSSimpleList<TerminalMenuItem*>* pIter = 0;
    BGSTerminal_SetPassword(((TerminalPasswordAccess*)pTerminal)->GetPassword());
    memcpy(&Data, &pTerminal->Data, sizeof(Data));
    reinterpret_cast<TerminalStateAccess*>(this)->BGSTerminal_ClearMenuItemList();
    pIter = pTerminal->FUN_00461150();
    while (pIter && !pIter->IsEmpty())
    {
        TerminalMenuItem* pSrc = pIter->GetItem();
        pIter = pIter->GetNext();
        TerminalMenuItem* pItem = new TerminalMenuItem;
        pItem->ResponseText = pSrc->ResponseText;
        pItem->m_kMenuText = pSrc->m_kMenuText;
        pItem->m_pNote = pSrc->m_pNote;
        pItem->m_pTerminal = pSrc->m_pTerminal;
        pItem->cFlags = pSrc->cFlags;
        pItem->m_kScript.CopyScriptContents(&pSrc->m_kScript);
        ((ConditionCopy*)&pItem->Conditions)->CopyFrom(&pSrc->Conditions, false);
        AddMenuItem(pItem);
    }
    TESObjectACTI::CopyFrom(pTerminal);
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct TerminalStringCmp
{
    bool IsDifferent(const BSStringT<char>* apOther);
};
struct TerminalScriptCmp
{
    bool IsDifferent(Script* apOther);
};
struct TerminalMenuList
{
    int GetSize();
};

// @fnv 0x00500e60
bool BGSTerminal::Compare(TESForm* apForm)
{
    BGSTerminal* pTerminal = dynamic_cast<BGSTerminal*>(apForm);
    if (!pTerminal)
        return true;
    if (reinterpret_cast<TerminalPasswordAccess*>(this)->GetPassword() !=
        reinterpret_cast<TerminalPasswordAccess*>(pTerminal)->GetPassword())
        return true;
    if (memcmp(&Data, &pTerminal->Data, sizeof(TerminalCompareData)))
        return true;

    BSSimpleList<TerminalMenuItem*>* pThisIter5 = FUN_00461150();
    BSSimpleList<TerminalMenuItem*>* pOtherIter = pTerminal->FUN_00461150();
    if (((TerminalMenuList*)pThisIter5)->GetSize() != ((TerminalMenuList*)pOtherIter)->GetSize())
        return true;

    while (pOtherIter && !pOtherIter->IsEmpty() && pThisIter5 && !pThisIter5->IsEmpty())
    {
        TerminalMenuItem* pOtherItem = pOtherIter->GetItem();
        TerminalMenuItem* pThisItem5 = pThisIter5->GetItem();
        if (((TerminalStringCmp*)&pThisItem5->ResponseText)->IsDifferent(&pOtherItem->ResponseText))
            return true;
        if (((TerminalStringCmp*)&pThisItem5->m_kMenuText)->IsDifferent(&pOtherItem->m_kMenuText))
            return true;
        if (((TerminalScriptCmp*)&pThisItem5->m_kScript)->IsDifferent(&pOtherItem->m_kScript))
            return true;
        if (pThisItem5->Conditions.Compare(&pOtherItem->Conditions))
            return true;
        if (pThisItem5->m_pNote != pOtherItem->m_pNote)
            return true;
        if (pThisItem5->m_pTerminal != pOtherItem->m_pTerminal)
            return true;
        if (pThisItem5->cFlags != pOtherItem->cFlags)
            return true;
        pOtherIter = pOtherIter->GetNext();
        pThisIter5 = pThisIter5->GetNext();
    }

    if (TESObjectACTI::Compare(pTerminal))
        return true;
    return false;
}

struct TerminalMenuItemDisposal
{
    int FUN_005010c0(int aFlag);
};

// @fnv 0x00501050
// src: COMMUNITY 0x00501050
void TerminalStateAccess::BGSTerminal_ClearMenuItemList()
{
    while (m_kMenuItems.IsEmpty() == 0)
    {
        TerminalMenuItemDisposal* a = reinterpret_cast<TerminalMenuItemDisposal*>(m_kMenuItems.GetItem());
        m_kMenuItems.RemoveHead();
        TerminalMenuItemDisposal* tmp = a;
        TerminalMenuItemDisposal* b2 = tmp;
        (b2 != 0 ? b2->FUN_005010c0(1) : 0);
    }
}

struct SaveModel : TESModelTextureSwap
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct DestructibleSaveAccess : BGSDestructibleObjectForm
{
    void FUN_00477f20();
};
struct SaveScript
{
    void FUN_005abe00();
};
bool __cdecl TESForm_QEndianSwapOnSave();
unsigned int __cdecl BSStringLength(const char*);
void __cdecl TESForm_AddChunkArray(unsigned int, const void*, unsigned int);
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
void __cdecl AppendChunk(unsigned int, void*, unsigned int);

// @fnv 0x00500a40
void BGSTerminal::SaveForm()
{
    BeginFormRecord();
    TESFullName::Save_00487010();
    reinterpret_cast<SaveModel*>(reinterpret_cast<char*>(this) +
        offsetof(BGSTerminal, m_kModelFilePath) - offsetof(TESModelTextureSwap, m_kModelFilePath))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESScriptableForm::Save_0048cca0();
    reinterpret_cast<DestructibleSaveAccess*>(reinterpret_cast<char*>(this) +
        offsetof(BGSTerminal, pData) - offsetof(BGSDestructibleObjectForm, pData))->FUN_00477f20();
    TESDescription::Save_00482cb0();
    if (m_pSoundEffect)
    {
        unsigned int soundID = reinterpret_cast<TESForm*>(m_pSoundEffect)->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e53, soundID);
    }
    if (reinterpret_cast<TerminalPasswordAccess*>(this)->GetPassword())
    {
        unsigned int passwordID = reinterpret_cast<TerminalPasswordAccess*>(this)->GetPassword()->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e50, passwordID);
    }
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<TerminalCleanup*>(&Data)->FUN_00483710();
    AppendChunk(0x4d414e44, &Data, 4);
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<TerminalCleanup*>(&Data)->FUN_00483710();
    BSSimpleList<TerminalMenuItem*>* pMenuNode = FUN_00461150();
    while (pMenuNode && !pMenuNode->IsEmpty())
    {
        TerminalMenuItem* item = pMenuNode->GetItem();
        pMenuNode = pMenuNode->GetNext();
        if (static_cast<const char*>(item->ResponseText))
            TESForm_AddChunkArray(
                0x54585449, static_cast<const char*>(item->ResponseText),
                BSStringLength(static_cast<const char*>(item->ResponseText)) + 1);
        else
            TESForm_AddChunk_00485910(0x54585449, 0);
        if (static_cast<const char*>(item->m_kMenuText))
            TESForm_AddChunkArray(
                0x4d414e52, static_cast<const char*>(item->m_kMenuText),
                BSStringLength(static_cast<const char*>(item->m_kMenuText)) + 1);
        else
            TESForm_AddChunk_00485910(0x4d414e52, 0);
        TESForm_AddChunk_3(0x4d414e41, item->cFlags);
        if (item->m_pNote)
        {
            unsigned int noteID = item->m_pNote->GetFormID();
            TESForm_AddChunk_00485910(0x4d414e49, noteID);
        }
        if (item->m_pTerminal)
        {
            unsigned int submenuID = item->m_pTerminal->GetFormID();
            TESForm_AddChunk_00485910(0x4d414e54, submenuID);
        }
        reinterpret_cast<SaveScript*>(&item->m_kScript)->FUN_005abe00();
        reinterpret_cast<TESConditionSave_bgsterminal*>(&item->Conditions)->ProcessItems();
    }
    FinishFormRecord();
}

struct Ref;
struct Form
{
    int Type();
};
struct Ref
{
    Form* GetOwner();
    bool CanBeUsed(Ref*, bool);
};
struct Player
{
    int Check(Ref*);
    void Penalize(int);
};
extern Player* _g_thePlayer;
bool Interface_IsPipboyOpening();
struct Open
{
    static int GetOpenState(Ref*);
};
bool BGSTerminal_IsTerminalRefInUse(Ref*);
struct Sound
{
    int id;
    int state;
    int flags;
    ~Sound();
    bool Play(bool);
};
struct Audio
{
    Sound GetSoundHandleByEditorID(const char*, unsigned int);
    static Audio* GetSingleton();
};
extern Setting g_011c8394, g_011d4810, originalRuntimeFloatSetting282;
const char* GetActorValueName(int);
float Clamp(float, float);
bool QueueUIMessage(const char*, int, const char*, const char*, float, bool);
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float Get(int);
};
struct OwnerActor
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    Values values;
};
struct Faction
{
    bool Test();
};
unsigned int TESActorBaseData_GetAlignmentForKarma(float);
void BGSOpenCloseForm_HandleActivate(Ref*, Ref*, int);
// Activation entry points missing from the shared terminal header.
struct TerminalActivationAccess : BGSTerminal
{
    float BGSTerminal_GetMinSkillRequiredToHack(Ref* target);
    bool BGSTerminal_IsUnlocked();
    bool ActivateTerminal(Ref* target, Ref* user, int arg3, int arg4, int arg5);
};
// @fnv 0x00501310
bool TerminalActivationAccess::ActivateTerminal(Ref* target, Ref* user, int arg3, int arg4, int arg5)
{
    if (Interface_IsPipboyOpening())
    {
        return false;
    }
    else if (Open::GetOpenState(target) == 1)
    {
        HandleOpenAnimationFinish(reinterpret_cast<TESObjectREFR*>(target), reinterpret_cast<TESObjectREFR*>(user));
    }
    else if (user == (Ref*)_g_thePlayer && _g_thePlayer->Check(target) == 4)
    {
        BSStringT<char> message;
        message.PrintfString( g_011c8394.GetString(), GetActorValueName(40), (int)Clamp(BGSTerminal_GetMinSkillRequiredToHack(target), 1.0f));
        QueueUIMessage(message, 0, "Interface\\Icons\\Message Icons\\glow_message_vaultboy_angry.dds", 0, 2.0f, false);
        Audio::GetSingleton()->GetSoundHandleByEditorID("UIPopUpMessageGeneral", 0x121).Play(false);
    }
    else if (user == (Ref*)_g_thePlayer && BGSTerminal_IsTerminalRefInUse(target))
    {
        QueueUIMessage(g_011d4810.String(), 0, 0, 0, 2.0f, false);
        return false;
    }
    else
    {
        Ref* actor = user;
        if (target->GetOwner() && !target->CanBeUsed(actor, true) && !BGSTerminal_IsUnlocked())
        {
            bool crime = false;
            Form* owner = target->GetOwner();
            int unused = 0;
            if (owner->Type() == 8)
            {
                Faction* faction = (Faction*)owner;
                if (!faction->Test())
                    crime = true;
            }
            else
            {
                OwnerActor* pOwnerActor = (OwnerActor*)owner;
                if (pOwnerActor)
                {
                    unsigned int rank = TESActorBaseData_GetAlignmentForKarma(pOwnerActor->values.Get(23));
                    if (rank != 2 && rank != 4)
                        crime = true;
                }
            }
            if (crime)
                _g_thePlayer->Penalize((int)*originalRuntimeFloatSetting282.Float());
        }
        BGSOpenCloseForm_HandleActivate(target, user, 0);
    }
    return true;
}

// @fnv 0x004ffaa0
BGSTerminal::BGSTerminal()
{
    SetFormType((ENUM_FORM_ID)0x17);
    ResetFormData();
}

extern float DAT_011c83c4;
extern void* DAT_011dea3c;
float* __fastcall Setting_Float_00403e20(float*);
unsigned short __fastcall GetLevel_0087f9f0(void*);

// Returns the initial result, optionally adding a scaled level value and capping it at 4 when the flag is set.
// @fnv 0x005011a0
// src: XBOX_PDB 0x005011a0
int __thiscall TerminalStateAccess::BGSTerminal_GetHackDifficultyLockLevel(TESObjectREFR* apRef)
{
    unsigned int result = BGSTerminal_GetRawDifficulty(reinterpret_cast<Script*>(apRef));
    if (IsFlagSet())
    {
        unsigned int level =
            apRef ? apRef->GetReferenceLevel(false) : GetLevel_0087f9f0(DAT_011dea3c);
        result += (unsigned int)((double)level * *Setting_Float_00403e20(&DAT_011c83c4));
        if (result > 4)
            result = 4;
    }
    return result;
}
