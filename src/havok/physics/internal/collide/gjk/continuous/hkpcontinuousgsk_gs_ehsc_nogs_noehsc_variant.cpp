
// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
#include <xmmintrin.h>
// local form of hkVector4: 0x00db4e40 needs the trivial default/copy and reference-returning assignment (shared form: 1207 bytes, exe: 1151).
struct __declspec(align(16)) SweepVectorLocal_00db4e40
{
    float x, y, z, w;
    SweepVectorLocal_00db4e40& operator=(const SweepVectorLocal_00db4e40& o)
    {
        *(__m128*)this = *(const __m128*)&o;
        return *this;
    }
    __m128& q()
    {
        return *(__m128*)this;
    }
    const __m128& q() const
    {
        return *(const __m128*)this;
    }
};

struct SweepObj
{
    void* unk00;
    void* unk04;
    SweepVectorLocal_00db4e40* m_items;
    int m_uiItemCount;
    int unk10;
    int unk14;
    float m_18;
    float m_1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    float m_44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    float m_80;
};

struct SweepOut
{
    float t;
    int unk04, unk08, unk0c;
    SweepVectorLocal_00db4e40 v;
};

struct SweepState
{
    SweepVectorLocal_00db4e40 r00, r10, r20, r30, r40, r50, r60, r70, r80, r90, ra0, rb0;
    SweepVectorLocal_00db4e40 n;   // c0
    SweepVectorLocal_00db4e40 o;   // d0
    SweepVectorLocal_00db4e40 c;   // e0
    SweepVectorLocal_00db4e40 a;   // f0
    SweepVectorLocal_00db4e40 b;   // 100
    SweepVectorLocal_00db4e40 oa;  // 110
    SweepVectorLocal_00db4e40 ob;  // 120
};

void __cdecl hkTransform_setMulInverseMul_UpdateState_00db4b50(SweepObj* obj, float t, SweepState* st);
float __cdecl Object_ProcessEntries_00db4ca0(SweepObj* obj, float* p, SweepVectorLocal_00db4e40* v, float a, float b, float c, float d, float e,
                           SweepOut* out);

static inline __m128 Cross(const __m128& a, const __m128& b)
{
    __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}

static inline __m128 Dot3(const __m128& a, const __m128& b)
{
    __m128 x2 = _mm_mul_ps(a, b);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), r);
}

static inline __m128 Dot4xyz1(const __m128& a, const __m128& b)
{
    __m128 xx = _mm_mul_ps(a, b);
    __m128 x2 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(b, b, 0xff));
    __m128 x3 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    return _mm_add_ps(x2, x3);
}

// @fnv 0x00db4e40
// src: GUESS 0x00db4e40 (confidence: low)
void __cdecl Object_ProcessEntries_00db4e40(SweepObj* obj, float* p, SweepOut* out)
{
    float tEnd = 1.0f;
    float tCur = obj->m_80;
    int num = obj->m_uiItemCount;
    float tPrev = tCur;
    if (num == 0)
        return;
    do
    {
        SweepState st;
        hkTransform_setMulInverseMul_UpdateState_00db4b50(obj, tCur, &st);
        int i = *(volatile int*)&num;
        SweepVectorLocal_00db4e40* it = obj->m_items;
        float dt = tEnd - tCur;
        SweepVectorLocal_00db4e40* dst = it;
        num = 0;
        float margin = obj->m_44 * dt;
        float tNext = tEnd;
        for (; --i >= 0; it++)
        {
            float dist;
            _mm_store_ss(&dist, Dot4xyz1(_mm_sub_ps(it->q(), st.o.q()), st.n.q()));
            if (dist > p[0] + margin)
                continue;
            float d0 = dist - p[0];
            __m128 v1 = _mm_sub_ps(it->q(), st.oa.q());
            __m128 v2 = _mm_sub_ps(it->q(), st.ob.q());
            __m128 x = _mm_sub_ps(Cross(st.a.q(), v1), st.c.q());
            x = _mm_sub_ps(x, Cross(st.b.q(), v2));
            float vel;
            _mm_store_ss(&vel, Dot3(x, st.n.q()));
            float d1 = d0 + vel * dt;
            float lim = dt * 0.5 * dt * obj->m_18;
            if (d1 > lim)
                continue;
            if (dist < p[0])
            {
                if (tCur == obj->m_80)
                {
                    out->t = tCur;
                    tEnd = tCur;
                    out->v = *it;
                }
                else
                {
                    float w = it->w;
                    tEnd = w;
                    tEnd = Object_ProcessEntries_00db4ca0(obj, p, it, tPrev, tCur, w, dist, vel, out);
                }
            }
            else
            {
                SweepVectorLocal_00db4e40 tmp = *it;
                *it = *dst;
                *dst = tmp;
                dst->w = dist;
                num++;
                dst++;
                float g = dist - p[1];
                float h = 2.0 * g * obj->m_1c;
                if (h > dt * dt)
                    continue;
                float k = p[0] - p[1];
                float m = 2.0 * k * obj->m_1c;
                float r = sqrtf(h);
                if (vel >= 0.0f)
                {
                    r = vel * obj->m_1c * 2.0f + r;
                }
                else
                {
                    float n2 = -vel * obj->m_1c;
                    if (n2 > r)
                        r = n2;
                }
                if (r > dt)
                    continue;
                float r3 = sqrtf(m) + r;
                float hi = p[2];
                if (!(r3 > hi))
                    r3 = hi;
                float u = r3 + tCur;
                if (!(tNext < u))
                    tNext = u;
            }
        }
        if (tEnd < tCur)
            return;
        if (tCur == tNext && tEnd <= tCur)
            return;
        tPrev = tCur;
        tCur = tNext;
    } while (num != 0);
}

// Adapted from the project's prior contributor draft of 24 October 2026.
// The same-file caller lets VC2008 reproduce the private register convention.

extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010ec7f0;
extern const double DAT_010290f0;

// @fnv 0x00db49b0
// src: GUESS 0x00db49b0 (confidence: low)
static __declspec(noinline) float HkpcontinuousgskGsEhscNogsNoehsc_ComputeValues_00db49b0(char* a, char* b, __m128* p, __m128* v0, __m128* v1, __m128* v2, float t)
{
    float tmp;
    float d1;
    __m128 vb = *v1;
    __m128 q = _mm_mul_ps(_mm_xor_ps(*v2, DAT_010c44d0), vb);
    tmp = (t - *(float*)(a + 0x4c)) * *(float*)(a + 0x5c);
    __m128 v0x = *v0;
    __m128 qy = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
    _mm_store_ss(&d1, _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), qy));

    __m128 ev = _mm_set1_ps(tmp);
    __m128 L = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, ev), *(__m128*)(a + 0x40)),
                          _mm_mul_ps(*(__m128*)(a + 0x50), ev));
    __m128 w = _mm_sub_ps(v0x, L);
    __m128 c = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*p, *p, 0xc9), _mm_shuffle_ps(w, w, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(*p, *p, 0xd2), _mm_shuffle_ps(w, w, 0xc9)));
    c = _mm_mul_ps(c, vb);
    __m128 cy = _mm_add_ss(_mm_shuffle_ps(c, c, 0x55), c);
    _mm_store_ss(&tmp, _mm_add_ss(_mm_shuffle_ps(c, c, 0xaa), cy));

    float r = tmp;
    // This ordering also preserves the original unordered comparison behavior.
    d1 = (float)(((r <= 0) ? r * DAT_010290f0 : r / DAT_010290f0) + d1);

    tmp = (t - *(float*)(b + 0x4c)) * *(float*)(b + 0x5c);
    ev = _mm_set1_ps(tmp);
    L = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, ev), *(__m128*)(b + 0x40)),
                   _mm_mul_ps(*(__m128*)(b + 0x50), ev));
    w = _mm_sub_ps(v0x, L);
    // Keep one local copy for both shuffles of the second vector.
    __m128 plane1 = p[1];
    c = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(plane1, plane1, 0xc9), _mm_shuffle_ps(w, w, 0xd2)),
                   _mm_mul_ps(_mm_shuffle_ps(plane1, plane1, 0xd2), _mm_shuffle_ps(w, w, 0xc9)));
    c = _mm_mul_ps(c, vb);
    cy = _mm_add_ss(_mm_shuffle_ps(c, c, 0x55), c);
    _mm_store_ss(&tmp, _mm_add_ss(_mm_shuffle_ps(c, c, 0xaa), cy));

    r = tmp;
    if (r >= 0)
    {
        d1 = (float)(d1 - r * DAT_010290f0);
    }
    else
    {
        d1 = (float)(d1 - r / DAT_010290f0);
    }
    return d1;
}

__m128* volatile dbPlanes;
char* volatile dbBodyA;
char* volatile dbBodyB;
__m128* volatile dbPoint;
__m128* volatile dbDirection;
__m128* volatile dbVelocity;
volatile float dbTime;
volatile float dbResult;
void evaluatePlaneDistance()
{
    dbResult = HkpcontinuousgskGsEhscNogsNoehsc_ComputeValues_00db49b0(dbBodyA, dbBodyB, dbPlanes, dbPoint, dbDirection, dbVelocity, dbTime);
}
