#include "../../include/BSLinearTaskThread.h"
#include "../../include/CountingSemaphore.h"

// @fnv 0x008c7720
unsigned int BSLinearTaskThread::ThreadProc()
{
    vfn_08();
    while (!stopping)
    {
        reinterpret_cast<CountingSemaphore&>(request).Wait();
        if (stopping)
            break;
        vfn_10();
        reinterpret_cast<CountingSemaphore&>(completion).Signal();
    }
    vfn_0c();
    reinterpret_cast<CountingSemaphore&>(completion).Signal();
    return 0;
}
