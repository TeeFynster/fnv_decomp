#include "../../include/hkArrayBase.h"
#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#include "../../include/NiTLargeArray.h"
#include "../../include/hkArray.h"
// staging/blk_00cc0000_o2.cpp: CacheOwner_cls, Owner, Obj, hkVector4 and more (425 functions)
#include <math.h>
#include <string.h>
#include "../../include/NiPointer.h"
#include "../../include/hkpConvexListShape.h"
#include "../../include/hkaSkeleton.h"
#include "../../include/hkaPose.h"
#include "../../include/hkpShape.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiTMap.h"
#include "../../include/NiTMapItem.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkConvexListShape.h"
#include "../../include/hkBool.h"
#include "../../include/hkQsTransform.h"
#include "../../include/hkQuaternion.h"
// local form of hkVector4: 0x00cdad80 needs original typed copy calls (shared extent 868 vs 798).


// Define FNV_VECTOR_USE_LOCAL_SSE when __m128 and intrinsics are already declared.
#if !defined(FNV_VECTOR_USE_LOCAL_SSE)
#include <xmmintrin.h>
#endif

class Scalar;
class Comparison;
class Transform;
class hkRotation;

class PoseVectorCallLocal_00cdad80
{
public:
    union
    {
        LocalM128 q;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };

    __forceinline PoseVectorCallLocal_00cdad80() {}
    __forceinline PoseVectorCallLocal_00cdad80(const PoseVectorCallLocal_00cdad80& vector) : q(vector.q) {}
    __forceinline PoseVectorCallLocal_00cdad80(const LocalM128& vector) : q(vector) {}
    PoseVectorCallLocal_00cdad80(float x, float y, float z);
    __forceinline PoseVectorCallLocal_00cdad80& operator=(const PoseVectorCallLocal_00cdad80& vector)
    {
        q = vector.q;
        return *this;
    }
    __forceinline void operator=(const LocalM128& vector)
    {
        q = vector;
    }
    operator LocalM128() const;
    PoseVectorCallLocal_00cdad80 operator*(float value) const;
    PoseVectorCallLocal_00cdad80 operator+(const PoseVectorCallLocal_00cdad80& vector) const;
    PoseVectorCallLocal_00cdad80 operator-() const;
    float& operator()(int index);
    const float& operator()(int index) const;
    LocalM128& packet();
    const LocalM128& packet() const;

    void set(float x, float y, float z, float w = 0.0f);
    void zero();
    void setZero4();
    void subtract(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void sub(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void setSub(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void setSub4(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void add(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void setAdd(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void setAdd4(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void add4(const PoseVectorCallLocal_00cdad80& vector);
    void mul(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void mul4(const PoseVectorCallLocal_00cdad80& vector);
    void mul4(const Scalar& scalar);
    void multiply(const Scalar& scalar);
    void scale(const Scalar& scalar);
    void product(const Scalar& scalar, const PoseVectorCallLocal_00cdad80& vector);
    void cross(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void setCross(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b);
    void negate(const PoseVectorCallLocal_00cdad80& vector);
    void setNeg4(const PoseVectorCallLocal_00cdad80& vector);
    void addMul(const PoseVectorCallLocal_00cdad80& a, LocalM128 scale, const PoseVectorCallLocal_00cdad80& b);
    void setAddMul4(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b, const Scalar& scalar);
    void interpolate(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b, const Scalar& t);
    void setInterpolate4(const PoseVectorCallLocal_00cdad80& a, const PoseVectorCallLocal_00cdad80& b, const Scalar& t);
    void Interpolate(const PoseVectorCallLocal_00cdad80& oldValue, const PoseVectorCallLocal_00cdad80& newValue, float factor);
    void SetTransformedPoint(const Transform& transform, const PoseVectorCallLocal_00cdad80& point);

    Scalar getSimdAt(int index) const;
    Scalar dot(const PoseVectorCallLocal_00cdad80& vector) const;
    Scalar dot3(const PoseVectorCallLocal_00cdad80& vector) const;
    float DotProduct(const PoseVectorCallLocal_00cdad80& vector);
    Scalar sum() const;
    Scalar norm() const;
    Scalar lengthSquared3() const;
    Scalar length3() const;
    float length() const;
    Scalar inverseLength() const;
    void normalize();
    void normalize3();
    Comparison compareLessThanZero4() const;
    int getMajorAxis() const;
    int maxAxisSecond() const;
    int maxAxis() const;
    float GetAngle();

    void SetComponents(float x, float y, float z);
    PoseVectorCallLocal_00cdad80 SubtractIntoVector(const PoseVectorCallLocal_00cdad80& vector);
    PoseVectorCallLocal_00cdad80 FUN_00439e90(const PoseVectorCallLocal_00cdad80& vector);
    void ScaleComponents(float value);
    void Unitize_004a0c10();
    void normalize_005611c0();
    void setMul(const PoseVectorCallLocal_00cdad80* a, const PoseVectorCallLocal_00cdad80* b);
    void setMulInverse(const PoseVectorCallLocal_00cdad80* a, const PoseVectorCallLocal_00cdad80* b);
    void hkQuaternion_getAxis(PoseVectorCallLocal_00cdad80* vector);
    void setTransformedPos_00c7f640(const Transform& transform, const PoseVectorCallLocal_00cdad80& point);
    void hkQuaternion_setAxisAngle(const PoseVectorCallLocal_00cdad80* vector, float value);
    void FUN_00cb26e0(const hkRotation* rotation);

    template <int I> void splat(const PoseVectorCallLocal_00cdad80& vector);

    static const PoseVectorCallLocal_00cdad80& getZero();
};

// ExtraMember_blk_00cc0000_o2: local type (was include/ExtraMember.h, which had no evidence of one real class); its methods are 0x0066b0d0 NiPointer<PathingSolution>::operator=
class ExtraMember_blk_00cc0000_o2
{
public:
    void* vptr;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int count;

    ExtraMember_blk_00cc0000_o2();
    ExtraMember_blk_00cc0000_o2(int initial);
    ~ExtraMember_blk_00cc0000_o2();
    void Reset(int value);
};
// bhkConstraintBaseSI_blk_00cc0000_o2: local type (was include/bhkConstraintBaseSI.h, which had no evidence of one real class); its methods are 0x00c8a230 hkConstraintCinfo::LoadBinary, 0x00c8a330 hkConstraintCinfo::LoadMotor (no shared hkConstraintCinfo header yet)

struct ConstraintDataSI;
struct NiStream;
struct NiStreamSI;

class bhkConstraintBaseSI_blk_00cc0000_o2
{
public:
    void* m_pVtable;
    ConstraintDataSI* m_pData;

    void LoadBinaryBase(NiStream& kStream);
    hkReferencedObject* LoadMotorSI(NiStream& kStream);
    void LoadBinaryBase(NiStreamSI& kStream);
    hkReferencedObject* LoadMotorSI(NiStreamSI& kStream);
};
// bhkLimitedHingeVector_blk_00cc0000_o2: local type (was include/bhkLimitedHingeVector.h, which had no evidence of one real class); its methods are 0x004b4db0 bhkVector4::operator=
class bhkLimitedHingeVector_blk_00cc0000_o2
{
public:
    union
    {
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0C;
        };
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float value[4];
        unsigned char vecData[16];
    };

    void SetQuaternionComponentsFromVector(const float*);
};
// bhkSaveOwner_blk_00cc0000_o2: local type (was include/bhkSaveOwner.h, which had no evidence of one real class); its methods are 0x00c9fc00 bhkConvexShape::SaveBinary, 0x00cd02d0 bhkConvexListShape::SaveBinary
#include "../../include/NiStream.h"

class CountedOwner;
class SaveStreamFields;

class bhkSaveOwner_blk_00cc0000_o2
{
public:
    unsigned int unk00;
    int unk04;
    CountedOwner* m_pSharedOwner;

    int GetCount();
    void bhkConvexShape_SaveBinary(NiStream* stream);
    void SaveLinkedObjects(NiStream* stream);
    void bhkConvexShape_SaveBinary(SaveStreamFields* stream);
    void SaveLinkedObjects(SaveStreamFields* stream);
};
#include "../../include/NiTransform.h"
#include "../../include/NiAVObject.h"
#include "../../include/bhkBvTreeShape.h"
#include "../../include/bhkConvexShape.h"
#include "../../include/bhkConvexSweepShape.h"
#include "../../include/hkMatrix3.h"
#include "../../include/Transform.h"
#include "../../include/hkVector4.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/MemoryHeap.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiStream.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/hkMonitorStream.h"
#include "../../include/StrArr.h"
#include "../../include/NiMatrix3.h"
#include "../../include/bhkConstraint.h"
#include "../../include/bhkFixedConstraint.h"
#include "../../include/bhkGenericConstraint.h"
#include "../../include/hkOstream.h"
#include "../../include/hkStreamWriter.h"

#include "../../include/hkMemoryRouter.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/AutoMemContext.h"
#include "../../include/MemoryManager.h"
#include "../../include/hkMemoryRouter.h"
#include "../../include/Vec4.h"
#include "../../include/hkMemoryAllocator.h"




__forceinline PoseVectorCallLocal_00cdad80::operator LocalM128() const { return q; }

__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline float& hkVector4::operator()(int index) { return m_vComponents.m128_f32[index]; }



inline void Transform::setIdentity()
{
    hkVector4* rows = reinterpret_cast<hkVector4*>(this);
    rows[0].setZero4();
    rows[1].setZero4();
    rows[2].setZero4();
    rows[0](0) = 1.0f;
    rows[1](1) = 1.0f;
    rows[2](2) = 1.0f;
    rows[3].setZero4();
}

// These serialized records copy four words without requiring aligned vector loads.
__forceinline void CopyVectorWords(hkVector4& destination, const hkVector4& source)
{
    memcpy(destination.m_f, source.m_f, sizeof(destination.m_f));
}

// The shared stream declarations leave runtime storage opaque; retain the original transfer access here.
template <class T> inline T& StreamField(NiStream& stream, unsigned int offset)
{
    return *reinterpret_cast<T*>(reinterpret_cast<char*>(&stream) + offset);
}
inline NiBinaryStream*& InputStream(NiStream& stream) { return StreamField<NiBinaryStream*>(stream, 0x24c); }
inline NiBinaryStream*& OutputStream(NiStream& stream) { return StreamField<NiBinaryStream*>(stream, 0x250); }
inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int read = (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, data, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += read;
    return read;
}
inline unsigned int NiBinaryStream::Read(void* data, unsigned int bytes)
{
    return BinaryRead(data, bytes, static_cast<unsigned int*>(0), 0);
}
inline void NiBinaryStream::Write(const void* data, unsigned int bytes, unsigned int size)
{
    BinaryWrite(data, bytes, &size, 1);
}
inline void NiBinaryStream::Write(void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    BinaryWrite(data, bytes, &size, 1);
}
inline unsigned int NiBinaryStream::Write(const void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    return BinaryWrite(data, bytes, &size, 1);
}
template <class T> inline void WriteStreamValues(NiBinaryStream* stream, const T* values, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    stream->BinaryWrite(values, size * count, &size, 1);
}
template <class T> inline void WriteBinaryArray(NiBinaryStream& stream, const T* values, unsigned int count)
{
    unsigned int size = sizeof(T);
    stream.Write(values, count * size, &size, 1);
}
template <class T> inline void SerializeValue(NiStream& stream, const T& value)
{
    WriteStreamValues(OutputStream(stream), &value);
}
inline unsigned int NiBinaryStream::BinaryRead(void* data, unsigned int bytes)
{
    unsigned int size = bytes;
    return BinaryRead(data, bytes, &size, 1);
}

inline void ReadStreamScalar(NiBinaryStream* stream, void* data)
{
    unsigned int size = 4;
    stream->BinaryRead(data, size, &size, 1);
}

void __fastcall PrepareReadStream(NiStream* stream);
void __fastcall PrepareOtherReadStream(NiStream* stream);

inline unsigned int StrArr::Add(char* const& element)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, element);
    return index;
}
inline void AppendStringReference(StrArr* array, char* const& element)
{
    (array->*static_cast<unsigned int (StrArr::*)(char* const&)>(&StrArr::Add))(element);
}
inline void StrArr::AppendInline(char* element)
{
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, element);
}

inline Vec4::Vec4(const Vec4& other)
    : xb(other.xb), yb(other.yb), zb(other.zb), w(other.w) {}

inline unsigned int NiBinaryStream::BinaryWrite(const void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    unsigned int written = (*reinterpret_cast<WriteFunction*>(reinterpret_cast<char*>(this) + 12))(this, data, bytes, sizes, count);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) += written;
    return written;
}
inline unsigned int NiBinaryStream::Write(const void* data, unsigned int bytes, unsigned int* sizes, unsigned int count)
{
    return BinaryWrite(data, bytes, sizes, count);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
template <class T> inline NiPointer<T>::NiPointer() : m_pObject(0) {}
template <class T> inline NiPointer<T>::NiPointer(T* pkNew) : m_pObject(pkNew)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::NiPointer(const NiPointer<T>& kSrc) : m_pObject(kSrc.m_pObject)
{
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> inline NiPointer<T>& NiPointer<T>::operator=(const NiPointer<T>& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}

template <class T> inline NiPointer<T>& NiPointer<T>::operator=(T* pkNew)
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> inline NiPointer<T>::operator T*() const
{
    return m_pObject;
}

// Shared hkMemoryAllocator declarations are nonvirtual; retain the original dispatch slots here.
inline void FreeAudioMemory(hkMemoryAllocator* allocator, void* memory, unsigned int size) throw()
{
    typedef void (__thiscall* FreeFn)(hkMemoryAllocator*, void*, unsigned int);
    reinterpret_cast<FreeFn>((*reinterpret_cast<void***>(allocator))[2])(allocator, memory, size);
}
inline void FreeAudioArray(hkMemoryAllocator* allocator, void* memory, unsigned int size) throw()
{
    typedef void (__thiscall* FreeFn)(hkMemoryAllocator*, void*, unsigned int);
    reinterpret_cast<FreeFn>((*reinterpret_cast<void***>(allocator))[4])(allocator, memory, size);
}

extern __declspec(thread) int g_tlsMemContext;
inline AutoMemContext::AutoMemContext()
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(g_tlsMemContext);
    g_tlsMemContext = 16;
}
inline AutoMemContext::AutoMemContext(int value)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(g_tlsMemContext);
    g_tlsMemContext = value;
}
inline AutoMemContext::~AutoMemContext() { g_tlsMemContext = m_eMemoryContext; }

// Retain the allocation symbol already bound by the fixed build recipe.
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int size);
};
inline void* MemoryManager::Allocate(unsigned int size)
{
    return reinterpret_cast<MemoryManagerAllocHelper*>(this)->Allocate(size);
}

// src/staging/blk_00cc0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

void __fastcall ReleaseOstreamOwner(hkReferencedObject* owner);
extern "C" void* DAT_010c9314;

// @fnv 0x00cc00b0
hkOstream* __fastcall InitializeOstream(hkOstream* self, void*, void* owner)
{
    self->m_sReferenceCount = 1;
    *reinterpret_cast<void**>(self) = &DAT_010c9314;
    self->m_pStreamWriter = static_cast<hkStreamWriter*>(owner);
    if (owner)
        ReleaseOstreamOwner(static_cast<hkReferencedObject*>(owner));
    return self;
}

extern "C" void __cdecl _delete(void* p, int flags);

void __cdecl FUN_00cc1520();

struct FUN_00cc1710_Class {
    FUN_00cc1710_Class* __thiscall FUN_00cc1710(int a);
};

// Calls FUN_00cc1520, then if bit 0 of a is set frees this with _delete, and returns this.
// @fnv 0x00cc1710
FUN_00cc1710_Class* __thiscall FUN_00cc1710_Class::FUN_00cc1710(int aiFlags)
{
    FUN_00cc1520();
    if (aiFlags & 1)
        _delete(this, 24);
    return this;
}

struct FUN_00cc1970 : NiExtraData {
    void LoadBinary(NiStream& stream);
};
// @fnv 0x00cc1970
void FUN_00cc1970::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    stream.ReadUnsignedInteger();
}

struct FUN_00a7b290_shell
{
    bool FUN_00a7b290(NiStream* apStream);
};

struct FUN_00cc1990_class : FUN_00a7b290_shell
{
    bool bhkExtraData_RegisterStreamables(NiStream* apStream);
};

// @fnv 0x00cc1990
// src: XBOX_PDB 0x00cc1990
bool FUN_00cc1990_class::bhkExtraData_RegisterStreamables(NiStream* apStream)
{
    bool bResult = FUN_00a7b290(apStream);

    unsigned int ItemUpdateArray = *(unsigned int*)((char*)this + 0x1c);
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        void* pObject = *(void**)(*(char**)((char*)this + 0x10) + i * 4);
        if (pObject)
        {
            void** ppVtbl = *(void***)pObject;
            ((void (__thiscall*)(void*, NiStream*))ppVtbl[21])(pObject, apStream);
        }
    }

    return bResult;
}

extern "C" void NiFreeAlias(void*);
extern int DAT_010c9490;

struct FUN_00cc1ab0_class {
    void __thiscall DestroyAndFreeAlias();
};

// @fnv 0x00cc1ab0
void __thiscall FUN_00cc1ab0_class::DestroyAndFreeAlias()
{
    *(int**)this = &DAT_010c9490;
    NiFreeAlias(*(void**)((char*)this + 4));
}

void __cdecl FUN_00cc1e40();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00cc1f60_Class {
    void* __thiscall FUN_00cc1f60(bool flag);
};

// Calls FUN_00cc1e40, then deletes this (size 0x24) when flag bit 0 is set, and returns this.
// @fnv 0x00cc1f60
void* __thiscall FUN_00cc1f60_Class::FUN_00cc1f60(bool flag)
{
    FUN_00cc1e40();
    if (flag & 1)
        operator delete(this, 0x24);
    return this;
}

void __cdecl FUN_00cc2ac0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc2b40_class {
    FUN_00cc2b40_class* __thiscall FUN_00cc2b40(int flag);
};
// Calls FUN_00cc2ac0, frees this with operator delete when flag bit 0 is set, and returns this.
// @fnv 0x00cc2b40
FUN_00cc2b40_class* __thiscall FUN_00cc2b40_class::FUN_00cc2b40(int flag)
{
    FUN_00cc2ac0();
    if (flag & 1)
        operator delete(this, 0x10);
    return this;
}

namespace fnv_00cc3a30 {
extern "C" void __cdecl _delete(void*, unsigned int);

void __cdecl FUN_00cc39b0();

struct GSGeometry
{
    GSGeometry();
    ~GSGeometry();
    GSGeometry* FUN_00cc3a30(int flags);
};

// Calls FUN_00cc39b0, deletes this with size 0x10 when flags has bit 0 set, and returns this.
// @fnv 0x00cc3a30
GSGeometry* GSGeometry::FUN_00cc3a30(int flags)
{
    FUN_00cc39b0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc3a30

namespace fnv_00cc5110 {
extern "C" void __cdecl _delete(void* p, size_t size);

void FUN_00cc5090();

struct FUN_00cc5110_Class {
    FUN_00cc5110_Class* FUN_00cc5110(int flags);
};

// Calls FUN_00cc5090, then deletes this with size 0x10 if flags has bit 0 set, and returns this.
// @fnv 0x00cc5110
FUN_00cc5110_Class* FUN_00cc5110_Class::FUN_00cc5110(int flags)
{
    FUN_00cc5090();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc5110

namespace fnv_00cc74e0 {
extern "C" void __cdecl operator delete(void*, unsigned int);

void __cdecl FUN_00cc7450();

struct FUN_00cc74e0_Class {
    void __thiscall FUN_00cc7450();
    void* __thiscall FUN_00cc74e0(int flags);
};

// Calls FUN_00cc7450, then deletes this with size 16 when flags has bit 0 set, and returns this.
// @fnv 0x00cc74e0
void* __thiscall FUN_00cc74e0_Class::FUN_00cc74e0(int flags)
{
    FUN_00cc7450();
    if (flags & 1)
        operator delete(this, 16);
    return this;
}
}  // namespace fnv_00cc74e0

namespace fnv_00cc8500 {
extern "C" void __cdecl _delete(void*, unsigned int);

struct FUN_00cc8500_class {
    void FUN_00cc8480();
    void* FUN_00cc8500(int flags);
};

// Calls FUN_00cc8480, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00cc8500
void* FUN_00cc8500_class::FUN_00cc8500(int flags)
{
    FUN_00cc8480();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc8500

struct MM { void Deallocate(void*); };
extern MM g_memoryManager;
extern int DAT_0108ffb4;
struct FUN_009ba5f0_shell { void SetChildObject(int); };
struct FUN_00cc8920_shell : FUN_009ba5f0_shell {
    int* m_p;
    FUN_00cc8920_shell* FUN_00cc8920(int a);
};
// Sets m_p to DAT_0108ffb4, calls SetChildObject(0), and if bit 0 of a is set deallocates this via g_memoryManager, returning this.
// @fnv 0x00cc8920
FUN_00cc8920_shell* FUN_00cc8920_shell::FUN_00cc8920(int a)
{
    m_p = &DAT_0108ffb4;
    SetChildObject(0);
    if (a & 1)
        ((MemoryManager*)&g_memoryManager)->Deallocate(this);
    return this;
}

namespace fnv_00cc8d80 {
void FUN_00d53220();

extern "C" void __cdecl operator delete(void*, unsigned int);

struct FUN_00cc8d80_class {
    FUN_00cc8d80_class* __thiscall FUN_00cc8d80(int);
};

// Calls FUN_00d53220, deletes this with size 0x10 when bit 0 of arg is set, and returns this.
// @fnv 0x00cc8d80
FUN_00cc8d80_class* __thiscall FUN_00cc8d80_class::FUN_00cc8d80(int arg)
{
    FUN_00d53220();
    if (arg & 1)
        operator delete(this, 0x10);
    return this;
}
}  // namespace fnv_00cc8d80

void __cdecl FUN_00cc8ce0();
void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00cc8da0_Class {
    FUN_00cc8da0_Class* FUN_00cc8da0(bool b);
};
// Calls FUN_00cc8ce0, then deletes this object with size 16 when b has bit 0 set, and returns this.
// @fnv 0x00cc8da0
FUN_00cc8da0_Class* FUN_00cc8da0_Class::FUN_00cc8da0(bool b)
{
    FUN_00cc8ce0();
    if (b & 1)
        operator delete(this, 16);
    return this;
}

extern "C" void __cdecl _delete(void*, int);
extern "C" void __cdecl FUN_00d54e60();

struct FUN_00ccb160_class {
    void* __thiscall FUN_00ccb160(int arg);
};

// @fnv 0x00ccb160
void* __thiscall FUN_00ccb160_class::FUN_00ccb160(int arg)
{
    FUN_00d54e60();
    if (arg & 1)
        _delete(this, 0x14);
    return this;
}

void __cdecl FUN_00ccbc00();

void __cdecl _delete(void*, unsigned int);

struct FUN_00ccc420_class {
    void* __thiscall FUN_00ccc420(int);
};

// Calls FUN_00ccbc00, then if bit 0 of a is set frees this with size 0x18, and returns this.
// @fnv 0x00ccc420
void* __thiscall FUN_00ccc420_class::FUN_00ccc420(int aiFlags)
{
    FUN_00ccbc00();
    if (aiFlags & 1)
        _delete(this, 0x18);
    return this;
}

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00ccc720_holder {
    void FUN_00ccc720();
    void* __thiscall DestroyHolder(int arg);
};

// Calls FUN_00ccc720, then frees this with operator delete when arg has bit 0 set, and returns this.
// @fnv 0x00cccfb0
void* __thiscall FUN_00ccc720_holder::DestroyHolder(int aiFlags)
{
    FUN_00ccc720();
    if (aiFlags & 1)
        operator delete(this, 0x10);
    return this;
}

void FUN_00ccd080();

void __cdecl operator delete(void* p, unsigned int size);

struct FUN_00ccd150_cls {
    FUN_00ccd150_cls* __thiscall FUN_00ccd150(int flags);
};

// Calls FUN_00ccd080, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00ccd150
FUN_00ccd150_cls* __thiscall FUN_00ccd150_cls::FUN_00ccd150(int flags)
{
    FUN_00ccd080();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

extern "C" void __cdecl _delete(void*, int);

struct FUN_00ccf870_class {
    int FUN_00ccf740();
    int FUN_00ccf870(int flags);
};

// @fnv 0x00ccf870
int FUN_00ccf870_class::FUN_00ccf870(int flags)
{
    FUN_00ccf740();
    if (flags & 1)
        _delete((void*)this, 0x14);
    return (int)this;
}

extern float DAT_0104da48;

struct FUN_00cd3290_class {
    void bhkCharacterPointCollector_reset();
};

// @fnv 0x00cd3290
// src: XBOX_PDB 0x00cd3290
void FUN_00cd3290_class::bhkCharacterPointCollector_reset()
{
    *(float*)((char*)this + 4) = DAT_0104da48;
    *(int*)((char*)this + 0x14) = 0;
}

namespace fnv_00cd7f30 {
extern "C" void __cdecl _delete(void*, unsigned int);

void __cdecl FUN_00ccdbc0();

struct FUN_00cd7f30_class {
    FUN_00cd7f30_class* __thiscall FUN_00cd7f30(unsigned char flags);
};

// Calls FUN_00ccdbc0, then frees this with _delete when bit 0 of flags is set, and returns this.
// @fnv 0x00cd7f30
FUN_00cd7f30_class* __thiscall FUN_00cd7f30_class::FUN_00cd7f30(unsigned char flags)
{
    FUN_00ccdbc0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}
}  // namespace fnv_00cd7f30

struct FUN_00cdea00_cls {
    void __thiscall hkpRagdollConstraintData_setConeLimitStabilization(char param_2);
};

// @fnv 0x00cdea00
// src: HAVOK_LIB 0x00cdea00
void __thiscall FUN_00cdea00_cls::hkpRagdollConstraintData_setConeLimitStabilization(char param_2)
{
    ((char*)this)[0x116] = (param_2 != 0) * 0x38;
}

struct FUN_00cdf250_class {
    void __thiscall hkMatrix3_setMul(int* a, int b);
    void __thiscall hkpRagdollConstraintData_setTargetRelativeOrientationOfBodies(int a);
};

// @fnv 0x00cdf250
// src: HAVOK_LIB 0x00cdf250
void __thiscall FUN_00cdf250_class::hkpRagdollConstraintData_setTargetRelativeOrientationOfBodies(int a)
{
    ((FUN_00cdf250_class*)((char*)this + 0xb0))->hkMatrix3_setMul((int*)a, (int)((char*)this + 0x20));
}

namespace fnv_00cdf7a0 {
extern int DAT_0102e388;
extern int DAT_010c82a4;

struct FUN_00cdf7a0Class {
    int m_vtbl;
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    hkReferencedObject* m_ref;
    void UpdateFields_00cdf7a0();
};
// @fnv 0x00cdf7a0
// src: GUESS 0x00cdf7a0 (confidence: low)
void FUN_00cdf7a0Class::UpdateFields_00cdf7a0()
{
    hkReferencedObject* ref = m_ref;
    *(int*)this = (int)&DAT_010c82a4;
    ref->removeReference();
    *(int*)this = (int)&DAT_0102e388;
}
}  // namespace fnv_00cdf7a0

void __cdecl NiFreeAlias(void* p);
extern MM g_memoryManager;
struct FUN_00cc19e0_class {
    void* m_kPointA;
    void* m_p;
    void* __thiscall FUN_00cc19e0(bool flag);
};
// @fnv 0x00cc19e0
void* __thiscall FUN_00cc19e0_class::FUN_00cc19e0(bool abFree)
{
    void* p = m_p;
    m_kPointA = &DAT_010c9490;
    NiFreeAlias(p);
    if (abFree & 1) g_memoryManager.Deallocate(this);
    return this;
}

extern int DAT_0126810c;
extern int DAT_01268238;
extern int DAT_01268208;
extern int DAT_012685a0;
extern int DAT_01030394;
extern int DAT_0103078c;
extern int DAT_010306b4;
extern int DAT_010c4694;
struct BhkReferenceState {
    BhkReferenceState* Initialize();
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned char m_bFlag;
};
struct FUN_00cc23c0_class {
    BhkReferenceState* __thiscall InitializeRefObject();
};
// Calls Initialize, sets the vtable and clears data fields and a flag, incrementing four global counters along the way.
// @fnv 0x00cc23c0
BhkReferenceState* __thiscall FUN_00cc23c0_class::InitializeRefObject()
{
    BhkReferenceState* self = (BhkReferenceState*)this;
    self->Initialize();
    self->m_pVtable = (void*)&DAT_01030394;
    self->m_uiData1 = 0;
    self->m_uiData2 = 0;
    DAT_0126810c += 1;
    self->m_pVtable = (void*)&DAT_0103078c;
    DAT_01268238 += 1;
    self->m_pVtable = (void*)&DAT_010306b4;
    DAT_01268208 += 1;
    self->m_bFlag = 0;
    self->m_pVtable = (void*)&DAT_010c4694;
    DAT_012685a0 += 1;
    self->m_bFlag = 0;
    return self;
}

struct FUN_00cc3d30_class {
    void* m_p;
    void* m_pUnk0;
    void* m_pUnk1;
    void* m_pData;
    void __thiscall FreeDataIfRequested(bool flag);
};

// If flag is set, deallocates the block preceding m_pData and clears m_pData.
// @fnv 0x00cc3d30
void __thiscall FUN_00cc3d30_class::FreeDataIfRequested(bool abFree)
{
    if (abFree) {
        if (m_pData)
            g_memoryManager.Deallocate((char*)m_pData - *(unsigned char*)((char*)m_pData - 1));
        m_pData = 0;
    }
}

void __fastcall ReleaseConstraint(bhkConstraint* constraint);
extern int DAT_0126860c;
struct FUN_00cc66b0 : bhkConstraint {
    ~FUN_00cc66b0();
};
// @fnv 0x00cc66b0
FUN_00cc66b0::~FUN_00cc66b0()
{
    ReleaseConstraint(this);
    --DAT_0126860c;
}

namespace fnv_00cca950 {
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_01268660;
extern int DAT_01030bf4;
extern int DAT_01030b0c;
extern int DAT_01030a24;
extern int DAT_010ca3f4;
struct BhkReferenceState {
    BhkReferenceState* __thiscall Initialize();
};
struct FUN_00cca950_class {
    void* m_ppVirtualMethodTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiValue2;
    unsigned int m_uiExtra2;
    FUN_00cca950_class* bhkTriangleShape_bhkTriangleShape();
};
// @fnv 0x00cca950
// src: EXE 0x00cca950
FUN_00cca950_class* FUN_00cca950_class::bhkTriangleShape_bhkTriangleShape()
{
    ((BhkReferenceState*)this)->Initialize();
    m_uiValue2 = 0;
    m_uiExtra2 = 0;
    m_ppVirtualMethodTable = (void*)&DAT_01030bf4;
    ++DAT_012680f8;
    m_ppVirtualMethodTable = (void*)&DAT_01030b0c;
    ++DAT_01268274;
    m_ppVirtualMethodTable = (void*)&DAT_01030a24;
    ++DAT_01268250;
    m_ppVirtualMethodTable = (void*)&DAT_010ca3f4;
    ++DAT_01268660;
    return this;
}
}  // namespace fnv_00cca950

extern "C" void __cdecl FUN_00d54e60();
extern "C" void __cdecl _delete(void*, int);
extern int DAT_010ca4dc;
extern int DAT_0126866c;

struct FUN_00ccb180_class {
    int* m_p;
    FUN_00ccb180_class* __thiscall FUN_00ccb180(int flag);
};

// Resets m_p to DAT_010ca4dc, decrements DAT_0126866c, calls FUN_00d54e60, and deletes this when flag bit 0 is set.
// @fnv 0x00ccb180
FUN_00ccb180_class* __thiscall FUN_00ccb180_class::FUN_00ccb180(int flag)
{
    m_p = &DAT_010ca4dc;
    --DAT_0126866c;
    FUN_00d54e60();
    if (flag & 1)
        _delete(this, 20);
    return this;
}

namespace fnv_00ccd100 {
extern int DAT_01030a24;
extern int DAT_01030b0c;
extern int DAT_01030bf4;
extern int DAT_010ca834;
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_0126868c;
struct BhkReferenceState {
    void* m_pVtable;
    int m_iRefCount;
    int m_iUnk;
    int m_iUnk2;
    int m_iUnk3;
    BhkReferenceState* __thiscall Initialize();
    BhkReferenceState* __thiscall InitializeFields_00ccd100();
};
// Calls Initialize, zeroes m_iUnk2 and m_iUnk3, assigns four successive vtables and increments four counters, then returns this.
// @fnv 0x00ccd100
// src: GUESS 0x00ccd100 (confidence: low)
BhkReferenceState* __thiscall BhkReferenceState::InitializeFields_00ccd100()
{
    Initialize();
    m_iUnk2 = 0;
    m_iUnk3 = 0;
    m_pVtable = &DAT_01030bf4;
    ++DAT_012680f8;
    m_pVtable = &DAT_01030b0c;
    ++DAT_01268274;
    m_pVtable = &DAT_01030a24;
    ++DAT_01268250;
    m_pVtable = &DAT_010ca834;
    ++DAT_0126868c;
    return this;
}
}  // namespace fnv_00ccd100

namespace fnv_00cce990 {
struct BhkReferenceState {
    void* m_ppVirtualMethodTable;
    int m_iRefCount;
    int m_iFlags;
    int m_iUnk;
    int m_iUnk2;
    BhkReferenceState* Initialize();
};
extern int DAT_012680f8;
extern int DAT_01268274;
extern int DAT_01268250;
extern int DAT_012686ac;
extern int DAT_01030bf4;
extern int DAT_01030b0c;
extern int DAT_01030a24;
extern int DAT_010caa0c;
struct FUN_00cce990_shell : BhkReferenceState {
    BhkReferenceState* UpdateState_00cce990();
};
// @fnv 0x00cce990
// src: GUESS 0x00cce990 (confidence: low)
BhkReferenceState* FUN_00cce990_shell::UpdateState_00cce990()
{
    Initialize();
    m_iUnk = 0;
    m_iUnk2 = 0;
    m_ppVirtualMethodTable = (void*)&DAT_01030bf4;
    DAT_012680f8 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_01030b0c;
    DAT_01268274 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_01030a24;
    DAT_01268250 += 1;
    m_ppVirtualMethodTable = (void*)&DAT_010caa0c;
    DAT_012686ac += 1;
    return this;
}
}  // namespace fnv_00cce990

namespace fnv_00ccf7c0 {
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_01268274;
extern int DAT_012686c0;
extern int DAT_01030bf4;
extern int DAT_01030b0c;
extern int DAT_01030a24;
extern int DAT_010cabdc;
struct BhkReferenceState {
    BhkReferenceState* __thiscall Initialize();
    void* m_pVtable;
    int m_iRefCount;
    int m_iUnk;
    int m_iUnk2;
    int m_iUnk3;
};
struct FUN_00ccf7c0_class : BhkReferenceState {
    FUN_00ccf7c0_class* bhkConvexListShape_bhkConvexListShape();
};
// Calls Initialize, zeroes m_iUnk2 and m_iUnk3, sets m_pVtable through four vtable assignments and increments four counters, then returns this.
// @fnv 0x00ccf7c0
// src: EXE 0x00ccf7c0
FUN_00ccf7c0_class* FUN_00ccf7c0_class::bhkConvexListShape_bhkConvexListShape()
{
    Initialize();
    m_iUnk2 = 0;
    m_iUnk3 = 0;
    m_pVtable = (void*)&DAT_01030bf4;
    ++DAT_012680f8;
    m_pVtable = (void*)&DAT_01030b0c;
    ++DAT_01268274;
    m_pVtable = (void*)&DAT_01030a24;
    ++DAT_01268250;
    m_pVtable = (void*)&DAT_010cabdc;
    ++DAT_012686c0;
    return this;
}
}  // namespace fnv_00ccf7c0

void __cdecl IncRefCountAllEntries();
void __cdecl ReleaseAllNodes();
struct H_00c8c810 { void __thiscall bhkShape_Link(bool); };
struct FUN_00ccfe20_class {
    void __thiscall bhkConvexListShape_Link(bool a);
};
// Calls IncRefCountAllEntries when a is true, otherwise ReleaseAllNodes, then forwards a to FUN_00c84e50 on this.
// @fnv 0x00ccfe20
// src: XBOX_PDB 0x00ccfe20
void __thiscall FUN_00ccfe20_class::bhkConvexListShape_Link(bool a)
{
    if (a)
        IncRefCountAllEntries();
    else
        ReleaseAllNodes();
    ((H_00c8c810*)this)->bhkShape_Link(a);
}

// @fnv 0x00cde9f0
// src: HAVOK_LIB 0x00cde9f0
void __fastcall hkpRagdollConstraintData_setMaxFrictionTorque(void* self, int, float v)
{
    *(float*)((char*)self + 0xf8) = v;
}

void __stdcall SetContactNormal(int a, int b);
// @fnv 0x00cdea70
// src: COMMUNITY 0x00cdea70
void __stdcall hkpRagdollConstraintData_setTwistMotor(int param_1)
{
    SetContactNormal(0, param_1);
}

void __stdcall SetContactNormal(int a, int b);
// @fnv 0x00cdea90
// src: HAVOK_LIB 0x00cdea90
void __stdcall hkpRagdollConstraintData_setConeMotor(int param_1)
{
    SetContactNormal(2, param_1);
}

struct FUN_00cdf290_cls {
    void __thiscall SetFlagAndClearFloats(int a, char b);
};

// Stores b at offset 0xa2 and its inverse at 0xf2, then zeroes twelve floats at the object reached via a+0x30 when present.
// @fnv 0x00cdf290
void __thiscall FUN_00cdf290_cls::SetFlagAndClearFloats(int a, char b)
{
    ((char*)this)[0xa2] = b;
    ((char*)this)[0xf2] = !b;
    if (a && *(int*)(a + 0x30) && *(int*)(*(int*)(a + 0x30) + 0x1c)) {
        float* p = (float*)(*(int*)(*(int*)(a + 0x30) + 0x1c) + 0x18);
        *p = 0.0f;
        *(p + 1) = 0.0f;
        *(p + 2) = 0.0f;
        *(p + 3) = 0.0f;
        *(p + 4) = 0.0f;
        *(p + 5) = 0.0f;
        *(p - 6) = 0.0f;
        *(p - 5) = 0.0f;
        *(p - 4) = 0.0f;
        *(p - 3) = 0.0f;
        *(p - 2) = 0.0f;
        *(p - 1) = 0.0f;
    }
}

struct MyObj { void* m_kPointA; void* m_kPointB; void* m_iThirdValue; };
struct OutS {
    bhkLimitedHingeVector_blk_00cc0000_o2 m_kPointA;
    bhkLimitedHingeVector_blk_00cc0000_o2 m_kPointB;
    bhkLimitedHingeVector_blk_00cc0000_o2 m_iThirdValue;
};
void __fastcall bhkConvexShape_CopyCinfo(MyObj* self, int, OutS* out);
// @fnv 0x00ccaa30
void __fastcall CopyHingeVectors(MyObj* self, int edx, OutS* out) {
    bhkConvexShape_CopyCinfo(self, edx, out);
    if (self && *(void**)((char*)self + 8) && (const char*)*(void**)((char*)self + 8) + 0x20) {
        const char* p = (const char*)*(void**)((char*)self + 8) + 0x20;
        ((bhkLimitedHingeVector_blk_00cc0000_o2*)((char*)out + 0x10))->SetQuaternionComponentsFromVector((const float*)p);
        ((bhkLimitedHingeVector_blk_00cc0000_o2*)((char*)out + 0x20))->SetQuaternionComponentsFromVector((const float*)(p + 0x10));
        ((bhkLimitedHingeVector_blk_00cc0000_o2*)((char*)out + 0x30))->SetQuaternionComponentsFromVector((const float*)(p + 0x20));
    }
}

namespace fnv_00ccb1b0 {
struct MyObj {
    void bhkShape_CopyCinfo(void*);
};
struct FUN_00ccb1b0_class {
    void bhkPlaneShape_CopyCinfo(void* apStream);
};
// @fnv 0x00ccb1b0
// src: XBOX_PDB 0x00ccb1b0
void FUN_00ccb1b0_class::bhkPlaneShape_CopyCinfo(void* apStream)
{
    ((MyObj*)this)->bhkShape_CopyCinfo(apStream);
    if (this && *(void**)((char*)this + 8)) {
        void* p = *(void**)((char*)this + 8);
        ((bhkLimitedHingeVector_blk_00cc0000_o2*)((char*)apStream + 0x30))->SetQuaternionComponentsFromVector((const float*)((char*)p + 0x20));
        ((bhkLimitedHingeVector_blk_00cc0000_o2*)((char*)apStream + 0x20))->SetQuaternionComponentsFromVector((const float*)((char*)p + 0x30));
        p = (char*)p + 0x10;
        ((bhkLimitedHingeVector_blk_00cc0000_o2*)((char*)apStream + 0x10))->SetQuaternionComponentsFromVector((const float*)p);
    }
}
}  // namespace fnv_00ccb1b0

extern int _data_011c16bc;
struct FUN_00cce990 {
    void* m_p;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cce990();
    static void* __cdecl operator new(unsigned int size);
};
struct FadeNodeState {
    static void* __cdecl operator new(unsigned int size);
};
// Allocates and returns a new FUN_00cce990 object via its operator new.
// @fnv 0x00ccea70
// src: EXE 0x00ccea70
FUN_00cce990* __stdcall bhkConvexTransformShape_CreateObject()
{
    return new FUN_00cce990;
}

struct FUN_00ccf060_stub { void __thiscall ReleaseActiveResource(); };
struct FUN_00ccf100_class : H_00c8c810 {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    void* m_pData;
    void bhkConvexTransformShape_Link(bool flag);
};

// @fnv 0x00ccf100
// src: XBOX_PDB 0x00ccf100
void FUN_00ccf100_class::bhkConvexTransformShape_Link(bool abAddRef)
{
    if (abAddRef) {
        if (this && m_pData) {
            void* p1 = *(void**)((char*)m_pData + 0x18);
            if (p1) {
                void* p2 = *(void**)((char*)p1 + 8);
                if (p2) {
                    InterlockedIncrement((long*)((char*)p2 + 4));
                    bhkShape_Link(abAddRef);
                    return;
                }
            }
        }
    } else {
        ((FUN_00ccf060_stub*)this)->ReleaseActiveResource();
    }
    bhkShape_Link(abAddRef);
}

extern int DAT_0102016c;
extern int DAT_010c5ef4;
extern int DAT_010c955c;
extern int DAT_01268154;
extern int DAT_01268194;
extern int DAT_012685ac;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base {
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    S_00cb79d0_Base();
};

struct DerivedStandin : A51BF0Base, S_00cb79d0_Base {
    unsigned int m_uiField3;

    DerivedStandin()
        : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c955c);
        DAT_012685ac += count;
    }
};

// Allocates and constructs a DerivedStandin object, returning its pointer.
// @fnv 0x00cc2bc0
void* CreateDerivedStandin()
{
    return new DerivedStandin;
}

struct FUN_00cc4180_Class {
    void __thiscall FUN_00cc4180();
    void* __thiscall FUN_00cc4200(int flag);
};
// @fnv 0x00cc4200
void* FUN_00cc4180_Class::FUN_00cc4200(int flag)
{
    FUN_00cc4180();
    if (flag & 1)
        _delete(this, 16);
    return this;
}

struct FUN_00cc47f0_t {
    void __thiscall FUN_00cc47f0();
    FUN_00cc47f0_t* __thiscall FUN_00cc48e0(int a);
};
// Calls FUN_00cc47f0, then deletes this with size 0x10 when bit 0 of a is set, and returns this.
// @fnv 0x00cc48e0
FUN_00cc47f0_t* __thiscall FUN_00cc47f0_t::FUN_00cc48e0(int aiFlags)
{
    FUN_00cc47f0();
    if (aiFlags & 1)
        _delete(this, 0x10);
    return this;
}

extern int DAT_010c99e0;
struct FUN_00cc4990 {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc4990();
};
// @fnv 0x00cc4990
FUN_00cc4990::FUN_00cc4990()
{
    m_uiRefCount = 0;
    m_uiValue1 = 1;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_pVtable = &DAT_010c99e0;
}

namespace fnv_00cc5130 {
extern int DAT_0108febc;
extern int DAT_01268188;
extern int DAT_010c9a14;
extern int DAT_012685e8;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct Derived5130 : S_00cb79d0_Base {
    int* m_p;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    int m_cByteAtOffset3;

    Derived5130()
    {
        m_p = &DAT_0108febc;
        m_cByteAtOffset3 = 0;
        ++DAT_01268188;
        m_p = &DAT_010c9a14;
        ++DAT_012685e8;
    }
};

// Allocates and constructs a Derived5130 object, returning the new instance.
// @fnv 0x00cc5130
void* CreateDerived5130()
{
    return new Derived5130;
}
}  // namespace fnv_00cc5130

extern int DAT_010c9af0;

struct FUN_00cc51c0 {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc51c0();
};

// @fnv 0x00cc51c0
FUN_00cc51c0::FUN_00cc51c0()
{
    m_uiRefCount = 0;
    m_uiValue1 = 1;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_pVtable = &DAT_010c9af0;
}

struct FUN_00cc5f10_Class {
    void __thiscall FUN_00cc5e60();
    FUN_00cc5f10_Class* __thiscall FUN_00cc5f10(unsigned int flag);
};

// @fnv 0x00cc5f10
FUN_00cc5f10_Class* FUN_00cc5f10_Class::FUN_00cc5f10(unsigned int flag)
{
    FUN_00cc5e60();
    if (flag & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_00cc60b0 {
extern int DAT_0108febc;
extern int DAT_010c9b0c;
extern int DAT_01268188;
extern int DAT_01268600;

struct A51BF0Base {
    void* m_pVtable;
    unsigned char m_ucUnknownByte[8];

    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct FUN_cc60b0_object : S_00cb79d0_Base {
    unsigned int m_uiCurrentValue;

    FUN_cc60b0_object();
};

FUN_cc60b0_object::FUN_cc60b0_object()
    : S_00cb79d0_Base()
{
    m_pVtable = &DAT_0108febc;
    m_uiCurrentValue = 0;
    ++DAT_01268188;
    m_pVtable = &DAT_010c9b0c;
    ++DAT_01268600;
}

// Allocates and constructs a new FUN_cc60b0_object, returning its pointer.
// @fnv 0x00cc60b0
// src: EXE 0x00cc60b0
void* __cdecl bhkRagdollLimitsConstraint_CreateObject()
{
    return new FUN_cc60b0_object;
}
}  // namespace fnv_00cc60b0


NiPoint3& __cdecl HK2NINS(NiPoint3& result, hkVector4 const& value);

char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

extern double const DAT_0102f248;

struct FUN_00cc7090_Constraint {
    unsigned char m_pad0000[0x20];
    hkVector4 m_twistAxisA;
    hkVector4 m_planeAxisA;
    unsigned char m_pad0040[0x10];
    hkVector4 m_kPivotInA;
    hkVector4 m_twistAxisB;
    hkVector4 m_planeAxisB;
    unsigned char m_pad0080[0x10];
    hkVector4 m_kPivotInB;
    unsigned char m_pad00A0[0x58];
    float m_fMaxFrictionTrq;
    unsigned char m_pad00FC[0x08];
    float m_fTwistMinAngle;
    float m_fTwistMaxAngle;
    unsigned char m_pad010C[0x10];
    float m_fConeMinAngle;
    unsigned char m_pad0120[0x0C];
    float m_fPlaneMinAngle;
    float m_fPlaneMaxAngle;
};

struct FUN_00cc7090_class {
    void* m_pVtable;
    FUN_00cc7090_Constraint* m_pConstraint;

    void __thiscall hkConstraintCinfo_GetViewerStrings(StrArr* strArr);
    void __thiscall AppendConstraintParams(StrArr* strArr);
};

// @fnv 0x00cc7090
void FUN_00cc7090_class::AppendConstraintParams(StrArr* strArr)
{
    this->hkConstraintCinfo_GetViewerStrings(strArr);

    FUN_00cc7090_Constraint* constraint = m_pConstraint;
    if (!constraint)
        return;

    {
        NiPoint3 point;
        char* value;
        unsigned int index;

        HK2NINS(point, constraint->m_kPivotInA);
        value = static_cast<const NiPoint3&>(point).FormatToBuffer("PivotInA");
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        NiPoint3 point;
        char* value;
        unsigned int index;

        HK2NINS(point, constraint->m_planeAxisA);
        value = static_cast<const NiPoint3&>(point).FormatToBuffer("planeAxisA");
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        NiPoint3 point;
        char* value;
        unsigned int index;

        HK2NINS(point, constraint->m_twistAxisA);
        value = static_cast<const NiPoint3&>(point).FormatToBuffer("twistAxisA");
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        NiPoint3 point;
        char* value;
        unsigned int index;

        HK2NINS(point, constraint->m_kPivotInB);
        value = static_cast<const NiPoint3&>(point).FormatToBuffer("PivotInB");
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        NiPoint3 point;
        char* value;
        unsigned int index;

        HK2NINS(point, constraint->m_planeAxisB);
        value = static_cast<const NiPoint3&>(point).FormatToBuffer("planeAxisB");
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        NiPoint3 point;
        char* value;
        unsigned int index;

        HK2NINS(point, constraint->m_twistAxisB);
        value = static_cast<const NiPoint3&>(point).FormatToBuffer("twistAxisB");
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = NiGetViewerString_00a7d550("ConeMinAngle", constraint->m_fConeMinAngle * DAT_0102f248);
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = NiGetViewerString_00a7d550("PlaneMinAngle", constraint->m_fPlaneMinAngle * DAT_0102f248);
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = NiGetViewerString_00a7d550("PlaneMaxAngle", constraint->m_fPlaneMaxAngle * DAT_0102f248);
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = NiGetViewerString_00a7d550("TwistMinAngle", constraint->m_fTwistMinAngle * DAT_0102f248);
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = NiGetViewerString_00a7d550("TwistMaxAngle", constraint->m_fTwistMaxAngle * DAT_0102f248);
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }

    {
        char* value;
        unsigned int index;

        value = NiGetViewerString_00a7d550("MaxFrictionTrq", constraint->m_fMaxFrictionTrq);
        index = strArr->m_usSize;
        if (index >= strArr->m_usMaxSize)
            strArr->SetSize(strArr->m_usGrowBy + index);
        strArr->SetAt(index, value);
    }
}

namespace fnv_00cc7500 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

extern int DAT_0108febc;
extern int DAT_010c9c84;
extern int DAT_01268188;
extern int DAT_01268618;

struct S_00cb79d0_Base : A51BF0Base {
    void* m_pVtable;
    unsigned int m_uiField1;
    unsigned int m_uiField2;
    unsigned int m_uiField3;

    S_00cb79d0_Base();
};

struct Object_00cc7500 : S_00cb79d0_Base {
    Object_00cc7500()
    {
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiField3 = 0;
        ++DAT_01268188;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c9c84);
        ++DAT_01268618;
    }
};

// Allocates and constructs a new Object_00cc7500, returning the new instance.
// @fnv 0x00cc7500
// src: EXE 0x00cc7500
Object_00cc7500* bhkPrismaticConstraint_CreateObject()
{
    return new Object_00cc7500;
}
}  // namespace fnv_00cc7500

extern int DAT_010c9d60;
struct FUN_00cc7590 {
    void* m_pVtable;
    int m_iRefCount;
    int m_iData1;
    int m_iData2;
    int m_iData3;
    FUN_00cc7590();
};
// @fnv 0x00cc7590
FUN_00cc7590::FUN_00cc7590()
{
    m_iRefCount = 0;
    m_iData1 = 1;
    m_iData2 = 0;
    m_iData3 = 0;
    m_pVtable = (void*)&DAT_010c9d60;
}

extern "C" void __cdecl _delete(void* p, int flags);
extern "C" void __cdecl FUN_00d50020();
struct FUN_00cc7da0_shell {
    FUN_00cc7da0_shell* FUN_00cc7da0(int flags);
};
// Calls FUN_00d50020, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x00cc7da0
FUN_00cc7da0_shell* FUN_00cc7da0_shell::FUN_00cc7da0(int flags)
{
    FUN_00d50020();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern int DAT_010c9f38;
struct FUN_00cc7f10 {
    int* m_pVTable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    FUN_00cc7f10();
};
// @fnv 0x00cc7f10
FUN_00cc7f10::FUN_00cc7f10()
{
    m_uiRefCount = 0;
    m_uiValue1 = 1;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_pVTable = &DAT_010c9f38;
}

namespace fnv_00cc8520 {
extern int DAT_0108febc;
extern int DAT_010c9f74;
extern int DAT_01268188;
extern int DAT_01268630;

struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

struct Object_00cc8520 : S_00cb79d0_Base {
    int* m_pVtable;
    void* m_pA;
    void* m_pB;
    int m_iValue;

    Object_00cc8520()
        : m_pVtable(&DAT_0108febc),
          m_iValue(0)
    {
        ++DAT_01268188;
        m_pVtable = &DAT_010c9f74;
        ++DAT_01268630;
    }
};

// Allocates and constructs a new Object_00cc8520 instance, returning its pointer.
// @fnv 0x00cc8520
// src: EXE 0x00cc8520
void* bhkHingeLimitsConstraint_CreateObject()
{
    return new Object_00cc8520;
}
}  // namespace fnv_00cc8520

struct FUN_00cc94b0_Class {
    void __thiscall FreeSpawnedStorage();
};
struct FUN_00cc9540_Class : FUN_00cc94b0_Class {
    FUN_00cc9540_Class* __thiscall FUN_00cc9540(char flag);
};

// @fnv 0x00cc9540
FUN_00cc9540_Class* FUN_00cc9540_Class::FUN_00cc9540(char flag)
{
    FUN_00cc94b0_Class::FreeSpawnedStorage();
    if (flag & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

namespace fnv_00cc9e60 {
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern int DAT_01030bf4;
extern int _DAT_0104dbac;
extern int DAT_010ca24c;
extern int DAT_012680f8;
extern int _DAT_012682cc;
extern int DAT_01268654;
}

inline bhkShape::bhkShape()
{
    m_0c = 0;
    m_10 = 0;
    *reinterpret_cast<void**>(this) = &fnv_00cc9e60::DAT_01030bf4;
    ++fnv_00cc9e60::DAT_012680f8;
}
inline bhkBvTreeShape::bhkBvTreeShape()
{
    *reinterpret_cast<void**>(this) = &fnv_00cc9e60::_DAT_0104dbac;
    ++fnv_00cc9e60::_DAT_012682cc;
    *reinterpret_cast<void**>(this) = &fnv_00cc9e60::DAT_010ca24c;
    ++fnv_00cc9e60::DAT_01268654;
}
namespace fnv_00cc9e60 {
// Allocates and constructs a new bhkBvTreeShape, returning the pointer.
// @fnv 0x00cc9e60
bhkBvTreeShape* CreateBhkBvTreeShape()
{
    return new bhkBvTreeShape;
}
}  // namespace fnv_00cc9e60

struct FUN_00cca8d0_shell {
    void __thiscall FUN_00cca8d0();
};

struct FUN_00cca9a0_class : FUN_00cca8d0_shell {
    FUN_00cca8d0_shell* __thiscall DestroyOrDelete(int flags);
};

// @fnv 0x00cca9a0
FUN_00cca8d0_shell* FUN_00cca9a0_class::DestroyOrDelete(int flags)
{
    FUN_00cca8d0();
    if (flags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_00cca9c0_class {
    void hkTriangleShapeCinfo_Scale(float scale);
};

// Multiplies the twelve floats starting at offset 0x10 of this object by scale.
// @fnv 0x00cca9c0
// src: XBOX_PDB 0x00cca9c0
void FUN_00cca9c0_class::hkTriangleShapeCinfo_Scale(float scale)
{
    float s = scale;
    float* p = (float*)((char*)this + 0x10);
    p[0] = p[0] * s;
    p[1] *= s;
    p[2] *= s;
    p[3] *= s;
    p[4] *= s;
    p[5] *= s;
    p[6] *= s;
    p[7] *= s;
    p[8] *= s;
    p[9] *= s;
    p[10] *= s;
    p[11] *= s;
}

// @fnv 0x00ccba20
// src: XBOX_PDB 0x00ccba20
bool __fastcall bhkExtendedMeshShapeData_IsEqual(char* p, int, char* q)
{
    return q == p;
}

namespace fnv_00ccbd70 {
struct A51BF0Base {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00cb79d0_Base : A51BF0Base {
    S_00cb79d0_Base();
};

extern int DAT_01030bf4;
extern int DAT_010c44e4;
extern int DAT_010ca744;
extern int DAT_012680f8;
extern int DAT_01268678;
extern int DAT_012686d0;

struct BD70_Object : S_00cb79d0_Base {
    void* m_pVtable;
    int m_unused04;
    int m_unused08;
    int m_field0C;
    int m_field10;
    int m_field14;

    BD70_Object()
    {
        m_pVtable = &DAT_01030bf4;
        m_field0C = 0;
        m_field10 = 0;
        ++DAT_012680f8;
        m_pVtable = &DAT_010c44e4;
        ++DAT_012686d0;
        m_pVtable = &DAT_010ca744;
        m_field14 = 0;
        ++DAT_01268678;
    }
};

// Allocates and constructs a BD70_Object, returning it as an S_00cb79d0_Base pointer.
// @fnv 0x00ccbd70
S_00cb79d0_Base* __cdecl CreateBD70Object()
{
    return new BD70_Object;
}
}  // namespace fnv_00ccbd70

struct FUN_00ccd170_cls {
    void __thiscall UpdateState_00ccd170(float scale);
};

// Multiplies the nine floats starting at offset 0x10 of this object by scale.
// @fnv 0x00ccd170
// src: GUESS 0x00ccd170 (confidence: low)
void __thiscall FUN_00ccd170_cls::UpdateState_00ccd170(float scale)
{
    float s = scale;
    float* p = (float*)((char*)this + 0x10);
    p[0] *= s;
    p[1] *= s;
    p[2] *= s;
    p[3] *= s;
    p[4] *= s;
    p[5] *= s;
    p[6] *= s;
    p[7] *= s;
    p[8] *= s;
}

struct FUN_00ccf570_class
{
    void __thiscall bhkConvexShape_LoadBinary(NiStream* stream);
    void __thiscall bhkConvexSweepShape_LoadBinary(NiStream* stream);
};

// @fnv 0x00ccf570
// src: XBOX_PDB 0x00ccf570
void FUN_00ccf570_class::bhkConvexSweepShape_LoadBinary(NiStream* stream)
{
    NiObject* resolved = stream->DeserializeObject();
    bhkConvexShape_LoadBinary(stream);
    stream->ChangeObject(resolved);
}

extern "C" void __cdecl _delete(void* p, int flags);

struct FUN_00ccf5b0_shell {
    void __thiscall FUN_00ccf4f0();
    FUN_00ccf5b0_shell* __thiscall FUN_00ccf5b0(bool flag);
};

// Calls FUN_00ccf4f0, then frees this with _delete when flag bit 0 is set, and returns this.
// @fnv 0x00ccf5b0
FUN_00ccf5b0_shell* __thiscall FUN_00ccf5b0_shell::FUN_00ccf5b0(bool abFree)
{
    FUN_00ccf4f0();
    if (abFree & 1)
        _delete(this, 0x14);
    return this;
}

namespace fnv_00cd2fd0 {

struct Object {
    void __thiscall bhkShape_GetViewerStrings(StrArr* arr);
    void __thiscall bhkShapeCollection_GetViewerStrings(StrArr* arr);
};

char* __cdecl _FUN_00a7d330(char const* value);

extern char const* const g_012681a8_arg1;

extern __declspec(thread) unsigned char DAT_00cd2fd0[0x2b8];

struct TLSGuard {
    unsigned int m_oldValue;

    TLSGuard()
    {
        m_oldValue = *reinterpret_cast<unsigned int*>(DAT_00cd2fd0 + 0x2b4);
        *reinterpret_cast<unsigned int*>(DAT_00cd2fd0 + 0x2b4) = 0x10;
    }

    ~TLSGuard()
    {
        *reinterpret_cast<unsigned int*>(DAT_00cd2fd0 + 0x2b4) = m_oldValue;
    }
};

// @fnv 0x00cd2fd0
// src: XBOX_PDB 0x00cd2fd0
void Object::bhkShapeCollection_GetViewerStrings(StrArr* pStrArr)
{
    TLSGuard guard;

    this->bhkShape_GetViewerStrings(pStrArr);

    char* value = _FUN_00a7d330(g_012681a8_arg1);
    unsigned int index = pStrArr->m_usSize;

    if (index >= pStrArr->m_usMaxSize)
        pStrArr->SetSize(index + pStrArr->m_usGrowBy);

    pStrArr->SetAt(index, value);
}
}  // namespace fnv_00cd2fd0

extern int DAT_010cb3c4;
struct FUN_00cd44c0_cls {
    int m_vft;
    unsigned short m_kPointA;
    unsigned short m_kPointB;
    FUN_00cd44c0_cls* SetVirtualTable_00cd44c0();
};
// @fnv 0x00cd44c0
// src: GUESS 0x00cd44c0 (confidence: low)
FUN_00cd44c0_cls* FUN_00cd44c0_cls::SetVirtualTable_00cd44c0()
{
    m_kPointB = 1;
    m_vft = (int)&DAT_010cb3c4;
    return this;
}

extern int DAT_010cb3f0;
struct FUN_00cd47e0_t {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned char m_bFlag;
    unsigned short m_usFlags;
    FUN_00cd47e0_t();
};
// @fnv 0x00cd47e0
FUN_00cd47e0_t::FUN_00cd47e0_t()
{
    *(unsigned short*)((char*)this + 6) = 1;
    m_pVtable = (void*)&DAT_010cb3f0;
    m_bFlag = 1;
}




extern "C" void HasFinitePoseValuesEntry();

__forceinline bool* HasFinitePoseValues(hkQsTransform* transform, bool* result)
{
    typedef bool* (__thiscall* CheckFn)(hkQsTransform*, bool*);
    return reinterpret_cast<CheckFn>(&HasFinitePoseValuesEntry)(transform, result);
}

// Checks bone flags and the validity of transforms that are not dirty.
// @fnv 0x00cda090
bool* __fastcall CheckPoseTransforms(hkaPose* pose, int, bool* result)
{
    bool value1;
    bool value2;
    int count = pose->m_pSkeleton->m_kBones.m_iElementCount;

    for (int i = 0; i < count; ++i) {
        if ((pose->m_pBoneFlags[i] & 2) && (pose->m_pBoneFlags[i] & 1)) {
            *result = false;
            return result;
        }

        if (!(pose->m_pBoneFlags[i] & 2)) {
            hkQsTransform* matrix = pose->m_pModelPose.m_data + i;
            if (!*HasFinitePoseValues(matrix, &value1)) {
                *result = false;
                return result;
            }
        }

        if (!(pose->m_pBoneFlags[i] & 1)) {
            hkQsTransform* matrix = pose->m_pLocalPose.m_data + i;
            if (!*HasFinitePoseValues(matrix, &value2)) {
                *result = false;
                return result;
            }
        }
    }

    *result = true;
    return result;
}

// @fnv 0x00cdeab0
// src: HAVOK_LIB 0x00cdeab0
void __stdcall hkpRagdollConstraintData_setPlaneMotor(int a)
{
    SetContactNormal(1, a);
}

// @fnv 0x00cdf270
// src: HAVOK_LIB 0x00cdf270
void __fastcall hkpRagdollConstraintData_getTarget(char* self, int, char* apMatrix)
{
    ((hkMatrix3*)apMatrix)->SetTransposeProduct(self + 0x60, self + 0xb0);
}

template <class T>
inline void CC1AD0BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC1AD0SaveBinary(NiStream& kStream, const T& value) {
    CC1AD0BinaryStreamSave(*OutputStream(kStream), &value);
}

class CC1AD0ListExtra : public NiExtraData {
public:
    unsigned int unk0c;
    NiObject** m_ppkObjects;
    int unk14;
    int unk18;
    unsigned int m_uiCount;

    void bhkExtraData_SaveBinary(NiStream& kStream);
};

// SaveBinary
// Saves the base extra data, writes m_uiCount, then saves a link ID for each non-null object in m_ppkObjects.
// @fnv 0x00cc1ad0
// src: XBOX_PDB 0x00cc1ad0
void CC1AD0ListExtra::bhkExtraData_SaveBinary(NiStream& kStream) {
    NiExtraData::SaveBinary(kStream);
    unsigned int ItemUpdateArray = m_uiCount;
    CC1AD0SaveBinary(kStream, ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        NiObject* pkObject = m_ppkObjects[i];
        if (pkObject)
            kStream.SaveLinkID(reinterpret_cast<const NiObject*>(pkObject));
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct ArrayRefObject {
    virtual void vf0();
    virtual void DeleteThis();
    long volatile refs;
    void DecRefCount() { if (InterlockedDecrement(&refs) == 0) DeleteThis(); }
    void IncRefCount() { InterlockedIncrement(&refs); }
};
void* __cdecl _NiMalloc_00aa1070(unsigned);
void __cdecl _NiFree_00aa10f0(void*);
// 0x00cc1b40 materializes the one-byte comparison result before converting it to bool.
struct ReferenceComparison {
    bool value;
    ReferenceComparison(bool result) : value(result) {}
    operator bool() const { return value; }
};
inline ReferenceComparison HasArrayReference(const NiPointer<ArrayRefObject>& pointer)
{
    return pointer.m_pObject != (ArrayRefObject*)0;
}
struct ReferenceArray {
    void* vtable;
    NiPointer<ArrayRefObject>* data;
    unsigned capacity, used, live;
    void Resize(unsigned);
};
// Resizes the reference array to n slots: releases entries past n, reallocates storage, copies live entries and default-initialises the rest.
// @fnv 0x00cc1b40
void ReferenceArray::Resize(unsigned uiCapacity) {
    if (uiCapacity != capacity) {
        if (uiCapacity < used) {
            for (unsigned i = uiCapacity; i < used; ++i) {
                if (HasArrayReference(data[i])) { data[i] = NiPointer<ArrayRefObject>(); --live; }
            }
            used = uiCapacity;
        }
        NiPointer<ArrayRefObject>* old = data;
        capacity = uiCapacity;
        if (uiCapacity > 0) {
            data = (NiPointer<ArrayRefObject>*)_NiMalloc_00aa1070(uiCapacity * sizeof(NiPointer<ArrayRefObject>));
            for (unsigned i = 0; i < used; ++i) data[i] = old[i];
            for (unsigned i = used; i < capacity; ++i) data[i] = NiPointer<ArrayRefObject>();
        } else data = 0;
        _NiFree_00aa10f0(old);
    }
}

extern int DAT_01268598;

// @fnv 0x00cc1e30
// src: COMMUNITY 0x00cc1e30
int __cdecl bhkExtraData_GetRTTI() {
    return reinterpret_cast<int>(&DAT_01268598);
}

struct FUN_00cc1e40_tls {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00cc1e40_tls g_tls_00cc1e40;

void __cdecl _NiFree_00aa10f0(void* apMemory);

struct Base_00cc1e40 {
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    ~Base_00cc1e40();
};

struct Member_00cc1e40 {
    virtual void unk00();
    void* m_04;
    void Destroy();
    ~Member_00cc1e40() {
        void* p = m_04;
        _NiFree_00aa10f0(p);
    }
};

class FUN_00cc1e40_cls : public Base_00cc1e40 {
public:
    Member_00cc1e40 m_0c;
    virtual ~FUN_00cc1e40_cls();
};

// @fnv 0x00cc1e40
FUN_00cc1e40_cls::~FUN_00cc1e40_cls() {
    {
        AutoMemContext guard;
        m_0c.Destroy();
    }

}

struct FUN_00cc1d80_object {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    FUN_00cc1d80_object();
    static void* __cdecl operator new(unsigned int bytes);
    void __thiscall AssignFixedString(void* value);
};
extern "C" char DAT_011f49e0;
// @fnv 0x00cc1ef0
FUN_00cc1d80_object* __cdecl CreateObjectWithGlobal()
{
    FUN_00cc1d80_object* value = new FUN_00cc1d80_object;
    value->AssignFixedString(&DAT_011f49e0);
    return value;
}

extern __declspec(thread) int g_iCC1F80AllocTag;

extern const char* g_pcCC1F80Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class CC1F80Node {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void CollectNames(StrArr* pkArray);
};

class CC1F80Group {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CC1F80Node** m_ppkChildren;
    int unk14;
    int unk18;
    unsigned int m_uiChildCount;

    void CollectOwnNames(StrArr* pkArray);
    void CollectAllNames(StrArr* pkArray);
};

// @fnv 0x00cc1f80
void CC1F80Group::CollectAllNames(StrArr* pkArray)
{
    AutoMemContext kScope(0x10);
    CollectOwnNames(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCC1F80Name);
    AppendStringReference(pkArray, pcName);

    unsigned int ItemUpdateArray = m_uiChildCount;
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        CC1F80Node* pkChild = m_ppkChildren[i];
        if (pkChild)
            pkChild->CollectNames(pkArray);
    }
}

extern "C" __declspec(thread) unsigned int g_tlsMode;
struct ThreadModeGuard {
    unsigned int previous;
    ThreadModeGuard() : previous(g_tlsMode) { g_tlsMode = 16; }
    ~ThreadModeGuard() { g_tlsMode = previous; }
};
struct OutputBuffer {
    void* unk00; void* unk04; void* unk08;
    struct ListStorage { void __thiscall Resize(unsigned int count); } list;
    void __thiscall AddRefObject(void* value);
};
struct SceneNode {
    virtual void unknown_slot_00();
    virtual void unknown_slot_04();
    virtual void unknown_slot_08();
    virtual void unknown_slot_0c();
    virtual void unknown_slot_10();
    virtual void unknown_slot_14();
    virtual void unknown_slot_18();
    virtual void unknown_slot_1c();
    virtual void unknown_slot_20();
    virtual void unknown_slot_24();
    virtual void unknown_slot_28();
    virtual void unknown_slot_2c();
    virtual void unknown_slot_30();
    virtual void unknown_slot_34();
    virtual void unknown_slot_38();
    virtual void unknown_slot_3c();
    virtual void unknown_slot_40();
    virtual void unknown_slot_44();
    virtual void* ReadValue(void* context);
};
struct SceneList {
    void* unk00; void* unk04; void* unk08; void* unk0c;
    SceneNode** entries;
    void* unk14; void* unk18;
    unsigned int count;
    void __thiscall CopyMembers_00a7b330(OutputBuffer* dest, void* context);
    void __thiscall WriteSceneList(OutputBuffer* dest, void* context);
};
// @fnv 0x00cc2120
void __thiscall SceneList::WriteSceneList(OutputBuffer* dest, void* context) {
    ThreadModeGuard mode;
    CopyMembers_00a7b330(dest, context);
    unsigned int n = count;
    dest->list.Resize(n);
    for (unsigned int i = 0; i < n; ++i) {
        SceneNode* node = entries[i];
        void* value = node;
        if (node) value = node->ReadValue(context);
        dest->AddRefObject(value);
    }
}

void* Object_DispatchCommandFour(unsigned int size);

struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};

extern __declspec(thread) ThreadHeapState g_threadHeapState;

struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard() { saved = g_threadHeapState.m_2b4; g_threadHeapState.m_2b4 = 0x10; }
    ~TlsHeapGuard() { g_threadHeapState.m_2b4 = saved; }
};

class SpawnedThing
{
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    static void* operator new(unsigned int size);
    SpawnedThing();
};

class FUN_00cc22a0_cls
{
public:
    void* CreateAndAttach(unsigned int arg);
    void Attach(SpawnedThing* obj, unsigned int arg);
};

void* SpawnedThing::operator new(unsigned int size)
{
    return Object_DispatchCommandFour(size);
}

// Allocates a SpawnedThing with a TLS heap guard active, attaches it using arg, and returns the new object.
// @fnv 0x00cc22a0
void* FUN_00cc22a0_cls::CreateAndAttach(unsigned int uiValue)
{
    TlsHeapGuard guard;
    SpawnedThing* obj = new SpawnedThing();
    Attach(obj, uiValue);
    return obj;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct RefObject24_b9018 {
    char m00[0x18];
    RefObject24_b9018();
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
};

// Allocates and constructs a RefObject24_b9018 via its operator new and returns the pointer.
// @fnv 0x00cc2410
RefObject24_b9018* CreateRefObject24() {
    return new RefObject24_b9018();
}

struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t(int saved)
    {
        m_saved = saved;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();

class SpawnedObject_t
{
public:
    virtual void unk00();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    void* operator new(unsigned int size);
    SpawnedObject_t();
};

struct FUN_00cc2480_cls
{
    int unk00;
    int unk04;
    void bhkWorldObject_CopyMembers(SpawnedObject_t* obj, unsigned int arg);
    SpawnedObject_t* bhkCachingShapePhantom_CreateClone(unsigned int arg);
};

// @fnv 0x00cc2480
// src: XBOX_PDB 0x00cc2480
SpawnedObject_t* FUN_00cc2480_cls::bhkCachingShapePhantom_CreateClone(unsigned int arg)
{
    TlsGuard_t guard(g_tlsBlock.m_2b4);
    SpawnedObject_t* result = 0;
    bhkSerializable_CloneCritLock();
    result = new SpawnedObject_t();
    bhkWorldObject_CopyMembers(result, arg);
    bhkSerializable_CloneCritUnlock();
    return result;
}

struct ThreadTlsBlock {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) ThreadTlsBlock g_tls;

struct TlsFlagGuard {
    unsigned int m_saved;
    TlsFlagGuard() { m_saved = g_tls.m_2b4; g_tls.m_2b4 = 0x10; }
    ~TlsFlagGuard() { g_tls.m_2b4 = m_saved; }
};

class FUN_00cc2a00_alloc {
public:
    unsigned char* Alloc(unsigned int size);
};
extern FUN_00cc2a00_alloc DAT_011f6238;

class FUN_00cc2a00_obj {
public:
    void Init();
};

class FUN_00cc2a00_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    FUN_00cc2a00_obj* m_08;
    FUN_00cc2a00_obj* m_0c;

    void Attach(FUN_00cc2a00_obj* obj);
    FUN_00cc2a00_obj* bhkShapePhantom_CreateCInfo(bool* out);
};

// Returns m_0c, allocating and initialising a new object first if it is null; sets *out to whether it was created.
// @fnv 0x00cc2a00
// src: COMMUNITY 0x00cc2a00
FUN_00cc2a00_obj* FUN_00cc2a00_cls::bhkShapePhantom_CreateCInfo(bool* abCreated) {
    TlsFlagGuard guard;
    bool created = (m_0c == 0);
    *abCreated = created;
    if (created) {
        unsigned char* p = DAT_011f6238.Alloc(0x70);
        unsigned char adj = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
        p += adj;
        p[-1] = adj;
        FUN_00cc2a00_obj* obj = (FUN_00cc2a00_obj*)p;
        obj->Init();
        m_0c = obj;
        if (m_08 != 0) {
            Attach(obj);
        }
    }
    return m_0c;
}

extern int DAT_012685b0;

// @fnv 0x00cc2b30
// src: COMMUNITY 0x00cc2b30
void* __cdecl bhkSpringAction_GetRTTI()
{
    return &DAT_012685b0;
}

namespace fnv_00cc2c60 {
extern "C" void __cdecl bhkSerializable_CloneCritLock();
extern "C" void __cdecl bhkSerializable_CloneCritUnlock();
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

extern unsigned int g_ctorCount1;
extern unsigned int g_ctorCount2;
extern unsigned int g_ctorCount3;

class NodeRoot_cls {
public:
    NodeRoot_cls();
    virtual void r00();
};

class NodeA_cls : public NodeRoot_cls {
public:
    int unk04;
    int unk08;
    volatile int m_0c;
    NodeA_cls() : NodeRoot_cls() {
        m_0c = 0;
        g_ctorCount1 += 1;
    }
    virtual void a00();
};

class NodeB_cls : public NodeA_cls {
public:
    NodeB_cls() : NodeA_cls() {
        g_ctorCount2++;
    }
    virtual void b00();
};

class NodeC_cls : public NodeB_cls {
public:
    NodeC_cls() : NodeB_cls() {
        g_ctorCount3++;
    }
    virtual void c00();
    static void* operator new(unsigned int size) throw() {
        return Object_DispatchCommandFour(size);
    }
};

class FUN_00cc2c60_cls {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(NodeC_cls* node, int a1);
    NodeC_cls* bhkSpringAction_CreateClone(int a1);
};

// Allocates a NodeC_cls, passes it with a1 to v52, and returns the new node.
// @fnv 0x00cc2c60
// src: XBOX_PDB 0x00cc2c60
NodeC_cls* FUN_00cc2c60_cls::bhkSpringAction_CreateClone(int aiValue) {
    bhkSerializable_CloneCritLock();
    NodeC_cls* p = new NodeC_cls();
    this->v52(p, aiValue);
    bhkSerializable_CloneCritUnlock();
    return p;
}
}  // namespace fnv_00cc2c60

struct Col4 { float r, g, b, a; Col4& operator*=(float s) { r *= s; g *= s; b *= s; a *= s; return *this; } };
struct S_00cc2d20_result {
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    Col4 m_kPointA;
    Col4 m_kPointB;
};

struct S_00cc2d20_argument {
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    float m_f10;
};

struct S_00cc2d20_class {
    virtual void* v00(char*) { return 0; }
    virtual void* v01(char*) { return 0; }
    virtual void* v02(char*) { return 0; }
    virtual void* v03(char*) { return 0; }
    virtual void* v04(char*) { return 0; }
    virtual void* v05(char*) { return 0; }
    virtual void* v06(char*) { return 0; }
    virtual void* v07(char*) { return 0; }
    virtual void* v08(char*) { return 0; }
    virtual void* v09(char*) { return 0; }
    virtual void* v10(char*) { return 0; }
    virtual void* v11(char*) { return 0; }
    virtual void* v12(char*) { return 0; }
    virtual void* v13(char*) { return 0; }
    virtual void* v14(char*) { return 0; }
    virtual void* v15(char*) { return 0; }
    virtual void* v16(char*) { return 0; }
    virtual void* v17(char*) { return 0; }
    virtual void* v18(char*) { return 0; }
    virtual void* v19(char*) { return 0; }
    virtual void* v20(char*) { return 0; }
    virtual void* v21(char*) { return 0; }
    virtual void* v22(char*) { return 0; }
    virtual void* v23(char*) { return 0; }
    virtual void* v24(char*) { return 0; }
    virtual void* v25(char*) { return 0; }
    virtual void* v26(char*) { return 0; }
    virtual void* v27(char*) { return 0; }
    virtual void* v28(char*) { return 0; }
    virtual void* v29(char*) { return 0; }
    virtual void* v30(char*) { return 0; }
    virtual void* v31(char*) { return 0; }
    virtual void* v32(char*) { return 0; }
    virtual void* v33(char*) { return 0; }
    virtual void* v34(char*) { return 0; }
    virtual void* v35(char*) { return 0; }
    virtual void* v36(char*) { return 0; }
    virtual void* v37(char*) { return 0; }
    virtual void* v38(char*) { return 0; }
    virtual void* v39(char*) { return 0; }
    virtual void* v40(char*) { return 0; }
    virtual void* v41(char*) { return 0; }
    virtual void* v42(char*) { return 0; }
    virtual void* v43(char*) { return 0; }
    virtual void* v44(char*) { return 0; }
    virtual S_00cc2d20_result* v45(char*) { return 0; }

    void __thiscall ClonePhysicsData(void* arg1, void* arg2);
    void __thiscall bhkDashpotAction_CopyMembers(
        void* arg1,
        S_00cc2d20_argument* arg2);
};

// Gets a result via v45, scales its two Col4 members by arg2->m_f10 when not 1.0, then calls ClonePhysicsData.
// @fnv 0x00cc2d20
// src: XBOX_PDB 0x00cc2d20
void S_00cc2d20_class::bhkDashpotAction_CopyMembers(
    void* arg1,
    S_00cc2d20_argument* apArgument)
{
    char local;
    S_00cc2d20_result* result = v45(&local);
    float scale = apArgument->m_f10;

    if (scale != 1.0f) {
        result->m_kPointA *= scale;
        result->m_kPointB *= scale;
    }

    ClonePhysicsData(arg1, apArgument);
}

extern float DAT_01013974;
extern float DAT_0101e2bc;

struct FUN_00cc2f40_cls {
    volatile unsigned int m_00;
    volatile unsigned int m_04;
    volatile unsigned int m_08;
    unsigned int unk0C;
    volatile float m_10;
    volatile float m_14;
    volatile float m_18;
    volatile float m_1c;
    volatile float m_20;
    volatile float m_24;
    volatile float m_28;
    volatile float m_2c;
    float m_30;
    float m_34;
    float m_38;
    unsigned char m_3c;
    unsigned char m_3d;
    FUN_00cc2f40_cls();
};

// @fnv 0x00cc2f40
FUN_00cc2f40_cls::FUN_00cc2f40_cls() {
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    m_10 = 0.0f;
    m_14 = 0.0f;
    m_18 = 0.0f;
    m_1c = 0.0f;
    m_20 = 0.0f;
    m_24 = 0.0f;
    m_28 = 0.0f;
    m_2c = 0.0f;
    m_30 = 1.0f;
    m_34 = DAT_01013974;
    m_38 = DAT_0101e2bc;
    m_3c = 1;
    m_3d = 1;
}

typedef unsigned int CC2F90size_t;

struct CC2F90MemoryManager;
extern CC2F90MemoryManager g_CC2F90MemoryManager;

extern __declspec(thread) int g_CC2F90AllocTag;

inline void* CC2F90AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)reinterpret_cast<MemoryManager&>(g_CC2F90MemoryManager).Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}

struct CC2F90Child {
    CC2F90Child();

    static void* operator new(CC2F90size_t, void* pvMem) { return pvMem; }
};

struct CC2F90Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CC2F90Child* m_pkChild;

    void CopyParentFieldsToChild(CC2F90Child* pkChild);
    CC2F90Child* bhkSpringAction_CreateCinfo(bool* pbCreated);
};

// @fnv 0x00cc2f90
// src: XBOX_PDB 0x00cc2f90
CC2F90Child* CC2F90Owner::bhkSpringAction_CreateCinfo(bool* pbCreated)
{
    AutoMemContext kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (m_pkChild == 0) {
        m_pkChild = new (CC2F90AlignedAlloc(0x50)) CC2F90Child();
        if (m_pParentNode)
            CopyParentFieldsToChild(m_pkChild);
    }
    return m_pkChild;
}

extern int DAT_012685b8;

struct FUN_00cc3270_base {
    virtual ~FUN_00cc3270_base();
};

struct FUN_00cc3270 : FUN_00cc3270_base {
    virtual ~FUN_00cc3270();
};

// @fnv 0x00cc3270
FUN_00cc3270::~FUN_00cc3270()
{
    ReleaseConstraint(reinterpret_cast<bhkConstraint*>(this));
    --DAT_012685b8;
}

extern int DAT_012685bc;

// @fnv 0x00cc32e0
// src: GUESS 0x00cc32e0 (confidence: low)
void* __cdecl Object_GetGlobalObjectAddress_00cc32e0()
{
    return &DAT_012685bc;
}

// @fnv 0x00cc32f0
// src: COMMUNITY 0x00cc32f0
int __cdecl bhkNiTriStripsShape_GetCinfoSize() {
    return 0x30;
}

void __cdecl FUN_00aa1460(void* p, unsigned int size);
struct S_00cc3300 {
    int unk00, unk04, unk08, unk0c;
    void FUN_00cc3270();
    S_00cc3300* FUN_00cc3300(unsigned int flags);
};
// @fnv 0x00cc3300
S_00cc3300* S_00cc3300::FUN_00cc3300(unsigned int flags)
{
    FUN_00cc3270();
    if (flags & 1)
        FUN_00aa1460(this, 0x10);
    return this;
}

extern float DAT_01267e30;

struct CC3320Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m_afPivot[4];
    float m_fMinimum;
    float m_fMaximum;
};


struct CC3320Info {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bhkLimitedHingeVector_blk_00cc0000_o2 m_kPivot;
    float m_fMinimum;
    float m_fMaximum;
    bool m_bStreamFlag;
};

class CC3320Base {
public:
    void GetInfo(CC3320Info* pkInfo);
};

class CC3320Constraint : public CC3320Base {
public:
    int unk00;
    int unk04;
    CC3320Data* m_pUserData;

    static const float* GetPivot(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_afPivot : &DAT_01267e30;
    }
    static float GetMax(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMaximum : 0.0f;
    }
    static float GetMin(const CC3320Constraint* pkConstraint)
    {
        return (pkConstraint && pkConstraint->m_pUserData) ? pkConstraint->m_pUserData->m_fMinimum : 0.0f;
    }

    void bhkMotorAction_CopyCinfo(CC3320Info* pkInfo);
};

// @fnv 0x00cc3320
// src: XBOX_PDB 0x00cc3320
void CC3320Constraint::bhkMotorAction_CopyCinfo(CC3320Info* pkInfo)
{
    GetInfo(pkInfo);
    pkInfo->m_bStreamFlag = true;
    pkInfo->m_kPivot.SetQuaternionComponentsFromVector(GetPivot(this));
    pkInfo->m_fMaximum = GetMax(this);
    pkInfo->m_fMinimum = GetMin(this);
}

namespace fnv_00cc33a0 {
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_010c9634;
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;

struct PhysicsElement {
    void* vtable;
    unsigned int referenceCount;
    unsigned int flags;
    unsigned int payload;

    void __thiscall UpdateState_00c87c30();

    static void* __cdecl operator new(unsigned int size) {
        return Object_DispatchCommandFour(size);
    }
    static void __cdecl operator delete(void*);

    PhysicsElement() {
        UpdateState_00c87c30();
        vtable = &DAT_0102016c;
        payload = 0;
        ++DAT_01268154;
        vtable = &DAT_0102009c;
        ++DAT_01268118;
        vtable = &DAT_010c9634;
        ++DAT_012685b8;
    }
};

// Allocates and constructs a new PhysicsElement, returning the pointer.
// @fnv 0x00cc33a0
PhysicsElement* __cdecl CreatePhysicsElement() {
    return new PhysicsElement();
}
}  // namespace fnv_00cc33a0

struct FUN_00cc3440_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00cc3440_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual unsigned int* vGet(FUN_00cc3440_obj** pp);
    void bhkUnaryAction_LoadBinary(FUN_00cc3440_obj* a);
    void SwapEndianFields(FUN_00cc3440_obj* a1);
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// @fnv 0x00cc3440
void FUN_00cc3440_cls::SwapEndianFields(FUN_00cc3440_obj* volatile apObj)
{
    FUN_00cc3440_obj* obj;
    bhkUnaryAction_LoadBinary(obj = apObj);
    if (obj->m_1e5 != 1)
    {
        volatile unsigned int* p = vGet((FUN_00cc3440_obj**)&apObj);
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
    }
}

struct PacketReader {
    void __thiscall bhkUnaryAction_SaveBinary(void* context);
    void __thiscall ReadPacketWithByteSwap(void* context);
};
typedef unsigned int* (__thiscall *GetPacketBlock)(PacketReader*, unsigned char*);
// @fnv 0x00cc34a0
void __thiscall PacketReader::ReadPacketWithByteSwap(void* context) {
    unsigned char format;
    volatile unsigned int* words = ((GetPacketBlock*)*(void**)this)[45](this, &format);
    if (((unsigned char*)context)[0x1E4] != 1) {
        words[4] = _byteswap_ulong(words[4]);
        words[5] = _byteswap_ulong(words[5]);
        words[6] = _byteswap_ulong(words[6]);
        words[7] = _byteswap_ulong(words[7]);
        words[8] = _byteswap_ulong(words[8]);
        words[9] = _byteswap_ulong(words[9]);
    }
    bhkUnaryAction_SaveBinary(context);
    if (((unsigned char*)context)[0x1E4] != 1) {
        words[4] = _byteswap_ulong(words[4]);
        words[5] = _byteswap_ulong(words[5]);
        words[6] = _byteswap_ulong(words[6]);
        words[7] = _byteswap_ulong(words[7]);
        words[8] = _byteswap_ulong(words[8]);
        words[9] = _byteswap_ulong(words[9]);
    }
}

namespace fnv_00cc3630 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct HeapAllocator_t
{
    char* Alloc(unsigned int size);
};
extern HeapAllocator_t DAT_011f6238;
extern unsigned int DAT_0126fd98;
extern float DAT_010162c0;

struct AlignedObj_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    unsigned char unk28;
};

class CacheOwner_cls
{
public:
    int unk00;
    int unk04;
    int m_08;
    AlignedObj_t* m_0c;
    void bhkMotorAction_CopyCinfo(AlignedObj_t* p);
    AlignedObj_t* bhkMotorAction_CreateCinfo(bool* out);
};

// @fnv 0x00cc3630
// src: XBOX_PDB 0x00cc3630
AlignedObj_t* CacheOwner_cls::bhkMotorAction_CreateCinfo(bool* pbCreated)
{
    TlsGuard_t guard;
    *pbCreated = (m_0c == 0);
    if (*pbCreated)
    {
        AlignedObj_t* p = (AlignedObj_t*)DAT_011f6238.Alloc(0x40);
        unsigned char shift = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
        p = (AlignedObj_t*)((char*)p + shift);
        ((unsigned char*)p)[-1] = shift;
        p->unk00 = 0;
        p->unk04 = 0;
        ((volatile AlignedObj_t*)p)->unk10 = 0.0f;
        p->unk14 = 0.0f;
        p->unk18 = 0.0f;
        p->unk1C = 0.0f;
        p->unk20 = 0.0f;
        p->unk24 = DAT_010162c0;
        ((volatile AlignedObj_t*)p)->unk28 = 1;
        m_0c = p;
        if (m_08 != 0)
        {
            bhkMotorAction_CopyCinfo(p);
        }
    }
    return m_0c;
}
}  // namespace fnv_00cc3630

extern int DAT_012685c4;

class FUN_00cc39b0_base {
public:
    virtual void unk00();
    ~FUN_00cc39b0_base();
    int unk04;
};

class FUN_00cc39b0 : public FUN_00cc39b0_base {
public:
    virtual ~FUN_00cc39b0();
    void unk08();
};

// Calls unk08 on this object and decrements the global counter DAT_012685c4.
// @fnv 0x00cc39b0
FUN_00cc39b0::~FUN_00cc39b0()
{
    this->unk08();
    DAT_012685c4--;
}

extern int DAT_012685c8;

// @fnv 0x00cc3a20
// src: COMMUNITY 0x00cc3a20
void* __cdecl bhkDashpotAction_GetRTTI()
{
    return &DAT_012685c8;
}

extern int DAT_010c970c;
extern int DAT_012685c4;

struct DerivedStandin2 : A51BF0Base, S_00cb79d0_Base {
    unsigned int m_uiField3;

    DerivedStandin2()
        : S_00cb79d0_Base()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0102016c);
        m_uiField3 = 0;
        DAT_01268154 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c5ef4);
        DAT_01268194 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c970c);
        DAT_012685c4 += count;
    }
};

// Allocates and constructs a DerivedStandin2 object, returning its pointer.
// @fnv 0x00cc3b30
void* CreateDerivedStandin2() {
    return new DerivedStandin2();
}

struct FUN_00cc3bd0_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};

struct FUN_00cc3bd0_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void bhkBinaryAction_LoadBinary(FUN_00cc3bd0_arg* a);
    void bhkDashpotAction_LoadBinary(FUN_00cc3bd0_arg* a1);
};

// Calls FUN_00c8a7a0 with the argument, then unless m_1e5 is 1, byte-swaps words 4 through 13 of the buffer returned by vGet.
// @fnv 0x00cc3bd0
// src: XBOX_PDB 0x00cc3bd0
void FUN_00cc3bd0_cls::bhkDashpotAction_LoadBinary(FUN_00cc3bd0_arg* a1)
{
    unsigned int tmp;
    bhkBinaryAction_LoadBinary(a1);
    if (a1->m_1e5 != 1)
    {
        volatile unsigned int* p = vGet((unsigned char*)&tmp);
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
    }
}

struct FUN_00cc3c50_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char m_1e4;
};

struct FUN_00cc3c50_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void DispatchChainNodes(FUN_00cc3c50_arg* a);
    void bhkDashpotAction_SaveBinary(FUN_00cc3c50_arg* a1);
};

// If a1->m_1e4 is not 1, byte-swaps p[4]..p[13] before and after calling DispatchChainNodes(a1).
// @fnv 0x00cc3c50
// src: XBOX_PDB 0x00cc3c50
void FUN_00cc3c50_cls::bhkDashpotAction_SaveBinary(FUN_00cc3c50_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
    }
    DispatchChainNodes(a1);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
        p[12] = _byteswap_ulong(p[12]);
        p[13] = _byteswap_ulong(p[13]);
    }
}

namespace fnv_00cc3e50 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;
    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct HeapAllocator_t
{
    char* Alloc(unsigned int size);
};
extern HeapAllocator_t DAT_011f6238;
extern unsigned int DAT_0126fd98;
extern float DAT_0101e2bc;
extern float DAT_01013ea4;

struct AlignedObj_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
};

class CacheOwner_cls
{
public:
    int unk00;
    int unk04;
    int m_08;
    AlignedObj_t* m_0c;
    void bhkDashpotAction_CopyCinfo(AlignedObj_t* p);
    AlignedObj_t* bhkDashpotAction_CreateCinfo(bool* out);
};

// @fnv 0x00cc3e50
// src: XBOX_PDB 0x00cc3e50
AlignedObj_t* CacheOwner_cls::bhkDashpotAction_CreateCinfo(bool* apIsNull)
{
    TlsGuard_t guard;
    *apIsNull = (m_0c == 0);
    if (*apIsNull)
    {
        AlignedObj_t* p = (AlignedObj_t*)DAT_011f6238.Alloc(0x50);
        unsigned char shift = (unsigned char)(0x10 - ((unsigned char)(unsigned int)p & 0xf));
        p = (AlignedObj_t*)((char*)p + shift);
        ((unsigned char*)p)[-1] = shift;
        p->unk00 = 0;
        p->unk04 = 0;
        p->unk08 = 0;
        ((volatile AlignedObj_t*)p)->unk10 = 0.0f;
        p->unk14 = 0.0f;
        p->unk18 = 0.0f;
        p->unk1C = 0.0f;
        p->unk20 = 0.0f;
        p->unk24 = 0.0f;
        p->unk28 = 0.0f;
        p->unk2C = 0.0f;
        p->unk30 = DAT_0101e2bc;
        p->unk34 = DAT_01013ea4;
        m_0c = p;
        if (m_08 != 0)
        {
            bhkDashpotAction_CopyCinfo(p);
        }
    }
    return m_0c;
}
}  // namespace fnv_00cc3e50

extern int DAT_012685d4;

// @fnv 0x00cc41f0
// src: COMMUNITY 0x00cc41f0
int* __cdecl bhkAngularDashpotAction_GetRTTI()
{
    return &DAT_012685d4;
}

struct FUN_00cc4220_source {
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
};

struct FUN_00cc4220_output {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
};

struct FUN_00cc4220_class {
    void* unk00;
    void* unk04;
    FUN_00cc4220_source* m_p;

    void __thiscall WriteScriptTargetInfo(void* p);
    void __thiscall bhkAngularDashpotAction_CopyCinfo(void* p);
};

extern "C" float DAT_012683b0[4];

// Calls WriteScriptTargetInfo, then copies m_f34, the four floats at m_f20 and m_f30 from m_p into the output, using defaults when m_p is null.
// @fnv 0x00cc4220
// src: COMMUNITY 0x00cc4220
void __thiscall FUN_00cc4220_class::bhkAngularDashpotAction_CopyCinfo(void* apOutput)
{
    FUN_00cc4220_output* out = static_cast<FUN_00cc4220_output*>(apOutput);

    this->WriteScriptTargetInfo(apOutput);

    float value = (this != 0 && this->m_p != 0)
        ? this->m_p->m_f34
        : 0.0f;
    out->m_f24 = value;

    const float* values = (this != 0 && this->m_p != 0)
        ? &this->m_p->m_f20
        : DAT_012683b0;

    out->m_f10 = values[0];
    out->m_f14 = values[1];
    out->m_f18 = values[2];
    out->m_f1c = values[3];

    float position = (this != 0 && this->m_p != 0)
        ? this->m_p->m_f30
        : 0.0f;
    out->m_f20 = position;
}

namespace fnv_00cc4340 {
extern "C" void __cdecl bhkSerializable_CloneCritLock();
extern "C" void __cdecl bhkSerializable_CloneCritUnlock();
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);

extern unsigned int g_ctorCount1;
extern unsigned int g_ctorCount2;
extern unsigned int g_ctorCount3;

class NodeRoot_cls {
public:
    NodeRoot_cls();
    virtual void r00();
};

class NodeA_cls : public NodeRoot_cls {
public:
    int unk04;
    int unk08;
    volatile int m_0c;
    NodeA_cls() : NodeRoot_cls() {
        m_0c = 0;
        g_ctorCount1 += 1;
    }
    virtual void a00();
};

class NodeB_cls : public NodeA_cls {
public:
    NodeB_cls() : NodeA_cls() {
        g_ctorCount2++;
    }
    virtual void b00();
};

class NodeC_cls : public NodeB_cls {
public:
    NodeC_cls() : NodeB_cls() {
        g_ctorCount3++;
    }
    virtual void c00();
    static void* operator new(unsigned int size) throw() {
        return Object_DispatchCommandFour(size);
    }
};

class FUN_00cc4340_cls {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52(NodeC_cls* node, int a1);
    NodeC_cls* bhkAngularDashpotAction_CreateClone(int a1);
};

// Allocates a NodeC_cls, passes it with a1 to v52, and returns the new node.
// @fnv 0x00cc4340
// src: XBOX_PDB 0x00cc4340
NodeC_cls* FUN_00cc4340_cls::bhkAngularDashpotAction_CreateClone(int a1) {
    bhkSerializable_CloneCritLock();
    NodeC_cls* p = new NodeC_cls();
    this->v52(p, a1);
    bhkSerializable_CloneCritUnlock();
    return p;
}
}  // namespace fnv_00cc4340

inline void CC4400Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}

struct CC4400Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_aulValues0;
    unsigned long m_aulValues1;
    unsigned long m_aulValues2;
    unsigned long m_aulValues3;
    unsigned long m_aulValues4;
    unsigned long m_aulValues5;
};

class CC4400Base {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual CC4400Data* GetData(unsigned int* puiSize);

    void Load(NiStream* pkStream);
};

class CC4400Object : public CC4400Base {
public:
    void bhkAngularDashpotAction_LoadBinary(NiStream* pkStream);
};

// @fnv 0x00cc4400
// src: XBOX_PDB 0x00cc4400
void CC4400Object::bhkAngularDashpotAction_LoadBinary(NiStream* pkStream)
{
    CC4400Base::Load(pkStream);
    if (StreamField<unsigned char>(*pkStream, 0x1e5) != 1) {
        unsigned int uiSize;
        CC4400Data* pkData = GetData(&uiSize);
        CC4400Swap(pkData->m_aulValues0);
        CC4400Swap(pkData->m_aulValues1);
        CC4400Swap(pkData->m_aulValues2);
        CC4400Swap(pkData->m_aulValues3);
        CC4400Swap(pkData->m_aulValues4);
        CC4400Swap(pkData->m_aulValues5);
    }
}

namespace fnv_00cc4500 {
extern "C" float DAT_0101e2bc;
extern "C" float DAT_01013ea4;
extern "C" float DAT_012683b0;
extern "C" float DAT_012683b4;
extern "C" float DAT_012683b8;
extern "C" float DAT_012683bc;

class FUN_00cc4500_cls {
public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int unk0C;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;

    FUN_00cc4500_cls* hkAngularDashpotActionCinfo_hkAngularDashpotActionCinfo();
};

// Zeroes the first fields, then stores the global float constants into m_20, m_24 and m_10 through m_1c, and returns this.
// @fnv 0x00cc4500
// src: COMMUNITY 0x00cc4500
FUN_00cc4500_cls* FUN_00cc4500_cls::hkAngularDashpotActionCinfo_hkAngularDashpotActionCinfo() {
    float zero = 0.0f;
    m_00 = 0;
    m_04 = 0;
    m_08 = 0;
    *(volatile float*)&m_10 = zero;
    *(volatile float*)&m_14 = zero;
    *(volatile float*)&m_18 = zero;
    *(volatile float*)&m_1c = zero;
    m_20 = DAT_0101e2bc;
    m_24 = DAT_01013ea4;
    m_10 = DAT_012683b0;
    m_14 = DAT_012683b4;
    m_18 = DAT_012683b8;
    m_1c = DAT_012683bc;
    return this;
}
}  // namespace fnv_00cc4500

extern int g_012685e0;

// @fnv 0x00cc4860
// src: GUESS 0x00cc4860 (confidence: low)
int* __cdecl Object_GetGlobalObjectAddress_00cc4860()
{
    return &g_012685e0;
}

extern int g_ctorCountA;
extern int g_ctorCountD;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct OwnerBase {
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw() {
        return Object_DispatchCommandFour(size);
    }
};

struct ChainA_cls : public OwnerBase {
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_cls() {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};

struct SpawnedObject : public ChainA_cls {
    virtual void unkD2();
    SpawnedObject() {
        g_ctorCountD += 1;
    }
};

// Allocates and constructs a new SpawnedObject via its operator new and returns the pointer.
// @fnv 0x00cc4900
// src: EXE 0x00cc4900
SpawnedObject* bhkBreakableConstraint_CreateObject() {
    return new SpawnedObject();
}

struct S_00cc4b90_Tls {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00cc4b90_Tls DAT_tls;

struct S_00cc4b90_Ctx {
    int saved;
    __forceinline S_00cc4b90_Ctx(int c) { saved = DAT_tls.ctx; DAT_tls.ctx = c; }
    __forceinline ~S_00cc4b90_Ctx() { DAT_tls.ctx = saved; }
};
struct S_00cc4b90_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00cc4b90_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00cc4b90_Alloc* unk10;
    S_00cc4b90_Alloc& heap() { return *unk10; }
};
S_00cc4b90_Router* hkMemoryRouter_getInstance() throw();
inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}

extern float DAT_01017b78;

struct S_00cc4b90_Base : hkReferencedObject {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00cc4b90_Base(int a);
};
struct __declspec(novtable) S_00cc4b90_Mid : S_00cc4b90_Base {
    float f20;
    S_00cc4b90_Mid() : S_00cc4b90_Base(0), f20(DAT_01017b78) {}
};
struct S_00cc4b90_Obj : S_00cc4b90_Mid {
    unsigned char b24;
    unsigned char b25;
    S_00cc4b90_Obj() { b24 = 0; b25 = 0; }
};
struct S_00cc4b90_Cls {
    int unk0;
    S_00cc4b90_Obj* m_p;
    int GetObjSize();
};
// Ensures m_p is allocated via the heap allocator if null, then returns sizeof(S_00cc4b90_Obj).
// @fnv 0x00cc4b90
int S_00cc4b90_Cls::GetObjSize()
{
    S_00cc4b90_Ctx ctx(0x10);
    if (!m_p)
        m_p = new S_00cc4b90_Obj;
    return sizeof(S_00cc4b90_Obj);
}

namespace fnv_00cc4c60 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;
extern int g_ctrA;
extern int g_ctrD;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int size);

class OwnerBase_t
{
public:
    OwnerBase_t();
    virtual void unkB0();
    virtual ~OwnerBase_t();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};

class ChainA_t : public OwnerBase_t
{
public:
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_t()
    {
        m_0c = 0;
        g_ctrA += 1;
    }
};

class SpawnedObject_t : public ChainA_t
{
public:
    virtual void unkD2();
    SpawnedObject_t()
    {
        g_ctrD += 1;
    }
};

struct FUN_00cc4c60_cls
{
    int unk00;
    int unk04;
    void bhkConstraint_CopyMembers(SpawnedObject_t* obj, unsigned int arg);
    SpawnedObject_t* bhkBreakableConstraint_Clone(unsigned int arg);
};

// @fnv 0x00cc4c60
// src: COMMUNITY 0x00cc4c60
SpawnedObject_t* FUN_00cc4c60_cls::bhkBreakableConstraint_Clone(unsigned int arg)
{
    TlsGuard_t guard;
    SpawnedObject_t* result = 0;
    bhkSerializable_CloneCritLock();
    result = new SpawnedObject_t();
    bhkConstraint_CopyMembers(result, arg);
    bhkSerializable_CloneCritUnlock();
    return result;
}
}  // namespace fnv_00cc4c60

struct FUN_00cc4e90_stream;

typedef unsigned int (__cdecl* FUN_00cc4e90_readfn)(FUN_00cc4e90_stream* s, void* dst, unsigned int size, unsigned int* outCount, unsigned int count);

struct FUN_00cc4e90_stream
{
    int unk00;
    unsigned int m_04;
    int unk08;
    FUN_00cc4e90_readfn m_0c;
};

struct FUN_00cc4e90_sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
};

void __cdecl bhkConstraintManager_SaveBinary(int a1, int v);

class FUN_00cc4e90_cls
{
public:
    int unk00;
    FUN_00cc4e90_sub* m_04;
    void __thiscall hkConstraintCinfo_SaveBinary(int a1);
    void LoadSubData(int a1);
};

// Calls FUN_00c8a280, passes m_04->m_18 to FUN_00cf4bc0, then reads 4 bytes into m_04->unk20 and 1 byte into m_04->unk24 from the stream at a1+0x250.
// @fnv 0x00cc4e90
void FUN_00cc4e90_cls::LoadSubData(int a1)
{
    hkConstraintCinfo_SaveBinary(a1);
    FUN_00cc4e90_sub* b = m_04;
    bhkConstraintManager_SaveBinary(a1, b->m_18);
    FUN_00cc4e90_stream* s = *(FUN_00cc4e90_stream**)((char*)a1 + 0x250);
    { unsigned int n = 4; s->m_04 += s->m_0c(s, &b->unk20, 4, &n, 1); }
    s = *(FUN_00cc4e90_stream**)((char*)a1 + 0x250);
    { unsigned int n = 1; s->m_04 += s->m_0c(s, &b->unk24, 1, &n, 1); }
}

extern int DAT_012685e8;

struct SpawnedBase {
    virtual ~SpawnedBase();
};

struct FUN_00cc5090 : SpawnedBase {
    virtual ~FUN_00cc5090();
};

// @fnv 0x00cc5090
FUN_00cc5090::~FUN_00cc5090()
{
    ReleaseConstraint(reinterpret_cast<bhkConstraint*>(this));
    DAT_012685e8--;
}

extern int g_unk012685ec;

// @fnv 0x00cc5100
// src: COMMUNITY 0x00cc5100
void* __cdecl bhkWheelConstraint_GetRTTI(void)
{
    return &g_unk012685ec;
}

namespace fnv_00cc5340 {
extern "C" __declspec(thread) int g_memoryContext;

struct Allocator {
    virtual void Release();
    virtual void* Allocate(unsigned int size);
};

struct MemorySystem {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Allocator* allocator;

    void* Allocate(unsigned int bytes) {
        return allocator->Allocate(bytes);
    }
};

extern "C" MemorySystem* __cdecl hkMemoryRouter_getInstance();

struct FUN_00d4edc0 {
    FUN_00d4edc0();
    static void* operator new(unsigned int size) {
        void* memory = hkMemoryRouter_getInstance()->Allocate(0x160);
        *reinterpret_cast<unsigned short*>(
            static_cast<char*>(memory) + 4) = 0x160;
        return memory;
    }
};

struct AllocationContext {
    int previous;
    AllocationContext() {
        previous = g_memoryContext;
        g_memoryContext = 0x10;
    }
    ~AllocationContext() {
        g_memoryContext = previous;
    }
};

struct ObjectHolder {
    int m_00;
    FUN_00d4edc0* object;
    int EnsureObjectAllocated();
};

// Creates the object via new FUN_00d4edc0 if it is null, then returns 0x160.
// @fnv 0x00cc5340
int ObjectHolder::EnsureObjectAllocated() {
    AllocationContext context;
    if (object == 0) {
        object = new FUN_00d4edc0();
    }
    return 0x160;
}
}  // namespace fnv_00cc5340

namespace fnv_00cc53f0 {
extern void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" void __cdecl bhkSerializable_CloneCritLock();
extern "C" void __cdecl bhkSerializable_CloneCritUnlock();
extern int DAT_0108febc;
extern int DAT_010c9a14;
extern int DAT_01268188;
extern int DAT_012685e8;
extern __declspec(thread) int hkThreadAllocationFlag;

}  // namespace fnv_00cc53f0

struct HavokRuntimeObject {
    void* vtable;
    int refCount;
    int heapFlags;
    int extra;
    void __thiscall UpdateState_00c87c30();
    static void* __cdecl operator new(unsigned int size) { return fnv_00cc53f0::Object_DispatchCommandFour(size); }
    HavokRuntimeObject() {
        UpdateState_00c87c30();
        vtable = &fnv_00cc53f0::DAT_0108febc;
        extra = 0;
        ++fnv_00cc53f0::DAT_01268188;
        vtable = &fnv_00cc53f0::DAT_010c9a14;
        ++fnv_00cc53f0::DAT_012685e8;
    }
};

namespace fnv_00cc53f0 {
struct HavokThreadScope {
    int oldValue;
    HavokThreadScope() {
        oldValue = hkThreadAllocationFlag;
        hkThreadAllocationFlag = 16;
    }
    ~HavokThreadScope() {
        bhkSerializable_CloneCritUnlock();
        hkThreadAllocationFlag = oldValue;
    }
};
}  // namespace fnv_00cc53f0

// 0x00cc53f0 is bhkWheelConstraint::CreateClone and 0x00c89730 bhkConstraint::CopyMembers (community
// FalloutNV.pdb names); the shared bhkWheelConstraint.h does not declare them, so this unit keeps a local shell.
class WheelConstraintClone_cc53f0
{
public:
    void* __thiscall bhkConstraint_CopyMembers(HavokRuntimeObject*, int);
    HavokRuntimeObject* __thiscall CreateRuntimeObject(int argument);
};
// @fnv 0x00cc53f0
HavokRuntimeObject* __thiscall WheelConstraintClone_cc53f0::CreateRuntimeObject(int argument) {
    fnv_00cc53f0::HavokThreadScope scope;
    fnv_00cc53f0::bhkSerializable_CloneCritLock();
    HavokRuntimeObject* obj = new HavokRuntimeObject;
    bhkConstraint_CopyMembers(obj, argument);
    return obj;
}

struct BinaryStream {
    void* m_ppVirtualMethodTable;
    unsigned int m_vContactPosition;
    void* m_pOwnerObject;
    int (__cdecl *m_write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* data, unsigned int count) {
        unsigned int actualCount = count;
        m_vContactPosition += m_write(this, data, count, &actualCount, 1);
    }
};
struct StreamContext {
    BinaryStream* OutputStream() {
        return *reinterpret_cast<BinaryStream**>(reinterpret_cast<unsigned char*>(this) + 0x250);
    }
};
struct FUN_00cc5730_class {
    void* m_ppVirtualMethodTable;
    unsigned char* m_objectData;
    void __thiscall hkConstraintCinfo_SaveBinary(StreamContext* context);
    void __thiscall hkWheelConstraintCinfo_SaveBinary(StreamContext* context);
};
// @fnv 0x00cc5730
// src: XBOX_PDB 0x00cc5730
void __thiscall FUN_00cc5730_class::hkWheelConstraintCinfo_SaveBinary(StreamContext* context) {
    hkConstraintCinfo_SaveBinary(context);
    unsigned char* data = m_objectData;
    context->OutputStream()->Write(data + 0x20, 0x40);
    context->OutputStream()->Write(data + 0x60, 0x40);
    context->OutputStream()->Write(data + 0xd0, 0x30);
    context->OutputStream()->Write(data + 0x100, 0x30);
    context->OutputStream()->Write(data + 0x140, 0x10);
    context->OutputStream()->Write(data + 0x150, 0x10);
    context->OutputStream()->Write(data + 0xa4, 4);
    context->OutputStream()->Write(data + 0xa8, 4);
    context->OutputStream()->Write(data + 0xb0, 4);
    context->OutputStream()->Write(data + 0xb4, 4);
}

extern int DAT_012685f4;

class FUN_00cc58c0_base {
public:
    virtual void unk00();
    ~FUN_00cc58c0_base();
    int unk04;
};

class FUN_00cc58c0 : public FUN_00cc58c0_base {
public:
    virtual ~FUN_00cc58c0();
    void unk08();
};

// Calls unk08 on this object and decrements the global counter DAT_012685f4.
// @fnv 0x00cc58c0
FUN_00cc58c0::~FUN_00cc58c0()
{
    this->unk08();
    DAT_012685f4--;
}

extern int DAT_0108febc;
extern int DAT_010c52bc;
extern int DAT_01268188;
extern int DAT_012685f4;

struct CC5930_Base {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiData08;
    CC5930_Base();
    static void* __cdecl operator new(unsigned int size);
};

struct CC5930_Obj : CC5930_Base {
    unsigned int m_uiData0C;

    CC5930_Obj()
    {
        unsigned int count = 1;
        m_pVtable = reinterpret_cast<void*>(&DAT_0108febc);
        m_uiData0C = 0;
        DAT_01268188 += count;
        m_pVtable = reinterpret_cast<void*>(&DAT_010c52bc);
        DAT_012685f4 += count;
    }
};

// Allocates and constructs a CC5930_Obj, returning the new object.
// @fnv 0x00cc5930
CC5930_Obj* __cdecl CreateCC5930Obj()
{
    return new CC5930_Obj;
}

template <class T>
inline void CC5D40BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC5D40LoadBinary(NiStream& kStream, T& value)
{
    CC5D40BinaryStreamLoad(*InputStream(kStream), &value);
}



struct CC5D40Constraint {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    hkVector4 m_kPivotA;
    hkVector4 m_kPivotB;
    int unk40;
    float m_fTau;
};

class CC5D40RefObject {
public:
    int unk00;
    CC5D40Constraint* m_pkConstraint;

    void LoadBinary(NiStream& kStream);
};

class CC5D40BallJoint : public CC5D40RefObject {
public:
    void hkStiffSpringConstraintCinfo_LoadBinary(NiStream& kStream);
};

// LoadBinary
// Loads the base object, then reads the constraint's pivot A, pivot B and tau from the stream.
// @fnv 0x00cc5d40
// src: XBOX_PDB 0x00cc5d40
void CC5D40BallJoint::hkStiffSpringConstraintCinfo_LoadBinary(NiStream& kStream)
{
    CC5D40RefObject::LoadBinary(kStream);
    CC5D40Constraint* pkConstraint = m_pkConstraint;
    CC5D40LoadBinary(kStream, pkConstraint->m_kPivotA);
    CC5D40LoadBinary(kStream, pkConstraint->m_kPivotB);
    CC5D40LoadBinary(kStream, pkConstraint->m_fTau);
}

class CC5DD0Object;

template <class T>
inline void CC5DD0BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CC5DD0SaveBinary(NiStream& kStream, const T& value) {
    CC5DD0BinaryStreamSave(*OutputStream(kStream), &value);
}



struct CC5DD0Constraint {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    hkVector4 m_kPivotA;
    hkVector4 m_kPivotB;
    int unk40;
    float m_fTau;
};

class CC5DD0RefObject {
public:
    int unk00;
    CC5DD0Constraint* m_pkConstraint;

    void SaveBinary(NiStream& kStream);
};

class CC5DD0BallJoint : public CC5DD0RefObject {
public:
    void hkStiffSpringConstraintCinfo_SaveBinary(NiStream& kStream);
};

// SaveBinary
// Saves the base object, then writes the constraint's pivot A, pivot B and tau to the stream.
// @fnv 0x00cc5dd0
// src: XBOX_PDB 0x00cc5dd0
void CC5DD0BallJoint::hkStiffSpringConstraintCinfo_SaveBinary(NiStream& kStream) {
    CC5DD0RefObject::SaveBinary(kStream);
    CC5DD0Constraint* pkConstraint = m_pkConstraint;
    CC5DD0SaveBinary(kStream, pkConstraint->m_kPivotA);
    CC5DD0SaveBinary(kStream, pkConstraint->m_kPivotB);
    CC5DD0SaveBinary(kStream, pkConstraint->m_fTau);
}

extern int DAT_01268600;

struct FUN_00cc5e60 : bhkConstraint {
    ~FUN_00cc5e60();
};

// @fnv 0x00cc5e60
FUN_00cc5e60::~FUN_00cc5e60()
{
    ReleaseConstraint(this);
    --DAT_01268600;
}

extern int DAT_01268604;

// @fnv 0x00cc5ed0
// src: GUESS 0x00cc5ed0 (confidence: low)
int* __cdecl Runtime_GetDAT01268604Address()
{
    return &DAT_01268604;
}

struct FUN_00cc5ee0_interface
{
    virtual void __thiscall FUN_00cc5ee0_call(int value) = 0;
};

struct FUN_00cc5ee0_class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;

    void __thiscall ClearInterface(char param_2);
};

// @fnv 0x00cc5ee0
void __thiscall FUN_00cc5ee0_class::ClearInterface(char abClear)
{
    if (abClear != 0)
    {
        if (unk0c != 0)
        {
            FUN_00cc5ee0_interface* object =
                reinterpret_cast<FUN_00cc5ee0_interface*>(
                    reinterpret_cast<unsigned char*>(unk0c) - 4);

            if (object != 0)
            {
                object->FUN_00cc5ee0_call(1);
            }
        }

        unk0c = 0;
    }
}

namespace fnv_00cc6140 {
struct Helper {
    void bhkConstraint_CopyMembers(void* a, int b);
};

struct Helper2 {
    void* UpdateState_00c87c30();
};

extern "C" void __cdecl bhkSerializable_CloneCritLock();
extern "C" void __cdecl bhkSerializable_CloneCritUnlock();
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);

extern int DAT_01268188;
extern int DAT_01268600;
extern int DAT_0108febc;
extern int DAT_010c9b0c;

struct Obj {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;

    static void* operator new(unsigned int s) { return Object_DispatchCommandFour(s); }

    Obj() {
        ((Helper2*)this)->UpdateState_00c87c30();
        m_pVtable = (void*)&DAT_0108febc;
        int one = 1;
        m_uiData1 = 0;
        DAT_01268188 += one;
        m_pVtable = (void*)&DAT_010c9b0c;
        DAT_01268600 += one;
    }
};

struct C {
    void* bhkRagdollLimitsConstraint_Clone(int arg);
};

// Calls FUN_00c876f0, allocates an Obj, passes it with arg to FUN_00c89730, calls FUN_00c87700 and returns the Obj.
// @fnv 0x00cc6140
// src: COMMUNITY 0x00cc6140
void* C::bhkRagdollLimitsConstraint_Clone(int arg) {
    bhkSerializable_CloneCritLock();
    Obj* esi = new Obj();
    ((Helper*)this)->bhkConstraint_CopyMembers(esi, arg);
    bhkSerializable_CloneCritUnlock();
    return esi;
}
}  // namespace fnv_00cc6140

namespace fnv_00cc6310 {
struct S_cc6310_Tls {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
};
__declspec(thread) S_cc6310_Tls g_tls_cc6310;
struct S_cc6310_Guard {
    int saved;
    S_cc6310_Guard() { saved = g_tls_cc6310.unk2B4; g_tls_cc6310.unk2B4 = 0x10; }
    ~S_cc6310_Guard() { g_tls_cc6310.unk2B4 = saved; }
};
struct S_cc6310_Pool {
    void* Game_DoHeapAlloc(unsigned int n);
};
extern S_cc6310_Pool DAT_011f6238;
extern int DAT_010c9be8;
struct S_cc6310_Base {
    int unk00;
};
struct S_cc6310_Obj {
    int* unk00;
    S_cc6310_Base base;
    int unk08;
    int unk0c;
    int unk10;
    static void* operator new(unsigned int n) { return DAT_011f6238.Game_DoHeapAlloc(n); }
};
struct S_cc6310 {
    int unk00;
    int unk04;
    int unk08;
    S_cc6310_Base* unk0c;
    void CopyFromSource(S_cc6310_Obj* c);
    S_cc6310_Base* GetOrCreateBase(bool* created);
};
// Sets *created when unk0c is null, allocates and initialises a new S_cc6310_Obj, stores its base in unk0c, and returns unk0c.
// @fnv 0x00cc6310
S_cc6310_Base* S_cc6310::GetOrCreateBase(bool* created) {
    S_cc6310_Guard guard;
    bool b = (unk0c == 0);
    *created = b;
    if (b) {
        S_cc6310_Obj* c = new S_cc6310_Obj;
        S_cc6310_Base* r;
        if (c) {
            S_cc6310_Base* pBase = &c->base;
            c->unk08 = 1;
            c->unk0c = 0;
            c->unk10 = 0;
            c->unk00 = &DAT_010c9be8;
            pBase->unk00 = 0;
            r = pBase;
        } else {
            r = 0;
        }
        unk0c = r;
        if (unk08)
            CopyFromSource(unk0c ? (S_cc6310_Obj*)((char*)unk0c - 4) : 0);
    }
    return unk0c;
}
}  // namespace fnv_00cc6310

class BSAudio;
namespace fnv_00cc6720 {

__declspec(nothrow) BSAudio* __cdecl hkMemoryRouter_getInstance();



class Payload : public hkReferencedObject {
public:
    Payload();
    char m_08[0x140 - 8];
};

class Owner {
public:
    int m_00;
    Payload* m_pkPayload;
    int EnsurePayload();
};

// Allocates a Payload into m_pkPayload if it is null, then returns sizeof(Payload).
// @fnv 0x00cc6720
int Owner::EnsurePayload()
{
    if (!m_pkPayload)
        m_pkPayload = new Payload();
    return sizeof(Payload);
}
}  // namespace fnv_00cc6720

extern int DAT_01268618;

class FUN_00cc7450_base {
public:
    virtual void unk00();
    ~FUN_00cc7450_base();
    int unk04;
};

class FUN_00cc7450 : public FUN_00cc7450_base {
public:
    virtual ~FUN_00cc7450();
    void unk08();
};

// @fnv 0x00cc7450
FUN_00cc7450::~FUN_00cc7450()
{
    this->unk08();
    DAT_01268618--;
}

extern int DAT_0126861c;

// @fnv 0x00cc74c0
// src: COMMUNITY 0x00cc74c0
void* __cdecl bhkPrismaticConstraint_GetRTTI()
{
    return &DAT_0126861c;
}

// FUN_00cc74d0 : a one-line function - getter
extern int g_target_00cc74d0;
// @fnv 0x00cc74d0
// src: COMMUNITY 0x00cc74d0
void* _GetCInfoSize_20() { return &g_target_00cc74d0; }

// FUN_00cc75b0: thiscall, one stack arg (int a1).
class FUN_00cc75b0_F {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    float m_b4;
};

class FUN_00cc75b0_C {
public:
    FUN_00cc75b0_F* m_00;
};

class FUN_00cc75b0_B {
public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_F* m_08;
    FUN_00cc75b0_F* m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned char unk1c;
    unsigned char m_1d;
};

class FUN_00cc75b0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    FUN_00cc75b0_B* m_08;
    FUN_00cc75b0_C* m_0c;
    void Call(int a1);
    void bhkPrismaticConstraint_Init(int a1);
};

// @fnv 0x00cc75b0
// src: XBOX_PDB 0x00cc75b0
void FUN_00cc75b0_cls::bhkPrismaticConstraint_Init(int aiArg) {
    FUN_00cc75b0_F* f = 0;
    Call(aiArg);
    if (this != 0 && this->m_08 != 0) {
        f = this->m_08->m_0c;
    } else {
        FUN_00cc75b0_C* c = this->m_0c;
        if (c != 0) f = c->m_00;
    }
    if (f != 0 && f->m_b4 != 0.0f) {
        FUN_00cc75b0_B* b = this->m_08;
        if (b != 0) b->m_1d = 1;
    }
}

namespace fnv_00cc7890 {
void bhkSerializable_CloneCritLock();
void* Object_DispatchCommandFour(unsigned int size);

struct SpawnBase
{
    virtual ~SpawnBase();
    SpawnBase();
    unsigned int unk04;
    unsigned int unk08;
};

extern unsigned int g_spawnCountA;
extern unsigned int g_spawnCountB;

struct SpawnChainA : SpawnBase
{
    SpawnChainA();
    unsigned int m_0c;
};

struct SpawnedObject : SpawnChainA
{
    virtual ~SpawnedObject() {}
    static void* operator new(unsigned int size);
    SpawnedObject();
};

void* SpawnedObject::operator new(unsigned int size)
{
    bhkSerializable_CloneCritLock();
    return Object_DispatchCommandFour(size);
}

SpawnChainA::SpawnChainA()
{
    m_0c = 0;
    g_spawnCountA++;
}

SpawnedObject::SpawnedObject()
{
    g_spawnCountB++;
}

struct ThreadHeapState
{
    unsigned char unk000[0x2b4];
    unsigned int m_2b4;
};

extern __declspec(thread) ThreadHeapState g_threadHeapState;

void bhkSerializable_CloneCritUnlock();

class FUN_00cc7890_cls
{
public:
    void* bhkPrismaticConstraint_CreateClone(unsigned int arg);
    void SpawnInit(SpawnedObject* obj, unsigned int arg);
};

struct TlsHeapGuard
{
    unsigned int saved;
    TlsHeapGuard() { saved = g_threadHeapState.m_2b4; g_threadHeapState.m_2b4 = 0x10; }
    ~TlsHeapGuard() { g_threadHeapState.m_2b4 = saved; }
};

// Allocates a SpawnedObject under a TLS heap guard, initializes it via SpawnInit with arg, calls FUN_00c87700 and returns the object.
// @fnv 0x00cc7890
// src: COMMUNITY 0x00cc7890
void* FUN_00cc7890_cls::bhkPrismaticConstraint_CreateClone(unsigned int arg)
{
    TlsHeapGuard guard;
    SpawnedObject* obj = new SpawnedObject();
    SpawnInit(obj, arg);
    bhkSerializable_CloneCritUnlock();
    return obj;
}
}  // namespace fnv_00cc7890

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

template <class T> inline void NiStreamLoadBinarySI(NiBinaryStream& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}







void __cdecl SwapRotHelper(Transform* pkTransform);

inline void Swap32SI(void* p)
{
    *(unsigned int*)p = _byteswap_ulong(*(unsigned int*)p);
}

inline void SwapVector4SI(hkVector4* v)
{
    Swap32SI(&v->x);
    Swap32SI(&v->y);
    Swap32SI(&v->z);
    Swap32SI(&v->w);
}

inline void SwapTransformSI(Transform* t)
{
    SwapVector4SI(reinterpret_cast<hkVector4*>(&t->r[3]));
    SwapRotHelper(t);
}


struct ConstraintDataSI {
    void* m_pVtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Transform m_kBodyALocalFrame;
    Transform m_kBodyBLocalFrame;
    unsigned short unkA0;
    unsigned char m_bMotorEnabled;
    unsigned char unkA3;
    int unkA4; int unkA8; int unkAC; int unkB0;
    float m_fB4;
    int unkB8; int unkBC; int unkC0; int unkC4;
    float m_fC8;
    float m_fCC;
    void SetMotorSI(hkReferencedObject* pMotor);
};


struct FUN_00cc7a40_class : bhkConstraintBaseSI_blk_00cc0000_o2 {
    void hkPrismaticConstraintCinfo_LoadBinary(NiStream& kStream);
};

// @fnv 0x00cc7a40
// src: XBOX_PDB 0x00cc7a40
void FUN_00cc7a40_class::hkPrismaticConstraintCinfo_LoadBinary(NiStream& kStream)
{
    LoadBinaryBase(kStream);
    ConstraintDataSI* pData = m_pData;
    InputStream(kStream)->Read(&pData->m_kBodyALocalFrame, 0x40);
    InputStream(kStream)->Read(&pData->m_kBodyBLocalFrame, 0x40);
    NiStreamLoadBinarySI(*InputStream(kStream), pData->m_fC8);
    NiStreamLoadBinarySI(*InputStream(kStream), pData->m_fCC);
    NiStreamLoadBinarySI(*InputStream(kStream), pData->m_fB4);
    if (StreamField<unsigned char>(kStream, 0x1e5) != 1) {
        SwapTransformSI(&pData->m_kBodyALocalFrame);
        SwapTransformSI(&pData->m_kBodyBLocalFrame);
    }
    if (StreamField<unsigned int>(kStream, 0x4) > 0x1d) {
        hkReferencedObject* pMotor = LoadMotorSI(kStream);
        pData->SetMotorSI(pMotor);
        if (pMotor) {
            NiStreamLoadBinarySI(*InputStream(kStream), pData->m_bMotorEnabled);
            pMotor->removeReference();
        }
    }
}

extern int DAT_01268624;

class FUN_00cc7d00_base {
public:
    virtual void unk00();
    ~FUN_00cc7d00_base();
    int unk04;
};

class FUN_00cc7d00 : public FUN_00cc7d00_base {
public:
    virtual ~FUN_00cc7d00();
    void unk08();
};

// @fnv 0x00cc7d00
FUN_00cc7d00::~FUN_00cc7d00()
{
    this->unk08();
    DAT_01268624--;
}

extern int DAT_01268628;

// @fnv 0x00cc7d70
// src: COMMUNITY 0x00cc7d70
int* __cdecl bhkFixedConstraint_GetRTTI()
{
    return &DAT_01268628;
}

// @fnv 0x00cc7d80
// src: COMMUNITY 0x00cc7d80
int __cdecl bhkListShape_GetCinfoSize()
{
    return 28;
}

struct CpuOpaque;
extern CpuOpaque DAT_01268f78;
// @fnv 0x00cc7d90
// src: COMMUNITY 0x00cc7d90
CpuOpaque* __cdecl bhkGenericConstraint_GetRTTI()
{
    return &DAT_01268f78;
}

extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
struct S_00cc7dc0_Arg { int unk00; int unk04; };
struct __declspec(novtable) S_00cc7dc0_Root {
    unsigned int unk04;
    unsigned int unk08;
    int unk0c;
    S_00cc7dc0_Root() { Initialize(); unk0c = 0; }
    virtual ~S_00cc7dc0_Root();
    void Initialize();
};
struct S_00cc7dc0_A : S_00cc7dc0_Root {
    S_00cc7dc0_A() { DAT_01268188++; }
    virtual ~S_00cc7dc0_A();
};
struct S_00cc7dc0_B : S_00cc7dc0_A {
    S_00cc7dc0_B() { DAT_01268f74++; }
    virtual ~S_00cc7dc0_B();
};
struct S_00cc7dc0_Init { void SpawnAndAttach(S_00cc7dc0_Arg* a); };
struct FUN_00cc7dc0 : S_00cc7dc0_B {
    FUN_00cc7dc0(S_00cc7dc0_Arg* a);
    void SpawnAndAttach(S_00cc7dc0_Arg* a);
    virtual ~FUN_00cc7dc0();
};
// @fnv 0x00cc7dc0
FUN_00cc7dc0::FUN_00cc7dc0(S_00cc7dc0_Arg* a) {
    SpawnAndAttach(a ? (S_00cc7dc0_Arg*)&a->unk04 : 0);
    DAT_01268624++;
}

namespace fnv_00cc83b0 {
extern __declspec(thread) unsigned int hkThreadAllocationTag;
extern int DAT_010c9f54;
struct AllocationManager {
    void* __thiscall Game_DoHeapAlloc(unsigned int bytes);
};
extern AllocationManager DAT_011f6238;

struct RefBlock {
    void* vtable;
    void* payload;
    unsigned int referenceCount;
    unsigned int flags;
    unsigned int userData;
};
struct RefBlockArgument { RefBlock* block; };
struct FUN_00cc83b0_Class;
extern "C" void __fastcall CopyFromSource(FUN_00cc83b0_Class*, RefBlockArgument);

struct ScopedAllocationTag {
    unsigned int previous;
    ScopedAllocationTag() : previous(hkThreadAllocationTag) {
        hkThreadAllocationTag = 16;
    }
    ~ScopedAllocationTag() {
        hkThreadAllocationTag = previous;
    }
};

struct FUN_00cc83b0_Class {
    void* vtable;
    void* unknown04;
    void* owner;
    void* object;
    void* __thiscall bhkFixedConstraint_CreateCinfo(bool* created);
};

// @fnv 0x00cc83b0
// src: XBOX_PDB 0x00cc83b0
void* FUN_00cc83b0_Class::bhkFixedConstraint_CreateCinfo(bool* created) {
    ScopedAllocationTag allocationTag;
    bool missing = (object == 0);
    *created = missing;
    if (missing) {
        RefBlock* block = static_cast<RefBlock*>(DAT_011f6238.Game_DoHeapAlloc(28));
        void* reference;
        if (block != 0) {
            void** data = &block->payload;
            block->referenceCount = 1;
            block->flags = 0;
            block->userData = 0;
            block->vtable = &DAT_010c9f54;
            *data = 0;
            reference = data;
        } else {
            reference = 0;
        }
        object = reference;
        if (owner != 0) {
            RefBlockArgument header = { reference ? reinterpret_cast<RefBlock*>(static_cast<char*>(reference) - 4) : 0 };
            CopyFromSource(this, header);
        }
    }
    return object;
}
}  // namespace fnv_00cc83b0

extern int DAT_01268630;
struct FUN_00cc8480 : bhkConstraint {
    ~FUN_00cc8480();
};
// @fnv 0x00cc8480
FUN_00cc8480::~FUN_00cc8480()
{
    ReleaseConstraint(this);
    DAT_01268630--;
}

extern int g_unk01268634;

// @fnv 0x00cc84f0
// src: COMMUNITY 0x00cc84f0
void* __cdecl bhkHingeLimitsConstraint_GetRTTI()
{
    return &g_unk01268634;
}

extern __declspec(thread) int g_iCC8770AllocTag;

void __cdecl BCC8770Lock();
void __cdecl BCC8770Unlock();

class BCC8770CloningProcess;

class BCC8770RefObject {
public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    BCC8770RefObject();
    virtual ~BCC8770RefObject();

    int unk04;
    int unk08;
};

class BCC8770Shape : public BCC8770RefObject {
public:
    BCC8770Shape() : m_pkShape(0) { ms_uiInstances++; }
    virtual ~BCC8770Shape();

    void* m_pkShape;

    static unsigned int ms_uiInstances;
};

class BCC8770DerivedShape : public BCC8770Shape {
public:
    BCC8770DerivedShape() { ms_uiInstances++; }
    virtual ~BCC8770DerivedShape();

    static unsigned int ms_uiInstances;
};

class BCC8770Source {
public:
    void CopyMemberData(BCC8770DerivedShape* pkDest, BCC8770CloningProcess& kCloning);
    BCC8770DerivedShape* CloneDerivedShape(BCC8770CloningProcess& kCloning);
};

// @fnv 0x00cc8770
BCC8770DerivedShape* BCC8770Source::CloneDerivedShape(BCC8770CloningProcess& kCloning)
{
    AutoMemContext kScope(0x10);
    BCC8770Lock();
    BCC8770DerivedShape* pkClone = new BCC8770DerivedShape;
    CopyMemberData(pkClone, kCloning);
    BCC8770Unlock();
    return pkClone;
}

extern __declspec(thread) int g_tlsMemContext;

struct SerializationMemoryContext {
    int previous;
    SerializationMemoryContext() : previous(g_tlsMemContext) {
        g_tlsMemContext = 16;
    }
    ~SerializationMemoryContext() {
        g_tlsMemContext = previous;
    }
};

struct ConstraintSerializationData {
    hkVector4 unk00;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 planeA;
    hkVector4 axis;
    hkVector4 pivot;
    hkVector4 unk60;
    hkVector4 unk70;
    int unk80;
    float minAngle;
    float maxAngle;
};

struct ConstraintSerializer {
    void* m_vtbl;
    ConstraintSerializationData* data;
    void SerializeBase(StrArr* strings);
    void SerializeConstraintData(StrArr* strings);
};

extern const char DAT_010c8388[];
extern const char DAT_010c8378[];
extern const char DAT_010c8368[];
extern const char DAT_010c835c[];
extern const char DAT_010c8350[];

inline void AppendConstraintString(StrArr* strings, char* text)
{
    unsigned int index = strings->m_usSize;
    if (index >= strings->m_usMaxSize) {
        strings->SetSize(index + strings->m_usGrowBy);
    }
    strings->SetAt(index, text);
}

// Serializes the base data, then appends formatted pivot, planeA, axis, minAngle and maxAngle strings from the constraint data to the string array.
// @fnv 0x00cc8ad0
void ConstraintSerializer::SerializeConstraintData(StrArr* strings)
{
    SerializationMemoryContext context;
    SerializeBase(strings);
    ConstraintSerializationData* constraint = data;
    if (constraint) {
        NiPoint3 vector;
        HK2NINS(vector, constraint->pivot);
        AppendConstraintString(strings, vector.FormatToBuffer(DAT_010c8388));
        HK2NINS(vector, constraint->planeA);
        AppendConstraintString(strings, vector.FormatToBuffer(DAT_010c8378));
        HK2NINS(vector, constraint->axis);
        AppendConstraintString(strings, vector.FormatToBuffer(DAT_010c8368));
        AppendConstraintString(strings, NiGetViewerString_00a7d550(DAT_010c835c, constraint->minAngle));
        AppendConstraintString(strings, NiGetViewerString_00a7d550(DAT_010c8350, constraint->maxAngle));
    }
}

extern int DAT_0126863c;
struct S_cc8ce0_Base {
    virtual ~S_cc8ce0_Base();
    void bhkSerializable_Kill();
};
struct FUN_00cc8ce0 : S_cc8ce0_Base {
    ~FUN_00cc8ce0();
};
// @fnv 0x00cc8ce0
FUN_00cc8ce0::~FUN_00cc8ce0() {
    bhkSerializable_Kill();
    DAT_0126863c--;
}

extern int DAT_01268640;

// @fnv 0x00cc8d50
// src: COMMUNITY 0x00cc8d50
int* __cdecl bhkBallSocketConstraintChain_GetRTTI()
{
    return &DAT_01268640;
}

// @fnv 0x00cc8d60
// src: GUESS 0x00cc8d60 (confidence: low)
int __cdecl Object_ComputeValue_00cc8d60()
{
    return 44;
}

extern int DAT_01268f84;

// @fnv 0x00cc8d70
// src: COMMUNITY 0x00cc8d70
int* bhkConstraintChain_GetRTTI()
{
    return &DAT_01268f84;
}

namespace fnv_00cc8dc0 {
extern int g_ctorCountA;
extern int g_ctorCountB;
extern int g_ctorCountD;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct OwnerBase {
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw() {
        return Object_DispatchCommandFour(size);
    }
};

struct ChainA_cls : public OwnerBase {
    virtual void unkA0();
    unsigned int m_0c;
    ChainA_cls() {
        m_0c = 0;
        g_ctorCountA += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        g_ctorCountB += 1;
    }
};

struct SpawnedObject : public ChainB_cls {
    virtual void unkD2();
    SpawnedObject() {
        g_ctorCountD += 1;
    }
};

// Allocates and constructs a new SpawnedObject via its operator new and returns the pointer.
// @fnv 0x00cc8dc0
// src: EXE 0x00cc8dc0
SpawnedObject* bhkBallSocketConstraintChain_CreateObject() {
    return new SpawnedObject();
}
}  // namespace fnv_00cc8dc0

void __cdecl bhkStream_SaveBinary(NiStream& stream, void* pValue);

struct HavokData_cc8 {
    char pad[0x24];
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
};

struct FUN_00cc8f60_cls {
    int unk00;
    HavokData_cc8* m_pUserData;
    char pad08[0x18];
    int m_20;

    void hkConstraintChainCinfo_SaveBinary(NiStream& stream);
    void hkBallSocketChainCinfo_SaveBinary(NiStream& stream);
};

// @fnv 0x00cc8f60
// src: XBOX_PDB 0x00cc8f60
void FUN_00cc8f60_cls::hkBallSocketChainCinfo_SaveBinary(NiStream& stream)
{
    HavokData_cc8* pkData = m_pUserData;
    bhkStream_SaveBinary(stream, &m_20);
    SerializeValue(stream, pkData->m_f28);
    SerializeValue(stream, pkData->m_f24);
    SerializeValue(stream, pkData->m_f2c);
    SerializeValue(stream, pkData->m_f30);
    hkConstraintChainCinfo_SaveBinary(stream);
}

extern __declspec(thread) int g_iCC90D0MemContext;

void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();

class CC90D0RefObject {
public:
    CC90D0RefObject();
    virtual ~CC90D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class CC90D0Level1 : public CC90D0RefObject {
public:
    CC90D0Level1() : m_pPointer(0) { ++ms_uiInstances; }
    virtual ~CC90D0Level1();

    void* m_pPointer;

    static unsigned int ms_uiInstances;
};

class CC90D0Level2 : public CC90D0Level1 {
public:
    CC90D0Level2() { ++ms_uiInstances; }
    virtual ~CC90D0Level2();

    static unsigned int ms_uiInstances;
};

class CC90D0Level3 : public CC90D0Level2 {
public:
    CC90D0Level3() { ++ms_uiInstances; }
    virtual ~CC90D0Level3();

    static unsigned int ms_uiInstances;
};

class CC90D0World {
public:
    void AddObject(CC90D0Level3* pkObject, void* pvInfo);

    CC90D0Level3* CreateAndAddObject(void* pvInfo);
};

// Creates a CC90D0Level3, adds it to the world with pvInfo, and returns it.
// @fnv 0x00cc90d0
CC90D0Level3* CC90D0World::CreateAndAddObject(void* pvInfo)
{
    AutoMemContext kContext(0x10);
    bhkSerializable_CloneCritLock();
    CC90D0Level3* pkObject = new CC90D0Level3;
    AddObject(pkObject, pvInfo);
    bhkSerializable_CloneCritUnlock();
    return pkObject;
}

class hkMemoryRouter;
namespace fnv_00cc94b0 {

 // Opaque tag preserves the existing external function signature.

hkMemoryRouter* hkMemoryRouter_getInstance();

struct SpawnedScopeOwner;

struct SpawnedScopeGuard {
    SpawnedScopeOwner* m_pSharedOwner;
    SpawnedScopeGuard(SpawnedScopeOwner* owner) : m_pSharedOwner(owner) {}
    ~SpawnedScopeGuard();
};

struct SpawnedScopeBase {
    void Cleanup();
};

struct SpawnedScopeOwner : public SpawnedScopeBase {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCap;

    void FreeSpawnedStorage();
};

SpawnedScopeGuard::~SpawnedScopeGuard()
{
    m_pSharedOwner->Cleanup();
}

// Frees m_pData through the allocator when m_uCap is not flagged, then resets m_pData and m_uCap to the empty state.
// @fnv 0x00cc94b0
void SpawnedScopeOwner::FreeSpawnedStorage()
{
    SpawnedScopeGuard guard(this);

    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    ::hkMemoryAllocator* pAllocator = reinterpret_cast<::hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder)->m_heap);
    unsigned int uCapacity = m_uCap;
    m_iArrayLength = 0;
    if ((uCapacity & 0x80000000u) == 0) {
        void* pData = m_pData;
        FreeAudioArray(pAllocator, pData, (uCapacity & 0x3fffffffu) * 16);
    }
    m_pData = 0;
    m_uCap = 0x80000000u;
}
}  // namespace fnv_00cc94b0

extern int DAT_01268648;

struct FUN_00cc9640 : bhkConstraint
{
    ~FUN_00cc9640();
};

// @fnv 0x00cc9640
FUN_00cc9640::~FUN_00cc9640()
{
    ReleaseConstraint(this);
    --DAT_01268648;
}

extern int DAT_0108febc;
extern int DAT_010c8b0c;
extern int DAT_01268188;
extern int DAT_01268648;

struct PhysicsAllocator {
    static void* __cdecl operator new(unsigned int size);
};

struct PhysicsReference {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    PhysicsReference();
};

struct PhysicsObject : PhysicsAllocator, PhysicsReference {
    unsigned int m_uiData;

    PhysicsObject() : PhysicsReference()
    {
        unsigned int count = 1;
        m_pVtable = &DAT_0108febc;
        m_uiData = 0;
        DAT_01268188 += count;
        m_pVtable = &DAT_010c8b0c;
        DAT_01268648 += count;
    }
};

// Allocates and constructs a new PhysicsObject via PhysicsAllocator::operator new and returns it.
// @fnv 0x00cc9700
PhysicsObject* __cdecl CreatePhysicsObject()
{
    return new PhysicsObject;
}

// MakeClone for a Havok wrapper: under the world lock, create a new wrapper and copy our data into it.

extern __declspec(thread) int g_iCC9940AllocTag;

void __cdecl CC9940LockWorld();
void __cdecl CC9940UnlockWorld();

extern int g_iCC9940RefObjectCount;
extern int g_iCC9940WrapperCount;

class CC9940Root {
public:
    CC9940Root();
    virtual ~CC9940Root();
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class CC9940Holder : public CC9940Root {
public:
    CC9940Holder() : m_pkHavokObject(0) {}
    virtual ~CC9940Holder();
    void* m_pkHavokObject;
};

class CC9940RefObject : public CC9940Holder {
public:
    CC9940RefObject() { ++g_iCC9940RefObjectCount; }
    virtual ~CC9940RefObject();
};

class CC9940Wrapper : public CC9940RefObject {
public:
    CC9940Wrapper() { ++g_iCC9940WrapperCount; }
    virtual ~CC9940Wrapper();

    void CopyMemberData(CC9940Wrapper* pkDest, int iCloning);
    CC9940Wrapper* bhkBallAndSocketConstraint_Clone(int iCloning);
};

// @fnv 0x00cc9940
// src: COMMUNITY 0x00cc9940
CC9940Wrapper* CC9940Wrapper::bhkBallAndSocketConstraint_Clone(int iCloning)
{
    AutoMemContext kScope(0x10);
    CC9940LockWorld();
    CC9940Wrapper* pkClone = new CC9940Wrapper;
    CopyMemberData(pkClone, iCloning);
    CC9940UnlockWorld();
    return pkClone;
}

template <class T>
inline void BCC9B80BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void BCC9B80LoadBinary(NiStream& kStream, T& value)
{
    BCC9B80BinaryStreamLoad(*InputStream(kStream), &value);
}



struct BCC9B80ShapeData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_kMin;
    hkVector4 m_kMax;
};

class BCC9B80Base {
public:
    void LoadBinary(NiStream& kStream);

    int unk00;
    BCC9B80ShapeData* m_pUserData;
};

class FUN_00cc9b80_cls : public BCC9B80Base {
public:
    void hkBallAndSocketConstraintCinfo_LoadBinary(NiStream& kStream);
};

// Loads the base data, then reads the shape data's m_kMin and m_kMax vectors from the stream.
// @fnv 0x00cc9b80
// src: XBOX_PDB 0x00cc9b80
void FUN_00cc9b80_cls::hkBallAndSocketConstraintCinfo_LoadBinary(NiStream& kStream)
{
    BCC9B80Base::LoadBinary(kStream);

    BCC9B80ShapeData* pkData = m_pUserData;
    BCC9B80LoadBinary(kStream, pkData->m_kMin);
    BCC9B80LoadBinary(kStream, pkData->m_kMax);
}

namespace fnv_00cc9bf0 {



struct HavokData_cc9 {
    char pad[0x20];
    hkVector4 m_kA;
    hkVector4 m_kB;
};

struct FUN_00cc9bf0_cls {
    int unk00;
    HavokData_cc9* m_pUserData;

    void hkConstraintCinfo_SaveBinary(NiStream& stream);
    void WriteHavokData(NiStream& stream);
};

// @fnv 0x00cc9bf0
void FUN_00cc9bf0_cls::WriteHavokData(NiStream& stream)
{
    hkConstraintCinfo_SaveBinary(stream);
    HavokData_cc9* pkData = m_pUserData;
    SerializeValue(stream, pkData->m_kA);
    SerializeValue(stream, pkData->m_kB);
}
}  // namespace fnv_00cc9bf0

class CC9C60Base {
public:
    virtual ~CC9C60Base();

    void Shutdown();
};

class FUN_00cc9c60 : public CC9C60Base {
public:
    virtual ~FUN_00cc9c60();

    static unsigned int ms_uiInstances;
};

// Destructor that calls Shutdown and decrements the static instance counter ms_uiInstances.
// @fnv 0x00cc9c60
FUN_00cc9c60::~FUN_00cc9c60()
{
    Shutdown();
    --ms_uiInstances;
}



struct BaseObject {
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    BaseObject(int a, int b);
    virtual ~BaseObject();
};

struct FUN_00cc9d00 : BaseObject {
    hkReferencedObject* m_pPointer;
    FUN_00cc9d00(int a, int b, hkReferencedObject* pkObject);
    virtual ~FUN_00cc9d00();
};

// @fnv 0x00cc9d00
FUN_00cc9d00::FUN_00cc9d00(int aiArg1, int aiArg2, hkReferencedObject* pkObject) : BaseObject(aiArg1, aiArg2) {
    m_pPointer = pkObject;
    if (pkObject)
        pkObject->addReference();
}

struct CpuInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke();
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    CpuInterface* target;
    void hkpMoppBvTreeShape_getContainer();
};
// @fnv 0x00cc9d70
// src: HAVOK_LIB 0x00cc9d70
void CpuObject::hkpMoppBvTreeShape_getContainer()
{
    target->Invoke();
}

class hkMemoryRouter;
namespace fnv_00cc9d80 {

 // Opaque tag preserves the existing external function signature.

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00cc9d80_cls {
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d54960();

    FUN_00cc9d80_cls* FUN_00cc9d80(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00d54960, then if bit 0 of acFlags is set frees this via the allocator from FUN_00c85750 using m_uSize, and returns this.
// @fnv 0x00cc9d80
FUN_00cc9d80_cls* FUN_00cc9d80_cls::FUN_00cc9d80(unsigned char acFlags)
{
    FUN_00d54960();
    if (acFlags & 1) {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder)->m_heap);
        FreeAudioMemory(pAllocator, this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00cc9d80

extern int DAT_01268658;

// @fnv 0x00cc9db0
// src: COMMUNITY 0x00cc9db0
void* __cdecl bhkMoppBvTreeShape_GetRTTI()
{
    return &DAT_01268658;
}

// @fnv 0x00cc9dc0
// src: COMMUNITY 0x00cc9dc0
int __cdecl bhkMoppBvTreeShape_GetCinfoSize() { return 16; }

struct S_00cc9df0_Val {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_f;
};
struct S_00cc9df0_Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S_00cc9df0_Val* m_kPointA;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    S_00cc9df0_Val* m_kPointB;
};
struct S_00cc9df0_Out {
    int unk00;
    int unk04;
    S_00cc9df0_Val* m_v;
    float m_fValue;
};
struct S_00cc9df0_Cls;
inline S_00cc9df0_Val* GetA(S_00cc9df0_Data* d) { return d ? d->m_kPointA : 0; }
inline S_00cc9df0_Val* GetB(S_00cc9df0_Data* d) { return d ? d->m_kPointB : 0; }
struct S_00cc9df0_Cls {
    int unk00;
    int unk04;
    S_00cc9df0_Data* m_iFourthElementInteger;
    void bhkBvTreeShape_CopyCinfo(S_00cc9df0_Out* out);
    void SetRatioFromValues(S_00cc9df0_Out* out);
};
inline S_00cc9df0_Data* GetD(S_00cc9df0_Cls* c) { return c ? c->m_iFourthElementInteger : 0; }
// @fnv 0x00cc9df0
void S_00cc9df0_Cls::SetRatioFromValues(S_00cc9df0_Out* out)
{
    bhkBvTreeShape_CopyCinfo(out);
    out->m_v = GetB(GetD(this));
    S_00cc9df0_Data* pData = GetD(this);
    if (pData && pData->m_kPointA) {
        S_00cc9df0_Data* pData2 = GetD(this);
        if (GetB(pData2)) {
            S_00cc9df0_Val* a = GetA(GetD(this));
            S_00cc9df0_Val* b = GetB(GetD(this));
            out->m_fValue = a->m_f / b->m_f;
        }
    }
}

// Apply a scale: multiply the Havok shape's radius by the scale, refresh the shape, then the base handles the rest.

struct CC9F10Scale {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScale;
};

struct CC9F10Shape {
    void Refresh();
};

struct CC9F10HavokData {
    int unk00;
    int unk04;
    CC9F10Shape* m_pkShape;
    float m_fBoundRadius;
};

class CC9F10Object {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual CC9F10HavokData* GetHavokData(bool* pbOwned);

    void ApplyBaseScale(int iFlags, CC9F10Scale* pkScale);
    void bhkMoppBvTreeShape_CopyMembers(int iFlags, CC9F10Scale* pkScale);
};

// Gets the havok data, multiplies its scale by pkScale->m_fScale, refreshes the shape if present, then calls ApplyBaseScale.
// @fnv 0x00cc9f10
// src: XBOX_PDB 0x00cc9f10
void CC9F10Object::bhkMoppBvTreeShape_CopyMembers(int iFlags, CC9F10Scale* pkScale)
{
    bool bIsValid;
    CC9F10HavokData* pkData = GetHavokData(&bIsValid);
    pkData->m_fBoundRadius = pkScale->m_fScale * pkData->m_fBoundRadius;
    if (pkData->m_pkShape)
        pkData->m_pkShape->Refresh();
    ApplyBaseScale(iFlags, pkScale);
}

struct Owner_Target {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
};

class FUN_00cca0e0_cls {
public:
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual Owner_Target* v45(unsigned int* p);
    void bhkBvTreeShape_LoadBinary(unsigned int a);
    void bhkMoppBvTreeShape_LoadBinary(unsigned int param);
};

void __cdecl ReadBlobObject(unsigned int a, unsigned int* b);

// Calls FUN_00ca4ec0 with param, gets an Owner_Target via v45, then stores the result of ReadBlobObject into its m_08 field.
// @fnv 0x00cca0e0
// src: XBOX_PDB 0x00cca0e0
void FUN_00cca0e0_cls::bhkMoppBvTreeShape_LoadBinary(unsigned int uiValue) {
    unsigned int value = *(volatile unsigned int*)&uiValue;
    bhkBvTreeShape_LoadBinary(value);
    Owner_Target* o = v45(&uiValue);
    unsigned int local = 0;
    ReadBlobObject(value, &local);
    o->m_08 = local;
}

extern __declspec(thread) int g_iCCA1B0MemContext;

void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();

class CCA1B0RefObject {
public:
    CCA1B0RefObject();
    virtual ~CCA1B0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class CCA1B0Level1 : public CCA1B0RefObject {
public:
    CCA1B0Level1() : m_pkFirst(0), m_pkSecond(0) { ++ms_uiInstances; }
    virtual ~CCA1B0Level1();

    void* m_pkFirst;
    void* m_pkSecond;

    static unsigned int ms_uiInstances;
};

class CCA1B0Level2 : public CCA1B0Level1 {
public:
    CCA1B0Level2() { ++ms_uiInstances; }
    virtual ~CCA1B0Level2();

    static unsigned int ms_uiInstances;
};

class CCA1B0Level3 : public CCA1B0Level2 {
public:
    CCA1B0Level3() { ++ms_uiInstances; }
    virtual ~CCA1B0Level3();

    static unsigned int ms_uiInstances;
};

class CCA1B0World {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void AddObject(CCA1B0Level3* pkObject, void* pvInfo);

    CCA1B0Level3* bhkMoppBvTreeShape_CreateClone(void* pvInfo);
};

// Creates a CCA1B0Level3, registers it via AddObject with pvInfo, and returns it.
// @fnv 0x00cca1b0
// src: COMMUNITY 0x00cca1b0
CCA1B0Level3* CCA1B0World::bhkMoppBvTreeShape_CreateClone(void* pvInfo)
{
    AutoMemContext kContext(0x10);
    bhkSerializable_CloneCritLock();
    CCA1B0Level3* pkObject = new CCA1B0Level3;
    AddObject(pkObject, pvInfo);
    bhkSerializable_CloneCritUnlock();
    return pkObject;
}

namespace fnv_00cca4e0 {
extern int DAT_012680f8;
extern int DAT_012682cc;
extern int DAT_01268654;

struct FUN_00c87c30_owner {
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct ChainA_cls : public FUN_00c87c30_owner {
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls() {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        DAT_012682cc += 1;
    }
};

struct FUN_00cca4e0 : public ChainB_cls {
    virtual void unkC2();
    FUN_00cca4e0(unsigned int a);
    void bhkMoppBvTreeShape_Init(unsigned int a);
};

// Increments DAT_01268654 and calls FUN_00cca360 with the constructor argument.
// @fnv 0x00cca4e0
FUN_00cca4e0::FUN_00cca4e0(unsigned int uiValue) {
    DAT_01268654 += 1;
    bhkMoppBvTreeShape_Init(uiValue);
}
}  // namespace fnv_00cca4e0

extern int DAT_01268664;

// @fnv 0x00cca940
// src: COMMUNITY 0x00cca940
int __cdecl bhkTriangleShape_GetRTTI() {
    return reinterpret_cast<int>(&DAT_01268664);
}

class CCAA80Object {
public:
    CCAA80Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// Allocates and constructs a new CCAA80Object, returning the pointer.
// @fnv 0x00ccaa80
CCAA80Object* __cdecl CreateCCAA80Object()
{
    return new CCAA80Object;
}

extern "C" void _ReadWriteBarrier(void);

struct FUN_00ccab60_arg {
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    char unk1E0;
    char unk1E1;
    char unk1E2;
    char unk1E3;
    char unk1E4;
    char m1E5;
};

struct FUN_00ccab60_rec {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    unsigned int m28;
    unsigned int m2C;
    unsigned int m30;
    unsigned int m34;
    unsigned int m38;
    unsigned int m3C;
};

struct FUN_00ccab60_cls {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual FUN_00ccab60_rec* GetRec(FUN_00ccab60_arg*& a);
    void bhkConvexShape_LoadBinary(FUN_00ccab60_arg* a);
    void ProcessRecord(FUN_00ccab60_arg* a1);
};

// Calls FUN_00c9fbc0 on the argument, then unless m1E5 is 1, byte-swaps the 12 unsigned fields m10 through m3C of the record returned by GetRec.
// @fnv 0x00ccab60
void FUN_00ccab60_cls::ProcessRecord(FUN_00ccab60_arg* a1)
{
    FUN_00ccab60_arg* volatile* pa = &a1;
    FUN_00ccab60_arg* a = *pa;
    bhkConvexShape_LoadBinary(a);
    if (a->m1E5 != 1) {
        FUN_00ccab60_rec* r = GetRec(a1);
        r->m10 = _byteswap_ulong(r->m10);
        _ReadWriteBarrier();
        r->m14 = _byteswap_ulong(r->m14);
        _ReadWriteBarrier();
        r->m18 = _byteswap_ulong(r->m18);
        _ReadWriteBarrier();
        r->m1C = _byteswap_ulong(r->m1C);
        _ReadWriteBarrier();
        r->m20 = _byteswap_ulong(r->m20);
        _ReadWriteBarrier();
        r->m24 = _byteswap_ulong(r->m24);
        _ReadWriteBarrier();
        r->m28 = _byteswap_ulong(r->m28);
        _ReadWriteBarrier();
        r->m2C = _byteswap_ulong(r->m2C);
        _ReadWriteBarrier();
        r->m30 = _byteswap_ulong(r->m30);
        _ReadWriteBarrier();
        r->m34 = _byteswap_ulong(r->m34);
        _ReadWriteBarrier();
        r->m38 = _byteswap_ulong(r->m38);
        _ReadWriteBarrier();
        r->m3C = _byteswap_ulong(r->m3C);
        _ReadWriteBarrier();
    }
}

struct FUN_00ccabf0_Param {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned char unk01e4;
};

struct FUN_00ccabf0_Data {
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0c;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
    volatile unsigned int unk18;
    volatile unsigned int unk1c;
    volatile unsigned int unk20;
    volatile unsigned int unk24;
    volatile unsigned int unk28;
    volatile unsigned int unk2c;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    volatile unsigned int unk3c;
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long value);

struct FUN_00ccabf0_class {
    virtual void FUN_00ccabf0_00();
    virtual void FUN_00ccabf0_01();
    virtual void FUN_00ccabf0_02();
    virtual void FUN_00ccabf0_03();
    virtual void FUN_00ccabf0_04();
    virtual void FUN_00ccabf0_05();
    virtual void FUN_00ccabf0_06();
    virtual void FUN_00ccabf0_07();
    virtual void FUN_00ccabf0_08();
    virtual void FUN_00ccabf0_09();
    virtual void FUN_00ccabf0_0a();
    virtual void FUN_00ccabf0_0b();
    virtual void FUN_00ccabf0_0c();
    virtual void FUN_00ccabf0_0d();
    virtual void FUN_00ccabf0_0e();
    virtual void FUN_00ccabf0_0f();
    virtual void FUN_00ccabf0_10();
    virtual void FUN_00ccabf0_11();
    virtual void FUN_00ccabf0_12();
    virtual void FUN_00ccabf0_13();
    virtual void FUN_00ccabf0_14();
    virtual void FUN_00ccabf0_15();
    virtual void FUN_00ccabf0_16();
    virtual void FUN_00ccabf0_17();
    virtual void FUN_00ccabf0_18();
    virtual void FUN_00ccabf0_19();
    virtual void FUN_00ccabf0_1a();
    virtual void FUN_00ccabf0_1b();
    virtual void FUN_00ccabf0_1c();
    virtual void FUN_00ccabf0_1d();
    virtual void FUN_00ccabf0_1e();
    virtual void FUN_00ccabf0_1f();
    virtual void FUN_00ccabf0_20();
    virtual void FUN_00ccabf0_21();
    virtual void FUN_00ccabf0_22();
    virtual void FUN_00ccabf0_23();
    virtual void FUN_00ccabf0_24();
    virtual void FUN_00ccabf0_25();
    virtual void FUN_00ccabf0_26();
    virtual void FUN_00ccabf0_27();
    virtual void FUN_00ccabf0_28();
    virtual void FUN_00ccabf0_29();
    virtual void FUN_00ccabf0_2a();
    virtual void FUN_00ccabf0_2b();
    virtual void FUN_00ccabf0_2c();

    virtual FUN_00ccabf0_Data* __thiscall FUN_00ccabf0_45(unsigned char* value);

    void __thiscall bhkConvexShape_SaveBinary(FUN_00ccabf0_Param* param);
    void __thiscall bhkTriangleShape_SaveBinary(FUN_00ccabf0_Param* param);
};

// @fnv 0x00ccabf0
// src: XBOX_PDB 0x00ccabf0
void __thiscall FUN_00ccabf0_class::bhkTriangleShape_SaveBinary(FUN_00ccabf0_Param* param)
{
    unsigned char local;
    FUN_00ccabf0_Data* data = this->FUN_00ccabf0_45(&local);

    if (param->unk01e4 != 1) {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1c = _byteswap_ulong(data->unk1c);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2c = _byteswap_ulong(data->unk2c);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3c = _byteswap_ulong(data->unk3c);
    }

    this->bhkConvexShape_SaveBinary(param);

    if (param->unk01e4 != 1) {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1c = _byteswap_ulong(data->unk1c);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2c = _byteswap_ulong(data->unk2c);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3c = _byteswap_ulong(data->unk3c);
    }
}

namespace fnv_00ccacf0 {
struct S_00ccacf0_Tls {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00ccacf0_Tls DAT_tls;

struct S_00ccacf0_Ctx {
    int saved;
    __forceinline S_00ccacf0_Ctx(int c) { saved = DAT_tls.ctx; DAT_tls.ctx = c; }
    __forceinline ~S_00ccacf0_Ctx() { DAT_tls.ctx = saved; }
};

void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int n);

struct S_00ccacf0_Obj {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    S_00ccacf0_Obj();
    static void* operator new(unsigned int n) { return Object_DispatchCommandFour(n); }
    static void operator delete(void*) {}
};

struct S_00ccacf0_Owner {
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_c4(S_00ccacf0_Obj* p, int a);
    S_00ccacf0_Obj* bhkTriangleShape_CreateClone(int a);
};

// Sets the TLS context to 0x10, allocates a new S_00ccacf0_Obj, passes it with a to vfn_c4, and returns the object.
// @fnv 0x00ccacf0
// src: XBOX_PDB 0x00ccacf0
S_00ccacf0_Obj* S_00ccacf0_Owner::bhkTriangleShape_CreateClone(int a)
{
    S_00ccacf0_Ctx guard(0x10);
    bhkSerializable_CloneCritLock();
    S_00ccacf0_Obj* p = new S_00ccacf0_Obj;
    vfn_c4(p, a);
    bhkSerializable_CloneCritUnlock();
    return p;
}
}  // namespace fnv_00ccacf0

namespace fnv_00ccae90 {
struct FUN_00ccae90_Object {
    unsigned int m_type;
    unsigned int m_sReferenceCount;
    unsigned int m_flags;
    void* m_resource;
    void __thiscall ReleaseResource(char release);
};
struct ResourceManager {
    void __thiscall MemoryManager_Deallocate(void* resource);
};
extern ResourceManager DAT_011f6238;
extern __declspec(thread) unsigned int tlsCurrentContext;
// @fnv 0x00ccae90
void FUN_00ccae90_Object::ReleaseResource(char release) {
    unsigned int previousContext = tlsCurrentContext;
    tlsCurrentContext = 0x10;
    if (release) {
        DAT_011f6238.MemoryManager_Deallocate(m_resource);
        m_resource = 0;
    }
    tlsCurrentContext = previousContext;
}
}  // namespace fnv_00ccae90

extern __declspec(thread) int g_iCCB080AllocTag;

extern const char* g_pcCCB080Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class FUN_00ccb080_cls {
public:
    void bhkConvexShape_GetViewerStrings(StrArr* pkArray);
    void AddNameToArray(StrArr* pkArray);
};

// Sets an allocation tag, calls FUN_00c9fc50 on the array, then appends the string returned by FUN_00a7d330(g_pcCCB080Name).
// @fnv 0x00ccb080
void FUN_00ccb080_cls::AddNameToArray(StrArr* pkArray)
{
    AutoMemContext kScope(0x10);
    bhkConvexShape_GetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCCB080Name);
    AppendStringReference(pkArray, pcName);
}

extern int DAT_01268670;
// @fnv 0x00ccb130
// src: COMMUNITY 0x00ccb130
void* __cdecl bhkPlaneShape_GetRTTI() {
    return &DAT_01268670;
}

// @fnv 0x00ccb140
// src: COMMUNITY 0x00ccb140
int __cdecl _sub_CCB140_GetCinfoSize()
{
    return 64;
}

extern int g_unk01268f90;

// @fnv 0x00ccb150
// src: COMMUNITY 0x00ccb150
void* bhkHeightFieldShape_GetRTTI()
{
    return &g_unk01268f90;
}

extern int DAT_01030bf4;
extern int DAT_010ca5c4;
extern int DAT_010ca4dc;
extern int DAT_012680f8;
extern int DAT_01268f8c;
extern int DAT_0126866c;

struct AllocationBase {
    static void* __cdecl operator new(unsigned int size);
};

struct S_00c87c30_Base {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    S_00c87c30_Base();
};

struct TargetObject : AllocationBase, S_00c87c30_Base {
    TargetObject() : S_00c87c30_Base() {
        m_pVtable = &DAT_01030bf4;
        unsigned int count = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
        DAT_012680f8 += count;
        m_pVtable = &DAT_010ca5c4;
        DAT_01268f8c += count;
        m_pVtable = &DAT_010ca4dc;
        DAT_0126866c += count;
    }
};

// Allocates and constructs a TargetObject, returning the new instance.
// @fnv 0x00ccb200
TargetObject* __cdecl CreateTargetObject() {
    return new TargetObject();
}

struct FUN_00ccb2b0_Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float m_f10;
};

struct FUN_00ccb2b0_Obj {
    void** m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;
};

class FUN_00ccb2b0_cls {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual FUN_00ccb2b0_Obj* GetScale(unsigned char* flag);
    void bhkShape_CopyMembers(int a1, FUN_00ccb2b0_Param* p2);
    void bhkPlaneShape_CopyMembers(int a1, FUN_00ccb2b0_Param* p2);
};

// Gets the scale object, multiplies its eight float fields by p2->m_f10 when it is not 1.0, then calls FUN_00c84df0.
// @fnv 0x00ccb2b0
// src: XBOX_PDB 0x00ccb2b0
void FUN_00ccb2b0_cls::bhkPlaneShape_CopyMembers(int aiArg, FUN_00ccb2b0_Param* pParam)
{
    unsigned char flag;
    FUN_00ccb2b0_Obj* obj = this->GetScale(&flag);
    float t = pParam->m_f10;
    if (t != 1.0f) {
        obj->m_f20 *= t;
        obj->m_f24 *= t;
        obj->m_f28 *= t;
        obj->m_f2c *= t;
        obj->m_f30 *= t;
        obj->m_f34 *= t;
        obj->m_f38 *= t;
        obj->m_f3c *= t;
    }
    this->bhkShape_CopyMembers(aiArg, pParam);
}

inline void CCB350Swap(unsigned long& ulValue) { ulValue = _byteswap_ulong(ulValue); }

struct CCB350Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_aulValues[12];
};

class CCB350Base {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual CCB350Data* GetData(unsigned int* puiSize);

    void LoadBase(NiStream* pkStream);
};

class CCB350Object : public CCB350Base {
public:
    void bhkPlaneShape_LoadBinary(NiStream* pkStream);
};

// Loads the base data from the stream, then if the stream is not little-endian byte-swaps the first twelve values of the retrieved data block.
// @fnv 0x00ccb350
// src: XBOX_PDB 0x00ccb350
void CCB350Object::bhkPlaneShape_LoadBinary(NiStream* pkStream)
{
    LoadBase(pkStream);
    if (StreamField<unsigned char>(*pkStream, 0x1e5) != 1) {
        unsigned int uiSize;
        CCB350Data* pkData = GetData(&uiSize);
        CCB350Swap(pkData->m_aulValues[0]);
        CCB350Swap(pkData->m_aulValues[1]);
        CCB350Swap(pkData->m_aulValues[2]);
        CCB350Swap(pkData->m_aulValues[3]);
        CCB350Swap(pkData->m_aulValues[4]);
        CCB350Swap(pkData->m_aulValues[5]);
        CCB350Swap(pkData->m_aulValues[6]);
        CCB350Swap(pkData->m_aulValues[7]);
        CCB350Swap(pkData->m_aulValues[8]);
        CCB350Swap(pkData->m_aulValues[9]);
        CCB350Swap(pkData->m_aulValues[10]);
        CCB350Swap(pkData->m_aulValues[11]);
    }
}

struct FUN_00ccb3e0_Data {
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
    volatile unsigned int unk18;
    volatile unsigned int unk1C;
    volatile unsigned int unk20;
    volatile unsigned int unk24;
    volatile unsigned int unk28;
    volatile unsigned int unk2C;
    volatile unsigned int unk30;
    volatile unsigned int unk34;
    volatile unsigned int unk38;
    volatile unsigned int unk3C;
};

struct FUN_00ccb3e0_Class {
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void bhkPlaneShape_SaveBinary(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00ccb3e0_Data* bhkPlaneShape_CreateCinfo(unsigned char* value);
    void __thiscall bhkShape_SaveBinary(unsigned char* arg);
};

// @fnv 0x00ccb3e0
// src: XBOX_PDB 0x00ccb3e0
void __thiscall FUN_00ccb3e0_Class::bhkPlaneShape_SaveBinary(unsigned char* arg)
{
    unsigned char value;
    FUN_00ccb3e0_Data* data = bhkPlaneShape_CreateCinfo(&value);

    if (arg[0x1e4] != 1)
    {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1C = _byteswap_ulong(data->unk1C);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2C = _byteswap_ulong(data->unk2C);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3C = _byteswap_ulong(data->unk3C);
    }

    bhkShape_SaveBinary(arg);

    if (arg[0x1e4] != 1)
    {
        data->unk10 = _byteswap_ulong(data->unk10);
        data->unk14 = _byteswap_ulong(data->unk14);
        data->unk18 = _byteswap_ulong(data->unk18);
        data->unk1C = _byteswap_ulong(data->unk1C);
        data->unk20 = _byteswap_ulong(data->unk20);
        data->unk24 = _byteswap_ulong(data->unk24);
        data->unk28 = _byteswap_ulong(data->unk28);
        data->unk2C = _byteswap_ulong(data->unk2C);
        data->unk30 = _byteswap_ulong(data->unk30);
        data->unk34 = _byteswap_ulong(data->unk34);
        data->unk38 = _byteswap_ulong(data->unk38);
        data->unk3C = _byteswap_ulong(data->unk3C);
    }
}

namespace fnv_00ccb4e0 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

__declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

extern "C" void __cdecl bhkSerializable_CloneCritLock();
extern "C" void __cdecl bhkSerializable_CloneCritUnlock();
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);
extern "C" int DAT_012680f8;
extern "C" int DAT_01268f8c;
extern "C" int DAT_0126866c;

struct SpawnRoot_cls
{
    virtual void v_root();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    SpawnRoot_cls();
    static void* operator new(unsigned int size) throw() { return Object_DispatchCommandFour(size); }
};

struct SpawnA_cls : SpawnRoot_cls
{
    virtual void v_a0();
    SpawnA_cls()
    {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct SpawnB_cls : SpawnA_cls
{
    virtual void v_b0();
    SpawnB_cls()
    {
        DAT_01268f8c += 1;
    }
};

struct SpawnC_cls : SpawnB_cls
{
    virtual void v_c0();
    SpawnC_cls()
    {
        DAT_0126866c += 1;
    }
};

struct FUN_00ccb4e0_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void Dispatch(SpawnC_cls* obj, unsigned int param);
    SpawnC_cls* CreateSpawnC(unsigned int param);
};

// Sets up a TLS guard, allocates a SpawnC_cls, dispatches it with param, and returns the new object.
// @fnv 0x00ccb4e0
SpawnC_cls* FUN_00ccb4e0_cls::CreateSpawnC(unsigned int param)
{
    TlsGuard_t guard;
    bhkSerializable_CloneCritLock();
    SpawnC_cls* o = new SpawnC_cls;
    Dispatch(o, param);
    bhkSerializable_CloneCritUnlock();
    return o;
}
}  // namespace fnv_00ccb4e0

typedef unsigned int CCB730size_t;

struct CCB730MemoryManager;
extern CCB730MemoryManager g_CCB730MemoryManager;

extern __declspec(thread) int g_CCB730AllocTag;

inline void* CCB730AlignedAlloc(unsigned int uiSize)
{
    char* pcMem = (char*)reinterpret_cast<MemoryManager&>(g_CCB730MemoryManager).Allocate(uiSize);
    unsigned char ucOffset = (unsigned char)(16 - ((unsigned char)(unsigned int)pcMem & 0xf));
    pcMem += ucOffset;
    pcMem[-1] = ucOffset;
    return pcMem;
}

struct CCB730Child {
    CCB730Child() throw()
        : m_pkOwnerManager(0), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {
    }

    void* m_pkOwnerManager;
    int unk04;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCB730size_t, void* pvMem) { return pvMem; }
};

struct CCB730Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCB730Child* m_pkChild;

    void bhkPlaneShape_CopyCinfo(CCB730Child* pkChild);
    CCB730Child* bhkPlaneShape_CreateCinfo(bool* pbCreated);
};

// @fnv 0x00ccb730
// src: XBOX_PDB 0x00ccb730
CCB730Child* CCB730Owner::bhkPlaneShape_CreateCinfo(bool* pbCreated)
{
    AutoMemContext kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (*pbCreated) {
        m_pkChild = new (CCB730AlignedAlloc(0x50)) CCB730Child();
        if (m_pParentNode)
            bhkPlaneShape_CopyCinfo(m_pkChild);
    }
    return m_pkChild;
}

extern int DAT_01268684;

// @fnv 0x00ccb990
// src: COMMUNITY 0x00ccb990
void* __cdecl bhkExtendedMeshShapeData_GetRTTI()
{
    return &DAT_01268684;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct FunObjBase_b9645 {
    FunObjBase_b9645();
    virtual void unk00();
    unsigned int m_04;
    static void* operator new(unsigned int size) throw() {
        return Object_DispatchCommandFour(size);
    }
};

struct FunObj_b9645 : public FunObjBase_b9645 {
    virtual void unk10();
    unsigned int m_08;
    unsigned int m_0c;
    FunObj_b9645() {
        m_08 = 0;
        m_0c = 0;
    }
};

// Allocates and constructs a new FunObj_b9645, returning the new object.
// @fnv 0x00ccb9a0
FunObj_b9645* CreateFunObj() {
    return new FunObj_b9645();
}

// Decompilation candidate for FUN_00ccba30 (0x00ccba30, 32 bytes).
//
// Shape: a member function that (1) forwards its single argument to a virtual
// slot of an object held at offset 0x14 of itself and (2) hands the same
// argument to its own member helper FUN_00aa0ad0.

struct TargetObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v15(NiStream* stream);
};

struct HC1Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    TargetObj* m_pEntryObject;
    bool __thiscall BSPackedAdditionalGeometryData_RegisterStreamables(NiStream* stream);
    void __thiscall bhkExtendedMeshShape_RegisterStreamables(NiStream* stream);
};

// @fnv 0x00ccba30
// src: XBOX_PDB 0x00ccba30
void HC1Base::bhkExtendedMeshShape_RegisterStreamables(NiStream* stream)
{
    m_pEntryObject->v15(stream);
    BSPackedAdditionalGeometryData_RegisterStreamables(stream);
}

struct FUN_00ccba50_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_14;
    char bhkShape_IsEqual(FUN_00ccba50_cls* p);
    char Equals(FUN_00ccba50_cls* p);
};

// @fnv 0x00ccba50
char FUN_00ccba50_cls::Equals(FUN_00ccba50_cls* apOther)
{
    char r = bhkShape_IsEqual(apOther);
    if (r)
        r = (m_14 == apOther->m_14);
    return r;
}

// GetValueForArg: thiscall, 37 bytes, 1 stack argument.
// Returns 0x24 when the argument is -1, otherwise it asks the object held in
// the member pointer at this+8 for a record and returns that record's +4 field.
struct FUN_00d55530_result {
    int m_00;
    int m_04;
};

struct FUN_00d55530_cls {
    FUN_00d55530_result* __thiscall hkpExtendedMeshShape_getMeshMaterial(int arg);
};

struct FUN_00ccba70_cls {
    int unk00;
    int unk04;
    FUN_00d55530_cls* m_08;
    int GetValueForArg(int arg);
};

// Returns 0x24 when arg is -1, otherwise returns m_04 of the result of FUN_00d55530(arg) on m_08 (or null if this is null).
// @fnv 0x00ccba70
int FUN_00ccba70_cls::GetValueForArg(int arg)
{
    int result = 0x24;
    FUN_00d55530_cls* pTarget = this ? m_08 : (FUN_00d55530_cls*)0;
    if (arg != -1) {
        result = pTarget->hkpExtendedMeshShape_getMeshMaterial(arg)->m_04;
    }
    return result;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p);

struct RefObjCC {
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};


struct FUN_00ccbaa0 {
    void* m_p0;
    NiPointer<RefObjCC> m_sp;
    FUN_00ccbaa0(RefObjCC* p);
};

// Constructs the holder with a null pointer and stores the given RefObjCC in the smart pointer, incrementing its reference count.
// @fnv 0x00ccbaa0
FUN_00ccbaa0::FUN_00ccbaa0(RefObjCC* apObject)
    : m_p0(0), m_sp(0)
{
    m_sp = apObject;
}

extern int DAT_0126867c;

// @fnv 0x00ccbb30
// src: COMMUNITY 0x00ccbb30
int __cdecl bhkExtendedMeshShape_GetRTTI() {
    return reinterpret_cast<int>(&DAT_0126867c);
}

// @fnv 0x00ccbb40
// src: COMMUNITY 0x00ccbb40
int __cdecl bhkPackedNiTriStripsShape_GetCinfoSize()
{
    return 0x20;
}

namespace fnv_00ccbb50 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

extern __declspec(thread) TlsBlock_t g_tlsBlock;

struct TlsFlagGuard
{
    int m_saved;
    TlsFlagGuard()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsFlagGuard()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

struct FUN_00ccbb50_pool
{
    void MemoryManager_Deallocate(int p);
};
extern FUN_00ccbb50_pool DAT_011f6238;

class FUN_00ccbb50_cls
{
public:
    unsigned int unk00;
    char* m_04;
    unsigned int unk08;
    char* m_0c;
    char* m_10;
    void UpdateState_00ccbb50();
};

// @fnv 0x00ccbb50
// src: GUESS 0x00ccbb50 (confidence: low)
void FUN_00ccbb50_cls::UpdateState_00ccbb50()
{
    TlsFlagGuard guard;
    if (m_04 != 0)
    {
        DAT_011f6238.MemoryManager_Deallocate((int)m_04);
    }
    if (m_0c != 0)
    {
        DAT_011f6238.MemoryManager_Deallocate((int)m_0c);
    }
    char* p = m_10;
    if (p != 0)
    {
        unsigned char len = (unsigned char)p[-1];
        DAT_011f6238.MemoryManager_Deallocate((int)(p - len));
    }
}
}  // namespace fnv_00ccbb50

namespace fnv_00ccc2f0 {
extern __declspec(thread) unsigned int g_tlsMemContext;

struct MemContextGuard {
    unsigned int uiOld;
    MemContextGuard(unsigned int uiNew) {
        uiOld = g_tlsMemContext;
        g_tlsMemContext = uiNew;
    }
    ~MemContextGuard() { g_tlsMemContext = uiOld; }
};

struct MemMgrStub {
    void* Allocate(unsigned int auiSize);
    void Deallocate(void* apMem);
};
extern MemMgrStub _g_memoryManager;

struct StreamStub {
    int unk00;
    int iPos;
    int (__cdecl* pfnWrite)(StreamStub*, void*, unsigned int, int, int);
};

struct SaveCtx {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    StreamStub* pStream;
};

struct Saveable {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4();
    virtual unsigned int GetSaveSize();

    unsigned int bhkExtendedMeshShape_LoadCInfo(SaveCtx* apCtx);
};

// Allocates a buffer of GetSaveSize() bytes, writes it to apCtx->pStream, advances the stream position, frees the buffer and returns the size.
// @fnv 0x00ccc2f0
// src: XBOX_PDB 0x00ccc2f0
unsigned int Saveable::bhkExtendedMeshShape_LoadCInfo(SaveCtx* apCtx) {
    MemContextGuard kGuard(0x10);
    unsigned int uiSize = GetSaveSize();
    void* pBuffer = _g_memoryManager.Allocate(uiSize);
    StreamStub* pStream = apCtx->pStream;
    pStream->iPos += pStream->pfnWrite(pStream, pBuffer, uiSize, 0, 0);
    _g_memoryManager.Deallocate(pBuffer);
    return uiSize;
}
}  // namespace fnv_00ccc2f0

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FNVRefObj;
struct FNVRefVTable {
    void (__thiscall *m_method00)(FNVRefObj*);
    void (__thiscall *m_release)(FNVRefObj*);
};
struct FNVRefObj {
    FNVRefVTable* m_ppVirtualMethodTable;
    volatile long m_refcount;
};
struct FNVHolder {
    void* m_ppVirtualMethodTable;
    FNVRefObj* m_object;
};
struct FNVParam {
    FNVRefObj* __thiscall FUN_00a63430();
};
struct FNVTarget {
    void* m_ppVirtualMethodTable;
    void __thiscall bhkShape_LinkObject(FNVParam*);
    void __thiscall AssignRefObject(FNVParam*);
};
typedef FNVHolder* (__thiscall *FNVQuery)(FNVTarget*, bool*);

// Queries a holder via vtable slot 45, swaps its m_object to the param's ref object with refcount updates, then calls FUN_00c84cc0.
// @fnv 0x00ccc3b0
void FNVTarget::AssignRefObject(FNVParam* param)
{
    bool initialized;
    FNVHolder* holder = reinterpret_cast<FNVQuery*>(m_ppVirtualMethodTable)[45](this, &initialized);
    FNVRefObj* object = param->FUN_00a63430();
    FNVRefObj* oldObject = holder->m_object;
    if (oldObject != object) {
        if (oldObject && InterlockedDecrement(&oldObject->m_refcount) == 0)
            oldObject->m_ppVirtualMethodTable->m_release(oldObject);
        holder->m_object = object;
        if (object)
            InterlockedIncrement(&object->m_refcount);
    }
    bhkShape_LinkObject(param);
}

struct S_00ccc620_Pair {
    int a;
    int b;
};
struct S_00ccc620_Obj {
    unsigned int unk00;
    float* unk04;
    unsigned int unk08;
    unsigned short* unk0c;
    S_00ccc620_Pair* unk10;
    void bhkExtendedMeshSubPart_SaveBinary(NiStream& kStream);
};
// Writes unk00, the unk04 array (unk00*3 elements), unk08, the unk0c array (unk08*3 elements), and unk10->a and unk10->b to the stream.
// @fnv 0x00ccc620
// src: XBOX_PDB 0x00ccc620
void S_00ccc620_Obj::bhkExtendedMeshSubPart_SaveBinary(NiStream& kStream)
{
    WriteBinaryArray(*OutputStream(kStream), &unk00, 1);
    WriteBinaryArray(*OutputStream(kStream), unk04, unk00 * 3);
    WriteBinaryArray(*OutputStream(kStream), &unk08, 1);
    WriteBinaryArray(*OutputStream(kStream), unk0c, unk08 * 3);
    WriteBinaryArray(*OutputStream(kStream), &unk10->a, 1);
    WriteBinaryArray(*OutputStream(kStream), &unk10->b, 1);
}



struct CCCF00Entity {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    hkVector4 m_kValue;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    float m_fMass;
};

class CCCF00RigidBody {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void Unlock(bool bLocked);
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void Lock(bool& bLocked);

    int unk04;
    CCCF00Entity* m_pkEntity;
    int unk0C;
    int unk10;
    void* m_pvLinked;

    void bhkShape_SaveBinary(NiStream& kStream);
    void bhkExtendedMeshShape_SaveBinary(NiStream& kStream);
};

// SaveBinary
// Locks the rigid body, writes the entity's mass and vector to the stream, saves the linked ID, then unlocks.
// @fnv 0x00cccf00
// src: XBOX_PDB 0x00cccf00
void CCCF00RigidBody::bhkExtendedMeshShape_SaveBinary(NiStream& kStream) {
    bool bLocked;
    Lock(bLocked);
    CCCF00Entity* pkEntity = m_pkEntity;
    bhkShape_SaveBinary(kStream);
    float fMass = pkEntity->m_fMass;
    OutputStream(kStream)->Write(&fMass, sizeof(fMass));
    OutputStream(kStream)->Write(&pkEntity->m_kValue, sizeof(hkVector4));
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pvLinked));
    Unlock(bLocked);
}

// FUN_00ccd0f0 : a one-line function - getter
extern int g_target_00ccd0f0;
// @fnv 0x00ccd0f0
// src: GUESS 0x00ccd0f0 (confidence: low)
void* Runtime_GetTarget00ccd0f0Address() { return &g_target_00ccd0f0; }

namespace fnv_00ccd1d0 {
extern int DAT_01267e30;

struct ccd1_inner_t {
    float __thiscall FUN_00d571a0();
};

struct ccd1_stage_t {
    void __thiscall bhkConvexShape_CopyCinfo(void* out);
};

struct FUN_00ccd1d0_cls {
    void* unk00;
    void* unk04;
    ccd1_inner_t* m_pInner;
    void WriteLimitedHingeData(void* out);
};

// @fnv 0x00ccd1d0
void FUN_00ccd1d0_cls::WriteLimitedHingeData(void* out) {
    ((ccd1_stage_t*)this)->bhkConvexShape_CopyCinfo(out);
    char* o = (char*)out;
    char* a;
    if (this != 0 && m_pInner != 0) {
        a = (char*)m_pInner + 0x20;
    } else {
        a = (char*)&DAT_01267e30;
    }
    ((bhkLimitedHingeVector_blk_00cc0000_o2*)(o + 0x10))->SetQuaternionComponentsFromVector((const float*)a);

    char* b;
    if (this != 0 && m_pInner != 0) {
        b = (char*)m_pInner + 0x30;
    } else {
        b = (char*)&DAT_01267e30;
    }
    ((bhkLimitedHingeVector_blk_00cc0000_o2*)(o + 0x20))->SetQuaternionComponentsFromVector((const float*)b);

    volatile float r;
    if (this != 0 && m_pInner != 0) {
        r = m_pInner->FUN_00d571a0();
    } else {
        r = 0.0f;
    }
    *(float*)(o + 0x30) = r;
}
}  // namespace fnv_00ccd1d0

extern void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00ccd100 {
    void* vtable;
    unsigned int refCount;
    unsigned int flags;
    unsigned int dataA;
    unsigned int dataB;
    FUN_00ccd100();
    static void* __cdecl operator new(unsigned int bytes) {
        return Object_DispatchCommandFour(bytes);
    }
};
// Allocates and constructs a new FUN_00ccd100 object, returning its pointer.
// @fnv 0x00ccd250
// src: EXE 0x00ccd250
FUN_00ccd100* __cdecl bhkCylinderShape_CreateObject() {
    return new FUN_00ccd100;
}

extern "C" void _ReadWriteBarrier(void);

struct S_00ccd330_Arg {
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char unk1E4;
    unsigned char m1E5;
};

struct S_00ccd330_Data {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
};

struct S_00ccd330_Foo {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void v05() {}
    virtual void v06() {}
    virtual void v07() {}
    virtual void v08() {}
    virtual void v09() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual void v13() {}
    virtual void v14() {}
    virtual void v15() {}
    virtual void v16() {}
    virtual void v17() {}
    virtual void v18() {}
    virtual void v19() {}
    virtual void v20() {}
    virtual void v21() {}
    virtual void v22() {}
    virtual void v23() {}
    virtual void v24() {}
    virtual void v25() {}
    virtual void v26() {}
    virtual void v27() {}
    virtual void v28() {}
    virtual void v29() {}
    virtual void v30() {}
    virtual void v31() {}
    virtual void v32() {}
    virtual void v33() {}
    virtual void v34() {}
    virtual void v35() {}
    virtual void v36() {}
    virtual void v37() {}
    virtual void v38() {}
    virtual void v39() {}
    virtual void v40() {}
    virtual void v41() {}
    virtual void v42() {}
    virtual void v43() {}
    virtual void v44() {}
    virtual S_00ccd330_Data* FUN_v45(void** value);
    S_00ccd330_Data* m_pData;
    void __thiscall bhkConvexShape_LoadBinary(S_00ccd330_Arg* a1);
    void bhkCapsuleShape_LoadBinary(S_00ccd330_Arg* a1);
};

// Calls FUN_00c9fbc0 on a1, returns early if m1E5 is 1, otherwise byte-swaps the 32-bit fields unk10 through unk2C of the data returned by FUN_v45.
// @fnv 0x00ccd330
// src: XBOX_PDB 0x00ccd330
void __thiscall S_00ccd330_Foo::bhkCapsuleShape_LoadBinary(S_00ccd330_Arg* apArg)
{
    S_00ccd330_Arg* volatile* pa = &apArg;
    S_00ccd330_Arg* a = *pa;
    bhkConvexShape_LoadBinary(a);
    if (a->m1E5 == 1)
        return;
    S_00ccd330_Data* d = FUN_v45((void**)&apArg);
    d->unk10 = _byteswap_ulong(d->unk10);
    _ReadWriteBarrier();
    d->unk14 = _byteswap_ulong(d->unk14);
    _ReadWriteBarrier();
    d->unk18 = _byteswap_ulong(d->unk18);
    _ReadWriteBarrier();
    d->unk1C = _byteswap_ulong(d->unk1C);
    _ReadWriteBarrier();
    d->unk20 = _byteswap_ulong(d->unk20);
    _ReadWriteBarrier();
    d->unk24 = _byteswap_ulong(d->unk24);
    _ReadWriteBarrier();
    d->unk28 = _byteswap_ulong(d->unk28);
    _ReadWriteBarrier();
    d->unk2C = _byteswap_ulong(d->unk2C);
    _ReadWriteBarrier();
}

struct FUN_00ccd3a0_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char m_1e4;
};

struct FUN_00ccd3a0_cls
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual volatile unsigned int* vGet(unsigned char* out);
    void bhkConvexShape_SaveBinary(FUN_00ccd3a0_arg* a);
    void bhkCapsuleShape_SaveBinary(FUN_00ccd3a0_arg* a1);
};

// If the argument's m_1e4 is not 1, byte-swaps p[4] through p[11] before and after calling FUN_00c9fc00.
// @fnv 0x00ccd3a0
// src: XBOX_PDB 0x00ccd3a0
void FUN_00ccd3a0_cls::bhkCapsuleShape_SaveBinary(FUN_00ccd3a0_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
    }
    bhkConvexShape_SaveBinary(a1);
    if (a1->m_1e4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
        p[8] = _byteswap_ulong(p[8]);
        p[9] = _byteswap_ulong(p[9]);
        p[10] = _byteswap_ulong(p[10]);
        p[11] = _byteswap_ulong(p[11]);
    }
}

namespace fnv_00ccd520 {
extern "C" __declspec(thread) int g_currentMemoryContext;
extern "C" float DAT_010c72bc;

void MemoryHeapAllocateEntry();
extern MemoryHeap DAT_011f6238;

struct TransformRecord {
    unsigned int m_flags;
    float m_scalar;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    float m_translationX;
    float m_translationY;
    float m_translationZ;
    float m_translationW;
    volatile float m_rotationW;
    volatile float m_rotationX;
    volatile float m_rotationY;
    volatile float m_rotationZ;
    float m_other;
};

struct MemoryContextScope {
    int previousContext;
    MemoryContextScope() {
        previousContext = g_currentMemoryContext;
        g_currentMemoryContext = 0x10;
    }
    ~MemoryContextScope() {
        g_currentMemoryContext = previousContext;
    }
};

struct TransformHolder {
    void* m_ppVirtualMethodTable;
    unsigned int m_iObjectReferenceCount;
    int m_enableCallback;
    TransformRecord* m_record;
    void __thiscall WriteLimitedHingeData(TransformRecord* transform);
    TransformRecord* __thiscall GetOrCreateTransform(bool* created);
};

// Returns m_record, allocating and initialising a TransformRecord when it is null and invoking the callback if enabled.
// @fnv 0x00ccd520
TransformRecord* TransformHolder::GetOrCreateTransform(bool* created) {
    MemoryContextScope m_uiMemoryContext;
    bool isNew = m_record == 0;
    *created = isNew;
    if (isNew) {
        char* allocation = (char*)reinterpret_cast<void* (__thiscall*)(MemoryHeap*, unsigned int)>(&MemoryHeapAllocateEntry)(&DAT_011f6238, 0x50); unsigned char delta=(unsigned char)(16 - (unsigned char)((unsigned int)allocation & 0xf)); allocation[delta - 1] = delta; allocation += delta; TransformRecord* record=(TransformRecord*)allocation;
        record->m_flags = 0;
        record->m_scalar = DAT_010c72bc;
        record->m_translationX = 0.0f;
        record->m_translationY = 0.0f;
        record->m_translationZ = 0.0f;
        record->m_translationW = 0.0f;
        record->m_rotationW = 0.0f;
        record->m_rotationX = 0.0f;
        record->m_rotationY = 0.0f;
        record->m_rotationZ = 0.0f;
        record->m_other = 0.0f;
        record->m_rotationW = 1.0f;
        record->m_rotationX = 0.0f;
        record->m_rotationY = 0.0f;
        record->m_rotationZ = 0.0f;
        m_record = record;
        if (m_enableCallback) {
            WriteLimitedHingeData(record);
        }
    }
    return m_record;
}
}  // namespace fnv_00ccd520

namespace fnv_00ccd610 {
struct S_00ccd610_Tls {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00ccd610_Tls DAT_tls;

struct S_00ccd610_Ctx {
    int saved;
    __forceinline S_00ccd610_Ctx(int c) { saved = DAT_tls.ctx; DAT_tls.ctx = c; }
    __forceinline ~S_00ccd610_Ctx() { DAT_tls.ctx = saved; }
};

struct S_00ccd610_Alloc {
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int n);
};
struct S_00ccd610_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00ccd610_Alloc* unk10;
    S_00ccd610_Alloc& heap() { return *unk10; }
};
S_00ccd610_Router* hkMemoryRouter_getInstance() throw();
extern float DAT_011b153c;


struct S_00ccd610_Obj : hkReferencedObject {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    S_00ccd610_Obj(int a, int b, float c, float d);
};

struct S_00ccd610_Cls {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(hkReferencedObject* o);
    void CreateAndDispatchObject(int a, int b, float c);
};

// Allocates an S_00ccd610_Obj with the given arguments and DAT_011b153c, passes it to vfn_8c, then calls its FUN_00c905b0.
// @fnv 0x00ccd610
void S_00ccd610_Cls::CreateAndDispatchObject(int aiArg1, int aiArg2, float afValue)
{
    S_00ccd610_Ctx ctx(0x10);
    S_00ccd610_Obj* o = new S_00ccd610_Obj(aiArg1, aiArg2, afValue, DAT_011b153c);
    this->vfn_8c(o);
    o->removeReference();
}
}  // namespace fnv_00ccd610

extern int g_012686a0;

// @fnv 0x00ccdc30
// src: COMMUNITY 0x00ccdc30
int* __cdecl bhkConvexVerticesShape_GetRTTI()
{
    return &g_012686a0;
}

// Constructor of a four-level Havok wrapper class: each level bumps its own live-instance counter.

extern int g_iCDC40LevelACount;
extern int g_iCDC40LevelBCount;
extern int g_iCDC40LevelCCount;
extern int g_iCDC40LevelDCount;

class CDC40Root {
public:
    CDC40Root();
    virtual ~CDC40Root();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
};

class CDC40Holder : public CDC40Root {
public:
    CDC40Holder() : m_pkHavokObject(0), m_uiData(0) {}
    virtual ~CDC40Holder();
    void* m_pkHavokObject;
    unsigned int m_uiData;
};

class CDC40LevelA : public CDC40Holder {
public:
    CDC40LevelA() { ++g_iCDC40LevelACount; }
    virtual ~CDC40LevelA();
};

class CDC40LevelB : public CDC40LevelA {
public:
    CDC40LevelB() { ++g_iCDC40LevelBCount; }
    virtual ~CDC40LevelB();
};

class CDC40LevelC : public CDC40LevelB {
public:
    CDC40LevelC() { ++g_iCDC40LevelCCount; }
    virtual ~CDC40LevelC();
};

class FUN_00ccdc40 : public CDC40LevelC {
public:
    FUN_00ccdc40();
    virtual ~FUN_00ccdc40();
};

// Constructs a CDC40LevelD object and increments the global CDC40 level D instance counter.
// @fnv 0x00ccdc40
FUN_00ccdc40::FUN_00ccdc40()
{
    ++g_iCDC40LevelDCount;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct RefObject20_b9084 {
    char m00[0x14];
    RefObject20_b9084();
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
};

// Allocates and constructs a RefObject20_b9084 via its operator new and returns the new object.
// @fnv 0x00ccdd00
RefObject20_b9084* CreateRefObject20() {
    return new RefObject20_b9084();
}

struct FUN_00ccdd70_arg {
    unsigned int m_u00;
    unsigned int m_u04;
    unsigned int m_u08;
    unsigned int m_u0C;
    float m_f10;
};

class CdResultObj {
public:
    virtual void v00();
    void hkConvexVerticesShapeCinfo_Scale(float value);
};

class FUN_00ccdd70_cls {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual CdResultObj* GetResult(unsigned char* flag);
    void bhkShape_CopyMembers(int a1, FUN_00ccdd70_arg* a2);
    void ApplyResultValue(int a1, FUN_00ccdd70_arg* a2);
};

// Gets a result object, applies a2->m_f10 to it when it is not 1.0, then forwards a1 and a2 to FUN_00c84df0.
// @fnv 0x00ccdd70
void FUN_00ccdd70_cls::ApplyResultValue(int a1, FUN_00ccdd70_arg* a2)
{
    unsigned char flag;
    CdResultObj* result = this->GetResult(&flag);
    float value = a2->m_f10;
    if (value != 1.0f) {
        result->hkConvexVerticesShapeCinfo_Scale(value);
    }
    this->bhkShape_CopyMembers(a1, a2);
}

struct CCDDE0Vector3 {
    float x;
    float y;
    float z;
};

struct CCDDE0Data {
    int unk00;
    float m_fScale;
    CCDDE0Vector3 m_kMin;
    CCDDE0Vector3 m_kMax;
};

struct CCDDE0Shape;

extern float DAT_010c72bc;

void CCDDE0SwapVector(CCDDE0Data* pkData, CCDDE0Shape* pkShape, CCDDE0Vector3* pkVector);
void CCDDE0ConvertVector(NiStream* pkStream, CCDDE0Vector3* pkVector);

class CCDDE0Base {
public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual CCDDE0Shape* GetShape();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual CCDDE0Data* GetData(unsigned int* puiSize);

    void Load(NiStream* pkStream);
};

class CCDDE0Object : public CCDDE0Base {
public:
    void bhkConvexVerticesShape_LoadBinary(NiStream* pkStream);
};

// Loads the base data, sets m_fScale, swaps min/max vectors when the platform is not 1, then converts both vectors from the stream.
// @fnv 0x00ccdde0
// src: XBOX_PDB 0x00ccdde0
void CCDDE0Object::bhkConvexVerticesShape_LoadBinary(NiStream* pkStream)
{
    CCDDE0Base::Load(pkStream);
    unsigned int uiSize;
    CCDDE0Data* pkData = GetData(&uiSize);
    pkData->m_fScale = DAT_010c72bc;
    if (StreamField<unsigned char>(*pkStream, 0x1e5) != 1) {
        CCDDE0Shape* pkShape = GetShape();
        CCDDE0SwapVector(pkData, pkShape, &pkData->m_kMin);
        CCDDE0SwapVector(pkData, pkShape, &pkData->m_kMax);
    }
    CCDDE0ConvertVector(pkStream, &pkData->m_kMin);
    CCDDE0ConvertVector(pkStream, &pkData->m_kMax);
}

class hkMemoryRouter;
namespace fnv_00cce0d0 {

 // Opaque tag preserves the existing external function signature.

hkMemoryRouter* hkMemoryRouter_getInstance();

struct FUN_00cce0d0_cls {
    void* m_pData;
    int m_04;
    unsigned int m_08;

    void ClearAndFree();
};

// @fnv 0x00cce0d0
void FUN_00cce0d0_cls::ClearAndFree()
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    ::hkMemoryAllocator* alloc = reinterpret_cast<::hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(holder)->m_heap);
    unsigned int flags = m_08;
    m_04 = 0;
    if ((flags & 0x80000000u) == 0) {
        FreeAudioArray(alloc, m_pData, (flags & 0x3fffffffu) * 16u);
    }
    m_pData = 0;
    m_08 = 0x80000000u;
}
}  // namespace fnv_00cce0d0

extern __declspec(thread) int g_iCCE110AllocTag;

extern const char* g_pcCCE110Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class FUN_00cce110_cls {
public:
    void bhkConvexShape_GetViewerStrings(StrArr* pkArray);
    void AppendNameToArray(StrArr* pkArray);
};

// Sets an allocation tag, calls FUN_00c9fc50 on the array, then appends the string returned by FUN_00a7d330(g_pcCCE110Name).
// @fnv 0x00cce110
void FUN_00cce110_cls::AppendNameToArray(StrArr* pkArray)
{
    AutoMemContext kScope(0x10);
    bhkConvexShape_GetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCCE110Name);
    AppendStringReference(pkArray, pcName);
}

class hkMemoryRouter;
namespace fnv_00cce290 {

 // Opaque tag preserves the existing external function signature.

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct AudioScopeGuard {
    void* m_pSharedOwner;
    AudioScopeGuard(void* owner) { m_pSharedOwner = owner; }
    ~AudioScopeGuard() { m_pSharedOwner = 0; }
};

struct FUN_00cce290_cls {
    int unk00;
    int unk04;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void UpdateState_00cce290();
};

// Frees both allocated arrays through the audio allocator and resets their pointers, counts and capacity bits.
// @fnv 0x00cce290
// src: GUESS 0x00cce290 (confidence: low)
void FUN_00cce290_cls::UpdateState_00cce290()
{
    {
        AudioScopeGuard guard(this);
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder)->m_heap);
        unsigned int uCapBits1 = m_uCapBits1;
        m_iCount1 = 0;
        if ((uCapBits1 & 0x80000000u) == 0) {
            void* pData1 = m_pData1;
            FreeAudioArray(pAllocator, pData1, (uCapBits1 & 0x3fffffffu) * 16);
        }
        m_pData1 = 0;
        m_uCapBits1 = 0x80000000u;
    }

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder2)->m_heap);
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0) {
        FreeAudioArray(pAllocator2, m_pData2, (uCapBits2 & 0x3fffffffu) * 16);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
}
}  // namespace fnv_00cce290

extern int DAT_012686b0;

// @fnv 0x00cce970
// src: COMMUNITY 0x00cce970
int* __cdecl bhkConvexTransformShape_GetRTTI()
{
    return &DAT_012686b0;
}

// @fnv 0x00cce980
// src: COMMUNITY 0x00cce980
int __cdecl bhkConvexTransformShape_GetCInfoSize()
{
    return 0x50;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00cce9e0_cls {
    int unk00;

    void BaseCleanup();

    FUN_00cce9e0_cls* FUN_00cce9e0(unsigned char acFlags);
};

// @fnv 0x00cce9e0
FUN_00cce9e0_cls* FUN_00cce9e0_cls::FUN_00cce9e0(unsigned char acFlags)
{
    BaseCleanup();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0x14);
    }
    return this;
}

struct BCCECC0Data {
    int unk00;
    int unk04;
    void* m_pvUserData;
};

struct BCCECC0Extra {
    int unk00;
    int unk04;
    void* m_pvUserData;
};

class BCCECC0Node {
public:
    BCCECC0Extra* FUN_00a63430();
};

class BCCECC0Wrapper {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual BCCECC0Data* GetData(bool* pbCreated);

    void bhkShape_LinkObject(BCCECC0Node* pkNode);
    void SetUserDataFromNode(BCCECC0Node* pkNode);
};

// Copies the node's extra user data pointer into the wrapper's data, then calls FUN_00c84cc0 with the node.
// @fnv 0x00ccecc0
void BCCECC0Wrapper::SetUserDataFromNode(BCCECC0Node* pkNode)
{
    bool bCreated;
    BCCECC0Data* pkData = GetData(&bCreated);
    BCCECC0Extra* pkExtra = pkNode->FUN_00a63430();
    pkData->m_pvUserData = pkExtra ? pkExtra->m_pvUserData : 0;
    bhkShape_LinkObject(pkNode);
}

struct FUN_00cced20_C {
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54(int a);
};

struct FUN_00cced20_B {
    int unk00;
    int unk04;
    FUN_00cced20_C* m_08;
};

struct FUN_00cced20_A {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00cced20_B* m_18;
};

struct FUN_00cced20_cls {
    int unk00;
    int unk04;
    FUN_00cced20_A* m_08;

    void BSPackedAdditionalGeometryData_RegisterStreamables(int a);
    void ForwardToNestedVtable(int a1);
};

// Walks this->m_08->m_18->m_08 and, if non-null, calls its v54 with a1, then calls FUN_00aa0ad0(a1).
// @fnv 0x00cced20
void FUN_00cced20_cls::ForwardToNestedVtable(int aiValue)
{
    if (this != 0) {
        FUN_00cced20_A* pRoot = m_08;
        if (pRoot != 0) {
            FUN_00cced20_B* pMid = pRoot->m_18;
            if (pMid != 0) {
                FUN_00cced20_C* pLeaf = pMid->m_08;
                if (pLeaf != 0) {
                    pLeaf->v54(aiValue);
                }
            }
        }
    }
    BSPackedAdditionalGeometryData_RegisterStreamables(aiValue);
}

namespace fnv_00ccef50 {
extern __declspec(thread) int g_iMemContext;

struct AutoMemCtx {
    int m_iOld;
    AutoMemCtx(int ctx) { m_iOld = g_iMemContext; g_iMemContext = ctx; }
    ~AutoMemCtx() { g_iMemContext = m_iOld; }
};

struct hkMemAllocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int size);
};

struct hkThreadMem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemAllocator* m_pAllocator;
};

hkThreadMem* hkMemoryRouter_getInstance();

struct IntegerBlock18 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct hkObj {
    void* m_pVtable;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;

    static void* operator new(unsigned int size) {
        hkThreadMem* t = hkMemoryRouter_getInstance();
        hkObj* p = (hkObj*)t->m_pAllocator->AllocateMemoryBlock(size);
        p->m_usMemSizeAndFlags = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
    hkObj(int a, IntegerBlock18* b, int c);
    void removeReference();
};

struct Inner2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned int unk10;
};

struct Inner1 {
    int unk00;
    int unk04;
    Inner2* unk08;
};

struct Inner0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Inner1* unk18;
};

struct Param {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    IntegerBlock18 info;
};

struct Holder {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void SetObject(hkObj* obj);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void SetParam(Param* p);

    int unk04;
    Inner0* unk08;
    int unk0C;
    unsigned int unk10;

    void SetObjectAndParam(Param* p);
};

// Allocates an hkObj from the param, passes it to SetObject, releases it, calls SetParam, then stores a masked value from the nested inner structures into unk10.
// @fnv 0x00ccef50
void Holder::SetObjectAndParam(Param* p)
{
    AutoMemCtx ctx(16);
    hkObj* obj = new hkObj(p->unk08, &p->info, 1);
    SetObject(obj);
    obj->removeReference();
    SetParam(p);
    if (unk08) {
        if (Inner1* a = unk08->unk18) {
            if (Inner2* b = a->unk08) {
                unk10 = b->unk10 & 0x1f;
                return;
            }
            return;
        }
        return;
    }
}
}  // namespace fnv_00ccef50

extern __declspec(thread) int gThreadAllocState;
struct ManagedReference {
    virtual void unused();
    virtual void destroy();
    volatile long references;
};
struct ResourceRecord {
    void* unk00;
    void* unk04;
    ManagedReference* resource;
};
struct OwnerRecord {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    ResourceRecord* active;
};
struct ScopedThreadSetting {
    int prior;
    ScopedThreadSetting() : prior(gThreadAllocState) {
        gThreadAllocState = 16;
    }
    ~ScopedThreadSetting() { gThreadAllocState = prior; }
};
// Sets the thread alloc state to 16, then decrements the active resource's reference count and destroys it when it reaches zero.
// @fnv 0x00ccf060
void __thiscall FUN_00ccf060_stub::ReleaseActiveResource() {
    ScopedThreadSetting scope;
    if (this != 0) {
        OwnerRecord* owner = *(OwnerRecord**)((char*)this + 8);
        if (owner != 0 && owner->active != 0) {
            ManagedReference* p = owner->active->resource;
            if (p != 0 && InterlockedDecrement(&p->references) == 0)
                p->destroy();
        }
    }
}


struct Output403 {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
 virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
 virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
 virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
 virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
 virtual void Output(StrArr*);
};
struct Link403 { int unk00,unk04; Output403* target; };
// 0x00ccf350 reads the child link at 0x18 and a physics transform at 0x20; include/Data.h has neither.
struct PhysicsTransformShapeView { int unk00,unk04,unk08,unk0c,unk10,unk14; Link403* link; int unk1c; Transform transform; };
extern Transform DAT_01268370;
extern const char* g_012686b0;
extern const char g_010c6050[],g_010c604c[];
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
void __cdecl HK2NI_00624b10(NiTransform*,const Transform*);
void __cdecl FUN_00458620(NiPoint3*,const hkVector4*);

struct Holder403 {
 int unk00,unk04;
 PhysicsTransformShapeView* data;
 void bhkConvexShape_GetViewerStrings(StrArr*);
 const Transform& GetTransform() const {
  if(this && data) return data->transform;
  return DAT_01268370;
 }
 void AppendTransformStrings(StrArr*);
};
// @fnv 0x00ccf350
void Holder403::AppendTransformStrings(StrArr* strings) {
 AutoMemContext context(16);
 bhkConvexShape_GetViewerStrings(strings);
 strings->AppendInline(NiViewerStrings_NiGetViewerString_Title(g_012686b0));
 const Transform& transform=GetTransform();
 // The conversion routine initializes the transform without a constructor call.
 void* convertedStorage[(sizeof(NiTransform) + sizeof(void*) - 1) / sizeof(void*)];
 NiTransform& converted = *reinterpret_cast<NiTransform*>(convertedStorage);
 HK2NI_00624b10(&converted,&transform);
 FUN_00458620(&converted.m_Translate,reinterpret_cast<const hkVector4*>(&transform.r[3]));
 strings->AppendInline(converted.m_Translate.FormatToBuffer(g_010c6050));
 strings->AppendInline(converted.m_Rotate.GetViewerString(g_010c604c));
 if(this) {
  PhysicsTransformShapeView* object=data;
  if(object) {
   Link403* link=object->link;
   if(link) {
    Output403* output=link->target;
    if(output) output->Output(strings);
   }
  }
 }
}

extern int DAT_012686b8;

// @fnv 0x00ccf550
// src: COMMUNITY 0x00ccf550
void* __cdecl bhkConvexSweepShape_GetRTTI()
{
    return &DAT_012686b8;
}

// @fnv 0x00ccf560
// src: XBOX_PDB 0x00ccf560
void __thiscall bhkConvexSweepShape::Init_00ccf560(int arg) {
    vf47(arg);
}

namespace fnv_00ccf5d0 {
extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);
extern "C" char DAT_01030b0c[];
extern "C" char DAT_01030a24[];
extern "C" int DAT_01268274;
extern "C" int DAT_01268250;
}

inline bhkSphereRepShape::bhkSphereRepShape()
{
    *reinterpret_cast<void**>(this) = fnv_00ccf5d0::DAT_01030b0c;
    ++fnv_00ccf5d0::DAT_01268274;
}
inline bhkConvexShape::bhkConvexShape()
{
    *reinterpret_cast<void**>(this) = fnv_00ccf5d0::DAT_01030a24;
    ++fnv_00ccf5d0::DAT_01268250;
}

// This factory's original allocator returns null instead of throwing.
enum SweepAllocationTag { SweepAllocation };
inline void* __cdecl operator new(unsigned int size, SweepAllocationTag) throw()
{
    return fnv_00ccf5d0::Object_DispatchCommandFour(size);
}

inline void __cdecl operator delete(void* memory, SweepAllocationTag)
{
    ::operator delete(memory, sizeof(bhkConvexSweepShape));
}

// @fnv 0x00ccf5d0
NiObject* __cdecl bhkConvexSweepShape::CreateObject()
{
    return ::new (SweepAllocation) bhkConvexSweepShape;
}


extern int DAT_012686c4;

// @fnv 0x00ccf7b0
// src: COMMUNITY 0x00ccf7b0
void* __cdecl bhkConvexListShape_GetRTTI()
{
    return &DAT_012686c4;
}

// FUN_00ccf810: thiscall, 21 bytes, 2 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x38] / jmp eax / end: ret 8
// Forwards the two stack arguments to virtual slot 0x38 of the object
// pointed to by the member at this+8.
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void Tail(int a, int b);
};

struct FUN_00ccf810_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void bhkConvexListShape_GetSupportingVertex(int a, int b);
};

// @fnv 0x00ccf810
// src: XBOX_PDB 0x00ccf810
void FUN_00ccf810_cls::bhkConvexListShape_GetSupportingVertex(int a, int b)
{
    if (this) {
        Target* p = m_08;
        if (p) {
            p->Tail(a, b);
        }
    }
}

namespace fnv_00ccf830 {
// DispatchTail: thiscall, 21 bytes, 3 stack args.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x3c] / jmp eax / end: ret 0xc
// Forwards the three stack arguments to virtual slot 0x3c of the object
// pointed to by the member at this+8.
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void Tail(int a, int b, int c);
};

struct FUN_00ccf830_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void DispatchTail(int a, int b, int c);
};

// @fnv 0x00ccf830
void FUN_00ccf830_cls::DispatchTail(int a, int b, int c)
{
    if (this) {
        Target* p = m_08;
        if (p) {
            p->Tail(a, b, c);
        }
    }
}
}  // namespace fnv_00ccf830

namespace fnv_00ccf850 {
// FUN_00ccf850: thiscall, 21 bytes, 1 stack arg.
// test ecx,ecx / je end / mov ecx,[ecx+8] / test ecx,ecx / je end
// mov eax,[ecx] / mov eax,[eax+0x34] / jmp eax / end: ret 4
// Forwards the stack argument to virtual slot 0x34 of the object pointed to
// by the member pointer at this+8.
struct Target
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void Tail(int a);
};

struct FUN_00ccf850_cls
{
    int unk00;
    int unk04;
    Target* volatile m_08;
    void bhkConvexListShape_GetFirstVertex(int a);
};

// @fnv 0x00ccf850
// src: XBOX_PDB 0x00ccf850
void FUN_00ccf850_cls::bhkConvexListShape_GetFirstVertex(int a)
{
    if (this) {
        Target* p = m_08;
        if (p) {
            p->Tail(a);
        }
    }
}
}  // namespace fnv_00ccf850

struct Link {
    void* m_type;
    unsigned int m_flags;
    void* m_object;
};
struct RefObject {
    void** m_ppVirtualMethodTable;
    unsigned int m_flags;
    Link* m_link;
};
struct LinkCollection {
    unsigned int m_type;
    unsigned int m_flags;
    unsigned int m_pRayCursor;
    unsigned int m_generation;
    Link** m_ppLinks;
    int m_uiItemCount;
};
struct Owner {
    void** m_ppVirtualMethodTable;
    void __thiscall bhkShape_CopyMembers(void* item, void* key);
    void __thiscall bhkConvexListShape_CopyMembers(void* item, void* key);
};
typedef LinkCollection* (__thiscall *AcquireLinks)(Owner*, unsigned char*);
typedef bool (__thiscall *CheckRef)(RefObject*, void*);
typedef RefObject* (__thiscall *FindRef)(RefObject*, void*);
// @fnv 0x00ccf900
// src: XBOX_PDB 0x00ccf900
void Owner::bhkConvexListShape_CopyMembers(void* item, void* key)
{
    unsigned char unusedFlag;
    LinkCollection* list = ((AcquireLinks)m_ppVirtualMethodTable[0xb4 / 4])(this, &unusedFlag);
    for (int index = 0; index < list->m_uiItemCount; ++index) {
        Link* link = list->m_ppLinks[index];
        if (link) {
            RefObject* ref = (RefObject*)link->m_object;
            if (ref && !((CheckRef)ref->m_ppVirtualMethodTable[0xd0 / 4])(ref, key)) {
                RefObject* replacement = ((FindRef)ref->m_ppVirtualMethodTable[0x48 / 4])(ref, key);
                list->m_ppLinks[index] = replacement ? replacement->m_link : 0;
            }
        }
    }
    bhkShape_CopyMembers(item, key);
}

struct FNVCountInterface {
    virtual void Reserved();
    virtual unsigned int GetCount();
};

struct FNVNotificationReceiver {
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void Reserved14();
    virtual void Reserved15();
    virtual void Reserved16();
    virtual void Reserved17();
    virtual void Reserved18();
    virtual void Reserved19();
    virtual void Reserved20();
    virtual void Notify(int context);
};

struct FNVNotificationEntry {
    void* m_unknown00;
    void* m_unknown04;
    FNVNotificationReceiver* m_receiver;
};

struct FNVNotificationCollection {
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    unsigned int m_unknown08;
    unsigned int m_unknown0c;
    unsigned int m_unknown10;
    FNVCountInterface m_countInterface;
    unsigned int m_unknown18;
    unsigned int m_unknown1c;
    unsigned int m_unknown20;
    unsigned int m_unknown24;
    unsigned int m_unknown28;
    unsigned int m_unknown2c;
    unsigned int m_unknown30;
    unsigned int m_unknown34;
    unsigned int m_unknown38;
    unsigned int m_unknown3c;
    unsigned int m_unknown40;
    FNVNotificationEntry** m_entries;
};

struct FNVNotificationOwner {
    unsigned int m_unknown00;
    unsigned int m_unknown04;
    FNVNotificationCollection* m_pShapeCollection;
    void NotifyAllReceivers(int context);
    void BSPackedAdditionalGeometryData_RegisterStreamables(int context);
};

// Calls Notify(context) on each non-null receiver in the collection's entries, then calls FUN_00aa0ad0(context).
// @fnv 0x00ccf990
void FNVNotificationOwner::NotifyAllReceivers(int context)
{
    unsigned int count;
    FNVNotificationCollection* collection;
    if (this && (collection = m_pShapeCollection))
        count = collection->m_countInterface.GetCount();
    else
        count = 0;
    for (unsigned int index = 0; index < count; ++index) {
        if (this && m_pShapeCollection) {
            FNVNotificationEntry* entry = m_pShapeCollection->m_entries[index];
            if (entry) {
                FNVNotificationReceiver* receiver = entry->m_receiver;
                if (receiver)
                    receiver->Notify(context);
            }
        }
    }
    BSPackedAdditionalGeometryData_RegisterStreamables(context);
}

class CCFA00RefObject {
public:
    virtual ~CCFA00RefObject();

    unsigned int m_uiRefCount;

    void IncRefCount() { InterlockedIncrement((volatile long*)&m_uiRefCount); }
};

struct CCFA00Entry {
    int unk00;
    int unk04;
    CCFA00RefObject* m_pPointer;
};

class CCFA00List {
public:
    virtual void vfunc00();
    virtual int GetSize();
};

struct CCFA00Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    CCFA00List m_kList;
    int unk18; int unk1C; int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34;
    int unk38; int unk3C; int unk40;
    CCFA00Entry** m_ppkEntries;
};

class CCFA00Holder {
public:
    int unk00;
    int unk04;
    CCFA00Data* m_pUserData;

    void IncRefCountAllEntries();
};

// If the holder's data is valid, iterates its entries and increments the reference count of each entry's referenced object.
// @fnv 0x00ccfa00
void CCFA00Holder::IncRefCountAllEntries()
{
    CCFA00Data* pkData;
    if (this && (pkData = m_pUserData) != 0) {
        int i = pkData->m_kList.GetSize();
        while (i) {
            i--;
            if (m_pUserData) {
                CCFA00Entry* pkEntry = m_pUserData->m_ppkEntries[i];
                if (pkEntry && pkEntry->m_pPointer)
                    pkEntry->m_pPointer->IncRefCount();
            }
        }
    }
}

struct ObjC;

struct SubObj14 {
    virtual void vfn0();
    virtual int vfn1();
};

struct ObjA {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    SubObj14 m_14;
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
    unsigned int unk40;
    ObjC** m_44;
};

struct ObjD {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(int p1, int p2);
};

struct ObjC {
    unsigned int unk00;
    unsigned int unk04;
    ObjD* m_08;
};

class FUN_00ccfad0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    ObjA* m_08;
    void bhkConvexListShape_BuildDisplayGeometry(int a1, int a2);
};

// Calls v53(a1, a2) on the m_08 object of each element in m_44, iterating up to the count returned by m_14.vfn1().
// @fnv 0x00ccfad0
// src: XBOX_PDB 0x00ccfad0
void FUN_00ccfad0_cls::bhkConvexListShape_BuildDisplayGeometry(int a1, int a2) {
    int count;
    ObjA* a0 = (this != 0) ? this->m_08 : 0;
    if (a0 != 0) {
        count = a0->m_14.vfn1();
    } else {
        count = 0;
    }
    int i = 0;
    if (count > 0) {
        do {
            if (this != 0) {
                ObjA* a = this->m_08;
                if (a != 0) {
                    ObjC* c = a->m_44[i];
                    if (c != 0) {
                        ObjD* d = c->m_08;
                        if (d != 0) {
                            d->v53(a1, a2);
                        }
                    }
                }
            }
            ++i;
        } while (i < count);
    }
}

struct ItemFlags {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int flags;
};
struct ItemEntry {
    unsigned int unk00;
    unsigned int unk04;
    ItemFlags* details;
};
struct CountProvider {
    virtual void unused();
    virtual unsigned int LastIndex();
};
struct ItemContainer {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    CountProvider counter;
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
    unsigned int unk40;
    ItemEntry** entries;
};
struct ItemCollection {
    unsigned int unk00;
    unsigned int unk04;
    ItemContainer* container;
    unsigned int unk0c;
    unsigned int defaultFlags;
    unsigned int __thiscall GetItemFlags(unsigned int index);
};
// @fnv 0x00ccfb40
unsigned int ItemCollection::GetItemFlags(unsigned int index) {
    if (index != 0xffffffffu) {
        unsigned int lastIndex;
        if (this != 0) {
            ItemContainer* pContainer = container;
            if (pContainer != 0)
                lastIndex = pContainer->counter.LastIndex();
            else
                lastIndex = 0;
        } else
            lastIndex = 0;
        if (index <= lastIndex && this != 0 && container != 0) {
            ItemEntry* entry = container->entries[index];
            if (entry != 0 && entry->details != 0)
                return entry->details->flags & 0x1f;
        }
    }
    return defaultFlags & 0x1f;
}

namespace fnv_00ccfba0 {
struct TlsBlock_b9412 {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) TlsBlock_b9412 g_tls;

void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();

struct SpawnedObj_b9412 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SpawnedObj_b9412();
    static void* operator new(unsigned int size) throw() { return Object_DispatchCommandFour(size); }
};

struct Holder_b9412 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void vSlot49(SpawnedObj_b9412* o, int p);
    SpawnedObj_b9412* CreateSpawnedObj(int p);
};

// @fnv 0x00ccfba0
SpawnedObj_b9412* Holder_b9412::CreateSpawnedObj(int p) {
    AutoMemContext guard;
    bhkSerializable_CloneCritLock();
    SpawnedObj_b9412* o = new SpawnedObj_b9412();
    vSlot49(o, p);
    bhkSerializable_CloneCritUnlock();
    return o;
}
}  // namespace fnv_00ccfba0

namespace fnv_00ccfc60 {






// The shared convex-list class omits its concrete virtual overrides; invoke its constructor with its thiscall ABI.
void ConstructConvexListShape();

struct HavokConstructionAllocation {
    void* memory;
    explicit HavokConstructionAllocation(void* p) : memory(p) {}
    ~HavokConstructionAllocation() { if (memory) hkReferencedObject::operator delete(memory); }
};

struct ShapeInfoCCF {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iA;
    int m_iB;
};



// Allocates an hkpConvexListShape from pkInfo's m_iA and m_iB, sets it as the shape, releases the reference, then calls FinishInit.
// The shared class omits Init; this helper preserves its ECX receiver and stack argument.
// @fnv 0x00ccfc60
void __fastcall InitializeConvexListShape(bhkConvexListShape* shape, void*, ShapeInfoCCF* pkInfo)
{
    AutoMemContext kScope(0x10);
    int iA = pkInfo->m_iA;
    int iB = pkInfo->m_iB;
    hkpConvexListShape* pkShape = static_cast<hkpConvexListShape*>(hkReferencedObject::operator new(sizeof(hkpConvexListShape)));
    {
        HavokConstructionAllocation allocation(pkShape);
        typedef hkpConvexListShape* (__thiscall* ConstructorFunction)(hkpConvexListShape*, hkpConvexShape**, int);
        pkShape = reinterpret_cast<ConstructorFunction>(&ConstructConvexListShape)(pkShape, reinterpret_cast<hkpConvexShape**>(iA), iB);
        allocation.memory = 0;
    }
    typedef void (__thiscall* SetShapeFunction)(bhkConvexListShape*, hkpConvexListShape*);
    reinterpret_cast<SetShapeFunction>((*reinterpret_cast<void***>(shape))[0x8c / sizeof(void*)])(shape, pkShape);
    pkShape->removeReference();
    shape->vf47(reinterpret_cast<int>(pkInfo));
}
}  // namespace fnv_00ccfc60

namespace fnv_00ccfd40 {
struct NodeRelease_tls {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int m_2b4;
};
extern __declspec(thread) NodeRelease_tls g_tls;

struct NodeRelease_guard {
    unsigned int m_saved;
    NodeRelease_guard() {
        m_saved = g_tls.m_2b4;
        g_tls.m_2b4 = 0x10;
    }
    ~NodeRelease_guard() {
        g_tls.m_2b4 = m_saved;
    }
};

class NodeRelease_sub {
public:
    virtual void vfn_0();
    virtual int vfn_4();
};

class NodeRelease_ref {
public:
    virtual void vfn_0();
    virtual void vfn_4();
    long m_04;
};

struct NodeRelease_node {
    unsigned int unk00;
    unsigned int unk04;
    NodeRelease_ref* m_08;
};

struct NodeRelease_mgr {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    NodeRelease_sub m_14;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    NodeRelease_node** m_44;
};

class NodeRelease_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    NodeRelease_mgr* m_08;
    void ReleaseAllNodes();
};

// Decrements the reference count of each node's ref in m_08's m_44 array and calls its vfn_4 when the count reaches zero.
// @fnv 0x00ccfd40
void NodeRelease_cls::ReleaseAllNodes() {
    NodeRelease_guard guard;
    if (this != 0) {
        NodeRelease_mgr* mgr = m_08;
        if (mgr != 0) {
            int i = mgr->m_14.vfn_4();
            if (i != 0) {
                do {
                    --i;
                    mgr = m_08;
                    if (mgr != 0) {
                        NodeRelease_node* node = mgr->m_44[i];
                        if (node != 0) {
                            NodeRelease_ref* ref = node->m_08;
                            if (ref != 0) {
                                if (InterlockedDecrement((volatile long*)&ref->m_04) == 0) {
                                    ref->vfn_4();
                                }
                            }
                        }
                    }
                } while (i != 0);
            }
        }
    }
}
}  // namespace fnv_00ccfd40

namespace fnv_00cd0480 {
extern __declspec(thread) int g_tlsMemContext;
class ContextScope {
 int previous;
public:
 ContextScope() { previous = g_tlsMemContext; g_tlsMemContext = 16; }
 ~ContextScope() { g_tlsMemContext = previous; }
};
inline void Add(StrArr* array,char* value) {
 unsigned int index = array->m_usSize;
 if(index >= array->m_usMaxSize) array->SetSize(index+array->m_usGrowBy);
 array->SetAt(index,value);
}
struct CountInterface { virtual void unused(); virtual int count(); };
struct CountObject { int unk00,unk04,unk08,unk0c,unk10; CountInterface value; };
extern char* DAT_012686c4;
extern const char DAT_010c41b0[];
extern const char DAT_010c6040[];
char* NiViewerStrings_NiGetViewerString_Title(char*);
char* NiGetViewerString_00a7d4d0(const char*,int);
int BSsprintf(char*,int,const char*,...);
struct ListOwner {
 int unk00,unk04; CountObject* object;
 void bhkConvexShape_GetViewerStrings(StrArr*);
 void AppendCountInfo(StrArr*);
 static int GetCount(ListOwner* p) {
 CountObject* o = p ? p->object : 0;
 return o ? o->value.count() : 0;
 }
};
// @fnv 0x00cd0480
void ListOwner::AppendCountInfo(StrArr* output) {
 ContextScope scope;
 bhkConvexShape_GetViewerStrings(output);
 Add(output,NiViewerStrings_NiGetViewerString_Title(DAT_012686c4));
 int count = GetCount(this);
 Add(output,NiGetViewerString_00a7d4d0(DAT_010c41b0,count));
 for (int i=0;i<count;++i) {
 char buffer[32];
 BSsprintf(buffer,32,DAT_010c6040,i);
 }
}
}  // namespace fnv_00cd0480

struct FNVArray {
    int* m_data;
    int m_iElementCount;
    unsigned int m_capacityFlags;
    void __thiscall hkArrayBase__spliceInto(void* allocator, int index, int removeCount, const int* source, int insertCount);
};
extern void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int newCapacity, int elementSize);
extern void __cdecl hkMemUtil_memMove(void* dest, const void* src, unsigned int byteCount);
// @fnv 0x00cd1d80
// src: COMMUNITY 0x00cd1d80
void FNVArray::hkArrayBase__spliceInto(void* allocator, int index, int removeCount, const int* source, int insertCount) {
    int iNewCount = (m_iElementCount - removeCount) + insertCount;
    int p = (m_iElementCount - index) - removeCount;
    int cnt = m_capacityFlags & 0x3fffffff;
    if (cnt < iNewCount) {
        cnt += cnt;
        if (iNewCount >= cnt) cnt = iNewCount;
        hkArrayUtil__reserve(allocator, this, cnt, 4);
    }
    hkMemUtil_memMove(m_data + (index + insertCount), m_data + (index + removeCount), p * 4);
    int* pInsertPos = m_data + index;
    for (int i = 0; i < insertCount; ++i) pInsertPos[i] = source[i];
    m_iElementCount = iNewCount;
}

// FUN_00cd3b00 : an empty __stdcall function with four arguments.
// MSVC emits only the stack cleanup: ret 0x10.
// @fnv 0x00cd3b00
// src: COMMUNITY 0x00cd3b00
void __stdcall nullsub_36(int a, int b, int c, int d) {
}

// FUN_00cd3c80: constant return 6
// @fnv 0x00cd3c80
// src: GUESS 0x00cd3c80 (confidence: high)
int __cdecl Object_ReturnSix()
{
    return 6;
}

extern int DAT_010cb344;

struct FUN_00cd3c90_cls
{
    void* m_pVtable;
    unsigned short m_uiValue1;
    unsigned short m_uiUnk;

    void* InitializeFields_00cd3c90();
};

// @fnv 0x00cd3c90
// src: GUESS 0x00cd3c90 (confidence: low)
void* FUN_00cd3c90_cls::InitializeFields_00cd3c90()
{
    m_uiUnk = 1;
    m_pVtable = (void*)&DAT_010cb344;
    return this;
}

extern float DAT_01013970;

struct SpawnedObjectBase
{
    unsigned short m_unk00;
    unsigned short m_unk02;
    float m_unk04;

    SpawnedObjectBase()
    {
        m_unk04 = DAT_01013970;
        m_unk02 = 1;
    }
};

struct FUN_00cd3f90 : SpawnedObjectBase
{
    virtual void Unk00();

    FUN_00cd3f90();
};

// @fnv 0x00cd3f90
FUN_00cd3f90::FUN_00cd3f90()
{
}

extern char DAT_010cb398[];

struct FUN_00cd4260_cls {
    void* m_vptr;
    unsigned short unk04;
    unsigned short m_w06;

    FUN_00cd4260_cls* SetVirtualTable_00cd4260();
};

// @fnv 0x00cd4260
// src: GUESS 0x00cd4260 (confidence: low)
FUN_00cd4260_cls* FUN_00cd4260_cls::SetVirtualTable_00cd4260()
{
    m_w06 = 1;
    m_vptr = DAT_010cb398;
    return this;
}

namespace fnv_00cd7d60 {
struct TlsMemBlock {
    int unk000; int unk004; int unk008; int unk00c;
    int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c;
    int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c;
    int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c;
    int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c;
    int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4; int unk0a8; int unk0ac;
    int unk0b0; int unk0b4; int unk0b8; int unk0bc;
    int unk0c0; int unk0c4; int unk0c8; int unk0cc;
    int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    int unk0e0; int unk0e4; int unk0e8; int unk0ec;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc;
    int unk100; int unk104; int unk108; int unk10c;
    int unk110; int unk114; int unk118; int unk11c;
    int unk120; int unk124; int unk128; int unk12c;
    int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c;
    int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c;
    int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c;
    int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4; int unk1a8; int unk1ac;
    int unk1b0; int unk1b4; int unk1b8; int unk1bc;
    int unk1c0; int unk1c4; int unk1c8; int unk1cc;
    int unk1d0; int unk1d4; int unk1d8; int unk1dc;
    int unk1e0; int unk1e4; int unk1e8; int unk1ec;
    int unk1f0; int unk1f4; int unk1f8; int unk1fc;
    int unk200; int unk204; int unk208; int unk20c;
    int unk210; int unk214; int unk218; int unk21c;
    int unk220; int unk224; int unk228; int unk22c;
    int unk230; int unk234; int unk238; int unk23c;
    int unk240; int unk244; int unk248; int unk24c;
    int unk250; int unk254; int unk258; int unk25c;
    int unk260; int unk264; int unk268; int unk26c;
    int unk270; int unk274; int unk278; int unk27c;
    int unk280; int unk284; int unk288; int unk28c;
    int unk290; int unk294; int unk298; int unk29c;
    int unk2a0; int unk2a4; int unk2a8; int unk2ac;
    int unk2b0;
    int m_iTrailingValue;
};
extern __declspec(thread) TlsMemBlock g_tlsMem;

struct MemClassGuard {
    int saved;
    MemClassGuard(int cls) { saved = g_tlsMem.m_iTrailingValue; g_tlsMem.m_iTrailingValue = cls; }
    ~MemClassGuard() { g_tlsMem.m_iTrailingValue = saved; }
};

struct ChunkAllocator {
    virtual void unk00();
    virtual void* allocateChunk(int size);
    virtual void freeChunk(void* p, int size);
};
struct MemHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ChunkAllocator* allocator;
    void* allocateChunk(int n) { return allocator->allocateChunk(n); }
    void freeChunk(void* p, int n) { allocator->freeChunk(p, n); }
};
MemHolder* GetMemHolder();

struct ShapeData {
    int data;
    int count;
    int stride;
};
struct ShapeParam {
    int unk00;
    float radius;
    int data;
    int count;
    int unk10;
    int extra;
};

struct RefObject {
    void* vtbl;
    unsigned short GetAllocationSize;
    short refCount;
    void removeReference();
    static void* operator new(unsigned int size) {
        RefObject* b = static_cast<RefObject*>(GetMemHolder()->allocateChunk(size));
        b->GetAllocationSize = static_cast<unsigned short>(size);
        return b;
    }
    static void operator delete(void* p, unsigned int size) {
        GetMemHolder()->freeChunk(p, size);
    }
};

struct ShapeBase : RefObject {
    int unk08;
    int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
    int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C;
    ShapeBase(const ShapeData& d, int* extra, float radius);
};

extern void* ShapeDerived_vftable;
struct ShapeDerived : ShapeBase {
    ShapeDerived(const ShapeData& d, int* extra, float radius) : ShapeBase(ShapeData(d), extra, radius) {
        vtbl = &ShapeDerived_vftable;
    }
};

struct ShapeOwner {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual void SetShape(RefObject* shape);
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8();
    virtual void ApplyParam(ShapeParam* p);
    void CreateShapeAndApplyParam(ShapeParam* p);
};

// Builds a ShapeDerived from the ShapeParam's data, count, radius and extra, sets it on the owner, releases the reference, then applies the param.
// @fnv 0x00cd7d60
void ShapeOwner::CreateShapeAndApplyParam(ShapeParam* apParam) {
    MemClassGuard guard(0x10);
    ShapeData d;
    d.count = apParam->count;
    d.stride = 0x10;
    d.data = apParam->data;
    ShapeDerived* shape = new ShapeDerived(d, &apParam->extra, apParam->radius);
    SetShape(shape);
    shape->removeReference();
    ApplyParam(apParam);
}
}  // namespace fnv_00cd7d60

namespace fnv_00cd7e80 {
extern unsigned int DAT_012680f8;
extern unsigned int DAT_01268274;
extern unsigned int DAT_01268250;
extern unsigned int DAT_0126869c;

struct FUN_00c87c30_owner {
    FUN_00c87c30_owner();
    virtual void unkB0();
    ~FUN_00c87c30_owner();
    unsigned int m_04;
    unsigned int m_08;
};

struct ChainA_cls : public FUN_00c87c30_owner {
    virtual void unkA0();
    unsigned int m_0c;
    unsigned int m_10;
    ChainA_cls() {
        m_0c = 0;
        m_10 = 0;
        DAT_012680f8 += 1;
    }
};

struct ChainB_cls : public ChainA_cls {
    virtual void unkB1();
    ChainB_cls() {
        DAT_01268274 += 1;
    }
};

struct ChainC_cls : public ChainB_cls {
    virtual void unkC2();
    ChainC_cls() {
        DAT_01268250 += 1;
    }
};

struct ChainD_cls : public ChainC_cls {
    virtual void unkD3();
    ChainD_cls() {
        DAT_0126869c += 1;
    }
};

struct FUN_00cd7e80 : public ChainD_cls {
    virtual void unkE4();
    void CreateShapeAndApplyParam(unsigned int a);
    FUN_00cd7e80(unsigned int a);
};

// Runs CreateShapeAndApplyParam with a, then increments DAT_0126869c.
// @fnv 0x00cd7e80
FUN_00cd7e80::FUN_00cd7e80(unsigned int auiValue) {
    CreateShapeAndApplyParam(auiValue);
    DAT_0126869c += 1;
}
}  // namespace fnv_00cd7e80

extern int DAT_012686e8;

// @fnv 0x00cd7f20
// src: COMMUNITY 0x00cd7f20
int* __cdecl bhkCharControllerShape_GetRTTI()
{
    return &DAT_012686e8;
}

namespace fnv_00cd8820 {
extern "C" int DAT_010cb644;
extern "C" unsigned int DAT_01267e30;
extern "C" unsigned int DAT_01267e34;
extern "C" unsigned int DAT_01267e38;
extern "C" unsigned int DAT_01267e3c;

struct FUN_00cd8820_Block128 {
    unsigned int m_auiBitFieldWords[32];
};



class FUN_00cd8820_cls {
public:
    void* m_pVtable;
    unsigned short m_04;
    unsigned short m_06;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_00cd8820_Block128 m_10;
    float m_90;
    float m_94;
    unsigned int m_98;
    unsigned int m_9c;
    __declspec(align(16)) unsigned char m_a0[sizeof(hkVector4)];
    float m_b0;
    unsigned char m_b4;
    unsigned char m_b5;
    unsigned char m_b6;
    unsigned char m_b7;
    unsigned int m_b8;
    unsigned int m_bc;
    __declspec(align(16)) unsigned char m_c0[sizeof(hkVector4)];
    __declspec(align(16)) unsigned char m_d0[sizeof(hkVector4)];
    __declspec(align(16)) unsigned char m_e0[sizeof(hkVector4)];
    FUN_00cd8820_cls(const FUN_00cd8820_Block128* src);
};

// Initializes the object: sets the vtable, copies the 128-byte block and a vector from src, zeroes floats and bytes, and copies three vectors from DAT_01267e30.
// @fnv 0x00cd8820
FUN_00cd8820_cls::FUN_00cd8820_cls(const FUN_00cd8820_Block128* apSource) {
    m_pVtable = (void*)&DAT_010cb644;
    m_06 = 1;
    m_10 = *apSource;
    m_90 = 0.0f;
    m_94 = 0.0f;
    CopyVectorWords(*reinterpret_cast<hkVector4*>(m_a0), *(const hkVector4*)((const char*)apSource + 0x30));
    m_b0 = 0.0f;
    m_b4 = 0;
    CopyVectorWords(*reinterpret_cast<hkVector4*>(m_c0), *(const hkVector4*)&DAT_01267e30);
    CopyVectorWords(*reinterpret_cast<hkVector4*>(m_d0), *(const hkVector4*)&DAT_01267e30);
    CopyVectorWords(*reinterpret_cast<hkVector4*>(m_e0), *(const hkVector4*)&DAT_01267e30);
}
}  // namespace fnv_00cd8820

extern float DAT_0101df44;

class FUN_00cd8a10_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned char m_60;
    unsigned char unk61;
    unsigned char unk62;
    unsigned char unk63;
    unsigned int m_64;
    float m_68;
    float m_6c;
    float m_70;
    float m_74;
    float m_78;
    float m_7c;
    unsigned int m_80;
    unsigned char m_84;

    FUN_00cd8a10_cls* InitializeDefaults();
};

// Sets the object's default values: m_68 from DAT_0101df44, m_60 to 1, several floats to 1.0f, and m_64, m_80, m_84 to 0, then returns this.
// @fnv 0x00cd8a10
FUN_00cd8a10_cls* FUN_00cd8a10_cls::InitializeDefaults()
{
    m_68 = DAT_0101df44;
    m_60 = 1;
    m_6c = 1.0f;
    m_64 = 0;
    m_70 = 1.0f;
    m_74 = 1.0f;
    m_78 = 1.0f;
    m_7c = 1.0f;
    m_80 = 0;
    m_84 = 0;
    return this;
}

// FUN_00cd9ed0 : sets a byte flag through its first argument.
//   mov eax,[esp+4] / mov byte ptr [eax],1 / ret 8
// @fnv 0x00cd9ed0
// src: GUESS 0x00cd9ed0 (confidence: high)
void __stdcall Runtime_SetOutputByteFlag(unsigned char* flag, int unused) {
    *flag = 1;
}



// Pose operations not declared in the shared header retain their original ECX entry points.
// @fnv 0x00cd9ee0
void __fastcall InvalidatePose(hkaPose* pose) {
    int count = pose->m_pSkeleton->m_kBones.m_iElementCount;
    for (int i = 0; i < count; ++i) {
        pose->m_pBoneFlags[i] = 3;
    }
    pose->m_bPoseFlag.m_cBooleanValue = 0;
    pose->m_bPoseInitialized.m_cBooleanValue = 0;
}


void __cdecl hkString_memCpy(void* a, void* b, int c);

// @fnv 0x00cd9f10
void __fastcall SetLocalPose(hkaPose* pose, int, void** p) {
    int count = pose->m_pSkeleton->m_kBones.m_iElementCount;
    hkString_memCpy(pose->m_pLocalPose.m_data, *p, count * 48);
    for (int i = 0; i < count; i++) {
        pose->m_pBoneFlags[i] = 2;
    }
    pose->m_bPoseInitialized = true;
    *(volatile unsigned char*)&pose->m_bPoseFlag.m_cBooleanValue = 0;
}


void __cdecl AllocateFillBlock(void* dst, int value, unsigned int size);

// @fnv 0x00cd9f60
void __fastcall SetModelPose(hkaPose* pose, int, int* p)
{
    int count = pose->m_pSkeleton->m_kBones.m_iElementCount;
    AllocateFillBlock(pose->m_pModelPose.m_data, *p, (unsigned int)(count * 3 * 16));
    int i = 0;
    unsigned char zero = 0;
    if (count > 0) {
        do {
            pose->m_pBoneFlags[i] = 1;
            ++i;
        } while (i < count);
    }
    *(volatile unsigned char*)&pose->m_bPoseInitialized.m_cBooleanValue = zero;
    *(volatile unsigned char*)&pose->m_bPoseFlag.m_cBooleanValue = 1;
}



// @fnv 0x00cd9fe0
hkArrayBase<hkQsTransform>* __fastcall AccessModelPose(hkaPose* pose)
{
    int count = pose->m_pSkeleton->m_kBones.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        pose->m_pBoneFlags[i] = 1;
    }
    pose->m_bPoseInitialized = false;
    pose->m_bPoseFlag = true;
    return &pose->m_pModelPose;
}



// @fnv 0x00cda010
bool* __fastcall CheckFlagCombinations(hkaPose* pose, int, bool* result) {
    int count = pose->m_pSkeleton->m_kBones.m_iElementCount;
    int i = 0;
    for (i = 0; i < count; i++) {
        unsigned int v = pose->m_pBoneFlags[i];
        if ((v & 1) != 0 && (v & 2) != 0) {
            goto fail;
        }
    }
    if (pose->m_bPoseInitialized.m_cBooleanValue != 0) {
        for (i = 0; i < count; i++) {
            if ((pose->m_pBoneFlags[i] & 1) != 0) {
                goto fail;
            }
        }
    }
    if (pose->m_bPoseFlag.m_cBooleanValue != 0) {
        for (i = 0; i < count; i++) {
            if ((pose->m_pBoneFlags[i] & 2) != 0) {
                goto fail;
            }
        }
    }
    *result = true;
    return result;
fail:
    *result = false;
    return result;
}

void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int newCapacity, int elementSize) throw();

__forceinline hkMemoryRouter& __cdecl GetMemoryRouter()
{
    return *reinterpret_cast<hkMemoryRouter*>(fnv_00cce0d0::hkMemoryRouter_getInstance());
}

// hkArray (include/hkArray.h) bodies SolverBuffers::InitBuffers inlines; hkContainerHeapAllocator = the router heap.
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return GetMemoryRouter().heap();
}
template <class T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    int cap = getCapacity();
    if (cap < n) {
        int cap2 = cap * 2;
        int newSize = n < cap2 ? cap2 : n;
        hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
    }
}
template <class T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}
template <class T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n, const T& fill)
{
    GrowArrayCapacity(alloc, n);
    int num = n - m_iElementCount;
    T* p = m_data + m_iElementCount;
    for (int i = 0; i < num; i++) {
        p[i] = fill;
    }
    m_iElementCount = n;
}
template <class T> __forceinline void hkArrayBase<T>::_reserveExactly(hkMemoryAllocator& alloc, int n)
{
    if (getCapacity() < n) {
        hkArrayUtil__reserve(&alloc, this, n, sizeof(T));
    }
}

struct Elem30 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
};

struct SolverInfo {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18;
    int m_iCapacityFlags;
    int unk20; int unk24; int unk28; int unk2C; int unk30;
    int m_numWords;
};

struct SolverBuffers {
    SolverInfo* m_info;
    hkArray<Elem30> m_arrayA;
    hkArray<Elem30> m_arrayB;
    hkArray<int> m_arrayC;
    int unk28;
    hkArray<unsigned int> m_bits;

    void InitSingle(int arg);
    void InitMulti(int arg);
    void InitBuffers(int mode, int unused, int arg);
};

// @fnv 0x00cdb150
void SolverBuffers::InitBuffers(int mode, int unused, int arg)
{
    int n = m_info->m_iCapacityFlags;
    m_arrayB.setSize(n);
    m_arrayA.setSize(n);
    m_arrayC.setSize(n);
    if (mode == 1) {
        InitSingle(arg);
    } else {
        InitMulti(arg);
    }
    m_bits.reserveExactly((m_info->m_numWords + 3) & ~3);
    m_bits.setSize(m_info->m_numWords, 0);
}

struct FUN_00cdb2a0_cls {
    volatile unsigned int m_i00;
    volatile unsigned int m_i04;
    volatile unsigned int m_i08;
    volatile unsigned int m_i0c;
    volatile unsigned int m_i10;
    volatile unsigned int m_i14;
    volatile unsigned int m_i18;
    volatile unsigned int m_i1c;
    volatile unsigned int m_i20;
    volatile unsigned int m_i24;
    volatile unsigned int m_i28;
    volatile unsigned int m_i2c;
    volatile unsigned int m_i30;
    volatile unsigned int m_i34;

    void InitBuffers(unsigned int a1, unsigned int a2, unsigned int a3);
    FUN_00cdb2a0_cls* hkaPose_hkaPose(unsigned int a1, unsigned int a2, unsigned int a3);
};

// @fnv 0x00cdb2a0
// src: HAVOK_LIB 0x00cdb2a0
FUN_00cdb2a0_cls* FUN_00cdb2a0_cls::hkaPose_hkaPose(unsigned int a1, unsigned int a2, unsigned int a3)
{
    m_i00 = a2;
    m_i04 = 0;
    m_i08 = 0;
    m_i0c = 0x80000000;
    m_i10 = 0;
    m_i14 = 0;
    m_i18 = 0x80000000;
    m_i1c = 0;
    m_i20 = 0;
    m_i24 = 0x80000000;
    m_i2c = 0;
    m_i30 = 0;
    m_i34 = 0x80000000;
    InitBuffers(a1, a2, a3);
    return this;
}

struct S_00cdb2f0_Arr {
    int* data;
    int size;
    unsigned int cap;
    S_00cdb2f0_Arr() : data(0), size(0), cap(0x80000000) {}
};
struct FUN_00cdb2f0 {
    int unk00;
    S_00cdb2f0_Arr a04;
    S_00cdb2f0_Arr a10;
    S_00cdb2f0_Arr a1c;
    int unk28;
    S_00cdb2f0_Arr a2c;
    void __thiscall InitBuffers(int arg1, int arg2, int* values);
    FUN_00cdb2f0(int arg1, int arg2, int arg3, int arg4);
};

// Initialises unk00 from arg2 and calls InitBuffers with arg1, arg2 and a three-element array built from arg3 and arg4.
// @fnv 0x00cdb2f0
FUN_00cdb2f0::FUN_00cdb2f0(int arg1, int aiValue, int aiFirst, int aiSecond) : unk00(aiValue)
{
    int values[3];
    values[0] = aiFirst;
    values[1] = aiSecond;
    values[2] = aiSecond | 0x80000000u;
    InitBuffers(arg1, aiValue, values);
}

class FUN_00cdb3d0_cls {
public:
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
	int m_28;
	void SetField28(int value);
};

// @fnv 0x00cdb3d0
// src: GUESS 0x00cdb3d0 (confidence: low)
void FUN_00cdb3d0_cls::SetField28(int value)
{
	m_28 = value;
}

class hkMemoryRouter;
namespace fnv_00cdb6f0 {

 // Opaque tag preserves the existing external function signature.

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00cdb6f0_sub {
    void Reset();
};

struct FUN_00cdb6f0_cls {
    void* m_pData4;
    int m_iCount4;
    unsigned int m_uCap4;
    void* m_pData3;
    int m_iCount3;
    unsigned int m_uCap3;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCap2;
    FUN_00cdb6f0_sub* m_pSub;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCap1;

    void ClearArrays();
};

// Resets m_pSub, then frees each of the four arrays through the audio allocator and clears its data pointer, count and capacity.
// @fnv 0x00cdb6f0
void FUN_00cdb6f0_cls::ClearArrays()
{
    m_pSub->Reset();

    hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder)->m_heap);
    unsigned int uCap1 = m_uCap1;
    m_iCount1 = 0;
    if ((uCap1 & 0x80000000u) == 0) {
        FreeAudioArray(pAllocator, m_pData1, (uCap1 & 0x3fffffffu) * 2);
    }
    m_pData1 = 0;
    m_uCap1 = 0x80000000u;

    hkMemoryRouter* pHolder2 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator2 = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder2)->m_heap);
    unsigned int uCap2 = m_uCap2;
    m_iCount2 = 0;
    if ((uCap2 & 0x80000000u) == 0) {
        FreeAudioArray(pAllocator2, m_pData2, (uCap2 & 0x3fffffffu) * 64);
    }
    m_pData2 = 0;
    m_uCap2 = 0x80000000u;

    hkMemoryRouter* pHolder3 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator3 = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder3)->m_heap);
    unsigned int uCap3 = m_uCap3;
    m_iCount3 = 0;
    if ((uCap3 & 0x80000000u) == 0) {
        FreeAudioArray(pAllocator3, m_pData3, (uCap3 & 0x3fffffffu) * 4);
    }
    m_pData3 = 0;
    m_uCap3 = 0x80000000u;

    hkMemoryRouter* pHolder4 = hkMemoryRouter_getInstance();
    hkMemoryAllocator* pAllocator4 = reinterpret_cast<hkMemoryAllocator*>(reinterpret_cast<::hkMemoryRouter*>(pHolder4)->m_heap);
    unsigned int uCap4 = m_uCap4;
    m_iCount4 = 0;
    if ((uCap4 & 0x80000000u) == 0) {
        FreeAudioArray(pAllocator4, m_pData4, (uCap4 & 0x3fffffffu) * 48);
    }
    m_pData4 = 0;
    m_uCap4 = 0x80000000u;
}
}  // namespace fnv_00cdb6f0

namespace fnv_00cde880 {
struct FUN_00cde880_cls {
    unsigned short* m_data;
    int m_len;
    unsigned int m_cap;

    void ReplaceRange(void* owner, int pos, int nRemove, const unsigned short* src, int nInsert);
};

extern "C" void __cdecl hkArrayUtil__reserve(void* owner, FUN_00cde880_cls* buf, int newCap, int stride);
extern "C" void __cdecl hkMemUtil_memMove(void* dst, const void* src, unsigned int bytes);

// Grows the buffer if needed, shifts the tail right by nInsert-nRemove elements, copies nInsert elements from src at pos, and updates m_len.
// @fnv 0x00cde880
void FUN_00cde880_cls::ReplaceRange(void* owner, int pos, int nRemove, const unsigned short* src, int nInsert)
{
    int len = m_len;

    int iNewLength = len - nRemove + nInsert;
    int iTailCount = len - pos - nRemove;
    int cap = (int)(m_cap & 0x3fffffffu);
    if (cap < iNewLength) {
        int g = cap * 2;
        if (iNewLength >= g) {
            g = iNewLength;
        }
        hkArrayUtil__reserve(owner, this, g, 2);
    }
    hkMemUtil_memMove(m_data + pos + nInsert, m_data + pos + nRemove, (unsigned int)iTailCount * 2);
    unsigned short* dst = m_data + pos;
    for (int i = 0; i < nInsert; i++) {
        dst[i] = src[i];
    }
    m_len = iNewLength;
}
}  // namespace fnv_00cde880

struct CallTarget_00cde880 { int ReplaceRange(int, int, int, int, int); };
struct SearchObject {
    int ProcessAndReturnValue_00cde920(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00cde920
// src: GUESS 0x00cde920 (confidence: low)
int SearchObject::ProcessAndReturnValue_00cde920(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int uiCallResult = (unsigned int)((CallTarget_00cde880*)this)->ReplaceRange((int)arg0, (int)arg1, (int)0u, (int)arg2, (int)arg3);
    return (int)uiCallResult;
}

class FUN_00cde940_cls {
public:
    void ProcessAndReturnValue_00cde920(int p1, int p2, int p3, int p4);
    void ForwardCall_00cde940(int p1, int p2, int p3);
};

// @fnv 0x00cde940
// src: GUESS 0x00cde940 (confidence: low)
void FUN_00cde940_cls::ForwardCall_00cde940(int p1, int p2, int p3)
{
    this->ProcessAndReturnValue_00cde920(p1, p2, p3, 1);
}

struct FUN_00cdea80_cls {
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int m_e8;
    int hkpRagdollConstraintData_getConeMotor();
};

// @fnv 0x00cdea80
// src: COMMUNITY 0x00cdea80
int FUN_00cdea80_cls::hkpRagdollConstraintData_getConeMotor() {
    return m_e8;
}

class FUN_00cdeaa0_cls {
public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int m_iE4;
    unsigned int hkpRagdollConstraintData_getPlaneMotor();
};
// @fnv 0x00cdeaa0
// src: COMMUNITY 0x00cdeaa0
unsigned int FUN_00cdeaa0_cls::hkpRagdollConstraintData_getPlaneMotor() { return m_iE4; }

struct FUN_00cdeac0_cls {
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    unsigned char unkA0;
    unsigned char unkA1;
    unsigned char m_bA2;
    unsigned char* __thiscall CopyFieldA2ToOutput_00cdeac0(unsigned char* pOut);
};

// @fnv 0x00cdeac0
// src: GUESS 0x00cdeac0 (confidence: low)
unsigned char* FUN_00cdeac0_cls::CopyFieldA2ToOutput_00cdeac0(unsigned char* pOut)
{
    *pOut = m_bA2;
    return pOut;
}



class RangeBase : public hkReferencedObject {
public:
    RangeBase() { m_bEnableState = false; }
    virtual void v0();
    struct HkBool { char m_cBooleanValue; HkBool() {} HkBool(bool b) { m_cBooleanValue = (char)b; } HkBool& operator=(bool b) { m_cBooleanValue = (char)b; return *this; } } m_bEnableState;
};

class FUN_00cdf560 : public RangeBase {
public:
    FUN_00cdf560(int iUnused);
    virtual void v0();
    float m_fMinimum;
    float m_fMaximum;
    float m_fFactor;
    float m_fScaleA;
    float m_fExponent;
    float m_fScaleB;
};

// Initializes the range bounds to -1000000 and 1000000, enables the range flag, and sets factor, scale and exponent defaults.
// @fnv 0x00cdf560
FUN_00cdf560::FUN_00cdf560(int iUnused)
{
    m_fMinimum = -1000000.0f;
    m_fMaximum = 1000000.0f;
    m_bEnableState = true;
    m_fFactor = 0.8f;
    m_fScaleA = 1.0f;
    m_fScaleB = 1.0f;
    m_fExponent = 2.0f;
}

struct CDF760FinishFlag {
    int m_bFinishing;
};

struct CDF760Member {
    int unk00;
    int unk04;
    void* m_pvOwner;

    void hkpBridgeConstraintAtom_init(void* pvOwner);

    CDF760Member(CDF760FinishFlag flag) {
        if (flag.m_bFinishing)
            hkpBridgeConstraintAtom_init(m_pvOwner);
    }
};

class FUN_00cdf760 {
public:
    int unk04;
    int unk08;
    int unk0C;
    CDF760Member m_kMember;

    FUN_00cdf760(CDF760FinishFlag flag);
    virtual void vfunc00();
};

// @fnv 0x00cdf760
FUN_00cdf760::FUN_00cdf760(CDF760FinishFlag flag) : m_kMember(flag) {
    if (flag.m_bFinishing)
        m_kMember.hkpBridgeConstraintAtom_init(this);
}

extern __declspec(thread) int g_iCC2950AllocTag;

extern const char* g_pcCC2950Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class FUN_00cc2950_cls {
public:
    void CC2950BaseGetViewerStrings(StrArr* pkArray);
    void AddNameToViewerStrings(StrArr* pkArray);
};

// Sets an allocation tag, appends the base viewer strings, then adds the string returned by FUN_00a7d330(g_pcCC2950Name) to the array.
// @fnv 0x00cc2950
void FUN_00cc2950_cls::AddNameToViewerStrings(StrArr* pkArray)
{
    AutoMemContext kScope(0x10);
    CC2950BaseGetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCC2950Name);
    AppendStringReference(pkArray, pcName);
}

struct S_arg
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00C;
    unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01C;
    unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02C;
    unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03C;
    unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04C;
    unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05C;
    unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06C;
    unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07C;
    unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08C;
    unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09C;
    unsigned int unk0A0; unsigned int unk0A4; unsigned int unk0A8; unsigned int unk0AC;
    unsigned int unk0B0; unsigned int unk0B4; unsigned int unk0B8; unsigned int unk0BC;
    unsigned int unk0C0; unsigned int unk0C4; unsigned int unk0C8; unsigned int unk0CC;
    unsigned int unk0D0; unsigned int unk0D4; unsigned int unk0D8; unsigned int unk0DC;
    unsigned int unk0E0; unsigned int unk0E4; unsigned int unk0E8; unsigned int unk0EC;
    unsigned int unk0F0; unsigned int unk0F4; unsigned int unk0F8; unsigned int unk0FC;
    unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10C;
    unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11C;
    unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12C;
    unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13C;
    unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14C;
    unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15C;
    unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16C;
    unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17C;
    unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18C;
    unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19C;
    unsigned int unk1A0; unsigned int unk1A4; unsigned int unk1A8; unsigned int unk1AC;
    unsigned int unk1B0; unsigned int unk1B4; unsigned int unk1B8; unsigned int unk1BC;
    unsigned int unk1C0; unsigned int unk1C4; unsigned int unk1C8; unsigned int unk1CC;
    unsigned int unk1D0; unsigned int unk1D4; unsigned int unk1D8; unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1E5;
};

struct S_res
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
};

class C
{
public:
    virtual void* v00();
    virtual void* v01();
    virtual void* v02();
    virtual void* v03();
    virtual void* v04();
    virtual void* v05();
    virtual void* v06();
    virtual void* v07();
    virtual void* v08();
    virtual void* v09();
    virtual void* v0A();
    virtual void* v0B();
    virtual void* v0C();
    virtual void* v0D();
    virtual void* v0E();
    virtual void* v0F();
    virtual void* v10();
    virtual void* v11();
    virtual void* v12();
    virtual void* v13();
    virtual void* v14();
    virtual void* v15();
    virtual void* v16();
    virtual void* v17();
    virtual void* v18();
    virtual void* v19();
    virtual void* v1A();
    virtual void* v1B();
    virtual void* v1C();
    virtual void* v1D();
    virtual void* v1E();
    virtual void* v1F();
    virtual void* v20();
    virtual void* v21();
    virtual void* v22();
    virtual void* v23();
    virtual void* v24();
    virtual void* v25();
    virtual void* v26();
    virtual void* v27();
    virtual void* v28();
    virtual void* v29();
    virtual void* v2A();
    virtual void* v2B();
    virtual void* v2C();
    virtual S_res* v45(S_arg** out);
    void bhkBinaryAction_LoadBinary(S_arg* arg);
    void ProcessAndByteSwapResult(S_arg* arg);
};

// Calls FUN_00c8a7a0 on arg, then unless arg->m_1E5 is 1, obtains a result via v45 and byte-swaps its fields m_10 through m_38.
// @fnv 0x00cc2dc0
void C::ProcessAndByteSwapResult(S_arg* arg)
{
    bhkBinaryAction_LoadBinary(arg);
    if (arg->m_1E5 == 1)
        return;
    S_arg* out;
    volatile S_res* r = v45(&out);
    r->m_10 = _byteswap_ulong(r->m_10);
    r->m_14 = _byteswap_ulong(r->m_14);
    r->m_18 = _byteswap_ulong(r->m_18);
    r->m_1C = _byteswap_ulong(r->m_1C);
    r->m_20 = _byteswap_ulong(r->m_20);
    r->m_24 = _byteswap_ulong(r->m_24);
    r->m_28 = _byteswap_ulong(r->m_28);
    r->m_2C = _byteswap_ulong(r->m_2C);
    r->m_30 = _byteswap_ulong(r->m_30);
    r->m_34 = _byteswap_ulong(r->m_34);
    r->m_38 = _byteswap_ulong(r->m_38);
}

inline void CC2E50Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}

struct CC2E50Data {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned long m_ul10;
    unsigned long m_ul14;
    unsigned long m_ul18;
    unsigned long m_ul1C;
    unsigned long m_ul20;
    unsigned long m_ul24;
    unsigned long m_ul28;
    unsigned long m_ul2C;
    unsigned long m_ul30;
    unsigned long m_ul34;
    unsigned long m_ul38;
};

__forceinline void CC2E50SwapData(CC2E50Data* pkData)
{
    CC2E50Swap(pkData->m_ul10);
    CC2E50Swap(pkData->m_ul14);
    CC2E50Swap(pkData->m_ul18);
    CC2E50Swap(pkData->m_ul1C);
    CC2E50Swap(pkData->m_ul20);
    CC2E50Swap(pkData->m_ul24);
    CC2E50Swap(pkData->m_ul28);
    CC2E50Swap(pkData->m_ul2C);
    CC2E50Swap(pkData->m_ul30);
    CC2E50Swap(pkData->m_ul34);
    CC2E50Swap(pkData->m_ul38);
}

class CC2E50Object {
public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual CC2E50Data* GetData(char* pcUnused);

    void SaveBase(NiStream* pkStream);
    void bhkSpringAction_SaveBinary(NiStream* pkStream);
};

// Gets the data, byte-swaps it when the stream is not little-endian, calls SaveBase, then swaps it back.
// @fnv 0x00cc2e50
// src: XBOX_PDB 0x00cc2e50
void CC2E50Object::bhkSpringAction_SaveBinary(NiStream* pkStream)
{
    char m_ucType;
    CC2E50Data* pkData = GetData(&m_ucType);
    if (StreamField<unsigned char>(*pkStream, 0x1e4) != 1)
        CC2E50SwapData(pkData);
    SaveBase(pkStream);
    if (StreamField<unsigned char>(*pkStream, 0x1e4) != 1)
        CC2E50SwapData(pkData);
}

struct CC3840Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    float m_fSpinRate;
    float m_fGain;
};
extern const char* g_pcCC3840Name;

class CC3840Base {
public:
    void CollectBaseNames(StrArr* pkArray);
};

class CC3840Node : public CC3840Base {
public:
    int unk00;
    int unk04;
    CC3840Data* m_pUserData;

    static float GetSpinRate(CC3840Node* p) { return (p && p->m_pUserData) ? p->m_pUserData->m_fSpinRate : 0.0f; }
    static float GetGain(CC3840Node* p) { return (p && p->m_pUserData) ? p->m_pUserData->m_fGain : 0.0f; }
    void bhkMotorAction_GetViewerStrings(StrArr* pkArray);
};

// Collects base names, then adds the CC3840 name plus "SpinRate" and "Gain" entries with this node's values to the array.
// @fnv 0x00cc3840
// src: XBOX_PDB 0x00cc3840
void CC3840Node::bhkMotorAction_GetViewerStrings(StrArr* pkArray)
{
    TlsHeapGuard kGuard;
    CollectBaseNames(pkArray);
    AppendStringReference(pkArray, NiViewerStrings_NiGetViewerString_Title(g_pcCC3840Name));
    AppendStringReference(pkArray, NiGetViewerString_00a7d550("SpinRate", GetSpinRate(this)));
    AppendStringReference(pkArray, NiGetViewerString_00a7d550("Gain", GetGain(this)));
}

struct BinaryInput {
 int unk00; unsigned int position;
 unsigned int (__cdecl* reader)(BinaryInput*,void*,unsigned int,unsigned int*,unsigned int);
 void Read(void* dst,unsigned int size) {
  unsigned int componentSize=size;
  position+=reader(this,dst,size,&componentSize,1);
 }
};
struct LoadStream {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
int unk12c;
int unk130;
int unk134;
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
BinaryInput* input;
};
struct ConstraintData {
unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060;
unsigned int unk064;
unsigned int unk068;
unsigned int unk06c;
unsigned int unk070;
unsigned int unk074;
unsigned int unk078;
unsigned int unk07c;
unsigned int unk080;
unsigned int unk084;
unsigned int unk088;
unsigned int unk08c;
unsigned int unk090;
unsigned int unk094;
unsigned int unk098;
unsigned int unk09c;
unsigned int unk0a0;
unsigned int unk0a4;
unsigned int unk0a8;
unsigned int unk0ac;
unsigned int unk0b0;
unsigned int unk0b4;
unsigned int unk0b8;
unsigned int unk0bc;
unsigned int unk0c0;
unsigned int unk0c4;
unsigned int unk0c8;
unsigned int unk0cc;
unsigned int unk0d0;
unsigned int unk0d4;
unsigned int unk0d8;
unsigned int unk0dc;
unsigned int unk0e0;
unsigned int unk0e4;
unsigned int unk0e8;
unsigned int unk0ec;
unsigned int unk0f0;
unsigned int unk0f4;
unsigned int unk0f8;
unsigned int unk0fc;
unsigned int unk100;
unsigned int unk104;
unsigned int unk108;
unsigned int unk10c;
unsigned int unk110;
unsigned int unk114;
unsigned int unk118;
unsigned int unk11c;
unsigned int unk120;
unsigned int unk124;
unsigned int unk128;
unsigned int unk12c;
unsigned int unk130;
unsigned int unk134;
unsigned int unk138;
unsigned int unk13c;
unsigned int unk140;
unsigned int unk144;
unsigned int unk148;
unsigned int unk14c;
unsigned int unk150;
unsigned int unk154;
unsigned int unk158;
unsigned int unk15c;
};
struct ConstraintLoader {
 int unk00; ConstraintData* data;
 void hkConstraintCinfo_LoadBinary(LoadStream*);
 void hkWheelConstraintCinfo_LoadBinary(LoadStream*);
};
// Calls FUN_00c8a230, then reads several blocks of ConstraintData fields from the stream's input.
// @fnv 0x00cc55a0
// src: XBOX_PDB 0x00cc55a0
void ConstraintLoader::hkWheelConstraintCinfo_LoadBinary(LoadStream* stream) {
 hkConstraintCinfo_LoadBinary(stream);
 ConstraintData* values=data;
 stream->input->Read(&values->unk020,64);
 stream->input->Read(&values->unk060,64);
 stream->input->Read(&values->unk0d0,48);
 stream->input->Read(&values->unk100,48);
 stream->input->Read(&values->unk140,16);
 stream->input->Read(&values->unk150,16);
 stream->input->Read(&values->unk0a4,4);
 stream->input->Read(&values->unk0a8,4);
 stream->input->Read(&values->unk0b0,4);
 stream->input->Read(&values->unk0b4,4);
}

// Lazily create the Havok helper object; report the object size.

extern __declspec(thread) int g_iCC5AE0AllocTag;

struct CC5AE0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CC5AE0MemoryRouter& __cdecl CC5AE0GetMemoryRouter();

class CC5AE0Helper {
public:
    CC5AE0Helper();
    virtual ~CC5AE0Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC5AE0Helper* p = static_cast<CC5AE0Helper*>(CC5AE0GetMemoryRouter().heap().blockAlloc(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes) { CC5AE0GetMemoryRouter().heap().blockFree(p, nbytes); }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

class CC5AE0Owner {
public:
    int unk00;
    CC5AE0Helper* m_pkHelper;

    unsigned int EnsureHelperAllocated();
};

// Allocates m_pkHelper with new CC5AE0Helper if it is null, then returns sizeof(CC5AE0Helper).
// @fnv 0x00cc5ae0
unsigned int CC5AE0Owner::EnsureHelperAllocated()
{
    AutoMemContext kScope(0x10);
    if (!m_pkHelper)
        m_pkHelper = new CC5AE0Helper;
    return sizeof(CC5AE0Helper);
}

template <class T> inline void CC61F0LoadBinary(NiBinaryStream& kBinStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kBinStream.BinaryRead(&value, uiSize, &uiSize, 1);
}



#include "../../include/hkRotation.h"

void __cdecl CC61F0SwapRotation(hkRotation* pkRotation);
struct CC61F0ConstraintData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    hkRotation m_kRotA;
    hkRotation m_kRotB;
    int unk80; int unk84;
    float m_f88;
    float m_f8C;
    int unk90; int unk94; int unk98; int unk9C;
    float m_fA0;
    int unkA4; int unkA8; int unkAC;
    float m_fB0;
    float m_fB4;
};
struct FUN_00cc61f0_class : bhkConstraintBaseSI_blk_00cc0000_o2 {
    void hkRagdollLimitsConstraintCinfo_LoadBinary(NiStream& kStream);
};

// Loads the base constraint data, reads two rotations (byte-swapping them if the stream is not little-endian) and five floats into the constraint data.
// @fnv 0x00cc61f0
// src: XBOX_PDB 0x00cc61f0
void FUN_00cc61f0_class::hkRagdollLimitsConstraintCinfo_LoadBinary(NiStream& kStream)
{
    LoadBinaryBase(kStream);
    CC61F0ConstraintData* pkData = reinterpret_cast<CC61F0ConstraintData*>(m_pData);
    InputStream(kStream)->Read(&pkData->m_kRotA, sizeof(hkRotation));
    InputStream(kStream)->Read(&pkData->m_kRotB, sizeof(hkRotation));
    if (StreamField<unsigned char>(kStream, 0x1e5) != 1) {
        CC61F0SwapRotation(&pkData->m_kRotA);
        CC61F0SwapRotation(&pkData->m_kRotB);
    }
    CC61F0LoadBinary(*InputStream(kStream), pkData->m_fA0);
    CC61F0LoadBinary(*InputStream(kStream), pkData->m_fB0);
    CC61F0LoadBinary(*InputStream(kStream), pkData->m_fB4);
    CC61F0LoadBinary(*InputStream(kStream), pkData->m_f88);
    CC61F0LoadBinary(*InputStream(kStream), pkData->m_f8C);
}

struct CC63E0_Context {
    int unk000; int unk004; int unk008; int unk00C; int unk010; int unk014; int unk018; int unk01C;
    int unk020; int unk024; int unk028; int unk02C; int unk030; int unk034; int unk038; int unk03C;
    int unk040; int unk044; int unk048; int unk04C; int unk050; int unk054; int unk058; int unk05C;
    int unk060; int unk064; int unk068; int unk06C; int unk070; int unk074; int unk078; int unk07C;
    int unk080; int unk084; int unk088; int unk08C; int unk090; int unk094; int unk098; int unk09C;
    int unk0A0; int unk0A4; int unk0A8; int unk0AC; int unk0B0; int unk0B4; int unk0B8; int unk0BC;
    int unk0C0; int unk0C4; int unk0C8; int unk0CC; int unk0D0; int unk0D4; int unk0D8; int unk0DC;
    int unk0E0; int unk0E4; int unk0E8; int unk0EC; int unk0F0; int unk0F4; int unk0F8; int unk0FC;
    int unk100; int unk104; int unk108; int unk10C; int unk110; int unk114; int unk118; int unk11C;
    int unk120; int unk124; int unk128; int unk12C; int unk130; int unk134; int unk138; int unk13C;
    int unk140; int unk144; int unk148; int unk14C; int unk150; int unk154; int unk158; int unk15C;
    int unk160; int unk164; int unk168; int unk16C; int unk170; int unk174; int unk178; int unk17C;
    int unk180; int unk184; int unk188; int unk18C; int unk190; int unk194; int unk198; int unk19C;
    int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; int unk1B8; int unk1BC;
    int unk1C0; int unk1C4; int unk1C8; int unk1CC; int unk1D0; int unk1D4; int unk1D8; int unk1DC;
    int unk1E0;
    unsigned char m_1e4; unsigned char unk1E5; unsigned char unk1E6; unsigned char unk1E7;
    int unk1E8; int unk1EC; int unk1F0; int unk1F4; int unk1F8; int unk1FC;
    int unk200; int unk204; int unk208; int unk20C; int unk210; int unk214; int unk218; int unk21C;
    int unk220; int unk224; int unk228; int unk22C; int unk230; int unk234; int unk238; int unk23C;
    int unk240; int unk244; int unk248; int unk24C;
    NiBinaryStream* m_stream;
};
struct CC63E0_Block {
    float m00; float m04; float m08; float m0C; float m10; float m14; float m18; float m1C; float m20; float m24; float m28; float m2C;
};
struct CC63E0_Data {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    CC63E0_Block m_20;
    CC63E0_Block m_50;
    int unk80; int unk84;
    int m_88; int m_8C;
    int unk90; int unk94; int unk98; int unk9C;
    int m_A0; int unkA4; int unkA8; int unkAC;
    int m_B0; int m_B4;
};
void __cdecl CC63E0_SwapBlock(CC63E0_Block* b);
struct CC63E0_Obj {
    void* m_ppVirtualMethodTable;
    CC63E0_Data* m_data;
    void SaveBase(CC63E0_Context* ctx);
    void hkRagdollLimitsConstraintCinfo_SaveBinary(CC63E0_Context* ctx);
};
// @fnv 0x00cc63e0
// src: XBOX_PDB 0x00cc63e0
void CC63E0_Obj::hkRagdollLimitsConstraintCinfo_SaveBinary(CC63E0_Context* ctx)
{
    SaveBase(ctx);
    CC63E0_Data* d = m_data;
    if (ctx->m_1e4 != 1) {
        CC63E0_SwapBlock(&d->m_20);
        CC63E0_SwapBlock(&d->m_50);
    }
    ctx->m_stream->Write(&d->m_20, 0x30);
    ctx->m_stream->Write(&d->m_50, 0x30);
    ctx->m_stream->Write(&d->m_A0, 4);
    ctx->m_stream->Write(&d->m_B0, 4);
    ctx->m_stream->Write(&d->m_B4, 4);
    ctx->m_stream->Write(&d->m_88, 4);
    ctx->m_stream->Write(&d->m_8C, 4);
    if (ctx->m_1e4 != 1) {
        CC63E0_SwapBlock(&d->m_20);
        CC63E0_SwapBlock(&d->m_50);
    }
}

struct __declspec(novtable) ReferenceRoot78 {
    unsigned int unk04;
    unsigned int unk08;
    static void* __cdecl operator new(unsigned int size);
    static void __cdecl operator delete(void*);
    virtual ~ReferenceRoot78();
    void Initialize();
    ReferenceRoot78() { Initialize(); }
};
struct ConstraintBase78 : ReferenceRoot78 {
    unsigned int data;
    ConstraintBase78() { data = 0; ++DAT_01268188; }
    virtual ~ConstraintBase78();
};
struct Constraint78 : ConstraintBase78 {
    Constraint78() { ++DAT_0126860c; }
    virtual ~Constraint78();
};
// Allocates and constructs a new Constraint78 object, returning the pointer.
// @fnv 0x00cc67a0
Constraint78* __cdecl CreateConstraint()
{
    return new Constraint78;
}

// Create a counted shape wrapper under the Havok allocation tag and the world lock, then register it with this owner.

extern __declspec(thread) int g_iCC69D0AllocTag;

void CC69D0Lock();
void CC69D0Unlock();

class CC69D0RefObject {
public:
    CC69D0RefObject();
    virtual ~CC69D0RefObject();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
};

class CC69D0Shape : public CC69D0RefObject {
public:
    CC69D0Shape() : m_pUserData(0) { ++ms_iCount; }
    virtual ~CC69D0Shape();

    void* m_pUserData;

    static int ms_iCount;
};

class CC69D0ListShape : public CC69D0Shape {
public:
    CC69D0ListShape() { ++ms_iCount; }
    virtual ~CC69D0ListShape();

    static int ms_iCount;
};

class CC69D0Owner {
public:
    void AddShape(CC69D0Shape* pkShape, int iIndex);
    CC69D0Shape* CreateListShape(int iIndex);
};

// Allocates a new CC69D0ListShape under a lock and allocation tag, adds it to the owner at iIndex, and returns it.
// @fnv 0x00cc69d0
CC69D0Shape* CC69D0Owner::CreateListShape(int iIndex)
{
    AutoMemContext kScope(0x10);
    CC69D0Lock();
    CC69D0Shape* pkShape = new CC69D0ListShape;
    AddShape(pkShape, iIndex);
    CC69D0Unlock();
    return pkShape;
}

extern int DAT_010c8ce4;

struct Child_00cc6ab0
{
    void* m_pVtable;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;

    static void* operator new(unsigned int, void* p) { return p; }

    Child_00cc6ab0()
        : m_08(1), m_0c(0), m_10(0)
    {
        m_pVtable = &DAT_010c8ce4;
        m_04 = 0;
    }
};

static __forceinline Child_00cc6ab0* Make_00cc6ab0(Child_00cc6ab0* obj)
{
    Child_00cc6ab0* p = (Child_00cc6ab0*)((char*)obj + 4);
    new (obj) Child_00cc6ab0();
    return p;
}

struct Owner_00cc6ab0
{
    unsigned int unk00;
    unsigned int unk04;
    void* m_08;
    Child_00cc6ab0* m_0c;

    void Attach(void* pChild);
    Child_00cc6ab0* bhkRagdollConstraint_CreateCinfo(bool* out);
};

// @fnv 0x00cc6ab0
// src: XBOX_PDB 0x00cc6ab0
Child_00cc6ab0* Owner_00cc6ab0::bhkRagdollConstraint_CreateCinfo(bool* out)
{
    TlsGuard_t guard(g_tlsBlock.m_2b4);
    bool created = (m_0c == 0);
    *out = created;
    if (created)
    {
        Child_00cc6ab0* obj = (Child_00cc6ab0*)DAT_011f6238.Alloc(0x14);
        Child_00cc6ab0* pChild;
        if (obj != 0)
            pChild = Make_00cc6ab0(obj);
        else
            pChild = 0;
        m_0c = pChild;
        if (m_08)
        {
            void* base = pChild ? (char*)pChild - 4 : 0;
            Attach(base);
        }
    }
    return m_0c;
}

struct CC77E0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CC77E0MemoryRouter& __cdecl hkMemoryRouterCC77();

extern __declspec(thread) int g_CC77E0AllocTag;

class CC77E0Child {
public:
    CC77E0Child();
    virtual ~CC77E0Child();

    static void* operator new(unsigned int uiSize) {
        void* p = hkMemoryRouterCC77().heap().blockAlloc(uiSize);
        static_cast<CC77E0Child*>(p)->m_usMemSizeAndFlags = (unsigned short)uiSize;
        return p;
    }
    static void operator delete(void* p);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    int unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84;
    int unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4;
    int unkA8, unkAC, unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    int unkC8, unkCC;
};

class CC77E0Owner {
public:
    int unk00;
    CC77E0Child* m_pkChild;

    int EnsureChildAllocated();
};

// Creates m_pkChild with new if it is null, then returns sizeof(CC77E0Child).
// @fnv 0x00cc77e0
int CC77E0Owner::EnsureChildAllocated()
{
    AutoMemContext kScope(0x10);
    if (!m_pkChild)
        m_pkChild = new CC77E0Child();
    return sizeof(CC77E0Child);
}


struct SaveData {
    char pad00[0x20];
    Transform kFirst;
    Transform kSecond;
    char pad60[2];
    bool bFlag;
    char padA3[9];
    void* pLinked;
    char padB0[4];
    unsigned int uiB4;
    char padB8[0x10];
    unsigned int uiC8;
    unsigned int uiCC;
};
struct FUN_00cc7bc0_shell {
    void* m_pVtable;
    SaveData* m_pData;
    void hkConstraintCinfo_SaveBinary(NiStream& kStream);
    void SaveShape(void* pLinked, NiStream& kStream);
    void hkPrismaticConstraintCinfo_SaveBinary(NiStream& kStream);
};
// @fnv 0x00cc7bc0
// src: XBOX_PDB 0x00cc7bc0
void FUN_00cc7bc0_shell::hkPrismaticConstraintCinfo_SaveBinary(NiStream& kStream) {
    hkConstraintCinfo_SaveBinary(kStream);
    SaveData* pData = m_pData;
    SerializeValue(kStream, pData->kFirst);
    SerializeValue(kStream, pData->kSecond);
    SerializeValue(kStream, pData->uiC8);
    SerializeValue(kStream, pData->uiCC);
    SerializeValue(kStream, pData->uiB4);
    SaveShape(pData->pLinked, kStream);
    if (pData->pLinked)
        SerializeValue(kStream, pData->bFlag);
}

extern __declspec(thread) int g_iCC7F30AllocTag;

class BCC7F30Router {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pkHeap;

    hkMemoryAllocator& heap() { return *m_pkHeap; }
};

BCC7F30Router* BCC7F30GetRouter();



class BCC7F30Shape : public hkReferencedObject {
public:
    BCC7F30Shape();

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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
};

class BCC7F30Wrapper {
public:
    void Init(BCC7F30Shape* pkShape, int iArg);
    void InitWithShape(BCC7F30Shape* pkShape, int iArg);
};

// Creates a BCC7F30Shape if pkShape is null, then calls Init with the shape and iArg inside an allocation-tag scope.
// @fnv 0x00cc7f30
void BCC7F30Wrapper::InitWithShape(BCC7F30Shape* pkShape, int iArg)
{
    AutoMemContext kScope(0x10);
    if (!pkShape)
        pkShape = new BCC7F30Shape;
    Init(pkShape, iArg);
}

template <class T>
inline void BCC8950BinaryStreamLoad(NiBinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void BCC8950LoadBinary(NiStream& kStream, T& value)
{
    BCC8950BinaryStreamLoad(*InputStream(kStream), &value);
}

struct BCC8950Transform {
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
};

struct BCC8950ConstraintData {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BCC8950Transform m_kTransformA;
    BCC8950Transform m_kTransformB;
    int unk80;
    float m_fMinAngle;
    float m_fMaxAngle;
};

class BCC8950Base {
public:
    void LoadBinary(NiStream& kStream);
};

class BCC8950Constraint : public BCC8950Base {
public:
    void hkHingeLimitsConstraintCinfo_LoadBinary(NiStream& kStream);

    int unk00;
    BCC8950ConstraintData* m_pUserData;
};

// @fnv 0x00cc8950
// src: XBOX_PDB 0x00cc8950
void BCC8950Constraint::hkHingeLimitsConstraintCinfo_LoadBinary(NiStream& kStream)
{
    BCC8950Base::LoadBinary(kStream);
    BCC8950ConstraintData* pkData = m_pUserData;
    BCC8950LoadBinary(kStream, pkData->m_kTransformA);
    BCC8950LoadBinary(kStream, pkData->m_kTransformB);
    BCC8950LoadBinary(kStream, pkData->m_fMinAngle);
    BCC8950LoadBinary(kStream, pkData->m_fMaxAngle);
}

// Lazily create the Havok helper object; report the object size.

extern __declspec(thread) int g_iCC9890AllocTag;

struct CC9890MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CC9890MemoryRouter& __cdecl CC9890GetMemoryRouter();

class CC9890Helper {
public:
    CC9890Helper();
    virtual ~CC9890Helper();

    static void* operator new(unsigned int nbytes)
    {
        CC9890Helper* p = static_cast<CC9890Helper*>(CC9890GetMemoryRouter().heap().blockAlloc(nbytes));
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes) { CC9890GetMemoryRouter().heap().blockFree(p, nbytes); }

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

class CC9890Owner {
public:
    int unk00;
    CC9890Helper* m_pkHelper;

    unsigned int GetOrCreateHelperSize();
};

// Allocates a CC9890Helper with allocation tag 0x10 if m_pkHelper is null, then returns sizeof(CC9890Helper).
// @fnv 0x00cc9890
unsigned int CC9890Owner::GetOrCreateHelperSize()
{
    AutoMemContext kScope(0x10);
    if (!m_pkHelper)
        m_pkHelper = new CC9890Helper;
    return sizeof(CC9890Helper);
}

struct CcaArg {
    int unkCur;
    int unkValue;
    int uNewnk;
    int unk00C;
    int uTmpnk;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char m_b1e4;
};

struct CcaRes {
    int unk;
    int unk04;
    void* m_08;
    unsigned int m_0c;
};

struct CcaOwner {
    virtual ~CcaOwner() {}
    virtual void vf();
    virtual void vfCur();
    virtual void vfValue();
    virtual void vNewf();
    virtual void vTmpf();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41(int a);
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual CcaRes* vf45(int& out);
    void bhkBvTreeShape_SaveBinary(CcaArg* a);
};

void __cdecl NiStream_WriteObjectBuffer(CcaArg* a, void* p);

struct FUN_00cca130_cls : CcaOwner {
    void ProcessArg(CcaArg* a1);
};

// @fnv 0x00cca130
void FUN_00cca130_cls::ProcessArg(CcaArg* a1)
{
    int flag;
    CcaRes* res = this->vf45(flag);
    if (a1->m_b1e4 != 1) {
        { unsigned int v = res->m_0c; res->m_0c = _byteswap_ulong(v); }
    }
    this->bhkBvTreeShape_SaveBinary(a1);
    NiStream_WriteObjectBuffer(a1, res->m_08);
    this->vf41(flag);
    if (!(unsigned char)flag && a1->m_b1e4 != 1) {
        { unsigned int v = res->m_0c; res->m_0c = _byteswap_ulong(v); }
    }
}

__declspec(thread) unsigned int DAT_0126fd98;

struct FUN_00cca450_param_item {
    void* unk00;
    void* unk04;
    struct FUN_00cca450_hook* unk08;
};
struct FUN_00cca450_hook {
    void __thiscall FUN_00c905b0();
};
struct FUN_00cca450_class {
    void __thiscall TailOne(FUN_00cca450_param_item*);
    void __thiscall bhkMoppBvTreeShape_PostInit(FUN_00cca450_param_item*);
};
// @fnv 0x00cca450
// src: XBOX_PDB 0x00cca450
void FUN_00cca450_class::bhkMoppBvTreeShape_PostInit(FUN_00cca450_param_item* pItem)
{
    AutoMemContext context(0x10);
    if (pItem->unk08)
        pItem->unk08->FUN_00c905b0();
    TailOne(pItem);
}

extern const char* g_01268658;
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
struct MoppCode570 {
 int unk00, unk04, unk08, unk0c;
 hkVector4 offset;
};
struct MoppData570 {
 int unk00, unk04, unk08, unk0c, unk10;
 MoppCode570* code;
};
struct MoppOwner570 {
 int unk00, unk04;
 MoppData570* data;
 void BaseOutput(StrArr*);
 void OutputMoppCodeInfo(StrArr*);
};
// @fnv 0x00cca570
void MoppOwner570::OutputMoppCodeInfo(StrArr* output) {
 AutoMemContext context(16);
 BaseOutput(output);
 AppendStringReference(output, NiViewerStrings_NiGetViewerString_Title(g_01268658));
 MoppCode570* code = this && data ? data->code : 0;
 char buffer[32];
 sprintf_s(buffer, 32, "0x%8X", code);
 AppendStringReference(output, NiGetViewerString_00a7d5e0("MoppCode", buffer));
 NiPoint3 point;
 FUN_00458620(&point, &code->offset);
 AppendStringReference(output, static_cast<const NiPoint3&>(point).FormatToBuffer("MoppCode Offset"));
}

typedef unsigned int CCADB0size_t;

struct CCADB0MemoryManager;
extern CCADB0MemoryManager g_CCADB0MemoryManager;

extern __declspec(thread) int g_CCADB0AllocTag;

extern const float g_fCCADB0DefaultScale;

struct CCADB0Child {
    CCADB0Child() throw()
        : m_pkOwnerManager(0), m_fScale(g_fCCADB0DefaultScale), m_f10(0.0f), m_f14(0.0f), m_f18(0.0f), m_f1C(0.0f), m_f20(0.0f), m_f24(0.0f),
          m_f28(0.0f), m_f2C(0.0f), m_f30(0.0f), m_f34(0.0f), m_f38(0.0f), m_f3C(0.0f)
    {
    }

    void* m_pkOwnerManager;
    float m_fScale;
    int unk08;
    int unk0C;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2C;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3C;

    static void* operator new(CCADB0size_t uiSize) throw() { return reinterpret_cast<MemoryManager&>(g_CCADB0MemoryManager).Allocate(uiSize); }
    static void operator delete(void* pvMem) {}
};

struct CCADB0Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCADB0Child* m_pkChild;

    void CCADB0Attach(CCADB0Child* pkChild);
    CCADB0Child* bhkTriangleShape_CreateCinfo(bool* pbCreated);
};

// @fnv 0x00ccadb0
// src: XBOX_PDB 0x00ccadb0
CCADB0Child* CCADB0Owner::bhkTriangleShape_CreateCinfo(bool* pbCreated)
{
    AutoMemContext kScope(0x10);
    *pbCreated = (m_pkChild == 0);
    if (*pbCreated) {
        m_pkChild = new CCADB0Child;
        if (m_pParentNode)
            CCADB0Attach(m_pkChild);
    }
    return m_pkChild;
}

extern int DAT_012686d0;
extern int DAT_01268678;
extern int DAT_010c44e4;
extern int DAT_010ca744;

struct BccObj : S_00c87c30_Base {
    unsigned int m_14;
    BccObj() : S_00c87c30_Base() {
        m_pVtable = &DAT_01030bf4;
        unsigned int* q = &m_uiData1;
        q[0] = 0;
        q[1] = 0;
        DAT_012680f8 += 1;
        m_pVtable = &DAT_010c44e4;
        DAT_012686d0 += 1;
        m_pVtable = &DAT_010ca744;
        m_14 = 0;
        DAT_01268678 += 1;
    }
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
    static void operator delete(void* p) {}
};

struct BccOwner {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49(BccObj* node, int a1);
    BccObj* CreateBccObj(int a1);
};

// Allocates a BccObj, passes it with a1 to v49, and returns the new object.
// @fnv 0x00ccbe10
BccObj* BccOwner::CreateBccObj(int a1) {
    TlsGuard_t guard(g_tlsBlock.m_2b4);
    bhkSerializable_CloneCritLock();
    BccObj* p = new BccObj();
    this->v49(p, a1);
    bhkSerializable_CloneCritUnlock();
    return p;
}

namespace fnv_00ccc7e0 {
struct MemoryManagerAllocHelper { void* Allocate(unsigned int size); };
extern MemoryManagerAllocHelper g_memoryHeap;

extern __declspec(thread) int g_tlsAllocPool;

static int GetMemContext() { return g_tlsAllocPool; }
static void SetMemContext(int context) { g_tlsAllocPool = context; }

struct TlsPoolGuard {
    int m_iOld;
    TlsPoolGuard(int context) { m_iOld = GetMemContext(); SetMemContext(context); }
    ~TlsPoolGuard() { Leave(); }
    void Leave() { SetMemContext(m_iOld); }
};

struct LoadStream;
typedef int (__cdecl *LoadStreamReadFn)(LoadStream* stream, void* buffer, int elemSize, int* count, int flag);
struct LoadStream {
    int unk00;
    int m_iPosition;
    LoadStreamReadFn m_pfnRead;
    void ReadUInt(unsigned int* value) {
        int count = 4;
        int read = m_pfnRead(this, value, 4, &count, 1);
        m_iPosition += read;
    }
};

struct LoadContext {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    LoadStream* m_pBinaryStream;
};

struct FiveIntegerLoadRecord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FiveIntegerLoadRecord();
    ~FiveIntegerLoadRecord();
    void Load(LoadContext* ctx);
    static void* operator new[](unsigned int size) { return g_memoryHeap.Allocate(size); }
};

struct FUN_00ccc7e0_class {
    int unk00;
    int unk04;
    unsigned int m_uiCount;
    FiveIntegerLoadRecord* m_pEntries;
    void LoadEntries(LoadContext* ctx);
};

// Reads a count from the stream, allocates an array of entries, and loads each entry from the context.
// @fnv 0x00ccc7e0
void FUN_00ccc7e0_class::LoadEntries(LoadContext* ctx)
{
    TlsPoolGuard guard(16);
    ctx->m_pBinaryStream->ReadUInt(&m_uiCount);
    m_pEntries = new FiveIntegerLoadRecord[m_uiCount];
    for (unsigned int i = 0; i < m_uiCount; i++)
        m_pEntries[i].Load(ctx);
}
}  // namespace fnv_00ccc7e0

// SaveBinary of an element array: the count, then each element saves itself.

template <class T>
inline void CCC920BinaryStreamSave(NiBinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1) {
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T>
inline void CCC920SaveBinary(NiStream& kStream, const T& value) {
    CCC920BinaryStreamSave(*OutputStream(kStream), &value);
}

template <class T>
inline void CCC920SaveBinary(NiStream& kStream, const T* pValues, unsigned int ItemUpdateArray) {
    CCC920BinaryStreamSave(*OutputStream(kStream), pValues, ItemUpdateArray);
}

struct CCC920Element {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    void SaveBinary(NiStream& kStream);
};

class CCC920Array {
public:
    void* m_pVtbl;
    int unk04;
    unsigned int m_uiCount;
    CCC920Element* m_pkVertexElements;

    void bhkExtendedMeshShapeData_SaveBinary(NiStream& kStream);
};

// Writes m_uiCount to the stream, then calls SaveBinary on each of the m_uiCount elements in the array.
// @fnv 0x00ccc920
// src: XBOX_PDB 0x00ccc920
void CCC920Array::bhkExtendedMeshShapeData_SaveBinary(NiStream& kStream)
{
    CCC920SaveBinary(kStream, m_uiCount);
    for (unsigned int i = 0; i < m_uiCount; i++)
        m_pkVertexElements[i].SaveBinary(kStream);
}

extern __declspec(thread) int g_iCCDE60MemContext;

void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();

class CCDE60Object {
public:
    CCDE60Object();
    virtual ~CCDE60Object();

    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class CCDE60World {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void AddObject(CCDE60Object* pkObject, void* pvInfo);

    CCDE60Object* bhkConvexVerticesShape_CreateClone(void* pvInfo);
};

// Creates a new CCDE60Object, registers it with AddObject using pvInfo, and returns it.
// @fnv 0x00ccde60
// src: XBOX_PDB 0x00ccde60
CCDE60Object* CCDE60World::bhkConvexVerticesShape_CreateClone(void* pvInfo)
{
    AutoMemContext kContext(0x10);
    bhkSerializable_CloneCritLock();
    CCDE60Object* pkObject = new CCDE60Object;
    AddObject(pkObject, pvInfo);
    bhkSerializable_CloneCritUnlock();
    return pkObject;
}

struct MemoryCCD {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pHeapAllocator;

    hkMemoryAllocator& heap() { return *m_pHeapAllocator; }
};

MemoryCCD* __cdecl GetMemoryCCD();

extern __declspec(thread) int g_iAllocTagCCD;

struct AllocTagScopeCCD {
    int m_iSaved;

    AllocTagScopeCCD(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagCCD;
        g_iAllocTagCCD = aiAllocationTag;
    }
    ~AllocTagScopeCCD() { g_iAllocTagCCD = m_iSaved; }
};





struct ShapeCinfoCCD {
    int m_iVertices;
    int m_iArrayCapacity;
    int m_iFlags;
};

extern float g_fConvexRadiusCCD;

class ShapeCCD : public hkReferencedObject {
public:
    ShapeCCD(const ShapeCinfoCCD& kCinfo, const hkVector4& m_kPoint2, float fRadius);

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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct InfoCCD {
    int unk00;
    int unk04;
    int m_iVertices;
    int m_iArrayCapacity;
    int unk10;
    float m_kHalfExtents[4];
};

class BodyCCD {
public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void SetShape(ShapeCCD* pkShape);
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void SetInfo(const InfoCCD* pkInfo);

    void SetShapeFromInfo(const InfoCCD* pkInfo);
};

// Builds a ShapeCCD from pkInfo's vertex count, id and half extents, assigns it via SetShape, releases it, then calls SetInfo(pkInfo).
// @fnv 0x00ccdf20
void BodyCCD::SetShapeFromInfo(const InfoCCD* pkInfo)
{
    AllocTagScopeCCD kScope(0x10);
    ShapeCinfoCCD kCinfo;
    kCinfo.m_iArrayCapacity = pkInfo->m_iArrayCapacity;
    kCinfo.m_iFlags = 0x10;
    kCinfo.m_iVertices = pkInfo->m_iVertices;
    ShapeCCD* pkShape = new ShapeCCD(kCinfo, *reinterpret_cast<const hkVector4*>(pkInfo->m_kHalfExtents), g_fConvexRadiusCCD);
    SetShape(pkShape);
    pkShape->removeReference();
    SetInfo(pkInfo);
}

struct CE340Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};
CE340Router* CE340GetRouter() throw();



template <class T>
static __forceinline void CE340Array_destroy(hkArrayBase<T>& self);

template <class T>
static __forceinline void CE340Array__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc);

template <class T>
static __forceinline void CE340Array_swap(hkArrayBase<T>& self, hkArrayBase<T>& a);

template <class T>
static __forceinline void CE340Array_destroy(hkArrayBase<T>& self)
{ CE340Array__clearAndDeallocate(self, CE340GetRouter()->heap()); }

template <class T>
static __forceinline void CE340Array__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc)
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0) {
            alloc.bufFree(self.m_data, self.getCapacity() * sizeof(T));
        }
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

template <class T>
static __forceinline void CE340Array_swap(hkArrayBase<T>& self, hkArrayBase<T>& a)
{
        T* d = self.m_data; self.m_data = a.m_data; a.m_data = d;
        int s = self.m_iElementCount; self.m_iElementCount = a.m_iElementCount; a.m_iElementCount = s;
        int c = self.m_iCapacityState; self.m_iCapacityState = a.m_iCapacityState; a.m_iCapacityState = c;
    }

struct CE340ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { CE340Array_destroy(self); }
};

template <> __forceinline hkArray<hkVector4, CE340ArrayPolicy>::~hkArray() { CE340ArrayPolicy::destroy(*this); }


struct CE340Data {
    int unk00;
    int unk04;
    hkArray<hkVector4, CE340ArrayPolicy> m_arr08;
    hkArray<hkVector4, CE340ArrayPolicy> m_arr14;
};

typedef FUN_00ccd3a0_arg CE340Stream;

void __cdecl bhkStream_SwapHKArray(CE340Data* data, void* ctx, hkArray<hkVector4, CE340ArrayPolicy>* arr);
void __cdecl bhkStream_SaveBinary(CE340Stream* stream, void* value);

struct CE340Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B();
    virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28();
    virtual void SetFlag(bool flag);
    virtual void* GetContext();
    virtual void v2B(); virtual void v2C();
    virtual CE340Data* GetData(bool* flag);
    void SaveBase(CE340Stream* stream);
    void SaveWithArrays(CE340Stream* stream);
};

// @fnv 0x00cce340
void CE340Obj::SaveWithArrays(CE340Stream* stream)
{
    bool flag;
    CE340Data* data = GetData(&flag);
    hkArray<hkVector4, CE340ArrayPolicy> arrFirst;
    hkArray<hkVector4, CE340ArrayPolicy> arrSecond;
    CE340Array_swap(arrFirst, data->m_arr08);
    CE340Array_swap(arrSecond, data->m_arr14);
    if (stream->m_1e4 != 1) {
        void* ctx = GetContext();
        bhkStream_SwapHKArray(data, ctx, &data->m_arr08);
        bhkStream_SwapHKArray(data, ctx, &data->m_arr14);
    }
    SaveBase(stream);
    bhkStream_SaveBinary(stream, &arrFirst);
    bhkStream_SaveBinary(stream, &arrSecond);
    SetFlag(flag);
    if (!flag && stream->m_1e4 != 1) {
        void* ctx = GetContext();
        bhkStream_SwapHKArray(data, ctx, &data->m_arr08);
        bhkStream_SwapHKArray(data, ctx, &data->m_arr14);
    }
}

// Release the cached Havok data when requested.

extern __declspec(thread) int g_iCCE860AllocTag;

class CCE860MemoryManager;
extern CCE860MemoryManager g_kCCE860MemoryManager;

inline void __cdecl operator delete(void* pvMem)
{
    reinterpret_cast<MemoryManager&>(g_kCCE860MemoryManager).Deallocate(pvMem);
}

class CCE860Data {
public:
    ~CCE860Data();
    int unk00;
};

class CCE860Owner {
public:
    int unk00;
    int unk04;
    int unk08;
    CCE860Data* m_pUserData;

    void ReleaseData(bool bRelease);
};

// If bRelease is set, deletes the owned CCE860Data object and clears the pointer, under an allocation-tag scope.
// @fnv 0x00cce860
void CCE860Owner::ReleaseData(bool bRelease)
{
    AutoMemContext kScope(0x10);
    if (bRelease) {
        delete m_pUserData;
        m_pUserData = 0;
    }
}

class ArgCCE;

class TargetCCE {
public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual bool Process(ArgCCE* pkArg);
};

struct LinkCCE {
    int unk00;
    int unk04;
    TargetCCE* m_pkTarget;
};

struct BodyCCE {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    LinkCCE* m_pkLink;
};

class BaseCCE {
public:
    bool Process(ArgCCE* pkArg);

    void* m_ppVirtualMethodTable;
    int unk04;
    BodyCCE* m_pkBody;
};

inline TargetCCE* GetTargetCCE(BaseCCE* pkObject)
{
    if (pkObject && pkObject->m_pkBody && pkObject->m_pkBody->m_pkLink)
        return pkObject->m_pkBody->m_pkLink->m_pkTarget;
    return 0;
}

class DerivedCCE : public BaseCCE {
public:
    bool ProcessWithTarget(ArgCCE* pkArg);
};

// @fnv 0x00cced60
bool DerivedCCE::ProcessWithTarget(ArgCCE* pkArg)
{
    bool bResult = BaseCCE::Process(pkArg);
    if (bResult) {
        TargetCCE* pkTarget = GetTargetCCE(this);
        if (pkTarget)
            return pkTarget->Process(pkArg);
    }
    return bResult;
}

__declspec(thread) unsigned int currentAllocationContext = 0x3b;

struct ThreadContextGuard
{
    unsigned int oldValue;
    ThreadContextGuard()
        : oldValue(currentAllocationContext)
    {
        currentAllocationContext = 0x10;
    }
    ~ThreadContextGuard()
    {
        currentAllocationContext = oldValue;
    }
};

struct StandinClass
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_pData;
    void* __thiscall bhkConvexSweepShape_CreateCinfo(bool* result);
};

extern float DAT_010c72bc;
extern MM g_memoryManager;

struct AllocatedBlock
{
    unsigned int unk00;
    float value04;
    unsigned int unk08;
    float value0c;
    float value10;
};

// Sets result to whether m_pData is null, allocates a 0x14-byte block with default values if so, stores it in m_pData, and returns m_pData.
// @fnv 0x00ccf680
// src: XBOX_PDB 0x00ccf680
void* StandinClass::bhkConvexSweepShape_CreateCinfo(bool* pbWasNull)
{
    ThreadContextGuard guard;
    *pbWasNull = (m_pData == 0);
    if (*pbWasNull)
    {
        MemoryManagerAllocHelper* allocator =
            reinterpret_cast<MemoryManagerAllocHelper*>(&g_memoryManager);
        AllocatedBlock* block =
            reinterpret_cast<AllocatedBlock*>(allocator->Allocate(0x14));
        if (block != 0)
        {
            block->unk00 = 0;
            block->value04 = DAT_010c72bc;
            block->unk08 = 0;
            block->value0c = 20.0f;
            block->value10 = 5.0f;
        }
        else
        {
            block = reinterpret_cast<AllocatedBlock*>(0);
        }
        m_pData = block;
    }
    return m_pData;
}

class BCCFA50Arg;

class BCCFA50Shape {
public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void VFunc64();
    virtual void VFunc68();
    virtual void VFunc6C();
    virtual void VFunc70();
    virtual void VFunc74();
    virtual void VFunc78();
    virtual void VFunc7C();
    virtual void VFunc80();
    virtual void VFunc84();
    virtual void VFunc88();
    virtual void VFunc8C();
    virtual void VFunc90();
    virtual void VFunc94();
    virtual void VFunc98();
    virtual void VFunc9C();
    virtual void VFuncA0();
    virtual void VFuncA4();
    virtual void VFuncA8();
    virtual void VFuncAC();
    virtual void VFuncB0();
    virtual void VFuncB4();
    virtual void VFuncB8();
    virtual void VFuncBC();
    virtual void VFuncC0();
    virtual void VFuncC4();
    virtual void VFuncC8();
    virtual void VFuncCC();
    virtual bool Process(BCCFA50Arg* pkArg);
};

struct BCCFA50Child {
    int unk00;
    int unk04;
    BCCFA50Shape* m_pkShape;
};

class BCCFA50Counter {
public:
    virtual void VFunc00();
    virtual int GetCount();
};

struct BCCFA50HavokList {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    BCCFA50Counter m_kCounter;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    BCCFA50Child** m_ppkChildren;
};

class BCCFA50Wrapper {
public:
    bool BaseProcess(BCCFA50Arg* pkArg);
    __forceinline BCCFA50HavokList* GetList() { return this ? m_pkList : 0; }
    bool ProcessChildren(BCCFA50Arg* pkArg);

    int unk00;
    int unk04;
    BCCFA50HavokList* m_pkList;
};

// Calls BaseProcess, then processes each child shape in the list while the result stays true, returning the combined result.
// @fnv 0x00ccfa50
bool BCCFA50Wrapper::ProcessChildren(BCCFA50Arg* pkArg)
{
    bool bResult = BaseProcess(pkArg);
    if (bResult) {
        int iCount = GetList() ? GetList()->m_kCounter.GetCount() : 0;
        for (int i = 0; bResult && i < iCount; i++) {
            BCCFA50Child* pkChild = GetList() ? GetList()->m_ppkChildren[i] : 0;
            BCCFA50Shape* pkShape = pkChild ? pkChild->m_pkShape : 0;
            if (pkShape)
                bResult &= pkShape->Process(pkArg);
        }
    }
    return bResult;
}

// Returns the lazily created settings block, creating it under the Havok allocation tag and registering it when owned.

extern __declspec(thread) int g_iCCFFD0AllocTag;

class CCFFD0MemoryManager;

extern CCFFD0MemoryManager g_kCCFFD0MemoryManager;
extern float g_fCCFFD0DefaultScale;

class CCFFD0Settings {
public:
    CCFFD0Settings()
    {
        m_pUserData = 0;
        m_fScale = g_fCCFFD0DefaultScale;
        m_pEntries = 0;
        m_iEntryCount = 0;
        m_iCapacityAndFlags = 0x80000000;
    }

    static void* operator new(unsigned int uiSize, void* pvMem) throw() { return pvMem; }

    void* m_pUserData;
    float m_fScale;
    int unk08;
    int unk0C;
    void* m_pEntries;
    int m_iEntryCount;
    int m_iCapacityAndFlags;
};

class CCFFD0Owner {
public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    CCFFD0Settings* m_pkSettings;

    void Register(CCFFD0Settings* pkSettings);
    CCFFD0Settings* GetOrCreateSettings(bool* pbCreated);
};

// Returns m_pkSettings, creating it via the memory manager and registering it with m_pkWorld when absent; sets *pbCreated accordingly.
// @fnv 0x00ccffd0
CCFFD0Settings* CCFFD0Owner::GetOrCreateSettings(bool* pbCreated)
{
    AutoMemContext kScope(0x10);
    bool bCreate = m_pkSettings == 0;
    *pbCreated = bCreate;
    if (bCreate)
    {
        m_pkSettings = new (reinterpret_cast<MemoryManager&>(g_kCCFFD0MemoryManager).Allocate(sizeof(CCFFD0Settings))) CCFFD0Settings;
        if (m_pkWorld)
            Register(m_pkSettings);
    }
    return m_pkSettings;
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkArrayBase<T>::_clearAndDeallocate(Allocator().get(this));
}

template <class T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <class T, class Allocator>
inline void hkArray<T, Allocator>::swap(hkArray& a)
{
    int s = a.m_iElementCount;
    T* d = a.m_data;
    a.m_data = m_data;
    a.m_iElementCount = m_iElementCount;
    m_data = d;
    m_iElementCount = s;
    int c = a.m_iCapacityState;
    a.m_iCapacityState = m_iCapacityState;
    m_iCapacityState = c;
}

template <class T>
inline void SaveBinaryValue(NiBinaryStream* stream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    stream->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

struct LinkedObjStub {
    int unk00;
    int unk04;
    void* m_pLinked;
};

struct CountedSub {
    virtual void v00();
    virtual int GetCount();
};

struct CountedOwner {
    int unk00; int unk04; int unk08; int unk0C; int unk10;
    CountedSub m_sub;
};

struct SavedData {
    int unk00;
    int unk04;
    char m_cUnk08;
    int m_iUnk0C;
    hkArray<LinkedObjStub*> m_ppData;
};

void bhkStream_SwapHKArray(SavedData* data, void* source, hkArray<LinkedObjStub*>* out);

inline int bhkSaveOwner_blk_00cc0000_o2::GetCount()
{
    CountedOwner* owner = m_pSharedOwner;
    return owner ? owner->m_sub.GetCount() : 0;
}

// Preserve the owner's original dispatch slots while its shared storage is opaque.
inline SavedData* GetSaveOwnerData(bhkSaveOwner_blk_00cc0000_o2* owner, bool* out)
{
    typedef SavedData* (__thiscall* GetDataFn)(bhkSaveOwner_blk_00cc0000_o2*, bool*);
    return reinterpret_cast<GetDataFn>((*reinterpret_cast<void***>(owner))[0xb4 / 4])(owner, out);
}
inline void* GetSaveOwnerSource(bhkSaveOwner_blk_00cc0000_o2* owner)
{
    typedef void* (__thiscall* GetSourceFn)(bhkSaveOwner_blk_00cc0000_o2*);
    return reinterpret_cast<GetSourceFn>((*reinterpret_cast<void***>(owner))[0xa8 / 4])(owner);
}

// @fnv 0x00cd02d0
void bhkSaveOwner_blk_00cc0000_o2::SaveLinkedObjects(NiStream* stream)
{
    bool bOut;
    SavedData* data = GetSaveOwnerData(this, &bOut);
    hkArray<LinkedObjStub*> arr;
    arr.swap(data->m_ppData);
    if (StreamField<unsigned char>(*stream, 0x1e4) != 1) {
        void* source = GetSaveOwnerSource(this);
        bhkStream_SwapHKArray(data, source, &data->m_ppData);
    }
    int count = arr.m_iElementCount;
    SaveBinaryValue(OutputStream(*stream), count);
    for (int i = 0; i < GetCount(); i++) {
        LinkedObjStub* obj = arr.m_data[i];
        stream->SaveLinkID(reinterpret_cast<const NiObject*>(obj ? obj->m_pLinked : 0));
    }
    bhkConvexShape_SaveBinary(stream);
    SaveBinaryValue(OutputStream(*stream), data->m_cUnk08);
    SaveBinaryValue(OutputStream(*stream), data->m_iUnk0C);
}


// @fnv 0x00cd9fb0
__declspec(noinline) hkArrayBase<hkQsTransform>* __fastcall ResetStates(hkaPose* pose)
{
    int iCount = pose->m_pSkeleton->m_kBones.m_iElementCount;
    for (int i = 0; i < iCount; ++i)
        pose->m_pBoneFlags[i] = 2;
    pose->m_bPoseFlag = false;
    pose->m_bPoseInitialized = true;
    return &pose->m_pLocalPose;
}

extern int DAT_0102016c;
extern int DAT_0102009c;
extern int DAT_010c9634;
extern int DAT_01268154;
extern int DAT_01268118;
extern int DAT_012685b8;

struct C200125Base
{
    void UpdateState_00c87c30();
};

struct C200125Object : C200125Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    C200125Object()
    {
        unsigned int count = 1;
        UpdateState_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_0102009c;
        DAT_01268118 += count;
        m_pVtable = &DAT_010c9634;
        DAT_012685b8 += count;
    }
};

struct C200125Owner
{
    void bhkUnaryAction_CopyMembers(C200125Object* object, unsigned int argument);
    C200125Object* bhkMotorAction_CreateClone(unsigned int argument);
};

// @fnv 0x00cc3540
// src: XBOX_PDB 0x00cc3540
C200125Object* C200125Owner::bhkMotorAction_CreateClone(unsigned int argument)
{
    TlsFlagGuard guard;
    bhkSerializable_CloneCritLock();

    C200125Object* object = new C200125Object;
    bhkUnaryAction_CopyMembers(object, argument);
    bhkSerializable_CloneCritUnlock();
    return object;
}

struct CC4560Obj
{
    void* __thiscall hkAngularDashpotActionCinfo_hkAngularDashpotActionCinfo();
};
struct CC4560Owner
{
    void* unk00;
    void* unk04;
    void* m_p;
    void* m_q;
    void __thiscall bhkAngularDashpotAction_CopyCinfo(void* p);
    void* __thiscall bhkAngularDashpotAction_CreateCinfo(bool* pbCreated);
};
// @fnv 0x00cc4560
// src: XBOX_PDB 0x00cc4560
void* __thiscall CC4560Owner::bhkAngularDashpotAction_CreateCinfo(bool* pbCreated)
{
    TlsFlagGuard guard;
    bool bEmpty = (m_q == 0);
    *pbCreated = bEmpty;
    if (bEmpty)
    {
        unsigned char* pMem = DAT_011f6238.Alloc(0x30);
        m_q = pMem ? ((CC4560Obj*)pMem)->hkAngularDashpotActionCinfo_hkAngularDashpotActionCinfo() : 0;
        if (m_p != 0)
            bhkAngularDashpotAction_CopyCinfo(m_q);
    }
    return m_q;
}

struct SaveStream;
typedef unsigned int (__cdecl *SaveStreamWriteFn)(SaveStream*, const void*, unsigned int, unsigned int*, unsigned int);

struct SaveStream {
    void* unk00;
    unsigned int m_04;
    void* unk08;
    SaveStreamWriteFn m_0c;
    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int num)
    { unsigned int r = m_0c(this, p, n, sizes, num); m_04 += r; return r; }
    unsigned int Write(const void* p, unsigned int n)
    { unsigned int cnt = n; return BinaryWrite(p, n, &cnt, 1); }
};

struct SaveCtx {
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    SaveStream* m_pBinaryStream;
};

class FUN_00cc8a10_cls {
public:
    void* unk00;
    unsigned char* m_pSub;
    void hkConstraintCinfo_SaveBinary(SaveCtx* ctx);
    void WriteSubData(int a1);
};

static inline void CC8A10Write(SaveCtx* c, void* p, unsigned int n)
{
    c->m_pBinaryStream->Write(p, n);
}
// @fnv 0x00cc8a10
void FUN_00cc8a10_cls::WriteSubData(int apCtx) {
    SaveCtx* c = (SaveCtx*)apCtx;
    unsigned char* sub = m_pSub;
    CC8A10Write(c, sub + 0x20, 0x30);
    CC8A10Write(c, sub + 0x50, 0x30);
    CC8A10Write(c, sub + 0x84, 4);
    CC8A10Write(c, sub + 0x88, 4);
    hkConstraintCinfo_SaveBinary(c);
}

// bhk wrapper LoadBinary: load the parent part, then fix up the Havok cinfo block when the
// stream's endianness differs (translation swapped inline, rotation through the shared helper).


struct CinfoX {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    Transform m_kMotionTransform;
};
void __cdecl bhkStream_Endian(Transform* pkRotation);
static inline void SwapDword(unsigned int& v) { v = _byteswap_ulong(v); }

struct bhkParentX {
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(), v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44();
    virtual CinfoX* GetCinfo(int* piSize);
    void bhkConvexShape_LoadBinary(NiStream& kStream);
};
struct bhkDerivedX : bhkParentX {
    void bhkConvexTransformShape_LoadBinary(NiStream& kStream);
};

// @fnv 0x00cceb90
// src: XBOX_PDB 0x00cceb90
void bhkDerivedX::bhkConvexTransformShape_LoadBinary(NiStream& kStream)
{
    PrepareReadStream(&kStream);
    bhkConvexShape_LoadBinary(kStream);
    int iSize;
    CinfoX* pkCinfo = GetCinfo(&iSize);
    pkCinfo->m_08 = 0;
    if (StreamField<unsigned char>(kStream, 0x1e5) != 1)
    {
        Transform* pkTransform = &pkCinfo->m_kMotionTransform;
        SwapDword(*reinterpret_cast<unsigned int*>(&pkTransform->m_f30));
        SwapDword(*reinterpret_cast<unsigned int*>(&pkTransform->m_f34));
        SwapDword(*reinterpret_cast<unsigned int*>(&pkTransform->m_f38));
        SwapDword(*reinterpret_cast<unsigned int*>(&pkTransform->m_f3c));
        bhkStream_Endian(pkTransform);
    }
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

namespace cce {
struct Block { char pad[0x30]; unsigned long m_kPointA; unsigned long m_kPointB; unsigned long m_iThirdValue; unsigned long m_iFourthElementInteger; };
void __cdecl bhkStream_Endian(Block* b);
inline void Swap32(unsigned long& v) { v = _byteswap_ulong(v); }
inline void SwapBlock(Block* b) {
    Swap32(b->m_kPointA); Swap32(b->m_kPointB); Swap32(b->m_iThirdValue); Swap32(b->m_iFourthElementInteger);
    bhkStream_Endian(b);
}
struct Hdr { char pad[0x10]; Block m_kBlock; };
struct Info { int unk; int unkCur; void* m_pName; };
struct Meta { char pad[0x18]; Info* m_pObjectInfo; };
struct Writer {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void SetName(void* p);
    char pad[0x1e4 - 4]; unsigned char m_ucMode;
};
struct Obj {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();virtual void v10();virtual void v14();virtual void v18();virtual void v1c();virtual void v20();virtual void v24();virtual void v28();virtual void v2c();virtual void v30();virtual void v34();virtual void v38();virtual void v3c();virtual void v40();virtual void v44();virtual void v48();virtual void v4c();virtual void v50();virtual void v54();virtual void v58();virtual void v5c();virtual void v60();virtual void v64();virtual void v68();virtual void v6c();virtual void v70();virtual void v74();virtual void v78();virtual void v7c();virtual void v80();virtual void v84();virtual void v88();virtual void v8c();virtual void v90();virtual void v94();virtual void v98();virtual void v9c();virtual void va();virtual void vaCur();virtual void vaValue();virtual void vac();virtual void vb();
    virtual Hdr* GetHeader(int* pSize);
    int unkCur; Meta* m_pMeta;
    void bhkConvexShape_SaveBinary(Writer* w);
    void bhkConvexTransformShape_SaveBinary(Writer* w);
};
static inline void* GetName(Obj* o) { return (o && o->m_pMeta && o->m_pMeta->m_pObjectInfo) ? o->m_pMeta->m_pObjectInfo->m_pName : 0; }
// @fnv 0x00ccec00
// src: XBOX_PDB 0x00ccec00
void Obj::bhkConvexTransformShape_SaveBinary(Writer* w)
{
    w->SetName(GetName(this));
    int iSize;
    Hdr* h = GetHeader(&iSize);
    if (w->m_ucMode != 1) SwapBlock(&h->m_kBlock);
    bhkConvexShape_SaveBinary(w);
    if (w->m_ucMode != 1) SwapBlock(&h->m_kBlock);
}
}

extern char g_vtblInst0104da28[];
extern char g_vtblInst010cb300[];

struct ContactPointPair
{
    int m_00; int m_04; int m_08; int m_0c;
    int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c;
    int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44; int m_48; int m_4c;
    int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c;
};


// hkArray<?>'s fields (m_data, m_size, m_capacityAndFlags), initialised in the body: the original stores them after the
// second vtable store, where the shared hkArray's member constructors would run before the body.
struct ContactCollectorArrayFields
{
    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapFlags;
    void Init()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapFlags = (int)0x80000000;
    }
};
struct FUN_00cd3410
{
    void* volatile m_pVtable;           // 0x00
    volatile float m_fEarlyOutDistance;  // 0x04
    int m_unk08;                        // 0x08
    int m_unk0c;                        // 0x0c
    void* m_pHits;                      // 0x10
    int m_iHitsSize;                    // 0x14
    int m_iHitsCapFlags;                // 0x18
    int m_unk1c;                        // 0x1c
    ContactPointPair m_kHits[8];               // 0x20 (8 * 112 = 0x380)
    volatile unsigned int m_3a0;        // 0x3a0
    ContactCollectorArrayFields m_a1;                   // 0x3a4
    ContactCollectorArrayFields m_a2;                   // 0x3b0
    ContactCollectorArrayFields m_a3;                   // 0x3bc

    FUN_00cd3410(unsigned int param);
};

// Initializes the object: sets vtable pointers, hit m_iCapacityState flags, hit buffer to inline storage, stores param, and inits three sub-objects.
// @fnv 0x00cd3410
FUN_00cd3410::FUN_00cd3410(unsigned int param)
{
    m_fEarlyOutDistance = 3.40282e38F;
    m_pVtable = g_vtblInst0104da28;
    m_iHitsCapFlags = 0x80000008;
    m_pHits = m_kHits;
    m_fEarlyOutDistance = 3.40282e38F;
    m_3a0 = param;
    m_pVtable = g_vtblInst010cb300;
    m_a1.Init();
    m_a2.Init();
    m_a3.Init();
    m_iHitsSize = 0;
    m_fEarlyOutDistance = 3.40282e38F;
}

inline void* operator new(unsigned int, void* p) { return p; }

extern const float runtimeFloatSettingDefault92;
extern const float runtimeFloatSettingDefault506;
extern const float g_011db1d4_arg1;
struct Defaults {
 float strength, damping, gain, recovery, maxVelocity, u14,u18,u1c,u20,u24,u28,u2c;
 Defaults() : strength(.17f),damping(0),gain(1),recovery(.6f),maxVelocity(.05f),u14(runtimeFloatSettingDefault92),u18(runtimeFloatSettingDefault506),u1c(.1f),u20(.3f),u24(.3f),u28(g_011db1d4_arg1),u2c(.1f) {}
 Defaults(int) {}
 Defaults* hkaKeyFrameHierarchyUtility_ControlData_ControlData();
};
template <class T>
static __forceinline void Array_reserve(hkArrayBase<T>& self, S_00cc4b90_Alloc& alloc,int n);

template <class T>
static __forceinline void Array_resizeUninitialized(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline void Array_resize(hkArrayBase<T>& self, int n);

template <class T>
static __forceinline void Array_resize(hkArrayBase<T>& self, int n,const T& value);

template <class T>
static __forceinline void Array_reserve(hkArrayBase<T>& self, S_00cc4b90_Alloc& alloc,int n)
{ int c=self.m_iCapacityState&0x3fffffff; if(c<n) { int doubled=c*2; hkArrayUtil__reserve(&alloc,(&self),n<doubled?doubled:n,sizeof(T)); } }

template <class T>
static __forceinline void Array_resizeUninitialized(hkArrayBase<T>& self, int n)
{ Array_reserve(self, hkMemoryRouter_getInstance()->heap(),n); self.m_iElementCount=n; }

template <class T>
static __forceinline void Array_resize(hkArrayBase<T>& self, int n)
{ Array_reserve(self, hkMemoryRouter_getInstance()->heap(),n); int delta=n-self.m_iElementCount; T* start=self.m_data+self.m_iElementCount; for(int i=0;i<delta;i++) new(start+i) T; self.m_iElementCount=n; }

template <class T>
static __forceinline void Array_resize(hkArrayBase<T>& self, int n,const T& value)
{ Array_reserve(self, hkMemoryRouter_getInstance()->heap(),n); int delta=n-self.m_iElementCount; T* start=self.m_data+self.m_iElementCount; for(int i=0;i<delta;i++) start[i]=value; self.m_iElementCount=n; }
struct Skeleton { int u00,u04,u08; short* parents; int u10,u14,u18; int count; };
struct Binding { int u00,u04; void* name; int boneCount; int u10,u14,u18,u1c; int* remapping; int u24,u28; Skeleton* skeleton; void FUN_00c90510(); };
struct PoseView { int count; void* name; short* parents; };
void __cdecl hkaKeyFrameHierarchyUtility_initialize(PoseView*,Transform*);
struct FUN_00cdb400 {
 hkArrayBase<Defaults> defaults;
 hkArrayBase<int> auxiliary;
 PoseView pose;
 int u24,u28;
 hkArrayBase<Transform> transforms;
 Binding* binding;
 hkArrayBase<short> parents;
 FUN_00cdb400(Binding* input);
};
// @fnv 0x00cdb400
FUN_00cdb400::FUN_00cdb400(Binding* pBinding):u24(0),u28(0),binding(pBinding) {
 pBinding->FUN_00c90510();
 Array_resize(defaults, 1);
 Defaults temp(0);
 defaults.m_data[0]=*temp.hkaKeyFrameHierarchyUtility_ControlData_ControlData();
 int n=pBinding->boneCount;
 if(n!=pBinding->skeleton->count) {
  Array_resize(parents, n,(short)-1);
  for(int i=0;i<pBinding->skeleton->count;i++) {
   int* pRemapping=pBinding->remapping;
   int iMappedIndex=pRemapping[i];
   if(iMappedIndex>=0) {
    int ancestor=i;
    int parent=-1;
    do { ancestor=pBinding->skeleton->parents[ancestor]; if(ancestor<0) break; parent=pRemapping[ancestor]; } while(parent<0);
    parents.m_data[iMappedIndex]=(short)parent;
   }
  }
 } else {
  Array_resize(parents, n,(short)-1);
  for(int i=0;i<pBinding->skeleton->count;i++) parents.m_data[i]=pBinding->skeleton->parents[i];
 }
 pose.count=n;pose.name=pBinding->name;pose.parents=parents.m_data;
 Array_resizeUninitialized(transforms, n);
 hkaKeyFrameHierarchyUtility_initialize(&pose,transforms.m_data);

}

class hkTargetCC01 {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void handle(void* pv);
};

class hkObjCC01 {
public:
    int unk00;
    int unk04;
    hkTargetCC01* m_target;

    void* DispatchToTarget(void* pv);
};

// @fnv 0x00cc0100
void* hkObjCC01::DispatchToTarget(void* pv)
{
    m_target->handle(pv);
    return pv;
}

extern "C" int __cdecl Vsnprintf(char* dst, int maxlen, const char* fmt, ...);
extern "C" int __cdecl hkString_strLen(const char* s);

// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(hkStreamWriter* writer, const char* str) {
    if (str) {
        writer->write(str, hkString_strLen(str));
    } else {
        writer->write("(null)", 6);
    }
}

// Formats val as a 64-bit integer into a buffer and writes the resulting string to the stream writer.
// @fnv 0x00cc0370
hkOstream* __fastcall WriteOstreamInt64(hkOstream* self, void*, __int64 val)
{
    int buf[0x2728 / sizeof(int)];
    Vsnprintf((char*)buf, sizeof(buf), "%I64i", val);
    writeString(self->m_pStreamWriter, (char*)buf);
    return self;
}

extern "C" void* DAT_010c9314;

struct OwnerManager {
    virtual void* Reserved0();
    virtual void* Reserved1();
    virtual void* Reserved2();
    virtual void* Reserved3();
    virtual void* CreateOwner(void* owner);
};

extern "C" OwnerManager* DAT_01268364;

// @fnv 0x00cc04d0
hkOstream* __fastcall InitializeOstreamOwner(hkOstream* self, void*, void* owner)
{
    self->m_sReferenceCount = 1;
    *reinterpret_cast<void**>(self) = &DAT_010c9314;
    self->m_pStreamWriter = static_cast<hkStreamWriter*>(DAT_01268364->CreateOwner(owner));
    return self;
}

struct FUN_00cc0550_VirtualObject {
    virtual void vf00();
    virtual void* vf04(int value);
};

struct FUN_00cc0550_Holder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FUN_00cc0550_VirtualObject* unk10;
};

struct FUN_00cc0550_Allocated {
    void* m_pVtable;
    unsigned short m_usField04;
    unsigned short m_usField06;
    void* m_pField08;
    int m_iField0C;
};

extern "C" void* DAT_010c933c;

// Sets the vtable and flags, allocates a 16-byte object via holder->unk10->vf04, stores value in it, and assigns it to m_pField08.
// @fnv 0x00cc0550
hkOstream* __fastcall InitializeOstreamValue(hkOstream* self, void*, int value)
{
    self->m_sReferenceCount = 1;
    *reinterpret_cast<void**>(self) = &DAT_010c9314;

    FUN_00cc0550_Holder* holder =
        reinterpret_cast<FUN_00cc0550_Holder*>(hkMemoryRouter_getInstance());
    FUN_00cc0550_Allocated* pValueBlock =
        reinterpret_cast<FUN_00cc0550_Allocated*>(holder->unk10->vf04(0x10));

    pValueBlock->m_usField04 = 0x10;
    pValueBlock->m_usField06 = 1;
    pValueBlock->m_pVtable = &DAT_010c933c;
    pValueBlock->m_pField08 = reinterpret_cast<void*>(value);
    pValueBlock->m_iField0C = 1;

    self->m_pStreamWriter = reinterpret_cast<hkStreamWriter*>(pValueBlock);
    return self;
}

struct FUN_00d46d40_s {
    const char* FUN_00d46d40();
};

FUN_00d46d40_s* __cdecl Runtime_GetDAT01268b54Address();

struct hkSourceCC08 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int v0C();
};

extern hkSourceCC08* DAT_01268b08;

struct hkObjCC08 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18(const char* name, int value);

    void hkResource_getContents_class_hkRootLevelContainer();
};

// Reads an int from DAT_01268b08 and passes it with the string from FUN_00d47f90()->FUN_00d46d40() to v18.
// @fnv 0x00cc0820
// src: HAVOK_LIB 0x00cc0820
void hkObjCC08::hkResource_getContents_class_hkRootLevelContainer()
{
    int value = DAT_01268b08->v0C();
    v18(Runtime_GetDAT01268b54Address()->FUN_00d46d40(), value);
}

struct CpuOpaque;
extern CpuOpaque DAT_01268590;
// @fnv 0x00cc1280
// src: COMMUNITY 0x00cc1280
CpuOpaque* __cdecl bhkPoseArray_GetRTTI()
{
    return &DAT_01268590;
}

struct FUN_00a5d2f0_shell {
    bool FUN_00a5d2f0(void* apStream);
};
struct FUN_00cc1310_class : FUN_00a5d2f0_shell {
    unsigned int m_uiUnk0;
    unsigned int m_uiUnk4;
    unsigned int m_uiCount;
    void* m_pData;
    bool bhkPoseArray_RegisterStreamables(void* apStream);
};
// @fnv 0x00cc1310
// src: XBOX_PDB 0x00cc1310
bool FUN_00cc1310_class::bhkPoseArray_RegisterStreamables(void* apStream)
{
    bool b = FUN_00a5d2f0(apStream);
    if (b) {
        for (unsigned int i = 0; i < m_uiCount; ++i)
            ((void (__thiscall *)(void*, void*))(*(void***)apStream)[8])(apStream, (char*)m_pData + i * 4);
    }
    return b;
}

struct Stream {
    int unk0;
    int total;
    int unk8;
    int (*io)(Stream* s, void* buf, int m_iElementCount, int* out, int n);
    void Rd(void* p) { int sz = 4; total += io(this, p, 4, &sz, 1); }
};
struct Item { unsigned int count; char** m_data; };
struct Loader {
    char pad[0x250];
    Stream* stream;
    void Read(unsigned int* p);
    void WriteObjectLink(unsigned int* p);
};
void __stdcall nullsub_3(Loader* l);
void bhkPoseArray_bhkPose_SaveBinary(Loader* l, char* p);
static inline void ReadU(Loader* l, void* p) { l->stream->Rd(p); }
struct Obj {
    int unk0, unk4;
    unsigned int count1;
    unsigned int* arr1;
    unsigned int count2;
    Item** arr2;
    void ReadFromStream(Loader* l);
};
// @fnv 0x00cc1610
void Obj::ReadFromStream(Loader* pLoader)
{
    nullsub_3(pLoader);
    ReadU(pLoader, &count1);
    for (unsigned int i = 0; i < count1; i++)
        pLoader->WriteObjectLink(&arr1[i]);
    ReadU(pLoader, &count2);
    for (unsigned int i = 0; i < count2; i++) {
        Item* it = arr2[i];
        ReadU(pLoader, it);
        for (unsigned int j = 0; j < it->count; j++)
            bhkPoseArray_bhkPose_SaveBinary(pLoader, (char*)it->m_data + j * 0x30);
    }
}

void __cdecl FUN_00a5d430(void);

// @fnv 0x00cc1960
// src: XBOX_PDB 0x00cc1960
void __cdecl bhkExtraData_ProcessClone(void)
{
    FUN_00a5d430();
}

struct RefObjC {
    virtual ~RefObjC();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount() { InterlockedIncrement(&m_uiRefCount); }
    void DecRefCount() { if (InterlockedDecrement(&m_uiRefCount) == 0) DeleteThis(); }
};

template <class T, class TAlloc> inline __declspec(noinline) void NiTLargeArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_uiSize) {
            m_uiSize = uiIndex + 1;
            if (element.m_pObject)
                m_uiESize++;
        } else {
            if (element.m_pObject) {
                if (!m_pBase[uiIndex].m_pObject)
                    m_uiESize++;
            } else {
                if (m_pBase[uiIndex].m_pObject)
                    m_uiESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
template <class T, class TAlloc> inline unsigned int NiTLargeArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
        if (uiIndex >= m_uiMaxSize)
            SetSize(uiIndex + m_uiGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
template <class T, class TAlloc> inline unsigned int NiTLargeArray<T, TAlloc>::Add(const T& element)
{ return SetAtGrow(m_uiSize, element); }

struct OwnerC {
    int unk00, unk04, unk08;
    NiTLargeArray<NiPointer<RefObjC> , NiTMallocInterface<NiPointer<RefObjC>> > m_kArray;
    void AddRefObject(RefObjC* pkObject);
};

// If pkObject is non-null, appends it to m_kArray.
// @fnv 0x00cc2080
void OwnerC::AddRefObject(RefObjC* pkObject)
{
    if (pkObject)
        m_kArray.Add(pkObject);
}

void __cdecl hkConstraintCinfo_GetViewerStrings();

// @fnv 0x00cc5080
// src: XBOX_PDB 0x00cc5080
void __cdecl hkBallAndSocketConstraintCinfo_GetViewerStrings() {
    hkConstraintCinfo_GetViewerStrings();
}

struct S_54d0_Poly {
    void* m_pVtable;
};

struct S_54d0_Child {
    void* m_pUnk00;

    S_54d0_Child() {}
};

struct S_54d0_Heap {
    void* Allocate(unsigned int uiSize);
};

extern S_54d0_Heap g_54d0Heap;
extern int DAT_010c9af0;

struct S_54d0_Node : S_54d0_Poly, S_54d0_Child {
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;

    static void* operator new(unsigned int uiSize) { return g_54d0Heap.Allocate(uiSize); }

    S_54d0_Node() {
        S_54d0_Child* pkSelf = this;
        m_uiRefCount = 1;
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_pVtable = (void*)&DAT_010c9af0;
        pkSelf->m_pUnk00 = 0;
    }
};

struct S_54d0_Owner {
    void* m_pUnk00;
    void* m_pUnk04;
    void* m_pUnk08;
    S_54d0_Child* m_pData;

    void Attach(unsigned int uiNode);
    S_54d0_Child* __thiscall bhkWheelConstraint_CreateCinfo(bool* pbCreated);
};

// Sets *pbCreated to whether m_pData is null, allocates a new S_54d0_Node when it is, attaches it if m_pUnk08 is set, and returns m_pData.
// @fnv 0x00cc54d0
// src: XBOX_PDB 0x00cc54d0
S_54d0_Child* __thiscall S_54d0_Owner::bhkWheelConstraint_CreateCinfo(bool* pbCreated) {
    SerializationMemoryContext kCtx;

    *pbCreated = (m_pData == 0);

    if (*pbCreated) {
        m_pData = new S_54d0_Node();

        if (m_pUnk08 != 0) {
            Attach((unsigned int)(S_54d0_Node*)m_pData);
        }
    }

    return m_pData;
}

struct CC7970_RefData { unsigned int m_uiFilterValue; };
struct CC7970_RefObject {
    void* m_pVtable;
    CC7970_RefData m_data;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiReserved;
};
static __forceinline CC7970_RefData* CC7970_CreateReference() {
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<MemoryManager*>(&DAT_011f6238)->Allocate(sizeof(CC7970_RefObject)));
    if (object) {
        CC7970_RefData* m_data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c9d60;
        m_data->m_uiFilterValue = 0;
        return m_data;
    }
    return 0;
}
struct CC7970_Owner {
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    void __thiscall CopyFromSource(CC7970_RefObject* object);
    CC7970_RefData* __thiscall GetOrCreateRefData(bool* created);
};
// @fnv 0x00cc7970
CC7970_RefData* CC7970_Owner::GetOrCreateRefData(bool* created) {
    TlsFlagGuard tlsGuard;
    *created = (m_pData == 0);
    if (*created) {
        CC7970_RefData* m_data = CC7970_CreateReference();
        m_pData = m_data;
        if (m_flag08) {
            CopyFromSource(m_data ? reinterpret_cast<CC7970_RefObject*>(reinterpret_cast<char*>(m_data) - 4) : 0);
        }
    }
    return m_pData;
}

void hkGenericConstraintCinfo_LoadBinary();

// @fnv 0x00cc7ce0
// src: XBOX_PDB 0x00cc7ce0
void hkFixedConstraintCinfo_LoadBinary() {
    hkGenericConstraintCinfo_LoadBinary();
}

void __cdecl hkGenericConstraintCinfo_SaveBinary();

// @fnv 0x00cc7cf0
// src: XBOX_PDB 0x00cc7cf0
void __cdecl hkFixedConstraintCinfo_SaveBinary()
{
    hkGenericConstraintCinfo_SaveBinary();
}

void* Object_DispatchCommandFour(unsigned int);
void FUN_00aa1460(void*,unsigned int);
extern int DAT_01268188;
extern int DAT_01268f74;
extern int DAT_01268624;
inline bhkConstraint::bhkConstraint() : m_iThirdValue(0) { ++DAT_01268188; }
inline bhkGenericConstraint::bhkGenericConstraint() { ++DAT_01268f74; }
inline bhkFixedConstraint::bhkFixedConstraint() { ++DAT_01268624; }
// Allocates and constructs a new bhkFixedConstraint object and returns it.
// @fnv 0x00cc7e70
bhkFixedConstraint* CreateFixedConstraint() { return new bhkFixedConstraint; }

struct FUN_00d53d90 : hkReferencedObject {
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    FUN_00d53d90();
};
struct S_00cc9020_Cls {
    int unk00;
    FUN_00d53d90* m_object;
    int __thiscall EnsureObject();
};
// Constructs a 16-byte context, allocates a FUN_00d53d90 into m_object if null, and returns 52.
// @fnv 0x00cc9020
int S_00cc9020_Cls::EnsureObject()
{
    S_00cc4b90_Ctx m_uiMemoryContext(16);
    if (!m_object)
        m_object = new FUN_00d53d90();
    return 52;
}

void __cdecl bhkBvTreeShape_LinkObject();

// @fnv 0x00cc9cd0
// src: XBOX_PDB 0x00cc9cd0
void __cdecl bhkMoppBvTreeShape_LinkObject()
{
    bhkBvTreeShape_LinkObject();
}

// Forward declaration of the target function
void __cdecl bhkBvTreeShape_RegisterStreamables();

// Tail call wrapper - jumps to FUN_00ca4f40
// @fnv 0x00cc9ce0
// src: XBOX_PDB 0x00cc9ce0
void __cdecl bhkMoppBvTreeShape_RegisterStreamables() {
    bhkBvTreeShape_RegisterStreamables();
}

void __cdecl bhkBvTreeShape_IsEqual();
// @fnv 0x00cc9cf0
// src: XBOX_PDB 0x00cc9cf0
void __cdecl bhkMoppBvTreeShape_IsEqual()
{
    bhkBvTreeShape_IsEqual();
}

namespace fnv_00cca2a0 {
inline void* __cdecl operator new(unsigned int, void* place) { return place; }

struct Allocator {
    void* __thiscall Game_DoHeapAlloc(unsigned int bytes);
};
extern "C" Allocator DAT_011f6238;
extern __declspec(thread) int g_threadMemoryMode;
struct ScopedMemoryMode {
    int previous;
    ScopedMemoryMode() : previous(g_threadMemoryMode) { g_threadMemoryMode = 16; }
    ~ScopedMemoryMode() { g_threadMemoryMode = previous; }
};
struct FUN_00cca2a0_class {
    void* m_ppVirtualMethodTable;
    void* m_object;
    void* m_parent;
    ::Vec4* m_vec;
    void __thiscall SetRatioFromValues(Vec4* vec);
    Vec4* __thiscall GetOrCreateVec(bool* created);
};
// @fnv 0x00cca2a0
Vec4* FUN_00cca2a0_class::GetOrCreateVec(bool* created) {
    ScopedMemoryMode memoryMode;
    *created = (m_vec == 0);
    if (*created) {
        ::Vec4 initial;
        initial.xb = 0;
        initial.yb = 0;
        initial.zb = 0;
        initial.w = 1.0f;
        ::Vec4* vec = new (DAT_011f6238.Game_DoHeapAlloc(sizeof(::Vec4))) ::Vec4(initial);
        m_vec = vec;
        if (m_parent)
            SetRatioFromValues(vec);
    }
    return m_vec;
}
}  // namespace fnv_00cca2a0

struct FUN_00cce5e0_class {
    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
    FUN_00cce5e0_class* __thiscall Construct();
};
// @fnv 0x00cce5e0
FUN_00cce5e0_class* __thiscall FUN_00cce5e0_class::Construct()
{
    m_pVtable = 0;
    m_uiRefCount = 0;
    m_uiValue1 = 0x80000000;
    m_uiData1 = 0;
    m_uiData2 = 0;
    m_uiData3 = 0x80000000;
    return this;
}

struct Cls00ccf5a0 {
    void bhkShape_LinkObject(int a);
    void bhkConvexSweepShape_LinkObject(int a);
};

// @fnv 0x00ccf5a0
// src: XBOX_PDB 0x00ccf5a0
void Cls00ccf5a0::bhkConvexSweepShape_LinkObject(int a) {
    bhkShape_LinkObject(a);
}

void __cdecl hkArrayUtil__reserve(void* alloc, void* arr, int cap, int elemSize);
struct FE50Router { int m0, m4, m8, mc; void* m10; };
struct FE50Iter {
    virtual void v00();
    virtual unsigned int GetCount();
    virtual void* GetFirst();
    virtual void* GetNext(void* it);
};
struct FE50Hk {
    char pad00[0x14];
    FE50Iter m_kIter;
    float m18;
    char pad1c[0x28];
    void** m44;
    bool hkpConvexListShape_getUseCachedAabb();
};
struct FE50Arr { void** m_data; int m_iElementCount; int m_iCapacityState; };
struct FE50Out {
    int m0, m4;
    unsigned char m8;
    float mc;
    hkArrayBase<void*> m10;
};
struct FE50Wrap {
    int m0, m4;
    FE50Hk* m8;
    void bhkConvexShape_CopyCinfo(FE50Out* out);
    float GetF() { if (this && m8) return m8->m18; return 0.0f; }
    int GetB() { if (this && m8) return m8->hkpConvexListShape_getUseCachedAabb(); return 0; }
    unsigned int GetCount() { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetCount(); if (0) return m8->m_kIter.GetCount(); return 0; }
    void* GetFirst() { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetFirst(); if (0) return m8->m_kIter.GetFirst(); return 0; }
    void* GetNext(void* it) { FE50Hk* p; if (this && (p = m8) != 0) return p->m_kIter.GetNext(it); if (0) return m8->m_kIter.GetNext(it); return 0; }
    void* GetAt(unsigned int i) { if (this && m8) return m8->m44[i]; return 0; }
    void FillOutput(FE50Out* out);
};
// Calls FUN_00c9fb70, then fills out with GetF, GetB, and copies GetCount elements from GetAt into out->m10.
// @fnv 0x00ccfe50
void FE50Wrap::FillOutput(FE50Out* out)
{
    TlsHeapGuard kGuard;
    bhkConvexShape_CopyCinfo(out);
    out->mc = GetF();
    out->m8 = GetB();
    unsigned int n = GetCount();
    out->m10.m_iElementCount = 0;
    Array_resizeUninitialized(out->m10, n);
    void* it = GetFirst();
    for (unsigned int i = 0; i < n; i++) {
        out->m10.m_data[i] = GetAt(i);
        it = GetNext(it);
    }
}

template <class T> inline void AGLoadBinary(NiBinaryStream& kStream, T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&value, uiSize, &uiSize, 1);
}

struct AGOwner : bhkSaveOwner_blk_00cc0000_o2 {
    void bhkConvexShape_LoadBinary(NiStream* stream);
    void LoadSavedData(NiStream* stream);
};

// @fnv 0x00cd00a0
void AGOwner::LoadSavedData(NiStream* stream)
{
    PrepareOtherReadStream(stream);
    bhkConvexShape_LoadBinary(stream);
    bool bFlag;
    SavedData* data = GetSaveOwnerData(this, &bFlag);
    if (StreamField<unsigned char>(*stream, 0x1e5) != 1)
        { void* src = GetSaveOwnerSource(this); bhkStream_SwapHKArray(data, src, &data->m_ppData); }
    AGLoadBinary(*(NiBinaryStream*)InputStream(*stream), data->m_cUnk08);
    AGLoadBinary(*(NiBinaryStream*)InputStream(*stream), data->m_iUnk0C);
    if (StreamField<unsigned char>(*stream, 0x1e5) != 1)
        { void* src = GetSaveOwnerSource(this); bhkStream_SwapHKArray(data, src, &data->m_ppData); }
}

struct FnvCpu_FUN_00cd0cf0_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char value;
    void SetValue(unsigned char arg0);
};
// @fnv 0x00cd0cf0
// src: GUESS 0x00cd0cf0 (confidence: low)
void FnvCpu_FUN_00cd0cf0_CpuObject::SetValue(unsigned char arg0)
{
    value = arg0;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void* pkSection);

struct hkWorldCD29 {
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    void* m_pWorldLock;
};

class hkWorldObjectCD29 {
public:
    int unk00;
    int unk04;
    hkWorldCD29* m_pOwningWorld;

    void LockWorldCriticalSection(int iUnused);
};

// @fnv 0x00cd2940
void hkWorldObjectCD29::LockWorldCriticalSection(int iUnused)
{
    if (m_pOwningWorld && m_pOwningWorld->m_pWorldLock)
        EnterCriticalSection(m_pOwningWorld->m_pWorldLock);
}

extern void (__stdcall *DAT_00fdf100)(int*);
struct B { char pad[0xc4]; int* f; };
struct A { int unk0; int unk4; B* b; void ProcessState_00cd2960(int a); };
// @fnv 0x00cd2960
// src: GUESS 0x00cd2960 (confidence: low)
void A::ProcessState_00cd2960(int a) {
    if (b) { if (b->f) DAT_00fdf100(b->f); }
}

// 0x00cd2980  bare ret
// @fnv 0x00cd2980
// src: GUESS 0x00cd2980 (confidence: high)
void Object_DoNothing_00cd2980() {
}

// 0x00cd2990  bare ret
// @fnv 0x00cd2990
// src: GUESS 0x00cd2990 (confidence: high)
void Runtime_DoNothing_00cd2990() {
}

// @fnv 0x00cd29a0
// src: GUESS 0x00cd29a0 (confidence: high)
void __cdecl Object_DoNothing_00cd29a0()
{
}

// @fnv 0x00cd29b0
// src: GUESS 0x00cd29b0 (confidence: low)
int __fastcall Object_EvaluateValue_00cd29b0(char* self, int)
{
    return *reinterpret_cast<int*>(self + 0x84);
}

struct FUN_00cd29f0_cls {
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    unsigned int unk88;
    void __thiscall hkpWorldObject_setTreeData(unsigned int v);
};

// @fnv 0x00cd29f0
// src: HAVOK_LIB 0x00cd29f0
void __thiscall FUN_00cd29f0_cls::hkpWorldObject_setTreeData(unsigned int v)
{
    unk88 = v;
}

struct FnvCpu_FUN_00cd2a00_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    int value;
    int GetValue_00cd2a00();
};
// @fnv 0x00cd2a00
// src: GUESS 0x00cd2a00 (confidence: high)
int FnvCpu_FUN_00cd2a00_CpuObject::GetValue_00cd2a00()
{
    return value;
}

struct hkPairCD2A {
    int m_kPointA;
    int m_kPointB;
};

// 0x00cd2a10 is hkpWorldObject::editProperty: its entries have a key and an eight-byte value (16 bytes, not hkEntry's 12).
struct WorldObjectPropertyEntry {
    int m_key;
    int m_04;
    hkPairCD2A m_uiFilterValue;
};

class hkObjCD2A {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74;
    WorldObjectPropertyEntry* m_entries;
    int m_iNumberOfEntries;

    void SetEntryValue(int iKey, hkPairCD2A kValue, int iUnused);
};

// @fnv 0x00cd2a10
void hkObjCD2A::SetEntryValue(int iKey, hkPairCD2A kValue, int iUnused)
{
    for (int i = 0; i < m_iNumberOfEntries; i++)
    {
        if (m_entries[i].m_key == iKey)
        {
            m_entries[i].m_uiFilterValue = kValue;
            return;
        }
    }
}

// @fnv 0x00cd3b10
// src: COMMUNITY 0x00cd3b10
void __stdcall nullsub_37(int, int, int, int) {
}

// @fnv 0x00cd7d10
// src: GUESS 0x00cd7d10 (confidence: high)
int __stdcall Runtime_ReturnConstant_112(int arg0, int arg1)
{
    return 112;
}

struct FUN_00cdb3c0_class {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* __thiscall GetUnk38_00cdb3c0();
};

// @fnv 0x00cdb3c0
// src: GUESS 0x00cdb3c0 (confidence: low)
void* FUN_00cdb3c0_class::GetUnk38_00cdb3c0()
{
    return unk38;
}

extern "C" void* __cdecl fnv_zlib_memset(void* dest, int val, unsigned int count) throw();

void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize) throw();
void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int newCapacity, int elementSize) throw();
template <typename T> inline void ConstructWithCopy(T* p, int n, const T& t) { for (int i = 0; i < n; i++) p[i] = t; }

template <class T>
static __forceinline void MyArray_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator* alloc, int n) throw();

template <class T>
static __forceinline void MyArray_SetSizeAndGrow(hkArrayBase<T>& self, int n, T fill) throw();

template <class T>
static __forceinline void MyArray_AddBack(hkArrayBase<T>& self, const T& val) throw();

template <class T>
static __forceinline void MyArray_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void MyArray_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator* alloc, int n) throw()
{
        int cap = self.getCapacity();
        if (cap < n) {
            int cap2 = cap * 2;
            int newCap = n < cap2 ? cap2 : n;
            hkArrayUtil__reserve(alloc, (&self), newCap, sizeof(T));
        }
    }

template <class T>
static __forceinline void MyArray_SetSizeAndGrow(hkArrayBase<T>& self, int n, T fill) throw()
{
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        MyArray_GrowArrayCapacity(self, router->m_heap, n);
        ConstructWithCopy<T>(self.m_data + self.m_iElementCount, n - self.m_iElementCount, fill);
        self.m_iElementCount = n;
    }

template <class T>
static __forceinline void MyArray_AddBack(hkArrayBase<T>& self, const T& val) throw()
{
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        if (self.m_iElementCount == self.getCapacity()) {
            ResizeAudioStream(router->m_heap, (&self), sizeof(T));
        }
        ConstructWithCopy<T>(self.m_data + self.m_iElementCount, 1, val);
        self.m_iElementCount++;
    }

template <class T>
static __forceinline void MyArray_destroy(hkArrayBase<T>& self) throw()
{
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkMemoryAllocator* alloc = router->m_heap;
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & hkArrayBase<T>::DONT_DEALLOCATE_FLAG) == 0) {
            alloc->bufFree(self.m_data, self.m_iCapacityState & 0x3fffffff);
        }
    }

struct MyArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { MyArray_destroy(self); }
};

template <> __forceinline hkArray<char, MyArrayPolicy>::~hkArray() { MyArrayPolicy::destroy(*this); }
template <> __forceinline hkArray<short, MyArrayPolicy>::~hkArray() { MyArrayPolicy::destroy(*this); }


template <typename T>
struct MyLocalArray : public hkArray<T, MyArrayPolicy> {
    void* m_initialStack;

    __forceinline MyLocalArray(int capacity) throw() {
        hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        int numBytes = capacity * sizeof(T);
        int aligned = (numBytes + 0x7f) & ~0x7f;
        void* p = (void*)router->m_stack.m_next.m_storage;
        router->m_stack.m_next.m_storage = (void*)((int)((char*)p + aligned));
        this->m_iCapacityState = capacity | hkArray<T, MyArrayPolicy>::DONT_DEALLOCATE_FLAG;
        this->m_data = (T*)p;
        this->m_initialStack = p;
    }

    __forceinline ~MyLocalArray() throw() {
        void* p = m_initialStack;
        if (p == this->m_data) {
            this->m_iElementCount = 0;
        }
        ((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_stack.m_next.m_storage = (void*)((int)p);
    }
};

struct SomeFilter {
    int unk00;
    int unk04;
    int unk08;
    const unsigned short* unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

// Marks entries referenced by filter->unk0c in a temporary byte array, then appends every unmarked index below filter->unk1c to out.
// @fnv 0x00cde5e0
void __cdecl CollectUnusedIndices(SomeFilter* filter, hkArray<short, MyArrayPolicy>& out) throw() {
    MyLocalArray<char> array(filter->unk1c);
    MyArray_SetSizeAndGrow<char>(array, filter->unk1c, 0);

    int i = 0;
    while (i < filter->unk10) {
        short val = (short)filter->unk0c[i];
        if (val != -1) {
            array.m_data[val] = 1;
        }
        i++;
    }

    for (short i = 0; i < filter->unk1c; i++) {
        if (array.m_data[i] == 0) {
            MyArray_AddBack(out, i);
        }
    }
}

struct FUN_00cdea20_cls {
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int m_e0;

    int hkpRagdollConstraintData_getTwistMotor() const;
};

// @fnv 0x00cdea20
// src: COMMUNITY 0x00cdea20
int FUN_00cdea20_cls::hkpRagdollConstraintData_getTwistMotor() const
{
    return m_e0;
}

struct CC0280Stream {
    virtual void Write(const char* str, int len);
};

int hkString_strLen(int);

// src: HAVOK_LIB 0x00cc0080
static void __declspec(noinline) writeString(CC0280Stream* s, const char* str)
{
    if (str == 0) {
        s->Write("(null)", 6);
        return;
    }
    s->Write(str, hkString_strLen((int)str));
}

// Writes the string "true" or "false" to the underlying stream based on the input boolean value and returns this.
// @fnv 0x00cc0170
hkOstream* __fastcall WriteOstreamBool(hkOstream* self, void*, bool abValue)
{
    writeString((CC0280Stream*)self->m_pStreamWriter, abValue ? "true" : "false");
    return self;
}

int __cdecl hkString_strLen(int);
int __cdecl Vsnprintf(char*, unsigned int, const char*, ...);

struct WriterObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void Write(const char* s, int len);
};

// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(WriterObj* obj, const char* str)
{
    if (!str)
        obj->Write("(null)", 6);
    else
        obj->Write(str, hkString_strLen((int)str));
}

// Formats the short parameter v as a decimal integer into a local buffer and writes it to m_obj via FUN_00cc0080, returning this.
// @fnv 0x00cc01e0
hkOstream* __fastcall WriteOstreamShort(hkOstream* self, void*, short asValue)
{
    int buf[2506];
    Vsnprintf((char*)buf, 0x2728, "%i", asValue);
    writeString(reinterpret_cast<WriterObj*>(self->m_pStreamWriter), (char*)buf);
    return self;
}

struct Param4 { int value; };
struct D274C0Child {
void* m_ppVirtualMethodTable;unsigned short m_memorySize;unsigned short m_sReferenceCount;int unk08,unk0c,unk10,unk14,unk18;
D274C0Child* __thiscall FUN_00d274c0(int first,int second,Param4 third);
};

// Initializes the object, allocates a 28-byte child atom block, and constructs it with the given arguments.
// @fnv 0x00cc0500
hkOstream* __fastcall InitializeOstreamAtom(hkOstream* self, void*, int first,int second,Param4 third)
{
self->m_sReferenceCount=1;*reinterpret_cast<void**>(self)=&DAT_010c9314;
D274C0Child* child=static_cast<D274C0Child*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(28));
child->m_memorySize=28;
self->m_pStreamWriter=reinterpret_cast<hkStreamWriter*>(child->FUN_00d274c0(first,second,third));
return self;
}

struct S00cc0850_Entry {
    void* __thiscall hkResource_getContents_class_hkRootLevelContainer();
};

struct S00cc0850_Registry {
    void* __thiscall FUN_00d46d40(int flags);
};

struct S00cc0850_Slot {
    void* __thiscall FindByName(void* key);
    void* __thiscall ProcessEntries_00d48150(const char* name, int flags);
};

void* __cdecl hkSerializeUtil_load(int owner, int a, int b);
extern int DAT_01268b9c;
extern const char str_010c93d0[];
extern const char str_010c93c0[];

// Looks up a key, then two named entries, on an object obtained from owner; on success stores that object in result and returns the found item, else 0.
// @fnv 0x00cc0850
// src: HAVOK_LIB 0x00cc0850
int __cdecl hkpHavokSnapshot_load(int owner, int* apEntry)
{
    if (owner == 0 || apEntry == 0)
        return 0;

    void* entry = hkSerializeUtil_load(owner, 0, 0);
    if (entry != 0) {
        S00cc0850_Slot* slot = reinterpret_cast<S00cc0850_Slot*>(
            reinterpret_cast<S00cc0850_Entry*>(entry)->hkResource_getContents_class_hkRootLevelContainer());
        if (slot != 0) {
            void* key = reinterpret_cast<S00cc0850_Registry*>(&DAT_01268b9c)->FUN_00d46d40(0);
            void* found = slot->FindByName(key);
            if (found == 0) {
                const char* names[3];
                names[0] = str_010c93d0;
                names[1] = str_010c93c0;
                names[2] = 0;
                for (int i = 0; names[i] != 0; ++i) {
                    found = slot->ProcessEntries_00d48150(names[i], 0);
                    if (found != 0)
                        break;
                }
            }
            if (found != 0) {
                *apEntry = reinterpret_cast<int>(entry);
                return reinterpret_cast<int>(found);
            }
        }
    }

    return 0;
}

extern "C" void __stdcall FUN_00ec5fce(void*, unsigned int, unsigned int, const void*);
extern "C" void FUN_004381b0();
struct FUN_00a5d3d0 {
    virtual void dummy();
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    ~FUN_00a5d3d0();
};
struct FUN_00cc1520 : FUN_00a5d3d0 {
    virtual void dummy();
    char* m_pName;
    unsigned int m_uiCount;
    void** m_pEntryData;
    ~FUN_00cc1520();
};
// Frees the name buffer, each entry in m_pEntryData, and the entry array itself under the TLS block guard.
// @fnv 0x00cc1520
FUN_00cc1520::~FUN_00cc1520() {
    {
        TlsGuard_t guard(g_tlsBlock.m_2b4);
        if (m_pName) {
            char* header = m_pName - 4;
            FUN_00ec5fce(m_pName, 4, *reinterpret_cast<unsigned int*>(header), &FUN_004381b0);
            g_memoryManager.Deallocate(header);
        }
        if (m_pEntryData) {
            for (unsigned int i = 0; i < m_uiCount; ++i) {
                void* item = m_pEntryData[i];
                if (item)
                    g_memoryManager.Deallocate(item);
            }
            void** releaseArray = m_pEntryData;
            g_memoryManager.Deallocate(releaseArray);
        }
    }
}

extern int DAT_01268188;
extern int DAT_012685f4;
extern int DAT_0108febc;
extern int DAT_010c52bc;
extern __declspec(thread) int g_ThreadData;
extern void* __cdecl Object_DispatchCommandFour(unsigned int bytes);
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
void __cdecl MemoryManager_Deallocate(void* p);

struct S_00cc5b90_Node
{
    int* vtable;
    int data04;
    int data08;
    int data0c;
    void __thiscall UpdateState_00c87c30();
};
struct S_00cc5b90_Scope
{
    volatile int savedState;
    S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(
            reinterpret_cast<char*>(&g_ThreadData) + 0x2b4);
        savedState = *currentState;
        *currentState = 16;
    }
    __forceinline ~S_00cc5b90_Scope()
    {
        int* currentState = reinterpret_cast<int*>(
            reinterpret_cast<char*>(&g_ThreadData) + 0x2b4);
        *currentState = savedState;
    }
};
struct S_00cc5b90_PendingAllocation
{
    S_00cc5b90_Node* object;
    explicit S_00cc5b90_PendingAllocation(S_00cc5b90_Node* p) : object(p) {}
    __forceinline ~S_00cc5b90_PendingAllocation() { if (object) MemoryManager_Deallocate(object); }
    void Transfer() { object = 0; }
};
struct S_00cc5b90_Owner
{
    void __thiscall bhkConstraint_CopyMembers(S_00cc5b90_Node*, int);
    S_00cc5b90_Node* __thiscall AllocateNode(int arg);
};
// Allocates and initializes a 16-byte S_00cc5b90_Node, passes it and arg to FUN_00c89730, and returns it (null if the allocation failed).
// @fnv 0x00cc5b90
S_00cc5b90_Node* __thiscall S_00cc5b90_Owner::AllocateNode(int arg)
{
    S_00cc5b90_Scope scope;
    bhkSerializable_CloneCritLock();
    S_00cc5b90_Node* result;
    {
        S_00cc5b90_PendingAllocation allocation(static_cast<S_00cc5b90_Node*>(Object_DispatchCommandFour(16)));
        S_00cc5b90_Node* pRawNode = allocation.object;
        if (pRawNode)
        {
            pRawNode->UpdateState_00c87c30();
            pRawNode->vtable = &DAT_0108febc;
            pRawNode->data0c = 0;
            ++DAT_01268188;
            pRawNode->vtable = &DAT_010c52bc;
            ++DAT_012685f4;
            result = pRawNode;
        }
        else
        {
            result = 0;
        }
        allocation.Transfer();
    }
    bhkConstraint_CopyMembers(result, arg);
    bhkSerializable_CloneCritUnlock();
    return result;
}

struct SaveBody {
 unsigned int field000;
 unsigned int field004;
 unsigned int field008;
 unsigned int field00c;
 unsigned int field010;
 unsigned int field014;
 unsigned int field018;
 unsigned int field01c;
 Transform transform;
 Transform inverse;
 unsigned short flags;unsigned char enabled;unsigned char unk0a3;
 unsigned int field0a4;
 unsigned int field0a8;
 unsigned int field0ac;
 unsigned int field0b0;
 unsigned int field0b4;
 unsigned int field0b8;
 unsigned int field0bc;
 unsigned int field0c0;
 unsigned int field0c4;
 unsigned int field0c8;
 unsigned int field0cc;
 unsigned int field0d0;
 unsigned int field0d4;
 unsigned int field0d8;
 unsigned int field0dc;
 unsigned int field0e0;
 unsigned int field0e4;
 unsigned int field0e8;
 unsigned int field0ec;
 unsigned int field0f0;
 unsigned int field0f4;
 unsigned int field0f8;
 unsigned int field0fc;
 unsigned int field100;
 unsigned int field104;
 unsigned int field108;
 unsigned int field10c;
 unsigned int field110;
 unsigned int field114;
 unsigned int field118;
 unsigned int field11c;
 unsigned int field120;
 unsigned int field124;
 unsigned int field128;
 unsigned int field12c;
 unsigned int field130;
};
struct SaveObject {
 int unk00;SaveBody* body;
 void hkConstraintCinfo_SaveBinary(SaveCtx*);
 void SaveShape(unsigned int,SaveCtx*);
 void hkRagdollConstraintCinfo_SaveBinary(SaveCtx*);
};
// Calls FUN_00c8a280, writes transform, inverse and six more body fields to the stream, saves the shape, and writes enabled if field0e0 is nonzero.
// @fnv 0x00cc6ef0
// src: XBOX_PDB 0x00cc6ef0
void SaveObject::hkRagdollConstraintCinfo_SaveBinary(SaveCtx* stream) {
 hkConstraintCinfo_SaveBinary(stream);
 SaveBody* data=body;
 stream->m_pBinaryStream->Write(&data->transform,64);
 stream->m_pBinaryStream->Write(&data->inverse,64);
 stream->m_pBinaryStream->Write(&data->field11c,4);
 stream->m_pBinaryStream->Write(&data->field12c,4);
 stream->m_pBinaryStream->Write(&data->field130,4);
 stream->m_pBinaryStream->Write(&data->field104,4);
 stream->m_pBinaryStream->Write(&data->field108,4);
 stream->m_pBinaryStream->Write(&data->field0f8,4);
 SaveShape(data->field0e0,stream);
 if(data->field0e0)stream->m_pBinaryStream->Write(&data->enabled,1);
}

extern int DAT_0108febc; extern int DAT_010c9e5c; extern int DAT_010c9d7c;
extern int DAT_01268188; extern int DAT_01268f74; extern int DAT_01268624;
void bhkSerializable_CloneCritLock(); void bhkSerializable_CloneCritUnlock() throw();
void* Object_DispatchCommandFour(unsigned int size);
struct ThreadHeapContext { unsigned int m_allocationTag; };
extern __declspec(thread) ThreadHeapContext g_threadHeapContext;
struct PhysicsNode {
    void* m_ppVirtualMethodTable; unsigned int m_sReferenceCount; unsigned int m_flags; unsigned int m_data;
    void UpdateState_00c87c30();
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
    PhysicsNode() {
        UpdateState_00c87c30(); m_ppVirtualMethodTable = &DAT_0108febc;
        unsigned int increment = 1; m_data = 0;
        DAT_01268188 += increment; m_ppVirtualMethodTable = &DAT_010c9e5c;
        DAT_01268f74 += increment; m_ppVirtualMethodTable = &DAT_010c9d7c; DAT_01268624 += increment;
    }
};
struct AllocationScope {
    unsigned int m_previousTag;
    AllocationScope() {
        m_previousTag = g_threadHeapContext.m_allocationTag;
        g_threadHeapContext.m_allocationTag = 16;
    }
    __forceinline ~AllocationScope() throw() {
        bhkSerializable_CloneCritUnlock();
        g_threadHeapContext.m_allocationTag = m_previousTag;
    }
};
struct PhysicsWorld { void bhkConstraint_CopyMembers(PhysicsNode*, bool); PhysicsNode* CreateNode(bool); };
// Constructs a PhysicsNode under an allocation scope, passes it and the flag to FUN_00c89730, and returns the node.
// @fnv 0x00cc80d0
PhysicsNode* PhysicsWorld::CreateNode(bool argument) {
    AllocationScope scope;
    bhkSerializable_CloneCritLock();
    PhysicsNode* node = new PhysicsNode;
    bhkConstraint_CopyMembers(node, argument);
    return node;
}

namespace fnv_00cc8cd0 {
extern void hkBallAndSocketConstraintCinfo_GetViewerStrings();

// @fnv 0x00cc8cd0
// src: XBOX_PDB 0x00cc8cd0
void hkFixedConstraintCinfo_GetViewerStrings()
{
    hkBallAndSocketConstraintCinfo_GetViewerStrings();
}
}  // namespace fnv_00cc8cd0

struct S00cc9af0_Inner {
    virtual void Run(int v);
};

struct S00cc9af0_Obj {
    int unk00;
    int unk04;
    int unk08;
    void* m_pData;
    void bhkBallAndSocketConstraint_KillCinfo(bool b);
};

// If b is true and m_pData is set, calls Run(1) on the object at m_pData minus 4, then nulls m_pData.
// @fnv 0x00cc9af0
// src: XBOX_PDB 0x00cc9af0
void S00cc9af0_Obj::bhkBallAndSocketConstraint_KillCinfo(bool b)
{
    AutoMemContext guard;
    if (b) {
        if (m_pData) {
            S00cc9af0_Inner* obj = reinterpret_cast<S00cc9af0_Inner*>((char*)m_pData - 4);
            if (obj) {
                obj->Run(1);
            }
        }
        m_pData = 0;
    }
}

extern const float g_fCCE1C0DefaultScale;

struct CCE1C0MemoryManager;
extern CCE1C0MemoryManager g_CCE1C0MemoryManager;

extern __declspec(thread) int g_CCE1C0AllocTag;





struct CCE1C0Child {
    CCE1C0Child() throw()
        : m_pkOwnerManager(0), m_fScale(g_fCCE1C0DefaultScale), m_arr08(), m_arr14()
    {
    }

    void* m_pkOwnerManager;
    float m_fScale;
    hkArrayBase<hkVector4> m_arr08;
    hkArrayBase<hkVector4> m_arr14;

    static void* operator new(unsigned int uiSize) throw() { return reinterpret_cast<MemoryManager&>(g_CCE1C0MemoryManager).Allocate(uiSize); }
    static void operator delete(void* pvMem) {}
};

struct CCE1C0Owner {
    int unk00;
    int unk04;
    void* m_pParentNode;
    CCE1C0Child* m_pkChild;

    void bhkConvexVerticesShape_CopyCinfo(CCE1C0Child* pkChild);
    CCE1C0Child* GetOrCreateChild(bool* pbCreated);
};

// Sets *pbCreated if m_pkChild was null and then creates it, calling FUN_00cce010 with it when m_pParentNode is set; returns m_pkChild.
// @fnv 0x00cce1c0
CCE1C0Child* CCE1C0Owner::GetOrCreateChild(bool* pbCreated)
{
    AutoMemContext scope(0x10);

    *pbCreated = (m_pkChild == 0);
    if (*pbCreated) {
        m_pkChild = new CCE1C0Child();
        if (m_pParentNode) bhkConvexVerticesShape_CopyCinfo(m_pkChild);
    }
    return m_pkChild;
}

extern __declspec(thread) unsigned int t_uiMemContextC01;

template <class T>
__forceinline void hkArrayUtil::constructWithCopy(T* p, int n, const T& t, hkTypeIsPod)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
    m_iElementCount++;
}



// slotB4 returns creation info with a child-pointer array at +0x10; hkpShapeContainer has no fields.
class ConvexListShapeCreationInfo {
public:
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    hkArray<hkpShape*> m_kChildShapes;
};





// The shared header omits the bhkShape override; import its ABI without a surrogate class.
void BhkShapeLinkObject();

// Reads and links the child shapes. The shared class omits LinkObject; retain its ECX receiver and stack argument here.
// @fnv 0x00cd0170
void __fastcall LinkConvexListShape(bhkConvexListShape* shape, void*, NiStream& kStream)
{
    AutoMemContext kContext(0x10);
    char cTmp;
    ConvexListShapeCreationInfo* pkContainer = reinterpret_cast<ConvexListShapeCreationInfo*>(shape->slotB4(&cTmp));
    unsigned int ItemUpdateArray = kStream.GetLinkID();
    hkArray<hkpShape*>& kShapes = pkContainer->m_kChildShapes;
    kShapes.clearAndDeallocate();
    kShapes.GrowArrayCapacity(GetMemoryRouter().heap(), ItemUpdateArray);
    for (unsigned int i = 0; i < ItemUpdateArray; i++) {
        bhkRefObject* pkObject = reinterpret_cast<bhkRefObject*>(kStream.GetLoadedObject());
        if (pkObject)
            kShapes.pushBack(reinterpret_cast<hkpShape*>(pkObject->m_pHavokObject));
    }
    typedef void (__thiscall* LinkObjectFunction)(bhkShape*, NiStream&);
    reinterpret_cast<LinkObjectFunction>(&BhkShapeLinkObject)(shape, kStream);
}

class FUN_00cdb360_cls
{
public:
    float m_00;
    float m_04;
    float m_08;
    float m_0c;
    float m_10;
    float m_14;
    float m_18;
    float m_1c;
    float m_20;
    float m_24;
    float m_28;
    float m_2c;
    FUN_00cdb360_cls* hkaKeyFrameHierarchyUtility_ControlData_ControlData();
};

// Sets the twelve float fields to fixed constants and returns this.
// @fnv 0x00cdb360
// src: HAVOK_LIB 0x00cdb360
FUN_00cdb360_cls* FUN_00cdb360_cls::hkaKeyFrameHierarchyUtility_ControlData_ControlData()
{
    m_00 = 0.17f;
    m_04 = 0.0f;
    m_08 = 1.0f;
    m_0c = 0.6f;
    m_10 = 0.05f;
    m_14 = 1.4f;
    m_18 = 1.8f;
    m_1c = 0.1f;
    m_20 = 0.3f;
    m_24 = 0.3f;
    m_28 = 0.03f;
    m_2c = 0.1f;
    return this;
}

// 10024 bytes of scratch stack space with no array type (the original frame
// carries no /GS cookie), spelled as nested scalar blocks sized 8..8192.
struct CcScratch8 { int m0, m1; };
struct CcScratch32 { CcScratch8 m0, m1, m2, m3; };
struct CcScratch256 { CcScratch32 m0, m1, m2, m3, m4, m5, m6, m7; };
struct CcScratch512 { CcScratch256 m0, m1; };
struct CcScratch1K { CcScratch256 m0, m1, m2, m3; };
struct CcScratch8K { CcScratch1K m0, m1, m2, m3, m4, m5, m6, m7; };
struct CcScratchBuf { CcScratch8K a; CcScratch1K b; CcScratch512 c; CcScratch256 d; CcScratch32 e; CcScratch8 f; };

// Formats w into a buffer and writes it to the stream in unk08, returning this.
// @fnv 0x00cc0230
hkOstream* __fastcall WriteOstreamUInt16(hkOstream* self, void*, unsigned short w)
{
	CcScratchBuf buffer;
	Vsnprintf((char*)&buffer, 10024, "%u", w);
	writeString(self->m_pStreamWriter, (const char*)&buffer);
	return self;
}

extern const char str_01094cf0[];

// @fnv 0x00cc0320
hkOstream& hkOstream::WriteFloat(float value) throw() {
    int buf[2506];
    Vsnprintf((char*)buf, 0x2728, str_01094cf0, value);
    writeString(m_pStreamWriter, (const char*)buf);
    return *this;
}

extern const char str_010c9328[];

// Formats a string into a local buffer using Vsnprintf and writes it to the hkStreamWriter in unk08 via FUN_00cc0080.
// @fnv 0x00cc03c0
hkOstream* __fastcall WriteOstreamUInt64(hkOstream* self, void*, unsigned __int64 v)
{
    int buf[0x9ca];
    Vsnprintf((char*)buf, 0x2728, str_010c9328, v);
    writeString(self->m_pStreamWriter, (const char*)buf);
    return self;
}

struct T { char pad[0x20]; unsigned short m_20; };
// @fnv 0x00cc0e00
// src: HAVOK_LIB 0x00cc0e00
static __declspec(noinline) T* getAnyNonFixedIsland(T* a, T* b)
{
    T* r = a;
    if (a->m_20 == 0xffff && b->m_20 != 0xffff)
        r = b;
    return r;
}
T* volatile g_a; T* volatile g_b; T* volatile g_sink;
void caller() { g_sink = getAnyNonFixedIsland(g_a, g_b); }

extern int DAT_010c93fc;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct CC1290Object {
    void __thiscall FUN_00a5d3a0();

    void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }

    CC1290Object() {
        FUN_00a5d3a0();
        m_pVtable = reinterpret_cast<void*>(&DAT_010c93fc);
        m_uiValue1 = 0;
        m_uiData1 = 0;
        m_uiData2 = 0;
        m_uiData3 = 0;
    }

    void* m_pVtable;
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    unsigned int m_uiData3;
};

// Allocates and returns a new CC1290Object instance via its operator new.
// @fnv 0x00cc1290
CC1290Object* __cdecl CreateCC1290Object()
{
    return new CC1290Object;
}

struct LoadMM { void* Allocate(unsigned int); };
extern LoadMM loadManager;
struct LoadTLS {
int unk000;
int unk004;
int unk008;
int unk00c;
int unk010;
int unk014;
int unk018;
int unk01c;
int unk020;
int unk024;
int unk028;
int unk02c;
int unk030;
int unk034;
int unk038;
int unk03c;
int unk040;
int unk044;
int unk048;
int unk04c;
int unk050;
int unk054;
int unk058;
int unk05c;
int unk060;
int unk064;
int unk068;
int unk06c;
int unk070;
int unk074;
int unk078;
int unk07c;
int unk080;
int unk084;
int unk088;
int unk08c;
int unk090;
int unk094;
int unk098;
int unk09c;
int unk0a0;
int unk0a4;
int unk0a8;
int unk0ac;
int unk0b0;
int unk0b4;
int unk0b8;
int unk0bc;
int unk0c0;
int unk0c4;
int unk0c8;
int unk0cc;
int unk0d0;
int unk0d4;
int unk0d8;
int unk0dc;
int unk0e0;
int unk0e4;
int unk0e8;
int unk0ec;
int unk0f0;
int unk0f4;
int unk0f8;
int unk0fc;
int unk100;
int unk104;
int unk108;
int unk10c;
int unk110;
int unk114;
int unk118;
int unk11c;
int unk120;
int unk124;
int unk128;
int unk12c;
int unk130;
int unk134;
int unk138;
int unk13c;
int unk140;
int unk144;
int unk148;
int unk14c;
int unk150;
int unk154;
int unk158;
int unk15c;
int unk160;
int unk164;
int unk168;
int unk16c;
int unk170;
int unk174;
int unk178;
int unk17c;
int unk180;
int unk184;
int unk188;
int unk18c;
int unk190;
int unk194;
int unk198;
int unk19c;
int unk1a0;
int unk1a4;
int unk1a8;
int unk1ac;
int unk1b0;
int unk1b4;
int unk1b8;
int unk1bc;
int unk1c0;
int unk1c4;
int unk1c8;
int unk1cc;
int unk1d0;
int unk1d4;
int unk1d8;
int unk1dc;
int unk1e0;
int unk1e4;
int unk1e8;
int unk1ec;
int unk1f0;
int unk1f4;
int unk1f8;
int unk1fc;
int unk200;
int unk204;
int unk208;
int unk20c;
int unk210;
int unk214;
int unk218;
int unk21c;
int unk220;
int unk224;
int unk228;
int unk22c;
int unk230;
int unk234;
int unk238;
int unk23c;
int unk240;
int unk244;
int unk248;
int unk24c;
int unk250;
int unk254;
int unk258;
int unk25c;
int unk260;
int unk264;
int unk268;
int unk26c;
int unk270;
int unk274;
int unk278;
int unk27c;
int unk280;
int unk284;
int unk288;
int unk28c;
int unk290;
int unk294;
int unk298;
int unk29c;
int unk2a0;
int unk2a4;
int unk2a8;
int unk2ac;
int unk2b0;
int context;
};
extern __declspec(thread) LoadTLS loadTLS;
struct LoadScope { int old; LoadScope() { old=loadTLS.context; loadTLS.context=16; } ~LoadScope() { loadTLS.context=old; } };

struct LoadString { void* value; LoadString(); ~LoadString(); static void* operator new[](unsigned int n) { return loadManager.Allocate(n); } };
struct LoadElem { int a,b,c,d,e,f,g,h,i,j,k,l; };
struct LoadGroup { unsigned int count; LoadElem* data; LoadGroup() : count(0), data(0) {} static void* operator new(unsigned int n) { return loadManager.Allocate(n); } };
struct LoadGroupPtr { LoadGroup* value; static void* operator new[](unsigned int n) { return loadManager.Allocate(n); } };

void __cdecl LoadElement(NiStream&,LoadElem&);
struct LoadObject { int unk00,unk04; unsigned int stringCount; LoadString* strings; unsigned int groupCount; LoadGroup** groups; void BaseLoad(NiStream&); void bhkPoseArray_LoadBinary(NiStream&); };
// Reads string and group counts from the stream, allocates LoadString and LoadGroup arrays, and reads each string and group element.
// @fnv 0x00cc1730
// src: XBOX_PDB 0x00cc1730
void LoadObject::bhkPoseArray_LoadBinary(NiStream& stream) { LoadScope scope;unsigned& uiGroupCount=groupCount; BaseLoad(stream); ReadStreamScalar(InputStream(stream), &stringCount); if (stringCount>0) strings=new LoadString[stringCount]; for(unsigned int n=0;n<stringCount;++n) stream.ReadStringTableEntry(*reinterpret_cast<NiFixedString*>(&strings[n])); ReadStreamScalar(InputStream(stream), &uiGroupCount); if(groupCount>0) groups=(LoadGroup**)new LoadGroupPtr[groupCount]; for(unsigned int n=0;n<groupCount;++n) { groups[n]=new LoadGroup; LoadGroup* group=groups[n]; ReadStreamScalar(InputStream(stream), &group->count); for(unsigned int j=0;j<group->count;++j) LoadElement(stream,group->data[j]); } }

extern int DAT_010c970c;
extern int DAT_012685c4;
struct CC3D60Base
{
    void UpdateState_00c87c30();
};
struct CC3D60Object : CC3D60Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    CC3D60Object()
    {
        unsigned int count = 1;
        UpdateState_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c970c;
        DAT_012685c4 += count;
    }
};
struct CC3D60Owner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52(CC3D60Object* object, unsigned int argument);
    CC3D60Object* CreateObject(unsigned int argument);
};
// Allocates a CC3D60Object, passes it and the argument to virtual vf52, and returns it.
// @fnv 0x00cc3d60
CC3D60Object* CC3D60Owner::CreateObject(unsigned int argument)
{
    TlsHeapGuard guard;
    bhkSerializable_CloneCritLock();
    CC3D60Object* object = new CC3D60Object;
    vf52(object, argument);
    bhkSerializable_CloneCritUnlock();
    return object;
}

#include <xmmintrin.h>
extern __declspec(thread) unsigned int memoryCategory;
struct ScopedMemoryCategory {
    unsigned int previous;
    ScopedMemoryCategory() : previous(memoryCategory) { memoryCategory = 16; }
    ~ScopedMemoryCategory() { memoryCategory = previous; }
};




struct ShapeInfoCC3 {
    unsigned int unk00;
    unsigned int m_uiArg1;
    unsigned int m_uiArg2;
    unsigned int unk0c;
    float pivotAx,pivotAy,pivotAz,pivotAw;
    float pivotBx,pivotBy,pivotBz,pivotBw;
    float m_fBoundRadius;
    float m_fFriction;
};



class FUN_00d4d980 : public hkReferencedObject {
public:
    FUN_00d4d980(unsigned int a, unsigned int b, int c); // FUN_00d4d980

    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __forceinline void assign(float ax,float ay,float az,float aw,float bx,float by,float bz,float bw) { m_kMinimumCorner.m_vComponents=_mm_setr_ps(ax,ay,az,aw);m_kMaximumCorner.m_vComponents=_mm_setr_ps(bx,by,bz,bw); }
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    float m_fBoundRadius;
    float m_fFriction;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};

class ShapeOwnerCC3 {
public:
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void AddShape(FUN_00d4d980* pkShape);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void Update(ShapeInfoCC3* pkInfo);
    void CreateShapeFromInfo(ShapeInfoCC3* pkInfo);
};

// Builds a shape from pkInfo's fields, adds it with AddShape, calls FUN_00c905b0 on it, then calls Update(pkInfo).
// @fnv 0x00cc3f40
void ShapeOwnerCC3::CreateShapeFromInfo(ShapeInfoCC3* pkInfo)
{
    ScopedMemoryCategory kScope;
    FUN_00d4d980* pkShape = new FUN_00d4d980(pkInfo->m_uiArg1, pkInfo->m_uiArg2, 0);
    pkShape->assign(pkInfo->pivotAx,pkInfo->pivotAy,pkInfo->pivotAz,pkInfo->pivotAw,pkInfo->pivotBx,pkInfo->pivotBy,pkInfo->pivotBz,pkInfo->pivotBw);
    pkShape->m_fBoundRadius = pkInfo->m_fBoundRadius;
    pkShape->m_fFriction = pkInfo->m_fFriction;
    AddShape(pkShape);
    pkShape->removeReference();
    Update(pkInfo);
}

extern int DAT_010c97e4;
extern int DAT_012685d0;
struct CC42A0Base
{
    void UpdateState_00c87c30();
};
struct CC42A0Object : CC42A0Base
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0c;

    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }

    CC42A0Object()
    {
        unsigned int count = 1;
        UpdateState_00c87c30();
        m_pVtable = &DAT_0102016c;
        m_0c = 0;
        DAT_01268154 += count;
        m_pVtable = &DAT_010c5ef4;
        DAT_01268194 += count;
        m_pVtable = &DAT_010c97e4;
        DAT_012685d0 += count;
    }
};
// Allocates and returns a new CC42A0Object instance via its operator new.
// @fnv 0x00cc42a0
CC42A0Object* CreateCC42A0Object()
{
    return new CC42A0Object;
}

struct SaveValues460 {
    unsigned long unk00, unk04, unk08, unk0C;
    volatile unsigned long value10, value14, value18, value1C, value20, value24;
};

struct SaveObject460 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B();
    virtual void v1C(); virtual void v1D(); virtual void v1E(); virtual void v1F();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2A(); virtual void v2B();
    virtual void v2C();
    virtual SaveValues460* GetData(bool* flag);
    void DispatchChainNodes(FUN_00cc3c50_arg* stream);
    void bhkAngularDashpotAction_SaveBinary(FUN_00cc3c50_arg* stream);
};

inline void SwapValues460(SaveValues460* data) {
    data->value10 = _byteswap_ulong(data->value10);
    data->value14 = _byteswap_ulong(data->value14);
    data->value18 = _byteswap_ulong(data->value18);
    data->value1C = _byteswap_ulong(data->value1C);
    data->value20 = _byteswap_ulong(data->value20);
    data->value24 = _byteswap_ulong(data->value24);
}

// Byte-swaps value10 through value24 of the data when stream->m_1e4 is not 1, calls DispatchChainNodes, then swaps them back.
// @fnv 0x00cc4460
// src: XBOX_PDB 0x00cc4460
void SaveObject460::bhkAngularDashpotAction_SaveBinary(FUN_00cc3c50_arg* stream) {
    bool flag;
    SaveValues460* data = GetData(&flag);
    if (stream->m_1e4 != 1) SwapValues460(data);
    DispatchChainNodes(stream);
    if (stream->m_1e4 != 1) SwapValues460(data);
}

void* __cdecl CreateF4A30Result(void* a, int b);
struct ObjHook : S_00cc4b90_Obj {
    void ahkpBreakableConstraintData_SetChild(void* child);
};
namespace c4a80 {
struct Cls {
    int unk0;
    S_00cc4b90_Obj* m_p;
    int hkBreakableConstraintCinfo_CloneData(S_00cc4b90_Obj* shape, int a2);
    int ReleaseObject(S_00cc4b90_Obj* shape, int a2);
};
// Uses shape or allocates one if null, attaches a child made from m_p->unk18, copies f20 and b24 from m_p, and returns ReleaseObject(shape, a2).
// @fnv 0x00cc4a80
// src: XBOX_PDB 0x00cc4a80
int Cls::hkBreakableConstraintCinfo_CloneData(S_00cc4b90_Obj* shape, int a2) {
    S_00cc4b90_Ctx ctx(0x10);
    S_00cc4b90_Obj* src = m_p;
    if (shape == 0)
        shape = new S_00cc4b90_Obj();
    if (src->unk18 != 0) {
        void* child = CreateF4A30Result((void*)src->unk18, a2);
        if (child != 0) {
            ((ObjHook*)shape)->ahkpBreakableConstraintData_SetChild(child);
            ((FUN_00cca450_hook*)child)->FUN_00c905b0();
        }
    }
    shape->f20 = src->f20;
    unsigned char b = *(volatile unsigned char*)&src->b24;
    shape->b24 = b;
    return ReleaseObject(shape, a2);
}
}

extern __declspec(thread) unsigned int t_uiMemContext4D40;
inline unsigned int GetMemContext4D40()
{
    return t_uiMemContext4D40;
}
inline void SetMemContext4D40(unsigned int m_uiGeometryShaderFlags)
{
    t_uiMemContext4D40 = m_uiGeometryShaderFlags;
}

struct MemoryManager4D40;
extern MemoryManager4D40 g_kMemoryManager4D40;

class PolyBase4D40 {
public:
    void* m_pVtable;
};

// 0x00cc4d40 creates breakable-constraint cinfo with four words; the unrelated Interface type is one byte.
struct BreakableConstraintInfoFields {
    BreakableConstraintInfoFields() {}
    int m_iFirst;
    int m_iArrayLength;
    int m_iA;
    int m_iB;
};

class Object4D40 : public PolyBase4D40, public BreakableConstraintInfoFields {
public:
    static void* operator new(unsigned int uiSize) throw() { return reinterpret_cast<MemoryManager&>(g_kMemoryManager4D40).Allocate(uiSize); }
    Object4D40() { BreakableConstraintInfoFields* self = this; m_iArrayLength = 1; m_iA = 0; m_iB = 0; m_pVtable = &DAT_010c99e0; self->m_iFirst = 0; }
};

class Owner4D40 {
public:
    BreakableConstraintInfoFields* GetOrCreateInterface(bool* pbCreated);
    void SetObject(Object4D40* pkObject);

    int unk00;
    int unk04;
    int m_iActive;
    BreakableConstraintInfoFields* m_pkInterface;
};

// Creates an Object4D40 if m_pkInterface is null, sets *pbCreated, and returns the interface pointer.
// @fnv 0x00cc4d40
BreakableConstraintInfoFields* Owner4D40::GetOrCreateInterface(bool* pbCreated)
{
    AutoMemContext kContext(0x10);
    bool bCreate = m_pkInterface == 0;
    *pbCreated = bCreate;
    if (bCreate) {
        m_pkInterface = new Object4D40;
        if (m_iActive)
            SetObject(static_cast<Object4D40*>(m_pkInterface));
    }
    return m_pkInterface;
}

extern __declspec(thread) int g_tlsMemContext;
struct ViewerMemoryContext {
    int previous;
    ViewerMemoryContext() : previous(g_tlsMemContext) { g_tlsMemContext = 16; }
    ~ViewerMemoryContext() { g_tlsMemContext = previous; }
};
struct ViewerStrings {
    void* vtable;
    char** values;
    unsigned short capacity, count, used, growth;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, char*&);
    void Append(char* value) {
        unsigned int index = count;
        if (index >= capacity) FUN_0096ad30(index + growth);
        FUN_0096ae90(index, value);
    }
};
inline void AppendViewerString(ViewerStrings* strings, char* value) {
    unsigned int index = strings->count;
    if (index >= strings->capacity) strings->FUN_0096ad30(index + strings->growth);
    strings->FUN_0096ae90(index, value);
}
struct ViewerConstraint {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual int type();
};
struct ConstraintViewer {
    virtual ~ConstraintViewer();
    virtual void v4(); virtual void v8(); virtual void vC(); virtual void v10();
    virtual void GetStrings(ViewerStrings*);
    void SetChildObject(ViewerConstraint*);
};
ConstraintViewer* __cdecl CreateSaver(int);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
char* __cdecl NiGetViewerString(const char*, bool);
extern const char DAT_010c9a04[], DAT_010c99f8[];
struct ViewerFlag { unsigned char value; operator bool() const { return value != 0; } };
struct ViewerData {
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    ViewerConstraint* constraint;
    int unk1C;
    float strength;
    ViewerFlag enabled;
    ViewerConstraint* GetConstraint() { return constraint; }
};
struct DataViewer {
    void* vtable;
    ViewerData* data;
    void hkConstraintCinfo_GetViewerStrings(ViewerStrings*);
    ViewerData* GetData() { return data; }
    float Strength() { return GetData() ? GetData()->strength : 0.0f; }
    bool Enabled() { return GetData() ? bool(GetData()->enabled) : false; }
    ViewerConstraint* Constraint() { return GetData() ? GetData()->GetConstraint() : 0; }
    void hkBreakableConstraintCinfo_GetViewerStrings(ViewerStrings* strings);
};
// Appends strength and enabled strings, then appends constraint-specific strings via a ConstraintViewer created from the constraint type.
// @fnv 0x00cc4f00
// src: XBOX_PDB 0x00cc4f00
void DataViewer::hkBreakableConstraintCinfo_GetViewerStrings(ViewerStrings* strings) {
    ViewerMemoryContext context;
    hkConstraintCinfo_GetViewerStrings(strings);
    AppendViewerString(strings, NiGetViewerString_00a7d550(DAT_010c9a04, Strength()));
    AppendViewerString(strings, NiGetViewerString(DAT_010c99f8, Enabled()));
    ViewerConstraint* constraint = Constraint();
    if (constraint) {
        int t = constraint->type();
        ConstraintViewer* viewer = CreateSaver(t);
        if (viewer) {
            viewer->SetChildObject(constraint);
            viewer->GetStrings(strings);
            delete viewer;
        }
    }
}

struct FUN_00d4f2a0 {
    int unk00;
    unsigned short m_us4;
    FUN_00d4f2a0();
    void* operator new(unsigned int, unsigned int n) {
        void* b = hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n);
        ((FUN_00d4f2a0*)b)->m_us4 = (unsigned short)n;
        return b;
    }
    void operator delete(void*, unsigned int) {}
};

struct S00cc6030_Cls {
    void* unk00;
    FUN_00d4f2a0* unk04;
    int hkRagdollLimitsConstraintCinfo_CreateData();
};

// Allocates a FUN_00d4f2a0 object of 0xc0 bytes into unk04 if it is null, then returns 0xc0.
// @fnv 0x00cc6030
// src: XBOX_PDB 0x00cc6030
int S00cc6030_Cls::hkRagdollLimitsConstraintCinfo_CreateData()
{
    if (unk04 == 0)
    {
        unk04 = new (0xc0u) FUN_00d4f2a0();
    }
    return 0xc0;
}

struct FUN_00d52fc0 : hkReferencedObject
{
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    FUN_00d52fc0();
};
struct CC86C0Owner
{
    int unk00;
    FUN_00d52fc0* m_pObject;
    int hkHingeLimitsConstraintCinfo_CreateData();
};
// Allocates m_pObject if null and returns the size of the FUN_00d52fc0 object.
// @fnv 0x00cc86c0
// src: XBOX_PDB 0x00cc86c0
int CC86C0Owner::hkHingeLimitsConstraintCinfo_CreateData()
{
    TlsHeapGuard guard;
    if (!m_pObject)
        m_pObject = new FUN_00d52fc0;
    return sizeof(FUN_00d52fc0);
}

extern int DAT_010ca050;
static __forceinline CC7970_RefData* CC8850_CreateReference() {
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<MemoryManager*>(&DAT_011f6238)->Allocate(sizeof(CC7970_RefObject)));
    if (object) {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010ca050;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC8850_Owner {
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    void __thiscall CopyFromSource(CC7970_RefObject* object);
    CC7970_RefData* __thiscall GetOrCreateReference(bool* created);
};
// Creates a CC7970_RefObject if m_pData is null, calls CopyFromSource on it when m_flag08 is set, and returns m_pData.
// @fnv 0x00cc8850
CC7970_RefData* CC8850_Owner::GetOrCreateReference(bool* created)
{
    TlsHeapGuard guard;
    *created = m_pData == 0;
    if (*created) {
        CC7970_RefData* data = CC8850_CreateReference();
        m_pData = data;
        if (m_flag08)
            CopyFromSource(data ? reinterpret_cast<CC7970_RefObject*>(reinterpret_cast<char*>(data) - 4) : 0);
    }
    return m_pData;
}

struct A9410Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void* pointer, unsigned int size);
};

struct O9410;

struct G9410
{
    O9410* m_pSharedOwner;
    G9410(void* p) { m_pSharedOwner = (O9410*)p; }
    ~G9410();
};

struct O9410
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    void* m_pData;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;

    void SetChildObject(int flag);
    void UpdateState_00cc9410();
};

G9410::~G9410()
{
    m_pSharedOwner->m_pVtable = &DAT_0108ffb4;
    m_pSharedOwner->SetChildObject(0);
}

// @fnv 0x00cc9410
// src: GUESS 0x00cc9410 (confidence: low)
void O9410::UpdateState_00cc9410()
{
    G9410 guard(this);
    S_00cc4b90_Router* router = hkMemoryRouter_getInstance();
    A9410Alloc* alloc = (A9410Alloc*)router->unk10;
    m_uiCount = 0;
    if ((m_uiValue1 & 0x80000000u) == 0)
    {
        void* data = m_pData;
        unsigned int tmp0 = m_uiValue1 & 0x3fffffff;
        alloc->Free(data, (tmp0) * 4u);
    }
    m_pData = 0;
    m_uiValue1 = 0x80000000;
}

extern "C" void* DAT_010ca22c;
extern __declspec(thread) int DAT_012722b4;

struct CacheValueVbase {
    void* m_pVtbl;
};
struct CacheValueFields {
    unsigned int m_uiRefCount;
    unsigned int m_uiValue1;
    unsigned int m_uiData1;
    unsigned int m_uiData2;
    CacheValueFields() {
        m_uiRefCount = 0;
        m_uiValue1 = 1;
        m_uiData1 = 0;
        m_uiData2 = 0;
    }
};
struct CacheValueMid {
    unsigned int m_uiData3;
    unsigned int m_uiData4;
    CacheValueMid() {
        m_uiData3 = 0;
        m_uiData4 = 0;
    }
};
struct CacheValue : CacheValueVbase, CacheValueFields, CacheValueMid {
    unsigned int m_uiCapacityAndFlags;
    void* m_pData;
    unsigned int m_uiSize;
    unsigned int m_uiFinalFlags;
    CacheValue() : CacheValueFields(), CacheValueMid() {
        m_uiCapacityAndFlags = 0x80000000;
        m_pVtbl = &DAT_010ca22c;
        m_pData = 0;
        m_uiSize = 0;
        m_uiFinalFlags = 0x80000000;
    }
    static void* operator new(unsigned int size) throw() {
        return reinterpret_cast<MemoryManager*>(&DAT_011f6238)->Allocate(size);
    }
};

struct CacheOwner {
    unsigned int unk00;
    unsigned int unk04;
    void* m_pSharedOwner;
    CacheValueFields* m_pIntegerData;
    void __thiscall bhkBallSocketConstraintChain_CopyCinfo(void* value);
    void* __thiscall GetOrCreateCacheValue(bool* created);
};

// Ensures m_pIntegerData points to a CacheValue, creating one if absent and reporting via created whether it was newly created.
// @fnv 0x00cc9560
void* CacheOwner::GetOrCreateCacheValue(bool* created)
{
    AutoMemContext tlsGuard;
    bool wasEmpty = (m_pIntegerData == 0);
    *created = wasEmpty;
    if (wasEmpty) {
        CacheValue* object = new CacheValue;
        m_pIntegerData = object;
        if (m_pSharedOwner != 0) {
            bhkBallSocketConstraintChain_CopyCinfo(static_cast<CacheValue*>(m_pIntegerData));
        }
    }
    return m_pIntegerData;
}

extern int DAT_010c8cc8;
static __forceinline CC7970_RefData* CC9A20_CreateReference() {
    CC7970_RefObject* object = reinterpret_cast<CC7970_RefObject*>(
        reinterpret_cast<MemoryManager*>(&DAT_011f6238)->Allocate(sizeof(CC7970_RefObject)));
    if (object) {
        CC7970_RefData* data = &object->m_data;
        object->m_uiRefCount = 1;
        object->m_uiValue1 = 0;
        object->m_uiReserved = 0;
        object->m_pVtable = &DAT_010c8cc8;
        data->m_uiFilterValue = 0;
        return data;
    }
    return 0;
}
struct CC9A20_Owner {
    unsigned int m_unk00, m_unk04, m_flag08;
    CC7970_RefData* m_pData;
    void __thiscall CopyFromSource(CC7970_RefObject* object);
    CC7970_RefData* __thiscall EnsureReference(bool* created);
};
// Creates a CC7970_RefData reference on first call, copies source data if m_flag08 is set, and returns m_pData.
// @fnv 0x00cc9a20
CC7970_RefData* CC9A20_Owner::EnsureReference(bool* created)
{
    TlsHeapGuard guard;
    *created = m_pData == 0;
    if (*created) {
        CC7970_RefData* data = CC9A20_CreateReference();
        m_pData = data;
        if (m_flag08)
            CopyFromSource(data ? reinterpret_cast<CC7970_RefObject*>(reinterpret_cast<char*>(data) - 4) : 0);
    }
    return m_pData;
}

extern int DAT_010ca744;
extern "C" int DAT_01268678;
extern "C" int (__cdecl *DAT_00fdf1c4)(void*);

class NiReferenceState {
public:
    virtual ~NiReferenceState();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void DecRefCount() {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0) DeleteThis();
    }
};

struct FUN_00ccbc00_elem {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C;
    unsigned int unk10; unsigned int m_14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
};

struct FUN_00ccbc00_inner {
    unsigned int unk00; unsigned int unk04; unsigned int unk08; unsigned int unk0C;
    unsigned int unk10; unsigned int unk14; unsigned int unk18; unsigned int unk1C;
    unsigned int unk20; unsigned int unk24; unsigned int unk28; unsigned int unk2C;
    unsigned int unk30; unsigned int unk34; unsigned int unk38; unsigned int unk3C;
    unsigned int unk40; unsigned int unk44; unsigned int unk48; unsigned int unk4C;
    unsigned int unk50; unsigned int unk54; unsigned int unk58; unsigned int unk5C;
    unsigned int unk60; unsigned int unk64; unsigned int unk68; unsigned int unk6C;
    unsigned int unk70; unsigned int unk74; unsigned int unk78; unsigned int unk7C;
    unsigned int unk80; unsigned int unk84; unsigned int unk88; unsigned int unk8C;
    unsigned int unk90; unsigned int unk94; unsigned int unk98; unsigned int unk9C;
    unsigned int unkA0; unsigned int unkA4; unsigned int unkA8; unsigned int unkAC;
    unsigned int unkB0; FUN_00ccbc00_elem* m_b4; unsigned int m_b8;
};

struct CcbcOwnerBase {
    void bhkSerializable_Kill();
    void FUN_00cd2de0();
    ~CcbcOwnerBase() { FUN_00cd2de0(); }
};

class FUN_00ccbc00 : public CcbcOwnerBase {
public:
    void* volatile m_pVtable;
    unsigned int unk04;
    FUN_00ccbc00_inner* volatile m_08;
    unsigned int unk0c;
    unsigned int unk10;
    NiPointer<NiReferenceState> m_14;
    ~FUN_00ccbc00();
};

// Sets vtable to DAT_010ca744, zeroes m_14 in each m_b4 element, calls FUN_00c876a0, decrements DAT_01268678, and releases m_14.m_pObject.
// @fnv 0x00ccbc00
FUN_00ccbc00::~FUN_00ccbc00() {
    m_pVtable = (void*)&DAT_010ca744;
    FUN_00ccbc00_inner* x = m_08;
    if ((int)x->m_b8 > 0) {
        int n = (int)x->m_b8;
        unsigned int off = 0;
        do {
            *(unsigned int*)((char*)x->m_b4 + off + 0x14) = 0;
            off += 0x60;
        } while (--n != 0);
    }
    bhkSerializable_Kill();
    int one = 1;
    DAT_01268678 -= one;
    NiReferenceState* p = m_14.m_pObject;
    if (p) {
        if (InterlockedDecrement((volatile long*)&p->m_uiRefCount) == 0) p->DeleteThis();
        m_14.m_pObject = 0;
    }

}

class S00ccd2c0_Obj {
public:
    void UpdateState_00ccd170(float value);
};

struct S00ccd2c0_Arg2 {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    float m_10;
};

class S00ccd2c0_cls {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual S00ccd2c0_Obj* v45(bool* flag);
    int bhkShape_CopyMembers(void* a1, S00ccd2c0_Arg2* a2);
    int bhkCylinderShape_CopyMembers(void* a1, S00ccd2c0_Arg2* a2);
};

static volatile float S00ccd2c0_sink;

// src: GUESS 0x00ccd170 (confidence: low)
__declspec(noinline) void S00ccd2c0_Obj::UpdateState_00ccd170(float value)
{
    S00ccd2c0_sink = value;
}

// Gets an object via v45, passes a2->m_10 to its FUN_00ccd170 when it is not 1.0f, then returns FUN_00c84df0(a1, a2).
// @fnv 0x00ccd2c0
// src: XBOX_PDB 0x00ccd2c0
int S00ccd2c0_cls::bhkCylinderShape_CopyMembers(void* a1, S00ccd2c0_Arg2* a2)
{
    bool flag;
    S00ccd2c0_Obj* obj = v45(&flag);
    float f = a2->m_10;
    if (f != 1.0f) {
        obj->UpdateState_00ccd170(f);
    }
    return bhkShape_CopyMembers(a1, a2);
}

struct CCD460Owner
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49(FUN_00ccd100* object, unsigned int argument);
    FUN_00ccd100* bhkCylinderShape_CreateClone(unsigned int argument);
};
// Allocates a new FUN_00ccd100, passes it and argument to vf49, and returns it, between calls to FUN_00c876f0 and FUN_00c87700.
// @fnv 0x00ccd460
// src: XBOX_PDB 0x00ccd460
FUN_00ccd100* CCD460Owner::bhkCylinderShape_CreateClone(unsigned int argument)
{
    TlsHeapGuard guard;
    bhkSerializable_CloneCritLock();
    FUN_00ccd100* object = new FUN_00ccd100;
    vf49(object, argument);
    bhkSerializable_CloneCritUnlock();
    return object;
}







extern __declspec(thread) int g_EE60Ctx;
inline int GetMemContext() { return g_EE60Ctx; }
inline void SetMemContext(int aiMemoryContext) { g_EE60Ctx = aiMemoryContext; }
struct MemContextGuard {
    int m_iSaved;
    MemContextGuard(int aiMemoryContext) { m_iSaved = GetMemContext(); SetMemContext(aiMemoryContext); }
    ~MemContextGuard() { SetMemContext(m_iSaved); }
};

class EE60MemMgr { public: void* Allocate(unsigned int); };
extern EE60MemMgr g_EE60MemMgr;

extern float DAT_010c72bc;

struct CcEE60Data
{
    int unk00;
    float m_f04;
    int unk08;
    int unk0C;
    unsigned char m_kMotionTransformStorage[sizeof(Transform)];

    static void* operator new(unsigned int nbytes)
    {
        unsigned char* p = (unsigned char*)g_EE60MemMgr.Allocate(nbytes + 16);
        unsigned char offset = (unsigned char)(16 - ((unsigned int)p & 15));
        p += offset;
        p[-1] = offset;
        return p;
    }
    static void operator delete(void* p);

    CcEE60Data()
    {
        unk00 = 0;
        m_f04 = DAT_010c72bc;
        unk08 = 0;
        reinterpret_cast<Transform*>(m_kMotionTransformStorage)->setIdentity();
    }
};

class CcEE60Self
{
public:
    int unk00;
    int unk04;
    int m_08;
    CcEE60Data* m_data;

    void bhkConvexTransformShape_CopyCinfo(CcEE60Data* d);
    CcEE60Data* bhkConvexTransformShape_CreateCinfo(bool* created);
};

// Creates m_data if null, calls FUN_00ccea00 when m_08 is set, and returns m_data.
// @fnv 0x00ccee60
// src: XBOX_PDB 0x00ccee60
CcEE60Data* CcEE60Self::bhkConvexTransformShape_CreateCinfo(bool* created)
{
    MemContextGuard kGuard(16);
    *created = (m_data == 0);
    if (*created)
    {
        m_data = new CcEE60Data();
        if (m_08)
            bhkConvexTransformShape_CopyCinfo(m_data);
    }
    return m_data;
}

struct CD05E0_Alloc { void __thiscall MemoryManager_Deallocate(void* p); };
struct CD05E0_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct CD05E0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct CD05E0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    CD05E0_Obj* m_pEntryObject;
    void bhkConvexListShape_KillCinfo(bool release);
};
// If release is set, frees m_pEntryObject's data buffer and then the object itself, and sets m_pEntryObject to null.
// @fnv 0x00cd05e0
// src: XBOX_PDB 0x00cd05e0
void CD05E0_Owner::bhkConvexListShape_KillCinfo(bool release)
{
    TlsHeapGuard guard;
    if (release) {
        CD05E0_Obj* obj = m_pEntryObject;
        if (obj) {
            S_00cc4b90_Router* router = hkMemoryRouter_getInstance();
            CD05E0_Heap* alloc = (CD05E0_Heap*)router->unk10;
            obj->m_iElementCount = 0;
            if ((obj->m_iCapacityState & 0x80000000) == 0)
                alloc->ReturnMemory(obj->m_data, (obj->m_iCapacityState & 0x3fffffff) * 4);
            obj->m_data = 0;
            obj->m_iCapacityState = 0x80000000;
            reinterpret_cast<CD05E0_Alloc*>(&DAT_011f6238)->MemoryManager_Deallocate(obj);
        }
        m_pEntryObject = 0;
    }
}

struct WorkingState { __declspec(align(16)) unsigned char data[512]; };
struct Arg;
struct ActionTarget {
virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
virtual void v52();
    virtual void apply(Arg* first, Arg* second);
};
struct Result { int ReportDiagnostic; int unused4; ActionTarget* action; };
struct Cursor {
    virtual void reserved0();
    virtual void reserved1();
    virtual int first();
    virtual int next(int index);
    virtual void FunctionAtSlot4();
    virtual Result* lookup(int index, WorkingState* state);
};
struct Collection {
    int unk00, unk04, unk08, unk0C;
    Cursor cursor;
};
struct Dispatcher {
    int unk00, unk04;
    Collection* collection;
    void ApplyAll(Arg* argument1, Arg* argument2);
};
static inline ActionTarget* getAction(Dispatcher* d, int position, WorkingState& state) {
    Collection* c;
    if (d && (c = d->collection) != 0) {
        Result* result = c->cursor.lookup(position, &state);
        if (result) return result->action;
    }
    return 0;
}
// Iterates the collection cursor and calls apply on each action target, stopping when a lookup fails.
// @fnv 0x00cd2e50
void Dispatcher::ApplyAll(Arg* argument1, Arg* argument2) {
    WorkingState state;
    int position = (this ? collection : 0)->cursor.first();
    bool bContinue = true;
    while (bContinue && position != -1) {
        ActionTarget* action = getAction(this, position, state);
        position = (this ? collection : 0)->cursor.next(position);
        if (action) action->apply(argument1, argument2);
        else bContinue = false;
    }
}

struct TargetAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void ReleaseBlock(void* data, int size);
    void ReturnMemory(void* data, int size) { ReleaseBlock(data, size); }
};
struct TargetReferencedObject { void removeReference(); };
struct TargetContact {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
};
template<class T> struct AllocatorArray {
    T* data;
    int size;
    int capacityAndFlags;
    static void deallocate(TargetAllocator& a, T* p, int n) { a.ReturnMemory(p, n * int(sizeof(T))); }
    int GetLogicalSize() const { return size; }
    int getCapacity() const { return capacityAndFlags & 0x3fffffff; }
    void ClearAndRelease(TargetAllocator& allocator) {
        size = 0;
        if (!(capacityAndFlags & 0x80000000))
            deallocate(allocator, data, getCapacity());
        data = 0;
        capacityAndFlags = 0x80000000;
    }
    void ClearAndRelease() {
        ClearAndRelease(reinterpret_cast<TargetAllocator&>(hkMemoryRouter_getInstance()->heap()));
    }
    ~AllocatorArray() { ClearAndRelease(reinterpret_cast<TargetAllocator&>(hkMemoryRouter_getInstance()->heap())); }
};
struct TargetCollectorBase {
    virtual ~TargetCollectorBase();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
};
struct FUN_00cd3490 : TargetCollectorBase {
    AllocatorArray<TargetReferencedObject*> references;
    AllocatorArray<unsigned int> indices;
    AllocatorArray<TargetContact> contacts;
    virtual ~FUN_00cd3490();
};
// Releases all TargetReferencedObject references, then clears and releases the references, contacts, and indices arrays.
// @fnv 0x00cd3490
FUN_00cd3490::~FUN_00cd3490() {
    for (int i = 0; i < references.GetLogicalSize(); ++i)
        references.data[i]->removeReference();
    references.ClearAndRelease();
    contacts.ClearAndRelease();
    indices.ClearAndRelease();
}

// The shared matrix has no declaration for this scale operation; keep it as a
// file-local helper with the original ECX and stack argument convention.
// @fnv 0x00cd4d40
const LocalM128* __fastcall ScaleMatrixColumns(hkMatrix3* matrix, int, const LocalM128* scale, const hkMatrix3* source)
{
    matrix->m_kColumn0.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(*scale, *scale, 0), source->m_kColumn0.m_vComponents);
    matrix->m_kColumn1.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(*scale, *scale, 0), source->m_kColumn1.m_vComponents);
    matrix->m_kColumn2.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(*scale, *scale, 0), source->m_kColumn2.m_vComponents);
    return scale;
}

struct FUN_00cd7d20_Class {
    void __thiscall hkCharControllerShape_getAabb(float* param1, float param2, float* param3);
};

// @fnv 0x00cd7d20
// src: XBOX_PDB 0x00cd7d20
void FUN_00cd7d20_Class::hkCharControllerShape_getAabb(float* param1, float afScalar, float* apResult) {

    LocalM128 v_this30 = *reinterpret_cast<LocalM128*>(reinterpret_cast<char*>(this) + 0x30);

    LocalM128 v_param1_30 = *reinterpret_cast<LocalM128*>(param1 + 0x30 / sizeof(float));

    LocalM128 v_this20 = *reinterpret_cast<LocalM128*>(reinterpret_cast<char*>(this) + 0x20);

    LocalM128 sum1 = _mm_add_ps(v_param1_30, v_this30);

    LocalM128 vScalar = _mm_set1_ps(afScalar);
    LocalM128 sum2 = _mm_add_ps(vScalar, v_this20);

    LocalM128 diff = _mm_sub_ps(sum1, sum2);

    LocalM128 final_sum = _mm_add_ps(sum1, sum2);

    *reinterpret_cast<LocalM128*>(apResult) = diff;

    *reinterpret_cast<LocalM128*>(apResult + 4) = final_sum;
}

void* __cdecl Object_DispatchCommandFour(unsigned int size);
void __cdecl FUN_00aa1460(void* p);
extern float DAT_010c72bc;
namespace nd {

}
class FUN_00cce290 {
public:
    int m_iWordAt00;
    float m_iWordAt04;
    hkArrayBase<char> m_8;
    hkArrayBase<char> m_14;
    FUN_00cce290() : m_iWordAt00(0) {}
    ~FUN_00cce290();
};
struct SrcD;
void __cdecl LoadIntoArray(SrcD* src, hkArrayBase<char>* a, hkArrayBase<char>* b);
struct SrcD { int m_iWordAt00; int m_iWordAt04; };
class FUN_00cd7e80 {
public:
    char pad[0x14];
    FUN_00cd7e80(FUN_00cce290* data);
    static void* operator new(unsigned int size) { return Object_DispatchCommandFour(size); }
    static void operator delete(void* p) { FUN_00aa1460(p); }
};
// Builds a FUN_00cd7e80 from a temporary data struct filled from src when src->m_iWordAt04 is nonzero, otherwise returns null.
// @fnv 0x00cd7f50
FUN_00cd7e80* CreateFromSource(SrcD* src)
{
    TlsHeapGuard guard;
    FUN_00cd7e80* result = 0;
    FUN_00cce290 data;
    data.m_iWordAt04 = DAT_010c72bc;
    if (src->m_iWordAt04 != 0) {
        LoadIntoArray(src, &data.m_14, &data.m_8);
        result = new FUN_00cd7e80(&data);
    }
    return result;
}


// @fnv 0x00cdb0a0
hkArrayBase<hkQsTransform>* __fastcall AccessLocalPose(hkaPose* pose)
{
    pose->syncLocalSpace();
    return ResetStates(pose);
}

// The shared hkaPose has no declaration for this operation; keep its ECX entry point here.
// @fnv 0x00cdb0b0
void __fastcall UpdateLockedPoseFlags(hkaPose* pose)
{
    int n = pose->m_pSkeleton->m_kBones.m_iElementCount;
    pose->syncLocalSpace();
    for (int i = 0; i < n; ++i) {
        if (pose->m_pSkeleton->m_kBones[i].m_bLockTranslation) {
            pose->m_pLocalPose[i].m_vTranslation.m_vComponents = pose->m_pSkeleton->m_kReferencePose[i].m_vTranslation.m_vComponents;
            pose->m_pBoneFlags[i] |= 2;
            pose->m_pBoneFlags[i] |= 4;
        } else {
            short parent = pose->m_pSkeleton->m_kParentIndices[i];
            if (parent != -1 && (pose->m_pBoneFlags[parent] & 4)) {
                pose->m_pBoneFlags[i] |= 2;
                pose->m_pBoneFlags[i] |= 4;
            }
        }
    }
    int flagCount = pose->m_pBoneFlags.m_iElementCount;
    for (int i = 0; i < flagCount; ++i)
        pose->m_pBoneFlags[i] &= ~28u;
}

struct EntryState { unsigned int id; unsigned char active,mode; unsigned short category; };
struct __declspec(align(16)) EntryData { LocalM128 coordinates,rotation,metadata; };
struct FUN_00cdd2d0_Input {
 int unk00,unk04,unk08,unk0c,unk10,unk14;
 EntryState* states;
 int size;
 int unk20;
 EntryData* entries;
};
// Copies EntryData records from input->entries to output for each active state in input->states, skipping inactive entries.
// @fnv 0x00cdd2d0
// src: GUESS 0x00cdd2d0 (confidence: high)
extern "C" void __cdecl Animation_CopyActiveEntries(FUN_00cdd2d0_Input* input, EntryData* output)
{
    int count = input->size;
    int index = 0;
    if (count <= 0) return;
    unsigned int offset = 0;
    do {
        if (input->states[index].active) {
            const LocalM128* value = (const LocalM128*)((const char*)input->entries + offset);
            LocalM128* destination = (LocalM128*)((char*)output + offset);
            *destination = *value;
        }
        ++index;
        offset += sizeof(EntryData);
    } while (index < count);
}

namespace fnv_00cdd320 {
typedef ::__m128 LocalM128;

struct FUN_00cdd320_Entry {
    int unk00;
    char unk04;
};

struct FUN_00cdd320_Elem {
    LocalM128 unk00;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct FUN_00cdd320_Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00cdd320_Entry* unk18;
    int unk1C;
};

// Copies the first 16 bytes of each source element to the destination where the corresponding entry flag is set.
// @fnv 0x00cdd320
void __cdecl CopySelectedElements(FUN_00cdd320_Obj* obj, FUN_00cdd320_Elem* src, FUN_00cdd320_Elem* dst)
{
    int count = obj->unk1C;
    for (int i = 0; i < count; ++i) {
        if (obj->unk18[i].unk04) {
            *(LocalM128*)&dst[i].unk00 = *(const LocalM128*)&src[i].unk00;
        }
    }
}
}  // namespace fnv_00cdd320

namespace scdd360 {

struct Slot {
    int m_iData;
    bool m_bValueAt0C;
};

struct Table {
    int unk000;
    int unk004;
    int unk008;
    short* m_psCounts;
    int unk010;
    int unk014;
    Slot* m_pkSlots;
    int m_iArrayLength;
};

struct Flag {
    bool b;
};

// Sets m_bValueAt0C on each slot whose count is positive, or on all slots when kOnlyActive.b is false.
// @fnv 0x00cdd360
// src: GUESS 0x00cdd360 (confidence: medium)
void Object_SetActiveSlotFlags(Table* pkTable, Flag kOnlyActive)
{
    int iCount = pkTable->m_iArrayLength;
    for (int i = 0; i < iCount; ++i)
    {
        if (pkTable->m_psCounts[i] > 0 || !kOnlyActive.b)
            pkTable->m_pkSlots[i].m_bValueAt0C = true;
    }
}

}



inline void hkMatrix3::setIdentity()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
    m_kColumn0(0) = 1.0f;
    m_kColumn1(1) = 1.0f;
    m_kColumn2(2) = 1.0f;
}



struct hkBool_s {
    char m_cBooleanValue;
    hkBool_s(bool b) { m_cBooleanValue = (char)b; }
};

struct RagdollAtoms_s {
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RagdollAtoms_s();
};



struct RefObjectBase_s {
    virtual void vfunc00();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    RefObjectBase_s() { m_sReferenceCount = 1; }
};

struct ConstraintDataBase_s : RefObjectBase_s {
    int m_ulUserData;
    ConstraintDataBase_s() { m_ulUserData = 0; }
    void setSolvingFlag(hkBool_s flag);
};

struct FUN_00cdf2f0 : ConstraintDataBase_s {
    int unk0C;
    RagdollAtoms_s m_kBridgeAtoms;
    unsigned char m_kBodyALocalFrameStorage[sizeof(Transform)];
    unsigned char m_kBodyBLocalFrameStorage[sizeof(Transform)];
    unsigned short unkA0;
    unsigned char unkA2;
    unsigned char unkA3;
    volatile unsigned short unkA4;
    unsigned short unkA6;
    int unkA8;
    int unkAC;
    __declspec(align(16)) unsigned char m_rotationB0[sizeof(hkMatrix3)];
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    unsigned char unkF0;
    unsigned char unkF1;
    unsigned char unkF2;
    unsigned char unkF3;
    unsigned char unkF4;
    unsigned char unkF5;
    unsigned char unkF6;
    unsigned char unkF7;
    float unkF8;
    unsigned char unkFC;
    unsigned char unkFD;
    unsigned char unkFE;
    unsigned char unkFF;
    unsigned char unk100;
    unsigned char unk101;
    unsigned char unk102;
    unsigned char unk103;
    float unk104;
    float unk108;
    float unk10C;
    unsigned char unk110;
    unsigned char unk111;
    unsigned char unk112;
    unsigned char unk113;
    unsigned char unk114;
    unsigned char unk115;
    unsigned char unk116;
    unsigned char unk117;
    float unk118;
    float unk11C;
    float unk120;
    unsigned char unk124;
    unsigned char unk125;
    unsigned char unk126;
    unsigned char unk127;
    unsigned char unk128;
    unsigned char unk129;
    unsigned char unk12A;
    unsigned char unk12B;
    float unk12C;
    float unk130;
    float unk134;

    FUN_00cdf2f0();
};

__declspec(noinline) void ConstraintDataBase_s::setSolvingFlag(hkBool_s flag)
{
    static_cast<FUN_00cdf2f0*>(this)->unk116 = (unsigned char)((flag.m_cBooleanValue != 0) * 0x38);
}

// @fnv 0x00cdf2f0
FUN_00cdf2f0::FUN_00cdf2f0()
{
    reinterpret_cast<Transform*>(m_kBodyALocalFrameStorage)->setIdentity();
    reinterpret_cast<Transform*>(m_kBodyBLocalFrameStorage)->setIdentity();
    unkF3 = 0;
    unkF8 = 0.0f;
    unkF4 = 3;
    unkA2 = 0;
    unkA4 = 0x60;
    unkA6 = 0x64;
    reinterpret_cast<hkMatrix3*>(m_rotationB0)->setIdentity();
    unk104 = -0.5236f;
    unkE0 = 0;
    unk108 = 0.5236f;
    unkE4 = 0;
    unkE8 = 0;
    unkFF = 0;
    unk100 = 1;
    unk10C = 0.8f;
    unk113 = 0;
    unk114 = 0;
    unk118 = -100.0f;
    unk115 = 0;
    unk11C = 1.0f;
    unk120 = 0.8f;
    setSolvingFlag(true);
    unk12C = -0.025f;
    unk127 = 0;
    unk128 = 1;
    unk130 = 0.025f;
    unk129 = 1;
    unk134 = 0.8f;
}

extern "C" void _ReadWriteBarrier();
extern float DAT_0104da48;

struct CdfSubObject
{
    volatile unsigned char m_00;
    void FindFloatTableIndex(float* value);
};

class CdfObject
{
public:
    volatile unsigned short m_00; // +0x0
    volatile unsigned char unk02; // +0x2
    volatile unsigned char unk03; // +0x3
    volatile unsigned char unk04; // +0x4
    volatile unsigned char unk05; // +0x5
    volatile unsigned char unk06; // +0x6
    volatile unsigned char unk07; // +0x7
    volatile unsigned char unk08; // +0x8
    volatile unsigned char unk09; // +0x9
    volatile unsigned char unk0a; // +0xa
    volatile unsigned char unk0b; // +0xb
    volatile unsigned char unk0c; // +0xc
    volatile unsigned char unk0d; // +0xd
    volatile unsigned char unk0e; // +0xe
    volatile unsigned char unk0f; // +0xf
    volatile unsigned char unk10; // +0x10
    volatile unsigned char unk11; // +0x11
    volatile unsigned char unk12; // +0x12
    volatile unsigned char unk13; // +0x13
    volatile unsigned char unk14; // +0x14
    volatile unsigned char unk15; // +0x15
    volatile unsigned char unk16; // +0x16
    volatile unsigned char unk17; // +0x17
    volatile unsigned char unk18; // +0x18
    volatile unsigned char unk19; // +0x19
    volatile unsigned char unk1a; // +0x1a
    volatile unsigned char unk1b; // +0x1b
    volatile unsigned char unk1c; // +0x1c
    volatile unsigned char unk1d; // +0x1d
    volatile unsigned char unk1e; // +0x1e
    volatile unsigned char unk1f; // +0x1f
    volatile unsigned char unk20; // +0x20
    volatile unsigned char unk21; // +0x21
    volatile unsigned char unk22; // +0x22
    volatile unsigned char unk23; // +0x23
    volatile unsigned char unk24; // +0x24
    volatile unsigned char unk25; // +0x25
    volatile unsigned char unk26; // +0x26
    volatile unsigned char unk27; // +0x27
    volatile unsigned char unk28; // +0x28
    volatile unsigned char unk29; // +0x29
    volatile unsigned char unk2a; // +0x2a
    volatile unsigned char unk2b; // +0x2b
    volatile unsigned char unk2c; // +0x2c
    volatile unsigned char unk2d; // +0x2d
    volatile unsigned char unk2e; // +0x2e
    volatile unsigned char unk2f; // +0x2f
    volatile unsigned char unk30; // +0x30
    volatile unsigned char unk31; // +0x31
    volatile unsigned char unk32; // +0x32
    volatile unsigned char unk33; // +0x33
    volatile unsigned char unk34; // +0x34
    volatile unsigned char unk35; // +0x35
    volatile unsigned char unk36; // +0x36
    volatile unsigned char unk37; // +0x37
    volatile unsigned char unk38; // +0x38
    volatile unsigned char unk39; // +0x39
    volatile unsigned char unk3a; // +0x3a
    volatile unsigned char unk3b; // +0x3b
    volatile unsigned char unk3c; // +0x3c
    volatile unsigned char unk3d; // +0x3d
    volatile unsigned char unk3e; // +0x3e
    volatile unsigned char unk3f; // +0x3f
    volatile unsigned char unk40; // +0x40
    volatile unsigned char unk41; // +0x41
    volatile unsigned char unk42; // +0x42
    volatile unsigned char unk43; // +0x43
    volatile unsigned char unk44; // +0x44
    volatile unsigned char unk45; // +0x45
    volatile unsigned char unk46; // +0x46
    volatile unsigned char unk47; // +0x47
    volatile unsigned char unk48; // +0x48
    volatile unsigned char unk49; // +0x49
    volatile unsigned char unk4a; // +0x4a
    volatile unsigned char unk4b; // +0x4b
    volatile unsigned char unk4c; // +0x4c
    volatile unsigned char unk4d; // +0x4d
    volatile unsigned char unk4e; // +0x4e
    volatile unsigned char unk4f; // +0x4f
    volatile unsigned char unk50; // +0x50
    volatile unsigned char unk51; // +0x51
    volatile unsigned char unk52; // +0x52
    volatile unsigned char unk53; // +0x53
    volatile unsigned char unk54; // +0x54
    volatile unsigned char unk55; // +0x55
    volatile unsigned char unk56; // +0x56
    volatile unsigned char unk57; // +0x57
    volatile unsigned char unk58; // +0x58
    volatile unsigned char unk59; // +0x59
    volatile unsigned char unk5a; // +0x5a
    volatile unsigned char unk5b; // +0x5b
    volatile unsigned char unk5c; // +0x5c
    volatile unsigned char unk5d; // +0x5d
    volatile unsigned char unk5e; // +0x5e
    volatile unsigned char unk5f; // +0x5f
    volatile unsigned char unk60; // +0x60
    volatile unsigned char unk61; // +0x61
    volatile unsigned char unk62; // +0x62
    volatile unsigned char unk63; // +0x63
    volatile unsigned char unk64; // +0x64
    volatile unsigned char unk65; // +0x65
    volatile unsigned char unk66; // +0x66
    volatile unsigned char unk67; // +0x67
    volatile unsigned char unk68; // +0x68
    volatile unsigned char unk69; // +0x69
    volatile unsigned char unk6a; // +0x6a
    volatile unsigned char unk6b; // +0x6b
    volatile unsigned char unk6c; // +0x6c
    volatile unsigned char unk6d; // +0x6d
    volatile unsigned char unk6e; // +0x6e
    volatile unsigned char unk6f; // +0x6f
    volatile unsigned char unk70; // +0x70
    volatile unsigned char unk71; // +0x71
    volatile unsigned char unk72; // +0x72
    volatile unsigned char unk73; // +0x73
    volatile unsigned char unk74; // +0x74
    volatile unsigned char unk75; // +0x75
    volatile unsigned char unk76; // +0x76
    volatile unsigned char unk77; // +0x77
    volatile unsigned char unk78; // +0x78
    volatile unsigned char unk79; // +0x79
    volatile unsigned char unk7a; // +0x7a
    volatile unsigned char unk7b; // +0x7b
    volatile unsigned char unk7c; // +0x7c
    volatile unsigned char unk7d; // +0x7d
    volatile unsigned char unk7e; // +0x7e
    volatile unsigned char unk7f; // +0x7f
    volatile unsigned char unk80; // +0x80
    volatile unsigned char unk81; // +0x81
    volatile unsigned char unk82; // +0x82
    volatile unsigned char unk83; // +0x83
    volatile unsigned char unk84; // +0x84
    volatile unsigned char unk85; // +0x85
    volatile unsigned char unk86; // +0x86
    volatile unsigned char unk87; // +0x87
    volatile unsigned char unk88; // +0x88
    volatile unsigned char unk89; // +0x89
    volatile unsigned char unk8a; // +0x8a
    volatile unsigned char unk8b; // +0x8b
    volatile unsigned char unk8c; // +0x8c
    volatile unsigned char unk8d; // +0x8d
    volatile unsigned char unk8e; // +0x8e
    volatile unsigned char unk8f; // +0x8f
    volatile unsigned short m_90; // +0x90
    volatile unsigned char m_92; // +0x92
    volatile unsigned char unk93; // +0x93
    unsigned short m_94; // +0x94
    unsigned short m_96; // +0x96
    volatile unsigned char unk98; // +0x98
    volatile unsigned char unk99; // +0x99
    volatile unsigned char unk9a; // +0x9a
    volatile unsigned char unk9b; // +0x9b
    volatile unsigned char unk9c; // +0x9c
    volatile unsigned char unk9d; // +0x9d
    volatile unsigned char unk9e; // +0x9e
    volatile unsigned char unk9f; // +0x9f
    volatile unsigned char unka0; // +0xa0
    volatile unsigned char unka1; // +0xa1
    volatile unsigned char unka2; // +0xa2
    volatile unsigned char unka3; // +0xa3
    volatile unsigned char unka4; // +0xa4
    volatile unsigned char unka5; // +0xa5
    volatile unsigned char unka6; // +0xa6
    volatile unsigned char unka7; // +0xa7
    volatile unsigned char unka8; // +0xa8
    volatile unsigned char unka9; // +0xa9
    volatile unsigned char unkaa; // +0xaa
    volatile unsigned char unkab; // +0xab
    volatile unsigned char unkac; // +0xac
    volatile unsigned char unkad; // +0xad
    volatile unsigned char unkae; // +0xae
    volatile unsigned char unkaf; // +0xaf
    volatile unsigned char unkb0; // +0xb0
    volatile unsigned char unkb1; // +0xb1
    volatile unsigned char unkb2; // +0xb2
    volatile unsigned char unkb3; // +0xb3
    volatile unsigned char unkb4; // +0xb4
    volatile unsigned char unkb5; // +0xb5
    volatile unsigned char unkb6; // +0xb6
    volatile unsigned char unkb7; // +0xb7
    volatile unsigned char unkb8; // +0xb8
    volatile unsigned char unkb9; // +0xb9
    volatile unsigned char unkba; // +0xba
    volatile unsigned char unkbb; // +0xbb
    volatile unsigned char unkbc; // +0xbc
    volatile unsigned char unkbd; // +0xbd
    volatile unsigned char unkbe; // +0xbe
    volatile unsigned char unkbf; // +0xbf
    volatile unsigned char unkc0; // +0xc0
    volatile unsigned char unkc1; // +0xc1
    volatile unsigned char unkc2; // +0xc2
    volatile unsigned char unkc3; // +0xc3
    volatile unsigned char unkc4; // +0xc4
    volatile unsigned char unkc5; // +0xc5
    volatile unsigned char unkc6; // +0xc6
    volatile unsigned char unkc7; // +0xc7
    volatile unsigned char unkc8; // +0xc8
    volatile unsigned char unkc9; // +0xc9
    volatile unsigned char unkca; // +0xca
    volatile unsigned char unkcb; // +0xcb
    volatile unsigned char unkcc; // +0xcc
    volatile unsigned char unkcd; // +0xcd
    volatile unsigned char unkce; // +0xce
    volatile unsigned char unkcf; // +0xcf
    volatile unsigned char unkd0; // +0xd0
    volatile unsigned char unkd1; // +0xd1
    volatile unsigned char unkd2; // +0xd2
    volatile unsigned char unkd3; // +0xd3
    volatile unsigned char unkd4; // +0xd4
    volatile unsigned char unkd5; // +0xd5
    volatile unsigned char unkd6; // +0xd6
    volatile unsigned char unkd7; // +0xd7
    volatile unsigned char unkd8; // +0xd8
    volatile unsigned char unkd9; // +0xd9
    volatile unsigned char unkda; // +0xda
    volatile unsigned char unkdb; // +0xdb
    volatile unsigned char unkdc; // +0xdc
    volatile unsigned char unkdd; // +0xdd
    volatile unsigned char unkde; // +0xde
    volatile unsigned char unkdf; // +0xdf
    volatile unsigned short m_e0; // +0xe0
    volatile unsigned char m_e2; // +0xe2
    volatile unsigned char unke3; // +0xe3
    volatile unsigned char m_e4; // +0xe4
    volatile unsigned char unke5; // +0xe5
    volatile unsigned char unke6; // +0xe6
    volatile unsigned char unke7; // +0xe7
    volatile unsigned char unke8; // +0xe8
    volatile unsigned char unke9; // +0xe9
    volatile unsigned char unkea; // +0xea
    volatile unsigned char unkeb; // +0xeb
    volatile unsigned short m_ec; // +0xec
    volatile unsigned char m_ee; // +0xee
    volatile unsigned char unkef; // +0xef
    volatile unsigned char unkf0; // +0xf0
    volatile unsigned char unkf1; // +0xf1
    volatile unsigned char unkf2; // +0xf2
    volatile unsigned char unkf3; // +0xf3
    volatile unsigned char unkf4; // +0xf4
    volatile unsigned char unkf5; // +0xf5
    volatile unsigned char unkf6; // +0xf6
    volatile unsigned char unkf7; // +0xf7
    volatile unsigned char unkf8; // +0xf8
    volatile unsigned char unkf9; // +0xf9
    volatile unsigned char unkfa; // +0xfa
    volatile unsigned char unkfb; // +0xfb
    volatile unsigned char unkfc; // +0xfc
    volatile unsigned char unkfd; // +0xfd
    volatile unsigned char unkfe; // +0xfe
    volatile unsigned char unkff; // +0xff
    volatile unsigned short m_100; // +0x100
    volatile unsigned char m_102; // +0x102
    volatile unsigned char unk103; // +0x103
    volatile unsigned char unk104; // +0x104
    volatile unsigned char unk105; // +0x105
    volatile unsigned char m_106; // +0x106
    volatile unsigned char unk107; // +0x107
    volatile unsigned char unk108; // +0x108
    volatile unsigned char unk109; // +0x109
    volatile unsigned char unk10a; // +0x10a
    volatile unsigned char unk10b; // +0x10b
    volatile unsigned char unk10c; // +0x10c
    volatile unsigned char unk10d; // +0x10d
    volatile unsigned char unk10e; // +0x10e
    volatile unsigned char unk10f; // +0x10f
    volatile unsigned char unk110; // +0x110
    volatile unsigned char unk111; // +0x111
    volatile unsigned char unk112; // +0x112
    volatile unsigned char unk113; // +0x113
    unsigned short m_114; // +0x114
    unsigned char m_116; // +0x116
    volatile unsigned char unk117; // +0x117
    volatile unsigned char unk118; // +0x118
    volatile unsigned char unk119; // +0x119
    volatile unsigned char m_11a; // +0x11a
    volatile unsigned char unk11b; // +0x11b
    volatile unsigned char unk11c; // +0x11c
    volatile unsigned char unk11d; // +0x11d
    volatile unsigned char unk11e; // +0x11e
    volatile unsigned char unk11f; // +0x11f
    volatile unsigned char unk120; // +0x120
    volatile unsigned char unk121; // +0x121
    volatile unsigned char unk122; // +0x122
    volatile unsigned char unk123; // +0x123
    volatile unsigned char unk124; // +0x124
    volatile unsigned char unk125; // +0x125
    volatile unsigned char unk126; // +0x126
    volatile unsigned char unk127; // +0x127
    unsigned short m_128; // +0x128
    volatile unsigned char m_12a; // +0x12a
    CdfSubObject m_12b; // +0x12b
    float m_12c; // +0x12c

    CdfObject* hkpRagdollConstraintData_Atoms_Atoms();
};

// Sets fixed initial values in several fields, initializes m_12b via FUN_00ca9360 with 1.0f, and returns this.
// @fnv 0x00cdf460
// src: HAVOK_LIB 0x00cdf460
CdfObject* CdfObject::hkpRagdollConstraintData_Atoms_Atoms()
{
    float one = 1.0f;
    m_00 = 2;
    m_90 = 0x13;
    m_92 = 1;
    m_94 = 0;
    m_96 = 0;
    m_e2 = 1;
    m_e4 = 1;
    m_e0 = 0x11;
    m_ee = 1;
    m_ec = 0xf;
    m_106 = 0;
    m_102 = 1;
    m_100 = 0x10;
    m_11a = 0;
    m_114 = 0x10;
    m_116 = 1;
    m_12a = 0;
    m_128 = 5;
    m_12b.FindFloatTableIndex(&one);
    m_12c = DAT_0104da48;
    return this;
}

#include <string.h>
struct NamedEntryC136 {
    const char* m_name;
    int m_uiFilterValue;
};

struct ClassInfoC136 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    NamedEntryC136* m_entries;
    int m_iNumberOfEntries;
};

struct NameSetC136 {
    int unk00;
    int unk04;
    unsigned int m_numNames;
    const char** m_ppNames;
    bool ContainsAllNames(const ClassInfoC136* pkInfo);
};

// Returns true if every name in pkInfo's entries is present in this set's m_ppNames, using strcmp for each comparison.
// @fnv 0x00cc1360
bool NameSetC136::ContainsAllNames(const ClassInfoC136* pkInfo)
{
    bool bAllFound = true;
    int iEntryIndex = pkInfo->m_iNumberOfEntries;
    for (int i = 0; i < iEntryIndex && bAllFound; i++) {
        const char* pcName = (const char*)((unsigned int)pkInfo->m_entries[i].m_name & ~1u);
        bool bFound = false;
        for (unsigned int j = 0; j < m_numNames && !bFound; j++) {
            if (strcmp(pcName, m_ppNames[j]) == 0)
                bFound = true;
        }
        if (!bFound)
            bAllFound = false;
    }
    return bAllFound;
}





struct Q1420Entry
{
    int unk00;
    hkMatrix3* unk04;
};

struct Q1420Item
{
    const char* unk00;
    int unk04;
};

struct Q1420Source
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Q1420Item* unk18;
    int unk1C;
};

struct Q1420Helper
{
    int unk00;
    int unk04;
    unsigned int unk08;
    const char** unk0C;
    int unk10;
    Q1420Entry** unk14;

    void bhkPoseArray_CreatePoseForRagdoll(hkMatrix3* dest, Q1420Source* source, int index);
};

// For each source item whose name matches an entry in this->unk0C, copies a hkMatrix3 from this->unk14[index]->unk04 into dest[i].
// @fnv 0x00cc1420
// src: COMMUNITY 0x00cc1420
void Q1420Helper::bhkPoseArray_CreatePoseForRagdoll(hkMatrix3* dest, Q1420Source* source, int index)
{
    int count = source->unk1C;
    for (int i = 0; i < count; i++)
    {
        const char* name = (const char*)((unsigned int)source->unk18[i].unk00 & 0xFFFFFFFEu);
        bool found = false;
        unsigned int j;
        for (j = 0; j < unk08; j++)
        {
            if (found)
                break;
            if (strcmp(name, unk0C[j]) == 0)
                found = true;
        }
        if (found)
        {
            const hkMatrix3& sourceMatrix = unk14[index]->unk04[j - 1];
            dest[i].m_kColumn0.m_vComponents = sourceMatrix.m_kColumn0.m_vComponents;
            dest[i].m_kColumn1.m_vComponents = sourceMatrix.m_kColumn1.m_vComponents;
            dest[i].m_kColumn2.m_vComponents = sourceMatrix.m_kColumn2.m_vComponents;
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char DAT_010c94a4, DAT_010c9498, str_010c9488;
extern "C" unsigned int DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* name);
struct FUN_00a7b2e0 {
 unsigned int unk04, unk08;

 FUN_00a7b2e0();
 virtual ~FUN_00a7b2e0();
};
inline ExtraMember_blk_00cc0000_o2::ExtraMember_blk_00cc0000_o2() { unk14=0; count=1; unk18=0; unk1c=0; unk10=0; vptr=&DAT_010c9498; }
struct NameRef {
 char* name;
 NameRef(const char* n) { name=FUN_00a5b690(n); }
 ~NameRef() throw() { if ((unsigned int)name!=DAT_0109b220) InterlockedDecrement((long volatile*)(name-8)); }
};
struct FUN_00cc1d80 : FUN_00a7b2e0 {
 ExtraMember_blk_00cc0000_o2 member;

 void AssignFixedString(const void*);
 FUN_00cc1d80();
 ~FUN_00cc1d80();
};
// Constructs the object and calls AssignFixedString with a name reference built from the string at str_010c9488.
// @fnv 0x00cc1d80
FUN_00cc1d80::FUN_00cc1d80() {

 AssignFixedString(&NameRef(&str_010c9488));
}

class CC4180Base {
public:
    virtual ~CC4180Base();

    void Shutdown();
};

class FUN_00cc4180 : public CC4180Base {
public:
    virtual ~FUN_00cc4180();

    static unsigned int ms_uiInstances;
};

// Calls Shutdown and decrements the static instance counter ms_uiInstances.
// @fnv 0x00cc4180
FUN_00cc4180::~FUN_00cc4180()
{
    Shutdown();
    --ms_uiInstances;
}

class CC47F0Base {
public:
    virtual ~CC47F0Base();
};

extern int g_iCC47F0Count;

class FUN_00cc47f0 : public CC47F0Base {
public:
    void Release();

    virtual ~FUN_00cc47f0();
};

// Destructor that calls Release and decrements the global g_iCC47F0Count.
// @fnv 0x00cc47f0
FUN_00cc47f0::~FUN_00cc47f0() {
    Release();
    --g_iCC47F0Count;
}

extern "C" void __cdecl operator_delete_sized(void* pvMem, unsigned int uiSize);

class FUN_00cc7e50 {
public:
    FUN_00cc7e50();
    virtual ~FUN_00cc7e50();

    static void operator delete(void* pvMem, unsigned int uiSize) { operator_delete_sized(pvMem, uiSize); }

    int unk04;
    int unk08;
    int unk0C;
};

// @fnv 0x00cc7e50
FUN_00cc7e50::FUN_00cc7e50()
{
}

struct FUN_00cc9dd0 {
    FUN_00cc9dd0();
    virtual ~FUN_00cc9dd0();

    static void operator delete(void* p, unsigned int size);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

// @fnv 0x00cc9dd0
FUN_00cc9dd0::FUN_00cc9dd0()
{
}

struct FUN_00ccbb50 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~FUN_00ccbb50();
    static void operator delete[](void* p) { g_memoryManager.Deallocate(p); }
};

class FUN_00ccc720 : public NiReferenceState {
public:
    unsigned int unk08;
    FUN_00ccbb50* entries;
    virtual ~FUN_00ccc720();
};

// Destructor that deletes the entries array inside an AutoMemContext(16) scope.
// @fnv 0x00ccc720
FUN_00ccc720::~FUN_00ccc720() {
    AutoMemContext context(16);
    delete[] entries;
}

namespace fnv_00cd3ad0 {

struct CD3AD0MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};

extern "C" CD3AD0MemoryRouter& __cdecl hkMemoryRouter_getInstance();

class FUN_00cd3ad0 {
// @fnv 0x00cd3ad0
public:
    FUN_00cd3ad0() {}
    virtual ~FUN_00cd3ad0();

    static void* operator new(unsigned int, void* p) { return p; }
    static void operator delete(void*, void*) {}
    static void operator delete(void* p, unsigned int nbytes)
    {
        if (p)
            hkMemoryRouter_getInstance().heap().blockFree(p, nbytes);
    }

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
};

void* CD3AD0Construct(void* pvMem)
{
    return new (pvMem) FUN_00cd3ad0;
}
}  // namespace fnv_00cd3ad0

extern "C" unsigned __int64 __rdtsc(void);
extern "C" int DAT_0126835c;
extern "C" void* DAT_00fdf044;

struct FUN_00cdfe00_Object {
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
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual int* vf40();
};

void __cdecl hkpWorldConstraintUtil_removeAndDeleteModifier(int* a, FUN_00cdfe00_Object* b, int c);

typedef void* (__stdcall *TlsGetValueFunc)(int);

// If vf40 returns non-null, calls vf18 on param2, logs a TtClrSurfVel TLS entry, calls FUN_00d27690(result, param2, 0x1a), then logs an Et entry.
// @fnv 0x00cdfe00
// src: HAVOK_LIB 0x00cdfe00
void hkpResponseModifier_clearSurfaceVelocity(FUN_00cdfe00_Object* param1, FUN_00cdfe00_Object* param2) {
    int* result = param1->vf40();
    if (result != 0) {
        param2->vf18();

        TlsGetValueFunc getTls = reinterpret_cast<TlsGetValueFunc>(DAT_00fdf044);
        char* pTlsBuffer = reinterpret_cast<char*>(getTls(DAT_0126835c));

        char* entry = *reinterpret_cast<char**>(pTlsBuffer + 4);
        if (entry < *reinterpret_cast<char**>(pTlsBuffer + 0xC)) {
            *reinterpret_cast<const char**>(entry) = "TtClrSurfVel";
            _ReadWriteBarrier();
            volatile unsigned int timestamp = __rdtsc();
            *reinterpret_cast<unsigned int*>(entry + 4) = timestamp;
            *reinterpret_cast<char**>(pTlsBuffer + 4) = entry + 12;
        }

        hkpWorldConstraintUtil_removeAndDeleteModifier(result, param2, 0x1a);

        pTlsBuffer = reinterpret_cast<char*>(getTls(DAT_0126835c));
        entry = *reinterpret_cast<char**>(pTlsBuffer + 4);
        if (entry < *reinterpret_cast<char**>(pTlsBuffer + 0xC)) {
            *reinterpret_cast<const char**>(entry) = "Et";
            _ReadWriteBarrier();
            volatile unsigned int timestamp = __rdtsc();
            *reinterpret_cast<unsigned int*>(entry + 4) = timestamp;
            *reinterpret_cast<char**>(pTlsBuffer + 4) = entry + 12;
        }
    }
}

struct RagdollConstraintData {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    LocalM128 axisA;
    LocalM128 planeA;
    LocalM128 binormalA;
    LocalM128 pivotA;
    LocalM128 axisB;
    LocalM128 planeB;
    LocalM128 binormalB;
    LocalM128 pivotB;
    unsigned short atomType;
    unsigned char enabled;
    unsigned char unk0a3;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    float maxFrictionTorque;
    unsigned int unk0fc;
    unsigned int unk100;
    float twistMin;
    float twistMax;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    float coneMax;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    float planeMin;
    float planeMax;
    void hkpRagdollConstraintData_setTwistMotor(hkReferencedObject*);
    void hkpRagdollConstraintData_setPlaneMotor(hkReferencedObject*);
    void hkpRagdollConstraintData_setConeMotor(hkReferencedObject*);
};

struct FUN_00d53200_class {
    void* vtable;
    RagdollConstraintData* data;
    void hkConstraintCinfo_LoadBinary(NiStream&);
    hkReferencedObject* hkConstraintCinfo_LoadMotor(NiStream&);
    void hkRagdollConstraintCinfo_LoadBinary(NiStream&);
};

extern const float DAT_01011d78;
extern const float DAT_01016248;
extern const float DAT_01017718;
__forceinline void Normalize(LocalM128& v) {
    LocalM128 vector = v;
    LocalM128 squared = _mm_mul_ps(vector,vector);
    LocalM128 sum = _mm_shuffle_ps(squared,squared,0x55);
    sum = _mm_add_ss(sum,squared);
    squared = _mm_shuffle_ps(squared,squared,0xaa);
    sum = _mm_add_ss(squared,sum);
    LocalM128 reciprocal = _mm_rsqrt_ss(sum);
    LocalM128 zero = _mm_set_ss(0.0f);
    LocalM128 three = _mm_set_ss(3.0f);
    LocalM128 half = _mm_set_ss(0.5f);
    LocalM128 correction = _mm_mul_ss(sum,reciprocal);
    correction = _mm_mul_ss(correction,reciprocal);
    correction = _mm_sub_ss(three,correction);
    LocalM128 scale = _mm_mul_ss(half,reciprocal);
    scale = _mm_mul_ss(scale,correction);
    sum = _mm_cmpeq_ss(sum,zero);
    scale = _mm_andnot_ps(sum,scale);
    scale = _mm_shuffle_ps(scale,scale,0);
    v = _mm_mul_ps(scale,vector);
}

// Reads constraint axes and limits, defaults zero friction torque to 100, normalizes four vectors, and for stream version above 29 may read an enabled byte.
// @fnv 0x00cc6b80
// src: XBOX_PDB 0x00cc6b80
void FUN_00d53200_class::hkRagdollConstraintCinfo_LoadBinary(NiStream& stream)
{
    (void)stream;
    hkConstraintCinfo_LoadBinary(stream);
    RagdollConstraintData* constraint = data;
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->axisA), 64);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->axisB), 64);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->coneMax), 4);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->planeMin), 4);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->planeMax), 4);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->twistMin), 4);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->twistMax), 4);
    InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->maxFrictionTorque), 4);
    if (constraint->maxFrictionTorque == 0.0f)
        constraint->maxFrictionTorque = 100.0f;
    Normalize(constraint->planeA);
    Normalize(constraint->axisA);
    Normalize(constraint->planeB);
    Normalize(constraint->axisB);
    if (StreamField<unsigned int>(stream, 4) > 29) {
        hkReferencedObject* object = hkConstraintCinfo_LoadMotor(stream);
        constraint->hkpRagdollConstraintData_setTwistMotor(object);
        constraint->hkpRagdollConstraintData_setPlaneMotor(object);
        constraint->hkpRagdollConstraintData_setConeMotor(object);
        if (object) {
            InputStream(stream)->BinaryRead(static_cast<void*>(&constraint->enabled),1);
            object->removeReference();
        }
    }
}

namespace fnv_00cc8e60 {
struct ReadIO {
    int unk00;
    unsigned int m_04;
    unsigned int (__cdecl *m_08)(ReadIO*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p) { unsigned int size = 4; unsigned int n = m_08(this, p, 4, &size, 1); m_04 += n; return n; }
};

struct ReadData {
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

    void __thiscall Push(void* first, void* second);
};

struct ReadContext {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    ReadIO* io;
};

void __cdecl bhkStream_LoadBinary(void* owner, void* data);



struct FUN_00d53200_class {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();

    ReadData* m_04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4* m_20;
    int m_24;

    void hkConstraintChainCinfo_LoadBinary(NiStream&);
    void __thiscall hkBallSocketChainCinfo_LoadBinary(ReadContext* owner);
};

// Calls vf10 and FUN_00cf0f40, passes m_20 entries in pairs to Push, reads four fields via io, then calls FUN_00d53200.
// @fnv 0x00cc8e60
// src: XBOX_PDB 0x00cc8e60
void FUN_00d53200_class::hkBallSocketChainCinfo_LoadBinary(ReadContext* owner)
{
    vf10();

    bhkStream_LoadBinary(owner, &m_20);

    ReadData* pReadData = m_04;
    int index = 0;
    while (index < m_24) {
        pReadData->Push(&m_20[index], &m_20[index + 1]);
        index += 2;
    }

    owner->io->Read(&pReadData->unk28);
    owner->io->Read(&pReadData->unk24);
    owner->io->Read(&pReadData->unk2C);
    owner->io->Read(&pReadData->unk30);
    hkConstraintChainCinfo_LoadBinary(*reinterpret_cast<NiStream*>(owner));
}
}  // namespace fnv_00cc8e60

struct CopyAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& bytes);
    virtual void ReleaseBlock(void* data, int bytes);
};

struct CopyArray {
    LocalM128* data;
    int size;
    int capacity;
};

struct CopyOutput {
    int unk00;
    int unk04;
    CopyArray vertices;
    CopyArray planes;
};

struct CopyShape {
    void FUN_00d59200(CopyArray*);
    const CopyArray& FUN_00d58d50();
};

struct CopyOwner {
    int unk00;
    int unk04;
    CopyShape* shape;
    void bhkConvexShape_CopyCinfo(CopyOutput*);
    void bhkConvexVerticesShape_CopyCinfo(CopyOutput* out);
};

// Fills the output's vertices through the shape, then copies the shape's array into the output's planes buffer, growing it if capacity is too small.
// @fnv 0x00cce010
// src: XBOX_PDB 0x00cce010
void CopyOwner::bhkConvexVerticesShape_CopyCinfo(CopyOutput* apOutput)
{
    bhkConvexShape_CopyCinfo(apOutput);
    CopyShape* p = this ? shape : 0;
    if (p) {
        p->FUN_00d59200(&apOutput->vertices);
        const CopyArray& src = p->FUN_00d58d50();
        CopyAllocator* alloc = reinterpret_cast<CopyAllocator*>(hkMemoryRouter_getInstance()->unk10);
        int cap = apOutput->planes.capacity & 0x3fffffff;
        if (cap < src.size) {
            if ((apOutput->planes.capacity & 0x80000000) == 0)
                alloc->ReleaseBlock(apOutput->planes.data, cap * 16);
            int bytes = src.size * 16;
            apOutput->planes.data = static_cast<LocalM128*>(alloc->AllocateBufferWithSize(bytes));
            apOutput->planes.capacity = bytes / 16;
        }
        int count = src.size;
        apOutput->planes.size = count;
        LocalM128* dst = apOutput->planes.data;
        const LocalM128* input = src.data;
        for (int i = 0; i < count; ++i)
            dst[i] = input[i];
    }
}

extern float DAT_0104da48;

struct ContactSource {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28;
    unsigned int m_uiCollisionFilterData;
    void FUN_00c905b0();
};

struct ContactHit;

struct ContactListener {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void OnEnter(ContactHit* hit);
    virtual void OnStay(ContactHit* hit);
};

struct ContactHandler {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    ContactListener* m_kListener;
};

struct ContactUser {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    ContactHandler* m_handler;
};

struct ContactOwner {
    int unk00; int unk04;
    ContactUser* m_user;
    void* getUserData() const { return m_user; }
};

struct ContactCollidable;
__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out);
struct ContactCollidable {
    int unk00; int unk04; int unk08; int unk0C;
    signed char m_iOwnerOffset;
    void* getOwner() const { return (char*)this + m_iOwnerOffset; }
};

struct ContactHit {
    int m_00; int m_04; int m_08; int m_0c;
    int m_10; int m_14; int m_18; int m_1c;
    int m_20; int m_24; int m_28; int m_2c;
    int m_30; int m_34; int m_38; int m_3c;
    int m_40; int m_44;
    ContactCollidable* m_kCollidable;
    int m_4c;
    int m_50; int m_54; int m_58; int m_5c;
    int m_60; int m_64; int m_68; int m_6c;
};

struct CopyBlock8 {
    unsigned int m_ucLowNibble;
    unsigned int m_ucHighNibble;
};

template <int N> struct MemCpyAligned {
    static __forceinline void copy(void* dst, const void* src)
    {
        const CopyBlock8* s = (const CopyBlock8*)src;
        CopyBlock8* d = (CopyBlock8*)dst;
        for (int i=0; i<N/8; i++) d[i]=s[i];
        if (N==4) *(unsigned int*)dst=*(const unsigned int*)src;
    }
};

__forceinline void getUserOut(const ContactCollidable* c, ContactUser*& out)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    out = owner ? owner->m_user : 0;
}

__forceinline void* getUserData(const ContactCollidable* c)
{
    const ContactOwner* owner = (const ContactOwner*)c->getOwner();
    return owner ? owner->getUserData() : 0;
}

__forceinline ContactUser* getUser(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    return owner ? owner->m_user : 0;
}

__forceinline ContactUser* getUser2(const ContactCollidable* c)
{
    ContactOwner* owner = (ContactOwner*)c->getOwner();
    if (!owner) {
        return 0;
    }
    return owner->m_user;
}

template <class T>
struct ContactArray { // local form of hkArrayBase: 0x00cd32b0 needs its local removeAt copy-helper split; the shared form changes extent from 352 to 254 bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index) {
            MemCpyAligned<sizeof(T)>::copy(&m_data[index], &m_data[m_iElementCount]);
        }
    }
};

struct TriggerCollector : FUN_00cd3410 {
    ContactArray<ContactSource*>& sources() { return *(ContactArray<ContactSource*>*)&m_a1; }
    ContactArray<int>& states() { return *(ContactArray<int>*)&m_a2; }
    ContactArray<ContactHit>& hits() { return *(ContactArray<ContactHit>*)&m_a3; }
    void ProcessContactEvents();
};

// Resets the hit count, dispatches OnEnter/OnStay for layer 14/16 contacts, then removes entries whose state is 1 and sets the others to 1.
// @fnv 0x00cd32b0
void TriggerCollector::ProcessContactEvents()
{
    double val = DAT_0104da48;
    int& cnt=m_iHitsSize;
    cnt = 0;
    m_fEarlyOutDistance = (float)val;
    int i;
    for (i = 0; i < states().GetLogicalSize(); i++) {
        unsigned int layer = sources()[i]->m_uiCollisionFilterData & 0x7f;
        ContactOwner* owner = (ContactOwner*)hits()[i].m_kCollidable->getOwner();
        void* ud = owner ? owner->getUserData() : 0;
        ContactUser* user = (ContactUser*)ud;
        if (user) {
            ContactHandler* handler = user->m_handler;
            if (handler) {
                switch (layer) {
                case 14:
                case 16: {
                    ContactListener* listener = handler->m_kListener;
                    if (listener) {
                        int state = states()[i];
                        if (state == 0) {
                            listener->OnEnter(&hits()[i]);
                        } else if (state == 1) {
                            listener->OnStay(&hits()[i]);
                        }
                    }
                    break;
                }
                }
            }
        }
    }
    for (i = states().GetLogicalSize() - 1; i >= 0; i--) {
        if (states()[i] == 1) {
            sources()[i]->FUN_00c905b0();
            sources().removeAt(i);
            hits().removeAt(i);
            states().removeAt(i);
        } else {
            states()[i] = 1;
        }
    }
}


using ::_mm_add_ps;
using ::_mm_add_ss;
using ::_mm_sub_ps;
using ::_mm_mul_ps;
using ::_mm_rcp_ps;
using ::_mm_and_ps;
using ::_mm_xor_ps;
using ::_mm_unpackhi_ps;

extern const LocalM128 DAT_010c71e0;
extern const LocalM128 DAT_010c7170;
extern const LocalM128 DAT_010c44d0;
extern const LocalM128 DAT_010c4c00;
extern const LocalM128 DAT_010c4c10;


// Quaternion storage is four words in the checked header; access those words as its SIMD vector.
__forceinline hkVector4& QuaternionVector(hkQuaternion& q) { return *reinterpret_cast<hkVector4*>(&q); }
__forceinline const hkVector4& QuaternionVector(const hkQuaternion& q) { return *reinterpret_cast<const hkVector4*>(&q); }
__forceinline LocalM128 PoseDot3(const hkVector4& a, const hkVector4& b)
{
    LocalM128 x2 = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
}
__forceinline void hkVector4::addMul4(LocalM128 s, const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
}
__forceinline void hkVector4::setNeg4(const hkVector4& a) { m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0); }
__forceinline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2), _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline void hkQuaternion::SetConjugate(const hkQuaternion& q)
{
    QuaternionVector(*this).m_vComponents = _mm_xor_ps(QuaternionVector(q).m_vComponents, DAT_010c4c00);
}
// src: COMMUNITY 0x00c66320
__declspec(noinline) void hkQuaternion::setMul(const hkQuaternion& a, const hkQuaternion& b)
{
    struct RawVector { LocalM128 value; };
    RawVector storage;
    hkVector4& imaginary = *(hkVector4*)&storage;
    imaginary.setCross(QuaternionVector(a), QuaternionVector(b));
    LocalM128 aw = _mm_shuffle_ps(QuaternionVector(a).m_vComponents, QuaternionVector(a).m_vComponents, 0xff);
    LocalM128 bw = _mm_shuffle_ps(QuaternionVector(b).m_vComponents, QuaternionVector(b).m_vComponents, 0xff);
    imaginary.m_vComponents = _mm_add_ps(imaginary.m_vComponents, _mm_mul_ps(aw, QuaternionVector(b).m_vComponents));
    imaginary.m_vComponents = _mm_add_ps(imaginary.m_vComponents, _mm_mul_ps(bw, QuaternionVector(a).m_vComponents));
    LocalM128 dot = PoseDot3(QuaternionVector(a), QuaternionVector(b));
    dot = _mm_shuffle_ps(dot, dot, 0);
    LocalM128 real = _mm_sub_ps(_mm_mul_ps(QuaternionVector(a).m_vComponents, QuaternionVector(b).m_vComponents), dot);
    QuaternionVector(*this).m_vComponents = _mm_shuffle_ps(imaginary.m_vComponents, _mm_unpackhi_ps(imaginary.m_vComponents, real), 0xc4);
}

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, 0xff);
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    LocalM128 imagDotDir = PoseDot3(QuaternionVector(quat), direction);
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(QuaternionVector(quat), direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(QuaternionVector(quat).m_vComponents, QuaternionVector(quat).m_vComponents, 0xff);
    hkVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4 ret;
    ret.setMul4(direction, q2minus1);
    LocalM128 imagDotDir = PoseDot3(QuaternionVector(quat), direction);
    ret.addMul4(imagDotDir, QuaternionVector(quat));
    hkVector4 imagCrossDir;
    imagCrossDir.setCross(direction, QuaternionVector(quat));
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

// Temporary inverse translation/rotation/scale used only by pose multiplication.
struct InversePoseTransform
{
    hkVector4 m_vTranslation;
    __declspec(align(16)) hkQuaternion m_rotation;
    hkVector4 m_vScale;
};

__forceinline void InvertPoseTransform(InversePoseTransform& inverse, const hkQsTransform& t)
{
    inverse.m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
    inverse.m_vTranslation.setNeg4(inverse.m_vTranslation);
    inverse.m_rotation.SetConjugate(t.m_rotation);
    hkVector4 scale;
    scale.m_vComponents = _mm_shuffle_ps(t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), 0xc4);
    inverse.m_vScale.setReciprocal4(scale);
    inverse.m_vScale.m_vComponents = _mm_and_ps(inverse.m_vScale.m_vComponents, DAT_010c4c10);
}
__forceinline void MultiplyInversePose(hkQsTransform& result, const InversePoseTransform& t1, const hkQsTransform& t2)
{
    hkVector4 temp;
    temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
    result.m_vTranslation.setAdd4(temp, t1.m_vTranslation);
    result.m_rotation.setMul(t1.m_rotation, t2.m_rotation);
    result.m_vScale.m_vComponents = _mm_mul_ps(t2.m_vScale.m_vComponents, t1.m_vScale.m_vComponents);
}
__forceinline hkQuaternion::hkQuaternion() {}

__forceinline void hkQsTransform::SetMulInverse(const hkQsTransform& a, const hkQsTransform& b)
{
    InversePoseTransform inverse;
    InvertPoseTransform(inverse, a);
    MultiplyInversePose(*this, inverse, b);
}
__forceinline void hkQsTransform::operator=(const hkQsTransform& t)
{
    m_vTranslation.m_vComponents = t.m_vTranslation.m_vComponents;
    QuaternionVector(m_rotation).m_vComponents = QuaternionVector(t.m_rotation).m_vComponents;
    m_vScale.m_vComponents = t.m_vScale.m_vComponents;
}





__forceinline void hkaPose::makeFirstChildrenModelSpace(int boneIdx)
{
    const int nb = m_pSkeleton->m_kBones.m_iElementCount;
    for (int b = boneIdx + 1; b < nb; ++b)
    {
        const int i = b;
        if (m_pSkeleton->m_kParentIndices.m_data[i] == boneIdx)
        {
            if (m_pBoneFlags[i] & F_DIRTY_MODEL)
                hkaPose_calculateBoneModelSpace(i);
            m_pBoneFlags[i] = F_DIRTY_LOCAL;
            m_bPoseInitialized = false;
        }
    }
}

__forceinline const hkQsTransform& hkaPose::calculateBoneLocalSpace(int boneIdx)
{
    const hkQsTransform& modelFromBone = m_pModelPose[boneIdx];
    const short parentIdx = m_pSkeleton->m_kParentIndices.m_data[boneIdx];
    if (parentIdx != -1)
    {
        const hkQsTransform& modelFromParent = isFlagOn(parentIdx, F_DIRTY_MODEL) == 0
            ? m_pModelPose[parentIdx] : hkaPose_calculateBoneModelSpace(parentIdx);
        m_pLocalPose[boneIdx].SetMulInverse(modelFromParent, modelFromBone);
    }
    else
    {
        m_pLocalPose[boneIdx] = m_pModelPose[boneIdx];
    }
    clearFlag(boneIdx, F_DIRTY_LOCAL);
    return m_pLocalPose[boneIdx];
}

__forceinline void hkaPose::makeAllChildrenLocalSpace(int boneIdx)
{
    const int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    setFlag(boneIdx, F_INTERNAL1);
    for (int i = boneIdx + 1; i < numBones; ++i)
    {
        const short parentIdx = m_pSkeleton->m_kParentIndices.m_data[i];
        if (parentIdx != -1 && isFlagOn(parentIdx, F_INTERNAL1))
        {
            if (isFlagOn(i, F_DIRTY_LOCAL))
                calculateBoneLocalSpace(i);
            setFlag(i, F_INTERNAL1);
            m_bPoseFlag = false;
        }
    }
    for (int i = boneIdx + 1; i < numBones; ++i)
    {
        unsigned int& f = m_pBoneFlags[i];
        if (f & F_INTERNAL1)
            f = (f & ~F_INTERNAL1) | F_DIRTY_MODEL;
    }
}

// Updates child bone flags (mode chosen by propagate), recalculates the bone's model pose if dirty, sets its flags to local-dirty, and returns the model pose.
// @fnv 0x00cdad80
// src: COMMUNITY 0x00cdad80
hkQsTransform& hkaPose::accessBoneModelSpace(int boneIdx, int propagate)
{
    if (propagate == 0)
        makeFirstChildrenModelSpace(boneIdx);
    else
        makeAllChildrenLocalSpace(boneIdx);
    if (m_pBoneFlags[boneIdx] & F_DIRTY_MODEL)
        hkaPose_calculateBoneModelSpace(boneIdx);
    m_pBoneFlags[boneIdx] = F_DIRTY_LOCAL;
    m_bPoseInitialized = false;
    return m_pModelPose[boneIdx];
}

namespace fnv_00cc1cf0 {
#include <windows.h>

// Stand-in for the game's NiTimeController: a reference-counted, polymorphic
// object whose reference counter lives at +4 and whose "release" virtual sits
// in the second vtable slot.
struct FNV_TCtrl {
    virtual void FNV_v0();
    virtual void FNV_Release();
    virtual void DecRefCount();
    virtual void IncRefCount();
    unsigned int m_uiRefCount;
};

// Stand-in for the game's NiTLargeArray<NiPointer<NiTimeController> >.
struct FNV_TCtrlArray {
    void** m_ppVirtualMethodTable;
    NiPointer<FNV_TCtrl>* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void ReleaseReference_00cc1cf0();
};

// Releases every element in the array by decrementing ref counts and calling FNV_Release when the count reaches zero, then resets m_uiSize and m_uiESize.
// @fnv 0x00cc1cf0
// src: GUESS 0x00cc1cf0 (confidence: medium)
void FNV_TCtrlArray::ReleaseReference_00cc1cf0() {
    for (unsigned int i = 0; i < m_uiSize; i++) {
        NiPointer<FNV_TCtrl> ptr;
        NiPointer<FNV_TCtrl>* pElem = &m_pBase[i];
        FNV_TCtrl* pCtrl = pElem->m_pObject;
        if (pCtrl) {
            if (InterlockedDecrement((volatile LONG*)&pCtrl->m_uiRefCount) == 0) {
                pCtrl->FNV_Release();
            }
            pElem->m_pObject = 0;
        }
    }
    m_uiSize = 0;
    m_uiESize = 0;
}
}  // namespace fnv_00cc1cf0

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" int DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern char DAT_010c9544[];
extern char DAT_010c41f8[];

struct Key4
{
    int v;
    Key4(const Key4& other) : v(other.v) {}
};

struct Mat4
{
    LocalM128 rows[4];
};

struct ObjInfo
{
    LocalM128 point;
    float dist;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
};

struct Query
{
    int f00;
    int f04;
    int f08;
    int f0c;
    ObjInfo info;
};

struct PointPair
{
    LocalM128 p0;
    LocalM128 p1;
    int key;
    int filter;
};

struct HitBool
{
    unsigned char value;
    HitBool(bool b) : value(b) {}
    operator bool() const { return value != 0; }
};

class PickObj
{
public:
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual HitBool TestInfo(PointPair *pts, ObjInfo *info);
};

struct Entry
{
    PickObj *obj;
    int f04;
    Mat4 *mat;
    int f0c;
    int f10;
    int f14;
    int f18;
    Key4 key;
};

struct EntryPair
{
    int first;
    Entry *second;
};

struct SubObj
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c;
    int f20, f24, f28, f2c, f30, f34, f38, f3c;
    int f40, f44, f48, f4c, f50, f54, f58, f5c;
    int f60, f64, f68, f6c, f70, f74, f78;
    int f7c;
};

struct RayArg
{
    LocalM128 p0;
    LocalM128 p1;
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    unsigned char f23;
    Key4 key;
};

struct BestOut
{
    LocalM128 v;
    float f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    Entry *entry;
};

bool __cdecl bhkCollisionFilter_IsCollisionEnabled(Key4 a, Key4 b);
void __stdcall hkVector4_setRotatedDir(void *a, BestOut *b);

struct Rotation3 { LocalM128 a, b, c; };

static __forceinline void Transpose(Rotation3& out, const Mat4* m)
{
    LocalM128 r0 = m->rows[0];
    LocalM128 r1 = m->rows[1];
    LocalM128 r2 = m->rows[2];
    LocalM128 lo = _mm_unpacklo_ps(r0, r1);
    LocalM128 hi = _mm_unpackhi_ps(r0, r1);
    out.a = _mm_movelh_ps(lo, r2);
    out.b = _mm_shuffle_ps(_mm_movehl_ps(hi, lo), r2, 0xd4);
    out.c = _mm_shuffle_ps(hi, r2, 0xe4);
}

static __forceinline void TransformPoint(LocalM128 &out, const Mat4 *m, const LocalM128 &pt)
{
    LocalM128 t0 = _mm_sub_ps(pt, m->rows[3]);
    LocalM128 c0 = m->rows[0];
    LocalM128 c1 = m->rows[1];
    LocalM128 c2 = m->rows[2];
    {
        LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
        LocalM128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(tmp, c2);
        tmp = _mm_movehl_ps(c0, tmp);
        c1 = _mm_shuffle_ps(tmp, c2, 0xd4);
        c2 = ctmp;
    }
    LocalM128 b0 = _mm_shuffle_ps(t0, t0, 0);
    LocalM128 b1 = _mm_shuffle_ps(t0, t0, 0x55);
    LocalM128 b2 = _mm_shuffle_ps(t0, t0, 0xaa);
    LocalM128 r0 = _mm_mul_ps(c0, b0);
    LocalM128 r1 = _mm_mul_ps(c1, b1);
    LocalM128 r2 = _mm_mul_ps(c2, b2);
    out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class PickSelf
{
public:
    int f00;
    int f04;
    SubObj *sub;
    int f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    int f30, f34, f38, f3c, f40, f44, f48, f4c;
    int f50, f54, f58, f5c, f60, f64, f68, f6c;
    int f70, f74, f78, f7c, f80, f84, f88, f8c;
    int f90, f94, f98, f9c, fa0, fa4, fa8, fac;
    int fb0, fb4, fb8, fbc, fc0, fc4, fc8, fcc;
    int fd0, fd4, fd8, fdc, fe0, fe4, fe8, fec;
    int ff0, ff4, ff8, ffc, f100, f104, f108, f10c;
    int f110, f114, f118, f11c, f120, f124, f128, f12c;
    int f130, f134, f138, f13c, f140, f144, f148, f14c;
    int f150, f154, f158, f15c;
    EntryPair *pairs;
    int count;
    void hkpCachingShapePhantomRay_castRay(RayArg *arg1, BestOut *arg2);
};

// @fnv 0x00cc26c0
// src: XBOX_PDB 0x00cc26c0
void PickSelf::hkpCachingShapePhantomRay_castRay(RayArg *arg1, BestOut *arg2)
{
    hkMonitorStream *buf = (hkMonitorStream *)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand *rec = reinterpret_cast<hkMonitorStream::TimerCommand*>(buf->m_end.m_storage);
    HitBool canWrite = reinterpret_cast<char*>(rec) < buf->m_capacityMinus16.m_storage;
    if (canWrite)
    {
        rec->m_commandAndMonitor = DAT_010c9544;
        unsigned int stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        rec->m_time0 = stamp;
        buf->m_end.m_storage = reinterpret_cast<char*>(rec + 1);
    }
    ObjInfo info;
    info.dist = 1.0f;
    info.f14 = -1;
    info.f20 = -1;
    info.f40 = 0;
    PointPair pts;
    pts.filter = 0;
    pts.key = arg1->key.v;
    pts.filter = arg1->f20 && sub->f7c ? sub->f7c + 0x10 : 0;
    bool flag = false;
    int n = count;
    int i = n - 1;
    if (i >= 0)
    {
        do
        {
            Entry *e = pairs[i].second;
            PickObj *o = e->obj;
            if (o != 0)
            {
                Key4 ek = e->key;
                if (bhkCollisionFilter_IsCollisionEnabled(arg1->key, ek))
                {
                    Mat4 *mat = e->mat;
                    TransformPoint(pts.p0, mat, arg1->p0);
                    TransformPoint(pts.p1, mat, arg1->p1);
                    info.dist = 1.0f;
                    info.f14 = -1;
                    info.f40 = 0;
                    info.f20 = -1;
                    HitBool hit = o->TestInfo(&pts, &info);
                    if (hit)
                    {
                        if (!flag || info.dist < arg2->f10)
                        {
                            arg2->f10 = info.dist;
                            flag = true;
                            arg2->v = info.point;
                            arg2->entry = e;
                        }
                    }
                }
            }
        } while (--i >= 0);
    }
    if (arg2->entry != 0)
    {
        hkVector4_setRotatedDir(arg2->entry->mat, arg2);
    }
        hkMonitorStream *buf2 = (hkMonitorStream *)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand *rec2 = reinterpret_cast<hkMonitorStream::TimerCommand*>(buf2->m_end.m_storage);
        if (reinterpret_cast<char*>(rec2) < buf2->m_capacityMinus16.m_storage)
        {
            rec2->m_commandAndMonitor = DAT_010c41f8;
            unsigned int stamp;
            __asm {
                rdtsc
                mov dword ptr[stamp], eax
            }
            rec2->m_time0 = stamp;
            buf2->m_end.m_storage = reinterpret_cast<char*>(rec2 + 1);
        }
}

extern "C" int DAT_012685ac;
void __cdecl bhkSerializable_Kill();
struct FUN_00c8a720 {
  void* vtable;
  virtual ~FUN_00c8a720();
};
struct FUN_00cc2ac0 : FUN_00c8a720 {
  virtual ~FUN_00cc2ac0();
};
// Destructor that calls FUN_00c876a0 and decrements the global DAT_012685ac.
// @fnv 0x00cc2ac0
FUN_00cc2ac0::~FUN_00cc2ac0() {
  bhkSerializable_Kill();
  --DAT_012685ac;
}

namespace fnv_00cc5c70 {
struct TlsBlock_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
__declspec(thread) TlsBlock_t g_tlsBlock;
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

extern int DAT_010c5398;

struct PoolAlloc { void* __thiscall Game_DoHeapAlloc(unsigned int n); };
extern PoolAlloc DAT_011f6238;
struct B0 { void* vf; };
struct Inner { Inner* p; int rc; int a; int b; };

struct NewObj : B0, Inner
{
    static void* __cdecl operator new(unsigned int n) { return DAT_011f6238.Game_DoHeapAlloc(n); }
    NewObj()
    {
        Inner* in = static_cast<Inner*>(this);
        rc = 1;
        a = 0;
        b = 0;
        vf = (void*)&DAT_010c5398;
        in->p = 0;
    }
};

struct FUN_00cc5c70_cls
{
    int m_00;
    int m_04;
    int m_08;
    Inner* m_0c;
    void __thiscall CopyFromSource(NewObj* o);
    Inner* bhkStiffSpringConstraint_CreateCinfo(bool* out);
};

// Creates a NewObj if m_0c is null, sets out to whether it was newly created, and returns the m_0c pointer.
// @fnv 0x00cc5c70
// src: XBOX_PDB 0x00cc5c70
Inner* FUN_00cc5c70_cls::bhkStiffSpringConstraint_CreateCinfo(bool* abCreated)
{
    TlsGuard_t guard;
    *abCreated = (m_0c == 0);
    if (*abCreated)
    {
        NewObj* o = new NewObj;
        m_0c = o;
        if (m_08)
            CopyFromSource(static_cast<NewObj*>(m_0c));
    }
    return m_0c;
}
}  // namespace fnv_00cc5c70

namespace fnv_00cc81c0 {
extern __declspec(thread) int g_tlsAllocType;


extern Transform DAT_01268370;

struct ShapeInner { int unk00; int unk04; int unk08; };
struct ShapeHolder { int unk00; int unk04; int unk08; ShapeInner* unk0C; };

struct RigidBodyStub {
    int unk00;
    int unk04;
    int unk08;
    ShapeInner* unk0C;
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    Transform m_kMotionTransform;
};

struct ParamStub {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual RigidBodyStub* GetBodyCC();
    virtual ShapeHolder* GetD0();
};

struct RefBase {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    RefBase() : unk04(0), unk08(1), unk0C(0), unk10(0) {}
    virtual ~RefBase() { Release(0); }
    void Release(int);
};

struct AllocTypeGuard {
    int m_saved;
    AllocTypeGuard(int type) { m_saved = g_tlsAllocType; g_tlsAllocType = type; }
    ~AllocTypeGuard() { g_tlsAllocType = m_saved; }
};

struct CinfoA : RefBase {
    int unk14;
    int unk18;
    CinfoA() {}
    ~CinfoA() {}
    void SetTransform(const Transform& t);
};

struct CinfoB : RefBase {
    CinfoB() {}
    void InitB();
    void SetB(int v);
    void SetScale(float f);
};

struct ResultBase {
    int unk00; int unk04; int unk08; int unk0C;
    static void* __cdecl operator new(unsigned int size);
};
struct ResultA : ResultBase { ResultA(CinfoA& a); };
struct ResultB : ResultBase { ResultB(CinfoB& b); };

// Fills a CinfoA from the param's body and shape data and returns a ResultA, or a ResultB with SetScale(f) applied when f is below 1.0.
// @fnv 0x00cc81c0
// src: COMMUNITY 0x00cc81c0
ResultBase* __cdecl bhkFixedConstraint_FixConstraint(ParamStub* apParam, float afScale)
{
    AllocTypeGuard guard(0x10);
    ResultBase* result;
    {
        CinfoA a;
        ShapeHolder* holder = apParam->GetD0();
        ShapeInner* pShapeInner = holder ? holder->unk0C : 0;
        RigidBodyStub* body = apParam->GetBodyCC();
        a.unk0C = (body && body->unk0C) ? body->unk0C->unk08 : 0;
        a.unk10 = pShapeInner ? pShapeInner->unk08 : 0;
        body = apParam->GetBodyCC();
        if (body) a.SetTransform(body->m_kMotionTransform); else a.SetTransform(DAT_01268370);
        if (afScale < 1.0f) {
            CinfoB b;
            b.InitB();
            b.SetB(a.unk04);
            b.unk0C = a.unk0C;
            b.unk10 = a.unk10;
            b.SetScale(afScale);
            result = new ResultB(b);
        } else {
            result = new ResultA(a);
        }
    }
    return result;
}
}  // namespace fnv_00cc81c0

inline float scalar(const LocalM128& value) {float result; _mm_store_ss(&result,value); return result;}
static const LocalM128 signMask = {-0.0f,-0.0f,-0.0f,-0.0f};
inline float cosineAngle(float angle) {return static_cast<float>(cos(angle));}

__forceinline LocalM128 readQuad(const LocalM128* __restrict p){return *p;}
__forceinline const LocalM128& readQuadRef(const LocalM128* __restrict p){return *p;}
__forceinline LocalM128 readFloats(const float* __restrict p){return _mm_load_ps(p);}
__forceinline const LocalM128& readFloatsRef(const float* __restrict p){return *reinterpret_cast<const LocalM128*>(p);}

struct Bool {
    char value;
    Bool(bool v) : value(v) {}
    operator bool() const {return value!=0;}
};
struct Shape {
    int unk00, unk04, unk08, type;
    LocalM128 unk10, vertexA, vertexB, vertexC;
    Bool isTriangle() const {Bool result=type==3; _ReadWriteBarrier(); return result;}
};
struct Body {
    Shape* shape;
    int key;
    void* transform;
    Body* parent;
    signed char bodyOffset;
    char unk11,unk12,unk13;
    int unk14,unk18,unk1c,unk20,unk24;
    char kind,unk29,unk2a,unk2b;
    unsigned flags;
    void FUN_00c90510();
    Bool isSpecial() const {Bool result=kind==1; _ReadWriteBarrier(); return result;}
    Bool isFlagged() const {Bool result=(flags&0x7f)==30; _ReadWriteBarrier(); return result;}
};
struct Input { LocalM128 position,direction; Body* a; Body* b; };
struct ShapeKeys { unsigned keys[8]; };
struct Collision {
    LocalM128 position,direction;
    Body* a; int state;
    ShapeKeys shapeKeysA;
    Body* b; int key;
    ShapeKeys shapeKeysB;
    Collision() {}
    __forceinline Collision(const Collision& c) {_mm_store_ps(position.m128_f32,c.position); _mm_store_ps(direction.m128_f32,c.direction); a=c.a; state=c.state; shapeKeysA=c.shapeKeysA; b=c.b; key=c.key; shapeKeysB=c.shapeKeysB; }
};
struct PointMatrix { LocalM128 x,y,z; };
struct PointVector { LocalM128 value; void hkVector4_setRotatedDir(const PointMatrix&,const PointVector&); };

template<class T> struct PointArray {
    T* data; int count; unsigned capacity;
    void reserve() {
        S_00cc4b90_Router* ctx=hkMemoryRouter_getInstance();
        if(count==int(capacity&0x3fffffff)) ResizeAudioStream(ctx->unk10,this,sizeof(T));
    }
    __forceinline void append(const T& value) {reserve(); new(data+count) T(value); ++count;}
    T& expand() {reserve(); return data[count++];}
    __forceinline void appendPointer(Body* value) {
        reserve(); T* item=data+count; _ReadWriteBarrier(); *item=value; ++count;
    }
    int find(Body* value) const {
        for(int i=0;i<count;++i) if(data[i]==value) return i;
        return -1;
    }
};
struct Collector {
    int unk00,unk04,unk08,unk0c;
    PointArray<Collision> collisions;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    PointArray<Body*> bodies;
    PointArray<int> states;
    PointArray<Collision> pending;
    void ProcessEntries_00cd3080();
    void bhkCharacterPointCollector_addCdPoint(Input* input);
};
// @fnv 0x00cd36a0
// src: XBOX_PDB 0x00cd36a0
void Collector::bhkCharacterPointCollector_addCdPoint(Input* input) {
    Body* root=input->b;
    while(root->parent) root=root->parent;
    Body* body=reinterpret_cast<Body*>(reinterpret_cast<char*>(root)+root->bodyOffset);
    if(!body) return;
    int index=bodies.find(body);
    if(index==-1) {
        body->FUN_00c90510();
        bodies.appendPointer(body);
        Collision collision;
        collision.position=input->position;
        collision.direction=input->direction;
        Body* a=input->a;
        while(a->parent) a=a->parent;
        collision.a=a;
        collision.state=input->a->key;
        Body* b=input->b;
        while(b->parent) b=b->parent;
        collision.b=b;
        collision.key=input->b->key;
        pending.append(collision);
        states.append(0);
    } else if(states.data[index]==1) states.data[index]=2;
    if(body->isSpecial() || body->isFlagged()) {
        Collision& collision=collisions.expand();
PointVector direction; (void)direction.value;
        collision.position=input->position;
        collision.direction=input->direction;
        Body* a=input->a;
        while(a->parent) a=a->parent;
        collision.a=a;
        Body* b=input->b;
        while(b->parent) b=b->parent;
        collision.b=b;
        collision.state=0;
        collision.key=input->b->key;
        float threshold=static_cast<float>(cosineAngle(0.008726646192371845f));
        if(input->b->shape->isTriangle()) {
            collision.state=2;
            Body* triangle=input->b;
            Shape* shape=triangle->shape;
            const LocalM128* __restrict p=&shape->vertexB;
            LocalM128 first=shape->vertexA;
            LocalM128 second=shape->vertexB;
            LocalM128 next=*p;
            LocalM128 u=_mm_sub_ps(second,first);
            LocalM128 v=_mm_sub_ps(shape->vertexC,next);
            LocalM128 normal=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(u,u,0xc9),_mm_shuffle_ps(v,v,0xd2)),_mm_mul_ps(_mm_shuffle_ps(u,u,0xd2),_mm_shuffle_ps(v,v,0xc9)));
            Normalize(normal);
            reinterpret_cast<PointVector&>(normal).hkVector4_setRotatedDir(*static_cast<PointMatrix*>(triangle->transform),reinterpret_cast<const PointVector&>(normal));
            direction.value=collision.direction;
            LocalM128 product=_mm_mul_ps(normal,direction.value);
            LocalM128 rotated=_mm_load_ps(normal.m128_f32);
            LocalM128 dot=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
            dot=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),dot);
            if(scalar(dot)<0.0f) rotated=_mm_xor_ps(rotated,signMask);
            product=_mm_mul_ps(direction.value,rotated);
            dot=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
            dot=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),dot);
            if(scalar(dot)>threshold) collision.state=1;
            ProcessEntries_00cd3080();
        }
    }
}

extern float DAT_01267e30;
extern float DAT_01267e34;
extern float DAT_01267e38;
extern float DAT_01267e3c;
extern const float DAT_01018238;
extern const float DAT_01050de4;
extern const float DAT_01012054;
extern const float DAT_01016248;
extern const float DAT_01030ff0;



struct S00cd8920_Pair {
    short a;
    short b;
};

struct S00cd8920_Obj {
    const struct Skeleton* unk00;
    short unk04a;short unk04b;
    short unk08;
    unsigned short unk0A;
    unsigned int unk0C;
    hkVector4 unk10;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    float unk70;
    bool unk74;

    S00cd8920_Obj* hkaFootPlacementIkSolver_Setup_Setup();
};

// Initializes the object: null pointer, shorts set to -1, four vectors copied from one global, floats set to fixed defaults, flag cleared; returns this.
// @fnv 0x00cd8920
// src: HAVOK_LIB 0x00cd8920
S00cd8920_Obj* S00cd8920_Obj::hkaFootPlacementIkSolver_Setup_Setup()
{
    unk00 = 0;
    unk04a = -1;
    unk04b = -1;
    unk08 = -1;

    const hkVector4& v = *(const hkVector4*)&DAT_01267e30;
    CopyVectorWords(unk10, v);
    CopyVectorWords(unk20, v);
    CopyVectorWords(unk30, v);
    CopyVectorWords(unk40, v);

    unk50 = 0.0f;
    unk54 = 0.0f;
    unk58 = 0.0f;
    unk74 = 0;

    unk5C = 0.7f;
    unk60 = -0.1f;
    unk64 = -1.0f;
    unk68 = 1.0f;
    unk6C = 0.5f;
    unk70 = 0.8f;

    return this;
}

#include <xmmintrin.h>
namespace fnv_00cd9d10 {

extern LocalM128 DAT_010c44d0;
extern LocalM128 DAT_010cb620;
extern LocalM128 DAT_010c71b0;
extern LocalM128 DAT_010c71d0;
extern LocalM128 DAT_010c71c0;
extern LocalM128 DAT_010cb630;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;

void __stdcall hkQuaternionf_setFlippedRotation(const LocalM128* from);



static inline LocalM128 quadRsqrt(LocalM128 r)
{
    const PoseVectorCallLocal_00cdad80 e = _mm_rsqrt_ps(r);
    const LocalM128 he = _mm_mul_ps(DAT_010c71d0, e);
    const LocalM128 ree = _mm_mul_ps(_mm_mul_ps(e, r), e);
    return _mm_mul_ps(he, _mm_sub_ps(DAT_010c71c0, ree));
}

struct Q_00cd9d10 {
    LocalM128 q;
    void ComputeValues_00cd9d10(const LocalM128* from, const LocalM128* to);
};

// Builds a quaternion from vectors from and to via their dot and cross products, with special cases for dot near 1 and near -1.
// @fnv 0x00cd9d10
// src: GUESS 0x00cd9d10 (confidence: low)
void Q_00cd9d10::ComputeValues_00cd9d10(const LocalM128* from, const LocalM128* to)
{
    LocalM128 vf = *from;
    LocalM128 nzero = DAT_010c44d0;
    LocalM128 vt = *to;
    PoseVectorCallLocal_00cdad80 mul = _mm_mul_ps(vt, vf);
    LocalM128 y2 = _mm_shuffle_ps(mul, mul, 0x55);
    y2 = _mm_add_ss(y2, mul);
    LocalM128 z2 = _mm_shuffle_ps(mul, mul, 0xaa);
    z2 = _mm_add_ss(z2, y2);
    LocalM128 spl = _mm_shuffle_ps(z2, z2, 0);
    LocalM128 dot = spl;
    LocalM128 near1 = DAT_010cb620;
    nzero = _mm_xor_ps(nzero, near1);
    LocalM128 m1 = _mm_cmplt_ps(near1, dot);
    int mask1 = _mm_movemask_ps(m1);
    LocalM128 m2 = _mm_cmplt_ps(dot, nzero);
    if (mask1) {
        this->q = DAT_010c71b0;
        return;
    }
    if (_mm_movemask_ps(m2)) {
        hkQuaternionf_setFlippedRotation(from);
        return;
    }
    LocalM128 three = DAT_010c71c0;
    PoseVectorCallLocal_00cdad80 t = _mm_add_ps(_mm_mul_ps(DAT_010c71d0, dot), DAT_010c71d0);
    LocalM128 nr = quadRsqrt(t);
    LocalM128 s1 = _mm_shuffle_ps(vt, vt, 201);
    LocalM128 s2 = _mm_shuffle_ps(vf, vf, 210);
    LocalM128 mx1 = _mm_mul_ps(s1, s2);
    LocalM128 s3 = _mm_shuffle_ps(vf, vf, 201);
    LocalM128 s4 = _mm_shuffle_ps(vt, vt, 210);
    LocalM128 mx2 = _mm_mul_ps(s4, s3);
    LocalM128 cross = _mm_sub_ps(mx2, mx1);
    LocalM128 neg999 = DAT_010cb630;
    LocalM128 dc = dot;
    LocalM128 near180 = _mm_cmplt_ps(dc, neg999);
    int mask180 = _mm_movemask_ps(near180);
    LocalM128 w05 = _mm_mul_ps(nr, DAT_010c71d0);
    if (mask180) {
        LocalM128 z0 = _mm_set_ss(DAT_01011d78);
        LocalM128 l2c = cross;
        LocalM128 l2 = _mm_mul_ps(l2c, cross);
        LocalM128 yl = _mm_shuffle_ps(l2, l2, 0x55);
        yl = _mm_add_ss(yl, l2);
        LocalM128 zl = _mm_shuffle_ps(l2, l2, 0xaa);
        zl = _mm_add_ss(zl, yl);
        LocalM128 lc = zl;
        LocalM128 rs = _mm_rsqrt_ss(lc);
        LocalM128 u = _mm_sub_ps(t, dot);
        LocalM128 rsc = rs;
        LocalM128 cz = _mm_set_ss(DAT_01011d78);
        LocalM128 czc = cz;
        LocalM128 lc2 = zl;
        zl = _mm_mul_ss(zl, rsc);
        zl = _mm_mul_ss(zl, rsc);
        LocalM128 eq = _mm_cmpeq_ss(lc2, czc);
        LocalM128 t3 = _mm_set_ss(DAT_01017718);
        LocalM128 sub = _mm_sub_ss(t3, zl);
        LocalM128 t5 = _mm_set_ss(DAT_01016248);
        LocalM128 g1 = _mm_mul_ss(t5, rsc);
        LocalM128 g2 = _mm_mul_ss(g1, sub);
        LocalM128 guard = _mm_andnot_ps(eq, g2);
        LocalM128 r2 = _mm_rsqrt_ps(u);
        LocalM128 ur2 = _mm_mul_ps(_mm_mul_ps(r2, u), r2);
        r2 = _mm_mul_ps(r2, DAT_010c71d0);
        LocalM128 nr2 = _mm_sub_ps(three, ur2);
        nr2 = _mm_mul_ps(nr2, r2);
        nr2 = _mm_mul_ps(nr2, u);
        LocalM128 guardB = _mm_shuffle_ps(guard, guard, 0);
        nr2 = _mm_mul_ps(nr2, guardB);
        w05 = nr2;
    }
    LocalM128 xyz = _mm_mul_ps(w05, cross);
    LocalM128 loc = xyz;
    LocalM128 wv = _mm_mul_ps(t, nr);
    LocalM128 hi = _mm_unpackhi_ps(xyz, wv);
    LocalM128 res = _mm_shuffle_ps(loc, hi, 196);
    this->q = res;
}
}  // namespace fnv_00cd9d10

#include <windows.h>
#include <intrin.h>

struct ConstraintInput {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void disable();
};
struct TimerEvent {
    const char* name;
    unsigned int ticks;
    unsigned int auxiliary;
};
struct TimerBuffer {
    TimerEvent* begin;
    TimerEvent* current;
    TimerEvent* storage;
    TimerEvent* end;
    void emit(const char* name) {
        TimerEvent* event = current;
        if (event < end) {
            event->name = name;
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            event->ticks = ticks;
            current = event + 1;
        }
    }
};
struct ConstraintRecord {
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    unsigned short size;
    unsigned short unk12;
    unsigned int unk14, unk18, unk1c;
    ConstraintRecord() : type(27), size(32) {}
    static void* operator new(unsigned int n) {
        return hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(n);
    }
};
void* __cdecl FindModifierConstraintAtom(void*, int);
void __cdecl hkpWorldConstraintUtil_addModifier(void*, ConstraintInput*, ConstraintRecord*);

// Disables the input, records a timer event, and if no ConstraintRecord exists on owner, allocates one and links it via FUN_00d27960.
// @fnv 0x00cdff60
// src: HAVOK_LIB 0x00cdff60
void __cdecl hkpResponseModifier_disableConstraint(void* owner, ConstraintInput* input) {
    input->disable();
    static_cast<TimerBuffer*>(TlsGetValue(DAT_0126835c))->emit("TtDsblConstr");
    if (!FindModifierConstraintAtom(owner, 27)) {
        ConstraintRecord* record = new ConstraintRecord;
        hkpWorldConstraintUtil_addModifier(owner, input, record);
    }
    static_cast<TimerBuffer*>(TlsGetValue(DAT_0126835c))->emit("Et");
}

struct S00ccaaf0_arg {
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    float m_f10;
};

class S00ccaaf0_cls {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual FUN_00cca9c0_class* vb4(unsigned char* out);
    void bhkTriangleShape_CopyMembers(void* a1, S00ccaaf0_arg* a2);
};

// @fnv 0x00ccaaf0
// src: XBOX_PDB 0x00ccaaf0
void S00ccaaf0_cls::bhkTriangleShape_CopyMembers(void* a1, S00ccaaf0_arg* a2)
{
    unsigned int tmp;
    FUN_00cca9c0_class* obj = vb4((unsigned char*)&tmp + 3);
    float f = a2->m_f10;
    if (f != 1.0f) {
        obj->hkTriangleShapeCinfo_Scale(f);
    }
    ((Owner*)this)->bhkShape_CopyMembers(a1, (void*)a2);
}


struct CC2B60Src {
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
    int unk28;
    int unk2c;
    float m_30[4];
    float m_40[4];
    float m_50;
    float m_54;
    float m_58;
    unsigned char m_5c;
    unsigned char m_5d;
};

struct CC2B60Dst {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    bhkLimitedHingeVector_blk_00cc0000_o2 m_10;
    bhkLimitedHingeVector_blk_00cc0000_o2 m_20;
    float m_30;
    float m_34;
    float m_38;
    unsigned char m_3c;
    unsigned char m_3d;
};

struct CC2F90Owner_SV {
    int unk00;
    int unk04;
    CC2B60Src* m_pParentNode;
    void* m_pkChild;

    void __thiscall WriteScriptTargetInfo(void* p);
    void CopyParentFieldsToChild(CC2B60Dst* pkChild);
};

// Calls FUN_00c8a800 on pkChild, then if m_pParentNode is set copies three floats, two four-float vectors and two bytes from it into pkChild.
// @fnv 0x00cc2b60
// src: GUESS 0x00cc2b60 (confidence: medium)
void CC2F90Owner_SV::CopyParentFieldsToChild(CC2B60Dst* pkChild)
{
    WriteScriptTargetInfo(pkChild);
    if (this && m_pParentNode)
    {
        CC2B60Src* pkSrc = m_pParentNode;
        pkChild->m_30 = pkSrc->m_50;
        pkChild->m_34 = pkSrc->m_54;
        pkChild->m_38 = pkSrc->m_58;
        pkChild->m_10.SetQuaternionComponentsFromVector(pkSrc->m_30);
        pkChild->m_20.SetQuaternionComponentsFromVector(pkSrc->m_40);
        pkChild->m_3c = pkSrc->m_5c ? pkSrc->m_5c : pkSrc->m_5c;
        pkChild->m_3d = pkSrc->m_5d ? pkSrc->m_5d : pkSrc->m_5d;
    }
}

struct MalleableConstraintStrength {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float strength;

    float __thiscall hkpMalleableConstraintData_getStrength() const;
};

// @fnv 0x00cdf680
// src: XBOX_PDB 0x00cdf680
float __thiscall MalleableConstraintStrength::hkpMalleableConstraintData_getStrength() const
{
    return strength;
}

extern float DAT_01017868;

struct FNVEffectRec
{
    unsigned short m_sType;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned short m_sSize;
    unsigned short unk12;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    float m_fValue20;
    float m_fValue24;
};

void* __cdecl FindModifierConstraintAtom(void* p, int type);

// Disables a4, then sets two floats on p's type 0x17 record, creating and registering one via FUN_00d27960 if absent; brackets work with profiler marks.
// @fnv 0x00cdfbd0
// src: HAVOK_LIB 0x00cdfbd0
void __cdecl hkpResponseModifier_setImpulseScalingForContact(FUN_00cdfe00_Object* a1, int aiUnk2, int aiUnk3, ConstraintInput* apConstraintInput, float afValue20, float afValue24)
{
    volatile unsigned long tick;
    void* p = a1->vf40();
    if (p == 0)
    {
        return;
    }
    apConstraintInput->disable();

    void* (__stdcall *pfnTls)(unsigned long) = TlsGetValue;
    hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "TtSetSoftContact";
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }

    FNVEffectRec* rec = (FNVEffectRec*)FindModifierConstraintAtom(p, 0x17);
    if (rec != 0)
    {
        rec->m_fValue20 = afValue20;
        rec->m_fValue24 = afValue24;
    }
    else
    {
        S_00cc4b90_Router* holder = hkMemoryRouter_getInstance();
        S_00cc4b90_Alloc* alloc = holder->unk10;
        rec = (FNVEffectRec*)alloc->AllocateMemoryBlock(0x30);
        if (rec != 0)
        {
            rec->m_fValue20 = DAT_0101e2bc;
            rec->m_fValue24 = DAT_01017868;
            rec->m_sType = 0x17;
            rec->m_sSize = 0x30;
        }
        else
        {
            rec = 0;
        }
        rec->m_fValue20 = afValue20;
        rec->m_fValue24 = afValue24;
        hkpWorldConstraintUtil_addModifier(p, apConstraintInput, (ConstraintRecord*)rec);
    }

    pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        pRec->m_time0 = tick;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
}

// If vf40 returns a handle, disables pObj and, when h has no atom of type 0x19, allocates one and passes it to FUN_00d27960.
// @fnv 0x00cdfe90
// src: HAVOK_LIB 0x00cdfe90
void __cdecl hkpResponseModifier_setLowSurfaceViscosity(FUN_00cdfe00_Object* pNode, ConstraintInput* pObj)
{
    volatile unsigned long ticks;
    void* h = pNode->vf40();
    if (h != 0)
    {
        pObj->disable();
        void* (__stdcall *pfnTls)(unsigned long) = TlsGetValue;
        hkMonitorStream* pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "TtSetSurfVisc";
            _ReadWriteBarrier();
            ticks = (unsigned long)__rdtsc();
            pRec->m_time0 = ticks;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
        if (FindModifierConstraintAtom(h, 0x19) == 0)
        {
            ConstraintRecord* m = (ConstraintRecord*)hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(0x20);
            if (m)
            {
                m->type = 0x19;
                m->size = 0x20;
            }
            else
                m = 0;
            hkpWorldConstraintUtil_addModifier(h, pObj, m);
        }
        pBuf = (hkMonitorStream*)pfnTls(DAT_0126835c);
        if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
        {
            hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
            pRec->m_commandAndMonitor = "Et";
            _ReadWriteBarrier();
            ticks = (unsigned long)__rdtsc();
            pRec->m_time0 = ticks;
            pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
        }
    }
}

#include <xmmintrin.h>
namespace CE6Memory {
S_00cc4b90_Router* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
}

struct CE6Heap {
 virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
 virtual void Free(void* p,int n);
};

struct CE6Array {
 hkVector4* data; int size; int capacity;
 CE6Array():data(0),size(0),capacity(0x80000000) {}
 ~CE6Array() { clear(CE6Memory::hkMemoryRouter_getInstance()->heap()); }
 void clear(S_00cc4b90_Alloc& alloc) { size=0; if(!(capacity&0x80000000)) reinterpret_cast<CE6Heap&>(alloc).Free(data,(capacity&0x3fffffff)*sizeof(hkVector4)); data=0;capacity=0x80000000; }
 void reserve(S_00cc4b90_Alloc& heap,int n) { int cap=capacity&0x3fffffff; if(cap<n) { int doubled=cap*2; CE6Memory::hkArrayUtil__reserve(&heap,this,n<doubled?doubled:n,sizeof(hkVector4)); } }
 void resize(int n) { reserve(CE6Memory::hkMemoryRouter_getInstance()->heap(),n); size=n; }
};
struct CE6Hull { CE6Array a,b; ~CE6Hull(); };
struct CE6View { hkVector4* data; int count; int stride; CE6View(const CE6Array& a) { count=a.size; stride=sizeof(hkVector4); data=a.data; } };
void __cdecl InitAndSetB(const CE6View*,CE6Hull*);
struct CE6Shape {
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
virtual int Count();
virtual hkVector4* Vertices(hkVector4* buffer);
};
struct CE6Owner {
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
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void vb8();
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void Output(void* first,CE6Hull* hull,void* second,const char* name);
 int unk04; CE6Shape* unk08;
 void bhkConvexVerticesShape_BuildDisplayGeometry(void* first,void* second);
};
// Computes the convex hull of the shape's vertices and calls Output with the hull and the name "bhkConvexVerticesShape".
// @fnv 0x00cce600
// src: XBOX_PDB 0x00cce600
void CE6Owner::bhkConvexVerticesShape_BuildDisplayGeometry(void* first,void* second) {
 S_00cc4b90_Ctx context(0x10);
 CE6Shape* shape=this ? unk08 : 0;
 int n=shape->Count();
 CE6Array scratch;
 scratch.resize(n);
 hkVector4* input=shape->Vertices(scratch.data);
 CE6Array vertices;
 vertices.resize(n);
 for(int i=0;i<n;++i) vertices.data[i].v=input[i].v;
 CE6View view(vertices);
 CE6Hull hull;
 InitAndSetB(&view,&hull);
 Output(first,&hull,second,"bhkConvexVerticesShape");
}

struct EdaTls_t
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};

struct TlsGuard_t_SV
{
    int m_saved;
    TlsGuard_t_SV()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }
    ~TlsGuard_t_SV()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};

void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();

class FUN_00cceda0_cls
{
public:

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void v0C4(void* p, unsigned int a);

    void* bhkConvexTransformShape_CreateClone(unsigned int arg);
};

// Creates a new FUN_00cce990 object, initializes it via v0C4 with the given argument, and returns the pointer.
// @fnv 0x00cceda0
// src: XBOX_PDB 0x00cceda0
void* FUN_00cceda0_cls::bhkConvexTransformShape_CreateClone(unsigned int arg)
{
    TlsGuard_t_SV guard;
    bhkSerializable_CloneCritLock();
    FUN_00cce990* res = 0;
    res = new FUN_00cce990();
    this->v0C4(res, arg);
    bhkSerializable_CloneCritUnlock();
    return res;
}
