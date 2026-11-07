// fallout_shared/tesammo_decls.h: declares BGSProjectile, TESAmmoEffect, MiddleLowProcess, TESAmmoInitCalls
#ifndef TESAMMO_DECLS_H
#define TESAMMO_DECLS_H

class Script;
#include "tesammo_types.h"

#include "../../include/BGSProjectile.h"
#include "../../include/TESAmmoEffect.h"
// TESAmmo projectile form-ID field accessors (0x008d80e0 get / 0x00502c90 set); not MiddleLowProcess
class TESAmmoProjectileField
{
  public:
    int GetProcessInteger();
    void SetProcessInteger(int);
};
class TESAmmoInitCalls
{
  public:
    unsigned int GetFieldBC();
    void* TESAmmo_GetAmmoEffectList();
    void SetAmmoConsumed(void*);
};

extern "C"
{
    extern const char DAT_01026288[];
    extern const char DAT_01026238[];
    extern const char DAT_010261e8[];
}

int Warning(const char*, ...);

#endif
