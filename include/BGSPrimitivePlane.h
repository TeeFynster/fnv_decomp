#pragma once

#include "BGSPrimitive.h"

class BGSPrimitivePlane : public BGSPrimitive
{
public:
    BGSPrimitivePlane();
    virtual ~BGSPrimitivePlane();
    virtual void vf06();
    virtual void vf07();

    void SetColor(NiColorA& color);
    void Build();
    void NormalizeRadii(NiPoint3& radii);
};
