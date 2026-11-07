
// src/fallout/ai/combat/combatdialoguemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatdialoguemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/CombatController.h"
struct CombatDialogueHandler
{
    bool CombatDialogueManager_StartDialogue(CombatController*, int, int, bool);
    bool TryStartDialogue(CombatActor*, CombatActor*, int, int, bool, CombatController*);
};
// Starts dialogue with the combat controller's actors, dialogue type, topic and interrupt flag.
// @fnv 0x00983970
// src: XBOX_PDB 0x00983970
bool CombatDialogueHandler::CombatDialogueManager_StartDialogue(CombatController* apCombatController, int aiDialogueType, int aiDialogueTopic,
                                         bool abInterrupt)
{
    return TryStartDialogue(apCombatController->GetFieldBC(), apCombatController->CombatController_GetTarget(),
                            aiDialogueType, aiDialogueTopic, abInterrupt, apCombatController);
}
