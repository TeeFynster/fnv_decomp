// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMatrix4.h"

// Matrix temporaries leave their components uninitialized.

// Functions absent from the shared class use an explicit matrix argument.
// The unused EDX argument keeps their remaining arguments on the x86 stack.

// @fnv 0x00de8f30
void __fastcall TransposeTo(hkMatrix4* matrix, void*, float* afOut)
{
    float* m_data = reinterpret_cast<float*>(matrix);
    afOut[0] = m_data[0];
    afOut[4] = m_data[1];
    afOut[8] = m_data[2];
    afOut[12] = m_data[3];
    afOut[1] = m_data[4];
    afOut[5] = m_data[5];
    afOut[9] = m_data[6];
    afOut[13] = m_data[7];
    afOut[2] = m_data[8];
    afOut[6] = m_data[9];
    afOut[10] = m_data[10];
    afOut[14] = m_data[11];
    afOut[3] = m_data[12];
    afOut[7] = m_data[13];
    afOut[11] = m_data[14];
    afOut[15] = m_data[15];
}

// @fnv 0x00de8f10
// src: HAVOK_LIB 0x00de8f10
void __fastcall hkMatrix4_resetFourthRow(hkMatrix4* matrix, void*)
{
    float* m_data = reinterpret_cast<float*>(matrix);
    m_data[11] = 0.0f;
    m_data[7] = 0.0f;
    m_data[3] = 0.0f;
    m_data[15] = 1.0f;
}

// Copies 16 floats from src into m_data in transposed order (row/column swap).
// @fnv 0x00de8fa0
// src: HAVOK_LIB 0x00de8fa0
void __fastcall hkMatrix4_set4x4RowMajor(hkMatrix4* matrix, void*, const float* src)
{
    float* m_data = reinterpret_cast<float*>(matrix);
    m_data[0] = src[0];
    m_data[1] = src[4];
    m_data[2] = src[8];
    m_data[3] = src[12];
    m_data[4] = src[1];
    m_data[5] = src[5];
    m_data[6] = src[9];
    m_data[7] = src[13];
    m_data[8] = src[2];
    m_data[9] = src[6];
    m_data[10] = src[10];
    m_data[11] = src[14];
    m_data[12] = src[3];
    m_data[13] = src[7];
    m_data[14] = src[11];
    m_data[15] = src[15];
}

// Copies the 16 floats in m_data into the destination array.
// @fnv 0x00de9010
void __fastcall CopyTo(hkMatrix4* matrix, void*, float* afOut)
{
    float* m_data = reinterpret_cast<float*>(matrix);
    *afOut = m_data[0];
    afOut[1] = m_data[1];
    afOut[2] = m_data[2];
    afOut[3] = m_data[3];
    afOut[4] = m_data[4];
    afOut[5] = m_data[5];
    afOut[6] = m_data[6];
    afOut[7] = m_data[7];
    afOut[8] = m_data[8];
    afOut[9] = m_data[9];
    afOut[10] = m_data[10];
    afOut[11] = m_data[11];
    afOut[12] = m_data[12];
    afOut[13] = m_data[13];
    afOut[14] = m_data[14];
    afOut[15] = m_data[15];
}

// Copies 16 floats from src into m_data.
// @fnv 0x00de9080
void __fastcall CopyFromFloats(hkMatrix4* matrix, void*, const float* apSource)
{
    float* m_data = reinterpret_cast<float*>(matrix);
    m_data[0] = apSource[0];
    m_data[1] = apSource[1];
    m_data[2] = apSource[2];
    m_data[3] = apSource[3];
    m_data[4] = apSource[4];
    m_data[5] = apSource[5];
    m_data[6] = apSource[6];
    m_data[7] = apSource[7];
    m_data[8] = apSource[8];
    m_data[9] = apSource[9];
    m_data[10] = apSource[10];
    m_data[11] = apSource[11];
    m_data[12] = apSource[12];
    m_data[13] = apSource[13];
    m_data[14] = apSource[14];
    m_data[15] = apSource[15];
}

// @fnv 0x00de8e50
// src: GUESS 0x00de8e50 (confidence: high)
void hkMatrix4::MultiplyInPlace(const hkMatrix4& b)
{
    hkMatrix4 t;
    t.hkMatrix4_setMul(*this, b);
    *this = t;
}

// Copies four __m128 rows from source into rows, then forces the fourth component of each row to 0,0,0,1.
// @fnv 0x00de90f0
// src: GUESS 0x00de90f0 (confidence: medium)
void __fastcall hkMatrix4_CopyMatrixWithAffineFourthComponents(hkMatrix4* matrix, void*, const __m128* source)
{
    __m128* rows = reinterpret_cast<__m128*>(matrix);
    rows[0] = source[0];
    rows[1] = source[1];
    rows[2] = source[2];
    rows[3] = source[3];
    volatile float* pfValues = (volatile float*)matrix;
    pfValues[3] = 0.0f;
    pfValues[7] = 0.0f;
    pfValues[11] = 0.0f;
    pfValues[15] = 1.0f;
}

struct CB20B0_Class
{
    void hkTransform_set4x4ColumnMajor(void* src);
};
// @fnv 0x00de9130
// src: GUESS 0x00de9130 (confidence: medium)
void __fastcall hkTransform_Set4x4ColumnMajor_Thunk(hkMatrix4* matrix, void*, CB20B0_Class* dst)
{
    dst->hkTransform_set4x4ColumnMajor(matrix);
}

// Copies four columns from source, then calls FUN_00de8910 with value.
// @fnv 0x00de8c50
// src: GUESS 0x00de8c50 (confidence: medium)
void __fastcall hkMatrix4_CopyColumnsAndApplyValue(hkMatrix4* matrix, void*, const __m128* apRows, float value)
{
    matrix->m_kColumn0.m_vComponents = apRows[0];
    matrix->m_kColumn1.m_vComponents = apRows[1];
    matrix->m_kColumn2.m_vComponents = apRows[2];
    matrix->m_kColumn3.m_vComponents = apRows[3];
    matrix->UpdateState_00de8910(value);
}

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
// @fnv 0x00cdf230
// src: HAVOK_LIB 0x00cdf230
void FUN_00cdf230_cls::hkpRagdollConstraintData_setTarget(int iArg)
{
    m_kRoomNode.hkMatrix3_setMul(&m_kSource, iArg);
}

__forceinline void AddColumn(hkVector4& destination, const hkVector4& source)
{
    __m128 t = source.m_vComponents;
    destination.m_vComponents = _mm_add_ps(t, destination.m_vComponents);
}

// Adds each of other's four rows into this matrix's matching rows and returns other.
// @fnv 0x00de8c90
const hkMatrix4* __fastcall Add(hkMatrix4* matrix, void*, const hkMatrix4* other)
{
    AddColumn(matrix->m_kColumn0, other->m_kColumn0);
    AddColumn(matrix->m_kColumn1, other->m_kColumn1);
    AddColumn(matrix->m_kColumn2, other->m_kColumn2);
    AddColumn(matrix->m_kColumn3, other->m_kColumn3);
    return other;
}

extern float DAT_0104da4c;

// src: GUESS 0x00de8910 (confidence: low)
__declspec(noinline) void __fastcall UpdateState_00de8910(hkMatrix4* matrix, float s)
{
    matrix->m_kColumn0.x = s;
    unsigned u = (unsigned)(int)s;
    matrix->m_kColumn0.y = (float)(int)(u / 10u);
}

// Copies the matrix into a local, calls FUN_00de8910, then multiplies dst by the local matrix.
// @fnv 0x00de9270
// src: GUESS 0x00de9270 (confidence: medium)
void __fastcall hkMatrix4_MultiplyByAdjustedMatrix(hkMatrix4* matrix, void*, hkMatrix4* dst, const hkMatrix4* src)
{
    hkMatrix4 matTmp;
    *(__m128*)&matTmp.m_kColumn0 = *(const __m128*)&src->m_kColumn0;
    *(__m128*)&matTmp.m_kColumn1 = *(const __m128*)&src->m_kColumn1;
    *(__m128*)&matTmp.m_kColumn2 = *(const __m128*)&src->m_kColumn2;
    *(__m128*)&matTmp.m_kColumn3 = *(const __m128*)&src->m_kColumn3;

    UpdateState_00de8910(&matTmp, DAT_0104da4c);

    matrix->hkMatrix4_setMul(*dst, matTmp);
}

// Subtracts the four columns of rhs from this matrix using SSE and returns rhs.
// @fnv 0x00de8ce0
// src: GUESS 0x00de8ce0 (confidence: medium)
const hkMatrix4* __fastcall hkMatrix4_SubtractMatrixColumns(hkMatrix4* matrix, void*, const hkMatrix4* rhs)
{
    *(__m128*)&matrix->m_kColumn0 = _mm_sub_ps(*(const __m128*)&matrix->m_kColumn0, *(const __m128*)&rhs->m_kColumn0);
    *(__m128*)&matrix->m_kColumn1 = _mm_sub_ps(*(const __m128*)&matrix->m_kColumn1, *(const __m128*)&rhs->m_kColumn1);
    *(__m128*)&matrix->m_kColumn2 = _mm_sub_ps(*(const __m128*)&matrix->m_kColumn2, *(const __m128*)&rhs->m_kColumn2);
    *(__m128*)&matrix->m_kColumn3 = _mm_sub_ps(*(const __m128*)&matrix->m_kColumn3, *(const __m128*)&rhs->m_kColumn3);
    return rhs;
}

// @fnv 0x00de8d30
// src: GUESS 0x00de8d30 (confidence: high)
const __m128* __fastcall hkMatrix4_ScaleColumnsByFirstComponent(hkMatrix4* matrix, void*, const __m128* apVector)
{
    __m128 v = *apVector;
    matrix->m_kColumn0.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), matrix->m_kColumn0.m_vComponents);
    v = *apVector;
    matrix->m_kColumn1.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), matrix->m_kColumn1.m_vComponents);
    v = *apVector;
    matrix->m_kColumn2.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), matrix->m_kColumn2.m_vComponents);
    v = *apVector;
    matrix->m_kColumn3.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), matrix->m_kColumn3.m_vComponents);
    return apVector;
}

__declspec(noinline) void __fastcall SwapFields(hkMatrix4* matrix, hkMatrix4* context)
{
    __m128* vectors = reinterpret_cast<__m128*>(matrix);
    __m128 low01 = _mm_unpacklo_ps(vectors[0], vectors[1]);
    __m128 high01 = _mm_unpackhi_ps(vectors[0], vectors[1]);
    __m128 low23 = _mm_unpacklo_ps(vectors[2], vectors[3]);
    __m128 high23 = _mm_unpackhi_ps(vectors[2], vectors[3]);
    vectors[0] = _mm_movelh_ps(low01, low23);
    vectors[1] = _mm_movehl_ps(low23, low01);
    vectors[2] = _mm_movelh_ps(high01, high23);
    vectors[3] = _mm_movehl_ps(high23, high01);
}

__forceinline float Dot4(const float* left, const float* right)
{
    __m128 first = *reinterpret_cast<const __m128*>(left);
    __m128 second = *reinterpret_cast<const __m128*>(right);
    __m128 product = _mm_mul_ps(first, second);
    __m128 halves = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
    __m128 sum = _mm_add_ps(_mm_shuffle_ps(halves, halves, 0xb1), halves);
    float scalar;
    _mm_store_ss(&scalar, sum);
    return scalar;
}

// Retain the stack-resident volatile pointer while using the shared matrix type.
struct MatrixPointerQ
{
    const hkMatrix4* volatile value;
    MatrixPointerQ(const MatrixPointerQ& other);
};

// Stores the matrix product formed by dotting each row of right with each column of left.
// @fnv 0x00de8da0
// src: XBOX_PDB 0x00de8da0
void __fastcall hkMatrix4_setMul(hkMatrix4* matrix, void*, const hkMatrix4* left, MatrixPointerQ right)
{
    hkMatrix4 columns;
    columns = *left;
    SwapFields(&columns, matrix);
    float* destination = reinterpret_cast<float*>(matrix);
    const float* input = reinterpret_cast<const float*>(right.value);
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            destination[row * 4 + column] =
                Dot4(input + row * 4, reinterpret_cast<const float*>(&columns) + column * 4);
        }
    }
}

extern float DAT_01011d78;
extern float DAT_01012068;
extern __m128 DAT_01017d10;

// Compares four selected values with two constants, then returns whether the first three absolute differences are at most DAT_01011d78.
// @fnv 0x00de8ea0
// src: GUESS 0x00de8ea0 (confidence: medium)
int __fastcall Object_CompareSelectedMatrixValues(hkMatrix4* matrix, void*)
{
    float* m_data = reinterpret_cast<float*>(matrix);
    __m128 column = _mm_setr_ps(m_data[3], m_data[7], m_data[11], m_data[15]);
    __m128 ref = _mm_setr_ps(DAT_01011d78, DAT_01011d78, DAT_01011d78, DAT_01012068);
    __m128 diff = _mm_sub_ps(column, ref);
    __m128 absDiff = _mm_and_ps(diff, DAT_01017d10);
    __m128 bound = _mm_set_ps1(DAT_01011d78);
    __m128 cmp = _mm_cmple_ps(absDiff, bound);
    int mask = _mm_movemask_ps(cmp) & 7;
    return mask == 7;
}
