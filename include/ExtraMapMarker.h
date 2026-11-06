#pragma once

#include "BSExtraData.h"

class MapMarkerData;

class ExtraMapMarker : public BSExtraData
{
public:
    ExtraMapMarker(MapMarkerData* pMapMarkerData);

    virtual ~ExtraMapMarker();
    virtual bool Compare(BSExtraData*);

    void __local_vftable_ctor_closure();

    MapMarkerData* data;
};
