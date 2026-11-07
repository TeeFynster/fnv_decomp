// src/staging/blk_00d20000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d20000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


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
    __m128 m_kScaleFactors;
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
    __m128 _mm_set_ps1(float a);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    void _mm_store_ps(float* p, __m128 a);
}
extern "C" double fabs(double);
struct ClosestPointResult
{
    float distSq;
    float s;
    float t;
    float unk0C;
    __m128 p1;
    __m128 p2;
};
static __forceinline void Dot3(float& result, __m128 u, __m128 v)
{
    __m128 m = _mm_mul_ps(u, v);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    _mm_store_ss(&result, _mm_add_ss(z, _mm_add_ss(y, m)));
}
int hkLineSegmentUtil_closestPointInfLineInfLine(const __m128* pa, const __m128* pb, const __m128* pc, const __m128* pd, ClosestPointResult* out);

namespace MoppSimd {
// Exe 0x00d2f0d0 FUN_00d2f0d0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ps1(const float*);

    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern float DAT_01016248;
extern MoppSimd::LocalM128 DAT_010ec7f0;
extern char DAT_010ce8e8[];
extern char DAT_010c41f8[];

struct MoppCastProfRec
{
    const char* name;
    unsigned long tick;
    unsigned long unk08;
};
struct MoppCastProfBuf
{
    unsigned long unk00;
    MoppCastProfRec* cur;
    unsigned long unk08;
    MoppCastProfRec* end;
};
struct MoppCastMatrix
{
    hkVector4 col0, col1, col2, translation;
    void hkTransform_setMulInverseMul(const MoppCastMatrix*, const MoppCastMatrix*);
};
struct MoppCastBounds
{
    hkVector4 min, max;
};
struct MoppCastInner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Eval(const MoppCastMatrix*, float, MoppCastBounds*);
};
struct MoppCastBody
{
    MoppCastInner* shape;
    int unk04;
    MoppCastMatrix* transform;
};
struct MoppCastInput
{
    void* unk00;
    int unk04;
    float tolerance;
    int unk0c;
    MoppCastMatrix transform;
    hkVector4 direction;
};
struct MoppCastQuery
{
    hkVector4 start, end, radius;
    MoppCastInput* input;
    MoppCastBody* a;
    MoppCastBody* b;
    int unk3c;
};
struct MoppCastCollector
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    MoppCastInner* shape;
    float inverse;
    void* unk18;
    float unk1c;
    float unk20;
    int d, e;
    MoppCastQuery* query;
    int unk30;
    void ProcessAndReturnValue_00da8180(MoppCastQuery*, int, int);
};
static void ProfMark(const char* name)
{
    MoppCastProfBuf* buf = (MoppCastProfBuf*)TlsGetValue(DAT_0126835c);
    if (buf->cur < buf->end)
    {
        MoppCastProfRec* rec = buf->cur;
        rec->name = name;
        _ReadWriteBarrier();
        volatile unsigned long tick = (unsigned long)__rdtsc();
        rec->tick = tick;
        buf->cur = rec + 1;
    }
}
struct MoppCastCastGeometry
{
    MoppCastBounds bounds;
    MoppCastQuery query;
    hkVector4 direction;
    int unk70;
    int unk74;
    int unk78;
    MoppCastCollector collector;
    MoppCastMatrix relative;
};
// @fnv 0x00d2f0d0
// src: GUESS 0x00d2f0d0 (confidence: low)
void __cdecl hkTransform_setMulInverseMul_ComputeValues_00d2f0d0(MoppCastBody* a, MoppCastBody* b, MoppCastInput* c, int d, int e)
{
    ProfMark(DAT_010ce8e8);
    // Preserve uninitialized scratch storage without vector constructors or a GS buffer.
    __declspec(align(16)) void* geometryStorage[sizeof(MoppCastCastGeometry) / sizeof(void*)];
    MoppCastCastGeometry& ls = *(MoppCastCastGeometry*)geometryStorage;
    ls.relative.hkTransform_setMulInverseMul(b->transform, a->transform);

    a->shape->Eval(&ls.relative, c->tolerance, &ls.bounds);

    ls.direction.hkVector4_setRotatedInverseDir(*(const hkRotation*)b->transform, c->direction);

    float tolerance = c->tolerance;
    MoppSimd::LocalM128 scalarHalf = MoppSimd::_mm_load_ss(&DAT_01016248);
    MoppSimd::LocalM128 half = MoppSimd::_mm_shuffle_ps(MoppSimd::_mm_load_ss(&DAT_01016248), scalarHalf, 0);
    (MoppSimd::LocalM128&)ls.query.start = MoppSimd::_mm_add_ps(
        MoppSimd::_mm_mul_ps(MoppSimd::_mm_sub_ps(DAT_010ec7f0, half), (MoppSimd::LocalM128&)ls.bounds.min),
        MoppSimd::_mm_mul_ps(half, (MoppSimd::LocalM128&)ls.bounds.max));
    (MoppSimd::LocalM128&)ls.query.end =
        MoppSimd::_mm_add_ps((MoppSimd::LocalM128&)ls.direction.m_vComponents, (MoppSimd::LocalM128&)ls.query.start);
    MoppSimd::LocalM128 radius = MoppSimd::_mm_add_ps(
        MoppSimd::_mm_mul_ps(MoppSimd::_mm_shuffle_ps(scalarHalf, scalarHalf, 0),
                             MoppSimd::_mm_sub_ps((MoppSimd::LocalM128&)ls.bounds.max, (MoppSimd::LocalM128&)ls.bounds.min)),
        MoppSimd::_mm_shuffle_ps(MoppSimd::_mm_load_ss(&tolerance), MoppSimd::_mm_load_ss(&tolerance), 0));
    ls.query.a = a;
    ls.query.b = b;
    (MoppSimd::LocalM128&)ls.query.radius = radius;
    ls.query.input = c;
    ls.collector.ProcessAndReturnValue_00da8180(&ls.query, d, e);
    ProfMark(DAT_010c41f8);
}
