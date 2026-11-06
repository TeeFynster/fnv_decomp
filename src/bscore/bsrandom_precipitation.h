// bscore/bsrandom_precipitation.h: unit-local aggregate and list lifetime helpers
#ifndef BSRANDOM_PRECIPITATION_H
#define BSRANDOM_PRECIPITATION_H
#include "../../include/NiPointer.h"
#include "../../include/NiMemObject.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiCamera.h"
// The shared BSShaderAccumulator declares unsized operator delete. This unit's
// original new-expression unwind uses NiMemObject's sized delete, so retain the
// allocation view until the shared declarations can represent that cleanup.
class BSShaderAccumulatorAlloc : public NiMemObject
{
  public:
    BSShaderAccumulatorAlloc(BSShaderManager::BATCHRENDERER_CREATION_MODE, unsigned int, unsigned int);
    char storage[0x280];
};
class GlobalObject_0048f200
{
  public:
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
    float xyz[3];
};
class GlobalObject_0048f200_d0049fe00 : public GlobalObject_0048f200
{
  public:
    GlobalObject_0048f200_d0049fe00()
    {}
    ~GlobalObject_0048f200_d0049fe00();
};
// FUN_0049fcd0_Object: unit-local; what 0x0049fcd0 constructs is not Precipitation (RTTI vftable 0x0104ed98, 0x18 bytes): no vftable store, NiPointers at +0/+0x20/+0x24 and two 12-byte values at +8/+0x14
class FUN_0049fcd0_Object
{
  public:
    FUN_0049fcd0_Object();
    NiPointer<NiAVObject> node;
    int unused;
    GlobalObject_0048f200_d0049fe00 a;
    GlobalObject_0048f200 b;
    NiPointer<NiAVObject> accumulator, object;
};
#endif
