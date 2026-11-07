typedef union __declspec(intrin_type) __declspec(align(16)) {
    float lanes[4];
} __m128, LocalM128;
#define _INCLUDED_MM2

// src/havok/physics/utilities/weapons/hkpmountedballgun_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpmountedballgun.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/weapons/hkpmountedballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpmountedballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpMountedBallGun.h"
#include "../../../../../include/hkMemoryAllocator.h"
// hkMemoryRouterQ_hkpmountedballgun_rtm_variant: local type (was include/hkMemoryRouterQ.h, which had no evidence of one real class); no method of it is bound to a named game function

class hkMemoryRouterQ_hkpmountedballgun_rtm_variant
{
public:
    int unk00;
    int unk04;
    int unk08;
    union
    {
        int unk0C;
        int unk0c;
    };
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }

    hkMemoryAllocator& debug();
};
#include <xmmintrin.h>
extern unsigned int DAT_010ec004;
extern float DAT_01011d78;
extern float DAT_01016410;
struct FUN_00e46f90_Obj
{
    void FUN_00e46f90(int a);
};
struct HKStr
{
    void* m_p;
    void operator=(const char* s);
};
union HKVec
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};
struct MBG
{
    void* vfptr;
    unsigned short unk04;
    short unk06;
    unsigned char m_type;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    HKStr m_name;
    unsigned char m_uiKeyboardKey;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    void** m_listenerData;
    int m_listenerCount;
    int m_listenerCap;
    float m_fBulletRadius;
    float m_fBulletVelocity;
    float m_fBulletMass;
    float m_fBulletSpread;
    int m_iBulletBatchCount;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    HKVec m_kBulletDirection;
    void* m_pBulletQueue;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    HKVec m_vContactPosition;
};
struct FUN_00e45150_class
{
    MBG* Initialize(int a);
};
void* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkString_memCpy(void* dst, const void* src, int numBytes);
inline hkMemoryRouterQ_hkpmountedballgun_rtm_variant& getRouter()
{
    return *(hkMemoryRouterQ_hkpmountedballgun_rtm_variant*)hkMemoryRouter_getInstance();
}
template <typename T> inline T* hkAllocateChunkQ(int n)
{
    return (T*)getRouter().heap().AllocateMemoryBlock(n * sizeof(T));
}
template <typename T> inline void hkDeallocateChunkQ(T* p, int n)
{
    getRouter().heap().blockFree(p, n * sizeof(T));
}
struct hkpRigidBody;
template <typename T> struct hkQueueQ
{
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    int getCapacity() const
    {
        return m_pRayCursor;
    }
    void releaseMemory()
    {
        if (m_pRayCursor)
            hkDeallocateChunkQ<T>(m_data, m_pRayCursor);
    }
    void hkQueue_hkpRigidBody_setCapacity(int n);
};
template struct hkQueueQ<hkpRigidBody*>;

namespace S00e451b0_SIMD {
using ::__m128;
using ::LocalM128;
// Exe 0x00e451b0 FUN_00e451b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
}
struct S00e451b0_ZScalar
{
    S00e451b0_SIMD::LocalM128 q;
    S00e451b0_ZScalar(float f) : q(S00e451b0_SIMD::_mm_load_ss(&f))
    {}
};
struct S00e451b0_ZInfo;
struct S00e451b0_ZSphere
{
    int unk00;
    unsigned short unk04;
    short unk06;
    S00e451b0_ZSphere* FUN_00cd8160(float);
    void FUN_00c905b0();
};
struct __declspec(align(16)) S00e451b0_ZInfo
{
    int unk00;
    S00e451b0_ZSphere* unk04;
    int unk08, unk0c;
    S00e451b0_SIMD::LocalM128 unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    float unk90, unk94, unk98, unk9c, unkA0, unkA4, unkA8, unkAc, unkB0;
    unsigned char unkB4, unkB5, unkB6, unkB7;
    int unkB8, unkBc;
    void InitializePhysicsFields();
};
struct S00e451b0_ZBody
{
    int unk00;
    unsigned short unk04;
    short unk06;
    struct S00e451b0_ZWorld* unk08;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    S00e451b0_SIMD::LocalM128 unk40, unk50, unk60, unk70, unk80;
    int unk90, unk94, unk98;
    float unk9c;
    S00e451b0_ZBody* AllocateStorage_00ca8c90(S00e451b0_ZInfo*);
    void FUN_00c905b0();
};
struct S00e451b0_ZListener
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC(S00e451b0_ZBody*);
    virtual void v10(S00e451b0_ZBody*);
    virtual void v14(const hkVector4*, const S00e451b0_SIMD::LocalM128*);
};
struct S00e451b0_ZWorld
{
    int unk00, unk04, unk08, unk0c;
    hkVector4 unk10;
    void hkpWorld_addEntity(S00e451b0_ZBody*, int);
    void ProcessTarget(bool*, S00e451b0_ZBody*);
};
namespace ZMem {
__declspec(nothrow) hkMemoryRouterQ_hkpmountedballgun_rtm_variant& __cdecl hkMemoryRouter_getInstance();
}
extern const float DAT_0102226c, DAT_01013ea4, DAT_0101df44;
extern float DAT_010231a8, DAT_010181bc;
void __cdecl hkpInertiaTensorComputer_setShapeVolumeMassProperties(S00e451b0_ZSphere*, float, S00e451b0_ZInfo*);
struct __declspec(align(16)) S00e451b0_ZCastResult
{
    S00e451b0_SIMD::LocalM128 point, normal;
    unsigned int shapeKey;
    S00e451b0_ZBody* body;
};
int __cdecl hkpWorldq_CastSphereAndStoreHit(S00e451b0_ZWorld*, const S00e451b0_SIMD::LocalM128*, float, const S00e451b0_SIMD::LocalM128*,
                         S00e451b0_ZCastResult*);
void __cdecl hkpFirstPersonGun_calcVelocityToTarget(const S00e451b0_SIMD::LocalM128*, const S00e451b0_SIMD::LocalM128*, const hkVector4*, float,
                          S00e451b0_SIMD::LocalM128*);
struct S00e451b0_ZQueue
{
    S00e451b0_ZBody** unk00;
    int unk04, unk08, unk0c, unk10;
    void hkQueue_hkpRigidBody_setCapacity(int);
    void push(S00e451b0_ZBody* body)
    {
        if (unk10 >= unk04)
        {
            if (unk04 == 0)
                hkQueue_hkpRigidBody_setCapacity(8);
            else
                hkQueue_hkpRigidBody_setCapacity(unk04 * 2);
        }
        if (unk0c == unk04)
            unk0c = 0;
        unk00[unk0c] = body;
        ++unk0c;
        ++unk10;
    }
    S00e451b0_ZBody* pop()
    {
        S00e451b0_ZBody* body = unk00[unk08++];
        if (unk08 == unk04)
            unk08 = 0;
        --unk10;
        return body;
    }
};
struct S00e451b0_ZGun : hkpMountedBallGun
{
    void hkpMountedBallGun_fireGun(S00e451b0_ZWorld*, const hkTransform*);
};
// @fnv 0x00e451b0
// src: HAVOK_SRC 0x00e451b0
void S00e451b0_ZGun::hkpMountedBallGun_fireGun(S00e451b0_ZWorld* world, const hkTransform* transform)
{
    S00e451b0_SIMD::LocalM128 direction = *(const S00e451b0_SIMD::LocalM128*)&transform->m_rotation.m_kColumn0;
    S00e451b0_SIMD::LocalM128 start =
        S00e451b0_SIMD::_mm_add_ps(S00e451b0_SIMD::_mm_load_ps(reinterpret_cast<const float*>(&transform->m_vTranslation)), direction);
    S00e451b0_ZScalar distance(200.0f);
    S00e451b0_SIMD::LocalM128 end = S00e451b0_SIMD::_mm_add_ps(
        S00e451b0_SIMD::_mm_mul_ps(S00e451b0_SIMD::_mm_shuffle_ps(distance.q, distance.q, 0), direction), start);
    S00e451b0_ZInfo info;
    info.InitializePhysicsFields();
    S00e451b0_ZSphere* sphere = (S00e451b0_ZSphere*)ZMem::hkMemoryRouter_getInstance().heap().blockAlloc(0x20);
    sphere->unk04 = 0x20;
    sphere = sphere->FUN_00cd8160(m_fBulletRadius);
    info.unk90 = m_fBulletMass;
    S00e451b0_SIMD::LocalM128 position = *(S00e451b0_SIMD::LocalM128*)&m_vContactPosition;
    info.unkB0 = 0.01f;
    info.unkA4 = 0.2f;
    const hkVector4* posPtr = &m_vContactPosition;
    info.unkA0 = 1.0f;
    info.unk04 = sphere;
    info.unkB7 = 6;
    info.unk10 = position;
    info.unkB4 = 2;
    hkpInertiaTensorComputer_setShapeVolumeMassProperties(sphere, m_fBulletMass * 2.0f, &info);
    info.unk90 = m_fBulletMass;
    info.unk94 = 0.0f;
    info.unk98 = DAT_010231a8;
    S00e451b0_ZCastResult target;
    if (!hkpWorldq_CastSphereAndStoreHit(world, &start, DAT_010181bc, &end, &target))
    {
        hkpFirstPersonGun_calcVelocityToTarget(&info.unk10, &target.point, &world->unk10, m_fBulletVelocity, &info.unk30);
    }
    else
    {
        S00e451b0_SIMD::LocalM128 speed = S00e451b0_SIMD::_mm_load_ss(&m_fBulletVelocity);
        info.unk30 = S00e451b0_SIMD::_mm_mul_ps(S00e451b0_SIMD::_mm_shuffle_ps(speed, speed, 0), direction);
    }
    S00e451b0_SIMD::LocalM128 hit = target.point;
    for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        ((S00e451b0_ZListener**)m_kListeners.m_data)[i]->v14(posPtr, &hit);
    S00e451b0_ZBody* body = (S00e451b0_ZBody*)ZMem::hkMemoryRouter_getInstance().heap().blockAlloc(0x220);
    body->unk04 = 0x220;
    body = body->AllocateStorage_00ca8c90(&info);
    info.unk04->FUN_00c905b0();
    body->unk9c = m_fBulletSpread;
    for (int i = 0; i < m_kListeners.m_iElementCount; ++i)
        ((S00e451b0_ZListener**)m_kListeners.m_data)[i]->vC(body);
    world->hkpWorld_addEntity(body, 1);
    ((S00e451b0_ZQueue*)m_pBulletQueue)->push(body);
    if (((S00e451b0_ZQueue*)m_pBulletQueue)->unk10 > m_iBulletBatchCount)
    {
        body = ((S00e451b0_ZQueue*)m_pBulletQueue)->pop();
        for (int i = m_kListeners.m_iElementCount - 1; i >= 0; --i)
            ((S00e451b0_ZListener**)m_kListeners.m_data)[i]->v10(body);
        if (body->unk08)
        {
            bool removed;
            body->unk08->ProcessTarget(&removed, body);
        }
        body->FUN_00c905b0();
    }
}
