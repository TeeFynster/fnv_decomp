
// src/fallout/audio/falloutradio_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00835be0: the skeleton of src/fallout/audio/falloutradio.cpp
// that unit declares it this way.

#include "../../../include/BGSTalkingActivator.h"
#include "../../../include/BSAudio.h"
#include "../../../include/DialogueItem.h"
#include "../../../include/FalloutRadio.h"

#include "../../../include/MEDIATYPE.h"

class FalloutAudioMedia
{
  public:
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static void BeginMediaUpdate();
    static void EndMediaUpdate();
    static bool IsRadioPlaying();
};

extern FalloutRadio::RadioStationState* DAT_011dd42c;
extern bool DAT_011dd434;
extern unsigned char DAT_011dd436;
extern BSSoundHandle DAT_011dd5bc;
extern BSSimpleList<FalloutRadio::RadioStationState*> DAT_011dd554;

void FalloutAudioMedia_MediaSetRadio(bool);

class Conversation
{
  public:
    BSSimpleList<DialogueItem*> items;
    BSSimpleList<DialogueItem*>* current;
    bool Conversation_NextItem();
    void Conversation_PrecacheSounds();
    bool Conversation_FirstItem();
    DialogueItem* FUN_0083c820();
    ~Conversation();
};
TESTopic* GetTopicSubTypeName(int, int);
FalloutRadio::RadioStationState* CreateRadioStationState(BGSTalkingActivator*, bool);
void FalloutRadio_UpdateStation(FalloutRadio::RadioStationState*);
void AdvanceConversation(FalloutRadio::RadioStationState*, TESTopic*);
bool FalloutRadio_GetIsDialogueOnlyRadio();
void FUN_008304a0();
void FUN_008304c0();
class ATM
{
  public:
    void BSCriticalSection_Enter(const char*);
    void FUN_004538c0();
};
extern ATM g_011dd5e8;
// @fnv 0x00835be0
// src: EXE 0x00835be0
void FalloutRadio_StartRadioConversation(BGSTalkingActivator* form, TESTopic* topic)
{
    TESTopic* a = 0;
    FalloutRadio::RadioStationState* station = 0;
    if (DAT_011dd436)
        return;
    BSSimpleList<FalloutRadio::RadioStationState*>* entries = &DAT_011dd554;
    while (entries && entries->GetItem())
    {
        if (entries->GetItem()->form == form)
        {
            station = entries->GetItem();
            break;
        }
        entries = entries->GetNext();
    }
    if (!station)
        station = CreateRadioStationState(form, false);
    a = topic ? topic : GetTopicSubTypeName(7, 0);
    if (!station || station->form->FUN_00440da0())
        return;
    bool f = station->station.IsFlag20Set();
    g_011dd5e8.BSCriticalSection_Enter("FalloutRadio::StartRadioConversation");
    if (station->station.conversation)
        while (station->station.conversation->Conversation_NextItem())
        {
        }
    if (station->station.FalloutRadio_StationState_IsTransmitting())
    {
        station->station.FalloutRadio_StationState_SetContBroadcast(false);
        station->station.state = 1;
        FalloutRadio_UpdateStation(station);
    }
    if (DAT_011dd42c == station && DAT_011dd434)
    {
        DAT_011dd5bc.Stop();
        DAT_011dd5bc.Release();
        if (FalloutRadio_GetIsDialogueOnlyRadio())
        {
            FUN_008304a0();
            FalloutAudioMedia_MediaSetRadio(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_MEDIA_RADIO, 0, 1000, false, false, 0.0f, 0);
            FUN_008304c0();
        }
    }
    BSSimpleList<FalloutRadio::RadioReceiver*>* b = &station->receivers;
    while (b && b->GetItem())
    {
        FalloutRadio::RadioReceiver* receiver = b->GetItem();
        receiver->sound.Stop();
        receiver->sound.Release();
        b = b->GetNext();
    }
    AdvanceConversation(station, a);
    station->station.state = 0;
    station->station.conversation->Conversation_PrecacheSounds();
    station->station.conversation->Conversation_FirstItem();
    if (!station->station.conversation->FUN_0083c820())
    {
        delete station->station.conversation;
        station->station.conversation = 0;
        station->station.state = 1;
    }
    else
    {
        if (DAT_011dd42c == station && DAT_011dd434)
        {
            DAT_011dd5bc.Stop();
            DAT_011dd5bc.Release();
            if (FalloutRadio_GetIsDialogueOnlyRadio())
            {
                FUN_008304a0();
                FalloutAudioMedia_MediaSetRadio(true);
                FalloutAudioMedia::PlayMedia(MEDIATYPE_MEDIA_RADIO, 0, 1000, false, false, 0.0f, 0);
                FUN_008304c0();
            }
        }
        station->station.conversation->FUN_0083c820()->SelectDefaultResponseList();
    }
    if (station->station.state > 1)
        station->station.state = 0;
    station->station.nextUpdate = BSAudio::BSAudio_QInstance()->GetSynchTime() + 50;
    station->station.SetFlag80(true);
    station->station.FalloutRadio_StationState_SetContBroadcast(f);
    g_011dd5e8.FUN_004538c0();
}
