#pragma once

#include "TESPackage.h"

class BGSSaveFormBuffer;

// 0x9c bytes (object_sizes.csv; the new in HighProcess::ShouldProcessActor pushes 0x9c); fields from the ctor 0x009f9250
// and the save/load routines in trespasspackage.cpp.
class TrespassPackage : public TESPackage
{
public:
    TrespassPackage(Actor* actor, TESForm* owner, TESObjectCELL* cell, int type);   // 0x009f9250
    virtual ~TrespassPackage();
    virtual void SaveGameLegacy(unsigned int changedFlags) override;
    virtual void LoadGame(BGSLoadFormBuffer* arg) override;
    virtual void Unk_19(void* arg) override;
    virtual unsigned short GetSaveSize() override;
    virtual unsigned short SaveGameTESAlt() override;
    virtual unsigned short LoadGameTESAlt() override;
    virtual void InitLoadGameTES() override;

    void SetTrespassEnabled(bool enabled);
    int FUN_009185e0();
    float BGSProjectile_GetExplosionTimer();
    void TrespassPackage_ModWarningTimer(float);
    void TrespassPackage_ModWarningCount(int);   // 0x009f94d0
    void* __thiscall FUN_009f9220(unsigned int flags);
    void __thiscall FUN_009f9450();
    unsigned short GetSaveSize_009f9500();
    void __thiscall SaveFormRefs();
    void __thiscall LoadTrespassPackage();
    void __thiscall SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
    void __thiscall LoadGame_009f9840(BGSLoadFormBuffer*);
    void __thiscall InitLoadGame_009f98e0(unsigned int);

    float fUnk80;                // 0x80
    unsigned int uiUnk84;        // 0x84 (ctor 0)
    TESForm* pOwner;             // 0x88 (ctor arg 2)
    TESObjectCELL* pCell;        // 0x8c (ctor arg 3)
    int iUnk90;                  // 0x90 (ctor -1)
    int iType;                   // 0x94 (ctor arg 4)
    unsigned int uiUnk98;        // 0x98 (ctor 0)
};
