#include "../../include/TESObjectCLOT.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESBoundObject.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSEquipType.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/TESForm.h"

// src/fallout_shared/tesobjectclot.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesobjectclot.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x005156b0
// src: XBOX_PDB 0x005156b0
void TESObjectCLOT::InitializeData_005156b0()
{
    TESEnchantableForm::SetCastingType(3);
}

// Save is absent from TESBipedModelForm.h; this adapter adds only that declaration.
struct BipedModelSave : TESBipedModelForm
{
    void Save();
};

struct FUN_00485e00_shell
{
    void TESForm_SaveData();
};

// @fnv 0x00515f40
// src: XBOX_PDB 0x00515f40
void TESObjectCLOT::Save_00515f40()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESScriptableForm::Save_0048cca0();
    TESEnchantableForm::Save();
    reinterpret_cast<BipedModelSave*>(reinterpret_cast<char*>(this) + 0x68)->Save();
    BGSDestructibleObjectForm::Save();
    BGSEquipType::Save();
    reinterpret_cast<FUN_00485e00_shell*>(this)->TESForm_SaveData();
    TESForm::FinishFormRecord();
}

void __cdecl operator delete(void*);

// Calls the object's destructor and, when bit 0 of flags is set, frees the object, then returns this.
// @fnv 0x00515580
void* TESObjectCLOT::DestroyIfFlagged(unsigned int flags)
{
    this->TESObjectCLOT::~TESObjectCLOT();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern unsigned int _data_011c16bc;

// Initializes the vtable pointers of all base classes, sets the form type to 0x1a, and calls FUN_005156b0 on the object.
// @fnv 0x00515440
TESObjectCLOT::TESObjectCLOT()
{
    TESForm::SetFormType(static_cast<ENUM_FORM_ID>(0x1a));
    InitializeData_005156b0();
}

namespace fnv_005156d0 {

void _FNV_Warning(const char*, const char*);

// TESObjectCLOT.h has no clothing-specific initialization declaration.
struct ClothingInitialization
{
    void Initialize();
};

// @fnv 0x005156d0
void ClothingInitialization::Initialize()
{
    if (((TESForm*)this)->GetInitialized())
        return;

    if (*(int*)((char*)this + 0x6c) == 0)
    {
        _FNV_Warning("MASTERFILE: Clothing '%s' needs to have biped slots selected in the editor.",
                     ((const char*(__thiscall*)(void*))(*(void***)this)[0x4c])((void*)this));
    }

    ((TESScriptableForm*)((char*)this + 0x3c))->InitItem((TESForm*)this);
    ((TESEnchantableForm*)((char*)this + 0x48))->InitItem((TESForm*)this);
    ((BGSDestructibleObjectForm*)((char*)this + 0x144))->InitItem((TESForm*)this);
    ((TESBipedModelForm*)((char*)this + 0x68))->InitItem((TESForm*)this);

    ((TESForm*)this)->SetInitializationState(true);
}
}  // namespace fnv_005156d0

// Destructor of the class; the body is empty, so it only runs the implicit destructors of its base classes.
// @fnv 0x005155b0
TESObjectCLOT::~TESObjectCLOT()
{}

extern "C" void* __cdecl _alloca(unsigned int);

struct RecordReader
{
    unsigned char FUN_00472660();
    int TESFile_GetTESChunk();
    bool FUN_004726f0();
    unsigned int GetField25C();
    void ReadChunkInt(unsigned int*);
    void ReadChunkData(unsigned short*);
    void FUN_00472890(void*, unsigned int);
    unsigned short FUN_00403570();
    bool FUN_00401680();
};
struct BipedFlags
{
    void BSEndian_Thunk();
    void QuestPerkEntryData_Endian();
};
void __cdecl ReadFullName(TESFullName*, RecordReader*);
void __cdecl BGSDestructibleObjectForm_LoadChunk(BGSDestructibleObjectForm*, RecordReader*);
void __cdecl FUN_004892d0(TESModelTextureSwap*, RecordReader*);
void __cdecl TESModel_LoadModelTextureChunk(TESModelTextureSwap*, RecordReader*);
void __cdecl FUN_0048a990(TESModelTextureSwap*, RecordReader*);
struct ClothingLoader : TESObjectCLOT
{
    void CallWithThis(RecordReader*);
    void FUN_00484ab0(int);
    void TESForm_LoadData(RecordReader*, int, int);
    bool ReadFromStream(RecordReader*);
};
// @fnv 0x00515760
bool ClothingLoader::ReadFromStream(RecordReader* reader)
{
    unsigned char marker = reader->FUN_00472660();
    if (marker != 0x1a)
        return false;
    CallWithThis(reader);
    FUN_00484ab0(0);
    int chunk;
    while ((chunk = reader->TESFile_GetTESChunk()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(pEditorId, 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f: {
            readOBNDSubRecord(reinterpret_cast<TESFile*>(reader));
            break;
        }
        case 0x4c4c5546: {
            ReadFullName(this ? reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 0x30) : 0, reader);
            break;
        }
        case 0x49524353: {
            unsigned int formID = 0;
            reader->ReadChunkInt(&formID);
            TESScriptableForm::FUN_006ecd40(formID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d544945:
        case 0x4d414e45: {
            unsigned int formID = 0;
            reader->ReadChunkInt(&formID);
            reinterpret_cast<TESEnchantableForm*>(reinterpret_cast<char*>(this) + 0x48)->SetFormEnchanting(reinterpret_cast<EnchantmentItem*>(formID));
            break;
        }
        case 0x4d414e41:
        case 0x544d4145: {
            unsigned short amount = 0;
            reader->ReadChunkData(&amount);
            reinterpret_cast<TESEnchantableForm*>(reinterpret_cast<char*>(this) + 0x48)->SetFormEnchantmentAmount(amount);
            break;
        }
        case 0x54444d42: {
            if (reader->FUN_00403570() < 11)
            {
                unsigned int bipedData;
                reader->FUN_00472890(&bipedData, 4);
                if (reader->FUN_00401680())
                    reinterpret_cast<BipedFlags*>(&bipedData)->BSEndian_Thunk();
                this->bipedFlags = ((unsigned char*)&bipedData)[2];
                this->partMask = *(unsigned short*)&bipedData;
            }
            else
            {
                reader->FUN_00472890(&this->partMask, 8);
                if (reader->FUN_00401680())
                    reinterpret_cast<BipedFlags*>(&this->partMask)->QuestPerkEntryData_Endian();
            }
            this->bipedFlags &= ~0x10;
            break;
        }
        case 0x54434d42: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->modelRDT.SetModelFilePath(buffer);
            break;
        }
        case 0x4c444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->bipedModel[0].SetModelFilePath(buffer);
            break;
        }
        case 0x54444f4d: {
            TESModel_LoadModelTextureChunk(&this->bipedModel[0], reader);
            break;
        }
        case 0x53444f4d: {
            FUN_0048a990(&this->bipedModel[0], reader);
            break;
        }
        case 0x44444f4d: {
            FUN_004892d0(&this->bipedModel[0], reader);
            break;
        }
        case 0x44534f4d: {
            FUN_004892d0(&this->bipedModel[1], reader);
            break;
        }
        case 0x32444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->groundModel[0].SetModelFilePath(buffer);
            break;
        }
        case 0x54324f4d: {
            TESModel_LoadModelTextureChunk(&this->groundModel[0], reader);
            break;
        }
        case 0x53324f4d: {
            FUN_0048a990(&this->groundModel[0], reader);
            break;
        }
        case 0x4e4f4349: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->icon[0].AssignTextureName(buffer);
            break;
        }
        case 0x4f43494d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->messageIcon[0].SetMessageIconTextureName(buffer);
            break;
        }
        case 0x3243494d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->messageIcon[1].SetMessageIconTextureName(buffer);
            break;
        }
        case 0x33444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->bipedModel[1].SetModelFilePath(buffer);
            break;
        }
        case 0x54334f4d: {
            TESModel_LoadModelTextureChunk(&this->bipedModel[1], reader);
            break;
        }
        case 0x53334f4d: {
            FUN_0048a990(&this->bipedModel[1], reader);
            break;
        }
        case 0x34444f4d: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->groundModel[1].SetModelFilePath(buffer);
            break;
        }
        case 0x54344f4d: {
            TESModel_LoadModelTextureChunk(&this->groundModel[1], reader);
            break;
        }
        case 0x53344f4d: {
            FUN_0048a990(&this->groundModel[1], reader);
            break;
        }
        case 0x324f4349: {
            char* buffer = (char*)_alloca(reader->GetField25C());
            reader->FUN_00472890(buffer, 0);
            this->icon[1].AssignTextureName(buffer);
            break;
        }
        case 0x44545344:
        case 0x54534544: {
            BGSDestructibleObjectForm_LoadChunk(this ? reinterpret_cast<BGSDestructibleObjectForm*>(reinterpret_cast<char*>(this) + 0x144) : 0, reader);
            break;
        }
        case 0x50595445: {
            unsigned int equipID = 0;
            reader->ReadChunkInt(&equipID);
            reinterpret_cast<BGSEquipType*>(reinterpret_cast<char*>(this) + 0x14c)->SetEquipType(static_cast<int>(equipID));
            break;
        }
        case 0x41544144: {
            TESForm_LoadData(reader, 0, 0);
            break;
        }
        default:
            break;
        }
        if (!reader->FUN_004726f0())
            break;
    }
    return true;
}

struct FUN_005092f0_obj
{
    void TESForm_CopyAllComponents(TESForm* apCopy);
};

struct ClothingCopyView : TESObjectCLOT
{
    void TESObjectCLOT_Copy(TESForm* apCopy);
};

// Dynamic-casts apCopy to TESObjectCLOT and, if valid, forwards the copy to the base class via FUN_004851b0.
// @fnv 0x00515fb0
// src: XBOX_PDB 0x00515fb0
void ClothingCopyView::TESObjectCLOT_Copy(TESForm* apCopy)
{
    TESObjectCLOT* pSourceClothing = dynamic_cast<TESObjectCLOT*>(apCopy);
    if (!pSourceClothing)
        return;
    ((FUN_005092f0_obj*)this)->TESForm_CopyAllComponents(apCopy);
}

struct ClothingComparison
{
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESObjectCLOT_Compare(TESForm*);
};
// Returns true if the given form is not a clothing item or if it passes the FUN_00485270 check.
// @fnv 0x00515ff0
// src: XBOX_PDB 0x00515ff0
bool ClothingComparison::TESObjectCLOT_Compare(TESForm* apForm)
{
    TESObjectCLOT* clothing = dynamic_cast<TESObjectCLOT*>(apForm);
    if (!clothing)
        return true;
    if (TESForm_CompareAllComponents(reinterpret_cast<TESForm*>(clothing)))
        return true;
    return false;
}
