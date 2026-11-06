// gamebryo2.2/corelibs/nianimation/nirotkey_decls.h: declares NiAnimationKey, TimedRotationKey
#ifndef ARMY_NIROTKEY_DECLS_H
#define ARMY_NIROTKEY_DECLS_H


#include "../../../../include/NiQuaternion.h"

#include "../../../../include/NiAnimationKey.h"

struct TimedRotationKey
{
    float m_fTime;
    NiQuaternion m_kRotationValue;

    static NiQuaternion __cdecl InterpolatePosition(float fTime, TimedRotationKey* pkKeys, NiAnimationKey::KeyType eType,
                                                    unsigned int uiNumKeys, unsigned int& ruiLastIndex,
                                                    unsigned char ucKeySize);
};

typedef void(__cdecl* NiRotKeyInterpFn)(float, const TimedRotationKey*, const TimedRotationKey*, NiQuaternion*);

extern "C" double DAT_010241b0;
extern "C" NiRotKeyInterpFn DAT_011f3cc0[];

// Placeholders for the 0x00a3ca30 span (thunk + padding + accessor); rename in one place later.
extern "C" void* DAT_01097054;  // NiKeyBasedInterpolator vtbl (JIP-LN-NVSE)
extern "C" void* DAT_011f3740;
void FUN_00a57010();  // ctor tail-target of the thunk (thiscall, no stack args)

#endif
