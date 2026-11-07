// include/havok/hkpProjectileGun.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPPROJECTILEGUN_H
#define FNV_HAVOK_HKPPROJECTILEGUN_H

#include "hkBase.h"
#include "hkpFirstPersonGun.h"
#pragma pack(push, 1)
class hkpProjectileGun : public hkpFirstPersonGun
{
  public:
    hkInt32 m_iMaxProjectiles;      // +0x20
    hkReal m_fReloadTime;           // +0x24
    hkReal m_fTimeSinceLastShot;    // +0x28
    hkArray<void*> m_kRigidBodies;  // +0x2C
    void* m_pOwningWorld;           // +0x38
    void* m_pBroadPhaseRegionData;  // +0x3C
    void removeDestroyedProjectiles();            // 0x00e44ef0, a member (contributor flag 1 Nov); declaration only, layout unchanged
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpProjectileGun[(sizeof(hkpProjectileGun) == 0x40) ? 1 : -1];
#endif
