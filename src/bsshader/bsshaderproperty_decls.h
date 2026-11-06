// bsshader/bsshaderproperty_decls.h: declares BSShaderPropertyLightSlot, BSShaderProperty
#ifndef FNV_BSSHADERPROPERTY_DECLS_H
#define FNV_BSSHADERPROPERTY_DECLS_H

#include "layout_support.h"
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;
#include "../../include/BSShaderProperty.h"
inline void* BSShaderProperty::ShaderPassEntry::operator new(unsigned int size)
{
    return g_memoryManager.Allocate(size);
}
void __cdecl operator delete(void*);
class NiGeometry;
class ShadowSceneLight;

// Trivial pointer slots let the shader's private allocator own the light array.
// The storage contains only the light pointer, with no per-array lifetime cookie.
struct BSShaderPropertyLightSlot
{
    ShadowSceneLight* light;
    static void* operator new[](unsigned int size)
    {
        return g_memoryManager.Allocate(size);
    }
};
FNV_STATIC_ASSERT(sizeof(BSShaderPropertyLightSlot) == sizeof(ShadowSceneLight*));



#include "../../include/NiTNewInterface.h"
#include "../../include/NiTObjectArray.h"
// Gamebryo NiTArray.inl: the original inlines Add (SetAtGrow); SetSize is 0x00ba8d30 (defined in bsshaderproperty.cpp)
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    T item = element;
    unsigned int index = m_usSize;
    if (index >= m_usMaxSize)
        SetSize(index + m_usGrowBy);
    SetAt(index, item);
    return index;
}
template <> void NiTArray<BSShaderProperty::ShaderPassEntry*, NiTNewInterface<BSShaderProperty::ShaderPassEntry*> >::SetSize(unsigned int);

FNV_STATIC_ASSERT(sizeof(BSShaderProperty::ShaderPassEntry) == 16);
FNV_STATIC_ASSERT(sizeof(BSShaderProperty::ShaderPassList) == 20);
#endif
