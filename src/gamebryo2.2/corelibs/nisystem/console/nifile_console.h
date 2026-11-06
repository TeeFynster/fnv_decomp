// gamebryo2.2/corelibs/nisystem/console/nifile_console.h: NiBinaryStream and NiFile come from include/
#ifndef FNV_ASTRA_NIFILE_H
#define FNV_ASTRA_NIFILE_H

#include <stddef.h>
#include "../../../../../include/NiFile.h"
extern "C" int __cdecl fclose(FILE*);
void __cdecl NiFree(void*);
typedef char check_NiBinaryStream_size[sizeof(NiBinaryStream) == 0x10 ? 1 : -1];
typedef char check_NiFile_size[sizeof(NiFile) == 0x30 ? 1 : -1];
typedef char check_NiFile_buffer[offsetof(NiFile, m_pBuffer) == 0x20 ? 1 : -1];
typedef char check_NiFile_file[offsetof(NiFile, m_pFile) == 0x24 ? 1 : -1];
typedef char check_NiFile_mode[offsetof(NiFile, m_eMode) == 0x28 ? 1 : -1];
typedef char check_NiFile_good[offsetof(NiFile, m_bGood) == 0x2c ? 1 : -1];
#endif
