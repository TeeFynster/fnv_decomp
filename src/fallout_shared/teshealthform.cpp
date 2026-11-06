// fallout_shared/teshealthform.cpp: TESHealthForm (7 functions)

#include "../../include/TESHealthForm.h"
#include "../../include/TESObjectWEAP.h"
#include "../../include/TESObjectARMO.h"
#include "../../include/TESActorBase.h"

static const int kInitializeDataComponentValue1 = 100;

// @fnv 0x00487220
void TESHealthForm::InitializeComponent()
{
    m_uiHealthValue = kInitializeDataComponentValue1;
}

// Returns the health of form if it is a TESHealthForm, otherwise returns 0.
// @fnv 0x004873d0
unsigned int TESHealthForm::GetBaseHealth(TESForm* form)
{
    TESHealthForm* health = GetFormAsHealthForm(form);
    if (health)
        return health->GetHealth();
    else
        return 0;
}

// @fnv 0x004871d0
TESHealthForm::TESHealthForm()
{
    InitializeComponent();
}

struct TESFile_Access
{
    void InitializeComponent();
};

// @fnv 0x00487200
TESHealthForm::~TESHealthForm()
{
    reinterpret_cast<TESFile_Access*>(this)->InitializeComponent();
}

unsigned int __fastcall _FNV_GetFormType(void* pForm);

// Returns apForm cast to TESHealthForm if its form type is weapon, armor, or actor base, otherwise null.
// @fnv 0x004872e0
TESHealthForm* TESHealthForm::GetFormAsHealthForm(TESForm* apForm)
{
    TESHealthForm* pHealthForm = 0;
    if (apForm)
    {
        switch (_FNV_GetFormType(apForm))
        {
        case 0x28: {
            TESObjectWEAP* pform = reinterpret_cast<TESObjectWEAP*>(apForm);
            pHealthForm = pform;
            break;
        }
        case 0x18: {
            TESObjectARMO* pform = reinterpret_cast<TESObjectARMO*>(apForm);
            pHealthForm = pform;
            break;
        }
        case 0x2a:
        case 0x2b: {
            TESActorBase* pform = reinterpret_cast<TESActorBase*>(apForm);
            pHealthForm = pform;
            break;
        }
        }
    }
    return pHealthForm;
}

// @fnv 0x00487240
void TESHealthForm::BaseFormRecord(BaseFormComponent* apCopyFC)
{
    TESHealthForm* pCopy = dynamic_cast<TESHealthForm*>(apCopyFC);
    if (!pCopy)
        return;
    SetFormHealth(pCopy->m_uiHealthValue);
}

// Returns true if the given component is not a TESHealthForm or its health value differs from this form's health value.
// @fnv 0x00487290
bool TESHealthForm::IsEqualToBase(BaseFormComponent* component)
{
    TESHealthForm* casted = dynamic_cast<TESHealthForm*>(component);
    if (!casted)
        return true;
    if (m_uiHealthValue != casted->m_uiHealthValue)
        return true;
    return false;
}
