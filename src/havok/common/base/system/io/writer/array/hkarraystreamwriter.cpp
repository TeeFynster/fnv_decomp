
// src/havok/common/base/system/io/writer/array/hkarraystreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/array/hkarraystreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkArrayStreamWriter.h"

// The shared router layout has its heap at +0x10; all router calls bind to 0x00c85750.
namespace HavokHeap {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return HavokHeap::hkMemoryRouter_getInstance().heap();
}
template <class T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int cap = getCapacity();
    if (cap < n)
    {
        int doubled = 2 * cap;
        hkArrayUtil::_reserve(alloc, this, n < doubled ? doubled : n, sizeof(T));
    }
}
template <class T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int) throw();
template <class T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n, const T& fill)
{
    GrowArrayCapacity(alloc, n);
    T* dst = m_data + m_iElementCount;
    int count = n - m_iElementCount;
    if (count <= 0)
    {
        m_iElementCount = n;
        return;
    }
    fnv_zlib_memset(dst, fill, count);
    m_iElementCount = n;
}
inline void hkReferencedObject::operator delete(void* p)
{
    HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(
        p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

// Kept locally: include/hkArrayStreamWriter.h does not declare Reset or Seek.

struct FUN_00d467c0
{
    void write(const char* a, unsigned int b);
};
struct FUN_00d468a0_obj
{
    unsigned int pad[2];
    FUN_00d467c0* p;
    unsigned int WriteToStream(unsigned int arg, unsigned int b);
};
// @fnv 0x00d468a0
unsigned int FUN_00d468a0_obj::WriteToStream(unsigned int apData, unsigned int auiSize)
{
    p->write((const char*)apData, auiSize);
    return auiSize;
}

struct FUN_00d469c0
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00d469c0(int v);
};
// @fnv 0x00d469c0
FUN_00d469c0::FUN_00d469c0(int v)
{
    m2 = 0;
    m3 = 0;
    m4 = 0x80000000;
    m1 = v;
    m0 = v;
}

struct FUN_00d46b20_inner
{
    void Run();
};

struct FUN_00d46b20_cls
{
    int unk00;
    int unk04;
    FUN_00d46b20_inner* m_08;
    void hkMemoryTrackStreamWriter_clear();
};

// @fnv 0x00d46b20
// src: HAVOK_SRC 0x00d46b20
void FUN_00d46b20_cls::hkMemoryTrackStreamWriter_clear()
{
    m_08->Run();
}

struct FUN_00d46c80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;

    void hkMemoryTrackStreamReader_skip(int aiDelta);
};

// @fnv 0x00d46c80
// src: HAVOK_LIB 0x00d46c80
void FUN_00d46c80_cls::hkMemoryTrackStreamReader_skip(int aiDelta)
{
    m_0c += aiDelta;
}

extern int DAT_010cf734;
struct FUN_00d466e0
{
    void* unk00;
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00d466e0(int a, int b);
};
// Initializes the object: sets unk06 to 1, points unk00 at DAT_010cf734, stores b in unk10 and a in unk08, and clears unk0C.
// @fnv 0x00d466e0
FUN_00d466e0::FUN_00d466e0(int a, int b)
{
    unk06 = 1;
    unk00 = &DAT_010cf734;
    unk10 = b;
    unk08 = a;
    unk0C = 0;
}

struct FNVWriter
{
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(int operation, const void* globalData, void* bytes, unsigned int count, unsigned int limit);
    int unk04;
    int unk08;
    int unk0c;
    unsigned char allowRestricted;
};
extern int DAT_010cc460;
extern unsigned int __cdecl hkStatisticsCollector_getAllocatedSize(void*, unsigned int);
struct FUN_00d46770_cls
{
    int unk00;
    int unk04;
    hkArray<char>* buffer;
    void WriteBufferToWriter(FNVWriter* writer, int unused);
};
// If buffer is set and either unrestricted or the writer allows restricted data, passes its data, used size and computed limit to writer->method14.
// @fnv 0x00d46770
void FUN_00d46770_cls::WriteBufferToWriter(FNVWriter* writer, int unused)
{
    hkArray<char>* b = buffer;
    if (b != 0)
    {
        unsigned int flags = b->m_iCapacityState;
        if ((flags & 0x80000000u) == 0 || writer->allowRestricted)
        {
            void* data = b->m_data;
            unsigned int limit = hkStatisticsCollector_getAllocatedSize(data, flags & 0x3fffffff);
            writer->method14(3, &DAT_010cc460, b->m_data, b->m_iElementCount, limit);
        }
    }
}

inline void hkDeallocateChunkD469(void* p, int iNumBytes)
{
    HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(p, iNumBytes);
}

class hkBlockPoolD469
{
  public:
    int m_iDofCount;
    int m_pTileTemplate;
    hkArray<void*> m_kBlocks;

    void FreeAllChunks();
};

// @fnv 0x00d469e0
void hkBlockPoolD469::FreeAllChunks()
{
    for (int i = 0; i < m_kBlocks.m_iElementCount; i++)
        hkDeallocateChunkD469(m_kBlocks.m_data[i], m_iDofCount);
    m_kBlocks.clearAndDeallocate();
    m_pTileTemplate = m_iDofCount;
}

struct FUN_00d469e0_Obj
{
    void FreeAllChunks();
};
struct FUN_00d46be0_Cls
{
    int m00;
    int m04;
    int* m08;
    int m0c;
    int m10;
    void UpdateFields_00d46be0();
};
// @fnv 0x00d46be0
// src: GUESS 0x00d46be0 (confidence: low)
void FUN_00d46be0_Cls::UpdateFields_00d46be0()
{
    reinterpret_cast<FUN_00d469e0_Obj*>(this)->FreeAllChunks();
    hkMemoryRouter* res = &HavokHeap::hkMemoryRouter_getInstance();
    hkMemoryAllocator* pInner = res->m_heap;
    int v = m10;
    m0c = 0;
    if (v & 0x80000000)
        goto done;
    pInner->bufFree(m08, (v & 0x3fffffff) * 4);
done:
    m08 = 0;
    m10 = 0x80000000;
}

class FUN_00d46be0_class
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    void UpdateFields_00d46be0() throw();
    ~FUN_00d46be0_class() throw()
    {
        UpdateFields_00d46be0();
    }
    static void operator delete(void* p) throw()
    {
        HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(p, sizeof(FUN_00d46be0_class));
    }
};

class FUN_00d46c30 : public hkReferencedObject
{
  public:
    FUN_00d46be0_class* m_stream;
    int m_0c;
    int m_ownership;

    virtual ~FUN_00d46c30() throw();
};

// Destructor that deletes m_stream when m_ownership equals 1.
// @fnv 0x00d46c30
FUN_00d46c30::~FUN_00d46c30() throw()
{
    if (m_ownership == 1)
        delete m_stream;
}

struct State
{
    bool status;
    State()
    {}
};
struct Counters
{
    int step;
    int base;
    int misc;
    int length;
};
struct FUN_00d46ca0_Class
{
    int unk00, unk04;
    Counters* counters;
    int position;
    State hkMemoryTrackStreamReader_isOk();
};
// @fnv 0x00d46ca0
// src: HAVOK_LIB 0x00d46ca0
State FUN_00d46ca0_Class::hkMemoryTrackStreamReader_isOk()
{
    State result;
    result.status = position <= (counters->length - 1) * counters->step + counters->base;
    return result;
}

namespace fnv_00d46cc0 {
struct FnvCpu_FUN_00d46cc0_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d46c30();
    FnvCpu_FUN_00d46cc0_CpuObject* Destroy(unsigned int flags);
};
// @fnv 0x00d46cc0
FnvCpu_FUN_00d46cc0_CpuObject* FnvCpu_FUN_00d46cc0_CpuObject::Destroy(unsigned int flags)
{
    FUN_00d46c30();
    if (flags & 1)
    {
        hkMemoryRouter* holder = &HavokHeap::hkMemoryRouter_getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}
}  // namespace fnv_00d46cc0

void __cdecl hkString_memCpy(void* dst, const void* src, int nbytes);

class hkBlockStreamD466
{
  public:
    int m_iDofCount;
    int m_iLastBlockSize;
    char** m_kBlocks;
    int m_iBlockCount;

    void Read(void* buf, int nbytes, int offset);
};

// Copies nbytes from the block stream into buf, starting at byte offset, spanning blocks as needed.
// @fnv 0x00d46660
void hkBlockStreamD466::Read(void* apDest, int aiByteCount, int offset)
{
    int block = offset / m_iDofCount;
    int blockOffset = offset - block * m_iDofCount;
    while (aiByteCount > 0)
    {
        int size = (block < m_iBlockCount - 1) ? m_iDofCount : m_iLastBlockSize;
        char* src = m_kBlocks[block] + blockOffset;
        int avail = size - blockOffset;
        if (aiByteCount <= avail)
        {
            hkString_memCpy(apDest, src, aiByteCount);
            return;
        }
        hkString_memCpy(apDest, src, avail);
        apDest = (char*)apDest + avail;
        aiByteCount -= avail;
        block++;
        blockOffset = 0;
    }
}

class hkBufferD467
{
  public:
    int m_iFirstIndex;
    int m_last;
    int unk08;
    int m_iCapacity;

    void Read(void* dst, int n, int offset) throw();
};

class hkStreamD467
{
  public:
    virtual ~hkStreamD467();
    virtual int read(void* dst, int n);
    virtual int skip(int n);
    virtual hkBool IsStreamValid();

    int unk04;
    hkBufferD467* m_buffer;
    int m_offset;

    int hkMemoryTrackStreamReader_read(void* dst, int n);
};

// Reads up to n bytes from the stream buffer into dst, advancing m_offset, and returns the number of bytes actually read.
// @fnv 0x00d46710
// src: HAVOK_LIB 0x00d46710
int hkStreamD467::hkMemoryTrackStreamReader_read(void* apBuffer, int aiCount)
{
    if (IsStreamValid())
    {
        int avail = (m_buffer->m_iCapacity - 1) * m_buffer->m_iFirstIndex + m_buffer->m_last - m_offset;
        int k = aiCount < avail ? aiCount : avail;
        m_buffer->Read(apBuffer, k, m_offset);
        m_offset += aiCount;
        return k;
    }
    return 0;
}

// Resets the buffer writer by clearing the size and position, reserving one byte, and null-terminating the buffer.
// @fnv 0x00d468c0
void hkArrayStreamWriter::Reset()
{
    m_aiIndexedValues->m_iElementCount = 0;
    m_offset = 0;
    m_aiIndexedValues->reserve(m_aiIndexedValues->m_iElementCount + 1);
    m_aiIndexedValues->m_data[m_aiIndexedValues->m_iElementCount] = 0;
}
// Seeks m_offset to iRelOffset relative to eWhence, growing m_aiIndexedValues if needed, and returns 1 on negative offset.
// @fnv 0x00d46b30
int hkArrayStreamWriter::Seek(int iRelOffset, int eWhence)
{
    int iAbsOffset = m_offset;
    switch (eWhence)
    {
    case 0:
        iAbsOffset = iRelOffset;
        break;
    case 1:
        iAbsOffset = m_offset + iRelOffset;
        break;
    case 2:
        iAbsOffset = m_aiIndexedValues->GetLogicalSize() - iRelOffset;
        break;
    }
    if (iAbsOffset >= 0)
    {
        if (iAbsOffset > m_aiIndexedValues->GetLogicalSize())
        {
            m_aiIndexedValues->setSize(iAbsOffset + 1, 0);
            m_aiIndexedValues->m_iElementCount = iAbsOffset;
        }
        m_offset = iAbsOffset;
        return 0;
    }
    return 1;
}

class Stream_d467
{
  public:
    int m_iDofCount;
    int m_offset;
    hkArray<const char*> m_kBlocks;

    void WriteBytesToBlocks(const char* pcData, int iSize);
};

void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl hkString_memCpy(void* dst, const void* src, int count);

// Copies iSize bytes from pcData into the stream's block array, allocating new blocks from the heap when the current block is full.
// @fnv 0x00d467c0
// src: GUESS 0x00d467c0 (confidence: medium)
void Stream_d467::WriteBytesToBlocks(const char* pcData, int iSize)
{
    int blockIndex = m_kBlocks.m_iElementCount - 1;

    if (iSize > 0)
    {
        hkArray<const char*>* blocks = &m_kBlocks;
        do
        {
            int blockSize = m_iDofCount;
            int available = blockSize - m_offset;

            if (available == 0)
            {
                hkMemoryAllocator& heap = HavokHeap::hkMemoryRouter_getInstance().heap();
                char* block = (char*)heap.blockAlloc(blockSize);

                hkMemoryRouter* router = &HavokHeap::hkMemoryRouter_getInstance();
                if (blocks->m_iElementCount == (blocks->m_iCapacityState & 0x3fffffff))
                {
                    ResizeAudioStream(router->m_heap, blocks, 4);
                }

                const char** pSlot = &blocks->m_data[blocks->m_iElementCount];
                pSlot[0] = block;
                pSlot[0] = block;
                blocks->m_iElementCount++;
                blockIndex++;
                m_offset = 0;
                available = m_iDofCount;
            }

            char* destination = (char*)m_kBlocks.m_data[blockIndex] + m_offset;

            if (iSize > available)
            {
                hkString_memCpy(destination, pcData, available);
                pcData += available;
                iSize -= available;
                m_offset = m_iDofCount;
            }
            else
            {
                hkString_memCpy(destination, pcData, iSize);
                m_offset += iSize;
                return;
            }
        } while (iSize > 0);
    }
}

// Copies size bytes from mem into the indexed values array at m_offset, growing the array if needed, then advances m_offset and returns size.
// @fnv 0x00d46920
int hkArrayStreamWriter::write(const void* mem, int size)
{
    int spaceLeft = m_aiIndexedValues->GetLogicalSize() - m_offset;
    if (size > spaceLeft)
    {
        int newSize = m_aiIndexedValues->GetLogicalSize() - spaceLeft + size;
        m_aiIndexedValues->reserve(newSize + 1);
        m_aiIndexedValues->m_iElementCount = newSize;
        (*m_aiIndexedValues)[newSize] = 0;
    }
    else if (m_aiIndexedValues->getCapacity() > m_aiIndexedValues->GetLogicalSize())
    {
        (*m_aiIndexedValues)[m_aiIndexedValues->GetLogicalSize()] = 0;
    }
    hkString_memCpy(m_aiIndexedValues->m_data + m_offset, mem, size);
    m_offset += size;
    return size;
}

namespace fnv_00d46a50 {
struct V46a50Elem
{
};
struct V46a50Owner
{
    void doElem(V46a50Elem* e, int n);
    void hkMemoryTrack_appendByMove(struct V46a50List* l);
};
struct V46a50List
{
    int m0;
    int m4;
    V46a50Elem** m_data;
    int m_iElementCount;
    int m_capFlags;
    void FreeAllChunks();
};

// Processes each stored element with doElem and heap v08, then releases the array buffer and resets the list.
// @fnv 0x00d46a50
// src: HAVOK_LIB 0x00d46a50
void V46a50Owner::hkMemoryTrack_appendByMove(V46a50List* apList)
{
    int n = apList->m_iElementCount;
    for (int i = 0; i < n - 1; i++)
    {
        V46a50Elem* e = apList->m_data[i];
        doElem(e, apList->m0);
        int k = apList->m0;
        HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(e, k);
    }
    if (n != 0)
    {
        V46a50Elem* e = apList->m_data[n - 1];
        doElem(e, apList->m4);
        int k = apList->m0;
        HavokHeap::hkMemoryRouter_getInstance().heap().blockFree(e, k);
    }
    hkMemoryAllocator& a = HavokHeap::hkMemoryRouter_getInstance().heap();
    apList->m_iElementCount = 0;
    if ((apList->m_capFlags & 0x80000000) == 0)
        a.bufFree(apList->m_data, (apList->m_capFlags & 0x3fffffff) * sizeof(V46a50Elem*));
    apList->m_data = 0;
    apList->m_capFlags = 0x80000000;
    apList->FreeAllChunks();
}
}  // namespace fnv_00d46a50
