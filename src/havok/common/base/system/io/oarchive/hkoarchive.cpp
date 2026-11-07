
// src/havok/common/base/system/io/oarchive/hkoarchive.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/oarchive/hkoarchive.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkOArchive.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

// @fnv 0x00d60810
void __fastcall AssignReferencedObject(hkOArchive* self, void*, hkReferencedObject* apObject)
{
    apObject->addReference();
    self->writer->removeReference();
    self->writer = static_cast<hkStreamWriter*>(apObject);
}

extern "C" unsigned int __stdcall WriteSwapped(void*, int, int);

// @fnv 0x00d609c0
unsigned int __stdcall HashUInt(unsigned int auiValue)
{
    return WriteSwapped(&auiValue, 4, 1);
}

// @fnv 0x00d609e0
void hkOArchive::WriteInt64(int n, int m)
{
    WriteBinaryData(&n, 8, 1);
}

// @fnv 0x00d60a20
// src: GUESS 0x00d60a20 (confidence: medium)
void __fastcall hkOArchive_WriteSwapped_Thunk(hkOArchive* self, void*, const void* data, unsigned int size)
{
    self->WriteSwapped(data, 1, size);
}

// @fnv 0x00d60a60
// src: GUESS 0x00d60a60 (confidence: medium)
void __fastcall hkOArchive_WriteSwapped_Thunk_00d60a60(hkOArchive* self, void*, int aiFirst, int aiSecond)
{
    self->WriteSwapped(reinterpret_cast<const void*>(aiFirst), 2, aiSecond);
}

// @fnv 0x00d60a80
// src: GUESS 0x00d60aa0 (confidence: medium)
void __fastcall hkOArchive_WriteSwapped_Thunk_00d60aa0(hkOArchive* self, void*, const void* apData, unsigned int count)
{
    self->WriteSwapped(apData, 4, count);
}

// @fnv 0x00d60aa0
// src: GUESS 0x00d60b00 (confidence: medium)
void __fastcall hkOArchive_WriteSwapped_Thunk_00d60b00(hkOArchive* self, void*, const void* data, int count)
{
    self->WriteSwapped(data, 4, count);
}

// @fnv 0x00d60ac0
void hkOArchive::WriteArray(const void* data, unsigned int elementCount)
{
    WriteSwapped(data, 8, elementCount);
}

// @fnv 0x00d60ae0
// src: GUESS 0x00d60ae0 (confidence: medium)
void __fastcall hkOArchive_WriteSwapped_Thunk_00d60ae0(hkOArchive* self, void*, int a, int b)
{
    self->WriteSwapped((void*)a, 8, b);
}

// @fnv 0x00d60940
void hkOArchive::WriteInt(unsigned int aiValue)
{
    WriteBinaryData(&aiValue, 4, 1);
}

// @fnv 0x00d60960
// src: XBOX_PDB 0x00d60960
void __stdcall hkOArchive_write32u(const float* p)
{
    WriteSwapped((void*)&p, 4, 1);
}

// @fnv 0x00d60980
// src: GUESS 0x00d609a0 (confidence: medium)
void __fastcall hkOArchive_WriteBinaryData_Thunk(hkOArchive* self, void*, int aiValue, int aiUnused)
{
    self->WriteBinaryData(&aiValue, 8, 1);
}

// @fnv 0x00d609a0
// src: GUESS 0x00d609e0 (confidence: medium)
void __fastcall hkOArchive_WriteBinaryData_Thunk_00d609e0(hkOArchive* self, void*, int value, int)
{
    self->WriteBinaryData(&value, 8, 1);
}

// @fnv 0x00d605b0
void hkOArchive::WriteUint8(unsigned char value)
{
    writer->write(&value, 1);
}

// @fnv 0x00d605d0
// src: XBOX_PDB 0x00d605d0
void __fastcall hkOArchive_write8u(hkOArchive* self, void*, unsigned char value)
{
    self->writer->write(&value, 1);
}

struct FUN_00d607e0_object
{
    virtual void FUN_00d607e0_virtual0();
    virtual void FUN_00d607e0_virtual1();
    virtual void FUN_00d607e0_virtual2();
    virtual void FUN_00d607e0_virtual3(int value);
};

// @fnv 0x00d607e0
int __fastcall ForwardValueToObject(hkOArchive* self, void*, int value)
{
    reinterpret_cast<FUN_00d607e0_object*>(self->writer)->FUN_00d607e0_virtual3(value);
    return value;
}

extern int DAT_010d14f8;

// @fnv 0x00d60830
// src: GUESS 0x00d60830 (confidence: high)
hkOArchive* __fastcall hkOArchive_InitializeWriterWithByteSwap(hkOArchive* self, void*, hkReferencedObject* apObject, char b)
{
    self->m_sReferenceCount = 1;
    *(int*)self = (int)&DAT_010d14f8;
    self->writer = static_cast<hkStreamWriter*>(apObject);
    self->byteSwap.m_cBooleanValue = b;
    apObject->addReference();
    return self;
}

// @fnv 0x00d60a00
void hkOArchive::WriteRaw(const void* data, int size)
{
    WriteBinaryData((void*)data, 1, size);
}

// @fnv 0x00d60a40
// src: GUESS 0x00d60a40 (confidence: medium)
void __fastcall hkOArchive_WriteBinaryData_Thunk_00d60a40(hkOArchive* self, void*, int apData, int b)
{
    self->WriteBinaryData((void*)apData, 2, b);
}

// @fnv 0x00d60b00
void __fastcall WriteFloatArray(hkOArchive* self, void*, const float* data, unsigned int count)
{
    self->WriteBinaryData((void*)data, 4, (int)count);
}

// Swaps the two bytes stored at the given addresses.
// @fnv 0x00d605f0
// src: GUESS 0x00d605f0 (confidence: high)
static void hkOArchive_SwapBytes(unsigned char* pFirst, unsigned char* pSecond)
{
    unsigned char t = *pFirst;
    *pFirst = *pSecond;
    *pSecond = t;
}

// Keeps the helper referenced so the compiler emits its out-of-line body.
void swapBytesCaller(unsigned char* pLeft, unsigned char* pRight)
{
    hkOArchive_SwapBytes(pLeft, pRight);
}

struct hkStub
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(int a);
};
// @fnv 0x00d607b0
// src: XBOX_PDB 0x00d607b0
void __fastcall hkOArchive_writeRaw(hkOArchive* self, void*, int a)
{
    reinterpret_cast<hkStub*>(self->writer)->vf10(a);
}

// @fnv 0x00d607c0
// src: GUESS 0x00d607c0 (confidence: low)
void __fastcall hkOArchive_UpdateFields_00d607c0(hkOArchive* self, void*, char v)
{
    self->byteSwap.m_cBooleanValue = v;
}

extern "C" void* __cdecl hkString_memCpy(void* dest, const void* src, unsigned int count);

inline void swapBytes(unsigned char& a, unsigned char& b)
{
    unsigned char t = a;
    a = b;
    b = t;
}

// @fnv 0x00d60600
void hkOArchive::WriteSwapped(const void* data, unsigned int size, unsigned int elementCount)
{
    int elementSize = static_cast<int>(size);
    int count = static_cast<int>(elementCount);
    if (!byteSwap.m_cBooleanValue)
    {
        writer->write(data, elementSize * count);
        return;
    }

    int aiBuffer[128];
    int chunkSize = 512;
    int numInBlock = chunkSize / elementSize;
    const char* cur = (const char*)data;
    int totalBytes = elementSize * count;
    int remBytes = totalBytes % 512;
    int remCount = remBytes / elementSize;

    while (totalBytes > 0)
    {
        if (totalBytes < 512)
        {
            numInBlock = remCount;
            chunkSize = remBytes;
        }

        hkString_memCpy(aiBuffer, cur, chunkSize);

        switch (elementSize)
        {
        case 2: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[1]);
                p += 2;
            }
        }
        break;
        case 4: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[3]);
                swapBytes(p[1], p[2]);
                p += 4;
            }
        }
        break;
        case 8: {
            unsigned char* p = (unsigned char*)aiBuffer;
            for (int iIndex = 0; iIndex < numInBlock; ++iIndex)
            {
                swapBytes(p[0], p[7]);
                swapBytes(p[1], p[6]);
                swapBytes(p[2], p[5]);
                swapBytes(p[3], p[4]);
                p += 8;
            }
        }
        break;
        }

        writer->write(aiBuffer, chunkSize);
        cur += chunkSize;
        totalBytes -= chunkSize;
    }
}

// @fnv 0x00d607d0
// src: GUESS 0x00d607d0 (confidence: high)
unsigned char* __fastcall hkOArchive_GetByteSwapFlag(hkOArchive* self, void*, unsigned char* output)
{
    *output = self->byteSwap.m_cBooleanValue;
    return output;
}

// @fnv 0x00d60800
// src: XBOX_PDB 0x00d60800
void* __fastcall hkOArchive_getStreamWriter(hkOArchive* self, void*)
{
    return self->writer;
}

class hkMap64DBA
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    unsigned __int64 hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(unsigned __int64 key, unsigned __int64 def) const;
    void InsertKeyValue(hkMemoryAllocator& alloc, unsigned __int64 key, unsigned __int64 val);
};

struct EntryDBA
{
    int m_uiFilterValue;
    int m_next;
};

class ListMapDBA
{
  public:
    EntryDBA* m_entries;
    int m_iNumberOfEntries;
    int m_pRayCursor;
    hkMap64DBA m_map;

    int AllocateSlot();
    void Insert(unsigned __int64 key, const int& value);
};

// Allocates an entry slot, stores value and the existing next index for key, then inserts the key-to-slot mapping into m_map.
// @fnv 0x00dba360
void ListMapDBA::Insert(unsigned __int64 key, const int& value)
{
    int next = (int)m_map.hkMapBase_unsigned_int64_unsigned_int64_struct_hkMapOperations_unsigned_int64_getWithDefault(key, (unsigned __int64)-1);
    int iSlot = AllocateSlot();
    EntryDBA& e = m_entries[iSlot];
    e.m_uiFilterValue = value;
    e.m_next = next;
    // Shared router accessor is bound to 0x00c85750; its heap allocator is at offset 0x10.
    hkMemoryAllocator& alloc = *hkMemoryRouter::getInstance().m_heap;
    m_map.InsertKeyValue(alloc, key, iSlot);
}
