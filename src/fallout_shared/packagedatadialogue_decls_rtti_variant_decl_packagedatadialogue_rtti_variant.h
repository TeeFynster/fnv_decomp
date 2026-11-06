// fallout_shared/packagedatadialogue_decls_rtti_variant_decl_packagedatadialogue_rtti_variant.h: declares TESDialoguePackageData
#ifndef PACKAGEDATADIALOGUE_DECLS_H
#define PACKAGEDATADIALOGUE_DECLS_H

class TESQuest;
enum DIALOGUE_TYPE;
class QuestDialogueInfo;
class TESTopicInfo;
class DialogueItem;
#include "../../include/TESForm.h"
#include "TESTopic.h"
TESForm* GetFormByID(unsigned int);
int Warning(const char*, ...);
#include "../../include/TESDialoguePackageData.h"
#endif
