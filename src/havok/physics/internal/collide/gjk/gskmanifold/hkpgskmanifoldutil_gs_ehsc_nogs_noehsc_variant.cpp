#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkVector4.h"

__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline const __m128& hkSimdReal::getQuad() const
{
    return m_vValue;
}

class Vector4Comparison
{
  public:
    enum Mask
    {
        MASK_XY = 3
    };
    __forceinline int anyIsSet(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
    __m128 m_uiMask;
};


__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& v0, const hkVector4& v1)
{
    __m128 cross0;
    cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
    __m128 cross1;
    cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline void hkVector4::setInterpolate4(const hkVector4& v0, const hkVector4& v1, const hkSimdReal& _t)
{
    static __declspec(align(16)) const float cw[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    __m128 t = _t.broadcast();
    __m128 s = _mm_sub_ps(*(const __m128*)&cw, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
}
__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}
__forceinline Vector4Comparison hkVector4::compareLessThanZero4() const
{
    hkVector4 zero;
    zero.m_vComponents = _mm_setzero_ps();
    Vector4Comparison m;
    m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
    return m;
}
__forceinline hkSimdReal hkVector4::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return m_vComponents;
    case 1:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    case 2:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    default:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    }
}
__forceinline float& hkVector4::operator()(int a)
{
    return reinterpret_cast<float*>(&m_vComponents)[a];
}

struct S_00dad640_Entry
{
    unsigned short unk0;
    unsigned short id;
    unsigned int unk4;
};
struct S_00dad640_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[1];
};
struct S_00dad640_Target
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void Release(unsigned short id, void* arg);
};
void ReleaseAllEntries(S_00dad640_Set* set, S_00dad640_Target* target, void* arg);
struct S_00dad4d0_Key
{
    unsigned short ids[4];
    unsigned char numA;
    unsigned char numB;
};
struct S_00dad4d0_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dad4d0_Raw
{
    unsigned int lo;
    unsigned int hi;
};
struct S_00dad4d0_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad4d0_Entry entries[1];

    unsigned short Id(unsigned char off)
    {
        return *(unsigned short*)((char*)&entries[count] + (off >> 3));
    }
};
bool FindAndPromoteEntry(S_00dad4d0_Set* set, S_00dad4d0_Key* key);
void __fastcall hkGskManifold_garbageCollect(int unused, S_00dad640_Set* set);
void __cdecl _hkGskManifold_removePoint(S_00dad640_Set* set, unsigned int index);

#include <xmmintrin.h>
extern float DAT_0104da48;

static __forceinline void storeLengthSquared3(const hkVector4& vector, float& f)
{
    __m128 v = vector.m_vComponents;
    __m128 x2 = _mm_mul_ps(v, v);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    _mm_store_ss(&f, r);
}

struct S_00daee00_Point
{
    hkVector4 pos;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
};

struct S_00daee00
{
    S_00daee00_Point points[5];
    int hkGskManifold_findRedundant5thPoint();
};

// @fnv 0x00daee00
// src: COMMUNITY 0x00daee00
int S_00daee00::hkGskManifold_findRedundant5thPoint()
{
    // The fallback phase reuses the completed geometric reduction scratch.
    float maxDist = 0.0f;
    float minDist = DAT_0104da48;
    float distance;
    float dr;
    struct PointSelection
    {
        float dists[4];
        int used[5];
    } ls;
    int* used = ls.used;
    float* dists = ls.dists;
    for (int k = 0; k < 5; k++)
        used[k] = 0;
    int farIdx = 0;
    int nearIdx = 0;

    for (int i = 0; i < 4; i++)
    {
        hkVector4 diff;
        diff.setSub4(points[4].pos, points[i].pos);
        storeLengthSquared3(diff, distance);
        float d = distance;
        dists[i] = d;
        if (maxDist < d)
        {
            maxDist = d;
            farIdx = i;
        }
        if (d < minDist)
        {
            minDist = d;
            nearIdx = i;
        }
    }
    dr = points[4].unk1C - points[nearIdx].unk1C;
    used[farIdx] = 1;

    int idx2 = 4;
    const hkVector4& farPos = points[farIdx].pos;
    maxDist *= 1.05f;
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            hkVector4 diff;
            diff.setSub4(points[farIdx].pos, points[i].pos);
            storeLengthSquared3(diff, distance);
            float d = distance;
            if (d > maxDist)
            {
                maxDist = d;
                idx2 = i;
            }
        }
    }
    used[idx2] = 1;

    int idx3 = 0;
    hkVector4 edge;
    edge.setSub4(farPos, points[idx2].pos);
    float maxDist3 = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            hkVector4 diff;
            diff.setSub4(points[i].pos, farPos);
            hkVector4 cross;
            cross.setCross(diff, edge);
            storeLengthSquared3(cross, distance);
            float d = distance;
            if (d > maxDist3)
            {
                maxDist3 = d;
                idx3 = i;
            }
        }
    }
    used[idx3] = 1;

    int idx4 = 0;
    const hkVector4& thirdPos = points[idx3].pos;
    maxDist3 = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            hkVector4 diff;
            diff.setSub4(thirdPos, points[i].pos);
            storeLengthSquared3(diff, distance);
            float d = distance;
            if (d > maxDist3)
            {
                maxDist3 = d;
                idx4 = i;
            }
        }
    }
    used[idx4] = 1;

    if (!used[4] && dr < 0.0f && minDist < 526.0 * dr * dr)
    {
        maxDist = 0.030461745f;
        int result = 4;
        float base = points[4].unk1C;
        for (int i = 0; i < 4; i++)
        {
            minDist = points[i].unk1C - base;
            dr = minDist * minDist;
            minDist = dr + 1e-9f;
            if (minDist > dists[i] * maxDist)
            {
                maxDist = minDist / (dists[i] + 1e-9f);
                result = i;
            }
        }
        return result;
    }

    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            return i;
        }
    }
    return 0;
}

struct S_00dad720_Vec
{
    __m128 m_afExtents[16];
    __m128 m_v100;
    int unk110;
    int unk114;
    int unk118;
    float m_pFreeList;
};

struct S_00dad720_Out
{
    __m128 m_v0;
    __m128 m_v10;
    __m128 m_v20;
};

struct S_00dad720_Rec
{
    int unk0;
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_iThirdValue;
};

extern const __m128 DAT_010ec7f0;

static __forceinline __m128 Cross3(const __m128& a, const __m128& b)
{
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(t1, t0);
}

static __forceinline __m128 Dot3_3vs3(const __m128& a0, const __m128& b0, const __m128& a1, const __m128& b1,
                                      const __m128& a2, const __m128& b2)
{
    __m128 m0 = _mm_mul_ps(a0, b0);
    __m128 m1 = _mm_mul_ps(a1, b1);
    __m128 m2 = _mm_mul_ps(a2, b2);
    __m128 tmp = _mm_unpacklo_ps(m0, m1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m0, m1), m2, 0xe4);
    m0 = _mm_movelh_ps(tmp, m2);
    m1 = _mm_shuffle_ps(_mm_movehl_ps(m0, tmp), m2, 0xd4);
    m2 = ctmp;
    return _mm_add_ps(_mm_add_ps(m0, m1), m2);
}

// @fnv 0x00dad720
// src: GUESS 0x00dad720 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00dad720(S_00dad720_Rec* rec, S_00dad720_Vec* vecs, S_00dad720_Out* out)
{
    const __m128& pa = *(__m128*)((char*)vecs + rec->m_kPointA);
    const __m128& pb = *(__m128*)((char*)vecs + rec->m_kPointB);
    const __m128& pc = *(__m128*)((char*)vecs + rec->m_iThirdValue);
    out->m_v0 = pa;
    out->m_v20 = vecs->m_v100;
    const __m128& b = pb;
    const __m128& c = pc;
    const __m128& a = pa;
    __m128 e1 = _mm_sub_ps(c, b);
    __m128 e0 = _mm_sub_ps(c, a);
    __m128 n = Cross3(e0, e1);
    __m128 dots = Dot3_3vs3(e0, e1, _mm_sub_ps(a, b), e1, n, n);
    __declspec(align(16)) float d[4];
    _mm_store_ps(d, dots);
    __m128 sq = _mm_mul_ps(e1, e1);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float lenSq;
    _mm_store_ss(&lenSq, s);
    if (!(d[3] > vecs->m_pFreeList * lenSq) && !(_mm_movemask_ps(_mm_cmplt_ps(dots, _mm_setzero_ps())) & 3))
    {
        __m128 sum = _mm_add_ss(dots, _mm_shuffle_ps(dots, dots, 0x55));
        __m128 t = _mm_div_ss(dots, sum);
        t = _mm_shuffle_ps(t, t, 0);
        __m128 p = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), b), _mm_mul_ps(c, t));
        out->m_v10 = _mm_sub_ps(a, p);
        return 0;
    }
    return 1;
}
volatile int g_rec;
volatile int g_vecs;
volatile int g_out;
volatile int g_res;
void CallTarget_dad720()
{
    S_00dad720_Out* o = (S_00dad720_Out*)g_out;
    g_res = Object_ProcessAndReturnValue_00dad720((S_00dad720_Rec*)g_rec, (S_00dad720_Vec*)g_vecs, o);
}

#include <xmmintrin.h>
#include "../../../../../../../include/hkPadSpu.h"   // Havok 7.1 hkPadSpu (was a unit-local ValueWrapper copy)
namespace fnv_00dad860 {

typedef float hkReal;
typedef __m128 hkQuadReal;


typedef const hkSimdReal& hkSimdRealParameter;

__forceinline hkSimdReal operator+(hkSimdRealParameter r, hkSimdRealParameter s)
{
    return _mm_add_ss(r.getQuad(), s.getQuad());
}
__forceinline hkSimdReal operator/(hkSimdRealParameter r, hkSimdRealParameter s)
{
    return _mm_div_ss(r.getQuad(), s.getQuad());
}




namespace hkVector4Util_S {
__forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
    register hkQuadReal c0 = _mm_mul_ps(a0.m_vComponents, b0.m_vComponents);
    register hkQuadReal c1 = _mm_mul_ps(a1.m_vComponents, b1.m_vComponents);
    register hkQuadReal c2 = _mm_mul_ps(a2.m_vComponents, b2.m_vComponents);
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, _MM_SHUFFLE(3, 1, 1, 0));
        c2 = _ctmp;
    }
    dotsOut.m_vComponents = _mm_add_ps(_mm_add_ps(c0, c1), c2);
}
}


struct MeshVertexBasisData
{
    hkVector4 m_pMeshVertexBuffer[16];
    hkVector4 m_kFirstBasisVector;
    hkPadSpu<hkReal> m_kBoxBasisVector;
    hkPadSpu<hkReal> m_kThirdBasisVector;
    hkPadSpu<hkReal> m_kFourthBasisVector;
    hkPadSpu<hkReal> m_fMinimumCollisionSeparation;
    __forceinline const hkVector4& getVertexA(unsigned int offset) const
    {
        return *(const hkVector4*)((const char*)this + offset);
    }
    __forceinline const hkVector4& getVertexB(unsigned int offset) const
    {
        return *(const hkVector4*)((const char*)this + offset);
    }
};

struct AlignedPairData
{
    unsigned short m_ucDimensionA;
    unsigned short m_ucDimensionB;
    unsigned char m_vert0;
    unsigned char m_vert1;
    unsigned char m_vert2;
};

struct TriangleClosestPointInfo
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 m_kTriangleNormal;
};

// @fnv 0x00dad860
// src: GUESS 0x00dad860 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00dad860(const MeshVertexBasisData& work, const AlignedPairData& point,
                                             TriangleClosestPointInfo& out)
{
    const hkVector4& a0 = work.getVertexA(point.m_vert0);
    const hkVector4& a1 = work.getVertexA(point.m_vert1);
    const hkVector4& b0 = work.getVertexB(point.m_vert2);

    out.m_kTriangleNormal = work.m_kFirstBasisVector;

    hkVector4 edge;
    edge.setSub4(a1, a0);
    hkVector4 d1;
    d1.setSub4(a1, b0);
    hkVector4 d0;
    d0.setSub4(b0, a0);
    hkVector4 cross;
    cross.setCross(edge, d1);

    hkVector4 dots;
    hkVector4Util_S::dot3_3vs3(d1, edge, d0, edge, cross, cross, dots);

    hkReal lenSq = edge.lengthSquared3();
    if (dots(3) > work.m_fMinimumCollisionSeparation * lenSq || dots.compareLessThanZero4().anyIsSet(Vector4Comparison::MASK_XY))
    {
        return 1;
    }
    hkSimdReal t = dots.getSimdAt(0) / (dots.getSimdAt(0) + dots.getSimdAt(1));
    out.m_vContactPosition.setInterpolate4(a1, a0, t);
    out.m_vHitNormal.setSub4(out.m_vContactPosition, b0);
    return 0;
}

const MeshVertexBasisData* volatile g_work;
const AlignedPairData* volatile g_point;
TriangleClosestPointInfo* volatile g_out;
int S00dad860_Call()
{
    return Object_ProcessAndReturnValue_00dad860(*g_work, *g_point, *g_out);
}
}  // namespace fnv_00dad860

struct S_00dae220_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dae220_Set
{
    unsigned char numA;
    unsigned char numB;
    unsigned char count;
    unsigned char unk3;
    S_00dae220_Entry entries[1];
};

// @fnv 0x00dae220
// src: COMMUNITY 0x00dae220
void __fastcall hkGskManifold_garbageCollect(int unused, S_00dae220_Set* set)
{
    __declspec(align(16)) unsigned char used[16];
    unsigned int remap[16];
    unsigned int i;

    _mm_store_ps((float*)used, _mm_setzero_ps());
    for (i = 0; i < set->count; i++)
    {
        S_00dae220_Entry* e = &set->entries[i];
        int n = e->numA + e->numB;
        used[e->offs[0] >> 4] = 1;
        used[e->offs[1] >> 4] = 1;
        if (n >= 3)
            used[e->offs[2] >> 4] = 1;
        if (n == 4)
            used[e->offs[3] >> 4] = 1;
    }

    unsigned short* ids = (unsigned short*)&set->entries[set->count];
    int total = set->numA + set->numB;
    int kept = 0;
    int j = 0;
    unsigned int off = 0;
    for (; j < total; j++)
    {
        remap[j] = off;
        if (used[j])
        {
            ids[kept] = ids[j];
            kept++;
            off += 16;
        }
    }

    unsigned char numA = (unsigned char)(remap[set->numA] >> 4);
    set->numA = numA;
    set->numB = (unsigned char)(kept - numA);

    for (i = 0; i < set->count; i++)
    {
        S_00dae220_Entry* e = &set->entries[i];
        e->offs[0] = (unsigned char)remap[e->offs[0] >> 4];
        e->offs[1] = (unsigned char)remap[e->offs[1] >> 4];
        e->offs[2] = (unsigned char)remap[e->offs[2] >> 4];
        e->offs[3] = (unsigned char)remap[e->offs[3] >> 4];
    }
}

extern "C" void _ReadWriteBarrier(void);

struct ContactManifold
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[4];
};

struct ContactRecord
{
    __m128 position;
    __m128 normal;
    unsigned id;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
};
struct ContactCache
{
    ContactRecord points[4];
    int hkGskManifold_findRedundant5thPoint();
};
struct ContactContext
{
    unsigned unk00;
    void* userData;
};
struct ContactManager
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned short add(void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                               ContactRecord* point);
    virtual void slot4();
    virtual void remove(unsigned short id, void* userData);
};

static inline void CopyContact(ContactRecord& destination, const ContactRecord& source)
{
    destination.position = source.position;
    destination.normal = source.normal;
    destination.id = source.id;
}

// Four contact entries are followed immediately by a variable-length vertex table.
// For smaller manifolds the table starts after the last live entry.
static inline unsigned short* VertexIds(ContactManifold* set)
{
    return reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + set->count * 8);
}
static inline S_00dad4d0_Entry& ContactEntry(ContactManifold* set, unsigned index)
{
    return *reinterpret_cast<S_00dad4d0_Entry*>(reinterpret_cast<char*>(set) + 4 + index * 8);
}

static void __fastcall hkGskManifold_garbageCollect(int, ContactManifold* set);

// @fnv 0x00daf1e0
// src: COMMUNITY 0x00daf1e0
int hkGskManifold_addPoint(ContactManifold* set, void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                 ContactRecord* point, ContactCache* cache, ContactManager* manager, int defer)
{
    int replaced = 4;
    unsigned short id;
    if (set->count == 4)
    {
        int index = cache->hkGskManifold_findRedundant5thPoint();
        if (index == 4)
            return 5;
        manager->remove(set->entries[index].id, context->userData);
        S_00dad640_Entry* added = &set->entries[index];
        if (index)
            *added = set->entries[0];
        else
            *added = set->entries[1];
        hkGskManifold_garbageCollect(index, set);
        id = manager->add(a, b, c, context, key, point);
        if (id == 0xffff)
        {
            set->entries[0] = set->entries[3];
            unsigned res = set->count;
            unsigned newCount = res - 1;
            set->count = static_cast<unsigned char>(newCount);
            volatile unsigned* destination =
                reinterpret_cast<unsigned*>(reinterpret_cast<char*>(set) + 4 + newCount * 8);
            const unsigned* source = reinterpret_cast<const unsigned*>(reinterpret_cast<char*>(set) + 4 + res * 8);
            for (int words = (set->unk0 + set->unk1 - 1) >> 1; words >= 0; --words)
                *destination++ = *source++;
            CopyContact(cache->points[index], cache->points[3]);
            return 6;
        }
        ContactRecord* fresh = *(ContactRecord* volatile*)&point;
        fresh->id = id;
        CopyContact(cache->points[index], *fresh);
        replaced = index;
    }
    else
    {
        if (defer && key->numB != 3)
        {
            id = 0xffff;
        }
        else
        {
            id = manager->add(a, b, c, context, key, point);
            if (id == 0xffff)
                return 5;
        }
        point->id = id;
        unsigned res = set->count;
        unsigned newCount = res + 1;
        int lastWord = (set->unk1 + set->unk0 - 1) >> 1;
        unsigned* destination = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(set) + 4 + newCount * 8) + lastWord;
        unsigned* source = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(set) + 4 + res * 8) + lastWord;
        for (; 0 <= lastWord; --lastWord)
            *destination-- = *source--;
        set->entries[res] = set->entries[0];
        set->count = static_cast<unsigned char>(newCount);
    }

    S_00dad4d0_Entry& entry = ContactEntry(set, 0);
    entry.numA = key->numA;
    entry.numB = key->numB;
    *reinterpret_cast<unsigned*>(entry.offs) = 0;
    *reinterpret_cast<unsigned short*>(&entry.unk2) = id;
    unsigned short* vertices = VertexIds(set);
    unsigned selected = 0;
    for (int i = 0; i < key->numA; ++i)
    {
        unsigned index = 0;
        unsigned short vertex = key->ids[i];
        while (index < set->unk0)
        {
            if (vertices[index] == vertex)
                goto foundA;
            ++index;
        }
        {
            unsigned end = set->unk0 + set->unk1;
            while (end > index)
            {
                vertices[end] = vertices[end - 1];
                --end;
            }
            vertices[index] = vertex;
            ++set->unk0;
            _ReadWriteBarrier();
            selected += 0x10;
        }
    foundA:
        entry.offs[i] = static_cast<unsigned char>(index << 4);
    }
    {
        if (selected)
        {
            S_00dad4d0_Entry* previous = &ContactEntry(set, 1);
            for (unsigned contact = 1; contact < set->count; ++contact, ++previous)
            {
                for (unsigned j = previous->numA; j < previous->numB + previous->numA; ++j)
                    previous->offs[j] += static_cast<unsigned char>(selected);
            }
        }
    }
    int i = 0;
    if (i < key->numB)
    {
        do
        {
            unsigned short vertex = key->ids[key->numA + i];
            long index = set->unk0;
            int end;
            end = set->unk0 + set->unk1;
            while (index < end)
            {
                if (vertices[index] == vertex)
                    goto foundB;
                ++index;
            }
            vertices[index] = vertex;
            set->unk1++;
        foundB:
            entry.offs[key->numA + i] = static_cast<unsigned char>(index << 4);
            ++i;
        } while (i < key->numB);
    }
    return replaced;
}

// Compact the shared vertex table and re-encode every contact's offsets.
// src: COMMUNITY 0x00dae220
static __declspec(noinline) void __fastcall hkGskManifold_garbageCollect(int, ContactManifold* set)
{
    __declspec(align(16)) unsigned int usedWords[4];
    _mm_store_ps(reinterpret_cast<float*>(usedWords), _mm_setzero_ps());
    unsigned char* used = reinterpret_cast<unsigned char*>(usedWords);
    unsigned remap[16];
    unsigned contactCount = set->count;
    unsigned char* offs = ContactEntry(set, 0).offs;
    for (unsigned k = 0; k < contactCount; ++k)
    {
        int total = offs[-4] + offs[-3];
        used[offs[0] >> 4] = 1;
        used[offs[1] >> 4] = 1;
        if (total >= 3)
            used[offs[2] >> 4] = 1;
        if (total == 4)
            used[offs[3] >> 4] = 1;
        offs += 8;
    }
    unsigned short* vertices = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(set) + 4 + contactCount * 8);
    int total = set->unk0 + set->unk1;
    unsigned count = 0;
    unsigned offset = 0;
    for (int i = 0; i < total; ++i)
    {
        remap[i] = offset;
        if (used[i])
        {
            vertices[count++] = vertices[i];
            offset += 16;
        }
    }
    unsigned countA = remap[set->unk0] >> 4;
    set->unk0 = static_cast<unsigned char>(countA);
    set->unk1 = static_cast<unsigned char>(count - countA);
    for (unsigned i = 0; i < set->count; ++i)
    {
        S_00dad4d0_Entry& entry = ContactEntry(set, i);
        entry.offs[0] = static_cast<unsigned char>(remap[entry.offs[0] >> 4]);
        entry.offs[1] = static_cast<unsigned char>(remap[entry.offs[1] >> 4]);
        entry.offs[2] = static_cast<unsigned char>(remap[entry.offs[2] >> 4]);
        entry.offs[3] = static_cast<unsigned char>(remap[entry.offs[3] >> 4]);
    }
}
