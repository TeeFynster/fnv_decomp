
// src/havok/physics/collide/shape/deprecated/mesh/hkpmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/mesh/hkpmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original compiler intrinsic representation; the CRT union changes alias analysis.
#define _INCLUDED_MM2
// Exe 0x00dccd50 ExpandAabbWithVertex: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_set_ps1(float);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);

#include "../../../../../../../include/hkpMeshShape.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpTriangleShape.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkAabb.h"

__forceinline void hkVector4::set(float a, float b, float c, float d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum() {}
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum(ENUM value) : m_kStorage(value) {}
inline hkpShape::hkpShape(hkpShapeType type)
{
    m_ulUserData = 0;
    reinterpret_cast<hkUint32&>(m_type) = type;
}
inline hkpConvexShape::hkpConvexShape(hkpShapeType type, hkReal radius) : hkpShape(type)
{
    m_fSphereRadius = radius;
}
inline hkpTriangleShape::hkpTriangleShape(float radius, unsigned short weldingInfo, int weldingType) throw()
    : hkpConvexShape(HK_SHAPE_TRIANGLE, radius)
{
    m_kWeldingInfo = weldingInfo;
    reinterpret_cast<hkUint8&>(m_eWeldingType) = static_cast<hkUint8>(weldingType);
    m_kVertexTransform.m_vComponents = _mm_setzero_ps();
    m_ucWeldingPadding = 0;
}

struct hkpMeshShapeSubpart
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    hkUint8 m_ucIndexStridingType;
    hkUint8 m_iMaterialIndexType;
    hkUint16 unk12;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iNumTriangles;
    int m_iIndexStriding;
    int m_iTriangleOffset;
};

struct __declspec(align(16)) hkpShapeBuffer
{
    hkVector4 m_kStorage[32];
};

extern float DAT_011b2e90;
extern "C" hkBool* __cdecl IsDegenerateTriangle(hkBool* result, const hkVector4* v0, const hkVector4* v1,
                                                const hkVector4* v2, float tolerance);
class MeshFirstTriangleCursor : public hkpShapeContainer
{
  public:
    int GetFirstTriangleKey();
};
// @fnv 0x00dccbc0
int MeshFirstTriangleCursor::GetFirstTriangleKey()
{
    const hkpMeshShape* mesh = reinterpret_cast<const hkpMeshShape*>(reinterpret_cast<const char*>(this) - 0x10);
    if (mesh->m_kSubparts.m_iElementCount == 0)
        return -1;
    hkpShapeBuffer buffer;
    const hkpTriangleShape* triangle = reinterpret_cast<const hkpTriangleShape*>(GetShapeForKey(0, buffer));
    hkBool result;
    if (!*IsDegenerateTriangle(&result, &triangle->m_kVertexA, &triangle->m_kVertexB, &triangle->m_kVertexC, DAT_011b2e90))
        return 0;
    return GetNextShapeKey(0);
}

hkBool __cdecl IsDegenerateTriangle(const hkVector4& kA, const hkVector4& kB, const hkVector4& kC,
                                 float fTolerance) throw();

// Secondary mesh-container view: original 0x00dccc30 reads key bits at this+0x20 (mesh+0x30).
class MeshTriangleKeyCursor : public hkpShapeContainer
{
  public:
    char meshStorage[0x1c];
    int m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpart> m_kSubparts;

    hkUint32 GetNextNonDegenerateTriangleKey(hkUint32 oldKey) const throw();
};

// @fnv 0x00dccc30
hkUint32 MeshTriangleKeyCursor::GetNextNonDegenerateTriangleKey(hkUint32 auiKey) const throw()
{
    hkpShapeBuffer buffer;

    hkUint32 subPart = auiKey >> (32 - m_iNumBitsForSubpartIndex);
    int triIndex = auiKey & (0xffffffff >> m_iNumBitsForSubpartIndex);

    while (true)
    {
        const hkpMeshShapeSubpart& kPart = m_kSubparts.m_data[subPart];
        if (++triIndex >= kPart.m_iTriangleCount)
        {
            if (++subPart >= static_cast<hkUint32>(m_kSubparts.m_iElementCount))
                return 0xffffffff;
            triIndex = 0;
        }
        hkUint32 key = (subPart << (32 - m_iNumBitsForSubpartIndex)) | triIndex;
        const hkpTriangleShape* pkTri = reinterpret_cast<const hkpTriangleShape*>(GetShapeForKey(key, buffer));
        if (!IsDegenerateTriangle(pkTri->m_kVertexA, pkTri->m_kVertexB, pkTri->m_kVertexC, 1e-7f))
            return key;
    }
}

extern const hkClass DAT_01269198;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

template <class T> __forceinline void addArray(hkStatisticsCollector* collector, const char* name, const hkArray<T>& array)
{
    if ((array.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations)
    {
        const T* data = array.m_data;
        int allocated = hkStatisticsCollector_getAllocatedSize(data, array.getCapacity() * sizeof(T));
        collector->AddMemoryChunk(3, name, array.m_data, array.GetLogicalSize() * sizeof(T), allocated);
    }
}

// Shared hkpShapeCollection omits its statistics override (0x00d213e0).
class ShapeCollectionStatistics : public hkpShapeCollection
{
  public:
    void CollectBaseStatistics(hkStatisticsCollector* collector, const hkClass* cls) const throw();
};
class MeshShapeStatistics : public hkpMeshShape
{
  public:
    void CollectSubPartsStats(hkStatisticsCollector* collector, const hkClass* cls) const throw();
};

// Adds the SubParts array to the statistics collector, then forwards to the base shape's statistics collection with DAT_01269198.
// @fnv 0x00dcd140
void MeshShapeStatistics::CollectSubPartsStats(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw()
{
    addArray(pkCollector, "SubParts", m_kSubparts);
    reinterpret_cast<const ShapeCollectionStatistics*>(this)->CollectBaseStatistics(pkCollector, &DAT_01269198);
}

class MeshMaterialIndex : public hkpMeshShape
{
  public:
    int GetElement(unsigned int key);
};
class MeshMaterialLookup : public hkpShapeContainer
{
  public:
    void* FindValue(unsigned int key);
};

// Gets an index for uiKey from GetElement on the owner; if found, returns the pointer stored in that page's value array, otherwise null.
// @fnv 0x00dccd00
void* MeshMaterialLookup::FindValue(unsigned int uiKey)
{
    MeshMaterialIndex* pkOwner = (MeshMaterialIndex*)((char*)this - 0x10);
    int iIndex = pkOwner->GetElement(uiKey);
    if (iIndex != -1)
    {
        hkpMeshShapeSubpart* pkPage = &pkOwner->m_kSubparts.m_data[uiKey >> (32 - pkOwner->m_iNumBitsForSubpartIndex)];
        void** ppValue = (void**)((char*)pkPage->m_pIndexBase + pkPage->m_iNumTriangles * iIndex);
        if (ppValue)
            return *ppValue;
    }
    return 0;
}

// Secondary container storage: scaling at +0x10 and key bits at +0x20 are mesh offsets +0x20/+0x30.
class MeshTriangleStorageView
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkVector4 m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpart> m_kSubparts;
    hkArray<hkUint16> m_kWeldingInfo;
    hkUint8 m_eWeldingType;
    char m_pad3d;
    char m_pad3e;
    char m_pad3f;
    hkReal m_fSphereRadius;

    const void* CreateTriangle(unsigned int key, void* buffer) const;
};

// Extracts a triangle's vertex data from subpart index arrays, scales it, and constructs a hkpTriangleShape in the provided buffer.
// @fnv 0x00dccf60
const void* MeshTriangleStorageView::CreateTriangle(unsigned int key, void* buffer) const
{
    unsigned int triangleIndex = key & (~0U >> m_iNumBitsForSubpartIndex);
    const hkpMeshShapeSubpart& subpart = m_kSubparts.m_data[key >> (32 - m_iNumBitsForSubpartIndex)];

    int flip = subpart.m_bFlipAlternateTriangles & triangleIndex;
    const float *v0 = 0, *v1, *v2;
    if (subpart.m_ucIndexStridingType == 1)
    {
        const unsigned short* pIndices16 =
            (const unsigned short*)((const char*)subpart.m_pMaterialDataBase + subpart.m_iMaterialStriding * triangleIndex);
        v0 = (const float*)((const char*)subpart.m_pMaterialIndexBase + pIndices16[0] * subpart.m_iTriangleIndexStride);
        v1 = (const float*)((const char*)subpart.m_pMaterialIndexBase + pIndices16[1 + flip] * subpart.m_iTriangleIndexStride);
        v2 = (const float*)((const char*)subpart.m_pMaterialIndexBase + pIndices16[1 + (flip ^ 1)] * subpart.m_iTriangleIndexStride);
    }
    else
    {
        const unsigned int* pIndices32 =
            (const unsigned int*)((const char*)subpart.m_pMaterialDataBase + subpart.m_iMaterialStriding * triangleIndex);
        v0 = (const float*)((const char*)subpart.m_pMaterialIndexBase + pIndices32[0] * subpart.m_iTriangleIndexStride);
        v1 = (const float*)((const char*)subpart.m_pMaterialIndexBase + pIndices32[1 + flip] * subpart.m_iTriangleIndexStride);
        v2 = (const float*)((const char*)subpart.m_pMaterialIndexBase + pIndices32[1 + (flip ^ 1)] * subpart.m_iTriangleIndexStride);
    }

    hkVector4 vVertexA;
    vVertexA.set(v0[0] * m_kScaling.x, v0[1] * m_kScaling.y, v0[2] * m_kScaling.z);
    hkVector4 vVertexB;
    vVertexB.set(v1[0] * m_kScaling.x, v1[1] * m_kScaling.y, v1[2] * m_kScaling.z);
    hkVector4 vVertexC;
    vVertexC.set(v2[0] * m_kScaling.x, v2[1] * m_kScaling.y, v2[2] * m_kScaling.z);

    hkUint16 weldingInfo;
    if (m_kWeldingInfo.m_iElementCount == 0)
    {
        weldingInfo = 0;
    }
    else
    {
        weldingInfo = m_kWeldingInfo.m_data[subpart.m_iTriangleOffset + triangleIndex];
    }

    hkpTriangleShape* pTriangle = ::new (buffer) hkpTriangleShape(m_fSphereRadius, weldingInfo, m_eWeldingType);
    pTriangle->m_kVertexA.m_vComponents = vVertexA.m_vComponents;
    pTriangle->m_kVertexB.m_vComponents = vVertexB.m_vComponents;
    pTriangle->m_kVertexC.m_vComponents = vVertexC.m_vComponents;
    return pTriangle;
}

// Retained: the shared collection header does not declare its (type, collectionType) constructor.
class FUN_00d21410 : public hkpShape, public hkpShapeContainer
{
  public:
    FUN_00d21410(unsigned int uiType, unsigned char ucCollectionType) throw();
    virtual ~FUN_00d21410() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

// Retained: the shared mesh header does not declare its (radius, subpartBits) constructor.
class FUN_00dcd310 : public FUN_00d21410
{
  public:
    FUN_00dcd310(float fRadius, int iNumBitsForSubpartIndex) throw();
    virtual ~FUN_00dcd310() throw();

    unsigned int unk18, unk1C;
    hkVector4 m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpart> m_kSubparts;
    hkArray<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
    int m_auiShapeKeys[3];
};

// @fnv 0x00dcd310
FUN_00dcd310::FUN_00dcd310(float afSphereRadius, int iNumBitsForSubpartIndex) throw() : FUN_00d21410(0x17, 5)
{
    m_kScaling.m_vComponents = _mm_set_ps1(1.0f);
    m_iNumBitsForSubpartIndex = iNumBitsForSubpartIndex;
    m_fSphereRadius = afSphereRadius;
    m_eWeldingType = 6;
}

// Looks up the element at uiKey in the paged array, returning its byte or short value, or -1 if the page is not allocated.
// @fnv 0x00dcd410
int MeshMaterialIndex::GetElement(unsigned int uiKey)
{
    unsigned int uiPage = uiKey >> (32 - m_iNumBitsForSubpartIndex);
    hkpMeshShapeSubpart* pkPage = &m_kSubparts.m_data[uiPage];
    if (pkPage->m_pVertexBase)
    {
        const unsigned char* p = (const unsigned char*)pkPage->m_pVertexBase + (uiKey & (0xffffffff >> m_iNumBitsForSubpartIndex)) * pkPage->m_iVertexStriding;
        if (pkPage->m_iMaterialIndexType == 1)
            return *p;
        return *(const unsigned short*)p;
    }
    return -1;
}

// Scales a vertex, transforms it to world space, and expands the AABB's min and max corners to include it.
// @fnv 0x00dccd50
static __declspec(noinline) void ExpandAabbWithVertex(hkAabb& aabb, const hkTransform& localToWorld,
                                                      const float* vertex, const hkVector4& scaling)
{
    hkVector4 scaled;
    scaled.set(vertex[0] * scaling.x, vertex[1] * scaling.y, vertex[2] * scaling.z);
    hkVector4 v;
    v.setTransformedPos_00c7f640(localToWorld, scaled);
    aabb.m_kMinimumCorner.m_vComponents = _mm_min_ps(aabb.m_kMinimumCorner.m_vComponents, v.m_vComponents);
    aabb.m_kMaximumCorner.m_vComponents = _mm_max_ps(aabb.m_kMaximumCorner.m_vComponents, v.m_vComponents);
}

// Trivial loading argument used by this unit's placement-construction entry point.
struct MeshFinishFlag
{
    int m_bFinishing;
};

// Retained: adapting the finish-loaded shape constructor to FinishingFlag changes bytes in 0x00dcd380.
class S00dcd380_Shape
{
  public:
    __forceinline S00dcd380_Shape(MeshFinishFlag flag)
    {
        if (flag.m_bFinishing)
            m_type = 0;
    }
    virtual ~S00dcd380_Shape();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};

// Retained: the shared collection header does not declare its finish-loaded constructor.
class S00dcd380_Collection : public S00dcd380_Shape, public hkpShapeContainer
{
  public:
    __forceinline S00dcd380_Collection(MeshFinishFlag flag) : S00dcd380_Shape(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = 7;
            m_eCollectionType = 3;
        }
    }
    virtual ~S00dcd380_Collection();
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
};

// Retained: the shared mesh header does not declare its finish-loaded constructor.
class S00dcd380_Mesh : public S00dcd380_Collection
{
  public:
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;

    __forceinline S00dcd380_Mesh(MeshFinishFlag flag) : S00dcd380_Collection(flag)
    {
        if (flag.m_bFinishing)
        {
            for (int i = 0; i < m_iElementCount; i++)
            {
                unsigned char& type = m_data[i].m_iMaterialIndexType;
                if (type == 0)
                    type = 1;
            }
            m_type = 0x17;
            m_eCollectionType = 5;
        }
    }
    virtual ~S00dcd380_Mesh();
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    hkpMeshShapeSubpart* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// Placement-construction entry point; this adapter has no mesh storage of its own.
class MeshFinishLoader
{
  public:
    S00dcd380_Mesh* FinishLoadMesh(int finishing);
};

// Placement-constructs an S00dcd380_Mesh into this host object, passing a flag that carries the finishing state.
// @fnv 0x00dcd380
S00dcd380_Mesh* MeshFinishLoader::FinishLoadMesh(int finishing)
{
    MeshFinishFlag flag;
    flag.m_bFinishing = finishing;
    __assume(this != 0);
    return ::new (this) S00dcd380_Mesh(flag);
}

__forceinline void setSplat(hkVector4& v, float f)
{
    v.m_vComponents = _mm_set_ps1(f);
}
__forceinline void subtract(hkVector4& a, const hkVector4& b)
{
    a.m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void add(const hkVector4& b, hkVector4& a)
{
    a.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
class MeshShapeHelper : public hkpMeshShape
{
  public:
    void hkpMeshShape_getAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const;
};
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* p, long n)
{
    return (const T*)((const char*)p + n);
}
// Computes the world-space AABB of all subpart triangles, then expands it by margin plus m_fSphereRadius.
// @fnv 0x00dccdd0
// src: XBOX_PDB 0x00dccdd0
void MeshShapeHelper::hkpMeshShape_getAabb(const hkTransform& placement, hkReal margin, hkAabb& bounds) const
{
    bounds.m_kMinimumCorner.set(3.402820018375656e+38f, 3.402820018375656e+38f, 3.402820018375656e+38f);
    bounds.m_kMaximumCorner.set(-3.402820018375656e+38f, -3.402820018375656e+38f, -3.402820018375656e+38f);
    for (int partIndex = 0; partIndex < m_kSubparts.m_iElementCount; ++partIndex)
    {
        const hkpMeshShapeSubpart& part = m_kSubparts.m_data[partIndex];
        for (int face = 0; face < part.m_iTriangleCount; ++face)
        {
            const float *a, *b, *c;
            if (part.m_ucIndexStridingType == INDICES_INT16)
            {
                const hkUint16* indices =
                    hkAddByteOffsetConst((const hkUint16*)part.m_pMaterialDataBase, part.m_iMaterialStriding * face);
                a = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[0] * part.m_iTriangleIndexStride);
                b = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[1] * part.m_iTriangleIndexStride);
                c = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[2] * part.m_iTriangleIndexStride);
            }
            else
            {
                const hkUint32* indices =
                    hkAddByteOffsetConst((const hkUint32*)part.m_pMaterialDataBase, part.m_iMaterialStriding * face);
                a = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[0] * part.m_iTriangleIndexStride);
                b = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[1] * part.m_iTriangleIndexStride);
                c = hkAddByteOffsetConst(part.m_pMaterialIndexBase, indices[2] * part.m_iTriangleIndexStride);
            }
            ExpandAabbWithVertex(bounds, placement, a, m_kScaling);
            ExpandAabbWithVertex(bounds, placement, b, m_kScaling);
            ExpandAabbWithVertex(bounds, placement, c, m_kScaling);
        }
    }
    hkVector4 expansion;
    setSplat(expansion, margin + m_fSphereRadius);
    subtract(bounds.m_kMinimumCorner, expansion);
    add(expansion, bounds.m_kMaximumCorner);
}

class MeshScalingSetter : public hkpMeshShape
{
  public:
    void UpdateFields_00dccf40(const hkVector4& value);
};

// @fnv 0x00dccf40
// src: GUESS 0x00dccf40 (confidence: low)
void MeshScalingSetter::UpdateFields_00dccf40(const hkVector4& value)
{
    LocalM128 data = _mm_load_ps(&value.x);
    _mm_store_ps(&m_kScaling.x, data);
}
