#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiRTTI.h"
#include "../../../../include/NiShader.h"

// gamebryo2.2/corelibs/nimain/nishader.h

#pragma optimize("", off)
bool NiObject_IsKindOf(const NiRTTI*, NiAVObject*);
class GarbageCollectorObjectPtr
{
  public:
    unsigned int storage[2];
    NiAVObject* operator->() const;
};
extern NiRTTI DAT_01267b70;
GarbageCollectorObjectPtr* bhkWorldObject_GetProperty(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
__forceinline bool NiShader::IsKindOfType(const NiRTTI* type) const
{
    const NiRTTI* current = GetRTTI();
    while (current)
    {
        if (current == type)
            return true;
        current = current->m_pBaseRTTI;
    }
    return false;
}
// @fnv 0x0043b300
// src: XBOX_PDB 0x0043b300
bool NiObject_IsKindOf(const NiRTTI* type, NiAVObject* object)
{
    if (!object)
        return false;
    return object->IsKindOfType(type);
}

// @fnv 0x004b5a50
NiAVObject* NiShader::DynamicCast(NiAVObject* object)
{
    GarbageCollectorObjectPtr result;
    return bhkWorldObject_GetProperty(&result, object, &DAT_01267b70)->operator->();
}

#pragma optimize("", on)
// @fnv 0x00b4f580
NiShader* NiShader::DynamicCast(const NiRTTI* type)
{
    return IsKindOfType(type) ? this : 0;
}
#pragma optimize("", off)
