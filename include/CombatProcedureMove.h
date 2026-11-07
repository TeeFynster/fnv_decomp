#pragma once

#include "CombatProcedure.h"
#include "GO.h"
#include "NiPoint3.h"
#include "TimeoutTimer.h"

class DebugDisplay;
class MoveInput;
class MoveRef;
class MoveRequest;
class MoveVec;
class Output052;
class OutputValue;

class CombatProcedureMove : public CombatProcedure
{
public:
    struct Location
    {
        unsigned int x;
        unsigned int y;
        unsigned int z;
        unsigned int w;

        Location();
        MoveVec* Point();
        float Distance(const Location&);
        MoveVec Position();
        void Set(const MoveVec&, int);
        void BGSWorldLocation_SaveGame(void* buffer);
        void BGSLoadGameBuffer_LoadBGSWorldLocation(void* buffer);
    };

    CombatProcedureMove(MoveInput* input, float speed, unsigned int flags);
    virtual ~CombatProcedureMove();

    virtual void Unk04();
    virtual void Unk0c();
    virtual void Unk10(int);
    virtual void d05();
    virtual void d11();
    virtual void d12();
    virtual int GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void vf16();

    void FUN_009d6ba0();
    void* DestroyIfFlagged(unsigned int flags);
    void Update_009d6ca0();
    void UpdateCombatMovement();
    void ClearTargetRef(TESObjectREFR* apRef);
    void PrintDebugInfo(DebugDisplay* display, int x, int y);
    void StartedPlanning();
    void FinishedPlanning();
    void SaveGame_009d8880(BGSSaveFormBuffer* buffer);
    void LoadGame_009d89a0(BGSLoadFormBuffer* buffer);
    void InitLoadGame_009d8ad0(unsigned int value);
    float GetHidingTime();
    void UpdateOutput(OutputValue* output);
    bool UpdateMovementRequest(Output052* output);

    MoveRef* Actor();
    MoveRef* Target();
    bool Begin();
    void Fail(const char*);
    void Clear();
    float Duration();
    void Look(const MoveVec&, unsigned char);
    void SetState(int);
    void Reset();
    void Avoid(MoveRequest*);

    unsigned int unk10;
    Location startTransform;
    Location currentTransform;
    float rate;
    unsigned int target38;
    unsigned int mode;
    TimeoutTimer pos40;
    NiPoint3 pos48;
    bool active54;
    unsigned char unk55[3];
    GO state58;
    bool active5C;
    unsigned char unk5D[3];
    int unk60;
    TimeoutTimer state64;
    TimeoutTimer state6C;
    TimeoutTimer state74;
};
