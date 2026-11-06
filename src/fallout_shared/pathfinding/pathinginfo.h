#ifndef FNV_PATHINGINFO_H
#define FNV_PATHINGINFO_H
#include "pathinginfo_decls.h"
// Exe ctor 0x004968b0 stores NiRefObject RTTI vftable 0x0101dce4, not PathingInfo.
#include "../../../include/NiRefObject.h"
// @fnv 0x004968b0
NiRefObject::NiRefObject()
{

    m_uiRefCount = 0;
    InitScriptRunLock((void*)&DAT_011f4400);
}
#endif
