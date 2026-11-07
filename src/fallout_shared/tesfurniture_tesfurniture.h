#include "../../include/BSStringT.h"
// Unit header for fallout_shared/tesfurniture.cpp: the shared TESFurniture hierarchy plus the externals the unit calls.
#ifndef FNV_TESFURNITURE_UNIT_H
#define FNV_TESFURNITURE_UNIT_H

#include <stddef.h>
// BSStringT with its out-of-line constructor and destructor (0x004037b0), as TESObjectACTI's constructor calls them.

#include "../../include/TESFurniture.h"
#include "../../include/TESFile.h"
#include "../../include/FurnitureMark.h"
#include "../../include/SettingT_GameSettingCollection_.h"

class NiAVObject;
class NiNode;
class Script;
NiAVObject* BSFurnitureMarker_Find(NiNode*);
int Warning(const char*, ...);
extern SettingT<GameSettingCollection>* g_ppFurnitureMarkerOffsetSettings[][4];
extern "C" void* __cdecl _alloca(size_t auiBytes);

#include "../../include/ENUM_FORM_ID.h"
#include "../../include/CHUNK_ID.h"

// TESFile::GetFormVersion view (0x004d0d10 family), kept as the unit's shim.
class TESFileFormVersion : public TESFile
{
  public:
    unsigned short GetFormVersion();
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
};
// TESForm::IsFormInitialized is folded with BGSDefaultObjectManager::IsFormInitialized (0x004013e0).
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};

#endif
