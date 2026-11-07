#include "../../include/PackageTargetRecord.h"
// fallout_shared/tesobjectdoor.cpp: TESObjectDOOR and door helpers (30 functions)

#include "../../include/BSSimpleList.h"

#include "../../include/Actor.h"
#include "../../include/BGSOpenCloseForm.h"
#include "../../include/BSAudio.h"
#include "../../include/Setting.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/DoorAccessData.h"
#include "../../include/ExtraLock.h"
#include "../../include/TES.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESFile.h"
#include "../../include/TESFullName.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESSound.h"

#include "../../include/ExtraFollower.h"
#include "../../include/HighProcess.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESObjectDOOR.h"

// Remaining private declarations for this unit.

class NiFixedString;
extern NiFixedString* DAT_011c61dc;
class Script;
class TESGlobal;
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/CHUNK_ID.h"
class TESObjectCELL;
class TESWorldSpace;
class NiNode;
class Animation;
class BaseProcess;
class LockExtraData
{
  public:
    unsigned int level;
    TESBoundObject* key;
    bool IsLocked();
    int GetLockLevel(TESObjectREFR*);
    bool MeetsMinimumLockLevel();
};
class TeleportableReference
{
  public:
    TESObjectCELL* DoorTeleportData_GetTeleportCell();
    TESWorldSpace* GetTeleportWorldspace();
    NiPoint3* GetPosition();
    NiPoint3* GetRotation();
};
class Animation
{
  public:
    void SpecialIdleFree(bool, bool);
};

// Exe 0x005177f0: unit-local Interface view; declarations and layout are preserved.
class TesobjectdoorInterfaceView
{
  public:
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
    static void PlayUISound(int);
};
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern TESBoundObject* g_pLockpickItem;
extern TESObjectREFR* DAT_011c9350;
extern Setting DAT_011c9384, DAT_011d276c, DAT_011d5110;
extern const float DAT_010162c0;
void TESObjectDOOR_LinkRandomTeleportDoors(TESObjectREFR*, TESObjectREFR*);
void TESIdleManager_SetUsedItem(TESBoundObject*);
void TESIdleManager_SetUsedItemLevel(int);
void TESIdleManager_SetUsedItemActivate(bool);
void Interface_CreateLockPickMenu(TESObjectREFR*, int, int);
void ApplyPerkModifiers(int, Actor*, float*);
int Warning(const char*, ...);
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);

// Loads a TESObjectDOOR record from a TESFile, dispatching each chunk to the matching sub-record loader and returning false if the form type is not 28.
// @fnv 0x005177f0
bool TESObjectDOOR::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 28)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (CHUNK_ID chunk = static_cast<CHUNK_ID>(file->GetChunkID()))
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 512);
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
            struct
            {
                unsigned int size;
                void* data;
            } chunkData;
            chunkData.size = file->GetChunkSize();
            chunkData.data = _alloca(chunkData.size);
            file->GetChunkData(chunkData.data, chunkData.size);
            ParseTextureSwapData(chunkData.data, chunkData.size, file->GetFormVersion());
            break;
        }
        case 'IRCS': {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 'MANS': {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            RemapFormIDForFile(soundID, file);
            m_pOpenSound = dynamic_cast<TESSound*>(GetFormByID(soundID));
            break;
        }
        case 'MANA': {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            RemapFormIDForFile(soundID, file);
            m_pSecondarySound = dynamic_cast<TESSound*>(GetFormByID(soundID));
            break;
        }
        case 'MANB': {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            RemapFormIDForFile(soundID, file);
            m_pLoopingSound = dynamic_cast<TESSound*>(GetFormByID(soundID));
            break;
        }
        case 'MANF':
            file->GetChunkData(&cFlags, 1);
            break;
        case 'MANT': {
            unsigned int teleportID = 0;
            file->GetChunkData(&teleportID);
            m_kRandomTeleportTargets.AddHead(reinterpret_cast<TESForm*>(teleportID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Initializes the door's scriptable, destructible and model forms, resolves random teleport form IDs and removes unresolved entries with a warning.
// @fnv 0x005176b0
void TESObjectDOOR::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    TESScriptableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BSSimpleList<TESForm*>* current = TESDataHandler_GetFactions();
    BSSimpleList<TESForm*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        struct
        {
            unsigned int id;
            TESForm* value;
        } resolvedForm;
        resolvedForm.id = reinterpret_cast<unsigned int>(current->GetItem());
        RemapFormIDForFile(resolvedForm.id, GetFile(-1));
        resolvedForm.value = GetFormByID(resolvedForm.id);
        if (resolvedForm.value)
        {
            current->SetItem(resolvedForm.value);
            previous = current;
            current = current->GetNext();
        }
        else
        {
            Warning("MASTERFILE: Could not find RandomTeleport (%08X) for Door '%s' (%08X).", resolvedForm.id,
                    GetName(), GetFormID());
            if (previous)
            {
                TESForm* missingForm = reinterpret_cast<TESForm*>(resolvedForm.id);
                previous->Remove(missingForm);
                current = previous->GetNext();
            }
            else
            {
                current->RemoveHead();
            }
        }
    }
    SetInitializationState(true);
}

// @fnv 0x005173e0
TESObjectDOOR::TESObjectDOOR()
{
    SetFormType(ENUM_FORM_ID_DOOR_ID);
    ResetFormData();
}

// @fnv 0x00518f00
bool TESObjectDOOR::ProcessDoorActivation(TESObjectREFR* door, Actor* actor, bool activate, bool movement)
{
    DoorAccessData lock(door);
    return ProcessDoorActivation(&lock, actor, door, activate, movement);
}

// @fnv 0x005175d0
void TESObjectDOOR::ResetFormData()
{
    m_pOpenSound = 0;
    m_pSecondarySound = 0;
    m_pLoopingSound = 0;
    cFlags = 0;
}

// Returns true if the cFlags bit 8 is set, otherwise false.
// @fnv 0x00518000
bool TESObjectDOOR::IsTeleportDoor()
{
    if (cFlags & 8)
        return true;
    else
        return false;
}

// @fnv 0x00517610
void TESObjectDOOR::ClearData()
{
    ClearRandomTeleportList();
}

// @fnv 0x0047a500
NiFixedString* TESObjectDOOR::GetOpenSequenceName()
{
    return DAT_011c61dc;
}

struct PhysicsSimulationContext;
struct hkMatrix3;
struct hkMotionState;
struct hkMultiThreadCheck;
struct hkReferencedObject;
struct hkStatisticsCollector;
struct hkTransform;
struct hkVector4;
struct hkaiObjectData;
struct hkdBreakableBody;
struct hkpAction;
struct hkpBreakableBody;
struct hkpCollidable;
struct hkpConstraintInstance;
struct hkpContactListener;
struct hkpDynamicsContactMgr;
struct hkpEntity;
struct hkpEntityActivationListener;
struct hkpEntityListener;
struct hkpLinkedCollidable;
struct hkpMaterial;
struct hkpMaxSizeMotion;
struct hkpMotion;
struct hkpRigidBody;
struct WorldPhysicsSettings;
struct hkpSimulationIsland;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct blob8
{
    char b[8];
};

hkpRigidBody* __fastcall Bipedanim_GetReferenceFlagsOrZero(void* p);
int __fastcall hkpRigidBody_getMotionType(hkpRigidBody* p);

struct bhkRigidBody_shell
{
    int bhkRigidBody_GetMotionType();
};

// @fnv 0x00517630
// src: XBOX_PDB 0x00517630
int bhkRigidBody_shell::bhkRigidBody_GetMotionType()
{
    hkpRigidBody* pb = Bipedanim_GetReferenceFlagsOrZero(this);
    return pb ? hkpRigidBody_getMotionType(pb) : 5;
}

class BGSRagdoll;
template <class T> class BSSimpleList;

int __fastcall hkpMotion_getType(void* pThis);

// @fnv 0x00517670
// src: XBOX_PDB 0x00517670
int __fastcall hkpRigidBody_getMotionType(TESDataHandler* apDataHandler)
{
    return hkpMotion_getType(apDataHandler->GetBGSRagdollList());
}



// @fnv 0x00517690
// src: XBOX_PDB 0x00517690
int __fastcall hkpMotion_getType(char* pThis)
{
    return ((PackageTargetRecord*)(pThis + 8))->GetTargetKind();
}

// Returns true if the byte at offset 0x84 of thisPtr has bit 2 set, otherwise false.
// @fnv 0x00517fa0
// src: XBOX_PDB 0x00517fa0
bool TESObjectDOOR::IsAutomaticDoor()
{
    if (cFlags & 2)
        return true;
    else
        return false;
}


// Returns true if the 0x10 flag is set in cFlags, otherwise false.
// @fnv 0x00518080
// src: XBOX_PDB 0x00518080
bool TESObjectDOOR::IsSlidingDoor()
{
    if (cFlags & 0x10)
        return true;
    else
        return false;
}

extern "C"
{
    bool __cdecl CanAccessLock();
}


struct Call_00501fd0
{
    bool call(Actor* a, bool b, bool c)
    {
        return ((bool(__thiscall*)(Call_00501fd0*, Actor*, bool, bool)) & CanAccessLock)(this, a, b, c);
    }
};

struct ProcessVtbl0x128
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual PlayerCharacter* v74();
};


// @fnv 0x00518e60
bool __cdecl CanActivateDoor(LockExtraData* apDoorLock, Actor* apActor, TESObjectREFR* apDoorRef, bool abactivate,
                             bool abmovement)
{
    bool bretval = false;
    if (apActor && apDoorLock)
    {
        if ((apActor->Actor_IsFollowing() && (((ProcessVtbl0x128*)apActor->GetProcess())->v74() == g_thePlayer) &&
             apDoorRef->Set3DObject()) ||
            apActor->IsDisabled())
        {
            bretval = true;
        }
        else
        {
            bretval = ((Call_00501fd0*)apDoorLock)->call(apActor, abactivate, abmovement);
        }
    }
    return bretval;
}

struct BSXFlags_shell
{
    char _pad[0xc];
    unsigned int m_uiCurrentValue;
    void BSXFlags_SetFlags(unsigned int aiFlags, bool abTF);
    void ClearFlags(unsigned int aiFlags);
};

// @fnv 0x00519230
// src: XBOX_PDB 0x00519230
void BSXFlags_shell::BSXFlags_SetFlags(unsigned int aiFlags, bool abTF)
{
    if (abTF)
        m_uiCurrentValue |= aiFlags;
    else
        ClearFlags(aiFlags);
}

// @fnv 0x005bb4d0
// src: XBOX_PDB 0x005bb4d0
bool BSAudio::TESRegionData_GetPriority()
{
    return bMultiThread;
}

struct FUN_00693d50_shell : public BaseProcess
{
    void BaseProcess_SetLastTimeProcessed(float);
};

// @fnv 0x00693d50
// src: XBOX_PDB 0x00693d50
void FUN_00693d50_shell::BaseProcess_SetLastTimeProcessed(float afTime)
{
    *(float*)((char*)this + 0x20) = afTime;
}


// Returns true if bit 4 of cDOFlags2 is set, otherwise false.
// @fnv 0x00517fd0
bool TESObjectDOOR::IsFlag4Set()
{
    if (cFlags & 4)
        return true;
    else
        return false;
}

struct FUN_00519270_shell
{
    void ClearFlags(unsigned int mask);
};

// @fnv 0x00519270
void FUN_00519270_shell::ClearFlags(unsigned int mask)
{
    *(unsigned int*)((char*)this + 0xc) &= ~mask;
}

struct Base_004d9210
{
    void FUN_004d9210(int a, int b);
};
extern int DAT_01021024;
struct Holder_004d9100
{
    Holder_004d9100* InitializeFields_004d9100(int a, int b);
};
// @fnv 0x004d9100
// src: GUESS 0x004d9100 (confidence: low)
Holder_004d9100* Holder_004d9100::InitializeFields_004d9100(int aiArg1, int aiArg2)
{
    ((Base_004d9210*)this)->FUN_004d9210(aiArg1, aiArg2);
    *(void**)this = (void*)&DAT_01021024;
    return this;
}

void __cdecl _Deallocate(void*);
// Calls FUN_00517500 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x005174d0
void* __thiscall TESObjectDOOR::FUN_005174d0(unsigned int flags)
{
    this->FUN_00517500();
    if (flags & 1)
        _Deallocate(this);
    return this;
}


// Sets or clears bit 3 (0x8) of the byte at offset 0x84 according to abSet.
// @fnv 0x00518030
// src: XBOX_PDB 0x00518030
void TESObjectDOOR::SetMinimalUse(bool abSet)
{
    if (abSet)
        cFlags |= 8;
    else
        cFlags &= ~8;
}

void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
struct DoorFormNode
{
    bool FUN_008256d0();
    TESForm** FUN_006815c0();
    DoorFormNode* FUN_00726070();
};
// TESModel.h has no declaration for this three-chunk writer.
extern "C" void WriteDoorModelChunks();

struct DoorSave_shell
{
    char pad0[0x30];
    TESFullName part30;
    TESModelTextureSwap part3c;
    TESScriptableForm part5c;
    BGSDestructibleObjectForm part68;
    char pad70[0x78 - 0x70];
    TESForm* form78;
    TESForm* form7c;
    TESForm* form80;
    unsigned char flags;
    void BeginFormRecord();
    void FinishFormRecord();
    DoorFormNode* TESDataHandler_GetFactions();
    void WriteSaveData();
};
// Writes the door save record: calls each part's writer, emits form IDs for form78/form7c/form80 and flags, then walks the node list emitting each form ID.
// @fnv 0x00517c30
void DoorSave_shell::WriteSaveData()
{
    DoorFormNode* pCurrentElementNext;
    unsigned int itempint;
    BeginFormRecord();
    part30.Save_00487010();
    ((void(__thiscall*)(TESModel*, unsigned int, unsigned int, unsigned int)) & WriteDoorModelChunks)(
        &part3c, 0x4c444f4d, 0x54444f4d, 0x53444f4d);
    part5c.Save_0048cca0();
    part68.Save();
    if (form78)
    {
        itempint = form78->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e53, itempint);
    }
    if (form7c)
    {
        itempint = form7c->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e41, itempint);
    }
    if (form80)
    {
        itempint = form80->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e42, itempint);
    }
    TESForm_AddChunk_3(0x4d414e46, flags);
    pCurrentElementNext = TESDataHandler_GetFactions();
    while (pCurrentElementNext && !pCurrentElementNext->FUN_008256d0())
    {
        itempint = (*pCurrentElementNext->FUN_006815c0())->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e54, itempint);
        pCurrentElementNext = pCurrentElementNext->FUN_00726070();
    }
    FinishFormRecord();
}

struct DoorTeleportNode
{
    bool IsEmpty();
    TESForm*& GetItem();
    DoorTeleportNode* GetNext();
    int GetSize();
    bool IsInList(TESForm*& item);
};

struct DoorCompare_shell : public TESObjectDOOR
{
    bool TESForm_CompareAllComponents(TESForm* form);
    TESSound* GetOpenSoundForm();
    TESSound* GetCloseSoundForm();
    TESSound* GetLoopSoundForm();
    DoorTeleportNode* GetTeleportList();
    bool CompareDoor(TESForm* form);
};

// Compares this door against another TESObjectDOOR's sounds, flags and teleport list, returning true when they differ.
// @fnv 0x00517e70
bool DoorCompare_shell::CompareDoor(TESForm* form)
{
    DoorCompare_shell* door = (DoorCompare_shell*)dynamic_cast<TESObjectDOOR*>(form);
    if (!door)
        return true;
    if (TESForm_CompareAllComponents(door))
        return true;
    if (m_pOpenSound != door->GetOpenSoundForm())
        return true;
    if (m_pSecondarySound != door->GetCloseSoundForm())
        return true;
    if (m_pLoopingSound != door->GetLoopSoundForm())
        return true;
    if (cFlags != door->cFlags)
        return true;
    DoorTeleportNode* node2 = door->GetTeleportList();
    if (GetTeleportList()->GetSize() != node2->GetSize())
        return true;
    while (node2 && !node2->IsEmpty())
    {
        if (!GetTeleportList()->IsInList(node2->GetItem()))
            return true;
        node2 = node2->GetNext();
    }
    return false;
}

struct S_00518f80_Obj
{
    int FUN_00401170();
};
struct S_00518f80_Ref : TESObjectREFR
{
    S_00518f80_Obj* BGSSaveFormBuffer_GetForm();
};
// These operations are not yet declared by the shared classes.
extern "C" void SetDoorActivationReference();
extern PlayerCharacter* DAT_011dea3c;
S_00518f80_Ref* __cdecl TESObjectREFR_FindReferenceFor3D(unsigned int id);
// @fnv 0x00518f80
// src: XBOX_PDB 0x00518f80
void __cdecl TESObjectDOOR_AutoDoorCallback(unsigned int uiRefId)
{
    S_00518f80_Ref* ref = TESObjectREFR_FindReferenceFor3D(uiRefId);
    if (ref)
    {
        if (ref->BGSSaveFormBuffer_GetForm()->FUN_00401170() == 0x1c)
        {
            if (!ref->FUN_00477ba0())
            {
                HighProcess* pHighProcess = dynamic_cast<HighProcess*>(DAT_011dea3c->GetProcess());
                if (pHighProcess)
                {
                    if (static_cast<BaseProcess*>(pHighProcess)->GetCurrentFadeState() != 4)
                        ((void(__thiscall*)(PlayerCharacter*, TESObjectREFR*)) &SetDoorActivationReference)(DAT_011dea3c, ref);
                }
            }
        }
    }
}

struct DoorCopyNode
{
    bool FUN_008256d0();
    TESForm** FUN_006815c0();
    DoorCopyNode* FUN_00726070();
    void FUN_00905820(TESForm**);
};
struct DoorCopy
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    TESSound *openSound, *closeSound, *loopSound;
    unsigned char flags;
    void FUN_00519550();
    DoorCopyNode* TESDataHandler_GetFactions();
    TESSound* GetEffectShader_00407820();
    TESSound* FUN_00407840();
    TESSound* FUN_004fb070();
    void TESForm_CopyAllComponents(TESForm*);
    void CopyFromDoor(TESForm*);
};
// Copies the door node list, flags and open/close/loop sounds from the TESObjectDOOR cast of form into this door, then calls FUN_004851b0(form).
// @fnv 0x00517d70
void DoorCopy::CopyFromDoor(TESForm* form)
{
    DoorCopy* source3 = reinterpret_cast<DoorCopy*>(dynamic_cast<TESObjectDOOR*>(form));
    if (!source3)
        return;
    DoorCopyNode* destination = 0;
    FUN_00519550();
    DoorCopyNode* node2 = source3->TESDataHandler_GetFactions();
    destination = TESDataHandler_GetFactions();
    while (node2 && !node2->FUN_008256d0())
    {
        destination->FUN_00905820(node2->FUN_006815c0());
        if (destination->FUN_00726070())
            destination = destination->FUN_00726070();
        node2 = node2->FUN_00726070();
    }
    flags = source3->flags;
    openSound = source3->GetEffectShader_00407820();
    closeSound = source3->FUN_00407840();
    loopSound = source3->FUN_004fb070();
    TESForm_CopyAllComponents(form);
}

#include <float.h>

struct ActivateVector
{
    float x, y, z;
};
struct ActivateAnimation
{
    void Animation_SpecialIdleFree(int, int);
};
struct ActivateKey
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    TESFullName name;
};
struct ActivateLock
{
    unsigned unk00;
    ActivateKey* key;
    bool FUN_005021a0();
};
struct ActivateTeleport
{
    void* DoorTeleportData_GetTeleportCell();
    void* FUN_0043a320();
    int FUN_00717e50();
    ActivateVector* TESDataHandler_GetWorldSpaceList();
};
struct ActivateProcess
{
    virtual void Slot0();
    virtual void Slot4();
    virtual void Slot8();
    virtual void Slotc();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3c();
    virtual void Slot40();
    virtual void Open(TESObjectREFR*, int, int, int, int, int);
    virtual void Slot48();
    virtual void Slot4c();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58();
    virtual void Slot5c();
    virtual void Slot60();
    virtual void Slot64();
    virtual void Slot68();
    virtual void Slot6c();
    virtual void Slot70();
    virtual void Slot74();
    virtual void Slot78();
    virtual void Slot7c();
    virtual void Slot80();
    virtual void Slot84();
    virtual void Slot88();
    virtual void Slot8c();
    virtual void Slot90();
    virtual void Slot94();
    virtual void Slot98();
    virtual void Slot9c();
    virtual void Slota0();
    virtual void Slota4();
    virtual void Slota8();
    virtual void Slotac();
    virtual void Slotb0();
    virtual void Slotb4();
    virtual void Slotb8();
    virtual void Slotbc();
    virtual void Slotc0();
    virtual void Slotc4();
    virtual void Slotc8();
    virtual void Slotcc();
    virtual void Slotd0();
    virtual void Slotd4();
    virtual void Slotd8();
    virtual void Slotdc();
    virtual void Slote0();
    virtual void Slote4();
    virtual void Slote8();
    virtual void Slotec();
    virtual void Slotf0();
    virtual void Slotf4();
    virtual void Slotf8();
    virtual void Slotfc();
    virtual void Slot100();
    virtual void Slot104();
    virtual void Slot108();
    virtual void Slot10c();
    virtual void Slot110();
    virtual void Slot114();
    virtual void Slot118();
    virtual void Slot11c();
    virtual void Slot120();
    virtual void Slot124();
    virtual void Slot128();
    virtual void Slot12c();
    virtual void Slot130();
    virtual void SetTarget(TESObjectREFR*);
    virtual void Slot138();
    virtual void Slot13c();
    virtual void Slot140();
    virtual void Slot144();
    virtual void Slot148();
    virtual void Slot14c();
    virtual void Slot150();
    virtual void Slot154();
    virtual void Slot158();
    virtual void Slot15c();
    virtual void Slot160();
    virtual void Slot164();
    virtual void Slot168();
    virtual void Slot16c();
    virtual void Slot170();
    virtual void Slot174();
    virtual void Slot178();
    virtual void Slot17c();
    virtual void Slot180();
    virtual void Slot184();
    virtual void Slot188();
    virtual void Slot18c();
    virtual void Slot190();
    virtual void Slot194();
    virtual void Slot198();
    virtual void Slot19c();
    virtual void Slot1a0();
    virtual void Slot1a4();
    virtual void Slot1a8();
    virtual void Slot1ac();
    virtual void Slot1b0();
    virtual void Slot1b4();
    virtual void Slot1b8();
    virtual void Slot1bc();
    virtual void Slot1c0();
    virtual void Slot1c4();
    virtual void Slot1c8();
    virtual void Slot1cc();
    virtual void Slot1d0();
    virtual void Slot1d4();
    virtual void Slot1d8();
    virtual void Slot1dc();
    virtual void Slot1e0();
    virtual void Slot1e4();
    virtual void Slot1e8();
    virtual void Slot1ec();
    virtual void Slot1f0();
    virtual void Slot1f4();
    virtual void Slot1f8();
    virtual void Slot1fc();
    virtual void Slot200();
    virtual void Slot204();
    virtual void Slot208();
    virtual void Slot20c();
    virtual void Slot210();
    virtual void Slot214();
    virtual void Slot218();
    virtual void Slot21c();
    virtual void Slot220();
    virtual void Slot224();
    virtual void Slot228();
    virtual void Slot22c();
    virtual void Slot230();
    virtual void Slot234();
    virtual void Slot238();
    virtual void Slot23c();
    virtual void Slot240();
    virtual void Slot244();
    virtual void Slot248();
    virtual void Slot24c();
    virtual void Slot250();
    virtual void Slot254();
    virtual void Slot258();
    virtual void Slot25c();
    virtual void Slot260();
    virtual void Slot264();
    virtual void Slot268();
    virtual void Slot26c();
    virtual void Slot270();
    virtual void Slot274();
    virtual void Slot278();
    virtual void Slot27c();
    virtual void Slot280();
    virtual void Slot284();
    virtual void Slot288();
    virtual void Slot28c();
    virtual void Slot290();
    virtual void Slot294();
    virtual void Slot298();
    virtual void Slot29c();
    virtual void Slot2a0();
    virtual void Slot2a4();
    virtual void Slot2a8();
    virtual void Slot2ac();
    virtual void Slot2b0();
    virtual void Slot2b4();
    virtual void Slot2b8();
    virtual void Slot2bc();
    virtual void Slot2c0();
    virtual void Slot2c4();
    virtual void Slot2c8();
    virtual void Slot2cc();
    virtual void Slot2d0();
    virtual void Slot2d4();
    virtual void Slot2d8();
    virtual void Slot2dc();
    virtual void Slot2e0();
    virtual void Slot2e4();
    virtual void Slot2e8();
    virtual void Slot2ec();
    virtual void Slot2f0();
    virtual void Slot2f4();
    virtual void Slot2f8();
    virtual void Slot2fc();
    virtual void Slot300();
    virtual void Slot304();
    virtual void Slot308();
    virtual void Slot30c();
    virtual void Slot310();
    virtual void Slot314();
    virtual void Slot318();
    virtual void Slot31c();
    virtual void Slot320();
    virtual void Slot324();
    virtual void Slot328();
    virtual void Slot32c();
    virtual void Slot330();
    virtual void Slot334();
    virtual void Slot338();
    virtual void Slot33c();
    virtual void Slot340();
    virtual void Slot344();
    virtual void Slot348();
    virtual void Slot34c();
    virtual void Slot350();
    virtual void Slot354();
    virtual void Slot358();
    virtual void Slot35c();
    virtual void Slot360();
    virtual void Slot364();
    virtual void Slot368();
    virtual void Slot36c();
    virtual void Slot370();
    virtual void Slot374();
    virtual void Slot378();
    virtual void Slot37c();
    virtual void Slot380();
    virtual void Slot384();
    virtual void Slot388();
    virtual void Slot38c();
    virtual void Slot390();
    virtual void Slot394();
    virtual void Slot398();
    virtual void Slot39c();
    virtual void Slot3a0();
    virtual void Slot3a4();
    virtual void Slot3a8();
    virtual void Slot3ac();
    virtual void Slot3b0();
    virtual void Slot3b4();
    virtual void Slot3b8();
    virtual void Slot3bc();
    virtual void Slot3c0();
    virtual void Slot3c4();
    virtual void Slot3c8();
    virtual void Slot3cc();
    virtual void Slot3d0();
    virtual void Slot3d4();
    virtual void Slot3d8();
    virtual void Slot3dc();
    virtual void Slot3e0();
    virtual void Slot3e4();
    virtual void Slot3e8();
    virtual void Slot3ec();
    virtual void Slot3f0();
    virtual void Slot3f4();
    virtual void Slot3f8();
    virtual void Slot3fc();
    virtual void Slot400();
    virtual void Slot404();
    virtual void Slot408();
    virtual void Slot40c();
    virtual void Slot410();
    virtual void Slot414();
    virtual void Slot418();
    virtual void Slot41c();
    virtual void Slot420();
    virtual void Slot424();
    virtual void Slot428();
    virtual void Slot42c();
    virtual void Slot430();
    virtual void Slot434();
    virtual void Slot438();
    virtual void Slot43c();
    virtual void Slot440();
    virtual void Slot444();
    virtual void Slot448();
    virtual void Slot44c();
    virtual void Slot450();
    virtual void Slot454();
    virtual void Slot458();
    virtual void Slot45c();
    virtual void Slot460();
    virtual void Slot464();
    virtual void Slot468();
    virtual void Slot46c();
    virtual void Slot470();
    virtual void Slot474();
    virtual void Slot478();
    virtual void Slot47c();
    virtual void Slot480();
    virtual void Slot484();
    virtual void Slot488();
    virtual void Slot48c();
    virtual void Slot490();
    virtual void Slot494();
    virtual void Slot498();
    virtual void Slot49c();
    virtual void Slot4a0();
    virtual void Slot4a4();
    virtual void Slot4a8();
    virtual void Slot4ac();
    virtual void Slot4b0();
    virtual void Slot4b4();
    virtual void Slot4b8();
    virtual void Slot4bc();
    virtual void Slot4c0();
    virtual void Slot4c4();
    virtual int Active();
    virtual void Slot4cc();
    virtual void Slot4d0();
    virtual void Slot4d4();
    virtual void Slot4d8();
    virtual void Slot4dc();
    virtual void Slot4e0();
    virtual void Slot4e4();
    virtual void Slot4e8();
    virtual void Slot4ec();
    virtual void Slot4f0();
    virtual void Slot4f4();
    virtual void Slot4f8();
    virtual void Slot4fc();
    virtual void Slot500();
    virtual void Slot504();
    virtual void Slot508();
    virtual void Slot50c();
    virtual void Slot510();
    virtual void Slot514();
    virtual void Slot518();
    virtual void Slot51c();
    virtual void Slot520();
    virtual void Slot524();
    virtual void Slot528();
    virtual void Slot52c();
    virtual void Slot530();
    virtual void Slot534();
    virtual void Slot538();
    virtual void Slot53c();
    virtual void Slot540();
    virtual void Slot544();
    virtual void Slot548();
    virtual void Slot54c();
    virtual void Slot550();
    virtual void Slot554();
    virtual void Slot558();
    virtual void Slot55c();
    virtual void Slot560();
    virtual void Slot564();
    virtual void Slot568();
    virtual void Slot56c();
    virtual void Slot570();
    virtual void Slot574();
    virtual void Slot578();
    virtual void Slot57c();
    virtual void Slot580();
    virtual void Slot584();
    virtual void Slot588();
    virtual void Slot58c();
    virtual void Slot590();
    virtual void Slot594();
    virtual void Slot598();
    virtual void Slot59c();
    virtual void Slot5a0();
    virtual void Slot5a4();
    virtual void Slot5a8();
    virtual void Slot5ac();
    virtual void Slot5b0();
    virtual void Slot5b4();
    virtual void Slot5b8();
    virtual void Slot5bc();
    virtual void Slot5c0();
    virtual void Slot5c4();
    virtual void Slot5c8();
    virtual void Slot5cc();
    virtual void Slot5d0();
    virtual void Slot5d4();
    virtual void Slot5d8();
    virtual void Slot5dc();
    virtual void Slot5e0();
    virtual void Slot5e4();
    virtual void Slot5e8();
    virtual void Slot5ec();
    virtual void Slot5f0();
    virtual void Slot5f4();
    virtual void Slot5f8();
    virtual void Slot5fc();
    virtual void Slot600();
    virtual void Slot604();
    virtual void Slot608();
    virtual void Slot60c();
    virtual int State();
    int FUN_0045cd60();
    void HighProcess_FadeOut(TESObjectREFR*, TESObjectREFR*, bool);
};
extern "C" ActivateTeleport* GetDoorTeleportData();
extern "C" ActivateLock* GetDoorLockData();
extern "C" ExtraLock* GetDoorExtraLock();
extern "C" bool ActivateDoorReference();
extern "C" bool GetDoorPlayerState();
extern "C" void SetDoorReferencePosition();
extern "C" void SetDoorReferenceRotation();

extern ActivateKey* DAT_011ca268;
struct ActivateDetection
{
    bool FUN_004511e0(void*, int);
};
extern ActivateDetection* DAT_011dea10;
void DispatchMessageToSink(const char*, int, const char*, int, float, int);
void TESObjectDOOR_LinkRandomTeleportDoors(TESObjectREFR*, TESObjectREFR*);
bool FUN_00518f00(TESObjectREFR*, TESObjectREFR*, int, int);
void FUN_005e58f0(int, TESObjectREFR*, float*);
void Interface_PlayMenuSound(int);
void Interface_CreateLockPickMenu(TESObjectREFR*, int, int);
void TESIdleManager_SetUsedItem(ActivateKey*);
void TESIdleManager_SetUsedItemActivate(int);
void TESIdleManager_SetUsedItemLevel(int);
int BSsprintf(char*, unsigned, const char*, ...);
void TESObjectREFR_MoveRefToNewSpace(TESObjectREFR*, void*, void*);
void BGSOpenCloseForm_HandleActivate(TESObjectREFR*, TESObjectREFR*, void*);
struct DoorActivation
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    bool ActivateDoor(TESObjectREFR*, TESObjectREFR*, int, int, int);
    bool IsRandomDoor();
    TESObjectREFR* FindRandomSelection(TESObjectREFR*, TESObjectREFR*);
    TESObjectREFR* GetEffectShader_00407820();
    void QueueDoorTeleport(TESObjectREFR*);
};
// Handles activation of a door reference by an activator: checks teleport/lock state, opens or unlocks the door, plays sounds, and performs teleportation.
// @fnv 0x005180b0
bool DoorActivation::ActivateDoor(TESObjectREFR* reference, TESObjectREFR* activator, int arg3, int arg4, int arg5)
{
    if (!reference || reference->FUN_00477ba0())
        return false;
    ActivateTeleport* teleport = ((ActivateTeleport*(__thiscall*)(TESObjectREFR*)) &GetDoorTeleportData)(reference);
    ActivateLock* lockA = ((ActivateLock*(__thiscall*)(TESObjectREFR*)) &GetDoorLockData)(reference);
    if (!teleport && IsRandomDoor())
    {
        TESObjectREFR* destination = FindRandomSelection(reference, activator);
        if (!destination)
        {
            DispatchMessageToSink(DAT_011c9384.FUN_00403df0(), 0,
                                  "Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds", 0, 2.0f, 0);
            return false;
        }
        TESObjectDOOR_LinkRandomTeleportDoors(reference, destination);
        teleport = ((ActivateTeleport*(__thiscall*)(TESObjectREFR*)) &GetDoorTeleportData)(reference);
        if (!teleport)
            return false;
    }
    Actor* actor = dynamic_cast<Actor*>(activator);
    ActivateProcess* process1 = actor ? reinterpret_cast<ActivateProcess*>(actor->FUN_008d8520()) : 0;
    unsigned usedKey2;
    if (actor)
    {
        if (reinterpret_cast<ActivateProcess*>(actor->FUN_008d8520())->Active() && actor->GetSitSleepState())
            return false;
        if (actor == (TESObjectREFR*)DAT_011dea3c)
            DAT_011dea3c->activationState = 0;
        bool alreadyOpen = FUN_00518f00(reference, actor, 1, 1);
        if (lockA && lockA->FUN_005021a0() && !alreadyOpen)
        {
            bool hasSkeleton = false;
            if (actor->IsCharacter())
                hasSkeleton = actor->Actor_HasObjects(reinterpret_cast<TESBoundObject*>(DAT_011ca268), 0, 1, 0, reinterpret_cast<int&>(usedKey2));
            if (lockA->key)
            {
                if (!DAT_011c9350 && !actor->Actor_HasObjects(reinterpret_cast<TESBoundObject*>(lockA->key), 0, 1, 0, reinterpret_cast<int&>(usedKey2)))
                {
                    if (actor == (TESObjectREFR*)DAT_011dea3c)
                    {
                        ExtraLock* statePart1 = ((ExtraLock*(__thiscall*)(TESObjectREFR*)) &GetDoorExtraLock)(reference);
                        float skillPart1 = 0.0f;
                        FUN_005e58f0(32, (TESObjectREFR*)DAT_011dea3c, &skillPart1);
                        if (statePart1 &&
                            (statePart1->pLock->GetLockLevel(reinterpret_cast<TESObjectREFR*>(reference)) == 5 || statePart1->pLock->MeetsMinimumLockLevel()))
                        {
                            DispatchMessageToSink(DAT_011d276c.FUN_00403df0(), 0,
                                                  "Interface\\Icons\\Message Icons\\glow_message_padlock.dds", 0, 2.0f,
                                                  0);
                            Interface_PlayMenuSound(18);
                        }
                        else
                            Interface_CreateLockPickMenu(reference, 0, 0);
                        return false;
                    }
                    else if (!hasSkeleton)
                        return false;
                    else
                    {
                        ActivateAnimation* animationPart1 = reinterpret_cast<ActivateAnimation*>(actor->GetAnimData());
                        if (animationPart1)
                            animationPart1->Animation_SpecialIdleFree(1, 0);
                        TESIdleManager_SetUsedItem(DAT_011ca268);
                        TESIdleManager_SetUsedItemActivate(1);
                        TESIdleManager_SetUsedItemLevel(1);
                        process1->Open(actor, 0, 2, 1, 0, 1);
                        TESIdleManager_SetUsedItem((ActivateKey*)0);
                        TESIdleManager_SetUsedItemActivate(0);
                        TESIdleManager_SetUsedItemLevel(-1);
                        ExtraLock* statePart2 = ((ExtraLock*(__thiscall*)(TESObjectREFR*)) &GetDoorExtraLock)(reference);
                        if (statePart2)
                        {
                            statePart2->FUN_00517360();
                            reference->TESObjectREFR_AddLockChange();
                        }
                    }
                }
                else if (actor == (TESObjectREFR*)DAT_011dea3c && !DAT_011c9350)
                {
                    DAT_011c9350 = (TESObjectREFR*)reference;
                    ExtraLock* statePart3 = ((ExtraLock*(__thiscall*)(TESObjectREFR*)) &GetDoorExtraLock)(reference);
                    if (statePart3)
                    {
                        statePart3->FUN_00517360();
                        reference->TESObjectREFR_AddLockChange();
                    }
                    BSAudio::GetSingleton()->GetSoundHandleByEditorID("UILockpickingUnlock", 0x121).Play(false);
                    char message[256];
                    BSsprintf(message, 255, DAT_011d5110.FUN_00403df0(),
                                 lockA->key->name.GetFullName());
                    DispatchMessageToSink(message, 0, "Interface\\Icons\\Message Icons\\glow_message_key.dds", 0, 2.0f,
                                          0);
                    ((bool(__thiscall*)(TESObjectREFR*, TESObjectREFR*, int, int, int)) &ActivateDoorReference)(DAT_011c9350, DAT_011dea3c, 0, 0, 1);
                    DAT_011c9350 = 0;
                    return true;
                }
            }
            else
            {
                if (actor == (TESObjectREFR*)DAT_011dea3c)
                {
                    ExtraLock* statePart4 = ((ExtraLock*(__thiscall*)(TESObjectREFR*)) &GetDoorExtraLock)(reference);
                    float skillPart2_2 = 0.0f;
                    FUN_005e58f0(32, (TESObjectREFR*)DAT_011dea3c, &skillPart2_2);
                    if (statePart4 &&
                        (statePart4->pLock->GetLockLevel(reinterpret_cast<TESObjectREFR*>(reference)) == 5 || statePart4->pLock->MeetsMinimumLockLevel()))
                    {
                        DispatchMessageToSink(DAT_011d276c.FUN_00403df0(), 0,
                                              "Interface\\Icons\\Message Icons\\glow_message_padlock.dds", 0, 2.0f, 0);
                        Interface_PlayMenuSound(18);
                    }
                    else
                        Interface_CreateLockPickMenu(reference, 0, 0);
                    return false;
                }
                else if (!hasSkeleton)
                    return false;
                else
                {
                    ActivateAnimation* animationPart2 = reinterpret_cast<ActivateAnimation*>(actor->GetAnimData());
                    if (animationPart2)
                        animationPart2->Animation_SpecialIdleFree(1, 0);
                    TESIdleManager_SetUsedItem(DAT_011ca268);
                    TESIdleManager_SetUsedItemActivate(1);
                    TESIdleManager_SetUsedItemLevel(1);
                    process1->Open(actor, 0, 2, 1, 0, 1);
                    TESIdleManager_SetUsedItem((ActivateKey*)0);
                    TESIdleManager_SetUsedItemActivate(0);
                    TESIdleManager_SetUsedItemLevel(-1);
                    ExtraLock* statePart5 = ((ExtraLock*(__thiscall*)(TESObjectREFR*)) &GetDoorExtraLock)(reference);
                    if (statePart5)
                    {
                        statePart5->FUN_00517360();
                        reference->TESObjectREFR_AddLockChange();
                    }
                }
            }
        }
    }
    if (teleport && actor)
    {
        if (!DAT_011dea3c->FUN_0094df60() && !process1->FUN_0045cd60() && process1->State() != 4)
        {
            if (GetEffectShader_00407820() && reference && reference->GetNiNode())
            {
                BSSoundHandle sound;
                if (actor == (TESObjectREFR*)DAT_011dea3c)
                    sound = BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(GetEffectShader_00407820()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0x80000121);
                else
                    sound = BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(GetEffectShader_00407820()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0x102u);
                if (actor != (TESObjectREFR*)DAT_011dea3c)
                {
                    NiPoint3 position = *static_cast<const TESObjectREFR*>(reference)->GetPos();
                    sound.SetPosition(position.x, position.y, position.z);
                }
                sound.Play(0);
                if (actor == (TESObjectREFR*)DAT_011dea3c && !BSAudio::GetSingleton()->TESRegionData_GetPriority())
                    for (int i = 0; i < 4; ++i)
                        BSAudio::GetSingleton()->Update(false);
            }
            process1->HighProcess_FadeOut(actor, reference, true);
            if (actor == (TESObjectREFR*)DAT_011dea3c)
                return true;
            else
                return false;
        }
        void* cell = teleport->DoorTeleportData_GetTeleportCell();
        void* world = teleport->FUN_0043a320();
        reinterpret_cast<ActivateProcess*>(actor->FUN_008d8520())->SetTarget(reference);
        if (actor == (TESObjectREFR*)DAT_011dea3c)
        {
            if (!((bool(__thiscall*)(PlayerCharacter*)) &GetDoorPlayerState)(DAT_011dea3c))
                DAT_011dea3c->lastExteriorDoor = reference;
            DAT_011dea3c->movingThroughDoor = 1;
            DAT_011dea3c->ProcessAllActions();
            QueueDoorTeleport(reference);
            DAT_011dea3c->movingThroughDoor = 0;
        }
        else
        {
            ((void(__thiscall*)(TESObjectREFR*, int)) &SetDoorReferencePosition)(activator, teleport->FUN_00717e50());
            if (cell && ((ActivateDetection*)DAT_011dea10)->FUN_004511e0(cell, 0))
            {
                ((void(__thiscall*)(TESObjectREFR*, float)) &SetDoorReferenceRotation)(activator, teleport->TESDataHandler_GetWorldSpaceList()->z);
                activator->TESObjectREFR_SetAngleOnReferenceX(0.0f);
            }
            else
                activator->TESObjectREFR_SetAngleOnReferenceX(FLT_MAX);
            Actor* actorAgain = dynamic_cast<Actor*>(activator);
            if (actorAgain)
                actorAgain->Actor_SetForceUpdateQuest(0);
            TESObjectREFR_MoveRefToNewSpace(activator, cell, world);
        }
    }
    else
    {
        ExtraLock* statePart6 = ((ExtraLock*(__thiscall*)(TESObjectREFR*)) &GetDoorExtraLock)(reference);
        if (statePart6)
        {
            statePart6->FUN_00517360();
            reference->TESObjectREFR_AddLockChange();
        }
        BGSOpenCloseForm_HandleActivate(reference, activator, this ? &unk070 : 0);
    }
    return true;
}

struct CellShell
{
    bool IsInterior();
};

struct FastTravelRequest
{
    TESWorldSpace* m_pContainingWorldspace;
    TESObjectCELL* pCell;
    NiPoint3 kPosition;
    NiPoint3 kRotationBasis;
    bool bFlag20;
    void(__cdecl* pCallback)(void*);
    TESObjectREFR* pRef;
    int unk2C;
    int unk30;
    FastTravelRequest();
};

void __cdecl DoorTeleportFinished(void*);

struct RefShell
{
    TESForm* GetBaseObject();
    TeleportableReference* GetTeleportData();
};


extern "C" void QueueDoorTeleportRequest();
extern bool DAT_011c9354;

// @fnv 0x00518b70
void TESObjectDOOR::QueueDoorTeleport(TESObjectREFR* apRef)
{
    if (apRef && ((RefShell*)apRef)->GetBaseObject() == (TESForm*)this)
    {
        TeleportableReference* pTeleport2 = ((RefShell*)apRef)->GetTeleportData();
        if (pTeleport2)
        {
            TESObjectCELL* pDestinationCell = pTeleport2->DoorTeleportData_GetTeleportCell();
            TESWorldSpace* pWorld8 = pTeleport2->GetTeleportWorldspace();
            FastTravelRequest* pRequest = new FastTravelRequest();
            pRequest->kPosition = *pTeleport2->GetPosition();
            pRequest->kRotationBasis = *pTeleport2->GetRotation();
            pRequest->bFlag20 = false;
            pRequest->pCallback = DoorTeleportFinished;
            pRequest->pRef = apRef;
            if (pDestinationCell && ((CellShell*)pDestinationCell)->IsInterior())
                pRequest->pCell = pDestinationCell;
            else
                pRequest->m_pContainingWorldspace = pWorld8;
            ((void(__thiscall*)(PlayerCharacter*, FastTravelRequest*)) &QueueDoorTeleportRequest)(g_thePlayer, pRequest);
            TESObjectCELL* pPlayerCell = reinterpret_cast<TESObjectCELL*>(g_thePlayer->FUN_008d6f30());
            DAT_011c9354 = pPlayerCell ? ((CellShell*)pPlayerCell)->IsInterior() : false;
        }
    }
}

namespace fnv_00518cf0 {
struct Proc;
struct Obj;
struct Mid;
struct VObj;
struct Ref;
struct FUN_0084e3a0_Class;
struct GlobalObj;
struct Other;

struct Proc
{
    bool FUN_00425fd0();
    void LockAndProcessPerks();
    void TESObjectCELL_ForceLODFadeInLoadedCells();
};

struct FUN_0084e3a0_Class
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct Obj
{
    FUN_0084e3a0_Class* FUN_00407840();
};

struct Mid
{
    VObj* Modelloader_GetReferencedThis();
};

struct VObj
{
    virtual void tv00();
    virtual void tv01();
    virtual void tv02();
    virtual void tv03();
    virtual void tv04();
    virtual void tv05();
    virtual void tv06();
    virtual void tv07();
    virtual void tv08();
    virtual void tv09();
    virtual void tv10();
    virtual void tv11();
    virtual void tv12();
    virtual void tv13();
    virtual void tv14();
    virtual void tv15();
    virtual void tv16();
    virtual void tv17();
    virtual void tv18();
    virtual void tv19();
    virtual void tv20();
    virtual void tv21();
    virtual void tv22();
    virtual void tv23();
    virtual void tv24();
    virtual void tv25();
    virtual void tv26();
    virtual void tv27();
    virtual void tv28();
    virtual void tv29();
    virtual void tv30();
    virtual void tv31();
    virtual void tv32();
    virtual void tv33();
    virtual void tv34();
    virtual void tv35();
    virtual void tv36();
    virtual void tv37();
    virtual void tv38();
    virtual void tv39();
    virtual void tv40();
    virtual void tv41();
    virtual void tv42();
    virtual void tv43();
    virtual void tv44();
    virtual void tv45();
    virtual void tv46();
    virtual void tv47();
    virtual void tv48();
    virtual void tv49();
    virtual void tv50();
    virtual void tv51();
    virtual void tv52();
    virtual void tv53();
    virtual void tv54();
    virtual void tv55();
    virtual void tv56();
    virtual void tv57();
    virtual void tv58();
    virtual void tv59();
    virtual void tv60();
    virtual void tv61();
    virtual void tv62();
    virtual void tv63();
    virtual void tv64();
    virtual void tv65();
    virtual void tv66();
    virtual void tv67();
    virtual void tv68();
    virtual void tv69();
    virtual void tv70();
    virtual void tv71();
    virtual void tv72();
    virtual void tv73();
    virtual void tv74();
    virtual void tv75();
    virtual void tv76();
    virtual void tv77();
    virtual void tv78();
    virtual void tv79();
    virtual void tv80();
    virtual void tv81();
    virtual void tv82();
    virtual void tv83();
    virtual void tv84();
    virtual void tv85();
    virtual void tv86();
    virtual void tv87();
    virtual void tv88();
    virtual void tv89();
    virtual void tv90();
    virtual void tv91();
    virtual void tv92();
    virtual void tv93();
    virtual void tv94();
    virtual void tv95();
    virtual void tv96();
    virtual void tv97();
    virtual void tv98();
    virtual void tv99();
    virtual void tv100();
    virtual void tv101();
    virtual void tv102();
    virtual void tv103();
    virtual void tv104();
    virtual void tv105();
    virtual void tv106();
    virtual void tv107();
    virtual void tv108();
    virtual void tv109();
    virtual void tv110();
    virtual void tv111();
    virtual void tv112();
    virtual void tv113();
    virtual void tv114();
    virtual void tv115();
    virtual int Gate1d0();
};


struct Ref
{
    Obj* BGSSaveFormBuffer_GetForm();
    Mid* FUN_00568e50();
};


struct GlobalObj
{
    unsigned char* FUN_00408d60();
};

struct Other
{
    void QueueAutosave();
};

extern GlobalObj DAT_011d8980;
extern Other* DAT_011de134;

void __cdecl TESObjectDOOR_PlayerPullFollower();

// Plays sound 0x121 for the given ref when its object and mid object pass checks, then updates the player proc state and notifies DAT_011de134.
// @fnv 0x00518cf0
void __cdecl PlaySoundForRef(unsigned int id)
{
    Ref* ref = (Ref*)id;
    if (ref)
    {
        TESObjectDOOR_PlayerPullFollower();
        if (reinterpret_cast<Proc*>(DAT_011dea3c->FUN_008d6f30()) && reinterpret_cast<Proc*>(DAT_011dea3c->FUN_008d6f30())->FUN_00425fd0())
        {
            reinterpret_cast<Proc*>(DAT_011dea3c->FUN_008d6f30())->LockAndProcessPerks();
        }
        Obj* obj = ref->BGSSaveFormBuffer_GetForm();
        if (obj->FUN_00407840())
        {
            if (ref->FUN_00568e50()->Modelloader_GetReferencedThis())
            {
                if (ref->FUN_00568e50()->Modelloader_GetReferencedThis()->Gate1d0())
                {
                    BSSoundHandle soundHandle =
                        BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(obj->FUN_00407840()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0x121);
                    soundHandle.Play(0);
                }
            }
        }
    }
    Proc* tailProc = reinterpret_cast<Proc*>(DAT_011dea3c->FUN_008d6f30());
    if (tailProc && !tailProc->FUN_00425fd0())
    {
        tailProc->TESObjectCELL_ForceLODFadeInLoadedCells();
    }
    if (*DAT_011d8980.FUN_00408d60() && tailProc)
    {
        DAT_011de134->QueueAutosave();
    }
}
}  // namespace fnv_00518cf0

void* __cdecl operator new(unsigned int);

struct FollowerExtraData
{
    ExtraFollower* ExtraDataList_GetFollowerExtra();
    void ExtraDataList_RemoveFollower(Actor* actor);
    void ExtraDataList_RemoveFollowerExtra();
};
extern "C" bool CanFollowerUseDoor();
extern "C" void PrepareFollowerForDoor();
struct FollowerListOps
{
    void FUN_00905820(Actor*& actor);
    void FUN_00470470();
};
struct Calendar
{
    float FUN_00867da0();
};
extern Calendar g_calendar;

// @fnv 0x00519290
// src: XBOX_PDB 0x00519290
void __cdecl TESObjectDOOR_PlayerPullFollower()
{
    ExtraFollower* followers = reinterpret_cast<FollowerExtraData*>(g_thePlayer->TESObjectREFR::BSFile_GetDevice())->ExtraDataList_GetFollowerExtra();
    if (followers)
    {
        BSSimpleList<Actor*>* removed = new BSSimpleList<Actor*>;
        BSSimpleList<Actor*>* source = new BSSimpleList<Actor*>;
        BSSimpleList<Actor*>* current = followers->list;
        while (current && current->GetItem())
        {
            reinterpret_cast<FollowerListOps*>(source)->FUN_00905820(current->GetItem());
            current = current->GetNext();
        }
        while (source && source->GetItem())
        {
            Actor* actor = source->GetItem();
            if (actor)
            {
                if (!((bool(__thiscall*)(Actor*, PlayerCharacter*)) &CanFollowerUseDoor)(actor, g_thePlayer))
                {
                    removed->AddHead(actor);
                }
                else
                {
                    ((void(__thiscall*)(Actor*)) &PrepareFollowerForDoor)(actor);
                    static_cast<FUN_00693d50_shell*>(actor->GetProcess())
                        ->BaseProcess_SetLastTimeProcessed(g_calendar.FUN_00867da0() - 1.0);
                }
            }
            source = source->GetNext();
        }
        source = removed;
        while (source && source->GetItem())
        {
            Actor* actorToRemove = source->GetItem();
            reinterpret_cast<FollowerExtraData*>(g_thePlayer->TESObjectREFR::BSFile_GetDevice())->ExtraDataList_RemoveFollower(actorToRemove);
            source = source->GetNext();
        }
        reinterpret_cast<FollowerListOps*>(removed)->FUN_00470470();
        delete removed;
        if (followers->list->IsEmpty())
        {
            reinterpret_cast<FollowerExtraData*>(g_thePlayer->TESObjectREFR::BSFile_GetDevice())->ExtraDataList_RemoveFollowerExtra();
        }
    }
}
