#include "../../../../../include/hkArray.h"

// src/havok/common/scenedata/mesh/hkxvertexbufferclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxvertexbufferclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct DFD680Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct DFD680MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DFD680Allocator* m_pStreamAllocator;

    DFD680Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" DFD680MemoryRouter& __cdecl hkMemoryRouter_getInstance();

template<class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& sharedAlloc)
{
DFD680Allocator& alloc = reinterpret_cast<DFD680Allocator&>(sharedAlloc);

        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    
}


struct DFD680Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct DFD680MeshData
{
    hkArrayBase<DFD680Vector4> m_kVertices;
    hkArrayBase<int> m_kIndices32;
    hkArrayBase<int> m_kMaterials;
    hkArrayBase<unsigned short> m_kIndices16;
    hkArrayBase<unsigned char> m_flags;

    void ReleaseMeshArrays_00dfd680();
};

// Clears and deallocates all five arrays of the mesh data in reverse order.
// @fnv 0x00dfd680
// src: GUESS 0x00dfd680 (confidence: medium)
void DFD680MeshData::ReleaseMeshArrays_00dfd680()
{
    m_flags._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
    m_kIndices16._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
    m_kMaterials._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
    m_kIndices32._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
    m_kVertices._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap()));
}
