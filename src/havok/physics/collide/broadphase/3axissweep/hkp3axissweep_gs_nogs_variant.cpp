#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkStatisticsCollector.h"

// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_gs_nogs_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);
void __cdecl ResizeAudioStream(void*, void*, int);
struct UnkRet { int x; int y; };
void __fastcall AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);
void __fastcall ToggleBit(int a, void* b);
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
    static S_00d1a180_Allocator& get(const void*) { return *(S_00d1a180_Allocator*)(&hkMemoryRouter::getInstance())->m_heap; }
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

    void RemapEndPoints(char* nodes, const hkArray<int>& remap);
};
void __fastcall staticClearBit(int index, unsigned int* bits);
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
void __fastcall AppendPairEntry(FUN_00d11c10_cls* self, FUN_00d11c10_cls* other, PairArray* arr);
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);
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
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(void* base, FnvNode* p, unsigned short a1, FnvNode* q, FnvArr* a3);
struct FUN_00d11da0_cls;
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
struct S_00d138a0_Node {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    int unk0c;
};
void __cdecl CollectNodePairs(int unused, S_00d138a0_Node* node, int count, hkArray<S_00d138a0_Pair>* out);
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
int __cdecl getMinComponent(const float* v, float* out);
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
void __cdecl hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(unsigned int* base, int lo, int hi, int unkArg);
void __cdecl QuickSortByLowWord(unsigned int* base, int lo, int hi, int unkArg);
static int staticIsBitSet(void* self, int index, unsigned int* bits);
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
struct BroadPhasePairArray : hkArray<S_00d138a0_Pair> {
    S_00d138a0_Pair& _expandOne(Allocator& alloc) {
        if (m_iElementCount == (int)(m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(&alloc, this, sizeof(S_00d138a0_Pair));
            construct(m_data + m_iElementCount, 1);
        }
        return m_data[m_iElementCount++];
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
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
// Broad-phase endpoint sweep with two inline active-node sets.
void __cdecl ResizeAudioStream(void*, void*, int);
struct AllocObj {
    void** m_vtbl;
};
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
// AppendN stores two Record::m_0c broad-phase handles; no methods bind this record to shared Pair.
struct BroadPhaseHandlePair {
    int m_00; int m_04;
};
struct PairVec {
    BroadPhaseHandlePair* m_00; int m_04; int m_08;
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
    hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ResizeAudioStream(h->m_heap, v, 2);
    v->m_00[v->m_04].v = val;
    v->m_04++;
}
static void PushDynamic(ShortVec* v, unsigned short val)
{
    hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
    if (v->m_04 == (v->m_08 & 0x3fffffff))
        ResizeAudioStream(h->m_heap, v, 2);
    U16* p = v->m_00 + *(volatile int*)&v->m_04;
    p->v = val;
    v->m_04++;
}
static void FreeLocalVec(LocalVec& v)
{
    hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
    AllocObj* ao = (AllocObj*)h->m_heap;
    int cap = v.m_08;
    v.m_04 = 0;
    if ((cap & (int)0x80000000) == 0) {
        typedef void (__thiscall* FreeFn)(AllocObj*, void*, int);
        FreeFn fn = (FreeFn)ao->m_vtbl[4];
        fn(ao, v.m_00, (cap & 0x3fffffff) * 2);
    }
    v.m_00 = 0;
    v.m_08 = (int)0x80000000;
}
static __forceinline void AppendN(PairVec* out, Record* other, Record* rec, int n)
{
    for (int k = 0; k < n; ++k) {
        BroadPhaseHandlePair* p = &out->m_00[out->m_04];
        out->m_04++;
        p->m_00 = other->m_0c;
        p->m_04 = rec->m_0c;
    }
}
static __forceinline void HandlePair(ThisCls* idx, Record* rec, Record* other, PairVec* out, char flag)
{
    Record* second = rec;
    Record* first = other;
    if ((rec->m_0c & 1) == 0) {
        if ((other->m_0c & 1) == 0) {
            hkMemoryRouter* r = (&hkMemoryRouter::getInstance());
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
        ((S_00d1a2d0_Allocator*)(&hkMemoryRouter::getInstance())->m_heap)->ReleaseBlock(p, b->m_usMemSizeAndFlags);
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
struct SweepPairX {
 unsigned int* first; unsigned int second;
 SweepPairX(unsigned int* a,unsigned int b) : first(a),second(b) {}
};
struct SweepPairsX {
 SweepPairX* data; int size; unsigned int capacity;
 void push(unsigned int* a,unsigned int b) {
  hkMemoryRouter* r=(&hkMemoryRouter::getInstance());
  if(size==(capacity&0x3fffffff)) ResizeAudioStream(r->m_heap,this,8);
  new(data+size) SweepPairX(a,b);
  ++size;
 }
};
struct SweepNodesX {
 SweepNodeX* data; int size; int capacity;
 void SetSizeAndGrow(int n) {
  D1A0E0Allocator& a=*(D1A0E0Allocator*)(&hkMemoryRouter::getInstance())->m_heap;
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

#include <math.h>
extern "C" void _ReadWriteBarrier();



struct __declspec(align(16)) RayDirection {
    union { __m128 value; float components[4]; };
    __forceinline float& component(int axis) { return components[axis]; }
    __forceinline void subtract(const RayDirection& origin) {
        value = _mm_sub_ps(value, origin.value);
    }
};

struct SweepEndpointD16300 {
    unsigned short position;
    unsigned short handle;
};




struct SweepAllocator {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void* allocate(unsigned int* byteCount);
    virtual void deallocate(void* memory, unsigned int byteCount);
};

// The router stores the stack allocator in its fourth slot.
static inline SweepAllocator& GetSweepStackAllocator(hkMemoryRouter* router)
{
    return *(SweepAllocator*)router->m_temp;
}

struct SweepScan {
    float origin[4];
    int rayCount;
    float* positions;
    int positionStride;
    hkArray<SweepEndpointD16300>* axes;
};

struct SweepHandle;

struct SweepRayCast {
    virtual void reserved0();
    virtual float intersect(const SweepHandle* handle, int rayIndex);
};

extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;

inline float sweepBound(float x,float offset,float scale) { return (x+offset)*scale; }
inline float sweepSub(float x,float y) { return x-y; }

inline float sweepMin(float a, float b) { return a < b ? a : b; }

struct SweepKeyValues { unsigned int x,y,z,w; };

union SweepScratch { SweepRayCast* collector; float cursorSteps; float curMask; };

struct SweepAllocation { int size; int capacity; };

struct SweepFlag {
    unsigned char value;
    SweepFlag& operator^=(unsigned char mask) { value ^= mask; return *this; }
};


__forceinline SweepEndpointD16300* searchEndpoints(const hkArray<SweepEndpointD16300>& axis,const unsigned int* low,int ordinal,unsigned char* a,int idx) {


    const SweepEndpointD16300* midP=&axis[axis.GetLogicalSize()>>1];
    const SweepEndpointD16300* p;
    
    if (low[ordinal] < midP->position) {
        const SweepEndpointD16300* endP = axis.begin()+axis.GetLogicalSize()-4;
        for(p = &axis[1]; p < endP && p[3].position <= low[ordinal]; p += 4) {
            ((SweepFlag*)a)[p[0].handle] ^= idx;
            ((SweepFlag*)a)[p[1].handle] ^= idx;
            ((SweepFlag*)a)[p[2].handle] ^= idx;
            ((SweepFlag*)a)[p[3].handle] ^= idx;
        }
        for(;p->position <= low[ordinal];++p) ((SweepFlag*)a)[p->handle] ^= idx;
    } else {
        const SweepEndpointD16300* endP = axis.begin()+4;
        for(p = &axis[axis.GetLogicalSize()-2];p >= endP && p[-3].position > low[ordinal];p -= 4) {
            ((SweepFlag*)a)[p[0].handle] ^= idx;
            ((SweepFlag*)a)[p[-1].handle] ^= idx;
            ((SweepFlag*)a)[p[-2].handle] ^= idx;
            ((SweepFlag*)a)[p[-3].handle] ^= idx;
        }
        for(;p->position > low[ordinal];--p) ((SweepFlag*)a)[p->handle] ^= idx;
        ++p;
    }
    return (SweepEndpointD16300*)p;
}

struct SweepNodeD16300 {
    unsigned short minY, minZ, maxY, maxZ, minX, maxX;
    SweepHandle* handle;
    int isMarker() const { return (unsigned int)handle & 1; }
};

struct SweepSpace {
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    float centerOffset[4];
    unsigned int unk50, unk54, unk58, unk5c;
    float reciprocalExtent[4];
    unsigned int unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c;
    SweepNodeD16300* nodes;
    int numNodes;
    unsigned int unkA8;
    hkArray<SweepEndpointD16300> axes[3];
    unsigned int unkD0, unkD4, unkD8;
    float tolerance;
    void hkp3AxisSweep_castRay(const SweepScan& scan, SweepRayCast* rays, int rayStride) const;
};

// @fnv 0x00d16300
// src: XBOX_PDB 0x00d16300
void SweepSpace::hkp3AxisSweep_castRay(const SweepScan& scan, SweepRayCast* rays, int rayStride) const
{
    __declspec(align(16)) unsigned int sweepKeys[4];
    SweepEndpointD16300* c[3];
    int capacity;
    __declspec(align(16)) float distances[4];
    __declspec(align(16)) float bias[4];
    SweepEndpointD16300* nextEndpoint[3];
    __declspec(align(16)) float inverse[4];
    unsigned int inv[3];
    RayDirection direction;

    unsigned int handle;
    (void)handle;
    __m128 node3;
    node3 = _mm_mul_ps(_mm_add_ps(_mm_load_ps(centerOffset), _mm_load_ps(scan.origin)), _mm_load_ps(reciprocalExtent));
    __m128 dist = _mm_setzero_ps();
    node3 = _mm_min_ps(node3, DAT_011b3790);
    node3 = _mm_max_ps(node3, dist);
    node3 = _mm_add_ps(node3, DAT_011b3770);
    _mm_store_ps((float*)sweepKeys, node3);
    SweepKeyValues x = { sweepKeys[0] >> 7, sweepKeys[1] >> 7, sweepKeys[2] >> 7, sweepKeys[3] >> 7 };
    sweepKeys[0] = (unsigned short)x.x;
    sweepKeys[1] = (unsigned short)x.y;
    sweepKeys[2] = (unsigned short)x.z;
    sweepKeys[3] = (unsigned short)x.w;

    unsigned long bytesNeeded = numNodes + 16;
    unsigned char* a;
    SweepScratch scratch;
    SweepAllocator* z = (SweepAllocator*)(&hkMemoryRouter::getInstance())->m_temp;
    int req = bytesNeeded;
    if (req) {
        unsigned int n = req;
        a = (unsigned char*)z->allocate(&n);
        req = n;
    } else {
        a = 0;
    }
    capacity = req ? req : 0x80000000;

    float* nearest = (float*)a;
    for (int n = numNodes >> 4; n >= 0; --n) {
        float* scaled;
        scaled = nearest;
        nearest += 4;
        _mm_store_ps(scaled, dist);
    }

    const hkArray<SweepEndpointD16300>* axesToScan = scan.axes ? scan.axes : axes;
    int idx = 0x11;
    for (int axisIndex = 0; axisIndex < 3; ++axisIndex, idx += idx) {
        nextEndpoint[axisIndex] = searchEndpoints(axesToScan[axisIndex],sweepKeys,axisIndex,a,idx);
    }

    unsigned int n = scan.rayCount;
    hkMemoryRouter* b0;
    b0 = (&hkMemoryRouter::getInstance());
    float* cnt = (float*)b0->m_stack.m_next.m_storage;
    b0->m_stack.m_next.m_storage = (char*)b0->m_stack.m_next.m_storage + ((4 * n + 0x7f) & ~0x7f);
    for (int q = 0; q < scan.rayCount; ++q) {
        cnt[q] = 1.0f;
    }

    const unsigned int* p = (const unsigned int*)a;
    const unsigned int* pEnd = p + (numNodes >> 2) + 1;
    const SweepNodeD16300* node = nodes;
    while (p < pEnd) {
        if (!((p[0] + 0x01010101) & 0x08080808)) {
            if (!((p[1] + 0x01010101) & 0x08080808)) {
                if (!((p[2] + 0x01010101) & 0x08080808)) {
                    node += 12;
                    p += 3;
                    continue;
                }
                node += 8;
                p += 2;
                continue;
            }
            node += 4;
            p++;
            continue;
        }

        const unsigned char* f = (const unsigned char*)p;
        if (f[0] == 0x77 && !node[0].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[0].handle, r);
                float selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }
        if (f[1] == 0x77 && !node[1].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[1].handle, r);
                float selectedDistance;
                selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }
        if (f[2] == 0x77 && !node[2].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[2].handle, r);
                float selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }
        if (f[3] == 0x77 && !node[3].isMarker()) {
            scratch.collector = rays;
            for (int r = 0; r < scan.rayCount; ++r) {
                float bestDistance = cnt[r];
                float zero = scratch.collector->intersect(node[3].handle, r);
                float selectedDistance = sweepMin(bestDistance, zero);
                cnt[r] = selectedDistance;
                scratch.collector = (SweepRayCast*)((char*)scratch.collector + rayStride);
            }
        }

        node += 4;
        p++;
    }

    a[0] = 0x88;
    SweepRayCast* in = rays;
    int nodeCount = numNodes;
    {
        for (int ray = 0; ray < scan.rayCount; ++ray) {
            float scaledDiff = cnt[ray];
            c[0] = nextEndpoint[0];
            c[1] = nextEndpoint[1];
            c[2] = nextEndpoint[2];
            unsigned int* res = (unsigned int*)((char*)scan.positions + ray * scan.positionStride);
            sweepKeys[0] = res[0];
            sweepKeys[1] = res[1];
            sweepKeys[2] = res[2];
            sweepKeys[3] = res[3];
            direction.value = _mm_load_ps((float*)sweepKeys);
            direction.subtract(*(const RayDirection*)scan.origin);


            for (int k = 0; 3 > k; ++k) {
                float zeroOut = direction.component(k) * reciprocalExtent[k];
                float s = fabsf(zeroOut);
                scratch.cursorSteps = (scan.origin[k] + centerOffset[k]) * reciprocalExtent[k];
                if (s < scratch.cursorSteps * 1.1920928955078125e-07 ||
                    s < sweepBound(((float*)sweepKeys)[k], centerOffset[k], reciprocalExtent[k]) * 1.1920928955078125e-07) {
                    inverse[k] = 0.0f;
                    bias[k] = -2.0f;
                } else {
                    inv[k] = 4;
                    float allocator;
                    allocator = 1.0f / zeroOut;
                    if (zeroOut < 0.0f) {
                        inv[k] = -4;
                        c[k] = (SweepEndpointD16300*)((char*)c[k] - 4);
                    }
                    inverse[k] = allocator;
                    bias[k] = allocator * sweepSub(scratch.cursorSteps, tolerance);
                }
            }

            distances[0] = (float)(int)(c[0]->position) * inverse[0] - bias[0];
            distances[1] = (float)(int)(c[1]->position) * inverse[1] - bias[1];
            distances[2] = (float)(int)(c[2]->position) * inverse[2] - bias[2];

            while (true) {
                long node2;
                if (distances[0] < distances[1]) {
                    if (!(distances[0] < distances[2])) {
                        node2 = 2;
                        scratch.curMask = distances[2];
                    } else {
                        node2 = 0;
                        scratch.curMask = distances[0];
                    }
                } else {
                    if (distances[1] < distances[2]) {
                        node2 = 1;
                        scratch.curMask = distances[1];
                    } else {
                        node2 = 2;
                        scratch.curMask = distances[2];
                    }
                }

                if (scratch.curMask > scaledDiff) break;

                unsigned char sweepCursor = (unsigned char)(1 << (node2 + 4));
                do {
                    SweepEndpointD16300* current;
                    current = c[node2];
                    handle = current->handle;
                    unsigned char& fl = a[handle];
                    fl ^= sweepCursor;
                    if (fl >= 0x70) {
                        if (handle == 0) {
                            distances[node2] = 2.0f;
                            break;
                        }
                        const SweepNodeD16300& y = nodes[handle];
                        if (!((unsigned int)y.handle & 1)) {
                            float dimensions = in->intersect(y.handle, ray);
                            if (!(scaledDiff < dimensions)) {
                                scaledDiff = dimensions;
                            }
                        }
                    }
                    unsigned int pos = current->position;
                    _ReadWriteBarrier();
                    SweepEndpointD16300* p;
                    p = c[node2] = (SweepEndpointD16300*)((char*)current + inv[node2]);
                    if ((unsigned short)pos != p->position) {
                        distances[node2] = (float)(int)(p->position) * inverse[node2] - bias[node2];
                        break;
                    }
                } while (true);
            }

            if (ray < scan.rayCount - 1) {
                unsigned int* flagEnd;
                flagEnd = (unsigned int*)a;
                unsigned int* end = (unsigned int*)(a + ((nodeCount >> 2) * 4) + 4);
                for (; flagEnd < end; flagEnd += 2) {
                    unsigned long rayBest;
                    rayBest = flagEnd[0] & 0x0f0f0f0f;
                    unsigned int val = flagEnd[1] & 0x0f0f0f0f;
                    flagEnd[0] = (rayBest << 4) | rayBest;
                    flagEnd[1] = (val << 4) | val;
                }
            }
            in = (SweepRayCast*)((char*)in + rayStride);
        }
    }

    (&hkMemoryRouter::getInstance())->m_stack.m_next.m_storage = (void*)((int)cnt);
    SweepAllocator& endpoint = GetSweepStackAllocator((&hkMemoryRouter::getInstance()));
    if ((capacity & 0x80000000) == 0) {
        endpoint.deallocate(a, capacity & 0x3fffffff);
    }
}
