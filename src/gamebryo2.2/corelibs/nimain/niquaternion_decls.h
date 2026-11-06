// gamebryo2.2/corelibs/nimain/niquaternion_decls.h: NiQuaternion, NiColorA, NiMatrix3, NiStream and
// NiBinaryStream come from include/; this header keeps the CRT declarations the unit uses.
#ifndef NIQUATERNION_PRIVATE_DECLS_H
#define NIQUATERNION_PRIVATE_DECLS_H

extern "C" double __cdecl sqrt(double);

#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiColorA.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiBinaryStream.h"

extern "C" double __cdecl cos(double);
extern "C" double __cdecl sin(double);
#endif
