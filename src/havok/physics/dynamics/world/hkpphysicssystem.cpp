
// src/havok/physics/dynamics/world/hkpphysicssystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/hkpphysicssystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkpPhysicsSystem.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkMemoryRouter.h"

// Allocator-dependent hkArray bodies are unit-defined; preserve this unit's original inline call forms.
inline void memMoveD062(void* pvDst, const void* pvSrc, int iNumBytes);
inline void memCpy4_d061(void* dst, const void* src, int nbytes);
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);

inline hkMemoryAllocator& physicsHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}
inline hkMemoryAllocator* physicsHeapAllocator(const void*)
{
    return &physicsHeap(*(&hkMemoryRouter::getInstance()));
}
inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void* array)
{
    return *physicsHeapAllocator(array);
}

template <typename T> __forceinline void hkArrayBase<T>::removeAtAndCopy(int index)
{
    --m_iElementCount;
    memMoveD062(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
}

template <typename T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    --m_iElementCount;
    if (m_iElementCount != index)
        ::memCpy4_d061(m_data + index, m_data + m_iElementCount, sizeof(T));
}

template <int SIZE> __forceinline void copyPhysicsArrayElement(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do { d[i] = s[i]; } while (++i < SIZE / 4);
}

template <typename T> __forceinline void hkArrayBase<T>::pushBackUnchecked(const T& e)
{
    copyPhysicsArrayElement<sizeof(T)>(m_data + m_iElementCount, &e);
    m_iElementCount++;
}

template <typename T> __forceinline void appendPhysicsArray(hkArrayBase<T>& array, const T& e)
{
    hkMemoryRouter& router = *(&hkMemoryRouter::getInstance());
    if (array.m_iElementCount == array.getCapacity())
        ResizeAudioStream(router.m_heap, &array, sizeof(T));
    array.pushBackUnchecked(e);
}

template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray& a)
{
    hkMemoryAllocator& alloc = AllocatorType().get(this);
    if (this->getCapacity() < a.m_iElementCount)
    {
        if ((this->m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(this->m_data, this->getCapacity() * sizeof(T));
        int bytes = a.m_iElementCount * sizeof(T);
        this->m_data = static_cast<T*>(alloc.bufAlloc(bytes));
        this->m_iCapacityState = bytes / (int)sizeof(T);
    }
    this->m_iElementCount = a.m_iElementCount;
    this->copy(this->m_data, a.m_data, this->m_iElementCount);
    return *this;
}

template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kHeap, int iWanted)
{
    const int iHave = getCapacity();
    if (iHave < iWanted)
    {
        int iTwice = 2 * iHave;
        int size = (iWanted < iTwice) ? iTwice : iWanted;
        hkArrayUtil::_reserve(kHeap, this, size, sizeof(T));
    }
}

template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    this->_clearAndDeallocate(AllocatorType().get(this));
}

struct DDCC60World
{
    void removeReference();
};

struct FUN_00d06090_Class
{
    void* vftable;
    int padding0;
    DDCC60World** refs0;
    int count0;
    int padding1;
    DDCC60World** refs1;
    int count1;
    int padding2;
    DDCC60World** refs2;
    int count2;
    int padding3;
    DDCC60World** refs3;
    int count3;

    void ReleaseAllReferences();
};

// Calls removeReference on each non-null entry of the four reference arrays, then resets their counts to zero.
// @fnv 0x00d06090
void FUN_00d06090_Class::ReleaseAllReferences()
{
    int count = count0;
    for (int i = 0; i < count; ++i)
    {
        if (refs0[i])
        {
            refs0[i]->removeReference();
        }
    }
    count0 = 0;

    count = count3;
    for (int i = 0; i < count; ++i)
    {
        if (refs3[i])
        {
            refs3[i]->removeReference();
        }
    }
    count3 = 0;

    count = count1;
    for (int i = 0; i < count; ++i)
    {
        if (refs1[i])
        {
            refs1[i]->removeReference();
        }
    }
    count1 = 0;

    count = count2;
    for (int i = 0; i < count; ++i)
    {
        if (refs2[i])
        {
            refs2[i]->removeReference();
        }
    }
    count2 = 0;
}

extern int DAT_010cce28;
extern int _DAT_0102e388;

struct MemoryAllocator
{
    virtual void FUN_00() = 0;
    virtual void FUN_01() = 0;
    virtual void FUN_02() = 0;
    virtual void FUN_03() = 0;
    virtual void Free(void* data, unsigned int size) = 0;
};

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

struct FUN_00d06640_class
{
    // Destroy writes the buffer pointer through a volatile lvalue, unlike hkArray's data member.
    struct Buffer
    {
        void* volatile m_pData;
        unsigned int m_uCount;
        unsigned int m_uCapacity;
    };

    void* volatile m_pVtable;
    void* m_pPadding;
    Buffer m_pWorkingSet[4];
    S_00d49310_Lock m_lock;

    void ReleaseAllReferences();
    void Destroy();
};

// @fnv 0x00d06640
void FUN_00d06640_class::Destroy()
{
    unsigned int highBit = 0x80000000u;

    m_pVtable = &DAT_010cce28;
    ReleaseAllReferences();
    m_lock.~S_00d49310_Lock();

    hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
    MemoryAllocator* allocator = reinterpret_cast<MemoryAllocator*>(router->m_heap);
    unsigned int capacity = m_pWorkingSet[3].m_uCapacity;
    m_pWorkingSet[3].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[3].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[3].m_pData = 0;
    m_pWorkingSet[3].m_uCapacity = highBit;

    router = (&hkMemoryRouter::getInstance());
    allocator = reinterpret_cast<MemoryAllocator*>(router->m_heap);
    capacity = m_pWorkingSet[2].m_uCapacity;
    m_pWorkingSet[2].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[2].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[2].m_pData = 0;
    m_pWorkingSet[2].m_uCapacity = highBit;

    router = (&hkMemoryRouter::getInstance());
    allocator = reinterpret_cast<MemoryAllocator*>(router->m_heap);
    capacity = m_pWorkingSet[1].m_uCapacity;
    m_pWorkingSet[1].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[1].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[1].m_pData = 0;
    m_pWorkingSet[1].m_uCapacity = highBit;

    router = (&hkMemoryRouter::getInstance());
    allocator = reinterpret_cast<MemoryAllocator*>(router->m_heap);
    capacity = m_pWorkingSet[0].m_uCapacity;
    m_pWorkingSet[0].m_uCount = 0;
    if (!(capacity & highBit))
        allocator->Free(m_pWorkingSet[0].m_pData, (capacity & 0x3FFFFFFFu) * 4u);
    m_pWorkingSet[0].m_pData = 0;
    m_pWorkingSet[0].m_uCapacity = highBit;

    m_pVtable = &_DAT_0102e388;
}

// @fnv 0x00cb0020
// src: XBOX_PDB 0x00cb0020
void __stdcall hkMemoryTrackStreamWriter_seekTellSupported(unsigned char* output)
{
    *output = 0;
}

inline void memMoveD062(void* pvDst, const void* pvSrc, int iNumBytes)
{
    for (int i = 0; i < iNumBytes; i += 4)
        *(int*)((char*)pvDst + i) = *(const int*)((const char*)pvSrc + i);
}

class hkObjD062
{
  public:
    int unk00[0xb];
    hkArray<void*> m_entries;

    void RemoveNullEntries();
};

// Iterates m_entries backwards and removes every entry that is null via removeAtAndCopy.
// @fnv 0x00d06230
void hkObjD062::RemoveNullEntries()
{
    for (int i = m_entries.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (m_entries[i] == 0)
            m_entries.removeAtAndCopy(i);
    }
}

typedef unsigned int Size64;
inline void* __cdecl operator new(Size64, void* p)
{
    return p;
}
struct Shape64
{
    void __thiscall FUN_00c90510();
};
typedef Shape64* ShapePtr64;
void __cdecl ResizeAudioStream(void* allocator, hkArray<ShapePtr64>* array, int elementSize);
struct Container64
{
    void* vtable;
    void* pad04;
    hkArray<ShapePtr64> array;
    void __thiscall AddShape(Shape64* object);
};
// Calls FUN_00c90510 on object, then appends object to array, growing it via ResizeAudioStream when full.
// @fnv 0x00d064a0
void Container64::AddShape(Shape64* pShape)
{
    if (pShape)
    {
        pShape->FUN_00c90510();
        hkArray<ShapePtr64>* pArray = &array;
        hkMemoryRouter* router = (&hkMemoryRouter::getInstance());
        if (pArray->m_iElementCount == (pArray->m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(router->m_heap, pArray, 4);
        }
        ShapePtr64* pSlot = pArray->m_data + pArray->m_iElementCount;
        __assume(pSlot != 0);
        new (pSlot) ShapePtr64(pShape);
        ++pArray->m_iElementCount;
    }
}

struct FUN_00cb0b80
{
    char* m_kStringBuffer;
    FUN_00cb0b80(const char* s) throw();
};

class hkRefObjD065
{
  public:
    virtual ~hkRefObjD065() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjD065()
    {
        m_sReferenceCount = 1;
    }
};

class FUN_00d065e0 : public hkRefObjD065
{
  public:
    hkArray<void*> m_kPointA;
    hkArray<void*> m_kPointB;
    hkArray<void*> m_iThirdValue;
    hkArray<void*> m_iFourthElementInteger;
    FUN_00cb0b80 m_name;
    int m_3c;
    bool m_40;

    FUN_00d065e0() throw();
    virtual ~FUN_00d065e0() throw();
};

// Initializes the object's name, m_3c to 0 and m_40 to true, leaving the four arrays default-constructed.
// @fnv 0x00d065e0
FUN_00d065e0::FUN_00d065e0() throw() : m_name(0), m_3c(0), m_40(true)
{}

namespace fnv_00d06c00 {
struct FnvCpu_FUN_00d06c00_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d06c00_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void Destroy();
    FnvCpu_FUN_00d06c00_CpuObject* FUN_00d06c00(unsigned int flags);
};
// @fnv 0x00d06c00
FnvCpu_FUN_00d06c00_CpuObject* FnvCpu_FUN_00d06c00_CpuObject::FUN_00d06c00(unsigned int flags)
{
    Destroy();
    if (flags & 1)
    {
        hkMemoryRouter* holder = (&hkMemoryRouter::getInstance());
        reinterpret_cast<FnvCpu_FUN_00d06c00_CpuAllocator*>(holder->m_heap)->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d06c00

// The shared class has no copy-method declaration; this helper keeps the original ECX instance and stack argument.
// Copies the rigid body, constraint, action, phantom, name, user data, and slot enabled state arrays and fields from kOther into this physics system.
// @fnv 0x00d06290
void __fastcall CopyPhysicsSystem(hkpPhysicsSystem* system, void*, const hkpPhysicsSystem& kOther)
{
    system->m_ppRigidBodies = kOther.m_ppRigidBodies;
    system->m_kPhantoms = kOther.m_kPhantoms;
    system->m_ppConstraints = kOther.m_ppConstraints;
    system->m_ppActions = kOther.m_ppActions;
    system->m_name.UpdateState_00cb0c30(&kOther.m_name);
    system->m_ulUserData = kOther.m_ulUserData;
    system->m_bSlotEnabled = kOther.m_bSlotEnabled;
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

class hkShapeD064
{
  public:
    void FUN_00c90510();
};

class hkOwnerD064
{
  public:
    int unk00[11];
    hkArray<hkShapeD064*> m_shapes;

    void hkpPhysicsSystem_addPhantom(hkShapeD064* shape);
};

// If shape is non-null, calls shape->FUN_00c90510() and appends it to m_shapes via AddBack.
// @fnv 0x00d064f0
// src: HAVOK_LIB 0x00d064f0
void hkOwnerD064::hkpPhysicsSystem_addPhantom(hkShapeD064* shape)
{
    if (shape)
    {
        shape->FUN_00c90510();
        appendPhysicsArray(m_shapes, shape);
    }
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

class hkShapeXd06540
{
  public:
    void FUN_00c90510();
};

class hkOwnerXd06540
{
  public:
    int unk00[5];
    hkArray<hkShapeXd06540*> m_shapes;

    void hkpPhysicsSystem_addConstraint(hkShapeXd06540* shape);
};

// If shape is non-null, calls shape->FUN_00c90510() and appends shape to m_shapes via AddBack.
// @fnv 0x00d06540
// src: HAVOK_LIB 0x00d06540
void hkOwnerXd06540::hkpPhysicsSystem_addConstraint(hkShapeXd06540* shape)
{
    if (shape)
    {
        shape->FUN_00c90510();
        appendPhysicsArray(m_shapes, shape);
    }
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

class hkShapeXd06590
{
  public:
    void FUN_00c90510();
};

class hkOwnerXd06590
{
  public:
    int unk00[8];
    hkArray<hkShapeXd06590*> m_shapes;

    void hkpPhysicsSystem_addAction(hkShapeXd06590* shape);
};

// If shape is non-null, calls shape->FUN_00c90510() and appends it to m_shapes via AddBack.
// @fnv 0x00d06590
// src: HAVOK_LIB 0x00d06590
void hkOwnerXd06590::hkpPhysicsSystem_addAction(hkShapeXd06590* shape)
{
    if (shape)
    {
        shape->FUN_00c90510();
        appendPhysicsArray(m_shapes, shape);
    }
}

#include <xmmintrin.h>
__declspec(align(16)) struct AlignedVector4
{
    float x, y, z, w;
    __forceinline AlignedVector4& operator=(const AlignedVector4& o)
    {
        *(__m128*)this = *(__m128*)&o;
        return *this;
    }
};

__declspec(align(16)) struct AlignedTransform
{
    AlignedVector4 m_kColumn0;
    AlignedVector4 m_kColumn1;
    AlignedVector4 m_kColumn2;
    AlignedVector4 m_vTranslation;

    AlignedTransform()
    {}
    AlignedTransform(const AlignedTransform& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_vTranslation = o.m_vTranslation;
    }

    void ProcessTransformedMatrixCopy_00cb23e0(const hkTransform* other);
};

struct FUN_00ca8890_Class
{
    int unk00, unk04, unk08, unk0C;
    int unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C;
    int unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C;
    int unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC;
    int unkE0, unkE4, unkE8, unkEC;
    hkTransform m_kMotionTransform;

    void hkpRigidBody_setTransform(const AlignedTransform* t);
};

struct FUN_00cf30f0_Class
{
    void ApplyTransformToWorldConstraint(const hkTransform* t);
};

void tranformPhantom(void* phantom, const hkTransform* t);

// The original transform input is copied as four scalar words per column before the aligned SIMD copy.
struct TransformColumnFields
{
    float x, y, z, w;
};

struct PhysicsSystemWrapper : public hkpPhysicsSystem
{
    void ApplyMotionTransform(const hkTransform* a2);
};

// Applies a2 to every rigid body, constraint, and phantom in the physics system.
// @fnv 0x00d05f60
void PhysicsSystemWrapper::ApplyMotionTransform(const hkTransform* a2)
{
    for (int i = 0; i < m_ppRigidBodies.m_iElementCount; ++i)
    {
        AlignedTransform t1;
        *(TransformColumnFields*)&t1.m_kColumn0 = *(const TransformColumnFields*)&a2->m_kColumn0;
        *(TransformColumnFields*)&t1.m_kColumn1 = *(const TransformColumnFields*)&a2->m_kColumn1;
        *(TransformColumnFields*)&t1.m_kColumn2 = *(const TransformColumnFields*)&a2->m_kColumn2;
        *(TransformColumnFields*)&t1.m_vTranslation = *(const TransformColumnFields*)&a2->m_vTranslation;

        AlignedTransform t2 = t1;

        t2.ProcessTransformedMatrixCopy_00cb23e0(&((FUN_00ca8890_Class*)m_ppRigidBodies.m_data[i])->m_kMotionTransform);
        ((FUN_00ca8890_Class*)m_ppRigidBodies.m_data[i])->hkpRigidBody_setTransform(&t2);
    }
    for (int i = 0; i < m_ppConstraints.m_iElementCount; ++i)
    {
        ((FUN_00cf30f0_Class*)m_ppConstraints.m_data[i])->ApplyTransformToWorldConstraint(a2);
    }
    for (int i = 0; i < m_kPhantoms.m_iElementCount; ++i)
    {
        tranformPhantom(m_kPhantoms.m_data[i], a2);
    }
}

struct ReferenceBody
{
    void FUN_00c905b0();
};
struct BodyCollection
{
    unsigned int unk00, unk04;
    ReferenceBody** data;
    int count;
    unsigned int capacityFlags;
    void hkpPhysicsSystem_removeRigidBody(unsigned int index);
};
// Calls FUN_00c905b0 on the element at index, decrements count, and shifts the last element into the slot if index is not the last.
// @fnv 0x00d06130
// src: HAVOK_LIB 0x00d06130
void BodyCollection::hkpPhysicsSystem_removeRigidBody(unsigned int index)
{
    data[index]->FUN_00c905b0();
    --count;
    if (count != index)
    {
        ReferenceBody** dst = data + index;
        ReferenceBody* const* src = data + count;
        for (int n = 0; n < sizeof(ReferenceBody*); n += sizeof(ReferenceBody*))
            *(ReferenceBody**)((char*)dst + n) = *(ReferenceBody* const*)((const char*)src + n);
    }
}

struct hkRefD061
{
    void FUN_00c905b0();
};
struct OwnerD061
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    hkRefD061** refs3;
    int count3;
    unsigned int capacityFlags3;
    void hkpPhysicsSystem_removePhantom(int index);
};
// Calls FUN_00c905b0 on refs3[index], decrements count3, and moves the last element into the slot if index is not the last.
// @fnv 0x00d06170
// src: HAVOK_LIB 0x00d06170
void OwnerD061::hkpPhysicsSystem_removePhantom(int index)
{
    refs3[index]->FUN_00c905b0();
    --count3;
    if (count3 != index)
    {
        hkRefD061** dst = refs3 + index;
        hkRefD061* const* src = refs3 + count3;
        for (int n = 0; n < sizeof(hkRefD061*); n += sizeof(hkRefD061*))
            *(hkRefD061**)((char*)dst + n) = *(hkRefD061* const*)((const char*)src + n);
    }
}

struct RefObj
{
    void __thiscall FUN_00c905b0();
};

inline void memCpy4_d061(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

struct FUN_00d061b0_Class
{
    void* vftable;
    int unk04, unk08, unk0C, unk10;
    hkArray<RefObj*> m_refs;
    void hkpPhysicsSystem_removeConstraint(int index);
};

// Calls FUN_00c905b0 on m_refs[index], then removes that entry from m_refs.
// @fnv 0x00d061b0
// src: HAVOK_LIB 0x00d061b0
void FUN_00d061b0_Class::hkpPhysicsSystem_removeConstraint(int index)
{
    m_refs[index]->FUN_00c905b0();
    m_refs.removeAt(index);
}

namespace fnv_00d061f0 {
struct RefObj
{
    void __thiscall FUN_00c905b0();
};

struct FUN_00d061f0_Class
{
    void* vftable;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkArray<RefObj*> m_refs;
    void hkpPhysicsSystem_removeAction(int index);
};

// Calls FUN_00c905b0 on the RefObj at index, then removes that entry from m_refs.
// @fnv 0x00d061f0
// src: HAVOK_LIB 0x00d061f0
void FUN_00d061f0_Class::hkpPhysicsSystem_removeAction(int index)
{
    m_refs[index]->FUN_00c905b0();
    m_refs.removeAt(index);
}
}  // namespace fnv_00d061f0

extern float DAT_0104da48;
extern __m128 DAT_011b1bd0;

struct __declspec(align(16)) TerrainVec
{
    __m128 q;
    float& lane(int i)
    {
        return reinterpret_cast<float*>(&q)[i];
    }
    const float& lane(int i) const
    {
        return reinterpret_cast<const float*>(&q)[i];
    }
    TerrainVec& operator=(const TerrainVec& b)
    {
        q = b.q;
        return *this;
    }
    void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    void multiply(const TerrainVec& a, const TerrainVec& b)
    {
        q = _mm_mul_ps(a.q, b.q);
    }
    void add(const TerrainVec& a, const TerrainVec& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
    void multiply(const TerrainVec& b)
    {
        q = _mm_mul_ps(q, b.q);
    }
    void add(const TerrainVec& b)
    {
        q = _mm_add_ps(q, b.q);
    }
    __m128 sum3() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
        return _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), xy);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        TerrainVec square;
        square.q = _mm_mul_ps(q, q);
        __m128 len = square.sum3();
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 estimate = _mm_rsqrt_ss(len);
        __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, estimate), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, estimate), estimate)));
        __m128 inv = _mm_andnot_ps(eq, refined);
        q = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), q);
    }
};
union GridCodes
{
    unsigned short lanes[4];
    unsigned __int64 packed;
};
__forceinline void encodePoint(const TerrainVec& point, const TerrainVec& offset, const TerrainVec& scale,
                               GridCodes& codes)
{
    TerrainVec value;
    value.add(point, offset);
    value.q = _mm_mul_ps(value.q, _mm_load_ps((const float*)&scale));
    TerrainVec bias;
    bias.q = DAT_011b1bd0;
    value.add(bias);
    union Packed
    {
        __m128 q;
        unsigned int words[4];
    } raw;
    raw.q = value.q;
    codes.lanes[0] = (unsigned short)(raw.words[0] >> 6);
    codes.lanes[1] = (unsigned short)(raw.words[1] >> 6);
    codes.lanes[2] = (unsigned short)(raw.words[2] >> 6);
    codes.lanes[3] = (unsigned short)(raw.words[3] >> 6);
}
struct TerrainInput
{
    const TerrainVec* spheres;
    int count;
};
struct TerrainFlip
{
    char value;
    TerrainFlip()
    {}
    TerrainFlip(bool b) : value(b)
    {}
};
struct TerrainBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual float sample(int x, int z) const;
    virtual TerrainFlip flipped() const;
    int refInfo;
    unsigned int userData;
    unsigned int typeInfo;
    int width;
    int depth;
    float minHeight;
    char projection;
};
struct TerrainShape : TerrainBase
{
    TerrainVec worldScale;
    TerrainVec gridScale;
    TerrainVec floorOffset;
    void EvaluateSpheres(const TerrainInput& input, TerrainVec* output) const;
};
// For each input sphere, computes terrain height and normal at its grid position, then stores the signed distance to the sphere in the output vector.
// @fnv 0x00cb01f0
void TerrainShape::EvaluateSpheres(const TerrainInput& input, TerrainVec* output) const
{
    const TerrainVec* sphere = input.spheres;
    TerrainVec fallback;
    fallback.set(0.0f, 1.0f, 0.0f, DAT_0104da48);
    for (int remaining = input.count - 1; remaining >= 0; ++output, ++sphere, --remaining)
    {
        *output = fallback;
        TerrainVec position;
        position.q = _mm_mul_ps(_mm_load_ps((const float*)sphere), _mm_load_ps((const float*)&gridScale));
        GridCodes codes;
        encodePoint(*sphere, floorOffset, gridScale, codes);
        int x = codes.lanes[0];
        int z = codes.lanes[2];
        if (x >= width - 1 || z >= depth - 1)
            continue;
        float fx = position.lane(0) - float(x);
        float afDepth = position.lane(2) - float(z);
        float height;
        float vertexHeight;
        int vertexX;
        TerrainFlip flip = flipped();
        if (flip.value)
        {
            float a = sample(x, z);
            vertexHeight = a;
            vertexX = x;
            float b = sample(x + 1, z + 1);
            if (fx > afDepth)
            {
                float c = sample(x + 1, z);
                float sx = c - a;
                float sz = b - c;
                height = a + afDepth * sz + fx * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
            else
            {
                float c = sample(x, z + 1);
                float sx = b - c;
                float sz = c - a;
                height = a + afDepth * sz + fx * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
        }
        else
        {
            float a = sample(x + 1, z);
            vertexHeight = a;
            vertexX = x + 1;
            float b = sample(x, z + 1);
            if (fx + afDepth > 1.0)
            {
                float c = sample(x + 1, z + 1);
                float sx = c - b;
                float sz = c - a;
                height = a + afDepth * sz + (fx - 1.0) * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
            else
            {
                float c = sample(x, z);
                float sx = a - c;
                float sz = b - c;
                height = c + afDepth * sz + fx * sx;
                output->lane(0) = -sx;
                output->lane(2) = -sz;
            }
        }
        output->q = _mm_mul_ps(output->q, gridScale.q);
        output->normalize();
        float distance;
        if (!projection)
        {
            distance = (position.lane(1) - height) * worldScale.lane(1) - sphere->lane(3);
        }
        else
        {
            TerrainVec vertex;
            vertex.set(float(vertexX), vertexHeight, float(z), 0.0f);
            TerrainVec delta;
            delta.q = _mm_sub_ps(position.q, vertex.q);
            delta.q = _mm_mul_ps(delta.q, worldScale.q);
            TerrainVec product;
            product.q = _mm_mul_ps(output->q, delta.q);
            float dot;
            _mm_store_ss(&dot, product.sum3());
            distance = dot - sphere->lane(3);
        }
        output->lane(3) = distance;
    }
}

namespace fnv_00d06720 {
#include <intrin.h>

class hkMemoryAllocatorD
{
  public:
    virtual ~hkMemoryAllocatorD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

inline hkMemoryAllocatorD& heap(hkMemoryRouter& router) throw()
{
    return *reinterpret_cast<hkMemoryAllocatorD*>(router.m_heap);
}

class hkBaseObjectD
{
  public:
    virtual ~hkBaseObjectD() throw();
};
class hkReferencedObjectD : public hkBaseObjectD
{
  public:
    void* operator new(unsigned int uiBytes) throw()
    {
        hkReferencedObjectD* b = static_cast<hkReferencedObjectD*>(heap(*(&hkMemoryRouter::getInstance())).AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpEntityD : public hkReferencedObjectD
{
};
class hkpRigidBodyD : public hkpEntityD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual hkpRigidBodyD* clone() const throw();
};
class hkpPhantomD : public hkReferencedObjectD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual hkpPhantomD* clone() const throw();
};

class hkBoolD
{
  public:
    hkBoolD(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkpConstraintInstanceD : public hkReferencedObjectD
{
  public:
    hkpRigidBodyD* getRigidBody() const throw()
    {
        return m_pEntityA;
    }
    hkpRigidBodyD* getRigidBodyB() const throw()
    {
        return m_pEntityB;
    }
    hkBoolD isConstrainedToWorld() const throw();
    hkpConstraintInstanceD* clone_00cf3fa0(hkpRigidBodyD* pk, hkpRigidBodyD* pkB, int eMode) const throw();

    void* m_pOwnerObject;
    void* m_data;
    void* m_pConstraintModifier;
    hkpRigidBodyD* m_pEntityA;
    hkpRigidBodyD* m_pEntityB;
};

class hkpActionD : public hkReferencedObjectD
{
  public:
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void GetEntities(hkArray<hkpEntityD*>& kEntitiesOut) throw();
    virtual void getPhantomArray(hkArray<hkpPhantomD*>& kPhantomsOut) throw();
    virtual void v18() throw();
    virtual hkpActionD* clone(const hkArray<hkpEntityD*>& kNewEntities,
                              const hkArray<hkpPhantomD*>& kNewPhantoms) const throw();
};

class FUN_00d065e0 : public hkReferencedObjectD
{
  public:
    FUN_00d065e0() throw();
    FUN_00d065e0* hkpPhysicsSystem_clone() const throw();

    hkArray<hkpRigidBodyD*> m_ppRigidBodies;
    hkArray<hkpConstraintInstanceD*> m_ppConstraints;
    hkArray<hkpActionD*> m_ppActions;
    hkArray<hkpPhantomD*> m_kPhantoms;
    hkStringPtr m_name;
    unsigned long m_ulUserData;
    hkBoolD m_bSlotEnabled;
};

// @fnv 0x00d06720
// src: HAVOK_LIB 0x00d06720
FUN_00d065e0* FUN_00d065e0::hkpPhysicsSystem_clone() const throw()
{
    FUN_00d065e0* newSystem = new FUN_00d065e0();

    newSystem->m_name.UpdateState_00cb0c30(&m_name);
    newSystem->m_ulUserData = m_ulUserData;
    newSystem->m_bSlotEnabled = m_bSlotEnabled;

    newSystem->m_ppRigidBodies.setSize(m_ppRigidBodies.GetLogicalSize());
    newSystem->m_kPhantoms.setSize(m_kPhantoms.GetLogicalSize());
    newSystem->m_ppConstraints.setSize(m_ppConstraints.GetLogicalSize());
    newSystem->m_ppActions.setSize(m_ppActions.GetLogicalSize());

    int i;
    for (i = 0; i < m_ppRigidBodies.GetLogicalSize(); i++)
    {
        newSystem->m_ppRigidBodies[i] = m_ppRigidBodies[i]->clone();
    }

    for (i = 0; i < m_kPhantoms.GetLogicalSize(); i++)
    {
        newSystem->m_kPhantoms[i] = m_kPhantoms[i]->clone();
    }

    for (i = 0; i < m_ppConstraints.GetLogicalSize(); i++)
    {
        hkpConstraintInstanceD* constraint = m_ppConstraints[i];
        hkpRigidBodyD* pNewRigidBodyA = newSystem->m_ppRigidBodies[m_ppRigidBodies.indexOf(constraint->getRigidBody())];
        hkpRigidBodyD* pNewRigidBodyB =
            constraint->isConstrainedToWorld()
                ? 0
                : newSystem->m_ppRigidBodies[m_ppRigidBodies.indexOf(constraint->getRigidBodyB())];
        newSystem->m_ppConstraints[i] = constraint->clone_00cf3fa0(pNewRigidBodyA, pNewRigidBodyB, 0);
    }

    for (i = 0; i < m_ppActions.GetLogicalSize(); i++)
    {
        hkpActionD* action = m_ppActions[i];
        if (!action)
        {
            newSystem->m_ppActions[i] = 0;
        }
        else
        {
            hkArray<hkpEntityD*> oldEntities;
            _ReadWriteBarrier();
            action->GetEntities(oldEntities);
            hkArray<hkpEntityD*> newEntities;
            int numEntities = oldEntities.GetLogicalSize();
            newEntities.setSize(numEntities);
            for (int j = 0; j < numEntities; j++)
            {
                int index = m_ppRigidBodies.indexOf(static_cast<hkpRigidBodyD*>(oldEntities[j]));
                newEntities[j] = newSystem->m_ppRigidBodies[index];
            }

            hkpActionD* actionCur = *(hkpActionD* volatile*)&action;
            _ReadWriteBarrier();
            hkArray<hkpPhantomD*> oldPhantoms;
            _ReadWriteBarrier();
            actionCur->getPhantomArray(oldPhantoms);
            hkArray<hkpPhantomD*> newPhantoms;
            int numPhantoms = oldPhantoms.GetLogicalSize();
            newPhantoms.setSize(numPhantoms);
            for (int k = 0; k < numPhantoms; k++)
            {
                hkpPhantomD* phantom = oldPhantoms[k];
                int index = m_kPhantoms.indexOf(phantom);
                newPhantoms[k] = newSystem->m_kPhantoms[index];
            }

            newSystem->m_ppActions[i] = action->clone(newEntities, newPhantoms);
        }
    }

    return newSystem;
}
}  // namespace fnv_00d06720
