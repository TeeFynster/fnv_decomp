
// src/gamebryo2.2/corelibs/nisystem/nimemstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/nimemstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiMemStream.h"

// @fnv 0x00aa2d70
// src: GAMEBRYO_LIB 0x00aa2d70
void __thiscall NiMemStream::Seek_00aa2d70(int iNumBytes)
{
    int iValue = m_pos + iNumBytes;
    if (iValue >= 0 && iValue < m_uiSize)
    {
        m_pos = (unsigned int)iValue;
        m_uiAbsoluteCurrentPos = (unsigned int)iValue;
    }
}

void* __cdecl _NiMalloc(unsigned int size);
void __cdecl _NiFreeAlias(void* p);
void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

// @fnv 0x00aa2dd0
// src: COMMUNITY 0x00aa2dd0
unsigned int __thiscall NiMemStream::MemWrite(const void* data, unsigned int numBytes)
{
    if (m_bFlag20)
        return 0;

    unsigned int freeSpace = m_uiSize - m_pos;
    if (numBytes > freeSpace)
    {
        unsigned int oldEnd = m_uiSize;
        unsigned int newSize;
        if (numBytes <= oldEnd + freeSpace)
            newSize = oldEnd * 2;
        else
            newSize = (oldEnd - freeSpace) + numBytes;

        void* newBuffer = _NiMalloc(newSize);
        _memmove(newBuffer, m_kRayStart, m_kRayEnd);
        _NiFreeAlias(m_kRayStart);
        m_kRayStart = (char*)newBuffer;
        m_uiSize = newSize;
    }

    _memmove(m_kRayStart + m_pos, data, numBytes);
    m_pos += numBytes;
    if (m_pos > m_kRayEnd)
        m_kRayEnd = m_pos;

    return numBytes;
}

namespace fnv_00aa2e60 {
extern "C" void* __cdecl _memmove(void* dest, const void* src, unsigned int size);

// Copies up to count bytes from the stream's buffer at m_pos into dest, advances m_pos, and returns the number of bytes copied.
// @fnv 0x00aa2e60
// src: COMMUNITY 0x00aa2e60
unsigned int NiMemStream_ReadNoSwap(NiMemStream* stream, void* dest, unsigned int count)
{
    unsigned int available = stream->m_kRayEnd - stream->m_pos;
    if (count > available)
        count = available;
    _memmove(dest, stream->m_kRayStart + stream->m_pos, count);
    stream->m_pos += count;
    return count;
}
}  // namespace fnv_00aa2e60

int __cdecl SwapBufferBySizes(void*, unsigned int, void*, void*);
// Copies up to uLen bytes from the stream's buffer at its current position into pData, advances the position, and calls SwapBufferBySizes on the data.
// @fnv 0x00aa2ec0
// src: COMMUNITY 0x00aa2ec0
unsigned int __cdecl NiMemStream_ReadAndSwap(NiMemStream* pStream, void* apBuffer, unsigned int auiLength, void* apArgA,
                                  void* apArgB)
{
    if (auiLength <= 0)
        return 0;
    unsigned int uiPosition = pStream->m_pos;
    unsigned int uiAvailable = pStream->m_kRayEnd - uiPosition;
    unsigned int uiCopied = auiLength;
    if (uiCopied > uiAvailable)
        uiCopied = uiAvailable;
    char* pBufferBase = pStream->m_kRayStart;
    _memmove(apBuffer, pBufferBase + uiPosition, uiCopied);
    pStream->m_pos += uiCopied;
    SwapBufferBySizes(apBuffer, auiLength, apArgA, apArgB);
    return uiCopied;
}

// Copies uSize bytes from pSrc into a temporary buffer, passes it to SwapBufferBySizes, writes it to pStream, frees the buffer and returns the write result.
// @fnv 0x00aa2f20
// src: COMMUNITY 0x00aa2f20
unsigned int __cdecl NiMemStream_WriteAndSwap(NiMemStream* pStream, const void* pSrc, unsigned int uSize, void* pA, void* pB)
{
    if (uSize <= 0)
        return 0;
    void* pBuffer = _NiMalloc(uSize);
    _memmove(pBuffer, pSrc, uSize);
    SwapBufferBySizes(pBuffer, uSize, pA, pB);
    unsigned int uRet = pStream->MemWrite(pBuffer, uSize);
    _NiFreeAlias(pBuffer);
    return uRet;
}

namespace fnv_00aa2f80 {
extern "C" void __cdecl NiMemStream_ReadNoSwap(void*);
extern "C" void __cdecl NiMemStream_WriteNoSwap(void*);
extern "C" void __cdecl NiMemStream_ReadAndSwap(void*);
extern "C" void __cdecl NiMemStream_WriteAndSwap(void*);

}  // namespace fnv_00aa2f80

// Assigns the read and write function pointers based on bDoSwap, choosing one pair of handlers or the other.
// @fnv 0x00aa2f80
void NiMemStream::SetSwapMode(bool bDoSwap)
{
    using namespace fnv_00aa2f80;
    if (bDoSwap)
    {
        m_pfnRead = (NIBINARYSTREAM_READFN)(void(__cdecl*)(void*))NiMemStream_ReadAndSwap;
        m_pfnWrite = (NIBINARYSTREAM_WRITEFN)(void(__cdecl*)(void*))NiMemStream_WriteAndSwap;
    }
    else
    {
        m_pfnRead = (NIBINARYSTREAM_READFN)(void(__cdecl*)(void*))NiMemStream_ReadNoSwap;
        m_pfnWrite = (NIBINARYSTREAM_WRITEFN)(void(__cdecl*)(void*))NiMemStream_WriteNoSwap;
    }
}

// @fnv 0x00aa2ea0
// src: COMMUNITY 0x00aa2ea0
void __cdecl NiMemStream_WriteNoSwap(NiMemStream* pThis, const void* pData, unsigned int uLen)
{
    pThis->MemWrite(pData, uLen);
}

struct NiAlloc
{
    void __thiscall MemoryManager_Deallocate(void* ptr);
};
extern NiAlloc DAT_011f6238;
void __cdecl _NiFree_00aa10f0(void* ptr);

extern void* NiMemStream_vftable[];

// Scalar deleting destructor: release the owned buffer, destroy the base, and optionally free the stream.
// @fnv 0x00aa2d90
void* __fastcall DestroyNiMemStream(NiMemStream* stream, void*, unsigned int flags)
{
    *(void***)stream = NiMemStream_vftable;
    if (!stream->m_bFlag20 && !stream->m_bFlag21)
    {
        _NiFree_00aa10f0(stream->m_kRayStart);
    }
    stream->NiBinaryStream::~NiBinaryStream();
    if (flags & 1)
        DAT_011f6238.MemoryManager_Deallocate(stream);
    return stream;
}
