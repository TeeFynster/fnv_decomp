// tesobjectarmo.cpp: TESObjectARMO, ArmorSerializer, ArmorCopy, TESObjectARMOFoley and more (15 functions)

#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

// Keep the list lifetime declarations used by these record loaders. The shared
// MagicTarget list currently declares neither its constructor nor destructor.
#include "../include/BSSimpleList.h"
#include "../include/BaseFormComponent.h"
#define FNV_BASEFORMCOMPONENT_H
#include "../include/TESForm.h"
#include "../include/ENUM_FORM_ID.h"
#include "../include/BSSoundHandle.h"
#include "../include/BGSBipedModelList.h"
#include "../include/BGSPickupPutdownSounds.h"
#include "../include/BGSRepairItemList.h"
#include "../include/TESBipedModelForm.h"
#include "../include/TESFullName.h"
#include "../include/TESHealthForm.h"
#include "../include/TESValueForm.h"
#include "../include/TESWeightForm.h"
#include "../include/ArmorData.h"
#include "../include/BGSDestructibleObjectForm.h"
#include "../include/BGSEquipType.h"
#include "../include/ShortPoint3.h"
#include "../include/TESBoundObject.h"
#include "../include/TESBoundObject__BOUND_DATA.h"
#include "../include/TESEnchantableForm.h"
#include "../include/TESObject.h"
#include "../include/TESTexture1024.h"

#include "../include/TESScriptableForm.h"
#include "../include/TESObjectARMO.h"

class BipedModelForm;
class BSFileEntry;

// Only corroborated SoundDescriptor fields are exposed; the middle four bytes have
// conflicting chance-field offsets in public declarations and are not accessed.
class SoundDescriptor
{
  public:
    SoundDescriptor();
    void Endian();
    TESSound* SoundAssetTmp;
    unsigned char layoutPadding4[4];
    int eType;
};
FNV_STATIC_ASSERT(sizeof(SoundDescriptor) == 12);
class DistantTreeTextureInfo;

class BipedModelForm
{
  public:
    void Endian();
    unsigned int m_uiBipedModelFlags;  // +0x0, 4 bytes
    unsigned char m_ucBipedModelData;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
};
FNV_STATIC_ASSERT(sizeof(BipedModelForm) == 8);
FNV_STATIC_ASSERT(offsetof(BipedModelForm, m_uiBipedModelFlags) == 0);
FNV_STATIC_ASSERT(offsetof(BipedModelForm, m_ucBipedModelData) == 4);

FNV_STATIC_ASSERT(sizeof(ArmorData) == 12);
FNV_STATIC_ASSERT(offsetof(ArmorData, m_usArmorRating) == 0);
FNV_STATIC_ASSERT(offsetof(ArmorData, fArmorProtectionValue) == 4);
FNV_STATIC_ASSERT(offsetof(ArmorData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(ArmorData, m_ucSubtype) == 9);

FNV_STATIC_ASSERT(sizeof(TESObjectARMO) == 400);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, data) == 376);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, flags) == 388);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, m_pPickupPutdownSoundList) == 392);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, m_pSoundSourceArmor) == 392);
FNV_STATIC_ASSERT(offsetof(TESObjectARMO, m_bUsesSoundList) == 396);

// ArmorData does not yet declare its record endian helper.
struct ArmorDataEndian
{
    void OBJ_WEAP_CRITICAL_Endian();
};

// Record-loading helpers and legacy armor layouts.
#include "../include/TESFile.h"
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFileChunkData16
{
  public:
    bool GetChunkData(unsigned short*);
};

// Legacy formats retained for records written before the current armor layout.
struct TESObjectARMOOldBipedModel
{
    unsigned short slots;
    unsigned char flags;
    void BSEndian_Thunk();
};
struct TESObjectARMOOldData
{
    unsigned short rating;
    void BSEndian_Thunk();
};

extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl Warning(const char*, ...);

// @fnv 0x00512e10
void TESObjectARMO::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    m_bUsesSoundList = false;
    m_pSoundSourceArmor = 0;
    SetCastingType(MagicSystem__CastingType_CONSTANT_EFFECT);
}

// Returns 1 for heavy armor, 2 for medium armor, otherwise 0.
// @fnv 0x00514410
unsigned char TESObjectARMO::GetArmorType()
{
    if (GetIsHeavyArmor())
        return 1;
    if (GetIsMediumArmor())
        return 2;
    return 0;
}

// @fnv 0x00512e60
void TESObjectARMO::InitItem()
{
    if (IsFormInitialized())
        return;
    if (!partMask)
        Warning("MASTERFILE: Armor '%s' needs to have biped slots selected in the editor.", GetName());
    TESScriptableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESBipedModelForm::InitItem(this);
    BGSRepairItemList::InitItem(this);
    BGSBipedModelList::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    if (!m_bUsesSoundList && m_pSoundSourceArmor)
    {
        m_pSoundSourceArmor = static_cast<TESObjectARMO*>(GetFormByID((unsigned int)m_pSoundSourceArmor));
    }
    else if (m_bUsesSoundList && m_pPickupPutdownSoundList)
    {
        BSSimpleList<SoundDescriptor*>* soundList = m_pPickupPutdownSoundList;
        while (soundList && soundList->GetItem())
        {
            SoundDescriptor* sound = soundList->GetItem();
            soundList = soundList->GetNext();
            if (sound->SoundAssetTmp)
                sound->SoundAssetTmp = (TESSound*)GetFormByID((unsigned int)sound->SoundAssetTmp);
        }
    }
    SetInitializationState(true);
}

// Reads an ARMO record from the TESFile: checks form type 24, loads the record header, then dispatches each chunk to the matching sub-record loader.
// @fnv 0x00512fd0
bool TESObjectARMO::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 24)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 512);
            SetEditorID_AtRuntime(name);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 'IRCS': {
            unsigned int uiScriptFormID = 0;
            file->GetChunkData(&uiScriptFormID);
            SetScript((Script*)uiScriptFormID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'MANE':
        case 'MTIE': {
            unsigned int uiEnchantmentFormID = 0;
            file->GetChunkData(&uiEnchantmentFormID);
            SetFormEnchanting((EnchantmentItem*)uiEnchantmentFormID);
            break;
        }
        case 'MANA':
        case 'TMAE': {
            unsigned short usEnchantmentAmount = 0;
            ((TESFileChunkData16*)file)->GetChunkData(&usEnchantmentAmount);
            SetFormEnchantmentAmount(usEnchantmentAmount);
            break;
        }
        case 'TDMB': {
            if (((TESFileFormVersion*)file)->GetFormVersion() < 11)
            {
                TESObjectARMOOldBipedModel oldBipedModel;
                file->GetChunkData(&oldBipedModel, sizeof(oldBipedModel));
                if (file->IsEndianConversionRequired())
                    oldBipedModel.BSEndian_Thunk();
                bipedFlags = oldBipedModel.flags;
                partMask = oldBipedModel.slots;
            }
            else
            {
                file->GetChunkData(&partMask, sizeof(BipedModelForm));
                if (file->IsEndianConversionRequired())
                    ((BipedModelForm*)&partMask)->Endian();
            }
            bipedFlags &= ~16;
            break;
        }
        case 'TCMB': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            modelRDT.SetModelFilePath(name);
            break;
        }
        case 'LDOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            bipedModel[0].SetModelFilePath(name);
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
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            groundModel[0].SetModelFilePath(name);
            break;
        }
        case 'T2OM':
            TESModel::LoadTextureSwapData(&groundModel[0], file);
            break;
        case 'S2OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&groundModel[0], file);
            break;
        case 'NOCI': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            ((TESTexture1024*)&icon[0])->SetTexture(name);
            break;
        }
        case 'OCIM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            messageIcon[0].SetMessageIconTextureName(name);
            break;
        }
        case '2CIM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            messageIcon[1].SetMessageIconTextureName(name);
            break;
        }
        case '3DOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            bipedModel[1].SetModelFilePath(name);
            break;
        }
        case 'T3OM':
            TESModel::LoadTextureSwapData(&bipedModel[1], file);
            break;
        case 'S3OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[1], file);
            break;
        case '4DOM': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            groundModel[1].SetModelFilePath(name);
            break;
        }
        case 'T4OM':
            TESModel::LoadTextureSwapData(&groundModel[1], file);
            break;
        case 'S4OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&groundModel[1], file);
            break;
        case '2OCI': {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0);
            ((TESTexture1024*)&icon[1])->SetTexture(name);
            break;
        }
        case 'TSED':
        case 'DTSD':
            BGSDestructibleObjectForm::LoadDestructibleData(this, file);
            break;
        case 'LPER': {
            unsigned int uiListFormID = 0;
            file->GetChunkData(&uiListFormID);
            SetRepairList((BGSListForm*)uiListFormID);
            break;
        }
        case 'LPIB': {
            unsigned int uiListFormID = 0;
            file->GetChunkData(&uiListFormID);
            SetBipedModelList((BGSListForm*)uiListFormID);
            break;
        }
        case 'PYTE': {
            unsigned int uiEquipType = 0;
            file->GetChunkData(&uiEquipType);
            SetEquipType((BGSEquipType__EQUIP_TYPE)uiEquipType);
            break;
        }
        case 'MANY': {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            SetPickupSound((TESSound*)sound);
            break;
        }
        case 'MANZ': {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            SetPutdownSound((TESSound*)sound);
            break;
        }
        case 'MANB': {
            unsigned int isBase = 0;
            file->GetChunkData(&isBase);
            if (isBase)
                m_bUsesSoundList = true;
            else
                m_bUsesSoundList = false;
            break;
        }
        case 'MANT': {
            if (!m_bUsesSoundList)
            {
                unsigned int formID = 0;
                file->GetChunkData(&formID);
                m_pSoundSourceArmor = (TESObjectARMO*)formID;
            }
            break;
        }
        case 'MANS': {
            if (m_bUsesSoundList)
            {
                if (!m_pPickupPutdownSoundList)
                    m_pPickupPutdownSoundList = new BSSimpleList<SoundDescriptor*>;
                SoundDescriptor* sound = new SoundDescriptor;
                ReadTypedData(file, sound, sizeof(SoundDescriptor));
                if (file->IsEndianConversionRequired())
                    sound->Endian();
                m_pPickupPutdownSoundList->AddHead(sound);
            }
            break;
        }
        case 'ATAD': {
            unsigned int added = GetDataSizeAdjustment();
            if (file->GetChunkSize() - added == 2)
            {
                TESObjectARMOOldData oldArmoData;
                memset(&oldArmoData, 0, sizeof(oldArmoData));
                ReadTypedData(file, &oldArmoData, sizeof(oldArmoData));
                if (file->IsEndianConversionRequired())
                    oldArmoData.BSEndian_Thunk();
                memcpy(&data, &oldArmoData, sizeof(oldArmoData));
                data.cFlags = 0;
            }
            else
            {
                ReadTypedData(file, 0, 0);
            }
            break;
        }
        case 'MAND': {
            memset(&data, 0, sizeof(data));
            file->GetChunkData(&data, sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<ArmorDataEndian*>(&data)->OBJ_WEAP_CRITICAL_Endian();
            break;
        }
        }
        if (chunk == 'ATAD' && file->IsEndianConversionRequired())
            reinterpret_cast<ArmorDataEndian*>(&data)->OBJ_WEAP_CRITICAL_Endian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_00514450_shell : public TESBipedModelForm
{
    bool TESBipedModelForm_IsMedium();
};

// @fnv 0x00514450
// src: XBOX_PDB 0x00514450
bool FUN_00514450_shell::TESBipedModelForm_IsMedium()
{
    return *((unsigned char*)this + 8) & 8;
}

// Save-game methods absent from TESObjectARMO use method-only bridges.
struct ArmorSaveGame
{
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(unsigned int);
    void LoadGame(unsigned int, unsigned int);
};
struct FormSaveGame
{
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(unsigned int);
    void LoadGame(unsigned int, unsigned int);
};

// @fnv 0x00514470
unsigned short ArmorSaveGame::GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<FormSaveGame*>(this)->GetSaveSize(aiFlags);
    isize += ((TESValueForm*)((char*)this + 0x58))->TESValueForm::GetSaveSize(aiFlags);
    return isize;
}

// @fnv 0x00516040
void ArmorSaveGame::SaveGame(unsigned int aiFlags)
{
    reinterpret_cast<FormSaveGame*>(this)->SaveGame(aiFlags);
    reinterpret_cast<TESValueForm*>((char*)this + 0x58)->SaveGame_0048e9e0(aiFlags);
}

// @fnv 0x00516070
void ArmorSaveGame::LoadGame(unsigned int a1, unsigned int a2)
{
    reinterpret_cast<FormSaveGame*>(this)->LoadGame(a1, a2);
    reinterpret_cast<TESValueForm*>((char*)this + 0x58)->LoadGame_0048ea10(a1, a2);
}

// @fnv 0x005129f0
TESObjectARMO::TESObjectARMO()
{
    SetFormType(ENUM_FORM_ID_ARMO_ID);
    ResetFormData();
}

// @fnv 0x00512bd0
TESObjectARMO::~TESObjectARMO()
{}

bool TESForm_QEndianSwapOnSave();
void AppendChunk(unsigned int, void*, unsigned int);
void TESForm_AddChunk_00485910(unsigned int, unsigned int);
struct FUN_004855a0_shell
{
    void BeginFormRecord();
    void FinishFormRecord();
    void TESForm_SaveData();
};

// Serialization methods missing from the shared component headers use method-only bridges.
struct BipedModelSerialization
{
    void InitBipedModel();
};

struct RepairListSerialization
{
    void FUN_0047b8a0();
};
struct BipedModelListSerialization
{
    void BGSBipedModelList_Save();
};

struct PickupPutdownSerialization
{
    void LogFormIDs();
};
struct RefObj
{
    unsigned int _ref_0084e3a0();
};
struct FoleyNode : BSSimpleList<SoundDescriptor*>
{
    SoundDescriptor*& FUN_006815c0();
    FoleyNode* FUN_00726070();
};
struct FUN_00513d60
{
    unsigned int formID;
    unsigned char soundType;
    int value;
    FUN_00513d60();
    void FUN_00483710();
};
struct ArmorSerializer : TESObjectARMO
{
    void Save();
};

// @fnv 0x00513d90
void ArmorSerializer::Save()
{
    ((FUN_004855a0_shell*)this)->BeginFormRecord();
    TESFullName::Save_00487010();
    TESScriptableForm::Save();
    TESEnchantableForm::Save();
    reinterpret_cast<BipedModelSerialization*>(((char*)this + 0x70))->InitBipedModel();
    BGSDestructibleObjectForm::Save();
    reinterpret_cast<RepairListSerialization*>(((char*)this + 0x15C))->FUN_0047b8a0();
    reinterpret_cast<BipedModelListSerialization*>(((char*)this + 0x164))->BGSBipedModelList_Save();
    BGSEquipType::Save();
    reinterpret_cast<PickupPutdownSerialization*>(((char*)this + 0x16C))->LogFormIDs();
    ((FUN_004855a0_shell*)this)->TESForm_SaveData();
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<ArmorDataEndian*>(&data)->OBJ_WEAP_CRITICAL_Endian();
    AppendChunk(0x4d414e44, &data, sizeof(data));
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<ArmorDataEndian*>(&data)->OBJ_WEAP_CRITICAL_Endian();
    TESForm_AddChunk_00485910(0x4d414e42, m_bUsesSoundList ? 1 : 0);
    if (!m_bUsesSoundList)
    {
        if (m_pSoundSourceArmor)
        {
            unsigned int formID = ((RefObj*)m_pSoundSourceArmor)->_ref_0084e3a0();
            TESForm_AddChunk_00485910(0x4d414e54, formID);
        }
    }
    else if (m_pPickupPutdownSoundList)
    {
        FoleyNode* node = (FoleyNode*)m_pPickupPutdownSoundList;
        while (node && node->FUN_006815c0())
        {
            SoundDescriptor* sound = node->FUN_006815c0();
            node = node->FUN_00726070();
            if (sound && sound->SoundAssetTmp)
            {
                FUN_00513d60 saved;
                saved.formID = ((RefObj*)sound->SoundAssetTmp)->_ref_0084e3a0();
                saved.soundType = sound->layoutPadding4[0];
                saved.value = sound->eType;
                if (TESForm_QEndianSwapOnSave())
                    saved.FUN_00483710();
                AppendChunk(0x4d414e53, &saved, sizeof(saved));
                if (TESForm_QEndianSwapOnSave())
                    saved.FUN_00483710();
            }
        }
    }
    ((FUN_004855a0_shell*)this)->FinishFormRecord();
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct ArmorCopy : TESObjectARMO
{
    void CopyBase(TESForm*);
    void CopyArmorData(TESForm* form);
};
// @fnv 0x00513fa0
void ArmorCopy::CopyArmorData(TESForm* form)
{
    TESObjectARMO* source3 = dynamic_cast<TESObjectARMO*>(form);
    BSSimpleList<SoundDescriptor*>* node_;
    BSSimpleList<SoundDescriptor*>* iter;
    SoundDescriptor* original9;
    SoundDescriptor* copy7;
    SoundDescriptor* sound;
    if (!source3)
        return;
    CopyBase(form);
    data = source3->data;
    if (m_bUsesSoundList && m_pPickupPutdownSoundList)
    {
        node_ = m_pPickupPutdownSoundList;
        while (node_ && node_->GetItem())
        {
            sound = node_->GetItem();
            operator delete(sound);
            node_ = node_->GetNext();
        }
        m_pPickupPutdownSoundList->RemoveAll();
        delete m_pPickupPutdownSoundList;
    }
    m_bUsesSoundList = source3->m_bUsesSoundList;
    if (!m_bUsesSoundList)
        m_pPickupPutdownSoundList = source3->m_pPickupPutdownSoundList;
    else
    {
        m_pPickupPutdownSoundList = new BSSimpleList<SoundDescriptor*>;
        if (source3->m_pPickupPutdownSoundList)
        {
            iter = source3->m_pPickupPutdownSoundList;
            while (iter && iter->GetItem())
            {
                original9 = iter->GetItem();
                iter = iter->GetNext();
                if (original9 && original9->SoundAssetTmp)
                {
                    copy7 = new SoundDescriptor;
                    *copy7 = *original9;
                    m_pPickupPutdownSoundList->AddHead(copy7);
                }
            }
        }
    }
}

unsigned int DialogueRandom();

class TESObjectARMOFoley : public TESObjectARMO
{
  public:
    TESSound* GetFoleySound(int eType);
};

// Scans the armor's foley list for an entry matching eType whose random chance roll succeeds, returning its sound or null.
// @fnv 0x00512d40
TESSound* TESObjectARMOFoley::GetFoleySound(int eType)
{
    BSSimpleList<SoundDescriptor*>* pFoleyList;
    TESSound* pkSound = 0;
    SoundDescriptor* pkFoley;

    pFoleyList = m_bUsesSoundList ? m_pPickupPutdownSoundList
                                  : (m_pSoundSourceArmor ? m_pSoundSourceArmor->m_pPickupPutdownSoundList : 0);
    while (pFoleyList && !pFoleyList->IsEmpty() && !pkSound)
    {
        pkFoley = pFoleyList->GetItem();
        pFoleyList = pFoleyList->GetNext();
        if (pkFoley->SoundAssetTmp && pkFoley->eType == eType && (int)(DialogueRandom() & 0x63) < pkFoley->layoutPadding4[0])
            pkSound = pkFoley->SoundAssetTmp;
    }
    return pkSound;
}

#include <string.h>
struct ArmorCompare : TESObjectARMO
{
    bool TESForm_CompareAllComponents(TESObjectARMO* other);
    bool IsDifferentFrom(TESForm* form);
};
// Returns true if form is not an armor or differs in base compare, data, sound source armor, or pickup/putdown sound list entries.
// @fnv 0x00514220
bool ArmorCompare::IsDifferentFrom(TESForm* form)
{
    TESObjectARMO* pOther = dynamic_cast<TESObjectARMO*>(form);
    if (!pOther)
        return true;
    if (TESForm_CompareAllComponents(pOther))
        return true;
    if (memcmp(&data, &pOther->data, 12))
        return true;
    if (m_bUsesSoundList != pOther->m_bUsesSoundList)
        return true;
    if (!m_bUsesSoundList)
    {
        if (m_pSoundSourceArmor != pOther->m_pSoundSourceArmor)
            return true;
    }
    else
    {
        if (pOther->m_pPickupPutdownSoundList && m_pPickupPutdownSoundList &&
            pOther->m_pPickupPutdownSoundList->GetItem() == m_pPickupPutdownSoundList->GetItem())
        {
            BSSimpleList<SoundDescriptor*>* pCurrent = m_pPickupPutdownSoundList;
            while (pCurrent && pCurrent->GetItem())
            {
                bool bFound = false;
                BSSimpleList<SoundDescriptor*>* search = pOther->m_pPickupPutdownSoundList;
                while (search && search->GetItem())
                {
                    if (pCurrent->GetItem()->SoundAssetTmp == search->GetItem()->SoundAssetTmp &&
                        pCurrent->GetItem()->layoutPadding4[0] == search->GetItem()->layoutPadding4[0] &&
                        pCurrent->GetItem()->eType == search->GetItem()->eType)
                    {
                        bFound = true;
                        break;
                    }
                    search = search->GetNext();
                }
                if (!bFound)
                    return true;
                pCurrent = pCurrent->GetNext();
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}
