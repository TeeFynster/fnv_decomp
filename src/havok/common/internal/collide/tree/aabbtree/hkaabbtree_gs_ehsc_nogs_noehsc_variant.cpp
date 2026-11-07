#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/Vec4.h"
#include <string.h>

// Keep native SIMD access and alignment while using the shared vector layout.
static __forceinline __m128& quad(Vec4& v) { return *reinterpret_cast<__m128*>(&v.x); }
static __forceinline const __m128& quad(const Vec4& v) { return *reinterpret_cast<const __m128*>(&v.x); }
static __forceinline float component(const Vec4& v, int i) { return quad(v).m128_f32[i]; }


// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/hkaabbtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d9be20_class {
    void UpdateFields_00d9be20();
};
struct FUN_00d9be30_class {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    void UpdateState_00d9be30();
};
struct FUN_00d9be20_cls {
    void __thiscall UpdateFields_00d9be20();
};
struct FUN_00d9bed0_cls {
    void __thiscall UpdateState_00d9bed0();
};
struct Obj_d9be20 {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    void UpdateFields_00d9be20();
};
struct Key {
    int a;
    int b;
    Key& operator=(const Key& o) { a = o.a; b = o.b; a = o.a; return *this; }
};
struct Elem {
    Vec4::Aligned v0;
    Vec4::Aligned v1;
    Key k;
    int c;
    int d;
};
struct IntArray {
    int* m_data;
    int m_iElementCount;
    int& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }
    int GetLogicalSize() const { return m_iElementCount; }
};
struct ElemPool {
    Elem* m_pElements;
    int m_pRayCursor;
    int m_unk08;
    IntArray m_freeArr;

    void Grow(int newCapacity, int a, int b);
    int AllocElem(int a, int b, const Elem& e);
};
struct FUN_00d9ce00_Class
{
    int base;
    int value;
    int unk08;
    int* items;
    int count;
    int hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb_unsigned_int_NodeManager_reserve(int start, int first, int second);
    int* PopItem(int first, int second, int* output);
};
struct UnsignedShortArray { unsigned short* elements; unsigned int count; unsigned int capacity; };
void __cdecl ResizeAudioStream(void* memory, UnsignedShortArray* buffer, unsigned int count);
struct Owner { int unknown00, unknown04, unknown08; UnsignedShortArray buffer; hkMemoryRouter* hkMemoryRouter_getInstance(); unsigned short* AppendElement(unsigned short value); };
struct Allocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* p, unsigned int bytes);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(Allocator* allocator, void** data, unsigned int capacity, unsigned int elemSize);
struct S_d9bf30_Rec {
    int unk0; int unk4; int unk8; int unkc;
    unsigned short unk10; unsigned short unk12;
};
struct S_d9bf30_Words {
    unsigned short* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    void push(unsigned short v) {
        unsigned short* p = m_data + m_uiItemCount;
        for (int k = 0; k < 1; k++) p[k] = v;
        m_uiItemCount++;
    }
    __forceinline void refill(unsigned short newSize, int oldCount) {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        Allocator* alloc = reinterpret_cast<Allocator*>(holder->m_heap);

        unsigned int cap = m_capFlags & 0x3fffffffu;
        if ((int)cap < (int)newSize) {
            unsigned int nc = cap + cap;
            if ((int)newSize >= (int)nc) {
                nc = newSize;
            }
            hkArrayUtil__reserve(alloc, (void**)&m_data, nc, 2);
        }

        for (int i = (int)newSize - 1; i >= oldCount; --i) {
            push((unsigned short)i);
        }
    }
};
struct FUN_00d9bf30_cls {
    S_d9bf30_Rec* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    S_d9bf30_Words m_free;

    void AllocateRecords(unsigned short newSize, S_d9bf30_Rec** out, unsigned short* idx);
};
struct Record20 { int field0,field4,field8,fieldC,field10; };
struct RecordPool {
    Record20* records;
    unsigned short type;
    unsigned short unk06;
    int unk08;
    unsigned short* available;
    int count;
    void __thiscall AllocateRecords(unsigned short typeCode, int first, int second);
    unsigned short __thiscall AddRecord(int first,int second,const Record20* item);
};
struct BoundsNode { unsigned short m00,m02,m04,m06,m08,m0A,m0C,m0E,m10,m12; };
struct FUN_00d9a4d0_cls { BoundsNode* __thiscall GetEntryOffset(unsigned short key); };
struct FUN_00d9b450_cls { int m00,m04,m08,m0C,m10,m14,m18; FUN_00d9a4d0_cls m1c; void __thiscall UpdateBoundsNode(BoundsNode* a1,unsigned short a2,unsigned short a3); };
struct S_00d9d650_Heap
{
    virtual void unkVfn0();
    virtual void unkVfn1();
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};
void __cdecl hkArrayUtil__reserve(S_00d9d650_Heap& alloc, void* array, int reqCapacity, int sizeElem);
template <typename T>
struct S_00d9d650_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d9d650_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d9d650_Array() throw() { _clearAndDeallocate(*reinterpret_cast<S_00d9d650_Heap*>(hkMemoryRouter_getInstance()->GetAllocator())); }

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }

    void _clearAndDeallocate(S_00d9d650_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00d9d650_Heap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00d9d650_Heap& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) { _setSize(*reinterpret_cast<S_00d9d650_Heap*>(hkMemoryRouter_getInstance()->GetAllocator()), n); }
};
struct S_00d9d650_Aabb
{
    Vec4::Aligned m_kMinimumCorner;
    Vec4::Aligned m_kMaximumCorner;
};
struct S_00d9d650_Node
{
    S_00d9d650_Aabb m_kBounds;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void setLeaf(int key)
    {
        m_20 = key;
        m_28 |= 0x80000000;
    }
};
struct S_00d9d650_Pool
{
    void hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb_unsigned_int_NodeManager_reserve(int numNodes, S_00d9d650_Node** root, int* a);
    S_00d9d650_Node* PopItem(S_00d9d650_Node** root, int* a, int* b);
};
struct S_00d9d650_Tree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d9d650_Node* m_pTreeNode;
    int m_14;
    int m_iNodeCount;
    S_00d9d650_Pool m_kNodePool;

    void ProcessEntries_00d9d1c0(S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Node* root, S_00d9d650_Array<int>& out, int depth);
    void MergeNode(S_00d9d650_Node* root, int a, int b);
    void TraverseTree(S_00d9d650_Node* root, int a);
    void BuildTree(const S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Array<int>& out) throw();
};
struct Node_d9c520
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
};
struct Resolver_d9c520
{
    Node_d9c520* GetEntryOffset(unsigned short index);
    Node_d9c520* ResolveChild(unsigned short index);
};
struct TrackedArray_d9c520
{
    Node_d9c520** elements;
    unsigned int count;
    int capacity;
};
struct Pool_d9c520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Resolver_d9c520 resolver;

    void TraverseNodeTree(Node_d9c520* node, int second);
};
void __cdecl AppendElement();
void __cdecl Hkaabbtree_AppendElement_Thunk(int param_1, unsigned short param_2);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
struct NodeD9C7 {
    char unk00[0x10];
    unsigned short m_usFlags;
};
class FreeListD9C7 {
public:
    void Hkaabbtree_AppendElement_Thunk(NodeD9C7* pkNode);
};
class FUN_00d9c7d0_C {
public:
    char unk00[0x10];
    NodeD9C7* m_pkTreeNode;
    short m_sValue;
    short unk16;
    int m_iArrayLength;
    FreeListD9C7 m_kFreeList;

    void hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_removeLeafInternal(NodeD9C7* pkNode, NodeD9C7** ppkOut);
    void hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_remove(NodeD9C7* pkNode);
};

extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmple_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmpge_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" int _mm_movemask_ps(__m128 a);


struct TreeAabb
{
    TreeAabb() : m_kMinimumCorner(Vec4::Uninitialized), m_kMaximumCorner(Vec4::Uninitialized) {}
    TreeAabb(const TreeAabb& o) : m_kMinimumCorner(Vec4::Uninitialized), m_kMaximumCorner(Vec4::Uninitialized) { memcpy(this, &o, sizeof(*this)); }
    Vec4::Aligned m_kMinimumCorner;
    Vec4::Aligned m_kMaximumCorner;
    void setUnion(const TreeAabb& a, const TreeAabb& b) { quad(m_kMinimumCorner) = _mm_min_ps(quad(a.m_kMinimumCorner), quad(b.m_kMinimumCorner)); quad(m_kMaximumCorner) = _mm_max_ps(quad(a.m_kMaximumCorner), quad(b.m_kMaximumCorner)); }
    bool contains(const TreeAabb& o) const { __m128 a = _mm_cmple_ps(quad(m_kMinimumCorner), quad(o.m_kMinimumCorner)); __m128 b = _mm_cmple_ps(quad(o.m_kMaximumCorner), quad(m_kMaximumCorner)); return (_mm_movemask_ps(_mm_and_ps(a, b)) & 7) == 7; }
};

static __forceinline __m128 vmin(__m128 a, __m128 b) { return _mm_min_ps(a, b); }
static __forceinline __m128 vmax(__m128 a, __m128 b) { return _mm_max_ps(a, b); }
static __forceinline void unionOut(TreeAabb& o, const TreeAabb& a, const TreeAabb& b) { quad(o.m_kMinimumCorner) = _mm_min_ps(quad(a.m_kMinimumCorner), quad(b.m_kMinimumCorner)); quad(o.m_kMaximumCorner) = _mm_max_ps(quad(a.m_kMaximumCorner), quad(b.m_kMaximumCorner)); }
struct TreeNode
{
    TreeAabb m_kBounds;
    int m_children[2];
    unsigned int m_parent;
    int m_next;

    unsigned int isLeaf() const { return m_parent & 0x80000000u; }
    unsigned int getParent() const { return m_parent & 0x7fffffffu; }
    void setParent(unsigned int parent) { m_parent = (m_parent & 0x80000000u) | parent; }
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
    TreeNode* m_pTreeNode;
    int m_rootIndex;
    int unk18;
    TreeNodeArray m_kNodeCollection;

    void ProcessEntries_00d9afe0(int root, int leaf, int branch);
};

// @fnv 0x00d9afe0
// src: GUESS 0x00d9afe0 (confidence: low)
void AabbTree::ProcessEntries_00d9afe0(int root, int leaf, int branch)
{
    TreeNode* leafNode = m_kNodeCollection.ComputeValue_00d9a4c0(leaf);
    TreeNode* branchNode = m_kNodeCollection.ComputeValue_00d9a4c0(branch);
    TreeAabb volume = leafNode->m_kBounds;
    __m128 center = _mm_add_ps(reinterpret_cast<__m128*>(&volume)[0], reinterpret_cast<__m128*>(&volume)[1]);

    TreeNode* siblingNode = m_kNodeCollection.ComputeValue_00d9a4c0(root);
    int sibling = root;
    int side = 0;
    while (!siblingNode->isLeaf())
    {
        TreeNode* child0 = m_kNodeCollection.ComputeValue_00d9a4c0(siblingNode->m_children[0]);
        TreeNode* child1 = m_kNodeCollection.ComputeValue_00d9a4c0(siblingNode->m_children[1]);
        __m128 d0 = _mm_sub_ps(_mm_add_ps(quad(child0->m_kBounds.m_kMinimumCorner), quad(child0->m_kBounds.m_kMaximumCorner)), center);
        __m128 d1 = _mm_sub_ps(_mm_add_ps(quad(child1->m_kBounds.m_kMinimumCorner), quad(child1->m_kBounds.m_kMaximumCorner)), center);
        __m128 diff = _mm_sub_ps(_mm_mul_ps(d1, d1), _mm_mul_ps(d0, d0));
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(diff, diff, 0x55), diff);
        sum = _mm_add_ss(_mm_shuffle_ps(diff, diff, 0xaa), sum);
        side = (~_mm_movemask_ps(sum)) & 1;
        sibling = siblingNode->m_children[side];
        siblingNode = m_kNodeCollection.ComputeValue_00d9a4c0(sibling);
    }

    unsigned int parent = siblingNode->getParent();
    TreeNode* parentNode = (parent != 0x7fffffffu) ? m_kNodeCollection.ComputeValue_00d9a4c0(parent) : 0;

    branchNode->m_kBounds.setUnion(leafNode->m_kBounds, siblingNode->m_kBounds);
    int* children = branchNode->m_children;
    children[0] = sibling;
    children[1] = leaf;
    siblingNode->setParent(branch);
    leafNode->setParent(branch);
    int next = siblingNode->m_next;
    siblingNode->m_next = leaf;
    leafNode->m_next = next;
    branchNode->m_next = next;

    if (parentNode != 0)
    {
        parentNode->m_children[side] = branch;
        branchNode->setParent(parent);
        if (side == 1)
        {
            TreeNode* node = m_kNodeCollection.ComputeValue_00d9a4c0(parentNode->m_children[0]);
            node->m_next = branch;
            while (!node->isLeaf())
            {
                node = m_kNodeCollection.ComputeValue_00d9a4c0(node->m_children[1]);
                node->m_next = branch;
            }
        }
        while (parentNode != 0)
        {
            __m128 minIn = _mm_cmpge_ps(reinterpret_cast<__m128*>(&volume)[0], quad(parentNode->m_kBounds.m_kMinimumCorner));
            __m128 maxIn = _mm_cmpge_ps(quad(parentNode->m_kBounds.m_kMaximumCorner), reinterpret_cast<__m128*>(&volume)[1]);
            if ((_mm_movemask_ps(_mm_and_ps(minIn, maxIn)) & 7) == 7)
            {
                return;
            }
            quad(parentNode->m_kBounds.m_kMinimumCorner) = _mm_min_ps(quad(parentNode->m_kBounds.m_kMinimumCorner), reinterpret_cast<__m128*>(&volume)[0]);
            quad(parentNode->m_kBounds.m_kMaximumCorner) = _mm_max_ps(quad(parentNode->m_kBounds.m_kMaximumCorner), reinterpret_cast<__m128*>(&volume)[1]);
            unsigned int up = parentNode->getParent();
            if (up == 0x7fffffffu)
            {
                return;
            }
            parentNode = m_kNodeCollection.ComputeValue_00d9a4c0(up);
        }
    }
    else
    {
        m_pTreeNode = branchNode;
        branchNode->m_parent |= 0x7fffffffu;
        m_rootIndex = branch;
    }
}

extern "C" {
__m128 __cdecl _mm_min_ps(__m128,__m128);
__m128 __cdecl _mm_max_ps(__m128,__m128);
__m128 __cdecl _mm_cmpeq_ps(__m128,__m128);
__m128 __cdecl _mm_and_ps(__m128,__m128);
int __cdecl _mm_movemask_ps(__m128);
}
struct S00d9b240_Mask { __m128 mask; unsigned char allXYZ() const {unsigned int m=_mm_movemask_ps(_mm_and_ps(mask,mask))&7;return m==7;} };
struct S00d9b240_Bounds {
 __m128 minimum,maximum;
 void setUnion(const S00d9b240_Bounds& a,const S00d9b240_Bounds& b) {minimum=_mm_min_ps(a.minimum,b.minimum);maximum=_mm_max_ps(a.maximum,b.maximum);}
};
struct S00d9b240_Node : S00d9b240_Bounds {
 int children[2];
 unsigned int parentAndLeaf;
 int escape;
};
struct S00d9b240_Pool { S00d9b240_Node* ComputeValue_00d9a4c0(int); };
struct S00d9b240_Tree {
 int unk00,unk04,unk08,unk0c;
 S00d9b240_Node* root;
 int rootIndex,numLeaves;
 S00d9b240_Pool pool;
 S00d9b240_Node* ProcessEntries_00d9b240(int leafIndex,int* removedParentIndex);
 S00d9b240_Node* getSibling(const S00d9b240_Node* p,const S00d9b240_Node* c) { S00d9b240_Node* a=pool.ComputeValue_00d9a4c0(p->children[0]); S00d9b240_Node* b=pool.ComputeValue_00d9a4c0(p->children[1]); return (S00d9b240_Node*)((unsigned int)a^(unsigned int)b^(unsigned int)c); }
 int getSiblingIndex(const S00d9b240_Node* p,int c) { return p->children[0]^p->children[1]^c; }
};
// @fnv 0x00d9b240
// src: GUESS 0x00d9b240 (confidence: low)
S00d9b240_Node* S00d9b240_Tree::ProcessEntries_00d9b240(int leafIndex,int* removedParentIndex) {
 S00d9b240_Node* leaf=pool.ComputeValue_00d9a4c0(leafIndex);
 unsigned int parentIndex=leaf->parentAndLeaf&0x7fffffffu;
 S00d9b240_Node* __restrict parent=parentIndex!=0x7fffffffu ? pool.ComputeValue_00d9a4c0(parentIndex):0;
 unsigned int grandparentIndex=parent->parentAndLeaf&0x7fffffffu;
 S00d9b240_Node* grandparent=grandparentIndex!=0x7fffffffu ? pool.ComputeValue_00d9a4c0(grandparentIndex):0;
 const int& firstIndex=parent->children[0];
 int secondIndex=parent->children[1];
 S00d9b240_Node* sibling=(S00d9b240_Node*)((unsigned int)pool.ComputeValue_00d9a4c0(firstIndex)^(unsigned int)pool.ComputeValue_00d9a4c0(secondIndex));
 sibling=(S00d9b240_Node*)((unsigned int)sibling^(unsigned int)leaf);
 int siblingIndex=firstIndex^parent->children[1]^leafIndex;
 *removedParentIndex=parentIndex;
 S00d9b240_Node* result;
 if(grandparent) {
  int child=(pool.ComputeValue_00d9a4c0(grandparent->children[1])==parent);
  grandparent->children[child]=siblingIndex;
  sibling->parentAndLeaf=(sibling->parentAndLeaf&0x80000000u)|grandparentIndex;
  result=root;
  if(child==1) {
   S00d9b240_Node* cursor=pool.ComputeValue_00d9a4c0(grandparent->children[0]);
   for(;;) {
    cursor->escape=siblingIndex;
    if(cursor->parentAndLeaf&0x80000000u) break;
    cursor=pool.ComputeValue_00d9a4c0(cursor->children[1]);
   }
  }
  while(grandparent) {
   S00d9b240_Node* right=pool.ComputeValue_00d9a4c0(grandparent->children[1]);
   S00d9b240_Node* left=pool.ComputeValue_00d9a4c0(grandparent->children[0]);
   S00d9b240_Bounds merged;
   merged.setUnion(*left,*right);
   S00d9b240_Mask equal;equal.mask=_mm_cmpeq_ps(grandparent->maximum,merged.maximum);
   if(equal.allXYZ()) {result=grandparent;break;}
   grandparent->minimum=merged.minimum;
   grandparent->maximum=merged.maximum;
   unsigned int next=grandparent->parentAndLeaf&0x7fffffffu;
   grandparent=next!=0x7fffffffu ? pool.ComputeValue_00d9a4c0(next):0;
  }
 } else {
  root=sibling;
  sibling->parentAndLeaf|=0x7fffffffu;
  result=root;
  rootIndex=siblingIndex;
 }
 S00d9b240_Node* __restrict tailParent=parent;
 if(pool.ComputeValue_00d9a4c0(tailParent->children[0])==sibling) {
  int escape=tailParent->escape;
  S00d9b240_Node* cursor=sibling;
  for(;;) {
   cursor->escape=escape;
   if(cursor->parentAndLeaf&0x80000000u) break;
   cursor=pool.ComputeValue_00d9a4c0(cursor->children[1]);
  }
 }
 return result;
}

struct Aabb {
    Vec4::Aligned lo;
    Vec4::Aligned hi;
};

struct Rec {
    Rec() : lo(Vec4::Uninitialized), hi(Vec4::Uninitialized) {}
    Vec4::Aligned lo;
    Vec4::Aligned hi;
    int f20;
    int f24;
    int f28;
    int f2c;
};

struct Sub {
    int unk00;
    int unk04;
    int* m_pStackBuffer;
    int m_uiItemCount;
    int push(Rec** a1, int* a2, const Rec& r);
    void pop(Rec** a1, int* a2, int* out);
    Rec* at(int idx);
};

struct Outer {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Rec* m_10;
    int m_14;
    int m_18;
    Sub m_1c;
    void fn(int a1, int a2, int a3);
    int UpdateState_00d9d110(const Aabb* box, int arg2);
};

// @fnv 0x00d9d110
// src: GUESS 0x00d9d110 (confidence: low)
int Outer::UpdateState_00d9d110(const Aabb* box, int arg2) {
    Rec rec;
    quad(rec.hi) = quad(box->hi);
    quad(rec.lo) = quad(box->lo);
    rec.f20 = arg2;
    rec.f28 = 0x80000000;

    int idx = m_1c.push(&m_10, &m_14, rec);
    if (m_14 == 0x7fffffff) {
        Rec* p = m_1c.at(idx);
        p->f28 |= 0x7fffffff;
        p->f2c = 0x7fffffff;
        m_10 = p;
        m_14 = idx;
    } else {
        int out;
        m_1c.pop(&m_10, &m_14, &out);
        fn(m_14, idx, out);
    }
    m_18++;
    return idx;
}

struct S00d9bb50_Aabb {
    S00d9bb50_Aabb() {}
    unsigned short min[3];
    unsigned short max[3];
    bool equals(const S00d9bb50_Aabb& o) const {
        for (int i = 0; i < 3; ++i) {
            if (max[i] != o.max[i] || min[i] != o.min[i])
                return false;
        }
        return true;
    }
};

inline unsigned short s00d9bb50_min(const unsigned short& a, const unsigned short& b) { return b < a ? b : a; }
inline unsigned short s00d9bb50_max(const unsigned short& a, const unsigned short& b) { return b > a ? b : a; }

template<class B, class I> struct CurrentTree {
    struct Node {
        B aabb;
        I child[2];
        I parent, next;
        static const I mask = I(~0) >> 1;
        I parentIndex() const { return parent & mask; }
        I childIndex(int side) const { return child[side]; }
    };
    struct Pool {
        Node* nodes;
        int count, capacity;
        __declspec(noinline) Node* GetEntryOffset(I i);
        __declspec(noinline) const Node* GetEntryOffset(I i) const;
        Node* get(I i) { return i != Node::mask ? GetEntryOffset(i) : 0; }
    };
    int m00,m04,m08,m0c;
    Node* m_pTreeNode;
    I m_usManagerValue,m16;
    int m18;
    Pool m_kNodePool;
    __forceinline Node* parentOf(const Node* n) const {
        return (n->parent & Node::mask) != Node::mask ? const_cast<Node*>(((const Pool*)&m_kNodePool)->GetEntryOffset(n->parent & Node::mask)) : 0;
    }
    __forceinline Node* childOf(const Node* n, int i) const { return const_cast<Node*>(((const Pool*)&m_kNodePool)->GetEntryOffset(n->child[i])); }
    Node* hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_removeLeafInternal(I leafIdx, I* outParent);
};
template<class B,class I> typename CurrentTree<B,I>::Node* CurrentTree<B,I>::Pool::GetEntryOffset(I i) { return &nodes[i]; }
template<class B,class I> const typename CurrentTree<B,I>::Node* CurrentTree<B,I>::Pool::GetEntryOffset(I i) const { return &nodes[i]; }

// @fnv 0x00d9bb50
// src: HAVOK_LIB 0x00d9bb50
template<class B,class I> typename CurrentTree<B,I>::Node* CurrentTree<B,I>::hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_removeLeafInternal(I leafIdx,I* outParent)
{
    Pool* pool = &m_kNodePool;
    Node* leaf = pool->GetEntryOffset(leafIdx);
    Node* parent = parentOf(leaf);
    Node* prev = parentOf(parent);
    I prevIdx = parent->parentIndex();
    Node* sib = (Node*)((unsigned int)childOf(parent, 0) ^ (unsigned int)childOf(parent, 1) ^ (unsigned int)leaf);
    I sibIdx = parent->childIndex(0) ^ parent->childIndex(1) ^ leafIdx;
    *outParent = leaf->parentIndex();
    Node* root;
    if (prev) {
        int which = childOf(prev, 1) == parent;
        prev->child[which] = sibIdx;
        sib->parent = (sib->parent & 0x8000) | prevIdx;
        root = m_pTreeNode;
        if (which == 1) {
            Node* n = childOf(prev, 0);
            n->next = sibIdx;
            while (!(n->parent & 0x8000)) {
                n = childOf(n, 1);
                n->next = sibIdx;
            }
        }
        do {
            Node* r = childOf(prev, 1);
            Node* l = childOf(prev, 0);
            S00d9bb50_Aabb nb;
            for (int k = 0; k < 3; ++k) {
                nb.max[k] = s00d9bb50_min(r->aabb.max[k], l->aabb.max[k]);
                nb.min[k] = s00d9bb50_max(r->aabb.min[k], l->aabb.min[k]);
            }
            if (prev->aabb.equals(nb)) {
                root = prev;
                break;
            }
            prev->aabb = nb;
            prev = (prev->parent & Node::mask) != Node::mask ? pool->GetEntryOffset(prev->parent & Node::mask) : 0;
        } while (prev);
    } else {
        m_pTreeNode = sib;
        sib->parent |= Node::mask;
        m_usManagerValue = sibIdx;
        root = m_pTreeNode;
    }
done:
    if (childOf(parent, 0) == sib) {
        unsigned short nx = parent->next;
        Node* n = sib;
        for (;;) {
            n->next = nx;
            if (n->parent & 0x8000)
                break;
            n = childOf(n, 1);
        }
    }
    return root;
}

template CurrentTree<S00d9bb50_Aabb,unsigned short>::Node* CurrentTree<S00d9bb50_Aabb,unsigned short>::hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_removeLeafInternal(unsigned short,unsigned short*);

extern "C" {
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_max_ps(__m128, __m128);
}

extern __m128 g_aabbQuantMax;   // 0x011b6d70: 2147352576.0f x4
extern __m128 g_vectorZero;     // 0x01267e30

struct TreeHeap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

void __cdecl hkArrayUtil__reserve(TreeHeap& alloc, void* array, int reqCapacity, int sizeElem) throw();

template <typename T>
struct TreeArrayLocalForm { // local form of hkArray: 0x00d9ce50 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline TreeArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~TreeArrayLocalForm() { _clearAndDeallocate(*reinterpret_cast<TreeHeap*>((&hkMemoryRouter_getInstance()->heap()))); }

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    __forceinline void _clearAndDeallocate(TreeHeap& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(TreeHeap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(*reinterpret_cast<TreeHeap*>((&hkMemoryRouter_getInstance()->heap())), n);
        m_iElementCount = n;
    }
};


struct TreeAabb16 {
    unsigned short m_kMinimumCorner[3];
    unsigned short m_kMaximumCorner[3];
};

struct TreeNode16 {
    TreeAabb16 m_kBounds;
    int m_key;
    unsigned short m_parent;
    unsigned short m_pChildAtom;

    __forceinline void setLeaf(int key)
    {
        m_key = key;
        m_parent |= 0x8000;
    }
};

struct TreeNodePool {
    void AllocateRecords(unsigned short numNodes, TreeNode16** nodes, unsigned short* root) throw();
    TreeNode16* PopGlyphRecord(TreeNode16** nodes, unsigned short* a, unsigned short* b) throw();
};

struct AabbTree16 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TreeNode16* m_kNodeCollection;
    unsigned short m_pTreeNode;
    unsigned short unk16;
    int m_iNodeCount;
    TreeNodePool m_kNodePool;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    __m128 m_kVectorAt50;
    __m128 m_kVectorAt40;
    __m128 m_vScale;

    void hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_buildTreeInternal(TreeAabb16* aabbs, const int* keys, int n, TreeNode16* root, TreeArrayLocalForm<unsigned short>* out, int depth) throw();
    void UpdateBoundsNode(TreeNode16* nodes, unsigned short root, int maxVal) throw();
    void TraverseNodeTree(TreeNode16* nodes, int a) throw();

    __forceinline void convertAabb(const TreeAabb& in, TreeAabb16& out)
    {
        Vec4::Aligned maxVal(Vec4::Uninitialized);
        quad(maxVal) = g_aabbQuantMax;
        Vec4::Aligned hi(Vec4::Uninitialized);
        quad(hi) = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(m_kVectorAt50, quad(in.m_kMinimumCorner)), m_vScale), quad(maxVal)), g_vectorZero);
        int hi0 = fnv_FloatToInt(component(hi, 0));
        int hi1 = fnv_FloatToInt(component(hi, 1));
        int hi2 = fnv_FloatToInt(component(hi, 2));
        int hi3 = fnv_FloatToInt(component(hi, 3));

        Vec4::Aligned lo(Vec4::Uninitialized);
        quad(lo) = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(quad(in.m_kMaximumCorner), m_kVectorAt40), m_vScale), quad(maxVal)), g_vectorZero);
        int lo0 = fnv_FloatToInt(component(lo, 0));
        int lo1 = fnv_FloatToInt(component(lo, 1));
        int lo2 = fnv_FloatToInt(component(lo, 2));
        int lo3 = fnv_FloatToInt(component(lo, 3));

        out.m_kMinimumCorner[0] = (unsigned short)((unsigned int)lo0 >> 15);
        out.m_kMaximumCorner[0] = (unsigned short)((unsigned int)hi0 >> 15);
        out.m_kMinimumCorner[1] = (unsigned short)((unsigned int)lo1 >> 15);
        out.m_kMaximumCorner[1] = (unsigned short)((unsigned int)hi1 >> 15);
        out.m_kMinimumCorner[2] = (unsigned short)((unsigned int)lo2 >> 15);
        out.m_kMaximumCorner[2] = (unsigned short)((unsigned int)hi2 >> 15);
    }

    void hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_build(const TreeAabb* aabbs, const int* keys, int n, TreeArrayLocalForm<unsigned short>* out) throw();
};

// @fnv 0x00d9ce50
// src: XBOX_PDB 0x00d9ce50
void AabbTree16::hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_build(const TreeAabb* aabbs, const int* keys, int n, TreeArrayLocalForm<unsigned short>* out) throw()
{
    m_iNodeCount = n;
    if (n == 0)
    {
        return;
    }

    out->SetSizeAndGrow(n);
    m_kNodePool.AllocateRecords(n + n - 1, &m_kNodeCollection, &m_pTreeNode);
    m_kNodeCollection = m_kNodePool.PopGlyphRecord(&m_kNodeCollection, &m_pTreeNode, &m_pTreeNode);
    m_kNodeCollection->m_parent |= 0x7fff;

    TreeArrayLocalForm<TreeAabb16> aabbs16;
    aabbs16.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
    {
        convertAabb(aabbs[i], aabbs16.m_data[i]);
    }

    if (n == 1)
    {
        m_kNodeCollection->setLeaf(keys[0]);
        m_kNodeCollection->m_pChildAtom = 0x7fff;
        m_kNodeCollection->m_kBounds = aabbs16.m_data[0];
        out->m_data[0] = m_pTreeNode;
    }
    else
    {
        hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_buildTreeInternal(aabbs16.m_data, keys, n, m_kNodeCollection, out, 0);
    }

    UpdateBoundsNode(m_kNodeCollection, m_pTreeNode, 0x7fff);
    TraverseNodeTree(m_kNodeCollection, 0);
}

extern float DAT_0104da48, DAT_0104e148, DAT_01016248;
extern "C" {
void _ReadWriteBarrier();
}
__forceinline void copyCount840(int* a,const int* b){_ReadWriteBarrier();*a=*b;}

// hkAabb construction and assignment were inline in this tree builder.
__forceinline hkAabb::hkAabb() {}
__forceinline void hkAabb::assign(const hkAabb& other) throw() {
 reinterpret_cast<__m128&>(m_kMinimumCorner.x)=reinterpret_cast<const __m128&>(other.m_kMinimumCorner.x);
 _ReadWriteBarrier();
 reinterpret_cast<__m128&>(m_kMaximumCorner.x)=reinterpret_cast<const __m128&>(other.m_kMaximumCorner.x);
}
static __forceinline void setVector(Vec4& v, float x, float y, float z, float w = 0.0f) { quad(v) = _mm_setr_ps(x, y, z, w); }
struct Source840 {
 unsigned short minimum[3],maximum[3];
 __forceinline void center(Vec4& result) const {
  Vec4::Aligned low(Vec4::Uninitialized);
  setVector(low,(float)minimum[0],(float)minimum[1],(float)minimum[2]);
  setVector(result,(float)maximum[0],(float)maximum[1],(float)maximum[2]);
  quad(result)=_mm_mul_ps(_mm_add_ps(quad(result),quad(low)),_mm_set_ps1(DAT_01016248));
 }
};
struct Node840 { int unk00,unk04,unk08; union { int key; unsigned short children[2]; }; unsigned short flags,escape; };
struct ParentAlias840 {Node840* value;};
struct Task840 {
    static __forceinline void* operator new(unsigned int, void* destination) { return destination; }
    Task840() {}
    Task840(const Task840& other) { memcpy(this, &other, sizeof(*this)); }
    hkAabb bounds;
    unsigned short start,unused22;
    int count;
    Node840* node;
    int unused2c;
};
struct Words840 { unsigned short* data; int count; unsigned int capacity; };
struct Tasks840 {
    Task840* data;
    int count;
    unsigned int capacity;
    Task840 local[64];
};
struct Manager840 {
    Node840* GetEntryOffset(unsigned short index);
    Node840* PopGlyphRecord(Node840** root, int* rootIndex, int* index);
};
void __cdecl Bounds_PartitionOnLongestAxis(Task840* task,const Source840* source,Words840* indices,unsigned short start,int count,hkAabb* left,hkAabb* right,int* leftCount,int* rightCount);
struct Tree840 {
    int unk00,unk04,unk08,unk0c;
    Node840* root;
    int rootIndex,numLeaves;
    Manager840 manager;
    __forceinline Node840* allocate(int& index) { return manager.PopGlyphRecord(&root,&rootIndex,&index); }
    __forceinline Node840* lookup(unsigned short index) { return manager.GetEntryOffset(index); }
    void hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_buildTreeInternal(const Source840* source,const int* keys,int count,Node840* rootNode,Words840& mapping,unsigned char reuse);
};
// @fnv 0x00d9c840
// src: XBOX_PDB 0x00d9c840
void Tree840::hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_buildTreeInternal(const Source840* source,const int* keys,int count,Node840* rootNode,Words840& mapping,unsigned char reuse) {
    Words840 indices;
    indices.data=0;
    indices.count=0;
    indices.capacity=0x80000000;
    hkMemoryRouter* holder=hkMemoryRouter_getInstance();
    Allocator* heap=reinterpret_cast<Allocator*>(holder->m_heap);
    int capacity=indices.capacity&0x3fffffff;
    if(capacity<count) {
        int newSize=capacity*2;
        if(count>=newSize) newSize=count;
        hkArrayUtil__reserve(heap,(void**)&indices.data,newSize,2);
    }
    indices.count=count;
    for(int i=0;i<count;++i) indices.data[i]=(unsigned short)i;
    Tasks840 tasks;
    tasks.data=tasks.local;
    tasks.capacity=0x80000040;
    Vec4::Aligned minBounds(Vec4::Uninitialized),maxBounds(Vec4::Uninitialized);
    quad(minBounds)=_mm_set_ps1(DAT_0104da48);
    quad(maxBounds)=_mm_set_ps1(DAT_0104e148);
    for(int i=0;i<count;++i) {
        Vec4::Aligned center(Vec4::Uninitialized);
        source[i].center(center);
        quad(minBounds)=_mm_min_ps(quad(minBounds),quad(center));
        quad(maxBounds)=_mm_max_ps(quad(maxBounds),quad(center));
    }
    tasks.count=1;
    tasks.local[0].start=0;
    tasks.local[0].count=count;
    reinterpret_cast<__m128&>(tasks.local[0].bounds.m_kMinimumCorner.x)=quad(minBounds);
    reinterpret_cast<__m128&>(tasks.local[0].bounds.m_kMaximumCorner.x)=quad(maxBounds);
    tasks.local[0].node=rootNode;
    do {
        Task840 current=tasks.data[tasks.count-1];
        --tasks.count;
        if(current.count<=2) {
            int first=current.start*2;
            unsigned short* cursor=current.node->children;
            for(int i=2;i!=0;--i) {
                int sourceIndex=*(unsigned short*)((char*)indices.data+first);
                int outputIndex;
                int nodeIndex;
                Node840* node;
                if(reuse) {
                    nodeIndex=outputIndex=mapping.data[sourceIndex];
                    node=lookup((unsigned short)nodeIndex);
                } else {
                    node=allocate(outputIndex); nodeIndex=outputIndex;
                }
                mapping.data[sourceIndex]=(unsigned short)nodeIndex;
                const int* data=(const int*)&source[sourceIndex];
                node->unk00=data[0];
                node->unk04=data[1];
                node->unk08=data[2];
                node->key=keys[sourceIndex];
                node->flags|=0x8000;
                *cursor++=(unsigned short)nodeIndex;
                first+=2;
            }
        } else {
            hkAabb bounds[2];
            int sizes[2];
            Bounds_PartitionOnLongestAxis(&current,source,&indices,current.start,current.count,&bounds[0],&bounds[1],&sizes[0],&sizes[1]);
            Task840 children[2];
            int i=0;
            int start=0;
            __declspec(align(16)) hkAabb* boundsCursor=bounds;
            ParentAlias840 parent;parent.value=current.node;

            for(;i<2;++i) {
                int outputIndex;
                int nodeIndex;
                if(sizes[i]>1) {
                    Node840* node=allocate(outputIndex); nodeIndex=outputIndex;
                    children[i].node=node;
                    int copied=sizes[i];copyCount840(&children[i].count,&copied);
                    children[i].bounds.assign(*boundsCursor);
                    children[i].start=(unsigned short)(current.start+i*sizes[0]);
                } else {
                    int sourceIndex=indices.data[current.start+start];
                    Node840* node;
                    if(reuse) {
                        nodeIndex=outputIndex=mapping.data[sourceIndex];
                        node=lookup((unsigned short)nodeIndex);
                    } else {
                        node=allocate(outputIndex); nodeIndex=outputIndex;
                    }
                    const int* data=(const int*)&source[sourceIndex];
                    node->unk00=data[0];
                    node->unk04=data[1];
                    node->unk08=data[2];
                    node->key=keys[sourceIndex];
                    node->flags|=0x8000;
                    mapping.data[sourceIndex]=(unsigned short)nodeIndex;
                }
                ++boundsCursor;
                start+=sizes[0];
                parent.value->children[i]=(unsigned short)nodeIndex;
            }
            for(int i=1;i>=0;--i) {
                if(sizes[i]>1) {
                    hkMemoryRouter* holder=hkMemoryRouter_getInstance();
                    Allocator* allocator=reinterpret_cast<Allocator*>(holder->m_heap);
                    if(tasks.count==(int)(tasks.capacity&0x3fffffff))
                        ResizeAudioStream(allocator,(UnsignedShortArray*)&tasks,48);
                    Task840* dest=&tasks.data[tasks.count];
                    new(dest) Task840(children[i]);
                    ++tasks.count;
                }
            }
        }
    } while(tasks.count);
    hkMemoryRouter* taskHolder=hkMemoryRouter_getInstance();
    Allocator* taskHeap=reinterpret_cast<Allocator*>(taskHolder->m_heap);
    tasks.count=0;
    if((tasks.capacity&0x80000000)==0) taskHeap->Free(tasks.data,(tasks.capacity&0x3fffffff)*48);
    tasks.data=0;
    tasks.capacity=0x80000000;
    hkMemoryRouter* wordHolder=hkMemoryRouter_getInstance();
    Allocator* wordHeap=reinterpret_cast<Allocator*>(wordHolder->m_heap);
    indices.count=0;
    if((indices.capacity&0x80000000)==0) wordHeap->Free(indices.data,(indices.capacity&0x3fffffff)*2);
    indices.data=0;
    indices.capacity=0x80000000;
}
