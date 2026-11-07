
// src/havok/common/scenedata/mesh/hkxmesh.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/mesh/hkxmesh.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkxMesh.h"

struct FUN_00e4ae20_MemoryManager
{
    // Virtual destructor for the memory manager; performs no work.
// @fnv 0x00e4ae20
    virtual ~FUN_00e4ae20_MemoryManager()
    {}
    virtual void Unused()
    {}
    virtual void Free(void* object, unsigned short size);
};

struct FUN_00e4ae20_Router
{
    unsigned int m_ucUnknownByte[4];
    FUN_00e4ae20_MemoryManager* m_pMemoryManager;
};

FUN_00e4ae20_Router* _D1A0E0GetMemoryRouter();

struct FUN_00e4ae20_Object
{
    unsigned int m_iObjectReferenceCount;
    unsigned short m_iElementCount;

    void ClearArrays();
    FUN_00e4ae20_Object* FUN_00e4ae20(unsigned int flags);
};

FUN_00e4ae20_Object* FUN_00e4ae20_Object::FUN_00e4ae20(unsigned int flags)
{
    this->ClearArrays();

    if (flags & 1)
    {
        FUN_00e4ae20_Router* router = _D1A0E0GetMemoryRouter();
        router->m_pMemoryManager->Free(this, m_iElementCount);
    }

    return this;
}

extern int DAT_010ec1dc;

struct FUN_00e4ad00_cls
{
    int m_vptr;

    FUN_00e4ad00_cls* SetVirtualTable_00e4ad00(unsigned int unusedArg);
};

// @fnv 0x00e4ad00
// src: GUESS 0x00e4ad00 (confidence: low)
FUN_00e4ad00_cls* FUN_00e4ad00_cls::SetVirtualTable_00e4ad00(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010ec1dc;
    return this;
}

struct MemoryAllocator_CCE530
{
    virtual void Unknown00();
    virtual void Unknown04();
    virtual void Unknown08();
    virtual void Unknown0C();
    virtual void Free(void* allocation, unsigned int bytes);
};
extern "C" FUN_00e4ae20_Router* hkMemoryRouter_getInstance();
struct ArrayElement_CCE530
{
    int unk00, unk04, unk08, unk0C;
};
struct Array_CCE530
{
    ArrayElement_CCE530* data;
    int size;
    int capacityAndFlags;
    ~Array_CCE530()
    {
        FUN_00e4ae20_Router* router = hkMemoryRouter_getInstance();
        MemoryAllocator_CCE530* heap = (MemoryAllocator_CCE530*)router->m_pMemoryManager;
        int capacity = capacityAndFlags;
        size = 0;
        if ((capacity & 0x80000000) == 0)
        {
            ArrayElement_CCE530* allocation = data;
            heap->Free(allocation, (capacity & 0x3fffffff) * sizeof(ArrayElement_CCE530));
        }
        data = 0;
        capacityAndFlags = 0x80000000;
    }
};
struct FUN_00cce530
{
    Array_CCE530 first;
    Array_CCE530 second;
    ~FUN_00cce530();
};
// Destructor that destroys the two Array_CCE530 members, freeing their allocations through the memory manager.
// @fnv 0x00cce530
FUN_00cce530::~FUN_00cce530()
{}

extern "C" int DAT_010ec1dc;
extern "C" int DAT_0102e388;
struct FNV_00e4ad10_Ref
{
    void FUN_00c905b0();
};
struct FNV_00e4ad10_Array
{
    FNV_00e4ad10_Ref** objects;
    int length;
    int capacity;
};
struct FNV_00e4ad10_Allocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void Free(void* allocation, unsigned int bytes);
};
struct FNV_00e4ad10_Layout
{
    void* vtable;
    int unk04;
    FNV_00e4ad10_Array first;
    FNV_00e4ad10_Array second;
};
extern "C" FUN_00e4ae20_Router* __cdecl hkMemoryRouter_getInstance();
// @fnv 0x00e4ad10
void FUN_00e4ae20_Object::ClearArrays()
{
    FNV_00e4ad10_Layout* object = reinterpret_cast<FNV_00e4ad10_Layout*>(this);
    object->vtable = &DAT_010ec1dc;
    FNV_00e4ad10_Allocator* heap = reinterpret_cast<FNV_00e4ad10_Allocator*>(hkMemoryRouter_getInstance()->m_pMemoryManager);
    int count = object->second.length;
    FNV_00e4ad10_Ref** ppItems = object->second.objects;
    for (int index = 0; index < count; index++)
    {
        FNV_00e4ad10_Ref* entry = ppItems[index];
        if (entry)
            entry->FUN_00c905b0();
        ppItems[index] = 0;
    }
    object->second.length = 0;
    int size = object->second.capacity;
    if ((size & 0x80000000u) == 0)
        heap->Free(object->second.objects, (size & 0x3fffffff) * 4);
    object->second.objects = 0;
    object->second.capacity = 0x80000000;
    heap = reinterpret_cast<FNV_00e4ad10_Allocator*>(hkMemoryRouter_getInstance()->m_pMemoryManager);
    count = object->first.length;
    ppItems = object->first.objects;
    for (int index = 0; index < count; index++)
    {
        FNV_00e4ad10_Ref* entry = ppItems[index];
        if (entry)
            entry->FUN_00c905b0();
        ppItems[index] = 0;
    }
    object->first.length = 0;
    size = object->first.capacity;
    if ((size & 0x80000000u) == 0)
        heap->Free(object->first.objects, (size & 0x3fffffff) * 4);
    object->first.objects = 0;
    object->first.capacity = 0x80000000;
    object->vtable = &DAT_0102e388;
}

class hkObjectE4AE
{
  public:
    int InsertElements(int a, int b, int c, int d, int e);
    int InsertElements_Thunk(int a, int b, int d, int e);
};

// @fnv 0x00e4ae00
// src: GUESS 0x00e4ae00 (confidence: medium)
int hkObjectE4AE::InsertElements_Thunk(int aiArg1, int aiArg2, int aiArg4, int aiArg5)
{
    return InsertElements(aiArg1, aiArg2, 0, aiArg4, aiArg5);
}

struct GeoOutputE4AB80
{
    hkArray<hkVector4> vertices;
    hkArray<ArrayElement_CCE530> triangles;
    void ProcessAndReturnValue_00d5a4c0(void* allocator, int start, const void* values, int count);
};
struct GeomArraysE4AB80
{
    ArrayElement_CCE530* data;
    int size;
    int capacityAndFlags;
};
struct GeomPairE4AB80
{
    GeomArraysE4AB80 first;
    GeomArraysE4AB80 second;
    void FUN_00cce530();
};
class TriangleInsertE4AB80
{
  public:
    int InsertElements_Thunk(int allocator, int start, int values, int count);
};
class MeshSectionE4AB80
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    void* material;
    void hkxMeshSection_appendGeometry(GeomPairE4AB80* geometry, int materialIndex);
};
void ResizeAudioStream(void* allocator, void* array, int elementSize);
template <class T> __forceinline void constructWithCopyRange(T* p, int n, T v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
struct MeshE4AB80
{
    int unk00, unk04;
    hkArray<hkxMeshSection*> m_sections;
    void CollectMeshSectionsWithRebasedIndices(GeoOutputE4AB80* output, hkArray<void*>* materials);
};
// Iterates mesh sections, resolves material indices, collects vertex and triangle arrays into output, and offsets triangle indices by the base vertex count.
// @fnv 0x00e4ab80
// src: GUESS 0x00e4ab80 (confidence: medium)
void MeshE4AB80::CollectMeshSectionsWithRebasedIndices(GeoOutputE4AB80* output, hkArray<void*>* materials)
{
    int materialIndex = -1;
    for (int iSectionIndex = 0; iSectionIndex < m_sections.m_iElementCount; ++iSectionIndex)
    {
        int baseVertex = output->vertices.m_iElementCount;
        if (materials != 0)
        {
            void* material = ((MeshSectionE4AB80*)m_sections.m_data[iSectionIndex])->material;
            materialIndex = -1;
            int count = materials->m_iElementCount;
            for (int k = 0; k < count; ++k)
            {
                if (materials->m_data[k] == material)
                {
                    materialIndex = k;
                    break;
                }
            }
            if (materialIndex == -1)
            {
                materialIndex = materials->m_iElementCount;
                FUN_00e4ae20_Router* router = hkMemoryRouter_getInstance();
                if (materials->m_iElementCount == (materials->m_iCapacityState & 0x3fffffff))
                {
                    ResizeAudioStream(router->m_pMemoryManager, materials, 4);
                }
                constructWithCopyRange(&materials->m_data[materials->m_iElementCount], 1, material);
                materials->m_iElementCount++;
            }
        }
        GeomPairE4AB80 data;
        data.first.capacityAndFlags = 0x80000000;
        data.second.capacityAndFlags = 0x80000000;
        data.first.data = 0;
        data.first.size = 0;
        data.second.data = 0;
        data.second.size = 0;
        ((MeshSectionE4AB80*)m_sections.m_data[iSectionIndex])->hkxMeshSection_appendGeometry(&data, materialIndex);
        for (int i = 0; i < data.second.size; ++i)
        {
            data.second.data[i].unk00 += baseVertex;
            data.second.data[i].unk04 += baseVertex;
            data.second.data[i].unk08 += baseVertex;
        }
        {
            int vn = data.first.size;
            ArrayElement_CCE530* pVertices = data.first.data;
            FUN_00e4ae20_Router* pRouter = hkMemoryRouter_getInstance();
            void* pAllocator = pRouter->m_pMemoryManager;
            output->ProcessAndReturnValue_00d5a4c0(pAllocator, baseVertex, pVertices, vn);
        }
        {
            int tn = data.second.size;
            int iTriangleStart = output->triangles.m_iElementCount;
            ArrayElement_CCE530* pTriangles = data.second.data;
            FUN_00e4ae20_Router* r2 = hkMemoryRouter_getInstance();
            void* al2 = r2->m_pMemoryManager;
            ((TriangleInsertE4AB80*)&output->triangles)->InsertElements_Thunk((int)al2, iTriangleStart, (int)pTriangles, tn);
        }
        data.FUN_00cce530();
    }
}
