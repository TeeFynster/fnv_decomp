#pragma once

#include "bhkSerializable.h"

class bhkCharacterProxy : public bhkSerializable
{
public:
    virtual ~bhkCharacterProxy();

    virtual const NiRTTI* GetRTTI() const;
};
