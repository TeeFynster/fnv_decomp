#include "../../../include/EffectItem.h"


int EffectItem::GetAffectedActorValue()
{
    return IsActorValueUsed() ? m_eAssociatedActorValue : -1;
}
