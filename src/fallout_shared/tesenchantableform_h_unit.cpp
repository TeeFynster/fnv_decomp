#include "../../include/TESEnchantableForm.h"
#include "../../include/TESForm.h"

// @fnv 0x004be330
EnchantmentItem* TESEnchantableForm::FindFormEnchantment(TESForm* form)
{
    TESEnchantableForm* enchantable = dynamic_cast<TESEnchantableForm*>(form);
    return enchantable ? enchantable->GetEnchantment() : 0;
}
