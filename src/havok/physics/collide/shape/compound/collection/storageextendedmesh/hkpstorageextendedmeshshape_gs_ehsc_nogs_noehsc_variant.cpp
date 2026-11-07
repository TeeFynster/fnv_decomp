#include "../../../../../../../../include/hkArray.h"

// src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpMeshMaterial.h"
#include "../../../../../../../../include/hkpStorageExtendedMeshShape.h"
#include <xmmintrin.h>


extern "C" void _ReadWriteBarrier();
extern "C" void* __cdecl hkString_memSet(void*, int, unsigned int);

enum hkPlacementNewArg
{
    hkPlacementNew
};
inline void* operator new(unsigned int, void* p, hkPlacementNewArg)
{
    return p;
}

struct Subpart
{
    unsigned char type;
    signed char materialIndexType;
    short materialStride;
    void* materialIndexBase;
    unsigned short materialIndexStride, numMaterials;
    const char* materialBase;
    const void* materialClass;
    int numTriangles;
    const char* vertexBase;
    int vertexStride, numVertices;
    __m128 extrusionVector;
    const char* indexBase;
    unsigned int indexStride;
    unsigned char indexType, extrusion;
    unsigned short flags;
    void UpdateState_00d4abf0(const Subpart&);
};
struct MaterialName
{
    const char* value;
    MaterialName(const char*) throw();
    MaterialName& operator=(const MaterialName&);
};
struct NamedMaterial : public hkpMeshMaterial
{
    MaterialName name;
    NamedMaterial() throw() : name("Default")
    {
        m_uiFilterInfo = 0;
    }
};
struct MeshMaterial : public hkpMeshMaterial
{
    union
    {
        struct
        {
            short restitution, friction;
        };
        int properties;
    };
    int userData;
};
void hkArrayUtil__reserve(void*, void*, int, int);
void ResizeAudioStream(void*, void*, int);
// src: HAVOK_LIB 0x00d49c20
static __declspec(noinline) int numIndices_00d49c20(int stride, int triangles)
{
    switch (stride)
    {
    case 1:
        return triangles + 2;
    case 2:
        return triangles * 2 + 1;
    default:
        return triangles * 4;
    }
}
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269bb4, g_01268c8c;

template <class T> inline void initializeItems(T*, int)
{}
inline void initializeItems(NamedMaterial* destination, int count)
{
    for (int i = 0; i < count; ++i)
        new (destination + i, hkPlacementNew) NamedMaterial;
}
template <class T>
static __forceinline void Buffer_reserveUsing(hkArrayBase<T>& self, hkMemoryAllocator& allocator, int requested)
{
        int available = self.m_iCapacityState & 0x3fffffff;
        if (available < requested)
        {
            int next = requested < available * 2 ? available * 2 : requested;
            hkArrayUtil__reserve(&allocator, (&self), next, sizeof(T));
        }
    }

template <class T>
static __forceinline T* Buffer_growUsing(hkArrayBase<T>& self, hkMemoryAllocator& allocator, int count)
{
        int offset = self.m_iElementCount;
        Buffer_reserveUsing(self, allocator, offset + count);
        initializeItems(self.m_data + self.m_iElementCount, count);
        self.m_iElementCount += count;
        return self.m_data + offset;
    }

template <class T>
static __forceinline T* Buffer_grow(hkArrayBase<T>& self, int count)
{
        return Buffer_growUsing(self, hkMemoryRouter::getInstance().heap(), count);
    }
struct hkpStorageExtendedMeshShapeMeshSubpartStorage : public hkReferencedObject
{
    hkArrayBase<__m128> vertices;
    hkArrayBase<unsigned char> indices8;
    hkArrayBase<unsigned short> indices16;
    hkArrayBase<unsigned int> indices32;
    hkArrayBase<unsigned char> materialIndices8;
    hkArrayBase<MeshMaterial> materials;
    hkArrayBase<NamedMaterial> namedMaterials;
    hkArrayBase<unsigned short> materialIndices16;
    hkpStorageExtendedMeshShapeMeshSubpartStorage() throw();
    static void* operator new(unsigned int bytes)
    {
        hkMemoryAllocator& allocator = hkMemoryRouter::getInstance().heap();
        hkpStorageExtendedMeshShapeMeshSubpartStorage* memory = static_cast<hkpStorageExtendedMeshShapeMeshSubpartStorage*>(allocator.blockAlloc(bytes));
        memory->m_usMemSizeAndFlags = static_cast<unsigned short>(bytes);
        return memory;
    }
};

template <class T> inline void copyItems(T* destination, int count, const T& value)
{
    for (int i = 0; i < count; ++i)
        destination[i] = value;
}
template <class T, template <class> class A> inline void append(A<T>& a, const T& value)
{
    hkMemoryRouter& manager = hkMemoryRouter::getInstance();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(manager.m_heap, &a, sizeof(T));
    copyItems(a.m_data + a.m_iElementCount, 1, value);
    ++a.m_iElementCount;
}
inline void append(hkArrayBase<unsigned char>& a, const unsigned char& value)
{
    hkMemoryRouter& manager = hkMemoryRouter::getInstance();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(manager.m_heap, &a, sizeof(unsigned char));
    unsigned char* slot = a.m_data;
    _ReadWriteBarrier();
    slot += a.m_iElementCount;
    copyItems(slot, 1, value);
    ++a.m_iElementCount;
}
inline void append(hkArrayBase<unsigned short>& a, const unsigned short& value)
{
    hkMemoryRouter& manager = hkMemoryRouter::getInstance();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(manager.m_heap, &a, sizeof(unsigned short));
    copyItems(a.m_data + a.m_iElementCount, 1, value);
    _ReadWriteBarrier();
    ++a.m_iElementCount;
    _ReadWriteBarrier();
}
inline short halfValue(const float& value)
{
    return short(*reinterpret_cast<const int*>(&value) >> 16);
}
struct SourceArg
{
    const Subpart* p;
    SourceArg(const Subpart* q) : p(q)
    {}
};
// @fnv 0x00d4a2b0
// src: XBOX_PDB 0x00d4a2b0
void hkpStorageExtendedMeshShape::addTrianglesSubpart(SourceArg sourceArg)
{
    Subpart* destination = hkpExtendedMeshShape_expandOneTriangleSubparts();
    const Subpart& source = *sourceArg.p;
    destination->UpdateState_00d4abf0(source);
    hkpStorageExtendedMeshShapeMeshSubpartStorage* created = new hkpStorageExtendedMeshShapeMeshSubpartStorage;
    hkArray<hkReferencedObject*>& mesh = reinterpret_cast<hkArray<hkReferencedObject*>&>(m_kMeshSubparts);
    append(mesh, static_cast<hkReferencedObject*>(created));
    _ReadWriteBarrier();
    hkpStorageExtendedMeshShapeMeshSubpartStorage* storage = static_cast<hkpStorageExtendedMeshShapeMeshSubpartStorage*>(mesh.m_data[mesh.m_iElementCount - 1]);
    __m128* vertices = Buffer_grow(storage->vertices, source.numVertices);
    const char* vertex = source.vertexBase;
    for (int i = 0; i < source.numVertices; ++i)
    {
        const float* v = reinterpret_cast<const float*>(vertex);
        *vertices++ = _mm_setr_ps(v[0], v[1], v[2], 0.0f);
        vertex += source.vertexStride;
    }
    destination->vertexBase = reinterpret_cast<const char*>(storage->vertices.m_data);
    destination->vertexStride = 16;
    destination->numVertices = source.numVertices;
    void* indices;
    if (source.indexType == 1)
    {
        const int inputStride = source.indexStride;
        const int stride = inputStride <= 2 ? inputStride : 4;
        destination->indexStride = stride * sizeof(unsigned char);
        int count = numIndices_00d49c20(inputStride, source.numTriangles);
        unsigned char* data = Buffer_grow(storage->indices8, count);
        hkString_memSet(data, 0, count * sizeof(unsigned char));
        const char* input = source.indexBase;
        indices = data;
        for (int i = 0; i < source.numTriangles; ++i)
        {
            const unsigned char* p = reinterpret_cast<const unsigned char*>(input);
            unsigned char* q = reinterpret_cast<unsigned char*>(data);
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            data = reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(data) + destination->indexStride);
            input += source.indexStride;
        }
    }
    else if (source.indexType == 2)
    {
        const unsigned int inputStride = source.indexStride >> 1;
        const int stride = static_cast<int>(inputStride) <= 2 ? inputStride : 4;
        destination->indexStride = stride * sizeof(unsigned short);
        int count = numIndices_00d49c20(inputStride, source.numTriangles);
        unsigned short* data = Buffer_grow(storage->indices16, count);
        hkString_memSet(data, 0, count * sizeof(unsigned short));
        const char* input = source.indexBase;
        indices = data;
        for (int i = 0; i < source.numTriangles; ++i)
        {
            const unsigned short* p = reinterpret_cast<const unsigned short*>(input);
            unsigned short* q = reinterpret_cast<unsigned short*>(data);
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            data = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(data) + destination->indexStride);
            input += source.indexStride;
        }
    }
    else
    {
        const unsigned int inputStride = source.indexStride >> 2;
        const int stride = static_cast<int>(inputStride) <= 2 ? inputStride : 4;
        destination->indexStride = stride * sizeof(unsigned int);
        int count = numIndices_00d49c20(inputStride, source.numTriangles);
        unsigned int* data = Buffer_grow(storage->indices32, count);
        hkString_memSet(data, 0, count * sizeof(unsigned int));
        const char* input = source.indexBase;
        indices = data;
        for (int i = 0; i < source.numTriangles; ++i)
        {
            const unsigned int* p = reinterpret_cast<const unsigned int*>(input);
            unsigned int* q = reinterpret_cast<unsigned int*>(data);
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            data = reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(data) + destination->indexStride);
            input += source.indexStride;
        }
    }
    destination->indexType = source.indexType;
    destination->numTriangles = source.numTriangles;
    destination->extrusion = source.extrusion;
    destination->indexBase = static_cast<const char*>(indices);
    destination->materialIndexType = source.materialIndexType;
    if (source.materialIndexBase)
    {
        if (source.materialIndexType == 1)
        {
            hkArrayBase<unsigned char>& materialIndices = storage->materialIndices8;
            if (source.materialIndexStride == 0)
            {
                append(materialIndices, *static_cast<const unsigned char*>(source.materialIndexBase));
                destination->materialIndexBase = materialIndices.m_data + materialIndices.m_iElementCount - 1;
            }
            else
            {
                unsigned char* data = Buffer_grow(materialIndices, source.numTriangles);
                destination->materialIndexBase = data;
                const char* input = static_cast<const char*>(source.materialIndexBase);
                for (int i = 0; i < source.numTriangles; ++i)
                {
                    data[i] = *reinterpret_cast<const unsigned char*>(input);
                    input += source.materialIndexStride;
                }
            }
        }
        else
        {
            hkArrayBase<unsigned short>& materialIndices = storage->materialIndices16;
            if (source.materialIndexStride == 0)
            {
                append(materialIndices, *static_cast<const unsigned short*>(source.materialIndexBase));
                destination->materialIndexBase = materialIndices.m_data + materialIndices.m_iElementCount - 1;
            }
            else
            {
                unsigned short* data = Buffer_grow(materialIndices, source.numTriangles);
                destination->materialIndexBase = data;
                const char* input = static_cast<const char*>(source.materialIndexBase);
                for (int i = 0; i < source.numTriangles; ++i)
                {
                    data[i] = *reinterpret_cast<const unsigned short*>(input);
                    input += source.materialIndexStride;
                }
            }
        }
        destination->materialIndexStride = source.materialIndexStride;
        if (destination->materialIndexStride)
        {
            switch (destination->materialIndexType)
            {
            case 1:
                destination->materialIndexStride = 1;
                break;
            case 2:
                destination->materialIndexStride = 2;
                break;
            }
        }
    }
    else
    {
        destination->materialIndexBase = 0;
        destination->materialIndexStride = 0;
    }
    if (destination->materialIndexBase)
    {
        if (source.materialClass == &g_01269bb4)
        {
            NamedMaterial* data = Buffer_grow(storage->namedMaterials, source.numMaterials);
            const char* input = source.materialBase;
            for (int i = 0; i < source.numMaterials; ++i)
            {
                NamedMaterial* material = new (data + i, hkPlacementNew) NamedMaterial;
                const NamedMaterial* original = reinterpret_cast<const NamedMaterial*>(input);
                material->m_uiFilterInfo = original->m_uiFilterInfo;
                material->name = original->name;
                input += source.materialStride;
            }
            destination->materialBase = reinterpret_cast<const char*>(storage->namedMaterials.m_data);
            if (source.materialStride)
            {
                destination->materialStride = 8;
                destination->numMaterials = source.numMaterials;
            }
            else
            {
                destination->materialStride = 0;
                destination->numMaterials = 1;
            }
        }
        else
        {
            MeshMaterial* data = Buffer_grow(storage->materials, source.numMaterials);
            const char* input = source.materialBase;
            for (int i = 0; i < source.numMaterials; ++i)
            {
                const MeshMaterial* original = reinterpret_cast<const MeshMaterial*>(input);
                if (source.materialClass == &g_01268c8c)
                {
                    data->m_uiFilterInfo = original->m_uiFilterInfo;
                    data->properties = original->properties;
                    data->userData = original->userData;
                }
                else
                {
                    data->m_uiFilterInfo = original->m_uiFilterInfo;
                    data->friction = halfValue(1.0f);
                    data->restitution = halfValue(0.0f);
                }
                input += source.materialStride;
                ++data;
            }
            destination->materialBase = reinterpret_cast<const char*>(storage->materials.m_data);
            if (source.materialStride)
            {
                destination->materialStride = 12;
                destination->numMaterials = source.numMaterials;
            }
            else
            {
                destination->materialStride = 0;
                destination->numMaterials = 1;
            }
        }
    }
    hkpExtendedMeshShape_recalcAabbExtents();
    int last = m_kTrianglesSubparts.m_iElementCount - 1;
    m_iNumTriangles += Vec4(destination, last);
}
