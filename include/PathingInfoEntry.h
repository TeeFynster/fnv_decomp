#pragma once

#include "PathingInfoParams.h"

#include "PATHING_INFO_TYPE.h"

#include "PATHING_MESSAGE_ID.h"

#include "PATHING_PARAMETER_ID.h"

class PathingInfoEntry
{
public:
    PATHING_INFO_TYPE InfoType;
    PATHING_MESSAGE_ID MessageID;
    PATHING_PARAMETER_ID ParamID;
    PathingInfoParams Params;

    PathingInfoEntry& operator=(const PathingInfoEntry&);
};
