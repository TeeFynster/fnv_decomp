#pragma once
#include "NiImageConverter.h"
#include "NiPixelFormat.h"
#include "NiTexture.h"
#include "NiTPointerList.h"
#include "NiTListItem.h"
#include "PixelDataExpander.h"

class NiFile;
class NiImageReader;
class NiPixelData;
class NiTexture;

class NiDevImageConverter : public NiImageConverter
{
public:
    class PixelFormatBitLayout
    {
    public:
        unsigned m_uiRedMask, m_uiGreenMask, m_uiBlueMask, m_uiAlphaMask;
        unsigned char m_ucRedDestinationShift, m_ucGreenDestinationShift,
            m_ucBlueDestinationShift, m_ucAlphaDestinationShift,
            m_ucRedSourceShift, m_ucGreenSourceShift,
            m_ucBlueSourceShift, m_ucAlphaSourceShift;

        PixelFormatBitLayout(const NiPixelFormat&);
    };

    NiDevImageConverter();
    virtual ~NiDevImageConverter();

    NiTexture* GenerateMipmaps(NiPixelData* pd, int a);
    void FUN_00a7b110();
    void ProcessEntries_00a7aff0();

    virtual bool CanConvertPixelFormat(const NiPixelFormat&, const NiPixelFormat&);
    virtual NiPixelData* ConvertImageData(const NiPixelData&, const NiPixelFormat&, NiPixelData*, bool);
    virtual bool CanReadImageFile(const char* pcFilename);
    virtual void vfn_1c();
    virtual bool IsSupportedDestinationFormat(const NiPixelFormat&);
    virtual bool IsSupportedSourceFormat(const NiPixelFormat&);
    virtual NiPixelData* ConvertBetweenPixelData(const NiPixelData*, NiPixelData*) throw();
    virtual NiPixelData* GenerateMipmapPyramidFromFiles(const char** ppcFileNames, unsigned uiNumLevels, NiPixelData* pkCurrentObject);
    virtual bool ConvertMipLevel(NiPixelData&, const NiPixelData&, int) throw();
    virtual NiPixelData* ConvertToBumpMap(const NiPixelData&, const NiPixelFormat&) throw();
    virtual void PushImageReaderNode(NiImageReader* pkReader);
    virtual void* SelectPlatformFormat(int ePlatform, void* kFmtPrefs, void* kSrcFmt, void* kDesiredFmt);
    virtual NiPixelData* ConvertForPlatform(int a1, int a2, const NiPixelData& kSrc, int a4);
    virtual void* GetImageReaderList();
    virtual const NiPixelFormat* FindClosestPixelFormatDX9(const NiTexture::TextureFormatPreferences& prefs,
        const NiPixelFormat& src, const NiPixelFormat& dest);
    virtual const NiPixelFormat* SelectFormat(const NiTexture::TextureFormatPreferences& kPrefs,
        const NiPixelFormat& kSrcFmt, const NiPixelFormat& kDestFmt);
    virtual const NiPixelFormat* FindClosestPixelFormatPS3(const NiTexture::TextureFormatPreferences& kPrefs,
        const NiPixelFormat& kSrcFmt, const NiPixelFormat& kDestFmt);

    bool ReadFileWithReader(const char*, int&, int&, int&, int&, int&);
    NiPixelData* ReadImageFile_00a77d10(const char* pcFilename, NiPixelData* pkOptDest, NiFile* pkIstr);
    bool QueryImageProperties(const char*, NiPixelFormat&, bool&, unsigned&, unsigned&, unsigned&) throw();
    NiPixelData* LoadPixelDataFromFile(const char*, NiPixelData*, int) throw();
    NiPixelData* GenerateMipmaps(const NiPixelData* pkSrc, NiPixelData* pkDst) throw();
    NiPixelData* GenerateMipmaps(NiPixelData* source, NiPixelData* destination);
    NiPixelData* ConvertPixelData(const NiPixelData& kSrc, const NiPixelFormat& kDstFmt,
        NiPixelData* pkDst, bool bWithMipmaps) throw();
    const NiPixelFormat* GetDestinationPixelFormat(int a1, int a2, const NiPixelFormat& kSrc, int a4);
    void* DestroyIfFlagged(unsigned int auiFlags);
    static NiImageReader* const& GetNext(NiTListItem<NiImageReader*>*& pkPos);

    void vfn_18();
    void vfn_2c();
    void vf14();
    void vf15();
    void vf16();
    void vf17();
    void vf18();
    void vf19();
    void vf20();

    unsigned char m_base[0x780 - sizeof(NiImageConverter)];
    PixelDataExpander m_kPixelDataExpander;
    unsigned char unk781[0x210 - sizeof(PixelDataExpander)];
    NiTPointerList<NiImageReader*> m_kImageReaderList;
};
