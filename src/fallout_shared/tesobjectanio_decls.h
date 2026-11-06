// fallout_shared/tesobjectanio_decls.h: TESObjectANIO and what its units call, from include/
#ifndef FNV_TESOBJECTANIO_DECLS_H
#define FNV_TESOBJECTANIO_DECLS_H


extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

#include "../../include/TESFile.h"
#include "../../include/TESObjectANIO.h"

typedef char TESObjectANIOSizeCheck[(sizeof(TESObjectANIO) == 0x3c) ? 1 : -1];
#endif
