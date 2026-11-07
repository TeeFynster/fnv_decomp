#define FNV64_HKVECTOR4_OWN_DEFAULT
#define FNV64_HKVECTOR4_OWN_ASSIGN

// src/havok/common/base/math/matrix/hktransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hktransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// The SDK SIMD union contains byte arrays that add a /GS cookie to this unit.
// Retain the original intrinsic storage layout while using the shared Transform.
// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkVector4.h"

struct __declspec(align(16)) Matrix43
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
    void hkTransform_setMul(Matrix43* a, Matrix43* b);
    void hkTransform_setMul_00cb22c0(Transform* a, Matrix43* b);
};
// @fnv 0x00cb22c0
// src: HAVOK_LIB 0x00cb22c0
void Matrix43::hkTransform_setMul_00cb22c0(Transform* apTransform, Matrix43* apMatrix)
{
    Matrix43 temp;
    apTransform->Object_ForwardCall_00ce5300(&temp);
    this->hkTransform_setMul(&temp, apMatrix);
}

struct Matrix44;
struct FUN_00cb21e0_shell
{
    void __thiscall hkTransform_setInverse(const Matrix44* source);
};
struct FUN_00cb2240_shell
{
    void __thiscall hkTransform_setMul(const Matrix44* left, const Matrix44* right);
};
__declspec(align(16)) struct Matrix44
{
    hkVector4 row0;
    hkVector4 row1;
    hkVector4 row2;
    hkVector4 row3;
    void hkTransform_setMulMulInverse(const Matrix44* left, const Matrix44* right);
};
// @fnv 0x00cb2420
// src: HAVOK_LIB 0x00cb2420
void Matrix44::hkTransform_setMulMulInverse(const Matrix44* left, const Matrix44* right)
{
    __m128 tempStorage[4];
    Matrix44& tempMatrix = *reinterpret_cast<Matrix44*>(tempStorage);
    ((FUN_00cb21e0_shell*)&tempMatrix)->hkTransform_setInverse(right);
    ((FUN_00cb2240_shell*)this)->hkTransform_setMul(left, &tempMatrix);
}

// The shared vector does not yet declare this method; retain only its call interface.
struct VectorFiniteCheck
{
    bool* __thiscall CheckFloatsFinite(bool* value);
};

struct S_cb2110_Foo
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

    hkVector4 unk30;

    bool* __thiscall hkRotation_isOk(bool* value);
    bool* __thiscall hkTransform_isOk(bool* result);
};

// @fnv 0x00cb2110
// src: HAVOK_LIB 0x00cb2110
bool* __thiscall S_cb2110_Foo::hkTransform_isOk(bool* result)
{
    bool value1;
    bool value2;
    bool value;

    if (*reinterpret_cast<VectorFiniteCheck*>(&unk30)->CheckFloatsFinite(&value1) && *hkRotation_isOk(&value2))
    {
        value = true;
    }
    else
    {
        value = false;
    }
    *result = value;
    return result;
}

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);

class hkMatrix3;

__forceinline void SetRotatedDir(hkVector4& out, const hkMatrix3& r, const hkVector4& b);
__forceinline void SetRotatedInverseDir(hkVector4& out, const hkMatrix3& r, const hkVector4& b);


#include "../../../../../../include/hkMatrix3.h"


static __forceinline hkVector4& MatrixColumn(hkMatrix3& m, int i) { return reinterpret_cast<hkVector4*>(&m.m_kColumn0)[i]; }
static __forceinline const hkVector4& MatrixColumn(const hkMatrix3& m, int i) { return reinterpret_cast<const hkVector4*>(&m.m_kColumn0)[i]; }
static __forceinline void MatrixTranspose(hkMatrix3& m)
{
    __m128 tmp = _mm_unpacklo_ps(m.m_kColumn0.m_vComponents, m.m_kColumn1.m_vComponents);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m.m_kColumn0.m_vComponents, m.m_kColumn1.m_vComponents), m.m_kColumn2.m_vComponents, 0xe4);
    m.m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m.m_kColumn2.m_vComponents);
    tmp = _mm_movehl_ps(m.m_kColumn0.m_vComponents, tmp);
    m.m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m.m_kColumn2.m_vComponents, 0xd4);
    m.m_kColumn2.m_vComponents = ctmp;
}
static __forceinline void MatrixMulInverse(hkMatrix3& m, const hkMatrix3& kA, const hkMatrix3& kB)
{
    __m128 transStorage[3];
    hkMatrix3& kATrans = *reinterpret_cast<hkMatrix3*>(transStorage);
    kATrans.m_kColumn0.m_vComponents = kA.m_kColumn0.m_vComponents;
    kATrans.m_kColumn1.m_vComponents = kA.m_kColumn1.m_vComponents;
    kATrans.m_kColumn2.m_vComponents = kA.m_kColumn2.m_vComponents;
    MatrixTranspose(kATrans);
    for (int i = 0; i < 3; i++)
    {
        __m128 kCol = MatrixColumn(kB, i).m_vComponents;
        SetRotatedDir(MatrixColumn(m, i), kATrans, *reinterpret_cast<const hkVector4*>(&kCol));
    }
}
__forceinline void SetRotatedDir(hkVector4& out, const hkMatrix3& r, const hkVector4& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void SetRotatedInverseDir(hkVector4& out, const hkMatrix3& r, const hkVector4& b)
{
    __m128 kC0 = r.m_kColumn0.m_vComponents;
    __m128 kC1 = r.m_kColumn1.m_vComponents;
    __m128 kC2 = r.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(kC0, kC1);
    const __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(kC0, kC1), kC2, 0xe4);
    kC0 = _mm_movelh_ps(tmp, kC2);
    tmp = _mm_movehl_ps(kC0, tmp);
    kC1 = _mm_shuffle_ps(tmp, kC2, 0xd4);
    kC2 = ctmp;
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), kC0);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), kC1);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), kC2);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class __declspec(align(16)) hkTransformCB22
{
  public:
    void hkTransform_setMulInverseMul(const hkTransformCB22& kA, const hkTransformCB22& kB);

    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;
};

// Sets the transform to the inverse of kA multiplied by kB, combining rotation via SetMulInverse and translation via a rotated difference.
// @fnv 0x00cb22f0
// src: XBOX_PDB 0x00cb22f0
void hkTransformCB22::hkTransform_setMulInverseMul(const hkTransformCB22& kA, const hkTransformCB22& kB)
{
    MatrixMulInverse(m_rotation, kA.m_rotation, kB.m_rotation);
    __m128 kDiff = _mm_sub_ps(kB.m_vTranslation.m_vComponents, kA.m_vTranslation.m_vComponents);
    SetRotatedInverseDir(m_vTranslation, kA.m_rotation, *reinterpret_cast<const hkVector4*>(&kDiff));
}

struct Row
{
    union
    {
        __m128 v;
        float f0;
    };
};

struct Matrix
{
    Row r0;
    Row r1;
    Row r2;
    Row r3;
};

struct Obj : Matrix
{
    void __thiscall hkTransform_setMul(Matrix* m, int a);
    void __thiscall ProcessTransformedMatrixCopy_00cb23e0(int a);
};

// Copies the matrix into a local, applies FUN_00cb2240 to that copy with a, leaving the original matrix unchanged.
// @fnv 0x00cb23e0
// src: GUESS 0x00cb23e0 (confidence: low)
void __thiscall Obj::ProcessTransformedMatrixCopy_00cb23e0(int a)
{
    Matrix localMatrix;
    localMatrix.r0.v = r0.v;
    localMatrix.r1.v = r1.v;
    localMatrix.r2.v = r2.v;
    localMatrix.r3.v = r3.v;
    hkTransform_setMul(&localMatrix, a);
}

extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);

extern const __m128 DAT_010c4c10;
extern const __m128 DAT_010c7170;

struct FUN_00cb2050_cls
{
    __m128 m_kRow0;
    __m128 m_kRow1;
    __m128 m_kRow2;
    __m128 m_kRow3;

    void CopyMaskedMatrixRows(FUN_00cb2050_cls* apOut);
};

// Copies the four m_kRow vectors into apOut, masking the first three with DAT_010c4c10 and shuffling the fourth with DAT_010c7170.
// @fnv 0x00cb2050
// src: GUESS 0x00cb2050 (confidence: medium)
void FUN_00cb2050_cls::CopyMaskedMatrixRows(FUN_00cb2050_cls* apOut)
{
    apOut->m_kRow0 = _mm_and_ps(m_kRow0, DAT_010c4c10);
    apOut->m_kRow1 = _mm_and_ps(m_kRow1, DAT_010c4c10);
    apOut->m_kRow2 = _mm_and_ps(m_kRow2, DAT_010c4c10);

    __m128 kRow3 = m_kRow3;
    apOut->m_kRow3 = _mm_shuffle_ps(kRow3, _mm_unpackhi_ps(kRow3, DAT_010c7170), 0xc4);
}

extern "C" __m128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);

extern __declspec(align(16)) const float g_absMask[4];
extern __declspec(align(16)) const float g_rowMask[4];

struct FUN_00cb20b0_shell
{
    hkVector4 row0;
    hkVector4 row1;
    hkVector4 row2;
    hkVector4 row3;

    const Matrix44* __thiscall hkTransform_set4x4ColumnMajor(const Matrix44* source);
};

// Applies g_absMask to the first three source rows, shuffles source row3 with g_rowMask, stores the results, and returns source.
// @fnv 0x00cb20b0
// src: XBOX_PDB 0x00cb20b0
const Matrix44* FUN_00cb20b0_shell::hkTransform_set4x4ColumnMajor(const Matrix44* source)
{
    _mm_store_ps(&row0.x, _mm_and_ps(_mm_load_ps(&source->row0.x), _mm_load_ps(g_absMask)));
    _mm_store_ps(&row1.x, _mm_and_ps(_mm_load_ps(&source->row1.x), _mm_load_ps(g_absMask)));
    _mm_store_ps(&row2.x, _mm_and_ps(_mm_load_ps(&source->row2.x), _mm_load_ps(g_absMask)));

    __m128 last = _mm_load_ps(&source->row3.x);
    __m128 high = _mm_unpackhi_ps(last, _mm_load_ps(g_rowMask));
    _mm_store_ps(&row3.x, _mm_shuffle_ps(last, high, 0xc4));

    return source;
}

extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);

extern const __m128 g_vectorSignMask;


#include "../../../../../../include/hkMatrix3.h"


struct S_00cb21e0_Transform
{
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;
    void Body(const S_00cb21e0_Transform& t);
};

__forceinline void S_00cb21e0_Transform::Body(const S_00cb21e0_Transform& t)
{
    m_rotation._setTranspose(t.m_rotation);
    __m128 translationStorage;
    hkVector4& tr = *reinterpret_cast<hkVector4*>(&translationStorage);
    tr.m_vComponents = _mm_xor_ps(t.m_vTranslation.m_vComponents, g_vectorSignMask);
    __m128 b0 = _mm_shuffle_ps(tr.m_vComponents, tr.m_vComponents, 0x00);
    __m128 b1 = _mm_shuffle_ps(tr.m_vComponents, tr.m_vComponents, 0x55);
    __m128 b2 = _mm_shuffle_ps(tr.m_vComponents, tr.m_vComponents, 0xaa);
    __m128 r0 = _mm_mul_ps(m_rotation.m_kColumn0.m_vComponents, b0);
    __m128 r1 = _mm_mul_ps(m_rotation.m_kColumn1.m_vComponents, b1);
    __m128 r2 = _mm_mul_ps(m_rotation.m_kColumn2.m_vComponents, b2);
    m_vTranslation.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

// @fnv 0x00cb21e0
// src: XBOX_PDB 0x00cb21e0
void FUN_00cb21e0_shell::hkTransform_setInverse(const Matrix44* source)
{
    ((S_00cb21e0_Transform*)this)->Body(*(const S_00cb21e0_Transform*)source);
}

extern "C" __m128 _mm_set_ps1(float _A);
extern "C" __m128 _mm_and_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_cmple_ps(__m128 _A, __m128 _B);
extern "C" int _mm_movemask_ps(__m128 _A);

extern __m128 DAT_01017d10;

struct FUN_00cb2160_cls : hkTransformCB22
{
    unsigned char* Probe(unsigned char* out, const FUN_00cb2160_cls* other, float eps);
    unsigned char* hkTransform_isApproximatelyEqual(unsigned char* out, const FUN_00cb2160_cls* other, float eps);
};
// Writes 1 when Probe succeeds and the masked first three translation differences are at most eps; otherwise writes 0.
// @fnv 0x00cb2160
// src: COMMUNITY 0x00cb2160
unsigned char* FUN_00cb2160_cls::hkTransform_isApproximatelyEqual(unsigned char* out, const FUN_00cb2160_cls* other, float eps)
{
    unsigned char flag;
    unsigned char* p = Probe(&flag, other, eps);
    unsigned char r = 0;
    if (*p != 0)
    {
        __m128 d = _mm_sub_ps(m_vTranslation.m_vComponents, other->m_vTranslation.m_vComponents);
        __m128 bound = _mm_set_ps1(eps);
        int mask = _mm_movemask_ps(_mm_cmple_ps(_mm_and_ps(d, DAT_01017d10), bound)) & 7;
        if (mask == 7)
        {
            r = 1;
            goto done;
        }
    }
    r = 0;
done:
    *(unsigned char volatile*)out = r;
    return out;
}
