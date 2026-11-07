// gamebryo2.2/corelibs/nimain/niquaternion.cpp: NiQuaternion, NiColorA (15 functions)

#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl cos(double);
extern "C" double __cdecl sin(double);

// Normalizes the quaternion by computing the reciprocal of the square root of the sum of squares and scaling all four components by it.
// @fnv 0x00a38560
void NiQuaternion::MakeUnitLength()
{
    float fNorm =
        m_fVectorX * m_fVectorX + m_fVectorY * m_fVectorY + m_fVectorZ * m_fVectorZ + m_fScalarPart * m_fScalarPart;
    float fScale = 1.0f / static_cast<float>(sqrt(fNorm));
    m_fVectorX *= fScale;
    m_fVectorY *= fScale;
    m_fVectorZ *= fScale;
    m_fScalarPart *= fScale;
}

// Reads four 4-byte values (r, g, b, a) from the stream's binary reader, advancing the stream position by the bytes read.
// @fnv 0x00a69800
void NiColorA::LoadBinary(NiStream& arStream)
{
    NiBinaryStream* pkStream = arStream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &r, 4, &uiBytesRead, 1);
    }
    pkStream = arStream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &g, 4, &uiBytesRead, 1);
    }
    pkStream = arStream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &b, 4, &uiBytesRead, 1);
    }
    pkStream = arStream.m_pkIstr;
    {
        unsigned int uiBytesRead = 4;
        pkStream->m_uiAbsoluteCurrentPos += pkStream->m_pfnRead(pkStream, &a, 4, &uiBytesRead, 1);
    }
}

// Spherical interpolation between quaternions a and b by t, using a cosine-based warp, then normalizes the result.
// @fnv 0x00a6e330
void NiQuaternion::Slerp(float t, const NiQuaternion& a, const NiQuaternion& b)
{
    float cosine = a.m_fVectorX * b.m_fVectorX + a.m_fVectorY * b.m_fVectorY + a.m_fVectorZ * b.m_fVectorZ +
                   a.m_fScalarPart * b.m_fScalarPart;
    float warped;
    if (t <= 0.5f)
        warped = CalculateSlerpWeight(t, cosine);
    else
        warped = 1.0f - CalculateSlerpWeight(1.0f - t, cosine);
    float fStart = a.m_fVectorX;
    m_fVectorX = fStart + warped * (b.m_fVectorX - fStart);
    fStart = a.m_fVectorY;
    m_fVectorY = fStart + warped * (b.m_fVectorY - fStart);
    fStart = a.m_fVectorZ;
    m_fVectorZ = fStart + warped * (b.m_fVectorZ - fStart);
    fStart = a.m_fScalarPart;
    m_fScalarPart = fStart + warped * (b.m_fScalarPart - fStart);
    EnsureCanonicalSign();
}

inline float QuaternionSqrt(float value)
{
    volatile float result = (float)sqrt(value);
    return result;
}
extern const unsigned int DAT_011a9e98[3];
__forceinline NiQuaternion::NiQuaternion()
{}
// Builds the quaternion components from a rotation matrix, using the trace branch or the largest-diagonal branch.
// @fnv 0x00a6df40
void NiQuaternion::FromRotationMatrix(const NiMatrix3& akMatrix)
{
    const float (*matrix)[3] = reinterpret_cast<const float (*)[3]>(&akMatrix);
    float root = akMatrix.m_pEntry[0][0] + akMatrix.m_pEntry[1][1] + akMatrix.m_pEntry[2][2];
    if (root > 0.0f)
    {
        root = QuaternionSqrt(root + 1.0f);
        m_fVectorX = root * 0.5;
        root = 0.5 / root;
        m_fVectorY = (matrix[2][1] - matrix[1][2]) * root;
        m_fVectorZ = (matrix[0][2] - matrix[2][0]) * root;
        m_fScalarPart = (matrix[1][0] - matrix[0][1]) * root;
    }
    else
    {
        unsigned int uiAxis = 0;
        if (matrix[1][1] > matrix[0][0])
            uiAxis = 1;
        if (matrix[2][2] > matrix[uiAxis][uiAxis])
            uiAxis = 2;
        unsigned int uiNextAxis = DAT_011a9e98[uiAxis];
        unsigned int uiLastAxis = DAT_011a9e98[uiNextAxis];
        root = QuaternionSqrt(matrix[uiAxis][uiAxis] - matrix[uiNextAxis][uiNextAxis] -
                              matrix[uiLastAxis][uiLastAxis] + 1.0f);
        float* apComponents[3] = {&m_fVectorY, &m_fVectorZ, &m_fScalarPart};
        *apComponents[uiAxis] = root * 0.5;
        root = 0.5 / root;
        m_fVectorX = (matrix[uiLastAxis][uiNextAxis] - matrix[uiNextAxis][uiLastAxis]) * root;
        *apComponents[uiNextAxis] = (matrix[uiAxis][uiNextAxis] + matrix[uiNextAxis][uiAxis]) * root;
        *apComponents[uiLastAxis] = (matrix[uiAxis][uiLastAxis] + matrix[uiLastAxis][uiAxis]) * root;
    }
}

extern double DAT_0109c9d0;
extern double DAT_0109c9d8;

// @fnv 0x00a6dc30
// src: GAMEBRYO_LIB 0x00a6dc30
float NiQuaternion_CounterWarp(float t, float fCos)
{
    float fFactor = 1.0f - DAT_0109c9d8 * fCos;
    fFactor *= fFactor;
    float fK = DAT_0109c9d0 * fFactor;
    return t * (fK * t * (2.0f * t - 3.0) + 1.0f + fK);
}

// Interpolates p to q and a to b by t, then slerps between those two results by 2*t*(1-t) into self.
// @fnv 0x00a6e430
// src: COMMUNITY 0x00a6e430
void __fastcall NiQuaternion_Squad(NiQuaternion* self, int edx, float afTime, const NiQuaternion& aStart,
                             const NiQuaternion& aStart2, const NiQuaternion& aEnd2, const NiQuaternion& aEnd)
{
    NiQuaternion q1;
    NiQuaternion q2;
    q1.Slerp(afTime, aStart, aEnd);
    q2.Slerp(afTime, aStart2, aEnd2);
    self->Slerp(2.0f * afTime * (1.0f - afTime), q1, q2);
}

extern unsigned char DAT_011F3FE4;

// @fnv 0x00a4ffe0
// src: COMMUNITY 0x00a4ffe0
unsigned char* __cdecl NiBSplineTransformInterpolator_GetRTTI()
{
    return &DAT_011F3FE4;
}

extern float DAT_011F3FEC;
extern float DAT_011F3FF0;

static inline float isqrt_approx_in_neighborhood(float s)
{
    return DAT_011F3FF0 + DAT_011F3FEC * (s - 0.9590659737586975);
}

// @fnv 0x00a4ff00
void NiQuaternion::EnsureCanonicalSign()
{
    float s =
        m_fVectorZ * m_fVectorZ + m_fVectorY * m_fVectorY + m_fScalarPart * m_fScalarPart + m_fVectorX * m_fVectorX;
    float fScale = isqrt_approx_in_neighborhood(s);
    if (s <= 0.9152119755744934)
    {
        fScale *= isqrt_approx_in_neighborhood(fScale * fScale * s);
        if (s <= 0.6521196961402893f)
        {
            fScale *= isqrt_approx_in_neighborhood(fScale * fScale * s);
        }
    }
    m_fVectorY = m_fVectorY * fScale;
    m_fVectorZ = fScale * m_fVectorZ;
    m_fScalarPart = m_fScalarPart * fScale;
    m_fVectorX = m_fVectorX * fScale;
}

template <class T> inline unsigned int BinaryWriteValue(NiBinaryStream* pkStream, const T& value)
{
    unsigned int uiComponentSize = sizeof(T);
    unsigned int uiBytes = pkStream->m_pfnWrite(pkStream, &value, sizeof(T), &uiComponentSize, 1);
    pkStream->m_uiAbsoluteCurrentPos += uiBytes;
    return uiBytes;
}

template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    NiBinaryStream* pkStream = kStream.m_pkOstr;
    BinaryWriteValue(pkStream, value);
}

// @fnv 0x00a6e4a0
void NiQuaternion::SaveBinary(NiStream* stream)
{
    NiStream& kStream = *stream;
    Snap();
    SerializeValue(kStream, m_fVectorX);
    SerializeValue(kStream, m_fVectorY);
    SerializeValue(kStream, m_fVectorZ);
    SerializeValue(kStream, m_fScalarPart);
}

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl acos(double);

extern double DAT_0101a6b0;
extern float DAT_0109c9c4;
static const float epsilon = 0.001f;

// Computes the rotation angle from the quaternion's w component and normalizes the xyz vector into an axis, zeroing both when the vector length is below epsilon.
// @fnv 0x00a6de50
void NiQuaternion::GetAngleAxis(float* angle, NiPoint3* axisPoint)
{
    float* axis = axisPoint->components;
    float fSquaredLength = m_fVectorY * m_fVectorY + m_fVectorZ * m_fVectorZ + m_fScalarPart * m_fScalarPart;
    volatile float root = (float)sqrt(fSquaredLength);
    float length = root;

    if (length < epsilon)
    {
        *angle = 0;
        axis[0] = 0;
        axis[1] = 0;
        axis[2] = 0;
        return;
    }

    float w = m_fVectorX;
    float fHalfAngle;
    if (w > DAT_0101a6b0)
    {
        if (w < 1.0f)
        {
            volatile float acosRoot = (float)acos(w);
            fHalfAngle = acosRoot;
        }
        else
        {
            fHalfAngle = 0;
        }
    }
    else
    {
        fHalfAngle = DAT_0109c9c4;
    }

    *angle = fHalfAngle + fHalfAngle;
    float invLength = 1.0f / length;
    axis[0] = invLength * m_fVectorY;
    axis[1] = invLength * m_fVectorZ;
    axis[2] = invLength * m_fScalarPart;
}

extern "C" double __cdecl fabs(double x);

inline float NiAbsA6E(float fValue)
{
    return (float)fabs(fValue);
}

static const float g_fSnapEpsilonA6E = 1e-08f;

// Sets each quaternion component to zero when its absolute value is at most g_fSnapEpsilonA6E but not already zero.
// @fnv 0x00a6e0f0
void NiQuaternion::Snap()
{
    if (NiAbsA6E(m_fVectorY) <= g_fSnapEpsilonA6E && m_fVectorY != 0.0f)
        m_fVectorY = 0.0f;
    if (NiAbsA6E(m_fVectorZ) <= g_fSnapEpsilonA6E && m_fVectorZ != 0.0f)
        m_fVectorZ = 0.0f;
    if (NiAbsA6E(m_fScalarPart) <= g_fSnapEpsilonA6E && m_fScalarPart != 0.0f)
        m_fScalarPart = 0.0f;
    if (NiAbsA6E(m_fVectorX) <= g_fSnapEpsilonA6E && m_fVectorX != 0.0f)
        m_fVectorX = 0.0f;
}

struct Quaternion
{
    float w, x, y, z;
    Quaternion* MultiplyQuaternion(Quaternion* out, const Quaternion* right);
};
Quaternion* __cdecl NiQuaternion_Log(Quaternion* out, const Quaternion* in);
void __cdecl NiQuaternion_Exp(Quaternion* out, const Quaternion* in);
extern const double DAT_0109c9e0;

// Combines two results from FUN_00a6dc90, scales their sum, passes it to FUN_00a88970, then multiplies by current.
// @fnv 0x00a6dd50
// src: COMMUNITY 0x00a6dd50
Quaternion* __cdecl NiQuaternion_Intermediate(Quaternion* output, const Quaternion* previous, Quaternion* current,
                                 const Quaternion* next)
{
    Quaternion inverse;
    inverse.w = current->w;
    inverse.x = -current->x;
    inverse.y = -current->y;
    inverse.z = -current->z;

    Quaternion qProductNext;
    Quaternion qLogNext;
    volatile Quaternion* pLogNext = NiQuaternion_Log(&qLogNext, inverse.MultiplyQuaternion(&qProductNext, next));

    Quaternion qProductPrev;
    Quaternion qLogPrev;
    Quaternion* pLogPrev = NiQuaternion_Log(&qLogPrev, inverse.MultiplyQuaternion(&qProductPrev, previous));

    inverse.w = pLogNext->w + pLogPrev->w;
    inverse.x = pLogNext->x + pLogPrev->x;
    inverse.y = pLogNext->y + pLogPrev->y;
    inverse.z = pLogNext->z + pLogPrev->z;

    Quaternion qScaled;
    qScaled.w = (float)(DAT_0109c9e0 * inverse.w);
    qScaled.x = (float)(DAT_0109c9e0 * inverse.x);
    qScaled.y = (float)(DAT_0109c9e0 * inverse.y);
    qScaled.z = (float)(DAT_0109c9e0 * inverse.z);

    Quaternion qExponential;
    NiQuaternion_Exp(&qExponential, &qScaled);
    current->MultiplyQuaternion(output, &qExponential);
    return output;
}

#include <math.h>
extern const float g_fQuatPi;  // 0x0109c9c4

inline float NiACos(float fValue)
{
    if (-1.0 < fValue)
    {
        if (fValue < 1.0f)
            return float(acos(fValue));
        else
            return 0.0f;
    }
    else
    {
        return g_fQuatPi;
    }
}

inline float NiSin(float fRadians)
{
    return sin(fRadians);
}

inline float NiAbs(float fValue)
{
    return float(fabs(fValue));
}

// Sets vector x to zero and scales the other vector components and scalar part by a coefficient derived from arccosine of vector x.
// @fnv 0x00a6dc90
// src: GAMEBRYO_LIB 0x00a6dc90
NiQuaternion __cdecl NiQuaternion_Log(const NiQuaternion& q)
{
    // q = cos(A)+sin(A)*(x*i+y*j+z*k), log(q) = A*(x*i+y*j+z*k)
    float fAngleDifference = NiACos(q.m_fVectorX);
    float fSin = NiSin(fAngleDifference);
    float fCoeff;
    if (NiAbs(fSin) < 1e-03f)
        fCoeff = 1.0f;
    else
        fCoeff = fAngleDifference / fSin;

    NiQuaternion kResult;
    kResult.m_fVectorX = 0.0f;
    kResult.m_fVectorY = fCoeff * q.m_fVectorY;
    kResult.m_fVectorZ = fCoeff * q.m_fVectorZ;
    kResult.m_fScalarPart = fCoeff * q.m_fScalarPart;
    return kResult;
}

// Computes a quaternion from three Euler angles (afXAngle, afYAngle, afZAngle) and stores the result in the vector and scalar parts.
// @fnv 0x00a6e1f0
void NiQuaternion::SetRotationFromEulerXYZ(float afXAngle, float afYAngle, float afZAngle)
{
    afXAngle = -afXAngle * 0.5;
    float cx = (float)cos(afXAngle);
    afYAngle = afYAngle * 0.5;
    float cy = (float)cos(afYAngle);
    afZAngle = -afZAngle * 0.5;
    float cz = (float)cos(afZAngle);
    float sx = (float)sin(afXAngle);
    float sy = (float)sin(afYAngle);
    float sz = (float)sin(afZAngle);
    float cycz = cy * cz;
    float sysz = sy * sz;
    m_fVectorX = cx * cycz + sx * sysz;
    m_fVectorY = sx * cycz - cx * sysz;
    m_fVectorZ = cx * sy * cz + sx * cy * sz;
    m_fScalarPart = cx * cy * sz - sx * sy * cz;
}

#include <string.h>
extern char* __cdecl NiSprintf(char*, unsigned int, const char*, ...);
extern void* __cdecl _NiMalloc(unsigned int);

// Allocates a buffer and writes the prefix and quaternion components using the shown format string.
// @fnv 0x00a6e190
char* NiQuaternion::FormatToBuffer(char* pcPrefix)
{
    unsigned int uiLen = strlen(pcPrefix) + 0x80;
    char* pcString = (char*)_NiMalloc(uiLen);
    NiSprintf(pcString, uiLen, "%s: (w=%g,x=%g,y=%g,z=%g)", pcPrefix, m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart);
    return pcString;
}
