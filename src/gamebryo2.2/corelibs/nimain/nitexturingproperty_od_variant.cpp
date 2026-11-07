// NiTexturingProperty map replacement, compiled with the original /Od flags.

#include "../../../../include/NiTexturingProperty.h"

// @fnv 0x00533f40
// src: COMMUNITY 0x00533f40
void NiTexturingProperty::SetBaseMap(Map* v)
{
    Map* old = m_kStringArray.GetAt(0);
    if (v != old)
    {
        delete old;
        static_cast<NiTArray<Map*, NiTMallocInterface<Map*> >&>(m_kStringArray).SetAt(0, v);
    }
}
