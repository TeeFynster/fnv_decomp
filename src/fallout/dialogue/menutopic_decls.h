// fallout/dialogue/menutopic_decls.h: private declarations for MenuTopic

#include "../../../include/MiscStatManager.h"

#ifndef FNV_MENUTOPIC_EXTENSIONS_H
#define FNV_MENUTOPIC_EXTENSIONS_H
class MobileObject;
class PlayerCharacter;
#include "menutopic_layout.h"
#include "../../../include/TESTopic.h"
#include "../../../include/TESTopicInfo.h"
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern PlayerCharacter* g_thePlayer;
int __cdecl Warning(const char*, ...);
class MenuTopicText
{
  public:
    void ImageSpaceModifierInstanceDOF_SetMaskConst();
};
class GlobalObject2_0040c150
{
  public:
    int* Int();
};
extern GlobalObject2_0040c150 g_011d0dc8;
#endif
