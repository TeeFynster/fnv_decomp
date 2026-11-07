// The class header lives in include/; a plain "BGSEntryPointFunction.h" resolves to this folder's
// bgsentrypointfunction.h (case-insensitive lookup), which declares a different class.
#include "../../include/BGSEntryPointFunction.h"
// layout_support.h already supplies the list template used by the shared headers.
#define FNV64_BSSIMPLELIST_DEFINED
#include "../../include/TESForm.h"
#include "../../include/TESSound.h"
#include "../../include/Script.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESLevItem.h"
#include "../../include/BGSEntryPointFunctionData.h"
#include "../../include/BGSEntryPointFunctionDataLeveledList.h"
#include "../../include/BGSEntryPointFunctionDataOneValue.h"
#include "../../include/BGSEntryPointFunctionDataTwoValue.h"
#include "../../include/BGSEntryPointFunctionDataActivateChoice.h"

// Script.h supplies the layout; only these two operations are absent there.
class EntryPointScriptOperations : public Script
{
  public:
    void SaveHeader();
    bool IsDifferentFrom(EntryPointScriptOperations* other);
};

// @fnv 0x005e5b30
unsigned char BGSEntryPointFunction::GetArgumentCount(ENTRY_POINT_FUNCTION_TYPE type)
{
    return static_cast<unsigned char>(ms_auiArgumentCountsByType[type]);
}

// Looks up the handler for the given entry point function in the table and calls it with the reference, type, argument count, arguments and data.
// @fnv 0x005e5b40
void BGSEntryPointFunction::ApplyFunction(ENTRY_POINT_FUNCTION function, TESObjectREFR* reference,
                                          ENTRY_POINT_FUNCTION_TYPE type, unsigned char argumentCount, void** arguments,
                                          void* data)
{
    if (ms_kEntryPointFunctionTable[function].pFunction)
    {
        ms_kEntryPointFunctionTable[function].pFunction(reference, type, argumentCount, arguments, data);
    }
}

bool ValidateEntryFunctionArgs(int aiFunctionType, int aiDataType, int aiArg1, int aiArg2, unsigned char aucArgCount,
                               float** apapValues, BGSEntryPointFunctionDataTwoValue* apSource);

float RandomFloat(float afMin, float afMax);

// Validates arguments, then adds a random float between the source's two values to the first value in apapValues.
// @fnv 0x005e5d80
// src: COMMUNITY 0x005e5d80
void EntryPointFunction_AddRangeToValue(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                  BGSEntryPointFunctionDataTwoValue* apSource)
{
    if (!ValidateEntryFunctionArgs(0, 2, aiArg1, aiArg2, aucArgCount, apapValues, apSource))
        return;

    float* pfValue = *apapValues;
    BGSEntryPointFunctionDataTwoValue* pSource = apSource;

    *pfValue += RandomFloat(pSource->ReadValueA(), pSource->ReadValueB());
}

class E5DF0Counter
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual int GetCount(unsigned int uiIndex);
};

class E5DF0Actor
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    E5DF0Counter m_kCounter;
};

bool BGSEntryPointFunction_CheckFunctionArguments(int iUnused, int iType, E5DF0Actor* pkActor, void* pvTarget, bool bFlag, float** ppfResult,
                  BGSEntryPointFunctionDataTwoValue* pkModifier);

// Validates the modifier, then adds the counter value times ReadValueA to the result.
// @fnv 0x005e5df0
// src: COMMUNITY 0x005e5df0
void EntryPointFunction_AddActorValueMult(E5DF0Actor* pkActor, void* pvTarget, bool bFlag, float** ppfResult, BGSEntryPointFunctionDataTwoValue* pkModifier)
{
    if (!BGSEntryPointFunction_CheckFunctionArguments(0, 2, pkActor, pvTarget, bFlag, ppfResult, pkModifier))
        return;

    float* pfOut3 = *ppfResult;
    BGSEntryPointFunctionDataTwoValue* pkMod = pkModifier;
    E5DF0Actor* pkSource = pkActor;
    float fSecondFunctionValue = pkMod->ReadValueA();
    unsigned int uiIndex3 = (unsigned int)pkMod->ReadValueB();
    *pfOut3 += pkSource->m_kCounter.GetCount(uiIndex3) * fSecondFunctionValue;
}

unsigned int BSStringLength(const char* text);
extern "C" char* __cdecl fnv_strcpy(char* dst, const char* src);

// Replaces choiceText with an allocated copy of text, or zero when text is null.
// @fnv 0x005e6c60
// src: XBOX_PDB 0x005e6c60
void BGSEntryPointFunctionDataActivateChoice::SetLabel(const char* text)
{
    delete[] choiceText;
    choiceText = 0;

    if (text)
    {
        choiceText = new char[BSStringLength(text) + 1];
        fnv_strcpy(choiceText, text);
    }
}

bool __cdecl BGSEntryPointFunction_CheckFunctionArguments(int, int, void*, void*, unsigned char, void*, void*);
// Calls FUN_005e5b80 to validate arguments, then writes the result of a5->FUN_006b9130() into the float pointed to by *a4.
// @fnv 0x005e5c70
// src: COMMUNITY 0x005e5c70
void __cdecl EntryPointFunction_SetValue(void* apArg1, void* apArg2, unsigned char a3, float** ppValue,
                          BGSEntryPointFunctionDataOneValue* apSource)
{
    BGSEntryPointFunctionDataOneValue* pSource;
    if (!BGSEntryPointFunction_CheckFunctionArguments(0, 1, apArg1, apArg2, a3, ppValue, apSource))
        return;
    {
        float* pValue;
        pValue = *ppValue;
        pSource = apSource;
        *pValue = pSource->CombatTimer_GetTargetTime();
    }
}

namespace std {
float __cdecl abs(float);
}

// Validates entry function arguments, then sets the first value in apapValues to its absolute value.
// @fnv 0x005e5ea0
// src: COMMUNITY 0x005e5ea0
void __cdecl EntryPointFunction_AbsoluteValue(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                          BGSEntryPointFunctionDataTwoValue* apSource)
{
    float* pfValue;
    if (!ValidateEntryFunctionArgs(0, 0, aiArg1, aiArg2, aucArgCount, apapValues, apSource))
        return;
    pfValue = *apapValues;
    *pfValue = std::abs(*pfValue);
}

// @fnv 0x005e5ef0
// src: COMMUNITY 0x005e5ef0
void EntryPointFunction_NegativeAbsoluteValue(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                  BGSEntryPointFunctionDataTwoValue* apSource)
{
    if (!ValidateEntryFunctionArgs(0, 0, aiArg1, aiArg2, aucArgCount, apapValues, apSource))
        return;

    float* pfValue = *apapValues;
    *pfValue = -std::abs(*pfValue);
}

void __cdecl _Deallocate(void*);

// @fnv 0x005e6490
void BGSEntryPointFunctionDataTwoValue::FUN_005e6490()
{
    BGSEntryPointFunctionData::~BGSEntryPointFunctionData();
}

// @fnv 0x005e64e0
void* BGSEntryPointFunctionDataTwoValue::FUN_005e64e0(unsigned int flags)
{
    FUN_005e6490();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x005e65d0
void* BGSEntryPointFunctionDataActivateChoice::FUN_005e65d0(unsigned int flags)
{
    FUN_005e6600();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x005e64b0
BGSEntryPointFunctionDataTwoValue::BGSEntryPointFunctionDataTwoValue()
{
    EntryPointTwoValueFunctionData = 0.0f;
    fSecondFunctionValue = 0.0f;
}

// Allocates a one-value copy.
// @fnv 0x005e6670
// src: XBOX_PDB 0x005e6670
BGSEntryPointFunctionDataOneValue* BGSEntryPointFunctionDataOneValue::Duplicate_005e6670()
{
    BGSEntryPointFunctionDataOneValue* pduplicate = new BGSEntryPointFunctionDataOneValue;
    pduplicate->fValue = fValue;
    return pduplicate;
}

// Returns true if apCompare is not a BGSEntryPointFunctionDataOneValue or its fValue differs from this object's fValue.
// @fnv 0x005e6700
// src: XBOX_PDB 0x005e6700
bool BGSEntryPointFunctionDataOneValue::Compare_005e6700(BGSEntryPointFunctionData* apCompare)
{
    BGSEntryPointFunctionDataOneValue* poneValue;
    poneValue = dynamic_cast<BGSEntryPointFunctionDataOneValue*>(apCompare);
    if (!poneValue)
        return true;
    if (fValue != poneValue->fValue)
        return true;
    return false;
}

// Allocates a two-value copy.
// @fnv 0x005e67f0
// src: XBOX_PDB 0x005e67f0
BGSEntryPointFunctionDataTwoValue* BGSEntryPointFunctionDataTwoValue::Duplicate_005e67f0()
{
    BGSEntryPointFunctionDataTwoValue* pduplicate = new BGSEntryPointFunctionDataTwoValue;
    pduplicate->EntryPointTwoValueFunctionData = EntryPointTwoValueFunctionData;
    pduplicate->fSecondFunctionValue = fSecondFunctionValue;
    return pduplicate;
}

// Returns true if the dynamic_cast to BGSEntryPointFunctionDataTwoValue fails or if either float field differs from apCompare.
// @fnv 0x005e6890
// src: XBOX_PDB 0x005e6890
bool BGSEntryPointFunctionDataTwoValue::Compare_005e6890(BGSEntryPointFunctionData* apCompare)
{
    BGSEntryPointFunctionDataTwoValue* ptwoValue = dynamic_cast<BGSEntryPointFunctionDataTwoValue*>(apCompare);
    if (!ptwoValue)
        return true;
    if (EntryPointTwoValueFunctionData != ptwoValue->EntryPointTwoValueFunctionData)
        return true;
    if (fSecondFunctionValue != ptwoValue->fSecondFunctionValue)
        return true;
    return false;
}

// @fnv 0x005e69d0
// src: XBOX_PDB 0x005e69d0
BGSEntryPointFunctionDataLeveledList* BGSEntryPointFunctionDataLeveledList::Duplicate_005e69d0()
{
    BGSEntryPointFunctionDataLeveledList* pduplicate = new BGSEntryPointFunctionDataLeveledList;
    pduplicate->pLeveledList = pLeveledList;
    return pduplicate;
}

unsigned int __cdecl _FUN_00485910(unsigned int, unsigned int);

// @fnv 0x005e6ab0
// src: XBOX_PDB 0x005e6ab0
void BGSEntryPointFunctionDataLeveledList::Save_005e6ab0()
{
    BGSEntryPointFunctionData::Save();
    unsigned int ileveledListID = 0;
    if (pLeveledList != 0)
    {
        ileveledListID = pLeveledList->GetHavokWorldObjectCountInSceneGraph_0084e3a0();
        _FUN_00485910(0x44465045, ileveledListID);
    }
}

template <int Value> struct EndianSizeTag
{
};
void __cdecl BSEndian(int*, EndianSizeTag<4>);
struct TESFile_s
{
    unsigned int _ref_00401660();
    void _ref_00472890(void*, unsigned int);
    bool GetChunkData();
};

// Reads a leveled list ID, byte-swapping it when GetChunkData returns true.
// @fnv 0x005e6b00
// src: XBOX_PDB 0x005e6b00
bool BGSEntryPointFunctionDataLeveledList::Load_005e6b00(TESFile_s* apFile)
{
    unsigned int isize = apFile->_ref_00401660();
    if (isize != 4)
        return false;
    unsigned int ileveledListID = 0;
    apFile->_ref_00472890(&ileveledListID, 0);
    if (apFile->GetChunkData())
        BSEndian((int*)&ileveledListID, EndianSizeTag<4>());
    pLeveledList = reinterpret_cast<TESLevItem*>(ileveledListID);
    return true;
}

unsigned int __cdecl _strlen(const char*);
unsigned int __cdecl _BSStringLength(const char*);
void __cdecl TESForm_AddChunkArray(unsigned int, void*, unsigned int);
void __cdecl TESForm_AddChunk_00485950(unsigned int, unsigned int);

// @fnv 0x005e6e50
// src: XBOX_PDB 0x005e6e50
void BGSEntryPointFunctionDataActivateChoice::Save_005e6e50()
{
    BGSEntryPointFunctionData::Save();
    unsigned int z = 0;
    if (choiceText && _strlen(choiceText))
        TESForm_AddChunkArray(0x32465045, choiceText, _BSStringLength(choiceText) + 1);
    TESForm_AddChunk_00485950(0x33465045, flags);
    FUN_00413f40()->SaveHeader();
}

// Validates the arguments, then adds the return value of FUN_006b9130 to the first pointed-to float.
// @fnv 0x005e5cc0
// src: COMMUNITY 0x005e5cc0
void EntryPointFunction_AddValue(int aiArg1, int aiArg2, unsigned char aucArgCount, float** apapValues,
                  BGSEntryPointFunctionDataTwoValue* apSource)
{
    BGSEntryPointFunctionDataOneValue* pSource;
    if (!ValidateEntryFunctionArgs(0, 1, aiArg1, aiArg2, aucArgCount, apapValues, apSource))
        return;

    {
        float* pfValue;
        pfValue = *apapValues;
        pSource = reinterpret_cast<BGSEntryPointFunctionDataOneValue*>(apSource);
        *pfValue += pSource->CombatTimer_GetTargetTime();
    }
}

// @fnv 0x005e6470
BGSEntryPointFunctionData::~BGSEntryPointFunctionData()
{
}

void __cdecl TESForm_AddChunk_00485910(unsigned int chunkID, float value);

// @fnv 0x005e6760
// src: XBOX_PDB 0x005e6760
void BGSEntryPointFunctionDataOneValue::Save_005e6760()
{
    BGSEntryPointFunctionData::Save();
    TESForm_AddChunk_00485910(0x44465045, fValue);
}

class ActionPointCostSetting
{
  public:
    float* Setting_Float_00403e20();
};

extern ActionPointCostSetting* DAT_0119baf8[22];

// Returns the action point cost for the given action index, or 0.0f if the index is out of range.
// @fnv 0x0066dc70
// src: COMMUNITY 0x0066dc70
float ActionPoints_GetCost(int aiAction)
{
    float cost = 0.0f;
    if (aiAction >= 0 && aiAction < 22)
        cost = *DAT_0119baf8[aiAction]->Setting_Float_00403e20();
    return cost;
}

int Warning(const char*, ...);

// This call site consumes the full EAX result from virtual slot one. Calling the
// shared unsigned-char GetType declaration would insert extra zero extensions.
typedef unsigned int (__thiscall *EntryPointDataTypeCall)(BGSEntryPointFunctionData*);

// Checks the function type, argument count, non-null arguments, and, when present, data type; warns and returns false on mismatches.
// @fnv 0x005e5b80
// src: EXE 0x005e5b80
bool BGSEntryPointFunction_CheckFunctionArguments(int aeExpectedFunctionType, unsigned char acExpectedFunctionData, TESObjectREFR* apPerkOwner,
                  int aeFunctionType, unsigned char acArgumentCount, void** apFunctionArgument, void* apData)
{
    if (aeExpectedFunctionType != aeFunctionType)
    {
        Warning(
            "DEFAULT: Invalid function type %i passed to BGSEntryPointFunction::CheckFunctionArguments.  Expected %i.",
            aeFunctionType, aeExpectedFunctionType);
        return false;
    }
    if (::BGSEntryPointFunction::ms_auiArgumentCountsByType[aeExpectedFunctionType] != acArgumentCount)
    {
        Warning(
            "DEFAULT: Invalid argument count %i passed to BGSEntryPointFunction::CheckFunctionArguments.  Expected %i.",
            acArgumentCount, ::BGSEntryPointFunction::ms_auiArgumentCountsByType[aeExpectedFunctionType]);
        return false;
    }
    for (unsigned int i = 0; i < acArgumentCount; ++i)
    {
        if (!apFunctionArgument[i])
        {
            Warning(
                "DEFAULT: Invalid function argument %i passed to BGSEntryPointFunction::CheckFunctionArguments.  Function arguments cannot be zero.",
                i);
            return false;
        }
    }
    BGSEntryPointFunctionData* pfunctionData = (BGSEntryPointFunctionData*)apData;
    if (pfunctionData &&
        reinterpret_cast<EntryPointDataTypeCall*>(*reinterpret_cast<void***>(pfunctionData))[1](pfunctionData) !=
            acExpectedFunctionData)
    {
        Warning(
            "DEFAULT: Invalid function data type %i passed to BGSEntryPointFunction::CheckFunctionArguments.  Expected %i.",
            reinterpret_cast<EntryPointDataTypeCall*>(*reinterpret_cast<void***>(pfunctionData))[1](pfunctionData),
            acExpectedFunctionData);
        return false;
    }
    return true;
}

void __cdecl TESForm_AddChunk_3(unsigned int, unsigned char);

// @fnv 0x005e6250
void BGSEntryPointFunctionData::Save()
{
    unsigned char type = GetType();
    TESForm_AddChunk_3(0x54465045, type);
}

struct EntryPointFloatPair
{
    float EntryPointTwoValueFunctionData;
    float fSecondFunctionValue;
    void TwoValues_Endian();
};
bool TESForm_QEndianSwapOnSave();
void FUN_00485990(unsigned int, void*, int);

// Copies two float fields into a local pair, conditionally byte-swaps it, and passes its address and size to a helper.
// @fnv 0x005e6900
// src: XBOX_PDB 0x005e6900
void BGSEntryPointFunctionDataTwoValue::Save_005e6900()
{
    BGSEntryPointFunctionData::Save();
    EntryPointFloatPair data;
    data.EntryPointTwoValueFunctionData = EntryPointTwoValueFunctionData;
    data.fSecondFunctionValue = fSecondFunctionValue;
    if (TESForm_QEndianSwapOnSave())
        data.TwoValues_Endian();
    FUN_00485990(0x44465045, &data, 8);
    if (TESForm_QEndianSwapOnSave())
        data.TwoValues_Endian();
}

// Returns true if the cast to BGSEntryPointFunctionDataLeveledList fails or if pLeveledList differs from the other entry's pLeveledList, otherwise false.
// @fnv 0x005e6a60
// src: XBOX_PDB 0x005e6a60
bool BGSEntryPointFunctionDataLeveledList::Compare_005e6a60(BGSEntryPointFunctionData* apCompare)
{
    BGSEntryPointFunctionDataLeveledList* pleveledList = dynamic_cast<BGSEntryPointFunctionDataLeveledList*>(apCompare);
    if (!pleveledList)
        return true;
    if (pLeveledList != pleveledList->pLeveledList)
        return true;
    return false;
}

struct SeqObj
{
    Script& GetName();
};

struct G2
{
    void AddHead(int*);
};

struct FUN_005e61b0_Local
{
    G2* pList;
    void* pLocals;
};

bool __cdecl BGSEntryPointFunction_CheckFunctionArguments(int, int, void*, void*, bool, void*, void*);

// Runs the challenge name object's script when it starts locked; otherwise adds the challenge pointer to pList.
// @fnv 0x005e61b0
// src: COMMUNITY 0x005e61b0
void __cdecl EntryPointFunction_AddActivateChoice(void* arg1, void* arg2, bool arg3, FUN_005e61b0_Local* apLocal, TESChallenge* apChallenge)
{
    if (!BGSEntryPointFunction_CheckFunctionArguments(2, 4, arg1, arg2, arg3, apLocal, apChallenge))
        return;

    G2* pChallenge = apLocal->pList;
    void* pLocals = apLocal->pLocals;
    TESChallenge* pList = apChallenge;

    if (pChallenge && pList)
    {
        if (static_cast<unsigned char>(pList->GetStartsLocked()))
        {
            Script* pName = &reinterpret_cast<SeqObj*>(pList)->GetName();
            if (pName)
                pName->Script::Run(pLocals, 0, 0, 0);
        }
        else
        {
            pChallenge->AddHead((int*)&pList);
        }
    }
}

// Reads fValue and converts its endianness; rejects chunks whose size is not four.
// @fnv 0x005e6790
// src: XBOX_PDB 0x005e6790
bool BGSEntryPointFunctionDataOneValue::Load_005e6790(TESFile* apFile)
{
    unsigned int isize = reinterpret_cast<TESFile_s*>(apFile)->_ref_00401660();
    if (isize != 4)
        return false;
    reinterpret_cast<TESFile_s*>(apFile)->_ref_00472890(&fValue, 0);
    if (reinterpret_cast<TESFile_s*>(apFile)->GetChunkData())
        BSEndian((int*)&fValue, EndianSizeTag<4>());
    return true;
}

// Copies the activation choice label, script, and flags.
// @fnv 0x005e6cd0
// src: XBOX_PDB 0x005e6cd0
BGSEntryPointFunctionData* BGSEntryPointFunctionDataActivateChoice::Duplicate_005e6cd0()
{
    BGSEntryPointFunctionDataActivateChoice* pduplicate = new BGSEntryPointFunctionDataActivateChoice();

    pduplicate->SetLabel(this->choiceText);
    pduplicate->GetName().CopyScriptContents(&this->GetName());
    pduplicate->flags = this->flags;

    return pduplicate;
}

int __cdecl BSstrcmp(const char* lhs, const char* rhs);

// Returns true if the cast fails, a label comparison is nonzero, the form comparison returns true, or flags differ.
// @fnv 0x005e6d80
// src: XBOX_PDB 0x005e6d80
bool BGSEntryPointFunctionDataActivateChoice::Compare_005e6d80(BGSEntryPointFunctionData* other)
{
    BGSEntryPointFunctionDataActivateChoice* pOtherChoice =
        dynamic_cast<BGSEntryPointFunctionDataActivateChoice*>(other);
    if (pOtherChoice == 0)
        return true;
    if ((choiceText != 0 &&
         pOtherChoice->choiceText == 0) ||
        (choiceText == 0 &&
         pOtherChoice->choiceText != 0))
        return true;
    if (choiceText != 0 &&
        pOtherChoice->choiceText != 0 &&
        BSstrcmp(choiceText,
                     pOtherChoice->choiceText))
        return true;
    if (FUN_00413f40()->IsDifferentFrom(pOtherChoice->FUN_00413f40()))
        return true;
    if (flags != pOtherChoice->flags)
        return true;
    return false;
}

class ActivationChoiceFormView
{
  public:
    virtual void Unknown000();
    virtual void Unknown004();
    virtual void Unknown008();
    virtual void Unknown00C();
    virtual void Unknown010();
    virtual void Unknown014();
    virtual void Unknown018();
    virtual void Unknown01C();
    virtual void Unknown020();
    virtual void Unknown024();
    virtual void Unknown028();
    virtual void Unknown02C();
    virtual void Unknown030();
    virtual void Unknown034();
    virtual void Unknown038();
    virtual void Unknown03C();
    virtual void Unknown040();
    virtual void Unknown044();
    virtual void Unknown048();
    virtual void Unknown04C();
    virtual void Unknown050();
    virtual void Unknown054();
    virtual void Unknown058();
    virtual void Unknown05C();
    virtual void Unknown060();
    virtual void Unknown064();
    virtual void Unknown068();
    virtual void Unknown06C();
    virtual void Unknown070();
    virtual void Unknown074();
    virtual void Unknown078();
    virtual void Unknown07C();
    virtual void Unknown080();
    virtual void Unknown084();
    virtual void Unknown088();
    virtual void Unknown08C();
    virtual void Unknown090();
    virtual void Unknown094();
    virtual void Unknown098();
    virtual void Unknown09C();
    virtual void Unknown0A0();
    virtual void Unknown0A4();
    virtual void Unknown0A8();
    virtual void Unknown0AC();
    virtual void Unknown0B0();
    virtual void Unknown0B4();
    virtual void Unknown0B8();
    virtual void Unknown0BC();
    virtual void Unknown0C0();
    virtual void Unknown0C4();
    virtual void Unknown0C8();
    virtual void Unknown0CC();
    virtual void Unknown0D0();
    virtual void Unknown0D4();
    virtual void Unknown0D8();
    virtual void Unknown0DC();
    virtual void Unknown0E0();
    virtual void Unknown0E4();
    virtual void Unknown0E8();
    virtual void Unknown0EC();
    virtual void Unknown0F0();
    virtual void Unknown0F4();
    virtual void Unknown0F8();
    virtual void Unknown0FC();
    virtual void Unknown100();
    virtual void Unknown104();
    virtual void Unknown108();
    virtual void Unknown10C();
    virtual void Unknown110();
    virtual void Unknown114();
    virtual void Unknown118();
    virtual void Unknown11C();
    virtual void Unknown120();
    virtual void Unknown124();
    virtual void Unknown128();
    virtual void Unknown12C();
    virtual const char* GetName();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

extern char str_010463f0[];

int __cdecl MessageHandler_QWarningCount();
void __cdecl MessageHandler_IncDisableWarningCount(bool disabled);
void __cdecl MessageHandler_SetWarningCount(int count);
void __cdecl Warning_005b5e40(const char* message, const char* name, unsigned int formID);

// Calls resultScript with form, then logs a message when the subsequent count returned by FUN_0046e8a0 is nonzero.
// @fnv 0x005e7230
void BGSEntryPointFunctionDataActivateChoice::InitItem(TESForm* form)
{
    int savedWarnings = MessageHandler_QWarningCount();
    MessageHandler_IncDisableWarningCount(true);
    MessageHandler_SetWarningCount(0);
    resultScript.InitItem(form);
    MessageHandler_IncDisableWarningCount(false);

    int newWarnings = MessageHandler_QWarningCount();
    MessageHandler_SetWarningCount(savedWarnings);

    if (newWarnings != 0)
        Warning_005b5e40(str_010463f0, reinterpret_cast<ActivationChoiceFormView*>(form)->GetName(),
                     reinterpret_cast<ActivationChoiceFormView*>(form)->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
}

namespace fnv_005e6970 {
struct TESFile_s
{
    unsigned int _ref_00401660();
    void _ref_00472890(void*, unsigned int);
    bool _ref_00401680();
};

struct EntryPointTwoValueChunk_5e6970
{
    float valueA;
    float valueB;
    void TwoValues_Endian();
};

} // namespace fnv_005e6970

// Reads the two floats, converting their endianness when required.
// @fnv 0x005e6970
// src: XBOX_PDB 0x005e6970
bool BGSEntryPointFunctionDataTwoValue::Load_005e6970(TESFile* apFile)
{
    fnv_005e6970::EntryPointTwoValueChunk_5e6970 data;
    unsigned int size = reinterpret_cast<fnv_005e6970::TESFile_s*>(apFile)->_ref_00401660();
    if (size != 8)
        return false;
    reinterpret_cast<fnv_005e6970::TESFile_s*>(apFile)->_ref_00472890(&data, size);
    if (reinterpret_cast<fnv_005e6970::TESFile_s*>(apFile)->_ref_00401680())
        data.TwoValues_Endian();
    EntryPointTwoValueFunctionData = data.valueA;
    fSecondFunctionValue = data.valueB;
    return true;
}

void FUN_00485d50(unsigned int&, TESFile*);
TESForm* TESForm_GetFormByNumericID(unsigned int);

class EntryPointOwnerView : public TESForm
{
  public:
    int GetFormEditorIDLength();
};
int Warning(const char*, ...);

// Resolves pLeveledList's numeric value to a TESLevItem and warns if the resolved form is not one.
// @fnv 0x005e6b70
// src: XBOX_PDB 0x005e6b70
void BGSEntryPointFunctionDataLeveledList::InitItem_005e6b70(TESForm* apOwner)
{
    if (pLeveledList)
    {
        unsigned int itempint = (unsigned int)pLeveledList;
        FUN_00485d50(itempint, apOwner->FUN_00484e60(-1));
        pLeveledList = dynamic_cast<TESLevItem*>(TESForm_GetFormByNumericID(itempint));
        if (!pLeveledList)
        {
            if (static_cast<EntryPointOwnerView*>(apOwner)->GetFormEditorIDLength())
                Warning("MASTERFILE: Unable to find leveled list (%08X) on owner object \"%s\".", itempint,
                        apOwner->GetName());
            else
                Warning("MASTERFILE: Unable to find leveled list (%08X) on owner object (%08X).", itempint,
                        apOwner->GetHavokWorldObjectCountInSceneGraph_0084e3a0());
        }
    }
}

// Initializes the label, script, and flags, then initializes the choice data.
// @fnv 0x005e6540
BGSEntryPointFunctionDataActivateChoice::BGSEntryPointFunctionDataActivateChoice()
    : BGSEntryPointFunctionData(), choiceText(0), resultScript(), flags(0)
{
    FUN_005e6c30();
}
