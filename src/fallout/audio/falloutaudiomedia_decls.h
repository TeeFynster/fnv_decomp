// fallout/audio/falloutaudiomedia_decls.h: declares FalloutAudioMedia and audio support
#ifndef FALLOUTAUDIOMEDIA_DECLS_H
#define FALLOUTAUDIOMEDIA_DECLS_H


#include "../../../include/MEDIATYPE.h"

unsigned long GetCurrentThreadId();
void FalloutAudioMedia_MediaAccessLeave();

extern char DAT_011dd310;
extern char DAT_011dd311;
extern unsigned char DAT_011dd313;
extern unsigned long DAT_011dd314;
extern unsigned long DAT_011dd334;
extern unsigned long DAT_011dd348;
extern unsigned long DAT_011dd368;
extern float DAT_011dd300;
extern float DAT_011dd304;
extern float DAT_011dd308;
extern unsigned long DAT_011dd328;
extern unsigned long DAT_011dd32c;
extern float DAT_011dd338;
extern float DAT_011dd33c;
extern float DAT_011dd340;
extern unsigned long DAT_011dd35c;
extern unsigned long DAT_011dd360;
class FalloutAudioMedia
{
  public:
    static void BeginMediaUpdate();
    static void EndMediaUpdate();
    static void FadeOutMedia(int, MEDIATYPE);
    static void PlayMedia(BGSMusicType*);
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static char IsRadioPlaying();
    static bool IsMediaPlaying(MEDIATYPE, bool);
    static void Startup();
    static void Update();
};

namespace fnv_anon_falloutaudiomedia {}
using namespace fnv_anon_falloutaudiomedia;
namespace fnv_anon_falloutaudiomedia {
class FAMThread
{
  public:
    char inheritedPadding[0x34];
    unsigned int threadID;
    unsigned int parentID;
    unsigned int state;
    void* event;

    void WaitForThread();
    unsigned int ThreadProc();
};
}

void EnsureArenaAllocated(void*);
void RunAudioChannel(void*);
void DoThreadShutdown(void*);

#endif
