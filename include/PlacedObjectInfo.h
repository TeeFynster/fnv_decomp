#pragma once

#include "NiPoint3.h"

class TESBoundObject;

class PlacedObjectInfo
{
public:
    TESBoundObject* m_pPlacedObject;
    NiPoint3 Angle;
    NiPoint3 Location;
};
