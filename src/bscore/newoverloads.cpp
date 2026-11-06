// The diagnostic allocation overload: it forwards the size to the plain
// MemoryManager allocator while carrying the caller's file, line and
// function text for the allocation trackers.

#include "../../include/MemoryManager.h"

// Allocates size bytes by calling the plain Allocate overload, ignoring the file, line and function arguments.
// @fnv 0x00aa4030
void* MemoryManager::Allocate(unsigned int size, const char* file, const int line, const char* function)
{
    void* result = Allocate(size);
    return result;
}
