#pragma once

#include "TESBoundObject.h"
#include "NOTE_TYPE.h"
#include "TESModel.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "BGSPickupPutdownSounds.h"
#include "MagicTarget.h"
#include "BSSimpleList.h"

class TESActorBase;
class TESDescription;
class TESFile;
class TESQuest;
class TESSound;
class TESTopic;


class BGSNote : public TESBoundObject,
                public TESModel,
                public TESFullName,
                public TESIcon,
                public BGSPickupPutdownSounds
{
public:
    void* m_pText;
    void* m_pDialogueSpeaker;
    BSSimpleList<TESQuest*> ownerQuests;
    signed char cType;
    bool m_bIsRead;
    char padding7e[2];

    BGSNote();
    virtual ~BGSNote();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool LoadForm(TESFile* file);
    virtual void SaveForm();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void InitItem();
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);

    void* Release(unsigned int flags);
    void ClearNoteData();
    void SaveNote();
    void SetNoteTexture(TESTexture* texture);
    void SetNoteText(TESDescription* text);
    BSSimpleList<TESQuest*>* GetOwnerQuests();

    void ChangeNoteType(NOTE_TYPE type);
    bool Load(TESFile* file);
    TESTexture* GetNoteTexture();
    TESSound* GetNoteSound();
    void SetNoteSound(TESSound* sound);
    TESTopic* GetNoteTopic();
    void SetNoteTopic(TESTopic* topic);
    TESActorBase* GetNoteSpeaker();
    void SetNoteSpeaker(TESActorBase* speaker);
    void ResetFormData();
    int GetNoteType();
    TESDescription* GetNoteDescription();
    bool GetUnk7d();
    void SetSoundNotePlayed(bool played);
};
