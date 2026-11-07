
// src/fallout/ai/combat/hitdata_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/hitdata_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/hitdata_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/hitdata.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/hitdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/hitdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// The point operations bind to NiPoint3 (0x00439e90, 0x00439ef0, 0x0053d280).
#include "../../../../include/NiPoint3.h"
#include "../../../../include/Actor.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/HitArray.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiNode.h"
// 0x0043d450 returns the world bound; 0x006815c0 exposes its center at offset zero.
#include "../../../../include/NiBound.h"
#include "../../../../include/hkBool.h"
#include "../../../../include/hkVector4.h"

struct FUN_009b7040_shell
{
    float GetField168();
};
struct FUN_009b73b0_shell
{
    char GetByteAtOffset() const;
};
struct FUN_009b7840_shell
{
    void RaiseMaxValue(float a);
};
bool ActionPoints_IsMeleeAttackAction(int a);
extern float DAT_011f4270;
extern float DAT_011f4274;
extern NiPoint3 _NiPoint3_ZERO;
struct BooleanFloatQuery
{
    void* m_pAggressor;
    void* pTarget;
    void* m_pSourceReference;
    unsigned int m_uiHitLocation;
    unsigned int m_uiHitFlags;
    float m_fDamage;
    float m_fArmorDamage;
    float m_fHealthDamage;
    float m_fLimbDamage;
    float m_fFatigueDamage;
    float m_fSneakAttackMultiplier;
    float m_fCriticalHitMultiplier;
    void* pWeapon;
    float m_fWeaponDamage;
    NiPoint3 vOffset1;
    NiPoint3 vOffset2;
    void* m_pHitDataObjectAtOffset50;
    void* m_pHitDataObjectAtOffset54;
    unsigned int uiFlags;
    float m_fHitValueAtOffset5C;
    int BackgroundTask;
    void ClearData_009b4dc0();
};
struct GlobalObject_00869f00
{
    void Clear(bool a);
};
extern int DAT_0108f9e8;
struct FUN_009b7970_shell
{
    void InitializeAndClear();
};

class Collidable9B6;

class Collision9B6
{
  public:
    Collidable9B6* GetCollidable();
};

class Entity9B6;

class Hit9B6
{
  public:
    Hit9B6(const Hit9B6& kOther);
    const hkVector4& GetPosition();
    hkVector4 m_kPathOffset;
    hkVector4 m_kPlaneNormal;
    float m_fHitFraction;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    Collidable9B6* m_pkCollidable;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};

class Results9B6
{
  public:
    hkBool HasHits();
    HitArray* GetHits();
};

class World9B6;

class Query9B6
{
  public:
    void SetWorld(World9B6* pkWorld);
    void Cast(NiPoint3& kFrom, NiPoint3& kWorldPosition, float fScaleMultiplier);
    Results9B6* GetResults();
};

class Middle9B6
{
  public:
    World9B6* GetWorld();
};

class SpherePick9B6
{
  public:
    SpherePick9B6();
    void SetPosition(const hkVector4& kPos);
    void SetRadius(float fRadius);
    hkVector4 m_kPathOffset;
};

class BodyPart9B6
{
  public:
    int GetIndex();
    bool IsSevered();
    float GetChance();
};

class BodyPartData9B6
{
  public:
    BodyPart9B6* GetPartByType(int iType);
    BodyPart9B6* GetPart(int iIndex);
};

class Base9B6
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual BodyPartData9B6* GetBodyPartData();
};

class PartSet9B6
{
  public:
    PartSet9B6();
    ~PartSet9B6();
    bool Contains(BodyPart9B6* pkPart);
    void Add(BodyPart9B6* pkPart, bool bSevered);
    BodyPart9B6* Pick();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

class Ref9B6
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual NiAVObject* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual bool IsCrippled();
    Base9B6* GetBaseObject();
    int GetPartIndex(NiAVObject* pkObject);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
};

class Attacker9B6
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual NiAVObject* Get3D();
    NiPoint3 GetEyePosition(int iMode);
    void GetLook(NiPoint3& kPos, NiPoint3& kWorldPosition, int iMode);
    Middle9B6* GetMiddle();
};
extern Attacker9B6* g_pkPlayer9B6;

class Weapon9B6
{
  public:
    bool IsAutomatic();
    float GetSpread();
};

class LinkInfo9B6
{
  public:
    void* m_pvForm;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int m_iPart;
};

class Contact9B6
{
  public:
    int unk00;
    NiPoint3 m_kPathOffset;
    NiPoint3 m_kPlaneNormal;
    unsigned int unk1c;
    unsigned int unk20;
    int m_iPart;
};

class Event9B6
{
  public:
    Contact9B6* FindContact(Ref9B6* pkRef);
    NiPoint3 GetDirection();
};

class FloatSetting9B6
{
  public:
    float* GetFloat();
};
extern FloatSetting9B6 g_kLinkScale9B6;
extern FloatSetting9B6 g_kCrippledScale9B6;

bool __cdecl ActionPoints_IsMeleeAttackAction(void* pvForm);
Query9B6* __cdecl HitCaster_GetInstance(int iNotPlayer, int iMode);
NiAVObject* __cdecl GetAVObjectForCollidable(Collidable9B6* pkCollidable);
Ref9B6* __cdecl TESObjectREFR_FindReferenceFor3D(NiAVObject* pkObject);
Entity9B6* __cdecl hkpGetRigidBody(Collidable9B6* pkCollidable);
void __cdecl FUN_00458620(NiPoint3& kOut, const hkVector4& kIn);
void __cdecl NI2HK(hkVector4& kOut, const NiPoint3& kIn);
Collision9B6* __cdecl bhkUtilFunctions_GetClosestBody(NiAVObject* pkRoot, SpherePick9B6* pkPick, int iFlags);
float __cdecl CombatFormulas_CalcTargetedLimbDamage(ActorValueOwner* pkOwner, BodyPart9B6* pkPart, float afChance);

class Target9B6
{
  public:
    bool HasFlag(int iFlag);
    void SetChance(float afChance);
    void HitData_SetTargetedLimb(Event9B6* pkEvent);
    Attacker9B6* m_pkAttacker;
    Ref9B6* m_pkTarget;
    int unk08;
    int unk0c;
    int m_iPart;
    float m_fBaseChance;
    int unk18;
    int unk1c;
    float m_fChance;
    int unk24;
    int unk28;
    int unk2c;
    Weapon9B6* m_pkWeapon;
    int unk34;
    NiPoint3 m_kPathOffset;
    NiPoint3 m_kLightVector;
    int unk50;
    LinkInfo9B6* m_pkLink;
};

// NiPoint3 uses a union; retain the original function's stack-cookie protection.
#pragma strict_gs_check(on)
// @fnv 0x009b6620
// src: XBOX_PDB 0x009b6620
void Target9B6::HitData_SetTargetedLimb(Event9B6* pkEvent)
{
    if (!m_pkTarget || !m_pkTarget->IsActor())
        return;
    Base9B6* pkBase = m_pkTarget->GetBaseObject();
    BodyPartData9B6* pkParts = pkBase->GetBodyPartData();
    BodyPart9B6* pkPart = 0;
    bool bSearch = false;
    if (m_pkLink)
    {
        if (m_pkLink->m_iPart != -1)
        {
            if (pkParts)
            {
                pkPart = pkParts->GetPartByType(m_pkLink->m_iPart);
                m_iPart = pkPart ? pkPart->GetIndex() : 0xe;
            }
        }
        else if (ActionPoints_IsMeleeAttackAction(m_pkLink->m_pvForm))
        {
            if (HasFlag(0x800))
                m_iPart = 0;
            else
                bSearch = true;
        }
        else
        {
            m_iPart = 0xe;
        }
    }
    else if (pkEvent)
    {
        bSearch = false;
        Contact9B6* pkContact = pkEvent->FindContact(m_pkTarget);
        if (pkContact)
        {
            m_iPart = pkContact->m_iPart;
            pkPart = pkParts->GetPart(m_iPart);
            m_kPathOffset = pkContact->m_kPathOffset;
            m_kLightVector = pkEvent->GetDirection();
            m_kLightVector.Unitize();
            m_kLightVector.ComputeValue_0063c8a0(-pkContact->m_kPlaneNormal);
            m_kLightVector.Unitize();
        }
    }
    else
    {
        bSearch = true;
    }
    if (bSearch)
    {
        NiPoint3 kHitPos = m_pkAttacker->GetEyePosition(1);
        NiPoint3 kLookPos;
        NiPoint3 kLookDir;
        m_pkAttacker->GetLook(kLookPos, kLookDir, 0);
        NiPoint3 kFrom = kLookPos;
        NiPoint3 kRay = kLookDir * 200.0f;
        float fScaleMultiplier = 200.0f;
        bool bFound = false;
        PartSet9B6 kParts;
        Middle9B6* pkMiddle = m_pkAttacker->GetMiddle();
        if (pkMiddle)
        {
            Query9B6* pkQuery = HitCaster_GetInstance(m_pkAttacker != g_pkPlayer9B6, 1);
            pkQuery->SetWorld(pkMiddle->GetWorld());
            pkQuery->Cast(kFrom, kLookDir, fScaleMultiplier);
            Results9B6* pkResults = pkQuery->GetResults();
            if (pkResults->HasHits())
            {
                for (int i = 0; i < pkResults->GetHits()->FUN_00726070(); i++)
                {
                    Hit9B6 kHit(*reinterpret_cast<Hit9B6*>(pkResults->GetHits()->GetEntryAt(i)));
                    NiAVObject* pkObject = GetAVObjectForCollidable(kHit.m_pkCollidable);
                    Ref9B6* pkRef = TESObjectREFR_FindReferenceFor3D(pkObject);
                    if (pkRef && pkRef == m_pkTarget)
                    {
                        FUN_00458620(kHitPos, kHit.GetPosition());
                        Entity9B6* pkEntity = hkpGetRigidBody(kHit.m_pkCollidable);
                        if (pkEntity)
                        {
                            if (!bFound)
                            {
                                bFound = true;
                                FUN_00458620(m_kPathOffset, kHit.GetPosition());
                                m_kLightVector = kLookDir;
                            }
                            int iIndex = pkObject->IsSceneNode() ? m_pkTarget->GetPartIndex(pkObject->IsSceneNode())
                                                             : m_pkTarget->GetPartIndex(pkObject->GetParent());
                            if (iIndex != -1 && iIndex != 0xe)
                            {
                                BodyPart9B6* pkHitPart = pkParts->GetPart(iIndex);
                                if (pkHitPart && !kParts.Contains(pkHitPart))
                                    kParts.Add(pkHitPart, pkHitPart->IsSevered());
                            }
                        }
                    }
                }
            }
        }
        if (!bFound && m_pkTarget->Get3D() && m_pkAttacker->Get3D())
        {
            NiPoint3 kTargetPos = *m_pkTarget->Get3D()->GetBoundingVolume().FUN_006815c0();
            NiPoint3 kAttackerPos = *m_pkAttacker->Get3D()->GetBoundingVolume().FUN_006815c0();
            m_kPathOffset = kTargetPos + (m_pkAttacker->GetEyePosition(1) - kTargetPos).ProcessAndReturnValue_0053d280(6.0f);
            m_kLightVector = kTargetPos - kAttackerPos;
            SpherePick9B6 kPick;
            hkVector4 kTargetCenter;
            NI2HK(kTargetCenter, kHitPos);
            kPick.SetPosition(kTargetCenter);
            kPick.SetRadius(200.0f);
            Collision9B6* pkCollision = bhkUtilFunctions_GetClosestBody(m_pkTarget->Get3D(), &kPick, 0);
            if (pkCollision)
            {
                bFound = true;
                NiAVObject* pkObject = GetAVObjectForCollidable(pkCollision->GetCollidable());
                if (pkObject)
                {
                    int iIndex = pkObject->IsSceneNode() ? m_pkTarget->GetPartIndex(pkObject->IsSceneNode())
                                                     : m_pkTarget->GetPartIndex(pkObject->GetParent());
                    if (iIndex != -1)
                    {
                        BodyPart9B6* pkHitPart = pkParts->GetPart(iIndex);
                        if (pkHitPart && !kParts.Contains(pkHitPart))
                            kParts.Add(pkHitPart, pkHitPart->IsSevered());
                    }
                }
            }
        }
        if (bFound)
        {
            pkPart = kParts.Pick();
            m_iPart = pkPart ? pkPart->GetIndex() : -1;
        }
    }
    if (m_iPart == 0xe)
    {
        m_fChance = m_fBaseChance;
        if (m_pkLink)
            m_fChance *= *g_kLinkScale9B6.GetFloat();
        m_fBaseChance = 0.0f;
        return;
    }
    if (pkPart)
    {
        m_iPart = pkPart ? pkPart->GetIndex() : -1;
        m_fChance = CombatFormulas_CalcTargetedLimbDamage((Actor*)m_pkTarget, pkPart, m_fBaseChance);
        if (m_pkTarget->IsCrippled())
            m_fChance *= *g_kCrippledScale9B6.GetFloat();
        float fBodyPartChance = pkPart->GetChance();
        if (!m_pkWeapon || m_pkWeapon->IsAutomatic())
            fBodyPartChance = 1.0f;
        if (m_pkWeapon)
            m_fChance *= m_pkWeapon->GetSpread();
        SetChance(fBodyPartChance);
    }
}
