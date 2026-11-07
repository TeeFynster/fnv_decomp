#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/Pair.h"
#include "../../../../../../include/Vec4.h"

#include "../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../include/hkp3AxisSweep.h"
// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);
BSAudio* __cdecl hkMemoryRouter_getInstance();
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
struct D1A0E0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D1A0E0Allocator* m_pStreamAllocator;

    D1A0E0Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" D1A0E0MemoryRouter& __cdecl D1A0E0GetMemoryRouter();
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
struct S_00d1a180_Router {
    int unk0; int unk4; int unk8; int unkC;
    S_00d1a180_Allocator* m_pStreamAllocator;

    static S_00d1a180_Router& hkMemoryRouter_getInstance();
    S_00d1a180_Allocator& heap() { return *m_pStreamAllocator; }
};
struct S_00d1a180_HeapAllocator {
    static S_00d1a180_Allocator& get(const void*) { return S_00d1a180_Router::hkMemoryRouter_getInstance().heap(); }
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
void __fastcall AppendPairEntry(FUN_00d11c10_cls* self, FUN_00d11c10_cls* other, PairArray* arr);
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
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(void* base, FnvNode* p, unsigned short a1, FnvNode* q, FnvArr* a3);
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
struct S_00d138a0_Heap : BSAudio {
    int unk0c;
    void* unk10;
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
int __cdecl getMinComponent(const float* v, float* out);
extern int DAT_011b37a4[];
struct hkp3AxisSweep;
// hkp3AxisSweep endpoint (Havok hkpBpEndPoint: 16-bit value, 16-bit node index; 4 bytes)
struct Endpoint {
    unsigned short value;
    unsigned short handle;
};
struct S_00d19d90_Class {
    Endpoint* m_endpoints;
    void MergeSortedEndpoints(void* pLookup, int totalCount, Endpoint* pSrc2, int count2);
};
struct FUN_00d19ef0_cls {
    Endpoint* m_pItems;
    void ProcessEntries_00d19ef0(char* out, int n, Endpoint* src, int k);
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
BSAudio* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkMemoryRouter_easyFree(void*, void*) throw();
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
struct Allocator;
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
        _pushBack(reinterpret_cast<Allocator&>((&hkMemoryRouter::getInstance())->heap()), val);
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
        return _expandOne(reinterpret_cast<Allocator&>((&hkMemoryRouter::getInstance())->heap()));
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
    Allocator* ao = reinterpret_cast<Allocator*>(h->m_heap);
    int cap = v.m_08;
    v.m_04 = 0;
    if ((cap & (int)0x80000000) == 0) {
        typedef void (__thiscall* FreeFn)(Allocator*, void*, int);
        FreeFn fn = (FreeFn)(*reinterpret_cast<void***>(ao))[4];
        fn(ao, v.m_00, (cap & 0x3fffffff) * 2);
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
__declspec(align(16)) struct S00d10b30_Node {
    __m64 lo;
    __m64 hi;
};
struct S00d10b30_Bnd {
    short lo0;
    short lo1;
    short lo2;
    short lo3;
    short hi0;
    short hi1;
};
void __stdcall Hkp3axissweepGsEhscNogsNoehsc_ProcessEntries_00d10b30(S00d10b30_Node* nodes, int n, const S00d10b30_Bnd* bnd);
__declspec(align(16)) struct BpRefBounds {
    unsigned short lo0;
    unsigned short lo1;
    unsigned short lo2;
    unsigned short lo3;
    unsigned short hi0;
    unsigned short hi1;
    unsigned short hi2;
    unsigned short hi3;
};
struct BpDeltaPair {
    unsigned int lo;
    unsigned int hi;
};
void __stdcall Object_ProcessEntries_00d10c40(FourIntegerBlock* nodes, int n, int delta, const int* bound);
struct BpBoundNode { __m64 lo; __m64 hi; };
struct BpBoundWords { unsigned short lo0, lo1, lo2, lo3, hi0, hi1; };
struct __declspec(align(16)) ReferenceBounds {
    unsigned short min0, min1, min2, min3;
    unsigned short max0, max1;
    unsigned int maxSentinels;
};
void __stdcall hkp3AxisSweep_updateNodesAfterDelete(BpBoundNode* nodes, int n, const BpBoundWords* bnd);
int fnv_FloatToInt(float fValue);
extern __m128 DAT_011b6d70;
extern __m128 DAT_01267e30;
struct SweepVec4 { __m128 m_vComponents; };
struct SweepAabb { SweepVec4 m_kMinimumCorner; SweepVec4 m_kMaximumCorner; };
struct SweepAabbInt { int m_min0; int m_min1; int m_min2; int m_min3; int m_max0; int m_max1; int m_max2; int m_max3; };
struct SweepCls {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int v14(void* a, SweepAabbInt* b, int c);
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
    SweepVec4 m_kVectorAt40;
    SweepVec4 m_kVectorAt50;
    SweepVec4 m_vScale;
    int hkp3AxisSweep_addObject(void* a1, const SweepAabb& aabb, int a3);
};
// Axis0 candidate-bitset sweep. First argument is updated node count,
// independently confirmed at the real caller; it is not allocation words.
// Destination is16-byte aligned raw bit storage with caller padding.
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
struct S_00d112c0_EndPoint {
    hkUint16 m_uiFilterValue;
    hkUint16 m_usIndex;
};
struct S_00d112c0_Node {
    hkUint16 m_min1, m_min2, m_max1, m_max2;
    hkUint16 m_min0;
    hkUint16 m_max0;
    unsigned int m_handle;
};
struct S_00d112c0_Marker {
    hkUint16 m_usIndex;
    hkUint16 unk2;
    const hkUint16* m_kNode;
    int m_uiItemCount;
    int m_iCapacityState;
};
struct S_00d112c0 {
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    S_00d112c0_Node* m_kNodeCollection;
    int unka4;
    int unka8;
    S_00d112c0_EndPoint* m_ep;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int m_iMarkerCount;
    int m_markerShift;
    S_00d112c0_Marker* m_pOverlappingMarkerInfo;
    void hkp3AxisSweep_setBitsBasedOnXInterval(int numNodes, int key, const S_00d112c0_Node* aabb, hkUint16 skip, hkUint32* bits);
};
inline void flip(hkUint32* bits, int i) {
    int idx = i >> 5;
    bits[idx] ^= 1u << (i & 31);
}
inline void clear(hkUint32* bits, int i) {
    int idx = i >> 5;
    bits[idx] &= ~(1u << (i & 31));
}
extern float DAT_011b3770[4];
extern float DAT_011b3790[4];
struct ObjPrefix { unsigned short f0; unsigned short f1; };
struct Obj8 : ObjPrefix { unsigned short f2; unsigned short f3; unsigned short f4; unsigned short f5; int tail; __forceinline unsigned short& slot0(){return f0;} __forceinline unsigned short& slot1(){return f1;} __forceinline unsigned short& slot2(){return f2;} __forceinline unsigned short& slot3(){return f3;} __forceinline unsigned short& slot4(){return f4;} __forceinline unsigned short& slot5(){return f5;} };
union End8 { struct { unsigned short key; unsigned short id; }; unsigned int packed; };
struct Mgr8;
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(Mgr8* mgr, Obj8* cur, int id, Obj8* other, unsigned int p);
void __fastcall RemoveOrAppendTagEntry(Mgr8* mgr, Obj8* cur, int id, Obj8* other, unsigned int p);
void __fastcall AppendPairToBuffer(Obj8* cur, Obj8* other, unsigned int p);
void __fastcall AppendPairEntry(Obj8* cur, Obj8* other, unsigned int p);
struct __declspec(align(16)) QuantMin40 { unsigned short x,y,z,w; };
struct Vec33 {
    __m128 data;
    __forceinline void setZero() { data=_mm_setzero_ps(); }
    __forceinline void setAdd4(const Vec33& a,const Vec33& b) { data=_mm_add_ps(a.data,b.data); }
    __forceinline void mul4(const Vec33& b) { data=_mm_mul_ps(data,b.data); }
    __forceinline void min4(const Vec33& b) { data=_mm_min_ps(data,b.data); }
    __forceinline void max4(const Vec33& b) { data=_mm_max_ps(data,b.data); }
    __forceinline void add4(const Vec33& b) { data=_mm_add_ps(data,b.data); }
};
struct Bounds33 { unsigned int min[4]; unsigned int max[4]; };
struct VPair8 { Vec33 v0; Vec33 v1; };
struct Sweep8 {
    int m00; int m04; int m08; int m0c; int m10; int m14; int m18; int m1c;
    int m20; int m24; int m28; int m2c; int m30; int m34; int m38; int m3c;
    Vec33 row40; Vec33 row50; Vec33 row60;
    int m70; int m74; int m78; int m7c; int m80; int m84; int m88; int m8c;
    int m90; int m94; int m98; int m9c;
    Obj8* objs; int mA4; int mA8; End8* listA; int mB0; int mB4; End8* listB; int mB8dummy;
    int mC0; End8* listC; int mC8; int mCC; int mD0; int mD4; Mgr8* mgr; int mDC;
    __forceinline void convert33(const unsigned int& addr, Bounds33& out) {
VPair8* a1=(VPair8*)addr; Vec33 zero; zero.setZero();
            Vec33 clamp; clamp.data=_mm_load_ps(DAT_011b3790);
            const Vec33& bias=*(const Vec33*)DAT_011b3770;
            Vec33 pw, qw;
            pw.setAdd4(a1->v0,row40); pw.mul4(row60); pw.min4(clamp); pw.max4(zero); pw.add4(bias);
                        QuantMin40 qa;
            qa.x = (unsigned short)(pw.data.m128_u32[0] >> 7);
            qa.y = (unsigned short)(pw.data.m128_u32[1] >> 7);
            qa.z = (unsigned short)(pw.data.m128_u32[2] >> 7);
            qw.setAdd4(a1->v1,row50); qw.mul4(row60); qw.min4(clamp); qw.max4(zero); qw.add4(bias);
            unsigned short u[4];
            u[0] = (unsigned short)(qw.data.m128_u32[0] >> 7);
            u[1] = (unsigned short)(qw.data.m128_u32[1] >> 7);
            u[2] = (unsigned short)(qw.data.m128_u32[2] >> 7);

            out.min[0] = (*(unsigned int*)&qa.x) & 0xfffe; out.min[1] = (*(unsigned int*)&qa.y) & 0xfffe; out.min[2] = (*(unsigned int*)&qa.z) & 0xfffe;
            out.max[0] = u[0] | 1;
            out.max[1] = u[1] | 1;
            out.max[2] = u[2] | 1;

    }
    __forceinline void axis34_0(Obj8* key, unsigned int r, Obj8& current, unsigned int lower, unsigned int upper, const unsigned int& a3, const unsigned int& a4) {
Obj8* ep=&current;
            // P1: listA, pos field f4 (offset 8), p lower, backward + equal tail
            {
                End8* list = listA;
                int obj = ep->f4;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot5() = (unsigned short)obj;
                            if ((overlaps & 0x80008000) == 0)
                                hkp3AxisSweep_beginOverlapCheckMarker(mgr, ep, r, other, a3);
                        } else {
                            other->slot4() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot4() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
                ep->f4 = (unsigned short)obj;
            }
            // P2: listA, pos field f5, p upper, forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listA;
                int obj = ep->f5;
                End8* i = list + obj;
                unsigned int p;
                p = upper;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
 Obj8* other; (void)other;
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot4()--;
                            if ((overlaps & 0x80008000) == 0)
                                hkp3AxisSweep_beginOverlapCheckMarker(mgr, ep, r, other, a3);
                        } else {
                            other->slot5()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        if (!nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot5()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            int a; unsigned int end; (void)a; end = (*(int*)&ep->f2) - (*(int*)&other->f0); a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            other->slot4()++;
                            if (((a | end) & 0x80008000) == 0)
                                RemoveOrAppendTagEntry(mgr, ep, r, other, a4);
                        } else {
                            other->slot5()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot5()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f5 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
            }
            // P1 forward: listA, pos field f4, p lower, forward + fwd-equal
            {
                End8* list = listA;
                int obj = ep->f4;
                End8* i = list + obj;
                unsigned int otherIdx = i[1].key;
                unsigned int p = lower;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        obj++;
                        if (otherIdx & 1) {
                            int a = (*(int*)&other->f2) - (*(int*)&ep->f0);
                            int end = (*(int*)&ep->f2) - (*(int*)&other->f0);
                            unsigned int overlaps = a | end;
                            other->slot5()--;
                            if ((overlaps & 0x80008000) == 0)
                                RemoveOrAppendTagEntry(mgr, ep, r, other, a4);
                        } else {
                            other->slot4()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot4()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f4 = (unsigned short)obj;
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
            }

    }
    __forceinline void axis34_1(Obj8* key, unsigned int r, Obj8& current, unsigned int lower, unsigned int upper, const unsigned int& a3, const unsigned int& a4) {
Obj8* ep=&current;
            // P4 backward: listB, pos field f0, p lower, backward + bwd-equal (4x u16 overlap test)
            {
                End8* list = listB;
                int obj = ep->f0;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            unsigned short a = (unsigned short)((unsigned short)((*(int*)&ep->f2) >> 16) - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot2() = (unsigned short)obj;
                            if ((a & 0x8000) == 0)
                                AppendPairToBuffer(ep, other, a3);
                        } else {
                            other->slot0() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot0() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
                ep->f0 = (unsigned short)obj;
            }
            // P5: listB, pos field f2, p upper, forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listB;
                int obj = ep->f2;
                End8* i = list + obj;
                unsigned int p = upper;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        Obj8* other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            unsigned short a = (unsigned short)((unsigned short)((*(int*)&ep->f2) >> 16) - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot0()--;
                            if ((a & 0x8000) == 0)
                                AppendPairToBuffer(ep, other, a3);
                        } else {
                            other->slot2()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        if (nextKey == 0) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot2()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        i[0].packed = i[-1].packed;
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i--;
                        obj--;
                        if ((n & 1) == 0) {
                            unsigned short a = (unsigned short)(ep->f3 - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot0()++;
                            if ((a & 0x8000) == 0)
                                AppendPairEntry(ep, other, a4);
                        } else {
                            other->slot2()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (r >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot2()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f2 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)r;
            }
            // P4 forward: listB, pos field f0, p lower, forward + fwd-equal
            {
                End8* list = listB;
                int obj = ep->f0;
                End8* i = list + obj;
                unsigned int p = lower;
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i += 1;
                        obj++;
                        if (otherIdx & 1) {
                            unsigned short a = (unsigned short)(ep->f3 - other->f1) | (unsigned short)(other->f3 - ep->f1) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f5 - ep->f4);
                            other->slot2()--;
                            if ((a & 0x8000) == 0)
                                AppendPairEntry(ep, other, a4);
                        } else {
                            other->slot0()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (r <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot0()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f0 = (unsigned short)obj;
                ((End8*)i)->id = (unsigned short)r;
                ((End8*)i)->key = (unsigned short)p;
            }

    }

    void hkp3AxisSweep_updateAabbs(int** a0, unsigned int a1, int a2, unsigned int volatile a3, unsigned int volatile a4);
};
#include <xmmintrin.h>
static unsigned int* Object_ProcessEntries_00d11000(unsigned int* dst, int n);
unsigned int* volatile g_zeroDestination;
volatile int g_zeroLength;
unsigned int* CallZeroBlocks();
#include <xmmintrin.h>
#include <xmmintrin.h>
#include <math.h>
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c7170;
struct SweepShiftPairs;
struct SweepShift
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void shiftObjects(const Vec4& distance, Vec4& applied, SweepShiftPairs& pairs);

    Vec4 m_10;
    Vec4 m_20;
    Vec4 m_30;
    Vec4 m_lowOffset;
    Vec4 m_lowRounded;
    Vec4 m_lowScale;
    Vec4 m_highOffset;
    Vec4 m_highRounded;
    Vec4 m_highScale;

    void hkp3AxisSweep_shiftBroadPhase(const Vec4& distance, Vec4& appliedOut, SweepShiftPairs& pairs);
};
void __cdecl ResizeAudioStream(void* allocator,void* array,int elementSize);
struct S4ef0Allocator {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
 virtual void ReturnMemory(void* p,int numBytes);
 template<class T> __forceinline T* _bufAlloc(int& reqNumInOut) { const int SIZE_ELEM=sizeof(T); int n=reqNumInOut*SIZE_ELEM; void* p=AllocateBufferWithSize(n); reqNumInOut=n/SIZE_ELEM; return static_cast<T*>(p); }
 template<class T> __forceinline void _bufFree(void* p,int numElem) { const int SIZE_ELEM=sizeof(T); ReturnMemory(p,numElem*SIZE_ELEM); }
};
struct S4ef0Router { int unk00,unk04,unk08; S4ef0Allocator* m_pTemp; S4ef0Allocator* m_pStreamAllocator;
 __forceinline S4ef0Allocator& temp() {return *m_pTemp;} __forceinline S4ef0Allocator& heap() {return *m_pStreamAllocator;}
 static __forceinline S4ef0Router& GetMonitorStream() { return *(S4ef0Router*)hkMemoryRouter_getInstance(); }
};
struct S4ef0TempAlloc { __forceinline S4ef0Allocator& get(void*) { return S4ef0Router::GetMonitorStream().temp(); } };
struct S4ef0HeapAlloc { __forceinline S4ef0Allocator& get(const void*) { return S4ef0Router::GetMonitorStream().heap(); } };
struct S4ef0TypeIsPod {};
struct S4ef0TypeIsClass {};
template<class T> __forceinline void S4ef0_construct(T* t,int n,S4ef0TypeIsPod) {}
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsClass) { for(int i=0;i<n;++i) { if(t+i) t[i]=tcopy; } }
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsPod) { for(int i=0;i<n;++i) { t[i]=tcopy; } }
template <class T>
static __forceinline void S4ef0ArrayBase_clear(hkArrayBase<T>& self);

template <class T>
static __forceinline void S4ef0ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, S4ef0Allocator& alloc);

template <class T>
static __forceinline void S4ef0ArrayBase_pushBackUnchecked(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void S4ef0ArrayBase__pushBack(hkArrayBase<T>& self, S4ef0Allocator& alloc,const T& t);

template <class T>
static __forceinline void S4ef0ArrayBase_clear(hkArrayBase<T>& self)
{ self.m_iElementCount=0; }

template <class T>
static __forceinline void S4ef0ArrayBase__clearAndDeallocate(hkArrayBase<T>& self, S4ef0Allocator& alloc)
{
  S4ef0ArrayBase_clear(self);
  if((self.m_iCapacityState&hkArrayBase<T>::DONT_DEALLOCATE_FLAG)==0) alloc._bufFree<T>(self.m_data,self.getCapacity());
  self.m_data=0; self.m_iCapacityState=hkArrayBase<T>::DONT_DEALLOCATE_FLAG;
 }

template <class T>
static __forceinline void S4ef0ArrayBase_pushBackUnchecked(hkArrayBase<T>& self, const T& t)
{ S4ef0_constructWithCopy(self.m_data+self.m_iElementCount,1,t,S4ef0TypeIsPod()); self.m_iElementCount++; }

template <class T>
static __forceinline void S4ef0ArrayBase__pushBack(hkArrayBase<T>& self, S4ef0Allocator& alloc,const T& t)
{
  if(self.m_iElementCount==self.getCapacity()) ResizeAudioStream(&alloc,(&self),sizeof(T));
  S4ef0_constructWithCopy(self.m_data+self.m_iElementCount,1,t,S4ef0TypeIsClass());
  self.m_iElementCount++;
 }
template<class T,class A> struct S4ef0Array : hkArrayBase<T> {
 __forceinline S4ef0Array(int n) : hkArrayBase<T>() {
  S4ef0Allocator& a=A().get(this);
  T* p=n ? a._bufAlloc<T>(n) : 0;
  int cap=n ? n : hkArrayBase<T>::DONT_DEALLOCATE_FLAG;
  this->setOwnedData(p,n,cap);
  S4ef0_construct(this->m_data,n,S4ef0TypeIsPod());
 }
 __forceinline ~S4ef0Array() { S4ef0ArrayBase__clearAndDeallocate(*this, A().get(this)); }
 __forceinline void AddBack(const T& t) { S4ef0ArrayBase__pushBack(*this, A().get(this),t); }
};
struct S4ef0Vector {
 __m128 m_vComponents;
 __forceinline S4ef0Vector() {}
 __forceinline __m128& getQuad() { return m_vComponents; }
 __forceinline const __m128& getQuad() const { return m_vComponents; }
 __forceinline void setZero4() { m_vComponents=_mm_setzero_ps(); }
 __forceinline void operator=(const S4ef0Vector& v) { m_vComponents=v.m_vComponents; }
 __forceinline void setAdd4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_add_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void add4(const S4ef0Vector& v) { m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents); }
 __forceinline void mul4(const S4ef0Vector& v) { m_vComponents=_mm_mul_ps(m_vComponents,v.m_vComponents); }
 __forceinline void setMin4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_min_ps(a.m_vComponents,b.m_vComponents); }
 __forceinline void setMax4(const S4ef0Vector& a,const S4ef0Vector& b) { m_vComponents=_mm_max_ps(a.m_vComponents,b.m_vComponents); }
};
struct S4ef0Aabb { S4ef0Vector m_kMinimumCorner,m_kMaximumCorner; };
__declspec(align(16)) struct S4ef0AabbInt { unsigned int m_kMinimumCorner[3]; unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; unsigned int m_kMaximumCorner[3]; unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
union S4ef0Union64 { __m128 quad; __int64 i64; unsigned __int64 u64; int i32[2]; unsigned int u32[2]; short i16[4]; unsigned short u16[4]; };
__forceinline void S4ef0_convertToUint16WithClip(const S4ef0Vector& in,const S4ef0Vector& offset,const S4ef0Vector& scale,const S4ef0Vector& min,const S4ef0Vector& max,S4ef0Union64& out) {
 S4ef0Vector x;
 x.setAdd4(in,offset);
 x.mul4(scale);
 x.setMin4(x,max);
 x.setMax4(x,min);
 S4ef0Vector magic;
 magic.getQuad()=*(const __m128*)DAT_011b3770;
 x.add4(magic);
 union { __m128 q; unsigned int i[4]; } u;
 u.q=x.getQuad();
 out.i16[0]=(short)(u.i[0]>>7);
 out.i16[1]=(short)(u.i[1]>>7);
 out.i16[2]=(short)(u.i[2]>>7);
 out.i16[3]=(short)(u.i[3]>>7);
}
__forceinline void S4ef0_memclear16(void* dest,int numBytes) {
 S4ef0Vector zero; zero.setZero4();
 S4ef0Vector* d=(S4ef0Vector*)dest;
 for(numBytes>>=4;numBytes>=0;numBytes--) { *(d++)=zero; }
}
__forceinline void S4ef0_staticFlipBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]^=mask; }
__forceinline void S4ef0_staticClearBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]&=~mask; }
struct S4ef0Pair { unsigned int m_kPointA,m_kPointB; };
struct S4ef0Node {
 unsigned short m_usValue00,m_usValue02,m_usValue04,m_usValue06,m_usValue08,m_usValue0A; unsigned int m_handle;
 __forceinline unsigned int yzDisjoint(const S4ef0Node& other) const {
  unsigned int minA=*(const unsigned int*)&m_usValue00; unsigned int minB=*(const unsigned int*)&other.m_usValue00;
  unsigned int maxA=*(const unsigned int*)&m_usValue04; unsigned int maxB=*(const unsigned int*)&other.m_usValue04;
  maxA-=minB; maxB-=minA; maxA|=maxB; maxA&=0x80008000; return maxA;
 }
 __forceinline int isMarker() const { return m_handle&1; }
};
struct S4ef0Marker { unsigned short m_usIndex,m_uiFilterValue; hkArrayBase<unsigned short> m_kMarkerIndices; };
struct S4ef0Axis : hkArrayBase<Entry> { const Entry* LowerBoundEntry(const Entry* first,const Entry* last,unsigned short key) const; };
__declspec(noinline) const Entry* S4ef0Axis::LowerBoundEntry(const Entry* start,const Entry* end,unsigned short value) const {
 while(end-start>16) {
  const Entry* mid=start+((end-start)>>1);
  if(mid->key<value) start=mid; else end=mid;
 }
 while(start->key<value) start++;
 return start;
}
struct S4ef0Handle;
struct S4ef0Collector { virtual void v0(); virtual float ReleaseCollector(unsigned int h,int i); };
typedef S4ef0Array<S4ef0Pair,S4ef0HeapAlloc> S4ef0Results;
typedef hkArrayBase<const S4ef0Node*> S4ef0NodeArr;
struct S4ef0Owner {
 __m128 unk00,unk10,unk20,unk30;
 S4ef0Vector m_kVectorAt40,m_kVectorAt50,m_vScale;
 __m128 unk70,unk80,unk90;
 hkArrayBase<S4ef0Node> m_kNodeCollection;
 S4ef0Axis m_kAxisEndPoints[3];
 int m_iMarkerCount,m_iMarkerCapacity; S4ef0Marker* m_pOverlappingMarkerInfo;
 __forceinline int getNumMarkers() const { return m_iMarkerCount; }
 __forceinline void _convertAabbToInt(const S4ef0Aabb& aabb,S4ef0AabbInt& aabbOut) const { _convertAabbToIntS(aabb,m_kVectorAt40,m_kVectorAt50,m_vScale,aabbOut); }
 static __forceinline void _convertAabbToIntS(const S4ef0Aabb& aabb,const S4ef0Vector& offsetLow,const S4ef0Vector& offsetHigh,const S4ef0Vector& scale,S4ef0AabbInt& aabbOut);
 __forceinline void querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 __forceinline void _querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 void hkp3AxisSweep_querySingleAabb(const S4ef0Aabb& aabb,S4ef0Results& pairsOut) const;
};
__forceinline void S4ef0Owner::_convertAabbToIntS(const S4ef0Aabb& aabb,const S4ef0Vector& offsetLow,const S4ef0Vector& offsetHigh,const S4ef0Vector& scale,S4ef0AabbInt& aabbOut) {
 S4ef0Vector zero; zero.setZero4();
 S4ef0Vector maxVal; maxVal.getQuad()=*(const __m128*)DAT_011b3790;
 S4ef0Union64 mi;
 S4ef0Union64 ma;
 S4ef0_convertToUint16WithClip(aabb.m_kMinimumCorner,offsetLow,scale,zero,maxVal,mi);
 S4ef0_convertToUint16WithClip(aabb.m_kMaximumCorner,offsetHigh,scale,zero,maxVal,ma);
 aabbOut.m_kMinimumCorner[0]=mi.u16[0]&0xfffe;
 aabbOut.m_kMinimumCorner[1]=mi.u16[1]&0xfffe;
 aabbOut.m_kMinimumCorner[2]=mi.u16[2]&0xfffe;
 aabbOut.m_kMaximumCorner[0]=ma.u16[0]|1;
 aabbOut.m_kMaximumCorner[1]=ma.u16[1]|1;
 aabbOut.m_kMaximumCorner[2]=ma.u16[2]|1;
}
__forceinline void S4ef0Owner::querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const {
 S4ef0Pair pair; pair.m_kPointA=(unsigned int)object;
 const S4ef0Node* nodes=&m_kNodeCollection[0];
 const unsigned int* bitFieldEnd=bitField+(m_kNodeCollection.GetLogicalSize()>>5)+1;
 for(;bitField<bitFieldEnd;nodes+=32,bitField++) {
  unsigned int bits=*bitField;
  if(!bits) continue;
  const S4ef0Node* n=nodes;
  do {
   if(bits&0xf) {
    if(bits&1) {
     if(!n[0].yzDisjoint(refNode) && !n[0].isMarker()) {
      if(type==0) { pair.m_kPointB=n[0].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[0]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[0].m_handle,0); }
     }
    }
    if(bits&2) {
     if(!n[1].yzDisjoint(refNode) && !n[1].isMarker()) {
      if(type==0) { pair.m_kPointB=n[1].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[1]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[1].m_handle,0); }
     }
    }
    if(bits&4) {
     if(!n[2].yzDisjoint(refNode) && !n[2].isMarker()) {
      if(type==0) { pair.m_kPointB=n[2].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[2]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[2].m_handle,0); }
     }
    }
    if(bits&8) {
     if(!n[3].yzDisjoint(refNode) && !n[3].isMarker()) {
      if(type==0) { pair.m_kPointB=n[3].m_handle; pairsOut->AddBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[3]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[3].m_handle,0); }
     }
    }
   }
   n+=4; bits>>=4;
  } while(bits);
 }
}
__forceinline void S4ef0Owner::_querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const {
 S4ef0Handle* object=0;
 int size=m_kNodeCollection.GetLogicalSize();
 S4ef0Array<unsigned int,S4ef0TempAlloc> bitFieldArr((size>>5)+8);
 unsigned int* bitField=bitFieldArr.begin();
 S4ef0_memclear16(bitField,size>>3);
 S4ef0AabbInt aabbInt;
 _convertAabbToInt(aabb,aabbInt);
 const Entry* ep=&m_kAxisEndPoints[0][1];
 if(getNumMarkers()) {
  int value=aabbInt.m_kMinimumCorner[0];
  int pos=value>>(16-m_iMarkerCapacity);
  if(pos>0) {
   S4ef0Marker* marker=&m_pOverlappingMarkerInfo[pos-1];
   S4ef0_staticFlipBit(bitField,marker->m_usIndex);
   const unsigned short* objects=marker->m_kMarkerIndices.begin();
   for(int i=marker->m_kMarkerIndices.GetLogicalSize()-1;i>=0;i--) { S4ef0_staticFlipBit(bitField,*objects); objects++; }
   const S4ef0Node& node=m_kNodeCollection[marker->m_usIndex];
   ep=&m_kAxisEndPoints[0][node.m_usValue08+1];
   const Entry* end=&m_kAxisEndPoints[0][node.m_usValue0A];
   for(;ep<end;ep++) { if(!(ep->key&1)) S4ef0_staticClearBit(bitField,ep->value); }
   ep=&m_kAxisEndPoints[0][node.m_usValue08+1];
  }
 }
 for(;ep->key<aabbInt.m_kMinimumCorner[0];ep++) { S4ef0_staticFlipBit(bitField,ep->value); }
 for(;ep->key<aabbInt.m_kMaximumCorner[0];ep++) { if(!(ep->key&1)) S4ef0_staticFlipBit(bitField,ep->value); }
 S4ef0Node refNode;
 {
  const S4ef0Axis& axis=m_kAxisEndPoints[1];
  const Entry* start=&axis[0];
  refNode.m_usValue00=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMinimumCorner[1])-start);
  refNode.m_usValue04=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMaximumCorner[1])-(start+1));
 }
 {
  const S4ef0Axis& axis=m_kAxisEndPoints[2];
  const Entry* start=&axis[0];
  refNode.m_usValue02=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMinimumCorner[2])-start);
  refNode.m_usValue06=(unsigned short)(axis.LowerBoundEntry(start+1,axis.end()-2,(unsigned short)aabbInt.m_kMaximumCorner[2])-(start+1));
 }
 querySingleAabbSub(object,bitField,refNode,type,pairsOut,nodesOut,collector);
}
inline void* __cdecl operator new(unsigned int, void* storage) { return storage; }
extern float DAT_0104da48;
extern float DAT_0104e148;
static const __m128 batchSweepBias={65536.0f,65536.0f,65536.0f,65536.0f};
extern float DAT_011b3790[4];
struct BatchSweepAllocator {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void* AllocateBufferWithSize(int& bytes) throw();
    virtual void ReturnMemory(void* memory, int bytes) throw();
    template<class T> __forceinline T* _bufAlloc(int& count) throw() {
        int bytes=count*(int)sizeof(T);
        void* memory=AllocateBufferWithSize(bytes);
        count=bytes/(int)sizeof(T);
        return (T*)memory;
    }
};
template<class T> __forceinline T* allocateSweep(BatchSweepAllocator& allocator, int count, int& capacity) {
    T* result = count ? allocator._bufAlloc<T>(count) : 0;
    capacity = count ? count : (int)0x80000000;
    return result;
}
struct SweepVector {
    __m128 v;
    __forceinline void operator=(const SweepVector& value){v=value.v;}
    __forceinline void setMin(const SweepVector& a,const SweepVector& b) {v=_mm_min_ps(a.v,b.v);}
    __forceinline void setMax(const SweepVector& a,const SweepVector& b) {v=_mm_max_ps(a.v,b.v);}
    __forceinline void setAdd(const SweepVector& a,const SweepVector& b) {v=_mm_add_ps(a.v,b.v);}
    __forceinline void mul(const SweepVector& a) {v=_mm_mul_ps(v,a.v);}
    __forceinline void add(const SweepVector& a) {v=_mm_add_ps(v,a.v);}
};
__forceinline void clearSweepQuads(void* storage,int chunks) {
 SweepVector zero;zero.v=_mm_setzero_ps();
 SweepVector* cursor=(SweepVector*)storage;
 while(--chunks>=0) *cursor++=zero;
}
union ShortResult {__m128 vector;unsigned short values[4];short signedValues[4];unsigned int pairs[2];__int64 wide;};
__forceinline void convertSweepBound(const SweepVector& input,const SweepVector& offset,const SweepVector& scale,const SweepVector& min,const SweepVector& max,ShortResult& out) {
    SweepVector value;
    value.setAdd(input,offset);value.mul(scale);value.setMin(value,max);value.setMax(value,min);
    SweepVector bias;bias.v=batchSweepBias;value.add(bias);
    union {__m128 v;unsigned int words[4];} bits;
    bits.v=value.v;
    out.values[0]=(unsigned short)(bits.words[0]>>7);
    out.values[1]=(unsigned short)(bits.words[1]>>7);
    out.values[2]=(unsigned short)(bits.words[2]>>7);
}
struct BatchAabb { SweepVector low,high;
 __forceinline void include(const BatchAabb& other) {low.setMin(low,other.low);high.setMax(high,other.high);}
};
struct __declspec(align(16)) QuantBatchAabb {
    unsigned int low[3];
    unsigned char expandLowX,expandLowY,expandLowZ,expandShift;
    unsigned int high[3];
    unsigned char expandHighX,expandHighY,expandHighZ,shapeByte;
};
struct __declspec(align(16)) SweepLowShorts { unsigned short x,y,z,w; };
__forceinline void quantizeSweepAabb(const SweepVector& offsetLow,const BatchAabb& box,const SweepVector& offsetHigh,const SweepVector& scale,QuantBatchAabb& out) {
    SweepVector zero,upper;zero.v=_mm_setzero_ps();upper.v=_mm_load_ps(DAT_011b3790);
    SweepVector magic;magic.v=batchSweepBias;
    SweepVector lowValue,highValue;
    lowValue.setAdd(box.low,offsetLow);lowValue.mul(scale);lowValue.setMin(lowValue,upper);lowValue.setMax(lowValue,zero);lowValue.add(magic);
    ShortResult lower;
    lower.values[0]=(unsigned short)(lowValue.v.m128_u32[0]>>7);
    lower.values[1]=(unsigned short)(lowValue.v.m128_u32[1]>>7);
    lower.values[2]=(unsigned short)(lowValue.v.m128_u32[2]>>7);
    highValue.setAdd(box.high,offsetHigh);highValue.mul(scale);highValue.setMin(highValue,upper);highValue.setMax(highValue,zero);highValue.add(magic);
    ShortResult upperResult;
    upperResult.values[0]=(unsigned short)(highValue.v.m128_u32[0]>>7);
    upperResult.values[1]=(unsigned short)(highValue.v.m128_u32[1]>>7);
    upperResult.values[2]=(unsigned short)(highValue.v.m128_u32[2]>>7);
    out.low[0]=lower.values[0]&0xfffe;
    out.low[1]=lower.values[1]&0xfffe;
    out.low[2]=lower.values[2]&0xfffe;
    out.high[0]=upperResult.values[0]|1;
    out.high[1]=upperResult.values[1]|1;
    out.high[2]=upperResult.values[2]|1;
}
__forceinline void quantizeCombinedSweepAabb(const BatchAabb& box,const SweepVector& offsetLow,const SweepVector& offsetHigh,const SweepVector& scale,QuantBatchAabb& out) {
    SweepVector zero,upper;zero.v=_mm_setzero_ps();upper.v=_mm_load_ps(DAT_011b3790);
    SweepVector magic;magic.v=batchSweepBias;
    SweepVector lowValue,highValue;
    lowValue.setAdd(box.low,offsetLow);lowValue.mul(scale);lowValue.setMin(lowValue,upper);lowValue.setMax(lowValue,zero);lowValue.add(magic);
    ShortResult lower;
    lower.values[0]=(unsigned short)(lowValue.v.m128_u32[0]>>7);
    lower.values[1]=(unsigned short)(lowValue.v.m128_u32[1]>>7);
    lower.values[2]=(unsigned short)(lowValue.v.m128_u32[2]>>7);
    highValue.setAdd(box.high,offsetHigh);highValue.mul(scale);highValue.setMin(highValue,upper);highValue.setMax(highValue,zero);highValue.add(magic);
    ShortResult upperResult;
    upperResult.values[0]=(unsigned short)(highValue.v.m128_u32[0]>>7);
    upperResult.values[1]=(unsigned short)(highValue.v.m128_u32[1]>>7);
    upperResult.values[2]=(unsigned short)(highValue.v.m128_u32[2]>>7);
    out.low[0]=lower.values[0]&0xfffe;
    out.low[1]=lower.values[1]&0xfffe;
    out.low[2]=lower.values[2]&0xfffe;
    out.high[0]=upperResult.values[0]|1;
    out.high[1]=upperResult.values[1]|1;
    out.high[2]=upperResult.values[2]|1;
}
void __fastcall ToggleBit(int index,void* storage) {
    int wordIndex=index>>5;
    ((unsigned int*)storage)[wordIndex] ^= 1 << (index&31);
}
// src: HAVOK_LIB 0x00d10af0
void __fastcall staticClearBit(int index,unsigned int* storage) {
    int wordIndex=index>>5;
    storage[wordIndex] &= ~(1 << (index&31));
}
struct Holder { void* p; int a; int b; BatchSweepAllocator* allocObj; void* f10; };
struct BatchSweepKey { unsigned short val,idx; };
struct SweepBatchNode;
template<class T> __forceinline void destroySweepRange(T* p,int n) {for(int k=0;k<n;++k)p[k].~T();}
template<class T> __forceinline void initializeSweepRange(T* p,int n) {for(int k=0;k<n;++k)::new(p+k) T;}
template<class T> struct SweepStorageBase {
 T* data;int size;int capacity;
 __forceinline SweepStorageBase():data(0),size(0),capacity(0x80000000){}
 __forceinline void own(T* pointer,int count,int flags){this->data=pointer;this->size=count;this->capacity=flags;}
 __forceinline T& operator[](int i){return data[i];}
 __forceinline void setSizeUnchecked(int n){destroySweepRange(data+n,size-n);initializeSweepRange(data+size,n-size);size=n;}
 __forceinline T* begin(){return data;}
};
struct SweepStackPolicy {__forceinline BatchSweepAllocator& get(const void*){Holder* h=(Holder*)hkMemoryRouter_getInstance();return *h->allocObj;}};
template<class T> struct SweepBuffer:SweepStorageBase<T> {
    __forceinline T& operator[](int i){return data[i];}
    __forceinline SweepBuffer(int count) :SweepStorageBase<T>() {
        BatchSweepAllocator& allocator=SweepStackPolicy().get(this);
        T* pointer=count ? allocator._bufAlloc<T>(count) : 0;
        int flags=count ? count : (int)0x80000000;
        own(pointer,count,flags);initializeSweepRange(data,count);
    }
    __forceinline SweepBuffer(int count,SweepBatchNode** nodes,void*& baseOut) :SweepStorageBase<T>() {
        BatchSweepAllocator& allocator=SweepStackPolicy().get(this);
        T* pointer;
        if(count){int bytes=count*(int)sizeof(T);pointer=(T*)allocator.AllocateBufferWithSize(bytes);count=bytes/(int)sizeof(T);}else {pointer=0;}
        int flags;if(count){flags=count;baseOut=*nodes;}else{flags=0x80000000;baseOut=*nodes;}
        own(pointer,count,flags);initializeSweepRange(data,count);
    }
};
struct SweepObjectHandle {unsigned int id;};
struct SweepBatchNode {
 unsigned short minY,minZ,maxY,maxZ,minX,maxX;
 SweepObjectHandle* handle;
 __forceinline unsigned int disjointYZ(const SweepBatchNode& other) const {
  unsigned int first=(*(const unsigned int*)&maxY)-(*(const unsigned int*)&other.minY);
  unsigned int second=(*(const unsigned int*)&other.maxY)-(*(const unsigned int*)&minY);
  return (first|second)&0x80008000;
 }
 __forceinline int isMarker() const {return (unsigned int)handle&1;}
};

struct BatchNodeArray:SweepStorageBase<SweepBatchNode> {};
struct BatchMarker { unsigned short node,value; unsigned short* data; int size,capacity; };
struct SortArr15 {
    Endpoint* data; int size; int cap;
    __declspec(noinline) void* LowerBoundEntry(void* begin, void* end, int thresh);
    int InsertEndpoints(void* base, int idx, void* ptr, int savedN);
    int MergeSortedEndpoints(void* base, int out, void* ptr, int savedN);
    int MergeEndpointRangesBackward(void* base, int out, void* ptr, int savedN);
    int ProcessEntries_00d19ef0(void* base, int out, void* ptr, int savedN);
};
__declspec(noinline) void* SortArr15::LowerBoundEntry(void* begin,void* end,int thresh) {
 Endpoint* first=(Endpoint*)begin;Endpoint* last=(Endpoint*)end;
 unsigned short key=(unsigned short)thresh;
 while(last-first>16){Endpoint* middle=first+((last-first)>>1);if(middle->value<key)first=middle;else last=middle;}
 while(first->value<key)++first;
 return first;
}
union PackedBatchBounds {
    unsigned short values[4];
    struct { unsigned int low,high; } packed;
};
struct In1 { SweepObjectHandle** f0; int count; };
struct In2 { BatchAabb* base; int gate; };
struct Sweep15 : public BroadPhaseBase {
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    SweepVector m_kVectorAt40;
    SweepVector m_kVectorAt50;
    SweepVector m_vScale;
    int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C;
    int unk90; int unk94; int unk98; int unk9C;
    BatchNodeArray arrA0;
    SortArr15 axes[3];
    int m_iMarkerCount;
    int m_markerShift;
    BatchMarker* m_pOverlappingMarkerInfo;

    __forceinline void collectSweepCandidates(const BatchAabb& spl,hkArrayBase<SweepBatchNode*>& local);
    void hkp3AxisSweep_addObjectBatch(In1* p1, In2* p2, int p3);
    int BuildBroadPhasePairs(void* a, int b, void* c, int d, int e, int f);
};
void __cdecl hkArrayUtil__reserve(void* a, void* b, int c, int d);
struct EndpointOrder { };
void __cdecl hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(void* a, int b, int c, EndpointOrder d);
__forceinline void sortSweepEndpoints(void* p,int count,EndpointOrder order) {
 if(count>1) hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(p,0,count-1,order);
}
void __cdecl hkRadixSort_sort16(void* a, int b, void* c);
void __cdecl CollectNodePairs(void* a, void* b, int c, int d);
__forceinline void Sweep15::collectSweepCandidates(const BatchAabb& spl,hkArrayBase<SweepBatchNode*>& local)
{
        int capA4=arrA0.size;
        int sz = (capA4 >> 5) + 8;
        SweepBuffer<int> bitmap(sz);
        
        clearSweepQuads(bitmap.data,(capA4>>7)+1);
        QuantBatchAabb quantized;
        quantizeCombinedSweepAabb(spl,m_kVectorAt40,m_kVectorAt50,m_vScale,quantized);

        Endpoint* cntBase = axes[0].data;
        int listCount = m_iMarkerCount;
        int listShift = m_markerShift;
        BatchMarker* listData = m_pOverlappingMarkerInfo;
        int* bits = (int*)bitmap.data;
        unsigned short* scan = (unsigned short*)(cntBase + 1);
        if (listCount != 0) {
            int cnt = (int)quantized.low[0] >> (16 - listShift);
            if (cnt > 0) {
                BatchMarker* entry = listData + cnt - 1;
                int w0 = entry->node;
                ToggleBit(w0,bits);
                int rem = entry->size - 1;
                unsigned short* wp = entry->data;
                while (rem >= 0) {
                    ToggleBit(*wp++,bits);
                    rem--;
                }
                SweepBatchNode* rec = arrA0.data + entry->node;
                Endpoint* rangeBase=axes[0].data;Endpoint* s=rangeBase+rec->minX+1;Endpoint* end=rangeBase+rec->maxX;
                while(s<end){
                    if((s->value&1)==0){int w=s->handle;staticClearBit(w,(unsigned int*)bits);}
                    ++s;
                }
                scan=(unsigned short*)(axes[0].data+rec->minX+1);
            }
        }
        while (*scan < (unsigned int)quantized.low[0]) {
            int w = scan[1];
            ToggleBit(w,bits);
            scan += 2;
        }
        unsigned short scanValue=*scan;
        while(scanValue < (unsigned int)quantized.high[0]) {
            if(!(scanValue&1)) {
                int w=scan[1];
                ToggleBit(w,bits);
            }
            scan+=2;
            scanValue=*scan;
        }
        SweepBatchNode sortBounds;
        {
            SortArr15* sa = &axes[1];
            char* d = (char*)sa->data;
            char* end = d + sa->size * 4 - 8;
            char* r = (char*)sa->LowerBoundEntry(d + 4, end, quantized.low[1]);
            sortBounds.minY = (unsigned short)((r - d) >> 2);
            r = (char*)sa->LowerBoundEntry(d + 4, end, quantized.high[1]);
            sortBounds.maxY = (unsigned short)(((r - d) - 4) >> 2);
        }
        {
            SortArr15* sa = &axes[2];
            char* d = (char*)sa->data;
            char* end = d + sa->size * 4 - 8;
            char* r = (char*)sa->LowerBoundEntry(d + 4, end, quantized.low[2]);
            sortBounds.minZ = (unsigned short)((r - d) >> 2);
            r = (char*)sa->LowerBoundEntry(d + 4, end, quantized.high[2]);
            sortBounds.maxZ = (unsigned short)(((r - d) - 4) >> 2);
        }
        {
            SweepBatchNode* group = arrA0.data;
            int* bp=bits;
            int* bitsEnd = bits + (arrA0.size >> 5) + 1;
            for (; bp < bitsEnd; bp++) {
                unsigned int word = *bp;
                SweepBatchNode* rec = group;
                while (word) {
                    if(word & 15) {
                        if(word & 1) {
                            if(!rec[0].disjointYZ(sortBounds) && !rec[0].isMarker())
                                ((SweepBatchNode**)local.m_data)[local.m_iElementCount++]=rec+0;
                        }
                        if(word & 2) {
                            if(!rec[1].disjointYZ(sortBounds) && !rec[1].isMarker())
                                ((SweepBatchNode**)local.m_data)[local.m_iElementCount++]=rec+1;
                        }
                        if(word & 4) {
                            if(!rec[2].disjointYZ(sortBounds) && !rec[2].isMarker())
                                ((SweepBatchNode**)local.m_data)[local.m_iElementCount++]=rec+2;
                        }
                        if(word & 8) {
                            if(!rec[3].disjointYZ(sortBounds) && !rec[3].isMarker())
                                ((SweepBatchNode**)local.m_data)[local.m_iElementCount++]=rec+3;
                        }
                    }
                    word >>= 4;
                    rec += 4;
                }
                group += 32;
            }
        }
        {
            Holder* h = (Holder*)hkMemoryRouter_getInstance();
            BatchSweepAllocator* al = h->allocObj;
            if ((bitmap.capacity & 0x80000000) == 0) al->ReturnMemory( bitmap.data, (bitmap.capacity & 0x3fffffff) * 4);
        }
    
}

extern "C" const float DAT_010cd5b0;
extern "C" const float DAT_010cd5b4;

struct OffsetScaleVector : SweepVec4 {
    void operator=(const OffsetScaleVector& v) { m_vComponents = v.m_vComponents; }
    float& operator()(int i) { return ((float*)&m_vComponents)[i]; }
    void setSub4(const OffsetScaleVector& a, const OffsetScaleVector& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    void setMul4(float r, const OffsetScaleVector& a) { __m128 t = _mm_load_ss(&r); m_vComponents = _mm_mul_ps(a.m_vComponents, _mm_shuffle_ps(t, t, 0)); }
    void setAddMul4(const OffsetScaleVector& a, const OffsetScaleVector& b, float r) { __m128 t = _mm_load_ss(&r); m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), b.m_vComponents), a.m_vComponents); }
    void zeroElement3() { __m128 z = _mm_setzero_ps(); m_vComponents = _mm_shuffle_ps(m_vComponents, _mm_unpackhi_ps(m_vComponents, z), 0xc4); }
};

struct Sweep3Axis {
    OffsetScaleVector unk00;
    OffsetScaleVector unk10;
    OffsetScaleVector m_aabbMin;
    OffsetScaleVector m_aabbMax;
    OffsetScaleVector m_kVectorAt40;
    OffsetScaleVector m_kVectorAt50;
    OffsetScaleVector m_vScale;
    OffsetScaleVector m_kVectorAt70;
    OffsetScaleVector m_kVectorAt80;
    OffsetScaleVector m_kVectorAt90;

    void hkp3AxisSweep_set32BitOffsetAndScale(const OffsetScaleVector& offsetLow, const OffsetScaleVector& offsetHigh, const OffsetScaleVector& scale);
};

// @fnv 0x00d11020
// src: XBOX_PDB 0x00d11020
void Sweep3Axis::hkp3AxisSweep_set32BitOffsetAndScale(const OffsetScaleVector& offsetLow, const OffsetScaleVector& offsetHigh, const OffsetScaleVector& scale)
{
    m_kVectorAt70 = offsetLow;
    m_kVectorAt80 = offsetHigh;
    m_kVectorAt90 = scale;
    m_kVectorAt40 = offsetLow;

    OffsetScaleVector span;
    span.setSub4(m_aabbMax, m_aabbMin);
    OffsetScaleVector spanInv;
    spanInv.set(1.0f / span(0), 1.0f / span(1), 1.0f / span(2), 0.0f);

    m_kVectorAt50.setAddMul4(m_kVectorAt40, span, DAT_010cd5b4);
    m_vScale.setMul4(DAT_010cd5b0, spanInv);

    m_vScale.zeroElement3();
    m_kVectorAt40.zeroElement3();
    m_kVectorAt50.zeroElement3();
}
