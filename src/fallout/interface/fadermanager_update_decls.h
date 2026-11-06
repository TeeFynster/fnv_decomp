// fallout/interface/fadermanager_update_decls.h: private update helpers
#ifndef FADERMANAGER_UPDATE_DECLS_H
#define FADERMANAGER_UPDATE_DECLS_H

// Private declarations for the fader update's out-of-line helpers.
#include "../../../include/MEM_CONTEXT.h"

class TimeGlobal
{
  public:
    float GetSecondsPassed();
};
extern TimeGlobal g_timeGlobal;
#endif
