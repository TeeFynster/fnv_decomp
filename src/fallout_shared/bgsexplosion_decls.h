// fallout_shared/bgsexplosion_decls.h: declares TESFormInitFlag, TESObjectLIGH, CombatProcedure, BGSImpactData, EndianConvertibleData and more
#ifndef FNV_BGSEXPLOSION_DECLS_H
#define FNV_BGSEXPLOSION_DECLS_H

#include "layout_support.h"
#include "../../include/TESForm.h"

struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};

#include "../../include/TESObjectLIGH.h"
class TESFileChunkData16
{
  public:
    bool GetChunkData(unsigned short* data);
};

class CombatController;
#include "../../include/CombatProcedure.h"
#include "../../include/BGSImpactData.h"
#include "../../include/EndianConvertibleData.h"
#include "../../include/TESSound.h"
#include "../../include/BGSImpactDataSet.h"
#include "../../include/EffectSetting.h"
class MagicItem;

#include "../../include/MagicCaster.h"
#include "../../include/PlayerMover.h"
int Warning(const char* format, ...);
#endif
