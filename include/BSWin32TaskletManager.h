#pragma once

#include "BSTaskletManager.h"

// vftable 0x010a4880: slots 1 (0x00b02710) and 9 (0x00aa7830) are inherited, the rest overridden.
class BSWin32TaskletManager : public BSTaskletManager
{
public:
    BSWin32TaskletManager(unsigned int uiThreadCount);
    ~BSWin32TaskletManager();

    virtual void* __thiscall Destroy(unsigned int flags);                   // 0x00 0x00b02640
    virtual void ShutdownThreads();                                         // 0x08 0x00b01f50
    virtual bool IsTaskletThread(unsigned int uiThreadId);                  // 0x0C 0x00b02600
    virtual bool CreateTaskletGroup(int& rGroup);                           // 0x10 0x00b02010
    virtual bool OpenTaskletGroup(void* apGroup);                           // 0x14 0x00b020a0
    virtual bool AddTasklet(void* apGroup, void* apTasklet, bool abClose);  // 0x18 0x00b02220
    virtual bool CloseTaskletGroup(void* apGroup);                          // 0x1C 0x00b02310
    virtual void DeleteTaskletGroup(void* apGroup);                         // 0x20 0x00b02360

    bool __thiscall GetTaskletValue(void* result);
    void ReleaseItem(void* item);

    unsigned char m_Data[64];
};
