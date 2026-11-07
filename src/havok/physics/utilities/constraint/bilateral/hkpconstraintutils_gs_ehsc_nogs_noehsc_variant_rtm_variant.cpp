#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkpRigidBody.h"
#include "../../../../../../include/hkpSetLocalTransformsConstraintAtom.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkReferencedObject.h"
// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct BSAudio;
BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}
struct Block5
{
    int unk00, unk04, unk08, unk0c, unk10;
};
struct Block5b
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    unsigned char unk07;
    int unk08, unk0c, unk10;
};
struct CloneDataBase : hkReferencedObject
{
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    __m128 unk20, unk30, unk40, unk50, unk60, unk70;
};
struct CloneDataA : CloneDataBase
{
    Block5 unk80;
    Block5b unk94;
    Block5 unka8;
    CloneDataA* FUN_00d4f2a0();
    void hkpRagdollLimitsData_setConeLimitStabilization(hkBool flag);
};
struct CloneDataB : CloneDataBase
{
    Block5 unk80;
    CloneDataB* FUN_00d52fc0();
};
struct SourceDataHeader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
};
struct SourceData : SourceDataHeader
{
    __m128 unk20, unk30, unk40, unk50, unk60, unk70, unk80;
};
struct SourceDataB : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Block5 unkc0;
};
struct SourceDataA : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc,
        unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    Block5 unkfc;
    Block5b unk110;
    Block5 unk124;
};
struct Instance;
struct Instance : hkReferencedObject
{
    int unk08;
    SourceData* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1c;
    Instance* FUN_00cf3ea0(void* entityA, void* entityB, CloneDataBase* data, int priority);
};
inline void* hkAlloc(int size)
{
    hkReferencedObject* p = (hkReferencedObject*)audio()->heap().blockAlloc(size);
    p->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}
Instance* __cdecl CloneInstanceFromSource(Instance* src);
class FnvSink
{
  public:
    virtual void Slot0() throw();
    virtual void Slot1() throw();
    virtual void Slot2() throw();
    virtual void Write(int level, unsigned int hash, const char* msg, const char* file, int line) throw();
};
extern FnvSink* DAT_01268360;
class MsgWriter
{
  public:
    void Init(char* buf, unsigned int cap) throw();
    void Append(const char* s) throw();
    void Finish() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
class FnvInner
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1C() throw();
    virtual unsigned int GetKind() throw();

    char unk04[0x0c];
    __m128 m_20;
    __m128 m_30;
    char unk40[0x10];
    __m128 m_50;
    char unk60[0x30];
    __m128 m_90;
};
class FnvHolder
{
  public:
    char unk00[0x0c];
    FnvInner* m_0c;
};
int hkpConstraintUtils_getConstraintPivots(FnvHolder* a0, __m128* a1, __m128* a2);
struct Ent
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    __m128 unkf0;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    __m128 unk120;
    int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    int unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    __m128 unk1b0;
    __m128 unk1c0;
    void hkpRigidBody_setPosition(__m128* v);
    void OnTrigger(int arg);
    void hkpRigidBody_setAngularVelocity(void* p);
};
struct FnvHolder2 : FnvHolder
{
    int unk10;
    Ent* unk14;
    Ent* unk18;
};
struct Conv
{
    __m128 m;
    void setTransformedPos_00c7f640(__m128* src, __m128* arg);
};
// Constraint pivots followed by their transformed positions.
struct WorkVectors
{
    __m128 va;
    __m128 vb;
    Conv cb;
    Conv ca;
};
extern "C"
{
    const __m128 DAT_010ec7f0 = {{1.0f, 1.0f, 1.0f, 1.0f}};
    const float DAT_010959f4 = 1e-6f;
}
bool* hkpConstraintUtils_checkAndFixConstraint(bool* out, FnvHolder2* h, float t, float t2);

// Keep the original inline operations with the shared class declarations.
__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}
__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline __m128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}
__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
__forceinline hkSimdReal hkVector4::getSimdAt3() const
{
    return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
}
__forceinline float& hkVector4::operator()(int a)
{
    return reinterpret_cast<float*>(&m_vComponents)[a];
}

__forceinline hkMatrix3::hkMatrix3()
{}
__forceinline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
__forceinline float& hkMatrix3::operator()(int r, int c)
{
    return getColumn(c)(r);
}
__forceinline hkRotation::hkRotation(const hkRotation& o)
{
    m_kColumn0 = o.m_kColumn0;
    m_kColumn1 = o.m_kColumn1;
    m_kColumn2 = o.m_kColumn2;
}
__forceinline const hkVector4& hkRotation::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
__forceinline hkRotation& hkTransform::getRotation()
{
    return reinterpret_cast<hkRotation&>(m_row0);
}
__forceinline hkVector4& hkTransform::getTranslation()
{
    return reinterpret_cast<hkVector4&>(m_row3);
}
__forceinline hkSimdReal hkpMotion::getMassInv() const
{
    return m_kInertiaAndMassInv.getSimdAt3();
}
__forceinline hkpMotion* hkpRigidBody::getRigidMotion()
{
    return &m_pMotionState;
}
__forceinline void hkpRigidBody::GetInertiaInvLocal(hkMatrix3& m)
{
    hkpMotion* motion = getRigidMotion();
    // The shared declaration calls the inertia getter slot vf24.
    typedef void (__thiscall *InertiaGetter)(hkpMotion*, hkMatrix3&);
    reinterpret_cast<InertiaGetter>((*reinterpret_cast<void***>(motion))[9])(motion, m);
}
__forceinline float hkpRigidBody::getMassInv()
{
    return getRigidMotion()->getMassInv();
}
__forceinline const hkVector4& hkpRigidBody::getCenterOfMassLocal()
{
    return m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMassLocal;
}

// @fnv 0x00e5a800
// src: GUESS 0x00e5a800 (confidence: low)
void __cdecl Object_ProcessAndReturnValue_00e5a800(Instance* constraint)
{
    SourceData* data = constraint->unk0c;
    hkpSetLocalTransformsConstraintAtom* transformsAtom = 0;
    switch (data->getType())
    {
    case 1:
        transformsAtom = (hkpSetLocalTransformsConstraintAtom*)&data->unk10;
        break;
    case 2:
        transformsAtom = (hkpSetLocalTransformsConstraintAtom*)&data->unk10;
        break;
    default:
        return;
    }

    hkpRigidBody* bodyA = (hkpRigidBody*)constraint->unk14;
    hkpRigidBody* bodyB = (hkpRigidBody*)constraint->unk18;

    const bool useRelativeInertia = true;

    float invInertiaA = 0.0f;
    {
        hkMatrix3 inertiaLocA;
        bodyA->GetInertiaInvLocal(inertiaLocA);
        hkRotation invRot = transformsAtom->m_kBodyALocalFrame.getRotation();
        reinterpret_cast<hkMatrix3&>(invRot).transpose();
        inertiaLocA.SetFromRotation(invRot);
        invInertiaA = float(inertiaLocA(1, 1) + inertiaLocA(2, 1)) + float(inertiaLocA(1, 2) + inertiaLocA(2, 2));
        if (useRelativeInertia && bodyA->getMassInv() > 1.192092896e-07f)
        {
            invInertiaA /= bodyA->getMassInv();
        }
    }

    float invInertiaB = 0.0f;
    {
        hkMatrix3 inertiaLocB;
        bodyB->GetInertiaInvLocal(inertiaLocB);
        hkRotation invRot = transformsAtom->m_kBodyBLocalFrame.getRotation();
        reinterpret_cast<hkMatrix3&>(invRot).transpose();
        inertiaLocB.SetFromRotation(invRot);
        invInertiaB = float(inertiaLocB(1, 1) + inertiaLocB(2, 1)) + float(inertiaLocB(1, 2) + inertiaLocB(2, 2));
        if (useRelativeInertia && bodyB->getMassInv() > 1.192092896e-07f)
        {
            invInertiaB /= bodyB->getMassInv();
        }
    }

    const hkVector4& axisA = transformsAtom->m_kBodyALocalFrame.getRotation().getColumn(0);
    hkVector4 pivotA;
    pivotA.setSub4(transformsAtom->m_kBodyALocalFrame.getTranslation(), bodyA->getCenterOfMassLocal());
    float pivotLengthAlongAxisA = pivotA.dot3(axisA);

    const hkVector4& axisB = transformsAtom->m_kBodyBLocalFrame.getRotation().getColumn(0);
    hkVector4 pivotB;
    pivotB.setSub4(transformsAtom->m_kBodyBLocalFrame.getTranslation(), bodyB->getCenterOfMassLocal());
    float pivotLengthAlongAxisB = pivotB.dot3(axisB);

    float invSumInertias = 1.0f / (invInertiaA + invInertiaB);
    float totalPivotLengthAlongAxis = pivotLengthAlongAxisA - pivotLengthAlongAxisB;
    float newPivotLenghtAlongAxisA = totalPivotLengthAlongAxis * invInertiaB * invSumInertias;
    float newPivotLenghtAlongAxisB = -totalPivotLengthAlongAxis * invInertiaA * invSumInertias;

    pivotA.addMul4(newPivotLenghtAlongAxisA - pivotLengthAlongAxisA, axisA);
    pivotB.addMul4(newPivotLenghtAlongAxisB - pivotLengthAlongAxisB, axisB);

    transformsAtom->m_kBodyALocalFrame.getTranslation().setAdd4(pivotA, bodyA->getCenterOfMassLocal());
    transformsAtom->m_kBodyBLocalFrame.getTranslation().setAdd4(pivotB, bodyB->getCenterOfMassLocal());
}
