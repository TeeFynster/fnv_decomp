// fallout_shared/region system/tesregiondatagrass_decls.h: declares TESRegionDataGrass
#ifndef TESREGIONDATAGRASS_DECLS_H
#define TESREGIONDATAGRASS_DECLS_H

class TESGrass;
#include "../../../include/BSSimpleList.h"
// LocalTESRegionDataGrass: unit-local; its ctor 0x004f1ed0 constructs an 8-byte list at +8 (0x0096a2d0), the shared TESRegionDataGrass has a 4-byte object-list pointer there (size 12, RTTI object size and Xbox PDB)
class LocalTESRegionDataGrass : public TESRegionData
{
  public:
    LocalTESRegionDataGrass();
    virtual ~LocalTESRegionDataGrass();
    BSSimpleList<TESGrass*> kObjects;
};
#endif
