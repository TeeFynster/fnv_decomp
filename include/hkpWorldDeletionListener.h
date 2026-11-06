#pragma once

class hkpWorld;

class hkpWorldDeletionListener
{
public:
    virtual ~hkpWorldDeletionListener();
    virtual void WorldDeletedCallback(hkpWorld* world) = 0;
    virtual void worldRemoveAllCallback(hkpWorld* world);
};
