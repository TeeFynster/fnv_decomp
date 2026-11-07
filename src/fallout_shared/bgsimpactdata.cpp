// fallout_shared/bgsimpactdata.cpp: BGSImpactData and impact-data helpers (14 functions)

#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "bgsimpactdata.h"
#include "../../include/BGSImpactData.h"
#include <string.h>
#include <malloc.h>
#include "../../include/TESFile.h"

static const char s_textureSetWarning[] = "MASTERFILE: Unable to find texture set (%08X) on impact data %s (%08X).";
static const char s_soundWarning[] = "MASTERFILE: Unable to find sound (%08X) on impact data %s (%08X).";

// @fnv 0x0058db40
BGSImpactData::BGSImpactData()
{
    SetFormType(ENUM_FORM_ID_IPCT_ID);
    ResetFormData();
}

// @fnv 0x0058dc90
void BGSImpactData::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
    Data.m_fEffectDuration = 0.25f;
    Data.m_eOrientation = BGSImpactData__ORIENTATION_ORIENT_PROJ_REFLECT;
    Data.m_fAngleThreshold = 15.0f;
    Data.m_fPlacementRadius = 16.0f;
    m_pDecalTextureSet = 0;
    m_pPrimaryImpactSound = 0;
    m_pSecondaryImpactSound = 0;
    Data.m_eSoundLevel = _SoundLevel::NORMAL;
}

// Loads a BGSImpactData record from a TESFile, reading the DATA chunk (old or new layout), editor ID, OBND, model, decal texture set and sound references.
// @fnv 0x0058dea0
bool BGSImpactData::LoadForm(TESFile* file)
{
    if (static_cast<TESFileFormInt*>(file)->GetTESForm() != ENUM_FORM_ID_IPCT_ID)
        return false;
    LoadRecordHeader(file);
    if (file->IsEndianConversionRequired())
        Data.Endian();
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C444F4D:  // MODL
        case 0x54444F4D:  // MODT
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        case 0x41544144:  // DATA
            if (static_cast<TESFileFormVersion*>(file)->GetFormVersion() < 10)
            {
                BGSImpactData__OLD_IMPACT_DATA_DATA oldData;
                memset(&oldData, 0, sizeof(oldData));
                ReadTypedData(file, &oldData, sizeof(oldData));
                if (file->IsEndianConversionRequired())
                    oldData.Endian();
                memset(&Data, 0, sizeof(Data));
                Data.m_fEffectDuration = oldData.m_fEffectDuration;
                Data.m_eOrientation = oldData.m_eOrientation;
                Data.m_fAngleThreshold = oldData.m_fAngleThreshold;
                Data.m_fPlacementRadius = oldData.m_fPlacementRadius;
                Data.m_eSoundLevel = oldData.m_eSoundLevel;
                ImpactDecalInfo.GetData()->m_fDecalMinWidth = oldData.m_fDecalMinWidth;
                ImpactDecalInfo.GetData()->m_fDecalMaxWidth = oldData.m_fDecalMaxWidth;
                ImpactDecalInfo.GetData()->m_fDecalMinHeight = oldData.m_fDecalMinHeight;
                ImpactDecalInfo.GetData()->m_fDecalMaxHeight = oldData.m_fDecalMaxHeight;
                ImpactDecalInfo.GetData()->m_fProjectionDepth = oldData.m_fProjectionDepth;
                ImpactDecalInfo.GetData()->m_fShininess = oldData.m_fShininess;
                ImpactDecalInfo.GetData()->m_fParallaxScale = oldData.m_fParallaxScale;
                ImpactDecalInfo.GetData()->m_ucParallaxPasses = oldData.m_ucParallaxPasses;
                ImpactDecalInfo.GetData()->cFlags = oldData.cFlags;
                ImpactDecalInfo.GetData()->iColor = oldData.iColor;
            }
            else
            {
                memset(&Data, 0, sizeof(Data));
                ReadTypedData(file, &Data, sizeof(Data));
                if (file->IsEndianConversionRequired())
                    Data.Endian();
            }
            break;
        case 0x54444F44:  // DODT
            ImpactDecalInfo.Load(file);
            break;
        case 0x4D414E44:  // DNAM
        {
            unsigned int textureSetID = 0;
            file->GetChunkData(&textureSetID);
            SetDecalTextureSet(reinterpret_cast<BGSTextureSet*>(textureSetID));
            break;
        }
        case 0x4D414E53:  // SNAM
        {
            unsigned int sound1ID = 0;
            file->GetChunkData(&sound1ID);
            SetSound1(reinterpret_cast<TESSound*>(sound1ID));
            break;
        }
        case 0x314D414E:  // NAM1
        {
            unsigned int sound2ID = 0;
            file->GetChunkData(&sound2ID);
            SetSound2(reinterpret_cast<TESSound*>(sound2ID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the texture set and two sound form IDs, warns on failed lookups, then copies decal data from the texture set and marks the form initialized.
// @fnv 0x0058e560
void BGSImpactData::InitItem()
{
    if (static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))->IsFormInitialized())
        return;
    unsigned int formID = reinterpret_cast<unsigned int>(m_pDecalTextureSet);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pDecalTextureSet = dynamic_cast<BGSTextureSet*>(TESFormInitFlag::GetFormByID(formID));
        if (m_pDecalTextureSet)
        {
            // Texture set resolved.
        }
        else
            Warning(s_textureSetWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(m_pPrimaryImpactSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pPrimaryImpactSound = dynamic_cast<TESSound*>(TESFormInitFlag::GetFormByID(formID));
        if (m_pPrimaryImpactSound)
        {
            // Sound resolved.
        }
        else
            Warning(s_soundWarning, formID, GetName(), GetFormID());
    }
    formID = reinterpret_cast<unsigned int>(m_pSecondaryImpactSound);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSecondaryImpactSound = dynamic_cast<TESSound*>(TESFormInitFlag::GetFormByID(formID));
        if (m_pSecondaryImpactSound)
        {
            // Sound resolved.
        }
        else
            Warning(s_soundWarning, formID, GetName(), GetFormID());
    }
    CopyDecalDataFromTextureSet();
    SetInitializationState(true);
}

// @fnv 0x0058dc10
BGSImpactData::~BGSImpactData()
{}

extern const char DAT_01183028[];
extern const char DAT_011862fc[];

void* __cdecl FUN_00ec43fb(int arg, int zero, const void* data1, const void* data2, int zero2);
void* __cdecl FUN_00401460(void* dst, const void* src, unsigned int size);

struct FUN_005054b0_shell
{
    void __thiscall TESForm_CopyAllComponents(TESForm* form);
};

struct FUN_005932b0_decal
{
    void __thiscall FUN_005932b0(FUN_005932b0_decal* source);
};

// @fnv 0x0058dd10
// src: XBOX_PDB 0x0058dd10
void __thiscall BGSImpactData::Copy_0058dd10(int arg)
{
    BGSImpactData* source =
        reinterpret_cast<BGSImpactData*>(FUN_00ec43fb(arg, 0, DAT_01183028, DAT_011862fc, 0));

    if (source == 0)
        return;

    reinterpret_cast<FUN_005054b0_shell*>(this)->TESForm_CopyAllComponents(source);
    FUN_00401460(reinterpret_cast<char*>(this) + 0x30, reinterpret_cast<char*>(source) + 0x30, 0x18);
    reinterpret_cast<FUN_005932b0_decal*>(reinterpret_cast<char*>(this) + 0x54)
        ->FUN_005932b0(reinterpret_cast<FUN_005932b0_decal*>(reinterpret_cast<char*>(source) + 0x54));
    m_pDecalTextureSet = source->m_pDecalTextureSet;
    m_pPrimaryImpactSound = source->m_pPrimaryImpactSound;
    m_pSecondaryImpactSound = source->m_pSecondaryImpactSound;
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};
struct FUN_005932e0_shell
{
    bool Compare(void*);
};
// Returns true if apCompare is not BGSImpactData or a checked comparison reports a difference.
// @fnv 0x0058dda0
bool BGSImpactData::IsDifferentFrom(TESForm* apCompare)
{
    BGSImpactData* pOther = dynamic_cast<BGSImpactData*>(apCompare);
    if (!pOther)
        return true;
    if (((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(pOther))
        return true;
    if (memcmp((char*)this + 0x30, (char*)pOther + 0x30, 0x18) != 0)
        return true;
    if (!IsFlagSet() &&
        ((FUN_005932e0_shell*)((char*)this + 0x54))->Compare((char*)pOther + 0x54))
        return true;
    if (m_pDecalTextureSet != pOther->m_pDecalTextureSet)
        return true;
    if (m_pPrimaryImpactSound != pOther->m_pPrimaryImpactSound)
        return true;
    if (m_pSecondaryImpactSound != pOther->m_pSecondaryImpactSound)
        return true;
    return false;
}

// @fnv 0x0058de80
bool __thiscall BGSImpactData::IsFlagSet()
{
    return (Data.cFlags & 1) ? true : false;
}

struct TagX
{
};
void BSEndian_00401080(void* p, TagX t);
class SelfX
{
  public:
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    void SwapMemberByteOrder();
};
// Calls FUN_00401080 with TagX() for each listed member.
// @fnv 0x0058e250
// src: GUESS 0x0058e250 (confidence: medium)
void SelfX::SwapMemberByteOrder()
{
    BSEndian_00401080(&m00, TagX());
    BSEndian_00401080(&m14, TagX());
    BSEndian_00401080(&m1c, TagX());
    BSEndian_00401080(&m20, TagX());
    BSEndian_00401080(&m04, TagX());
    BSEndian_00401080(&m08, TagX());
    BSEndian_00401080(&m0c, TagX());
    BSEndian_00401080(&m18, TagX());
    BSEndian_00401080(&m24, TagX());
    BSEndian_00401080(&m28, TagX());
    BSEndian_00401080(&m2c, TagX());
    BSEndian_00401080(&m30, TagX());
    BSEndian_00401080(&m34, TagX());
}

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);

// Calls BSEndian on this object at byte offsets 0, 4, 8, 12, and 16.
// @fnv 0x0058e3a0
void BGSImpactData__IMPACT_DATA_DATA::Endian()
{
    BSEndian((unsigned char*)this, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 4, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 8, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 12, EndianSizeTag<1>());
    BSEndian((unsigned char*)this + 16, EndianSizeTag<1>());
}

struct FUN_00485e00_shell
{
    void TESForm___SaveData(int, int);
};

struct FUN_00593320_shell
{
    void ProcessState_00593320(void*);
};

bool _FUN_00401500();
void _FUN_00485910(int, int);

// Calls base helpers, processes bytes at offset 0x30, and passes non-null form IDs to _FUN_00485910.
// @fnv 0x0058e450
// src: XBOX_PDB 0x0058e450
void BGSImpactData::Save_0058e450()
{
    TESForm::BeginFormRecord();

    reinterpret_cast<TESModel*>(reinterpret_cast<unsigned char*>(this) + 0x18)
        ->WriteToBuffer(0x4c444f4d, 0x54444f4d);

    if (_FUN_00401500())
    {
        reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x30)->Endian();
    }

    reinterpret_cast<FUN_00485e00_shell*>(this)->TESForm___SaveData(
        reinterpret_cast<int>(reinterpret_cast<unsigned char*>(this) + 0x30), 0x18);

    if (_FUN_00401500())
    {
        reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x30)->Endian();
    }

    if (!IsFlagSet())
    {
        reinterpret_cast<FUN_00593320_shell*>(reinterpret_cast<unsigned char*>(this) + 0x54)
            ->ProcessState_00593320(reinterpret_cast<void*>(0x54444f44));
    }

    {
        unsigned int itempint;

        if (m_pDecalTextureSet)
        {
            itempint = m_pDecalTextureSet->GetFormID();
            _FUN_00485910(0x4d414e44, itempint);
        }
    }

    {
        unsigned int itempint;

        if (m_pPrimaryImpactSound)
        {
            itempint = m_pPrimaryImpactSound->GetFormID();
            _FUN_00485910(0x4d414e53, itempint);
        }
    }

    {
        unsigned int itempint;

        if (m_pSecondaryImpactSound)
        {
            itempint = m_pSecondaryImpactSound->GetFormID();
            _FUN_00485910(0x314d414e, itempint);
        }
    }

    TESForm::FinishFormRecord();
}

void* __fastcall BGSTextureSet_GetDecalData(char*);
void* DecalData_GetDefaultDecalData();
// DecalData::Copy is 0x005932b0 (see decaldata.cpp); the shared BGSImpactData.h omits it.
struct DecalDataCopy
{
    void Copy(DecalData*);
};

// When the flag is set, copies decal data from the texture set or the default data.
// @fnv 0x0058e730
void BGSImpactData::CopyDecalData()
{
    if (IsFlagSet())
    {
        if (GetDecalTextureSet())
        {
            reinterpret_cast<DecalDataCopy*>(reinterpret_cast<char*>(this) + 0x54)
                ->Copy(reinterpret_cast<DecalData*>(
                    BGSTextureSet_GetDecalData(reinterpret_cast<char*>(GetDecalTextureSet()))));
        }
        else
        {
            reinterpret_cast<DecalDataCopy*>(reinterpret_cast<char*>(this) + 0x54)
                ->Copy(reinterpret_cast<DecalData*>(DecalData_GetDefaultDecalData()));
        }
    }
}

struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011cd3b4;
extern GlobalObject_0045cfe0 g_011cd538;
extern GlobalObject_0045cfe0 g_011cdde0;

// Returns the int value of one of three global objects selected by the member at offset 0x40.
// @fnv 0x0058e790
int BGSImpactData::GetGlobalValue()
{
    int result = 0;
    switch (Data.m_eSoundLevel)
    {
    case 2:
        result = *g_011cd3b4.Int();
        break;
    case 1:
        result = *g_011cd538.Int();
        break;
    case 0:
        result = *g_011cdde0.Int();
        break;
    }
    return result;
}
