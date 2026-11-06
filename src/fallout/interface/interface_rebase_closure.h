// fallout/interface/interface_rebase_closure.h: declares MessageMenu, LoadingMenu, AutoMemContext
#ifndef FNV_INTERFACE_REBASE_CLOSURE_H
#define FNV_INTERFACE_REBASE_CLOSURE_H

#include <stdarg.h>
#include "interface_rebase_types_Tile.h"
#include "interface_rebase_Menu.h"
#include "interface_rebase_PlayerCharacter.h"
#include "interface_rebase_PC_NiNode.h"
#include "interface_rebase_BSFadeNode.h"
#include "interface_rebase_types_FOPipboyManager.h"
#include "interface_rebase_types_TESCreature.h"
#include "interface_rebase_TESRecipe.h"
#include "interface_rebase_types_ActiveEffect.h"
#include "interface_rebase_HUDMainMenu.h"
#include "interface_rebase_types_MenuManager.h"
#include "interface_rebase_types_BSAnimGroupSequence.h"
class MessageMenu
{
  public:
    static void SetMessageMenuActive(bool);
};
class LoadingMenu
{
  public:
    static Tile* Create(TESForm*, bool, bool);
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, unsigned int);
    ~AutoMemContext();

  private:
    MEM_CONTEXT eOldMemContext;
};
FNV_STATIC_ASSERT(sizeof(MEM_CONTEXT) == 4);
FNV_STATIC_ASSERT(sizeof(AutoMemContext) == 4);
FNV_STATIC_ASSERT(offsetof(InterfaceManager, fScreenAspectRatio) == 0x4D0);
extern PlayerCharacter* g_thePlayer;
#endif
