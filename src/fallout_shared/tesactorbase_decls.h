#include "../../include/ProcessLists.h"
// Additional declarations used by the TESActorBase variant unit.
#ifndef TESACTORBASE_DECLS_H
#define TESACTORBASE_DECLS_H

#include "../../include/SEX.h"
#include "../../include/ENUM_FORM_ID.h"

class GlobalObject_008c71b0;

class Crime
{
  public:
    void LoadGame(BGSLoadGameBuffer*);
};

extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;



extern ProcessLists g_kProcessLists;
extern PlayerCharacter* g_thePlayer;
extern "C" void* DAT_01047670;
class GlobalObject_008c71b0
{
  public:
    int flags;
    GlobalObject_008c71b0(int);
    GlobalObject_008c71b0(const GlobalObject_008c71b0&);
};
#endif
