#include "../include/BSSimpleList.h"
#ifndef LOADSCREEN_MATCH_H
#define LOADSCREEN_MATCH_H

#include <stddef.h>
#define FNV_JOIN2(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN2(a, b)
#define FNV_STATIC_ASSERT(e) typedef char FNV_JOIN(fnv_check_, __LINE__)[(e) ? 1 : -1]
#include "../include/ENUM_FORM_ID.h"


class WorldCellRecord
{
  public:
    unsigned int auiFormId;
    unsigned int uiWorldID;
    unsigned int uiCellKey;
};
FNV_STATIC_ASSERT(sizeof(WorldCellRecord) == 12);
FNV_STATIC_ASSERT(offsetof(WorldCellRecord, auiFormId) == 0);
FNV_STATIC_ASSERT(offsetof(WorldCellRecord, uiWorldID) == 4);
FNV_STATIC_ASSERT(offsetof(WorldCellRecord, uiCellKey) == 8);


class ExtraDataList;
class NiNode;
class AnimData;
class ValidBip01Names;

extern "C" void* __cdecl _alloca(unsigned int);
int __cdecl Warning(const char*, ...);
#endif
