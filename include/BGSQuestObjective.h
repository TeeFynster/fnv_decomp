#pragma once

#include "MagicTarget.h"
#include "TESFullName.h"

class RegionObjectEntry;
class TESFile;
class TESQuest;

enum QUEST_OBJECTIVE_STATE
{
    QOS_DORMANT = 0,
    QOS_DISPLAYED = 1,
    QOS_COMPLETED = 2,
    QOS_COMPLETED_DISPLAYED = 3
};

class ObjectiveDisplayText : public BSStringT<char>
{
public:
    ObjectiveDisplayText();
    ~ObjectiveDisplayText();
    ObjectiveDisplayText& operator=(const char* text);
};

class BGSQuestObjective
{
public:
    struct _State
    {
        enum State
        {
            DORMANT = 0,
            DISPLAYED = 1,
            COMPLETED = 2,
            COMPLETED_DISPLAYED = 3
        };
    };
    typedef _State::State State;

    BGSQuestObjective();
    virtual ~BGSQuestObjective();

    unsigned int iIndex;
    ObjectiveDisplayText m_kDisplayText;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> m_kTargetList;
    bool bInitialized;
    unsigned char layoutPadding1D[3];
    QUEST_OBJECTIVE_STATE eState;

    unsigned int GetIndex();
    void SetIndex(unsigned int index);
    void Initialize();
    void InitItem(TESQuest* owner);
    void Load(TESFile* file);
    void GetTargetsAndObjectives(BSSimpleList<RegionObjectEntry*>* targets);
    BSSimpleList<RegionObjectEntry*>* GetTargetList();
    QUEST_OBJECTIVE_STATE GetState();
    void SetState(QUEST_OBJECTIVE_STATE state);
    void SetOwnerQuest(TESQuest* owner);
    void SetOwner(TESQuest* owner);
    bool GetCompleted() const;
    bool GetDisplayed() const;
    const char* GetDisplayText();
    TESQuest* TESMain_GetThread();
    void AddMatchingTargetsToList(void* targets);
    bool HasFlag();
};
