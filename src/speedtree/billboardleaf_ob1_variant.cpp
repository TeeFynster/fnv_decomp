
// src/speedtree/billboardleaf_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/billboardleaf.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/billboardleaf.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/billboardleaf.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00b28440_Class
{
    float m_v[3];
    FUN_00b28440_Class& Scale(float s);
    const float& operator[](int i) const;
};

inline const float& FUN_00b28440_Class::operator[](int i) const
{
    return m_v[i];
}

struct FUN_00b404c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;

    void CBillboardLeaf_SetColor(const FUN_00b28440_Class* src, bool flag);
};

// @fnv 0x00b404c0
// src: COMMUNITY 0x00b404c0
void FUN_00b404c0_cls::CBillboardLeaf_SetColor(const FUN_00b28440_Class* src, bool flag)
{
    FUN_00b28440_Class v = *src;
    int i;
    if (flag)
    {
        v.Scale((float)((double)unk18 / 255.0));
    }
    for (i = 0; i < 3; ++i)
    {
        if (v.m_v[i] > 1.0)
        {
            v.m_v[i] = 1.0f;
        }
        if (v.m_v[i] < 0.0)
        {
            v.m_v[i] = 0.0f;
        }
    }
    unk14 = (int)(v[0] * 255.0) + ((int)(v[1] * 255.0) << 8) + ((int)(v[2] * 255.0) << 16) + 0xFF000000;
}

struct V3
{
    float x;
    float y;
    float z;
};
struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        fopen_0044a730(true, 0);
    }
    void fopen_0044a730(unsigned char b, unsigned n);
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, unsigned char bErrno) : FUN_00b096a0(bErrno ? FUN_0044a4c0("e") : msg)
    {
        int dq[40];
        dq[0] = 0;
    }
    virtual ~FUN_00b09480();
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float CTreeFileAccess_ParseFloat();
    int AdvanceBlockAllocationCursor();
    unsigned char GetNextChar();
    V3 GetVector3();
};
inline void DeadEnd()
{
    int aiD[14];
}
inline void DeadTop()
{
    int aiD[63];
    aiD[5] = 0;
}
struct LeafQ
{
    int i0;
    V3 kA;
    unsigned char b10;
    int i14;
    unsigned char b18;
    V3 kB;
    int ai28[6];
    unsigned char b40;
    float f44;
    int i48;
    LeafQ();
    void SetA(const V3& v)
    {
        int aiE[8];
        kA = v;
    }
};
// @fnv 0x00b405c0
// src: XBOX_PDB 0x00b405c0
LeafQ* CBillboardLeaf_Parse(Parser* p)
{
    LeafQ* pLeaf = new LeafQ;
    int iToken = p->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x1b5e:
            pLeaf->i14 = p->AdvanceBlockAllocationCursor();
            break;
        case 0x1b5f:
            pLeaf->b10 = p->GetNextChar();
            break;
        case 0x1b60:
            pLeaf->b18 = p->GetNextChar();
            break;
        case 0x1b62:
            pLeaf->kB = p->GetVector3();
            break;
        case 0x1b63:
            pLeaf->b40 = p->GetNextChar();
            break;
        case 0x1b64:
            pLeaf->f44 = p->GetNextChar() / 255.0;
            break;
        case 0x1b65:
            pLeaf->i48 = p->GetNextElement();
            break;
        case 0x1b67:
            pLeaf->SetA(p->GetVector3());
            break;
        case 0x1b68:
            p->CTreeFileAccess_ParseFloat();
            break;
        default:
            throw FUN_00b09480("malformed billboard leaf", false);
        }
        iToken = p->GetNextElement();
    } while (iToken != 0x1b5d);
    DeadEnd();
    return pLeaf;
}
