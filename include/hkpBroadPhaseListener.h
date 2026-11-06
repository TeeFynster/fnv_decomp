#pragma once

class hkpBroadPhaseListener
{
public:
    virtual ~hkpBroadPhaseListener();
    virtual void AddCollisionPair(void* pair) = 0;
    virtual void RemoveCollisionPair(void* pair) = 0;
};
