#pragma once

typedef unsigned char hkUint8;
typedef unsigned int hkUint32;

class hkaDeltaCompressedAnimationQuantizationFormat
{
public:
    hkUint8 m_ucFirstQuantizationParameter;
    hkUint8 m_ucSecondQuantizationParameter;
    char pad2[0x2];
    hkUint32 m_uiDynamicDofCount;
    hkUint32 m_uiOffsetIndexOffset;
    hkUint32 m_uiScaleIndexOffset;
    hkUint32 m_uiBitWidthIndexOffset;
};
