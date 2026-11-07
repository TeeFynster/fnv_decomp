
// src/havok/common/base/container/array/hkarrayutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/array/hkarrayutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"

typedef unsigned __int64 CB1BC0Key;

struct CB1BC0MapOperations
{
    static unsigned hash(CB1BC0Key key, unsigned mod)
    {
        return (unsigned(key) >> 4) * 2654435761U & mod;
    }
    static bool isValid(CB1BC0Key key)
    {
        return key != CB1BC0Key(-1);
    }
    static bool equal(CB1BC0Key key0, CB1BC0Key key1)
    {
        return key0 == key1;
    }
};

struct CB1BC0Pair
{
    CB1BC0Key key;
    CB1BC0Key val;
};

struct CB1BC0Map
{
    CB1BC0Pair* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    void ResizeStorage(hkMemoryAllocator& alloc, int capacity);
    int InsertKeyValue(hkMemoryAllocator& alloc, CB1BC0Key key, CB1BC0Key val);
};

// Grows the table if needed, probes for the key, stores key/val, and returns whether the key was newly inserted.
// @fnv 0x00cb1bc0
int CB1BC0Map::InsertKeyValue(hkMemoryAllocator& alloc, CB1BC0Key key, CB1BC0Key val)
{
    {
        int iCount = m_iCapacityFlags & 0x7fffffff;
        if ((iCount + iCount) > m_iPairCount)
            ResizeStorage(alloc, m_iPairCount + m_iPairCount + 2);
    }

    unsigned i;
    int isNewKey = true;
    for (i = CB1BC0MapOperations::hash(key, m_iPairCount); CB1BC0MapOperations::isValid(m_kPrimitiveElement[i].key);
         i = (i + 1) & m_iPairCount)
    {
        if (CB1BC0MapOperations::equal(m_kPrimitiveElement[i].key, key))
        {
            isNewKey = false;
            break;
        }
    }

    m_iCapacityFlags += isNewKey;

    m_kPrimitiveElement[i].key = key;
    m_kPrimitiveElement[i].val = val;
    return isNewKey;
}

struct SpawnedArray
{
    int m_00;
    int m_04;
    unsigned int m_08;
};

void __cdecl FUN_00ec44d0(int a, int b, int c);

// @fnv 0x00c908c0
// src: HAVOK_LIB 0x00c908c0
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* apObject, SpawnedArray* apArray, int aiSize, int stride)
{
    int iNewSize = aiSize * stride;
    if ((apArray->m_08 & 0x80000000u) == 0)
    {
        int n = (int)(apArray->m_08 & 0x3fffffffu) * stride;
        apArray->m_00 = (int)apObject->bufRealloc((void*)apArray->m_00, n, iNewSize);
        apArray->m_08 = (unsigned int)(iNewSize / stride);
    }
    else
    {
        int pNewData = (int)apObject->bufAlloc(iNewSize);
        FUN_00ec44d0(pNewData, apArray->m_00, apArray->m_04 * stride);
        apArray->m_00 = pNewData;
        apArray->m_08 = (unsigned int)(iNewSize / stride);
    }
}

// ---------------------------------------------------------------------------
// ResizeAudioStream - reserve/grow the element buffer of an audio stream.
//
// The stream keeps the element pointer at +0, the live item count at +4 and
// the capacity (plus two flag bits) at +8.  The allocator is a polymorphic
// object: slot 3 hands out a fresh block, slot 5 resizes an existing one.
// ---------------------------------------------------------------------------

struct AudioStream
{
    void* m_pData;
    int m_iArrayLength;
    int m_uCapacity;
};

extern "C" void* __cdecl FNV_block_copy(void* dst, const void* src, unsigned int size);

// @fnv 0x00c90940
void ResizeAudioStream(hkMemoryAllocator* pAlloc, AudioStream* pStream, int elemSize)
{
    int n = (pStream->m_iArrayLength ? pStream->m_iArrayLength * 2 : 1) * elemSize;
    if (!(pStream->m_uCapacity & 0x80000000))
    {
        pStream->m_pData = pAlloc->bufRealloc(pStream->m_pData, (pStream->m_uCapacity & 0x3fffffff) * elemSize, n);
        pStream->m_uCapacity = n / elemSize;
    }
    else
    {
        void* pBlock = pAlloc->bufAlloc(n);
        FNV_block_copy(pBlock, pStream->m_pData, pStream->m_iArrayLength * elemSize);
        pStream->m_pData = pBlock;
        pStream->m_uCapacity = n / elemSize;
    }
}

typedef unsigned int hkUlong;

extern void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int n, int sizeElem);
extern void __cdecl ResizeAudioStream(void* alloc, void* arr, int sizeElem);

inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}

struct S_00da2bd0_Node
{
    hkUlong m_uiFilterValue;
    int m_parent;
    int m_iFirstChild;
    int m_next;

    S_00da2bd0_Node() : m_uiFilterValue(0), m_parent(-1), m_iFirstChild(-1), m_next(-1)
    {}
};

struct S_00da2bd0_CallTree
{
    S_00da2bd0_Node* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void* m_pThreadAllocator;

    __forceinline void _setSize(void* alloc, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = cap * 2;
            hkArrayUtil__reserve(alloc, this, n < cap2 ? cap2 : n, sizeof(S_00da2bd0_Node));
        }
        int numNew = n - m_iElementCount;
        S_00da2bd0_Node* p = m_data + m_iElementCount;
        for (int i = 0; i < numNew; ++i)
        {
            new (p + i) S_00da2bd0_Node();
        }
        m_iElementCount = n;
    }

    __forceinline S_00da2bd0_Node& AllocatePair()
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(m_pThreadAllocator, this, sizeof(S_00da2bd0_Node));
        }
        new (m_data + m_iElementCount) S_00da2bd0_Node();
        return m_data[m_iElementCount++];
    }

    int __thiscall FindOrAddCallTrace(const hkUlong* trace, int depth);
};

// @fnv 0x00da2bd0
int S_00da2bd0_CallTree::FindOrAddCallTrace(const hkUlong* trace, int depth)
{
    if (m_iElementCount == 0)
    {
        _setSize(m_pThreadAllocator, 1);
    }
    int curNode = 0;
    for (int i = depth - 1; i >= 0; --i)
    {
        hkUlong ulAddress = trace[i];
        int nextNode = -1;
        int child = m_data[curNode].m_iFirstChild;
        while (child > 0)
        {
            if (m_data[child].m_uiFilterValue == ulAddress)
            {
                nextNode = child;
                break;
            }
            child = m_data[child].m_next;
        }
        if (nextNode == -1)
        {
            nextNode = m_iElementCount;
            S_00da2bd0_Node& node = AllocatePair();
            node.m_uiFilterValue = ulAddress;
            node.m_parent = curNode;
            node.m_next = m_data[curNode].m_iFirstChild;
            m_data[curNode].m_iFirstChild = nextNode;
        }
        curNode = nextNode;
    }
    return curNode;
}

struct Holder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    void* m_pAllocator;
};

Holder* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void* pAllocator, void* pBuf, int newCap, int bFlag);
void __cdecl ResizeAudioStream(void* pAllocator, void* pBuf, int bFlag);
extern "C" void _ReadWriteBarrier(void);

struct FUN_00e108b0_cls
{
    char* m_pData;
    int m_len;
    unsigned int m_cap;

    FUN_00e108b0_cls* InitializeStringBuffer();
};

// Initialises the string buffer (data, length, capacity), grows it to at least 0x40 if needed, appends a null terminator and returns this.
// @fnv 0x00e108b0
// src: GUESS 0x00e108b0 (confidence: medium)
FUN_00e108b0_cls* FUN_00e108b0_cls::InitializeStringBuffer()
{
    m_pData = 0;
    m_len = 0;
    m_cap = 0x80000000u;

    Holder* h = hkMemoryRouter_getInstance();
    void* alloc = h->m_pAllocator;
    int cap = (int)(m_cap & 0x3fffffffu);
    if (cap < 0x40)
    {
        int newCap = cap + cap;
        if (newCap <= 0x40)
        {
            newCap = 0x40;
        }
        hkArrayUtil__reserve(alloc, this, newCap, 1);
    }

    h = hkMemoryRouter_getInstance();
    if ((unsigned int)m_len == (m_cap & 0x3fffffffu))
    {
        ResizeAudioStream(h->m_pAllocator, this, 1);
    }

    char* pEnd = m_pData + m_len;
    _ReadWriteBarrier();
    *pEnd = 0;
    m_len++;
    return this;
}

#include <xmmintrin.h>
extern __declspec(thread) int g_tlsMemContext;

// local form of hkVector4: 0x00c70de0 needs the trivial copy/default form and reference-returning assignment (shared form: 1042 bytes, exe: 828).
struct __declspec(align(16)) ArrayVectorLocal_00c70de0
{
    char storage[16];
    __forceinline float& component(unsigned i)
    {
        return reinterpret_cast<float*>(storage)[i];
    }
    __forceinline ArrayVectorLocal_00c70de0& operator=(const ArrayVectorLocal_00c70de0& other)
    {
        *reinterpret_cast<__m128*>(storage) = *reinterpret_cast<const __m128*>(other.storage);
        return *this;
    }
};

struct S00c70de0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S00c70de0_Router* __cdecl S00c70de0_getInstance();

int __cdecl CreateFromSource(void* arr);

extern "C" float DAT_01267bcc;
extern "C" double DAT_0101ffa0;
extern "C" double DAT_01011588;
extern "C" float DAT_011b0154[];
extern "C" float DAT_011b0174[];

struct S00c70de0_Guard
{
    int m_oldContext;
    __forceinline S00c70de0_Guard(int newContext)
    {
        m_oldContext = g_tlsMemContext;
        g_tlsMemContext = newContext;
    }
    __forceinline ~S00c70de0_Guard()
    {
        g_tlsMemContext = m_oldContext;
    }
};

struct S00c70de0_ArrayLocalForm
{ // local form of hkArray: 0x00c70de0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    ArrayVectorLocal_00c70de0* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline S00c70de0_ArrayLocalForm()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& a, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = cap * 2;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&a, this, newSize, sizeof(ArrayVectorLocal_00c70de0));
        }
    }
    __forceinline void reserve(int n)
    {
        GrowArrayCapacity(S00c70de0_getInstance()->heap(), n);
    }

    __forceinline void _pushBack(hkMemoryAllocator& a, const ArrayVectorLocal_00c70de0& val)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&a, this, sizeof(ArrayVectorLocal_00c70de0));
        }
        m_data[m_iElementCount] = val;
        m_iElementCount++;
    }
    __forceinline void AddBack(const ArrayVectorLocal_00c70de0& val)
    {
        _pushBack(S00c70de0_getInstance()->heap(), val);
    }

    __forceinline void _clearAndDeallocate(hkMemoryAllocator& a)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            a.bufFree(m_data, getCapacity() * sizeof(ArrayVectorLocal_00c70de0));
        }
    }
    __forceinline ~S00c70de0_ArrayLocalForm()
    {
        _clearAndDeallocate(S00c70de0_getInstance()->heap());
    }
};

// Builds 18 vertices using scaled start coordinates, end z, radius, and height, then passes them to CreateFromSource.
// @fnv 0x00c70de0
// src: XBOX_PDB 0x00c70de0
int __cdecl MakeConvex(float* end, float* start, float radius, float height)
{
    S00c70de0_Guard memGuard(16);
    float fScaledRadius = radius * DAT_01267bcc;
    S00c70de0_ArrayLocalForm mesh;
    mesh.reserve(18);

    ArrayVectorLocal_00c70de0 vertex;
    ArrayVectorLocal_00c70de0 ringVertex;
    vertex.component(0) = start[0] * DAT_01267bcc;
    vertex.component(1) = start[1] * DAT_01267bcc;
    vertex.component(2) = start[2] * DAT_01267bcc;
    vertex.component(3) = 0.0f;
    vertex.component(2) -= fScaledRadius;
    {
        hkMemoryAllocator& a = S00c70de0_getInstance()->heap();
        if (mesh.m_iElementCount == mesh.getCapacity())
        {
            ResizeAudioStream(&a, &mesh, sizeof(ArrayVectorLocal_00c70de0));
        }
        double fTopZ = height + DAT_0101ffa0 + vertex.component(2);
        mesh.m_data[mesh.m_iElementCount] = vertex;
        mesh.m_iElementCount++;
        vertex.component(2) = (float)fTopZ;
    }
    for (unsigned int i = 0; i < 8; ++i)
    {
        ringVertex = vertex;
        ringVertex.component(0) += fScaledRadius * DAT_011b0154[i];
        ringVertex.component(1) += fScaledRadius * DAT_011b0174[i];
        mesh.AddBack(ringVertex);
    }

    vertex.component(0) = end[0] * DAT_01267bcc;
    vertex.component(1) = end[1] * DAT_01267bcc;
    vertex.component(2) = end[2] * DAT_01267bcc;
    vertex.component(3) = 0.0f;

    double halfRadius = fScaledRadius * DAT_01011588;
    vertex.component(2) += halfRadius;

    for (unsigned int i = 0; i < 8; ++i)
    {
        ringVertex = vertex;
        ringVertex.component(0) = fScaledRadius * DAT_011b0154[i];
        ringVertex.component(1) = fScaledRadius * DAT_011b0174[i];
        mesh.AddBack(ringVertex);
    }
    vertex.component(2) += halfRadius;
    mesh.AddBack(vertex);

    return CreateFromSource(&mesh);
}

namespace fnv_00c909d0 {
struct hkArrayVoid
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

extern "C" void* __cdecl memcpy(void*, const void*, size_t);

// Reallocates an hkArrayVoid buffer to requestedCapacity, reusing inplaceMem when provided, otherwise calling BufRealloc on the allocator.
// @fnv 0x00c909d0
// src: HAVOK_LIB 0x00c909d0
void __cdecl hkArrayUtil__reduce(hkMemoryAllocator& alloc, void* array, int aiElementSize, void* apInPlaceMemory,
                          int requestedCapacity)
{
    hkArrayVoid& arr = *static_cast<hkArrayVoid*>(array);
    if (apInPlaceMemory && arr.m_iElementCount < requestedCapacity)
    {
        memcpy(apInPlaceMemory, arr.m_data, arr.m_iElementCount * aiElementSize);
        alloc.bufFree(arr.m_data, (arr.m_iCapacityState & 0x3fffffff) * aiElementSize);
        arr.m_iCapacityState = requestedCapacity | 0x80000000;
        arr.m_data = apInPlaceMemory;
    }
    else
    {
        int iRequestedBytes = requestedCapacity * aiElementSize;
        arr.m_data = alloc.bufRealloc(arr.m_data, arr.m_iCapacityState * aiElementSize, iRequestedBytes);
        arr.m_iCapacityState = iRequestedBytes / aiElementSize;
    }
}
}  // namespace fnv_00c909d0

// Adapted from another contributor's verified-close draft (chk_8b483addbe354a1f8074),
// merged onto the current pack unit (real __m128 from <xmmintrin.h>).

static __forceinline hkMemoryAllocator* getMeshAllocator()
{
    Holder* holder = hkMemoryRouter_getInstance();
    return (hkMemoryAllocator*)holder->unk10;
}

struct MeshVertex
{
    __m128 quad;
    __forceinline MeshVertex()
    {}
    __forceinline MeshVertex(const MeshVertex& o)
    {
        quad = o.quad;
    }
    __forceinline void operator=(const MeshVertex& o)
    {
        quad = o.quad;
    }
};
struct MeshTriangle
{
    int a, b, c, material;
};

static __forceinline void copyRange(MeshVertex* dst, const MeshVertex* src, int n)
{
    for (int i = 0; i < n; ++i)
        dst[i].quad = src[i].quad;
}
template <class T> struct MeshArray
{

    T* data;
    int size;
    int cap;
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }

    __forceinline void reserve(hkMemoryAllocator* a, int n)
    {

        int old = cap & 0x3fffffff;

        if (old < n)
            hkArrayUtil__reserve(a, this, n < old * 2 ? old * 2 : n, sizeof(T));
    }

    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(getMeshAllocator(), n);
        size = n;
    }

    __forceinline void reset()
    {

        hkMemoryAllocator* a = getMeshAllocator();

        size = 0;

        if ((cap & 0x80000000) == 0)
            a->bufFree(data, (cap & 0x3fffffff) * sizeof(T));

        data = 0;
        cap = 0x80000000;
    }

    __forceinline void destroy()
    {
        hkMemoryAllocator* a = getMeshAllocator();
        size = 0;
        if ((cap & 0x80000000) == 0)
            a->bufFree(data, (cap & 0x3fffffff) * sizeof(T));
    }
    __forceinline void copyFrom(const MeshArray& other)
    {

        hkMemoryAllocator* a = getMeshAllocator();

        if ((cap & 0x3fffffff) < other.size)
        {

            if ((cap & 0x80000000) == 0)
                a->bufFree(data, (cap & 0x3fffffff) * sizeof(T));

            int bytes = other.size * sizeof(T);
            data = (T*)a->bufAlloc(bytes);
            cap = bytes / int(sizeof(T));
        }

        size = other.size;

        copyRange(data, other.data, other.size);
    }
};

struct ScriptProgram
{
    MeshArray<MeshVertex> vertices;
    MeshArray<MeshTriangle> triangles;
};

struct MeshBool
{
    char value;
    __forceinline MeshBool(bool b)
    {
        value = (char)b;
    }
    __forceinline operator bool() const
    {
        return value != 0;
    }
};

__declspec(noinline) MeshBool __cdecl CheckDuplicateValues(const MeshTriangle& tri)
{
    return MeshBool(tri.a == tri.b || tri.a == tri.c || tri.b == tri.c);
}

void __cdecl hkMemoryRouter_getInstance_ProcessEntries_00da0f10(ScriptProgram*, MeshArray<MeshVertex>*, MeshArray<int>*, float);

// @fnv 0x00da12b0
// src: GUESS 0x00da12b0 (confidence: low)
void __cdecl hkMemoryAllocator_ProcessEntries_00da12b0(ScriptProgram* mesh, float tolerance, bool unique, MeshArray<int>* vertexMap,
                          MeshArray<int>* triangleMap)
{

    int count = mesh->triangles.size;

    vertexMap->SetSizeAndGrow(mesh->vertices.size);

    MeshArray<MeshVertex> vertices = {0, 0, 0x80000000};

    hkMemoryRouter_getInstance_ProcessEntries_00da0f10(mesh, &vertices, vertexMap, tolerance);

    if (unique)
    {

        MeshArray<MeshVertex> compact = {0, 0, 0x80000000};

        MeshArray<int> mapping = {0, 0, 0x80000000};

        int n = vertices.size;

        mapping.reserve(getMeshAllocator(), n);

        int* end = mapping.data + mapping.size;

        for (int i = n - mapping.size; i > 0; --i)
            *end++ = -1;

        mapping.size = n;

        for (int i = 0; i < vertexMap->size; ++i)
        {

            int idx = vertexMap->data[i];

            int dest = mapping.data[idx];

            if (dest == -1)
            {

                dest = compact.size;
                mapping.data[idx] = dest;

                const MeshVertex& v = vertices.data[idx];

                hkMemoryAllocator* a = getMeshAllocator();

                if (compact.size == (compact.cap & 0x3fffffff))
                    ResizeAudioStream(a, &compact, sizeof(MeshVertex));

                _mm_store_ps(reinterpret_cast<float*>(&compact.data[compact.size]), v.quad);
                ++compact.size;
            }

            vertexMap->data[i] = dest;
        }

        mesh->vertices.copyFrom(compact);

        mapping.reset();
        compact.reset();
    }
    else
        mesh->vertices.copyFrom(vertices);

    vertices.destroy();

    for (int i = 0; i < count; ++i)
    {

        MeshTriangle& t = mesh->triangles.data[i];

        t.a = vertexMap->data[t.a];
        t.b = vertexMap->data[t.b];
        t.c = vertexMap->data[t.c];
    }

    triangleMap->SetSizeAndGrow(count);

    MeshTriangle* dest = mesh->triangles.begin();

    for (int i = 0; i < count; ++i)
    {

        MeshTriangle& tri = mesh->triangles[i];

        int newIndex = -1;

        if (!CheckDuplicateValues(tri))
        {
            newIndex = dest - mesh->triangles.begin();
            *dest = tri;
            dest++;
        }

        triangleMap->data[i] = newIndex;
    }

    mesh->triangles.SetSizeAndGrow(dest - mesh->triangles.begin());
}
