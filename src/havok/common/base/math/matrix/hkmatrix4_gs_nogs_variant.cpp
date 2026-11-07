// src/havok/common/base/math/matrix/hkmatrix4_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/math/matrix/hkmatrix4.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkMatrix4.h"

struct CB20B0_Class
{
    void hkTransform_set4x4ColumnMajor(void* src);
};
struct SourceBlockCDF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct TargetBlockCDF
{
    void hkMatrix3_setMul(SourceBlockCDF* pkSource, int iArg);
};
struct FUN_00cdf230_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    SourceBlockCDF m_kSource;
    TargetBlockCDF m_kRoomNode;
    void hkpRagdollConstraintData_setTarget(int iArg);
};
struct FUN_00de8910_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void UpdateState_00de8910(float s);
};
struct FUN_00de8da0_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void hkMatrix4_setMul(void* dst, const float* src);
};
// src: GUESS 0x00de8910 (confidence: low)
__declspec(noinline) void FUN_00de8910_Class::UpdateState_00de8910(float s)
{
    unk00 = s;
    unsigned u = (unsigned)(int)s;
    unk04 = (float)(int)(u / 10u);
}
struct S00de9270_cls
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void hkMatrix4_MultiplyByAdjustedMatrix(void* dst, const hkMatrix4* src);
};

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_setr_ps(float, float, float, float);
    void _mm_store_ss(float*, __m128);
}

extern const __m128 DAT_010c7160;

class S00de92d0_SimdReal
{
  public:
    __forceinline S00de92d0_SimdReal(const __m128& x) : m_vValue(x)
    {}
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

__forceinline S00de92d0_SimdReal operator-(const S00de92d0_SimdReal& r)
{
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}

class S00de92d0_Vector4
{
  public:
    __forceinline S00de92d0_Vector4()
    {}
    __forceinline void operator=(const S00de92d0_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float a, float b, float c, float d = 0)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setMul4(const S00de92d0_Vector4& a, const S00de92d0_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00de92d0_Vector4& x, const S00de92d0_Vector4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setBroadcast(const S00de92d0_Vector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    __forceinline S00de92d0_SimdReal getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __m128 m_vComponents;
};

enum S00de92d0_Result
{
    S00de92d0_SUCCESS = 0,
    S00de92d0_FAILURE = 1
};

// local form of hkMatrix3: 0x00de92d0 needs inline construction/rows/vector operations; shared form gives 320 bytes vs exe 311.
class S00de92d0_Matrix3
{
  public:
    S00de92d0_Vector4 m_kColumn0;
    S00de92d0_Vector4 m_kColumn1;
    S00de92d0_Vector4 m_kColumn2;

    __forceinline S00de92d0_Matrix3()
    {}
    __forceinline S00de92d0_Vector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const S00de92d0_Vector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    __forceinline void setRows(const S00de92d0_Vector4& r0, const S00de92d0_Vector4& r1, const S00de92d0_Vector4& r2)
    {
        getColumn(0).set(r0(0), r1(0), r2(0));
        getColumn(1).set(r0(1), r1(1), r2(1));
        getColumn(2).set(r0(2), r1(2), r2(2));
    }
    S00de92d0_Result invert_00cd4f10(float epsilon);
    __forceinline void multiplyVector(const S00de92d0_Vector4& v, S00de92d0_Vector4& resultOut) const
    {
        S00de92d0_Vector4 xb;
        xb.setBroadcast(v, 0);
        S00de92d0_Vector4 yb;
        yb.setBroadcast(v, 1);
        S00de92d0_Vector4 zb;
        zb.setBroadcast(v, 2);

        S00de92d0_Vector4 t0;
        t0.setMul4(xb, m_kColumn0);
        t0.addMul4(yb, m_kColumn1);
        t0.addMul4(zb, m_kColumn2);

        resultOut = t0;
    }
};

class S00de92d0_GeometryProcessing
{
  public:
    static bool __cdecl EvaluateValue_00de92d0(const S00de92d0_Vector4& p0, const S00de92d0_Vector4& p1,
                                     const S00de92d0_Vector4& p2, S00de92d0_Vector4& intersection);
};

// @fnv 0x00de92d0
// src: GUESS 0x00de92d0 (confidence: low)
bool __cdecl S00de92d0_GeometryProcessing::EvaluateValue_00de92d0(const S00de92d0_Vector4& p0, const S00de92d0_Vector4& p1,
                                                        const S00de92d0_Vector4& p2, S00de92d0_Vector4& intersection)
{
    S00de92d0_Matrix3 m;
    S00de92d0_Vector4 d;
    d.set(-p0.getSimdAt(3), -p1.getSimdAt(3), -p2.getSimdAt(3), 0.0f);
    m.setRows(p0, p1, p2);
    if (m.invert_00cd4f10(1.192092896e-07f) == S00de92d0_SUCCESS)
    {
        m.multiplyVector(d, intersection);
        return true;
    }
    return false;
}
