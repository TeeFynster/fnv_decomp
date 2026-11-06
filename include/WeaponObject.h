#pragma once

#include "bhkBlendCollisionObject.h"

class WeaponObject : public bhkBlendCollisionObject
{
  public:
    void UpdateWeapon(bool immediate, void* weaponData, NiAVObject* root, bool hidden);
    void AttachWeapon();
    void* GetTranslation(void* translation);
};
