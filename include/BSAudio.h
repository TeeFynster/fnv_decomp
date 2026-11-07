#pragma once

#include "BSAudioSyncTimer.h"
#include "BSSoundHandle.h"
#include "NiPoint3.h"
#include "BSSoundHandle.h"

class BSAudioListener;
class BSGameSound;
struct BSSndHStruct;
struct SoundObj;
class NiAVObject;
class BSShaderAccumulator;
class hkMemoryAllocator;
class Allocator;
class InputManager;

namespace weapon_audio
{
    struct NiPoint3;
    struct AudioPlaybackHandle;
}

typedef void (__cdecl* AudioCallback)();
typedef bool (__cdecl* BSAudioSettingsCallback)(int, int*, int*);

class BSAudio
{
  public:
    virtual void vfn_00();
    virtual void vfn_04(unsigned int);
    virtual void vfn_08();
    virtual void vfn_0c(AudioCallback);
    virtual BSAudioSettingsCallback GetPfnB();
    virtual BSGameSound* Create(const char* filename);
    virtual void vfn_18(char*);
    virtual void vf07();

    bool bAudioEnabled;
    bool bInitialized;
    bool bMultiThread;
    unsigned char _pad7[1];
    unsigned int iMusicStartOffset;
    bool bSeekMusic;
    unsigned char _padD[3];
    BSAudioListener* pListener;
    BSAudioSyncTimer SynchTimer;
    void* pfnIDCallback;
    void* pfnNameCallback;
    void* pfnRandomFilenameCallback;
    void* pfnSettingsCallback;
    void* pfnSynchPausedCallback;
    void* pfnSynchUnPausedCallback;

    static BSAudio* GetSingleton();
    static BSAudio* BSAudio_QInstance();
    static BSAudio* GetRandomGenerator();
    static void EnableAudio();
    static void DeactivateAudio();

    void vfn_04();
    const NiPoint3& GetPosition();

    void SetAudioState(unsigned int);
    float GetMusicVolume();
    float GetMasterVolume();
    void SetMasterVolume(float);
    void DisableAudioPlayback();
    void PausePlayback();
    void SetListenerPosition(NiPoint3);
    void SetAudioProperty(unsigned int, unsigned int, unsigned int);
    void Update(bool);
    void SetUseMultipleThreads(bool);
    bool IsAudioEnabled() const;
    bool IsEnabled();
    bool IsPatrolling();

    void Precache(char*, unsigned int);
    void Precache(const char*, unsigned int, void*);
    void ForwardToManager(unsigned int, unsigned int);
    void ForwardToManager(unsigned int, bool);

    BSSoundHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags);
    BSSoundHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags, bool assumeSuccess);
    BSSoundHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags, unsigned int value);
    BSSoundHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags);
    BSSoundHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags, int value);
    BSSoundHandle GetSoundHandleByEditorID(const char* editorID, unsigned int flags, bool value);
    BSSoundHandle GetSoundHandleByFilePath(const char* path, unsigned int flags, void*);
    BSSoundHandle GetSoundHandleByFormID_00ad73b0(unsigned int formID, unsigned int flags);
    BSSoundHandle GetSoundHandleByFormID_00ad73b0(int formID, int flags);
    weapon_audio::NiPoint3 BSAudio_GetListenerPosition();
    weapon_audio::AudioPlaybackHandle BSAudio_GetSoundHandleByFilename(const char* path);
    BSSoundHandle BSAudio_GetSoundHandleByFilename(const char* path, unsigned int flags, unsigned int sound);
    BSSndHStruct BSAudio_GetSoundHandleByFilename(const char* path, unsigned int flags, SoundObj* sound);
    BSSoundHandle BSAudio_GetSoundHandleByEditorName(const char* editorID, unsigned int flags);
    BSSoundHandle BSAudio_SpawnSoundReference(unsigned int formID, unsigned int flags, NiPoint3 position, unsigned int id);

    int GetCurrentTimeMilliseconds();
    unsigned int GetSynchTime();
    void* GetAudioBackendData();
    void (__cdecl* GetCallback())(char*);

    bool TESRegionData_GetPriority();
    void BSAudio_UnPauseWorldVoices();
    void BSAudio_PauseWorldSounds();
    unsigned int FUN_0044ddc0();
    unsigned int Deallocate();
    unsigned int GetFlags();
    InputManager* Main_GetControls();
    BSShaderAccumulator* Main_QDrawWorldAccum();
    void OrientListener(NiPoint3, NiPoint3);
    void SetListenerUnderwater(bool);
    void SetEnvironment(unsigned int);
    void SetEnvironment(int);
    float GetFootVolume();
    float GetVoiceVolume();
    float GetEffectsVolume();
    float GetMusicVolume_00ad7ab0();
    void SetFootstepVolume(float);
    void SetVoiceVolume(float);
    void SetEffectsVolume(float);
    void SetMusicVolume(float);
    void SetRadioVolume(float);
    bool IsListenerUnderwater_00ad7c50();
    float GetMasterSecondaryVolume();
    void SetConditions(float, unsigned int);
    int BSAudioManager_DebugPrintSounds_(unsigned int);
    void FUN_00ad7fa0(const char*, int);
    void Precache_00ad8100(unsigned int, unsigned int, unsigned int);
    void SetAudioThreadModeAndForward(unsigned int);
    void BSAudio_SetCacheEnabled(bool);
    void BSAudio_KillAllOfType(int, bool);
    void BSAudio_PauseAllOfType(int, int);
    void BSAudio_StopMovingSounds(NiAVObject*, float, bool);
    void BSAudio_StopMovingSounds(NiAVObject*, float, unsigned int);
    void EnterDialogue();
    void UnPauseSynchTimer();
    void FUN_00ad8780(int);
    void* FUN_00ad8790(unsigned int flags);

    hkMemoryAllocator& heap();
    Allocator& GetAlloc();
    void Release(void* p, unsigned int size);
};
