// niblendinterpolator units: NiInterpolator/NiBlendInterpolator come from include/; NiRefObject's inline bodies too.
#ifndef FNV_NIBLENDINTERPOLATOR_PRIVATE_FNV_NIBLENDINTERPOLATOR_H
#define FNV_NIBLENDINTERPOLATOR_PRIVATE_FNV_NIBLENDINTERPOLATOR_H

#include "niblendinterpolator_layout_support.h"
#include "../../../../include/NiRefObject_inline.h"
#include "../../../../include/NiBlendInterpolator.h"
// include/NiInterpolator.h redeclares the reference-count members; they are NiRefObject's inline bodies.
__forceinline void NiInterpolator::IncRefCount() { NiRefObject::IncRefCount(); }
__forceinline void NiInterpolator::DecRefCount() { NiRefObject::DecRefCount(); }
#endif
