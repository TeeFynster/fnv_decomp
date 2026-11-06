#pragma once

#include "hkpContactListener.h"

// The destructor is user-declared: 0x006234d0 stores the bhkContactListener vftable (0x0104dd5c)
// before calling ~hkpContactListener.
class bhkContactListener : public hkpContactListener
{
public:
    virtual ~bhkContactListener();
};
