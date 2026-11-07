#ifndef NID3DSHADERINTERFACE_DECLS_H
#define NID3DSHADERINTERFACE_DECLS_H

#include "../../../../include/NiD3DDefaultShader.h"
#include "../../../../include/NiD3DPass.h"
#include "../../../../include/NiD3DShaderFactory.h"
#include "../../../../include/NiD3DShaderInterface.h"
#include "../../../../include/NiShader.h"
#include "../../../../include/NiMemObject.h"
#include "../../../../include/NiRenderer.h"

class ShaderPassRenderer
{
  public:
    void** m_ppVirtualMethodTable;
};
class Direct3DDeviceInterface
{
  public:
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
};
class GraphicsRenderer
{
  public:
    unsigned char pad000[0x288];
    ShaderPassRenderer* m_pCurrentRenderState;
    unsigned char pad28c[0x8b8 - 0x28c];
    Direct3DDeviceInterface* m_pD3DDevice;
};
void NiD3DPass_SetD3DRenderer(GraphicsRenderer*);
void NiD3DTextureStage_SetD3DRenderer(GraphicsRenderer*);
void NiD3DShaderProgramFactory_SetD3DRenderer(GraphicsRenderer*);
void NiD3DShaderProgramCreator_SetD3DRenderer(GraphicsRenderer*);
class Program : public NiMemObject
{
  public:
    unsigned char data[28];
    Program* FUN_00e93ad0();
};
extern Direct3DDeviceInterface* DAT_0126f99c;
extern Program* DAT_0126fa10;
#endif
