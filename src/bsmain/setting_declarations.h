#include "../../include/SettingT.h"
// Private declarations for the setting template bodies.
#ifndef FNV_SETTING_PRIVATE_DECLARATIONS_H
#define FNV_SETTING_PRIVATE_DECLARATIONS_H


#include "../../include/layout_support.h"
#include "../../include/Setting.h"
#include "../../include/INIPrefSettingCollection.h"
#include "../../include/INISettingCollection.h"

#include "../../include/SettingT.h"

// File-level declarations for the original collection storage and initialization
// helpers, which are not exposed by the shared SettingT declaration.
extern INISettingCollection* g_pINISettingCollection;
extern INIPrefSettingCollection* g_pINIPrefSettingCollection;
void __cdecl EnsureINISettingCollection();
void __cdecl EnsureINIPrefSettingCollection();

// These are declarations only. The pack identifies the real global allocator.
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

FNV_STATIC_ASSERT(sizeof(INISettingCollection) == 0x114);
FNV_STATIC_ASSERT(sizeof(INIPrefSettingCollection) == 0x114);
FNV_STATIC_ASSERT(sizeof(SettingT<INISettingCollection>) == 0xC);
FNV_STATIC_ASSERT(sizeof(SettingT<INIPrefSettingCollection>) == 0xC);

#endif
