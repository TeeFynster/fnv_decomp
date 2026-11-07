
// src/havok/common/visualize/shape/hkdisplaycylinder_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaycylinder_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/visualize/shape/hkdisplaycylinder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/shape/hkdisplaycylinder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
void __stdcall nullsub_78(int, int);
#include <xmmintrin.h>
struct DE1F50Vector4
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void operator=(const DE1F50Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct DE1F50Transform
{
    DE1F50Vector4 m_kColumn0;
    DE1F50Vector4 m_kColumn1;
    DE1F50Vector4 m_kColumn2;
    DE1F50Vector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};
class DE1F50ReferencedObject
{
  public:
    DE1F50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DE1F50Shape : public DE1F50ReferencedObject
{
  public:
    DE1F50Shape() : m_ulUserData(0), m_type(2)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE1F50Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de1f50 : public DE1F50Shape
{
  public:
    FUN_00de1f50(const DE1F50Vector4& v);
    virtual void unk00();

    DE1F50Vector4 m_vector;
};

extern "C" void _ReadWriteBarrier();
#include <math.h>
extern float DAT_010c7180[4], DAT_010c7190[4], DAT_010c71a0[4], DAT_010c71e0[4];
struct AllocObj
{
    virtual void v00();
    virtual void* v04(int);
};
struct Mgr
{
    int unk00, unk04, unk08, unk0c;
    AllocObj* m_10;
};
Mgr* hkMemoryRouter_getInstance();
int hkArrayUtil__reserve(void*, void*, int, int);
struct Quaternion;
class LaneScalar
{
    __m128 lane;

  public:
    LaneScalar()
    {}
    LaneScalar(const __m128& x) : lane(x)
    {}
    LaneScalar(float x) : lane(_mm_load_ss(&x))
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, lane);
        return f;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(lane, lane, 0);
    }
    __forceinline const __m128& raw() const
    {
        return lane;
    }
};
struct MathVector
{
  private:
    __m128 lanes;

  public:
    __forceinline MathVector()
    {}
    __forceinline MathVector(const MathVector& v) : lanes(v.lanes)
    {}
    __forceinline MathVector(const __m128& v) : lanes(v)
    {}
    __forceinline operator __m128() const
    {
        return lanes;
    }
    __forceinline void operator=(const MathVector& v)
    {
        lanes = v.lanes;
    }
    __forceinline void operator=(const __m128& v)
    {
        lanes = v;
    }
    __forceinline const __m128& raw() const
    {
        return lanes;
    }
    __forceinline float& at(int i)
    {
        return lanes.m128_f32[i];
    }
    __forceinline void subtract(const MathVector& a, const MathVector& b)
    {
        lanes = _mm_sub_ps(a.lanes, b.lanes);
    }
    __forceinline void cross(const MathVector& a, const MathVector& b)
    {
        __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.lanes, a.lanes, 0xc9), _mm_shuffle_ps(b.lanes, b.lanes, 0xd2));
        __m128 q = _mm_mul_ps(_mm_shuffle_ps(a.lanes, a.lanes, 0xd2), _mm_shuffle_ps(b.lanes, b.lanes, 0xc9));
        lanes = _mm_sub_ps(p, q);
    }

    __forceinline LaneScalar squared() const
    {
        __m128 p = _mm_mul_ps(lanes, lanes);
        __m128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), t);
    }
    __forceinline LaneScalar length() const
    {
        return _mm_sqrt_ss(squared().raw());
    }
    __forceinline LaneScalar inv() const
    {
        const __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        const __m128 d = squared().raw();
        const __m128 mask = _mm_cmpeq_ss(d, zero);
        const __m128 estimate = _mm_rsqrt_ss(d);
        __m128 factor =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(d, estimate), estimate)));
        return _mm_andnot_ps(mask, factor);
    }
    __forceinline void setMul4(const LaneScalar& s, const MathVector& a)
    {
        lanes = _mm_mul_ps(s.splat(), a.lanes);
    }
    __forceinline void add4(const MathVector& b)
    {
        lanes = _mm_add_ps(lanes, b.lanes);
    }
    __forceinline void setAdd4(const MathVector& a, const MathVector& b)
    {
        lanes = _mm_add_ps(a.lanes, b.lanes);
    }
    void SetRotatedDirection(const Quaternion& rotation, const MathVector& radial);
    __forceinline void normalize()
    {
        __m128 f = inv().splat();
        lanes = _mm_mul_ps(f, lanes);
    }
    __forceinline void multiply(const LaneScalar& s)
    {
        lanes = _mm_mul_ps(s.splat(), lanes);
    }
};
struct __declspec(align(16)) Quaternion
{
    float x, y, z, w;
    Quaternion()
    {}
    Quaternion(const MathVector& axis, float theta)
    {
        hkQuaternion_setAxisAngle(axis, theta);
    }
    __declspec(noinline) void hkQuaternion_setAxisAngle(const MathVector& axis, float theta);
    __declspec(noinline) void setMul(const Quaternion& a, const Quaternion& b);
};
// src: XBOX_PDB 0x00cb2450
__declspec(noinline) void Quaternion::hkQuaternion_setAxisAngle(const MathVector& axis, float angle)
{
    float h = (float)(angle * 0.5);
    float sn = (float)sin(h);
    *(MathVector*)this = _mm_mul_ps(_mm_set_ps1(sn), axis.raw());
    w = (float)cos(h);
}
// src: COMMUNITY 0x00c66320
__declspec(noinline) void Quaternion::setMul(const Quaternion& av, const Quaternion& bv)
{
    __m128 a = ((const MathVector*)&av)->raw();
    __m128 b = ((const MathVector*)&bv)->raw();
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    __m128 xyz = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
    __m128 ab = _mm_mul_ps(a, b);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0x55), ab);
    sum = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0xaa), sum);
    __m128 scalar = _mm_sub_ps(ab, _mm_shuffle_ps(sum, sum, 0));
    __m128 zw = _mm_unpackhi_ps(xyz, scalar);
    MathVector result;
    result = _mm_shuffle_ps(xyz, zw, 0xc4);
    *(MathVector*)this = result;
}

__forceinline void MathVector::SetRotatedDirection(const Quaternion& rotation, const MathVector& radial)
{
    __m128 q = ((const MathVector*)&rotation)->raw();
    __m128 lenSq = radial.raw();
    __m128 xmm0 = _mm_mul_ps(q, lenSq);
    __m128 xmm7 = _mm_add_ss(_mm_shuffle_ps(xmm0, xmm0, 0x55), xmm0);
    __m128 xmm3 = _mm_shuffle_ps(xmm0, xmm0, 0xaa);
    __m128 phase = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(lenSq, lenSq, 0xd2));
    __m128 cols = _mm_shuffle_ps(q, q, 0xff);
    __m128 cb = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(lenSq, lenSq, 0xc9));
    __m128 xmm5 = _mm_add_ps(_mm_mul_ps(cols, cols), *(const __m128*)DAT_010c71e0);
    phase = _mm_mul_ps(_mm_sub_ps(phase, cb), cols);
    xmm3 = _mm_add_ss(xmm3, xmm7);
    __m128 xmm2 = _mm_shuffle_ps(xmm3, xmm3, 0);
    xmm5 = _mm_mul_ps(xmm5, lenSq);
    xmm5 = _mm_add_ps(xmm5, _mm_mul_ps(xmm2, q));
    __m128 pt = _mm_add_ps(phase, xmm5);
    lanes = _mm_add_ps(pt, pt);
}
struct Face
{
    int a, b, c, material;
    inline void set(int p, int q, int r, int m = -1)
    {
        a = p;
        b = q;
        c = r;
        material = m;
    }
};
template <class T> struct List
{
    T* data;
    int size, capacity;
    List() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline T* expandBy(int amount)
    {
        Mgr* mgr = hkMemoryRouter_getInstance();
        void* allocator = mgr->m_10;
        int old = size;
        int need = old + amount;
        int cap = capacity & 0x3fffffff;
        if (cap < need)
        {
            int twice = cap + cap;
            int next = need < twice ? twice : need;
            hkArrayUtil__reserve(allocator, this, next, sizeof(T));
        }
        size += amount;
        return data + old;
    }
};
struct Geometry
{
    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    List<MathVector> vertices;
    List<Face> triangles;
};
struct CylinderMeshBuilder
{
    int unk00, unk04;
    Geometry* m_08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48,
        unk4c, unk50, unk54, unk58, unk5c;
    MathVector m_60, m_70;
    float m_80;
    int m_84, m_88;
};
static inline float AbsValue(float x)
{
    return (float)fabs((double)x);
}
struct AxisWork
{
    MathVector unit;
    Quaternion previous;
};
struct StepWork
{
    MathVector zxy;
    MathVector yzx;
    Quaternion delta;
};
struct CachePair
{
    MathVector yzx;
    Quaternion delta;
};
// @fnv 0x00d58590
// src: HAVOK_SRC 0x00d58590
__declspec(noinline) void __fastcall hkDisplayCylinder_buildGeometry(CylinderMeshBuilder* self)
{
    const int& heights = self->m_88;
    const int& sectors = self->m_84;
    {
        CachePair pair;
        MathVector segment;
        segment.subtract(self->m_60, self->m_70);
        float unusedHeight = segment.length();
        const MathVector& origin = self->m_70;
        MathVector step;
        step.subtract(self->m_60, self->m_70);
        step.multiply(float(1.0 / heights));
        AxisWork axisWork;
        MathVector& unit = axisWork.unit;
        unit = step;
        unit.normalize();
        MathVector radial;
        {
            MathVector basis;
            if (AbsValue(unit.at(0)) > 0.5)
                basis = *(const __m128*)DAT_010c7190;
            else if (AbsValue(unit.at(1)) > 0.5)
                basis = *(const __m128*)DAT_010c71a0;
            else
                basis = *(const __m128*)DAT_010c7180;
            radial.cross(unit, basis);
            radial.normalize();
            radial.multiply(self->m_80);
        }
        volatile MathVector zxyStorage;
        MathVector& zxy = const_cast<MathVector&>(zxyStorage);
        MathVector& yzx = pair.yzx;
        Quaternion& delta = pair.delta;
        delta.hkQuaternion_setAxisAngle(unit, float(double(6.28318548f) / sectors));
        Quaternion rotation(unit, 0.0f);
        Mgr* mgr = hkMemoryRouter_getInstance();
        void* allocation = mgr->m_10->v04(24);
        self->m_08 = allocation ? new (allocation) Geometry : 0;
        *self->m_08->vertices.expandBy(1) = origin;
        {
            MathVector end;
            end.setMul4(float(heights), step);
            end.add4(origin);
            *self->m_08->vertices.expandBy(1) = end;
        }
        int a = 0;
        if (sectors > 0)
        {
            yzx = _mm_shuffle_ps(radial.raw(), radial.raw(), 0xc9);
            zxy = _mm_shuffle_ps(radial.raw(), radial.raw(), 0xd2);
            do

            {
                MathVector point;
                {
                    MathVector rotated;

                    __m128 q = ((const MathVector*)&rotation)->raw();
                    __m128 lenSq = radial.raw();
                    __m128 xmm0 = _mm_mul_ps(q, lenSq);
                    __m128 xmm7 = _mm_add_ss(_mm_shuffle_ps(xmm0, xmm0, 0x55), xmm0);
                    __m128 xmm3 = _mm_shuffle_ps(xmm0, xmm0, 0xaa);
                    __m128 phase = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), zxy.raw());
                    __m128 cols = _mm_shuffle_ps(q, q, 0xff);
                    __m128 cb = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), yzx.raw());
                    __m128 xmm5 = _mm_add_ps(_mm_mul_ps(cols, cols), *(const __m128*)DAT_010c71e0);
                    phase = _mm_mul_ps(_mm_sub_ps(phase, cb), cols);
                    xmm3 = _mm_add_ss(xmm3, xmm7);
                    __m128 xmm2 = _mm_shuffle_ps(xmm3, xmm3, 0);
                    xmm5 = _mm_mul_ps(xmm5, lenSq);
                    xmm5 = _mm_add_ps(xmm5, _mm_mul_ps(xmm2, q));
                    __m128 pt = _mm_add_ps(phase, xmm5);
                    rotated = _mm_add_ps(pt, pt);

                    point.setAdd4(origin, rotated);
                }
                for (int h = 0; h < heights; ++h)
                {
                    *self->m_08->vertices.expandBy(1) = point;
                    point.add4(step);
                }
                *self->m_08->vertices.expandBy(1) = point;
                _ReadWriteBarrier();
                Quaternion& previous = axisWork.previous;
                previous = rotation;
                rotation.setMul(previous, delta);
                ++a;
            } while (a < sectors);
        }
    }
    {
        int stride = heights + 1;
        int limit = (heights + 1) * sectors + 2;
        int quad[4];
        quad[0] = 2;
        quad[1] = stride + 2;
        quad[2] = 3;
        quad[3] = stride + 3;
        int heightIndex = 0;
        for (int a = 0; a < sectors; ++a)
        {
            for (heightIndex = 0; heightIndex < heights; ++heightIndex)
            {
                self->m_08->triangles.expandBy(1)->set(quad[0], quad[1], quad[2]);
                self->m_08->triangles.expandBy(1)->set(quad[2], quad[1], quad[3]);
                ++quad[0];
                ++quad[1];
                ++quad[2];
                ++quad[3];
            }
            ++quad[0];
            ++quad[1];
            ++quad[2];
            ++quad[3];
            if (quad[3] >= limit)
            {
                quad[1] += 2 - limit;
                quad[3] += 2 - limit;
            }
        }
        for (heightIndex = 0; heightIndex < 2; ++heightIndex)
        {
            int start = (heightIndex ? heights : 0) + 2;
            for (int a = 0; a < sectors; ++a)
            {
                int next = start + stride;
                if (next >= limit)
                    next += 2 - limit;
                if (heightIndex)
                    self->m_08->triangles.expandBy(1)->set(heightIndex, start, next);
                else
                    self->m_08->triangles.expandBy(1)->set(0, next, start);
                start = next;
            }
        }
    }
}
