// Unit-local header for fallout_shared/tescasinochips.cpp.
// Class layouts (TESObject through TESCasinoChips) are copied verbatim from
// canonical); EndianConvertibleData and TESCasino are copied verbatim from
// comments).
#ifndef FNV_TESCASINOCHIPS_PACKET_H
#define FNV_TESCASINOCHIPS_PACKET_H

class TESFile;
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"

#include "../../include/TESFullName.h"
#include "TESIcon.h"
#include "../../include/TESTexture.h"
#include "layout_support.h"
#include "../../include/BGSImpactData.h"
// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it yet,
// so it is declared on this shim, following the accepted TESFileFormInt
// precedent in tessound.cpp.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};
// TESFile::GetFormVersion is not declared in the bundled TESFile.h; its
// mangled name (TESFileFormVersion::GetFormVersion, 0x00403570) shows the
// canonical declaration site, so it is declared on this shim.
struct TESFileFormVersion : public TESFile
{
    unsigned short GetFormVersion();
};
// TESFullName::LoadFullNameChunk is not declared in the bundled TESFullName.h;
// declared here on a shim following the accepted TESRecipe precedent.

// TESTexture::ReadTextureData is not declared in the bundled TESTexture.h;
// declared here on a shim following the TESFullNameLoader precedent.
struct TESTextureLoader : public TESTexture
{
    static void ReadTextureData(TESTexture* apTexture, TESFile* apFile);
};
class BGSDestructibleObjectForm;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESCasinoChips;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class TESValueForm;
class DistantTreeTextureInfo;
#include "../../include/TESObject.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESBoundObject.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/TESValueForm.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/TESCasinoChips.h"
// TESModel and TESModelTextureSwap are already defined above and are not
// repeated. Real method declarations used by this unit are added.
#include "../../include/EndianConvertibleData.h"
#include "../../include/TESCasino.h"
#endif
