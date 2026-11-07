#include <xmmintrin.h>
typedef ::__m128 LocalM128;

// src/havok/physics/collide/shape/compound/collection/simplemesh/hkpsimplemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/simplemesh/hkpsimplemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef ::__m128 LocalM128;

#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../../include/hkpTriangleShape.h"
#include "../../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../../include/hkStatisticsCollector.h"





inline hkpShapeContainer::~hkpShapeContainer()
{}

// include/ has no hkMemoryRouter header yet; the heap pointer is at offset 0x10.
#include "../../../../../../../../include/hkMemoryRouter.h"

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

inline void hkReferencedObject::operator delete(void* p)
{
    hkReferencedObject* object = static_cast<hkReferencedObject*>(p);
    hkMemoryRouter_getInstance().heap().blockFree(object, object->m_usMemSizeAndFlags);
}

inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}

template <class T, class Allocator> inline hkArray<T, Allocator>::~hkArray() throw()
{
    hkMemoryAllocator& kAlloc = hkContainerHeapAllocator().get(this);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

using ::_mm_setzero_ps;

inline void* operator new(unsigned int, void* p)
{
    return p;
}

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

template <class ENUM, class STORAGE> inline hkEnum<ENUM, STORAGE>::hkEnum()
{}

inline hkpShape::hkpShape(hkpShapeType type) throw() : m_ulUserData(0)
{
    // hkEnum stores this shape tag as hkUint32; initialize it without an extra converting constructor.
    *reinterpret_cast<hkUint32*>(&m_type) = type;
}

inline hkpConvexShape::hkpConvexShape(int type, float radius) throw()
    : hkpShape(static_cast<hkpShapeType>(type)), m_fSphereRadius(radius)
{}

inline hkpTriangleShape::hkpTriangleShape(float fRadius, unsigned short usWeldingInfo, int eWeldingType) throw()
    : hkpConvexShape(3, fRadius)
{
    m_kWeldingInfo = usWeldingInfo;
    *reinterpret_cast<hkUint8*>(&m_eWeldingType) = static_cast<hkUint8>(eWeldingType);
    m_kVertexTransform.setZero4();
    m_ucWeldingPadding = 0;
}

// include/ has no hkpSimpleMeshShape header yet; keep its definition here.
class hkpSimpleMeshShape : public hkpShapeCollection
{
public:
    struct Triangle
    {
        int m_kPointA, m_kPointB, m_iThirdValue;
        unsigned short m_kWeldingInfo;
    };

    hkpSimpleMeshShape();
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    // hkpShapeCollection has no declaration for its statistics implementation at 0x00d213e0.
    void CollectShapeStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    void setTriangleWeldingInfo(int index, unsigned short value);
    void setWeldingType(unsigned char type);

    hkArray<hkVector4> m_kVertices;
    hkArray<Triangle> m_uiTriangleCount;
    hkArray<unsigned char> m_kMaterialIndices8;
    float m_fSphereRadius;
    unsigned char m_eWeldingType;
};

// Its implicit destructor and deleting-destructor thunk cover 0x00dfcfd0 and 0x00dfcfc0/0x00dfd080.
hkpSimpleMeshShape::hkpSimpleMeshShape()
{}

// @fnv 0x00e3c240
void hkpSimpleMeshShape::setTriangleWeldingInfo(int index, unsigned short value)
{
    m_uiTriangleCount[index].m_kWeldingInfo = value;
}

// @fnv 0x00e3c260
void hkpSimpleMeshShape::setWeldingType(unsigned char type)
{
    m_eWeldingType = type;
}

// Placement-constructs a triangle shape from the vertex indices in m_uiTriangleCount[uiKey] and returns it as a hkpShape pointer.
// @fnv 0x00e3c430
const hkpShape* hkpSimpleMeshShape::GetShapeForKey(hkpShapeKey uiKey, hkpShapeBuffer& buffer) const
{
    hkpTriangleShape* pkTriangle =
        ::new (&buffer) hkpTriangleShape(m_fSphereRadius, m_uiTriangleCount[uiKey].m_kWeldingInfo, m_eWeldingType);
    pkTriangle->setVertex(0, m_kVertices[m_uiTriangleCount[uiKey].m_kPointA]);
    pkTriangle->setVertex(1, m_kVertices[m_uiTriangleCount[uiKey].m_kPointB]);
    pkTriangle->setVertex(2, m_kVertices[m_uiTriangleCount[uiKey].m_iThirdValue]);
    return pkTriangle;
}

extern float DAT_011b2e90;
hkBool __cdecl IsDegenerateTriangle(const hkVector4&, const hkVector4&, const hkVector4&, float);
// These arrays are at +8/+20 from the container this pointer, unlike hkGeometry at +0/+12.
// Returns the index of the first triangle in m_uiTriangleCount that is not degenerate, or -1 if all are degenerate.
// @fnv 0x00e3c340
hkpShapeKey hkpSimpleMeshShape::GetFirstKey() const
{
    for (int i = 0; i < m_uiTriangleCount.GetLogicalSize(); i++)
    {
        if (!IsDegenerateTriangle(m_kVertices[m_uiTriangleCount[i].m_kPointA], m_kVertices[m_uiTriangleCount[i].m_kPointB],
                                  m_kVertices[m_uiTriangleCount[i].m_iThirdValue], DAT_011b2e90))
            return i;
    }
    return -1;
}

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* p, int bytes);
extern char DAT_01269198;

template <class T> inline void CollectArray(hkStatisticsCollector* collector, const char* name, int type, const hkArray<T>& a)
{
    if ((a.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations)
    {
        const T* data = a.m_data;
        int allocated = hkStatisticsCollector_getAllocatedSize(data, a.getCapacity() * (int)sizeof(T));
        collector->AddMemoryChunk(type, name, a.m_data, a.m_iElementCount * (int)sizeof(T), allocated);
    }
}

// Reports the mesh arrays, then delegates to the collection statistics implementation.
// @fnv 0x00e3c4e0
void hkpSimpleMeshShape::calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const
{
    CollectArray(collector, "Vertices", 3, m_kVertices);
    CollectArray(collector, "Triangles", 3, m_uiTriangleCount);
    CollectArray(collector, "MaterialIds", 3, m_kMaterialIndices8);
    CollectShapeStatistics(collector, reinterpret_cast<const hkClass*>(&DAT_01269198));
}

// @fnv 0x00e3c3b0
hkpShapeKey hkpSimpleMeshShape::GetNextShapeKey(hkpShapeKey oldKey) const
{
    for (int i = static_cast<int>(oldKey) + 1; i < m_uiTriangleCount.GetLogicalSize(); ++i)
    {
        if (!IsDegenerateTriangle(m_kVertices[m_uiTriangleCount[i].m_kPointA], m_kVertices[m_uiTriangleCount[i].m_kPointB],
                                  m_kVertices[m_uiTriangleCount[i].m_iThirdValue], DAT_011b2e90))
            return i;
    }
    return 0xffffffffu;
}
