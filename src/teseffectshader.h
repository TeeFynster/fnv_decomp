// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESEFFECTSHADER_H
#define FNV_TESEFFECTSHADER_H

#include "layout_support.h"
#include "../include/NiPoint3.h"
#include "../include/TESForm.h"
#include "../include/BGSDebris.h"
#include "../include/TESTexture.h"
#include "../include/EffectShaderData.h"
#include "../include/TESEffectShader.h"
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
class ParticleShader
{
  public:
    static unsigned int GetShaderParticleCount();
};
#endif
