#include "../../../../include/Interface.h"
// gamebryo2.2/corelibs/nimain/nirefobject_queue.h: declares Interface, ScrapHeapTaskQueue

class BGSLoadGameBuffer;

int __cdecl BSAtomicCompareExchange(volatile long*, long, long);
class ScrapHeapTaskQueue
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual bool Enqueue(void*);
    volatile long lock;
    bool QueueCall(void*);
};
