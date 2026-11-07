#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkDisplayConvex.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkGeometry.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpShape.h"

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int newCapacity, int elemSize);


template <class T>
static __forceinline void VertexArray_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void VertexArray_reserve(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline void VertexArray_SetSizeAndGrow(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline void VertexArray_ClearAndRelease(hkArrayBase<T>& self);

template <class T>
static __forceinline void VertexArray_destroy(hkArrayBase<T>& self)
{
        VertexArray_ClearAndRelease(self);
    }

template <class T>
static __forceinline void VertexArray_reserve(hkArrayBase<T>& self, int n)
{
        hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
        const int capacity = self.getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(&alloc, (&self), newSize, sizeof(T));
        }
    }

template <class T>
static __forceinline void VertexArray_SetSizeAndGrow(hkArrayBase<T>& self, int n)
{
        VertexArray_reserve(self, n);
        self.m_iElementCount = n;
    }

template <class T>
static __forceinline void VertexArray_ClearAndRelease(hkArrayBase<T>& self)
{
        hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
        {
            alloc.bufFree(self.m_data, self.getCapacity() * sizeof(T));
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct VertexArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { VertexArray_destroy(self); }
};

template <typename T> inline void InitializeGeometryArray(hkArray<T>& array)
{
    array.m_iCapacityState = 0x80000000;
    array.m_data = 0;
    array.m_iElementCount = 0;
}

inline hkGeometry::hkGeometry()
{
    InitializeGeometryArray(m_kVertices);
    InitializeGeometryArray(m_uiTriangleCount);
}

inline void* hkGeometry::operator new(size_t nbytes) throw()
{
    return hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes);
}

struct FloatArrayDescriptor
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};

inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter_getInstance()->heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}

inline void* hkDisplayGeometry::operator new(std::size_t nbytes)
{
    return hkReferencedObject::operator new(nbytes);
}

struct VertexSource;

void __cdecl hkGeometryUtility_createVerticesFromPlaneEquations(const VertexSource* src, hkArray<hkVector4>* verticesOut);
void __cdecl InitAndSetB(const FloatArrayDescriptor& vertices, hkGeometry& geometryOut);

// @fnv 0x00de3360
// src: HAVOK_LIB 0x00de3360
static __declspec(noinline) hkpShape* _createConvexDisplayFromPlanes(const VertexSource* src, const hkTransform& transform)
{
    hkArray<hkVector4, VertexArrayPolicy> localVertices;
    hkGeometryUtility_createVerticesFromPlaneEquations(src, reinterpret_cast<hkArray<hkVector4>*>(&localVertices));
    const int numVertices = localVertices.GetLogicalSize();
    if (numVertices < 1)
    {
        return 0;
    }

    hkArray<hkVector4, VertexArrayPolicy> vertices;
    VertexArray_SetSizeAndGrow(vertices, numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        vertices[i].setTransformedPos_00c7f640(transform, localVertices[i]);
    }

    hkGeometry* geom = new hkGeometry;

    FloatArrayDescriptor stridedVerts;
    stridedVerts.m_iStridedVertexCount = vertices.GetLogicalSize();
    stridedVerts.m_iVertexStride = sizeof(hkVector4);
    stridedVerts.m_kVertices = (const float*)vertices.begin();
    InitAndSetB(stridedVerts, *geom);

    hkpShape* shape = reinterpret_cast<hkpShape*>(new hkDisplayConvex(geom));
    return shape;
}

hkpShape* BuildConvexShapeEntry(const VertexSource* src, const hkTransform& transform)
{
    return _createConvexDisplayFromPlanes(src, transform);
}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
