#include "../../include/BSStringT.h"
// fallout_shared/tesscript_layout.h: declares TESFile, TESFullNameLoader
#ifndef FNV_LAYOUT_SUPPORT_H
#define FNV_LAYOUT_SUPPORT_H
#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
class Actor;
class EffectSetting;
class TESForm;
class TESFile;
class TESFaction;
class TESObjectREFR;
class MediaSet;
class MediaLocationController;
class NiNode;
class TESSound;
#include "../../include/BSSimpleList.h"

FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
FNV_STATIC_ASSERT(sizeof(BSStringT<char>) == 8);
#include "../../include/ENUM_FORM_ID.h"

#include "../../include/NiFile.h"
#include "../../include/TESFile.h"
class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
};
extern "C" void* __cdecl _alloca(size_t auiBytes);
#include "../../include/CHUNK_ID.h"
#endif
