#include <new>
#include <xmmintrin.h>
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/BSAudio.h"
// local form of hkVector4: 0x00d323f0 needs its original packet form (compiled function extent differs: 240 vs 226).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
union __m128;
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class PacketCallLocal_00d323f0
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) __m128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    PacketCallLocal_00d323f0();
    PacketCallLocal_00d323f0(float x, float y, float z, float w);
    PacketCallLocal_00d323f0(const __m128& vector);

    PacketCallLocal_00d323f0* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(PacketCallLocal_00d323f0* vector);
    void __thiscall SetQuaternionComponentsFromVector(const PacketCallLocal_00d323f0* vector);
    PacketCallLocal_00d323f0& ComputeValue_00e531a0(int parameter);
    PacketCallLocal_00d323f0 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const PacketCallLocal_00d323f0& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const PacketCallLocal_00d323f0& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const PacketCallLocal_00d323f0& vector);
    void Sub(const PacketCallLocal_00d323f0& vector);
    void Cross(const PacketCallLocal_00d323f0& a, const PacketCallLocal_00d323f0& b);

    void setAbs4(const PacketCallLocal_00d323f0& vector);
    void setMul4(const SimdReal& scalar, const PacketCallLocal_00d323f0& vector);
    void addMul4(const SimdReal& scalar, const PacketCallLocal_00d323f0& vector);
    void setAddMul4(const PacketCallLocal_00d323f0& a, const PacketCallLocal_00d323f0& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const PacketCallLocal_00d323f0& vector);
    void setAddMul(const PacketCallLocal_00d323f0& a, const PacketCallLocal_00d323f0& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const PacketCallLocal_00d323f0& vector);
    void transformed(const Transform& transform, const PacketCallLocal_00d323f0& vector);
    void addScaled(const PacketCallLocal_00d323f0& base, const PacketCallLocal_00d323f0& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMotionState.h"
#include "../../../../../../include/hkSphere.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpHeightFieldShape.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../../include/hkpCdPointCollector.h"


// src/havok/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/heightfieldagent/hkpheightfieldagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

__forceinline PacketCallLocal_00d323f0::PacketCallLocal_00d323f0() {}
__forceinline void PacketCallLocal_00d323f0::operator=(const PacketCallLocal_00d323f0& other) {
    unsigned int* dst = reinterpret_cast<unsigned int*>(this);
    const unsigned int* src = reinterpret_cast<const unsigned int*>(&other);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
}
__forceinline hkTransform::hkTransform() {}
__forceinline hkTransform::hkTransform(const hkTransform& other) {
    m_row0 = other.m_row0;
    m_row1 = other.m_row1;
    m_row2 = other.m_row2;
    m_row3 = other.m_row3;
}

extern char DAT_010ceaa8[];

hkMemoryRouter* hkMemoryRouter_getInstance();

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct SizeSource {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10();
    virtual int GetCount();
};

struct SourceRef {
    SizeSource* m_p;
};

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    hkMemoryRouter* a = hkMemoryRouter_getInstance();
    return *(hkMemoryAllocator*)a->m_heap;
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    int c = m_iCapacityState & 0x3fffffff;
    if (c < n) {
        c = c * 2;
        hkArrayUtil__reserve(alloc, this, n < c ? c : n, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n, const T& fill)
{
    GrowArrayCapacity(alloc, n);
    int num = n - m_iElementCount;
    T* p = m_data + m_iElementCount;
    for (int i = 0; i < num; ++i) {
        p[i] = fill;
    }
    m_iElementCount = n;
}

struct FUN_00d32060_Class {
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_flag;
    hkArray<unsigned short> m_aiIndexedValues;

    FUN_00d32060_Class* Init(const SourceRef& src, int b, int c, int flag);
};

// Sets the vtable, flag and count fields, initialises the array, and if flag is set fills it with 0xffff up to src.m_p->GetCount().
// @fnv 0x00d32060
FUN_00d32060_Class* FUN_00d32060_Class::Init(const SourceRef& aSource, int aiUnused1, int aiUnused2, int aiFlags)
{
    m_sReferenceCount = 1;
    m_flag = aiFlags;
    m_vtbl = DAT_010ceaa8;
    m_aiIndexedValues.setOwnedData(0, 0, hkArrayBase<unsigned short>::DONT_DEALLOCATE_FLAG);
    if (aiFlags) {
        int n = aSource.m_p->GetCount();
        m_aiIndexedValues.setSize(n, 0xffff);
    }
    return this;
}

namespace fnv_00d32110 {
hkMemoryRouter* hkMemoryRouter_getInstance();

struct TargetObj {
    int unk00;
    unsigned short size;
    TargetObj* FUN_00d32060(void* a1, void* a2, void* a3, void* a4);
};

// Allocates a 0x18-byte TargetObj from the shared allocator, sets its size to 0x18, and returns the result of FUN_00d32060(a1, a2, a3, a4).
// @fnv 0x00d32110
TargetObj* AllocateTargetObj(void* apArg1, void* apArg2, void* apArg3, void* apArg4) {
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    TargetObj* obj = (TargetObj*)((hkMemoryAllocator*)holder->m_heap)->blockAlloc(0x18);
    obj->size = 0x18;
    return obj->FUN_00d32060(apArg1, apArg2, apArg3, apArg4);
}
}  // namespace fnv_00d32110

extern void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(void*, void*, void*, void*);
// @fnv 0x00d32170
// src: HAVOK_SRC 0x00d32170
void __stdcall hkpHeightFieldAgent_getClosestPoints(void* apArg1, void* apArg2, void* apArg3, void* apArg4) {
    hkpHeightFieldAgent_staticGetClosestPoints(apArg1, apArg2, apArg3, apArg4);
}

typedef void (*S_00d321e0_Func)();

void hkpHeightFieldAgent_createHeightFieldAAgent();
void hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370();
void hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0();
void Hkpheightfieldagent_UpdateState_00d323f0();
void AllocateTargetObj();
void hkpHeightFieldAgent_staticGetPenetrations();
void hkpHeightFieldAgent_staticGetClosestPoints();
void hkpHeightFieldAgent_ProcessSphereQueries();

struct S_00d321e0_AgentFuncs {
    S_00d321e0_Func m_pCreateFunc;
    S_00d321e0_Func m_pQueryPenetrationsFunc;
    S_00d321e0_Func m_pGetPenetrationsFunc;
    S_00d321e0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct S_00d321e0_Dispatcher {
    void AppendRecordAndRegisterAgents(S_00d321e0_AgentFuncs& f, int typeA, int typeB);
};

// @fnv 0x00d321e0
// src: XBOX_PDB 0x00d321e0
void hkpHeightFieldAgent_registerAgent(S_00d321e0_Dispatcher* dispatcher)
{
    {
        S_00d321e0_AgentFuncs af;
        af.m_pCreateFunc = hkpHeightFieldAgent_createHeightFieldAAgent;
        af.m_pQueryPenetrationsFunc = hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370;
        af.m_pGetPenetrationsFunc = hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0;
        af.m_pLinearCastFunc = Hkpheightfieldagent_UpdateState_00d323f0;
        af.m_bIsFlipped = true;
        af.m_bIsPredictive = true;
        dispatcher->AppendRecordAndRegisterAgents(af, 0x19, 0x1a);
    }
    {
        S_00d321e0_AgentFuncs af;
        af.m_pCreateFunc = AllocateTargetObj;
        af.m_pQueryPenetrationsFunc = hkpHeightFieldAgent_staticGetPenetrations;
        af.m_pGetPenetrationsFunc = hkpHeightFieldAgent_staticGetClosestPoints;
        af.m_pLinearCastFunc = hkpHeightFieldAgent_ProcessSphereQueries;
        af.m_bIsFlipped = false;
        af.m_bIsPredictive = true;
        dispatcher->AppendRecordAndRegisterAgents(af, 0x1a, 0x19);
    }
}

extern float g_D323B0MaxDistance;

struct D323B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D323B0CollectorBase() : m_fEarlyOutDistance(g_D323B0MaxDistance) {}
};

struct D323B0Collector : D323B0CollectorBase {
    int m_iData;

    D323B0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};

void __cdecl hkpHeightFieldAgent_staticGetClosestPoints(int a, int b, int c, D323B0CollectorBase* collector);

// Constructs a D323B0Collector from d and passes it with b, a, c to FUN_00d319e0.
// @fnv 0x00d323b0
// src: GUESS 0x00d323b0 (confidence: low)
void __cdecl hkpHeightFieldAgent_staticGetClosestPoints_ProcessState_00d323b0(int aiArg1, int aiArg2, int aiArg3, int aiData)
{
    D323B0Collector collector(aiData);
    hkpHeightFieldAgent_staticGetClosestPoints(aiArg2, aiArg1, aiArg3, &collector);
}

struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void invoke(unsigned short item, int value);
};
struct Owner {
    virtual void clear(unsigned int mode);
    int unk04;
    Handler* callback;
    unsigned short* indices;
    int count;
    void NotifyAndClear(int value);
};
// Invokes callback->invoke for each non-0xffff entry in indices, then calls clear(1).
// @fnv 0x00d31770
void Owner::NotifyAndClear(int value) {
    if (callback) {
        for(int index=0; index<count; ++index) {
            unsigned short item=indices[index];
            if(item!=0xffff)
                callback->invoke(item,value);
        }
    }
    clear(1);
}

extern "C" void __cdecl hkpHeightFieldAgent_ProcessSphereQueries(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
// Forwards all five arguments unchanged to FUN_00d31d30.
// @fnv 0x00d32030
// src: HAVOK_SRC 0x00d32030
extern "C" void __stdcall hkpHeightFieldAgent_linearCast(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4)
{
    hkpHeightFieldAgent_ProcessSphereQueries(arg0, arg1, arg2, arg3, arg4);
}

extern "C" void __cdecl hkpHeightFieldAgent_staticGetPenetrations(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d32150
// src: HAVOK_SRC 0x00d32150
extern "C" void __stdcall hkpHeightFieldAgent_getPenetrations(void* arg0, void* arg1, void* arg2, void* arg3)
{
    hkpHeightFieldAgent_staticGetPenetrations(arg0, arg1, arg2, arg3);
}

extern char DAT_010ce81c;

void __cdecl hkpHeightFieldAgent_staticGetPenetrations(int a1, int a2, int a3, void* a4);

struct FUN_00d32370_cls {
    void* vt;
    unsigned char flag;
    int d;
};

// Builds a FUN_00d32370_cls with vt set to DAT_010ce81c and d set to a4, then calls FUN_00d317d0 with a2, a1, a3 and the struct.
// @fnv 0x00d32370
// src: GUESS 0x00d32370 (confidence: low)
void __cdecl hkpHeightFieldAgent_staticGetPenetrations_UpdateState_00d32370(int aiArg1, int aiArg2, int aiArg3, int a4) {
    FUN_00d32370_cls local;
    local.flag = 0;
    local.d = a4;
    local.vt = &DAT_010ce81c;
    hkpHeightFieldAgent_staticGetPenetrations(aiArg2, aiArg1, aiArg3, &local);
}

namespace fnv_00d323f0 {
struct __declspec(align(16)) CopyPacket {
    void* unk00;
    unsigned int unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    PacketCallLocal_00d323f0 orientation;
    unsigned int unk60, unk64, unk68, unk6c;
};
struct Argument {
    const void* vtable;
    float scale;
    unsigned int unk08, unk0c;
    PacketCallLocal_00d323f0 orientation;
    int identifier;
    unsigned int unk24, unk28, unk2c;
};
extern "C" const float DAT_0104da48;
extern "C" const __m128 DAT_010c44d0;
extern "C" const char UNK_010ce80c;
extern "C" void __cdecl hkpHeightFieldAgent_ProcessSphereQueries(int, int, const CopyPacket*, const Argument*, const Argument*);

// Copies a CopyPacket with its orientation sign-flipped and calls FUN_00d31d30 with one or two Argument descriptors built from the source.
// @fnv 0x00d323f0
// src: GUESS 0x00d323f0 (confidence: low)
void __cdecl Hkpheightfieldagent_UpdateState_00d323f0(int a, int b, const CopyPacket* source, int id1, int id2) {
    __m128 orient = _mm_load_ps(&source->orientation.x);
    __m128 inverted = _mm_xor_ps(orient, DAT_010c44d0);
    Argument first;
    first.scale = DAT_0104da48;
    CopyPacket copy = *source;
    _mm_store_ps(&copy.orientation.x, inverted);
    const void* vptr = &UNK_010ce80c;
    first.vtable = vptr;
    first.orientation = source->orientation;
    first.identifier = id1;
    if (id2) {
        Argument second;
        second.vtable = vptr;
        second.scale = DAT_0104da48;
        second.orientation = source->orientation;
        second.identifier = id2;
        hkpHeightFieldAgent_ProcessSphereQueries(b, a, &copy, &first, &second);
    } else {
        hkpHeightFieldAgent_ProcessSphereQueries(b, a, &copy, &first, 0);
    }
}
}  // namespace fnv_00d323f0

extern unsigned long DAT_0126835c;
extern const char DAT_010cea38[];
extern const char DAT_010cea7c[];
extern const char DAT_010cea6c[];
extern const char DAT_010cea60[];
extern const char DAT_010cea54[];
extern const char DAT_010cea48[];
extern const char DAT_01076f38[];
extern const char str_010cea1c[];

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

struct MonitorCommand {
    const char* name;
    unsigned int time;
    unsigned int timeHi;
    const char* subName;
};
__forceinline hkMonitorStream& hkMonitorStream::getInstance() {
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}
// The original's timer helpers (expansions of Havok's timer macros), kept as members of a unit-local view so the
// inlined code keeps its shape.
struct StringCursor_hkpheightfieldagent : hkMonitorStream
{
    void timerBegin(const char* name);
    void timerBegin(const char* name1, const char* name2);
    void timerEnd(const char* name);
    void timerSplit(const char* name);
};
__forceinline void StringCursor_hkpheightfieldagent::timerBegin(const char* name1, const char* name2) {
    if (m_end.m_storage < m_capacityMinus16.m_storage) {
        MonitorCommand* cmd = (MonitorCommand*)m_end.m_storage;
        cmd->name = name1;
        cmd->subName = name2;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cmd->time = ticks;
        m_end.m_storage = (char*)(cmd + 1);
    }
}
__forceinline void StringCursor_hkpheightfieldagent::timerSplit(const char* name) {
    if (m_end.m_storage < m_capacityMinus16.m_storage) {
        MonitorCommand* cmd = (MonitorCommand*)m_end.m_storage;
        cmd->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        cmd->time = ticks;
        m_end.m_storage = (char*)cmd + 12;
    }
}
__forceinline void StringCursor_hkpheightfieldagent::timerEnd(const char* name) { timerSplit(name); }

__forceinline void hkVector4::SetRotatedDirection(const hkTransform& a, const hkVector4& b) {
    __m128 y = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 x = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 z = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a.m_row1), _mm_mul_ps(x, a.m_row0)), _mm_mul_ps(z, a.m_row2));
}

__forceinline void hkVector4::SetTransformedPoint(const hkTransform& a, const hkVector4& b) {
    __m128 y = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 x = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 z = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a.m_row1), _mm_mul_ps(x, a.m_row0)), _mm_add_ps(_mm_mul_ps(z, a.m_row2), a.m_row3));
}

__forceinline void transformSphere(hkVector4& __restrict out, const hkTransform& __restrict a, const hkVector4& __restrict sphere) {
    __m128 y = _mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x55);
    __m128 x = _mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0x00);
    __m128 z = _mm_shuffle_ps(sphere.m_vComponents, sphere.m_vComponents, 0xaa);
    __m128 pos = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a.m_row1), _mm_mul_ps(x, a.m_row0)), _mm_add_ps(_mm_mul_ps(z, a.m_row2), a.m_row3));
    __m128 unpck = _mm_unpackhi_ps(pos, sphere.m_vComponents);
    out.m_vComponents = _mm_shuffle_ps(pos, unpck, 0xc4);
}

// Use the compiler's float-only intrinsic view for register temporaries. The SDK's
// __m128 union also contains byte arrays, which VC9 treats as stack buffers.
namespace N {
// Exe 0x00d317d0 FUN_00d317d0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; } __m128, LocalM128;
extern "C" {
LocalM128 _mm_add_ps(LocalM128, LocalM128); LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int); LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
}
}

__forceinline void transformSpheres(const hkTransform& tr, const hkSphere* src, int count, hkSphere* dst) {
    N::LocalM128 row0 = reinterpret_cast<const N::LocalM128&>(tr.m_row0);
    N::LocalM128 row1 = reinterpret_cast<const N::LocalM128&>(tr.m_row1);
    N::LocalM128 row2 = reinterpret_cast<const N::LocalM128&>(tr.m_row2);
    N::LocalM128 row3 = reinterpret_cast<const N::LocalM128&>(tr.m_row3);
    int i = count - 1;
    do {
        const N::LocalM128& sphere = reinterpret_cast<const N::LocalM128&>(src[i].m_pos.m_vComponents);
        N::LocalM128 y = N::_mm_shuffle_ps(sphere, sphere, 0x55);
        N::LocalM128 x = N::_mm_shuffle_ps(sphere, sphere, 0x00);
        N::LocalM128 z = N::_mm_shuffle_ps(sphere, sphere, 0xaa);
        N::LocalM128 value = N::_mm_add_ps(N::_mm_add_ps(N::_mm_mul_ps(y, row1), N::_mm_mul_ps(x, row0)), N::_mm_add_ps(N::_mm_mul_ps(z, row2), row3));
        value = N::_mm_shuffle_ps(value, N::_mm_unpackhi_ps(value, sphere), 0xc4);
        reinterpret_cast<N::LocalM128&>(dst[i].m_pos.m_vComponents) = value;
    } while (--i >= 0);
}

struct CollisionSphereData {
    __forceinline void setSpheres(const hkSphere* p){ m_kSpheres=p; }
    const hkSphere* m_kSpheres;
    int m_iSphereCount;
    float m_fScalar;
};

// Declare only the derived virtual slots missing from the shared shape headers.
struct CollisionSphereShape : hkpShape {
    virtual int getNumCollisionSpheres();
    virtual const hkSphere* getCollisionSpheres(hkSphere* buffer);
};
struct HeightFieldSphereCollider : hkpHeightFieldShape {
    virtual void CollideSpheres(const CollisionSphereData& input, hkSphere* results);
};

struct CollisionAgentContext {
    int unk00;
    int unk04;
    float m_fScalar;
};

struct ContactPointPair {
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    ContactPointPair() {}
    __forceinline ContactPointPair(const hkpCdBody* a, const hkpCdBody* b) : m_pBodyA(a), m_pBodyB(b) {}
};


struct CollisionScratch { hkTransform transform; ContactPointPair contact; };


// @fnv 0x00d317d0
// src: XBOX_PDB 0x00d317d0
void __cdecl hkpHeightFieldAgent_staticGetPenetrations(int a1, int a2, int a3, void* a4)
{
    const hkpCdBody* bodyA = (const hkpCdBody*)a1;
    const hkpCdBody* bodyB = (const hkpCdBody*)a2;
    const CollisionAgentContext* input = (const CollisionAgentContext*)a3;
    hkpCdBodyPairCollector* collector = (hkpCdBodyPairCollector*)a4;

    static_cast<StringCursor_hkpheightfieldagent&>(hkMonitorStream::getInstance()).timerBegin("LtHeightField", "StGetSpheres");

    const hkpShape* shapeA = bodyA->m_pCollisionShape;
    hkpHeightFieldShape* shapeB = (hkpHeightFieldShape*)bodyB->m_pCollisionShape;
    // Float storage avoids VC9 treating the SDK __m128 byte lanes as a GS buffer.
    __declspec(align(16)) float transformStorage[sizeof(hkTransform) / sizeof(float)];
    hkTransform& aTb = *::new (transformStorage) hkTransform;
    aTb.hkTransform_setMulInverseMul(bodyB->m_pMotionState, bodyA->m_pMotionState);

    int count = ((CollisionSphereShape*)shapeA)->getNumCollisionSpheres();

    hkMemoryRouter* q = hkMemoryRouter_getInstance();
    char* cur1 = (char*)q->m_stack.m_next.m_storage;
    hkSphere* sphereBuffer = (hkSphere*)cur1;
    q->m_stack.m_next.m_storage = (void*)((int)(cur1 + ((count * 16 + 127) & ~127)));

    const hkSphere* spheres = ((CollisionSphereShape*)shapeA)->getCollisionSpheres(sphereBuffer);
    transformSpheres(aTb, spheres, count, sphereBuffer);

    static_cast<StringCursor_hkpheightfieldagent&>(hkMonitorStream::getInstance()).timerSplit("StCollide");

    hkMemoryRouter* bs2 = hkMemoryRouter_getInstance();
    char* cur2 = (char*)bs2->m_stack.m_next.m_storage;
    hkSphere* hitResults = (hkSphere*)cur2;
    {
        const CollisionAgentContext* __restrict in = input;
        CollisionSphereData shB;
        shB.m_kSpheres = sphereBuffer;
        bs2->m_stack.m_next.m_storage = (void*)((int)(cur2 + ((count * 16 + 127) & ~127)));
        shB.m_iSphereCount = count;
        shB.m_fScalar = in->m_fScalar;
        ((HeightFieldSphereCollider*)shapeB)->CollideSpheres(shB, hitResults);
    }

    static_cast<StringCursor_hkpheightfieldagent&>(hkMonitorStream::getInstance()).timerSplit(str_010cea1c);

    const hkSphere* hit = hitResults;
    for (int i = count - 1; i >= 0; ++hit, --i) {
        if (hit->m_pos.m_vComponents.m128_f32[3] < 0.0f) {
            collector->AddCdBodyPair(*bodyA, *bodyB);
            break;
        }
    }

    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = (void*)((int)hitResults);
    hkMemoryRouter_getInstance()->m_stack.m_next.m_storage = (void*)((int)sphereBuffer);

    static_cast<StringCursor_hkpheightfieldagent&>(hkMonitorStream::getInstance()).timerEnd("lt");
}

namespace fnv_00d32190 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

extern char DAT_010ceaf4[];

struct FUN_00d32190_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;

    void FUN_00d32060(int a1, int a2, int a3, int a4);
};

// Allocates a 0x18 byte object via m_pAllocator, sets m_w04 to 0x18, calls FUN_00d32060, and sets m_vptr to DAT_010ceaf4.
// @fnv 0x00d32190
// src: HAVOK_LIB 0x00d32190
FUN_00d32190_cls* __cdecl hkpHeightFieldAgent_createHeightFieldAAgent(int a1, int a2, int a3, int a4)
{
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    FUN_00d32190_cls* obj = (FUN_00d32190_cls*)((hkMemoryAllocator*)holder->m_heap)->blockAlloc(0x18);
    obj->m_w04 = 0x18;
    obj->FUN_00d32060(a2, a1, a3, a4);
    obj->m_vptr = DAT_010ceaf4;
    return obj;
}
}  // namespace fnv_00d32190
