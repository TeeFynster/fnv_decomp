#pragma once

class BGSZoneTargetListener
{
public:
    virtual void* __thiscall Destroy(unsigned int flags);
    virtual void* Create(unsigned int a, unsigned int b);
    virtual void* CreateZoneTargetNode(unsigned int a, unsigned int b);

    ~BGSZoneTargetListener();
    void SetFlags(int flags, bool set);

    int m_flags;
};
