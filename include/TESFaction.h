#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESReactionForm.h"
#include "FactionSaveData.h"

class FactionRankPresentation;
class TESReputation;
enum FIGHT_REACTION;

struct _FightReaction
{
    enum Type
    {
        NEUTRAL = 0,
        ENEMY = 1,
        ALLY = 2,
        FRIEND = 3,
        COUNT
    };
};

class TESFaction : public TESForm, public TESFullName, public TESReactionForm
{
public:
    struct Rank;

    TESFaction();
    virtual ~TESFaction();

    virtual void ClearData();
    virtual void Revert(BGSLoadFormBuffer* buffer);
    virtual void InitItem();

    void ResetFormData();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void ClearReactions();
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    int InitializeFaction();
    BSSimpleList<FactionRankPresentation*>* GetRankDataList();
    bool Load(TESFile* file);
    bool GetPCAnEnemy() const;
    FIGHT_REACTION GetFactionReaction(TESFaction* faction);
    void SetFactionFightReaction(TESFaction* faction, _FightReaction::Type reaction);
    bool IsHiddenFlagSet();
    unsigned int GetFormID();
    bool GetEvil();
    void ForwardCall_0047eb90(bool value);

    FactionSaveData data;
    TESReputation* pReputationData;
    BSSimpleList<FactionRankPresentation*> m_kRankDataList;
    int m_iFirstFactionValue;
    int m_iSecondFactionValue;
};
