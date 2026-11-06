// Enum and allocation declarations used by memorymanager.cpp.
#ifndef FNV_MEMORYMANAGER_IDENTITY_H
#define FNV_MEMORYMANAGER_IDENTITY_H

#include "../../include/SEX.h"

void operator delete(void* pointer) throw();
void FNV_DeleteBuffer(void* pointer);

#endif
