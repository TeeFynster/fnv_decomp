#pragma once

// Units built on include/layout_support.h already have its legacy BSSimpleArray stand-in (same 0x10 bytes);
// the shared definition would collide with it there.
#ifndef FNV_LAYOUT_SUPPORT_H
#include "BSSimpleArray.h"
#else
template <class T, unsigned int Growth> class BSSimpleArray;
#endif
#include "NiRefObject.h"

// RTTI (.?AV?$BSSimpleArrayRefCounted@...): BSSimpleArray<T,N> at 0 (vftable, data, size, capacity), NiRefObject at
// 0x10 (vftable, reference count), size 0x18.
template <class T, unsigned int Growth>
class BSSimpleArrayRefCounted : public BSSimpleArray<T, Growth>, public NiRefObject
{
};
