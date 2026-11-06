#include "../../include/PackageList.h"
#include "../../include/PerkEntryConditionSet.h"
// Local declarations used by tescondition.cpp.
#ifndef TESCONDITION_DECLS_H
#define TESCONDITION_DECLS_H

class TESPackage;

class TESConditionItem
{
  public:
    char opaque[0x1C];
    TESConditionItem();
    ~TESConditionItem();
    bool IsFlagSet();
    void Load(TESFile* file);
    void InitItem(TESForm* form);
    bool Compare(TESConditionItem* other);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result);
};

class DecalDataDeleter
{
  public:
    void* DeleteThis(int doFree);
};

// The approved shared raw-pointer layout lacks automatic list destruction and exception cleanup required at 0x006808b0.
#endif
