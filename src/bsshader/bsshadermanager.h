// bsshader/bsshadermanager.h: implements BSShaderManager
#ifndef FNV_BSSHADERMANAGER_H
#define FNV_BSSHADERMANAGER_H

#include "bsshadermanager_decls.h"
#include "../../include/BSShaderManager.h"
// @fnv 0x004dc060
BSShaderManager::etShaderLevel __cdecl BSShaderManager::GetSupportedShaderLevel(bool particleShader)
{
    return static_cast<etShaderLevel>(particleShader ? DAT_011f91bc : fnv_particle_shader_renderer_level);
}
#endif
