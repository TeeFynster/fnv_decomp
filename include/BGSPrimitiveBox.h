#pragma once

#include "BGSPrimitive.h"
#include "NiPoint3.h"

class BGSPrimitiveBox : public BGSPrimitive
{
public:
    BGSPrimitiveBox();
    virtual ~BGSPrimitiveBox();
    virtual void vf06();

    void NormalizeRadii(NiPoint3& radii);
    void SetColor(NiColorA& color);
    void Build();
    void SetSize(int value);
    void SetPosition(NiPoint3& position);

    void* m_apBoxData[6];
};
