
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern double DAT_0101ff40;
extern double DAT_0104ed58;
extern double DAT_0108c160;
extern double DAT_010b7f30;
extern double DAT_010731a8;
extern double DAT_01012060;
extern double DAT_0101a6b0;
extern double DAT_010290b0;
extern float DAT_01200060;
extern float DAT_01200064;
extern float DAT_01200068;

extern "C" double __cdecl cos(double value);
extern "C" double __cdecl sin(double value);
extern "C" double __cdecl exp(double value);

// @fnv 0x00ba1480
// src: COMMUNITY 0x00ba1480
float __stdcall ImageSpaceEffectWaterFFT_Phillips(float x, float y)
{
    float a = (float)((double)DAT_01200064 * DAT_0101ff40 / DAT_0104ed58);
    float fScaleB = (float)((double)DAT_01200060 / DAT_0108c160);
    float fScaleC = (float)((double)DAT_01200068 * DAT_01200068 / DAT_010b7f30);
    float fScaleD = (float)((double)fScaleC / DAT_010731a8);
    float fRadiusSq = x * x + y * y;

    float fCosAngle = (float)cos((double)a);
    double dCosTerm = (double)(fCosAngle * x);
    float fSinAngle = (float)sin((double)a);
    x = (float)((double)(fSinAngle * y) + dCosTerm);
    if (x < DAT_01012060)
    {
        x = 0.0f;
    }

    float q = (float)(DAT_0101a6b0 / ((double)fRadiusSq * ((double)fScaleC * fScaleC)));
    q = (float)exp((double)q);

    double dNumerator = (double)q * ((double)x * x) * fScaleB;
    q = (float)(dNumerator / (((double)fRadiusSq * fRadiusSq) * fRadiusSq));

    float fExpTerm = -fRadiusSq * fScaleD * fScaleD;
    volatile float fExpResult = (float)exp((double)fExpTerm);
    fExpTerm = fExpResult;
    if (x < 0.0f)
    {
        q = (float)(q * DAT_010290b0);
    }
    return fExpTerm * q;
}

struct BB7290Entry
{
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fScale;
    float m_fCos;
    float m_fSin;
    int unk18;
    int unk1C;
};

class BB7290Owner
{
  public:
    void SetEntry(int iIndex, float fX, float fY, float fZ, float fAngleDifference, float fScale);

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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    BB7290Entry* m_pkEntryArray;
};

// Writes position, angle and scale into entry iIndex of the array, storing cos and sin of the angle.
// @fnv 0x00bb7290
void BB7290Owner::SetEntry(int iIndex, float fX, float fY, float fZ, float fAngleDifference, float fScale)
{
    m_pkEntryArray[iIndex].m_fVectorY = fX;
    m_pkEntryArray[iIndex].m_fVectorZ = fY;
    m_pkEntryArray[iIndex].m_fScalarPart = fZ;
    m_pkEntryArray[iIndex].m_fScale = fScale;
    m_pkEntryArray[iIndex].m_fCos = cos(fAngleDifference);
    m_pkEntryArray[iIndex].m_fSin = sin(fAngleDifference);
}

#include <xmmintrin.h>
#include <math.h>
// bhkCharacterListener - Havok character listener, constructor.
//
//
// pPos   : 16-byte position/direction, copied to this+0x10
//
// The class' vtable lives in the game image at 0x010c4488; it is referenced
// through a name of our own so that the checker binds the relocation from the
// original's own bytes.

extern int FNV_bhkCharacterListener_vftable;

struct BhkCharListener
{
    int* m_vtbl;          // +0x00  vtable pointer
    int m_04;             // +0x04
    int m_08;             // +0x08
    int m_0c;             // +0x0c
    __m128 m_pos;         // +0x10  position / direction
    float m_20;           // +0x20  cos(angle)
    int m_24;             // +0x24
    int m_28;             // +0x28
    int m_2c;             // +0x2c
    __m128 m_30;          // +0x30
    int m_40;             // +0x40
    int m_44;             // +0x44
    int m_48;             // +0x48
    int m_4c;             // +0x4c
    float m_50;           // +0x50
    float m_54;           // +0x54
    float m_58;           // +0x58
    float m_5c;           // +0x5c
    float m_60;           // +0x60  radius
    float m_64;           // +0x64  radius * cos(angle) / sin(angle)
    unsigned char m_68;   // +0x68
    unsigned char m_69;   // +0x69
    unsigned short m_6a;  // +0x6a
    int m_6c;             // +0x6c

    BhkCharListener* Init(const void* pPos, float fAngleDifference, float fRadius);
};

// Copies the input vector, computes cosine and sine-based values, and assigns constants and zeroes to fields.
// @fnv 0x00c6c7a0
BhkCharListener* BhkCharListener::Init(const void* pPos, float fAngleDifference, float fRadius)
{
    m_vtbl = &FNV_bhkCharacterListener_vftable;
    m_pos = *(const __m128*)pPos;

    m_20 = cosf(fAngleDifference);
    m_04 = 0;
    m_60 = fRadius;
    m_24 = 0x24;
    m_28 = 0;
    m_5c = 1.17549435e-38f;
    m_30 = _mm_setzero_ps();
    m_58 = 1.17549435e-38f;
    m_68 = 0;
    m_54 = 1.17549435e-38f;
    m_6c = 0;
    m_50 = 1.17549435e-38f;
    m_69 = 0;

    m_64 = (float)((double)fRadius / sinf(fAngleDifference) * cosf(fAngleDifference));
    return this;
}

struct SkyEntry
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
};

extern SkyEntry DAT_01269210[31];

inline float ClampMax(float afValue)
{
    return afValue < 3.1415927410125732 ? afValue : 3.1415927f;
}

// Fills the 31-entry SkyEntry table with cos/sin values for angles stepped 12 degrees from -PI to PI, adjusted by afA and afB.
// @fnv 0x00d10890
void UpdateSkyEntries(float afA, float afB)
{
    for (int i = 0; i < 31; i++)
    {
        float fAngleDifference = i * 0.20943951606750488 - 3.1415927410125732;
        if (fAngleDifference < 0.0f)
        {
            fAngleDifference = 3.1415927410125732 - fabs(fAngleDifference);
            float fDiff = fAngleDifference - afA;
            DAT_01269210[i].unk00 = 1.0f;
            DAT_01269210[i].unk04 = 0.0f;
            if (fDiff > afB)
            {
                DAT_01269210[i].unk08 = cos(afB);
            }
            else
            {
                DAT_01269210[i].unk08 = cos(fDiff > 0.0f ? fDiff : 0.0f);
            }
            DAT_01269210[i].unk0C = cos(fDiff > 0.0f ? fDiff : 0.0f);
            DAT_01269210[i].unk10 = cos(fAngleDifference);
            DAT_01269210[i].unk14 = sin(fAngleDifference);
        }
        else
        {
            DAT_01269210[i].unk00 = cos(fAngleDifference);
            DAT_01269210[i].unk04 = sin(fAngleDifference);
            DAT_01269210[i].unk08 = cos(ClampMax((float)(fAngleDifference + afA)));
            float fValue = fAngleDifference + afA;
            float fMin = 3.1415927410125732 - afB;
            if (fValue < fMin)
            {
                DAT_01269210[i].unk0C = cos(fMin);
            }
            else
            {
                DAT_01269210[i].unk0C = cos(fValue < 3.1415927410125732 ? fValue : 3.1415927f);
            }
            DAT_01269210[i].unk10 = -1.0f;
            DAT_01269210[i].unk14 = 0.0f;
        }
    }
}
