#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#include "../../../../../../../../include/hkArray.h"

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/queryutils/hkaabbtreequeryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the matched SIMD representation when including the shared vector.
typedef ::__m128 LocalM128;

#define FNV_VECTOR_USE_LOCAL_SSE
#include "../../../../../../../../include/hkVector4.h"

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

extern float DAT_0104da48;

struct AabbQ
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;

    __forceinline void operator=(const AabbQ& o)
    {
        m_kMinimumCorner.m_vComponents = o.m_kMinimumCorner.m_vComponents;
        m_kMaximumCorner.m_vComponents = o.m_kMaximumCorner.m_vComponents;
    }
};

struct TreeNode
{
    AabbQ m_kBounds;
    int m_children[2];
    unsigned int m_flags;

    __forceinline unsigned int isLeaf() const
    {
        return m_flags & 0x80000000;
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
    int unk0c;
    TreeNode* m_pTreeNode;
    int unk14;
    int unk18;
    TreeNodeArray m_kNodeCollection;
};

struct ClosestCollector
{
    virtual void unk00();
    virtual float processLeaf(const TreeNode* leaf);
};

struct HeapAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

extern "C" void _ReadWriteBarrier(void);

float __cdecl Runtime_ComputeValues_00d1bad0(const AabbQ* aabb, const hkVector4* point);

struct NodeStack
{
    TreeNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    TreeNode* m_kStorage[128];

    __forceinline NodeStack()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000080;
    }
    __forceinline ~NodeStack()
    {
        _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
    }

    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void _clearAndDeallocate(S_00d1bcb0_Allocator& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            reinterpret_cast<HeapAllocator&>(alloc).ReturnMemory(m_data, getCapacity() * sizeof(TreeNode*));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _pushBack(S_00d1bcb0_Allocator& alloc, TreeNode* const& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(alloc, this, sizeof(TreeNode*));
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void pushBack(TreeNode* const& t)
    {
        _pushBack(hkMemoryRouter_getInstance()->heap(), t);
    }
};

// @fnv 0x00d1dbb0
// src: GUESS 0x00d1dbb0 (confidence: low)
void __cdecl hkVector4_ProcessEntries_00d1dbb0(AabbTree* tree, const hkVector4& point, ClosestCollector* collector)
{
    TreeNode* root = tree->m_pTreeNode;
    if (root)
    {
        float maxDist = DAT_0104da48;
        NodeStack stack;
        if (!root->isLeaf())
        {
            stack.pushBack(root);
            _ReadWriteBarrier();
            do
            {
                TreeNode* node = stack.m_data[stack.m_iElementCount - 1];
                stack.m_iElementCount--;
                if (!node->isLeaf())
                {
                    TreeNode* c0 = tree->m_kNodeCollection.ComputeValue_00d9a4c0(node->m_children[0]);
                    TreeNode* c1 = tree->m_kNodeCollection.ComputeValue_00d9a4c0(node->m_children[1]);
                    AabbQ a0;
                    a0 = c0->m_kBounds;
                    AabbQ a1;
                    a1 = c1->m_kBounds;
                    float d0 = Runtime_ComputeValues_00d1bad0(&a0, &point);
                    float d1 = Runtime_ComputeValues_00d1bad0(&a1, &point);
                    int mask = ((d0 < maxDist) ? 1 : 0) + ((maxDist > d1) ? 2 : 0);
                    switch (mask & 3)
                    {
                    case 1:
                        stack.pushBack(c0);
                        break;
                    case 2:
                        stack.pushBack(c1);
                        break;
                    case 3:
                        if (d0 < d1)
                        {
                            stack.pushBack(c1);
                            stack.pushBack(c0);
                        }
                        else
                        {
                            stack.pushBack(c0);
                            stack.pushBack(c1);
                        }
                        break;
                    }
                }
                else
                {
                    maxDist = collector->processLeaf(node);
                    if (maxDist == 0.0f)
                        break;
                }
            } while (stack.m_iElementCount);
        }
        else
        {
            collector->processLeaf(root);
        }
    }
}
