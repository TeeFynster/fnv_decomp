// fallout_shared/tesscript.cpp: Script and ScriptLocals runtime (82 functions)

#ifndef FNV_TESSCRIPT_DECLS_H
#define FNV_TESSCRIPT_DECLS_H

#include <stdarg.h>
#include <new>
#include <malloc.h>
#include "tesscript_layout.h"
#include "../../include/TESFile.h"
// The unit layout already supplies the list API used by the shared forms.
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/ExtraDataList.h"
#include "../../include/InventoryStackRecord.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESQuest.h"
#include "../../include/EffectSetting.h"
#include "../../include/MagicItem.h"
#include "../../include/Script.h"
#include "../../include/ScriptFunctionInfo.h"
#include "../../include/ScriptLocals.h"
#include "../../include/ScriptLocalVariable.h"
#include "../../include/ScriptReferencedObject.h"
#include "../../include/SpellItem.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESContainer.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/NiFile.h"
#include "../../include/TESObjectBOOK.h"
#include "../../include/BSFadeNode.h"

// These unit-only operations have no shared declarations and add no layout.

struct CompileDataStub;
struct ScriptUnitOperations : Script
{
    void SaveHeader();
    void Save();
    char FindVariableType(const char*, unsigned int*);
    bool IsDifferentFromCompileData(CompileDataStub*);
    bool IsDifferentFrom(Script*);
    void ExecuteEffectOnTarget(TESObjectREFR*, ScriptLocals*);
};
class FormFlagRecord;
class ScriptVariableInfo;
class ScriptParameter;
class ScriptDefinition;
#include <string.h>

// The legacy variable-info header uses the shared local-variable definition.
#define FNV_SCRIPT_LOCAL_H
#include "ScriptVariableInfo.h"
#include "tesscript_types_SCRIPT_PARAMETER.h"
class EnchantmentItem;
struct ScriptParameterKind
{
    const char* name;
    unsigned char valueKind;
    bool isReference;
    unsigned short reserved;
};
extern ScriptParameterKind DAT_0118cdd0[];
int Warning(const char*, ...);
bool ExtractArgs(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                 ScriptLocals*, ...);

class TESGlobalValueReader
{
  public:
    float GetValue();
};
ScriptFunctionInfo* GetFunctionByOpcode(SCRIPT_OUTPUT output);

#include "../../include/MEM_CONTEXT.h"
#include "../../include/SettingT_GameSettingCollection_.h"
extern SettingT_GameSettingCollection_ DAT_011cac68;
extern float DAT_011cad20[8];
extern int DAT_011cad40;
char* AllocateZeroed(unsigned int count, unsigned int size);
class FormRecordMetadata
{
  public:
    unsigned int iFormID;
};
#include "../../include/TESSaveLoadGame.h"
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern BSSimpleList<TESObjectREFR*> DAT_011caca8;
extern BSSimpleList<TESObjectREFR*> DAT_011cac98;
extern BSSimpleList<TESObjectREFR*> DAT_011cace8;
extern BSSimpleList<TESObjectREFR*> DAT_011cacb8;
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
#include "../../include/ScriptExecutor.h"
extern int DAT_011cae50;
class FormFlagRecord
{
  public:
    TESForm* pForm;
    unsigned int iFlags;
};
extern bool DAT_0118c685;
#endif

typedef TESBoundObject* (__thiscall* ScriptActionEntry)(ScriptLocals*);

class NiPoint3;
class TESObjectCELL;
#include "../../include/MobileObject.h"
#include "../../include/AutoMemHelper.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/GO.h"
#include "../../include/MemoryManager.h"
#include "../../include/SL.h"
#include "../../include/AutoMemContext.h"
// @fnv 0x005aa0f0
Script::Script()
{
    InitializeComponent();
}

// @fnv 0x005ac740
bool Script::IsConsolePlatform()
{
    return DAT_0118c685;
}

// @fnv 0x006ebc50
void __fastcall ProcessPendingTasks(ScriptLocals* locals)
{
    locals->m_pOwnerScript->FUN_006eae40();
}

// @fnv 0x005ab7d0
void Script::InitItem()
{
    InitItem(this);
}

// @fnv 0x005acc70
void Script::CopyIdentifierBitsToValue(const unsigned int& id, double& value)
{
    memcpy(&value, &id, sizeof(unsigned int));
}

// @fnv 0x00541cb0
TESBoundObject* ScriptLocals::GetActionEntry()
{
    return (*(ScriptActionEntry**)this)[0x94 / 4](this);
}

// @fnv 0x005533c0
void Script::GetLocalData()
{
    TESBoundObject* object = reinterpret_cast<ScriptLocals*>(this)->GetLocalData();
    if (object)
        object->TESForm::ClearData();
}

// Returns the bound object from this ScriptLocals instance, or null when the instance pointer is null.
// @fnv 0x00541c80
TESBoundObject* ScriptLocals::GetLocalData()
{
    return this ? GetActionEntry() : 0;
}

// Runs this script on the given reference with the given locals and time via the singleton instance.
// @fnv 0x005ac3c0
void Script::AdvanceScript(TESObjectREFR* ref, ScriptLocals* locals, float time)
{
    ScriptExecutor::Instance()->Run(this, ref, locals, 0, false, false, false, time);
}

// @fnv 0x005aa2a0
void Script::ClearData()
{
    ::operator delete(m_data);
    ::operator delete(m_pText);
    FUN_005aa2e0();
    InitializeActionList();
}

// Deletes this ScriptLocals object.
// @fnv 0x0041af70
void ScriptLocals::Destroy()
{
    delete this;
}

// Zeroes the 0x14-byte object at pThis, clears the int at offset 0 and offset 0x10, and returns pThis.
// @fnv 0x005a8b80
ScriptLocals::ScriptLocals()
{
    memset(this, 0, 0x14);
    *reinterpret_cast<int*>(this) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = 0;
}

void __cdecl Deallocate(void* p);
void __fastcall FUN_005a8c00(void* pThis);
void __fastcall FUN_005a8c90(void* pThis);

// Calls two cleanup helpers, then deallocates the pointer stored at offset 0x10 if it is non-null.
// @fnv 0x005a8bc0
ScriptLocals::~ScriptLocals()
{
    FUN_005a8c00(this);
    FUN_005a8c90(this);
    if (*(void**)((char*)this + 0x10) != 0)
    {
        void* p = *(void**)((char*)this + 0x10);
        Deallocate(p);
    }
}

// Deletes every item in the list at offset 0xc, then deletes the list itself and nulls the pointer.
// @fnv 0x005a8c90
void __fastcall FUN_005a8c90(void* object)
{
    if (*(BSSimpleList<ScriptLocalVariable*>**)((char*)object + 0xc))
    {
        while ((*(BSSimpleList<ScriptLocalVariable*>**)((char*)object + 0xc))->GetItem())
        {
            ScriptLocalVariable* local = (*(BSSimpleList<ScriptLocalVariable*>**)((char*)object + 0xc))->GetItem();
            (*(BSSimpleList<ScriptLocalVariable*>**)((char*)object + 0xc))->RemoveHead();
            delete local;
        }
        delete *(BSSimpleList<ScriptLocalVariable*>**)((char*)object + 0xc);
        *(BSSimpleList<ScriptLocalVariable*>**)((char*)object + 0xc) = 0;
    }
}

// @fnv 0x005a8e20
bool ScriptLocals::FUN_005a8e20(TESForm* form, unsigned int flag)
{
    bool result = false;
    if (!m_pLocalVariableList)
        return false;
    FormFlagRecord* obj = GetActionEntry(form, true);
    if (obj)
    {
        obj->iFlags |= flag;
        result = true;
    }
    obj = GetActionEntry(0, true);
    if (obj)
    {
        obj->iFlags |= flag;
        result = true;
    }
    return result;
}

int* __fastcall _ref_006815c0(void* pThis);
void* __fastcall _ref_00726070(void* pThis);

// Walks the list at this+8 and sets the second int of each entry returned by _ref_006815c0 to 0 until the list or entry is null.
// @fnv 0x005a8ea0
void ScriptLocals::ClearActionFlags()
{
    void* pList = *(void**)((char*)this + 8);
    while (pList && *_ref_006815c0(pList))
    {
        int* used = (int*)*_ref_006815c0(pList);
        pList = _ref_00726070(pList);
        used[1] = 0;
    }
}

extern const char DAT_01015890[];
extern int DAT_011cae50;

bool __fastcall _ref_008256d0(unsigned int);
ScriptLocalVariable** __fastcall _ref_006815c0(unsigned int);
unsigned int __fastcall _ref_00726070(unsigned int);

struct TLS_Data_005a9140
{
    char pad[0x270];
    ScriptLocalVariable* pLastLocal;
    unsigned int uiLastID;
    void* pLastLocals;
};

__declspec(thread) TLS_Data_005a9140 tls_005a9140;

// Looks up a script local variable by ID (using a TLS cache), returns its double value, or warns and returns 0.0 if not found.
// @fnv 0x005a9140
double ScriptLocals::GetVariable(unsigned int auiID, Script* apScript)
{
    ScriptLocalVariable* plocalvar = 0;
    if (tls_005a9140.pLastLocals == this && tls_005a9140.uiLastID == auiID)
    {
        plocalvar = tls_005a9140.pLastLocal;
    }
    if (plocalvar == 0)
    {
        unsigned int pCurrentElementNext = ((TESForm*)this)->GetFormID();
        while (pCurrentElementNext != 0 && !_ref_008256d0(pCurrentElementNext))
        {
            ScriptLocalVariable* pCandidate = *_ref_006815c0(pCurrentElementNext);
            if (pCandidate->uiID == auiID)
            {
                plocalvar = pCandidate;
                break;
            }
            pCurrentElementNext = _ref_00726070(pCurrentElementNext);
        }
    }
    tls_005a9140.pLastLocals = this;
    tls_005a9140.uiLastID = auiID;
    tls_005a9140.pLastLocal = plocalvar;
    if (plocalvar != 0)
    {
        return plocalvar->fValue;
    }
    Warning(
        "SCRIPTS: Variable ID %08X not found. Try to recompile script '%s'. The script may also have a bad reference variable in an if statement on line %d.",
        auiID, apScript ? ((TESForm*)apScript)->GetName() : DAT_01015890, DAT_011cae50);
    return 0.0;
}

// @fnv 0x005aa1a0
Script::~Script()
{
    ClearData();
}

void* __cdecl memset(void*, int, unsigned int);

__declspec(thread) extern char tls_pad[0x268];
__declspec(thread) extern bool tls_bIsInitialized;

// Clears the script's data fields and TLS state, then sets the form type to 0x11.
// @fnv 0x005aa220
void Script::InitializeComponent()
{
    memset(&m_kHeader, 0, sizeof(m_kHeader));
    m_data = 0;
    m_pText = 0;
    tls_bIsInitialized = false;
    m_pOwnerQuest = 0;
    m_fValueAtOffset34 = 0.0f;
    fValueAtOffset38 = 0.0f;
    m_fValueAtOffset3C = 0.0f;
    SetFormType((ENUM_FORM_ID)0x11);
}

// Deletes every item in the variable list and removes each head until the list is empty.
// @fnv 0x005aa2e0
void Script::FUN_005aa2e0()
{
    BSSimpleList<ScriptVariableInfo*>* pList = GetVariableList();
    while (pList && !pList->IsEmpty())
    {
        delete pList->GetItem();
        pList->RemoveHead();
    }
}

void* __cdecl memcpy(void*, const void*, unsigned int);

// Copies the header, data, referenced objects, variables and text from another Script into this one, resetting the variable count.
// @fnv 0x005aa420
void Script::CopyScriptContents(Script* apScriptToCopy)
{
    if (!apScriptToCopy)
        return;

    memcpy(&m_kHeader, apScriptToCopy->GetHeader(), sizeof(ScriptHeaderData));
    m_kHeader.variableCount = 0;

    SetScriptData(m_kHeader.dataSize, apScriptToCopy->GetData());

    InitializeActionList();
    CopyScriptReferences(apScriptToCopy->GetReferencedObjectList(), GetReferencedObjectList(), this);

    FUN_005aa2e0();
    CopyListToView(apScriptToCopy->GetVariableList(), GetVariableList(), this);

    if (apScriptToCopy->GetText())
        SetText(apScriptToCopy->GetText());
    else
        SetText(0);

    SetInitializationState(apScriptToCopy->IsFormInitialized());
}

struct G2
{
    void _ref_00905330(int* p);
    void AddHead(int* p);
};
struct ATM
{
    void QueryPerformanceCounter(int a);
    void WaitForTasksDuringRendering();
};
extern G2 g_011cac98;
extern G2 g_011caca8;
extern ATM g_011cacf8;
bool FUN_005aa680(int p);
// Queries the performance counter, and if value is non-zero references it and adds it to a list unless FUN_005aa680 accepts it, then waits for rendering tasks.
// @fnv 0x005aa580
void FUN_005aa580(int value)
{
    g_011cacf8.QueryPerformanceCounter(0);
    if (value)
    {
        g_011cac98._ref_00905330(&value);
        if (!FUN_005aa680(value))
            g_011caca8.AddHead(&value);
    }
    g_011cacf8.WaitForTasksDuringRendering();
}

namespace fnv_005aa5d0 {
struct G2
{
    void _ref_00905330(int* p);
};
struct ATM
{
    void QueryPerformanceCounter(int a);
    void WaitForTasksDuringRendering();
};
extern G2 g_011cac98;
extern G2 g_011caca8;
extern G2 g_011cacb8;
extern G2 g_011cace8;
extern ATM g_011cacf8;
// If value is nonzero, queries the performance counter, passes value to four objects' _ref_00905330, then waits for tasks during rendering.
// @fnv 0x005aa5d0
void FUN_005aa5d0(int value)
{
    if (value)
    {
        g_011cacf8.QueryPerformanceCounter(0);
        g_011caca8._ref_00905330(&value);
        g_011cac98._ref_00905330(&value);
        g_011cace8._ref_00905330(&value);
        g_011cacb8._ref_00905330(&value);
        g_011cacf8.WaitForTasksDuringRendering();
    }
}
}  // namespace fnv_005aa5d0

#include "../../include/ActorTaskManager.h"
namespace fnv_005aa630 {
extern BSSimpleList<Actor*> g_011cac98;
extern ActorTaskManager g_011cacf8;

// Checks whether apRef is non-null and present in g_011cac98, bracketing the check with calls on g_011cacf8, and returns the result.
// @fnv 0x005aa630
bool __cdecl FUN_005aa630(Actor* apRef)
{
    bool bretval = false;
    g_011cacf8.QueryPerformanceCounter(0);
    if (apRef && g_011cac98.IsInList(apRef))
        bretval = true;
    g_011cacf8.WaitForTasksDuringRendering();
    return bretval;
}
}  // namespace fnv_005aa630

namespace fnv_005aa680 {
extern BSSimpleList<Actor*> g_011caca8;
extern ActorTaskManager g_011cacf8;

// Checks whether apRef is non-null and present in g_011caca8, calling QueryPerformanceCounter and WaitForTasksDuringRendering around the check.
// @fnv 0x005aa680
bool __cdecl FUN_005aa680(Actor* apRef)
{
    bool bretval = false;
    g_011cacf8.QueryPerformanceCounter(0);
    if (apRef && g_011caca8.IsInList(apRef))
        bretval = true;
    g_011cacf8.WaitForTasksDuringRendering();
    return bretval;
}
}  // namespace fnv_005aa680

namespace fnv_005aa720 {
extern ActorTaskManager g_011cacf8;

void __fastcall FUN_00573f40(TESObjectREFR* ref);

extern BSSimpleList<TESObjectREFR*> g_011caca8;
extern BSSimpleList<TESObjectREFR*> g_011cac98;
extern BSSimpleList<TESObjectREFR*> g_011cace8;
extern BSSimpleList<TESObjectREFR*> g_011cacb8;

// @fnv 0x005aa720
void FUN_005aa720()
{
    BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
    g_011cacf8.QueryPerformanceCounter(0);
    while (!g_011caca8.IsEmpty())
    {
        TESObjectREFR* pref = g_011caca8.GetItem();
        g_011caca8.RemoveHead();
        FUN_00573f40(pref);
    }
    while (!g_011cac98.IsEmpty())
    {
        TESObjectREFR* pref = g_011cac98.GetItem();
        g_011cac98.RemoveHead();
        pref->FUN_00574400();
    }
    pCurrentElementNext = &g_011cace8;
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        TESObjectREFR* pref;
        NiNode* pav;
        BSSimpleList<TESObjectREFR*>* m_pActionSuccessor = pCurrentElementNext->GetNext();
        pref = pCurrentElementNext->GetItem();
        pav = pref->GetNiNode();
        BSFadeNode* pfade = pav ? pav->IsFadeNode() : 0;
        if (!pfade || !pfade->IsVisible())
        {
            pref->FUN_00574400();
            g_011cace8.Remove(pref);
            if (pCurrentElementNext == &g_011cace8)
                m_pActionSuccessor = &g_011cace8;
        }
        pCurrentElementNext = m_pActionSuccessor;
    }
    while (!g_011cacb8.IsEmpty())
    {
        TESObjectREFR* pref = g_011cacb8.GetItem();
        g_011cacb8.RemoveHead();
        delete pref;
    }
    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aa720

void __cdecl Deallocate(void*);
char* __cdecl AllocateZeroed(unsigned int, unsigned int);

// Frees m_data, stores auiDataSize at offset 0x20, and if nonzero allocates that many bytes and copies apCompileData into m_data.
// @fnv 0x005aae70
void Script::SetScriptData(unsigned int auiDataSize, char* apCompileData)
{
    Deallocate(m_data);
    m_data = 0;
    *(unsigned int*)((char*)this + 0x20) = auiDataSize;
    if (*(unsigned int*)((char*)this + 0x20))
    {
        m_data = AllocateZeroed(1, *(unsigned int*)((char*)this + 0x20));
        memcpy(m_data, apCompileData, *(unsigned int*)((char*)this + 0x20));
    }
}

MemoryManager* __cdecl FUN_00401020(void);

// Multiplies aSize by aNum, allocates that many bytes from the memory manager, zeroes them with memset, and returns the pointer.
// @fnv 0x005aaee0
char* __cdecl AllocateZeroed(unsigned int aNum, unsigned int aSize)
{
    aSize = aSize * aNum;
    void* pBuffer = FUN_00401020()->Allocate(aSize);
    memset(pBuffer, 0, aSize);
    return (char*)pBuffer;
}

void* __cdecl operator new(unsigned int);
bool __fastcall _ref_008256d0(void*);
int* __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);

class SoundListEntry;
class SoundListView
{
  public:
    void AddTail(SoundListEntry* const&);
};

// Copies each element of pCopyFromList into a new FUN_005ab8b0 and appends it to pCopyToList until the source list is exhausted or _ref_008256d0 returns true.
// @fnv 0x005ab7f0
void __cdecl CopyListToTail(void* pSourceList, SoundListView* pCopyToList)
{
    if (!pCopyToList || !pSourceList)
        return;

    while (pSourceList && !_ref_008256d0(pSourceList))
    {
        SoundListEntry* pNewRefObject = (SoundListEntry*)new ScriptReferencedObject((ScriptReferencedObject*)*_ref_006815c0(pSourceList));
        pCopyToList->AddTail(pNewRefObject);
        pSourceList = _ref_00726070(pSourceList);
    }
}

void __cdecl Deallocate(void*);
unsigned int __cdecl strlen(const char*);
void* __cdecl memcpy(void*, const void*, unsigned int);
char* __cdecl AllocateZeroed(int, int);

// Frees the stored string, then copies newText into a newly allocated buffer (or clears it when newText is null).
// @fnv 0x005abe50
void Script::SetText(const char* newText)
{
    if (m_pText)
    {
        Deallocate(m_pText);
    }
    if (newText)
    {
        int iSize = strlen(newText);
        m_pText = AllocateZeroed(1, iSize + 1);
        memcpy(m_pText, newText, iSize);
    }
    else
    {
        m_pText = 0;
    }
}

void* __cdecl operator new(unsigned int);
void* __fastcall CopyVariableList(Script*);

// Allocates a ScriptLocals, stores the result of CopyVariableList(this) at offset 0xc and this at offset 0, then returns it.
// @fnv 0x005abf60
ScriptLocals* Script::GetOrCreateScriptLocals()
{
    AutoMemContext tempMemContext(static_cast<MEM_CONTEXT>(0x15), true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 0xcde);
    ScriptLocals* sl = new ScriptLocals;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(sl) + 0xc) = CopyVariableList(this);
    *reinterpret_cast<Script**>(sl) = this;
    return sl;
}

// @fnv 0x005ac190
void __cdecl DoCheckScriptRunnerAndRun(TESObjectREFR* ownerObject, ExtraDataList* apExtra)
{
    if (apExtra && apExtra->FUN_00418830())
    {
        ScriptLocals* locals = apExtra->FUN_00418830();
        if (!locals->m_pLocalVariableList)
        {
            ScriptExecutor::Instance()->FUN_005e2730(locals->m_pOwnerScript, ownerObject, locals);
        }
    }
}

extern SettingT_GameSettingCollection_ g_011cac68;

// Runs the script via the script runner, decrementing a timer and resetting it from the game setting or a referenced value when the header flag is set.
// @fnv 0x005ac1e0
bool Script::Run(TESObjectREFR* ownerObject, ScriptLocals* ownerVars,
                                      TESObjectREFR* ownerContainer, bool abIsPartialScript)
{
    if (!abIsPartialScript && GetHeader()->dataSize <= 4)
        return false;

    if (GetHeader()->m_bQuest && fValueAtOffset38 > 0.0)
    {
        fValueAtOffset38 -= g_timeGlobal.FUN_0084d030();
        m_fValueAtOffset3C += g_timeGlobal.FUN_0084d030();
        if (fValueAtOffset38 > 0.0)
            return false;
    }

    bool bretVal = ScriptExecutor::Instance()->Run(this, ownerObject, ownerVars, ownerContainer, abIsPartialScript,
                                                   false, false, 0.0f);

    if (GetHeader()->m_bQuest && g_011cac68.Float()->f > 0.0)
    {
        if (m_pOwnerQuest && m_pOwnerQuest->FUN_00792760() > 0.0)
        {
            fValueAtOffset38 += m_pOwnerQuest->FUN_00792760();
        }
        else
        {
            fValueAtOffset38 += g_011cac68.Float()->f;
        }
        m_fValueAtOffset3C = 0.0f;
    }

    FUN_005ae2e0();
    return bretVal;
}

namespace fnv_005ac4f0 {

void __cdecl FUN_005acc90(unsigned int* apFormID, double* apValue);
bool __fastcall _ref_008256d0(void* pList);
void* __fastcall _ref_00726070(void* pList);
ScriptReferencedObject** __fastcall _ref_006815c0(void* pList);

struct TLSData
{
    char padding[0x27c];
    ScriptReferencedObject* lastRefObj;
    unsigned int lastIndex;
    ScriptLocals* lastLocals;
    Script* lastScript;
};

__declspec(thread) TLSData g_tlsData;

} // namespace fnv_005ac4f0

// Returns the reference at aiIndex in this object's extra-data list, resolving its form ID via the script locals and caching the last result in TLS.
// @fnv 0x005ac4f0
ScriptReferencedObject* Script::GetReferencedForm(unsigned int aiIndex, ScriptLocals* apScriptLocals)
{
    using namespace fnv_005ac4f0;
    if (aiIndex == 0)
        return 0;
    if (aiIndex > *(unsigned int*)((char*)this + 0x1c))
        return 0;

    if (fnv_005ac4f0::g_tlsData.lastScript == this && fnv_005ac4f0::g_tlsData.lastIndex == aiIndex && fnv_005ac4f0::g_tlsData.lastLocals == apScriptLocals)
        return fnv_005ac4f0::g_tlsData.lastRefObj;

    void* pList;
    ScriptReferencedObject* pExtraDataEntry;
    unsigned int iCount = 1;
    pList = ((TESObjectREFR*)this)->GetExtraData();

    while (pList && !fnv_005ac4f0::_ref_008256d0(pList) && iCount < aiIndex)
    {
        iCount++;
        pList = fnv_005ac4f0::_ref_00726070(pList);
    }

    if (!pList)
        return 0;

    pExtraDataEntry = *fnv_005ac4f0::_ref_006815c0(pList);
    if (*(unsigned int*)((char*)pExtraDataEntry + 0xc) != 0 && apScriptLocals != 0)
    {
        double dtemp =
            apScriptLocals->GetVariable(*(unsigned int*)((char*)pExtraDataEntry + 0xc), this);
        unsigned int formID = 0;
        fnv_005ac4f0::FUN_005acc90(&formID, &dtemp);
        if (formID != 0)
        {
            *(TESForm**)((char*)pExtraDataEntry + 8) = TESForm::GetFormByID(formID);
        }
    }

    fnv_005ac4f0::g_tlsData.lastScript = this;
    fnv_005ac4f0::g_tlsData.lastLocals = apScriptLocals;
    fnv_005ac4f0::g_tlsData.lastIndex = aiIndex;
    fnv_005ac4f0::g_tlsData.lastRefObj = pExtraDataEntry;
    return pExtraDataEntry;
}

// If apExtra has script locals, forwards apActionForm and aiFlag to the locals' FUN_005a8e20 and returns its result; otherwise returns false.
// @fnv 0x005ac750
bool __cdecl MarkBaseExtraListScriptEvent(TESForm* apActionForm, ExtraDataList* apExtra, unsigned int aiFlag)
{
    bool bres = false;
    if (apExtra && apExtra->FUN_00418830())
    {
        ScriptLocals* locals = apExtra->FUN_00418830();
        bres = locals->FUN_005a8e20(apActionForm, aiFlag);
    }
    return bres;
}

// @fnv 0x005acc90
void __cdecl FUN_005acc90(unsigned int* aiID, const double* adVal)
{
    memcpy(aiID, adVal, sizeof(unsigned int));
}

// @fnv 0x00792760
float TESQuest::FUN_00792760()
{
    return data.fQuestDelayTime;
}

namespace fnv_005a8d20 {

struct G2
{
    void AddHead(int*);
};
} // namespace fnv_005a8d20

// @fnv 0x005a8d20
void ScriptLocals::CopyActionListFrom(ScriptLocals* apLocals)
{
    AutoMemContext ctx((MEM_CONTEXT)0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                       300);
    if (!*(void**)((char*)this + 8))
        *(SL**)((char*)this + 8) = new SL();
    FormFlagRecord* used = GetActionEntry((TESForm*)apLocals, false);
    if (!used)
    {
        used = new FormFlagRecord;
        used->pForm = (TESForm*)apLocals;
        used->iFlags = 0;
        (*(fnv_005a8d20::G2**)((char*)this + 8))->AddHead((int*)&used);
    }
}

struct Flt
{
    operator unsigned int() const;
};
struct VarX
{
    unsigned int id;
    char pad[0x14];
    Flt flt;
};
typedef char*(__thiscall* NameFn)(void*);
int* __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
// @fnv 0x005abed0
const char* Script::GetVariableName(unsigned int auiID)
{
    void* pList = GetVariableList();
    while (pList && *_ref_006815c0(pList))
    {
        VarX* pVar = (VarX*)*_ref_006815c0(pList);
        pList = _ref_00726070(pList);
        if (pVar->id == auiID)
            return (char*)(unsigned int)pVar->flt;
    }
    Warning("SCRIPTS: Trying to access local variable %d in script '%s' -- variable not found.\r\n", auiID,
            (*(NameFn**)this)[0x130 / 4](this));
    return 0;
}

bool __fastcall _ref_008256d0(unsigned int);
int* __fastcall _ref_006815c0(void*);
void* __fastcall _ref_00726070(void*);
__declspec(thread) void* g_tlsSlot;
// Clears the thread-local slot if it holds this object, then walks the extra-data list and zeroes f8 on each referenced object that has a nonzero fc.
// @fnv 0x005ae2e0
void Script::FUN_005ae2e0()
{
    if (g_tlsSlot == (void*)this)
        g_tlsSlot = 0;
    void* pCurrentElementNext = ((TESObjectREFR*)this)->GetExtraData();
    while (pCurrentElementNext && !_ref_008256d0((unsigned int)pCurrentElementNext))
    {
        ScriptReferencedObject* prefObject = (ScriptReferencedObject*)*_ref_006815c0(pCurrentElementNext);
        if (prefObject && prefObject->m_uiFormID)
            prefObject->pForm = 0;
        pCurrentElementNext = _ref_00726070(pCurrentElementNext);
    }
}

void __cdecl Deallocate(void*);

struct FUN_005a9460_This
{
    unsigned int field_1c4;
    unsigned int FUN_005a9460();
};

// @fnv 0x005a9460
unsigned int FUN_005a9460_This::FUN_005a9460()
{
    return reinterpret_cast<unsigned int*>(this)[0x1c4 / 4];
}

namespace fnv_005aae20 {
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};

struct G2
{
    void RemoveAll();
};

struct GlobalObject2_0096a2d0
{
    void RemoveAll();
};

extern ATM g_011cacf8;
extern G2 g_011cac98;
extern G2 g_011caca8;
extern GlobalObject2_0096a2d0 g_011cacb8;
extern GlobalObject2_0096a2d0 g_011cace8;

// @fnv 0x005aae20
void __cdecl FUN_005aae20()
{
    g_011cacf8.QueryPerformanceCounter(0);
    g_011caca8.RemoveAll();
    g_011cac98.RemoveAll();
    g_011cacb8.RemoveAll();
    g_011cace8.RemoveAll();
    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aae20

extern "C" bool __cdecl FUN_00401500();
extern "C" unsigned int __cdecl AppendChunk(unsigned int, void*, unsigned int);

// @fnv 0x005abe00
void ScriptUnitOperations::SaveHeader()
{
    if (FUN_00401500())
        m_kHeader.Endian();
    AppendChunk(0x52484353, &m_kHeader, 0x14);
    if (FUN_00401500())
        m_kHeader.Endian();
}

// @fnv 0x005ac730
void FUN_005ac730(bool abProcessScripts)
{
    DAT_0118c685 = abProcessScripts;
}

__declspec(thread) int DAT_tls;

// @fnv 0x005ae270
void FUN_005ae270()
{
    *(int*)((char*)&DAT_tls + 0x288) = 0;
    *(int*)((char*)&DAT_tls + 0x284) = 0;
    *(int*)((char*)&DAT_tls + 0x280) = 0xffffffff;
    *(int*)((char*)&DAT_tls + 0x27c) = 0;
}

struct FUN_00857bd0
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0c;
    int m_0x10;
    unsigned int m_0x14;
    void Init(unsigned int value);
};

// @fnv 0x00857bd0
void FUN_00857bd0::Init(unsigned int value)
{
    m_0x14 += value;
}

__declspec(thread) int tlsVar1;
__declspec(thread) int tlsVar2 = -1;
__declspec(thread) int tlsVar3;

// Resets the three thread-local variables to 0, -1 and 0.
// @fnv 0x005a9d60
void FUN_005a9d60()
{
    tlsVar1 = 0;
    tlsVar2 = -1;
    tlsVar3 = 0;
}

namespace fnv_005aa6d0 {
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

struct LH
{
    bool IsInList(int*&);
};

extern ATM g_011cacf8;
extern LH g_011cace8;

// Queries the performance counter, checks whether arg is in the list, waits for tasks during rendering, and returns whether arg was found.
// @fnv 0x005aa6d0
char __cdecl FUN_005aa6d0(int* pItem)
{
    char result = 0;
    g_011cacf8.QueryPerformanceCounter(0);
    if (pItem && g_011cace8.IsInList(pItem))
        result = 1;
    g_011cacf8.WaitForTasksDuringRendering();
    return result;
}
}  // namespace fnv_005aa6d0

// Unit-only flag operations missing from the shared declarations; no added layout.
struct BSFadeNodeUnitOperations : BSFadeNode
{
    bool HasFlags(unsigned int);
    bool HasFlag8000();
};

// @fnv 0x005aa910
bool BSFadeNodeUnitOperations::HasFlag8000()
{
    return this->HasFlags(0x8000);
}

// @fnv 0x005abd70
bool Script::LoadForm(TESFile* apFile)
{
    return TESForm::LoadForm(apFile);
}

struct FUN_00857ba0_class
{
    void __thiscall ReadFromStream(int a, int b, int c);
};

void __thiscall FUN_00857ba0_class::ReadFromStream(int a, int b, int c)
{}

struct FUN_008586d0_class
{
    void __thiscall FUN_008586d0(int a, int b, int c);
};

// @fnv 0x008586d0
void __thiscall FUN_008586d0_class::FUN_008586d0(int a, int b, int c)
{
    reinterpret_cast<FUN_00857ba0_class*>(this)->ReadFromStream(a, b, c);
}

struct LocalListStub
{
    ScriptLocalVariable** _ref_006815c0();
};

// Searches the script local list for the given variable ID and assigns the value, warning if the variable is not found.
// @fnv 0x005a9290
void ScriptLocals::SetVariable(unsigned int auiID, double value)
{
    BSSimpleList<ScriptLocalVariable*>* pList = (BSSimpleList<ScriptLocalVariable*>*)((TESForm*)this)->GetFormID();
    while (pList && *((LocalListStub*)pList)->_ref_006815c0())
    {
        ScriptLocalVariable* pLocal = *((LocalListStub*)pList)->_ref_006815c0();
        pList = pList->GetNext();
        if (pLocal->uiID == auiID)
        {
            pLocal->fValue = value;
            return;
        }
    }
    bool bshowGenericWarning = true;
    if (*(TESForm**)this)
    {
        Warning("SCRIPTS: Trying to set variableID %d in script '%s' -- variable not found.", auiID,
                (*(TESForm**)this)->GetName());
        bshowGenericWarning = false;
    }
    else if (g_TESSaveLoadGame->GetLoading())
    {
        FormRecordMetadata* ploadHeader = static_cast<FormRecordMetadata*>(g_TESSaveLoadGame->FUN_004fd3c0());  // 0x004fd3c0: the currently loading form header
        TESForm* pform = 0;
        if (ploadHeader)
        {
            pform = TESForm::GetFormByID(ploadHeader->iFormID);
            TESObjectREFR* pref = dynamic_cast<TESObjectREFR*>(pform);
            const char* pfullname;
            if (pref)
                pfullname = ((MobileObject*)pref)->GetFullName();
            else
                pfullname = TESFullName::GetFullName(pform);
            if (pform && pfullname)
            {
                if (pref)
                    Warning(
                        "SAVELOAD: (LoadGame '%s') Trying to set variableID %d on ref '%s' (%08X) -- variable not found. The script may have been changed in the master/plug-in file.",
                        g_TESSaveLoadGame->FUN_005a9460(), auiID, pfullname, ploadHeader->iFormID);
                else
                    Warning(
                        "SAVELOAD: (LoadGame '%s') Trying to set variableID %d on '%s' (%08X) -- variable not found. The script may have been changed in the master/plug-in file.",
                        g_TESSaveLoadGame->FUN_005a9460(), auiID, pfullname, ploadHeader->iFormID);
            }
            else
            {
                Warning(
                    "SAVELOAD: (LoadGame '%s') Trying to set variableID %d on (%08X) -- variable not found. The script may have been changed in the master/plug-in file.",
                    g_TESSaveLoadGame->FUN_005a9460(), auiID, ploadHeader->iFormID);
            }
            bshowGenericWarning = false;
        }
    }
    if (bshowGenericWarning)
        Warning("SCRIPTS: Trying to set variableID %d -- variable not found.", auiID);
}

namespace fnv_005a9f20 {

} // namespace fnv_005a9f20

// @fnv 0x005a9f20
void ScriptLocals::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    using namespace fnv_005a9f20;
    bool bhasScriptEffectData;
    bool bonLoadFlagSet;
    {
        unsigned int iVariableCount = apLoadGameBuffer->BGSLoadGameBuffer::ReadElementCount();
        for (unsigned int iIndex = 0; iIndex < iVariableCount; iIndex++)
        {
            double fvalue = 0.0;
            unsigned int ivarID = 0;
            apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&ivarID, 4);
            if (ivarID & 0x80000000)
            {
                ivarID &= 0x7fffffff;
                unsigned int irefID = 0;
                apLoadGameBuffer->BGSLoadGameBuffer::ReadFormIdentifier(&irefID);
                Script::CopyIdentifierBitsToValue(irefID, fvalue);
            }
            else
            {
                apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&fvalue, 8);
            }
            SetVariable(ivarID, fvalue);
        }
    }
    bhasScriptEffectData = false;
    apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&bhasScriptEffectData, 1);
    if (bhasScriptEffectData)
    {
        *(double**)((char*)this + 0x10) = new double;
        apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)*(double**)((char*)this + 0x10), 8);
    }
    bonLoadFlagSet = false;
    if (apLoadGameBuffer->GetVersion() >= 0x15)
        apLoadGameBuffer->BGSLoadGameBuffer::ReadTypedData((void*)&bonLoadFlagSet, 1);
    if (*(void**)((char*)this + 8) == 0)
        ScriptExecutor::Instance()->FUN_005e2730(*(Script**)this, apLoadGameBuffer->GetReference(), this);
    else
        ((ScriptLocals*)this)->ClearActionFlags();
    if (bonLoadFlagSet)
        FUN_005a8e20(0, 0x1000);
}

namespace fnv_005ac020 {

struct SoundListView
{
    void AddTail(char* const&);
};
struct S006815c0
{
    ScriptVariableInfo** FUN_006815c0();
    S006815c0* FUN_00726070();
};

} // namespace fnv_005ac020

// @fnv 0x005ac020
BSSimpleList<ScriptLocalVariable*>* Script::GetScriptEntryList()
{
    using namespace fnv_005ac020;
    AutoMemHelper tempMemContext(0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                                 0xceb);
    S006815c0* pList;
    fnv_005ac020::SoundListView* pNewList;

    pNewList = (fnv_005ac020::SoundListView*)new SL;
    pList = (S006815c0*)GetVariableList();
    while (pList && *pList->FUN_006815c0())
    {
        char* pLocal;
        ScriptVariableInfo* pVar;
        pVar = *pList->FUN_006815c0();
        pList = pList->FUN_00726070();
        pLocal = (char*)new ScriptLocalVariable(pVar);
        pNewList->AddTail(pLocal);
    }
    return (BSSimpleList<ScriptLocalVariable*>*)pNewList;
}

namespace fnv_005ab930 {
struct FUN_005e2910
{
    char* m_pInventoryEntryData;
    char m_bIsDeleted;
    FUN_005e2910(char*);
    ~FUN_005e2910();
};

struct FUN_008256d0
{
    char* m_pInventoryEntryData;
    unsigned char FUN_008256d1() const;
    FUN_005e2910* FUN_006815c0() const;
    FUN_008256d0* FUN_00726070();
};

struct SoundListView
{
    void AddTail(FUN_005e2910* const&);
};

struct FUN_005e2910Big
{
    char* m_pInventoryEntryData;
    char m_bIsDeleted;
    FUN_005e2910Big(char*);
    ~FUN_005e2910Big();
    char m_bFiller[0x18];
};

// @fnv 0x005ab930
void CopyListToView(FUN_008256d0* pSourceList, SoundListView* pTargetView)
{
    if (!pTargetView || !pSourceList)
        return;

    while (pSourceList && !pSourceList->FUN_008256d1())
    {
        FUN_005e2910* const pNewItem =
            (FUN_005e2910*)new FUN_005e2910Big(pSourceList->FUN_006815c0()->m_pInventoryEntryData);
        pTargetView->AddTail(pNewItem);
        pSourceList = pSourceList->FUN_00726070();
    }
}
}  // namespace fnv_005ab930

namespace fnv_005aa090 {
void __cdecl _Deallocate(void*);

void* __fastcall CopyVariableList(Script*);

} // namespace fnv_005aa090

// Calls FUN_005a8c90 and FUN_005a8ea0, refreshes pData from pScript, frees pAlloc and clears it.
// @fnv 0x005aa090
void ScriptLocals::ResetFormData(Script* dummy)
{
    FUN_005a8c90(this);
    ((ScriptLocals*)this)->ClearActionFlags();
    if (m_pOwnerScript)
        m_pVariableList = (BSSimpleList<ScriptLocalVariable*>*)fnv_005aa090::CopyVariableList(m_pOwnerScript);
    if (m_pExtendedLocals)
    {
        void* tmp = m_pExtendedLocals;
        fnv_005aa090::_Deallocate(tmp);
    }
    m_pExtendedLocals = 0;
}

bool FUN_00401500();
void AppendChunk(unsigned int, char*, unsigned int);
// @fnv 0x005abd90
void ScriptUnitOperations::Save()
{
    TESForm::FUN_004855a0();
    TESForm::ClearData();
    if (FUN_00401500())
        reinterpret_cast<ScriptHeaderData*>(reinterpret_cast<char*>(this) + 0x18)->Endian();
    AppendChunk(0x52484353, reinterpret_cast<char*>(this) + 0x18, 0x14);
    if (FUN_00401500())
        reinterpret_cast<ScriptHeaderData*>(reinterpret_cast<char*>(this) + 0x18)->Endian();
    TESForm::FUN_00485680();
}

namespace fnv_005ac6a0 {
int __cdecl FUN_00404dc0(const char*, const char*);
struct Flt
{
    operator unsigned int() const;
};
} // namespace fnv_005ac6a0

// @fnv 0x005ac6a0
char ScriptUnitOperations::FindVariableType(const char* pcName, unsigned int* puiID)
{
    using namespace fnv_005ac6a0;
    BSSimpleList<ScriptVariableInfo*>* node = GetVariableList();
    while (node && node->GetItem())
    {
        ScriptVariableInfo* variable = node->GetItem();
        node = node->GetNext();
        if (FUN_00404dc0((const char*)(unsigned int)*(fnv_005ac6a0::Flt*)((char*)variable + 0x18), pcName) == 0)
        {
            *puiID = variable->data.uiID;
            if (variable->data.m_bIsString)
                return 's';
            else
                return 'f';
        }
    }
    *puiID = 0;
    return 0;
}

namespace fnv_005aa500 {
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};

struct ContNode
{
    void FUN_00905330(void*);
};

struct G2 : public ContNode
{
    void AddHead(int*);
};

struct GlobalObject2_0096a2d0 : public G2
{
};

extern ATM g_011cacf8;
extern G2 g_011caca8;
extern G2 g_011cac98;
extern GlobalObject2_0096a2d0 g_011cace8;

bool __cdecl FUN_005aa630(int);
bool __cdecl FUN_005aa6d0(int);

// @fnv 0x005aa500
void __cdecl FUN_005aa500(int aiTask, unsigned char abAlternate)
{
    g_011cacf8.QueryPerformanceCounter(0);

    if (aiTask != 0)
    {
        g_011caca8.FUN_00905330(&aiTask);

        if (abAlternate == 0)
        {
            if (!FUN_005aa630(aiTask))
                g_011cac98.AddHead(&aiTask);
        }
        else
        {
            if (!FUN_005aa6d0(aiTask))
                g_011cace8.AddHead(&aiTask);
        }
    }

    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aa500

namespace fnv_005aaaf0 {
struct G2;

struct List_009e03e0
{
    void RemoveAll();
};

struct G2 : public List_009e03e0
{
    void AddHead(int* value);
};

struct GlobalObject2_0096a2d0 : public G2
{
};

class ATM
{
  public:
    void QueryPerformanceCounter(int value);
    void WaitForTasksDuringRendering();
};

TESForm* _GetFormByNumericID(unsigned int formID);

G2 g_011cac98;
G2 g_011caca8;
GlobalObject2_0096a2d0 g_011cacb8;
GlobalObject2_0096a2d0 g_011cace8;
ATM g_011cacf8;

// @fnv 0x005aaaf0
void __cdecl LoadReferenceLists(BGSLoadFormBuffer* buffer)
{
    g_011cacf8.QueryPerformanceCounter(0);
    g_011caca8.RemoveAll();
    g_011cac98.RemoveAll();
    g_011cacb8.RemoveAll();
    g_011cace8.RemoveAll();

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new TESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011caca8.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new TESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011cac98.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new TESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011cacb8.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = buffer->ReadElementCount();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new TESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(_GetFormByNumericID(buffer->ReadFormIdentifier()));
                g_011cace8.AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    g_011cacf8.WaitForTasksDuringRendering();
}
}  // namespace fnv_005aaaf0

struct CStringArgument
{
    const char* input;
};

struct S7010
{
    unsigned int Length();
};

struct TESFaction_RankDataView
{
    unsigned char* GetRankDataList();
};

void* __cdecl __memcpy(void* destination, void* source, unsigned int size);

// @fnv 0x005aaf20
void Script::InitFromCompileData(CStringArgument* apCompileData)
{
    this->InitItem();

    if (((S7010*)((char*)apCompileData + 0x0C))->Length() == 0)
    {
        this->MarkForDeletion(true);
    }
    else if (((ScriptUnitOperations*)this)->IsDifferentFromCompileData((CompileDataStub*)apCompileData))
    {
        this->SetEditorID_AtRuntime((const char*)(((GO*)((char*)apCompileData + 0x0C))->operator unsigned int()));

        __memcpy((char*)this + 0x18, (char*)apCompileData + 0x28, 0x14);

        this->SetScriptData(*(unsigned int*)((char*)this + 0x20), *(char**)((char*)apCompileData + 0x20));

        this->InitializeActionList();
        this->FUN_005aa2e0();

        if (*(unsigned int*)((char*)this + 0x20) != 0)
        {
            Script::CopyScriptReferences(
                (BSSimpleList<ScriptReferencedObject*>*)((TESObjectREFR*)apCompileData)->GetExtraData(),
                (BSSimpleList<ScriptReferencedObject*>*)((TESObjectREFR*)this)->GetExtraData(), (Script*)this);

            Script::CopyListToView(
                (BSSimpleList<ScriptVariableInfo*>*)(unsigned char*)((TESFaction_RankDataView*)apCompileData)
                    ->GetRankDataList(),
                this->GetVariableList(), (Script*)this);
        }

        this->MarkForDeletion(false);
        this->SetAltered(true);
    }
}

// Runs the script on the target reference with the given effect locals via the script runner singleton.
// @fnv 0x005ac340
void Script::ExecuteScript(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptExecutor::Instance()->Run((Script*)this, apTargetRef, apEffectLocals, 0, 0, 1, 0, 0.0f);
}

// @fnv 0x005ac380
void ScriptUnitOperations::ExecuteEffectOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptExecutor::Instance()->Run((Script*)this, apTargetRef, apEffectLocals, 0, 0, 0, 1, 0.0f);
}

#include "../../include/COMPILER_NAME.h"

#include "../../include/ScriptCompiler.h"
extern int __tls_index;
__declspec(thread) unsigned char FUN_005ac400_tls[0x269];

// Compiles the script with the given compiler index and owner object, and if compilation succeeds and the script has data, runs it with the owner's locals.
// @fnv 0x005ac400
void Script::CompileScriptText(ScriptCompiler* compiler, COMPILER_NAME compilerIndex,
                                       TESObjectREFR* ownerObject)
{
    AutoMemHelper tempMemContext(0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                                 0xd53);

    if (compiler->FUN_005aedb0((Script*)this, ownerObject, compilerIndex, false) &&
        ((Script*)this)->m_kHeader.dataSize != 0)
    {
        if (compilerIndex == 1)
            FUN_005ac400_tls[0x268] = 1;

        ScriptLocals* ownerVars = 0;
        if (ownerObject != 0)
            ownerVars = ownerObject->GetReferenceLocals();

        ((Script*)this)->Run(ownerObject, ownerVars, (TESObjectREFR*)0, true);

        FUN_005ac400_tls[0x268] = 0;
    }
}

void* __fastcall FUN_005d43c0(void* pThis);
int* __fastcall FUN_006815c0(void* pThis);
void* __fastcall FUN_00726070(void* pThis);

// Walks the linked list from pHead and returns true if any node's item has a formID matching formID.
// @fnv 0x005a9480
bool ScriptLocals::IsReferenceVariable(unsigned int formID)
{
    if (m_pOwnerScript == 0)
    {
        return false;
    }
    void* node = FUN_005d43c0(m_pOwnerScript);
    while (node != 0 && *FUN_006815c0(node) != 0)
    {
        ScriptReferencedObject* item = (ScriptReferencedObject*)*FUN_006815c0(node);
        if (item->m_uiFormID == formID)
        {
            return true;
        }
        node = FUN_00726070(node);
    }
    return false;
}

struct ScriptLocalList
{
    ScriptLocalVariable** FUN_006815c0();
    ScriptLocalList* FUN_00726070();
};
struct GlobalGameState
{
    bool FUN_00862110();
    void* FUN_004fd3e0();
};
struct FlagManager
{
    unsigned char* FUN_00408d60();
};
struct MessageProducer
{
    void* unk00;
};
struct Formatter
{
    unsigned int getItem(int item, unsigned int line, const char* text)
    {
        typedef unsigned int(__thiscall * Callback)(Formatter*, int, unsigned int, const char*);
        Callback fn = *(Callback*)(*(char**)this + 0x130);
        return fn(this, item, line, text);
    }
};
extern GlobalGameState* DAT_011de45c;
extern FlagManager DAT_011de4e8;
extern const char DAT_01036d58;
extern const char DAT_01012cb0;
extern const char DAT_01012c78;
extern Formatter* __cdecl FUN_004839c0(void* item);
extern void __cdecl FUN_0040fbe0(const char* message, ...);
// @fnv 0x005a94f0
unsigned short __fastcall GetScriptLocalsSerializedSize(ScriptLocals* pLocals)
{
    unsigned short bytes = 0;
    unsigned short original = bytes;
    if (DAT_011de45c->FUN_00862110())
    {
        bytes += 4;
        bytes += 2;
    }
    bytes += 2;
    ScriptLocalList* entry = (ScriptLocalList*)pLocals->m_pVariableList;
    while (entry)
    {
        ScriptLocalVariable* value = *entry->FUN_006815c0();
        if (value && value->fValue != 0.0)
        {
            if (pLocals->IsReferenceVariable(value->uiID))
                bytes += 8;
            else
                bytes += 12;
        }
        entry = entry->FUN_00726070();
    }
    bytes += 1;
    if (pLocals->m_pExtendedLocals)
        bytes += 8;
    if (*DAT_011de4e8.FUN_00408d60())
    {
        void* info = DAT_011de45c->FUN_004fd3e0();
        if (info)
        {
            Formatter* formatter = FUN_004839c0(*(void**)info);
            FUN_0040fbe0(&DAT_01012cb0, (unsigned int)bytes - (unsigned int)original, *(void**)info,
                         ((TESForm*)formatter)->GetName(), *(int*)((char*)info + 5), 638, &DAT_01036d58);
        }
        else
        {
            FUN_0040fbe0(&DAT_01012c78, (unsigned int)bytes - (unsigned int)original, 638, &DAT_01036d58);
        }
    }
    return bytes;
}

void* __fastcall CopyVariableList(Script*);

// @fnv 0x005a9d00
void ScriptLocals::Revert()
{
    FUN_005a8c90(this);
    ClearActionFlags();
    if (m_pOwnerScript)
        m_pVariableList = (BSSimpleList<ScriptLocalVariable*>*)CopyVariableList(m_pOwnerScript);
    if (m_pExtendedLocals)
        delete (void*)m_pExtendedLocals;
    m_pExtendedLocals = 0;
}

void __cdecl FUN_005acc90(unsigned int* aiID, const double* adVal);

// @fnv 0x005a9db0
void ScriptLocals::SaveGame(BGSSaveFormBuffer* buffer)
{
    int count3 = 0;
    unsigned int offset = buffer->FUN_00865f20();
    BSSimpleList<ScriptLocalVariable*>* node3 = m_pVariableList;
    while (node3)
    {
        ScriptLocalVariable* local_ = node3->GetItem();
        if (local_ && local_->fValue != 0.0)
        {
            if (IsReferenceVariable(local_->uiID))
            {
                unsigned int value7 = 0;
                FUN_005acc90(&value7, &local_->fValue);
                unsigned int id3 = local_->uiID | 0x80000000;
                buffer->FUN_00865e50(&id3, 4, 0);
                buffer->FUN_00865db0(value7, 0);
            }
            else
            {
                buffer->FUN_00865e50(local_, 4, 0);
                buffer->FUN_00865e50(&local_->fValue, 8, 0);
            }
            count3++;
        }
        node3 = node3->GetNext();
    }
    buffer->FUN_00865ff0(count3, offset);
    unsigned char hasEffect = m_pExtendedLocals != 0;
    buffer->FUN_00865e50(&hasEffect, 1, 0);
    if (hasEffect)
    {
        buffer->FUN_00865e50(m_pExtendedLocals, 8, 0);
    }
    char result2 = CheckActionFlag(0, 0x1000);
    buffer->FUN_00865e50(&result2, 1, 0);
}

extern unsigned char DAT_011ad7b4;
extern double DAT_01012060;

// Returns true when flag 0x8000 is set, fading is disabled, or the current fade exceeds the threshold.
// @fnv 0x005aa8c0
bool BSFadeNode::IsVisible()
{
    return (static_cast<BSFadeNodeUnitOperations*>(this)->HasFlag8000() || DAT_011ad7b4 == 0 ||
            fCurrentFade > DAT_01012060) ? 1 : 0;
}

int __cdecl StrICmp(const char*, const char*);

struct ScrVarStub
{
    bool IsDifferent(ScrVarStub* other);
};

struct VarListStub
{
    ScrVarStub** Item();
    VarListStub* Next();
    int Count();
};

struct RefListStub
{
    ScriptReferencedObject** Item();
    RefListStub* Next();
    int Count();
};

struct NameStr
{
    int unk00;
    int unk04;
    unsigned int Length();
    operator const char*() const;
};

struct CompileDataStub
{
    int unk00;
    int unk04;
    int unk08;
    NameStr name;
    int unk14;
    int unk18;
    int unk1C;
    char* data;
    int unk24;
    ScriptHeaderData header;
    VarListStub* GetVars();
    RefListStub* GetRefs();
};

// @fnv 0x005ab040
bool ScriptUnitOperations::IsDifferentFromCompileData(CompileDataStub* apData)
{
    unsigned int i8;
    ScriptHeaderData* headerTmp;
    char* dataB;
    VarListStub* newVars;
    VarListStub* oldVars;
    ScrVarStub* newVar4;
    ScrVarStub* oldVar4;
    RefListStub* newRefs3;
    RefListStub* oldRefs4;
    ScriptReferencedObject* newRef;
    ScriptReferencedObject* oldRef;

    if (TESForm::FUN_00474cb0() && apData->name.Length())
    {
        if (StrICmp(GetName(), apData->name))
            return true;
    }

    headerTmp = &apData->header;
    if (m_kHeader.dataSize != headerTmp->dataSize)
        return true;
    if (m_kHeader.m_uiReferenceID != headerTmp->m_uiReferenceID)
        return true;

    dataB = apData->data;
    for (i8 = 0; i8 < m_kHeader.dataSize; i8++)
    {
        if (m_data[i8] != dataB[i8])
            return true;
    }

    newVars = apData->GetVars();
    oldVars = (VarListStub*)GetVariableList();
    if (newVars->Count() != oldVars->Count())
        return true;
    while (newVars && oldVars)
    {
        oldVar4 = *oldVars->Item();
        newVar4 = *newVars->Item();
        if (newVar4 && oldVar4 && newVar4->IsDifferent(oldVar4))
            return true;
        newVars = newVars->Next();
        oldVars = oldVars->Next();
    }

    newRefs3 = apData->GetRefs();
    oldRefs4 = (RefListStub*)GetReferencedObjectList();
    if (newRefs3->Count() != oldRefs4->Count())
        return true;
    while (newRefs3 && oldRefs4)
    {
        oldRef = *oldRefs4->Item();
        newRef = *newRefs3->Item();
        if (newRef && oldRef && newRef->pForm != oldRef->pForm)
            return true;
        newRefs3 = newRefs3->Next();
        oldRefs4 = oldRefs4->Next();
    }
    return false;
}

struct FUN_005a8c00_list
{
    void _ref_0063f7b0();
    int _ref_004702f0(int flag);
};

// @fnv 0x005a8c00
void __fastcall FUN_005a8c00(void* pThis)
{
    unsigned int v;
    void* arg;
    void* t;
    void* l;
    if (((ScriptLocals*)pThis)->m_pLocalVariableList != 0)
    {
        while (*_ref_006815c0(((ScriptLocals*)pThis)->m_pLocalVariableList) != 0)
        {
            v = *(unsigned int*)_ref_006815c0(((ScriptLocals*)pThis)->m_pLocalVariableList);
            ((FUN_005a8c00_list*)((ScriptLocals*)pThis)->m_pLocalVariableList)->_ref_0063f7b0();
            arg = (void*)v;
            Deallocate(arg);
        }
        t = ((ScriptLocals*)pThis)->m_pLocalVariableList;
        l = t;
        l != 0 ? ((FUN_005a8c00_list*)l)->_ref_004702f0(1) : 0;
        ((ScriptLocals*)pThis)->m_pLocalVariableList = 0;
    }
}

struct StateX
{
    char* FUN_00825c00();
    void FUN_008579b0(const void* p, unsigned int n);
    void FUN_00857a10(const void* p, unsigned int n);
};
void __cdecl FUN_005b5e40(const char* pFmt, const char* file, int line);

// Serializes the script local variable list to the save stream, writing a BLOCK chunk header, count, tagged values and an optional tail, with debug logging.
// @fnv 0x005a9670
void ScriptLocals::SaveGame()
{
    char* posTmp;
    char* endPos;
    Formatter* pFmt;
    char* curPos;
    void* formPtr;
    unsigned int converted;
    unsigned int tagged;
    ScriptLocalVariable* pCur;
    unsigned int chunkTag;
    unsigned short written;
    ScriptLocalList* pList;
    char* fromPos;
    unsigned short numHdr;
    char* posNum;
    bool hasTail;
    char* posB;
    numHdr = 0;
    posB = 0;
    fromPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
    if (*DAT_011de4e8.FUN_00408d60())
        fromPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
    if (DAT_011de45c->FUN_00862110())
    {
        chunkTag = 0x424c4f4b;
        ((StateX*)DAT_011de45c)->FUN_008579b0(&chunkTag, 4);
        posB = ((StateX*)DAT_011de45c)->FUN_00825c00();
        ((StateX*)DAT_011de45c)->FUN_008579b0(&numHdr, 2);
    }
    written = 0;
    posNum = ((StateX*)DAT_011de45c)->FUN_00825c00();
    ((StateX*)DAT_011de45c)->FUN_008579b0(&written, 2);
    pList = (ScriptLocalList*)m_pVariableList;
    while (pList)
    {
        pCur = *pList->FUN_006815c0();
        if (pCur && pCur->fValue != 0.0)
        {
            if (IsReferenceVariable(pCur->uiID))
            {
                converted = 0;
                FUN_005acc90(&converted, &pCur->fValue);
                tagged = pCur->uiID | 0x80000000;
                ((StateX*)DAT_011de45c)->FUN_008579b0(&tagged, 4);
                ((StateX*)DAT_011de45c)->FUN_00857a10(&converted, 4);
            }
            else
            {
                ((StateX*)DAT_011de45c)->FUN_008579b0(pCur, 4);
                ((StateX*)DAT_011de45c)->FUN_008579b0(&pCur->fValue, 8);
            }
            written++;
        }
        pList = pList->FUN_00726070();
    }
    *(unsigned short*)posNum = written;
    hasTail = false;
    if (m_pExtendedLocals)
        hasTail = true;
    ((StateX*)DAT_011de45c)->FUN_008579b0(&hasTail, 1);
    if (hasTail)
        ((StateX*)DAT_011de45c)->FUN_008579b0(m_pExtendedLocals, 8);
    if (*DAT_011de4e8.FUN_00408d60())
    {
        curPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
        formPtr = DAT_011de45c->FUN_004fd3e0();
        if (formPtr)
        {
            pFmt = FUN_004839c0(*(void**)formPtr);
            typedef unsigned int(__thiscall * GetItemFn)(Formatter*);
            FUN_0040fbe0("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         curPos - fromPos, *(int*)formPtr, (*(GetItemFn*)(*(char**)pFmt + 0x130))(pFmt),
                         *(int*)((char*)formPtr + 5), 694,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp");
        }
        else
        {
            FUN_0040fbe0("SaveGame(): %-5i ending at line %i in file %s", curPos - fromPos, 694,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp");
        }
    }
    if (DAT_011de45c->FUN_00862110())
    {
        endPos = ((StateX*)DAT_011de45c)->FUN_00825c00();
        posTmp = posB;
        if (endPos > posTmp + 0xffff)
            FUN_005b5e40("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 694);
        *(unsigned short*)posB = (unsigned short)(endPos - posTmp);
    }
}

class BGSSaveFormBuffer_Write : public BGSSaveFormBuffer
{

  public:
    void FUN_00865df0(TESObjectREFR* reference, unsigned int flag);
};

// Writes each of four global TESObjectREFR lists to the save buffer, counting non-null entries and patching each count at its recorded offset.
// @fnv 0x005aa930
void __cdecl WriteReferenceLists(BGSSaveFormBuffer* buffer)

{

    int count1;

    unsigned int offset1;

    BSSimpleList<TESObjectREFR*>* list1;

    {

        TESObjectREFR* item9;

        int count2;

        unsigned int offset6;

        BSSimpleList<TESObjectREFR*>* listVal;

        TESObjectREFR* aItem2;

        int count7;

        unsigned int offsetVal;

        BSSimpleList<TESObjectREFR*>* list9;

        TESObjectREFR* item8;

        int count9;

        {

            unsigned int offset4;

            BSSimpleList<TESObjectREFR*>* list4;

            TESObjectREFR* item6;

            g_011cacf8.QueryPerformanceCounter(0);

            count1 = 0;

            offset1 = buffer->FUN_00865f20();

            list1 = &DAT_011caca8;

            while (list1 != 0)
            {

                item9 = (TESObjectREFR*)*FUN_006815c0(list1);

                if (item9 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(item9, 0);

                    count1 = count1 + 1;
                }

                list1 = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(list1);
            }

            buffer->FUN_00865ff0(count1, offset1);

            count2 = 0;

            offset6 = buffer->FUN_00865f20();

            listVal = &DAT_011cac98;

            while (listVal != 0)
            {

                aItem2 = (TESObjectREFR*)*FUN_006815c0(listVal);

                if (aItem2 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(aItem2, 0);

                    count2 = count2 + 1;
                }

                listVal = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(listVal);
            }

            buffer->FUN_00865ff0(count2, offset6);

            count7 = 0;

            offsetVal = buffer->FUN_00865f20();

            list9 = &DAT_011cacb8;

            while (list9 != 0)
            {

                item8 = (TESObjectREFR*)*FUN_006815c0(list9);

                if (item8 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(item8, 0);

                    count7 = count7 + 1;
                }

                list9 = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(list9);
            }

            buffer->FUN_00865ff0(count7, offsetVal);

            count9 = 0;

            offset4 = buffer->FUN_00865f20();

            list4 = &DAT_011cace8;

            while (list4 != 0)
            {

                item6 = (TESObjectREFR*)*FUN_006815c0(list4);

                if (item6 != 0)
                {

                    ((BGSSaveFormBuffer_Write*)buffer)->FUN_00865df0(item6, 0);

                    count9 = count9 + 1;
                }

                list4 = (BSSimpleList<TESObjectREFR*>*)FUN_00726070(list4);
            }

            buffer->FUN_00865ff0(count9, offset4);
        }
    }

    g_011cacf8.WaitForTasksDuringRendering();
}

int _mbscmp(const unsigned char* a, const unsigned char* b);
unsigned int __cdecl strlen(const char*);

// @fnv 0x005ab240
bool ScriptUnitOperations::IsDifferentFrom(Script* apOther)
{
    unsigned int i8;
    BSSimpleList<ScriptReferencedObject*>* pOtherIter7;
    ScriptHeaderData* pHeader;
    char* pData6;
    BSSimpleList<ScriptReferencedObject*>* kPIter;
    ScriptReferencedObject* pOtherRef8;
    ScriptReferencedObject* pRef;
    if (!apOther)
        return true;
    pHeader = apOther->GetHeader();
    if (m_kHeader.dataSize != pHeader->dataSize)
        return true;
    if (m_kHeader.m_uiReferenceID != pHeader->m_uiReferenceID)
        return true;
    if (m_kHeader.m_bCompiled != pHeader->m_bCompiled)
        return true;
    pData6 = apOther->GetData();
    for (i8 = 0; i8 < m_kHeader.dataSize; i8++)
    {
        if (m_data[i8] != pData6[i8])
            return true;
    }
    if (GetText() && apOther->GetText())
    {
        if (strlen(GetText()) != strlen(apOther->GetText()))
            return true;
        else if (_mbscmp((const unsigned char*)GetText(), (const unsigned char*)apOther->GetText()))
            return true;
    }
    else if (GetText() || apOther->GetText())
        return true;
    pOtherIter7 = apOther->GetReferencedObjectList();
    kPIter = GetReferencedObjectList();
    while (pOtherIter7 && kPIter)
    {
        pRef = kPIter->GetItem();
        pOtherRef8 = pOtherIter7->GetItem();
        if (pOtherRef8 && pRef && pOtherRef8->pForm != pRef->pForm)
            return true;
        pOtherIter7 = pOtherIter7->GetNext();
        kPIter = kPIter->GetNext();
    }
    return false;
}

struct FUN_00501c10_s
{
    void* CallAndReturnSelf(const void* src);
};

namespace ns5a {
}

// @fnv 0x005ab8b0
ScriptReferencedObject::ScriptReferencedObject(ScriptReferencedObject* src)
{
    ((FUN_00501c10_s*)this)->CallAndReturnSelf(src);
    pForm = src->pForm;
    m_uiFormID = src->m_uiFormID;
}

void FUN_005acc70(const unsigned int*, double*);
ScriptFunctionInfo* FUN_005b1120(int);
void FUN_005accb0(const ScriptParameter*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*,
                  ScriptLocals*);
void FUN_00401460(void*, const void*, unsigned int);
// @fnv 0x005ac7a0
bool ReadScriptValue(double* value, const char* data, unsigned int* offset, TESObjectREFR* reference,
                     TESObjectREFR* container, Script* script, ScriptLocals* locals, bool skip)
{
    ScriptLocals* a;
    ScriptReferencedObject* p;
    char h;
    short i;
    TESQuest* s;
    TESObjectREFR* f;
    TESObjectREFR* eb;
    InventoryStackRecord* cf;
    ScriptFunctionInfo* q;
    int b;
    TESObjectREFR* ba;
    ScriptParameter* k;
    FNVScriptExecuteFunction l;
    short c;
    unsigned int e;
    a = locals;
    if (!a)
        return false;
    p = 0;
    if (skip && script->IsFormInitialized())
        skip = false;
    h = data[*offset];
    *offset += 1;
    switch (h)
    {
    case 'G':
    case 'Z':
    case 'r': {
        i = *(short*)(data + *offset);
        *offset += 2;
        p = script->GetReferencedForm(i, locals);
        if (p)
        {
            if (p->pForm || skip)
            {
                if (h == 'G')
                {
                    *value = ((TESGlobalValueReader*)p->pForm)->GetValue();
                    return true;
                }
                else if (h == 'Z')
                {
                    e = p->pForm->GetFormID();
                    FUN_005acc70(&e, value);
                    return true;
                }
                else
                {
                    h = data[*offset];
                    *offset += 1;
                    if (h != 'X')
                    {
                        s = 0;
                        if (p->pForm && p->pForm->GetFormType() == 0x47)
                            s = (TESQuest*)p->pForm;
                        if (s)
                            a = s->GetScriptLocalData();
                        else
                        {
                            f = 0;
                            if (p->pForm)
                            {
                                switch (p->pForm->GetFormType())
                                {
                                case 0x3a:
                                case 0x3b:
                                case 0x3c:
                                case 0x3d:
                                case 0x3e:
                                case 0x3f:
                                case 0x40:
                                case 0x69:
                                    f = (TESObjectREFR*)p->pForm;
                                    break;
                                }
                            }
                            if (f)
                            {
                                if (f->GetExtraData()->GetReplacementReference())
                                {
                                    eb = f->GetExtraData()->GetReplacementReference();
                                    cf = eb->FindEntryForObject(f->GetObjectReference(), f->GetFormID());
                                    if (cf)
                                        a = cf->GetScriptLocalData();
                                    delete cf;
                                }
                                else
                                    a = f->GetReferenceLocals();
                            }
                        }
                        if (!a)
                            return false;
                    }
                }
            }
            else
            {
                if (p->m_uiFormID)
                {
                    *value = 0.0;
                    return true;
                }
                else
                    return false;
            }
        }
        else
            return false;
        break;
    }
    case 'n':
        *value = *(int*)(data + *offset);
        *offset += 4;
        return true;
    case 'z':
        FUN_00401460(value, data + *offset, 8);
        *offset += 8;
        return true;
    }
    if (h == 'X')
    {
        b = *(short*)(data + *offset);
        *offset += 2;
        *offset += 2;
        q = FUN_005b1120(b);
        if (!q)
            return false;
        else
        {
            ba = (TESObjectREFR*)reference;
            if (p && p->pForm)
            {
                ba = 0;
                if (p->pForm)
                {
                    switch (p->pForm->GetFormType())
                    {
                    case 0x3a:
                    case 0x3b:
                    case 0x3c:
                    case 0x3d:
                    case 0x3e:
                    case 0x3f:
                    case 0x40:
                    case 0x69:
                        ba = (TESObjectREFR*)p->pForm;
                        break;
                    }
                }
            }
            k = q->pParameters;
            if (skip)
            {
                if (k)
                    FUN_005accb0(k, data, offset, ba, container, script, locals);
            }
            else
            {
                if (!q->m_bRequiresReference || (q->m_bRequiresReference && ba))
                {
                    l = q->m_pfnExecute;
                    if (l && l(k, data, ba, container, script, locals, *value, *offset))
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    else
    {
        c = *(short*)(data + *offset);
        *offset += 2;
        switch (h)
        {
        case 'f':
        case 'l':
        case 's':
            *value = a->GetVariable(c, script);
            return true;
        default:
            return false;
        }
    }
    return false;
}

struct ExtractParameter
{
    const char* name;
    unsigned int type;
    bool optional;
};
bool FUN_00481f30(int);
extern const char extractUnimplemented[];
bool ReadScriptValue(double*, const char*, unsigned int*, TESObjectREFR*, TESObjectREFR*, Script*, ScriptLocals*,
                     bool);
// @fnv 0x005accb0
bool __cdecl FUN_005accb0(const ExtractParameter* parameters, const char* data, unsigned int* offset,
                          TESObjectREFR* reference, TESObjectREFR* container, Script* script,
                          ScriptLocals* locals, ...)
{
    if (!parameters)
        return false;
    va_list args2;
    va_start(args2, locals);
    short count = *reinterpret_cast<const short*>(data + *offset);
    *offset += 2;
    short index;
    for (index = 0; index < count; ++index)
    {
        if (DAT_0118cdd0[parameters[index].type].isReference)
        {
            if (data[(*offset)++] != 'r')
                return false;
            short refIndex3 = *reinterpret_cast<const short*>(data + *offset);
            *offset += 2;
            ScriptReferencedObject* ref = script->GetReferencedForm(refIndex3, locals);
            if (script->IsFormInitialized() && ref && ref->pForm)
            {
                bool valid = false;
                switch (parameters[index].type)
                {
                case 3: {
                    if (FUN_00481f30(ref->pForm->GetFormType()))
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = 0;
                        if (ref->pForm && ref->pForm->IsBoundObject())
                            *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 50: {
                    if (FUN_00481f30(ref->pForm->GetFormType()) ||
                        ref->pForm->GetFormType() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 53: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm && (ref->pForm->IsBoundObject() ||
                                       ref->pForm->GetFormType() == 85))
                        *formOutput = ref->pForm;
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 4:
                case 24:
                case 26: {
                    switch (ref->pForm->GetFormType())
                    {
                    case 58:
                    case 59:
                    case 60:
                    case 61:
                    case 62:
                    case 63:
                    case 64:
                    case 105: {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = 0;
                        if (ref->pForm)
                        {
                            switch (ref->pForm->GetFormType())
                            {
                            case 58:
                            case 59:
                            case 60:
                            case 61:
                            case 62:
                            case 63:
                            case 64:
                            case 105:
                                *formOutput = ref->pForm;
                                break;
                            }
                        }
                        if (*formOutput)
                            valid = true;
                    }
                    break;
                    }
                }
                break;
                case 6: {
                    switch (ref->pForm->GetFormType())
                    {
                    case 59:
                    case 60: {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                    break;
                    }
                }
                break;
                case 9: {
                    if (ref->pForm->GetFormType() == 57)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 27: {
                    if (ref->pForm->GetFormType() == 65)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 7: {
                    SpellItem** spellOutput = va_arg(args2, SpellItem**);
                    *spellOutput = dynamic_cast<SpellItem*>(ref->pForm);
                    if (*spellOutput)
                        valid = true;
                    else
                    {
                        TESObjectBOOK* book = 0;
                        if (ref->pForm && ref->pForm->GetFormType() == 25)
                            book = reinterpret_cast<TESObjectBOOK*>(ref->pForm);
                        *spellOutput = reinterpret_cast<SpellItem*>(book);
                        if (book && book->FindFormEnchantment())
                            valid = true;
                    }
                }
                break;
                case 11: {
                    MagicItem** formOutput = va_arg(args2, MagicItem**);
                    *formOutput = dynamic_cast<MagicItem*>(ref->pForm);
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 31: {
                    EffectSetting** formOutput = va_arg(args2, EffectSetting**);
                    *formOutput = dynamic_cast<EffectSetting*>(ref->pForm);
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 12: {
                    if (ref->pForm->GetFormType() == 13)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 54: {
                    if (ref->pForm->GetFormType() == 102)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 13: {
                    if (ref->pForm->GetFormType() == 69)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 14: {
                    if (ref->pForm->GetFormType() == 71)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 15: {
                    if (ref->pForm->GetFormType() == 12)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 47: {
                    if (ref->pForm->GetFormType() == 97)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 16: {
                    if (ref->pForm->GetFormType() == 7)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 17: {
                    if (ref->pForm->GetFormType() == 8)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 62: {
                    if (ref->pForm->GetFormType() == 104)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 65: {
                    if (ref->pForm->GetFormType() == 113)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 63: {
                    if (ref->pForm->GetFormType() == 109)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 64: {
                    if (ref->pForm->GetFormType() == 108)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 66: {
                    if (ref->pForm->GetFormType() == 116)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 67: {
                    if (ref->pForm->GetFormType() == 115)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 68: {
                    if (ref->pForm->GetFormType() == 117)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 69: {
                    if (ref->pForm->GetFormType() == 55)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 19: {
                    if (ref->pForm->GetFormType() == 6)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 20: {
                    if (ref->pForm->GetFormType() == 39 ||
                        ref->pForm->GetFormType() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 21: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm && ref->pForm->IsBoundObject())
                        *formOutput = ref->pForm;
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 25: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (ref->pForm->GetFormType())
                        {
                        case 42:
                        case 43:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 29: {
                    if (ref->pForm->GetFormType() == 73)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 30: {
                    if (ref->pForm->GetFormType() == 74)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 33: {
                    if (ref->pForm->GetFormType() == 53)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 42: {
                    if (ref->pForm->GetFormType() == 84)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 43: {
                    if (ref->pForm->GetFormType() == 83)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 34: {
                    if (ref->pForm->GetFormType() == 42)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 35: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (ref->pForm->GetFormType())
                        {
                        case 42:
                            *formOutput = ref->pForm;
                            break;
                        case 8:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 36: {
                    if (ref->pForm->GetFormType() == 79)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 37: {
                    if (ref->pForm->GetFormType() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 38: {
                    if (ref->pForm->GetFormType() == 5)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 39: {
                    if (ref->pForm->GetFormType() == 86)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 40: {
                    if (ref->pForm->GetFormType() == 49)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 49: {
                    if (ref->pForm->GetFormType() == 98)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 56: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (ref->pForm->GetFormType())
                        {
                        case 42:
                            *formOutput = ref->pForm;
                            break;
                        case 45:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 57: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (ref->pForm->GetFormType())
                        {
                        case 43:
                            *formOutput = ref->pForm;
                            break;
                        case 44:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 58: {
                    if (ref->pForm->GetFormType() == 45)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 59: {
                    if (ref->pForm->GetFormType() == 44)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 60: {
                    if (ref->pForm->GetFormType() == 52)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 61: {
                    if (ref->pForm)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                default:
                    Warning(extractUnimplemented, parameters[index].type);
                    return false;
                }
                if (!valid)
                    return false;
            }
            else
                return false;
        }
        else
        {
            switch (parameters[index].type)
            {
            case 0: {
                short length = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->IsFormInitialized())
                {
                    char* textOutput = va_arg(args2, char*);
                    memcpy(textOutput, data + *offset, length);
                    textOutput[length] = 0;
                }
                *offset += length;
            }
            break;
            case 1:
            case 23: {
                double value = 0.0;
                if (ReadScriptValue(&value, data, offset, reference, container, script, locals, true))
                {
                    if (script->IsFormInitialized())
                    {
                        int* intOutput = va_arg(args2, int*);
                        *intOutput = (int)value;
                    }
                }
                else
                    return false;
            }
            break;
            case 2: {
                double value = 0.0;
                if (ReadScriptValue(&value, data, offset, reference, container, script, locals, true))
                {
                    if (script->IsFormInitialized())
                    {
                        float* floatOutput = va_arg(args2, float*);
                        *floatOutput = (float)value;
                    }
                }
                else
                    return false;
            }
            break;
            case 8: {
                if (script->IsFormInitialized())
                {
                    char* byteOutput = va_arg(args2, char*);
                    *byteOutput = data[*offset];
                }
                *offset += 1;
            }
            break;
            case 5:
            case 41:
            case 51:
            case 52:
            case 55: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->IsFormInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 28: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->IsFormInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 10: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->IsFormInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 32: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->IsFormInitialized())
                {
                    char* byteOutput = va_arg(args2, char*);
                    *byteOutput = (char)value;
                }
            }
            break;
            case 18: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (script->IsFormInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            default:
                return false;
            }
        }
    }
    va_end(args2);
    return true;
}

void __cdecl FNV_Warning(const char* fmt, ...);
extern int DAT_011cad40;
extern float DAT_011cad20[8];

struct S4eb0_list
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    ScriptReferencedObject** FUN_006815c0();
    S4eb0_list* FUN_00726070();
    void FUN_00905330(ScriptReferencedObject** p);
};

void ResolveFormID(TESForm** form, TESFile* file);
TESForm* FUN_004839c0(TESForm* form);

// @fnv 0x005ab400
void Script::InitItem(TESForm* form)
{
    if (IsFormInitialized() || form == 0)
        return;
    AutoMemContext saveCtx((MEM_CONTEXT)21, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 0xab5);
    if (form != this && IsTemporary())
    {
        SetFile(form->GetFile(-1));
    }
    int num = 0;
    S4eb0_list* iter = (S4eb0_list*)GetReferencedObjectList();
    S4eb0_list* pPrev = 0;
    TESFile* pTemp = form ? form->GetFile(-1) : 0;
    while (iter && !iter->FUN_008256d0())
    {
        ScriptReferencedObject* refTmp = *iter->FUN_006815c0();
        TESForm* form7 = refTmp->pForm;
        unsigned int idB = refTmp->m_uiFormID;
        bool ok3 = false;
        if (form7)
        {
            ResolveFormID(&form7, pTemp);
            refTmp->pForm = FUN_004839c0(form7);
            if (refTmp->pForm)
                ok3 = true;
        }
        else if (idB)
        {
            ok3 = true;
        }
        if (ok3)
        {
            pPrev = iter;
            iter = iter->FUN_00726070();
        }
        else
        {
            if (pPrev)
            {
                pPrev->FUN_00905330(iter->FUN_006815c0());
                iter = pPrev->FUN_00726070();
            }
            else
            {
                iter->FUN_0063f7b0();
            }
            if (form7)
            {
                FNV_Warning(
                    "MASTERFILE: Could not find referenced object (%08X) on Script (%08X) '%s'.  Script will not be executed.",
                    form7, GetFormID(), GetName());
            }
            else
            {
                FNV_Warning(
                    "MASTERFILE: Referenced object %d on Script (%08X) '%s' is invalid.  Script will not be executed.",
                    num, GetFormID(), GetName());
            }
            m_kHeader.dataSize = 0;
        }
        num++;
    }
    if (num != m_kHeader.m_uiReferenceID && m_kHeader.dataSize != 0)
    {
        FNV_Warning(
            "MASTERFILE: Referenced object list on Script (%08X) '%s' is corrupt.  Expected %d objects, found %d.",
            GetFormID(), GetName(), m_kHeader.m_uiReferenceID, num);
        m_kHeader.dataSize = 0;
    }
    if (m_data)
        TESForm::ClearData();
    if (GetHeader()->m_bQuest)
    {
        if (DAT_011cac68.Float()->f > 0.0)
        {
            float t = DAT_011cac68.Float()->f;
            if (DAT_011cad40 == 0)
            {
                for (int j = 0; j < 8; j++)
                {
                    t = t / 2.0;
                    DAT_011cad20[j] = t;
                }
            }
            int mask3 = DAT_011cad40 & 0xff;
            int k = 0;
            if (m_pOwnerQuest != 0 && m_pOwnerQuest->FUN_00792760() > 0.0)
            {
                fValueAtOffset38 = 0.0f;
            }
            else if (mask3 == 0)
            {
                fValueAtOffset38 = DAT_011cac68.Float()->f;
            }
            else
            {
                while (mask3)
                {
                    if (mask3 & 1)
                        fValueAtOffset38 += DAT_011cad20[k];
                    k++;
                    mask3 >>= 1;
                }
            }
            DAT_011cad40++;
        }
    }
    if (form->GetFormType() == 0x47)
        m_pOwnerQuest = (TESQuest*)form;
    SetInitializationState(true);
}

extern const char DAT_01015588[];
struct SavedFormHeader
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flagsLow, flagsByte1, flagsByte2, flagsByte3;
    unsigned char version;
};
struct ScriptSaveReader : TESSaveLoadGame
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    void FUN_00857aa0(unsigned int*, unsigned int);
    SavedFormHeader* FUN_004fd3c0();
    unsigned int FUN_00825c00();
    unsigned char FUN_008df040();
};
TESForm* __cdecl _ref_004839c0(unsigned int);
void __cdecl FUN_005acc70(const unsigned int&, double&);
// Reads script locals from the save stream, handling version 117+ reference encoding and optional extended locals, then verifies the block size.
// @fnv 0x005a9950
void ScriptLocals::LoadGame()
{
    unsigned short a = 0;
    unsigned int i = 0;
    unsigned short s;
    unsigned char h;
    int p;
    if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int blockTag;
        ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&blockTag, 4);
        if (blockTag != 0x424c4f4b)
        {
            SavedFormHeader* header = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_004fd3c0();
            if (header)
            {
                TESForm* form = _ref_004839c0(header->formID);
                Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    &DAT_01036d58, 700, header->formID, form->GetName(), header->version,
                    *(unsigned int*)&header->flagsLow);
            }
            else
            {
                Warning(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    &DAT_01036d58, 700, ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040());
            }
        }
        i = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00825c00();
        ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&a, 2);
    }
    ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&s, 2);
    for (p = 0; p < s; p++)
    {
        unsigned int i = 0;
        double p = 0.0;
        if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040() >= 117)
        {
            ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&i, 4);
            if (i & 0x80000000)
            {
                i &= 0x7fffffff;
                unsigned int refID;
                ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00857aa0(&refID, 4);
                FUN_005acc70(refID, p);
            }
            else
            {
                ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&p, 8);
            }
        }
        if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040() < 117)
        {
            ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&i, 4);
            ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&p, 8);
        }
        SetVariable(i, p);
    }
    ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(&h, 1);
    if (h)
    {
        m_pExtendedLocals = (ScriptDefinition*)new double;
        ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008579e0(m_pExtendedLocals, 8);
    }
    if (((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00862110())
    {
        unsigned int s = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_00825c00();
        SavedFormHeader* h = ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_004fd3c0();
        if (h)
        {
            TESForm* form = _ref_004839c0(h->formID);
            if (s > i + a)
                Warning(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    s - (i + a), &DAT_01036d58, 747, h->formID, form->GetName(), h->version,
                    *(unsigned int*)&h->flagsLow);
            else if (s < i + a)
                Warning(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    i + a - s, &DAT_01036d58, 747, h->formID, form->GetName(), h->version,
                    *(unsigned int*)&h->flagsLow);
        }
        else
        {
            if (s > i + a)
                Warning("SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                        s - (i + a), &DAT_01036d58, 747, ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040());
            else if (s < i + a)
                Warning("SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                        i + a - s, &DAT_01036d58, 747, ((ScriptSaveReader*)g_TESSaveLoadGame)->FUN_008df040());
        }
    }
}

// The shared reference type does not declare the flag-taking disposal entry.
// This adapter adds no data and uses the shared string destructor.
struct ScriptReferenceOperations : ScriptReferencedObject
{
    void* DestroyAndFree(unsigned int flags);
};

// @fnv 0x005aa3f0
void* ScriptReferenceOperations::DestroyAndFree(unsigned int flags)
{
    ScriptReferencedObject::~ScriptReferencedObject();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_005aa350 {
struct TlsSlot
{
    char pad[0x24F0];
    void* pCached;
};

struct ListX
{
    bool FUN_008256d0();
    ScriptReferenceOperations** FUN_006815c0();
    void FUN_0063f7b0();
};

extern __declspec(thread) TlsSlot DAT_0126fd98;

} // namespace fnv_005aa350

// Clears the TLS cached pointer if it points to this object, then iterates the list from FUN_005d43c0 and calls FUN_005aa3f0(1) on each item.
// @fnv 0x005aa350
void Script::InitializeActionList()
{
    using namespace fnv_005aa350;
    if (DAT_0126fd98.pCached == this)
        DAT_0126fd98.pCached = 0;
    ListX* pList = (ListX*)GetReferencedObjectList();
    while (pList != 0 && !pList->FUN_008256d0())
    {
        ScriptReferenceOperations* b = *pList->FUN_006815c0();
        ScriptReferenceOperations* pItem = b;
        // the result is discarded but stays in an implicit temp (VM /Od slot layout)
        (void)(pItem ? pItem->DestroyAndFree(1) : 0);
        pList->FUN_0063f7b0();
    }
}
