// Unit-local audio interfaces.
#ifndef FNV_MEDIASET_DECLS_H
#define FNV_MEDIASET_DECLS_H


#include "../../include/BSSoundHandle.h"

#include "../../include/ENUM_FORM_ID.h"
#include "../../include/NiPointer.h"
#include "../../include/NiFile.h"
#include "../../include/TESFile.h"
#include "../../include/MediaLocationController.h"

#include "../../include/MediaSetEntry.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESFullName.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESSound.h"
#include "../../include/MEDIATYPE.h"
class FalloutAudioMedia
{
  public:
    static bool IsMediaPlaying(MEDIATYPE, bool);
    static void FadeOutMedia(int, MEDIATYPE);
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static void EndMediaUpdate();
};
unsigned int FalloutAudioMedia_MediaGetSubDuration(MEDIATYPE);
unsigned int FalloutAudioMedia_MediaGetPosition(MEDIATYPE);
extern unsigned int DAT_011dd37c;

extern unsigned int DAT_011ca9fc;

int Warning(const char* format, ...);

#endif
