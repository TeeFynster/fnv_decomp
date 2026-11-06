
#include "../include/StartMenu.h"
#include "startmenu_decls.h"

extern StartMenu::OptionManager* DAT_011daac4;

// @fnv 0x007cb4d0
int StartMenu::GetClass()
{
    return 0x3f5;
}

// @fnv 0x00403df0
TileMenu* StartMenu::GetMenuTitle()
{
    return this ? pMenu : 0;
}

// @fnv 0x007ce8f0
bool StartMenu::IsStartMenuActive()
{
    return StartMenuInterfaceQuery::GetSelectedTargetIndex(StartMenuInterfaceQuery::START_MENU) && IsFlagSet(FLAG_ACTION_MAPPING) &&
           m_kDownloadOptions.IsListItem(static_cast<void*>(m_kDownloadOptions.GetHighlightedItem()));
}

// @fnv 0x007cb710
StartMenu::OptionManager* StartMenu::OptionManager::Instance()
{
    if (!DAT_011daac4)
        DAT_011daac4 = new OptionManager;
    return DAT_011daac4;
}
