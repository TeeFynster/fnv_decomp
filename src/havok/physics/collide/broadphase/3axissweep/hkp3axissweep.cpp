#include "../../../../../../include/hkArray.h"
#include <xmmintrin.h>

#include "../../../../../../include/hkVector4q.h"
#include "../../../../../../include/hkp3AxisSweep.h"
#include "../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/Pair.h"

// src/havok/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/broadphase/3axissweep/hkp3axissweep.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d11630
// src: HAVOK_LIB 0x00d11630
int hkp3AxisSweep::getAabbCacheSize()
{
    return 8 * (3 * (*(int*)((char*)this + 0xa4) - *(int*)((char*)this + 0xd0))) + 0x24;
}

// @fnv 0x00d19d70
unsigned short MaxUnsignedShort(unsigned short ausLeft, unsigned short ausRight)
{
    return ausLeft > ausRight ? ausLeft : ausRight;
}

BSAudio* __cdecl hkMemoryRouter_getInstance();

__forceinline hkMemoryRouter& hkMemoryRouter::getInstance() { return *(hkMemoryRouter*)hkMemoryRouter_getInstance(); }
template <typename T>
__forceinline T* hkMemoryAllocator::_bufAlloc(int& num) {
    int numBytes = num * (int)sizeof(T);
    void* p = bufAlloc(numBytes);
    num = numBytes / (int)sizeof(T);
    return (T*)p;
}
void __cdecl ResizeAudioStream(void*, void*, int);
struct UnkRet { int x; int y; };
// @fnv 0x00d11bc0
void __fastcall AppendPairToBuffer(UnkRet* apFirst, UnkRet* apSecond, void* apBuffer)
{
    BSAudio* p = hkMemoryRouter_getInstance();
    int* q = (int*)apBuffer;
    if (q[1] == (q[2] & 0x3fffffff))
        ResizeAudioStream(*(void**)((char*)p + 0x10), apBuffer, 8);
    int* e = (int*)((char*)q[0] + q[1] * 8);
    q[1] = q[1] + 1;
    e[0] = *(int*)((char*)apFirst + 0xc);
    e[1] = *(int*)((char*)apSecond + 0xc);
}

// @fnv 0x00d10ad0
void __fastcall ToggleBit(int aiBitIndex, void* apBits)
{
    int* p = (int*)apBits;
    int idx = aiBitIndex >> 5;
    int mask = 1 << (aiBitIndex & 0x1F);
    p[idx] ^= mask;
}

struct Entry {
    unsigned short key;
    unsigned short value;
};
// Binary-searches a sorted Entry range for the first entry whose key is not less than key, returning that entry pointer.
// @fnv 0x00d10ea0
Entry* __stdcall LowerBoundEntry(Entry* first, Entry* last, unsigned short key) {
    while ((((char*)last - (char*)first) & ~3) > 0x40) {
        Entry* middle = first + (((char*)last - (char*)first) >> 3);
        if (middle->key < key) first = middle;
        else last = middle;
    }
    while (first->key < key) ++first;
    return first;
}

struct FUN_00d11960_cls {
    int* m_pEntryData;
    int m_iArrayLength;
    void hkp3AxisSweep_hkpBpAxis_remove(int aiFirst, int aiSecond);
};

// @fnv 0x00d11960
// src: HAVOK_LIB 0x00d11960
void FUN_00d11960_cls::hkp3AxisSweep_hkpBpAxis_remove(int aiFirst, int aiSecond)
{
    int* p = m_pEntryData + aiFirst;
    int* pEnd = m_pEntryData + aiSecond - 1;
    while (p < pEnd) {
        p[0] = p[1];
        p++;
    }
    int iCount = m_iArrayLength;
    int* pLast = m_pEntryData + (iCount - 2);
    m_iArrayLength = iCount - 2;
    while (p < pLast) {
        p[0] = p[2];
        p++;
    }
}

namespace fnv_00d1a040 {
struct Entry { unsigned short type; unsigned short index; };
struct Container {
    Entry* entries;
    int count;
    int capacity;
    void hkp3AxisSweep_hkpBpAxis_removeBatch_0(int indexOffset, int** remap);
};
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
extern unsigned char* DAT_011b37a4[2];
// Remaps each entry's index through remap, drops entries with negative mapping, writes kept positions into DAT_011b37a4 tables, and grows capacity if needed.
// @fnv 0x00d1a040
// src: XBOX_PDB 0x00d1a040
void Container::hkp3AxisSweep_hkpBpAxis_removeBatch_0(int indexOffset, int** remap) {
    Entry* src = entries;
    Entry* end = src + count;
    int kept = 0;
    Entry* dst = src;
    while (src < end) {
        int mapped = (*remap)[src->index];
        if (mapped >= 0) {
            *dst = *src;
            dst->index = (unsigned short)mapped;
            *(unsigned short*)((char*)DAT_011b37a4[src->type & 1] + mapped * 16 + indexOffset) = (unsigned short)kept;
            ++dst;
            ++kept;
        }
        ++src;
    }
    BSAudio* audio = hkMemoryRouter_getInstance();
    void* mgr = ((void**)audio)[4];
    int capacity = this->capacity & 0x3fffffff;
    if (capacity < kept) {
        int newCapacity = capacity * 2;
        if (kept >= newCapacity)
            newCapacity = kept;
        hkArrayUtil__reserve(mgr, this, newCapacity, 4);
    }
    count = kept;
}
}  // namespace fnv_00d1a040

extern "C" hkMemoryRouter& __cdecl D1A0E0GetMemoryRouter();
void __cdecl hkArrayUtil__reserve(Allocator* alloc, void* array, int numElements, int sizeElem);

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

    void GrowArrayCapacity(Allocator& alloc, int n)
    {
        const int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, this, newSize, sizeof(D1A0E0Entry));
        }
    }

    void SetSizeAndGrow(Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }

    void hkp3AxisSweep_hkpBpAxis_removeBatch_1(int offset, const D1A0E0IntArray& remap);
};

// @fnv 0x00d1a0e0
// src: XBOX_PDB 0x00d1a0e0
void D1A0E0EntryArray::hkp3AxisSweep_hkpBpAxis_removeBatch_1(int offset, const D1A0E0IntArray& remap)
{
    D1A0E0Entry* end = m_data + m_iElementCount;
    int count = 0;
    D1A0E0Entry* dst = m_data;
    for (D1A0E0Entry* src = m_data; src < end; src++) {
        int newIndex = remap.m_data[src->m_uiEdgeIndex];
        if (newIndex >= 0) {
            *dst = *src;
            dst->m_uiEdgeIndex = (unsigned short)newIndex;
            *(unsigned short*)(g_D1A0E0Tables[src->m_flags & 1] + newIndex * 16 + offset) = (unsigned short)count;
            dst++;
            count++;
        }
    }
    SetSizeAndGrow(reinterpret_cast<Allocator&>(D1A0E0GetMemoryRouter().heap()), count);
}

struct S_00d1a180_ArrayUtil {
    static int __cdecl hkArrayUtil__reserve(Allocator& alloc, void* arr, int numElem, int elemSize);
};

extern int DAT_011b37b4[2];

struct S_00d1a180_HeapAllocator {
    static Allocator& get(const void*) { return reinterpret_cast<Allocator&>(hkMemoryRouter::getInstance().heap()); }
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

    void GrowArrayCapacity(Allocator& a, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            S_00d1a180_ArrayUtil::hkArrayUtil__reserve(a, this, newSize, sizeof(S_00d1a180_EndPoint));
        }
    }

    void _setSize(Allocator& a, int n)
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

// @fnv 0x00d1a180
void S_00d1a180_Axis::RemapEndPoints(char* nodes, const hkArrayBase<int>& remap)
{
    S_00d1a180_EndPoint* end = m_data + m_iElementCount;
    int n = 0;
    S_00d1a180_EndPoint* dst = m_data;
    for (S_00d1a180_EndPoint* src = m_data; src < end; src++) {
        int newIndex = remap.m_data[src->m_usIndex];
        if (newIndex >= 0) {
            *dst = *src;
            dst->m_usIndex = (unsigned short)newIndex;
            *(unsigned short*)(nodes + (newIndex * 16 + DAT_011b37b4[src->m_uiFilterValue & 1])) = (unsigned short)n;
            dst++;
            n++;
        }
    }
    SetSizeAndGrow(n);
}

// @fnv 0x00d10af0
// src: HAVOK_LIB 0x00d10af0
void __fastcall staticClearBit(int index, unsigned int* apuiBits)
{
    unsigned int mask = 1u << (index & 0x1f);
    unsigned int w = index >> 5;
    apuiBits[w] &= ~mask;
}

// @fnv 0x00d11620
// src: XBOX_PDB 0x00d11620
int hkp3AxisSweep::getNumObjects()
{
    return m_iA4 - 1;
}

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

// @fnv 0x00d119c0
// src: HAVOK_LIB 0x00d119c0
void hkp3AxisSweep::getAabb_00d119c0(UnkHandle* handle) {
    ::getAabbFromNode(this, handle, this->unkA0 + handle->unk00);
}

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

// Grows the pair array if full, then appends an entry holding self->m_0C and other->m_0C and increments the count.
// @fnv 0x00d11c10
void __fastcall AppendPairEntry(FUN_00d11c10_cls* pFirst, FUN_00d11c10_cls* pSecond, PairArray* arr) {
    hkMemoryRouter* holder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    if (arr->m_iArrayLength == (int)(arr->m_uCapFlags & 0x3fffffffu)) {
        ResizeAudioStream(holder->m_heap, arr, 8);
    }
    PairEntry* slot = arr->m_pData + arr->m_iArrayLength;
    arr->m_iArrayLength++;
    slot->m_pHeadNode = pFirst->m_0C;
    slot->m_iSecondInteger = pSecond->m_0C;
}

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

// @fnv 0x00d11c60
// src: HAVOK_LIB 0x00d11c60
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(void* base, FnvNode* pNode, unsigned short ausValue, FnvNode* pOther, FnvArr* pPairArr)
{
    if ((pOther->m_0c & 1) == 0) {
        FnvArr* arr = pPairArr;
        hkMemoryRouter* h = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
        if ((int)arr->m_uiItemCount == (int)(arr->m_cap & 0x3fffffff)) {
            ResizeAudioStream(h->m_heap, arr, 8);
        }
        unsigned int idx = (unsigned int)arr->m_uiItemCount;
        FnvPair8* e = (FnvPair8*)arr->m_data + idx;
        arr->m_uiItemCount = (int)(idx + 1);
        e->first = pNode->m_0c;
        e->second = pOther->m_0c;
    } else {
        FnvArr* arr = (FnvArr*)((char*)base + (pOther->m_0c & 0xfffffffe) + 4);
        hkMemoryRouter* h = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
        if ((int)arr->m_uiItemCount == (int)(arr->m_cap & 0x3fffffff)) {
            ResizeAudioStream(h->m_heap, arr, 2);
        }
        unsigned int idx = (unsigned int)arr->m_uiItemCount;
        unsigned short* e = (unsigned short*)arr->m_data + *(volatile int*)&arr->m_uiItemCount;
        *e = ausValue;
        arr->m_uiItemCount++;
    }
}

namespace fnv_00d11d00 {
unsigned short MaxUnsignedShort(unsigned short a, unsigned short b);

BSAudio* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*, void*, int);

void __fastcall AppendPairToBuffer(UnkRet* a, UnkRet* b, void* c);

struct PairEntry {
    int m_00;
    int m_04;
};

struct PairArray {
    PairEntry* m_00;
    int m_04;
    unsigned int m_08;
};

struct TagOwner {
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0c;
};

struct TagEntity {
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
};

struct TaggedList {
    int unk00;
    unsigned short* m_04;
    int m_08;
};

// @fnv 0x00d11d00
void __fastcall RemoveOrAppendTagEntry(char* base, TagEntity* entity, unsigned int idx, TagOwner* owner, PairArray* arr)
{
    if ((owner->m_0c & 1) == 0) {
        hkMemoryRouter* holder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
        if (arr->m_04 == (int)(arr->m_08 & 0x3fffffff)) {
            fnv_00d11d00::ResizeAudioStream(holder->m_heap, arr, 8);
        }
        int n = arr->m_04;
        PairEntry* e = arr->m_00 + n;
        arr->m_04 = n + 1;
        e->m_00 = entity->m_0c;
        e->m_04 = owner->m_0c;
    } else {
        TaggedList* list = reinterpret_cast<TaggedList*>(base + (owner->m_0c & 0xfffffffe));
        int count = list->m_08;
        int index = 0;
        if (count > 0) {
            do {
                if (list->m_04[index] == (unsigned short)idx) {
                    goto found;
                }
                ++index;
            } while (index < count);
        }
        index = -1;
found:
        volatile int* cnt = &list->m_08;
        (*cnt)--;
        int last = list->m_08;
        if (last != index) {
            list->m_04[index] = list->m_04[last];
        }
    }
}
}  // namespace fnv_00d11d00

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

// @fnv 0x00d11da0
void FUN_00d11da0_cls::InsertPair(unsigned int auiUnused, unsigned int auiValue, unsigned short ausKey2,
                                    unsigned short ausKey1, unsigned short* pausIndex2, unsigned short* pausIndex1)
{
    int n = m_uiItemCount + 2;
    hkMemoryRouter* holder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    void* allocator = holder->m_heap;
    unsigned int cap = m_capFlags & 0x3fffffffu;

    if ((int)cap < n) {
        int newCap = (int)(cap + cap);
        if (n >= newCap) {
            newCap = n;
        }
        hkArrayUtil__reserve(allocator, this, (unsigned int)newCap, 4);
    }

    FUN_00d11da0_entry* p = m_data + (n - 3);
    m_uiItemCount = n;
    p[2] = p[0];
    p--;
    while (ausKey1 < p->key) {
        p[2] = p[0];
        p--;
    }
    while (ausKey1 == p->key && auiValue < p->value) {
        p[2] = p[0];
        p--;
    }
    p[2].key = ausKey1;
    p[2].value = (unsigned short)auiValue;
    *pausIndex1 = (unsigned short)((p - m_data) + 2);

    FUN_00d11da0_entry* q = p;
    while (ausKey2 < q->key) {
        q[1] = q[0];
        q--;
    }
    while (ausKey2 == q->key && auiValue < q->value) {
        q[1] = q[0];
        q--;
    }
    q[1].value = (unsigned short)auiValue;
    q[1].key = ausKey2;
    *pausIndex2 = (unsigned short)((q - m_data) + 1);
    (void)auiUnused;
}

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
// @fnv 0x00d138a0
void __cdecl CollectNodePairs(int unused, S_00d138a0_Node* node, int count, S_00d138a0_Array* out)
{
    for (--count; count > 0; --count) {
        unsigned int limit = node->unk0a;
        S_00d138a0_Node* cur = node + 1;
        for (; cur->unk08 < limit; cur++) {
            if (((cur->unk04 - node->unk00) | (node->unk04 - cur->unk00)) & 0x80008000) {
            } else if (!(cur->unk0c & 1)) {
                hkMemoryRouter* heap = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
                if (out->unk04 == (int)(out->unk08 & 0x3fffffff))
                    ResizeAudioStream(heap->m_heap, out, 8);
                S_00d138a0_Pair* e = &out->unk00[out->unk04++];
                e->unk00 = node->unk0c;
                e->unk04 = cur->unk0c;
            }
        }
        node = node + 1;
    }
}

struct SpawnedObject {
    int unk00;
    unsigned short m_wSize;

    SpawnedObject* Init(int a, int b, int c);
};

// Allocates a 0xe0-byte SpawnedObject from the holder's allocator, sets its size, and initializes it with the three arguments.
// @fnv 0x00d182a0
// src: XBOX_PDB 0x00d182a0
SpawnedObject* hk3AxisSweep16CreateBroadPhase(int a, int b, int c)
{
    hkMemoryRouter* holder = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    SpawnedObject* obj = reinterpret_cast<SpawnedObject*>(reinterpret_cast<hkMemoryAllocator*>(holder->m_heap)->blockAlloc(0xe0));
    obj->m_wSize = 0xe0;
    return obj->Init(a, b, c);
}

// Writes the smallest of v[0], v[1], v[2] to out and returns its index (0, 1 or 2).
// @fnv 0x00d19d10
// src: HAVOK_LIB 0x00d19d10
int __cdecl getMinComponent(const float* afValues, float* pfMin) {
    if (afValues[0] < afValues[1]) {
        if (afValues[0] < afValues[2]) {
            *pfMin = afValues[0];
            return 0;
        }
    } else if (afValues[1] < afValues[2]) {
        *pfMin = afValues[1];
        return 1;
    }
    *pfMin = afValues[2];
    return 2;
}

extern int DAT_011b37a4[];

struct Endpoint {
    unsigned short value;
    unsigned short handle;
};

struct S_00d19d90_Class {
    Endpoint* m_endpoints;
    void MergeSortedEndpoints(void* pLookup, int totalCount, Endpoint* pSrc2, int count2);
};

// Merges two sorted Endpoint ranges into m_endpoints from the back, writing each endpoint's output index into pLookup at a handle-derived offset.
// @fnv 0x00d19d90
void S_00d19d90_Class::MergeSortedEndpoints(void* pLookupTable, int iDestCount, Endpoint* pSrcEndpoints, int iSrcCount)
{
    Endpoint* pSrcCursor = &pSrcEndpoints[iSrcCount - 1];
    Endpoint* pDestEndpoints = m_endpoints;
    int iOutIndex = iDestCount;
    int c = iOutIndex - iSrcCount;
    Endpoint* pDestCursor = &pDestEndpoints[c - 1];
    iSrcCount = pDestCursor->value;
    iOutIndex--;
    iDestCount = pSrcCursor->value;
    Endpoint* pOut = &pDestEndpoints[iOutIndex];
    while (true)
    {
        if (iSrcCount > iDestCount)
        {
            *pOut = *pDestCursor;
            unsigned int offset = (pDestCursor->handle << 4) + DAT_011b37a4[pDestCursor->value & 1];
            *(unsigned short*)((char*)pLookupTable + offset) = (unsigned short)iOutIndex;
            pDestCursor--;
            pOut--;
            iOutIndex--;
            iSrcCount = pDestCursor->value;
        }
        else
        {
            *pOut = *pSrcCursor;
            unsigned int offset = (pSrcCursor->handle << 4) + DAT_011b37a4[pSrcCursor->value & 1];
            *(unsigned short*)((char*)pLookupTable + offset) = (unsigned short)iOutIndex;
            pSrcCursor--;
            pOut--;
            iDestCount = pSrcCursor->value;
            iOutIndex--;
            if (pSrcCursor < pSrcEndpoints)
                break;
        }
    }
}

// hkp3AxisSweep endpoint (Havok hkpBpEndPoint: 16-bit value, 16-bit node index; 4 bytes)
struct BpEndPoint {
    unsigned short key;
    unsigned short hi;
};

struct FUN_00d19ef0_cls {
    BpEndPoint* m_pItems;
    void ProcessEntries_00d19ef0(char* out, int n, BpEndPoint* src, int k);
};

// @fnv 0x00d19ef0
// src: GUESS 0x00d19ef0 (confidence: low)
void FUN_00d19ef0_cls::ProcessEntries_00d19ef0(char* out, int iCount, BpEndPoint* src, int iSplit) {
    int cnt = iCount - iSplit;
    BpEndPoint* pRight = &src[iSplit - 1];
    BpEndPoint* base = m_pItems;
    BpEndPoint* pLeft = &base[cnt - 1];
    int iLeftKey = pLeft->key;
    int s2 = pRight->key;
    --iCount;
    int idx = iCount;
    BpEndPoint* pWrite = &base[idx];
    for (;;) {
        if (iLeftKey > s2) {
            *pWrite = *pLeft;
            unsigned int off = ((unsigned int)pLeft->hi << 4) + DAT_011b37b4[pLeft->key & 1];
            *(unsigned short*)(out + off) = (unsigned short)idx;
            --pLeft;
            --pWrite;
            --idx;
            iLeftKey = pLeft->key;
        } else {
            *pWrite = *pRight;
            unsigned int off = ((unsigned int)pRight->hi << 4) + DAT_011b37b4[pRight->key & 1];
            *(unsigned short*)(out + off) = (unsigned short)idx;
            --pRight;
            --pWrite;
            --idx;
            s2 = pRight->key;
            if (pRight < src) {
                break;
            }
        }
    }
}

// Recursive quicksort partition over 4-byte records keyed by (low16, high16) lexicographically.
// @fnv 0x00d19fa0
// src: HAVOK_LIB 0x00d19fa0
void __cdecl hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(unsigned int* auiValues, int lo, int hi, int auiUnused)
{
    for (;;) {
        int i = lo;
        int j = hi;
        __declspec(align(16)) struct PivotSlot { unsigned int v; } pivot;
        pivot.v = auiValues[(i + j) >> 1];

        for (;;) {
            while ((unsigned short)auiValues[i] < (unsigned short)pivot.v
                || ((unsigned short)auiValues[i] == (unsigned short)pivot.v
                    && ((unsigned short*)&auiValues[i])[1] < (unsigned short)(pivot.v >> 16))) {
                ++i;
            }
            while ((unsigned short)pivot.v < (unsigned short)auiValues[j]
                || ((unsigned short)pivot.v == (unsigned short)auiValues[j]
                    && *(volatile unsigned short*)((char*)&pivot.v + 2) < ((unsigned short*)&auiValues[j])[1])) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                unsigned int a = auiValues[i];
                unsigned int b = auiValues[j];
                auiValues[j] = a;
                auiValues[i] = b;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            hkAlgorithm_quickSortRecursive_class_hkp3AxisSweep_hkpBpEndPoint_class_hkAlgorithm_less_class_hkp3AxisSweep_hkpBpEndPoint(auiValues, lo, j, auiUnused);
        }
        if (i >= hi) {
            return;
        }
        lo = i;
    }
}

// Recursive quicksort partition over 4-byte records keyed by their low 16 bits.
// @fnv 0x00d1a220
void __cdecl QuickSortByLowWord(unsigned int* auiArray, int lo, int hi, int auiUnused)
{
    for (;;) {
        int j = hi;
        int i = lo;
        unsigned int pivot = auiArray[(i + j) >> 1];

        for (;;) {
            while ((unsigned short)auiArray[i] < (unsigned short)pivot) {
                ++i;
            }
            while ((unsigned short)pivot < (unsigned short)auiArray[j]) {
                --j;
            }
            if (j < i) {
                break;
            }
            if (j != i) {
                __declspec(align(16)) unsigned int uiLeftValue = auiArray[i];
                unsigned int uiRightValue = auiArray[j];
                auiArray[j] = uiLeftValue;
                auiArray[i] = uiRightValue;
            }
            --j;
            ++i;
            if (i > j) {
                break;
            }
        }

        if (lo < j) {
            QuickSortByLowWord(auiArray, lo, j, auiUnused);
        }
        if (i >= hi) {
            return;
        }
        lo = i;
    }
}

// @fnv 0x00d10b10
// src: HAVOK_LIB 0x00d10b10
static int __declspec(noinline) staticIsBitSet(void* self, int index, unsigned int* apuiBits)
{
    unsigned int mask = 1u << (index & 31);
    return (int)(mask & apuiBits[index >> 5]);
}

int IsBitmapBitSet(void* table, int index, unsigned int* bits)
{
    return staticIsBitSet(table, index, bits);
}

extern int DAT_011b37a4[];

class FUN_00d11120_cls {
public:
    Endpoint* m_endpoints;
    void MergeEndpoints(char* cells, int n, int m,
                      unsigned int axis, Endpoint* scratch);
};

// @fnv 0x00d11120
void FUN_00d11120_cls::MergeEndpoints(char* cells, int aiCount, int aiExtraCount,
                                    unsigned int axis, Endpoint* scratch)
{
    for (int i = 0; i < aiCount; i++) {
        scratch[i] = m_endpoints[i];
    }

    Endpoint* last = scratch + 1;
    Endpoint* b = m_endpoints + aiCount;
    Endpoint* w = m_endpoints + 1;
    Endpoint* a = scratch + aiCount - 1;
    aiCount += aiExtraCount;
    Endpoint* pRightEnd = m_endpoints + aiCount;

    while (last->value < b->value) {
        last++;
        w++;
    }

    if (last < a && b < pRightEnd) {
        for (;;) {
            if (last->value < b->value || (last->value == b->value && last->handle < b->handle)) {
                *w = *last;
                unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
                *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
                last++;
                w++;
                if (last >= a) {
                    break;
                }
            } else {
                *w = *b;
                unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
                *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
                b++;
                w++;
                if (b >= pRightEnd) {
                    break;
                }
            }
        }
    }
    while (b < pRightEnd) {
        *w = *b;
        unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
        *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
        b++;
        w++;
    }
    while (last <= a) {
        *w = *last;
        unsigned int slot = (w->handle << 4) + DAT_011b37a4[(w->value & 1) + 2 * axis];
        *(unsigned short*)(cells + slot) = (unsigned short)(w - m_endpoints);
        last++;
        w++;
    }
}

// Adapted from an unverified prior attempt by another contributor; original author/model unknown.

typedef hkp3AxisSweep::Node SweepEdgeNode;
typedef unsigned short SweepEdgeNode::* S_d11790_Field;

static __forceinline void S_d11790_Fix(hkp3AxisSweep::Node* nodes, hkp3AxisSweep::EndPoint* edges, hkp3AxisSweep::Node* node, S_d11790_Field field, unsigned h)
{
    unsigned i = node->*field;
    hkp3AxisSweep::EndPoint* e = edges + i;
    while (e[0].m_uiFilterValue == e[-1].m_uiFilterValue) {
        unsigned p = e[-1].m_usIndex;
        if (!(h < p)) break;
        e[0] = e[-1];
        --e;
        nodes[p].*field = i;
        --i;
    }
    e->m_usIndex = h;
    unsigned short* currentField = &(node->*field);

    *currentField = i;
}

// Runs S_d11790_Fix on node h for six node fields across the three edge axes.
// @fnv 0x00d11790
void hkp3AxisSweep::FixNodeEdges(unsigned auiNodeIndex)
{
    hkp3AxisSweep::Node* nd = nodes;
    hkp3AxisSweep::Node* n = &nd[auiNodeIndex];
    S_d11790_Fix(nd, axis0, n, &SweepEdgeNode::m_usValue08, auiNodeIndex);
    S_d11790_Fix(nd, axis0, n, &SweepEdgeNode::m_usValue0A, auiNodeIndex);
    S_d11790_Fix(nd, axis1, n, &SweepEdgeNode::m_usValue00, auiNodeIndex);
    S_d11790_Fix(nd, axis1, n, &SweepEdgeNode::m_usValue04, auiNodeIndex);
    S_d11790_Fix(nd, axis2, n, &SweepEdgeNode::m_usValue02, auiNodeIndex);
    S_d11790_Fix(nd, axis2, n, &SweepEdgeNode::m_usValue06, auiNodeIndex);
}

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

template <typename Array>
__forceinline void addArray(hkStatisticsCollector* collector, const char* name, const Array& arr)
{
    if ((arr.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations) {
        void* data = arr.m_data;
        int capacity = arr.m_iCapacityState & 0x3fffffff;
        int allocated = hkStatisticsCollector_getAllocatedSize(data, capacity * sizeof(*arr.m_data));
        collector->AddMemoryChunk(3, name, arr.m_data, arr.m_iElementCount * sizeof(*arr.m_data), allocated);
    }
}

// Reports the sizes of the node, axis and marker arrays to the statistics collector, including each marker's overlapping markers.
// @fnv 0x00d119e0
void hkp3AxisSweep::calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const
{
    addArray(collector, "Nodes", m_kNodeCollection);
    addArray(collector, "Axis", m_axis0);
    addArray(collector, "Axis", m_axis1);
    addArray(collector, "Axis", m_axis2);

    if (m_iMarkerCount != 0) {
        collector->DispatchWithMode("Markers", m_pOverlappingMarkerInfo, m_iMarkerCount * sizeof(OverlappingMarkerInfo), 0);
    }

    for (int i = 0; i < m_iMarkerCount; ++i) {
        addArray(collector, "Markers", m_pOverlappingMarkerInfo[i].m_overlappingMarkers);
    }
}

BSAudio* __cdecl hkMemoryRouter_getInstance() throw();
void __cdecl hkMemoryRouter_easyFree(void*, void*) throw();

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc) {
    int cap = m_iCapacityState;
    m_iElementCount = 0;
    if (!(cap & 0x80000000)) {
        alloc.bufFree(m_data, (cap & 0x3fffffff) * sizeof(T));
    }
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

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

// Frees each sub-node's array, the sub-node block, the three endpoint arrays and the node array through the router's allocator.
// @fnv 0x00d182e0
hkp3AxisSweep::~hkp3AxisSweep() throw() {
    for (int i = 0; i < m_numSubNodes; ++i) {
        hkArray<unsigned short>* arr = &reinterpret_cast<SubNode_00d182e0*>(unkD8)[i].m_ppData;
        arr->_clearAndDeallocate(*reinterpret_cast<hkMemoryAllocator*>((&hkMemoryRouter::getInstance())->m_heap));
    }
    SubNode_00d182e0* subNodes = reinterpret_cast<SubNode_00d182e0*>(unkD8);
    hkMemoryRouter_easyFree(reinterpret_cast<hkMemoryAllocator*>((&hkMemoryRouter::getInstance())->m_heap), subNodes);

    hkArray<EndPoint_00d182e0>* axis = reinterpret_cast<hkArray<EndPoint_00d182e0>*>(&m_kAxisEndPoints[3]);
    for (int i = 2; i >= 0; --i) {
        --axis;
        axis->_clearAndDeallocate(*reinterpret_cast<hkMemoryAllocator*>((&hkMemoryRouter::getInstance())->m_heap));
    }
    reinterpret_cast<hkArray<Node_00d182e0>&>(m_kNodeCollection)._clearAndDeallocate(*reinterpret_cast<hkMemoryAllocator*>((&hkMemoryRouter::getInstance())->m_heap));
}

// Returns 0.
// @fnv 0x00d10ac0
// src: COMMUNITY 0x00d10ac0
int __cdecl hkp3AxisSweep_getType() {
    return 0;
}

// Empty function that does nothing and returns immediately.
// @fnv 0x00d10ff0
// src: COMMUNITY 0x00d10ff0
void __cdecl nullsub_73() {
}

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

// Sweeps two sorted node arrays, emitting overlapping pairs into pairs or adding/removing ids in per-node SmallArrays depending on mode.
// @fnv 0x00d13620
void hkp3AxisSweep::BuildBroadPhasePairs(Node* nodesA, int numNodesA, Node* nodesB, int numNodesB, int mode, BroadPhasePairArray& pairs)
{
    char* idx = (char*)unkD8;
    while (true) {
        if (nodesA->m_usValue08 > nodesB->m_usValue08) {
            unsigned int target = nodesB->m_usValue0A;
            Node* curB = nodesA;
            while (curB->m_usValue08 < target) {
                if (!(((*reinterpret_cast<int*>(&nodesB->m_usValue04) - *reinterpret_cast<int*>(&curB->m_usValue00)) | (*reinterpret_cast<int*>(&curB->m_usValue04) - *reinterpret_cast<int*>(&nodesB->m_usValue00))) & 0x80008000)) {
                    if (nodesB->unk0C & 1) {
                        if (mode != 1) {
                            unsigned int id = *(unsigned int*)curB->unk0C;
                            TargetStruct* m = (TargetStruct*)(idx + (nodesB->unk0C & ~1));
                            if (mode == 0) {
                                m->m_ppData.AddBack(id);
                            } else {
                                m->m_ppData.removeAt(m->m_ppData.indexOf(id));
                            }
                        }
                    } else {
                        S_00d138a0_Pair& pair = pairs.AllocatePair();
                        pair.unk00 = curB->unk0C;
                        pair.unk04 = nodesB->unk0C;
                    }
                }
                curB++;
            }
            nodesB++;
            if (--numNodesB <= 0) break;
        } else {
            unsigned int target = nodesA->m_usValue0A;
            Node* curA = nodesB;
            while (curA->m_usValue08 < target) {
                if (!(((*reinterpret_cast<int*>(&nodesA->m_usValue04) - *reinterpret_cast<int*>(&curA->m_usValue00)) | (*reinterpret_cast<int*>(&curA->m_usValue04) - *reinterpret_cast<int*>(&nodesA->m_usValue00))) & 0x80008000)) {
                    if (curA->unk0C & 1) {
                        if (mode != 1) {
                            unsigned int id = *(unsigned int*)nodesA->unk0C;
                            TargetStruct* m = (TargetStruct*)(idx + (curA->unk0C & ~1));
                            if (mode == 0) {
                                m->m_ppData.AddBack(id);
                            } else {
                                m->m_ppData.removeAt(m->m_ppData.indexOf(id));
                            }
                        }
                    } else {
                        S_00d138a0_Pair& pair = pairs.AllocatePair();
                        pair.unk00 = nodesA->unk0C;
                        pair.unk04 = curA->unk0C;
                    }
                }
                curA++;
            }
            nodesA++;
            if (--numNodesA <= 0) break;
        }
    }
}

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

// The caller reserves space before appending overlap pairs.
static __forceinline void AppendN(PairVec* out, Record* other, Record* rec, int n)
{
    for (int k = 0; k < n; ++k) {
        Pair* p = &out->m_00[out->m_04];
        out->m_04++;
        p->a = other->m_0c;
        p->b = rec->m_0c;
    }
}
static __forceinline void HandlePair(hkp3AxisSweep* idx, Record* rec, Record* other, PairVec* out, char flag)
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
    int fidx = (int)((char*)first - (char*)reinterpret_cast<Record*>(idx->unkA0)) >> 4;
    ObjX* obj = (ObjX*)((second->m_0c & 0xfffffffe) + (int)idx->m_markerBase);
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

// @fnv 0x00d14a60
// src: HAVOK_LIB 0x00d14a60
void hkp3AxisSweep::queryBatchAabbSub(unsigned int* bits, PairVec* out, char flag)
{
    LocalVec sv1;
    LocalVec sv2;
    sv2.m_00 = sv2.m_0c;
    sv2.m_08 = (int)0x80000100;
    sv2.m_04 = 0;
    sv1.m_00 = sv1.m_0c;
    sv1.m_08 = (int)0x80000100;
    sv1.m_04 = 0;
    hkp3AxisSweep* idx = this;
    EntryLocal* end = (EntryLocal*)idx->axis0 + idx->unkB0 - 1;
    EntryLocal* cur = (EntryLocal*)idx->axis0 + 1;
    if ((unsigned int)cur < (unsigned int)end) {
        do {
            int val = cur->m_02;
            int y = (1 << (val & 0x1f)) & (int)bits[val >> 5];
            if ((cur->m_00 & 1) != 0) {
                ShortVec* v = y != 0 ? (ShortVec*)&sv2 : (ShortVec*)&sv1;
                int n = v->m_04;
                int self = FindIdx(v->m_00, n, (unsigned short)val);
                int last = n - 1;
                v->m_04 = last;
                if (last != self)
                    v->m_00[self] = v->m_00[last];
            } else {
                Record* rec = &reinterpret_cast<Record*>(idx->unkA0)[val];
                for (int i = 0; i < sv2.m_04; i++) {
                    Record* other = &reinterpret_cast<Record*>(idx->unkA0)[sv2.m_00[i].v];
                    int d1 = rec->m_04 - other->m_00;
                    int d0 = other->m_04 - rec->m_00;
                    if (((d0 | d1) & (int)0x80008000) != 0) continue;
                    HandlePair(idx, rec, other, out, flag);
                }
                if (y != 0) {
                    for (int i = 0; i < sv1.m_04; i++) {
                        Record* other = &reinterpret_cast<Record*>(idx->unkA0)[sv1.m_00[i].v];
                        int d0 = other->m_04 - rec->m_00;
                        int d1 = rec->m_04 - other->m_00;
                        if (((d0 | d1) & (int)0x80008000) != 0) continue;
                        HandlePair(idx, rec, other, out, flag);
                    }
                    PushShort((ShortVec*)&sv2, (unsigned short)val);
                } else {
                    PushShort((ShortVec*)&sv1, (unsigned short)val);
                }
            }
            cur++;
        } while ((unsigned int)cur < (unsigned int)end);
    }
    FreeLocalVec(sv1);
    FreeLocalVec(sv2);
}

#include <xmmintrin.h>
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c7170;
extern float DAT_010cd5b0;

// XORs m_negSrc with DAT_010c44d0 into out0, computes a Newton-refined reciprocal of m_recipSrc, scales it by DAT_010cd5b0, and adds out0 into out1.
// @fnv 0x00d10e10
// src: XBOX_PDB 0x00d10e10
void hkp3AxisSweep::getExtents(__m128* out0, __m128* out1) {
    __m128 negated = _mm_xor_ps(m_negSrc, DAT_010c44d0);
    *out0 = negated;

    __m128 v = m_recipSrc;
    __m128 hi = _mm_unpackhi_ps(v, DAT_010c7170);
    __m128 x = _mm_shuffle_ps(v, hi, 0xc4);

    __m128 r = _mm_rcp_ps(x);
    __m128 rxr = _mm_mul_ps(_mm_mul_ps(r, x), r);
    __m128 refined = _mm_sub_ps(_mm_add_ps(r, r), rxr);
    *out1 = refined;

    __m128 scale = _mm_set1_ps(DAT_010cd5b0);
    __m128 scaled = _mm_mul_ps(scale, refined);
    *out1 = scaled;
    *out1 = _mm_add_ps(*out0, scaled);
}

// @fnv 0x00d10e80
// src: GUESS 0x00d10e80 (confidence: high)
void __cdecl Object_DoNothing_00d10e80()
{
}

struct S00d11470_Entry {
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
};

// Takes the 16-byte records at unkA0 indexed by *first and *second and returns true if none of their field cross-differences has a sign bit set.
// @fnv 0x00d11470
// src: HAVOK_LIB 0x00d11470
bool __thiscall hkp3AxisSweep::areAabbsOverlapping(int* first, int* second)
{
    hkp3AxisSweep* object = this;

    S00d11470_Entry* entrySecond =
        reinterpret_cast<S00d11470_Entry*>(reinterpret_cast<char*>(object->unkA0) + *first * 16);
    S00d11470_Entry* entryFirst =
        reinterpret_cast<S00d11470_Entry*>(reinterpret_cast<char*>(object->unkA0) + *second * 16);

    unsigned short difference = static_cast<unsigned short>(
        entrySecond->unk0A - entryFirst->unk08);
    difference = static_cast<unsigned short>(
        difference | (entryFirst->unk0A - entrySecond->unk08));
    difference = static_cast<unsigned short>(
        difference | (entrySecond->unk04 - entryFirst->unk00));
    difference = static_cast<unsigned short>(
        difference | (entryFirst->unk04 - entrySecond->unk00));

    int differenceFirst = entrySecond->unk04 - entryFirst->unk00;
    int differenceSecond = entryFirst->unk04 - entrySecond->unk00;

    if (!(difference & 0x8000) && !((differenceFirst | differenceSecond) & 0x80008000))
        return true;
    return false;
}

void __cdecl hkArrayUtil__reserve(void* alloc, void* self, int newCap, int elemSize);

struct FUN_00d11e80_cls { // distinct from hkArrayBase: own endpoint insertion 0x00d11e80 also updates axis/node indices.
    S_00d1a180_EndPoint* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int InsertEndpoints(char* nodes, int axis, S_00d1a180_EndPoint* newEndpoints, int numNew);
};

// Grows the endpoint array if needed, shifts existing endpoints to make room for numNew new entries, and returns the insertion index.
// @fnv 0x00d11e80
int FUN_00d11e80_cls::InsertEndpoints(char* nodes, int axis, S_00d1a180_EndPoint* newEndpoints, int numNew) {
    int oldCount = m_iElementCount;
    int newCount = oldCount + numNew;

    char* r = (char*)hkMemoryRouter_getInstance();
    void* alloc = *(void**)(r + 0x10);
    int cap = m_iCapacityState & 0x3fffffff;
    if (cap < newCount) {
        cap = (newCount < 2 * cap) ? 2 * cap : newCount;
        hkArrayUtil__reserve(alloc, this, cap, 4);
    }

    m_iElementCount = newCount;

    unsigned int ins = newEndpoints[numNew - 1].m_uiFilterValue;
    S_00d1a180_EndPoint* dst = m_data + newCount - 1;
    S_00d1a180_EndPoint* src = m_data + oldCount - 1;
    _mm_prefetch((const char*)dst, _MM_HINT_NTA);
    _mm_prefetch((const char*)(dst - 128), _MM_HINT_NTA);
    _mm_prefetch((const char*)src, _MM_HINT_NTA);
    _mm_prefetch((const char*)(dst - 128), _MM_HINT_NTA);

    *dst = *src;
    int axis2 = axis * 2;
    *(unsigned short*)(nodes + DAT_011b37a4[(src->m_uiFilterValue & 1) + axis2] + (src->m_usIndex << 4)) = (unsigned short)(dst - m_data);
    src--;
    dst--;

    while (src->m_uiFilterValue > (unsigned short)ins) {
        *dst = *src;
        _mm_prefetch((const char*)(src - 128), _MM_HINT_NTA);
        *(unsigned short*)(nodes + DAT_011b37a4[(src->m_uiFilterValue & 1) + axis2] + (src->m_usIndex << 4)) = (unsigned short)(dst - m_data);
        _mm_prefetch((const char*)(src - 128), _MM_HINT_NTA);
        src--;
        dst--;
    }

    return (dst - m_data) + 1;
}

extern "C" void _ReadWriteBarrier(void);
typedef hkArrayBase<char> d11Out;
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

// @fnv 0x00d11fa0
void hkp3AxisSweep::GetAllAabbs(hkArray<hkAabb>& output) const
{
    d11Out& out = reinterpret_cast<d11Out&>(output);
    d11Out* pOut = &out;
    int iCount = m_iArrayLength - m_iBase;
    d11Heap* m_pPoolBase = (d11Heap*)hkMemoryRouter_getInstance();
    if ((pOut->m_iCapacityState & 0x3fffffff) < iCount)
        hkArrayUtil__reserve((Allocator*)m_pPoolBase->m_pAllocator, pOut, iCount, 0x20);
    int n = m_iArrayLength - m_iBase;
    _ReadWriteBarrier();
    pOut->m_iElementCount = n;
    int iPairIndex = 0;
    for (int i = 0; i < m_iArrayLength; i++) {
        d11Node* node = &reinterpret_cast<d11Node*>(unkA0)[i];
        _ReadWriteBarrier();
        if (!(node->m_flags & 1))
            ((void (__thiscall*)(const hkp3AxisSweep*, d11Node*, d11Pair*))::getAabbFromNode)(this, node, &((d11Pair*)pOut->m_data)[iPairIndex++]);
    }
}

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

template <class T>
static __forceinline void SweepArray_pushBackUnchecked(hkArrayBase<T>& self, const T& t);

template <class T>
static __forceinline void SweepArray_pushBackUnchecked(hkArrayBase<T>& self, const T& t)
{
        S00d13950_constructWithCopy<T>(self.m_data + self.m_iElementCount, 1, t);
        self.m_iElementCount++;
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

// Fills three hkArrayBase<SweepEndpoint> buffers with min/max endpoints from each SweepNode, sorts each axis, and adds sentinel endpoints.
// @fnv 0x00d13950
// src: HAVOK_LIB 0x00d13950
void hkp3AxisSweep::calcAabbCacheInternal(Blk* input, unsigned int output)
{
    const hkArrayBase<SweepNode*>& nodes = *reinterpret_cast<const hkArrayBase<SweepNode*>*>(input);
    hkArrayBase<SweepEndpoint>* tempAxes = reinterpret_cast<hkArrayBase<SweepEndpoint>*>(output);
    SweepEndpoint* buf = (SweepEndpoint*)(tempAxes + 3);
    int cap = 2 * nodes.m_iElementCount + 2;
    new (&tempAxes[0]) hkArrayBase<SweepEndpoint>(buf, 0, cap);
    new (&tempAxes[1]) hkArrayBase<SweepEndpoint>(buf + cap, 0, cap);
    new (&tempAxes[2]) hkArrayBase<SweepEndpoint>(buf + cap * 2, 0, cap);

    SweepEndpoint sentinel;
    sentinel.m_uiFilterValue = 0;
    sentinel.m_usIndex = 0;
    SweepArray_pushBackUnchecked(tempAxes[0], sentinel);
    SweepArray_pushBackUnchecked(tempAxes[1], sentinel);
    SweepArray_pushBackUnchecked(tempAxes[2], sentinel);

    SweepNode* const* nodeIt = nodes.m_data;
    for (int i = nodes.m_iElementCount - 1; i >= 0; --i) {
        SweepArray_pushBackUnchecked(tempAxes[0], reinterpret_cast<hkArrayBase<SweepEndpoint>*>(m_kAxisEndPoints)[0].m_data[(*nodeIt)->m_min0]);
        SweepArray_pushBackUnchecked(tempAxes[0], reinterpret_cast<hkArrayBase<SweepEndpoint>*>(m_kAxisEndPoints)[0].m_data[(*nodeIt)->m_max0]);
        SweepArray_pushBackUnchecked(tempAxes[1], reinterpret_cast<hkArrayBase<SweepEndpoint>*>(m_kAxisEndPoints)[1].m_data[(*nodeIt)->m_min1]);
        SweepArray_pushBackUnchecked(tempAxes[1], reinterpret_cast<hkArrayBase<SweepEndpoint>*>(m_kAxisEndPoints)[1].m_data[(*nodeIt)->m_max1]);
        SweepArray_pushBackUnchecked(tempAxes[2], reinterpret_cast<hkArrayBase<SweepEndpoint>*>(m_kAxisEndPoints)[2].m_data[(*nodeIt)->m_min2]);
        SweepArray_pushBackUnchecked(tempAxes[2], reinterpret_cast<hkArrayBase<SweepEndpoint>*>(m_kAxisEndPoints)[2].m_data[(*nodeIt)->m_max2]);
        nodeIt++;
    }

    for (int j = 0; j < 3; ++j) {
        S00d13950_quickSort(tempAxes[j].m_data + 1, tempAxes[j].m_iElementCount - 1, S00d13950_Less());
    }

    sentinel.m_uiFilterValue = 0xfffc;
    sentinel.m_usIndex = 0;
    SweepArray_pushBackUnchecked(tempAxes[0], sentinel);
    SweepArray_pushBackUnchecked(tempAxes[1], sentinel);
    SweepArray_pushBackUnchecked(tempAxes[2], sentinel);
}

namespace fnv_00d13bd0 {
inline void* operator new(unsigned int, void* p) { return p; }
struct SweepBase {
    const void** vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    SweepBase() throw();
};

struct SweepRouter {
    int unk00, unk04, unk08, unk0c;
    Allocator* heap;
};
void* AllocateWithHeader(Allocator*, int);
void __cdecl hkArrayUtil__reserve(Allocator*, void*, int, int);
void __cdecl ResizeAudioStream(Allocator*, void*, int);
BSAudio* __cdecl hkMemoryRouter_getInstance();

struct SweepNode {
    unsigned short min0, max0, min1, max1, min2, max2;
    int link;
};
struct SweepEnd {
    unsigned short value, node;
};
template<class T> struct SweepEndpointView {
    T* data;
    int size, capacity;
    SweepEndpointView():data(0),size(0),capacity(0x80000000) {}

    static void reserveHeap(Allocator& heap, SweepEndpointView* array, int n) {
        int cap = array->capacity & 0x3fffffff;
        if (cap < n) {
            int grown = 2*cap;
            fnv_00d13bd0::hkArrayUtil__reserve(&heap, array, n < grown ? grown : n, sizeof(T));
        }
    }
    T& _expandOne(Allocator& heap) { if(size == (capacity & 0x3fffffff)) { fnv_00d13bd0::ResizeAudioStream(&heap,this,sizeof(T)); construct(data+size,1); } return data[size++]; }
    T& expand() { SweepRouter* router=(SweepRouter*)hkMemoryRouter_getInstance();return _expandOne(*router->heap); }
    void append(const SweepEnd& value) {
        new (data+size) SweepEnd(value);
        ++size;
    }
};
struct SweepMarker { unsigned short node,value; SweepEndpointView<unsigned short> overlaps; };
union SweepBits { __m128 vector; struct { unsigned int x,y,z,w; } bits; };
static const __m128 sweepBias={65536.0f,65536.0f,65536.0f,65536.0f};
extern __m128 DAT_011b3790;
extern const void* DAT_010cd5cc[];
extern "C" void _ReadWriteBarrier(void);
inline void findSweepShift(int value,int& result) { result=-1; if(value>0) { int current=*(volatile int*)&result; do {value>>=1;++current;}while(value>0);result=current;} }
struct SweepScratch { union {float upper;SweepEnd endpoint;}; union {int logarithm;int byteOffset;}; union {float lower;int power;int index;SweepEnd last;}; union {float middle;float value;int needed;int markerCount;}; SweepNode* root; };
struct SweepBound { int x,y,z,w; SweepBound(const int* p):x(p[0]),y(p[1]),z(p[2]),w(p[3]) {} };

// Retained: the shared hkpBroadPhase constructor lacks throw(), adding EH code here.
struct FUN_00d13bd0 : SweepBase {
    SweepBound lowBound,highBound;
    __m128 offset,offset2,scale,unk70,unk80,unk90;
    SweepEndpointView<SweepNode> nodes;
    SweepEndpointView<SweepEnd> axes[3];
    int mask,shift;
    SweepMarker* markers;
    float correction;
    FUN_00d13bd0(const int* low,const int* high,int count);
};
// Initializes sweep bounds, node and marker arrays, and the initial sweep tree.
// @fnv 0x00d13bd0
FUN_00d13bd0::FUN_00d13bd0(const int* low,const int* high,int count):lowBound((vtable=DAT_010cd5cc,low)),highBound(high) {
    SweepScratch scratch; findSweepShift(count ? count : 1,scratch.logarithm);
    SweepRouter* router = (SweepRouter*)hkMemoryRouter_getInstance();
    nodes.reserveHeap(*router->heap, &nodes, 255);
    __m128 scaleCopy,maximum,bias;
    scratch.lower=10.0f;scratch.upper=11.0f;
    bias=sweepBias;
    offset=_mm_setzero_ps(); offset2=_mm_setzero_ps(); scale=_mm_set1_ps(1.0f);
    const __m128& scaleRef=scale;
    scaleCopy=scaleRef;
    maximum=DAT_011b3790;
    for(int iteration=0;iteration<23;++iteration) {
        scratch.middle=(scratch.upper+scratch.lower)*0.5;
        double midpoint=scratch.middle; float& value=scratch.value;value=midpoint+1.0f;
        SweepBits result;
        result.vector=_mm_add_ps(_mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(_mm_set1_ps(value),offset),scaleCopy),maximum),_mm_setzero_ps()),bias);
        if((unsigned short)((result.bits.x>>7)|1)<12) scratch.lower=midpoint; else scratch.upper=midpoint;
    }
    scale=_mm_setzero_ps(); offset=_mm_setzero_ps(); offset2=_mm_setzero_ps();
    correction=(scratch.upper+scratch.lower)*0.5-11.0;
    scratch.root=&nodes.expand();
    SweepNode& root=*scratch.root;
    root.max0=0;root.min0=0;root.min2=0;root.link=0;
    scratch.power=1<<scratch.logarithm;
    scratch.needed = scratch.power + scratch.power + 510;
    SweepRouter* r0 = (SweepRouter*)hkMemoryRouter_getInstance();
    axes[0].reserveHeap(*r0->heap, &axes[0], scratch.needed);
    SweepRouter* r1 = (SweepRouter*)hkMemoryRouter_getInstance();
    axes[1].reserveHeap(*r1->heap, &axes[1], 512);
    SweepRouter* r2 = (SweepRouter*)hkMemoryRouter_getInstance();
    axes[2].reserveHeap(*r2->heap, &axes[2], 512);
    scratch.endpoint.node=0;scratch.endpoint.value=0;
    axes[0].append(scratch.endpoint); axes[1].append(scratch.endpoint); axes[2].append(scratch.endpoint);
    shift=scratch.logarithm; scratch.markerCount=scratch.power-1; mask=scratch.markerCount; markers=0;
    if(scratch.markerCount) {
        SweepRouter* r = (SweepRouter*)hkMemoryRouter_getInstance();
        Allocator* heap = r->heap;
        int iAllocationSize = scratch.markerCount * 16;
        markers = (SweepMarker*)AllocateWithHeader(heap, iAllocationSize);
    }
    scratch.index=0;
    if(scratch.index<mask) { scratch.byteOffset=0; for(;scratch.index<mask;++scratch.index,scratch.byteOffset+=16) {
        SweepMarker* marker=new((SweepMarker*)((char*)markers+scratch.byteOffset)) SweepMarker;
        scratch.endpoint.node=(unsigned short)nodes.size;scratch.endpoint.value=(unsigned short)((scratch.index+1)<<(16-shift));
        marker->node=scratch.endpoint.node; marker->value=scratch.endpoint.value;
        SweepNode& node=nodes.expand();
        node.min2=(unsigned short)axes[0].size;
        axes[0].append(scratch.endpoint);
        scratch.endpoint.value|=1;
        node.max2=(unsigned short)axes[0].size;
        axes[0].append(scratch.endpoint);
        node.link=scratch.byteOffset|1;
        node.max0=0;node.min0=0;node.max1=1;node.min1=1;
    }
    }
    *scratch.root=nodes.data[0];
    scratch.root->max2=(unsigned short)axes[0].size;
    scratch.root->min1=(unsigned short)axes[1].size;
    scratch.root->max1=(unsigned short)axes[2].size;
    scratch.last.node=0;scratch.last.value=0xfffd;
    axes[0].append(scratch.last);axes[1].append(scratch.last);axes[2].append(scratch.last);
}
}  // namespace fnv_00d13bd0

BSAudio* __cdecl hkMemoryRouter_getInstance() throw();

template <typename T>
struct HkDynamicArray {
    T* m_data;
    int m_iCapacityState;

    __forceinline HkDynamicArray(int n) throw() {
        allocate(hkMemoryRouter::getInstance().temp(), n);
    }
    __forceinline void allocate(hkMemoryAllocator& alloc, int n) throw() {
        int num = n;
        m_data = num ? alloc._bufAlloc<T>(num) : 0;
        m_iCapacityState = num ? num : (int)0x80000000;
    }

    __forceinline ~HkDynamicArray() throw() {
        release(hkMemoryRouter::getInstance().temp());
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
        alloc.bufFree(p, (cap & 0x3fffffff) * (int)sizeof(T));
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

// Sorts m_kNodeCollection by m_usValue08, remaps node indices in m_d8 and m_ac, updates node h pointers, and calls FixNodeEdges.
// @fnv 0x00d15fc0
// src: HAVOK_LIB 0x00d15fc0
void hkp3AxisSweep::defragment() {
    int n = reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).GetLogicalSize();
    int tmpCap;
    Elem* tmp = hkTempAlloc<Elem>(hkMemoryRouter::getInstance().temp(), n, tmpCap);
    int keysCap;
    KeyPair* keys = hkTempAlloc<KeyPair>(hkMemoryRouter::getInstance().temp(), n, keysCap);
    int remapCap;
    int* remap = hkTempAlloc<int>(hkMemoryRouter::getInstance().temp(), n, remapCap);

    {
    int i=0;
    if (i < reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).GetLogicalSize()) {
        int offset=0;
        do {
        *(Elem*)((char*)tmp + offset) = *(Elem*)((char*)reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).m_data + offset);
        keys[i].val = ((Elem*)((char*)reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).m_data + offset))->m_usValue08;
        keys[i].idx = (unsigned short)i;
i++; offset += sizeof(Elem);
        } while (i < reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).GetLogicalSize());
    }
    }

    hkQuickSort(&keys[1], n - 1, KeyLess());

    for (int i = 0; i < reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).GetLogicalSize(); i++) {
        unsigned idx = keys[i].idx;
        remap[idx] = i;
        reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection)[i] = tmp[idx];
    }

    for (int i=1; i<reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).GetLogicalSize(); i++) {
int* h=reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection)[i].h; Elem& node=reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection)[i];
if (((unsigned)node.h & 1)==0) *h=i; else node.getMarker(reinterpret_cast<Sub*>(unkD8))->x=(unsigned short)i;
    }

    for (int j = 0; j < m_iMarkerCount; j++) {
        Sub* x = &reinterpret_cast<Sub*>(unkD8)[j];
        for (int idx = x->n - 1; idx >= 0; idx--) {
            x->idx[idx] = (unsigned short)remap[x->idx[idx]];
        }
    }

    for (int a = 0; a < 3; a++) {
        KeyPair* w = (KeyPair*)reinterpret_cast<AxisPair*>(m_kAxisEndPoints)[a].p;
        for (int idx = 0; idx < reinterpret_cast<AxisPair*>(m_kAxisEndPoints)[a].n; idx++) {
            w[idx].idx = (unsigned short)remap[w[idx].idx];
        }
    }

    for (int i = 1; i < reinterpret_cast<hkArrayBase<Elem>&>(m_kNodeCollection).GetLogicalSize(); i++) {
        FixNodeEdges(i);
    }

    hkTempFree(hkMemoryRouter::getInstance().temp(), remap, remapCap);
    hkTempFree(hkMemoryRouter::getInstance().temp(), keys, keysCap);
    hkTempFree(hkMemoryRouter::getInstance().temp(), tmp, tmpCap);
}

extern int DAT_011b37ac[2];

struct SweepMerge {
    Endpoint* m_endpoints;
    void MergeEndpointRangesBackward(char* cells, int n, Endpoint* source, int count);
};

// Merges m_endpoints[0..n-count) with source[0..count) from the back into m_endpoints, writing each moved endpoint's new index into cells.
// @fnv 0x00d19e40
// src: GUESS 0x00d19e40 (confidence: medium)
void SweepMerge::MergeEndpointRangesBackward(char* cells, int aiTotalCount, Endpoint* apRightStart, int aiRightCount)
{
    Endpoint* base = m_endpoints;
    Endpoint* right = apRightStart;
    right += aiRightCount - 1;
    int oldCount = aiTotalCount - aiRightCount;
    Endpoint* left = base + oldCount - 1;
    int leftValue = base[oldCount - 1].value;
    int rightValue = right->value;
    int index = aiTotalCount - 1;
    Endpoint* out = base + index;
    for (;;) {
        if (leftValue > rightValue) {
            *out = *left;
            unsigned int slot = (left->handle << 4) + DAT_011b37ac[left->value & 1];
            *(unsigned short*)(cells + slot) = (unsigned short)index;
            --left;
            --out;
            --index;
            leftValue = left->value;
        } else {
            *out = *right;
            unsigned int slot = (right->handle << 4) + DAT_011b37ac[right->value & 1];
            *(unsigned short*)(cells + slot) = (unsigned short)index;
            --right;
            rightValue = right->value;
            --out;
            --index;
            if (right < apRightStart) break;
        }
    }
}

// Copies the two __m128 members m_v70 and m_v80 into the caller-supplied output pointers out0 and out1.
// @fnv 0x00d1a2a0
void hkp3AxisSweep::GetValues(__m128* out0, __m128* out1)
{
    *out0 = m_v70;
    *out1 = m_v80;
}

// The compiler emits the scalar deleting destructor for hkp3AxisSweep at 0x00d1a2d0.
__forceinline void hkReferencedObject::operator delete(void* p)
{
    hkReferencedObject* object = static_cast<hkReferencedObject*>(p);
    reinterpret_cast<hkMemoryAllocator*>((&hkMemoryRouter::getInstance())->m_heap)->blockFree(p, object->m_usMemSizeAndFlags);
}

namespace fnv_00d11650 {
// Exe 0x00d11650 FUN_00d11650: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);

typedef float hkReal;

// Preserve this unit's intrinsic representation without constructing vector wrappers.
__forceinline void setVector(LocalM128& v, hkReal x, hkReal y, hkReal z, hkReal w) {
    v = _mm_setr_ps(x, y, z, w);
}
__forceinline void subtractVector(LocalM128& v, const LocalM128& b) {
    v = _mm_sub_ps(v, b);
}
}  // namespace fnv_00d11650

// Computes the axis-aligned bounding box of a BpNode in local space by scaling its endpoint coordinates and storing the result in aabb.
// @fnv 0x00d11650
// src: XBOX_PDB 0x00d11650
void hkp3AxisSweep::getAabbFromNode(const Node& node, hkAabb& output) const
{
    using namespace fnv_00d11650;
    hkReal fInvScaleX = 1.0f / scale.m128_f32[0];
    hkReal fInvScaleY = 1.0f / scale.m128_f32[1];
    hkReal fInvScaleZ = 1.0f / scale.m128_f32[2];

    fnv_00d11650::LocalM128 mn;
    setVector(mn, fInvScaleX * m_kAxisEndPoints[0].m_data[node.m_usValue08].m_uiFilterValue, fInvScaleY * m_kAxisEndPoints[1].m_data[node.m_usValue00].m_uiFilterValue, fInvScaleZ * m_kAxisEndPoints[2].m_data[node.m_usValue02].m_uiFilterValue, 0.0f);
    float hx = m_kAxisEndPoints[0].m_data[node.m_usValue0A].m_uiFilterValue;
    float hy = m_kAxisEndPoints[1].m_data[node.m_usValue04].m_uiFilterValue;
    float hz = m_kAxisEndPoints[2].m_data[node.m_usValue06].m_uiFilterValue;
    fnv_00d11650::LocalM128 mx;
    setVector(mx, fInvScaleX * hx, fInvScaleY * hy, fInvScaleZ * hz, 0.0f);
    subtractVector(mn, reinterpret_cast<const fnv_00d11650::LocalM128&>(offset));
    subtractVector(mx, reinterpret_cast<const fnv_00d11650::LocalM128&>(offset));
    reinterpret_cast<hkVector4q*>(&output)[0].m_vComponents = reinterpret_cast<const ::__m128&>(mn);
    reinterpret_cast<hkVector4q*>(&output)[1].m_vComponents = reinterpret_cast<const ::__m128&>(mx);
}

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

// Iterates sweep records matching a bitmask, appending those whose f0c value is even to the events list, growing it when full.
// @fnv 0x00d14100
// src: HAVOK_LIB 0x00d14100
void hkp3AxisSweep::reQuerySingleObject(int* index, EventList* events)
{
    int count = m_iA4;
    int blocks = (count >> 5) + 8;
    AudioSink& sink = ((AudioGlobal*)hkMemoryRouter_getInstance())->temp();
    SweepRecord* block;
    unsigned* pMask;
    void* buffer;
    int masks = 0;
    unsigned* maskEnd;
    sink.allocateBlocks(blocks, buffer, masks);
    if (!masks)
        masks = 0x80000000;

    int idx = *index;
    SweepRecord* ref = reinterpret_cast<SweepRecord*>(unkA0) + idx;
    unsigned short code = reinterpret_cast<SweepType*>(axis0)[ref->f08].value;
    pMask = (unsigned*)buffer;
    hkp3AxisSweep_setBitsBasedOnXInterval(count, code, ref, idx, buffer);

    block = reinterpret_cast<SweepRecord*>(unkA0);
    maskEnd = pMask + (m_iA4 >> 5) + 1;
    while (pMask < maskEnd) {
        unsigned mask = *pMask;
        SweepRecord* rec = block;
        while (mask) {
            if ((mask & 0xff) == 0) {
                rec += 8;
                mask >>= 8;
                continue;
            }
            if (mask & 1) {
                if (!(((rec->f04 - ref->f00) | (ref->f04 - rec->f00)) & 0x80008000)) {
                    int value = rec->f0c;
                    if (!(value & 1)) {
                        AudioGlobal* owner = (AudioGlobal*)hkMemoryRouter_getInstance();
                        if (events->count == (events->capacity & 0x3fffffff))
                            ResizeAudioStream(owner->listOwner, events, 8);
                        SweepEvent* slot = (SweepEvent*)((char*)events->data + events->count * 8);
                        if (slot) {
                            slot->index = index;
                            slot->value = value;
                        }
                        events->count++;
                    }
                }
            }
            rec += 1;
            mask >>= 1;
        }
        block += 32;
        pMask += 1;
    }

    AudioSink& s2 = ((AudioGlobal*)hkMemoryRouter_getInstance())->temp();
    if (!(masks & 0x80000000u))
        s2.fn10(buffer, (masks & 0x3fffffff) * 4);
}

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
 Allocator* heap;
 static SweepRouterX* __cdecl router();
 Allocator& getHeap() { return *heap; }
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
  Allocator& a=SweepRouterX::router()->getHeap();
  int cap=capacity&0x3fffffff;
  if(cap<n) { int twice=cap*2; hkArrayUtil__reserve(&a,this,n<twice?twice:n,16); }
  size=n;
 }
};
struct SweepAxisX {
 Endpoint* data; int size; int capacity;
 void hkp3AxisSweep_hkpBpAxis_remove(int a,int b);
};

// Removes the node at handle from the sweep structure, updating axes, groups, and node storage.
// @fnv 0x00d14600
// src: HAVOK_LIB 0x00d14600
void hkp3AxisSweep::removeObject(unsigned int* handle,SweepPairsX* pairs) {
 unsigned long base=*handle;
 unsigned long count;
 count = reinterpret_cast<SweepNodesX&>(m_kNodeCollection).size;
 SweepNodeX* alloc=reinterpret_cast<SweepNodesX&>(m_kNodeCollection).data+base;
 unsigned int* index;
 int c;
 int first=((unsigned int)count>>5)+8;
 SweepAllocatorX& other=SweepRouterX::router()->getStack();
 if(first) {
  int bytes=first*4;
  unsigned int* value=index=(unsigned int*)other.allocate(bytes);
  int converted=bytes/4;
_ReadWriteBarrier();
  index=value;
  c=converted;
 } else { index=0; c=0; }
 if(!c) c=0x80000000;
 hkp3AxisSweep_setBitsBasedOnXInterval(count,reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[0].data[alloc->lowZ].value,alloc,base,index);
 unsigned int* capacity=index;
 SweepNodeX* q;
 q = reinterpret_cast<SweepNodesX&>(m_kNodeCollection).data;
 unsigned int* last;
 last = index+(reinterpret_cast<SweepNodesX&>(m_kNodeCollection).size>>5)+1;
 for(;capacity<last;++capacity,q+=32) {
  SweepNodeX* wordCount=q;
  unsigned int mask=*capacity;
  while(mask) {
   if(!(mask&255)) { wordCount+=8; mask>>=8; }
   else {
    if(mask&1) {
     if(!(((wordCount->maximum-alloc->minimum)|(alloc->maximum-wordCount->minimum))&0x80008000)) {
      unsigned int result=wordCount->handle;
      if(!(result&1)) {
       pairs->push(handle,result);
      } else {
       SweepGroupX* group=(SweepGroupX*)((char*)reinterpret_cast<SweepGroupX*>(unkD8)+(result&~1));
       group->remove((unsigned short)base);
      }
     }
    }
    ++wordCount; mask>>=1;
   }
  }
 }
 SweepAllocatorX& releaseAlloc=SweepRouterX::router()->getStack();
 if(!(c&0x80000000)) releaseAlloc.release(index,(c&0x3fffffff)*4);
 q=reinterpret_cast<SweepNodesX&>(m_kNodeCollection).data;
 reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[0].hkp3AxisSweep_hkpBpAxis_remove(alloc->lowZ,alloc->highZ);
 reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[1].hkp3AxisSweep_hkpBpAxis_remove((unsigned short)alloc->minimum,(unsigned short)alloc->maximum);
 reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[2].hkp3AxisSweep_hkpBpAxis_remove((unsigned short)(alloc->minimum>>16),(unsigned short)(alloc->maximum>>16));
 hkp3AxisSweep_updateNodesAfterDelete(q,count,alloc);
 if(base<(unsigned int)(count-1)) {
  *alloc=reinterpret_cast<SweepNodesX&>(m_kNodeCollection).data[count-1];
  reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[0].data[alloc->lowZ].handle=(unsigned short)base;
  reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[0].data[alloc->highZ].handle=(unsigned short)base;
  if(!(1 & alloc->handle)) {
   reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[1].data[(unsigned short)alloc->minimum].handle=(unsigned short)base;
   reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[1].data[(unsigned short)alloc->maximum].handle=(unsigned short)base;
   reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[2].data[(unsigned short)(alloc->minimum>>16)].handle=(unsigned short)base;
   reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[2].data[(unsigned short)(alloc->maximum>>16)].handle=(unsigned short)base;
   *(unsigned int*)alloc->handle=base;
  } else {
   SweepGroupX* group=(SweepGroupX*)((char*)reinterpret_cast<SweepGroupX*>(unkD8)+(alloc->handle&~1));
   group->node=(unsigned short)base;
  }
  if(m_iMarkerCount && !(alloc->handle&1)) {
   unsigned short low=alloc->lowZ;
   Endpoint* zPoints=reinterpret_cast<SweepAxisX*>(m_kAxisEndPoints)[0].data;
   
   int cursor=zPoints[low].value>>(unsigned short)(16-shiftBits);
   if(cursor > 0 && reinterpret_cast<SweepNodesX&>(m_kNodeCollection).data[reinterpret_cast<SweepGroupX*>(unkD8)[cursor-1].node].highZ>low) --cursor;
   int end=(zPoints[alloc->highZ].value>>(unsigned short)(16-shiftBits))-1;
   if(cursor<=end) {
   unsigned short oldIndex=(unsigned short)(count-1);
   for(int i=cursor;i<=end;++i) {
    SweepGroupX& group=reinterpret_cast<SweepGroupX*>(unkD8)[i];
    group.data[group.find(oldIndex)]=(unsigned short)base;
   }
   }
  }
  FixNodeEdges(static_cast<unsigned int>(base));
 }
 reinterpret_cast<SweepNodesX&>(m_kNodeCollection).SetSizeAndGrow(count-1);
}

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

// Fills a pool array with (item->m_14 << 4) + m_a0 per item, calls FUN_00d13950 with it and a2, then restores the pool pointer and frees the array.
// @fnv 0x00d15f10
// src: HAVOK_LIB 0x00d15f10
void hkp3AxisSweep::calcAabbCache(ItemList* apItemList, unsigned int a2)
{
    hkp3AxisSweep* volatile self = this;
    Blk blk;
    ItemList* list = apItemList;
    unsigned int n = (unsigned int)list->m_uiItemCount;
    int i = 0;
    blk.b = (unsigned int)i;
    Pool* pool = reinterpret_cast<Pool*>(hkMemoryRouter_getInstance());
    unsigned int base = pool->m_ptr;
    pool->m_ptr = base + ((n * 4 + 0x7f) & 0xffffff80u);
    unsigned int flags = n | 0x80000000u;
    blk.a = base;
    blk.c = flags;
    unsigned int* arr = reinterpret_cast<unsigned int*>(base);
    blk.d = base;

    if (i < list->m_uiItemCount) {
      do {
        unsigned int index=list->m_items[i]->m_14; unsigned int v = (index << 4) + reinterpret_cast<unsigned int>(self->unkA0); arr[i++] = v;
      } while(i < list->m_uiItemCount);
      blk.b = (unsigned int)i;
    }
    hkp3AxisSweep* callSelf=self; callSelf->calcAabbCacheInternal(&blk, a2);
    pool = reinterpret_cast<Pool*>(hkMemoryRouter_getInstance());
    pool->m_ptr = base;
    Pool* pool2 = reinterpret_cast<Pool*>(hkMemoryRouter_getInstance());
    Alloc* pAlloc = pool2->m_alloc;
    if ((flags & 0x80000000u) == 0) {
        pAlloc->Free(arr, (flags & 0x3fffffffu) * 4);
    }
}
#include <xmmintrin.h>

#include <xmmintrin.h>

struct Entry4 { unsigned short value; unsigned short handle; };
struct AxisArr {
    Entry4* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
    void InsertPair(unsigned int a1, unsigned int a2, unsigned short a3, unsigned short a4, unsigned short* out2, unsigned short* out1);
};
struct Node16 {
    union { unsigned int f0; struct { unsigned short minY, minZ; }; };
    union { unsigned int f4; struct { unsigned short maxY, maxZ; }; };
    union { unsigned int f8; struct { unsigned short minX, maxX; }; };
    int* fC;
};
struct NodesArr {
    Node16* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct Pair8 { int first; int second; };
struct PairArr {
    Pair8* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};
struct Input {
    unsigned int v0; unsigned int v4; unsigned int v8; unsigned int vC;
    unsigned int v10; unsigned int v14; unsigned int v18; unsigned int v1C;
};

union CheckedUnsignedShortVector {
    __m64 v;
    struct { short x,y,z,w; };
};
// src: GUESS 0x00d10b30 (confidence: low)
__declspec(noinline) void hkp3AxisSweep::Hkp3axissweepGsEhscNogsNoehsc_ProcessEntries_00d10b30(Node16* buf, int index, Node16* node) {
    CheckedUnsignedShortVector lo,hi,loMax,hiMax;
    __m64 yz = *(__m64*)&node->f0;
    __m64 x = *(__m64*)&node->f8;
    __m64 all = _mm_cmpeq_pi16(_mm_setzero_si64(),_mm_setzero_si64());
    __m64 ones = _mm_srli_pi16(all,15);
    __m64 twos = _mm_slli_pi16(ones,1);
    lo.v = _mm_sub_pi16(_mm_unpacklo_pi32(yz,yz), ones);
    __m64 yzMax = _mm_srli_si64(yz,32);
    loMax.v = _mm_sub_pi16(_mm_unpacklo_pi32(yzMax,yzMax), twos);
    hi.v = _mm_sub_pi16(_mm_unpacklo_pi16(x,x), ones);
    __m64 xMax = _mm_srli_si64(x,16);
    hiMax.v = _mm_sub_pi16(_mm_unpacklo_pi16(xMax,xMax), twos);
    __m64 mask = _mm_srli_si64(all,32);
    Node16* end = buf + index;
    for (;buf < end; ++buf) {
        __m64 a = *(__m64*)&buf->f0;
        __m64 b = *(__m64*)&buf->f8;
        *(__m64*)&buf->f0 = _mm_sub_pi16(a,_mm_add_pi16(_mm_cmpgt_pi16(a,lo.v),_mm_cmpgt_pi16(a,loMax.v)));
        *(__m64*)&buf->f8 = _mm_sub_pi16(b,_mm_and_si64(mask,_mm_add_pi16(_mm_cmpgt_pi16(b,hi.v),_mm_cmpgt_pi16(b,hiMax.v))));
    }
    _mm_empty();
}

struct __declspec(align(16)) BoundVector {
    unsigned int x,y,z,w;
};
// Inserts a node into m_kNodeCollection, updates axis bounds, and collects overlapping node handles into outPairs.
// @fnv 0x00d142b0
// src: XBOX_PDB 0x00d142b0
void hkp3AxisSweep::addObject_00d142b0(int* handle, Input* input, PairArr* outPairs) {
    BoundVector mins, maxs;
    mins.x = input->v0 >> 15;
    mins.y = input->v4 >> 15;
    mins.z = input->v8 >> 15;
    unsigned int max0 = input->v10 >> 15;
    if (max0 != 0xffff) ++max0;
    maxs.x = max0 | 1;
    unsigned int max1 = input->v14 >> 15;
    if (max1 != 0xffff) ++max1;
    maxs.y = max1 | 1;
    unsigned int max2 = input->v18 >> 15;
    if (max2 != 0xffff) ++max2;
    maxs.z = max2 | 1;
    mins.x &= 0xfffe;
    mins.y &= 0xfffe;
    mins.z &= 0xfffe;
    int oldSize = reinterpret_cast<NodesArr&>(m_kNodeCollection).m_iElementCount;
    NodesArr* nodes = &reinterpret_cast<NodesArr&>(m_kNodeCollection);
    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    if (nodes->m_iElementCount == (int)(nodes->m_capFlags & 0x3fffffff)) {
        ResizeAudioStream((void*)router->m_heap, nodes, 0x10);
    }
    Node16* node = nodes->m_data + nodes->m_iElementCount++;
    Node16* data = reinterpret_cast<NodesArr&>(m_kNodeCollection).m_data;
    reinterpret_cast<FUN_00d11da0_cls&>(m_axis0).InsertPair((unsigned int)data, oldSize, (unsigned short)mins.x, (unsigned short)maxs.x, &node->minX, &node->maxX);
    reinterpret_cast<FUN_00d11da0_cls&>(m_axis1).InsertPair((unsigned int)data, oldSize, (unsigned short)mins.y, (unsigned short)maxs.y, &node->minY, &node->maxY);
    reinterpret_cast<FUN_00d11da0_cls&>(m_axis2).InsertPair((unsigned int)data, oldSize, (unsigned short)mins.z, (unsigned short)maxs.z, &node->minZ, &node->maxZ);
    Hkp3axissweepGsEhscNogsNoehsc_ProcessEntries_00d10b30(data, oldSize, node);
    node->fC = handle;
    *handle = oldSize;
    int nodeCount = reinterpret_cast<NodesArr&>(m_kNodeCollection).m_iElementCount;
    int count = (nodeCount >> 5) + 8;
    hkMemoryRouter* router2 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(router2->m_temp);
    int* bufData;
    unsigned int bufCap;
    if (count != 0) {
        volatile int bytes = count * 4;
        int* result = (int*)alloc->bufAlloc(*(int*)&bytes);
        int n = bytes / 4;
        bufData = result;
        bufCap = n;
    } else {
        bufData = 0;
        bufCap = 0;
    }
    if (bufCap == 0) bufCap = 0x80000000;
    hkp3AxisSweep_setBitsBasedOnXInterval(nodeCount, mins.x, node, oldSize, bufData);
    int* cursor = bufData;
    Node16* chunk = reinterpret_cast<NodesArr&>(m_kNodeCollection).m_data;
    int* end = bufData + ((reinterpret_cast<NodesArr&>(m_kNodeCollection).m_iElementCount >> 5) + 1);
    while (cursor < end) {
        Node16* n = chunk;
        unsigned int bits = (unsigned int)*cursor;
        if (bits != 0) {
            for (;;) {
                if ((unsigned char)bits == 0) {
                    n += 8;
                    bits >>= 8;
                } else {
                    if (bits & 1) {
                        int diff1 = (int)n->f4 - (int)node->f0;
                        int diff2 = (int)node->f4 - (int)n->f0;
                        if (((diff1 | diff2) & 0x80008000) == 0) {
                            int fc = (int)n->fC;
                            if ((fc & 1) == 0) {
                                hkMemoryRouter* pRouter3 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
                                if (outPairs->m_iElementCount == (int)(outPairs->m_capFlags & 0x3fffffff)) {
                                    ResizeAudioStream((void*)pRouter3->m_heap, outPairs, 8);
                                }
                                Pair8* dst = outPairs->m_data + outPairs->m_iElementCount;
                                if (dst) {
                                    dst->first = (int)handle;
                                    dst->second = fc;
                                }
                                outPairs->m_iElementCount++;
                            } else {
                                TargetStruct* marker = (TargetStruct*)(m_markerBase + (fc & ~1));
                                marker->m_ppData.AddBack((const unsigned short&)oldSize);
                            }
                        }
                    }
                    ++n;
                    bits >>= 1;
                }
                if (!bits) break;
            }
        }
        chunk += 32;
        ++cursor;
    }
    hkMemoryRouter* router3 = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc3 = reinterpret_cast<hkMemoryAllocator*>(router3->m_temp);
    if (!(bufCap & 0x80000000)) {
        alloc3->bufFree(bufData, (bufCap & 0x3fffffff) * 4);
    }
}

#include <xmmintrin.h>
// Retained: using the shared ShiftAllObjects declaration changes FUN_00d175f0 bytes.
namespace fnv_00d175f0 {
#include <xmmintrin.h>

extern "C" void _ReadWriteBarrier(void);
struct SweepEnd { unsigned short value, handle; };
struct SweepNode {
    unsigned short minY, minZ, maxY, maxZ, minX, maxX;
    unsigned* handle;
};
struct SweepList { void* data; int size; int capacity;
    SweepList():data(0),size(0),capacity(0x80000000) {}
    void clear() throw() {
        hkMemoryRouter* router=(hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkMemoryAllocator* heap=reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
        int cap=capacity;
        size=0;
        if (!(cap & 0x80000000)) heap->bufFree(data,(cap&0x3fffffff)*8);
        data=0;capacity=0x80000000;
    }

};
struct SweepAxis { SweepEnd* data; int size; int capacity; };
void __fastcall hkp3AxisSweep_beginOverlapCheckMarker(void*, SweepNode*, unsigned, SweepNode*, void*);
void __fastcall RemoveOrAppendTagEntry(void*, SweepNode*, unsigned, SweepNode*, void*);
void __fastcall AppendPairToBuffer(SweepNode*, SweepNode*, void*);
void __fastcall AppendPairEntry(SweepNode*, SweepNode*, void*);
struct __declspec(align(16)) SweepVector { float x,y,z,w; };
struct __declspec(align(16)) SweepBounds { unsigned low[4], high[4]; };
struct SweepManager {
    unsigned field00;
    unsigned field04;
    unsigned field08;
    unsigned field0C;
    unsigned field10;
    unsigned field14;
    unsigned field18;
    unsigned field1C;
    unsigned field20;
    unsigned field24;
    unsigned field28;
    unsigned field2C;
    unsigned field30;
    unsigned field34;
    unsigned field38;
    unsigned field3C;
    unsigned field40;
    unsigned field44;
    unsigned field48;
    unsigned field4C;
    unsigned field50;
    unsigned field54;
    unsigned field58;
    unsigned field5C;
    float scale[4];
    unsigned field70;
    unsigned field74;
    unsigned field78;
    unsigned field7C;
    unsigned field80;
    unsigned field84;
    unsigned field88;
    unsigned field8C;
    unsigned field90;
    unsigned field94;
    unsigned field98;
    unsigned field9C;
    SweepNode* nodes;
    int nodeCount, nodeCapacity;
    SweepAxis axes[3];
    int markerCount, fieldD4;
    void* markers;
    __forceinline void update(unsigned id, const SweepBounds& bounds, void* added, SweepList& removed);
    void hkp3AxisSweep_shiftAllObjects(const SweepVector* shift, SweepVector* effective, void* added);
};
// Rounds a shift vector to integer scale, updates sweep axis values, and calls update for nodes crossing sweep boundaries.
// @fnv 0x00d175f0
// src: XBOX_PDB 0x00d175f0
void SweepManager::hkp3AxisSweep_shiftAllObjects(const SweepVector* shift, SweepVector* effective, void* added) {
    SweepVector rounded = *shift;
    __int64 delta[3];
    for (int a=0; a<3; ++a) {
        delta[a] = (__int64)(scale[a] * (&rounded.x)[a]) & ~(__int64)1;
        (&rounded.x)[a] = (float)delta[a] / scale[a];
    }
    *(__m128*)effective = *(__m128*)&rounded;
    SweepList removed;
    for (int axis=0; axis<3; ++axis) {
        SweepAxis* list = &axes[axis];
        int displacement = (int)delta[axis];
        int end, step, first;
        if (displacement < 0) { end=list->size-1; first=1; step=1; }
        else { first=list->size-2; _ReadWriteBarrier(); end=0; step=-1; }
        for (int position=first; position!=end; position+=step) {
            SweepEnd* ep = list->data+position;
            unsigned value=ep->value;
            if (value-2 > 0xfff9u) continue;
            int shifted=((displacement+value)&~1) | (value&1);
            SweepNode* original=nodes+ep->handle;
            if (shifted<0) shifted=value&1;
            else if (shifted>=0xfffc) shifted=(value&1)|0xfffc;
            ep->value=(unsigned short)shifted;
            if (shifted!=0 && shifted!=0xfffd) continue;
            SweepBounds bounds;
            SweepEnd* edgesX=axes[0].data;
            bounds.low[0]=edgesX[original->minX].value;
            SweepEnd* edgesY=axes[1].data;
            bounds.low[1]=edgesY[original->minY].value;
            SweepEnd* edgesZ=axes[2].data;
            bounds.low[2]=edgesZ[original->minZ].value;
            _ReadWriteBarrier();
            bounds.high[0]=edgesX[original->maxX].value;
            bounds.high[1]=edgesY[original->maxY].value;
            bounds.high[2]=edgesZ[original->maxZ].value;
            unsigned id=*original->handle;
            update(id,bounds,added,removed);
        }
    }
    removed.clear();
    hkMemoryRouter_getInstance();
}

__forceinline void SweepManager::update(unsigned id, const SweepBounds& bounds, void* added, SweepList& removed) {
            SweepNode* crossing7; (void)crossing7;
            SweepNode* crossing6; (void)crossing6;
            SweepNode* crossing5; (void)crossing5;
            SweepNode* crossing4; (void)crossing4;
            SweepNode* node=nodes+id;
            unsigned xLeftOverlap; (void)xLeftOverlap;
            SweepNode* base=nodes;
            { // min_left, axis 0
                unsigned index=node->minX;
                SweepEnd* cursor=axes[0].data+index;
                unsigned adjacent=cursor[-1].value;
                while (bounds.low[0] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[-1];
                    cursor+=-1;
                    if ((adjacent&1)) {
                        unsigned overlaps = (( *(unsigned*)&node->maxY - *(unsigned*)&other->minY) | (*(unsigned*)&other->maxY - *(unsigned*)&node->minY));
                        other->maxX=(unsigned short)index;
                        if ((overlaps & 0x80008000u)==0) hkp3AxisSweep_beginOverlapCheckMarker(markers,node,id,other,added);
                    } else {
                        other->minX=(unsigned short)index;
                    }
                    --index;
                    adjacent=cursor[-1].value;
                }
                while (bounds.low[0] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    other->minX=(unsigned short)index;
                    --index;
                }
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[0];
                node->minX=(unsigned short)index;
                _ReadWriteBarrier();
            }
            { // max_right, axis 0
                unsigned index=node->maxX;
                SweepEnd* cursor=axes[0].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.high[0] > adjacent) {
                    *cursor=cursor[1];
                    ++index;
                    cursor+=1;
                    SweepNode* other=base+cursor->handle;
                    if (!(adjacent&1)) {
                        unsigned firstMax=*(unsigned*)&other->maxY;
                        unsigned secondMax=*(unsigned*)&node->maxY;
                        _ReadWriteBarrier();
                        unsigned secondGap=secondMax-*(unsigned*)&other->minY;
                        _ReadWriteBarrier();
                        unsigned firstGap=firstMax-*(unsigned*)&node->minY;
                        unsigned overlaps=firstGap|secondGap;
                        --other->minX;
                        if ((overlaps & 0x80008000u)==0) hkp3AxisSweep_beginOverlapCheckMarker(markers,node,id,other,added);
                    } else {
                        --other->maxX;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.high[0] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId || otherId==0) break;
                    ++index;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].maxX;
                    cursor+=1;
                    --*otherIndex;
                }
                adjacent=cursor[-1].value;
                while (bounds.high[0] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    --index;
                    if (!(adjacent&1)) {
                        unsigned short* mx=&other->minX;
                        xLeftOverlap = ((*(unsigned*)&node->maxY - *(unsigned*)&other->minY) | (*(unsigned*)&other->maxY - *(unsigned*)&node->minY));
                        ++*mx;
                        if ((xLeftOverlap & 0x80008000u)==0) RemoveOrAppendTagEntry(markers,node,id,other,&removed);
                    } else {
                        ++other->maxX;
                    }
                    adjacent=cursor[-1].value;
                }
                while (bounds.high[0] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    --index;
                    *cursor=cursor[-1];
                    unsigned short* otherIndex=&base[otherId].maxX;
                    cursor+=-1;
                    ++*otherIndex;
                }
                node->maxX=(unsigned short)index;
                cursor->value=(unsigned short)bounds.high[0];
                cursor->handle=(unsigned short)id;
            }
            { // min_right, axis 0
                unsigned index=node->minX;
                SweepEnd* cursor=axes[0].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.low[0] > adjacent) {
                    unsigned otherId=cursor[1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[1];
                    cursor+=1;
                    ++index;
                    if ((adjacent&1)) {
                        unsigned overlaps = (( *(unsigned*)&node->maxY - *(unsigned*)&other->minY) | (*(unsigned*)&other->maxY - *(unsigned*)&node->minY));
                        --other->maxX;
                        if ((overlaps & 0x80008000u)==0) RemoveOrAppendTagEntry(markers,node,id,other,&removed);
                    } else {
                        --other->minX;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.low[0] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId) break;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].minX;
                    cursor+=1;
                    --*otherIndex;
                    ++index;
                }
                node->minX=(unsigned short)index;
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[0];
            }
            { // min_left, axis 1
                unsigned index=node->minY;
                SweepEnd* cursor=axes[1].data+index;
                unsigned adjacent=cursor[-1].value;
                while (bounds.low[1] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    crossing4=base+otherId;
                    *cursor=cursor[-1];
                    cursor+=-1;
                    if ((adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing4->minZ;
                        overlaps |= crossing4->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing4->minX;
                        overlaps |= crossing4->maxX-node->minX;

                        crossing4->maxY=(unsigned short)index;
                        if ((overlaps & 0x8000u)==0) AppendPairToBuffer(node,crossing4,added);
                    } else {
                        crossing4->minY=(unsigned short)index;
                    }
                    --index;
                    adjacent=cursor[-1].value;
                }
                while (bounds.low[1] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    other->minY=(unsigned short)index;
                    --index;
                }
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[1];
                node->minY=(unsigned short)index;
            }
            { // max_right, axis 1
                unsigned index=node->maxY;
                SweepEnd* cursor=axes[1].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.high[1] > adjacent) {
                    *cursor=cursor[1];
                    ++index;
                    cursor+=1;
                    crossing5=base+cursor->handle;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing5->minZ;
                        overlaps |= crossing5->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing5->minX;
                        overlaps |= crossing5->maxX-node->minX;

                        --crossing5->minY;
                        if ((overlaps & 0x8000u)==0) AppendPairToBuffer(node,crossing5,added);
                    } else {
                        --crossing5->maxY;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.high[1] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId || otherId==0) break;
                    ++index;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].maxY;
                    cursor+=1;
                    --*otherIndex;
                }
                adjacent=cursor[-1].value;
                while (bounds.high[1] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    *cursor=cursor[-1];
                    crossing6=base+otherId;
                    cursor+=-1;
                    --index;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing6->minZ;
                        overlaps |= crossing6->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing6->minX;
                        overlaps |= crossing6->maxX-node->minX;

                        ++crossing6->minY;
                        if ((overlaps & 0x8000u)==0) AppendPairEntry(node,crossing6,&removed);
                    } else {
                        ++crossing6->maxY;
                    }
                    adjacent=cursor[-1].value;
                }
                while (bounds.high[1] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    --index;
                    *cursor=cursor[-1];
                    unsigned short* otherIndex=&base[otherId].maxY;
                    cursor+=-1;
                    ++*otherIndex;
                }
                node->maxY=(unsigned short)index;
                cursor->value=(unsigned short)bounds.high[1];
                cursor->handle=(unsigned short)id;
            }
            { // min_right, axis 1
                unsigned index=node->minY;
                SweepEnd* cursor=axes[1].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.low[1] > adjacent) {
                    unsigned otherId=cursor[1].handle;
                    crossing7=base+otherId;
                    *cursor=cursor[1];
                    cursor+=1;
                    ++index;
                    if ((adjacent&1)) {
                        unsigned short overlaps = node->maxZ-crossing7->minZ;
                        overlaps |= crossing7->maxZ-node->minZ;
                        overlaps |= node->maxX-crossing7->minX;
                        overlaps |= crossing7->maxX-node->minX;

                        --crossing7->maxY;
                        if ((overlaps & 0x8000u)==0) AppendPairEntry(node,crossing7,&removed);
                    } else {
                        --crossing7->minY;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.low[1] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId) break;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].minY;
                    cursor+=1;
                    --*otherIndex;
                    ++index;
                }
                node->minY=(unsigned short)index;
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[1];
            }
            { // min_left, axis 2
                unsigned index=node->minZ;
                SweepEnd* cursor=axes[2].data+index;
                unsigned adjacent=cursor[-1].value;
                while (bounds.low[2] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[-1];
                    cursor+=-1;
                    if ((adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        other->maxZ=(unsigned short)index;
                        if ((overlaps & 0x8000u)==0) AppendPairToBuffer(node,other,added);
                    } else {
                        other->minZ=(unsigned short)index;
                    }
                    --index;
                    adjacent=cursor[-1].value;
                }
                while (bounds.low[2] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    other->minZ=(unsigned short)index;
                    --index;
                }
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[2];
                node->minZ=(unsigned short)index;
            }
            { // max_right, axis 2
                unsigned index=node->maxZ;
                SweepEnd* cursor=axes[2].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.high[2] > adjacent) {
                    *cursor=cursor[1];
                    ++index;
                    cursor+=1;
                    SweepNode* other=base+cursor->handle;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        --other->minZ;
                        if ((overlaps & 0x8000u)==0) AppendPairToBuffer(node,other,added);
                    } else {
                        --other->maxZ;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.high[2] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId || otherId==0) break;
                    ++index;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].maxZ;
                    cursor+=1;
                    --*otherIndex;
                }
                adjacent=cursor[-1].value;
                while (bounds.high[2] < adjacent) {
                    unsigned otherId=cursor[-1].handle;
                    *cursor=cursor[-1];
                    SweepNode* other=base+otherId;
                    cursor+=-1;
                    --index;
                    if (!(adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        ++other->minZ;
                        if ((overlaps & 0x8000u)==0) AppendPairEntry(node,other,&removed);
                    } else {
                        ++other->maxZ;
                    }
                    adjacent=cursor[-1].value;
                }
                while (bounds.high[2] == cursor[-1].value) {
                    unsigned otherId=cursor[-1].handle;
                    if (id >= otherId) break;
                    --index;
                    *cursor=cursor[-1];
                    unsigned short* otherIndex=&base[otherId].maxZ;
                    cursor+=-1;
                    ++*otherIndex;
                }
                node->maxZ=(unsigned short)index;
                cursor->value=(unsigned short)bounds.high[2];
                cursor->handle=(unsigned short)id;
            }
            { // min_right, axis 2
                unsigned index=node->minZ;
                SweepEnd* cursor=axes[2].data+index;
                unsigned adjacent=cursor[1].value;
                while (bounds.low[2] > adjacent) {
                    unsigned otherId=cursor[1].handle;
                    SweepNode* other=base+otherId;
                    *cursor=cursor[1];
                    cursor+=1;
                    ++index;
                    if ((adjacent&1)) {
                        unsigned short overlaps = other->maxX-node->minX;
                        overlaps |= node->maxX-other->minX;
                        overlaps |= other->maxY-node->minY;
                        overlaps |= node->maxY-other->minY;

                        --other->maxZ;
                        if ((overlaps & 0x8000u)==0) AppendPairEntry(node,other,&removed);
                    } else {
                        --other->minZ;
                    }
                    adjacent=cursor[1].value;
                }
                while (bounds.low[2] == cursor[1].value) {
                    unsigned otherId=cursor[1].handle;
                    if (id <= otherId) break;
                    *cursor=cursor[1];
                    unsigned short* otherIndex=&base[otherId].minZ;
                    cursor+=1;
                    --*otherIndex;
                    ++index;
                }
                node->minZ=(unsigned short)index;
                cursor->handle=(unsigned short)id;
                cursor->value=(unsigned short)bounds.low[2];
            }
}
}  // namespace fnv_00d175f0

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

// Removes the listed boxes by moving the last boxes into their slots, calls FUN_00d138a0 and FUN_00d13620, and remaps node index arrays.
// @fnv 0x00d193e0
// src: HAVOK_LIB 0x00d193e0
void hkp3AxisSweep::removeObjectBatch(RemovedHandleList* apRemoved, int arg2)
{
    int count = apRemoved->count;
    int total = reinterpret_cast<Arr<Box>&>(m_kNodeCollection).size;
    Box* current=0;
    Box* data=0;
    int marker = 0;
    unsigned capA; int sizeA = count + 1;
    Box* pSortedBoxes = AllocateBuffer<Box>(sizeA, capA);
    __declspec(align(16)) Box L = reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data[apRemoved->items[0]->idx];
    {
        unsigned capB; int sizeB = count + 4;
    Key* pSortKeys; IAlloc* allocatorB=GetHeap()->temp;
        if (sizeB) { int request=sizeB*4;
            pSortKeys=(Key*)allocatorB->Alloc(request);
            sizeB=request/4;
        } else { pSortKeys=0; }
        capB=sizeB?sizeB:0x80000000;
        
        for (int i = 0; i < count; ++i) {
            int idx = apRemoved->items[i]->idx;
            Box& b = reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data[idx];
            pSortKeys[i].idx = idx;
            pSortKeys[i].key = b.loZ;
            unsigned short loZ = b.loZ; if (L.loZ >= loZ) L.loZ = loZ;
            if (L.lo0 >= b.lo0) L.lo0 = b.lo0;
            if (L.lo1 >= b.lo1) L.lo1 = b.lo1;
            if (L.hiZ <= b.hiZ) L.hiZ = b.hiZ;
            if (L.hi0 <= b.hi0) L.hi0 = b.hi0;
            if (L.hi1 <= b.hi1) L.hi1 = b.hi1;
        }
        unsigned capC; int sizeC = count + 4;
    Key* pScratch = AllocateBuffer<Key>(sizeC, capC);
        pSortKeys[count].key = 0xffff;
        pSortKeys[count + 1].key = 0xffff;
        pSortKeys[count + 2].key = 0xffff;
        hkRadixSort_sort16(pSortKeys, (count + 3) & ~3, pScratch);
        for (int i = 0; i < count; ++i) {
            Box& b = reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data[pSortKeys[i].idx];
            pSortedBoxes[i].CopyPacked(b);
            *b.ref = 0;
            b.ref = &marker;
        }
        pSortedBoxes[count].loZ = 0xffff;
        FreeBuffer(pScratch, capC);
        FreeBuffer(pSortKeys, capB);
    }
    Arr<int> D;
    D.data = 0; D.size = 0; D.cap = 0x80000000;
    int reserve = m_iMarkerCount + count;
    Heap* heap = GetHeap();
    if ((int)(D.cap & 0x3fffffff) < reserve)
        hkArrayUtil__reserve(heap->temp, &D, reserve, 4);
    unsigned capE; int sizeE = total;
    Arr<int> view;
    view.data = AllocateBuffer<int>(sizeE, capE);
    int* E = view.data;
    view.size = sizeE; view.cap = capE;
    int iOverlapCount = 0;
    unsigned capG; int sizeG = total - count + 4;
    Key* pOverlapKeys = AllocateBuffer<Key>(sizeG, capG);
    int last = total - 1;
    E[0] = 0;
    for (int i = 1; i <= last; ++i) {
        data = &reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data[0];
        current=data+i;
        if (data[last].ref == &marker) {
            E[last] = -1;
            --last;
            --i;
            continue;
        }
        if (current->ref == &marker) {
            current->CopyPacked(data[last]);
            E[last]=i; E[i]=-1; --last; constructWithCopy(D.data + D.size, 1, i);
            ++D.size;
            int* r = current->ref;
            if (!((unsigned)r & 1)) {
                *r = i;
            } else {
                *(unsigned short*)((char*)reinterpret_cast<::Node*>(unkD8) + ((unsigned)r & ~1u)) = (unsigned short)i;
                continue;
            }
        } else {
            E[i] = i;
        }
        Box& b=*current;
        if (0 == (((b.hi01 - L.lo01) | (L.hi01 - b.lo01)) & 0x80008000)) {
            unsigned short lo = b.loZ;
            unsigned short t = b.hi0 - L.lo0;
            t |= b.hiZ - L.loZ;
            t |= L.hi0 - b.lo0;
            t |= L.hiZ - lo;
            if ((t & 0x8000) == 0) {
                pOverlapKeys[iOverlapCount].key = lo;
                pOverlapKeys[iOverlapCount].idx = i;
                ++iOverlapCount;
            }
        }
    }
    reinterpret_cast<Arr<Box>&>(m_kNodeCollection).SetSize(last + 1);
    unsigned capret; int sizeret = iOverlapCount + 1;
    Box* pOverlapBoxes = AllocateBuffer<Box>(sizeret, capret);
    {
        unsigned capI; int sizeI = iOverlapCount + 4;
    Key* pOverlapScratch = AllocateBuffer<Key>(sizeI, capI);
        pOverlapKeys[iOverlapCount].key = 0xffff;
        pOverlapKeys[iOverlapCount + 1].key = 0xffff;
        pOverlapKeys[iOverlapCount + 2].key = 0xffff;
        hkRadixSort_sort16(pOverlapKeys, (iOverlapCount + 3) & ~3, pOverlapScratch);
        for (int j = 0; j < iOverlapCount; ++j)
            { Box& b=reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data[pOverlapKeys[j].idx];
            pOverlapBoxes[j].CopyPacked(b); }
        pOverlapBoxes[iOverlapCount].loZ = 0xffff;
        FreeBuffer(pOverlapScratch, capI);
    }
    CollectNodePairs(this, pSortedBoxes, count, arg2);
    BuildBroadPhasePairs(reinterpret_cast<hkp3AxisSweep::Node*>(pSortedBoxes), count, reinterpret_cast<hkp3AxisSweep::Node*>(pOverlapBoxes), iOverlapCount, 1, *reinterpret_cast<BroadPhasePairArray*>(arg2));
    reinterpret_cast<Stub_00d1a040&>(m_axis0).hkp3AxisSweep_hkpBpAxis_removeBatch_0(reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data, &view);
    reinterpret_cast<Stub_00d1a0e0&>(m_axis1).hkp3AxisSweep_hkpBpAxis_removeBatch_1(reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data, &view);
    reinterpret_cast<Stub_00d1a180&>(m_axis2).RemapEndPoints(reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data, &view);
    if (m_iMarkerCount) {
        int twoN = count + count;
        for (int k = 0; k < m_iMarkerCount; ++k) {
            ::Node* nd = &reinterpret_cast<::Node*>(unkD8)[k];
            Box& b = reinterpret_cast<Arr<Box>&>(m_kNodeCollection).data[nd->idx];
            b.hi0 -= twoN;
            b.hi1 -= twoN;
            int cnt = 0;
            for (int j = 0; j < nd->arr.size; ++j) {
                int v = E[nd->arr.data[j]];
                if (v >= 0) nd->arr.data[cnt++] = v;
            }
            nd->arr.SetSize(cnt);
        }
    }
    for (int i = 0; i < D.size; ++i) FixNodeEdges(D.data[i]);
    FreeBuffer(pOverlapBoxes, capret);
    FreeBuffer(pOverlapKeys, capG);
    FreeBuffer(E, capE);
    GetHeap()->ReleaseTemp(D);
    FreeBuffer(pSortedBoxes, capA);
}
