#pragma once

#include "hkpBoxMotion.h"

class hkpThinBoxMotion : public hkpBoxMotion
{
public:
    hkpThinBoxMotion(FinishingFlag flag);
    virtual ~hkpThinBoxMotion() throw();
};
