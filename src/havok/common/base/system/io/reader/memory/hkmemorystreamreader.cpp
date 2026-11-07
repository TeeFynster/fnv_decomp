
// src/havok/common/base/system/io/reader/memory/hkmemorystreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/memory/hkmemorystreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkMemoryRouter.h"

// hkMemoryRouter is the shared router layout: TLS accessor 0x00c85750, heap at +0x10.


struct FUN_00e059e0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int __thiscall GetCurrentOffset();
};

// @fnv 0x00e059e0
int __thiscall FUN_00e059e0::GetCurrentOffset()
{
    if (m_14 >= 0)
    {
        m_0c = m_14;
        return 0;
    }
    return 1;
}

struct hkMemoryStreamReader
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    unsigned char* __thiscall IsSupported(unsigned char* supported);
};

// @fnv 0x00e059c0
unsigned char* __thiscall hkMemoryStreamReader::IsSupported(unsigned char* supported)
{
    *supported = (m_10 != 0);
    return supported;
}

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00e05bf0Class : hkMemoryStreamReader
{
    void __thiscall FUN_00e05bb0();
    hkMemoryStreamReader* __thiscall FUN_00e05bf0(int flags);
};

hkMemoryStreamReader* __thiscall FUN_00e05bf0Class::FUN_00e05bf0(int flags)
{
    FUN_00e05bb0();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->heap().blockFree(this, (unsigned short)m_04);
    }

    return this;
}

struct FUN_00e059d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int unk10;
    int m_14;
    unsigned char* hkMemoryStreamReader_setMark(unsigned char* supported);
};

// @fnv 0x00e059d0
// src: HAVOK_LIB 0x00e059d0
unsigned char* FUN_00e059d0_cls::hkMemoryStreamReader_setMark(unsigned char* supported)
{
    m_14 = m_0c;
    return 0;
}

// FUN_00e05a00: sets the flag byte pointed to by the argument to 1 and returns the argument.
// @fnv 0x00e05a00
// src: HAVOK_SRC 0x00e05a00
unsigned char* __stdcall hkMemoryStreamReader_seekTellSupported(unsigned char* supported)
{
    *supported = 1;
    return supported;
}

// The stream's end/current integers are at +0x0c/+0x10; this is a stream state view.
class MemoryStreamEndState
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iEnd;
    int m_iCurrent;

    hkBool IsNotAtEnd() const;
};

// @fnv 0x00e059a0
hkBool MemoryStreamEndState::IsNotAtEnd() const
{
    return m_iEnd != m_iCurrent + 1;
}

struct FUN_00e05a10_cls : hkMemoryStreamReader
{
    int __thiscall hkMemoryStreamReader_seek(int arg4, int mode);
};
// Computes a new stream position from arg4 and mode, clamps it to [0, m_10], stores it in m_0c and returns whether clamping occurred.
// @fnv 0x00e05a10
// src: HAVOK_LIB 0x00e05a10
int __thiscall FUN_00e05a10_cls::hkMemoryStreamReader_seek(int aiOffset, int mode)
{
    int edx = -1;
    switch (mode)
    {
    case 0:
        edx = aiOffset;
        break;
    case 1:
        edx = m_0c + aiOffset;
        break;
    case 2:
        edx = m_10 - aiOffset;
        break;
    }
    int result = 0;
    if (edx < 0)
    {
        edx = 0;
        result = edx + 1;
    }
    else
    {
        int esi = m_10;
        if (edx > esi)
        {
            edx = esi;
            result = 1;
        }
    }
    m_0c = edx;
    return result;
}

struct FnvCpu_FUN_00e05a70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int value;
    int GetValue();
};
// @fnv 0x00e05a70
// src: GUESS 0x00e05a70 (confidence: low)
int FnvCpu_FUN_00e05a70_CpuObject::GetValue()
{
    return value;
}

struct FUN_00e05a80Class
{
    virtual void first();
    virtual void second();
    virtual void third();
    virtual unsigned char* checkState(unsigned char* state);

    int m_04;
    unsigned char* m_08;
    int m_0c;
    int m_10;

    int __thiscall ReadFromBuffer(void* destination, int count);
};
extern "C" void __cdecl hkString_memCpy(void* destination, const void* source, int count);

// @fnv 0x00e05a80
int __thiscall FUN_00e05a80Class::ReadFromBuffer(void* destination, int count)
{
    unsigned char state;
    if (*checkState(&state))
    {
        int remaining = m_10 - m_0c;
        int copied = count < remaining ? count : remaining;
        hkString_memCpy(destination, m_08 + m_0c, copied);
        m_0c += copied;
        if (copied == 0 && count != 0)
            m_0c = m_10 + 1;
        return copied;
    }
    return 0;
}

struct FUN_00e05af0_Obj : hkMemoryStreamReader
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual unsigned char* IsNotAtEnd(unsigned char* value);
    virtual void vf10();
    virtual int ReadBytes(int value);
};

// @fnv 0x00e05af0
int __thiscall FUN_00e05af0_Obj::ReadBytes(int aiByteCount)
{
    int local;
    unsigned char* result = IsNotAtEnd(((unsigned char*)&local) + 3);

    if (*result != 0)
    {
        int count = m_0c - m_08;

        if (aiByteCount < count)
            count = aiByteCount;

        m_08 += count;

        if (count == 0 && aiByteCount != 0)
            m_08 = m_0c + 1;

        return count;
    }

    return 0;
}

namespace hkRouterE05B {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void* __cdecl AllocateWithHeader(hkMemoryAllocator& kAlloc, int iNumBytes) throw();
void __cdecl hkString_memCpy(void* pvDst, const void* pvSrc, int iNumBytes) throw();

class FUN_00e05b40 : public hkReferencedObject
{
  public:
    void* m_data;
    int unk0C;
    int m_iElementCount;
    int unk14;
    int m_external;

    FUN_00e05b40(void* data, int size, int external) throw();
    virtual ~FUN_00e05b40() throw();
};

// Stores size and external flag; if not external, allocates size bytes from the router heap and copies data into it, otherwise keeps the data pointer.
// @fnv 0x00e05b40
FUN_00e05b40::FUN_00e05b40(void* data, int size, int external) throw()
{
    unk0C = 0;
    m_iElementCount = size;
    unk14 = -1;
    m_external = external;
    if (!external)
    {
        m_data = AllocateWithHeader(hkRouterE05B::hkMemoryRouter_getInstance().heap(), size);
        hkString_memCpy(m_data, data, size);
    }
    else
    {
        m_data = data;
    }
}

namespace fnv_00e05bb0 {
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkMemoryRouter_easyFree(hkMemoryAllocator* pAllocator, void* p) throw();

inline void hkDeallocateE05B(void* p)
{
    hkMemoryRouter* r = hkMemoryRouter_getInstance();
    hkMemoryRouter_easyFree(r->m_heap, p);
}

// The data pointer at +0x08 and ownership flag at +0x18 belong to the memory stream.
class MemoryStreamStorage : public hkReferencedObject
{
  public:
    void* m_data;
    int unk0C;
    int unk10;
    int unk14;
    int m_iValueAfterFlags;

    virtual ~MemoryStreamStorage() throw()
    {
        if (m_iValueAfterFlags == 0 || m_iValueAfterFlags == 1)
            hkDeallocateE05B(m_data);
    }

    void FUN_00e05bb0();
};

// @fnv 0x00e05bb0
void MemoryStreamStorage::FUN_00e05bb0()
{
    this->MemoryStreamStorage::~MemoryStreamStorage();
}
}  // namespace fnv_00e05bb0
