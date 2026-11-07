#ifndef BSDISTANTTREESHADER_DECLS_H
#define BSDISTANTTREESHADER_DECLS_H


#include "bsdistanttreeshader_types_BSDistantTreeShader.h"
#include "bsdistanttreeshader_types_NiPointer_NiGPUProgram_.h"
#include "bsdistanttreeshader_types_NiConsoleShaderDeclaration.h"

class NiRenderer;
extern NiRenderer* DAT_011f9508;
extern "C" unsigned int __security_cookie;
extern "C" void* fnv_zlib_memset(void*, int, unsigned long);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*);
extern "C" void __fastcall __security_check_cookie(unsigned int);



class NiPointerDispatch
{
  public:
    NiPointer_NiGPUProgram_& Replace(NiGPUProgram*);
};



class BeamStage
{
  public:
    static void CreateNewStage(NiPointer<BeamStage>&);
    void NiD3DTextureStage_SetFilterMode(unsigned int);
    void ReturnToPool();
};
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
#include "MemoryManager.h"
extern unsigned int DAT_012007b8;
extern "C" int fnv_particle_shader_renderer_level;
#endif
