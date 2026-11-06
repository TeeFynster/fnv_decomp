// bsshader/bsfogproperty_decls.h: declares FogPropertyWithBase using shared property types
#ifndef BSFOGPROPERTY_DECLS_H
#define BSFOGPROPERTY_DECLS_H

#include "../../include/NiColor.h"
#include "../../include/NiFogProperty.h"
#include "../../include/NiPlane.h"
#include "../../include/NiProperty.h"

extern NiColor DAT_011f4998;
extern const double DAT_010b9e30;
extern const double DAT_0103a480;
// include/BSFogProperty.h lacks the NiFogProperty base, virtual destructor,
// and typed fog-plane members required by the original constructor.
// local form of BSFogProperty: 0x00bb8180 needs the inlined NiFogProperty base ctor and virtual teardown absent from the shared opaque layout.
class FogPropertyWithBase : public NiFogProperty
{
  public:
    FogPropertyWithBase();
    virtual ~FogPropertyWithBase();
    float m_fFogStartDistance, m_fFogEndDistance, m_fFogParameterA, m_fFogParameterB;
    NiPlane m_kFogPlane;
    float fFalloff, m_fGlyphExtent;
    NiColor m_kFogColor;
    float m_fAlpha;
};
#endif
