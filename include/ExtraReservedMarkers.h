#pragma once

#include "BSExtraData.h"

class ExtraReservedMarkers : public BSExtraData
{
public:
    virtual ~ExtraReservedMarkers();

    ExtraReservedMarkers();
    void SetUsedMarker(unsigned int, bool);

    unsigned int m_uiReservedMarkers;
};
