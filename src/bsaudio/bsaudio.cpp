// bsaudio/bsaudio.cpp: audio forwarding and playback handles

#include "bsaudio_decls.h"
#include "../../include/BSAudio.h"
#include "../../include/BSAudioListener.h"
#include "../../include/BSAudioManager.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/AutoMemContext.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiObject.h"
#include "../../include/NiFixedString.h"
#include "../../include/Tile.h"
#include "../../include/TESResponse.h"

struct TLSPad_00ad7740
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSPad_00ad7740 g_tls_00ad7740;

__forceinline AutoMemContext::AutoMemContext(int context)
{
    int previous = g_tls_00ad7740.memContext;
    m_eMemoryContext = static_cast<MEM_CONTEXT>(previous);
    g_tls_00ad7740.memContext = context;
}

__forceinline AutoMemContext::~AutoMemContext()
{
    int previous = m_eMemoryContext;
    g_tls_00ad7740.memContext = previous;
}

inline BSSoundHandle::BSSoundHandle(const BSSoundHandle& rhs)
    : iSoundID(rhs.iSoundID), bAssumeSuccess(rhs.bAssumeSuccess), eState(rhs.eState)
{}

inline BSSoundHandle::~BSSoundHandle()
{}

// @fnv 0x00ad8780
void BSAudio::SetAudioState(unsigned int argument0)
{}

// @fnv 0x00762150
void BSAudio::EnableAudio()
{
    DAT_011dcfa4 = 1;
}

// @fnv 0x007624c0
void BSAudio::DeactivateAudio()
{
    DAT_011dcfa4 = 0;
}

// @fnv 0x007ec380
void BSAudio::DisableAudioPlayback()
{
    reinterpret_cast<BSAudioManager*>(this)->DisableAudioPlayback(0x3002, false);
}

// @fnv 0x00ad7ae0
float BSAudio::GetMusicVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fRadioVolume;
    return volume;
}

// @fnv 0x00ad8480
void BSAudio::SetAudioProperty(unsigned int type, unsigned int flags, unsigned int value)
{
    BSAudioManager::GetRandomGenerator().SetAudioSettingValue(type, flags, value);
}

// @fnv 0x00ad78b0
void BSAudio::SetListenerPosition(NiPoint3 position)
{
    BSAudioManager::GetRandomGenerator().SetListenerPosition(position);
}

// @fnv 0x00ad8d10
bool BSSoundHandle::Release()
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }

    bool released = BSAudioManager::GetRandomGenerator().BSAudioManager_Release(iSoundID);
    if (released)
    {
        iSoundID = 0xffffffff;
    }
    return released;
}

// @fnv 0x00ad79f0
float BSAudio::GetMasterVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMasterVolume;
    return volume;
}

// @fnv 0x00ad7a20
// src: COMMUNITY 0x00ad7a20
float BSAudio::GetFootVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fFootVolume;
    return volume;
}

// @fnv 0x00ad7a50
// src: COMMUNITY 0x00ad7a50
float BSAudio::GetVoiceVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fVoiceVolume;
    return volume;
}

// @fnv 0x00ad7a80
// src: COMMUNITY 0x00ad7a80
float BSAudio::GetEffectsVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fEffectsVolume;
    return volume;
}

// @fnv 0x00ad7ab0
// src: COMMUNITY 0x00ad7ab0
float BSAudio::GetMusicVolume_00ad7ab0()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMusicVolume;
    return volume;
}

// @fnv 0x00ad7c80
// src: COMMUNITY 0x00ad7c80
float BSAudio::GetMasterSecondaryVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMasterSecondaryVolume;
    return volume;
}

inline bool IsListenerUnderwater(BSAudioManager* manager)
{
    return manager->bListenerUnderwater;
}

// @fnv 0x00ad7c50
// src: COMMUNITY 0x00ad7c50
bool BSAudio::IsListenerUnderwater_00ad7c50()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    return IsListenerUnderwater(manager);
}

// @fnv 0x00ad7990
// src: COMMUNITY 0x00ad7990
void BSAudio::SetListenerUnderwater(bool value)
{
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetListenerUnderwater(value);
}

// @fnv 0x00ad7940
// src: COMMUNITY 0x00ad7940
void BSAudio::OrientListener(NiPoint3 front, NiPoint3 top)
{
    if (*reinterpret_cast<const NiPointer<BSAudioListener>*>(&pListener))
        (*reinterpret_cast<const NiPointer<BSAudioListener>*>(&pListener))->vfn_14(&front, &top);
}

// Calls the synchronization callback, then clears bit 0 of the synchronization flags.
// @fnv 0x00ad8740
// src: XBOX_PDB 0x00ad8740
void BSAudio::UnPauseSynchTimer()
{
    if (*reinterpret_cast<void (**)()>(reinterpret_cast<char*>(this) + 0x34))
    {
        (*reinterpret_cast<void (**)()>(reinterpret_cast<char*>(this) + 0x34))();
    }
    char* p = reinterpret_cast<char*>(this) + 0x14;
    *reinterpret_cast<unsigned int*>(p + 8) &= ~1u;
}

// Sets the thread-local memory context to 0xb for the duration of the call, then forwards abFlag to BSAudioManager::Update.
// @fnv 0x00ad7740
void BSAudio::Update(bool abFlag)
{
    AutoMemContext guard(0xb);
    BSAudioManager::GetRandomGenerator().Update(abFlag);
}

// @fnv 0x00ad7fa0
void BSAudio::Precache(char* apName, unsigned int aiFlag)
{
    AutoMemContext guard(0xb);
    BSAudioManager::GetRandomGenerator().BSAudioManager_Precache(apName, aiFlag);
}

struct FUN_0083b8d0_stub
{
    void FUN_0083b8d0();
};
struct FUN_00798450_shell
{
    void* FUN_00798450(unsigned int flags);
};
// Calls FUN_0083b8d0 on this, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x00798450
void* FUN_00798450_shell::FUN_00798450(unsigned int flags)
{
    ((FUN_0083b8d0_stub*)this)->FUN_0083b8d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void* __cdecl InterfaceManager_GetSingleton();
extern int DAT_011da9a4;
// If DAT_011da9a4 is set, stores 7 at offset 0x28 and calls Set(0xfa9, 255.0f, true) on the next TESResponse tile.
// @fnv 0x007c2420
// src: COMMUNITY 0x007c2420
void SlotMachineMenu_SetShouldExit()
{
    if (DAT_011da9a4)
    {
        *(int*)(DAT_011da9a4 + 0x28) = 7;
        ((Tile*)((TESResponse*)InterfaceManager_GetSingleton())->GetNext())->Set(0xfa9, 255.0f, true);
    }
}

struct FUN_00aa4a50_shell2
{
    void Thiscall_1Arg(int a);
};
// @fnv 0x00aa4a50
// src: COMMUNITY 0x00aa4a50
void FUN_00aa4a50_shell2::Thiscall_1Arg(int a)
{}

__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
inline bool IsAudioActive(BSAudio* audio)
{
    return audio->bAudioEnabled;
}

// If audio is enabled, stops multithreaded processing when needed, clears initialization, and resets the manager.
// @fnv 0x00ad7150
// src: XBOX_PDB 0x00ad7150
void __fastcall BSAudio_Shutdown(BSAudio* audio)
{
    AudioThreadModeScope scope;
    if (IsAudioActive(audio))
    {
        if (audio->bMultiThread)
            BSAudioManager::GetRandomGenerator().BSAudioManager_StopAudioThread();
        audio->bInitialized = false;
        BSAudioManager::GetRandomGenerator().BSAudioManager_Shutdown();
    }
}

extern NiPoint3 _NiPoint3_ZERO;
// BSAudio.h currently declares this operation with weapon_audio::NiPoint3,
// rather than the NiPoint3 value returned by this unit.
struct FUN_00ad78e0_cls : public BSAudio
{
    NiPoint3 BSAudio_GetListenerPosition();
};
// @fnv 0x00ad78e0
// src: COMMUNITY 0x00ad78e0
NiPoint3 FUN_00ad78e0_cls::BSAudio_GetListenerPosition()
{
    const NiPoint3* p = pListener ? &pListener->GetPosition_00aeaad0() : &_NiPoint3_ZERO;
    return *p;
}

// Sets BSAudioManager's master volume to f and calls FUN_00adc160 with the manager.
// @fnv 0x00ad7b10
void BSAudio::SetMasterVolume(float afVolume)
{
    BSAudioManager& mgr = BSAudioManager::GetRandomGenerator();
    mgr.fMasterVolume = afVolume;
    mgr.BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7b40
// src: COMMUNITY 0x00ad7b40
void BSAudio::SetFootstepVolume(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fFootVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}

// @fnv 0x00ad7b70
// src: COMMUNITY 0x00ad7b70
void BSAudio::SetVoiceVolume(float fVoiceVolume)
{
    BSAudioManager& instance = BSAudioManager::GetRandomGenerator();
    instance.fVoiceVolume = fVoiceVolume;
    instance.BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7ba0
// src: COMMUNITY 0x00ad7ba0
void BSAudio::SetEffectsVolume(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fEffectsVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7bd0
// src: COMMUNITY 0x00ad7bd0
void BSAudio::SetMusicVolume(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fMusicVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7c00
// src: XBOX_PDB 0x00ad7c00
void BSAudio::SetRadioVolume(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fRadioVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}

// @fnv 0x00ad7c30
// src: COMMUNITY 0x00ad7c30
void __fastcall BSAudio_VolumeChanged(BSAudio*)
{
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetRadioVolume();
}

// Reads the float at offset 0x15c of the BSAudioManager singleton and returns it.
// @fnv 0x00ad7cb0
// src: COMMUNITY 0x00ad7cb0
float __fastcall BSAudio_GetFootSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float val = mgr->fFootSecondaryVolume;
    return val;
}

// @fnv 0x00ad7ce0
// src: COMMUNITY 0x00ad7ce0
float __fastcall BSAudio_GetVoiceSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fVoiceSecondaryVolume;
    return result;
}

// @fnv 0x00ad7d10
// src: COMMUNITY 0x00ad7d10
float __fastcall BSAudio_GetEffectsSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fEffectsSecondaryVolume;
    return result;
}

// @fnv 0x00ad7d40
// src: COMMUNITY 0x00ad7d40
float __fastcall BSAudio_GetMusicSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fMusicSecondaryVolume;
    return result;
}

// @fnv 0x00ad7d70
// src: COMMUNITY 0x00ad7d70
float __fastcall BSAudio_GetRadioSecondaryVolume(BSAudio*)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->fRadioSecondaryVolume;
    return result;
}

namespace fnv_00ad7da0 {

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7da0
// src: COMMUNITY 0x00ad7da0
void __fastcall BSAudio_SetMasterSecondaryVolume(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fMasterSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7da0

namespace fnv_00ad7dd0 {

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7dd0
// src: COMMUNITY 0x00ad7dd0
void __fastcall BSWin32Audio_SetFootstepVolumeMult(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fFootSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7dd0

namespace fnv_00ad7e00 {

// Stores value into the audio manager's field and then calls FUN_00adc160 on it.
// @fnv 0x00ad7e00
// src: COMMUNITY 0x00ad7e00
void __fastcall BSWin32Audio_SetVoiceVolumeMult(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fVoiceSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7e00

namespace fnv_00ad7e30 {

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7e30
// src: COMMUNITY 0x00ad7e30
void __fastcall BSWin32Audio_SetEffectsVolumeMult(BSAudio*, float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fEffectsSecondaryVolume = value;
    mgr->BSAudioManager_SetRadioVolume();
}
}  // namespace fnv_00ad7e30

// @fnv 0x00ad7e60
// src: COMMUNITY 0x00ad7e60
void __fastcall BSWin32Audio_SetMusicVolumeMult(BSAudio*, float v)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fMusicSecondaryVolume = v;
    mgr->BSAudioManager_SetRadioVolume();
}

// @fnv 0x00ad7e90
// src: COMMUNITY 0x00ad7e90
void __fastcall BSWin32Audio_SetRadioVolumeMult(BSAudio*, float v)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->fRadioSecondaryVolume = v;
    mgr->BSAudioManager_SetRadioVolume();
}

void __fastcall BSAudioManager_ClearSecondaryVolumes(BSAudioManager* m);
// @fnv 0x00ad7ec0
// src: COMMUNITY 0x00ad7ec0
void __fastcall BSAudio_ClearSecondaryVolumes(BSAudio*)
{
    BSAudioManager_ClearSecondaryVolumes(&BSAudioManager::GetRandomGenerator());
}

namespace fnv_00ad7ee0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// BSAudioManager.h lacks int FUN_00ae5ff0(unsigned int).
struct FUN_00ae5ff0_stub
{
    int BSAudioManager_DebugPrintSounds(unsigned int);
};
// BSAudio.h lacks int FUN_00ad7ee0(unsigned int).
struct FUN_00ad7ee0_shell
{
    int BSAudioManager_DebugPrintSounds_(unsigned int n);
};
// Saves the current audio thread mode, sets it to 11 for the duration of the call, then restores it and returns the result of FUN_00ae5ff0(n).
// @fnv 0x00ad7ee0
// src: COMMUNITY 0x00ad7ee0
int FUN_00ad7ee0_shell::BSAudioManager_DebugPrintSounds_(unsigned int n)
{
    AudioThreadModeScope scope;
    return ((FUN_00ae5ff0_stub*)&BSAudioManager::GetRandomGenerator())->BSAudioManager_DebugPrintSounds(n);
}
}  // namespace fnv_00ad7ee0

namespace fnv_00ad81c0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// BSAudio.h lacks void SetAudioThreadModeAndForward(unsigned int).
struct FUN_00ad81c0_shell
{
    void SetAudioThreadModeAndForward(unsigned int n);
};
// Saves the current audio thread mode, sets it to 11 for the scope, and forwards n to SetAudioCacheSize on the BSAudioManager singleton.
// @fnv 0x00ad81c0
void FUN_00ad81c0_shell::SetAudioThreadModeAndForward(unsigned int auiValue)
{
    AudioThreadModeScope scope;
    BSAudioManager::GetRandomGenerator().SetAudioCacheSize(static_cast<int>(auiValue));
}
}  // namespace fnv_00ad81c0

namespace fnv_00ad8270 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// @fnv 0x00ad8270
// src: COMMUNITY 0x00ad8270
int __fastcall BSAudio_GetAudioCacheSizeInK(BSAudio*)
{
    AudioThreadModeScope scope;
    return BSAudioManager::GetRandomGenerator()._BSAudioManager_AudioCacheSize();
}
}  // namespace fnv_00ad8270

namespace fnv_00ad8320 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// BSAudio.h lacks void FUN_00ad8320(bool).
struct FUN_00ad8320_shell
{
    void BSAudio_SetCacheEnabled(bool b);
};
// Saves the current audio thread mode, sets it to 11 for the duration of the call, then restores it after forwarding b to FUN_00ae6ca0 on the audio manager.
// @fnv 0x00ad8320
// src: COMMUNITY 0x00ad8320
void FUN_00ad8320_shell::BSAudio_SetCacheEnabled(bool b)
{
    AudioThreadModeScope scope;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetCacheEnabled(b);
}
}  // namespace fnv_00ad8320

namespace fnv_00ad83d0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
// @fnv 0x00ad83d0
// src: COMMUNITY 0x00ad83d0
bool __fastcall BSAudio_GetCacheEnabled(BSAudio*)
{
    AudioThreadModeScope scope;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_IsEnableAudioCache();
}
}  // namespace fnv_00ad83d0

extern MemoryManager g_memoryManager;
void __fastcall FUN_00ad7000(BSAudio*);
// BSAudio.h lacks void* FUN_00ad8790(unsigned int), the deleting destructor.
struct FUN_00ad8790_shell
{
    void* FUN_00ad8790(unsigned int flags);
};
// Calls FUN_00ad7000 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ad8790
void* FUN_00ad8790_shell::FUN_00ad8790(unsigned int flags)
{
    FUN_00ad7000(reinterpret_cast<BSAudio*>(this));
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

extern bool DAT_01202800;

struct SettingBool
{
    virtual ~SettingBool();
    bool bValue;
    char* pKey;
    bool& GetBool()
    {
        return this ? bValue : (DAT_01202800 = false);
    }
};

extern SettingBool g_011f6dfc;

inline bool BSAudio::IsAudioEnabled() const
{
    return bAudioEnabled;
}

// @fnv 0x00ad7230
void BSAudio::SetUseMultipleThreads(bool abUseMultipleThreads)
{
    MemContextScope tempMemContext(11);
    if (!IsAudioEnabled())
    {
        return;
    }
    if (!g_011f6dfc.GetBool() && abUseMultipleThreads)
    {
        return;
    }
    if (abUseMultipleThreads && !bMultiThread)
    {
        BSAudioManager::GetRandomGenerator().StartAudioThreads();
    }
    else if (!abUseMultipleThreads && bMultiThread)
    {
        BSAudioManager::GetRandomGenerator().StopAudioThreads();
    }
    bMultiThread = abUseMultipleThreads;
}

// BSAudioManager.h lacks BSSoundHandle FUN_00ae5870(unsigned int, unsigned int).
struct FUN_00ae5870_t
{
    BSSoundHandle BSAudioManager_InitSoundForm(unsigned int, unsigned int);
};
extern __declspec(thread) int BSAudioThreadContext;
__forceinline int BSAudioGetMemContext()
{
    return BSAudioThreadContext;
}
__forceinline void BSAudioSetMemContext(int aiMemoryContext)
{
    BSAudioThreadContext = aiMemoryContext;
}
struct BSAudioScopedMemContext
{
    int m_eMemoryContext;
    __forceinline BSAudioScopedMemContext(int m_iLineNumber) : m_eMemoryContext(BSAudioGetMemContext())
    {
        BSAudioSetMemContext(m_iLineNumber);
    }
    __forceinline ~BSAudioScopedMemContext()
    {
        BSAudioSetMemContext(m_eMemoryContext);
    }
};
// Sets the audio memory context to 11, then forwards the form ID and type flags to the sound manager to create a sound handle.
// @fnv 0x00ad73b0
// src: COMMUNITY 0x00ad73b0
BSSoundHandle BSAudio::GetSoundHandleByFormID_00ad73b0(unsigned int aiFormID, unsigned int aiTypeFlags)
{
    BSAudioScopedMemContext tempMemContext(11);
    return reinterpret_cast<FUN_00ae5870_t*>(&BSAudioManager::GetRandomGenerator())->BSAudioManager_InitSoundForm(aiFormID, aiTypeFlags);
}

namespace fnv_00ad7620 {
extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

// BSAudioManager.h lacks BSSoundHandle FUN_00ae5870(unsigned int, unsigned int).
struct FUN_00ae5870_t
{
    BSSoundHandle BSAudioManager_InitSoundForm(unsigned int, unsigned int);
};

// BSAudio.h lacks this four-argument positioned-handle factory.
struct FUN_00ad7620_t : public BSAudio
{
    BSSoundHandle BSAudio_SpawnSoundReference(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc, unsigned int aiID);
};

// Creates a sound handle for the given form and type flags, positions it at aLoc, starts playback, and returns the handle.
// @fnv 0x00ad7620
// src: XBOX_PDB 0x00ad7620
BSSoundHandle FUN_00ad7620_t::BSAudio_SpawnSoundReference(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc,
                                             unsigned int aiID)
{
    MemContextScope tempMemContext(11);
    BSSoundHandle hndl =
        reinterpret_cast<FUN_00ae5870_t*>(&BSAudioManager::GetRandomGenerator())->BSAudioManager_InitSoundForm(aiFormID, aiTypeFlags);
    hndl.SetPosition(aLoc.x, aLoc.y, aLoc.z);
    hndl.Play(true);
    return hndl;
}
}  // namespace fnv_00ad7620

namespace fnv_00ad77f0 {
struct OH2TlsBlock
{
    char pad[0x2b4];
    int m_iThreadLocalValue;
};
extern __declspec(thread) OH2TlsBlock g_OH2Tls;
struct OH2MemContext
{
    int m_eMemoryContext;
    __forceinline OH2MemContext(int aiContext)
    {
        int iOld = g_OH2Tls.m_iThreadLocalValue;
        m_eMemoryContext = iOld;
        g_OH2Tls.m_iThreadLocalValue = aiContext;
    }
    __forceinline ~OH2MemContext()
    {
        int iOld = m_eMemoryContext;
        g_OH2Tls.m_iThreadLocalValue = iOld;
    }
};
} // namespace fnv_00ad77f0

// @fnv 0x00ad77f0
// src: COMMUNITY 0x00ad77f0
void BSAudio::SetConditions(float afCurrentGamehour, unsigned int aiWeatherConditions)
{
    fnv_00ad77f0::OH2MemContext tempMemContext(0xb);
    BSAudioManager::GetRandomGenerator().SetConditions_00ada300(afCurrentGamehour, aiWeatherConditions);
}

__forceinline BSAudioListener* BSAudioGetListener(BSAudio* pAudio)
{
    return pAudio->pListener;
}
// If a listener is attached, forwards aiEnviroType to SetListenerID.
// @fnv 0x00ad79b0
// src: XBOX_PDB 0x00ad79b0
void BSAudio::SetEnvironment(unsigned int aiEnviroType)
{
    if (BSAudioGetListener(this))
    {
        BSAudioGetListener(this)->SetListenerID(aiEnviroType);
    }
}

extern __declspec(thread) int g_tlsMemContext;

namespace sad8050 {

struct MemContextGuard
{
    int m_iPrevious;

    MemContextGuard(int aiMemoryContext)
    {
        int iPrevious = g_tlsMemContext;
        m_iPrevious = iPrevious;
        g_tlsMemContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        int iPrevious = m_iPrevious;
        g_tlsMemContext = iPrevious;
    }
};

} // namespace sad8050

// Sets the thread memory context to 0xb and forwards iArg0 and iArg1 to FUN_00add630 on the Manager returned by FUN_00ad9060.
// @fnv 0x00ad8050
void BSAudio::ForwardToManager(unsigned int iArg0, unsigned int iArg1)
{
    sad8050::MemContextGuard kGuard(0xb);
    BSAudioManager::GetRandomGenerator().Precache_00add630(iArg0, iArg1);
}

namespace fnv_00ad8100 {

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

static inline int GetCurrentMemContext()
{
    return g_tlsData.memContext;
}

static inline void SetCurrentMemContext(int context)
{
    g_tlsData.memContext = context;
}

struct MemContextScope
{
    int oldContext;
    MemContextScope(int newContext)
    {
        oldContext = GetCurrentMemContext();
        g_tlsData.memContext = newContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(oldContext);
    }
};

} // namespace fnv_00ad8100

// Sets memory context 11 and forwards the sound name, flags, and parameter to BSAudioManager::FUN_00add6f0.
// @fnv 0x00ad8100
// src: COMMUNITY 0x00ad8100
void BSAudio::Precache_00ad8100(unsigned int apSoundName, unsigned int aiFlags, unsigned int apParam)
{
    fnv_00ad8100::MemContextScope tempMemContext(11);
    BSAudioManager::GetRandomGenerator().BSAudioManager_Precache_00add6f0(apSoundName, aiFlags, apParam);
}
