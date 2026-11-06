// fallout_shared/packagelocation_runtime.h: declares TESObjectCELL, BGSCameraPath
#ifndef FNV_PACKAGELOCATION_RUNTIME_H
#define FNV_PACKAGELOCATION_RUNTIME_H


class BSExtraData;
class InventoryChanges;
class TESBoundObject;
struct CellDataNode;
class AnimData;
class ValidBip01Names;
class ScriptLocals;

#include "../../include/TESForm.h"
#include "packagelocation_reference.h"
#include "packagelocation_process.h"
#include "packagelocation_package.h"

// Only the base relationship is needed by the runtime checked cast.
class TESObjectCELL : public TESForm
{
};

// The canonical binding names this folded form-name predicate after its
// BGSCameraPath use. It operates on the TESForm prefix of the owner.
class BGSCameraPath : public TESForm
{
  public:
    int HasNameForWarning();
};

int Warning(const char* format, ...);

#endif
