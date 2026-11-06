#pragma once

class TESObjectREFR;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
enum PTYPE;

class ActorPackageData
{
public:
    ActorPackageData();
    virtual ~ActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    ActorPackageData* FUN_0067d920();
    void FUN_006ecd40(void*);
    TESObjectREFR* FUN_00726070();   // 0x00726070: returns +0x4
    void FUN_009f41c0();             // 0x009f41c0 (HighProcess::Update 0x008eeec0)

    static ActorPackageData* CreatePackageData(PTYPE aeType);
};
