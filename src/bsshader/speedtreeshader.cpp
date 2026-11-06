// bsshader/speedtreeshader.cpp: SpeedTreeLeafShaderConstantMapSetup (1 function)

#include "speedtreeshader_decls.h"
// Registers the TreeData and WindMatrices shader constants on the map, incrementing index for the second entry.
// @fnv 0x00bb2f50
void SpeedTreeLeafShaderConstantMapSetup::ConfigureShaderConstantMap(NiD3DShaderConstantMap* map, int index)
{
    map->SetConstant("TreeData", 0x10000007, 0, index, 1, "", 16, 4, DAT_01200678, false);
    map->SetConstant("WindMatrices", 0x10000009, 0, ++index, 16, "", 256, 4, DAT_01200688, false);
}
