#include "../../../../include/NiQuatTransform.h"

// The original copies the translation and rotation as plain data; the shared NiQuaternion declares an out-of-line operator=.
struct NiQuaternionValue
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
};

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;

#pragma optimize("", off)
// @fnv 0x00494260
NiQuatTransform::NiQuatTransform()
{
    *(NiPoint3*)&x = DAT_011a8400;
    *(NiQuaternionValue*)&qx = *(const NiQuaternionValue*)&DAT_011f3704;
    scale = DAT_01096b8c;
}

#pragma optimize("", on)
// @fnv 0x00a39180
bool NiQuatTransform::IsInvalid() const
{
    return scale == -3.4028234663852886e+38 && qy == -3.4028234663852886e+38 && x == -3.4028234663852886e+38;
}

