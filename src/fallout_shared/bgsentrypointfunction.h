#ifndef FNV_BGSENTRYPOINTFUNCTION_UNIT_H
#define FNV_BGSENTRYPOINTFUNCTION_UNIT_H
#include "bgsentrypointfunction_decls.h"
// @fnv 0x005e6c30
void BGSEntryPointFunctionDataActivateChoice::InitializeComponent()
{
    flags = 0;
    static_cast<TESForm*>(&resultScript)->SetInitializationState(false);
    static_cast<TESForm*>(&resultScript)->NotifySaveLoadGameOfFormChange();
}
#endif
