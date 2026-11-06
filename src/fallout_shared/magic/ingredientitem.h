#ifndef FNV_INGREDIENTITEM_H
#define FNV_INGREDIENTITEM_H

#include "../../../include/IngredientItem.h"
#include "../../../include/TESClass.h"

// @fnv 0x005f6e60
bool TESClass::IsGuard()
{
    return bool(data.m_ucClassFlags & 2);
}

#endif
