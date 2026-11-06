#pragma once

class hkpEntity;

// Havok 7.1 hkpEntityActivationListener (RTTI vftable 0x0106c3c4: the destructor, then two pure
// virtuals; 0x006c0150 is the destructor).
class hkpEntityActivationListener
{
public:
    virtual ~hkpEntityActivationListener();
    virtual void entityDeactivatedCallback(hkpEntity* entity) = 0;
    virtual void entityActivatedCallback(hkpEntity* entity) = 0;
};
