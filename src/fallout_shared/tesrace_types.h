// Private helpers used only by TESRace.
#ifndef FNV_TESRACE_TYPES_H
#define FNV_TESRACE_TYPES_H

#include <stddef.h>
#include "../../include/BSStringT.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#undef FNV64_NIPOINTER_INLINE_BODIES

class NiTexture;
class NiSourceTexture;
class BSFaceGenModel;
// This /Od unit uses the game's out-of-line smart-pointer instantiations.
template <> NiPointer<NiTexture>::NiPointer(NiTexture*);
template <> NiPointer<NiTexture>::~NiPointer();
template <> NiPointer<NiTexture>::operator NiTexture*() const;
template <> NiPointer<NiTexture>& NiPointer<NiTexture>::operator=(NiTexture*);
template <> bool NiPointer<NiTexture>::operator==(NiTexture*) const;
// BSFaceGenModel uses the out-of-line API declared by its class specialization in NiPointer.h.
template <> NiPointer<NiSourceTexture>::operator NiSourceTexture*() const;
template <> NiPointer<NiSourceTexture>& NiPointer<NiSourceTexture>::operator=(NiSourceTexture*);

#include "../../include/BSSimpleList.h"
#include "../../include/ENUM_FORM_ID.h"

#include "../../include/BGSTextureModel.h"
#include "../../include/BGSVoiceType.h"
#include "../../include/BSFaceGenModelMap.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/FileEntryList.h"
#include "../../include/PlayerCharacter.h"

#include "../../include/SETTING_VALUE.h"
#include "../../include/TESActorBase.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESDescription.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESHair.h"
#include "../../include/TESModel.h"
#include "../../include/TESNPC.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/NiTexturingProperty.h"
#include "../../include/TESReactionForm.h"
#include "../../include/TESSpellList.h"
#include "../../include/TESTexture.h"
#include "../../include/BIPED_OBJECT.h"
class TESEyes;
class SpellItem;
class TESLevSpell;
class BSFileEntry;
class FaceGenUndo;

#include "../../include/SEX.h"

extern BGSVoiceType* g_pDefaultMaleVoiceType;
extern BGSVoiceType* g_pDefaultFemaleVoiceType;
int __cdecl Warning(const char*, ...);

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
int __cdecl NormalizePartIndex(BIPED_OBJECT);
class TESBoundObject;

extern PlayerCharacter* g_thePlayer;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int __cdecl strcat_s(char*, unsigned int, const char*);
char* __cdecl strrchr_0040ab30(char*, int);
extern "C" const char* __cdecl strrchr(const char*, int);
#endif
