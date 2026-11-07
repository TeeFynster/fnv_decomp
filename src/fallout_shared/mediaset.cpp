#include "../../include/BSStringT.h"
// fallout_shared/mediaset.cpp: MediaSet, MediaSetLoad, MediaSetBattle and more (22 functions)

#include "../../include/MediaSet.h"
#include "../../include/BSAudio.h"
#include "mediaset_decls.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/GO.h"
#include "../../include/Sky.h"
#include "../../include/TES.h"

// @fnv 0x00598a70
void MediaSet::InitItem()
{
    unsigned int formID;
    if (GetInitialized())
        return;

    formID = 0;
    formID = reinterpret_cast<unsigned int>(m_pSound1);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSound1 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!m_pSound1)
            Warning("MASTERFILE: Could not find open sound (%08X) for MediaSet '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    formID = reinterpret_cast<unsigned int>(m_pSound2);
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        m_pSound2 = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!m_pSound2)
            Warning("MASTERFILE: Could not find open sound (%08X) for MediaSet '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    SetInitializationState(true);
}

// Resets six entries, then zeroes two sound members.
// @fnv 0x00599bd0
void MediaSet::ClearData()
{
    m_kMediaSetEntry1.Reset();
    m_kMediaSetEntry2.Reset();
    m_kMediaSetEntry3.Reset();
    m_kMediaSetEntry4.Reset();
    m_kMediaSetEntry5.Reset();
    m_kMediaSetEntry6.Reset();
    m_pSound1 = 0;
    m_pSound2 = 0;
}

// @fnv 0x00599b30
void MediaSet::ResetFormData()
{
    m_kMediaSetEntry1.Reset();
    m_kMediaSetEntry2.Reset();
    m_kMediaSetEntry3.Reset();
    m_kMediaSetEntry4.Reset();
    m_kMediaSetEntry5.Reset();
    m_kMediaSetEntry6.Reset();
    m_fMediaParameter1 = 0.0f;
    fSkillValueBonus = 0.0f;
    m_fMediaParameter3 = 0.0f;
    m_fMediaValue = 0.0f;
    m_pSound1 = 0;
    m_pSound2 = 0;
}

// @fnv 0x00597990
bool MediaSet::Update(unsigned int time, bool force, MediaLocationController* controller)
{
    if (controller)
    {
        switch (Type)
        {
        case LAYER_LOCATION:
            return UpdateLayerLocation(time, force, controller);
            break;
        case LAYER_DUNGEON:
            return PointLocation(time, force, controller);
            break;
        case BATTLE:
            return UpdateBattleState(force, time, 4);
        }
    }
    else if (!controller && Type == INCIDENTAL)
    {
        if (DAT_011ca9fc > time)
            return true;
        UpdateIncidental(time);
    }
    else if (!controller && Type == BATTLE)
    {
        return UpdateBattleState(force, time, 4);
    }
    return false;
}

// @fnv 0x00597610
MediaSet::MediaSet()
{
    SetFormType(ENUM_FORM_ID_MSET_ID);
    Type = static_cast<MEDIASETTYPE>(-1);
    m_kMediaSetEntry1.Reset();
    m_kMediaSetEntry2.Reset();
    m_kMediaSetEntry3.Reset();
    m_kMediaSetEntry4.Reset();
    m_kMediaSetEntry5.Reset();
    m_kMediaSetEntry6.Reset();
    m_fMediaParameter1 = 0.0f;
    fSkillValueBonus = 0.0f;
    m_fMediaParameter3 = 0.0f;
    m_fMediaValue = 0.0f;
    m_pSound1 = 0;
    m_pSound2 = 0;
    DAT_011ca9fc = 0;
    m_uiMediaValue3 = 0;
    m_uiMediaValue2 = 0;
    bEffectFlag = false;
    m_bActorStateFlag = false;
    m_bConditionWasTrue = false;
    m_cMediaState = 0;
}

// Selects an incidental media layer for the controller based on scale and layer percentages, then starts or stops playback and updates cached state.
// @fnv 0x00597a60
bool MediaSet::UpdateLayerLocation(unsigned int time, bool force, MediaLocationController* controller)
{
    bool bReturn;
    bool bPlaying = FalloutAudioMedia::IsMediaPlaying(MEDIATYPE_MEDIA_LOCATION, false);
    bReturn = true;
    char cLayer = 0;
    if (force)
    {
        return false;
    }
    else
    {
        bool a;  // Restart after the previous incidental reaches its fade window.
        unsigned int fMinPercent = FalloutAudioMedia_MediaGetSubDuration(MEDIATYPE_MEDIA_LOCATION);
        a = false;
        if (m_uiMediaValue3 && fMinPercent && time > m_uiMediaValue3 + fMinPercent - m_fMediaParameter3 * 1000.0)
        {
            FalloutAudioMedia::FadeOutMedia(static_cast<int>(m_fMediaParameter3 * 1000.0), MEDIATYPE_MEDIA_LOCATION);
            m_uiMediaValue3 = time;
            if (!controller->GetLoop())
                a = true;
            else
                return false;
        }
        float fNormalizedPosition = reinterpret_cast<TESObjectREFR*>(controller)->GetScale() * 100.0;
        float m_uiPlaybackFlags = 1000.0f;  // Lowest eligible layer percentage.
        if (controller->GetByteAtOffset55())
        {
            if ((m_cMediaFlag & 1) && m_kMediaSetEntry1.Percent > fNormalizedPosition &&
                m_kMediaSetEntry1.Percent < m_uiPlaybackFlags)
            {
                cLayer = 1;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry1.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry1.Percent;
            }
            if ((m_cMediaFlag & 2) && m_kMediaSetEntry2.Percent > fNormalizedPosition &&
                m_kMediaSetEntry2.Percent < m_uiPlaybackFlags)
            {
                cLayer = 2;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry2.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry2.Percent;
            }
            if ((m_cMediaFlag & 4) && m_kMediaSetEntry3.Percent > fNormalizedPosition &&
                m_kMediaSetEntry3.Percent < m_uiPlaybackFlags)
            {
                cLayer = 3;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry3.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry3.Percent;
            }
        }
        else
        {
            if ((m_cMediaFlag & 8) && m_kMediaSetEntry4.Percent > fNormalizedPosition &&
                m_kMediaSetEntry4.Percent < m_uiPlaybackFlags)
            {
                cLayer = 1;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry4.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry4.Percent;
            }
            if ((m_cMediaFlag & 16) && m_kMediaSetEntry5.Percent > fNormalizedPosition &&
                m_kMediaSetEntry5.Percent < m_uiPlaybackFlags)
            {
                cLayer = 2;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry5.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry5.Percent;
            }
            if ((m_cMediaFlag & 32) && m_kMediaSetEntry6.Percent > fNormalizedPosition &&
                m_kMediaSetEntry6.Percent < m_uiPlaybackFlags)
            {
                cLayer = 3;
                m_uiPlaybackFlags =
                    m_kMediaSetEntry6.Percent > m_uiPlaybackFlags ? m_uiPlaybackFlags : m_kMediaSetEntry6.Percent;
            }
        }
        if (!(bPlaying && m_bActorStateFlag == force && m_bConditionWasTrue == controller->GetByteAtOffset55() &&
              m_cMediaState == cLayer) &&
                DAT_011dd37c < time ||
            a)
        {
            MediaSetEntry* pLayer = 0;
            if (controller->GetByteAtOffset55())
            {
                switch (cLayer)
                {
                case 1:
                    pLayer = &m_kMediaSetEntry1;
                    break;
                case 2:
                    pLayer = &m_kMediaSetEntry2;
                    break;
                case 3:
                    pLayer = &m_kMediaSetEntry3;
                }
            }
            else
            {
                switch (cLayer)
                {
                case 1:
                    pLayer = &m_kMediaSetEntry4;
                    break;
                case 2:
                    pLayer = &m_kMediaSetEntry5;
                    break;
                case 3:
                    pLayer = &m_kMediaSetEntry6;
                }
            }
            if (pLayer)
            {
                DAT_011dd37c = static_cast<unsigned int>(time + m_fMediaParameter1 * 1000.0);
                unsigned int uiElapsedMilliseconds = 0;
                if (FalloutAudioMedia_MediaGetPosition(MEDIATYPE_MEDIA_LOCATION) && !a)
                    uiElapsedMilliseconds = time - FalloutAudioMedia_MediaGetPosition(MEDIATYPE_MEDIA_LOCATION);
                FalloutAudioMedia::PlayMedia(
                    MEDIATYPE_MEDIA_LOCATION,
                    reinterpret_cast<const char*>(reinterpret_cast<const NiPointer<NiNode>*>(pLayer)->operator->()),
                    static_cast<unsigned int>(m_fMediaParameter3 * 1000.0), !controller->GetLoop(), true,
                    pLayer->Attenuation, uiElapsedMilliseconds);
                FalloutAudioMedia::EndMediaUpdate();
                m_uiMediaValue3 = time;
            }
            else
            {
                if (bPlaying)
                    FalloutAudioMedia::FadeOutMedia(static_cast<int>(m_fMediaParameter3 * 1000.0), MEDIATYPE_MEDIA_LOCATION);
                bReturn = false;
            }
            m_bActorStateFlag = force;
            m_bConditionWasTrue = controller->GetByteAtOffset55();
            m_cMediaState = cLayer;
        }
    }
    return bReturn;
}

extern float const runtimeFloatSettingDefault313;

// Clears the name and restores the attenuation and percentage defaults.
// @fnv 0x00597850
void MediaSetEntry::Reset()
{
    Name.Set(0, 0);
    Attenuation = runtimeFloatSettingDefault313;
    Percent = 100.0f;
}

// @fnv 0x007d9ec0
// src: GUESS 0x007d9ec0 (confidence: medium)
void __fastcall BSStringT_BSStringT_Thunk(BSStringT<char>* apString)
{
    apString->BSStringT<char>::~BSStringT<char>();
}

extern "C" void* __cdecl _alloca(unsigned int);



struct MediaSetLoad : public MediaSet
{
    bool MediaSet_Load(TESFile* apFile);
};

// Reads a MediaSet record from the file, handling EDID, OBND, FULL, type, name, attenuation, percent, sound and float chunks, then returns true.
// @fnv 0x00598bc0
// src: XBOX_PDB 0x00598bc0
bool MediaSetLoad::MediaSet_Load(TESFile* apFile)
{
    unsigned int itempint = 0;
    int chunkid;

    LoadRecordHeader(apFile);
    SetInitializationState(false);

    while ((chunkid = (int)apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 'DIDE': {
            char* pMessage = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pMessage, 0x200);
            SetEditorID_AtRuntime(pMessage);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(apFile);
            break;
        case 'LLUF':
            TESFullName::LoadFullNameChunk(this, apFile);
            break;
        case '1MAN':
            apFile->GetChunkData(&itempint);
            Type = (MEDIASETTYPE)itempint;
            break;
        case '2MAN':
        case '3MAN':
        case '4MAN':
        case '5MAN':
        case '6MAN':
        case '7MAN': {
            char* pMessage = 0;
            float tF = 0.0f;
            unsigned int cSize = apFile->GetChunkSize();
            if (cSize)
            {
                pMessage = (char*)_alloca(apFile->GetChunkSize());
                apFile->GetChunkData(pMessage, 0);
                ::BSStringT<char> stemp("Data\\Music\\");
                stemp += pMessage;
                switch (chunkid)
                {
                case '2MAN':
                    ((::BSStringT<char>*)&m_kMediaSetEntry1.Name)->Set(stemp);
                    break;
                case '3MAN':
                    ((::BSStringT<char>*)&m_kMediaSetEntry2.Name)->Set(stemp);
                    break;
                case '4MAN':
                    ((::BSStringT<char>*)&m_kMediaSetEntry3.Name)->Set(stemp);
                    break;
                case '5MAN':
                    ((::BSStringT<char>*)&m_kMediaSetEntry4.Name)->Set(stemp);
                    break;
                case '6MAN':
                    ((::BSStringT<char>*)&m_kMediaSetEntry5.Name)->Set(stemp);
                    break;
                case '7MAN':
                    ((::BSStringT<char>*)&m_kMediaSetEntry6.Name)->Set(stemp);
                    break;
                }
            }
            break;
        }
        case '8MAN':
        case '9MAN':
        case '0MAN':
        case 'MANA':
        case 'MANB':
        case 'MANC': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case '8MAN':
                m_kMediaSetEntry1.Attenuation = tF;
                break;
            case '9MAN':
                m_kMediaSetEntry2.Attenuation = tF;
                break;
            case '0MAN':
                m_kMediaSetEntry3.Attenuation = tF;
                break;
            case 'MANA':
                m_kMediaSetEntry4.Attenuation = tF;
                break;
            case 'MANB':
                m_kMediaSetEntry5.Attenuation = tF;
                break;
            case 'MANC':
                m_kMediaSetEntry6.Attenuation = tF;
                break;
            }
            break;
        }
        case 'MANJ':
        case 'MANK':
        case 'MANL':
        case 'MANM':
        case 'MANN':
        case 'MANO': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case 'MANJ':
                m_kMediaSetEntry1.Percent = tF;
                break;
            case 'MANK':
                m_kMediaSetEntry2.Percent = tF;
                break;
            case 'MANL':
                m_kMediaSetEntry3.Percent = tF;
                break;
            case 'MANM':
                m_kMediaSetEntry4.Percent = tF;
                break;
            case 'MANN':
                m_kMediaSetEntry5.Percent = tF;
                break;
            case 'MANO':
                m_kMediaSetEntry6.Percent = tF;
                break;
            }
            break;
        }
        case 'MANP':
            ReadTypedData(apFile, &m_cMediaFlag, 1);
            break;
        case 'MAND':
        case 'MANE':
        case 'MANF':
        case 'MANG': {
            float tF = 0.0f;
            apFile->GetChunkData((unsigned int*)&tF);
            switch (chunkid)
            {
            case 'MAND':
                m_fMediaParameter1 = tF;
                break;
            case 'MANE':
                fSkillValueBonus = tF;
                break;
            case 'MANF':
                m_fMediaParameter3 = tF;
                break;
            case 'MANG':
                m_fMediaValue = tF;
                break;
            }
            break;
        }
        case 'MANH':
        case 'MANI': {
            unsigned int itempint = 0;
            apFile->GetChunkData(&itempint);
            switch (chunkid)
            {
            case 'MANH':
                m_pSound1 = (TESSound*)itempint;
                break;
            case 'MANI':
                m_pSound2 = (TESSound*)itempint;
                break;
            }
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00598000
// src: COMMUNITY 0x00598000
int MediaLocationController::GetLoop()
{
    return (iFlags >> 4) & 3;
}

struct MediaSetLifetime
{
    void* Destroy(unsigned int flags);
};
void _Deallocate(void*);
// Destroys the media set, optionally deallocates it, and returns its address.
// @fnv 0x00597880
void* MediaSetLifetime::Destroy(unsigned int flags)
{
    reinterpret_cast<MediaSet*>(this)->MediaSet::~MediaSet();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct UnnamedStr
{
    int _00;
    int _04;
    void __thiscall AssignFromString(const UnnamedStr&);
};
// Operations absent from the shared MediaSetEntry declaration use a stateless
// adapter; all storage and offsets come from MediaSetEntry.
struct MediaSetEntryOperations
{
    MediaSetEntry* CopyConstruct(const MediaSetEntry& other);
};

// @fnv 0x00599780
MediaSetEntry* MediaSetEntryOperations::CopyConstruct(const MediaSetEntry& other)
{
    reinterpret_cast<UnnamedStr*>(this)->AssignFromString(*reinterpret_cast<const UnnamedStr*>(&other.Name));
    reinterpret_cast<MediaSetEntry*>(this)->Attenuation = other.Attenuation;
    reinterpret_cast<MediaSetEntry*>(this)->Percent = other.Percent;
    return reinterpret_cast<MediaSetEntry*>(this);
}

struct S7010 : GO
{
    unsigned int Length();
};

struct MediaFormWriter
{
    void Finish();
};

void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);
void __cdecl _FUN_00485910(unsigned int, unsigned int);
void __cdecl _FUN_00485910(unsigned int, float);

// @fnv 0x005991b0
void MediaSet::SaveMediaSet()
{
    TESForm::BeginFormRecord();
    TESFullName::Save_00487010();

    _FUN_00485910(0x314d414e, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x44));

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)->Length() > 0)
    {
        TESForm_AddChunkArray(0x324d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<const GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x48)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)->Length() > 0)
    {
        TESForm_AddChunkArray(0x334d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<const GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x58)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)->Length() > 0)
    {
        TESForm_AddChunkArray(0x344d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<const GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x68)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)->Length() > 0)
    {
        TESForm_AddChunkArray(0x354d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<const GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x78)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)->Length() > 0)
    {
        TESForm_AddChunkArray(0x364d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<const GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x88)->Length() + 1);
    }

    if (reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)->Length() > 0)
    {
        TESForm_AddChunkArray(0x374d414e,
                     reinterpret_cast<void*>(static_cast<unsigned int>(
                         *reinterpret_cast<const GO*>(reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)))),
                     reinterpret_cast<S7010*>(reinterpret_cast<char*>(this) + 0x98)->Length() + 1);
    }

    _FUN_00485910(0x384d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x50));
    _FUN_00485910(0x394d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x60));
    _FUN_00485910(0x304d414e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x70));
    _FUN_00485910(0x4d414e41, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x80));
    _FUN_00485910(0x4d414e42, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x90));
    _FUN_00485910(0x4d414e43, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xa0));
    _FUN_00485910(0x4d414e4a, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x54));
    _FUN_00485910(0x4d414e4b, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x64));
    _FUN_00485910(0x4d414e4c, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x74));
    _FUN_00485910(0x4d414e4d, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x84));
    _FUN_00485910(0x4d414e4e, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x94));
    _FUN_00485910(0x4d414e4f, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xa4));

    TESForm_AddChunk_3(0x4d414e50, *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0xa8));

    _FUN_00485910(0x4d414e44, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xac));
    _FUN_00485910(0x4d414e45, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb0));
    _FUN_00485910(0x4d414e46, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb4));
    _FUN_00485910(0x4d414e47, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xb8));

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xbc))
    {
        _FUN_00485910(0x4d414e48,
                      reinterpret_cast<TESSound*>(*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xbc))
                          ->GetFormID());
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xc0))
    {
        _FUN_00485910(0x4d414e49,
                      reinterpret_cast<TESSound*>(*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0xc0))
                          ->GetFormID());
    }

    reinterpret_cast<MediaFormWriter*>(this)->Finish();
    TESForm::FinishFormRecord();
}

// @fnv 0x005978b0
MediaSet::~MediaSet()
{}

float __fastcall Sky_GetSunriseBegin(void* apSky);
float __fastcall Sky_GetSunsetEnd(void* apSky);

extern TES* g_TES;

unsigned int GetRandomNumberInRange(int aiMin, int aiMax);

struct MediaSetBattle : public MediaSet
{
    bool UpdateBattleMusic(unsigned int auiTime);
};

// @fnv 0x00598890
bool MediaSetBattle::UpdateBattleMusic(unsigned int auiTime)
{
    if (auiTime <= DAT_011ca9fc)
    {
        return true;
    }
    Sky* pWeatherSky = g_TES->GetSky();
    bool m_bConditionWasTrue = pWeatherSky ? (Sky_GetSunriseBegin(pWeatherSky) <= pWeatherSky->GetFieldEC() &&
                                              pWeatherSky->GetFieldEC() <= Sky_GetSunsetEnd(pWeatherSky))
                                           : true;
    if (m_bConditionWasTrue)
    {
        BSAudio::GetSingleton()->GetSoundHandleByFormID(m_pSound1->GetFormID(), 0x901).Play(false);
        DAT_011ca9fc =
            GetRandomNumberInRange((int)(m_fMediaParameter1 * 1000.0), (int)(m_fMediaParameter3 * 1000.0)) + auiTime;
    }
    else
    {
        BSAudio::GetSingleton()->GetSoundHandleByFormID(m_pSound2->GetFormID(), 0x901).Play(false);
        DAT_011ca9fc =
            GetRandomNumberInRange((int)(fSkillValueBonus * 1000.0), (int)(m_fMediaValue * 1000.0)) + auiTime;
    }
    return true;
}

struct MediaLayerData : MediaSetEntry
{
    MediaLayerData(const MediaLayerData& arOther);
    ~MediaLayerData();
    void SetLayer(MediaLayerData arLayer);
};

struct MediaSetBaseCopy
{
    void CopyBase(TESForm* apForm);
};

// 0x00599550 copies MediaSet fields; its missing shared declaration needs only a storage-free thiscall adapter.
struct MediaFormCopyOperation
{
    void CopyFrom(TESForm* apForm);
};

// Copies Type, six layer entries and several scalar fields from another MediaSet, then calls CopyBase.
// @fnv 0x00599550
void MediaFormCopyOperation::CopyFrom(TESForm* apForm)
{
    MediaSet* pOther = dynamic_cast<MediaSet*>(apForm);
    if (!pOther)
        return;
    reinterpret_cast<MediaSet*>(this)->Type = pOther->Type;
    ((MediaLayerData*)&reinterpret_cast<MediaSet*>(this)->m_kMediaSetEntry1)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry1);
    ((MediaLayerData*)&reinterpret_cast<MediaSet*>(this)->m_kMediaSetEntry2)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry2);
    ((MediaLayerData*)&reinterpret_cast<MediaSet*>(this)->m_kMediaSetEntry3)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry3);
    ((MediaLayerData*)&reinterpret_cast<MediaSet*>(this)->m_kMediaSetEntry4)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry4);
    ((MediaLayerData*)&reinterpret_cast<MediaSet*>(this)->m_kMediaSetEntry5)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry5);
    ((MediaLayerData*)&reinterpret_cast<MediaSet*>(this)->m_kMediaSetEntry6)->SetLayer(*(MediaLayerData*)&pOther->m_kMediaSetEntry6);
    reinterpret_cast<MediaSet*>(this)->m_cMediaFlag = pOther->m_cMediaFlag;
    reinterpret_cast<MediaSet*>(this)->m_fMediaParameter1 = pOther->m_fMediaParameter1;
    reinterpret_cast<MediaSet*>(this)->fSkillValueBonus = pOther->fSkillValueBonus;
    reinterpret_cast<MediaSet*>(this)->m_fMediaParameter3 = pOther->m_fMediaParameter3;
    reinterpret_cast<MediaSet*>(this)->m_fMediaValue = pOther->m_fMediaValue;
    reinterpret_cast<MediaSet*>(this)->m_pSound1 = pOther->m_pSound1;
    reinterpret_cast<MediaSet*>(this)->m_pSound2 = pOther->m_pSound2;
    ((MediaSetBaseCopy*)this)->CopyBase(pOther);
}

// local form of BSStringT<char>: 0x00599700 needs the 0x007d9ec0 destructor wrapper and dummy-argument accessor; shared replacement changes bytes.
struct TextValue
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    TextValue* Modelloader_GetReferencedThis(int flag);
    ~TextValue();
};
struct StringRecord
{
    void FUN_004037f0(TextValue*);
    void SetValues(TextValue value, float firstValue, float secondValue);
};
// @fnv 0x00599700
void StringRecord::SetValues(TextValue aTextValue, float afFirst, float afSecond)
{
    FUN_004037f0(aTextValue.Modelloader_GetReferencedThis(0));
    reinterpret_cast<MediaSetEntry*>(this)->Attenuation = afFirst;
    reinterpret_cast<MediaSetEntry*>(this)->Percent = afSecond;
}

struct LayerInfo : MediaSetEntry
{

    const char* __thiscall Modelloader_GetReferencedThis(unsigned int index);
    int __thiscall FUN_00408a80(const char* text);
    bool __thiscall EvaluateValue_00599a50(LayerInfo other);
};
// @fnv 0x00599a50
// src: GUESS 0x00599a50 (confidence: low)
bool LayerInfo::EvaluateValue_00599a50(LayerInfo other)
{
    if (Attenuation != other.Attenuation)
        return true;
    if (Percent != other.Percent)
        return true;
    if (FUN_00408a80(other.Modelloader_GetReferencedThis(0)))
        return false;
    return true;
}

struct MediaSetNameHolder : public TESForm, public TESFullName
{
    virtual ~MediaSetNameHolder();
};

// @fnv 0x00599d00
MediaSetNameHolder::~MediaSetNameHolder()
{}

bool __fastcall GetControllerCondition(MediaLocationController* controller);
bool __cdecl FalloutAudioMedia_MediaIsPlaying(unsigned long, bool);
unsigned int __cdecl FalloutAudioMedia_MediaGetDuration(unsigned long);
void __cdecl StartFade(int, int);
void __cdecl PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
void __cdecl FUN_008304c0();
extern unsigned int DAT_011ca9fc;

// @fnv 0x00598060
bool MediaSet::PointLocation(unsigned int auiTime, bool abEnabled, MediaLocationController* apCtrl)
{
    bool flagDTmp;
    bool retVal;
    unsigned int local7;
    bool b2;
    bool b4;
    MediaSetEntry* ptrLocal;
    int local4;
    b2 = FalloutAudioMedia_MediaIsPlaying(3, true);
    retVal = true;
    b4 = reinterpret_cast<TESObjectREFR*>(apCtrl)->GetScale() < 100.0;
    if (this->m_bActorStateFlag == 0 && abEnabled)
    {
        DAT_011dd37c = 0;
    }
    local7 = FalloutAudioMedia_MediaGetDuration(2);
    flagDTmp = false;
    if (this->m_uiMediaValue3 != 0 && local7 != 0)
    {
        if ((double)auiTime > (double)(unsigned int)(this->m_uiMediaValue3 + local7) - this->m_fMediaParameter3 * 1000.0)
        {
            StartFade((int)(this->m_fMediaParameter3 * 1000.0), 2);
            this->m_uiMediaValue3 = auiTime;
            if (apCtrl->GetLoop() == 0)
            {
                flagDTmp = true;
            }
            else
            {
                return false;
            }
        }
    }
    if (!((b2 && this->m_bActorStateFlag == abEnabled && this->m_bCountWasNonzero == GetControllerCondition(apCtrl) &&
           ((char)this->m_cMediaState == (char)b4 || (char)this->m_cMediaState != 0)) ||
          DAT_011dd37c >= auiTime) ||
        flagDTmp)
    {
    body:
        ptrLocal = 0;
        if (abEnabled)
        {
            if (this->m_pSound1 != 0 && !this->bEffectFlag)
            {
                BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0((int)this->m_pSound1->TESForm::GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0x901).Play(false);
            }
            ptrLocal = &this->m_kMediaSetEntry1;
            this->bEffectFlag = 1;
        }
        else if (GetControllerCondition(apCtrl))
        {
            if (this->bEffectFlag && this->m_pSound2 != 0)
            {
                BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0((int)this->m_pSound2->TESForm::GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0x901).Play(false);
            }
            ptrLocal = &this->m_kMediaSetEntry3;
            this->bEffectFlag = 0;
        }
        else
        {
            if (this->bEffectFlag && this->m_pSound2 != 0)
            {
                BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0((int)this->m_pSound2->TESForm::GetHavokWorldObjectCountInSceneGraph_0084e3a0(), 0x901).Play(false);
            }
            ptrLocal = &this->m_kMediaSetEntry2;
            this->bEffectFlag = 0;
        }
        if (ptrLocal != 0)
        {
            DAT_011dd37c = auiTime;
            if (!abEnabled)
            {
                DAT_011dd37c = (unsigned int)(this->m_fMediaParameter1 * 1000.0 + (double)DAT_011dd37c);
            }
            local4 = 0;
            if (FalloutAudioMedia_MediaGetPosition((MEDIATYPE)3) != 0 && !flagDTmp)
            {
                local4 = auiTime - FalloutAudioMedia_MediaGetPosition((MEDIATYPE)3);
            }
            if (ptrLocal == &this->m_kMediaSetEntry1)
            {
                PlayAudioMedia(3, ptrLocal->Name.String(), 1000, true, true, ptrLocal->Attenuation, (unsigned int)local4);
            }
            else
            {
                PlayAudioMedia(3, ptrLocal->Name.String(), (unsigned int)(this->m_fMediaParameter3 * 1000.0), true, true,
                               ptrLocal->Attenuation, (unsigned int)local4);
            }
            FUN_008304c0();
        }
        else
        {
            StartFade((int)(this->m_fMediaParameter3 * 1000.0), 3);
            retVal = false;
        }
        this->m_bActorStateFlag = abEnabled;
        this->m_bCountWasNonzero = GetControllerCondition(apCtrl);
        this->m_cMediaState = b4;
    }
    else
    {
        if ((char)b4 == 0)
        {
            if (auiTime > DAT_011ca9fc)
            {
                if (this->bEffectFlag == 0)
                {
                    if (b2)
                    {
                        StartFade((int)(this->m_fMediaParameter3 * 1000.0), 3);
                    }
                    retVal = false;
                }
            }
        }
    }
    return retVal;
}

namespace fnv_00598550 {
struct DungeonController
{
    void FUN_007037c0(unsigned int);
};
extern DungeonController* DAT_011dd374;
bool FalloutAudioMedia_MediaIsPlaying(unsigned long, bool);
unsigned int FalloutAudioMedia_MediaGetDuration(unsigned long);
void FalloutAudioMedia_MediaPause();
void ResetThreadFlags();
void StartFade(int, int);
struct DungeonMediaSet : MediaSet
{
    bool UpdatePlayback(bool active, unsigned int time, int mediaType);
};
// Starts, refreshes or fades the media set's audio based on active, time and mediaType, updating DAT_011ca9fc and the playing flag.
// @fnv 0x00598550
bool DungeonMediaSet::UpdatePlayback(bool active, unsigned int time, int mediaType)
{
    bool changed;
    if (active)
    {
        changed = false;
        bool playing = FalloutAudioMedia_MediaIsPlaying(mediaType, false);
        if (!playing && !bEffectFlag)
        {
            if (m_pSound1 && !bEffectFlag)
                BSAudio::GetSingleton()->GetSoundHandleByFormID(m_pSound1->GetFormID(), 0x901).Play(false);
            DAT_011ca9fc = time - 1;
            bEffectFlag = true;
            FalloutAudioMedia::PlayMedia((MEDIATYPE)mediaType, m_kMediaSetEntry1.Name.String(),
                                         (unsigned int)(fSkillValueBonus * 1000.0), true, true,
                                         m_kMediaSetEntry1.Attenuation, 0);
            FalloutAudioMedia::EndMediaUpdate();
            FalloutAudioMedia_MediaPause();
        }
        if (time > DAT_011ca9fc + m_fMediaParameter1)
        {
            ResetThreadFlags();
            bEffectFlag = true;
        }
        unsigned int length = FalloutAudioMedia_MediaGetDuration(mediaType);
        if (length && time > DAT_011ca9fc + length - 1000)
        {
            FalloutAudioMedia::PlayMedia((MEDIATYPE)mediaType, m_kMediaSetEntry1.Name.String(),
                                         (unsigned int)(fSkillValueBonus * 1000.0), true, true,
                                         m_kMediaSetEntry1.Attenuation, 0);
            FalloutAudioMedia::EndMediaUpdate();
            DAT_011ca9fc = time;
        }
    }
    else
    {
        bool fading = false;
        if (FalloutAudioMedia_MediaIsPlaying(mediaType, false) && bEffectFlag)
        {
            fading = true;
            StartFade((int)(fSkillValueBonus * 1000.0), mediaType);
        }
        if (fading)
        {
            if (m_pSound2)
                BSAudio::GetSingleton()->GetSoundHandleByFormID(m_pSound2->GetFormID(), 0x901).Play(false);
            DAT_011ca9fc = time + m_fMediaParameter3 * 1000.0;
            if (DAT_011dd374)
                DAT_011dd374->FUN_007037c0(DAT_011ca9fc);
            bEffectFlag = false;
        }
    }
    return active;
}
}  // namespace fnv_00598550

struct MediaLayerCompare
{
    bool EvaluateValue_00599a50(MediaLayerData other);
};
struct MediaFormCompare
{
    bool TESForm_CompareAllComponents(TESForm* other);
};
struct MediaSetCompare : MediaSet
{
    bool IsDifferentFrom(TESForm* form);
};

// Compares this MediaSet with form cast to MediaSet: returns true if any layer, scalar field or base comparison differs.
// @fnv 0x005997c0
bool MediaSetCompare::IsDifferentFrom(TESForm* form)
{
    MediaSet* other = dynamic_cast<MediaSet*>(form);
    if (!other)
        return true;
    if (other->Type != Type)
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry1)
            ->EvaluateValue_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry1)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry2)
            ->EvaluateValue_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry2)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry3)
            ->EvaluateValue_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry3)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry4)
            ->EvaluateValue_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry4)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry5)
            ->EvaluateValue_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry5)))
        return true;
    if (reinterpret_cast<MediaLayerCompare*>(&m_kMediaSetEntry6)
            ->EvaluateValue_00599a50(*reinterpret_cast<MediaLayerData*>(&other->m_kMediaSetEntry6)))
        return true;
    if (m_cMediaFlag != other->m_cMediaFlag)
        return true;
    if (m_fMediaParameter1 != other->m_fMediaParameter1)
        return true;
    if (fSkillValueBonus != other->fSkillValueBonus)
        return true;
    if (m_fMediaParameter3 != other->m_fMediaParameter3)
        return true;
    if (m_fMediaValue != other->m_fMediaValue)
        return true;
    if (m_pSound1 != other->m_pSound1)
        return true;
    if (m_pSound2 != other->m_pSound2)
        return true;
    if (reinterpret_cast<MediaFormCompare*>(this)->TESForm_CompareAllComponents(other))
        return true;
    return false;
}
