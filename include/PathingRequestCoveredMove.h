#pragma once

#include "PathingRequest.h"

class PathingRequestCoveredMove : public PathingRequest
{
public:
    class AvoidanceItems
    {
    public:
        void FUN_007cb2e0();
    };

    PathingRequestCoveredMove();
    virtual ~PathingRequestCoveredMove();

    PathingRequestCoveredMove* FUN_006e4a50();

    void FUN_005076c0(float);
    void FUN_006e4f10(unsigned int);
    int GetOffsetF4();
    int FUN_006e4f90();
    AvoidanceItems* FUN_006e4f90(void*);

    union
    {
        char extra[44];
        void* unkB0;
    };
    unsigned int unkDC[12];
};
