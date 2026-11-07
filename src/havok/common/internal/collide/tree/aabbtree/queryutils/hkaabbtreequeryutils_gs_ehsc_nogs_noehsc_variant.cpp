#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/Pair.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkAabb.h"

inline Pair::Pair() throw()
{
}


// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d1bb40_Class
{
    int* GetElementAddress_00d1bb40(unsigned short index);
};
inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}
struct S_00d1bcb0_Allocator
{
    int unk00;
};
struct S_00d1bcb0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d1bcb0_Allocator* m_pStreamAllocator;
    S_00d1bcb0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00d1bcb0_Router* hkMemoryRouter_getInstance();
void ResizeAudioStream(S_00d1bcb0_Allocator& alloc, void* array, int sizeElem);
struct S_00d1bcb0_Entry
{
    int m_kPointA;
    int m_kPointB;
};
typedef hkArray<S_00d1bcb0_Entry> S_00d1bcb0_Array;
struct S_00d1bcb0
{
    int unk00;
    S_00d1bcb0_Array* m_ppData;
    bool AppendPointPairAndReturnFalse(int a, int b);
};
extern int __cdecl Object_CollectAABBTreeHits(void*, int, int, int, int, int);
int __cdecl CallWithDefaults(void* arg0, int arg1, int arg2);
int __cdecl Object_CollectAABBTreeHits(void* a, void* b, int c, int d, void* e, void* f);
int __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_queryAabb(void* a, void* b, void* e, void* f);
extern int __cdecl Object_CollectAABBTreeHits(void*, int, int, int, int, int);
int __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_queryAabb_00d1d500(void* arg0, int arg1, int arg2);
extern "C" void* __cdecl hkAabb_QueryAllIfTreePresent(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d540
// src: XBOX_PDB 0x00d1d540
extern "C" void* __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_queryAabb(void* p, int a, int d, int e)
{
    if (!p)
        return 0;
    return hkAabb_QueryAllIfTreePresent(p, a, 0, 0, d, e);
}

extern "C" void* __cdecl Object_CollectOverlappingTreeLeaves(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d570
// src: GUESS 0x00d1d570 (confidence: low)
extern "C" void* __cdecl AabbTree_ProcessIfPresent_00d1d570(void* p, int a, int b)
{
    if (!p)
        return p;
    return Object_CollectOverlappingTreeLeaves(p, a, b, 0, 0, 0);
}

extern "C" void __cdecl Object_ProcessEntries_00d1ca00();
// @fnv 0x00d1d530
// src: GUESS 0x00d1d530 (confidence: low)
extern "C" void __cdecl AabbTree_ForwardCall_00d1d530()
{
    Object_ProcessEntries_00d1ca00();
}

extern int __cdecl Object_CollectRayTreeHits();
int __cdecl hkAabbTreeQueryUtils_ForwardCall_00d1d490();

inline hkAabb::hkAabb()
{
}

// hkAabb's shared declaration has no overlaps method; keep the SIMD bounds test local.
static inline bool overlaps(const hkAabb& bounds, const hkAabb& other)
{
    __m128 mins = _mm_cmple_ps(bounds.m_kMinimumCorner.m_vComponents, other.m_kMaximumCorner.m_vComponents);
    __m128 maxs = _mm_cmple_ps(other.m_kMinimumCorner.m_vComponents, bounds.m_kMaximumCorner.m_vComponents);
    return (_mm_movemask_ps(_mm_and_ps(mins, maxs)) & 7) == 7;
}

struct TreeNodeD1C
{
    hkAabb m_kBounds;
    union
    {
        unsigned short m_pChildAtom;
        int m_data;
    };
    unsigned short m_flags;
    unsigned short m_next;
};

class CollectorD1C
{
  public:
    virtual void unk00();
    virtual float GetHitDistance(TreeNodeD1C* pkNode);
};

struct hkArrayIntD1CLocalForm
{ // local form of hkArray: 0x00d1ce50 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static __forceinline void construct(int* where, int n, const int& e)
    {
        for (int i = 0; i < n; ++i)
            where[i] = e;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void pushBack(int e)
    {
        S_00d1bcb0_Allocator& alloc = hkMemoryRouter_getInstance()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(int));
        construct(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct TreeD1C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TreeNodeD1C* m_pTreeNode;
    int unk14;
    int unk18;
    FUN_00d1bb40_Class m_kNodeCollection;

    __forceinline int queryAll(const hkAabb& kAabb, CollectorD1C* pkCollector, hkArrayIntD1CLocalForm* pkHits, int** ppiOut,
                               int iMaxOut);
};

__forceinline int TreeD1C::queryAll(const hkAabb& kAabb, CollectorD1C* pkCollector, hkArrayIntD1CLocalForm* pkHits,
                                    int** ppiOut, int iMaxOut)
{
    TreeNodeD1C* pkNode = m_pTreeNode;
    int iCount = 0;
    if (pkCollector)
    {
        for (;;)
        {
            hkAabb kNodeAabb;
            kNodeAabb = pkNode->m_kBounds;
            TreeNodeD1C* pkNext =
                (pkNode->m_next != 0x7fff) ? (TreeNodeD1C*)m_kNodeCollection.GetElementAddress_00d1bb40(pkNode->m_next) : 0;
            if (overlaps(kAabb, kNodeAabb))
            {
                if (!(pkNode->m_flags & 0x8000))
                {
                    pkNode = (TreeNodeD1C*)m_kNodeCollection.GetElementAddress_00d1bb40(pkNode->m_pChildAtom);
                    continue;
                }
                if (pkCollector->GetHitDistance(pkNode) == 0.0f)
                    return iCount;
                iCount++;
            }
            pkNode = pkNext;
            if (!pkNode)
                break;
        }

        return iCount;
    }
    if (ppiOut)
    {
        for (;;)
        {
            hkAabb kNodeAabb;
            kNodeAabb = pkNode->m_kBounds;
            TreeNodeD1C* pkNext =
                (pkNode->m_next != 0x7fff) ? (TreeNodeD1C*)m_kNodeCollection.GetElementAddress_00d1bb40(pkNode->m_next) : 0;
            if (overlaps(kAabb, kNodeAabb))
            {
                if (!(pkNode->m_flags & 0x8000))
                {
                    pkNode = (TreeNodeD1C*)m_kNodeCollection.GetElementAddress_00d1bb40(pkNode->m_pChildAtom);
                    continue;
                }
                *(*ppiOut)++ = pkNode->m_data;
                if (iCount >= iMaxOut)
                    return iCount;
                iCount++;
            }
            pkNode = pkNext;
            if (!pkNode)
                break;
        }

        return iCount;
    }
    if (pkHits)
    {
        for (;;)
        {
            hkAabb kNodeAabb;
            kNodeAabb = pkNode->m_kBounds;
            TreeNodeD1C* pkNext =
                (pkNode->m_next != 0x7fff) ? (TreeNodeD1C*)m_kNodeCollection.GetElementAddress_00d1bb40(pkNode->m_next) : 0;
            if (overlaps(kAabb, kNodeAabb))
            {
                if (!(pkNode->m_flags & 0x8000))
                {
                    pkNode = (TreeNodeD1C*)m_kNodeCollection.GetElementAddress_00d1bb40(pkNode->m_pChildAtom);
                    continue;
                }
                pkHits->pushBack(pkNode->m_data);
                iCount++;
            }
            pkNode = pkNext;
            if (!pkNode)
                break;
        }
    }
    return iCount;
}

// @fnv 0x00d1ce50
// src: GUESS 0x00d1ce50 (confidence: high)
int __cdecl hkAabb_QueryAllIfTreePresent(TreeD1C* pkTree, const hkAabb& kAabb, CollectorD1C* pkCollector, hkArrayIntD1CLocalForm* pkHits,
                         int** ppiOut, int iMaxOut)
{
    if (!pkTree->m_pTreeNode)
        return 0;
    return pkTree->queryAll(kAabb, pkCollector, pkHits, ppiOut, iMaxOut);
}

struct Node
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
    unsigned int m_child0;
    unsigned int m_child1;
    unsigned int m_flags;
    unsigned int unk2c;
};

struct NodeArr
{
    Node* m_data;
    Node* ComputeValue_00d9a4c0(unsigned int index);
};

struct Tree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Node* m_pTreeNode;
    int unk14;
    int unk18;
    NodeArr m_kNodeCollection;
};

struct Collider
{
    virtual void v0();
    virtual bool collide(Node* a, Node* b);
};

struct HkAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n);
};

void hkArrayUtil__reserve(S_00d1bcb0_Allocator* alloc, void* arr, int cap, int elemSize);

// src: XBOX_PDB (hkInplaceArray<...::NodePair,64,hkContainerHeapAllocator> family).
// Exe 0x00d1d890: 64 inline node pairs, grown and released with the heap allocator.
template <> __forceinline void hkArray<Pair,hkContainerHeapAllocator>::setSize(int n) {
        S_00d1bcb0_Router* router = hkMemoryRouter_getInstance();
        S_00d1bcb0_Allocator* alloc = router->m_pStreamAllocator;
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int newCap = cap * 2;
            if (n >= newCap)
                newCap = n;
            hkArrayUtil__reserve(alloc, this, newCap, (int)sizeof(Pair));
        }
        m_iElementCount = n;
    }
template <> __forceinline hkArray<Pair,hkContainerHeapAllocator>::~hkArray() {
        S_00d1bcb0_Router* router = hkMemoryRouter_getInstance();
        HkAllocator* alloc = (HkAllocator*)router->m_pStreamAllocator;
        int flags = m_iCapacityState;
        m_iElementCount = 0;
        if ((flags & 0x80000000) == 0)
            alloc->ReturnMemory(m_data, (flags & 0x3fffffff) * (int)sizeof(Pair));
    }
typedef hkInplaceArray<Pair,64,hkContainerHeapAllocator> AabbQueryPairStack;


// @fnv 0x00d1d890
// src: GUESS 0x00d1d890 (confidence: low)
int HkaabbtreequeryutilsGsEhscNogsNoehsc_ProcessEntries_00d1d890(Tree* treeA, Tree* treeB, Collider* cb)
{
    Node* rootA = treeA->m_pTreeNode;
    Node* rootB = treeB->m_pTreeNode;
    if (rootA && rootB)
    {
        int iAllocationSize = 64;
        AabbQueryPairStack stack;

        stack.setSize(iAllocationSize);
        stack.m_data[0].a = (int)rootA;
        stack.m_data[0].b = (int)rootB;
        int index = 1;

        do
        {
            // Five named temps: VC9 sorts the cmpleps pair by symbol id.
            int p0 = index;
            int p1 = p0;
            int p2 = p1;
            int p3 = p2;
            int p4 = p3;
            index = p4;
            Node* nodeA = (Node*)stack.m_data[index - 1].a;
            Node* nodeB = (Node*)stack.m_data[index - 1].b;
            index--;
            if (index > iAllocationSize - 4)
            {
                iAllocationSize *= 2;
                stack.setSize(iAllocationSize);
            }

            unsigned int aLeaf = nodeA->m_flags & 0x80000000u;
            unsigned int bLeaf = nodeB->m_flags & 0x80000000u;

            if (nodeA == nodeB)
            {
                if (aLeaf)
                    continue;

                Node* c0 = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(nodeA->m_child0);
                _mm_prefetch((const char*)c0, _MM_HINT_NTA);
                Node* c1 = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(nodeA->m_child1);
                _mm_prefetch((const char*)c1, _MM_HINT_NTA);
                stack.m_data[index].a = (int)c0;
                stack.m_data[index].b = (int)c0;
                index++;
                stack.m_data[index].a = (int)c0;
                stack.m_data[index].b = (int)c1;
                index++;
                stack.m_data[index].a = (int)c1;
                stack.m_data[index].b = (int)c1;
                index++;
            }
            else
            {
                __m128 cLo = _mm_cmple_ps(nodeA->m_kMinimumCorner, nodeB->m_kMaximumCorner);
                __m128 cHi = _mm_cmple_ps(nodeB->m_kMinimumCorner, nodeA->m_kMaximumCorner);
                if ((_mm_movemask_ps(_mm_and_ps(cLo, cHi)) & 7) != 7)
                    continue;

                if (aLeaf)
                {
                    if (bLeaf)
                    {
                        if (cb->collide(nodeA, nodeB))
                            break;
                    }
                    else
                    {
                        Node* c0 = treeB->m_kNodeCollection.ComputeValue_00d9a4c0(nodeB->m_child0);
                        Node* c1 = treeB->m_kNodeCollection.ComputeValue_00d9a4c0(nodeB->m_child1);
                        stack.m_data[index].a = (int)nodeA;
                        stack.m_data[index].b = (int)c0;
                        _mm_prefetch((const char*)c0, _MM_HINT_NTA);
                        index++;
                        stack.m_data[index].a = (int)nodeA;
                        stack.m_data[index].b = (int)c1;
                        _mm_prefetch((const char*)c1, _MM_HINT_NTA);
                        index++;
                    }
                }
                else if (bLeaf)
                {
                    Node* c0 = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(nodeA->m_child0);
                    Node* c1 = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(nodeA->m_child1);
                    stack.m_data[index].a = (int)c0;
                    stack.m_data[index].b = (int)nodeB;
                    _mm_prefetch((const char*)c0, _MM_HINT_NTA);
                    index++;
                    stack.m_data[index].a = (int)c1;
                    stack.m_data[index].b = (int)nodeB;
                    _mm_prefetch((const char*)c1, _MM_HINT_NTA);
                    index++;
                }
                else
                {
                    Node* a0 = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(nodeA->m_child0);
                    _mm_prefetch((const char*)a0, _MM_HINT_NTA);
                    Node* a1 = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(nodeA->m_child1);
                    _mm_prefetch((const char*)a1, _MM_HINT_NTA);
                    Node* b0 = treeB->m_kNodeCollection.ComputeValue_00d9a4c0(nodeB->m_child0);
                    _mm_prefetch((const char*)b0, _MM_HINT_NTA);
                    Node* b1 = treeB->m_kNodeCollection.ComputeValue_00d9a4c0(nodeB->m_child1);
                    _mm_prefetch((const char*)b1, _MM_HINT_NTA);
                    stack.m_data[index].a = (int)a0;
                    stack.m_data[index].b = (int)b0;
                    index++;
                    stack.m_data[index].a = (int)a0;
                    stack.m_data[index].b = (int)b1;
                    index++;
                    stack.m_data[index].a = (int)a1;
                    stack.m_data[index].b = (int)b0;
                    index++;
                    stack.m_data[index].a = (int)a1;
                    stack.m_data[index].b = (int)b1;
                    index++;
                }
            }
        } while (index);


    }
    return 0;
}
