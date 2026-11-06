// fallout/misc/saveload/bgssaveloadgame_decls.h: declares FormChangeMask, TESDataHandlerSaveLoad, FormChangeRecord and more
#ifndef BGSSAVELOADGAME_DECLS_H
#define BGSSAVELOADGAME_DECLS_H

// TESForm comes from the canonical TESForm.h; TESDataHandler and TESObjectCELL
// come from layout_support.h. The source includes the shared NiTPointerMap.
#include "layout_support.h"
#include "TESForm.h"
#include "../../../../include/BGSReconstructFormsInAllFilesMap.h"
class TESFile;
class BGSReconstructFormsInFileMap;
class TESObjectREFR;
#include "../../../../include/FormChangeMask.h"
// TESDataHandler members the canonical (API-only) layout_support.h class does not declare yet; called through a cast
// of g_dataHandler (same address).
class TESDataHandlerSaveLoad
{
  public:
    bool FormIDExists(unsigned int);
    unsigned int GetNextID();
    TESFile* GetCompiledFileByIndex(int);
    unsigned char GetCompiledFileCount();
};
extern TESDataHandler* g_dataHandler;
class FormChangeRecord
{
  public:
    FormChangeMask flags;
    FormChangeMask savedFlags;
};
// The shared map's nested character storage enables an extra /GS check in
// BGSSaveLoadGame::FormReconstructionMap (0x00849b10), changing its original bytes.
class BGSSaveLoadReferencesMap
{
  public:
    void LoadCellReferences(TESObjectCELL*, BGSReconstructFormsInAllFilesMap*);
};
#endif
