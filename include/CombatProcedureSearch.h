#pragma once

#include "CombatProcedure.h"
#include "TimeoutTimer.h"

class Actor;
class Output;

class CombatProcedureSearch : public CombatProcedure
{
public:
    struct Location
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0c;

        void Init();
        void* FUN_006815c0();
        void* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        double BGSWorldLocation_GetDistanceSquared(const Location*);
        void BGSWorldLocation_SaveGame(BGSSaveFormBuffer*);
        void BGSLoadGameBuffer_LoadBGSWorldLocation(BGSLoadFormBuffer*);
    };

    CombatProcedureSearch();
    virtual ~CombatProcedureSearch();
    virtual void Unk04() override;
    virtual void Unk0c() override;
    virtual void d05() override;
    virtual void OnInventoryItemChanged(TESObjectREFR* apRef, TESBoundObject* apObject,
                                        int aiCount, bool abActivatedScriptOnly) override;
    virtual int GetType() override;
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer) override;
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer) override;
    virtual void vf16() override;

    void* Destroy(unsigned int flags);
    void UpdateSearchState();
    void UpdateEngageTarget();
    void PrintDebugInfo(Output* output, int x, int y);
    void ClearRefIfMatches(TESObjectREFR* apRef, TESBoundObject* apObject,
                          int aiCount, bool abActivatedScriptOnly);
    void RevertAndResolveRef(BGSLoadFormBuffer* apLoadGameBuffer);
    Actor* CombatProcedure_GetAttacker();
    void* GetTarget_00996e00();
    void CombatProcedure_SetFailed(const char*);
    void SetMoveMode_00996e20(int);
    void ClearMoveMode();

    unsigned int state;
    TimeoutTimer timer14;
    TimeoutTimer timer1c;
    TimeoutTimer timer24;
    Location location;
    TESObjectREFR* m_pReference;
};
