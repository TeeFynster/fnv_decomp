#pragma once

#include "hkReferencedObject.h"
#include "hkpPhantomOverlapListener.h"

class hkpRejectChassisListener : public hkReferencedObject, public hkpPhantomOverlapListener
{
public:
    virtual ~hkpRejectChassisListener();

    // The hkpPhantomOverlapListener vtable pointer occupies pad8.
    void* m_pChassisCollidable;
};
