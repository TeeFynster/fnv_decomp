#pragma once

#include "MagicTarget.h"
#include "BSSoundHandle.h"

class BGSLoadGameBuffer;
class BGSTalkingActivator;
class Conversation;
class TESObjectREFR;

class FalloutRadio
{
public:
    unsigned char unk00;

    class RadioReceiver
    {
    public:
        void* form;
        BSSoundHandle sound;
        char padding[12];
        unsigned char active;

        void* FUN_00832190(bool);
        void InitLoadGame(BGSLoadGameBuffer*);
    };

    class RadioConversation
    {
    public:
        Conversation* conversation;
        unsigned int unk04;
        unsigned int nextUpdate;
        int state;
        char padding[8];

        bool IsFlag20Set();
        bool FalloutRadio_StationState_IsTransmitting();
        void FalloutRadio_StationState_SetContBroadcast(bool);
        void SetFlag80(bool);
    };

    class RadioStationState
    {
    public:
        BGSTalkingActivator* form;
        RadioConversation station;
        BSSimpleList<RadioReceiver*> receivers;

        void InitLoadGame(BGSLoadGameBuffer*);
        void* FUN_00832160(bool);
    };

    static bool __cdecl SetRadioEnabled(bool);
    static bool SetRadioReferenceEnabled(TESObjectREFR*, bool);
    static void RefreshRadioReceivers(bool);
    static bool __cdecl Update(bool);
    static void UpdateRadioConversations(bool);
    static void InitLoadGame(BGSLoadGameBuffer*);
    static void ApplyLoadBuffer(BGSLoadGameBuffer*);
    static RadioConversation* GetRadioConversation(BGSTalkingActivator*);
    static void __cdecl RadioSynchUnPaused();

    void Revert(BGSLoadGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);

    static unsigned int ms_uiRadioSyncFlags;
};
