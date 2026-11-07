// fallout_shared/medialocationcontroller.cpp: MediaLocationController, MediaSetEntry, FormStub_cls, MLCFullName_cls and more (25 functions)

#include "layout_support.h"
#include "../../include/TESClimate.h"
#include "../../include/TESDataHandler.h"
// Use the shared form bases in the remaining unit-local headers.
#define FNV_BASEFORMCOMPONENT_H
#define FNV_TESFORM_H
#include "medialocationcontroller_update_decls.h"
#include "medialocationcontroller.h"
#include "mediaset.h"

unsigned int __cdecl GetRandomNumberInRange(int aiMin, int aiMax);
int __cdecl Warning(const char* apFormat, ...);
extern TESDataHandler* g_dataHandler;

// @fnv 0x005974f0
void MediaLocationController::ResetFormData()
{
    m_fLowerWeightThreshold = 0.33f;
    m_fUpperWeightThreshold = 0.66f;
    m_fUpdateInterval = 60.0f;
    m_uiShortDelay = 0x40;
    m_uiLongDelay = 0x150;
    m_kMediaSetList1.RemoveAll();
    m_kMediaSetList2.RemoveAll();
    m_kMediaSetList3.RemoveAll();
    m_kMediaSetList4.RemoveAll();
    m_kMediaSetList5.RemoveAll();
    m_kMediaSetList6.RemoveAll();
    pFaction = 0;
    m_eRequiredFightReaction = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
    m_pReference = 0;
}

// Removes all entries from the six member containers of MediaLocationController.
// @fnv 0x005975b0
void MediaLocationController::ClearData()
{
    m_kMediaSetList1.RemoveAll();
    m_kMediaSetList2.RemoveAll();
    m_kMediaSetList3.RemoveAll();
    m_kMediaSetList4.RemoveAll();
    m_kMediaSetList5.RemoveAll();
    m_kMediaSetList6.RemoveAll();
}

// @fnv 0x005977d0
MediaSetEntry::MediaSetEntry()
{
    Name.Set(0, 0);
    Attenuation = -12.0f;
    Percent = 100.0f;
}

// @fnv 0x005962e0
void MediaLocationController::InitItem()
{
    if (IsFormInitialized())
        return;
    ProcessMediaSetList(&m_kMediaSetList1);
    ProcessMediaSetList(&m_kMediaSetList2);
    ProcessMediaSetList(&m_kMediaSetList3);
    ProcessMediaSetList(&m_kMediaSetList4);
    ProcessMediaSetList(&m_kMediaSetList5);
    ProcessMediaSetList(&m_kMediaSetList6);
    if (pFaction)
    {
        unsigned int auiFormId = reinterpret_cast<unsigned int>(pFaction);
        TESForm::RemapFormIDForFile(auiFormId, GetFile(-1));
        pFaction = g_dataHandler->GetFactionByFormID(auiFormId);
        if (!pFaction)
            Warning("MASTERFILE: Could not find reputation (%08X) for MediaLocationController", pFaction);
    }
    SetInitializationState(true);
}

// Walks a list of MediaSet form IDs, resolves each via TESForm lookup, warns and removes entries that fail to resolve.
// @fnv 0x00596190
void MediaLocationController::ProcessMediaSetList(BSSimpleList<MediaSet*>* apList)
{
    BSSimpleList<MediaSet*>* pPrevNode = 0;
    while (apList && !apList->IsEmpty())
    {
        unsigned int auiFormId = reinterpret_cast<unsigned int>(apList->GetItem());
        TESForm::RemapFormIDForFile(auiFormId, GetFile(-1));
        MediaSet* pMediaSet = dynamic_cast<MediaSet*>(TESForm::GetFormByID(auiFormId));
        if (!pMediaSet)
        {
            BSStringT<char> strName;
            GetDebugName(&strName);
            Warning("MASTERFILE: Could not find MediaSet (%08X) for %s.", auiFormId, strName.String());
            if (pPrevNode)
            {
                pPrevNode->Remove(reinterpret_cast<MediaSet*>(auiFormId));
                apList = pPrevNode->GetNext();
            }
            else
                apList->RemoveHead();
        }
        else
        {
            apList->SetItem(pMediaSet);
            pPrevNode = apList;
            apList = apList->GetNext();
        }
    }
}

// @fnv 0x005963d0
bool MediaLocationController::LoadForm(TESFile* apFile)
{
    unsigned int auiFormId = 0;
    LoadRecordHeader(apFile);
    SetInitializationState(false);
    CHUNK_ID eChunk;
    while ((eChunk = static_cast<CHUNK_ID>(apFile->GetChunkID())) != 0)
    {
        switch (eChunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* pEditorID = static_cast<char*>(_alloca(apFile->GetChunkSize()));
            apFile->GetChunkData(pEditorID, 512);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(apFile);
            break;
        case CHUNK_ID_FULL_ID:
            TESFullNameLoader::LoadFullNameChunk(this, apFile);
            break;
        case CHUNK_ID_NAM1_ID:
            apFile->GetChunkData(reinterpret_cast<unsigned int*>(&iFlags));
            break;
        case CHUNK_ID_NAM2_ID:
            apFile->GetChunkData(reinterpret_cast<unsigned int*>(&m_fLowerWeightThreshold));
            break;
        case CHUNK_ID_NAM3_ID:
            apFile->GetChunkData(reinterpret_cast<unsigned int*>(&m_fUpperWeightThreshold));
            break;
        case CHUNK_ID_NAM4_ID:
            apFile->GetChunkData(reinterpret_cast<unsigned int*>(&m_fUpdateInterval));
            break;
        case CHUNK_ID_NAM5_ID:
            apFile->GetChunkData(&m_uiShortDelay);
            break;
        case CHUNK_ID_NAM6_ID:
            apFile->GetChunkData(&m_uiLongDelay);
            break;
        case CHUNK_ID_NAM7_ID:
            apFile->GetChunkData(reinterpret_cast<unsigned int*>(&m_fMediaSelectionValue));
            break;
        case CHUNK_ID_HNAM_ID: {
            apFile->GetChunkData(&auiFormId);
            m_kMediaSetList1.AddHead(
                const_cast<MediaSet*&>(static_cast<MediaSet* const&>(reinterpret_cast<MediaSet*>(auiFormId))));
            break;
        }
        case CHUNK_ID_ZNAM_ID: {
            apFile->GetChunkData(&auiFormId);
            m_kMediaSetList2.AddHead(
                const_cast<MediaSet*&>(static_cast<MediaSet* const&>(reinterpret_cast<MediaSet*>(auiFormId))));
            break;
        }
        case CHUNK_ID_XNAM_ID: {
            apFile->GetChunkData(&auiFormId);
            m_kMediaSetList3.AddHead(
                const_cast<MediaSet*&>(static_cast<MediaSet* const&>(reinterpret_cast<MediaSet*>(auiFormId))));
            break;
        }
        case CHUNK_ID_YNAM_ID: {
            apFile->GetChunkData(&auiFormId);
            m_kMediaSetList4.AddHead(
                const_cast<MediaSet*&>(static_cast<MediaSet* const&>(reinterpret_cast<MediaSet*>(auiFormId))));
            break;
        }
        case CHUNK_ID_LNAM_ID: {
            apFile->GetChunkData(&auiFormId);
            m_kMediaSetList5.AddHead(
                const_cast<MediaSet*&>(static_cast<MediaSet* const&>(reinterpret_cast<MediaSet*>(auiFormId))));
            break;
        }
        case CHUNK_ID_GNAM_ID: {
            apFile->GetChunkData(&auiFormId);
            m_kMediaSetList6.AddHead(
                const_cast<MediaSet*&>(static_cast<MediaSet* const&>(reinterpret_cast<MediaSet*>(auiFormId))));
            break;
        }
        case 'MANR':  // RNAM: faction form ID
            apFile->GetChunkData(&auiFormId);
            pFaction = reinterpret_cast<TESFaction*>(auiFormId);
            break;
        case CHUNK_ID_FNAM_ID:
            apFile->GetChunkData(&auiFormId);
            m_eRequiredFightReaction = static_cast<FIGHT_REACTION>(auiFormId);
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

// Picks a random MediaSet from the list, moves it to the tail, and returns it, or returns null if the list is empty.
// @fnv 0x00595560
MediaSet* MediaLocationController::GetMediaSetFromList(BSSimpleList<MediaSet*>* apList)
{
    BSSimpleList<MediaSet*>* pList = apList;
    MediaSet* pResult = 0;
    if (pList && pList->GetItem())
    {
        while (pList && pList->GetItem())
        {
            unsigned int uiRandom = GetRandomNumberInRange(0, 4);
            if (uiRandom == 0 || !pResult)
                pResult = pList->GetItem();
            pList = pList->GetNext();
        }
    }
    else
        return 0;
    if (pResult)
    {
        apList->Remove(pResult);
        apList->AddTail(pResult);
    }
    return pResult;
}
// @fnv 0x00595600
bool MediaLocationController::Update(bool abInCombat)
{
    // Local spellings and declaration order preserve MSVC 2008 stack allocation.
    BSSimpleList<ActorCombatEntry*>* o;  // perceived actor list
    bool m;                              // found a hostile actor
    bool j;                              // found a faction actor
    bool e;                              // conditional selection flag
    float r;                             // squared XY distance
    float d;                             // normalized player distance from marker
    unsigned char c;                     // tension changed
    MusicMarkerReference* l;             // closest audio marker info
    float k;                             // squared marker radius
    bool b;                              // combat changed
    FIGHT_REACTION g;                    // current faction reaction
    unsigned char f;                     // faction presence changed
    bool n;                              // day/night changed
    bool i;                              // faction reaction changed
    unsigned int a;                      // current synchronization time
    bool h;                              // previous faction presence

    if (!g_thePlayer && g_thePlayer->GetMusicMarkerReference() &&
        g_thePlayer->GetMusicMarkerReference()->m_pMarkerReference)
        return false;
    if (DAT_011dd374 != this)
    {
        if (m_pMediaSet)
            m_pMediaSet->Reset();
        m_pMediaSet = 0;
    }
    DAT_011dd374 = this;
    a = BSAudio::GetSingleton()->GetSynchTime();
    if (!bIsActive)
    {
        if (m_pMediaSet)
            m_pMediaSet->Reset();
        m_pMediaSet = 0;
    }
    g = pFaction ? pFaction->GetFactionReaction(static_cast<TESFaction*>(
                       BGSDefaultObjectManager::GetDefaultObjectByIndex(DEFAULT_OBJECT_DO_PLAYER_FACTION)))
                 : FIGHT_REACTION_FIGHT_REACTION_NEUTRAL;
    l = g_thePlayer->GetMusicMarkerReference();
    e = false;
    k = l->m_pMarkerReference->GetRadius();
    k *= k;
    NiPoint3 q = *static_cast<const TESObjectREFR*>(l->m_pMarkerReference)->GetPos();  // marker position
    NiPoint3 p = q - *static_cast<const TESObjectREFR*>(g_thePlayer)->GetPos();        // marker-to-player difference
    r = p.GetSquaredXYLength();
    d = 1000.0f;
    if (r <= k)
        d = r / k;
    o = g_thePlayer->GetListofPerceivedActors();
    j = false;
    m = false;
    h = static_cast<bool>(m_uiPreviousPerceivedActorCount);
    m_uiPreviousPerceivedActorCount = 0;
    m_uiPerceivedActorCount = 0;
    while (o && !o->IsEmpty())
    {
        ActorCombatEntry* s = o->GetItem();  // perceived actor record
        if (s && s->pActor)
        {
            if (pFaction && s->pActor->HasFaction(pFaction))
            {
                m_uiPreviousPerceivedActorCount++;
                j = true;
                if (s->m_bIsEnemy)
                    g = FIGHT_REACTION_FIGHT_REACTION_ENEMY;
            }
            if (s->m_bIsEnemy)
            {
                m_uiPerceivedActorCount++;
                m = true;
            }
        }
        o = o->GetNext();
    }
    b = m_bActorStateFlag != abInCombat;
    c = m_bCountWasNonzero != (m_uiPerceivedActorCount > 0 ? 1U : 0U);
    f = h != (m_uiPreviousPerceivedActorCount > 0 ? 1U : 0U);
    n = m_bConditionWasTrue != IsMediaLocationActive();
    i = m_eCurrentFightReaction != g;
    if (g == GetDeadRep())
        f = false;
    m_bActorStateFlag = abInCombat;
    m_bCountWasNonzero = m_uiPerceivedActorCount > 0U ? true : false;
    m_bConditionWasTrue = IsMediaLocationActive();
    m_eCurrentFightReaction = g;
    m_fLocationDistance = d;
    if (m_fLocationDistance < 100.0 && m_fUpdateCooldown > a && !bIsActive)
        return false;
    bIsActive = false;
    if (m_pMediaSet)
        bIsActive = m_pMediaSet->Update(a, abInCombat, this);
    if (n || i || f)
    {
        if (m_pMediaSet)
            m_pMediaSet->Reset();
        m_pMediaSet = 0;
    }
    if (!bIsActive && d < 100.0)
    {
        if (m_pMediaSet)
        {
            m_pMediaSet->Reset();
            m_pMediaSet = 0;
        }
        if (!m_pMediaSet)
        {
            if (j)
            {
                switch (g)
                {
                case FIGHT_REACTION_FIGHT_REACTION_NEUTRAL:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList1);
                    break;
                case FIGHT_REACTION_FIGHT_REACTION_ENEMY:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList4);
                    break;
                case FIGHT_REACTION_FIGHT_REACTION_ALLY:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList2);
                    break;
                case FIGHT_REACTION_FIGHT_REACTION_FRIEND:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList3);
                    break;
                }
            }
            else
            {
                switch (GetDeadRep())
                {
                    break;
                case DEADFACTION_LOCATION:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList5);
                    break;
                case DEADFACTION_CONDITIONAL_NEUTRAL:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList1);
                    break;
                case DEADFACTION_CONDITIONAL_ALLY:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList2);
                    break;
                case DEADFACTION_CONDITIONAL_FRIEND:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList3);
                    break;
                case DEADFACTION_CONDITIONAL_ENEMY:
                    m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList4);
                    break;
                }
            }
        }
    }
    if ((!m_pMediaSet ||
         (m_pMediaSet->GetType() != MediaSet::BATTLE && m_pMediaSet->GetType() != MediaSet::LAYER_DUNGEON)) &&
        m_fLocationDistance < 100.0 && abInCombat)
    {
        if (m_pMediaSet)
        {
            m_pMediaSet->Reset();
            m_pMediaSet = 0;
        }
        if (!DAT_011dd378)
            m_pMediaSet = GetMediaSetFromList(&m_kMediaSetList6);
    }
    if (!bIsActive && m_pMediaSet)
        bIsActive = m_pMediaSet->Update(a, abInCombat, this);
    if (bIsActive)
        m_fUpdateCooldown = static_cast<unsigned int>(a + m_fUpdateInterval * 1000.0);
    if (!bIsActive && m_fLocationDistance > 1.0)
        DAT_011dd374 = 0;
    return bIsActive;
}

struct FUN_00595c80_shell : public NiPoint3
{
    float GetSquaredXYLength();
};

// Returns the sum of the squared x and y components of this NiPoint3.
// @fnv 0x00595c80
float FUN_00595c80_shell::GetSquaredXYLength()
{
    return x * x + y * y;
}

struct FUN_00595cf0_shell : public MediaLocationController
{
    int MediaLocationController_GetDeadRep();
};

// @fnv 0x00595cf0
// src: COMMUNITY 0x00595cf0
int FUN_00595cf0_shell::MediaLocationController_GetDeadRep()
{
    return *(unsigned int*)((char*)this + 0x6c) & 0xf;
}

struct FUN_00595d10_shell : public PlayerCharacter
{
    void* PlayerCharacter_GetCompassTargets();
};

// @fnv 0x00595d10
// src: COMMUNITY 0x00595d10
void* FUN_00595d10_shell::PlayerCharacter_GetCompassTargets()
{
    return *(void**)((char*)this + 0xd48);
}

struct FUN_00595e80_shell : public MediaLocationController
{
    bool MediaLocationController_GetDefaultTime();
};

// @fnv 0x00595e80
// src: COMMUNITY 0x00595e80
bool FUN_00595e80_shell::MediaLocationController_GetDefaultTime()
{
    if ((*(int*)((char*)this + 0x6c) >> 6) & 1)
        return true;
    return false;
}

extern float DAT_011ca9e8;

// @fnv 0x00595ea0
// src: COMMUNITY 0x00595ea0
float __fastcall Sky_GetSunriseBegin(char* apThis)
{
    if ((*(unsigned int*)(apThis + 0x118) & 0x100) && *(TESClimate**)(apThis + 0xc))
    {
        DAT_011ca9e8 = (double)(*(TESClimate**)(apThis + 0xc))->GetTransTime(0) / 6.0;
        *(unsigned int*)(apThis + 0x118) &= ~0x100u;
    }
    return DAT_011ca9e8;
}

// Returns the indexed time setting when the index is in [0,4), otherwise returns 0.
// @fnv 0x00595f10
// src: COMMUNITY 0x00595f10
unsigned char TESClimate::GetTransTime(int aiIndex)
{
    return (aiIndex < 4 && aiIndex >= 0) ? m_ucTimeSettings[aiIndex] : 0;
}

class Atmosphere;
class BGSLoadGameBuffer;
class BGSSaveGameBuffer;
class BSMultiBoundNode;
class Clouds;
class ImageSpaceModifierInstanceForm;
class Moon;
class NiColor;
class NiDirectionalLight;
class NiFogProperty;
class NiNode;
class Precipitation;
class Sky;
class SkyTextureManager;
class Stars;
class Sun;
struct TESWeather;
namespace fnv_00595f50 {
struct BSFogProperty;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};

extern float DAT_011ca9ec;

// @fnv 0x00595f50
// src: COMMUNITY 0x00595f50
float __fastcall Sky_GetSunriseEnd(Sky* pThis)
{
    if ((*(unsigned int*)((char*)pThis + 0x118) & 0x200) && *(TESClimate**)((char*)pThis + 0xc))
    {
        DAT_011ca9ec = (*(TESClimate**)((char*)pThis + 0xc))->GetTransTime(1) / 6.0;
        *(unsigned int*)((char*)pThis + 0x118) &= ~0x200;
    }
    return DAT_011ca9ec;
}
}  // namespace fnv_00595f50

namespace fnv_00595fc0 {
extern float DAT_011ca9f0;

// If the 0x400 flag is set and a TESClimate is present, stores its value for index 2 divided by 6.0 in DAT_011ca9f0 and clears the flag; returns DAT_011ca9f0.
// @fnv 0x00595fc0
// src: COMMUNITY 0x00595fc0
float __fastcall Sky_GetSunsetBegin(char* pThis)
{
    if ((*(unsigned int*)(pThis + 0x118) & 0x400) && *(TESClimate**)(pThis + 0xc))
    {
        DAT_011ca9f0 = (float)((*(TESClimate**)(pThis + 0xc))->GetTransTime(2) / 6.0);
        *(unsigned int*)(pThis + 0x118) &= ~0x400;
    }
    return DAT_011ca9f0;
}
}  // namespace fnv_00595fc0

extern double DAT_01034208;
extern float DAT_011ca9f4;
struct FUN_00596030_cls
{
    int pad0[3];
    TESClimate* inner;
    char pad1[0x118 - 0x10];
    unsigned int flags;
    float Sky_GetSunsetEnd();
};
// @fnv 0x00596030
// src: COMMUNITY 0x00596030
float FUN_00596030_cls::Sky_GetSunsetEnd()
{
    if ((flags & 0x800) && inner)
    {
        DAT_011ca9f4 = (float)(inner->GetTransTime(3) / DAT_01034208);
        flags &= ~0x800u;
    }
    return DAT_011ca9f4;
}

// @fnv 0x00966a20
float __fastcall GetFieldEC(const char* pThis)
{
    return *(const float*)(pThis + 0xec);
}

struct FUN_00595cb0_shell
{
    unsigned char m_0x00;
    unsigned char m_0x01;
    unsigned char m_0x02;
    unsigned char m_0x03;
    unsigned char m_0x04;
    unsigned char m_0x05;
    unsigned char m_0x06;
    unsigned char m_0x07;
    unsigned char m_0x08;
    unsigned char m_0x09;
    unsigned char m_0x0a;
    unsigned char m_0x0b;
    unsigned char m_0x0c;
    unsigned char m_0x0d;
    unsigned char m_0x0e;
    unsigned char m_0x0f;
    unsigned char m_0x10;
    unsigned char m_0x11;
    unsigned char m_0x12;
    unsigned char m_0x13;
    unsigned char m_0x14;
    unsigned char m_0x15;
    unsigned char m_0x16;
    unsigned char m_0x17;
    unsigned char m_0x18;
    unsigned char m_0x19;
    unsigned char m_0x1a;
    unsigned char m_0x1b;
    unsigned char m_0x1c;
    unsigned char m_0x1d;
    unsigned char m_0x1e;
    unsigned char m_0x1f;
    unsigned char m_0x20;
    unsigned char m_0x21;
    unsigned char m_0x22;
    unsigned char m_0x23;
    unsigned char m_0x24;
    unsigned char m_0x25;
    unsigned char m_0x26;
    unsigned char m_0x27;
    unsigned int m_0x28;
    unsigned char m_0x2c;
    unsigned char m_0x2d;
    unsigned char m_0x2e;
    unsigned char m_0x2f;
    unsigned char m_0x30;
    unsigned char m_0x31;
    unsigned char m_0x32;
    unsigned char m_0x33;
    unsigned char m_0x34;
    void ResetState();
};

// Clears the fields at offsets 0x28 and 0x30 through 0x34, setting them all to zero.
// @fnv 0x00595cb0
void FUN_00595cb0_shell::ResetState()
{
    m_0x30 = 0;
    m_0x28 = 0;
    m_0x31 = 0;
    m_0x32 = 0;
    m_0x33 = 0;
    m_0x34 = 0;
}

void _Deallocate(void*);
struct Stub00595530
{
    void FUN_005960a0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_005960a0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00595530
void* Stub00595530::DestroyIfFlagged(unsigned int flags)
{
    this->FUN_005960a0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

class FormStub_cls
{
  public:
    virtual ~FormStub_cls();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};

class MLCFullName_cls : public TESFullName
{
  public:
    virtual ~MLCFullName_cls();
};

class FUN_005960a0 : public FormStub_cls, public MLCFullName_cls
{
  public:
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    MLCFullName_cls m_kLocationName;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    BSSimpleList<MediaSet*> m_kMediaSetList1;
    BSSimpleList<MediaSet*> m_kMediaSetList2;
    BSSimpleList<MediaSet*> m_kMediaSetList3;
    BSSimpleList<MediaSet*> m_kMediaSetList4;
    BSSimpleList<MediaSet*> m_kMediaSetList5;
    BSSimpleList<MediaSet*> m_kMediaSetList6;
    virtual ~FUN_005960a0();
};

FormStub_cls::~FormStub_cls()
{}

MLCFullName_cls::~MLCFullName_cls()
{}

// @fnv 0x005960a0
FUN_005960a0::~FUN_005960a0()
{}

struct MLCFormSaver
{
    void BeginFormRecord();
    void FinishFormRecord();
};

struct MLCFullNameSaver : public TESFullName
{
    void Save_00487010();
};

struct MLCFormID
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

void __cdecl TESForm_AddChunk_00485910(unsigned int auiChunkID, unsigned int auiValue);
void __cdecl SaveChunkFloat(unsigned int auiChunkID, float afValue);

struct MLCSaver : public TESForm, public MLCFullNameSaver
{
    unsigned int m_fUpdateCooldown;
    unsigned int m_uiFirstCounter;
    unsigned int m_uiSecondCounter;
    unsigned int m_uiThirdCounter;
    bool bIsActive;
    bool m_bCountWasNonzero;
    bool m_bActorStateFlag;
    bool m_bConditionWasTrue;
    bool m_bConditionActive;
    float m_fLocationDistance;
    unsigned int m_uiPerceivedActorCount;
    unsigned int m_uiPreviousPerceivedActorCount;
    FIGHT_REACTION m_eCurrentFightReaction;
    char m_cMediaState;
    MediaSet* m_pMediaSet;
    TESFullName m_kLocationName;
    TESFaction* pFaction;
    FIGHT_REACTION m_eRequiredFightReaction;
    TESObjectREFR* m_pReference;
    int iFlags;
    float m_fLowerWeightThreshold;
    float m_fUpperWeightThreshold;
    float m_fMediaSelectionValue;
    float m_fUpdateInterval;
    unsigned int m_uiShortDelay;
    unsigned int m_uiLongDelay;
    BSSimpleList<MediaSet*> m_kMediaSetList1;
    BSSimpleList<MediaSet*> m_kMediaSetList2;
    BSSimpleList<MediaSet*> m_kMediaSetList3;
    BSSimpleList<MediaSet*> m_kMediaSetList4;
    BSSimpleList<MediaSet*> m_kMediaSetList5;
    BSSimpleList<MediaSet*> m_kMediaSetList6;
    void SaveToStream();
};

// Writes the form's flags, float fields, media-set form IDs and faction form ID as chunks, then finishes the form save.
// @fnv 0x00596790
void MLCSaver::SaveToStream()
{
    ((MLCFormSaver*)this)->BeginFormRecord();
    MLCFullNameSaver::Save_00487010();
    TESForm_AddChunk_00485910(CHUNK_ID_NAM1_ID, (unsigned int)iFlags);
    SaveChunkFloat(CHUNK_ID_NAM2_ID, m_fLowerWeightThreshold);
    SaveChunkFloat(CHUNK_ID_NAM3_ID, m_fUpperWeightThreshold);
    SaveChunkFloat(CHUNK_ID_NAM4_ID, m_fUpdateInterval);
    TESForm_AddChunk_00485910(CHUNK_ID_NAM5_ID, m_uiShortDelay);
    TESForm_AddChunk_00485910(CHUNK_ID_NAM6_ID, m_uiLongDelay);
    SaveChunkFloat(CHUNK_ID_NAM7_ID, m_fMediaSelectionValue);

    BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList1;
    if (!pIter->IsEmpty())
    {
        MediaSet* pMediaSet;
        while (pIter && (pMediaSet = pIter->GetItem()) != 0)
        {
            unsigned int auiFormId = ((MLCFormID*)pMediaSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(CHUNK_ID_HNAM_ID, auiFormId);
            pIter = pIter->GetNext();
        }
    }
    pIter = &m_kMediaSetList2;
    if (!pIter->IsEmpty())
    {
        MediaSet* pMediaSet;
        while (pIter && (pMediaSet = pIter->GetItem()) != 0)
        {
            unsigned int auiFormId = ((MLCFormID*)pMediaSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(CHUNK_ID_ZNAM_ID, auiFormId);
            pIter = pIter->GetNext();
        }
    }
    pIter = &m_kMediaSetList3;
    if (!pIter->IsEmpty())
    {
        MediaSet* pMediaSet;
        while (pIter && (pMediaSet = pIter->GetItem()) != 0)
        {
            unsigned int auiFormId = ((MLCFormID*)pMediaSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(CHUNK_ID_XNAM_ID, auiFormId);
            pIter = pIter->GetNext();
        }
    }
    pIter = &m_kMediaSetList4;
    if (!pIter->IsEmpty())
    {
        MediaSet* pMediaSet;
        while (pIter && (pMediaSet = pIter->GetItem()) != 0)
        {
            unsigned int auiFormId = ((MLCFormID*)pMediaSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(CHUNK_ID_YNAM_ID, auiFormId);
            pIter = pIter->GetNext();
        }
    }
    pIter = &m_kMediaSetList5;
    if (!pIter->IsEmpty())
    {
        MediaSet* pMediaSet;
        while (pIter && (pMediaSet = pIter->GetItem()) != 0)
        {
            unsigned int auiFormId = ((MLCFormID*)pMediaSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(CHUNK_ID_LNAM_ID, auiFormId);
            pIter = pIter->GetNext();
        }
    }
    pIter = &m_kMediaSetList6;
    if (!pIter->IsEmpty())
    {
        MediaSet* pMediaSet;
        while (pIter && (pMediaSet = pIter->GetItem()) != 0)
        {
            unsigned int auiFormId = ((MLCFormID*)pMediaSet)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
            TESForm_AddChunk_00485910(CHUNK_ID_GNAM_ID, auiFormId);
            pIter = pIter->GetNext();
        }
    }
    if (pFaction)
    {
        unsigned int auiFormId = ((MLCFormID*)pFaction)->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        TESForm_AddChunk_00485910(0x4d414e52, auiFormId);
    }
    TESForm_AddChunk_00485910(CHUNK_ID_FNAM_ID, (unsigned int)m_eRequiredFightReaction);
    ((MLCFormSaver*)this)->FinishFormRecord();
}

struct ListOps
{
    int FUN_005ae380();
};
struct FormOps
{
    bool TESForm_CompareAllComponents(TESForm* apOther);
};
struct FUN_00596d70_shell : public MediaLocationController
{
    bool MediaLocationController_Compare(TESForm* apForm);
};
// Compares this MediaLocationController with apForm: returns true if apForm is not one, or if any flag, faction, field or media list differs; false if all match.
// @fnv 0x00596d70
// src: XBOX_PDB 0x00596d70
bool FUN_00596d70_shell::MediaLocationController_Compare(TESForm* apForm)
{
    MediaLocationController* pOther = dynamic_cast<MediaLocationController*>(apForm);
    if (!pOther)
        return true;
    if (iFlags != pOther->iFlags)
        return true;
    if (pFaction != pOther->pFaction)
        return true;
    if (m_eRequiredFightReaction != pOther->m_eRequiredFightReaction)
        return true;
    if (m_pReference != pOther->m_pReference)
        return true;
    if (m_fLowerWeightThreshold != pOther->m_fLowerWeightThreshold)
        return true;
    if (m_fUpperWeightThreshold != pOther->m_fUpperWeightThreshold)
        return true;
    if (m_fUpdateInterval != pOther->m_fUpdateInterval)
        return true;
    if (m_fMediaSelectionValue != pOther->m_fMediaSelectionValue)
        return true;
    if (m_uiShortDelay != pOther->m_uiShortDelay)
        return true;
    if (m_uiLongDelay != pOther->m_uiLongDelay)
        return true;
    if (reinterpret_cast<FormOps*>(this)->TESForm_CompareAllComponents(pOther))
        return true;
    if (pOther->m_kMediaSetList1.GetItem() && m_kMediaSetList1.GetItem() &&
        reinterpret_cast<ListOps*>(&pOther->m_kMediaSetList1)->FUN_005ae380() ==
            reinterpret_cast<ListOps*>(&m_kMediaSetList1)->FUN_005ae380())
    {
        BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList1;
        while (pIter && pIter->GetItem())
        {
            BSSimpleList<MediaSet*>* pOtherIter;
            bool bFound = false;
            pOtherIter = &pOther->m_kMediaSetList1;
            while (pOtherIter && pOtherIter->GetItem())
            {
                if (!pIter->GetItem()->Compare(pOtherIter->GetItem()))
                {
                    bFound = true;
                    break;
                }
                pOtherIter = pOtherIter->GetNext();
            }
            if (!bFound)
                return true;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        return true;
    }
    if (pOther->m_kMediaSetList2.GetItem() && m_kMediaSetList2.GetItem() &&
        reinterpret_cast<ListOps*>(&pOther->m_kMediaSetList2)->FUN_005ae380() ==
            reinterpret_cast<ListOps*>(&m_kMediaSetList2)->FUN_005ae380())
    {
        BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList2;
        while (pIter && pIter->GetItem())
        {
            BSSimpleList<MediaSet*>* pOtherIter;
            bool bFound = false;
            pOtherIter = &pOther->m_kMediaSetList2;
            while (pOtherIter && pOtherIter->GetItem())
            {
                if (!pIter->GetItem()->Compare(pOtherIter->GetItem()))
                {
                    bFound = true;
                    break;
                }
                pOtherIter = pOtherIter->GetNext();
            }
            if (!bFound)
                return true;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        return true;
    }
    if (pOther->m_kMediaSetList3.GetItem() && m_kMediaSetList3.GetItem() &&
        reinterpret_cast<ListOps*>(&pOther->m_kMediaSetList3)->FUN_005ae380() ==
            reinterpret_cast<ListOps*>(&m_kMediaSetList3)->FUN_005ae380())
    {
        BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList3;
        while (pIter && pIter->GetItem())
        {
            BSSimpleList<MediaSet*>* pOtherIter;
            bool bFound = false;
            pOtherIter = &pOther->m_kMediaSetList3;
            while (pOtherIter && pOtherIter->GetItem())
            {
                if (!pIter->GetItem()->Compare(pOtherIter->GetItem()))
                {
                    bFound = true;
                    break;
                }
                pOtherIter = pOtherIter->GetNext();
            }
            if (!bFound)
                return true;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        return true;
    }
    if (pOther->m_kMediaSetList4.GetItem() && m_kMediaSetList4.GetItem() &&
        reinterpret_cast<ListOps*>(&pOther->m_kMediaSetList4)->FUN_005ae380() ==
            reinterpret_cast<ListOps*>(&m_kMediaSetList4)->FUN_005ae380())
    {
        BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList4;
        while (pIter && pIter->GetItem())
        {
            BSSimpleList<MediaSet*>* pOtherIter;
            bool bFound = false;
            pOtherIter = &pOther->m_kMediaSetList4;
            while (pOtherIter && pOtherIter->GetItem())
            {
                if (!pIter->GetItem()->Compare(pOtherIter->GetItem()))
                {
                    bFound = true;
                    break;
                }
                pOtherIter = pOtherIter->GetNext();
            }
            if (!bFound)
                return true;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        return true;
    }
    if (pOther->m_kMediaSetList5.GetItem() && m_kMediaSetList5.GetItem() &&
        reinterpret_cast<ListOps*>(&pOther->m_kMediaSetList5)->FUN_005ae380() ==
            reinterpret_cast<ListOps*>(&m_kMediaSetList5)->FUN_005ae380())
    {
        BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList5;
        while (pIter && pIter->GetItem())
        {
            BSSimpleList<MediaSet*>* pOtherIter;
            bool bFound = false;
            pOtherIter = &pOther->m_kMediaSetList5;
            while (pOtherIter && pOtherIter->GetItem())
            {
                if (!pIter->GetItem()->Compare(pOtherIter->GetItem()))
                {
                    bFound = true;
                    break;
                }
                pOtherIter = pOtherIter->GetNext();
            }
            if (!bFound)
                return true;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        return true;
    }
    if (pOther->m_kMediaSetList6.GetItem() && m_kMediaSetList6.GetItem() &&
        reinterpret_cast<ListOps*>(&pOther->m_kMediaSetList6)->FUN_005ae380() ==
            reinterpret_cast<ListOps*>(&m_kMediaSetList6)->FUN_005ae380())
    {
        BSSimpleList<MediaSet*>* pIter = &m_kMediaSetList6;
        while (pIter && pIter->GetItem())
        {
            BSSimpleList<MediaSet*>* pOtherIter;
            bool bFound = false;
            pOtherIter = &pOther->m_kMediaSetList6;
            while (pOtherIter && pOtherIter->GetItem())
            {
                if (!pIter->GetItem()->Compare(pOtherIter->GetItem()))
                {
                    bFound = true;
                    break;
                }
                pOtherIter = pOtherIter->GetNext();
            }
            if (!bFound)
                return true;
            pIter = pIter->GetNext();
        }
    }
    else
    {
        return true;
    }
    return false;
}

struct ObjT
{
    float Sky_GetSunriseEnd();
    float Sky_GetSunsetBegin();
    float Sky_GetSunsetEnd();
};
struct GlobT
{
    ObjT* FUN_008d8520();
};
extern GlobT* DAT_011dea10;
extern double DAT_01034200;
float __fastcall Sky_GetSunriseBegin(char* apThis);
float __fastcall GetFieldEC(const char* pThis);

struct ThisT
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int m_uiShortDelay;
    unsigned int m_uiLongDelay;
    bool MediaLocationController_GetDefaultTime();
    bool IsWithinRange();
};

// @fnv 0x00595d30
bool ThisT::IsWithinRange()
{
    ObjT* p;
    p = DAT_011dea10->FUN_008d8520();
    if (MediaLocationController_GetDefaultTime())
    {
        return (p != 0) ? (((Sky_GetSunriseBegin((char*)p) + p->Sky_GetSunriseEnd()) / 2.0 <= GetFieldEC((const char*)p)) &&
                           (GetFieldEC((const char*)p) <= (p->Sky_GetSunsetBegin() + p->Sky_GetSunsetEnd()) / 2.0))
                        : true;
    }
    else
    {
        return (p != 0) ? (((double)m_uiShortDelay * DAT_01034200 <= GetFieldEC((const char*)p)) &&
                           (GetFieldEC((const char*)p) <= (double)m_uiLongDelay * DAT_01034200))
                        : true;
    }
}

struct ThisCls
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    TESFaction* pFaction;
    int m_eRequiredFightReaction;
    TESObjectREFR* m_pReference;
    int iFlags;
    float m_fLowerWeightThreshold;
    float m_fUpperWeightThreshold;
    float m_fMediaSelectionValue;
    float m_fUpdateInterval;
    unsigned int m_uiShortDelay;
    unsigned int m_uiLongDelay;
    BSSimpleList<MediaSet*> m_kMediaSetList1;
    BSSimpleList<MediaSet*> m_kMediaSetList2;
    BSSimpleList<MediaSet*> m_kMediaSetList3;
    BSSimpleList<MediaSet*> m_kMediaSetList4;
    BSSimpleList<MediaSet*> m_kMediaSetList5;
    BSSimpleList<MediaSet*> m_kMediaSetList6;
    void TESForm_CopyAllComponents(MediaLocationController* apSrc);
    void CopyFromMediaLocationController(TESForm* apForm);
};

// Casts apForm to MediaLocationController, copies its scalar fields and faction/ref, and copies each of six MediaSet lists in reverse order.
// @fnv 0x00596ac0
void ThisCls::CopyFromMediaLocationController(TESForm* apForm)
{
    BSSimpleList<MediaSet*>* pNode;
    MediaLocationController* pSrc = dynamic_cast<MediaLocationController*>(apForm);
    if (pSrc == 0)
        return;
    TESForm_CopyAllComponents(pSrc);
    iFlags = pSrc->iFlags;
    m_fLowerWeightThreshold = pSrc->m_fLowerWeightThreshold;
    m_fUpperWeightThreshold = pSrc->m_fUpperWeightThreshold;
    m_fUpdateInterval = pSrc->m_fUpdateInterval;
    m_fMediaSelectionValue = pSrc->m_fMediaSelectionValue;
    m_uiShortDelay = pSrc->m_uiShortDelay;
    m_uiLongDelay = pSrc->m_uiLongDelay;
    pFaction = pSrc->pFaction;
    m_eRequiredFightReaction = pSrc->m_eRequiredFightReaction;
    m_pReference = pSrc->m_pReference;
    m_kMediaSetList1.RemoveAll();
    pNode = &pSrc->m_kMediaSetList1;
    while (pNode && pNode->GetItem())
    {
        m_kMediaSetList1.AddHead(pNode->GetItem());
        pNode = pNode->GetNext();
    }
    m_kMediaSetList2.RemoveAll();
    pNode = &pSrc->m_kMediaSetList2;
    while (pNode && pNode->GetItem())
    {
        m_kMediaSetList2.AddHead(pNode->GetItem());
        pNode = pNode->GetNext();
    }
    m_kMediaSetList3.RemoveAll();
    pNode = &pSrc->m_kMediaSetList3;
    while (pNode && pNode->GetItem())
    {
        m_kMediaSetList3.AddHead(pNode->GetItem());
        pNode = pNode->GetNext();
    }
    m_kMediaSetList4.RemoveAll();
    pNode = &pSrc->m_kMediaSetList4;
    while (pNode && pNode->GetItem())
    {
        m_kMediaSetList4.AddHead(pNode->GetItem());
        pNode = pNode->GetNext();
    }
    m_kMediaSetList5.RemoveAll();
    pNode = &pSrc->m_kMediaSetList5;
    while (pNode && pNode->GetItem())
    {
        m_kMediaSetList5.AddHead(pNode->GetItem());
        pNode = pNode->GetNext();
    }
    m_kMediaSetList6.RemoveAll();
    pNode = &pSrc->m_kMediaSetList6;
    while (pNode && pNode->GetItem())
    {
        m_kMediaSetList6.AddHead(pNode->GetItem());
        pNode = pNode->GetNext();
    }
}
