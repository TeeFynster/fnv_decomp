// fallout_shared/tesobjectcont.cpp: TESObjectCONT (9 functions)

#include "../../include/PlayerMover.h"
#include "tesobjectcont_decls.h"
#include "tesobjectcont_types_TESObjectCONT.h"
#include "tesobjectcont_match_decls.h"
#include <new>
#include <string.h>

// @fnv 0x00516330
void TESObjectCONT::ResetFormData()
{
    Data.m_cValue = 0;
    m_pOpenSound = 0;
    m_pSecondarySound = 0;
    pLoopingSound = 0;
}

// @fnv 0x005160f0
TESObjectCONT::TESObjectCONT()
{
    *reinterpret_cast<void**>(this) = &kVtbl_TESObjectCONT;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x30) = &DAT_0102ae9c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x3C) = &DAT_0102ae88;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x48) = &DAT_0102ae64;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x68) = &DAT_0102ae50;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x74) = &DAT_0102ae3c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x7C) = &DAT_0102ae28;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x84) = &DAT_0102ae18;
    SetFormType((ENUM_FORM_ID)0x1B);
    ResetFormData();
}

// @fnv 0x00516370
void TESObjectCONT::InitItem()
{
    unsigned int soundFormID;

    if (TESForm::GetInitialized())
        return;

    reinterpret_cast<TESObjectCONT_TESScriptableInitCall*>(reinterpret_cast<unsigned char*>(this) + 0x68)
        ->InitItem(this);
    reinterpret_cast<TESContainer*>(reinterpret_cast<unsigned char*>(this) + 0x30)->InitItem(this);
    reinterpret_cast<BGSDestructibleObjectForm*>(reinterpret_cast<unsigned char*>(this) + 0x7C)->InitItem(this);
    reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<unsigned char*>(this) + 0x48)->InitItem(this);

    soundFormID = (unsigned int)m_pOpenSound;
    if (soundFormID != 0)
    {
        TESForm::RemapFormIDForFile(soundFormID, GetFile(-1));
        m_pOpenSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(soundFormID));
        if (!m_pOpenSound)
            Warning("MASTERFILE: Could not find open sound (%08X) for container '%s' (%08X).", soundFormID, GetName(),
                    GetFormID());
    }

    soundFormID = (unsigned int)m_pSecondarySound;
    if (soundFormID != 0)
    {
        TESForm::RemapFormIDForFile(soundFormID, GetFile(-1));
        m_pSecondarySound = dynamic_cast<TESSound*>(TESForm::GetFormByID(soundFormID));
        if (!m_pSecondarySound)
            Warning("MASTERFILE: Could not find open sound (%08X) for container '%s' (%08X).", soundFormID, GetName(),
                    GetFormID());
    }

    soundFormID = (unsigned int)pLoopingSound;
    if (soundFormID != 0)
    {
        TESForm::RemapFormIDForFile(soundFormID, GetFile(-1));
        pLoopingSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(soundFormID));
        if (!pLoopingSound)
            Warning("MASTERFILE: Could not find pLoopingSound (%08X) for container '%s' (%08X).", soundFormID,
                    GetName(), GetFormID());
    }

    SetInitializationState(true);
}

// Reads a TESObjectCONT record: checks the form type, loads the record header, then dispatches each chunk to its loader until the chunk list ends.
// @fnv 0x00516580
bool TESObjectCONT::LoadForm(TESFile* file)
{
    unsigned char formType;
    int chunkID;

    formType = file->GetTESForm();
    if (formType != 0x1B)
        return false;

    LoadRecordHeader(file);
    SetInitializationState(false);

    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorIDData = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorIDData, 0x200);
            SetEditorID_AtRuntime(editorIDData);
            break;
        }

        case 0x444E424F:
            readOBNDSubRecord(file);
            break;

        case 0x4C4C5546:
            TESFullNameLoader::LoadFullNameChunk(
                this ? reinterpret_cast<TESFullName*>(reinterpret_cast<unsigned char*>(this) + 0x3C) : 0, file);
            break;

        case 0x4C444F4D:
        case 0x44444F4D:
        case 0x44534F4D:
        case 0x54444F4D:
            TESModel::LoadModelData(
                this ? reinterpret_cast<TESModel*>(reinterpret_cast<unsigned char*>(this) + 0x48) : 0, file);
            break;

        case 0x53444F4D: {
            unsigned int textureSwapSize = file->GetChunkSize();
            char* textureSwapData = (char*)_alloca(textureSwapSize);
            file->GetChunkData(textureSwapData, textureSwapSize);
            reinterpret_cast<TESModelTextureSwap*>(reinterpret_cast<unsigned char*>(this) + 0x48)
                ->ParseTextureSwapData(textureSwapData, textureSwapSize,
                                       reinterpret_cast<TESFileFormVersion*>(file)->GetFormVersion());
            break;
        }

        case 0x49524353: {
            unsigned int scriptFormID = 0;
            file->GetChunkData(&scriptFormID);
            reinterpret_cast<CombatProcedure*>(reinterpret_cast<unsigned char*>(this) + 0x68)
                ->Initialize(reinterpret_cast<CombatController*>(scriptFormID));
            reinterpret_cast<TESObjectCONT_TESScriptableInitCall*>(reinterpret_cast<unsigned char*>(this) + 0x68)
                ->InitItem(this);
            break;
        }

        case 0x44454F43:
        case 0x4F544E43: {
            switch (file->GetChunkID())
            {
            case 0x4F544E43: {
                CNTOChunkData cntoItem;
                memset(&cntoItem, 0, 8);
                file->GetChunkData(&cntoItem, 8);
                if (file->IsEndianConversionRequired())
                    cntoItem.TwoValues_Endian();
                DAT_011c9348 = reinterpret_cast<ContainerItemExtraOwner*>(
                    reinterpret_cast<TESContainer*>(reinterpret_cast<unsigned char*>(this) + 0x30)
                        ->AddContainerObject(&cntoItem));
                break;
            }
            case 0x44454F43:
                if (DAT_011c9348)
                {
                    DAT_011c9348->item = new ContainerItemExtra;
                    DAT_011c9348->item->Load(file);
                    DAT_011c9348 = 0;
                }
                break;
            }
            break;
        }

        case 0x41544144:
            ReadTypedData(file, &Data, 1);
            break;

        case 0x44545344:
        case 0x54534544:
            BGSDestructibleObjectForm::LoadDestructibleData(
                this ? reinterpret_cast<BGSDestructibleObjectForm*>(reinterpret_cast<unsigned char*>(this) + 0x7C) : 0,
                file);
            break;

        case 0x4D414E53: {
            unsigned int snamFormID = 0;
            file->GetChunkData(&snamFormID);
            reinterpret_cast<EffectSetting*>(this)->SetAreaSound(reinterpret_cast<TESSound*>(snamFormID));
            break;
        }

        case 0x4D414E51: {
            unsigned int qnamFormID = 0;
            file->GetChunkData(&qnamFormID);
            SetImpactDataSet_004fb0b0(qnamFormID);
            break;
        }

        case 0x4D414E52: {
            unsigned int rnamFormID = 0;
            file->GetChunkData(&rnamFormID);
            reinterpret_cast<BGSTalkingActivator*>(this)->SetVoiceType(reinterpret_cast<BGSVoiceType*>(rnamFormID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

struct S1
{
    void FUN_00516240();
};
void _Deallocate(void*);
struct S2
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00516210
void* S2::DestroyIfFlagged(unsigned int flags)
{
    ((S1*)this)->FUN_00516240();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00516b60_shell
{
    void TESForm_CopyAllComponents(TESForm*);
    unsigned char* GetTESChallengeList();
    TESSound* GetAreaSound();
    void SetAreaSound(TESSound*);
    TESObjectREFR* GetTempRef();
    void SetImpactDataSet_004fb0b0(TESObjectREFR*);
    BGSVoiceType* GetActorStateFlags();
    void SetVoiceType(BGSVoiceType*);
    void CopyFromContainer(TESForm* apCopy);
};
// @fnv 0x00516b60
void FUN_00516b60_shell::CopyFromContainer(TESForm* apCopy)
{
    TESObjectCONT* cont = dynamic_cast<TESObjectCONT*>(apCopy);
    if (!cont)
        return;
    ((FUN_00516b60_shell*)this)->TESForm_CopyAllComponents(apCopy);
    *(unsigned char*)((char*)this + 0x98) = *((FUN_00516b60_shell*)cont)->GetTESChallengeList();
    ((FUN_00516b60_shell*)this)->SetAreaSound(((FUN_00516b60_shell*)cont)->GetAreaSound());
    ((FUN_00516b60_shell*)this)->SetImpactDataSet_004fb0b0(((FUN_00516b60_shell*)cont)->GetTempRef());
    ((FUN_00516b60_shell*)this)->SetVoiceType(((FUN_00516b60_shell*)cont)->GetActorStateFlags());
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};
struct FUN_00516bf0_shell
{
    TESObjectREFR* GetTempRef();
};
struct FUN_008ce390_shell
{
    TESSound* GetAreaSound();
};
struct FUN_00461150_shell
{
    BSSimpleList<TESObjectREFR*>* GetTESChallengeList();
};
struct FUN_00516c10_shell
{
    signed char c98;
    bool IsNotMatchingContainer(TESForm* apCompare);
};
// @fnv 0x00516c10
bool FUN_00516c10_shell::IsNotMatchingContainer(TESForm* apCompare)
{
    TESObjectCONT* pComp = dynamic_cast<TESObjectCONT*>(apCompare);
    if (!pComp)
        return true;
    if (((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(pComp))
        return true;
    if (*(signed char*)((char*)this + 0x98) != *(signed char*)((FUN_00461150_shell*)pComp)->GetTESChallengeList())
        return true;
    if (((FUN_008ce390_shell*)this)->GetAreaSound() != ((FUN_008ce390_shell*)pComp)->GetAreaSound())
        return true;
    if (((FUN_00516bf0_shell*)this)->GetTempRef() != ((FUN_00516bf0_shell*)pComp)->GetTempRef())
        return true;
    if (((PlayerMover*)this)->GetActorStateFlags() != ((PlayerMover*)pComp)->GetActorStateFlags())
        return true;
    return false;
}

struct FUN_00516a20_shell
{
    void TESObjectCONT_SaveAlt();
};

struct FUN_00481b40_shell
{
    void FUN_00481b40();
};

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct DoorPart30
{
    void Save_00487010();
};

struct DoorPart3c
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

struct DoorPart5c
{
    void Save_0048cca0();
};

struct DoorPart68
{
    void FUN_00477f20();
};

struct FUN_00485e00_shell
{
    void TESForm___SaveData(TESForm*, int);
};

bool _FUN_00401500();
void _FUN_00485910(unsigned int, unsigned int);

// @fnv 0x00516a20
// src: COMMUNITY 0x00516a20
void FUN_00516a20_shell::TESObjectCONT_SaveAlt()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();
    reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x3c)->Save_00487010();
    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x48)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<DoorPart5c*>(reinterpret_cast<char*>(this) + 0x68)->Save_0048cca0();
    reinterpret_cast<FUN_00481b40_shell*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00481b40();
    reinterpret_cast<DoorPart68*>(reinterpret_cast<char*>(this) + 0x7c)->FUN_00477f20();

    if (_FUN_00401500())
    {
        reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) + 0x98)->TESForm::ClearData();
    }

    reinterpret_cast<FUN_00485e00_shell*>(this)->TESForm___SaveData(
        reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) + 0x98), 1);

    if (_FUN_00401500())
    {
        reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) + 0x98)->TESForm::ClearData();
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x8c))
    {
        {
            unsigned int itempint = (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x8c))->GetFormID();
            _FUN_00485910(0x4d414e53, itempint);
        }
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x90))
    {
        {
            unsigned int itempint = (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x90))->GetFormID();
            _FUN_00485910(0x4d414e51, itempint);
        }
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x94))
    {
        {
            unsigned int itempint = (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x94))->GetFormID();
            _FUN_00485910(0x4d414e52, itempint);
        }
    }

    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct PrimaryBase_b4857
{
    virtual ~PrimaryBase_b4857();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};

struct SecondaryA_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    ~SecondaryA_b4857();
};

struct SecondaryB_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    ~SecondaryB_b4857();
};

struct SecondaryC_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    ~SecondaryC_b4857();
};

struct SecondaryD_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
};

struct SecondaryE_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    ~SecondaryE_b4857();
};

struct SecondaryF_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    ~SecondaryF_b4857();
};

struct SecondaryG_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
};

class FUN_00516240 : public PrimaryBase_b4857,
                     public SecondaryA_b4857,
                     public SecondaryB_b4857,
                     public SecondaryC_b4857,
                     public SecondaryD_b4857,
                     public SecondaryE_b4857,
                     public SecondaryF_b4857,
                     public SecondaryG_b4857
{
  public:
    virtual ~FUN_00516240();
};

// Empty destructor for a class inheriting from multiple base classes.
// @fnv 0x00516240
FUN_00516240::~FUN_00516240()
{}
