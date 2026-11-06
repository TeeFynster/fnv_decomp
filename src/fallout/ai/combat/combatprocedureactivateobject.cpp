// fallout/ai/combat/combatprocedureactivateobject.cpp: CombatProcedureActivateObject, CombatProcedure, ScriptableFormForward and more (14 functions)

#include "../../../../include/Actor.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/CombatProcedure.h"
#include "../../../../include/CombatProcedureActivateObject.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TESBoundObject.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESScriptableForm.h"

// @fnv 0x006ecd40
void CombatProcedure::Initialize(CombatController* apCombatController)
{
    ((CombatController**)this)[1] = apCombatController;
}

// @fnv 0x006e4ba0
int CombatProcedureActivateObject::FUN_006e4ba0()
{
    return 8;
}

struct TESObjectREFRHelper
{
    void SetTargetingState(int);
};
// Stores both pointers, sets m_cValue24 to zero, and calls SetTargetingState(1) when m_pReference is non-null.
// @fnv 0x009ca5f0
CombatProcedureActivateObject::CombatProcedureActivateObject(TESObjectREFR* apTargetRef, TESBoundObject* apBoundObject)
{
    m_pReference = apTargetRef;
    m_pBaseObject = apBoundObject;
    m_cValue24 = 0;
    if (m_pReference)
        ((TESObjectREFRHelper*)m_pReference)->SetTargetingState(1);
}

// @fnv 0x009ca740
CombatProcedureActivateObject::~CombatProcedureActivateObject()
{
}

#include <string.h>
#include <stdlib.h>
#include "../../../../include/BGSLoadGameBuffer.h"
class S_BaseProcess;
class S_Idle;
class S_HY;
class S_FileEntry;
class S_FileSub;
class S_Tile;
class S_TileProv;


class S_BaseProcess
{
  public:
    int GetProcessLevel();
    bool FUN_008ff0b0(Actor* actor, unsigned int refid, void* target);
};

class S_FileSub
{
  public:
    virtual const char* v0();
    virtual const char* v1();
    virtual const char* v2();
    virtual const char* v3();
    virtual const char* v4();
    virtual const char* v5();
};

class S_FileEntry
{
  public:
    char pad[0x18];
    S_FileSub sub;
};

class S_Idle
{
  public:
    bool FUN_004985f0();
    bool HasIdleForm(void* form);
    bool FUN_00498f80();
    S_FileEntry* GetFileEntry();
    S_HY* FUN_00921e30();
    float FUN_00453700();
};

class S_HY
{
  public:
    float FUN_004eec60(float v);
};

class S_Tile
{
  public:
    void* GetActionAtIndex(int i);
    void FUN_0099a780(int obj);
    void EvaluateWeaponScores();
};

class S_TileProv
{
  public:
    S_Tile* FUN_00586150();
};

class S_REFR
{
  public:
    unsigned int GetRefID();
    int FUN_00575610(int obj);
    bool Activate(Actor* actor, bool a2, void* bound, int count);
};

struct CombatProcedureActorAccess
{
    Actor* GetActor();
};

// Checks the target and actor idle state, updates status, activates the target reference, and may evaluate weapon scores.
// @fnv 0x009ca760
void CombatProcedureActivateObject::FUN_009ca760()
{
    if (((S_REFR*)this->m_pReference) == 0)
    {
        this->FUN_009caac0("Targeted reference is NULL for some reason");
        return;
    }
    Actor* actor = ((CombatProcedureActorAccess*)this)->GetActor();
    S_Idle* idle = (S_Idle*)actor->GetAnimData();
    if (((S_BaseProcess*)actor->GetProcess())->GetProcessLevel() == 0 && idle != 0)
    {
        if (this->status == 0)
        {
            if (idle && (!idle->FUN_004985f0() || idle->HasIdleForm(0)))
                return;
            S_BaseProcess* proc = (S_BaseProcess*)actor->GetProcess();
            bool ok = proc->FUN_008ff0b0(actor, ((S_REFR*)this->m_pReference)->GetRefID(), ((S_REFR*)this->m_pReference));
            if (ok)
            {
                this->status = 1;
                return;
            }
            else
            {
                this->status = -1;
            }
        }
        else if (this->status == 1 || this->status == 3)
        {
            if (idle && (!idle->FUN_004985f0() || idle->FUN_00498f80()))
            {
                if (this->status == 1)
                {
                    S_FileEntry* fe = idle->GetFileEntry();
                    if (fe)
                    {
                        const char* str = fe->sub.v5();
                        if (str)
                        {
                            S_HY* hy;
                            float val = 0.0f;
                            const char* b = strrchr(str, '_');
                            if (b)
                                val = (float)atof(b + 1);
                            hy = idle->FUN_00921e30();
                            if (!hy || val < hy->FUN_004eec60(idle->FUN_00453700()))
                                this->status = 2;
                        }
                    }
                }
                if (this->status != 2)
                    return;
            }
        }
    }
    if (this->status != 3)
    {
        S_Tile* tile = ((S_TileProv*)this->m_pCombatController)->FUN_00586150();
        if (((S_REFR*)this->m_pReference)->GetRefID() != (unsigned int)this->m_pBaseObject)
        {
            unsigned int cnt;
            int arr[5];
            memset(arr, 0, sizeof(arr));
            cnt = 0;
            for (unsigned int i = 0; i < 5; i++)
            {
                int* item = (int*)tile->GetActionAtIndex(i);
                if (item && *item == (int)((S_REFR*)this->m_pReference))
                {
                    arr[cnt] = item[1];
                    cnt++;
                }
            }
            tile->FUN_0099a780((int)((S_REFR*)this->m_pReference));
            for (unsigned int j = 0; j < cnt; j++)
            {
                int c = ((S_REFR*)this->m_pReference)->FUN_00575610(arr[j]);
                if (c)
                {
                    if (c < 0)
                        c = -c;
                    ((S_REFR*)this->m_pReference)->Activate(actor, 1, (void*)arr[j], c);
                }
            }
        }
        else
        {
            tile->FUN_0099a780((int)((S_REFR*)this->m_pReference));
            ((S_REFR*)this->m_pReference)->Activate(actor, 1, 0, 1);
        }
        if (!actor->FUN_00493bb0())
            return;
        tile->EvaluateWeaponScores();
    }
    if (this->status == 2)
    {
        this->status = 3;
        return;
    }
    this->SetState();
}

// @fnv 0x009caac0
void __thiscall CombatProcedureActivateObject::FUN_009caac0(int arg1)
{
    ((int*)this)[3] = arg1;
    ((int*)this)[2] = 1;
}

// @fnv 0x009caae0
void CombatProcedureActivateObject::SetState()
{
    ((int*)this)[2] = 2;
}

// If m_pReference matches apRef, clears it and passes a message string to FUN_009caac0.
// @fnv 0x009cab00
void CombatProcedureActivateObject::FUN_009cab00(TESObjectREFR* apRef)
{
    if (m_pReference == apRef)
    {
        m_pReference = 0;
        FUN_009caac0((int)"Targeted reference pointer was cleared");
    }
}

struct FUN_009cab30_TextOutput
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Print(int aiX, int aiY, const char* apFormat, ...);
};
// The shared class has no debug-print declaration; this extension uses its layout.
struct ActivateObjectDebugView : CombatProcedureActivateObject
{
    void PrintDebug(FUN_009cab30_TextOutput* apOutput, int aiX, int aiY);
};
// Prints the current animation state and, if m_pReference is set, its name, form ID, and position to apOutput at aiX, aiY.
// @fnv 0x009cab30
void ActivateObjectDebugView::PrintDebug(FUN_009cab30_TextOutput* apOutput, int aiX, int aiY)
{
    switch (cAnimState)
    {
    case -1:
        apOutput->Print(aiX, aiY, "NO ANIM");
        break;
    case 1:
        apOutput->Print(aiX, aiY, "ANIM PLAYING");
        break;
    case 2:
        apOutput->Print(aiX, aiY, "ANIM GRABBING");
        break;
    case 3:
        apOutput->Print(aiX, aiY, "ANIM FINISHING PLAYING");
        break;
    }
    if (m_pReference)
    {
        NiPoint3 kPos = *static_cast<const TESObjectREFR*>(m_pReference)->GetPos();
        apOutput->Print(aiX, aiY, "Target: '%s' (%08X) - Position: (%.02f,%.02f,%.02f)",
                        m_pReference->FUN_00474cb0() ? m_pReference->GetName() : m_pReference->GetFullName(),
                        m_pReference->GetFormID(), kPos.x, kPos.y, kPos.z);
    }
}

// Saves the combat procedure state by calling SaveGame, serializing m_pReference and m_pBaseObject, and saving bFlag.
// @fnv 0x009cacb0
void CombatProcedureActivateObject::FUN_009cacb0(BGSSaveFormBuffer* apSaveBuffer)
{
    CombatProcedure::SaveGame(apSaveBuffer);
    apSaveBuffer->SerializeFormData(m_pReference, 0);
    apSaveBuffer->SerializeFormData(m_pBaseObject, 0);
    apSaveBuffer->SaveData(&bFlag, 1, 0);
}

struct CPStandIn004534f0
{
    void FUN_004534f0(unsigned int);
};
struct CPStandIn00564db0
{
    void FUN_00564db0(int);
};
extern "C" TESForm* __cdecl FUN_004839c0(TESObjectREFR*);

// Calls FUN_004534f0 with arg, assigns the cast result of FUN_004839c0 to m_pReference, then calls FUN_00564db0(1) if non-null.
// @fnv 0x009cad70
void CombatProcedureActivateObject::FUN_009cad70(unsigned int arg)
{
    ((CPStandIn004534f0*)this)->FUN_004534f0(arg);
    m_pReference = m_pReference ? dynamic_cast<TESObjectREFR*>(FUN_004839c0(m_pReference)) : 0;
    if (m_pReference)
        ((CPStandIn00564db0*)m_pReference)->FUN_00564db0(1);
}


struct ScriptableFormForward : public TESScriptableForm
{
    void FUN_009cc4b0(unsigned int a);
};

// @fnv 0x009cc4b0
void ScriptableFormForward::FUN_009cc4b0(unsigned int auiInitData)
{
    TESScriptableForm::Initialize(auiInitData);
}

::TESForm* __cdecl FUN_004839c0(unsigned int);
// Reads the activate object load view from a form buffer, loading the reference, base object, and flag.
// @fnv 0x009cad00
void CombatProcedureActivateObject::FUN_009cad00(BGSLoadFormBuffer* apBuffer)
{
    CombatProcedure::LoadGame(apBuffer);
    apBuffer->ReadFormIdentifier(&m_pReference);
    m_pBaseObject =
        dynamic_cast< ::TESBoundObject*>(FUN_004839c0(((BGSLoadGameBuffer*)apBuffer)->ReadFormIdentifier()));
    apBuffer->ReadTypedData(&bFlag, 1);
}
