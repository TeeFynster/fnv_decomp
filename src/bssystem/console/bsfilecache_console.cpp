
//
// builds the platform cache object once on first use behind the usual
// one-time flag, registers it for destruction, and hands back the shared
// BSFileCache reference the engine caches files through.
//
// Covered PC function: 0x00AFF100 (116 bytes).

#include "layout_support.h"

#include "../../../include/BSFileCache.h"
#include "../../../include/BSWin32FileCache.h"

// Returns a reference to the function-local static BSWin32FileCache instance.
// @fnv 0x00aff100
BSFileCache& BSFileCache::GetRandomGenerator()
{
    static BSWin32FileCache s_fileCache;
    return s_fileCache;
}
