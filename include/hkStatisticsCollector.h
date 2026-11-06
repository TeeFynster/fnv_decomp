#pragma once

#include "hkReferencedObject.h"

class hkClass;

template <class T, class Allocator>
class hkArray;

class hkStatisticsCollector : public hkReferencedObject
{
public:
    virtual ~hkStatisticsCollector() throw();
    virtual void addChildObject(const char* name, const void* obj, const void* cls) throw();
    virtual void AddObjectInstance(const char* name, const void* obj);
    virtual void AddMemoryChunk(int type, const char* name, const void* chunk, int usedSize, int allocatedSize) throw();
    virtual void beginObject(const char* name) throw();
    virtual void endObject() throw();

    int pad08;
    int pad0C;
    char m_reportInplaceAllocations;
    unsigned char unk11[3];

    __forceinline void beginObject(const char* name, const void* obj, const hkClass* cls) throw()
    {
        addChildObject(name, obj, static_cast<const void*>(cls));
    }

    void addChildObject(const char* name, const void* obj, int flags);

    template <class T, class Allocator>
    void addArray(const char* name, const hkArray<T, Allocator>& array);

    void DispatchWithMode(const char* name, const void* ptr, int size, int unk) throw();
};
