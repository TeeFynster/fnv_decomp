#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form

// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree_gs_nogs_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/hkaabbtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkArray.h"

__forceinline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }
__forceinline const float& hkVector4::operator()(int i) const { return m_vComponents.m128_f32[i]; }
__forceinline float& hkVector4::operator()(int i) { return m_vComponents.m128_f32[i]; }

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
    hkVector4 v0;
    hkVector4 v1;
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
namespace fnvc_adapt { hkMemoryRouter& __cdecl hkMemoryRouter_getInstance(); }
void __cdecl hkArrayUtil__reserve(S_00d9d650_Heap& alloc, void* array, int reqCapacity, int sizeElem);
template <typename T>
struct S_00d9d650_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d9d650_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d9d650_Array() throw() { _clearAndDeallocate(*reinterpret_cast<S_00d9d650_Heap*>(fnvc_adapt::hkMemoryRouter_getInstance().GetAllocator())); }

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
    void SetSizeAndGrow(int n) { _setSize(*reinterpret_cast<S_00d9d650_Heap*>(fnvc_adapt::hkMemoryRouter_getInstance().GetAllocator()), n); }
};
struct S_00d9d650_Aabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
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
extern hkVector4 DAT_01267e30;
struct Range {
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    Range() : m_kPointA(0), m_kPointB(0), m_iThirdValue(0x80000000u) {}
};
struct FUN_00d9c110_cls {
    virtual ~FUN_00d9c110_cls();
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    Range m1c;
    Range m28;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    hkVector4 m40;
    hkVector4 m50;
    hkVector4 m60;
    hkVector4 m70;
    FUN_00d9c110_cls();
};
struct Handle_d9c4 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int m_pOwnerObject;
    int unk2C;
    Handle_d9c4() { m_pOwnerObject = 0; }
};
struct HandlePool_d9c4 {
    hkArray<Handle_d9c4> m_handles;
    hkArray<int> m_kFreeListEntries;
    void hkAabbTree_struct_hkAabbTreeData_hkAabbTreeAabb_unsigned_int_NodeManager_reserve(int newSize, Handle_d9c4** ppHandle, const int* pIndex);
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern const __m128 DAT_011b6d70;

struct S00d9c610_Aabb {
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct __declspec(align(16)) S00d9c610_AabbUint32 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_expansionMin0, m_expansionMin1, m_expansionMin2;
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_expansionMax0, m_expansionMax1, m_expansionMax2;
    unsigned char m_expansionMaxXYZ;
};

__forceinline void S00d9c610_convertToUint32WithClip(const hkVector4& in, const hkVector4& offset, const hkVector4& scale, const hkVector4& minv, const hkVector4& maxv, unsigned int* out)
{
    hkVector4 x;
    x.setAdd4(in, offset);
    x.mul4(scale);
    x.setMin4(x, maxv);
    x.setMax4(x, minv);

    out[0] = static_cast<unsigned int>(fnv_FloatToInt(x(0)));
    out[1] = static_cast<unsigned int>(fnv_FloatToInt(x(1)));
    out[2] = static_cast<unsigned int>(fnv_FloatToInt(x(2)));
    out[3] = static_cast<unsigned int>(fnv_FloatToInt(x(3)));
}

__forceinline void S00d9c610_convertAabbToUint32(const S00d9c610_Aabb& aabb, const hkVector4& offsetLow, const hkVector4& offsetHigh, const hkVector4& scale, S00d9c610_AabbUint32& aabbOut)
{
    hkVector4 maxVal; maxVal.m_vComponents = DAT_011b6d70;
    S00d9c610_convertToUint32WithClip(aabb.m_kMinimumCorner, offsetLow, scale, DAT_01267e30, maxVal, aabbOut.m_kMinimumCorner);
    S00d9c610_convertToUint32WithClip(aabb.m_kMaximumCorner, offsetHigh, scale, DAT_01267e30, maxVal, aabbOut.m_kMaximumCorner);
}

struct S00d9c610_TreeAabb16 {
    unsigned short m_max0, m_max1, m_max2;
    unsigned short m_min0, m_min1, m_min2;
    static __forceinline void convertAabbToTreeSpace(const S00d9c610_AabbUint32& volumeIn, S00d9c610_TreeAabb16& volumeOut)
    {
        volumeOut.m_max0 = (unsigned short)(volumeIn.m_kMaximumCorner[0] >> 15);
        volumeOut.m_min0 = (unsigned short)(volumeIn.m_kMinimumCorner[0] >> 15);
        volumeOut.m_max1 = (unsigned short)(volumeIn.m_kMaximumCorner[1] >> 15);
        volumeOut.m_min1 = (unsigned short)(volumeIn.m_kMinimumCorner[1] >> 15);
        volumeOut.m_max2 = (unsigned short)(volumeIn.m_kMaximumCorner[2] >> 15);
        volumeOut.m_min2 = (unsigned short)(volumeIn.m_kMinimumCorner[2] >> 15);
    }
    static __forceinline void convertAabbToTreeSpace(const S00d9c610_Aabb& volume, const hkVector4& bitOffsetLow, const hkVector4& bitOffsetHigh, const hkVector4& bitScale, S00d9c610_TreeAabb16& volumeOut)
    {
        S00d9c610_AabbUint32 qAabb;
        S00d9c610_convertAabbToUint32(volume, bitOffsetLow, bitOffsetHigh, bitScale, qAabb);
        convertAabbToTreeSpace(qAabb, volumeOut);
    }
};

struct S00d9c610_Node {
    S00d9c610_TreeAabb16 m_iBufferSize;
    union {
        struct { unsigned short m_childIdx0, m_childIdx1; } m_kChildIndices;
        struct { void* m_ulUserData; } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;
    S00d9c610_Node() : m_usNodeValue(0) {}
    void setSkipNodeIdx(unsigned short idx) { m_iSkipNodeIndex = idx; }
    void setParentNodeIdx(unsigned short idx) { m_usNodeValue = idx | (m_usNodeValue & 0x8000); }
    void setLeafData(void* userData) { m_kLeafData.m_ulUserData = userData; m_usNodeValue |= 0x8000; }
};

struct S00d9c610_NodeManager {
    unsigned short AddRecord(S00d9c610_Node*& rootNode, unsigned short& rootIdx, S00d9c610_Node& node);
    S00d9c610_Node* PopGlyphRecord(S00d9c610_Node*& rootNode, unsigned short& rootIdx, unsigned short& newNodeIdx);
    S00d9c610_Node* GetEntryOffset(unsigned short idx);
};

struct S00d9c610_AabbTree {
    void* vtbl;
    unsigned int unk04, unk08, unk0c;
    S00d9c610_Node* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    S00d9c610_NodeManager m_kNodeManager;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    hkVector4 m_kAabbMin;
    hkVector4 m_kAabbMaximum;
    hkVector4 m_kAabbScale;
    void ProcessEntries_00d9b580(unsigned short insertPointIdx, unsigned short newLeafIdx, unsigned short scratchNodeIdx);
    unsigned short hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_add(const S00d9c610_Aabb& aabb, void* userData);
};

// @fnv 0x00d9c610
// src: XBOX_PDB 0x00d9c610
unsigned short S00d9c610_AabbTree::hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_add(const S00d9c610_Aabb& aabb, void* userData)
{
    S00d9c610_AabbUint32 qAabb;
    S00d9c610_convertAabbToUint32(aabb, m_kAabbMin, m_kAabbMaximum, m_kAabbScale, qAabb);
    unsigned short leafIdx;
    {
        S00d9c610_Node node;
        S00d9c610_TreeAabb16::convertAabbToTreeSpace(qAabb, node.m_iBufferSize);
        node.setLeafData(userData);
        leafIdx = m_kNodeManager.AddRecord(m_pAabbRootNode, m_usManagerValue, node);
    }
    if (m_usManagerValue == 0x7fff)
    {
        S00d9c610_Node* n = m_kNodeManager.GetEntryOffset(leafIdx);
        n->setParentNodeIdx(0x7fff);
        n->setSkipNodeIdx(0x7fff);
        m_pAabbRootNode = n;
        m_usManagerValue = leafIdx;
    }
    else
    {
        unsigned short scratchNodeIdx;
        m_kNodeManager.PopGlyphRecord(m_pAabbRootNode, m_usManagerValue, scratchNodeIdx);
        ProcessEntries_00d9b580(m_usManagerValue, leafIdx, scratchNodeIdx);
    }
    m_iNodeCount++;
    return leafIdx;
}
