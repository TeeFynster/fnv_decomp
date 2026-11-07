// fallout_shared/magic/ingredientitem.cpp: IngredientItem, LCItem (14 functions)

#include "ingredientitem.h"

// @fnv 0x00409c40
void IngredientItem::ResetFormData()
{
    data.m_iEffectIndex = -1;
    data.m_ucEntryType = 0;
    IngredientItem::InitializeComponent();
}

// @fnv 0x00409d40
void IngredientItem::InitItem()
{
    if (IsFormInitialized())
    {
        return;
    }
    TESScriptableForm::InitItem((TESForm*)this);
    BGSDestructibleObjectForm::InitItem((TESForm*)this);
    TESModelTextureSwap::InitItem((TESForm*)this);
    MagicItemObject::InitItem();
}

struct FUN_00409a30_shell
{
    bool IngredientItem_GetFlag(unsigned int aFlag);
};

// Returns true if the byte at offset 0xa0 has any of the bits in aFlag set.
// @fnv 0x00409a30
// src: COMMUNITY 0x00409a30
bool FUN_00409a30_shell::IngredientItem_GetFlag(unsigned int aFlag)
{
    return (reinterpret_cast<unsigned char*>(this)[0xa0] & aFlag) != 0;
}

struct BipedModelForm
{
    void __thiscall Endian(void);
};

struct FUN_0040a0f0_shell : BipedModelForm
{
    void __thiscall EndianAtOffset9C(void);
};

// @fnv 0x0040a0f0
void __thiscall FUN_0040a0f0_shell::EndianAtOffset9C(void)
{
    ((BipedModelForm*)((char*)this + 0x9c))->Endian();
}

struct FUN_00409a10_shell : public FUN_00409a30_shell
{
    void IngredientItem_IsFood();
};
// @fnv 0x00409a10
// src: COMMUNITY 0x00409a10
void FUN_00409a10_shell::IngredientItem_IsFood()
{
    ((FUN_00409a30_shell*)((char*)this - 0x3C))->IngredientItem_GetFlag(2);
}

struct FUN_00409a50_shell : FUN_00409a30_shell
{
    bool IngredientItem_EffectItemList_GetIngredientFlag1();
};

// @fnv 0x00409a50
// src: COMMUNITY 0x00409a50
bool FUN_00409a50_shell::IngredientItem_EffectItemList_GetIngredientFlag1()
{
    return !IngredientItem_GetFlag(1);
}

void _Deallocate(void*);
struct FUN_00409b10_shell
{
    void FUN_00409b40();
    void* FUN_00409b10(unsigned int);
};
// Calls FUN_00409b40, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00409b10
void* FUN_00409b10_shell::FUN_00409b10(unsigned int flags)
{
    FUN_00409b40();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct S_00477f20
{
    void __thiscall FUN_00477f20();
};
struct S_0048a520
{
    void __thiscall ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
struct S_0048cca0
{
    void __thiscall Save_0048cca0();
};
struct FUN_00479350_shell
{
    void __thiscall BGSEquipType_Save();
};
struct FUN_00485e00_shell
{
    void __thiscall TESForm_SaveData();
};

struct FUN_00409c70_shell
{
    void __thiscall IngredientItem_SaveMagicItemComponents();
};

// @fnv 0x00409c70
// src: XBOX_PDB 0x00409c70
void __thiscall FUN_00409c70_shell::IngredientItem_SaveMagicItemComponents()
{
    ((S_0048a520*)((char*)this + 0x1c))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((TESIcon*)((char*)this + 0x3c))->Save(0x4e4f4349);
    ((S_0048cca0*)((char*)this + 0x48))->Save_0048cca0();
    ((S_00477f20*)((char*)this + 0x64))->FUN_00477f20();
    ((FUN_00479350_shell*)((char*)this + 0x5c))->BGSEquipType_Save();
    ((FUN_00485e00_shell*)((char*)this - 0x30))->TESForm_SaveData();
}

struct P0_004098
{
    virtual void v0();
    char pad[0x2c];
};
struct P30_004098
{
    virtual void v0();
    char pad[0x8];
};
struct P3c_004098
{
    virtual void v0();
    char pad[0xc];
};
struct FUN_00402b40 : P0_004098, P30_004098, P3c_004098
{
    FUN_00402b40();
    ~FUN_00402b40();
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    virtual void v0();
    char pad[0x1c];
};
struct FUN_0048cc50
{
    FUN_0048cc50();
    virtual void v0();
    char pad[0x8];
};
struct FUN_0048eac0
{
    FUN_0048eac0();
    ~FUN_0048eac0();
    virtual void v0();
    char pad[0x4];
};
struct FUN_00479320
{
    FUN_00479320();
    virtual void v0();
    char pad[0x4];
};
struct FUN_00475350
{
    FUN_00475350();
    ~FUN_00475350();
    virtual void v0();
    char pad[0x4];
};
struct S_004f15a0
{
    void FUN_004f15a0(int);
};
struct FUN_004098f0 : FUN_00402b40, B2_4fe, TESIcon, FUN_0048cc50, FUN_0048eac0, FUN_00479320, FUN_00475350
{
    IngredientItem::EffectIndexRecord data;
    FUN_004098f0();
};
// @fnv 0x004098f0
FUN_004098f0::FUN_004098f0()
{
    ((S_004f15a0*)this)->FUN_004f15a0(0x1d);
    ((IngredientItem*)(void*)this)->IngredientItem::ResetFormData();
}

struct DtorBase00
{
    virtual ~DtorBase00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DtorBase30
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
};

struct DtorBase3c
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
    int unk0C;
};

struct DtorBase4c
{
    virtual ~DtorBase4c();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct DtorBase78
{
    virtual void Vslot00()
    {}
    int unk04;
    int unk08;
};

struct DtorBase84
{
    virtual ~DtorBase84();
    int unk04;
};

struct DtorBase8c
{
    virtual void Vslot00()
    {}
    int unk04;
};

struct DtorBase94
{
    virtual ~DtorBase94();
    int unk04;
};

struct FUN_00409b40 : DtorBase00,
                      DtorBase30,
                      DtorBase3c,
                      DtorBase4c,
                      TESIcon,
                      DtorBase78,
                      DtorBase84,
                      DtorBase8c,
                      DtorBase94
{
    virtual ~FUN_00409b40();
    void Cleanup();
};

// @fnv 0x00409b40
FUN_00409b40::~FUN_00409b40()
{
    Cleanup();
}

struct S_00586150_obj
{
    char unk00[0xa0];
    unsigned char m_a0;
    void* __thiscall CombatController_GetCombatState();
};

struct S_00810570_obj
{
    void __thiscall SetAssociatedActorValue(void* arg);
};

void* __cdecl FUN_00ec43fb(unsigned int aFlag, unsigned int unk1, const char* unk2, const char* unk3,
                           unsigned int unk4);

extern char DAT_011839dc[];
extern char DAT_01183140[];

struct FUN_0040a040_cls
{
    char unk00[0x70];
    unsigned char m_70;

    void IngredientItem_CopyMagicItemData(unsigned int aFlag);
};

// @fnv 0x0040a040
// src: COMMUNITY 0x0040a040
void FUN_0040a040_cls::IngredientItem_CopyMagicItemData(unsigned int aFlag)
{
    S_00586150_obj* obj = (S_00586150_obj*)FUN_00ec43fb(aFlag, 0, DAT_01183140, DAT_011839dc, 0);
    if (obj == 0)
    {
    }
    else
    {
        ((S_00810570_obj*)((char*)this - 0x30))->SetAssociatedActorValue(obj->CombatController_GetCombatState());
        m_70 = obj->m_a0;
    }
}

extern "C" void* __cdecl _alloca(unsigned int);

struct LCFile
{
    unsigned int GetChunkSize();
    bool GetChunkData(void* apData, unsigned int auiSize);
    bool GetChunkData(unsigned int* apData);
    unsigned short GetFormVersion();
};

struct LCForm
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;

    void ReadTypedData(LCFile* apFile, void* apUnk, unsigned short ausVersion);
};

struct LCLoader
{
    virtual void IngredientItem_LoadMagicItemChunk(LCFile* apFile, int aiChunk);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct LCModel
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    bool LoadTextureSwaps(void* apData, unsigned int auiSize, unsigned int auiVersion);
};

struct LCScriptable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    void SetScriptID(unsigned int auiFormID);
    void InitItem(LCForm* apForm);
};

struct LCEquipType
{
    int unk00;
    int unk04;

    void SetEquipType(unsigned int auiType);
};

struct LCDestructible
{
    int unk00;
};

void __cdecl LCLoadModel(LCModel* apModel, LCFile* apFile);
void __cdecl LCLoadIcon(TESIcon* apIcon, LCFile* apFile);
void __cdecl LCLoadDestructible(LCDestructible* apDestructible, LCFile* apFile);

struct LCItem : LCForm, LCLoader, LCModel, TESIcon, LCScriptable, LCEquipType, LCDestructible
{
    virtual void IngredientItem_LoadMagicItemChunk(LCFile* apFile, int aiChunk);
};

// @fnv 0x00409da0
// src: COMMUNITY 0x00409da0
void LCItem::IngredientItem_LoadMagicItemChunk(LCFile* apFile, int aiChunk)
{
    switch (aiChunk)
    {
    case 'LDOM':
    case 'DSOM':
    case 'DDOM':
    case 'TDOM':
        LCLoadModel(this, apFile);
        break;
    case 'SDOM': {
        unsigned int uiSize = apFile->GetChunkSize();
        void* pBuffer = _alloca(uiSize);
        apFile->GetChunkData(pBuffer, uiSize);
        LCModel::LoadTextureSwaps(pBuffer, uiSize, apFile->GetFormVersion());
        break;
    }
    case 'NOCI':
        LCLoadIcon(this, apFile);
        break;
    case 'IRCS': {
        unsigned int uiScript = 0;
        apFile->GetChunkData(&uiScript);
        SetScriptID(uiScript);
        InitItem(this);
        break;
    }
    case 'DTSD':
    case 'TSED':
        LCLoadDestructible(this, apFile);
        break;
    case 'PYTE': {
        unsigned int uiEquipType = 0;
        apFile->GetChunkData(&uiEquipType);
        SetEquipType(uiEquipType);
        break;
    }
    case 'ATAD':
        ReadTypedData(apFile, 0, 0);
        break;
    }
}

namespace n40 {
struct Blk
{
    void QuestPerkEntryData_Endian();
};
}
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(void* stream, void* data, unsigned int size);

class PrimaryBase409
{
  public:
    virtual void p0();
};

class StreamIface409
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void* v9();
    virtual void IngredientItem_Endian();
};

class Obj409 : public PrimaryBase409, public StreamIface409
{
  public:
    int pad08, pad0c, pad10, pad14, pad18, pad1c, pad20, pad24;
    int pad28, pad2c, pad30, pad34, pad38, pad3c, pad40, pad44;
    int pad48, pad4c, pad50, pad54, pad58, pad5c, pad60, pad64;
    int pad68, pad6c;
    n40::Blk m_70;
    virtual void IngredientItem_Endian();
};

// @fnv 0x00409ce0
// src: COMMUNITY 0x00409ce0
void Obj409::IngredientItem_Endian()
{
    if (TESForm_QEndianSwapOnSave())
        m_70.QuestPerkEntryData_Endian();
    AppendChunk(v9(), &m_70, 8);
    if (TESForm_QEndianSwapOnSave())
        m_70.QuestPerkEntryData_Endian();
}

struct BaseZero
{
    virtual void v0();
    int unk04;
    int unk08;
    ~BaseZero();
};
struct BaseTwelve
{
    virtual void v0();
    ~BaseTwelve();
    void RemoveAllEffects();
};
struct FUN_0040a140 : BaseZero, BaseTwelve
{
    ~FUN_0040a140();
};
// Destructor that calls BaseTwelve::FUN_00406340().
// @fnv 0x0040a140
FUN_0040a140::~FUN_0040a140()
{
    BaseTwelve::RemoveAllEffects();
}
