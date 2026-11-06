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
    int* FUN_00d1bb40(unsigned short index);
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
S_00d1bcb0_Router* FUN_00c85750();
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
    bool FUN_00d1bcb0(int a, int b);
};
extern int __cdecl FUN_00d1c560(void*, int, int, int, int, int);
int __cdecl CallWithDefaults(void* arg0, int arg1, int arg2);
int __cdecl FUN_00d1c560(void* a, void* b, int c, int d, void* e, void* f);
int __cdecl FUN_00d1d4d0(void* a, void* b, void* e, void* f);
extern int __cdecl FUN_00d1c560(void*, int, int, int, int, int);
int __cdecl FUN_00d1d500(void* arg0, int arg1, int arg2);
extern "C" void* __cdecl FUN_00d1ce50(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d540
extern "C" void* __cdecl FUN_00d1d540(void* p, int a, int d, int e)
{
    if (!p)
        return 0;
    return FUN_00d1ce50(p, a, 0, 0, d, e);
}

extern "C" void* __cdecl FUN_00d1d240(void* p, int a, int b, int c, int d, int e);
// @fnv 0x00d1d570
extern "C" void* __cdecl FUN_00d1d570(void* p, int a, int b)
{
    if (!p)
        return p;
    return FUN_00d1d240(p, a, b, 0, 0, 0);
}

extern "C" void __cdecl FUN_00d1ca00();
// @fnv 0x00d1d530
extern "C" void __cdecl FUN_00d1d530()
{
    FUN_00d1ca00();
}

extern int __cdecl FUN_00d1bfa0();
int __cdecl FUN_00d1d490();

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
    TreeNode* FUN_00d9a4c0(int index);
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

float __cdecl FUN_00d1bad0(const AabbQ* aabb, const hkVector4* point);

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
        _clearAndDeallocate(FUN_00c85750()->heap());
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
        _pushBack(FUN_00c85750()->heap(), t);
    }
};

// @fnv 0x00d1dbb0
void __cdecl FUN_00d1dbb0(AabbTree* tree, const hkVector4& point, ClosestCollector* collector)
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
                    TreeNode* c0 = tree->m_kNodeCollection.FUN_00d9a4c0(node->m_children[0]);
                    TreeNode* c1 = tree->m_kNodeCollection.FUN_00d9a4c0(node->m_children[1]);
                    AabbQ a0;
                    a0 = c0->m_kBounds;
                    AabbQ a1;
                    a1 = c1->m_kBounds;
                    float d0 = FUN_00d1bad0(&a0, &point);
                    float d1 = FUN_00d1bad0(&a1, &point);
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
