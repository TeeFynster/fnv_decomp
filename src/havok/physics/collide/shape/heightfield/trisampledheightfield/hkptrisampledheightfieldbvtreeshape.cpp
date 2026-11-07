#include "../../../../../../../include/hkArray.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form

// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep this unit's minimal intrinsic declaration: the SDK's extra byte-array union members
// change MSVC 9's /GS classification without changing the SIMD representation.
#define _INCLUDED_MM2
// Exe 0x00d26940 FUN_00d26940: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_or_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_setzero_ps(void);
}

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkpSampledHeightFieldShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpTriSampledHeightFieldCollection.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../include/hkThreadMemory.h"

struct hkSimdVector
{
    union
    {
        LocalM128 m_vComponents;
        float m_f[4];
        struct { float x, y, z, w; };
    };

    __forceinline void operator=(const hkSimdVector& value)
    {
        m_vComponents = value.m_vComponents;
    }
};

// These constructors stay inline here so AABB temporaries keep their original code.

__forceinline hkAabb::hkAabb()
{}

__forceinline hkAabb::hkAabb(const hkAabb& a) throw()
{
    m_kMinimumCorner.m_vComponents = a.m_kMinimumCorner.m_vComponents;
    m_kMaximumCorner.m_vComponents = a.m_kMaximumCorner.m_vComponents;
}

// The BV tree's reflected layout is not yet provided by include/.
#pragma pack(push, 1)
class hkpTriSampledHeightFieldBvTreeShape
{
  public:
    char pad0[0x14];
    hkpSingleShapeContainer m_kChildContainer;
    hkInt32 m_iChildSize;
    hkBool m_bCheckHeightFieldBounds;
    unsigned char m_ucUnknownByte[12];
    char pad2D[3];
};
#pragma pack(pop)

// ---------------------------------------------------------------------------
// The shape container.  It derives from the real class so that the members
// keep their real offsets: m_kChildContainer.m_pContainedShape lives at +0x18.
// ---------------------------------------------------------------------------
struct TriSampledHeightFieldBvTreeShape : public hkpTriSampledHeightFieldBvTreeShape
{
    void hkpTriSampledHeightFieldBvTreeShape_getContainer();
};

// @fnv 0x00d27200
// src: HAVOK_LIB 0x00d27200
void TriSampledHeightFieldBvTreeShape::hkpTriSampledHeightFieldBvTreeShape_getContainer()
{
    m_kChildContainer.m_pContainedShape->GetShapeContainer();
}

struct FUN_00d268b0_Obj : public hkpTriSampledHeightFieldBvTreeShape
{
    int __thiscall hkpTriSampledHeightFieldBvTreeShape_calcSizeForSpu(int a, int b);
};

// @fnv 0x00d268b0
// src: HAVOK_LIB 0x00d268b0
int __thiscall FUN_00d268b0_Obj::hkpTriSampledHeightFieldBvTreeShape_calcSizeForSpu(int a, int aiUnused)
{
    const hkpShape* childShape = m_kChildContainer.m_pContainedShape;
    unsigned int result = (unsigned int)childShape->CalcSizeForSpu(
        *reinterpret_cast<const hkpShape::PhysicsShape*>(a), 0x100);
    if (result <= 0x100u)
    {
        m_iChildSize = (hkInt32)result;
        return 0x30;
    }
    return -1;
}

struct ShapeDispatch
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    const hkpShape* shape;
    void DispatchCallback(void* first, float value, void* last);
};
// @fnv 0x00d26ae0
void ShapeDispatch::DispatchCallback(void* first, float value, void* last)
{
    shape->CalculateAabb(*static_cast<const hkTransform*>(first), value, *static_cast<hkAabb*>(last));
}

class hkObjD26B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const hkpTriSampledHeightFieldCollection* m_holder;

    hkBool Query(void* a, void* b) throw();
};

// Forwards the two arguments to the query method of the target obtained from m_holder and returns its result.
// @fnv 0x00d26b00
hkBool hkObjD26B::Query(void* a, void* b) throw()
{
    return m_holder->getHeightFieldShape()->IntersectRayWithShape(
        *static_cast<const ShapeRayCastQuery*>(a), *static_cast<ShapeRayCastOutput*>(b));
}

extern void __cdecl ComputeAabbFromTransform(int, int, float, char*);

class FUN_00d268f0_Shape
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void ProcessBuffer(int, int, float, int);
    virtual void CollectHits(char*, int);
};

// Calls ComputeAabbFromTransform(a, b, c, &buffer), then calls CollectHits with that buffer and d.
// @fnv 0x00d268f0
void __thiscall FUN_00d268f0_Shape::ProcessBuffer(int a, int b, float c, int d)
{
    hkAabb buffer;

    ComputeAabbFromTransform(a, b, c, reinterpret_cast<char*>(&buffer));
    CollectHits(reinterpret_cast<char*>(&buffer), d);
}

extern int DAT_010c6fd0;
extern int DAT_010ce404;

struct FUN_00d26b50
{
    const int* m_pVT;
    char pad4[2];
    unsigned short m_uiValue1;
    int m_iA;
    int m_iB;
    unsigned char m_bC;
    char pad11[3];
    const int* m_pD;
    hkpShape* m_pShape;
    char pad1d[4];
    unsigned char m_bE;
    FUN_00d26b50(hkpShape* pShape, unsigned char bE);
};

// Initializes a FUN_00d26b50 object with default values, assigns pShape and bE, and calls pShape->FUN_00c90510().
// @fnv 0x00d26b50
FUN_00d26b50::FUN_00d26b50(hkpShape* pShape, unsigned char bE)
{
    m_uiValue1 = 1;
    m_iA = 0;
    m_iB = 8;
    m_bC = 1;
    m_pVT = &DAT_010ce404;
    m_pD = &DAT_010c6fd0;
    m_pShape = pShape;
    m_pShape->addReference();
    m_bE = bE;
}

extern "C" hkThreadMemory* hkMemoryRouter_getInstance();
extern "C" void ResizeAudioStream(hkMemory* memory, void* array, int elemSize);
extern "C" void hkArrayUtil__reserve(hkMemory* memory, void* array, int numElements, int elemSize);

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

static __forceinline void hkShapeKeyArray_AddBack(hkArrayBase<hkUint32>& self, const hkUint32& e)
{
        hkThreadMemory* tm = hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity())
        {
            ResizeAudioStream(tm->m_pMemoryAllocator, (&self), sizeof(hkUint32));
        }
        hkConstructWithCopy(self.m_data + self.m_iElementCount, 1, e);
        self.m_iElementCount++;
    }

static __forceinline void hkShapeKeyArray_SetSizeAndGrow(hkArrayBase<hkUint32>& self, int n)
{
        hkThreadMemory* tm = hkMemoryRouter_getInstance();
        hkMemory* memory = tm->m_pMemoryAllocator;
        int cap = self.getCapacity();
        if (cap < n)
        {
            int cap2 = cap + cap;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(memory, (&self), newSize, sizeof(hkUint32));
        }
        self.m_iElementCount = n;
    }


__declspec(noalias) hkBool hkpTriSampledHeightFieldBvTreeShape_getExtentsForQueryAabb(const hkAabb* aabb, const hkpTriSampledHeightFieldCollection* collection,
                                         hkUint32* minX, hkUint32* maxX, hkUint32* minZ, hkUint32* maxZ);

struct TriSampledHeightFieldBvTreeShapeq : public hkpTriSampledHeightFieldBvTreeShape
{
    __forceinline const hkpTriSampledHeightFieldCollection* getShapeCollection() const
    {
        return static_cast<const hkpTriSampledHeightFieldCollection*>(m_kChildContainer.m_pContainedShape);
    }
    void CollectHits(const hkAabb& aabbIn, hkArrayBase<hkUint32>& hits) const;
};

// Appends shape keys for grid cells overlapping aabbIn to hits; with bounds checking, drops them if all sampled heights are above or below the AABB.
// @fnv 0x00d26e50
void TriSampledHeightFieldBvTreeShapeq::CollectHits(const hkAabb& aabbIn, hkArrayBase<hkUint32>& hits) const
{
    hkAabb aabb(aabbIn);

    hkUint32 minX, maxX, minZ, maxZ;
    {
        hkBool valid = hkpTriSampledHeightFieldBvTreeShape_getExtentsForQueryAabb(&aabb, getShapeCollection(), &minX, &maxX, &minZ, &maxZ);
        if (!valid)
        {
            return;
        }
    }

    const hkpSampledHeightFieldShape* hf = getShapeCollection()->getHeightFieldShape();
    int origSize = hits.GetLogicalSize();

    if (m_bCheckHeightFieldBounds)
    {
        hkBool allBelow = true;
        hkBool allAbove = true;

        for (hkUint32 x = minX; x <= maxX; x++)
        {
            for (hkUint32 z = minZ; z <= maxZ; z++)
            {
                hkUint32 key = (z << 16) + (x << 1);
                hkShapeKeyArray_AddBack(hits, key);
                hkShapeKeyArray_AddBack(hits, key | 1);

                if (allBelow || allAbove)
                {
                    hkReal raw = hf->GetHeightAtGridPoint(x, z);
                    hkReal h = raw * hf->m_kHeightScaleVector.y;
                    if (aabb.m_kMinimumCorner.y < h)
                    {
                        allBelow = false;
                    }
                    if (h < aabb.m_kMaximumCorner.y)
                    {
                        allAbove = false;
                    }
                }
            }
        }

        if (!allBelow && !allAbove)
        {
            return;
        }

        for (hkUint32 x = minX; x <= maxX + 1; x++)
        {
            hkReal raw = hf->GetHeightAtGridPoint(x, maxZ + 1);
            hkReal h = raw * hf->m_kHeightScaleVector.y;
            if (aabb.m_kMinimumCorner.y < h)
            {
                allBelow = false;
            }
            if (h < aabb.m_kMaximumCorner.y)
            {
                allAbove = false;
            }
        }

        for (hkUint32 z = minZ; z <= maxZ + 1; z++)
        {
            hkReal raw = hf->GetHeightAtGridPoint(maxX + 1, z);
            hkReal h = raw * hf->m_kHeightScaleVector.y;
            if (aabb.m_kMinimumCorner.y < h)
            {
                allBelow = false;
            }
            if (h < aabb.m_kMaximumCorner.y)
            {
                allAbove = false;
            }
        }

        if (allBelow || allAbove)
        {
            hkShapeKeyArray_SetSizeAndGrow(hits, origSize);
        }
    }
    else
    {
        for (hkUint32 x = minX; x <= maxX; x++)
        {
            for (hkUint32 z = minZ; z <= maxZ; z++)
            {
                hkUint32 key = (z << 16) + (x << 1);
                hkShapeKeyArray_AddBack(hits, key);
                hkShapeKeyArray_AddBack(hits, key | 1);
            }
        }
    }
}

struct FUN_00d26b30_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    const hkpTriSampledHeightFieldCollection* m_holder;

    void hkpTriSampledHeightFieldBvTreeShape_castRayWithCollectorImpl(int a, int b, int c, int d);
};

// @fnv 0x00d26b30
// src: HAVOK_LIB 0x00d26b30
void FUN_00d26b30_cls::hkpTriSampledHeightFieldBvTreeShape_castRayWithCollectorImpl(int a, int b, int c, int d)
{
    const hkpSampledHeightFieldShape* shape = m_holder->getHeightFieldShape();
    // Preserve this forwarding entry point's four-word argument ABI.
    typedef void (__thiscall *CollectorFunction)(const hkpSampledHeightFieldShape*, int, int, int, int);
    reinterpret_cast<CollectorFunction>((*reinterpret_cast<void* const* const*>(shape))[9])(shape, a, b, c, d);
}

__forceinline hkSimdVector& simd(hkVector4& value)
{
    return reinterpret_cast<hkSimdVector&>(value);
}

__forceinline const hkSimdVector& simd(const hkVector4& value)
{
    return reinterpret_cast<const hkSimdVector&>(value);
}

struct hkVector4Comparisonq
{
    LocalM128 m_uiMask;
};

extern const LocalM128 hkVector4Comparison_maskXYZW;

extern const hkTransform hkTransform_identity;

union hkQuadUintq
{
    LocalM128 q;
    hkUint32 i[4];
};

struct hkUint16x4
{
    hkUint16 x;
    hkUint16 y;
    hkUint16 z;
    hkUint16 w;
};

__forceinline const hkSimdVector& getFloatToIntScale(const hkpSampledHeightFieldShape* hf)
{
    return simd(hf->m_kInverseScale);
}

__forceinline const hkSimdVector& getFloatToIntOffsetFloorCorrected(const hkpSampledHeightFieldShape* hf)
{
    return simd(hf->m_kOffset);
}

extern const hkVector4 hkVector4Util_uint16Magic;

__forceinline hkReal getRadius(const hkpTriSampledHeightFieldCollection* collection)
{
    return collection->m_fSphereRadius;
}

__forceinline void SetAllComponents(hkSimdVector& self, hkReal r)
{
    self.m_vComponents = _mm_set_ps1(r);
}
__forceinline void setZero4(hkSimdVector& self)
{
    self.m_vComponents = _mm_setzero_ps();
}
__forceinline void set(hkSimdVector& self, hkReal a, hkReal b, hkReal c, hkReal d)
{
    self.m_vComponents = _mm_setr_ps(a, b, c, d);
}
__forceinline void add4(hkSimdVector& self, const hkSimdVector& v)
{
    self.m_vComponents = _mm_add_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void sub4(hkSimdVector& self, const hkSimdVector& v)
{
    self.m_vComponents = _mm_sub_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void mul4(hkSimdVector& self, const hkSimdVector& v)
{
    self.m_vComponents = _mm_mul_ps(self.m_vComponents, v.m_vComponents);
}
__forceinline void setAdd4(hkSimdVector& self, const hkSimdVector& a, const hkSimdVector& b)
{
    self.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void setMin4(hkSimdVector& self, const hkSimdVector& a, const hkSimdVector& b)
{
    self.m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline void setMax4(hkSimdVector& self, const hkSimdVector& a, const hkSimdVector& b)
{
    self.m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline hkVector4Comparisonq compareLessThan4(const hkSimdVector& self, const hkSimdVector& a,
                                                    const hkVector4Comparisonq& mask)
{
    hkVector4Comparisonq c;
    c.m_uiMask = _mm_and_ps(_mm_cmplt_ps(self.m_vComponents, a.m_vComponents), mask.m_uiMask);
    return c;
}

__forceinline void setSelect4(hkSimdVector& self, const hkVector4Comparisonq& comp, const hkSimdVector& trueValue,
                              const hkSimdVector& falseValue)
{
    self.m_vComponents = _mm_or_ps(_mm_andnot_ps(comp.m_uiMask, falseValue.m_vComponents),
                                   _mm_and_ps(comp.m_uiMask, trueValue.m_vComponents));
}

// Clip-converts a vector and returns the magic value for reuse by the second conversion.
__forceinline LocalM128 convertToUint16WithClip(const hkSimdVector& in, const hkSimdVector& offset, const hkSimdVector& scale,
                                            const hkSimdVector& minVal, const hkSimdVector& maxVal, hkUint16x4& out)
{
    hkSimdVector x;
    setAdd4(x, in, offset);
    mul4(x, scale);
    setMin4(x, x, maxVal);
    setMax4(x, x, minVal);
    add4(x, simd(hkVector4Util_uint16Magic));
    const LocalM128 magic = hkVector4Util_uint16Magic.m_vComponents;
    hkQuadUintq u;
    u.q = x.m_vComponents;
    out.x = hkUint16(u.i[0] >> 7);
    out.y = hkUint16(u.i[1] >> 7);
    out.z = hkUint16(u.i[2] >> 7);
    out.w = hkUint16(u.i[3] >> 7);
    return magic;
}

__forceinline void convertToUint16WithClipAgain(const hkSimdVector& in, const hkSimdVector& offset, const hkSimdVector& scale,
                                              const hkSimdVector& minVal, const hkSimdVector& maxVal, const LocalM128 magic,
                                              hkUint16x4& out)
{
    hkSimdVector x;
    setAdd4(x, in, offset);
    mul4(x, scale);
    setMin4(x, x, maxVal);
    setMax4(x, x, minVal);
    x.m_vComponents = _mm_add_ps(x.m_vComponents, magic);
    hkQuadUintq u;
    u.q = x.m_vComponents;
    out.x = hkUint16(u.i[0] >> 7);
    out.y = hkUint16(u.i[1] >> 7);
    out.z = hkUint16(u.i[2] >> 7);
    out.w = hkUint16(u.i[3] >> 7);
}

// Expands aabb by the collection radius, clamps it to the height field's AABB, returns false if empty, else outputs uint16 grid min/max X and Z.
// @fnv 0x00d26940
// src: XBOX_PDB 0x00d26940
hkBool hkpTriSampledHeightFieldBvTreeShape_getExtentsForQueryAabb(const hkAabb* aabb, const hkpTriSampledHeightFieldCollection* collection, hkUint32* minX,
                     hkUint32* maxX, hkUint32* minZ, hkUint32* maxZ)
{
    // The caller's aabb is expanded and clipped in place.
    const hkpSampledHeightFieldShape* hf = collection->getHeightFieldShape();

    hkSimdVector radius;
    SetAllComponents(radius, getRadius(collection));
    add4(simd(const_cast<hkAabb*>(aabb)->m_kMaximumCorner), radius);
    sub4(simd(const_cast<hkAabb*>(aabb)->m_kMinimumCorner), radius);

    {
        hkAabb hfAabb;
        hf->CalculateAabb(hkTransform_identity, 0.0f, hfAabb);

        hkVector4Comparisonq all;
        all.m_uiMask = hkVector4Comparison_maskXYZW;
        setSelect4(simd(const_cast<hkAabb*>(aabb)->m_kMinimumCorner),
                   compareLessThan4(simd(const_cast<hkAabb*>(aabb)->m_kMinimumCorner), simd(hfAabb.m_kMinimumCorner), all),
                   simd(hfAabb.m_kMinimumCorner), simd(const_cast<hkAabb*>(aabb)->m_kMinimumCorner));
        setSelect4(simd(const_cast<hkAabb*>(aabb)->m_kMaximumCorner),
                   compareLessThan4(simd(hfAabb.m_kMaximumCorner), simd(const_cast<hkAabb*>(aabb)->m_kMaximumCorner), all),
                   simd(hfAabb.m_kMaximumCorner), simd(const_cast<hkAabb*>(aabb)->m_kMaximumCorner));
    }

    if (_mm_movemask_ps(_mm_cmple_ps(const_cast<hkAabb*>(aabb)->m_kMaximumCorner.m_vComponents,
                                     const_cast<hkAabb*>(aabb)->m_kMinimumCorner.m_vComponents)) &
        7)
    {
        hkBool result;
        result.m_cBooleanValue = 0;
        return result;
    }

    hkSimdVector zero;
    setZero4(zero);
    hkSimdVector maxVal;
    set(maxVal, hkReal(hf->m_iXResolution - 2), 0.0f, hkReal(hf->m_iZResolution - 2), 0.0f);

    hkUint16x4 out;
    const LocalM128 magic =
        convertToUint16WithClip(simd(const_cast<hkAabb*>(aabb)->m_kMinimumCorner), getFloatToIntOffsetFloorCorrected(hf),
                                getFloatToIntScale(hf), zero, maxVal, out);
    *minX = out.x;
    *minZ = out.z;

    convertToUint16WithClipAgain(simd(const_cast<hkAabb*>(aabb)->m_kMaximumCorner), getFloatToIntOffsetFloorCorrected(hf),
                                 getFloatToIntScale(hf), zero, maxVal, magic, out);
    *maxX = out.x;
    *maxZ = out.z;

    hkBool result;
    result.m_cBooleanValue = 1;
    return result;
}

__forceinline hkReal hkpSampledHeightFieldShape::getHeightAt(int x, int z) const throw()
{
    hkReal h = GetHeightAtGridPoint(x, z);
    return h * m_kHeightScaleVector.y;
}

__forceinline hkReal hkpSampledHeightFieldShape::getScaledHeight(int x, int z) const throw()
{
    hkReal h = GetHeightAtGridPoint(x, z);
    return m_kHeightScaleVector.y * h;
}


__declspec(noinline) hkBool
// src: XBOX_PDB 0x00d26940
    __cdecl hkpTriSampledHeightFieldBvTreeShape_getExtentsForQueryAabb(const hkAabb& aabb, const hkpTriSampledHeightFieldCollection* collection, hkUint32& minX,
                         hkUint32& maxX, hkUint32& minZ, hkUint32& maxZ)
{
    const hkpSampledHeightFieldShape* hf = collection->getHeightFieldShape();
    minX = (int)(aabb.m_kMinimumCorner.m_f[0] * hf->m_kHeightScaleVector.x);
    maxX = (int)(aabb.m_kMaximumCorner.m_f[0] * hf->m_kHeightScaleVector.x);
    minZ = (int)(aabb.m_kMinimumCorner.m_f[2] * hf->m_kHeightScaleVector.z);
    maxZ = (int)(aabb.m_kMaximumCorner.m_f[2] * hf->m_kHeightScaleVector.z);
    return hkBool(minX <= maxX && minZ <= maxZ);
}

typedef hkBool(__cdecl* ExtentsQueryFn)(const hkAabb&, const hkpTriSampledHeightFieldCollection*, hkUint32&,
                                              hkUint32&, hkUint32&, hkUint32&);
ExtentsQueryFn S00d26ba0_extentsFp = &hkpTriSampledHeightFieldBvTreeShape_getExtentsForQueryAabb;

struct BvTreeShape : public hkpTriSampledHeightFieldBvTreeShape
{
    hkUint32 hkpTriSampledHeightFieldBvTreeShape_queryAabbImpl(const hkAabb& aabbIn, hkpShapeKey* hits, int maxNumKeys) const;
};

// Fills hits with shape keys for grid cells overlapping aabbIn and returns the count, or 0 if bounds checking finds every sampled height above or below it.
// @fnv 0x00d26ba0
// src: HAVOK_SRC 0x00d26ba0
hkUint32 BvTreeShape::hkpTriSampledHeightFieldBvTreeShape_queryAabbImpl(const hkAabb& aabbIn, hkpShapeKey* hits, int maxNumKeys) const
{
    hkAabb aabb(aabbIn);
    const hkpTriSampledHeightFieldCollection* collection =
        static_cast<const hkpTriSampledHeightFieldCollection*>(m_kChildContainer.m_pContainedShape);

    hkUint32 maxZ, minZ, maxX, minX;
    {
        hkBool ok = hkpTriSampledHeightFieldBvTreeShape_getExtentsForQueryAabb(aabb, collection, minX, maxX, minZ, maxZ);
        if (!ok)
        {
            return 0;
        }
    }

    int numHits = 0;
    const hkpSampledHeightFieldShape* hf = collection->getHeightFieldShape();

    if (m_bCheckHeightFieldBounds)
    {
        bool allBelow = true;
        bool allAbove = true;
        int x, z;

        for (x = minX; x <= maxX; x++)
        {
            for (z = minZ; z <= maxZ; z++)
            {
                hkpShapeKey key = (x << 1) + (z << 16);
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key;
                }
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key | 1;
                }
                if (allBelow || allAbove)
                {
                    hkReal height = hf->getScaledHeight(x, z);
                    if (aabb.m_kMinimumCorner.m_f[1] < height)
                    {
                        allBelow = false;
                    }
                    if (height < aabb.m_kMaximumCorner.m_f[1])
                    {
                        allAbove = false;
                    }
                }
            }
        }

        if (allBelow || allAbove)
        {
            for (x = minX; x <= maxX + 1; x++)
            {
                hkReal height = hf->getHeightAt(x, maxZ + 1);
                if (aabb.m_kMinimumCorner.m_f[1] < height)
                {
                    allBelow = false;
                }
                if (height < aabb.m_kMaximumCorner.m_f[1])
                {
                    allAbove = false;
                }
            }
            for (z = minZ; z <= maxZ + 1; z++)
            {
                hkReal height = hf->getHeightAt(maxX + 1, z);
                if (aabb.m_kMinimumCorner.m_f[1] < height)
                {
                    allBelow = false;
                }
                if (height < aabb.m_kMaximumCorner.m_f[1])
                {
                    allAbove = false;
                }
            }
            if (allBelow || allAbove)
            {
                return 0;
            }
        }
    }
    else
    {
        for (int x = minX; x <= maxX; x++)
        {
            for (int z = minZ; z <= maxZ; z++)
            {
                hkpShapeKey key = (x << 1) + (z << 16);
                if (numHits < maxNumKeys)
                {
                    hits[numHits++] = key;
                    if (numHits < maxNumKeys)
                    {
                        hits[numHits++] = key | 1;
                    }
                }
            }
        }
    }
    return numHits;
}
