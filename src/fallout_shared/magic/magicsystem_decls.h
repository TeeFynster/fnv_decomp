// Declarations used by fallout_shared/magic/magicsystem.cpp.
#ifndef FNV_MAGICSYSTEM_DECLS_H
#define FNV_MAGICSYSTEM_DECLS_H

#include "../../../include/AutoMemContext.h"
#include "../../../include/EffectItemList.h"
#include "../../../include/EffectShaderData.h"
#include "../../../include/MagicItem.h"
#include "../../../include/MagicItemForm.h"
#include "../../../include/SpellItem.h"
#include "../../../include/TESBoundAnimObject.h"
#include "../../../include/TESEffectShader.h"
#include "../../../include/TESSound.h"
#include "../../../include/TESSoundFile.h"
#include "../../../include/TESSound__SOUND_DATA.h"
#include <new>

#include "../../../include/ENUM_FORM_ID.h"
#include "../../../include/MEM_CONTEXT.h"

namespace MagicSystem
{
    void InitializeMagicSystem();
}
class EffectSettingCollection
{
  public:
    static void InitializeEffectSettings();
};

// The three data-handler list accessors have no consistent named identity
// in the identity table or sym/xref evidence.
class DataHandler
{
  public:
    BSSimpleList<TESSound*>* hkpMotion_getLinearVelocity();
    BSSimpleList<TESEffectShader*>* TESDataHandler_GetEffectShaders();
    BSSimpleList<SpellItem*>* FUN_0087eaa0();
};
extern DataHandler* g_dataHandler;
TESForm* GetFormByID(unsigned int formID);

extern TESSound* DAT_011c3538;
extern TESSound* DAT_011c353c;
extern TESSound* DAT_011c3540;
extern TESSound* DAT_011c3544;
extern TESSound* DAT_011c3548;
extern TESSound* DAT_011c354c;
extern TESSound* DAT_011c3550;
extern TESSound* DAT_011c3554;
extern TESSound* DAT_011c3558;
extern TESSound* DAT_011c355c;
extern TESSound* DAT_011c3560;
extern TESSound* DAT_011c3564;
extern TESSound* DAT_011c3568;
extern TESSound* DAT_011c356c;
extern TESSound* DAT_011c3570;
extern TESSound* DAT_011c3574;
extern TESSound* DAT_011c3578;
extern TESSound* DAT_011c357c;
extern TESEffectShader* DAT_011c3580;
extern TESEffectShader* DAT_011c3584;
extern TESEffectShader* DAT_011c3588;
extern SpellItem* DAT_011c358c;
#endif
