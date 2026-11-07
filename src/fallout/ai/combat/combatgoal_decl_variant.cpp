// Combat goal world-state validation, using the shared goal declarations.

#include "layout_support_decl_combatgoal.h"
#include "../../../../include/CombatGoal.h"
#include "../../../../include/CombatWorldStateListNode.h"
#include "../../../../include/CombatGoalActivateCombatItem.h"
#include "../../../../include/CombatGoalAdvance.h"
#include "../../../../include/CombatGoalAmbush.h"
#include "../../../../include/CombatGoalAvoidThreats.h"
#include "../../../../include/CombatGoalCluster.h"
#include "../../../../include/CombatGoalFallBack.h"
#include "../../../../include/CombatGoalFindTarget.h"
#include "../../../../include/CombatGoalFlank.h"
#include "../../../../include/CombatGoalFlee.h"
#include "../../../../include/CombatGoalFlushTarget.h"
#include "../../../../include/CombatGoalGuard.h"
#include "../../../../include/CombatGoalHideFromTarget.h"
#include "../../../../include/CombatGoalKillTarget.h"
#include "../../../../include/CombatGoalReachDestination.h"
#include "../../../../include/CombatGoalStayInCombatArea.h"
#include "../../../../include/CombatGoalUseCombatItem.h"
#include "../../../../include/CombatWorldStateListNode.h"

class UnsignedIdHandle
{
  public:
    int type;
    int value;
    int Modelloader_GetReferencedThis();
    int FUN_00726070();
};
class CombatStateValues
{
  public:
    unsigned int GetCombatGoal(int);
    bool CombatWorldStateArray_IsTrue(int, int);
};
// @fnv 0x009843b0
bool CombatGoal::vf00(CombatStateValues* values)
{
    BSSimpleList<UnsignedIdHandle*>* current = GetWorldStateList();
    UnsignedIdHandle* value;
    int state;
    int type;
    while (current && current->GetItem())
    {
        value = current->GetItem();
        state = value->Modelloader_GetReferencedThis();
        type = value->FUN_00726070();
        if (state == 21)
        {
            if (values->GetCombatGoal(type))
                return false;
        }
        else if (state == 22)
        {
            if (!values->GetCombatGoal(type))
                return false;
        }
        else
        {
            if (!values->CombatWorldStateArray_IsTrue(state, type))
                return false;
        }
        current = reinterpret_cast<BSSimpleList<UnsignedIdHandle*>*>(reinterpret_cast<CombatWorldStateListNode*>(current)->GetNext());  // 0x0062d990
    }
    return true;
}
