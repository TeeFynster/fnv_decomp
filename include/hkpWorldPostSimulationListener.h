#pragma once

class hkpWorld;
class hkpEntity;

class hkpWorldPostSimulationListener
{
public:
    virtual ~hkpWorldPostSimulationListener() throw();
    virtual void postSimulationCallback(hkpWorld* world) = 0;
    virtual void EntityRemovalCallback(hkpEntity* entity);
};
