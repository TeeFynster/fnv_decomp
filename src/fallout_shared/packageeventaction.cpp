// fallout_shared/packageeventaction.cpp: PackageEventActionData_packageeventaction (7 functions)

#include "../../include/BSStringT.h"

// PackageEventActionData_packageeventaction: local type (was include/PackageEventActionData.h, which had no evidence of one real class); its methods are 0x0067da80 PackageEventAction::~PackageEventAction, 0x0067dad0 PackageEventAction::Copy, 0x0067dbf0 PackageEventAction::Compare, 0x0067dc80 TESPackageOnBeginEndOrChange_Save
class TESIdleForm;
class Script;
class TESTopic;
class TESForm;
class TESFile;
enum PACK_EVENT_ACTION_TYPE;

class PackageEventActionData_packageeventaction
{
public:
    TESIdleForm* m_pIdleForm;
    Script* m_pScript;
    TESTopic* pTopic;
    PACK_EVENT_ACTION_TYPE eType;

    PackageEventActionData_packageeventaction();
    void Clear();
    void CopyFrom(PackageEventActionData_packageeventaction* apCopy);
    bool IsDifferentFrom(PackageEventActionData_packageeventaction* apParam);
    void Save(int aeChunk);
    void* GetScript();
    void InitItem(TESForm* owner);
    void InitItem(int item);
    void Load(TESFile* file);
};
#include "../../include/BSSimpleList.h"
#include "../../include/TESObjectREFR.h"

#include "../../include/TESObjectANIO.h"
#include "../../include/TESTopic.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/Script.h"
#include "../../include/ScriptVariableInfo.h"
#include "../../include/ScriptReferencedObject.h"
#include "../../include/TESFile.h"
#include "../../include/MagicCaster.h"
#include "../../include/GO.h"
#include <malloc.h>
#include <string.h>

int Warning();
int Warning(const char*, ...);
unsigned int SetWarningState(bool);
void BGSMessageWarningAuxiliary(int);
TESForm* GetFormByID(unsigned int);
extern ScriptVariableInfo* DAT_011d66ac;

// @fnv 0x00680890
PackageEventActionData_packageeventaction::PackageEventActionData_packageeventaction()
{
    // The original initializes the two leading pointers through this list constructor.
    reinterpret_cast<BSSimpleList<TESForm*>*>(this)->BSSimpleList<TESForm*>::BSSimpleList();
}

// @fnv 0x0067e190
void PackageEventActionData_packageeventaction::InitItem(TESForm* owner)
{
    unsigned int id = (unsigned int)m_pIdleForm;
    TESForm::RemapFormIDForFile(id, owner->GetFile(-1));
    TESObjectANIO* idle = dynamic_cast<TESObjectANIO*>(GetFormByID(id));
    if (idle)
        m_pIdleForm = reinterpret_cast<TESIdleForm*>(idle);
    else if (id)
    {
        if (((BGSCameraPath*)owner)->HasNameForWarning())
            Warning("MASTERFILE: Unable to find Idle (%08X) on owner object \"%s\".", id, owner->GetName());
        else
            Warning("MASTERFILE: Unable to find Idle (%08X) on owner object (%08X).", id, owner->GetFormID());
        m_pIdleForm = 0;
    }
    id = (unsigned int)pTopic;
    TESForm::RemapFormIDForFile(id, owner->GetFile(-1));
    TESTopic* topic = dynamic_cast<TESTopic*>(GetFormByID(id));
    if (topic)
        pTopic = topic;
    else if (id)
    {
        if (((BGSCameraPath*)owner)->HasNameForWarning())
            Warning("MASTERFILE: Unable to find Topic (%08X) on owner object \"%s\".", id, owner->GetName());
        else
            Warning("MASTERFILE: Unable to find Topic (%08X) on owner object (%08X).", id, owner->GetFormID());
        pTopic = 0;
    }
    if (m_pScript)
    {
        int errors;
        int oldWarning = Warning();
        SetWarningState(true);
        BGSMessageWarningAuxiliary(0);
        ((Script*)m_pScript)->NotifySaveLoadGameOfFormChange();
        ((Script*)m_pScript)->InitItem(owner);
        ((Script*)m_pScript)->GetHeader()->m_bQuest = false;
        SetWarningState(false);
        errors = Warning();
        BGSMessageWarningAuxiliary(oldWarning);
        if (errors)
            Warning("MASTERFILE: Errors were encountered during InitItem for result script on eventaction for package",
                    owner->GetName(), owner->GetFormID());
    }
}

// Loads a Script from a TESFile: reads variable, condition, data, reference and item/topic chunks, then discards the script if it has no data.
// @fnv 0x0067dd20
void PackageEventActionData_packageeventaction::Load(TESFile* file)
{
    unsigned int id;
    m_pIdleForm = 0;
    pTopic = 0;
    if (m_pScript)
    {
        delete (Script*)m_pScript;
        m_pScript = 0;
    }
    m_pScript = new Script;
    for (;;)
    {
        bool done = false;
        switch ((int)file->GetChunkID())
        {
        case 0x44534c53:
        case 0x52564353:
            if (file->GetChunkID() == 0x44534c53)
            {
                DAT_011d66ac = new ScriptVariableInfo;
                DAT_011d66ac->Load(file);
                ((Script*)m_pScript)->GetVariableList()->AddTail(DAT_011d66ac);
            }
            else if (DAT_011d66ac)
            {
                char* name = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(name, 512);
                DAT_011d66ac->name.Set(name, 0);
            }
            break;
        case 0x52484353:
            file->GetChunkData(((Script*)m_pScript)->GetHeader(), 0);
            if (file->IsEndianConversionRequired())
                ((Script*)m_pScript)->GetHeader()->Endian();
            break;
        case 0x41444353: {
            unsigned int size = file->GetChunkSize();
            char* data = (char*)_alloca(size);
            memset(data, 0, size);
            file->GetChunkData(data, 0);
            ((Script*)m_pScript)->SetScriptData(size, data);
            break;
        }
        case 0x4f524353: {
            unsigned int formID;
            ScriptReferencedObject* object = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            object->pForm = (TESForm*)formID;
            ((Script*)m_pScript)->GetReferencedObjectList()->AddTail(object);
            break;
        }
        case 0x56524353: {
            unsigned int formID;
            ScriptReferencedObject* object = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            object->m_uiFormID = formID;
            ((Script*)m_pScript)->GetReferencedObjectList()->AddTail(object);
            break;
        }
        break;
        case 0x4d414e49:
            file->GetChunkData(&id);
            m_pIdleForm = (TESIdleForm*)id;
            break;
        case 0x4d414e54:
            file->GetChunkData(&id);
            pTopic = (TESTopic*)id;
            done = true;
            break;
        }
        if (done)
            break;
        file->NextChunk();
    }
    ((Script*)m_pScript)->SetInitializationState(false);
    if (!((Script*)m_pScript)->GetData())
    {
        delete (Script*)m_pScript;
        m_pScript = 0;
    }
}

// @fnv 0x0067da80
void PackageEventActionData_packageeventaction::Clear()
{
    *(int*)this = 0;
    *((int*)this + 2) = 0;
    delete *((Script**)this + 1);
}

extern "C" void TESForm_AddChunk(int);
extern "C" void TESForm_AddChunk_00485910(int, int);
// These operations are not declared by the shared Script header yet.
// This adapter supplies only the missing methods, with no copied Script layout.
struct PackageEventScriptMethods
{
    void ProcessHeader();
    bool IsDifferentFrom(void*);
};
// @fnv 0x0067dc80
void PackageEventActionData_packageeventaction::Save(int aeChunk)
{
    TESForm_AddChunk(aeChunk);
    unsigned int iid = m_pIdleForm ? ((TESForm*)m_pIdleForm)->GetFormID() : 0;
    TESForm_AddChunk_00485910(0x4d414e49, iid);
    iid = pTopic ? pTopic->GetFormID() : 0;
    if (m_pScript)
        ((PackageEventScriptMethods*)m_pScript)->ProcessHeader();
    TESForm_AddChunk_00485910(0x4d414e54, iid);
}

struct QuantityData
{
    void SetQuantity(unsigned int);
};

void* __cdecl operator new(unsigned int);

// Copies quantity, flags and form ID from apCopy, then clones or clears the script pointer depending on whether apCopy has one.
// @fnv 0x0067dad0
void PackageEventActionData_packageeventaction::CopyFrom(PackageEventActionData_packageeventaction* apCopy)
{
    reinterpret_cast<QuantityData*>(this)->SetQuantity(reinterpret_cast<const GO*>(apCopy)->operator unsigned int());

    reinterpret_cast<TESObjectREFR*>(this)->SetFlags(reinterpret_cast<TESObjectREFR*>(apCopy)->GetFlags());

    reinterpret_cast<MagicCaster*>(this)->SetSelectedMagicItem(reinterpret_cast<TESForm*>(apCopy)->GetFormID());

    if (apCopy->m_pScript)
    {
        if (!m_pScript)
        {
            m_pScript = new Script;
            ((Script*)m_pScript)->NotifySaveLoadGameOfFormChange();
        }
        ((Script*)m_pScript)->CopyScriptContents((Script*)apCopy->m_pScript);
    }
    else
    {
        delete (Script*)m_pScript;
        m_pScript = 0;
    }
}

// @fnv 0x0067dbf0
bool PackageEventActionData_packageeventaction::IsDifferentFrom(PackageEventActionData_packageeventaction* apParam)
{
    if ((int)m_pIdleForm != (int)reinterpret_cast<const GO*>(apParam)->operator unsigned int())
        return true;
    if ((int)pTopic != reinterpret_cast<TESObjectREFR*>(apParam)->GetFlags())
        return true;
    if ((void*)m_pScript || apParam->GetScript())
    {
        if (!(void*)m_pScript || !apParam->GetScript())
            return true;
        if (((PackageEventScriptMethods*)m_pScript)->IsDifferentFrom(apParam->GetScript()))
            return true;
    }
    return false;
}
