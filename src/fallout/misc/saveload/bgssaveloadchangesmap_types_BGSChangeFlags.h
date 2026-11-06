// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSCHANGEFLAGS_H
#define FNV_BGSCHANGEFLAGS_H

#include "layout_support.h"
#include "../../../../include/FormChangeMask.h"
class FormChangeMask;
#pragma pack(push, 4)
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormChangeMask) == 4);
FNV_STATIC_ASSERT(offsetof(FormChangeMask, flags) == 0);
#endif
