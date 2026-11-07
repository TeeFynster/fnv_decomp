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
    bool BSAudioManager_Release(unsigned int);
    void BSAudioManager_Precache(char*, unsigned int);
    void Precache_00add630(unsigned int, unsigned int);
    void BSAudioManager_Precache_00add6f0(unsigned int, unsigned int, unsigned int);
    void StartAudioThread();
    void SetConditions_00ada300(float, unsigned int);
    void BSAudioManager_SetListenerUnderwater(bool);
    void BSAudioManager_SetCompletionCallback(unsigned int, BSSoundHandle::CompletionCallback, void*);
    bool BSAudioManager_PlayAfter(unsigned int, unsigned int, int);
    void BSAudioManager_KillAllOfType(void*, void*);
    void BSAudio_KillAllOfType(void*, void*);
    void BSAudioManager_StopMovingSounds(int, float, int);
    void BSAudioManager_FadeInPlay(int, int);
    void AudioMessageStack_Pop();
    SoundMessageRecord* GetFreeQueueMessage();
    bool __thiscall ProcessMessage_00adf080(SoundMessageRecord*);
    void __thiscall BSAudioManager_ComposeMessage(int, unsigned int, int, unsigned int, NiPointer<NiAVObject>, NiPoint3);
    BSGameSound* __thiscall BSAudioManager_GetFromCache(void*, void*, unsigned int);
    void __thiscall BSAudioManager_Precache_00add960(BSGameSound*);
    void __thiscall BSAudioManager_SetVoiceState(unsigned int, BSGameSound*);
    bool __thiscall HasMatchingEntry(unsigned int);
    bool __thiscall AddSlot(void*, bool);
    bool __thiscall ClearPausedType(int, unsigned char);
    void __thiscall BSAudioManager_SetAttenuationCurve(unsigned int, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void __thiscall AddSound(BSGameSound*);

    void InitAudioVolumes();
    void InitUISounds(bool);
    void SetAudioCacheSize(int);
    void ProcessAudioQueue();
    void BSAudioManager_Initialize();
    void BSAudioManager_Shutdown();
    void BSAudioManager_SuspendAudioThread();
    void BSAudioManager_StopAudioThread();
    void BSAudioManager_SynchVoiceStates();
    float GetVolumeValue(float, unsigned int);
    void BSAudioManager_FreeMessage(SoundMessageRecord*);
    void BSAudioManager_FreeMessage(int);
    void BSAudioManager_QueueMessage(SoundMessageRecord*);
    bool BSAudioManager_Play(unsigned int, bool);
    bool BSAudioManager_Pause(unsigned int);
    bool BSAudioManager_Pause(int);
    bool BSAudioManager_Stop(unsigned int);
    bool BSAudioManager_Stop(int);
    void BSAudioManager_StopMovingSounds(NiRefObject*, float, int);
    bool BSAudioManager_SetStaticAttenuation(unsigned int, unsigned short);
    bool BSAudioManager_SetFrequency(unsigned int, float);
    bool BSAudioManager_SetModFrequency(int, float);
    bool BSAudioManager_SetFrequencyVariance(unsigned int, bool);
    bool BSAudioManager_SetFrequencyVariance(int, bool);
    bool BSAudioManager_SetBalance(int, int);
    bool BSAudioManager_SetBalance(unsigned int, unsigned int);
    bool BSAudioManager_SetPosition(unsigned int, float, float, float);
    bool BSAudioManager_SetPosition(int, float, float, float);
    bool BSAudioManager_SetBeamEnd(unsigned int, float, float, float);
    void BSAudioManager_SetMinMaxDistance(unsigned int, float, float);
    void BSAudioManager_SetMinMaxDistance(int, float, float);
    void BSAudioManager_SetReverbAttenuation(int, int);
    void BSAudioManager_SetReverbAttenuation(int, unsigned short);
    bool BSAudioManager_SetOrientation(float, float, float, float);
    bool BSAudioManager_SetOrientation(unsigned int, float, float, float);
    void BSAudioManager_SetPlayCallback(unsigned int, void (__cdecl*)(void*, unsigned int), void*);
    bool BSAudioManager_SetPlayCallback(int, int, int);
    bool BSAudioManager_SetVolume(int, float);
    void BSAudioManager_SetRadioVolume();
    void BSAudioManager_SetObjectToFollow(unsigned int, NiAVObject*);
    void BSAudioManager_SetObjectToFollow(int, NiRefObject*);
    void BSAudioManager_Seek(unsigned int, unsigned int);
    void BSAudioManager_Seek(int, int);
    void BSAudioManager_SetAtListener(unsigned int, unsigned char);
    void BSAudioManager_SetAtListener(int, bool);
    void BSAudioManager_SetSynchStartTime(unsigned int, unsigned int);
    void BSAudioManager_SetSynchStartTime(int, int);
    void BSAudioManager_ClearSynchStartTime(unsigned int);
    void BSAudioManager_ClearSynchStartTime(int);
    void BSAudioManager_SetPriority(unsigned int, unsigned int);
    void BSAudioManager_SetPriority(int, int);
    void BSAudioManager_SetTimeConstraints(unsigned int, unsigned char, unsigned char);
    void BSAudioManager_SetTimeConstraints(int, bool, bool);
    void BSAudioManager_FadeOut(int, int, unsigned int);
    void BSAudioManager_FadeIn(int, int, int);
    bool ContainsKey(unsigned int);
    int BSAudioManager_GetDuration(unsigned int);
    float BSAudioManager_GetVolume(unsigned long);
    float BSAudioManager_GetVolume(unsigned int);
    bool BSAudioManager_IsPlaying(unsigned int);
    int BSAudioManager_GetSoundType(unsigned long);
    int BSAudioManager_GetSoundType(unsigned int);
    void BSAudioManager_MuteAllOfType(int, int, int);
    void BSAudioManager_UnMuteAllOfType(int, int);
    void BSAudioManager_PauseAllOfType(int, bool);
    void BSAudioManager_UnPauseAllOfType(int, int);
    void BSAudioManager_KillAllOfType(int, int);
    bool BSAudioManager_IsInCache(int, bool);
    bool BSAudioManager_IsInCache(unsigned int, bool);
    void BSAudioManager_Precache(const char*, unsigned int);
    void BSAudioManager_Precache_00add6f0(const char*, unsigned int, unsigned int);
    void BSAudioManager_Precache_00add6f0(const char*, int, int);
    void BSAudioManager_Process();
    void BSAudioManager_ProcessSoundUpdates();
    void BSAudioManager_UpdateMovingSounds();
    void BSAudioManager_PositionListener(NiPoint3);
    BSSoundHandle BSAudioManager_InitSoundForm(unsigned int, unsigned int);
    int BSAudioManager_DebugPrintSounds(unsigned int);
    int _BSAudioManager_AudioCacheSize();
    void BSAudioManager_SetCacheEnabled(bool);
    void BSAudioManager_SetCacheEnabled(int);
    bool BSAudioManager_IsEnableAudioCache();
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(void*);
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove(int);
    void NiTPointerListBase_NiTPointerAllocator_unsigned_int_ShadowSceneLight_Remove();
    void AddSound(int);

    __forceinline unsigned int GetNextID()
    {
        return iNextID++;
    }
};
