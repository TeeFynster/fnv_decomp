#ifndef FNV_CONSOLE_NIPOINT3_INL
#define FNV_CONSOLE_NIPOINT3_INL


#include "nipoint3_decls.h"

// @fnv 0x00457990
float NiPoint3::ComputeMagnitude() const
{
    return NiSqrt_004579e0(x * x + y * y + z * z);
}

// @fnv 0x00457910
float NiPoint3::GetLengthSquared()
{
    float fScaleMultiplier = static_cast<const NiPoint3*>(this)->ComputeMagnitude();
    if (fScaleMultiplier > DAT_01017cf8)
    {
        float fInvLength = 1.0f / fScaleMultiplier;
        x *= fInvLength;
        y *= fInvLength;
        z *= fInvLength;
    }
    else
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        fScaleMultiplier = 0.0f;
    }
    return fScaleMultiplier;
}

// @fnv 0x0053d1a0
NiPoint3 NiPoint3::CrossProduct(const NiPoint3& kPoint) const
{
    NiPoint3 kCross(
        y * kPoint.z - z * kPoint.y,
        z * kPoint.x - x * kPoint.z,
        x * kPoint.y - y * kPoint.x);
    float fScaleMultiplier = static_cast<const NiPoint3&>(kCross).ComputeMagnitude();
    if (fScaleMultiplier > DAT_01017cf8)
        return kCross.ProcessAndReturnValue_0053d280(fScaleMultiplier);
    else
        return NiPoint3(0.0f, 0.0f, 0.0f);
}

#pragma optimize("gty", on)
// @fnv 0x00a69990
NiPlane::NiPlane(const NiPoint3& kNormal, const NiPoint3& kPoint)
{
    *reinterpret_cast<NiPoint3*>(&x) = kNormal;
    c = kNormal.x * kPoint.x + kNormal.y * kPoint.y + kNormal.z * kPoint.z;
}
#pragma optimize("", off)

#endif
