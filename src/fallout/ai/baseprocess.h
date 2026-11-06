#include "baseprocess_packet.h"

static const int kCalculateMoveModeValue1 = 257;

// @fnv 0x008d0540
unsigned int BaseProcess::GetAttackChance(Actor* argument0, float argument1, float argument2, float argument3, bool argument4,
                                 bool argument5) const
{
    return kCalculateMoveModeValue1;
}

// @fnv 0x008d03a0
void BaseProcess::StopPackage()
{
    m_kProcessData.Clear();
}

// @fnv 0x00859670
TESPackage* BaseProcess::GetOneTimePackage() const
{
    return GetCurrentPackage();
}

// @fnv 0x008d0450
int BaseProcess::GetPackageInfoValue() const
{
    return GetPackageState();
}

// @fnv 0x008d0400
void BaseProcess::SetPackageExecutionState(int amount)
{
    m_kProcessData.AddToProcedureIndex(amount);
}

// @fnv 0x008d0470
void BaseProcess::SetAnimationState(unsigned int index)
{
    SetPackageInfoState(index);
}
