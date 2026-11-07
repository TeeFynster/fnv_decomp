// fallout_shared/tesobjectarma.cpp: TESObjectARMA (12 functions)

#include <malloc.h>
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/TESBipedModelForm.h"
#include "../../include/TESObjectARMA.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESResponse.h"
#include "../../include/TESValueForm.h"

// Local method access for ARMA routines not yet declared by the shared header; no layout is duplicated.
class ArmorAddonOperations : public TESObjectARMA
{
  public:
    void* DestroyIfFlagged(unsigned int flags);
    void SaveArmorGame(unsigned int flags);
    void LoadArmorGame(BGSLoadFormBuffer* buffer);
    void CopyArmor(TESForm* apCopy);
    bool CompareArmor(TESForm* apCompare);
    void SaveArmor();
};

#include "../../include/ENUM_FORM_ID.h"

struct BIPED_MODEL_OLD
{
    unsigned short m_uiBipedModelFlags;
    unsigned char m_ucBipedModelData;
    void BSEndian_Thunk();
};
class RegionDataEntry
{
  public:
    void Endian();
};
// ArmorData's shared layout has no endian method yet.
struct ArmorDataEndianAccess
{
    void Endian();
};

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern int __cdecl Warning(const char* format, ...);

// Zeroes the ARMA's data block with memset.
// @fnv 0x00512010
void TESObjectARMA::ResetFormData()
{
    memset(&data, 0, sizeof(data));
}

// Initializes the armor form: warns if no biped slots are set, then initializes destructible and biped data and marks the form initialized.
// @fnv 0x00512030
void TESObjectARMA::InitItem()
{
    if (IsFormInitialized())
        return;
    if (partMask == 0)
        Warning("MASTERFILE: Armor '%s' needs to have biped slots selected in the editor.", GetName());
    BGSDestructibleObjectForm::InitItem((TESForm*)this);
    TESBipedModelForm::InitItem((TESForm*)this);
    SetInitializationState(true);
}

// @fnv 0x005120a0
bool TESObjectARMA::Load(TESFile* file)
{
    unsigned char form = file->GetTESForm();
    if (form != 0x60)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (int chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullName::LoadFullNameChunk(this ? (TESFullName*)((char*)this + 0x30) : 0, file);
            break;
        case 'TDMB':
            if (file->GetFormVersion() < 11)
            {
                BIPED_MODEL_OLD oldData;
                file->GetChunkData(&oldData, 4);
                if (file->IsEndianConversionRequired())
                    oldData.BSEndian_Thunk();
                bipedFlags = oldData.m_ucBipedModelData;
                partMask = oldData.m_uiBipedModelFlags;
            }
            else
            {
                file->GetChunkData(&partMask, 8);
                if (file->IsEndianConversionRequired())
                    ((RegionDataEntry*)&partMask)->Endian();
            }
            bipedFlags &= ~0x10;
            break;
        case 'TCMB': {
            char* constraint = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(constraint, 0);
            modelRDT.SetModelFilePath(constraint);
            break;
        }
        case 'LDOM': {
            char* maleBiped = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleBiped, 0);
            bipedModel[0].SetModelFilePath(maleBiped);
            break;
        }
        case 'TDOM':
            TESModel::LoadTextureSwapData(&bipedModel[0], file);
            break;
        case 'SDOM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[0], file);
            break;
        case 'DDOM':
            TESModel::LoadModelData(&bipedModel[0], file);
            break;
        case 'DSOM':
            TESModel::LoadModelData(&bipedModel[1], file);
            break;
        case '2DOM': {
            char* maleWorld = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleWorld, 0);
            groundModel[0].SetModelFilePath(maleWorld);
            break;
        }
        case 'T2OM':
            TESModel::LoadTextureSwapData(&groundModel[0], file);
            break;
        case 'S2OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&groundModel[0], file);
            break;
        case 'NOCI': {
            char* maleIcon = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleIcon, 0);
            icon[0].SetTexture(maleIcon);
            break;
        }
        case 'OCIM': {
            char* maleMessage = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(maleMessage, 0);
            messageIcon[0].SetMessageIconTextureName(maleMessage);
            break;
        }
        case '2CIM': {
            char* femaleMessage = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleMessage, 0);
            messageIcon[1].SetMessageIconTextureName(femaleMessage);
            break;
        }
        case '3DOM': {
            char* femaleBiped = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleBiped, 0);
            bipedModel[1].SetModelFilePath(femaleBiped);
            break;
        }
        case 'T3OM':
            TESModel::LoadTextureSwapData(&bipedModel[1], file);
            break;
        case 'S3OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[1], file);
            break;
        case '4DOM': {
            char* femaleWorld = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleWorld, 0);
            groundModel[1].SetModelFilePath(femaleWorld);
            break;
        }
        case 'T4OM':
            TESModel::LoadTextureSwapData(&groundModel[1], file);
            break;
        case 'S4OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&groundModel[1], file);
            break;
        case '2OCI': {
            char* femaleIcon = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(femaleIcon, 0);
            icon[1].SetTexture(femaleIcon);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(static_cast<BGSDestructibleObjectForm*>(this), file);
            break;
        case 'PYTE': {
            unsigned int type = 0;
            file->GetChunkData(&type);
            // Reuse the canonical identity of the folded scalar setter.
            ((TESResponse*)((char*)this + 0x154))->SetEmotionValue(type);
            break;
        }
        case 'MAND':
            memset(&data, 0, sizeof(data));
            file->GetChunkData(&data, sizeof(data));
            if (file->IsEndianConversionRequired())
                ((ArmorDataEndianAccess*)&data)->Endian();
            break;
        }
        if (chunk == 'ATAD' && file->IsEndianConversionRequired())
            ((ArmorDataEndianAccess*)&data)->Endian();
        if (!file->NextChunk())
            break;
    }
    SetFormType(ENUM_FORM_ID_ARMO_ID);
    return true;
}

// @fnv 0x00511e40
TESObjectARMA::TESObjectARMA()
{
    SetFormType(ENUM_FORM_ID_ARMA_ID);
    ResetFormData();
}

struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0048ea40_holder
{
    void SaveGameBGS_0048ea40(unsigned int);
};

// @fnv 0x005144c0
void ArmorAddonOperations::SaveArmorGame(unsigned int flags)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(flags);
    reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x58)->SaveGameBGS_0048ea40(flags);
}

struct TESFormBufferAccess
{
    void LoadGame(BGSLoadFormBuffer*);
};

// Loads the form buffer via TESFormBufferAccess::LoadGame, then loads the value form at offset 0x58 via TESValueForm::LoadGame.
// @fnv 0x005160a0
void ArmorAddonOperations::LoadArmorGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESFormBufferAccess*>(this)->TESFormBufferAccess::LoadGame(buffer);
    reinterpret_cast<TESValueForm*>(reinterpret_cast<char*>(this) + 0x58)
        ->TESValueForm::LoadGame(buffer);
}

void _Deallocate(void*);
// Destroys the armor addon, then deallocates it if bit 0 of flags is set, and returns this.
// @fnv 0x00511f30
void* ArmorAddonOperations::DestroyIfFlagged(unsigned int flags)
{
    this->TESObjectARMA::~TESObjectARMA();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00511f60
TESObjectARMA::~TESObjectARMA()
{
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);
// Byte-swaps the 16-bit value at the start of this object by calling BSEndian.
// @fnv 0x00512810
// src: GUESS 0x00512810 (confidence: medium)
void BIPED_MODEL_OLD::BSEndian_Thunk()
{
    BSEndian((unsigned short*)this, EndianSizeTag<2>());
}

void* __memcpy(void*, const void*, unsigned int);
struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
// If apCopy is a TESObjectARMO, copies 0xc bytes at offset 0x178 from apCopy into this and calls FUN_004851b0(apCopy).
// @fnv 0x005128e0
void ArmorAddonOperations::CopyArmor(TESForm* apCopy)
{
    TESObjectARMO* parmo = dynamic_cast<TESObjectARMO*>(apCopy);
    if (parmo == 0)
        return;
    __memcpy((char*)this + 0x178, (char*)apCopy + 0x178, 0xc);
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(apCopy);
}

struct FUN_004855a0_shell
{
    void M();
};
struct S_00487010
{
    void Save_00487010();
};
struct FUN_00479350_shell
{
    void BGSEquipType_Save();
};
struct FUN_00485e00_shell
{
    void TESForm_SaveData();
};
struct FUN_00485680_shell
{
    void M();
};
bool __cdecl TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(unsigned int size, void* apDest, unsigned int flags);
// The shared biped header has no declaration for its save routine.
struct BipedModelSaveAccess
{
    void Save();
};

// @fnv 0x00512840
void ArmorAddonOperations::SaveArmor()
{
    ((FUN_004855a0_shell*)this)->M();
    ((S_00487010*)((char*)this + 0x30))->Save_00487010();
    ((BipedModelSaveAccess*)((char*)this + 0x70))->Save();
    ((FUN_00479350_shell*)((char*)this + 0x154))->BGSEquipType_Save();
    ((FUN_00485e00_shell*)this)->TESForm_SaveData();
    if (TESForm_QEndianSwapOnSave())
        ((ArmorDataEndianAccess*)((char*)this + 0x178))->Endian();
    AppendChunk(0x4d414e44, (char*)this + 0x178, 0xc);
    if (TESForm_QEndianSwapOnSave())
        ((ArmorDataEndianAccess*)((char*)this + 0x178))->Endian();
    ((FUN_00485680_shell*)this)->M();
}

extern int __cdecl _memcmp(const void* a, const void* b, unsigned int n);
struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};
// @fnv 0x00512940
bool ArmorAddonOperations::CompareArmor(TESForm* apCompare)
{
    TESObjectARMA* pcomp = dynamic_cast<TESObjectARMA*>(apCompare);
    if (!pcomp)
        return true;
    if (((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(pcomp))
        return true;
    if (_memcmp(&data, &pcomp->data, sizeof(data)))
        return true;
    return false;
}
