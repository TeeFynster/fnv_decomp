#include "../../../../include/NiTStringPointerMap.h"
// gamebryo2.2/corelibs/nimain/niskindata_packet.h: declares SkinMapContext and SkinBoneContainer

#include "../../../../include/NiTStringPointerMap.h"

class ShaderBufferRecord;
struct SkinMapContext
{
    NiTStringPointerMap<ShaderBufferRecord*>* map;
};
struct SkinBoneContainer
{
    char padding[0x44];
    unsigned int count;
};
