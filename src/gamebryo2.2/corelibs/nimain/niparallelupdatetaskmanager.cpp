// gamebryo2.2/corelibs/nimain/niparallelupdatetaskmanager.cpp: Interface, NiParallelUpdateTaskManager (1 function)

#include "niparallelupdatetaskmanager_decls.h"

// @fnv 0x0086f450
void NiParallelUpdateTaskManager::DispatchParallelUpdates()
{
    if (DAT_011dea2b && !Interface::GetSelectedTargetIndex(Interface::DialogueMenu) && !StartMenu_MainMenuIsActive() &&
        !Interface::IsMenuActive(Interface::VATSMenu, 11) && !Interface::IsMenuActive(Interface::MessageMenu, 11) &&
        !Interface::IsPipboyMenuActive() && !Interface::IsConsoleActive() && !DAT_011dea29 && DAT_011dea28)
    {
        reinterpret_cast<Main*>(this)->RunFrame();
    }
    else if (DAT_011dea29 &&
             (!DAT_011dea2b || StartMenu_MainMenuIsActive() || (Interface::IsConsoleActive() && !Interface::IsPipboyMenuOpen()) ||
              Interface::GetSelectedTargetIndex(Interface::DialogueMenu) ||
              Interface::GetSelectedTargetIndex(Interface::VATSMenu)) &&
             !DAT_011d8804->FaderManager_IsFaderActive(true) && !Interface::IsMenuActive(Interface::Menu_41e, 0) &&
             !Interface::IsMenuActive(Interface::Menu_3f6, 0) && !Interface::IsMenuActive(Interface::Menu_424, 0) &&
             !Interface::IsMenuActive(Interface::Menu_432, 0) && !Interface::IsMenuActive(Interface::Menu_438, 0) &&
             !Interface::IsMenuActive(Interface::Menu_439, 0) && !Interface::IsMenuActive(Interface::Menu_43a, 0) &&
             !Interface::IsMenuActive(Interface::Menu_43b, 0))
    {
        reinterpret_cast<Main*>(this)->RefreshAfterSave();
    }
}
