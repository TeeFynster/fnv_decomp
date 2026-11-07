#pragma once

#include "bhkContactListener.h"
#include "hkpEntityListener.h"
#include "hkpEntityActivationListener.h"

// No user-declared destructor: the implicit one (0x00807910) destroys the three bases without
// storing this class's vftables, which a user-declared destructor would do.
class bhkTelekinesisListener : public bhkContactListener,
                               public hkpEntityListener,
                               public hkpEntityActivationListener
{
public:
    virtual void EntityDeletionCallback(hkpEntity* entity);

    // The scalar deleting destructor (0x008078e0, primary vftable slot 3), spelled as a member.
    void* Destroy(unsigned int flags);
    void bhkTelekinesisListener_entityDeletedCallback(void* entity);
    void bhkTelekinesisListener_entityDeactivatedCallback(hkpEntity* entity);
    void bhkTelekinesisListener_Finish(hkpEntity* entity);
};
