// src/havok/physics/utilities/weapons/hkpballgun_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpballgun.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/weapons/hkpballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve the original intrinsic views: byte arrays change VC9 /GS instrumentation.
#define _INCLUDED_MM2
// Exe 0x00e470d0 fireBallGun: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#include "../../../../../include/hkBoolResult.h"
#include "../../../../../include/hkpBallGun.h"
#include "../../../../../include/hkpFirstPersonGun.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkpWorld.h"

typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
extern "C" LocalM128 _mm_setzero_ps();
// Shared hkMemoryRouter view: GetMonitorStream is bound to 0x00c85750 in other units.
extern "C"
{

    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_load_ss(float const*);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}

__forceinline void hkVector4::setMul4(float r, const hkVector4& a)
{
    LocalM128 t = _mm_load_ss(&r);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), a.m_vComponents);
}

__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, float r)
{
    LocalM128 t = _mm_load_ss(&r);
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), b.m_vComponents), a.m_vComponents);
}

struct hkpBallGunSweepOutput
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 m_unk20;
};

struct hkQuadTransform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;
};

struct hkpShapeBase : public hkReferencedObject
{
    void FUN_00c905b0();

    __forceinline void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        return b;
    }
    __forceinline void operator delete(void*)
    {}
};

struct FUN_00cd8160 : public hkpShapeBase
{
    FUN_00cd8160(hkReal radius) throw();
    hkUint32 unk08, unk0C, unk10, unk14, unk18, unk1C;
};

struct FUN_00cf5ea0
{
    FUN_00cf5ea0() throw();

    hkUint32 m_uiCollisionFilterData;
    hkpShapeBase* m_pCollisionShape;
    hkUint32 m_unk08;
    hkUint32 m_unk0C;
    hkVector4 m_vContactPosition;
    hkVector4 m_rotation;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_inertiaTensor0;
    hkVector4 m_inertiaTensor1;
    hkVector4 m_inertiaTensor2;
    hkVector4 m_kCenterOfMass1;
    hkReal m_fViscosityFriction;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    hkReal m_fSlipAngle;
    hkReal m_fElasticity;
    hkReal m_fSurfaceFriction;
    hkReal m_fRestitution;
    hkReal m_unkAC;
    hkReal m_fAllowedPenetrationDepth;
    hkUint8 m_bFlag;
    hkUint8 m_unkB5;
    hkUint8 m_unkB6;
    hkUint8 m_iAutoRemoveLevel;
    hkUint32 m_unkB8;
    hkUint32 m_unkBC;
};

// 0x00ca8c90 constructs hkpRigidBody; the shared header does not yet declare
// its hkpRigidBodyCinfo overload. Cast only this external entry to its thiscall ABI.
extern "C" void constructBallGunBullet() throw();
typedef hkpRigidBody* (__thiscall* BallGunBulletConstructor)(hkpRigidBody*, const FUN_00cf5ea0&);

__forceinline hkpRigidBody* createBallGunBullet(const FUN_00cf5ea0& info)
{
    hkpRigidBody* body = static_cast<hkpRigidBody*>(hkpShapeBase::operator new(sizeof(hkpRigidBody)));
    if (body)
        return reinterpret_cast<BallGunBulletConstructor>(&constructBallGunBullet)(body, info);
    return 0;
}


struct hkpBallGunListener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void bulletCreatedCallback(hkpRigidBody* bullet);
    virtual void bulletDeletedCallback(hkpRigidBody* bullet);
    virtual void gunFiredCallback(const hkVector4* from, const hkVector4* to);
};

template <typename T> struct CapacityGrowingArray
{
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void hkQueue_hkpRigidBody_setCapacity(int n);

    __forceinline int GetLogicalSize() const
    {
        return m_iNodeCount;
    }

    __forceinline void increaseCapacity()
    {
        if (m_pRayCursor == 0)
        {
            hkQueue_hkpRigidBody_setCapacity(8);
        }
        else
        {
            hkQueue_hkpRigidBody_setCapacity(m_pRayCursor * 2);
        }
    }

    __forceinline void enqueue(const T& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
        {
            increaseCapacity();
        }
        if (m_pTail == m_pRayCursor)
        {
            m_pTail = 0;
        }
        m_data[m_pTail++] = element;
        m_iNodeCount++;
    }

    __forceinline void dequeue(T& data)
    {
        data = m_data[m_pFirstNode];
        if (++m_pFirstNode == m_pRayCursor)
        {
            m_pFirstNode = 0;
        }
        m_iNodeCount--;
    }
};

void hkpInertiaTensorComputer_setShapeVolumeMassProperties(const hkpShapeBase* shape, hkReal mass, FUN_00cf5ea0& out);
int hkpWorldq_CastSphereAndStoreHit(hkpWorld* world, const hkVector4& start, hkReal radius, const hkVector4& end,
                 hkpBallGunSweepOutput& output);
void hkpFirstPersonGun_calcVelocityToTarget(const hkVector4& position, const hkVector4& target, const hkVector4& gravity,
                  hkReal speed, hkVector4& velocityOut);

// The shared hkpBallGun has no fireGun declaration yet; ECX carries the gun and
// the unused EDX argument preserves the original thiscall stack arguments.
// @fnv 0x00e470d0
void __fastcall fireBallGun(hkpBallGun* gun, void*, hkpWorld* world, const hkQuadTransform& viewTransform)
{
    hkVector4 forward = viewTransform.m_kColumn0;
    hkVector4 eye = viewTransform.m_vTranslation;
    hkVector4 start;
    start.setAdd4(eye, forward);
    hkVector4 end;
    end.setAddMul4(start, forward, 200.0f);

    FUN_00cf5ea0 ci;
    ci.m_pCollisionShape = new FUN_00cd8160(gun->m_fBulletRadius);
    ci.m_fViscosityFriction = gun->m_fBulletMass;
    ci.m_fAllowedPenetrationDepth = 0.01f;
    ci.m_fSurfaceFriction = 0.2f;
    ci.m_iAutoRemoveLevel = 6;
    ci.m_bFlag = 2;
    ci.m_fElasticity = 1.0f;
    hkpInertiaTensorComputer_setShapeVolumeMassProperties(ci.m_pCollisionShape, gun->m_fBulletMass * 2.0f, ci);
    ci.m_fViscosityFriction = gun->m_fBulletMass;
    ci.m_fLinearDamping = 0.0f;
    ci.m_fAngularDamping = 0.4f;
    ci.m_vContactPosition.setAdd4(start, gun->m_kBulletDirection);

    hkpBallGunSweepOutput output;
    if (!hkpWorldq_CastSphereAndStoreHit(world, start, gun->m_fBulletRadius, end, output))
    {
        hkpFirstPersonGun_calcVelocityToTarget(ci.m_vContactPosition, output.m_vContactPosition, world->m_kGravity, gun->m_fBulletVelocity,
                     ci.m_kTranslationalVelocity);
    }
    else
    {
        ci.m_kTranslationalVelocity.setMul4(gun->m_fBulletVelocity, forward);
    }

    hkVector4 target = output.m_vContactPosition;
    int i;
    for (i = 0; i < gun->m_kListeners.m_iElementCount; i++)
    {
        static_cast<hkpBallGunListener*>(gun->m_kListeners.m_data[i])->gunFiredCallback(&eye, &target);
    }

    hkpRigidBody* bullet = createBallGunBullet(ci);
    ci.m_pCollisionShape->FUN_00c905b0();
    bullet->m_fBulletSpread = gun->m_fBulletSpread;

    for (i = 0; i < gun->m_kListeners.m_iElementCount; i++)
    {
        static_cast<hkpBallGunListener*>(gun->m_kListeners.m_data[i])->bulletCreatedCallback(bullet);
    }

    world->hkpWorld_addEntity(bullet, 1);

    CapacityGrowingArray<hkpRigidBody*>* addedBodies =
        static_cast<CapacityGrowingArray<hkpRigidBody*>*>(gun->m_pBulletQueue);
    addedBodies->enqueue(bullet);

    if (static_cast<CapacityGrowingArray<hkpRigidBody*>*>(gun->m_pBulletQueue)->GetLogicalSize() > gun->m_iBulletBatchCount)
    {
        hkpRigidBody* rb;
        static_cast<CapacityGrowingArray<hkpRigidBody*>*>(gun->m_pBulletQueue)->dequeue(rb);
        for (i = gun->m_kListeners.m_iElementCount - 1; i >= 0; i--)
        {
            static_cast<hkpBallGunListener*>(gun->m_kListeners.m_data[i])->bulletDeletedCallback(rb);
        }
        if (rb->m_pOwningWorld)
        {
            world->ProcessTarget(rb);
        }
        rb->removeReference();
    }
}
