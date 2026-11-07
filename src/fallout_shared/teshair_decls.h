// fallout_shared/teshair_decls.h: declares TESActorBase, TESHairRaceResult, TESHairCanBeNPCData_teshair_decls, TESTextureLoader, TESFileFormInt_teshair_decls
#ifndef FNV_TESHAIR_DECLS_H
#define FNV_TESHAIR_DECLS_H


#include "layout_support.h"
#include "../../include/TESForm.h"

class TESActorBase;
#include "../../include/SEX.h"
#include "../../include/TESActorBase.h"
class BGSQuestObjective;
#include "../../include/BSSimpleList.h"

class TESHairRaceResult
{
  public:
    BSSimpleList<BGSQuestObjective*>* NiAVObject_GetWorldTranslate();
};

// TESHairCanBeNPCData_teshair_decls: local type (was include/TESHairCanBeNPCData.h, which had no evidence of one real class); its methods are 0x004ac110 TESNPC::GetRace
class TESHairRaceResult;

class TESHairCanBeNPCData_teshair_decls
{
public:
    TESHairRaceResult* TESNPC_GetRace();
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};

// TESFileFormInt_teshair_decls: local type (was include/TESFileFormInt.h, which had no evidence of one real class); its methods are 0x00472660 TESFile::GetTESForm
class TESFileFormInt_teshair_decls
{
public:
    int GetTESForm();
};
#endif
