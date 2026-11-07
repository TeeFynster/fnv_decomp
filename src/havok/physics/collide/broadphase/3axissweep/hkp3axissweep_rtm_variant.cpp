#include "../../../../../../include/hkArray.h"
// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Pair.h"

unsigned short MaxUnsignedShort(unsigned short ausLeft, unsigned short ausRight);
BSAudio* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*, void*, int);
struct UnkRet { int x; int y; };
void __fastcall AppendPairToBuffer(UnkRet* apFirst, UnkRet* apSecond, void* apBuffer);
void __fastcall ToggleBit(int aiBitIndex, void* apBits);
struct Entry {
    unsigned short key;
    unsigned short value;
};
Entry* __stdcall LowerBoundEntry(Entry* first, Entry* last, unsigned short key);
struct FUN_00d11960_cls {
    int* m_pEntryData;
    int m_iArrayLength;
    void hkp3AxisSweep_hkpBpAxis_remove(int aiFirst, int aiSecond);
};
struct D1A0E0Allocator;
void __cdecl hkArrayUtil__reserve(D1A0E0Allocator* alloc, void* array, int numElements, int sizeElem);
extern char* g_D1A0E0Tables[2];
struct D1A0E0Entry {
    unsigned short m_flags;
    unsigned short m_uiEdgeIndex;
};
struct D1A0E0IntArray {
    int* m_data;
    int m_iElementCount;
};
// distinct from hkArrayBase: sweep entry remapping method 0x00d1a0e0.
struct D1A0E0EntryArray {
    D1A0E0Entry* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void GrowArrayCapacity(D1A0E0Allocator& alloc, int n)
    {
        const int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(D1A0E0Entry));
        }
    }

    void SetSizeAndGrow(D1A0E0Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void hkp3AxisSweep_hkpBpAxis_removeBatch_1(int offset, const D1A0E0IntArray& remap);
};
struct S_00d1a180_Allocator {
    int unk0;
};
struct S_00d1a180_ArrayUtil {
    static int __cdecl hkArrayUtil__reserve(S_00d1a180_Allocator& alloc, void* arr, int numElem, int elemSize);
};
extern int DAT_011b37b4[2];
struct S_00d1a180_HeapAllocator {
    static S_00d1a180_Allocator& get(const void*) { return *reinterpret_cast<S_00d1a180_Allocator*>((&hkMemoryRouter::getInstance())->m_heap); }
};

struct S_00d1a180_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};
// distinct from hkArrayBase: sweep endpoint remapping method 0x00d1a180.
struct S_00d1a180_Axis {
    S_00d1a180_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void GrowArrayCapacity(S_00d1a180_Allocator& a, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            S_00d1a180_ArrayUtil::hkArrayUtil__reserve(a, this, newSize, sizeof(S_00d1a180_EndPoint));
        }
    }

    void _setSize(S_00d1a180_Allocator& a, int n)
    {
        GrowArrayCapacity(a, n);
        m_iElementCount = n;
    }

    void SetSizeAndGrow(int n)
    {
        _setSize(S_00d1a180_HeapAllocator().get(this), n);
    }

    void RemapEndPoints(char* nodes, const hkArrayBase<int>& remap);
};
void __fastcall staticClearBit(int index, unsigned int* apuiBits);
struct FUN_00d11620_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int m_iA4;
    int getNumObjects();
};
// Reconstructed source for FUN_00d119c0 (forwarding thunk, 24 bytes).
// Target shape:
//   mov edx, [esp+4]            ; handle (first stack arg)
//   mov eax, [edx]              ; handle->unk00 (entry index)
//   shl eax, 4                  ; * 16 (entry stride)
//   add eax, [ecx+0xA0]         ; + &this->entries
//   mov [esp+4], eax            ; forward as first stack arg
//   jmp FUN_00d11650            ; __thiscall tail call, ecx = this preserved
struct UnkHandle {
    int unk00; // entry index read at [handle]
};
struct SweepEntry { // 16-byte entry, matches shl eax,4 stride
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
// Tail-call target observed forwarding (this, handle, entry) with edx = handle kept live:
// __fastcall helper taking (self in ecx, handle in edx, entry on stack).
void __fastcall getAabbFromNode(void* self, UnkHandle* handle, SweepEntry* entry);
// Stand-in owner class for the __thiscall thunk; fnvcheck matches the name FUN_00d119c0.
struct FUN_00d119c0_owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    SweepEntry* unkA0; // entry array base pointer at this+0xA0

    void getAabb_00d119c0(UnkHandle* handle);
};
struct HkHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct PairEntry {
    int m_pHeadNode;
    int m_iSecondInteger;
};
struct PairArray {
    PairEntry* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};
struct FUN_00d11c10_cls {
    int unk00;
    int unk04;
    int unk08;
    int m_0C;
};
void __fastcall AppendPairEntry(FUN_00d11c10_cls* pFirst, FUN_00d11c10_cls* pSecond, PairArray* arr);
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);
BSAudio* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*, void*, int);
void __fastcall AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);
struct FnvNode {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
};
struct FnvArr {
    void* m_data;
    int m_uiItemCount;
    unsigned int m_cap;
};
struct FnvPair8 {
    unsigned int first;
    unsigned int second;
};
struct FnvHolderTail {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(void* base, FnvNode* pNode, unsigned short ausValue, FnvNode* pOther, FnvArr* pPairArr);
struct FUN_00d11da0_cls;
struct FUN_00d11da0_holder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};
struct FUN_00d11da0_entry {
    unsigned short key;
    unsigned short value;
};
void __cdecl hkArrayUtil__reserve(void* allocator, FUN_00d11da0_cls* self, unsigned int newCap, int elemSize);
struct FUN_00d11da0_cls {
    FUN_00d11da0_entry* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;

    void InsertPair(unsigned int a1, unsigned int a2, unsigned short a3,
                      unsigned short a4, unsigned short* outIndex2, unsigned short* outIndex);
};
struct S_00d138a0_Pair {
    int unk00;
    int unk04;
};
struct S_00d138a0_Array {
    S_00d138a0_Pair* unk00;
    int unk04;
    unsigned int unk08;
};
struct S_00d138a0_Node {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    int unk0c;
};
void __cdecl CollectNodePairs(int unused, S_00d138a0_Node* node, int count, S_00d138a0_Array* out);
struct AllocIface {
    virtual void* unk00();
    virtual void* Alloc(unsigned int size);
};
struct SpawnedObject {
    int unk00;
    unsigned short m_wSize;

    SpawnedObject* Init(int a, int b, int c);
};
SpawnedObject* hk3AxisSweep16CreateBroadPhase(int a, int b, int c);
int __cdecl getMinComponent(const float* afValues, float* pfMin);
extern int DAT_011b37a4[];
struct hkp3AxisSweep;
struct Endpoint {
    unsigned short value;
    unsigned short handle;
};
struct S_00d19d90_Class {
    Endpoint* m_endpoints;
    void MergeSortedEndpoints(void* pLookup, int totalCount, Endpoint* pSrc2, int count2);
};
// hkp3AxisSweep endpoint (Havok hkpBpEndPoint: 16-bit value, 16-bit node index; 4 bytes)
struct BpEndPoint {
    unsigned short key;
    unsigned short hi;
};
struct FUN_00d19ef0_cls {
    BpEndPoint* m_pItems;
    void ProcessEntries_00d19ef0(char* out, int n, BpEndPoint* src, int k);
};
void __cdecl hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(unsigned int* auiValues, int lo, int hi, int auiUnused);
void __cdecl QuickSortByLowWord(unsigned int* auiArray, int lo, int hi, int auiUnused);
static int staticIsBitSet(void* self, int index, unsigned int* apuiBits);
int IsBitmapBitSet(void* table, int index, unsigned int* bits);
extern int DAT_011b37a4[];
class FUN_00d11120_cls {
public:
    Endpoint* m_endpoints;
    void MergeEndpoints(char* cells, int n, int m,
                      unsigned int axis, Endpoint* scratch);
};
// Adapted from an unverified prior attempt by another contributor; original author/model unknown.
struct S_d11790_Node { unsigned short m_usValue00, m_usValue02, m_usValue04, m_usValue06, m_usValue08, m_usValue0A; unsigned short unk0c, unk0e; };
struct S_d11790_Edge { unsigned short value; unsigned short handle; };
typedef unsigned short S_d11790_Node::* S_d11790_Field;
static __forceinline void S_d11790_Fix(S_d11790_Node* nodes, S_d11790_Edge* edges, S_d11790_Node* node, S_d11790_Field field, unsigned h)
{
    unsigned i = node->*field;
    S_d11790_Edge* e = edges + i;
    while (e[0].value == e[-1].value) {
        unsigned p = e[-1].handle;
        if (!(h < p)) break;
        e[0] = e[-1];
        --e;
        nodes[p].*field = i;
        --i;
    }
    e->handle = h;
    unsigned short* currentField = &(node->*field);

    *currentField = i;
}
struct S_d11790_Sweep {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    S_d11790_Node* nodes;
    int unka4;
    int unka8;
    S_d11790_Edge* axis0;
    int unkb0;
    int unkb4;
    S_d11790_Edge* axis1;
    int unkbc;
    int unkc0;
    S_d11790_Edge* axis2;
    void FixNodeEdges(unsigned h);
};
extern "C" int __cdecl hkStatisticsCollector_getAllocatedSize(const void* ptr, int size);
struct FourIntegerBlock {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};
struct UnsignedShortPair {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};
struct OverlappingMarkerInfo {
    int unk00;
    hkArray<unsigned short> m_overlappingMarkers;
};
template <typename T>
__forceinline void addArray(hkStatisticsCollector* collector, const char* name, const hkArray<T>& arr)
{
    if ((arr.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations) {
        void* data = arr.m_data;
        int capacity = arr.m_iCapacityState & 0x3fffffff;
        int allocated = hkStatisticsCollector_getAllocatedSize(data, capacity * sizeof(T));
        collector->AddMemoryChunk(3, name, arr.m_data, arr.m_iElementCount * sizeof(T), allocated);
    }
}
struct S_00d119e0 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;

    hkArray<FourIntegerBlock> m_kNodeCollection;
    hkArray<UnsignedShortPair> m_axis0;
    hkArray<UnsignedShortPair> m_axis1;
    hkArray<UnsignedShortPair> m_axis2;
    int m_iMarkerCount;
    int unkD4;
    OverlappingMarkerInfo* m_pOverlappingMarkerInfo;

    void ReportStatistics(hkStatisticsCollector* collector, const void* cls);
};
BSAudio* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkMemoryRouter_easyFree(void*, void*) throw();
struct Allocator_00d182e0 {
    virtual void unk00() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual void unk0c() throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
};
struct Node_00d182e0 {
    int unk00; int unk04; int unk08; int unk0c;
};
struct EndPoint_00d182e0 {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
};
struct SubNode_00d182e0 {
    int unk00;
    hkArray<unsigned short> m_ppData;
};
struct BroadPhaseBase {
    virtual ~BroadPhaseBase() throw();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00d182e0 : public BroadPhaseBase {
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    hkArray<Node_00d182e0> m_kNodeCollection;
    hkArray<EndPoint_00d182e0> m_kAxisEndPoints[3];
    int m_numSubNodes;
    int unkD4;
    SubNode_00d182e0* m_subNodes;

    virtual ~FUN_00d182e0() throw();
};
int __cdecl hkp3AxisSweep_getType();
void __cdecl nullsub_73();
template <typename T>
static void constructWithCopy(T* p, int n, const T& t) {
    for (int i = 0; i < n; i++) {
        p[i] = t;
    }
}
template <typename T>
static void construct(T* p, int n) {
    for (int i = 0; i < n; i++) {
    }
}
struct SmallArray {
    unsigned short* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;

    void _pushBack(Allocator& alloc, const unsigned short& val) {
        if (m_iElementCount == (int)(m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(&alloc, this, sizeof(unsigned short));
        }
        constructWithCopy(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }

    void AddBack(const unsigned short& val) {
        _pushBack(*reinterpret_cast<Allocator*>((&hkMemoryRouter::getInstance())->m_heap), val);
    }

    int indexOf(const unsigned short& val) const {
        for (int i = 0; i < m_iElementCount; i++) {
            if (m_data[i] == val)
                return i;
        }
        return -1;
    }

    void removeAt(int index) {
        m_iElementCount--;
        if (m_iElementCount != index) {
            m_data[index] = m_data[m_iElementCount];
        }
    }
};
struct TargetStruct {
    int unk00;
    SmallArray m_ppData;
};
struct BroadPhasePairArray : S_00d138a0_Array {
    S_00d138a0_Pair& _expandOne(Allocator& alloc) {
        if (unk04 == (int)(unk08 & 0x3fffffff)) {
            ResizeAudioStream(&alloc, this, sizeof(S_00d138a0_Pair));
            construct(unk00 + unk04, 1);
        }
        return unk00[unk04++];
    }

    S_00d138a0_Pair& AllocatePair() {
        return _expandOne(*reinterpret_cast<Allocator*>((&hkMemoryRouter::getInstance())->m_heap));
    }
};
struct C_00d13620 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    void* m_unkD8;

    void BuildBroadPhasePairs(S_00d138a0_Node* nodesA, int numNodesA, S_00d138a0_Node* nodesB, int numNodesB, int mode, BroadPhasePairArray& pairs);
};
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
// Broad-phase endpoint sweep with two inline active-node sets.
void __cdecl ResizeAudioStream(void*, void*, int);
struct U16 { unsigned short v; };
struct ShortVec {
    U16* m_00; int m_04; int m_08;
};
struct LocalVec {
    U16* m_00; int m_04; int m_08;
    U16 m_0c[256];
};
struct EntryLocal {
    unsigned short m_00; unsigned short m_02;
};
struct Record {
    int m_00; int m_04; int m_08; int m_0c;
};
struct ObjX {
    int m_00;
    ShortVec m_04v;
};
struct PairVec {
    Pair* m_00; int m_04; int m_08;
};
struct ThisCls {
    int m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c; int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44; int m_48; int m_4c; int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c; int m_70; int m_74; int m_78; int m_7c;
    int m_80; int m_84; int m_88; int m_8c; int m_90; int m_94; int m_98; int m_9c;
    Record* m_a0; int m_a4; int m_a8;
    int* m_ac; int m_b0;
    int m_b4; int m_b8; int m_bc; int m_c0; int m_c4; int m_c8; int m_cc; int m_d0; int m_d4;
    char* m_d8;
    void queryBatchAabbSub(unsigned int* bits, PairVec* out, char flag);
};
static int FindIdx(const U16* p, int n, unsigned short v)
{
    for (int i = 0; i < n; i++) {
        if (p[i].v == v) return i;
    }
    return -1;
}
static void PushShort(ShortVec* v, unsigned short val)
{
    hkMemoryRouter* h = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ResizeAudioStream(h->m_heap, v, 2);
    v->m_00[v->m_04].v = val;
    v->m_04++;
}
static void PushDynamic(ShortVec* v, unsigned short val)
{
    hkMemoryRouter* h = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ResizeAudioStream(h->m_heap, v, 2);
    U16* p = v->m_00 + *(volatile int*)&v->m_04;
    p->v = val;
    v->m_04++;
}
static void FreeLocalVec(LocalVec& v)
{
    hkMemoryRouter* h = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* ao = reinterpret_cast<hkMemoryAllocator*>(h->m_heap);
    int cap = v.m_08;
    v.m_04 = 0;
    if ((cap & (int)0x80000000) == 0) {
        ao->bufFree(v.m_00, (cap & 0x3fffffff) * 2);
    }
    v.m_00 = 0;
    v.m_08 = (int)0x80000000;
}
static __forceinline void AppendN(PairVec* out, Record* other, Record* rec, int n)
{
    for (int k = 0; k < n; ++k) {
        Pair* p = &out->m_00[out->m_04];
        out->m_04++;
        p->a = other->m_0c;
        p->b = rec->m_0c;
    }
}
static __forceinline void HandlePair(ThisCls* idx, Record* rec, Record* other, PairVec* out, char flag)
{
    Record* second = rec;
    Record* first = other;
    if ((rec->m_0c & 1) == 0) {
        if ((other->m_0c & 1) == 0) {
            hkMemoryRouter* r = (hkMemoryRouter*)hkMemoryRouter_getInstance();
            if (out->m_04 == (out->m_08 & 0x3fffffff))
                ResizeAudioStream(r->m_heap, out, 8);
            AppendN(out, other, rec, 1);
            return;
        }
        first = rec;
        second = other;
    }
    int fidx = (int)((char*)first - (char*)idx->m_a0) >> 4;
    ObjX* obj = (ObjX*)((second->m_0c & 0xfffffffe) + (int)idx->m_d8);
    if (flag != 0) {
        PushDynamic(&obj->m_04v, (unsigned short)fidx);
    } else {
        ShortVec* lv = &obj->m_04v;
        int self = FindIdx(lv->m_00, lv->m_04, (unsigned short)fidx);
        int& cnt = lv->m_04;
        cnt--;
        int last = cnt;
        if (last != self)
            lv->m_00[self] = lv->m_00[last];
    }
}
#include <xmmintrin.h>
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c7170;
extern float DAT_010cd5b0;
struct FUN_00d10e10_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    __m128 m_negSrc;   // +0x40
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    __m128 m_recipSrc; // +0x60

    void getExtents(__m128* out0, __m128* out1);
};
void __cdecl Object_DoNothing_00d10e80();
struct S00d11470_Entry {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
};
struct S00d11470_Object {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    char* unkA0;
};
struct S00d11470_Owner {
    bool __thiscall areAabbsOverlapping(int* first, int* second);
};
void __cdecl hkArrayUtil__reserve(void* alloc, void* self, int newCap, int elemSize);
struct FUN_00d11e80_cls {
    S_00d1a180_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int InsertEndpoints(char* nodes, int axis, S_00d1a180_EndPoint* newEndpoints, int numNew);
};
extern "C" void _ReadWriteBarrier(void);
struct d11Out {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct d11Node {
    int unk00;
    int unk04;
    int unk08;
    int m_flags;
};
struct d11Pair {
    float minX, minY, minZ, minW;
    float maxX, maxY, maxZ, maxW;
};
struct d11Heap { int unk00, unk04, unk08, unk0c; void* m_pAllocator; };
struct d11Sweep {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    d11Node* m_pNodes;
    int m_iArrayLength;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_iBase;

    void FUN_00d11fa0(d11Out& __restrict out);
};
struct SweepEndpoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    SweepEndpoint() {}
    SweepEndpoint(unsigned short val, unsigned short idx) : m_uiFilterValue(val), m_usIndex(idx) {}
};
inline void* operator new(unsigned int, void* p) { return p; }
template <typename T>
inline void S00d13950_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i) {
        new (p + i) T(t);
    }
}
template <typename T>
__forceinline void hkArrayBase<T>::pushBackUnchecked(const T& t)
{
    S00d13950_constructWithCopy<T>(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}
struct SweepNode {
    unsigned short m_min1;
    unsigned short m_min2;
    unsigned short m_max1;
    unsigned short m_max2;
    unsigned short m_min0;
    unsigned short m_max0;
};
struct S00d13950_Less {};
void __cdecl hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(SweepEndpoint* base, int lo, int hi, S00d13950_Less cmp);
template <typename T, typename L>
inline void S00d13950_quickSort(T* pArr, int iSize, L cmpLess)
{
    if (iSize > 1) {
        hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(pArr, 0, iSize - 1, cmpLess);
    }
}
struct SweepClass {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    hkArray<SweepEndpoint> m_kAxisEndPoints[3];

    void calcAabbCacheInternal(const hkArray<SweepNode*>& nodes, hkArray<SweepEndpoint>* tempAxes);
};
BSAudio* __cdecl hkMemoryRouter_getInstance() throw();
template <typename T>
struct HkDynamicArray {
    T* m_data;
    int m_iCapacityState;

    __forceinline HkDynamicArray(int n) throw() {
        allocate(*hkMemoryRouter::getInstance()->m_aiEntries, n);
    }
    __forceinline void allocate(hkMemoryAllocator& alloc, int n) throw() {
        int num = n;
        m_data = num ? alloc._bufAlloc<T>(num) : 0;
        m_iCapacityState = num ? num : (int)0x80000000;
    }

    __forceinline ~HkDynamicArray() throw() {
        release(*hkMemoryRouter::getInstance()->m_aiEntries);
    }
    __forceinline void release(hkMemoryAllocator& alloc) throw() {
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * (int)sizeof(T));
        }
    }

    __forceinline T& operator[](int i) { return m_data[i]; }
};
template <typename T>
__forceinline T* hkTempAlloc(hkMemoryAllocator& alloc, int n, int& capOut) throw() {
    int num = n;
    T* p = num ? alloc._bufAlloc<T>(num) : 0;
    capOut = num ? num : (int)0x80000000;
    return p;
}
template <typename T>
__forceinline void hkTempFree(hkMemoryAllocator& alloc, T* p, int cap) throw() {
    if ((cap & 0x80000000) == 0) {
        alloc.ReturnMemory(p, (cap & 0x3fffffff) * (int)sizeof(T));
    }
}
struct Elem {
    unsigned short m_usValue00;
    unsigned short m_usValue02;
    unsigned short m_usValue04;
    unsigned short m_usValue06;
    unsigned short m_usValue08;
    unsigned short m_usValue0A;
    int* h;
    __forceinline int isMarker() const throw() { return (unsigned)h & 1; }
    __forceinline struct Sub* getMarker(struct Sub* base) const throw() { return (struct Sub*)((char*)base + ((unsigned)h & ~1)); }
};
struct Sub {
    unsigned short x;
    unsigned short x2;
    unsigned short* idx;
    int n;
    int y;
};
struct AxisPair {
    unsigned short* p;
    int n;
    int cap;
};
struct KeyPair {
    unsigned short val;
    unsigned short idx;
};
struct KeyLess { bool operator()(const KeyPair& a, const KeyPair& b) const { return a.val < b.val; } };
void __cdecl QuickSortByLowWord(void*, int, int, KeyLess) throw();
template <typename L>
__forceinline void hkQuickSort(KeyPair* p, int size, L cmp) throw() {
    if (size > 1) {
        QuickSortByLowWord(p, 0, size - 1, cmp);
    }
}
struct Sweep {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    hkArray<Elem> m_kNodeCollection;
    AxisPair m_ac[3];
    int m_d0;
    int m_d4;
    Sub* m_d8;

    void defragment();
    void FixNodeEdges(int) throw();
    __forceinline void setNodeIndex(Elem& node, int i) throw() {
        int* const& h = node.h;
        if (((unsigned)h & 1) == 0) {
            *h = i;
        } else {
            *(unsigned short*)((char*)m_d8 + ((unsigned)h & ~1)) = (unsigned short)i;
        }
    }
};
extern int DAT_011b37ac[2];
struct SweepMerge {
    Endpoint* m_endpoints;
    void MergeEndpointRangesBackward(char* cells, int n, Endpoint* source, int count);
};
__declspec(align(16)) struct FUN_00d1a2a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    __m128 m_v70;
    __m128 m_v80;

    void GetValues(__m128* out0, __m128* out1);
};
struct S_00d1a2d0_Allocator {
    virtual void v0();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00d1a2d0_Base {
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual void v0();
    static void operator delete(void* p)
    {
        S_00d1a2d0_Base* b = static_cast<S_00d1a2d0_Base*>(p);
        reinterpret_cast<S_00d1a2d0_Allocator*>((&hkMemoryRouter::getInstance())->m_heap)->ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};
struct FUN_00d1a2d0 : S_00d1a2d0_Base {
    FUN_00d1a2d0();
    virtual ~FUN_00d1a2d0();
};
#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();
// Havok axis sweep. Based on community near miss nm_5cdcf740ad53441b93a7.
//
// The sweep shape keeps a block of 32 sixteen byte records; every block owns
// a bit mask that marks the records which still overlap the reference record
// of the current sweep.  The overlapping ones are appended to the event list
// of the caller.
struct AudioSink {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* fn0c(int* size);
    virtual void fn10(void* data, int size);
    __forceinline void allocateBlocks(int blocks, void*& buffer, int& masks) {
        if (blocks) {
            int size = blocks * 4;
            void* result = fn0c(&size);
            int actualMasks = size / 4;
            buffer = result;
            // Preserve the buffer store before publishing its allocation flags.
            _ReadWriteBarrier();
            masks = actualMasks;
            return;
        }
        buffer = 0;
    }

};
struct AudioGlobal {
    void* unk00;
    int unk04;
    int unk08;
    AudioSink* sink;
    void* listOwner;
    AudioSink& temp() { return *sink; }
};
struct EventList {
    void* data;
    int count;
    int capacity;
};
struct SweepEvent {
    int* index;
    int value;
};
struct SweepRecord {
    int f00;
    int f04;
    unsigned short f08;
    unsigned short f0a;
    int f0c;
};
struct SweepType {
    unsigned short value;
    unsigned short unk02;
};
struct AxisSweep {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    SweepRecord* records;
    int numRecords;
    int unkA8;
    SweepType* types;
    void hkp3AxisSweep_setBitsBasedOnXInterval(int numRecords, unsigned short code, SweepRecord* rec, int index, void* buffer);
    void reQuerySingleObject(int* index, EventList* events);
};
extern "C" void _ReadWriteBarrier();
struct SweepNodeX {
 unsigned int minimum;
 unsigned int maximum;
 unsigned short lowZ, highZ;
 unsigned int handle;
};
struct SweepGroupX {
 unsigned short node, flags;
 unsigned short* data;
 int size;
 int capacity;
 int find(const unsigned short& value,int start=0,int end=-1) const {
  if(end<0) end=size;
  for(int i=start;i<end;++i) if(data[i]==value) return i;
  return -1;
 }
 void remove(unsigned short value) {
  int i=find(value); removeAt(i);
 }
 void removeAt(int i) { --*(volatile int*)&size;
  if(size!=i) data[i]=data[size];
 }
};
struct SweepAllocatorX {
 virtual void f0(); virtual void f4(); virtual void f8();
 virtual void* allocate(int& bytes);
 virtual void release(void*, int bytes);
};
struct SweepRouterX {
 int u0,u4,u8;
 SweepAllocatorX* stack;
 D1A0E0Allocator* heap;
 static SweepRouterX* __cdecl router();
 D1A0E0Allocator& getHeap() { return *heap; }
 SweepAllocatorX& getStack() { return *stack; }
};
struct SweepPairX {
 unsigned int* first; unsigned int second;
 SweepPairX(unsigned int* a,unsigned int b) : first(a),second(b) {}
};
struct SweepPairsX {
 SweepPairX* data; int size; unsigned int capacity;
 void push(unsigned int* a,unsigned int b) {
  SweepRouterX* r=SweepRouterX::router();
  if(size==(capacity&0x3fffffff)) ResizeAudioStream(r->heap,this,8);
  new(data+size) SweepPairX(a,b);
  ++size;
 }
};
struct SweepNodesX {
 SweepNodeX* data; int size; int capacity;
 void SetSizeAndGrow(int n) {
  D1A0E0Allocator& a=SweepRouterX::router()->getHeap();
  int cap=capacity&0x3fffffff;
  if(cap<n) { int twice=cap*2; hkArrayUtil__reserve(&a,this,n<twice?twice:n,16); }
  size=n;
 }
};
struct SweepAxisX {
 Endpoint* data; int size; int capacity;
 void hkp3AxisSweep_hkpBpAxis_remove(int a,int b);
};
struct SweepOwnerX {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int unk98;
 int unk9c;
 SweepNodesX nodes;
 SweepAxisX axes[3];
 int groupCount;
 unsigned short shiftBits, unusedD6;
 SweepGroupX* groups;
 void hkp3AxisSweep_setBitsBasedOnXInterval(int count,int key,SweepNodeX* node,unsigned int index,unsigned int* bits);
 void hkp3AxisSweep_updateNodesAfterDelete(SweepNodeX* base,int count,SweepNodeX* node);
 void FixNodeEdges(unsigned int index);
 void removeObject(unsigned int* handle,SweepPairsX* pairs);
};
struct CacheNode { unsigned short minY,minZ,maxY,maxZ,minX,maxX; unsigned int handle; };
struct Alloc {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(unsigned int* p, unsigned int size);
};
struct Pool {
    unsigned int m_ptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Alloc* m_alloc;
};
struct Item {
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    volatile unsigned int m_14;
};
struct ItemList {
    Item** m_items;
    int m_uiItemCount;
};
struct Blk {
    unsigned int a; // data pointer
    unsigned int b; // element count
    unsigned int c; // capacity and ownership flags
    unsigned int d; // original local allocation
};
struct CacheOwner {
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74;
    unsigned int unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int m_a0;

    int unkA4, unkA8;
    hkArray<SweepEndpoint> axis[3];
    __declspec(noinline) void calcAabbCacheInternal(Blk* array, unsigned int a2);
    void calcAabbCache(ItemList* a1, unsigned int a2);
};
// src: HAVOK_LIB 0x00d13950
void CacheOwner::calcAabbCacheInternal(Blk* input, unsigned int out) {
    int n=(input->b+1)*2;
    hkArray<SweepEndpoint>* cache=(hkArray<SweepEndpoint>*)out;
    SweepEndpoint* storage=(SweepEndpoint*)(cache+3);
    new(cache) hkArray<SweepEndpoint>(storage,0,n);
    new(cache+1) hkArray<SweepEndpoint>(storage+n,0,n);
    new(cache+2) hkArray<SweepEndpoint>(storage+n*2,0,n);
    SweepEndpoint sentry(0,0);
    cache[0].pushBackUnchecked(sentry);
    cache[1].pushBackUnchecked(sentry);
    cache[2].pushBackUnchecked(sentry);
    CacheNode* const* node=(CacheNode* const*)input->a;
    for(int i=input->b-1;i>=0;--i,++node) {
        cache[0].pushBackUnchecked(axis[0].m_data[(*node)->minX]);
        cache[0].pushBackUnchecked(axis[0].m_data[(*node)->maxX]);
        cache[1].pushBackUnchecked(axis[1].m_data[(*node)->minY]);
        cache[1].pushBackUnchecked(axis[1].m_data[(*node)->maxY]);
        cache[2].pushBackUnchecked(axis[2].m_data[(*node)->minZ]);
        cache[2].pushBackUnchecked(axis[2].m_data[(*node)->maxZ]);
    }
    for(int j=0;j<3;++j) {
        int count=cache[j].m_iElementCount-1;
        if(count>1) hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(cache[j].m_data+1,0,count-1,S00d13950_Less());
    }
    sentry.m_uiFilterValue=0xfffc;
    cache[0].pushBackUnchecked(sentry);
    cache[1].pushBackUnchecked(sentry);
    cache[2].pushBackUnchecked(sentry);
}
#include <xmmintrin.h>
#include <xmmintrin.h>
extern "C" void _ReadBarrier();
template<class T> struct Arr;
struct IAlloc {
template<class T> __forceinline T* BufferAlloc(int& n) {
    int bytes = n * (int)sizeof(T);
    void* p = Alloc(bytes);
    n = bytes / (int)sizeof(T);
    return (T*)p;
}
template<class T> __forceinline T* AllocateBuffer(int& n, unsigned& capacity) {
    T* p = n ? BufferAlloc<T>(n) : 0;
    capacity = n ? n : 0x80000000;
    return p;
}
template<class T> __forceinline void FreeBuffer(T* data, unsigned capacity) {
    if ((capacity & 0x80000000) == 0) this->Free(data, (capacity & 0x3fffffff) * sizeof(T));
}
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void* Alloc(int& size) = 0;
    virtual void Free(void* p, unsigned size) = 0;
};
struct Heap {
    int unk00, unk04, unk08;
    IAlloc* temp;
    IAlloc* main;
    template<class T> void ReleaseTemp(Arr<T>& arr);
};
static Heap* GetHeap() { return (Heap*)hkMemoryRouter_getInstance(); }
void __cdecl hkArrayUtil__reserve(IAlloc* a, void* arr, int cap, int esz);
void __cdecl hkRadixSort_sort16(void* a, int n, void* scratch);
template<class T> struct Arr {
    T* data;
    int size;
    unsigned cap;
    __forceinline void SetSize(int n) {
        SetSize(*GetHeap()->main, n);
    }
    __forceinline void SetSize(IAlloc& a, int n) {
        int c = cap & 0x3fffffff;
        if (c < n) {
            int nc = c * 2;
            if (n >= nc) nc = n;
            hkArrayUtil__reserve(&a, this, nc, sizeof(T));
        }
        size = n;
    }
};
template<class T> __forceinline void Heap::ReleaseTemp(Arr<T>& arr) {
    IAlloc* a=temp;
    arr.size=0;
    if ((arr.cap & 0x80000000) == 0) a->Free(arr.data,(arr.cap & 0x3fffffff)*sizeof(T));
    arr.data=0;arr.cap=0x80000000;
}
template<class T> static __forceinline T* AllocateBuffer(int& n, unsigned& capacity) {
    return GetHeap()->temp->AllocateBuffer<T>(n, capacity);
}
template<class T> static __forceinline void FreeBuffer(T* data, unsigned capacity) {
    GetHeap()->temp->FreeBuffer<T>(data, capacity);
}
struct RawBox { unsigned lower, upper, axis; int* handle; };
struct Box {
    union { struct { unsigned short lo0, lo1; }; unsigned lo01; };
    union { struct { unsigned short hi0, hi1; }; unsigned hi01; };
    union { struct { unsigned short loZ, hiZ; }; unsigned zPair; };
    int* ref;
    void CopyPacked(const Box& b) { *(RawBox*)this = *(const RawBox*)&b; }
    Box& operator=(const Box& b) { CopyPacked(b); return *this; }
};
struct Key { unsigned short key, idx; };
struct RemovedHandle { int idx; };
struct RemovedHandleList { RemovedHandle** items; int count; };
struct Node { unsigned short idx, pad; Arr<unsigned short> arr; };
struct Stub_00d1a040 { int a, b, c; void hkp3AxisSweep_hkpBpAxis_removeBatch_0(Box*, Arr<int>*); };
struct Stub_00d1a0e0 { int a, b, c; void hkp3AxisSweep_hkpBpAxis_removeBatch_1(Box*, Arr<int>*); };
struct Stub_00d1a180 { int a, b, c; void RemapEndPoints(Box*, Arr<int>*); };
void __cdecl CollectNodePairs(void*, Box*, int, int);
struct AssignedSweep {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    Arr<Box> boxes;
    Stub_00d1a040 s_ac;
    Stub_00d1a0e0 s_b8;
    Stub_00d1a180 s_c4;
    int nodeCount;
    int unkD4;
    Node* nodes;
    void BuildBroadPhasePairs(Box*, int, Box*, int, int, int);
    void FixNodeEdges(int);
    void removeObjectBatch(RemovedHandleList*, int);
};

struct SweepDeltaPair { const unsigned short* x; const unsigned short* y; };
struct SweepEdge { unsigned short value,index; };
struct SweepAxis { SweepEdge* data; int size,capacity; };
struct SweepHandle { unsigned index; };
struct __declspec(align(16)) SweepBounds { unsigned v[4]; };
struct SweepBoundsPair { SweepBounds low,high; };
struct SweepBox { unsigned lo[4],hi[4]; };
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(void*,CacheNode*,unsigned,CacheNode*,void*);
void __fastcall RemoveOrAppendTagEntry(void*,CacheNode*,unsigned,CacheNode*,void*);
void __fastcall AppendPairEntry(CacheNode*,CacheNode*,void*);
struct SweepTarget {
 unsigned unk00;
 unsigned unk04;
 unsigned unk08;
 unsigned unk0c;
 unsigned unk10;
 unsigned unk14;
 unsigned unk18;
 unsigned unk1c;
 unsigned unk20;
 unsigned unk24;
 unsigned unk28;
 unsigned unk2c;
 unsigned unk30;
 unsigned unk34;
 unsigned unk38;
 unsigned unk3c;
 unsigned unk40;
 unsigned unk44;
 unsigned unk48;
 unsigned unk4c;
 unsigned unk50;
 unsigned unk54;
 unsigned unk58;
 unsigned unk5c;
 unsigned unk60;
 unsigned unk64;
 unsigned unk68;
 unsigned unk6c;
 unsigned unk70;
 unsigned unk74;
 unsigned unk78;
 unsigned unk7c;
 unsigned unk80;
 unsigned unk84;
 unsigned unk88;
 unsigned unk8c;
 unsigned unk90;
 unsigned unk94;
 unsigned unk98;
 unsigned unk9c;
 CacheNode* nodes;
 unsigned unkA4,unkA8;
 SweepAxis xAxis,yAxis,zAxis;
 unsigned unkD0,unkD4;
 void* pairs;
 template<int Axis> __forceinline unsigned short& minimum(CacheNode& n) { return Axis==0?n.minX:Axis==1?n.minY:n.minZ; }
 template<int Axis> __forceinline unsigned short& maximum(CacheNode& n) { return Axis==0?n.maxX:Axis==1?n.maxY:n.maxZ; }
 __forceinline unsigned yRightFlags(CacheNode* a,CacheNode* b) {SweepDeltaPair p;p.y=&b->maxZ;p.x=&a->maxZ;unsigned short f=(unsigned short)(*p.x-b->minZ)|(unsigned short)(*p.y-a->minZ)|(unsigned short)(a->maxX-b->minX)|(unsigned short)(b->maxX-a->minX);return f;}
 template<int Axis> __forceinline unsigned overlaps(CacheNode* a,CacheNode* b) {
  if(Axis==0) { const unsigned& x=*(const unsigned*)&a->maxY; const unsigned& y=*(const unsigned*)&b->maxY; const unsigned& u=*(const unsigned*)&a->minY; const unsigned& v=*(const unsigned*)&b->minY; return (x-v)|(y-u); }
  unsigned short flags;
  if (Axis==1) flags=(unsigned short)(b->maxZ-a->minZ)|(unsigned short)(a->maxZ-b->minZ)|(unsigned short)(a->maxX-b->minX)|(unsigned short)(b->maxX-a->minX);
  else flags=(unsigned short)(b->maxX-a->minX)|(unsigned short)(a->maxX-b->minX)|(unsigned short)(b->maxY-a->minY)|(unsigned short)(a->maxY-b->minY);
  return flags;
 }
 template<int Axis> __forceinline void added(CacheNode* a,CacheNode* b,unsigned index,void* out) {
  if(Axis==0) hkp3AxisSweep_beginOverlapCheckMarker(pairs,a,index,b,out);
  else AppendPairToBuffer((UnkRet*)a,(UnkRet*)b,out);
 }
 template<int Axis> __forceinline void removed(CacheNode* a,CacheNode* b,unsigned index,void* out) {
  if(Axis==0) RemoveOrAppendTagEntry(pairs,a,index,b,out);
  else AppendPairEntry(a,b,out);
 }
 template<int Axis> __forceinline void updateAxis(CacheNode* allNodes,SweepAxis& axis,CacheNode* node,unsigned index,unsigned low,unsigned high,void* add,void* remove) {
  CacheNode* leftNeighbor; (void)leftNeighbor;
  CacheNode* backNeighbor; (void)backNeighbor;
  CacheNode* rightNeighbor; (void)rightNeighbor;
  CacheNode* outNeighbor; (void)outNeighbor;
  unsigned position=minimum<Axis>(*node);
  SweepEdge* edge=axis.data+position;
  unsigned value=edge[-1].value;
  while(low<value) {
   leftNeighbor=allNodes+edge[-1].index;
   *edge=edge[-1]; --edge;
   if(value&1) {
    unsigned separated=overlaps<Axis>(node,leftNeighbor);
    maximum<Axis>(*leftNeighbor)=(unsigned short)position;
    if(!(separated & (Axis==0?0x80008000:0x8000))) added<Axis>(node,leftNeighbor,index,add);
   } else minimum<Axis>(*leftNeighbor)=(unsigned short)position;
   value=edge[-1].value; --position;
  }
  while(low==edge[-1].value && index<edge[-1].index) {
   unsigned otherIndex=edge[-1].index;
   *edge=edge[-1]; --edge;
   minimum<Axis>(allNodes[otherIndex])=(unsigned short)position; --position;
  }
  edge->index=(unsigned short)index; edge->value=(unsigned short)low; minimum<Axis>(*node)=(unsigned short)position;
  position=maximum<Axis>(*node);edge=axis.data+position;
  value=edge[1].value;
  while(high>value) {
   *edge=edge[1]; ++edge; outNeighbor=allNodes+edge->index; ++position;
   if(!(value&1)) {
    unsigned separated=overlaps<Axis>(node,outNeighbor);
    --minimum<Axis>(*outNeighbor);
    if(!(separated & (Axis==0?0x80008000:0x8000))) added<Axis>(node,outNeighbor,index,add);
   } else --maximum<Axis>(*outNeighbor);
   value=edge[1].value;
  }
  while(high==edge[1].value) {
   unsigned otherIndex=edge[1].index;
   if(index<=otherIndex || otherIndex==0) break; *edge=edge[1]; ++edge;
   --maximum<Axis>(allNodes[otherIndex]); ++position;
  }
  value=edge[-1].value;
  while(high<value) {
   *edge=edge[-1]; backNeighbor=allNodes+edge[-1].index; --edge; --position;
   if(!(value&1)) {
    unsigned separated=overlaps<Axis>(node,backNeighbor);
    ++minimum<Axis>(*backNeighbor);
    if(!(separated & (Axis==0?0x80008000:0x8000))) removed<Axis>(node,backNeighbor,index,remove);
   } else ++maximum<Axis>(*backNeighbor);
   value=edge[-1].value;
  }
  while(high==edge[-1].value && index<edge[-1].index) {
   unsigned otherIndex=edge[-1].index; *edge=edge[-1]; --edge;
   ++maximum<Axis>(allNodes[otherIndex]); --position;
  }
  maximum<Axis>(*node)=(unsigned short)position; edge->value=(unsigned short)high; edge->index=(unsigned short)index;
  position=minimum<Axis>(*node);edge=axis.data+position;value=edge[1].value;
  while(low>value) {
   rightNeighbor=allNodes+edge[1].index; *edge=edge[1]; ++edge; ++position;
   if(value&1) {
    unsigned separated=Axis==1?yRightFlags(node,rightNeighbor):overlaps<Axis>(node,rightNeighbor);
    --maximum<Axis>(*rightNeighbor);
    if(!(separated & (Axis==0?0x80008000:0x8000))) removed<Axis>(node,rightNeighbor,index,remove);
   } else --minimum<Axis>(*rightNeighbor);
   value=edge[1].value;
  }
  while(low==edge[1].value && index>edge[1].index) {
   unsigned otherIndex=edge[1].index;*edge=edge[1];++edge;
   --minimum<Axis>(allNodes[otherIndex]);++position;
  }
  minimum<Axis>(*node)=(unsigned short)position;edge->index=(unsigned short)index;edge->value=(unsigned short)low;
 }
 void hkp3AxisSweep_updateAabbsUint32(SweepHandle**,const SweepBox*,int,void*,void*);
};
// @fnv 0x00d12b80
// src: HAVOK_LIB 0x00d12b80
void SweepTarget::hkp3AxisSweep_updateAabbsUint32(SweepHandle** handles,const SweepBox* boxes,int count,void* add,void* remove) {
 SweepHandle** end; (void)end;
 CacheNode* node; (void)node;
 SweepHandle** current; (void)current;
 CacheNode* base; (void)base;
 unsigned index; (void)index;

 end=handles+count;
 for(current=handles;current<end;++current,++boxes) {
  SweepBoundsPair bounds;
  for(int k=0;k<3;++k) bounds.low.v[k]=boxes->lo[k]>>15;
  for(int k=0;k<3;++k) {
   unsigned v=boxes->hi[k]>>15;
   if(v!=0xffff) ++v;
   bounds.high.v[k]=v|1;
  }

  for(int k=0;k<3;++k) bounds.low.v[k]&=0xfffe;
  base=nodes;
  index=(*current)->index;
  node=base+index;
  updateAxis<0>(base,xAxis,node,index,bounds.low.v[0],bounds.high.v[0],add,remove);
  updateAxis<1>(base,yAxis,node,index,bounds.low.v[1],bounds.high.v[1],add,remove);
  updateAxis<2>(base,zAxis,node,index,bounds.low.v[2],bounds.high.v[2],add,remove);
 }
}
