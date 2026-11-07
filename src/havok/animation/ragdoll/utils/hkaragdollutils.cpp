#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkErrStream.h"
#include "../../../../../include/hkError.h"
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../../../../include/hkQuaternion.h"
// Keep the unit's original SIMD lane types: the extra integer lanes in the
// compiler header change alias analysis across quaternion calls.
#define _INCLUDED_MM2
// Exe 0x00ce9880 FUN_00ce9880: retain this LocalM128 view; the CRT type does not reproduce this function.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_rcp_ps(LocalM128);
}
#include "../../../../../include/hkVector4.h"

extern "C"
{
    int __cdecl hkaRagdollUtils_reorderForRagdoll(void*, void*);
    int __cdecl HkaragdollutilsFpfast_ProcessEntries_00ce9db0(void*, void*);
    int __cdecl alignConstraintSpacesToChildren(void*);
}

// @fnv 0x00cea7c0
// src: HAVOK_LIB 0x00cea7c0
int __cdecl hkaRagdollUtils_reorderAndAlignForRagdoll(void* apFirst, void* apSecond, void* apThird)
{
    if (hkaRagdollUtils_reorderForRagdoll(apFirst, apSecond))
        return 1;
    if (HkaragdollutilsFpfast_ProcessEntries_00ce9db0(apSecond, apThird))
        return 1;
    if (alignConstraintSpacesToChildren(apSecond))
        return 1;
    return 0;
}

struct Item
{
    int unk00[11];
    int unk2c;
};
struct Container
{
    int unk00[2];
    Item** items;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct Counter
{
    int unk00[12];
    int unk30;
};
extern "C" void __cdecl AssignNodeFlags(int, int, int);
// Sets unk2c of every item in the container to value, increments counter->unk30 and passes the new count to AssignNodeFlags with c->unk14 and c->unk18.
// @fnv 0x00ce9fa0
// src: HAVOK_LIB 0x00ce9fa0
void __cdecl hkaRagdollUtils_setCollisionLayer(Container* pContainer, int value, Counter* counter)
{
    for (int i = 0; i < pContainer->unk0c; ++i)
        pContainer->items[i]->unk2c = value;
    int count = ++counter->unk30;
    AssignNodeFlags(pContainer->unk14, pContainer->unk18, count);
}

struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};

struct Obj
{
    char pad0[0xc];
    Inner* inner;
};

extern hkError* DAT_01268360;

// Returns true if obj->inner->getSomething() is one of 0,1,2,6,7,8; otherwise optionally reports an unsupported-constraint error and returns false.
// @fnv 0x00ce9ba0
static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw()
{
    int val = obj->inner->getSomething();
    switch (val)
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
        return true;
    default:
        break;
    }
    if (reportError)
    {
        unsigned int buf[128];
        hkErrStream stream(buf, 512);
        stream << "Unsupported type of constraint in rag doll";
        DAT_01268360->message(1, 0xabbabf3b, (char*)buf, ".\\Utils\\hkaRagdollUtils.cpp", 129);
    }
    return false;
}

void caller(Obj* obj)
{
    IsSupportedRagdollConstraint(obj, true);
}

struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct SpawnedObject
{
    int unk00;
    unsigned short m_size04;
    int Init(void* a, void* b, int c, void* d);
};

struct SourceRecord
{
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
    int m_i2c;
};

// Allocates a 0x30-byte SpawnedObject from the global allocator and initializes it from src's fields, returning Init's result.
// @fnv 0x00ce9ff0
int __cdecl SpawnObjectFromRecord(SourceRecord* pSourceRecord)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    SpawnedAllocator* pAllocator = reinterpret_cast<SpawnedAllocator*>(holder->m_heap);
    SpawnedObject* obj = (SpawnedObject*)pAllocator->allocate(0x30);
    obj->m_size04 = 0x30;
    int iValue = pSourceRecord->m_i2c;
    return obj->Init(&pSourceRecord->unk08, &pSourceRecord->unk14, iValue, &pSourceRecord->unk20);
}

struct Node
{
    int unk00, unk04, unk08, unk0c, unk10;
    void* source;
    void* destination;
};
template <class T> struct GameArray
{
    T* data;
    int count;
    int capacity;
    __forceinline void assign(const T* source, int size) throw();
};
typedef GameArray<void*> IntArray;
typedef GameArray<Node*> NodeArray;
struct HeapAllocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void* allocate(int* size);
    virtual void release(void* data, int size);
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
struct ScratchArray
{
    int* data;
    int count;
    unsigned int capacity;
    int* initial;
    __forceinline int& operator[](int index) throw()
    {
        return data[index];
    }
};
struct LogText
{
    int unk00, unk04, unk08;
    void FUN_00cb1600(void* storage, int length) throw();
    LogText(void* storage, int length) throw()
    {
        FUN_00cb1600(storage, length);
    }
    ~LogText() throw()
    {
        FUN_00cc00e0();
    }
    LogText* ProcessAndReturnValue_00cc01c0(const char* value) throw();
    LogText* WriteInt(int value) throw();
    void FUN_00cc00e0() throw();
};
extern "C" void __cdecl hkArrayUtil__reserve(HeapAllocator* allocator, ScratchArray* array, int capacity, int itemSize);
extern "C" const char DAT_010cbde0[];
extern "C" const char DAT_010cbdec[];
extern "C" const char DAT_010cbe00[];
extern "C" const char DAT_010cbd34[];
struct BSAudio;
BSAudio* __cdecl _FUN_00c85750() throw();
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(_FUN_00c85750());
}
static int* reserveScratch(int bytes) throw()
{
    ScratchAllocator* allocator = scratchState();
    int* result = reinterpret_cast<int*>(allocator->cursor);
    allocator->cursor += bytes;
    return result;
}
static __forceinline void reserveArray(HeapAllocator* allocator, ScratchArray* array, int size) throw()
{
    int capacity = array->capacity & 0x3fffffff;
    if (capacity < size)
    {
        int doubled = capacity * 2;
        int newCapacity = size < doubled ? doubled : size;
        hkArrayUtil__reserve(allocator, array, newCapacity, 4);
    }
}
static __forceinline void fillWords(int* destination, int value, int count) throw()
{
    for (int index = 0; index < count; ++index)
        *destination++ = value;
}
static __forceinline void clearAndFree(HeapAllocator* allocator, ScratchArray* array) throw()
{
    array->count = 0;
    if (!(array->capacity & 0x80000000))
        allocator->release(array->data, (array->capacity & 0x3fffffff) * 4);
    array->data = 0;
    array->capacity = 0x80000000;
}
struct LocalArray : ScratchArray
{
    LocalArray(int size, int bytes) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        int* allocation = reserveScratch(bytes);
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    LocalArray(int size, int* output) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        ScratchAllocator* allocator = scratchState();
        int* allocation = reinterpret_cast<int*>(allocator->cursor);
        *output = (size * 4 + 127) & ~127;
        allocator->cursor += *output;
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    __forceinline void SetSizeAndGrow(int size, int value) throw()
    {
        reserveArray(scratchState()->heap, this, size);
        int num = size - count;
        int* destination = data + count;
        fillWords(destination, value, num);
        count = size;
    }
    __forceinline ~LocalArray() throw()
    {
        int* allocation = initial;
        if (allocation == data)
            count = 0;
        scratchState()->cursor = reinterpret_cast<unsigned char*>(allocation);
        clearAndFree(scratchState()->heap, this);
    }
};
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, unsigned int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, (capacity & 0x3fffffff) * 4);
}
template <class T> struct LocalBuffer
{
    T* data;
    int count;
    unsigned int capacity;
    LocalBuffer(int size, int bytes) throw()
    {
        count = size;
        data = reinterpret_cast<T*>(reserveScratch(bytes));
        capacity = size | 0x80000000;
    }
    __forceinline ~LocalBuffer() throw()
    {
        scratchState()->cursor = reinterpret_cast<unsigned char*>(data);
        freeBuffer(scratchState()->heap, data, capacity);
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
};
template <class T> __forceinline void GameArray<T>::assign(const T* source, int size) throw()
{
    HeapAllocator* allocator = scratchState()->heap;
    int available = capacity & 0x3fffffff;
    if (available < size)
    {
        if (!(capacity & 0x80000000))
            allocator->release(data, available * 4);
        int bytes = size * 4;
        data = reinterpret_cast<T*>(allocator->allocate(&bytes));
        capacity = bytes / 4;
    }
    count = size;
    T* destination = data;
    for (int index = 0; index < size; ++index)
        destination[index] = source[index];
}

template <class T> static __forceinline void swapItems(T& first, T& second) throw()
{
    T temporary = first;
    first = second;
    second = temporary;
}
static int findNode(const IntArray* nodes, void* value)
{
    int count = nodes->count;
    for (int index = 0; index < count; ++index)
        if (nodes->data[index] == value)
            return index;
    return -1;
}
// Checks link count and endpoint membership, then orders nodes by successor-chain length and reorders links accordingly.
// @fnv 0x00cea030
// src: HAVOK_LIB 0x00cea030
extern "C" int __cdecl hkaRagdollUtils_reorderForRagdoll(void* apNodes, void* apLinks)
{
    IntArray* nodes = static_cast<IntArray*>(apNodes);
    NodeArray* links = static_cast<NodeArray*>(apLinks);
    int nodeCount = nodes->count;
    int linkCount = links->count;
    if (linkCount != nodeCount - 1)
    {
        int messageStorage[128];
        hkErrStream message(messageStorage, 512);
        reinterpret_cast<LogText*>(&message)
            ->ProcessAndReturnValue_00cc01c0(DAT_010cbde0)
            ->WriteInt(nodeCount - 1)
            ->ProcessAndReturnValue_00cc01c0(DAT_010cbdec)
            ->WriteInt(linkCount)
            ->ProcessAndReturnValue_00cc01c0(DAT_010cbe00);
        DAT_01268360->message(1, 0xabba54bb, reinterpret_cast<const char*>(messageStorage), DAT_010cbd34, 0x144);
        return 1;
    }
    int nodeBytes;
    LocalArray linkPosition(nodeCount, &nodeBytes);
    linkPosition.SetSizeAndGrow(nodeCount, 0);
    LocalBuffer<int> permutation(nodeCount, nodeBytes);
    LocalArray successor(nodeCount, nodeBytes);
    successor.SetSizeAndGrow(nodeCount, -1);
    for (int edgeIndex = 0; edgeIndex < linkCount; ++edgeIndex)
    {
        Node* edge = links->data[edgeIndex];
        void* destination = edge->destination;
        void* source = edge->source;
        int sourceIndex = findNode(nodes, source);
        int targetIndex = findNode(nodes, destination);
        if (sourceIndex < 0 || targetIndex < 0)
            return 1;
        if (successor[sourceIndex] != -1 || linkPosition[sourceIndex] != 0)
            return 1;
        linkPosition[sourceIndex] = edgeIndex;
        successor[sourceIndex] = targetIndex;
    }
    {
        LocalArray chainDepth(nodeCount, nodeBytes);
        chainDepth.SetSizeAndGrow(nodeCount, 0);
        for (int index = 0; index < nodeCount; ++index)
        {
            for (int next = successor[index]; next != -1; next = successor[next])
                ++chainDepth[index];
        }
        for (int index = 0; index < nodeCount; ++index)
            permutation[index] = index;
        for (int left = 0; left < nodeCount - 1; ++left)
        {
            for (int right = left + 1; right < nodeCount; ++right)
            {
                if (chainDepth[left] > chainDepth[right])
                {
                    swapItems(chainDepth[left], chainDepth[right]);
                    swapItems(permutation[left], permutation[right]);
                }
            }
        }
    }
    LocalBuffer<void*> sortedNodes(nodeCount, nodeBytes);
    LocalBuffer<Node*> sortedEdges(linkCount, (linkCount * 4 + 127) & ~127);
    for (int index = 0; index < nodeCount; ++index)
    {
        int original = permutation[index];
        sortedNodes[index] = nodes->data[original];
        if (index > 0)
        {
            int position = linkPosition[original];
            if (position >= 0)
                sortedEdges[index - 1] = links->data[position];
            else
                sortedEdges[index - 1] = 0;
        }
    }
    nodes->assign(sortedNodes.data, nodeCount);
    links->assign(sortedEdges.data, linkCount);
    return 0;
}

namespace fnv_00ceaf60 {
struct HeapAllocator
{
    virtual void slot0();
    virtual void* AllocateMemoryBlock(int bytes) throw();
    virtual void slot2();
    virtual void* allocate(int* bytes) throw();
    virtual void release(void* data, int bytes) throw();
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(hkMemoryRouter_getInstance());
}
extern "C" void __cdecl ResizeAudioStream(HeapAllocator*, void*, int);
template <class T> static __forceinline T* allocateBuffer(HeapAllocator* allocator, int& count) throw()
{
    if (count)
    {
        int bytes = count * sizeof(T);
        T* data = (T*)allocator->allocate(&bytes);
        count = bytes / sizeof(T);
        return data;
    }
    return 0;
}
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, capacity & 0x3fffffff);
}
static __forceinline char& maskAt(char* const& data, int index) throw()
{
    return data[index];
}
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() throw()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    __forceinline ArrayBase(int count) throw()
    {
        int allocatedCount = count;
        data = allocateBuffer<T>(scratchState()->heap, allocatedCount);
        capacity = allocatedCount ? allocatedCount : 0x80000000;
        size = count;
    }
    __forceinline int GetLogicalSize() const throw()
    {
        return size;
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
    __forceinline const T& operator[](int index) const throw()
    {
        return data[index];
    }
    __forceinline void AddBack(HeapAllocator* allocator, const T& value) throw()
    {
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(allocator, this, sizeof(T));
        data[size] = value;
        ++size;
    }
    __forceinline void ClearAndRelease(HeapAllocator* allocator) throw()
    {
        size = 0;
        if (!(capacity & 0x80000000))
            allocator->release(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
template <class T> struct Array : ArrayBase<T>
{
    __forceinline Array() throw()
    {}
    __forceinline Array(int count) throw() : ArrayBase<T>(count)
    {}
    __forceinline void clear() throw()
    {
        ClearAndRelease(scratchState()->heap);
    }
    __forceinline void AddBack(const T& value) throw()
    {
        ArrayBase<T>::AddBack(scratchState()->heap, value);
    }
};
struct RigidBody;
struct Constraint;
struct Skeleton
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int boneCount;
};
struct Ragdoll
{
    unsigned int unk00;
    unsigned short memorySizeAndFlags, referenceCount;
    ArrayBase<RigidBody*> bodies;
    ArrayBase<Constraint*> constraints;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    Ragdoll* FUN_00ce2510(const ArrayBase<RigidBody*>&, const ArrayBase<Constraint*>&, Skeleton*,
                          const ArrayBase<int>&) throw();
    __forceinline Skeleton* getSkeleton() const throw()
    {
        return skeleton;
    }
    __forceinline RigidBody* getBody(int bone) const throw()
    {
        int mapped = boneMap[bone];
        return mapped < 0 ? 0 : bodies[mapped];
    }
    __forceinline Constraint* GetConstraintForBone(int bone) const throw()
    {
        int mapped = boneMap[bone];
        return --mapped < 0 ? 0 : constraints[mapped];
    }
};
extern "C" void __cdecl MarkHierarchyDescendants(Skeleton*, int, char*, int) throw();
// Splits a Ragdoll into two output Ragdolls by partitioning bones into hierarchy descendants of source and the rest.
// @fnv 0x00ceaf60
// src: HAVOK_LIB 0x00ceaf60
void __cdecl hkaRagdollUtils_splitRagdollInstanceShallow(Ragdoll* original, int aiSourceBone, Ragdoll** first, Ragdoll** second)
{
    Ragdoll** outputs[2];
    outputs[0] = first;
    outputs[1] = second;
    const char selectors[2] = {0, 1};
    int maskCount = original->skeleton->boneCount;
    char* mask = allocateBuffer<char>(scratchState()->heap, maskCount);
    int maskCapacity = maskCount ? maskCount : 0x80000000;
    MarkHierarchyDescendants(original->skeleton, aiSourceBone, mask, 1);
    for (int partition = 0; partition < 2; ++partition)
    {
        Array<RigidBody*> bodies;
        Array<Constraint*> constraints;
        Array<int> remap;
        for (int bone = 0; bone < original->skeleton->boneCount; ++bone)
        {
            if (maskAt(mask, bone) != selectors[partition])
            {
                remap.AddBack(-1);
                continue;
            }
            RigidBody* body = original->getBody(bone);
            Constraint* constraint = original->GetConstraintForBone(bone);
            if (!body)
            {
                remap.AddBack(-1);
                continue;
            }
            remap.AddBack(bodies.GetLogicalSize());
            bodies.AddBack(body);
            if (bone != aiSourceBone && bone != 0)
                constraints.AddBack(constraint);
        }
        Ragdoll* result = (Ragdoll*)scratchState()->heap->AllocateMemoryBlock(0x30);
        result->memorySizeAndFlags = 0x30;
        result = result->FUN_00ce2510(bodies, constraints, original->getSkeleton(), remap);
        *outputs[partition] = result;
        HeapAllocator* allocator = scratchState()->heap;
        remap.size = 0;
        if (!(remap.capacity & 0x80000000))
            allocator->release(remap.data, (remap.capacity & 0x3fffffff) * 4);
        remap.data = 0;
        remap.capacity = 0x80000000;
        constraints.clear();
        bodies.clear();
    }
    freeBuffer(scratchState()->heap, mask, maskCapacity);
}
}  // namespace fnv_00ceaf60

extern "C" void _ReadWriteBarrier();
extern LocalM128 DAT_010c71e0;
extern LocalM128 DAT_010c7170;
extern LocalM128 DAT_010c44d0;
extern LocalM128 DAT_010c4c00;
extern LocalM128 DAT_010c4c10;

struct hkBoolR
{
    char m_cBooleanValue;
    hkBoolR()
    {}
    hkBoolR(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

inline hkQuaternion::hkQuaternion()
{}
inline const hkVector4& hkQuaternion::getImag() const
{
    return *reinterpret_cast<const hkVector4*>(this);
}
inline void hkQuaternion::SetConjugate(const hkQuaternion& a)
{
    reinterpret_cast<hkVector4*>(this)->setNeg3(a.getImag());
}
inline hkVector4::hkVector4(const hkVector4& a)
{
    for (int i = 0; i < 4; ++i)
        reinterpret_cast<unsigned int*>(this)[i] = reinterpret_cast<const unsigned int*>(&a)[i];
}
inline hkSimdReal::hkSimdReal(const LocalM128& a) : m_vValue(a)
{}
inline const LocalM128& hkSimdReal::getQuad() const
{
    return m_vValue;
}
inline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
inline void hkVector4::SetAllComponents(const hkSimdReal& a)
{
    getQuad() = a.broadcast();
}
inline LocalM128& hkVector4::getQuad()
{
    return m_vComponents;
}
inline const LocalM128& hkVector4::getQuad() const
{
    return m_vComponents;
}
inline void hkVector4::operator=(const hkVector4& a)
{
    m_vComponents = a.m_vComponents;
}
inline void hkVector4::operator=(const LocalM128& a)
{
    getQuad() = a;
}
inline void hkVector4::setAdd4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& c)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(b.m_vComponents, c.m_vComponents));
}
inline void hkVector4::addMul4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
}
inline void hkVector4::addMul4(const hkSimdReal& a, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.broadcast(), b.m_vComponents));
}
inline void hkVector4::setNeg4(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
}
inline void hkVector4::setNeg3(const hkVector4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c4c00);
}
inline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    LocalM128 first = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 201),
                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 210));
    LocalM128 second = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 210),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 201));
    m_vComponents = _mm_sub_ps(first, second);
}
inline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    LocalM128 products = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
    return _mm_add_ss(_mm_shuffle_ps(products, products, 170), xy);
}
inline void hkVector4::setBroadcast(const hkVector4& a, int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 85);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 170);
    else
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 255);
}
inline void hkVector4::broadcast(int i)
{
    setBroadcast(*this, i);
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& a, const hkVector4& b)
{
    hkVector4 half;
    half.getQuad() = DAT_010c71e0;
    hkVector4 real;
    real.setBroadcast(a.getImag(), 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 result;
    result.setMul4(b, factor);
    hkVector4 dot;
    dot.getQuad() = a.getImag().dot3(b).getQuad();
    dot.broadcast(0);
    result.addMul4(dot, a.getImag());
    hkVector4 cross;
    cross.setCross(a.getImag(), b);
    result.addMul4(real, cross);
    setAdd4(result, result);
}
__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& a, const hkVector4& b)
{
    hkVector4 half;
    half.getQuad() = DAT_010c71e0;
    hkVector4 real;
    real.setBroadcast(a.getImag(), 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 result;
    result.setMul4(b, factor);
    hkVector4 dot;
    dot.getQuad() = a.getImag().dot3(b).getQuad();
    dot.broadcast(0);
    result.addMul4(dot, a.getImag());
    hkVector4 cross;
    cross.setCross(b, a.getImag());
    result.addMul4(real, cross);
    setAdd4(result, result);
}

inline hkSimdReal hkVector4::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return getQuad();
    case 1:
        return _mm_shuffle_ps(getQuad(), getQuad(), 85);
    case 2:
        return _mm_shuffle_ps(getQuad(), getQuad(), 170);
    default:
        return _mm_shuffle_ps(getQuad(), getQuad(), 255);
    }
}
inline void hkVector4::sub4(const hkVector4& a)
{
    getQuad() = _mm_sub_ps(getQuad(), a.getQuad());
}
inline void hkVector4::setXYZW(const hkVector4& xyz, const hkVector4& w)
{
    getQuad() = _mm_shuffle_ps(xyz.getQuad(), _mm_unpackhi_ps(xyz.getQuad(), w.getQuad()), 196);
}
// src: COMMUNITY 0x00c66320
inline void hkQuaternion::setMul(const hkQuaternion& a, const hkQuaternion& b)
{
    hkVector4 cross;
    cross.setCross(a.getImag(), b.getImag());
    cross.addMul4(a.getImag().getSimdAt(3), b.getImag());
    cross.addMul4(b.getImag().getSimdAt(3), a.getImag());
    hkVector4 projection;
    projection.SetAllComponents(a.getImag().dot3(b.getImag()));
    hkVector4 product;
    product.setMul4(a.getImag(), b.getImag());
    product.sub4(projection);
    reinterpret_cast<hkVector4*>(this)->setXYZW(cross, product);
}

// Keep this expression local to preserve the original compiler's instruction order.
static inline LocalM128 reciprocalQuad(LocalM128 a)
{
    LocalM128 estimate = _mm_rcp_ps(a);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, a), estimate));
}
inline void hkVector4::setReciprocal3(const hkVector4& a)
{
    hkVector4 one;
    one.getQuad() = DAT_010c7170;
    hkVector4 combined;
    combined.setXYZW(a, one);
    getQuad() = reciprocalQuad(combined.getQuad());
}
inline void hkVector4::setXYZ0(const hkVector4& a)
{
    m_vComponents = _mm_and_ps(a, DAT_010c4c10);
}
// local form of hkQsTransform: 0x00ce9880 needs inline SetProduct/SetConjugate; shared out-of-line operations do not reproduce exe bytes.
struct hkQsXform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;

    hkBoolR ProcessAndReturnValue_00ce5120(const hkQsXform& other, float eps) const;
    void setFromTransformNoScale(const void* transform);
    void CopyRotationAndTranslationToTarget(void* transformOut) const;

    __forceinline void SetProduct(const hkQsXform& t1, const hkQsXform& t2)
    {
        hkVector4 extra;
        extra.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(t1.m_vTranslation, extra);
        m_rotation.setMul(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
    __forceinline void SetConjugate(const hkQsXform& t)
    {

        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4 reciprocal;
        reciprocal.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(reciprocal);
    }
};

struct hkXform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;
};

struct MassA
{
    void* unk00;
    void* unk04;
    unsigned char unk08, unk09, unk0a, unk0b;
    void FUN_00d733e0();
};
struct MassB
{
    hkVector4 unk00;
    void FUN_00d73410();
};
struct ErrorIface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void SetErrorCodeEnabled(int id, hkBoolR enabled);
    virtual hkBoolR isEnabled(int id);
};
struct ShapeObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    ShapeObj* FUN_00cf5990(void* shape, const hkXform& t);
    void FUN_00c905b0();
};
struct Body
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void SetCollisionShapeAndKey(ShapeObj* shape);
    void* m_pCollisionShape;
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
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    char m_bFlag;
    int unkec;
    hkXform m_kMotionTransform;
    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    void hkpRigidBody_setTransform(const hkXform& t);
    void hkpRigidBody_setCenterOfMassLocal(const hkVector4& com);
};
void __cdecl hkpEntity_RemapSingleEntityCollisionShapes(Body* body, MassA* a, MassB* b);

extern hkQsXform DAT_01268700;
extern float DAT_01017d00;

static __forceinline SpawnedAllocator& heap(hkMemoryRouter* router)
{
    return *reinterpret_cast<SpawnedAllocator*>(router->m_heap);
}

static __forceinline ErrorIface* GetError()
{
    return (ErrorIface*)DAT_01268360;
}

// @fnv 0x00ce9880
// src: XBOX_PDB 0x00ce9880
static __declspec(noinline) int moveRigidBodyPivot(const hkQsXform& t, Body* body)
{
    if (t.ProcessAndReturnValue_00ce5120(DAT_01268700, DAT_01017d00).m_cBooleanValue == 0)
    {
        hkQsXform bodyQs;
        bodyQs.setFromTransformNoScale(&body->m_kMotionTransform);

        hkQsXform combined;
        combined.SetProduct(bodyQs, t);
        hkQsXform inv;
        inv.SetConjugate(t);
        hkVector4 com = body->m_vCenterOfMass1;
        hkBoolR bErrorEnabled = GetError()->isEnabled(0x2ff8c16f);
        GetError()->SetErrorCodeEnabled(0x2ff8c16f, false);
        hkXform kXform;
        {
            void* shape = body->m_pCollisionShape;
            inv.CopyRotationAndTranslationToTarget(&kXform);
            ShapeObj* pShapeObj = (ShapeObj*)heap(hkMemoryRouter_getInstance()).allocate(0x70);
            pShapeObj->m_usMemSizeAndFlags = 0x70;
            ShapeObj* pTransformedShape = pShapeObj->FUN_00cf5990(shape, kXform);
            body->SetCollisionShapeAndKey(pTransformedShape);
            pTransformedShape->FUN_00c905b0();
        }
        {
            MassA a;
            a.FUN_00d733e0();
            MassB b;
            b.FUN_00d73410();
            hkpEntity_RemapSingleEntityCollisionShapes(body, &a, &b);
        }
        GetError()->SetErrorCodeEnabled(0x2ff8c16f, bErrorEnabled);
        combined.CopyRotationAndTranslationToTarget(&kXform);
        body->hkpRigidBody_setTransform(kXform);
        if (body->m_bFlag != 5)
        {
            hkVector4 lc;
            lc.hkVector4_setTransformedInversePos(reinterpret_cast<const hkTransform&>(kXform), com);
            body->hkpRigidBody_setCenterOfMassLocal(lc);
        }
    }
    return 0;
}
volatile int g_inT;
volatile int g_inBody;
volatile int g_out;
void CallTarget_ce9880()
{
    g_out = moveRigidBodyPivot(*(const hkQsXform*)g_inT, (Body*)g_inBody);
}
