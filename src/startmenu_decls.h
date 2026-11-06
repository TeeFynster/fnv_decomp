// startmenu_decls.h: declares StartMenuInterfaceQuery
#ifndef FNV_STARTMENU_DECLS_H
#define FNV_STARTMENU_DECLS_H

// Interface's static menu query at 0x00702450 (Interface::GetSelectedTargetIndex(enumMenus)); the shared Menu.h has
// Interface only as a stub, so the call goes through this helper bound to that address
class StartMenuInterfaceQuery
{
  public:
    enum enumMenus
    {
        START_MENU = 0x3f5
    };
    static bool GetSelectedTargetIndex(enumMenus);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
#endif
