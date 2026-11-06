#ifndef FNV_SETTING_AUTHORED_BODIES_H
#define FNV_SETTING_AUTHORED_BODIES_H


#include "setting_declarations.h"

// @fnv 0x0044f570
void __cdecl EnsureINISettingCollection()
{
    if (!g_pINISettingCollection)
        g_pINISettingCollection = new INISettingCollection;
}

// @fnv 0x0044f560
template <> INISettingCollection* SettingT<INISettingCollection>::GetCollection()
{
    EnsureINISettingCollection();
    return g_pINISettingCollection;
}

// @fnv 0x004de490
template <> INIPrefSettingCollection* SettingT<INIPrefSettingCollection>::GetCollection()
{
    EnsureINIPrefSettingCollection();
    return g_pINIPrefSettingCollection;
}

// @fnv 0x005e02b0
template <> Setting* SettingCollectionList<Setting>::GetPtr(const char* key)
{
    Setting* result = 0;
    Get(key, result);
    return result;
}

#endif
