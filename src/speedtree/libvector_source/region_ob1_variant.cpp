
// src/speedtree/libvector_source/region_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/libvector_source/region.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/libvector_source/region.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/libvector_source/region.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Vec3Pt
{
    float m_v[3];
};

struct BoxCorner
{
    float m_v[3];
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    ~BoxCorner();
    float& operator[](int index)
    {
        return m_v[index];
    }
};

struct BoxBounds
{
    BoxCorner m_ucLowNibble;
    BoxCorner m_ucHighNibble;
    BoxBounds ComputeValue_00b3caa0(const Vec3Pt* p) const;
};

// @fnv 0x00b3caa0
// src: GUESS 0x00b3caa0 (confidence: low)
BoxBounds BoxBounds::ComputeValue_00b3caa0(const Vec3Pt* p) const
{

    BoxBounds tmp = *this;

    if (p->m_v[0] < tmp.m_ucLowNibble[0])
        tmp.m_ucLowNibble[0] = p->m_v[0];

    if (p->m_v[1] < tmp.m_ucLowNibble[1])
        tmp.m_ucLowNibble[1] = p->m_v[1];

    if (p->m_v[2] < tmp.m_ucLowNibble[2])
        tmp.m_ucLowNibble[2] = p->m_v[2];

    if (p->m_v[0] > tmp.m_ucHighNibble[0])
        tmp.m_ucHighNibble[0] = p->m_v[0];

    if (p->m_v[1] > tmp.m_ucHighNibble[1])
        tmp.m_ucHighNibble[1] = p->m_v[1];

    if (p->m_v[2] > tmp.m_ucHighNibble[2])
        tmp.m_ucHighNibble[2] = p->m_v[2];

    return tmp;
}
