#ifndef BSSHADERLIGHTINGPROPERTY_GLOBALS_H
#define BSSHADERLIGHTINGPROPERTY_GLOBALS_H

#include "../../include/RecursiveSpinLock.h"
extern unsigned int DAT_011c5f84;
inline bool bsshaderlightingproperty_IsActive(ShadowSceneLight* light)
{
    return light && *(unsigned short*)((char*)light + 0x110) != 0xff &&
           !(*(unsigned int*)(*(char**)((char*)light + 0xf8) + 0x30) & 1);
}
#endif
