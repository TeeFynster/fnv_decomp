typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#include "../../../../../../../include/hkArrayBase.h"

// src/havok/physics/collide/shape/heightfield/compressedsampledheightfield/hkpcompressedsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/compressedsampledheightfield/hkpcompressedsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCompressedSampledHeightFieldShape.h"

// @fnv 0x00e49510
// src: HAVOK_LIB 0x00e49510
int __stdcall hkpCompressedSampledHeightFieldShape_calcSizeForSpu_00e49510(int a, int b)
{
    int r = (b >= 0x80) ? 1 : 0;
    r = r - 1;
    r = r & 0xffffff7f;
    return r + 0x80;
}

// Exe 0x00e49530 Collide: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_set_ss(float);
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" void _mm_store_ps(float*, LocalM128);

struct HfVec_e49530
{
    LocalM128 m_vComponents;
    __forceinline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setMul4(const HfVec_e49530& a, const HfVec_e49530& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const HfVec_e49530& a, const HfVec_e49530& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setSub4(const HfVec_e49530& a, const HfVec_e49530& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const HfVec_e49530& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void add4(const HfVec_e49530& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline float dot3(const HfVec_e49530& a) const
    {
        LocalM128 t = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 s = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
    __forceinline void normalize3()
    {
        LocalM128 t = _mm_mul_ps(m_vComponents, m_vComponents);
        LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t));
        LocalM128 r = _mm_rsqrt_ss(len2);
        LocalM128 eq = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
        LocalM128 f = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, r), r)));
        f = _mm_andnot_ps(eq, f);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(f, f, 0), m_vComponents);
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};

extern const HfVec_e49530 DAT_011b1bd0;

struct HfInput_e49530
{
    HfVec_e49530* m_kSpheres;
    int m_iSphereCount;
};
typedef hkBool HfBool_e49530;

static inline const HfVec_e49530& HfQ_e49530(const hkVector4& v)
{
    return reinterpret_cast<const HfVec_e49530&>(v);
}

class HfShape_e49530 : public hkpSampledHeightFieldShape
{
  public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual float GetHeightAtGridPoint(int x, int z) const;
    virtual HfBool_e49530 IsTriangleWindingFlipped() const;

    void Collide(const HfInput_e49530& input, HfVec_e49530* outputArray) const;
};

static __forceinline void HfCollide_e49530(const HfShape_e49530& hf, const HfInput_e49530& input,
                                           HfVec_e49530* outputArray)
{
    HfVec_e49530* sphere = input.m_kSpheres;
    HfVec_e49530 defaultOut;
    defaultOut.set(0.0f, 1.0f, 0.0f, 3.40282e+38f);
    for (int i = input.m_iSphereCount - 1; i >= 0; sphere++, outputArray++, i--)
    {
        HfVec_e49530& output = *outputArray;
        output.m_vComponents = defaultOut.m_vComponents;

        const HfVec_e49530& scale = HfQ_e49530(hf.m_kInverseScale);
        HfVec_e49530 sc;
        sc.m_vComponents = scale.m_vComponents;
        const HfVec_e49530& pos = *sphere;
        HfVec_e49530 localPos;
        localPos.setMul4(pos, sc);
        union
        {
            HfVec_e49530 v;
            unsigned int u[4];
        } fc;
        fc.v.setAdd4(pos, HfQ_e49530(hf.m_kOffset));
        fc.v.mul4(sc);
        fc.v.add4(DAT_011b1bd0);
        struct
        {
            unsigned short a, b, c, d;
        } out;
        out.a = (unsigned short)(fc.u[0] >> 6);
        out.c = (unsigned short)(fc.u[2] >> 6);
        int x = out.a;
        int z = out.c;

        if (x >= hf.m_iXResolution - 1 || z >= hf.m_iZResolution - 1)
        {
            continue;
        }

        float subX = localPos(0) - x;
        float subZ = localPos(2) - z;

        float height;
        int cornerX;
        float cornerH;
        HfBool_e49530 flip = hf.IsTriangleWindingFlipped();
        if (flip.m_cBooleanValue)
        {
            float h00 = hf.GetHeightAtGridPoint(x, z);
            cornerH = h00;
            cornerX = x;
            float h11 = hf.GetHeightAtGridPoint(x + 1, z + 1);
            if (subX > subZ)
            {
                float h10 = hf.GetHeightAtGridPoint(x + 1, z);
                float dx = h10 - h00;
                float dz = h11 - h10;
                height = h00 + dz * subZ + dx * subX;
                output(0) = -dx;
                output(2) = -dz;
            }
            else
            {
                float h01 = hf.GetHeightAtGridPoint(x, z + 1);
                float dx = h11 - h01;
                float dz = h01 - h00;
                height = h00 + dz * subZ + dx * subX;
                output(0) = -dx;
                output(2) = -dz;
            }
        }
        else
        {
            float h10 = hf.GetHeightAtGridPoint(x + 1, z);
            cornerH = h10;
            cornerX = x + 1;
            float h01 = hf.GetHeightAtGridPoint(x, z + 1);
            if (subZ + subX > 1.0)
            {
                float h11 = hf.GetHeightAtGridPoint(x + 1, z + 1);
                float dx = h11 - h01;
                float dz = h11 - h10;
                height = h10 + dz * subZ + dx * (subX - 1.0);
                output(0) = -dx;
                output(2) = -dz;
            }
            else
            {
                float h00 = hf.GetHeightAtGridPoint(x, z);
                float dx = h10 - h00;
                float dz = h01 - h00;
                height = h00 + dz * subZ + dx * subX;
                output(0) = -dx;
                output(2) = -dz;
            }
        }

        output.setMul4(scale, output);
        HfVec_e49530 normal;
        normal.m_vComponents = output.m_vComponents;
        normal.normalize3();
        _mm_store_ps(&output(0), normal.m_vComponents);

        float dist;
        if (!hf.m_bUseProjectionBasedHeight)
        {
            dist = (localPos(1) - height) * hf.m_kHeightScaleVector.y - (*sphere)(3);
        }
        else
        {
            HfVec_e49530 corner;
            corner.set((float)cornerX, cornerH, (float)z, 0.0f);
            HfVec_e49530 d;
            d.setSub4(localPos, corner);
            d.mul4(HfQ_e49530(hf.m_kHeightScaleVector));
            dist = d.dot3(normal) - (*sphere)(3);
        }
        output(3) = dist;
    }
}

// Delegates sphere-vs-heightfield collision to HfCollide_e49530, writing per-sphere contact results into outputArray.
// @fnv 0x00e49530
void HfShape_e49530::Collide(const HfInput_e49530& input, HfVec_e49530* outputArray) const
{
    HfCollide_e49530(*this, input, outputArray);
}

extern "C" void* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl hkArrayUtil__reserve(void* alloc, void* array, int capacity, int elemSize);
extern int DAT_010e901c;

struct hkBoolR_e499
{
    char m_cBooleanValue;
    hkBoolR_e499()
    {}
    operator char() const
    {
        return m_cBooleanValue;
    }
};

class HfSrc_e499 : public hkpSampledHeightFieldShape
{
  public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual float GetHeightAtGridPoint(int x, int z) const;
    virtual hkBool IsTriangleWindingFlipped() const;
};

struct Alloc_e499;
struct Holder_e499
{
    int pad[4];
    Alloc_e499* m_alloc;
};

static __forceinline void Arr16_e499_GrowArrayCapacity(hkArrayBase<hkUint16>& self, Alloc_e499& a, int n)
{
        int cap = self.getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&a, (&self), newSize, sizeof(hkUint16));
        }
    }

static __forceinline void Arr16_e499__setSize(hkArrayBase<hkUint16>& self, Alloc_e499& a, int n)
{
        Arr16_e499_GrowArrayCapacity(self, a, n);
        self.m_iElementCount = n;
    }

static __forceinline void Arr16_e499_reserve(hkArrayBase<hkUint16>& self, int n)
{
        Holder_e499* h = (Holder_e499*)hkMemoryRouter_getInstance();
        Alloc_e499* alloc = h->m_alloc;
        int c = self.m_iCapacityState & 0x3fffffff;
        if (c < n)
        {
            c = c * 2;
            hkArrayUtil__reserve(alloc, (&self), n < c ? c : n, 2);
        }
    }

static __forceinline void Arr16_e499_SetSizeAndGrow(hkArrayBase<hkUint16>& self, int n)
{
        Arr16_e499_reserve(self, n);
        self.m_iElementCount = n;
    }

class Compressed_e499 : public hkpCompressedSampledHeightFieldShape
{
  public:
    Compressed_e499* InitializeFields_00e499d0(const HfSrc_e499* hf);
};

// Initializes a compressed heightfield from a source heightfield by copying parameters, computing height range, and storing scaled 16-bit heights.
// @fnv 0x00e499d0
// src: GUESS 0x00e499d0 (confidence: low)
Compressed_e499* Compressed_e499::InitializeFields_00e499d0(const HfSrc_e499* apSourceHeightField)
{
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    m_type = (hkpShapeType)0xd;
    *(int**)this = &DAT_010e901c;
    hkArrayBase<hkUint16>& st = (hkArrayBase<hkUint16>&)m_kStorage;
    st.m_data = 0;
    st.m_iElementCount = 0;
    st.m_iCapacityState = 0x80000000;
    m_ucHeightFieldType = HEIGHTFIELD_COMPRESSED;
    m_iXResolution = apSourceHeightField->m_iXResolution;
    m_iZResolution = apSourceHeightField->m_iZResolution;
    {
        hkBool flip = apSourceHeightField->IsTriangleWindingFlipped();
        m_bFlipTriangleOrder.m_cBooleanValue = flip.m_cBooleanValue;
    }
    m_fHeightScale = apSourceHeightField->m_fHeightScale;
    *(LocalM128*)&m_kHeightScaleVector = *(const LocalM128*)&apSourceHeightField->m_kHeightScaleVector;
    *(LocalM128*)&m_kInverseScale = *(const LocalM128*)&apSourceHeightField->m_kInverseScale;
    *(LocalM128*)&m_kOffset = *(const LocalM128*)&apSourceHeightField->m_kOffset;
    *(LocalM128*)&SetCenterPosition = *(const LocalM128*)&apSourceHeightField->SetCenterPosition;

    Arr16_e499_SetSizeAndGrow(st, m_iXResolution * m_iZResolution);

    float fMinHeight = 3.40282e+38f;
    float maxv = -3.40282e+38f;
    for (int z = 0; z < m_iZResolution; z++)
    {
        for (int x = 0; x < m_iXResolution; x++)
        {
            float h = apSourceHeightField->GetHeightAtGridPoint(x, z);
            if (h < fMinHeight)
                fMinHeight = h;
            if (h > maxv)
                maxv = h;
        }
    }
    m_offset = fMinHeight;
    m_vScale = (float)((maxv - fMinHeight) / 65535.0);
    for (int z = 0; z < m_iZResolution; z++)
    {
        for (int x = 0; x < m_iXResolution; x++)
        {
            float h = apSourceHeightField->GetHeightAtGridPoint(x, z);
            m_kStorage.m_data[z * m_iXResolution + x] = (hkUint16)(int)((h - m_offset) / m_vScale);
        }
    }
    return this;
}
