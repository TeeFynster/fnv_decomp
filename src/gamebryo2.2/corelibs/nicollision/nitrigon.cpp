// src/gamebryo2.2/corelibs/nicollision/nitrigon.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nitrigon.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct EB3830Point3
{
    float x;
    float y;
    float z;

    EB3830Point3()
    {}
    EB3830Point3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    EB3830Point3 Cross(const EB3830Point3& pt) const
    {
        return EB3830Point3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    }
    void Unitize();
};

struct EB3830Triangle
{
    int unk00;
    int unk04;
    int unk08;
    EB3830Point3 m_kEdgeA;
    EB3830Point3 m_kEdgeB;

    EB3830Point3 NiTrigon_GetNormal() const;
};

// Computes the cross product of m_kEdgeA and m_kEdgeB, normalizes it, and returns the resulting vector.
// @fnv 0x00eb3830
// src: COMMUNITY 0x00eb3830
EB3830Point3 EB3830Triangle::NiTrigon_GetNormal() const
{
    EB3830Point3 kNormal = m_kEdgeA.Cross(m_kEdgeB);
    kNormal.Unitize();
    return kNormal;
}
