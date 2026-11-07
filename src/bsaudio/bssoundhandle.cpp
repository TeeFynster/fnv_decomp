// bsaudio/bssoundhandle.cpp: sound playback and HUD helpers (37 functions)

#include "bssoundhandle_decls.h"
#include "../../include/BSAudio.h"
#include "../../include/BSAudioManager.h"
#include "../../include/HUDMainMenu.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/Setting.h"

extern BSAudio* DAT_011f6d98;

__forceinline BSAudio* BSAudio::GetRandomGenerator()
{
    return DAT_011f6d98;
}

__forceinline bool BSAudio::IsAudioEnabled() const
{
    return bAudioEnabled;
}

// @fnv 0x00ad8e60
void BSSoundHandle::SetCompletionCallback(CompletionCallback callback, void* context)
{
    if (!BSAudio::GetRandomGenerator()->IsAudioEnabled() && callback)
    {
        callback(context, false);
    }
    if (iSoundID != 0xffffffff)
    {
        BSAudioManager::GetRandomGenerator().BSAudioManager_SetCompletionCallback(iSoundID, callback, context);
    }
}

// Returns false when the sound handle is invalid, otherwise checks the cached state or queries BSAudioManager::IsPlaying for the handle.
// @fnv 0x00ad8930
bool BSSoundHandle::IsPlaying()
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    if (bAssumeSuccess)
    {
        return eState == ASSUMED_STATE_PLAYING;
    }
    else
    {
        return BSAudioManager::GetRandomGenerator().IsPlaying(iSoundID);
    }
}

// If the stored sound handle is valid, sets the state to playing and forwards the handle, delay and start time to BSAudioManager.
// @fnv 0x00ad8870
bool BSSoundHandle::PlayAfter(unsigned int delay, int startTime)
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_PlayAfter(iSoundID, delay, startTime);
}

// If a sound handle is set, passes it with fadeTime and 0x26 to BSAudioManager, clears the handle, and returns true; otherwise returns false.
// @fnv 0x00ad8da0
bool BSSoundHandle::FadeOutAndRelease(unsigned int fadeTime)
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    BSAudioManager::GetRandomGenerator().SetPlaybackTime(iSoundID, fadeTime, 0x26);
    iSoundID = 0xffffffff;
    return true;
}

// @fnv 0x00719060
bool SystemColorManager::GetColor(int id, NiColor& color)
{
    SystemColor* systemColor = Find(id);
    if (systemColor)
    {
        systemColor->SystemColorManager_SystemColor_GetColor(color);
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x00ad8a90
bool BSSoundHandle::SetModFrequency(float frequency)
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    return BSAudioManager::GetRandomGenerator().SetPlaybackFrequency(iSoundID, frequency);
}

// @fnv 0x00ad8ce0
bool BSSoundHandle::IsValid()
{
    if (iSoundID == 0xffffffff)
    {
        return false;
    }
    return BSAudioManager::GetRandomGenerator().IsSoundPlaying(iSoundID);
}

// This singleton helper is distinct from the shared instance RefreshTargetDisplay method.
// @fnv 0x00778b10
void __cdecl RefreshHUDTargetDisplay()
{
    if (HUDMainMenu::g_pHudMainMenuInstance)
    {
        HUDMainMenu::UpdateTargetReference(HUDMainMenu::g_pHudMainMenuInstance->m_pCrosshairReference, false, true);
    }
}

void __cdecl abs_0072fa80(int);

// @fnv 0x0072fa60
// src: XBOX_PDB 0x0072fa60
void __cdecl BSAbs(int param_1)
{
    abs_0072fa80(param_1);
}

// @fnv 0x00ad8830
bool BSSoundHandle::Play(bool v)
{
    if (iSoundID == 0xffffffff)
        return false;
    eState = ASSUMED_STATE_PLAYING;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_Play(iSoundID, v);
}

// @fnv 0x00ad89b0
bool BSSoundHandle::SetStaticAttenuation(unsigned short aiStaticAttenutation)
{
    if (iSoundID == -1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetStaticAttenuation(iSoundID, aiStaticAttenutation);
}

// @fnv 0x00ad89e0
bool BSSoundHandle::SetVolume(float aiNewVolume)
{
    if (static_cast<int>(iSoundID) == -1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetVolume(static_cast<int>(iSoundID), aiNewVolume);
}

// If id is valid, forwards id and v to BSAudioManager's FUN_00adb8e0 and returns its result; otherwise returns false.
// @fnv 0x00ad8ad0
bool BSSoundHandle::SetFrequencyVariance(unsigned char v)
{
    if (iSoundID == 0xffffffff)
        return false;
    // Forward the original byte unchanged; converting it to bool adds normalization code.
    return (BSAudioManager::GetRandomGenerator().*reinterpret_cast<bool (BSAudioManager::*)(unsigned int, unsigned char)>(
        static_cast<bool (BSAudioManager::*)(unsigned int, bool)>(&BSAudioManager::BSAudioManager_SetFrequencyVariance)))(iSoundID, v);
}

// @fnv 0x00ad8b60
bool BSSoundHandle::SetPosition(float x, float y, float z)
{
    if (iSoundID == 0xFFFFFFFF)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetPosition(iSoundID, x, y, z);
}

// @fnv 0x00ad8be0
void BSSoundHandle::SetMinMax(float afMin, float afMax)
{
    if (iSoundID == 0xFFFFFFFF)
        return;

    BSAudioManager::GetRandomGenerator().BSAudioManager_SetMinMaxDistance(iSoundID, afMin, afMax);
}

// @fnv 0x00ad8c20
void BSSoundHandle::SetAttenuationCurve(unsigned short ausArg1, unsigned short ausArg2, unsigned short ausArg3,
                                            unsigned short ausArg4, unsigned short ausArg5)
{
    if (iSoundID == 0xFFFFFFFF)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetAttenuationCurve(iSoundID, ausArg1, ausArg2, ausArg3, ausArg4, ausArg5);
}

// @fnv 0x00ad8c70
void BSSoundHandle::SetReverbAttenuation(unsigned short param)
{
    if (iSoundID == -1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetReverbAttenuation(iSoundID, param);
}

extern void(__cdecl* DAT_011f6e08)(NiAVObject*);
// If the stored id is valid and apObj is non-null, calls DAT_011f6e08 on apObj and then FUN_00adc1e0 with the stored id and apObj.
// @fnv 0x00ad8f20
void BSSoundHandle::SetObjectToFollow(NiAVObject* apObj)
{
    if (iSoundID == 0xFFFFFFFF || !apObj)
        return;
    if (DAT_011f6e08)
        DAT_011f6e08(apObj);
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetObjectToFollow(iSoundID, apObj);
}

// @fnv 0x00ad8f70
void BSSoundHandle::Seek(unsigned int v)
{
    if (iSoundID == 0xffffffff)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetPriority(iSoundID, v);
}

extern Setting originalRuntimeFloatSetting104;

struct FUN_008bc240_h
{
    char pad[0x150];
    unsigned int f150;
    float f154;
    void Actor_SetActionSoundValue(unsigned int v);
};

// Stores v into f150 and copies the float from originalRuntimeFloatSetting104 into f154.
// @fnv 0x008bc240
// src: COMMUNITY 0x008bc240
void FUN_008bc240_h::Actor_SetActionSoundValue(unsigned int auiValue)
{
    f150 = auiValue;
    f154 = *originalRuntimeFloatSetting104.Float();
}

struct Owner009b11c0
{
    void Explosion_StopSounds();
};

// @fnv 0x009b11c0
// src: XBOX_PDB 0x009b11c0
void Owner009b11c0::Explosion_StopSounds()
{
    if (((BSSoundHandle*)((char*)this + 0xac))->IsValid())
    {
        ((BSSoundHandle*)((char*)this + 0xac))->Stop();
        if (((BSSoundHandle*)((char*)this + 0xac))->IsValid())
        {
            ((BSSoundHandle*)((char*)this + 0xac))->Release();
        }
    }
    if (((BSSoundHandle*)((char*)this + 0xb8))->IsValid())
    {
        ((BSSoundHandle*)((char*)this + 0xb8))->Stop();
        if (((BSSoundHandle*)((char*)this + 0xb8))->IsValid())
        {
            ((BSSoundHandle*)((char*)this + 0xb8))->Release();
        }
    }
}

// @fnv 0x00ad88b0
bool BSSoundHandle::Pause()
{
    if (iSoundID == (unsigned int)-1)
        return false;
    eState = ASSUMED_STATE_PAUSED;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_Pause(iSoundID);
}

// @fnv 0x00ad88f0
bool BSSoundHandle::Stop()
{
    if (iSoundID == (unsigned int)-1)
        return false;
    eState = ASSUMED_STATE_STOPPED;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_Stop(iSoundID);
}

// @fnv 0x00ad8980
int BSSoundHandle::GetSoundType()
{
    if (iSoundID == 0xFFFFFFFF)
        return 0;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_GetSoundType(iSoundID);
}

// @fnv 0x00ad8a20
float BSSoundHandle::GetVolume()
{
    if (iSoundID == 0xFFFFFFFF)
        return 0.0f;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_GetVolume(iSoundID);
}

// If the stored id is not -1, forwards the id and arg to BSAudioManager's FUN_00adb7c0 and returns its result; otherwise returns false.
// @fnv 0x00ad8a50
bool BSSoundHandle::SetFrequency(float afValue)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetFrequency(iSoundID, afValue);
}

// Returns false if id is -1, otherwise forwards id and arg to FUN_00adb960 on the BSAudioManager singleton.
// @fnv 0x00ad8b00
bool BSSoundHandle::SetBalance(int arg)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetBalance(iSoundID, static_cast<unsigned int>(arg));
}

// Queries the duration through the audio manager when this handle is valid.
// @fnv 0x00ad8b30
int BSSoundHandle::GetDuration()
{
    if (iSoundID == -1)
        return 0;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_GetDuration(iSoundID);
}

// Returns false if id is -1, otherwise forwards id and the three floats to the audio manager's FUN_00adb9f0 and returns its result.
// @fnv 0x00ad8ba0
bool BSSoundHandle::SetBeamEnd(float a, float b, float c)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetBeamEnd(iSoundID, a, b, c);
}

// If id is not -1, forwards id and the three floats to the audio manager's FUN_00adbf40 and returns its result; otherwise returns false.
// @fnv 0x00ad8ca0
bool BSSoundHandle::SetOrientation(float a, float b, float c)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    return BSAudioManager::GetRandomGenerator().BSAudioManager_SetOrientation(iSoundID, a, b, c);
}

// @fnv 0x00ad8de0
bool BSSoundHandle::FadeOut(unsigned int arg)
{
    if (iSoundID == (unsigned int)-1)
        return false;
    eState = ASSUMED_STATE_STOPPED;
    BSAudioManager::GetRandomGenerator().SetPlaybackTime(iSoundID, arg, 0);
    return true;
}

// If id is not -1, forwards id and the two byte arguments to FUN_00adc4e0 on the BSAudioManager singleton.
// @fnv 0x00ad8e20
void BSSoundHandle::SetTimeConstraints(unsigned char aucArg1, unsigned char aucArg2)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetTimeConstraints(iSoundID, aucArg1, aucArg2);
}

typedef void(__cdecl* LocalCb)(void*, unsigned int);

// @fnv 0x00ad8ec0
void BSSoundHandle::SetPlayCallback(CompletionCallback apCallback, void* arg)
{
    BSAudio* audio = DAT_011f6d98;
    bool flag = audio->bAudioEnabled;
    if (!flag && apCallback)
    {
        reinterpret_cast<LocalCb>(apCallback)(arg, 5000);
    }
    if (iSoundID != 0xFFFFFFFF)
    {
        BSAudioManager::GetRandomGenerator().BSAudioManager_SetPlayCallback(iSoundID, reinterpret_cast<LocalCb>(apCallback), arg);
    }
}

// If id is not -1, forwards id and arg to FUN_00adc260 on the BSAudioManager instance.
// @fnv 0x00ad8fd0
void BSSoundHandle::SetSynchStartTime(unsigned int uiValue)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_Seek(iSoundID, uiValue);
}

// If the stored id is not -1, forwards it and arg to BSAudioManager's FUN_00adc2e0.
// @fnv 0x00ad8fa0
void BSSoundHandle::SetFollowsListener(bool arg)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetAtListener(iSoundID, static_cast<unsigned char>(arg));
}

// If the stored id is not -1, forwards it and arg to BSAudioManager::FUN_00adc360.
// @fnv 0x00ad9030
void BSSoundHandle::SetPriority(unsigned int arg)
{
    if (iSoundID == (unsigned int)-1)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_SetSynchStartTime(iSoundID, arg);
}

// BSSoundHandle::ClearSynchStartTime (community FalloutNV.pdb at this address).
// @fnv 0x00ad9000
void BSSoundHandle::ClearSynchStartTime()
{
    if (iSoundID == 0xFFFFFFFF)
        return;
    BSAudioManager::GetRandomGenerator().BSAudioManager_ClearSynchStartTime(iSoundID);
}
