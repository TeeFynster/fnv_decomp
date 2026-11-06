// gamebryo2.2/corelibs/nimain/nismartpointer_h_unit.cpp: free functions (1 function)

#include "nismartpointer.h"

struct Struct6c89e0
{
    NiPointer<WaitableObject> f0;
    int f4;
    int f8;
    NavMeshPtr fC;
    Struct6c89e0& AssignFrom(Struct6c89e0 const*);
};
// @fnv 0x006c89e0
Struct6c89e0& Struct6c89e0::AssignFrom(Struct6c89e0 const* apSource)
{
    f0 = apSource->f0;
    f4 = apSource->f4;
    f8 = apSource->f8;
    fC = apSource->fC;
    return *this;
}
