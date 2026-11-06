// src/havok/physics/collide/shape/convex/convexvertices/hkpconvexverticesconnectivity.cpp

#include "../../../../../../../include/hkpConvexVerticesConnectivity.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

// The shared connectivity class has no reset/append declarations; these free
// functions retain the member-call ABI (ECX object, unused EDX, callee pops arguments).
// @fnv 0x00e48de0
void __fastcall ResetConnectivity(hkpConvexVerticesConnectivity* connectivity, void*)
{
    connectivity->m_kVertexIndices.m_iElementCount = 0;
    connectivity->m_kNumVerticesPerFace.m_iElementCount = 0;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

// hkMemoryRouter::get is bound to 0x00c85750 in other units; heap is the allocator at +0x10.
template <class T>
static inline void AppendConnectivityElement(hkArray<T>& array, const T& value)
{
    hkMemoryRouter* router = &hkMemoryRouter::getInstance();
    if (array.m_iElementCount == (array.m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(*reinterpret_cast<hkMemoryAllocator*>(router->m_heap), &array, sizeof(T));
    T* p = &array.m_data[array.m_iElementCount];
    __assume(p != 0);
    new (p) T(value);
    array.m_iElementCount++;
}

// @fnv 0x00e48df0
void __fastcall AppendConnectivityFace(hkpConvexVerticesConnectivity* connectivity, void*, const int* values, int count)
{
    AppendConnectivityElement(connectivity->m_kNumVerticesPerFace, (unsigned char)count);
    for (int i = 0; i < count; i++)
        AppendConnectivityElement(connectivity->m_kVertexIndices, (unsigned short)values[i]);
}
