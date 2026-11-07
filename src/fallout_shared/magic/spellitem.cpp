// fallout_shared/magic/spellitem.cpp: SpellItem, MagicItem (15 functions)

#include "../../../include/SpellItem.h"
#include "../../../include/ActorValues.h"
#include "../../../include/IngredientItem.h"
#include "../../../include/MagicItem.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESTopicInfo.h"

// Resets spellType, cost, level and flags to 0, -1, 0 and 0.
// @fnv 0x0040e330
void SpellItem::ResetFormData()
{
    spellType = 0;
    cost = -1;
    level = 0;
    flags = 0;
}

// @fnv 0x0040e280
unsigned int MagicItem::GetChunkID()
{
    return 0x54495053;
}

// @fnv 0x0040e500
void SpellItem::SetValue(int value)
{
    cost = value;
}

// @fnv 0x0040e670
bool MagicItem::GetNoAbsorbOrReflect()
{
    return ((SpellItem*)((char*)this - 0x18))->FUN_0040e210(0x40);
}

struct Base5a
{
    virtual ~Base5a();
    char _pad[20];
};
struct FUN_00409210
{
    Base5a _a;
    IngredientItem _b;
    ~FUN_00409210();
};
// Destructor for the object holding a Base5a and an IngredientItem; the body is empty.
// @fnv 0x00409210
FUN_00409210::~FUN_00409210()
{}

// Returns true when the object at this-0x18 reports false for the argument 1.
// @fnv 0x0040e1e0
bool MagicItem::IsAutoCalculated()
{
    return !(unsigned char)((SpellItem*)((char*)this - 0x18))->ContainsAnyFlag(1);
}

// @fnv 0x0040e650
bool MagicItem::IgnoreResistance()
{
    return ((SpellItem*)((char*)this - 0x18))->FUN_0040e210(0x20);
}

// Sets the form type to 0x14 and resets the spell data.
// @fnv 0x0040e160
SpellItem::SpellItem()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x14));
    ResetFormData();
}

// Secondary-interface override: the speaker sound when the info is flagged, otherwise a sound picked
// from the interface's own value.

class E600Sound;

E600Sound* __cdecl E600PickSound(float fValue);

class E600Info
{
  public:
    virtual ~E600Info();
    bool HasFlag(int iFlag);
    E600Sound* GetSpeaker();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

class E600SoundSource
{
  public:
    virtual void Unk_00();
    virtual E600Sound* SpellItem_GetLevel();
    virtual float GetValue(int iIndex);
};

class E600TopicInfo : public E600Info, public E600SoundSource
{
  public:
    virtual E600Sound* SpellItem_GetLevel();
};

// Returns the speaker sound if flag 1 is set, otherwise picks a sound from the value at index 0.
// @fnv 0x0040e600
// src: COMMUNITY 0x0040e600
E600Sound* E600TopicInfo::SpellItem_GetLevel()
{
    if (HasFlag(1))
        return GetSpeaker();
    else
        return E600PickSound(GetValue(0));
}

// @fnv 0x0040e2c0
SpellItem::~SpellItem()
{
    SpellItem::ClearData();
}

struct MagicBase
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6();
    virtual bool SpellItem_CompareMagicItemData(MagicItem* p);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

// Returns true if the other spell is absent or differs in type, cost, level or flags.
// RTTI returns the containing spell; this points to its secondary interface at offset 0x18.
// @fnv 0x0040e3c0
// src: COMMUNITY 0x0040e3c0
bool MagicItem::SpellItem_CompareMagicItemData(MagicItem* apItem)
{
    MagicItem* a = reinterpret_cast<MagicItem*>(dynamic_cast<SpellItem*>(apItem));
    if (a == 0)
    {
        return true;
    }
    if (reinterpret_cast<MagicBase*>(reinterpret_cast<char*>(a) + 0x18)->s6() != reinterpret_cast<MagicBase*>(reinterpret_cast<char*>(this) - 0x18 + 0x18)->s6() ||
        reinterpret_cast<TESForm*>(a)->GetA() != reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) - 0x18)->GetA() ||
        reinterpret_cast<TESForm*>(a)->GetB() != reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) - 0x18)->GetB() ||
        reinterpret_cast<SpellItem*>(a)->flags != *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x28))
    {
        return true;
    }
    return false;
}

bool TESForm_QEndianSwapOnSave();
void __cdecl AppendChunk(int iValue, void* pData, int iSize);
struct SubE360
{
    void TESRegionSound_Endian();
};
struct PadE360
{
    virtual void f00();
};
struct IfaceE360
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual int GetValue();
    virtual void EnchantmentItem_Endian();
};
struct ObjE360 : PadE360, IfaceE360
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SubE360 m_sub;
    virtual void EnchantmentItem_Endian();
};
// @fnv 0x0040e360
// src: COMMUNITY 0x0040e360
void ObjE360::EnchantmentItem_Endian()
{
    if (TESForm_QEndianSwapOnSave())
        m_sub.TESRegionSound_Endian();
    AppendChunk(GetValue(), &m_sub, 0x10);
    if (TESForm_QEndianSwapOnSave())
        m_sub.TESRegionSound_Endian();
}

struct MagicEffectKind
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int GetType();
};
float __cdecl ScaleBySettingBlend(float cost, int value, int adjustment);
struct FUN_0040e520_shell
{
    int EffectItemList_GetAssociatedSkill();
    float GetTotalCost(Actor* caster);
    float SpellItem_GetCost(Actor* caster);
};
// @fnv 0x0040e520
// src: COMMUNITY 0x0040e520
float FUN_0040e520_shell::SpellItem_GetCost(Actor* caster)
{
    float cost = 0.0f;
    Actor* effectiveCaster = (((MagicEffectKind*)((char*)this - 12))->GetType() == 2 ||
                              ((MagicEffectKind*)((char*)this - 12))->GetType() == 3)
                                 ? 0
                                 : caster;
    if (((SpellItem*)((char*)this - 36))->FUN_0040e210(1))
    {
        cost = (float)((SpellItem*)((char*)this - 36))->GetField38();
        if (effectiveCaster)
        {
            cost =
                ScaleBySettingBlend(cost, ((ActorValues*)((char*)effectiveCaster + 0xa4))->FUN_0066ef20(EffectItemList_GetAssociatedSkill()),
                                    ((ActorValues*)((char*)effectiveCaster + 0xa4))->FUN_0066ef20(11));
        }
    }
    else
    {
        cost = GetTotalCost(effectiveCaster);
    }
    return cost;
}

extern char DAT_01183060;
extern char DAT_01183140;
extern "C" void* __cdecl _FNV_DynamicCast(void*, int, void*, void*, int);
struct SpeakerSink40E
{
    void FUN_00409480(TESActorBase* value);
};

struct CopyPart40E
{
    virtual void slot0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned char flags;
    virtual void SpellItem_CopyMagicItemData(MagicItem* input);
};
struct CopyOwner40E : TESForm, CopyPart40E
{
    void FUN_008d7dc0(int value);
    virtual void SpellItem_CopyMagicItemData(MagicItem* input);
};
// Passes source values to setters, assigns the value returned by GetSpeaker, and copies the source flags.
// @fnv 0x0040e470
// src: COMMUNITY 0x0040e470
void CopyOwner40E::SpellItem_CopyMagicItemData(MagicItem* apSource)
{
    SpellItem* source = static_cast<SpellItem*>(_FNV_DynamicCast(apSource, 0, &DAT_01183140, &DAT_01183060, 0));
    if (source == 0)
        return;
    FUN_008d7dc0(reinterpret_cast<MagicBase*>(reinterpret_cast<char*>(source) + 0x18)->s6());
    reinterpret_cast<SpellItem*>(this)->SetValue(source->GetField38());
    reinterpret_cast<SpeakerSink40E*>(this)->FUN_00409480(reinterpret_cast<TESTopicInfo*>(source)->GetSpeaker());
    flags = source->flags;
}
