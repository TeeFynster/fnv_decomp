
// src/havok/unplaced/viewcaster_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/havok/unplaced/viewcaster_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/unplaced/viewcaster_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/havok/unplaced/viewcaster.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/havok/unplaced/viewcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/viewcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
// Point631 used NiPoint3 addition (0x00439e90) and scalar multiplication (0x0045bb20).
#include "../../../include/NiPoint3.h"
#include "../../../include/NiAVObject.h"
#include "../../../include/hkBool.h"
// HitArray accessors bind to the shared FUN_00726070 (0x00726070) and GetEntryAt (0x00807770).
#include "../../../include/HitArray.h"
// Transform631 held four aligned Havok columns, rather than Transform.h's packed scene transform.
#include "../../../include/hkTransform.h"
// hkSimdReal631 was the vector scalar returned by hkVector4::dot3/length3; getReal binds to 0x004586d0.
#include "../../../include/hkSimdReal.h"
// This /Od unit calls the out-of-line assignment and subtraction copies.
#define FNV64_HKVECTOR4_OWN_ASSIGN
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#include "../../../include/hkVector4.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/Actor.h"

class Entity631
{
  public:
    const hkTransform& GetTransform();
};

class Filter631
{
  public:
    Filter631();
    Filter631(unsigned int uiFilterInfo);
    int GetLayer();
    unsigned int GetValue();
    unsigned int m_uiBits;
};

class RayInput631
{
  public:
    RayInput631();
    hkVector4 m_kFrom;
    hkVector4 m_kTo;
    unsigned int m_uiFilter;
    int unk24;
    int unk28;
    int unk2c;
};

class RayOutput631
{
  public:
    RayOutput631();
    void Reset();
    hkBool HasHit();
    hkVector4 m_kPlaneNormal;
    float m_fHitFraction;
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
};

class Owner631
{
  public:
    int GetType();
    hkBool CastRay(RayInput631& kInput, RayOutput631& kOutput);
};

class Collidable631
{
  public:
    unsigned int GetFilterInfo();
    Owner631* GetOwner();
};

class Hit631
{
  public:
    Hit631(const Hit631& kOther);
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
    Collidable631* m_pkCollidable;
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

class Query631
{
  public:
    Query631();
    ~Query631();
    hkBool HasHits();
    void Sort();
    HitArray* GetHits();
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
    __m128 m_qc0;
    __m128 m_qd0;
    __m128 m_qe0;
    __m128 m_qf0;
    __m128 m_q100;
    __m128 m_q110;
    __m128 m_q120;
    __m128 m_q130;
    __m128 m_q140;
    __m128 m_q150;
    __m128 m_q160;
    __m128 m_q170;
    __m128 m_q180;
    __m128 m_q190;
    __m128 m_q1a0;
    __m128 m_q1b0;
    __m128 m_q1c0;
    __m128 m_q1d0;
    __m128 m_q1e0;
    __m128 m_q1f0;
    __m128 m_q200;
    __m128 m_q210;
    __m128 m_q220;
    __m128 m_q230;
    __m128 m_q240;
    __m128 m_q250;
    __m128 m_q260;
    __m128 m_q270;
    __m128 m_q280;
    __m128 m_q290;
    __m128 m_q2a0;
    __m128 m_q2b0;
    __m128 m_q2c0;
    __m128 m_q2d0;
    __m128 m_q2e0;
    __m128 m_q2f0;
    __m128 m_q300;
    __m128 m_q310;
    __m128 m_q320;
    __m128 m_q330;
    __m128 m_q340;
    __m128 m_q350;
    __m128 m_q360;
    __m128 m_q370;
    __m128 m_q380;
    __m128 m_q390;
};

class CastInput631
{
  public:
    CastInput631();
    hkVector4 m_kTo;
    float m_fRadiusA;
    float m_fRadiusB;
    int unk18;
    int unk1c;
};

class Shape631
{
  public:
    Filter631 GetFilter();
    void Cast(const hkVector4& kFrom, CastInput631& kInput, Query631& kQuery, int iFlags);
};

class RayHit631
{
  public:
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
    void* m_pvRootCollidable;
};

class RayHitArray
{
  public:
    int GetSize();
    RayHit631* GetAt(int i);
};

class RayHitCollector631
{
  public:
    virtual ~RayHitCollector631();
    float m_fEarlyOutHitFraction;
};

class AllRayHits631 : public RayHitCollector631
{
  public:
    AllRayHits631();
    virtual ~AllRayHits631();
    RayHitArray* GetHits();
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
    __m128 m_qb0;
    __m128 m_qc0;
    __m128 m_qd0;
    __m128 m_qe0;
    __m128 m_qf0;
    __m128 m_q100;
    __m128 m_q110;
    __m128 m_q120;
    __m128 m_q130;
    __m128 m_q140;
    __m128 m_q150;
    __m128 m_q160;
    __m128 m_q170;
    __m128 m_q180;
    __m128 m_q190;
    __m128 m_q1a0;
    __m128 m_q1b0;
    __m128 m_q1c0;
    __m128 m_q1d0;
    __m128 m_q1e0;
    __m128 m_q1f0;
    __m128 m_q200;
    __m128 m_q210;
    __m128 m_q220;
    __m128 m_q230;
    __m128 m_q240;
    __m128 m_q250;
    __m128 m_q260;
    __m128 m_q270;
    __m128 m_q280;
    __m128 m_q290;
    __m128 m_q2a0;
    __m128 m_q2b0;
    __m128 m_q2c0;
    __m128 m_q2d0;
    __m128 m_q2e0;
    __m128 m_q2f0;
    __m128 m_q300;
    __m128 m_q310;
};

class Pick631
{
  public:
    Pick631();
    void SetFilter(Filter631 kFilter);
    void SetFrom(const hkVector4& kFrom);
    void SetTo(const hkVector4& kTo);
    void SetCollector(AllRayHits631* pkCollector);
    bool IsSingleHit();
    __m128 m_q00;
    __m128 m_q10;
    __m128 m_q20;
    __m128 m_q30;
    __m128 m_q40;
    __m128 m_q50;
    __m128 m_q60;
    __m128 m_q70;
    __m128 m_q80;
    __m128 m_q90;
    __m128 m_qa0;
};

class Caster631
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
    virtual void CastRay(Pick631* pkPick);
};

class BaseForm631
{
  public:
    int GetFormType();
    bool IsPlayable();
};
extern BaseForm631* g_pkSpecialBase631;

class Process631
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
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual int GetState();
};

class Controller631
{
  public:
    int GetMode();
};

extern TESObjectREFR* g_pkPlayer631;

class Result631
{
  public:
    void* GetObject();
    float GetDistance();
};

class Results631
{
  public:
    unsigned int GetCount();
    Result631* GetAt(int i);
};

class List631
{
  public:
    List631(int iA, int iB);
    ~List631();
    void SetMode(int iMode);
    void SetSorted(int iSorted);
    Results631* GetResults();
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
};

class Scope631
{
  public:
    Scope631(int iType, int iFlag, const char* pcFile, int iLine);
    ~Scope631();
    int unk00;
};

class BoolSetting631
{
  public:
    bool* GetBool();
};
class IntSetting631
{
  public:
    int* GetInt();
};
extern BoolSetting631 g_kCheckSetting631;
extern IntSetting631 g_kMaxHits631;
extern IntSetting631 g_kMaxTargets631;
extern IntSetting631 g_kMaxRays631;
extern int g_iLine631;
extern void* g_pvLastHit631;

void __cdecl NI2HK(hkVector4& kOut, const NiPoint3& kIn);
NiAVObject* __cdecl GetAVObjectForCollidable(Collidable631* pkCollidable);
TESObjectREFR* __cdecl TESObjectREFR_FindReferenceFor3D(void* pvObject);
Entity631* __cdecl hkpGetRigidBody(Collidable631* pkCollidable);
void* __cdecl bhkEntity_Getbhk(Entity631* pkEntity);
void __cdecl PickDistance(List631* pkList, const NiPoint3* pkOrigin, const NiPoint3* pkDir, float fImpulseRadiusSquared,
                          NiAVObject* pkNode, int iFlags);
float __cdecl HK2NI(float fValue);

// ViewCaster has no shared include/ header yet; retain its declaration with its real name.
class ViewCaster
{
  public:
    bool IsEnabled();
    Shape631* GetShape();
    Caster631* GetCaster();
    void Prepare();
    TESObjectREFR* FindActivateREFR(const NiPoint3* pkOrigin, const NiPoint3* pkDir, float fImpulseRadiusSquared, float* pfDistance,
                                   bool* pbAlternate);
};

// @fnv 0x00631d60
// src: XBOX_PDB 0x00631d60
TESObjectREFR* ViewCaster::FindActivateREFR(const NiPoint3* pkOrigin, const NiPoint3* pkDir, float fImpulseRadiusSquared,
                                              float* pfDistance, bool* pbAlternate)
{
    Scope631 kScope(0x10, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Havok\\ViewCaster.cpp", 0x9b);
    g_pvLastHit631 = 0;
    TESObjectREFR* pkResult = 0;
    if (IsEnabled() && GetShape() && GetCaster())
    {
        Query631 kQuery;
        Caster631* pkCaster = GetCaster();
        NiPoint3 kEnd = *pkOrigin + *pkDir * fImpulseRadiusSquared;
        *pbAlternate = false;
        *pfDistance = 3.402823466e+38f;
        List631 kList(0, 8);
        kList.SetMode(0);
        kList.SetSorted(1);
        g_iLine631 = 0xdad;
        hkVector4 kFrom;
        NI2HK(kFrom, *pkOrigin);
        hkVector4 kTo;
        NI2HK(kTo, kEnd);
        bool bHits = false;
        CastInput631 kInput;
        kInput.m_fRadiusB = 0.01f;
        kInput.m_fRadiusA = 0.01f;
        kInput.m_kTo = kTo;
        Prepare();
        GetShape()->Cast(kFrom, kInput, kQuery, 0);
        if (kQuery.HasHits().operator bool())
        {
            kQuery.Sort();
            bHits = true;
        }
        TESObjectREFR* pkClosest = 0;
        float fClosest = 3.402823466e+38f;
        TESObjectREFR* pkAlternate = 0;
        float fAlternateDistance = 3.402823466e+38f;
        float fAlternateOffset = 3.402823466e+38f;
        void* pvAlternateHit = 0;
        bool bCheck = *g_kCheckSetting631.GetBool();
        int iRays = 0;
        int iHits = 0;
        int iTargets = 0;
        if (bHits)
        {
            g_iLine631 = 0xdae;
            TESObjectREFR* pkLast = 0;
            TESObjectREFR* pkRef = 0;
            Entity631* pkLastEntity = 0;
            for (int i = 0; i < kQuery.GetHits()->FUN_00726070(); i++)
            {
                g_iLine631 = 0xdaf;
                Hit631 kHit(*reinterpret_cast<Hit631*>(kQuery.GetHits()->GetEntryAt(i)));
                if (kHit.m_pkCollidable)
                {
                    g_iLine631 = 0xdb0;
                    NiAVObject* pkObject = GetAVObjectForCollidable(kHit.m_pkCollidable);
                    g_iLine631 = 0xdb1;
                    if (pkObject)
                        pkRef = TESObjectREFR_FindReferenceFor3D(pkObject);
                    if (!pkRef || pkRef == g_pkPlayer631)
                        continue;
                    bool bHidden = false;
                    NiAVObject* pkWalk = pkObject;
                    NiAVObject* pkRoot = reinterpret_cast<NiAVObject*>(pkRef->GetNiNode());
                    while (!bHidden && pkWalk && pkWalk != pkRoot)
                    {
                        bHidden |= pkWalk->GetAppCulled_00456610();
                        pkWalk = reinterpret_cast<NiAVObject*>(pkWalk->GetParent());
                    }
                    if (bHidden)
                        continue;
                    Entity631* pkEntity = hkpGetRigidBody(kHit.m_pkCollidable);
                    bool bSolid = false;
                    Filter631 kFilter(kHit.m_pkCollidable->GetFilterInfo());
                    switch (kFilter.GetLayer())
                    {
                    case 4:
                    case 5:
                    case 6:
                        bSolid = true;
                        break;
                    case 1: {
                        Owner631* pkOwner = kHit.m_pkCollidable->GetOwner();
                        if (pkOwner && pkOwner->GetType() == 0xa)
                            bSolid = true;
                    }
                    break;
                    }
                    if (reinterpret_cast<BaseForm631*>(pkRef->BGSSaveFormBuffer_GetForm()) == g_pkSpecialBase631)
                        bSolid = true;
                    if (pkEntity && pkEntity != pkLastEntity && bSolid)
                    {
                        pkLastEntity = pkEntity;
                        if (iHits < *g_kMaxHits631.GetInt())
                        {
                            iHits++;
                            RayInput631 kRay;
                            kRay.m_uiFilter = GetShape()->GetFilter().GetValue();
                            hkTransform kXform(pkEntity->GetTransform());
                            kRay.m_kFrom.hkVector4_setTransformedInversePos(kXform, kFrom);
                            kRay.m_kTo.hkVector4_setTransformedInversePos(kXform, kTo);
                            RayOutput631 kOut;
                            kOut.Reset();
                            Owner631* pkShape = kHit.m_pkCollidable->GetOwner();
                            pkShape->CastRay(kRay, kOut);
                            if (kOut.HasHit().operator bool())
                            {
                                if (kOut.m_fHitFraction < fClosest)
                                {
                                    pkClosest = pkRef;
                                    fClosest = kOut.m_fHitFraction;
                                }
                            }
                        }
                    }
                    else
                    {
                        g_iLine631 = 0xdb2;
                        if (pkLast != pkRef && reinterpret_cast<NiAVObject*>(pkRef->GetNiNode()) && iTargets < *g_kMaxTargets631.GetInt())
                        {
                            iTargets++;
                            PickDistance(&kList, pkOrigin, pkDir, fImpulseRadiusSquared, reinterpret_cast<NiAVObject*>(pkRef->GetNiNode()), 0);
                        }
                    }
                    bool bValid = true;
                    switch (kFilter.GetLayer())
                    {
                    case 30:
                        if (pkRef->IsActor())
                        {
                            Process631* pkProcess = reinterpret_cast<Process631*>(static_cast<Actor*>(pkRef)->GetProcess());
                            Controller631* pkController = reinterpret_cast<Controller631*>(static_cast<Actor*>(pkRef)->FUN_009306d0());
                            if (pkProcess && pkController && pkController->GetMode() == 1)
                            {
                                int iState = pkProcess->GetState();
                                if (iState == 9 || iState == 4)
                                    bValid = false;
                            }
                        }
                        break;
                    case 1:
                    case 13:
                    case 17:
                    case 18:
                        bValid = false;
                        break;
                    case 6:
                        if (!pkEntity)
                            bValid = false;
                        break;
                    }
                    if (bValid && bCheck && pkCaster)
                    {
                        hkVector4 kIntersectionOffset;
                        kIntersectionOffset.setSub4(kHit.GetPosition(), kFrom);
                        hkVector4 kWorldPosition;
                        kWorldPosition.setSub4(kTo, kFrom);
                        kWorldPosition.normalize3_0062aea0();
                        kWorldPosition.hkVector4_mul4(kWorldPosition.dot3(kIntersectionOffset));
                        hkVector4 kPerp;
                        kPerp.setSub4(kIntersectionOffset, kWorldPosition);
                        float fProjectionAlongAim = HK2NI(kPerp.length3().getReal());
                        if (fProjectionAlongAim < fAlternateOffset)
                        {
                            if (iRays < *g_kMaxRays631.GetInt())
                            {
                                if (pkAlternate && pkAlternate == pkRef)
                                {
                                    fAlternateDistance = HK2NI(kIntersectionOffset.length3().getReal());
                                    fAlternateOffset = fProjectionAlongAim;
                                }
                                else
                                {
                                    iRays++;
                                    Pick631 kPick;
                                    kPick.SetFilter(GetShape()->GetFilter());
                                    kPick.SetFrom(kFrom);
                                    kPick.SetTo(kHit.GetPosition());
                                    AllRayHits631 kRayHits;
                                    kPick.SetCollector(&kRayHits);
                                    pkCaster->CastRay(&kPick);
                                    if (!kPick.IsSingleHit())
                                    {
                                        if (kRayHits.GetHits()->GetSize() > 0)
                                        {
                                            NiAVObject* pkHitObject = GetAVObjectForCollidable(
                                                (Collidable631*)kRayHits.GetHits()->GetAt(0)->m_pvRootCollidable);
                                            if (pkHitObject)
                                            {
                                                TESObjectREFR* pkHitRef = TESObjectREFR_FindReferenceFor3D(pkHitObject);
                                                if (pkHitRef && pkHitRef == pkRef)
                                                {
                                                    pkAlternate = pkRef;
                                                    fAlternateDistance =
                                                        HK2NI(kIntersectionOffset.length3().getReal());
                                                    fAlternateOffset = fProjectionAlongAim;
                                                    pvAlternateHit = bhkEntity_Getbhk(pkEntity);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            pkAlternate = pkRef;
                                            fAlternateDistance = HK2NI(kIntersectionOffset.length3().getReal());
                                            fAlternateOffset = fProjectionAlongAim;
                                            pvAlternateHit = bhkEntity_Getbhk(pkEntity);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    g_iLine631 = 0xdb3;
                    pkLast = pkRef;
                }
            }
        }
        fClosest *= fImpulseRadiusSquared;
        g_iLine631 = 0xdb5;
        if (kList.GetResults()->GetCount() > 0)
        {
            g_iLine631 = 0xdb6;
            void* pvObject = kList.GetResults()->GetAt(0)->GetObject();
            g_iLine631 = 0xdb7;
            pkResult = TESObjectREFR_FindReferenceFor3D(pvObject);
            g_iLine631 = 0xdb8;
            *pfDistance = kList.GetResults()->GetAt(0)->GetDistance();
            g_iLine631 = 0xdb9;
            if (*pfDistance > fClosest)
            {
                *pfDistance = fClosest;
                pkResult = pkClosest;
            }
        }
        else if (pkClosest)
        {
            *pfDistance = fClosest;
            pkResult = pkClosest;
        }
        g_iLine631 = 0xdba;
        if (bCheck)
        {
            bool bUseAlternate = true;
            if (pkResult && reinterpret_cast<BaseForm631*>(pkResult->BGSSaveFormBuffer_GetForm()))
            {
                bUseAlternate = false;
                switch (reinterpret_cast<BaseForm631*>(pkResult->BGSSaveFormBuffer_GetForm())->GetFormType())
                {
                case 0x20:
                case 0x21:
                case 0x25:
                    bUseAlternate = true;
                    break;
                case 0x1e:
                    if (!reinterpret_cast<BaseForm631*>(pkResult->BGSSaveFormBuffer_GetForm())->IsPlayable())
                        bUseAlternate = true;
                    break;
                }
            }
            if (bUseAlternate && pkAlternate && pkResult != pkAlternate)
            {
                *pfDistance = fAlternateDistance;
                pkResult = pkAlternate;
                *pbAlternate = true;
                g_pvLastHit631 = pvAlternateHit;
            }
        }
    }
    return pkResult;
}
