#include "../../../include/EffectItem.h"


int EffectItem::GetAffectedActorValue()
{
    return FUN_00403ee0() ? m_eAssociatedActorValue : -1;
}
