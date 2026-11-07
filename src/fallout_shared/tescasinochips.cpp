#include "../../include/TESTexture.h"
// fallout_shared/tescasinochips.cpp: TESCasinoChips, TESCasino, IntFieldContainer, CasinoAccess and more (24 functions)

#include "tescasinochips_packet.h"
#include "../../include/GO.h"
#include "../../include/EndianConvertibleData.h"
#include <malloc.h>

// Constructor: sets the form type to ENUM_FORM_ID_CHIP_ID and clears the object's data.
// @fnv 0x00503bd0
TESCasinoChips::TESCasinoChips()
{
    SetFormType(ENUM_FORM_ID_CHIP_ID);
    ClearData();
}

// @fnv 0x00503e70
void TESCasinoChips::ClearData()
{
    m_kPrimaryString.Set(0, 0);
}

// If the form is not already initialized, initializes the destructible object, model texture swap and pickup/putdown sounds components, then marks it initialized.
// @fnv 0x00503e90
void TESCasinoChips::InitItem()
{
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Reads a TESFile record: checks form type 108, loads the record header, then dispatches chunk handlers until no more chunks, returning true.
// @fnv 0x00503ef0
bool TESCasinoChips::LoadForm(TESFile* apFile)
{
    unsigned char type = apFile->GetTESForm();
    if (type != 108)
        return false;
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    int chunk;
    while (chunk = apFile->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 512);
            SetEditorID_AtRuntime(b);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, apFile);
            break;
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x53444f4d: {
            char* swapBuffer;
            {
                unsigned int size = apFile->GetChunkSize();
                swapBuffer = (char*)_alloca(size);
                apFile->GetChunkData(swapBuffer, size);
                ParseTextureSwapData(swapBuffer, size, static_cast<TESFileFormVersion*>(apFile)->GetFormVersion());
            }
            break;
        }
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(static_cast<TESIcon*>(this), apFile);
            break;
        case 0x4f43494d:
            BGSMessageIcon::LoadMessageIconChunk(this, apFile);
            break;
        case 0x44545344:
        case 0x54534544:
            BGSDestructibleObjectForm::LoadDestructibleData(this, apFile);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            apFile->GetChunkData(&id);
            SetPickupSound((TESSound*)id);
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            apFile->GetChunkData(&id);
            SetPutdownSound((TESSound*)id);
            break;
        }
        case 0x4d414e4f: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 0);
            m_kPrimaryString.Set(b, 0);
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x005048d0
bool TESCasino::LoadForm(TESFile* apFile)
{
    unsigned char type = apFile->GetTESForm();
    if (type != 109)
        return false;
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    int unused2 = 0;
    int model = 7;
    int icon2 = 0;
    int chunk = 0;
    int unused1 = 0;
    int icon;
    while (icon = apFile->GetChunkID())
    {
        switch (icon)
        {
        case 0x44494445: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 512);
            SetEditorID_AtRuntime(b);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, apFile);
            break;
        case 0x4c444f4d: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 0);
            m_kModelTextureSwaps[unused2].SetModelFilePath(b);
            TESModel::LoadTextureSwapData(&m_kModelTextureSwaps[unused2], apFile);
            ++unused2;
            break;
        }
        case 0x32444f4d: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 0);
            m_kModelTextureSwaps[7].SetModelFilePath(b);
            TESModel::LoadTextureSwapData(&m_kModelTextureSwaps[7], apFile);
            break;
        }
        case 0x33444f4d: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 0);
            m_kModelTextureSwaps[8].SetModelFilePath(b);
            TESModel::LoadTextureSwapData(&m_kModelTextureSwaps[8], apFile);
            break;
        }
        case 0x34444f4d: {
            char* b = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(b, 0);
            m_kModelTextureSwaps[9].SetModelFilePath(b);
            TESModel::LoadTextureSwapData(&m_kModelTextureSwaps[9], apFile);
            break;
        }
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(&m_kIconTextures[icon2], apFile);
            ++icon2;
            break;
        case 0x324f4349:
            TESTextureLoader::ReadTextureData(&m_kIconTextures[model], apFile);
            ++model;
            break;
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(apFile, &data, 56);
            if (apFile->IsEndianConversionRequired())
                data.Endian();
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

struct FUN_00504480 : public TESForm, public TESFullName
{
    TESModelTextureSwap unk24[10];
    TESTexture unk164[11];

    FUN_00504480();
    virtual ~FUN_00504480();
};

// Initializes the form by setting its form type to 0x6d.
// @fnv 0x00504480
FUN_00504480::FUN_00504480()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x6d));
}

struct FUN_005046e0_shell : public TESCasino
{
    void TESCasino_InitItem();
};

// @fnv 0x005046e0
// src: COMMUNITY 0x005046e0
void FUN_005046e0_shell::TESCasino_InitItem()
{
    TESForm::RemapFormIDForFile(*(unsigned int*)((char*)this + 0x214), GetFile(-1));
}

void __cdecl Deallocate(void*);

struct TESCasinoChips_shell
{
    void __thiscall FUN_00503d40();
    void* __thiscall Destroy(unsigned int flags);
};

// Calls FUN_00503d40, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00503d10
void* __thiscall TESCasinoChips_shell::Destroy(unsigned int flags)
{
    FUN_00503d40();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

struct FUN_00504620_shell
{
    void __thiscall ClearFields();
};

// Zeroes 0x38 bytes starting at offset 0x1e8 of this object via memset.
// @fnv 0x00504620
void __thiscall FUN_00504620_shell::ClearFields()
{
    memset(this + 0x1e8, 0, 0x38);
}

struct FUN_00504e00_shell
{
    void* __thiscall TESCasino_GetModel(int index);
};

// @fnv 0x00504e00
// src: XBOX_PDB 0x00504e00
void* __thiscall FUN_00504e00_shell::TESCasino_GetModel(int index)
{
    return (void**)((char*)this + 0x24 + index * 32);
}

struct FUN_00504e20_shell
{
    unsigned char _pad[0x164];
    unsigned char m_aiIndexedValues[0x200];
    unsigned char* __thiscall TESCasino_GetNthSlotReel(int idx);
};

// @fnv 0x00504e20
// src: COMMUNITY 0x00504e20
unsigned char* __thiscall FUN_00504e20_shell::TESCasino_GetNthSlotReel(int aiIndex)
{
    return &m_aiIndexedValues[aiIndex * 0xc];
}

extern "C" TESForm* __cdecl GetFormByID(unsigned int);

struct FUN_00504e40_shell
{
    unsigned int m_0218;
    TESForm* __thiscall TESCasino_GetQuest();
};

// @fnv 0x00504e40
// src: XBOX_PDB 0x00504e40
TESForm* __thiscall FUN_00504e40_shell::TESCasino_GetQuest()
{
    return GetFormByID(*(unsigned int*)((char*)this + 0x218));
}

struct FUN_00504e60_shell
{
    char* TESCasino_GetData();
};

// @fnv 0x00504e60
// src: XBOX_PDB 0x00504e60
char* FUN_00504e60_shell::TESCasino_GetData()
{
    return reinterpret_cast<char*>(this) + 0x1E8;
}

void __cdecl _Deallocate(void*);
struct S504540
{
    void FUN_00504570();
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00504540
void* S504540::DestroyIfFlagged(unsigned int flags)
{
    FUN_00504570();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00504cc0 {
struct ModelSrc_504cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const char* GetModelFilePath();
};
struct ModelElem_504cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void SetModelFilePath(const char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct FNStub
{
    const char* GetFullName();
};
struct FullNameEx
{
    void SetFullName(const char*);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct FUN_00504e00_shell
{
    void* TESCasino_GetModel(int);
};
struct FUN_00504e20_shell
{
    unsigned char* TESCasino_GetNthSlotReel(int);
};
struct FUN_00504e40_shell
{
    TESForm* TESCasino_GetQuest();
};
struct FUN_00504e60_shell
{
    char* TESCasino_GetData();
};
int __fastcall FNV_GetFormType(TESForm*);
// 0x004f15a0 stores its argument byte at +4 (the form type here); the same folded code is BSSoundHandle::SetAssumeSuccess.
struct FormTypeSetter_4f15a0
{
    void SetFormType(int);
};

struct Casino_504cc0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    ModelElem_504cc0 m_kModelTextureSwaps[10];
    FullNameEx m_kIconTextures[11];
    // Casino record at +0x1E8 is 0x38 bytes with its form ID at +0x30, matching EndianConvertibleData.
    EndianConvertibleData data;
    void CopyFromCasino(TESForm* apCopy);
};

// Copies model names, full names and data from a TESCasino into this object, then sets the form type.
// @fnv 0x00504cc0
void Casino_504cc0::CopyFromCasino(TESForm* apCopy)
{
    TESCasino* pSourceCasino = dynamic_cast<TESCasino*>(apCopy);
    if (!pSourceCasino)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pSourceCasino);
    for (int i = 0; i < 10; i++)
    {
        m_kModelTextureSwaps[i].SetModelFilePath(
            ((ModelSrc_504cc0*)((FUN_00504e00_shell*)pSourceCasino)->TESCasino_GetModel(i))->GetModelFilePath());
    }
    for (int i = 0; i < 11; i++)
    {
        m_kIconTextures[i].SetFullName(((FNStub*)((FUN_00504e20_shell*)pSourceCasino)->TESCasino_GetNthSlotReel(i))->GetFullName());
    }
    if (((FUN_00504e40_shell*)pSourceCasino)->TESCasino_GetQuest())
        data.uiChunkType = ((FUN_00504e40_shell*)pSourceCasino)->TESCasino_GetQuest()->GetFormID();
    else
        data.uiChunkType = 0;
    data = *(EndianConvertibleData*)((FUN_00504e60_shell*)pSourceCasino)->TESCasino_GetData();
    ((fnv_00504cc0::FormTypeSetter_4f15a0*)this)->SetFormType(fnv_00504cc0::FNV_GetFormType(pSourceCasino));
}
}  // namespace fnv_00504cc0

extern void* vftable_TESCasinoChips;

struct FUN_00503d40_shell : public TESBoundObject,
                            public TESFullName,
                            public TESModelTextureSwap,
                            public TESIcon,
                            public BGSMessageIcon,
                            public TESValueForm,
                            public BGSDestructibleObjectForm,
                            public BGSPickupPutdownSounds
{
    BSStringT<char> m_kPrimaryString;

    ~FUN_00503d40_shell();
};

// Destructor that calls TESCasinoChips::ClearData on this object to release its data.
// @fnv 0x00503d40
FUN_00503d40_shell::~FUN_00503d40_shell()
{
    reinterpret_cast<TESCasinoChips*>(this)->TESCasinoChips::ClearData();
}

struct FUN_004855a0
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

struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};

struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};

struct DoorPart68
{
    void FUN_00477f20();
};

struct FUN_0047b560_holder
{
    void LogFormIDs();
};

struct S7010
{
    unsigned int Length();
};

struct FUN_00485680
{
    void M();
};

struct FUN_00504280_shell
{
    void TESCasinoChips_Save();
};

void TESForm_AddChunkArray(unsigned int, void*, unsigned int);

// @fnv 0x00504280
// src: XBOX_PDB 0x00504280
void FUN_00504280_shell::TESCasinoChips_Save()
{
    reinterpret_cast<struct FUN_004855a0*>(this)->M();
    reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x30)->Save_00487010();
    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x3c)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x5c)->TESTexture_Save(0x4e4f4349);
    reinterpret_cast<FUN_0047a240_shell*>(reinterpret_cast<char*>(this) + 0x68)->FUN_0047a240(0x4f43494d);
    reinterpret_cast<DoorPart68*>(reinterpret_cast<char*>(this) + 0x80)->FUN_00477f20();
    reinterpret_cast<FUN_0047b560_holder*>(reinterpret_cast<char*>(this) + 0x88)->LogFormIDs();

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x94)->Length())
    {
        TESForm_AddChunkArray(0x4d414e4f,
                     reinterpret_cast<void*>(
                         reinterpret_cast<const GO*>(reinterpret_cast<char*>(this) + 0x94)->operator unsigned int()),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x94)->Length() + 1);
    }

    reinterpret_cast<struct FUN_00485680*>(this)->M();
}

extern "C" void* __cdecl memset(void* destination, int value, size_t count);

struct FUN_00504640_shell
{
    struct Model
    {
        virtual void Init()
        {}
        char padding[28];
    };

    struct Texture
    {
        virtual void Init()
        {}
        char padding[8];
    };

    char base[0x24];
    Model m_kModelTextureSwaps[10];
    Texture m_kIconTextures[11];
    char data[0x38];

    void TESCasino_SetDefault();
};

// Zeroes the data block, then calls Init on all 10 Model entries and all 11 Texture entries.
// @fnv 0x00504640
// src: COMMUNITY 0x00504640
void FUN_00504640_shell::TESCasino_SetDefault()
{
    memset(this->data, 0, sizeof(this->data));

    int i;
    for (i = 0; i < 10; i++)
        this->m_kModelTextureSwaps[i].Init();

    {
        int i;
        for (i = 0; i < 11; i++)
            this->m_kIconTextures[i].Init();
    }
}

namespace fnv_00504710 {
struct FUN_004855a0
{
    void M();
};

struct DoorPart30
{
    void Save_00487010();
};

struct FUN_00485e00_shell
{
    void TESForm___SaveData(int, int);
};

struct DoorPart3c
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};



struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};

struct FUN_00485680
{
    void M();
};

bool _FUN_00401500();

struct FUN_00504710_shell : public TESCasino
{
    void TESCasino_Save();
};

// @fnv 0x00504710
// src: XBOX_PDB 0x00504710
void FUN_00504710_shell::TESCasino_Save()
{
    reinterpret_cast<struct FUN_004855a0*>(this)->M();
    reinterpret_cast<DoorPart30*>(reinterpret_cast<unsigned char*>(this) + 0x18)->Save_00487010();

    if (_FUN_00401500())
    {
        reinterpret_cast<EndianConvertibleData*>(reinterpret_cast<unsigned char*>(this) + 0x1E8)->Endian();
    }

    reinterpret_cast<FUN_00485e00_shell*>(this)->TESForm___SaveData(
        reinterpret_cast<int>(reinterpret_cast<EndianConvertibleData*>(reinterpret_cast<unsigned char*>(this) + 0x1E8)),
        0x38);

    if (_FUN_00401500())
    {
        reinterpret_cast<EndianConvertibleData*>(reinterpret_cast<unsigned char*>(this) + 0x1E8)->Endian();
    }

    {
        int i;
        for (i = 0; i < 8; ++i)
        {
            if (reinterpret_cast<TESTexture*>(reinterpret_cast<unsigned char*>(this) + 0x24 + i * 0x20)
                    ->GetTextureNameLength())
            {
                reinterpret_cast<DoorPart3c*>(reinterpret_cast<unsigned char*>(this) + 0x24 + i * 0x20)
                    ->ProcessAndFreeData(0x4C444F4D, 0x54444F4D, 0x53444F4D);
            }
        }
    }

    if (reinterpret_cast<TESTexture*>(reinterpret_cast<unsigned char*>(this) + 0x104)->GetTextureNameLength())
    {
        reinterpret_cast<DoorPart3c*>(reinterpret_cast<unsigned char*>(this) + 0x104)
            ->ProcessAndFreeData(0x32444F4D, 0x54444F4D, 0x53444F4D);
    }

    if (reinterpret_cast<TESTexture*>(reinterpret_cast<unsigned char*>(this) + 0x124)->GetTextureNameLength())
    {
        reinterpret_cast<DoorPart3c*>(reinterpret_cast<unsigned char*>(this) + 0x124)
            ->ProcessAndFreeData(0x33444F4D, 0x54444F4D, 0x53444F4D);
    }

    if (reinterpret_cast<TESTexture*>(reinterpret_cast<unsigned char*>(this) + 0x144)->GetTextureNameLength())
    {
        reinterpret_cast<DoorPart3c*>(reinterpret_cast<unsigned char*>(this) + 0x144)
            ->ProcessAndFreeData(0x34444F4D, 0x54444F4D, 0x53444F4D);
    }

    {
        int i;
        for (i = 0; i < 7; ++i)
        {
            reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<unsigned char*>(this) + 0x164 + i * 0x0C)
                ->TESTexture_Save(0x4E4F4349);
        }
    }

    {
        int i;
        for (i = 7; i < 0x0B; ++i)
        {
            reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<unsigned char*>(this) + 0x164 + i * 0x0C)
                ->TESTexture_Save(0x324F4349);
        }
    }

    reinterpret_cast<struct FUN_00485680*>(this)->M();
}
}  // namespace fnv_00504710

struct FUN_00504340_shell : public TESCasinoChips
{
    void CopyBoundObject(TESForm* pkForm);
    unsigned int GetChipsFormType();
    void SetChipsFormType(unsigned int eType);
    void CopyFromChipsForm(TESForm* pkForm);
};

// @fnv 0x00504340
void FUN_00504340_shell::CopyFromChipsForm(TESForm* pkForm)
{
    TESCasinoChips* pkChips = dynamic_cast<TESCasinoChips*>(pkForm);
    if (!pkChips)
        return;
    CopyBoundObject(pkChips);
    SetChipsFormType(static_cast<FUN_00504340_shell*>(pkChips)->GetChipsFormType());
    m_kPrimaryString.Set(pkChips->m_kPrimaryString.String(), 0);
}

struct EndianFlag
{
    bool b;
};

void __cdecl SwapDword(int*, EndianFlag = EndianFlag());

struct IntFieldContainer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;

    void SwapAllFields();
};

// Byte-swaps each of the 13 int fields from unk00 through unk30 by calling SwapDword on each.
// @fnv 0x004faaa0
void IntFieldContainer::SwapAllFields()
{
    SwapDword(&unk00);
    SwapDword(&unk04);
    SwapDword(&unk08);
    SwapDword(&unk0c);
    SwapDword(&unk10);
    SwapDword(&unk14);
    SwapDword(&unk18);
    SwapDword(&unk1c);
    SwapDword(&unk20);
    SwapDword(&unk24);
    SwapDword(&unk28);
    SwapDword(&unk2c);
    SwapDword(&unk30);
}

// Structural layout informed by a prior contributor's unverified October 22, 2026 attempt.
// This destructor reconstruction and exact-match check are independently verified.
struct Primary_504570
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    unsigned int a04, a08, a0c, a10, a14;
    void FUN_00483630();
    ~Primary_504570()
    {
        FUN_00483630();
    }
};
struct Secondary_504570
{
    virtual void v00();
    unsigned int b04;
    void BSStringT_Thunk();
    ~Secondary_504570()
    {
        BSStringT_Thunk();
    }
};
struct Elem32_504570
{
    int a0, a4, a8, ac, a10, a14, a18, a1c;
    void FUN_0048a490();
    ~Elem32_504570()
    {
        FUN_0048a490();
    }
};
struct Elem12_504570
{
    int a0, a4, a8;
    void FUN_0048e2e0();
    ~Elem12_504570()
    {
        FUN_0048e2e0();
    }
};
struct FUN_00504570_cls : Primary_504570, Secondary_504570
{
    unsigned int unk20;
    Elem32_504570 models[10];
    Elem12_504570 textures[11];
    void ClearFields();
    ~FUN_00504570_cls();
};
// @fnv 0x00504570
FUN_00504570_cls::~FUN_00504570_cls()
{
    ClearFields();
}

#include <string.h>
int BSstrcmp(const char*, const char*);
struct TextureAccess : TESTexture
{
    const char* TESModel_GetModel();
};
struct CasinoAccess : TESCasino
{
    TESTexture* TESCasino_GetNthSlotReel(int);
    TESModelTextureSwap* TESCasino_GetModel(int);
    TESForm* TESCasino_GetQuest();
    void* TESCasino_GetData();
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESCasino_Compare(TESForm* form);
};
// Returns true when the cast fails or any subsequent comparison check returns nonzero.
// @fnv 0x00504e80
// src: XBOX_PDB 0x00504e80
bool CasinoAccess::TESCasino_Compare(TESForm* form)
{
    TESCasino* other = dynamic_cast<TESCasino*>(form);
    if (!other)
        return true;
    if (TESForm_CompareAllComponents(other))
        return true;
    for (int i = 0; i < 11; i++)
    {
        if (BSstrcmp(reinterpret_cast<TextureAccess*>(&m_kIconTextures[i])->TESModel_GetModel(),
                         reinterpret_cast<TextureAccess*>(reinterpret_cast<CasinoAccess*>(other)->TESCasino_GetNthSlotReel(i))
                             ->TESModel_GetModel()))
            return true;
    }
    for (int j = 0; j < 10; j++)
    {
        if (BSstrcmp(m_kModelTextureSwaps[j].GetModelFilePath(),
                         reinterpret_cast<CasinoAccess*>(other)->TESCasino_GetModel(j)->GetModelFilePath()))
            return true;
    }
    if (GetFormByID(data.uiChunkType) != reinterpret_cast<CasinoAccess*>(other)->TESCasino_GetQuest())
        return true;
    if (memcmp(&data, reinterpret_cast<CasinoAccess*>(other)->TESCasino_GetData(), 0x38))
        return true;
    return false;
}

struct CasinoChipFormCompareCall
{
    bool TESForm_CompareAllComponents(::TESForm*);
};
struct CasinoChipStringCompareCall
{
    int CompareString(const ::BSStringT<char>*, bool);
};

struct CasinoChipCompareView : public ::TESCasinoChips
{
    bool TESCasinoChips_Compare(::TESForm* form);
};

// @fnv 0x005043b0
// src: XBOX_PDB 0x005043b0
bool CasinoChipCompareView::TESCasinoChips_Compare(::TESForm* form)
{
    ::TESCasinoChips* chip = dynamic_cast< ::TESCasinoChips*>(form);
    if (!chip)
        return true;
    if (reinterpret_cast<CasinoChipFormCompareCall*>(this)->TESForm_CompareAllComponents(chip))
        return true;
    if (reinterpret_cast<CasinoChipStringCompareCall*>(&m_kPrimaryString)->CompareString(&chip->m_kPrimaryString, true))
        return true;
    return false;
}
