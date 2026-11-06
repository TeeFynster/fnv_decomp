// bsshader/particleshader_decls.h: declares NiD3DVertexDeclaration, ParticleShader
#ifndef PARTICLESHADER_DECLS_H
#define PARTICLESHADER_DECLS_H

#include "../../include/BSShader.h"


extern "C"
{
    extern unsigned int fnv_particle_shader_particle_count;
    extern int fnv_particle_shader_renderer_level;
}

class NiRenderer;
class NiD3DVertexDeclaration
{
  public:
    static NiD3DVertexDeclaration* Create(NiRenderer*, unsigned int, unsigned int);
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    virtual void vfn_90();
    virtual void vfn_94(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                        unsigned int, unsigned int);
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
};
extern NiRenderer* DAT_011f9508;
class ParticleShader : public BSShader
{
  public:
    static unsigned int GetShaderParticleCount();
    static BSShader* CreateShader();
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
    virtual void vfn_13c();
    virtual void vfn_140();
    char data[0xc0];
};

class FUN_00ba53f0 : public ParticleShader
{
  public:
    FUN_00ba53f0(NiD3DVertexDeclaration*);
};

#endif
