
// src/fallout_shared/tempeffects/bstempeffectsimpledecal_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/tempeffects/bstempeffectsimpledecal.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "../../../include/BSTempEffectSimpleDecal.h"
#include "../../../include/Mat3.h"
#include "../../../include/QueuedFile.h"


// Original PC source filename label passed to the preload memory context;
// contents and target are verified against the engine data section.
const char kBSTempEffectSimpleDecalFileLabel[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TempEffects\\BSTempEffectSimpleDecal.cpp";
// Source line of the preload context in the original PC file (0x11f).
enum
{
    kPreloadDecalDataSourceLine = 0x11f
};
NiPointer<QueuedFile> BSTempEffectSimpleDecal::ms_pPreloadDecalDataFile;

#include <math.h>
inline float NiSqrt(float fValue)
{
    return sqrt(fValue);
}

struct Pt
{
    float x, y, z;
    Pt()
    {}
    Pt(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    float FUN_00457990() const
    {
        return NiSqrt(x * x + y * y + z * z);
    }
// src: XBOX_PDB 0x004a0c10
    void Unitize_004a0c10()
    {
        float fScaleMultiplier = FUN_00457990();
        if (fScaleMultiplier > 1e-06)
        {
            float fRecip = 1.0f / fScaleMultiplier;
            x *= fRecip;
            y *= fRecip;
            z *= fRecip;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
    Pt FUN_004b3800(const Pt& kPt) const
    {
        return Pt(y * kPt.z - z * kPt.y, z * kPt.x - x * kPt.z, x * kPt.y - y * kPt.x);
    }
};

inline Mat3::Mat3()
{
}

inline void Mat3::SetRow(unsigned int uiRow, const Pt& kRow)
{
    reinterpret_cast<float (*)[3]>(&m00)[uiRow][0] = kRow.x;
    reinterpret_cast<float (*)[3]>(&m00)[uiRow][1] = kRow.y;
    reinterpret_cast<float (*)[3]>(&m00)[uiRow][2] = kRow.z;
}

inline float NiAbs(float fValue)
{
    return (float)fabs(fValue);
}

// @fnv 0x00c4b600
// src: XBOX_PDB 0x00c4b600
Mat3 __cdecl BSUtilities_GetRotationZToVector(Pt kWorldPosition)
{
    Pt kAt = kWorldPosition;
    kAt.Unitize_004a0c10();
    float fX = NiAbs(kAt.x);
    float fY2 = NiAbs(kAt.y);
    float fZ2 = NiAbs(kAt.z);
    Pt kRight2;
    if (fX <= fY2 && fX <= fZ2)
        kRight2 = Pt(0.0f, -kAt.z, kAt.y);
    else if (fY2 <= fX && fY2 <= fZ2)
        kRight2 = Pt(-kAt.z, 0.0f, kAt.x);
    else
        kRight2 = Pt(-kAt.y, kAt.x, 0.0f);
    kRight2.Unitize_004a0c10();
    Pt kUpVal;
    kUpVal = kRight2.FUN_004b3800(kAt);
    kUpVal.Unitize_004a0c10();
    kRight2 = kUpVal.FUN_004b3800(kAt);
    kRight2.Unitize_004a0c10();
    Mat3 kMatX;
    kMatX.SetRow(0, kRight2);
    kMatX.SetRow(1, kUpVal);
    kMatX.SetRow(2, kAt);
    return kMatX;
}
