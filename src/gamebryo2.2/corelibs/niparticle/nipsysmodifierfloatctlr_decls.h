// Local allocation and float interpolator declarations.
#ifndef NIPSYSMODIFIERFLOATCTLR_DECLS_H
#define NIPSYSMODIFIERFLOATCTLR_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
#include "../../../../include/NiMemObject.h"
class NiFloatData;
// NiObject already derives NiMemObject (through NiRefObject), which supplies operator new (0x00aa13e0).
// LocalNiFloatInterpolator: NiPSysModifierFloatCtlr::LinkObject 0x00c32e10 news it with no unwind state, so its
// constructor must be throw(); include/NiFloatInterpolator.h declares it without an exception specification.
class LocalNiFloatInterpolator : public NiObject
{
  public:
    unsigned char pad[16];
    void SetFloatValue(float);
    LocalNiFloatInterpolator(NiFloatData*) throw();
};
#endif
