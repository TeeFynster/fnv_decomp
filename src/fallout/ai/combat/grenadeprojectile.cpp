// fallout/ai/combat/grenadeprojectile.cpp: GrenadeProjectile, ImpactProjectile (11 functions)

#include "../../../../include/NiColor.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Creature.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/Projectile.h"
#include "../../../../include/bhkCollisionObject.h"
#include "../../../../include/GrenadeProjectile.h"

// Returns true if the projectile's explosion detonates, or if it has an alt trigger and a positive explosion proximity.
// @fnv 0x009bdf80
bool GrenadeProjectile::IsProximityTriggered()
{
    return GetProjectileBase()->GetHasExplosionDetonates() ||
           (GetProjectileBase()->GetHasExplosionAltTrigger() && GetProjectileBase()->GetExplosionProximity() > 0.0);
}

// Constructs the object via the base constructor with abFlag, clears bFlag150, and sets the form type to 0x3e.
// @fnv 0x009b3fa0
GrenadeProjectile::GrenadeProjectile(bool abFlag) : Projectile(abFlag)
{
    bFlag150 = false;
    SetFormType(0x3e);
}

// Calls FUN_009c43e0 with the given arguments, then invokes HandleTracer, returning the result of the first call.
// @fnv 0x009b4700
// src: COMMUNITY 0x009b4700
bool GrenadeProjectile::TurnOff(int aiArg, bool b)
{
    bool r = Projectile_DisarmPlacedExplosives(aiArg, b);
    HandleTracer();
    return r;
}

extern double _gModifierZero;
// @fnv 0x009b4c70
// src: COMMUNITY 0x009b4c70
void GrenadeProjectile::ReportHavokDeactivation()
{
    if (GetProjectileBase()->GetHasExplosionDetonates() ||
        (GetProjectileBase()->GetHasExplosionAltTrigger() &&
         GetProjectileBase()->GetExplosionProximity() > _gModifierZero))
    {
        Creature::SetNodeFlagsRecursive(reinterpret_cast<NiAVObject*>(GetNiNode()), 5, true, false, true);
    }
}

// @fnv 0x009b4d10
// src: COMMUNITY 0x009b4d10
void __thiscall GrenadeProjectile::RevertBGS_009b4d10(BGSLoadFormBuffer* apLoadGameBuffer)
{
    Projectile::RevertBGS_009c58e0(apLoadGameBuffer);
    bFlag150 = 0;
}

struct ObjHelper
{
    void* __thiscall bhkCharacterController_GetNiObject();
    TESForm* __thiscall bhkCharacterProxy_GethkShapePhantom();
};

extern TESObjectREFR* __cdecl GetReferenceFromNiAVObject(NiAVObject*);

// If a1 is set and its object resolves, gets the reference and its source file list, then calls virtual slot 203 with them.
// @fnv 0x009b4bf0
void GrenadeProjectile::DispatchReferenceSourceFiles(ObjHelper* pObjHelper, void* a2, void* a3, void* a4, void* a5,
                                                  void* a6, void* a7)
{
    if (pObjHelper)
    {
        if (pObjHelper->bhkCharacterController_GetNiObject())
        {
            TESObjectREFR* pRef8;
            BSSimpleList<TESFile*>* m_kSourceFiles;
            int nCount2;
            pRef8 = GetReferenceFromNiAVObject((NiAVObject*)pObjHelper->bhkCharacterController_GetNiObject());
            m_kSourceFiles = pObjHelper->bhkCharacterProxy_GethkShapePhantom()->GetSourceFiles();
            nCount2 = -1;
            ((void(__thiscall*)(void*, TESObjectREFR*, void**, void**, BSSimpleList<TESFile*>*, int, int))(
                (*(void***)this)[203]))(this, pRef8, &a2, &a5, m_kSourceFiles, nCount2, 0x24);
        }
    }
}

// Enables or disables the node returned by GetNiNode based on whether flag 0x200 is set.
// @fnv 0x009b46c0
void GrenadeProjectile::SetLightEnabled()
{
    TESObjectREFR_SetLight_005726e0(GetNiNode(), !Projectile_IsFlagSet(0x200));
}

// Constructs the base object, clears bFlag150, and sets the form type to 0x3e.
// @fnv 0x009b4020
GrenadeProjectile::GrenadeProjectile(void* a1, void* a2, void* a3, NiPoint3 aPoint, float a5, float a6)
    : Projectile((int)a1, (int)a2, (int)a3, reinterpret_cast<const NiPoint3&>(aPoint), a5, a6)
{
    bFlag150 = false;
    SetFormType(0x3e);
}

struct hkVector4;
// The shared header does not declare the game's out-of-line scene-object accessor.
NiAVObject* __fastcall GetCollisionSceneObject(bhkCollisionObject*);
struct FUN_00624020_Class
{
    FUN_00624020_Class* GetLastNode();
};
struct GPCdBody
{
    void* _ref_006815c0();
};
void* __cdecl hkpGetRigidBody(const void*);
NiPoint3& __cdecl SetNiPoint3FromHkVector4(NiPoint3&, const hkVector4&);
struct GPContact
{
    FUN_00624020_Class* pBodyA;
    FUN_00624020_Class* pBodyB;
    int pad08, pad0c;
    GPCdBody* pPoint;
    int pad14, pad18, pad1c;
    int iFlag;
};
struct GPRefVt
{
    virtual void r000();
    virtual void r001();
    virtual void r002();
    virtual void r003();
    virtual void r004();
    virtual void r005();
    virtual void r006();
    virtual void r007();
    virtual void r008();
    virtual void r009();
    virtual void r010();
    virtual void r011();
    virtual void r012();
    virtual void r013();
    virtual void r014();
    virtual void r015();
    virtual void r016();
    virtual void r017();
    virtual void r018();
    virtual void r019();
    virtual void r020();
    virtual void r021();
    virtual void r022();
    virtual void r023();
    virtual void r024();
    virtual void r025();
    virtual void r026();
    virtual void r027();
    virtual void r028();
    virtual void r029();
    virtual void r030();
    virtual void r031();
    virtual void r032();
    virtual void r033();
    virtual void r034();
    virtual void r035();
    virtual void r036();
    virtual void r037();
    virtual void r038();
    virtual void r039();
    virtual void r040();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r050();
    virtual void r051();
    virtual void r052();
    virtual void r053();
    virtual void r054();
    virtual void r055();
    virtual void r056();
    virtual void r057();
    virtual void r058();
    virtual void r059();
    virtual void r060();
    virtual void r061();
    virtual void r062();
    virtual void r063();
    virtual void r064();
    virtual void r065();
    virtual void r066();
    virtual void r067();
    virtual void r068();
    virtual void r069();
    virtual void r070();
    virtual void r071();
    virtual void r072();
    virtual void r073();
    virtual void r074();
    virtual void r075();
    virtual void r076();
    virtual void r077();
    virtual void r078();
    virtual void r079();
    virtual void r080();
    virtual void r081();
    virtual void r082();
    virtual void r083();
    virtual void r084();
    virtual void r085();
    virtual void r086();
    virtual void r087();
    virtual void r088();
    virtual void r089();
    virtual void r090();
    virtual void r091();
    virtual void r092();
    virtual void r093();
    virtual void r094();
    virtual void r095();
    virtual void r096();
    virtual void r097();
    virtual void r098();
    virtual void r099();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void r114();
    virtual void r115();
    virtual void r116();
    virtual void r117();
    virtual void r118();
    virtual void r119();
    virtual void r120();
    virtual void r121();
    virtual void r122();
    virtual void r123();
    virtual void r124();
    virtual void r125();
    virtual void r126();
    virtual void r127();
    virtual void r128();
    virtual void r129();
    virtual void r130();
    virtual void r131();
    virtual void r132();
    virtual void r133();
    virtual void r134();
    virtual void r135();
    virtual void r136();
    virtual bool Unk_89b();
};
// Resolves the reference behind each contact body, picks the hit target and position/normal, calls HandleHit, and flags the contact when both bodies are present.
// @fnv 0x009b4950
void GrenadeProjectile::HandleContactHit(GPContact* apContact)
{
    void* pCollA2 = hkpGetRigidBody(apContact->pBodyA->GetLastNode());
    bhkCollisionObject* pbhkA8 = pCollA2 ? bhkCollisionObject::GetFromRigidBody((const hkpRigidBody*)pCollA2) : 0;
    NiAVObject* pNiA2 = pbhkA8 ? GetCollisionSceneObject(pbhkA8) : 0;
    TESObjectREFR* pRefA_ = pNiA2 ? GetReferenceFromNiAVObject(pNiA2) : 0;
    void* pCollB3 = hkpGetRigidBody(apContact->pBodyB->GetLastNode());
    bhkCollisionObject* pbhkB_ = pCollB3 ? bhkCollisionObject::GetFromRigidBody((const hkpRigidBody*)pCollB3) : 0;
    NiAVObject* pNiB = pbhkB_ ? GetCollisionSceneObject(pbhkB_) : 0;
    TESObjectREFR* pRefB = pNiB ? GetReferenceFromNiAVObject(pNiB) : 0;
    TESObjectREFR* kPTarget = 0;
    NiPoint3 kPos = NiPoint3::ZERO;
    NiPoint3 _kNormal = NiPoint3::ZERO;
    int iShapeKey = 0;
    int iBody5 = -1;
    if (pRefA_ && ((GPRefVt*)pRefA_)->Unk_89b())
    {
        kPTarget = pRefB;
        SetNiPoint3FromHkVector4(kPos, *(const hkVector4*)apContact->pPoint->_ref_006815c0());
        SetNiPoint3FromHkVector4(_kNormal, *(const hkVector4*)((TESForm*)apContact->pPoint)->GetSourceFiles());
        ((NiColor*)&_kNormal)->operator*=(-1.0f);
        iShapeKey = (int)apContact->pBodyB->GetLastNode();
        iBody5 = (int)((BSSimpleList<TESFile*>*)apContact->pBodyB)->GetNext();
    }
    else if (pRefB && ((GPRefVt*)pRefB)->Unk_89b())
    {
        kPTarget = pRefA_;
        SetNiPoint3FromHkVector4(kPos, *(const hkVector4*)((TESForm*)apContact->pPoint)->GetSourceFiles());
        SetNiPoint3FromHkVector4(_kNormal, *(const hkVector4*)((TESForm*)apContact->pPoint)->GetSourceFiles());
        iShapeKey = (int)apContact->pBodyA->GetLastNode();
        iBody5 = (int)((BSSimpleList<TESFile*>*)apContact->pBodyA)->GetNext();
    }
    ((void(__thiscall*)(GrenadeProjectile*, TESObjectREFR*, NiPoint3*, NiPoint3*, int, int, int))
        (*(void***)this)[203])(this, kPTarget, &kPos, &_kNormal, iShapeKey, iBody5, 0x24);
    if (kPTarget && kPTarget->IsActor() && pCollA2 && pCollB3)
        apContact->iFlag = 1;
}

// Sets projectile flags based on the 0x400 test and owner cell checks, then calls FinishSetup.
// @fnv 0x009b40d0
void GrenadeProjectile::InitProjectileFlags()
{
    SetProjFlag(4, true);
    if (TestFlag400(0x400))
    {
        SetProjFlag(2, true);
        SetProjFlag(0x100, false);
    }
    else
    {
        SetProjFlag(0x100, true);
    }

    SetProjFlag(0x2000,
                (GetProjectileBase()->GetHasExplosion() && !GetProjectileBase()->FUN_00975300() && !GetProjectileBase()->GetHasExplosionDetonates_005de080()) ? true : false);
    SetProjFlag(0x8000, true);
    SetProjFlag(0x40000, true);
    FinishSetup();
}

struct Ref
{

    virtual void slot0();

    virtual void slot1();

    virtual void slot2();

    virtual void slot3();

    virtual void slot4();

    virtual void slot5();

    virtual void slot6();

    virtual void slot7();

    virtual void slot8();

    virtual void slot9();

    virtual void slot10();

    virtual void slot11();

    virtual void slot12();

    virtual void slot13();

    virtual void slot14();

    virtual void slot15();

    virtual void slot16();

    virtual void slot17();

    virtual void slot18();

    virtual void slot19();

    virtual void slot20();

    virtual void slot21();

    virtual void slot22();

    virtual void slot23();

    virtual void slot24();

    virtual void slot25();

    virtual void slot26();

    virtual void slot27();

    virtual void slot28();

    virtual void slot29();

    virtual void slot30();

    virtual void slot31();

    virtual void slot32();

    virtual void slot33();

    virtual void slot34();

    virtual void slot35();

    virtual void slot36();

    virtual void slot37();

    virtual void slot38();

    virtual void slot39();

    virtual void slot40();

    virtual void slot41();

    virtual void slot42();

    virtual void slot43();

    virtual void slot44();

    virtual void slot45();

    virtual void slot46();

    virtual void slot47();

    virtual void slot48();

    virtual void slot49();

    virtual void slot50();

    virtual void slot51();

    virtual void slot52();

    virtual void slot53();

    virtual void slot54();

    virtual void slot55();

    virtual void slot56();

    virtual void slot57();

    virtual void slot58();

    virtual void slot59();

    virtual void slot60();

    virtual void slot61();

    virtual void slot62();

    virtual void slot63();

    virtual bool IsActor();

    virtual void slot65();

    virtual void slot66();

    virtual void slot67();

    virtual void slot68();

    virtual void slot69();

    virtual void slot70();

    virtual void slot71();

    virtual void slot72();

    virtual void slot73();

    virtual void slot74();

    virtual void slot75();

    virtual void slot76();

    virtual void slot77();

    virtual void slot78();

    virtual void slot79();

    virtual void slot80();

    virtual void ApplyTime(float, int);

    virtual void slot82();

    virtual void slot83();

    virtual void slot84();

    virtual void slot85();

    virtual void slot86();

    virtual void slot87();

    virtual void slot88();

    virtual void ApplyValue(int);

    virtual int GetValue();

    virtual void slot91();

    virtual void slot92();

    virtual void slot93();

    virtual void slot94();

    virtual void slot95();

    virtual void slot96();

    virtual void slot97();

    virtual void slot98();

    virtual void slot99();

    virtual void slot100();

    virtual void slot101();

    virtual void slot102();

    virtual void slot103();

    virtual void slot104();

    virtual void slot105();

    virtual void slot106();

    virtual void slot107();

    virtual void slot108();

    virtual void slot109();

    virtual void slot110();

    virtual void slot111();

    virtual void slot112();

    virtual void slot113();

    virtual void slot114();

    virtual void slot115();

    virtual void slot116();

    virtual void slot117();

    virtual void slot118();

    virtual void slot119();

    virtual void slot120();

    virtual void slot121();

    virtual void slot122();

    virtual void slot123();

    virtual void slot124();

    virtual void slot125();

    virtual void slot126();

    virtual void slot127();

    virtual void slot128();

    virtual void slot129();

    virtual void slot130();

    virtual void slot131();

    virtual void slot132();

    virtual void slot133();

    virtual void slot134();

    virtual void slot135();

    virtual void slot136();

    virtual void slot137();

    virtual void slot138();

    virtual bool CheckFlag(int);

    virtual void slot140();

    virtual void slot141();

    virtual void slot142();

    virtual void slot143();

    virtual void slot144();

    virtual void slot145();

    virtual void slot146();

    virtual void slot147();

    virtual void slot148();

    virtual void slot149();

    virtual void slot150();

    virtual void slot151();

    virtual void slot152();

    virtual void slot153();

    virtual void slot154();

    virtual void slot155();

    virtual void slot156();

    virtual void slot157();

    virtual void slot158();

    virtual void slot159();

    virtual void slot160();

    virtual void slot161();

    virtual void slot162();

    virtual void slot163();

    virtual void slot164();

    virtual void slot165();

    virtual void slot166();

    virtual void slot167();

    virtual void slot168();

    virtual void slot169();

    virtual void slot170();

    virtual void slot171();

    virtual void slot172();

    virtual void slot173();

    virtual void slot174();

    virtual void slot175();

    virtual void slot176();

    virtual void slot177();

    virtual void slot178();

    virtual void slot179();

    virtual void slot180();

    virtual void slot181();

    virtual void slot182();

    virtual void slot183();

    virtual void slot184();

    virtual void slot185();

    virtual void slot186();

    virtual void slot187();

    virtual void slot188();

    virtual void slot189();

    virtual void slot190();

    virtual void slot191();

    virtual void slot192();

    virtual void slot193();

    virtual void slot194();

    virtual void slot195();

    virtual void slot196();

    virtual void slot197();

    virtual void slot198();

    virtual void slot199();

    virtual void slot200();

    virtual void slot201();

    virtual void slot202();

    virtual void slot203();

    virtual void slot204();

    virtual void slot205();

    virtual void slot206();

    virtual void slot207();

    virtual void slot208();

    virtual void slot209();

    virtual void slot210();

    virtual void slot211();

    virtual void slot212();

    virtual void slot213();

    virtual void slot214();

    virtual void slot215();

    virtual bool IsValidTarget();

    int TESObjectREFR_Get3D();

    bool TESForm_GetDisabledOrDeleted();

    bool FUN_00477ba0();

    unsigned int FUN_0044ddc0();

    unsigned short GetShortAtOffset1C0();

    int bhkRigidBody_GetMotionType();

    int SetEffectValue(int, float, int);

    void Actor_HitMe(void*, int);
};

struct Hit
{

    Ref* reference;

    NiPoint3 position;

    NiPoint3 normal;

    int itemID;

    int unk20;

    int unk24;

    bool valid28;

    bool valid29;
};

struct HitList
{

    Hit* data;

    HitList* next;

    bool FUN_008256d0();

    Hit** FUN_006815c0();

    HitList* FUN_00726070();
};

struct ContactHelper
{
    void* reference;

    ContactHelper(void*);

    ~ContactHelper();

    Ref* Modelloader_GetReferencedThis();
};

struct LoadedProjectile
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

    LoadedProjectile();

    ~LoadedProjectile();
};

struct Resource
{

    int TESObjectREFR_Get3D();

    int bhkRigidBody_GetMotionType();
};

struct EventStatus
{

    bool GetHasExplosion();

    bool FUN_00975300();

    bool GetHasExplosionDetonates_005de080();
};

extern Ref* DAT_011dea3c;

extern Ref* DAT_011f21e8;

extern Ref* DAT_011f21ec;

extern float DAT_0102918c;

extern double DAT_01012060;

struct TargetSettings
{
    bool VATS_IsInVats();
};
extern TargetSettings DAT_011f2250;

extern void __cdecl PlayMysteriousStrangerSound();

extern Ref* __cdecl bhkEntity_Getbhk(int);

struct FormID
{
    Ref* TESDataHandler_GetWorldSpaceList();
};

extern LoadedProjectile* __cdecl FUN_009b4d90();

extern void __cdecl InitFromObjects(Ref*, int, Ref*, int, Ref*);

struct ImpactProjectile : Ref
{

    int unk004;

    int unk008;

    int unk00c;

    int unk010;

    int unk014;

    int unk018;

    int unk01c;

    int unk020;

    int unk024;

    int unk028;

    int unk02c;

    int unk030;

    int unk034;

    int unk038;

    int unk03c;

    int unk040;

    int unk044;

    int unk048;

    int unk04c;

    int unk050;

    int unk054;

    int unk058;

    int unk05c;

    int unk060;

    int unk064;

    int unk068;

    int unk06c;

    int unk070;

    int unk074;

    int unk078;

    int unk07c;

    int unk080;

    int unk084;

    HitList list88;

    bool impacted90;

    bool ProcessHits();

    float GetFieldDC();

    Ref* Projectile_GetShooter();

    Ref* Sky_GetMode();

    EventStatus* FUN_004181e0();

    void NotifyActorIfEligible(Ref*, int);

    void ApplyImpact(Ref*, const NiPoint3*, const NiPoint3*, Ref*, int);

    NiPoint3 Projectile_GetMovementDirection(Ref*);

    void Projectile_ApplyImpactForce(NiPoint3, NiPoint3);
};

// Iterates the hit list, applies impact effects to each hit's target, and marks the projectile as impacted.
// @fnv 0x009c1b70
bool ImpactProjectile::ProcessHits()
{

    bool processed = false;

    bool inverse = false;

    if (!impacted90 && !list88.FUN_008256d0())
    {

        HitList* node = &list88;

        while (node && !node->FUN_008256d0())
        {

            Hit* hit = *node->FUN_006815c0();

            node = node->FUN_00726070();

            bool aChanged = false;

            Ref* aTarget = hit->reference;

            if (aTarget && GetFieldDC() > DAT_01012060 && hit->valid29)
            {

                int oldState = hit->reference->TESObjectREFR_Get3D();

                if (Projectile_GetShooter() && Projectile_GetShooter()->IsActor() &&

                    aTarget->IsActor() && !Projectile_GetShooter()->TESForm_GetDisabledOrDeleted())
                {

                    inverse = !aTarget->CheckFlag(0);

                    NotifyActorIfEligible(aTarget, 0);
                }
                else
                {

                    Ref* form = bhkEntity_Getbhk(hit->itemID);

                    if (form && form->bhkRigidBody_GetMotionType() < 4)

                        aTarget->ApplyValue(GetValue());

                    Ref* attacker = (Projectile_GetShooter() && Projectile_GetShooter()->IsActor()) ? Projectile_GetShooter() : 0;

                    float jump = 0.0f;

                    if (attacker && attacker->IsValidTarget() && DAT_011f2250.VATS_IsInVats() && Sky_GetMode())

                        jump = (float)Sky_GetMode()->GetShortAtOffset1C0();

                    float delay = GetFieldDC() + jump;

                    if (aTarget->IsActor())
                    {

                        Ref* actor = aTarget;
                        ContactHelper helper(new LoadedProjectile());

                        InitFromObjects(helper.Modelloader_GetReferencedThis(), 0, actor, 0, this);

                        inverse = !actor->CheckFlag(0);

                        actor->Actor_HitMe(helper.Modelloader_GetReferencedThis(), 0);
                    }
                    else
                    {

                        hit->reference->ApplyTime(delay, 0);
                    }

                    if (aTarget->FUN_00477ba0() && Projectile_GetShooter() == DAT_011dea3c)

                        DAT_011dea3c->SetEffectValue(10, DAT_0102918c, 0);
                }

                if (oldState != aTarget->TESObjectREFR_Get3D())
                    aChanged = true;
            }

            if (!aTarget || !(aTarget->FUN_0044ddc0() & 0x20))
            {

                if (!FUN_004181e0()->GetHasExplosion() || FUN_004181e0()->FUN_00975300() || FUN_004181e0()->GetHasExplosionDetonates_005de080())
                {

                    if (!aChanged)
                    {

                        if (DAT_011f21e8 && DAT_011f21e8 == Projectile_GetShooter() && aTarget && aTarget->IsActor())

                            PlayMysteriousStrangerSound();

                        if (DAT_011f21ec && DAT_011f21ec == Projectile_GetShooter() && aTarget && aTarget->IsActor() &&
                            aTarget->CheckFlag(0) && inverse)

                            PlayMysteriousStrangerSound();

                        Ref* form = hit->itemID ? ((FormID*)hit->itemID)->TESDataHandler_GetWorldSpaceList() : 0;

                        ApplyImpact(aTarget, &hit->position, &hit->normal, form, hit->unk20);

                        Projectile_ApplyImpactForce(hit->position, Projectile_GetMovementDirection(form));
                    }
                }
            }

            processed = true;

            if (TESForm_GetDisabledOrDeleted())

                break;
        }

        impacted90 = true;
    }

    return processed;
}
