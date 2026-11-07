// Declarations specific to the middle-high process variant unit.
#ifndef FNV_MIDDLEHIGHPROCESS_DECLS_H
#define FNV_MIDDLEHIGHPROCESS_DECLS_H

#include "../../../include/Actor.h"

#include "../../../include/BIPED_BONE.h"
class BipedAnim
{
  public:
    NiNode* GetBoneNode(BIPED_BONE);
};

template <>
NiPointer<BSShaderPPLightingProperty>& NiPointer<BSShaderPPLightingProperty>::operator=(BSShaderPPLightingProperty*);

class TESAmmoInitCalls
{
  public:
    void* TESAmmo_GetAmmoEffectList();
};

bool IsValidSandboxProcedure(int aiProcedure);

extern unsigned int(__stdcall* DAT_00fdf1b0)(void*);

#endif
