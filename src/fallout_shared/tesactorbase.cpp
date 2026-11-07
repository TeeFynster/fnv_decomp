#include "../../include/ProcessLists.h"
// fallout_shared/tesactorbase.cpp: TESActorBase and Reset3DMobIterator (23 functions)

#include "../../include/TESActorBase.h"
#include "../../include/BGSBodyPartData.h"
#include "../../include/BGSSaveGameBuffer.h"
#include "../../include/BGSLoadGameBuffer.h"
#include "../../include/BGSLoadFormBuffer.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESDataHandler.h"
#include "../../include/BaseProcess.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESBoundObject.h"
#include "../../include/MissileProjectile.h"
// The original constructor installs its vtable explicitly after base initialization.
class __declspec(novtable) Reset3DMobIterator;
#include "../../include/Reset3DMobIterator.h"

// Unit-specific declarations; TESForm and TESFullName come from the shared headers.
#include "../../include/SEX.h"
#include "../../include/ENUM_FORM_ID.h"
#include "../../include/TESSaveLoadGame.h"

class Crime
{
  public:
    void LoadGame(BGSLoadGameBuffer*);
};

extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;


extern ProcessLists g_kProcessLists;
extern PlayerCharacter* g_thePlayer;
extern "C" void* DAT_01047670;

// @fnv 0x0048cee0
SEX TESActorBase::GetSex()
{
    return reinterpret_cast<MissileProjectile*>(reinterpret_cast<char*>(this) + 4)->GetCharacterSex();
}

// Returns true if the form is an actor base (type 42) whose actor base data has flag 0x10 set; otherwise false.
// @fnv 0x005f0d00
bool TESActorBase::IsAutoCalculated() const
{
    if (reinterpret_cast<const TESForm*>(this)->GetFormType() == 42)
        return reinterpret_cast<const TESActorBaseData*>(reinterpret_cast<const char*>(this) + 0x30)->GetFlag(0x10);
    return false;
}

// @fnv 0x005f1630
void TESActorBase::NotifyFormIDChanged(int changeFlags)
{
    if (g_dataHandler->FormIDExists(reinterpret_cast<TESForm*>(this)->GetFormID()))
    {
        if (g_BGSSaveLoadGame->ShouldSaveForm(reinterpret_cast<TESForm*>(this), false))
            reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)->AddFormChangeFlags(changeFlags);
    }
    else
        reinterpret_cast<TESForm*>(this)->NotifyFormIDChanged(changeFlags);
}

// Loads the actor base from the buffer: base form, actor data, crime, attributes, AI form, and optionally the full name when change flag 0x20 is set.
// @fnv 0x005f1fd0
void TESActorBase::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::LoadGame(buffer);
    reinterpret_cast<TESActorBaseData*>(reinterpret_cast<char*>(this) + 0x30)->LoadGame_0047ea70(buffer);
    reinterpret_cast<Crime*>(reinterpret_cast<char*>(this) + 0x7c)->LoadGame(buffer);
    reinterpret_cast<TESAttributes*>(reinterpret_cast<char*>(this) + 0xb8)->LoadDataIfChanged(buffer);
    reinterpret_cast<TESAIForm*>(reinterpret_cast<char*>(this) + 0x90)->LoadGame(buffer);
    if (buffer->GetChangeFlags(0x20u).operator bool())
    {
        char name[264];
        buffer->LoadString(name);
        reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 0xd0)->SetFullName(static_cast<const char*>(name));
    }
}

// @fnv 0x005f2150
Reset3DMobIterator::Reset3DMobIterator()
{
    *reinterpret_cast<void**>(this) = &DAT_01047670;
}

// If reset is set, runs the 3D mob iterator over this actor base twice and resets the player's process 3D when this is the player's base.
// @fnv 0x005f20a0
// src: COMMUNITY 0x005f20a0
void TESActorBase::Reset3DForLoadedActors(bool reset)
{
    if (!reset)
        return;
    Reset3DMobIterator mobIter;
    mobIter.base = this;
    mobIter.reset = reset;
    mobIter.FUN_006ecd40(0);
    g_kProcessLists.ProcessMobileObjects(&mobIter);
    mobIter.FUN_006ecd40(1);
    g_kProcessLists.ProcessMobileObjects(&mobIter);
    if (g_thePlayer->GetActorBase() == this)
    {
        if (g_thePlayer->GetProcess())
            g_thePlayer->GetProcess()->ResetActorModel((RESET_3D_FLAGS)reset);
    }
}

// If the actor's object reference equals base and it has a process, resets that process's 3D state with reset.
// @fnv 0x005f2170
void Reset3DMobIterator::operator()(Actor* actor)
{
    if (actor->GetObjectReference() == base && actor->GetProcess())
        actor->GetProcess()->ResetActorModel((RESET_3D_FLAGS)reset);
}

// 0x005f15c6/0x005f1608 construct the by-value argument from int at 0x008c71b0.
// @fnv 0x005f1590
bool TESActorBase::ShouldUseDefaultAppearance(TESObjectREFR* ref)
{
    bool result = true;
    if (g_BGSSaveLoadGame->BGSSaveLoadGame_GetSaveGameLoading())
    {
        if (static_cast<Actor*>(ref)->TESForm_IsStillLoading() &&
            g_BGSSaveLoadGame->HasFormChangeFlags(reinterpret_cast<TESForm*>(ref), 0x08000020))
            result = false;
    }
    else
    {
        if (ref->HasHealth(false) &&
            g_BGSSaveLoadGame->HasFormChangeFlags(reinterpret_cast<TESForm*>(ref), 0x400))
            result = false;
    }
    return result;
}


struct VTableHolder_005f0b00
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual int vfn_4();
};

// @fnv 0x005f0b00
// src: XBOX_PDB 0x005f0b00
int TESActorBase::GetHealth_005f0b00()
{
    return ((VTableHolder_005f0b00*)((char*)this + 0xb0))->vfn_4();
}


// @fnv 0x005f0b50
// src: XBOX_PDB 0x005f0b50
bool TESActorBase::DoesSwim()
{
    if (static_cast<const TESForm*>(this)->GetFormType() == 0x2b)
    {
        if (reinterpret_cast<TESActorBaseData*>((char*)this + 0x30)->GetFlag(0x10) ||
            reinterpret_cast<TESActorBaseData*>((char*)this + 0x30)->GetFlag(1))
            return true;
        else
            return false;
    }
    return true;
}


// @fnv 0x005f0c80
// src: XBOX_PDB 0x005f0c80
bool TESActorBase::IsImmobile()
{
    if (static_cast<const TESForm*>(this)->GetFormType() == 0x2b)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x800000))
            return true;
        else
            return false;
    }
    return false;
}

// @fnv 0x005f0f80
// src: COMMUNITY 0x005f0f80
BGSBodyPartData* __fastcall TESActorBase_GetBodyPartData(TESActorBase* apActorBase)
{
    if (BGSBodyPartData::ms_pBodyPartDataInstance && apActorBase == g_thePlayer->GetActorBase())
        return BGSBodyPartData::ms_pBodyPartDataInstance;
    return BGSBodyPartData::ms_pBodyPartData;
}


// @fnv 0x005f0b30
// src: COMMUNITY 0x005f0b30
void TESActorBase::SetHealth_005f0b30(int aiValue)
{
    ((Reset3DMobIterator*)((char*)this + 0xb0))->FUN_006ecd40(aiValue);
}



// @fnv 0x005f0ba0
// src: XBOX_PDB 0x005f0ba0
bool TESActorBase::FightsInWater()
{
    if (!DoesSwim())
        return false;
    if (static_cast<const TESForm*>(this)->GetFormType() == 0x2b)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x40000))
            return false;
    }
    return true;
}

// Exe 0x005f0f50: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct TesactorbaseOffset08View
{
    unsigned int GetFlags();
};

struct FUN_005f0f50_shell : TesactorbaseOffset08View
{
    char HasFlag80000();
};

// @fnv 0x005f0f50
char __thiscall FUN_005f0f50_shell::HasFlag80000()
{
    unsigned int flags = GetFlags();
    return (flags & 0x80000) != 0;
}

// Returns true if this form is an actor base (type 0x2B) whose actor base data has flag 0x20 set; otherwise false.
// @fnv 0x005f0c40
// src: XBOX_PDB 0x005f0c40
bool TESActorBase::DoesFly()
{
    if (static_cast<const TESForm*>(this)->GetFormType() == 0x2B)
    {
        if (((TESActorBaseData*)((char*)this + 0x30))->GetFlag(0x20))
            return true;
        else
            return false;
    }
    return false;
}

struct TESForm_Hack
{
    void MarkAsUnmodified(unsigned int);
};
// @fnv 0x005f1690
// src: XBOX_PDB 0x005f1690
void TESActorBase::RemoveChange(int aiChangeFlags)
{
    if (g_dataHandler->FormIDExists(GetFormID()) && g_BGSSaveLoadGame->IsFormChanged(this))
        ((TESActorBaseData*)((char*)this + 0x30))->ClearChangeFlags(aiChangeFlags);
    else
        ((TESForm_Hack*)this)->MarkAsUnmodified(aiChangeFlags);
}

struct FNStub
{
    const char* GetFullName();
};
struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0048e040_holder
{
    void TESSpellList_SaveGameBGS(unsigned int);
};
// @fnv 0x005f1f30
// src: XBOX_PDB 0x005f1f30
void TESActorBase::SaveGame_005f1f30(unsigned int buffer)
{
    ((FUN_00484d60_holder*)this)->SaveIfChanged(buffer);
    ((TESActorBaseData*)((char*)this + 0x30))->SaveGame((BGSSaveFormBuffer*)buffer);
    ((FUN_0048e040_holder*)((char*)this + 0x7c))->TESSpellList_SaveGameBGS(buffer);
    ((TESAttributes*)((char*)this + 0xb8))->SaveGame((BGSSaveFormBuffer*)buffer);
    ((TESAIForm*)((char*)this + 0x90))->SaveGame((BGSSaveFormBuffer*)buffer);
    if (((BGSLoadFormBuffer*)buffer)->GetChangeFlags(0x20u).operator bool())
    {
        const char* pfullname = ((FNStub*)((char*)this + 0xd0))->GetFullName();
        ((BGSSaveGameBuffer*)buffer)->SaveGameString(pfullname, 0);
    }
}

// Returns true unless the form type is 0x2B and neither the 0x40 nor the 1 flag is set in abd.
// @fnv 0x005f0bf0
// src: XBOX_PDB 0x005f0bf0
bool TESActorBase::DoesWalk()
{
    if (((const TESForm*)this)->GetFormType() == 0x2B)
    {
        if (TESActorBaseData::GetFlag(0x40) || TESActorBaseData::GetFlag(1))
            return true;
        else
            return false;
    }
    return true;
}

extern int DAT_011840c4, DAT_01183028, DAT_01183998, DAT_01186fcc, DAT_01183a34;
extern float DAT_01016410;
void* __cdecl FUN_00ec43fb(void*, int, void*, void*, int);
struct ComponentTarget
{
    unsigned int FUN_00726070();
};
struct ItemTarget
{
    float TESObjectARMO_GetArmorRating();
    float TESObjectARMO_GetDamageThreshold();
};
int __cdecl FUN_004873d0(void*);
float __cdecl CombatFormulas_CalcWeaponDamage(void*, void*, float, float, int, int, int, int);
float __cdecl ConvertUIntToFloat(unsigned int);
double __cdecl FUN_00646360(unsigned short, float);
// Looks up a form by type and returns a value derived from the matching item, component or constant, defaulting to 0.0f.
// @fnv 0x005f0d60
// src: XBOX_PDB 0x005f0d60
float TESActorBase::GetDesirability(TESForm* form)
{
    float result = 0.0f;
    if (form)
    {
        switch (form->FUN_00401170())
        {
        case 41: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_011840c4, 0);
            if (item)
                result = 1.0f;
            break;
        }
        case 40: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01183998, 0);
            if (item && FUN_004873d0(item))
            {
                float condition = 1.0f;
                enum
                {
                    actorComponentOffset = 0x100
                };
                result = CombatFormulas_CalcWeaponDamage(this ? reinterpret_cast<char*>(this) + actorComponentOffset : 0, item, condition,
                                      1.0f, 0, 0, 0, 0);
            }
            break;
        }
        case 26: {
            void* item = FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01186fcc, 0);
            if (item)
            {
                enum
                {
                    itemComponentOffset = 0x58
                };
                result = ConvertUIntToFloat(
                    reinterpret_cast<ComponentTarget*>(reinterpret_cast<char*>(item) + itemComponentOffset)
                        ->FUN_00726070());
            }
            break;
        }
        case 24: {
            ItemTarget* item = static_cast<ItemTarget*>(FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01183a34, 0));
            if (item && FUN_004873d0(item))
            {
                float condition = 1.0f;
                result =
                    FUN_00646360(static_cast<unsigned short>(item->TESObjectARMO_GetArmorRating()), condition) + item->TESObjectARMO_GetDamageThreshold();
            }
            break;
        }
        case 30:
            result = DAT_01016410;
            break;
        }
    }
    return result;
}

struct FormIDEntry
{
    unsigned int formID;
    unsigned char type;
    unsigned char flags;
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;

struct SaveSizeNamedForm
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
};
SaveSizeNamedForm* LookupFormByIDForSize(unsigned int formID);

int __cdecl SaveSizeMessage(const char* fmt, ...);
unsigned int BSStringLength(const char* str);

struct SaveSizeFormPart
{
    int unk00;
    unsigned short GetSaveSize(unsigned int changeFlags);
};
struct SaveSizeContainer
{
    int unk00;
    unsigned short GetSaveSizeCont(unsigned int changeFlags);
};


// Accumulates the save size of the actor base's parts and optionally logs the total with the current form's ID and editor ID.
// @fnv 0x005f16f0
// src: XBOX_PDB 0x005f16f0
unsigned short TESActorBase::GetSaveSize_005f16f0(unsigned int changeFlags)
{
    unsigned short totalSize = 0;
    unsigned short startSize = totalSize;
    if (g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        totalSize += 4;
        totalSize += 2;
    }
    if (g_TESSaveLoadGame->FUN_008df040() >= 0x6d)
    {
        totalSize += ((SaveSizeFormPart*)this)->GetSaveSize(changeFlags);
    }
    totalSize += ((TESAttributes*)((char*)this + 0xb8))->GetSaveSize(changeFlags);
    totalSize += ((TESActorBaseData*)((char*)this + 0x30))->GetSaveSize(changeFlags);
    totalSize += ((SaveSizeContainer*)((char*)this + 0x7c))->GetSaveSizeCont(changeFlags);
    totalSize += ((TESAIForm*)((char*)this + 0x90))->TESAIForm::GetSaveSize(changeFlags);
    if (changeFlags & 0)
    {
        totalSize += 4;
    }
    if (changeFlags & 0x20)
    {
        totalSize += 1;
        totalSize += BSStringLength(((FNStub*)((char*)this + 0xd0))->GetFullName());
    }
    if (*g_011de4e8.Bool())
    {
        FormIDEntry* pFormHeader = (FormIDEntry*)g_TESSaveLoadGame->FUN_004fd3e0();
        if (pFormHeader)
        {
            SaveSizeNamedForm* namedForm = LookupFormByIDForSize(pFormHeader->formID);
            SaveSizeMessage("GetSaveSize(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                            totalSize - startSize, pFormHeader->formID, namedForm->GetEditorID(),
                            *(unsigned int*)&pFormHeader->flags, 550,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
        else
        {
            SaveSizeMessage("GetSaveSize(): %-5i ending at line %i in file %s", totalSize - startSize, 550,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
    }
    return totalSize;
}

namespace fnv_005f18c0 {
struct SaveRecord
{
    unsigned int formID;
    unsigned char type;
    unsigned char flagsLow;
    unsigned char flagsByte1;
    unsigned char flagsByte2;
    unsigned char flagsByte3;
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct SaveInventory
{
    void SaveSpellList(unsigned int);
};
struct SaveList
{
    unsigned int FUN_00726070();
};
struct SaveFormAccess
{
    void TESForm_SaveGame(unsigned int);
    void TESForm_SaveGameDataOLD(const void*, int);
};
struct SaveForm
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* Describe();
};
SaveForm* TESForm_GetFormByNumericID(unsigned int);
unsigned int BSstrlen(const char*);
void ProgramFlow(const char*, ...);
void FNV_Warning(const char*, ...);

}  // namespace fnv_005f18c0

// @fnv 0x005f18c0
// src: XBOX_PDB 0x005f18c0
void TESActorBase::SaveGame_005f18c0(unsigned int flags)
{
    using namespace fnv_005f18c0;
    unsigned short size = 0;
    unsigned short* pos2 = 0;
    unsigned int offset2 = fnv_005f18c0::g_TESSaveLoadGame->GetTimeStamp();
    if (*fnv_005f18c0::g_011de4e8.Bool())
        offset2 = fnv_005f18c0::g_TESSaveLoadGame->GetTimeStamp();
    if (fnv_005f18c0::g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int tag = 0x424c4f4b;
        fnv_005f18c0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&tag, 4);
        pos2 = (unsigned short*)fnv_005f18c0::g_TESSaveLoadGame->GetTimeStamp();
        fnv_005f18c0::g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&size, 2);
    }
    if (fnv_005f18c0::g_TESSaveLoadGame->FUN_008df040() >= 109)
        ((SaveFormAccess*)this)->TESForm_SaveGame(flags);
    ((TESAttributes*)((char*)this + 0xb8))->SaveGame(flags);
    ((TESActorBaseData*)((char*)this + 0x30))->SaveGame(flags);
    ((SaveInventory*)((char*)this + 0x7c))->SaveSpellList(flags);
    ((TESAIForm*)((char*)this + 0x90))->TESAIForm::SaveGame(flags);
    if (flags & 0)
    {
        unsigned int first = ((SaveList*)((char*)this + 0xb0))->FUN_00726070();
        ((SaveFormAccess*)this)->TESForm_SaveGameDataOLD(&first, 4);
    }
    if (flags & 0x20)
    {
        const char* data = ((FNStub*)((char*)this + 0xd0))->GetFullName();
        unsigned char pos = (unsigned char)BSstrlen(data);
        ((SaveFormAccess*)this)->TESForm_SaveGameDataOLD(&pos, 1);
        if (pos)
            ((SaveFormAccess*)this)->TESForm_SaveGameDataOLD(data, pos);
    }
    if (*fnv_005f18c0::g_011de4e8.Bool())
    {
        unsigned int end = fnv_005f18c0::g_TESSaveLoadGame->GetTimeStamp();
        SaveRecord* record = (SaveRecord*)fnv_005f18c0::g_TESSaveLoadGame->GetHitSound();
        if (record)
        {
            fnv_005f18c0::SaveForm* form = fnv_005f18c0::TESForm_GetFormByNumericID(record->formID);
            ProgramFlow("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                         end - offset2, record->formID, form->Describe(), *(unsigned int*)&record->flagsLow, 587,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
        else
        {
            ProgramFlow("SaveGame(): %-5i ending at line %i in file %s", end - offset2, 587,
                         "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp");
        }
    }
    if (fnv_005f18c0::g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int current = fnv_005f18c0::g_TESSaveLoadGame->GetTimeStamp();
        unsigned int block = (unsigned int)pos2;
        if (current > block + 0xffff)
            FNV_Warning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 587);
        *pos2 = (unsigned short)(current - block);
    }
}


namespace fnv_005f1b30 {
void* __cdecl memset(void*, int, unsigned int);
void __cdecl Warning_005b5e40(const char*, ...);

struct LoadHdr
{
    int id;
    char b04;
    char b05;
    char b06;
    char b07;
    char b08;
    unsigned char ver;
};

struct FormName
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual const char* GetName();
};

FormName* __cdecl TESForm_GetFormByNumericID(unsigned int);

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct Sub7C
{
    int data;
    void LoadSpellList(unsigned int, unsigned int);
};
struct SubB0
{
    int data;
    void FUN_006ecd40(void*);
};
struct SubD0
{
    int data;
    void FUN_00489100(const char*);
};

struct LoadFormAccess
{
    void TESForm_LoadGame(unsigned int, unsigned int);
    void TESForm_LoadGameDataOLD(void*, int);
};

// Reads the actor base block from the save stream, dispatches to sub-structs, and verifies the block boundary against the expected end position.
}  // namespace fnv_005f1b30

// @fnv 0x005f1b30
// src: XBOX_PDB 0x005f1b30
void TESActorBase::LoadGame_005f1b30(unsigned int aiFlags, unsigned int a2)
{
    using namespace fnv_005f1b30;
    FormName* form5;
    LoadHdr* hdrB;
    int hdrWord;
    unsigned int curPosC;
    unsigned short usVarZ;
    usVarZ = 0;
    curPosC = 0;
    if (fnv_005f1b30::g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        fnv_005f1b30::g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&hdrWord, 4);
        if (hdrWord != 0x424c4f4b)
        {
            hdrB = (LoadHdr*)fnv_005f1b30::g_TESSaveLoadGame->BGSProjectile_GetExplosion();
            if (hdrB != 0)
            {
                form5 = TESForm_GetFormByNumericID(hdrB->id);
                Warning_005b5e40(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 596, hdrB->id,
                    form5->GetName(), hdrB->ver, *(int*)((char*)hdrB + 5));
            }
            else
            {
                Warning_005b5e40(
                    "SAVELOAD: (LoadGame Buffer error) Block Header is incorrect in file %s on line %i.  Current version is %i",
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 596,
                    fnv_005f1b30::g_TESSaveLoadGame->FUN_008df040());
            }
        }
        curPosC = fnv_005f1b30::g_TESSaveLoadGame->FUN_00825c00();
        fnv_005f1b30::g_TESSaveLoadGame->TESSaveLoadGame_LoadGameDataOLD(&usVarZ, 2);
    }
    if (fnv_005f1b30::g_TESSaveLoadGame->FUN_008df040() >= 0x6d)
        ((LoadFormAccess*)this)->TESForm_LoadGame(aiFlags, a2);
    ((TESAttributes*)((char*)this + 0xb8))->LoadGame(aiFlags, a2);
    ((TESActorBaseData*)((char*)this + 0x30))->LoadGame(aiFlags, a2);
    ((Sub7C*)((char*)this + 0x7c))->LoadSpellList(aiFlags, a2);
    ((TESAIForm*)((char*)this + 0x90))->TESAIForm::LoadGame(aiFlags, a2);
    if (aiFlags & 0)
    {
        void* scriptVal;
        ((LoadFormAccess*)this)->TESForm_LoadGameDataOLD(&scriptVal, 4);
        ((SubB0*)((char*)this + 0xb0))->FUN_006ecd40(scriptVal);
    }
    if (aiFlags & 0x20)
    {
        unsigned char flagByte;
        char nameBuf[0x104];
        fnv_005f1b30::memset(nameBuf, 0, 0x104);
        ((LoadFormAccess*)this)->TESForm_LoadGameDataOLD(&flagByte, 1);
        if (flagByte != 0)
            ((LoadFormAccess*)this)->TESForm_LoadGameDataOLD(nameBuf, flagByte);
        ((SubD0*)((char*)this + 0xd0))->FUN_00489100(nameBuf);
    }
    if (fnv_005f1b30::g_TESSaveLoadGame->TESSaveLoadGame_UseSaveGameBlocks())
    {
        FormName* form25;
        unsigned int endPos0;
        LoadHdr* hdr2A;
        endPos0 = fnv_005f1b30::g_TESSaveLoadGame->FUN_00825c00();
        hdr2A = (LoadHdr*)fnv_005f1b30::g_TESSaveLoadGame->BGSProjectile_GetExplosion();
        if (hdr2A != 0)
        {
            form25 = TESForm_GetFormByNumericID(hdr2A->id);
            if (endPos0 > usVarZ + curPosC)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    endPos0 - (usVarZ + curPosC),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628, hdr2A->id,
                    form25->GetName(), hdr2A->ver, *(int*)((char*)hdr2A + 5));
            }
            else if (endPos0 < usVarZ + curPosC)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Currently loading form is %08X %s with version %i and flags %08X",
                    (usVarZ + curPosC) - endPos0,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628, hdr2A->id,
                    form25->GetName(), hdr2A->ver, *(int*)((char*)hdr2A + 5));
            }
        }
        else
        {
            if (endPos0 > usVarZ + curPosC)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer overrun of %i bytes in file %s on line %i.  Current version is %i",
                    endPos0 - (usVarZ + curPosC),
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628,
                    fnv_005f1b30::g_TESSaveLoadGame->FUN_008df040());
            }
            else if (endPos0 < usVarZ + curPosC)
            {
                Warning_005b5e40(
                    "SAVELOAD: LoadGame Buffer underrun of %i bytes in file %s on line %i.  Current version is %i",
                    (usVarZ + curPosC) - endPos0,
                    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESActorBase.cpp", 628,
                    fnv_005f1b30::g_TESSaveLoadGame->FUN_008df040());
            }
        }
    }
}

