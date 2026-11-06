#pragma once

#include "Projectile.h"

class BGSLoadFormBuffer;
struct GPContact;
struct ObjHelper;

class GrenadeProjectile : public Projectile
{
public:
    GrenadeProjectile(bool flag);
    GrenadeProjectile(void* a1, void* a2, void* a3, NiPoint3 point, float a5, float a6);
    virtual ~GrenadeProjectile();
    virtual bool IsProximityTriggered();

    bool bFlag150;
    unsigned char unk151[0x1f];
    bool m_bProximityTriggered;
    unsigned char layoutPadding171[15];

    void InitProjectileFlags();
    void SetProjFlag(unsigned int flag, bool on);
    bool TestFlag400(unsigned int flag);
    void FinishSetup();
    void SetLightEnabled();
    bool FUN_00444d00(int flag);
    void FUN_005726e0(void* light, bool enabled);
    bool FUN_009b4700(int arg, bool flag);
    bool FUN_009c43e0(int arg, bool flag);
    void FUN_009b4c70();
    void FUN_009b4d10(BGSLoadFormBuffer* buffer);
    void DispatchReferenceSourceFiles(ObjHelper*, void*, void*, void*, void*, void*, void*);
    void HandleContactHit(GPContact* contact);
};
