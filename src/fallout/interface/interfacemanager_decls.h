#include "../../../include/InterfaceManager.h"
// fallout/interface/interfacemanager_decls.h: declares SettingT_GameSettingCollection_, SystemColorManager, SoftSystemColor, InterfaceManager
#ifndef FNV_INTERFACEMANAGER_DECLS_H
#define FNV_INTERFACEMANAGER_DECLS_H

#include "../../../include/SETTING_VALUE.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
class SystemColorManager
{
  public:
    class SoftSystemColor
    {
      public:
        unsigned char padding[12];
        SettingT_GameSettingCollection_* setting;
        unsigned int GetColor();
    };
};
class FORenderedMenu;

#endif
