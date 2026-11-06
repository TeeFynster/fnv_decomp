// fallout_shared/tesloadscreentype_decls.h: declares LoadScreenTypeData
#ifndef TESLOADSCREENTYPE_DECLS_H
#define TESLOADSCREENTYPE_DECLS_H

#include "layout_support.h"
class LoadScreenTypeData
{
  public:
    unsigned char bytes[88];
    void Endian();
};
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
#endif
