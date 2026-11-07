#pragma once

#include "CombatProcedure.h"
#include "NiPoint3.h"
#include "TimeoutTimer.h"

class Actor;

class CombatProcedureAttackRanged : public CombatProcedure
{
public:
    CombatProcedureAttackRanged();
    virtual ~CombatProcedureAttackRanged();
    virtual void Unk04();
    virtual void Unk0c();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    void Disarmed_009d1dc0(Actor* apOpponent);
    void CombatProcedure_SetFailed(const char* str);

    unsigned int m_10;
    NiPoint3 m_14;
    TimeoutTimer m_20;
    TimeoutTimer m_28;
    TimeoutTimer m_30;
    TimeoutTimer m_38;
    TimeoutTimer m_40;
};
