#pragma once

#include "TESPackage.h"

class Actor;
class BGSSaveFormBuffer;

class BackUpPackage : public TESPackage
{
public:
    BackUpPackage();
    virtual ~BackUpPackage();

    virtual void SaveGame(BGSSaveFormBuffer* arg);
    virtual void LoadGame(BGSLoadFormBuffer* arg);
    virtual void Unk_19(void* arg);
    virtual unsigned short GetSaveSize();
    virtual unsigned short SaveGameTESAlt();
    virtual unsigned short LoadGameTESAlt();

    int unk80;
    int unk84;
    int unk88;

    void __thiscall FUN_009ed330();
    void* __thiscall DestroyOrFree(unsigned int flags);
    void ExecuteBackupPackage(Actor* actor);

    void ForwardToBase(void* buffer);
    void __thiscall SaveGame_009edb60(BGSSaveFormBuffer* buffer);
    void __thiscall LoadGameWithBackup(BGSLoadFormBuffer* buffer);
    unsigned short __thiscall GetSaveSize_009ed5f0();
    void SaveBackupPackage();
    void LoadPackageBlock();

    using TESPackage::LoadGame;
};
