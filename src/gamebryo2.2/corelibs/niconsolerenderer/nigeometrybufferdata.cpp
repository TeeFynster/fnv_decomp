// gamebryo2.2/corelibs/niconsolerenderer/nigeometrybufferdata.cpp: NiGeometryBufferData, RendererData, NiSlotSetE8E (8 functions)

#include <cstddef>
#include "nigeometrybufferdata.h"
#include "../../../../include/NiGeometryBufferData.h"
#include "../../../../include/MemoryManager.h"

// @fnv 0x00e8eee0
void NiGeometryBufferData::ReleaseBuffers()
{
    if (m_pkIndexBuffer)
    {
        m_pkIndexBuffer->Release();
        m_pkIndexBuffer = NULL;
    }

    m_uiPrimitiveCount = 0;
}

extern void* NiGeometryBufferData_vtable;
extern int DAT_010f0170;
void __cdecl _NiFreeAlias(void*);

struct UnknownVtable08
{
    void(__thiscall* pfn0)(void*);
    void(__thiscall* pfn1)(void*);
    void(__thiscall* pfn2)(void*);
    void(__thiscall* pfn3)(void*);
    void(__thiscall* pfn4)(void*);
    void(__thiscall* pfn5)(void*);
    void(__thiscall* pfn6)(void*);
    void(__thiscall* pfn7)(void*, void*, unsigned int);
};

// Keep destruction in a free function: a C++ destructor adds exception cleanup
// for the RendererData base that is absent from this original function.
// @fnv 0x00e8f0f0
void __fastcall DestroyGeometryBufferData(NiGeometryBufferData* apData)
{
    *reinterpret_cast<void**>(apData) = &NiGeometryBufferData_vtable;
    if (apData->m_pkOwnerGroup)
    {
        for (unsigned int i = 0; i < apData->m_uiRegisterStreamCount; ++i)
        {
            void* p = apData->m_pkOwnerGroup;
            (*reinterpret_cast<UnknownVtable08**>(p))->pfn7(p, apData, i);
        }
    }

    COMBaseInterface* pIB = apData->m_pkIndexBuffer;
    if (pIB)
    {
        pIB->Release();
        apData->m_pkIndexBuffer = 0;
    }

    apData->m_uiPrimitiveCount = 0;
    _NiFreeAlias(apData->m_ppkVertexBuffers);
    _NiFreeAlias(apData->m_puiVertexStrides);

    COMUnknownInterface* pDecl = apData->m_pkVertexDeclaration;
    if (pDecl)
    {
        pDecl->Release();
    }

    *reinterpret_cast<void**>(apData) = &DAT_010f0170;
}

namespace fnv_00e8f170 {
extern MemoryManager g_memoryManager;
// Calls the object's destructor, then frees the object via g_memoryManager when _flags has bit 0 set, and returns _this.
// @fnv 0x00e8f170
void* __fastcall FUN_00e8f170(void* _this, int, unsigned int auiFlags)
{
    DestroyGeometryBufferData((NiGeometryBufferData*)_this);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(_this);
    return _this;
}
}  // namespace fnv_00e8f170

extern MemoryManager g_memoryManager;
extern int DAT_010f0170;
// Sets the object's vtable pointer to DAT_010f0170 and, if bit 0 of a1 is set, deallocates the object via g_memoryManager, then returns this.
// @fnv 0x00e8ee80
void* __fastcall DestroyRendererData(NiGeometryData::RendererData* apData, int, unsigned int auiFlags)
{
    *(void**)apData = (void*)&DAT_010f0170;
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(apData);
    return apData;
}

// @fnv 0x00e8f010
void __fastcall SetGeometryGroupIndex(NiGeometryBufferData* apData, int, int aiIndex)
{
    apData->m_uiGroupIndex = aiIndex;
    if (apData->m_pkVertexDeclaration)
    {
        apData->m_pkVertexDeclaration->Release();
        apData->m_pkVertexDeclaration = 0;
    }
}

// Releases the old declaration, stores apDeclaration and AddRefs it when different,
// then resets the group index.
// @fnv 0x00e8f040
void __fastcall SetVertexDeclaration(NiGeometryBufferData* apData, int, COMUnknownInterface* apDeclaration)
{
    if (apDeclaration != apData->m_pkVertexDeclaration)
    {
        if (apData->m_pkVertexDeclaration)
            apData->m_pkVertexDeclaration->Release();
        apData->m_pkVertexDeclaration = apDeclaration;
        if (apDeclaration)
            apDeclaration->AddRef();
    }
    apData->m_uiGroupIndex = 0;
}

void* NiMallocE8E(unsigned int uiSize);
void NiFreeE8E(void* pvMem);
extern "C" void* __cdecl MemMoveE8E(void* pvDest, const void* pvSrc, unsigned int uiSize);
extern "C" void* __cdecl MemSetE8E(void* pvDest, int iValue, unsigned int uiSize);

extern MemoryManager g_kMemManagerE8E;

class NiSlotSetE8E;

class NiSlotListenerE8E
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void SlotRemoved(NiSlotSetE8E* pkSet, unsigned int uiSlot);
};

class NiSlotSetE8E
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    NiSlotListenerE8E* m_pkListener;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int m_uiSize;
    unsigned int* m_puiFlags;
    void** m_ppvSlots;

    void NiGeometryBufferData_SetStreamCount(unsigned int uiNewSize);
};

// Resizes the slot and flag arrays to uiNewSize, copying existing entries, zeroing new ones, notifying the listener of removed slots, and freeing the old arrays.
// @fnv 0x00e8ef10
// src: COMMUNITY 0x00e8ef10
void NiSlotSetE8E::NiGeometryBufferData_SetStreamCount(unsigned int uiNewSize)
{
    if (uiNewSize == m_uiSize)
        return;

    void** ppvNewSlots = (void**)NiMallocE8E(uiNewSize * sizeof(void*));
    unsigned int* puiNewFlags = (unsigned int*)NiMallocE8E(uiNewSize * sizeof(unsigned int));

    if (uiNewSize < m_uiSize)
    {
        MemMoveE8E(ppvNewSlots, m_ppvSlots, uiNewSize * sizeof(void*));
        MemMoveE8E(puiNewFlags, m_puiFlags, uiNewSize * sizeof(unsigned int));
        if (m_pkListener)
        {
            for (unsigned int i = uiNewSize; i < m_uiSize; i++)
                m_pkListener->SlotRemoved(this, i);
        }
    }
    else
    {
        MemMoveE8E(ppvNewSlots, m_ppvSlots, m_uiSize * sizeof(void*));
        MemMoveE8E(puiNewFlags, m_puiFlags, m_uiSize * sizeof(unsigned int));
        MemSetE8E(ppvNewSlots + m_uiSize, 0, (uiNewSize - m_uiSize) * sizeof(void*));
        MemSetE8E(puiNewFlags + m_uiSize, 0, (uiNewSize - m_uiSize) * sizeof(unsigned int));
    }

    g_kMemManagerE8E.Deallocate(m_ppvSlots);
    NiFreeE8E(m_puiFlags);
    m_ppvSlots = ppvNewSlots;
    m_puiFlags = puiNewFlags;
    m_uiSize = uiNewSize;
}

// Returns whether a geometry buffer data kind is enabled by checking bit fields in m_uiValue1.
// @fnv 0x00e8f080
bool NiGeometryBufferData::IsKindEnabled(int kind)
{
    bool r;
    switch (kind)
    {
    case 4:
        r = ((m_uiValue1 >> 22) & 1) != 0;
        return r;
    case 3:
        r = ((m_uiValue1 >> 23) & 1) != 0;
        return r;
    case 13:
    case 14:
        r = ((m_uiValue1 >> 21) & 1) != 0;
        return r;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return (unsigned int)(kind - 5) < (m_uiValue1 >> 24);
    }
    return false;
}
