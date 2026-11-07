
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nid3dshaderfactory_decls.h"
const char kFailedShaderFactoryMessage[] = "Failed to create shader factory!";

int __cdecl NiStricmp(const char*, const char*);

struct FUN_00a1e740_Class
{
    bool __thiscall ProcessAndTransformResult_00a1e740(const char*, const char*);
};

// @fnv 0x00a1e740
// src: GUESS 0x00a1e740 (confidence: low)
bool __thiscall FUN_00a1e740_Class::ProcessAndTransformResult_00a1e740(const char* pcKey1, const char* pcKey2)
{
    return NiStricmp(pcKey1, pcKey2) == 0;
}
