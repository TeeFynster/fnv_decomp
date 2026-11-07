
// src/havok/common/base/system/io/writer/buffered/hkbufferedstreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/buffered/hkbufferedstreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkStreamWriter.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"

// These constructors and destructors were inline in this unit's original Havok implementation.

// The +0x10 allocator and getter at 0x00c85750 match the shared hkMemoryRouter.

struct FUN_00d27260_standin
{
    void* m_unknown00;
    void* m_unknown04;
    void* m_unknown08;
    char* m_buffer;
    int m_vContactPosition;
    int m_kRayEnd;

    int FlushToDestination();
    int hkBufferedStreamWriter_write(const void* data, int size);
};

void _FUN_00cb1260(void* destination, const void* source, unsigned int size);

// @fnv 0x00d27260
// src: HAVOK_LIB 0x00d27260
int __thiscall FUN_00d27260_standin::hkBufferedStreamWriter_write(const void* data, int size)
{
    int remaining = size;
    const char* bytes = static_cast<const char*>(data);
    int available = m_kRayEnd - m_vContactPosition;

    while (remaining > available)
    {
        _FUN_00cb1260(m_buffer + m_vContactPosition, bytes, available);
        m_vContactPosition += available;

        int position = m_vContactPosition;
        bytes += available;
        remaining -= available;

        if (FlushToDestination() != position)
            return size - remaining;

        available = m_kRayEnd - m_vContactPosition;
    }

    _FUN_00cb1260(m_buffer + m_vContactPosition, bytes, remaining);
    m_vContactPosition += remaining;
    return size;
}

struct FUN_00d27420_class
{
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3(const char*, void*, int) = 0;
    virtual void m4() = 0;
    virtual void m5(int, const char*, void*, void*, int) = 0;

    void WriteToStream(FUN_00d27420_class*, int);
};

// Writes the Buffer and stream members to the given stream via its virtual methods.
// @fnv 0x00d27420
void FUN_00d27420_class::WriteToStream(FUN_00d27420_class* stream, int)
{
    stream->m5(1, "Buffer", *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x0c),
               *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x14), 0);

    stream->m3("stream", *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x08), 0);
}

void __cdecl hkBufferedStreamWriter_flush();
hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();
void __cdecl hkMemoryRouter_alignedFree(void*, void*);

extern int DAT_010ce448;
extern int _DAT_0102e388;

struct FUN_00d27520
{
    void* m_vtbl;           // +0x00
    int m_04;               // +0x04
    hkReferencedObject* m_pWorld;  // +0x08
    void* m_pData;          // +0x0c
    int m_10;               // +0x10
    int m_14;               // +0x14
    char m_18;              // +0x18

    ~FUN_00d27520();
};

// @fnv 0x00d27520
FUN_00d27520::~FUN_00d27520()
{
    m_vtbl = &DAT_010ce448;
    hkBufferedStreamWriter_flush();
    if (m_pWorld)
        m_pWorld->removeReference();
    if (m_18)
    {
        void* pData = m_pData;
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        hkMemoryRouter_alignedFree(router->m_heap, pData);
    }
    m_vtbl = &_DAT_0102e388;
}

namespace fnv_00d27570 {
struct FUN_00d27570Writer
{
    void* vftable;
    unsigned short id;

    void FUN_00d27520();
    void* DestroyWriter(unsigned char deletingFlag);
};

// Calls FUN_00d27520, then if deletingFlag has bit 0 set, deallocates this through the memory router using id, and returns this.
// @fnv 0x00d27570
void* FUN_00d27570Writer::DestroyWriter(unsigned char deletingFlag)
{
    FUN_00d27520();

    if (deletingFlag & 1)
    {
        hkMemoryRouter* memoryRouter = _D1A0E0GetMemoryRouter();
        reinterpret_cast<hkMemoryAllocator*>(memoryRouter->m_heap)->blockFree(this, id);
    }

    return this;
}
}  // namespace fnv_00d27570

extern int DAT_012689e4;

// @fnv 0x00d27560
// src: GUESS 0x00d27560 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00d27560()
{
    return &DAT_012689e4;
}

struct StreamBufferD27210
{
    void* unk00;
    void* unk04;
    hkStreamWriter* m_destination;
    char* m_buffer;
    int m_vContactPosition;
    int m_kRayEnd;
    int FlushToDestination();
};
// @fnv 0x00d27210
int StreamBufferD27210::FlushToDestination()
{
    if (m_destination != 0)
    {
        int written = 0;
        int remaining = m_vContactPosition;
        while (written < remaining)
        {
            int count = m_destination->write(m_buffer + written, remaining - written);
            written += count;
            if (count == 0)
                return written;
        }
        m_vContactPosition = 0;
        return written;
    }
    return 0;
}

// Compatibility view: hkStreamWriter.h lacks the void flush() signature at slot 5.
struct StreamWriterFlushView
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void flush();
};

struct FUN_00d272e0_class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}

    int unk04;
    StreamWriterFlushView* unk08;

    void hkBufferedStreamWriter_flush();
};

// @fnv 0x00d272e0
// src: HAVOK_LIB 0x00d272e0
void FUN_00d272e0_class::hkBufferedStreamWriter_flush()
{
    reinterpret_cast<FUN_00d27260_standin*>(this)->FlushToDestination();

    if (unk08 != 0)
    {
        return unk08->flush();
    }
}

// Compatibility view: hkStreamWriter.h lacks the hkBool isOk() signature at slot 3.
class StreamWriterStatusView
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual hkBool isOk();
};

class hkObjD273
{
  public:
    int unk00;
    int unk04;
    StreamWriterStatusView* m_pObservedSource;
    int unk0C;
    int m_10;
    int m_14;

    hkBool GetBool();
};

// @fnv 0x00d27300
hkBool hkObjD273::GetBool()
{
    return m_pObservedSource ? m_pObservedSource->isOk() : hkBool(m_10 != m_14);
}

enum hkResultD273
{
    HK_SUCCESS_D273 = 0,
    HK_FAILURE_D273 = 1
};

// Compatibility view: hkStreamWriter.h lacks seek(int, SeekWhence) at slot 7.
class StreamWriterSeekView
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual hkResultD273 seek(int offset, int whence);
};

class hkBufferedStreamD273
{
  public:
    int unk00;
    int unk04;
    StreamWriterSeekView* m_pChildAtom;
    int unk0C;
    int m_pos;
    int m_iElementCount;

    void FlushToDestination();
    hkResultD273 hkBufferedStreamWriter_seek(int offset, int whence);
};

// @fnv 0x00d27380
// src: HAVOK_LIB 0x00d27380
hkResultD273 hkBufferedStreamD273::hkBufferedStreamWriter_seek(int offset, int whence)
{
    if (m_pChildAtom)
    {
        FlushToDestination();
        return m_pChildAtom->seek(offset, whence);
    }
    int pos = -1;
    switch (whence)
    {
    case 0:
        pos = offset;
        break;
    case 1:
        pos = m_pos + offset;
        break;
    case 2:
        pos = m_pos - offset;
        break;
    }
    hkResultD273 res = HK_SUCCESS_D273;
    if (pos < 0)
    {
        pos = 0;
        res = HK_FAILURE_D273;
    }
    else if (pos > m_iElementCount)
    {
        pos = m_iElementCount;
        res = HK_FAILURE_D273;
    }
    m_pos = pos;
    return res;
}

extern "C" void __cdecl hkString_memSet(void* pvDest, int iValue, int iCount) throw();

class FUN_00d274c0 : public hkReferencedObject
{
  public:
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    char m_overflowed;

    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, char bMemoryIsString) throw();
    virtual ~FUN_00d274c0() throw();
};

// @fnv 0x00d274c0
FUN_00d274c0::FUN_00d274c0(void* pvMem, int aiSize, char bMemoryIsString) throw()
{
    m_offset = 0;
    m_buf = (char*)pvMem;
    m_curSize = 0;
    m_iCapacity = bMemoryIsString ? aiSize - 1 : aiSize;
    m_overflowed = false;
    if (bMemoryIsString)
        hkString_memSet(pvMem, 0, aiSize);
}

// Compatibility view: hkStreamWriter.h lacks hkBool seekTellSupported() const at slot 6.
class StreamWriterSeekSupportView
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual hkBool seekTellSupported() const;
};

class FUN_00d27340_cls
{
  public:
    int unk00, unk04;
    StreamWriterSeekSupportView* m_inner;

    hkBool IsValid() const;
};

// Returns StreamWriterSeekTellSupported(m_inner) when m_inner is non-null, otherwise true.
// @fnv 0x00d27340
hkBool FUN_00d27340_cls::IsValid() const
{
    return m_inner ? m_inner->seekTellSupported() : hkBool(true);
}

// Compatibility view: hkStreamWriter.h lacks int tell() const at slot 8.
class StreamWriterPositionView
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int tell() const;
};

class FUN_00d273f0_cls
{
  public:
    int unk00, unk04;
    StreamWriterPositionView* m_inner;
    int unk0C;
    int m_base;

    int hkBufferedStreamWriter_tell() const;
};

// Returns the wrapped stream position plus buffered bytes, or -1 for an invalid position.
// @fnv 0x00d273f0
// src: HAVOK_LIB 0x00d273f0
int FUN_00d273f0_cls::hkBufferedStreamWriter_tell() const
{
    int n = m_inner ? m_inner->tell() : 0;
    if (n >= 0)
        return m_base + n;
    return -1;
}

namespace hkRouterD274 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
void* __cdecl hkMemoryRouter_alignedAlloc(hkMemoryAllocator& alloc, int iSize, int iAlign) throw();
class hkBufStreamWriterD274 : public hkStreamWriter
{
  public:
    hkBufStreamWriterD274(hkStreamWriter* s, int bufSize) throw();
    virtual ~hkBufStreamWriterD274() throw();
    hkStreamWriter* m_stream;
    char* m_buf;
    int m_iBufferPosition;
    int m_bufSize;
    hkBool m_bIsOk;
};
// Stores s, allocates bufSize bytes with alignment argument 0x40, and initializes the buffer size and position.
// @fnv 0x00d27460
hkBufStreamWriterD274::hkBufStreamWriterD274(hkStreamWriter* apStream, int aiBufferSize) throw()
    : m_stream(apStream), m_bIsOk(true)
{
    if (m_stream)
        m_stream->addReference();
    m_buf = (char*)hkMemoryRouter_alignedAlloc(hkRouterD274::hkMemoryRouter_getInstance().heap(), aiBufferSize, 0x40);
    m_bufSize = aiBufferSize;
    m_iBufferPosition = 0;
}
