#pragma once

class ContactArray;
class hkpWorld;

class hkpPhysicsContextWorldListener
{
public:
    virtual ~hkpPhysicsContextWorldListener() throw();
    virtual void WorldAddedCallback(hkpWorld* world);
    virtual void WorldRemovedCallback(hkpWorld* world);

    void UpdateFields_00de2980(void*) throw();
};
