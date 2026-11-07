#pragma once

class TESFile;
class TESForm;
class TESGlobal;
class TESObjectREFR;

// Bethesda TESConditionItem: one condition (the CTDA record), 0x1C bytes: Load reads exactly 0x1C bytes of the CTDA
// chunk into it (0x00681950) and the constructor memsets 0x1C (0x006811e0). TESCondition keeps them in a
// BSSimpleList<TESConditionItem*> (RTTI: ListBox<TESConditionItem *>). No vtable.
class TESConditionItem
{
  public:
    char m_flags;               // +0x00 comparison operator (bits 5..7), OR, run-on/global bits
    unsigned char m_pad01[3];
    union
    {
        float m_comparisonValue;        // +0x04
        TESGlobal* m_comparisonGlobal;  // +0x04 when m_flags & 4
    };
    unsigned short m_usFunctionCode;    // +0x08
    unsigned char m_pad0A[2];
    unsigned int m_data0C;              // +0x0C first parameter
    unsigned int m_data10;              // +0x10 second parameter
    int m_objectType;                   // +0x14 run-on
    TESObjectREFR* m_objectRef;         // +0x18 run-on reference

    TESConditionItem();                                                // 0x006811e0
    ~TESConditionItem();                                               // empty; scalar deleting destructor 0x007b3fa0 (folded)
    unsigned int GetConditionFunction();                                       // 0x005eb680
    bool IsFlagSet();                                                  // 0x005ec040
    int GetComparisonCondition();                                      // 0x005ec060
    void SetObjectType(int objectType);                                // 0x00600ab0
    void FixupAfterLoad();                                             // 0x00681170
    void SetFunction(int functionCode);                                // 0x00681220
    float GetConditionValue();                                         // 0x00681490
    void SetValueIfNoParams(float value);
    bool GetParamCount();                                              // 0x006814e0
    bool IsDifferentFrom(TESConditionItem* other);                     // 0x006815d0
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result); // 0x00681600
    void Load(TESFile* file);                                          // 0x00681950
    void InitItem(TESForm* owner);                                     // 0x006819e0
    bool GetValueIsGlobal() const;
};
