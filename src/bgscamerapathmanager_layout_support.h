// Unit-local declaration subset of the supplied layout support header.
// No out-of-unit function bodies are defined here.
#ifndef FNV_LAYOUT_SUPPORT_H
#define FNV_LAYOUT_SUPPORT_H

#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
class TESFile;
class TESObjectREFR;
class TESConditionItem;
#include "../include/BSSimpleList.h"
#include "../include/NiTMallocInterface.h"
#include "../include/NiTArray.h"
#include "../include/ENUM_FORM_ID.h"
FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
#endif
