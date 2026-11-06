// bsmain/bstaskmanager_types.h: declares IOTask
#ifndef FNV_BSTASKMANAGER_TYPES_H
#define FNV_BSTASKMANAGER_TYPES_H

#include "../../include/IOTask.h"

// Enumerators are unused by this unit.
#include "../../include/IO_TASK_PRIORITY.h"
typedef char IOTaskPriority_size[(sizeof(IO_TASK_PRIORITY) == 4) ? 1 : -1];
typedef char BSTaskInt64_size[(sizeof(BSTask<__int64>) == 24) ? 1 : -1];
typedef char BSTaskInt64_refcount_offset[(offsetof(BSTask<__int64>, BackgroundTask) == 8) ? 1 : -1];
typedef char BSTaskInt64_state_offset[(offsetof(BSTask<__int64>, eState) == 12) ? 1 : -1];
typedef char BSTaskInt64_key_offset[(offsetof(BSTask<__int64>, Key) == 16) ? 1 : -1];
typedef char IOTask_size[(sizeof(IOTask) == 24) ? 1 : -1];
#endif
