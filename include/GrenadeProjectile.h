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
    bool Projectile_IsFlagSet(int flag);
    void TESObjectREFR_SetLight_005726e0(void* light, bool enabled);
    bool TurnOff(int arg, bool flag);
    bool Projectile_DisarmPlacedExplosives(int arg, bool flag);
    void ReportHavokDeactivation();
    void RevertBGS_009b4d10(BGSLoadFormBuffer* buffer);
    void DispatchReferenceSourceFiles(ObjHelper*, void*, void*, void*, void*, void*, void*);
    void HandleContactHit(GPContact* contact);
};
