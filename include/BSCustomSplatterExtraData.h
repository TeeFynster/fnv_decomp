#pragma once

#include "NiExtraData.h"

// Exe 0x004dea80: four DWORDs copied into the splatter extra data; no SIMD alignment or vector arithmetic.
struct SplatterWordsView
{
    int a, b, c, d;
};

struct OpacityFadeState;

class BSCustomSplatterExtraData : public NiExtraData
{
public:
    SplatterWordsView q;

    BSCustomSplatterExtraData(SplatterWordsView* source);
    virtual const NiRTTI* GetRTTI() const override;

    void ForwardCall_004deb10();
    void* DestroyIfFlagged(unsigned int flags);
    OpacityFadeState* GetOffsetC();
    void* GetList();

};
