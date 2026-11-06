
// src/speedtree/leafinfo.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/leafinfo.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/NiPoint3.h"

class Sub14_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;

    void AssignSubstring(const Sub14_cls* src, int zero, int value);
};

class Scratch_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
};

extern int DAT_010173f0;

class FUN_00b2e680_cls
{
  public:
    FUN_00b2e680_cls(const FUN_00b2e680_cls& src);

    unsigned char m_b00;
    // Raw storage avoids default construction before the copy constructor assigns the points.
    float m_p04[3];
    float m_f10;
    Sub14_cls m_s14;
    float m_p30[3];
    float m_p3c[3];
    float m_p48[3];
};

// Copies the fields of src into this, delegating the embedded Sub14_cls member to AssignSubstring with DAT_010173f0.
// @fnv 0x00b2e680
FUN_00b2e680_cls::FUN_00b2e680_cls(const FUN_00b2e680_cls& src)
{
    Scratch_cls scratch;
    unsigned int tail;

    this->m_b00 = src.m_b00;
    *reinterpret_cast<NiPoint3*>(this->m_p04) = *reinterpret_cast<const NiPoint3*>(src.m_p04);
    this->m_f10 = src.m_f10;
    Sub14_cls* sub = &m_s14;
    sub->AssignSubstring(&src.m_s14, 0, DAT_010173f0);
    *reinterpret_cast<NiPoint3*>(this->m_p30) = *reinterpret_cast<const NiPoint3*>(src.m_p30);
    *reinterpret_cast<NiPoint3*>(this->m_p3c) = *reinterpret_cast<const NiPoint3*>(src.m_p3c);
    *reinterpret_cast<NiPoint3*>(this->m_p48) = *reinterpret_cast<const NiPoint3*>(src.m_p48);
}

struct S_00b3cf40_Random
{
    S_00b3cf40_Random();
    ~S_00b3cf40_Random();
    float FUN_00b3f130(float lo, float hi);
};

static const float DAT_01022958 = 10000.0f;

struct S_00b3cf40
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
    int unk3C;
    int m_uiItemCount;  // 40
    int m_rows;         // 44
    int m_iElementCount;         // 48
    float** m_tables;   // 4C
    float* m_verts;     // 50
    float* m_iSlotIds;  // 54
    void Init(int size);
};

// @fnv 0x00b3cf40
void S_00b3cf40::Init(int size)
{
    m_iElementCount = size;
    m_iSlotIds = new float[m_uiItemCount];
    S_00b3cf40_Random rng;
    for (int iIndex = 0; iIndex < m_uiItemCount; iIndex++)
        m_iSlotIds[iIndex] = rng.FUN_00b3f130(0.0f, DAT_01022958);

    m_verts = new float[size * 16];
    float* pfVert = m_verts;
    for (int iIndex = 0; iIndex < size * 2; iIndex++)
    {
        *pfVert = 0.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 1.0f;
        pfVert++;
        *pfVert = 0.0f;
        pfVert++;
        *pfVert = 0.0f;
        pfVert++;
        *pfVert = 0.0f;
        pfVert++;
    }

    m_tables = new float*[m_rows];
    int iTableCount = size * 2 * m_uiItemCount * 16;
    for (int iIndex = 0; iIndex < m_rows; iIndex++)
    {
        m_tables[iIndex] = new float[iTableCount];
        for (int jIndex = 0; jIndex < iTableCount; jIndex++)
            m_tables[iIndex][jIndex] = 0.0f;
    }
}
