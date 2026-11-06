// Types needed by this unit in addition to the shared Gamebryo definitions.
#ifndef FNV_NIAVOBJECT_TYPES_H
#define FNV_NIAVOBJECT_TYPES_H

#include "../../../../include/MapEntryCount.h"
#include "../../../../include/NiBound.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiObjectNET.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiProperty.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiTimeController.h"
#include "../../../../include/NiTransform.h"

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

// The two constructor parameters are inferred from the PC call site.
class FourComponentFloatVector : public NiBound
{
  public:
    FourComponentFloatVector(unsigned int, unsigned int);
};

#endif
