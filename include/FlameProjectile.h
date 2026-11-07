#pragma once

#include "Projectile.h"

class FlameProjectile : public Projectile
{
public:
    FlameProjectile();
    virtual bool IsProximityDetonationTriggered();
    void LoadGame_009b3f00(BGSLoadFormBuffer* apLoadGameBuffer);
    void RevertBGS_009b3f50(BGSLoadFormBuffer* apLoadGameBuffer);
};
