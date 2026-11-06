
// src/havok/common/base/container/string/hkstringbuf.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstringbuf.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include <stdarg.h>

BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(void*, void*, int, int);

class BufferOwner
{
  public:
    char* m_pData;
    unsigned int m_iReferenceCount;
    unsigned int m_uiObjectFlags;

    BufferOwner* InitBuffer();
};

// @fnv 0x00cbbd80
BufferOwner* BufferOwner::InitBuffer()
{
    m_pData = (char*)this + 0xc;
    m_iReferenceCount = 0;
    m_uiObjectFlags = 0x80000080;
    hkMemoryRouter* pHolder = reinterpret_cast<hkMemoryRouter*>(FUN_00c85750());
    void* pAllocator = pHolder->m_temp;
    int iCount = (int)(m_uiObjectFlags & 0x3fffffff);
    if (iCount < 1)
    {
        int iCapacity = iCount + iCount;
        if (iCapacity <= 1)
        {
            iCapacity = 1;
        }
        FUN_00c908c0(pAllocator, this, iCapacity, 1);
    }
    m_iReferenceCount = 1;
    *m_pData = 0;
    *m_pData = 0;
    return this;
}

int __cdecl FUN_00cb0f50(char* buf, int size, const char* fmt, va_list args);
inline hkMemoryAllocator& GetStreamAllocator(hkMemoryRouter& router)
{
    return *static_cast<hkMemoryAllocator*>(router.m_temp);
}
struct StringBuf : public BufferOwner
{
    char* Begin()
    {
        return m_pData;
    }
    int GetCapacity() const
    {
        return m_uiObjectFlags & 0x3fffffff;
    }
    void Reserve(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = GetCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, 1);
        }
    }
    void SetSize(int n)
    {
        Reserve(GetStreamAllocator(*reinterpret_cast<hkMemoryRouter*>(FUN_00c85750())), n);
        m_iReferenceCount = n;
    }
    void SetLength(int n)
    {
        SetSize(n + 1);
        m_pData[n] = 0;
    }
    void FUN_00d61d00(const char* fmt, ...);
};
// Formats fmt into the buffer with va_list args, growing capacity until the write fits, then null-terminates.
// @fnv 0x00d61d00
void StringBuf::FUN_00d61d00(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    while (1)
    {
        int size = GetCapacity();
        int iChars = FUN_00cb0f50(Begin(), size, fmt, args);
        if (iChars >= 0 && iChars < size)
        {
            SetLength(iChars);
            break;
        }
        else if (iChars < 0)
        {
            int n = 2 * size;
            SetLength(n > 255 ? n : 255);
        }
        else
        {
            SetLength(iChars);
        }
    }
    va_end(args);
}
