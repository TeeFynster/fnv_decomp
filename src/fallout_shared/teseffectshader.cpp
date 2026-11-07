// fallout_shared/teseffectshader.cpp: TESEffectShader, EffectShaderData and shader helpers (26 functions)

// Keep the generated support templates private; use checked scene and model types.
#define FNV_TESFILE_H  // the shared TESFile below replaces layout_support.h's stub
#include "../../include/NiFile.h"
#include "layout_support.h"
#define FNV_BASEFORMCOMPONENT_H
#include "../../include/NiPoint3.h"
#include "../../include/TESForm.h"
#include "../../include/BGSDebris.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiProperty.h"
#include "../../include/NiBound.h"
#include "../../include/TESModel.h"
#include "../../include/EffectShaderData.h"
#include "../../include/TESEffectShader.h"
#include "../teseffectshader.h"
#include "TESFile.h"
#include "../../include/TESFile.h"

// @fnv 0x00506510
void EffectShaderData::Initialize()
{
    cFlags = 0;
    m_eDestinationBlend = static_cast<_D3DBLEND>(5);
    m_eBlendOperation = static_cast<_D3DBLENDOP>(1);
    m_eDepthCompareFunction = static_cast<_NDLZCMPFUNC>(3);
    BlendDepthState = 0;
    BlendDepthParameters = 0.0f;
    DepthCompareParameters = 0.0f;
    IndexedFloatParameters = 0.0f;
    ShaderFloatParameterSet = 0.0f;
    ShaderParameterFormatSet = 0.0f;
    SevenFloatParameterRecord = 1.0f;
    SixFloatAndUnsignedIntegerRecord = 0.0f;
    SixFloatUnsignedIntegerAndFloatRecord = 0.0f;
    ExtendedFloatFlagParameters = 1.0f;
    ShaderFloatParameterBlock = 0;
    SixFloatRecordWithMiddleFlag = 0.0f;
    FloatFlagParameters = 0.0f;
    SixFloatRecordWithLeadingFlag = 0.0f;
    BlendFloatParameters = 0.0f;
    AlphaBlendParameters = 0.0f;
    BlendStateParameters = 1.0f;
    m_eSourceBlend = static_cast<_D3DBLEND>(6);
    BlendFactorState = 1.0f;
    BlendModeConfiguration = 1.0f;
    m_eAlphaSourceBlend = static_cast<_D3DBLEND>(5);
    m_eAlphaDestinationBlend = static_cast<_D3DBLEND>(6);
    m_eAlphaBlendOperation = static_cast<_D3DBLENDOP>(1);
    m_eAlphaDepthCompareFunction = static_cast<_NDLZCMPFUNC>(4);
    AlphaBlendSettings = 0.0f;
    m_fAlphaBlendParameter = 0.0f;
    BlendFactorParameters = 0.0f;
    m_fShaderFloatParameter1 = 1.0f;
    m_fShaderFloatParameter2 = 1.0f;
    m_fShaderFloatParameter3 = 1.0f;
    m_fShaderFloatParameter4 = 0.0f;
    m_fShaderFloatParameter5 = 0.0f;
    m_fShaderFloatParameter6 = 0.0f;
    VelocityState = NiPoint3(0.0f, 0.0f, 0.0f);
    m_kVectorState2 = NiPoint3(0.0f, 0.0f, 0.0f);
    m_fShaderFloatParameter7 = 1.0f;
    m_fShaderFloatParameter8 = 1.0f;
    m_fShaderFloatParameter9 = 0.0f;
    m_fShaderFloatParameter10 = 1.0f;
    m_uiColorParameter1 = 16777215;
    m_uiColorParameter2 = 16777215;
    m_uiColorParameter3 = 16777215;
    m_fShaderFloatParameter11 = 1.0f;
    m_fShaderFloatParameter12 = 1.0f;
    m_fShaderFloatParameter13 = 1.0f;
    m_fShaderFloatParameter14 = 0.0f;
    m_fShaderFloatParameter15 = 0.5f;
    m_fShaderFloatParameter16 = 1.0f;
    m_fShaderFloatParameter17 = 0.0f;
    m_fShaderFloatParameter18 = 0.0f;
    m_fShaderFloatParameter19 = 0.0f;
    m_fShaderFloatParameter20 = 0.0f;
    m_fShaderFloatParameter21 = 0.0f;
    DebrisModelSettings = 0.0f;
    EffectShaderAddonData = 10.0f;
    DebrisColorSettings = 255.0f;
    EffectShaderColorData = 0.0f;
    EffectShaderParameters = 0.0f;
    m_uiBaseColor = 16777215;
    m_fFloatAfterDefaultColor = 0.0f;
    m_uiIntegerParameter1 = 1;
    m_uiIntegerParameter2 = 1;
    m_fFirstValueAfterIntegerFields = 1.0f;
    m_fSecondValueAfterIntegerFields = 1.0f;
    UnsignedIntAndSixFloatData = 1.0f;
    SixFloatValueSet = 1.0f;
    FiveFloatData = 1.0f;
    FourFloatValueSet = 1.0f;
}

// @fnv 0x00505db0
void TESEffectShader::ResetFormData()
{
    GetData()->Initialize();
}

// @fnv 0x00505dd0
void TESEffectShader::InitItem()
{
    if (IsFormInitialized())
        return;
    unsigned int formID = reinterpret_cast<unsigned int>(GetAddonModels());
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        SetAddonModels(dynamic_cast<BGSDebris*>(GetFormByID(formID)));
    }
    SetInitializationState(true);
}

extern "C" void* __cdecl _alloca(unsigned int size);

// @fnv 0x00505e70
bool TESEffectShader::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x4f)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    int iChunkID;
    while (iChunkID = file->GetChunkID())
    {
        switch (iChunkID)
        {
        case 0x44494445: {
            char* pChunkBuffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pChunkBuffer, 0x200);
            SetEditorID_AtRuntime(pChunkBuffer);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(&m_kFillTexture, file);
            break;
        case 0x324f4349:
            TESTextureLoader::ReadTextureData(&m_kParticleShaderTexture, file);
            break;
        case 0x374d414e:
            TESTextureLoader::ReadTextureData(&m_kHolesTexture, file);
            break;
        case 0x41544144:
            if (file->IsEndianConversionRequired())
                Data.Endian();
            ReadTypedData(file, &Data, sizeof(Data));
            if (file->IsEndianConversionRequired())
                Data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (Data.m_fShaderFloatParameter1 <= 1.0 && Data.m_fShaderFloatParameter1 > 0.0)
        Data.m_fShaderFloatParameter1 *= ParticleShader::GetShaderParticleCount();
    if (Data.m_fShaderFloatParameter2 <= 1.0 && Data.m_fShaderFloatParameter2 > 0.0)
        Data.m_fShaderFloatParameter2 *= ParticleShader::GetShaderParticleCount();
    return true;
}

// @fnv 0x00507040
// src: XBOX_PDB 0x00507040
bool TESEffectShader::IsFlagSet_00507040(unsigned int mask)
{
    return *(unsigned char*)GetData() & mask;
}

struct FUN_005050b0 : TESForm
{
    ~FUN_005050b0();
};
// @fnv 0x005050b0
FUN_005050b0::~FUN_005050b0()
{}

// @fnv 0x00506370
TESTexture* TESEffectShader::GetFieldAt14C()
{
    return reinterpret_cast<TESTexture*>(&m_kFillTexture);
}

// @fnv 0x00506390
TESTexture* TESEffectShader::GetFieldAt158()
{
    return reinterpret_cast<TESTexture*>(&m_kParticleShaderTexture);
}

// @fnv 0x005063b0
TESTexture* TESEffectShader::GetFieldAt164()
{
    return reinterpret_cast<TESTexture*>(&m_kHolesTexture);
}

extern "C" void __cdecl ParticleShader_Stop(NiAVObject*, ParticleShaderProperty*);

// @fnv 0x00507810
// src: COMMUNITY 0x00507810
void TESEffectShader::StopParticleShader(NiAVObject* aiArg1, ParticleShaderProperty* aiArg2)
{
    ParticleShader_Stop(aiArg1, aiArg2);
}

// @fnv 0x00507b00
float __fastcall GetEffectShaderScale(TESEffectShader* shader)
{
    return shader->Data.ExtendedFloatFlagParameters;
}

// @fnv 0x00507b20
float __fastcall GetEffectShaderCount(TESEffectShader* shader)
{
    return shader->Data.DebrisColorSettings;
}

struct Color;
class ParticleShaderProperty
{
  public:
    void SetParticleTime(float);
    void ParticleShaderProperty_SetTexture0x118(void*);
    void SetWaterLODHeight(float);
    void ParticleShaderProperty_SetLifetimeVar(float);
    void SkyShaderProperty_SetBlendValue(float);
    void bhkCharacterControllerCinfo_SetAcrobatics(float);
    void FUN_006e29d0(float);
    void SetData(NiPoint3);
    void ParticleShaderProperty_SetAcceleration(NiPoint3);
    void LowProcess_SetDeathTime(float);
    void bhkCharacterControllerCinfo_SetScale(float);
    void PathingRequestClosePoint_SetMinDistance(float);
    void SetMaxDistance_006e5ee0(float);
    void FUN_00507780(float);
    void SetBoltSmallWidth(float);
    void BoltShaderProperty_SetSegmentVariance(float);
    void SetPoint(Color);
    void ParticleShaderProperty_SetColor2(Color);
    void ParticleShaderProperty_SetColor3(Color);
    void PathingRequestCoveredMove_SetAttackerHeight(float);
    void PathingRequestCoveredMove_SetAttackerSneakHeight(float);
    void PathingRequestCoveredMove_SetAttackerHealth(float);
    void SetFieldAtOffsetF4_005076e0(float);
    void NiCamera_SetMinNearPlaneDist(float);
    void NiCamera_SetMaxFarNearRatio(float);
    void SetFieldAtOffset100_00507720(float);
    void PathingRequestCoveredMove_SetCombatCoverSearchInfo(int);
    void FUN_00505e50(int);
    void ParticleShaderProperty_SetBlendOp(int);
    void ParticleShaderProperty_SetZTestFunc(int);
};
ParticleShaderProperty* __cdecl ParticleShader_Start(NiAVObject*, NiAVObject*);
// @fnv 0x005077c0
ParticleShaderProperty* TESEffectShader::CreateParticleShaderProperty(NiAVObject* apRootObject, NiAVObject* apTargetObject,
                                                        NiSourceTexture* apTex, float afTime)
{
    ParticleShaderProperty* pProp;
    if (apTex)
    {
        pProp = ParticleShader_Start(apRootObject, apTargetObject);
        CopySettingsTo(pProp, apTex);
        pProp->SetParticleTime(afTime);
        return pProp;
    }
    return 0;
}

// @fnv 0x00505d20
TESEffectShader::~TESEffectShader()
{}

void __cdecl _memcpy(void* dst, const void* src, unsigned int n);
// Copies a TESEffectShader's data, base component and three textures into this object after a dynamic_cast check.
// @fnv 0x005062a0
void TESEffectShader::CopyFrom(const TESForm* apCopy)
{
    TESEffectShader* pcopy = dynamic_cast<TESEffectShader*>(const_cast<TESForm*>(apCopy));
    if (!pcopy)
        return;
    TESForm::CopyFrom(pcopy);
    _memcpy(GetData(), pcopy->GetData(), 0x134);
    m_kFillTexture.CopyFromBase((BaseFormComponent*)pcopy->GetFieldAt14C());
    m_kParticleShaderTexture.CopyFromBase((BaseFormComponent*)pcopy->GetFieldAt158());
    m_kHolesTexture.CopyFromBase((BaseFormComponent*)pcopy->GetFieldAt164());
}

int __cdecl _memcmp(const void*, const void*, unsigned int);
// Compares this effect shader with apCompare: returns true if apCompare is not a TESEffectShader or any component or the shader data differs.
// @fnv 0x005063d0
bool TESEffectShader::Compare(TESForm* apCompare)
{
    TESEffectShader* pOtherShader = dynamic_cast<TESEffectShader*>(apCompare);
    if (!pOtherShader)
        return true;
    if (TESForm::Compare(pOtherShader))
        return true;
    if (m_kFillTexture.CompareWithBase((BaseFormComponent*)pOtherShader->GetFieldAt14C()))
        return true;
    if (m_kParticleShaderTexture.CompareWithBase(
            (BaseFormComponent*)pOtherShader->GetFieldAt158()))
        return true;
    if (m_kHolesTexture.CompareWithBase((BaseFormComponent*)pOtherShader->GetFieldAt164()))
        return true;
    if (_memcmp(&Data, pOtherShader->GetData(), sizeof(EffectShaderData)))
        return true;
    return false;
}

struct FUN_0048e370_obj
{
    void TESTexture_Save(unsigned int);
};

void TESForm_AddChunkArray(unsigned int, void*, unsigned int);

bool _FUN_00401500();

// @fnv 0x005060f0
void TESEffectShader::SaveForm()
{
    TESForm::BeginFormRecord();

    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x14c)->GetModelLength() == 0)
    {
        TESForm_AddChunkArray(0x4e4f4349, reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x14c)->GetFullName(),
                     reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x14c)->GetModelLength() + 1);
    }
    else
    {
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x14c)->TESTexture_Save(0x4e4f4349);
    }

    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x158)->GetModelLength() == 0)
    {
        TESForm_AddChunkArray(0x324f4349, reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x158)->GetFullName(),
                     reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x158)->GetModelLength() + 1);
    }
    else
    {
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x158)->TESTexture_Save(0x324f4349);
    }

    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x164)->GetModelLength() == 0)
    {
        TESForm_AddChunkArray(0x374d414e, reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x164)->GetFullName(),
                     reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x164)->GetModelLength() + 1);
    }
    else
    {
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x164)->TESTexture_Save(0x374d414e);
    }

    BGSDebris* psaveAddon = Data.pAddonModels;

    Data.pAddonModels =
        Data.pAddonModels
            ? reinterpret_cast<BGSDebris*>(Data.pAddonModels->GetFormID())
            : 0;

    if (_FUN_00401500())
    {
        Data.Endian();
    }

    TESForm::TESForm___SaveData(&Data, sizeof(Data));

    if (_FUN_00401500())
    {
        Data.Endian();
    }

    Data.pAddonModels = psaveAddon;

    TESForm::FinishFormRecord();
}

// @fnv 0x005064d0
EffectShaderData::EffectShaderData()
{
    Initialize();
}

struct FUN_005074e0_vec4
{
    float x;
    float y;
    float z;
    float w;
};

class FUN_005074e0_cls
{
  public:
    FUN_005074e0_vec4 m_v;
    FUN_005074e0_vec4* DivideByScalar(FUN_005074e0_vec4* out, float s);
};

// Copies m_v into a local vector, divides each of its four components by s, stores the result in out and returns out.
// @fnv 0x005074e0
FUN_005074e0_vec4* FUN_005074e0_cls::DivideByScalar(FUN_005074e0_vec4* out, float s)
{
    FUN_005074e0_vec4 vDivided = m_v;
    vDivided.x = vDivided.x / s;
    vDivided.y = vDivided.y / s;
    vDivided.z = vDivided.z / s;
    vDivided.w = vDivided.w / s;
    *out = vDivided;
    return out;
}

struct NiPropStub
{
    NiFixedString& GetName();
};

struct ShaderPropStub
{
    void ApplyTexEffect(void* apData);
};

int BSstrcmp(const char*, const char*);

// @fnv 0x00507b40
void TESEffectShader::ApplyShaderToTree(NiAVObject* apObject, BSShaderPPLightingProperty::TextureEffectData* apData)
{
    if (apObject)
    {
        if (apObject->IsGeometry())
        {
            NiProperty* pProp = apObject->GetProperty(3);
            ShaderPropStub* pShader;
            if ((pShader = (!pProp ? 0 : (pProp->FUN_00441110() >= 8 && pProp->FUN_00441110() <= 12))
                               ? (ShaderPropStub*)pProp
                               : 0) != 0)
            {
                bool bApply = true;
                if (IsFlagSet_00507040(0x20))
                {
                    NiPropStub* pNameProp = reinterpret_cast<NiPropStub*>(apObject->GetProperty(2));
                    if (!(const char*)pNameProp->GetName() || BSstrcmp(pNameProp->GetName(), "skin"))
                    {
                        bApply = false;
                    }
                }
                if (bApply)
                {
                    pShader->ApplyTexEffect(apData);
                }
            }
        }
        else
        {
            NiNode* pNode = apObject->IsSceneNode();
            if (pNode)
            {
                for (unsigned int i = 0; i < pNode->FUN_0043b480(); i++)
                {
                    ApplyShaderToTree(pNode->FUN_0043b4a0(i), apData);
                }
            }
        }
    }
}

struct S_00507c90_Ptr;
struct S_00507c90_Item
{
    int FUN_00441110();
    S_00507c90_Ptr* FOPipboyManager_Get3rdPersonPipboyRoot();
    void AssignRefObj(S_00507c90_Ptr* p);
};
struct S_00507c90_Cls
{
    void ClearItemRef(NiAVObject* obj, S_00507c90_Ptr* ref);
};
// Recursively walks obj's list, and for items whose value is 8..12 clears the reference if it equals ref.
// @fnv 0x00507c90
void S_00507c90_Cls::ClearItemRef(NiAVObject* obj, S_00507c90_Ptr* ref)
{
    if (obj)
    {
        if (obj->IsGeometry())
        {
            S_00507c90_Item* t_ = reinterpret_cast<S_00507c90_Item*>(obj->GetProperty(3));
            S_00507c90_Item* s;
            if ((s = (!t_ ? 0 : (t_->FUN_00441110() >= 8 && t_->FUN_00441110() <= 12)) ? t_ : 0) != 0)
            {
                if (s->FOPipboyManager_Get3rdPersonPipboyRoot() == ref)
                    s->AssignRefObj(0);
            }
        }
        else
        {
            NiNode* list = obj->IsSceneNode();
            if (list)
            {
                for (unsigned int i2 = 0; i2 < (unsigned int)list->FUN_0043b480(); i2++)
                    ClearItemRef(list->FUN_0043b4a0(i2), ref);
            }
        }
    }
}

struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
    Color operator/(float);
};

// Copies the effect shader's Data fields into dest via its setters, converting three packed RGB values into normalized Colors with separate alpha values.
// @fnv 0x00507060
void TESEffectShader::CopySettingsTo(ParticleShaderProperty* apDestination, NiSourceTexture* apTexture)
{
    apDestination->ParticleShaderProperty_SetTexture0x118(apTexture);
    apDestination->SetWaterLODHeight(Data.m_fShaderFloatParameter3);
    apDestination->ParticleShaderProperty_SetLifetimeVar(Data.m_fShaderFloatParameter4);
    apDestination->SkyShaderProperty_SetBlendValue(Data.m_fShaderFloatParameter5);
    apDestination->bhkCharacterControllerCinfo_SetAcrobatics(Data.m_fShaderFloatParameter6);
    apDestination->FUN_006e29d0(Data.m_fShaderFloatParameter17);
    apDestination->SetData(Data.VelocityState);
    apDestination->ParticleShaderProperty_SetAcceleration(Data.m_kVectorState2);
    apDestination->LowProcess_SetDeathTime(Data.m_fShaderFloatParameter18);
    apDestination->bhkCharacterControllerCinfo_SetScale(Data.m_fShaderFloatParameter19);
    apDestination->PathingRequestClosePoint_SetMinDistance(Data.m_fShaderFloatParameter20);
    apDestination->SetMaxDistance_006e5ee0(Data.m_fShaderFloatParameter21);
    apDestination->FUN_00507780(Data.m_uiIntegerParameter1);
    apDestination->SetBoltSmallWidth(Data.m_uiIntegerParameter2);
    apDestination->BoltShaderProperty_SetSegmentVariance(Data.m_fFloatAfterDefaultColor);
    Color color1 = Color((unsigned char)(Data.m_uiColorParameter1 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter1 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter1 >> 16) & 255), 0.0f) /
                   255.0f;
    Color color2 = Color((unsigned char)(Data.m_uiColorParameter2 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter2 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter2 >> 16) & 255), 0.0f) /
                   255.0f;
    Color color3 = Color((unsigned char)(Data.m_uiColorParameter3 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter3 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter3 >> 16) & 255), 0.0f) /
                   255.0f;
    color1.a = Data.m_fShaderFloatParameter11;
    color2.a = Data.m_fShaderFloatParameter12;
    color3.a = Data.m_fShaderFloatParameter13;
    apDestination->SetPoint(color1);
    apDestination->ParticleShaderProperty_SetColor2(color2);
    apDestination->ParticleShaderProperty_SetColor3(color3);
    apDestination->PathingRequestCoveredMove_SetAttackerHeight(Data.m_fShaderFloatParameter14);
    apDestination->PathingRequestCoveredMove_SetAttackerSneakHeight(Data.m_fShaderFloatParameter15);
    apDestination->PathingRequestCoveredMove_SetAttackerHealth(Data.m_fShaderFloatParameter16);
    apDestination->SetFieldAtOffsetF4_005076e0(Data.m_fShaderFloatParameter7);
    apDestination->NiCamera_SetMinNearPlaneDist(Data.m_fShaderFloatParameter8);
    apDestination->NiCamera_SetMaxFarNearRatio(Data.m_fShaderFloatParameter9);
    apDestination->SetFieldAtOffset100_00507720(Data.m_fShaderFloatParameter10);
    apDestination->PathingRequestCoveredMove_SetCombatCoverSearchInfo(Data.m_eAlphaSourceBlend);
    apDestination->FUN_00505e50(Data.m_eAlphaDestinationBlend);
    apDestination->ParticleShaderProperty_SetBlendOp(Data.m_eAlphaBlendOperation);
    apDestination->ParticleShaderProperty_SetZTestFunc(Data.m_eAlphaDepthCompareFunction);
}

struct ColorValue
{
    float x, y, z, w;
    ColorValue(float, float, float, float);
    ColorValue Normalize(float);
};
struct RefValue
{
    void* value;
    RefValue& operator=(void*);
};
struct EffectData
{
    int unk00, unk04;
    RefValue root;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    ColorValue fill, edge;
    float unk4c, unk50, scale, diameter;
    unsigned int unk5c, unk60, unk64, unk68;
    RefValue target;
    unsigned int unk70;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    EffectData();
};
struct ShaderSource
{
    unsigned int Fill();
    unsigned int Edge();
    unsigned int Mode();
    unsigned int Value60();
    unsigned int Value64();
    unsigned int Value68();
};
// @fnv 0x00507830
BSShaderPPLightingProperty::TextureEffectData* TESEffectShader::CreateEffectData(
    NiAVObject* scene, NiSourceTexture* root, NiSourceTexture* target)
{
    EffectData* data2 = new EffectData;
    unsigned int fill = reinterpret_cast<ShaderSource*>(this)->Fill();
    unsigned int edge = reinterpret_cast<ShaderSource*>(this)->Edge();
    data2->root = 0;
    data2->fill =
        ColorValue((float)(unsigned char)(fill & 255), (float)(unsigned char)((unsigned short)fill >> 8 & 255),
                   (float)(unsigned char)(fill >> 16 & 255), 0.0f)
            .Normalize(255.0f);
    data2->edge =
        ColorValue((float)(unsigned char)(edge & 255), (float)(unsigned char)((unsigned short)edge >> 8 & 255),
                   (float)(unsigned char)(edge >> 16 & 255), 0.0f)
            .Normalize(255.0f);
    data2->unk4c = 0.0f;
    data2->unk50 = 0.0f;
    data2->scale = GetEffectShaderScale(this);
    data2->diameter = scene->GetBound().FUN_0084d030() * 2.0f;
    data2->unk5c = reinterpret_cast<ShaderSource*>(this)->Mode();
    data2->unk60 = reinterpret_cast<ShaderSource*>(this)->Value60();
    data2->unk64 = reinterpret_cast<ShaderSource*>(this)->Value64();
    data2->unk68 = reinterpret_cast<ShaderSource*>(this)->Value68();
    data2->root = root;
    data2->target = target;
    data2->unk70 = (unsigned int)GetEffectShaderCount(this);
    if (IsFlagSet_00507040(16))
    {
        data2->edge.x += -1.0;
        data2->edge.y += -1.0;
        data2->edge.z += -1.0;
    }
    return reinterpret_cast<BSShaderPPLightingProperty::TextureEffectData*>(data2);
}

struct Color4
{
    float x, y, z, w;
};
struct ShaderState
{
    int unk00, unk04, unk08;
    Color4 fill, edge, baseFill, baseEdge;
    float u, v;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned int alpha;
};
float __cdecl BSMAX_00404010(float, float);
float __cdecl BSMIN(float, float);
float __cdecl LinearInterpolate(float, float, float, float, float);
struct ShaderUpdate
{
    float UpdateFill(float, float, float, unsigned char);
    float FillPulse(float);
    float UpdateEdge(float, float, float, unsigned char);
    float EdgePulse(float);
    float USpeed();
    float VSpeed();
    float EndTime();
    float StartTime();
    float EndAlpha();
    float StartAlpha();
    void UpdateShaderState(ShaderState*, float, float, float, unsigned char);
};
// Advances a ShaderState's fill/edge alpha, UV offsets and alpha from delta, duration, time and mode.
// @fnv 0x00507e30
void ShaderUpdate::UpdateShaderState(ShaderState* state, float delta, float duration, float time, unsigned char mode)
{
    if (state)
    {
        state->baseFill.w = UpdateFill(state->baseFill.w, delta, duration, mode);
        state->fill = state->baseFill;
        state->fill.w = FillPulse(time) * state->fill.w + state->fill.w;
        state->fill.w = BSMIN(1.0f, BSMAX_00404010(0.0f, state->fill.w));
        state->baseEdge.w = UpdateEdge(state->baseEdge.w, delta, duration, mode);
        state->edge = state->baseEdge;
        state->edge.w = EdgePulse(time) * state->edge.w + state->edge.w;
        state->edge.w = BSMIN(1.0f, BSMAX_00404010(0.0f, state->edge.w));
        state->u = USpeed() * delta + state->u;
        state->v = VSpeed() * delta + state->v;
        float boundedTime = BSMIN(StartTime(), BSMAX_00404010(EndTime(), time));
        state->alpha = (unsigned int)LinearInterpolate(StartAlpha(), EndAlpha(), EndTime(), StartTime(), boundedTime);
    }
}

struct SwapFlag
{
    bool value;
};
extern "C" void __cdecl BSEndian_00401080(void* field, bool reverseBytes);
// @fnv 0x00506850
void EffectShaderData::Endian()
{
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eDestinationBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eBlendOperation, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eDepthCompareFunction, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendDepthState, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendDepthParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&DepthCompareParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&IndexedFloatParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&ShaderFloatParameterSet, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&ShaderParameterFormatSet, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&SevenFloatParameterRecord, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&SixFloatAndUnsignedIntegerRecord, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&SixFloatUnsignedIntegerAndFloatRecord, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&ExtendedFloatFlagParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&ShaderFloatParameterBlock, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&SixFloatRecordWithMiddleFlag, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&FloatFlagParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&SixFloatRecordWithLeadingFlag, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendFloatParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&AlphaBlendParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendStateParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendFactorState, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendModeConfiguration, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eSourceBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eAlphaSourceBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eAlphaBlendOperation, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eAlphaDepthCompareFunction, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_eAlphaDestinationBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&AlphaBlendSettings, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fAlphaBlendParameter, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&BlendFactorParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter1, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter2, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter3, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter4, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter5, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter6, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&VelocityState.x, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&VelocityState.y, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&VelocityState.z, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_kVectorState2.x, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_kVectorState2.y, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_kVectorState2.z, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter7, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter8, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter9, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter10, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_uiColorParameter1, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_uiColorParameter2, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_uiColorParameter3, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter11, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter12, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter13, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter14, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter15, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter16, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter17, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter18, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter19, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter20, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fShaderFloatParameter21, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&DebrisModelSettings, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&EffectShaderAddonData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&DebrisColorSettings, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&EffectShaderColorData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&EffectShaderParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_uiBaseColor, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fFloatAfterDefaultColor, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_uiIntegerParameter1, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_uiIntegerParameter2, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fFirstValueAfterIntegerFields, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&m_fSecondValueAfterIntegerFields, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&UnsignedIntAndSixFloatData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&SixFloatValueSet, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&FiveFloatData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        BSEndian_00401080(&FourFloatValueSet, needsEndianSwap.value);
    }
}
