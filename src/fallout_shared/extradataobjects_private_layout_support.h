// fallout_shared/extradataobjects_private_layout_support.h: declares TESFullNameLoader
#ifndef FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H
#define FNV_EXTRADATAOBJECTS_PRIVATE_LAYOUT_SUPPORT_H
#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
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
#include "../../include/BSStringT.h"
FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
FNV_STATIC_ASSERT(sizeof(BSStringT<char>) == 8);
#include "../../include/ENUM_FORM_ID.h"

class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
};
extern "C" void* __cdecl _alloca(size_t auiBytes);
#include "../../include/CHUNK_ID.h"
#endif
