#include "../../../../include/NiTStringPointerMap.h"
// gamebryo2.2/corelibs/niparticle/nipsysmodifierctlr_decls.h: declares the clone map used by this unit
#ifndef NIPSYSMODIFIERCTLR_DECLS_H
#define NIPSYSMODIFIERCTLR_DECLS_H

#include "../../../../include/NiTStringPointerMap.h"

class ShaderBufferRecord;
class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};
#endif
