#pragma once

#include "NiObject.h"
#include "NiPixelFormat.h"
#include "NiPalettePointer.h"
#include "NiPalette.h"
#include <stddef.h>

class NiPixelData : public NiObject
{
public:
    NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format,
                unsigned int mipmapLevels = 1, unsigned int faces = 1);
    NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat* format,
                unsigned int mipmapLevels, unsigned int faces);
    virtual ~NiPixelData();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);

    static unsigned int CalculateMipmapLevels(unsigned int width, unsigned int height);
    void AllocateData(unsigned int mipmapLevels, unsigned int faces, unsigned int totalBytes);
    NiPalette* GetPalette() const throw();
    void SetPalette(NiPalette* palette);
    void SetOwnsPixelData(bool value) { m_bOwnsPixelData = value; }
    unsigned int GetWidth(unsigned int level = 0) const throw()
    {
        return m_puiWidth[level];
    }
    unsigned int GetHeight(unsigned int level = 0) const throw()
    {
        return m_puiHeight[level];
    }
    const unsigned char* GetPixels(unsigned int level, unsigned int face) const throw()
    {
        return m_pucPixels + m_puiOffsetInBytes[level] + face * m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    unsigned char* GetPixels(unsigned int level, unsigned int face)
    {
        return m_pucPixels + m_puiOffsetInBytes[level] + face * m_puiOffsetInBytes[m_uiMipmapLevels];
    }
    unsigned char* GetPixels();
    unsigned int GetSizeInBytes(unsigned int level) const throw()
    {
        return m_puiOffsetInBytes[level + 1] - m_puiOffsetInBytes[level];
    }
    unsigned char* Pixels()
    {
        return m_pucPixels + m_puiOffsetInBytes[0];
    }
    void AddString();
    void NiPixelData_SetPalette(NiPalette* palette);
    NiPixelData* NiPixelData_00a7c030(const NiPixelData& source);
    unsigned char* NiPixelData_GetPixels(unsigned int level, unsigned int face);
    unsigned char* NiPixelData_GetPixels(int level, int face);
    void* NiPixelData_GetPixels(int level, int face, unsigned int size);
    void FUN_004f31b0();

    NiPixelFormat m_kPixelFormat;
    NiPalettePointer m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffsetInBytes;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiRevID;
    unsigned int m_uiFaces;
    bool m_bOwnsPixelData;
    unsigned char m_ucUnknownByte[3];
};
