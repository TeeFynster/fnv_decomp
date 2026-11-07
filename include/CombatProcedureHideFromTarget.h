#pragma once

#include "CombatProcedure.h"
#include "NiPoint3.h"

class Hiding;
class Output;

class CombatProcedureHideFromTarget : public CombatProcedure
{
public:
    struct Clock
    {
        int a;
        int b;

        Clock();
        void FUN_008d7f40(float duration);
        bool expired();
        float elapsed();
        float FUN_00435e00();
        float CombatTimer_GetTargetTime();
        void FUN_009a5eb0(BGSSaveFormBuffer* buffer);
        void FUN_009a5f20(BGSLoadFormBuffer* buffer);
    };

    CombatProcedureHideFromTarget(int aiValue, float afValue, bool abFlag1, bool abFlag2);

    virtual ~CombatProcedureHideFromTarget();
    virtual void Unk04();
    virtual void d05();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    COMBAT_PROCEDURES GetType_009d60e0();
    void Update();
    void PrintState(Output* out, int x, int y);
    void SetMoveMode_00996e20(int mode);
    void SetLookAtPoint(const NiPoint3& point, unsigned char mode);
    void CombatProcedure_SetFailed(const char* message);
    void SetState();

    union
    {
        int state;
        int m_10;
        int m_uiContentCount;
    };
    union
    {
        float duration;
        float m_14;
    };
    Clock clock;
    NiPoint3 destination;
    NiPoint3 rotation;
    union
    {
        Hiding* hiding;
        int m_38;
        int unk38;
    };
    union
    {
        bool keep;
        bool m_3c;
    };
    union
    {
        bool reset;
        bool m_3d;
    };
};
