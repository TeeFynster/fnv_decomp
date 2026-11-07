
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkppointtopathconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkppointtopathconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original SIMD lane type: byte-array lanes in the CRT version add /GS cookies.
#define _INCLUDED_MM2
// Exe 0x00dee870 FUN_00dee870: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ps(const float*);
}

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkpConstraintAtom.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpBridgeAtoms.h"
#include "../../../../../../../include/hkpBridgeConstraintAtom.h"
#include "../../../../../../../include/hkpParametricCurve.h"
#include "../../../../../../../include/hkpSetLocalTransformsConstraintAtom.h"

typedef float hkReal;

class hkpPointToPathConstraintData : public hkpConstraintData
{
public:
    enum OrientationConstraintType
    {
        CONSTRAIN_ORIENTATION_INVALID = 0,
        CONSTRAIN_ORIENTATION_NONE = 1,
        CONSTRAIN_ORIENTATION_ALLOW_SPIN = 2,
        CONSTRAIN_ORIENTATION_TO_PATH = 3,
        CONSTRAIN_ORIENTATION_MAX_ID = 4
    };
    hkpBridgeAtoms m_kBridgeAtoms;
    hkpParametricCurve* m_path;
    hkReal m_fFriction;
    signed char m_cOrientationConstraintType;
    char pad21[15];
    hkTransform m_kLocalTransforms[2];
};

inline hkTransform::hkTransform()
{}
inline void hkTransform::operator=(const hkTransform& transform)
{
    m_kColumn0 = transform.m_kColumn0;
    m_kColumn1 = transform.m_kColumn1;
    m_kColumn2 = transform.m_kColumn2;
    m_vTranslation = transform.m_vTranslation;
}

inline float& hkVector4::operator()(int index)
{
    return reinterpret_cast<float*>(&m_vComponents)[index];
}
inline const float& hkVector4::operator()(int index) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[index];
}

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
inline void hkRotation::setIdentity()
{
    hkVector4 zero;
    zero.setZero4();
    m_kColumn0 = zero;
    m_kColumn1 = zero;
    m_kColumn2 = zero;
    m_kColumn0(0) = 1.0f;
    m_kColumn1(1) = 1.0f;
    m_kColumn2(2) = 1.0f;
}

inline void hkTransform::setIdentity()
{
    reinterpret_cast<hkRotation*>(&m_kColumn0)->setIdentity();
    reinterpret_cast<hkVector4*>(&m_vTranslation)->setZero4();
}
inline void hkTransform::setTranslation(const hkVector4& translation)
{
    m_vTranslation = *reinterpret_cast<const LocalM128*>(&translation);
}

// @fnv 0x00dee720
// src: HAVOK_LIB 0x00dee720
void __stdcall hkpPointToPathConstraintData_getRuntimeInfo(int aiUnused, void* apData)
{
    *(int*)((char*)apData + 4) = 7;
    *(int*)apData = 0x3c;
}

struct FUN_00dee7f0_class
{
    void __thiscall hkpPointToPathConstraintData_getConstraintInfo(void* a);
};

// Fills the struct at a with a pointer to this+0xc and constant fields 0, 0x180, 7, 8, 0xc.
// @fnv 0x00dee7f0
// src: HAVOK_LIB 0x00dee7f0
void __thiscall FUN_00dee7f0_class::hkpPointToPathConstraintData_getConstraintInfo(void* a)
{
    *(int*)((char*)a + 0x10) = (int)((char*)this + 0xc);
    *(int*)((char*)a + 0x14) = 0xc;
    *(int*)((char*)a + 0x0) = 0;
    *(int*)((char*)a + 0x4) = 0x180;
    *(int*)((char*)a + 0x8) = 7;
    *(int*)((char*)a + 0xc) = 8;
}

extern int DAT_010da004;
extern int _DAT_0102e388;
struct FUN_00dee7d0_class
{
    void* m_vft;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    hkReferencedObject* m_obj;
    void __thiscall Destroy();
};
// @fnv 0x00dee7d0
void __thiscall FUN_00dee7d0_class::Destroy()
{
    hkReferencedObject* p = m_obj;
    m_vft = &DAT_010da004;
    if (p)
        p->removeReference();
    m_vft = &_DAT_0102e388;
}

// @fnv 0x00dee740
// src: GUESS 0x00dee740 (confidence: low)
int __cdecl Object_ComputeValue_00dee740()
{
    return 3;
}

struct FUN_00c7f640_Class
{
    void __thiscall setTransformedPos_00c7f640(unsigned int arg, void* position);
};
class FUN_00dee820_Class
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
    unsigned int m_60;
    void hkpPointToPathConstraintData_calcPivot(unsigned int a, FUN_00c7f640_Class* owner);
};
// @fnv 0x00dee820
// src: HAVOK_LIB 0x00dee820
void FUN_00dee820_Class::hkpPointToPathConstraintData_calcPivot(unsigned int uiValue, FUN_00c7f640_Class* owner)
{
    owner->setTransformedPos_00c7f640(uiValue, &m_60);
}

class hkObjectDEE8
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_18;
    int unk1c;
    char m_20;

    hkBool hkpPointToPathConstraintData_isValid() const;
};

// Returns true when m_18 is non-null and m_20 is set.
// @fnv 0x00dee840
// src: HAVOK_LIB 0x00dee840
hkBool hkObjectDEE8::hkpPointToPathConstraintData_isValid() const
{
    return m_18 != 0 && m_20;
}

inline hkpConstraintData::hkpConstraintData() throw() : m_ulUserData(0)
{}

inline hkpConstraintAtom::hkpConstraintAtom(AtomType type) : m_type(type)
{}

inline hkpBridgeConstraintAtom::hkpBridgeConstraintAtom() : hkpConstraintAtom(TYPE_BRIDGE)
{}

class FUN_00dee750 : public hkpConstraintData
{
  public:
    FUN_00dee750() throw();
    virtual ~FUN_00dee750() throw();

    hkpBridgeAtoms m_kBridgeAtoms;
    void* m_path;
    float m_fFriction;
    signed char m_cOrientationConstraintType;
    hkTransform m_kLocalTransforms[2];
};

// @fnv 0x00dee750
FUN_00dee750::FUN_00dee750() throw() : m_path(0), m_fFriction(0.0f), m_cOrientationConstraintType(1)
{
    m_kLocalTransforms[0].setIdentity();
    m_kLocalTransforms[1].setIdentity();
    m_kBridgeAtoms.m_kBridgeAtom.hkpBridgeConstraintAtom_init(this);
}

// Calls at 0x00c7f640/690/700 are the hkVector4 transform operations, with 16-byte SIMD storage.
namespace fnv_00dee870 {

inline void setPathFrameCross(hkVector4& result, const hkVector4& a, const hkVector4& b)
{
    LocalM128 t1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
    LocalM128 t2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
    LocalM128 t3 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
    LocalM128 t0 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
    result.m_vComponents = _mm_sub_ps(_mm_mul_ps(t1, t0), _mm_mul_ps(t3, t2));
}

// A 96-byte tangent/binormal/frame scratch aggregate; shared Pair is two integers (8 bytes).
struct PathFrameScratch
{
    hkVector4 lo;
    hkVector4 hi;
    hkTransform res;
};

struct Obj_00dee870
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkpParametricCurve* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    hkTransform m_30;
    hkTransform m_70;
    void hkpPointToPathConstraintData_setInWorldSpace(void* a1, void* a2, void* a3, void* a4, void* a5);
};

// Swaps m_18 to a4 (adding and releasing references), copies a5 into m_70, and builds m_30 from a1, a2, a3, a5 and a4's nearest-point, tangent and binormal results.
// @fnv 0x00dee870
// src: XBOX_PDB 0x00dee870
void Obj_00dee870::hkpPointToPathConstraintData_setInWorldSpace(void* a1, void* a2, void* a3, void* a4, void* a5)
{
    hkTransform xform;
    hkTransform tmpMat;
    hkVector4 v1;
    PathFrameScratch pair;
    hkTransform basis;

    if (a4)
    {
        static_cast<hkpParametricCurve*>(a4)->addReference();
    }
    if (m_18)
    {
        m_18->removeReference();
    }
    m_18 = (hkpParametricCurve*)a4;
    m_70 = *(hkTransform*)a5;
    xform.SetProduct(*(hkTransform*)a2, *(hkTransform*)a5);
    v1.hkVector4_setTransformedInversePos(xform, *static_cast<const hkVector4*>(a3));
    // Shared curve declarations still name the opaque VectorQ ABI parameter type.
    float fTime = m_18->FindNearestPoint(0.0f, reinterpret_cast<const VectorQ&>(v1), reinterpret_cast<VectorQ&>(v1));
    m_18->GetTangentAt(fTime, reinterpret_cast<VectorQ&>(pair.hi));
    m_18->GetBinormal(fTime, reinterpret_cast<VectorQ&>(pair.lo));
    basis.m_kColumn1 = pair.lo.m_vComponents;
    basis.m_kColumn0 = pair.hi.m_vComponents;
    hkVector4 cross;
    setPathFrameCross(cross, pair.lo, pair.hi);
    basis.m_kColumn2 = cross.m_vComponents;
    basis.m_vTranslation = v1.m_vComponents;
    tmpMat.SetProduct(*(hkTransform*)a5, basis);
    xform.SetProduct(*(hkTransform*)a2, tmpMat);
    pair.res.hkTransform_setMulInverseMul(a1, &xform);
    m_30 = pair.res;
}
}  // namespace fnv_00dee870

namespace fnv_00deea00 {

namespace hkDEEA {

struct hkpPointToPathAtoms
{
    hkpSetLocalTransformsConstraintAtom m_kTransforms;
};

class hkpPointToPathConstraintData : public hkpConstraintData
{
  public:
    void setInBodySpace_00deea00(const hkVector4& kPivotA, const hkVector4& kPivotB, hkpParametricCurve* pkPath);

    unsigned int unk0C, unk10, unk14;
    hkpParametricCurve* m_path;
    unsigned int unk1C;
    hkpPointToPathAtoms m_kBridgeAtoms;
};

// Replaces the parametric curve path, updating reference counts, and sets the bridge atom local frame translations from the given pivots.
// @fnv 0x00deea00
// src: XBOX_PDB 0x00deea00
void hkpPointToPathConstraintData::setInBodySpace_00deea00(const hkVector4& kPivotA, const hkVector4& kPivotB,
                                                hkpParametricCurve* pkPath)
{
    if (pkPath)
    {
        pkPath->addReference();
    }
    if (m_path)
    {
        m_path->removeReference();
    }
    m_path = pkPath;
    m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.setIdentity();
    m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.setIdentity();
    m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.setTranslation(reinterpret_cast<const ::hkVector4&>(kPivotA));
    m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.setTranslation(reinterpret_cast<const ::hkVector4&>(kPivotB));
}
}
}  // namespace fnv_00deea00

#include <math.h>
extern "C" void _WriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _ReadWriteBarrier(void);

extern LocalM128 DAT_010c44d0;

class hkBoolC
{
  public:
    char m_cBooleanValue;
    hkBoolC(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

typedef hkReal(__thiscall* CurveLengthCall)(hkpParametricCurve*, hkReal);
struct CurveDispatchTable
{
    void* destructor;
    void* vf04;
    void* vf08;
    void* vf0c;
    void* nearestPoint;
    void* tangent;
    void* start;
    void* end;
    CurveLengthCall length;
};
struct CurveDispatch
{
    CurveDispatchTable* table;
};

struct PathRuntime
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
    hkReal m_fValueAtOffset38;
};

struct QueryIn
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
    const hkTransform* m_kBodyALocalFrame;
    const hkTransform* m_kBodyBLocalFrame;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    PathRuntime* m_pByteBuffer;
};

struct QueryOut;

struct LinearRow
{
    hkVector4 m_kPivotA;
    hkVector4 m_kPivotB;
    hkVector4 m_kAxisEndPoints;
};
struct FrictionRow
{
    hkVector4 m_kPivotVector;
    hkVector4 m_kAxisEndPoints;
    hkReal m_fFriction;
    PathRuntime* m_pRuntime;
};
struct AngularRow
{
    hkVector4 m_kAxisEndPoints;
    hkVector4 m_perpA;
    hkVector4 m_perpB;
};
struct LimitRow
{
    hkVector4 m_kPivotA;
    hkVector4 m_kPivotB;
    hkVector4 m_kAxisEndPoints;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
};

void __cdecl AppendEventRecord(const QueryIn& in, QueryOut& out, PathRuntime* runtime, int size);
void __cdecl hk1dLinearFrictionBuildJacobian(FrictionRow* row, const QueryIn& in, QueryOut& out);
void __cdecl hk1dLinearBilateralConstraintBuildJacobian(LinearRow* row, const QueryIn& in, QueryOut& out);
void __cdecl hk1dAngularBilateralConstraintBuildJacobian(AngularRow* row, const QueryIn& in, QueryOut& out);
void __cdecl hk1dLinearLimitBuildJacobian(LimitRow* row, const QueryIn& in, QueryOut& out);

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetCross(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

static __forceinline LocalM128 hkCross(const LocalM128 v0, const LocalM128 v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0, v0, 0xc9), _mm_shuffle_ps(v1, v1, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0, v0, 0xd2), _mm_shuffle_ps(v1, v1, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetNeg4(hkVector4& out, const hkVector4& v)
{
    out.m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}

static __forceinline CurveLengthCall& lengthSlot(CurveDispatchTable* table)
{
    CurveLengthCall& result = table->length;
    _WriteBarrier();
    return result;
}
struct PointToPathData : public hkpPointToPathConstraintData
{
    void hkpPointToPathConstraintData_buildJacobian(const QueryIn& in, QueryOut& out);
};

// Fills QueryOut with friction, linear, angular, and limit constraint rows for a point-to-path constraint using the nearest path point.
// @fnv 0x00deea90
// src: XBOX_PDB 0x00deea90
void PointToPathData::hkpPointToPathConstraintData_buildJacobian(const QueryIn& in, QueryOut& out)
{
    AppendEventRecord(in, out, in.m_pByteBuffer, 8);

    hkTransform pathToWorld;
    pathToWorld.SetProduct(*in.m_kBodyBLocalFrame, m_kLocalTransforms[1]);
    hkTransform bodyToWorld;
    bodyToWorld.SetProduct(*in.m_kBodyALocalFrame, m_kLocalTransforms[0]);

    hkVector4& headingAws = reinterpret_cast<hkVector4&>(bodyToWorld.m_kColumn0);
    PathRuntime* runtime = in.m_pByteBuffer;

    hkVector4 pathPointWs;
    hkVector4 tangentWs;
    {
        hkVector4 pivotInPathSpace;
        pivotInPathSpace.hkVector4_setTransformedInversePos(pathToWorld, reinterpret_cast<const hkVector4&>(bodyToWorld.m_vTranslation));
        runtime->m_fValueAtOffset38 =
            m_path->FindNearestPoint(runtime->m_fValueAtOffset38, reinterpret_cast<const VectorQ&>(pivotInPathSpace),
                                     reinterpret_cast<VectorQ&>(pivotInPathSpace));

        pathPointWs.setTransformedPos_00c7f640(pathToWorld, pivotInPathSpace);

        m_path->GetTangentAt(runtime->m_fValueAtOffset38, reinterpret_cast<VectorQ&>(pivotInPathSpace));
        tangentWs.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation&>(pathToWorld), pivotInPathSpace);
    }

    hkVector4 perpWs1;
    hkCalculatePerpendicularVector(tangentWs, perpWs1);
    hkNormalize3(perpWs1);

    hkVector4 perpWs2;
    perpWs2.m_vComponents = hkCross(tangentWs.m_vComponents, perpWs1.m_vComponents);

    hkReal distance = -m_path->GetCurvature(runtime->m_fValueAtOffset38);
    hkVector4 limitPivot;
    limitPivot.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_set_ps1(distance), tangentWs.m_vComponents),
                                          bodyToWorld.m_vTranslation);

    if (m_fFriction > 0.0f)
    {
        FrictionRow friction;
        friction.m_kAxisEndPoints = tangentWs;
        friction.m_kPivotVector = limitPivot;
        friction.m_fFriction = m_fFriction;
        friction.m_pRuntime = runtime;
        hk1dLinearFrictionBuildJacobian(&friction, in, out);
    }

    LinearRow linear;
    linear.m_kPivotA = reinterpret_cast<const hkVector4&>(bodyToWorld.m_vTranslation);
    linear.m_kPivotB = pathPointWs;
    linear.m_kAxisEndPoints = perpWs1;
    hk1dLinearBilateralConstraintBuildJacobian(&linear, in, out);
    linear.m_kAxisEndPoints = perpWs2;
    hk1dLinearBilateralConstraintBuildJacobian(&linear, in, out);

    if (m_cOrientationConstraintType > CONSTRAIN_ORIENTATION_NONE)
    {
        AngularRow angular;
        angular.m_kAxisEndPoints = tangentWs;
        angular.m_perpB = reinterpret_cast<const hkVector4&>(bodyToWorld.m_kColumn2);
        angular.m_perpA = reinterpret_cast<const hkVector4&>(bodyToWorld.m_kColumn1);
        hk1dAngularBilateralConstraintBuildJacobian(&angular, in, out);
        angular.m_perpB = reinterpret_cast<const hkVector4&>(bodyToWorld.m_kColumn1);
        hkSetNeg4(angular.m_perpA, reinterpret_cast<const hkVector4&>(bodyToWorld.m_kColumn2));
        hk1dAngularBilateralConstraintBuildJacobian(&angular, in, out);

        if (m_cOrientationConstraintType == CONSTRAIN_ORIENTATION_TO_PATH)
        {
            hkVector4 binormal;
            m_path->GetBinormal(runtime->m_fValueAtOffset38, reinterpret_cast<VectorQ&>(binormal));
            hkVector4 binormalWs;
            binormalWs.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation&>(pathToWorld), binormal);
            angular.m_kAxisEndPoints = reinterpret_cast<const hkVector4&>(bodyToWorld.m_kColumn2);
            hkSetNeg4(angular.m_perpB, binormalWs);
            angular.m_perpA = headingAws;
            hk1dAngularBilateralConstraintBuildJacobian(&angular, in, out);
        }
    }

    if (!m_path->IsClosedCurve())
    {
        LimitRow limit;
        limit.m_kPivotA = reinterpret_cast<const hkVector4&>(bodyToWorld.m_vTranslation);
        limit.m_kPivotB = limitPivot;
        limit.m_kMinimumCorner = m_path->GetCurvature(m_path->GetStreamStart());
        {
            CurveLengthCall& length = lengthSlot(reinterpret_cast<CurveDispatch*>(m_path)->table);
            limit.m_kMaximumCorner = length(m_path, m_path->GetStreamEnd());
        }
        limit.m_kAxisEndPoints = tangentWs;
        hk1dLinearLimitBuildJacobian(&limit, in, out);
    }
}

struct PathDeleteAllocator
{
    virtual void vf00();
    virtual void vf04();
    virtual void ReleaseBlock(void* object, int size);
};

struct PathDeleteRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    PathDeleteAllocator* heap;
};

PathDeleteRouter* __cdecl hkMemoryRouter_getInstance();

struct PathDeleteData : hkpPointToPathConstraintData
{
    void __thiscall Destroy();
    void* __thiscall FUN_00deef10(unsigned char flags);
};

// Calls the base destructor, then if flags bit 0 is set, releases this block through the router heap using m_usMemSizeAndFlags, and returns this.
// @fnv 0x00deef10
void* __thiscall PathDeleteData::FUN_00deef10(unsigned char flags)
{
    Destroy();
    if (flags & 1)
    {
        PathDeleteRouter* router = hkMemoryRouter_getInstance();
        router->heap->ReleaseBlock(this, m_usMemSizeAndFlags);
    }
    return this;
}
