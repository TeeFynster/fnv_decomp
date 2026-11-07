// fallout_shared/tesobjectstat.cpp: TESObjectSTAT, TESGlobal, Standin, StatCopy (9 functions)

#include "tesobjectstat_load.h"
#include "../../include/TESGlobal.h"
#include "../../include/TESObjectSTAT.h"
#include "../../include/TESSound.h"

// Initializes a TESGlobal: sets cType to 's', fValue to 0.0f, and the form type to 6.
// @fnv 0x005a6320
TESGlobal::TESGlobal()
{
    cType = 's';
    fValue = 0.0f;
    SetFormType((ENUM_FORM_ID)6);
}

// Sets the form type to 0x20, initializes a byte field to 0xFF and a second field to 0.
// @fnv 0x0051b140
TESObjectSTAT::TESObjectSTAT()
{
    SetFormType((ENUM_FORM_ID)0x20);
    m_cType = (char)0xFF;
    m_pSoundForm = 0;
}

// @fnv 0x0051b280
bool TESObjectSTAT::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    LoadRecordHeader(file);
    unsigned int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch ((int)uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            void* pChunkData;
            {
                unsigned int uiChunkSize = file->GetChunkSize();
                pChunkData = _alloca(uiChunkSize);
                file->GetChunkData(pChunkData, uiChunkSize);
                ParseTextureSwapData(pChunkData, uiChunkSize, ((TESFileFormVersion*)file)->GetFormVersion());
            }
            break;
        }
        case 0x53555242: {
            unsigned int soundIndex = 0;
            file->GetChunkData(&soundIndex);
            m_cType = (char)(soundIndex > 10 ? 255 : soundIndex);
            break;
        }
        case 0x4d414e52: {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            m_pSoundForm = (TESSound*)sound;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

void _Deallocate(void*);
struct Standin
{
    void FUN_0051b200();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_0051b200, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0051b1d0
void* Standin::DestroyIfFlagged(unsigned int flags)
{
    FUN_0051b200();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_004855a0_shell
{
    void M();
    void BeginFormRecord();
};
struct FUN_00485680_shell
{
    void M();
    void FinishFormRecord();
};
struct S_0048a520_shell
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl TESForm_AddChunk_00485910(unsigned int, unsigned int);

struct FUN_0051b4b0_shell : public FUN_004855a0_shell
{
    void TESObjectSTAT_SaveAlt();
};

// @fnv 0x0051b4b0
// src: COMMUNITY 0x0051b4b0
void FUN_0051b4b0_shell::TESObjectSTAT_SaveAlt()
{
    ((FUN_004855a0_shell*)this)->M();
    ((S_0048a520_shell*)((char*)this + 0x30))->ProcessAndFreeData(0x4C444F4D, 0x54444F4D, 0x53444F4D);
    TESForm_AddChunk_3(0x53555242, *(unsigned char*)((char*)this + 0x50));
    if (*(unsigned int*)((char*)this + 0x54))
    {
        unsigned int id = ((TESForm*)(*(unsigned int*)((char*)this + 0x54)))->GetFormID();
        TESForm_AddChunk_00485910(0x4D414E52, id);
    }
    ((FUN_00485680_shell*)this)->M();
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESObjectSTAT_Compare(TESForm* form);
    char m_cType;
    TESSound* m_pSoundForm;
};
// Casts form to TESObjectSTAT and returns true if it is null, passes FUN_00485270, or differs in the byte at 0x50 or the TESSound pointer at 0x54.
// @fnv 0x0051b650
// src: XBOX_PDB 0x0051b650
bool FUN_005e79a0_t::TESObjectSTAT_Compare(TESForm* form)
{
    TESObjectSTAT* other = dynamic_cast<TESObjectSTAT*>(form);
    if (!other)
        return true;
    if (TESForm_CompareAllComponents(other))
        return true;
    if (*(char*)((char*)this + 0x50) != *(char*)((char*)other + 0x50))
        return true;
    if (*(TESSound**)((char*)this + 0x54) != *(TESSound**)((char*)other + 0x54))
        return true;
    return false;
}

extern char str_0102bbb0[];

void __cdecl _FNV_Warning(char*, unsigned int, char*, unsigned int);

struct TESObjectSTAT_shell : public TESForm
{
    void TESObjectSTAT_InitItem();
    void FUN_0048aa80(TESForm*);
};

// @fnv 0x0051b530
// src: XBOX_PDB 0x0051b530
void TESObjectSTAT_shell::TESObjectSTAT_InitItem()
{
    unsigned int itempint;

    if (IsFormInitialized())
        return;

    reinterpret_cast<TESObjectSTAT_shell*>(reinterpret_cast<unsigned char*>(this) + 0x30)->FUN_0048aa80(this);

    itempint =
        reinterpret_cast<unsigned int>(*reinterpret_cast<TESSound**>(reinterpret_cast<unsigned char*>(this) + 0x54));

    if (itempint)
    {
        TESForm::RemapFormIDForFile(itempint, GetFile(-1));

        reinterpret_cast<TESSound**>(reinterpret_cast<unsigned char*>(this) + 0x54)[0] =
            dynamic_cast<TESSound*>(GetFormByID(itempint));

        if (!reinterpret_cast<TESSound**>(reinterpret_cast<unsigned char*>(this) + 0x54)[0])
        {
            _FNV_Warning(str_0102bbb0, itempint, GetName(), GetFormID());
        }
    }

    SetInitializationState(true);
}

struct ObjectFormBase
{
    virtual ~ObjectFormBase();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
};
struct ModelTextureBase
{
    virtual ~ModelTextureBase();
};
struct FUN_0051b200 : ObjectFormBase, ModelTextureBase
{
    virtual ~FUN_0051b200();
    void FUN_00483710();
};
// @fnv 0x0051b200
FUN_0051b200::~FUN_0051b200()
{
    FUN_00483710();
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm* apForm);
};

struct StatCopy : public TESObjectSTAT
{
    void __thiscall TESObjectSTAT_Copy(TESForm* apCopy);
};

// @fnv 0x0051b5f0
// src: XBOX_PDB 0x0051b5f0
void __thiscall StatCopy::TESObjectSTAT_Copy(TESForm* apCopy)
{
    TESObjectSTAT* pcopy = dynamic_cast<TESObjectSTAT*>(apCopy);
    if (!pcopy)
    {
        return;
    }
    this->m_pSoundForm = pcopy->m_pSoundForm;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(pcopy);
    this->m_cType = pcopy->m_cType;
}
