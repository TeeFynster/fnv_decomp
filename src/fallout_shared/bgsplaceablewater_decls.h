// fallout_shared/bgsplaceablewater_decls.h: declares TESWaterForm, BGSImpactData, TESFileFormVersion, TESFileGetChunkData
#ifndef FNV_BGSPLACEABLEWATER_DECLS_H
#define FNV_BGSPLACEABLEWATER_DECLS_H


#include "layout_support.h"
#include "../../include/TESForm.h"

#include "../../include/TESWaterForm.h"
#include "../../include/BGSImpactData.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};

class TESFileGetChunkData : public TESFile
{
  public:
    bool GetChunkData();
};

extern TESWaterForm* DAT_011ca53c;
TESForm* GetFormByID(unsigned int formID);

#endif
