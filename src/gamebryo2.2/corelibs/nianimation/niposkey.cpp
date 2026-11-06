// gamebryo2.2/corelibs/nianimation/niposkey.cpp: PositionKeyInterpolator (4 functions)

#include "PointStorage.h"
#include "niposkey_decls.h"

// Finds the key interval containing time, interpolates between the lower and upper keys via DAT_011f3ca8[type], updates lastIndex and returns the result.
// @fnv 0x00a27490
NiPoint3 PositionKeyInterpolator::InterpolatePosition(float time, PositionKeyInterpolator* keys, KeyType type,
                                                      unsigned int count, unsigned int& lastIndex, unsigned char size)
{
    if (count == 1 || time == DAT_010241b0)
        return keys->GetPos();

    unsigned int last = count - 1;
    unsigned int lower = lastIndex;
    float lowerTime = keys->GetKeyAtIndex(lower, size)->GetTime();
    if (time < lowerTime)
    {
        lower = 0;
        lowerTime = keys->GetTime();
    }

    float upperTime = 0.0f;
    unsigned int upper = lower + 1;
    // The cached index identifies a valid interval with a following key.
    __assume(upper <= last);
    while (upper <= last)
    {
        upperTime = keys->GetKeyAtIndex(upper, size)->GetTime();
        if (time <= upperTime)
            break;
        ++lower;
        lowerTime = upperTime;
        ++upper;
    }

    float normalizedTime = (time - lowerTime) / (upperTime - lowerTime);
    NiPoint3 result;
    DAT_011f3ca8[type](normalizedTime, keys->GetKeyAtIndex(lower, size), keys->GetKeyAtIndex(upper, size), &result);
    lastIndex = lower;
    return result;
}

struct A27760Point3
{
    float x;
    float y;
    float z;

    bool operator==(const A27760Point3& pt) const
    {
        return x == pt.x && y == pt.y && z == pt.z;
    }
};

struct A27760Data
{
    int unk00;
    A27760Point3 m_kValue;
};

bool AreFloatsEqual(const A27760Data* pkA, const A27760Data* pkB);

// Returns true when AreFloatsEqual succeeds for both records and their m_kValue points compare equal.
// @fnv 0x00a27760
bool AreDataEqual(const A27760Data* pkA, const A27760Data* pkB)
{
    if (!AreFloatsEqual(pkA, pkB))
        return false;
    return pkA->m_kValue == pkB->m_kValue;
}

// A NiPoint3 (key position value, 0x011f365c is the zero point) with a user constructor, so it returns through the
// hidden pointer like the original 0x00a276a0. Not the shared NiPoint3: this unit's decls use the POD include/NiPoint3.h
// that ComputeFrenetFrame (0x00a277c0) matches with; include/'s flips its last cross product's x87 operand order.
struct NiPosKeyPoint3
{
    float x, y, z;
    NiPosKeyPoint3()
    {}
};
struct PKey
{
    float m_fTime;
    NiPosKeyPoint3 m_kPositionValue;
    float GetTime() const
    {
        return m_fTime;
    }
    const NiPosKeyPoint3& GetPos() const
    {
        return m_kPositionValue;
    }
    PKey* GetKeyAtIndex(unsigned int i, unsigned char s)
    {
        return (PKey*)((char*)this + i * s);
    }
};
extern NiPosKeyPoint3 DAT_011f365c;
NiPosKeyPoint3 __cdecl FUN_00a27490(float time, PKey* keys, int type, unsigned int count, unsigned int& lastIndex,
                        unsigned char size);
// Returns the key position for time, clamping to the first/last key when time is out of range, otherwise delegating to FUN_00a27490.
// @fnv 0x00a276a0
NiPosKeyPoint3 __cdecl GetKeyPosAtTime(float time, PKey* keys, int type, unsigned int count, unsigned char size)
{
    if (count)
    {
        if (time < keys->GetTime())
            return keys->GetPos();
        if (time > keys->GetKeyAtIndex(count - 1, size)->GetTime())
            return keys->GetKeyAtIndex(count - 1, size)->GetPos();
        unsigned int lastIndex = 0;
        return FUN_00a27490(time, keys, type, count, lastIndex, size);
    }
    return DAT_011f365c;
}

#include <math.h>
extern NiPosInterpFunction DAT_011f3c18[NiAnimationKey::NUMKEYTYPES];
extern NiPosInterpFunction DAT_011f3b88[NiAnimationKey::NUMKEYTYPES];
// The curve helpers hand their results back as plain point storage (copied out through a temporary).
inline PointStorage ScaleCurveVector(const NiPoint3& v, float s)
{
    PointStorage r;
    r.x = s * v.x;
    r.y = s * v.y;
    r.z = s * v.z;
    return r;
}
inline PointStorage CrossCurveVectors(const NiPoint3& a, const NiPoint3& b)
{
    PointStorage r;
    r.x = b.z * a.y - b.y * a.z;
    r.y = b.x * a.z - b.z * a.x;
    r.z = a.x * b.y - b.x * a.y;
    return r;
}
inline PointStorage InitialCrossCurveVectors(const NiPoint3& a, const NiPoint3& b)
{
    PointStorage r;
    double az = a.z;
    r.x = b.z * a.y - b.y * az;
    r.y = b.x * az - b.z * a.x;
    r.z = a.x * b.y - b.x * a.y;
    return r;
}
// Evaluates curve velocity and acceleration at time, then derives the tangent, normal, binormal and curvature for the animation key pair.
// @fnv 0x00a277c0
void __cdecl ComputeFrenetFrame(float time, const NiAnimationKey* key0, const NiAnimationKey* key1,
                                NiAnimationKey::KeyType type, NiPoint3& tangent, NiPoint3& normal, NiPoint3& binormal,
                                float& curvature)
{
    NiPosInterpFunction pFirstDerivative = DAT_011f3c18[type];
    NiPosInterpFunction pSecondDerivative = DAT_011f3b88[type];
    NiPoint3 velocity, vAcceleration;
    pFirstDerivative(time, key0, key1, &velocity);
    pSecondDerivative(time, key0, key1, &vAcceleration);
    float lengthSquared = velocity.Dot(velocity);
    float invLength = 1.0f / (float)sqrt(lengthSquared);
    reinterpret_cast<PointStorage&>(tangent) = ScaleCurveVector(velocity, invLength);
    PointStorage vCross = InitialCrossCurveVectors(velocity, vAcceleration);

    float crossLength = (float)sqrt(vCross.x * vCross.x + vCross.y * vCross.y + vCross.z * vCross.z);
    curvature = crossLength * invLength * invLength;
    if ((float)fabs(curvature) > 1e-6f)
    {
        float dot = velocity.Dot(vAcceleration);
        velocity *= dot;
        PointStorage vScaled = ScaleCurveVector(vAcceleration, lengthSquared);
        vAcceleration.x = vScaled.x - velocity.x;
        vAcceleration.y = vScaled.y - velocity.y;
        vAcceleration.z = vScaled.z - velocity.z;
        normal = vAcceleration;
    }
    else
    {
        curvature = 0.0f;
        if ((float)fabs(tangent.x) > 1e-6f || (float)fabs(tangent.y) > 1e-6f)
        {
            normal.x = tangent.y;
            normal.y = -tangent.x;
            normal.z = 0.0f;
        }
        else
        {
            normal.z = tangent.y;
            normal.y = -tangent.z;
            normal.x = 0.0f;
        }
    }
    normal.Unitize();
    reinterpret_cast<PointStorage&>(binormal) = CrossCurveVectors(tangent, normal);
}
