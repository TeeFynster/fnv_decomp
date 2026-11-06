#pragma once

#include "hkaAnimation.h"
#include "hkaDeltaCompressedAnimationQuantizationFormat.h"

class hkaDeltaCompressedAnimation : public hkaAnimation
{
public:
    virtual hkUint32 getBlockKey(int block) const; // RTTI slot 16.
    virtual void vf16();

    hkInt32 m_iFrameCount;
    hkInt32 m_iDofCount;
    hkaDeltaCompressedAnimationQuantizationFormat m_eQuantizationFormat;
    hkUint32 m_uiNumDynamicDofs;
    hkUint32 m_uiNumDynamicTracks;
    hkUint32 m_uiFramesPerBlock;
    hkUint32 m_uiBlockByteSize;
    hkUint32 m_uiNumBlocks;
    hkUint32 m_uiBlockOffsetsOffset;
    hkUint32 m_uiOffsetDataOffset;
    hkUint32 m_uiScaleDataOffset;
    hkUint32 m_uiCompressedBlockSize;
    hkUint32 m_iLastBlockSize;
    hkArray<hkUint8> m_kCompressedData;
};
