#include "../../../../include/NiObject.h"
#include "../../../../include/NiTransformData.h"
// Unit-specific rotation-key operation and animation-key dispatch tables.
#ifndef FNV_NITRANSFORMDATA_ACCEPTED_DECLS_H
#define FNV_NITRANSFORMDATA_ACCEPTED_DECLS_H

class TimedRotationKey
{
  public:
    void ClearFloatKeys();
};
class PositionKeyInterpolator;
class TimedAnimationKey;

typedef void(__cdecl* NiRotKeyDeleteFunction)(TimedRotationKey*);
typedef void(__cdecl* NiPosKeyDeleteFunction)(PositionKeyInterpolator*);
typedef void(__cdecl* NiFloatKeyDeleteFunction)(TimedAnimationKey*);
extern NiRotKeyDeleteFunction DAT_011f38d0[NiAnimationKey::NUMKEYTYPES];
extern NiPosKeyDeleteFunction DAT_011f38b8[NiAnimationKey::NUMKEYTYPES];
extern NiFloatKeyDeleteFunction DAT_011f38a0[NiAnimationKey::NUMKEYTYPES];
extern unsigned char DAT_011f3764[NiAnimationKey::NUMKEYTYPES];
extern unsigned char DAT_011f375e[NiAnimationKey::NUMKEYTYPES];
extern unsigned char DAT_011f3758[NiAnimationKey::NUMKEYTYPES];

FNV_STATIC_ASSERT(sizeof(NiTransformData) == 0x2c);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_eRotationKeyType) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkRotationKeys) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkPositionKeys) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkScaleKeyArray) == 0x28);

#endif
