
// src/havok/physics/dynamics/constraint/chain/ballsocket/hkpballsocketchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/ballsocket/hkpballsocketchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpConstraintAtom.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
// The original SIMD union has no byte-array member; the CRT union adds /GS code at 0x00d53e80.
#define _INCLUDED_MM2
// Exe 0x00d53e80 FUN_00d53e80: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../../../../../../include/hkVector4.h"
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpBridgeConstraintAtom.h"
#include "../../../../../../../include/hkpBridgeAtoms.h"
#include "../../../../../../../include/hkpConstraintChainData.h"

inline hkpConstraintData::hkpConstraintData() throw() : m_ulUserData(0) {}
inline hkpConstraintData::hkpConstraintData(FinishingFlag flag) : hkReferencedObject(flag) {}
inline hkpConstraintData::~hkpConstraintData() throw() {}

// Shared hkMemoryRouter view: 0x00c85750 returns this record, with its heap pointer at +0x10.
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*) { return hkMemoryRouter_getInstance().heap(); }
template <class T> inline void hkMemoryAllocator::_bufFree(void* p, int count)
{
    bufFree(p, count * sizeof(T));
}
template <class T> __forceinline void hkArrayUtil::destruct(T* data, int count, hkTypeIsClass)
{
    for (int n = 0; n < count; ++n)
        data[n].~T();
}
template <class T> __forceinline void hkArrayBase<T>::clear()
{
    hkArrayUtil::destruct(m_data, m_iElementCount, hkTypeIsClass());
    m_iElementCount = 0;
}
template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& memory)
{
    clear();
    if (!(m_iCapacityState & 0x80000000))
        memory._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}
inline void hkReferencedObject::operator delete(void* p)
{
    hkMemoryRouter_getInstance().heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

inline hkpConstraintChainData::hkpConstraintChainData() {}
inline hkpConstraintChainData::hkpConstraintChainData(FinishingFlag flag) : hkpConstraintData(flag) {}

inline hkpConstraintAtom::hkpConstraintAtom(AtomType type) : m_type(type) {}
inline hkpConstraintAtom::hkpConstraintAtom(FinishingFlag) {}

inline hkpBridgeConstraintAtom::hkpBridgeConstraintAtom() : hkpConstraintAtom(TYPE_BRIDGE) {}
inline hkpBridgeConstraintAtom::hkpBridgeConstraintAtom(FinishingFlag flag) : hkpConstraintAtom(flag)
{
    if (flag.m_bFinishing)
        hkpBridgeConstraintAtom_init(m_pConstraintData);
}

// Two 16-byte pivots at stride 0x20 (0x00d53d30/0x00d53e80), unlike include/Pair.h's two integers.
struct hkpBallSocketChainDataConstraintInfo
{
    hkVector4 m_kPivotInA, m_kPivotInB;
};
struct ChainRuntimeInfo
{
    int x, y;
};
struct PortQuery;
struct QueryResultSchema;

// No include/hkpBallSocketChainData.h exists yet; keep the real class locally.
class hkpBallSocketChainData : public hkpConstraintChainData
{
public:
    hkpBridgeAtoms m_kBridgeAtoms;
    hkArray<hkpBallSocketChainDataConstraintInfo> m_pConstraintInfo;
    float m_fTau;
    float m_fMotorDamping;
    float m_fMaxErrorDistance;
    float m_fMaximumAngularImpulse;

    hkpBallSocketChainData();
    hkpBallSocketChainData(FinishingFlag flag);
    virtual ~hkpBallSocketChainData() throw();
    void InitChainData(char* out);
    void GetConstraintSizeInfo(bool enabled, ChainRuntimeInfo* info);
    void Push(const LocalM128& a, const LocalM128& b);
    hkpBallSocketChainData* DestroyAndFree(unsigned int flags) throw();
    void buildJacobian_00d53e80(const PortQuery& input, QueryResultSchema& output);
};

// @fnv 0x00d53cf0
void hkpBallSocketChainData::GetConstraintSizeInfo(bool abEnabled, ChainRuntimeInfo* apSizeInfo)
{
    if (abEnabled)
    {
        apSizeInfo->y = 3 * m_pConstraintInfo.m_iElementCount;
        apSizeInfo->x = apSizeInfo->y * 8;
    }
    else
    {
        apSizeInfo->y = 0;
        apSizeInfo->x = 0;
    }
}

// @fnv 0x00d53ca0
void hkpBallSocketChainData::InitChainData(char* out)
{
    *(int*)(out + 0x10) = (int)&m_kBridgeAtoms;
    int zero = 0;
    *(int*)(out + 8) = zero;
    *(int*)(out + 0xc) = zero;
    *(int*)out = zero;
    *(int*)(out + 4) = 0x10;
    *(int*)(out + 0x14) = 0xc;
    int iCount = m_pConstraintInfo.m_iElementCount;
    int iTripleCount = iCount * 3;
    *(int*)(out + 4) = (((iCount * 0x134 + 0x33) & 0xfffffff0) + 0x10);
    *(int*)(out + 8) = iTripleCount;
    *(int*)(out + 0xc) = iTripleCount;
}

extern int g_target_00d53c90;
// @fnv 0x00d53c90
// src: GUESS 0x00d53c90 (confidence: low)
void* hkpBallSocketChainData_GetTarget00d53c90Address()
{
    return &g_target_00d53c90;
}

// @fnv 0x00d53d90
hkpBallSocketChainData::hkpBallSocketChainData()
{
    m_fTau = 0.6f;
    m_fMotorDamping = 1.0f;
    m_fMaxErrorDistance = 1.1920929e-08f;
    m_fMaximumAngularImpulse = 0.1f;
    m_kBridgeAtoms.m_kBridgeAtom.hkpBridgeConstraintAtom_init(this);
}

// @fnv 0x00d53df0
hkpBallSocketChainData::hkpBallSocketChainData(FinishingFlag flag)
    : hkpConstraintChainData(flag), m_kBridgeAtoms(flag), m_pConstraintInfo(flag)
{
    if (flag.m_bFinishing)
        m_kBridgeAtoms.m_kBridgeAtom.hkpBridgeConstraintAtom_init(this);
}

// @fnv 0x00d53e30
__declspec(noinline) hkpBallSocketChainData::~hkpBallSocketChainData() throw()
{
}

// @fnv 0x00d54150
hkpBallSocketChainData* hkpBallSocketChainData::DestroyAndFree(unsigned int flags) throw()
{
    this->hkpBallSocketChainData::~hkpBallSocketChainData();
    if (flags & 1)
        hkpBallSocketChainData::operator delete(this);
    return this;
}

namespace fnv_00d549d0 {
struct Elem
{
    int a, b;
};

struct DummyClass
{
    int unk00;
    Elem* data1;
    int size1;
    int cap1;
    Elem* data2;
    int size2;
    int cap2;

    void ClearArrays();
};

// @fnv 0x00d549d0
void DummyClass::ClearArrays()
{
    hkMemoryRouter& pThreadContext2 = ::hkMemoryRouter_getInstance();
    hkMemoryAllocator& mem2 = pThreadContext2.heap();
    int iCapacity2 = cap2;
    size2 = 0;
    if ((iCapacity2 & 0x80000000) == 0)
    {
        mem2.bufFree(data2, (iCapacity2 & 0x3FFFFFFF) * 8);
    }
    data2 = 0;
    cap2 = 0x80000000;

    hkMemoryRouter& pThreadContext1 = ::hkMemoryRouter_getInstance();
    hkMemoryAllocator& mem1 = pThreadContext1.heap();
    int iCapacity1 = cap1;
    size1 = 0;
    if ((iCapacity1 & 0x80000000) == 0)
    {
        mem1.bufFree(data1, (iCapacity1 & 0x3FFFFFFF) * 8);
    }
    data1 = 0;
    cap1 = 0x80000000;
}
}  // namespace fnv_00d549d0

void ResizeAudioStream(void* alloc, void* arr, int elemSize);

// @fnv 0x00d53d30
void hkpBallSocketChainData::Push(const LocalM128& a, const LocalM128& b)
{
    hkArray<hkpBallSocketChainDataConstraintInfo>& arr = m_pConstraintInfo;
    hkMemoryRouter& router = hkMemoryRouter_getInstance();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(router.m_heap, &arr, 0x20);
    hkpBallSocketChainDataConstraintInfo& e = arr.m_data[arr.m_iElementCount++];
    e.m_kPivotInA.m_vComponents = a;
    e.m_kPivotInB.m_vComponents = b;
}

struct ChainPlacement
{
};
inline void* operator new(unsigned int, ChainPlacement* pointer)
{
    return pointer;
}
template <class T> struct ChainValue
{
    T value;
    ChainValue()
    {}
    ChainValue(T x) : value(x)
    {}
    void operator=(T x)
    {
        value = x;
    }
    T val() const
    {
        return value;
    }
    operator T() const
    {
        return val();
    }
};
struct QueryResultSchema
{
    ChainValue<void*> m_pQueryResultSchema;
};
struct QuantizedBoundsData;
struct ChainStep
{
    __declspec(align(16)) ChainValue<float> unk00;
    ChainValue<float> unk04, m_kThirdChainValue, unk0c, unk10, unk14, unk18, unk1c, m_fThirdQueryValue,
        m_fFourthQueryValue, unk28;
};
struct ChainSimd
{
    LocalM128 value;
};
struct PortQuery : ChainStep
{
    __declspec(align(16)) ChainValue<const QuantizedBoundsData*> m_pBodyA;
    ChainValue<const QuantizedBoundsData*> m_pBodyB;
    ChainValue<const hkTransform*> m_kBodyALocalFrame, m_kBodyBLocalFrame;
    ChainValue<float> unk40, unk44;
    ChainSimd maximum;
    ChainValue<hkpConstraintInstance*> m_pConstraintChainInstance;
    ChainValue<void*> m_pByteBuffer;
    ChainValue<void*> unk68;
    ChainValue<unsigned int> unk6c, unk70;
    ChainValue<void*> unk74;
    PortQuery()
    {}
};

extern "C" void ResizeAudioStream(hkMemoryAllocator&, void*, int);

template <class T> __forceinline void hkArrayUtil::constructWithCopy(T* dst, int count, const T& source, hkTypeIsClass)
{
    for (int n = 0; n < count; ++n)
        ::new (reinterpret_cast<ChainPlacement*>(dst + n)) T(source);
}

template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& memory, const T& item)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(memory, this, sizeof(T));
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, item, hkTypeIsClass());
    ++m_iElementCount;
}
template <class T> __forceinline void hkArrayBase<T>::pushBackUnchecked(const T& item)
{
    hkArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, item, hkTypeIsClass());
    ++m_iElementCount;
}

struct PortMotion
{
    int unke0, unke4, unke8, unkec;
    hkTransform transform;
    inline const hkTransform& getTransform() const
    {
        return transform;
    }
};
struct PortEntity
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0;
    int m_uiFilterInfo;
    int unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    PortMotion m_pMotionState;
    inline PortMotion* getMotion()
    {
        return &m_pMotionState;
    }
};
struct PortInstance
{
    int unk00, unk04, unk08, unk0c, unk10;
    PortEntity* m_actionOrEntity;
    int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    hkArray<PortEntity*> m_ppRigidBodies;
    inline PortEntity* getEntityA() const
    {
        return m_actionOrEntity;
    }
};

struct PortVector
{
    LocalM128 value;
    PortVector()
    {}
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& p)
    {
        LocalM128 v = *reinterpret_cast<const LocalM128*>(&p);
        LocalM128 c1 = *reinterpret_cast<const LocalM128*>(&t.m_kColumn1);
        LocalM128 c0 = *reinterpret_cast<const LocalM128*>(&t.m_kColumn0);
        LocalM128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1);
        LocalM128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0);
        y = _mm_add_ps(y, x);
        LocalM128 c2 = *reinterpret_cast<const LocalM128*>(&t.m_kColumn2);
        LocalM128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2);
        LocalM128 w = *reinterpret_cast<const LocalM128*>(&t.m_vTranslation);
        z = _mm_add_ps(z, w);
        value = _mm_add_ps(y, z);
    }
};

struct OffsetForChain
{
    int value;
    OffsetForChain()
    {}
    OffsetForChain(const QuantizedBoundsData* base, const QuantizedBoundsData* at)
        : value(int((const char*)at - (const char*)base))
    {}
};
extern "C"
{
    void AppendEventRecord(const PortQuery*, QueryResultSchema*, void*, int);
    char* hkJacobianBallSocketChainSchema_getJacobians(void*);
    void hkLoadVelocityAccumulators(PortQuery*);
    void hkStabilizedBallSocketConstraintBuildJacobian_noSchema(const PortVector*, const PortVector*, float, PortQuery*, char*);
    void hkBallSocketChainBuildJacobian(int, float, float, float, OffsetForChain*, const QuantizedBoundsData*, char*, const PortQuery*,
                      QueryResultSchema*);
}
// Iterates a rigid-body constraint chain, computing transformed pivot positions and accumulating query results into the output schema.
// @fnv 0x00d53e80
// src: XBOX_PDB 0x00d53e80
void hkpBallSocketChainData::buildJacobian_00d53e80(const PortQuery& input, QueryResultSchema& output)
{
    void* solver = input.m_pByteBuffer.val();
    AppendEventRecord(&input, &output, solver, 8);
    PortQuery localQuery = input;
    localQuery.m_pConstraintChainInstance = 0;
    localQuery.m_pByteBuffer = 0;
    hkInplaceArray<OffsetForChain, 32> offsets;
    PortInstance* instance = reinterpret_cast<PortInstance*>(input.m_pConstraintChainInstance.val());
    const QuantizedBoundsData* base = reinterpret_cast<const QuantizedBoundsData*>(
        reinterpret_cast<const char*>(input.m_pBodyA.val()) - instance->getEntityA()->m_uiFilterInfo);
    const hkArray<PortEntity*>& bodies = instance->m_ppRigidBodies;
    int count = bodies.GetLogicalSize() - 1;
    PortEntity* body = bodies[0];
    PortMotion* motion = body->getMotion();
    localQuery.m_pBodyB =
        reinterpret_cast<const QuantizedBoundsData*>(reinterpret_cast<const char*>(base) + body->m_uiFilterInfo);
    offsets.pushBackUnchecked(OffsetForChain(base, localQuery.m_pBodyB));
    localQuery.m_kBodyBLocalFrame = &motion->getTransform();
    localQuery.m_fFourthQueryValue = 1.0f;
    localQuery.m_fThirdQueryValue = localQuery.m_kThirdChainValue;
    char* schema = hkJacobianBallSocketChainSchema_getJacobians(output.m_pQueryResultSchema);
    for (int index = 0; index < count; ++index)
    {
        localQuery.m_pBodyA = localQuery.m_pBodyB;
        localQuery.m_kBodyALocalFrame = localQuery.m_kBodyBLocalFrame;
        body = bodies[index + 1];
        motion = body->getMotion();
        localQuery.m_pBodyB =
            reinterpret_cast<const QuantizedBoundsData*>(reinterpret_cast<const char*>(base) + body->m_uiFilterInfo);
        offsets.pushBack(OffsetForChain(base, localQuery.m_pBodyB));
        localQuery.m_kBodyBLocalFrame = &motion->getTransform();
        PortVector a, b;
        a._setTransformedPos(*localQuery.m_kBodyALocalFrame, m_pConstraintInfo.m_data[index].m_kPivotInA);
        b._setTransformedPos(*localQuery.m_kBodyBLocalFrame, m_pConstraintInfo.m_data[index].m_kPivotInB);
        hkLoadVelocityAccumulators(&localQuery);
        hkStabilizedBallSocketConstraintBuildJacobian_noSchema(&a, &b, m_fMaximumAngularImpulse, &localQuery, schema);
        schema += 0x90;
    }
    hkBallSocketChainBuildJacobian(count, m_fTau, m_fMotorDamping, m_fMaxErrorDistance, offsets.begin(), base, schema, &input, &output);
}
