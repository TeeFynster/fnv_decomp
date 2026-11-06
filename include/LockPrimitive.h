#pragma once

class LockPrimitive
{
public:
    LockPrimitive();
    ~LockPrimitive();

    unsigned int m_uiLockState;

    void Lock();
    bool TryLock();
    void Unlock();
    bool IsLocked() const;
};
