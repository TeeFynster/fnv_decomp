#include "../../../include/InterfaceManager.h"
// fallout/interface/menuconsole_decls.h: console helpers and external declarations.
#ifndef FNV_MENUCONSOLE_DECLS_H
#define FNV_MENUCONSOLE_DECLS_H

#include "menuconsole_support.h"

extern "C" char* __cdecl __insecure_strcpy(char*, const char*);
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
extern "C" int __cdecl sscanf(const char*, const char*, ...);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
namespace console_crt
{
    int __cdecl strcat_s(char*, unsigned int, const char*);
}
int __cdecl _mbsicmp(const unsigned char*, const unsigned char*);
int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
int __cdecl _mbsnicmp(const unsigned char*, const unsigned char*, unsigned int);
template <class T> unsigned int BSStringLength(const T*);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
void DebugLog(const char*, ...);
int FUN_0071cfd0(const char*, const char*, unsigned int);
int FUN_0071cff0(const char*, const char*, unsigned int);
void FUN_005cbd90(char*, const char*, unsigned int);
void FUN_0071d030(ConsoleManager*, const char*, ...);
void FUN_007030c0(int, int);
void FUN_007038e0(int);
void FUN_00703920();
void FUN_00702c80(bool, bool);
void UpdateMenuTileVisibility();
int FUN_0070ede0();
int MinInt(int, int);
int FUN_00647b70(int, int);

#include "../../../include/SETTING_VALUE.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
extern SettingT_GameSettingCollection_ DAT_011d8cfc;
extern SettingT_GameSettingCollection_ DAT_011d8d38;
extern bool DAT_011d8ce4;

#include "../../../include/COMPILER_NAME.h"
FNV_STATIC_ASSERT(sizeof(Script) == 0x54);
Tile* FindNamedTile(Tile*, const char*);
Menu* FindMenuById(int);

InterfaceManager* FUN_004b7210();
class MenuSystem
{
  public:
    static MenuSystem* Instance(bool);
    Tile* TileReloadContext(int);
    bool DeleteMenu(int);
    Menu* GetFrontmostMenu();
    bool IsMenuClassVisible(int);
};
void* DynamicCastByRTTI(void*, NiNode*);
extern unsigned char DAT_011f4428;
const char* FUN_00700300(Tile*);

FNV_STATIC_ASSERT(sizeof(BSFile) == 0x158);
FNV_STATIC_ASSERT(sizeof(NiFrustum) == 28);
#endif
