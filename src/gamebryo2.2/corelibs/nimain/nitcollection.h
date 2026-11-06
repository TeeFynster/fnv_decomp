#include "nitcollection_decls.h"
template <>
// @fnv 0x00c1d740
NiPointer<NiGeometry>* NiTNewInterface<NiPointer<NiGeometry> >::Allocate(unsigned int count)
{
    return reinterpret_cast<NiPointer<NiGeometry>*>(new (g_memoryManager) NiPointer<NiTexture>[count]);
}
