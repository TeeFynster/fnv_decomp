// src/fallout/ai/actor_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/actor.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// BaseForm_actor: local type (was include/BaseForm.h, which had no evidence of one real class); its methods are 0x00401170 TESForm::GetFormType
class BaseForm_actor
{
public:
    int FUN_00401170();
    unsigned int FormType();
    unsigned int GetFormType();
};
#include "../../../include/Actor.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/CombatController.h"
#include "../../../include/NiBound.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiMatrix3.h"
#include "../../../include/TESActorBase.h"

#include <xmmintrin.h>
#include <string.h>
#pragma intrinsic(memcpy)
#include "../../../include/NiObject.h"
struct HandleRef
{
    int iData;
    HandleRef();
    int CFilter_GetGroup();
};

struct Process
{
    virtual void vp000();
    virtual void vp001();
    virtual void vp002();
    virtual void vp003();
    virtual void vp004();
    virtual void vp005();
    virtual void vp006();
    virtual void vp007();
    virtual void vp008();
    virtual void vp009();
    virtual void FUN_vt28();
    virtual void vp00b();
    virtual void vp00c();
    virtual void vp00d();
    virtual void vp00e();
    virtual void vp00f();
    virtual void vp010();
    virtual void vp011();
    virtual void vp012();
    virtual void vp013();
    virtual void vp014();
    virtual void vp015();
    virtual void vp016();
    virtual void vp017();
    virtual void vp018();
    virtual void vp019();
    virtual void vp01a();
    virtual void vp01b();
    virtual void vp01c();
    virtual void vp01d();
    virtual void vp01e();
    virtual void vp01f();
    virtual void vp020();
    virtual void vp021();
    virtual void vp022();
    virtual void vp023();
    virtual void vp024();
    virtual void vp025();
    virtual void vp026();
    virtual void vp027();
    virtual void vp028();
    virtual void vp029();
    virtual void vp02a();
    virtual void vp02b();
    virtual void vp02c();
    virtual void vp02d();
    virtual void vp02e();
    virtual void vp02f();
    virtual void vp030();
    virtual void vp031();
    virtual void vp032();
    virtual void vp033();
    virtual void vp034();
    virtual void vp035();
    virtual void vp036();
    virtual void vp037();
    virtual void vp038();
    virtual void vp039();
    virtual void vp03a();
    virtual void vp03b();
    virtual void vp03c();
    virtual void vp03d();
    virtual void vp03e();
    virtual void vp03f();
    virtual void vp040();
    virtual void vp041();
    virtual void vp042();
    virtual void vp043();
    virtual void vp044();
    virtual void vp045();
    virtual void vp046();
    virtual void vp047();
    virtual void vp048();
    virtual void vp049();
    virtual void vp04a();
    virtual void vp04b();
    virtual void vp04c();
    virtual void vp04d();
    virtual void vp04e();
    virtual void vp04f();
    virtual void vp050();
    virtual void vp051();
    virtual void vp052();
    virtual void vp053();
    virtual void vp054();
    virtual void vp055();
    virtual void vp056();
    virtual void vp057();
    virtual void vp058();
    virtual void vp059();
    virtual void vp05a();
    virtual void vp05b();
    virtual void vp05c();
    virtual void vp05d();
    virtual void vp05e();
    virtual void vp05f();
    virtual void vp060();
    virtual void vp061();
    virtual void vp062();
    virtual void vp063();
    virtual void vp064();
    virtual void vp065();
    virtual void vp066();
    virtual void vp067();
    virtual void vp068();
    virtual void vp069();
    virtual void vp06a();
    virtual void vp06b();
    virtual void vp06c();
    virtual void vp06d();
    virtual void vp06e();
    virtual void vp06f();
    virtual void vp070();
    virtual void vp071();
    virtual void vp072();
    virtual void vp073();
    virtual void vp074();
    virtual void vp075();
    virtual void vp076();
    virtual void vp077();
    virtual void vp078();
    virtual void vp079();
    virtual void vp07a();
    virtual void vp07b();
    virtual void vp07c();
    virtual void vp07d();
    virtual void vp07e();
    virtual void vp07f();
    virtual void vp080();
    virtual void vp081();
    virtual void vp082();
    virtual void vp083();
    virtual void vp084();
    virtual void vp085();
    virtual void vp086();
    virtual void vp087();
    virtual void vp088();
    virtual void vp089();
    virtual void vp08a();
    virtual void vp08b();
    virtual void vp08c();
    virtual void vp08d();
    virtual void vp08e();
    virtual void vp08f();
    virtual void vp090();
    virtual void vp091();
    virtual void vp092();
    virtual void vp093();
    virtual void vp094();
    virtual void vp095();
    virtual void vp096();
    virtual void vp097();
    virtual void vp098();
    virtual void vp099();
    virtual void vp09a();
    virtual void vp09b();
    virtual void vp09c();
    virtual void vp09d();
    virtual void vp09e();
    virtual void vp09f();
    virtual void vp0a0();
    virtual void vp0a1();
    virtual void vp0a2();
    virtual CombatController* FUN_vt28c();
};

struct PathMover
{
    void GetMovement(NiPoint3* apPos, void* apActor, int aiA, int aiB);
};

struct LookTarget
{
    bool TESObjectCELL_GetAttached();
};

namespace ActorUpdate3D {


struct AlignedRotation
{
    __m128 vec;
    AlignedRotation(float afA, float afB, float afC, float afD);
};

struct FormType
{
    int iData;
    FormType();
    int CFilter_GetLayer();
};


struct ProfileMarker
{
    void FUN_00483710();
};

struct Clock
{
    float FUN_0084d030();
};

struct ActorList
{
    unsigned int FUN_0044ddc0();
    float GetTargetUpdateMult();
};


struct Holder
{
    virtual void vh000();
    virtual void vh001();
    virtual void vh002();
    virtual void vh003();
    virtual void vh004();
    virtual void vh005();
    virtual void vh006();
    virtual void vh007();
    virtual int FUN_vt20();
    virtual bool FUN_vt24(NiPoint3* apPos);
};


struct CameraNode
{
    NiPoint3* NiAVObject_GetWorldTranslate();
};

struct LodManager
{
    int GetStringAtOffset13C();
    void UpdateOrAddItem(int aiRefID, NiBound* apBound, bool abVisible);
};


struct Havok
{
    bool bhkRagdollController_QRagdollAnimEnable();
    void bhkRagdollController_DisableRagdollAnim(int aiValue);
};

struct Ragdoll
{
    void bhkRagdollPenetrationUtil_Initialize(NiNode* apRoot, int aiValue);
};

struct AnimSequence
{
    float GetEndKeyTime_00508100();
    void PathingLOSGridMap_SetSightRadius(float afTime);
};

struct AnimController
{
    bool Animation_GroupLoaded(int aiGroup);
    void Animation_ForceSection(int aiA, int aiGroup, int aiB, float afC, int aiD);
    AnimSequence* Animation_GetCurrentSequence(int aiValue);
    void Animation_Update(void* apActor, float afA, float afB);
    void Animation_UpdateMovement(void* apActor);
};

struct ActorListNodeView;

struct ChildPtr
{
    NiAVObject* Modelloader_GetReferencedThis();
};

// Exe 0x00886cb0: unit-local ListNode view; declarations and layout are preserved.
struct ActorListNodeView
{
    ChildPtr* FUN_006815c0();
    ActorListNodeView* FUN_00726070();
};

struct ShaderProp
{
    struct ShaderData* bhkLimitedHingeConstraint_GetMotor();
    void bhkLimitedHingeConstraint_SetMotorActive(int aiValue);
    void bhkLimitedHingeConstraint_SetMotorTargetAngle(float afValue);
};

struct ShaderData
{
    float GetFloatAt0xC8();
    float TESCombatStyle_GetDodgeDuringAttackMult();
};

struct PropertyHolder
{
    virtual void vr000();
    virtual void vr001();
    virtual void vr002();
    virtual void vr003();
    virtual void vr004();
    virtual void vr005();
    virtual void vr006();
    virtual void vr007();
    virtual void vr008();
    virtual void vr009();
    virtual void vr00a();
    virtual void vr00b();
    virtual void vr00c();
    virtual void vr00d();
    virtual void vr00e();
    virtual void vr00f();
    virtual void vr010();
    virtual ShaderProp* FUN_vt44();
};

struct FaceProp
{
    void ForwardToScriptLocals(int aiValue);
    void bhkOrientHingedBodyAction_SetTargetDir(AlignedRotation* apRot);
};

struct GeomData
{
    virtual void vz000();
    virtual void vz001();
    virtual void vz002();
    virtual void vz003();
    virtual void vz004();
    virtual void vz005();
    virtual void vz006();
    virtual void vz007();
    virtual void vz008();
    virtual void vz009();
    virtual void vz00a();
    virtual void vz00b();
    virtual void vz00c();
    virtual void vz00d();
    virtual void vz00e();
    virtual void vz00f();
    virtual void vz010();
    virtual void vz011();
    virtual void vz012();
    virtual void vz013();
    virtual void vz014();
    virtual void vz015();
    virtual void vz016();
    virtual void vz017();
    virtual void vz018();
    virtual void vz019();
    virtual void vz01a();
    virtual void vz01b();
    virtual void vz01c();
    virtual void vz01d();
    virtual void vz01e();
    virtual void vz01f();
    virtual void vz020();
    virtual void vz021();
    virtual void vz022();
    virtual void vz023();
    virtual void vz024();
    virtual int FUN_vt94();
    ActorListNodeView* FUN_007d6bb0();
    int bhkRigidBody_GetMotionType();
    void UpdateMatchingNodes(int aiValue);
    FormType bhkWorldObject_GetCollisionFilter();
    void bhkRigidBody_SetActive(int aiValue);
};

struct Geometry
{
    GeomData* bhkNiCollisionObject_GetWorldObject();
};

struct FaceAnim
{
    void SetPairIfEnabled();
};


extern ProfileMarker DAT_011df69e;
extern Clock DAT_011f6394;
extern ActorList DAT_011f2250;
extern Actor* DAT_011f21cc;
extern Actor* DAT_011dea3c;
extern NiPoint3 DAT_011f426c;
extern NiPoint3 DAT_011a9484;
extern CameraNode* DAT_011e07d4;
extern CameraNode* DAT_011e07d0;
extern int DAT_01267e64;
extern int DAT_012683ec;
extern const double DAT_01012060;
extern const double DAT_01021798;

float __cdecl BSFadeNode_GetFadeOutMultiplier(int aiSetting);
LodManager* __cdecl BSShaderManager_GetAccumulator();
bool __cdecl Main_GetSceneIsComplex();
void __cdecl bhkBlendController_DoKnockDown(NiNode* apRoot, NiPoint3* apDir, int aiA, float afB, int aiC);
const char* __cdecl FixedStrings_QBip01Yaw();
const char* __cdecl FixedStrings_QBip01Pitch();
NiAVObject* __cdecl BSUtilities_GetObjectByName_004ade00(NiNode* apRoot, const char* apName);
void* __cdecl NiObject_DynamicCast(int* apType, int aiObject);
bool __cdecl bhkRigidBody_IsMotionTypeDynamic(int* apValue);
void __cdecl bhkWorld_SetMotion(NiAVObject* apObject, int a, int b, int c, int d);
int __cdecl bhkWorld_Getbhk(int aiValue);
void __cdecl bhkUtilFunctions_SetLayer(NiNode* apRoot, int aiValue);
float __cdecl NiCos(float afValue);
float __cdecl NiSin_005c53d0(float afValue);
void __cdecl BSClamp_float(float* apValue, float afMin, float afMax);
bool __cdecl AILinearTaskThreadManager_ShouldQueue3DTask();
FaceAnim* __stdcall FUN_004537b0(Actor* apActor, NiAVObject* apObject);
void __cdecl SetTlsValueAndReset(NiAVObject* apObject, int aiValue);
NiPoint3 __cdecl FUN_004a3760(float afScale, const NiPoint3& arPoint);


}

using namespace ActorUpdate3D;

// @fnv 0x00886cb0
// src: XBOX_PDB 0x00886cb0
void Actor::UpdateMovement_00886cb0(float afDelta, int aiUnused)
{
    DAT_011df69e.FUN_00483710();
    float fTimeSinceScaleStart = afDelta;
    if (fTimeSinceScaleStart == DAT_01012060 && !FUN_00931850())
    {
        if (DAT_011f2250.FUN_0044ddc0() == 4 && this == DAT_011f21cc)
            fTimeSinceScaleStart = DAT_011f6394.FUN_0084d030() * DAT_011f2250.GetTargetUpdateMult();
        else
            fTimeSinceScaleStart = DAT_011f6394.FUN_0084d030();
    }
    UpdateFlag800State();
    if (this != DAT_011dea3c)
    {
        NiPoint3 kTarget = DAT_011f426c;
        int iTargetFlags = 0;
        if (!FUN_vt4b4() && !PlaceAtPosition(&kTarget))
        {
            iTargetFlags = ((Holder*)m_pActorMover)->FUN_vt20();
            if (!((Holder*)m_pActorMover)->FUN_vt24(&kTarget))
            {
                PathMover* pMover = Actor_GetAnimation();
                if (pMover)
                    pMover->GetMovement(&kTarget, this, 0, 1);
            }
        }
        LookTarget* pLook = FUN_008d6f30();
        if (pLook && pLook->TESObjectCELL_GetAttached() && !DAT_011dea3c->FUN_0094df60())
        {
            Move(fTimeSinceScaleStart, &kTarget, iTargetFlags);
        }
        else
        {
            NiMatrix3 kRotate;
            kRotate.MakeZRotation(FUN_00430830()->z);
            TESObjectREFR_SetLocationOnReference(static_cast<const Actor*>(this)->GetPos()->FUN_00439e90(static_cast<const NiMatrix3&>(kRotate).operator*(kTarget)));
        }
    }
    if (Actor_IsInCombat())
        UpdateControllerFlag();
    CombatController* pCombat = m_pBaseProcess ? ((Process*)m_pBaseProcess)->FUN_vt28c() : 0;
    if (this != DAT_011dea3c)
    {
        NiNode* p3D = GetNiNode();
        if (this != DAT_011dea3c && p3D)
        {
            NiPoint3 kCameraPos;
            if (DAT_011dea3c->PlayerCharacter_Is3rdPerson() && DAT_011e07d4)
                kCameraPos = *DAT_011e07d4->NiAVObject_GetWorldTranslate();
            else if (DAT_011e07d0)
                kCameraPos = *DAT_011e07d0->NiAVObject_GetWorldTranslate();
            else
                kCameraPos = DAT_011dea3c->FUN_00436aa0()->FUN_00439e90(
                    FUN_004a3760(DAT_011dea3c->Actor_GetEyeLevel(), DAT_011a9484));
            // Preserve the original trivial snapshot copy of the bound.
            __declspec(align(4)) unsigned char boundStorage[sizeof(NiBound)];
            memcpy(boundStorage, p3D->NiAVObject_GetWorldBound(), sizeof(boundStorage));
            float fDistance =
                kCameraPos.SubtractIntoVector(*reinterpret_cast<NiBound*>(boundStorage)->FUN_006815c0()).FUN_00457990() -
                reinterpret_cast<NiBound*>(boundStorage)->FUN_0084d030() * DAT_01021798;
            bool bFar = false;
            NiObject* pFade = reinterpret_cast<NiObject*>(p3D->IsFadeNode());
            if (pFade)
            {
                float fRatio = fDistance / BSFadeNode_GetFadeOutMultiplier(3);
                bFar = fRatio > pFade->GetFloatAtOffsetB0();
            }
            LodManager* pLod = BSShaderManager_GetAccumulator();
            if (pLod && pLod->GetStringAtOffset13C())
            {
                bool bVisible = bFar ? false : fDistance > DAT_01012060;
                pLod->UpdateOrAddItem(GetHavokWorldObjectCountInSceneGraph_0084e3a0(), reinterpret_cast<NiBound*>(boundStorage), bVisible);
            }
            if (pCombat)
                pCombat->bhkCharacterController_SetFarAway(bFar);
        }
    }
    if (pCombat)
        pCombat->bhkCharacterController_SetQuickSimulate(Main_GetSceneIsComplex());
    if (m_bHasUpdated && FUN_008d8520())
    {
        NiNode* pRoot = TESObjectREFR_Get3D();
        if (pRoot)
        {
            bool bUpright = true;
            Actor* pCreature = 0;
            if (((BaseForm_actor*)BGSSaveFormBuffer_GetForm())->FUN_00401170() == 0x2b)
                pCreature = this;
            if (pCreature && !pCreature->FUN_vt38c())
                bUpright = false;
            if (m_pRagdollController && ((Havok*)m_pRagdollController)->bhkRagdollController_QRagdollAnimEnable())
                ((Havok*)m_pRagdollController)->bhkRagdollController_DisableRagdollAnim(1);
            if (m_pRagdollPenetrationUtil)
                ((Ragdoll*)m_pRagdollPenetrationUtil)->bhkRagdollPenetrationUtil_Initialize(pRoot, FUN_00931ed0().CFilter_GetGroup());
            FUN_008a1800(1);
            Unk_A8();
            if (bUpright)
            {
                NiMatrix3 kHeading;
                kHeading.MakeZRotation(GetCurrentTargetDistance(0));
                NiPoint3 kForward(0.0f, 1.0f, 0.0f);
                kForward = static_cast<const NiMatrix3&>(kHeading).operator*(kForward);
                bhkBlendController_DoKnockDown(pRoot, &kForward, 1, 0.0f, 0);
                MarkAsModified(4);
                ((Process*)m_pBaseProcess)->FUN_vt28();
            }
            else
            {
                AnimController* pAnim = (AnimController*)GetAnimData();
                if (pAnim && pAnim->Animation_GroupLoaded(0xe0))
                {
                    pAnim->Animation_ForceSection(0x14, 0xe0, -1, 0.0f, -1);
                    AnimSequence* pSequence = pAnim->Animation_GetCurrentSequence(1);
                    if (pSequence)
                    {
                        pSequence->PathingLOSGridMap_SetSightRadius(pSequence->GetEndKeyTime_00508100());
                        pAnim->Animation_Update(this, 0.0f, pSequence->GetEndKeyTime_00508100());
                        pAnim->Animation_UpdateMovement(this);
                    }
                    TryMakeTargetThing();
                }
            }
            m_bHasUpdated = false;
        }
    }
    if (GetTurretBehavior() && !HasHealth(0) && !Actor_IsUnConscious())
    {
        NiNode* pFaceRoot = GetNiNode();
        NiAVObject* pObject = BSUtilities_GetObjectByName_004ade00(pFaceRoot, FixedStrings_QBip01Yaw());
        bool bChanged = false;
        if (pObject)
        {
            NiObject* iObject = pObject->NiAVObject_GetCollisionObject();
            Geometry* m_pShaderGeometry = (Geometry*)NiObject_DynamicCast(&DAT_01267e64, (int)pObject->NiAVObject_GetCollisionObject());
            if (m_pShaderGeometry)
            {
                GeomData* pData = m_pShaderGeometry->bhkNiCollisionObject_GetWorldObject();
                ActorListNodeView* pIter = pData->FUN_007d6bb0();
                int iSkin = pData->bhkRigidBody_GetMotionType();
                if (!bhkRigidBody_IsMotionTypeDynamic(&iSkin))
                {
                    bhkWorld_SetMotion(pObject, 1, 1, 1, 1);
                    int iNewSkin = bhkWorld_Getbhk(pData->FUN_vt94());
                    pData->UpdateMatchingNodes(iNewSkin);
                    bChanged = true;
                }
                FormType kType = pData->bhkWorldObject_GetCollisionFilter();
                if (kType.CFilter_GetLayer() == 0x1d)
                    bhkUtilFunctions_SetLayer(pFaceRoot, 8);
                pData->bhkRigidBody_SetActive(1);
                while (pIter && pIter->FUN_006815c0()->Modelloader_GetReferencedThis())
                {
                    FaceProp* pFace =
                        (FaceProp*)NiObject_DynamicCast(&DAT_012683ec, (int)pIter->FUN_006815c0()->Modelloader_GetReferencedThis());
                    if (pFace)
                    {
                        float fDesiredHeadingAngle = GetCurrentTargetDistance(0);
                        AlignedRotation kRotationBasis(NiSin_005c53d0(fDesiredHeadingAngle), NiCos(fDesiredHeadingAngle), 0.0f, 0.0f);
                        pFace->ForwardToScriptLocals(1);
                        pFace->bhkOrientHingedBodyAction_SetTargetDir(&kRotationBasis);
                        break;
                    }
                    pIter = pIter->FUN_00726070();
                }
                if (AILinearTaskThreadManager_ShouldQueue3DTask())
                    FUN_004537b0(this, pObject)->SetPairIfEnabled();
                else
                    SetTlsValueAndReset(pObject, 2);
            }
        }
        pObject = BSUtilities_GetObjectByName_004ade00(pFaceRoot, FixedStrings_QBip01Pitch());
        if (pObject)
        {
            NiObject* iObject = pObject->NiAVObject_GetCollisionObject();
            Geometry* m_pShaderGeometry = (Geometry*)NiObject_DynamicCast(&DAT_01267e64, (int)pObject->NiAVObject_GetCollisionObject());
            if (m_pShaderGeometry)
            {
                GeomData* pData = m_pShaderGeometry->bhkNiCollisionObject_GetWorldObject();
                ActorListNodeView* pIter = pData->FUN_007d6bb0();
                int iSkin = pData->bhkRigidBody_GetMotionType();
                if (!bhkRigidBody_IsMotionTypeDynamic(&iSkin))
                {
                    bhkWorld_SetMotion(pObject, 1, 1, 1, 1);
                    int iNewSkin = bhkWorld_Getbhk(pData->FUN_vt94());
                    pData->UpdateMatchingNodes(iNewSkin);
                    bChanged = true;
                }
                FormType kType = pData->bhkWorldObject_GetCollisionFilter();
                if (kType.CFilter_GetLayer() == 0x1d)
                    bhkUtilFunctions_SetLayer(pFaceRoot, 8);
                pData->bhkRigidBody_SetActive(1);
                while (pIter && pIter->FUN_006815c0()->Modelloader_GetReferencedThis())
                {
                    PropertyHolder* pProps = (PropertyHolder*)pIter->FUN_006815c0()->Modelloader_GetReferencedThis();
                    ShaderProp* pShader = pProps->FUN_vt44();
                    if (pShader)
                    {
                        ShaderData* m_pSPData = pShader->bhkLimitedHingeConstraint_GetMotor();
                        float fScale = data.Angle.x;
                        BSClamp_float(&fScale, m_pSPData->TESCombatStyle_GetDodgeDuringAttackMult(), m_pSPData->GetFloatAt0xC8());
                        pShader->bhkLimitedHingeConstraint_SetMotorActive(1);
                        pShader->bhkLimitedHingeConstraint_SetMotorTargetAngle(fScale);
                        break;
                    }
                    pIter = pIter->FUN_00726070();
                }
                if (AILinearTaskThreadManager_ShouldQueue3DTask())
                    FUN_004537b0(this, pObject)->SetPairIfEnabled();
                else
                    SetTlsValueAndReset(pObject, 2);
            }
        }
        if (bChanged)
            MarkAsModified(4);
    }
    DAT_011df69e.FUN_00483710();
}

extern const char DAT_0102fdc8[];
struct P164Flags
{
    unsigned int value;
    bool FUN_004280f0(unsigned int);
};
struct P164Buffer
{
    virtual unsigned char GetVersion();
    void LoadData(void*, unsigned int);
    void FUN_008648e0(void*);
    unsigned int FUN_008648a0();
    unsigned int FUN_00864a60();
    P164Flags FUN_00428110();
};
struct P164Item
{
    TESForm* FUN_0044ddc0();
    ~P164Item();
};
struct P164Inventory
{
    P164Item* InventoryChanges_GetWornItem(unsigned int, int);
};
P164Inventory* __cdecl FUN_004bf220(TESObjectREFR*);
TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
struct P164Modifier
{
    void LoadModifiers(P164Buffer*);
};
struct ActorListEntry
{
    float value;
    TESForm* form;
};
struct P164List
{
    void FUN_005ae3d0(ActorListEntry*&);
};
struct P164Clock
{
    float ProcessLists_GetSystemTimeClock();
};
extern P164Clock DAT_011e0e80;
struct P164Biped
{
    TESForm* BipedAnim_GetParent(int);
};
// Declaration-only extension for load routines not yet exposed by the shared Actor header.
struct ActorLoadGame : Actor
{
    void Actor_LoadGame_008ab3a0(P164Buffer*);
    void MobileObject_LoadGame(P164Buffer*);
    void Actor_SetActorRefEssential(bool);
    void SetFlag40000000(bool);
    bool FUN_00566950();
    int GameSettingCollection_File();
};
struct P164Mover
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void Load(P164Buffer*);
};
struct P164Process
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual P164Item* GetLoadedForm();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void Update(bool);
};
// @fnv 0x008ab3a0
// src: XBOX_PDB 0x008ab3a0
void ActorLoadGame::Actor_LoadGame_008ab3a0(P164Buffer* buffer)
{
    int oldState = GameSettingCollection_File();
    MobileObject_LoadGame(buffer);
    m_eLifeState = (ACTOR_LIFE_STATE)oldState;
    SetWalkRunFlagDirty();
    buffer->LoadData(&ActorConditionAndAnimationState, 4);
    ActorConditionAndAnimationState = DAT_011e0e80.ProcessLists_GetSystemTimeClock() - ActorConditionAndAnimationState;
    buffer->LoadData(&ActorStateFlags, 1);
    buffer->LoadData(&ActorReferenceData, 1);
    buffer->LoadData(&m_bFirstActorFlag, 1);
    buffer->LoadData(&m_bActorFlag, 1);
    buffer->LoadData(&m_fFirstValueAfterFlag, 4);
    buffer->LoadData(&m_bSecondBooleanValue, 1);
    buffer->LoadData(&m_eAnimationGroup, 4);
    buffer->LoadData(&m_bHasUpdated, 1);
    buffer->LoadData(&ActorReferenceListData, 1);
    buffer->LoadData(&ActorBaseConfiguration, 1);
    buffer->LoadData(&m_bFlagBeforeActorBase, 1);
    buffer->LoadData(&ActorBaseReference, 1);
    buffer->LoadData(&m_bSecondActorFlag, 1);
    buffer->LoadData(&m_iIntegerBeforeTwoFloatValues, 4);
    buffer->LoadData(&BooleanIntegerTwoFloatData, 4);
    buffer->LoadData(&IntegerFloatFlagSettings, 4);
    buffer->LoadData(&m_bFirstFlagAfterForm, 1);
    buffer->LoadData(&m_bFormFlag, 1);
    buffer->LoadData(&m_bMiddleFlagBeforeActorMover, 1);
    buffer->LoadData(&m_iPackageState, 4);
    buffer->LoadData(&ActorProjectileState, 4);
    buffer->LoadData(&m_bFlagBeforeTwoBooleans, 1);
    buffer->LoadData(&m_bMiddleFlag, 1);
    if (buffer->GetVersion() >= 8)
        buffer->LoadData(&m_eCriticalStage, 4);
    if (buffer->GetVersion() >= 9)
    {
        buffer->LoadData(&m_bActorListValid, 1);
        buffer->LoadData(&m_iIntegerAfterActorListValid, 4);
        buffer->LoadData(&ActorStatusData, 1);
        buffer->LoadData(&m_uiFirstValueAfterInteger, 4);
        buffer->LoadData(&m_uiActorFlags, 4);
        Actor_SetActorRefEssential(false);
        SetFlag40000000(false);
    }
    if (buffer->GetVersion() >= 13)
        buffer->LoadData(&m_uiValueBeforeBooleanFields, 4);
    buffer->FUN_008648e0(&m_pActorReference);
    m_pActorBase = dynamic_cast<TESActorBase*>(TESForm_GetFormByNumericID(buffer->FUN_008648a0()));
    buffer->FUN_008648e0(&m_pMobileObject);
    if (buffer->FUN_00428110().FUN_004280f0(0x400))
    {
        unsigned char lifeState = 0;
        buffer->LoadData(&lifeState, 1);
        m_eLifeState = (ACTOR_LIFE_STATE)lifeState;
    }
    if (buffer->FUN_00428110().FUN_004280f0(0x80000))
    {
        unsigned int count = buffer->FUN_00864a60();
        for (unsigned int i = 0; i < count; ++i)
        {
            ActorListEntry* modifier = new ActorListEntry;
            buffer->FUN_008648e0(&modifier->form);
            buffer->LoadData(modifier, 4);
            ((P164List*)&m_kSecondPointerList)->FUN_005ae3d0(modifier);
        }
    }
    if (buffer->FUN_00428110().FUN_004280f0(0x800000))
        ((P164Modifier*)&m_kFirstActorData)->LoadModifiers(buffer);
    if (buffer->FUN_00428110().FUN_004280f0(0x400000))
        ((P164Modifier*)&m_kSecondActorData)->LoadModifiers(buffer);
    ((P164Mover*)m_pActorMover)->Load(buffer);
    if (Get3DSimple() && m_pBaseProcess)
    {
        P164Biped* inventory = ((P164Biped*)GetValidBip01Names());
        P164Inventory* biped = FUN_004bf220(this);
        if (inventory && biped)
        {
            unsigned int slots[] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
            unsigned int slotCount = 19;
            for (unsigned int slot = 0; slot < slotCount; ++slot)
            {
                TESForm* current = inventory->BipedAnim_GetParent(slot);
                P164Item* item = biped->InventoryChanges_GetWornItem(slot, 0);
                TESForm* equipped = item ? item->FUN_0044ddc0() : 0;
                if (current)
                {
                    if (((BaseForm_actor*)current)->FUN_00401170() == 12)
                        current = 0;
                    else if (current->Unk_3D())
                        current = 0;
                }
                if (current != equipped)
                {
                    ((P164Process*)m_pBaseProcess)->Update(true);
                    break;
                }
                delete item;
            }
        }
        else if (biped && IsCreature() && FUN_00566950() &&
                 strstr(TESObjectREFR_GetFullName(), DAT_0102fdc8))
        {
            P164Item* weapon = biped->InventoryChanges_GetWornItem(5, 0);
            TESForm* weaponForm = weapon ? weapon->FUN_0044ddc0() : 0;
            if (((P164Process*)m_pBaseProcess)->GetLoadedForm() &&
                ((P164Process*)m_pBaseProcess)->GetLoadedForm()->FUN_0044ddc0() != weaponForm)
                ((P164Process*)m_pBaseProcess)->Update(true);
        }
    }
    if (!HasHealth(false) && m_eCriticalStage != 0)
        m_eCriticalStage = (ACTOR_CRITICAL_STAGE)0;
}
