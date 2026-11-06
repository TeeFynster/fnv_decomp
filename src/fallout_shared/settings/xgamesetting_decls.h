// fallout_shared/settings/xgamesetting_decls.h: shared Setting/GameSettingCollection plus the reader's helpers
#ifndef FNV_XGAMESETTING_DECLS_H
#define FNV_XGAMESETTING_DECLS_H


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "layout_support.h"
#include "TESFile.h"
#include "SETTING_VALUE.h"

#include "../../../include/GameSettingCollection.h"

FNV_STATIC_ASSERT(sizeof(Setting) == 0xC);
FNV_STATIC_ASSERT(offsetof(Setting, uValue) == 0x4);
FNV_STATIC_ASSERT(offsetof(Setting, pKey) == 0x8);
FNV_STATIC_ASSERT(offsetof(GameSettingCollection, pFile) == 0x108);

extern "C" void* __cdecl _alloca(unsigned int size);
const char* PrepareScriptMessage(const char* text, bool alternate);

#endif
