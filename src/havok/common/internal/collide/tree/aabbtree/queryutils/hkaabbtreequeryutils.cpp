#include "../../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Preserve the unit's SIMD representation: the SDK's byte-array aliases
// cause this compiler to insert additional /GS instrumentation.
// Exe 0x00d1bd00 FUN_00d1bd00: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2

#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkpFixedBufferRayHitCollector.h"
#include "../../../../../../../../include/hkCpuWorldRayCastCollector.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkAabb.h"

__forceinline hkpRayHitCollector::hkpRayHitCollector() : m_fEarlyOutHitFraction(1.0f) {}
__forceinline hkpFixedBufferRayHitCollector::hkpFixedBufferRayHitCollector(int buffer, int capacity)
{
    m_pRayHitBuffer = reinterpret_cast<WorldRayCastOutput*>(buffer);
    m_pHitBufferEnd = reinterpret_cast<WorldRayCastOutput*>(buffer);
    m_pRayCursor = capacity;
    m_iHitCount = 0;
    m_pCollidable = 0;
}

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d1bb40_Class
{
    int* GetElementAddress_00d1bb40(unsigned short index);
};

// @fnv 0x00d1bb40
// src: GUESS 0x00d1bb40 (confidence: low)
int* FUN_00d1bb40_Class::GetElementAddress_00d1bb40(unsigned short index)
{
    return *reinterpret_cast<int**>(this) + index * 12;
}

inline void* __cdecl operator new(unsigned int, void* where) throw()
{
    return where;
}


hkMemoryRouter* hkMemoryRouter_getInstance();
void ResizeAudioStream(hkMemoryAllocator& alloc, void* array, int sizeElem);

struct S_00d1bcb0_Entry
{
    int m_kPointA;
    int m_kPointB;
};

typedef hkArray<S_00d1bcb0_Entry> S_00d1bcb0_Array;
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
return reinterpret_cast<hkMemoryAllocator&>(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap()));
}
template<> __forceinline void hkArrayBase<S_00d1bcb0_Entry>::_pushBack(hkMemoryAllocator& sharedAlloc, S_00d1bcb0_Entry const& e)
{
hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(sharedAlloc);

        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(S_00d1bcb0_Entry));
        new (m_data + m_iElementCount) S_00d1bcb0_Entry(e);
        m_iElementCount++;
    
}


struct S_00d1bcb0
{
    int unk00;
    S_00d1bcb0_Array* m_ppData;
    bool AppendPointPairAndReturnFalse(int a, int b);
};

// @fnv 0x00d1bcb0
// src: GUESS 0x00d1bcb0 (confidence: high)
bool S_00d1bcb0::AppendPointPairAndReturnFalse(int iFirst, int iSecond)
{
    S_00d1bcb0_Entry e;
    e.m_kPointA = iFirst;
    e.m_kPointB = iSecond;
    m_ppData->pushBack(e);
    return false;
}

extern int __cdecl Object_CollectAABBTreeHits(void*, int, int, int, int, int);

// Returns 0 if arg0 is null, otherwise forwards arg0, arg1 and arg2 to FUN_00d1c560 with the remaining arguments zeroed.
// @fnv 0x00d1d4a0
int __cdecl CallWithDefaults(void* arg0, int arg1, int arg2)
{
    if (!arg0)
        return 0;
    return Object_CollectAABBTreeHits(arg0, arg1, 0, arg2, 0, 0);
}

int __cdecl Object_CollectAABBTreeHits(void* a, void* b, int c, int d, void* e, void* f);

// Returns 0 if a is null, otherwise forwards a, b, e and f to FUN_00d1c560 with c and d set to 0.
// @fnv 0x00d1d4d0
// src: XBOX_PDB 0x00d1d4d0
int __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_queryAabb(void* a, void* apArg2, void* apArg5, void* apArg6)
{
    if (!a)
        return 0;
    return Object_CollectAABBTreeHits(a, apArg2, 0, 0, apArg5, apArg6);
}

extern int __cdecl Object_CollectAABBTreeHits(void*, int, int, int, int, int);

// If arg0 is non-null, forwards it with arg1 and arg2 plus three zero arguments to FUN_00d1c560 and returns its result; otherwise returns 0.
// @fnv 0x00d1d500
// src: XBOX_PDB 0x00d1d500
int __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_queryAabb_00d1d500(void* arg0, int arg1, int arg2)
{
    if (!arg0)
        return 0;
    return Object_CollectAABBTreeHits(arg0, arg1, arg2, 0, 0, 0);
}

extern "C" void* __cdecl hkAabb_QueryAllIfTreePresent(void* p, int a, int b, int c, int d, int e);

// If p is non-null, forwards it to FUN_00d1ce50 with zeroed middle arguments and returns the result; otherwise returns 0.
// @fnv 0x00d1d540
// src: XBOX_PDB 0x00d1d540
extern "C" void* __cdecl hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_queryAabb(void* p, int aiArg1, int aiArg4, int aiArg5)
{
    if (!p)
        return 0;
    return hkAabb_QueryAllIfTreePresent(p, aiArg1, 0, 0, aiArg4, aiArg5);
}

extern "C" void* __cdecl Object_CollectOverlappingTreeLeaves(void* p, int a, int b, int c, int d, int e);

// If p is non-null, forwards it to FUN_00d1d240 with a, b and three zero arguments; otherwise returns p unchanged.
// @fnv 0x00d1d570
// src: GUESS 0x00d1d570 (confidence: low)
extern "C" void* __cdecl AabbTree_ProcessIfPresent_00d1d570(void* p, int aiArg1, int aiArg2)
{
    if (!p)
        return p;
    return Object_CollectOverlappingTreeLeaves(p, aiArg1, aiArg2, 0, 0, 0);
}

extern "C" void __cdecl Object_ProcessEntries_00d1ca00();
// @fnv 0x00d1d530
// src: GUESS 0x00d1d530 (confidence: low)
extern "C" void __cdecl AabbTree_ForwardCall_00d1d530()
{
    Object_ProcessEntries_00d1ca00();
}

extern int __cdecl Object_CollectRayTreeHits();
// @fnv 0x00d1d490
// src: GUESS 0x00d1d490 (confidence: low)
int __cdecl hkAabbTreeQueryUtils_ForwardCall_00d1d490()
{
    return Object_CollectRayTreeHits();
}

extern "C"
{
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpge_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
}

struct DNode
{
    LocalM128 m_ucLowNibble;
    LocalM128 m_ucHighNibble;
    int m_pChildAtom;
    int unk24;
    int m_flags;
    int m_nextId;
};
struct DIndex
{
    DNode* ComputeValue_00d9a4c0(int id);
};
struct DOwner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    DNode* m_pTreeNode;
    int unk14;
    int unk18;
    DIndex m_uiEdgeIndex;
};

struct DVisitor
{
    virtual void v0();
    virtual float visit(DNode* n);
};
template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct DIntArrayLocalForm
{ // local form of hkArray: 0x00d1d240 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _pushBack(hkMemoryAllocator& alloc, int e)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(int));
        hkConstructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
    __forceinline void pushBack(int e)
    {
        _pushBack(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap()), e);
    }
};
extern float DAT_01011d78;

// Traverses the tree, reporting overlapping leaves to a visitor or storing their child-atom values in an output array.
// @fnv 0x00d1d240
// src: GUESS 0x00d1d240 (confidence: medium)
extern "C" void* __cdecl Object_CollectOverlappingTreeLeaves(void* apOwner, int apQueryBox, int apVisitor, int apIntArray, int apOutArray,
                                      int aiMaxCount)
{
    DOwner* owner = (DOwner*)apOwner;
    DNode* node = owner->m_pTreeNode;
    if (!node)
        return 0;
    int count = 0;
    LocalM128 lo;
    LocalM128 hi;
    if (apVisitor)
    {
        for (;;)
        {
            lo = node->m_ucLowNibble;
            hi = node->m_ucHighNibble;
            DNode* next = node->m_nextId != 0x7fffffff ? owner->m_uiEdgeIndex.ComputeValue_00d9a4c0(node->m_nextId) : 0;
            int mask = _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(((hkAabb*)apQueryBox)->m_kMinimumCorner.m_vComponents, hi),
                                                  _mm_cmple_ps(lo, ((hkAabb*)apQueryBox)->m_kMaximumCorner.m_vComponents)));
            if ((mask & 7) == 7)
            {
                if (!(node->m_flags & 0x80000000))
                {
                    node = owner->m_uiEdgeIndex.ComputeValue_00d9a4c0(node->m_pChildAtom);
                    continue;
                }
                {
                    DVisitor* pVisitor = (DVisitor*)apVisitor;
                    if (pVisitor->visit(node) == 0.0f)
                        return (void*)count;
                }
                count++;
            }
            node = next;
            if (!node)
                break;
        }
    }
    else if (apOutArray)
    {
        int** ppOut = (int**)apOutArray;
        for (;;)
        {
            lo = node->m_ucLowNibble;
            hi = node->m_ucHighNibble;
            DNode* next = node->m_nextId != 0x7fffffff ? owner->m_uiEdgeIndex.ComputeValue_00d9a4c0(node->m_nextId) : 0;
            int mask = _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(((hkAabb*)apQueryBox)->m_kMinimumCorner.m_vComponents, hi),
                                                  _mm_cmple_ps(lo, ((hkAabb*)apQueryBox)->m_kMaximumCorner.m_vComponents)));
            if ((mask & 7) == 7)
            {
                if (!(node->m_flags & 0x80000000))
                {
                    node = owner->m_uiEdgeIndex.ComputeValue_00d9a4c0(node->m_pChildAtom);
                    continue;
                }
                **ppOut = node->m_pChildAtom;
                (*ppOut)++;
                if (count >= aiMaxCount)
                    break;
                count++;
            }
            node = next;
            if (!node)
                break;
        }
    }
    else if (apIntArray)
    {
        DIntArrayLocalForm* array = (DIntArrayLocalForm*)apIntArray;
        for (;;)
        {
            lo = node->m_ucLowNibble;
            hi = node->m_ucHighNibble;
            DNode* next = node->m_nextId != 0x7fffffff ? owner->m_uiEdgeIndex.ComputeValue_00d9a4c0(node->m_nextId) : 0;
            int mask = _mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(((hkAabb*)apQueryBox)->m_kMinimumCorner.m_vComponents, hi),
                                                  _mm_cmple_ps(lo, ((hkAabb*)apQueryBox)->m_kMaximumCorner.m_vComponents)));
            if ((mask & 7) == 7)
            {
                if (!(node->m_flags & 0x80000000))
                {
                    node = owner->m_uiEdgeIndex.ComputeValue_00d9a4c0(node->m_pChildAtom);
                    continue;
                }
                array->pushBack(node->m_pChildAtom);
                count++;
            }
            node = next;
            if (!node)
                break;
        }
    }
    return (void*)count;
}

namespace fnv_00d1d5a0 {
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int reqCapacity, int elemSize);

static __forceinline bool treeBoundsOverlap(const hkAabb& bounds, const hkAabb& other)
{
    LocalM128 mincomp = _mm_cmple_ps(bounds.m_kMinimumCorner.m_vComponents, other.m_kMaximumCorner.m_vComponents);
    LocalM128 maxcomp = _mm_cmpge_ps(bounds.m_kMaximumCorner.m_vComponents, other.m_kMinimumCorner.m_vComponents);
    return (_mm_movemask_ps(_mm_and_ps(mincomp, maxcomp)) & 7) == 7;
}


struct TreeNode
{
    hkAabb m_kBounds;
    int m_children[2];
    unsigned int m_parent;
    int m_next;

    unsigned int isLeaf() const
    {
        return m_parent & 0x80000000u;
    }
};

struct TreeNodeArray
{
    TreeNode* ComputeValue_00d9a4c0(int index);
};

struct AabbTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iNodeCount;
    int m_rootIndex;
    int unk18;
    TreeNodeArray m_kNodeCollection;
};

typedef S_00d1bcb0_Entry TreePair;

struct TreePairStack
{
    TreePair* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    TreePair m_kStorage[64];

    __forceinline TreePairStack()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000040;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(TreePair));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap()), n);
        m_iElementCount = n;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, getCapacity() * sizeof(TreePair));
    }
};

typedef hkArray<TreePair> TreePairArray;
}
namespace fnv_00d1d5a0 {


// Performs a simultaneous traversal of two AABB trees, collecting overlapping leaf pairs into pairsOut and returning the count.
// @fnv 0x00d1d5a0
// src: GUESS 0x00d1d5a0 (confidence: medium)
int Object_CollectOverlappingLeafPairs(AabbTree* treeA, AabbTree* treeB, TreePairArray* pairsOut)
{
    if (treeA->m_iNodeCount == 0 || treeB->m_iNodeCount == 0)
    {
        return 0;
    }

    int stackCap = 64;
    TreePairStack pairStack;
    pairStack.SetSizeAndGrow(stackCap);
    TreePair rootPair = {treeA->m_rootIndex, treeB->m_rootIndex};
    pairStack.m_data[0] = rootPair;

    int top = 1;
    int numPairs = 0;
    do
    {
        TreePair pair = pairStack.m_data[--top];
        if (top > stackCap - 4)
        {
            stackCap += stackCap;
            pairStack.SetSizeAndGrow(stackCap);
        }

        const TreeNode* nodeA = treeA->m_kNodeCollection.ComputeValue_00d9a4c0(pair.m_kPointA);
        const TreeNode* nodeB = treeB->m_kNodeCollection.ComputeValue_00d9a4c0(pair.m_kPointB);
        unsigned int leafA = nodeA->isLeaf();
        unsigned int leafB = nodeB->isLeaf();

        if (nodeA == nodeB)
        {
            if (!leafA)
            {
                int iChild0 = nodeA->m_children[0];
                int iChild1 = nodeA->m_children[1];
                pairStack.m_data[top].m_kPointA = iChild0;
                pairStack.m_data[top].m_kPointB = iChild0;
                top++;
                pairStack.m_data[top].m_kPointA = iChild0;
                pairStack.m_data[top].m_kPointB = iChild1;
                top++;
                pairStack.m_data[top].m_kPointA = iChild1;
                pairStack.m_data[top].m_kPointB = iChild1;
                top++;
            }
        }
        else if (treeBoundsOverlap(nodeB->m_kBounds, nodeA->m_kBounds))
        {
            if (leafA)
            {
                if (leafB)
                {
                    pairsOut->pushBack(pair);
                    numPairs++;
                }
                else
                {
                    int iChildB1 = nodeB->m_children[1];
                    int iChildB0 = nodeB->m_children[0];
                    pairStack.m_data[top].m_kPointA = pair.m_kPointA;
                    pairStack.m_data[top].m_kPointB = iChildB0;
                    top++;
                    pairStack.m_data[top].m_kPointA = pair.m_kPointA;
                    pairStack.m_data[top].m_kPointB = iChildB1;
                    top++;
                }
            }
            else
            {
                if (leafB)
                {
                    TreePair children = {nodeA->m_children[1], nodeA->m_children[0]};
                    pairStack.m_data[top].m_kPointA = children.m_kPointB;
                    pairStack.m_data[top].m_kPointB = pair.m_kPointB;
                    top++;
                    pairStack.m_data[top].m_kPointA = children.m_kPointA;
                    pairStack.m_data[top].m_kPointB = pair.m_kPointB;
                    top++;
                }
                else
                {
                    int iChildA0 = nodeA->m_children[0];
                    int iChildA1 = nodeA->m_children[1];
                    int iChildB0 = nodeB->m_children[0];
                    int iChildB1 = nodeB->m_children[1];
                    pairStack.m_data[top].m_kPointA = iChildA0;
                    pairStack.m_data[top].m_kPointB = iChildB0;
                    top++;
                    pairStack.m_data[top].m_kPointA = iChildA0;
                    pairStack.m_data[top].m_kPointB = iChildB1;
                    top++;
                    pairStack.m_data[top].m_kPointA = iChildA1;
                    pairStack.m_data[top].m_kPointB = iChildB0;
                    top++;
                    pairStack.m_data[top].m_kPointA = iChildA1;
                    pairStack.m_data[top].m_kPointB = iChildB1;
                    top++;
                }
            }
        }
    } while (top);

    pairStack._clearAndDeallocate(reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap()));
    return numPairs;
}
}  // namespace fnv_00d1d5a0

#include <windows.h>
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);

struct Inner
{
    DWORD unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int m_20;
    int m_24;
    int m_28;
};
struct Frame
{
    DWORD unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int m_20;
    int m_24;
    int m_28;
    Inner* m_2C;
    int m_30;
};
class Target
{
  public:
    void ProcessCallback(void* a, void* b, int c);
};
int hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_queryAabb(int a, Inner* b, int* c, int d);
int hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_queryAabb(int a, Inner* b, int* c, int d);
int hkKdTreeAabbQueryUtils_queryAabbIterative_00d1b930(int a, Inner* b, int* c, int d);
// Records CPU profile ticks, iterates Inner nodes calling FUN_00d1d540, FUN_00d1d4d0, FUN_00d1b930, then calls ProcessCallback.
// @fnv 0x00df6850
void __cdecl ProcessAabbTree(Target* apTarget, Frame* apFrame)
{
    hkMonitorStream* pProfBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pProfBuf->m_end.m_storage < pProfBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pProfRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfBuf->m_end.m_storage);
        pProfRec->m_commandAndMonitor = "TtCpuAabbTreeAabb";
        _ReadWriteBarrier();
        volatile DWORD tick = (DWORD)__rdtsc();
        pProfRec->m_time0 = tick;
        pProfBuf->m_end.m_storage = reinterpret_cast<char*>(pProfRec + 1);
    }
    Frame* pFrame = apFrame;
    int* rem = (int*)(&apTarget + 1);
    Inner* in = pFrame->m_2C;
    int n = pFrame->m_30;
    if (n > 0)
    {
        int k = n;
        do
        {
            int iCount = in->m_20;
            int initial = in->m_24;
            in->m_28 = 0;
            *rem = initial;
            if (pFrame->m_20)
            {
                int r = hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_queryAabb(pFrame->m_20, in, rem, iCount);
                in->m_28 += r;
                iCount -= r;
            }
            if (pFrame->m_24)
            {
                int r = hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_queryAabb(pFrame->m_24, in, rem, iCount);
                in->m_28 += r;
                iCount -= r;
            }
            if (pFrame->m_28)
            {
                int r = hkKdTreeAabbQueryUtils_queryAabbIterative_00d1b930(pFrame->m_28, in, rem, iCount);
                in->m_28 += r;
            }
            in = (Inner*)((char*)in + 0x30);
        } while (--k);
    }
    pProfBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pProfBuf->m_end.m_storage < pProfBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pProfRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pProfBuf->m_end.m_storage);
        pProfRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        volatile DWORD dwTick2 = (DWORD)__rdtsc();
        pProfRec->m_time0 = dwTick2;
        pProfBuf->m_end.m_storage = reinterpret_cast<char*>(pProfRec + 1);
    }
    apTarget->ProcessCallback(pFrame, pFrame, 0);
}

extern "C" LocalM128 _mm_set_ps1(float a);
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_andnot_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_or_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_cmpeq_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_rcp_ps(LocalM128 a);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);

extern LocalM128 DAT_010c7170;  // (1,1,1,1)
extern float DAT_01267e30;   // zero vector (bss)
extern LocalM128 DAT_010cd670;  // HK_REAL_MAX x4

extern LocalM128 DAT_01268460[];
struct Vector4Comparison
{
    LocalM128 m_uiMask;
    __forceinline void set(int m)
    {
        m_uiMask = DAT_01268460[m];
    }
    __forceinline void setAnd(const Vector4Comparison& a, const Vector4Comparison& b)
    {
        m_uiMask = _mm_and_ps(a.m_uiMask, b.m_uiMask);
    }
    __forceinline int anyIsSet(int m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
};

__forceinline Vector4Comparison hkVector4::compareEqual4(const hkVector4& b) const
{ Vector4Comparison r; r.m_uiMask = _mm_cmpeq_ps(m_vComponents, b.m_vComponents); return r; }
__forceinline Vector4Comparison hkVector4::compareLessThan4(const hkVector4& b) const
{ Vector4Comparison r; r.m_uiMask = _mm_cmplt_ps(m_vComponents, b.m_vComponents); return r; }

__forceinline hkAabb::hkAabb() {}
__forceinline const LocalM128& hkVector4::getQuad() const { return m_vComponents; }
__forceinline void hkVector4::set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
__forceinline void hkVector4::SetAllComponents(float a) { m_vComponents = _mm_set_ps1(a); }
__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::add4(const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
__forceinline void hkVector4::sub4(const hkVector4& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
__forceinline void hkVector4::mul4(const hkVector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setBroadcast(const hkVector4& v, int i)
{
    if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    else if (i == 3) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
}
__forceinline float& hkVector4::operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
__forceinline void hkVector4::setReciprocal3(const hkVector4& a)
{
    LocalM128 input = _mm_shuffle_ps(a.m_vComponents, _mm_unpackhi_ps(a.m_vComponents, DAT_010c7170), 0xc4);
    LocalM128 estimate = _mm_rcp_ps(input);
    m_vComponents = _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, input), estimate));
}

static __forceinline void vectorSelect(hkVector4& out, const hkVector4& a, const hkVector4& b, const Vector4Comparison& m)
{ out.m_vComponents = _mm_or_ps(_mm_and_ps(m.m_uiMask, b.m_vComponents), _mm_andnot_ps(m.m_uiMask, a.m_vComponents)); }

struct RayQ
{
    hkVector4 m_kRayStart;
    hkVector4 m_vInverseDirection;
    __forceinline void init(const hkVector4& from, const hkVector4& to)
    {
        m_kRayStart = from;
        hkVector4 delta;
        delta.setSub4(to, from);
        Vector4Comparison zeros = delta.compareEqual4(*reinterpret_cast<const hkVector4*>(&DAT_01267e30));
        hkVector4 safe;
        vectorSelect(safe, delta, *reinterpret_cast<const hkVector4*>(&DAT_010c7170), zeros);
        hkVector4 inverse;
        inverse.setReciprocal3(safe);
        vectorSelect(m_vInverseDirection, inverse, *reinterpret_cast<const hkVector4*>(&DAT_010cd670), zeros);
    }
};

static __forceinline int rayHitsBounds(const hkAabb& bounds, const hkVector4& start, const hkVector4& invDir, const hkVector4& limit)
{
    hkVector4 lo;
    lo.setSub4(bounds.m_kMinimumCorner, start);
    lo.mul4(invDir);
    hkVector4 hi;
    hi.setSub4(bounds.m_kMaximumCorner, start);
    hi.mul4(invDir);
    hkVector4 nearT;
    nearT.setMin4(lo, hi);
    hkVector4 nz;
    nz.setBroadcast(nearT, 2);
    hkVector4 nX;
    nX.setMax4(nearT, *reinterpret_cast<const hkVector4*>(&DAT_01267e30));
    hkVector4 ny;
    ny.setBroadcast(nearT, 1);
    hkVector4 farT;
    farT.setMax4(lo, hi);
    hkVector4 afDepth;
    afDepth.setBroadcast(farT, 2);
    hkVector4 fX;
    fX.setMin4(farT, limit);
    hkVector4 nYZ;
    nYZ.setMax4(ny, nz);
    nX.setMax4(nX, nYZ);
    hkVector4 fy;
    fy.setBroadcast(farT, 1);
    hkVector4 fYZ;
    fYZ.setMin4(fy, afDepth);
    fX.setMin4(fX, fYZ);
    return nX.compareLessThan4(fX).anyIsSet(1);
}


struct TreeNode
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    int m_child0;
    int m_child1;
    unsigned int m_parent;
    int m_next;
};

struct TreeNodeArray
{
    TreeNode* ComputeValue_00d9a4c0(int index);
};

struct RayVisitor
{
    virtual void v00();
    virtual float processLeaf(const TreeNode* node);
};

struct NodeTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TreeNode* m_pTreeNode;
    int unk14;
    int unk18;
    TreeNodeArray m_kNodeCollection;
};

// Traverses the node tree, testing each node's AABB against a ray and calling visitor->processLeaf on hits to update the max fraction.
// @fnv 0x00d1d0b0
// src: GUESS 0x00d1d0b0 (confidence: medium)
void hkVector4_VisitRayIntersectedTreeLeaves(NodeTree* tree, const hkVector4* from, const hkVector4* to, RayVisitor* visitor,
                  float maxFraction)
{
    if (!tree)
        return;
    TreeNode* node = tree->m_pTreeNode;
    if (!node)
        return;

    hkVector4 fraction;
    fraction.m_vComponents = _mm_set_ps1(maxFraction);
    RayQ ray;
    ray.init(*from, *to);

    for (;;)
    {
        hkAabb bounds;
        bounds = *reinterpret_cast<const hkAabb*>(&node->m_kMinimumCorner);
        TreeNode* next;
        if (node->m_next != 0x7fffffff)
            next = tree->m_kNodeCollection.ComputeValue_00d9a4c0(node->m_next);
        else
            next = 0;

        if (rayHitsBounds(bounds, ray.m_kRayStart, ray.m_vInverseDirection, fraction))
        {
            if (!(node->m_parent & 0x80000000))
            {
                node = tree->m_kNodeCollection.ComputeValue_00d9a4c0(node->m_child0);
                continue;
            }
            float f = visitor->processLeaf(node);
            fraction.m_vComponents = _mm_set_ps1(f);
        }
        node = next;
        if (!node)
            break;
    }
}

extern "C" LocalM128 _mm_setr_ps(float, float, float, float);

extern LocalM128 DAT_01268460[];
extern const int DAT_010c92e0[4];

struct Bundle
{
    hkVector4 m_data[3];
};

struct RayQuerySet
{
    Bundle m_vFrom;
    Bundle m_vInverseDirection;
    int m_uiMask;
};

struct QuantizedAabb
{
    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];
};

struct Node16
{
    QuantizedAabb m_iBufferSize;
    unsigned short m_ausChildIndices[2];
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;
    __forceinline int isLeaf() const
    {
        return m_usNodeValue & 0x8000;
    }
};

struct IndexedNode16Collection
{
    int unk00;
    const Node16* GetEntryOffset(unsigned short idx) const;
};

struct hkAabbTree16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    IndexedNode16Collection m_kNodeManager;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_kAabbMin;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    hkVector4 m_kAabbInverseScale;
    __forceinline const Node16* getChild(const Node16* node, int i) const
    {
        return m_kNodeManager.GetEntryOffset(node->m_ausChildIndices[i]);
    }
    __forceinline const Node16* getSkipNode(const Node16* node) const
    {
        return (node->m_iSkipNodeIndex != 0x7fff) ? m_kNodeManager.GetEntryOffset(node->m_iSkipNodeIndex) : 0;
    }
};

struct Collector
{
    virtual ~Collector();
    virtual float GetHitDistance(const Node16* leaf);
};


struct RayQueryAabb : hkAabb
{
    __forceinline RayQueryAabb() {}
    __forceinline int overlaps(const RayQuerySet& ray, const hkVector4& ealyOutFractions,
                               Vector4Comparison& hitOut) const
    {
        hkVector4 max[3];
        max[0].setBroadcast(m_kMaximumCorner, 0);
        max[1].setBroadcast(m_kMaximumCorner, 1);
        max[2].setBroadcast(m_kMaximumCorner, 2);
        hkVector4 min[3];
        min[0].setBroadcast(m_kMinimumCorner, 0);
        min[1].setBroadcast(m_kMinimumCorner, 1);
        min[2].setBroadcast(m_kMinimumCorner, 2);
        Bundle dNear;
        Bundle dFar;
        for (int i = 0; i < 3; i++)
        {
            hkVector4 dNearTmp;
            hkVector4 dFarTmp;
            dNearTmp.setSub4(min[i], ray.m_vFrom.m_data[i]);
            dFarTmp.setSub4(max[i], ray.m_vFrom.m_data[i]);
            dNearTmp.mul4(ray.m_vInverseDirection.m_data[i]);
            dFarTmp.mul4(ray.m_vInverseDirection.m_data[i]);
            dNear.m_data[i].setMin4(dNearTmp, dFarTmp);
            dFar.m_data[i].setMax4(dNearTmp, dFarTmp);
        }
        hkVector4 maxNear;
        hkVector4 minFar;
        maxNear.setMax4(dNear.m_data[0], dNear.m_data[1]);
        maxNear.setMax4(maxNear, dNear.m_data[2]);
        maxNear.setMax4(maxNear, *reinterpret_cast<const hkVector4*>(&DAT_01267e30));
        minFar.setMin4(dFar.m_data[0], dFar.m_data[1]);
        minFar.setMin4(minFar, dFar.m_data[2]);
        minFar.setMin4(minFar, ealyOutFractions);
        hitOut.set(ray.m_uiMask);
        Vector4Comparison lt;
        lt.m_uiMask = _mm_cmplt_ps(maxNear.m_vComponents, minFar.m_vComponents);
        hitOut.setAnd(lt, hitOut);

        return hitOut.anyIsSet(ray.m_uiMask);
    }
};


static __forceinline void restoreAabb(const QuantizedAabb& in, const hkVector4& bitScaleInv,
                                      const hkVector4& bitOffsetLow, hkAabb& out)
{
    out.m_kMaximumCorner.set((float)(in.m_kMaximumCorner[0] << 15), (float)(in.m_kMaximumCorner[1] << 15),
                             (float)(in.m_kMaximumCorner[2] << 15));
    out.m_kMinimumCorner.set((float)(in.m_kMinimumCorner[0] << 15), (float)(in.m_kMinimumCorner[1] << 15),
                             (float)(in.m_kMinimumCorner[2] << 15));

    out.m_kMinimumCorner.mul4(bitScaleInv);
    out.m_kMaximumCorner.mul4(bitScaleInv);
    out.m_kMinimumCorner.sub4(bitOffsetLow);
    out.m_kMaximumCorner.sub4(bitOffsetLow);
}

// Walks the AABB tree from node to escapeNode, testing each node's bounds against the ray and updating collector hit distances on leaf overlaps.
// @fnv 0x00d1bfa0
// src: GUESS 0x00d1bfa0 (confidence: medium)
void Object_CollectRayTreeHits(const hkAabbTree16* tree, const Node16* apStartNode, const Node16* escapeNode,
                  const RayQuerySet& rayBundle, Collector* const* appCollectors, const float* apEarlyOutFractions)
{
    hkVector4 earlyOut;
    earlyOut.set(apEarlyOutFractions[0], apEarlyOutFractions[1], apEarlyOutFractions[2], apEarlyOutFractions[3]);

    const hkVector4& bitScaleInv = tree->m_kAabbInverseScale;
    const hkVector4& bitOffsetLow = tree->m_kAabbMin;

    while (1)
    {
        RayQueryAabb aabb;
        restoreAabb(apStartNode->m_iBufferSize, bitScaleInv, bitOffsetLow, aabb);

        const Node16* next = tree->getSkipNode(apStartNode);

        Vector4Comparison hits;
        if (aabb.overlaps(rayBundle, earlyOut, hits))
        {
            if (!apStartNode->isLeaf())
            {
                apStartNode = tree->getChild(apStartNode, 0);
                continue;
            }
            for (int ir = 0; ir < 4; ir++)
            {
                if (hits.anyIsSet(DAT_010c92e0[ir]))
                {
                    earlyOut(ir) = appCollectors[ir]->GetHitDistance(apStartNode);
                }
            }
        }

        if (next == escapeNode)
            break;
        apStartNode = next;
    }
}

extern "C" LocalM128 _mm_setr_ps(float, float, float, float);

struct S1c2b0_Cmp
{
    LocalM128 m_uiMask;
    __forceinline int anyIsSet(int m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
};

// This existing helper returns vectors from setSub4/setMin4/setMax4. The shared
// API returns void; merging it changes the code at 0x00d1bd00.
struct hkVector4Real
{
    LocalM128 m_vComponents;
    __forceinline hkVector4Real& operator=(const hkVector4Real& v)
    { m_vComponents = v.m_vComponents; return *this; }
    __forceinline const LocalM128& getQuad() const { return m_vComponents; }
    __forceinline void set(float a, float b, float c, float d = 0.0f)
    { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline void SetAllComponents(float a) { m_vComponents = _mm_set_ps1(a); }
    __forceinline void setAdd4(const hkVector4Real& a, const hkVector4Real& b)
    { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void add4(const hkVector4Real& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void sub4(const hkVector4Real& v) { m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(const hkVector4Real& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline hkVector4Real setSub4(const hkVector4Real& a, const hkVector4Real& b)
    { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); return *this; }
    __forceinline hkVector4Real setMin4(const hkVector4Real& a, const hkVector4Real& b)
    { m_vComponents = _mm_min_ps(a.getQuad(), b.getQuad()); return *this; }
    __forceinline hkVector4Real setMax4(const hkVector4Real& a, const hkVector4Real& b)
    { m_vComponents = _mm_max_ps(a.getQuad(), b.getQuad()); return *this; }
    __forceinline hkVector4Real& setBroadcast(const hkVector4Real& v, int i)
    {
        if (i == 0) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        else if (i == 1) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        else m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        return *this;
    }
    __forceinline S1c2b0_Cmp compareEqual4(const hkVector4Real& a) const
    { S1c2b0_Cmp m; m.m_uiMask = _mm_cmpeq_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline S1c2b0_Cmp compareLessThan4(const hkVector4Real& a) const
    { S1c2b0_Cmp m; m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents); return m; }
    __forceinline hkVector4Real& select32(const hkVector4Real& a, const hkVector4Real& b, const S1c2b0_Cmp& comp)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(comp.m_uiMask, b.m_vComponents), _mm_andnot_ps(comp.m_uiMask, a.m_vComponents));
        return *this;
    }
    __forceinline hkVector4Real& setReciprocal3(const hkVector4Real& a)
    {
        LocalM128 input = _mm_shuffle_ps(a.m_vComponents, _mm_unpackhi_ps(a.m_vComponents, DAT_010c7170), 0xc4);
        LocalM128 estimate = _mm_rcp_ps(input);
        m_vComponents = _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, input), estimate));
        return *this;
    }
};

struct hkpCompressedNode
{
    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];
    unsigned short m_pChildAtom;
    unsigned short m_unk0e;
    unsigned short m_flags;
    unsigned short m_skip;
};

struct NodeArray
{
    hkpCompressedNode* m_data;
    const hkpCompressedNode* GetEntryOffset(unsigned short index);
};

struct CompressedTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    const hkpCompressedNode* m_pTreeNode;
    int unk14;
    int unk18;
    NodeArray m_kNodeCollection;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4Real m_kAabbMin;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    hkVector4Real m_kAabbInverseScale;
};

struct SweptBoxQuery
{
    hkVector4Real m_vFrom;
    hkVector4Real m_vTo;
    hkVector4Real m_vHalfExtents;
};

struct LeafCollector
{
    virtual void unk00();
    virtual float GetHitDistance(const hkpCompressedNode* node);
};

struct S1c2b0_Ray
{
    hkVector4Real m_kRayStart;
    hkVector4Real m_vInverseDirection;
    __forceinline void setRay(const hkVector4Real& start, const hkVector4Real& end)
    {
        m_kRayStart = start;
        hkVector4Real delta;
        delta.m_vComponents = _mm_sub_ps(end.m_vComponents, start.m_vComponents);
        S1c2b0_Cmp isZero = delta.compareEqual4(*reinterpret_cast<const hkVector4Real*>(&DAT_01267e30));
        hkVector4Real maskedDelta;
        maskedDelta.select32(delta, *reinterpret_cast<const hkVector4Real*>(&DAT_010c7170), isZero);
        hkVector4Real invDelta;
        invDelta.setReciprocal3(maskedDelta);
        m_vInverseDirection.select32(invDelta, *reinterpret_cast<const hkVector4Real*>(&DAT_010cd670), isZero);
    }
};

static __forceinline int compressedRayOverlapsBounds(const hkAabb& bounds, const S1c2b0_Ray& r, const hkVector4Real& earlyOutHitFraction)
{
    hkVector4Real dNearTemp;
    hkVector4Real dFarTemp;
    dNearTemp.setSub4(reinterpret_cast<const hkVector4Real&>(bounds.m_kMinimumCorner), r.m_kRayStart);
    dFarTemp.setSub4(reinterpret_cast<const hkVector4Real&>(bounds.m_kMaximumCorner), r.m_kRayStart);
    dNearTemp.mul4(r.m_vInverseDirection);
    dFarTemp.mul4(r.m_vInverseDirection);
    hkVector4Real dNear;
    dNear.setMin4(dNearTemp, dFarTemp);
    hkVector4Real dFar;
    dFar.setMax4(dNearTemp, dFarTemp);
    hkVector4Real dNearY;
    dNearY.setBroadcast(dNear, 1);
    hkVector4Real dNearZ;
    dNearZ.setBroadcast(dNear, 2);
    hkVector4Real dFarY;
    dFarY.setBroadcast(dFar, 1);
    hkVector4Real dFarZ;
    dFarZ.setBroadcast(dFar, 2);
    hkVector4Real nearYZ;
    nearYZ.setMax4(dNearY, dNearZ);
    hkVector4Real farYZ;
    farYZ.setMin4(dFarY, dFarZ);
    hkVector4Real nearX;
    nearX.setMax4(dNear, *reinterpret_cast<const hkVector4Real*>(&DAT_01267e30));
    hkVector4Real farX;
    farX.setMin4(dFar, earlyOutHitFraction);
    nearX.setMax4(nearX, nearYZ);
    farX.setMin4(farX, farYZ);
    S1c2b0_Cmp nearLtFar = nearX.compareLessThan4(farX);
    return nearLtFar.anyIsSet(1);
}


static __forceinline void restoreAabb(const hkpCompressedNode& in, const hkVector4Real& bitScaleInv,
                                      const hkVector4Real& bitOffsetLow, hkAabb& out)
{
    reinterpret_cast<hkVector4Real&>(out.m_kMaximumCorner).set((float)(in.m_kMaximumCorner[0] << 15), (float)(in.m_kMaximumCorner[1] << 15),
                             (float)(in.m_kMaximumCorner[2] << 15));
    reinterpret_cast<hkVector4Real&>(out.m_kMinimumCorner).set((float)(in.m_kMinimumCorner[0] << 15), (float)(in.m_kMinimumCorner[1] << 15),
                             (float)(in.m_kMinimumCorner[2] << 15));
    reinterpret_cast<hkVector4Real&>(out.m_kMinimumCorner).mul4(bitScaleInv);
    reinterpret_cast<hkVector4Real&>(out.m_kMaximumCorner).mul4(bitScaleInv);
    reinterpret_cast<hkVector4Real&>(out.m_kMinimumCorner).sub4(bitOffsetLow);
    reinterpret_cast<hkVector4Real&>(out.m_kMaximumCorner).sub4(bitOffsetLow);
}

static __forceinline hkVector4Real expandedValue(const hkVector4Real& a, const hkVector4Real& b)
{
    hkVector4Real out;
    out.setAdd4(a, b);
    return out;
}
static __forceinline LocalM128 expandedQuad(LocalM128 a, LocalM128 b)
{
    return _mm_add_ps(a, b);
}
static __forceinline void expandedRef(hkVector4Real& out, const hkVector4Real& a, const hkVector4Real& b)
{
    out.setAdd4(a, b);
}
static __forceinline void expandedVal(hkVector4Real& out, LocalM128 a, LocalM128 b)
{
    out.m_vComponents = _mm_add_ps(a, b);
}

// Traverses a compressed tree to find nodes overlapping a swept box, collecting leaf hits or reporting hit distances via a collector.
// @fnv 0x00d1c2b0
// src: XBOX_PDB 0x00d1c2b0
int hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castAabb(CompressedTree* tree, int aabb, const SweptBoxQuery* apQuery, LeafCollector* collector, float radius,
                 int* hits, int capacity)
{
    if (!tree)
        return 0;
    const hkpCompressedNode* node = tree->m_pTreeNode;
    if (!node)
        return 0;

    hkAabb box;
    reinterpret_cast<hkVector4Real&>(box.m_kMaximumCorner) = *reinterpret_cast<const hkVector4Real*>(&DAT_01267e30);
    S1c2b0_Ray ray;
    ray.setRay(apQuery->m_vFrom, apQuery->m_vTo);

    hkVector4Real extents;
    extents.SetAllComponents(radius);
    extents.add4(apQuery->m_vHalfExtents);

    const hkVector4Real& bitScaleInv = tree->m_kAabbInverseScale;
    const hkVector4Real& bitOffsetLow = tree->m_kAabbMin;

    hkVector4Real earlyOut;
    earlyOut.SetAllComponents(1.0f);
    int numHits = 0;

    for (;;)
    {
        hkAabb decoded;
        restoreAabb(*node, bitScaleInv, bitOffsetLow, decoded);
        box.m_kMaximumCorner.m_vComponents = _mm_add_ps(decoded.m_kMaximumCorner.m_vComponents, extents.m_vComponents);
        reinterpret_cast<hkVector4Real&>(box.m_kMinimumCorner).setSub4(
            reinterpret_cast<const hkVector4Real&>(decoded.m_kMinimumCorner), extents);

        const hkpCompressedNode* next;
        if (node->m_skip != 0x7fff)
            next = tree->m_kNodeCollection.GetEntryOffset(node->m_skip);
        else
            next = 0;

        if (compressedRayOverlapsBounds(box, ray, earlyOut))
        {
            if ((node->m_flags & 0x8000) == 0)
            {
                node = tree->m_kNodeCollection.GetEntryOffset(node->m_pChildAtom);
                continue;
            }
            if (collector)
            {
                earlyOut.SetAllComponents(collector->GetHitDistance(node));
            }
            else if (hits)
            {
                *hits++ = *(const int*)&node->m_pChildAtom;
                if (numHits >= capacity)
                    return numHits;
            }
            numHits++;
        }

        node = next;
        if (!node)
            break;
    }
    return numHits;
}

static __forceinline Vector4Comparison queryLessEqual(const hkVector4& a, const hkVector4& b)
{
    Vector4Comparison r;
    r.m_uiMask = _mm_cmple_ps(a.m_vComponents, b.m_vComponents);
    return r;
}

static __forceinline int queryBoundsOverlap(const hkAabb& bounds, const hkAabb& other)
{
    Vector4Comparison mincomp = queryLessEqual(bounds.m_kMinimumCorner, other.m_kMaximumCorner);
    Vector4Comparison maxcomp = queryLessEqual(other.m_kMinimumCorner, bounds.m_kMaximumCorner);
    Vector4Comparison both;
    both.setAnd(mincomp, maxcomp);
    return ((_mm_movemask_ps(both.m_uiMask) & 7) == 7);
}


struct QueryBounds16
{
    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];

    __forceinline static void restoreAabb(const QueryBounds16& in, const hkVector4& bitScaleInv,
                                          const hkVector4& bitOffsetLow, hkAabb& out)
    {
        out.m_kMaximumCorner.set((float)(in.m_kMaximumCorner[0] << 15), (float)(in.m_kMaximumCorner[1] << 15),
                                 (float)(in.m_kMaximumCorner[2] << 15));
        out.m_kMinimumCorner.set((float)(in.m_kMinimumCorner[0] << 15), (float)(in.m_kMinimumCorner[1] << 15),
                                 (float)(in.m_kMinimumCorner[2] << 15));
        out.m_kMinimumCorner.mul4(bitScaleInv);
        out.m_kMaximumCorner.mul4(bitScaleInv);
        out.m_kMinimumCorner.sub4(bitOffsetLow);
        out.m_kMaximumCorner.sub4(bitOffsetLow);
    }
};

class QueryNode
{
  public:
    static const unsigned short s_leafMask = 0x7fff;
    static const unsigned short s_leafFlag = 0x8000;
    QueryBounds16 m_iBufferSize;
    union
    {
        struct
        {
            unsigned short m_ausChildIndices[2];
        } m_kChildIndices;
        struct
        {
            void* m_ulUserData;
        } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;

    __forceinline int isLeaf() const
    {
        return m_usNodeValue & s_leafFlag;
    }
    template <typename T> __forceinline T getLeafData() const
    {
        T r = (T)m_kLeafData.m_ulUserData;
        return r;
    }
};

class QueryNodeManager
{
  public:
    QueryNode* GetEntryOffset(unsigned short idx);
    int m_kNodeCollection;
};

class QueryTree16
{
  public:
    static const unsigned short s_invalidIdx = 0x7fff;
    __forceinline QueryNode* getRootNode() const
    {
        return m_pAabbRootNode;
    }
    __forceinline QueryNode* getChild(const QueryNode* node, int i) const
    {
        return const_cast<QueryNodeManager&>(m_kNodeManager).GetEntryOffset(node->m_kChildIndices.m_ausChildIndices[i]);
    }
    __forceinline QueryNode* getSkipNode(const QueryNode* node) const
    {
        return (node->m_iSkipNodeIndex != s_invalidIdx)
                   ? const_cast<QueryNodeManager&>(m_kNodeManager).GetEntryOffset(node->m_iSkipNodeIndex)
                   : 0;
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    QueryNode* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    QueryNodeManager m_kNodeManager;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4 m_kAabbMin;
    hkVector4 m_kAabbMaximum;
    hkVector4 m_kAabbScale;
    hkVector4 m_kAabbInverseScale;
};

static __forceinline const QueryNode* treeGetNode(const QueryNode* readNodePpu, int dmaIdx = 0,
                                                  bool RunWorkerThread = true)
{
    return readNodePpu;
}

struct AabbCollector
{
    virtual void v0();
    virtual float GetHitDistance(const QueryNode* node);
};

typedef hkArray<void*> VoidArray;
template<> __forceinline void hkArrayBase<void*>::_pushBack(hkMemoryAllocator& sharedAlloc, void* const& e)
{
hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(sharedAlloc);

        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(void*));
        hkConstructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    
}


// Traverses a QueryTree16, tests node bounds against the query AABB, and reports overlapping leaf hits through a collector, iterator, or array.
// @fnv 0x00d1c560
// src: GUESS 0x00d1c560 (confidence: medium)
int __cdecl Object_CollectAABBTreeHits(const QueryTree16* tree, const hkAabb& apQueryAabb, AabbCollector* collector,
                         VoidArray* hitArray, void*** appHitIter, int hitCapacity)
{
    const QueryNode* rootNode = tree->getRootNode();
    const QueryNode* node = treeGetNode(rootNode);
    if (!node)
        return 0;

    const hkVector4& bitScaleInv = tree->m_kAabbInverseScale;
    const hkVector4& bitOffsetLow = tree->m_kAabbMin;

    int iHits = 0;
    int iVisited = 0;

    if (collector)
    {
        while (1)
        {
            hkAabb nodeAabb;
            QueryBounds16::restoreAabb(node->m_iBufferSize, bitScaleInv, bitOffsetLow, nodeAabb);
            const QueryNode* skipNode = tree->getSkipNode(node);
            iVisited++;
            if (queryBoundsOverlap(nodeAabb, apQueryAabb))
            {
                if (!node->isLeaf())
                {
                    node = treeGetNode(tree->getChild(node, 0));
                    continue;
                }
                if (collector->GetHitDistance(node) == 0.0f)
                    break;
                iHits++;
            }
            node = treeGetNode(skipNode);
            if (node)
                continue;
            break;
        }
    }
    else if (appHitIter)
    {
        while (1)
        {
            hkAabb nodeAabb;
            QueryBounds16::restoreAabb(node->m_iBufferSize, bitScaleInv, bitOffsetLow, nodeAabb);
            const QueryNode* skipNode = tree->getSkipNode(node);
            iVisited++;
            if (queryBoundsOverlap(nodeAabb, apQueryAabb))
            {
                if (!node->isLeaf())
                {
                    node = treeGetNode(tree->getChild(node, 0));
                    continue;
                }
                **appHitIter = node->getLeafData<void*>();
                (*appHitIter)++;
                if (iHits >= hitCapacity)
                    break;
                iHits++;
            }
            node = treeGetNode(skipNode);
            if (node)
                continue;
            break;
        }
    }
    else if (hitArray)
    {
        while (1)
        {
            hkAabb nodeAabb;
            QueryBounds16::restoreAabb(node->m_iBufferSize, bitScaleInv, bitOffsetLow, nodeAabb);
            const QueryNode* skipNode = tree->getSkipNode(node);
            iVisited++;
            if (queryBoundsOverlap(nodeAabb, apQueryAabb))
            {
                if (!node->isLeaf())
                {
                    node = treeGetNode(tree->getChild(node, 0));
                    continue;
                }
                hitArray->pushBack(node->getLeafData<void*>());
                iHits++;
            }
            node = treeGetNode(skipNode);
            if (node)
                continue;
            break;
        }
    }
    return iHits;
}

extern "C" LocalM128 _mm_load_ps(const float*);

struct ScalarQuad
{
    float x, y, z, w;
};
union QuadStorage
{
    ScalarQuad scalar;
    LocalM128 simd;
};

// Traverses the compressed tree, restores each node's AABB, and calls GetHitDistance for leaves overlapping the ray within maxDistance.
// @fnv 0x00d1bd00
// src: XBOX_PDB 0x00d1bd00
void hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_castRay(CompressedTree* tree, const LocalM128* from, const LocalM128* to, LeafCollector* collector,
                  float maxDistance)
{
    if (!tree)
        return;
    const hkpCompressedNode* node = tree->m_pTreeNode;
    if (!node)
        return;

    hkVector4Real maxT;
    maxT.SetAllComponents(maxDistance);
    S1c2b0_Ray ray;
    ray.setRay(*reinterpret_cast<const hkVector4Real*>(from), *reinterpret_cast<const hkVector4Real*>(to));

    QuadStorage scale;
    scale.scalar = reinterpret_cast<const ScalarQuad&>(tree->m_kAabbInverseScale);

    QuadStorage offset;
    offset.scalar = reinterpret_cast<const ScalarQuad&>(tree->m_kAabbMin);

    for (;;)
    {
        hkAabb bounds;
        restoreAabb(*node, *reinterpret_cast<const hkVector4Real*>(&scale),
                    *reinterpret_cast<const hkVector4Real*>(&offset), bounds);

        const hkpCompressedNode* next;
        if (node->m_skip != 0x7fff)
            next = tree->m_kNodeCollection.GetEntryOffset(node->m_skip);
        else
            next = 0;

        if (compressedRayOverlapsBounds(bounds, ray, maxT))
        {
            if ((node->m_flags & 0x8000) == 0)
            {
                node = tree->m_kNodeCollection.GetEntryOffset(node->m_pChildAtom);
                continue;
            }
            maxT.SetAllComponents(collector->GetHitDistance(node));
        }
        node = next;
        if (!node)
            break;
    }
}

struct NodesSV_1cc50
{
    int* GetElementAddress_00d1bb40(unsigned short index);
};

struct TNodeQ
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    unsigned int m_data;
    unsigned short m_flags;
    unsigned short m_next;
};

struct NTreeQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TNodeQ* m_pTreeNode;
    int unk14;
    int unk18;
    NodesSV_1cc50 m_kNodeCollection;
};

struct RayCollector
{
    virtual void v00();
    virtual float GetHitDistance(const TNodeQ* node);
};

__forceinline LocalM128 inverseDir(LocalM128 dir)
{
    LocalM128 isZero = _mm_cmpeq_ps(*reinterpret_cast<const LocalM128*>(&DAT_01267e30), dir);
    LocalM128 safe = _mm_or_ps(_mm_and_ps(isZero, DAT_010c7170), _mm_andnot_ps(isZero, dir));
    safe = _mm_shuffle_ps(safe, _mm_unpackhi_ps(safe, DAT_010c7170), 0xc4);
    LocalM128 r = _mm_rcp_ps(safe);
    LocalM128 inv = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, safe), r));
    return _mm_or_ps(_mm_andnot_ps(isZero, inv), _mm_and_ps(isZero, DAT_010cd670));
}
struct RayDir
{
    hkVector4 m_dir;
    hkVector4 m_vInverseDirection;
};


struct RayInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkVector4 m_fExtents;
};

// Traverses tree nodes, tests each AABB against the ray, and reports leaf hits through the collector or output buffer.
// @fnv 0x00d1cc50
// src: XBOX_PDB 0x00d1cc50
int hkAabbTreeQueryUtils_hkAabbTreeData_hkAabbTreeAabb_unsigned_short_castAabb(NTreeQ* tree, void* unused, const RayInput* ray, RayCollector* collector, float radius,
                 unsigned int* out, int maxCount)
{
    if (!tree)
        return 0;
    TNodeQ* node = tree->m_pTreeNode;
    if (!node)
        return 0;

    LocalM128 from = ray->m_vFrom.m_vComponents;
    hkAabb aabb;
    aabb.m_kMaximumCorner.m_vComponents = from;
    RayDir kRayDir;
    kRayDir.m_dir.m_vComponents = _mm_sub_ps(ray->m_vTo.m_vComponents, from);
    LocalM128 dir = kRayDir.m_dir.m_vComponents;
    kRayDir.m_vInverseDirection.m_vComponents = inverseDir(dir);
    LocalM128 vExtent = _mm_add_ps(_mm_set_ps1(radius), ray->m_fExtents.m_vComponents);
    LocalM128 fraction = _mm_set_ps1(1.0f);

    int count = 0;
    for (;;)
    {
        aabb.m_kMinimumCorner.m_vComponents = node->m_kMinimumCorner.m_vComponents;
        aabb.m_kMaximumCorner.m_vComponents = node->m_kMaximumCorner.m_vComponents;
        aabb.m_kMaximumCorner.m_vComponents = _mm_add_ps(aabb.m_kMaximumCorner.m_vComponents, vExtent);
        aabb.m_kMinimumCorner.m_vComponents = _mm_sub_ps(aabb.m_kMinimumCorner.m_vComponents, vExtent);
        TNodeQ* next;
        if (node->m_next != 0x7fff)
            next = (TNodeQ*)tree->m_kNodeCollection.GetElementAddress_00d1bb40(node->m_next);
        else
            next = 0;

        aabb.m_kMinimumCorner.m_vComponents = _mm_sub_ps(aabb.m_kMinimumCorner.m_vComponents, from);
        aabb.m_kMaximumCorner.m_vComponents = _mm_sub_ps(aabb.m_kMaximumCorner.m_vComponents, from);
        aabb.m_kMaximumCorner.m_vComponents =
            _mm_mul_ps(aabb.m_kMaximumCorner.m_vComponents, kRayDir.m_vInverseDirection.m_vComponents);
        aabb.m_kMinimumCorner.m_vComponents =
            _mm_mul_ps(aabb.m_kMinimumCorner.m_vComponents, kRayDir.m_vInverseDirection.m_vComponents);
        LocalM128 vNearT = _mm_min_ps(aabb.m_kMinimumCorner.m_vComponents, aabb.m_kMaximumCorner.m_vComponents);
        LocalM128 vFarT = _mm_max_ps(aabb.m_kMinimumCorner.m_vComponents, aabb.m_kMaximumCorner.m_vComponents);
        LocalM128 vExitT = _mm_min_ps(_mm_min_ps(vFarT, fraction),
                                   _mm_min_ps(_mm_shuffle_ps(vFarT, vFarT, 0x55), _mm_shuffle_ps(vFarT, vFarT, 0xaa)));
        LocalM128 vEnterT =
            _mm_max_ps(_mm_max_ps(vNearT, *reinterpret_cast<const LocalM128*>(&DAT_01267e30)),
                       _mm_max_ps(_mm_shuffle_ps(vNearT, vNearT, 0x55), _mm_shuffle_ps(vNearT, vNearT, 0xaa)));
        if (_mm_movemask_ps(_mm_cmplt_ps(vEnterT, vExitT)) & 1)
        {
            if (!(node->m_flags & 0x8000))
            {
                node = (TNodeQ*)tree->m_kNodeCollection.GetElementAddress_00d1bb40((unsigned short)node->m_data);
                continue;
            }
            if (collector)
            {
                float f = collector->GetHitDistance(node);
                fraction = _mm_set_ps1(f);
            }
            else if (out)
            {
                *out++ = node->m_data;
                if (count >= maxCount)
                    return count;
            }
            count++;
        }
        node = next;
        if (!node)
            break;
    }
    return count;
}

struct NodeMgrSV
{
    int* GetElementAddress_00d1bb40(unsigned short index);
};
__forceinline void FilterRays_filterSetAll(hkVector4& out, float x)
{
    out.m_vComponents = _mm_set_ps1(x);
}

struct FilterRays_Ray
{
    hkVector4 m_kRayStart;
    hkVector4 m_vInverseDirection;
};

class FilterRays_FilterAabb : public hkAabb
{
public:
    __forceinline FilterRays_FilterAabb() {}
    __forceinline int overlapsLeaf(const FilterRays_Ray& r, const hkVector4& earlyOutHitFraction) const
    {
        LocalM128 dNearTemp = _mm_sub_ps(m_kMinimumCorner.m_vComponents, r.m_kRayStart.m_vComponents);
        LocalM128 dFarTemp = _mm_sub_ps(m_kMaximumCorner.m_vComponents, r.m_kRayStart.m_vComponents);
        dNearTemp = _mm_mul_ps(dNearTemp, r.m_vInverseDirection.m_vComponents);
        dFarTemp = _mm_mul_ps(dFarTemp, r.m_vInverseDirection.m_vComponents);
        LocalM128 dNear = _mm_min_ps(dNearTemp, dFarTemp);
        LocalM128 dFar = _mm_max_ps(dNearTemp, dFarTemp);
        LocalM128 dNearY = _mm_shuffle_ps(dNear, dNear, 0x55);
        LocalM128 dNearZ = _mm_shuffle_ps(dNear, dNear, 0xaa);
        LocalM128 dFarY = _mm_shuffle_ps(dFar, dFar, 0x55);
        LocalM128 dFarZ = _mm_shuffle_ps(dFar, dFar, 0xaa);
        LocalM128 nearYZ = _mm_max_ps(dNearY, dNearZ);
        LocalM128 farYZ = _mm_min_ps(dFarY, dFarZ);
        LocalM128 nearX = _mm_max_ps(dNear, *reinterpret_cast<const LocalM128*>(&DAT_01267e30));
        LocalM128 farX = _mm_min_ps(dFar, earlyOutHitFraction.m_vComponents);
        nearX = _mm_max_ps(nearX, nearYZ);
        farX = _mm_min_ps(farX, farYZ);
        return _mm_movemask_ps(_mm_cmplt_ps(nearX, farX)) & 1;
    }
    __forceinline static void restoreAabb(const hkAabb& in, const hkVector4& bitScaleInv,
                                         const hkVector4& bitOffsetLow, FilterRays_FilterAabb& out)
    {
        static_cast<hkAabb&>(out) = in;
    }
};


static __forceinline bool filterRayOverlapsBounds(const hkAabb& bounds, const FilterRays_Ray& r,
                                                const hkVector4& earlyOutHitFraction)
{
    LocalM128 dNearTemp = _mm_sub_ps(bounds.m_kMinimumCorner.m_vComponents, r.m_kRayStart.m_vComponents);
    LocalM128 dFarTemp = _mm_sub_ps(bounds.m_kMaximumCorner.m_vComponents, r.m_kRayStart.m_vComponents);
    dNearTemp = _mm_mul_ps(dNearTemp, r.m_vInverseDirection.m_vComponents);
    dFarTemp = _mm_mul_ps(dFarTemp, r.m_vInverseDirection.m_vComponents);
    LocalM128 dNear = _mm_min_ps(dNearTemp, dFarTemp);
    LocalM128 dFar = _mm_max_ps(dNearTemp, dFarTemp);
    LocalM128 dNearY = _mm_shuffle_ps(dNear, dNear, 0x55);
    LocalM128 dNearZ = _mm_shuffle_ps(dNear, dNear, 0xaa);
    LocalM128 dFarY = _mm_shuffle_ps(dFar, dFar, 0x55);
    LocalM128 dFarZ = _mm_shuffle_ps(dFar, dFar, 0xaa);
    LocalM128 nearYZ = _mm_max_ps(dNearY, dNearZ);
    LocalM128 farYZ = _mm_min_ps(dFarY, dFarZ);
    LocalM128 nearX = _mm_max_ps(dNear, *reinterpret_cast<const LocalM128*>(&DAT_01267e30));
    LocalM128 farX = _mm_min_ps(dFar, earlyOutHitFraction.m_vComponents);
    nearX = _mm_max_ps(nearX, nearYZ);
    farX = _mm_min_ps(farX, farYZ);
    return _mm_movemask_ps(_mm_cmplt_ps(nearX, farX)) & 1;
}

struct FilterRays_Node
{
    hkAabb m_iBufferSize;
    unsigned short m_ausChildIndices[2];
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;

    __forceinline int isLeaf() const
    {
        return m_usNodeValue & 0x8000;
    }
    void CopyFrom(int* other);
};

struct FilterRays_Tree
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_00d1bb40_Class m_kNodeManager;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    hkVector4 m_kAabbMin;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    hkVector4 m_kAabbInverseScale;
    __forceinline int* getChild(const FilterRays_Node* node, int i) const
    {
        return ((NodeMgrSV*)&m_kNodeManager)->GetElementAddress_00d1bb40(node->m_ausChildIndices[i]);
    }
};

struct RayCastRequest
{
    hkVector4 m_vFrom, m_vTo;
    int m_uiFilterInfo, m_bEnableShapeCollectionFilter;
    int unk28, unk2c;
    int m_pResultBuffer;
    int m_iResultCount;
    int m_iResultCapacity;
    unsigned char m_useFilterCollector;
};

extern int DAT_011b3830[5];
extern void* DAT_0126ec04;
void Runtime_ProcessEntries_00e2b9b0();
void __cdecl setCollector(hkCpuWorldRayCastCollector* collector, const RayCastRequest* command,
                          const void* filter);
RayQuerySet __cdecl hkVector4_UpdateState_00e2baf0(const hkVector4& s0, const hkVector4& e0, const hkVector4& s1, const hkVector4& e1,
                                 const hkVector4& s2, const hkVector4& e2, const hkVector4& s3, const hkVector4& e3,
                                 int mask);
void __cdecl Object_ProcessEntries_00d1ca00(const FilterRays_Tree* tree, const FilterRays_Node* node, const void* skipNode,
                          const RayQuerySet* bundle, hkAabbTreeQueryUtils<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Collector** collectors, float* fractions);

template <class T> __forceinline T FilterRays_min2(T x, T y)
{
    return x < y ? x : y;
}

__forceinline void FilterRays_registerAddRayHit(void (*f)())
{
    DAT_0126ec04 = (void*)f;
}

// Tests each ray against a leaf AABB, or partitions ray indices by the two child AABBs.
// @fnv 0x00e2bbd0
// src: GUESS 0x00e2bbd0 (confidence: medium)
void __cdecl hkCpuWorldRayCastCollector_PartitionRaysByChildBounds(const FilterRays_Tree* tree, const FilterRays_Node* node, const void* skipNode,
                          const FilterRays_Ray* rays, hkCpuWorldRayCastCollector* collectors,
                          hkpFixedBufferRayHitCollector* fixedBufferFilterCollectors,
                          const RayCastRequest* commandArray, const void* filter, float* earlyHitFractionArray,
                          int* raysIdx, int numRays, int taskCap, int raysIdxOutCap0, int raysIdxOutCap1,
                          int* raysIdxOut0, int& numRaysOut0, int* raysIdxOut1, int& numRaysOut1,
                          FilterRays_Node& child0Out, FilterRays_Node& child1Out)
{
    numRaysOut1 = 0;
    numRaysOut0 = 0;
    if (node->isLeaf())
    {
        FilterRays_FilterAabb aabb;
        FilterRays_FilterAabb::restoreAabb(node->m_iBufferSize, tree->m_kAabbInverseScale, tree->m_kAabbMin, aabb);
        for (int i = 0; i < numRays; i++)
        {
            int idx = raysIdx[i];
            hkCpuWorldRayCastCollector* collector = collectors;
            hkVector4 earlyOut;
            FilterRays_filterSetAll(earlyOut, 1.0f);
            if (aabb.overlapsLeaf(rays[idx], earlyOut))
            {
                setCollector(collector, commandArray + idx, filter);
                collector->GetHitDistance(reinterpret_cast<const hkAabbTree<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Node*>(node));
            }
        }
    }
    else if (raysIdxOutCap0 >= numRays && raysIdxOutCap1 >= numRays && taskCap >= 2 && numRays > 4)
    {
        int* child1 = tree->getChild(node, 1);
        child0Out.CopyFrom(tree->getChild(node, 0));
        child1Out.CopyFrom(child1);
        hkAabb aabb0;
        hkAabb aabb1;
        aabb0 = child0Out.m_iBufferSize;
        aabb1 = child1Out.m_iBufferSize;
        hkVector4 earlyOut;
        FilterRays_filterSetAll(earlyOut, 1.0f);
        for (int i = 0; i < numRays; i++)
        {
            int idx = raysIdx[i];
            if (filterRayOverlapsBounds(aabb0, rays[idx], earlyOut))
            {
                *raysIdxOut0 = idx;
                raysIdxOut0++;
                numRaysOut0++;
            }
            if (filterRayOverlapsBounds(aabb1, rays[idx], earlyOut))
            {
                *raysIdxOut1 = idx;
                raysIdxOut1++;
                numRaysOut1++;
            }
        }
    }
    else
    {
        int numBundles = (numRays + 3) >> 2;
        int rayIdx[4];
        rayIdx[0] = 0;
        rayIdx[1] = 0;
        rayIdx[2] = 0;
        rayIdx[3] = 0;
        for (int b = 0; b < numBundles; b++)
        {
            int n = FilterRays_min2(numRays - b * 4, 4);
            float fractions[4];
            for (int j = 0; j < n; j++)
            {
                rayIdx[j] = raysIdx[j + b * 4];
                const RayCastRequest* command = commandArray + rayIdx[j];
                setCollector(&collectors[j], command, filter);
                FilterRays_filterSetAll(collectors[j].m_fEarlyOutHitFraction, earlyHitFractionArray[rayIdx[j]]);
                fractions[j] = earlyHitFractionArray[rayIdx[j]];
                if (command->m_useFilterCollector)
                {
                    collectors[j].m_fixedBufferRayHitFilterCollector = ::new (&fixedBufferFilterCollectors[j])
                        hkpFixedBufferRayHitCollector(command->m_pResultBuffer, command->m_iResultCount);
                    FilterRays_registerAddRayHit(Runtime_ProcessEntries_00e2b9b0);
                }
                else
                {
                    collectors[j].m_fixedBufferRayHitFilterCollector = 0;
                }
            }
            RayQuerySet bundle = hkVector4_UpdateState_00e2baf0(
                rays[rayIdx[0]].m_kRayStart, rays[rayIdx[0]].m_vInverseDirection, rays[rayIdx[1]].m_kRayStart,
                rays[rayIdx[1]].m_vInverseDirection, rays[rayIdx[2]].m_kRayStart, rays[rayIdx[2]].m_vInverseDirection,
                rays[rayIdx[3]].m_kRayStart, rays[rayIdx[3]].m_vInverseDirection, DAT_011b3830[n]);
            hkAabbTreeQueryUtils<hkAabbTreeData::hkAabbTreeAabb, unsigned short>::Collector* collectorPtrs[4] = {&collectors[0], &collectors[1], &collectors[2],
                                                            &collectors[3]};
            Object_ProcessEntries_00d1ca00(tree, node, skipNode, &bundle, collectorPtrs, fractions);
            for (int j = 0; j < n; j++)
                earlyHitFractionArray[rayIdx[j]] = collectors[j].m_fEarlyOutHitFraction(0);
        }
    }
}
