#pragma once

#include "NiPoint3.h"

class FNVVec3;
class NiStream;
class NiMatrix3;

class NiPlane
{
public:
    float x;
    float y;
    float z;
    float c;

    NiPlane();
    NiPlane(const NiPoint3& normal, float constant);
    NiPlane(const NiPoint3& normal, const NiPoint3& point);

    bool operator==(const NiPlane& other);
    bool operator==(const NiPlane& other) const;
    bool operator==(const NiPoint3& point);

    bool FUN_00439090(const NiPlane* other);
    bool HasEqualComponents(const NiPlane& other);
    bool HasEqualComponents(const NiPoint3& point);

    void Apply(const NiMatrix3& matrix, const NiPoint3& translation);
    int Side(const FNVVec3& point) const;
    float Distance(const FNVVec3& point) const;
    float Distance(const NiPoint3& point) const;
    const NiPoint3& GetPlaneNormal() const;
    float GetPlaneConstant() const;
    float FUN_0084d030() const;
    void LoadBinary(NiStream& stream);
};
