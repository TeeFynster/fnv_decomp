
// src/gamebryo2.2/corelibs/nicollision/nicapsulecapsuleintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicapsulecapsuleintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"

inline NiPoint3::NiPoint3(float fx, float fy, float afDepth) : x(fx), y(fy), z(afDepth)
{}

inline NiPoint3 NiPoint3::operator*(float s) const
{
    return NiPoint3(x * s, y * s, z * s);
}

inline NiPoint3 NiPoint3::operator*(double s) const
{
    return NiPoint3(x * s, y * s, z * s);
}

struct S_00eaee50_Line
{
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
};

struct S_00eaee50_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_00eaee50_Line m_kLine;
};

float NiSqrDistance_Compute(const S_00eaee50_Line& a, const S_00eaee50_Line& b, float* pS, float* pT);

struct S_00eaee50
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
    S_00eaee50_Shape* m_pkShapeA;
    S_00eaee50_Shape* m_pkShapeB;
    float m_fScale;
    float m_fParamA;
    float m_fParamB;

    float NiCapsuleCapsuleIntersector_Pseudodistance(const NiPoint3& kOffsetA, const NiPoint3& kOffsetB, float fTime);
};

// @fnv 0x00eaee50
// src: GAMEBRYO_LIB 0x00eaee50
float S_00eaee50::NiCapsuleCapsuleIntersector_Pseudodistance(const NiPoint3& kOffsetA, const NiPoint3& kOffsetB, float fTime)
{
    S_00eaee50_Line kA = m_pkShapeA->m_kLine;
    S_00eaee50_Line kB = m_pkShapeB->m_kLine;
    kA.m_kStartPoint += kOffsetA * fTime;
    kB.m_kStartPoint += kOffsetB * fTime;
    return NiSqrDistance_Compute(kA, kB, &m_fParamA, &m_fParamB) * m_fScale - 1.0;
}

inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}

inline void FUN_Offset(NiPoint3& kPt, const NiPoint3& kOff, float fScale)
{
    kPt += kOff * fScale;
}

extern const NiPoint3 DAT_011a9484;

struct S_Line : S_00eaee50_Line
{
    void NiSegment_GetPoint(NiPoint3& out, float t);
};

struct S_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    S_Line m_kLine;
    float m_fBoundRadius;
};

struct S_00eaef80
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float unk1C;
    NiPoint3 m_kPoint20;
    NiPoint3 m_kPoint2C;
    S_Shape* m_pkShapeA;
    S_Shape* m_pkShapeB;
    float m_fScale;
    float m_fParamA;
    float m_fParamB;

    void UpdatePoints(const NiPoint3& kOffsetA, const NiPoint3& kOffsetB);
};

inline NiPoint3 CopyPoint(const NiPoint3& p) { return NiPoint3(p.x, p.y, p.z); }

// @fnv 0x00eaef80
void S_00eaef80::UpdatePoints(const NiPoint3& kOffsetA, const NiPoint3& kOffsetB)
{
    NiPoint3 kPointA;
    m_pkShapeA->m_kLine.NiSegment_GetPoint(kPointA, m_fParamA);

    NiPoint3 kPointB;
    m_pkShapeB->m_kLine.NiSegment_GetPoint(kPointB, m_fParamB);

    if (unk18 == 2)
    {
        {
            NiPoint3 t = CopyPoint(kOffsetA * unk1C);
            kPointA += t;
        }
        FUN_Offset(kPointB, kOffsetB, unk1C);

        m_kPoint2C = kPointB - kPointA;
        m_kPoint2C.Unitize_004a0c10();

        m_kPoint20 = kPointA + m_kPoint2C * m_pkShapeA->m_fBoundRadius;
    }
    else
    {
        NiPoint3 kSum = kPointB + kPointA;
        m_kPoint20 = kSum * 0.5;

        if (kPointB != kPointA)
        {
            m_kPoint2C = kPointB - kPointA;
            m_kPoint2C.Unitize_004a0c10();
        }
        else
        {
            m_kPoint2C = DAT_011a9484;
        }
    }
}
