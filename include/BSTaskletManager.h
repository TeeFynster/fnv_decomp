#pragma once

// vftable 0x010a48ac (10 slots). Slots 2..8 are _purecall (0x00ec60fa) here; BSWin32TaskletManager
// (vftable 0x010a4880) supplies them.
class BSTaskletManager
{
public:
    virtual void* __thiscall Destroy(unsigned int flags);                   // 0x00 0x00b02780
    virtual void vf01();                                                    // 0x04 0x00b02710 (empty)
    virtual void ShutdownThreads();                                         // 0x08 Win32 0x00b01f50
    virtual bool IsTaskletThread(unsigned int uiThreadId);                  // 0x0C Win32 0x00b02600
    virtual bool CreateTaskletGroup(int& rGroup);                           // 0x10 Win32 0x00b02010
    virtual bool OpenTaskletGroup(void* apGroup);                           // 0x14 Win32 0x00b020a0
    virtual bool AddTasklet(void* apGroup, void* apTasklet, bool abClose);  // 0x18 Win32 0x00b02220
    virtual bool CloseTaskletGroup(void* apGroup);                          // 0x1C Win32 0x00b02310
    virtual void DeleteTaskletGroup(void* apGroup);                         // 0x20 Win32 0x00b02360
    virtual void vf09();                                                    // 0x24 0x00aa7830

    int _04;
    int _08;
    void* _0c;
};
