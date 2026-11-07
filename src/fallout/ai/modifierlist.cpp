// fallout/ai/modifierlist.cpp: ModifierListCalc (21 functions)

#include "modifierlist_decls.h"
#include "../../../include/ActorValueModifierList.h"
#include "../../../include/ActorValueInfo.h"
#include "../../../include/GameTimerRecord.h"
#include "../../../include/TESSaveLoadGame.h"

extern "C" int gModifierListIndex[];
extern "C" const double gModifierZero;

// Deletes every Modifier returned by GetItem while removing list heads, then deletes and nulls the stored object.
// @fnv 0x009370b0
void ActorValueModifierList::RemoveAllModifiers()
{
    Modifier* modifier;
    while ((modifier = GetItem()) != 0)
    {
        Modifier* node = modifier;
        ::operator delete(node);
        RemoveHead();
    }

    if (m_ppModifiedActorValues)
    {
        delete m_ppModifiedActorValues;
        m_ppModifiedActorValues = 0;
    }
}

// Removes any existing modifier for key, then stores modifier in the fast-modifier table unless it is null or the zero value with no override.
// @fnv 0x00937280
void ActorValueModifierList::AddFastModifier(char key, Modifier* modifier)
{
    if (!modifier && !m_ppModifiedActorValues)
        return;

    if (m_ppModifiedActorValues)
        m_ppModifiedActorValues->RemoveModifier(key);

    if (!modifier || (modifier->GetValue() == gModifierZero && !m_bAllowZeroValueModifiers))
        return;

    if (!m_ppModifiedActorValues)
        m_ppModifiedActorValues = new ModifierPointerList();

    m_ppModifiedActorValues->m_ppModifiers[gModifierListIndex[key]] = modifier;
}

// @fnv 0x00937760
Modifier* ActorValueModifierList::GetModifierItem(char key)
{
    struct SearchState
    {
        ActorValueModifierList* current;
        Modifier* modifier;
    } searchState;
    searchState.modifier = 0;
    if (m_ppModifiedActorValues && gModifierListIndex[key] < 0x4d)
    {
        searchState.modifier = m_ppModifiedActorValues->m_ppModifiers[gModifierListIndex[key]];
    }
    else
    {
        searchState.current = this;
        while (searchState.current && searchState.current->GetItem() != 0 && !searchState.modifier)
        {
            Modifier* item = searchState.current->GetItem();
            if (item && item->GetKey() == key)
                searchState.modifier = item;
            searchState.current = (ActorValueModifierList*)searchState.current->GetNext();
        }
    }
    return searchState.modifier;
}

// Calls the two-argument overload with a fresh found flag and returns its float result for the given key.
// @fnv 0x00937730
float ActorValueModifierList::GetActorValueModifierAmount(char key)
{
    bool found = false;
    return GetActorValueModifierAmount(key, found);
}

// Looks up the modifier for key, sets found based on whether it exists, and returns its value or 0.0f.
// @fnv 0x009376e0
float ActorValueModifierList::GetActorValueModifierAmount(char key, bool& found)
{
    Modifier* modifier = GetModifierItem(key);
    found = (unsigned char)(modifier != 0);
    return modifier ? modifier->GetValue() : 0.0f;
}

// @fnv 0x00937160
void ActorValueModifierList::CopyModifierListFrom(ActorValueModifierList* apSource)
{
    RemoveAllModifiers();
    if (!apSource)
        return;
    if (apSource->m_ppModifiedActorValues)
        m_ppModifiedActorValues = new ModifierPointerList(apSource->m_ppModifiedActorValues);
    ActorValueModifierList* current = apSource;
    while (current && current->GetItem() != 0)
    {
        Modifier* item = current->GetItem();
        AppendModifier(new Modifier(item));
        current = (ActorValueModifierList*)current->GetNext();
    }
}

// @fnv 0x00937480
void ActorValueModifierList::ModifyModifier(char key, float delta, ClampStyle clamp)
{
    Modifier* modifier = GetModifierItem(key);
    if (!modifier)
    {
        if (delta != gModifierZero || m_bAllowZeroValueModifiers)
        {
            modifier = new Modifier(key, delta);
            AppendModifier(modifier);
        }
    }
    else
    {
        float value = ModifyAndClamp(modifier->GetValue(), delta, clamp);
        modifier->SetValue(value);
        if (modifier->GetValue() == gModifierZero && !m_bAllowZeroValueModifiers)
            EraseModifier(modifier);
    }
}

struct FUN_009375b0_shell : Modifier
{
    Modifier* SetKeyAndValue(char key, float value);
};

// Stores the key character, applies the float value via SetValue, and returns this modifier.
// @fnv 0x009375b0
Modifier* FUN_009375b0_shell::SetKeyAndValue(char key, float value)
{
    cKey = key;
    SetValue(value);
    return this;
}

void* __cdecl operator new(unsigned int);
void __cdecl FastModifierCollection_CheckInitializeMapping();
extern int DAT_011e0750;

// Calls FUN_00937fd0, then allocates an int array of DAT_011e0750 elements, zeroes it, and stores the pointer through pThis.
// @fnv 0x00937d70
// src: XBOX_PDB 0x00937d70
int** __fastcall FastModifierCollection_FastModifierCollection(int** apArrayOut)
{
    FastModifierCollection_CheckInitializeMapping();
    if (DAT_011e0750)
    {
        *apArrayOut = DAT_011e0750 ? new int[DAT_011e0750] : 0;
        for (int i = 0; i < DAT_011e0750; ++i)
        {
            (*apArrayOut)[i] = 0;
        }
    }
    else
    {
        *apArrayOut = 0;
    }
    return apArrayOut;
}

// @fnv 0x009375e0
// src: COMMUNITY 0x009375e0
void ActorValueModifierList::ModifierList_SetModifier(char key, float value)
{
    Modifier* modifier = GetModifierItem(key);
    if (!modifier)
    {
        if (value != gModifierZero || m_bAllowZeroValueModifiers)
        {
            modifier = new Modifier(key, value);
            AppendModifier(modifier);
        }
    }
    else if (value == gModifierZero && !m_bAllowZeroValueModifiers)
    {
        EraseModifier(modifier);
    }
    else
    {
        modifier->SetValue(value);
    }
}

extern double _gModifierZero;

// Adds param1 and param2, then clamps the sum to 0.0f when param3 is 0 (if above _gModifierZero) or 1 (if below), returning the result.
// @fnv 0x00937810
float __cdecl ClampSumByMode(float afValueA, float afValueB, int aiMode)
{
    float result = afValueA + afValueB;
    switch (aiMode)
    {
    case 0:
        if (result > _gModifierZero)
            result = 0.0f;
        break;
    case 1:
        if (result < _gModifierZero)
            result = 0.0f;
        break;
    default:
        break;
    }
    return result;
}

// @fnv 0x00937b30
void ActorValueModifierList::Revert()
{
    RemoveAllModifiers();
}

struct FUN_00936fd0_shell
{
    char cKey;
    FUN_00936fd0_shell* CopyFrom(Modifier*);
};
// Copies the key and value from another Modifier into this one and returns this.
// @fnv 0x00936fd0
FUN_00936fd0_shell* FUN_00936fd0_shell::CopyFrom(Modifier* other)
{
    cKey = other->cKey;
    ((Modifier*)this)->SetValue(other->GetValue());
    return this;
}

void _Deallocate(void*);
struct Unk3713
{
    void FreeArrayItems();
    void* ReleaseIfFlagged(unsigned int);
};
// @fnv 0x00937130
void* Unk3713::ReleaseIfFlagged(unsigned int flags)
{
    FreeArrayItems();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern TESSaveLoadGame* g_TESSaveLoadGame;
struct Host37870
{
    bool ModifierList_WriteModifier(Modifier* p);
};
// @fnv 0x00937870
// src: COMMUNITY 0x00937870
bool Host37870::ModifierList_WriteModifier(Modifier* apModifier)
{
    if (apModifier == 0)
        return false;
    char key = apModifier->GetKey();
    float value = apModifier->GetValue();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&key, 1);
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&value, 4);
    return true;
}

namespace fnv_009379c0 {
extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x009379c0
void __fastcall LoadModifiers(ActorValueModifierList* list)
{
    unsigned short count;
    g_TESSaveLoadGame->ReadTypedData(&count, 2);
    for (unsigned int i = 0; i < count; i++)
    {
        char key;
        float value;
        Modifier* modifier = 0;
        g_TESSaveLoadGame->ReadTypedData(&key, 1);
        g_TESSaveLoadGame->ReadTypedData(&value, 4);
        modifier = new Modifier(key, value);
        list->AppendModifier(modifier);
    }
}
}  // namespace fnv_009379c0

namespace fnv_009378d0 {
struct Modifier;

struct BSSimpleList_helper
{
    Modifier** _ref_006815c0();
};

extern TESSaveLoadGame* g_TESSaveLoadGame;

struct Host37870
{
    bool ModifierList_WriteModifier(Modifier*);
};

extern int DAT_011e0750;

// @fnv 0x009378d0
void __fastcall CountModifiers(ActorValueModifierList* list)
{
    unsigned short icount = 0;
    unsigned short* pusCount = (unsigned short*)((const GameTimerRecord*)g_TESSaveLoadGame)->GetTime();
    g_TESSaveLoadGame->TESSaveLoadGame_SaveGameDataOLD(&icount, 2);

    BSSimpleList<Modifier*>* pmodlist = (BSSimpleList<Modifier*>*)list;
    while (pmodlist && *((BSSimpleList_helper*)pmodlist)->_ref_006815c0())
    {
        Modifier* pmod = *((BSSimpleList_helper*)pmodlist)->_ref_006815c0();
        if (((Host37870*)list)->ModifierList_WriteModifier(pmod))
            icount++;
        pmodlist = pmodlist->GetNext();
    }

    int ifastCount = list->m_ppModifiedActorValues ? DAT_011e0750 : 0;
    if (ifastCount)
    {
        for (int i = 0; i < ifastCount; i++)
        {
            ((Host37870*)list)->ModifierList_WriteModifier((Modifier*)list->m_ppModifiedActorValues->m_ppModifiers[i]);
            icount++;
        }
    }

    *pusCount = icount;
}
}  // namespace fnv_009378d0

namespace fnv_00938060 {
struct FUN_00938060_s
{
    void** m_pEntries;
    void FreeModifierEntry(int aiIndex);
};

extern "C" void __cdecl _Deallocate(void*);
extern "C" int gModifierListIndex[];

// @fnv 0x00938060
void FUN_00938060_s::FreeModifierEntry(int aiIndex)
{
    if (aiIndex >= 0 && aiIndex < 77 && m_pEntries)
    {
        if (gModifierListIndex[aiIndex] < 77 && m_pEntries[gModifierListIndex[aiIndex]])
        {
            void* pv = m_pEntries[gModifierListIndex[aiIndex]];
            _Deallocate(pv);
            m_pEntries[gModifierListIndex[aiIndex]] = 0;
        }
    }
}
}  // namespace fnv_00938060

extern unsigned int _data_011c16bc;
extern int DAT_011e0750;

struct FUN_00937e10
{
    Modifier** m_ppModifiers;

    FUN_00937e10(FUN_00937e10* other);
};

// Copy constructor: allocates an array of DAT_011e0750 Modifier pointers and deep-copies each non-null element from other, or stores null.
// @fnv 0x00937e10
FUN_00937e10::FUN_00937e10(FUN_00937e10* other)
{
    if (other->m_ppModifiers)
    {
        m_ppModifiers = DAT_011e0750 ? new Modifier*[DAT_011e0750] : 0;

        for (int i = 0; i < DAT_011e0750; ++i)
        {
            if (other->m_ppModifiers[i])
            {
                m_ppModifiers[i] = new Modifier(other->m_ppModifiers[i]);
            }
            else
            {
                m_ppModifiers[i] = 0;
            }
        }
    }
    else
    {
        m_ppModifiers = 0;
    }
}

extern int DAT_011e0750;

struct ModifierListCalc : public ActorValueModifierList
{
    int GetSlotCount();
    unsigned short ModifierList_GetSaveSize();
};

// Computes a total from key4 times GetSlotCount() plus 2, plus key4 times a mask derived from DAT_011e0750, and returns it.
// @fnv 0x00937ab0
// src: COMMUNITY 0x00937ab0
unsigned short ModifierListCalc::ModifierList_GetSaveSize()
{
    unsigned short total = 0;
    int mask;
    unsigned short key4 = 0;
    key4 = 5;
    if (key4 == 0)
    {
        return 0;
    }
    total += key4 * GetSlotCount() + 2;
    mask = ((m_ppModifiedActorValues != 0) ? -1 : 0) & DAT_011e0750;
    total += key4 * mask;
    return total;
}

namespace ActorValue {
ActorValueInfo* GetActorValueInfo(Index aeActorValueIndex);
}

// Removes a modifier from the list, or from m_ppModifiedActorValues when the actor value is flagged and tracked there.
// @fnv 0x00937400
void ActorValueModifierList::EraseModifier(Modifier* modifier)
{
    if (!modifier)
        return;
    ActorValueInfo* pkInfo = ActorValue::GetActorValueInfo((ActorValue::Index)modifier->GetKey());
    if (pkInfo && (pkInfo->uFlags & 1) && m_ppModifiedActorValues)
    {
        m_ppModifiedActorValues->RemoveModifier(modifier->GetKey());
        return;
    }
    Remove(modifier);
    delete modifier;
}
