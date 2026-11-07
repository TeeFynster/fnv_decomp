#include "../../../../include/ContinuousBeamProjectile.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/NiGeometry.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiNode.h"
// fallout/ai/combat/continuousbeamprojectile.cpp: ContinuousBeamProjectile (7 functions)

// @fnv 0x009da760
int ContinuousBeamProjectile::Initialize()
{
    return 5;
}

bool __cdecl CanProjectileHit(void*, void*, void*, void*);

// @fnv 0x009ab9c0
// src: XBOX_PDB 0x009ab9c0
bool ContinuousBeamProjectile::AddImpact_009ab9c0(void* arg1, NiPoint3* arg2, void* arg3, void* arg4, void* arg5, void* arg6)
{
    if (CanProjectileHit(arg1, arg4, this, GetActorBase()) && !Projectile_IsFlagSet(0x20) &&
        ProcessHit(arg1, arg2, arg3, arg4, arg5, arg6))
    {
        if (m_bHasImpactData)
        {
            kImpacts.RemoveAll();
        }
        m_bHasImpactData = 0;
        Projectile_SetRange((*arg2 - *static_cast<const ContinuousBeamProjectile*>(this)->GetPos()).Length());
        return true;
    }
    return false;
}

bool __cdecl NiObject_IsKindOf(NiRTTI const*, NiAVObject*);
extern char const* const g_011f4a48_arg1;

// Recursively walks a NiAVObject tree; for NiGeometry objects it marks their geometry data mutable, otherwise recurses into child nodes.
// @fnv 0x009abe40
void ContinuousBeamProjectile::MarkGeometryDataMutable(NiAVObject* ap3D)
{
    if (ap3D)
    {
        if (NiObject_IsKindOf((const NiRTTI*)&g_011f4a48_arg1, ap3D))
        {
            NiGeometry* pgeom = (NiGeometry*)ap3D;
            NiGeometryData* pdata = pgeom->GetModelData();
            if (pdata)
            {
                pdata->SetDataConsistency((NiGeometryData::Consistency)0);
            }
        }
        else
        {
            NiNode* pnode = ap3D->IsSceneNode();
            if (pnode)
            {
                for (unsigned int uiIndex = 0; uiIndex < pnode->GetNumChildren(); ++uiIndex)
                {
                    NiAVObject* pChild = pnode->GetAt(uiIndex);
                    MarkGeometryDataMutable(pChild);
                }
            }
        }
    }
}

struct S_009ab280_Target
{
    void FOHUDEffectManager_SetBlurIntensityHUD(float f);
};
struct S_009ab280_Sub
{
    int unk00;
    S_009ab280_Target* Modelloader_GetReferencedThis();
};
struct S_009ab280_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    S_009ab280_Sub m150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    ContinuousBeamProjectile* unk1a0;
};
void __cdecl Warning_005b5e40(const char* msg);

// Sets several flags via FUN_005de0a0, clears unk154, updates m150, and registers this as the owner's unk1a0 or logs an error and calls FUN_009bc8f0.
// @fnv 0x009ab280
void ContinuousBeamProjectile::InitContinuousBeam()
{
    Projectile_SetFlag(0x10, 0);
    Projectile_SetFlag(1, 1);
    Projectile_SetFlag(2, 0);
    Projectile_SetFlag(8, 1);
    Projectile_SetFlag(0x20, 0);
    Projectile_SetFlag(0x100, 1);
    Projectile_SetFlag(0x80, 1);
    Projectile_SetFlag(0x2000, 1);
    // The shared class does not yet name the trailing state at +0x154.
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x154) = 0;
    Projectile_Initialize();
    if (reinterpret_cast<S_009ab280_Sub*>(&m_spUnk150)->Modelloader_GetReferencedThis())
    {
        reinterpret_cast<S_009ab280_Sub*>(&m_spUnk150)->Modelloader_GetReferencedThis()->FOHUDEffectManager_SetBlurIntensityHUD(GetFirstLightParameter());
    }
    S_009ab280_Owner* owner = reinterpret_cast<S_009ab280_Owner*>(Projectile_GetShooter());
    if (owner)
    {
        if (owner->unk1a0)
        {
            owner->unk1a0->Projectile_Kill();
        }
        owner->unk1a0 = this;
    }
    else
    {
        Warning_005b5e40("Continuous Beam created without Shooter!");
        Projectile_Kill();
    }
}

struct ScPoint3
{
    float x, y, z;
};
struct ScPoint2
{
    float x, y;
};
extern ScPoint3 g_kZero_011f426c;
struct ScRTTI
{
    int unk;
};
extern ScRTTI g_kRTTI_01202558;
extern ScRTTI g_kRTTI_012024e0;
extern ScRTTI g_kRTTI_01202508;

struct ScTransform
{
    char pad00[0xc];
    float m_fScale;
    void ScaleComponents(float fScale);
};
struct ScData
{
    virtual void v00();
    unsigned short FUN_0047d370();
};
struct ScGeomData
{
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
    virtual bool FUN_v8c();
};
struct ScAccess
{
    ScAccess();
    void NiGeometryDataIteratorNiPoint3_Get(int iIndex, ScPoint3* pkPt);
    void FUN_0065b390(int iIndex, ScPoint3* pkPt);
    int pad[3];
};
struct ScGeom
{
    ScGeomData* NiTimeController_GetNext();
    bool FUN_00a67360(int i);
    void NiGeometryData_GetVerticesIterator(ScAccess* pkAccess);
    void NiGeometryData_UnlockPackedVertexData();
    ScPoint3* BGSSaveFormBuffer_GetForm();
    unsigned short FUN_004a8ae0();
    ScPoint2* FUN_0055b980();
};
struct ScChild
{
    float FUN_00639b20();
    void BSShaderProperty_SetDepthBias(float fValue);
};
struct ScAVObject
{
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
    virtual void FUN_vd8(void* pkArg);
    ScTransform* GetSourceFilesFromForm();
    ScGeom* NiGeometry_GetModelData();
    unsigned int NiParticleSystem_GetModifierCount();
    ScAVObject* GetByIndex(unsigned int uiIndex);
};
bool __cdecl NiObject_IsKindOf(ScRTTI* pkRTTI, void* pkObject);
void* __cdecl NiXenonRenderer_GetRenderer();

// Scales pkObject's transform by fScale and scales its geometry vertices or child objects depending on the geometry type.
// @fnv 0x009aba90
void ContinuousBeamProjectile::ScaleObject(NiAVObject* pkObject, float fScale)
{
    if (pkObject)
    {
        reinterpret_cast<ScAVObject*>(pkObject)->GetSourceFilesFromForm()->m_fScale *= fScale;
        reinterpret_cast<ScAVObject*>(pkObject)->GetSourceFilesFromForm()->ScaleComponents(fScale);
        ScGeom* pkGeom = reinterpret_cast<ScAVObject*>(pkObject)->NiGeometry_GetModelData();
        if (pkGeom)
        {
            if (NiObject_IsKindOf(&g_kRTTI_01202558, pkGeom))
            {
                if (NiObject_IsKindOf(&g_kRTTI_012024e0, pkObject))
                {
                    ScAVObject* pkNode = reinterpret_cast<ScAVObject*>(pkObject);
                    for (unsigned int i = 0; i < pkNode->NiParticleSystem_GetModifierCount(); i++)
                    {
                        ScAVObject* pkChild = pkNode->GetByIndex(i);
                        if (NiObject_IsKindOf(&g_kRTTI_01202508, pkChild))
                        {
                            ScChild* pkTarget = (ScChild*)pkChild;
                            pkTarget->BSShaderProperty_SetDepthBias(pkTarget->FUN_00639b20() * fScale);
                        }
                    }
                }
            }
            else if (pkGeom->NiTimeController_GetNext() && pkGeom->NiTimeController_GetNext()->FUN_v8c())
            {
                ScAccess kAccess;
                ScGeomData* pkData = pkGeom->NiTimeController_GetNext();
                if (pkGeom->FUN_00a67360(1))
                {
                    pkGeom->NiGeometryData_GetVerticesIterator(&kAccess);
                    for (int j = 0; j < ((ScData*)pkData)->FUN_0047d370(); j++)
                    {
                        ScPoint3 kPt = g_kZero_011f426c;
                        kAccess.NiGeometryDataIteratorNiPoint3_Get(j, &kPt);
                        kPt.y *= fScale;
                        kAccess.FUN_0065b390(j, &kPt);
                    }
                    pkGeom->NiGeometryData_UnlockPackedVertexData();
                }
            }
            else if (pkGeom->BGSSaveFormBuffer_GetForm())
            {
                for (int k = 0; k < pkGeom->FUN_004a8ae0(); k++)
                {
                    pkGeom->BGSSaveFormBuffer_GetForm()[k].y *= fScale;
                    pkGeom->FUN_0055b980()[k].y *= fScale;
                }
                reinterpret_cast<ScAVObject*>(pkObject)->FUN_vd8(NiXenonRenderer_GetRenderer());
            }
        }
    }
}

class AlignMatrix
{
  public:
    float m_afEntry[9];
    AlignMatrix FUN_004b45b0() const;                           // Transpose
    AlignMatrix FUN_0043f8d0(const AlignMatrix& kOther) const;  // operator*
};

class AlignSceneObject
{
  public:
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_00A();
    virtual void Unk_00B();
    virtual void Unk_00C();
    virtual void Unk_00D();
    virtual void Unk_00E();
    virtual void Unk_00F();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_01A();
    virtual void Unk_01B();
    virtual void Unk_01C();
    virtual void Unk_01D();
    virtual void Unk_01E();
    virtual void Unk_01F();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_02A();
    virtual void Unk_02B();
    virtual void Unk_02C();
    virtual void Unk_02D();
    virtual void UpdateWorldData(NiUpdateData& kData);  // +0xb8
    AlignMatrix& NiAVObject_GetWorldRotate();                        // rotation
};

class AlignTargetSource
{
  public:
    virtual void Unk_000();
    virtual void Unk_001();
    virtual void Unk_002();
    virtual void Unk_003();
    virtual void Unk_004();
    virtual void Unk_005();
    virtual void Unk_006();
    virtual void Unk_007();
    virtual void Unk_008();
    virtual void Unk_009();
    virtual void Unk_00A();
    virtual void Unk_00B();
    virtual void Unk_00C();
    virtual void Unk_00D();
    virtual void Unk_00E();
    virtual void Unk_00F();
    virtual void Unk_010();
    virtual void Unk_011();
    virtual void Unk_012();
    virtual void Unk_013();
    virtual void Unk_014();
    virtual void Unk_015();
    virtual void Unk_016();
    virtual void Unk_017();
    virtual void Unk_018();
    virtual void Unk_019();
    virtual void Unk_01A();
    virtual void Unk_01B();
    virtual void Unk_01C();
    virtual void Unk_01D();
    virtual void Unk_01E();
    virtual void Unk_01F();
    virtual void Unk_020();
    virtual void Unk_021();
    virtual void Unk_022();
    virtual void Unk_023();
    virtual void Unk_024();
    virtual void Unk_025();
    virtual void Unk_026();
    virtual void Unk_027();
    virtual void Unk_028();
    virtual void Unk_029();
    virtual void Unk_02A();
    virtual void Unk_02B();
    virtual void Unk_02C();
    virtual void Unk_02D();
    virtual void Unk_02E();
    virtual void Unk_02F();
    virtual void Unk_030();
    virtual void Unk_031();
    virtual void Unk_032();
    virtual void Unk_033();
    virtual void Unk_034();
    virtual void Unk_035();
    virtual void Unk_036();
    virtual void Unk_037();
    virtual void Unk_038();
    virtual void Unk_039();
    virtual void Unk_03A();
    virtual void Unk_03B();
    virtual void Unk_03C();
    virtual void Unk_03D();
    virtual void Unk_03E();
    virtual void Unk_03F();
    virtual void Unk_040();
    virtual void Unk_041();
    virtual void Unk_042();
    virtual void Unk_043();
    virtual void Unk_044();
    virtual void Unk_045();
    virtual void Unk_046();
    virtual void Unk_047();
    virtual void Unk_048();
    virtual void Unk_049();
    virtual void Unk_04A();
    virtual void Unk_04B();
    virtual void Unk_04C();
    virtual void Unk_04D();
    virtual void Unk_04E();
    virtual void Unk_04F();
    virtual void Unk_050();
    virtual void Unk_051();
    virtual void Unk_052();
    virtual void Unk_053();
    virtual void Unk_054();
    virtual void Unk_055();
    virtual void Unk_056();
    virtual void Unk_057();
    virtual void Unk_058();
    virtual void Unk_059();
    virtual void Unk_05A();
    virtual void Unk_05B();
    virtual void Unk_05C();
    virtual void Unk_05D();
    virtual void Unk_05E();
    virtual void Unk_05F();
    virtual void Unk_060();
    virtual void Unk_061();
    virtual void Unk_062();
    virtual void Unk_063();
    virtual void Unk_064();
    virtual void Unk_065();
    virtual void Unk_066();
    virtual void Unk_067();
    virtual void Unk_068();
    virtual void Unk_069();
    virtual void Unk_06A();
    virtual void Unk_06B();
    virtual void Unk_06C();
    virtual void Unk_06D();
    virtual void Unk_06E();
    virtual void Unk_06F();
    virtual void Unk_070();
    virtual void Unk_071();
    virtual void Unk_072();
    virtual void Unk_073();
    virtual void Unk_074();
    virtual void Unk_075();
    virtual void Unk_076();
    virtual void Unk_077();
    virtual void Unk_078();
    virtual void Unk_079();
    virtual void Unk_07A();
    virtual void Unk_07B();
    virtual void Unk_07C();
    virtual void Unk_07D();
    virtual void Unk_07E();
    virtual void Unk_07F();
    virtual void Unk_080();
    virtual void Unk_081();
    virtual void Unk_082();
    virtual AlignSceneObject* GetTargetNode();  // +0x20c
};

// Updates the 3D object's world data and recomputes m_kRotate from the target node's transform when a target node exists.
// @fnv 0x009ab160
void ContinuousBeamProjectile::UpdateAlignment()
{
    AlignSceneObject* pkObject2 = reinterpret_cast<AlignSceneObject*>(GetNiNode());
    if (pkObject2)
    {
        float fScale = GetFirstLightParameter();
        if (fScale < 1.0)
            fScale = 1.0f;
        fn_9ABD00_Recurse(reinterpret_cast<NiAVObject*>(pkObject2), fScale, 0.0f);
        AlignSceneObject* pkTarget2 = Projectile_GetShooter() ? reinterpret_cast<AlignTargetSource*>(Projectile_GetShooter())->GetTargetNode() : 0;
        if (pkTarget2)
        {
            NiUpdateData kData2(0.0f, false, false);
            pkObject2->UpdateWorldData(kData2);
            reinterpret_cast<AlignMatrix&>(m_kImpactTransform.m_Rotate) = reinterpret_cast<AlignSceneObject*>(GetNiNode())->NiAVObject_GetWorldRotate().FUN_0043f8d0(pkTarget2->NiAVObject_GetWorldRotate().FUN_004b45b0());
        }
    }
}

extern NiRTTI DAT_011f4acc;

// If obj is non-null, scales its point when f2 > 0, then scales it or recursively processes its child nodes.
// @fnv 0x009abd00
// src: COMMUNITY 0x009abd00
void ContinuousBeamProjectile::fn_9ABD00_Recurse(NiAVObject* apObject, float f1, float f2)
{
    if (apObject)
    {
        if (f2 > 0.0f)
        {
            float scale = f1 / f2;
            NiPoint3 translate8 = apObject->GetTranslate_0043c490();
            translate8 *= scale;
            apObject->NiAVObject_SetTranslate(translate8);
        }

        if (NiObject_IsKindOf(&DAT_011f4acc, apObject))
        {
            NiAVObject* target2 = apObject;
            float val3 = (f2 > 0.0f) ? f2 : this->FindBeamGeometryLength(target2);
            if (val3 != 0.0f)
            {
                float fRatio = f1 / val3;
                this->ScaleObject(target2, fRatio);
            }
        }
        else
        {
            NiNode* pNode = apObject->IsSceneNode();
            if (pNode)
            {
                for (unsigned int iIndex = 0; iIndex < pNode->FUN_0043b480(); ++iIndex)
                {
                    NiAVObject* pChild = pNode->FUN_0043b4a0(iIndex);
                    this->fn_9ABD00_Recurse(pChild, f1, f2);
                }
            }
        }
    }
}
