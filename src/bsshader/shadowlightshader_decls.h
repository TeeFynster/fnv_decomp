// bsshader/shadowlightshader_decls.h: declares ShadowLightShader
#ifndef SHADOWLIGHTSHADER_DECLS_H
#define SHADOWLIGHTSHADER_DECLS_H

#include "layout_support.h"
#include "NiRefObject.h"
#include "../../include/NiPointer.h"
#include "../../include/NiD3DShaderConstantMap.h"
FNV_STATIC_ASSERT(sizeof(NiD3DShaderConstantMap) == 0x44);
class ShadowLightShader
{
  public:
    unsigned char layoutPadding0[0x18];
    GraphicsRenderer* m_pShaderObject;
    unsigned char layoutPadding1c[0x14];
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
    unsigned char layoutPadding38[0x44];
    NiPointer<NiD3DShaderConstantMap> m_spFillColorConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFogConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spFirstPassConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondPassConstantMap;
    void UpdateShaderConstants();
};
FNV_STATIC_ASSERT(sizeof(ShadowLightShader) == 0x8c);
FNV_STATIC_ASSERT(offsetof(ShadowLightShader, m_spSecondShaderConstantMap) == 0x34);
FNV_STATIC_ASSERT(offsetof(ShadowLightShader, m_spFillColorConstantMap) == 0x7c);
extern "C" const char DAT_01011584[];
extern "C" const char DAT_010A1E50[];
extern "C" const char DAT_010AF568[];
extern "C" const char DAT_010AF5E4[];
extern "C" const char DAT_010AF60C[];
extern const float DAT_011fa090[];
extern const float DAT_011fa0b0[];
extern "C" const unsigned char DAT_011FA0C0[];
extern "C" const unsigned char DAT_011FA0D0[];
extern const float DAT_011fa270[];
extern "C" const unsigned char DAT_011FA280[];
extern "C" const unsigned char DAT_011FA290[];
extern const float DAT_011fa2d0[];
extern const float DAT_011fa2e0[];
extern const float DAT_011fa2f0[];
extern const float DAT_011fa300[];
extern const float DAT_011fa580[];
extern const float DAT_011fd85c[];
extern const float DAT_011fd860[];
extern const float DAT_011fd864[];
extern const float DAT_011fd868[];
extern const float DAT_011fd874[];
extern const float DAT_011fd884[];
extern const float DAT_011fd894[];
extern const float DAT_011fd8a4[];
extern const float DAT_011fd8b4[];
extern const float DAT_011fd8c4[];
extern const float DAT_011fd8d4[];
extern const float DAT_011fd8e4[];
extern const float DAT_011fd8f4[];
extern const float DAT_011fd904[];
extern const float DAT_011fd914[];
extern const float DAT_011fd924[];
extern const float DAT_011fd934[];
extern const float DAT_011fd944[];
extern const float DAT_011fd954[];
extern const float DAT_011fd968[];
extern const float DAT_011fd9a8[];
extern const float DAT_011fd9b8[];
extern const float DAT_011fd9c8[];
extern const float DAT_011fd9d8[];
extern const float DAT_011fd9e8[];
extern const float DAT_011fec88[];
extern const float DAT_011fecc8[];
extern const float DAT_011fed08[];
extern const float DAT_011fed48[];
extern NiPointer<NiShaderConstantMapEntry> DAT_011febd8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febdc;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febe0;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febe4;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febe8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febec;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febf0;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febf4;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febf8;
extern NiPointer<NiShaderConstantMapEntry> DAT_011febfc;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec00;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec04;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec08;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec0c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec10;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec14;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec18;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec1c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec20;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec24;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec28;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec2c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec30;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec34;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec38;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec3c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec40;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec44;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec48;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec4c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec50;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec54;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec58;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec6c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec70;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec74;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec78;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec7c;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec80;
extern NiPointer<NiShaderConstantMapEntry> DAT_011fec84;
#endif
