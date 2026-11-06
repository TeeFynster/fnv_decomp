// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderfactory_decls.h: the shared shader factory classes plus NiStringMapStorage
#ifndef FNV_NID3DSHADERFACTORY_DECLS_H
#define FNV_NID3DSHADERFACTORY_DECLS_H

#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiD3DShaderFactory.h"
#include "../../../../include/NiD3DDefaultShader.h"
struct NiStringMapStorage
{
    void* m_ppVirtualMethodTable;
    unsigned int m_hashSize;
    void* m_hashTable;
    unsigned int m_unused;
    bool m_sState;
};
extern void* DAT_011f4a64;
extern void* DAT_0126fa0c;
extern void* DAT_011f6044;
extern void* DAT_010f0bc0;
extern void* DAT_010f0c20;
extern void* DAT_010f0c80;
extern void* DAT_010f0ca0;
extern void(__stdcall* DAT_00fdf054)(void*);
extern unsigned char kVtbl_NiD3DShaderFactory;
extern MemoryManager g_memoryManager;
extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned long);
#endif
