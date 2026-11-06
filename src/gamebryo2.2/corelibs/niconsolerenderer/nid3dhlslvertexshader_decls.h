#ifndef NID3DHLSLVERTEXSHADER_DECLS_H
#define NID3DHLSLVERTEXSHADER_DECLS_H
void* __cdecl _NiMalloc(unsigned int);
class NiD3DShaderProgramCreatorObj;
#include "../../../../include/NiTMallocInterface.h"
#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl / NiTCollection.h bodies the original inlines into the NiTPrimitiveArray constructor
template <class T> inline T* NiTMallocInterface<T>::Allocate(unsigned int uiNumElements)
{
    return (T*)_NiMalloc(uiNumElements * sizeof(T));
}
template <class T, class TAlloc> inline NiTArray<T, TAlloc>::NiTArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
{
    m_usMaxSize = (unsigned short)uiMaxSize;
    m_usGrowBy = (unsigned short)uiGrowBy;
    m_usSize = 0;
    m_usESize = 0;
    if (m_usMaxSize > 0)
        m_pBase = TAlloc::Allocate(m_usMaxSize);
    else
        m_pBase = 0;
}
#endif
