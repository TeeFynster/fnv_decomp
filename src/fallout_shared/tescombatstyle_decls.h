// fallout_shared/tescombatstyle_decls.h: shared combat-style types and local helpers

#include "layout_support.h"
#include "../../include/BGSHungerStage.h"
#include "../../include/StatsChunkData.h"
#include "../../include/TESCombatStyle.h"
#include "../../include/UInt32ChunkData.h"
#include "../../include/UnsignedIntArray16.h"
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl memset(void*, int, unsigned int);
TESCombatStyle* TESCombatStyle_GetDefaultCombatStyle();
StatsChunkData& __fastcall GetCombatStyleData(TESCombatStyle* style);
HungerStageData* __fastcall GetHungerStageData(BGSHungerStage* stage);
UInt32ChunkData* __fastcall GetCombatStyleAdvancedData(TESCombatStyle* style);
void __fastcall SwapUInt32ChunkData(UInt32ChunkData* data);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFileExtra
{
  public:
    bool FUN_00401680();
};
