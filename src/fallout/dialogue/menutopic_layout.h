// Shared types used by the remaining private MenuTopic layouts.
#ifndef FNV_MENUTOPIC_LAYOUT_H
#define FNV_MENUTOPIC_LAYOUT_H
#include <stddef.h>
#include "../../../include/BSStringT.h"
#include "../../../include/BSSimpleList.h"
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif
