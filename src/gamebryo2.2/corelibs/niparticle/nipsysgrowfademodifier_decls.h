// gamebryo2.2/corelibs/niparticle/nipsysgrowfademodifier_decls.h: declares NiPSysGrowFadeModifier
#pragma once

#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiPSysModifier.h"
#include "../../../../include/NiStream.h"

class NiPSysGrowFadeModifier : public NiPSysModifier
{
  public:
    float m_fGrowthTime;
    unsigned short m_usGrowGenerationLimit;
    float m_fFadeDuration;
    unsigned short m_usFadeGenerationLimit;
    float m_fInitialScale;
    virtual void LoadBinary(NiStream&);
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T* value)
{
    unsigned int size = sizeof(T);
    stream.m_uiAbsoluteCurrentPos += stream.m_pfnRead(&stream, value, sizeof(T), &size, 1);
}
