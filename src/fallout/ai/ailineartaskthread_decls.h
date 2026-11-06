// fallout/ai/ailineartaskthread_decls.h: declares BSThread, CountingSemaphore, BSLinearTaskThread, hkMemoryRouter, AILinearTaskThread
#ifndef BSLINEARTASKTHREAD_DECLS_H
#define BSLINEARTASKTHREAD_DECLS_H

class BSThread
{
  public:
    BSThread();
    virtual ~BSThread();
    virtual unsigned int ThreadProc();
    unsigned char threadData[0x2c];
};
class CountingSemaphore
{
  public:
    CountingSemaphore();
    ~CountingSemaphore();
    void Wait();
    void Signal();
    unsigned char data[12];
};
class BSLinearTaskThread : public BSThread
{
  public:
    BSLinearTaskThread();
    virtual unsigned int ThreadProc();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    CountingSemaphore m_kWorkAvailableSemaphore;
    CountingSemaphore m_kCompletionSemaphore;
    bool m_bStopRequested;
};
#endif
#include "../../../include/hkMemoryRouter.h"
class AILinearTaskThread : public BSLinearTaskThread
{
  public:
    AILinearTaskThread(void(__cdecl* taskFunction)());
    virtual ~AILinearTaskThread();
    void(__cdecl* m_pTaskFunction)();
    hkMemoryRouter ThreadMemory;
    void* m_pTaskMemory;
};
