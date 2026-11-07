#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Preserve the float-only SIMD type used by the original /GS build.
#define _INCLUDED_MM2
// Exe 0x00d73590 FUN_00d73590: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);

extern "C" LocalM128 _mm_setzero_ps();

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpConvexTransformShape.h"
#include "../../../../../../../include/hkpConvexTransformShapeBase.h"
#include "../../../../../../../include/hkpConvexTranslateShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpListShape.h"
#include "../../../../../../../include/hkpListShapeChildInfo.h"
#include "../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../include/hkpTransformShape.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkReferencedObject.h"

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

// Resets the three fields, forwards each ref's value at offset 0x10 to FUN_00d738f0, then calls FUN_00d74a20 and returns this.
// @fnv 0x00d74b20
// src: HAVOK_LIB 0x00d74b20
ShapeData* ShapeData::_SharedShapeData__SharedShapeData(ShapeRefArray* refs)
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0x80000000;
    for (int i = 0; i < refs->count; ++i)
        _SharedShapeData_recursivelyParseShapeReferences(*(int*)(refs->refs[i] + 0x10));
    _SharedShapeData_removeSingleReferencedShapeData();
    return this;
}

struct FUN_00d74980_Class
{
    int* refs;
    int count;
    int FindMappedValue(int value);
};

// Scans the refs array in groups of three and returns the third entry of the first group whose first or second entry equals value, otherwise 0.
// @fnv 0x00d74980
int FUN_00d74980_Class::FindMappedValue(int value)
{
    for (int i = 0; i < count; ++i)
    {
        if (refs[i * 3] == value || refs[i * 3 + 1] == value)
            return refs[i * 3 + 2];
    }

    return 0;
}

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

// @fnv 0x00d74420
int RunContextOperation(int aiArg1, int aiArg2, int aiArg3, int* piOut)
{
    FUN_00d74420_Context ctx;
    ctx.m_kPointA = 0;
    ctx.m_kPointB = 0;
    ctx.m_iThirdValue = 0x80000000;
    ctx._SharedShapeData_recursivelyParseShapeReferences(aiArg1);
    ctx._SharedShapeData_removeSingleReferencedShapeData();
    *piOut = hkpShape_ProcessEntries_00d739f0(aiArg1, aiArg2, &ctx, aiArg3);
    ctx.ProcessEntries_00d74aa0();
    return 0;
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyD748(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

// Array allocation bodies are unit-defined, as required by the shared hkArray declarations.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}

template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    constructWithCopyD748(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}

class hkpEntity;

int __cdecl RemapCollisionShapes(hkArray<hkpEntity*>& kEntities, int iA, int iB) throw();

// Appends pkEntity to a local hkArray and forwards it with iA and iB to RemapCollisionShapes, returning its result.
// @fnv 0x00d748d0
// src: GUESS 0x00d748d0 (confidence: high)
int __cdecl hkpEntity_RemapSingleEntityCollisionShapes(hkpEntity* pkEntity, int iA, int iB) throw()
{
    hkArray<hkpEntity*> kEntities;
    kEntities.pushBack(pkEntity);
    return RemapCollisionShapes(kEntities, iA, iB);
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

// Scans the table for an entry matching key in either key field, releases the old value, stores the new value, and returns 0 on success or 1 if not found.
// @fnv 0x00d749c0
int D749Table::SetEntryValue(int key, int value)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            if (m_data[i].m_key0 == key || m_data[i].m_uiFilterValue == key)
                goto found;
            ++i;
        } while (i < m_uiItemCount);
    }
    return 1;
found:
    ((hkReferencedObject*)value)->addReference();
    int pOldValue = m_data[i].m_uiFilterValue;
    if (pOldValue)
        ((hkReferencedObject*)pOldValue)->removeReference();
    m_data[i].m_uiFilterValue = value;
    return 0;
}

extern const LocalM128 g_hkQuadXYZMask;
extern int DAT_010d0e5c;
// Inline implementations retain this unit's original code generation.
__forceinline float& hkVector4::operator()(int i) { return m_vComponents.m128_f32[i]; }
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline void hkVector4::setXYZ0(const hkVector4& v) { m_vComponents = _mm_and_ps(v.m_vComponents, g_hkQuadXYZMask); }
__forceinline hkRotation::hkRotation() {}
__forceinline void hkRotation::setIdentity()
{
    hkVector4 zero;
    zero.setZero4();
    m_kColumn0 = zero;
    m_kColumn0(0) = 1.0f;
    m_kColumn1 = zero;
    m_kColumn1(1) = 1.0f;
    m_kColumn2 = zero;
    m_kColumn2(2) = 1.0f;
}
__forceinline hkTransform::hkTransform() {}
__forceinline const hkTransform& hkTransform::GetIdentityTransform() { return s_identity; }
__forceinline hkRotation& hkTransform::getRotation() { return reinterpret_cast<hkRotation&>(m_row0); }
__forceinline const hkRotation& hkTransform::getRotation() const { return reinterpret_cast<const hkRotation&>(m_row0); }
__forceinline void hkTransform::setTranslation(const hkVector4& t) { m_row3 = t.m_vComponents; }
__forceinline hkpShapeType hkpShape::getType() const { return reinterpret_cast<const hkpShapeType&>(m_type); }
__forceinline const hkpShape* hkpTransformShape::GetShapeForKey() const { return m_pContainedShape.getChild(); }
__forceinline const hkTransform& hkpTransformShape::getTransform() const { return m_kMotionTransform; }
__forceinline const hkpConvexShape* hkpConvexTransformShapeBase::GetShapeForKey() const
{ return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild()); }
__forceinline const hkpConvexShape* hkpConvexTransformShape::GetShapeForKey() const
{ return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild()); }
__forceinline const hkpConvexShape* hkpConvexTranslateShape::GetShapeForKey() const
{ return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild()); }

// Typed adapters for the original pointer-returning constructor entry points.
// These allow construction without duplicating the shared abstract classes.
extern "C" void FUN_00cf5990();
extern "C" void hkpConvexTransformShape_hkpConvexTransformShape();
extern "C" void FUN_00c9e340();
__forceinline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}
__forceinline hkpConvexTranslateShape* hkpConvexTranslateShape::init(const hkpConvexShape* child, const hkVector4& translation)
{
    reinterpret_cast<void(__thiscall*)(hkpConvexTransformShapeBase*, int, float, const hkpConvexShape*, int)>(FUN_00c9e340)(this, HK_SHAPE_CONVEX_TRANSLATE, child->getRadius(), child, 1);
    *reinterpret_cast<void**>(this) = &DAT_010d0e5c;
    m_vTranslation.setXYZ0(translation);
    m_iChildShapeSize = 0;
    return this;
}

struct CacheEnt_d74480
{
    hkpShape* source;
    hkpShape* replacement;
    int unk08;
};
struct Cache_d74480
{
    CacheEnt_d74480* data;
    int count;
    int capacity;
    void SetEntryValue(hkpShape* source, hkpShape* replacement);
};
extern LocalM128 DAT_010c4c10;
struct Arr_d74480
{
    hkpShape** data;
    int size;
    int capacity;
};
hkpShape* __cdecl hkpShape_ProcessEntries_00d739f0(hkpShape*, void*, Cache_d74480*, void*);

// Recursively processes a shape tree, replacing nodes with cached or newly allocated equivalents and storing results in the cache.
// @fnv 0x00d74480
hkpShape* __cdecl ProcessShape(hkpShape* shape, void* context, Cache_d74480* cache, void* settings)
{
    for (int i = 0; i < cache->count; ++i)
    {
        if (cache->data[i].source == shape)
        {
            hkpShape* found = cache->data[i].replacement;
            if (found)
            {
                found->addReference();
                return found;
            }
            break;
        }
    }
    hkpShape* result;
    switch (shape->getType())
    {
    case 9: {
        hkpListShape* list = static_cast<hkpListShape*>(shape);
        int count = static_cast<hkpShapeContainer&>(*list).GetNumChildShapes();
        Arr_d74480 childShapes;
        childShapes.data = 0;
        childShapes.size = 0;
        childShapes.capacity = 0x80000000;
        bool bUnchanged = true;
        for (int i = 0; i < count; ++i)
        {
            hkpShape* pChild = const_cast<hkpShape*>(list->m_kChildInfoList.m_data[i].m_pCollisionShape);
            hkpShape* n = ProcessShape(pChild, context, cache, settings);
            hkMemoryRouter* pRouter = &hkMemoryRouter::getInstance();
            if (childShapes.size == (childShapes.capacity & 0x3fffffff))
                ResizeAudioStream(&pRouter->heap(), &childShapes, 4);
            childShapes.data[childShapes.size++] = n;
            if (n != pChild)
                bUnchanged = false;
        }
        if (bUnchanged)
        {
            for (int i = 0; i < count; ++i)
                childShapes.data[i]->removeReference();
            shape->addReference();
            hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
            childShapes.size = 0;
            if ((childShapes.capacity & 0x80000000) == 0)
                a.bufFree(childShapes.data, (childShapes.capacity & 0x3fffffff) * 4);
            result = shape;
            break;
        }
        hkpShape* v = (hkpShape*)hkMemoryRouter::getInstance().heap().blockAlloc(0x70);
        v->m_usMemSizeAndFlags = 0x70;
        v = reinterpret_cast<hkpListShape*>(v)->FUN_00cf5640(childShapes.data, count, 1);
        for (int i = 0; i < count; ++i)
            childShapes.data[i]->removeReference();
        cache->SetEntryValue(shape, v);
        result = v;
        hkMemoryAllocator& a = hkMemoryRouter::getInstance().heap();
        childShapes.size = 0;
        if ((childShapes.capacity & 0x80000000) == 0)
            a.bufFree(childShapes.data, (childShapes.capacity & 0x3fffffff) * 4);
        break;
    }
    case 15: {
        hkpTransformShape* xf = static_cast<hkpTransformShape*>(shape);
        hkpShape* pChild = const_cast<hkpShape*>(xf->m_pContainedShape.getChild());
        hkpShape* v = ProcessShape(pChild, context, cache, settings);
        hkpShape* n = v;
        if (pChild == v)
        {
            v->removeReference();
            v = shape;
            shape->addReference();
        }
        else
        {
            hkpShape* mem = (hkpShape*)hkMemoryRouter::getInstance().heap().blockAlloc(0x70);
            mem->m_usMemSizeAndFlags = 0x70;
            v = reinterpret_cast<hkpTransformShape*(__thiscall*)(hkpTransformShape*, const hkpShape*, const hkTransform&)>(FUN_00cf5990)(static_cast<hkpTransformShape*>(mem), n, xf->m_kMotionTransform);
            n->removeReference();
            cache->SetEntryValue(shape, v);
        }
        result = hkpShape_ProcessEntries_00d739f0(v, context, cache, settings);
        v->removeReference();
        break;
    }
    case 12: {
        hkpConvexTransformShapeBase* cv = static_cast<hkpConvexTransformShapeBase*>(shape);
        hkpShape* pChild = const_cast<hkpShape*>(cv->m_pContainedShape.getChild());
        hkpShape* v = ProcessShape(pChild, context, cache, settings);
        hkpShape* n = v;
        if (pChild == v)
        {
            v->removeReference();
            v = shape;
            shape->addReference();
        }
        else
        {
            hkpShape* mem = (hkpShape*)hkMemoryRouter::getInstance().heap().blockAlloc(0x60);
            mem->m_usMemSizeAndFlags = 0x60;
            v = reinterpret_cast<hkpConvexTransformShape*(__thiscall*)(hkpConvexTransformShape*, const hkpConvexShape*, const hkTransform&, int)>(hkpConvexTransformShape_hkpConvexTransformShape)(static_cast<hkpConvexTransformShape*>(mem), static_cast<hkpConvexShape*>(n), static_cast<hkpConvexTransformShape*>(cv)->m_kMotionTransform, 1);
            n->removeReference();
            cache->SetEntryValue(shape, v);
        }
        result = hkpShape_ProcessEntries_00d739f0(v, context, cache, settings);
        v->removeReference();
        break;
    }
    case 11: {
        hkpConvexTransformShapeBase* cv = static_cast<hkpConvexTransformShapeBase*>(shape);
        hkpShape* v;
        hkpShape* pChild = const_cast<hkpShape*>(cv->m_pContainedShape.getChild());
        hkpShape* n = ProcessShape(pChild, context, cache, settings);
        if (pChild == n)
        {
            n->removeReference();
            v = shape;
            shape->addReference();
        }
        else
        {
            hkpConvexTranslateShape* pNewConvex = (hkpConvexTranslateShape*)hkMemoryRouter::getInstance().heap().blockAlloc(0x30);
            pNewConvex->m_usMemSizeAndFlags = 0x30;
            reinterpret_cast<void(__thiscall*)(hkpConvexTransformShapeBase*, int, float, const hkpConvexShape*, int)>(FUN_00c9e340)(pNewConvex, 11, static_cast<hkpConvexShape*>(n)->m_fSphereRadius, static_cast<hkpConvexShape*>(n), 1);
            *reinterpret_cast<void**>(pNewConvex) = &DAT_010d0e5c;
            pNewConvex->m_vTranslation.m_vComponents = _mm_and_ps(static_cast<hkpConvexTranslateShape*>(cv)->m_vTranslation.m_vComponents, DAT_010c4c10);
            pNewConvex->m_iChildShapeSize = 0;
            v = pNewConvex;
            n->removeReference();
            cache->SetEntryValue(shape, v);
        }
        result = hkpShape_ProcessEntries_00d739f0(v, context, cache, settings);
        v->removeReference();
        break;
    }
    default:
        shape->addReference();
        result = shape;
        break;
    }
    return result;
}

struct hkShapeEntryD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkReferencedObject* m_pCollisionShape;
};

struct hkShapeEntryArrayD748
{
    hkShapeEntryD748** m_data;
    int m_iElementCount;
};

struct hkShapeOutputD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void UpdateFields_00d73400() throw();
};

struct hkShapeMapD748
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkShapeMapD748* _SharedShapeData__SharedShapeData(hkShapeEntryArrayD748* refs) throw();
    void ProcessEntries_00d74aa0() throw();
};

hkReferencedObject* __cdecl ProcessShape(hkReferencedObject* shape, void* context, hkShapeMapD748* map,
                                         hkShapeOutputD748* out) throw();

// Remaps each collision shape in refs via ProcessShape, storing results back into the entries and releasing the old references.
// @fnv 0x00d74850
int __cdecl RemapCollisionShapes(hkShapeEntryArrayD748* refs, void* context, hkShapeOutputD748* out)
{
    out->UpdateFields_00d73400();
    hkShapeMapD748 map;
    map._SharedShapeData__SharedShapeData(refs);
    for (int i = 0; i < refs->m_iElementCount; i++)
    {
        hkShapeEntryD748* entry = refs->m_data[i];
        hkReferencedObject* shape = entry->m_pCollisionShape;
        hkReferencedObject* pRemappedShape = ProcessShape(shape, context, &map, out);
        shape->removeReference();
        entry->m_pCollisionShape = pRemappedShape;
    }
    map.ProcessEntries_00d74aa0();
    return 0;
}

template <class T> static __forceinline void PushBackD737(hkArray<T>* a, const T& t)
{
    hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
    if (a->m_iElementCount == a->getCapacity())
        ResizeAudioStream(&kAlloc, a, sizeof(T));
    constructWithCopyD748(a->m_data + a->m_iElementCount, 1, t);
    a->m_iElementCount++;
}

// Appends the child shapes of a shape to out: every list child for type 9, or the single child pointer for types 15, 12 and 11.
// @fnv 0x00d737d0
// src: GUESS 0x00d737d0 (confidence: high)
static __declspec(noinline) void hkpShape_AppendChildShapesByType(const hkpShape* shape, hkArray<const hkpShape*>* out)
{
    switch (shape->getType())
    {
    case 9: {
        const hkpListShape* list = static_cast<const hkpListShape*>(shape);
        const hkpShapeContainer& container = *list;
        int i = 0;
        if (container.GetNumChildShapes() > 0)
        {
            do
            {
                const hkpShape* child = list->m_kChildInfoList.m_data[i].m_pCollisionShape;
                PushBackD737(out, child);
                ++i;
            } while (i < container.GetNumChildShapes());
        }
    }
    break;
    case 15: {
        const hkpShape* child = static_cast<const hkpTransformShape*>(shape)->m_pContainedShape.getChild();
        PushBackD737(out, child);
    }
    break;
    case 12: {
        const hkpShape* child = static_cast<const hkpConvexTransformShapeBase*>(shape)->m_pContainedShape.getChild();
        PushBackD737(out, child);
    }
    break;
    case 11: {
        const hkpShape* child = static_cast<const hkpConvexTransformShapeBase*>(shape)->m_pContainedShape.getChild();
        PushBackD737(out, child);
    }
    break;
    }
}

void zz_probe_d737d0(const hkpShape* shape, hkArray<const hkpShape*>* out)
{
    hkpShape_AppendChildShapesByType(shape, out);
}

struct D74A20Entry
{
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    int m_uiItemCount;
};

struct D74A20Array
{
    D74A20Entry* m_data;
    int m_iElementCount;
};

// @fnv 0x00d74a20
// src: HAVOK_LIB 0x00d74a20
void ShapeData::_SharedShapeData_removeSingleReferencedShapeData()
{
    D74A20Array* array = reinterpret_cast<D74A20Array*>(this);

    int index = array->m_iElementCount - 1;
    if (index < 0)
        return;

    while (index >= 0)
    {
        if (array->m_data[index].m_uiItemCount < 2)
        {
            if (array->m_data[index].m_kPointA != 0)
                array->m_data[index].m_kPointA->removeReference();

            if (array->m_data[index].m_kPointB != 0)
                array->m_data[index].m_kPointB->removeReference();

            for (int once = 0; once < 1; once++)
            {
                array->m_iElementCount--;
                int n = array->m_iElementCount;
                if (n != index)
                {
                    char* d = reinterpret_cast<char*>(array->m_data);
                    char* src = d + n * 12;
                    d += index * 12;
                    int* dst = reinterpret_cast<int*>(d);
                    int delta = (int)(src - d);
                    int count = 3;
                    do
                    {
                        *dst = *reinterpret_cast<int*>(reinterpret_cast<char*>(dst) + delta);
                        dst++;
                    } while (--count != 0);
                }
            }
        }

        index--;
    }
}

// Applies a transform to a shape, collapsing identity results to the child shape or creating a new transform/convex shape wrapper.
// @fnv 0x00d73590
// src: GUESS 0x00d73590 (confidence: medium)
const hkpShape* __cdecl hkpShape_CreateTransformedShape(const hkpShape* shape, const hkTransform& transform) throw()
{
    bool identity = transform.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f);
    const hkpShape* retainedShape = shape;
    if (identity)
    {
retainShape:
        retainedShape->addReference();
        return retainedShape;
    }

    switch (shape->getType())
    {
    case HK_SHAPE_TRANSFORM: {
        const hkpTransformShape* pTransformShape = static_cast<const hkpTransformShape*>(shape);
        hkTransform combined;
        combined.SetProduct(transform, pTransformShape->getTransform());
        if (combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
        {
            retainedShape = pTransformShape->GetShapeForKey();
            goto retainShape;
        }
        hkpTransformShape* p = static_cast<hkpTransformShape*>(hkReferencedObject::operator new(sizeof(hkpTransformShape)));
        return reinterpret_cast<hkpTransformShape*(__thiscall*)(hkpTransformShape*, const hkpShape*, const hkTransform&)>(FUN_00cf5990)(p, pTransformShape->GetShapeForKey(), combined);
    }
    case HK_SHAPE_CONVEX_TRANSFORM: {
        const hkpConvexTransformShape* cts = static_cast<const hkpConvexTransformShape*>(shape);
        hkTransform combined;
        combined.SetProduct(transform, cts->getTransform());
        if (combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
        {
            const hkpShape* child = cts->GetShapeForKey();
            child->addReference();
            return child;
        }
        hkpConvexTransformShape* p = static_cast<hkpConvexTransformShape*>(hkReferencedObject::operator new(sizeof(hkpConvexTransformShape)));
        return reinterpret_cast<hkpConvexTransformShape*(__thiscall*)(hkpConvexTransformShape*, const hkpConvexShape*, const hkTransform&, int)>(hkpConvexTransformShape_hkpConvexTransformShape)(p, cts->GetShapeForKey(), combined, 1);
    }
    case HK_SHAPE_CONVEX_TRANSLATE: {
        if (transform.getRotation().IsEqualWithinTolerance(hkTransform::GetIdentityTransform().getRotation(), 0.001f))
        {
            const hkpConvexTranslateShape* cts = static_cast<const hkpConvexTranslateShape*>(shape);
            hkTransform local;
            local.getRotation().setIdentity();
            local.setTranslation(cts->getTranslation());
            hkTransform combined;
            combined.SetProduct(transform, local);
            if (combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
            {
                const hkpShape* child = cts->GetShapeForKey();
                child->addReference();
                return child;
            }
            hkpConvexTranslateShape* p = static_cast<hkpConvexTranslateShape*>(hkReferencedObject::operator new(sizeof(hkpConvexTranslateShape)));
            return p->init(cts->GetShapeForKey(), cts->getTranslation());
        }
        break;
    }
    }

    hkpTransformShape* p = static_cast<hkpTransformShape*>(hkReferencedObject::operator new(sizeof(hkpTransformShape)));
    return reinterpret_cast<hkpTransformShape*(__thiscall*)(hkpTransformShape*, const hkpShape*, const hkTransform&)>(FUN_00cf5990)(p, shape, transform);
}

struct RefPairD74
{
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    int m_iThirdValue;
};
class RefPairListD74
{
  public:
    hkArray<RefPairD74> m_pairs;
    void ProcessEntries_00d74aa0();
};
// Removes references from all pairs in m_pairs and then clears and releases the underlying array storage.
// @fnv 0x00d74aa0
// src: GUESS 0x00d74aa0 (confidence: low)
void RefPairListD74::ProcessEntries_00d74aa0()
{
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_kPointA)
            m_pairs.m_data[i].m_kPointA->removeReference();
        if (m_pairs.m_data[i].m_kPointB)
            m_pairs.m_data[i].m_kPointB->removeReference();
    }
    m_pairs.clearAndDeallocate();
}
