#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../include/Vec4.h"

// Preserve the original inline SIMD operations with the shared vector layout.
inline Vec4::Vec4(const __m128& q) { getQuad() = q; }
inline __m128& Vec4::getQuad() { return *reinterpret_cast<__m128*>(this); }
inline const __m128& Vec4::getQuad() const { return *reinterpret_cast<const __m128*>(this); }
inline void Vec4::setZero4() { getQuad() = _mm_setzero_ps(); }
inline void Vec4::setAdd4(const Vec4& a, const Vec4& b) { getQuad() = _mm_add_ps(a.getQuad(), b.getQuad()); }
inline void Vec4::add4(const Vec4& v) { getQuad() = _mm_add_ps(getQuad(), v.getQuad()); }
inline void Vec4::mul4(const Vec4& v) { getQuad() = _mm_mul_ps(getQuad(), v.getQuad()); }
inline void Vec4::setMin(const Vec4& a, const Vec4& b) { getQuad() = _mm_min_ps(a.getQuad(), b.getQuad()); }
inline void Vec4::setMax(const Vec4& a, const Vec4& b) { getQuad() = _mm_max_ps(a.getQuad(), b.getQuad()); }

// Keep the original inline allocator access while using the shared router layout.

// Array operations used by this unit retain the original inline allocator calls.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap());
}
__forceinline hkMemoryAllocator& hkContainerTempAllocator::get(void*)
{
    return *reinterpret_cast<hkMemoryAllocator*>((&hkMemoryRouter::getInstance())->m_temp);
}
template <typename T>
__forceinline void hkArrayBase<T>::clear() { m_iElementCount = 0; }
template <typename T>
__forceinline void hkArrayBase<T>::pushBackUnchecked(const T& t)
{
    m_data[m_iElementCount] = t;
    m_iElementCount++;
}

// The shared router currently exposes the temporary allocator slot as unk0c.
template <class T>
inline T& GetTemporaryAllocator(hkMemoryRouter& router)
{
    return *reinterpret_cast<T*>(router.m_temp);
}

// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
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
struct SmallArray : hkArrayBase<unsigned short> {

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
struct BroadPhasePairArray : hkArray<S_00d138a0_Pair> {
    S_00d138a0_Pair& _expandOne(Allocator& alloc) {
        if (m_iElementCount == (int)(m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(&alloc, this, sizeof(S_00d138a0_Pair));
            construct(m_data + m_iElementCount, 1);
        }
        return m_data[m_iElementCount++];
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
// AppendN copies two sweep-node handles at +0x0c; this has none of the reflection/serialization Pair methods.
struct BroadPhaseOverlap {
    int m_00; int m_04;
};
struct PairVec {
    BroadPhaseOverlap* m_00; int m_04; int m_08;
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
    AllocObj* ao = reinterpret_cast<AllocObj*>(h->m_heap);
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
        BroadPhaseOverlap* p = &out->m_00[out->m_04];
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

// @fnv 0x00d10b30
// src: GUESS 0x00d10b30 (confidence: low)
void __stdcall Hkp3axissweepGsEhscNogsNoehsc_ProcessEntries_00d10b30(S00d10b30_Node* nodes, int n, const S00d10b30_Bnd* bnd)
{
    S00d10b30_Node r1, r2;
    r1.hi.m64_i16[1] = r1.hi.m64_i16[0] = bnd->hi0 - 1;
    r1.lo.m64_i16[2] = r1.lo.m64_i16[0] = bnd->lo0 - 1;
    r1.lo.m64_i16[3] = r1.lo.m64_i16[1] = bnd->lo1 - 1;
    r2.hi.m64_i16[1] = r2.hi.m64_i16[0] = bnd->hi1 - 2;
    r2.lo.m64_i16[2] = r2.lo.m64_i16[0] = bnd->lo2 - 2;
    r2.lo.m64_i16[3] = r2.lo.m64_i16[1] = bnd->lo3 - 2;
    __m64 mask = _mm_set_pi32(0, -1);

    S00d10b30_Node* end = nodes + n;
    for (S00d10b30_Node* p = nodes; p < end; ++p) {
        __m64 lo = p->lo;
        __m64 hi = p->hi;
        p->lo = _mm_sub_pi16(lo, _mm_add_pi16(_mm_cmpgt_pi16(lo, r1.lo), _mm_cmpgt_pi16(lo, r2.lo)));
        p->hi = _mm_sub_pi16(hi, _mm_and_si64(mask, _mm_add_pi16(_mm_cmpgt_pi16(hi, r1.hi), _mm_cmpgt_pi16(hi, r2.hi))));
    }
    _mm_empty();
}

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

// @fnv 0x00d10c40
// src: GUESS 0x00d10c40 (confidence: low)
void __stdcall Object_ProcessEntries_00d10c40(FourIntegerBlock* nodes, int n, int delta, const int* bound)
{
    BpRefBounds ref;
    ref.hi0 = (unsigned short)(bound[0] - 1);
    ref.hi1 = ref.hi0;
    ref.lo0 = (unsigned short)(bound[1] - 1);
    ref.lo2 = ref.lo0;
    ref.lo1 = (unsigned short)(bound[2] - 1);
    ref.lo3 = ref.lo1;

    unsigned int d = (unsigned int)delta * 0x10001u;
    __m64 dAll = _mm_set_pi32(d, d);
    __m64 dHi = _mm_set_pi32(0, d);
    __m64 refLo = *(__m64*)&ref.lo0;
    __m64 refHi = *(__m64*)&ref.hi0;

    FourIntegerBlock* end = nodes + n;
    for (FourIntegerBlock* p = nodes; p < end; ++p) {
        __m64 lo = *(__m64*)&p->unk00;
        __m64 hi = *(__m64*)&p->unk08;
        *(__m64*)&p->unk00 = _mm_add_pi16(lo, _mm_and_si64(_mm_cmpgt_pi16(lo, refLo), dAll));
        *(__m64*)&p->unk08 = _mm_add_pi16(hi, _mm_and_si64(_mm_cmpgt_pi16(hi, refHi), dHi));
    }
    _mm_empty();
}

struct BpBoundNode { __m64 lo; __m64 hi; };
struct BpBoundWords { unsigned short lo0, lo1, lo2, lo3, hi0, hi1; };
struct __declspec(align(16)) ReferenceBounds {
    unsigned short min0, min1, min2, min3;
    unsigned short max0, max1;
    unsigned int maxSentinels;
};
// @fnv 0x00d10d10
// src: XBOX_PDB 0x00d10d10
void __stdcall hkp3AxisSweep_updateNodesAfterDelete(BpBoundNode* nodes, int n, const BpBoundWords* bnd)
{
    ReferenceBounds first, second;
    __m64 mask;
    unsigned int hi0 = bnd->hi0;
    first.max0 = hi0; first.max1 = hi0;
    unsigned int lo0 = bnd->lo0;
    first.min0 = lo0; first.min2 = lo0;
    unsigned int lo1 = bnd->lo1;
    first.min1 = lo1; first.min3 = lo1;
    unsigned int hi1 = bnd->hi1;
    second.max0 = hi1; second.max1 = hi1;
    unsigned int lo2 = bnd->lo2;
    second.min0 = lo2; second.min2 = lo2;
    unsigned int lo3 = bnd->lo3;
    second.min1 = lo3; second.min3 = lo3;
    BpBoundNode* end = nodes + n;
    first.maxSentinels = 0xffffffff;
    second.maxSentinels = 0xffffffff;
    mask = _mm_set_pi32(0, -1);
    __m64 a = *(__m64*)&first.min0;
    __m64 b = *(__m64*)&first.max0;
    __m64 d = *(__m64*)&second.max0;
    for (BpBoundNode* p = nodes; p != end; ++p) {
        __m64 lo = p->lo;
        __m64 hi = p->hi;
        __m64 t0 = _mm_cmpgt_pi16(lo, a);
        __m64 t1 = _mm_cmpgt_pi16(lo, *(__m64*)&second.min0);
        t0 = _mm_add_pi16(t0, t1);
        p->lo = _mm_add_pi16(lo, t0);
        __m64 u0 = _mm_cmpgt_pi16(hi, b);
        __m64 u1 = _mm_cmpgt_pi16(hi, d);
        u0 = _mm_and_si64(_mm_add_pi16(u0, u1), mask);
        p->hi = _mm_add_pi16(hi, u0);
    }
    _mm_empty();
}

int fnv_FloatToInt(float fValue);

extern __m128 DAT_011b6d70;
extern __m128 DAT_01267e30;


struct SweepAabb { __declspec(align(16)) Vec4 m_kMinimumCorner; Vec4 m_kMaximumCorner; };
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
    __declspec(align(16)) Vec4 m_kVectorAt40;
    __declspec(align(16)) Vec4 m_kVectorAt50;
    __declspec(align(16)) Vec4 m_vScale;
    int hkp3AxisSweep_addObject(void* a1, const SweepAabb& aabb, int a3);
};

// @fnv 0x00d114e0
// src: XBOX_PDB 0x00d114e0
int SweepCls::hkp3AxisSweep_addObject(void* a1, const SweepAabb& aabb, int a3)
{
    SweepAabbInt out;
    const __m128 maxVal = DAT_011b6d70;
    {
        __m128 v = _mm_add_ps(m_kVectorAt40.getQuad(), aabb.m_kMinimumCorner.getQuad());
        v = _mm_mul_ps(v, m_vScale.getQuad());
        v = _mm_min_ps(v, maxVal);
        v = _mm_max_ps(v, DAT_01267e30);
        __declspec(align(16)) Vec4 t(v);
        const float* f = (const float*)&t;
        out.m_min0 = fnv_FloatToInt(f[0]);
        out.m_min1 = fnv_FloatToInt(f[1]);
        out.m_min2 = fnv_FloatToInt(f[2]);
        out.m_min3 = fnv_FloatToInt(f[3]);
    }
    {
        __m128 v = _mm_add_ps(m_kVectorAt50.getQuad(), aabb.m_kMaximumCorner.getQuad());
        v = _mm_mul_ps(v, m_vScale.getQuad());
        v = _mm_min_ps(v, maxVal);
        v = _mm_max_ps(v, DAT_01267e30);
        __declspec(align(16)) Vec4 t(v);
        const float* f = (const float*)&t;
        out.m_max0 = fnv_FloatToInt(f[0]);
        out.m_max1 = fnv_FloatToInt(f[1]);
        out.m_max2 = fnv_FloatToInt(f[2]);
        out.m_max3 = fnv_FloatToInt(f[3]);
    }
    return v14(a1, &out, a3);
}

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
// @fnv 0x00d112c0
// src: XBOX_PDB 0x00d112c0
void S_00d112c0::hkp3AxisSweep_setBitsBasedOnXInterval(int numNodes, int key, const S_00d112c0_Node* aabb, hkUint16 skip, hkUint32* bits)
{
    unsigned minX = aabb->m_min0;
    unsigned maxX = aabb->m_max0;
    int n = numNodes >> 7;
    __m128 zero = _mm_setzero_ps();
    hkUint32* const b0 = bits;
    __m128* d = (__m128*)b0;
    for (; n >= 0; n--) {
        __m128* t = d;
        d++;
        _mm_store_ps((float*)t, zero);
    }
    S_00d112c0_EndPoint* ep = m_ep + 1;
    if (m_iMarkerCount) {
        key >>= (16 - m_markerShift);
        if (key > 0) {
            const S_00d112c0_Marker* m = &m_pOverlappingMarkerInfo[key - 1];
            flip(bits, m->m_usIndex);
            const hkUint16* l = m->m_kNode;
            int c = m->m_uiItemCount - 1;
            while (c >= 0) {
                if (*l != skip)
                    flip(bits, *l);
                l++;
                c--;
            }
            const S_00d112c0_Node* n = &m_kNodeCollection[m->m_usIndex];
            S_00d112c0_EndPoint* p = m_ep + n->m_min0 + 1;
            S_00d112c0_EndPoint* e = m_ep + n->m_max0;
            for (; p < e; p++)
                if (!(p->m_uiFilterValue & 1))
                    clear(bits, p->m_usIndex);
            ep = m_ep + n->m_min0 + 1;
        }
    }
    S_00d112c0_EndPoint* e1 = m_ep + minX;
    for (; ep < e1; ep++)
        flip(bits, ep->m_usIndex);
    ep++;
    S_00d112c0_EndPoint* e2 = m_ep + maxX;
    for (; ep < e2; ep++)
        if (!(ep->m_uiFilterValue & 1))
            flip(bits, ep->m_usIndex);
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
// @fnv 0x00d12040
// src: XBOX_PDB 0x00d12040
void Sweep8::hkp3AxisSweep_updateAabbs(int** a0, unsigned int a1, int a2, unsigned int volatile a3, unsigned int volatile a4)
{
    
    int** r;
    int** res = a0 + a2;
    r = a0;

    if (r < res) {
        do {
            Bounds33 bounds; convert33(const_cast<const unsigned int&>(a1), bounds);
            unsigned int pObj;
            Obj8* key;
            key = objs;
            pObj = **r;
            Obj8* ep;
            ep = key + pObj;
            axis34_0(key,pObj,*ep,bounds.min[0],bounds.max[0],const_cast<const unsigned int&>(a3),const_cast<const unsigned int&>(a4));
            axis34_1(key,pObj,*ep,bounds.min[1],bounds.max[1],const_cast<const unsigned int&>(a3),const_cast<const unsigned int&>(a4));
            {
 const unsigned int& added=const_cast<const unsigned int&>(a3); const unsigned int& removed=const_cast<const unsigned int&>(a4);

            // P7 backward: listC, pos field f1, p bounds.min[2], backward + bwd-equal (4x u16 overlap test, pairs f5/f4 + f2/f0)
            {
                End8* list = listC;
                int obj = ep->f1;
                End8* i = list + obj;
                unsigned int p = bounds.min[2];
                unsigned int n = i[-1].key;
                if (p < n) {
                    do {
                        int nextKey = i[-1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        if (n & 1) {
                            unsigned short a;
                            a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot3() = (unsigned short)obj;
                            if ((a & 0x8000) == 0)
                                AppendPairToBuffer(ep, other, added);
                        } else {
                            other->slot1() = (unsigned short)obj;
                        }
                        n = i[-1].key;
                        obj--;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (pObj >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot1() = (unsigned short)obj;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ((End8*)i)->id = (unsigned short)pObj;
                ((End8*)i)->key = (unsigned short)p;
                ep->f1 = (unsigned short)obj;
            }
            // P8: listC, pos field f3, p bounds.max[2], forward + fwd-equal + backward + bwd-equal
            {
                End8* list = listC;
                int obj = ep->f3;
                End8* i = list + obj;
                unsigned int p = bounds.max[2];
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        i[0].packed = i[1].packed;
                        i++;
                        int nextKey = i[0].id;
                        Obj8* other = key + nextKey;
                        obj++;
                        if ((otherIdx & 1) == 0) {
                            unsigned short a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot1()--;
                            if ((a & 0x8000) == 0)
                                AppendPairToBuffer(ep, other, added);
                        } else {
                            other->slot3()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (pObj <= nextKey) break;
                        if (nextKey == 0) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot3()--;
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
                            unsigned short a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot1()++;
                            if ((a & 0x8000) == 0)
                                AppendPairEntry(ep, other, removed);
                        } else {
                            other->slot3()++;
                        }
                        n = i[-1].key;
                    } while (p < n);
                }
                if (p == i[-1].key) {
                    do {
                        unsigned int nextKey = i[-1].id;
                        if (pObj >= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[-1].packed;
                        i--;
                        other->slot3()++;
                        n = i[-1].key;
                        obj--;
                    } while (p == n);
                }
                ep->f3 = (unsigned short)obj;
                ((End8*)i)->key = (unsigned short)p;
                ((End8*)i)->id = (unsigned short)pObj;
            }
            // P7 forward: listC, pos field f1, p bounds.min[2], forward + fwd-equal
            {
                End8* list = listC;
                int obj = ep->f1;
                End8* i = list + obj;
                unsigned int p = bounds.min[2];
                unsigned int otherIdx = i[1].key;
                if (p > otherIdx) {
                    do {
                        int nextKey = i[1].id;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        obj++;
                        if (otherIdx & 1) {
                            unsigned short a = (unsigned short)(other->f5 - ep->f4) | (unsigned short)(ep->f5 - other->f4) | (unsigned short)(other->f2 - ep->f0) | (unsigned short)(ep->f2 - other->f0);
                            other->slot3()--;
                            if ((a & 0x8000) == 0)
                                AppendPairEntry(ep, other, removed);
                        } else {
                            other->slot1()--;
                        }
                        otherIdx = i[1].key;
                    } while (p > otherIdx);
                }
                if (p == i[1].key) {
                    do {
                        unsigned int nextKey = i[1].id;
                        if (pObj <= nextKey) break;
                        Obj8* other = key + nextKey;
                        i[0].packed = i[1].packed;
                        i++;
                        other->slot1()--;
                        otherIdx = i[1].key;
                        obj++;
                    } while (p == otherIdx);
                }
                ep->f1=(unsigned short)obj;
i->id=(unsigned short)pObj;
i->key=(unsigned short)p;
a1+=sizeof(Vec33);
a1+=sizeof(Vec33);
            }

    }

r += 1;
        } while (r < res);
    }
}

#include <xmmintrin.h>
namespace fnv_00d154a0 {
extern "C" void _ReadWriteBarrier(void);
extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;

struct Alloc154 {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* alloc(int& size);
    virtual void ReleaseBlock(void* p, int n);
};
struct Obj154 {
    virtual float unk00(int a, int b);
    virtual float call4(int a, int b);
};

struct Entry16 {
    unsigned short key;
    unsigned short pad;
    unsigned short* list;
    int count;
    int capacity;
};
struct Node16 {
    int f0; int f4;
    unsigned short f8;
    unsigned short f10;
    int f12;
};
struct Elem64 {
    int minPair;
    int maxPair;
    int unk8;
    int handle;
};

// A view beginning at one node's packed maximum and ending at the next node's minimum.
struct NodeTail154 { int maxPair,unk8,handle,nextMinPair; };

struct Axis154 : hkArrayBase<Entry> {
    Entry* LowerBoundEntry(Entry*, Entry*, int);
    __forceinline void search(int low,int high,unsigned short& lower,unsigned short& upper) {
        Entry* base=m_data;
        Entry* last=base+m_iElementCount-2;
        Entry* res=LowerBoundEntry(base+1,last,low);
        lower=(unsigned short)(res-base);
        res=LowerBoundEntry(base+1,last,high);
        upper=(unsigned short)(res-(base+1));
    }

};

struct Aabb154 {__m128 min,max;};
struct Input154 { const Aabb154* p; Input154(const Aabb154* q):p(q) {} };
struct Callback154 { Obj154* p; Callback154(Obj154* q):p(q) {} };
struct Sweep154 {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    __m128 unk40;
    __m128 unk50;
    __m128 unk60;
    int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c;
    int unk90; int unk94; int unk98; int unk9c;
    Node16* unkA0;
    int unkA4;
    int unkA8;
    int* unkAC;
    int unkB0, unkB4;
    Axis154 axisB8;
    Axis154 axisC4;
    int unkD0;
    int unkD4;
    Entry16* unkD8;

    void hkp3AxisSweep_querySingleAabbWithCollector(Input154 input, Callback154 callback);
};

static void toggleBit(int* buf,int v){int idx=v>>5;int mask=1<<(v&31);buf[idx]^=mask;}
static void clearBit(int* buf,int v){int idx=v>>5;int mask=1<<(v&31);buf[idx]&=~mask;}
// @fnv 0x00d154a0
// src: XBOX_PDB 0x00d154a0
void Sweep154::hkp3AxisSweep_querySingleAabbWithCollector(Input154 input, Callback154 callback) {
    int* wordEnd;
    (void)&wordEnd; // Keep the end pointer first in the compiler's local-symbol ordering.
    int count = unkA4;
    int nInts = (count >> 5) + 8;
    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
    Alloc154* alloc = reinterpret_cast<Alloc154*>(router->m_temp);
    int* buf;
    int cap;
    if (nInts != 0) {
        int reqSize=nInts*4;
        int* data=(int*)alloc->alloc(reqSize);
        int capacity=reqSize/4;
        buf=data;
        _ReadWriteBarrier();
        cap=capacity;
    } else {buf=0;cap=0;}
    if(!cap) cap=0x80000000;
    int nWords = count >> 7;
    __m128 zero = _mm_setzero_ps();
    __m128* zp = (__m128*)buf;
    for (int i = nWords; i >= 0; i--) { _mm_store_ps((float*)zp++, zero); }
    __m128 in0 = input.p->min;
    __m128 in1 = input.p->max;
    const __m128& scale = unk60;
    __m128 cmax = DAT_011b3790;
    const __m128& coff = DAT_011b3770;
    __m128 r = _mm_add_ps(_mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(unk40, in0), scale), cmax), zero), coff);
    struct Scratch154 { unsigned short ep[4]; union { __m128 vector; unsigned int u[4]; struct {int low[4],high[4];} bounds; } tmp; } scratch;
    scratch.tmp.vector = r;

    scratch.ep[0] = (unsigned short)(scratch.tmp.u[0] >> 7);
    scratch.ep[1] = (unsigned short)(scratch.tmp.u[1] >> 7);
    scratch.ep[2] = (unsigned short)(scratch.tmp.u[2] >> 7);
    __m128 r2 = _mm_add_ps(_mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(unk50, in1), scale), cmax), zero), coff);
    scratch.tmp.vector = r2;
    unsigned int hx=scratch.tmp.u[0]>>7,hy=scratch.tmp.u[1]>>7,hz=scratch.tmp.u[2]>>7;

    scratch.tmp.bounds.low[0] = *(int*)&scratch.ep[0] & 0xfffe;
    scratch.tmp.bounds.low[1] = *(int*)&scratch.ep[1] & 0xfffe;
    scratch.tmp.bounds.low[2] = *(int*)&scratch.ep[2] & 0xfffe;
    scratch.tmp.bounds.high[0] = (unsigned short)hx | 1;
    scratch.tmp.bounds.high[1] = (unsigned short)hy | 1;
    scratch.tmp.bounds.high[2] = (unsigned short)hz | 1;

    Endpoint* scan = (Endpoint*)unkAC + 1;
    if (unkD0 != 0) {
        int idx = scratch.tmp.bounds.low[0] >> (16 - unkD4);
        if (idx > 0) {
            Entry16* e = &unkD8[idx - 1];
            toggleBit(buf, e->key);
            unsigned short* cur = e->list;
            int rem = e->count - 1;
            while (rem >= 0) {
                toggleBit(buf, *cur);
                cur++;
                rem--;
            }
            Node16* node = &unkA0[e->key];
            Endpoint* axis=(Endpoint*)unkAC;
            int lower=node->f8,upper=node->f10;
            Endpoint* q=axis+lower+1;Endpoint* end=axis+upper;
            for (;q<end;q++) {
                if (!(q->value & 1))
                    clearBit(buf, q->handle);
            }
            scan = (Endpoint*)unkAC + node->f8 + 1;
        }
    }
    while (scan->value < (unsigned int)scratch.tmp.bounds.low[0]) {
        toggleBit(buf, scan->handle);
        scan++;
    }
    while (scan->value < (unsigned int)scratch.tmp.bounds.high[0]) {
        if (!(scan->value & 1))
            toggleBit(buf, scan->handle);
        scan++;
    }

    axisB8.search(scratch.tmp.bounds.low[1],scratch.tmp.bounds.high[1],scratch.ep[0],scratch.ep[2]);
    axisC4.search(scratch.tmp.bounds.low[2],scratch.tmp.bounds.high[2],scratch.ep[1],scratch.ep[3]);
    int* wp=buf;
    Elem64* ausAnimationGroup = (Elem64*)unkA0;
    wordEnd = buf + (unkA4 >> 5) + 1;
    if(wp < wordEnd) {
    Obj154* obj = callback.p;
    do {
        int word = *wp;
        NodeTail154* g = (NodeTail154*)&ausAnimationGroup[2].maxPair;
        while (word != 0) {
            if (word & 0xf) {
                if (word & 1) {
                    if ((((*(int*)&scratch.ep[2] - g[-3].nextMinPair) | (g[-2].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[-2].handle & 1))
                        obj->call4(g[-2].handle, 0);
                }
                if (word & 2) {
                    if ((((*(int*)&scratch.ep[2] - g[-2].nextMinPair) | (g[-1].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[-1].handle & 1))
                        obj->call4(g[-1].handle, 0);
                }
                if (word & 4) {
                    if ((((*(int*)&scratch.ep[2] - g[-1].nextMinPair) | (g[0].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[0].handle & 1))
                        obj->call4(g[0].handle, 0);
                }
                if (word & 8) {
                    if ((((*(int*)&scratch.ep[2] - g[0].nextMinPair) | (g[1].maxPair - *(int*)&scratch.ep[0])) & 0x80008000) == 0 && !(g[1].handle & 1))
                        obj->call4(g[1].handle, 0);
                }
            }
            word = (int)((unsigned int)word >> 4);
            g += 4;
        }
        ausAnimationGroup += 32;
        ++wp;
    }while(wp < wordEnd);

    }
    hkMemoryRouter* router2 = (&hkMemoryRouter::getInstance());
    Alloc154* alloc2 = reinterpret_cast<Alloc154*>(router2->m_temp);
    if (!(cap & 0x80000000))
        alloc2->ReleaseBlock(buf, (cap & 0x3fffffff) * 4);
}

__declspec(noinline) Entry* Axis154::LowerBoundEntry(Entry* first, Entry* last, int key) {
    while (last-first > 16) {
        Entry* middle=first+((last-first)>>1);
        if (middle->key < (unsigned short)key) first=middle;
        else last=middle;
    }
    while (first->key < (unsigned short)key) ++first;
    return first;
}
}  // namespace fnv_00d154a0

// @fnv 0x00d11000
// src: GUESS 0x00d11000 (confidence: low)
static __declspec(noinline) unsigned int* Object_ProcessEntries_00d11000(unsigned int* dst, int n)
{
    int i = n >> 4;
    __m128 zero = _mm_setzero_ps();
    if (i >= 0) {
        unsigned int* p = dst;
        do {
            unsigned int* cur = p;
            p = cur + 4;
            _mm_store_ps((float*)cur, zero);
            i--;
        } while (i >= 0);
        return p;
    }
    return dst;
}

unsigned int* volatile g_zeroDestination;
volatile int g_zeroLength;
unsigned int* CallZeroBlocks() { return Object_ProcessEntries_00d11000(g_zeroDestination, g_zeroLength); }

#include <xmmintrin.h>
namespace fnv_00d159a0 {
#include <xmmintrin.h>


struct S159a0_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int& reqNumBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};
inline S159a0_Alloc& S159a0_stack() { return GetTemporaryAllocator<S159a0_Alloc>(*(&hkMemoryRouter::getInstance())); }

struct S159a0_Node {
    unsigned short m_usValue00;
    unsigned short m_usValue02;
    unsigned short m_usValue04;
    unsigned short m_usValue06;
    unsigned short minX;
    unsigned short maxX;
    unsigned int handle;
    unsigned int yzDisjoint(const S159a0_Node& o) const
    {
        unsigned int maxA = *(const unsigned int*)&m_usValue04;
        unsigned int minB = *(const unsigned int*)&o.m_usValue00;
        unsigned int maxB = *(const unsigned int*)&o.m_usValue04;
        unsigned int minA = *(const unsigned int*)&m_usValue00;
        maxB -= minA;
        maxA -= minB;
        return (maxA | maxB) & 0x80008000;
    }
};
inline void destroyOverlappingNodes(hkArrayBase<S159a0_Node*>& nodes)
{
    S159a0_Alloc& a = S159a0_stack();
    nodes.m_iElementCount = 0;
    if ((nodes.m_iCapacityState & 0x80000000) == 0)
        a.ReturnMemory(nodes.m_data, (nodes.m_iCapacityState & 0x3fffffff) * sizeof(S159a0_Node*));
}
void __cdecl hkArrayUtil__reserve(S159a0_Alloc* alloc, hkArrayBase<S159a0_Node*>* arr, int numElements, int sizeElem);

struct S159a0_Marker {
    unsigned short m_usIndex;
    unsigned short m_uiFilterValue;
    hkArray<unsigned short> m_kMarkerIndices;
};
struct S159a0_Axis : hkArrayBase<Endpoint> {
    Endpoint* LowerBoundEntry(Endpoint* first, Endpoint* last, unsigned int value);
};
union __declspec(align(16)) S159a0_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
union S159a0_QuadInt {
    __m128 q;
    unsigned int u[4];
};
struct __declspec(align(16)) S159a0_AabbInt {
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};
struct S159a0_Aabb {
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};
extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;



inline void S159a0_convert(const __m128& in, const __m128& offset, const __m128& scale, const Vec4& minV, const Vec4& maxV, S159a0_IntUnion64& out)
{
    __m128 x = _mm_add_ps(offset, in);
    x = _mm_mul_ps(x, scale);
    x = _mm_min_ps(x, maxV.getQuad());
    x = _mm_max_ps(x, minV.getQuad());
    x = _mm_add_ps(x, DAT_011b3770);
    S159a0_QuadInt u;
    u.q = x;
    out.u16[0] = (unsigned short)(u.u[0] >> 7);
    out.u16[1] = (unsigned short)(u.u[1] >> 7);
    out.u16[2] = (unsigned short)(u.u[2] >> 7);
}

inline void S159a0_flip(unsigned int* bits, int i) { int mask = 1 << (i & 31); int w = i >> 5; bits[w] ^= mask; }
inline void S159a0_clear(unsigned int* bits, int i) { int mask = 1 << (i & 31); int w = i >> 5; bits[w] &= ~mask; }

inline void S159a0_memClear16(void* dst, int numQuads)
{
    __m128 zero = _mm_setzero_ps();
    __m128* d = (__m128*)dst;
    for (int i = numQuads - 1; i >= 0; i--)
        _mm_store_ps((float*)d++, zero);
}

struct S159a0_Sweep {
    int unk00; int unk04; int unk08; int unk0c;
    __m128 unk10; __m128 unk20; __m128 unk30;
    __m128 m_kVectorAt40; __m128 m_kVectorAt50; __m128 m_vScale;
    __m128 unk70; __m128 unk80; __m128 unk90;
    S159a0_Node* m_kNodeCollection; int m_iNodeCount; int m_nodesCap;
    S159a0_Axis m_kAxisEndPoints[3];
    int m_iMarkerCount; int m_iMarkerCapacity; S159a0_Marker* m_pOverlappingMarkerInfo;
    void calcAabbCacheInternal(hkArrayBase<S159a0_Node*>* nodes, PairArray* out);
    __forceinline void querySingleAabbSub(unsigned int* handle, const unsigned int* bitField, const unsigned int* bitFieldEnd, const S159a0_Node& queryNode, hkArrayBase<S159a0_Node*>& out);
    void hkp3AxisSweep_calcAabbCache(const S159a0_Aabb& aabb, PairArray& out);
};

inline void S159a0_test(S159a0_Node* n, int k, const S159a0_Node& q, hkArrayBase<S159a0_Node*>& arr)
{
    if (!q.yzDisjoint(n[k]) && !(n[k].handle & 1))
        arr.m_data[arr.m_iElementCount++] = &n[k];
}

__forceinline void S159a0_Sweep::querySingleAabbSub(unsigned int* handle, const unsigned int* bitField, const unsigned int* bitFieldEnd, const S159a0_Node& queryNode, hkArrayBase<S159a0_Node*>& out)
{
    const unsigned int* b = bitField;
    S159a0_Node* nodes = &m_kNodeCollection[0];
    bitFieldEnd += (m_iNodeCount >> 5) + 1;
    for (; b < bitFieldEnd; nodes += 32, b++) {
        unsigned int bits = *b;
        if (!bits) continue;
        S159a0_Node* n = nodes;
        do {
            if (bits & 15) {
                if (bits & 1) S159a0_test(n, 0, queryNode, out);
                if (bits & 2) S159a0_test(n, 1, queryNode, out);
                if (bits & 4) S159a0_test(n, 2, queryNode, out);
                if (bits & 8) S159a0_test(n, 3, queryNode, out);
            }
            bits >>= 4;
            n += 4;
        } while (bits);
    }
}

// @fnv 0x00d159a0
// src: XBOX_PDB 0x00d159a0
void S159a0_Sweep::hkp3AxisSweep_calcAabbCache(const S159a0_Aabb& aabb, PairArray& out)
{
    // Preserve the original explicit initialization without invoking the array constructor.
    void* overlappingStorage[sizeof(hkArrayBase<S159a0_Node*>) / sizeof(void*)];
    hkArrayBase<S159a0_Node*>& overlapping = reinterpret_cast<hkArrayBase<S159a0_Node*>&>(overlappingStorage);
    overlapping.m_data = 0;
    overlapping.m_iElementCount = 0;
    overlapping.m_iCapacityState = 0x80000000;
    {
        int n = m_iNodeCount;
        hkMemoryRouter* r = (&hkMemoryRouter::getInstance());
        if ((overlapping.m_iCapacityState & 0x3fffffff) < n)
            hkArrayUtil__reserve(reinterpret_cast<S159a0_Alloc*>(r->m_temp), &overlapping, n, 4);
    }

    int numNodes = m_iNodeCount;
    int bitFieldSize = (numNodes >> 5) + 8;
    unsigned int* b = 0;
    unsigned int* bitField;
    int bitFieldCap;
    {
        S159a0_Alloc& a = S159a0_stack();
        if (bitFieldSize) {
            int bytes = bitFieldSize * 4;
            bitField = (unsigned int*)a.AllocateBufferWithSize(bytes);
            bitFieldCap = bytes / 4;
        } else {
            bitField = 0;
            bitFieldCap = 0;
        }
        if (!bitFieldCap) bitFieldCap = 0x80000000;
    }
    S159a0_memClear16(bitField, (numNodes >> 7) + 1);
    __declspec(align(16)) Vec4 clipMin(_mm_setzero_ps());
    __declspec(align(16)) Vec4 clipMax(DAT_011b3790);

    S159a0_AabbInt aabbInt;
    S159a0_IntUnion64 mi;
    {
        S159a0_IntUnion64 ma;
        S159a0_convert(aabb.m_kMinimumCorner, m_kVectorAt40, m_vScale, clipMin, clipMax, mi);
        S159a0_convert(aabb.m_kMaximumCorner, m_kVectorAt50, m_vScale, clipMin, clipMax, ma);
        aabbInt.m_kMinimumCorner[0] = mi.u16[0] & 0xfffe;
        aabbInt.m_kMinimumCorner[1] = mi.u16[1] & 0xfffe;
        aabbInt.m_kMinimumCorner[2] = mi.u16[2] & 0xfffe;
        aabbInt.m_kMaximumCorner[0] = ma.u16[0] | 1;
        aabbInt.m_kMaximumCorner[1] = ma.u16[1] | 1;
        aabbInt.m_kMaximumCorner[2] = ma.u16[2] | 1;
    }

    Endpoint* ep = m_kAxisEndPoints[0].m_data + 1;
    if (m_iMarkerCount) {
        int mk = (int)aabbInt.m_kMinimumCorner[0] >> (16 - m_iMarkerCapacity);
        if (mk > 0) {
            S159a0_Marker* m = &m_pOverlappingMarkerInfo[mk - 1];
            S159a0_flip(bitField, m->m_usIndex);
            unsigned short* o = m->m_kMarkerIndices.m_data;
            for (int i = m->m_kMarkerIndices.m_iElementCount - 1; i >= 0; i--)
                S159a0_flip(bitField, *o++);
            S159a0_Node* node = &m_kNodeCollection[m->m_usIndex];
            Endpoint* e = m_kAxisEndPoints[0].m_data + node->minX + 1;
            Endpoint* end = m_kAxisEndPoints[0].m_data + node->maxX;
            for (; e < end; e++)
                if (!(e->value & 1)) S159a0_clear(bitField, e->handle);
            ep = m_kAxisEndPoints[0].m_data + node->minX + 1;
        }
    }
    while (ep->value < aabbInt.m_kMinimumCorner[0]) {
        S159a0_flip(bitField, ep->handle);
        ep++;
    }
    while (ep->value < aabbInt.m_kMaximumCorner[0]) {
        if (!(ep->value & 1)) S159a0_flip(bitField, ep->handle);
        ep++;
    }

    S159a0_Node qn;
    {
        S159a0_Axis& ax = m_kAxisEndPoints[1];
        Endpoint* data = ax.m_data;
        Endpoint* last = data + ax.m_iElementCount - 2;
        qn.m_usValue00 = (unsigned short)(ax.LowerBoundEntry(data + 1, last, aabbInt.m_kMinimumCorner[1]) - data);
        qn.m_usValue04 = (unsigned short)(ax.LowerBoundEntry(data + 1, last, aabbInt.m_kMaximumCorner[1]) - 1 - data);
    }
    {
        S159a0_Axis& ax = m_kAxisEndPoints[2];
        Endpoint* data = ax.m_data;
        Endpoint* last = data + ax.m_iElementCount - 2;
        qn.m_usValue02 = (unsigned short)(ax.LowerBoundEntry(data + 1, last, aabbInt.m_kMinimumCorner[2]) - data);
        qn.m_usValue06 = (unsigned short)(ax.LowerBoundEntry(data + 1, last, aabbInt.m_kMaximumCorner[2]) - 1 - data);
    }

    querySingleAabbSub(b, bitField, bitField, qn, overlapping);

    {
        S159a0_Alloc& a = S159a0_stack();
        if ((bitFieldCap & 0x80000000) == 0) a.ReturnMemory(bitField, (bitFieldCap & 0x3fffffff) * 4);
    }
    calcAabbCacheInternal(&overlapping, &out);
    destroyOverlappingNodes(overlapping);
}
}  // namespace fnv_00d159a0

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d16c50 {
#include <math.h>


struct S16c50_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int& numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
    template <class T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * (int)sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <class T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};
struct S16c50_TempAllocator {
    S16c50_Alloc& get(void*) { return GetTemporaryAllocator<S16c50_Alloc>(*(&hkMemoryRouter::getInstance())); }
};



} // namespace fnv_00d16c50

// Preserve this scratch array's original allocator call form.
template <>
__forceinline hkArray<unsigned char, hkContainerTempAllocator>::hkArray(int n)
    : hkArrayBase<unsigned char>()
{
    fnv_00d16c50::S16c50_Alloc& a = fnv_00d16c50::S16c50_TempAllocator().get(this);
    unsigned char* p = n ? a._bufAlloc<unsigned char>(n) : 0;
    int cap = n ? n : (int)0x80000000;
    m_data = p;
    m_iElementCount = n;
    m_iCapacityState = cap;
}
template <>
__forceinline hkArray<unsigned char, hkContainerTempAllocator>::~hkArray()
{
    fnv_00d16c50::S16c50_Alloc& a = fnv_00d16c50::S16c50_TempAllocator().get(this);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        a._bufFree<unsigned char>(m_data, m_iCapacityState & 0x3fffffff);
    m_data = 0;
    m_iCapacityState = (int)0x80000000;
}

namespace fnv_00d16c50 {

// Retained: the shared vector's zeroing default constructor changes this function's bytes.
struct S16c50_Vec4 {
    __m128 m_vComponents;
    float& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    const float& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    void setAdd4(const S16c50_Vec4& a, const S16c50_Vec4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setSub4(const S16c50_Vec4& a, const S16c50_Vec4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void operator=(const S16c50_Vec4& v) { m_vComponents = v.m_vComponents; }
};

union S16c50_IntUnion64 {
    unsigned short u16[4];
    unsigned int u32[2];
};
union S16c50_QuadInt {
    __m128 q;
    unsigned int i[4];
};
extern __m128 DAT_011b3790;
extern __m128 DAT_011b3770;

__forceinline void S16c50_convertToUint16WithClip(const S16c50_Vec4& in, const S16c50_Vec4& offset, const S16c50_Vec4& scale, const S16c50_Vec4& minV, const S16c50_Vec4& maxV, S16c50_IntUnion64& out)
{
    __m128 x = _mm_add_ps(offset.m_vComponents, in.m_vComponents);
    x = _mm_mul_ps(x, scale.m_vComponents);
    x = _mm_min_ps(x, maxV.m_vComponents);
    x = _mm_max_ps(x, minV.m_vComponents);
    x = _mm_add_ps(x, DAT_011b3770);
    S16c50_QuadInt u;
    u.q = x;
    out.u16[0] = (unsigned short)(u.i[0] >> 7);
    out.u16[1] = (unsigned short)(u.i[1] >> 7);
    out.u16[2] = (unsigned short)(u.i[2] >> 7);
    out.u16[3] = (unsigned short)(u.i[3] >> 7);
}

struct S16c50_EndPoint {
    unsigned short m_uiFilterValue;
    unsigned short m_usIndex;
    int isMaxPoint() const { return m_uiFilterValue & 1; }
};
struct S16c50_Node {
    unsigned short m_min_y;
    unsigned short m_min_z;
    unsigned short m_max_y;
    unsigned short m_max_z;
    unsigned short m_min_x;
    unsigned short m_max_x;
    unsigned int m_handle;
    int isMarker() const { return m_handle & 1; }
};
struct S16c50_Collector {
    virtual void v0();
    virtual float ReleaseCollector(unsigned int handle, int castIndex);
};
struct S16c50_CastAabbInput {
    S16c50_Vec4 m_vFrom;
    S16c50_Vec4 m_vTo;
    S16c50_Vec4 m_vHalfExtents;
    const char* m_pBroadPhaseAabbCache;
};

extern const double DAT_010c9300;
extern const float DAT_0104a494, DAT_010162c0;

static __forceinline void S16c50_memclear16(void* dest, int numBytes)
{
    S16c50_Vec4 zero; zero.setZero4();
    S16c50_Vec4* d = (S16c50_Vec4*)dest;
    for (numBytes = numBytes >> 4; numBytes >= 0; numBytes--) {
        *(d++) = zero;
    }
}

static __forceinline float S16c50_min2(float a, float b) { return a < b ? a : b; }

template <class T> static inline void S16c50_swap(T& a, T& b) { T t = a; a = b; b = t; }

static __forceinline int S16c50_getMinComponent(const S16c50_Vec4& v, float& m)
{
    if (v(0) < v(1)) {
        if (v(0) < v(2)) { m = v(0); return 0; }
    } else if (v(1) < v(2)) {
        m = v(1); return 1;
    }
    m = v(2); return 2;
}

// src: HAVOK_LIB 0x00d19d10
__declspec(noinline) int __cdecl getMinComponent(const float* v, float* m)
{
    if (v[0] < v[1]) {
        if (v[0] < v[2]) { *m = v[0]; return 0; }
    } else if (v[1] < v[2]) {
        *m = v[1]; return 1;
    }
    *m = v[2]; return 2;
}

static __forceinline void S16c50_calcCurDist(int axis, S16c50_Vec4& curDist, const S16c50_EndPoint* ep, const S16c50_Vec4& invDir, const S16c50_Vec4& start)
{
    curDist(axis) = ep->m_uiFilterValue * invDir(axis) - start(axis);
}

struct S16c50_Sweep {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    S16c50_Vec4 m_kVectorAt40;
    S16c50_Vec4 m_kVectorAt50;
    S16c50_Vec4 m_vScale;
    S16c50_Vec4 unk70;
    S16c50_Vec4 unk80;
    S16c50_Vec4 unk90;
    hkArray<S16c50_Node> m_kNodeCollection;
    hkArray<S16c50_EndPoint> m_kAxisEndPoints[3];
    int m_iMarkerCount;
    int m_iMarkerCapacity;
    void* m_pOverlappingMarkerInfo;
    float m_fValueAfterOverlappingMarkerInfo;

    __forceinline void convertVectorToInt(const S16c50_Vec4& vec, unsigned int* intsOut) const
    {
        S16c50_Vec4 minVal; minVal.setZero4();
        S16c50_Vec4 maxVal; maxVal.m_vComponents = DAT_011b3790;
        S16c50_IntUnion64 out;
        S16c50_convertToUint16WithClip(vec, m_kVectorAt40, m_vScale, minVal, maxVal, out);
        intsOut[0] = out.u16[0];
        intsOut[1] = out.u16[1];
        intsOut[2] = out.u16[2];
        intsOut[3] = out.u16[3];
    }
    void hkp3AxisSweep_castAabb(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const;
};

// @fnv 0x00d16c50
// src: XBOX_PDB 0x00d16c50
void S16c50_Sweep::hkp3AxisSweep_castAabb(const S16c50_CastAabbInput& input, S16c50_Collector& collector) const
{
    S16c50_Vec4 fromMin; fromMin.setSub4(input.m_vFrom, input.m_vHalfExtents);
    S16c50_Vec4 fromMax; fromMax.setAdd4(input.m_vFrom, input.m_vHalfExtents);
    __declspec(align(16)) unsigned int auiLowerBounds[4];
    __declspec(align(16)) unsigned int auiUpperBounds[4];
    convertVectorToInt(fromMin, auiLowerBounds);
    convertVectorToInt(fromMax, auiUpperBounds);

    hkArray<unsigned char, hkContainerTempAllocator> bitFieldArray(m_kNodeCollection.GetLogicalSize() + 16);
    S16c50_memclear16(bitFieldArray.begin(), m_kNodeCollection.GetLogicalSize());

    const hkArray<S16c50_EndPoint>* axisArray = input.m_pBroadPhaseAabbCache ? (const hkArray<S16c50_EndPoint>*)input.m_pBroadPhaseAabbCache : &m_kAxisEndPoints[0];

    const S16c50_EndPoint* enterCur[3];
    const S16c50_EndPoint* exitCur[3];
    {
        unsigned char* bitField;
        bitField = bitFieldArray.begin();
        int mask = 1;
        for (int i = 0; 3 > i; i++) {
            const hkArray<S16c50_EndPoint>& axis = axisArray[i];
            if (auiLowerBounds[i] < axis[axis.GetLogicalSize() >> 1].m_uiFilterValue) {
                const S16c50_EndPoint* end = axis.begin() + axis.GetLogicalSize() - 4;
                const S16c50_EndPoint* ep = &axis[1];
                for (; ep < end; ep += 4) {
                    if (ep[3].m_uiFilterValue > auiLowerBounds[i]) break;
                    bitField[ep[0].m_usIndex] ^= mask;
                    bitField[ep[1].m_usIndex] ^= mask;
                    bitField[ep[2].m_usIndex] ^= mask;
                    bitField[ep[3].m_usIndex] ^= mask;
                }
                for (; ep->m_uiFilterValue <= auiLowerBounds[i]; ep++) {
                    bitField[ep->m_usIndex] ^= mask;
                }
                enterCur[i] = ep;
                for (; ep->m_uiFilterValue <= auiUpperBounds[i]; ep++) {
                    bitField[ep->m_usIndex] ^= mask & (ep->isMaxPoint() - 1);
                }
                exitCur[i] = ep;
            } else {
                const S16c50_EndPoint* start = axis.begin() + 4;
                const S16c50_EndPoint* ep;
                ep = &axis[axis.GetLogicalSize() - 2];
                for (; ep >= start; ep -= 4) {
                    if (ep[-3].m_uiFilterValue <= auiUpperBounds[i]) break;
                    bitField[ep[0].m_usIndex] ^= mask;
                    bitField[ep[-1].m_usIndex] ^= mask;
                    bitField[ep[-2].m_usIndex] ^= mask;
                    bitField[ep[-3].m_usIndex] ^= mask;
                }
                for (; ep->m_uiFilterValue > auiUpperBounds[i]; ep--) {
                    bitField[ep->m_usIndex] ^= mask;
                }
                exitCur[i] = 1 + ep;
                for (; ep->m_uiFilterValue > auiLowerBounds[i]; ep--) {
                    bitField[ep->m_usIndex] ^= mask & (-ep->isMaxPoint());
                }
                enterCur[i] = ep + 1;
            }
            mask <<= 1;
        }
    }

    float earliestHit = 1.0f;
    {
        const S16c50_Node* node = &m_kNodeCollection[0];
        int numNodes = m_kNodeCollection.GetLogicalSize();
        unsigned char* bf = bitFieldArray.begin();
        const unsigned int* p = (const unsigned int*)bf;
        const unsigned int* pEnd = p + (numNodes >> 2) + 1;
        for (; p < pEnd; node += 4, p++) {
            if (((*p + 0x01010101) & 0x08080808) == 0) continue;
            const unsigned char* b = (const unsigned char*)p;
            if (b[0] == 7 && !node[0].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[0].m_handle, 0));
            if (b[1] == 7 && !node[1].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[1].m_handle, 0));
            if (b[2] == 7 && !node[2].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[2].m_handle, 0));
            if (b[3] == 7 && !node[3].isMarker()) earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node[3].m_handle, 0));
        }
    }

    S16c50_Vec4 dir; dir.setSub4(input.m_vTo, input.m_vFrom);
    S16c50_Vec4 invDir;
    S16c50_Vec4 startDist;
    S16c50_Vec4 endDist;
    int step[3];
    int flipEnter[3];
    int flipExit[3];
    for (int i = 0; i < 3; i++) {
        float d = m_vScale(i) * dir(i);
        float absD = fabsf(d);
        if (d > 0.0) {
            step[i] = 4;
            flipEnter[i] = 0;
            flipExit[i] = 1;
        } else {
            step[i] = -4;
            S16c50_swap(enterCur[i], exitCur[i]);
            S16c50_swap(fromMin(i), fromMax(i));
            S16c50_swap(auiLowerBounds[i], auiUpperBounds[i]);
            enterCur[i]--;
            exitCur[i]--;
            flipEnter[i] = 1;
            flipExit[i] = 0;
        }
        float a = (fromMin(i) + m_kVectorAt40(i)) * m_vScale(i);
        float lo = m_kVectorAt40(i);
        float b = (input.m_vTo(i) + lo) * m_vScale(i);
        if (absD < a * 1.1920928955078125e-07 || absD < b * 1.1920928955078125e-07) {
            invDir(i) = 0.0f;
            startDist(i) = -2.0f;
            endDist(i) = -2.0f;
        } else {
            float inv = 1.0f / d;
            invDir(i) = inv;
            float s0 = (fromMin(i) + m_kVectorAt40(i)) * m_vScale(i);
            float s1 = s0 - m_fValueAfterOverlappingMarkerInfo;
            startDist(i) = inv * s1;
            float e0 = (fromMax(i) + m_kVectorAt40(i)) * m_vScale(i);
            float e1 = e0 - m_fValueAfterOverlappingMarkerInfo;
            endDist(i) = inv * e1;
        }
    }

    S16c50_Vec4 enterDist;
    S16c50_Vec4 exitDist;
    const S16c50_EndPoint* curEnter[3] = { enterCur[0], enterCur[1], enterCur[2] };
    const S16c50_EndPoint* curExit[3] = { exitCur[0], exitCur[1], exitCur[2] };
    enterDist(0) = curEnter[0]->m_uiFilterValue * invDir(0) - startDist(0);
    enterDist(1) = curEnter[1]->m_uiFilterValue * invDir(1) - startDist(1);
    enterDist(2) = curEnter[2]->m_uiFilterValue * invDir(2) - startDist(2);
    exitDist(0) = curExit[0]->m_uiFilterValue * invDir(0) - endDist(0);
    exitDist(1) = curExit[1]->m_uiFilterValue * invDir(1) - endDist(1);
    exitDist(2) = curExit[2]->m_uiFilterValue * invDir(2) - endDist(2);

    unsigned char* bitField = bitFieldArray.begin();
    bitField[0] = 8;
    float dummy;
    float d2;
    float d3;
    float d4;
    float d5;
    int enterAxis = S16c50_getMinComponent(enterDist, dummy);
    int exitAxis = S16c50_getMinComponent(exitDist, dummy);

    while (1) {
        if (exitDist(exitAxis) < enterDist(enterAxis)) {
            if (exitDist(exitAxis) > earliestHit) break;
            while (1) {
                unsigned int nodeIndex = curExit[exitAxis]->m_usIndex;
                int m = (curExit[exitAxis]->isMaxPoint() ^ flipExit[exitAxis]) << exitAxis;
                bitField[nodeIndex] ^= m;
                if (bitField[nodeIndex] >= 7) {
                    if (!nodeIndex) {
                        exitDist(exitAxis) = DAT_010162c0;
                        exitAxis = getMinComponent(&exitDist(0), &d2);
                        break;
                    }
                    const S16c50_Node& node = m_kNodeCollection[nodeIndex];
                    if (m && !node.isMarker()) {
                        earliestHit = S16c50_min2(earliestHit, collector.ReleaseCollector(node.m_handle, 0));
                    }
                }
                unsigned short value = curExit[exitAxis]->m_uiFilterValue;
                curExit[exitAxis] = (const S16c50_EndPoint*)((const char*)curExit[exitAxis] + step[exitAxis]);
                if (value == curExit[exitAxis]->m_uiFilterValue) continue;
                S16c50_EndPoint ep = *curExit[exitAxis];
                S16c50_calcCurDist(exitAxis, exitDist, &ep, invDir, endDist);
                exitAxis = getMinComponent(&exitDist(0), &d3);
                break;
            }
        } else {
            if (enterDist(enterAxis) > earliestHit) break;
            while (1) {
                unsigned int nodeIndex = curEnter[enterAxis]->m_usIndex;
                bitField[nodeIndex] ^= (curEnter[enterAxis]->isMaxPoint() ^ flipEnter[enterAxis]) << enterAxis;
                if (bitField[nodeIndex] > 8) {
                    enterDist(enterAxis) = DAT_010162c0;
                    enterAxis = getMinComponent(&enterDist(0), &d4);
                    break;
                }
                unsigned short value = curEnter[enterAxis]->m_uiFilterValue;
                curEnter[enterAxis] = (const S16c50_EndPoint*)((const char*)curEnter[enterAxis] + step[enterAxis]);
                if (value == curEnter[enterAxis]->m_uiFilterValue) continue;
                S16c50_EndPoint ep = *curEnter[enterAxis];
                S16c50_calcCurDist(enterAxis, enterDist, &ep, invDir, startDist);
                enterAxis = getMinComponent(&enterDist(0), &d5);
                break;
            }
        }
    }
}
}  // namespace fnv_00d16c50

extern __m128 DAT_010c44d0;
extern __m128 DAT_010c7170;
inline void Vec4::setNeg4(const Vec4& v) { getQuad() = _mm_xor_ps(v.getQuad(), DAT_010c44d0); }
inline void Vec4::setXYZW(const Vec4& xyz, const Vec4& w)
{
    getQuad() = _mm_shuffle_ps(xyz.getQuad(), _mm_unpackhi_ps(xyz.getQuad(), w.getQuad()), _MM_SHUFFLE(3, 0, 1, 0));
}
inline void Vec4::setReciprocal4(const Vec4& v)
{
    __m128 e = _mm_rcp_ps(v.getQuad());
    getQuad() = _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, v.getQuad()), e));
}




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

    __declspec(align(16)) Vec4 m_10;
    __declspec(align(16)) Vec4 m_20;
    __declspec(align(16)) Vec4 m_30;
    __declspec(align(16)) Vec4 m_lowOffset;
    __declspec(align(16)) Vec4 m_lowRounded;
    __declspec(align(16)) Vec4 m_lowScale;
    __declspec(align(16)) Vec4 m_highOffset;
    __declspec(align(16)) Vec4 m_highRounded;
    __declspec(align(16)) Vec4 m_highScale;

    void hkp3AxisSweep_shiftBroadPhase(const Vec4& distance, Vec4& appliedOut, SweepShiftPairs& pairs);
};

// @fnv 0x00d10f00
// src: XBOX_PDB 0x00d10f00
void SweepShift::hkp3AxisSweep_shiftBroadPhase(const Vec4& distance, Vec4& appliedOut, SweepShiftPairs& pairs)
{
    __declspec(align(16)) Vec4 negated(_mm_xor_ps(distance.getQuad(), DAT_010c44d0));
    // The virtual call fills this output; preserve its original uninitialized storage.
    __m128 appliedStorage;
    Vec4& applied = reinterpret_cast<Vec4&>(appliedStorage);
    shiftObjects(negated, applied, pairs);

    m_lowOffset.add4(applied);
    {
        const Vec4& one = reinterpret_cast<const Vec4&>(DAT_010c7170);
        __declspec(align(16)) Vec4 scale(_mm_setzero_ps());
        scale.setXYZW(m_lowScale, one);
        __declspec(align(16)) Vec4 step(_mm_setzero_ps());
        step.setReciprocal4(scale);
        m_lowRounded.setAdd4(step, m_lowOffset);
    }
    m_highOffset.add4(applied);
    {
        const Vec4& one = reinterpret_cast<const Vec4&>(DAT_010c7170);
        __declspec(align(16)) Vec4 scale(_mm_setzero_ps());
        scale.setXYZW(m_highScale, one);
        __declspec(align(16)) Vec4 step(_mm_setzero_ps());
        step.setReciprocal4(scale);
        m_highRounded.setAdd4(step, m_highOffset);
    }
    appliedOut.setNeg4(applied);
}

void __cdecl ResizeAudioStream(void* allocator,void* array,int elementSize);
struct S4ef0Allocator {
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
 virtual void ReturnMemory(void* p,int numBytes);
 template<class T> __forceinline T* _bufAlloc(int& reqNumInOut) { const int SIZE_ELEM=sizeof(T); int n=reqNumInOut*SIZE_ELEM; void* p=AllocateBufferWithSize(n); reqNumInOut=n/SIZE_ELEM; return static_cast<T*>(p); }
 template<class T> __forceinline void _bufFree(void* p,int numElem) { const int SIZE_ELEM=sizeof(T); ReturnMemory(p,numElem*SIZE_ELEM); }
};
struct S4ef0TempAlloc { __forceinline S4ef0Allocator& get(void*) { return GetTemporaryAllocator<S4ef0Allocator>(*(&hkMemoryRouter::getInstance())); } };
struct S4ef0HeapAlloc { __forceinline S4ef0Allocator& get(const void*) { return reinterpret_cast<S4ef0Allocator&>((&hkMemoryRouter::getInstance())->heap()); } };
// Preserve the original temporary allocator call form for the word scratch array.
template <>
__forceinline hkArray<unsigned int, hkContainerTempAllocator>::hkArray(int n)
    : hkArrayBase<unsigned int>()
{
    S4ef0Allocator& alloc = S4ef0TempAlloc().get(this);
    unsigned int* p = n ? alloc._bufAlloc<unsigned int>(n) : 0;
    int cap = n ? n : hkArrayBase<unsigned int>::DONT_DEALLOCATE_FLAG;
    setOwnedData(p, n, cap);
}
template <>
__forceinline hkArray<unsigned int, hkContainerTempAllocator>::~hkArray()
{
    S4ef0Allocator& alloc = S4ef0TempAlloc().get(this);
    clear();
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc._bufFree<unsigned int>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}
struct S4ef0TypeIsPod {}; struct S4ef0TypeIsClass {};
template<class T> __forceinline void S4ef0_construct(T* t,int n,S4ef0TypeIsPod) {}
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsClass) { for(int i=0;i<n;++i) { if(t+i) t[i]=tcopy; } }
template<class T> __forceinline void S4ef0_constructWithCopy(T* t,int n,const T& tcopy,S4ef0TypeIsPod) { for(int i=0;i<n;++i) { t[i]=tcopy; } }
struct S4ef0Aabb { __declspec(align(16)) Vec4 m_kMinimumCorner,m_kMaximumCorner; };
__declspec(align(16)) struct S4ef0AabbInt { unsigned int m_kMinimumCorner[3]; unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; unsigned int m_kMaximumCorner[3]; unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
union S4ef0Union64 { __m128 quad; __int64 i64; unsigned __int64 u64; int i32[2]; unsigned int u32[2]; short i16[4]; unsigned short u16[4]; };
__forceinline void S4ef0_convertToUint16WithClip(const Vec4& in,const Vec4& offset,const Vec4& scale,const Vec4& min,const Vec4& max,S4ef0Union64& out) {
 __declspec(align(16)) Vec4 x(_mm_add_ps(in.getQuad(), offset.getQuad()));
 x.mul4(scale);
 x.setMin(x,max);
 x.setMax(x,min);
 __declspec(align(16)) Vec4 magic(*(const __m128*)DAT_011b3770);
 x.add4(magic);
 union { __m128 q; unsigned int i[4]; } u;
 u.q=x.getQuad();
 out.i16[0]=(short)(u.i[0]>>7);
 out.i16[1]=(short)(u.i[1]>>7);
 out.i16[2]=(short)(u.i[2]>>7);
 out.i16[3]=(short)(u.i[3]>>7);
}
__forceinline void S4ef0_memclear16(void* dest,int numBytes) {
 __declspec(align(16)) Vec4 zero(_mm_setzero_ps());
 Vec4* d=(Vec4*)dest;
 for(numBytes>>=4;numBytes>=0;numBytes--) { (d++)->getQuad()=zero.getQuad(); }
}
__forceinline void S4ef0_staticFlipBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]^=mask; }
__forceinline void S4ef0_staticClearBit(unsigned int* bitfield,int nodeIndex) { int word=nodeIndex>>5; int mask=1<<(nodeIndex&31); bitfield[word]&=~mask; }
struct S4ef0Pair { unsigned int m_kPointA,m_kPointB; };
template <>
__forceinline void hkArrayBase<S4ef0Pair>::_pushBack(hkMemoryAllocator& alloc, const S4ef0Pair& t)
{
    if (m_iElementCount == getCapacity()) ResizeAudioStream(&alloc, this, sizeof(S4ef0Pair));
    S4ef0_constructWithCopy(m_data + m_iElementCount, 1, t, S4ef0TypeIsClass());
    m_iElementCount++;
}
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
typedef hkArray<S4ef0Pair,hkContainerHeapAllocator> S4ef0Results;
typedef hkArrayBase<const S4ef0Node*> S4ef0NodeArr;
struct S4ef0Owner {
 __m128 unk00,unk10,unk20,unk30;
 __declspec(align(16)) Vec4 m_kVectorAt40,m_kVectorAt50,m_vScale;
 __m128 unk70,unk80,unk90;
 hkArrayBase<S4ef0Node> m_kNodeCollection;
 S4ef0Axis m_kAxisEndPoints[3];
 int m_iMarkerCount,m_iMarkerCapacity; S4ef0Marker* m_pOverlappingMarkerInfo;
 __forceinline int getNumMarkers() const { return m_iMarkerCount; }
 __forceinline void _convertAabbToInt(const S4ef0Aabb& aabb,S4ef0AabbInt& aabbOut) const { _convertAabbToIntS(aabb,m_kVectorAt40,m_kVectorAt50,m_vScale,aabbOut); }
 static __forceinline void _convertAabbToIntS(const S4ef0Aabb& aabb,const Vec4& offsetLow,const Vec4& offsetHigh,const Vec4& scale,S4ef0AabbInt& aabbOut);
 __forceinline void querySingleAabbSub(S4ef0Handle* object,const unsigned int* bitField,S4ef0Node& refNode,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 __forceinline void _querySingleAabb(const S4ef0Aabb& aabb,int type,S4ef0Results* pairsOut,S4ef0NodeArr* nodesOut,S4ef0Collector* collector) const;
 void hkp3AxisSweep_querySingleAabb(const S4ef0Aabb& aabb,S4ef0Results& pairsOut) const;
};
__forceinline void S4ef0Owner::_convertAabbToIntS(const S4ef0Aabb& aabb,const Vec4& offsetLow,const Vec4& offsetHigh,const Vec4& scale,S4ef0AabbInt& aabbOut) {
 __declspec(align(16)) Vec4 zero(_mm_setzero_ps());
 __declspec(align(16)) Vec4 maxVal(*(const __m128*)DAT_011b3790);
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
      if(type==0) { pair.m_kPointB=n[0].m_handle; pairsOut->pushBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[0]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[0].m_handle,0); }
     }
    }
    if(bits&2) {
     if(!n[1].yzDisjoint(refNode) && !n[1].isMarker()) {
      if(type==0) { pair.m_kPointB=n[1].m_handle; pairsOut->pushBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[1]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[1].m_handle,0); }
     }
    }
    if(bits&4) {
     if(!n[2].yzDisjoint(refNode) && !n[2].isMarker()) {
      if(type==0) { pair.m_kPointB=n[2].m_handle; pairsOut->pushBack(pair); }
      else if(type==1) { const S4ef0Node* t=&n[2]; nodesOut->pushBackUnchecked(t); }
      else { collector->ReleaseCollector(n[2].m_handle,0); }
     }
    }
    if(bits&8) {
     if(!n[3].yzDisjoint(refNode) && !n[3].isMarker()) {
      if(type==0) { pair.m_kPointB=n[3].m_handle; pairsOut->pushBack(pair); }
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
 hkArray<unsigned int,hkContainerTempAllocator> bitFieldArr((size>>5)+8);
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
// @fnv 0x00d14ef0
// src: XBOX_PDB 0x00d14ef0
void S4ef0Owner::hkp3AxisSweep_querySingleAabb(const S4ef0Aabb& aabb,S4ef0Results& pairsOut) const {
 _querySingleAabb(aabb,0,&pairsOut,0,0);
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

// Retained: migration changes the batch sweep's SIMD instruction sequence.
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
struct SweepStackPolicy {__forceinline BatchSweepAllocator& get(const void*){hkMemoryRouter* h=(&hkMemoryRouter::getInstance());return *reinterpret_cast<BatchSweepAllocator*>(h->m_temp);}};
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

struct SweepCandidateArrayLocalForm:SweepStorageBase<SweepBatchNode*> { // local form of hkArrayBase: 0x00d18400 needs this ctor/helper split; shared replacement keeps 4050 bytes but differs at 14 byte positions (+0x256..+0x285).
 __forceinline void clear(BatchSweepAllocator& alloc) {
   size=0;if(!(capacity&0x80000000))alloc.ReturnMemory(data,(capacity&0x3fffffff)*4);
   data=0;capacity=0x80000000;
 }
 __forceinline void clearAndFree() {hkMemoryRouter* holder=(&hkMemoryRouter::getInstance());clear(*reinterpret_cast<BatchSweepAllocator*>(holder->m_temp));}
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

    __forceinline void collectSweepCandidates(const BatchAabb& spl,SweepCandidateArrayLocalForm& local);
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

__forceinline void Sweep15::collectSweepCandidates(const BatchAabb& spl,SweepCandidateArrayLocalForm& local)
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
                                ((SweepBatchNode**)local.data)[local.size++]=rec+0;
                        }
                        if(word & 2) {
                            if(!rec[1].disjointYZ(sortBounds) && !rec[1].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+1;
                        }
                        if(word & 4) {
                            if(!rec[2].disjointYZ(sortBounds) && !rec[2].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+2;
                        }
                        if(word & 8) {
                            if(!rec[3].disjointYZ(sortBounds) && !rec[3].isMarker())
                                ((SweepBatchNode**)local.data)[local.size++]=rec+3;
                        }
                    }
                    word >>= 4;
                    rec += 4;
                }
                group += 32;
            }
        }
        {
            hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
            BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
            if ((bitmap.capacity & 0x80000000) == 0) al->ReturnMemory( bitmap.data, (bitmap.capacity & 0x3fffffff) * 4);
        }
    
}

// @fnv 0x00d18400
// src: XBOX_PDB 0x00d18400
void Sweep15::hkp3AxisSweep_addObjectBatch(In1* p1, In2* p2, int p3)
{
    Endpoint* ptrs[3];
    BatchAabb spl;
    In2* g = p2;
    if (g->gate < 1) return;
    In1* input = p1;
    int capA4 = arrA0.size;
    int savedN = input->count;
    int two = savedN + savedN;
    SweepBuffer<Endpoint> b1(two);
    SweepBuffer<Endpoint> b2(two);
    SweepBuffer<Endpoint> b3(two);
    SweepCandidateArrayLocalForm local; local.data = 0; local.size = 0; local.capacity = (int)0x80000000;
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        if ((local.capacity & 0x3fffffff) < capA4)
            hkArrayUtil__reserve(reinterpret_cast<BatchSweepAllocator*>(h->m_temp), &local, capA4, 4);
    }
    {
        BatchNodeArray& nodes=arrA0;
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        void* growArg = h->m_heap;
        int need = nodes.size + savedN;
        if ((nodes.capacity & 0x3fffffff) < need) {
            int want = nodes.capacity & 0x3fffffff;
            want += want;
            if (need < want) need = want;
            hkArrayUtil__reserve(growArg, &nodes, need, 0x10);
        }
        nodes.size += savedN;
    }
    spl.low.v=_mm_set1_ps(DAT_0104da48);
    spl.high.v=_mm_set1_ps(DAT_0104e148);
    ptrs[0] = b1.data; ptrs[1] = b2.data; ptrs[2] = b3.data;
    int i=0;
    if(i<savedN) {

        do {

            spl.include(p2->base[i]);
            QuantBatchAabb quantized;
            quantizeSweepAabb(m_kVectorAt40,p2->base[i],m_kVectorAt50,m_vScale,quantized);
            unsigned int* ca=quantized.low;unsigned int* db=quantized.high;
            int destIdx=capA4+i;
            SweepObjectHandle* val = p1->f0[i];
            SweepBatchNode* rec = arrA0.data + destIdx;
            rec->handle = val;
            val->id = destIdx;
            Endpoint* o1=ptrs[0]+i*2;
            o1[0].value=(unsigned short)ca[0];o1[0].handle=(unsigned short)destIdx;
            o1[1].value=(unsigned short)db[0];o1[1].handle=(unsigned short)destIdx;
            Endpoint* o2=ptrs[1]+i*2;
            o2[0].value=(unsigned short)ca[1];o2[0].handle=(unsigned short)destIdx;
            o2[1].value=(unsigned short)db[1];o2[1].handle=(unsigned short)destIdx;
            Endpoint* o3=ptrs[2]+i*2;
            o3[0].value=(unsigned short)ca[2];o3[0].handle=(unsigned short)destIdx;
            o3[1].value=(unsigned short)db[2];o3[1].handle=(unsigned short)destIdx;
            (void)ptrs;


            ++i;
        } while(i<savedN);
    }
    arrA0.setSizeUnchecked(capA4);
    collectSweepCandidates(spl,local);

    {
        BatchNodeArray& nodes=arrA0;
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        void* growArg = h->m_heap;
        int need = nodes.size + savedN;
        if ((nodes.capacity & 0x3fffffff) < need) {
            int want = nodes.capacity & 0x3fffffff;
            want += want;
            if (need < want) need = want;
            hkArrayUtil__reserve(growArg, &nodes, need, 0x10);
        }
        nodes.size += savedN;
    }
    void* baseA0 = arrA0.data;
    int outArr[3];
    int endPointCount;
    for (int i = 0; i < 3; i++) {
        endPointCount=savedN+savedN;
        int twoN=endPointCount;
        sortSweepEndpoints(ptrs[i],twoN,EndpointOrder());
    }
    for (int i = 0; i < 3; i++) {
        SortArr15* sa = axes + i;
        outArr[i] = sa->InsertEndpoints(baseA0, i, ptrs[i], endPointCount);
    }
    axes[0].MergeSortedEndpoints(baseA0, outArr[0], b1.data, endPointCount);
    axes[1].MergeEndpointRangesBackward(baseA0, outArr[1], b2.data, endPointCount);
    axes[2].ProcessEntries_00d19ef0(baseA0, outArr[2], b3.data, endPointCount);
    if(m_iMarkerCount) {
        for(int i=0;i<m_iMarkerCount;++i) {
            SweepBatchNode& node=arrA0.data[m_pOverlappingMarkerInfo[i].node];
            node.maxY+=(unsigned short)(endPointCount);
            node.maxZ+=(unsigned short)(endPointCount);
        }
    }
    SweepBuffer<SweepBatchNode> sortedNew(savedN + 1);
     
    SweepBuffer<BatchSweepKey> newKeys(savedN + 4);
     
    SweepBuffer<BatchSweepKey> newScratch(savedN + 4);
     
    {
        unsigned short* b = (unsigned short*)newKeys.data;
        for (int i = 0; i < savedN; i++) {
            b[i * 2 + 1] = (unsigned short)(capA4 + i);
            b[i * 2] = arrA0.data[capA4+i].minX;
        }
        b[savedN * 2] = (unsigned short)0xffff;
        b[savedN * 2 + 2] = (unsigned short)0xffff;
        b[savedN * 2 + 4] = (unsigned short)0xffff;
    }
    hkRadixSort_sort16(newKeys.data, (savedN + 3) & 0xfffffffc, newScratch.data);
    for(int i=0;i<savedN;++i) sortedNew[i]=arrA0.data[newKeys[i].idx];
    ((SweepBatchNode*)sortedNew.data)[savedN].minX = (unsigned short)0xffff;
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((newScratch.capacity & (int)0x80000000) == 0) al->ReturnMemory( newScratch.data, (newScratch.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((newKeys.capacity & 0x80000000) == 0) al->ReturnMemory( newKeys.data, (newKeys.capacity & 0x3fffffff) * 4);
    }
    int cntC = local.size;
    SweepBuffer<SweepBatchNode> sortedOld(cntC + 1);
     
    SweepBuffer<BatchSweepKey> oldKeys(cntC + 4);
     
    SweepBuffer<BatchSweepKey> oldScratch(cntC + 4);
    SweepBatchNode* oldBase=arrA0.data;
     
    {
        unsigned short* b = (unsigned short*)oldKeys.data;
        for (int i = 0; i < cntC; i++) {
            SweepBatchNode* rec = ((SweepBatchNode**)local.data)[i];
            b[i * 2 + 1] = (unsigned short)(rec-oldBase);
            b[i * 2] = rec->minX;
        }
        b[cntC * 2] = (unsigned short)0xffff;
        b[cntC * 2 + 2] = (unsigned short)0xffff;
        b[cntC * 2 + 4] = (unsigned short)0xffff;
    }
    hkRadixSort_sort16(oldKeys.data, (cntC + 3) & 0xfffffffc, oldScratch.data);
    for(int i=0;i<cntC;++i) sortedOld[i]=arrA0.data[oldKeys[i].idx];
    ((SweepBatchNode*)sortedOld.data)[cntC].minX = (unsigned short)0xffff;
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((oldScratch.capacity & (int)0x80000000) == 0) al->ReturnMemory( oldScratch.data, (oldScratch.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((oldKeys.capacity & (int)0x80000000) == 0) al->ReturnMemory( oldKeys.data, (oldKeys.capacity & 0x3fffffff) * 4);
    }
    CollectNodePairs(this, sortedNew.data, savedN, p3);
    BuildBroadPhasePairs(sortedNew.data, savedN, sortedOld.data, cntC, 0, p3);
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((sortedOld.capacity & 0x80000000) == 0) al->ReturnMemory( sortedOld.data, (sortedOld.capacity & 0x3fffffff) * 16);
    }
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((sortedNew.capacity & 0x80000000) == 0) al->ReturnMemory( sortedNew.data, (sortedNew.capacity & 0x3fffffff) * 16);
    }
    local.clearAndFree();
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((b3.capacity & 0x80000000) == 0) al->ReturnMemory( b3.data, (b3.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((b2.capacity & 0x80000000) == 0) al->ReturnMemory( b2.data, (b2.capacity & 0x3fffffff) * 4);
    }
    {
        hkMemoryRouter* h = (&hkMemoryRouter::getInstance());
        BatchSweepAllocator* al = reinterpret_cast<BatchSweepAllocator*>(h->m_temp);
        if ((b1.capacity & 0x80000000) == 0) al->ReturnMemory( b1.data, (b1.capacity & 0x3fffffff) * 4);
    }
    return;
}
