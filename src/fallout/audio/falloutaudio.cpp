// fallout/audio/falloutaudio.cpp: SoundPlaybackManager, PlayerCharacter, std, Interface and more (14 functions)

#include "../../../include/BGSAcousticSpace.h"
#include "../../../include/BGSImpactData.h"
#include "../../../include/BGSLoadGameBuffer.h"
#include "../../../include/BSAudio.h"
#include "../../../include/Clouds.h"
#include "../../../include/LowProcess.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiTPointerMap.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/Precipitation.h"
#include "../../../include/Sky.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/Sun.h"
#include "../../../include/TES.h"
#include "../../../include/TESDataHandler.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESLandTexture.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESRegionData.h"
#include "../../../include/TESSound.h"
#include "../../../include/TESTopicInfo.h"
#include "../../../include/TESWeather.h"
#include "../../../include/BSAudioListener.h"
#include "../../../include/BSSimpleList.h"
#include "falloutaudio_decls.h"
#include "../../../include/BGSSaveFormBuffer.h"
// Updates ambient and region sounds from the player's target acoustic space, weather and time of day, starting/stopping sound handles and pruning stale ones.
// @fnv 0x0082d7c0
void SoundPlaybackManager::ProcessPendingSounds()
{
    bool updated = false;
    BSSoundHandle* pendingHandle = 0;
    BSSoundHandle* existingHandle;
    float fStartHour;
    float soundEndHour;
    BSSimpleList<RegionSound*>* sounds = g_thePlayer->GetRegionSounds();
    bool isSubmerged = TESLandTexture::GetSoundSystem()->IsListenerUnderwater_00ad7c50();
    BGSAcousticSpace* acousticSpace = !g_thePlayer                ? 0
                                      : !g_thePlayer->GetTarget() ? 0
                                                                  : g_thePlayer->GetTarget()->GetAcousticSpace();
    if (DAT_011dcfb4 && !DAT_011dcfb4->GetByteAtOffset48() && acousticSpace && acousticSpace->GetByteAtOffset48())
    {
        SetAcousticSpace(acousticSpace);
        DAT_011dcfb1 = false;
        DAT_011dcfb8 = 0;
    }
    if (DAT_011dcfb1)
    {
        if (DAT_011dcfb8 == DAT_011dcfb4)
        {
            DAT_011dcfb8 = 0;
            DAT_011dcfb1 = false;
        }
        else
            SetAcousticSpace(DAT_011dcfb8);
    }
    if (!DAT_011dcfa8)
    {
        DAT_011dcfa8 = g_dataHandler->GetSoundByEditorID("UIActivateNothing");
        if (DAT_011dcfa8)
            TESLandTexture::GetSoundSystem()->Precache(DAT_011dcfa8->TESSound_GetFilename(), 0x121, DAT_011dcfa8);
    }
    if (!DAT_011dcfb4 && g_thePlayer && g_thePlayer->GetTarget() &&
        g_thePlayer->GetTarget()->GetAcousticSpace() != DAT_011dcfb4)
        SetAcousticSpace(g_thePlayer->GetTarget()->GetAcousticSpace());
    else if (!g_thePlayer || (!g_thePlayer->GetTarget() && !g_thePlayer->IsRegionSoundsEnabled()))
        ResetAcousticSpace(0);
    if (DAT_011dcfb4 && reinterpret_cast<BGSImpactData*>(DAT_011dcfb4)->GetDecalTextureSet())
    {
        RegionSoundSource source;
        source.region = reinterpret_cast<NiAVObject*>(reinterpret_cast<BGSImpactData*>(DAT_011dcfb4)->GetDecalTextureSet());
        source.data = reinterpret_cast<RegionDataList*>(source.region->GetParent())->Find(7);
        if (source.data)
            sounds = source.data->GetOffsetC();
    }
    if (DAT_011dcfb4)
        TESLandTexture::GetSoundSystem()->SetEnvironment(DAT_011dcfb4->GetField4C());
    else
        TESLandTexture::GetSoundSystem()->SetEnvironment(0);
    if (isSubmerged && g_thePlayer->GetTarget() && !DAT_011dd0a0.IsPlaying())
    {
        DAT_011dd0a0 = TESLandTexture::GetSoundSystem()->GetSoundHandleByEditorID("AMBUnderwaterLP", 0x2101);
        DAT_011dd0a0.SetAssumeSuccess(1);
        DAT_011dd0a0.Play(false);
    }
    else if ((!isSubmerged || !g_thePlayer->GetTarget()) && DAT_011dd0a0.IsPlaying())
        DAT_011dd0a0.FadeOutAndRelease(300);
    InitFootstepImpacts();
    InitializeSlots();
    if (DAT_011dcfa6)
        return;
    Sky* pWeatherSky = g_TES->GetLogDate();
    float time = pWeatherSky ? pWeatherSky->GetFieldEC() : 0.0f;
    TESLandTexture::GetSoundSystem()->SetConditions(time, 0);
    if (std::abs(TESLandTexture::GetSoundSystem()->GetCurrentTimeMilliseconds() - DAT_011dcfc0) > 1000)
    {
        if (g_thePlayer)
            g_thePlayer->ResetRegionSoundTimer();
        if (!Interface::GetSelectedTargetIndex(Interface::MenuLoading))
            g_TES->TES_UpdateRefSounds();
        float fade = DAT_011dd044.Float()->f;
        if (DAT_011dd0d8.IsPlaying())
            fade = DAT_011dd094.Float()->f;
        if (DAT_011dcfb4 && g_thePlayer)
        {
            if (DAT_011dcfb4->GetByteAtOffset48())
            {
                bool changed = DAT_011dcfb1;
                if (!DAT_011dd0d8.IsValid())
                    changed = true;
                if (changed)
                {
                    if (DAT_011dcfb1)
                    {
                        DAT_011dcfb8 = 0;
                        DAT_011dcfb1 = false;
                    }
                    if (DAT_011dd0d8.IsPlaying())
                    {
                        DAT_011dd0d8.FadeOutAndRelease((unsigned int)(DAT_011dd050.Float()->f * 500.0));
                        DAT_011dd0d8.Clear();
                    }
                    DAT_011dcfb0 = false;
                    TESSound* sound = reinterpret_cast<TESSound*>(reinterpret_cast<LowProcess*>(DAT_011dcfb4)->BaseProcess::GetCurrentBoundObject());
                    if (sound)
                    {
                        DAT_011dd0d8 = TESLandTexture::GetSoundSystem()->GetSoundHandleByFilePath(sound->TESSound_GetFilename(),
                                                                                                  0x11011, sound);
                        DAT_011dd0d8.FadeInPlay((unsigned int)(fade * 1000.0));
                    }
                }
            }
            else
            {
                bool changed = DAT_011dcfb1;
                if (!changed)
                {
                    switch (DAT_011dcfac)
                    {
                    case 0:
                        if (time > DAT_011f6dcc.Float()->f)
                            changed = true;
                        break;
                    case 1:
                        if (time > DAT_011f6dd8.Float()->f)
                            changed = true;
                        break;
                    case 2:
                        if (time > DAT_011f6de4.Float()->f)
                            changed = true;
                        break;
                    case 3:
                        if (time > DAT_011f6dc0.Float()->f && time < DAT_011f6de4.Float()->f)
                            changed = true;
                        break;
                    }
                }
                if (changed)
                {
                    if (DAT_011dcfb1)
                    {
                        DAT_011dcfb8 = 0;
                        DAT_011dcfb1 = false;
                    }
                    else
                    {
                        DAT_011dd0d8.FadeOutAndRelease((unsigned int)(DAT_011dd050.Float()->f * 1000.0));
                        DAT_011dd0d8.Clear();
                    }
                    DAT_011dcfb0 = false;
                    TESSound* sound;
                    if (time > DAT_011f6dc0.Float()->f)
                    {
                        if (time > DAT_011f6dcc.Float()->f)
                        {
                            if (time > DAT_011f6dd8.Float()->f)
                            {
                                if (time > DAT_011f6de4.Float()->f)
                                {
                                    sound = reinterpret_cast<TESSound*>(reinterpret_cast<LowProcess*>(DAT_011dcfb4)->LowProcess::GetTarget());
                                    DAT_011dcfac = 3;
                                }
                                else
                                {
                                    sound = reinterpret_cast<TESSound*>(reinterpret_cast<TESTopicInfo*>(DAT_011dcfb4)->GetSpeaker());
                                    DAT_011dcfac = 2;
                                }
                            }
                            else
                            {
                                sound = reinterpret_cast<TESSound*>(reinterpret_cast<TESTopicInfo*>(DAT_011dcfb4)->GetConversationData());
                                DAT_011dcfac = 1;
                            }
                        }
                        else
                        {
                            sound = reinterpret_cast<TESSound*>(reinterpret_cast<LowProcess*>(DAT_011dcfb4)->BaseProcess::GetCurrentBoundObject());
                            DAT_011dcfac = 0;
                        }
                    }
                    else
                    {
                        sound = reinterpret_cast<TESSound*>(reinterpret_cast<LowProcess*>(DAT_011dcfb4)->LowProcess::GetTarget());
                        DAT_011dcfac = 3;
                    }
                    if (sound)
                    {
                        DAT_011dd0d8 = TESLandTexture::GetSoundSystem()->GetSoundHandleByFilePath(sound->TESSound_GetFilename(),
                                                                                                  0x11011, sound);
                        DAT_011dd0d8.FadeInPlay((unsigned int)(fade * 1000.0));
                    }
                }
            }
        }
        else
        {
            DAT_011dd0d8.FadeOutAndRelease(1000);
            DAT_011dd0d8.Clear();
        }
        if (!sounds->IsEmpty() && !Interface::GetSelectedTargetIndex(Interface::MenuLoading))
        {
            updated = true;
            BSSimpleList<RegionSound*>* pRegionCursor = sounds;
            RegionSound* soundEntry = 0;
            TESSound* pActiveSound = 0;
            BSSoundHandle* loopSoundHandle = 0;
            BSSoundHandle kPlaybackHandle(0u);
            NiPoint3 location;
            bool isSoundAllowed = true;
            bool looping = false;
            bool soundFound = false;
            float fPlayProbability;
            BSAudioListener* pCurrentListener = static_cast<BSAudioListener*>(TESLandTexture::GetSoundSystem()->GetAudioBackendData());
            while (pRegionCursor && !pRegionCursor->IsEmpty())
            {
                isSoundAllowed = true;
                soundEntry = pRegionCursor->GetItem();
                pActiveSound = soundEntry->sound;
                if (!soundEntry || !pActiveSound)
                {
                    pRegionCursor = pRegionCursor->GetNext();
                    continue;
                }
                fStartHour = pActiveSound->GetHighByteOfField4E() * 0.09375;
                soundEndHour = pActiveSound->GetEndTime_0082d700() * 0.09375;
                looping = TESSound::GetPlaybackFlags(pActiveSound->CopyBig().iFlags) != 0;
                if (pWeatherSky)
                {
                    if ((soundEntry->weatherFlags & 0xffff) && pWeatherSky->GetAudioBackendData())
                    {
                        unsigned int weather = pWeatherSky->GetAudioBackendData()->GetWeatherDataRaw(11);
                        if (!((soundEntry->weatherFlags & 0xffff) & weather) && weather)
                            isSoundAllowed = false;
                    }
                    if (std::abs(soundEndHour - fStartHour) >= 0.09375)
                    {
                        if ((fStartHour < soundEndHour && (fStartHour > time || soundEndHour < time)) ||
                            (fStartHour > soundEndHour && fStartHour > time && soundEndHour < time))
                            isSoundAllowed = false;
                    }
                }
                soundFound = DAT_011dd014.GetAt(pActiveSound->Deallocate(), existingHandle);
                if (looping && !soundFound && isSoundAllowed)
                {
                    loopSoundHandle = new BSSoundHandle;
                    *loopSoundHandle = TESLandTexture::GetSoundSystem()->GetSoundHandleByFilePath(
                        pActiveSound->TESSound_GetFilename(), 0x11011, pActiveSound);
                    loopSoundHandle->SetAssumeSuccess(1);
                    DAT_011dd014.SetAt(pActiveSound->Deallocate(), loopSoundHandle);
                    loopSoundHandle->FadeInPlay((unsigned int)(DAT_011dd06c.Float()->f * 1000.0));
                }
                else if (looping && soundFound)
                {
                    if (existingHandle->IsPlaying() && !isSoundAllowed)
                    {
                        existingHandle->FadeOutAndRelease((unsigned int)(DAT_011dcfe4.Float()->f * 1000.0));
                        DAT_011dd014.RemoveAt(pActiveSound->Deallocate());
                        delete existingHandle;
                    }
                    else if (existingHandle->IsValid() && !existingHandle->IsPlaying() && isSoundAllowed)
                        existingHandle->FadeInPlay((unsigned int)(DAT_011dd06c.Float()->f * 1000.0));
                }
                else if (!looping && isSoundAllowed)
                {
                    fPlayProbability = soundEntry->chance / 20000000.0;
                    if (RandomBoolean(fPlayProbability))
                    {
                        if (pActiveSound->CopyBig().iFlags & 0x40)
                            kPlaybackHandle = TESLandTexture::GetSoundSystem()->GetSoundHandleByFilePath(
                                pActiveSound->TESSound_GetFilename(), 0x11101, pActiveSound);
                        else
                            kPlaybackHandle = TESLandTexture::GetSoundSystem()->GetSoundHandleByFilePath(
                                pActiveSound->TESSound_GetFilename(), 0x11102, pActiveSound);
                        location = *static_cast<const TESObjectREFR*>(g_thePlayer)->GetPos();
                        if (pCurrentListener)
                            location = pCurrentListener->GetPosition_00aeaad0();
                        RegionSoundOffset offset;
                        offset.x = DialogueRandom() % 650 + 100;
                        offset.y = DialogueRandom() % 650 + 100;
                        if (RandomBoolean(0.5f))
                            offset.x *= -1.0;
                        if (RandomBoolean(0.5f))
                            offset.y *= -1.0;
                        location.x += offset.x;
                        location.y += offset.y;
                        location.z += 200.0;
                        kPlaybackHandle.SetPriority(static_cast<unsigned char>(255));
                        kPlaybackHandle.SetPosition(location.x, location.y, location.z);
                        kPlaybackHandle.Play(false);
                    }
                }
                pRegionCursor = pRegionCursor->GetNext();
            }
            unsigned int key = 0;
            bool bKeepSound = false;
            void* soundIterator = DAT_011dd014.GetFirstPos();
            pRegionCursor = sounds;
            while (soundIterator)
            {
                DAT_011dd014.GetNext(soundIterator, key, existingHandle);
                while (pRegionCursor && !pRegionCursor->IsEmpty())
                {
                    soundEntry = pRegionCursor->GetItem();
                    pActiveSound = soundEntry->sound;
                    if (key == pActiveSound->Deallocate())
                    {
                        bKeepSound = true;
                        break;
                    }
                    pRegionCursor = pRegionCursor->GetNext();
                }
                if (!bKeepSound)
                {
                    DAT_011dd014.RemoveAt(key);
                    soundIterator = DAT_011dd014.GetFirstPos();
                    existingHandle->FadeOutAndRelease((unsigned int)(DAT_011dcfe4.Float()->f * 1000.0));
                    delete existingHandle;
                    existingHandle = 0;
                }
            }
        }
        DAT_011dcfc0 = TESLandTexture::GetSoundSystem()->GetCurrentTimeMilliseconds();
    }
    else if (sounds->IsEmpty() && !DAT_011dd014.IsEmpty())
    {
        void* pos;
        {
            bool cleared = false;
            pos = DAT_011dd014.GetFirstPos();
            while (pos)
            {
                unsigned int key;
                DAT_011dd014.GetNext(pos, key, existingHandle);
                DAT_011dd014.RemoveAt(key);
                pos = DAT_011dd014.GetFirstPos();
                existingHandle->FadeOutAndRelease(300);
                delete existingHandle;
                existingHandle = 0;
            }
        }
    }
}

// Switches the sky mode, unloading textures and stopping sounds when leaving full/exterior mode, then updates HDR values.
// @fnv 0x0063a3f0
void Sky::SetMode(Sky::SKY_MODE mode)
{
    if ((eMode == Sky::SM_NONE || eMode == Sky::SM_INTERIOR || eMode == Sky::SM_COUNT) && (mode == Sky::SM_FULL || mode == Sky::SM_FAKEEXTERIOR))
    {
        LoadAllTextures();
        if (m_pClouds)
            m_pClouds->ForceTransTextureUpdate();
        if (static_cast<NiAVObject*>(m_pRootNode))
            static_cast<NiAVObject*>(m_pRootNode)->FUN_00450f90(false);
        if (m_pSun)
            static_cast<const SkyObject*>(m_pSun)->GetRoot()->FUN_00450f90(false);
    }
    else if ((eMode == Sky::SM_FULL || eMode == Sky::SM_FAKEEXTERIOR || eMode == Sky::SM_COUNT) &&
             (mode == Sky::SM_NONE || mode == Sky::SM_INTERIOR))
    {
        UnloadAllTextures();
        if (static_cast<NiAVObject*>(m_pRootNode))
            static_cast<NiAVObject*>(m_pRootNode)->FUN_00450f90(true);
        if (m_pSun)
            static_cast<const SkyObject*>(m_pSun)->GetRoot()->FUN_00450f90(true);
        while (!m_pSkySounds->IsEmpty())
        {
            if (m_pSkySounds->GetItem()->IsPlaying())
                m_pSkySounds->GetItem()->Stop();
            m_pSkySounds->GetItem()->Release();
            delete m_pSkySounds->GetItem();
            m_pSkySounds->RemoveHead();
        }
        DAT_011ccb74 = false;
        eMode = mode;
        if (m_pPrecipitation)
            m_pPrecipitation->Update(0.0f);
        m_fWeatherFade = 0.0f;
    }
    eMode = mode;
    UpdateHDRValues();
}

// @fnv 0x0082d280
bool SoundPlaybackManager::ResolveSoundFile(const char* name, char* path, unsigned int* apuiFlags, void** extra)
{
    if (!name)
        return false;
    TESSound* sound = g_dataHandler->GetSoundByEditorID(name);
    if (sound && sound->TESSound_GetFilename() && path)
    {
        TaskQueueInterface::CopyStringToBuffer(path, 260, sound->TESSound_GetFilename());
    }
    else
    {
        if (g_dataHandler && !g_dataHandler->FUN_004516b0() && g_dataHandler->GetFirstSceneObject())
            Warning("Audio: Could not find TESSound corresponding to form name \"%s\"", name);
        return false;
    }
    if (sound->CopyBig().iFlags & 0x40)
    {
        *apuiFlags |= 1;
        *apuiFlags &= ~2;
    }
    else if (!(*apuiFlags & 1) && !(*apuiFlags & 2))
    {
        *apuiFlags |= 2;
        *apuiFlags &= ~1;
    }
    if (sound->CopyBig().iFlags & 1)
        *apuiFlags |= 0x40;
    if (sound->CopyBig().iFlags & 0x800)
        *apuiFlags |= 0x8000000;
    *apuiFlags |= TESSound::GetPlaybackFlags(sound->CopyBig().iFlags);
    *extra = sound;
    return true;
}

// Returns true if sound is non-null, the audio object exists, and position is within sound->GetField45()*100*scale of the listener position on all axes.
// @fnv 0x0082eca0
bool SoundPlaybackManager::CanPlaySoundAt(TESSound* sound, NiPoint3 position, float scale)
{
    BSAudioListener* m_pAudioListener = static_cast<BSAudioListener*>(TESLandTexture::GetSoundSystem()->GetAudioBackendData());
    if (!sound || !m_pAudioListener)
        return false;
    {
        NiPoint3 kListenerPosition = m_pAudioListener->GetPosition_00aeaad0();
        float fDistance = sound->GetField45() * 100.0 * scale;
        if (std::abs(position.x - kListenerPosition.x) > fDistance ||
            std::abs(position.y - kListenerPosition.y) > fDistance ||
            std::abs(position.z - kListenerPosition.z) > fDistance)
            return false;
    }
    return true;
}

// @fnv 0x0082eb70
void SoundPlaybackManager::ResetAcousticSpace(BGSAcousticSpace* space)
{
    if (DAT_011dcfa7 || (space && space != DAT_011dcfb4) || !DAT_011dcfb4)
        return;
    DAT_011dd0d8.FadeOutAndRelease((unsigned int)(DAT_011dd050.Float()->f * 1000.0));
    DAT_011dd0d8.Clear();
    DAT_011dcfb4 = 0;
    DAT_011dcfb1 = true;
    TESLandTexture::GetSoundSystem()->SetEnvironment(0);
}

// @fnv 0x0082ec60
void SoundPlaybackManager::LoadGame(BGSLoadGameBuffer* buffer)
{
    DAT_011dcfa8 = dynamic_cast<TESSound*>(TESForm::GetFormByID(buffer->ReadFormIdentifier()));
}

// @fnv 0x0082eae0
void SoundPlaybackManager::SetAcousticSpace(BGSAcousticSpace* space)
{
    if (DAT_011dcfb4 == space)
        return;
    DAT_011dd0d8.FadeOutAndRelease((unsigned int)(DAT_011dd050.Float()->f * 1000.0));
    DAT_011dd0d8.Clear();
    if (space)
        TESLandTexture::GetSoundSystem()->SetEnvironment(space->GetField4C());
    DAT_011dcfb4 = space;
    DAT_011dcfb1 = true;
}
// @fnv 0x0082ea80
void PlayerCharacter::ResetRegionSoundTimer()
{
    regionSoundTimer = 0;
}
// @fnv 0x0082eac0
bool PlayerCharacter::IsRegionSoundsEnabled()
{
    return regionSoundsEnabled;
}
// @fnv 0x0082eaa0
BSSimpleList<RegionSound*>* PlayerCharacter::GetRegionSounds()
{
    return &regionSounds;
}

extern TESSound* DAT_011dcfa8;
extern TESDataHandler* g_dataHandler;

// Returns the cached TESSound named "UIActivateNothing", looking it up via g_dataHandler if not yet set.
// @fnv 0x0082ec10
TESSound* __cdecl GetUIActivateNothingSound()
{
    if (DAT_011dcfa8 == 0)
        DAT_011dcfa8 = g_dataHandler->GetSoundByEditorID("UIActivateNothing");
    return DAT_011dcfa8;
}

// @fnv 0x0082ec40
// src: COMMUNITY 0x0082ec40
void TESAudio_SaveGame(BGSSaveFormBuffer* buffer)
{
    buffer->SerializeFormData(DAT_011dcfa8, 0);
}

// @fnv 0x0082ed80
void __cdecl PlayMysteriousStrangerMusic()
{
    BSSoundHandle hndle =
        TESLandTexture::GetSoundSystem()->GetSoundHandleByEditorID("MUSMysteriousStrangerA01", 0x210101);
    hndle.Play(false);
    TESLandTexture::GetSoundSystem()->FUN_00ad7fa0("MUSMysteriousStrangerA02", 0x20200101);
}

// @fnv 0x0082ee10
void __cdecl PlayMysteriousStrangerSound()
{
    BSSoundHandle hndle =
        TESLandTexture::GetSoundSystem()->GetSoundHandleByEditorID("MUSMysteriousStrangerA02", 0x200101);
    hndle.Play(false);
}
