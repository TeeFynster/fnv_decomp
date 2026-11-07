#pragma once

#include "CombatProcedure.h"
#include "IDebugText.h"

class Projectile;

class CombatProcedureBeInCover : public CombatProcedure
{
public:
    enum COVER_STATE  // values: Xbox PDB CombatProcedureBeInCover::COVER_STATE
    {
        COVER_STATE_INITIALIZING = 0,
        COVER_STATE_WAITING_BEHIND_COVER = 1,
        COVER_STATE_MOVING_OUT = 2,
        COVER_STATE_WAITING_OUT_OF_COVER = 3,
        COVER_STATE_FIRING_OUT_OF_COVER = 4,
        COVER_STATE_MOVING_IN = 5,
        COVER_STATE_MOVING_IN_AND_ROTATE = 6,
        COVER_STATE_HOLDING_GROUND = 7
    };

    struct Timer
    {
        float m_fStartTime;
        float m_fTimeout;

        bool CombatTimer_IsSet();
        float GetValue();
        float GetElapsedTime();
    };

    CombatProcedureBeInCover(void* pLoc);

    virtual ~CombatProcedureBeInCover();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);

    void DebugText(IDebugText*, DEBUGTEXT_LOCATION, DEBUGTEXT_JUSTIFY);
    void UpdateCoverState();
    void StopAttackerAndEngageTarget();
    void UpdateCombatProcedure(Projectile* apProjectile);

    COVER_STATE eState;
    void* m_pCurrentCoverPoint;
    float m_afFirstVector[3];
    float m_afSecondVector[3];
    unsigned char _pad1[0x0C];
    Timer m_waitTimer;
    Timer m_waitingOutTimer;
    Timer m_firingTimer;
    Timer m_reevaluateTimer;
    Timer m_holdingGroundTimer;
    Timer m_targetBlockedTimer;
};
