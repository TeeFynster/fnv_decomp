
// src/havok/physics/utilities/weapons/hkpprojectilegun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpprojectilegun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkpRigidBody.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkBoolResult.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkpFirstPersonGun.h"
#include "../../../../../include/hkVector4q.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/FinishingFlag.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkpContactListener.h"

// Havok initializes only the reference count in the inlined default constructor.

__forceinline void hkpContactListener::contact0() {}
__forceinline void hkpContactListener::contact1() {}
__forceinline void hkpContactListener::contact2() {}
__forceinline hkpContactListener::~hkpContactListener() {}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();


template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance().heap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <class BITS, class STORAGE> class hkFlagsE44
{
  public:
    hkFlagsE44(STORAGE s)
    {
        m_kStorage = s;
    }
    STORAGE m_kStorage;

    void clear(STORAGE mask)
    {
        m_kStorage &= ~mask;
    }
};

enum ProjectileFlagsE44
{
    PROJECTILE_FLAG_NONE
};

// No approved hkpGunProjectile.h is available yet.
class hkpGunProjectile : public hkReferencedObject, public hkpContactListener
{
public:
    hkFlagsE44<ProjectileFlagsE44, unsigned char> m_flags;
    hkpRigidBody* m_kCollisionBody;
    float m_fDamage;
    void* m_pGun;

    hkpGunProjectile(void* gun, hkpRigidBody* body);
    virtual ~hkpGunProjectile() throw();
    virtual void destroyProjectile();
    virtual void vf10();
    virtual void vf14(float);
    virtual void contact0();
    __declspec(noinline) void removeFromWorld_00e44cc0();
    __declspec(noinline) void ReleaseWorld();
    __declspec(noinline) void InitOnce();
    __declspec(noinline) void update_00e44d20(float);
    void setHitListening(bool);
    __declspec(noinline) void ResetVtables();
    void ReleaseBody();
    void UpdateState_00e450b0(int);
    hkpGunProjectile* FUN_00e450c0(unsigned int);
    __declspec(noinline) void addToWorld_00e44c90(hkpWorld* scene) throw();
};

// No approved hkpProjectileGun.h is available yet.
class hkpProjectileGun : public hkpFirstPersonGun
{
  public:
    hkInt32 m_iMaxProjectiles;
    hkReal m_fReloadTime;
    hkReal m_fTimeSinceLastShot;
    hkArray<hkpGunProjectile*> m_kRigidBodies;
    void* m_pOwningWorld;
    void* m_pBroadPhaseRegionData;
    hkpProjectileGun(void* pkWorld);
    __declspec(noinline) virtual ~hkpProjectileGun() throw();
    virtual void trigger(int, int);
    virtual void v10(float, int, int, int, int, int);
    void TriggerIfElapsed(int, int);
    void UpdateValue(float, int, int, int, int, int);
    __declspec(noinline) void ApplyToAll(float);
    __declspec(noinline) void ClearProjectileFlags();
    hkpGunProjectile* FindFirstUnflaggedObject();
    void destroyAgedProjectiles(float);
    __declspec(noinline) void clearProjectiles() throw();
    __declspec(noinline) void removeDestroyedProjectiles();
    void onUpdate(float, int, int, int, int, int);
    void GetCallResult(unsigned int);
    void addProjectile(hkpGunProjectile*);
    void* FUN_00e450f0(int);
};

// @fnv 0x00e44c70
void hkpGunProjectile::InitOnce()
{
    if (!(m_flags.m_kStorage & 1))
    {
        destroyProjectile();
        m_flags.m_kStorage |= 1;
    }
}

// @fnv 0x00e44d50
// src: HAVOK_LIB 0x00e44d50
void hkpGunProjectile::setHitListening(bool on)
{
    if (on != (m_flags.m_kStorage >> 2 & 1))
    {
        hkpRigidBody* e = m_kCollisionBody;
        if (e && e->m_pOwningWorld)
        {
            void* arg = static_cast<hkpContactListener*>(this);
            if (on)
                e->AddContactListener(arg);
            else
                e->RemoveContactListener(arg);
        }
        if (on)
            m_flags.m_kStorage |= 4;
        else
            m_flags.m_kStorage &= 0xfb;
    }
}

// Subtracts a from value when value is above zero, then forwards all arguments to v10.
// @fnv 0x00e44be0
void hkpProjectileGun::UpdateValue(float afDelta, int b, int c, int d, int e, int f)
{
    if (m_fTimeSinceLastShot > 0.0f)
        m_fTimeSinceLastShot = m_fTimeSinceLastShot - afDelta;

    v10(afDelta, b, c, d, e, f);
}

// Unregisters a body that is still in a world, then releases and clears the body reference.
// @fnv 0x00e44cf0
void hkpGunProjectile::ReleaseWorld()
{
    if (m_kCollisionBody)
    {
        if (m_kCollisionBody->m_pOwningWorld)
            removeFromWorld_00e44cc0();
        m_kCollisionBody->removeReference();
        m_kCollisionBody = 0;
    }
}

// @fnv 0x00e44de0
void hkpProjectileGun::ApplyToAll(float value)
{
    int count = m_kRigidBodies.m_iElementCount;
    for (int i = 0; i < count; ++i)
        m_kRigidBodies[i]->update_00e44d20(value);
}

// @fnv 0x00e44e40
hkpGunProjectile* hkpProjectileGun::FindFirstUnflaggedObject()
{
    int i = 0;
    while (i < m_kRigidBodies.m_iElementCount)
    {
        hkpGunProjectile* object = m_kRigidBodies[i];
        if ((object->m_flags.m_kStorage & 1) == 0)
            return object;
        ++i;
    }
    return 0;
}

extern int DAT_010ebf74;
extern int DAT_010ebf94;
extern int _DAT_0102e388;
extern int DAT_0104dd7c;

// @fnv 0x00e44e70
void hkpGunProjectile::ResetVtables()
{
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&DAT_010ebf94);
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8) = reinterpret_cast<void*>(&DAT_010ebf74);

    ReleaseWorld();

    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 8) = reinterpret_cast<void*>(&DAT_0104dd7c);
    *reinterpret_cast<void**>(this) = reinterpret_cast<void*>(&_DAT_0102e388);
}

// Calls ApplyToAll with a, then ClearProjectileFlags, then FUN_00e44ef0; b through f are unused.
// @fnv 0x00e44f30
// src: HAVOK_LIB 0x00e44f30
void hkpProjectileGun::onUpdate(float a, int b, int c, int d, int e, int f)
{
    ApplyToAll(a);
    ClearProjectileFlags();
    removeDestroyedProjectiles();
}

// Calls FUN_00e45040, then if flags bit 0 is set deallocates this via the memory router's manager, and returns this.
// @fnv 0x00e450f0
void* hkpProjectileGun::FUN_00e450f0(int flags)
{
    this->hkpProjectileGun::~hkpProjectileGun();

    if (flags & 1)
    {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        router.m_heap->blockFree(this, m_usMemSizeAndFlags);
    }

    return this;
}

// Clears the projectiles; the callback argument is unused.
// @fnv 0x00e44f50
void hkpProjectileGun::GetCallResult(unsigned int auiUnused)
{
    clearProjectiles();
}

struct V
{
    virtual void __fastcall f0(int);
    virtual void __fastcall f1(int);
    virtual void __fastcall f2(int);
    virtual void __fastcall f3(int);
    virtual void __fastcall f4(int);
};
struct C
{
    void __fastcall hkpGunProjectile_contactPointCallback(int);
};
// @fnv 0x00e45090
// src: HAVOK_LIB 0x00e45090
void __fastcall C::hkpGunProjectile_contactPointCallback(int x)
{
    V* base = reinterpret_cast<V*>(reinterpret_cast<char*>(this) - 8);
    base->f4(x);
}

// @fnv 0x00e450b0
// src: GUESS 0x00e450b0 (confidence: low)
void __thiscall hkpGunProjectile::UpdateState_00e450b0(int)
{
    m_flags.m_kStorage |= 2;
}

// @fnv 0x00e44bc0
void hkpProjectileGun::TriggerIfElapsed(int a, int b)
{
    if (!(m_fTimeSinceLastShot > 0.0f))
    {
        m_fTimeSinceLastShot = m_fReloadTime;
        trigger(a, b);
    }
}

// @fnv 0x00e44cc0
// src: HAVOK_LIB 0x00e44cc0
void hkpGunProjectile::removeFromWorld_00e44cc0()
{
    if (m_kCollisionBody)
    {
        static_cast<hkpWorld*>(m_kCollisionBody->m_pOwningWorld)->ProcessTarget(m_kCollisionBody);
        if (m_flags.m_kStorage & 4)
            m_kCollisionBody->RemoveContactListener(static_cast<hkpContactListener*>(this));
    }
}

// @fnv 0x00e44e10
void hkpProjectileGun::ClearProjectileFlags()
{
    const int n = m_kRigidBodies.GetLogicalSize();
    for (int i = 0; i < n; i++)
        m_kRigidBodies[i]->m_flags.clear(2);
}

// @fnv 0x00e44ea0
void hkpGunProjectile::ReleaseBody()
{
    ReleaseWorld();
}

extern float DAT_01017870;

// 0x00e46660 is hkpFirstPersonGun(); its default constructor is absent from the shared header.
// This retained construction view also includes the derived projectile limit at +0x20.
class FUN_00e46660
{
  public:
    FUN_00e46660() throw();
    virtual ~FUN_00e46660() throw();
    int unk04[7];
    int m_20;
};

class hkRangeE44F
{
  public:
    float m_24;
    float m_28;

    hkRangeE44F() throw() : m_24(DAT_01017870), m_28(0.0f)
    {}
};

template <typename T>
__forceinline void initializeProjectileArray(hkArray<T>& array)
{
    array.m_data = 0;
    array.m_iElementCount = 0;
    array.m_iCapacityState = 0x80000000;
}

class FUN_00e44fc0 : public FUN_00e46660, public hkRangeE44F
{
  public:
    hkArray<int> m_items;
    int m_38;
    int m_3c;

    FUN_00e44fc0(int a, int b) throw();
    virtual ~FUN_00e44fc0() throw();
};

// Initializes the object: sets m_20 to 5, inits m_items, and stores the two constructor arguments into m_38 and m_3c.
// @fnv 0x00e44fc0
FUN_00e44fc0::FUN_00e44fc0(int a, int b) throw() : m_items(FinishingFlag(0))
{
    m_20 = 5;
    initializeProjectileArray(m_items);
    m_38 = a;
    m_3c = b;
}

// @fnv 0x00e450c0
hkpGunProjectile* hkpGunProjectile::FUN_00e450c0(unsigned int flags)
{
    ResetVtables();
    if (flags & 1)
    {
        hkMemoryRouter& router = hkMemoryRouter_getInstance();
        router.m_heap->blockFree(this, m_usMemSizeAndFlags);
    }
    return this;
}

// The shared vector overlay must retain the original no-op initialization.

// Preserve the inlined SIMD operations used by ApplyTurnRate.
static __forceinline __m128 projectileDot3(const hkVector4q& a, const hkVector4q& b)
{
    __m128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}

__forceinline hkReal hkVector4q::length3() const
{
    hkReal len;
    _mm_store_ss(&len, _mm_sqrt_ss(projectileDot3(*this, *this)));
    return len;
}

__forceinline void hkVector4q::normalize3()
{
    __m128 len2 = projectileDot3(*this, *this);
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                          _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
}

namespace projectile_simd {
// local form of hkRotation: 0x00e44990 needs inline rotation assignment; shared form gives 539 bytes vs exe 552.
struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline void operator=(const hkRotationq& r)
    {
        m_kColumn0 = r.m_kColumn0;
        m_kColumn1 = r.m_kColumn1;
        m_kColumn2 = r.m_kColumn2;
    }

    void SetAxisAngle(const hkVector4q& axis, hkReal angle);
    void SetProduct(const hkRotationq& a, const hkRotationq& b);
};

struct hkTransformq
{
    hkRotationq m_rotation;
    hkVector4q m_vTranslation;
};

class hkpRigidBodyq
{
  public:
    __forceinline const hkTransformq& getTransform() const
    {
        return *reinterpret_cast<const hkTransformq*>(reinterpret_cast<const char*>(this) + 0xf0);
    }

    __forceinline const hkVector4q& getLinearVelocity() const
    {
        return *reinterpret_cast<const hkVector4q*>(reinterpret_cast<const char*>(this) + 0x1b0);
    }

    void SetGeometryTransform(const hkTransformq& transform);
};

// If speed exceeds minSpeed, rotates the body's transform about the cross of its normalized velocity and rotation column 0, by an angle scaled by turnRate.
// @fnv 0x00e44990
void __cdecl ApplyTurnRate(hkpRigidBodyq* body, hkReal minSpeed, hkReal turnRate)
{
    hkTransformq t;
    t = body->getTransform();
    const hkVector4q& vel = body->getLinearVelocity();

    if (vel.length3() > minSpeed)
    {
        hkVector4q col0;
        col0 = t.m_rotation.m_kColumn0;
        hkVector4q dir;
        dir = vel;
        dir.normalize3();

        hkVector4q cross;
        cross.m_vComponents = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0xc9),
                       _mm_shuffle_ps(col0.m_vComponents, col0.m_vComponents, 0xd2)),
            _mm_mul_ps(_mm_shuffle_ps(dir.m_vComponents, dir.m_vComponents, 0xd2),
                       _mm_shuffle_ps(col0.m_vComponents, col0.m_vComponents, 0xc9)));

        hkReal len = cross.length3();
        if (len > 1e-5f)
        {
            hkReal angle = len * turnRate * -5.0;
            hkVector4q axis;
            axis = cross;
            axis.normalize3();

            hkRotationq rot;
            rot.SetAxisAngle(axis, angle);

            hkRotationq newRot;
            newRot.SetProduct(rot, t.m_rotation);
            t.m_rotation = newRot;

            body->SetGeometryTransform(t);
        }
    }
}

} // namespace projectile_simd

// Stores gun and body, zeroes flags and damage, and calls FUN_00c90510 on the body.
// @fnv 0x00e44c20
hkpGunProjectile::hkpGunProjectile(void* gun, hkpRigidBody* apCollisionBody)
    : m_flags(0), m_fDamage(0.0f), m_kCollisionBody(apCollisionBody), m_pGun(gun)
{
    m_kCollisionBody->addReference();
}

void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& e)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    const unsigned int* src = reinterpret_cast<const unsigned int*>(&e);
    unsigned int* dst = reinterpret_cast<unsigned int*>(m_data + m_iElementCount);
    int i = 0;
    do
    {
        dst[i] = src[i];
    } while (++i < sizeof(T) / 4);
    m_iElementCount++;
}

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}

// @fnv 0x00e44f60
// src: HAVOK_LIB 0x00e44f60
void hkpProjectileGun::addProjectile(hkpGunProjectile* entity)
{
    entity->addReference();
    m_kRigidBodies.pushBack(entity);
    entity->addToWorld_00e44c90(static_cast<hkpWorld*>(m_pOwningWorld));
}

// @fnv 0x00e45040
hkpProjectileGun::~hkpProjectileGun() throw()
{
    clearProjectiles();
}

class FUN_00e46e80
{
  public:
    FUN_00e46e80() throw();
    void hkQueue_hkpRigidBody_setCapacity(void* world) throw();

    static void* operator new(unsigned int n)
    {
        return hkMemoryRouter_getInstance().heap().blockAlloc(n);
    }
    static void operator delete(void* p);

    int unk00[5];
};

class FUN_00e466a0
{
  public:
    FUN_00e466a0(FinishingFlag flag) throw();
    virtual ~FUN_00e466a0() throw();
    int unk04;
    char unk08;
};

class FUN_00e46f20 : public FUN_00e466a0
{
  public:
    FUN_00e46f20(FinishingFlag flag) throw();
    virtual ~FUN_00e46f20() throw();

    int unk0C[9];
    void* m_pOwningWorld;
    int unk34[7];
    FUN_00e46e80* m_helper;
};

// Initializes the object and, when finishing, allocates a helper and binds it to the owning world.
// @fnv 0x00e46f20
FUN_00e46f20::FUN_00e46f20(FinishingFlag flag) throw() : FUN_00e466a0(flag)
{
    if (flag.m_bFinishing)
    {
        unk08 = 1;
        m_helper = new FUN_00e46e80();
        m_helper->hkQueue_hkpRigidBody_setCapacity(m_pOwningWorld);
    }
}

// @fnv 0x00e45010
hkpProjectileGun::hkpProjectileGun(void* pkWorld) : hkpFirstPersonGun(pkWorld)
{}

// Registers the offset-8 contact listener when enabled, then adds the collision body to the world.
// @fnv 0x00e44c90
// src: HAVOK_LIB 0x00e44c90
void hkpGunProjectile::addToWorld_00e44c90(hkpWorld* scene) throw()
{
    if (m_flags.m_kStorage & 4)
        m_kCollisionBody->AddContactListener(static_cast<hkpContactListener*>(this));
    scene->hkpWorld_addEntity(m_kCollisionBody, 1);
}

// Iterates m_kRigidBodies and calls FUN_00e44c70 on each item whose offset-0x14 float field exceeds value.
// @fnv 0x00e44da0
// src: HAVOK_LIB 0x00e44da0
void __thiscall hkpProjectileGun::destroyAgedProjectiles(float value)
{
    int count = m_kRigidBodies.m_iElementCount;
    int index = 0;

    while (index < count)
    {
        hkpGunProjectile* item = m_kRigidBodies.m_data[index];
        float itemValue = item->m_fDamage;

        if (itemValue > value)
        {
            item->InitOnce();
        }

        ++index;
    }
}

// Adds elapsed time and invokes the update callback while the projectile is active.
// @fnv 0x00e44d20
// src: HAVOK_LIB 0x00e44d20
void hkpGunProjectile::update_00e44d20(float value)
{
    if ((m_flags.m_kStorage & 1) == 0)
    {
        m_fDamage += value;
        vf14(value);
    }
}

// Destroys and releases every projectile, then clears the array count.
// @fnv 0x00e44eb0
// src: HAVOK_LIB 0x00e44eb0
void hkpProjectileGun::clearProjectiles() throw()
{
    int count = m_kRigidBodies.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        hkpGunProjectile* p = m_kRigidBodies.m_data[i];
        p->InitOnce();
        p->removeReference();
    }
    m_kRigidBodies.m_iElementCount = 0;
}

__forceinline void copyProjectile(void* dst, const void* src)
{
    unsigned int k = 0;
    do
    {
        static_cast<int*>(dst)[k] = static_cast<const int*>(src)[k];
    } while (++k < sizeof(void*) / sizeof(int));
}

__forceinline void eraseProjectile(hkArray<hkpGunProjectile*>& a, int i)
{
    --a.m_iElementCount;
    if (a.m_iElementCount != i)
        copyProjectile(a.m_data + i, a.m_data + a.m_iElementCount);
}

// For each item in m_kRigidBodies whose flags bit 0 is set, calls FUN_00c905b0 on it and removes it from the array.
// @fnv 0x00e44ef0
// src: HAVOK_LIB 0x00e44ef0
void hkpProjectileGun::removeDestroyedProjectiles()
{
    int count = m_kRigidBodies.m_iElementCount;
    for (int i = 0; i < count; ++i)
    {
        hkpGunProjectile* item = m_kRigidBodies.m_data[i];
        if (item->m_flags.m_kStorage & 1)
        {
            item->removeReference();
            eraseProjectile(m_kRigidBodies, i);
            --count;
            --i;
        }
    }
}
