
// src/havok/common/base/system/io/reader/buffered/hkbufferedstreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/buffered/hkbufferedstreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/MemoryManager.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkReferencedObject.h"

struct FUN_00d2bb20_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int SetValueAndCompare(int p);
};

// @fnv 0x00d2bb20
int FUN_00d2bb20_cls::SetValueAndCompare(int iValue)
{
    m_1c = m_10;
    m_20 = iValue;
    return iValue > m_18;
}

struct FUN_00d2bb40_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int hkBufferedStreamReader_rewindToMark();
};
// @fnv 0x00d2bb40
// src: HAVOK_LIB 0x00d2bb40
int FUN_00d2bb40_cls::hkBufferedStreamReader_rewindToMark()
{
    if (m_1c >= 0)
    {
        m_10 = m_1c;
        return 0;
    }
    return 1;
}

extern int DAT_0102e388;
extern int DAT_010ce688;
struct hkBufferedStreamReader
{
    int* m_pVTable;
    int m_uiStandInValue;
    hkReferencedObject* m_pObject;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    void UpdateState_00d2bc10();
    void Destroy();
};
// @fnv 0x00d2bc70
void hkBufferedStreamReader::Destroy()
{
    m_pVTable = &DAT_010ce688;
    m_pObject->removeReference();
    ((hkBufferedStreamReader*)((char*)this + 0xc))->UpdateState_00d2bc10();
    m_pVTable = &DAT_0102e388;
}

struct FUN_00d2ba80_cls
{
    int SkipBytes(int);
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual int v12();
};
// Advances the read position by n bytes, refilling the buffer via v12() when the remaining bytes are insufficient, and returns the number of bytes consumed.
// @fnv 0x00d2ba80
int FUN_00d2ba80_cls::SkipBytes(int aiByteCount)
{
    int iRemaining = aiByteCount;
    int iAvailable = ((int*)this)[5] - ((int*)this)[4];
    while (iRemaining > iAvailable)
    {
        iRemaining -= iAvailable;
        if (v12())
            return aiByteCount - iRemaining;
        iAvailable = ((int*)this)[5] - ((int*)this)[4];
    }
    ((int*)this)[4] += iRemaining;
    return aiByteCount;
}

struct FUN_00d2bb10_this
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    bool* hkBufferedStreamReader_markSupported(bool* out);
};

// @fnv 0x00d2bb10
// src: HAVOK_SRC 0x00d2bb10
bool* FUN_00d2bb10_this::hkBufferedStreamReader_markSupported(bool* out)
{
    *out = (m_18 != 0);
    return out;
}

void _FUN_00cb1260(void*, const void*, int);

struct FUN_00d2ba00_cls : FUN_00d2ba80_cls
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    char* m_pBuffer;
    int m_vContactPosition;
    int m_kRayEnd;

    int hkBufferedStreamReader_read(char* pBuffer, int nSize);
};

// Copies up to nSize bytes from the internal buffer into pBuffer, refilling via v12 when exhausted, and returns the number of bytes read.
// @fnv 0x00d2ba00
// src: HAVOK_LIB 0x00d2ba00
int FUN_00d2ba00_cls::hkBufferedStreamReader_read(char* apDest, int nSize)
{
    char* pDest = apDest;
    int nRemaining = nSize;
    int nAvailable = m_kRayEnd - m_vContactPosition;

    while (nRemaining > nAvailable)
    {
        _FUN_00cb1260(pDest, m_pBuffer + m_vContactPosition, nAvailable);
        m_vContactPosition += nAvailable;
        pDest += nAvailable;
        nRemaining -= nAvailable;

        if (v12() != 0)
            return nSize - nRemaining;

        nAvailable = m_kRayEnd - m_vContactPosition;
    }

    _FUN_00cb1260(pDest, m_pBuffer + m_vContactPosition, nRemaining);
    m_vContactPosition += nRemaining;
    return nSize;
}

struct FUN_00d2bb60_object
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9(int)
    {}
};

struct FUN_00d2bb60_cls
{
    int* m_pVTable;
    int m_uiStandInValue;
    FUN_00d2bb60_object* m_pObject;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
};

// @fnv 0x00d2bb60
// src: HAVOK_LIB 0x00d2bb60
int __fastcall hkBufferedStreamReader_seekTellSupported(FUN_00d2bb60_cls* self, int unused, int value)
{
    self->m_pObject->v9(value);
    return value;
}

MemoryManager* hkMemoryRouter_getInstance();
void* hkMemoryRouter_alignedAlloc(void*, void*, unsigned int);
struct FUN_00d2bbd0_cls
{
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00d2bbd0_cls* Init(int p);
};
// @fnv 0x00d2bbd0
FUN_00d2bbd0_cls* FUN_00d2bbd0_cls::Init(int p)
{
    void* a = hkMemoryRouter_getInstance()->allocator;
    m_00 = hkMemoryRouter_alignedAlloc(a, (void*)p, 0x40);
    m_04 = 0;
    m_08 = 0;
    m_0c = p;
    m_10 = -1;
    m_14 = -1;
    return this;
}

// Reader interface: 0x00d2b990 fills the buffer via slot 4, matching the read slot used at 0x00cb14f0.
class BufferedReaderSource
{
  public:
    virtual ~BufferedReaderSource() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual hkBool IsStreamValid() const throw();
    virtual int read(void* pvBuf, int iNumBytes) throw();
};

// Reader buffer: refill at 0x00d2b990 calls compaction at 0x00d2b900; the writer flush is at 0x00d27210.
class BufferedReaderBuffer
{
  public:
    int unk00;
    int unk04;
    BufferedReaderSource* m_stream;
    char* m_buf;
    int m_readPos;
    int m_bufferedBytes;
    int m_bufSize;
    int m_markPos;
    int m_markLimit;

    void CompactBuffer() throw();
    int RefillBuffer();
};

// @fnv 0x00d2b990
int BufferedReaderBuffer::RefillBuffer()
{
    if (!m_stream->IsStreamValid().m_cBooleanValue)
        return 1;
    CompactBuffer();
    int iNumBytes = m_bufSize - m_bufferedBytes;
    int iTotal = 0;
    while (iTotal < iNumBytes)
    {
        int iBytesRead = m_stream->read(m_buf + m_readPos, iNumBytes);
        m_bufferedBytes += iBytesRead;
        iTotal += iBytesRead;
        if (iBytesRead != iNumBytes)
            return iTotal == 0;
    }
    return 0;
}

struct Reader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char* v3(unsigned char*);
};
struct Stream
{
    int a, b;
    Reader* reader;
    int c, pos, end;
    hkBool hkBufferedStreamReader_isOk();
};
// @fnv 0x00d2bad0
// src: HAVOK_LIB 0x00d2bad0
hkBool Stream::hkBufferedStreamReader_isOk()
{
    unsigned char byte;
    return hkBool(pos != end || *reader->v3(&byte) != 0);
}

namespace fnv_00d2bba0 {
struct Stream
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int Tell();
};
struct FUN_00d2bba0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    Stream* m_stream;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int GetCurrentPosition();
};
// Returns the stream's Tell() offset adjusted by (m_10 - m_14), or -1 if Tell() is negative.
// @fnv 0x00d2bba0
int FUN_00d2bba0_cls::GetCurrentPosition()
{
    int r = m_stream->Tell();
    if (r >= 0)
        return (m_10 - m_14) + r;
    return -1;
}
}  // namespace fnv_00d2bba0

class hkTargetD2BB
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
    virtual void V8();
    virtual void V9();
    virtual void reset(int flags);
};

class hkTrackerD2BB
{
  public:
    int unk00;
    int unk04;
    hkTargetD2BB* m_target;
    int unk0C;
    int m_uiItemCount;
    int m_total;
    int unk18;
    int m_pHeadNode;
    int m_last;

    void Reset(int flags);
};

// @fnv 0x00d2bb80
void hkTrackerD2BB::Reset(int flags)
{
    m_pHeadNode = -1;
    m_last = -1;
    m_uiItemCount = 0;
    m_total = 0;
    m_target->reset(flags);
}

extern "C" void __cdecl hkString_memMove(void*, const void*, int);
// @fnv 0x00d2b900
void BufferedReaderBuffer::CompactBuffer() throw()
{
    if (m_markPos < 0)
    {
        m_readPos = 0;
        m_bufferedBytes = 0;
        return;
    }
    if (m_readPos - m_markPos > m_markLimit)
    {
        m_readPos = 0;
        m_bufferedBytes = 0;
        m_markPos = -1;
        m_markLimit = -1;
        return;
    }
    if (m_markPos > 0)
    {
        int dataSize = m_readPos - m_markPos;
        int remainder = dataSize % 512;
        int padBytes = (remainder != 0) ? (512 - remainder) : 0;
        hkString_memMove(m_buf + padBytes, m_buf + m_markPos, dataSize);
        m_markPos = padBytes;
        m_readPos = ((dataSize / 512) + (remainder != 0 ? 1 : 0)) * 512;
        m_bufferedBytes = m_readPos;
    }
}

struct CC9F10Shape
{
    void Refresh();
};
struct V_00d2bbd0 : FUN_00d2bbd0_cls
{
    FUN_00d2bbd0_cls* Init(int);
};
struct FUN_00d2bc30_cls
{
    int* m_pVTable;
    unsigned short m_04;
    unsigned short m_06;
    int m_08;
    FUN_00d2bbd0_cls* Init(int);
    FUN_00d2bc30_cls* hkBufferedStreamReader_hkBufferedStreamReader(int, int);
};
// Sets m_06 to 1, stores a in m_08, sets vtable, calls FUN_00d2bbd0 with b, and calls Refresh on m_08.
// @fnv 0x00d2bc30
// src: HAVOK_LIB 0x00d2bc30
FUN_00d2bc30_cls* FUN_00d2bc30_cls::hkBufferedStreamReader_hkBufferedStreamReader(int aiShape, int b)
{
    m_06 = 1;
    m_08 = aiShape;
    m_pVTable = &DAT_010ce688;
    ((V_00d2bbd0*)((char*)this + 0xc))->Init(b);
    ((CC9F10Shape*)m_08)->Refresh();
    return this;
}

struct BufferedReaderHeap
{
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void*, unsigned int);
};

struct BufferedReaderDeletionView : hkBufferedStreamReader
{
    void Destroy();
    hkBufferedStreamReader* FUN_00d2bca0(unsigned int);
};

// Calls FUN_00d2bc70, and if flags has bit 0 set, releases this block via the memory router's heap ReleaseBlock, then returns this.
// @fnv 0x00d2bca0
hkBufferedStreamReader* BufferedReaderDeletionView::FUN_00d2bca0(unsigned int flags)
{
    Destroy();
    if (flags & 1)
    {
        MemoryManager* router = hkMemoryRouter_getInstance();
        unsigned short size = static_cast<unsigned short>(m_uiStandInValue);
        static_cast<BufferedReaderHeap*>(router->allocator)->ReleaseBlock(this, size);
    }
    return this;
}

void __cdecl hkMemoryRouter_alignedFree(void* allocator, void* buffer);

// @fnv 0x00d2bc10
// src: GUESS 0x00d2bc10 (confidence: low)
__declspec(noinline) void hkBufferedStreamReader::UpdateState_00d2bc10()
{
    void* buffer = m_pVTable;
    MemoryManager* memory = hkMemoryRouter_getInstance();
    hkMemoryRouter_alignedFree(memory->allocator, buffer);
}
