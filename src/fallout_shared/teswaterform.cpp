// fallout_shared/teswaterform.cpp: TESWaterForm, BGSPlaceableWater, WaterShaderSettings and helpers (27 functions)

#include "layout_support.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESForm.h"
// Use the shared bases when the remaining unit-local headers include them.
#define FNV_BASEFORMCOMPONENT_H
#define FNV_TESFORM_H
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSPlaceableWater.h"
#include "../../include/FormChangeMask.h"
#include "../../include/TESModel.h"
#include "../../include/TESPackage.h"
#include "../../include/BGSImpactData.h"
#include "../../include/EffectSetting.h"
#include "../../include/SpellItem.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/TESSound.h"
#include "../../include/TESWaterForm.h"
#include "teswaterform_decls.h"
#include "../../include/WaterShaderSettings.h"
#include "../../include/BGSSaveFormBuffer.h"
#include "../../include/NP.h"
#include "../../include/EffectItem.h"
#include "../../include/TESTexture.h"
#include "../../include/TESFullName.h"
#include "../../include/BSStringT.h"
#include "../../include/NiPointer.h"

// @fnv 0x0057ef10
void TESWaterForm::ResetFormData()
{
    m_ucOpacity = 0x4B;
    cFlags = 0;
    m_pWaterSound = 0;
    m_kMaterialId.Set(0, 0);
    Sky_GetStarsColor()->Initialize();

    for (int i = 0; i < 3; ++i)
        m_apWaterForms[i] = 0;
}

// Initializes the object's fields with default constants and global values.
// @fnv 0x0057e9c0
void WaterShaderSettings::Initialize()
{
    SplatterSettings = g_splatterDefaultSecond;
    m_fSecondParameter = DAT_010249d8;
    m_fThirdParameter = 0.5f;
    m_fFourthSetting = 1.0f;
    SevenFloatParameterData = DAT_0101b268;
    SevenFloatParameters = 0.5f;
    SevenFloatData = DAT_010313d4;
    m_fEighthParameter = 0.0f;
    FiveFloatAndTwoUnsignedIntegerRecord = 0.0f;
    FourFloatAndThreeUnsignedIntegerRecord = 0.0f;
    WaterFogSettings = 1.0f;
    fUnderwaterFogDistNear = 0.0f;
    fUnderwaterFogDistFar = DAT_01013974;
    fUnderwaterFogAmount = 1.0f;
    FloatColorSettingsRecord = 0x00808000;
    ShaderColorParameterBlock = 0x00190000;
    ColorSettingsRecord = 0x00FFFFFF;
    SplatterColorSettings = g_splatterDefaultSecond;
    SplatterScalarSettings = DAT_01018180;
    SplatterFloatSettings = DAT_010231a4;
    SplatterParameterSet = DAT_010162c0;
    SplatterTimingSettings = 0.01f;
    SevenFloatRecordWithGlobals = DAT_010231a8;
    SevenFloatRecordWithStepAndGlobals = DAT_01018180;
    SevenFloatRecordWithStep = DAT_010231a4;
    SevenFloatFormatBlock = 10.0f;
    SevenFloatRecordWithUnitValue = DAT_010181bc;
    m_fWaterFogParameter1 = 0.0f;
    m_fValueBeforeWaterFogSettings = 0.0f;
    SevenFloatParameterSet = 1.0f;
    WaterFogParameterData = DAT_01013d84;
    m_fWaterParameter1 = 100.0f;
    m_fWaterParameter2 = 100.0f;
    m_fWaterParameter3 = 100.0f;
    WaterShaderProperties = DAT_0101b2d0;
    m_fShininess = 100.0f;
    WaterShaderParameters = 1.0f;
    MaterialParametersWithLeadingFloat = DAT_01022958;
    MaterialParameters = 1.0f;
}

// @fnv 0x0057f8b0
void TESWaterForm::InitItem()
{
    if (static_cast<const TESForm*>(this)->GetInitialized())
        return;
    unsigned int id = (unsigned int)m_pWaterSound;
    if (id)
    {
        RemapFormIDForFile(id, GetFile(-1));
        m_pWaterSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(id));
        if (!m_pWaterSound)
            Warning("MASTERFILE: Could not find sound (%08X) for water type '%s' (%08X).", id, GetName(), GetFormID());
    }
    id = (unsigned int)m_pWaterSpell;
    if (id)
    {
        RemapFormIDForFile(id, GetFile(-1));
        m_pWaterSpell = dynamic_cast<SpellItem*>(TESForm::GetFormByID(id));
        if (!m_pWaterSpell)
            Warning("MASTERFILE: Could not find sound (%08X) for spell item '%s' (%08X).", id, GetName(), GetFormID());
        if (m_pWaterSpell && !m_pWaterSpell->IsEmpty())
        {
            EffectItemList* node = m_pWaterSpell;
            EffectItem* radiation = 0;
            EffectItem* health = 0;
            while (node && (!radiation || !health))
            {
                EffectItem* effect = node->GetItem();
                if (effect->GetAffectedActorValue() == 54 && effect->GetEffectSetting()->IsFlagSet(4))
                {
                    radiation = effect;
                    m_iRadiationMagnitude = radiation->GetMagnitude();
                }
                else if (effect->GetAffectedActorValue() == 16 && !effect->GetEffectSetting()->IsFlagSet(4))
                {
                    health = effect;
                    m_iHealthMagnitude = health->GetMagnitude();
                }
                node = static_cast<EffectItemList*>(node->GetNext());
            }
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        id = (unsigned int)m_apWaterForms[i];
        if (id)
        {
            RemapFormIDForFile(id, GetFile(-1));
            m_apWaterForms[i] = dynamic_cast<TESWaterForm*>(TESForm::GetFormByID(id));
            if (!m_apWaterForms[i])
                Warning("MASTERFILE: Could not find WaterForm (%08X) for water type '%s' (%08X).", id, GetName(),
                        GetFormID());
        }
    }
    SetInitializationState(true);
}

// Reads a TESWaterForm record from file: checks form type 78, loads the header, then processes chunks (EDID, OBND, FULL, DATA, DNAM, etc.) into the form's fields.
// @fnv 0x0057ef80
bool TESWaterForm::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 78)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
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
        case 0x4c4c5546:
            TESFullName::LoadFullNameChunk(this, file);
            break;
        case 0x41544144: {
            unsigned int uiAddedSize = file->GetChunkSize() - GetDataSizeAdjustment();
            if (!uiAddedSize)
            {
                reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, 0, 0);
                if (file->IsEndianConversionRequired())
                    Data.Endian();
            }
            else
            {
                reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &Data, 196);
                if (file->IsEndianConversionRequired())
                    Data.Endian();
                Data.m_fWaterParameter1 = 100.0f;
                Data.m_fWaterParameter2 = 100.0f;
                Data.m_fWaterParameter3 = 100.0f;
                Data.m_fWaterParameter4 = 1.0f;
                Data.m_fWaterParameter5 = 0.5f;
                Data.m_fWaterParameter6 = 0.25f;
                SetAttackDamage(0);
            }
            break;
        }
        case 0x4d414e44:
            file->GetChunkData(&Data, 196);
            if (file->IsEndianConversionRequired())
                Data.Endian();
            break;
        case 0x4d414e4e:
            TESTexture::ReadTextureData(&m_kNoiseMapTexture, file);
            break;
        case 0x4d414e41:
            file->GetChunkData(&m_ucOpacity, 1);
            break;
        case 0x4d414e46:
            file->GetChunkData(&cFlags, 1);
            break;
        case 0x4d414e53: {
            unsigned int shader = 0;
            file->GetChunkData(&shader);
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader((TESEffectShader*)shader);
            break;
        }
        case 0x4d414e58: {
            unsigned int spell = 0;
            file->GetChunkData(&spell);
            SetSpellItem((SpellItem*)spell);
            break;
        }
        case 0x4d414e4d: {
            char* material = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(material, 0);
            m_kMaterialId.Set(material, 0);
            break;
        }
        case 0x4d414e47:
            file->GetChunkData(m_apWaterForms, 12);
            if (file->IsEndianConversionRequired())
            {
                for (int i = 0; i < 3; ++i)
                    BSEndian((unsigned int*)&m_apWaterForms[i], EndianSizeTag<4>());
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0057eef0
// src: XBOX_PDB 0x0057eef0
WaterShaderSettings* TESWaterForm::Sky_GetStarsColor()
{
    return &Data;
}

// @fnv 0x0057f890
// src: XBOX_PDB 0x0057f890
void TESWaterForm::SetSpellItem_0057f890(SpellItem* apSpellItem)
{
    m_pWaterSpell = apSpellItem;
}

// @fnv 0x0057fed0
unsigned int TESWaterForm::GetMember()
{
    return (unsigned int)m_pWaterSpell;
}

// @fnv 0x0057fef0
// src: COMMUNITY 0x0057fef0
void TESWaterForm::SetMaterialName(const char* name)
{
    m_kMaterialId.Set(name, 0);
}

// @fnv 0x00580060
// src: COMMUNITY 0x00580060
bool TESWaterForm::IsDangerous()
{
    if (this->cFlags & 1)
        return true;
    return false;
}

// @fnv 0x00580080
// src: COMMUNITY 0x00580080
unsigned int TESWaterForm::GetNoiseTextureNameLength()
{
    return m_kNoiseMapTexture.GetTextureNameLength();
}


// @fnv 0x005800a0
// src: COMMUNITY 0x005800a0
char const* TESWaterForm::GetNoiseTextureName() const
{
    return const_cast<TESTexture&>(m_kNoiseMapTexture).GetTextureResourceName();
}

// @fnv 0x005800c0
void TESWaterForm::SetNP(void* apValue)
{
    *reinterpret_cast<NP*>(&m_kNoiseTextureData) = apValue;
}

// @fnv 0x005806e0
// src: XBOX_PDB 0x005806e0
void TESWaterForm::SaveGame_005806e0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    TESForm::SaveGame(apSaveGameBuffer);
    if (apSaveGameBuffer->GetChangeFlags(0x80000000).operator bool())
        apSaveGameBuffer->FUN_00865df0(m_pWaterForm, 0);
}

// @fnv 0x005807a0
// src: COMMUNITY 0x005807a0
void TESWaterForm::Revert_005807a0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (static_cast<const BGSLoadFormBuffer*>(apLoadGameBuffer)->GetOldChangeFlags(0x80000000).operator bool())
        *(void**)((char*)this + 0x80) = 0;
}

// BGSPlaceableWater.h does not yet declare the helper at 0x005802f0.
struct FUN_005802f0_shell
{
    void BGSPlaceableWater_SetReflectsLODTrees(bool abFlag);
};
// @fnv 0x005802f0
// src: COMMUNITY 0x005802f0
void FUN_005802f0_shell::BGSPlaceableWater_SetReflectsLODTrees(bool abFlag)
{
    ((BGSPlaceableWater*)this)->BGSPlaceableWater_SetFlag(0x20, abFlag);
}

// @fnv 0x00580730
// src: XBOX_PDB 0x00580730
void TESWaterForm::LoadGame_00580730(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->GetChangeFlags(0x80000000).operator bool())
        m_pWaterForm = dynamic_cast<TESWaterForm*>(TESForm::GetFormByID(apLoadGameBuffer->BGSLoadGameBuffer::ReadFormIdentifier()));
}

// Returns the stored string pointer if the field is nonzero, otherwise an empty string literal.
// @fnv 0x0057fda0
// src: COMMUNITY 0x0057fda0
const char* TESWaterForm::GetMaterialName()
{
    return m_kMaterialId ? (const char*)m_kMaterialId : "";
}

extern double g_d100;
// @fnv 0x00580100
// src: COMMUNITY 0x00580100
float TESWaterForm::GetOpacity_00580100()
{
    return m_ucOpacity / g_d100;
}

// TESForm.h does not yet declare the serialization helper at 0x00485e00.
struct FUN_00485e00_shell
{
    void TESForm_SaveData();
};
void TESForm_AddChunkArray(unsigned int id, void* data, unsigned int size);
void TESForm_AddChunk_3(unsigned int id, unsigned char value);
void TESForm_AddChunk_00485910(unsigned int id, unsigned int value);
void AppendChunk(unsigned int id, void* data, unsigned int size);
void TESForm_AddChunkArray_00485710(unsigned int id, unsigned int* data, unsigned int count);
bool TESForm_QEndianSwapOnSave();

// Serializes the water form: writes name, model, flags, form IDs, and a 0xc4-byte Data block, swapping endianness when needed.
// @fnv 0x0057fbf0
void TESWaterForm::SaveWaterForm()
{
    unsigned int auiFormIds[3];
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();
    TESForm_AddChunkArray(0x4d414e4e, (void*)m_kNoiseMapTexture.GetTextureResourceName(),
                 m_kNoiseMapTexture.GetTextureNameLength() + 1);
    TESForm_AddChunk_3(0x4d414e41, m_ucOpacity);
    TESForm_AddChunk_3(0x4d414e46, cFlags);
    TESForm_AddChunkArray(0x4d414e4d, (void*)GetMaterialName(), m_kMaterialId.Length() + 1);
    if (m_pWaterSound)
    {
        unsigned int itempint = m_pWaterSound->TESForm::GetFormID();
        TESForm_AddChunk_00485910(0x4d414e53, itempint);
    }
    if (m_pWaterSpell)
    {
        unsigned int itempint = m_pWaterSpell->GetFormID();
        TESForm_AddChunk_00485910(0x4d414e58, itempint);
    }
    ((FUN_00485e00_shell*)this)->TESForm_SaveData();
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    AppendChunk(0x4d414e44, &Data, 0xc4);
    if (TESForm_QEndianSwapOnSave())
        Data.Endian();
    for (int i = 0; i < 3; i++)
    {
        if (m_apWaterForms[i])
            auiFormIds[i] = m_apWaterForms[i]->GetFormID();
        else
            auiFormIds[i] = 0;
    }
    TESForm_AddChunkArray_00485710(0x4d414e47, auiFormIds, 3);
    TESForm::FinishFormRecord();
}



extern int __cdecl _memcmp(const void*, const void*, unsigned int);

// @fnv 0x0057ff10
// src: XBOX_PDB 0x0057ff10
bool TESWaterForm::Compare_0057ff10(TESForm* apCompare)
{
    TESWaterForm* pcomp;

    pcomp = dynamic_cast<TESWaterForm*>(apCompare);
    if (pcomp == 0)
        return true;

    if (TESForm::Compare(pcomp))
        return true;

    if (*(unsigned char*)((char*)this + 0x71) != *(unsigned char*)((char*)pcomp + 0x71))
        return true;

    if (*(unsigned char*)((char*)this + 0x70) != *(unsigned char*)((char*)pcomp + 0x70))
        return true;

    if (_memcmp(Sky_GetStarsColor(), pcomp->Sky_GetStarsColor(), 0xc4) != 0)
        return true;

    if (m_kNoiseMapTexture.CompareWithBase(&pcomp->m_kNoiseMapTexture))
        return true;

    if (((TESPackage*)this)->GetRefCount() != ((TESPackage*)pcomp)->GetRefCount())
        return true;

    if (GetMaterialName() != pcomp->GetMaterialName())
        return true;

    if (GetMember() != pcomp->GetMember())
        return true;

    if (_memcmp((char*)this + 0x148, (char*)pcomp + 0x148, 0xc) != 0)
        return true;

    return false;
}

// BGSPlaceableWater.h lacks these three no-op helper declarations.
struct FUN_00580310_t
{
    void SetFlag400(bool);
};

struct FUN_005802d0_shell
{
    void BGSPlaceableWater_SetReflectsLODBuildings(bool);
};

struct FUN_00589f50_shell
{
    void SetSound(void*);
};

void* __cdecl operator new(unsigned int);
int _sprintf_s(char*, unsigned int, const char*, ...);

void FUN_00580310_t::SetFlag400(bool)
{}

// src: COMMUNITY 0x005802d0
void FUN_005802d0_shell::BGSPlaceableWater_SetReflectsLODBuildings(bool)
{}

void FUN_00589f50_shell::SetSound(void*)
{}

// Returns the BGSPlaceableWater stored at offset 0x180, creating and initialising it with editor ID "PlaceableAutoWater" if it is null.
// @fnv 0x00580130
// src: XBOX_PDB 0x00580130
BGSPlaceableWater* TESWaterForm::GetPlaceableAutoWater()
{
    char ptempname[260];

    if (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180) == 0)
    {
        *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180) = new BGSPlaceableWater;

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->NotifySaveLoadGameOfFormChange();

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))->BGSPlaceableWater_SetAutomaticWater(true);

        reinterpret_cast<FUN_00580310_t*>(*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->SetFlag400(true);

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))->BGSPlaceableWater_SetReflectsLODLand(true);

        reinterpret_cast<FUN_005802d0_shell*>(
            *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->BGSPlaceableWater_SetReflectsLODBuildings(true);

        reinterpret_cast<FUN_005802f0_shell*>(
            *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->BGSPlaceableWater_SetReflectsLODTrees(true);

        _sprintf_s(ptempname, 0x104, "PlaceableAutoWater");

        (*reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->SetEditorID_AtRuntime(ptempname);

        reinterpret_cast<FUN_00589f50_shell*>(
            *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180))
            ->SetSound(this);
    }

    return *reinterpret_cast<BGSPlaceableWater**>(reinterpret_cast<char*>(this) + 0x180);
}

// @fnv 0x00580330
// src: XBOX_PDB 0x00580330
BGSPlaceableWater* TESWaterForm::GetPlaceableLODWater()
{
    char ptempname[260];

    if (m_pPlaceableWater == 0)
    {
        m_pPlaceableWater = new BGSPlaceableWater;

        reinterpret_cast<TESForm*>(m_pPlaceableWater)->NotifySaveLoadGameOfFormChange();

        m_pPlaceableWater->SetFlag8000000(true);
        m_pPlaceableWater->BGSPlaceableWater_SetReflectionEnabled(true);
        m_pPlaceableWater->BGSPlaceableWater_SetRefractionEnabled(false);
        m_pPlaceableWater->SetValue(false);
        m_pPlaceableWater->BGSPlaceableWater_SetReflectsLand(false);
        m_pPlaceableWater->BGSPlaceableWater_SetReflectsLODLand(true);

        reinterpret_cast<FUN_005802d0_shell*>(m_pPlaceableWater)->BGSPlaceableWater_SetReflectsLODBuildings(true);

        reinterpret_cast<FUN_005802f0_shell*>(m_pPlaceableWater)->BGSPlaceableWater_SetReflectsLODTrees(false);

        m_pPlaceableWater->BGSPlaceableWater_SetReflectsSky(true);
        m_pPlaceableWater->SetFlag80(false);
        m_pPlaceableWater->SetFlag100(false);

        _sprintf_s(ptempname, 0x104, "PlaceableLODWater");

        reinterpret_cast<TESForm*>(m_pPlaceableWater)->SetEditorID_AtRuntime(ptempname);

        reinterpret_cast<FUN_00589f50_shell*>(m_pPlaceableWater)->SetSound(this);
    }

    return m_pPlaceableWater;
}

// Release the noise texture before destroying the other components.
// @fnv 0x0057ee10
TESWaterForm::~TESWaterForm()
{
    reinterpret_cast<NP*>(&m_kNoiseTextureData)->operator=((void*)0);
}

// @fnv 0x0057eba0
TESWaterForm::TESWaterForm()
    : m_pRenderedTexture(0), m_kTextureScrollLayer0(0.0f, 0.0f, 0.0f, 0.0f),
      m_kTextureScrollLayer1(0.0f, 0.0f, 0.0f, 0.0f), m_kTextureScrollLayer2(0.0f, 0.0f, 0.0f, 0.0f),
      m_kNoiseTextureData(0)
{
    SetFormType((ENUM_FORM_ID)0x4e);
    ResetFormData();
    m_iCurrentTextureSelection1 = 0;
    m_iCurrentTextureSelection2 = 0;
    m_uiNoiseFrequencyX = 9;
    m_uiNoiseFrequencyY = 9;
    m_iNoiseOctaveCount = 4;
    m_fNoiseAmplitude = 0.5f;
    m_fNoiseLacunarity = 2.0f;
    fSideOffset = 0.5f;
    m_fDistanceScale = 0.5f;
    m_pWaterSpell = 0;
    m_bNeedsUpdate = true;
    m_bResetNoiseTextures = false;
    m_pPlaceableAutoWater = 0;
    m_pPlaceableWater = 0;
    m_iRadiationMagnitude = 0;
    m_iHealthMagnitude = 0;
    m_pWaterForm = 0;
}

struct ByteArg
{
    unsigned char c;
};
void BSEndian_00401080(void* p, ByteArg v);
// @fnv 0x0057f3a0
void WaterShaderSettings::Endian()
{
    BSEndian_00401080((char*)this + 0x0, ByteArg());
    BSEndian_00401080((char*)this + 0x4, ByteArg());
    BSEndian_00401080((char*)this + 0x8, ByteArg());
    BSEndian_00401080((char*)this + 0xc, ByteArg());
    BSEndian_00401080((char*)this + 0x10, ByteArg());
    BSEndian_00401080((char*)this + 0x14, ByteArg());
    BSEndian_00401080((char*)this + 0x18, ByteArg());
    BSEndian_00401080((char*)this + 0x1c, ByteArg());
    BSEndian_00401080((char*)this + 0x20, ByteArg());
    BSEndian_00401080((char*)this + 0x24, ByteArg());
    BSEndian_00401080((char*)this + 0x28, ByteArg());
    BSEndian_00401080((char*)this + 0x2c, ByteArg());
    BSEndian_00401080((char*)this + 0x30, ByteArg());
    BSEndian_00401080((char*)this + 0x38, ByteArg());
    BSEndian_00401080((char*)this + 0x3c, ByteArg());
    BSEndian_00401080((char*)this + 0x40, ByteArg());
    BSEndian_00401080((char*)this + 0x44, ByteArg());
    BSEndian_00401080((char*)this + 0x48, ByteArg());
    BSEndian_00401080((char*)this + 0x4c, ByteArg());
    BSEndian_00401080((char*)this + 0x50, ByteArg());
    BSEndian_00401080((char*)this + 0x54, ByteArg());
    BSEndian_00401080((char*)this + 0x58, ByteArg());
    BSEndian_00401080((char*)this + 0x5c, ByteArg());
    BSEndian_00401080((char*)this + 0x60, ByteArg());
    BSEndian_00401080((char*)this + 0x64, ByteArg());
    BSEndian_00401080((char*)this + 0x68, ByteArg());
    BSEndian_00401080((char*)this + 0x6c, ByteArg());
    BSEndian_00401080((char*)this + 0x70, ByteArg());
    BSEndian_00401080((char*)this + 0x74, ByteArg());
    BSEndian_00401080((char*)this + 0x78, ByteArg());
    BSEndian_00401080((char*)this + 0x7c, ByteArg());
    BSEndian_00401080((char*)this + 0x80, ByteArg());
    BSEndian_00401080((char*)this + 0x84, ByteArg());
    BSEndian_00401080((char*)this + 0x88, ByteArg());
    BSEndian_00401080((char*)this + 0x8c, ByteArg());
    BSEndian_00401080((char*)this + 0x90, ByteArg());
    BSEndian_00401080((char*)this + 0x94, ByteArg());
    BSEndian_00401080((char*)this + 0x98, ByteArg());
    BSEndian_00401080((char*)this + 0x9c, ByteArg());
    BSEndian_00401080((char*)this + 0xa0, ByteArg());
    BSEndian_00401080((char*)this + 0xa4, ByteArg());
    BSEndian_00401080((char*)this + 0xa8, ByteArg());
    BSEndian_00401080((char*)this + 0xac, ByteArg());
    BSEndian_00401080((char*)this + 0xb0, ByteArg());
    BSEndian_00401080((char*)this + 0xb4, ByteArg());
    BSEndian_00401080((char*)this + 0xb8, ByteArg());
    BSEndian_00401080((char*)this + 0xbc, ByteArg());
    BSEndian_00401080((char*)this + 0xc0, ByteArg());
}

// @fnv 0x005800e0
// src: COMMUNITY 0x005800e0
void TESWaterForm::GetNoiseTexture(NiPointer<NiTexture>& a1)
{
    a1 = m_kNoiseTextureData;
}

#include <string.h>

// Copies water effect settings from apCopy into this, including flags, opacity, shader, spell item, and noise map texture.
// @fnv 0x0057fde0
// src: XBOX_PDB 0x0057fde0
void TESWaterForm::Copy_0057fde0(TESForm* apCopy)
{
    TESWaterForm* pcopy = dynamic_cast<TESWaterForm*>(apCopy);
    if (!pcopy)
        return;
    TESForm::CopyFrom(pcopy);
    this->cFlags = pcopy->cFlags;
    this->m_ucOpacity = pcopy->m_ucOpacity;
    memcpy(this->Sky_GetStarsColor(), pcopy->Sky_GetStarsColor(), 0xc4);
    reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(
        reinterpret_cast<TESEffectShader*>(reinterpret_cast<TESPackage*>(pcopy)->GetRefCount()));
    this->SetSpellItem(reinterpret_cast<SpellItem*>(pcopy->GetMember()));
    memcpy(reinterpret_cast<unsigned char*>(this) + 0x148, reinterpret_cast<unsigned char*>(pcopy) + 0x148, 0xc);
    this->m_kNoiseMapTexture.CopyFromBase(
        reinterpret_cast<BaseFormComponent*>(reinterpret_cast<unsigned char*>(pcopy) + 0x64));
    SetMaterialName(pcopy->GetMaterialName());
}
