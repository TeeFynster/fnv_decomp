
// src/havok/physics/dynamics/constraint/chain/stiffspring/hkpstiffspringchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/stiffspring/hkpstiffspringchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Retain the original float/word SIMD intrinsic type: the CRT's byte-array
// lanes would add /GS stack cookies to this unit's solver scratch frame.
#define _INCLUDED_MM2
// Exe 0x00e3b0f0 FUN_00e3b0f0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
    void _mm_store_ss(float*, LocalM128);
}

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpConstraintChainData.h"
#include "../../../../../../../include/hkpBridgeAtoms.h"
#include "../../../../../../../include/hkpConstraintChainInstance.h"
#include "../../../../../../../include/hkpEntity.h"

// The TLS accessor at 0x00c85750 and heap pointer at +0x10 identify hkMemoryRouter,
// represented by the shared hkMemoryRouter declaration.
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

struct ConstraintInfo
{
    int m_maxNumExternalSlaveContactPoints;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpBridgeAtoms* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};


struct SixteenWordFloatRecord;
struct QueryResultSchema;
class hkpStiffSpringChainDataConstraintInfo;

// include/ has no hkpStiffSpringChainData.h yet; retain its reflected 0x30 layout
// and this unit's methods together until that shared declaration is available.
class hkpStiffSpringChainData : public hkpConstraintChainData
{
public:
    virtual ~hkpStiffSpringChainData() throw();

    hkpBridgeAtoms m_kBridgeAtoms;
    hkArray<hkpStiffSpringChainDataConstraintInfo> m_pConstraintInfo;
    hkReal m_fTau;
    hkReal m_fMotorDamping;
    hkReal m_fMaxErrorDistance;

    void getRuntimeInfo_00e3af80(bool bFlag, unsigned int* pOut);
    void getConstraintInfo_00e3af40(::ConstraintInfo& info);
    void buildJacobian_00e3b0f0(const SixteenWordFloatRecord& inNonConst, QueryResultSchema& out) volatile;
    hkpStiffSpringChainData* DestroyAndFree(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().blockFree(
            p, static_cast<hkpStiffSpringChainData*>(p)->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00e3af80
// src: HAVOK_LIB 0x00e3af80
void hkpStiffSpringChainData::getRuntimeInfo_00e3af80(bool bFlag, unsigned int* pOut)
{
    if (bFlag)
    {
        unsigned int u = static_cast<unsigned int>(m_pConstraintInfo.m_iElementCount);
        pOut[1] = u;
        pOut[0] = u * 8;
    }
    else
    {
        pOut[1] = 0;
        pOut[0] = 0;
    }
}

// @fnv 0x00e3af30
// src: GUESS 0x00e3af30 (confidence: high)
int __cdecl hkpStiffSpringChainData_ReturnConstant_0x64()
{
    return 0x64;
}

// @fnv 0x00e3af40
// src: HAVOK_LIB 0x00e3af40
void hkpStiffSpringChainData::getConstraintInfo_00e3af40(::ConstraintInfo& info)
{
    info.m_kBridgeAtoms = &m_kBridgeAtoms;
    info.m_iSolverResultCount = 0;
    info.m_iSolverElementTemporaryCount = 0;
    info.m_maxNumExternalSlaveContactPoints = 0;
    info.m_iSchemaByteSize = 16;
    info.m_usSizeOfAllAtoms = sizeof(hkpBridgeAtoms);

    int size = m_pConstraintInfo.m_iElementCount;
    info.m_iSchemaByteSize += (size * 80 + 36 + 15) & ~15;
    info.m_iSolverResultCount = size;
    info.m_iSolverElementTemporaryCount = size;
}

// Runs the destructor and, when bit 0 of uiFlags is set, frees the object through operator delete; returns this.
// @fnv 0x00e3b4a0
hkpStiffSpringChainData* hkpStiffSpringChainData::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->hkpStiffSpringChainData::~hkpStiffSpringChainData();
    if (uiFlags & 1)
        hkpStiffSpringChainData::operator delete(this);
    return this;
}

extern "C" const LocalM128 DAT_01268370;
struct QuantizedBoundsData;
struct SolverSchemaHeader;
struct SixteenWordFloatRecord
{
    int m_unk00;
    int m_unk04;
    int m_fQueryInputValue;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_iBeforeFourthQueryValue;
    hkReal m_fFourthQueryValue;
    int m_unk28;
    int m_unk2c;
    const QuantizedBoundsData* m_pBodyA;
    const QuantizedBoundsData* m_pBodyB;
    const hkTransform* m_kBodyALocalFrame;
    const hkTransform* m_kBodyBLocalFrame;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    hkpConstraintChainInstance* m_pConstraintChainInstance;
    void* m_pByteBuffer;
    int m_unk68;
    int m_unk6c;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7c;
};
template <class T> struct OutputSlot31
{
    T* ptr;
    __forceinline OutputSlot31()
    {}
    __forceinline OutputSlot31(T* p) : ptr(p)
    {}
    __forceinline operator T*() const
    {
        return ptr;
    }
    __forceinline T* value() const
    {
        return ptr;
    }
    __forceinline T* const& cref() const
    {
        return ptr;
    }
    __forceinline T*& ref()
    {
        return ptr;
    }
};
struct QueryResultSchema
{
    OutputSlot31<SolverSchemaHeader> m_pQueryResultSchema;
};
// POD SIMD storage keeps the solver scratch frame free of vector construction.
union SolverVectorStorage
{
    LocalM128 m_vComponents;
};
struct hk1dLinearBilateralConstraintInfo
{
    SolverVectorStorage m_kPivotA;
    SolverVectorStorage m_kPivotB;
    SolverVectorStorage m_kConstraintAxis;
};
class hkpStiffSpringChainDataConstraintInfo
{
  public:
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkReal m_fSpringRestLength;
    int unk24;
    int unk28;
    int unk2c;
};
// A declaration-only view preserves the no-throw call at 0x00c7f640; the
// shared hkVector4 method omits that contract, and this view adds no data.
struct SolverPointTransform : public hkVector4
{
    void SetTransformedPoint(const hkTransform& t, const hkVector4& v) throw();
};
void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int sizeElem) throw();
extern "C" void __cdecl AppendEventRecord(const SixteenWordFloatRecord& in, QueryResultSchema& out, void* solverResults,
                                     int solverResultStriding) throw();
SolverSchemaHeader* __cdecl hkJacobianStiffSpringChainSchema_getJacobians(SolverSchemaHeader* schema) throw();
void __cdecl hkLoadVelocityAccumulators(SixteenWordFloatRecord* in) throw();
void __cdecl hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(const hk1dLinearBilateralConstraintInfo& info, const SixteenWordFloatRecord& in,
                          SolverSchemaHeader* schema, hkReal rhs) throw();
void __cdecl hkStiffSpringChainBuildJacobian(int numConstraints, hkReal tau, hkReal damping, hkReal cfm, int* offsets, hkUint32 base,
                          SolverSchemaHeader* schema, const SixteenWordFloatRecord& in, QueryResultSchema& out) throw();
__forceinline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
struct hkInplaceIntArray32
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    __forceinline hkInplaceIntArray32()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000 | 32;
    }
    __forceinline ~hkInplaceIntArray32()
    {
        hkMemoryAllocator* alloc = &hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc->bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(int));
        }
    }
    __forceinline void pushBackUnchecked(int v)
    {
        m_data[m_iElementCount] = v;
        m_iElementCount++;
    }
    __forceinline void AddBack(hkMemoryRouter* alloc, int v)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(alloc->m_heap, this, sizeof(int));
        }
        new (&m_data[m_iElementCount]) int(v);
        m_iElementCount++;
    }
};
static __forceinline LocalM128 hkLengthSquared3(const SolverVectorStorage& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
static __forceinline LocalM128 hkLengthInverse3(const SolverVectorStorage& v)
{
    LocalM128 len2 = hkLengthSquared3(v);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    return _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
}
static __forceinline hkReal hkNormalizeWithLength3(SolverVectorStorage& v)
{
    LocalM128 invLen = hkLengthInverse3(v);
    invLen = _mm_shuffle_ps(invLen, invLen, 0);
    hkReal length;
    _mm_store_ss(&length, _mm_mul_ss(hkLengthSquared3(v), invLen));
    v.m_vComponents = _mm_mul_ps(invLen, v.m_vComponents);
    return length;
}
// @fnv 0x00e3b0f0
// src: XBOX_PDB 0x00e3b0f0
void hkpStiffSpringChainData::buildJacobian_00e3b0f0(const SixteenWordFloatRecord& inNonConst, QueryResultSchema& out) volatile
{
    AppendEventRecord(inNonConst, out, inNonConst.m_pByteBuffer, 8);
    SixteenWordFloatRecord in = inNonConst;
    in.m_pConstraintChainInstance = 0;
    in.m_pByteBuffer = 0;
    hkInplaceIntArray32 velocityAccumulatorsOffsets;
    hkpConstraintChainInstance* instance = inNonConst.m_pConstraintChainInstance;
    int numConstraints = instance->m_ppRigidBodies.m_iElementCount - 1;
    hkUint32 base = (hkUint32)inNonConst.m_pBodyA - instance->m_kActorEntries[0]->m_uiFilterInfo;
    hkpEntity* rA = instance->m_ppRigidBodies.m_data[0];
    in.m_pBodyB = (const QuantizedBoundsData*)(base + rA->m_uiFilterInfo);
    velocityAccumulatorsOffsets.pushBackUnchecked((hkUint32)in.m_pBodyB - base);
    in.m_kBodyBLocalFrame = &rA->m_pMotionState.m_kMotionState.m_kMotionTransform;
    in.m_fFourthQueryValue = 1.0f;
    in.m_iBeforeFourthQueryValue = in.m_fQueryInputValue;
    SolverSchemaHeader* schema = hkJacobianStiffSpringChainSchema_getJacobians(out.m_pQueryResultSchema.value());
    for (int i = 0; i < numConstraints; i++)
    {
        in.m_pBodyA = in.m_pBodyB;
        in.m_kBodyALocalFrame = in.m_kBodyBLocalFrame;
        hkpEntity* rB = instance->m_ppRigidBodies.m_data[i + 1];
        in.m_pBodyB = (const QuantizedBoundsData*)(base + rB->m_uiFilterInfo);
        velocityAccumulatorsOffsets.AddBack(&hkMemoryRouter_getInstance(),
                                            (hkUint32)in.m_pBodyB - base);
        in.m_kBodyBLocalFrame = &rB->m_pMotionState.m_kMotionState.m_kMotionTransform;
        hk1dLinearBilateralConstraintInfo bp;
        reinterpret_cast<SolverPointTransform&>(bp.m_kPivotA).SetTransformedPoint(*in.m_kBodyALocalFrame, m_pConstraintInfo.m_data[i].m_kPivotInA);
        reinterpret_cast<SolverPointTransform&>(bp.m_kPivotB).SetTransformedPoint(*in.m_kBodyBLocalFrame, m_pConstraintInfo.m_data[i].m_kPivotInB);
        SolverVectorStorage dir;
        dir.m_vComponents = _mm_sub_ps(bp.m_kPivotA.m_vComponents, bp.m_kPivotB.m_vComponents);
        hkReal length = hkNormalizeWithLength3(dir);
        if (length > 0.0f)
        {
            bp.m_kConstraintAxis.m_vComponents = dir.m_vComponents;
        }
        else
        {
            bp.m_kConstraintAxis.m_vComponents = DAT_01268370;
            length = 0.0f;
        }
        hkLoadVelocityAccumulators(&in);
        hkReal rhs = m_pConstraintInfo.m_data[i].m_fSpringRestLength - length;
        hk1dLinearBilateralConstraintBuildJacobianWithCustomRhs_noSchema(bp, in, schema, rhs);
        schema = reinterpret_cast<SolverSchemaHeader*>(reinterpret_cast<char*>(schema) + 0x30);
    }
    hkStiffSpringChainBuildJacobian(numConstraints, m_fTau, m_fMotorDamping, m_fMaxErrorDistance, velocityAccumulatorsOffsets.m_data, base,
                 schema, inNonConst, out);
}
