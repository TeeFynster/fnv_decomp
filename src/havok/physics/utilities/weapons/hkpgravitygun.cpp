#include <xmmintrin.h>

// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.



#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/FinishingFlag.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStringPtr.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkpFirstPersonGun.h"
#include "../../../../../include/hkpGravityGun.h"
#include "../../../../../include/hkpRigidBody.h"

typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef int hkInt32;
typedef unsigned int hkUint32;

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
template <typename T> void hkMemoryAllocator::_bufFree(void* p, int n) { bufFree(p, n * sizeof(T)); }
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*) { return hkMemoryRouter_getInstance().heap(); }
template <class T> __forceinline void hkArrayBase<T>::clear()
{
    for (int i = 0; i < m_iElementCount; ++i) m_data[i].~T();
    m_iElementCount = 0;
}
template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0) alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <class T, class A> __forceinline hkArray<T, A>::~hkArray() { clearAndDeallocate(); }
inline void hkReferencedObject::operator delete(void* p)
{
    hkMemoryRouter_getInstance().heap().blockFree(p, static_cast<hkReferencedObject*>(p)->m_usMemSizeAndFlags);
}

struct GGTransform;
struct GGWorld;
struct GunTransform;
class hkpWorld;
struct GunArg3;

// The shared base lacks the finish-loaded constructor at 0x00e466a0.

// The shared class lacks both constructors and the release, attach and action methods defined here.

// @fnv 0x00e45fb0
// src: GUESS 0x00e45fb0 (confidence: high)
void hkpGravityGun::DropPickedObjectIfPresent(int, int, int)
{
    if (m_kPickedBodies.m_iElementCount != 0)
        hkpGravityGun_dropObject(0);
}


// @fnv 0x00e45fc0
void hkpGravityGun::RemoveAllReferences(int)
{
    int i = 0;
    if (m_kPickedBodies.m_iElementCount > 0)
    {
        do
        {
            ((hkReferencedObject*)m_kPickedBodies.m_data[i])->removeReference();
            ++i;
        } while (i < m_kPickedBodies.m_iElementCount);
    }
    m_kPickedBodies.m_iElementCount = 0;
}

// @fnv 0x00e46300
hkpGravityGun::hkpGravityGun(FinishingFlag flag) : hkpFirstPersonGun(flag)
{
    if (flag.m_bFinishing)
        m_type = 3;
}

// Destroys the object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00e46340
hkpGravityGun* hkpGravityGun::DestroyAndFree(unsigned int uiFlags) throw()
{
    // The original scalar-deleting wrapper tears down members and the base without a derived vptr store.
    m_kPickedBodies.~hkArray();
    this->hkpFirstPersonGun::~hkpFirstPersonGun();
    if (uiFlags & 1)
        hkpGravityGun::operator delete(this);
    return this;
}


extern "C" double __cdecl fabs(double);

namespace MathUtilities {
inline hkReal fabs(hkReal r)
{
    return static_cast<hkReal>(::fabs(r));
}
}



struct GGSimulationIsland
{
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
    hkArrayBase<hkpRigidBody*> m_kActorEntries;
};



struct GGWorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    hkUint32 m_uiFilterInfo;
    GGWorldRayCastInput() : m_bEnableShapeCollectionFilter(false), m_uiFilterInfo(0)
    {}
};

struct GGRayHitCollector
{
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo) = 0;
    hkReal m_fEarlyOutHitFraction;

    GGRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_fEarlyOutHitFraction = 1.0f;
    }
};

struct GGShapeRayCastCollectorOutput
{
    hkVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    hkInt32 m_iExtraInfo;
    int unk18;
    int unk1c;

    GGShapeRayCastCollectorOutput()
    {
        reset();
    }
    void reset()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
    }
};

struct GGShapeRayCastOutput : GGShapeRayCastCollectorOutput
{
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;

    GGShapeRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        GGShapeRayCastCollectorOutput::reset();
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct GGWorldRayCastOutput : GGShapeRayCastOutput
{
    const hkpCollidable* m_pRootCollidable;

    GGWorldRayCastOutput()
    {
        reset();
    }
    void reset()
    {
        m_pRootCollidable = 0;
        GGShapeRayCastOutput::reset();
    }
};

struct GGClosestRayHitCollector : GGRayHitCollector
{
    GGWorldRayCastOutput m_kClosestHit;

    GGClosestRayHitCollector()
    {
        reset();
    }
    void reset()
    {
        m_kClosestHit.reset();
        GGRayHitCollector::reset();
    }
    virtual void CollectRayHit(const void* cdBody, const void* hitInfo);
};

struct GGWorld
{
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
    hkArrayBase<GGSimulationIsland*> m_kActiveSimulationIslands;
    hkArrayBase<GGSimulationIsland*> m_kInactiveSimulationIslands;

    void RayCast(const GGWorldRayCastInput& input, GGRayHitCollector& collector) const;
};

struct GGTransform
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
    hkVector4 m_vTranslation;
};

inline const hkVector4& hkpRigidBody::getCenterOfMassInWorld() const
{
    return m_pMotionState.m_kMotionState.m_kSweptTransform.m_vCenterOfMass1;
}

inline hkReal gravityGunBodyMass(hkpRigidBody* body)
{
    return body->m_pMotionState.GetMassValue();
}

// The shared gravity-gun declarations still use the opaque GGRigidBody pointer type.
bool hkpGravityGun::isGrabbed(const GGRigidBody* body) const
    {
        for (int i = 0; i < m_kPickedBodies.m_iElementCount; i++)
        {
            if (m_kPickedBodies.m_data[i] == body)
            {
                return true;
            }
        }
        return false;
    }

// Finds the best rigid body to grab by scoring candidates in active and inactive islands, then ray-casting to verify line of sight.
// @fnv 0x00e45a60
// src: GUESS 0x00e45a60 (confidence: medium)
GGRigidBody* hkpGravityGun::FindVisibleRigidBodyToGrab(const GGTransform& viewTransform, const GGRigidBody* characterBody,
                                      const GGWorld* world)
{
    hkpRigidBody* pickedBody = 0;
    hkReal bestValue = 0.35f;

    const hkArrayBase<GGSimulationIsland*>* islands = &world->m_kActiveSimulationIslands;
    for (int iIslandSet = 0; iIslandSet < 2; iIslandSet++)
    {
        for (int i = 0; i < islands->m_iElementCount; i++)
        {
            GGSimulationIsland* island = islands->m_data[i];
            for (int e = 0; e < island->m_kActorEntries.m_iElementCount; e++)
            {
                hkpRigidBody* body = island->m_kActorEntries.m_data[e];
                const hkVector4& vCenterOfMass = body->getCenterOfMassInWorld();

                hkVector4 posInView;
                posInView.SetTransformedPosition(reinterpret_cast<const hkTransform&>(viewTransform), vCenterOfMass);

                hkReal x = posInView(0);
                if (x < 0.1f || x > m_fMaxPickDistance || body == reinterpret_cast<const hkpRigidBody*>(characterBody))
                {
                    continue;
                }

                hkReal value = MathUtilities::fabs(posInView(2)) + MathUtilities::fabs(posInView(1));
                value = value / (x + 1.0);

                if (gravityGunBodyMass(body) > m_fMaxPickMass)
                {
                    value += 0.1f;
                }

                if (value > bestValue)
                {
                    continue;
                }

                if (isGrabbed(reinterpret_cast<const GGRigidBody*>(body)))
                {
                    continue;
                }

                {
                    GGClosestRayHitCollector collector;
                    GGWorldRayCastInput input;
                    input.m_vFrom = viewTransform.m_vTranslation;
                    input.m_vTo = vCenterOfMass;

                    world->RayCast(input, collector);

                    if (collector.m_kClosestHit.m_pRootCollidable == 0 ||
                        collector.m_kClosestHit.m_pRootCollidable == &body->m_kCollidable)
                    {
                        bestValue = value;
                        pickedBody = body;
                    }
                }
            }
        }
        islands = &world->m_kInactiveSimulationIslands;
    }
    return reinterpret_cast<GGRigidBody*>(pickedBody);
}

struct GunArg3
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    int unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c;
    int unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c;
    int unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac;
    int unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc;
    int unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c;
    hkVector4 unk120;
};

struct GunTransform
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    hkVector4 m_vTranslation;
};

struct GunListener
{
    virtual void func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func4();
    virtual void gunAction(const hkVector4& from, const hkVector4* to = 0);
};

// Dispatches a gun action to listeners based on b1/b2 and picked-body capacity, then calls FUN_00e45c90 with dt, a4, a3.
// @fnv 0x00e46140
// src: HAVOK_SRC 0x00e46140
void hkpGravityGun::stepGun(hkReal dt, hkpWorld* world, GunArg3* a3, GunTransform* apGunTransform, bool b1,
                                   bool b2)
{
    hkVector4 v1;
    hkVector4 v2;

    if (b1)
    {
        gravityGunPush(apGunTransform, a3, world);
        *(__m128*)&v1 = *(__m128*)&a3->unk120;
        for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        {
            ((GunListener*)m_kListeners.m_data[i])->gunAction(v1, 0);
        }
    }
    else if (b2)
    {
        if (m_kPickedBodies.m_iElementCount != m_iMaxPickedBodies)
        {
            gravityGunPull(apGunTransform, a3, world);
            *(__m128*)&v2 = *(__m128*)&apGunTransform->m_vTranslation;
            *(__m128*)&v1 = *(__m128*)&a3->unk120;
            for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
            {
                ((GunListener*)m_kListeners.m_data[i])->gunAction(v2, &v1);
            }
        }
        else
        {
            DropPickedObjectIfPresent(apGunTransform, a3, world);
            *(__m128*)&v2 = *(__m128*)&a3->unk120;
            for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
            {
                ((GunListener*)m_kListeners.m_data[i])->gunAction(v2, 0);
            }
        }
    }

    gravityGunStep(dt, apGunTransform, a3);
}

extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern "C" void _mm_store_ss(float* _V, __m128 _A);
template <class T> __forceinline void constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& e)
{
    if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        hkArrayUtil::_reserveMore(alloc, this, sizeof(T));
    constructWithCopy<T>(m_data + m_iElementCount, 1, e);
    m_iElementCount++;
}

// Retains the body, appends it to the picked bodies, and scales its inverse mass by 100.
// @fnv 0x00e46000
// src: XBOX_PDB 0x00e46000
void hkpGravityGun::takeObject(hkpRigidBody* apEntity)
{
    apEntity->addReference();
    m_kPickedBodies.pushBack(apEntity);
    float w = apEntity->m_pMotionState.m_kInertiaAndMassInv.getW();
    float f = (float)(w * 100.0);
    apEntity->hkpRigidBody_setMassInv(f);
}

extern "C" __m128 _mm_setr_ps(float, float, float, float);

// Constructs a GravityGun object, initializing pick limits, grab and target positions, and setting the type and name fields.
// @fnv 0x00e46260
hkpGravityGun::hkpGravityGun() throw()
    : m_iMaxPickedBodies(10), m_fMaxPickMass(200.0f), m_fMaxPickDistance(50.0f), m_fPickAngle(100.0f),
      m_fHoldDistance(50.0f)
{
    m_type = 3;
    m_name = "GravityGun";
    m_kGrabPosition.set(2.5f, 0.6f, 0.0f);
    m_kTargetPosition.set(0.0f, 1.0f, 0.0f);
}

__forceinline float hkVector4::getW() const
{
    __m128 lane = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    float value;
    _mm_store_ss(&value, lane);
    return value;
}
__forceinline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}
inline void hkStringPtr::operator=(const char* text) throw() { Assign(text); }

__forceinline float& hkVector4::operator()(int i) { return m_vComponents.m128_f32[i]; }
