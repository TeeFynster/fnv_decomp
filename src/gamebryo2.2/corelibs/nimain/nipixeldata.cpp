// gamebryo2.2/corelibs/nimain/nipixeldata.cpp: NiPixelData (13 functions)

#include "../../../../include/NiPixelData.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiPalettePointer.h"
#include "../../../../include/StrArr.h"


extern "C" void* __cdecl fnv_zlib_memcpy(void* destination, const void* source, unsigned int size);

__forceinline bool pixelCompressed(int f)
{
    if (f < 4)
        return false;
    if (f > 6)
        return false;
    return true;
}

// Initializes pixel format, mipmap levels, faces, per-level widths/heights/offsets, allocates data and copies the level tables.
// @fnv 0x00a7c190
NiPixelData::NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format,
                         unsigned int mipmapLevels, unsigned int faces) throw()
{
    m_bOwnsPixelData = false;
    m_kPixelFormat = format;

    if (mipmapLevels == 0)
        m_uiMipmapLevels = CalculateMipmapLevels(width, height);
    else
        m_uiMipmapLevels = mipmapLevels;
    m_uiFaces = faces;

    unsigned int offsets[16];
    unsigned int widths[16];
    unsigned int heights[16];
    offsets[0] = 0;

    if (!pixelCompressed(format.unk04))
    {
        m_uiPixelStride = reinterpret_cast<const unsigned char*>(&format.unk00)[1] >> 3;
        if (m_uiPixelStride != 0)
        {
            for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
            {
                unsigned int levelWidth = width ? width : 1;
                widths[level] = levelWidth;
                unsigned int levelHeight = height ? height : 1;
                heights[level] = levelHeight;
                offsets[level + 1] = offsets[level] + levelWidth * levelHeight * m_uiPixelStride;
                width >>= 1;
                height >>= 1;
            }
        }
        else
        {
            for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
            {
                unsigned int levelWidth = width ? width : 1;
                widths[level] = levelWidth;
                unsigned int levelHeight = height ? height : 1;
                heights[level] = levelHeight;
                offsets[level + 1] = offsets[level] + ((levelWidth * levelHeight) >> 1);
                width >>= 1;
                height >>= 1;
            }
        }
    }
    else
    {
        m_uiPixelStride = 0;
        unsigned int blockSize = format.unk04 == 4 ? 8 : 16;
        for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
        {
            unsigned int levelWidth = width ? width : 1;
            widths[level] = levelWidth;
            unsigned int levelHeight = height ? height : 1;
            heights[level] = levelHeight;
            unsigned int blockWidth = (levelWidth + 3) & ~3u;
            unsigned int blockHeight = (levelHeight + 3) & ~3u;
            offsets[level + 1] = offsets[level] + ((blockWidth * blockHeight) >> 4) * blockSize;
            width >>= 1;
            height >>= 1;
        }
    }

    AllocateData(m_uiMipmapLevels, faces, offsets[m_uiMipmapLevels]);
    unsigned int uiTableBytes = m_uiMipmapLevels * sizeof(unsigned int);
    fnv_zlib_memcpy(m_puiWidth, widths, uiTableBytes);
    fnv_zlib_memcpy(m_puiHeight, heights, uiTableBytes);
    fnv_zlib_memcpy(m_puiOffsetInBytes, offsets, (m_uiMipmapLevels + 1) * sizeof(unsigned int));
    m_uiRevID = 1;
}

#include "../../../../include/NiMemObject.h"

void __fastcall ReleaseSpawnedRefs(void*);

// @fnv 0x00a7c450
void* __fastcall FUN_00a7c450(void* pThis, int, unsigned int flags)
{
    ReleaseSpawnedRefs(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, 0x74);
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f4a90;
// @fnv 0x00a7c020
const NiRTTI* NiPixelData::GetRTTI() const
{
    return reinterpret_cast<const NiRTTI*>(&g_011f4a90);
}


// @fnv 0x00a7bee0
bool NiPixelData::RegisterStreamables(NiStream& stream)
{
    bool ok = NiObject::RegisterStreamables(stream);
    if (!ok)
    {
        return ok;
    }
    NiPalette* target = static_cast<NiPalette*>(m_spPalette.value);
    if (target != 0)
    {
        target->RegisterStreamables(stream);
    }
    return true;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

extern int DAT_0109dbb4;
// Constructor entry points used by the default and copy initialization paths.
struct NiObjectInitialization
{
    void Construct() throw();
};
struct NiPixelFormatInitialization
{
    void Construct() throw();
};

static __forceinline void InitializePixelData(NiPixelData* data)
{
    reinterpret_cast<NiObjectInitialization*>(data)->Construct();
    *reinterpret_cast<void**>(data) = &DAT_0109dbb4;
    reinterpret_cast<NiPixelFormatInitialization*>(&data->m_kPixelFormat)->Construct();
    data->m_spPalette.value = 0;
}

// Allocates and initializes the default pixel data object.
// @fnv 0x00a7c3f0
void* __cdecl CreateSpawnedPixelData()
{
    NiPixelData* data = static_cast<NiPixelData*>(Object_DispatchCommandFour(sizeof(NiPixelData)));
    if (data)
    {
        InitializePixelData(data);
        data->m_pucPixels = 0;
        data->m_puiWidth = 0;
        data->m_puiHeight = 0;
        data->m_puiOffsetInBytes = 0;
        data->m_uiMipmapLevels = 0;
        data->m_uiFaces = 0;
        data->m_uiPixelStride = 0;
        data->m_uiRevID = 1;
        return data;
    }
    return 0;
}

struct NiStreamTransfer
{
    void* unk00;
    unsigned int bytesTransferred;
    void* unk08;
    unsigned int(__cdecl* transfer)(NiStreamTransfer*, const void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void TransferData(const void* bytes, unsigned int count, unsigned int initialCount)
    {
        unsigned int bytesTransferred = initialCount;
        this->bytesTransferred += transfer(this, bytes, count, &bytesTransferred, 1);
    }
};

static __forceinline void TransferData(NiStream* stream, const void* bytes, unsigned int count,
                                       unsigned int initialCount = 4)
{
    NiStreamTransfer* io = *reinterpret_cast<NiStreamTransfer**>(reinterpret_cast<char*>(stream) + 0x250);
    io->TransferData(bytes, count, initialCount);
}

// Serializes the pixel format, palette, mipmap level/stride/width/height/offset arrays, face count and pixel data through the stream.
// @fnv 0x00a7c670
void NiPixelData::SaveBinary(NiStream& kStream)
{
    NiStream* stream = &kStream;
    // The original uses the empty base hook at 0x00a89af0.
    NiObject::LinkObject(*stream);
    m_kPixelFormat.SaveBinary(stream);
    stream->SaveLinkID(reinterpret_cast<const NiObject*>(m_spPalette.value));

    TransferData(stream, &m_uiMipmapLevels, sizeof(m_uiMipmapLevels));
    TransferData(stream, &m_uiPixelStride, sizeof(m_uiPixelStride));

    for (unsigned int level = 0; level < m_uiMipmapLevels; ++level)
    {
        TransferData(stream, &m_puiWidth[level], sizeof(unsigned int));
        TransferData(stream, &m_puiHeight[level], sizeof(unsigned int));
        TransferData(stream, &m_puiOffsetInBytes[level], sizeof(unsigned int));
    }

    TransferData(stream, &m_puiOffsetInBytes[m_uiMipmapLevels], sizeof(unsigned int));
    TransferData(stream, &m_uiFaces, sizeof(m_uiFaces));
    const void* pixels = m_pucPixels;
    unsigned int pixelBytes = m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces;
    TransferData(stream, pixels, pixelBytes, 1);
}

struct NiBinaryStreamLoad
{
    void* unk00;
    unsigned int bytesTransferred;
    unsigned int(__cdecl* transfer)(NiBinaryStreamLoad*, void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void Read(void* bytes, unsigned int count, unsigned int initialCount)
    {
        unsigned int done = initialCount;
        unsigned int transferred = transfer(this, bytes, count, &done, 1);
        bytesTransferred += transferred;
    }
};

// The shared stream header leaves the original fields opaque.
inline unsigned int NiStream::GetFileVersion() const
{
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 0xd8);
}

__forceinline void NiStream::Read(void* bytes, unsigned int count, unsigned int initialCount)
{
    NiBinaryStreamLoad* io = *reinterpret_cast<NiBinaryStreamLoad**>(reinterpret_cast<char*>(this) + 0x24c);
    io->Read(bytes, count, initialCount);
}

template <class T> static __forceinline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.Read(&value, sizeof(T), sizeof(T));
}

// Loads pixel format, mipmap levels, per-mipmap width/height/offset, faces and pixel data from the stream, then allocates and copies them.
// @fnv 0x00a7c470
void NiPixelData::LoadBinary(NiStream& kStream)
{
    NiStream& stream = kStream;
    NiObject::LoadBinary(stream);
    m_kPixelFormat.LoadBinary(&stream);
    stream.ReadLinkIDStub();

    unsigned int auiOffsetInBytes[16];
    unsigned int auiWidth[16];
    unsigned int auiHeight[16];

    ReadBinaryValue(stream, m_uiMipmapLevels);
    ReadBinaryValue(stream, m_uiPixelStride);
    unsigned int i;
    for (i = 0; i < m_uiMipmapLevels; i++)
    {
        ReadBinaryValue(stream, auiWidth[i]);
        ReadBinaryValue(stream, auiHeight[i]);
        ReadBinaryValue(stream, auiOffsetInBytes[i]);
    }
    ReadBinaryValue(stream, *(auiOffsetInBytes + m_uiMipmapLevels));

    if (stream.GetFileVersion() < 0x0A030006)
        m_uiFaces = 1;
    else
        ReadBinaryValue(stream, m_uiFaces);

    AllocateData(m_uiMipmapLevels, m_uiFaces, auiOffsetInBytes[m_uiMipmapLevels]);

    unsigned int uiMipmapArrayBytes = m_uiMipmapLevels * sizeof(unsigned int);
    fnv_zlib_memcpy(m_puiWidth, auiWidth, uiMipmapArrayBytes);
    fnv_zlib_memcpy(m_puiHeight, auiHeight, uiMipmapArrayBytes);
    fnv_zlib_memcpy(m_puiOffsetInBytes, auiOffsetInBytes, (m_uiMipmapLevels + 1) * sizeof(unsigned int));

    unsigned char* pixels = m_pucPixels;
    stream.Read(pixels, m_puiOffsetInBytes[m_uiMipmapLevels] * m_uiFaces, 1);
}

char* __cdecl NiViewerStrings_NiGetViewerString_Title(char* pcText);
char* __cdecl NiGetViewerString_00a7d510(const char* pcName, unsigned int uiValue);
inline void StrArr::AppendReference(char*& element)
{
    unsigned int uiIndex = m_usSize;
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
}

struct Base00a5d6e0
{
    void AppendCameraPathEntries(StrArr* pkStrings);
};
inline unsigned int PixelFaceSize(const NiPixelData* p)
{
    return p->m_puiOffsetInBytes[p->m_uiMipmapLevels];
}
inline unsigned int PixelTotalSize(const NiPixelData* p)
{
    return p->m_puiOffsetInBytes[p->m_uiMipmapLevels] * p->m_uiFaces;
}
// Appends the base debug strings plus Width, Height, mipmap level, face count, total and per-face byte sizes to pkStrings.
// @fnv 0x00a7c820
void NiPixelData::GetViewerStrings(NiViewerStringsArray* strings)
{
    StrArr* pkStrings = reinterpret_cast<StrArr*>(strings);
    ((Base00a5d6e0*)this)->AppendCameraPathEntries(pkStrings);
    char* pcString = NiViewerStrings_NiGetViewerString_Title(*(char**)&g_011f4a90);
    pkStrings->AppendReference(pcString);
    pcString = NiGetViewerString_00a7d510("Width", GetWidth());
    pkStrings->AppendReference(pcString);
    pcString = NiGetViewerString_00a7d510("Height", GetHeight());
    pkStrings->AppendReference(pcString);
    pcString = NiGetViewerString_00a7d510("m_uiMipmapLevels", m_uiMipmapLevels);
    pkStrings->AppendReference(pcString);
    pcString = NiGetViewerString_00a7d510("m_uiFaces", m_uiFaces);
    pkStrings->AppendReference(pcString);
    pcString = NiGetViewerString_00a7d510("TotalSizeInBytes", PixelTotalSize(this));
    pkStrings->AppendReference(pcString);
    pcString = NiGetViewerString_00a7d510("FaceSizeInBytes", PixelFaceSize(this));
    pkStrings->AppendReference(pcString);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
struct RendererDataBase_s
{
    void LinkObject(NiStream& kStream);
};
inline void DecRefCount(NiObject* pkObject)
{
    if (InterlockedDecrement((long volatile*)&pkObject->m_uiRefCount) == 0)
        pkObject->DeleteThis();
}
static __forceinline void AssignPalette(NiPalettePointer& palette, NiObject* object)
{
    if (palette.value != object)
    {
        if (palette.value)
            DecRefCount(static_cast<NiObject*>(palette.value));
        palette.value = object;
        if (palette.value)
            InterlockedIncrement((long volatile*)&static_cast<NiObject*>(palette.value)->m_uiRefCount);
    }
}
// Calls the base LinkObject on kStream, then loads m_spPalette from the stream.
// @fnv 0x00a7be80
void NiPixelData::LinkObject(NiStream& kStream)
{
    reinterpret_cast<RendererDataBase_s*>(this)->LinkObject(kStream);
    AssignPalette(m_spPalette, kStream.FUN_00a63430());
}


void __fastcall FreePixelDataBuffers(NiPixelData* data);
void __fastcall TeardownPixelDataBase(NiObject* data);

// Releases the palette before and after freeing the pixel buffers, then tears down the base object.
// @fnv 0x00a7c390
void __fastcall ReleaseSpawnedRefs(void* object)
{
    NiPixelData* data = static_cast<NiPixelData*>(object);
    *(void* volatile*)data = (void*)&DAT_0109dbb4;
    NiPalette* first = *(NiPalette* volatile*)&data->m_spPalette.value;
    if (first != 0)
    {
        if (InterlockedDecrement((long volatile*)&first->m_uiRefCount) == 0)
        {
            first->DeleteThis();
        }
        data->m_spPalette.value = 0;
    }
    FreePixelDataBuffers(data);
    NiPalette* second = static_cast<NiPalette*>(data->m_spPalette.value);
    if (second != 0)
    {
        if (InterlockedDecrement((long volatile*)&second->m_uiRefCount) == 0)
        {
            second->DeleteThis();
        }
    }
    TeardownPixelDataBase(data);
}

static inline unsigned int Levels(unsigned int v)
{
    unsigned int l = 1;
    while (v >>= 1)
        ++l;
    return l;
}
// Returns the number of mip levels for a texture of the given width and height, or 0 if either dimension is zero.
// @fnv 0x00a7be30
unsigned int NiPixelData::CalculateMipmapLevels(unsigned int width, unsigned int height)
{
    if (!width || !height)
        return 0;
    unsigned int iWidthLevels = 1;
    while (width >>= 1)
        ++iWidthLevels;
    unsigned int iHeightLevels = Levels(height);
    unsigned int r = iWidthLevels;
    if (iHeightLevels >= iWidthLevels)
        r = iHeightLevels;
    return r;
}

#include <string.h>

// Compares pixel format, palette, mipmap dimensions, face count, and pixel data of two NiPixelData objects, returning true only if all match.
// @fnv 0x00a7bf10
bool NiPixelData::IsEqual(NiObject* pkObject) const
{
    if (!const_cast<NiPixelData*>(this)->NiObject::IsEqual(pkObject))
        return false;

    NiPixelData* pkPD = (NiPixelData*)pkObject;

    if (m_kPixelFormat != pkPD->m_kPixelFormat)
        return false;

    const NiPalette* pkPalette = (const NiPalette*)m_spPalette.value;
    if (pkPalette)
    {
        NiObject* pkOther = (NiObject*)pkPD->m_spPalette.value;
        if (!pkPalette->IsEqual(pkOther))
            return false;
    }

    if (m_uiMipmapLevels != pkPD->m_uiMipmapLevels || m_uiPixelStride != pkPD->m_uiPixelStride)
        return false;

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        if (m_puiWidth[i] != pkPD->m_puiWidth[i] || m_puiHeight[i] != pkPD->m_puiHeight[i] ||
            m_puiOffsetInBytes[i] != pkPD->m_puiOffsetInBytes[i])
            return false;
    }

    if (m_puiOffsetInBytes[m_uiMipmapLevels] != pkPD->m_puiOffsetInBytes[m_uiMipmapLevels])
        return false;

    if (m_uiFaces != pkPD->m_uiFaces)
        return false;

    if (memcmp(m_pucPixels, pkPD->m_pucPixels, m_puiOffsetInBytes[m_uiMipmapLevels]) != 0)
        return false;

    return true;
}

#include <windows.h>
inline void NiPalette::IncRefCount()
{
    InterlockedIncrement((LONG*)&m_uiRefCount);
}

inline void NiPalette::DecRefCount()
{
    if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
        DeleteThis();
}

class NiPalettePtr
{
  public:
    NiPalette* m_pObject;
    NiPalettePtr() throw() : m_pObject(0)
    {}
    NiPalette* operator->() const
    {
        return m_pObject;
    }
    NiPalette& operator*() const
    {
        return *m_pObject;
    }
    operator NiPalette*() const
    {
        return m_pObject;
    }
    NiPalettePtr& operator=(NiPalette* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

// @fnv 0x00a7c030
// src: EXE 0x00a7c030
NiPixelData* NiPixelData::NiPixelData_00a7c030(const NiPixelData& kSrc)
{
    reinterpret_cast<NiObjectInitialization*>(this)->Construct();
    *reinterpret_cast<void**>(this) = &DAT_0109dbb4;
    reinterpret_cast<NiPixelFormatInitialization*>(&m_kPixelFormat)->Construct();
    m_spPalette = NiPalettePointer();
    m_bOwnsPixelData = false;
    m_kPixelFormat = kSrc.m_kPixelFormat;
    if (reinterpret_cast<const NiPalettePtr&>(kSrc.m_spPalette))
        reinterpret_cast<NiPalettePtr&>(m_spPalette) = new NiPalette(*reinterpret_cast<const NiPalettePtr&>(kSrc.m_spPalette));

    m_uiMipmapLevels = kSrc.m_uiMipmapLevels;
    m_uiFaces = kSrc.m_uiFaces;
    m_uiPixelStride = kSrc.m_uiPixelStride;

    unsigned int auiWidth[16];
    unsigned int auiHeight[16];
    unsigned int auiOffsetInBytes[16];

    for (unsigned int i = 0; i < m_uiMipmapLevels; i++)
    {
        auiWidth[i] = kSrc.m_puiWidth[i];
        auiHeight[i] = kSrc.m_puiHeight[i];
        auiOffsetInBytes[i] = kSrc.m_puiOffsetInBytes[i];
    }
    unsigned int uiTotalBytes = kSrc.m_puiOffsetInBytes[m_uiMipmapLevels];
    auiOffsetInBytes[m_uiMipmapLevels] = uiTotalBytes;

    AllocateData(m_uiMipmapLevels, m_uiFaces, uiTotalBytes);

    unsigned int uiDimBytes = sizeof(unsigned int) * m_uiMipmapLevels;
    memcpy(m_puiWidth, auiWidth, uiDimBytes);
    memcpy(m_puiHeight, auiHeight, uiDimBytes);
    memcpy(m_puiOffsetInBytes, auiOffsetInBytes, sizeof(unsigned int) * (m_uiMipmapLevels + 1));
    memcpy(m_pucPixels, kSrc.m_pucPixels, uiTotalBytes);
    m_uiRevID = 1;
    return this;
}
