// fallout_shared/tesweightform.cpp: TESWeightForm, Modifier, WeightComparison (6 functions)

#include "../../include/BaseFormComponent.h"
#include "../../include/ActiveEffect.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESForm.h"
#include "../../include/TESWeightForm.h"

// @fnv 0x0048ebc0
float TESWeightForm::GetWeightForForm(TESForm* form, bool useFormWeight)
{
    TESWeightForm* weightForm = 0;
    float weight = 0.0f;

    if (form)
    {
        switch (((TESBoundObject*)form)->GetFormType())
        {
        case 0x1d: {
            TESForm* form1d = form;
            weightForm = (TESWeightForm*)(form1d ? (char*)form1d + 0x84 : 0);
            break;
        }
        case 0x2f: {
            TESForm* form2f = form;
            weightForm = (TESWeightForm*)(form2f ? (char*)form2f + 0x94 : 0);
            break;
        }
        case 0x28: {
            TESForm* form28 = form;
            weightForm = (TESWeightForm*)(form28 ? (char*)form28 + 0x8c : 0);
            break;
        }
        case 0x1f:
        case 0x2e:
        case 0x32:
        case 0x67: {
            TESForm* form1f = form;
            weightForm = (TESWeightForm*)(form1f ? (char*)form1f + 0x7c : 0);
            break;
        }
        case 0x1b: {
            TESForm* form1b = form;
            weightForm = (TESWeightForm*)(form1b ? (char*)form1b + 0x74 : 0);
            break;
        }
        case 0x1a: {
            TESForm* form1a = form;
            weightForm = (TESWeightForm*)(form1a ? (char*)form1a + 0x60 : 0);
            break;
        }
        case 0x19: {
            TESForm* form19 = form;
            weightForm = (TESWeightForm*)(form19 ? (char*)form19 + 0x8c : 0);
            break;
        }
        case 0x18: {
            TESForm* form18 = form;
            weightForm = (TESWeightForm*)(form18 ? (char*)form18 + 0x60 : 0);
            break;
        }
        case 0x1e: {
            TESForm* form1e = form;
            weightForm = (TESWeightForm*)(form1e ? (char*)form1e + 0x84 : 0);
            break;
        }
        case 0x29: {
            TESForm* form29 = form;
            if (useFormWeight)
                weight = form29->GetFieldB8Float();
            break;
        }
        }
    }

    if (weight != 0.0)
        return weight;
    else if (weightForm)
        return ((ActiveEffect*)weightForm)->GetAge();
    else
        return -1.0f;
}

struct Modifier
{
    void SetValue(float);
    void SetWeight(BaseFormComponent*);
};

extern int DAT_0101a4c4;
void __fastcall FUN_008c6060(void* pThis);

// Runs the BaseFormComponent constructor, installs the vtable pointer from DAT_0101a4c4, calls FUN_008c6060, and returns pThis.
// @fnv 0x0048eac0
// src: GUESS 0x0048eac0 (confidence: low)
void* __fastcall Object_InitializeFields_0048eac0(void* pThis)
{
    ((BaseFormComponent*)pThis)->BaseFormComponent::BaseFormComponent();
    *(int**)pThis = &DAT_0101a4c4;
    FUN_008c6060(pThis);
    return pThis;
}

extern int DAT_0101a4c4;

void __fastcall DestroyBaseFormComponent(void* component);

// @fnv 0x0048eaf0
// src: GUESS 0x0048eaf0 (confidence: low)
void __fastcall TESWeightForm_UpdateState_0048eaf0(void* pThis)
{
    *reinterpret_cast<int*>(pThis) = reinterpret_cast<int>(&DAT_0101a4c4);
    DestroyBaseFormComponent(pThis);
}

class PC7d;
extern PC7d* g_thePlayer;
void __cdecl Interface_QueueMenuCreate(int, int, int, int, int, int);
void __cdecl BGSOpenCloseForm_HandleActivate(int, PC7d*, int);
struct S00517380
{
    void TESObjectCONT_HandleOpenFinish(int, PC7d*);
};
// If a1 is non-zero and a2 is the player, calls FUN_00709470 with (1, a1, 0, 0, 1, 0) then FUN_0047a560(a1, a2, 0).
// @fnv 0x00517380
// src: COMMUNITY 0x00517380
void S00517380::TESObjectCONT_HandleOpenFinish(int a1, PC7d* a2)
{
    if (a1 != 0 && a2 == g_thePlayer)
    {
        Interface_QueueMenuCreate(1, a1, 0, 0, 1, 0);
        BGSOpenCloseForm_HandleActivate(a1, a2, 0);
    }
}

// Casts the component to TESWeightForm and, if valid, sets the value to its weight via GetWeightForForm.
// @fnv 0x0048eb10
void Modifier::SetWeight(BaseFormComponent* component)
{
    TESWeightForm* weightForm = dynamic_cast<TESWeightForm*>(component);
    if (!weightForm)
        return;
    SetValue(weightForm->GetWeightForForm());
}

struct WeightComparison : TESWeightForm
{
    bool TESWeightForm_CompareComponent(BaseFormComponent* component);
};
// Returns true if the other form is not a TESWeightForm or its weight differs from this form's weight.
// @fnv 0x0048eb60
// src: XBOX_PDB 0x0048eb60
bool WeightComparison::TESWeightForm_CompareComponent(BaseFormComponent* component)
{
    TESWeightForm* other = dynamic_cast<TESWeightForm*>(component);
    if (!other)
        return true;
    if (GetWeightForForm() != other->GetWeightForForm())
        return true;
    return false;
}
