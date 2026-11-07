
// src/bsshader/bsshaderbloodsplatter_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/bsshaderbloodsplatter.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include <stddef.h>
#ifndef FNV_STATIC_ASSERT
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
#endif

#include "../../include/BSShaderBloodSplatter.h"
#include "../../include/NiPointer.h"
#include "../../include/BSShader.h"
#include "../../include/BSShaderManager.h"
#include "../../include/NiD3DDefaultShader.h"
#include "../../include/NiD3DPass.h"
#include "../../include/NiD3DPixelShader.h"
#include "../../include/NiD3DShader.h"
#include "../../include/NiD3DShaderDeclaration.h"
#include "../../include/NiD3DShaderInterface.h"
#include "../../include/NiD3DVertexShader.h"
#include "../../include/NiShader.h"
#include "../../include/NiShaderDeclaration.h"

#include "bsshaderbloodsplatter_types_NiConsoleShaderDeclaration.h"
extern GraphicsRenderer* g_pkRenderer;
extern float g_splatterDefaultFirst;
extern float g_splatterDefaultSecond;
extern float g_splatterValueA;
extern char g_splatterWhiteFlashPath[];
extern char g_splatterWhiteFlashTexture;
struct SplatterFloat4
{
    float x;
    float y;
    float z;
    float w;
};
#include "bsshaderbloodsplatter_decls.h"
struct SplatterShaderInfo
{
    const char* file;
    _D3DXMACRO macros[9];
};
extern int g_011fedc8;
int* __cdecl BSShaderBloodSplatter_GetRTTI();

struct FUN_0068ab60_shell
{
    void __thiscall ReleaseStorage_0068ab80();
    void __thiscall ForwardCall_0068ab60();
};
// @fnv 0x0068ab60
// src: GUESS 0x0068ab60 (confidence: low)
void __thiscall FUN_0068ab60_shell::ForwardCall_0068ab60()
{
    ReleaseStorage_0068ab80();
}
