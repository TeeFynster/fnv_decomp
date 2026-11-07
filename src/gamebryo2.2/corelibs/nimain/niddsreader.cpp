// gamebryo2.2/corelibs/nimain/niddsreader.cpp: NiDDSReader, DDSReader, NiBMPReader, ClsReader and more (23 functions)

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiDDSReader.h"
#include "../../../../include/NiBMPReader.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPixelData.h"
inline void* operator new(size_t, void* memory) throw()
{
    return memory;
}


// The shared stream declares these operations; this unit needs their inline bodies.
// Its approved declaration has no named storage for position or the transfer callbacks.
inline unsigned int NiBinaryStream::BinaryRead(void* buffer, unsigned int bytes,
                                               unsigned int* componentSizes, unsigned int componentCount)
{
    unsigned int bytesRead = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(
        this, buffer, bytes, componentSizes, componentCount);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += bytesRead;
    return bytesRead;
}

inline unsigned int NiBinaryStream::Read(void* buffer, unsigned int bytes)
{
    unsigned int size = 1;
    return BinaryRead(buffer, bytes, &size, 1);
}

inline void NiBinaryStream::Seek(int offset, int whence)
{
    // The image readers use the file-stream extension at virtual slot five.
    typedef void (__thiscall* SeekFile)(NiBinaryStream*, int, int);
    reinterpret_cast<SeekFile>((*reinterpret_cast<void***>(this))[5])(this, offset, whence);
}

static inline void ReadPixelBytes(NiBinaryStream* stream, void* data, unsigned int count)
{
    unsigned int size = 1;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(stream) + 4) +=
        (*reinterpret_cast<NiBinaryStream::ReadFunction*>(reinterpret_cast<char*>(stream) + 8))(
            stream, data, count, &size, 1);
}

static __forceinline void ReadStreamBytes(NiBinaryStream& stream, void* buffer, int size)
{
    stream.BinaryRead(buffer, size, reinterpret_cast<unsigned int*>(&size), 1);
}

extern const NiPixelFormat DAT_011aa2e8;
extern void(__stdcall* DAT_00fdf054)(void*);

inline NiImageReader::NiImageReader()
{
    DAT_00fdf054(lock);
}

// Initializes the NiBMPReader fields: zeroes height, width, unknown, x, y, sets format to DAT_011aa2e8 and clears b1 and b2.
// @fnv 0x00a8e410
NiBMPReader::NiBMPReader()
{
    height = 0;
    width = 0;
    format = DAT_011aa2e8;
    unknown = 0;
    x = 0;
    y = 0;
    b1 = false;
    b2 = false;
}

// For each of the count at thisPtr+0x10e, copies one source byte into three consecutive destination bytes.
// @fnv 0x00a8d4e0
void __fastcall ExpandGrayToRgb(void* thisPtr, int, unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < *(unsigned short*)((char*)thisPtr + 0x10e); ++i)
    {
        dst[0] = dst[1] = dst[2] = *src;
        dst += 3;
        src += 1;
    }
}

// Converts a count of 16-bit RGB565 pixels from pucSrc into 24-bit RGB888 bytes written to pucDest.
// @fnv 0x00a8d520
void __fastcall ConvertRgb565ToRgb888(char* pThis, int, unsigned char* pucSrc, unsigned char* pucDest)
{
    for (unsigned int i = 0; i < *(unsigned short*)(pThis + 0x10e); i++)
    {
        *(pucDest++) = (pucSrc[1] & 0x7c) << 1;
        *(pucDest++) = ((pucSrc[1] & 0x03) << 6) + ((pucSrc[0] & 0xe0) >> 2);
        *(pucDest++) = (pucSrc[0] & 0x1f) << 3;
        pucSrc += 2;
    }
}

// @fnv 0x00a8d590
// src: GUESS 0x00a8d590 (confidence: low)
void __fastcall NiDDSReader_ProcessEntries_00a8d590(char* this_ptr, int, unsigned char* pSrcIndices, unsigned char* pDst)
{
    for (unsigned int i = 0; i < *(unsigned short*)(this_ptr + 0x10e); i++)
    {
        unsigned int uiPaletteIndex =
            ((unsigned int)pSrcIndices[1] << 8) - *(unsigned short*)(this_ptr + 0x104) + pSrcIndices[0];
        unsigned char* pPaletteEntry = *(unsigned char**)(this_ptr + 0x16c) + uiPaletteIndex * 4;
        *pDst++ = pPaletteEntry[0];
        *pDst++ = pPaletteEntry[1];
        *pDst++ = pPaletteEntry[2];
        pSrcIndices += 2;
    }
}

int __cdecl NiStricmp(const char*, const char*);
// @fnv 0x00a8c0e0
// src: XBOX_PDB 0x00a8c0e0
bool __stdcall NiDDSReader_CanReadFile(const char* extension)
{
    if (NiStricmp(extension, ".dds") != 0)
        return false;
    return true;
}

// @fnv 0x00a8c100
bool __stdcall IsValidBitDepth(int a, int b, int c, int d, unsigned int bits)
{
    if (bits == 16 || bits == 24 || bits == 32)
        return true;
    return false;
}

extern const NiPixelFormat gNiPoint3StartupSrc;
struct NiPixelFormatMaskView : NiPixelFormat
{
    unsigned int GetMask(int) const;
};
// Returns a canonical NiPixelFormat for 16-, 24- and 32-bit formats, otherwise returns fmt unchanged.
// @fnv 0x00a8c120
NiPixelFormat __stdcall NormalizePixelFormat(NiPixelFormat aFormat)
{
    switch (aFormat.bits)
    {
    case 16:
        if (static_cast<NiPixelFormatMaskView&>(aFormat).GetMask(3) != 0)
            return gNiPoint3StartupSrc;
        return DAT_011aa2e8;
    case 24:
        return DAT_011aa2e8;
    case 32:
        return gNiPoint3StartupSrc;
    }
    return aFormat;
}

extern NiPixelFormat DAT_011aa498;
struct FUN_00a8c190 : NiImageReader
{
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    unsigned int m_iFourthElementInteger;
    NiPixelFormat m_kPixelFormat;
    FUN_00a8c190();
    virtual void vfn_x();
};
// @fnv 0x00a8c190
FUN_00a8c190::FUN_00a8c190()
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_kPixelFormat = DAT_011aa498;
}

// For each of the count at self+0x10e, reads a byte from src, subtracts the byte at self+0x104, and writes the result to dst.
// @fnv 0x00a8d4a0
// src: GUESS 0x00a8d4a0 (confidence: medium)
void __fastcall Object_CopyBytesWithOffset(char* self, int edx, const unsigned char* src, unsigned char* dst)
{
    unsigned int i;
    for (i = 0; i < *(unsigned short*)(self + 0x10e); i++)
    {
        unsigned char v = *src++;
        *dst++ = v - *(unsigned char*)(self + 0x104);
    }
}

// @fnv 0x00a8d600
// src: GUESS 0x00a8d600 (confidence: low)
void __fastcall Object_ProcessEntries_00a8d600(char* self, int edx, const unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < *(unsigned short*)(self + 0x10e); ++i)
    {
        unsigned int idx = (src[1] << 8) - *(unsigned short*)(self + 0x104) + src[0];
        const unsigned char* pEntry = *(unsigned char**)(self + 0x16c) + idx * 4;
        *dst++ = pEntry[0];
        *dst++ = pEntry[1];
        *dst++ = pEntry[2];
        *dst++ = pEntry[3];
        src += 2;
    }
}

struct FUN_00a8d670_obj
{
    char pad[0x10e];
    unsigned short width;
};
// @fnv 0x00a8d670
// src: GUESS 0x00a8d670 (confidence: high)
void __fastcall NiDDSReader_SwapRedBlue24BitPixels(FUN_00a8d670_obj* self, int unused, const unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < self->width; i++)
    {
        *dst++ = src[2];
        *dst++ = src[1];
        *dst++ = src[0];
        src += 3;
    }
}

struct FUN_00a8d6c0_obj
{
    char pad[0x10e];
    unsigned short width;
};
// @fnv 0x00a8d6c0
// src: GUESS 0x00a8d6c0 (confidence: low)
void __fastcall Object_ProcessEntries_00a8d6c0(FUN_00a8d6c0_obj* self, int unused, const unsigned char* src, unsigned char* dst)
{
    for (unsigned int i = 0; i < self->width; i++)
    {
        *dst++ = src[2];
        *dst++ = src[1];
        *dst++ = src[0];
        *dst++ = src[3];
        src += 4;
    }
}

int __cdecl NiStricmp(const char*, const char*);
// @fnv 0x00a8d710
bool __stdcall IsTgaExtension(const char* ext)
{
    if (NiStricmp(ext, ".tga") == 0 || NiStricmp(ext, ".targa") == 0)
        return true;
    return false;
}

struct FUN_00a8d750 : NiImageReader
{
    unsigned char b100, b101, b102;
    unsigned char pad103;
    unsigned short w104, w106;
    unsigned char b108;
    unsigned char pad109;
    unsigned short w10a, w10c, w10e, w110;
    unsigned char b112, b113, b114, b115, b116, b117, b118;
    unsigned char pad119[3];
    NiPixelFormat m_eFormat;
    unsigned int d160, d164, d168, d16c, d170, d174;
    unsigned char b178, b179, b17a, b17b, b17c;
    FUN_00a8d750();
    virtual void vfn_x();
};
// @fnv 0x00a8d750
FUN_00a8d750::FUN_00a8d750()
{
    b100 = 0;
    b101 = 0;
    b102 = 0;
    w104 = 0;
    w106 = 0;
    b108 = 0;
    w10a = 0;
    w10c = 0;
    w10e = 0;
    w110 = 0;
    b112 = 0;
    b113 = 0;
    b114 = 0;
    b115 = 0;
    b116 = 0;
    b117 = 0;
    b118 = 0;
    m_eFormat = DAT_011aa2e8;
    d160 = 0;
    d164 = 0;
    d168 = 0;
    d16c = 0;
    d170 = 0;
    d174 = 0;
    b178 = 0;
    b179 = 0;
    b17a = 0;
    b17b = 0;
    b17c = 0;
}

int __cdecl NiStricmp(const char*, const char*);
// @fnv 0x00a8e3f0
bool __stdcall IsNotBmpExtension(const char* extension)
{
    if (NiStricmp(extension, ".bmp") != 0)
        return false;
    return true;
}

extern int DAT_0109f4b0;
extern int DAT_0109f3d0;
extern void(__stdcall* DAT_00fdf058)(void*);

void __cdecl _NiFree_00aa10f0(void* apMemory);

extern MemoryManager DAT_011f6238;

struct FUN_00a8d850_cls : NiImageReader
{
    unsigned int unk100, unk104, unk108, unk10c;
    unsigned int unk110, unk114, unk118, unk11c;
    unsigned int unk120, unk124, unk128, unk12c;
    unsigned int unk130, unk134, unk138, unk13c;
    unsigned int unk140, unk144, unk148, unk14c;
    unsigned int unk150, unk154, unk158, unk15c;
    unsigned int unk160;
    void* m_p164;
    unsigned int unk168;
    void* m_p16c;

    FUN_00a8d850_cls* DestroyImageReader(unsigned char acFlags);
};

// @fnv 0x00a8d850
FUN_00a8d850_cls* FUN_00a8d850_cls::DestroyImageReader(unsigned char acFlags)
{
    void* pFirst = m_p164;
    *(int*)this = (int)&DAT_0109f4b0;
    _NiFree_00aa10f0(pFirst);
    void* pSecond = m_p16c;
    DAT_011f6238.Deallocate(pSecond);
    *(int*)this = (int)&DAT_0109f3d0;
    DAT_00fdf058(lock);
    if (acFlags & 1)
    {
        DAT_011f6238.Deallocate(this);
    }
    return this;
}

struct ClsSub
{
    ClsSub* NiPalette_NiPalette_00a8b110(int b, int w, int d);
};
extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern void __cdecl _NiFree_00aa10f0(void* p);
extern void* __cdecl _NiMalloc_00aa1070(unsigned int size);
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);

struct ClsReader : NiImageReader
{
    unsigned char b100;
    unsigned char b101;
    unsigned char b102;
    unsigned char f103;
    unsigned short w104;
    unsigned short w106;
    unsigned char b108;
    unsigned char f109;
    unsigned short w10a;
    unsigned short w10c;
    unsigned short w10e;
    unsigned short w110;
    unsigned char b112;
    unsigned char b113;
    unsigned char b114;
    unsigned char b115;
    unsigned char b116;
    unsigned char b117;
    unsigned char b118;
    unsigned char f119;
    unsigned char f11a;
    unsigned char f11b;
    NiPixelFormat m_eFormat;
    unsigned int m_pRayCursor;
    unsigned char* m_buffer;
    int d168;
    int d16c;
    void (ClsReader::*m_fn170)(unsigned char*, int);
    int d174;
    bool Slot3(NiBinaryStream* stream, int* o3, int* o2, NiPixelFormat* fmt, unsigned char* byteOut, int* o1)
    {
        // The shared base declares vf03 without this reader's parameters.
        typedef bool (__thiscall* ReadHeader)(ClsReader*, NiBinaryStream*, int*, int*, NiPixelFormat*, unsigned char*, int*);
        return reinterpret_cast<ReadHeader>((*reinterpret_cast<void***>(this))[3])(this, stream, o3, o2, fmt,
                                                                                  byteOut, o1);
    }
    void ReadPixels(NiBinaryStream* stream);
    void Decode(NiBinaryStream* stream, unsigned char* buf, int cap);
    NiPixelData* ReadImage(NiBinaryStream* stream, NiPixelData* image);
};

// Reads pixel data from the stream into an image, allocating or reusing the image and buffer, then writes each row via m_fn170.
// @fnv 0x00a8e120
NiPixelData* ClsReader::ReadImage(NiBinaryStream* stream, NiPixelData* image)
{
    NiPixelFormat fmt;
    void* lockPtr = lock;
    DAT_00fdf05c(lockPtr);
    int out1;
    int out2;
    int out3;
    unsigned char byteOut;
    if (!Slot3(stream, &out3, &out2, &fmt, &byteOut, &out1))
    {
        DAT_00fdf100(lockPtr);
        return 0;
    }
    int count = (int)(unsigned char)b114 * (int)(unsigned short)w10e;
    if (b114 == 0)
    {
        if (b112 != 4)
        {
            DAT_00fdf100(lockPtr);
            return 0;
        }
        count = (int)(unsigned short)w10e >> 1;
    }
    if (b101 != 0)
    {
        if ((unsigned int)((int)(unsigned short)w106 + (int)(unsigned short)w104 + 1) >= 0x4000)
        {
            DAT_00fdf100(lockPtr);
            return 0;
        }
        ReadPixels(stream);
    }
    else if (b116 != 0)
    {
        DAT_00fdf100(lockPtr);
        return 0;
    }
    NiPixelData* result;
    if (image != 0 && *image->m_puiWidth == (unsigned int)(unsigned short)w10e &&
        *image->m_puiHeight == (unsigned int)(unsigned short)w110 && image->m_kPixelFormat == m_eFormat)
    {
        result = image;
    }
    else
    {
        void* pImageMem = Object_DispatchCommandFour(0x74);
        if (pImageMem != 0)
        {
            result = ::new (pImageMem) NiPixelData((int)(unsigned short)w10e, (int)(unsigned short)w110, &m_eFormat, 1, 1);
        }
        else
        {
            result = 0;
        }
        image = result;
    }
    if (b116 != 0)
    {
        void* pSubMem = Object_DispatchCommandFour(0x24);
        ClsSub* sub;
        if (pSubMem != 0)
        {
            sub = ((ClsSub*)pSubMem)->NiPalette_NiPalette_00a8b110((int)(unsigned char)b115, (int)(unsigned short)w106, d16c);
        }
        else
        {
            sub = 0;
        }
        image->NiPixelData_SetPalette(reinterpret_cast<NiPalette*>(sub));
    }
    if (m_pRayCursor < (unsigned int)count)
    {
        m_pRayCursor = count;
        _NiFree_00aa10f0(m_buffer);
        m_buffer = (unsigned char*)_NiMalloc_00aa1070(m_pRayCursor);
    }
    int iOffset = (int)*image->m_puiOffsetInBytes + (int)image->m_pucPixels;
    int step = image->m_uiPixelStride * (int)*image->m_puiWidth;
    if (step == 0)
    {
        step = (int)(*image->m_puiWidth >> 1);
    }
    if (b117 != 0)
    {
        iOffset += ((int)(unsigned short)w110 - 1) * step;
        step = -step;
    }
    int flag;
    if (b118 != 0)
    {
        for (unsigned int i = 0; i < (unsigned int)(unsigned short)w110; ++i)
        {
            Decode(stream, m_buffer, m_pRayCursor);
            (this->*m_fn170)(m_buffer, iOffset);
            iOffset += step;
        }
    }
    else
    {
        for (unsigned int i = 0; i < (unsigned int)(unsigned short)w110; ++i)
        {
            unsigned char* rowBuffer = m_buffer;
            flag = 1;
            stream->BinaryRead(rowBuffer, count, reinterpret_cast<unsigned int*>(&flag), 1);
            (this->*m_fn170)(m_buffer, iOffset);
            iOffset += step;
        }
    }
    DAT_00fdf100(lockPtr);
    return result;
}

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_010a2484;

template <class T> inline unsigned int NiBinaryStreamLoad(NiBinaryStream& kStream, T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return kStream.BinaryRead(pkValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

inline void ReadBinaryValue(NiBinaryStream& kStream, unsigned int& uiValue)
{
    NiBinaryStreamLoad(kStream, &uiValue, 1);
}

void __cdecl NiStreamLoadBinary_00a575b0(NiBinaryStream& kStream, unsigned int& uiValue);
NiPixelFormat __cdecl CreateFromMasks(unsigned int uiBitsPerPixel, unsigned int uiRedMask, unsigned int uiGreenMask,
                                      unsigned int uiBlueMask, unsigned int uiAlphaMask);

inline void NiSwap32(char* pcValue)
{
    char cTemp = pcValue[0];
    pcValue[0] = pcValue[3];
    pcValue[3] = cTemp;
    cTemp = pcValue[1];
    pcValue[1] = pcValue[2];
    pcValue[2] = cTemp;
}

extern NiPixelFormat DAT_011aa498;
extern NiPixelFormat DAT_011aa4e0;
extern NiPixelFormat DAT_011aa528;
extern NiPixelFormat DAT_011aa570;
extern NiPixelFormat DAT_011aa5b8;
extern NiPixelFormat DAT_011aa600;
extern NiPixelFormat DAT_011aa648;
extern NiPixelFormat DAT_011aa690;
extern NiPixelFormat DAT_011aa6d8;

inline void NiDDSReader::Lock()
{
    DAT_00fdf05c(lock);
}

inline void NiDDSReader::Unlock()
{
    DAT_00fdf100(lock);
}

__declspec(noinline) bool NiDDSReader::IsValidBitDepth(unsigned int uiRedMask, unsigned int uiGreenMask,
                                                       unsigned int uiBlueMask, unsigned int uiAlphaMask,
                                                       unsigned int uiBitsPerPixel)
{
    return uiBitsPerPixel == 16 || uiBitsPerPixel == 24 || uiBitsPerPixel == 32;
}

// Parses a DDS header from kIst, validating magic, size, and pixel format, then sets uiWidth, uiHeight, kFormat, bMipmap, and uiFaces.
// @fnv 0x00a8c1e0
// src: XBOX_PDB 0x00a8c1e0
bool NiDDSReader::ReadHeader_00a8c1e0(NiBinaryStream& kIst, unsigned int& uiWidth, unsigned int& uiHeight,
                               NiPixelFormat& kFormat, bool& bMipmap, unsigned int& uiFaces)
{
    Lock();

    unsigned int uiMagic;
    ReadBinaryValue(kIst, uiMagic);
    if (uiMagic != 0x20534444)
    {
        unsigned int uiSwapped = uiMagic;
        NiSwap32((char*)&uiSwapped);
        if (uiSwapped != 0x20534444)
        {
            Unlock();
            return false;
        }
        kIst.SetEndianSwap(true);
    }

    unsigned int uiSize;
    ReadBinaryValue(kIst, uiSize);
    if (uiSize != 124)
    {
        Unlock();
        return false;
    }

    unsigned int uiFlags;
    ReadBinaryValue(kIst, uiFlags);
    if ((uiFlags & 0x1007) != 0x1007)
    {
        Unlock();
        return false;
    }

    ReadBinaryValue(kIst, m_uiImageHeight);
    ReadBinaryValue(kIst, m_uiImageWidth);

    unsigned int uiTemp;
    ReadBinaryValue(kIst, uiTemp);
    ReadBinaryValue(kIst, uiTemp);
    if ((uiFlags & 0x800000) && uiTemp != 0)
    {
        Unlock();
        return false;
    }

    unsigned int uiMipMapCount;
    ReadBinaryValue(kIst, uiMipMapCount);
    kIst.Seek(44, DAT_010a2484);

    ReadBinaryValue(kIst, uiTemp);
    unsigned int uiPFFlags;
    ReadBinaryValue(kIst, uiPFFlags);
    unsigned int uiFourCC;
    ReadBinaryValue(kIst, uiFourCC);

    m_bCubeMap = false;

    if (uiPFFlags & 0x4)
    {
        const NiPixelFormat* pkFormat;
        switch (uiFourCC)
        {
        case 0x31545844:
            pkFormat = &DAT_011aa498;
            break;
        case 0x33545844:
            pkFormat = &DAT_011aa4e0;
            break;
        case 0x35545844:
            pkFormat = &DAT_011aa528;
            break;
        case 0x6f:
            pkFormat = &DAT_011aa6d8;
            break;
        case 0x70:
            pkFormat = &DAT_011aa648;
            break;
        case 0x71:
            pkFormat = &DAT_011aa5b8;
            break;
        case 0x72:
            pkFormat = &DAT_011aa600;
            break;
        case 0x73:
            pkFormat = &DAT_011aa690;
            break;
        case 0x74:
            pkFormat = &DAT_011aa570;
            break;
        default:
            Unlock();
            return false;
        }
        m_eFormat = *pkFormat;
        kFormat = m_eFormat;
        kIst.Seek(20, DAT_010a2484);
    }
    else if (uiPFFlags & 0x40)
    {
        unsigned int uiRGBBitCount;
        unsigned int uiRBitMask;
        unsigned int uiGBitMask;
        unsigned int uiBBitMask;
        unsigned int uiABitMask;
        NiStreamLoadBinary_00a575b0(kIst, uiRGBBitCount);
        NiStreamLoadBinary_00a575b0(kIst, uiRBitMask);
        NiStreamLoadBinary_00a575b0(kIst, uiGBitMask);
        NiStreamLoadBinary_00a575b0(kIst, uiBBitMask);
        NiStreamLoadBinary_00a575b0(kIst, uiABitMask);
        if (!(uiPFFlags & 0x1))
            uiABitMask = 0;
        if (!IsValidBitDepth(uiRBitMask, uiGBitMask, uiBBitMask, uiABitMask, uiRGBBitCount))
        {
            Unlock();
            return false;
        }
        kFormat = CreateFromMasks(uiRGBBitCount, uiRBitMask, uiGBitMask, uiBBitMask, uiABitMask);
        m_eFormat = kFormat;
        kFormat = NormalizePixelFormat(kFormat);
    }
    else
    {
        Unlock();
        return false;
    }

    unsigned int uiCaps1;
    NiStreamLoadBinary_00a575b0(kIst, uiCaps1);
    if (!(uiCaps1 & 0x8) && !(uiCaps1 & 0x401000))
    {
        Unlock();
        return false;
    }

    unsigned int uiCaps2;
    NiStreamLoadBinary_00a575b0(kIst, uiCaps2);
    if (uiCaps2 & 0x200000)
    {
        Unlock();
        return false;
    }
    if (uiCaps2 & 0x200)
    {
        if (!(uiCaps2 & 0x400) || !(uiCaps2 & 0x800) || !(uiCaps2 & 0x1000) || !(uiCaps2 & 0x2000) ||
            !(uiCaps2 & 0x4000) || !(uiCaps2 & 0x8000))
        {
            Unlock();
            return false;
        }
    }
    uiFaces = (uiCaps2 & 0x200) ? 6 : 1;

    kIst.Seek(12, DAT_010a2484);

    uiWidth = m_uiImageWidth;
    uiHeight = m_uiImageHeight;

    if ((uiCaps1 & 0x8) && (uiCaps1 & 0x400000) && uiMipMapCount != 1)
    {
        bMipmap = true;
        m_uiMipMapLevels = uiMipMapCount;
    }
    else
    {
        bMipmap = false;
        m_uiMipMapLevels = 1;
    }

    Unlock();
    return true;
}

struct MaskData
{
    unsigned int mask[4];
    unsigned char shift0, shift1, shift2, shift3;
    unsigned char gap0, gap1, gap2, gap3;
    void FUN_00a779b0(const NiPixelFormat&);
    unsigned char ExpandChannel0(unsigned int value) const
    {
        unsigned char g = gap0;
        unsigned int component = (value & mask[0]) >> shift0;
        unsigned int result = 0;
        unsigned char remaining = g;
        unsigned char bits = 8 - g;
        while (bits <= remaining)
        {
            result |= component;
            remaining -= bits;
            result <<= bits;
        }
        return (unsigned char)((component << g) | (result >> bits) | (component >> (8 - g - remaining)));
    }
    unsigned char ExpandChannel(unsigned int value, unsigned int ch) const
    {
        unsigned int component = (value & mask[ch]) >> (&shift0)[ch];
        unsigned int result = 0;
        unsigned char remaining = (&gap0)[ch];
        unsigned char bits = 8 - (&gap0)[ch];
        while (bits <= remaining)
        {
            result |= component;
            remaining -= bits;
            result <<= bits;
        }
        return (unsigned char)((component << (&gap0)[ch]) | (result >> bits) |
                               (component >> (8 - (&gap0)[ch] - remaining)));
    }
};
struct FormatCompare : NiPixelFormat
{
    bool FUN_00a765c0(const NiPixelFormat&) const;
};
struct Component
{
    unsigned int semantic;
    unsigned int representation;
    unsigned char bits;
    unsigned char flags;
    unsigned short unk0a;
};
struct FormatView
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    Component components[4];
    unsigned char GetPixelBitData(unsigned int semantic) const
    {
        for (unsigned int i = 0; i < 4; ++i)
            if (components[i].semantic == semantic)
                return components[i].bits;
        return 0;
    }
};
// Reads one mip level from a stream and expands its packed pixels into RGBA bytes, forcing alpha to 255 when the source format has no alpha channel.
// @fnv 0x00a8c7a0
// src: XBOX_PDB 0x00a8c7a0
void __cdecl NiDDSReader_Read32Bit(NiBinaryStream* stream, NiPixelData* data, NiPixelFormat source, NiPixelFormat dest,
                          unsigned int level, unsigned int face)
{
    unsigned char* __restrict pixels = data->m_pucPixels + data->m_puiOffsetInBytes[level] + data->m_puiOffsetInBytes[data->m_uiMipmapLevels] * face;
    ReadPixelBytes(stream, pixels, data->m_puiOffsetInBytes[level + 1] - data->m_puiOffsetInBytes[level]);
    MaskData masks;
    masks.FUN_00a779b0(source);
    unsigned int width = data->m_puiWidth[level];
    unsigned int height = data->m_puiHeight[level];
    if (((FormatCompare&)source).FUN_00a765c0(dest))
    {
        unsigned int* input = (unsigned int*)pixels;
        if (((FormatView&)source).GetPixelBitData(3) != 0)
        {
            for (unsigned int y = 0; y < height; y++)
            {
                for (unsigned int x = 0; x < width; x++)
                {
                    unsigned char r = masks.ExpandChannel0(*input);
                    unsigned char g = masks.ExpandChannel(*input, 1);
                    unsigned char b = masks.ExpandChannel(*input, 2);
                    unsigned char a = masks.ExpandChannel(*input, 3);
                    *pixels++ = r;
                    *pixels++ = g;
                    *pixels++ = b;
                    *pixels++ = a;
                    ++input;
                }
            }
        }
        else
        {
            for (unsigned int y = 0; y < height; y++)
            {
                for (unsigned int x = 0; x < width; x++)
                {
                    unsigned char r = masks.ExpandChannel0(*input);
                    unsigned char g = masks.ExpandChannel(*input, 1);
                    unsigned char b = masks.ExpandChannel(*input, 2);
                    *pixels++ = r;
                    *pixels++ = g;
                    *pixels++ = b;
                    *pixels++ = 255;
                    ++input;
                }
            }
        }
    }
}

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
void __cdecl Convert32(NiBinaryStream*, NiPixelData*, NiPixelFormat, NiPixelFormat, unsigned int, unsigned int,
                       unsigned char);
void __cdecl Convert24(NiBinaryStream*, NiPixelData*, NiPixelFormat, NiPixelFormat, unsigned int, unsigned int,
                       unsigned char);
void __cdecl Convert16(NiBinaryStream*, NiPixelData*, NiPixelFormat, NiPixelFormat, unsigned int, unsigned int,
                       unsigned char);
inline bool ReadDDSHeader(NiDDSReader* reader, NiBinaryStream* stream, unsigned int* width, unsigned int* height,
                          NiPixelFormat* format, bool* mipmap, unsigned int* faces)
{
    // The shared base declares vf03 without this reader's parameters.
    typedef bool (__thiscall* ReadHeader)(NiDDSReader*, NiBinaryStream*, unsigned int*, unsigned int*, NiPixelFormat*,
                                         bool*, unsigned int*);
    return reinterpret_cast<ReadHeader>((*reinterpret_cast<void***>(reader))[3])(reader, stream, width, height,
                                                                                format, mipmap, faces);
}

// Reads DDS pixel data for all faces and mip levels from stream into result, converting pixel format if it differs from the requested format.
// @fnv 0x00a8d0d0
NiPixelData* __fastcall ReadDDSPixelData(NiDDSReader* reader, int, NiBinaryStream* stream, NiPixelData* apPixelData)
{
    unsigned int uiWidth, uiHeight, faceCount;
    bool headerFlag;
    NiPixelFormat requested;
    DAT_00fdf05c(reader->lock);
    if (!ReadDDSHeader(reader, stream, &uiWidth, &uiHeight, &requested, &headerFlag, &faceCount))
    {
        DAT_00fdf100(reader->lock);
        return 0;
    }
    if (!apPixelData || apPixelData->m_puiWidth[0] != reader->m_uiImageWidth || apPixelData->m_puiHeight[0] != reader->m_uiImageHeight ||
        !(apPixelData->m_kPixelFormat == requested) || apPixelData->m_uiMipmapLevels != reader->m_uiMipMapLevels || apPixelData->m_uiFaces != faceCount)
    {
        void* memory = NiPixelData::operator new(sizeof(NiPixelData));
        apPixelData = memory ? ::new (memory) NiPixelData(reader->m_uiImageWidth, reader->m_uiImageHeight, requested,
                                                       reader->m_uiMipMapLevels, faceCount) : 0;
    }
    unsigned int mipCount = apPixelData->m_uiMipmapLevels;
    if (requested == reader->m_eFormat)
    {
        for (unsigned int face = 0; face < faceCount; ++face)
        {
            unsigned int faceIndex;
            switch (face - 1)
            {
            case 0:
                faceIndex = 1;
                break;
            case 1:
                faceIndex = 2;
                break;
            case 2:
                faceIndex = 3;
                break;
            case 3:
                faceIndex = 4;
                break;
            case 4:
                faceIndex = 5;
                break;
            default:
                faceIndex = 0;
                break;
            }
            for (unsigned int mip = 0; mip < mipCount; ++mip)
            {
                unsigned char* destination = apPixelData->m_pucPixels + apPixelData->m_puiOffsetInBytes[mip] +
                                             apPixelData->m_puiOffsetInBytes[apPixelData->m_uiMipmapLevels] * faceIndex;
                unsigned int size = apPixelData->m_puiOffsetInBytes[mip + 1] - apPixelData->m_puiOffsetInBytes[mip];
                unsigned int count = 1;
                stream->BinaryRead(destination, size, &count, 1);
            }
        }
    }
    else
    {
        for (unsigned int face = 0; face < faceCount; ++face)
        {
            unsigned int faceIndex;
            switch (face - 1)
            {
            case 0:
                faceIndex = 1;
                break;
            case 1:
                faceIndex = 2;
                break;
            case 2:
                faceIndex = 3;
                break;
            case 3:
                faceIndex = 4;
                break;
            case 4:
                faceIndex = 5;
                break;
            default:
                faceIndex = 0;
                break;
            }
            for (unsigned int mip = 0; mip < mipCount; ++mip)
            {
                switch (reader->m_eFormat.bits)
                {
                case 32:
                    Convert32(stream, apPixelData, reader->m_eFormat, requested, mip, faceIndex, reader->m_bCubeMap);
                    break;
                case 24:
                    Convert24(stream, apPixelData, reader->m_eFormat, requested, mip, faceIndex, reader->m_bCubeMap);
                    break;
                case 16:
                    Convert16(stream, apPixelData, reader->m_eFormat, requested, mip, faceIndex, reader->m_bCubeMap);
                    break;
                }
            }
        }
    }
    DAT_00fdf100(reader->lock);
    return apPixelData;
}

namespace fnv_00a8dce0 {
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);
extern int DAT_010a2484;
extern const NiPixelFormat DAT_011aa180;
extern const NiPixelFormat DAT_011aa1c8;
extern const NiPixelFormat DAT_011aa210;
extern const NiPixelFormat DAT_011aa258;
extern const NiPixelFormat DAT_011aa2a0;
void __fastcall DecodeBytes(char* self, int edx, const unsigned char* src, unsigned char* dst);
void __fastcall Object_CopyBytesWithOffset(char* self, int edx, const unsigned char* src, unsigned char* dst);
void __fastcall ExpandGrayToRgb(void* thisPtr, int, unsigned char* src, unsigned char* dst);
void __fastcall ConvertRgb565ToRgb888(char* pThis, int, unsigned char* pucSrc, unsigned char* pucDest);
void __fastcall NiDDSReader_ProcessEntries_00a8d590(char* this_ptr, int, unsigned char* pSrc, unsigned char* pDst);
void __fastcall Object_ProcessEntries_00a8d600(char* self, int edx, const unsigned char* src, unsigned char* dst);
void __fastcall NiDDSReader_SwapRedBlue24BitPixels(char*, int, unsigned char*, unsigned char*);
void __fastcall Object_ProcessEntries_00a8d6c0(char*, int, unsigned char*, unsigned char*);
struct DDSReader : NiImageReader
{
    unsigned char b100, b101, b102, unk103;
    unsigned short w104, w106;
    unsigned char b108, unk109;
    unsigned short w10a, w10c, w10e, w110;
    unsigned char b112, b113, b114, b115, b116, b117, b118;
    unsigned char unk119, unk11a, unk11b;
    NiPixelFormat m_eFormat;
    unsigned int d160, d164, d168, d16c;
    void(__fastcall* m_pfnPixelConverter)(char*, int, unsigned char*, unsigned char*);
    unsigned int d174;
    unsigned char b178, b179, b17a, b17b;
    bool NiTGAReader_ReadHeader(NiBinaryStream* stream, int* pA, int* pB, NiPixelFormat* pFmt, unsigned char* pByte, int* pFlag);
};
// Seeks to the start, reads fields, selects m_eFormat and a converter, and writes values to pFlag, pA, pB, pFmt, and pByte.
// @fnv 0x00a8dce0
// src: GAMEBRYO_SRC 0x00a8dce0
bool DDSReader::NiTGAReader_ReadHeader(NiBinaryStream* stream, int* apWidth, int* apHeight, NiPixelFormat* apFormat,
                             unsigned char* pByte, int* pFlag)
{
    NiBinaryStream& kReadStream = *stream;
    kReadStream.SetEndianSwap(false);
    DAT_00fdf05c(lock);
    *pFlag = 1;
    ReadStreamBytes(kReadStream, &b100, 1);
    ReadStreamBytes(kReadStream, &b101, 1);
    ReadStreamBytes(kReadStream, &b102, 1);
    ReadStreamBytes(kReadStream, &w104, 2);
    ReadStreamBytes(kReadStream, &w106, 2);
    ReadStreamBytes(kReadStream, &b108, 1);
    ReadStreamBytes(kReadStream, &w10a, 2);
    ReadStreamBytes(kReadStream, &w10c, 2);
    ReadStreamBytes(kReadStream, &w10e, 2);
    ReadStreamBytes(kReadStream, &w110, 2);
    ReadStreamBytes(kReadStream, &b112, 1);
    ReadStreamBytes(kReadStream, &b113, 1);
    if (b100)
    {
        kReadStream.Seek(b100, DAT_010a2484);
    }
    b117 = ~(b113 >> 5) & 1;
    switch (b102)
    {
    case 1:
        b116 = 1;
        b118 = 0;
        break;
    case 2:
        b118 = 0;
        b116 = 0;
        break;
    case 3:
        b118 = 0;
        b116 = 0;
        break;
    case 9:
        b116 = 1;
        b118 = 1;
        break;
    case 10:
        b118 = 1;
        b116 = 0;
        break;
    case 11:
        b118 = 1;
        b116 = 0;
        break;
    default:
        DAT_00fdf100(lock);
        return false;
    }
    unsigned char bHasPalette = b116;
    unsigned char bits = bHasPalette ? b108 : b112;
    bool bIs32Bit = bits == 0x20;
    b115 = bIs32Bit;
    if (bHasPalette)
    {
        if (w106 == 0x10)
            m_eFormat = bIs32Bit ? DAT_011aa1c8 : DAT_011aa180;
        else
            m_eFormat = bIs32Bit ? DAT_011aa258 : DAT_011aa210;
    }
    else
    {
        m_eFormat = bIs32Bit ? DAT_011aa2a0 : DAT_011aa2e8;
    }
    switch (b112)
    {
    case 4:
        b114 = 0;
        if (bHasPalette)
            m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))DecodeBytes;
        else
        {
            DAT_00fdf100(lock);
            return false;
        }
        break;
    case 8:
        b114 = 1;
        if (bHasPalette)
            m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))Object_CopyBytesWithOffset;
        else
            m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))ExpandGrayToRgb;
        break;
    case 15:
    case 16:
        b114 = 2;
        if (bHasPalette)
        {
            if (bIs32Bit)
                m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))Object_ProcessEntries_00a8d600;
            else
                m_pfnPixelConverter = NiDDSReader_ProcessEntries_00a8d590;
        }
        else
            m_pfnPixelConverter = ConvertRgb565ToRgb888;
        break;
    case 24:
        b114 = 3;
        m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))NiDDSReader_SwapRedBlue24BitPixels;
        break;
    case 32:
        b114 = 4;
        m_pfnPixelConverter = (void(__fastcall*)(char*, int, unsigned char*, unsigned char*))Object_ProcessEntries_00a8d6c0;
        break;
    }
    b178 = 0;
    d174 = 0;
    *apWidth = w10e;
    *apHeight = w110;
    *apFormat = m_eFormat;
    *pByte = 0;
    DAT_00fdf100(lock);
    return true;
}
}  // namespace fnv_00a8dce0

extern MemoryManager g_memoryManager;
__declspec(dllimport) void __stdcall DeleteCriticalSection(void*);
struct FUN_00a8e480 : NiImageReader
{
    virtual ~FUN_00a8e480();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// @fnv 0x00a8e480
FUN_00a8e480::~FUN_00a8e480()
{
    DeleteCriticalSection((char*)this + 0x80);
}

namespace fnv_00a8cc40 {
extern const NiPixelFormat DAT_011aa2a0;
struct FormatAccess
{
    unsigned int GetMask(int) const;
    unsigned char FUN_00a62230(int) const;
};
struct ChannelInfo
{
    unsigned int mask[4];
    unsigned char shift0, shift1, shift2, shift3;
    unsigned char bits0, bits1, bits2, bits3;
    __declspec(noinline) ChannelInfo(const NiPixelFormat& f);
};
ChannelInfo::ChannelInfo(const NiPixelFormat& f)
{
    const FormatAccess& access = reinterpret_cast<const FormatAccess&>(f);
    mask[0] = access.GetMask(0);
    shift0 = access.FUN_00a62230(0);
    unsigned char b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 0)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits0 = 8 - b;
    mask[1] = access.GetMask(1);
    shift1 = access.FUN_00a62230(1);
    b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 1)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits1 = 8 - b;
    mask[2] = access.GetMask(2);
    shift2 = access.FUN_00a62230(2);
    b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 2)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits2 = 8 - b;
    mask[3] = access.GetMask(3);
    shift3 = access.FUN_00a62230(3);
    b = 0;
    for (unsigned int i = 0; i < 4; ++i)
    {
        if (f.data[4 + i * 3] == 3)
        {
            b = (unsigned char)f.data[6 + i * 3];
            break;
        }
    }
    bits3 = 8 - b;
}

template <int C> static inline unsigned char Expand(unsigned int raw, const ChannelInfo& ci)
{
    const unsigned char& bits = C == 0 ? ci.bits0 : C == 1 ? ci.bits1 : C == 2 ? ci.bits2 : ci.bits3;
    unsigned char shift = C == 0 ? ci.shift0 : C == 1 ? ci.shift1 : C == 2 ? ci.shift2 : ci.shift3;
    unsigned int v = (raw & ci.mask[C]) >> shift;
    unsigned int acc = 0;
    unsigned char rem = bits;
    unsigned char sh = 8 - bits;
    while (sh <= rem)
    {
        acc |= v;
        acc <<= sh;
        rem -= sh;
    }
    acc >>= sh;
    acc |= v >> ((8 - bits) - rem);
    v <<= bits;
    return (unsigned char)(v | acc);
}

// Reads packed pixel data from stream into buf, expands each channel via ChannelInfo, and writes RGBA or RGB bytes into data->m_pucPixels for the given mip and face.
// @fnv 0x00a8cc40
// src: XBOX_PDB 0x00a8cc40
void __cdecl NiDDSReader_Read16Bit(NiBinaryStream* stream, NiPixelData* apPixelData, NiPixelFormat srcFmt, NiPixelFormat dstFmt,
                          unsigned int mip, unsigned int face)
{
    unsigned char* dst =
        apPixelData->m_pucPixels + apPixelData->m_puiOffsetInBytes[mip] + apPixelData->m_puiOffsetInBytes[apPixelData->m_uiMipmapLevels] * face;
    unsigned int total = apPixelData->m_puiHeight[mip] * apPixelData->m_puiWidth[mip] * 2;
    ChannelInfo ci(srcFmt);
    unsigned short buf[256];
    for (unsigned int done = 0; done < total;)
    {
        unsigned int uiChunkBytes = 0x200;
        if (total - done < 0x200)
            uiChunkBytes = total - done;
        stream->Read(buf, uiChunkBytes);
        if (dstFmt == DAT_011aa2a0)
        {
            unsigned short* p = buf;
            for (unsigned int i = 0; i < (uiChunkBytes >> 1); i++)
            {
                *dst++ = Expand<0>(*p, ci);
                *dst++ = Expand<1>(*p, ci);
                *dst++ = Expand<2>(*p, ci);
                *dst++ = Expand<3>(*p, ci);
                p++;
            }
        }
        else if (dstFmt == DAT_011aa2e8)
        {
            unsigned short* p = buf;
            for (unsigned int i = 0; i < (uiChunkBytes >> 1); i++)
            {
                *dst++ = Expand<0>(*p, ci);
                *dst++ = Expand<1>(*p, ci);
                *dst++ = Expand<2>(*p, ci);
                p++;
            }
        }
        else
            return;
        done += uiChunkBytes;
    }
}
}  // namespace fnv_00a8cc40
