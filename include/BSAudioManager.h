#pragma once

#include "BSSoundHandle.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

template <class T> class NiPointer;

class BSAudioManagerThread;
class BSGameSound;
class NiAVObject;
class NiRefObject;
class SoundMessageRecord;

enum SOUND_MSG
{
    SOUND_MSG_ENTER_DIALOGUE = 13
};

class BSAudioManager
{
public:
    BSAudioManager();
    virtual ~BSAudioManager();

    int iMessageListIndex;
    int iMessageProcessingListIndex;
    unsigned char Messages[24];
    unsigned char FreeMessages[16];
    unsigned char FreeQueueMessages[16];
    unsigned char GarbageMessages[16];
    unsigned char SoundList[16];
    unsigned char SoundStateMap[16];
    unsigned char StateUpdateMap[16];
    unsigned char MovingRefrList[16];
    unsigned char CachedSoundList[12];
    unsigned int iCurrentCachSize;
    unsigned int iWeatherFlags;
    float fCurrentGamehour;
    unsigned char MessageCritSection[24];
    unsigned char StateCritSection[24];
    unsigned char CacheCritSection[24];
    unsigned char ProcessingCritSection[24];
    unsigned char CacheLoadTaskCritSection[24];
    unsigned char CacheLoadTaskList[12];
    unsigned int iDelayTimerDelta;
    bool bPrecacheCompleted;
    bool bListenerMoved;
    unsigned char _pad136[2];
    unsigned long dwAudioThreadID;
    BSAudioManagerThread* pUpdateThread;
    float fMasterVolume;
    float fFootVolume;
    float fVoiceVolume;
    float fEffectsVolume;
    float fMusicVolume;
    float fRadioVolume;
    float fMasterSecondaryVolume;
    float fFootSecondaryVolume;
    float fVoiceSecondaryVolume;
    float fEffectsSecondaryVolume;
    float fMusicSecondaryVolume;
    float fRadioSecondaryVolume;
    unsigned int iMuteMask;
    bool bDialogueFade;
    bool bListenerUnderwater;
    unsigned char _pad176[2];
    void* pPauseEntries;
    unsigned int iPauseListSize;
    unsigned int iNextID;
    bool bIgnoreGlobalTimeMultiplier;
    unsigned char _pad185[3];

    static BSAudioManager& __cdecl GetRandomGenerator();
    void DisableAudioPlayback(unsigned int, bool);
    void SetAudioSettingValue(unsigned int, unsigned int, unsigned int);
    void SetListenerPosition(NiPoint3);
    void Update(bool);
    void StartAudioThreads();
    void StopAudioThreads();
    bool IsPlaying(unsigned int);
    void SetPlaybackTime(unsigned int, unsigned int, unsigned int);
    bool SetPlaybackFrequency(unsigned int, float);
    bool IsSoundPlaying(unsigned int);
    BSSoundHandle FindSoundHandleByPath(const char* path, unsigned int flags, void* sound);
    BSSoundHandle GetSoundHandleByFilePath(const char* path, unsigned int flags, void* sound);
    void SendSoundMessage(SOUND_MSG, unsigned int, int, void*, NiPointer<NiAVObject>, NiPoint3);
    bool FUN_00adbf50(unsigned int);
    void FUN_00add570(char*, unsigned int);
    void FUN_00add630(unsigned int, unsigned int);
    void FUN_00add6f0(unsigned int, unsigned int, unsigned int);
    void FUN_00ad9f30();
    void FUN_00ada300(float, unsigned int);
    void FUN_00adeff0(bool);
    void FUN_00adbfd0(unsigned int, BSSoundHandle::CompletionCallback, void*);
    bool FUN_00adb4e0(unsigned int, unsigned int, int);
    void FUN_00adcd00(void*, void*);
    void FUN_00ad84e0(void*, void*);
    void FUN_00adb690(int, float, int);
    void FUN_00adc670(int, int);
    void FUN_00adad60();
    SoundMessageRecord* FUN_00adaf80();
    bool __thiscall FUN_00adf080(SoundMessageRecord*);
    void __thiscall FUN_00adb1a0(int, unsigned int, int, unsigned int, NiPointer<NiAVObject>, NiPoint3);
    BSGameSound* __thiscall FUN_00add1e0(void*, void*, unsigned int);
    void __thiscall FUN_00add960(BSGameSound*);
    void __thiscall FUN_00ada5d0(unsigned int, BSGameSound*);
    bool __thiscall HasMatchingEntry(unsigned int);
    bool __thiscall AddSlot(void*, bool);
    bool __thiscall FUN_00ae6e60(int, unsigned char);
    void __thiscall FUN_00adbb30(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void __thiscall AddSound(BSGameSound*);

    void InitAudioVolumes();
    void InitUISounds(bool);
    void SetAudioCacheSize(int);
    void ProcessAudioQueue();
    void FUN_00ad9640();
    void FUN_00ad9870();
    void FUN_00ada020();
    void FUN_00ada0f0();
    void FUN_00ada330();
    float FUN_00adac30(float, unsigned int);
    void FUN_00adad80(SoundMessageRecord*);
    void FUN_00adad80(int);
    void FUN_00adafa0(SoundMessageRecord*);
    bool FUN_00adb3e0(unsigned int, bool);
    bool FUN_00adb590(unsigned int);
    bool FUN_00adb590(int);
    bool FUN_00adb610(unsigned int);
    bool FUN_00adb610(int);
    void FUN_00adb690(NiRefObject*, float, int);
    bool FUN_00adb720(unsigned int, unsigned short);
    bool FUN_00adb7c0(unsigned int, float);
    bool FUN_00adb850(int, float);
    bool FUN_00adb8e0(unsigned int, bool);
    bool FUN_00adb8e0(int, bool);
    bool FUN_00adb960(int, int);
    bool FUN_00adb960(unsigned int, unsigned int);
    bool FUN_00adb970(unsigned int, float, float, float);
    bool FUN_00adb970(int, float, float, float);
    bool FUN_00adb9f0(unsigned int, float, float, float);
    void FUN_00adba70(unsigned int, float, float);
    void FUN_00adba70(int, float, float);
    void FUN_00adbec0(int, int);
    void FUN_00adbec0(int, unsigned short);
    bool FUN_00adbf40(float, float, float, float);
    bool FUN_00adbf40(unsigned int, float, float, float);
    void FUN_00adc050(unsigned int, void (__cdecl*)(void*, unsigned int), void*);
    bool FUN_00adc050(int, int, int);
    bool FUN_00adc0d0(int, float);
    void FUN_00adc160();
    void FUN_00adc1e0(unsigned int, NiAVObject*);
    void FUN_00adc1e0(int, NiRefObject*);
    void FUN_00adc260(unsigned int, unsigned int);
    void FUN_00adc260(int, int);
    void FUN_00adc2e0(unsigned int, unsigned char);
    void FUN_00adc2e0(int, bool);
    void FUN_00adc360(unsigned int, unsigned int);
    void FUN_00adc360(int, int);
    void FUN_00adc3e0(unsigned int);
    void FUN_00adc3e0(int);
    void FUN_00adc460(unsigned int, unsigned int);
    void FUN_00adc460(int, int);
    void FUN_00adc4e0(unsigned int, unsigned char, unsigned char);
    void FUN_00adc4e0(int, bool, bool);
    void FUN_00adc560(int, int, unsigned int);
    void FUN_00adc5f0(int, int, int);
    bool ContainsKey(unsigned int);
    int FUN_00adc830(unsigned int);
    float FUN_00adc8b0(unsigned long);
    float FUN_00adc8b0(unsigned int);
    bool FUN_00adc910(unsigned int);
    int FUN_00adc9a0(unsigned long);
    int FUN_00adc9a0(unsigned int);
    void FUN_00adca20(int, int, int);
    void FUN_00adcaa0(int, int);
    void FUN_00adcb20(int, bool);
    void FUN_00adcc10(int, int);
    void FUN_00adcd00(int, int);
    bool FUN_00add480(int, bool);
    bool FUN_00add480(unsigned int, bool);
    void FUN_00add570(const char*, unsigned int);
    void FUN_00add6f0(const char*, unsigned int, unsigned int);
    void FUN_00add6f0(const char*, int, int);
    void FUN_00addc00();
    void FUN_00adddd0();
    void FUN_00adea90();
    void FUN_00adef80(NiPoint3);
    BSSoundHandle FUN_00ae5870(unsigned int, unsigned int);
    int FUN_00ae5ff0(unsigned int);
    int FUN_00ae6c60();
    void FUN_00ae6ca0(bool);
    void FUN_00ae6ca0(int);
    bool FUN_00ae6cf0();
    void FUN_00ae6f10(void*);
    void FUN_00ae6f10(int);
    void FUN_00ae6f10();
    void AddSound(int);

    __forceinline unsigned int GetNextID()
    {
        return iNextID++;
    }
};
