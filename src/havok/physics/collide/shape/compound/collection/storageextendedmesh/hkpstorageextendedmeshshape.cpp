
// src/havok/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/storageextendedmesh/hkpstorageextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpStorageExtendedMeshShape.h"
#include "../../../../../../../../include/hkVector4q.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../../include/hkpMeshMaterial.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../../include/hkStringPtr.h"

typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef int hkInt32;
typedef unsigned int hkUint32;
typedef short hkHalf;

// Specialization of the shared IsPodType trait for the unsigned-short array element; no separate local trait.
template <> struct IsPodType<hkUint16> : hkTypeIsPod {};




void FUN_00d4ac70();

struct ShapeSubpartStorage
{
    virtual void Release(void*, unsigned short)
    {}
    unsigned short m_iElementCount;

    ShapeSubpartStorage* FUN_00d4ad20(int deletingFlag);
};

// @fnv 0x00d4ad20
ShapeSubpartStorage* ShapeSubpartStorage::FUN_00d4ad20(int deletingFlag)
{
    FUN_00d4ac70();

    if (deletingFlag & 1)
    {
        hkMemoryRouter* memoryManager = (&hkMemoryRouter::getInstance());
        unsigned short size = m_iElementCount;
        reinterpret_cast<hkMemoryAllocator*>(memoryManager->m_heap)->blockFree(this, size);
    }

    return this;
}

namespace fnv_00d4b120 {

struct hkpStorageExtendedMeshShape_MeshSubpartStorage
{
    void* m_unknown;
    unsigned short m_iElementCount;

    void FUN_00d4af60();
    hkpStorageExtendedMeshShape_MeshSubpartStorage* DestroyStorage(unsigned int);
};

// @fnv 0x00d4b120
hkpStorageExtendedMeshShape_MeshSubpartStorage* hkpStorageExtendedMeshShape_MeshSubpartStorage::DestroyStorage(
    unsigned int deletingDestructor)
{
    FUN_00d4af60();

    if (deletingDestructor & 1)
    {
        hkMemoryRouter* context = &hkMemoryRouter::getInstance();
        context->m_heap->blockFree(this, m_iElementCount);
    }

    return this;
}
}  // namespace fnv_00d4b120

extern int DAT_010cfd84;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* SetVptr_00d4a170(unsigned int unusedArg);
};

// @fnv 0x00d4a170
// src: GUESS 0x00d4a170 (confidence: low)
FnvVtObj* FnvVtObj::SetVptr_00d4a170(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010cfd84;
    return this;
}

class hkpStorageExtendedMeshShapeMeshSubpartStorage : public hkReferencedObject
{
};

class hkpStorageExtendedMeshShapeShapeSubpartStorage : public hkReferencedObject
{
};

struct FUN_00d56800
{
    int m_kNextStreamField[16];
    ~FUN_00d56800() throw();
};

struct FUN_00d56e00 : public hkpShape, public hkpShapeContainer
{
    int m_aiUnk14[43];
    hkArray<FUN_00d56800> m_kTrianglesSubparts;
    int m_aiUnkCC[9];
    ~FUN_00d56e00() throw();
};

class FUN_00d49cb0 : public FUN_00d56e00
{
  public:
    hkArray<hkpStorageExtendedMeshShapeMeshSubpartStorage*> m_kMeshSubparts;
    hkArray<hkpStorageExtendedMeshShapeShapeSubpartStorage*> m_kShapeSubparts;
    int m_aiUnk108[2];
    ~FUN_00d49cb0() throw();
};

// @fnv 0x00d49cb0
FUN_00d49cb0::~FUN_00d49cb0() throw()
{
    for (int i = 0; i < m_kMeshSubparts.m_iElementCount; i++)
        m_kMeshSubparts.m_data[i]->removeReference();
    m_kTrianglesSubparts.clear();
    for (int i = 0; i < m_kShapeSubparts.m_iElementCount; i++)
        m_kShapeSubparts.m_data[i]->removeReference();
}

class FUN_00d4a170
{
  public:
    virtual void CalcSizeForSpu() throw();
    int m_usMemSizeAndFlags;
    hkArray<hkReal> m_kVertices;
    hkArray<hkUint8> m_kIndices8;
    hkArray<hkUint16> m_kIndices16;
    hkArray<hkUint32> m_kIndices32;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<void*> m_kNamedMaterials;
    hkArray<hkUint32> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    FUN_00d4a170(FinishingFlag flag) throw();
};

class FUN_00d49c40
{
  public:
    virtual void CalcSizeForSpu() throw();
    int m_usMemSizeAndFlags;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<hkUint32> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    FUN_00d49c40(FinishingFlag flag) throw();
};

__declspec(noinline) FUN_00d49c40::FUN_00d49c40(FinishingFlag flag) throw()
    : m_kMaterialIndices8(FinishingFlag(flag.m_bFinishing)), m_kMaterials(FinishingFlag(flag.m_bFinishing)),
      m_kMaterialIndices16(FinishingFlag(flag.m_bFinishing))
{}

__declspec(noinline) FUN_00d4a170::FUN_00d4a170(FinishingFlag flag) throw()
    : m_kVertices(FinishingFlag(flag.m_bFinishing)), m_kIndices8(FinishingFlag(flag.m_bFinishing)),
      m_kIndices16(FinishingFlag(flag.m_bFinishing)), m_kIndices32(FinishingFlag(flag.m_bFinishing)),
      m_kMaterialIndices8(FinishingFlag(flag.m_bFinishing)), m_kNamedMaterials(FinishingFlag(flag.m_bFinishing)),
      m_kMaterials(FinishingFlag(flag.m_bFinishing)), m_kMaterialIndices16(FinishingFlag(flag.m_bFinishing))
{}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}

struct hkpTrianglesSubpartD4A1
{
    hkUint8 m_type;
    hkUint8 m_iMaterialIndexType;
    char m_pad02[2];
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iIndexStriding;
    int m_iNumTriangles;
    const float* m_pMaterialIndexBase;
    char m_pad1c[0x24];
    const void* m_pMaterialDataBase;
    int m_iMaterialStriding;
    hkUint8 m_ucIndexStridingType;
    char m_pad49[0x17];
};

struct hkpShapesSubpartD4A1
{
    hkUint8 m_type;
    hkUint8 m_iMaterialIndexType;
    char m_pad02[2];
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    char m_pad10[0x30];
};

class FUN_00d56f10 : public hkpShape, public hkpShapeContainer
{
  public:
    char m_pad14[0xa0];
    hkArray<hkpTrianglesSubpartD4A1> m_kTrianglesSubparts;
    hkArray<hkpShapesSubpartD4A1> m_kShapesSubparts;
    char m_padCC[0x24];

    FUN_00d56f10(FinishingFlag flag) throw();
};

class FUN_00d4a180 : public FUN_00d56f10
{
  public:
    hkArray<FUN_00d4a170*> m_kMeshSubparts;
    hkArray<FUN_00d49c40*> m_kShapeSubparts;
    char m_pad108[0x8];

    FUN_00d4a180(FinishingFlag flag) throw();
};

// @fnv 0x00d4a180
FUN_00d4a180::FUN_00d4a180(FinishingFlag flag) throw()
    : FUN_00d56f10(flag), m_kMeshSubparts(FinishingFlag(flag.m_bFinishing)), m_kShapeSubparts(FinishingFlag(flag.m_bFinishing))
{
    if (flag.m_bFinishing)
    {
        for (int i = 0; i < m_kTrianglesSubparts.m_iElementCount; i++)
        {
            hkpTrianglesSubpartD4A1& kPart = m_kTrianglesSubparts.m_data[i];
            new (m_kMeshSubparts.m_data[i]) FUN_00d4a170(flag);
            FUN_00d4a170* pkStorage = m_kMeshSubparts.m_data[i];
            kPart.m_pMaterialIndexBase = pkStorage->m_kVertices.m_data;
            kPart.m_pMaterialDataBase = (kPart.m_ucIndexStridingType == 1) ? (const void*)pkStorage->m_kIndices8.m_data
                                        : (kPart.m_ucIndexStridingType == 2)
                                            ? (const void*)pkStorage->m_kIndices16.m_data
                                            : (const void*)pkStorage->m_kIndices32.m_data;
            kPart.m_pVertexBase = (kPart.m_iMaterialIndexType == 1)
                                      ? (const void*)pkStorage->m_kMaterialIndices8.m_data
                                      : (const void*)pkStorage->m_kMaterialIndices16.m_data;
            if (pkStorage->m_kMaterials.m_iElementCount)
                kPart.m_pIndexBase = pkStorage->m_kMaterials.m_data;
            else
                kPart.m_pIndexBase = pkStorage->m_kNamedMaterials.m_data;
        }
        for (int i = 0; i < m_kShapesSubparts.m_iElementCount; i++)
        {
            hkpShapesSubpartD4A1& kPart = m_kShapesSubparts.m_data[i];
            new (m_kShapeSubparts.m_data[i]) FUN_00d49c40(flag);
            FUN_00d49c40* pkStorage = m_kShapeSubparts.m_data[i];
            kPart.m_pVertexBase = (kPart.m_iMaterialIndexType == 1)
                                      ? (const void*)pkStorage->m_kMaterialIndices8.m_data
                                      : (const void*)pkStorage->m_kMaterialIndices16.m_data;
            kPart.m_pIndexBase = pkStorage->m_kMaterials.m_data;
        }
    }
}

struct FUN_00d4aec0_Class
{
    unsigned short m_usMemSizeAndFlags;
    void FUN_00d49cb0();
    virtual FUN_00d4aec0_Class* FUN_00d4aec0(unsigned char flags);
};
// @fnv 0x00d4aec0
FUN_00d4aec0_Class* FUN_00d4aec0_Class::FUN_00d4aec0(unsigned char flags)
{
    FUN_00d49cb0();
    if (flags & 1)
    {
        hkMemoryRouter* mgr = (&hkMemoryRouter::getInstance());
        reinterpret_cast<hkMemoryAllocator*>(mgr->m_heap)->blockFree(this, m_usMemSizeAndFlags);
    }
    return this;
}

// No shared hkpNamedMeshMaterial header yet: filter info followed by hkStringPtr (destructor 0x00cb0c00).
struct hkpNamedMeshMaterial : public hkpMeshMaterial
{
    hkStringPtr m_name;
};

namespace fnv_00d4aef0 {
struct hkpStorageExtendedMeshShapeMaterialD4AE : public hkpMeshMaterial
{
    hkHalf m_fElasticity;
    hkHalf m_fSlipAngle;
    hkUlong m_ulUserData;
};

class FUN_00d4aef0 : public hkReferencedObject
{
  public:
    hkArray<hkVector4> m_kVertices;
    hkArray<hkUint8> m_kIndices8;
    hkArray<hkUint16> m_kIndices16;
    hkArray<hkUint32> m_kIndices32;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<hkpStorageExtendedMeshShapeMaterialD4AE> m_kMaterials;
    hkArray<hkpNamedMeshMaterial> m_kNamedMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    FUN_00d4aef0() throw();
    virtual ~FUN_00d4aef0() throw();
};

// @fnv 0x00d4aef0
FUN_00d4aef0::FUN_00d4aef0() throw()
{}
}  // namespace fnv_00d4aef0

namespace fnv_00d4af60 {
struct hkpStorageExtendedMeshShapeMaterialD4AF : public hkpMeshMaterial
{
    hkHalf m_fElasticity;
    hkHalf m_fSlipAngle;
    hkUlong m_ulUserData;
};

class FUN_00d4af60 : public hkReferencedObject
{
  public:
    hkArray<hkVector4> m_kVertices;
    hkArray<hkUint8> m_kIndices8;
    hkArray<hkUint16> m_kIndices16;
    hkArray<hkUint32> m_kIndices32;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<hkpStorageExtendedMeshShapeMaterialD4AF> m_kMaterials;
    hkArray<hkpNamedMeshMaterial> m_kNamedMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    virtual ~FUN_00d4af60() throw();
};

// @fnv 0x00d4af60
FUN_00d4af60::~FUN_00d4af60() throw()
{}
}  // namespace fnv_00d4af60


// Havok's inline array operations use this unit's stream allocator.
template <typename T> __forceinline void hkArrayUtil::construct(T* data, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        new (data + i) T;
}
template <typename T> __forceinline void hkArrayUtil::destruct(T* data, int n, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        data[i].~T();
}
template <typename T> __forceinline void hkArrayUtil::constructWithArray(T* data, int n, const T* source, hkTypeIsClass)
{
    for (int i = 0; i < n; ++i)
        new (data + i) T(source[i]);
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsClass());
    m_iElementCount = 0;
}

template <typename T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& count)
{
    int bytes = count * sizeof(T);
    void* p = bufAlloc(bytes);
    count = bytes / (int)sizeof(T);
    return (T*)p;
}
template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int count)
{
    bufFree(p, count * sizeof(T));
}

template <typename T> __forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(
    hkMemoryAllocator& kHeap, const hkArrayBase<T>& kSrc, hkTypeIsPod)
{
    if (getCapacity() < kSrc.GetLogicalSize())
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap._bufFree<T>(m_data, getCapacity());
        int iCount = kSrc.GetLogicalSize();
        m_data = kHeap._bufAlloc<T>(iCount);
        m_iCapacityState = iCount;
    }
    m_iElementCount = kSrc.GetLogicalSize();
    copy(m_data, kSrc.m_data, m_iElementCount);
    return *this;
}

template <typename T> __forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(
    hkMemoryAllocator& kHeap, const hkArrayBase<T>& kSrc, hkTypeIsClass)
{
    int iWas = m_iElementCount;
    int iNow = kSrc.m_iElementCount;
    int iShared = iNow > iWas ? iWas : iNow;
    GrowArrayCapacity(kHeap, iNow);
    hkArrayUtil::destruct(m_data + iNow, iWas - iNow, hkTypeIsClass());
    copy(m_data, kSrc.m_data, iShared);
    hkArrayUtil::constructWithArray(m_data + iShared, iNow - iShared, kSrc.m_data + iShared, hkTypeIsClass());
    m_iElementCount = iNow;
    return *this;
}

template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray& a)
{
    copyFromArray(hkMemoryRouter::getInstance().heap(), a, typename IsPodType<T>::type());
    return *this;
}

// The serialized subpart's translation is copied component by component in this unit.
__forceinline void hkVector4::operator=(const hkVector4& vector)
{
    *reinterpret_cast<hkUint32*>(&x) = *reinterpret_cast<const hkUint32*>(&vector.x);
    *reinterpret_cast<hkUint32*>(&y) = *reinterpret_cast<const hkUint32*>(&vector.y);
    *reinterpret_cast<hkUint32*>(&z) = *reinterpret_cast<const hkUint32*>(&vector.z);
    *reinterpret_cast<hkUint32*>(&w) = *reinterpret_cast<const hkUint32*>(&vector.w);
}

__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&q);
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

// @fnv 0x00d4ac70
hkpStorageExtendedMeshShape::ShapeSubpartStorage::~ShapeSubpartStorage() throw()
{}

#include <xmmintrin.h>
namespace fnv_00d4aa70 {
struct hkpTrianglesSubpartD4AA
{
    char m_pad00[0x60];
};

struct hkpShapesSubpartD4AA
{
    char m_pad00[0x40];
};

class FUN_00d569c0 : public hkpShape, public hkpShapeContainer
{
  public:
    char m_bDisableWelding;
    char m_pad15[0x6b];
    hkVector4q m_kAabbHalfExtents;
    hkVector4q m_kAabbCenter;
    char m_padA0[0x10];
    int m_iNumBitsForSubpartIndex;
    hkArray<hkpTrianglesSubpartD4AA> m_kTrianglesSubparts;
    hkArray<hkpShapesSubpartD4AA> m_kShapesSubparts;
    hkArray<hkUint16> m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    char m_padD9[0xb];
    hkReal m_fSphereRadius;
    char m_padE8[0x8];

    FUN_00d569c0(hkReal fRadius, int iNumBitsForSubpartIndex) throw();
    void hkpExtendedMeshShape_recalcAabbExtents() throw();
};

class FUN_00d4aa70 : public FUN_00d569c0
{
  public:
    hkArray<void*> m_kMeshSubparts;
    hkArray<void*> m_kShapeSubparts;
    char m_pad108[0x8];

    FUN_00d4aa70(const FUN_00d569c0* pkMesh) throw();
    void addTrianglesSubpart(const hkpTrianglesSubpartD4AA& kPart) throw();
    void addShapesSubpart(const hkpShapesSubpartD4AA& kPart) throw();
};

typedef char fnv_check_d4aa70_a[(sizeof(FUN_00d4aa70) == 0x110) ? 1 : -1];

// Constructs from pkMesh, copies its half extents, user data and welding data, calls FUN_00d4a2b0 and FUN_00d49dc0 per subpart, then FUN_00d55950.
// @fnv 0x00d4aa70
FUN_00d4aa70::FUN_00d4aa70(const FUN_00d569c0* pkMesh) throw()
    : FUN_00d569c0(pkMesh->m_fSphereRadius, pkMesh->m_iNumBitsForSubpartIndex)
{
    m_kAabbHalfExtents = pkMesh->m_kAabbHalfExtents;
    m_ulUserData = pkMesh->m_ulUserData;
    m_bDisableWelding = pkMesh->m_bDisableWelding;

    for (int i = 0; i < pkMesh->m_kTrianglesSubparts.GetLogicalSize(); i++)
        addTrianglesSubpart(pkMesh->m_kTrianglesSubparts[i]);
    for (int i = 0; i < pkMesh->m_kShapesSubparts.GetLogicalSize(); i++)
        addShapesSubpart(pkMesh->m_kShapesSubparts[i]);

    m_kWeldingInfo = pkMesh->m_kWeldingInfo;
    m_eWeldingType = pkMesh->m_eWeldingType;
    hkpExtendedMeshShape_recalcAabbExtents();
}
}  // namespace fnv_00d4aa70

struct hkpExtendedMeshShapeSubpartD4AB
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    hkUlong m_ulUserData;
};

struct hkpExtendedMeshShapeTrianglesSubpartD4AB : public hkpExtendedMeshShapeSubpartD4AB
{
    int m_iVertexStride;
    const hkReal* m_pMaterialIndexBase;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    hkVector4q m_kVertexTransform;
    int m_iTriangleIndexStride;
    int m_iMaterialStriding;
    hkInt8 m_ucIndexStridingType;
    hkInt8 m_bFlipAlternateTriangles;
    int m_iTriangleOffset;
    int m_userData50;

    hkpExtendedMeshShapeTrianglesSubpartD4AB& UpdateState_00d4abf0(
        const hkpExtendedMeshShapeTrianglesSubpartD4AB& kOther) throw();
};

// Copies all triangle subpart fields from kOther into this, after delegating to the base class assignment operator.
// @fnv 0x00d4abf0
// src: GUESS 0x00d4abf0 (confidence: low)
hkpExtendedMeshShapeTrianglesSubpartD4AB& hkpExtendedMeshShapeTrianglesSubpartD4AB::UpdateState_00d4abf0(
    const hkpExtendedMeshShapeTrianglesSubpartD4AB& kOther) throw()
{
    hkpExtendedMeshShapeSubpartD4AB::operator=(kOther);
    m_iVertexStride = kOther.m_iVertexStride;
    m_pMaterialIndexBase = kOther.m_pMaterialIndexBase;
    m_iStridedVertexCount = kOther.m_iStridedVertexCount;
    m_pMaterialDataBase = kOther.m_pMaterialDataBase;
    m_kVertexTransform = kOther.m_kVertexTransform;
    m_iTriangleIndexStride = kOther.m_iTriangleIndexStride;
    m_iMaterialStriding = kOther.m_iMaterialStriding;
    m_ucIndexStridingType = kOther.m_ucIndexStridingType;
    m_bFlipAlternateTriangles = kOther.m_bFlipAlternateTriangles;
    m_iTriangleOffset = kOther.m_iTriangleOffset;
    m_userData50 = kOther.m_userData50;
    return *this;
}

namespace fnv_00d4ad60 {
inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

template <class T> class hkRefPtrD4AD
{
  public:
    T* m_pRetainedObject;

    hkRefPtrD4AD(const hkRefPtrD4AD& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->addReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrD4AD()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
    void operator=(const hkRefPtrD4AD& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->addReference();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
};

struct hkpExtendedMeshShapeSubpartD4AD
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    hkUlong m_ulUserData;
};

struct hkpExtendedMeshShapeShapesSubpartD4AD : public hkpExtendedMeshShapeSubpartD4AD
{
    hkArray<hkRefPtrD4AD<hkpConvexShape> > m_kChildShapes;
    hkQuaternion m_rotation;
    hkVector4q m_vTranslation;

    hkpExtendedMeshShapeShapesSubpartD4AD& CopySubpartFields(const hkpExtendedMeshShapeShapesSubpartD4AD& kOther) throw();
};

// Copies the base subpart fields, child shapes array, rotation, and translation from kOther into this subpart, then returns a reference to this.
// @fnv 0x00d4ad60
// src: GUESS 0x00d4ad60 (confidence: medium)
hkpExtendedMeshShapeShapesSubpartD4AD& hkpExtendedMeshShapeShapesSubpartD4AD::CopySubpartFields(
    const hkpExtendedMeshShapeShapesSubpartD4AD& kOther) throw()
{
    hkpExtendedMeshShapeSubpartD4AD::operator=(kOther);
    m_kChildShapes = kOther.m_kChildShapes;
    m_rotation = kOther.m_rotation;
    m_vTranslation = kOther.m_vTranslation;
    return *this;
}
}  // namespace fnv_00d4ad60

#include <string.h>
extern "C" void _ReadWriteBarrier();

template <class T> __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
        memcpy(p + i, &t, sizeof(T));
}

// hkArray bodies used by FUN_00d49dc0 (heap = the memory router's stream allocator).
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}
template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int capacity = getCapacity();
    if (capacity < n)
    {
        if (sizeof(T) == 12)
        {
            int doubled = capacity * 2;
            int count;
            if (n < doubled)
                count = doubled;
            else
                count = n;
            hkArrayUtil::_reserve(alloc, this, count, sizeof(T));
        }
        else
        {
            int cap2 = 2 * capacity;
            int newSize;
            if (sizeof(T) == 4)
                newSize = (n < cap2) ? cap2 : n;
            else
            {
                newSize = n;
                if (newSize < cap2)
                    newSize = cap2;
            }
            hkArrayUtil::_reserve(alloc, this, newSize, sizeof(T));
        }
    }
}
template <typename T> __forceinline T* hkArrayBase<T>::_expandBy(hkMemoryAllocator& alloc, int n)
{
    int oldsize = m_iElementCount;
    GrowArrayCapacity(alloc, oldsize + n);
    hkArrayUtil::construct(m_data + m_iElementCount, n, hkTypeIsClass());
    m_iElementCount += n;
    return m_data + oldsize;
}
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
    {
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    }
    constructWithCopy(m_data + m_iElementCount, 1, t);
    if (sizeof(T) == 2)
        _ReadWriteBarrier();
    ++m_iElementCount;
}
// expandBy returning the first new index.
template <typename T> static __forceinline int expandByIndex(hkArray<T>& a, int n)
{
    hkMemoryAllocator& alloc = hkMemoryRouter::getInstance().heap();
    int first = a.m_iElementCount;
    a.GrowArrayCapacity(alloc, first + n);
    a.m_iElementCount += n;
    return first;
}

__forceinline hkInt16 halfBits(hkReal r)
{
    return hkInt16(*(int*)&r >> 16);
}
struct hkHalfT
{
    hkInt16 m_uiFilterValue;
    __forceinline void operator=(const hkReal& r)
    {
        m_uiFilterValue = halfBits(r);
    }
};

__forceinline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(
        hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
    return b;
}

class hkClass;
extern const hkClass g_kHkpMeshMaterialClass;

struct StorageMaterial : hkpMeshMaterial
{
    hkHalfT m_fElasticity;
    hkHalfT m_fSlipAngle;
    hkUlong m_ulUserData;
};

struct MeshSubpartStorage : hkReferencedObject
{
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<StorageMaterial> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;
    __forceinline MeshSubpartStorage()
    {}
    virtual ~MeshSubpartStorage();
};

enum MaterialIndexStridingType
{
    MATERIAL_INDICES_INVALID,
    MATERIAL_INDICES_INT8,
    MATERIAL_INDICES_INT16,
};

struct TrianglesSubpart
{
    char m_type;
    char m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const hkpMeshMaterial* m_pIndexBase;
    const hkClass* m_pMaterialBase;
    hkUlong m_ulUserData;
    int m_iVertexStride;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    void CopySubpartFields(const TrianglesSubpart& other);
};

// Copies partIn into a new TrianglesSubpart, copies its vertex and material index data into MeshSubpartStorage, and returns the new subpart index.
// @fnv 0x00d49dc0
// src: HAVOK_LIB 0x00d49dc0
int hkpStorageExtendedMeshShape::addShapesSubpart(const TrianglesSubpart& partIn)
{
    TrianglesSubpart& part = *AppendElement();
    reinterpret_cast<hkArray<::MeshSubpartStorage*>&>(m_kShapeSubparts).pushBack(new ::MeshSubpartStorage());
    ::MeshSubpartStorage* storage = reinterpret_cast<hkArray<::MeshSubpartStorage*>&>(m_kShapeSubparts).back();

    part.CopySubpartFields(partIn);

    part.m_iMaterialIndexType = partIn.m_iMaterialIndexType;
    if (partIn.m_pVertexBase)
    {
        if (partIn.m_iMaterialIndexType == MATERIAL_INDICES_INT8)
        {
            hkArray<hkUint8>& indices = storage->m_kMaterialIndices8;
            if (partIn.m_iVertexStriding == 0)
            {
                indices.pushBack(*(const hkUint8*)partIn.m_pVertexBase);
                part.m_pVertexBase = &indices.back();
            }
            else
            {
                int num = partIn.m_iVertexStride;
                hkUint8* dst = indices.expandBy(num);
                part.m_pVertexBase = dst;
                const hkUint8* src = (const hkUint8*)partIn.m_pVertexBase;
                for (int i = 0; i < num; i++)
                {
                    dst[i] = *src;
                    src += partIn.m_iVertexStriding;
                }
            }
        }
        else
        {
            hkArray<hkUint16>& indices = storage->m_kMaterialIndices16;
            if (partIn.m_iVertexStriding == 0)
            {
                indices.pushBack(*(const hkUint16*)partIn.m_pVertexBase);
                _ReadWriteBarrier();
                part.m_pVertexBase = &indices.back();
            }
            else
            {
                int num = partIn.m_iVertexStride;
                hkUint16* dst = indices.expandBy(num);
                part.m_pVertexBase = dst;
                const hkUint8* src = (const hkUint8*)partIn.m_pVertexBase;
                for (int i = 0; i < num; i++)
                {
                    dst[i] = *(const hkUint16*)src;
                    src += partIn.m_iVertexStriding;
                }
            }
        }
        part.m_iVertexStriding = partIn.m_iVertexStriding;
        if (part.m_iVertexStriding)
        {
            switch (part.m_iMaterialIndexType)
            {
            case MATERIAL_INDICES_INT8:
                part.m_iVertexStriding = sizeof(hkUint8);
                break;
            case MATERIAL_INDICES_INT16:
                part.m_iVertexStriding = sizeof(hkUint16);
                break;
            }
        }
    }
    else
    {
        part.m_pVertexBase = 0;
        part.m_iVertexStriding = 0;
    }

    if (part.m_pVertexBase)
    {
        hkArray<StorageMaterial>& materials = storage->m_kMaterials;
        int first = expandByIndex(materials, partIn.m_iNumTriangles);
        const hkpMeshMaterial* src = partIn.m_pIndexBase;
        StorageMaterial* dst = materials.m_data + first;
        for (int i = 0; i < partIn.m_iNumTriangles; i++)
        {
            if (partIn.m_pMaterialBase == &g_kHkpMeshMaterialClass)
            {
                *dst = *static_cast<const StorageMaterial*>(src);
            }
            else
            {
                dst->m_uiFilterInfo = src->m_uiFilterInfo;
                dst->m_fSlipAngle = 1.0f;
                dst->m_fElasticity = 0.0f;
            }
            src = (const hkpMeshMaterial*)((const char*)src + partIn.m_iIndexStriding);
            dst++;
        }
        if (partIn.m_iIndexStriding)
        {
            part.m_iIndexStriding = sizeof(StorageMaterial);
            part.m_iNumTriangles = partIn.m_iNumTriangles;
        }
        else
        {
            part.m_iIndexStriding = 0;
            part.m_iNumTriangles = 1;
        }
        part.m_pIndexBase = materials.begin();
    }

    hkpExtendedMeshShape_recalcAabbExtents();
    m_iNumTriangles += hkpExtendedMeshShape__getNumChildShapesInShapesSubpart(part);
    return m_kShapesSubparts.m_iElementCount - 1;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void FUN_00d4ad50();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00d4ad50();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d4ad50
    virtual void FUN_00d4ad50();
};

Derived::Derived()
{}

#include <xmmintrin.h>
namespace fnv_00d56500 {
// Exe 0x00d56500 FUN_00d56500: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_and_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_cmple_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_set_ps1(float a);
    int _mm_movemask_ps(LocalM128 a);
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

typedef float hkReal;
typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;

extern const LocalM128 g_hkQuadIdentityQuat;
extern const LocalM128 g_hkQuadZero;
extern const LocalM128 g_hkQuadAbsMask;
extern const float g_hkEqualsEps;

template <class T> struct hkRefPtrS
{
    T* m_pRetainedObject;

    __forceinline hkRefPtrS() : m_pRetainedObject(0)
    {}
    __forceinline void operator=(T* e)
    {
        if (e)
        {
            e->addReference();
        }
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = e;
    }
};

struct ShapesSubpartS
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    unsigned int m_ulUserData;
    hkArray<hkRefPtrS<hkpConvexShape> > m_kChildShapes;
    hkVector4q m_rotation;
    hkVector4 m_vTranslation;

    __forceinline void initSubpart(hkInt8 type)
    {
        m_type = type;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_pIndexBase = 0;
        m_pVertexBase = 0;
        m_ulUserData = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
    }
    ShapesSubpartS* InitializeConvexSubpartTranslation(hkpConvexShape* const* childShapes, int numChildShapes, const hkVector4& offset);
};

static __forceinline bool equals3(const hkVector4& a, const LocalM128& b, hkReal epsilon)
{
    const LocalM128 diff = _mm_and_ps(_mm_sub_ps(*(const LocalM128*)&a, b), g_hkQuadAbsMask);
    const LocalM128 eps = _mm_set_ps1(epsilon);
    return (_mm_movemask_ps(_mm_cmple_ps(diff, eps)) & 7) == 7;
}

// Initializes a convex subpart with child shapes, translation offset, and identity rotation, encoding a non-zero flag in the translation w component.
// @fnv 0x00d56500
// src: GUESS 0x00d56500 (confidence: medium)
ShapesSubpartS* ShapesSubpartS::InitializeConvexSubpartTranslation(hkpConvexShape* const* childShapes, int numChildShapes,
                                             const hkVector4& offset)
{
    initSubpart(1);
    m_kChildShapes.setOwnedData(0, 0, 0x80000000);
    m_vTranslation = offset;

    hkRefPtrS<hkpConvexShape>* dst = m_kChildShapes.expandBy(numChildShapes);
    for (int i = 0; i < numChildShapes; i++)
    {
        dst[i] = childShapes[i];
    }

    m_rotation.m_vComponents = *reinterpret_cast<const ::__m128*>(&g_hkQuadIdentityQuat);
    const int bOffsetNonZero = !equals3(offset, g_hkQuadZero, g_hkEqualsEps);
    *(int*)&m_vTranslation.w = bOffsetNonZero | 0x3f000000;
    return this;
}
}  // namespace fnv_00d56500
