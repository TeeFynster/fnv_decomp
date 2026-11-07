// fallout_shared/bgsacousticspace.cpp: BGSAcousticSpace (12 functions)

#include "../../include/BGSAcousticSpace.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSAddonNode.h"
#include "../../include/BSOcclusionPlane.h"
#include "../../include/TESTopicInfo.h"
#include "../../include/TESSound.h"
#include "../../include/TESRegion.h"
#include <malloc.h>
#include "../../include/NiFormArray.h"

int Warning(const char* apFormat, ...);

static const char s_kAcousticDawnSoundWarning[] =
    "MASTERFILE: Could not find pDawnSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticNoonSoundWarning[] =
    "MASTERFILE: Could not find pNoonSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticDuskSoundWarning[] =
    "MASTERFILE: Could not find pDuskSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticNightSoundWarning[] =
    "MASTERFILE: Could not find pNightSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticRegionWarning[] =
    "MASTERFILE: Could not find sound region (%08X) for activator '%s' (%08X).";
static const char s_kAcousticWallaSoundWarning[] =
    "MASTERFILE: Could not find pWallaSound (%08X) for activator '%s' (%08X).";

// Resets all sound pointers and related fields to zero/default values.
// @fnv 0x00589980
void BGSAcousticSpace::ResetFormData()
{
    pDawnSound = 0;
    pNoonSound = 0;
    pDuskSound = 0;
    pNightSound = 0;
    pWallaSound = 0;
    m_iFlags = 0;
    m_bIsInterior = true;
    pRegion = 0;
    m_eCellEnvironmentType = CELL_ENVIRO_TYPE_CET_DEFAULT;
}

// @fnv 0x005899f0
void BGSAcousticSpace::InitItem()
{
    unsigned int formID;
    if (IsFormInitialized())
        return;
    formID = reinterpret_cast<unsigned int>(pDawnSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pDawnSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pDawnSound)
            Warning(s_kAcousticDawnSoundWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(pNoonSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pNoonSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pNoonSound)
            Warning(s_kAcousticNoonSoundWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(pDuskSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pDuskSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pDuskSound)
            Warning(s_kAcousticDuskSoundWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(pNightSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pNightSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pNightSound)
            Warning(s_kAcousticNightSoundWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(pRegion);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pRegion = dynamic_cast<TESRegion*>(TESForm::GetFormByID(formID));
        if (!pRegion)
            Warning(s_kAcousticRegionWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(pWallaSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pWallaSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!pWallaSound)
            Warning(s_kAcousticWallaSoundWarning, formID, GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// Loads an acoustic space record from a TESFile, reading the editor ID, OBND, SNAM sound slots, WNAM, RDAT region, ANAM type and INAM interior flag chunks.
// @fnv 0x00589d30
bool BGSAcousticSpace::Load(TESFile* file)
{
    unsigned int soundFormID = 0;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int m_uiSoundEntryCount = 0;
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4D414E53:  // SNAM
            soundFormID = 0;
            file->GetChunkData(&soundFormID);
            if (m_uiSoundEntryCount == 4)
                SetWallaSound(reinterpret_cast<TESSound*>(soundFormID));
            else if (m_uiSoundEntryCount == 3)
                SetNightSound(reinterpret_cast<TESSound*>(soundFormID));
            else if (m_uiSoundEntryCount == 2)
                SetDuskSound(reinterpret_cast<TESSound*>(soundFormID));
            else if (m_uiSoundEntryCount == 1)
                SetNoonSound(reinterpret_cast<TESSound*>(soundFormID));
            else
                SetDawnSound(reinterpret_cast<TESSound*>(soundFormID));
            m_uiSoundEntryCount++;
            break;
        case 0x4D414E57:  // WNAM
            file->GetChunkData(reinterpret_cast<unsigned int*>(&m_iFlags));
            break;
        case 0x54414452:  // RDAT
            soundFormID = 0;
            file->GetChunkData(&soundFormID);
            SetRegion(reinterpret_cast<TESRegion*>(soundFormID));
            break;
        case 0x4D414E41:  // ANAM
            file->GetChunkData(&soundFormID);
            SetListenerID(static_cast<CELL_ENVIRO_TYPE>(soundFormID));
            break;
        case 0x4D414E49:  // INAM
        {
            unsigned int interiorFlag;
            file->GetChunkData(&interiorFlag);
            if (interiorFlag == 0)
                m_bIsInterior = false;
            else
                m_bIsInterior = true;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0058a200
char __fastcall GetByteAtOffset48(void* this_ptr)
{
    return static_cast<char*>(this_ptr)[0x30];
}

struct FUN_00589f50_shell
{
    void SetSound(void* apSound);
};

// @fnv 0x00589f50
void __thiscall FUN_00589f50_shell::SetSound(void* apSound)
{
    *(int*)((char*)this + 0x4c) = (int)apSound;
}

struct Standin00589930
{
    void UpdateFields_00589960();
    void* FUN_00589930(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00589960, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00589930
void* Standin00589930::FUN_00589930(unsigned int flags)
{
    UpdateFields_00589960();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Returns the BGSCameraPath at index idx from the form array, or null if the array is absent or the form is not a camera path.
// @fnv 0x0058b630
BGSCameraPath* BGSCameraPath::GetCameraPathAt(unsigned int uiIndex)
{
    BGSCameraPath* result = 0;
    if (m_pPathArray)
        result = dynamic_cast<BGSCameraPath*>(m_pPathArray->GetFormAt(uiIndex));
    return result;
}

extern int DAT_010320fc;

void __fastcall UpdateState_0050e9f0(void*);

struct FUN_00589960_shell
{
    void __thiscall UpdateFields_00589960();
};

// @fnv 0x00589960
// src: GUESS 0x00589960 (confidence: low)
void __thiscall FUN_00589960_shell::UpdateFields_00589960()
{
    *reinterpret_cast<int**>(this) = &DAT_010320fc;
    UpdateState_0050e9f0(this);
}

struct FUN_0058a120_shell : BGSAcousticSpace
{
    void CopyFromAcousticSpace(TESForm* apCopy);
};
struct FUN_00792780_Class
{
    void SetByteAtOffset30(unsigned char);
};
struct EP_008c48d0
{
    TESSound* GetEntryPoint();
};
struct Idle_008b2010
{
    TESSound* GetState();
};
struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct FUN_0068a810_shell
{
    int GetField4C();
};
// Casts apCopy to BGSAcousticSpace, copies its sound, index, region and environment fields into this, then calls FUN_004851b0.
// @fnv 0x0058a120
void FUN_0058a120_shell::CopyFromAcousticSpace(TESForm* apCopy)
{
    BGSAcousticSpace* pcopy = dynamic_cast<BGSAcousticSpace*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_00792780_Class*)this)->SetByteAtOffset30(::GetByteAtOffset48(pcopy));
    SetDawnSound(reinterpret_cast<TESSound*>(((BGSCameraPath*)pcopy)->GetPrevPath()));
    SetNoonSound(reinterpret_cast<TESSound*>(((TESTopicInfo*)pcopy)->GetConversationData()));
    SetDuskSound(((EP_008c48d0*)pcopy)->GetEntryPoint());
    SetNightSound(reinterpret_cast<TESSound*>(((BSOcclusionPlane*)pcopy)->GetCullResult()));
    SetWallaSound(((Idle_008b2010*)pcopy)->GetState());
    ((BGSAddonNode*)this)->SetIndex(((BGSAddonNode*)pcopy)->GetIndex());
    SetRegion(reinterpret_cast<TESRegion*>(((TESTopicInfo*)pcopy)->GetParentQuest()));
    SetListenerID((CELL_ENVIRO_TYPE)((FUN_0068a810_shell*)pcopy)->GetField4C());
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
}

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct P09AS
{
    int GetField4C();
};

void _FUN_00485910(int, int);

struct FUN_00589f70_shell
{
    void BGSAcousticSpace_Save();
};

// @fnv 0x00589f70
// src: XBOX_PDB 0x00589f70
void FUN_00589f70_shell::BGSAcousticSpace_Save()
{
    unsigned int questFormID;
    unsigned int formID;

    reinterpret_cast<FUN_004855a0*>(this)->M();

    questFormID = 0;
    if (reinterpret_cast<BGSCameraPath*>(this)->GetPrevPath() != 0)
    {
        questFormID = reinterpret_cast<TESForm*>(reinterpret_cast<BGSCameraPath*>(this)->GetPrevPath())->GetFormID();
    }
    _FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (reinterpret_cast<TESTopicInfo*>(this)->GetConversationData() != 0)
    {
        questFormID =
            reinterpret_cast<TESForm*>(reinterpret_cast<TESTopicInfo*>(this)->GetConversationData())->GetFormID();
    }
    _FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (reinterpret_cast<EP_008c48d0*>(this)->GetEntryPoint() != 0)
    {
        questFormID = reinterpret_cast<TESForm*>(reinterpret_cast<EP_008c48d0*>(this)->GetEntryPoint())->GetFormID();
    }
    _FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (reinterpret_cast<BSOcclusionPlane*>(this)->GetCullResult() != 0)
    {
        questFormID =
            reinterpret_cast<TESForm*>(reinterpret_cast<BSOcclusionPlane*>(this)->GetCullResult())->GetFormID();
    }
    _FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (reinterpret_cast<Idle_008b2010*>(this)->GetState() != 0)
    {
        questFormID = reinterpret_cast<TESForm*>(reinterpret_cast<Idle_008b2010*>(this)->GetState())->GetFormID();
    }
    _FUN_00485910(0x4d414e53, questFormID);

    _FUN_00485910(0x4d414e57, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x50));

    if (reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest() != 0)
    {
        formID = reinterpret_cast<TESForm*>(reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest())->GetFormID();
        _FUN_00485910(0x54414452, formID);
    }

    _FUN_00485910(0x4d414e41, reinterpret_cast<P09AS*>(this)->GetField4C());

    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x30) != 0)
    {
        _FUN_00485910(0x4d414e49, 1);
    }
    else
    {
        _FUN_00485910(0x4d414e49, 0);
    }

    reinterpret_cast<FUN_00485680*>(this)->M();
}

namespace fnv_0058a220 {
struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};

struct P09AS
{
    int GetField4C();
};

struct FUN_0058a220_shell
{
    bool IsNotEqual(TESForm*);
};

// @fnv 0x0058a220
bool FUN_0058a220_shell::IsNotEqual(TESForm* apCompare)
{
    BGSAcousticSpace* pcomp = dynamic_cast<BGSAcousticSpace*>(apCompare);
    if (!pcomp)
        return true;

    if (static_cast<unsigned char>(GetByteAtOffset48(this)) != static_cast<unsigned char>(GetByteAtOffset48(pcomp)))
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pcomp))
        return true;

    if (reinterpret_cast<BGSCameraPath*>(this)->GetPrevPath() != reinterpret_cast<BGSCameraPath*>(pcomp)->GetPrevPath())
        return true;

    if (reinterpret_cast<TESTopicInfo*>(this)->GetConversationData() !=
        reinterpret_cast<TESTopicInfo*>(pcomp)->GetConversationData())
        return true;

    if (reinterpret_cast<EP_008c48d0*>(this)->GetEntryPoint() != reinterpret_cast<EP_008c48d0*>(pcomp)->GetEntryPoint())
        return true;

    if (reinterpret_cast<BSOcclusionPlane*>(this)->GetCullResult() !=
        reinterpret_cast<BSOcclusionPlane*>(pcomp)->GetCullResult())
        return true;

    if (reinterpret_cast<Idle_008b2010*>(this)->GetState() != reinterpret_cast<Idle_008b2010*>(pcomp)->GetState())
        return true;

    if (reinterpret_cast<BGSAddonNode*>(this)->GetIndex() != reinterpret_cast<BGSAddonNode*>(pcomp)->GetIndex())
        return true;

    if (reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest() !=
        reinterpret_cast<TESTopicInfo*>(pcomp)->GetParentQuest())
        return true;

    if (reinterpret_cast<P09AS*>(this)->GetField4C() != reinterpret_cast<P09AS*>(pcomp)->GetField4C())
        return true;

    return false;
}
}  // namespace fnv_0058a220

class FUN_0050e820 : public TESForm
{
  public:
    FUN_0050e820();
    virtual ~FUN_0050e820();
};

class FUN_005898c0 : public FUN_0050e820
{
  public:
    FUN_005898c0();
    virtual ~FUN_005898c0();
    void FUN_00589980();
};

// Sets the form type to ASPC and calls FUN_00589980.
// @fnv 0x005898c0
FUN_005898c0::FUN_005898c0()
{
    SetFormType(static_cast<ENUM_FORM_ID>(14));  // ASPC
    FUN_00589980();
}
