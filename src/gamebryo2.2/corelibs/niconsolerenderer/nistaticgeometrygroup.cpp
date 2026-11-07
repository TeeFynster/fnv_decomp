#include "../../../../include/NiTPrimitiveArray.h"
#include "../../../../include/NiGeometryBufferData.h"
#include "../../../../include/NiGeometryGroup.h"
#include "../../../../include/NiStaticGeometryGroup.h"
#include "../../../../include/NiScreenTexture.h"
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTMapItem.h"
#include "../../../../include/NiVBBlock.h"

// Keep local VBSetLocal_00e94b00: the shared header lacks the full block-array layout and
// constructor fields, including the trailing fields at offsets 0x2c and 0x30.
struct VbNode;

template <class T> inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int a, unsigned int b) : NiTArray<T, NiTMallocInterface<T> >(a,b) {}
typedef NiTPrimitiveArray<NiVBBlock*> S_00e94b00_Arr;
template <> inline NiTArray<NiVBBlock*, NiTMallocInterface<NiVBBlock*> >::NiTArray(unsigned int, unsigned int)
{
        m_usMaxSize = 0;
        m_usGrowBy = 1;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
    }
template <> inline void NiTArray<NiVBBlock*, NiTMallocInterface<NiVBBlock*> >::RemoveAll()
{
        for (unsigned short i = 0; i < m_usSize; ++i)
            m_pBase[i] = 0;
        m_usSize = 0;
        m_usESize = 0;
    }

// local form of NiVBSet: 0x00e94b00 needs the unit array at +0x1c and fields through +0x30; the shared form omits those fields.
class VBSetLocal_00e94b00
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00e94b00_Arr arr;
    int unk2c;
    int unk30;
    VBSetLocal_00e94b00();
    ~VBSetLocal_00e94b00();
    VbNode* NiVBSet_AllocateChip(unsigned int size, bool flag);
    void FreeChip(unsigned int uiArrayIndex, unsigned int uiChipIndex);
};

typedef NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, NiVBSet*> GeometryMapBase;
typedef NiTMapItem<unsigned int, NiVBSet*> GeometryMapItem;

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// If p->m_pkBuffData is set, removes it from the group, deletes it, and clears p->m_pkBuffData.
// @fnv 0x00e94740
void NiGeometryGroup::RemoveAndDeleteBuffer(NiGeometryData* p)
{
    NiGeometryBufferData* q = static_cast<NiGeometryBufferData*>(p->m_pkBuffData);
    if (q)
    {
        RemoveObject(q);
        delete q;
        p->m_pkBuffData = 0;
    }
}

namespace fnv_00e94770 {
struct NiVBChip
{
    unsigned int m_uiPosition;
    NiVBBlock* m_pkTreeBlock;
    void* m_pkOwningStream;
};
// @fnv 0x00e94770
// src: COMMUNITY 0x00e94770
void __stdcall NiStaticGeometryGroup_ReleaseChip(NiGeometryBufferData* pkBuffData, unsigned int uiStream)
{
    NiVBChip* pkChip;
    NiVBBlock* pkBlock;
    if (uiStream < pkBuffData->m_uiRegisterStreamCount)
    {
        pkChip = reinterpret_cast<NiVBChip*>(pkBuffData->m_ppkVertexBuffers[uiStream]);
        if (pkChip)
        {
            if (pkChip->m_pkOwningStream)
            {
                pkBlock = pkChip->m_pkTreeBlock;
                reinterpret_cast<VBSetLocal_00e94b00*>(pkBlock->m_pBuffer)->FreeChip(pkBlock->m_04, pkChip->m_uiPosition);
            }
            if (uiStream < pkBuffData->m_uiRegisterStreamCount)
                pkBuffData->m_ppkVertexBuffers[uiStream] = 0;
        }
    }
}
}  // namespace fnv_00e94770

void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_010f0f94;
extern int DAT_010f0fb4;
extern int DAT_010f0fd4;
// Resets vtables, clears the map at offset 12, frees its buffer, calls cleanup, and optionally deletes the object.
// @fnv 0x00e94890
void* NiStaticGeometryGroup::Destroy(unsigned int flag)
{
    *reinterpret_cast<void**>(this) = &DAT_010f0fd4;
    Purge_00e946b0();
    GeometryMapBase* pSets = reinterpret_cast<GeometryMapBase*>(&map);
    *reinterpret_cast<void**>(pSets) = &DAT_010f0fb4;
    pSets->RemoveAll();
    *reinterpret_cast<void**>(pSets) = &DAT_010f0f94;
    pSets->RemoveAll();
    _NiFreeAlias(pSets->m_ppkHashTable);
    FUN_00e98710();
    if (flag & 1)
        _delete(this, 0x1c);
    return this;
}

struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
void __cdecl _NiFreeAlias(void*);
extern int DAT_010f0f84;
struct S
{
    void* f0;
    void* f4;
    void* FUN_00e94a80(unsigned int);
};
// Sets f0 to DAT_010f0f84, frees f4, and if flag bit 0 is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00e94a80
void* S::FUN_00e94a80(unsigned int flag)
{
    void* tmp = f4;
    f0 = &DAT_010f0f84;
    _NiFreeAlias(tmp);
    if (flag & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

// Frees the NiGeometryBufferData stored at offset 0x28 of pkObj, removes it from the group, and clears the pointer.
// @fnv 0x00e94d00
void NiGeometryGroup::vf04(void* pkObj)
{
    NiGeometryBufferData* pkData = *(NiGeometryBufferData**)((char*)pkObj + 0x28);
    if (pkData)
    {
        RemoveObject(pkData);
        delete pkData;
        *(NiGeometryBufferData**)((char*)pkObj + 0x28) = 0;
    }
}

// Frees the NiGeometryBufferData stored at offset 0x1c of pkData via RemoveObject and delete, then clears the pointer.
// @fnv 0x00e94db0
void NiGeometryGroup::vf03(NiGeometryData* pkData)
{
    NiGeometryBufferData* pkBuffData = *(NiGeometryBufferData**)((char*)pkData + 0x1c);
    if (pkBuffData)
    {
        RemoveObject(pkBuffData);
        delete pkBuffData;
        *(NiGeometryBufferData**)((char*)pkData + 0x1c) = 0;
    }
}

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl _fnv_zlib_memset(void* dest, int value, unsigned int size);

template <>
__declspec(nothrow) inline GeometryMapBase::NiTMapBase(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_kItemCount.m_uiCount = 0;
    m_ppkHashTable = static_cast<GeometryMapItem**>(NiMalloc(uiHashSize * 4));
    _fnv_zlib_memset(m_ppkHashTable, 0, m_uiHashSize * 4);
}

template <>
__declspec(nothrow) inline NiTPointerMap<unsigned int, NiVBSet*>::NiTPointerMap(unsigned int uiHashSize)
    : GeometryMapBase(uiHashSize)
{}

// Constructs the group and allocates and zeroes its map bucket array.
// @fnv 0x00e94ab0
__declspec(noinline) __declspec(nothrow) NiStaticGeometryGroup::NiStaticGeometryGroup()
{}

namespace fnv_00e94c00 {
// @fnv 0x00e94c00
// src: XBOX_PDB 0x00e94c00
NiStaticGeometryGroup* __cdecl NiStaticGeometryGroup_Create()
{
    return new NiStaticGeometryGroup;
}
}  // namespace fnv_00e94c00

// @fnv 0x00e946b0
// src: COMMUNITY 0x00e946b0
void NiStaticGeometryGroup::Purge_00e946b0()
{
    GeometryMapItem* pFirstNode = 0;
    GeometryMapBase* pMap = reinterpret_cast<GeometryMapBase*>(&map);
    unsigned int i = 0;
    unsigned int count = pMap->m_uiHashSize;

    if (count > 0)
    {
        GeometryMapItem** buckets = pMap->m_ppkHashTable;
        GeometryMapItem** ppBucketCursor = buckets;
        do
        {
            if (*ppBucketCursor != 0)
            {
                goto found_head;
            }
            ppBucketCursor++;
            i++;
        } while (i < count);
    }
    pFirstNode = 0;
    goto have_head;
found_head:
    pFirstNode = pMap->m_ppkHashTable[i];
have_head:
    GeometryMapItem* node = pFirstNode;
    if (node == 0)
    {
        return;
    }
    do
    {
        unsigned int key = node->m_key;
        VBSetLocal_00e94b00* value = reinterpret_cast<VBSetLocal_00e94b00*>(node->m_val);

        if (node->m_pkNext != 0)
        {
            node = node->m_pkNext;
        }
        else
        {
            i = pMap->KeyToHashIndex(key) + 1;
            if (i < pMap->m_uiHashSize)
            {
                GeometryMapItem** p = pMap->m_ppkHashTable + i;
                do
                {
                    node = *p;
                    if (node != 0)
                    {
                        goto scanned;
                    }
                    p++;
                    i++;
                } while (i < pMap->m_uiHashSize);
            }
            node = 0;
        scanned:;
        }

        pMap->RemoveAt(key);
        if (value != 0)
        {
            value->VBSetLocal_00e94b00::~VBSetLocal_00e94b00();
            _delete(value, 0x34);
        }
    } while (node != 0);
}

struct S_00e948f0_Rtti
{
    int unk00;
    S_00e948f0_Rtti* m_base;
};

struct S_00e948f0_Pool
{
    void* Game_DoHeapAlloc(unsigned int n);
};
extern S_00e948f0_Pool DAT_011f6238;

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00e948f0_Obj
{
    virtual void v00();
    virtual void v04();
    virtual S_00e948f0_Rtti* GetRTTI();
    int unk04;
    int unk08;
    unsigned short m_0c;
    unsigned short unk0E;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void* m_24;
    void* m_28;
    int unk2C;
    int unk30;
    NiGeometryBufferData* m_34;
};

struct S_00e948f0_Y
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short m_22;
    int unk24;
    NiGeometryBufferData* m_28;
};

extern S_00e948f0_Rtti DAT_011f4a88;
extern S_00e948f0_Rtti DAT_011f4a70;
extern unsigned int DAT_011bf558;
bool __cdecl NiObject_IsKindOf(const S_00e948f0_Rtti* r, S_00e948f0_Obj* o);

// The shared group has no declaration for the buffer-registration helper.
void __cdecl RegisterStaticGeometryBuffer();
typedef void (__thiscall* RegisterStaticGeometryBufferFn)(NiStaticGeometryGroup*, NiGeometryBufferData*);

// @fnv 0x00e948f0
void __fastcall InitStaticGeometryData(NiStaticGeometryGroup* group, void*, S_00e948f0_Obj* apObj, int aiUnused, S_00e948f0_Y* apY)
{
    NiGeometryBufferData* d;
    if (apY)
    {
        if (apY->m_28)
        {
            return;
        }
        d = ::new (DAT_011f6238.Game_DoHeapAlloc(sizeof(NiGeometryBufferData))) NiGeometryBufferData;
        d->m_eRequestType = (apY->m_22 != 0) + 4;
        apY->m_28 = d;
    }
    else
    {
        if (apObj->m_34)
        {
            return;
        }
        d = ::new (DAT_011f6238.Game_DoHeapAlloc(sizeof(NiGeometryBufferData))) NiGeometryBufferData;
        bool found = false;
        for (S_00e948f0_Rtti* r = apObj->GetRTTI(); r; r = r->m_base)
        {
            if (r == &DAT_011f4a88)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            d->m_eRequestType = 4;
        }
        else if (NiObject_IsKindOf(&DAT_011f4a70, apObj))
        {
            d->m_eRequestType = 5;
        }
        apObj->m_34 = d;
    }
    bool hasA = apObj->m_28 != 0;
    bool hasB = apObj->m_24 != 0;
    bool hasC = hasB && (apObj->m_0c & 0xf000) != 0;
    unsigned int t = apObj->m_0c & 1;
    if (t > DAT_011bf558)
    {
        t = DAT_011bf558;
    }
    unsigned int flags = 0;
    if (hasA)
    {
        flags = 0x400000;
    }
    if (hasB)
    {
        flags |= 0x800000;
    }
    if (hasC)
    {
        flags |= 0x200000;
    }
    d->m_uiValue1 = (t << 24) | flags;
    reinterpret_cast<RegisterStaticGeometryBufferFn>(&RegisterStaticGeometryBuffer)(group, d);
}

extern int DAT_011c0ce0;
extern int DAT_011c0ce4;

// @fnv 0x00e94b00
VBSetLocal_00e94b00::VBSetLocal_00e94b00()
{
    unk0c = DAT_011c0ce0;
    unk04 = 0;
    unk08 = 0;
    unk00 = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    arr.RemoveAll();
    unk2c = 0;
    unk30 = DAT_011c0ce4;
}

struct VbNode
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
};

void* __cdecl NiVBSet_Create(unsigned int a, void* b, unsigned int key, unsigned int usage, unsigned int c);

struct VbDesc
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned char b14;
    unsigned char unk15;
    unsigned char unk16;
    unsigned char unk17;
    unsigned int unk18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int* m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int m_38;
    unsigned int GetKey() const
    {
        return m_0c;
    }
    unsigned int GetCount() const
    {
        return m_20;
    }
    unsigned int GetVertexCount() const
    {
        return m_1c;
    }
    unsigned int GetStride(unsigned int i) const
    {
        if (i < m_20)
            return m_24[i];
        return 0;
    }
    bool IsDynamic() const
    {
        return b14 != 0;
    }
    void SetBase(unsigned int base)
    {
        m_38 = base;
    }
};

// Looks up or creates a VbNode, calls FUN_00e94650 with vertex-count times stride and count>1, then stores a quotient in d->m_38.
// @fnv 0x00e94c20
VbNode* __fastcall GetOrCreateNode(NiStaticGeometryGroup* group, void*, VbDesc* apDesc, unsigned int uiStrideIndex)
{
    VBSetLocal_00e94b00* pNode = 0;
    VBSetLocal_00e94b00* object;
    NiStaticGeometryGroup* owner = group;
    unsigned int key = apDesc->GetKey();
    unsigned int stride;
    stride = apDesc->GetStride(uiStrideIndex);
    if (key == 0)
    {
        key = stride | 0x80000000u;
    }
    unsigned int usage = 0;
    if (apDesc->IsDynamic())
    {
        key |= 0x40000000u;
        usage = 0x80000000u;
    }
    if (!owner->map.GetAt(key, reinterpret_cast<NiVBSet*&>(pNode)) || !(object = pNode))
    {
        object = (VBSetLocal_00e94b00*)NiVBSet_Create(0x10000, owner->m_pD3DDevice, key, usage, 0);
        owner->map.SetAt(key, reinterpret_cast<NiVBSet*>(object));
    }
    unsigned int count = apDesc->GetCount();
    VbNode* r = object->NiVBSet_AllocateChip(apDesc->GetVertexCount() * stride, count > 1);
    apDesc->m_38 = r->m_0c / stride;
    return r;
}

void* __cdecl Object_DispatchCommandFour(unsigned int n);
void __cdecl NiVBSet_DetermineUsageAndPool(void* object);
struct S00e94b80_Unknown
{
    virtual long __stdcall QueryInterface(void* riid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};
struct S00e94b80_Heap
{
};
static S00e94b80_Heap s00e94b80_heap;
inline void* operator new(unsigned int n, S00e94b80_Heap) throw()
{
    return Object_DispatchCommandFour(n);
}
// Allocates a FUN_00e94b00, assigns its fields, AddRefs b when nonnull, releases the prior stored pointer otherwise, and calls FUN_00e941a0.
// @fnv 0x00e94b80
// src: COMMUNITY 0x00e94b80
void* __cdecl NiVBSet_Create(unsigned int a, void* apUnknown, unsigned int key, unsigned int usage, unsigned int c)
{
    VBSetLocal_00e94b00* object = new (s00e94b80_heap) VBSetLocal_00e94b00;
    if (object)
    {
        object->unk0c = a;
        S00e94b80_Unknown* pUnknown = (S00e94b80_Unknown*)apUnknown;
        if (pUnknown)
        {
            object->unk10 = (int)pUnknown;
            pUnknown->AddRef();
        }
        else
        {
            S00e94b80_Unknown* pOldUnknown = (S00e94b80_Unknown*)object->unk10;
            if (pOldUnknown)
                pOldUnknown->Release();
            object->unk10 = 0;
        }
        object->unk04 = key;
        object->unk08 = usage;
        object->unk00 = c;
        NiVBSet_DetermineUsageAndPool(object);
    }
    return object;
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern int DAT_01400000;
// Allocates and initializes a NiGeometryBufferData buffer when pkScreenTexture->m_pkGeometryRendererData is null, then calls FUN_00e98730.
// @fnv 0x00e94a30
void __fastcall InitStaticScreenTexture(NiStaticGeometryGroup* group, void*, NiScreenTexture* pkScreenTexture)
{
    if (!pkScreenTexture->m_pkGeometryRendererData)
    {
        void* p = reinterpret_cast<P03MM*>(&g_memoryManager)->Allocate(0x54);
        NiGeometryBufferData* pkBuffData;
        if (p)
            pkBuffData = ::new (p) NiGeometryBufferData;
        else
            pkBuffData = 0;
        pkBuffData->m_eRequestType = 4;
        pkBuffData->m_uiValue1 = (unsigned int)&DAT_01400000;
        reinterpret_cast<RegisterStaticGeometryBufferFn>(&RegisterStaticGeometryBuffer)(group, pkBuffData);
    }
}
