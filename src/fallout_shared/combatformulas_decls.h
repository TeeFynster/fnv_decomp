#pragma once

class CombatDamageCalculator
{
  public:
    static float CalculateWeaponDamage(ActorValueOwner*, TESObjectWEAP*, float, bool, InventoryStackRecord*, bool, bool, int,
                                       float, float, bool, bool, TESAmmo*);
    static float CalculateWeaponDamageForActor(TESObjectREFR*, TESObjectWEAP*, bool, InventoryStackRecord*);
    static float GetWeaponConditionDamageMultiplier(int);
    static float GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
    static float GetDamageMultiplier(float, float);
    static float CalculateArmorDamageThreshold(unsigned short rating, float condition);
};
