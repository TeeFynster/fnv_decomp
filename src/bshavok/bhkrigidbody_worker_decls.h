// bshavok/bhkrigidbody_worker_decls.h: declares WorldPhysicsSettings, hkpRigidBodyMotionView, bhkRigidBodyPrefix, BhkRigidBody
#ifndef FNV_BHKRIGIDBODY_WORKER_DECLS_H
#define FNV_BHKRIGIDBODY_WORKER_DECLS_H

#include <stddef.h>
#include <xmmintrin.h>
#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif
#include "NiPoint3.h"
class NiQuaternion;

extern __declspec(align(16)) float DAT_01267e30;
extern __declspec(align(16)) float DAT_012683b0;
extern NiRTTI DAT_012681c0;
extern float DAT_01022958;
extern float DAT_010c60d8;


class WorldPhysicsSettings
{
  public:
    char layoutPadding000[0xa8];
    float m_fSurfaceFriction;
    float m_fRestitution;
    char layoutPaddingB0[7];
    unsigned char m_iAutoRemoveLevel;
    char layoutPaddingB8[8];
    WorldPhysicsSettings();
};

FNV_STATIC_ASSERT(sizeof(WorldPhysicsSettings) == 0xc0);
FNV_STATIC_ASSERT(offsetof(WorldPhysicsSettings, m_fSurfaceFriction) == 0xa8);
FNV_STATIC_ASSERT(offsetof(WorldPhysicsSettings, m_fRestitution) == 0xac);
FNV_STATIC_ASSERT(offsetof(WorldPhysicsSettings, m_iAutoRemoveLevel) == 0xb7);

#include "../../include/hkpRigidBody.h"
#include "../../include/NiD3DDefaultShader.h"
// Motion-state vectors of the body at their hkpRigidBody offsets: the transform translation (0x120), the swept
// transform's second centre of mass (0x140) and rotation (0x160) and the local centre of mass (0x170).
struct hkpRigidBodyMotionView
{
    char layoutPadding000[0x120];
    __m128 m_vContactPosition;
    char layoutPadding130[0x10];
    __m128 m_vCenterOfMass1;
    char layoutPadding150[0x10];
    __m128 m_rotation;
    __m128 m_vCenterOfMassLocal;
};

class bhkRigidBodyPrefix
{
  public:
    volatile unsigned int field0;
    volatile unsigned int field4;
    union
    {
        hkpRigidBody* m_pHavokObject;
        volatile unsigned char initialized;
    };
    volatile unsigned int fieldC;
    volatile unsigned int field10;
    volatile unsigned int field14;
    volatile unsigned char field18;
    unsigned char padding19;
    volatile unsigned short field1a;
    volatile unsigned int field1c;

    ~bhkRigidBodyPrefix();
    __forceinline bhkRigidBodyPrefix()
    {
        fieldC = 0;
        field10 = 0;
        field14 = 0x80000000;
        initialized = 1;
        field0 = 0;
        field4 = 0;
        field18 = 1;
        field1a = 0xffff;
    }
};

FNV_STATIC_ASSERT(sizeof(bhkRigidBodyPrefix) == 0x20);
FNV_STATIC_ASSERT(offsetof(bhkRigidBodyPrefix, m_pHavokObject) == 8);
struct __declspec(align(16)) bhkrigidbody_vector
{
    __m128 v;
    __forceinline bhkrigidbody_vector& operator=(const bhkrigidbody_vector& other)
    {
        v = other.v;
        return *this;
    }
};
class BhkRigidBody : public bhkRigidBodyPrefix
{
  public:
    WorldPhysicsSettings rigidBody;
    BhkRigidBody();
};
#endif
