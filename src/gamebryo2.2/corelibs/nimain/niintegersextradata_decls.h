// gamebryo2.2/corelibs/nimain/niintegersextradata_decls.h: the shared NiIntegersExtraData plus NiIntegerStreamEntry
#ifndef NIINTEGERSEXTRADATA_DECLS_H
#define NIINTEGERSEXTRADATA_DECLS_H

#include "../../../../include/NiIntegersExtraData.h"
class NiStream;
template <class T> void ReadBinaryValue(NiStream&, T&);
class NiIntegerStreamEntry
{
  public:
    unsigned int fields[3];
    void FurnitureMark_LoadBinary(NiStream&);
};
#endif
