// fallout_shared/bgssleepdeprevation.h: local sleep-deprivation declarations
#ifndef FNV_BGSSLEEPDEPREVATION_H
#define FNV_BGSSLEEPDEPREVATION_H


#include "layout_support.h"
#include "../../include/BGSDehydrationStage.h"
#include "../../include/SpellItem.h"
#include "../../include/BGSSleepDeprevationStage.h"

void BGSSleepDeprevationStage_AddStage(BGSSleepDeprevationStage* stage);

class SleepStageDataOperations
{
  public:
    void Initialize();
    void SwapEndian();
};

extern "C" unsigned int DAT_011c31b0;
extern "C" BGSSleepDeprevationStage** DAT_011c31b4;

void operator delete(void* pointer);

#endif
