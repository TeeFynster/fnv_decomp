#pragma once

#include "bhkShape.h"

class bhkBvTreeShape : public bhkShape
{
public:
    bhkBvTreeShape();

    const char* const* GetArg1Ptr();

};
