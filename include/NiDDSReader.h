#pragma once

#include "NiImageReader.h"
#include "NiPixelFormat.h"
class NiBinaryStream;

class NiDDSReader : public NiImageReader
{
public:
    unsigned int m_uiImageHeight;
    unsigned int m_uiImageWidth;
    unsigned int m_uiMipMapLevels;
    bool m_bCubeMap;
    NiPixelFormat m_eFormat;

    void Lock();
    void Unlock();

    __declspec(noinline) bool IsValidBitDepth(unsigned int uiRedMask, unsigned int uiGreenMask,
                                            unsigned int uiBlueMask, unsigned int uiAlphaMask,
                                            unsigned int uiBitsPerPixel);
    NiPixelFormat NormalizePixelFormat(NiPixelFormat kFormat);
    bool ReadHeader_00a8c1e0(NiBinaryStream& kIst, unsigned int& uiWidth, unsigned int& uiHeight,
                      NiPixelFormat& kFormat, bool& bMipmap, unsigned int& uiFaces);
};
