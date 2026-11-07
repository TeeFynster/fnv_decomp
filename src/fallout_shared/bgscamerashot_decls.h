// fallout_shared/bgscamerashot_decls.h: declares VATS, StateNode, CameraTargetResetFields, TESFileFormInt, CombatProcedure and more
#ifndef FNV_BGSCAMERASHOT_DECLS_H
#define FNV_BGSCAMERASHOT_DECLS_H

class BSExtraData;
class InventoryChanges;
class TESBoundObject;
class TESObjectCELL;
class CellDataNode;
class AnimData;
class ValidBip01Names;
class ScriptLocals;
class NiAVObject;
int __cdecl Warning(const char*, ...);
class VATS
{
  public:
    void ProcessVATSCommands();
};
class StateNode
{
  public:
    void ResetCameraState();
};
class ImageSpaceModifierInstanceDOF;
void ImageSpaceModifierInstance_Stop(ImageSpaceModifierInstanceDOF*);
struct CameraTargetResetFields
{
    char pad[12];
    void* field0c;
    StateNode* node;
    float f14, f18;
    char pad1c[12];
    ImageSpaceModifierInstanceDOF* a;
    ImageSpaceModifierInstanceDOF* b;
};
class TESFileFormInt
{
  public:
    int GetTESForm();
};
struct CameraShotLegacyData
{
    int action, location, target;
    unsigned int flags;
    float playerMult, globalMult, maxTime, minTime;
    void ProcessState_0058c2e0();
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
#endif
