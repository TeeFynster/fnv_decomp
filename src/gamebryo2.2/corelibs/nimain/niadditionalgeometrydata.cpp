// gamebryo2.2/corelibs/nimain/niadditionalgeometrydata.cpp: NiAdditionalGeometryData (1 function)

#include "../../../../include/NiAdditionalGeometryData.h"

extern ShadowSceneNode* DAT_011f91c8[];

// @fnv 0x00450b80
ShadowSceneNode* NiAdditionalGeometryData::GetShadowSceneNodeForIndex(int index)
{
    return DAT_011f91c8[index];
}
