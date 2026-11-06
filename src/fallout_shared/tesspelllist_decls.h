// fallout_shared/tesspelllist_decls.h: unit-local BSSimpleList (its destructor gives TESSpellList's constructor the
// original EH states; the shared BSSimpleList declares none) and the shared classes the unit uses
#ifndef FNV_TESSPELLLIST_DECLS_H
#define FNV_TESSPELLLIST_DECLS_H

class ActorPackageContext;
class InventoryStackRecord;

#include "../../include/BSSimpleList.h"

#include "../../include/BaseProcess.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/SpellItem.h"
#include "../../include/TESLevSpell.h"
#include "../../include/TESActorBase.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/TESAttributes.h"
#include "../../include/TESSpellList.h"

extern PlayerCharacter* g_thePlayer;
int Warning(const char*, ...);

#endif
