// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/collide/tree/aabbtree/hkaabbtree_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/hkaabbtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/Vec4.h"

__forceinline __m128& Vec4::getQuad() { return *reinterpret_cast<__m128*>(&x); }
__forceinline const __m128& Vec4::getQuad() const { return *reinterpret_cast<const __m128*>(&x); }
__forceinline Vec4::Vec4(const Vec4& other) { getQuad() = other.getQuad(); }
__forceinline void Vec4::set(float a, float b, float c, float d) { getQuad() = _mm_setr_ps(a, b, c, d); }
__forceinline void Vec4::add4(const Vec4& value) { getQuad() = _mm_add_ps(getQuad(), value.getQuad()); }
__forceinline void Vec4::sub4(const Vec4& value) { getQuad() = _mm_sub_ps(getQuad(), value.getQuad()); }
__forceinline void Vec4::mul4(const Vec4& value) { getQuad() = _mm_mul_ps(getQuad(), value.getQuad()); }

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
        Allocator* alloc = reinterpret_cast<Allocator*>(&holder->heap());

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
struct TreeAabb
{
    Vec4::Aligned m_kMinimumCorner;
    Vec4::Aligned m_kMaximumCorner;
    void setUnion(const TreeAabb& a, const TreeAabb& b) { m_kMinimumCorner.getQuad() = _mm_min_ps(a.m_kMinimumCorner.getQuad(), b.m_kMinimumCorner.getQuad()); m_kMaximumCorner.getQuad() = _mm_max_ps(a.m_kMaximumCorner.getQuad(), b.m_kMaximumCorner.getQuad()); }
    bool contains(const TreeAabb& o) const { __m128 a = _mm_cmple_ps(m_kMinimumCorner.getQuad(), o.m_kMinimumCorner.getQuad()); __m128 b = _mm_cmple_ps(o.m_kMaximumCorner.getQuad(), m_kMaximumCorner.getQuad()); return (_mm_movemask_ps(_mm_and_ps(a, b)) & 7) == 7; }
};
static __forceinline __m128 vmin(__m128 a, __m128 b) { return _mm_min_ps(a, b); }
static __forceinline __m128 vmax(__m128 a, __m128 b) { return _mm_max_ps(a, b); }
static __forceinline void unionOut(TreeAabb& o, const TreeAabb& a, const TreeAabb& b) { o.m_kMinimumCorner.getQuad() = _mm_min_ps(a.m_kMinimumCorner.getQuad(), b.m_kMinimumCorner.getQuad()); o.m_kMaximumCorner.getQuad() = _mm_max_ps(a.m_kMaximumCorner.getQuad(), b.m_kMaximumCorner.getQuad()); }
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
struct Aabb {
    Vec4::Aligned lo;
    Vec4::Aligned hi;
};
struct Rec {
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
template CurrentTree<S00d9bb50_Aabb,unsigned short>::Node* CurrentTree<S00d9bb50_Aabb,unsigned short>::hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_removeLeafInternal(unsigned short,unsigned short*);
extern __m128 g_aabbQuantMax;
// 0x011b6d70: 2147352576.0f x4
extern __m128 g_vectorZero;
// 0x01267e30
struct TreeHeap {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
void __cdecl hkArrayUtil__reserve(TreeHeap& alloc, void* array, int reqCapacity, int sizeElem) throw();
template <typename T>
struct TreeArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline TreeArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~TreeArray() { _clearAndDeallocate(*reinterpret_cast<TreeHeap*>(hkMemoryRouter_getInstance()->GetAllocator())); }

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
        GrowArrayCapacity(*reinterpret_cast<TreeHeap*>(hkMemoryRouter_getInstance()->GetAllocator()), n);
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

    void hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_buildTreeInternal(TreeAabb16* aabbs, const int* keys, int n, TreeNode16* root, TreeArray<unsigned short>* out, int depth) throw();
    void UpdateBoundsNode(TreeNode16* nodes, unsigned short root, int maxVal) throw();
    void TraverseNodeTree(TreeNode16* nodes, int a) throw();

    __forceinline void convertAabb(const TreeAabb& in, TreeAabb16& out)
    {
        Vec4::Aligned maxVal(Vec4::Uninitialized);
        maxVal.getQuad() = g_aabbQuantMax;
        Vec4::Aligned hi(Vec4::Uninitialized);
        hi.getQuad() = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(m_kVectorAt50, in.m_kMinimumCorner.getQuad()), m_vScale), maxVal.getQuad()), g_vectorZero);
        int hi0 = fnv_FloatToInt(hi.x);
        int hi1 = fnv_FloatToInt(hi.y);
        int hi2 = fnv_FloatToInt(hi.z);
        int hi3 = fnv_FloatToInt(hi.w);

        Vec4::Aligned lo(Vec4::Uninitialized);
        lo.getQuad() = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(in.m_kMaximumCorner.getQuad(), m_kVectorAt40), m_vScale), maxVal.getQuad()), g_vectorZero);
        int lo0 = fnv_FloatToInt(lo.x);
        int lo1 = fnv_FloatToInt(lo.y);
        int lo2 = fnv_FloatToInt(lo.z);
        int lo3 = fnv_FloatToInt(lo.w);

        out.m_kMinimumCorner[0] = (unsigned short)((unsigned int)lo0 >> 15);
        out.m_kMaximumCorner[0] = (unsigned short)((unsigned int)hi0 >> 15);
        out.m_kMinimumCorner[1] = (unsigned short)((unsigned int)lo1 >> 15);
        out.m_kMaximumCorner[1] = (unsigned short)((unsigned int)hi1 >> 15);
        out.m_kMinimumCorner[2] = (unsigned short)((unsigned int)lo2 >> 15);
        out.m_kMaximumCorner[2] = (unsigned short)((unsigned int)hi2 >> 15);
    }

    void hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_build(const TreeAabb* aabbs, const int* keys, int n, TreeArray<unsigned short>* out) throw();
};
extern float DAT_0104da48, DAT_0104e148, DAT_01016248;
extern "C" {
void _ReadWriteBarrier();
}
__forceinline void copyCount840(int* a,const int* b){_ReadWriteBarrier();*a=*b;}
struct Source840 {
 unsigned short minimum[3],maximum[3];
 __forceinline void center(Vec4& result) const {
  Vec4::Aligned low(Vec4::Uninitialized);
  low.set((float)minimum[0],(float)minimum[1],(float)minimum[2]);
  result.set((float)maximum[0],(float)maximum[1],(float)maximum[2]);
  result.getQuad()=_mm_mul_ps(_mm_add_ps(result.getQuad(),low.getQuad()),_mm_set_ps1(DAT_01016248));
 }
};
struct Node840 { int unk00,unk04,unk08; union { int key; unsigned short children[2]; }; unsigned short flags,escape; };
struct ParentAlias840 {Node840* value;};
struct Task840 {
    static __forceinline void* operator new(unsigned int, void* destination) { return destination; }
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


class Sd9_SimdReal
{
public:
    __forceinline Sd9_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline Sd9_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
private:
    __m128 m_vValue;
};


static __forceinline void Sd9_multiply(Vec4& vector, const Sd9_SimdReal& scalar)
{
    vector.getQuad() = _mm_mul_ps(scalar.broadcast(), vector.getQuad());
}
static __forceinline Sd9_SimdReal Sd9_horizontalAdd3(const Vec4& vector)
{
    __m128 xySum = _mm_add_ss(_mm_shuffle_ps(vector.getQuad(), vector.getQuad(), 0x55), vector.getQuad());
    return _mm_add_ss(_mm_shuffle_ps(vector.getQuad(), vector.getQuad(), 0xaa), xySum);
}

template <typename T> __forceinline T Sd9_max2(T x, T y) { return x > y ? x : y; }
template <typename T> __forceinline T Sd9_min2(T x, T y) { return x < y ? x : y; }
__forceinline int Sd9_isNegative(const Sd9_SimdReal& r0) { return _mm_movemask_ps(r0.getQuad()) & 1; }

class Sd9_Bool
{
public:
    __forceinline Sd9_Bool(bool b) { m_cBooleanValue = static_cast<char>(b); }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
private:
    char m_cBooleanValue;
};

struct Sd9_Aabb16
{
    struct Metric
    {
        Vec4::Aligned m_kCenterPosition;
        __forceinline int select(const Sd9_Aabb16& a, const Sd9_Aabb16& b) const;
    };
    __forceinline Metric getMetric() const;
    __forceinline void center(Vec4& centerOut) const;
    __forceinline static void combine(const Sd9_Aabb16& a, const Sd9_Aabb16& b, Sd9_Aabb16& out);
    __forceinline Sd9_Bool contains(const Sd9_Aabb16& other) const;
    __forceinline void includeAabb(const Sd9_Aabb16& aabb);

    unsigned short m_kMaximumCorner[3];
    unsigned short m_kMinimumCorner[3];
};

__forceinline int Sd9_Aabb16::Metric::select(const Sd9_Aabb16& a, const Sd9_Aabb16& b) const
{
    Vec4::Aligned centerA; a.center(centerA);
    Vec4::Aligned centerB; b.center(centerB);
    centerA.sub4(m_kCenterPosition);
    centerB.sub4(m_kCenterPosition);
    centerA.mul4(centerA);
    centerB.mul4(centerB);
    centerB.sub4(centerA);
    int index = Sd9_isNegative(Sd9_horizontalAdd3(centerB));
    return index;
}

__forceinline Sd9_Aabb16::Metric Sd9_Aabb16::getMetric() const
{
    Metric metric;
    center(metric.m_kCenterPosition);
    return metric;
}

__forceinline void Sd9_Aabb16::center(Vec4& centerOut) const
{
    centerOut.set(m_kMaximumCorner[0], m_kMaximumCorner[1], m_kMaximumCorner[2]);
    Vec4::Aligned myMin;
    myMin.set(m_kMinimumCorner[0], m_kMinimumCorner[1], m_kMinimumCorner[2]);
    centerOut.add4(myMin);
    Sd9_multiply(centerOut, 0.5f);
}

__forceinline void Sd9_Aabb16::combine(const Sd9_Aabb16& a, const Sd9_Aabb16& b, Sd9_Aabb16& out)
{
    for (int i = 0; i < 3; i++)
    {
        out.m_kMinimumCorner[i] = Sd9_min2(a.m_kMinimumCorner[i], b.m_kMinimumCorner[i]);
        out.m_kMaximumCorner[i] = Sd9_max2(a.m_kMaximumCorner[i], b.m_kMaximumCorner[i]);
    }
}

__forceinline Sd9_Bool Sd9_Aabb16::contains(const Sd9_Aabb16& other) const
{
    bool outside = false;
    for (int i = 0; i < 3; i++)
    {
        outside |= (m_kMaximumCorner[i] < other.m_kMaximumCorner[i] || other.m_kMinimumCorner[i] < m_kMinimumCorner[i]);
    }
    return !outside;
}

__forceinline void Sd9_Aabb16::includeAabb(const Sd9_Aabb16& aabb)
{
    combine(*this, aabb, *this);
}

struct Sd9_Node
{
    static const unsigned short s_leafMask = 0x7fff;
    static const unsigned short s_leafFlag = 0x8000;

    Sd9_Aabb16 m_iBufferSize;
    union
    {
        struct { unsigned short m_ausChildIndices[2]; } m_kChildIndices;
        struct { void* m_ulUserData; } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;

    unsigned short getParentIdx() const { return m_usNodeValue & s_leafMask; }
    unsigned short getSkipNodeIdx() const { return m_iSkipNodeIndex; }
    unsigned short getChildIdx(int i) const { return m_kChildIndices.m_ausChildIndices[i]; }
    void setSkipNodeIdx(unsigned short idx) { m_iSkipNodeIndex = idx; }
    void setParentNodeIdx(unsigned short idx) { m_usNodeValue = idx | (m_usNodeValue & s_leafFlag); }
    void setChildIdx(int iChild, unsigned short idx) { m_kChildIndices.m_ausChildIndices[iChild] = idx; }
    int isLeaf() const { return m_usNodeValue & s_leafFlag; }
};

struct Sd9_NodeManager
{
    Sd9_Node* m_data;
    int m_iElementCount;
    int m_pRayCursor;
    Sd9_Node* GetEntryOffset(unsigned short idx);
    const Sd9_Node* GetEntryOffset(unsigned short idx) const;
};

inline __declspec(noinline) Sd9_Node* Sd9_NodeManager::GetEntryOffset(unsigned short idx) { return &m_data[idx]; }
inline __declspec(noinline) const Sd9_Node* Sd9_NodeManager::GetEntryOffset(unsigned short idx) const { return &m_data[idx]; }

struct Sd9_Tree
{
    static const unsigned short s_invalidIdx = 0x7fff;
    typedef Sd9_Node Node;

    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0C;
    Node* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    Sd9_NodeManager m_kNodeManager;

    __forceinline Node* getChild(const Node* node, int i) const
    {
        return const_cast<Node*>(m_kNodeManager.GetEntryOffset(node->m_kChildIndices.m_ausChildIndices[i]));
    }
    __forceinline Node* getParent(const Node* node) const
    {
        return ((node->m_usNodeValue & Node::s_leafMask) != s_invalidIdx) ?
            const_cast<Node*>(m_kNodeManager.GetEntryOffset(node->m_usNodeValue & Node::s_leafMask)) : 0;
    }

    void ProcessEntries_00d9b580(unsigned short insertPointIdx, unsigned short newLeafIdx, unsigned short scratchNodeIdx);
};

// @fnv 0x00d9b580
// src: GUESS 0x00d9b580 (confidence: low)
void Sd9_Tree::ProcessEntries_00d9b580(unsigned short insertPointIdx, unsigned short newLeafIdx, unsigned short scratchNodeIdx)
{
    Node* insertPoint = m_kNodeManager.GetEntryOffset(insertPointIdx);
    Node* newLeaf = m_kNodeManager.GetEntryOffset(newLeafIdx);
    Node* scratch = m_kNodeManager.GetEntryOffset(scratchNodeIdx);

    Sd9_Aabb16 volume = newLeaf->m_iBufferSize;
    Sd9_Aabb16::Metric metric = volume.getMetric();

    Node* cur = insertPoint;
    unsigned short curIdx = insertPointIdx;
    int index = 0;
    while (!cur->isLeaf())
    {
        Node* a = getChild(cur, 0);
        Node* b = getChild(cur, 1);
        index = metric.select(a->m_iBufferSize, b->m_iBufferSize);
        curIdx = cur->getChildIdx(index);
        cur = getChild(cur, index);
    }

    Node* parent = getParent(cur);
    unsigned short parentIdx = cur->getParentIdx();

    Sd9_Aabb16::combine(newLeaf->m_iBufferSize, cur->m_iBufferSize, scratch->m_iBufferSize);
    scratch->setChildIdx(0, curIdx);
    scratch->setChildIdx(1, newLeafIdx);
    cur->setParentNodeIdx(scratchNodeIdx);
    newLeaf->setParentNodeIdx(scratchNodeIdx);

    unsigned short skipIdx = cur->getSkipNodeIdx();
    cur->setSkipNodeIdx(newLeafIdx);
    newLeaf->setSkipNodeIdx(skipIdx);
    scratch->setSkipNodeIdx(skipIdx);

    if (parent)
    {
        parent->setChildIdx(index, scratchNodeIdx);
        scratch->setParentNodeIdx(parentIdx);
        if (index == 1)
        {
            Node* n = getChild(parent, 0);
            while (1)
            {
                n->setSkipNodeIdx(scratchNodeIdx);
                if (n->isLeaf())
                {
                    break;
                }
                n = getChild(n, 1);
            }
        }
        do
        {
            if (parent->m_iBufferSize.contains(volume))
            {
                break;
            }
            parent->m_iBufferSize.includeAabb(volume);
            parent = getParent(parent);
        } while (parent);
    }
    else
    {
        m_pAabbRootNode = scratch;
        m_pAabbRootNode->setParentNodeIdx(s_invalidIdx);
        m_usManagerValue = scratchNodeIdx;
    }
}


inline void* operator new(unsigned int, void* p) throw() { return p; }
inline void operator delete(void*, void*) throw() {}

void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);


struct BuildAabb
{
    BuildAabb() : m_kMinimumCorner(Vec4::Uninitialized), m_kMaximumCorner(Vec4::Uninitialized) {}
    void operator=(const BuildAabb& other) { m_kMinimumCorner.getQuad() = other.m_kMinimumCorner.getQuad(); m_kMaximumCorner.getQuad() = other.m_kMaximumCorner.getQuad(); }
    Vec4::Aligned m_kMinimumCorner;
    Vec4::Aligned m_kMaximumCorner;
};

struct BuildTreeNode
{
    BuildAabb m_kBounds;
    int m_children[2];
    unsigned int m_parent;
    int m_next;

    void setLeaf(int key)
    {
        m_children[0] = key;
        m_parent |= 0x80000000;
    }
};

template <typename T>
struct BuildArrayLocalForm
{ // local form of hkArray: 0x00d9d1c0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    BuildArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    BuildArrayLocalForm(T* data, int flags) : m_data(data), m_iCapacityState(flags) {}
    __forceinline ~BuildArrayLocalForm() { _clearAndDeallocate(*reinterpret_cast<S_00d9d650_Heap*>((&hkMemoryRouter_getInstance()->heap()))); }

    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }
    T& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }

    __forceinline void _clearAndDeallocate(S_00d9d650_Heap& alloc)
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
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(*reinterpret_cast<S_00d9d650_Heap*>((&hkMemoryRouter_getInstance()->heap())), n);
        m_iElementCount = n;
    }
    __forceinline T& expandOneUnchecked()
    {
        return m_data[m_iElementCount++];
    }
    __forceinline void AddBack(const T& t)
    {
        S_00d9d650_Heap& alloc = *reinterpret_cast<S_00d9d650_Heap*>((&hkMemoryRouter_getInstance()->heap()));
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)

struct BuildWorkItem
{
    BuildWorkItem() {}
    BuildWorkItem(const BuildWorkItem& other) { memcpy(this, &other, sizeof(*this)); }
    BuildAabb m_kBounds;
    int m_kRayStart;
    int m_uiItemCount;
    BuildTreeNode* m_node;
};

template <typename T, int N>
struct BuildInplaceArray : public BuildArrayLocalForm<T>
{
    T m_kStorage[N];

    BuildInplaceArray() : BuildArrayLocalForm<T>(m_kStorage, N | 0x80000000)
    {
        this->m_data = m_kStorage;

        this->m_iCapacityState = N | 0x80000000;
    }
};

struct BuildNodePool
{
    __declspec(noalias) BuildTreeNode* ComputeValue_00d9a4c0(int index);
    __declspec(noalias) BuildTreeNode* PopItem(BuildTreeNode** root, int* rootIndex, int* indexOut);
};

void __cdecl hkAabb_ProcessEntries_00d9a520(const BuildAabb* item, const BuildAabb* aabbs, BuildArrayLocalForm<int>* indices, int start, int count,
                          BuildAabb* leftAabb, BuildAabb* rightAabb, int* numLeft, int* numRight);

struct BuildTree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BuildTreeNode* m_pTreeNode;
    int m_rootIndex;
    int unk18;
    BuildNodePool m_kNodeCollection;

    void ProcessEntries_00d9d1c0(const BuildAabb* aabbs, const int* keys, int numAabbs, BuildTreeNode* root, BuildArrayLocalForm<int>& nodeIndices, bool reuseNodes);
};

static __forceinline __m128 centerOf(const BuildAabb& b)
{
    __m128 half = _mm_load_ss(&DAT_01016248);
    return _mm_mul_ps(_mm_add_ps(b.m_kMinimumCorner.getQuad(),b.m_kMaximumCorner.getQuad()), _mm_shuffle_ps(half,half,0));
}
static __forceinline void includeCenter(BuildAabb& b,__m128 p)
{
    b.m_kMinimumCorner.getQuad() = _mm_min_ps(b.m_kMinimumCorner.getQuad(),p);
    b.m_kMaximumCorner.getQuad() = _mm_max_ps(b.m_kMaximumCorner.getQuad(),p);
}
// src: GUESS 0x00d9a520 (confidence: low)
__declspec(noinline) void __cdecl hkAabb_ProcessEntries_00d9a520(const BuildAabb* item, const BuildAabb* aabbs, BuildArrayLocalForm<int>* indices, int start, int count,
                          BuildAabb* leftAabb, BuildAabb* rightAabb, int* numLeft, int* numRight)
{
    leftAabb->m_kMinimumCorner.getQuad() = rightAabb->m_kMinimumCorner.getQuad() = _mm_set_ps1(3.40282e+38f);
    leftAabb->m_kMaximumCorner.getQuad() = rightAabb->m_kMaximumCorner.getQuad() = _mm_set_ps1(-3.40282e+38f);
    __m128 sum = _mm_add_ps(item->m_kMaximumCorner.getQuad(),item->m_kMinimumCorner.getQuad());
    float extent[4];
    _mm_store_ps(extent,_mm_sub_ps(item->m_kMaximumCorner.getQuad(),item->m_kMinimumCorner.getQuad()));
    int axis = extent[0] > extent[1] ? 0 : 1;
    if(extent[2] > extent[axis]) axis=2;
    float s[4]; _mm_store_ps(s,sum);
    float mid=s[axis]*0.5f;
    int cut;
    if(extent[axis]*0.5f > 2.384185791015625e-7) {
        int l=start;
        int r=start+count-1;
        do {
            for(;;) {
                __m128 center=centerOf(aabbs[(*indices)[l]]);
                float c[4]; _mm_store_ps(c,center);
                if(c[axis]>mid) break;
                ++l; includeCenter(*leftAabb,center);
            }
            for(;;) {
                __m128 center=centerOf(aabbs[(*indices)[r]]);
                float c[4]; _mm_store_ps(c,center);
                if(c[axis]<=mid) break;
                --r; includeCenter(*rightAabb,center);
            }
            if(l>=r) break;
            int t=(*indices)[l]; (*indices)[l]=(*indices)[r]; (*indices)[r]=t;
            includeCenter(*leftAabb,centerOf(aabbs[(*indices)[l]]));
            includeCenter(*rightAabb,centerOf(aabbs[(*indices)[r]]));
            ++l; --r;
        } while(l<=r);
        cut=l;
    } else {
        cut=start+count/2;
        *leftAabb=*item;
        *rightAabb=*item;
    }
    *numLeft=cut-start;
    *numRight=count-*numLeft;
}

// @fnv 0x00d9d1c0
// src: GUESS 0x00d9d1c0 (confidence: low)
void BuildTree::ProcessEntries_00d9d1c0(const BuildAabb* aabbs, const int* keys, int numAabbs, BuildTreeNode* root, BuildArrayLocalForm<int>& nodeIndices, bool reuseNodes)
{
    BuildArrayLocalForm<int> indices;
    indices.SetSizeAndGrow(numAabbs);
    for (int i = 0; i < numAabbs; i++)
    {
        indices.m_data[i]=i;
    }

    BuildInplaceArray<BuildWorkItem, 64> stack;

    __m128 lo = _mm_set_ps1(3.40282e+38f);
    __m128 hi = _mm_set_ps1(-3.40282e+38f);
    for (int i = 0; i < numAabbs; i++)
    {
        __m128 scalarHalf = _mm_load_ss(&DAT_01016248);
        __m128 center = _mm_mul_ps(_mm_add_ps(aabbs[i].m_kMinimumCorner.getQuad(), aabbs[i].m_kMaximumCorner.getQuad()), _mm_shuffle_ps(scalarHalf,scalarHalf,0));
        lo = _mm_min_ps(lo, center);
        hi = _mm_max_ps(hi, center);
    }

    {
        BuildWorkItem& first = stack.m_data[0];
        stack.m_iElementCount = 1;
        first.m_kRayStart = 0;
        first.m_uiItemCount = numAabbs;
        first.m_kBounds.m_kMinimumCorner.getQuad() = lo;
        first.m_kBounds.m_kMaximumCorner.getQuad() = hi;
        first.m_node = root;
    }

    while (stack.GetLogicalSize())
    {
        BuildWorkItem item = stack.back();
        stack.popBack();

        if (item.m_uiItemCount <= 2)
        {
            int start = item.m_kRayStart;
            BuildTreeNode* parent = item.m_node;
            for (int j = 0; j < 2; j++)
            {
                int idx = indices[start + j];
                int nodeIndex;
                BuildTreeNode* node;
                if (reuseNodes)
                {
                    nodeIndex = nodeIndices[idx];
                    node = m_kNodeCollection.ComputeValue_00d9a4c0(nodeIndex);
                }
                else
                {
                    node = m_kNodeCollection.PopItem(&m_pTreeNode, &m_rootIndex, &nodeIndex);
                }
                nodeIndices[idx] = nodeIndex;
                node->m_kBounds = aabbs[idx];
                node->setLeaf(keys[idx]);
                parent->m_children[j] = nodeIndex;
            }
        }
        else
        {
            BuildAabb childAabbs[2];
            int counts[2];
            int start = item.m_kRayStart;
            hkAabb_ProcessEntries_00d9a520(&item.m_kBounds, aabbs, &indices, start, item.m_uiItemCount, &childAabbs[0], &childAabbs[1], &counts[0], &counts[1]);

            BuildWorkItem children[2];
            
            for (int i = 0; i < 2; i++)
            {
                int count = counts[i];
                int nodeIndex;
                if (count > 1)
                {
                    BuildTreeNode* node = m_kNodeCollection.PopItem(&m_pTreeNode, &m_rootIndex, &nodeIndex);
                    children[i].m_node = node;
                    children[i].m_uiItemCount = count;
                    children[i].m_kBounds = childAabbs[i];
                    children[i].m_kRayStart = item.m_kRayStart + i * counts[0];
                    
                }
                else
                {
                    int idx = indices[item.m_kRayStart + i * counts[0]];
                    BuildTreeNode* node;
                    if (reuseNodes)
                    {
                        nodeIndex = nodeIndices[idx];
                        node = m_kNodeCollection.ComputeValue_00d9a4c0(nodeIndex);
                    }
                    else
                    {
                        node = m_kNodeCollection.PopItem(&m_pTreeNode, &m_rootIndex, &nodeIndex);
                    }
                    
                    node->m_kBounds = aabbs[idx];
                    node->setLeaf(keys[idx]);
                    nodeIndices[idx] = nodeIndex;
                }
                item.m_node->m_children[i] = nodeIndex;

            }

            for (int i = 1; i >= 0; i--)
            {
                if (counts[i] > 1)
                {
                    stack.AddBack(children[i]);
                }
            }
        }
    }
}
