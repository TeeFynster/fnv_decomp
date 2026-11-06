#pragma once

#include "bhkShapeCollection.h"

class bhkPackedNiTriStripsShape : public bhkShapeCollection
{
public:
    bhkPackedNiTriStripsShape();
    static NiObject* __cdecl CreateObject();

    virtual void vf56();
};
