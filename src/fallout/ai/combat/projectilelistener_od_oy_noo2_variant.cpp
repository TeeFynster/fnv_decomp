
// src/fallout/ai/combat/projectilelistener_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/projectilelistener.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/projectilelistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/projectilelistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/hkVector4.h"

// Point arithmetic binds to NiPoint3: + 0x00439e90, * 0x0045bb20, Unitize 0x004a0c10.


class Matrix9C64
{
  public:
    Matrix9C64();
    void SetZRotation(float fAngleDifference);
    void SetXRotation(float fAngleDifference);
    Matrix9C64 operator*(const Matrix9C64& kMat) const;
    void GetCol(unsigned int uiCol, NiPoint3& kCol) const;
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class RayHit9C64
{
  public:
    RayHit9C64();
    RayHit9C64(const RayHit9C64& kOther);
    hkVector4 m_kPlaneNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1c;
    int m_aiShapeKeys[8];
    int m_iShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;
    void* m_pvRootCollidable;
    int unk54;
    int unk58;
    int unk5c;
};

class RayHitArray9C64
{
  public:
    int GetSize();
    RayHit9C64& GetAt(int i);
    RayHit9C64* m_pUserData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
    RayHit9C64 m_akStorage[8];
};

class RayHitCollector9C64
{
  public:
    virtual ~RayHitCollector9C64();
    float m_fEarlyOutHitFraction;
};

class AllRayHits9C64 : public RayHitCollector9C64
{
  public:
    AllRayHits9C64();
    virtual ~AllRayHits9C64();
    RayHitArray9C64* GetHits();
    RayHitArray9C64 m_kHits;
};

class PickData9C64
{
  public:
    PickData9C64();
    void SetFrom(const NiPoint3& kFrom);
    void SetTo(const NiPoint3& kTo);
    void SetCollector(AllRayHits9C64* pkCollector);
    AllRayHits9C64* GetCollector();
    hkVector4 m_kFrom;
    hkVector4 m_kTo;
    int m_iEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
    int unk28;
    int unk2c;
    RayHit9C64 m_kOutput;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    AllRayHits9C64* m_pkCollector;
    int unkac;
};

class Filter9C64
{
  public:
    Filter9C64();
    int GetLayer();
    bool IsFlagSet();
    unsigned int m_uiBits;
};

class WorldObject9C64
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
    virtual int IsFixed();
    Filter9C64 GetFilter();
};

class CollisionObject9C64
{
  public:
    WorldObject9C64* GetWorldObject();
};

class Node9C64;

class ExtraList9C64;

class Ref9C64
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
    virtual Node9C64* Get3D();
    ExtraList9C64* GetExtraData();
};

class Form9C64;

class Owner9C64
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
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const NiPoint3* GetPos();
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
    virtual float GetCurrentTargetDistance(int iMode);
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
    virtual void Notify(Ref9C64* pkRef, NiPoint3* pkPoint, NiPoint3* pkNormal, void* pvObject, unsigned int uiData,
                        int iType);
    float GetLooking() const;
    Form9C64* GetForm();
};

class Event9C64
{
  public:
    const hkVector4& GetPosition();
    const hkVector4& GetPlaneNormal();
    hkVector4 m_kPathOffset;
    hkVector4 m_kPlaneNormal;
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
    void* m_pvObject;
    unsigned int m_uiData;
};

extern NiRTTI g_kRTTI9C64;

Ref9C64* __cdecl GetReferenceFromObject(void* pvObject);
NiPoint3& __cdecl FUN_00458620(NiPoint3& kOut, const hkVector4& kIn);
NiPoint3& __cdecl HK2NINS(NiPoint3& kOut, const hkVector4& kIn);
void* __cdecl hkpGetPhantom(const void* pvObject);
WorldObject9C64* __cdecl bhkEntity_Getbhk(void* pvEntry);
bool __cdecl Script_SetActionFlag(void* pvForm, ExtraList9C64* pkExtra, unsigned int uiFlag);
bool __cdecl NiObject_IsKindOf(NiRTTI* pkRTTI, WorldObject9C64* pkObject);
CollisionObject9C64* __cdecl FindFirstCollisionObject(Node9C64* pkNode);
bool __cdecl Projectile_PickSceneGraph(PickData9C64* pkPick, Node9C64* pkNode, bool bCheckMotion, bool bUpdate);

class Listener9C64
{
  public:
    void ProjectileListener_contactPointAddedCallback(void* pvUnused, Event9C64* pkEvent);
    unsigned int unk00;
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
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    Owner9C64* m_pkOwnerManager;
};

// Preserve the original /GS stack protection with the shared vector union.
#pragma strict_gs_check(push, on)
// @fnv 0x009c6490
// src: COMMUNITY 0x009c6490
void Listener9C64::ProjectileListener_contactPointAddedCallback(void* pvUnused, Event9C64* pkEvent)
{
    Owner9C64* pkOwner = m_pkOwnerManager;
    if (!pkOwner)
        return;
    Ref9C64* pkRef = GetReferenceFromObject(pkEvent->m_pvObject);
    NiPoint3 kPoint;
    FUN_00458620(kPoint, pkEvent->GetPosition());
    NiPoint3 kNormal;
    HK2NINS(kNormal, pkEvent->GetPlaneNormal());
    void* pvObject = pkEvent->m_pvObject;
    unsigned int uiData = pkEvent->m_uiData;
    void* pvEntry = hkpGetPhantom(pvObject);
    WorldObject9C64* pkWorldObject = pvEntry ? bhkEntity_Getbhk(pvEntry) : 0;
    if (pkRef && pkWorldObject &&
        (pkWorldObject->GetFilter().GetLayer() == 0x17 || pkWorldObject->GetFilter().GetLayer() == 0x18))
    {
        Script_SetActionFlag(pkOwner, pkRef->GetExtraData(), 0x80);
        if (pkOwner->GetForm())
            Script_SetActionFlag(pkOwner->GetForm(), pkRef->GetExtraData(), 0x100);
        return;
    }
    bool bBlocked = false;
    if (pkWorldObject && (NiObject_IsKindOf(&g_kRTTI9C64, pkWorldObject) || pkWorldObject->GetFilter().GetLayer() == 0x1e))
    {
        bBlocked = true;
        Node9C64* pkNode = pkRef ? pkRef->Get3D() : 0;
        CollisionObject9C64* pkCollision = FindFirstCollisionObject(pkNode);
        WorldObject9C64* pkRefObject = pkCollision ? pkCollision->GetWorldObject() : 0;
        if (pkRefObject && (pkRefObject->GetFilter().IsFlagSet() || !pkRefObject->IsFixed()))
        {
            PickData9C64 kPick;
            NiPoint3 kFrom;
            NiPoint3 kRay;
            NiPoint3 kForward;
            kFrom = *pkOwner->GetPos();
            Matrix9C64 kRot;
            kRot.SetZRotation(pkOwner->GetCurrentTargetDistance(0));
            Matrix9C64 kPitch;
            kPitch.SetXRotation(pkOwner->GetLooking());
            kRot = kRot * kPitch;
            kRot.GetCol(1, kForward);
            kForward.Unitize();
            kRay = kForward * 1000.0f;
            kPick.SetFrom(kFrom);
            kPick.SetTo(kRay);
            AllRayHits9C64 kHits;
            kPick.SetCollector(&kHits);
            bool bHitDetected = Projectile_PickSceneGraph(&kPick, pkNode, false, true);
            if (bHitDetected && kPick.GetCollector()->GetHits()->GetSize() > 0)
            {
                bBlocked = false;
                RayHit9C64 kHit(kPick.GetCollector()->GetHits()->GetAt(0));
                NiPoint3 kIntersectionOffset = kRay * kHit.m_fHitFraction;
                kPoint = kFrom + kIntersectionOffset;
                HK2NINS(kNormal, kHit.m_kPlaneNormal);
                pvObject = kHit.m_pvRootCollidable;
                int iShapeKey = -1;
                for (int i = 0; i < 8 && kHit.m_aiShapeKeys[i] != -1; i++)
                    iShapeKey = kHit.m_aiShapeKeys[i];
            }
        }
    }
    if (!bBlocked)
        pkOwner->Notify(pkRef, &kPoint, &kNormal, pvObject, uiData, 0x24);
}

#pragma strict_gs_check(pop)
