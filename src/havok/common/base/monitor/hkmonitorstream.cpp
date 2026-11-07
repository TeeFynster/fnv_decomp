
// src/havok/common/base/monitor/hkmonitorstream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/monitor/hkmonitorstream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00cb0da0
{
    int m_00;
    int m_04;
};

// @fnv 0x00cb0da0
// src: XBOX_PDB 0x00cb0da0
void hkMonitorStream_reset(S_00cb0da0* p)
{
    p->m_04 = p->m_00;
}

// ResizeBuffer - grow/shrink a spawned byte buffer through the audio allocator.
//
// The buffer keeps four pointers and a flag:
//   +0x00  m_00  start of the allocation
//   +0x04  m_04  current write position
//   +0x08  m_08  end of the allocation
//   +0x0c  m_0c  end - 0x20 (the reserved tail)
//   +0x10  m_10  "the allocation is live" flag
//
// FUN_00c85750 is hkMemoryRouter::getInstancePtr(); the router's debug allocator
// (+0x14) grows the buffer with bufAlloc (slot 3, in/out size) and releases it
// with bufFree (slot 4).

#include "../../../../../include/hkMemoryAllocator.h"

// hkMemoryRouter (Havok 7.1 Common/Base/Memory/Router/hkMemoryRouter.h): m_stack (3 words), then the temp, heap,
// debug, solver and global allocators and m_userData (0x24 bytes). No shared header has it (the hkMemoryRouter.h
// and hkMemoryRouter.h stand-ins model only part of it).
#include "../../../../../include/hkMemoryRouter.h"

struct SpawnedBuffer
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    unsigned char m_10;
};

hkMemoryRouter* hkMemoryRouter_getInstance();  // hkMemoryRouter::getInstancePtr (TLS slot read)
void hkMonitorStream_quit(SpawnedBuffer* buf);

// @fnv 0x00cb0e50
void ResizeBuffer(SpawnedBuffer* pBuffer, int iSize)
{
    char* begin = pBuffer->m_00;
    char* end = pBuffer->m_08;
    if (iSize == (int)(pBuffer->m_08 - pBuffer->m_00))
    {
        return;
    }
    if (iSize > 0)
    {
        if (begin != 0 && pBuffer->m_10 != 0)
        {
            hkMemoryRouter* h = hkMemoryRouter_getInstance();
            h->m_debug->bufFree(begin, end - begin);
        }
        pBuffer->m_10 = 1;
        hkMemoryRouter* h2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = h2->m_debug;
        {
            int count = iSize;
            char* p = (char*)pAllocator->bufAlloc(count);
            pBuffer->m_00 = p;
            pBuffer->m_04 = p;
            pBuffer->m_08 = p + count;
            pBuffer->m_0c = p + count - 0x20;
        }
    }
    else
    {
        hkMonitorStream_quit(pBuffer);
    }
}

#include <windows.h>
namespace fnv_00cb0db0 {
extern DWORD DAT_0126835c;



hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct SpawnedObject
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    unsigned char m_10;
};

// Allocates a SpawnedObject from the router's debug allocator (blockAlloc), stores it in TLS, and zeroes its fields.
// @fnv 0x00cb0db0
// src: HAVOK_LIB 0x00cb0db0
void __cdecl hkMonitorStream_init()
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc = holder->m_debug;
    SpawnedObject* obj = (SpawnedObject*)alloc->blockAlloc(0x14);
    TlsSetValue(DAT_0126835c, obj);
    obj->m_10 = 0;
    obj->m_00 = 0;
    obj->m_08 = 0;
    obj->m_04 = 0;
    obj->m_0c = 0;
}
}  // namespace fnv_00cb0db0

namespace fnv_00cb0df0 {
extern DWORD DAT_0126835c;



hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct GrowBuffer
{
    char* m_pBegin;
    char* m_pCurrent;
    char* m_pRecordEnd;
    char* m_pReadData;
    char m_bOwned;
};

// Frees the owned record buffer (bufFree) and the TLS block (blockFree) through the debug allocator, then clears the TLS slot.
// @fnv 0x00cb0df0
// src: HAVOK_LIB 0x00cb0df0
void __cdecl hkMonitorStream_quit(GrowBuffer* apBuffer)
{
    void* pThreadData = TlsGetValue(DAT_0126835c);

    char* pBegin = apBuffer->m_pBegin;
    if (pBegin != 0 && apBuffer->m_bOwned != 0)
    {
        char* pEnd = apBuffer->m_pRecordEnd;
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = pHolder->m_debug;
        pAllocator->bufFree(pBegin, (int)(pEnd - pBegin));
    }

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = pHolder2->m_debug;
    pAllocator2->blockFree(pThreadData, 0x14);

    TlsSetValue(DAT_0126835c, 0);
}
}  // namespace fnv_00cb0df0
