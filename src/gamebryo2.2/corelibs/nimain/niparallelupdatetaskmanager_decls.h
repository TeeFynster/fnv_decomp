#include "../../../../include/Interface.h"
// gamebryo2.2/corelibs/nimain/niparallelupdatetaskmanager_decls.h: declares Interface, Main, NiParallelUpdateTaskManager
#ifndef NIPARALLELUPDATETASKMANAGER_DECLS_H
#define NIPARALLELUPDATETASKMANAGER_DECLS_H




class Main
{
  public:
    void RunFrame();
    void RefreshAfterSave();
};

class NiParallelUpdateTaskManager
{
  public:
    void DispatchParallelUpdates();
};

// The packet has no identities for these menu-state globals and helper.
extern bool DAT_011dea28;
extern bool DAT_011dea29;
extern bool DAT_011dea2b;
extern Interface* DAT_011d8804;
bool StartMenu_MainMenuIsActive();

#endif
