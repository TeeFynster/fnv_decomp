
// src/havok/physics/collide/query/collector/pointcollector/hkpallcdpointcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/pointcollector/hkpallcdpointcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00caba90_array
{
    void* data;
    unsigned int count;
    unsigned int capacity;
};
struct FUN_006212c0_shell
{
    void* InitializeFields_006212c0(void* source);
};
void* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* manager, void* array, int itemSize);
struct FUN_00caba90_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00caba90_array array;
    void* AppendItem(void* source);
};
// @fnv 0x00caba90
void* FUN_00caba90_Class::AppendItem(void* source)
{
    FUN_00caba90_array* items = &array;
    void* manager = hkMemoryRouter_getInstance();
    if (items->count == (items->capacity & 0x3fffffff))
    {
        void* allocator = *(void**)((char*)manager + 0x10);
        ResizeAudioStream(allocator, items, 0x70);
    }
    unsigned int index = items->count;
    char* item = (char*)items->data + index * 0x70;
    items->count = index + 1;
    return ((FUN_006212c0_shell*)item)->InitializeFields_006212c0(source);
}

struct ByteTag
{
    char m_cValue;

    ByteTag() : m_cValue(0)
    {}

    ~ByteTag()
    {}
};

void __cdecl hkAlgorithm_quickSortRecursive_hkpRootCdPoint_hkAlgorithm_less_hkpRootCdPoint(void* apData, int aiFirst, int aiLast, ByteTag akTag);

struct SortableArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pData;
    int m_iArrayLength;

    void hkpAllCdPointCollector_sortHits();
};

// @fnv 0x00cabad0
// src: XBOX_PDB 0x00cabad0
void SortableArray::hkpAllCdPointCollector_sortHits()
{
    ByteTag kTag;
    if (m_iArrayLength > 1)
        hkAlgorithm_quickSortRecursive_hkpRootCdPoint_hkAlgorithm_less_hkpRootCdPoint(m_pData, 0, m_iArrayLength - 1, kTag);
}

#include <xmmintrin.h>
struct S_00cab970_Heap
{
    int unk00;
};
struct S_00cab970_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cab970_Heap* heap;
};
void* __cdecl hkMemoryRouter_getInstance();
struct S_00cab970_Vec
{
    __m128 q;
};
struct S_00cab970_Cd
{
    int unk00;
    unsigned int key;
    int unk08;
    S_00cab970_Cd* parent;
};
struct S_00cab970_Src
{
    S_00cab970_Vec a;
    S_00cab970_Vec b;
    S_00cab970_Cd* bodyA;
    S_00cab970_Cd* bodyB;
};
struct S_00cab970_Entry
{
    S_00cab970_Vec a;
    S_00cab970_Vec b;
    S_00cab970_Cd* rootA;
    unsigned int keyA;
    unsigned int keysA[8];
    S_00cab970_Cd* rootB;
    unsigned int keyB;
    unsigned int keysB[8];
};
struct S_00cab970_Arr;
void __cdecl ResizeAudioStream(S_00cab970_Heap* heap, S_00cab970_Arr* arr, int elemSize);
struct S_00cab970_Arr
{
    S_00cab970_Entry* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline S_00cab970_Entry& AllocatePair()
    {
        S_00cab970_Router* r = (S_00cab970_Router*)hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->heap, this, sizeof(S_00cab970_Entry));
        return m_data[m_iElementCount++];
    }
};
__forceinline void S_00cab970_Path(S_00cab970_Cd* const volatile& body, S_00cab970_Cd*& rootOut, unsigned int& keyOut,
                                   unsigned int* keys)
{
    S_00cab970_Cd* root = body;
    while (root->parent)
        root = root->parent;
    rootOut = root;
    keyOut = body->key;
    int depth = 0;
    S_00cab970_Cd* p = body->parent;
    while (p)
    {
        depth++;
        p = p->parent;
    }
    int n = depth;
    S_00cab970_Cd* c = body;
    keys[n--] = 0xffffffff;
    if (n >= 0)
    {
        unsigned int* k = keys + n;
        do
        {
            *k = c->key;
            c = c->parent;
            --n;
            --k;
        } while (n >= 0);
    }
}
struct S_00cab970_Cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cab970_Arr arr;
    void hkpAllCdPointCollector_addCdPoint(const S_00cab970_Src* src);
};
// Allocates an entry in arr, copies the two vectors from src, and records the root, key, and key path for each body via S_00cab970_Path.
// @fnv 0x00cab970
// src: XBOX_PDB 0x00cab970
void S_00cab970_Cls::hkpAllCdPointCollector_addCdPoint(const S_00cab970_Src* src)
{
    S_00cab970_Entry& entry = arr.AllocatePair();
    entry.a.q = src->a.q;
    entry.b.q = src->b.q;
    S_00cab970_Path(src->bodyA, entry.rootA, entry.keyA, entry.keysA);
    S_00cab970_Path(src->bodyB, entry.rootB, entry.keyB, entry.keysB);
}
