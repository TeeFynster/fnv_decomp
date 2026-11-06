// gamebryo2.2/corelibs/nimain/nibound_decls.h: declares NiBound (NiPoint3, NiMatrix3, NiTransform: the shared headers)
#ifndef NIBOUND_DECLS_H
#define NIBOUND_DECLS_H

#include "../../../../include/NiTransform.h"
class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
    void Update(const NiBound&, const NiTransform&);
};
#endif
