// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MIDDLEHIGHPROCESS_DECLS_H
#define FNV_MIDDLEHIGHPROCESS_DECLS_H
#include "layout_support.h"
#include "../../../include/Actor.h"
#include "ActorPackageContext.h"
#include "MagicTarget.h"
#include "MiddleLowProcess.h"
#include "NiPoint3.h"
#include "layout_support.h"
class Actor;
class TESObjectREFR;
class InventoryStackRecord;
class Animation;
class ArrowProjectile;
class BSAnimGroupSequence;
class BSBound;
class ActorSupportClass;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class FurnitureMark;
class BooleanFloatQuery;
class BipedAnim;
class NiNode;
class LipSyncAnimation;
class MiddleHighProcess;
class MiddleHighProcess__DeferredHideLimb;
class NiAVObject;
class QueuedFile;
class PaddedFloatRecord;
class TESEffectShader;
class TESIdleForm;
class TESObjectWEAP;
class bhkCharacterController;

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

#pragma pack(push, 4)
#include "../../../include/FurnitureMark.h"

#pragma pack(pop)
#pragma pack(push, 4)
#include "../../../include/MiddleHighProcess.h"

#pragma pack(pop)
#endif
