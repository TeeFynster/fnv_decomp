
// src/gamebryo2.2/corelibs/nicollision/niobbox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niobbox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiOBBRoot.h"
#include "../../../../include/NiTransform.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& p) const
{
    return NiPoint3(x + p.x, y + p.y, z + p.z);
}

inline float NiPoint3::Xvalue() const
{
    return x;
}

inline const float& NiPoint3::Xref() const
{
    return x;
}

inline const float& NiPoint3::Zref() const
{
    return z;
}

inline const float& NiPoint3::operator[](int i) const
{
    if (i == 0)
        return x;
    if (i == 1)
        return y;
    return z;
}

inline float NiPoint3::operator*(const NiPoint3& kV) const
{
    return x * kV.x + y * kV.y + z * kV.z;
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& kV) const
{
    return NiPoint3(x - kV.x, y - kV.y, z - kV.z);
}

inline NiPoint3 NiPoint3::Cross(const NiPoint3& r) const
{
    return NiPoint3(y * r.z - z * r.y, z * r.x - x * r.z, x * r.y - y * r.x);
}

inline NiPoint3 operator*(float s, const NiPoint3& p)
{
    return NiPoint3(s * p.x, s * p.y, s * p.z);
}

// M * v: each output coordinate is one matrix row dotted with v (x, y, z terms in that order)
#define M3_ROW_DOT_V(i) m_pEntry[i][0] * kV.x + m_pEntry[i][1] * kV.y + m_pEntry[i][2] * kV.z
inline NiPoint3 NiMatrix3::operator*(const NiPoint3& kV) const
{
    return NiPoint3(M3_ROW_DOT_V(0), M3_ROW_DOT_V(1), M3_ROW_DOT_V(2));
}
#undef M3_ROW_DOT_V

struct S_00eba480
{
    NiPoint3 m_kCenter;
    NiPoint3 m_akAxes[3];
    float m_afExtents[3];
    NiPoint3 m_kWorldCenter;
    NiPoint3 m_akWorldAxis[3];
    float m_afWorldExtent[3];

    void UpdateWorldBounds(const NiTransform& kXform);
};

// Transforms the center, axes and extents by kXform into the world-space center, axes and extents.
// @fnv 0x00eba480
void S_00eba480::UpdateWorldBounds(const NiTransform& kXform)
{
    m_kWorldCenter = kXform.m_fScale * (kXform.m_Rotate * m_kCenter) + kXform.m_Translate;
    m_akWorldAxis[0] = kXform.m_Rotate * m_akAxes[0];
    m_akWorldAxis[1] = kXform.m_Rotate * m_akAxes[1];
    m_akWorldAxis[2] = kXform.m_Rotate * m_akAxes[2];
    m_afWorldExtent[0] = m_afExtents[0] * kXform.m_fScale;
    m_afWorldExtent[1] = m_afExtents[1] * kXform.m_fScale;
    m_afWorldExtent[2] = m_afExtents[2] * kXform.m_fScale;
}

extern double DAT_01032980;

struct S_00ebf4a0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    NiPoint3 unk3C;
    NiPoint3 unk48;
    NiPoint3 unk54;
    NiPoint3 unk60;
    float unk6C;
    float unk70;
    float unk74;

    void ProjectOntoAxes(const NiPoint3* in, NiPoint3* out);
};

// @fnv 0x00ebf4a0
void S_00ebf4a0_Class::ProjectOntoAxes(const NiPoint3* in, NiPoint3* out)
{
    NiPoint3 norm;
    norm.x = unk6C;
    norm.y = unk70;
    norm.z = unk74;
    norm.Unitize_004a0c10();

    if (norm.x <= DAT_01032980)
    {
        *out = unk48;
        return;
    }
    if (norm.y <= DAT_01032980)
    {
        *out = unk54;
        return;
    }
    if (norm.z <= DAT_01032980)
    {
        *out = unk60;
        return;
    }

    norm.x = in->x - unk3C.x;
    norm.y = in->y - unk3C.y;
    norm.z = in->z - unk3C.z;

    float fDotX = norm.x * unk48.x + norm.y * unk48.y + norm.z * unk48.z;
    out->x = fDotX / (unk6C * unk6C);

    float fDotY = norm.x * unk54.x + norm.y * unk54.y + norm.z * unk54.z;
    out->y = fDotY / (unk70 * unk70);

    float fDotZ = norm.x * unk60.x + norm.y * unk60.y + norm.z * unk60.z;
    out->z = fDotZ / (unk74 * unk74);

    out->Unitize_004a0c10();
}

#include <math.h>

inline float NiAbs(float fValue)
{
    return float(fabs(fValue));
}

struct NiOBB
{
    NiPoint3 m_kCenter;
    NiPoint3 m_akBasis[3];
    float m_afExtents[3];
    NiPoint3 m_kWorldCenter;
    NiPoint3 m_akWorldBasis[3];
    float m_afWorldExtent[3];
    NiOBBRoot* m_pkTreeNode;

    int NiOBBox_FindIntersection(const NiOBB& kBox, float& rfTime, NiPoint3& rkPoint);
};

// Tests swept OBB collision against kBox, writing the earliest collision time to rfTime and the contact point to rkPoint, returning 1 on hit or 0 on miss.
// @fnv 0x00ebc2a0
// src: GAMEBRYO_LIB 0x00ebc2a0
int NiOBB::NiOBBox_FindIntersection(const NiOBB& kBox, float& rfHitTime, NiPoint3& rkHitPoint)
{
    const NiPoint3* pkA = m_akWorldBasis;
    const NiPoint3* pkB = kBox.m_akWorldBasis;
    const float* pfExtentsA = m_afWorldExtent;
    const float* pfExtentsB = kBox.m_afWorldExtent;

    float fRadiusA, fRadiusB, fRadiusSum, fProjNow, fProjEnd;
    float aafDotProducts[3][3];
    float afD0[3], afD1[3];

    NiPoint3 kDiff = kBox.m_kWorldCenter - m_kWorldCenter;
    NiPoint3 kVel = kBox.m_pkTreeNode->GetSourceVelocity() - m_pkTreeNode->GetSourceVelocity();
    float fTimeStep = m_pkTreeNode->GetDeltaTime();

    int iType = 0, iSide = 0;
    float fHitTime, fEarliestTime = 0.0f;

    aafDotProducts[0][0] = pkA[0] * pkB[0];
    aafDotProducts[0][1] = pkA[0] * pkB[1];
    aafDotProducts[0][2] = pkA[0] * pkB[2];
    fProjNow = afD0[0] = pkA[0] * kDiff;
    fProjEnd = afD1[0] = afD0[0] + fTimeStep * (kVel * pkA[0]);
    fRadiusA = NiAbs(pfExtentsA[0]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[0][0]) + NiAbs(pfExtentsB[1] * aafDotProducts[0][1]) +
               NiAbs(pfExtentsB[2] * aafDotProducts[0][2]);
    fRadiusSum = fRadiusA + fRadiusB;
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 1;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 1;
            iSide = -1;
        }
    }

    aafDotProducts[1][0] = pkA[1] * pkB[0];
    aafDotProducts[1][1] = pkA[1] * pkB[1];
    aafDotProducts[1][2] = pkA[1] * pkB[2];
    afD0[1] = pkA[1] * kDiff;
    afD1[1] = afD0[1] + fTimeStep * (pkA[1] * kVel);
    fRadiusA = NiAbs(pfExtentsA[1]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[1][0]) + NiAbs(pfExtentsB[1] * aafDotProducts[1][1]) +
               NiAbs(pfExtentsB[2] * aafDotProducts[1][2]);
    fRadiusSum = fRadiusA + fRadiusB;
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 2;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 2;
            iSide = -1;
        }
    }

    aafDotProducts[2][0] = pkA[2] * pkB[0];
    aafDotProducts[2][1] = pkA[2] * pkB[1];
    aafDotProducts[2][2] = pkA[2] * pkB[2];
    afD0[2] = pkA[2] * kDiff;
    afD1[2] = afD0[2] + fTimeStep * (pkA[2] * kVel);
    fRadiusA = NiAbs(pfExtentsA[2]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[2][0]) + NiAbs(pfExtentsB[1] * aafDotProducts[2][1]) +
               NiAbs(pfExtentsB[2] * aafDotProducts[2][2]);
    fRadiusSum = fRadiusA + fRadiusB;
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 3;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 3;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[0][0]) + NiAbs(pfExtentsA[1] * aafDotProducts[1][0]) +
               NiAbs(pfExtentsA[2] * aafDotProducts[2][0]);
    fRadiusB = NiAbs(pfExtentsB[0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = pkB[0] * kDiff;
    fProjEnd = fProjNow + fTimeStep * (pkB[0] * kVel);
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 4;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 4;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[0][1]) + NiAbs(pfExtentsA[1] * aafDotProducts[1][1]) +
               NiAbs(pfExtentsA[2] * aafDotProducts[2][1]);
    fRadiusB = NiAbs(pfExtentsB[1]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = pkB[1] * kDiff;
    fProjEnd = fProjNow + fTimeStep * (pkB[1] * kVel);
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 5;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 5;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[0][2]) + NiAbs(pfExtentsA[1] * aafDotProducts[1][2]) +
               NiAbs(pfExtentsA[2] * aafDotProducts[2][2]);
    fRadiusB = NiAbs(pfExtentsB[2]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = pkB[2] * kDiff;
    fProjEnd = fProjNow + fTimeStep * (pkB[2] * kVel);
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 6;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 6;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[1] * aafDotProducts[2][0]) + NiAbs(pfExtentsA[2] * aafDotProducts[1][0]);
    fRadiusB = NiAbs(pfExtentsB[1] * aafDotProducts[0][2]) + NiAbs(pfExtentsB[2] * aafDotProducts[0][1]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[2] * aafDotProducts[1][0] - afD0[1] * aafDotProducts[2][0];
    fProjEnd = afD1[2] * aafDotProducts[1][0] - afD1[1] * aafDotProducts[2][0];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 7;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 7;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[1] * aafDotProducts[2][1]) + NiAbs(pfExtentsA[2] * aafDotProducts[1][1]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[0][2]) + NiAbs(pfExtentsB[2] * aafDotProducts[0][0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[2] * aafDotProducts[1][1] - afD0[1] * aafDotProducts[2][1];
    fProjEnd = afD1[2] * aafDotProducts[1][1] - afD1[1] * aafDotProducts[2][1];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 8;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 8;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[1] * aafDotProducts[2][2]) + NiAbs(pfExtentsA[2] * aafDotProducts[1][2]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[0][1]) + NiAbs(pfExtentsB[1] * aafDotProducts[0][0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[2] * aafDotProducts[1][2] - afD0[1] * aafDotProducts[2][2];
    fProjEnd = afD1[2] * aafDotProducts[1][2] - afD1[1] * aafDotProducts[2][2];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 9;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 9;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[2][0]) + NiAbs(pfExtentsA[2] * aafDotProducts[0][0]);
    fRadiusB = NiAbs(pfExtentsB[1] * aafDotProducts[1][2]) + NiAbs(pfExtentsB[2] * aafDotProducts[1][1]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[0] * aafDotProducts[2][0] - afD0[2] * aafDotProducts[0][0];
    fProjEnd = afD1[0] * aafDotProducts[2][0] - afD1[2] * aafDotProducts[0][0];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 10;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 10;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[2][1]) + NiAbs(pfExtentsA[2] * aafDotProducts[0][1]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[1][2]) + NiAbs(pfExtentsB[2] * aafDotProducts[1][0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[0] * aafDotProducts[2][1] - afD0[2] * aafDotProducts[0][1];
    fProjEnd = afD1[0] * aafDotProducts[2][1] - afD1[2] * aafDotProducts[0][1];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 11;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 11;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[2][2]) + NiAbs(pfExtentsA[2] * aafDotProducts[0][2]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[1][1]) + NiAbs(pfExtentsB[1] * aafDotProducts[1][0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[0] * aafDotProducts[2][2] - afD0[2] * aafDotProducts[0][2];
    fProjEnd = afD1[0] * aafDotProducts[2][2] - afD1[2] * aafDotProducts[0][2];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 12;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 12;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[1][0]) + NiAbs(pfExtentsA[1] * aafDotProducts[0][0]);
    fRadiusB = NiAbs(pfExtentsB[1] * aafDotProducts[2][2]) + NiAbs(pfExtentsB[2] * aafDotProducts[2][1]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[1] * aafDotProducts[0][0] - afD0[0] * aafDotProducts[1][0];
    fProjEnd = afD1[1] * aafDotProducts[0][0] - afD1[0] * aafDotProducts[1][0];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 13;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 13;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[1][1]) + NiAbs(pfExtentsA[1] * aafDotProducts[0][1]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[2][2]) + NiAbs(pfExtentsB[2] * aafDotProducts[2][0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[1] * aafDotProducts[0][1] - afD0[0] * aafDotProducts[1][1];
    fProjEnd = afD1[1] * aafDotProducts[0][1] - afD1[0] * aafDotProducts[1][1];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 14;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 14;
            iSide = -1;
        }
    }

    fRadiusA = NiAbs(pfExtentsA[0] * aafDotProducts[1][2]) + NiAbs(pfExtentsA[1] * aafDotProducts[0][2]);
    fRadiusB = NiAbs(pfExtentsB[0] * aafDotProducts[2][1]) + NiAbs(pfExtentsB[1] * aafDotProducts[2][0]);
    fRadiusSum = fRadiusA + fRadiusB;
    fProjNow = afD0[1] * aafDotProducts[0][2] - afD0[0] * aafDotProducts[1][2];
    fProjEnd = afD1[1] * aafDotProducts[0][2] - afD1[0] * aafDotProducts[1][2];
    if (fProjNow > fRadiusSum)
    {
        if (fProjEnd > fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 15;
            iSide = 1;
        }
    }
    else if (fProjNow < -fRadiusSum)
    {
        if (fProjEnd < -fRadiusSum)
            return 0;
        fHitTime = fTimeStep * (-fRadiusSum - fProjNow) / (fProjEnd - fProjNow);
        if (fHitTime > fEarliestTime)
        {
            fEarliestTime = fHitTime;
            iType = 15;
            iSide = -1;
        }
    }

    rfHitTime = fEarliestTime;

    const float fEpsilon = 1e-06f;
    int i, j;
    float afX[3], afY[3], fProjA, fProjB, fDenom, fTmp;

    NiPoint3 kDTW;
    const NiPoint3& kV0 = m_pkTreeNode->GetSourceVelocity();
    const NiPoint3& kV1 = kBox.m_pkTreeNode->GetSourceVelocity();

    switch (iType)
    {
    case 1:
    case 2:
    case 3: {
        i = iType - 1;
        for (j = 0; j < 3; j++)
        {
            if (aafDotProducts[i][j] > 0.0f)
                afY[j] = -iSide * pfExtentsB[j];
            else if (aafDotProducts[i][j] < 0.0f)
                afY[j] = iSide * pfExtentsB[j];
            else
                afY[j] = 0.0f;
        }
        rkHitPoint = kBox.m_kWorldCenter + rfHitTime * kV1 + afY[0] * pkB[0] + afY[1] * pkB[1] + afY[2] * pkB[2];
        break;
    }
    case 4:
    case 5:
    case 6: {
        j = iType - 4;
        for (i = 0; i < 3; i++)
        {
            if (aafDotProducts[i][j] > 0.0f)
                afX[i] = iSide * pfExtentsA[i];
            else if (aafDotProducts[i][j] < 0.0f)
                afX[i] = -iSide * pfExtentsA[i];
            else
                afX[i] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 7: {
        if (aafDotProducts[2][0] > 0.0f)
            afX[1] = -iSide * pfExtentsA[1];
        else if (aafDotProducts[2][0] < 0.0f)
            afX[1] = iSide * pfExtentsA[1];
        else
            afX[1] = 0.0f;
        if (aafDotProducts[1][0] > 0.0f)
            afX[2] = iSide * pfExtentsA[2];
        else if (aafDotProducts[1][0] < 0.0f)
            afX[2] = -iSide * pfExtentsA[2];
        else
            afX[2] = 0.0f;
        if (aafDotProducts[0][2] > 0.0f)
            afY[1] = -iSide * pfExtentsB[1];
        else if (aafDotProducts[0][2] < 0.0f)
            afY[1] = iSide * pfExtentsB[1];
        else
            afY[1] = 0.0f;
        if (aafDotProducts[0][1] > 0.0f)
            afY[2] = iSide * pfExtentsB[2];
        else if (aafDotProducts[0][1] < 0.0f)
            afY[2] = -iSide * pfExtentsB[2];
        else
            afY[2] = 0.0f;
        fDenom = 1.0f - aafDotProducts[0][0] * aafDotProducts[0][0];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[0] * kDTW;
            fProjB = pkB[0] * kDTW;
            fTmp = aafDotProducts[1][0] * afX[1] + aafDotProducts[2][0] * afX[2] - fProjB;
            afX[0] =
                (fProjA + aafDotProducts[0][0] * fTmp + aafDotProducts[0][1] * afY[1] + aafDotProducts[0][2] * afY[2]) /
                fDenom;
        }
        else
        {
            afX[0] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 8: {
        if (aafDotProducts[2][1] > 0.0f)
            afX[1] = -iSide * pfExtentsA[1];
        else if (aafDotProducts[2][1] < 0.0f)
            afX[1] = iSide * pfExtentsA[1];
        else
            afX[1] = 0.0f;
        if (aafDotProducts[1][1] > 0.0f)
            afX[2] = iSide * pfExtentsA[2];
        else if (aafDotProducts[1][1] < 0.0f)
            afX[2] = -iSide * pfExtentsA[2];
        else
            afX[2] = 0.0f;
        if (aafDotProducts[0][2] > 0.0f)
            afY[0] = iSide * pfExtentsB[0];
        else if (aafDotProducts[0][2] < 0.0f)
            afY[0] = -iSide * pfExtentsB[0];
        else
            afY[0] = 0.0f;
        if (aafDotProducts[0][0] > 0.0f)
            afY[2] = -iSide * pfExtentsB[2];
        else if (aafDotProducts[0][0] < 0.0f)
            afY[2] = iSide * pfExtentsB[2];
        else
            afY[2] = 0.0f;
        fDenom = 1.0f - aafDotProducts[0][1] * aafDotProducts[0][1];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[0] * kDTW;
            fProjB = pkB[1] * kDTW;
            fTmp = aafDotProducts[1][1] * afX[1] + aafDotProducts[2][1] * afX[2] - fProjB;
            afX[0] =
                (fProjA + aafDotProducts[0][1] * fTmp + aafDotProducts[0][0] * afY[0] + aafDotProducts[0][2] * afY[2]) /
                fDenom;
        }
        else
        {
            afX[0] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 9: {
        if (aafDotProducts[2][2] > 0.0f)
            afX[1] = -iSide * pfExtentsA[1];
        else if (aafDotProducts[2][2] < 0.0f)
            afX[1] = iSide * pfExtentsA[1];
        else
            afX[1] = 0.0f;
        if (aafDotProducts[1][2] > 0.0f)
            afX[2] = iSide * pfExtentsA[2];
        else if (aafDotProducts[1][2] < 0.0f)
            afX[2] = -iSide * pfExtentsA[2];
        else
            afX[2] = 0.0f;
        if (aafDotProducts[0][1] > 0.0f)
            afY[0] = -iSide * pfExtentsB[0];
        else if (aafDotProducts[0][1] < 0.0f)
            afY[0] = iSide * pfExtentsB[0];
        else
            afY[0] = 0.0f;
        if (aafDotProducts[0][0] > 0.0f)
            afY[1] = iSide * pfExtentsB[1];
        else if (aafDotProducts[0][0] < 0.0f)
            afY[1] = -iSide * pfExtentsB[1];
        else
            afY[1] = 0.0f;
        fDenom = 1.0f - aafDotProducts[0][2] * aafDotProducts[0][2];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[0] * kDTW;
            fProjB = pkB[2] * kDTW;
            fTmp = aafDotProducts[1][2] * afX[1] + aafDotProducts[2][2] * afX[2] - fProjB;
            afX[0] =
                (fProjA + aafDotProducts[0][2] * fTmp + aafDotProducts[0][0] * afY[0] + aafDotProducts[0][1] * afY[1]) /
                fDenom;
        }
        else
        {
            afX[0] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 10: {
        if (aafDotProducts[2][0] > 0.0f)
            afX[0] = iSide * pfExtentsA[0];
        else if (aafDotProducts[2][0] < 0.0f)
            afX[0] = -iSide * pfExtentsA[0];
        else
            afX[0] = 0.0f;
        if (aafDotProducts[0][0] > 0.0f)
            afX[2] = -iSide * pfExtentsA[2];
        else if (aafDotProducts[0][0] < 0.0f)
            afX[2] = iSide * pfExtentsA[2];
        else
            afX[2] = 0.0f;
        if (aafDotProducts[1][2] > 0.0f)
            afY[1] = -iSide * pfExtentsB[1];
        else if (aafDotProducts[1][2] < 0.0f)
            afY[1] = iSide * pfExtentsB[1];
        else
            afY[1] = 0.0f;
        if (aafDotProducts[1][1] > 0.0f)
            afY[2] = iSide * pfExtentsB[2];
        else if (aafDotProducts[1][1] < 0.0f)
            afY[2] = -iSide * pfExtentsB[2];
        else
            afY[2] = 0.0f;
        fDenom = 1.0f - aafDotProducts[1][0] * aafDotProducts[1][0];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[1] * kDTW;
            fProjB = pkB[0] * kDTW;
            fTmp = aafDotProducts[0][0] * afX[0] + aafDotProducts[2][0] * afX[2] - fProjB;
            afX[1] =
                (fProjA + aafDotProducts[1][0] * fTmp + aafDotProducts[1][1] * afY[1] + aafDotProducts[1][2] * afY[2]) /
                fDenom;
        }
        else
        {
            afX[1] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 11: {
        if (aafDotProducts[2][1] > 0.0f)
            afX[0] = iSide * pfExtentsA[0];
        else if (aafDotProducts[2][1] < 0.0f)
            afX[0] = -iSide * pfExtentsA[0];
        else
            afX[0] = 0.0f;
        if (aafDotProducts[0][1] > 0.0f)
            afX[2] = -iSide * pfExtentsA[2];
        else if (aafDotProducts[0][1] < 0.0f)
            afX[2] = iSide * pfExtentsA[2];
        else
            afX[2] = 0.0f;
        if (aafDotProducts[1][2] > 0.0f)
            afY[0] = iSide * pfExtentsB[0];
        else if (aafDotProducts[1][2] < 0.0f)
            afY[0] = -iSide * pfExtentsB[0];
        else
            afY[0] = 0.0f;
        if (aafDotProducts[1][0] > 0.0f)
            afY[2] = -iSide * pfExtentsB[2];
        else if (aafDotProducts[1][0] < 0.0f)
            afY[2] = iSide * pfExtentsB[2];
        else
            afY[2] = 0.0f;
        fDenom = 1.0f - aafDotProducts[1][1] * aafDotProducts[1][1];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[1] * kDTW;
            fProjB = pkB[1] * kDTW;
            fTmp = aafDotProducts[0][1] * afX[0] + aafDotProducts[2][1] * afX[2] - fProjB;
            afX[1] =
                (fProjA + aafDotProducts[1][1] * fTmp + aafDotProducts[1][0] * afY[0] + aafDotProducts[1][2] * afY[2]) /
                fDenom;
        }
        else
        {
            afX[1] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 12: {
        if (aafDotProducts[2][2] > 0.0f)
            afX[0] = iSide * pfExtentsA[0];
        else if (aafDotProducts[2][2] < 0.0f)
            afX[0] = -iSide * pfExtentsA[0];
        else
            afX[0] = 0.0f;
        if (aafDotProducts[0][2] > 0.0f)
            afX[2] = -iSide * pfExtentsA[2];
        else if (aafDotProducts[0][2] < 0.0f)
            afX[2] = iSide * pfExtentsA[2];
        else
            afX[2] = 0.0f;
        if (aafDotProducts[1][1] > 0.0f)
            afY[0] = -iSide * pfExtentsB[0];
        else if (aafDotProducts[1][1] < 0.0f)
            afY[0] = iSide * pfExtentsB[0];
        else
            afY[0] = 0.0f;
        if (aafDotProducts[1][0] > 0.0f)
            afY[1] = iSide * pfExtentsB[1];
        else if (aafDotProducts[1][0] < 0.0f)
            afY[1] = -iSide * pfExtentsB[1];
        else
            afY[1] = 0.0f;
        fDenom = 1.0f - aafDotProducts[1][2] * aafDotProducts[1][2];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[1] * kDTW;
            fProjB = pkB[2] * kDTW;
            fTmp = aafDotProducts[0][2] * afX[0] + aafDotProducts[2][2] * afX[2] - fProjB;
            afX[1] =
                (fProjA + aafDotProducts[1][2] * fTmp + aafDotProducts[1][0] * afY[0] + aafDotProducts[1][1] * afY[1]) /
                fDenom;
        }
        else
        {
            afX[1] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 13: {
        if (aafDotProducts[1][0] > 0.0f)
            afX[0] = -iSide * pfExtentsA[0];
        else if (aafDotProducts[1][0] < 0.0f)
            afX[0] = iSide * pfExtentsA[0];
        else
            afX[0] = 0.0f;
        if (aafDotProducts[0][0] > 0.0f)
            afX[1] = iSide * pfExtentsA[1];
        else if (aafDotProducts[0][0] < 0.0f)
            afX[1] = -iSide * pfExtentsA[1];
        else
            afX[1] = 0.0f;
        if (aafDotProducts[2][2] > 0.0f)
            afY[1] = -iSide * pfExtentsB[1];
        else if (aafDotProducts[2][2] < 0.0f)
            afY[1] = iSide * pfExtentsB[1];
        else
            afY[1] = 0.0f;
        if (aafDotProducts[2][1] > 0.0f)
            afY[2] = iSide * pfExtentsB[2];
        else if (aafDotProducts[2][1] < 0.0f)
            afY[2] = -iSide * pfExtentsB[2];
        else
            afY[2] = 0.0f;
        fDenom = 1.0f - aafDotProducts[2][0] * aafDotProducts[2][0];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[2] * kDTW;
            fProjB = pkB[0] * kDTW;
            fTmp = aafDotProducts[0][0] * afX[0] + aafDotProducts[1][0] * afX[1] - fProjB;
            afX[2] =
                (fProjA + aafDotProducts[2][0] * fTmp + aafDotProducts[2][1] * afY[1] + aafDotProducts[2][2] * afY[2]) /
                fDenom;
        }
        else
        {
            afX[2] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 14: {
        if (aafDotProducts[1][1] > 0.0f)
            afX[0] = -iSide * pfExtentsA[0];
        else if (aafDotProducts[1][1] < 0.0f)
            afX[0] = iSide * pfExtentsA[0];
        else
            afX[0] = 0.0f;
        if (aafDotProducts[0][1] > 0.0f)
            afX[1] = iSide * pfExtentsA[1];
        else if (aafDotProducts[0][1] < 0.0f)
            afX[1] = -iSide * pfExtentsA[1];
        else
            afX[1] = 0.0f;
        if (aafDotProducts[2][2] > 0.0f)
            afY[0] = iSide * pfExtentsB[0];
        else if (aafDotProducts[2][2] < 0.0f)
            afY[0] = -iSide * pfExtentsB[0];
        else
            afY[0] = 0.0f;
        if (aafDotProducts[2][0] > 0.0f)
            afY[2] = -iSide * pfExtentsB[2];
        else if (aafDotProducts[2][0] < 0.0f)
            afY[2] = iSide * pfExtentsB[2];
        else
            afY[2] = 0.0f;
        fDenom = 1.0f - aafDotProducts[2][1] * aafDotProducts[2][1];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[2] * kDTW;
            fProjB = pkB[1] * kDTW;
            fTmp = aafDotProducts[0][1] * afX[0] + aafDotProducts[1][1] * afX[1] - fProjB;
            afX[2] =
                (fProjA + aafDotProducts[2][1] * fTmp + aafDotProducts[2][0] * afY[0] + aafDotProducts[2][2] * afY[2]) /
                fDenom;
        }
        else
        {
            afX[2] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    case 15: {
        if (aafDotProducts[1][2] > 0.0f)
            afX[0] = -iSide * pfExtentsA[0];
        else if (aafDotProducts[1][2] < 0.0f)
            afX[0] = iSide * pfExtentsA[0];
        else
            afX[0] = 0.0f;
        if (aafDotProducts[0][2] > 0.0f)
            afX[1] = iSide * pfExtentsA[1];
        else if (aafDotProducts[0][2] < 0.0f)
            afX[1] = -iSide * pfExtentsA[1];
        else
            afX[1] = 0.0f;
        if (aafDotProducts[2][1] > 0.0f)
            afY[0] = -iSide * pfExtentsB[0];
        else if (aafDotProducts[2][1] < 0.0f)
            afY[0] = iSide * pfExtentsB[0];
        else
            afY[0] = 0.0f;
        if (aafDotProducts[2][0] > 0.0f)
            afY[1] = iSide * pfExtentsB[1];
        else if (aafDotProducts[2][0] < 0.0f)
            afY[1] = -iSide * pfExtentsB[1];
        else
            afY[1] = 0.0f;
        fDenom = 1.0f - aafDotProducts[2][2] * aafDotProducts[2][2];
        if (NiAbs(fDenom) > fEpsilon)
        {
            kDTW = kDiff + rfHitTime * kVel;
            fProjA = pkA[2] * kDTW;
            fProjB = pkB[2] * kDTW;
            fTmp = aafDotProducts[0][2] * afX[0] + aafDotProducts[1][2] * afX[1] - fProjB;
            afX[2] =
                (fProjA + aafDotProducts[2][2] * fTmp + aafDotProducts[2][0] * afY[0] + aafDotProducts[2][1] * afY[1]) /
                fDenom;
        }
        else
        {
            afX[2] = 0.0f;
        }
        rkHitPoint = m_kWorldCenter + rfHitTime * kV0 + afX[0] * pkA[0] + afX[1] * pkA[1] + afX[2] * pkA[2];
        break;
    }
    }

    return 1;
}

extern float DAT_01015f5c;
extern float DAT_01016970;

static inline float S_00ebf610_Abs(float f)
{
    return (float)fabs(f);
}

struct S_00ebf610_Box
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    NiPoint3 m_kCenterPosition;
    NiPoint3 m_kAxisEndPoints[3];
    float m_fExtents[3];
    int IntersectRay(const NiPoint3& origin, const NiPoint3& dir);
};

// Tests whether a ray from origin along dir intersects this oriented box, returning 1 on hit and 0 on miss.
// @fnv 0x00ebf610
int S_00ebf610_Box::IntersectRay(const NiPoint3& origin, const NiPoint3& dir)
{
    float fNearT = DAT_01015f5c;
    float fFarT = DAT_01016970;
    float afExtents[3];
    afExtents[0] = S_00ebf610_Abs(m_fExtents[0]);
    afExtents[1] = S_00ebf610_Abs(m_fExtents[1]);
    afExtents[2] = S_00ebf610_Abs(m_fExtents[2]);
    NiPoint3 kDelta;
    kDelta.x = m_kCenterPosition.x - origin.x;
    kDelta.y = m_kCenterPosition.y - origin.y;
    kDelta.z = m_kCenterPosition.z - origin.z;
    for (int i = 0; i < 3; i++)
    {
        const NiPoint3& kAxis = m_kAxisEndPoints[i];
        const float* pfAxis = &m_kAxisEndPoints[i].x;
        float p = kDelta.x * pfAxis[0] + kDelta.y * pfAxis[1] + kDelta.z * pfAxis[2];
        float q = dir.x * m_kAxisEndPoints[i].x + dir.y * kAxis.y + dir.z * kAxis.z;
        if (S_00ebf610_Abs(q) > 1.0000000116860974e-07)
        {
            float inv = 1.0f / q;
            float t1;
            t1 = (afExtents[i] + p) * inv;
            float t2 = (p - afExtents[i]) * inv;
            if (t1 > t2)
            {
                float t = t1;
                t1 = t2;
                t2 = t;
            }
            if (fNearT < t1)
                fNearT = t1;
            if (t2 < fFarT)
                fFarT = t2;
            if (fNearT > fFarT || fFarT < 0.0f)
                return 0;
        }
        else if (S_00ebf610_Abs(p) > afExtents[i])
            return 0;
    }
    return 1;
}

#include <math.h>
namespace fnv_00eba680 {
extern "C" double fabs(double);
static float magnitude(float v)
{
    return (float)fabs(v);
}

extern "C" void _ReadWriteBarrier(void);
static float orderedDot(const NiPoint3& l, const NiPoint3& r)
{
    double py = r.y * l.y;
    _ReadWriteBarrier();
    double px = r.x * l.x;
    double pz = r.z * l.z;
    return (float)(px + py + pz);
}

static float projectionB1(const NiPoint3& l, const NiPoint3& r)
{
    return l.Xref() * r.Xvalue() + l.y * r.y + l.Zref() * r[2];
}

static float absTemporary(float v)
{
    float a = (float)fabs(v);
    return a;
}
static float val(float v)
{
    return v;
}

struct BoxE
{
    NiPoint3 localCenter;
    NiPoint3 localAxes[3];
    float localExtents[3];
    NiPoint3 center;
    NiPoint3 axes[3];
    float extents[3];
    const float* Extents() const
    {
        return extents;
    }
    NiOBBRoot* root;
    float Extent(int i) const
    {
        return extents[i];
    }
    int NiOBBox_TestIntersection(const BoxE& other);
};
// Performs a swept OBB vs OBB collision test using relative motion over root->GetDeltaTime(), returning 1 if the boxes intersect during the sweep.
// @fnv 0x00eba680
// src: GAMEBRYO_LIB 0x00eba680
int BoxE::NiOBBox_TestIntersection(const BoxE& other)
{
    const NiPoint3* a = axes;
    const NiPoint3* b = other.axes;
    const float* pExtents = extents;
    const float* pOtherExtents = other.extents;
    float fOwnRadius, fOtherRadius, fTotalRadius, start, end;
    float c[3][3], fStartProj[3], fEndProj[3];
    NiPoint3 vDelta = other.center - center;
    NiPoint3 vMotion = reinterpret_cast<const NiPoint3&>(other.root->GetSourceVelocity()) -
                      reinterpret_cast<const NiPoint3&>(root->GetSourceVelocity());
    float step = root->GetDeltaTime();

    c[0][0] = a[0] * b[0];
    c[0][1] = a[0] * b[1];
    c[0][2] = a[0] * b[2];
    fStartProj[0] = a[0] * vDelta;
    fEndProj[0] = fStartProj[0] + step * (a[0] * vMotion);
    fOwnRadius = magnitude(pExtents[0]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[0][0]) + magnitude(pOtherExtents[1] * c[0][1]) +
                   magnitude(pOtherExtents[2] * c[0][2]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    if ((fStartProj[0] > fTotalRadius && fEndProj[0] > fTotalRadius) ||
        (fStartProj[0] < -fTotalRadius && fEndProj[0] < -fTotalRadius))
        return 0;
    c[1][0] = a[1] * b[0];
    c[1][1] = a[1] * b[1];
    c[1][2] = a[1] * b[2];
    fStartProj[1] = a[1] * vDelta;
    fEndProj[1] = fStartProj[1] + step * (a[1] * vMotion);
    fOwnRadius = magnitude(extents[1]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[1][0]) + magnitude(pOtherExtents[1] * c[1][1]) +
                   magnitude(pOtherExtents[2] * c[1][2]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    if ((fStartProj[1] > fTotalRadius && fEndProj[1] > fTotalRadius) ||
        (fStartProj[1] < -fTotalRadius && fEndProj[1] < -fTotalRadius))
        return 0;
    c[2][0] = a[2] * b[0];
    c[2][1] = a[2] * b[1];
    c[2][2] = a[2] * b[2];
    fStartProj[2] = a[2] * vDelta;
    fEndProj[2] = fStartProj[2] + step * (a[2] * vMotion);
    fOwnRadius = absTemporary(extents[2]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[2][0]) + magnitude(pOtherExtents[1] * c[2][1]) +
                   magnitude(pOtherExtents[2] * c[2][2]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    if ((fStartProj[2] > fTotalRadius && fEndProj[2] > fTotalRadius) ||
        (fStartProj[2] < -fTotalRadius && fEndProj[2] < -fTotalRadius))
        return 0;
    fOwnRadius =
        magnitude(pExtents[0] * c[0][0]) + magnitude(Extent(1) * c[1][0]) + magnitude(val(pExtents[2]) * c[2][0]);
    fOtherRadius = magnitude(pOtherExtents[0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = orderedDot(b[0], vDelta);
    end = start + step * (orderedDot(b[0], vMotion));
    if ((start > fTotalRadius && end > fTotalRadius) || (start < -fTotalRadius && end < -fTotalRadius))
        return 0;
    fOwnRadius =
        magnitude(pExtents[0] * c[0][1]) + magnitude(Extent(1) * c[1][1]) + magnitude(val(pExtents[2]) * c[2][1]);
    fOtherRadius = magnitude(pOtherExtents[1]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = projectionB1(b[1], vDelta);
    end = start + step * (projectionB1(b[1], vMotion));
    if ((start > fTotalRadius && end > fTotalRadius) || (start < -fTotalRadius && end < -fTotalRadius))
        return 0;
    fOwnRadius = magnitude(pExtents[0] * c[0][2]) + magnitude(pExtents[1] * c[1][2]) + magnitude(pExtents[2] * c[2][2]);
    fOtherRadius = magnitude(pOtherExtents[2]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = b[2] * vDelta;
    end = start + step * (b[2] * vMotion);
    if ((start > fTotalRadius && end > fTotalRadius) || (start < -fTotalRadius && end < -fTotalRadius))
        return 0;
    fOwnRadius = magnitude(pExtents[1] * c[2][0]) + magnitude(pExtents[2] * c[1][0]);
    fOtherRadius = magnitude(pOtherExtents[1] * c[0][2]) + magnitude(pOtherExtents[2] * c[0][1]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[2] * c[1][0] - fStartProj[1] * c[2][0];
    if (start > fTotalRadius)
    {
        end = fEndProj[2] * c[1][0] - fEndProj[1] * c[2][0];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[2] * c[1][0] - fEndProj[1] * c[2][0];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(pExtents[1] * c[2][1]) + magnitude(pExtents[2] * c[1][1]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[0][2]) + magnitude(pOtherExtents[2] * c[0][0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[2] * c[1][1] - fStartProj[1] * c[2][1];
    if (start > fTotalRadius)
    {
        end = fEndProj[2] * c[1][1] - fEndProj[1] * c[2][1];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[2] * c[1][1] - fEndProj[1] * c[2][1];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(pExtents[1] * c[2][2]) + magnitude(pExtents[2] * c[1][2]);
    fOtherRadius = magnitude(other.extents[0] * c[0][1]) + magnitude(pOtherExtents[1] * c[0][0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[2] * c[1][2] - fStartProj[1] * c[2][2];
    if (start > fTotalRadius)
    {
        end = fEndProj[2] * c[1][2] - fEndProj[1] * c[2][2];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[2] * c[1][2] - fEndProj[1] * c[2][2];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(pExtents[0] * c[2][0]) + magnitude(pExtents[2] * c[0][0]);
    fOtherRadius = magnitude(pOtherExtents[1] * c[1][2]) + magnitude(val(pOtherExtents[2]) * c[1][1]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[0] * c[2][0] - fStartProj[2] * c[0][0];
    if (start > fTotalRadius)
    {
        end = fEndProj[0] * c[2][0] - fEndProj[2] * c[0][0];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[0] * c[2][0] - fEndProj[2] * c[0][0];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(Extents()[0] * c[2][1]) + magnitude(pExtents[2] * c[0][1]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[1][2]) + magnitude(pOtherExtents[2] * c[1][0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[0] * c[2][1] - fStartProj[2] * c[0][1];
    if (start > fTotalRadius)
    {
        end = fEndProj[0] * c[2][1] - fEndProj[2] * c[0][1];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[0] * c[2][1] - fEndProj[2] * c[0][1];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(extents[0] * c[2][2]) + magnitude(pExtents[2] * c[0][2]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[1][1]) + magnitude(pOtherExtents[1] * c[1][0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[0] * c[2][2] - fStartProj[2] * c[0][2];
    if (start > fTotalRadius)
    {
        end = fEndProj[0] * c[2][2] - fEndProj[2] * c[0][2];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[0] * c[2][2] - fEndProj[2] * c[0][2];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(Extent(0) * c[1][0]) + magnitude(pExtents[1] * c[0][0]);
    fOtherRadius = magnitude(pOtherExtents[1] * c[2][2]) + magnitude(pOtherExtents[2] * c[2][1]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[1] * c[0][0] - fStartProj[0] * c[1][0];
    if (start > fTotalRadius)
    {
        end = fEndProj[1] * c[0][0] - fEndProj[0] * c[1][0];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[1] * c[0][0] - fEndProj[0] * c[1][0];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(extents[0] * c[1][1]) + magnitude(Extent(1) * c[0][1]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[2][2]) + magnitude(val(pOtherExtents[2]) * c[2][0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[1] * c[0][1] - fStartProj[0] * c[1][1];
    if (start > fTotalRadius)
    {
        end = fEndProj[1] * c[0][1] - fEndProj[0] * c[1][1];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[1] * c[0][1] - fEndProj[0] * c[1][1];
        if (end < -fTotalRadius)
            return 0;
    }
    fOwnRadius = magnitude(pExtents[0] * c[1][2]) + magnitude(Extent(1) * c[0][2]);
    fOtherRadius = magnitude(pOtherExtents[0] * c[2][1]) + magnitude(pOtherExtents[1] * c[2][0]);
    fTotalRadius = fOwnRadius + fOtherRadius;
    start = fStartProj[1] * c[0][2] - fStartProj[0] * c[1][2];
    if (start > fTotalRadius)
    {
        end = fEndProj[1] * c[0][2] - fEndProj[0] * c[1][2];
        if (end > fTotalRadius)
            return 0;
    }
    else if (start < -fTotalRadius)
    {
        end = fEndProj[1] * c[0][2] - fEndProj[0] * c[1][2];
        if (end < -fTotalRadius)
            return 0;
    }
    NiPoint3 vSweep = vMotion.Cross(vDelta);
    float va[3], vb[3], distance, fOwnProj, fOtherProj, fTotalProj;
    va[1] = vMotion.Dot(a[1]);
    float& projection1 = va[2];
    projection1 = vMotion.Dot(a[2]);
    distance = magnitude(a[0].Dot(vSweep));
    fOwnProj = pExtents[1] * magnitude(projection1) + pExtents[2] * magnitude(va[1]);
    fOtherProj = pOtherExtents[0] * magnitude(c[1][0] * projection1 - c[2][0] * va[1]) +
                 pOtherExtents[1] * magnitude(c[1][1] * projection1 - c[2][1] * va[1]) +
                 pOtherExtents[2] * magnitude(c[1][2] * projection1 - c[2][2] * va[1]);
    fTotalProj = fOwnProj + fOtherProj;
    if (distance > fTotalProj)
        return 0;
    float& projection2 = va[0];
    projection2 = vMotion.Dot(a[0]);
    distance = magnitude(a[1].Dot(vSweep));
    fOwnProj = Extent(2) * magnitude(projection2) + pExtents[0] * magnitude(projection1);
    fOtherProj = other.Extent(0) * magnitude(c[2][0] * projection2 - c[0][0] * projection1) +
                 other.extents[1] * magnitude(c[2][1] * projection2 - c[0][1] * projection1) +
                 other.extents[2] * magnitude(c[2][2] * projection2 - c[0][2] * projection1);
    fTotalProj = fOwnProj + fOtherProj;
    if (distance > fTotalProj)
        return 0;
    distance = magnitude(a[2].Dot(vSweep));
    fOwnProj = pExtents[0] * magnitude(va[1]) + pExtents[1] * magnitude(projection2);
    fOtherProj = other.extents[0] * magnitude(c[0][0] * va[1] - c[1][0] * projection2) +
                 pOtherExtents[1] * magnitude(c[0][1] * va[1] - c[1][1] * projection2) +
                 pOtherExtents[2] * magnitude(c[0][2] * va[1] - c[1][2] * projection2);
    fTotalProj = fOwnProj + fOtherProj;
    if (distance > fTotalProj)
        return 0;
    vb[1] = vMotion.Dot(b[1]);
    vb[2] = vMotion.Dot(b[2]);
    distance = magnitude(b[0].Dot(vSweep));
    fOwnProj = pExtents[0] * magnitude(c[0][1] * vb[2] - c[0][2] * vb[1]) +
               pExtents[1] * magnitude(c[1][1] * vb[2] - c[1][2] * vb[1]) +
               Extent(2) * magnitude(c[2][1] * vb[2] - c[2][2] * vb[1]);
    fOtherProj = other.extents[2] * magnitude(vb[1]) + other.extents[1] * magnitude(vb[2]);
    fTotalProj = fOwnProj + fOtherProj;
    if (distance > fTotalProj)
        return 0;
    vb[0] = vMotion.Dot(b[0]);
    distance = magnitude(b[1].Dot(vSweep));
    fOwnProj = extents[0] * magnitude(c[0][2] * vb[0] - c[0][0] * vb[2]) +
               Extent(1) * magnitude(c[1][2] * vb[0] - c[1][0] * vb[2]) +
               Extent(2) * magnitude(c[2][2] * vb[0] - c[2][0] * vb[2]);
    fOtherProj = other.extents[2] * magnitude(vb[0]) + other.Extents()[0] * magnitude(vb[2]);
    fTotalProj = fOwnProj + fOtherProj;
    if (distance > fTotalProj)
        return 0;
    distance = magnitude(b[2].Dot(vSweep));
    fOwnProj = pExtents[0] * magnitude(c[0][0] * vb[1] - c[0][1] * vb[0]) +
               pExtents[1] * magnitude(c[1][0] * vb[1] - c[1][1] * vb[0]) +
               pExtents[2] * magnitude(c[2][0] * vb[1] - c[2][1] * vb[0]);
    fOtherProj = other.extents[0] * magnitude(vb[1]) + other.extents[1] * magnitude(vb[0]);
    fTotalProj = fOwnProj + fOtherProj;
    if (distance > fTotalProj)
        return 0;
    return 1;
}
}  // namespace fnv_00eba680
