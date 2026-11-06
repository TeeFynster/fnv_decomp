// bscore/bsperformancetimer_decls.h: declares BSPerformanceTimerFrameData, PerformanceTimerManager
#ifndef BSPERFORMANCETIMER_DECLS_H
#define BSPERFORMANCETIMER_DECLS_H

#include "../../include/NiPointer.h"

class PerformanceMeasurement;
class NiAVObject;
struct BSPerformanceTimerFrameData
{
    bool active;
    unsigned char padding[7];
    unsigned int count;
    float time;
    NiPointer<NiAVObject> object;
    unsigned char tail[8];
};
extern BSPerformanceTimerFrameData DAT_011d8830[3];
class PerformanceTimerManager
{
  public:
    PerformanceMeasurement** m_ppMeasurements;
    int m_iTimerCount;
    int m_iTimerCapacity;
    bool bReset;
    PerformanceMeasurement* Register(char*, char*, bool, bool);
    PerformanceTimerManager* BeginFrame();
};
#endif
