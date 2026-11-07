
// to their real unit once identified.

#include "layout_support.h"
class NiD3DPass;
class NiD3DPixelShader;
class D3DRenderStateGroup;
class NiD3DShaderConstantMap;
class BeamStage;
class NiD3DVertexShader;
#include "nid3dpass_types_NiTArray_NiPointer_NiD3DTextureStage__NiTNewInterface_NiPointer_NiD3DTextureStage_____.h"
#include "nid3dpass_decls.h"

struct FUN_00e7ee80 : SNAEntry
{
    unsigned int extra;
    FUN_00e7ee80() throw();
    ~FUN_00e7ee80() throw();
};
// @fnv 0x00e7f0a0
// src: GUESS 0x00e7f0a0 (confidence: medium)
FUN_00e7ee80* Object_CreateElementArray(unsigned int count)
{
    return new FUN_00e7ee80[count];
}

namespace fnv_00e7e880 {
class SpawnedObject
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    static void* operator new[](unsigned int bytes) throw();
    SpawnedObject() throw();
    ~SpawnedObject()
    {}
};

// @fnv 0x00e7e880
// src: GUESS 0x00e7e880 (confidence: low)
SpawnedObject* Object_GetIndexedValue_00e7e880(unsigned int count)
{
    return new SpawnedObject[count];
}
}  // namespace fnv_00e7e880
