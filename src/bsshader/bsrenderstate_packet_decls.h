// bsshader/bsrenderstate_packet_decls.h: declares BSRenderStateDevice, GraphicsRenderer
#ifndef BSRENDERSTATE_PACKET_DECLS_H
#define BSRENDERSTATE_PACKET_DECLS_H

class BSRenderStateDevice
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
    virtual void SetRenderState(unsigned int, unsigned int, unsigned int, unsigned int);
};
class GraphicsRenderer
{
  public:
    char pad[0x8b8];
    BSRenderStateDevice* device;
};
extern GraphicsRenderer* g_pkRenderer;
extern int DAT_011ff9d8[];
extern unsigned int DAT_011ffa9c;
extern unsigned int DAT_011ffcd0;
#endif
