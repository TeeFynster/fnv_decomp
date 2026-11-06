#pragma once

#include "hkaAnimation.h"
#include "hkaWaveletCompressedAnimationQuantizationFormat.h"

class hkaWaveletCompressedAnimation : public hkaAnimation
{
public:
    virtual hkUint32 getBlockKey(int block) const; // RTTI slot 16.
    virtual void vf16();

    hkInt32 m_iFrameCount;
    hkInt32 m_iDofCount;
    hkaWaveletCompressedAnimationQuantizationFormat m_eQuantizationFormat;
    hkUint32 m_uiFramesPerBlock;
    hkUint32 m_uiNumBlocks;
    hkUint32 m_uiOffsetDataOffset;
    hkUint32 m_uiScaleDataOffset;
    hkUint32 m_uiIndexDataOffset;
    hkUint32 m_uiNumIndices;
    hkUint32 m_uiNumDynamicDofs;
    hkUint32 m_uiNumDynamicTracks;
    hkArray<hkUint8> m_kCompressedData;
};
