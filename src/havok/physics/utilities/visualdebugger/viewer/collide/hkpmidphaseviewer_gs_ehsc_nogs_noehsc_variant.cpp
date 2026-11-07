
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#define FNV_VEC4_SIMD
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkpMidphaseViewer.h"
#include "../../../../../../../include/hkpShape.h"

inline hkAabb::hkAabb() {}


hkMemoryRouter* hkMemoryRouter_getInstance() throw();

template <class T> __forceinline void hkArrayUtil_destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

#include <xmmintrin.h>
struct EventStamp {
    const void* marker;
    unsigned tick;
    unsigned unk08;
};
struct EventSample {
    const void* marker;
    unsigned tick;
};
struct EventStorage {
    unsigned unk00;
    EventStamp* m_next;
    unsigned unk08;
    EventStamp* m_pFreeList;
};
extern unsigned long DAT_0126835c;
extern char DAT_010d233c[];
extern char DAT_010c41f8[];
extern void* DAT_01269024;
extern const float DAT_01011d78;
extern const __m128 DAT_010c7170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

static __forceinline void TimerMark(char* marker)
{
    EventStorage* s = (EventStorage*)TlsGetValue(DAT_0126835c);
    EventStamp* next = s->m_next;
    if (next < s->m_pFreeList) {
        next->marker = marker;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        next->tick = ticks;
        s->m_next = next + 1;
    }
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* arr, int newSize, int elemSize);
struct __declspec(align(16)) UInt4 {
    unsigned x, y, z, w;
};
static __forceinline void SetVec(Vec4& v,float x,float y,float z,float w) { *(__m128*)&v=_mm_setr_ps(x,y,z,w); }
struct QuantizedBounds { UInt4 min; UInt4 max; };
struct Elem80 {
    virtual ~Elem80();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    void FUN_00de1210();
    void hkDisplayAABB_setExtents(const Vec4& a, const Vec4& b);
};
struct ListEntry {
    int m_00;
    int m_04;
    int m_08;
    unsigned char b0c;
    unsigned char b0d;
    unsigned char b0e;
    unsigned char b0f;
    int m_10;
    int m_14;
    int m_18;
    unsigned char b1c;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
static __forceinline void Decode(const ListEntry* list, QuantizedBounds& quantized) {
    unsigned cl = list->b0f;
    quantized.min.x = list->m_00 - (int)(list->b0c << cl);
    quantized.min.y = list->m_04 - (int)(list->b0d << cl);
    quantized.min.z = list->m_08 - (int)(list->b0e << cl);
    quantized.max.x = (int)(list->b1c << cl) + list->m_10;
    quantized.max.y = (int)(list->b1d << cl) + list->m_14;
    quantized.max.z = (int)(list->b1e << cl) + list->m_18;
}
struct Node {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    unsigned short m_uiItemCount;
    unsigned short unk22;
    ListEntry* m_kNode;
    int unk28;
    int unk2c;
};
struct SubEntry {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Node m_node;
};
struct PtrArray {
    void** m_data;
    int m_iElementCount;
    unsigned int m_cap;
};
struct Entry {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
    PtrArray m_sub;
    int unk54;
    int unk58;
    int unk5c;
};
struct Param {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24;
    PtrArray m_arrs[2];
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74;
    float* m_matrix;
};
struct ParamRef {
    Param* p;
    __forceinline Param* operator->() const { return p; }
};
struct ElemArray {
    Elem80* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct PtrArrayLocal {
    Elem80** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
static __forceinline Elem80** AllocatePointers(hkMemoryAllocator& alloc, int& count)
{
    if (count) {
        int bytes = count * 4;
        Elem80** result = (Elem80**)alloc.bufAlloc(bytes);
        count = bytes / 4;
        return result;
    }
    return 0;
}
struct Dispatch {
    virtual ~Dispatch();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void FUN_dispatch(PtrArrayLocal* arr, int a, int b, void* c);
};
struct Self {
    int unk00;
    ElemArray m_aiIndexedValues;
    int unk14;
    int unk18;
    int unk1c;
    void hkpMidphaseViewer_postSimulationCallback(Param* apParam);
};

struct ViewerPrefix { Dispatch* m_dispatch; int unk04; int unk08; int unk0c; };
struct Viewer : ViewerPrefix, Self {};

// @fnv 0x00d6a2f0
// src: XBOX_PDB 0x00d6a2f0
void Self::hkpMidphaseViewer_postSimulationCallback(Param* apParam)
{
    TimerMark(DAT_010d233c);
    hkArrayUtil_destruct(m_aiIndexedValues.m_data, m_aiIndexedValues.m_iElementCount);
    m_aiIndexedValues.m_iElementCount = 0;
    PtrArray* arr = &apParam->m_arrs[0];
    int passes = 2;
    do {
        int ai = 0;
        if (arr->m_iElementCount > 0) {
            do {
                Entry* entry = (Entry*)arr->m_data[ai];
                PtrArray* sub = &entry->m_sub;
                int bi = 0;
                if (sub->m_iElementCount > 0) {
                    do {
                        SubEntry* se = (SubEntry*)sub->m_data[bi];
                        Node* node = &se->m_node;
                        ListEntry* list = node->m_kNode;
                        if (list) {
                            int k = 0;
                            if ((unsigned short)k < node->m_uiItemCount) {
                                do {
                                    float* mat = apParam->m_matrix + 8;
                                    __declspec(align(16)) hkAabb bounds;
                                    QuantizedBounds quantized;
                                    Decode(list,quantized);
                                    float f0 = (float)quantized.min.x;
                                    float f1 = (float)quantized.min.y;
                                    float f2 = (float)quantized.min.z;
                                    *(__m128*)&bounds.m_kMinimumCorner.x = _mm_setr_ps(f0,f1,f2,0.0f);
                                    float f3 = (float)quantized.max.x;
                                    float f4 = (float)quantized.max.y;
                                    float f5 = (float)quantized.max.z;
                                    SetVec(*reinterpret_cast<Vec4*>(&bounds.m_kMaximumCorner.x),f3,f4,f5,0.0f);
                                    __m128 row1 = _mm_load_ps(mat + 8);
                                    __m128 t = _mm_shuffle_ps(row1, _mm_unpackhi_ps(row1, DAT_010c7170), 0xc4);
                                    __m128 r = _mm_rcp_ps(t);
                                    __m128 inv = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, t), r));
                                    *(__m128*)&bounds.m_kMinimumCorner.x = _mm_mul_ps(*(__m128*)&bounds.m_kMinimumCorner.x, inv);
                                    *(__m128*)&bounds.m_kMaximumCorner.x = _mm_mul_ps(*(__m128*)&bounds.m_kMaximumCorner.x, inv);
                                    *(__m128*)&bounds.m_kMinimumCorner.x = _mm_sub_ps(*(__m128*)&bounds.m_kMinimumCorner.x, _mm_load_ps(mat));
                                    *(__m128*)&bounds.m_kMaximumCorner.x = _mm_sub_ps(*(__m128*)&bounds.m_kMaximumCorner.x, _mm_load_ps(mat));
                                    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
                                    ElemArray* output = &m_aiIndexedValues;
                                    int oldSize = output->m_iElementCount;
                                    int newSize = oldSize + 1;
                                    if ((output->m_iCapacityState & 0x3fffffff) < newSize) {
                                        int dbl = (output->m_iCapacityState & 0x3fffffff) * 2;
                                        if (newSize < dbl) newSize = dbl;
                                        hkArrayUtil__reserve(&alloc, output, newSize, 0x80);
                                    }
                                    Elem80* elem = &output->m_data[output->m_iElementCount];
                                    if (elem) elem->FUN_00de1210();
                                    output->m_iElementCount++;
                                    output->m_data[oldSize].hkDisplayAABB_setExtents(*reinterpret_cast<const Vec4*>(&bounds.m_kMinimumCorner.x),
                                                                      *reinterpret_cast<const Vec4*>(&bounds.m_kMaximumCorner.x));
                                    k++;
                                    list++;
                                } while (k < node->m_uiItemCount);
                            }
                        }
                        bi++;
                    } while (bi < sub->m_iElementCount);
                }
                ai++;
            } while (ai < arr->m_iElementCount);
        }
        arr = &apParam->m_arrs[1];
        passes--;
    } while (passes != 0);

    int count = m_aiIndexedValues.m_iElementCount;
    int allocatedCount = count;
    PtrArrayLocal indices;
    indices.m_data = 0;
    indices.m_iElementCount = 0;
    indices.m_iCapacityState = 0x80000000;
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
    Elem80** buf = AllocatePointers(alloc, allocatedCount);
    int capacity = allocatedCount ? allocatedCount : (int)0x80000000;
    indices.m_data = buf;
    indices.m_iElementCount = allocatedCount;
    indices.m_iCapacityState = capacity;
    hkMemoryAllocator& alloc2 = hkMemoryRouter_getInstance()->heap();
    if ((indices.m_iCapacityState & 0x3fffffff) < count) {
        int ns = (indices.m_iCapacityState & 0x3fffffff) * 2;
        if (count >= ns) ns = count;
        hkArrayUtil__reserve(&alloc2, &indices, ns, 4);
    }
    indices.m_iElementCount = count;
    for (int i = 0; i < count; i++) {
        indices.m_data[i] = &m_aiIndexedValues.m_data[i];
    }
    Dispatch* disp = static_cast<Viewer*>(this)->m_dispatch;
    disp->FUN_dispatch(&indices, -0x5b00, 0, DAT_01269024);
    TimerMark(DAT_010c41f8);
    hkMemoryAllocator& cleanupAlloc = hkMemoryRouter_getInstance()->heap();
    indices.m_iElementCount = 0;
    if ((indices.m_iCapacityState & 0x80000000u) == 0)
        cleanupAlloc.bufFree(indices.m_data, (indices.m_iCapacityState & 0x3fffffff) * 4);
    return;
}
