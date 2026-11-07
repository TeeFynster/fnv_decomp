
// src/fallout/ai/combat/vats_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/ai/combat/vats_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/vats_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/vats.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../../include/bhkWorld.h"
#include "../../../../include/Actor.h"
#include "../../../../include/VATSCommand.h"
typedef char _sizecheck_VATS_COMMAND[sizeof(VATSCommand) == 40 ? 1 : -1];
struct PlayerCharacter;
extern PlayerCharacter* DAT_011f21f0;
struct FUN_00498910_shell
{
    void Animation_SpecialIdleFree(bool, bool);
};
struct Node
{
    VATSCommand* item;
    Node* next;
};
struct StandIn
{
    void* FUN_009c8870(unsigned int);
};
extern float DAT_011afe74;
extern float DAT_011afe78;
extern unsigned char DAT_012677cc;
float __cdecl bhkWorld_GetMaxPickTime();
struct SoundListEntry;
struct SoundListView
{
    void AddTail(SoundListEntry* const&);
    void AddCommand(SoundListEntry* apCommand);
};
struct ListHolder
{
    bool _ref_008256d0();
    void* _ref_006815c0();
    void* VATS_GetCurrentAction();
};
struct MyList
{
    bool _ref_008256d0();
    MyList* _ref_00726070();
    VATSCommand** _ref_006815c0();
    VATSCommand* VATS_GetLastAction();
};
float __cdecl bhkWorld_GetMaxPickTime();
extern float DAT_012677c4;
bool __cdecl bhkWorld_GetPickTimeOverMax();
struct FUN_009c9900_shell
{
    void SetByteAt76(unsigned char param_2);
};
struct Helper62d0
{
    Helper62d0& operator=(void const*);
};
struct FUN_009d9ec0_shell
{
    void AssignAtOffsetB0(void* p);
};

#include <xmmintrin.h>
class NiPoint3L8
{
  public:
    float x;
    float y;
    float z;
};

class HitResultsL8
{
  public:
    HitResultsL8();
    ~HitResultsL8();
    __m128 m_akData[50];
};

class HitL8
{
  public:
    HitL8(void* pvHit);
    __m128 m_akPad[5];
    void* m_pvCollidable;
    int m_aiPad[3];
};

class HitListL8
{
  public:
    int GetCount();
    void* GetAt(int iIndex);
};

class HitArrayL8
{
  public:
    HitListL8* GetList();
};

class PickFlagsL8
{
  public:
    PickFlagsL8(int iValue);
    void SetType(int iType);
    void SetTarget(void* pvTarget);
    int m_iValue;
};

class PickQueryL8
{
  public:
    PickQueryL8();
    void SetFlags(PickFlagsL8 kFlags);
    void SetOrigin(const NiPoint3L8& akStart);
    void SetEnd(const NiPoint3L8& kEnd);
    void SetResults(HitResultsL8* pkResults);
    HitArrayL8* GetHits();
    __m128 m_akData[11];
};

class WorldL8
{
  public:
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w00a();
    virtual void w00b();
    virtual void w00c();
    virtual void w00d();
    virtual void w00e();
    virtual void w00f();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w01a();
    virtual void w01b();
    virtual void w01c();
    virtual void w01d();
    virtual void w01e();
    virtual void w01f();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w02a();
    virtual void w02b();
    virtual void w02c();
    virtual void w02d();
    virtual void w02e();
    virtual void w02f();
    virtual void w030();
    virtual void w031();
    virtual bool Pick(PickQueryL8& kQuery);
};

class CellL8
{
  public:
    WorldL8* GetWorld();
};

class ProjL8
{
  public:
    void* GetTarget();
};

class RefL8
{
  public:
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
    virtual void r00a();
    virtual void r00b();
    virtual void r00c();
    virtual void r00d();
    virtual void r00e();
    virtual void r00f();
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
    virtual void r01a();
    virtual void r01b();
    virtual void r01c();
    virtual void r01d();
    virtual void r01e();
    virtual void r01f();
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
    virtual void r02a();
    virtual void r02b();
    virtual void r02c();
    virtual void r02d();
    virtual void r02e();
    virtual void r02f();
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
    virtual void r03a();
    virtual void r03b();
    virtual void r03c();
    virtual void r03d();
    virtual void r03e();
    virtual void r03f();
    virtual bool IsActor();
    virtual void r041();
    virtual void r042();
    virtual void r043();
    virtual void r044();
    virtual void r045();
    virtual void r046();
    virtual void r047();
    virtual void r048();
    virtual void r049();
    virtual void r04a();
    virtual void r04b();
    virtual void r04c();
    virtual void r04d();
    virtual void r04e();
    virtual void r04f();
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
    virtual void r05a();
    virtual void r05b();
    virtual void r05c();
    virtual void r05d();
    virtual void r05e();
    virtual void r05f();
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
    virtual void r06a();
    virtual void r06b();
    virtual void r06c();
    virtual void r06d();
    virtual void r06e();
    virtual void r06f();
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
    virtual void r07a();
    virtual void r07b();
    virtual void r07c();
    virtual const NiPoint3L8* GetPos();
    CellL8* GetParentCell();
    ProjL8* GetProjectileData();
};
extern RefL8* g_pkPlayerL8;

class PackageL8
{
  public:
    char m_acPad[0xc];
    RefL8* m_pkTarget;
};

void __cdecl FUN_00c82870(int iLayer, unsigned __int64 ulMask);
void* __cdecl bhkCollisionFilter_GetNewSystemGroup();
void* __cdecl GetAVObjectForCollidable(void* pvCollidable);
RefL8* __cdecl TESObjectREFR_FindReferenceFor3D(void* pvCollidable);

class CheckerL8
{
  public:
    bool VATS_GetLineOfSight(PackageL8* pkPackage);
};

// @fnv 0x009c8f20
// src: COMMUNITY 0x009c8f20
bool CheckerL8::VATS_GetLineOfSight(PackageL8* pkPackage)
{
    RefL8* pkTarget = 0;
    if (pkPackage->m_pkTarget->IsActor())
        pkTarget = pkPackage->m_pkTarget;
    if (!pkTarget)
        return false;
    WorldL8* pkWorld = pkTarget->GetParentCell() ? pkTarget->GetParentCell()->GetWorld() : 0;
    if (!pkWorld)
        return false;
    unsigned int uiMask = 0x26206;
    FUN_00c82870(0x27, uiMask);
    NiPoint3L8 kFrom = *g_pkPlayerL8->GetPos();
    NiPoint3L8 kTo = *pkTarget->GetPos();
    kFrom.z += 60.0;
    kTo.z += 60.0;
    PickQueryL8 kQuery;
    PickFlagsL8 kFlags(0);
    kFlags.SetType(0x27);
    RefL8* pkActor = pkTarget->IsActor() ? pkTarget : 0;
    if (pkActor && pkActor->GetProjectileData())
        kFlags.SetTarget(pkActor->GetProjectileData()->GetTarget());
    else
        kFlags.SetTarget(bhkCollisionFilter_GetNewSystemGroup());
    kQuery.SetFlags(kFlags);
    kQuery.SetOrigin(kFrom);
    kQuery.SetEnd(kTo);
    HitResultsL8 kResults;
    kQuery.SetResults(&kResults);
    bool bPickResultFound = false;
    pkWorld->Pick(kQuery);
    for (int i = 0; !bPickResultFound && i < kQuery.GetHits()->GetList()->GetCount(); i++)
    {
        HitL8 kHit(kQuery.GetHits()->GetList()->GetAt(i));
        void* pvCollidable = GetAVObjectForCollidable(kHit.m_pvCollidable);
        RefL8* pkRef = TESObjectREFR_FindReferenceFor3D(pvCollidable);
        if (pvCollidable)
        {
            if (pkRef == pkTarget || pkRef == g_pkPlayerL8)
                continue;
            else
                return false;
        }
    }
    return true;
}
