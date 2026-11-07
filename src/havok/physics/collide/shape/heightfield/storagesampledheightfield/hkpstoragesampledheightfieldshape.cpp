typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2

// src/havok/physics/collide/shape/heightfield/storagesampledheightfield/hkpstoragesampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/storagesampledheightfield/hkpstoragesampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStorageSampledHeightFieldShape.h"

// @fnv 0x00d496b0
// src: HAVOK_LIB 0x00d496b0
int __stdcall hkpCompressedSampledHeightFieldShape_calcSizeForSpu(int unused, int aiValue)
{
    int r = (aiValue >= 0x80);
    --r;
    r &= 0xffffff7f;
    r -= -0x80;
    return r;
}

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010cfb34;

struct FUN_00d496d0
{
    int vtbl;
    void SetVirtualTable_00d24660();
    ~FUN_00d496d0();
};

// @fnv 0x00d496d0
FUN_00d496d0::~FUN_00d496d0()
{
    *(void**)this = &DAT_010cfb34;
    if (*(char*)((char*)this + 0x70))
        Deallocate(*(void**)((char*)this + 0x60));
    SetVirtualTable_00d24660();
}

#pragma pack(push, 4)
struct FUN_00d248a0
{
    FUN_00d248a0(int resolution, int mode);
    virtual ~FUN_00d248a0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned long m_ulUserData;
    unsigned int m_iType;
    int m_xResolution;
    int m_zResolution;
    float m_fHeightScale;
    bool m_bUseProjectionBasedHeight;
    unsigned char m_ucHeightFieldType;
    unsigned char m_reserved1e;
    unsigned char m_reserved1f;
    float m_kHeightScaleVectorStorage[4];
    hkVector4& get_m_kHeightScaleVector() { return *reinterpret_cast<hkVector4*>(m_kHeightScaleVectorStorage); }
    __declspec(property(get=get_m_kHeightScaleVector)) hkVector4 m_kHeightScaleVector;
    float m_kInverseScaleStorage[4];
    hkVector4& get_m_kInverseScale() { return *reinterpret_cast<hkVector4*>(m_kInverseScaleStorage); }
    __declspec(property(get=get_m_kInverseScale)) hkVector4 m_kInverseScale;
    float m_kOffsetStorage[4];
    hkVector4& get_m_kOffset() { return *reinterpret_cast<hkVector4*>(m_kOffsetStorage); }
    __declspec(property(get=get_m_kOffset)) hkVector4 m_kOffset;
    float SetCenterPositionStorage[4];
    hkVector4& get_SetCenterPosition() { return *reinterpret_cast<hkVector4*>(SetCenterPositionStorage); }
    __declspec(property(get=get_SetCenterPosition)) hkVector4 SetCenterPosition;
};
#pragma pack(pop)
struct FUN_00d49700 : public FUN_00d248a0
{
    int* values;
    bool cleared;
    unsigned char unk65;
    unsigned char unk66;
    unsigned char unk67;
    int capacity;
    float scale;
    bool initialized;
    FUN_00d49700(int resolution, int* source, float value);
    virtual ~FUN_00d49700();
};
// Initializes the base with resolution and mode 0, then stores the source pointer, capacity (zResolution - 1) and scale, clearing the flags.
// @fnv 0x00d49700
FUN_00d49700::FUN_00d49700(int resolution, int* source, float value) : FUN_00d248a0(resolution, 0)
{
    const int& zResolution = m_zResolution;
    cleared = false;
    double convertedResolution(zResolution);
    initialized = false;
    int* inputValues = (int*)*source;
    values = inputValues;
    capacity = static_cast<int>(convertedResolution - 1.0);
    scale = value;
}

// Exe 0x00d49850 Collide: retain this LocalM128 view; the CRT type does not preserve this unit.
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

struct HfVec_d49850
{
    LocalM128 m_vComponents;
    __forceinline void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setMul4(const HfVec_d49850& a, const HfVec_d49850& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const HfVec_d49850& a, const HfVec_d49850& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setSub4(const HfVec_d49850& a, const HfVec_d49850& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(const HfVec_d49850& a)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void add4(const HfVec_d49850& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline float dot3(const HfVec_d49850& a) const
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

extern const HfVec_d49850 DAT_011b1bd0;

struct HfInput_d49850
{
    HfVec_d49850* m_kSpheres;
    int m_iSphereCount;
};
typedef hkBool HfBool_d49850;

static inline const HfVec_d49850& HfQ_d49850(const hkVector4& v)
{
    return reinterpret_cast<const HfVec_d49850&>(v);
}

class HfShape_d49850 : public hkpSampledHeightFieldShape
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
    virtual HfBool_d49850 IsTriangleWindingFlipped() const;

    void Collide(const HfInput_d49850& input, HfVec_d49850* outputArray) const;
};

static __forceinline void HfCollide_d49850(const HfShape_d49850& hf, const HfInput_d49850& input,
                                           HfVec_d49850* outputArray)
{
    HfVec_d49850* sphere = input.m_kSpheres;
    HfVec_d49850 defaultOut;
    defaultOut.set(0.0f, 1.0f, 0.0f, 3.40282e+38f);
    for (int i = input.m_iSphereCount - 1; i >= 0; sphere++, outputArray++, i--)
    {
        HfVec_d49850& output = *outputArray;
        output.m_vComponents = defaultOut.m_vComponents;

        const HfVec_d49850& scale = HfQ_d49850(hf.m_kInverseScale);
        HfVec_d49850 sc;
        sc.m_vComponents = scale.m_vComponents;
        const HfVec_d49850& pos = *sphere;
        HfVec_d49850 localPos;
        localPos.setMul4(pos, sc);
        union
        {
            HfVec_d49850 v;
            unsigned int u[4];
        } fc;
        fc.v.setAdd4(pos, HfQ_d49850(hf.m_kOffset));
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
        HfBool_d49850 flip = hf.IsTriangleWindingFlipped();
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
        HfVec_d49850 normal;
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
            HfVec_d49850 corner;
            corner.set((float)cornerX, cornerH, (float)z, 0.0f);
            HfVec_d49850 d;
            d.setSub4(localPos, corner);
            d.mul4(HfQ_d49850(hf.m_kHeightScaleVector));
            dist = d.dot3(normal) - (*sphere)(3);
        }
        output(3) = dist;
    }
}

// Delegates to HfCollide_d49850 to compute sphere-heightfield collision results into outputArray.
// @fnv 0x00d49850
void HfShape_d49850::Collide(const HfInput_d49850& input, HfVec_d49850* outputArray) const
{
    HfCollide_d49850(*this, input, outputArray);
}

extern int DAT_010cfb34;

struct HeightFieldSource;
struct HeightFieldVtable
{
    void* v00;
    void* v04;
    void* v08;
    void* v0c;
    void* v10;
    void* v14;
    void* v18;
    void* v1c;
    void* v20;
    void* v24;
    void* v28;
    void* v2c;
    void* v30;
    float(__thiscall* GetHeightAt)(HeightFieldSource*, int, int);
    void(__thiscall* GetTriangleFlip)(HeightFieldSource*, unsigned char*);
};
struct HeightFieldSource
{
    HeightFieldVtable* vtable;
    unsigned short m_usMemSizeAndFlags;
    volatile short m_sReferenceCount;
    volatile unsigned int m_ulUserData;
    volatile unsigned int m_type;
    int m_iXResolution;
    int m_iZResolution;
    float m_fHeightScale;
    unsigned char m_bUseProjectionBasedHeight;
    volatile unsigned char m_ucHeightFieldType;
    unsigned short m_stitchingMode;
    LocalM128 m_kHeightScaleVector;
    LocalM128 m_kInverseScale;
    LocalM128 m_kOffset;
    LocalM128 SetCenterPosition;
};
struct FUN_00d49750
{
    int* volatile vtable;
    unsigned short m_usMemSizeAndFlags;
    volatile short m_sReferenceCount;
    volatile unsigned int m_ulUserData;
    volatile unsigned int m_type;
    int m_iXResolution;
    int m_iZResolution;
    float m_fHeightScale;
    unsigned char m_bUseProjectionBasedHeight;
    volatile unsigned char m_ucHeightFieldType;
    unsigned short m_stitchingMode;
    LocalM128 m_kHeightScaleVector;
    LocalM128 m_kInverseScale;
    LocalM128 m_kOffset;
    LocalM128 SetCenterPosition;
    float* m_storageData;
    unsigned char m_bFlipTriangleOrder;
    unsigned int m_storageCapacity;
    unsigned int m_bufferOptions;
    unsigned char m_sState;

    FUN_00d49750(HeightFieldSource* source);
};
// Copies resolution, scale, offset and flip settings from a HeightFieldSource, allocates a height buffer, and fills it with sampled heights.
// @fnv 0x00d49750
FUN_00d49750::FUN_00d49750(HeightFieldSource* source) : m_sReferenceCount(1)
{
    m_ulUserData = 0;
    m_type = 13;
    vtable = &DAT_010cfb34;
    m_ucHeightFieldType = 0;
    m_iXResolution = source->m_iXResolution;
    m_iZResolution = source->m_iZResolution;
    unsigned char flip;
    source->vtable->GetTriangleFlip(source, &flip);
    m_bFlipTriangleOrder = flip;
    m_fHeightScale = source->m_fHeightScale;
    m_kHeightScaleVector = source->m_kHeightScaleVector;
    m_kInverseScale = source->m_kInverseScale;
    m_kOffset = source->m_kOffset;
    SetCenterPosition = source->SetCenterPosition;
    m_storageData = new float[m_iXResolution * m_iZResolution];
    m_sState = 1;
    for (int row = 0; row < m_iZResolution; ++row)
    {
        for (int column = 0; column < m_iXResolution; ++column)
        {
            float sampledHeight = source->vtable->GetHeightAt(source, column, row);
            m_storageData[row * m_iXResolution + column] = sampledHeight;
        }
    }
}
