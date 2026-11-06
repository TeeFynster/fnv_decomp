#pragma once

#include "CombatProcedure.h"

class TESForm;
class TESObjectWEAP;

class CombatProcedureSwitchWeapon : public CombatProcedure
{
public:
    CombatProcedureSwitchWeapon(TESObjectWEAP*);
    virtual ~CombatProcedureSwitchWeapon();
    virtual void Unk04();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);

    void* DestroyIfFlagged(unsigned int flags);
    void UpdateWeaponDraw();

    TESForm* pWeapon;
    bool m_ucWeaponState;
};
