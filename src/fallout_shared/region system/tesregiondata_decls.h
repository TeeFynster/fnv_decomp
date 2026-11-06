// fallout_shared/region system/tesregiondata_decls.h: declares RegionDataEntry and ENUM_FORM_ID
#ifndef TESREGIONDATA_DECLS_H
#define TESREGIONDATA_DECLS_H

#include "../../../include/ENUM_FORM_ID.h"
class RegionDataEntry
{
  public:
    unsigned int m_eRegionDataId;
    bool bOverride;
    unsigned char m_ucRegionPriority;
    unsigned char padding[2];
};
#endif
