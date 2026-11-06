// Constructor implementations for this unit's shared dynamic containers.
#ifndef NIDYNAMICGEOMETRYGROUP_DECLS_H
#define NIDYNAMICGEOMETRYGROUP_DECLS_H

void* __cdecl _NiMalloc(unsigned int) throw();
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int) throw();

template <class T> DynamicMapBase<T>::DynamicMapBase() : size(37), count(0)
{
    table = _NiMalloc(37 * 4);
    fnv_zlib_memset(table, 0, size * 4);
}

template <class T> DynamicMap<T>::DynamicMap()
{}

template <class T, class A> __forceinline NiTArray<T,A>::NiTArray(unsigned int maxSize, unsigned int growBy) throw()
{
    m_usMaxSize = (unsigned short)maxSize;
    m_usGrowBy = (unsigned short)growBy;
    m_usSize = 0;
    m_usESize = 0;
    m_pBase = m_usMaxSize ? A::Allocate(m_usMaxSize) : 0;
}
template <class T> __forceinline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int maxSize, unsigned int growBy) throw()
    : NiTArray<T, NiTMallocInterface<T> >(maxSize,growBy)
{}

#endif
