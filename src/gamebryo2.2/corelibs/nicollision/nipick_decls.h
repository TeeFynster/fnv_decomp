// Supporting declarations for nipick.cpp.
#ifndef FNV_NIPICK_DECLS_H
#define FNV_NIPICK_DECLS_H

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiPick.h"

extern MemoryManager g_memoryManager;
void NiFree(void*);
extern void* DAT_010f16ec[];
extern void* DAT_010f16dc[];

namespace NiPickIntersections {
bool FindIntersections(const NiPoint3&, const NiPoint3&, NiPick&, NiAVObject*);
}
#endif
