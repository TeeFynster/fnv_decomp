#define FNV64_HKVECTOR4_PACKET_BODIES

// src/havok/common/base/math/qstransform/hkqstransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/qstransform/hkqstransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Matrix
{
    float values[12];
    bool* HasFiniteValues(bool* output);
};

// Checks the 12 matrix values (skipping indices 3 and 11) for infinite/NaN exponents and writes the result to output.
// @fnv 0x00ce50e0
bool* Matrix::HasFiniteValues(bool* pbFinite)
{
    for (int index = 0; index < 12; ++index)
    {
        if (index != 3 && index != 11)
        {
            union FloatBits
            {
                float value;
                unsigned int bits;
            } valueBits;
            valueBits.value = values[index];
            if ((valueBits.bits & 0x7f800000) == 0x7f800000)
            {
                *pbFinite = false;
                return pbFinite;
            }
        }
    }
    *pbFinite = true;
    return pbFinite;
}

#include <xmmintrin.h>
struct S_00ce5070_Vector4
{
    __m128 m_vComponents;
};

extern const S_00ce5070_Vector4 DAT_010c7170;


#include "../../../../../../include/hkRotation.h"







#include "../../../../../../include/hkQsTransform.h"
#include "../../../../../../include/hkTransform.h"


// Copies rotation and translation from a Transform into the QsTransform, and sets scale to the constant DAT_010c7170.
// @fnv 0x00ce5070
// src: COMMUNITY 0x00ce5070
void hkQsTransform::setFromTransformNoScale(const hkTransform& akTransform)
{
    m_rotation.FUN_00cb26e0(akTransform.m_rotation);
    m_vTranslation.m_vComponents = akTransform.m_vTranslation;
    m_vScale.m_vComponents = DAT_010c7170.m_vComponents;
}

class CB2FC0Object
{
  public:
    void hkRotation_set(void* snapshot);
};

class FUN_00ce50b0_cls
{
  public:
    void CopyRotationAndTranslationToTarget(CB2FC0Object* target);
};

// @fnv 0x00ce50b0
// src: GUESS 0x00ce50b0 (confidence: medium)
void FUN_00ce50b0_cls::CopyRotationAndTranslationToTarget(CB2FC0Object* target)
{
    Matrix* self = (Matrix*)this;
    target->hkRotation_set(&self->values[4]);
    __m128 vMatrix = _mm_load_ps(self->values);
    _mm_store_ps((float*)((char*)target + 0x30), vMatrix);
}

#include "../../../../../../include/hkVector4.h"
struct FUN_008cd6a0_Class
{
    hkVector4 row0, row1, row2;
    void hkRotation_set(void*);
};
struct FUN_00cdf250_class
{
    hkVector4 row0, row1, row2;
    void hkMatrix3_setMul(int*, int);
};
struct TransformMatrix
{
    hkVector4 row0, row1, row2, row3;
    void CopyMaskedMatrixRows(int);
};
// hkQsTransform layout with float rotation/scale lanes (0x00ce51f0 builds an hkTransform from it); kept local because the body reads the lanes as floats.
struct QsTransformFloats
{
    hkVector4 position;
    float rotationX, rotationY, rotationZ, rotationW;
    float scaleX, scaleY, scaleZ;
    void BuildMatrixFromRotationScaleAndPosition(int);
};
// Builds a matrix from rotation, scale, and position, then passes out to FUN_00cb2050.
// @fnv 0x00ce51f0
// src: GUESS 0x00ce51f0 (confidence: medium)
void QsTransformFloats::BuildMatrixFromRotationScaleAndPosition(int out)
{
    FUN_008cd6a0_Class rotMatrix;
    rotMatrix.hkRotation_set(&rotationX);
    FUN_00cdf250_class scaleMatrix;
    *(__m128*)&scaleMatrix.row0 = _mm_setzero_ps();
    scaleMatrix.row0.x = scaleX;
    *(__m128*)&scaleMatrix.row1 = _mm_setzero_ps();
    scaleMatrix.row1.y = scaleY;
    *(__m128*)&scaleMatrix.row2 = _mm_setzero_ps();
    scaleMatrix.row2.z = scaleZ;
    FUN_00cdf250_class combinedMatrix;
    combinedMatrix.hkMatrix3_setMul((int*)&rotMatrix, (int)&scaleMatrix);
    TransformMatrix resultMatrix;
    *(__m128*)&resultMatrix.row0 = *(__m128*)&combinedMatrix.row0;
    *(__m128*)&resultMatrix.row1 = *(__m128*)&combinedMatrix.row1;
    *(__m128*)&resultMatrix.row2 = *(__m128*)&combinedMatrix.row2;
    *(__m128*)&resultMatrix.row3 = *(__m128*)&position;
    resultMatrix.CopyMaskedMatrixRows(out);
}

struct S_00ce5290_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

struct S_00ce5290_Bool
{
    char m_cBooleanValue;
    S_00ce5290_Bool(bool b)
    {
        m_cBooleanValue = b;
    }
};

struct S_00ce5290_Result
{
    S_00ce5290_Vector4 m_v0;
    S_00ce5290_Vector4 m_v1;
    S_00ce5290_Vector4 m_v2;
    char unk30;
    char unk31;
    short unk32;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};

void hkMathUtil_decompose4x4ColTransform(const void* input, S_00ce5290_Result* out);

struct S_00ce5290
{
    S_00ce5290_Vector4 m_v0;
    S_00ce5290_Vector4 m_v1;
    S_00ce5290_Vector4 m_v2;
    S_00ce5290_Bool SetFromInput(const void* input);
};

// Calls FUN_00d72e90 to compute a result from input, copies the three vector fields into m_v0, m_v1, m_v2, and returns whether res.unk31 is zero.
// @fnv 0x00ce5290
S_00ce5290_Bool S_00ce5290::SetFromInput(const void* input)
{
    __declspec(align(16)) S_00ce5290_Result result;
    hkMathUtil_decompose4x4ColTransform(input, &result);
    m_v0.q() = result.m_v0.q();
    m_v1.q() = result.m_v1.q();
    m_v2.q() = result.m_v2.q();
    return result.unk31 == 0;
}
