// bsshader/tallgrassshaderproperty_decls.h: declares Entry, TallGrassShaderProperty, TallGrassCacheData, NiRefObject and more
#ifndef TALLGRASS_PRIVATE_H
#define TALLGRASS_PRIVATE_H

#include "../../include/MemoryManager.h"
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../include/NiPointer.h"
#include "../../include/NiRefObject.h"

extern unsigned long DAT_011c9f6c;
extern unsigned int DAT_011f9ef4, DAT_011f9ef8;
class NiShader;
class TallGrassShaderProperty;
#include "../../include/NiTPointerAllocator.h"
#include "../../include/NiTMapBase.h"
template <class A, class K, class V> inline unsigned int NiTMapBase<A, K, V>::GetCount() const
{
    return m_kItemCount.m_uiCount;
}
template <class A, class K, class V> inline void* NiTMapBase<A, K, V>::GetFirstPos() const
{
    for (unsigned int i = 0; i < m_uiHashSize; ++i)
        if (m_ppkHashTable[i])
            return m_ppkHashTable[i];
    return 0;
}

typedef NiTMapBase<NiTPointerAllocator<unsigned int>, const char*, NiShader*> GrassMap;
extern MemoryManager g_memoryManager;
inline MemoryManager& MemoryManager::Instance()
{
    return g_memoryManager;
}
inline void TallGrassFree(void* data)
{
    MemoryManager::Instance().Deallocate(data);
}
class TallGrassShaderProperty
{
  public:
    class TallGrassCacheData
    {
      public:
        unsigned char data[64];
        ~TallGrassCacheData();
        static void operator delete(void* p)
        {
            MemoryManager::Instance().Deallocate(p);
        }
    };
    static unsigned long GetCacheIdentifier();
    __declspec(noalias) static NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned long,
                                          TallGrassCacheData*>* GetCacheDataMap();
    static void ClearCacheData();
    class GeometryCacheEntry;
    __declspec(noalias) static NiTMapBase<NiTPointerAllocator<unsigned int>, const char*,
                                          NiPointer<GeometryCacheEntry> >* GetGeometryCacheMap();
    static void ClearCaches();
};
template <class T> inline void DestroyGrass(T* pointer)
{
    if (pointer)
    {
        pointer->~T();
        MemoryManager::Instance().Deallocate(pointer);
    }
}
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
}
inline void NiRefObject::DecRefCount()
{
    if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)))
        DeleteThis();
}
class TallGrassShaderProperty::GeometryCacheEntry : public NiRefObject
{
  public:
    NiPointer<NiRefObject> geometry;
    void* data;
    unsigned int field10;
    NiPointer<NiRefObject> field14;
    NiPointer<NiRefObject> field18;
    NiPointer<NiRefObject> field1c;
    NiPointer<NiRefObject> field20;
    unsigned char padding[14];
    bool owned;
};
template <> __declspec(noalias) void NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned long,
    TallGrassShaderProperty::TallGrassCacheData*>::GetNext(void*&, unsigned long&,
    TallGrassShaderProperty::TallGrassCacheData*&) const;
template <> __declspec(noalias) void NiTMapBase<NiTPointerAllocator<unsigned int>, const char*,
    NiPointer<TallGrassShaderProperty::GeometryCacheEntry> >::GetNext(void*&, const char*&,
    NiPointer<TallGrassShaderProperty::GeometryCacheEntry>&) const;
#endif
