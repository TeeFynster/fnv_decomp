// speedtree/windengine_decls.h: declares Matrix4f
#ifndef FNV_WINDENGINE_DECLS_H
#define FNV_WINDENGINE_DECLS_H


#include "layout_support.h"
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;

class Matrix4f
{
  public:
    float m_fComponents[4][4];

    Matrix4f();
    void InitializeIdentity();

    static __forceinline void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }

    static __forceinline void operator delete[](void* pointer)
    {
        g_memoryManager.Deallocate(pointer);
    }
};

FNV_STATIC_ASSERT(sizeof(Matrix4f) == 64);

#endif
