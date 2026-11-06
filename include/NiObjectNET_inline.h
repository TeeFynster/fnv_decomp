// NiObjectNET_inline.h: inline bodies for the reference-count members the shared include/NiObjectNET.h redeclares
// (they forward to NiRefObject's inline bodies), for units whose original inlines them.
#pragma once
#include "NiObjectNET.h"
#include "NiRefObject_inline.h"

inline void NiObjectNET::IncRefCount()
{
    NiRefObject::IncRefCount();
}
inline void NiObjectNET::DecRefCount()
{
    NiRefObject::DecRefCount();
}
