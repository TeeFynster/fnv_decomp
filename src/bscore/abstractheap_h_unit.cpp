#include "../../include/AbstractHeap.h"

// @fnv 0x00aa7e70
bool AbstractHeap::ContainsBlockImpl(const void* pointer)
{
    return pointer >= pMemHeap && pointer < pMemHeap + MemHeapSize;
}
