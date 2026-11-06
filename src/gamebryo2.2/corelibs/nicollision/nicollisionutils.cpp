// gamebryo2.2/corelibs/nicollision/nicollisionutils.cpp: RayTriangleIntersector (1 function)

#include "nicollisionutils_decls.h"

inline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& p) const
{
    return NiPoint3(x - p.x, y - p.y, z - p.z);
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    return NiPoint3(x + p.x, y + p.y, z + p.z);
}

inline NiPoint3 NiPoint3::Cross(const NiPoint3& p) const
{
    return NiPoint3(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
}

// @fnv 0x00eadb90
bool RayTriangleIntersector::IntersectRayTriangle(const NiPoint3& aOrigin, const NiPoint3& aDirection,
                                                  const NiPoint3& aVertex0, const NiPoint3& aVertex1,
                                                  const NiPoint3& aVertex2, bool cull, NiPoint3& hit, float& t,
                                                  float& u, float& v)
{
    NiPoint3 edge1 = aVertex1 - aVertex0;
    NiPoint3 edge2 = aVertex2 - aVertex0;
    NiPoint3 pVec = aDirection.Cross(edge2);
    float det = edge1.Dot(pVec);
    if (det >= 0.00001f)
    {
        NiPoint3 sVec = aOrigin - aVertex0;
        u = sVec.Dot(pVec);
        if (u < 0.0f || u > det)
            return false;
        NiPoint3 qVec = sVec.Cross(edge1);
        v = aDirection.Dot(qVec);
        if (v < 0.0f || u + v > det)
            return false;
        t = edge2.Dot(qVec);
        if (t < 0.0f)
            return false;
    }
    else if (det <= -0.00001f && !cull)
    {
        NiPoint3 sVec = aOrigin - aVertex0;
        u = sVec.Dot(pVec);
        if (u > 0.0f || u < det)
            return false;
        NiPoint3 qVec = sVec.Cross(edge1);
        v = aDirection.Dot(qVec);
        if (v > 0.0f || u + v < det)
            return false;
        t = edge2.Dot(qVec);
        if (t > 0.0f)
            return false;
    }
    else
        return false;
    float fInvDet = 1.0f / det;
    u *= fInvDet;
    v *= fInvDet;
    t *= fInvDet;
    hit = aOrigin + NiPosData::ComputePositionAtTime(t, aDirection);
    return true;
}
