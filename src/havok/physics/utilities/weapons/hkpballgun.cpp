#include <xmmintrin.h>
// src/havok/physics/utilities/weapons/hkpballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkpBallGun.h"
#include "../../../../../include/hkpFirstPersonGun.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkBoolResult.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"

extern "C" __m128 _mm_setzero_ps();

// The router at 0x00c85750 has its heap allocator at +0x10.

__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline hkpWorld* hkpWorldObject::getWorld() const
{
    return static_cast<hkpWorld*>(m_pOwningWorld);
}

// No shared hkQueue header exists yet; 0x00e46e80 constructs this five-field queue.
template <class T> class hkQueue
{
  public:
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    static void* operator new(unsigned int uiSize)
    {
        return hkMemoryRouter::getInstance().heap().blockAlloc(uiSize);
    }

    hkQueue() throw();
    ~hkQueue() throw();
    void hkQueue_hkpRigidBody_setCapacity(int iCapacity);

    bool isEmpty() const
    {
        return m_iNodeCount == 0;
    }
    void dequeue(T& data)
    {
        data = m_data[m_pFirstNode];
        m_pFirstNode++;
        if (m_pFirstNode == m_pRayCursor)
            m_pFirstNode = 0;
        m_iNodeCount--;
    }
};

// The bullet-deleted callback occupies vtable slot 4 in both original loops.
class hkpFirstPersonGunListener
{
  public:
    virtual ~hkpFirstPersonGunListener() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void bulletDeletedCallback(hkpRigidBody* pkBullet) throw();
};

// hkpBallGun.h lacks reset; ECX carries the gun, and unused EDX preserves the thiscall stack.
// @fnv 0x00e46ea0
void __fastcall resetBallGun(hkpBallGun* gun, void*, hkpWorld* pkWorld) throw()
{
    while (!static_cast<hkQueue<hkpRigidBody*>*>(gun->m_pBulletQueue)->isEmpty())
    {
        hkpRigidBody* pkBody;
        static_cast<hkQueue<hkpRigidBody*>*>(gun->m_pBulletQueue)->dequeue(pkBody);
        for (int i = gun->m_kListeners.GetLogicalSize() - 1; i >= 0; i--)
            static_cast<hkpFirstPersonGunListener*>(gun->m_kListeners[i])->bulletDeletedCallback(pkBody);
        if (pkBody->getWorld() == pkWorld)
            pkWorld->ProcessTarget(pkBody);
        pkBody->removeReference();
    }
}

static const float DAT_0101df44 = 0.2f;
static const float DAT_0104ef80 = 40.0f;
static const float DAT_0101b268 = 50.0f;

// The shared class lacks its constructor/destructor declarations. These entry points
// reproduce their thiscall ABI and explicitly install the original derived vtable.
extern "C" void* ballGunVtable[];
extern "C" void constructFirstPersonGunBase() throw();
typedef hkpFirstPersonGun* (__thiscall* BallGunBaseConstructor)(hkpFirstPersonGun*);

// @fnv 0x00e46f90
hkpBallGun* __fastcall constructBallGun(hkpBallGun* gun, void*, int iNumBullets) throw()
{
    reinterpret_cast<BallGunBaseConstructor>(&constructFirstPersonGunBase)(gun);
    *reinterpret_cast<void***>(gun) = ballGunVtable;
    gun->m_fBulletRadius = DAT_0101df44;
    gun->m_fBulletVelocity = DAT_0104ef80;
    gun->m_iBulletBatchCount = iNumBullets;
    gun->m_fBulletSpread = gun->m_fBulletMass = DAT_0101b268;
    gun->m_kBulletDirection.setZero4();
    gun->m_type = 1;
    gun->m_name = "BallGun";
    gun->m_pBulletQueue = new hkQueue<hkpRigidBody*>();
    static_cast<hkQueue<hkpRigidBody*>*>(gun->m_pBulletQueue)->hkQueue_hkpRigidBody_setCapacity(iNumBullets);
    return gun;
}

// @fnv 0x00e47020
void __fastcall destroyBallGun(hkpBallGun* gun, void*) throw()
{
    *reinterpret_cast<void***>(gun) = ballGunVtable;
    while (!static_cast<hkQueue<hkpRigidBody*>*>(gun->m_pBulletQueue)->isEmpty())
    {
        hkpRigidBody* pkBody;
        static_cast<hkQueue<hkpRigidBody*>*>(gun->m_pBulletQueue)->dequeue(pkBody);
        for (int i = gun->m_kListeners.GetLogicalSize() - 1; i >= 0; i--)
            static_cast<hkpFirstPersonGunListener*>(gun->m_kListeners[i])->bulletDeletedCallback(pkBody);
        if (pkBody->m_pOwningWorld)
            static_cast<hkpWorld*>(pkBody->m_pOwningWorld)->ProcessTarget(pkBody);
        pkBody->removeReference();
    }
    hkQueue<hkpRigidBody*>* pkQueue = static_cast<hkQueue<hkpRigidBody*>*>(gun->m_pBulletQueue);
    if (pkQueue)
    {
        pkQueue->~hkQueue();
        hkMemoryRouter::getInstance().heap().blockFree(pkQueue, sizeof(*pkQueue));
    }
    gun->hkpFirstPersonGun::~hkpFirstPersonGun();
}
