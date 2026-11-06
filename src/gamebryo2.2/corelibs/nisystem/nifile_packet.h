// gamebryo2.2/corelibs/nisystem/nifile_packet.h: declares NiFile, NiFileAccessRequest
#include "../../../../include/NiFile.h"
#ifndef NIFILE_PACKET_H
#define NIFILE_PACKET_H

extern NiFile*(__cdecl* DAT_011ac224)(const char*, NiFile::OpenMode, unsigned int);
struct NiFileAccessRequest
{
    const char* name;
    unsigned int operation;
    unsigned int bufferSize;
    unsigned int reserved0;
    unsigned int mode;
    unsigned int reserved1;
    unsigned int result;
};
void __cdecl CompleteJob(NiFileAccessRequest*);
#endif
