
// src/fallout/magic/bhkcharacterlistenerspell_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/bhkcharacterlistenerspell_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/bhkcharacterlistenerspell_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/bhkcharacterlistenerspell.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/bhkcharacterlistenerspell.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bhkcharacterlistenerspell.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/Actor.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/Setting.h"
#include "../../../include/hkTransform.h"
#include "../../../include/hkRotation.h"
#include "../../../include/hkVector4.h"
#include "../../../include/MagicProjectile.h"
#include "../../../include/NiRTTI.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/bhkCharacterProxy.h"

extern const NiRTTI g_01268344;

#include <xmmintrin.h>


#include "../../../include/NiPoint3.h"

class Matrix807
{
  public:
    Matrix807();
    float m00, m01, m02;
    float m10, m11, m12;
    float m20, m21, m22;
};

class Color807
{
  public:
    Color807(float fR, float fG, float fB);
    float r, g, b;
};

class ColorA807
{
  public:
    ColorA807(float fR, float fG, float fB, float fA);
    float r, g, b, a;
};

class Line807
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    Line807(int iType);
    void SetLocalRotation(Matrix807& kRot);
    void GetTransformScale(NiPoint3& kPos);
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
};

class DebugNode807
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
    virtual void AttachLine(Line807* pkLine, const Color807& kColor);
};


class Body807
{
  public:
    hkTransform* GetTransform();
    void* GetOwner();
};

class Event807
{
  public:
    const hkVector4& GetPosition();
    hkVector4 m_kPathOffset;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    void* m_pvCollidableA;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    void* m_pvCollidableB;
};

class EventCopy807
{
  public:
    EventCopy807(Event807* pkEvent);
    hkVector4 m_kPathOffset;
    hkVector4 m_kPlaneNormal;
    Body807* m_pkBodyA;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    Body807* m_pkBodyB;
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

class Unk815;




class Caster807
{
  public:
    Unk815* GetEffect();
};

class Effect807
{
  public:
    void* GetData();
};


class Unk815
{
  public:
    Effect807* GetEffect();
};

class Player807
{
  public:
    TESObjectREFR* GetRef();
};
extern Player807* g_pkPlayer807;

extern Setting g_kDebugSetting807;

class Debug807
{
  public:
    void AddLine(Line807* pkLine, float fTime);
};
extern Debug807* g_pkDebug807;

DebugNode807* __cdecl bhkShape_Getbhk(void* pvOwner);
void __cdecl HK2NI_00624b10(Matrix807& kOut, const hkRotation& kIn);
void __cdecl FUN_00458620(NiPoint3& kOut, const hkVector4& kIn);
void* __cdecl hkpGetPhantom(void* pvCollidable);
void* __cdecl hkpGetRigidBody(void* pvCollidable);
void* __cdecl bhkEntity_Getbhk(void* pvEntry);
Line807* __cdecl CreateOctahedron(float fSize, const ColorA807& kColor, int iType);

class Listener807
{
  public:
    TESObjectREFR* GetRef(void* pvCollidable);
    void bhkCharacterListenerSpell_contactPointAddedCallback(Event807* pkEvent);
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
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    unsigned int unk5d0;
    unsigned int unk5d4;
    unsigned int unk5d8;
    unsigned int unk5dc;
    unsigned int unk5e0;
    unsigned int unk5e4;
    unsigned int unk5e8;
    unsigned int unk5ec;
    unsigned int unk5f0;
    unsigned int unk5f4;
    unsigned int unk5f8;
    unsigned int unk5fc;
    unsigned int unk600;
    unsigned int unk604;
    unsigned int unk608;
    unsigned int unk60c;
    unsigned int unk610;
    unsigned int unk614;
    unsigned int unk618;
    unsigned int unk61c;
    unsigned int unk620;
    unsigned int unk624;
    unsigned int unk628;
    unsigned int unk62c;
    unsigned int unk630;
    unsigned int unk634;
    unsigned int unk638;
    unsigned int unk63c;
    unsigned int unk640;
    unsigned int unk644;
    unsigned int unk648;
    unsigned int unk64c;
    MagicProjectile* m_pkProjectile;
};

// Preserve the original stack protection for the address-taken collision/debug temporaries.
#pragma strict_gs_check(push, on)
// @fnv 0x008070d0
// src: XBOX_PDB 0x008070d0
void Listener807::bhkCharacterListenerSpell_contactPointAddedCallback(Event807* pkEvent)
{
    MagicProjectile* pkProjectile = dynamic_cast<MagicProjectile*>(GetRef(pkEvent->m_pvCollidableA));
    if (!pkProjectile)
        pkProjectile = m_pkProjectile;
    if (!pkProjectile->IsActive())
        return;
    TESObjectREFR* pkHit = GetRef(pkEvent->m_pvCollidableB);
    Actor* pkActor = pkHit && pkHit->IsActor() ? (Actor*)pkHit : 0;
    void* pvEntry = hkpGetPhantom(pkEvent->m_pvCollidableB);
    if (pvEntry)
    {
        if (!pkActor)
            return;
        else if (pkActor->HasHealth(0))
            return;
        else if (pkActor->GetProcess() && pkActor->GetProcess()->GetKnockedState() && pkActor->GetProcess()->GetKnockedState() != 6)
            return;
        else if (pkActor->GetSitSleepState() == 4 || pkActor->GetSitSleepState() == 9)
            return;
    }
    if (pkHit && pkHit == g_pkPlayer807->GetRef())
        return;
    if (pkActor && pkActor->GetGhost())
        return;
    if (*g_kDebugSetting807.Bool())
    {
        NiPoint3 kUnused;
        EventCopy807 kCopy(pkEvent);
        DebugNode807* pkNodeA = bhkShape_Getbhk(kCopy.m_pkBodyA->GetOwner());
        if (pkNodeA)
        {
            Line807* pkLineA = new Line807(0);
            Color807 kColorA(1.0f, 1.0f, 1.0f);
            pkNodeA->AttachLine(pkLineA, kColorA);
            Matrix807 kRotA;
            HK2NI_00624b10(kRotA, kCopy.m_pkBodyA->GetTransform()->getRotation());
            pkLineA->SetLocalRotation(kRotA);
            NiPoint3 kPosA;
            FUN_00458620(kPosA, kCopy.m_pkBodyA->GetTransform()->getTranslation());
            pkLineA->GetTransformScale(kPosA);
        }
        DebugNode807* pkNodeB = bhkShape_Getbhk(kCopy.m_pkBodyB->GetOwner());
        if (pkNodeB)
        {
            Line807* pkLineB = new Line807(0);
            Color807 kColorB(1.0f, 1.0f, 1.0f);
            pkNodeB->AttachLine(pkLineB, kColorB);
            Matrix807 kRotB;
            HK2NI_00624b10(kRotB, kCopy.m_pkBodyB->GetTransform()->getRotation());
            pkLineB->SetLocalRotation(kRotB);
            NiPoint3 kPosB;
            FUN_00458620(kPosB, kCopy.m_pkBodyB->GetTransform()->getTranslation());
            pkLineB->GetTransformScale(kPosB);
        }
    }
    NiPoint3 kPos;
    FUN_00458620(kPos, pkEvent->GetPosition());
    if (*g_kDebugSetting807.Bool())
    {
        Line807* pkMarker = CreateOctahedron(5.0f, ColorA807(1.0f, 0.0f, 0.0f, 1.0f), 1);
        pkMarker->GetTransformScale(kPos);
        g_pkDebug807->AddLine(pkMarker, 50.0f);
    }
    Caster807* pkCaster = pkProjectile->GetCaster();
    bool bActorHit = false;
    TESObjectREFR* pkHitActor = 0;
    if (pkHit && pkHit->IsActor())
    {
        bActorHit = true;
        pkHitActor = pkHit;
    }
    Unk815* pkEffect = pkCaster ? pkCaster->GetEffect() : 0;
    void* pvHitEntry = hkpGetRigidBody(pkEvent->m_pvCollidableB);
    void* pvTarget = pvHitEntry ? bhkEntity_Getbhk(pvHitEntry) : 0;
    pkProjectile->OnHit(kPos, pvTarget, pkHit, 0);
}

#pragma strict_gs_check(pop)
