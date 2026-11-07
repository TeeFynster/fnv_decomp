#include "../../../include/Atmosphere.h"
#include "../../../include/BSFaceGenAnimationData.h"
#include "../../../include/BSFaceGenNiNode.h"
#include "../../../include/BSMultiBoundRoom.h"
#include "../../../include/NiCamera.h"
#include "../../../include/NiPoint3.h"


// src/fallout_shared/sky/atmosphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/sky/atmosphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl _Deallocate(void* p);

// @fnv 0x00633160
void* __fastcall FUN_00633160(Atmosphere* pAtmosphere, void*, unsigned int flags)
{
    pAtmosphere->FUN_00633190();
    if (flags & 1)
        _Deallocate(pAtmosphere);
    return pAtmosphere;
}

// @fnv 0x00633190
Atmosphere::~Atmosphere()
{
    m_spFog = (NiFogProperty*)0;
    m_spAtmosphere = (NiNode*)0;
    m_spSkyShape = (NiNode*)0;
    m_spSkyNode = (NiNode*)0;
}

void __cdecl AtmoFree(void* pvMem);

// Hide the inherited unsized delete so constructor unwinding uses the game's
// sized node deallocation call. The shared NiNode supplies the complete layout.
struct AtmosphereModelNode : NiNode
{
    AtmosphereModelNode(unsigned short iChildren);
    static void operator delete(void* pvMem, unsigned int)
    {
        AtmoFree(pvMem);
    }
};

struct AtmoObject;

struct AtmoPropertyList
{
    void* GetTranslate_0043c490();
};
struct AtmoShaderMgr
{
    AtmoPropertyList* BSSceneGraph_GetCameraRoot();
};
AtmoShaderMgr* __cdecl Main_GetWorldSceneGraph();
void __cdecl SkyShader_CreateSkyQuad(NiPointer<NiNode>* pspNode);
void __cdecl FUN_00b55540(int iUnk, NiFogProperty* pkFog);
void __cdecl Warning_005b5e40(const char* pFormat, ...);
extern unsigned char g_bNoSky_011f941e;
extern char g_kNiNodeRTTI_011f4a40[];
bool __cdecl NiObject_IsKindOf(void* pkRTTI, AtmoObject* pkObject);

struct AtmoObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int IsGeometry();
    NiNode* NiNode_GetAtChecked(int iIndex);
};

struct AtmoStream
{
    char unk000[0x5cc];
    AtmoStream();
    ~AtmoStream();
    bool BSStream_Load(const char* pPath, int iFlags);
};

struct AtmoLoadedModel
{
    int unk00[4];
    AtmoLoadedModel(const char* pPath, AtmoStream* pkStream, int a3, int a4);
    ~AtmoLoadedModel();
    AtmoObject* NiObjectNET_GetControllers();
};

// @fnv 0x00633260
void Atmosphere::SetAtmosphere(NiNode* pkRoot, NiFogProperty* pkFog)
{
    CreateSortAdjustNode(pkRoot);
    if (!g_bNoSky_011f941e)
    {
        SkyShader_CreateSkyQuad(&m_spSkyShape);
        m_spSkyShape->NiAVObject_SetSelectiveUpdate(true);
        m_spSkyShape->NiAVObject_SetTranslate((const NiPoint3*)Main_GetWorldSceneGraph()->BSSceneGraph_GetCameraRoot()->GetTranslate_0043c490());
        m_spSkyNode = new AtmosphereModelNode(0);
        m_spSkyNode->NiAVObject_SetSelectiveUpdate(true);
        m_spSkyNode->AttachChildInAvailableSlot((NiAVObject*)m_spSkyShape.operator->(), true);
        m_pRootNode->AttachChildInAvailableSlot((NiAVObject*)m_spSkyNode.operator->(), true);
    }

    AtmoStream kStream;
    if (kStream.BSStream_Load("Meshes\\Sky\\Atmosphere.nif", 0))
    {
        AtmoLoadedModel kModel_("Meshes\\Sky\\Atmosphere.nif", &kStream, 0, 0);
        AtmoObject* pkFirstVal2 = kModel_.NiObjectNET_GetControllers();
        NiNode* pkMeshRes = 0;
        AtmoObject* pkObjectOut = kModel_.NiObjectNET_GetControllers();
        if (pkObjectOut)
        {
            if (pkObjectOut->IsGeometry())
                pkMeshRes = pkObjectOut->NiNode_GetAtChecked(0);
            else if (NiObject_IsKindOf(g_kNiNodeRTTI_011f4a40, pkObjectOut))
                pkMeshRes = (NiNode*)pkObjectOut;
        }
        if (!pkMeshRes)
        {
            Warning_005b5e40("Cannot load the atmosphere model.");
            return;
        }
        m_spAtmosphere = pkMeshRes;
        m_spAtmosphere->NiAVObject_SetSelectiveUpdate(true);
        m_pRootNode->AttachChildInAvailableSlot((NiAVObject*)m_spAtmosphere.operator->(), true);
    }
    m_spFog = pkFog;
    FUN_00b55540(0, pkFog);
}

namespace fnv_006335d0 {
struct Param
{
    float a;
    float b;
    float c;
    float d;
    Param* FUN_00414430(float a0, float a1, float a2, float a3);
};
struct Light
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
};
struct FUN_00633bf0_Class
{
    void NiFogProperty_SetFogColor(const NiPoint3* v);
};
struct FUN_00633c20_Class : FUN_00633bf0_Class
{
    void BSFogProperty_SetWaterDistance(float a, float b);
};
struct FUN_00633c40_Class : FUN_00633c20_Class
{
    void BSFogProperty_SetFogHeight(float a);
};
struct FUN_00633c60_Class : FUN_00633c40_Class
{
    void BSFogProperty_SetWaterColor(const NiPoint3& v);
};
struct Fog : FUN_00633c60_Class
{
    void NiAlphaProperty_SetAlphaBlending(bool b);
    void BSFogProperty_SetDistance(float a, float b);
    void FOHUDEffectManager_SetBlurIntensityHUD(float a);
};
struct Node : BSMultiBoundRoom
{
    float GetFieldE4Float();
    int Sky_GetMode();
    NiPoint3* GetExtraPartList();
    NiPoint3* FUN_0050d100();
    NiPoint3* FUN_009c1a50();
    NiPoint3* ComputeValue_005a8080();
    Light* TESAmmo_GetAmmoEffectList();
    float GetFieldE8Float();
};
struct Probe
{
    int FUN_008d6f30();
    float TESObjectREFR_GetRelevantWaterHeight();
};
struct Info
{
    float unk00;
    float unk04;
    float unk08;
};
// This object supplies a camera, not face-generation animation data.
struct AtmosphereSceneGraph
{
    NiCamera* GetCamera();
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual float v40();
};
extern Probe* DAT_011dea3c;
extern Param DAT_011ff8e0;
extern Param DAT_011ff8f0;
extern Param DAT_011ff900;
extern unsigned char DAT_011f941e;
extern float DAT_011f9190;
Fog* __cdecl BSShaderManager_GetFogProperty(int a0);
void __cdecl FUN_00b55540(int a0, Fog* a1);
AtmosphereSceneGraph* __cdecl Main_GetWorldSceneGraph();
void* __fastcall BSSceneGraph_GetCameraRoot(AtmosphereSceneGraph* w);
Info* __fastcall NiAVObject_GetWorldTranslate(void* p);
}  // namespace fnv_006335d0

// Refreshes the fog reference and positions, and syncs the camera frustum far plane.
// @fnv 0x006335d0
void Atmosphere::UpdateAtmosphere(Sky* node, float f)
{
    using namespace fnv_006335d0;
    float len;
    {
        float p3;
        Light* p1;
        {
            NiCamera* u;
            {
                float farv;
                {
                    NiFrustum tmp;
                    {
                        Param pData;
                        {
                            Param light;
                            Param p0;
                            {
                                Param k;
                                {
                                    Param p4;
                                    Param t;
                                    {
                                        // ScaleTo writes all components; avoid a default-constructor call.
                                        float pNode[3];

                                        if (!node)
                                            return;
                                        if (BSShaderManager_GetFogProperty(0) != reinterpret_cast<Fog*>(m_spFog.operator->()))
                                            FUN_00b55540(0, reinterpret_cast<Fog*>(m_spFog.operator->()));
                                        FUN_008d0600(node, f);
                                        if (reinterpret_cast<Node*>(node)->Sky_GetMode() == 3 || 2 == reinterpret_cast<Node*>(node)->Sky_GetMode())
                                        {
                                            if (!(m_spAtmosphere.operator->()))
                                                return;
                                            if (DAT_011dea3c != 0 && DAT_011dea3c->FUN_008d6f30() &&
                                                NiAVObject_GetWorldTranslate(BSSceneGraph_GetCameraRoot(fnv_006335d0::Main_GetWorldSceneGraph()))->unk08 <
                                                    DAT_011dea3c->TESObjectREFR_GetRelevantWaterHeight())
                                            {
                                                DAT_011ff8e0 = *pData.FUN_00414430(reinterpret_cast<Node*>(node)->GetExtraPartList()->x,
                                                                                   reinterpret_cast<Node*>(node)->GetExtraPartList()->y,
                                                                                   reinterpret_cast<Node*>(node)->GetExtraPartList()->z, 1.0f);
                                                DAT_011ff8f0 =
                                                    *p0.FUN_00414430(reinterpret_cast<Node*>(node)->GetExtraPartList()->x, reinterpret_cast<Node*>(node)->GetExtraPartList()->y,
                                                                     reinterpret_cast<Node*>(node)->GetExtraPartList()->z, 1.0f);
                                                DAT_011ff900 = *light.FUN_00414430(reinterpret_cast<Node*>(node)->GetExtraPartList()->x,
                                                                                   reinterpret_cast<Node*>(node)->GetExtraPartList()->y,
                                                                                   reinterpret_cast<Node*>(node)->GetExtraPartList()->z, 1.0);
                                            }
                                            else
                                            {
                                                DAT_011ff8e0 =
                                                    *k.FUN_00414430(reinterpret_cast<Node*>(node)->FUN_0050d100()->x, reinterpret_cast<Node*>(node)->FUN_0050d100()->y,
                                                                    reinterpret_cast<Node*>(node)->FUN_0050d100()->z, 1.0);
                                                DAT_011ff8f0 =
                                                    *p4.FUN_00414430(reinterpret_cast<Node*>(node)->FUN_009c1a50()->x, reinterpret_cast<Node*>(node)->FUN_009c1a50()->y,
                                                                     reinterpret_cast<Node*>(node)->FUN_009c1a50()->z, 1.0);
                                                DAT_011ff900 =
                                                    *t.FUN_00414430(reinterpret_cast<Node*>(node)->ComputeValue_005a8080()->x, reinterpret_cast<Node*>(node)->ComputeValue_005a8080()->y,
                                                                    reinterpret_cast<Node*>(node)->ComputeValue_005a8080()->z, 1.0f);
                                            }
                                        }
                                        if (0 != reinterpret_cast<Fog*>(m_spFog.operator->()))
                                        {
                                            p1 = reinterpret_cast<Node*>(node)->TESAmmo_GetAmmoEffectList();
                                            reinterpret_cast<Fog*>(m_spFog.operator->())->NiAlphaProperty_SetAlphaBlending(p1->unk04 > p1->unk00);
                                            if (unk18)
                                            {
                                                reinterpret_cast<Fog*>(m_spFog.operator->())->BSFogProperty_SetDistance(p1->unk00, p1->unk04);
                                                reinterpret_cast<Fog*>(m_spFog.operator->())->FOHUDEffectManager_SetBlurIntensityHUD(reinterpret_cast<Node*>(node)->GetFieldE8Float());
                                            }
                                            if (!(DAT_011f941e))
                                            {
                                                p3 = DAT_011f9190 / 3.75f;
                                                reinterpret_cast<Fog*>(m_spFog.operator->())->NiFogProperty_SetFogColor(
                                                    reinterpret_cast<Node*>(node)->GetExtraPartList()->ScaleTo(reinterpret_cast<NiPoint3*>(pNode), p3));
                                            }
                                            else
                                            {
                                                reinterpret_cast<Fog*>(m_spFog.operator->())->NiFogProperty_SetFogColor(reinterpret_cast<Node*>(node)->GetExtraPartList());
                                            }
                                            len = reinterpret_cast<Node*>(node)->GetFieldE4Float();
                                            reinterpret_cast<Fog*>(m_spFog.operator->())->BSFogProperty_SetFogHeight(reinterpret_cast<Node*>(node)->GetFieldE4Float());
                                            reinterpret_cast<Fog*>(m_spFog.operator->())->BSFogProperty_SetWaterDistance(p1->unk08, p1->unk0c);
                                            reinterpret_cast<Fog*>(m_spFog.operator->())->BSFogProperty_SetWaterColor(*(NiPoint3*)reinterpret_cast<Node*>(node)->TESCombatStyle_GetAdvancedData());
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (unk18)
                    {
                        u = 0;
                        farv = fnv_006335d0::Main_GetWorldSceneGraph()->v40();
                        u = fnv_006335d0::Main_GetWorldSceneGraph()->GetCamera();
                        if (0 != u)
                        {
                            tmp = u->GetViewFrustum();
                            if (farv != tmp.m_fFarPlane)
                            {
                                tmp.m_fFarPlane = farv;
                                u->NiCamera_SetMaxFarNearRatio(farv / tmp.m_fNearPlane);
                                u->FUN_00a6faf0(tmp);
                            }
                        }
                    }
                }
            }
        }
    }
}

struct FUN_00633cc0_SkyObject
{
    FUN_00633cc0_SkyObject();
    ~FUN_00633cc0_SkyObject();
    virtual void vf();
};

struct FUN_00633cc0_ElemA
{
    void* m_pObject;
    FUN_00633cc0_ElemA();
    ~FUN_00633cc0_ElemA();
};

struct FUN_00633cc0_ElemB
{
    int unk0;
    int unk4;
    int unk8;
    FUN_00633cc0_ElemB();
};

struct FUN_00633cc0 : FUN_00633cc0_SkyObject
{
    int unk04;
    FUN_00633cc0_ElemA m_kPointA[4];
    FUN_00633cc0_ElemA m_kPointB[4];
    FUN_00633cc0_ElemB m_iThirdValue[4];
    unsigned short m_58;
    unsigned char m_5a;

    void Clouds_ZeroGeo();
    void Clouds_ClearTransTextures();
    FUN_00633cc0();
    virtual void vf();
};

// Initializes the object: clears m_58, calls FUN_00633d90 and FUN_00634930, then sets m_5a to 0.
// @fnv 0x00633cc0
FUN_00633cc0::FUN_00633cc0() : m_58(0)
{
    Clouds_ZeroGeo();
    Clouds_ClearTransTextures();
    m_5a = 0;
}
