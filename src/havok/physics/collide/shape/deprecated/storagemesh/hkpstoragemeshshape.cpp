
// src/havok/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"  // Shared Havok memory router; FUN_00c85750 returns this layout.
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../include/hkpShapeContainer.h"

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();


__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}

// Allocator-backed hkArray bodies are unit-defined, as declared in hkArray.h.
template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int n)
{
    bufFree(p, n * sizeof(T));
}

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    _clearAndDeallocate(A().get(this));
}

template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray& a)
{
    hkMemoryAllocator& kHeap = hkMemoryRouter_getInstance().heap();
    if (getCapacity() < a.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap.bufFree(m_data, getCapacity() * sizeof(T));
        int iNumBytes = a.m_iElementCount * sizeof(T);
        m_data = static_cast<T*>(kHeap.bufAlloc(iNumBytes));
        m_iCapacityState = iNumBytes / static_cast<int>(sizeof(T));
    }
    m_iElementCount = a.m_iElementCount;
    copy(m_data, a.m_data, m_iElementCount);
    return *this;
}

typedef float hkReal;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hkUint32;
typedef unsigned char hkUint8;

// Preserve the inline base construction and destruction used by this unit.
inline hkpShapeContainer::~hkpShapeContainer() {}

struct hkpMeshShapeSubpartD4B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
};

class FUN_00dcd310 : public hkpShapeCollection
{
  public:
    FUN_00dcd310(float fRadius, int iNumBitsForSubpartIndex) throw();

    int unk18;
    int unk1C;
    hkVector4 m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArray<hkpMeshShapeSubpartD4B> m_kSubparts;
    hkArray<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
    int unk54;
    int unk58;
    int unk5C;

    void hkpStorageMeshShape_addSubpart(const hkpMeshShapeSubpartD4B& kSubpart) throw();
};

class FUN_00d4bab0 : public FUN_00dcd310
{
  public:
    FUN_00d4bab0(const FUN_00dcd310& kOther) throw();
    virtual ~FUN_00d4bab0() throw();

    hkArray<int> m_60;
};

// @fnv 0x00d4bab0
FUN_00d4bab0::FUN_00d4bab0(const FUN_00dcd310& kOther) throw()
    : FUN_00dcd310(kOther.m_fSphereRadius, kOther.m_iNumBitsForSubpartIndex)
{
    m_kScaling = kOther.m_kScaling;
    m_ulUserData = kOther.m_ulUserData;
    m_bDisableWelding.m_cBooleanValue = kOther.m_bDisableWelding.m_cBooleanValue;
    for (int i = 0; i < kOther.m_kSubparts.GetLogicalSize(); i++)
        hkpStorageMeshShape_addSubpart(kOther.m_kSubparts[i]);
    m_kWeldingInfo = kOther.m_kWeldingInfo;
    m_eWeldingType = kOther.m_eWeldingType;
}

namespace fnv_00d4bc00 {

class FUN_00d4bc00 : public hkReferencedObject
{
  public:
    hkArray<hkReal> m_kVertices;
    hkArray<hkUint16> m_kIndices16;
    hkArray<hkUint32> m_kIndices32;
    hkArray<hkUint8> m_kMaterialIndices8;
    hkArray<hkUint32> m_kMaterials;
    hkArray<hkUint16> m_kMaterialIndices16;

    virtual ~FUN_00d4bc00() throw();
};

// Destructor that releases the six hkArray members of the object via their own destructors.
// @fnv 0x00d4bc00
FUN_00d4bc00::~FUN_00d4bc00() throw()
{}
}  // namespace fnv_00d4bc00

namespace fnv_00d4bd30 {

class FUN_00d4bc00 : public hkReferencedObject
{
  public:
    virtual ~FUN_00d4bc00() throw();

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().blockFree(p, static_cast<FUN_00d4bc00*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d4bc00* DestroyAndFree(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object through operator delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00d4bd30
FUN_00d4bc00* FUN_00d4bc00::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->FUN_00d4bc00::~FUN_00d4bc00();
    if (uiFlags & 1)
        FUN_00d4bc00::operator delete(this);
    return this;
}
}  // namespace fnv_00d4bd30

namespace fnv_00d4be00 {

struct FUN_00d4b400_Obj
{
    void FUN_00d4b400();
};

class FUN_00d4be00_cls : public FUN_00d4bab0
{
  public:
    FUN_00d4be00_cls* FUN_00d4be00(int flags);
};

// @fnv 0x00d4be00
FUN_00d4be00_cls* FUN_00d4be00_cls::FUN_00d4be00(int flags)
{
    ((FUN_00d4b400_Obj*)this)->FUN_00d4b400();
    if (flags & 1)
    {
        hkMemoryRouter* mem = &hkMemoryRouter_getInstance();
        hkMemoryAllocator* alloc = mem->m_heap;
        alloc->blockFree(this, m_usMemSizeAndFlags);
    }
    return this;
}
}  // namespace fnv_00d4be00

class FUN_00d4bd60 : public hkpShapeCollection
{
  public:
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;

    virtual ~FUN_00d4bd60() throw();
};

class FUN_00d4b400 : public FUN_00d4bd60
{
  public:
    hkArray<hkReferencedObject*> m_children;

    virtual ~FUN_00d4b400() throw();
    virtual void V0() throw();
};

// Destructor that calls FUN_00c905b0 on each element of m_children.
// @fnv 0x00d4b400
FUN_00d4b400::~FUN_00d4b400() throw()
{
    for (int i = 0; i < m_children.GetLogicalSize(); i++)
    {
        m_children.m_data[i]->removeReference();
    }
}

class FUN_00d4bbb0 : public hkReferencedObject
{
  public:
    hkArray<int> m_array08;
    hkArray<int> m_array14;
    hkArray<int> m_array20;
    hkArray<int> m_array2C;
    hkArray<int> m_array38;
    hkArray<int> m_array44;

    FUN_00d4bbb0();
    virtual ~FUN_00d4bbb0();
};

// Default constructor for FUN_00d4bbb0 that leaves the inherited hkReferencedObject and the six hkArray<int> members at their default-initialized state.
// @fnv 0x00d4bbb0
FUN_00d4bbb0::FUN_00d4bbb0()
{}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual inherited through a second base.
struct Derived : hkpShape, hkpShapeContainer
{
    Derived();
// @fnv 0x00d4bdf0
    virtual void vf06();
};

Derived::Derived() : hkpShape(HK_SHAPE_INVALID)
{}

void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);
void __cdecl hkArrayUtil__reserve(void* heap, void* arr, int newCap, int elemSize);
extern float DAT_01267e30;
struct SubpartFlags480
{
    int vertices, stride, numVertices, indices;
    unsigned char indexType, materialIndexType;
    unsigned short flags;
};

// src: HAVOK_LIB 0x00d4b390
static __declspec(noinline) int __cdecl storageMeshShape_numIndices(int a, int n)
{
    switch (a)
    {
    case 1:
        return n + 2;
    case 2:
        return 2 * n + 1;
    default:
        return 3 * n;
    }
}

template <class T> __forceinline void hkArrayUtil::construct(T*, int, hkTypeIsPod)
{}

template <class T> __forceinline void hkArrayUtil::constructWithCopy(T* dest, int count, const T& value, hkTypeIsPod)
{
    for (int j = 0; j < count; ++j)
        dest[j] = value;
}

template <class T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& heap, int needed)
{
    int capacity = getCapacity();
    if (capacity < needed)
    {
        int doubled = 2 * capacity;
        int result = needed < doubled ? doubled : needed;
        hkArrayUtil__reserve(&heap, this, result, sizeof(T));
    }
}

template <class T> __forceinline T* hkArrayBase<T>::_expandBy(hkMemoryAllocator& heap, int count)
{
    int oldSize = m_iElementCount;
    GrowArrayCapacity(heap, m_iElementCount + count);
    hkArrayUtil::construct(m_data + m_iElementCount, count, hkTypeIsPod());
    m_iElementCount += count;
    return m_data + oldSize;
}

template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& heap, const T& value)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&heap, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, value, hkTypeIsPod());
    m_iElementCount++;
}

template <class Arr> __forceinline void GrowIfFull480(Arr& arr, int elemSize)
{
    hkMemoryRouter& router = hkMemoryRouter_getInstance();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router.m_heap, &arr, elemSize);
}
__forceinline hkpMeshShapeSubpartD4B* ExpandInit480(hkArray<hkpMeshShapeSubpartD4B>& arr)
{
    GrowIfFull480(arr, 0x38);
    hkpMeshShapeSubpartD4B* e = &arr.m_data[arr.m_iElementCount];
    if (e)
    {
        ((SubpartFlags480*)e)->materialIndexType = 1;
        e->unk24 = 0;
        e->unk2C = 0;
        e->unk30 = 1;
        e->unk28 = 0;
        e->unk20 = 0;
        e->unk34 = -1;
        e->unk18 = 0;
    }
    return &arr.m_data[arr.m_iElementCount++];
}

struct Storage480 : hkReferencedObject
{
    hkArray<float> verts;
    hkArray<unsigned short> idx16;
    hkArray<int> idx32;
    hkArray<unsigned char> mat8;
    hkArray<int> extra;
    hkArray<unsigned short> mat16;
    Storage480* FUN_00d4bbb0();
};

// Copies a mesh subpart's vertex, index, material, and extra data into owned storage arrays and updates the subpart's pointers and strides.
// @fnv 0x00d4b480
// src: HAVOK_LIB 0x00d4b480
void FUN_00dcd310::hkpStorageMeshShape_addSubpart(const hkpMeshShapeSubpartD4B& kSubpart) throw()
{
    hkpMeshShapeSubpartD4B* pSubpart = ExpandInit480(m_kSubparts);

    Storage480* storage = (Storage480*)hkMemoryRouter_getInstance().heap().blockAlloc(0x50);
    storage->m_usMemSizeAndFlags = 0x50;
    storage = storage->FUN_00d4bbb0();

    hkArray<Storage480*>& arr60 = (hkArray<Storage480*>&)static_cast<FUN_00d4bab0*>(this)->m_60;
    arr60.pushBack(storage);
    storage = arr60.m_data[arr60.m_iElementCount - 1];
    int numFloats = kSubpart.unk08 * 3;

    {
        hkArray<float>& verts = storage->verts;
        float* dst = verts.expandBy(numFloats);
        const float* src = (const float*)kSubpart.unk00;
        for (int i = 0; i < kSubpart.unk08; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst += 3;
            src = (const float*)((const char*)src + kSubpart.unk04);
        }
        pSubpart->unk00 = (int)verts.m_data;
        pSubpart->unk04 = 12;
        pSubpart->unk08 = kSubpart.unk08;
    }

    int idxDst;
    if (((const SubpartFlags480*)&kSubpart)->indexType == 1)
    {
        int a = (int)((unsigned int)kSubpart.unk14 >> 1);
        int iClamped = a;
        if (iClamped > 2)
            iClamped = 3;
        pSubpart->unk14 = iClamped + iClamped;
        int numIndices = storageMeshShape_numIndices(a, kSubpart.unk1C);
        hkArray<unsigned short>& arr = storage->idx16;
        unsigned short* dst = arr.expandBy(numIndices);
        idxDst = (int)dst;
        const unsigned short* src = (const unsigned short*)kSubpart.unk0C;
        for (int i = 0; i < kSubpart.unk1C; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = (unsigned short*)((char*)dst + pSubpart->unk14);
            src = (const unsigned short*)((const char*)src + kSubpart.unk14);
        }
    }
    else
    {
        int a = (int)((unsigned int)kSubpart.unk14 >> 2);
        int iClamped = a;
        if (iClamped > 2)
            iClamped = 3;
        pSubpart->unk14 = (iClamped << 2);
        int numIndices = storageMeshShape_numIndices(a, kSubpart.unk1C);
        hkArray<int>& arr = storage->idx32;
        int* dst = arr.expandBy(numIndices);
        idxDst = (int)dst;
        const int* src = (const int*)kSubpart.unk0C;
        for (int i = 0; i < kSubpart.unk1C; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = (int*)((char*)dst + pSubpart->unk14);
            src = (const int*)((const char*)src + kSubpart.unk14);
        }
    }

    ((SubpartFlags480*)pSubpart)->indexType = ((const SubpartFlags480*)&kSubpart)->indexType;
    pSubpart->unk1C = kSubpart.unk1C;
    pSubpart->unk18 = kSubpart.unk18;
    pSubpart->unk0C = idxDst;
    ((SubpartFlags480*)pSubpart)->materialIndexType = ((const SubpartFlags480*)&kSubpart)->materialIndexType;

    const void* materialIndices = (const void*)kSubpart.unk20;
    if (materialIndices != 0)
    {
        if (((const SubpartFlags480*)&kSubpart)->materialIndexType == 1)
        {

            if (kSubpart.unk24 == 0)
            {
                storage->mat8.pushBack(*(const unsigned char*)materialIndices);
                pSubpart->unk20 = (int)&storage->mat8.back();
            }
            else
            {
                unsigned char* dst = storage->mat8.expandBy(kSubpart.unk1C);
                pSubpart->unk20 = (int)dst;
                const unsigned char* src = (const unsigned char*)kSubpart.unk20;
                for (int i = 0; i < kSubpart.unk1C; i++)
                {
                    dst[i] = src[0];
                    src += kSubpart.unk24;
                }
            }
        }
        else
        {
            hkArray<unsigned short>& arr = storage->mat16;
            if (kSubpart.unk24 == 0)
            {
                arr.pushBack(*(const unsigned short*)materialIndices);
                pSubpart->unk20 = (int)(arr.m_data + arr.m_iElementCount - 1);
            }
            else
            {
                unsigned short* dst = arr.expandBy(kSubpart.unk1C);
                pSubpart->unk20 = (int)dst;
                const unsigned short* src = (const unsigned short*)kSubpart.unk20;
                for (int i = 0; i < kSubpart.unk1C; i++)
                {
                    dst[i] = src[0];
                    src = (const unsigned short*)((const char*)src + kSubpart.unk24);
                }
            }
        }
        int matStride = kSubpart.unk24;
        pSubpart->unk24 = matStride;
        if (matStride != 0)
        {
            switch ((signed char)((SubpartFlags480*)pSubpart)->materialIndexType)
            {
            case 1:
                pSubpart->unk24 = 1;
                break;
            case 2:
                pSubpart->unk24 = 2;
                break;
            }
        }
    }
    else
    {
        pSubpart->unk20 = 0;
        pSubpart->unk24 = 0;
    }

    if (pSubpart->unk20 != 0)
    {
        hkArray<int>& arr = storage->extra;
        if (kSubpart.unk2C == 0)
        {
            const int* pExtraSrc = (const int*)kSubpart.unk28;
            arr.pushBack(*pExtraSrc);
            pSubpart->unk2C = 0;
            pSubpart->unk30 = 1;
        }
        else
        {
            int* dst = arr.expandBy(kSubpart.unk30);
            const int* pExtraSrc = (const int*)kSubpart.unk28;
            for (int i = 0; i < kSubpart.unk30; i++)
            {
                dst[i] = pExtraSrc[0];
                pExtraSrc = (const int*)((const char*)pExtraSrc + kSubpart.unk2C);
            }
            pSubpart->unk2C = 4;
            pSubpart->unk30 = kSubpart.unk30;
        }
        pSubpart->unk28 = (int)arr.m_data;
    }
    else
    {
        pSubpart->unk30 = 1;
        pSubpart->unk28 = (int)&DAT_01267e30;
        pSubpart->unk2C = 0;
        pSubpart->unk20 = (int)&DAT_01267e30;
    }
    pSubpart->unk34 = kSubpart.unk34;
}

namespace fnv_00d4ba30 {

struct hkpMeshSubpartD4B
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    unsigned char m_ucIndexStridingType;
    unsigned char m_iMaterialIndexType;
    short unk12;
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

class FUN_00dcd380 : public hkpShapeCollection
{
  public:
    virtual ~FUN_00dcd380();
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    hkArray<hkpMeshSubpartD4B> m_kSubparts;

    FUN_00dcd380(FinishingFlag flag);
};

struct hkpSubpartStorageD4B : hkReferencedObject
{
    hkArray<float> m_kVertices;
    hkArray<unsigned short> m_kIndices16;
    hkArray<unsigned int> m_kIndices32;
    hkArray<unsigned char> m_kMaterialIndices8;
    hkArray<unsigned int> m_kMaterials;
    hkArray<unsigned short> m_kMaterialIndices16;
};

class FUN_00d4ba30 : public FUN_00dcd380
{
  public:
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkArray<hkpSubpartStorageD4B*> m_kStorage;

    FUN_00d4ba30(FinishingFlag flag);
    virtual ~FUN_00d4ba30();
};

// Constructor: calls the base constructor and, if flag.m_bFinishing is set, points each subpart's data fields at the begin of the matching storage arrays.
// @fnv 0x00d4ba30
FUN_00d4ba30::FUN_00d4ba30(FinishingFlag flag) : FUN_00dcd380(flag), m_kStorage(flag)
{
    if (flag.m_bFinishing)
    {
        for (int i = 0; i < m_kSubparts.GetLogicalSize(); i++)
        {
            hkpMeshSubpartD4B& part = m_kSubparts[i];
            hkpSubpartStorageD4B& storage = *m_kStorage[i];
            part.m_pMaterialIndexBase = storage.m_kVertices.begin();
            if (part.m_ucIndexStridingType == 1)
                part.m_pMaterialDataBase = storage.m_kIndices16.begin();
            else
                part.m_pMaterialDataBase = storage.m_kIndices32.begin();
            if (part.m_iMaterialIndexType == 1)
                part.m_pVertexBase = storage.m_kMaterialIndices8.begin();
            else
                part.m_pVertexBase = storage.m_kMaterialIndices16.begin();
            part.m_pIndexBase = storage.m_kMaterials.begin();
        }
    }
}
}  // namespace fnv_00d4ba30

namespace fnv_00d4bd60 {

namespace hkD4BD {

struct TriangleD4BD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34;
};
}

// Concrete collection interface for the mesh owner; all layout comes from the shared base.
class MeshShapeCollectionD4BD : public hkpShapeCollection
{
  public:
    virtual void CalculateAabb(const hkTransform&, hkReal, hkAabb&) const;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&, ShapeRayCastOutput&) const;
    virtual void CastRayWithCollector(const ShapeRayCastQuery&, const hkpCdBody&, hkpRayHitCollector&) const;
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey) const;
    virtual const hkpShape* GetShapeForKey(hkpShapeKey, hkpShapeBuffer&) const;
};

class FUN_00d4bd60
{
  public:
    ~FUN_00d4bd60() throw();

    MeshShapeCollectionD4BD m_kCollection;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    hkArray<hkD4BD::TriangleD4BD> m_kTriangles;
    hkArray<unsigned short> m_kMaterialIndices;
};

// Destructor for a triangle collection object that owns a shape collection, a triangle array, and a material index array.
// @fnv 0x00d4bd60
FUN_00d4bd60::~FUN_00d4bd60() throw()
{}
}  // namespace fnv_00d4bd60

namespace fnv_00dcebd0 {
template <typename T> static __forceinline void CopyElements(T* dest, const T* src, int count)
{
    for (int index = 0; index < count; ++index)
        dest[index] = src[index];
}

struct FUN_00dcebd0_Class : hkpShapeCollection
{
    int m_reserved18;
    int m_reserved1c;
    float m_scalingX, m_scalingY, m_scalingZ, m_scalingW;
    int m_iNumBitsForSubpartIndex;
    void* m_subpartsData;
    int m_subpartsSize;
    int m_subpartsCapacity;
    void* m_weldingInfoData;
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void FUN_00d06290(const FUN_00dcebd0_Class& source);
    void hkpPhysicsSystemWithContacts_copy(const FUN_00dcebd0_Class& source);
};
// Calls FUN_00d06290(source), then copies source's int array into this, reallocating through the thread allocator when capacity is smaller.
// @fnv 0x00dcebd0
// src: HAVOK_LIB 0x00dcebd0
void FUN_00dcebd0_Class::hkpPhysicsSystemWithContacts_copy(const FUN_00dcebd0_Class& source)
{
    FUN_00d06290(source);
    hkMemoryAllocator* allocator = hkMemoryRouter_getInstance().m_heap;
    int capacity = m_iCapacityState & 0x3fffffff;
    if (capacity < source.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000u) == 0)
        {
            allocator->bufFree(m_data, capacity * sizeof(int));
        }
        int bytes = source.m_iElementCount * sizeof(int);
        m_data = static_cast<int*>(allocator->bufAlloc(bytes));
        m_iCapacityState = bytes / 4;
    }
    m_iElementCount = source.m_iElementCount;
    CopyElements(m_data, source.m_data, m_iElementCount);
}
}  // namespace fnv_00dcebd0
