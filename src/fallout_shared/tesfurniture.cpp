// fallout_shared/tesfurniture.cpp: TESFurniture, TESObjectACTI (21 functions)

#include "tesfurniture_tesfurniture.h"
#include "../../include/FurnitureMark.h"

// @fnv 0x00508f70
void TESFurniture::ResetFormData()
{
    m_iMarkerCount = 0;
    TESObjectACTI::ResetFormData();
}

// Skips initialization if the form is already initialized; otherwise initializes the destructible object form, then calls two further setup steps.
// @fnv 0x00508f90
void TESFurniture::InitItem()
{
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    InitializeMarkerFlags();
    SetInitializationState(true);
}

// @fnv 0x005093f0
bool TESFurniture::GetCanSitOn()
{
    if (m_iMarkerCount & 0x40000000)
        return true;
    else
        return false;
}

// @fnv 0x00509420
bool TESFurniture::GetCanSleepOn()
{
    if (m_iMarkerCount & 0x80000000)
        return true;
    else
        return false;
}

// Returns true if the marker bit for aiMarker (below 0x20) is set in the marker mask.
// @fnv 0x00509450
bool TESFurniture::IsMarkerEnabled(unsigned int aiMarker)
{
    bool bEnabled = false;
    if (aiMarker < 0x20)
    {
        unsigned int iMask = 1 << aiMarker;
        if (m_iMarkerCount & iMask)
            bEnabled = true;
    }
    return bEnabled;
}

// @fnv 0x005094f0
bool TESFurniture::IsFurnitureSleepMarker(unsigned int auMarker)
{
    bool bSleep = false;
    if (auMarker < 10)
        bSleep = true;
    return bSleep;
}

// Returns true when auMarker is between 10 and 20 inclusive or equals 26, otherwise false.
// @fnv 0x00509510
bool TESFurniture::IsFurnitureSitMarker(unsigned int auMarker)
{
    bool bSit = false;
    if (auMarker >= 10 && auMarker <= 20 || auMarker == 26)
        bSit = true;
    return bSit;
}

// @fnv 0x00508fd0
bool TESFurniture::Load(TESFile* file)
{
    CHUNK_ID chunk;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while ((chunk = static_cast<CHUNK_ID>(file->GetChunkID())) != 0)
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_FULL_ID:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case CHUNK_ID_MODL_ID:
        case CHUNK_ID_MODD_ID:
        case CHUNK_ID_MODT_ID:
        case CHUNK_ID_MOSD_ID:
            TESModel::LoadModelData(this, file);
            break;
        case CHUNK_ID_MODS_ID: {
            void* textureSwapData;
            unsigned int textureSwapSize = file->GetChunkSize();
            textureSwapData = _alloca(textureSwapSize);
            file->GetChunkData(textureSwapData, textureSwapSize);
            ParseTextureSwapData(textureSwapData, textureSwapSize,
                                 static_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }
        case CHUNK_ID_SCRI_ID: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            SetScript(reinterpret_cast<Script*>(scriptID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case CHUNK_ID_DEST_ID:
        case CHUNK_ID_DSTD_ID:
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case CHUNK_ID_MNAM_ID:
            file->GetChunkData(reinterpret_cast<unsigned int*>(&m_iMarkerCount));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Returns the offset for a marker index (1-40) from the marker table, scaling the z component by afScale - 1.
// @fnv 0x00509920
NiPoint3 TESFurniture::GetMarkerOffset(unsigned int auMarkerIndex, float afScale)
{
    NiPoint3 offset = NiPoint3::ZERO;
    if (auMarkerIndex > 0 && auMarkerIndex <= 40)
    {
        offset.x = *g_ppFurnitureMarkerOffsetSettings[auMarkerIndex - 1][0]->Float();
        offset.y = *g_ppFurnitureMarkerOffsetSettings[auMarkerIndex - 1][1]->Float();
        offset.z = *g_ppFurnitureMarkerOffsetSettings[auMarkerIndex - 1][2]->Float() * (afScale - 1.0f);
    }
    return offset;
}

// @fnv 0x005104f0
TESObjectACTI::TESObjectACTI()
{
    SetFormType(ENUM_FORM_ID_ACTI_ID);
    ResetFormData();
    SetInitializationState(true);
}

// @fnv 0x00509350
void TESFurniture::InitializeMarkerFlags()
{
    if (IsTemporary())
        return;
    if (m_iMarkerCount == 0)
    {
        if (!BSFurnitureMarker_Find(Clone3DAlt(0)))
            Warning("MODELS: No FurnitureMarkers found in '%s'.", GetModelFilePath());
        else
            Warning("MODELS: You have not selected any FurnitureMarkers for '%s'.", GetName());
        Destroy3DModel(0);
    }
}

int __fastcall NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(void* pThis);

// @fnv 0x00509490
// src: XBOX_PDB 0x00509490
int __fastcall BSFurnitureMarker_QNumMarks(char* pThis)
{
    return NiTArray_char_NiTMallocInterface_char_GetEffectiveSize(pThis + 0xc);
}

typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];

// @fnv 0x005094b0
unsigned int FurnitureMark::QNumber()
{
    return cMarkerType;
}

struct DummyArr
{
    void GetElementAddress16(int);
};

struct DummyThis
{
    char pad[0xc];
    DummyArr arr;
};

struct StackArg
{
    int val;
};

// @fnv 0x005094d0
// src: XBOX_PDB 0x005094d0
void __fastcall BSFurnitureMarker_QMark(DummyThis* this_ptr, StackArg param_1)
{
    this_ptr->arr.GetElementAddress16(param_1.val);
}

struct FUN_005099c0_shell : public TESFurniture
{
    float GetFurnitureHeading(unsigned int);
};

struct FurnitureMarkerData
{
    int unk0;
    int unk4;
    SettingT<GameSettingCollection>* pHeadingSetting;
    int unkC;
};
extern FurnitureMarkerData DAT_01189fa4[];

// Returns the heading float from the furniture marker setting at aiIndex-1 when aiIndex is in 1..0x28, otherwise 0.0f.
// @fnv 0x005099c0
float FUN_005099c0_shell::GetFurnitureHeading(unsigned int aiIndex)
{
    float fheading = 0.0f;
    if (aiIndex > 0 && aiIndex <= 0x28)
    {
        fheading = *DAT_01189fa4[aiIndex - 1].pHeadingSetting->Float();
    }
    return fheading;
}

struct FUN_00508e00 : public TESObjectACTI
{
    FUN_00508e00();
    virtual ~FUN_00508e00();
};

// @fnv 0x00508e00
FUN_00508e00::FUN_00508e00()
{
    SetFormType((ENUM_FORM_ID)0x27);
    ((TESFurniture*)this)->ResetFormData();
    SetInitializationState(true);
}

void operator delete(void*);

struct FUN_00508eb0_obj
{
    void FUN_00508ee0();
    void* Destroy(unsigned int flags);
};

// Calls FUN_00508ee0, then deletes this object if flags has bit 0 set, and returns this.
// @fnv 0x00508eb0
void* FUN_00508eb0_obj::Destroy(unsigned int flags)
{
    FUN_00508ee0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_00508ee0 : public TESObjectACTI
{
    virtual ~FUN_00508ee0();
};

// Destructor for this TESObjectACTI subclass that calls ClearData().
// @fnv 0x00508ee0
FUN_00508ee0::~FUN_00508ee0()
{
    ClearData();
}

struct S_00487010
{
    void Save_00487010();
};
struct S_0048a520
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void Save_0048cca0();
};
struct S_00477f20
{
    void FUN_00477f20();
};
void __cdecl TESForm_AddChunk_00485910(unsigned int, int);

struct FUN_00509280_obj : public TESFurniture
{
    void BeginFormRecord();
    void FinishFormRecord();
    void TESFurniture_Save();
};

// @fnv 0x00509280
// src: XBOX_PDB 0x00509280
void FUN_00509280_obj::TESFurniture_Save()
{
    BeginFormRecord();
    ((S_00487010*)((char*)this + 0x30))->Save_00487010();
    ((S_0048a520*)((char*)this + 0x3c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((S_0048cca0*)((char*)this + 0x5c))->Save_0048cca0();
    ((S_00477f20*)((char*)this + 0x68))->FUN_00477f20();
    TESForm_AddChunk_00485910(0x4d414e4d, m_iMarkerCount);
    FinishFormRecord();
}

struct FUN_005092f0_obj : public TESFurniture
{
    void TESForm_CopyAllComponents(TESForm*);
    void CopyFromFurniture(TESForm* apCopy);
};

// @fnv 0x005092f0
void FUN_005092f0_obj::CopyFromFurniture(TESForm* apCopy)
{
    TESFurniture* pcopy = dynamic_cast<TESFurniture*>(apCopy);
    if (!pcopy)
        return;
    TESForm_CopyAllComponents(apCopy);
    m_iMarkerCount = pcopy->m_iMarkerCount;
    InitializeMarkerFlags();
}

struct FUN_00509540_obj : public TESFurniture
{
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESFurniture_Compare(TESForm* apCompare);
};

// @fnv 0x00509540
// src: XBOX_PDB 0x00509540
bool FUN_00509540_obj::TESFurniture_Compare(TESForm* apCompare)
{
    TESFurniture* pcomp = dynamic_cast<TESFurniture*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm_CompareAllComponents(pcomp))
        return true;
    if (m_iMarkerCount != pcomp->m_iMarkerCount)
        return true;
    return false;
}
