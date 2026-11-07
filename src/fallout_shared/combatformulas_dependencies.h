#ifndef FNV_COMBATFORMULAS_DEPENDENCIES_H
#define FNV_COMBATFORMULAS_DEPENDENCIES_H

#include "combatformulas_decls.h"
class TESAmmoInitCalls
{
  public:
    void* TESAmmo_GetAmmoEffectList();
};
extern Setting DAT_011ce2c0;
extern Setting DAT_011cece8;
extern Setting DAT_011ceef0;
extern Setting DAT_011cf21c;
extern Setting DAT_011cf350;
extern Setting DAT_011cf6c0;
extern Setting DAT_011cf810;
extern Setting DAT_011cf888;
extern Setting DAT_011cfbf0;
extern PlayerCharacter* g_thePlayer;
extern const double runtimeInitializationDouble2;
float GetWeaponHealthConditionMultiplier(float);
float GetArmorConditionFactor(float);
float BSMIN(float, float);
float BSMAX_00404010(float, float);
void BSClamp_float(float&, float, float);
float RandomFloat(float, float);
void ApplyPerkModifiers(int, Actor*, ...);
class CombatWeaponCritical
{
  public:
    float ProcessActorAction();
};
enum AMMO_EFFECT_TYPE
{
    AMMO_EFFECT_TYPE_AMMO_EFFECT_DAM = 0
};
#endif
