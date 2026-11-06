// fallout_shared/facegen/bsfacegenkeyframe_decls.h: unit-specific declarations
#ifndef FNV_BSFACEGENKEYFRAME_DECLS_H
#define FNV_BSFACEGENKEYFRAME_DECLS_H

#include "layout_support.h"

class BSFaceGenManager
{
  public:
    static void ApplyFaceGenValues(float* quantities, unsigned int count, bool initialize);
    static void NormalizeFaceGenValues(float* quantities, unsigned int count);
};

#endif
