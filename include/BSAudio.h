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
    static BSAudio* FUN_00453a70();
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
    BSSoundHandle FUN_00ad73b0(unsigned int formID, unsigned int flags);
    BSSoundHandle FUN_00ad73b0(int formID, int flags);
    weapon_audio::NiPoint3 FUN_00ad78e0();
    weapon_audio::AudioPlaybackHandle FUN_00ad7480(const char* path);
    BSSoundHandle FUN_00ad7480(const char* path, unsigned int flags, unsigned int sound);
    BSSndHStruct FUN_00ad7480(const char* path, unsigned int flags, SoundObj* sound);
    BSSoundHandle FUN_00ad7550(const char* editorID, unsigned int flags);
    BSSoundHandle FUN_00ad7620(unsigned int formID, unsigned int flags, NiPoint3 position, unsigned int id);

    int GetCurrentTimeMilliseconds();
    unsigned int GetSynchTime();
    void* GetAudioBackendData();
    void (__cdecl* GetCallback())(char*);

    bool FUN_005bb4d0();
    void FUN_0070bc00();
    void FUN_007eb8a0();
    unsigned int FUN_0044ddc0();
    unsigned int Deallocate();
    unsigned int GetFlags();
    InputManager* FUN_00877720();
    BSShaderAccumulator* FUN_004e2190();
    void FUN_00ad7940(NiPoint3, NiPoint3);
    void FUN_00ad7990(bool);
    void FUN_00ad79b0(unsigned int);
    void FUN_00ad79b0(int);
    float FUN_00ad7a20();
    float FUN_00ad7a50();
    float FUN_00ad7a80();
    float FUN_00ad7ab0();
    void FUN_00ad7b40(float);
    void FUN_00ad7b70(float);
    void FUN_00ad7ba0(float);
    void FUN_00ad7bd0(float);
    void FUN_00ad7c00(float);
    bool FUN_00ad7c50();
    float FUN_00ad7c80();
    void FUN_00ad77f0(float, unsigned int);
    int FUN_00ad7ee0(unsigned int);
    void FUN_00ad7fa0(const char*, int);
    void FUN_00ad8100(unsigned int, unsigned int, unsigned int);
    void SetAudioThreadModeAndForward(unsigned int);
    void FUN_00ad8320(bool);
    void FUN_00ad84e0(int, bool);
    void FUN_00ad8510(int, int);
    void FUN_00ad8570(NiAVObject*, float, bool);
    void FUN_00ad8570(NiAVObject*, float, unsigned int);
    void FUN_00ad85a0();
    void FUN_00ad8740();
    void FUN_00ad8780(int);
    void* FUN_00ad8790(unsigned int flags);

    hkMemoryAllocator& heap();
    Allocator& GetAlloc();
    void Release(void* p, unsigned int size);
};
