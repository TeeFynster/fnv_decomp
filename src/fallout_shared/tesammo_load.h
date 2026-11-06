// fallout_shared/tesammo_load.h: declares TESFileFormVersion, TESTextureLoader, CombatProcedure, TESRegionGrassObject, BGSImpactData and more

#include "tesammo_decls.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};
class CombatController;
#include "../../include/CombatProcedure.h"
class TESLandTexture;
#include "../../include/TESRegionGrassObject.h"
#include "../../include/BGSImpactData.h"
#include "../../include/EncounterZoneData.h"
class TESAmmoNVEndian
{
  public:
    void SwapEndianFields();
};
class ActorCause;
class ScriptVariableInfo;
