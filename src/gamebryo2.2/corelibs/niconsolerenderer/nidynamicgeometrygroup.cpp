// Exe 0x00e957b0: nothrow primitive-array constructors retain the original cleanup states.
#define FNV64_NITARRAY_CTOR_SPEC throw()
#define FNV64_NITPRIMITIVEARRAY_CTOR_SPEC throw()
// gamebryo2.2/corelibs/niconsolerenderer/nidynamicgeometrygroup.cpp: dynamic geometry groups and buffer helpers (17 functions)

#include "../../../../include/NiDynamicGeometryGroup.h"
#include "../../../../include/NiGeometryGroup.h"
#include "nidynamicgeometrygroup_decls.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiGeometryBufferData.h"
#include "../../../../include/NiGeometryData.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiSkinPartition.h"
#include "../../../../include/NiScreenTexture.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTArray.h"
#include "../../../../include/NiTMallocInterface.h"

typedef NiTArray<NiVBDynamicSet*, NiTMallocInterface<NiVBDynamicSet*> > DynamicSetArray;
typedef NiTArray<NiVBChip*, NiTMallocInterface<NiVBChip*> > DynamicChipArray;

// RTTI vftables 0x010f107c / 0x010f109c identify the sets/chips maps as
// NiTPointerMap<unsigned int, NiVBDynamicSet*> / NiTPointerMap<unsigned int, NiVBChip*>.
// Their bases at 0x010f103c / 0x010f105c use NiTPointerAllocator<unsigned int>.
inline void* __cdecl operator new(unsigned int, void* pvMem) throw()
{
    return pvMem;
}

// Constructs a NiDynamicGeometryGroup and initializes nextIndex to 0.
// @fnv 0x00e957b0
NiDynamicGeometryGroup::NiDynamicGeometryGroup() : nextIndex(0)
{}

struct NiVBChip
{
    unsigned int m_uiPosition;
    NiObject* m_pkTreeBlock;
    NiStream* m_pkOwningStream;
};
// @fnv 0x00e951e0
// src: XBOX_PDB 0x00e951e0
void __stdcall NiDynamicGeometryGroup_ReleaseChip(NiGeometryBufferData* pkBuffData, unsigned int uiStream)
{
    if (uiStream < pkBuffData->m_uiRegisterStreamCount)
    {
        NiVBChip* pkChip = pkBuffData->m_ppkVertexBuffers[uiStream];
        if (pkChip)
        {
            if (pkChip->m_pkOwningStream)
            {
                pkChip->m_pkTreeBlock->NiObject::LinkObject(*pkChip->m_pkOwningStream);
                pkChip->m_pkOwningStream = 0;
            }
            if (uiStream < pkBuffData->m_uiRegisterStreamCount)
                pkBuffData->m_ppkVertexBuffers[uiStream] = 0;
        }
    }
}


extern NiGeometryGroup* DAT_0126fa34;
extern void* DAT_010f1008;

// Returns the cached NiGeometryGroup singleton, constructing it with BSFadeNode::operator new and initialising it if DAT_0126fa34 is null.
// @fnv 0x00e94d70
NiGeometryGroup* __cdecl GetGeometryGroup()
{
    NiGeometryGroup* pkGroup = DAT_0126fa34;
    if (pkGroup == 0)
    {
        pkGroup = static_cast<NiGeometryGroup*>(BSFadeNode::operator new(0xc));
        if (pkGroup != 0)
        {
            pkGroup->NiGeometryGroup::NiGeometryGroup();
            *reinterpret_cast<void**>(pkGroup) = &DAT_010f1008;
            DAT_0126fa34 = pkGroup;
        }
        else
        {
            DAT_0126fa34 = 0;
        }
    }
    return DAT_0126fa34;
}

void __cdecl _NiFreeAlias(void*);
extern MemoryManager g_memoryManager;
extern int DAT_010f1034;
// Frees the stored pointer via _NiFreeAlias, sets the first field to &DAT_010f1034, and deallocates this when f has bit 0 set.
// @fnv 0x00e95780
void* __fastcall DestroySetArray(DynamicSetArray* array, void*, unsigned int auiFlags)
{
    void* tmp = array->m_pBase;
    *reinterpret_cast<void**>(array) = &DAT_010f1034;
    _NiFreeAlias(tmp);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(array);
    return array;
}

void __cdecl operator delete(void*, unsigned int);
// Destroys the group, frees it when bit 0 of uiFlags is set, and returns its address.
// @fnv 0x00e95b40
void* __fastcall DestroyIfFlagged(NiDynamicGeometryGroup* group, void*, unsigned int uiFlags)
{
    group->NiDynamicGeometryGroup::~NiDynamicGeometryGroup();
    if (uiFlags & 1)
        operator delete(group, 0x50);
    return group;
}

extern MemoryManager _g_memoryManager;

void __cdecl _NiFree(void*);

extern void* vftable_DynamicMap;
extern void* vftable_DynamicMapBase;

// @fnv 0x00e95380
void* __fastcall DestroyChipMap(NiTPointerMap<unsigned int, NiVBChip*>* map, void*, unsigned int uiFlags)
{
    *reinterpret_cast<void**>(map) = &vftable_DynamicMap;
    map->RemoveAll();
    *reinterpret_cast<void**>(map) = &vftable_DynamicMapBase;
    map->RemoveAll();
    _NiFree(map->m_ppkHashTable);
    if (uiFlags & 1)
    {
        _g_memoryManager._DeallocateAlias(map);
    }
    return map;
}

// Clears a slot and updates the array's logical size and occupied count.
// @fnv 0x00a93c50
template <class T, class TAlloc>
inline T NiTArray<T, TAlloc>::RemoveAt(unsigned int uiIndex)
{
    if (uiIndex >= m_usSize)
        return 0;

    T element = m_pBase[uiIndex];
    m_pBase[uiIndex] = 0;
    if (element)
        m_usESize--;

    if (uiIndex == (unsigned short)(m_usSize - 1))
        m_usSize--;

    return element;
}

template NiVBDynamicSet* DynamicSetArray::RemoveAt(unsigned int);

extern void* DAT_010f107c;
extern void* DAT_010f103c;

// @fnv 0x00e95300
void* __fastcall DestroySetMap(NiTPointerMap<unsigned int, NiVBDynamicSet*>* map, void*, unsigned int uiFlags)
{
    *reinterpret_cast<void**>(map) = &DAT_010f107c;
    map->RemoveAll();
    *reinterpret_cast<void**>(map) = &DAT_010f103c;
    map->RemoveAll();
    _NiFree(map->m_ppkHashTable);
    if (uiFlags & 1)
    {
        _g_memoryManager._DeallocateAlias(map);
    }
    return map;
}

namespace fnv_00e95500 {
extern MemoryManager DAT_011f6238;
extern char DAT_01400000;
// NiGeometryGroup's buffer-registration operation is not in the shared
// declaration yet.  Give the external entry point its original member ABI.
void __cdecl NiGeometryGroup_AddObject();
typedef void(__thiscall* RegisterBuffer)(NiGeometryGroup*, NiGeometryBufferData*);
// Creates and registers renderer data for a screen texture on first use.
// @fnv 0x00e95500
void __fastcall EnsureBuffer(NiDynamicGeometryGroup* group, void*, NiScreenTexture* destination)
{
    if (destination->m_pkGeometryRendererData == 0)
    {
        NiGeometryBufferData* ptr = static_cast<NiGeometryBufferData*>(DAT_011f6238.Game_DoHeapAlloc(sizeof(NiGeometryBufferData)));
        NiGeometryBufferData* newBuffer = ptr ? ::new (ptr) NiGeometryBufferData : 0;
        newBuffer->m_eRequestType = 4;
        destination->m_pkGeometryRendererData = newBuffer;
        newBuffer->m_uiValue1 = reinterpret_cast<unsigned int>(&DAT_01400000);
        reinterpret_cast<RegisterBuffer>(&NiGeometryGroup_AddObject)(group, newBuffer);
        destination->flags = 0xffff;
    }
}
}  // namespace fnv_00e95500

extern const NiRTTI kRtti_TriShapeData;
extern const NiRTTI kRtti_TriStripsData;

extern MemoryManager g_kMemoryManager;

extern int DAT_011bf558;

// This overload is absent from NiGeometryData's shared declarations. Keep
// its external entry point with the original thiscall ABI, without a class copy.
void __cdecl SetConsistencyMaskEntry();
typedef void(__thiscall* SetConsistencyMaskFn)(NiGeometryData*, unsigned short);

bool __cdecl IsKindOfGeometryData(const NiRTTI* pkRTTI, NiGeometryData* pkObject);

inline bool IsKindOfInline(const NiRTTI* pkRTTI, NiGeometryData* pkObject)
{
    for (const NiRTTI* p = pkObject->GetRTTI(); p; p = p->m_pBaseRTTI)
        if (p == pkRTTI)
            return true;
    return false;
}

// Explicit allocation and placement construction preserve this unit's original
// constructor-call ABI without adding a class-specific allocation overload.
inline NiGeometryBufferData* AllocateGeometryBufferData()
{
    NiGeometryBufferData* data = static_cast<NiGeometryBufferData*>(g_kMemoryManager.Allocate(sizeof(NiGeometryBufferData)));
    return data ? ::new (data) NiGeometryBufferData : 0;
}

// @fnv 0x00e953c0
void __fastcall CreateBufferData(NiDynamicGeometryGroup* group, void*, NiGeometryData* pkData, bool abUnused, NiSkinPartition::Partition* pkPartition)
{
    NiGeometryBufferData* pkBuffData;
    if (pkPartition)
    {
        if (pkPartition->m_pkGeometryRendererData)
            return;
        pkBuffData = AllocateGeometryBufferData();
        pkBuffData->m_eRequestType = (pkPartition->m_usStrips != 0) + 4;
        pkPartition->m_pkGeometryRendererData = pkBuffData;
    }
    else
    {
        if (pkData->m_pkBuffData)
            return;
        pkBuffData = AllocateGeometryBufferData();
        if (IsKindOfInline(&kRtti_TriShapeData, pkData))
            pkBuffData->m_eRequestType = 4;
        else if (IsKindOfGeometryData(&kRtti_TriStripsData, pkData))
            pkBuffData->m_eRequestType = 5;
        pkData->m_pkBuffData = pkBuffData;
    }

    bool bColors = pkData->m_pkColor != 0;
    bool bHasNormals = pkData->m_pkNormal != 0;
    bool bBinormals = bHasNormals && (pkData->m_usDataFlags & 0xf000);
    unsigned int uiT = pkData->m_usDataFlags & 1;
    if (uiT > (unsigned int)DAT_011bf558)
        uiT = DAT_011bf558;
    unsigned int uiFlags = 0;
    if (bColors)
        uiFlags = 0x400000;
    if (bHasNormals)
        uiFlags |= 0x800000;
    if (bBinormals)
        uiFlags |= 0x200000;
    pkBuffData->m_uiValue1 = (uiT << 24) | uiFlags;
    reinterpret_cast<fnv_00e95500::RegisterBuffer>(&fnv_00e95500::NiGeometryGroup_AddObject)(group, pkBuffData);
    reinterpret_cast<SetConsistencyMaskFn>(&SetConsistencyMaskEntry)(pkData, 0xffff);
}

struct ByteFlag
{
    union
    {
        bool value;
        unsigned int flags;
    };
    ByteFlag(bool b) : value(b)
    {}
};
struct MemoryAllocationProvider
{
    void* AllocateStream(unsigned int, unsigned int*, unsigned int*, bool, ByteFlag);
};
struct Chip
{
    unsigned int index;
    MemoryAllocationProvider* set;
    void* buffer;
    unsigned int size;
    unsigned int offset;
    unsigned int stride;
};
MemoryAllocationProvider* __cdecl CreateBufferSetData(unsigned int, void*, unsigned int, unsigned int);
Chip* __cdecl FUN_00537d60(unsigned int, void*, unsigned int, unsigned int, unsigned int);
// These operations are not yet declared on the shared dynamic group.  The
// unused EDX parameter keeps the original member-call register convention.
// @fnv 0x00e95550
Chip* __fastcall GetOrCreateChip(NiDynamicGeometryGroup* group, void*, NiGeometryBufferData* data, unsigned int stream)
{
    Chip* chip = 0;
    unsigned int count = data->m_uiRegisterStreamCount;
    unsigned int key = data->m_uiGroupIndex;
    unsigned int length = stream < count ? data->m_puiVertexStrides[stream] : 0;
    unsigned int stride = data->m_uiVertexDataSize * length;
    unsigned int size = 0;
    unsigned int offset = 0;
    if (count > 1)
    {
        if (reinterpret_cast<DynamicSetArray&>(group->streamSets).m_usMaxSize < count)
        {
            reinterpret_cast<DynamicSetArray&>(group->streamSets).SetSize(count);
            reinterpret_cast<DynamicChipArray&>(group->streamChips).SetSize(count);
        }
        if (group->nextIndex >= reinterpret_cast<DynamicSetArray&>(group->streamSets).m_usMaxSize)
            group->nextIndex = 0;
        MemoryAllocationProvider* set = reinterpret_cast<MemoryAllocationProvider*>(reinterpret_cast<DynamicSetArray&>(group->streamSets).m_pBase[group->nextIndex]);
        if (!set)
        {
            set = CreateBufferSetData(2048, group->m_pD3DDevice, 0, 0);
            reinterpret_cast<DynamicSetArray&>(group->streamSets).SetAt(group->nextIndex, reinterpret_cast<NiVBDynamicSet* const&>(set));
        }
        ByteFlag flag(data->m_bIsInitialized);
        void* buffer = set->AllocateStream(stride, &size, &offset, true, flag);
        Chip* branchChip = reinterpret_cast<Chip*>(reinterpret_cast<DynamicChipArray&>(group->streamChips).m_pBase[group->nextIndex]);
        if (!branchChip)
        {
            branchChip = FUN_00537d60(0, buffer, size, stride, 0);
            chip = branchChip;
            reinterpret_cast<DynamicChipArray&>(group->streamChips).SetAt(group->nextIndex, reinterpret_cast<NiVBChip* const&>(chip));
        }
        else
        {
            branchChip->buffer = buffer;
            branchChip->size = size;
            branchChip->stride = stride;
        }
        branchChip->set = set;
        branchChip->offset = offset;
        data->m_uiBufferSize = 0;
        ++group->nextIndex;
        return branchChip;
    }
    else
    {
        MemoryAllocationProvider* set = 0;
        unsigned int mapKey = key ? key : length | 0x80000000;
        if (!reinterpret_cast<NiTPointerMap<unsigned int, NiVBDynamicSet*>&>(group->sets).GetAt(mapKey, reinterpret_cast<NiVBDynamicSet*&>(set)) || !set)
        {
            set = CreateBufferSetData(2048, group->m_pD3DDevice, key, 0);
            reinterpret_cast<NiTPointerMap<unsigned int, NiVBDynamicSet*>&>(group->sets).SetAt(mapKey, reinterpret_cast<NiVBDynamicSet*>(set));
        }
        ByteFlag flag(data->m_bIsInitialized);
        void* buffer = set->AllocateStream(stride, &size, &offset, false, flag);
        reinterpret_cast<NiTPointerMap<unsigned int, NiVBChip*>&>(group->chips).GetAt(mapKey, reinterpret_cast<NiVBChip*&>(chip));
        Chip* result = chip;
        if (!result)
        {
            result = FUN_00537d60(0, buffer, size, stride, 0);
            reinterpret_cast<NiTPointerMap<unsigned int, NiVBChip*>&>(group->chips).SetAt(mapKey, reinterpret_cast<NiVBChip*>(result));
        }
        else
        {
            result->buffer = buffer;
            result->size = size;
            result->stride = stride;
        }
        result->set = set;
        result->offset = offset;
        data->m_uiBufferSize = size / length;
        return result;
    }
}

extern NiGeometryGroup* DAT_0126fa38;

// Creates the NiDynamicGeometryGroup singleton on first use and returns it.
// @fnv 0x00e95b10
NiGeometryGroup* __cdecl GetNiGeometryGroup() throw()
{
    if (!DAT_0126fa38)
        DAT_0126fa38 = ::new (NiMemObject::operator new(sizeof(NiDynamicGeometryGroup))) NiDynamicGeometryGroup;
    return DAT_0126fa38;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct VertexBufferRef
{
    virtual void __stdcall QueryInterface() = 0;
    virtual void __stdcall AddRef() = 0;
    virtual void __stdcall Release() = 0;
};

struct BufferSetData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int size;
    VertexBufferRef* buffer;
    unsigned int unk10;
    unsigned int unk14;

    BufferSetData() : unk00(0), unk04(0), size(0), buffer(0), unk10(0)
    {}
    static void* operator new(unsigned int bytes)
    {
        return Object_DispatchCommandFour(bytes);
    }
    void SetBuffer(VertexBufferRef* value)
    {
        if (buffer)
            buffer->Release();
        if (value)
        {
            buffer = value;
            value->AddRef();
        }
        else
        {
            buffer = 0;
        }
    }
};

// @fnv 0x00e95230
MemoryAllocationProvider* __cdecl CreateBufferSetData(unsigned int size, void* buffer, unsigned int flags,
                                                      unsigned int kind)
{
    BufferSetData* set = new BufferSetData;
    if (set)
    {
        if (size & 15)
            size = (size & ~15U) + 32;
        set->size = size;
        set->SetBuffer((VertexBufferRef*)buffer);
        set->unk04 = flags;
        set->unk00 = kind;
    }
    return (MemoryAllocationProvider*)set;
}

// Scalar deleting destructor entry points retain the original member ABI.
// @fnv 0x00e952c0
void* __fastcall DestroySetMapBase(NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, NiVBDynamicSet*>* map,
                                 void*, unsigned int uiFlags)
{
    *reinterpret_cast<void**>(map) = &DAT_010f103c;
    map->RemoveAll();
    _NiFree(map->m_ppkHashTable);
    if (uiFlags & 1)
        _g_memoryManager._DeallocateAlias(map);
    return map;
}

// @fnv 0x00e95340
void* __fastcall DestroyChipMapBase(NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, NiVBChip*>* map,
                                  void*, unsigned int uiFlags)
{
    *reinterpret_cast<void**>(map) = &vftable_DynamicMapBase;
    map->RemoveAll();
    _NiFree(map->m_ppkHashTable);
    if (uiFlags & 1)
        _g_memoryManager._DeallocateAlias(map);
    return map;
}

struct S_00e987c0_Stream
{
    void** vtable;
};

struct S_00e987c0_Device
{
    void** vtable;
};

typedef void(__stdcall* FUN_00e987c0_StreamRelease)(S_00e987c0_Stream*);
typedef int(__stdcall* FUN_00e987c0_Allocate)(S_00e987c0_Device*, unsigned int, unsigned int, void*, int, void*, int);

struct S_00e987c0_Class
{
    void* unk00;
    void* unk04;
    unsigned int unk08;
    S_00e987c0_Device* unk0c;
    S_00e987c0_Stream* unk10;
    unsigned int unk14;

    S_00e987c0_Stream* __thiscall AllocateStream(unsigned int uiStream, unsigned int* lpOffset, unsigned int* lpFlags,
                                                 unsigned char bForceFallback, unsigned char bUseSpecialFlags);
};

// Updates the stream size and allocation as needed, advances or resets the offset, sets flags, and returns the stream pointer.
// @fnv 0x00e987c0
S_00e987c0_Stream* __thiscall S_00e987c0_Class::AllocateStream(unsigned int uiStream, unsigned int* lpOffset,
                                                               unsigned int* lpFlags, unsigned char bForceFallback,
                                                               unsigned char bUseSpecialFlags)
{
    if (unk08 < uiStream)
    {
        if (unk10 != 0)
        {
            FUN_00e987c0_StreamRelease pfnRelease = reinterpret_cast<FUN_00e987c0_StreamRelease>(unk10->vtable[2]);
            pfnRelease(unk10);
        }

        unk10 = 0;

        unsigned int uiSize = uiStream;
        if ((uiStream & 0x0f) != 0)
        {
            uiSize = (uiStream & 0xfffffff0u) + 0x20u;
        }
        unk08 = uiSize;
    }

    S_00e987c0_Stream** ppStream = &unk10;

    if (unk10 == 0)
    {
        unsigned int uiAllocationFlags = 0x208u;
        if (bUseSpecialFlags != 0)
        {
            uiAllocationFlags = 0x218u;
        }

        int iResult = (reinterpret_cast<FUN_00e987c0_Allocate>(reinterpret_cast<void**>(unk0c->vtable)[0x1a]))(
            unk0c, unk08, uiAllocationFlags, unk04, 0, static_cast<void*>(ppStream), 0);

        if (iResult >= 0)
        {
            unk14 = 0;
        }
    }

    if (bForceFallback == 0)
    {
        unsigned int uiCommitted = unk14;
        unsigned int uiRemaining = unk08 - uiCommitted;

        if (uiRemaining >= uiStream)
        {
            *lpOffset = uiCommitted;
            unk14 += uiStream;
            *lpFlags = 0x1000u;
            goto L_00b3;
        }
    }

    *lpOffset = 0;
    unk14 = uiStream;
    *lpFlags = 0x2000u;

L_00b3:
    if (*lpOffset == 0)
    {
        *lpFlags = 0x2000u;
    }

    return *ppStream;
}

extern unsigned int DAT_010f10c4;
extern unsigned int DAT_010f0f7c;
extern unsigned int DAT_010f109c;
extern unsigned int DAT_010f105c;

struct ReleaseBuffer
{
    void** vtable;
};
typedef void(__stdcall* ReleaseFn)(ReleaseBuffer*);
struct DynamicSetData
{
    unsigned int unk00, unk04, capacity;
    ReleaseBuffer* buffer0c;
    ReleaseBuffer* buffer10;
    unsigned int offset;
    void Destroy()
    {
        ReleaseBuffer* a = buffer10;
        if (a)
            ((ReleaseFn)a->vtable[2])(a);
        ReleaseBuffer* b = buffer0c;
        if (b)
            ((ReleaseFn)b->vtable[2])(b);
    }
};
struct DynamicChipData
{
    static void operator delete(void*, unsigned int);
    ~DynamicChipData()
    {
        buffer = 0;
    }
    unsigned int index;
    DynamicSetData* set;
    ReleaseBuffer* buffer;
    unsigned int size, offset, stride, unk18, unk1c;
};
template <class TAlloc, class TKEY, class TVAL>
inline void* NiTMapBase<TAlloc, TKEY, TVAL>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; ++i)
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    return 0;
}

template <class TAlloc, class TKEY, class TVAL>
inline void NiTMapBase<TAlloc, TKEY, TVAL>::GetNext(void*& pos, TKEY& key, TVAL& value) const
{
    EntryType* item = (EntryType*)pos;
    key = item->m_key;
    value = item->m_val;
    if (item->m_pkNext)
    {
        pos = item->m_pkNext;
    }
    else
    {
        unsigned int i = KeyToHashIndex(item->m_key);
        for (++i; i < m_uiHashSize; i++)
        {
            item = m_ppkHashTable[i];
            if (item)
            {
                pos = item;
                return;
            }
        }
        pos = 0;
    }
}

template <class TKEY, class TVAL>
inline void DestroyPointerMap(NiTPointerMap<TKEY, TVAL>& map, void* derivedVtable, void* baseVtable)
{
    *reinterpret_cast<void**>(&map) = derivedVtable;
    map.RemoveAll();
    *reinterpret_cast<void**>(&map) = baseVtable;
    map.RemoveAll();
    _NiFree(map.m_ppkHashTable);
}

// Iterates the set and chip maps and stream arrays, destroys entries, updates vtables, clears a matching global pointer, and destroys the base group.
// @fnv 0x00e95880
// The cleanup body keeps the original member-call convention without a local
// copy of the group.  The shared base destructor completes its destruction.
void __fastcall DestroyDynamicGeometryGroup(NiDynamicGeometryGroup* group, void*)
{
    *reinterpret_cast<void**>(group) = &DAT_010f10c4;
    unsigned int key;
    DynamicSetData* set;
    DynamicChipData* chip;
    void* setPos = reinterpret_cast<NiTPointerMap<unsigned int, NiVBDynamicSet*>&>(group->sets).GetFirstPos();
    while (setPos)
    {
        reinterpret_cast<NiTPointerMap<unsigned int, NiVBDynamicSet*>&>(group->sets).GetNext(setPos, key, reinterpret_cast<NiVBDynamicSet*&>(set));
        reinterpret_cast<NiTPointerMap<unsigned int, NiVBDynamicSet*>&>(group->sets).RemoveAt(key);
        if (set)
        {
            set->Destroy();
            ::operator delete(set, sizeof(DynamicSetData));
        }
    }
    void* chipPos = reinterpret_cast<NiTPointerMap<unsigned int, NiVBChip*>&>(group->chips).GetFirstPos();
    while (chipPos)
    {
        reinterpret_cast<NiTPointerMap<unsigned int, NiVBChip*>&>(group->chips).GetNext(chipPos, key, reinterpret_cast<NiVBChip*&>(chip));
        reinterpret_cast<NiTPointerMap<unsigned int, NiVBChip*>&>(group->chips).RemoveAt(key);
        chip->buffer = 0;
        delete chip;
    }
    for (unsigned int i = 0; i < reinterpret_cast<DynamicSetArray&>(group->streamSets).m_usMaxSize; ++i)
    {
        set = reinterpret_cast<DynamicSetData*>(reinterpret_cast<DynamicSetArray&>(group->streamSets).RemoveAt(i));
        if (set)
        {
            set->Destroy();
            ::operator delete(set, sizeof(DynamicSetData));
        }
        chip = reinterpret_cast<DynamicChipData*>(reinterpret_cast<DynamicChipArray&>(group->streamChips).RemoveAt(i));
        chip->buffer = 0;
        delete chip;
    }
    if (group == (void*)DAT_0126fa38)
        DAT_0126fa38 = 0;
    *reinterpret_cast<void**>(&group->streamChips) = &DAT_010f0f7c;
    _NiFree(reinterpret_cast<DynamicChipArray&>(group->streamChips).m_pBase);
    *reinterpret_cast<void**>(&group->streamSets) = &DAT_010f1034;
    _NiFree(reinterpret_cast<DynamicSetArray&>(group->streamSets).m_pBase);
    DestroyPointerMap(reinterpret_cast<NiTPointerMap<unsigned int, NiVBChip*>&>(group->chips), &DAT_010f109c, &DAT_010f105c);
    DestroyPointerMap(reinterpret_cast<NiTPointerMap<unsigned int, NiVBDynamicSet*>&>(group->sets), &DAT_010f107c, &DAT_010f103c);
    group->NiGeometryGroup::~NiGeometryGroup();
}
