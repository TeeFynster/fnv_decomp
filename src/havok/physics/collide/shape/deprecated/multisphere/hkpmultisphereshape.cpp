#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/shape/deprecated/multisphere/hkpmultisphereshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/multisphere/hkpmultisphereshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the float-only SIMD representation used by this unit: MSVC 2008
// treats the CRT's byte-array SIMD members as /GS buffers.
#define _INCLUDED_MM2
// Exe 0x00d2a7c0 FUN_00d2a7c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkpMultiSphereShape.h"
#include "../../../../../../../include/hkMotionState.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpRayHitCollector.h"

extern "C" LocalM128 _mm_set_ps(float, float, float, float);
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" LocalM128 _mm_move_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);

class FnvShapeGetter : public hkpSphereRepShape
{
  public:
    int unk10;
    int GetUnk10();
};

// @fnv 0x00d2a5f0
// src: GUESS 0x00d2a5f0 (confidence: low)
int FnvShapeGetter::GetUnk10()
{
    return unk10;
}

extern const hkClass g_01268910;

// @fnv 0x00d2a600
void hkpMultiSphereShape::calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const
{
    hkReferencedObject::calcContentStatistics(pkCollector, &g_01268910);
}

extern int DAT_010ce4bc;

struct FUN_00d2a760
{
    void* m_ppVirtualMethodTable;
    short unk04;
    short m_iObjectReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1C;
    LocalM128 m_kSpheres[8];

    FUN_00d2a760(const hkVector4* spheres, int count);
};

// @fnv 0x00d2a760
FUN_00d2a760::FUN_00d2a760(const hkVector4* spheres, int count)
{
    m_iObjectReferenceCount = 1;
    m_ulUserData = 0;
    m_type = 0x15;
    m_ppVirtualMethodTable = &DAT_010ce4bc;
    for (int i = 0; i < count; ++i)
        *(LocalM128*)&m_kSpheres[i] = *(const LocalM128*)&spheres[i];
    m_iSphereCount = count;
}

extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) Ray
{

    LocalM128 from;

    LocalM128 to;
};

struct __declspec(align(16)) Out
{

    LocalM128 normal;

    float fraction;

    int sphereId;

    int unk18;

    int unk1C;

    int keys[8];

    int keyIndex;
};

struct __declspec(align(16)) Sph
{

    float x, y, z, w;
};

extern LocalM128 DAT_010ec7f0;

// Finds the smallest fraction in fracs, writes the interpolated and scaled normal and sphere id into out, and returns the best index or -1.
// @fnv 0x00d2a610
// src: XBOX_PDB 0x00d2a610
static __declspec(noinline) int getBestHit(Out* out, const Sph* spheres, const float* fracs, const int* ids,
                                             int count, const Ray* ray)

{

    float best = out->fraction;

    int bestIdx = -1;

    int i = 0;

    for (; i < count; ++i)
    {

        if (fracs[i] < best)
        {

            best = fracs[i];

            bestIdx = i;
        }
    }

    if (bestIdx != -1)
    {

        out->keys[out->keyIndex] = -1;

        int id = ids[bestIdx];

        out->fraction = best;

        const Sph* base = spheres;

        LocalM128 t = _mm_load_ss(&best);
        t = _mm_shuffle_ps(t, t, 0);

        LocalM128 one = DAT_010ec7f0;

        LocalM128 center = _mm_load_ps(&base[id].x);

        LocalM128 n = _mm_add_ps(

            _mm_mul_ps(_mm_sub_ps(ray->from, center), _mm_sub_ps(one, t)),

            _mm_mul_ps(_mm_sub_ps(ray->to, center), t));

        out->normal = n;

        float invR = 1.0f / base[id].w;

        LocalM128 inv = _mm_load_ss(&invR);

        LocalM128 scaled = _mm_mul_ps(n, _mm_shuffle_ps(inv, inv, 0));

        out->normal = scaled;

        out->sphereId = id;

        return bestIdx;
    }

    return bestIdx;
}

extern "C" Out* d2a610_out();

extern "C" Sph* d2a610_sph();

extern "C" float* d2a610_fracs();

extern "C" int* d2a610_ids();

extern "C" int d2a610_count();

extern "C" Ray* d2a610_ray();

extern "C" void d2a610_sink(int);

void d2a610_caller()

{

    int r = getBestHit(d2a610_out(), d2a610_sph(), d2a610_fracs(), d2a610_ids(), d2a610_count(), d2a610_ray());

    d2a610_sink(r);
}

struct FUN_00d2a920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iSphereCount;
    char pad14[0xC];
    hkVector4 m_kSpheres[8];
    hkVector4* CopySpheres(hkVector4* dst);
};

// Copies m_iSphereCount hkVector4 entries from m_kSpheres into dst using 128-bit moves and returns dst.
// @fnv 0x00d2a920
hkVector4* FUN_00d2a920::CopySpheres(hkVector4* dst)
{

    for (int i = 0; i < m_iSphereCount; ++i)
    {
        *reinterpret_cast<LocalM128*>(dst + i) = *reinterpret_cast<LocalM128*>(m_kSpheres + i);
    }
    return dst;
}

struct RayCtx
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

class S00d2ab90_Shape : public hkpSphereRepShape
{
  public:
    void* m_disp;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kSpheres[8];
    char* hkpMultiSphereShape_castRayImpl(char* ok, RayCtx* in, void* p3);
};

#include <math.h>

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern const char str_010ce4f0[];
extern const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
struct Sph_Mon
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct Sph_V
{
    float x, y, z, w;
};
struct Sph_Seg
{
    Sph_V a;
    Sph_V b;
};
union Sph_U
{
    Sph_V v;
    LocalM128 q;
};

static inline LocalM128 Sph_sum3(LocalM128 t)
{
    return _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
}

// Finds all spheres in an array that the segment intersects, storing their indices and normalized hit parameters, and returns the count.
// @fnv 0x00d2a960
// src: XBOX_PDB 0x00d2a960
static __declspec(noinline) int castRayInternal(const Sph_Seg* seg, const Sph_V* spheres, int n, int* apHitIndices,
                                             float* apHitParams)
{
    union
    {
        int count;
        volatile unsigned int tick;
    } hitCounter;
    {
        Sph_Mon* m = (Sph_Mon*)TlsGetValue(DAT_0126835c);
        char* p = m->cur;
        if (p < m->end)
        {
            *(const char**)p = str_010ce4f0;
            _ReadWriteBarrier();
            hitCounter.tick = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = hitCounter.tick;
            m->cur = p + 12;
        }
    }
    union
    {
        float A;
        volatile unsigned int tick;
    } scratch;
    hitCounter.count = 0;
    for (int i = 0; i < n; i++)
    {
        Sph_U e, s, c;
        e.v = seg->b;
        s.v = seg->a;
        c.q = *(const LocalM128*)&spheres[i];
        LocalM128 d2 = _mm_sub_ps(e.q, c.q);
        s.q = _mm_sub_ps(s.q, c.q);
        c.q = _mm_mul_ps(s.q, s.q);
        LocalM128 d1 = _mm_sub_ps(d2, s.q);
        float C;
        _mm_store_ss(&C, Sph_sum3(c.q));
        float B;
        _mm_store_ss(&B, Sph_sum3(_mm_mul_ps(d1, s.q)));
        float B2 = B + B;
        if (B2 >= 0.0f)
            continue;
        _mm_store_ss(&scratch.A, Sph_sum3(_mm_mul_ps(d1, d1)));
        float q = spheres[i].w * spheres[i].w;
        float cc = C - q;
        float disc = B2 * B2 - cc * (scratch.A * 4.0f);
        if (disc <= 0.0f)
            continue;
        float sq = (float)sqrt(disc);
        float tn = -B2 - sq;
        float t = tn * 0.5f;
        if (t >= scratch.A)
            continue;
        if (t < 0.0f)
            continue;
        apHitParams[hitCounter.count] = t / scratch.A;
        apHitIndices[hitCounter.count] = i;
        hitCounter.count++;
    }
    {
        Sph_Mon* m = (Sph_Mon*)TlsGetValue(DAT_0126835c);
        char* p = m->cur;
        if (p < m->end)
        {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            scratch.tick = (unsigned int)__rdtsc();
            *(unsigned int*)(p + 4) = scratch.tick;
            m->cur = p + 12;
        }
    }
    return hitCounter.count;
}

// Performs a raycast against m_kSpheres using in and p3, storing whether a hit was found in *ok and returning ok.
// @fnv 0x00d2ab90
// src: XBOX_PDB 0x00d2ab90
char* S00d2ab90_Shape::hkpMultiSphereShape_castRayImpl(char* ok, RayCtx* in, void* p3)
{
    int hitKeys[8];
    float hitFractions[8];
    int numHits = castRayInternal((const Sph_Seg*)in, (const Sph_V*)m_kSpheres, (int)m_disp,
                                 hitKeys, hitFractions);
    int hitIndex = getBestHit((Out*)p3, (const Sph*)m_kSpheres, hitFractions, hitKeys,
                                  numHits, (const Ray*)in);
    *ok = (hitIndex != -1);
    return ok;
}

int Sph_caller(const Sph_Seg* seg, const Sph_V* spheres, int n, int* a, float* b)
{
    return castRayInternal(seg, spheres, n, a, b);
}

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkReal m_rayEnforcement;
    hkUint32 m_uiFilterInfo;
};

struct ShapeRayCastOutput
{
    LocalM128 m_vComponents;
    hkReal m_fHitFraction;
    int m_iExtraInfo;
    int unk18[2];
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    ShapeRayCastOutput()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeyIndex = 0;
        m_uiShapeKeys[0] = 0xFFFFFFFFu;
    }

    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xFFFFFFFFu;
        m_uiShapeKeyIndex = 0;
    }
};

// Pack unit supplies static noinline overloads for both helpers:
// a960 Sph_Seg form puts the hitKeys (int*) param in EAX;
// a610 Out-first form puts the out param in EDI.

struct DummyMultiSphere : hkpMultiSphereShape
{
    void hkpMultiSphereShape_castRayWithCollectorImpl(const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Ray-casts against the multi-sphere shape, transforms each hit normal into world space, and reports hits to the collector.
// @fnv 0x00d2abe0
// src: XBOX_PDB 0x00d2abe0
void DummyMultiSphere::hkpMultiSphereShape_castRayWithCollectorImpl(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                    hkpRayHitCollector& collector) const
{
    hkReal hitFractions[8];
    hkUint32 hitKeys[8];
    const hkVector4* spheres = m_kSpheres;

    int numHits =
        castRayInternal((const Sph_Seg*)&input, (const Sph_V*)spheres, m_iSphereCount, (int*)hitKeys, hitFractions);

    ShapeRayCastOutput output;
    if (numHits == 0)
    {
        return;
    }

    do
    {
        output.reset();

        int hitIndex = getBestHit((Out*)&output, (const Sph*)spheres, hitFractions, (const int*)hitKeys, numHits,
                                    (const Ray*)&input);

        const hkTransform& transform = static_cast<const hkMotionState*>(cdBody.m_pMotionState)->m_kMotionTransform;

        LocalM128 v = output.m_vComponents;
        LocalM128 v0 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), transform.m_row1);
        LocalM128 v1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), transform.m_row0);
        LocalM128 v2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), transform.m_row2);
        v0 = _mm_add_ps(v0, v1);
        output.m_vComponents = _mm_add_ps(v0, v2);

        collector.CollectRayHit(cdBody, reinterpret_cast<const RayCastHitResult&>(output));

        numHits--;
        hitFractions[hitIndex] = hitFractions[numHits];
        hitKeys[hitIndex] = hitKeys[numHits];
    } while (numHits != 0);
}

extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
inline Vec4::Vec4(const Vec4& q) : xb(q.xb), yb(q.yb), zb(q.zb), wb(q.wb) {}

inline LocalM128 Vec4::get() const
{
    return *reinterpret_cast<const LocalM128*>(this);
}

inline void Vec4::set(LocalM128 v)
{
    *reinterpret_cast<LocalM128*>(this) = v;
}

struct hkTransformSimd
{
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
    Vec4 m_vTranslation;
};

struct hkAabbSimd
{
    Vec4 m_kMinimumCorner;
    Vec4 m_kMaximumCorner;
};

static __forceinline void TransformPointArray(const hkTransformSimd& t, const Vec4* vin, int num, LocalM128* vout)
{
    __declspec(align(16)) Vec4 c0 = t.m_kColumn0;
    __declspec(align(16)) Vec4 c1 = t.m_kColumn1;
    __declspec(align(16)) Vec4 c2 = t.m_kColumn2;
    __declspec(align(16)) Vec4 c3 = t.m_vTranslation;
    LocalM128 q0 = c0.get();
    LocalM128 q1 = c1.get();
    LocalM128 q2 = c2.get();
    LocalM128 RunFourthVirtual = c3.get();
    int i = num - 1;
    do
    {
        LocalM128 b = vin[i].get();
        LocalM128 xb = _mm_shuffle_ps(b, b, 0);
        LocalM128 yb = _mm_shuffle_ps(b, b, 0x55);
        LocalM128 zb = _mm_shuffle_ps(b, b, 0xAA);
        LocalM128 t0 = _mm_mul_ps(xb, q0);
        LocalM128 t1 = _mm_mul_ps(yb, q1);
        LocalM128 t2 = _mm_mul_ps(zb, q2);
        vout[i] = _mm_add_ps(_mm_add_ps(t0, t1), _mm_add_ps(t2, RunFourthVirtual));
    } while (--i >= 0);
}

extern float DAT_0104da48;
extern float DAT_0104e148;

struct MultiSphereShape
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iSphereCount;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kSpheres[8];

    void hkpMultiSphereShape_getAabbImpl(const hkTransformSimd& localToWorld, float tolerance, hkAabbSimd& out) const;
};

// Transforms the sphere centers by localToWorld, expands by each radius, and writes the min/max corners, widened by tolerance, into out.
// @fnv 0x00d2a7c0
// src: XBOX_PDB 0x00d2a7c0
void MultiSphereShape::hkpMultiSphereShape_getAabbImpl(const hkTransformSimd& localToWorld, float tolerance, hkAabbSimd& out) const
{
    LocalM128 tmp[8];
    TransformPointArray(localToWorld, m_kSpheres, m_iSphereCount, tmp);

    LocalM128 absMin = _mm_set_ps1(DAT_0104da48);
    LocalM128 absMax = _mm_set_ps1(DAT_0104e148);

    for (int i = 0; i < m_iSphereCount; i++)
    {
        LocalM128 r = _mm_shuffle_ps(m_kSpheres[i].get(), m_kSpheres[i].get(), 0xFF);
        LocalM128 mn = _mm_sub_ps(tmp[i], r);
        LocalM128 mx = _mm_add_ps(tmp[i], r);
        absMin = _mm_min_ps(absMin, mn);
        absMax = _mm_max_ps(absMax, mx);
    }
    LocalM128 tol4 = _mm_set_ps1(tolerance);
    out.m_kMinimumCorner.set(_mm_sub_ps(absMin, tol4));
    out.m_kMaximumCorner.set(_mm_add_ps(tol4, absMax));
}
