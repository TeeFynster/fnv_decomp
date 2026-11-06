#pragma once

#include "NiObject.h"

class ScreenReference;

class NiScreenPolygon : public NiObject
{
  public:
    ScreenReference* unk08;
    ScreenReference* unk0C;
    ScreenReference* unk10;
    ScreenReference* unk14;
    ScreenReference* unk18;

    NiScreenPolygon(const NiScreenPolygon& other);
    NiScreenPolygon& operator=(const NiScreenPolygon& other);
};
