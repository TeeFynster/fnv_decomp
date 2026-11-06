#ifndef FNV_NITCOLLECTION_DECLS_H
#define FNV_NITCOLLECTION_DECLS_H
#include "../../../../include/NiPointer.h"
#include "../../../../include/MemoryManager.h"
extern MemoryManager g_memoryManager;
class NiGeometry;
class NiTexture;
template <class T> inline NiPointer<T>::~NiPointer()
{
}
inline void* operator new[](unsigned int size, MemoryManager& memoryManager)
{
    return memoryManager.Allocate(size);
}
#include "../../../../include/NiTNewInterface.h"
#endif
