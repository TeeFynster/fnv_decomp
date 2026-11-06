// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramfactory_packet.h: declares NiD3DShaderProgramFactory, DirectoryEntry
#pragma once

#include "../../../../include/NiD3DShaderProgramFactory.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/NiTStringTemplateMap.h"

class NiShader;

typedef NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*> CreatorMap;
extern CreatorMap* DAT_0126fa14;
extern "C" const char* __cdecl strchr(const char*, int);
extern "C" int __cdecl tolower(int);
struct DirectoryEntry
{
    DirectoryEntry* next;
    unsigned int unused;
    const char* value;
};
