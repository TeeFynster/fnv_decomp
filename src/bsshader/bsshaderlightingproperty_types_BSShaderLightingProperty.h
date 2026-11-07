// The shared BSShaderLightingProperty plus the unit's allocation helpers.
#ifndef FNV_BSSHADERLIGHTINGPROPERTY_H
#define FNV_BSSHADERLIGHTINGPROPERTY_H

#include "../../include/BSShaderLightingProperty.h"
#include "../../include/BSShaderNoLightingProperty.h"
// NiMemObjectAllocation_bsshaderlightingproperty_types_BSShaderLightingProperty: local type (was include/NiMemObjectAllocation.h, which had no evidence of one real class); no method of it is bound to a named game function
class NiMemObjectAllocation_bsshaderlightingproperty_types_BSShaderLightingProperty
{
public:
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer);
    static void operator delete(void* pointer, unsigned int size);
};
class ShadowSceneLight;
class CloningProcess;
class bsshaderlightingproperty_NodePool
{
  public:
    void* NiGeometry_AddProperty();
};
// The light list at BSShaderLightingProperty+0x60 (NiTPointerList<ShadowSceneLight*>): the constructor (0x00b71720)
// calls 0x00b71300 on it with ecx = this+0x60, so 0x00b71300/0x00b713c0 are list operations.
class ShadowSceneLightPointerList
{
  public:
    void RemoveAll();
    void InsertAfter(void* position, void* const& element);
};
#endif
