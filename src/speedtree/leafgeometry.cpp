
// src/speedtree/leafgeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/leafgeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct LeafLod
{
    char b[0x44];
};
struct SpeedTreeLodData
{
    char m_auiShapeKeys[0x28];
    unsigned short m_usValueAt28;
    char m_pAuxiliaryObject[2];
    LeafLod* m_pLeafLod;
    void CLeafGeometry_Invalidate();
};
// @fnv 0x00b27820
// src: COMMUNITY 0x00b27820
void SpeedTreeLodData::CLeafGeometry_Invalidate()
{
    if (m_pLeafLod)
    {
        for (int i = 0; i < m_usValueAt28; ++i)
        {
            char* pEntry = (char*)m_pLeafLod + i * 0x44;
            *(unsigned char*)(pEntry + 0x3c) = 0;
        }
    }
}

struct FUN_00b28440_Class
{
    float x;
    float y;
    float z;
    FUN_00b28440_Class& Scale(float scale);
};

// Multiplies the x, y and z components by scale and returns a reference to this object.
// @fnv 0x00b28440
FUN_00b28440_Class& FUN_00b28440_Class::Scale(float scale)
{
    x *= scale;
    y *= scale;
    z *= scale;
    return *this;
}

struct FUN_00b27870_Class
{
    unsigned char m_bValueAt00;
    unsigned char m_auiShapeKeys[7];
    unsigned short m_usValueAt08;
    unsigned char m_pAuxiliaryObject[6];
    float** m_ppFloatData;
    unsigned char m_pad3[4];
    float* m_pCopiedLodData;
    unsigned short m_usValue;

    const float* CopyLodData(unsigned int& aiFloatCount);
};

void* __cdecl _memmove(void* dest, const void* src, unsigned int count);

// @fnv 0x00b27870
const float* FUN_00b27870_Class::CopyLodData(unsigned int& auiOffset)
{
    float* pSearchEntries = m_pCopiedLodData;
    int nLodSize = m_usValue * m_usValueAt08 * 2 * 4 * 4;

    if (pSearchEntries != 0 && m_ppFloatData != 0 && m_ppFloatData[0] != 0 && m_pCopiedLodData != 0)
    {
        _memmove(pSearchEntries, m_ppFloatData[0], nLodSize * sizeof(float));
        pSearchEntries += nLodSize;
        auiOffset = pSearchEntries - m_pCopiedLodData;
    }

    return m_pCopiedLodData;
}

extern "C" bool CSpeedTreeRT_GetTextureFlip();
extern const float DAT_01012054;

struct FUN_00b28720_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float* m_pLeafTable;

    void SetLeafTableEntry(int nLeaf, const float* pSrc);
};

// Writes two 8-float rows into m_pLeafTable at index nLeaf, scaling odd components by DAT_01012054 or 1.0f depending on FUN_00b0d7a0.
// @fnv 0x00b28720
void FUN_00b28720_Class::SetLeafTableEntry(int aiLeafIndex, const float* apSrcFloats)
{
    if (m_pLeafTable && apSrcFloats)
    {
        float fOddScale = CSpeedTreeRT_GetTextureFlip() ? DAT_01012054 : 1.0f;

        float* pfDest = m_pLeafTable + (aiLeafIndex * 2) * 8;
        *pfDest++ = apSrcFloats[0];
        *pfDest++ = fOddScale * apSrcFloats[1];
        *pfDest++ = apSrcFloats[2];
        *pfDest++ = fOddScale * apSrcFloats[3];
        *pfDest++ = apSrcFloats[4];
        *pfDest++ = fOddScale * apSrcFloats[5];
        *pfDest++ = apSrcFloats[6];
        *pfDest++ = fOddScale * apSrcFloats[7];

        pfDest = m_pLeafTable + (aiLeafIndex * 2 + 1) * 8;
        *pfDest++ = apSrcFloats[2];
        *pfDest++ = fOddScale * apSrcFloats[1];
        *pfDest++ = apSrcFloats[0];
        *pfDest++ = fOddScale * apSrcFloats[3];
        *pfDest++ = apSrcFloats[6];
        *pfDest++ = fOddScale * apSrcFloats[5];
        *pfDest++ = apSrcFloats[4];
        *pfDest++ = fOddScale * apSrcFloats[7];
    }
}

struct LodB28
{
    char pad[0x10];
    char *p10, *p14, *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34, *p38;
    int pad3c;
    char* p40;
};
struct CB28
{
    char pad[0x28];
    unsigned short count;
    char pad2[2];
    LodB28* lods;
    void FreeLodBuffers();
};
// Frees the twelve heap buffers of each of the count LOD entries and nulls the pointers.
// @fnv 0x00b28ed0
void CB28::FreeLodBuffers()
{
    if (lods && count)
    {
        for (int i = 0; i < count; ++i)
        {
            delete[] lods[i].p10;
            delete[] lods[i].p14;
            delete[] lods[i].p18;
            delete[] lods[i].p24;
            delete[] lods[i].p28;
            delete[] lods[i].p2c;
            delete[] lods[i].p30;
            delete[] lods[i].p1c;
            delete[] lods[i].p20;
            delete[] lods[i].p34;
            delete[] lods[i].p38;
            lods[i].p10 = 0;
            lods[i].p14 = 0;
            lods[i].p18 = 0;
            lods[i].p24 = 0;
            lods[i].p28 = 0;
            lods[i].p2c = 0;
            lods[i].p30 = 0;
            lods[i].p1c = 0;
            lods[i].p20 = 0;
            lods[i].p34 = 0;
            lods[i].p38 = 0;
            delete[] lods[i].p40;
            lods[i].p40 = 0;
        }
    }
}

namespace CSpeedTreeRT {
struct TreeLodData
{
    struct TreeLodEntry
    {
        bool m_bVisible;
        char m_iValueAfterStandIn[7];
        unsigned int m_usLodLevel;
        char m_pAuxiliaryObject[48];
    };
};
}

struct FUN_00b28e40_Class
{
    struct SpeedTreeGeometryRecord
    {
        CSpeedTreeRT::TreeLodData::TreeLodEntry m_sGeometry;
        char m_auiShapeKeys[8];
    };

    bool m_bValueAt00;
    char m_iValueAfterStandIn[3];
    void* m_pObjectAt04;
    unsigned short m_usValueAt08;
    char m_pAuxiliaryObject[2];
    float* m_pfFloatData;
    float** m_ppFloatData;
    char m_pad3[0x0c];
    void* m_pObjectAt20;
    void* m_pObjectAt24;
    unsigned short m_usValueAt28;
    char m_pad4[2];
    SpeedTreeGeometryRecord* m_pLeafLod;

    void SetLeafLodGeometry(CSpeedTreeRT::TreeLodData::TreeLodEntry& sGeometry, unsigned short usLodLevel,
                            float fAzimuth, float fCurrentSpeed, float fSizeIncreaseFactor);
};

// If usLodLevel is in range and the required pointers are non-null, copies that leaf LOD geometry record into sGeometry and marks it visible.
// @fnv 0x00b28e40
void FUN_00b28e40_Class::SetLeafLodGeometry(CSpeedTreeRT::TreeLodData::TreeLodEntry& sGeometry,
                                            unsigned short usLodLevel, float fAzimuth, float fCurrentSpeed,
                                            float fSizeIncreaseFactor)
{
    SpeedTreeGeometryRecord* pLod;
    if (m_pLeafLod && usLodLevel < m_usValueAt28 && m_ppFloatData && m_pObjectAt24 && m_pObjectAt20 && m_pObjectAt04 &&
        m_pfFloatData)
    {
        pLod = &m_pLeafLod[usLodLevel];
        sGeometry = pLod->m_sGeometry;
        sGeometry.m_bVisible = true;
        sGeometry.m_usLodLevel = usLodLevel;
    }
}
