typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/compressedmesh/hkpcompressedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Retain the unit's SIMD storage type and intrinsic declarations: the legacy
// compiler's alias analysis changes when __m128 also has byte-array members.
// Exe 0x00e3c270 FUN_00e3c270: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

#define _INCLUDED_MM2
extern "C"
{
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_setzero_ps();
    void _mm_store_ps(float*, LocalM128);
}

#define FNV_VECTOR_USE_LOCAL_SSE
// Preserve the scalar copy form of the former reflection-only POD view.
__forceinline void CopyReflectionQuad(void* destination, const void* source)
{
    unsigned int* out = static_cast<unsigned int*>(destination);
    const unsigned int* in = static_cast<const unsigned int*>(source);
    out[0] = in[0]; out[1] = in[1]; out[2] = in[2]; out[3] = in[3];
}

#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/Transform.h"
#include "../../../../../../../../include/hkAabb.h"
#include "../../../../../../../../include/hkVector4.h"

// Preserve the original empty default construction before compiling hkVector4q.
__forceinline hkAabb::hkAabb() {}

#include "../../../../../../../../include/hkVector4q.h"
#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkStringPtr.h"
#include "../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../../include/hkpCompressedMeshShape.h"

// Value-only reflection types preserve the existing helper signatures.
#include "../../../../../../../../include/hkAabb.h"
#include "havok/hkBase.h"

namespace reflected_havok
{
#include "havok/hkBase.h"
#include "havok/hkAabb.h"
}
using ::hkUint8;
using ::hkUint16;
using ::hkUint32;
using ::hkInt32;
using ::hkReal;

// @fnv 0x00e3cad0
unsigned int hkpCompressedMeshShape::GetShapeIndexMask()
{
    // The game's entry receives the mesh's secondary hkpShapeContainer address.
    const hkpCompressedMeshShape& mesh = *reinterpret_cast<const hkpCompressedMeshShape*>(
        reinterpret_cast<const char*>(this) - sizeof(hkpShape));
    if (mesh.m_kBigTriangles.m_iElementCount)
        return 0;
    if (mesh.m_kChunks.m_iElementCount)
        return 1 << mesh.m_iBitsPerWIndex;
    if (mesh.m_kConvexPieces.m_iElementCount)
        return ((1 << (32 - mesh.m_iBitsPerWIndex)) - 1) << mesh.m_iBitsPerWIndex;
    return -1;
}

// Layout-free helpers retain methods absent from the shared mesh declaration.
struct CompressedMeshDeleteCall : ::hkpCompressedMeshShape
{
    void* __thiscall FUN_00e3deb0(unsigned int uiFlags);
};

hkMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

// @fnv 0x00e3deb0
void* __thiscall CompressedMeshDeleteCall::FUN_00e3deb0(unsigned int uiFlags)
{
    CompressedMeshDeleteCall* pShape = this;

    pShape->hkpCompressedMeshShape::~hkpCompressedMeshShape();

    if (uiFlags & 1)
    {
        hkMemoryRouter* pRouter = _D1A0E0GetMemoryRouter();
        pRouter->m_heap->blockFree(pShape, pShape->m_usMemSizeAndFlags);
    }

    return pShape;
}

// @fnv 0x00e3c9d0
// src: GUESS 0x00e3c9d0 (confidence: high)
__declspec(noinline) unsigned int __stdcall hkpCompressedMeshShape_ReturnConstant_0xF0(unsigned int a1, unsigned int a2)
{
    return 0xF0;
}

// Stores the given welding type byte at offset 0x2c of this object.
// @fnv 0x00e3d0d0
void hkpCompressedMeshShape::SetWeldingType(unsigned char weldingType)
{
    m_eWeldingType = weldingType;
}

extern int DAT_01269198;
int __cdecl hkpShapeCollection_calcContentStatistics(int first, int* second);

// @fnv 0x00e3c9c0
// src: XBOX_PDB 0x00e3c9c0
int __cdecl hkpCompressedMeshShape_calcContentStatistics(int first, int unusedSecond)
{
    return hkpShapeCollection_calcContentStatistics(first, &DAT_01269198);
}

// @fnv 0x00e3ca00
// src: GUESS 0x00e3ca00 (confidence: high)
int __stdcall Object_ReturnZero_00e3ca00(int arg0)
{
    return 0;
}

void __cdecl hkArray_ComputeScaledVertexBounds(void* pIndices, const ::hkVector4* pSrcVec, float fScale, ::hkVector4* pDstVec,
                          const ::hkVector4* pOtherVec);

struct FUN_00e3cd20_Class : ::hkVector4
{
    void* unk10;
    unsigned int unk14;

    void ForwardCall_00e3cd20(float a1, ::hkVector4* a2, ::hkVector4* a3);
};

// Calls FUN_00e3cc20 with the object's unk10, this vector, a1, a2 and a3.
// @fnv 0x00e3cd20
// src: GUESS 0x00e3cd20 (confidence: low)
void FUN_00e3cd20_Class::ForwardCall_00e3cd20(float afScale, ::hkVector4* a2, ::hkVector4* a3)
{
    hkArray_ComputeScaledVertexBounds(&unk10, this, afScale, a2, a3);
}

extern "C" void _ReadWriteBarrier(void);

const void* DAT_010d0fc4[];

struct FUN_00d59710
{
    const void** m_vtbl;
    unsigned short unk04;
    unsigned short m_uiType;
    unsigned int m_uiPad;
    unsigned int m_uiNumShapes;
    float m_fScale;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int m_uiF40;
    unsigned int m_uiF44;
    unsigned int m_uiF48;
    unsigned int unk4c;
    unsigned int m_uiF50;
    unsigned int m_uiF54;
    unsigned int m_uiF58;
    unsigned int m_uiF5c;
    unsigned int m_uiF60;
    FUN_00d59710(float fScale);
};

// @fnv 0x00d59710
FUN_00d59710::FUN_00d59710(float fScale)
{
    unsigned short us = 1;
    unsigned int uiZero = 0;
    m_fScale = fScale;
    m_uiType = us;
    m_uiPad = uiZero;
    m_uiNumShapes = 6;
    m_vtbl = DAT_010d0fc4;
    m_uiF40 = uiZero;
    m_uiF44 = uiZero;
    _ReadWriteBarrier();
    unsigned int uiHi = 0x80000000;
    m_uiF48 = uiHi;
    m_uiF50 = uiZero;
    m_uiF54 = uiZero;
    m_uiF58 = uiZero;
    m_uiF5c = uiHi;
    m_uiF60 = uiZero;
}

struct FUN_00e3ca10_Class
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
    unsigned short* unk28;
    int unk2c;

    int hkpCompressedMeshShape_Chunk_getNextIndex(int aiIndex, int* apOut);
};

// Locates aiIndex+1 among cumulative section sizes in unk28, adjusts it, sets *apOut to a parity bit in the strip part, and returns -1 once past unk20.
// @fnv 0x00e3ca10
// src: HAVOK_LIB 0x00e3ca10
int FUN_00e3ca10_Class::hkpCompressedMeshShape_Chunk_getNextIndex(int aiIndex, int* apOut)
{
    *apOut = 0;
    if (aiIndex < 0)
    {
        return unk20 ? 0 : -1;
    }

    int iCount = unk2c;
    ++aiIndex;
    int i = 0;
    int iAccumulated = 0;
    int iPrevious = 0;
    if (iCount != 0)
    {
        iAccumulated = unk28[0];
        if (aiIndex >= iAccumulated)
        {
            do
            {
                ++i;
                if (i >= iCount)
                {
                    break;
                }
                iPrevious = iAccumulated;
                iAccumulated += unk28[i];
            } while (aiIndex >= iAccumulated);
        }
    }

    if (i >= iCount)
    {
        int iDelta = aiIndex - iAccumulated;
        int iStride = 3;
        while (iDelta % iStride != 0)
        {
            ++iDelta;
            ++aiIndex;
        }
    }
    else if (aiIndex >= iAccumulated - 2)
    {
        aiIndex = iAccumulated;
    }
    else
    {
        *apOut = (aiIndex - iPrevious) & 1;
    }

    if (aiIndex >= unk20)
    {
        return -1;
    }

    return aiIndex;
}

struct StripsShapeE3CEB0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_iNumIndices;
    int unk24;
    unsigned short* m_pusStripLengths;
    int m_iNumStrips;
    int GetNumTriangles();
};

// Sums strip lengths to get total strip indices, computes triangles per strip, and adds remaining indices divided by three to return total triangle count.
// @fnv 0x00e3ceb0
int StripsShapeE3CEB0::GetNumTriangles()
{
    int iTotalStripIndices = 0;
    int iStripTriangles = 0;
    for (int i = 0; i < m_iNumStrips; i++)
    {
        iTotalStripIndices += m_pusStripLengths[i];
        iStripTriangles += m_pusStripLengths[i] - 2;
    }
    int iRemainingIndices = m_iNumIndices - iTotalStripIndices;
    return iRemainingIndices / 3 + iStripTriangles;
}

// Writes attributeValue to the attribute table or sub-attribute data based on instanceMask and m_iBitsPerWIndex.
// @fnv 0x00e3d060
void __thiscall hkpCompressedMeshShape::SetAttribute(unsigned long instanceMask, unsigned short attributeValue)
{
    unsigned int shiftResult = instanceMask >> m_iBitsPerWIndex;

    if (!shiftResult)
    {
        unsigned int shapeOffset = m_iNumBitsForIndex & instanceMask;
        *(unsigned short*)((char*)m_kBigTriangles.m_data + shapeOffset * 16 + 12) = attributeValue;
    }
    else
    {
        unsigned int indexOffset = m_iNumBitsForWIndex & instanceMask;
        unsigned int index = shiftResult - 1;
        unsigned short entry = *(unsigned short*)((char*)m_kChunks.m_data + index * 80 + 0x44);
        if (entry != 0xFFFF)
            index = entry;
        unsigned int attributeEntryOffset = *(unsigned int*)((char*)m_kChunks.m_data + index * 80 + 0x34);
        *(unsigned short*)((char*)attributeEntryOffset + indexOffset * 2) = attributeValue;
    }
}

template <typename ENUM, typename STORAGE> __forceinline hkEnum<ENUM, STORAGE>::hkEnum() {}
__forceinline hkpShape::hkpShape(FinishingFlag flag) : hkReferencedObject(flag)
{
    if (flag.m_bFinishing)
        *reinterpret_cast<int*>(&m_type) = 0;
}

__forceinline hkpShapeCollection::hkpShapeCollection(FinishingFlag flag) : ::hkpShape(flag)
{
    if (flag.m_bFinishing)
    {
        *reinterpret_cast<int*>(&m_type) = 7;
        m_eCollectionType = 3;
    }
}


extern int DAT_010eba5c;
extern int DAT_010eba3c;

// @fnv 0x00e3dbd0
hkpCompressedMeshShape::hkpCompressedMeshShape(FinishingFlag flag) throw()
    : hkpShapeCollection(flag), m_kMaterials(flag), m_kMaterialIndices16(flag),
      m_kMaterialIndices8(flag), m_kTransforms(flag), m_kBigVertices(flag),
      m_kBigTriangles(flag), m_kChunks(flag), m_kConvexPieces(flag), m_kNamedMaterials(flag)
{
    *reinterpret_cast<void**>(this) = &DAT_010eba5c;
    *reinterpret_cast<void**>(static_cast<hkpShapeContainer*>(this)) = &DAT_010eba3c;
    if (flag.m_bFinishing)
    {
        *reinterpret_cast<int*>(&m_type) = 0x10;
        m_eCollectionType = 6;
        if (m_kNamedMaterials.m_iElementCount)
            m_pUserData = m_kNamedMaterials.m_data;
    }
}

::hkMemoryRouter& __cdecl GetMemoryRouterE3D() throw();
template <typename T> __forceinline void DestructE3D(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}

template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& kAlloc = GetMemoryRouterE3D().heap();
    DestructE3D(this->m_data, this->m_iElementCount);
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

struct hkpCompressedMeshShapeBigTriangle
{
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    unsigned short m_iThirdValue;
    unsigned short m_iMaterialIndex;
    unsigned short m_kWeldingInfo;
    unsigned short m_iSectionVertexCount;
    int unk0C;
};
struct hkpCompressedMeshShapeChunk
{
    ~hkpCompressedMeshShapeChunk() throw();
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
};
struct hkpCompressedMeshShapeConvexPiece
{
    ~hkpCompressedMeshShapeConvexPiece() throw();
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
};
struct hkpNamedMeshMaterial
{
    unsigned int m_uiFilterInfo;
    ::hkStringPtr m_name;
};

__forceinline hkpShapeContainer::~hkpShapeContainer() {}

// @fnv 0x00e3dc50
hkpCompressedMeshShape::~hkpCompressedMeshShape() throw()
{}

__forceinline void hkVector4q::setMin4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4q::setMax4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4q::add4(const hkVector4q& a)
{
    m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
}

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

class hkpConvexVerticesShapeq
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_usMemSizeAndFlags;
    unsigned int m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    unsigned int unk14;
    hkVector4q* m_kVertices;
    int m_iStridedVertexCount;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    float m_fSphereRadius;

    void hkpSimpleMeshShape_getAabb(const ::hkTransform& localToWorld, float tolerance, hkAabbq& out) const;
};

// Transforms each vertex of the convex shape by localToWorld, accumulates the min/max corners into out, then expands the AABB by m_fSphereRadius plus tolerance.
// @fnv 0x00e3c270
// src: XBOX_PDB 0x00e3c270
void hkpConvexVerticesShapeq::hkpSimpleMeshShape_getAabb(const ::hkTransform& localToWorld, float tolerance, hkAabbq& out) const
{
    out.m_kMinimumCorner.set(3.40282e+38f, 3.40282e+38f, 3.40282e+38f, 0.0f);
    out.m_kMaximumCorner.set(-3.40282e+38f, -3.40282e+38f, -3.40282e+38f, 0.0f);
    for (int i = 0; i < m_iStridedVertexCount; i++)
    {
        hkVector4q v;
        v.setTransformedPos_00c7f640(reinterpret_cast<const ::hkTransform&>(localToWorld), m_kVertices[i]);
        out.m_kMinimumCorner.setMin4(out.m_kMinimumCorner, v);
        out.m_kMaximumCorner.setMax4(out.m_kMaximumCorner, v);
    }
    hkVector4q vTolerance;
    (vTolerance.*static_cast<void (hkVector4q::*)(float)>(&hkVector4q::SetAllComponents))(m_fSphereRadius + tolerance);
    out.m_kMinimumCorner.sub4(vTolerance);
    out.m_kMaximumCorner.add4(vTolerance);
}

struct CompressedMeshScaleCopy : hkpCompressedMeshShape
{
    void CopyFrom(LocalM128* src);
};

// @fnv 0x00e3c9e0
void CompressedMeshScaleCopy::CopyFrom(LocalM128* src)
{
    *reinterpret_cast<LocalM128*>(&padD4[0xC]) = *src;
}

namespace fnv_00e3cc20 {
struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

// Finds the max x, y, z of the uint16 vertex triples, sets the max corner to max * scale + offset and min corner to offset, then multiplies both by scale4.
// @fnv 0x00e3cc20
// src: GUESS 0x00e3cc20 (confidence: medium)
void __cdecl hkArray_ComputeScaledVertexBounds(const ::hkArray<hkUint16>& vertices, const hkVector4q& offset, float scale, hkAabbq& aabbOut,
                          const hkVector4q& scale4)
{
    hkUint16 maxX = 0;
    hkUint16 maxY = 0;
    hkUint16 maxZ = 0;
    int numVertices = vertices.m_iElementCount / 3;
    for (int i = 0; i < numVertices; i++)
    {
        const hkUint16* v = &vertices.m_data[i * 3];
        if (v[0] > maxX)
            maxX = v[0];
        if (v[1] > maxY)
            maxY = v[1];
        if (v[2] > maxZ)
            maxZ = v[2];
    }
    hkVector4q scaleV;
    scaleV.m_vComponents = _mm_load_ss(&scale);
    scaleV.m_vComponents = _mm_shuffle_ps(scaleV.m_vComponents, scaleV.m_vComponents, 0);
    hkVector4q extent;
    extent.set(hkReal(maxX), hkReal(maxY), hkReal(maxZ), 0.0f);
    aabbOut.m_kMaximumCorner.m_vComponents =
        _mm_add_ps(_mm_mul_ps(extent.m_vComponents, scaleV.m_vComponents), offset.m_vComponents);
    aabbOut.m_kMinimumCorner = offset;
    aabbOut.m_kMaximumCorner.mul4(scale4);
    aabbOut.m_kMinimumCorner.mul4(scale4);
}
}  // namespace fnv_00e3cc20

namespace reflected_havok
{
class hkpCompressedMeshShapeChunk
{
  public:
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned materialInfo;
    unsigned short reference, unk46;
    unsigned unk48, unk4c;
    unsigned hkpCompressedMeshShape_Chunk_getNextIndex(unsigned triangle, unsigned* welding);
};
}
struct CompressedMeshKeyValidation : ::hkpCompressedMeshShape
{
    unsigned hkpCompressedMeshShape_isValidShapeKey(unsigned key);
};
// Validates a packed triangle key against the compressed mesh chunks, returning 0 on success or an error code 1-4 on mismatch.
// @fnv 0x00e3cfe0
// src: HAVOK_LIB 0x00e3cfe0
unsigned CompressedMeshKeyValidation::hkpCompressedMeshShape_isValidShapeKey(unsigned key)
{
    int index = (int)(key >> m_iBitsPerWIndex);
    unsigned triangle = key & m_iNumBitsForIndex;
    int other = (int)triangle;
    triangle &= m_iNumBitsForWIndex;
    other >>= m_iBitsPerIndex;
    if (index == 0)
    {
        if (other != 0)
            return 1;
    }
    else
    {
        --index;
        if (index >= m_kChunks.m_iElementCount)
            return 2;
        unsigned uiNextTriangle = reinterpret_cast<reflected_havok::hkpCompressedMeshShapeChunk*>(m_kChunks.m_data)[index].hkpCompressedMeshShape_Chunk_getNextIndex(triangle - 1, &key);
        if (uiNextTriangle != triangle)
            return 3;
        if (key != (unsigned)other)
            return 4;
    }
    return 0;
}

namespace fnv_00e3d250 {
struct AabbQ
{
    ::hkVector4 m_kMinimumCorner;
    ::hkVector4 m_kMaximumCorner;
};

struct ChunkQ
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    unsigned short m_kSmartReference;
    unsigned short m_iSectionVertexCount;
    unsigned int unk48, unk4c;

    void ForwardCall_00e3cd20(float error, AabbQ* aabb, const ::hkVector4* scale);
};

struct CompressedMeshChunkBounds : ::hkpCompressedMeshShape
{
    void ComputeValues_00e3d250(const ChunkQ* chunk, AabbQ* aabb);
};

union QuadVector
{
    struct { ::hkVector4 v; };
    union { LocalM128 q; LocalM128 m_vComponents; };
};

// Calls FUN_00e3cd20 with aabb on the chunk (or the chunk it references), then transforms aabb's corners by that chunk's transform scaled by m_vScale, if any.
// @fnv 0x00e3d250
// src: GUESS 0x00e3d250 (confidence: low)
void CompressedMeshChunkBounds::ComputeValues_00e3d250(const ChunkQ* chunk, AabbQ* aabb)
{
    if (chunk->m_kSmartReference == 0xffff)
        ((ChunkQ*)chunk)->ForwardCall_00e3cd20(m_eScriptError, aabb, &(*reinterpret_cast<const ::hkVector4*>(&padD4[0xC])));
    else
        reinterpret_cast<ChunkQ*>(m_kChunks.m_data)[chunk->m_kSmartReference].ForwardCall_00e3cd20(m_eScriptError, aabb, &(*reinterpret_cast<const ::hkVector4*>(&padD4[0xC])));

    if (chunk->m_iSectionVertexCount != 0xffff)
    {
        const ::hkTransform& t = reinterpret_cast<const ::hkTransform&>(m_kTransforms.m_data[chunk->m_iSectionVertexCount]);
        QuadVector c0, c1, c2, tr;
        CopyReflectionQuad(&c0.v, &t.m_rotation.m_kColumn0);
        CopyReflectionQuad(&c1.v, &t.m_rotation.m_kColumn1);
        CopyReflectionQuad(&c2.v, &t.m_rotation.m_kColumn2);
        CopyReflectionQuad(&tr.v, &t.m_vTranslation);
        ::Transform scaled;
        scaled.r[0] = c0.q;
        scaled.r[1] = c1.q;
        scaled.r[2] = c2.q;
        scaled.r[3] = _mm_mul_ps(tr.m_vComponents, (*reinterpret_cast<const ::hkVector4*>(&padD4[0xC])).m_vComponents);
        aabb->m_kMaximumCorner.setTransformedPos_00c7f640(scaled, aabb->m_kMaximumCorner);
        aabb->m_kMinimumCorner.setTransformedPos_00c7f640(scaled, aabb->m_kMinimumCorner);
    }
}
}  // namespace fnv_00e3d250

namespace fnv_00e3d380 {
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
}

extern LocalM128 DAT_010c71d0;

void __cdecl hkAabbUtil_calcAabb_00d26230(const ::hkTransform& localToWorld, const ::hkVector4& halfExtents, const ::hkVector4& center,
                          float tolerance, ::hkAabb& out);

__forceinline LocalM128 LD(const ::hkVector4& v)
{
    return *reinterpret_cast<const LocalM128*>(&v);
}
__forceinline void ST(::hkVector4& v, LocalM128 q)
{
    *reinterpret_cast<LocalM128*>(&v) = q;
}

__forceinline void getCenter(const ::hkAabb& b, ::hkVector4& c)
{
    ST(c, _mm_mul_ps(_mm_add_ps(LD(b.m_kMinimumCorner), LD(b.m_kMaximumCorner)), DAT_010c71d0));
}
__forceinline void getHalfExtents(const ::hkAabb& b, ::hkVector4& he)
{
    ST(he, _mm_mul_ps(_mm_sub_ps(LD(b.m_kMaximumCorner), LD(b.m_kMinimumCorner)), DAT_010c71d0));
}

}  // namespace fnv_00e3d380

// Computes the world-space AABB of the compressed mesh by transforming its bounds center and half extents with the given tolerance.
// @fnv 0x00e3d380
void hkpCompressedMeshShape::CalculateAabb(const ::hkTransform& localToWorld, float tolerance, ::hkAabb& out) const
{
    ::hkVector4 center;
    fnv_00e3d380::getCenter(reinterpret_cast<const ::hkAabb&>(m_kBounds), center);
    ::hkVector4 halfExtents;
    fnv_00e3d380::getHalfExtents(reinterpret_cast<const ::hkAabb&>(m_kBounds), halfExtents);
    fnv_00e3d380::hkAabbUtil_calcAabb_00d26230(reinterpret_cast<const ::hkTransform&>(localToWorld), halfExtents, center, tolerance, reinterpret_cast<::hkAabb&>(out));
}

// Returns the next key of the shape: big triangles first (chunk id 0), then the compressed
// chunks (chunk id 1..maxChunk-1), then the convex pieces (chunk id maxChunk).
// Key layout: bitsPerWIndex = chunk id, wIndexMask/indexMask = element index,
// bitsPerIndex = the winding bit of the returned triangle.

// Triangle-iteration view uses index/strip counts at +0x20/+0x2C and a reference at +0x44.
class CompressedChunkTriangleIterator
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    int m_iIndexCount;
    unsigned int unk24;
    unsigned short* m_pStripIndices;
    int m_numStrips;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    hkUint16 m_kSmartReference;  // 0xffff: no reference, otherwise an index into the chunk array
    unsigned short unk46;
    unsigned int unk48, unk4c;

    int hkpCompressedMeshShape_Chunk_getNextIndex(int iIndex, int& iWinding) throw();
};

// The shared header does not redeclare the container's key iterator.
class CompressedMeshKeyIterator : public hkpCompressedMeshShape
{
  public:
    unsigned int GetNextShapeKey(unsigned int uiOldKey) const;
};

// src: HAVOK_LIB 0x00e3ca10
__declspec(noinline) int CompressedChunkTriangleIterator::hkpCompressedMeshShape_Chunk_getNextIndex(int index, int& winding) throw()
{
    winding = 0;
    if (index < 0)
        return m_iIndexCount ? 0 : -1;
    ++index;
    int strip = 0, end = 0, start = 0;
    for (; strip < m_numStrips; ++strip)
    {
        start = end;
        end += m_pStripIndices[strip];
        if (index < end)
            break;
    }
    if (strip >= m_numStrips)
    {
        while ((index - end) % 3)
            ++index;
    }
    else if (index >= end - 2)
    {
        index = end;
    }
    else
    {
        winding = (index - start) & 1;
    }
    return index < m_iIndexCount ? index : -1;
}

// Computes the next key in the compressed mesh shape key space by traversing big triangles, chunks, and convex pieces.
// @fnv 0x00e3cb10
unsigned int CompressedMeshKeyIterator::GetNextShapeKey(unsigned int uiOldKey) const
{
    int i = (int)uiOldKey;
    const ::hkArray<CompressedChunkTriangleIterator>& chunks = reinterpret_cast<const ::hkArray<CompressedChunkTriangleIterator>&>(m_kChunks);
    const int iBitsPerWIndex = m_iBitsPerWIndex;
    unsigned int uiChunkId = (unsigned int)i >> iBitsPerWIndex;
    int iIndex = i & m_iNumBitsForWIndex;
    if (uiChunkId == 0)
    {
        // the big triangles come first
        iIndex++;
        if (iIndex < m_kBigTriangles.m_iElementCount)
            return (unsigned int)iIndex;
        uiChunkId = 1;
        iIndex = -1;
    }
    const unsigned int uiMaxChunk = (1u << (32 - iBitsPerWIndex)) - 1;
    if (uiChunkId != uiMaxChunk)
    {
        // walk the compressed chunks
        int i = (int)uiChunkId - 1;
        const int iNumChunks = chunks.m_iElementCount;
        if (i < iNumChunks)
        {
            CompressedChunkTriangleIterator* pkChunks = chunks.m_data;
            do
            {
                CompressedChunkTriangleIterator* pkChunk = &pkChunks[i];
                int iWinding = 0;
                if (pkChunk->m_kSmartReference != 0xffff)
                    iIndex = chunks.m_data[pkChunk->m_kSmartReference].hkpCompressedMeshShape_Chunk_getNextIndex(iIndex, iWinding);
                else
                    iIndex = pkChunk->hkpCompressedMeshShape_Chunk_getNextIndex(iIndex, iWinding);
                if (iIndex != -1 && iIndex <= m_iNumBitsForWIndex)
                    return ((iWinding & 1) << m_iBitsPerIndex) | ((i + 1) << iBitsPerWIndex) |
                           (iIndex & m_iNumBitsForIndex);
                iIndex = -1;
                i++;
            } while (i < iNumChunks);
        }
    }
    // the convex pieces come last
    iIndex++;
    if (iIndex < m_kConvexPieces.m_iElementCount)
        return (uiMaxChunk << iBitsPerWIndex) | (unsigned int)iIndex;
    return 0xffffffff;
}

class CompressedChunk
{
  public:
    hkVector4q m_offset;
    hkUint16* m_kVertices;
    int m_iStridedVertexCount;
    int m_verticesCapacity;

    __forceinline void getVertex(unsigned int index, hkReal error, hkVector4q& vertex) const
    {
        hkVector4q quantized;
        quantized.set(m_kVertices[index], m_kVertices[index + 1], m_kVertices[index + 2], 0.0f);
        LocalM128 scale = _mm_load_ss(&error);
        scale = _mm_shuffle_ps(scale, scale, 0);
        vertex.m_vComponents = _mm_add_ps(_mm_mul_ps(quantized.m_vComponents, scale), m_offset.m_vComponents);
    }

    void ProcessState_00e3cd50(unsigned int i0, unsigned int i1, unsigned int i2, hkReal error, hkVector4q& v0, hkVector4q& v1,
                      hkVector4q& v2) const;
};

// Calls getVertex for i0, i1 and i2 to write v0, v1 and v2, each uint16 triple scaled by error and offset by m_offset.
// @fnv 0x00e3cd50
// src: GUESS 0x00e3cd50 (confidence: low)
void CompressedChunk::ProcessState_00e3cd50(unsigned int i0, unsigned int i1, unsigned int i2, hkReal error, hkVector4q& v0,
                                   hkVector4q& v1, hkVector4q& v2) const
{
    getVertex(i0, error, v0);
    getVertex(i1, error, v1);
    getVertex(i2, error, v2);
}

inline void* operator new(unsigned int, void* memory)
{
    return memory;
}

extern hkVector4 DAT_01268370;
extern hkVector4 DAT_01268380;
extern hkVector4 DAT_01268390;
extern hkVector4 DAT_012683a0;
extern float DAT_011b153c;
extern float DAT_0104da48, DAT_0104e148, DAT_01011d78;
extern hkVector4 DAT_010c71d0;
extern int DAT_010c749c;
struct VertexBlock
{
    hkVector4 x, y, z;
};
extern VertexBlock DAT_0126ec10[];
struct ConvexPiece
{
    hkVector4 offset;
    ::hkArray<hkUint16> vertices;
    ::hkArray<hkUint8> faces;
    ::hkArray<hkUint8> indices;
    hkUint16 reference, transform;
    unsigned int material;
    unsigned int unk3c;
};
struct Chunk
{
    hkVector4 offset;
    ::hkArray<hkUint16> vertices;
    ::hkArray<hkUint16> indices;
    ::hkArray<hkUint16> strips;
    ::hkArray<hkUint16> welding;
    unsigned int unk40;
    hkUint16 reference, transform;
    unsigned int material;
    unsigned int unk4c;
    void ProcessState_00e3cd50(int a, int b, int c, float error, hkVector4& va, hkVector4& vb, hkVector4& vc);
};
struct BigTriangle
{
    hkUint16 a, b, c, unk06;
    unsigned int material;
    hkUint16 welding, unk0e;
};
inline LocalM128 MulV(const hkVector4& a, const hkVector4& b)
{
    return _mm_mul_ps(_mm_load_ps(&a.x), *(const LocalM128*)&b);
}
inline LocalM128 MulQ(LocalM128 a, LocalM128 b)
{
    return _mm_mul_ps(a, b);
}
struct Triangle
{
    int* vtable;
    hkUint16 memorySize, references;
    unsigned int userData, type;
    float radius;
    hkUint16 welding;
    hkUint8 weldingType, extruded;
    hkVector4 vertices[3], extrusion;
    __forceinline Triangle(float r)
    {
        references = 1;
        userData = 0;
        type = 3;
        radius = r;
        vtable = &DAT_010c749c;
        welding = 0;
        weldingType = 6;
        *(LocalM128*)&extrusion = _mm_setzero_ps();
        extruded = 0;
    }
};
struct ConvexShape
{
    int* vtable;
    hkUint16 memorySize, references;
    unsigned int userData, type;
    float radius;
    unsigned int unk14, unk18, unk1c;
    hkVector4 halfExtents, center;
    VertexBlock* vertices;
    int blockCount, capacity, vertexCount;
    ConvexPiece* piece;
    ConvexShape(float radius);
};
struct ShapeBuffer
{
    ConvexShape* FUN_00d59710(float radius);
};
struct BufferRef
{
    ShapeBuffer* p;
    operator bool() const
    {
        return p != 0;
    }
    ShapeBuffer* operator->() const
    {
        return p;
    }
};
// This query is entered through the mesh's secondary container base.
struct CompressedMeshChildQuery : ::hkpShapeContainer
{
    Triangle* AllocateStorage_00e3d3f0(unsigned int key, BufferRef buffer);
};

// Decodes key into a big triangle, chunk triangle or convex piece, applies its transform and scale, and returns a Triangle or ConvexShape built in buffer.
// @fnv 0x00e3d3f0
// src: GUESS 0x00e3d3f0 (confidence: low)
Triangle* CompressedMeshChildQuery::AllocateStorage_00e3d3f0(unsigned int key, BufferRef buffer)
{
    hkpCompressedMeshShape& mesh = *reinterpret_cast<hkpCompressedMeshShape*>(reinterpret_cast<char*>(this) - sizeof(hkpShape));
    int index;
    (void)index;
    int count;
    (void)count;
    int iBlockCount;
    (void)iBlockCount;
    BufferRef bufv = buffer;
    unsigned int chunkIndex = key >> mesh.m_iBitsPerWIndex;
    index = key & mesh.m_iNumBitsForIndex;
    int winding = index >> mesh.m_iBitsPerIndex;
    Transform transform;
    if (chunkIndex == (1 << (32 - mesh.m_iBitsPerWIndex)) - 1)
    {
        _mm_store_ps(&transform.m_f00, _mm_load_ps(&DAT_01268370.x));
        _mm_store_ps(&transform.m_f10, _mm_load_ps(&DAT_01268380.x));
        _mm_store_ps(&transform.m_f20, _mm_load_ps(&DAT_01268390.x));
        _mm_store_ps(&transform.m_f30, _mm_load_ps(&DAT_012683a0.x));
        ConvexShape* shape = bufv ? bufv->FUN_00d59710(mesh.m_fSphereRadius) : 0;
        ConvexPiece* pieces = reinterpret_cast<ConvexPiece*>(mesh.m_kConvexPieces.m_data);
        if (pieces[index].transform != 0xffff)
        {
            ::hkTransform& t = reinterpret_cast<::hkTransform&>(mesh.m_kTransforms.m_data[pieces[index].transform]);
            _mm_store_ps(&transform.m_f00, _mm_load_ps(&t.m_rotation.m_kColumn0.x));
            _mm_store_ps(&transform.m_f10, _mm_load_ps(&t.m_rotation.m_kColumn1.x));
            _mm_store_ps(&transform.m_f20, _mm_load_ps(&t.m_rotation.m_kColumn2.x));
            _mm_store_ps(&transform.m_f30, _mm_load_ps(reinterpret_cast<const float*>(&t.m_vTranslation)));
        }
        if (pieces[index].reference != 0xffff)
            index = pieces[index].reference;
        ConvexPiece* piece = &pieces[index];
        const hkUint16* vertices = piece->vertices.m_data;
        count = piece->vertices.m_iElementCount / 3;
        iBlockCount = (count + 3) >> 2;
        hkAabb bounds;
        LocalM128& minimum = *(LocalM128*)&bounds.m_kMinimumCorner.x;
        LocalM128& maximum = *(LocalM128*)&bounds.m_kMaximumCorner.x;
        minimum = _mm_set_ps1(DAT_0104da48);
        maximum = _mm_set_ps1(DAT_0104e148);
        LocalM128 tolerance = _mm_load_ss(&mesh.m_eScriptError);
        int vertex = 0;
        VertexBlock* output = DAT_0126ec10 + 1;
        int iv;
        hkVector4 v[4];
        for (int i = 0; i < iBlockCount; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                float fx, fy, afDepth;
                *&iv = vertices[0];
                fx = (float)((float)iv);
                *&iv = vertices[1];
                fy = (float)iv;
                *&iv = vertices[2];
                afDepth = (float)iv;
                hkVector4 source;
                _mm_store_ps(&source.x, _mm_add_ps(_mm_mul_ps(_mm_setr_ps(fx, fy, afDepth, DAT_01011d78),
                                                              _mm_shuffle_ps(tolerance, tolerance, 0)),
                                                   *(const LocalM128*)&piece->offset));
                v[j].setTransformedPos_00c7f640(transform, source);
                minimum = _mm_min_ps(minimum, _mm_load_ps(&source.x));
                maximum = _mm_max_ps(maximum, _mm_load_ps(&source.x));
                if (vertex < count - 1)
                {
                    ++vertex;
                    vertices += 3;
                }
            }
            LocalM128& r0 = *(LocalM128*)&v[0];
            LocalM128& r1 = *(LocalM128*)&v[1];
            LocalM128& r2 = *(LocalM128*)&v[2];
            LocalM128& r3 = *(LocalM128*)&v[3];
            LocalM128 tmp3, tmp2, tmp1, tmp0;
            tmp0 = _mm_shuffle_ps(r0, r1, 0x44);
            tmp2 = _mm_shuffle_ps(r0, r1, 0xEE);
            tmp1 = _mm_shuffle_ps(r2, r3, 0x44);
            tmp3 = _mm_shuffle_ps(r2, r3, 0xEE);
            r0 = _mm_shuffle_ps(tmp0, tmp1, 0x88);
            r1 = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
            r2 = _mm_shuffle_ps(tmp2, tmp3, 0x88);
            r3 = _mm_shuffle_ps(tmp2, tmp3, 0xDD);
            *(LocalM128*)&output[-1].x = r0;
            *(LocalM128*)&output[-1].y = r1;
            *(LocalM128*)&output[-1].z = r2;
            ++output;
        }
        shape->vertices = DAT_0126ec10;
        shape->blockCount = iBlockCount;
        _ReadWriteBarrier();
        shape->capacity = 8;
        _ReadWriteBarrier();
        shape->vertexCount = count;
        _ReadWriteBarrier();
        shape->piece = piece;
        shape->halfExtents.m_vComponents = _mm_mul_ps(_mm_sub_ps(maximum, minimum), _mm_load_ps(&DAT_010c71d0.x));
        shape->center.m_vComponents = _mm_mul_ps(_mm_add_ps(maximum, minimum), _mm_load_ps(&DAT_010c71d0.x));
        return reinterpret_cast<Triangle*>(shape);
    }
    Triangle* triangle = new (bufv.p) Triangle(DAT_011b153c);
    {
        Triangle* __restrict tt = triangle;
        tt->radius = mesh.m_fSphereRadius;
    }
    triangle->weldingType = mesh.m_eWeldingType;
    if (chunkIndex == 0)
    {
        Triangle* __restrict tr = triangle;
        tr->welding = reinterpret_cast<BigTriangle*>(mesh.m_kBigTriangles.m_data)[index].welding;
        BigTriangle& big = reinterpret_cast<BigTriangle*>(mesh.m_kBigTriangles.m_data)[index];
        unsigned int iVertexA = big.a;
        const ::hkVector4* pBigVertices = reinterpret_cast<::hkVector4*>(mesh.m_kBigVertices.m_data);
        _mm_store_ps(&tr->vertices[0].x, _mm_load_ps(&pBigVertices[iVertexA].x));
        _mm_store_ps(&tr->vertices[1].x, _mm_load_ps(&pBigVertices[big.b].x));
        _mm_store_ps(&tr->vertices[2].x, _mm_load_ps(&pBigVertices[big.c].x));
        hkVector4 scalev;
        CopyReflectionQuad(&scalev, &mesh.padD4[0xC]);
        _mm_store_ps(&tr->vertices[0].x, MulV(scalev, tr->vertices[0]));
        _mm_store_ps(&tr->vertices[1].x, MulV(tr->vertices[1], scalev));
        _mm_store_ps(&triangle->vertices[2].x, MulQ(triangle->vertices[2].m_vComponents, scalev.m_vComponents));
        return triangle;
    }
    index &= mesh.m_iNumBitsForWIndex;
    --chunkIndex;
    _mm_store_ps(&transform.m_f00, _mm_setzero_ps());
    transform.m_f00 = 1.0f;
    _mm_store_ps(&transform.m_f10, _mm_setzero_ps());
    transform.m_f14 = 1.0f;
    _mm_store_ps(&transform.m_f20, _mm_setzero_ps());
    transform.m_f28 = 1.0f;
    _mm_store_ps(&transform.m_f30, _mm_setzero_ps());
    if (reinterpret_cast<Chunk*>(mesh.m_kChunks.m_data)[chunkIndex].transform != 0xffff)
    {
        ::hkTransform& t = reinterpret_cast<::hkTransform&>(mesh.m_kTransforms.m_data[reinterpret_cast<Chunk*>(mesh.m_kChunks.m_data)[chunkIndex].transform]);
        _mm_store_ps(&transform.m_f00, _mm_load_ps(&t.m_rotation.m_kColumn0.x));
        _mm_store_ps(&transform.m_f10, _mm_load_ps(&t.m_rotation.m_kColumn1.x));
        _mm_store_ps(&transform.m_f20, _mm_load_ps(&t.m_rotation.m_kColumn2.x));
        _mm_store_ps(&transform.m_f30, _mm_load_ps(reinterpret_cast<const float*>(&t.m_vTranslation)));
    }
    if (reinterpret_cast<Chunk*>(mesh.m_kChunks.m_data)[chunkIndex].reference != 0xffff)
        chunkIndex = reinterpret_cast<Chunk*>(mesh.m_kChunks.m_data)[chunkIndex].reference;
    Chunk* chunk = &reinterpret_cast<Chunk*>(mesh.m_kChunks.m_data)[chunkIndex];
    Triangle* __restrict tw = triangle;
    tw->welding = chunk->welding.m_data[index];
    {
        hkVector4 a, b, c;
        const hkUint16* indices = chunk->indices.m_data;
        chunk->ProcessState_00e3cd50(indices[index] * 3, indices[index + 1] * 3, indices[index + 2] * 3, mesh.m_eScriptError, a, b, c);
        a.setTransformedPos_00c7f640(transform, a);
        b.setTransformedPos_00c7f640(transform, b);
        c.setTransformedPos_00c7f640(transform, c);
        Triangle* __restrict tc = triangle;
        hkVector4 scalev2;
        CopyReflectionQuad(&scalev2, &mesh.padD4[0xC]);
        *(LocalM128*)&a = _mm_mul_ps(*(LocalM128*)&a, *(LocalM128*)&scalev2);
        *(LocalM128*)&b = _mm_mul_ps(*(LocalM128*)&b, *(LocalM128*)&scalev2);
        *(LocalM128*)&c = _mm_mul_ps(*(LocalM128*)&c, *(LocalM128*)&scalev2);
        *(LocalM128*)&tc->vertices[2 * winding] = *(LocalM128*)&a;
        *(LocalM128*)&tc->vertices[1] = *(LocalM128*)&b;
        *(LocalM128*)&tc->vertices[2 * (winding ^ 1)] = *(LocalM128*)&c;
        return triangle;
    }
}

void __cdecl hkArrayUtil__reserve(::hkMemoryAllocator& alloc, void* array, int numElem, int sizeElem);

// hkArray::setSize through this unit's heap allocator view (hkArrayUtil::_reserve is FUN_00c908c0).
template <class T> static __forceinline void SetSizeAndGrow(::hkArrayBase<T>& a, int n)
{
    ::hkMemoryAllocator& alloc = GetMemoryRouterE3D().heap();
    int cap = a.getCapacity();
    if (cap < n)
    {
        int cap2 = 2 * cap;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(alloc, &a, newSize, sizeof(T));
    }
    a.m_iElementCount = n;
}

struct ConvexVertexDecoder : CompressedChunk
{
    void ProcessEntries_00e3d9d0(hkReal quantization, const ::hkTransform& transform, ::hkArray<hkVector4q>& vertices) const;
};

// Expands the compressed vertex data into hkVector4q entries, applying quantization, offset, and transform to fill the output array.
// @fnv 0x00e3d9d0
// src: GUESS 0x00e3d9d0 (confidence: low)
void ConvexVertexDecoder::ProcessEntries_00e3d9d0(hkReal quantization, const ::hkTransform& transform,
                                       ::hkArray<hkVector4q>& vertices) const
{
    SetSizeAndGrow(vertices, m_iStridedVertexCount / 3);
    for (int i = 0; i < m_iStridedVertexCount; i += 3)
    {
        hkVector4q vertex;
        vertex.set(m_kVertices[i], m_kVertices[i + 1], m_kVertices[i + 2], 0.0f);
        LocalM128 q = _mm_load_ss(&quantization);
        vertex.m_vComponents = _mm_mul_ps(vertex.m_vComponents, _mm_shuffle_ps(q, q, 0));
        vertex.add4(m_offset);
        vertex.setTransformedPos_00c7f640(reinterpret_cast<const ::hkTransform&>(transform), vertex);
        vertices[i / 3].m_vComponents = vertex.m_vComponents;
    }
}

extern float DAT_01012068;

// Initializes the mesh with its radius, default key layout, arrays, and scale.
// @fnv 0x00e3dae0
hkpCompressedMeshShape::hkpCompressedMeshShape(float value)
    : hkpShapeCollection(0x10u, (unsigned char)6),
      m_kMaterials(FinishingFlag()), m_kMaterialIndices16(FinishingFlag()),
      m_kMaterialIndices8(FinishingFlag()), m_kTransforms(FinishingFlag()),
      m_kBigVertices(FinishingFlag()), m_kBigTriangles(FinishingFlag()),
      m_kChunks(FinishingFlag()), m_kConvexPieces(FinishingFlag()), m_kNamedMaterials(FinishingFlag())
{
    m_fSphereRadius = value;
    *reinterpret_cast<void**>(this) = &DAT_010eba5c;
    *reinterpret_cast<void**>(static_cast<hkpShapeContainer*>(this)) = &DAT_010eba3c;
    m_iBitsPerIndex = 0x11;
    m_iBitsPerWIndex = 0x12;
    m_iNumBitsForIndex = 0x3FFFF;
    m_iNumBitsForWIndex = 0x1FFFF;
    LocalM128 constantVector = _mm_set_ps1(DAT_01012068);

    static_cast<unsigned int* volatile&>(m_kMaterials.m_data) = 0;
    static_cast<volatile int&>(m_kMaterials.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kMaterials.m_iCapacityState) = 0x80000000;
    static_cast<unsigned short* volatile&>(m_kMaterialIndices16.m_data) = 0;
    static_cast<volatile int&>(m_kMaterialIndices16.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kMaterialIndices16.m_iCapacityState) = 0x80000000;
    static_cast<unsigned char* volatile&>(m_kMaterialIndices8.m_data) = 0;
    static_cast<volatile int&>(m_kMaterialIndices8.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kMaterialIndices8.m_iCapacityState) = 0x80000000;
    static_cast<hkTransform* volatile&>(m_kTransforms.m_data) = 0;
    static_cast<volatile int&>(m_kTransforms.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kTransforms.m_iCapacityState) = 0x80000000;
    static_cast<hkVector4* volatile&>(m_kBigVertices.m_data) = 0;
    static_cast<volatile int&>(m_kBigVertices.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kBigVertices.m_iCapacityState) = 0x80000000;
    static_cast<hkpCompressedMeshShapeBigTriangle* volatile&>(m_kBigTriangles.m_data) = 0;
    static_cast<volatile int&>(m_kBigTriangles.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kBigTriangles.m_iCapacityState) = 0x80000000;
    static_cast<hkpCompressedMeshShapeChunk* volatile&>(m_kChunks.m_data) = 0;
    static_cast<volatile int&>(m_kChunks.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kChunks.m_iCapacityState) = 0x80000000;
    static_cast<hkpCompressedMeshShapeConvexPiece* volatile&>(m_kConvexPieces.m_data) = 0;
    static_cast<volatile int&>(m_kConvexPieces.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kConvexPieces.m_iCapacityState) = 0x80000000;

    static_cast<void* volatile&>(m_pUserData) = 0;
    static_cast<volatile unsigned short&>(m_iIndexStriding) = 0;
    static_cast<volatile unsigned short&>(m_iNumTriangles) = 0;
    static_cast<hkpNamedMeshMaterial* volatile&>(m_kNamedMaterials.m_data) = 0;
    static_cast<volatile int&>(m_kNamedMaterials.m_iElementCount) = 0;
    static_cast<volatile int&>(m_kNamedMaterials.m_iCapacityState) = 0x80000000;

    static_cast<volatile unsigned char&>(m_eWeldingType) = 6;
    *reinterpret_cast<LocalM128*>(&padD4[0xC]) = constantVector;
}

namespace reflected_havok
{
class hkpCompressedMeshShapeBigTriangle
{
  public:
    unsigned short a, b, c, weldingInfo;
    unsigned material;
    unsigned unk0c;
};
}
struct CompressedMeshMaterialQuery : ::hkpCompressedMeshShape
{
    void* hkpCompressedMeshShape_getMaterial(unsigned key);
};
// Resolves a material index from a compressed mesh key and returns a pointer into the material data buffer.
// @fnv 0x00e3d0e0
// src: HAVOK_LIB 0x00e3d0e0
void* CompressedMeshMaterialQuery::hkpCompressedMeshShape_getMaterial(unsigned key)
{
    char* materials = (char*)m_pUserData;
    if (!materials)
        return 0;
    unsigned chunkIndex = key >> m_iBitsPerWIndex;
    unsigned triangle = key & m_iNumBitsForWIndex;
    if (chunkIndex == 0)
    {
        triangle = reinterpret_cast<reflected_havok::hkpCompressedMeshShapeBigTriangle*>(m_kBigTriangles.m_data)[triangle].material;
    }
    else
    {
        if (chunkIndex == ((1u << (32 - m_iBitsPerWIndex)) - 1))
            return 0;
        unsigned short reference = reinterpret_cast<reflected_havok::hkpCompressedMeshShapeChunk*>(m_kChunks.m_data)[chunkIndex - 1].reference;
        if (reference != 0xffff)
            chunkIndex = reference;
        else
            --chunkIndex;
        unsigned int material = reinterpret_cast<reflected_havok::hkpCompressedMeshShapeChunk*>(m_kChunks.m_data)[chunkIndex].materialInfo;
        switch ((unsigned int)m_ucMaterialType)
        {
        case MATERIAL_SINGLE_VALUE_PER_CHUNK:
            triangle = material;
            break;
        case MATERIAL_FOUR_BYTES_PER_TRIANGLE:
            triangle = m_kMaterials.m_data[material + triangle];
            break;
        case MATERIAL_TWO_BYTES_PER_TRIANGLE:
            triangle = m_kMaterialIndices16.m_data[material + triangle];
            break;
        case MATERIAL_ONE_BYTE_PER_TRIANGLE:
            triangle = m_kMaterialIndices8.m_data[material + triangle];
            break;
        default:
            return 0;
        }
    }
    return materials + m_iIndexStriding * triangle;
}

struct ChunkAabbCalls
{
    void ForwardCall_00e3cd20(float, ::hkVector4*, ::hkVector4*);
};
struct CompressedMeshContentBounds : ::hkpCompressedMeshShape
{
    void GetChunkBounds(hkAabbq* out);
};

// Computes the bounding box by expanding an initial AABB with the AABB of each chunk in m_kChunks.
// @fnv 0x00e3cf40
// src: GUESS 0x00e3cf40 (confidence: medium)
void CompressedMeshContentBounds::GetChunkBounds(hkAabbq* out)
{
    (out->m_kMinimumCorner.*static_cast<void (hkVector4q::*)(float)>(&hkVector4q::SetAllComponents))(DAT_0104da48);
    (out->m_kMaximumCorner.*static_cast<void (hkVector4q::*)(float)>(&hkVector4q::SetAllComponents))(DAT_0104e148);
    for (int i = 0; i < m_kChunks.m_iElementCount; i++)
    {
        hkAabbq aabb;
        ((ChunkAabbCalls&)m_kChunks.m_data[i])
            .ForwardCall_00e3cd20(m_eScriptError, (::hkVector4*)&aabb, (::hkVector4*)&padD4[0xC]);
        out->m_kMinimumCorner.setMin4(out->m_kMinimumCorner, aabb.m_kMinimumCorner);
        out->m_kMaximumCorner.setMax4(out->m_kMaximumCorner, aabb.m_kMaximumCorner);
    }
}
