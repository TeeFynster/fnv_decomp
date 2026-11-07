#include <xmmintrin.h>
typedef ::__m128 LocalM128;
// src/staging/blk_00d20000_od_o2_nood_variant_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 SP1 and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/staging/blk_00d20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
#include "../../include/hkVector4.h"
#include "../../include/hkpCollisionDispatcher.h"
struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};
bool Object_ProcessEntries_00d28560(void* unused, char** items, int count, int offset);
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}
static inline FinishingFlag NotFinishing()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    return flag;
}
class S00d2c8a0_Base
{
  public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class S00d2c8a0_Derived : public S00d2c8a0_Base
{
  public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag)
    {}
    virtual void vf04();
    LocalM128 m_kScaleFactors;
};
const void* __cdecl Object_GetConstructedVirtualTable();
struct SortPair
{
    unsigned int key;
    unsigned int val;
};
// @fnv 0x00d36520
// src: GUESS 0x00d36520 (confidence: low)
extern "C" void Object_ProcessEntries_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;)
    {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do
        {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val))
            {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val))
            {
                --j;
            }
            if (j < i)
            {
                break;
            }
            if (j != i)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j)
        {
            Object_ProcessEntries_00d36520(arr, lo, j, extra);
        }
        if (i >= hi)
        {
            break;
        }
        lo = i;
    }
}
void __cdecl hkpCollectionAgent3_initAgentFunc(hkpCollisionDispatcher::Agent3FunctionTable& kFuncs);
void __cdecl hkpCollectionAgent3_registerAgent3(hkpCollisionDispatcher* pkDispatcher);
void InitOutputDefaults();
void Runtime_ReleaseHandles_Thunk();
void ReleaseHandles();
void RemoveKeyFromTable();
void InsertIntoSlotArray();
void nullsub_15();
void hkCollideCapsuleUtilCapsVsTri_ProcessEntries_00d39150();
void hkCapsuleTriangleAgent3_process();
void __cdecl hkCapsuleTriangleAgent3_registerAgent3(hkpCollisionDispatcher* pkDispatcher);
extern "C"
{
using ::_mm_set_ps1;
using ::_mm_add_ps;
using ::_mm_sub_ps;
using ::_mm_store_ps;
}
extern "C" double fabs(double);
struct ClosestPointResult
{
    float distSq;
    float s;
    float t;
    float unk0C;
    LocalM128 p1;
    LocalM128 p2;
};
static __forceinline void Dot3(float& result, LocalM128 u, LocalM128 v)
{
    LocalM128 m = _mm_mul_ps(u, v);
    LocalM128 y = _mm_shuffle_ps(m, m, 0x55);
    LocalM128 z = _mm_shuffle_ps(m, m, 0xaa);
    _mm_store_ss(&result, _mm_add_ss(z, _mm_add_ss(y, m)));
}
int hkLineSegmentUtil_closestPointInfLineInfLine(const LocalM128* pa, const LocalM128* pb, const LocalM128* pc, const LocalM128* pd, ClosestPointResult* out);
using ::_mm_store_ps;
using ::_mm_xor_ps;
extern float DAT_0104da48;
extern LocalM128 DAT_010c44d0;
extern char DAT_010ce80c;
struct __declspec(align(16)) D2fInput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    hkVector4 m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};
struct D2fRayHitCollector
{
    virtual void CollectRayHit(const void* a, const void* b) = 0;
    float m_fHitDistance;
    D2fRayHitCollector() throw() : m_fHitDistance(DAT_0104da48)
    {}
};
struct __declspec(align(16)) D2fCollector : D2fRayHitCollector
{
    hkVector4 m_vec;
    void* m_user;

    D2fCollector(const hkVector4& v, void* user) throw() : m_vec(v), m_user(user)
    {}
    virtual void CollectRayHit(const void* a, const void* b);
};
struct D2fWorld
{
    void hkpBvTreeAgent_linearCast(int a, int b, D2fInput* in, D2fCollector* c1, D2fCollector* c2);
    void CopyData_00d2f460(int a1, int a2, const D2fInput* a3, int a4, void* a5);
};

namespace N {
typedef ::__m128 LocalM128;
extern "C"
{
}
}

struct S00d2c960_Info
{
    float unk00;
    float unk04;
    float m_fTime;
};

class S00d2c960_Motion
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58(float fTime, void* pTarget, const N::LocalM128* pPosition);
};

class S00d2c960_Body
{
  public:
    void activate_00c9c1d0();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    S00d2c960_Motion m_kMotion;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    N::LocalM128 m_kPathOffset;
};

class FUN_00d2c960_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    S00d2c960_Body* m_pkBody;
    unsigned int unk1C;
    unsigned int m_kRoomNode;

    void hkLiquidAction_applyAction(const S00d2c960_Info* pkInfo);
};

// @fnv 0x00d2c960
// src: XBOX_PDB 0x00d2c960
void FUN_00d2c960_cls::hkLiquidAction_applyAction(const S00d2c960_Info* pkInfo)
{
    float fTime = pkInfo->m_fTime;
    S00d2c960_Body* pkBody = m_pkBody;
    N::LocalM128 kPosition = pkBody->m_kPathOffset;
    pkBody->activate_00c9c1d0();
    pkBody->m_kMotion.vf58(fTime, &m_kRoomNode, &kPosition);
}
