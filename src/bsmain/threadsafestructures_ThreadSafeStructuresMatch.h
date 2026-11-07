// Unit-local C++03 declarations. Layout evidence is itemized in NOTES.md.
#ifndef FNV_THREAD_SAFE_STRUCTURES_MATCH_H
#define FNV_THREAD_SAFE_STRUCTURES_MATCH_H

#include <stddef.h>
void* __cdecl operator new(size_t);
void* __cdecl operator new[](size_t);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
extern "C" const char kThreadSafeStructuresSourceFile[];
unsigned int __cdecl _TlsAlloc();
class bhkRigidBody;
class QueuedReference;
class TESObjectREFR;
class AnimIdle;
class QueuedAnimIdle;
class Animation;
class QueuedReplacementKFList;
class QueuedHelmet;
class Model;
class ExteriorCellLoaderTask;
#include "../../include/MEM_CONTEXT.h"
template <class T> class ThreadInterfaceManager
{
  public:
    struct ThreadInterfaceEntry
    {
        ThreadInterfaceEntry();
        unsigned int uiThreadID;
        T* pInterface;
    };
    unsigned int uiMaxThreads;
    unsigned int uiTLSIndex;
    ThreadInterfaceEntry* m_pThreadInterfaceEntries;
    unsigned int uiThreadCount;
    ThreadInterfaceManager(unsigned int maxThreads);
};
#include "../../include/LockFreeQueue.h"


typedef LockFreeQueue<bhkRigidBody*> RigidBodyQueue;
typedef LockFreeMap<unsigned int, NiPointer<ExteriorCellLoaderTask> > TreeMap;
typedef char CheckSpinLockSize[(sizeof(RecursiveSpinLock) == 32) ? 1 : -1];
typedef char CheckQueueSize[(sizeof(RigidBodyQueue) == 64) ? 1 : -1];
typedef char CheckQueueLock[(offsetof(RigidBodyQueue, kLock) == 32) ? 1 : -1];
typedef char CheckMapSize[(sizeof(TreeMap) == 64) ? 1 : -1];
typedef char CheckMapLock[(offsetof(TreeMap, kLock) == 32) ? 1 : -1];
typedef char CheckMapInterface[(sizeof(TreeMap::DeletedNodeScanner) == 36) ? 1 : -1];
#endif
