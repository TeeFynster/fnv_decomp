#include "../../../include/OSGlobals.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/AILinearTaskThread.h"
#include "../../../include/hkMemoryRouter.h"
#include "../../../include/TESEnchantableForm.h"
#include "../../../include/hkMemoryAllocator.h"
#include "../../../include/hkMemorySystem.h"
// fallout/ai/ailineartaskthread.cpp: AILinearTaskThread, Thr (3 functions)

struct Flag
{
    int value;

  public:
    Flag(int);
    Flag(const Flag&);
};
// 0x008c6ff0 passes ThreadMemory; folded helper 0x00984f60 stores its allocator at +0x18.
class RouterAllocatorView_008c6ff0
{
  public:
    void FUN_00984f60(unsigned int);
};
class BGSPerkEntry;
#include "../../../include/BSSimpleList.h"
class PointerCallback
{
  public:
    static void HandlePointer(void*);
};
extern TESDataHandler* g_dataHandler;
// @fnv 0x008c6ff0
void AILinearTaskThread::StartTaskThread()
{
    hkMemorySystem::GetMonitorStream()->InitializeThreadRouter(&ThreadMemory, "AILinearTaskThread", Flag(1));
    PointerCallback::HandlePointer(&ThreadMemory);
    ((TESEnchantableForm*)&ThreadMemory)
        ->SetCastingType((MagicSystem__CastingType)((OSGlobals*)&ThreadMemory)->GetUptimeMilliseconds());
    ((RouterAllocatorView_008c6ff0*)&ThreadMemory)->FUN_00984f60(((OSGlobals*)&ThreadMemory)->GetUptimeMilliseconds());
    m_pTaskMemory = ((hkMemoryAllocator*)((OSGlobals*)&ThreadMemory)->GetUptimeMilliseconds())->blockAlloc(0x32000);
    ((hkMemorySystem*)&((BSSimpleList<BGSPerkEntry*>*)&ThreadMemory)->GetItem())->GetMonitorStream(m_pTaskMemory, 0x32000);
    g_dataHandler->BuildCompiledFileList();
}

void __cdecl operator delete(void*);
struct FUN_008c7830
{
    void FUN_008c7860();
    FUN_008c7830* FUN_008c7830_(unsigned int aiFlags);
};
// Calls FUN_008c7860, frees this with operator delete when aiFlags has bit 0 set, and returns this.
// @fnv 0x008c7830
FUN_008c7830* FUN_008c7830::FUN_008c7830_(unsigned int aiFlags)
{
    FUN_008c7860();
    if (aiFlags & 1)
        operator delete(this);
    return this;
}

struct Alloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8(void* p, int n);
};
struct Fin
{
    void Done();
};
// 0x006815c0 returns this (folded identity, ReturnThis); here it is called on the thread's router with two
// zero arguments.
struct ReturnThis_6815c0
{
    Fin* Next(int a, int b);
};
struct HkSys
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10(hkMemoryRouter* r, Flag g);
};
void hkInit();
HkSys* hkGet();
struct Thr
{
    char padding[0x50];
    hkMemoryRouter memoryRouter;
    void* memory;
    void InitMemory();
};
// @fnv 0x008c7110
void Thr::InitMemory()
{
    memoryRouter.heap().blockFree(memory, 0x32000);
    hkInit();
    hkGet()->v10(&memoryRouter, Flag(1));
    reinterpret_cast<ReturnThis_6815c0*>(&memoryRouter)->Next(0, 0)->Done();
}
