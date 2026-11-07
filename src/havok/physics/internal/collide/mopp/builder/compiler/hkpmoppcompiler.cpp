
// src/havok/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/compiler/hkpmoppcompiler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct InitArg;

struct SubFirst
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;

    void hkpMoppSplitter_hkpMoppSplitParams_hkpMoppSplitParams(InitArg* apArg);
};

struct SubSecond
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;

    void hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(InitArg* apArg);
};

struct FUN_00dd4bf0
{
    int m_i00;
    int m_i04;
    SubFirst m_kFirst;
    SubSecond m_kSecond;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    int m_i4c;
    __m128 m_kVector;
    int m_iMode;
    char m_bFlag;

    FUN_00dd4bf0(InitArg* apArg);
};

// Constructs the object by initializing m_kFirst and m_kSecond, setting m_fCoefficientA, m_fB, m_fC, m_iMode, m_kVector, m_bFlag, and m_i04.
// @fnv 0x00dd4bf0
FUN_00dd4bf0::FUN_00dd4bf0(InitArg* apArg)
{
    m_kFirst.hkpMoppSplitter_hkpMoppSplitParams_hkpMoppSplitParams(apArg);
    m_kSecond.hkpMoppCostFunction_hkpMoppSplitCostParams_hkpMoppSplitCostParams(apArg);

    m_fCoefficientA = 0.5f;
    m_fB = 0.2f;
    m_fC = 1.0f;
    m_iMode = 5;
    m_kVector = _mm_setr_ps(0.2f, 0.2f, 0.05f, 0.0f);
    *(volatile char*)&m_bFlag = 1;
    *(volatile int*)&m_i04 = 0;
}

struct SourceData
{
    float x;
    float y;
    float z;
    unsigned int unk0C;
    __m128 unk10;
    unsigned int unk20;
    unsigned char unk24;
};
struct Destination
{
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
    float unk40;
    float unk44;
    float unk48;
    __m128 unk50;
    unsigned int unk60;
    unsigned char unk64;
    void CopyFromSourceData(unsigned int srcAddress);
};
// Copies x, y, z, a 16-byte vector, a 32-bit value and a byte from the SourceData at srcAddress into this object's unk40 to unk64 fields.
// @fnv 0x00dd4c70
void Destination::CopyFromSourceData(unsigned int srcAddress)
{
    const SourceData* src = (const SourceData*)srcAddress;
    unk40 = src->x;
    unk44 = src->y;
    unk48 = src->z;
    unk50 = src->unk10;
    unk60 = src->unk20;
    unk64 = src->unk24;
}
