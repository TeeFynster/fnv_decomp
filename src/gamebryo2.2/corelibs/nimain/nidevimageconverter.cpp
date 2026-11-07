// gamebryo2.2/corelibs/nimain/nidevimageconverter.cpp: image conversion and reader registration (34 functions)

#include "../../../../include/BSShaderLightingProperty.h"
#include "../../../../include/NiBMPReader.h"
#include "../../../../include/NiD3DDefaultShader.h"
#include "../../../../include/NiDevImageConverter.h"
#include "../../../../include/NiFile.h"
#include "../../../../include/NiFilename.h"
#include "../../../../include/NiImageReader.h"
#include "../../../../include/NiPalette.h"
#include "../../../../include/NiPixelData.h"
#include "../../../../include/NiPixelFormat.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/PixelDataExpander.h"
#include "../../../../include/RecursiveSpinLock.h"

__forceinline void* operator new(unsigned int, void* memory) throw() { return memory; }

inline NiPalette* NiPixelData::GetPalette() const throw()
{
    return static_cast<NiPalette*>(m_spPalette.value);
}

inline unsigned NiPalette::GetEntries(PaletteColorEntry*& entries) const throw()
{
    entries = reinterpret_cast<PaletteColorEntry*>(unk14);
    return unk0C;
}

inline NiPalette::PaletteColorEntry* NiPalette::GetEntries(unsigned& count) const throw()
{
    PaletteColorEntry* entries = reinterpret_cast<PaletteColorEntry*>(unk14);
    count = unk0C;
    return entries;
}

#include "nidevimageconverter_decls.h"

// The shared palette header does not declare the game's palette assignment routine.
void CopyPaletteContents();
static __forceinline void AssignPalette(NiPalette* destination, const NiPalette& source)
{
    typedef void (__thiscall* AssignFn)(NiPalette*, const NiPalette&);
    ((AssignFn)&CopyPaletteContents)(destination, source);
}

// Typed dispatch for the image-reader virtual slots until the shared header names them.
static __forceinline void DestroyImageReader(NiImageReader* reader)
{
    typedef void* (__thiscall* DestroyFn)(NiImageReader*, unsigned int);
    ((DestroyFn)(*(void***)reader)[0])(reader, 1);
}

static __forceinline bool IsExtensionSupported(const NiImageReader* reader, const char* extension)
{
    typedef bool (__thiscall* SupportsFn)(const NiImageReader*, const char*);
    return ((SupportsFn)(*(void* const* const*)reader)[1])(reader, extension);
}

static __forceinline NiPixelData* ReadImageFile(NiImageReader* reader, NiFile& file, NiPixelData* destination)
{
    typedef NiPixelData* (__thiscall* ReadFn)(NiImageReader*, NiFile&, NiPixelData*);
    return ((ReadFn)(*(void***)reader)[2])(reader, file, destination);
}

static __forceinline bool ReadImageHeader(NiImageReader* reader, NiFile* file,
    int& width, int& height, int& format, int& mipmaps, int& faces)
{
    typedef bool (__thiscall* HeaderFn)(NiImageReader*, NiFile*, int&, int&, int&, int&, int&);
    return ((HeaderFn)(*(void***)reader)[3])(reader, file, width, height, format, mipmaps, faces);
}

// @fnv 0x00a7a4f0
bool NiDevImageConverter::ConvertMipLevel(NiPixelData& dst, const NiPixelData& src, int mip)
{
    const NiPixelFormat& sf = src.m_kPixelFormat;
    const NiPixelFormat& df = dst.m_kPixelFormat;
    if (src.GetWidth() != dst.GetWidth() || src.GetHeight() != dst.GetHeight())
        return false;
    unsigned faces = src.m_uiFaces;
    if (faces != dst.m_uiFaces)
        return false;
    unsigned uiFirstLevel, uiLastLevel;
    if (mip == -1)
    {
        uiLastLevel = dst.m_uiMipmapLevels;
        if (src.m_uiMipmapLevels < uiLastLevel)
            return false;
        uiFirstLevel = 0;
        --uiLastLevel;
    }
    else
    {
        if ((unsigned)mip >= src.m_uiMipmapLevels || (unsigned)mip >= dst.m_uiMipmapLevels)
            return false;
        uiFirstLevel = uiLastLevel = mip;
    }
    if (sf == df)
    {
        for (unsigned face = 0; face < faces; ++face)
            for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
        if (src.GetPalette())
        {
            if (!dst.GetPalette())
                dst.NiPixelData_SetPalette(new NiPalette(*src.GetPalette()));
            else
                AssignPalette(dst.GetPalette(), *src.GetPalette());
        }
        return true;
    }
    int dstFormat = df.m_eFormat;
    int srcFormat = sf.m_eFormat;
    unsigned dstBpp = df.m_ucBitsPerPixel;
    unsigned srcBpp = sf.m_ucBitsPerPixel;
    PixelFormatBitLayout dstBits(df), srcBits(sf);
    if (dstFormat == 4 || dstFormat == 5 || dstFormat == 6)
        return false;
    if (dstBpp == 24 &&
        (dstBits.m_uiGreenMask != 0xff00 || (dstBits.m_uiRedMask != 0xff && dstBits.m_uiRedMask != 0xff0000)))
        return false;
    PixelConvertFunc convert;
    if (sf == DAT_011aa180)
    {
        if (!src.GetPalette())
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 24)
                convert = Convert4BitPalettedTo24Bit;
            else if (dstBpp == 32)
                convert = ExpandPalettedImage;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa1c8))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.GetPalette())
                return false;
            if (!dst.GetPalette())
                dst.NiPixelData_SetPalette(new NiPalette(*src.GetPalette()));
            else
                AssignPalette(dst.GetPalette(), *src.GetPalette());
            NiPalette* palette = dst.GetPalette();
            NiPalette::PaletteColorEntry* entries;
            unsigned paletteCount = palette->GetEntries(entries);
            for (unsigned entry = 0; entry < paletteCount; ++entry)
                entries->a = 255;
            return true;
        }
    }
    else if (sf == DAT_011aa1c8)
    {
        if (!src.GetPalette())
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 24)
                convert = Convert4BitPalettedTo24Bit;
            else if (dstBpp == 32)
                convert = NiPalette_ExpandFourBitPaletteIndices;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa180))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.GetPalette())
                return false;
            unsigned paletteCount;
            dst.NiPixelData_SetPalette(new NiPalette(false, 16, src.GetPalette()->GetEntries(paletteCount)));
            return true;
        }
    }
    else if (sf == DAT_011aa210)
    {
        if (!src.GetPalette())
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 16)
                convert = ConvertPaletteTo16Bit;
            else if (dstBpp == 24)
                convert = Object_ProcessEntries_00a79e20;
            else if (dstBpp == 32)
                convert = NiDevImageConverter_ConvertPAL8To32;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa258))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.GetPalette())
                return false;
            if (!dst.GetPalette())
                dst.NiPixelData_SetPalette(new NiPalette(*src.GetPalette()));
            else
                AssignPalette(dst.GetPalette(), *src.GetPalette());
            NiPalette* palette = dst.GetPalette();
            NiPalette::PaletteColorEntry* entries;
            unsigned paletteCount = palette->GetEntries(entries);
            for (unsigned entry = 0; entry < paletteCount; ++entry)
                entries->a = 255;
            return true;
        }
    }
    else if (sf == DAT_011aa258)
    {
        if (!src.GetPalette())
            return false;
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp == 16)
                convert = NiDevImageConverter_ConvertPALA8To16;
            else if (dstBpp == 24)
                convert = Object_ProcessEntries_00a79e20;
            else if (dstBpp == 32)
                convert = ConvertPalettizedToFormat;
            else
                return false;
        }
        else
        {
            if (!(df == DAT_011aa210))
                return false;
            for (unsigned face = 0; face < faces; ++face)
                for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
                    fnv_zlib_memcpy(dst.GetPixels(level, face), src.GetPixels(level, face), src.GetSizeInBytes(level));
            if (!src.GetPalette())
                return false;
            unsigned paletteCount;
            dst.NiPixelData_SetPalette(new NiPalette(false, 256, src.GetPalette()->GetEntries(paletteCount)));
            return true;
        }
    }
    else if (sf == DAT_011aa2e8)
    {
        if (!(dstFormat == 0 || dstFormat == 1))
            return false;
        if (dstBpp == 16)
            convert = ConvertPixelsTo16Bit;
        else if (dstBpp == 24)
            convert = Object_ConvertBGRPixels;
        else if (dstBpp == 32)
            convert = ConvertRGBToFormat;
        else
            return false;
    }
    else if (sf == SOURCE_FORMAT_RGB)
    {
        if (!(dstFormat == 0 || dstFormat == 1))
            return false;
        if (dstBpp == 16)
            convert = ConvertRGBAToPacked;
        else if (dstBpp == 24)
            convert = NiDevImageConverter_ConvertRGBA32To24;
        else if (dstBpp == 32)
            convert = Runtime_PackRgbaPixelsByFormat;
        else
            return false;
    }
    else if (sf == DAT_011aa408)
    {
        if (!(dstFormat == 8 || dstFormat == 9))
            return false;
        if (dstBpp == 16)
            convert = NiDevImageConverter_ConvertBUMP16To16;
        else if (dstBpp == 32)
            convert = NiDevImageConverter_ConvertBUMP16To32;
        else
            return false;
    }
    else if (sf == DAT_011aa450)
    {
        if (!(dstFormat == 8 || dstFormat == 9))
            return false;
        if (dstBpp == 16)
            convert = ConvertRgbToPacked16;
        else if (dstBpp == 32)
            convert = NiDevImageConverter_ConvertBUMPLUMA32To32;
        else
            return false;
    }
    else if (sf == DAT_011aa330 && df == DAT_011aa3c0)
        convert = NiDevImageConverter_ConvertRGBA16ToBGRA16;
    else if (sf == DAT_011aa3c0 && df == DAT_011aa330)
        convert = NiPalette_NiDevImageConverter_ConvertRGBA16ToBGRA16_Thunk;
    else
    {
        if (srcFormat != 0 && srcFormat != 1)
            return false;
        if (df == SOURCE_FORMAT_RGB)
        {
            if (srcBpp == 16)
            {
                if (srcBits.m_uiAlphaMask)
                    convert = ConvertPixelsToBytes;
                else
                    convert = NiDevImageConverter_Convert16NoAlphaToRGBA32;
            }
            else if (srcBpp == 24)
                convert = ConvertRgbToRgba;
            else if (srcBpp == 32)
            {
                if (srcBits.m_uiAlphaMask)
                    convert = ConvertPixelFormat;
                else
                    convert = ConvertPackedPixelsToRGBA;
            }
            else
                return false;
        }
        else if (df == DAT_011aa2e8)
        {
            if (srcBpp == 16)
                convert = UnpackPixels;
            else if (srcBpp == 24)
                convert = NiDevImageConverter_ProcessEntries_00a7a1f0;
            else if (srcBpp == 32)
                convert = ConvertPixelsToRgb;
            else
                return false;
        }
        else
            return false;
    }
    for (unsigned face = 0; face < faces; ++face)
        for (unsigned level = uiFirstLevel; level <= uiLastLevel; ++level)
            convert(dst.m_puiWidth[level], dst.m_puiHeight[level], dst.GetSizeInBytes(level),
                    dst.GetPixels(level, face), src.GetPalette(), dstBits, src.GetPixels(level, face), srcBits);
    return true;
}

// Checks whether a source NiPixelFormat can be converted to a destination NiPixelFormat, validating endianness, compression, bit depth and format pairs.
// @fnv 0x00a77e40
bool NiDevImageConverter::CanConvertPixelFormat(const NiPixelFormat& sf, const NiPixelFormat& df)
{
    NiPixelFormat::Format dstFormat = df.GetFormat();
    unsigned dstBpp = df.GetBitsPerPixel();
    PixelFormatBitLayout bits(df);
    if (sf == df)
        return true;
    if (!sf.GetLittleEndian() || !df.GetLittleEndian() || df.IsCompressed())
        return false;
    if (dstBpp == 24 && (bits.m_uiGreenMask != 0xff00 || (bits.m_uiRedMask != 0xff && bits.m_uiRedMask != 0xff0000)))
        return false;
    if (sf == DAT_011aa180 || sf == DAT_011aa1c8)
    {
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else if (df != DAT_011aa180 && df != DAT_011aa1c8)
            return false;
    }
    else if (sf == DAT_011aa210 || sf == DAT_011aa258)
    {
        if (dstFormat == 0 || dstFormat == 1)
        {
            if (dstBpp != 16 && dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else if (df != DAT_011aa210 && df != DAT_011aa258)
            return false;
    }
    else if (sf == DAT_011aa2e8 || sf == SOURCE_FORMAT_RGB || sf.IsField4InRange())
    {
        if (dstFormat == 0 || dstFormat == 1 || dstFormat == 8 || dstFormat == 9)
        {
            if (dstBpp != 16 && dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else
            return false;
    }
    else if (sf == DAT_011aa408 || sf == DAT_011aa450)
    {
        if (dstFormat == 8 || dstFormat == 9)
        {
            if (dstBpp != 16 && dstBpp != 24 && dstBpp != 32)
                return false;
        }
        else
            return false;
    }
    else if (sf == DAT_011aa330 || sf == DAT_011aa3c0)
    {
        if (dstBpp != 16)
            return false;
    }
    else
        return false;
    return true;
}

// @fnv 0x00a78050
bool NiDevImageConverter::IsSupportedSourceFormat(const NiPixelFormat& format)
{
    if (format == DAT_011aa180 || format == DAT_011aa210 || format == DAT_011aa2e8)
        return true;
    return false;
}

// @fnv 0x00a78010
bool NiDevImageConverter::IsSupportedDestinationFormat(const NiPixelFormat& format)
{
    if (format == DAT_011aa1c8 || format == DAT_011aa258 || format == SOURCE_FORMAT_RGB)
        return true;
    return false;
}

// Dispatches on ePlatform: returns gNiPoint3StartupSrc or kDesiredFmt for case 0, calls virtual slots 18-20 for platforms 6/4/5, else returns 0.
// @fnv 0x00a78630
void* NiDevImageConverter::SelectPlatformFormat(int ePlatform, void* kFmtPrefs, void* kSrcFmt, void* kDesiredFmt)
{
    typedef void*(__thiscall * VFn)(void*, void*, void*, void*);

    switch (ePlatform)
    {
    case 0:
        if ((*(int*)((char*)kDesiredFmt + 4) == 2 || *(int*)((char*)kDesiredFmt + 4) == 3 ||
             *(unsigned char*)((char*)kDesiredFmt + 1) == 16) &&
            *(int*)kFmtPrefs == 4)
        {
            return &gNiPoint3StartupSrc;
        }
        return kDesiredFmt;
    case 6:
        return ((VFn)(*(void***)this)[18])(this, kFmtPrefs, kSrcFmt, kDesiredFmt);
    case 4:
        return ((VFn)(*(void***)this)[19])(this, kFmtPrefs, kSrcFmt, kDesiredFmt);
    case 5:
        return ((VFn)(*(void***)this)[20])(this, kFmtPrefs, kSrcFmt, kDesiredFmt);
    default:
        return 0;
    }
}

template <class T> struct PoolAllocatorBase
{
    struct LinkedListEntry
    {
        LinkedListEntry* next;
        LinkedListEntry* prev;
        void* data;
    };
    static LinkedListEntry* ms_pFreeList;
};

extern int DAT_0109d9c4;
extern RecursiveSpinLock g_011c5f80;
extern unsigned int DAT_011c5f84;
void __fastcall FUN_00a76680(void* pThis);

// @fnv 0x00a7aff0
// src: GUESS 0x00a7aff0 (confidence: low)
void NiDevImageConverter::ProcessEntries_00a7aff0()
{
    *(void**)this = &DAT_0109d9c4;
    while (m_kImageReaderList.m_kItemCount.m_uiCount)
    {
        NiTListItem<NiImageReader*>* node = m_kImageReaderList.m_pkHead;
        m_kImageReaderList.m_pkHead = node->m_pkNext;
        if (m_kImageReaderList.m_pkHead)
        {
            m_kImageReaderList.m_pkHead->m_pkPrev = 0;
        }
        else
        {
            m_kImageReaderList.m_pkTail = 0;
        }
        NiImageReader* entry = (NiImageReader*)node->m_element;
        node->m_element = 0;
        g_011c5f80.Lock(0);
        node->m_pkPrev = 0;
        node->m_pkNext = reinterpret_cast<NiTListItem<NiImageReader*>*>(PoolAllocatorBase<unsigned int>::ms_pFreeList);
        PoolAllocatorBase<unsigned int>::ms_pFreeList = reinterpret_cast<PoolAllocatorBase<unsigned int>::LinkedListEntry*>(node);
        if (--DAT_011c5f84 == 0)
        {
            g_011c5f80.m_uiOwningThreadID = 0;
        }
        --m_kImageReaderList.m_kItemCount.m_uiCount;
        if (entry)
        {
            DestroyImageReader(entry);
        }
    }
    ((BSShaderLightingProperty*)&m_kImageReaderList.m_pkHead)->ClearLights();
    typedef void(__fastcall * InitCapsFn)(void*);
    ((InitCapsFn)&NiD3DDefaultShader::SetShaderName)(&m_kPixelDataExpander);
    FUN_00a76680(this);
}

// @fnv 0x00a77940
int __fastcall IsPalettizedFormat(const NiPixelFormat* format, void*)
{
    if (format->m_eFormat == 2 || format->m_eFormat == 3)
        return 1;
    return 0;
}

// @fnv 0x00a7b0a0
// src: XBOX_PDB 0x00a7b0a0
void* NiDevImageConverter::GetImageReaderList()
{
    return &m_kImageReaderList;
}

// @fnv 0x00a79e20
// src: GUESS 0x00a79e20 (confidence: low)
void __cdecl Object_ProcessEntries_00a79e20(unsigned int width, unsigned int height, unsigned int, unsigned char* dst, void* tableSrc,
                          void* codeSrc, const unsigned char* src)
{
    unsigned char* table = *(unsigned char**)((unsigned char*)tableSrc + 0x14);
    unsigned int* codePtr = (unsigned int*)codeSrc;
    if (codePtr[1] != 0xff00)
        return;
    unsigned int code = codePtr[0];
    if (code == 0xff)
    {
        if (height <= 0)
            return;
        unsigned int uiRows = height;
        do
        {
            if (width <= 0)
                continue;
            unsigned int uiCols = width;
            do
            {
                *dst = table[*src * 4];
                ++dst;
                *dst = table[*src * 4 + 1];
                ++dst;
                *dst = table[*src * 4 + 2];
                ++dst;
                ++src;
            } while (--uiCols != 0);
        } while (--uiRows != 0);
    }
    else if (code == 0x00ff0000)
    {
        if (height <= 0)
            return;
        unsigned int uiRows = height;
        do
        {
            if (width <= 0)
                continue;
            unsigned int uiCols = width;
            do
            {
                *dst = table[*src * 4 + 2];
                ++dst;
                *dst = table[*src * 4 + 1];
                ++dst;
                *dst = table[*src * 4];
                ++dst;
                ++src;
            } while (--uiCols != 0);
        } while (--uiRows != 0);
    }
}

// Scans four int entries at offset 0x14 for value and returns the byte at offset 0x1c + i*12 for the matching entry, else 0.
// @fnv 0x00a77980
unsigned char NiPixelFormat::GetPixelBitData(int value)
{
    unsigned int i = 0;
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x14);
    while (i < 4)
    {
        if (*p == value)
        {
            return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1c + i * 12);
        }
        ++i;
        p += 3;
    }
    return 0;
}

struct NodePoolView
{
    void* AddHead(void);
};

// Allocates a node from the pool at self+0x998, stores pkReader at offset 8, and links the node into the list at self+0x990/0x994.
// @fnv 0x00a7b0b0
void __thiscall NiDevImageConverter::PushImageReaderNode(NiImageReader* pkReader)
{
    char* self = (char*)this;
    NodePoolView* pool = (NodePoolView*)(self + 0x998);
    void* node = pool->AddHead();
    *(NiImageReader**)((char*)node + 8) = pkReader;
    *(void**)((char*)node + 4) = 0;
    void* head = *(void**)(self + 0x990);
    *(void**)node = head;
    head = *(void**)(self + 0x990);
    if (head)
    {
        *(void**)((char*)head + 4) = node;
        ++*(unsigned int*)(self + 0x998);
        *(void**)(self + 0x990) = node;
    }
    else
    {
        ++*(unsigned int*)(self + 0x998);
        *(void**)(self + 0x994) = node;
        *(void**)(self + 0x990) = node;
    }
}

void __cdecl _delete(void*, unsigned int);
// Calls FUN_00a7aff0, then deletes this with size 0xA00 when bit 0 of a is set, and returns this.
// @fnv 0x00a7b260
void* NiDevImageConverter::DestroyIfFlagged(unsigned int auiFlags)
{
    ProcessEntries_00a7aff0();
    if (auiFlags & 1)
        _delete(this, 0xA00);
    return this;
}

struct Format_a79ef0
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShl[4];
    unsigned char m_aucShr[4];
};

// Builds a 256-entry table mapping palette RGBA through the format's shift/mask fields, then writes one converted pixel per source byte into pDst.
// @fnv 0x00a79ef0
void __cdecl ConvertPalettizedToFormat(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused,
                                       unsigned int* pDst, NiPalette* pkPalette, Format_a79ef0* pkFormat,
                                       const unsigned char* pSrc)
{
    unsigned int auiTable[256];
    NiPalette::PaletteColorEntry* pkEntries = reinterpret_cast<NiPalette::PaletteColorEntry*>(pkPalette->unk14);
    for (unsigned int i = 0; i < 256; i++)
    {
        auiTable[i] =
            (((unsigned int)pkEntries[i].r >> pkFormat->m_aucShr[0]) << pkFormat->m_aucShl[0]) &
                pkFormat->m_auiMask[0] |
            (((unsigned int)pkEntries[i].g >> pkFormat->m_aucShr[1]) << pkFormat->m_aucShl[1]) &
                pkFormat->m_auiMask[1] |
            (((unsigned int)pkEntries[i].b >> pkFormat->m_aucShr[2]) << pkFormat->m_aucShl[2]) &
                pkFormat->m_auiMask[2] |
            (((unsigned int)pkEntries[i].a >> pkFormat->m_aucShr[3]) << pkFormat->m_aucShl[3]) & pkFormat->m_auiMask[3];
    }
    unsigned int* puiDst = pDst;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
        {
            *puiDst++ = auiTable[*pSrc++];
        }
    }
}

void* _NiMalloc(unsigned int);
void _NiFree(void*);
extern int DAT_00ff0000;

struct FUN_00a78f70_Fmt
{
    unsigned int mask0;
    unsigned int mask1;
};

// @fnv 0x00a78f70
void Convert4BitPalettedTo24Bit(unsigned int width, unsigned int height, unsigned int unused, unsigned char* dst,
                                NiPalette* pal, FUN_00a78f70_Fmt* fmt, unsigned char* src)
{
    NiPalette::PaletteColorEntry* entries = reinterpret_cast<NiPalette::PaletteColorEntry*>(pal->unk14);
    if (fmt->mask1 != 0xff00)
        return;
    unsigned char* p = (unsigned char*)_NiMalloc(width * height);
    unsigned char* pTempBuffer = p;
    for (unsigned int i = 0; i < width / 2 * height; i++)
    {
        *p++ = src[i] >> 4;
        *p++ = src[i] & 0xf;
    }
    unsigned char* pRead = pTempBuffer;
    if (fmt->mask0 == 0xff)
    {
        for (unsigned int y = 0; y < height; y++)
        {
            for (unsigned int x = 0; x < width; x++)
            {
                *dst++ = entries[*pRead].r;
                *dst++ = entries[*pRead].g;
                *dst++ = entries[*pRead].b;
                pRead++;
            }
        }
    }
    else if (fmt->mask0 == (unsigned int)&DAT_00ff0000)
    {
        for (unsigned int y = 0; y < height; y++)
        {
            for (unsigned int x = 0; x < width; x++)
            {
                *dst++ = entries[*pRead].b;
                *dst++ = entries[*pRead].g;
                *dst++ = entries[*pRead].r;
                pRead++;
            }
        }
    }
    _NiFree(pTempBuffer);
}

static inline unsigned char FindComponentBits(const NiPixelFormat* kFmt, int kind)
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (kFmt->m_akComponents[i].kind == kind)
        {
            return kFmt->m_akComponents[i].bits;
        }
    }
    return 0;
}

// Builds per-component masks, bit counts and 8-minus-bits shifts from a NiPixelFormat for all four components.
// @fnv 0x00a779b0
NiDevImageConverter::PixelFormatBitLayout::PixelFormatBitLayout(const NiPixelFormat& format)
{
    const NiPixelFormat* kFmt = &format;
    const NiPixelFormat* maskView = kFmt;

    m_uiRedMask = maskView->GetMask(0);
    m_ucRedDestinationShift = maskView->GetPixelBitData((NiPixelFormat::Component)0);
    m_ucRedSourceShift = 8 - FindComponentBits(kFmt, 0);

    m_uiGreenMask = maskView->GetMask(1);
    m_ucGreenDestinationShift = maskView->GetPixelBitData((NiPixelFormat::Component)1);
    m_ucGreenSourceShift = 8 - FindComponentBits(kFmt, 1);

    m_uiBlueMask = maskView->GetMask(2);
    m_ucBlueDestinationShift = maskView->GetPixelBitData((NiPixelFormat::Component)2);
    m_ucBlueSourceShift = 8 - FindComponentBits(kFmt, 2);

    m_uiAlphaMask = maskView->GetMask(3);
    m_ucAlphaDestinationShift = maskView->GetPixelBitData((NiPixelFormat::Component)3);
    m_ucAlphaSourceShift = 8 - FindComponentBits(kFmt, 3);
}

extern const NiPixelFormat g_kFmtDXT1_a78a50;
extern const NiPixelFormat g_kFmtDXT3_a78a50;
extern const NiPixelFormat g_kFmtDXT5_a78a50;
extern const NiPixelFormat g_kFmtRGBA128_a78a50;
extern const NiPixelFormat g_kFmtRGBA64_a78a50;
extern const NiPixelFormat g_kFmtRGBA16_a78a50;
extern const NiPixelFormat g_kFmtRGB16_a78a50;
extern const NiPixelFormat g_kFmtDefault_a78a50;

static inline unsigned char FindAlphaBits_a78a50(const NiPixelFormat& kFmt)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        if (kFmt.m_akComponents[i].kind == 3)
            return kFmt.m_akComponents[i].bits;
    }
    return 0;
}

static inline bool IsPal_a78a50(const NiPixelFormat& kFmt)
{
    return kFmt.m_eFormat == NiPixelFormat::FORMAT_PAL || kFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA;
}

// @fnv 0x00a78a50
// src: XBOX_PDB 0x00a78a50
const NiPixelFormat* NiDevImageConverter::FindClosestPixelFormatPS3(const NiTexture::TextureFormatPreferences& kPrefs, const NiPixelFormat& kSrcFmt,
                                            const NiPixelFormat& kDestFmt)
{
    bool bAlpha;
    if (IsPal_a78a50(kSrcFmt))
        bAlpha = (kSrcFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA);
    else
        bAlpha = FindAlphaBits_a78a50(kSrcFmt) > 0;
    if (kSrcFmt.IsCompressed())
        bAlpha = true;

    int eLayout = kPrefs.m_ePreferredPixelLayout;
    if (eLayout == 14)
        return &g_kFmtRGBA128_a78a50;
    if (eLayout == 13)
        return &g_kFmtRGBA64_a78a50;
    if (eLayout == 12)
        return &g_kFmtRGBA64_a78a50;
    if (eLayout == 1)
    {
        return bAlpha ? &g_kFmtRGBA16_a78a50 : &g_kFmtRGB16_a78a50;
    }
    if (eLayout == 0 || eLayout == 5)
    {
        if (kPrefs.m_eAlphaFormat == 2)
            return &g_kFmtDXT5_a78a50;
        return &g_kFmtDXT1_a78a50;
    }
    if (eLayout == 3)
    {
        int eDestFormat = kDestFmt.m_eFormat;
        if (eDestFormat == NiPixelFormat::FORMAT_DXT1)
            return &g_kFmtDXT1_a78a50;
        if (eDestFormat == NiPixelFormat::FORMAT_DXT3)
            return &g_kFmtDXT3_a78a50;
        if (eDestFormat == NiPixelFormat::FORMAT_DXT5)
            return &g_kFmtDXT5_a78a50;
        if (kPrefs.m_eAlphaFormat == 2)
            return &g_kFmtDXT5_a78a50;
        return &g_kFmtDXT1_a78a50;
    }
    if (eLayout == 6)
    {
        const NiPixelFormat& kDest = kDestFmt;
        if (kDest.IsField4InRange() || const_cast<NiPixelFormat&>(kDest).GetPalettized())
        {
            int eDestFormat = kDestFmt.m_eFormat;
            if (eDestFormat == NiPixelFormat::FORMAT_DXT1)
                return &g_kFmtDXT1_a78a50;
            if (eDestFormat == NiPixelFormat::FORMAT_DXT3)
                return &g_kFmtDXT3_a78a50;
            if (eDestFormat == NiPixelFormat::FORMAT_DXT5)
                return &g_kFmtDXT5_a78a50;
            if (kPrefs.m_eAlphaFormat == 2)
                return &g_kFmtDXT5_a78a50;
            return &g_kFmtDXT1_a78a50;
        }
        if (kDestFmt.m_ucBitsPerPixel == 16)
        {
            bool bDestAlpha;
            if (const_cast<NiPixelFormat&>(kDest).GetPalettized())
                bDestAlpha = (kDestFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA);
            else
                bDestAlpha = const_cast<NiPixelFormat&>(kDest).GetPixelBitData(3) > 0;
            if (kDest.IsField4InRange())
                bDestAlpha = true;

            int iAlphaMode = kPrefs.m_eAlphaFormat;
            bool bUseAlpha = (iAlphaMode == 1 || iAlphaMode == 2 || (iAlphaMode != 0 && bDestAlpha));
            if (bUseAlpha)
                return &g_kFmtRGBA16_a78a50;
            return &g_kFmtRGB16_a78a50;
        }
    }
    return &g_kFmtDefault_a78a50;
}

struct Format_a798c0
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShl[4];
    unsigned char m_aucShr[4];
};

// Builds a 256-entry lookup table from the palette using the format masks/shifts, then converts the source indices into destination pixels.
// @fnv 0x00a798c0
// src: GAMEBRYO_LIB 0x00a798c0
void __cdecl NiDevImageConverter_ConvertPAL8To32(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned int* pDst,
                          NiPalette* pkPalette, Format_a798c0* pkFormat, const unsigned char* pSrc)
{
    unsigned int auiTable[256];
    NiPalette::PaletteColorEntry* pkEntries = reinterpret_cast<NiPalette::PaletteColorEntry*>(pkPalette->unk14);
    for (unsigned int i = 0; i < 256; i++)
        auiTable[i] = (((0xffu >> pkFormat->m_aucShr[3]) << pkFormat->m_aucShl[3]) & pkFormat->m_auiMask[3]) |
                      (((pkEntries[i].b >> pkFormat->m_aucShr[2]) << pkFormat->m_aucShl[2]) & pkFormat->m_auiMask[2]) |
                      (((pkEntries[i].g >> pkFormat->m_aucShr[1]) << pkFormat->m_aucShl[1]) & pkFormat->m_auiMask[1]) |
                      (((pkEntries[i].r >> pkFormat->m_aucShr[0]) << pkFormat->m_aucShl[0]) & pkFormat->m_auiMask[0]);
    unsigned int* pDstPixel = pDst;
    for (unsigned int y = 0; y < uiHeight; y++)
        for (unsigned int x = 0; x < uiWidth; x++)
            *pDstPixel++ = auiTable[*pSrc++];
}

void strcpy_s(char* dst, unsigned int size, const char* src);
void _fnv_StandardizeFilePath(char* path);

inline NiImageReader* const& NiDevImageConverter::GetNext(NiTListItem<NiImageReader*>*& pkPos)
{
    NiImageReader* const& element = pkPos->m_element;
    pkPos = pkPos->m_pkNext;
    return element;
}

// @fnv 0x00a77d10
// src: XBOX_PDB 0x00a77d10
NiPixelData* NiDevImageConverter::ReadImageFile_00a77d10(const char* pcFilename, NiPixelData* pkOptDest, NiFile* pkIstr)
{
    NiTListItem<NiImageReader*>* pkPos = m_kImageReaderList.m_pkHead;
    char acStandardFilename[260];
    strcpy_s(acStandardFilename, 260, pcFilename);
    _fnv_StandardizeFilePath(acStandardFilename);
    NiFilename kFileName(acStandardFilename);

    while (pkPos)
    {
        NiImageReader* pkReader = GetNext(pkPos);
        if (IsExtensionSupported(pkReader, kFileName.GetExt()))
        {
            NiFile* pkFile = pkIstr ? pkIstr : NiFile::GetFile(acStandardFilename, NiFile::READ_ONLY, 0x8000);
            if (!pkFile || !(*pkFile))
            {
                delete pkFile;
                return 0;
            }
            NiPixelData* pkData = ReadImageFile(pkReader, *pkFile, pkOptDest);
            if (pkData)
            {
                delete pkFile;
                return pkData;
            }
            if (!pkIstr)
                delete pkFile;
        }
    }
    delete pkIstr;
    return 0;
}

extern const NiPixelFormat DAT_011aad98;
extern const NiPixelFormat DAT_011aa768;
extern const NiPixelFormat DAT_011aa6d8;
extern const NiPixelFormat DAT_011aa600;
extern const NiPixelFormat DAT_011aa648;
extern const NiPixelFormat DAT_011aa690;
extern const NiPixelFormat DAT_011aa570;
extern const NiPixelFormat DAT_011aa5b8;
extern const NiPixelFormat DAT_011aab58;
extern const NiPixelFormat DAT_011aaac8;
extern const NiPixelFormat DAT_011aa960;
extern const NiPixelFormat DAT_011aa9f0;
extern const NiPixelFormat DAT_011aa8d0;
extern const NiPixelFormat DAT_011aa498;
extern const NiPixelFormat DAT_011aa4e0;
extern const NiPixelFormat DAT_011aa528;

// @fnv 0x00a786e0
// src: GAMEBRYO_LIB 0x00a786e0
const NiPixelFormat* NiDevImageConverter::FindClosestPixelFormatDX9(const NiTexture::TextureFormatPreferences& prefs, const NiPixelFormat& src,
                                            const NiPixelFormat& dest)
{
    if (prefs.m_ePreferredPixelLayout == 7)
    {
        if (prefs.m_eAlphaFormat == 0)
            return &DAT_011aad98;
        return &DAT_011aa768;
    }
    if (prefs.m_ePreferredPixelLayout == 8)
        return &DAT_011aa6d8;
    if (prefs.m_ePreferredPixelLayout == 9)
        return &DAT_011aa600;
    if (prefs.m_ePreferredPixelLayout == 10)
        return &DAT_011aa648;
    if (prefs.m_ePreferredPixelLayout == 11)
        return &DAT_011aa690;
    if (prefs.m_ePreferredPixelLayout == 14)
        return &DAT_011aa570;
    if (prefs.m_ePreferredPixelLayout == 13)
        return &DAT_011aa5b8;
    if (prefs.m_ePreferredPixelLayout == 12)
        return &DAT_011aa5b8;
    if (prefs.m_ePreferredPixelLayout == 2)
    {
        if (prefs.m_eAlphaFormat == 0)
            return &DAT_011aab58;
        return &DAT_011aaac8;
    }
    if (prefs.m_ePreferredPixelLayout == 1)
    {
        if (prefs.m_eAlphaFormat == 1)
            return &DAT_011aa960;
        if (prefs.m_eAlphaFormat == 2)
            return &DAT_011aa9f0;
        return &DAT_011aa8d0;
    }
    if (prefs.m_ePreferredPixelLayout == 0 || prefs.m_ePreferredPixelLayout == 5)
    {
        if (prefs.m_eAlphaFormat == 2)
            return &DAT_011aa528;
        return &DAT_011aa498;
    }
    if (prefs.m_ePreferredPixelLayout == 3)
    {
        if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT1)
            return &DAT_011aa498;
        if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT3)
            return &DAT_011aa4e0;
        if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT5)
            return &DAT_011aa528;
        if (prefs.m_eAlphaFormat == 2)
            return &DAT_011aa528;
        return &DAT_011aa498;
    }
    if (prefs.m_ePreferredPixelLayout == 4)
        return &DAT_011aa450;
    if (prefs.m_ePreferredPixelLayout == 6)
    {
        if (dest.IsField4InRange() || const_cast<NiPixelFormat&>(dest).GetPalettized())
        {
            if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT1)
                return &DAT_011aa498;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT3)
                return &DAT_011aa4e0;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_DXT5)
                return &DAT_011aa528;
            if (prefs.m_eAlphaFormat == 2)
                return &DAT_011aa528;
            return &DAT_011aa498;
        }
        if (dest.m_ucBitsPerPixel == 16)
        {
            bool alpha;
            if (const_cast<NiPixelFormat&>(dest).GetPalettized())
                alpha = dest.m_eFormat == NiPixelFormat::FORMAT_PALALPHA;
            else
                alpha = const_cast<NiPixelFormat&>(dest).GetPixelBitData(3) > 0;
            if (dest.IsField4InRange())
                alpha = true;
            if (prefs.m_eAlphaFormat == 1)
                return &DAT_011aa960;
            if (prefs.m_eAlphaFormat == 2)
                return &DAT_011aa9f0;
            if (prefs.m_eAlphaFormat == 0)
                return &DAT_011aa8d0;
            if (alpha)
                return &DAT_011aa9f0;
            return &DAT_011aa8d0;
        }
        if (dest.m_ucBitsPerPixel == 32)
        {
            if (prefs.m_eAlphaFormat == 0)
                return &DAT_011aab58;
            if (prefs.m_eAlphaFormat == 1 || prefs.m_eAlphaFormat == 2)
                return &DAT_011aaac8;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_RGB)
                return &DAT_011aab58;
            if (dest.m_eFormat == NiPixelFormat::FORMAT_RGBA)
                return &DAT_011aaac8;
        }
    }
    return &dest;
}

extern const NiPixelFormat DAT_011aa498;
extern const NiPixelFormat DAT_011aa4e0;
extern const NiPixelFormat DAT_011aa528;
extern const NiPixelFormat DAT_011aa570;
extern const NiPixelFormat DAT_011aa5b8;
extern const NiPixelFormat DAT_011aa8d0;
extern const NiPixelFormat DAT_011aa9f0;
extern const NiPixelFormat DAT_011aaac8;

static inline unsigned char GetAlphaBits_a78910(const NiPixelFormat& kFmt)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        if (kFmt.m_akComponents[i].kind == 3)
            return kFmt.m_akComponents[i].bits;
    }
    return 0;
}

static __forceinline const NiPixelFormat* PickCompressed_a78910(const NiPixelFormat& kFmt, bool bAlpha)
{
    NiPixelFormat::Format eFormat = kFmt.m_eFormat;
    if (eFormat == NiPixelFormat::FORMAT_DXT1)
        return &DAT_011aa498;
    if (eFormat == NiPixelFormat::FORMAT_DXT3)
        return &DAT_011aa4e0;
    if (eFormat == NiPixelFormat::FORMAT_DXT5)
        return &DAT_011aa528;
    return bAlpha ? &DAT_011aa528 : &DAT_011aa498;
}

static inline bool IsPalettized_a78910(const NiPixelFormat& kFmt)
{
    return kFmt.m_eFormat == NiPixelFormat::FORMAT_PAL || kFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA;
}

// Chooses a target NiPixelFormat from the preferred layout and source alpha/compression, falling back to compressed or default formats.
// @fnv 0x00a78910
const NiPixelFormat* NiDevImageConverter::SelectFormat(const NiTexture::TextureFormatPreferences& kPrefs, const NiPixelFormat& kSrcFmt,
                                                         const NiPixelFormat& kDestFmt)
{
    bool bAlpha;
    if (IsPalettized_a78910(kSrcFmt))
        bAlpha = (kSrcFmt.m_eFormat == NiPixelFormat::FORMAT_PALALPHA);
    else
        bAlpha = GetAlphaBits_a78910(kSrcFmt) > 0;
    if (kSrcFmt.IsCompressed())
        bAlpha = true;

    int eLayout = kPrefs.m_ePreferredPixelLayout;
    if (eLayout == 14)
        return &DAT_011aa570;
    if (eLayout == 13)
        return &DAT_011aa5b8;
    if (eLayout == 2)
        return &DAT_011aaac8;
    if (eLayout == 1)
        return bAlpha ? &DAT_011aa9f0 : &DAT_011aa8d0;
    if (eLayout == 0 || eLayout == 5)
        return bAlpha ? &DAT_011aa528 : &DAT_011aa498;
    if (eLayout == 3)
        return PickCompressed_a78910(kDestFmt, bAlpha);
    if (eLayout == 4)
        return &DAT_011aa450;
    if (eLayout == 6)
    {
        if (const_cast<NiPixelFormat&>(kDestFmt).GetPalettized() || kDestFmt.IsField4InRange())
            return PickCompressed_a78910(kDestFmt, bAlpha);
        unsigned char ucBpp = kDestFmt.m_ucBitsPerPixel;
        if (ucBpp == 16)
            return bAlpha ? &DAT_011aa9f0 : &DAT_011aa8d0;
        if (ucBpp == 64)
            return &DAT_011aa5b8;
        if (ucBpp == 128)
            return &DAT_011aa570;
    }
    return &DAT_011aaac8;
}

void* __cdecl _NiMalloc_00aa1070(unsigned);
void __cdecl _NiFree_00aa10f0(void*);
// Expands 4-bit paletted source pixels into a 32-bit color buffer using the palette and bit-shift masks, then frees the temporary buffer.
// @fnv 0x00a790a0
void __cdecl ExpandPalettedImage(unsigned width, unsigned height, unsigned unused, unsigned char* dst,
                                 const NiPalette* palette, const NiDevImageConverter::PixelFormatBitLayout& bits,
                                 const unsigned char* src, const NiDevImageConverter::PixelFormatBitLayout& srcBits)
{
    const NiPalette::PaletteColorEntry* entries = reinterpret_cast<NiPalette::PaletteColorEntry*>(palette->unk14);
    unsigned char* expanded = (unsigned char*)_NiMalloc_00aa1070(width * height);
    unsigned count = (width >> 1) * height;
    unsigned char* saved = expanded;
    for (unsigned i = 0; i < count; ++i)
    {
        *expanded++ = src[i] >> 4;
        *expanded++ = src[i] & 15;
    }
    const unsigned char* read = saved;
    unsigned colors[16];
    for (unsigned i = 0; i < 16; ++i)
    {
        colors[i] =
            (((unsigned)entries[i].r >> bits.m_ucRedSourceShift) << bits.m_ucRedDestinationShift & bits.m_uiRedMask) |
            (((unsigned)entries[i].g >> bits.m_ucGreenSourceShift) << bits.m_ucGreenDestinationShift &
             bits.m_uiGreenMask) |
            (((unsigned)entries[i].b >> bits.m_ucBlueSourceShift) << bits.m_ucBlueDestinationShift &
             bits.m_uiBlueMask) |
            (((255u >> bits.m_ucAlphaSourceShift) << bits.m_ucAlphaDestinationShift) & bits.m_uiAlphaMask);
    }
    unsigned* output = (unsigned*)dst;
    for (unsigned y = 0; y < height; ++y)
        for (unsigned x = 0; x < width; ++x)
            *output++ = colors[*read++];
    _NiFree_00aa10f0(saved);
}

void* _NiMalloc_00aa1070(unsigned int uiSize);
void NiFree(void* pvMem);

struct Format_a79310
{
    unsigned int m_auiMask[4];
    unsigned char m_aucShl[4];
    unsigned char m_aucShr[4];
};

// Expands 4-bit packed palette indices into 32-bit colors using the palette and format masks, writes them to pDst, and frees the temporary buffer.
// @fnv 0x00a79310
// src: GUESS 0x00a79310 (confidence: high)
void __cdecl NiPalette_ExpandFourBitPaletteIndices(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiUnused, unsigned int* pDst,
                          NiPalette* pkPalette, Format_a79310* pkFormat, const unsigned char* pSrc)
{
    NiPalette::PaletteColorEntry* pkEntries = reinterpret_cast<NiPalette::PaletteColorEntry*>(pkPalette->unk14);
    unsigned char* pucOut = (unsigned char*)_NiMalloc_00aa1070(uiWidth * uiHeight);
    unsigned int uiBytes = (uiWidth >> 1) * uiHeight;
    unsigned char* pucIndices = pucOut;
    for (unsigned int i = 0; i < uiBytes; i++)
    {
        *pucOut++ = pSrc[i] >> 4;
        *pucOut++ = pSrc[i] & 0xf;
    }

    unsigned char* pucRead = pucIndices;
    unsigned int auiColors[16];
    for (unsigned int i = 0; i < 16; i++)
    {
        auiColors[i] = (((pkEntries[i].r >> pkFormat->m_aucShr[0]) << pkFormat->m_aucShl[0]) & pkFormat->m_auiMask[0]) |
                       (((pkEntries[i].g >> pkFormat->m_aucShr[1]) << pkFormat->m_aucShl[1]) & pkFormat->m_auiMask[1]) |
                       (((pkEntries[i].b >> pkFormat->m_aucShr[2]) << pkFormat->m_aucShl[2]) & pkFormat->m_auiMask[2]) |
                       (((pkEntries[i].a >> pkFormat->m_aucShr[3]) << pkFormat->m_aucShl[3]) & pkFormat->m_auiMask[3]);
    }

    unsigned int* puiDst = pDst;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
            *puiDst++ = auiColors[*pucRead++];
    }
    NiFree(pucIndices);
}

// Builds a 256-entry palette table from the palette using the format's channel shifts/masks, then converts each source index to a 16-bit output pixel.
// @fnv 0x00a79ae0
// src: GAMEBRYO_LIB 0x00a79ae0
void __cdecl NiDevImageConverter_ConvertPALA8To16(unsigned width, unsigned height, unsigned unused, unsigned char* dst,
                          const NiPalette* pPalette, const NiDevImageConverter::PixelFormatBitLayout& kFormat,
                          const unsigned char* src, const NiDevImageConverter::PixelFormatBitLayout& unusedFmt)
{
    unsigned short paletteTable[256];
    const NiPalette::PaletteColorEntry* paletteEntries = reinterpret_cast<NiPalette::PaletteColorEntry*>(pPalette->unk14);
    unsigned alphaLeftShift = kFormat.m_ucAlphaDestinationShift;
    signed char alphaRightShift = kFormat.m_ucAlphaSourceShift;
    unsigned short blueMask;
    unsigned short alphaMask = (unsigned short)kFormat.m_uiAlphaMask;
    unsigned char blueRightShift = kFormat.m_ucBlueSourceShift;
    unsigned blueLeftShift = kFormat.m_ucBlueDestinationShift;
    blueMask = (unsigned short)kFormat.m_uiBlueMask;
    char greenRightShift = kFormat.m_ucGreenSourceShift;
    unsigned greenLeftShift;
    greenLeftShift = kFormat.m_ucGreenDestinationShift;
    unsigned short greenMask = (unsigned short)kFormat.m_uiGreenMask;
    unsigned redLeftShift;
    unsigned char redRightShift = kFormat.m_ucRedSourceShift;
    unsigned uiIndex = 0;
    redLeftShift = kFormat.m_ucRedDestinationShift;
    unsigned short redMask = (unsigned short)kFormat.m_uiRedMask;
    for (; uiIndex < 256; ++uiIndex)
    {
        paletteTable[uiIndex] =
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].r >> redRightShift)) << redLeftShift & redMask) |
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].g >> greenRightShift)) << greenLeftShift &
             greenMask) |
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].b >> blueRightShift)) << blueLeftShift &
             blueMask) |
            ((unsigned short)((unsigned char)(paletteEntries[uiIndex].a >> alphaRightShift)) << alphaLeftShift &
             alphaMask);
    }
    unsigned short* output = (unsigned short*)dst;
    for (unsigned row = 0; row < height; ++row)
        for (unsigned col = 0; col < width; ++col)
            *output++ = paletteTable[*src++];
}

struct ReaderAllocator
{
    void* Allocate(unsigned int);
};
extern ReaderAllocator DAT_011f6238;
struct ReaderStorage
{
    static void* operator new(unsigned int size) throw()
    {
        return DAT_011f6238.Allocate(size);
    }
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
};
struct FUN_00a8d750 : ReaderStorage
{
    __declspec(nothrow) FUN_00a8d750() throw();
};
struct FUN_00a8c190 : ReaderStorage
{
    __declspec(nothrow) FUN_00a8c190() throw();
};
template <class TAlloc, class T> __forceinline void NiTPointerListBase<TAlloc, T>::AddHead(const T& reader)
{
    NiTListItem<T>* node = static_cast<NiTListItem<T>*>(reinterpret_cast<NodePoolView*>(&m_kItemCount)->AddHead());
    node->m_element = reader;
    node->m_pkPrev = 0;
    node->m_pkNext = m_pkHead;
    if (m_pkHead)
        m_pkHead->m_pkPrev = node;
    else
        m_pkTail = node;
    ++m_kItemCount.m_uiCount;
    m_pkHead = node;
}

void __fastcall InitializeConverterBase(void*) throw();
void __fastcall InitializeConverterCodec(void*) throw();
// The shared base has no declaration for the game's converter initializer. Keep
// this constructor-ABI entry as a typed free function so it can initialize the
// original base and codec without invoking synthesized base construction.
// Initializes the reader list and registers the three built-in image readers.
// @fnv 0x00a7b110
NiDevImageConverter* __fastcall InitializeNiDevImageConverter(NiDevImageConverter* self)
{
    InitializeConverterBase(self);
    *(void**)self = &DAT_0109d9c4;
    InitializeConverterCodec(&self->m_kPixelDataExpander);
    self->m_kImageReaderList.m_kItemCount.m_uiCount = 0;
    self->m_kImageReaderList.m_pkHead = 0;
    self->m_kImageReaderList.m_pkTail = 0;
    self->m_kImageReaderList.AddHead(new (DAT_011f6238.Allocate(sizeof(ReaderStorage))) NiBMPReader);
    self->m_kImageReaderList.AddHead(reinterpret_cast<NiImageReader*>(new FUN_00a8d750));
    self->m_kImageReaderList.AddHead(reinterpret_cast<NiImageReader*>(new FUN_00a8c190));
    return self;
}

extern "C" void __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);

typedef void* NiTListIterator;

template <class TAlloc, class T> inline T& NiTPointerListBase<TAlloc, T>::GetNext(void*& kPos)
{
    T* pElement = &((NiTListItem<T>*)kPos)->m_element;
    kPos = ((NiTListItem<T>*)kPos)->m_pkNext;
    return *pElement;
}

// Copies the path, normalizes it, then tries each registered image reader's extension match and opens the file to test readability.
// @fnv 0x00a77ae0
// src: XBOX_PDB 0x00a77ae0
bool NiDevImageConverter::CanReadImageFile(const char* pcFilename)
{
    char acStandardFilename[0x104];
    NiTListIterator kIter = m_kImageReaderList.m_pkHead;
    FUN_00ec65a6(acStandardFilename, 0x104, pcFilename);
    _fnv_StandardizeFilePath(acStandardFilename);
    NiFilename kFileName(acStandardFilename);
    while (kIter)
    {
        NiImageReader* pkReader = m_kImageReaderList.GetNext(kIter);
        if (IsExtensionSupported(pkReader, kFileName.GetExt()))
        {
            NiFile* pkIstr = NiFile::GetFile(acStandardFilename, NiFile::READ_ONLY, 0x8000);
            if (!pkIstr)
                return false;
            if (*pkIstr)
            {
                delete pkIstr;
                return true;
            }
            delete pkIstr;
            return false;
        }
    }
    return false;
}

namespace fnv_00a77bd0 {
int __cdecl _strcpy_s(char*, unsigned int, const char*);
void __cdecl _fnv_StandardizeFilePath(char*);
struct ReaderNode
{
    ReaderNode* next;
    ReaderNode* prev;
    ImageConverterPointer<NiImageReader> data;
};
inline NiImageReader*& NextReader(ReaderNode*& position)
{
    NiImageReader*& result = position->data.m_pObject;
    position = position->next;
    return result;
}

}  // namespace fnv_00a77bd0

// @fnv 0x00a77bd0
bool NiDevImageConverter::ReadFileWithReader(const char* apPath, int& a2, int& a3, int& a4, int& a5, int& a6)
{
    using namespace fnv_00a77bd0;
    fnv_00a77bd0::ReaderNode* node = reinterpret_cast<fnv_00a77bd0::ReaderNode*>(m_kImageReaderList.m_pkHead);
    char acFilePath[260];
    _strcpy_s(acFilePath, 260, apPath);
    fnv_00a77bd0::_fnv_StandardizeFilePath(acFilePath);
    NiFilename fileNameParts(acFilePath);
    while (node)
    {
        NiImageReader* reader = NextReader(node);
        if (IsExtensionSupported(reader, fileNameParts.GetExt()))
        {
            NiFile* file = NiFile::GetFile(acFilePath, NiFile::READ_ONLY, 0x8000);
            if (file && *file)
            {
                if (ReadImageHeader(reader, file, a4, a5, a2, a3, a6))
                {
                    delete file;
                    return true;
                }
                delete file;
            }
            else
            {
                delete file;
                return false;
            }
        }
    }
    return false;
}

inline unsigned PixelDataMipmapLevels(const NiPixelData& k)
{
    return k.m_uiMipmapLevels;
}
inline unsigned PixelDataFaces(const NiPixelData& k)
{
    return k.m_uiFaces;
}
// Converts kSrc to the destination pixel format, returning a new NiPixelData or a pointer to kSrc if no conversion is needed.
// @fnv 0x00a78570
// src: XBOX_PDB 0x00a78570
NiPixelData* NiDevImageConverter::ConvertForPlatform(int a1, int a2, const NiPixelData& kSrc, int a4)
{
    typedef const NiPixelFormat* (__thiscall* DestinationFn)(NiDevImageConverter*, int, int, const NiPixelFormat&, int);
    const NiPixelFormat* pkFmt = ((DestinationFn)(*(void***)this)[15])(this, a1, a2, kSrc.m_kPixelFormat, a4);
    if (pkFmt == &kSrc.m_kPixelFormat)
        return (NiPixelData*)&kSrc;
    if (!pkFmt)
        return 0;
    if (*pkFmt == kSrc.m_kPixelFormat)
        return (NiPixelData*)&kSrc;
    if (!CanConvertPixelFormat(kSrc.m_kPixelFormat, *pkFmt))
        return 0;
    NiPixelData* pkDest =
        ::new (NiPixelData::operator new(sizeof(NiPixelData))) NiPixelData(kSrc.GetWidth(), kSrc.GetHeight(), *pkFmt, PixelDataMipmapLevels(kSrc), PixelDataFaces(kSrc));
    return ConvertMipLevel(*pkDest, kSrc, -1) ? pkDest : 0;
}

// Allocates destination pixel data and fills it using differences between neighboring source bytes.
// @fnv 0x00a78be0
// src: XBOX_PDB 0x00a78be0
NiPixelData* __stdcall NiDevImageConverter_GenerateBumpMap(const NiPixelData& src, const NiPixelFormat& fmt)
{
    unsigned width = src.m_puiWidth[0], height = src.m_puiHeight[0];
    unsigned levels = src.m_uiMipmapLevels;
    NiPixelData* dst;
    unsigned dstStride, srcStride;
    unsigned level, x, y;
    unsigned char* out;
    const unsigned char *in, *below, *right;
    if (src.m_kPixelFormat == SOURCE_FORMAT_RGB)
    {
        dst = ::new (NiPixelData::operator new(sizeof(NiPixelData))) NiPixelData(width, height, DAT_011aa450, levels, 1);
        for (level = 0; level < levels; ++level)
        {
            out = dst->m_pucPixels + dst->m_puiOffsetInBytes[level];
            width = src.m_puiWidth[level];
            height = src.m_puiHeight[level];
            in = src.m_pucPixels + src.m_puiOffsetInBytes[level];
            for (y = 0; y < height; ++y)
                for (x = width; x > 0; --x)
                {
                    out[2] = in[3];
                    out[3] = in[0];
                    in += 4;
                    out += 4;
                }
        }
        dstStride = 4;
        srcStride = 4;
    }
    else if (src.m_kPixelFormat == DAT_011aa2e8 && fmt == DAT_011aa450)
    {
        dst = ::new (NiPixelData::operator new(sizeof(NiPixelData))) NiPixelData(width, height, DAT_011aa450, levels, 1);
        for (level = 0; level < levels; ++level)
        {
            out = dst->m_pucPixels + dst->m_puiOffsetInBytes[level];
            width = src.m_puiWidth[level];
            height = src.m_puiHeight[level];
            in = src.m_pucPixels + src.m_puiOffsetInBytes[level];
            for (y = 0; y < height; ++y)
                for (x = width; x > 0; --x)
                {
                    out[2] = 255;
                    out[3] = in[0];
                    in += 3;
                    out += 4;
                }
        }
        dstStride = 4;
        srcStride = 3;
    }
    else if (src.m_kPixelFormat == DAT_011aa2e8)
    {
        dst = ::new (NiPixelData::operator new(sizeof(NiPixelData))) NiPixelData(width, height, DAT_011aa408, levels, 1);
        dstStride = 2;
        srcStride = 3;
    }
    else
        return 0;
    for (level = 0; level < levels; ++level)
    {
        out = dst->m_pucPixels + dst->m_puiOffsetInBytes[level];
        width = src.m_puiWidth[level];
        const unsigned char* in = src.m_pucPixels + src.m_puiOffsetInBytes[level];
        right = in + srcStride;
        below = in + width * srcStride;
        width--;
        height = src.m_puiHeight[level] - 1;
        for (y = 0; y < height; ++y)
        {
            for (x = 0; x < width; ++x)
            {
                unsigned short value = in[0];
                unsigned short delta = (unsigned short)(below[0] - value);
                out[0] = (unsigned char)(right[0] - value);
                out[1] = (unsigned char)delta;
                out += dstStride;
                in += srcStride;
                right += srcStride;
                below += srcStride;
            }
            if (x)
                out[0] = (unsigned char)(in[0] - *(in - srcStride));
            else
                out[0] = 0;
            out[1] = (unsigned char)(below[0] - in[0]);
            in += srcStride;
            out += dstStride;
            right += srcStride;
            below += srcStride;
        }
        below = in - (width + 1) * srcStride;
        for (x = 0; x < width; ++x)
        {
            unsigned short value = in[0];
            unsigned short delta = (unsigned short)(value - below[0]);
            out[0] = (unsigned char)(right[0] - value);
            out[1] = (unsigned char)delta;
            out += dstStride;
            below += srcStride;
            in += srcStride;
            right += srcStride;
        }
        if (x)
        {
            out[0] = (unsigned char)(in[0] - *(in - srcStride));
            if (y)
                out[1] = (unsigned char)(in[0] - below[0]);
            else
                out[1] = 0;
        }
        else
        {
            out[0] = 0;
            if (y)
                out[1] = (unsigned char)(in[0] - below[0]);
            else
                out[1] = 0;
        }
    }
    return dst;
}

struct PixelDataRef
{
    NiPixelData* m_pObject;
    PixelDataRef() throw() : m_pObject(0)
    {}
    PixelDataRef& operator=(NiPixelData*) throw();
    void Release() throw();
};

// Queries the first file's properties, allocates a NiPixelData buffer, and copies each mipmap level from the source files into it.
// @fnv 0x00a7ae60
// src: XBOX_PDB 0x00a7ae60
NiPixelData* NiDevImageConverter::GenerateMipmapPyramidFromFiles(const char** ppcFileNames, unsigned uiNumLevels, NiPixelData* pkCurrentObject)
{
    if (!ppcFileNames[0])
        return 0;

    NiPixelFormat kFormat;
    bool bMipmap;
    unsigned uiWidth, uiHeight, uiFaces;
    typedef bool (__thiscall* QueryFn)(NiDevImageConverter*, const char*, NiPixelFormat&, bool&, unsigned&, unsigned&, unsigned&);
    typedef NiPixelData* (__thiscall* LoadFn)(NiDevImageConverter*, const char*, NiPixelData*, int);
    if (!((QueryFn)(*(void***)this)[2])(this, ppcFileNames[0], kFormat, bMipmap, uiWidth, uiHeight, uiFaces) || uiFaces != 1)
        return 0;

    NiPixelData* pkDest = ::new (NiPixelData::operator new(sizeof(NiPixelData))) NiPixelData(uiWidth, uiHeight, kFormat, uiNumLevels, 1);
    if (!pkDest)
        return 0;

    for (unsigned i = 0; i < uiNumLevels; i++)
    {
        if (!ppcFileNames[i])
        {
            delete pkDest;
            return 0;
        }

        PixelDataRef spSrc;
        if (i == 0 && pkCurrentObject)
            spSrc = pkCurrentObject;
        else
            spSrc = ((LoadFn)(*(void***)this)[3])(this, ppcFileNames[i], 0, 0);

        NiPixelData* pkSrc = *(NiPixelData* volatile*)&spSrc.m_pObject;
        if (!pkSrc)
        {
            delete pkDest;
            return 0;
        }

        unsigned uiSize = pkDest->GetSizeInBytes(i);
        if (uiSize != pkSrc->GetSizeInBytes(0))
        {
            delete pkDest;
            spSrc.Release();
            return 0;
        }

        fnv_zlib_memcpy(pkDest->GetPixels(i, 0), pkSrc->GetPixels(0, 0), uiSize);

        if (i == 0 && kFormat.GetPalettized())
            pkDest->SetPalette(pkSrc->GetPalette());

        spSrc.Release();
    }

    return pkDest;
}

extern const NiPixelFormat DAT_011aa2a0;

// Generates RGB or RGBA mip levels by averaging pixels from the preceding level.
// @fnv 0x00a78090
NiPixelData* NiDevImageConverter::GenerateMipmaps(NiPixelData* source, NiPixelData* destination)
{
    const NiPixelFormat& sourceFormat = source->m_kPixelFormat;
    NiPixelFormat format;

    if (IsSupportedSourceFormat(sourceFormat))
        format = DAT_011aa2e8;
    else if (IsSupportedDestinationFormat(sourceFormat))
        format = DAT_011aa2a0;
    else
        return 0;

    NiPixelData* output = destination;

    if (!output || !output->m_kPixelFormat.operator==(format) || output->m_uiMipmapLevels <= 1 || output->m_uiFaces != source->m_uiFaces)
    {
        void* storage = NiPixelData::operator new(sizeof(NiPixelData));
        if (storage)
            output = ::new (storage) NiPixelData(source->GetWidth(), source->GetHeight(), format, 0, PixelDataFaces(*source));
        else
            output = 0;
    }

    unsigned int levels = output->m_uiMipmapLevels;

    if (source != output && !ConvertMipLevel(*output, *source, 0))
        return 0;

    for (unsigned int face = 0; face < source->m_uiFaces; ++face)
    {

        if (format.operator==(DAT_011aa2e8))
        {

            for (unsigned int level = 1; level < levels; ++level)
            {

                unsigned char* src = output->GetPixels(level - 1, face);

                unsigned char* dst = output->GetPixels(level, face);

                unsigned int width = output->m_puiWidth[level];

                unsigned int height = output->m_puiHeight[level];

                unsigned int priorWidth = output->m_puiWidth[level - 1];

                unsigned int row = priorWidth * 3;

                if (priorWidth == 1)
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        *dst++ = (unsigned int)(src[0] + src[3]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[5]) >> 1;

                        src += 6;
                    }
                }

                else if (output->m_puiHeight[level - 1] == 1)
                {
                    for (unsigned int x = 0; x < width; ++x)
                    {
                        *dst++ = (unsigned int)(src[0] + src[3]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[5]) >> 1;

                        src += 6;
                    }
                }

                else
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        for (unsigned int x = 0; x < width; ++x)
                        {
                            *dst++ = (unsigned int)(src[0] + src[3] + src[row + 0] + src[row + 3]) >> 2;

                            *dst++ = (unsigned int)(src[1] + src[4] + src[row + 1] + src[row + 4]) >> 2;

                            *dst++ = (unsigned int)(src[2] + src[5] + src[row + 2] + src[row + 5]) >> 2;

                            src += 6;
                        }
                        src += row;
                    }
                }
            }
        }

        else if (format.operator==(DAT_011aa2a0))
        {

            for (unsigned int level = 1; level < levels; ++level)
            {
                // This mip reads its predecessor: 1 <= level < levels.
                __assume(((level <= levels - 1) & (level >= 1)) != 0);

                unsigned char* src = output->GetPixels(level - 1, face);

                unsigned char* dst = output->GetPixels(level, face);

                unsigned int width = output->m_puiWidth[level];

                unsigned int height = output->m_puiHeight[level];

                unsigned int priorWidth = output->m_puiWidth[level - 1];

                unsigned int row = priorWidth * 4;

                if (priorWidth == 1)
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        *dst++ = (unsigned int)(src[0] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[5]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[6]) >> 1;

                        *dst++ = (unsigned int)(src[3] + src[7]) >> 1;

                        src += 8;
                    }
                }

                else if (output->m_puiHeight[level - 1] == 1)
                {
                    for (unsigned int x = 0; x < width; ++x)
                    {
                        *dst++ = (unsigned int)(src[0] + src[4]) >> 1;

                        *dst++ = (unsigned int)(src[1] + src[5]) >> 1;

                        *dst++ = (unsigned int)(src[2] + src[6]) >> 1;

                        *dst++ = (unsigned int)(src[3] + src[7]) >> 1;

                        src += 8;
                    }
                }

                else
                {
                    for (unsigned int y = 0; y < height; ++y)
                    {
                        for (unsigned int x = 0; x < width; ++x)
                        {
                            *dst++ = (unsigned int)(src[0] + src[4] + src[row + 0] + src[row + 4]) >> 2;

                            *dst++ = (unsigned int)(src[1] + src[5] + src[row + 1] + src[row + 5]) >> 2;

                            *dst++ = (unsigned int)(src[2] + src[6] + src[row + 2] + src[row + 6]) >> 2;

                            *dst++ = (unsigned int)(src[3] + src[7] + src[row + 3] + src[row + 7]) >> 2;

                            src += 8;
                        }
                        src += row;
                    }
                }
            }
        }
    }
    return output;
}

// Converts an 8-bit paletted image to 16-bit using the given NiPalette and pixel format bit layouts.
// @fnv 0x00a795d0
void __cdecl ConvertPaletteTo16Bit(unsigned int uiWidth, unsigned int uiHeight, unsigned int uiDestSize,
                                   unsigned char* pucDest, const NiPalette* pkPalette,
                                   const NiDevImageConverter::PixelFormatBitLayout& kDestBits,
                                   const unsigned char* pucSrc,
                                   const NiDevImageConverter::PixelFormatBitLayout& kSrcBits)
{
    const NiPalette::PaletteColorEntry* pkEntries = reinterpret_cast<NiPalette::PaletteColorEntry*>(pkPalette->unk14);
    unsigned short ausPalette[256];
    unsigned int i;

    for (i = 0; i < 256; i++)
    {
        ausPalette[i] =
            (unsigned short)((((pkEntries[i].r >> kDestBits.m_ucRedSourceShift) << kDestBits.m_ucRedDestinationShift) &
                              kDestBits.m_uiRedMask) |
                             (((pkEntries[i].g >> kDestBits.m_ucGreenSourceShift)
                               << kDestBits.m_ucGreenDestinationShift) &
                              kDestBits.m_uiGreenMask) |
                             (((pkEntries[i].b >> kDestBits.m_ucBlueSourceShift)
                               << kDestBits.m_ucBlueDestinationShift) &
                              kDestBits.m_uiBlueMask) |
                             (((0xffu >> kDestBits.m_ucAlphaSourceShift) << kDestBits.m_ucAlphaDestinationShift) &
                              kDestBits.m_uiAlphaMask));
    }

    unsigned short* pusDest = (unsigned short*)pucDest;
    for (unsigned int y = 0; y < uiHeight; y++)
    {
        for (unsigned int x = 0; x < uiWidth; x++)
            *pusDest++ = ausPalette[*pucSrc++];
    }
}

extern int DAT_00ff0000;

// Swaps BGR to RGB pixel order when the source has a 0xFF00 green mask and 0xFF red mask, or copies raw bytes when the red mask is 0xFF.
// @fnv 0x00a7a160
// src: GUESS 0x00a7a160 (confidence: medium)
void __cdecl Object_ConvertBGRPixels(unsigned int uiWidth, unsigned int uiHeight, unsigned int, unsigned char* pDst,
                          const NiPalette*, const NiDevImageConverter::PixelFormatBitLayout& kSrcBits,
                          const unsigned char* pSrc, const NiDevImageConverter::PixelFormatBitLayout&)
{
    if (kSrcBits.m_uiGreenMask == 0xFF00u)
    {
        if (kSrcBits.m_uiRedMask == (unsigned int)&DAT_00ff0000)
        {
            if (uiHeight <= 0)
                return;
            unsigned int y = uiHeight;
            const unsigned char* src = pSrc;
            unsigned char* dst = pDst;
            do
            {
                if (uiWidth > 0)
                {
                    unsigned int x = uiWidth;
                    do
                    {
                        *dst++ = src[2];
                        *dst++ = src[1];
                        *dst++ = src[0];
                        src += 3;
                    } while (--x);
                }
            } while (--y);
        }
        else if (kSrcBits.m_uiRedMask == 0xFFu)
        {
            fnv_zlib_memcpy(pDst, pSrc, uiWidth * uiHeight * 3);
        }
    }
}

struct Format_a7a1f0
{
    int unk00;
    int unk04;
};

void __cdecl FUN_00ec44d0(void* destination, const void* source, unsigned int size);

// @fnv 0x00a7a1f0
// src: GUESS 0x00a7a1f0 (confidence: low)
void __cdecl NiDevImageConverter_ProcessEntries_00a7a1f0(unsigned int width, unsigned int height, unsigned int unused, unsigned char* destination,
                          unsigned int unused2, unsigned int FlushUsageData, unsigned char* source,
                          Format_a7a1f0* format)
{
    if (format->unk04 != 0xff00)
        return;

    if (format->unk00 == reinterpret_cast<unsigned int>(&DAT_00ff0000))
    {
        for (unsigned int row = 0; row < height; ++row)
        {
            for (unsigned int column = 0; column < width; ++column)
            {
                *destination++ = source[2];
                *destination++ = source[1];
                *destination++ = source[0];
                source += 3;
            }
        }
    }
    else if (format->unk00 == 0xff)
    {
        FUN_00ec44d0(destination, source, width * height * 3);
    }
}

// NiRefObject exposes a nonvirtual DeleteThis declaration; this unit uses virtual slot 1.
static __forceinline void DecRefCount(NiRefObject* object) throw()
{
    if (InterlockedDecrement((volatile long*)&object->m_uiRefCount) == 0)
    {
        typedef void (__thiscall* DeleteFn)(NiRefObject*);
        ((DeleteFn)(*(void***)object)[1])(object);
    }
}

template <class T> ImageConverterPointer<T>& ImageConverterPointer<T>::operator=(T* pObject) throw()
{
    if (m_pObject != pObject)
    {
        if (m_pObject)
            DecRefCount((NiRefObject*)m_pObject);
        m_pObject = pObject;
        if (m_pObject)
            ((NiRefObject*)m_pObject)->IncRefCount();
    }
    return *this;
}

static inline bool IsPowerOf2(unsigned int uiValue) throw()
{
    if (uiValue == 0)
        return false;
    return (uiValue & (uiValue - 1)) == 0;
}

static inline unsigned int GetNumMipmapLevels(const NiPixelData* pkData) throw()
{
    return pkData->m_uiMipmapLevels;
}

static inline unsigned int GetFaceTotal(const NiPixelData* pkData) throw()
{
    return pkData->m_uiFaces;
}

struct ConverterTable;
typedef bool(__fastcall* ConvertProc)(NiDevImageConverter*, ConverterTable*, NiPixelData&, const NiPixelData&, int);
typedef NiPixelData*(__thiscall* BumpProc)(NiDevImageConverter*, const NiPixelData&, const NiPixelFormat&);
struct ConverterTable
{
    void* entry00;
    void* entry04;
    void* entry08;
    void* entry0C;
    void* entry10;
    void* entry14;
    void* entry18;
    void* entry1C;
    void* entry20;
    void* entry24;
    void* entry28;
    void* entry2C;
    ConvertProc convert;
    BumpProc bump;
};

// Converts source pixel data to a destination format, optionally expanding compressed data, generating mipmaps, and converting to bump maps.
// @fnv 0x00a7a280
// src: XBOX_PDB 0x00a7a280
NiPixelData* NiDevImageConverter::ConvertPixelData(const NiPixelData& kSrc, const NiPixelFormat& kDstFmt,
                                                 NiPixelData* pkDst, bool bWithMipmaps) throw()
{
    ImageConverterPointer<NiPixelData> spExpanded;
    const NiPixelData* pkSrc = &kSrc;
    if (!kSrc.m_kPixelFormat.GetLittleEndian() || !kDstFmt.GetLittleEndian())
        return 0;

    if (kSrc.m_kPixelFormat.IsCompressed() && kDstFmt.GetFormat() != kSrc.m_kPixelFormat.GetFormat())
    {
        spExpanded = m_kPixelDataExpander.ExpandPixelData(kSrc);
        pkSrc = spExpanded;
    }

    ImageConverterPointer<NiPixelData> spMipmap;
    const NiPixelData* mipSource = 0;
    if (bWithMipmaps && pkSrc->m_uiMipmapLevels <= 1 && IsPowerOf2(pkSrc->GetWidth()) &&
        NiIsPowerOf2(pkSrc->GetHeight()) &&
        (kDstFmt.GetFormat() == NiPixelFormat::FORMAT_RGB || kDstFmt.GetFormat() == NiPixelFormat::FORMAT_RGBA ||
         kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMP || kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMPLUMA))
    {
        spMipmap = GenerateMipmaps(pkSrc, pkDst);
        if (spMipmap)
            mipSource = spMipmap;
        else
            mipSource = pkSrc;
    }
    else
        mipSource = pkSrc;

    if (pkDst && pkDst->m_kPixelFormat == kDstFmt && (!bWithMipmaps || pkDst->m_uiMipmapLevels > 1))
    {
        if (pkDst == mipSource)
            return pkDst;
        else
        {
            ConverterTable* table = *reinterpret_cast<ConverterTable**>(this);
            if (table->convert(this, table, *pkDst, *mipSource, -1))
                return pkDst;
        }
    }

    ImageConverterPointer<NiPixelData> spBump;
    const NiPixelData* bumpSource = mipSource;
    if (kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMP || kDstFmt.GetFormat() == NiPixelFormat::FORMAT_BUMPLUMA)
    {
        spBump = ConvertToBumpMap(*mipSource, kDstFmt);
        if (spBump)
            bumpSource = spBump;
    }

    NiPixelData* pkNew = ::new (NiPixelData::operator new(sizeof(NiPixelData))) NiPixelData(bumpSource->GetWidth(), bumpSource->GetHeight(), kDstFmt,
                                         GetNumMipmapLevels(bumpSource), GetFaceTotal(bumpSource));
    if (ConvertMipLevel(*pkNew, *bumpSource, -1))
        return pkNew;
    return 0;
}

