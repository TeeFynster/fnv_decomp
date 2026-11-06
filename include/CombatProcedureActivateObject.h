#pragma once

#include "CombatProcedure.h"

class TESObjectREFR;
class TESBoundObject;

class CombatProcedureActivateObject : public CombatProcedure
{
public:
    CombatProcedureActivateObject(TESObjectREFR* apTargetRef, TESBoundObject* apBoundObject);
    virtual ~CombatProcedureActivateObject();

    virtual void Unk04();
    virtual void Unk10(int);
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);

    int FUN_006e4ba0();
    void FUN_009ca740();
    void FUN_009ca760();
    void FUN_009caac0(const char* msg);
    void FUN_009caac0(int arg1);
    void SetState();
    void FUN_009cab00(TESObjectREFR* apRef);
    void vf04(TESObjectREFR* apRef);
    void FUN_009cacb0(BGSSaveFormBuffer* apBuffer);
    void FUN_009cad00(BGSLoadFormBuffer* apBuffer);
    void FUN_009cad70(unsigned int arg);

    TESObjectREFR* m_pReference;
    TESBoundObject* m_pBaseObject;
    union
    {
        char m_cValue24;
        char cAnimState;
        char bFlag;
        signed char status;
    };
};
