// gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator.cpp: NiBackToFrontAccumulator (12 functions)

#include "../../../../include/BSFaceGenMorphData.h"
#include "../../../../include/NiBackToFrontAccumulator.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiCamera.h"
#include "../../../../include/NiPoint3.h"

#include <new>

#include "../../../../include/RecursiveSpinLock.h"

template <class T> class PoolAllocatorBase
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
    };

    static RecursiveSpinLock ms_kPoolState;
    static LinkedListEntry* ms_pFreeList;
};

class ItemListNode
{
  public:
    ItemListNode* m_pkNext;
    ItemListNode* m_pkPrevious;
    void* m_pInventoryEntryData;
};

typedef PoolAllocatorBase<ItemListNode> NiBackToFrontItemPool;

// Returns a list node to the item pool (its lock at 0x011c5f80, free list at 0x011c5f58).
static inline void DeleteListItem(ItemListNode* pkNode)
{
    pkNode->m_pInventoryEntryData = 0;
    NiBackToFrontItemPool::ms_kPoolState.Lock(0);
    pkNode->m_pkPrevious = 0;
    reinterpret_cast<NiBackToFrontItemPool::LinkedListEntry*>(pkNode)->m_pkNext = NiBackToFrontItemPool::ms_pFreeList;
    NiBackToFrontItemPool::ms_pFreeList = reinterpret_cast<NiBackToFrontItemPool::LinkedListEntry*>(pkNode);
    NiBackToFrontItemPool::ms_kPoolState.Unlock();
}

extern void NiFree(void*);

// Initializes the accumulator base without introducing a second class definition.
// @fnv 0x00aa0fc0
NiAccumulator* __fastcall InitializeAccumulator(NiAccumulator* self, void*) throw()
{
    __assume(self != 0);
    ::new (self) NiObject;
    *(volatile unsigned int*)self = 0x010a2304;
    self->m_pkCamera = 0;
    return self;
}

// Returns the median of the three values at indices left, mid and right in the array.
// @fnv 0x00aa0a20
float NiBackToFrontAccumulator::GetPivotValue(int left, int right)
{
    int mid = (left + right) >> 1;
    if (m_pfDepths[left] < m_pfDepths[mid])
    {
        if (m_pfDepths[mid] < m_pfDepths[right])
            return m_pfDepths[mid];
        if (m_pfDepths[left] < m_pfDepths[right])
            return m_pfDepths[right];
        return m_pfDepths[left];
    }
    if (m_pfDepths[left] < m_pfDepths[right])
        return m_pfDepths[left];
    if (m_pfDepths[mid] < m_pfDepths[right])
        return m_pfDepths[right];
    return m_pfDepths[mid];
}

// @fnv 0x00aa0b40
void NiBackToFrontAccumulator::QuickSort(int left, int right)
{
    if (right > left)
    {
        int iLeft = left - 1;
        int i = right + 1;
        float pivot = GetPivotValue(left, right);
        for (;;)
        {
            do
            {
                --i;
            } while (m_pfDepths[i] > pivot);
            do
            {
                ++iLeft;
            } while (m_pfDepths[iLeft] < pivot);
            if (iLeft >= i)
                break;
            NiGeometry* item = m_ppkItems[iLeft];
            m_ppkItems[iLeft] = m_ppkItems[i];
            m_ppkItems[i] = item;
            float fTempDepth = m_pfDepths[iLeft];
            m_pfDepths[iLeft] = m_pfDepths[i];
            m_pfDepths[i] = fTempDepth;
        }
        if (i == right)
            QuickSort(left, i - 1);
        else
        {
            QuickSort(left, i);
            QuickSort(i + 1, right);
        }
    }
}

unsigned char __stdcall BSAnimNotes_IsEqual(NiObject*);
// @fnv 0x00aa0ae0
// src: XBOX_PDB 0x00aa0ae0
unsigned char __stdcall NiBackToFrontAccumulator_IsEqual(NiObject* pkObject)
{
    unsigned char r = BSAnimNotes_IsEqual(pkObject);
    return r != 0;
}

extern const char g_011f5f74_arg1[];
// @fnv 0x00aa0e50
// src: COMMUNITY 0x00aa0e50
const char* __cdecl NiBackToFrontAccumulator_GetRTTI()
{
    return g_011f5f74_arg1;
}

struct S_00aa0d00_Renderer;
struct S_00aa0d00_Item
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37(S_00aa0d00_Renderer* r);
};
extern S_00aa0d00_Renderer* DAT_011f4748;

void __fastcall ResetBackToFrontAccumulator(NiBackToFrontAccumulator*, void*);

// Sorts and releases the items, returns their nodes to the free list, and resets the accumulator.
// Free entry points retain the member-call ABI where the shared header has no declaration.
// @fnv 0x00aa0d00
void __fastcall ReleaseAllItems(NiBackToFrontAccumulator* self, void*)
{
    S_00aa0d00_Renderer* r = DAT_011f4748;
    if (r)
    {
        self->Sort();
        self->m_iCurrItem = self->m_iNumItems;
        S_00aa0d00_Item* item = 0;
        if (self->m_iCurrItem)
        {
            item = (reinterpret_cast<S_00aa0d00_Item**>(self->m_ppkItems))[--self->m_iCurrItem];
        }
        while (item)
        {
            item->vfn_37(r);
            item = 0;
            if (self->m_iCurrItem)
            {
                item = (reinterpret_cast<S_00aa0d00_Item**>(self->m_ppkItems))[--self->m_iCurrItem];
            }
        }
        while (self->m_kItems.m_kItemCount.m_uiCount)
        {
            ItemListNode* pNode = self->m_kItems.m_pkHead;
            self->m_kItems.m_pkHead = pNode->m_pkNext;
            if (self->m_kItems.m_pkHead)
                self->m_kItems.m_pkHead->m_pkPrevious = 0;
            else
                self->m_kItems.m_pkTail = 0;
            DeleteListItem(pNode);
            self->m_kItems.m_kItemCount.m_uiCount--;
        }
        reinterpret_cast<void (__thiscall *)(NiBackToFrontAccumulator*)>(ResetBackToFrontAccumulator)(self);
    }
}

extern "C" void __cdecl AA0F30DeleteSized(void* pvMem, unsigned int uiSize);

void __fastcall DestroyBackToFrontAccumulator(NiBackToFrontAccumulator*, void*);

// Scalar deleting destructor.
// @fnv 0x00aa0f30
NiBackToFrontAccumulator* __fastcall DestroyAndFree(NiBackToFrontAccumulator* self, void*, unsigned int uiFlags)
{
    reinterpret_cast<void (__thiscall *)(NiBackToFrontAccumulator*)>(DestroyBackToFrontAccumulator)(self);
    if (uiFlags & 1)
        AA0F30DeleteSized(self, sizeof(NiBackToFrontAccumulator));
    return self;
}

extern int DAT_010a23ac;

// The shared base has no declared constructor, so initialize it through its original entry point.
static inline NiBackToFrontAccumulator* InitializeBackToFrontAccumulator(NiBackToFrontAccumulator* pkObject)
{
    if (pkObject)
    {
        reinterpret_cast<NiAccumulator* (__thiscall *)(NiAccumulator*)>(InitializeAccumulator)(pkObject);
        *(volatile unsigned int*)pkObject = (unsigned int)&DAT_010a23ac;
        NiBackToFrontAccumulator::ItemList* pkList = &pkObject->m_kItems;
        __assume(pkList != 0);
        ::new (pkList) NiBackToFrontAccumulator::ItemList;
        pkObject->m_kItemsToSortAndRender = 0;
        pkObject->m_iNumItems = 0;
        pkObject->m_iMaxItems = 0;
        pkObject->m_ppkItems = 0;
        pkObject->m_pfDepths = 0;
        return pkObject;
    }
    return 0;
}

// @fnv 0x00aa0f50
NiBackToFrontAccumulator* __fastcall CloneBackToFrontAccumulator(NiBackToFrontAccumulator* self, void*, CloningProcess& kCloning)
{
    NiBackToFrontAccumulator* pkObject = InitializeBackToFrontAccumulator(
        static_cast<NiBackToFrontAccumulator*>(BSFaceGenMorphData::operator new(sizeof(NiBackToFrontAccumulator))));
    self->NiCollisionObject_CopyMembers(pkObject, kCloning);
    return pkObject;
}

void __cdecl BSTextureSet_LoadBinary();
// @fnv 0x00aa0ac0
// src: XBOX_PDB 0x00aa0ac0
void __cdecl NiKeyBasedInterpolator_LoadBinary()
{
    BSTextureSet_LoadBinary();
}


extern int DAT_010a23ac;
extern int DAT_010a2304;

extern void NiFree(void*);

void __fastcall ClearItemList(NiBackToFrontAccumulator::ItemList*, void*);

// Frees geometry arrays, moves unsorted list nodes to a global free list, updates the vtable, and calls FUN_00a5d3d0.
// @fnv 0x00aa0dc0
void __fastcall DestroyBackToFrontAccumulator(NiBackToFrontAccumulator* self, void*)
{
    *(unsigned int*)self = (unsigned int)&DAT_010a23ac;
    NiFree(self->m_ppkItems);
    NiFree(self->m_pfDepths);

    while (self->m_kItems.m_kItemCount.m_uiCount != 0)
    {
        ItemListNode* item = self->m_kItems.m_pkHead;

        self->m_kItems.m_pkHead = item->m_pkNext;
        if (self->m_kItems.m_pkHead != 0)
        {
            self->m_kItems.m_pkHead->m_pkPrevious = 0;
        }
        else
        {
            self->m_kItems.m_pkTail = 0;
        }

        DeleteListItem(item);

        --self->m_kItems.m_kItemCount.m_uiCount;
    }

    reinterpret_cast<void (__thiscall *)(NiBackToFrontAccumulator::ItemList*)>(ClearItemList)(&self->m_kItems);
    *(unsigned int*)self = (unsigned int)&DAT_010a2304;
    self->FUN_00a5d3d0();
}

void* NiMalloc(unsigned int uiSize);

extern NiBound DAT_011f4288;

inline const NiBound& NiAVObject::GetBoundingVolume() const
{
    return m_kWorldBound ? *reinterpret_cast<const NiBound*>(m_kWorldBound) : DAT_011f4288;
}

inline const NiPoint3& NiBound::GetNavMeshData() const
{
    return m_kCenter;
}

inline void NiMatrix3::GetCol(unsigned int column, NiPoint3& point) const
{
    const float* entries = reinterpret_cast<const float*>(this);
    point.x = entries[column];
    point.y = entries[3 + column];
    point.z = entries[6 + column];
}

inline NiPoint3 NiCamera::GetWorldTranslation() const
{
    NiPoint3 direction;
    m_kWorld.m_Rotate.GetCol(0U, direction);
    return direction;
}

// Collects the geometry pointers, computes their camera-relative depths, and sorts them.
// @fnv 0x00aa0c00
void NiBackToFrontAccumulator::Sort()
{
    if (!m_kItemsToSortAndRender)
        m_kItemsToSortAndRender = &m_kItems;

    m_iNumItems = m_kItemsToSortAndRender->m_kItemCount.m_uiCount;
    if (m_iNumItems == 0)
        return;

    if (m_iNumItems > m_iMaxItems)
    {
        NiFree(m_ppkItems);
        m_iMaxItems = m_iNumItems;
        m_ppkItems = (NiGeometry**)NiMalloc(m_iMaxItems * sizeof(void*));
        NiFree(m_pfDepths);
        m_pfDepths = (float*)NiMalloc(m_iMaxItems * sizeof(float));
    }

    ItemListNode* pkPos = m_kItemsToSortAndRender->m_pkHead;
    NiPoint3 kViewDir = ((NiCamera*)m_pkCamera)->GetWorldTranslation();

    for (int i = 0; i < m_iNumItems; i++)
    {
        void** ppkElement = &pkPos->m_pInventoryEntryData;
        pkPos = pkPos->m_pkNext;
        m_ppkItems[i] = static_cast<NiGeometry*>(*ppkElement);
        m_pfDepths[i] = ((const NiAVObject*)m_ppkItems[i])->GetBoundingVolume().GetNavMeshData().Dot(kViewDir);
    }

    QuickSort(0, m_iNumItems - 1);
}

struct NiBackToFrontItemsArg
{
    void** m_ppkItems;
    int m_iArrayLength;
};

void NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();

static inline ItemListNode* NewListItem()
{
    NiBackToFrontItemPool::ms_kPoolState.Lock(0);
    NiBackToFrontItemPool::LinkedListEntry* pkReturn = NiBackToFrontItemPool::ms_pFreeList;
    if (pkReturn == 0)
    {
        NiTAbstractPoolAllocator_unsigned_int_CreateFreeMem();
        pkReturn = NiBackToFrontItemPool::ms_pFreeList;
    }
    NiBackToFrontItemPool::ms_pFreeList = NiBackToFrontItemPool::ms_pFreeList->m_pkNext;
    ItemListNode* pkItem = reinterpret_cast<ItemListNode*>(pkReturn);
    pkItem->m_pInventoryEntryData = 0;
    pkItem->m_pkNext = 0;
    pkItem->m_pkPrevious = 0;
    NiBackToFrontItemPool::ms_kPoolState.Unlock();
    return pkItem;
}

static inline void AddNodeTail(NiBackToFrontAccumulator::ItemList& kList, ItemListNode* pkNode)
{
    pkNode->m_pkNext = 0;
    pkNode->m_pkPrevious = kList.m_pkTail;
    if (kList.m_pkTail)
        kList.m_pkTail->m_pkNext = pkNode;
    else
        kList.m_pkHead = pkNode;
    kList.m_pkTail = pkNode;
    kList.m_kItemCount.m_uiCount++;
}

static inline void AddTail(NiBackToFrontAccumulator::ItemList& kList, void* element)
{
    ItemListNode* pkNode = NewListItem();
    pkNode->m_pInventoryEntryData = element;
    AddNodeTail(kList, pkNode);
}

// Appends each geometry pointer in pkArg->m_ppkItems to m_kItems via AddTail.
// @fnv 0x00aa0e60
void __fastcall AddGeometries(NiBackToFrontAccumulator* self, void*, NiBackToFrontItemsArg* pkArg)
{
    unsigned int ItemUpdateArray = pkArg->m_iArrayLength;
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        AddTail(self->m_kItems, pkArg->m_ppkItems[uiIndex]);
    }
}
