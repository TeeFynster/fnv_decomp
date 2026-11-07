// Keep the original float-only SIMD intrinsic declaration: the CRT's byte-array
// aliases would make VC9 insert a /GS cookie in the collapse routine.
#define _INCLUDED_MM2
// Exe 0x00d739f0 FUN_00d739f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpBoxShape.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpConvexTransformShape.h"
#include "../../../../../../../include/hkpConvexTranslateShape.h"
#include "../../../../../../../include/hkpConvexVerticesShape.h"
#include "../../../../../../../include/hkpCylinderShape.h"
#include "../../../../../../../include/hkpListShape.h"
#include "../../../../../../../include/hkpListShapeChildInfo.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpTransformShape.h"

#include <math.h>

// src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct ShapeRefArray
{
    int* refs;
    int count;
};
struct ShapeData
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void _SharedShapeData_recursivelyParseShapeReferences(int);
    void _SharedShapeData_removeSingleReferencedShapeData();
    ShapeData* _SharedShapeData__SharedShapeData(ShapeRefArray* refs);
};
struct FUN_00d74980_Class
{
    int* refs;
    int count;
    int FindMappedValue(int value);
};
// RunContextOperation — __cdecl (caller pops its arguments).
//
// Builds a 12-byte context object on the stack, initializes it to
// (0, 0, 0x80000000), runs its setup pass, resets it, then delegates to the
// helper FUN_00d739f0 and stores its result through the caller's out pointer.
// Finally the context's cleanup pass runs and the function returns 0.
struct FUN_00d74420_Context
{
    int m_kPointA;  // +0x00
    int m_kPointB;  // +0x04
    int m_iThirdValue;  // +0x08, initialized to 0x80000000
    void _SharedShapeData_recursivelyParseShapeReferences(int value);
    void _SharedShapeData_removeSingleReferencedShapeData();
    void ProcessEntries_00d74aa0();
};
int hkpShape_ProcessEntries_00d739f0(int a1, int a2, FUN_00d74420_Context* ctx, int a3);
int RunContextOperation(int a1, int a2, int a3, int* out);
// Other units bind GetMonitorStream to 0x00c85750; the allocator is at +0x10.
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
void hkArrayUtil__reserve(void*, void*, int, int);
// Allocator-dependent array bodies are supplied by each unit, as declared in hkArray.h.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap());
}
template <class T> __forceinline void hkArrayUtil::construct(T*, int, hkTypeIsPod) {}
template <class T> __forceinline void hkArrayUtil::destruct(T*, int, hkTypeIsPod) {}
template <class T> __forceinline void hkArrayUtil::constructWithCopy(T* t, int n, const T& tcopy, hkTypeIsPod)
{
    for (int i = 0; i < n; ++i)
        t[i] = tcopy;
}
template <class T> __forceinline void hkArrayBase<T>::clear()
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsPod());
    m_iElementCount = 0;
}
template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}
template <class T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        int cap2 = 2 * capacity;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
    }
}
template <class T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    hkArrayUtil::destruct(m_data + n, m_iElementCount - n, hkTypeIsPod());
    hkArrayUtil::construct(m_data + m_iElementCount, n - m_iElementCount, hkTypeIsPod());
    m_iElementCount = n;
}
template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}
template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}
struct D749Entry
{
    int m_key0;
    int m_uiFilterValue;
    int m_key1;
};
class D749Table
{
  public:
    D749Entry* m_data;
    int m_uiItemCount;

    int SetEntryValue(int key, int value);
};
struct EntryD738
{
    int m_pCollisionShape;
    int m_unk04;
    int m_iObjectReferenceCount;
};

// src: GUESS 0x00d737d0 (confidence: high)
static __declspec(noinline) void hkpShape_AppendChildShapesByType(hkpShape* shape, hkArray<hkpShape*>* out)
{
    switch (shape->getType())
    {
    case 9: {
        hkpListShape* list = static_cast<hkpListShape*>(shape);
        for (int i = 0; i < static_cast<hkpShapeContainer&>(*list).GetNumChildShapes(); i++)
            out->pushBack(const_cast<hkpShape*>(list->getChildShapeInl(i)));
    }
    break;
    case 11:
        out->pushBack(const_cast<hkpShape*>(static_cast<hkpConvexTranslateShape*>(shape)->m_pContainedShape.getChild()));
        break;
    case 12:
        out->pushBack(const_cast<hkpShape*>(static_cast<hkpConvexTransformShape*>(shape)->m_pContainedShape.getChild()));
        break;
    case 15:
        out->pushBack(const_cast<hkpShape*>(static_cast<hkpTransformShape*>(shape)->m_pContainedShape.getChild()));
        break;
    }
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

static __forceinline int indexOfD738(ShapeData* self, int value)
{
    for (int i = 0; i < self->m_kPointB; i++)
        if (((EntryD738*)self->m_kPointA)[i].m_pCollisionShape == value)
            return i;
    return -1;
}

static __forceinline void addShapeD738(ShapeData* self, int value)
{
    EntryD738 e;
    e.m_pCollisionShape = value;
    e.m_unk04 = 0;
    e.m_iObjectReferenceCount = 1;
    hkMemoryAllocator& kAlloc = reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap());
    if (self->m_kPointB == (self->m_iThirdValue & 0x3fffffff))
        ResizeAudioStream(&kAlloc, self, sizeof(EntryD738));
    new ((EntryD738*)self->m_kPointA + self->m_kPointB) EntryD738(e);
    self->m_kPointB++;

    ((hkReferencedObject*)value)->addReference();

    hkArray<hkpShape*> children;
    hkpShape_AppendChildShapesByType((hkpShape*)value, &children);
    for (int i = 0; i < children.m_iElementCount; i++)
        self->_SharedShapeData_recursivelyParseShapeReferences((int)children.m_data[i]);
}

// @fnv 0x00d738f0
// src: HAVOK_LIB 0x00d738f0
void ShapeData::_SharedShapeData_recursivelyParseShapeReferences(int value)
{
    int index = indexOfD738(this, value);
    if (index >= 0)
    {
        ((EntryD738*)m_kPointA)[index].m_iObjectReferenceCount++;
        return;
    }
    addShapeD738(this, value);
}

// Inline implementations used by this unit, with storage supplied by include/.
inline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal() {}
inline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
inline const LocalM128& hkSimdReal::getQuad() const { return m_vValue; }
__forceinline hkVector4::hkVector4(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
__forceinline hkSimdReal hkVector4::length3() const { return _mm_sqrt_ss(this->dot3(*this).getQuad()); }
__forceinline float& hkVector4::operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
__forceinline const float& hkVector4::operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
__forceinline hkRotation::hkRotation() {}
__forceinline const hkVector4& hkRotation::getColumn(int i) const { return (&m_kColumn0)[i]; }
inline void hkRotation::operator=(const hkRotation& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}
__forceinline void hkRotation::setIdentity()
{
    hkVector4 zero;
    zero.setZero4();
    m_kColumn0 = zero;
    m_kColumn1 = zero;
    m_kColumn2 = zero;
    float one = 1.0f;
    m_kColumn0(0) = one;
    m_kColumn1(1) = one;
    m_kColumn2(2) = one;
}
__forceinline hkTransform::hkTransform() {}
__forceinline hkRotation& hkTransform::getRotation() { return reinterpret_cast<hkRotation&>(m_row0); }
__forceinline const hkRotation& hkTransform::getRotation() const { return reinterpret_cast<const hkRotation&>(m_row0); }
__forceinline hkVector4& hkTransform::getTranslation() { return reinterpret_cast<hkVector4&>(m_row3); }
__forceinline const hkVector4& hkTransform::getTranslation() const { return reinterpret_cast<const hkVector4&>(m_row3); }
__forceinline void hkTransform::SetBodyOrientation(const hkRotation& r) { getRotation() = r; }
__forceinline void hkTransform::setTranslation(const hkVector4& t) { getTranslation() = t; }
__forceinline void hkTransform::setIdentity() { getRotation().setIdentity(); getTranslation().setZero4(); }
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.getRotation().getColumn(0);
    const hkVector4 r1 = t.getRotation().getColumn(1);
    const hkVector4 r2 = t.getRotation().getColumn(2);
    const hkVector4 r3 = t.getTranslation();
    const_cast<hkVector4&>(getRotation().getColumn(0)) = r0;
    const_cast<hkVector4&>(getRotation().getColumn(1)) = r1;
    const_cast<hkVector4&>(getRotation().getColumn(2)) = r2;
    getTranslation() = r3;
}
__forceinline void hkTransform::operator=(const hkTransform& t)
{
    getRotation() = t.getRotation();
    getTranslation() = t.getTranslation();
}
__forceinline void setTransformedPos(hkVector4& result, const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    LocalM128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    LocalM128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    LocalM128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    result.m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}
extern hkTransform DAT_01268370;
extern int DAT_010d0e5c;
extern float DAT_011b153c;
extern const double DAT_01032980;

__forceinline hkMemoryAllocator& heapAllocator()
{
    return reinterpret_cast<hkMemoryAllocator&>((&hkMemoryRouter::getInstance())->heap());
}
struct FloatArrayDescriptor
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};
extern LocalM128 DAT_010c4c10;
__forceinline void* shapeNew(int nbytes)
{
    hkpShape* b = static_cast<hkpShape*>(heapAllocator().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}

// The shared headers omit these pointer-returning initializers, vector
// overloads and cylinder getter. Typed thiscall adapters retain the original
// entry points without duplicating a game class.
extern "C" void setTransformedPos_00c7f640();
extern "C" void hkVector4_setRotatedDir();
extern "C" void FUN_00cf5990();
extern "C" void FUN_00d22590();
extern "C" void FUN_00d571a0();
extern "C" void hkpCylinderShape_hkpCylinderShape();
extern "C" void hkpConvexTransformShape_hkpConvexTransformShape();
__forceinline void transformPoint(hkVector4& result, const hkTransform* transform, const hkVector4* point)
{
    reinterpret_cast<void(__thiscall*)(hkVector4*, const hkTransform*, const hkVector4*)>(setTransformedPos_00c7f640)(&result, transform, point);
}
__forceinline const hkpShape* hkpTransformShape::GetShapeForKey() const { return m_pContainedShape.getChild(); }
__forceinline const hkTransform& hkpTransformShape::getTransform() const { return m_kMotionTransform; }
__forceinline const hkpConvexShape* hkpConvexTransformShape::GetShapeForKey() const
{
    return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild());
}
__forceinline const hkpConvexShape* hkpConvexTranslateShape::GetShapeForKey() const
{
    return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild());
}
__forceinline const hkVector4* hkpCapsuleShape::GetIndexedVertices() const { return &m_kVertexA; }
__forceinline const hkpShape* hkpListShape::getChildShapeInl(int i) const { return m_kChildInfoList.m_data[i].m_pCollisionShape; }
__forceinline hkpShapeType hkpShape::getType() const { return reinterpret_cast<const hkpShapeType&>(m_type); }
__forceinline hkpConvexTranslateShape* hkpConvexTranslateShape::init(const hkpConvexShape* child, const hkVector4& translation)
{
    // The base initializer returns through the original constructor ABI.
    extern void __cdecl initializeConvexTransformBase();
    reinterpret_cast<void(__thiscall*)(hkpConvexTransformShapeBase*, int, float, const hkpConvexShape*, int)>(initializeConvexTransformBase)(this, 11, child->m_fSphereRadius, child, 1);
    *reinterpret_cast<void**>(this) = &DAT_010d0e5c;
    m_vTranslation.m_vComponents = _mm_and_ps(translation.m_vComponents, DAT_010c4c10);
    m_iChildShapeSize = 0;
    return this;
}
struct Options
{
    int m_iFirstOptionValue, m_iSecondOptionValue;
    hkBool m_bOptionFlag;
};
struct Results
{
    int m_iFirstResult, m_iSecondResult, m_iThirdResult, m_numPropagatedTransformsInLists;
};
__forceinline void TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        setTransformedPos(vectorsOut[i], unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
// @fnv 0x00d739f0
// src: GUESS 0x00d739f0 (confidence: low)
const hkpShape* hkpShape_ProcessEntries_00d739f0(const hkpShape* transformShape, const Options& options, D749Table& sharedShapeData,
                             Results& resultsOut)
{
    const int transformShapeType = transformShape->getType();
    hkTransform parentFromChild;
    const hkpShape* childShape = 0;
    switch (transformShapeType)
    {
    case 15: {
        const hkpTransformShape* tformshape = static_cast<const hkpTransformShape*>(transformShape);
        parentFromChild = tformshape->getTransform();
        childShape = tformshape->GetShapeForKey();
        break;
    }
    case 12: {
        const hkpConvexTransformShape* ctformshape = static_cast<const hkpConvexTransformShape*>(transformShape);
        parentFromChild = ctformshape->getTransform();
        childShape = ctformshape->GetShapeForKey();
        break;
    }
    case 11: {
        const hkpConvexTranslateShape* ctlateshape = static_cast<const hkpConvexTranslateShape*>(transformShape);
        parentFromChild.setIdentity();
        parentFromChild.setTranslation(ctlateshape->getTranslation());
        childShape = ctlateshape->GetShapeForKey();
        break;
    }
    default:
        transformShape->addReference();
        return transformShape;
    }
    const int childShapeType = childShape->getType();
    if (childShapeType == 1)
        parentFromChild.SetBodyOrientation(DAT_01268370.getRotation());
    if (parentFromChild.IsEqualWithinTolerance(DAT_01268370, 1e-3f))
    {
        resultsOut.m_iSecondResult++;
        childShape->addReference();
        sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(childShape));
        return childShape;
    }
    bool allowChangesToChildShape = true;
    switch (options.m_iFirstOptionValue)
    {
    case 0:
        allowChangesToChildShape = true;
        break;
    case 1:
        allowChangesToChildShape = false;
        break;
    case 2:
        allowChangesToChildShape =
            reinterpret_cast<FUN_00d74980_Class&>(sharedShapeData).FindMappedValue(reinterpret_cast<int>(childShape)) <
            options.m_iSecondOptionValue;
        break;
    }
    if (childShapeType == 9)
    {
        const hkpListShape* listShape = static_cast<const hkpListShape*>(childShape);
        if (!options.m_bOptionFlag && allowChangesToChildShape)
        {
            resultsOut.m_numPropagatedTransformsInLists++;
            hkArray<const hkpShape*> newChildren;
            for (int i = 0; i < reinterpret_cast<const hkpShapeContainer*>(reinterpret_cast<const char*>(listShape) + sizeof(hkpShape))->GetNumChildShapes(); i++)
            {
                const hkpShape* grandChildShape = listShape->getChildShapeInl(i);
                hkpTransformShape* wrapperMem = static_cast<hkpTransformShape*>(shapeNew(0x70));
                const hkpShape* childTransformShape = reinterpret_cast<hkpTransformShape*(__thiscall*)(hkpTransformShape*, const hkpShape*, const hkTransform*)>(FUN_00cf5990)(wrapperMem, grandChildShape, &parentFromChild);
                const hkpShape* collapsedGrandChild =
                    hkpShape_ProcessEntries_00d739f0(childTransformShape, options, sharedShapeData, resultsOut);
                newChildren.pushBack(collapsedGrandChild);
                childTransformShape->removeReference();
            }
            hkpListShape* newListMem = static_cast<hkpListShape*>(shapeNew(0x70));
            hkpListShape* newListShape = newListMem->FUN_00cf5640(newChildren.begin(), newChildren.GetLogicalSize(), 1);
            for (int n = 0; n < newChildren.GetLogicalSize(); n++)
                newChildren[n]->removeReference();
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newListShape));
            return newListShape;
        }
        transformShape->addReference();
        return transformShape;
    }
    if (allowChangesToChildShape)
    {
        switch (childShapeType)
        {
        case 5: {
            const hkpCapsuleShape* childCapsuleShape = static_cast<const hkpCapsuleShape*>(childShape);
            const hkVector4* childA = &childCapsuleShape->GetIndexedVertices()[0];
            const hkVector4* childB = &childCapsuleShape->GetIndexedVertices()[1];
            const float radius = childCapsuleShape->getRadius();
            hkVector4 parentA;
            transformPoint(parentA, &parentFromChild, childA);
            hkVector4 parentB;
            transformPoint(parentB, &parentFromChild, childB);
            hkpCapsuleShape* newCapsuleMem = static_cast<hkpCapsuleShape*>(shapeNew(0x40));
            hkpCapsuleShape* newCapsule = reinterpret_cast<hkpCapsuleShape*(__thiscall*)(hkpCapsuleShape*, const hkVector4&, const hkVector4&, float)>(FUN_00d22590)(newCapsuleMem, parentA, parentB, radius);
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newCapsule));
            resultsOut.m_iFirstResult++;
            return newCapsule;
        }
        case 2: {
            const hkpCylinderShape* childCylinderShape = static_cast<const hkpCylinderShape*>(childShape);
            const hkVector4* childA = &childCylinderShape->GetIndexedVertices()[0];
            const hkVector4* childB = &childCylinderShape->GetIndexedVertices()[1];
            const float cylRadius = reinterpret_cast<float(__thiscall*)(const hkpCylinderShape*)>(FUN_00d571a0)(childCylinderShape);
            const float radius = childCylinderShape->getRadius();
            hkVector4 parentA;
            transformPoint(parentA, &parentFromChild, childA);
            hkVector4 parentB;
            transformPoint(parentB, &parentFromChild, childB);
            hkpCylinderShape* newCylinderMem = static_cast<hkpCylinderShape*>(shapeNew(0x60));
            hkpCylinderShape* newCylinder = reinterpret_cast<hkpCylinderShape*(__thiscall*)(hkpCylinderShape*, const hkVector4&, const hkVector4&, float, float)>(hkpCylinderShape_hkpCylinderShape)(newCylinderMem, parentA, parentB, cylRadius, radius);
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newCylinder));
            resultsOut.m_iFirstResult++;
            return newCylinder;
        }
        case 6: {
            const hkpConvexVerticesShape* childCVShape = static_cast<const hkpConvexVerticesShape*>(childShape);
            hkArray<hkVector4> vertices;
            childCVShape->GetOriginalVertices(vertices);
            TransformPointArray(parentFromChild, vertices.begin(), vertices.GetLogicalSize(), vertices.begin());
            FloatArrayDescriptor newverts;
            newverts.m_iStridedVertexCount = vertices.GetLogicalSize();
            newverts.m_iVertexStride = 16;
            newverts.m_kVertices = &vertices[0](0);
            const hkArray<hkVector4>& planes = childCVShape->GetPlaneEquations();
            hkArray<hkVector4> newplanes;
            newplanes.setSize(planes.GetLogicalSize());
            hkVector4 pivotShift(parentFromChild.getTranslation());
            for (int p = 0; p < planes.GetLogicalSize(); p++)
            {
                hkVector4 plane;
                _mm_store_ps(reinterpret_cast<float*>(&plane.m_vComponents), planes[p].m_vComponents);
                const float newDist = plane(3) - pivotShift.dot3(plane);
                reinterpret_cast<void(__thiscall*)(hkVector4*, const hkRotation&, const hkVector4&)>(hkVector4_setRotatedDir)(&plane, parentFromChild.getRotation(), plane);
                plane(3) = newDist;
                newplanes[p] = plane;
            }
            hkpConvexVerticesShape* newCVShapeMem = static_cast<hkpConvexVerticesShape*>(shapeNew(0x70));
            hkpConvexVerticesShape* newCVShape =
                newCVShapeMem->Initialize(newverts, newplanes, childCVShape->getRadius());
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newCVShape));
            resultsOut.m_iFirstResult++;
            return newCVShape;
        }
        case 4: {
            const double& tol = DAT_01032980;
            if (!(parentFromChild.getRotation().IsOrthonormal(1e-3f) && parentFromChild.getRotation().isOk()))
                break;
            if (parentFromChild.getRotation().IsEqualWithinTolerance(DAT_01268370.getRotation(), 1e-3f))
                break;
            bool failedA = false;
            bool failedB = false;
            int map[3];
            for (int i = 0; i < 3; i++)
            {
                const hkVector4& axisRot = parentFromChild.getRotation().getColumn(i);
                bool passedA1 = false;
                for (int j = 0; j < 3; j++)
                {
                    const bool testA0 = fabsf(axisRot(j)) < tol;
                    const bool testA1 = fabsf(fabsf(axisRot(j)) - 1.0f) < tol;
                    if (!testA0 && !testA1)
                    {
                        failedA = true;
                        break;
                    }
                    if (testA1)
                    {
                        map[j] = i;
                        passedA1 = true;
                    }
                }
                if (!passedA1)
                    failedA = true;
                if (failedA)
                    break;
                float sum = 0.0f;
                for (int j = 0; j < 3; j++)
                    sum += fabsf(axisRot(j));
                failedB = !(sum - 1.0f < tol);
                if (failedB)
                    break;
            }
            if (failedA || failedB)
                break;
            const hkpBoxShape* childBoxShape = static_cast<const hkpBoxShape*>(childShape);
            const hkVector4& halfExtents = childBoxShape->getHalfExtents();
            hkVector4 newHalfExtents(halfExtents(map[0]), halfExtents(map[1]), halfExtents(map[2]), 0.0f);
            hkpBoxShape* newBoxShapeMem = static_cast<hkpBoxShape*>(shapeNew(0x30));
            hkpBoxShape* newBoxShape = newBoxShapeMem->SetExtentsAndRadius(newHalfExtents, DAT_011b153c);
            if (parentFromChild.getTranslation().length3() < tol)
            {
                sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape),
                                              reinterpret_cast<int>(newBoxShape));
                resultsOut.m_iFirstResult++;
                return newBoxShape;
            }
            hkpConvexTranslateShape* newShapeMem = static_cast<hkpConvexTranslateShape*>(shapeNew(0x30));
            hkpConvexTranslateShape* pRemappedShape = newShapeMem->init(newBoxShape, parentFromChild.getTranslation());
            newBoxShape->removeReference();
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(pRemappedShape));
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
        }
    }
    switch (childShapeType)
    {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 18: {
        const hkpConvexShape* childConvexShape = static_cast<const hkpConvexShape*>(childShape);
        hkBool translateOnly = parentFromChild.getRotation().IsEqualWithinTolerance(DAT_01268370.getRotation(), 1e-3f);
        if (translateOnly && transformShapeType != 11)
        {
            hkpConvexTranslateShape* newShapeMem = static_cast<hkpConvexTranslateShape*>(shapeNew(0x30));
            hkpConvexTranslateShape* pRemappedShape =
                newShapeMem->init(childConvexShape, parentFromChild.getTranslation());
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(pRemappedShape));
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
        if (transformShapeType == 15)
        {
            hkpConvexTransformShape* newShapeMem = static_cast<hkpConvexTransformShape*>(shapeNew(0x60));
            hkpConvexTransformShape* pRemappedShape = reinterpret_cast<hkpConvexTransformShape*(__thiscall*)(hkpConvexTransformShape*, const hkpConvexShape*, const hkTransform*, int)>(hkpConvexTransformShape_hkpConvexTransformShape)(newShapeMem, childConvexShape, &parentFromChild, 1);
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(pRemappedShape));
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
    }
    }
    transformShape->addReference();
    return transformShape;
}
