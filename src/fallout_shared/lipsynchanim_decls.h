// fallout_shared/lipsynchanim_decls.h: declares LipSyncAnimation and stream helpers
#ifndef FNV_LIPSYNCHANIM_DECLS_H
#define FNV_LIPSYNCHANIM_DECLS_H


#include "layout_support.h"
#include "../../include/BSFaceGenAnimationData.h"

#include "../../include/BS_FACEGEN_MORPH_TYPE.h"

class LipSyncAnimation
{
  public:
    unsigned int iTransformCountPerTrack;
    int m_iValue;
    float** m_ppPhonemeFrames;
    float** m_ppModifierFrames;

    bool ApplyToAnimationData(BSFaceGenAnimationData* animation, float endDelay);
    void* DeleteThis(unsigned int flags);
    void ReleaseStorage_004d5080();
    float GetNegativeMagnitude(bool, bool, bool, bool, bool);
};

FNV_STATIC_ASSERT(sizeof(LipSyncAnimation) == 16);
FNV_STATIC_ASSERT(offsetof(LipSyncAnimation, m_ppPhonemeFrames) == 8);
FNV_STATIC_ASSERT(offsetof(LipSyncAnimation, m_ppModifierFrames) == 12);

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __cdecl operator delete(void*);
float __cdecl BSMIN(float, float);

#include "../../include/NiBinaryStream.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);
bool __cdecl LipSynchAnim_Decompress(NiBinaryStream*, char*, unsigned int);

#endif
