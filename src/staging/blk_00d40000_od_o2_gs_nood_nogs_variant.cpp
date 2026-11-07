
// src/staging/blk_00d40000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
extern float DAT_01017718, DAT_01011d78, DAT_01016248;

struct FloatMatrix3
{
    __m128 row0, row1, row2;
};

struct ConstraintBasis
{
    __m128 unk00, unk10;
    __m128 basisA[3], basisB[3];
    void ComputeValues_00d4f3d0(const FloatMatrix3*, const FloatMatrix3*, const __m128*, const __m128*);
};

static __forceinline __m128 NormalizeAxis(__m128 value)
{
    __m128 square = _mm_mul_ps(value, value);
    __m128 dot =
        _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square));
    __m128 reciprocal = _mm_rsqrt_ss(dot);
    __m128 correction = _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(dot, reciprocal), reciprocal));
    __m128 factor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), reciprocal), correction);
    factor = _mm_andnot_ps(_mm_cmpeq_ss(dot, _mm_set_ss(DAT_01011d78)), factor);
    return _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), value);
}

static __forceinline void Transform(const FloatMatrix3* m, const __m128* basis, __m128* out)
{
    __m128 r0 = m->row0, r1 = m->row1, r2 = m->row2;
    __m128 lowSave = _mm_unpacklo_ps(r0, r1);
    r0 = _mm_unpackhi_ps(r0, r1);
    r1 = lowSave;
    __m128 c0 = _mm_movelh_ps(r1, r2);
    __m128 c1 = _mm_movehl_ps(c0, r1);
    c1 = _mm_shuffle_ps(c1, r2, 0xd4);
    __m128 c2 = _mm_shuffle_ps(r0, r2, 0xe4);
    for (int i = 0; i < 3; ++i)
    {
        __m128 v = basis[i];
        out[i] =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0)),
                       _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
    }
}

// @fnv 0x00d4f3d0
// src: GUESS 0x00d4f3d0 (confidence: low)
void ConstraintBasis::ComputeValues_00d4f3d0(const FloatMatrix3* a, const FloatMatrix3* b, const __m128* axisA,
                                   const __m128* axisB)
{
    __m128 basis[3];
    basis[0] = NormalizeAxis(*axisA);
    basis[1] = NormalizeAxis(*axisB);
    basis[2] =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(basis[1], basis[1], 0xd2), _mm_shuffle_ps(basis[0], basis[0], 0xc9)),
                   _mm_mul_ps(_mm_shuffle_ps(basis[1], basis[1], 0xc9), _mm_shuffle_ps(basis[0], basis[0], 0xd2)));
    Transform(a, basis, basisA);
    Transform(b, basis, basisB);
}

struct StubHeapHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* heap;
};
StubHeapHolder* hkMemoryRouter_getInstance();
void ResizeAudioStream(void* heap, void* arr, int elemSize);

template <class T> struct StubArray
{
    T* data;
    int count;
    unsigned int capacity;
    static void Construct(T* base, int n, const T& c)
    {
        for (int i = 0; i < n; ++i)
            base[i] = c;
    }
    static void Construct1(T* p, const T& c)
    {
        *p = c;
    }
    void Add(const T& v)
    {
        StubHeapHolder* h = hkMemoryRouter_getInstance();
        if (count == (int)(capacity & 0x3fffffff))
            ResizeAudioStream(h->heap, this, sizeof(T));
        Construct(data + count, 1, v);
        count++;
    }
};
struct StubVecArray
{
    __m128* data;
    int count;
    unsigned int capacity;
    void Add(const __m128& v)
    {
        StubHeapHolder* h = hkMemoryRouter_getInstance();
        if (count == (int)(capacity & 0x3fffffff))
            ResizeAudioStream(h->heap, this, sizeof(__m128));
        data[count] = v;
        count++;
    }
};
struct StubObj;
struct StubBuilder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    StubArray<__m128> vecs;
    StubArray<int> ops;
    int unk28;
    int unk2C;
    int unk30;
    StubArray<StubObj*> refs;
};
struct StubObj
{
    void Touch();
};
struct StubOwner
{
    int unk00;
    StubBuilder* builder;
    int UpdateState_00d52790(unsigned char flag, StubObj* obj);
};

// @fnv 0x00d52790
// src: GUESS 0x00d52790 (confidence: low)
int StubOwner::UpdateState_00d52790(unsigned char flag, StubObj* obj)
{
    builder->ops.Add(0xf);
    builder->ops.Add(flag);
    int r = builder->vecs.count;
    __m128 v = _mm_setr_ps((float)builder->refs.count, 0.0f, 0.0f, 0.0f);
    obj->Touch();
    builder->vecs.Add(v);
    builder->refs.Add(obj);
    StubBuilder* b = builder;
    b->unk08 += 1;
    b->unk04 += 0x50;
    b->unk0C += 3;
    return r;
}
