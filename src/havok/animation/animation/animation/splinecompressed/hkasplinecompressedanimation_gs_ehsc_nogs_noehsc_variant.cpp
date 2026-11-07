
// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/splinecompressed/hkasplinecompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../include/hkaSplineCompressedAnimation.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkOstream.h"

__declspec(noinline) int __cdecl FindKeyInterval(int iLast, int iDegree, int iParam, const hkUint8* pKnots)
{
    hkUint8 ucParam = (hkUint8)iParam;
    if (ucParam >= pKnots[iLast + 1])
        return iLast;
    if (ucParam <= pKnots[0])
        return iDegree;
    int iLo = iDegree;
    int iHi = iLast + 1;
    int iMid = (iLo + iHi) / 2;
    while (ucParam < pKnots[iMid] || ucParam >= pKnots[iMid + 1])
    {
        if (ucParam < pKnots[iMid])
            iHi = iMid;
        else
            iLo = iMid;
        iMid = (iLo + iHi) / 2;
    }
    return iMid;
}

enum QuantizationType
{
    BITS8 = 0,
    BITS16 = 1
};
enum RotationQuantizationType
{
    POLAR32 = 0,
    THREECOMP40 = 1,
    THREECOMP48 = 2,
    THREECOMP24 = 3,
    STRAIGHT16 = 4,
    UNCOMPRESSED = 5
};

__declspec(noinline) hkBool StoreBoolFlag(QuantizationType type)
{
    return type == BITS8 || type == BITS16;
}

__declspec(noinline) hkBool IsValidMode(RotationQuantizationType type)
{
    return type == POLAR32 || type == THREECOMP40 || type == THREECOMP48 || type == THREECOMP24 || type == STRAIGHT16 ||
           type == UNCOMPRESSED;
}

// src: GUESS 0x00e32ea0 (confidence: low)
__declspec(noinline) hkReal Object_ComputeValue_00e32ea0(QuantizationType type)
{
    switch (type)
    {
    case BITS8:
        return 0.0078125f;
    case BITS16:
        return 3.0517578125e-05f;
    }
    return 0.0f;
}

double hkaSplineCompressedAnimation_TrackCompressionParams_approximateQuantizationAccuracy(RotationQuantizationType type);

struct TrackCompressionParams
{
    hkReal m_fRotationTolerance;
    hkReal m_fTranslationTolerance;
    hkReal m_fScaleTolerance;
    hkReal m_fFloatingTolerance;
    int m_iRotationDegree;
    int m_iTranslationDegree;
    hkUint8 m_eRotationQuantizationType;
    hkUint8 m_eTranslationQuantizationType;
    hkUint8 m_eScaleQuantizationType;
    hkUint8 m_eFloatQuantizationType;

    hkBool hkaSplineCompressedAnimation_TrackCompressionParams_isOk() const;
};

// @fnv 0x00e330b0
// src: HAVOK_LIB 0x00e330b0
hkBool TrackCompressionParams::hkaSplineCompressedAnimation_TrackCompressionParams_isOk() const
{
    hkBool ok = StoreBoolFlag((QuantizationType)m_eTranslationQuantizationType) &&
                    IsValidMode((RotationQuantizationType)m_eRotationQuantizationType) &&
                    StoreBoolFlag((QuantizationType)m_eScaleQuantizationType) &&
                    StoreBoolFlag((QuantizationType)m_eFloatQuantizationType);

    hkBool tolerancesOk = m_fTranslationTolerance >= 0.0f && m_fRotationTolerance >= 0.0f &&
                              m_fScaleTolerance >= 0.0f && m_fFloatingTolerance >= 0.0f;

    if (m_fTranslationTolerance < Object_ComputeValue_00e32ea0((QuantizationType)m_eTranslationQuantizationType))
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting translation quality.  If artifacts are visible, try increasing the number of translation quantization bits.";
        hkError::s_instance->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 79);
    }

    if (m_fScaleTolerance < Object_ComputeValue_00e32ea0((QuantizationType)m_eScaleQuantizationType))
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting scale quality.  If artifacts are visible, try increasing the number of scale quantization bits.";
        hkError::s_instance->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 84);
    }

    if (m_fFloatingTolerance < Object_ComputeValue_00e32ea0((QuantizationType)m_eFloatQuantizationType))
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting float quality.  If artifacts are visible, try increasing the number of float quantization bits.";
        hkError::s_instance->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 89);
    }

    RotationQuantizationType rq = (RotationQuantizationType)m_eRotationQuantizationType;
    if (m_fRotationTolerance < hkaSplineCompressedAnimation_TrackCompressionParams_approximateQuantizationAccuracy(rq) * 0.16260161995887756)
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr
            << "Quantization may be limiting rotation quality.  If artifacts are visible, try increasing the number of rotation quantization bits.";
        hkError::s_instance->message(1, 0xabba5a61, assertBuf,
                              ".\\Animation\\SplineCompressed\\hkaSplineCompressedAnimation.cpp", 100);
    }

    return ok && tolerancesOk;
}
