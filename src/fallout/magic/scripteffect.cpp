// fallout/magic/scripteffect.cpp: ScriptEffect (14 functions)

#include "../../../include/Actor.h"
#include "../../../include/ScriptEffect.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/ScriptLocalVariable.h"
#include "../../../include/ScriptLocals.h"
#include "../../../include/TESSaveLoadGame.h"
#include "../../../include/TESForm.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/Script.h"
#include "../../../include/BGSLoadFormBuffer.h"

// @fnv 0x00827bd0
void ScriptEffect::Update(float elapsed)
{
    if (pScript)
    {
        pScript->AdvanceScript(FUN_0059bb30()->GetMagicTargetReference(), m_pScriptLocals, elapsed);
    }
}
// Loads the script effect's saved state: reads a has-locals flag, then loads script locals into the cached ScriptLocals or a temporary one.
// @fnv 0x00827e60
void ScriptEffect::LoadGame(BGSLoadFormBuffer* buffer)
{
    ActiveEffect::LoadGame(buffer);
    unsigned char hasLocals = 0;
    buffer->ReadTypedData(&hasLocals, 1);
    if (hasLocals)
    {
        if (!m_pScriptLocals)
            m_pScriptLocals = pScript->GetOrCreateScriptLocals();
        if (m_pScriptLocals)
            m_pScriptLocals->LoadGame(buffer);
        else
        {
            ScriptLocals locals;
            locals.LoadGame(buffer);
        }
    }
}

// Reverts the form, then resets the cached script locals when present.
// @fnv 0x00827de0
void ScriptEffect::Revert(Actor* apActor)
{
    ActiveEffect::Revert(apActor);
    if (m_pScriptLocals)
        m_pScriptLocals->LoadGame();
}

void* __cdecl operator new(unsigned int);

struct SCRIPT_LOCAL_LIST
{
    ScriptLocalVariable* item;
    SCRIPT_LOCAL_LIST* next;
    bool FUN_008256d0();
    ScriptLocalVariable*& FUN_006815c0();
    SCRIPT_LOCAL_LIST* FUN_00726070();
};

struct ScriptEventListStub
{
    int a;
    int b;
};

// @fnv 0x00827930
void ScriptEffect::CopyData(ActiveEffect* apDestination)
{
    ActiveEffect::CopyData(apDestination);
    ScriptEffect* pse = dynamic_cast<ScriptEffect*>(apDestination);
    if (pse)
    {
        pse->pScript = pScript;
        if (pScript && m_pScriptLocals)
        {
            pse->m_pScriptLocals = pScript->GetOrCreateScriptLocals();
            pse->m_pScriptLocals->CopyActionListFrom(m_pScriptLocals);
            SCRIPT_LOCAL_LIST* pLocalEntry = (SCRIPT_LOCAL_LIST*)m_pScriptLocals->GetLocalList();
            while (pLocalEntry && !pLocalEntry->FUN_008256d0())
            {
                pse->m_pScriptLocals->SetVariable(pLocalEntry->FUN_006815c0()->uiID, pLocalEntry->FUN_006815c0()->fValue);
                pLocalEntry = pLocalEntry->FUN_00726070();
            }
            if (m_pScriptLocals->m_pExtendedLocals)
                pse->m_pScriptLocals->m_pExtendedLocals = reinterpret_cast<ScriptDefinition*>(new ScriptEventListStub);
        }
    }
}

// Deletes the cached script locals before destroying the active-effect base.
// @fnv 0x008277f0
ScriptEffect::~ScriptEffect()
{
    if (m_pScriptLocals)
        delete m_pScriptLocals;
}

// Allocates and constructs a ScriptEffect from the caster, magic item and effect item.
// @fnv 0x00827a40
ScriptEffect* CreateScriptEffect(MagicCaster* apCaster, MagicItem* apItem, EffectItem* apEffect)
{
    return new ScriptEffect(apCaster, apItem, apEffect);
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x00827c20
unsigned short ScriptEffect::GetSaveSize(Actor* apActor)
{
    unsigned short usSaveSize = 0;
    usSaveSize += ActiveEffect::GetSaveSize(apActor);
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x2a)
        usSaveSize += 2;
    if (m_pScriptLocals)
        usSaveSize += m_pScriptLocals->GetSaveSize();
    return usSaveSize;
}

extern unsigned int _data_011c16bc;

// @fnv 0x00827880
ActiveEffect* ScriptEffect::Copy()
{
    ScriptEffect* pEffect = new ScriptEffect(m_pEffectInstance, pSpell, this->pEffect);

    CopyData(pEffect);

    return pEffect;
}

struct ScriptExtended
{
    void RunScriptOnTarget(TESObjectREFR*);
};
struct TargetContext
{
    virtual void unused();
    virtual TESObjectREFR* GetActor(ScriptLocals*);
};
// If pScript is set, gets its ScriptLocals and passes the actor from the target context to ScriptExtended::RunScriptOnTarget.
// @fnv 0x00827ac0
void ScriptEffect::Start()
{
    if (pScript != 0)
    {
        m_pScriptLocals = pScript->GetOrCreateScriptLocals();
        ((ScriptExtended*)pScript)->RunScriptOnTarget(((TargetContext*)FUN_0059bb30())->GetActor(m_pScriptLocals));
    }
}

// The shared no-buffer overload names retain their legacy symbol bindings.
void __fastcall WriteScriptLocals(ScriptLocals* locals);

// @fnv 0x00827ca0
void ScriptEffect::SaveGame(Actor* apActor)
{
    ActiveEffect::SaveGame(apActor);
    unsigned short count = 0;
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x2a)
    {
        if (m_pScriptLocals)
        {
            count = m_pScriptLocals->GetSaveSize();
        }
        g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&count, 2u);
    }
    if (g_TESSaveLoadGame->FUN_008df040() < 0x2a)
    {
        count = 1;
    }
    if (count)
    {
        WriteScriptLocals(m_pScriptLocals);
    }
}

// @fnv 0x00827d30
void ScriptEffect::LoadGame(Actor* apActor)
{
    ActiveEffect::LoadGame(apActor);
    unsigned short flag = 0;
    if (g_TESSaveLoadGame->FUN_008df040() >= 42)
    {
        g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&flag, 2);
    }
    if (g_TESSaveLoadGame->FUN_008df040() < 42)
    {
        flag = 1;
    }
    if (flag)
    {
        if (m_pScriptLocals == 0)
        {
            m_pScriptLocals = pScript->GetOrCreateScriptLocals();
        }
        if (m_pScriptLocals != 0)
        {
            m_pScriptLocals->SaveGame();
        }
        else
        {
            g_TESSaveLoadGame->FUN_00857bd0(flag);
        }
    }
}

// Saves the base effect and the cached locals when present.
// @fnv 0x00827e10
void ScriptEffect::SaveGame(BGSSaveFormBuffer* apBuffer)
{
    ActiveEffect::SaveGame(apBuffer);

    bool bValue = m_pScriptLocals;
    apBuffer->FUN_00865e50(&bValue, 1, 0);

    if (bValue)
        m_pScriptLocals->SaveGame(apBuffer);
}

struct Cell827b
{
    virtual void v00();
    virtual void* v01(ScriptLocals* apLocals);
};
struct FUN_005ac380_t
{
    void FUN_005ac380(void*);
};
// @fnv 0x00827b20
void ScriptEffect::Finish()
{
    if (pScript && (!g_TESSaveLoadGame->FUN_0047c850() ||
                    g_TESSaveLoadGame->FUN_0047c850()))
    {
        ((FUN_005ac380_t*)pScript)->FUN_005ac380(((Cell827b*)FUN_0059bb30())->v01(m_pScriptLocals));
    }
    if (m_pScriptLocals)
    {
        delete m_pScriptLocals;
        m_pScriptLocals = 0;
    }
}
