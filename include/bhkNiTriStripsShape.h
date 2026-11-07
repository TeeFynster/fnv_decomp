#pragma once

#include "bhkShapeCollection.h"

class StripsShape;
class NiNode;

class bhkNiTriStripsShape : public bhkShapeCollection
{
public:
    virtual void BuildDisplayGeometry_00ca6b60(NiNode* parent, int arg);
    virtual void vf56();
    virtual void vf57();

    float GetScaleValue();
    static NiObject* __cdecl CreateObject();

    int unk00;
    int unk04;
    StripsShape* m_pShape;
};
