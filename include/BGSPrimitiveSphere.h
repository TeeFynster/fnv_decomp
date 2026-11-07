#pragma once

#include "BGSPrimitive.h"

class TESCombatStyle;

class BGSPrimitiveSphere : public BGSPrimitive
{
public:
    BGSPrimitiveSphere();
    virtual ~BGSPrimitiveSphere();
    virtual void vfn_04();
    virtual void ApplyColor(NiColorA& color);
    virtual void vf03(NiPoint3& radii);
    virtual bool vf04(TESCombatStyle& point);
    virtual void* vf05(int unused);

    void* FUN_004a71f0(unsigned int flags);
    void SetRadii(NiPoint3& radii);
    bool IsInside(TESCombatStyle& point);
    void SetColor_004a7830(NiColorA& color);

    void CreateSphereGeometry();
    void SetRadius(float radius);
};
