// fallout/ai/guardpackage.cpp: GuardActorPackageData, std (6 functions)

#include "../../../include/Actor.h"
#include "../../../include/GuardActorPackageData.h"
#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/TESForm.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "guardpackage_decls.h"
// @fnv 0x00408840
double std::abs(float value)
{
    return fabsf_00408860(value);
}
// Reads eState, a second dword, iWarningCount and a trailing value from the load buffer.
// @fnv 0x009f28b0
void GuardActorPackageData::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(static_cast<void*>(&eState), 4u);
    buffer->ReadTypedData(static_cast<void*>(&m_fWarningTimer), 4u);
    buffer->ReadTypedData(static_cast<void*>(&iWarningCount), 4u);
    buffer->ReadFormIdentifier(&pWarningTarget);
}
// Resolves the stored form reference to an Actor and, if found, calls the reference helper with true.
// @fnv 0x009f2900
void GuardActorPackageData::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    pWarningTarget =
        pWarningTarget ? dynamic_cast<Actor*>(TESForm::GetFormByID((unsigned int)pWarningTarget)) : 0;
    if (pWarningTarget)
        ((TESObjectREFRHelper*)pWarningTarget)->SetTargetingState(true);
}

// Saves the guard state, warning timer, warning count and warning target.
// @fnv 0x009f2850
void GuardActorPackageData::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&eState, 4, 0);
    apSaveGameBuffer->SaveData(&m_fWarningTimer, 4, 0);
    apSaveGameBuffer->SaveData(&iWarningCount, 4, 0);
    apSaveGameBuffer->SerializeFormData(pWarningTarget, 0);
}

void _Deallocate(void*);

// @fnv 0x009f2800
void* GuardActorPackageData::DestroyIfFlagged(unsigned int flags)
{
    this->~GuardActorPackageData();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

// @fnv 0x009f2830
GuardActorPackageData::~GuardActorPackageData()
{
}
