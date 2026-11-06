#pragma once

#include <cstddef>

class PhysicsSimulationContext;
struct hkFinishLoadedObjectFlagCD2C;

class hkMultiThreadCheck
{
public:
    enum AccessType
    {
        HK_ACCESS_IGNORE = 0,
        HK_ACCESS_RO = 1,
        HK_ACCESS_RW = 2
    };

    enum ReadMode
    {
        THIS_OBJECT_ONLY = 0,
        RECURSIVE = 1
    };

    enum
    {
        MARKED_RO = 0xffffffe1,
        MARKED_RO_SELF_ONLY = 0xffffffc1,
        UNMARKED = 0xfffffff1
    };

    unsigned int m_uiThreadId;
    unsigned short m_usMarkedForWrite;
    unsigned short m_usMarkCount;

    hkMultiThreadCheck();
    hkMultiThreadCheck(hkFinishLoadedObjectFlagCD2C flag);

    void markForReadImpl(ReadMode mode);

    static void* __cdecl operator new(std::size_t nbytes);
    static PhysicsSimulationContext* m_pWorldLock;
};
