// Unit-local PC header for fallout_shared/bgstalkingactivator.cpp.
//   TESObjectACTI base (144 bytes), m_pTempRef +0x90, m_kFactionList +0x94
//   (152 bytes total).
// TESObject/TESBoundObject/TESBoundAnimObject are scaffolds flattened to
// member, no virtuals). TESMagicTargetForm (1-byte empty base) is omitted;
// the first field lands at +0x74 either way. Only sizes and polymorphism
// matter for this unit's codegen.
// TESSound/BGSVoiceType are minimal polymorphic derivations sufficient for
// the InitItem dynamic_cast and the SNAM/INAM/VNAM setters; their real
// definitions live in other units.
// The TESFormInitFlag / TESFileFormVersion / TESFullNameLoader shims follow
// the accepted bgsacousticspace.cpp / tescasinochips.h / tesrecipe.h
// precedents (canonical TESForm.h / TESFile.h / TESFullName.h do not declare
// other names at the same addresses):
//   TESScriptableForm::SetScript -> 0x006ecd40 (shared bytes with
//   TESModelTextureSwap::LoadTextureSwapChunk -> 0x0048a7b0,
//   BGSDestructibleObjectForm::LoadDestructibleData -> 0x004781e0,
//   BGSTalkingActivator::SetLoopSound -> 0x004febb0 (SNAM, writes +0x74),
//   BGSTalkingActivator::SetRadioTemplate -> 0x004febd0 (INAM, writes +0x7C),
//   BGSTalkingActivator::SetVoiceType -> 0x004febf0 (VNAM, writes +0x94).
#ifndef FNV_BGSTALKINGACTIVATOR_UNIT_H
#define FNV_BGSTALKINGACTIVATOR_UNIT_H

#include "layout_support.h"
#include "bgstalkingactivator_form.h"
#include "../../include/TESFullName.h"

class Script;
class TESObjectREFR;
class TESWaterForm;
class BGSTalkingActivator;

// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it, so
// it is declared on this shim, following the accepted tessound.cpp precedent.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int auiFormID);
};

// TESFile::GetFormVersion is not declared in the bundled TESFile.h; its
// mangled name (TESFileFormVersion::GetFormVersion, 0x00403570) shows the
// canonical declaration site, so it is declared on this shim, following the
// accepted tescasinochips.h precedent.
struct TESFileFormVersion : public TESFile
{
    unsigned short GetFormVersion();
};

// TESFullName::LoadFullNameChunk is not declared in the bundled TESFullName.h;
// declared here on a shim following the accepted tesrecipe.h precedent.

#include "../../include/TESSound.h"
#include "../../include/BGSVoiceType.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSOpenCloseForm.h"
#include "../../include/TESObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESObjectACTI.h"

int Warning(const char* apFormat, ...);

#include "../../include/BGSTalkingActivator.h"
#endif
