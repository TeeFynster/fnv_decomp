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
        void* FUN_0084e3a0();
        double FUN_00527a40(const Location*);
        void FUN_00527b70(BGSSaveFormBuffer*);
        void FUN_00527ba0(BGSLoadFormBuffer*);
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
    Actor* FUN_00996de0();
    void* FUN_00996e00();
    void FUN_009caac0(const char*);
    void FUN_00996e20(int);
    void FUN_00996e40();

    unsigned int state;
    TimeoutTimer timer14;
    TimeoutTimer timer1c;
    TimeoutTimer timer24;
    Location location;
    TESObjectREFR* m_pReference;
};
