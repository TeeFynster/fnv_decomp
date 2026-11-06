#include "../../../include/NiSourceTexture.h"
// fallout/interface/fadermanager_create_decls.h: private surface and texture helpers
#ifndef FADERMANAGER_CREATE_DECLS_H
#define FADERMANAGER_CREATE_DECLS_H

// Private type and helper declarations used by the two creation routines.
void* operator new[](size_t);
void* _NiMalloc(unsigned int);
int FUN_004dc1f0();
int FUN_004dc200();

// Shader inputs used while constructing the fader surface.
struct FaderSurfaceParameters
{
    float fInitialAlpha;
    NiPoint2* pTexCoords;
};

bool FUN_004de070();

extern NiTexture::TextureFormatPreferences DAT_011a9598;

#endif
