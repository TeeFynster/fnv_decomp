#pragma once

#include "BSExtraData.h"

class ExtraUsedMarkers : public BSExtraData
{
public:
    virtual ~ExtraUsedMarkers();

    ExtraUsedMarkers();
    void SetUsedMarker(unsigned int aMarker, bool aUsed);
    bool IsUsedMarker(unsigned int aMarker);

    unsigned int m_uiUsedMarkerFlags;
};
