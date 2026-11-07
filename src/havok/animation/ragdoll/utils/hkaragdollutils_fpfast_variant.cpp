#include "../../../../../include/Vec4.h"
#include "../../../../../include/hkErrStream.h"
#include "../../../../../include/hkError.h"

// src/havok/animation/ragdoll/utils/hkaragdollutils_fpfast_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy /fp:fast (unit src/havok/animation/ragdoll/utils/hkaragdollutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    int __cdecl hkaRagdollUtils_reorderForRagdoll(void*, void*);
    int __cdecl HkaragdollutilsFpfast_ProcessEntries_00ce9db0(void*, void*);
    int __cdecl alignConstraintSpacesToChildren(void*);
}
int __cdecl hkaRagdollUtils_reorderAndAlignForRagdoll(void* p1, void* p2, void* p3);
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
void __cdecl hkaRagdollUtils_setCollisionLayer(Container* c, int value, Counter* counter);
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
static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw();
void caller(Obj* obj);
struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct SpawnedGlobal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};
SpawnedGlobal* __cdecl hkMemoryRouter_getInstance() throw();
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
int __cdecl SpawnObjectFromRecord(SourceRecord* src);
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
// The shared stream header does not yet declare the signed-integer overload.
extern "C" void FUN_00cc0280();
static __forceinline hkOstream& writeInt(hkOstream& stream, int value) throw()
{
    typedef hkOstream& (__thiscall *WriteInt)(hkOstream*, int);
    return reinterpret_cast<WriteInt>(&FUN_00cc0280)(&stream, value);
}
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
// @fnv 0x00cea030
// src: HAVOK_LIB 0x00cea030
extern "C" int __cdecl hkaRagdollUtils_reorderForRagdoll(void* first, void* second)
{
    IntArray* nodes = static_cast<IntArray*>(first);
    NodeArray* links = static_cast<NodeArray*>(second);
    int nodeCount = nodes->count;
    int linkCount = links->count;
    if (linkCount != nodeCount - 1)
    {
        int messageStorage[128];
        hkErrStream message(messageStorage, 512);
        writeInt(writeInt(message.ProcessAndReturnValue_00cc01c0(DAT_010cbde0), nodeCount - 1)
            .ProcessAndReturnValue_00cc01c0(DAT_010cbdec), linkCount)
            .ProcessAndReturnValue_00cc01c0(DAT_010cbe00);
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

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
extern "C" void _WriteBarrier(void);

extern const float DAT_010959f4;
extern const float DAT_01012068;
extern const __m128 DAT_010c71b0;

struct PivotVec;
struct Bits
{
    int x, y, z, w;
};
struct __declspec(align(16)) V4A
{
    float x, y, z, w;
};
struct __declspec(align(16)) Qs
{
    V4A translation;
    V4A rotation;
    V4A scale;
};

struct Shape
{
    virtual int v0();
    virtual int v1();
};

struct Body : public Obj
{
    int unk10;
    Shape* shape;
};

struct List
{
    Body** items;
    int count;
};

static __declspec(noinline) bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw()
{
    return obj->inner != 0 && reportError;
}

// src: HAVOK_LIB 0x00ce9c40
static __declspec(noinline) Vec4* _accessConstraintPivotA(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    return (Vec4*)((char*)inner + (t <= 8 ? 0x20 : 0x50));
}

extern Qs* g_pivotXf;
// src: XBOX_PDB 0x00ce9880
static __declspec(noinline) int moveRigidBodyPivot(Qs* xf, Shape* shape) throw()
{
    g_pivotXf = xf;
    int s = shape->v0();
    s += shape->v1();
    return s;
}

struct A1W
{
    List* p;
    A1W(List* q) : p(q)
    {}
};
struct __declspec(align(16)) PivotVec
{
    float x, y, z, w;
    __m128 quad() const
    {
        return _mm_load_ps(&x);
    }
    void setQuad(__m128 q)
    {
        _mm_store_ps(&x, q);
    }
    void operator=(const PivotVec& v)
    {
        setQuad(v.quad());
    }
    void SetAllComponents(float a)
    {
        setQuad(_mm_set_ps1(a));
    }
    float lengthSquared3() const
    {
        __m128 x2 = _mm_mul_ps(quad(), quad());
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum));
        return r;
    }
};

// local form of hkQsTransform: 0x00ce9db0 needs implicit construction and inline scale setup; shared form gives 235 bytes vs exe 224.
struct __declspec(align(16)) PivotXform
{
    PivotVec m_vTranslation;
    PivotVec m_rotation;
    PivotVec m_vScale;
};

// @fnv 0x00ce9db0
// src: GUESS 0x00ce9db0 (confidence: low)
int __cdecl HkaragdollutilsFpfast_ProcessEntries_00ce9db0(A1W constraints, void* warnOnAlignment)
{
    const int numConstraints = constraints.p->count;
    int result = 0;
    for (int c = 0; c < numConstraints; c++)
    {
        Body* constraint = constraints.p->items[c];
        if (!IsSupportedRagdollConstraint(constraint, true))
        {
            result = 1;
            continue;
        }
        PivotVec pivotInA = *(const PivotVec*)_accessConstraintPivotA(constraint);
        Shape* shape = constraint->shape;
        PivotXform childFromConstraint;
        childFromConstraint.m_rotation = *(const PivotVec*)&DAT_010c71b0;
        childFromConstraint.m_vScale.SetAllComponents(DAT_01012068);
        childFromConstraint.m_vTranslation = pivotInA;
        if (childFromConstraint.m_vTranslation.lengthSquared3() > DAT_010959f4)
        {
            if (moveRigidBodyPivot((Qs*)&childFromConstraint, shape) != 0)
                result = 1;
        }
    }
    return result;
}
