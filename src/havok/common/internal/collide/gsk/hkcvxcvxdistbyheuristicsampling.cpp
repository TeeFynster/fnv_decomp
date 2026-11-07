// src/havok/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkcvxcvxdistbyheuristicsampling.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Baseline from an unnamed contributor, 2026-10-28, packet score 58 (unverified).
// The inherited volatile-global caller is replaced by an ordinary argument-forwarding caller.
// No unverified non-aliasing qualifier is imposed on the result pointer.
// Exe 0x00e625c0 FUN_00e625c0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    };
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps(const float*);
    int _mm_movemask_ps(LocalM128);
    float _mm_cvtss_f32(LocalM128);
}

extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern const LocalM128 DAT_010c44d0;
struct Matrix;
struct Scalar
{
    LocalM128 v;
    Scalar(LocalM128 x) : v(x)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, v);
        return value;
    }
};
// hkVector4 stand-in with the unit's own inline setNeg4/_setRotatedInverseDir/_setTransformedPos/setSub4/dot3/getSimdAt bodies over a local __m128 (Matrix = hkTransform).
struct CvxDistVector4
{
    union
    {
        LocalM128 v;
        struct
        {
            float x, y, z, w;
        };
    };
    CvxDistVector4()
    {}
    CvxDistVector4(const CvxDistVector4& a) : v(a.v)
    {}
    void operator=(const CvxDistVector4& a)
    {
        v = a.v;
    }
    void negative(const CvxDistVector4& n)
    {
        v = _mm_xor_ps(n.v, DAT_010c44d0);
    }
    void inv(const Matrix& m, const CvxDistVector4& n);
    void point(const Matrix& m, const CvxDistVector4& b);
    void difference(const CvxDistVector4& a, const CvxDistVector4& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    Scalar dot(const CvxDistVector4& n) const
    {
        LocalM128 p = _mm_mul_ps(v, n.v);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return Scalar(_mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy));
    }
    Scalar at(int i) const
    {
        if (i == 0)
            return Scalar(v);
        if (i == 1)
            return Scalar(_mm_shuffle_ps(v, v, 0x55));
        if (i == 2)
            return Scalar(_mm_shuffle_ps(v, v, 0xaa));
        return Scalar(_mm_shuffle_ps(v, v, 0xff));
    }
    void set(float a, float b, float c, float d)
    {
        v = _mm_setr_ps(a, b, c, d);
    }
};
struct Matrix
{
    CvxDistVector4 row0, row1, row2, row3;
};
__forceinline void CvxDistVector4::inv(const Matrix& m, const CvxDistVector4& n)
{
    LocalM128 a = m.row0.v, b = m.row1.v, c = m.row2.v;
    LocalM128 low = _mm_unpacklo_ps(a, b);
    LocalM128 high = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c, 0xe4);
    a = _mm_movelh_ps(low, c);
    b = _mm_shuffle_ps(_mm_movehl_ps(a, low), c, 0xd4);
    c = high;
    LocalM128 x = _mm_shuffle_ps(n.v, n.v, 0);
    LocalM128 px = _mm_mul_ps(a, x);
    LocalM128 y = _mm_shuffle_ps(n.v, n.v, 0x55);
    LocalM128 py = _mm_mul_ps(b, y);
    LocalM128 z = _mm_shuffle_ps(n.v, n.v, 0xaa);
    LocalM128 pz = _mm_mul_ps(c, z);
    v = _mm_add_ps(_mm_add_ps(px, py), pz);
}
__forceinline void CvxDistVector4::point(const Matrix& m, const CvxDistVector4& b)
{
    LocalM128 x = _mm_shuffle_ps(b.v, b.v, 0);
    LocalM128 px = _mm_mul_ps(m.row0.v, x);
    LocalM128 y = _mm_shuffle_ps(b.v, b.v, 0x55);
    LocalM128 py = _mm_mul_ps(m.row1.v, y);
    LocalM128 z = _mm_shuffle_ps(b.v, b.v, 0xaa);
    LocalM128 pz = _mm_mul_ps(m.row2.v, z);
    v = _mm_add_ps(_mm_add_ps(px, py), _mm_add_ps(pz, m.row3.v));
}
struct Shape
{
    virtual void reserved() = 0;
    virtual void transform(const CvxDistVector4*, CvxDistVector4*) = 0;
};
struct Result
{
    CvxDistVector4 pointA, pointB, localB, plane;
};
// @fnv 0x00e625c0
// src: GUESS 0x00e625c0 (confidence: low)
static __declspec(noinline) void Object_UpdateFields_00e625c0(const Matrix* matrix, Shape* shape, Shape* other, const CvxDistVector4* normal,
                                              Result* result)
{
    Result* output = result;
    CvxDistVector4 opposite, local, a, b;
    opposite.negative(*normal);
    local.inv(*matrix, *normal);
    shape->transform(&opposite, &a);
    other->transform(&local, &b);
    CvxDistVector4 mapped, delta;
    mapped.point(*matrix, b);
    delta.difference(a, mapped);
    CvxDistVector4 n = *normal;
    Scalar distance = delta.dot(n);
    if (_mm_movemask_ps(_mm_sub_ss(output->plane.at(3).v, distance.v)) & 1)
    {

        output->plane.set(n.at(0), n.at(1), n.at(2), distance);
        output->pointA = a;
        output->localB = b;
        output->pointB = mapped;
    }
}
// An ordinary caller keeps this internal helper present and lets the compiler
// assign its internal register ABI. It forwards genuine function arguments.
void ProjectShapes(const Matrix* matrix, Shape* shape, Shape* other, const CvxDistVector4* normal, Result* result)
{
    Object_UpdateFields_00e625c0(matrix, shape, other, normal, result);
}
