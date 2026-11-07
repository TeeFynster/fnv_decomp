#pragma once

#include "PerkEntryConditionSet.h"

class Actor;
class EffectSetting;
class TESFile;
class TESForm;
class TESObjectREFR;
template <class T> class BSStringT;

struct MagicEffectEntry
{
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
    MagicEffectEntry();
    void Endian();
};

class EffectItem
{
public:
    union
    {
        struct
        {
            MagicEffectEntry data;
        };
        struct
        {
            int m_iMagnitude;
            int m_iArea;
            int m_iPayloadInteger;
            int m_eRange;
            int m_eAssociatedActorValue;
        };
        struct
        {
            int unk00;
            int unk04;
            int unk08;
            int unk0c;
            int unk10;
        };
    };
    union
    {
        EffectSetting* m_pEffectSetting;
        EffectSetting* unk14;
    };
    union
    {
        float m_fCost;
        float unk18;
    };
    union
    {
        struct
        {
            PerkEntryConditionSet Conditions;
        };
        struct
        {
            TESConditionItem* unk1c;
            BSSimpleList<TESConditionItem*>* unk20;
        };
    };

    EffectItem();
    EffectItem(int value);
    EffectItem(EffectSetting* setting);
    ~EffectItem();
    void Save();
    void Init(int value);
    void Initialize(EffectSetting* setting);
    void Initialize_00403be0(EffectSetting* setting);
    bool SetMagnitude_004043d0(int magnitude);
    bool SetArea_00404470(int area);
    bool SetDuration_00404510(int duration);
    bool SetRange_00404560(unsigned int range);
    bool SetMagnitude(int magnitude);
    bool SetArea(int area);
    bool SetDuration(int duration);
    bool SetRange(unsigned int range);
    EffectItem* GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    int FUN_00403ea0();
    float FUN_00403f00();

    void DestroyContents();                          // 0x00403d50
    void InitItem(TESForm* form);                    // 0x00403db0
    int GetAffectedActorValue();                     // 0x00403ea0
    bool IsActorValueUsed();                             // 0x00403ee0
    float GetRawCost();                              // 0x00403f00 computes and caches m_fCost
    float GetCost(Actor* actor);                     // 0x00403f80
    bool Compare(EffectItem* other);                 // 0x004042a0
    int GetMagnitude();                              // 0x00404390
    int GetArea();                                   // 0x00404420
    int GetDuration();                               // 0x004044d0
    void* GetScript();                               // 0x004045e0
    int GetEffectID();                               // 0x00404650
    BSStringT<char> GetEffectName();                 // 0x00404670
    bool IsHostile();                                // 0x00404710
    bool IsScriptBasedEffect();                      // 0x00404730
    bool IsDetrimental();                            // 0x00405e40
    PerkEntryConditionSet* GetConditions();          // 0x00409140
    void Process(TESObjectREFR* target, int arg);    // 0x0062e500
    bool IsScriptEffect_008231f0();                             // 0x008231f0
    EffectSetting* GetEffectSetting();               // 0x00825c00
    int GetRange();                                  // 0x0084e3a0 (folded int getter)
    bool Load(TESFile* file, const char* actorEffect);
    EffectItem* Delete(unsigned int flags);
};
