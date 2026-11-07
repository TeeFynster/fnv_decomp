
// src/havok/common/base/memory/allocator/freelist/systemmemoryblockserver/hksystemmemoryblockserver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/systemmemoryblockserver/hksystemmemoryblockserver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"

struct FUN_00d60480
{
    int __thiscall GetValueAsInteger();
};
// @fnv 0x00d60480
int __thiscall FUN_00d60480::GetValueAsInteger()
{
    int end = *(int*)((char*)this + 0xc);
    if (!end)
        return -1;
    return end - *(int*)((char*)this + 8);
}

struct hkSystemMemoryBlockServer
{
    unsigned int GetBlockSize(unsigned int size);
};

// @fnv 0x00d603f0
unsigned int hkSystemMemoryBlockServer::GetBlockSize(unsigned int size)
{
    unsigned char* base = reinterpret_cast<unsigned char*>(this);

    unsigned int value = *reinterpret_cast<unsigned int*>(base + 0xc);
    if (value != 0)
    {
        unsigned int available = value - *reinterpret_cast<unsigned int*>(base + 0x8);
        if (available >= size)
            return available;
        return size;
    }

    unsigned int minimum = *reinterpret_cast<unsigned int*>(base + 0x4);
    if (size < minimum)
        return minimum;

    return (size + 0x7fffu) & 0xffff8000u;
}

struct FUN_00d60460_Block
{
// @fnv 0x00d60460
    virtual void FUN_00d60460_dummy1()
    {}
    virtual void FUN_00d60460_dummy2()
    {}
    virtual void free(void*, int)
    {}
};

struct FUN_00d60460_Class
{
    int m_auiShapeKeys[2];
    int m_uiBufferCapacity;
    int m_pAuxiliaryObject;
    FUN_00d60460_Block* m_block;

    void hkSystemMemoryBlockServer_free(void*, int);
};

// src: HAVOK_LIB 0x00d60460
void FUN_00d60460_Class::hkSystemMemoryBlockServer_free(void* p, int size)
{
    m_uiBufferCapacity -= size;
    m_block->free(p, size);
}

struct FUN_00d604e0_inner
{
    virtual void v00();
    virtual void Tail(int a);
};

struct FUN_00d604e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d604e0_inner* m_pInner;
    void hkSystemMemoryBlockServer_criticalAlloc(int a);
};

// @fnv 0x00d604e0
// src: HAVOK_LIB 0x00d604e0
void FUN_00d604e0_cls::hkSystemMemoryBlockServer_criticalAlloc(int a)
{
    m_pInner->Tail(a);
}

struct SpawnedTarget
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void Forward(int a);
};

struct FUN_00d604f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedTarget* m_10;
    void hkSystemMemoryBlockServer_criticalFree(int a);
};

// @fnv 0x00d604f0
// src: HAVOK_LIB 0x00d604f0
void FUN_00d604f0_cls::hkSystemMemoryBlockServer_criticalFree(int a)
{
    m_10->Forward(a);
}

// FUN_00d60530: stdcall, 5 stack params, clears one byte through the first param.
// Original: mov eax,[esp+4]; mov byte ptr [eax],0; ret 0x14

// @fnv 0x00d60530
// src: HAVOK_SRC 0x00d60530
void __stdcall hkSystemMemoryBlockServer_resize(unsigned char* out, int a2, int a3, int a4, int a5)
{
    *out = 0;
}

class hkObjD604
{
  public:
    int unk00;
    int unk04;
    unsigned int m_pos;
    unsigned int m_pFreeList;
    // allocate at 0x00d60420 calls allocator slot +4 with a byte count; stream reads take a buffer and count.
    hkMemoryAllocator* m_system;

    int ReadBytes(int iNumBytes, int* piOut);
};

// Checks the allocation limit, advances m_pos, stores the byte count and returns the allocated block.
// @fnv 0x00d60420
int hkObjD604::ReadBytes(int iNumBytes, int* piOut)
{
    if (m_pFreeList && m_pos + iNumBytes > m_pFreeList)
        return 0;
    *piOut = iNumBytes;
    m_pos += iNumBytes;
    return reinterpret_cast<int>(m_system->blockAlloc(iNumBytes));
}

struct FUN_00d60490_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int GetUnk0C();
};

// @fnv 0x00d60490
// src: GUESS 0x00d60490 (confidence: low)
int FUN_00d60490_cls::GetUnk0C()
{
    return unk0C;
}

namespace fnv_00d604a0 {
struct hkObjD604
{
    int unk00;
    int unk04;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;

    hkBool hkSystemMemoryBlockServer_setMemoryLimit(unsigned int n);
};

// @fnv 0x00d604a0
// src: HAVOK_LIB 0x00d604a0
hkBool hkObjD604::hkSystemMemoryBlockServer_setMemoryLimit(unsigned int n)
{
    if (n == 0)
    {
        m_iElementCount = 0;
        return true;
    }
    if (m_pRayCursor > n)
        return false;
    m_iElementCount = n;
    return true;
}
}  // namespace fnv_00d604a0
