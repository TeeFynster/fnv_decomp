// fallout_shared/bgsmessage_match_decls.h: declares message access helpers
#ifndef FNV_BGSMESSAGE_MATCH_DECLS_H
#define FNV_BGSMESSAGE_MATCH_DECLS_H


#include "layout_support.h"

class TESForm;
class TESFile;
class TESObjectREFR;
class TESConditionItem;
class NiTexture;
class PerkButtonEntry;

#include "../../include/PerkEntryConditionSet.h"

#include "../../include/TESDescription.h"

extern unsigned int __cdecl SetWarningState(NiTexture* texture);
extern void __cdecl BGSMessageWarningAuxiliary(int value);
extern int __cdecl Warning();
extern int __cdecl Warning(const char* format, ...);

#endif
