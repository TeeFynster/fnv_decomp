#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "MediaSetEntry.h"

class MediaLocationController;
class TESSound;

class MediaSet : public TESForm, public TESFullName
{
public:
    typedef ::MediaSetEntry MediaSetEntry;

    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };

    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    MEDIASETTYPE Type;
    MediaSetEntry m_kMediaSetEntry1;
    MediaSetEntry m_kMediaSetEntry2;
    MediaSetEntry m_kMediaSetEntry3;
    MediaSetEntry m_kMediaSetEntry4;
    MediaSetEntry m_kMediaSetEntry5;
    MediaSetEntry m_kMediaSetEntry6;
    char m_cMediaFlag;
    float m_fMediaParameter1;
    float fSkillValueBonus;
    float m_fMediaParameter3;
    float m_fMediaValue;
    TESSound* m_pSound1;
    TESSound* m_pSound2;

    virtual void InitItem();
    virtual void ClearData();

    MediaSet();
    virtual ~MediaSet();
    void ResetFormData();
    void SaveMediaSet();
    bool UpdateLayerLocation(unsigned int, bool, MediaLocationController*);
    bool PointLocation(unsigned int, bool, MediaLocationController*);
    bool UpdateBattleState(bool, unsigned int, int);
    void UpdateIncidental(unsigned int);
    bool Update(unsigned int auiTime, bool abForce, MediaLocationController* apController);
    void Reset();
    MEDIASETTYPE GetType();
};
