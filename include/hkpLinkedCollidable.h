#pragma once

#include <cstddef>
#include "hkpCollidable.h"
#include "hkaAnimation.h"

class NarrowPhaseAgentEntry;
struct hkFinishLoadedObjectFlagCD2C;

class hkpLinkedCollidable : public hkpCollidable
{
public:
    struct CollisionKeyEntry
    {
        static void* __cdecl operator new(std::size_t nbytes);
        static void __cdecl operator delete(void* p);
        static void* __cdecl operator new(std::size_t n, void* p);
        static void* __cdecl operator new[](std::size_t n, void* p);
        static void __cdecl operator delete(void* p, void* placement);
        static void __cdecl operator delete[](void* p, void* placement);

        class CommandArgument;

        NarrowPhaseAgentEntry* m_pAgentEntry;
        hkpLinkedCollidable* m_pCollidable;
    };

    hkpLinkedCollidable(const void* shape, const void* motionState, int type);
    hkpLinkedCollidable(hkFinishLoadedObjectFlagCD2C flag);

    static void* __cdecl operator new(std::size_t nbytes);
    const hkArray<CollisionKeyEntry>& getCollisionEntriesDeterministicUnchecked() const;

    hkArray<char> m_kCollisionEntries;
};
