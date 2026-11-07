// fallout_shared/bgsheadpart.cpp: BGSHeadPart and related helpers (13 functions)

#include "../../include/BGSHeadPart.h"
#include "../../include/TESFile.h"

extern "C" void ref_004013e0();
extern "C" void ref_0048aa80();
extern "C" void ref_00624700();
extern "C" void ref_008256d0();
extern "C" void ref_006815c0();
extern "C" void ref_00484e60();
extern "C" void ref_00485d50();
extern "C" void ref_004839c0();
extern "C" void ref_004892d0();
extern "C" void ref_00ec43fb();
extern "C" void ref_0084e3a0();
extern "C" void ref_005b5e40();
extern "C" void ref_00905330();
extern "C" void ref_00726070();
extern "C" void ref_0063f7b0();
extern "C" void ref_00726c60();
extern "C" void ref_00484ab0();
extern "C" void ref_00472660();
extern "C" void ref_00485110();
extern "C" void ref_004726b0();
extern "C" void ref_00401660();
extern "C" void ref_00ec5ec0();
extern "C" void ref_00472890();
extern "C" void ref_00403570();
extern "C" void ref_004727f0();
extern "C" void ref_005e7790();
extern "C" void ref_004726f0();
extern "C" void ref_00ec408c();
extern "C" unsigned char data_011863b8[];
extern "C" unsigned char data_01183028[];
extern "C" unsigned char data_010465ec[];
extern "C" unsigned char data_011c16bc[];

#include "../../include/ENUM_FORM_ID.h"
// @fnv 0x005e7440
void BGSHeadPart::ResetFormData()
{
    cFlags = 0;
}

// @fnv 0x005e72c0
BGSHeadPart::BGSHeadPart() : TESForm(), TESFullName(), TESModelTextureSwap(), m_kExtraParts()
{
    SetFormType(ENUM_FORM_ID_HDPT_ID);
    ResetFormData();
}

extern "C" void* __cdecl _alloca(unsigned int);

// @fnv 0x005e7530
// src: XBOX_PDB 0x005e7530
bool BGSHeadPart::Load_005e7530(TESFile* apFile)
{
    // The original caller consumes the full EAX result; the shared accessor returns a byte.
    if (((int(__thiscall*)(TESFile*))ref_00472660)(apFile) != 9)
        return false;

    ((void(__thiscall*)(TESForm*, TESFile*))ref_00485110)(this, apFile);

    int chunkid;
    while ((chunkid = apFile->ReadCurrentForm()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 0x444E424F:
            readOBNDSubRecord(apFile);
            break;
        case 0x4C4C5546:
            TESFullName::LoadFullNameChunk(this, apFile);
            break;
        case 0x4C444F4D:
        case 0x44444F4D:
        case 0x44534F4D:
        case 0x54444F4D:
            // This chunk loader differs from the shared model header's helper at 0x0048a990.
            ((void(__cdecl*)(TESModelTextureSwap*, TESFile*))ref_004892d0)(this, apFile);
            break;
        case 0x53444F4D: {
            unsigned int isize = apFile->GetChunkSize();
            void* pdata = _alloca(isize);
            apFile->GetChunkData(pdata, isize);
            TESModelTextureSwap::ParseTextureSwapData(pdata, isize, apFile->GetFormVersion());
            break;
        }
        case 0x41544144:
            apFile->GetChunkData(&cFlags, 1);
            break;
        case 0x4D414E48: {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            ((void(__thiscall*)(BGSHeadPart*, unsigned int))ref_005e7790)(this, itempint);
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x00624700
// src: XBOX_PDB 0x00624700
void* BGSHeadPart::GetExtraPartList()
{
    return &m_kExtraParts;
}

struct List_005e7480
{
    bool FUN_008256d0();
    BGSHeadPart*& FUN_006815c0();
    List_005e7480* FUN_00726070();
};
// The shared model header does not declare the three-chunk save helper.
extern "C" void ref_0048a520();
void TESForm_AddChunk_3(unsigned int, unsigned char);
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
// @fnv 0x005e7480
void BGSHeadPart::InitializeHeadPart()
{
    BSSimpleList<BGSHeadPart*>* pCurrentElementNext;
    BeginFormRecord();
    TESFullName::Save_00487010();
    ((void(__thiscall*)(TESModelTextureSwap*, unsigned int, unsigned int, unsigned int))ref_0048a520)(
        reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<char*>(this) + 0x24),
        0x4c444f4d, 0x54444f4d, 0x53444f4d);
    TESForm_AddChunk_3(0x41544144, cFlags);
    pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(GetExtraPartList());
    while (pCurrentElementNext && !reinterpret_cast<List_005e7480*>(pCurrentElementNext)->FUN_008256d0())
    {
        unsigned int itempint;
        BGSHeadPart* ppart;
        ppart = reinterpret_cast<List_005e7480*>(pCurrentElementNext)->FUN_006815c0();
        pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(reinterpret_cast<List_005e7480*>(pCurrentElementNext)->FUN_00726070());
        itempint = ppart->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e48, itempint);
    }
    FinishFormRecord();
}

struct List_009e03e0
{
    void RemoveAll();
    bool FUN_008256d0();
    BGSHeadPart*& FUN_006815c0();
    List_009e03e0* FUN_00726070();
};
// @fnv 0x005e78f0
// src: XBOX_PDB 0x005e78f0
void BGSHeadPart::Copy_005e78f0(TESForm* apCopy)
{
    BSSimpleList<BGSHeadPart*>* pCurrentElementNext;
    BGSHeadPart* pSourcePart;
    pSourcePart = dynamic_cast<BGSHeadPart*>(apCopy);
    if (!pSourcePart)
        return;
    TESForm::CopyFrom(apCopy);
    cFlags = pSourcePart->cFlags;
    pCurrentElementNext = 0;
    reinterpret_cast<List_009e03e0*>(GetExtraPartList())->RemoveAll();
    pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(pSourcePart->GetExtraPartList());
    while (pCurrentElementNext && !reinterpret_cast<List_009e03e0*>(pCurrentElementNext)->FUN_008256d0())
    {
        BGSHeadPart* ppart = reinterpret_cast<List_009e03e0*>(pCurrentElementNext)->FUN_006815c0();
        pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(reinterpret_cast<List_009e03e0*>(pCurrentElementNext)->FUN_00726070());
        FUN_005e7790(ppart);
    }
}

struct LH
{
    bool IsInList(BGSHeadPart* const&) const;
    bool FUN_008256d0();
    BGSHeadPart*& FUN_006815c0();
    LH* FUN_00726070();
};
// @fnv 0x005e79a0
// src: XBOX_PDB 0x005e79a0
bool BGSHeadPart::Compare_005e79a0(TESForm* apCompare)
{
    BGSHeadPart* pcomp;
    BSSimpleList<BGSHeadPart*>* pCurrentElementNext;
    pcomp = dynamic_cast<BGSHeadPart*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm::Compare(pcomp))
        return true;
    if ((char)pcomp->cFlags != (char)cFlags)
        return true;
    pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(pcomp->GetExtraPartList());
    while (pCurrentElementNext && !reinterpret_cast<LH*>(pCurrentElementNext)->FUN_008256d0())
    {
        BGSHeadPart* ppart = reinterpret_cast<LH*>(pCurrentElementNext)->FUN_006815c0();
        pCurrentElementNext = reinterpret_cast<BSSimpleList<BGSHeadPart*>*>(reinterpret_cast<LH*>(pCurrentElementNext)->FUN_00726070());
        if (!reinterpret_cast<LH*>(GetExtraPartList())->IsInList(ppart))
            return true;
    }
    return false;
}

void _Deallocate(void*);
struct Deleter
{
    void* Destroy(unsigned int);
};
// Calls FUN_005e73a0 on this, frees this when flags has bit 1 set, and returns this.
// @fnv 0x005e7370
void* Deleter::Destroy(unsigned int flags)
{
    reinterpret_cast<BGSHeadPart*>(this)->BGSHeadPart::~BGSHeadPart();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x005e73a0
BGSHeadPart::~BGSHeadPart()
{
    ClearData_005e7460();
}

// FUN_005e6600: real destructor (__thiscall, no params) of a class with:
//   - a polymorphic base at offset 0 (total size 8, its dtor at 0x5e6470)
//   - a member object at offset 8 whose dtor is 0x5aa1a0
//   - a destructor body calling this->FUN_005e6c60(0)

struct FUN_005e6470
{
    virtual ~FUN_005e6470();
    void SetLabel(int);
    int unk04;
};

struct FUN_005aa1a0
{
    ~FUN_005aa1a0();
};

struct FUN_005e6600 : FUN_005e6470
{
    FUN_005aa1a0 unk08;
    ~FUN_005e6600();
};

// Destructor that calls FUN_005e6c60 with 0 on this object.
// @fnv 0x005e6600
FUN_005e6600::~FUN_005e6600()
{
    this->SetLabel(0);
}

// @fnv 0x005e7a60
// src: COMMUNITY 0x005e7a60
unsigned char BGSHeadPart::IsPlayable_005e7a60()
{
    return (static_cast<signed char>(cFlags) & 1) != 0;
}

struct HeadPartListOperations
{
    void FUN_00470470();
};

// @fnv 0x005e7460
// src: COMMUNITY 0x005e7460
void BGSHeadPart::ClearData_005e7460()
{
    reinterpret_cast<HeadPartListOperations*>(GetExtraPartList())
        ->FUN_00470470();
}

struct HeadPartList
{
    bool IsEmpty();
    BGSHeadPart*& GetItemRef();
    HeadPartList* GetNext();
    void RemoveHead();
    void SetItem(BGSHeadPart* const&);
    void Remove(BGSHeadPart* const&);
};
void LinkFormID(unsigned int*, TESFile*);
TESForm* LookupFormByID(unsigned int);
void FNV_Warning(const char*, ...);
// @fnv 0x005e77b0
// src: XBOX_PDB 0x005e77b0
void BGSHeadPart::InitItem_005e77b0()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    HeadPartList* pIter = reinterpret_cast<HeadPartList*>(GetExtraParts());
    HeadPartList* pPrev = 0;
    while (pIter && !pIter->IsEmpty())
    {
        unsigned int auiFormId = (unsigned int)pIter->GetItemRef();
        LinkFormID(&auiFormId, GetFile(-1));
        BGSHeadPart* m_pModel = dynamic_cast<BGSHeadPart*>(LookupFormByID(auiFormId));
        if (!m_pModel)
        {
            FNV_Warning("Unable to find extra part (%08X) for head part '%s' (%08X).", auiFormId, GetName(),
                        GetFormID());
            if (pPrev)
            {
                pPrev->Remove((BGSHeadPart*)auiFormId);
                pIter = pPrev->GetNext();
            }
            else
            {
                pIter->RemoveHead();
            }
        }
        else
        {
            pIter->SetItem(m_pModel);
            pPrev = pIter;
            pIter = pIter->GetNext();
        }
    }
    SetInitializationState(1);
}
