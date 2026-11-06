// bsshader/speedtreeshader_decls.h: declares SpeedTreeLeafShaderConstantMapSetup
#ifndef SPEEDTREESHADER_DECLS_H
#define SPEEDTREESHADER_DECLS_H

#include "../../include/NiD3DShaderConstantMap.h"

class SpeedTreeLeafShaderConstantMapSetup
{
  public:
    static void ConfigureShaderConstantMap(NiD3DShaderConstantMap*, int);
};
extern float DAT_01200678[4];
extern float DAT_01200688[64];
#endif
