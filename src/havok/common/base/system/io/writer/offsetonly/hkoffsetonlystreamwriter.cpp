
// src/havok/common/base/system/io/writer/offsetonly/hkoffsetonlystreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/offsetonly/hkoffsetonlystreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkReferencedObject.h"



struct FUN_00e02ef0 : hkReferencedObject
{
    int m_kPointA;
    int m_kPointB;

    FUN_00e02ef0();
    virtual void vf1();
};

// @fnv 0x00e02ef0
FUN_00e02ef0::FUN_00e02ef0()
{
    m_kPointA = 0;
    m_kPointB = 0;
}

struct E02E70Stats
{
    int unk00;
    int unk04;
    int m_pTileTemplate;
    int m_peak;

    int hkOffsetOnlyStreamWriter_write(void* p, int numBytes);
};

// Adds numBytes to the running total, updates the peak if the total exceeds it, and returns numBytes.
// @fnv 0x00e02e70
// src: HAVOK_LIB 0x00e02e70
int E02E70Stats::hkOffsetOnlyStreamWriter_write(void* p, int numBytes)
{
    m_pTileTemplate += numBytes;
    m_peak = (m_pTileTemplate > m_peak) ? m_pTileTemplate : m_peak;
    return numBytes;
}

class FUN_00e02e90_cls
{
  public:
    int unk00;
    int unk04;
    int m_08;
    int m_0c;
    int ApplyValue(int value, int mode);
};

// Applies value to m_08 according to mode (set, add, or subtract from m_0c), then stores the larger of m_08 and m_0c into m_0c and returns 0.
// @fnv 0x00e02e90
int FUN_00e02e90_cls::ApplyValue(int value, int mode)
{
    switch (mode)
    {
    case 0:
        m_08 = value;
        break;
    case 1:
        m_08 += value;
        break;
    case 2:
        m_08 = m_0c - value;
        break;
    }
    int iCurrent = m_08;
    int iOldMax = *(volatile int*)&m_0c;
    if (iCurrent > iOldMax)
    {
        m_0c = iCurrent;
    }
    else
    {
        m_0c = iOldMax;
    }
    return 0;
}

// @fnv 0x00e02f10
// src: XBOX_PDB 0x00e02f10
void __stdcall hkOffsetOnlyStreamWriter_isOk(unsigned char* output)
{
    *output = 1;
}

// @fnv 0x00e02f20
// src: XBOX_PDB 0x00e02f20
void __stdcall hkOffsetOnlyStreamWriter_seekTellSupported(unsigned char* output)
{
    *output = 1;
}

struct FUN_00e02ee0_cls
{
    virtual void vf00();
    int unk04;
    int unk08;

    int GetUnk08_00e02ee0();
};

// @fnv 0x00e02ee0
// src: GUESS 0x00e02ee0 (confidence: low)
int FUN_00e02ee0_cls::GetUnk08_00e02ee0()
{
    return unk08;
}
