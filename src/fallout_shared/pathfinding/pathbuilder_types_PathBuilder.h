// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHBUILDER_H
#define FNV_PATHBUILDER_H

struct OutNodes;
class PathingInfoEntry;
class ScrapHeapBuffer;

MemoryManager* MemoryManager_Instance();
#include "../../../include/PathBuilder.h"
void* Memory_ReturnPlacementAddress(unsigned int, void*);
FNV_STATIC_ASSERT(sizeof(PathBuilder::FindTriangleForLocationWaterFilter) == 4);
FNV_STATIC_ASSERT(sizeof(PathBuilder) == 52);
FNV_STATIC_ASSERT(offsetof(PathBuilder, pRequest) == 0);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_pOutputSolution) == 4);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_pAllocator) == 8);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_kTriangleLocationWaterFilter) == 12);
FNV_STATIC_ASSERT(offsetof(PathBuilder, m_bPathFound) == 16);
FNV_STATIC_ASSERT(offsetof(PathBuilder, DetailedPathInfoList) == 20);
FNV_STATIC_ASSERT(offsetof(PathBuilder, DetailedPathMeshList) == 36);
#endif
