#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "MagicTarget.h"

class MediaSet;
class TESFaction;
class TESObjectREFR;

#include "FIGHT_REACTION.h"

struct MediaLocationController : public TESForm, public TESFullName
{
public:
    enum DEADREPFLAGS
    {
        DEADFACTION_CONDITIONAL_NEUTRAL,
        DEADFACTION_CONDITIONAL_ENEMY,
        DEADFACTION_CONDITIONAL_ALLY,
        DEADFACTION_CONDITIONAL_FRIEND,
        DEADFACTION_LOCATION,
        DEADFACTION_NONE
    };

    MediaLocationController();

    virtual bool LoadForm(TESFile* apFile);
    virtual void InitItem();
    virtual void ClearData();

    bool Load(TESFile* apFile);
    void ProcessMediaSetList(BSSimpleList<MediaSet*>* apList);
    MediaSet* GetMediaSetFromList(BSSimpleList<MediaSet*>* apList);
    bool Update(bool abInCombat);
    bool IsMediaLocationActive();
    DEADREPFLAGS GetDeadRep();
    void ResetFormData();
    int GetLoop();
    bool GetByteAtOffset55();

    unsigned int m_fUpdateCooldown;
    unsigned int m_uiFirstCounter;
    unsigned int m_uiSecondCounter;
    unsigned int m_uiThirdCounter;
    bool bIsActive;
    bool m_bCountWasNonzero;
    bool m_bActorStateFlag;
    bool m_bConditionWasTrue;
    bool m_bConditionActive;
    unsigned char layoutPadding39[3];
    float m_fLocationDistance;
    unsigned int m_uiPerceivedActorCount;
    unsigned int m_uiPreviousPerceivedActorCount;
    FIGHT_REACTION m_eCurrentFightReaction;
    char m_cMediaState;
    unsigned char layoutPadding4D[3];
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
};
