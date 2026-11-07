// gamebryo2.2/corelibs/nimain/niobjectnet_decls.h: the shared classes niobjectnet.cpp works on, plus its externals
#ifndef NIOBJECTNET_PRIVATE_DECLS_H
#define NIOBJECTNET_PRIVATE_DECLS_H

#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiExtraData.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiMorphData.h"
#include "../../../../include/NiInterpolator.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/bhkSphereShape.h"

class CloningProcess;
extern unsigned int DAT_01268280;
float __cdecl NI2HK_004a3e90(float);
extern char g_NiObjectNETExtraDataLock;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
void* __cdecl _NiMalloc(unsigned int);
void __cdecl NiFree(void*);
extern "C" void* __cdecl fnv_zlib_memcpy(void*, const void*, unsigned int);

#endif
