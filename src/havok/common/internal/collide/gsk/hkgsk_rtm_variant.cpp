#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/common/internal/collide/gsk/hkgsk_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/collide/gsk/hkgsk.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/internal/collide/gsk/hkgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the original intrinsic union: the CRT byte arrays change VC9 /GS instrumentation.
#define _INCLUDED_MM2
// Exe 0x00e4c730 FUN_00e4c730: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../../../../../include/hkVector4.h"
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../../include/Vec4.h"

extern "C" void _ReadWriteBarrier(void);
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
}
typedef float hkReal;

__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::add4(const hkVector4& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}
__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline int hkVector4::lessZeroXYZ() const
{
    return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
}

extern LocalM128 DAT_010c44d0;
__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
static __forceinline int hkDot3LessZero(const hkVector4& a, const hkVector4& b)
{
    LocalM128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 xyz = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
    return _mm_movemask_ps(xyz) & 1;
}
static __forceinline void hkTranspose3(hkVector4& c0, hkVector4& c1, hkVector4& c2)
{
    LocalM128 tmp = _mm_unpacklo_ps(c0.m_vComponents, c1.m_vComponents);
    LocalM128 ctmp = _mm_unpackhi_ps(c0.m_vComponents, c1.m_vComponents);
    c0.m_vComponents = _mm_movelh_ps(tmp, c2.m_vComponents);
    c1.m_vComponents = _mm_shuffle_ps(_mm_movehl_ps(c0.m_vComponents, tmp), c2.m_vComponents, 0xd4);
    c2.m_vComponents = _mm_shuffle_ps(ctmp, c2.m_vComponents, 0xe4);
}
static __forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                                    const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
    hkVector4 c0;
    c0.setMul4(a0, b0);
    hkVector4 c1;
    c1.setMul4(a1, b1);
    hkVector4 c2;
    c2.setMul4(a2, b2);
    hkTranspose3(c0, c1, c2);
    dotsOut.setAdd4(c0, c1);
    dotsOut.add4(c2);
}
template <class T> static __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}
struct TriangleVerts
{
    hkVector4 m_kVertices[3];
    hkVector4 m_extra30;
    hkVector4 m_extra40;
    hkVector4 m_extra50;
};
struct TriangleSolver
{
    hkVector4 m_barycentric;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_flipped;
    hkVector4 m_kPoint;
    hkVector4 m_unk30;
    hkVector4 m_unk40;
    hkVector4 m_unk50;
    hkVector4 m_unk60;
    hkVector4 m_unk70;
    hkVector4 m_unk80;
    hkVector4 m_unk90;
    hkVector4 m_kSmartReference;

    int ComputeTriangleBarycentricTerms(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut);
};
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_div_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps();
    int _mm_movemask_ps(LocalM128);
    void _mm_store_ss(float*, LocalM128);
}
struct Out
{
    int* p;
    Out(int* a) : p(a)
    {}
};
static const LocalM128 one4 = {1, 1, 1, 1};
struct Scalar
{
    LocalM128 q;
    Scalar()
    {}
    Scalar(const LocalM128& a) : q(a)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, q);
        return value;
    }
    LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
inline Scalar operator*(const Scalar& a, const Scalar& b)
{
    return _mm_mul_ss(a.q, b.q);
}
inline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.q, b.q);
}
inline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.q, b.q);
}
struct V
{
    union
    {
        LocalM128 q;
        struct
        {
            unsigned x, y, z, w;
        };
    };
    V()
    {}
    V(const V& a) : x(a.x), y(a.y), z(a.z), w(a.w)
    {}
    V& operator=(const V& a)
    {
        q = a.q;
        return *this;
    }
    void sub(const V& a, const V& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    void cross(const V& a, const V& b)
    {
        LocalM128 l = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        LocalM128 r = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(l, r);
    }
    Scalar dot(const V& b) const
    {
        LocalM128 p = _mm_mul_ps(q, b.q);
        LocalM128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), t);
    }
    void interpolate(const V& a, const V& b, const Scalar& f)
    {
        LocalM128 t = f.broadcast();
        LocalM128 s = _mm_sub_ps(one4, t);
        q = _mm_add_ps(_mm_mul_ps(s, a.q), _mm_mul_ps(t, b.q));
    }
    Scalar component(int i) const
    {
        switch (i)
        {
        case 0:
            return q;
        case 1:
            return _mm_shuffle_ps(q, q, 0x55);
        case 2:
            return _mm_shuffle_ps(q, q, 0xaa);
        default:
            return _mm_shuffle_ps(q, q, 0xff);
        }
    }
};
static __forceinline void Swap(V& a, V& b)
{
    V saved = a;
    a = b;
    b = saved;
}
static __forceinline bool ComparePlane(const V& oldValue, const V& newValue, int i, int j)
{
    Scalar oldI = oldValue.component(i);
    Scalar oldJ = oldValue.component(j);
    Scalar deltaI = newValue.component(i) - oldI;
    Scalar deltaJ = newValue.component(j) - oldJ;
    return float(oldJ * deltaI) > float(oldI * deltaJ);
}
struct Shape
{
    V points[4];
    V anchors[3];
};
struct Clip
{
    V point;
    V separation;
    float distance;
};
struct Both
{
    Clip first;
    Clip second;
};
extern "C" int hkLineSegmentUtil_closestLineSegLineSeg(Shape*, const V*, const V*, const V*, Clip*);
static __forceinline void ThreeDots(const V& first, const V& firstWeight, const V& second, const V& secondWeight,
                                    const V& third, const V& thirdWeight, V& out)
{
    register LocalM128 products0 = _mm_mul_ps(first.q, firstWeight.q);
    register LocalM128 products1 = _mm_mul_ps(second.q, secondWeight.q);
    register LocalM128 products2 = _mm_mul_ps(third.q, thirdWeight.q);
    LocalM128 lower = _mm_unpacklo_ps(products0, products1);
    LocalM128 upper = _mm_shuffle_ps(_mm_unpackhi_ps(products0, products1), products2, 0xe4);
    products0 = _mm_movelh_ps(lower, products2);
    products1 = _mm_shuffle_ps(_mm_movehl_ps(products0, lower), products2, 0xd4);
    products2 = upper;
    out.q = _mm_add_ps(_mm_add_ps(products0, products1), products2);
}
static __forceinline int mask(const V& p, const Shape* b)
{
    V e0, e1, e2, n, d0, d1, d2, c0, c1, c2;
    e0.sub(b->points[2], b->points[1]);
    e1.sub(b->points[0], b->points[2]);
    e2.sub(b->points[1], b->points[0]);
    n.cross(e0, e1);
    d0.sub(p, b->points[1]);
    d1.sub(p, b->points[2]);
    d2.sub(p, b->points[0]);
    c0.cross(d0, e0);
    c1.cross(d1, e1);
    c2.cross(d2, e2);
    V sum;
    ThreeDots(c0, n, c1, n, c2, n, sum);
    return _mm_movemask_ps(_mm_cmplt_ps(sum.q, _mm_setzero_ps())) & 7;
}
static __forceinline void ReplaceSelected(V& point, V& anchor, const V& newPoint, const V& newAnchor, int* count)
{
    point = newPoint;
    anchor = newAnchor;
    *count = 2;
}
static __forceinline void CollapseFirst(Shape* shape, const V& point, int* count)
{
    *count = 1;
    shape->points[0] = point;
    shape->anchors[0] = shape->anchors[1];
}
struct State
{
    V origin;
    int m10, m14, m18, m1c;
    V m20, m30, m40, m50, m60, m70, m80, m90, ma0, mb0, mc0, md0, me0, mf0, m100, m110;
    V direction;
    int ComputeTriangleBarycentricTerms(Shape*, Shape*, V*);
    int GetTriangleEdgeSignMask(V*, Shape*, V*);
    int ProcessAndReturnValue_00e4bbe0(Shape*, Shape*, int*, int*, unsigned char, int);
};

extern "C"
{
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_div_ss(LocalM128, LocalM128);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_load_ss(float const*);
    void _mm_store_ss(float*, LocalM128);
}

typedef float Real;
typedef unsigned char UChar;
typedef signed char SChar;

template <class T> class Pad
{
  public:
    __forceinline Pad()
    {}
    __forceinline Pad(T e) : m_kStorage(e)
    {}
    __forceinline void operator=(T e)
    {
        m_kStorage = e;
    }
    __forceinline T val() const
    {
        return m_kStorage;
    }
    __forceinline T operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator T() const
    {
        return val();
    }

  private:
    T m_kStorage;
};

class SReal
{
  public:
    SReal(const LocalM128& x) : m_vValue(x)
    {}
    SReal(Real x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    SReal()
    {}
    operator Real() const
    {
        Real s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return m_vValue;
    }

  private:
    LocalM128 m_vValue;
};

inline SReal __cdecl operator*(const SReal& r, const SReal& s)
{
    return _mm_mul_ss(r.getQuad(), s.getQuad());
}
inline SReal __cdecl operator-(const SReal& r, const SReal& s)
{
    return _mm_sub_ss(r.getQuad(), s.getQuad());
}
inline SReal __cdecl operator+(const SReal& r, const SReal& s)
{
    return _mm_add_ss(r.getQuad(), s.getQuad());
}
inline SReal __cdecl operator/(const SReal& r, const SReal& s)
{
    return _mm_div_ss(r.getQuad(), s.getQuad());
}

class VComp
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_X = 1,
        MASK_Y = 2,
        MASK_XY = 3,
        MASK_Z = 4,
        MASK_XZ = 5,
        MASK_YZ = 6,
        MASK_XYZ = 7,
        MASK_W = 8,
        MASK_XW = 9,
        MASK_YW = 10,
        MASK_XYW = 11,
        MASK_ZW = 12,
        MASK_XZW = 13,
        MASK_YZW = 14,
        MASK_XYZW = 15
    };
    __forceinline int allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(m_uiMask) & m) == m;
    }
    __forceinline int anyIsSet(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
    __forceinline int allAreSet() const
    {
        return _mm_movemask_ps(m_uiMask) == MASK_XYZW;
    }
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(m_uiMask);
    }
    __forceinline int GetLaneMask(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }

  private:
    LocalM128 m_uiMask;
    friend class Vec4;
};

extern LocalM128 DAT_010c44d0;
extern LocalM128 DAT_010ec7f0;

// hkMatrix3 (three Vec4 columns; Rot/Xform below mirror hkRotation/hkTransform) over this unit's Vec4 SIMD stand-in.
class GskMatrix3
{
  public:
    __forceinline GskMatrix3()
    {}
    __forceinline Vec4& getColumn(int i);
    __forceinline const Vec4& getColumn(int i) const;

  protected:
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
};

class Rot : public GskMatrix3
{
};

class Xform
{
  public:
    __forceinline Xform()
    {}
    __forceinline Xform(const Xform& t);
    __forceinline const Vec4& getTranslation() const;
    __forceinline Rot& getRotation();
    __forceinline const Rot& getRotation() const;

  public:
    Rot m_rotation;
    Vec4 m_vTranslation;
};

__forceinline LocalM128& Vec4::getQuad()
{
    return m_vComponents;
}
__forceinline const LocalM128& Vec4::getQuad() const
{
    return m_vComponents;
}
__forceinline void Vec4::operator=(const Vec4& v)
{
    m_vComponents = v.m_vComponents;
}
__forceinline void Vec4::operator=(const LocalM128& r)
{
    getQuad() = r;
}
__forceinline void Vec4::set(Real a, Real b, Real c, Real d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
__forceinline void Vec4::SetAllComponents(const SReal& a)
{
    m_vComponents = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
}
__forceinline void Vec4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
__forceinline int Vec4::getInt24W() const
{
    return (reinterpret_cast<const unsigned int*>(this))[3] & ~0x3f000000;
}
__forceinline void Vec4::setSub4(const Vec4& v0, const Vec4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void Vec4::setAddMul4(const Vec4& a, const Vec4& b, const SReal& r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
}
__forceinline void Vec4::setCross(const Vec4& v0, const Vec4& v1)
{
    LocalM128 cross0;
    cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1;
    cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline void Vec4::setInterpolate4(const Vec4& v0, const Vec4& v1, const SReal& _t)
{
    LocalM128 t = _t.broadcast();
    LocalM128 s = _mm_sub_ps(DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
__forceinline VComp Vec4::compareLessThan4(const Vec4& a) const
{
    VComp m;
    m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
    return m;
}
__forceinline VComp Vec4::compareLessThanZero4() const
{
    Vec4 zero;
    zero.setZero4();
    VComp m;
    m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero);
    return m;
}
__forceinline VComp Vec4::compareGreaterThan4(const Vec4& a) const
{
    return a.compareLessThan4(*this);
}
__forceinline void Vec4::setNeg4(const Vec4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
__forceinline SReal Vec4::dot3(const Vec4& a) const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
__forceinline SReal Vec4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
__forceinline SReal Vec4::lengthInverse3() const
{
    const LocalM128 half = _mm_set_ss(0.5f);
    const LocalM128 three = _mm_set_ss(3.0f);
    const LocalM128 zero = _mm_set_ss(0.0f);
    const LocalM128 len2 = this->dot3(*this).getQuad();
    const LocalM128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const LocalM128 approx = _mm_rsqrt_ss(len2);
    const LocalM128 refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
__forceinline SReal Vec4::normalizeWithLength3()
{
    LocalM128 len2 = this->dot3(*this).getQuad();
    LocalM128 lenInv = lengthInverse3().broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    return _mm_mul_ss(len2, lenInv);
}
__forceinline void Vec4::fastNormalize3NonZero()
{
    LocalM128 len2 = this->dot3(*this).getQuad();
    SReal approx = _mm_rsqrt_ss(len2);
    m_vComponents = _mm_mul_ps(m_vComponents, approx.broadcast());
}
__forceinline Real& Vec4::operator()(int a)
{
    return reinterpret_cast<Real*>(&m_vComponents)[a];
}
__forceinline const Real& Vec4::operator()(int a) const
{
    return reinterpret_cast<const Real*>(&m_vComponents)[a];
}
__forceinline SReal Vec4::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return m_vComponents;
    case 1:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
    case 2:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
    case 3:
    default:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
}

inline Vec4& GskMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
inline const Vec4& GskMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

Xform::Xform(const Xform& t)
{
    const Vec4 r0 = t.m_rotation.getColumn(0);
    const Vec4 r1 = t.m_rotation.getColumn(1);
    const Vec4 r2 = t.m_rotation.getColumn(2);
    const Vec4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}
const Vec4& Xform::getTranslation() const
{
    return m_vTranslation;
}
Rot& Xform::getRotation()
{
    return m_rotation;
}
const Rot& Xform::getRotation() const
{
    return m_rotation;
}

__forceinline void Vec4::rotInvDir(const Rot& r, const Vec4& b)
{
    LocalM128 c0 = r.getColumn(0).m_vComponents;
    LocalM128 c1 = r.getColumn(1).m_vComponents;
    LocalM128 c2 = r.getColumn(2).m_vComponents;
    {
        LocalM128 _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
        c2 = _ctmp;
    }
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const LocalM128 r0 = _mm_mul_ps(c0, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(c1, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void Vec4::xformPos(const Xform& t, const Vec4& b)
{
    const Rot& r = t.getRotation();
    LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    LocalM128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    LocalM128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    LocalM128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}

inline int __cdecl isNeg(const SReal& r0)
{
    return _mm_movemask_ps(r0.getQuad()) & VComp::MASK_X;
}

template <typename T> __forceinline void __cdecl swap16(T& x, T& y)
{
    __declspec(align(16)) T t = x;
    x = y;
    y = t;
}

class VUtil
{
  public:
    __forceinline static void __cdecl mulSigns4(Vec4& inout, const Vec4& signs);
    __forceinline static void __cdecl TransformPointArray(const Xform& t, const Vec4* vectorsIn, int numVectors,
                                                          Vec4* vectorsOut);
    __forceinline static void __cdecl dot3_3vs3(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1,
                                                const Vec4& a2, const Vec4& b2, Vec4& dotsOut);
    __forceinline static void __cdecl dot3_4vs4(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1,
                                                const Vec4& a2, const Vec4& b2, const Vec4& a3, const Vec4& b3,
                                                Vec4& dotsOut);
};

inline void __cdecl VUtil::mulSigns4(Vec4& inout, const Vec4& signs)
{
    inout.getQuad() = _mm_xor_ps(inout.getQuad(), _mm_and_ps(signs.getQuad(), DAT_010c44d0));
}

inline void __cdecl VUtil::TransformPointArray(const Xform& t, const Vec4* vectorsIn, int numVectors, Vec4* vectorsOut)
{
    Xform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i].xformPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

inline void __cdecl VUtil::dot3_3vs3(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1, const Vec4& a2,
                                     const Vec4& b2, Vec4& dotsOut)
{
    register LocalM128 c0 = _mm_mul_ps(a0.getQuad(), b0.getQuad());
    register LocalM128 c1 = _mm_mul_ps(a1.getQuad(), b1.getQuad());
    register LocalM128 c2 = _mm_mul_ps(a2.getQuad(), b2.getQuad());
    {
        LocalM128 _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
        c2 = _ctmp;
    }
    dotsOut.getQuad() = _mm_add_ps(_mm_add_ps(c0, c1), c2);
}

inline void __cdecl VUtil::dot3_4vs4(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1, const Vec4& a2,
                                     const Vec4& b2, const Vec4& a3, const Vec4& b3, Vec4& dotsOut)
{
    dotsOut(0) = a0.dot3(b0);
    dotsOut(1) = a1.dot3(b1);
    dotsOut(2) = a2.dot3(b2);
    dotsOut(3) = a3.dot3(b3);
}

class SegUtil
{
  public:
    enum
    {
        CLSLS_POINTA_START = 1,
        CLSLS_POINTA_END = 2,
        CLSLS_POINTB_START = 4,
        CLSLS_POINTB_END = 8
    };
    struct Result
    {
        Vec4 m_kFirstVector;
        Vec4 m_kClosestPointOnSecond;
        Pad<Real> m_fValue;
    };
    static int __cdecl hkLineSegmentUtil_closestLineSegLineSeg(const Vec4& A, const Vec4& dA, const Vec4& B, const Vec4& dB, Result& result);
};

extern const SChar DAT_010ececc[];
extern const SChar DAT_010eced4[];

struct GskOut
{
    Vec4 m_vPointOnShapeA;
    Vec4 m_vPointOnShapeB;
};

struct GskCache
{
    UChar m_ausVertexIds[4];
    UChar m_ucVertexCount;
    UChar m_ucUnknownByte;
};

struct GskShape
{
    virtual ~GskShape()
    {}
    virtual void GetSupportPoint(const Vec4& direction, Vec4* supportingVertexOut) const = 0;
    virtual void GetVerticesForIds(UChar* ids, int numIds, Vec4* verticesOut) const;
};

enum GskStatus
{
    GSK_OK = 0,
    GSK_PD_HEURISTIC_SAMPLING = 1,
    GSK_PD_OUT_OF_MEMORY = 2,
    GSK_PD_DISTANCE_TOO_BIG = 3,
    GSK_PENETRATING = 4,
    GSK_PD_UNSOLVABLE = 5
};

int __cdecl Runtime_ProcessEntries_00e4b810(const Vec4& point, const Vec4* vertices, Real sign);

extern const VComp::Mask DAT_010ec600[];
extern const VComp::Mask DAT_010ec5f0[];

class PenUtil
{
  public:
    void init(const GskShape* shapeA, const GskShape* shapeB, const Xform& aTb, Real epsTol, Vec4* pointsAinA,
              Vec4* pointsBinB, Vec4* simplex, int simplexSize);
    GskStatus ComputePenetration(GskOut& out);

  public:
    Xform m_kTransform;
    Vec4 m_kPenetrationVector;
    Pad<Real> m_fEpsilonTolerance;
    Pad<const GskShape*> m_pShapeA;
    Pad<const GskShape*> m_pShapeB;
    Pad<int> m_iSimplexDimension;
    Pad<Vec4*> m_pPointsAInA;
    Pad<Vec4*> m_pPointsBInB;
    Pad<Vec4*> m_kVertexPosition;
    Pad<int> m_iSimplexSize;
};

extern "C" void heuristicSampling(const GskShape* shapeA, const GskShape* shapeB, const Xform& aTb, Vec4* verticesA,
                                  Vec4* verticesBinB, GskOut& output);

class Gsk
{
  public:
    struct Input
    {
        Xform m_kTransform;
        Pad<const GskShape*> m_pShapeA;
        Pad<const GskShape*> m_pShapeB;
        SReal m_fBlendWeight;
    };

    GskStatus hkGsk_getClosestPoint(const Input& input, GskCache* __restrict cache, GskOut& output);

    enum
    {
        GSK_NONE_NONE = 0,
        GSK_POINT_POINT = 9,
        GSK_POINT_EDGE = 10,
        GSK_EDGE_POINT = 17,
        GSK_POINT_TRIANGLE = 11,
        GSK_TRIANGLE_POINT = 25,
        GSK_EDGE_TRIANGLE = 19,
        GSK_TRIANGLE_EDGE = 26,
        GSK_POINT_TETRA = 12,
        GSK_TETRA_POINT = 33,
        GSK_EDGE_EDGE = 18
    };
    enum NextCase
    {
        NEXT_IS_BREAK = 0,
        NEXT_IS_PENETRATION = 1,
        NEXT_IS_EDGE_EDGE = 2
    };
    enum SupportTypes
    {
        BUILD_NEG_SUPPORT = -1,
        BUILD_NO_SUPPORT = 0,
        BUILD_POS_SUPPORT = 1
    };
    enum SupportState
    {
        SUPPORT_CHANGED = 0,
        DONT_CALL_GET_SUPPORTING_VERTEX_A = 1,
        DONT_CALL_GET_SUPPORTING_VERTEX_B = -1
    };
    enum ReduceDimensionResult
    {
        REDUCE_DIMENSION_OK = 0,
        REDUCE_DIMENSION_PENETRATION = 1
    };

  protected:
    int ComputeTriangleBarycentricTerms(const Vec4& support, Vec4* __restrict vertices, Vec4& normalOut);
    int checkTri0(const Vec4& support, Vec4* __restrict vertices, Vec4& normalOut);
    int isPointInTriangle(const Vec4& point, const Vec4* __restrict vertices);
    NextCase ProcessAndReturnValue_00e4bbe0(Vec4* __restrict vertexA, Vec4* __restrict vertexB, Pad<int>& dimA, Pad<int>& dimB,
                          bool comingFromEdgeEdge, SupportTypes supportType);
    __forceinline ReduceDimensionResult reduceDimension(Pad<int>& dimA, Pad<int>& dimB, Vec4& support);
    void ProcessEntries_00e4c230(const GskShape* shapeA, const GskShape* shapeB, const Xform& aTb, Pad<int>& dimA, Pad<int>& dimB,
                      GskOut& output);

  public:
    Vec4 m_pCachedPoint;
    Pad<int> m_iCacheState;
    SupportState m_eSupportState;
    Pad<unsigned int> m_uiCacheFlags;
    Pad<int> m_iFeatureChange;
    Vec4 m_akPackedVerticesA[4];
    Vec4 m_iFadeNodeMode[4];
    Vec4 m_akCachedVectors[4];
    Vec4 m_akPackedVerticesB[4];
    Vec4 m_pSupport;
    SegUtil::Result m_kVectorPairResult;
};

static __forceinline int process_point_edge(Vec4* __restrict vertexA, Vec4* __restrict vertexB, int dimB, Vec4& support,
                                            Gsk::SupportTypes stype)
{
    Vec4 edge;
    edge.setSub4(vertexB[1], vertexB[0]);
    Vec4 a;
    a.setSub4(vertexB[1], vertexA[0]);
    Vec4 b;
    b.setSub4(vertexB[0], vertexA[0]);
    SReal adot = a.dot3(edge);
    SReal bdot = b.dot3(edge);
    int aneg = isNeg(adot);
    int bneg = isNeg(bdot);
    if (aneg != bneg)
    {
        edge.fastNormalize3NonZero();
        Vec4 c;
        c.setCross(a, b);
        if (stype == Gsk::BUILD_POS_SUPPORT)
        {
            support.setCross(edge, c);
        }
        else
        {
            support.setCross(c, edge);
        }
    }
    else
    {
        if (aneg)
        {
            vertexB[0] = vertexB[1];
            vertexB[4] = vertexB[5];
        }
        dimB = 1;
        if (stype == Gsk::BUILD_POS_SUPPORT)
        {
            support.setSub4(vertexA[0], vertexB[0]);
        }
        else
        {
            support.setSub4(vertexB[0], vertexA[0]);
        }
    }
    return dimB;
}

// src: GUESS 0x00e4bbe0 (confidence: low)
Gsk::NextCase Gsk::ProcessAndReturnValue_00e4bbe0(Vec4* __restrict vertexA, Vec4* __restrict vertexB, Pad<int>& dimA, Pad<int>& dimB,
                                bool comingFromEdgeEdge, SupportTypes supportType)
{
    if (comingFromEdgeEdge)
    {
        Vec4 edge0;
        edge0.setSub4(vertexB[1], vertexB[2]);
        Vec4 edge1;
        edge1.setSub4(vertexB[0], vertexB[2]);

        Vec4 normal;
        normal.setCross(edge0, edge1);

        Vec4 diff0;
        diff0.setSub4(vertexA[0], vertexB[0]);
        Vec4 diff1;
        diff1.setSub4(vertexA[1], vertexB[0]);

        SReal dot0 = normal.dot3(diff0);
        SReal dot1 = normal.dot3(diff1);
        SReal dot0Sqrd = dot0 * dot0;
        SReal dot1Sqrd = dot1 * dot1;
        if (isNeg(dot0 * dot1))
        {
            {
                SReal a = dot0 / (dot0 - dot1);
                Vec4 pointOnSurface;
                pointOnSurface.setInterpolate4(vertexA[0], vertexA[1], a);
                if (isPointInTriangle(pointOnSurface, vertexB))
                {
                    return NEXT_IS_PENETRATION;
                }
            }
        checkEdges: {
            Vec4 edgeA;
            edgeA.setSub4(vertexA[1], vertexA[0]);
            SegUtil::Result result0;
            SegUtil::Result result1;
            SegUtil::hkLineSegmentUtil_closestLineSegLineSeg(vertexA[0], edgeA, vertexB[2], edge0, result0);
            SegUtil::hkLineSegmentUtil_closestLineSegLineSeg(vertexA[0], edgeA, vertexB[2], edge1, result1);

            int index = (result0.m_fValue > result1.m_fValue) ? 1 : 0;

            vertexB[index] = vertexB[2];
            vertexB[index + 4] = vertexB[6];
            dimB = 2;
            return NEXT_IS_EDGE_EDGE;
        }
        }

        if (dot0Sqrd > dot1Sqrd)
        {
            swap16(vertexA[0], vertexA[1]);
            swap16(vertexA[4], vertexA[5]);
        }

        int maskT = ComputeTriangleBarycentricTerms(vertexA[0], vertexB, m_pSupport);

        if (maskT == VComp::MASK_XYZ)
        {
            dimA = 1;
            return NEXT_IS_BREAK;
        }
        goto checkEdges;
    }

    {
        Vec4 oldDots = m_pCachedPoint;
        {
            Vec4 va0;
            va0.setSub4(vertexA[0], vertexB[0]);
            Vec4 va1;
            va1.setSub4(vertexA[1], vertexB[0]);

            SReal dot0 = m_pSupport.dot3(va0);
            SReal dot1 = m_pSupport.dot3(va1);

            if (isNeg(dot0 * dot1))
            {
                SReal a = dot0 / (dot0 - dot1);
                Vec4 pointOnSurface;
                pointOnSurface.setInterpolate4(vertexA[0], vertexA[1], a);
                if (isPointInTriangle(pointOnSurface, vertexB))
                {
                    return NEXT_IS_PENETRATION;
                }
            }
        }

        int maskT = checkTri0(vertexA[1], vertexB, m_pSupport);
        if (maskT == VComp::MASK_XYZ)
        {
            dimA = 1;
            vertexA[0] = vertexA[1];
            vertexA[4] = vertexA[5];
            m_eSupportState = SupportState(supportType);
            return NEXT_IS_BREAK;
        }
        dimB = 2;

        if (maskT == VComp::MASK_YZ)
        {
            goto remove_b0;
        }
        if (maskT == VComp::MASK_XZ)
        {
            goto remove_b1;
        }
        if (maskT == VComp::MASK_XY)
        {
            goto remove_b2;
        }

        if (maskT == VComp::MASK_X)
        {
            SReal oldDot0 = oldDots.getSimdAt(1);
            SReal oldDot1 = oldDots.getSimdAt(2);
            SReal d0 = m_pCachedPoint.getSimdAt(1) - oldDot0;
            SReal d1 = m_pCachedPoint.getSimdAt(2) - oldDot1;
            if (oldDot1 * d0 > oldDot0 * d1)
            {
                goto remove_b2;
            }
            else
            {
                goto remove_b1;
            }
        }
        if (maskT == VComp::MASK_Y)
        {
            SReal oldDot0 = oldDots.getSimdAt(2);
            SReal oldDot1 = oldDots.getSimdAt(0);
            SReal d0 = m_pCachedPoint.getSimdAt(2) - oldDot0;
            SReal d1 = m_pCachedPoint.getSimdAt(0) - oldDot1;
            if (oldDot1 * d0 > oldDot0 * d1)
            {
                goto remove_b0;
            }
            else
            {
                goto remove_b2;
            }
        }
        if (maskT == VComp::MASK_Z)
        {
            SReal oldDot0 = oldDots.getSimdAt(0);
            SReal oldDot1 = oldDots.getSimdAt(1);
            SReal d0 = m_pCachedPoint.getSimdAt(0) - oldDot0;
            SReal d1 = m_pCachedPoint.getSimdAt(1) - oldDot1;
            if (oldDot1 * d0 > oldDot0 * d1)
            {
                goto remove_b1;
            }
        }

    remove_b0:
        vertexB[0] = vertexB[2];
        vertexB[4] = vertexB[6];
        return NEXT_IS_EDGE_EDGE;
    remove_b1:
        vertexB[1] = vertexB[2];
        vertexB[5] = vertexB[6];
    remove_b2:
        return NEXT_IS_EDGE_EDGE;
    }
}

Gsk::ReduceDimensionResult Gsk::reduceDimension(Pad<int>& dimA, Pad<int>& dimB, Vec4& support)
{
    m_eSupportState = SUPPORT_CHANGED;
    while (1)
    {
        switch ((dimA << 3) | dimB)
        {
        case GSK_POINT_POINT:
        case_point_point:
            m_pSupport.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
            break;

        case GSK_POINT_EDGE:
        case_point_edge:
            dimB = process_point_edge(m_akPackedVerticesA, m_akCachedVectors, dimB, m_pSupport, BUILD_POS_SUPPORT);
            break;

        case GSK_EDGE_POINT:
        case_edge_point:
            dimA = process_point_edge(m_akCachedVectors, m_akPackedVerticesA, dimA, m_pSupport, BUILD_NEG_SUPPORT);
            break;

        case GSK_POINT_TRIANGLE:
        case_point_triangle: {
            int mask = ComputeTriangleBarycentricTerms(m_akPackedVerticesA[0], m_akCachedVectors, m_pSupport);
            if (mask == VComp::MASK_XYZ)
            {
                break;
            }
            int CI = DAT_010ececc[mask];
            dimB = 2;
            if (CI < 0)
            {
                CI += 8;
                CI &= 3;
                m_akCachedVectors[CI] = m_akCachedVectors[2];
                m_akPackedVerticesB[CI] = m_akPackedVerticesB[2];
                goto case_point_edge;
            }
            int LI = DAT_010eced4[CI];
            int UI = DAT_010eced4[CI + 2];

            Vec4 diff;
            diff.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[CI]);
            Vec4 ledge;
            ledge.setSub4(m_akCachedVectors[LI], m_akCachedVectors[CI]);
            Vec4 uedge;
            uedge.setSub4(m_akCachedVectors[UI], m_akCachedVectors[CI]);

            if (isNeg(diff.dot3(ledge)))
            {
                Vec4 hA = m_akCachedVectors[2];
                Vec4 hB = m_akPackedVerticesB[2];
                m_akCachedVectors[LI] = hA;
                m_akPackedVerticesB[LI] = hB;
                if (isNeg(diff.dot3(uedge)))
                {
                    if (UI == dimB)
                    {
                        UI = LI;
                    }
                    dimB = 1;
                    hA = m_akCachedVectors[1];
                    hB = m_akPackedVerticesB[1];
                    m_akCachedVectors[UI] = hA;
                    m_akPackedVerticesB[UI] = hB;
                    goto case_point_point;
                }
            }
            else
            {
                Vec4 hA = m_akCachedVectors[2];
                Vec4 hB = m_akPackedVerticesB[2];
                m_akCachedVectors[UI] = hA;
                m_akPackedVerticesB[UI] = hB;
            }
        }
            goto case_point_edge;

        case GSK_TRIANGLE_POINT:
        case_triangle_point: {
            int mask = ComputeTriangleBarycentricTerms(m_akCachedVectors[0], m_akPackedVerticesA, m_pSupport);
            if (mask == VComp::MASK_XYZ)
            {
                break;
            }
            int CI = DAT_010ececc[mask];
            dimA = 2;
            if (CI < 0)
            {
                CI += 8;
                CI &= 3;
                m_akPackedVerticesA[CI] = m_akPackedVerticesA[2];
                goto case_edge_point;
            }
            int LI = DAT_010eced4[CI];
            int UI = DAT_010eced4[CI + 2];

            Vec4 diff;
            diff.setSub4(m_akCachedVectors[0], m_akPackedVerticesA[CI]);
            Vec4 ledge;
            ledge.setSub4(m_akPackedVerticesA[LI], m_akPackedVerticesA[CI]);
            Vec4 uedge;
            uedge.setSub4(m_akPackedVerticesA[UI], m_akPackedVerticesA[CI]);

            if (isNeg(diff.dot3(ledge)))
            {
                m_akPackedVerticesA[LI] = m_akPackedVerticesA[2];
                if (isNeg(diff.dot3(uedge)))
                {
                    if (UI == dimA)
                    {
                        UI = LI;
                    }
                    dimA = 1;
                    m_akPackedVerticesA[UI] = m_akPackedVerticesA[1];
                    goto case_point_point;
                }
            }
            else
            {
                m_akPackedVerticesA[UI] = m_akPackedVerticesA[2];
            }
        }
            goto case_edge_point;

        case GSK_EDGE_TRIANGLE: {
            NextCase nextcase =
                ProcessAndReturnValue_00e4bbe0(m_akPackedVerticesA, m_akCachedVectors, dimA, dimB, m_iCacheState == 2, BUILD_POS_SUPPORT);
            switch (nextcase)
            {
            case NEXT_IS_EDGE_EDGE:
                goto case_edge_edge;
            case NEXT_IS_PENETRATION:
                goto penetration;
            }
        }
        break;

        case GSK_TRIANGLE_EDGE: {
            NextCase nextcase =
                ProcessAndReturnValue_00e4bbe0(m_akCachedVectors, m_akPackedVerticesA, dimB, dimA, m_iCacheState == 2, BUILD_NEG_SUPPORT);
            switch (nextcase)
            {
            case NEXT_IS_EDGE_EDGE:
                goto case_edge_edge;
            case NEXT_IS_PENETRATION:
                goto penetration;
            }
        }
        break;

        case GSK_EDGE_EDGE:
        case_edge_edge: {
            Vec4 a0 = m_akPackedVerticesA[0];
            Vec4 a1 = m_akPackedVerticesA[1];
            Vec4 b0 = m_akCachedVectors[0];
            Vec4 b1 = m_akCachedVectors[1];
            Vec4 edgeA;
            edgeA.setSub4(a1, a0);
            Vec4 edgeB;
            edgeB.setSub4(b1, b0);

            m_pSupport.setCross(edgeA, edgeB);
            Vec4 planeB;
            planeB.setCross(m_pSupport, edgeA);
            Vec4 planeA;
            planeA.setCross(m_pSupport, edgeB);

            Vec4 a0minusB0;
            a0minusB0.setSub4(a0, b0);
            Vec4 b1minusA0;
            b1minusA0.setSub4(b1, a0);
            Vec4 b0minusA1;
            b0minusA1.setSub4(b0, a1);

            Vec4 dots;
            VUtil::dot3_4vs4(a0minusB0, planeA, b0minusA1, planeA, a0minusB0, planeB, b1minusA0, planeB, dots);
            Vec4 zero;
            zero.setZero4();
            VComp comp = dots.compareGreaterThan4(zero);

            if (comp.allAreSet())
            {
                SReal a = dots.getSimdAt(0);
                SReal b = dots.getSimdAt(1);
                SReal r = a / (a + b);
                m_kVectorPairResult.m_kFirstVector.setInterpolate4(a0, a1, r);
                {
                    Vec4 sign;
                    sign.getQuad() = m_pSupport.dot3(a0minusB0).broadcast();
                    VUtil::mulSigns4(m_pSupport, sign);
                }
                break;
            }

            int mask = comp.GetLaneMask();
            switch (mask)
            {
            case VComp::MASK_XZW:
                m_akPackedVerticesA[0] = m_akPackedVerticesA[1];
            case VComp::MASK_YZW:
                dimA = 1;
                goto case_point_edge;
            case VComp::MASK_XYZ:
                m_akCachedVectors[0] = m_akCachedVectors[1];
                m_akPackedVerticesB[0] = m_akPackedVerticesB[1];
            case VComp::MASK_XYW:
                dimB = 1;
                goto case_edge_point;
            }

            int result = SegUtil::hkLineSegmentUtil_closestLineSegLineSeg(a0, edgeA, b0, edgeB, m_kVectorPairResult);
            if (result == 0)
            {
                {
                    Vec4 sign;
                    sign.getQuad() = m_pSupport.dot3(a0minusB0).broadcast();
                    VUtil::mulSigns4(m_pSupport, sign);
                }
                break;
            }

            if (result & SegUtil::CLSLS_POINTA_START)
            {
                Vec4 v1 = m_akPackedVerticesA[1];
                m_akPackedVerticesA[0] = v1;
                dimA = 1;
            }
            else if (result & SegUtil::CLSLS_POINTA_END)
            {
                dimA = 1;
            }

            if (result & SegUtil::CLSLS_POINTB_START)
            {
                Vec4 v1 = m_akCachedVectors[1];
                m_akCachedVectors[0] = v1;
                m_akPackedVerticesB[0] = m_akPackedVerticesB[1];
                dimB = 1;
            }
            else if (result & SegUtil::CLSLS_POINTB_END)
            {
                dimB = 1;
            }
        }
            continue;

        case GSK_POINT_TETRA: {
            int maxIndex = Runtime_ProcessEntries_00e4b810(m_akPackedVerticesA[0], m_akCachedVectors, 1.0f);
            if (maxIndex >= 0)
            {
                dimB = dimB - 1;
                m_akCachedVectors[maxIndex] = m_akCachedVectors[3];
                m_akPackedVerticesB[maxIndex] = m_akPackedVerticesB[3];
                goto case_point_triangle;
            }
        }
            goto penetration;

        case GSK_TETRA_POINT: {
            int maxIndex = Runtime_ProcessEntries_00e4b810(m_akCachedVectors[0], m_akPackedVerticesA, -1.0f);
            if (maxIndex >= 0)
            {
                dimA = dimA - 1;
                m_akPackedVerticesA[maxIndex] = m_akPackedVerticesA[3];
                goto case_triangle_point;
            }
        }
            goto penetration;

        case GSK_NONE_NONE:

        default:
        penetration:
            return REDUCE_DIMENSION_PENETRATION;
        }
        break;
    }
    m_iCacheState = dimB;
    return REDUCE_DIMENSION_OK;
}

// src: GUESS 0x00e4c230 (confidence: low)
void Gsk::ProcessEntries_00e4c230(const GskShape* shapeA, const GskShape* shapeB, const Xform& aTb, Pad<int>& dimA, Pad<int>& dimB,
                       GskOut& output)
{
    int simplexSize = 4;

    if (dimB >= 3)
    {
        if (dimB > 3)
        {
            m_akPackedVerticesA[3] = m_akPackedVerticesA[0];
        }
        else if (dimA > 1)
        {
            m_akPackedVerticesA[3] = m_akPackedVerticesA[1];
            m_akPackedVerticesB[3] = m_akPackedVerticesB[0];
            m_akCachedVectors[3] = m_akCachedVectors[0];
        }
        else
        {
            simplexSize = 3;
        }
        m_akPackedVerticesA[1] = m_akPackedVerticesA[0];
        m_akPackedVerticesA[2] = m_akPackedVerticesA[0];
    }
    else if (dimA >= 3)
    {
        if (dimA > 3)
        {
            m_akPackedVerticesB[3] = m_akPackedVerticesB[0];
            m_akCachedVectors[3] = m_akCachedVectors[0];
        }
        else if (dimB > 1)
        {
            m_akPackedVerticesA[3] = m_akPackedVerticesA[0];
            m_akPackedVerticesB[3] = m_akPackedVerticesB[1];
            m_akCachedVectors[3] = m_akCachedVectors[1];
        }
        else
        {
            simplexSize = 3;
        }
        m_akPackedVerticesB[1] = m_akPackedVerticesB[0];
        m_akCachedVectors[1] = m_akCachedVectors[0];
        m_akPackedVerticesB[2] = m_akPackedVerticesB[0];
        m_akCachedVectors[2] = m_akCachedVectors[0];
    }
    else
    {
        Vec4 vertA = m_akPackedVerticesA[0];
        m_akPackedVerticesA[dimA] = vertA;
        m_akPackedVerticesA[dimA + 1] = vertA;
        Vec4 vertBB = m_akPackedVerticesB[0];
        m_akPackedVerticesB[dimB] = vertBB;
        m_akPackedVerticesB[dimB + 1] = vertBB;
        Vec4 vertBA = m_akCachedVectors[0];
        m_akCachedVectors[dimB] = vertBA;
        m_akCachedVectors[dimB + 1] = vertBA;
        simplexSize = 1;
    }

    Vec4 simplex[4];
    simplex[0].setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
    simplex[1].setSub4(m_akPackedVerticesA[1], m_akCachedVectors[1]);
    simplex[2].setSub4(m_akPackedVerticesA[2], m_akCachedVectors[2]);
    simplex[3].setSub4(m_akPackedVerticesA[3], m_akCachedVectors[3]);

    PenUtil penDepth;
    penDepth.init(shapeA, shapeB, aTb, 0.0001f, m_akPackedVerticesA, m_akPackedVerticesB, simplex, simplexSize);
    GskStatus status = penDepth.ComputePenetration(output);
    if (status == GSK_PD_UNSOLVABLE)
    {
        heuristicSampling(shapeA, shapeB, aTb, m_akPackedVerticesA, m_akPackedVerticesB, output);
        status = GSK_PD_HEURISTIC_SAMPLING;
        dimA = 1;
        dimB = 1;
    }
    else
    {
        dimA = 3;
        dimB = 3;

        if (m_akPackedVerticesA[1].getInt24W() == m_akPackedVerticesA[2].getInt24W())
        {
            dimA = dimA - 1;
        }
        else if (m_akPackedVerticesA[0].getInt24W() == m_akPackedVerticesA[2].getInt24W())
        {
            dimA = dimA - 1;
        }
        if (dimA >= 2 && m_akPackedVerticesA[0].getInt24W() == m_akPackedVerticesA[1].getInt24W())
        {
            dimA = dimA - 1;
            m_akPackedVerticesA[0] = m_akPackedVerticesA[dimA];
        }

        if (m_akPackedVerticesB[1].getInt24W() == m_akPackedVerticesB[2].getInt24W())
        {
            dimB = dimB - 1;
        }
        else if (m_akPackedVerticesB[0].getInt24W() == m_akPackedVerticesB[2].getInt24W())
        {
            dimB = dimB - 1;
        }
        if (dimB >= 2 && m_akPackedVerticesB[0].getInt24W() == m_akPackedVerticesB[1].getInt24W())
        {
            dimB = dimB - 1;
            m_akPackedVerticesB[0] = m_akPackedVerticesB[dimB];
        }

        VUtil::TransformPointArray(aTb, m_akPackedVerticesB, dimB, m_akCachedVectors);

        if (dimA + dimB > 4)
        {
            if (dimA > dimB)
            {
                dimA = 3;
                dimB = 1;
            }
            else
            {
                dimB = 3;
                dimA = 1;
            }
        }
    }

    m_pSupport = output.m_vPointOnShapeA;
}

// @fnv 0x00e4c730
// src: XBOX_PDB 0x00e4c730
GskStatus Gsk::hkGsk_getClosestPoint(const Input& input, GskCache* __restrict cache, GskOut& output)
{
    const GskShape* shapeA = input.m_pShapeA;
    const GskShape* shapeB = input.m_pShapeB;

    Pad<int> dimA;
    Pad<int> dimB;

    if (cache)
    {
        int dimAb = cache->m_ucVertexCount;
        dimB = dimAb & 0xf;
        dimA = dimAb >> 4;

        shapeB->GetVerticesForIds(cache->m_ausVertexIds + dimA, dimB, &m_akPackedVerticesB[0]);
        shapeA->GetVerticesForIds(cache->m_ausVertexIds, dimA, &m_akPackedVerticesA[0]);
        VUtil::TransformPointArray(input.m_kTransform, &m_akPackedVerticesB[0], dimB, &m_akCachedVectors[0]);
    }
    else
    {
        dimA = 1;
        dimB = 1;
        Vec4 dir;
        dir.set(1.0f, 0.0f, 0.0f, 0.0f);
        Vec4 dirNeg;
        dirNeg.setNeg4(dir);
        dirNeg.hkVector4_setRotatedInverseDir(input.m_kTransform.getRotation(), dirNeg);
        shapeA->GetSupportPoint(dir, &m_akPackedVerticesA[0]);
        shapeB->GetSupportPoint(dirNeg, &m_akPackedVerticesB[0]);
        m_akCachedVectors[0].hkVector4_setRotatedDir(input.m_kTransform.getRotation(), m_akPackedVerticesB[0]);
    }

    SReal terminationEps = 1e-5f;
    GskStatus result = GSK_OK;
    while (1)
    {
        terminationEps = terminationEps * SReal(1.4f);
        int dim = dimA + dimB;
        ReduceDimensionResult reduceDimensionResult = reduceDimension(dimA, dimB, m_pSupport);

        m_iFeatureChange = m_iFeatureChange | (dimA + dimB - dim);

        {
            SReal supportLengthSquared = m_pSupport.normalizeWithLength3();
            Vec4 diff;
            diff.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
            SReal distUnscaled = diff.dot3(m_pSupport);

            if (reduceDimensionResult != REDUCE_DIMENSION_OK || distUnscaled < terminationEps ||
                supportLengthSquared < terminationEps * terminationEps)
            {
                m_iFeatureChange = 1;

                if (!m_uiCacheFlags.val())
                {
                    ProcessEntries_00e4c230(shapeA, shapeB, input.m_kTransform, dimA, dimB, output);
                    result = GSK_OK;
                }
                else
                {
                    if (dimA + dimB > 4)
                    {
                        if (dimA > dimB)
                        {
                            dimA = 3;
                            dimB = 1;
                        }
                        else
                        {
                            dimA = 1;
                            dimB = 3;
                        }
                    }
                    result = GSK_PENETRATING;
                }
                goto END_AND_EXPORT_CACHE;
            }
        }

        Vec4 supportA;
        supportA.setNeg4(m_pSupport);
        Vec4 supportB;
        supportB.rotInvDir(input.m_kTransform.getRotation(), m_pSupport);

        Vec4 newVertexA;
        shapeA->GetSupportPoint(supportA, &newVertexA);
        Vec4 newVertexBinB;
        shapeB->GetSupportPoint(supportB, &newVertexBinB);

        Vec4& newVertexBinA = m_akCachedVectors[dimB];
        newVertexBinA.xformPos(input.m_kTransform, newVertexBinB);

        {
            Vec4 ref;
            ref.set(input.m_fBlendWeight, terminationEps, terminationEps, terminationEps);
            Vec4 eps4;
            eps4.SetAllComponents(terminationEps);
            Vec4 diff;
            diff.setSub4(newVertexA, newVertexBinA);
            Vec4 diffA0;
            diffA0.setSub4(newVertexA, m_akPackedVerticesA[0]);
            Vec4 diffA1;
            diffA1.setSub4(newVertexA, m_akPackedVerticesA[1]);
            Vec4 diffA2;
            diffA2.setSub4(newVertexA, m_akPackedVerticesA[2]);
            Vec4 diffB0;
            diffB0.setSub4(newVertexBinB, m_akPackedVerticesB[0]);
            Vec4 diffB1;
            diffB1.setSub4(newVertexBinB, m_akPackedVerticesB[1]);
            Vec4 diffB2;
            diffB2.setSub4(newVertexBinB, m_akPackedVerticesB[2]);
            Vec4 dots;
            VUtil::dot3_3vs3(m_pSupport, diff, supportA, diffA0, supportB, diffB0, dots);
            Vec4 dots2;
            VUtil::dot3_4vs4(supportA, diffA1, supportA, diffA2, supportB, diffB1, supportB, diffB2, dots2);

            VComp c = dots.compareGreaterThan4(ref);
            VComp shouldIgnore = dots2.compareLessThan4(eps4);
            int mask = c.GetLaneMask(VComp::MASK_XYZ);

            switch (mask)
            {
            default:
                break;

            case VComp::MASK_X:
            case VComp::MASK_XY:
            case VComp::MASK_XZ:
            case VComp::MASK_XYZ:
                result = GSK_PD_DISTANCE_TOO_BIG;
                goto END_AND_EXPORT_CACHE;

            case VComp::MASK_YZ:
                if (dots.getSimdAt(2) < dots.getSimdAt(1))
                {
                    goto CASE_B;
                }

            case VComp::MASK_Y: {
                if (!shouldIgnore.anyIsSet(DAT_010ec600[dimA]))
                {
                    m_akPackedVerticesA[dimA] = newVertexA;
                    dimA = dimA + 1;
                    m_iFeatureChange = 1;
                    continue;
                }
                break;
            }

            case VComp::MASK_Z:
            CASE_B: {
                if (!shouldIgnore.anyIsSet(DAT_010ec5f0[dimB]))
                {
                    m_akPackedVerticesB[dimB] = newVertexBinB;
                    dimB = dimB + 1;
                    m_iFeatureChange = 1;
                    continue;
                }
                break;
            }
            }
        }

        break;
    }

    {
        Vec4 diff;
        diff.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
        Vec4 normalInA;
        normalInA = m_pSupport;
        SReal dist = diff.dot3(normalInA);
        normalInA.set(normalInA.getSimdAt(0), normalInA.getSimdAt(1), normalInA.getSimdAt(2), dist);
        output.m_vPointOnShapeA = normalInA;
        m_pSupport = normalInA;

        Vec4 pointAinA;
        if (dimA == 1)
        {
            pointAinA = m_akPackedVerticesA[0];
        }
        else if (dimB == 1)
        {
            pointAinA.setAddMul4(m_akCachedVectors[0], normalInA, dist);
        }
        else
        {
            pointAinA = m_kVectorPairResult.m_kFirstVector;
        }
        output.m_vPointOnShapeB = pointAinA;
    }

END_AND_EXPORT_CACHE:

    if (cache)
    {
        cache->m_ausVertexIds[0] = UChar(m_akPackedVerticesA[0].getInt24W());
        cache->m_ausVertexIds[1] = UChar(m_akPackedVerticesA[1].getInt24W());
        cache->m_ausVertexIds[2] = UChar(m_akPackedVerticesA[2].getInt24W());
        cache->m_ausVertexIds[dimA + 0] = UChar(m_akPackedVerticesB[0].getInt24W());
        cache->m_ausVertexIds[dimA + 1] = UChar(m_akPackedVerticesB[1].getInt24W());
        cache->m_ausVertexIds[dimA + 2] = UChar(m_akPackedVerticesB[2].getInt24W());
        cache->m_ucVertexCount = UChar((dimA << 4) | dimB);
    }

    return result;
}
