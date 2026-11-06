#pragma once

#include "ActiveEffect.h"
#include "Script.h"
#include "ScriptLocals.h"

class ScriptEffect : public ActiveEffect
{
public:
    virtual ~ScriptEffect();
    virtual ActiveEffect* Copy();
    virtual void Update(float afElapsedSeconds);
    virtual unsigned short GetSaveSize(Actor* apActor);
    virtual void SaveGame(Actor* apActor);
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(Actor* apActor);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void Revert(Actor* apActor);
    virtual void CopyData(ActiveEffect* apOther);
    virtual void Start();
    virtual void Finish();

    Script* pScript;
    ScriptLocals* m_pScriptLocals;

    ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
    void Destroy(bool);
};
