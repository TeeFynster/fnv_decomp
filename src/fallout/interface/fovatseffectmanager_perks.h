// fallout/interface/fovatseffectmanager_perks.h: declares BGSPerkEntry, BGSEntryPointFunction, EntryPointFunctionDispatcher, EntryPoint
#include "../../../include/BGSPerkEntry.h"
#ifndef FNV_FOVATSEFFECTMANAGER_PERKS_H
#define FNV_FOVATSEFFECTMANAGER_PERKS_H

#include "Actor.h"
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
class BGSEntryPointFunction
{
  public:
    enum ENTRY_POINT_FUNCTION_TYPE
    {
        FUNCTION_TYPE_NONE = 0
    };
    enum ENTRY_POINT_FUNCTION
    {
        FUNCTION_NONE = 0
    };
    static unsigned char GetArgumentCount(ENTRY_POINT_FUNCTION_TYPE type);
    static void ApplyFunction(ENTRY_POINT_FUNCTION function, TESObjectREFR* actor, ENTRY_POINT_FUNCTION_TYPE type,
                              unsigned char count, void** arguments, void* data);
};
class EntryPointFunctionDispatcher
{
  public:
    struct EntryPoint
    {
        const char* name;
        unsigned char filterCount;
        unsigned char padding[7];
        unsigned char functionType;
        unsigned char tail[3];
    };
    static EntryPoint ms_kEntryPointTable[74];
};
extern const char g_entryPointArgumentErrorFormat[];
extern const char g_entryPointFilterParameterName[];
extern const char g_entryPointFunctionArgumentName[];
int Warning(const char*, ...);
#endif
