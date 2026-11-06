#ifndef FNV_NIPSYSBOUNDUPDATEMODIFIER_DECLS_H
#define FNV_NIPSYSBOUNDUPDATEMODIFIER_DECLS_H

#include "../../../../include/NiBound.h"
#include "../../../../include/NiPSysBoundUpdateModifier.h"
#include "../../../../include/NiPSysModifier.h"
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;
extern "C" const NiPoint3 NiPoint3_ZERO;

typedef char BoundUpdate_NiBound_size_check[(sizeof(NiBound) == 0x10) ? 1 : -1];
typedef char BoundUpdate_NiPSysModifier_size_check[(sizeof(NiPSysModifier) == 0x18) ? 1 : -1];
typedef char BoundUpdate_size_check[(sizeof(NiPSysBoundUpdateModifier) == 0x20) ? 1 : -1];
typedef char BoundUpdate_skip_offset_check[(offsetof(NiPSysBoundUpdateModifier, m_usUpdateSkip) == 0x18) ? 1 : -1];
typedef char BoundUpdate_bounds_offset_check[(offsetof(NiPSysBoundUpdateModifier, m_pkBounds) == 0x1C) ? 1 : -1];
#endif
