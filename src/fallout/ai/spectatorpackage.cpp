// fallout/ai/spectatorpackage.cpp: SpectatorPackage (1 function)
#include "spectatorpackage_decls.h"

// @fnv 0x009f9c80
int SpectatorPackage::IsComplete(const SpectatorPackage& other)
{
    if (&other != this)
    {
        Object_ReleaseMediaTypeData(this);
        if (Runtime_CopyMemory_009f9bb0(this, &other) < 0)
            return 0x8007000e;
    }
    return 0;
}
