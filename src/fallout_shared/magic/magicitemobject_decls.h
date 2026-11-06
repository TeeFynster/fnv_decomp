// Declarations used only by magicitemobject.cpp.
#pragma once

#include <stddef.h>

#include "../../../include/EffectItemList.h"
#include "../../../include/MagicItem.h"
#include "../../../include/MagicItemObject.h"
#include "../../../include/TESFile.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESFullName.h"

// Use the shared layouts without introducing nullable base-pointer conversions.
enum
{
    kMagicItemOffset = offsetof(MagicItemObject, m_kName) - offsetof(MagicItem, m_kName),
    kEffectListOffset = offsetof(MagicItemObject, m_iEffectCount) - offsetof(EffectItemList, m_iEffectCount),
    kEffectEntriesOffset = offsetof(MagicItemObject, m_item)
};

// The shared list has no declaration for this out-of-line counting entry point.
class EffectListEntries : public BSSimpleList<EffectItem*>
{
public:
    unsigned int ItemsInList();
};

void __fastcall FUN_004056d0(void*);
extern "C" void* memset(void*, int, unsigned int);
int Warning(const char*, ...);
