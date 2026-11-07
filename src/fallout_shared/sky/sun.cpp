// fallout_shared/sky/sun.cpp: Sun and NiPick (11 functions)

#include "../../../include/BSShaderAccumulator.h"
#include "../../../include/BSShaderManager.h"
#include "../../../include/Sun.h"
#include "../../../include/Setting.h"
#include "../../../include/AutoMemContext.h"
#include "../../../include/BSAudio.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/NiBillboardNode.h"
#include "../../../include/NiDirectionalLight.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPick.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPointLight.h"
#include "../../../include/NiTriBasedGeom.h"
#include "../../../include/NiTriShape.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiColorA.h"
#include "../../../include/Sky.h"
#include "../../../include/SkyObject.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESObjectTREE.h"
#include "../../../include/TESWeather.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/Transform.h"
#include "../../../include/AnimIdle.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BaseFormComponent.h"
#include "../../../include/NP.h"
#include "../../../include/NiColor.h"
#include "../../../include/TESFullName.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/BGSTerrainManager.h"

// Select sized deletion on constructor failure; the shared class also has
// an unsized overload. Inherit the checked layout and allocation function.
struct SunAccumulatorAllocation : BSShaderAccumulator
{
    SunAccumulatorAllocation(BSShaderManager::BATCHRENDERER_CREATION_MODE, unsigned int, unsigned int);
    static void operator delete(void*, unsigned int);
};

// Initializes the Sun object's fields to zero and creates a BSShaderAccumulator for SunMode, disabling occlusion tests.
// @fnv 0x006404f0
Sun::Sun()
    : m_pFirstSceneObject(0), m_pSecondSceneObject(0), m_pThirdSceneObject(0), m_pFourthSceneObject(0),
      m_pMenuLight(0), m_pSunShaderAccumulator(0)
{
    m_pRootNode = 0;
    m_pFirstSceneObject = 0;
    m_pSecondSceneObject = 0;
    m_pThirdSceneObject = 0;
    m_pFourthSceneObject = 0;
    m_pMenuLight = 0;
    m_pSunGlarePick = 0;
    m_fSunGlareIntensity = 0.0f;
    bDoOcclusionTests = false;
    m_pSunShaderAccumulator = reinterpret_cast<NiAVObject*>(new SunAccumulatorAllocation(BSShaderManager::BRCM_NO_GROUPS, 1, 1));
}

// @fnv 0x00461110
// src: XBOX_PDB 0x00461110
int __fastcall Sky_GetSunColor(int param_1)
{
    return param_1 + 0x78;
}

// @fnv 0x00514f30
// src: XBOX_PDB 0x00514f30
int __fastcall Sky_GetSunLightSpecularColor(int this_ptr)
{
    return this_ptr + 0xC0;
}

// Destroys the NiPick object and, when flags has bit 0 set, frees its memory via operator delete; returns this.
// @fnv 0x006407e0
void* NiPick::ScalarDeletingDestructor(unsigned int flags)
{
    NiPick::~NiPick();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl _Deallocate(void*);
struct SunDestruction
{
    void* ScalarDeletingDestructor(unsigned int);
};
// @fnv 0x00640670
void* SunDestruction::ScalarDeletingDestructor(unsigned int flags)
{
    ((Sun*)this)->Sun::~Sun();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00642660
void NiMatrix3::SetEntry(unsigned int aiRow, unsigned int aiColumn, float afValue)
{
    reinterpret_cast<float (*)[3]>(&m_pEntry[0][0])[aiRow][aiColumn] = afValue;
}

class BSShaderNoLightingProperty;
class BSShaderPPLightingProperty;
class BSShaderProperty;
class BSShaderTextureSet;
class NiAlphaController;
class NiMaterialColorController;
struct NiStream;
class SkyShaderProperty;
class TileShaderProperty;
namespace fnv_00640810 {
struct BSMaterialEmittanceMultController;
struct BSRefractionFirePeriodController;
struct BSRefractionStrengthController;
struct TallGrassShaderProperty;
struct VolumetricFogShaderProperty;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct ShaderPropertyConversionData
{
    void Convert(NiAVObject*, unsigned int);
    void CheckTextureAlphas();
    void AddShaderProperty(NiAVObject*);
    void AddMaterialProperty(NiAVObject*);
    void AddAlphaProperty(NiAVObject*);
    BSShaderProperty* GetShaderProperty();
    void SetupShaderFlags(BSShaderProperty*, NiAVObject*);
    void SetupTexturesPPLightingShader(BSShaderPPLightingProperty*);
    void SetupDataPPLightingShader(BSShaderPPLightingProperty*);
    void SetupTexturesNoLightingShader(BSShaderNoLightingProperty*);
    void SetupDataVolumetricFogShader(VolumetricFogShaderProperty*);
    void SetupTexturesTallGrassShader(TallGrassShaderProperty*);
    void SetupTexturesSkyShader(SkyShaderProperty*);
    void SetupDataSkyShader(SkyShaderProperty*);
    void SetupTexturesTileShader(TileShaderProperty*);
    bool IsValidProperty(NiAVObject*, BSShaderProperty*);
    int m_iShaderType;
    char m_kAmbientColor[12];
    char m_kDiffuseColor[12];
    float m_fShininess;
    float fAlpha;
    float m_fEmittanceMultiplier;
    NiMaterialColorController* m_pAmbientColorController;
    NiMaterialColorController* m_pDiffuseColorController;
    NiAlphaController* m_pAlphaController;
    BSMaterialEmittanceMultController* m_pEmittanceMultiplierController;
    bool m_bHasMaterialProperty;
    char _pad_39[3];
    int m_iShaderFlags1;
    int m_iShaderFlags2;
    bool m_bHasAlphaProperty;
    char _pad_45[3];
    int m_iShaderOption;
    unsigned char m_uiShaderOptionByte;
    bool m_bShaderFeature1;
    bool m_bShaderFeature2;
    bool m_bShaderFeature3;
    bool m_bShaderFeature4;
    bool m_bShaderFeature5;
    bool m_bShaderFeature6;
    bool m_bShaderFeatureActive;
    bool m_bShaderFeature8;
    bool m_bShaderFeature9;
    bool m_bShaderFeature10;
    bool m_bShaderFeature11;
    float m_fValueBeforeTextureCount;
    bool m_bShaderFeature12;
    char _pad_5d[3];
    int m_iTextureCount;
    BSRefractionStrengthController* m_pRefractionStrengthController;
    BSRefractionFirePeriodController* m_pRefractionFirePeriodController;
    bool m_bShaderFeature13;
    bool m_bShaderFeature14;
    char _pad_6e[2];
    float m_fRefractionStrength;
    float m_fRefractionFirePeriod;
    char m_kSpecularColor[12];
    float m_fShaderParameter1;
    bool m_bShaderFeature15;
    bool m_bShaderFeature16;
    bool m_bShaderFeature17;
    char _pad_8b[1];
    float m_fShaderParameter2;
    int m_iShaderOptionIndex;
    bool m_bShaderFeature18;
    char _pad_95[3];
    // The shader conversion initializer constructs this color later.
    unsigned char m_kEmissiveColor[sizeof(NiColorA)];
    BSShaderTextureSet* m_pTextureSet;
    char m_cTrailingBytes[7];
    char _pad_b3[1];
    int m_iShaderDataFlags;
};
typedef char _sizecheck_BSShaderData[sizeof(ShaderPropertyConversionData) == 184 ? 1 : -1];


struct C3;

// The shared billboard layout lacks these flag/facing setters.
// Declare only the missing operations and sized allocation cleanup here.
struct SunBillboardNode : NiBillboardNode
{
    SunBillboardNode();
    static void operator delete(void*, unsigned int);
    void NiAVObject_SetSelectiveUpdate(bool);
    void SetMode_0051d000(int);
};
// Preserve the original sized delete call when construction fails. The shared
// NiAVObject allocation interface also declares an unsized delete overload.
template <class T> struct SunAllocated : T
{
    SunAllocated();
    static void operator delete(void*, unsigned int);
};
struct QuantityData
{
    void SetQuantity(unsigned int);
};
struct FUN_00baf3c0_S
{
    void FUN_00baf3c0();
};
struct FUN_00bb0180_S
{
    void AddProperties(NiAVObject*, unsigned int);
};
void* __cdecl _NiMalloc(unsigned int);

extern Setting g_011cce7c;
extern Setting g_011cce50;
extern NiColor DAT_011a9b7c;
extern NiPoint3 _NiPoint3_ZERO;

}  // namespace fnv_00640810

using namespace fnv_00640810;

// NiPoint3.h has only an implicit copy assignment. Prevent MSVC from
// inlining it so these calls retain the original out-of-line assignment ABI.
#pragma inline_depth(0)

// @fnv 0x00640810
void Sun::Init(NiNode* apSkyRoot)
{
    NiPoint3* psunNormals;
    NiPoint3* pglareNormals;
    NiColorA* psunColors;
    unsigned short* sglareVertOrder;
    NiPoint3* pglareVertices;
    NiColorA* pglareColors;
    ShaderPropertyConversionData bsshaderdata;
    unsigned short* ssunVertOrder;
    NiPoint3* psunVertices;
    NiPoint2* psunTexture;
    NiPoint2* pglareTexture;

    ((Sun*)this)->SkyObject::Initialize(apSkyRoot);

    psunVertices = new NiPoint3[4];
    psunVertices[0] = NiPoint3(-1.0 * *g_011cce7c.Float(), *g_011cce7c.Float(), 0.0f);
    psunVertices[1] = NiPoint3(-1.0 * *g_011cce7c.Float(), -1.0 * *g_011cce7c.Float(), 0.0f);
    psunVertices[2] = NiPoint3(*g_011cce7c.Float(), *g_011cce7c.Float(), 0.0f);
    psunVertices[3] = NiPoint3(*g_011cce7c.Float(), -1.0 * *g_011cce7c.Float(), 0.0f);

    psunNormals = new NiPoint3[4];
    psunNormals[0] = _NiPoint3_ZERO;
    psunNormals[1] = _NiPoint3_ZERO;
    psunNormals[2] = _NiPoint3_ZERO;
    psunNormals[3] = _NiPoint3_ZERO;

    pglareVertices = new NiPoint3[4];
    pglareVertices[0] = NiPoint3(-1.0 * *g_011cce50.Float(), *g_011cce50.Float(), 0.0f);
    pglareVertices[1] = NiPoint3(-1.0 * *g_011cce50.Float(), -1.0 * *g_011cce50.Float(), 0.0f);
    pglareVertices[2] = NiPoint3(*g_011cce50.Float(), *g_011cce50.Float(), 0.0f);
    pglareVertices[3] = NiPoint3(*g_011cce50.Float(), -1.0 * *g_011cce50.Float(), 0.0f);

    pglareNormals = new NiPoint3[4];
    pglareNormals[0] = _NiPoint3_ZERO;
    pglareNormals[1] = _NiPoint3_ZERO;
    pglareNormals[2] = _NiPoint3_ZERO;
    pglareNormals[3] = _NiPoint3_ZERO;

    {
        NiColorA defaultColor(1.0f, 0.0f, 0.0f, 1.0f);

        psunColors = ::new NiColorA[4];
        psunColors[0] = defaultColor;
        psunColors[1] = defaultColor;
        psunColors[2] = defaultColor;
        psunColors[3] = defaultColor;

        pglareColors = ::new NiColorA[4];
        pglareColors[0] = defaultColor;
        pglareColors[1] = defaultColor;
        pglareColors[2] = defaultColor;
        pglareColors[3] = defaultColor;
    }

    psunTexture = ::new NiPoint2[4];
    psunTexture[0] = NiPoint2(0.0f, 0.0f);
    psunTexture[1] = NiPoint2(0.0f, 1.0f);
    psunTexture[2] = NiPoint2(1.0f, 0.0f);
    psunTexture[3] = NiPoint2(1.0f, 1.0f);

    pglareTexture = ::new NiPoint2[4];
    pglareTexture[0] = NiPoint2(0.0f, 0.0f);
    pglareTexture[1] = NiPoint2(0.0f, 1.0f);
    pglareTexture[2] = NiPoint2(1.0f, 0.0f);
    pglareTexture[3] = NiPoint2(1.0f, 1.0f);

    ssunVertOrder = (unsigned short*)_NiMalloc(sizeof(unsigned short) * 6);
    ssunVertOrder[0] = 0;
    ssunVertOrder[1] = 1;
    ssunVertOrder[2] = 2;
    ssunVertOrder[3] = 2;
    ssunVertOrder[4] = 1;
    ssunVertOrder[5] = 3;

    sglareVertOrder = (unsigned short*)_NiMalloc(sizeof(unsigned short) * 6);
    sglareVertOrder[0] = 0;
    sglareVertOrder[1] = 1;
    sglareVertOrder[2] = 2;
    sglareVertOrder[3] = 2;
    sglareVertOrder[4] = 1;
    sglareVertOrder[5] = 3;

    (NP&)((Sun*)this)->m_pThirdSceneObject =
        new NiTriShape(4, psunVertices, psunNormals, psunColors, psunTexture, 1, 0, 2, ssunVertOrder);
    ((NiTriShape*)((const NP&)((Sun*)this)->m_pThirdSceneObject).Modelloader_GetReferencedThis())->NiAVObject_SetSelectiveUpdate(true);

    (NP&)((Sun*)this)->m_pFirstSceneObject = new SunBillboardNode;
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pFirstSceneObject).Modelloader_GetReferencedThis())->NiAVObject_SetSelectiveUpdate(true);
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pFirstSceneObject).Modelloader_GetReferencedThis())->SetMode_0051d000(2);
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pFirstSceneObject).Modelloader_GetReferencedThis())
        ->AttachChildInAvailableSlot((NiTriShape*)((const NP&)((Sun*)this)->m_pThirdSceneObject).Modelloader_GetReferencedThis(), true);

    (NP&)((Sun*)this)->m_pFourthSceneObject =
        new NiTriShape(4, pglareVertices, pglareNormals, pglareColors, pglareTexture, 1, 0, 2, sglareVertOrder);
    ((NiTriShape*)((const NP&)((Sun*)this)->m_pFourthSceneObject).Modelloader_GetReferencedThis())->NiAVObject_SetSelectiveUpdate(true);

    (NP&)((Sun*)this)->m_pSecondSceneObject = new SunBillboardNode;
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pSecondSceneObject).Modelloader_GetReferencedThis())->NiAVObject_SetSelectiveUpdate(true);
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pSecondSceneObject).Modelloader_GetReferencedThis())->SetMode_0051d000(2);
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pSecondSceneObject).Modelloader_GetReferencedThis())
        ->NiAVObject_SetScale(((Sun*)this)->m_fSunGlareIntensity);
    ((SunBillboardNode*)((const NP&)((Sun*)this)->m_pSecondSceneObject).Modelloader_GetReferencedThis())
        ->AttachChildInAvailableSlot((NiTriShape*)((const NP&)((Sun*)this)->m_pFourthSceneObject).Modelloader_GetReferencedThis(), true);

    ((NiNode*)((const NP&)((Sun*)this)->m_pRootNode).Modelloader_GetReferencedThis())
        ->AttachChildInAvailableSlot((NiAVObject*)((const NP&)((Sun*)this)->m_pFirstSceneObject).Modelloader_GetReferencedThis(), true);

    (NP&)((Sun*)this)->m_pMenuLight = new SunAllocated<NiDirectionalLight>;
    ((NiPointLight*)((const NP&)((Sun*)this)->m_pMenuLight).Modelloader_GetReferencedThis())->NiLight_SetDimmer(1.0f);
    ((NiDirectionalLight*)((const NP&)((Sun*)this)->m_pMenuLight).Modelloader_GetReferencedThis())->SetAmbientColor(DAT_011a9b7c);
    ((NiPointLight*)((const NP&)((Sun*)this)->m_pMenuLight).Modelloader_GetReferencedThis())
        ->SetEffectColor((const NiPoint3&)DAT_011a9b7c);
    ((NiNode*)((const NP&)((Sun*)this)->m_pRootNode).Modelloader_GetReferencedThis())
        ->AttachChildInAvailableSlot((NiDirectionalLight*)((const NP&)((Sun*)this)->m_pMenuLight).Modelloader_GetReferencedThis(), true);

    ((Sun*)this)->m_pSunGlarePick = new NiPick(0, 8);
    // NiPick.h lacks these two setters; retain their existing out-of-line calls.
    ((QuantityData*)((Sun*)this)->m_pSunGlarePick)->SetQuantity(1);
    ((TESObjectREFR*)((Sun*)this)->m_pSunGlarePick)->SetFlags(1);
    ((NiPick*)((Sun*)this)->m_pSunGlarePick)->RadioEntry_Data_SetLastSignalStrength(true);
    ((NiPick*)((Sun*)this)->m_pSunGlarePick)->SetByteAtOffset17(true);

    ((FUN_00baf3c0_S*)&bsshaderdata)->FUN_00baf3c0();
    bsshaderdata.m_iShaderType = 6;
    bsshaderdata.m_iShaderOptionIndex = 0;
    ((FUN_00bb0180_S*)&bsshaderdata)
        ->AddProperties((NiTriShape*)((const NP&)((Sun*)this)->m_pThirdSceneObject).Modelloader_GetReferencedThis(), 1);
    bsshaderdata.m_iShaderOptionIndex = 1;
    ((FUN_00bb0180_S*)&bsshaderdata)
        ->AddProperties((NiTriShape*)((const NP&)((Sun*)this)->m_pFourthSceneObject).Modelloader_GetReferencedThis(), 1);
}

class Actor;
class Atmosphere;
class BGSAcousticSpace;
struct BGSEncounterZone;
class BGSLightingTemplate;
class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
struct BGSMusicType;
class BGSSaveFormBuffer;
class BGSSaveGameBuffer;
class BSFile;
class BSMultiBoundNode;
class BSPortalGraph;
class CellMopp;
class Clouds;
class ExtraDataList;
class FormRecordHeader;
class HWND__;
class InteriorData;
class ImageSpaceModifierInstanceForm;
class IntSeenData;
struct InventoryChanges;
class Moon;
class NavMeshCollection;
class NiCamera;
class NiFogProperty;
class NiRenderedTexture;
struct NiStream;
class Precipitation;
class SeenData;
class SkyTextureManager;
class Stars;
class TESActorBase;
class TESBoundObject;
class TESClimate;
class TESFile;
class TESForm;
class TESGlobal;
struct TESImageSpace;
class TESObject;
class TESObjectCELL;
class TESObjectLAND;
class TESRegionObjectBase;
struct TESWaterForm;
class TESWorldSpace;
class bhkWorld;
class TES;
namespace fnv_00641830 {
struct BSFogProperty;
struct CHUNK;
struct CellRecord;
struct ExteriorData;
struct TESFileGroup;
struct ImpactSwap;
struct LoadedCellData;
struct TESRegionList;
struct RegionPoint;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
// Sun.h does not yet declare the update and occlusion entry points.
// This adapter adds only their declarations; all object storage comes from Sun.
struct SunUpdate : public Sun
{
    void UpdateSun(Sky*, float);
    float Sun_GetSunOcclusionPercent();
    void Sun_StopSunOcclusion();
};

struct C3;
struct V3;
struct GlobalObject_0044f440
{
    float FUN_00450410();
};
struct CP_008c48d0
{
    TESObjectCELL* GetPrevPath();
};
struct KFModel
{
    NiAVObject* GetControllerSequence();
};
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct Cell_S
{
    unsigned int GetDataDirectionalXY();
    unsigned int GetDirectionalZ();
};
float __cdecl fabsf_00408860(float);
float __cdecl pow_004dd130(float, float);
bool TESWaterSystem_GetPlayerUnderwater();
NiAVObject* __fastcall BSSceneGraph_GetCameraRoot(NiNode*);
NiNode* Main_GetWorldSceneGraph();
float __fastcall Sky_GetSunriseBegin(char*);
float __fastcall Sky_GetSunriseEnd(char*);
float __fastcall Sky_GetSunsetBegin(char*);
float __fastcall Sky_GetSunsetEnd(void*);
float __fastcall Sky_GetCurrentWeatherPct(const char*);
float __fastcall GetFieldEC(const char*);
void __fastcall _ref_006815c0(void*);
int __fastcall _ref_0084e3a0(TES*);
extern Setting originalRuntimeFloatSetting80;
extern Setting originalRuntimeFloatSetting81;
extern Setting originalRuntimeFloatSetting82;
extern Setting originalRuntimeFloatSetting83;
extern Setting originalRuntimeFloatSetting84;
extern Setting originalRuntimeFloatSetting85;
extern TES* g_TES;
extern NiPoint3 _NiPoint3_ZERO;
extern NiMatrix3 DAT_011a9448;
extern float DAT_0104f2a8;
extern const double DAT_01023128;
extern double DAT_01011588;
extern float _DAT_010162c0;

template <class T> struct SunUninitialized
{
    void* storage[(sizeof(T) + sizeof(void*) - 1) / sizeof(void*)];
};

// These values use raw storage because the original performs no constructor calls.
#define SUN_VALUE(type, name) (*reinterpret_cast<type*>(&name))

// @fnv 0x00641830
void SunUpdate::UpdateSun(Sky* apSky, float afSecondsPassed)
{
    AutoMemContext tempMemContext(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sun.cpp",
                                  300);
    SunUninitialized<NiPoint3> newLoc;
    SUN_VALUE(NiPoint3, newLoc) = _NiPoint3_ZERO;
    float fhour = GetFieldEC((const char*)apSky);
    this->SkyObject::Update(apSky, afSecondsPassed);
    if (apSky->Sky_GetMode() == 0)
    {
        SunUninitialized<NiMatrix3> lightDir;
        SUN_VALUE(NiMatrix3, lightDir) = DAT_011a9448;
        TESObjectCELL* pcell = g_TES ? ((CP_008c48d0*)g_TES)->GetPrevPath() : 0;
        if (pcell)
        {
            SunUninitialized<NiMatrix3> rotmat;
            _ref_006815c0(&SUN_VALUE(NiMatrix3, rotmat));
            SUN_VALUE(NiMatrix3, lightDir).MakeZRotation(((Cell_S*)pcell)->GetDataDirectionalXY() * DAT_01023128);
            SUN_VALUE(NiMatrix3, rotmat).MakeYRotation(((Cell_S*)pcell)->GetDirectionalZ() * DAT_01023128);
            SUN_VALUE(NiMatrix3, lightDir) =
                static_cast<const NiMatrix3&>(SUN_VALUE(NiMatrix3, lightDir)) *
                SUN_VALUE(NiMatrix3, rotmat);
        }
        else
        {
            SUN_VALUE(NiMatrix3, lightDir).SetEntry(1, 0, DAT_0104f2a8);
            SUN_VALUE(NiMatrix3, lightDir).SetEntry(2, 0, DAT_0104f2a8);
        }
        ((NiAVObject*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())->SetLocalRotation(SUN_VALUE(NiMatrix3, lightDir));
        ((NiDirectionalLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
            ->SetAmbientColor(*(const NiColor*)((TESDataHandler*)apSky)->GetTESRaceList());
        ((NiPointLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
            ->SetEffectColor(*(const NiPoint3*)((TESObjectTREE*)apSky)->GetData());
        ((NiPointLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
            ->FUN_0050dd50(*(const NiPoint3*)((TESDataHandler*)apSky)->GetTESCaravanDeckList());
    }
    else if (apSky->Sky_GetMode() == 1)
    {
        SunUninitialized<NiMatrix3> lightDir;
        SUN_VALUE(NiMatrix3, lightDir) = DAT_011a9448;
        TESObjectCELL* pcell = g_TES ? ((CP_008c48d0*)g_TES)->GetPrevPath() : 0;
        if (pcell)
        {
            SunUninitialized<NiMatrix3> rotmat;
            _ref_006815c0(&SUN_VALUE(NiMatrix3, rotmat));
            SUN_VALUE(NiMatrix3, lightDir).MakeZRotation(((Cell_S*)pcell)->GetDataDirectionalXY() * DAT_01023128);
            SUN_VALUE(NiMatrix3, rotmat).MakeYRotation(((Cell_S*)pcell)->GetDirectionalZ() * DAT_01023128);
            SUN_VALUE(NiMatrix3, lightDir) =
                static_cast<const NiMatrix3&>(SUN_VALUE(NiMatrix3, lightDir)) *
                SUN_VALUE(NiMatrix3, rotmat);
        }
        else
        {
            SUN_VALUE(NiMatrix3, lightDir).SetEntry(1, 0, DAT_0104f2a8);
            SUN_VALUE(NiMatrix3, lightDir).SetEntry(2, 0, DAT_0104f2a8);
        }
        ((NiAVObject*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())->SetLocalRotation(SUN_VALUE(NiMatrix3, lightDir));
        ((NiDirectionalLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
            ->SetAmbientColor(*(const NiColor*)((TESDataHandler*)apSky)->GetTESRaceList());
        ((NiPointLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
            ->SetEffectColor(*(const NiPoint3*)((TESObjectTREE*)apSky)->GetData());
        ((NiPointLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
            ->FUN_0050dd50(*(const NiPoint3*)((TESDataHandler*)apSky)->GetTESCaravanDeckList());
    }
    else if (apSky->Sky_GetMode() == 3 || apSky->Sky_GetMode() == 2)
    {
        ((NiAVObject*)((const NP&)m_pRootNode).Modelloader_GetReferencedThis())
            ->SetAppCulled(!((NiAVObject*)((const NP&)m_pRootNode).Modelloader_GetReferencedThis())->GetDisplayObject());
        float fSunriseBegin = (Sky_GetSunriseEnd((char*)apSky) + Sky_GetSunriseBegin((char*)apSky)) / 2.0;
        float fSunsetEnd = (Sky_GetSunsetEnd(apSky) + Sky_GetSunsetBegin((char*)apSky)) / 2.0;
        float fhalftrans = *originalRuntimeFloatSetting82.Float() * DAT_01011588;
        float fAlphaInBegin = fSunriseBegin - fhalftrans;
        float fAlphaInEnd = fSunriseBegin + fhalftrans;
        float fAlphaOutBegin = fSunsetEnd - fhalftrans;
        float fAlphaOutEnd = fSunsetEnd + fhalftrans;
        float fDiscAlpha = 1.0f;
        if (!(fAlphaInBegin <= fhour && fhour <= fAlphaOutEnd))
        {
            fDiscAlpha = 0.0f;
        }
        else if (fAlphaInBegin < fhour && fhour < fAlphaInEnd)
        {
            fDiscAlpha = (fhour - fAlphaInBegin) / (fAlphaInEnd - fAlphaInBegin);
        }
        else if (fAlphaOutBegin < fhour && fhour < fAlphaOutEnd)
        {
            fDiscAlpha = 1.0f - (fhour - fAlphaOutBegin) / (fAlphaOutEnd - fAlphaOutBegin);
        }
        TESWeather* pCurr = (TESWeather*)((BSAudio*)apSky)->GetAudioBackendData();
        TESWeather* pLast = (TESWeather*)((AnimIdle*)apSky)->GetSection();
        float fCurrPct = Sky_GetCurrentWeatherPct((const char*)apSky);
        float fGlareAlpha = (pCurr ? pCurr->GetWeatherData(4, fCurrPct * fDiscAlpha, 0.0f) : fDiscAlpha) +
                            (pLast ? pLast->GetWeatherData(4, (1.0f - fCurrPct) * fDiscAlpha, 0.0f) : 0.0f);
        void* pshadeProperty =
            ((((PropHelper*)((const NP&)m_pThirdSceneObject).Modelloader_GetReferencedThis())->GetProperty(3) == 0)
                 ? 0
                 : (((BGSTerrainManager*)((PropHelper*)((const NP&)m_pThirdSceneObject).Modelloader_GetReferencedThis())->GetProperty(3))
                        ->GetMinLevel() == 13))
                ? ((PropHelper*)((const NP&)m_pThirdSceneObject).Modelloader_GetReferencedThis())->GetProperty(3)
                : 0;
        if (pshadeProperty)
        {
            *(NiColorA*)((char*)pshadeProperty + 0x60) =
                NiColorA(((float*)((TESDataHandler*)apSky)->GetBGSCameraShotList())[0],
                          ((float*)((TESDataHandler*)apSky)->GetBGSCameraShotList())[1],
                          ((float*)((TESDataHandler*)apSky)->GetBGSCameraShotList())[2], fDiscAlpha);
        }
        pshadeProperty =
            ((((PropHelper*)((const NP&)m_pFourthSceneObject).Modelloader_GetReferencedThis())->GetProperty(3) == 0)
                 ? 0
                 : (((BGSTerrainManager*)((PropHelper*)((const NP&)m_pFourthSceneObject).Modelloader_GetReferencedThis())->GetProperty(3))
                        ->GetMinLevel() == 13))
                ? ((PropHelper*)((const NP&)m_pFourthSceneObject).Modelloader_GetReferencedThis())->GetProperty(3)
                : 0;
        if (pshadeProperty)
        {
            *(NiColorA*)((char*)pshadeProperty + 0x60) =
                NiColorA(((float*)((TESDataHandler*)apSky)->GetBGSCameraShotList())[0],
                          ((float*)((TESDataHandler*)apSky)->GetBGSCameraShotList())[1],
                          ((float*)((TESDataHandler*)apSky)->GetBGSCameraShotList())[2], fGlareAlpha);
        }
        {
            float fxNewAim = 0.0f;
            SunUninitialized<NiMatrix3> newSunRot;
            SUN_VALUE(NiMatrix3, newSunRot) = DAT_011a9448;
            float ftemp;
            SunUninitialized<NiPoint3> ksundirection;
            if (fAlphaInBegin < fhour && fhour < fAlphaOutEnd)
            {
                ftemp = (fhour - fAlphaInBegin) / (fAlphaOutEnd - fAlphaInBegin);
                fxNewAim = (1.0 - 2.0 * ftemp) * *originalRuntimeFloatSetting83.Float();
            }
            else if (fhour >= fAlphaOutEnd)
            {
                ftemp = (fhour - fAlphaOutEnd) / (24.0 - (fAlphaOutEnd - fAlphaInBegin));
                fxNewAim = (2.0 * ftemp - 1.0) * *originalRuntimeFloatSetting83.Float();
            }
            else if (fhour <= fAlphaInBegin)
            {
                ftemp = (24.0 - fAlphaOutEnd + fhour) / (24.0 - (fAlphaOutEnd - fAlphaInBegin));
                fxNewAim = (2.0 * ftemp - 1.0) * *originalRuntimeFloatSetting83.Float();
            }
            SUN_VALUE(NiPoint3, newLoc).x = fxNewAim;
            SUN_VALUE(NiPoint3, newLoc).y = ((GlobalObject_0044f440*)&originalRuntimeFloatSetting84)->FUN_00450410();
            SUN_VALUE(NiPoint3, newLoc).z = fabsf_00408860(((GlobalObject_0044f440*)&originalRuntimeFloatSetting83)->FUN_00450410()) -
                       fabsf_00408860(fxNewAim);
            ((NiAVObject*)((const NP&)m_pRootNode).Modelloader_GetReferencedThis())->NiAVObject_SetTranslate((const NiPoint3&)SUN_VALUE(NiPoint3, newLoc));
            ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())->NiAVObject_SetTranslate((const NiPoint3&)SUN_VALUE(NiPoint3, newLoc));
            ((NiPoint3*)&SUN_VALUE(NiPoint3, ksundirection))
                ->Set(-fxNewAim, ((GlobalObject_0044f440*)&originalRuntimeFloatSetting84)->FUN_00450410(),
                      ((GlobalObject_0044f440*)&originalRuntimeFloatSetting85)->FUN_00450410());
            SUN_VALUE(NiPoint3, ksundirection).ComputeMagnitude();
            ((Transform::Mat*)&SUN_VALUE(NiMatrix3, newSunRot))
                ->FUN_004769c0(0, (const NiPoint3&)SUN_VALUE(NiPoint3, ksundirection));
            ((NiAVObject*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())->SetLocalRotation(SUN_VALUE(NiMatrix3, newSunRot));
            ((NiDirectionalLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
                ->SetAmbientColor(*(const NiColor*)((TESDataHandler*)apSky)->GetTESRaceList());
            ((NiPointLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
                ->SetEffectColor(*(const NiPoint3*)((TESObjectTREE*)apSky)->GetData());
            ((NiPointLight*)((const NP&)m_pMenuLight).Modelloader_GetReferencedThis())
                ->FUN_0050dd50(*(const NiPoint3*)((TESDataHandler*)apSky)->GetTESCaravanDeckList());
        }
        if (g_TES && _ref_0084e3a0(g_TES))
        {
            SunUninitialized<NiPoint3> origin;
            SUN_VALUE(NiPoint3, origin) = *(NiPoint3*)((TESDataHandler*)BSSceneGraph_GetCameraRoot(Main_GetWorldSceneGraph()))->GetTESEyesList();
            SunUninitialized<NiPoint3> direction;
            SUN_VALUE(NiPoint3, direction) = SUN_VALUE(NiPoint3, newLoc);
            float fscaleChange = *originalRuntimeFloatSetting81.Float() * afSecondsPassed;
            SUN_VALUE(NiPoint3, direction).ComputeMagnitude();
            bool bblocked =
                this->Sun_GetSunOcclusionPercent() >= 1.0 || (((EffectSetting*)g_TES)->GetEffectID(), TESWaterSystem_GetPlayerUnderwater());
            float fscale = pow_004dd130(1.0f - this->Sun_GetSunOcclusionPercent(), _DAT_010162c0);
            this->Sun_StopSunOcclusion();
            if (bblocked || fscale < *originalRuntimeFloatSetting80.Float())
            {
                if (this->m_fSunGlareIntensity - fscaleChange < *originalRuntimeFloatSetting80.Float())
                {
                    ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())->SetAppCulled(true);
                    this->m_fSunGlareIntensity = 0.0f;
                }
                else
                {
                    ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())->SetAppCulled(false);
                    this->m_fSunGlareIntensity -= fscaleChange;
                    ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())
                        ->NiAVObject_SetScale(this->m_fSunGlareIntensity);
                }
            }
            else
            {
                if (this->m_fSunGlareIntensity + fscaleChange >= fscale ||
                    this->m_fSunGlareIntensity >= fscale)
                {
                    this->m_fSunGlareIntensity = fscale;
                }
                else
                {
                    this->m_fSunGlareIntensity += fscaleChange;
                }
                ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())->SetAppCulled(false);
                ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())
                    ->NiAVObject_SetScale(this->m_fSunGlareIntensity);
            }
            if (!((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())->GetDisplayObject())
            {
                ((NiAVObject*)((const NP&)m_pSecondSceneObject).Modelloader_GetReferencedThis())->SetAppCulled(true);
            }
        }
        if (apSky->IsFlag4Set())
        {
            ((KFModel*)this)->GetControllerSequence()->SetAppCulled(true);
        }
        else
        {
            ((KFModel*)this)->GetControllerSequence()->SetAppCulled(false);
        }
    }
}

#pragma inline_depth()

#undef SUN_VALUE
}  // namespace fnv_00641830


// @fnv 0x00642680
bool Sky::IsFlag4Set()
{
    return 0 < (uiFlags & 4);
}

// @fnv 0x006406a0
Sun::~Sun()
{
    m_pRootNode = 0;
    m_pFirstSceneObject = 0;
    m_pSecondSceneObject = 0;
    m_pThirdSceneObject = 0;
    m_pFourthSceneObject = 0;
    m_pMenuLight = 0;
    if (m_pSunGlarePick)
        delete static_cast<NiPick*>(m_pSunGlarePick);
    m_pSunShaderAccumulator = 0;
}

// Sun update: with a world and enabled, point the glare at the new target and run its update at a scaled time step.

extern const double g_dA6A0TimeScale;


class A6A0World
{
  public:
    float GetTimeStep();
    void SetTimeStep(float fTimeStep);
};

class A6A0Target
{
  public:
    void Update(A6A0World* pkWorld, void* pvArg0, void* pvArg1);
};

// Additional entry points absent from Sun.h; no duplicate object layout.
class SunAccumulatorUpdate : public Sun
{
  public:
    A6A0World* GetWorld();
    void UpdateAccumulator(void* pvArg0, A6A0Target* pkTarget, void* pvArg1);
};

// @fnv 0x006426a0
void SunAccumulatorUpdate::UpdateAccumulator(void* pvArg0, A6A0Target* pkTarget, void* pvArg1)
{
    AutoMemHelper kMem(0x21, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Sky\\Sun.cpp", 0x222);
    if (GetWorld() && bDoOcclusionTests)
    {
        A6A0Target* pkCurrent = pkTarget;
        if (pkCurrent)
        {
            ((NP*)&m_pSunShaderAccumulator)->Reset(pkTarget);
            A6A0World* pkWorld = GetWorld();
            pkWorld->SetTimeStep((float)(pkWorld->GetTimeStep() / g_dA6A0TimeScale));
            pkCurrent->Update(pkWorld, pvArg0, pvArg1);
            pkWorld->SetTimeStep((float)(pkWorld->GetTimeStep() * g_dA6A0TimeScale));
        }
    }
}
