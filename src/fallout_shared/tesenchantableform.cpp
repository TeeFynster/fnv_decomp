// fallout_shared/tesenchantableform.cpp: TESEnchantableForm (7 functions)

#include "../../include/TESEnchantableForm.h"
#include "../../include/EnchantmentItem.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/TESForm.h"

TESForm* GetFormByID(unsigned int formID);
int Warning(const char* format, ...);

// @fnv 0x004830a0
TESEnchantableForm::TESEnchantableForm()
{
    InitializeComponent();
}

// Resolves the form's enchantment by form ID, warns when it is missing or has an invalid effect trigger, and clears it on failure.
// @fnv 0x00483210
void TESEnchantableForm::InitItem(TESForm* owner)
{
    if (m_pEnchantment)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pEnchantment);
        if (owner)
            TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));

        m_pEnchantment = dynamic_cast<EnchantmentItem*>(GetFormByID(formID));
        if (!m_pEnchantment)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find enchanting (%08X) on owner object \"%s\".", formID,
                            owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find enchanting (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
                Warning("MASTERFILE: Unable to find enchanting (%08X) on unknown owner.", formID);
        }

        if (m_pEnchantment && owner && !m_pEnchantment->FUN_004094f0(owner))
        {
            Warning(
                "MASTERFILE: Enchanting (%08X) '%s' has invalid effect trigger type or effect for object (%08X) '%s'.",
                m_pEnchantment->GetFormID(), m_pEnchantment->GetName(), owner->GetFormID(), owner->GetName());
            m_pEnchantment = 0;
        }
    }
}

// @fnv 0x00483170
void TESEnchantableForm::SetFormEnchantmentAmount(unsigned short amount)
{
    m_usEnchantmentAmount = amount;
}

void __cdecl TESForm_AddChunk_00485910(unsigned int a, unsigned int b);
void __cdecl TESForm_AddChunk_00485950(unsigned int a, unsigned int b);

// @fnv 0x0047bd70
void TESEnchantableForm::Save()
{
    unsigned int tempint;
    if (m_pEnchantment != 0)
    {
        tempint = m_pEnchantment->GetFormID();
        TESForm_AddChunk_00485910(0x4d544945, tempint);
    }
    if (m_usEnchantmentAmount != 0)
    {
        TESForm_AddChunk_00485950(0x544d4145, m_usEnchantmentAmount);
    }
}

// Clears the enchantment form's fields, setting the casting type to 4 and zeroing the other two members.
// @fnv 0x004830d0
void TESEnchantableForm::InitializeComponent()
{
    m_pEnchantment = 0;
    m_usEnchantmentAmount = 0;
    m_eCastingType = MagicSystem__CastingType_CASTING_COUNT;
}


// Returns true when the cast fails or the enchantment or enchantment amount differs.
// @fnv 0x00483190
bool TESEnchantableForm::IsEqualToBase(BaseFormComponent* component)
{
    TESEnchantableForm* other = dynamic_cast<TESEnchantableForm*>(component);
    if (!other)
        return true;
    if (GetEnchantment() != other->GetEnchantment())
        return true;
    if (GetFormEnchantmentAmount() != other->GetFormEnchantmentAmount())
        return true;
    return false;
}

// Casts apComponent to TESEnchantableForm and copies its enchantment, enchantment amount and casting type onto this form.
// @fnv 0x00483100
void TESEnchantableForm::BaseFormRecord(BaseFormComponent* apComponent)
{
    TESEnchantableForm* pForm = dynamic_cast<TESEnchantableForm*>(apComponent);
    if (!pForm)
        return;
    SetFormEnchanting(pForm->GetEnchantment());
    SetFormEnchantmentAmount(pForm->GetFormEnchantmentAmount());
    SetCastingType(pForm->GetCastingType());
}
