// Shared Havok layouts. Only construction declarations absent from the shared
// headers remain local.
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMatrix3.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkError.h"
#include "../../../../../include/hkOstream.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpMotion.h"
#include "../../../../../include/hkpMaxSizeMotion.h"
#include "../../../../../include/hkMotionState.h"
#include "../../../../../include/hkQuaternion.h"
#include "../../../../../include/hkUFloat8.h"

// These value types are initialized by the surrounding SIMD code.
inline hkAabb::hkAabb() {}

extern float DAT_01016248;
inline float lowerPair(float left, float right)
{
    return left < right ? left : right;
}
inline float lowerPairReversed(float left, float right)
{
    return left > right ? right : left;
}

#include <xmmintrin.h>
#include <math.h>
#include "../../../../../include/hkpFixedRigidMotion.h"
extern "C" int DAT_01268370;
extern "C" double __cdecl sqrt(double);
static inline float CA8Sqrtf(float x)
{
    return ((float)sqrt((double)x));
}
static inline float CA8Sqrt(float r)
{
    return CA8Sqrtf(r);
}
static inline float CA8Max2(float a, float b)
{
    return (a > b) ? a : b;
}

struct hkpRigidBodyCinfo;

// Shared data layout; these construction entry points are not declared by
// hkpRigidBody.h or hkpEntity.h yet.
struct RigidBodyConstruction : hkpRigidBody
{
    void FUN_00c9cce0(const hkpShape* shape) throw();
    void hkpRigidBody_updateCachedShapeInfo(const hkpShape* shape, hkVector4* result) throw();
    void hkpRigidBody_enableDeactivation(bool enabled) throw();
    void hkpRigidBody_setAngularVelocity(const hkVector4& velocity) throw();
    RigidBodyConstruction* AllocateStorage_00ca8c90(const hkpRigidBodyCinfo& info);
};

// @fnv 0x00ca8150
// src: XBOX_PDB 0x00ca8150
void RigidBodyConstruction::hkpRigidBody_updateCachedShapeInfo(const hkpShape* seg, hkVector4* dst) throw()
{
    hkAabb pair;
    seg->CalculateAabb(reinterpret_cast<const hkTransform&>(DAT_01268370), 0.0f, pair);
    __m128 a = *(const __m128*)&pair.m_kMinimumCorner;
    __m128 b = *(const __m128*)&pair.m_kMaximumCorner;
    _mm_store_ps(&dst->x, _mm_sub_ps(b, a));

    hkVector4& p = pair.m_kMinimumCorner;
    unsigned int* target = reinterpret_cast<unsigned int*>(&p);
    const unsigned int* source = reinterpret_cast<const unsigned int*>(&m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMassLocal);
    target[0] = source[0];
    target[1] = source[1];
    target[2] = source[2];
    target[3] = source[3];
    __m128 pv = _mm_load_ps(&p.x);
    __m128 d0 = _mm_sub_ps(b, pv);
    __m128 d1 = _mm_sub_ps(a, pv);
    __m128 x0 = _mm_mul_ps(d0, d0);
    float db;
    _mm_store_ss(&db, _mm_add_ss(_mm_shuffle_ps(x0, x0, 0xaa), _mm_add_ss(_mm_shuffle_ps(x0, x0, 0x55), x0)));
    __m128 x1 = _mm_mul_ps(d1, d1);
    float da;
    _mm_store_ss(&da, _mm_add_ss(_mm_shuffle_ps(x1, x1, 0xaa), _mm_add_ss(_mm_shuffle_ps(x1, x1, 0x55), x1)));

    m_pMotionState.m_kMotionState.m_fObjectRadius = CA8Sqrt(CA8Max2(db, da));
}

// Only the initialization methods missing from the shared headers live here.
struct RigidMotionInitialization : hkpMaxSizeMotion
{
    void FUN_00c86420(int) throw();
};
inline void* operator new(std::size_t, void* memory) throw()
{
    return memory;
}
struct hkpRigidBodyCinfo
{
    unsigned int collisionFilterInfo;
    const hkpShape* shape;
    hkReferencedObject* localFrame;
    unsigned char response, unk0d;
    unsigned short responseCount;
    hkVector4 position;
    hkQuaternion rotation;
    hkVector4 linearVelocity, angularVelocity;
    hkMatrix3 inertia;
    hkVector4 centerOfMass;
    float mass, linearDamping, angularDamping;
    unsigned short unk9c, solverDeactivation;
    float friction, restitution, maxLinear, maxAngular, penetrationDepth;
    signed char motionType;
    unsigned char enableDeactivation;
    signed char deactivationClass, quality;
    unsigned char removalLevel, responseModifier;
    signed char shapeKeys;
    unsigned char forceCollide;
};

unsigned char __cdecl GetSubtreeDepth(const hkpShape* shape) throw();
extern float DAT_0104da48;

extern hkError* DAT_01268360;

static __declspec(noinline) void ComputeScaledMinimum(hkpCollidable* coll, const hkVector4& he)
{
    float lo = lowerPair(he.x, lowerPair(he.y, he.z));
    float hi = he.x > he.y ? he.x : he.y;
    if (he.z > hi)
        hi = he.z;
    coll->m_fAllowedPenetrationDepth = lowerPairReversed(hi * DAT_01016248, lo);
    coll->m_kBoundingVolumeData.m_pChildShapeKeys = coll->m_kBoundingVolumeData.m_pChildShapeAabbs;
}

extern void* DAT_010c7888;
// @fnv 0x00ca8c90
// src: GUESS 0x00ca8c90 (confidence: low)
RigidBodyConstruction* RigidBodyConstruction::AllocateStorage_00ca8c90(const hkpRigidBodyCinfo& info)
{
    FUN_00c9cce0(info.shape);
    *(void**)this = &DAT_010c7888;
    *reinterpret_cast<unsigned char*>(&m_iMaterialIndex.m_eResponseType) = info.response;
    m_usNextProcessCallbackDelay = info.responseCount;
    m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = info.collisionFilterInfo;
    hkReferencedObject* frame = info.localFrame;
    if (frame)
    {
        frame->addReference();
        if (m_pLocalFrame)
            reinterpret_cast<hkReferencedObject*>(m_pLocalFrame)->removeReference();
        m_pLocalFrame = reinterpret_cast<hkLocalFrame*>(frame);
        frame->addReference();
    }
    if (info.motionType == 5)
    {
        hkpFixedRigidMotion* fixed = ::new (&m_pMotionState) hkpFixedRigidMotion(&info.position, &info.rotation);
        reinterpret_cast<hkUFloat8*>(&fixed->m_kMotionState.m_fSurfaceFriction)->FindFloatTableIndex(&info.maxLinear);
        reinterpret_cast<hkUFloat8*>(&fixed->m_kMotionState.m_fRestitution)->FindFloatTableIndex(&info.maxAngular);
        fixed->FUN_00c86420(1);
        m_kCollidable.m_pMotionState = &m_pMotionState.m_kMotionState.m_kMotionTransform;
        if (info.penetrationDepth <= 0.0f)
            m_kCollidable.m_fAllowedPenetrationDepth = DAT_0104da48;
        else
            m_kCollidable.m_fAllowedPenetrationDepth = info.penetrationDepth;
    }
    else
    {
        hkpRigidBody::createDynamicRigidMotion(
            static_cast<hkpMotion::MotionType>(info.motionType), info.position, info.rotation,
            info.mass, info.inertia, info.centerOfMass, info.maxLinear, info.maxAngular, &m_pMotionState);
        static_cast<RigidMotionInitialization&>(m_pMotionState).FUN_00c86420(info.deactivationClass);
        OnTrigger(info.linearVelocity);
        hkpRigidBody_setAngularVelocity(info.angularVelocity);
        m_kCollidable.m_pMotionState = &m_pMotionState.m_kMotionState.m_kMotionTransform;
        m_kCollidable.m_fAllowedPenetrationDepth = info.penetrationDepth;
    }
    hkpRigidBody_enableDeactivation(info.enableDeactivation != 0);
    m_pMotionState.m_kMotionState.m_fLinearDamping = info.linearDamping;
    m_pMotionState.m_kMotionState.m_fAngularDamping = info.angularDamping;
    if (m_kCollidable.m_pCollisionShape)
    {
        hkVector4 halfExtents;
        hkpRigidBody_updateCachedShapeInfo(m_kCollidable.m_pCollisionShape, &halfExtents);
        if (m_kCollidable.m_fAllowedPenetrationDepth <= 0.0f)
            ComputeScaledMinimum(&m_kCollidable, halfExtents);
    }
    if (info.quality != -1)
        m_kCollidable.m_kBroadPhaseHandle.m_ucObjectQualityType = info.quality;
    else if (*reinterpret_cast<const unsigned char*>(&m_pMotionState.m_type) == 5)
        m_kCollidable.m_kBroadPhaseHandle.m_ucObjectQualityType = 0;
    else
        m_kCollidable.m_kBroadPhaseHandle.m_ucObjectQualityType = (info.motionType == 4) ? 1 : 2;
    m_iAutoRemoveLevel = info.removalLevel;
    if (info.forceCollide)
        m_kCollidable.m_uiForceCollideOntoPpu |= 1;
    m_iMaterialIndex.m_fSlipAngle = info.friction;
    m_iMaterialIndex.m_fElasticity = info.restitution;
    m_pMotionState.m_fGravityFactor.m_value = info.solverDeactivation;
    if (info.shapeKeys >= 0)
    {
        m_ucNumShapeKeysInContactPointProperties = info.shapeKeys;
        if (m_ucNumShapeKeysInContactPointProperties > 0 && m_ucNumShapeKeysInContactPointProperties < GetSubtreeDepth(info.shape))
        {
            char buffer[512];
            __declspec(align(16)) char streamStorage[(sizeof(hkOstream) + 15) & ~15];
            ::new (streamStorage) hkOstream(buffer, 512);
            hkOstream& stream = *reinterpret_cast<hkOstream*>(streamStorage);
            stream.ProcessAndReturnValue_00cc01c0(
                "Shape key storage insufficient to store all possible branches. This may cause truncation of the shape key information.");
            DAT_01268360->message(1, 0x458a1bb2, buffer, ".\\Entity\\hkpRigidBody.cpp", 329);
            stream.FUN_00cc00e0();
        }
    }
    else
        m_ucNumShapeKeysInContactPointProperties = GetSubtreeDepth(info.shape);
    m_ucResponseModifierFlags = info.responseModifier;
    return this;
}
