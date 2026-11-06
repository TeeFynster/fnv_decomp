#pragma once

#include "CombatProcedure.h"
#include "NiPoint3.h"
#include "TimeoutTimer.h"

class Actor;
class IDebugText;
class NiPoint3;
class Projectile;
class SoundObj;
class Target;

class CombatProcedureAttackGrenade : public CombatProcedure
{
public:
    CombatProcedureAttackGrenade();
    CombatProcedureAttackGrenade(const NiPoint3* src, unsigned char flag);

    virtual ~CombatProcedureAttackGrenade();
    virtual void Unk04();
    virtual void Unk0c();
    virtual void d05();
    virtual void d06();
    virtual void d08();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    void FUN_009cafc0();
    void UpdateWeaponFire();
    NiPoint3 GetPathingPoint();
    NiPoint3* GetPathingPoint(NiPoint3* out);
    bool FUN_009cb380(SoundObj* object, NiPoint3* point, float value);
    bool FUN_009cb380(void* object, int arg, float value);
    bool FUN_009cb460(NiPoint3* output, NiPoint3* input);
    void FUN_009cb830(Projectile* apProjectile);
    void WriteDebugText(IDebugText* debugText, int location, int justify);
    void FUN_009cb9c0(BGSSaveFormBuffer* buffer);
    void FUN_009cba50(BGSLoadFormBuffer* buffer);

    Actor* FUN_00996de0();
    Actor* FUN_00996e00();
    void FUN_009caac0(const char* message);
    void FUN_00996ea0();
    void SetLookAtPoint(NiPoint3* point, int arg);
    void SetState();
    void* ActorGet();
    Target* TargetGet();
    bool Validate(void* object, NiPoint3* point, float value);
    void Reset();

    unsigned char unk10[0x2C];
};
