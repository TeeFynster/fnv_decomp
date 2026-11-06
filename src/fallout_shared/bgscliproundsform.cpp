
// src/fallout_shared/bgscliproundsform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgscliproundsform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BaseFormComponent.h"
#include "../../include/TESForm.h"

// @fnv 0x00475100
void BGSClipRoundsForm::Init()
{
    m_ucClipRounds = 0xc;
}

// Copies clip rounds when component is a BGSClipRoundsForm.
// @fnv 0x00475120
void BGSClipRoundsForm::CopyFromBase(BaseFormComponent* component)
{
    BGSClipRoundsForm* clipRounds = dynamic_cast<BGSClipRoundsForm*>(component);
    if (!clipRounds)
        return;
    SetFormClipRounds(clipRounds->GetClipRounds());
}

// Returns true if the cast fails or the clip rounds differ.
// @fnv 0x00475170
bool BGSClipRoundsForm::CompareWithBase(BaseFormComponent* other)
{
    BGSClipRoundsForm* pClipRoundsForm = dynamic_cast<BGSClipRoundsForm*>(other);
    if (!pClipRoundsForm)
        return true;
    if (GetClipRounds() != pClipRoundsForm->GetClipRounds())
        return true;
    return false;
}
