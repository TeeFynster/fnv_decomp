// fallout_shared/magic/effectitem.cpp: EffectItem, EffectItemList, ScriptEffect, Setting and more (52 functions)

#include "../../../include/BSStringT.h"

#include "../../../include/AutoMemContext.h"
#include "../../../include/Setting.h"
#include "../../../include/SettingCollectionMap.h"
#include "../../../include/TESChallenge.h"
#include "../../../include/TESGrass.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/CachedValuesOwner.h"
#include "../../../include/TESChildCell.h"
#include "../../../include/ActiveEffect.h"
#include "../../../include/BGSImpactData__IMPACT_DATA_DATA.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/PerkEntryConditionSet.h"
#include "../../../include/ScriptEffect.h"
#include "../../../include/TESFile.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/EffectItemList.h"
#include "../../../include/EffectItem.h"
// MagicEffectSystem_effectitem: local type (was include/MagicEffectSystem.h, which had no evidence of one real class); its methods are 0x00403ab0 EffectArchetypes::Activate, 0x00403c80 EffectArchetypes::CheckFlag, 0x00810fd0 EffectSetting::GetEffectArchetype
class ActiveEffect;
class MagicCaster;
class MagicItem;
class TESBoundObject;

class MagicEffectSystem_effectitem
{
public:
    struct _Type
    {
        enum Type
        {
            VALUE_MODIFIER,
            SCRIPT,
            DISPEL,
            CURE_DISEASE,
            ABSORB,
            SHIELD,
            CALM,
            DEMORALIZE,
            FRENZY,
            COMMAND_CREATURE,
            COMMAND_HUMANOID,
            INVISIBILITY,
            CHAMELEON,
            LIGHT,
            DARKNESS,
            NIGHT_EYE,
            LOCK,
            OPEN,
            BOUND_ITEM,
            SUMMON_CREATURE,
            DETECT_LIFE,
            TELEKINESIS,
            DISINTEGRATE_ARMOR,
            DISINTEGRATE_WEAPON,
            PARALYSIS,
            REANIMATE,
            SOUL_TRAP,
            TURN_UNDEAD,
            SUN_DAMAGE,
            VAMPIRISM,
            CURE_PARALYSIS,
            CURE_ADDICTION,
            CURE_POISON,
            CONCUSSION,
            VALUE_AND_PARTS,
            LIMB_CONDITION,
            TURBO,
            COUNT,
        };
    };

    typedef _Type::Type Type;

    static bool __cdecl IsFlagSet(Type type, unsigned int flags);
    static bool __cdecl IsFlagSet(int type, unsigned int flags);
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
// TESConditionSave_effectitem: local type (was include/TESConditionSave.h, which had no evidence of one real class); its methods are 0x00680910 TESCondition::Save
class TESConditionSave_effectitem
{
public:
    void ProcessItems();
};

// Unit-specific declarations; TESForm is supplied by the shared headers.

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
int __cdecl Warning(const char* format, ...);

// The game uses the cdecl deallocation wrapper, rather than the manager member.
void __cdecl _Deallocate(void* pointer);

EffectSetting* __cdecl GetUsageMonitorEffectSetting();

// @fnv 0x00404650
int EffectItem::GetEffectID()
{
    return m_pEffectSetting->GetEffectID();
}

// @fnv 0x00405e40
bool EffectItem::IsDetrimental()
{
    return m_pEffectSetting->IsDetrimental();
}

// @fnv 0x00404710
bool EffectItem::IsHostile()
{
    return GetEffectSetting()->IsFlagSet(1);
}

// Returns whether GetEffectSetting() equals GetUsageMonitorEffectSetting().
// @fnv 0x00404730
bool EffectItem::IsScriptBasedEffect()
{
    return GetEffectSetting() == GetUsageMonitorEffectSetting();
}

// Returns the effect name by delegating to the effect's GetEffectName method.
// @fnv 0x00404670
BSStringT<char> EffectItem::GetEffectName()
{
    return m_pEffectSetting->GetEffectName();
}

// Destroys the effect item's contents and, if flags has bit 0 set, deallocates the object; returns this.
// @fnv 0x004059d0
EffectItem* EffectItem::Delete(unsigned int flags)
{
    DestroyContents();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x00405d20
void EffectItemList::AddItem(EffectItem* item)
{
    if (item->IsScriptBasedEffect() && GetScriptEffect())
        return;

    AddTail(item);
    if (item->IsHostile())
        ++m_iEffectCount;
}

// Constructs a ScriptEffect, storing its script and initializing the script locals to null.
// @fnv 0x00827740
ScriptEffect::ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{
    pScript = static_cast<Script*>(effect->GetScript());
    m_pScriptLocals = 0;
}

// Loads an EffectItem from a TESFile chunk: reads the 20-byte effect data (with endian conversion) or loads its conditions, returning false on unknown chunk IDs.
// @fnv 0x00404120
bool EffectItem::Load(TESFile* file, const char* actorEffect)
{
    switch (file->GetChunkID())
    {
    case 0x54494645:
        memset(this, 0, 20);
        file->GetChunkData(this, 20);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(this)->Endian();
        if (!m_pEffectSetting)
            Warning("GAME EFFECTS: Unknown EffectSetting encountered when loading EffectItem in actor effect '%s'",
                    actorEffect == 0 ? "{unknown}" : actorEffect);
        else if (m_pEffectSetting->IsAssociatedActorValueUsed() && m_pEffectSetting->HasAssociatedActorValue())
            data.m_eAssociatedActorValue = m_pEffectSetting->GetAssociatedActorValue();
        break;
    case 0x41445443:
        GetConditions()->Load(file);
        break;
    default:
        return false;
    }
    return true;
}

// Initializes the effect data with zero values and no associated actor value.
// @fnv 0x00403ba0
MagicEffectEntry::MagicEffectEntry()
{
    m_iMagnitude = 0;
    m_iArea = 0;
    m_iPayloadInteger = 0;
    m_eRange = 0;
    m_eAssociatedActorValue = -1;
}

// @fnv 0x00403c60
bool EffectSetting::HasFlag2()
{
    return MagicEffectSystem_effectitem::IsFlagSet(GetArchetype(), 2);
}

struct EffectArchetypeEntry
{
    unsigned int uiFlags;
    unsigned int pad[3];
};

extern EffectArchetypeEntry DAT_01183328[];

// @fnv 0x00403c80
bool __cdecl HasEffectArchetypeFlag(int aiIndex, unsigned int aiFlag)
{
    return (DAT_01183328[aiIndex].uiFlags & aiFlag) != 0;
}

void* __cdecl _fnv_zlib_memset(void* apDest, int aiValue, unsigned int aCount);

// @fnv 0x00403d30
// src: COMMUNITY 0x00403d30
void __cdecl ourMemset(void* apDest, int aiValue, unsigned int aCount)
{
    _fnv_zlib_memset(apDest, aiValue, aCount);
}

// If apForm is not initialized, initializes the item's conditions with apForm.
// @fnv 0x00403db0
void EffectItem::InitItem(TESForm* apForm)
{
    if (apForm->GetInitialized())
        return;
    if (GetConditions())
        GetConditions()->InitItem(apForm);
}

// @fnv 0x00403e60
// src: XBOX_PDB 0x00403e60
bool EffectSetting::IsFlagSet_00403e60(unsigned int auiFlag)
{
    return GetFlag(auiFlag);
}

// @fnv 0x00403e80
bool EffectSetting::HasAssociatedActorValue()
{
    return GetAssociatedActorValue() != -1;
}

// @fnv 0x00403ee0
// src: XBOX_PDB 0x00403ee0
bool EffectItem::IsActorValueUsed()
{
    return m_pEffectSetting->IsAssociatedActorValueUsed();
}

float __cdecl CalcEffectCost(float, int, int, int, bool);

// @fnv 0x00403f00
float EffectItem::GetRawCost()
{
    if (m_fCost < 0.0)
    {
        m_fCost = CalcEffectCost(((TESGrass*)GetEffectSetting())->TESGrass::GetLowestAllowedSlope(), GetArea(), GetDuration(),
                                 GetMagnitude(), GetRange() == 2);
    }
    return m_fCost;
}

struct Actor;
struct AlchemyItem;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiNode;
struct SpellItem;
struct TESBoundObject;
struct TESObjectCELL;
struct TESObjectREFR;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
float __cdecl ScaleBySettingBlend(float, int, int);
float __cdecl FloatFloor(float);
float __cdecl BSMAX_00404010(float, float);

// @fnv 0x00403f80
float EffectItem::GetCost(Actor* apActor)
{
    float fcost = GetRawCost();
    if (apActor != 0)
    {
        fcost = ScaleBySettingBlend(fcost,
                                    ((ActorValueOwner*)((char*)apActor + 0xa4))->GetActorValueAsInteger(GetEffectID()),
                                    ((ActorValueOwner*)((char*)apActor + 0xa4))->GetActorValueAsInteger(0xb));
    }
    fcost = FloatFloor(fcost);
    return BSMAX_00404010(fcost, 1.0f);
}

// Returns the larger of the two float arguments.
// @fnv 0x00404010
// src: XBOX_PDB 0x00404010
float __cdecl BSMAX_00404010(float fA, float fB)
{
    return (fA > fB) ? fA : fB;
}

float __cdecl TruncateToInt(float);
extern const double _gModifierZero;

// @fnv 0x00404040
// src: XBOX_PDB 0x00404040
float __cdecl FloatFloor(float aIn)
{
    float droundToZero = TruncateToInt(aIn);
    return (aIn - droundToZero >= _gModifierZero) ? droundToZero : (droundToZero - 1.0);
}

// @fnv 0x004042a0
bool EffectItem::Compare(EffectItem* apCompare)
{
    bool bDifferent = apCompare->GetEffectSetting() != GetEffectSetting() ||
                      apCompare->GetMagnitude() != GetMagnitude() || apCompare->GetArea() != GetArea() ||
                      apCompare->GetDuration() != GetDuration() || apCompare->GetRange() != GetRange() ||
                      apCompare->GetAffectedActorValue() != GetAffectedActorValue();

    if (GetConditions())
    {
        if (GetConditions()->Compare(apCompare->GetConditions()))
            return true;
    }
    else if (apCompare->GetConditions())
    {
        return true;
    }

    return bDifferent;
}

// Returns 0 if the EffectSetting at offset 0x14 has flag 0x100 set, otherwise returns the int at offset 0 of this EffectItem.
// @fnv 0x00404390
int EffectItem::GetMagnitude()
{
    return m_pEffectSetting->IsFlagSet(0x100) ? 0 : data.m_iMagnitude;
}

// @fnv 0x00404420
int EffectItem::GetArea()
{
    return (!m_pEffectSetting->IsFlagSet(0x200) && GetRange() != 0) ? data.m_iArea : 0;
}

// Returns 0 if the EffectSetting at offset 0x14 has flag 0x80 set, otherwise returns the int at offset 0x8.
// @fnv 0x004044d0
int EffectItem::GetDuration()
{
    return m_pEffectSetting->IsFlagSet(0x80) ? 0 : data.m_iPayloadInteger;
}

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
class ExtraDataList;
class ScriptHeaderData;
class ScriptReferencedObject;
class Script;
class ScriptCompiler;
class ScriptLocals;
class TESObject;
class TESObjectREFR;
class TESQuest;
namespace fnv_004045e0 {
struct CStringArgument;
int __fastcall _FNV_GetFormType(int);
}  // namespace fnv_004045e0

// @fnv 0x004045e0
void* EffectItem::GetScript()
{
    Script* pscript = 0;
    EffectSetting* psetting = GetEffectSetting();
    if (MagicEffectSystem_effectitem::IsFlagSet((MagicEffectSystem_effectitem::_Type::Type)psetting->GetArchetype(), 0x40))
    {
        if (((TESChallenge*)psetting)->GetInterval())
        {
            if (fnv_004045e0::_FNV_GetFormType(((TESChallenge*)psetting)->GetInterval()) == 0x11)
            {
                pscript = (Script*)((TESChallenge*)GetEffectSetting())->GetInterval();
            }
        }
    }
    return pscript;
}

char* __cdecl _strcpy(char*, const char*);

// @fnv 0x004046f0
// src: XBOX_PDB 0x004046f0
void __cdecl ourStrcpy(char* apStrDest, const char* apStrSource)
{
    _strcpy(apStrDest, apStrSource);
}

// Calls Enter with the given arguments and returns this.
// @fnv 0x00404eb0
AutoMemContext::AutoMemContext(int m, bool o, const char* f, int l)
{
    Enter(m, o, const_cast<char*>(f), l);
}

int __cdecl GetTlsField();
void __cdecl SetMemContext_00404f30(int);

// @fnv 0x00404f00
void AutoMemContext::Enter(int memContext, bool overridable, char* apFile, int aiLine)
{
    m_eMemoryContext = static_cast<MEM_CONTEXT>(GetTlsField());
    SetMemContext_00404f30(memContext);
}

// @fnv 0x00404f70
void AutoMemContext::Leave()
{
    SetMemContext_00404f30(m_eMemoryContext);
}

unsigned int __cdecl _strlen(const char*);

// @fnv 0x0044a670
// src: XBOX_PDB 0x0044a670
unsigned int __cdecl BSstrlen(const char* apString)
{
    return _strlen(apString);
}

// The shared header has no associated-form getter; keep its register ABI here.
// @fnv 0x005f5f80
TESForm* __fastcall GetEffectAssociatedForm(EffectSetting* effect)
{
    return effect->data.m_pAssociatedForm;
}

// Returns the larger of the two integer arguments.
// @fnv 0x00647b70
// src: XBOX_PDB 0x00647b70
int __cdecl BSMAX_00647b70(int iA, int iB)
{
    return iA > iB ? iA : iB;
}

extern "C" int __tls_index;

__declspec(thread) int DAT_tls_field = 0x3b;

// @fnv 0x00404f50
int __cdecl GetTlsField()
{
    return DAT_tls_field;
}

// The shared header has no caster getter; keep its register ABI here.
// @fnv 0x0045cd60
MagicCaster* __fastcall GetActiveEffectCaster(ActiveEffect* effect)
{
    return effect->m_pEffectInstance;
}

extern "C" bool __cdecl TESForm_QEndianSwapOnSave();
extern "C" void __cdecl AppendChunk(unsigned int, void*, unsigned int);

// @fnv 0x004040b0
void EffectItem::Save()
{
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(this)->Endian();
    AppendChunk(0x54494645, this, 0x14);
    if (TESForm_QEndianSwapOnSave())
        reinterpret_cast<BGSImpactData__IMPACT_DATA_DATA*>(this)->Endian();
    if (GetConditions())
        reinterpret_cast<TESConditionSave_effectitem*>(GetConditions())->ProcessItems();
}

// @fnv 0x00404470
// src: COMMUNITY 0x00404470
bool EffectItem::SetArea_00404470(int range)
{
    bool result = false;
    if (!m_pEffectSetting->IsFlagSet(0x200))
    {
        if (GetRange() != 0 && range >= 0)
        {
            data.m_iArea = range;
            m_fCost = -1.0f;
            result = true;
        }
    }
    return result;
}

namespace fnv_00404f30 {
extern "C" unsigned int __tls_index;

__declspec(thread) int tlsVar[0x2b4 / 4 + 1];

// @fnv 0x00404f30
// src: XBOX_PDB 0x00404f30
void __cdecl SetMemContext_00404f30(int aiValue)
{
    tlsVar[0x2b4 / 4] = aiValue;
}
}  // namespace fnv_00404f30

// @fnv 0x00403d50
EffectItem::~EffectItem()
{
    GetConditions()->InitializeConditionItems();
}

// @fnv 0x004043d0
// src: COMMUNITY 0x004043d0
bool EffectItem::SetMagnitude_004043d0(int a)
{
    bool result = false;
    if (!m_pEffectSetting->IsFlagSet(0x100))
    {
        if (a >= 0)
        {
            data.m_iMagnitude = a;
            m_fCost = -1.0f;
            result = true;
        }
    }
    return result;
}

// Sets a non-negative duration and invalidates the cached cost when the effect permits a duration.
// @fnv 0x00404510
// src: COMMUNITY 0x00404510
bool EffectItem::SetDuration_00404510(int aiValue)
{
    bool b = false;
    if (!m_pEffectSetting->IsFlagSet(0x80) && aiValue >= 0)
    {
        data.m_iPayloadInteger = aiValue;
        m_fCost = -1.0f;
        b = true;
    }
    return b;
}

// @fnv 0x004049a0
void* Setting::FUN_004049a0(unsigned int flags)
{
    FUN_00404950();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Dummy
{
    void FUN_00404c00();
    void* FUN_00404ca0(unsigned int);
};
// Calls FUN_00404c00, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00404ca0
void* Dummy::FUN_00404ca0(unsigned int flags)
{
    FUN_00404c00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// Exe 0x00404f90: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct EffectitemOffset08View
{
    unsigned int GetFlags();
};

struct MapH
{
    bool RemoveAt(unsigned int);
};

struct FUN_00404f90_shell
{
    unsigned char _pad[0x10c];
    MapH _map;
    void RemoveSettingFromMap(EffectitemOffset08View* apSetting);
};

// If apSetting is non-null and has flags set, removes the entry keyed by those flags from _map.
// @fnv 0x00404f90
void FUN_00404f90_shell::RemoveSettingFromMap(EffectitemOffset08View* apSetting)
{
    if (apSetting && apSetting->GetFlags())
    {
        _map.RemoveAt(apSetting->GetFlags());
    }
}

namespace fnv_00404fd0 {

struct MapX
{
    void* GetFirstPos();
};

// Unit-local view of NiTMap for 0x00404fd0 (namespace fnv_00404fd0): built on the shared NiTMap, that code does not compile or does not match.
struct NiTMap_00404fd0
{
    void GetNext(void*&, unsigned int&, void*&);
};

int _data_011c16bc;
}  // namespace fnv_00404fd0

// Iterates the map at offset 0x10c, calls FUN_00c33280 on each non-null Setting with apStringsA, and returns the count processed.
// @fnv 0x00404fd0
// src: XBOX_PDB 0x00404fd0
template <> unsigned int SettingCollectionMap<Setting>::GetViewerStrings_00404fd0(NiTPrimitiveArray<char*>* apStringsA)
{
    unsigned int I;
    unsigned int cpkey;
    void* IT;
    AutoMemHelper tempMemContext(9, true, "..\\BSMain\\Setting.h", 0x239);
    Setting* pval;

    I = 0;
    IT = reinterpret_cast<fnv_00404fd0::MapX*>(reinterpret_cast<char*>(this) + 0x10c)->GetFirstPos();
    while (IT != 0)
    {
        reinterpret_cast<fnv_00404fd0::NiTMap_00404fd0*>(reinterpret_cast<char*>(this) + 0x10c)
            ->GetNext(IT, cpkey, reinterpret_cast<void*&>(pval));

        if (pval != 0)
        {
            pval->Setting_GetViewerStrings(apStringsA);
            ++I;
        }
    }

    return I;
}

// Initializes the effect data and conditions, then calls Init with the given value.
// @fnv 0x00403b30
EffectItem::EffectItem(int aiValue) : data(), Conditions()
{
    Init(aiValue);
}

extern float DAT_01012054;

// Stores the effect setting, resets the fields, and selects its associated actor value or -1.
// @fnv 0x00403be0
// src: COMMUNITY 0x00403be0
void EffectItem::Initialize_00403be0(EffectSetting* manager)
{
    m_pEffectSetting = manager;
    data.m_iArea = 0;
    data.m_iPayloadInteger = 0;
    data.m_iMagnitude = 0;
    data.m_eAssociatedActorValue = m_pEffectSetting->HasFlag2() ? m_pEffectSetting->GetAssociatedActorValue() : -1;
    m_fCost = DAT_01012054;
}

// @fnv 0x00404090
float TruncateToInt(float fValue)
{
    return (float)(int)fValue;
}

struct MapAccess
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void** position, int* key, void** value);
};
struct EffectProcess
{
    virtual void unknown00() = 0;
    virtual void unknown04() = 0;
    virtual void unknown08() = 0;
    virtual void unknown0c() = 0;
    virtual bool ProcessEffect(void* effect) = 0;
    bool FUN_00404d30();
    bool ProcessAllEffects();
};
// If FUN_00404d30 succeeds, iterates the map at this+0x10c and ANDs ProcessEffect over each non-null effect; returns the result.
// @fnv 0x004050a0
bool EffectProcess::ProcessAllEffects()
{
    bool result = FUN_00404d30();
    if (result)
    {
        int key;
        {
            void* position = ((MapAccess*)((char*)this + 0x10c))->FUN_004b9ba0();
            while (position != 0)
            {
                void* effect;
                ((MapAccess*)((char*)this + 0x10c))->FUN_006b7f20(&position, &key, &effect);
                if (effect != 0)
                    result &= ProcessEffect(effect);
            }
        }
    }
    return result;
}

namespace fnv_00404560 {
extern const float DAT_01012054;
}  // namespace fnv_00404560

// @fnv 0x00404560
// src: COMMUNITY 0x00404560
bool __thiscall EffectItem::SetRange_00404560(unsigned int value)
{
    bool result = false;

    if ((value == 1 && m_pEffectSetting->IsFlagSet_00403e60(0x20)) || (value == 2 && m_pEffectSetting->IsFlagSet_00403e60(0x40)) ||
        (value == 0 && m_pEffectSetting->IsFlagSet_00403e60(0x10)))
    {
        data.m_eRange = value;
        m_fCost = fnv_00404560::DAT_01012054;
        result = true;
    }

    return result;
}

extern char str_01012220[];
struct SettingMap
{
    int FUN_004b9ba0();
    void FUN_006b7f20(int*, int*, int*);
};
struct SettingRegistry
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual bool HandleSetting(int);
    bool SettingCollectionMap_Setting_ReadSettings();
};
extern "C" bool __fastcall FUN_00404d30(SettingRegistry*);
// @fnv 0x00405120
// src: XBOX_PDB 0x00405120
bool SettingRegistry::SettingCollectionMap_Setting_ReadSettings()
{
    int key;
    AutoMemContext memoryGuard(9, true, str_01012220, 0x278);
    bool isValid = FUN_00404d30(this);
    if (isValid)
    {
        int iterator = reinterpret_cast<SettingMap*>(reinterpret_cast<char*>(this) + 0x10c)->FUN_004b9ba0();
        while (iterator != 0)
        {
            int value;
            reinterpret_cast<SettingMap*>(reinterpret_cast<char*>(this) + 0x10c)->FUN_006b7f20(&iterator, &key, &value);
            if (value != 0)
                isValid = isValid & HandleSetting(value);
        }
    }
    return isValid;
}

char* __cdecl FormHeap_Allocate(unsigned int aSize);
const char* __cdecl ConvertFromUni(const char* apString, int aFlag);

struct FUN_004d61b0_sub
{
    FUN_004d61b0_sub(int aValue);
    ~FUN_004d61b0_sub();
};

class FUN_004d61b0
{
  public:
    int m00;
    int m04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_004d61b0_sub m18;
    int unk1C;
    int unk20;
    int unk24;
    int m28;
    char* m2c;

    void CreateTreeWindows(int a5, int a6, int a7, int a8);
    void NiTreeCtrl_SetImageList();
    void NiTreeCtrl_CreateTree(int aValue, int aFlag);
    FUN_004d61b0(int a1, int a2, int a3, const char* a4, int a5, int a6, int a7, int a8);
};

// @fnv 0x004d61b0
FUN_004d61b0::FUN_004d61b0(int a1, int a2, int a3, const char* apName, int a5, int a6, int a7, int a8) : m18(0x25)
{
    m00 = a1;
    m04 = a2;
    m28 = a3;
    char* pNameBuffer = FormHeap_Allocate(BSstrlen(apName) + 1);
    m2c = pNameBuffer;
    ourStrcpy(m2c, ConvertFromUni(apName, 0));
    CreateTreeWindows(a5, a6, a7, a8);
    NiTreeCtrl_SetImageList();
    if (a3 != 0)
    {
        NiTreeCtrl_CreateTree(a3, 0);
    }
}

