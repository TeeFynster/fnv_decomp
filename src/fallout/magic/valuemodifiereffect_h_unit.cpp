#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/ActorMover.h"
#include "../../../include/ActorValueOwner.h"
#include "../../../include/BaseProcess.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/HighProcess.h"
#include "../../../include/MagicCaster.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/ValueModifierEffect.h"

// @fnv 0x006733e0
ActorValue::Index ValueModifierEffect::GetActorValue()
{
    return m_eActorValue;
}

// @fnv 0x00673400
void ValueModifierEffect::SetActorValue(ActorValue::Index value)
{
    m_eActorValue = value;
}
