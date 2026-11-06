#pragma once

#include "BSExtraData.h"
#include "TwoIntRecord.h"

class ExtraNavMeshPortal : public BSExtraData
{
public:
    ExtraNavMeshPortal(TwoIntRecord);

    TwoIntRecord handle;
};
