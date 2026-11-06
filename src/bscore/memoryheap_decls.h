// bscore/memoryheap_decls.h: the shared MemoryHeap and VirtualAlloc
#ifndef MEMORYHEAP_DECLS_H
#define MEMORYHEAP_DECLS_H

#include "../../include/MemoryHeap.h"
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned int, unsigned int, unsigned int);
#endif
