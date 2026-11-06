#ifndef FNV_ASTRA_NIREF_ARRAY_TYPES_H
#define FNV_ASTRA_NIREF_ARRAY_TYPES_H
#include <stddef.h>
// The covered PC address belongs to this array specialization, not DecRefCount.
#define FNV64_NIPOINTER_INLINE_BODIES
#include "../../../../include/NiPointer.h"
#undef FNV64_NIPOINTER_INLINE_BODIES
#include "../../../../include/NiTArray.h"
class NiAVObject;
// This unit calls the game's out-of-line smart-pointer helpers.
template<> NiPointer<NiAVObject>::NiPointer(NiAVObject*);
template<> NiPointer<NiAVObject>::~NiPointer();
template<> bool NiPointer<NiAVObject>::operator==(const NiPointer<NiAVObject>&) const;
template<> bool NiPointer<NiAVObject>::operator!=(const NiPointer<NiAVObject>&) const;
template<> NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(const NiPointer<NiAVObject>&);
typedef NiPointer<NiAVObject> AVObjectPointer;
typedef NiTArray<AVObjectPointer, NiTNewInterface<AVObjectPointer> > AVObjectArray;
typedef char check_NiPointer[sizeof(AVObjectPointer) == 4 ? 1 : -1];
typedef char check_array_size[sizeof(AVObjectArray) == 0x10 ? 1 : -1];
typedef char check_array_size_field[offsetof(AVObjectArray, m_usSize) == 0x0a ? 1 : -1];
typedef char check_array_effective_field[offsetof(AVObjectArray, m_usESize) == 0x0c ? 1 : -1];
#endif
