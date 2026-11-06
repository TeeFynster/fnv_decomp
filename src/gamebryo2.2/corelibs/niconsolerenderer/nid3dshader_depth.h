#ifndef FNV_NID3DSHADER_DEPTH_H
#define FNV_NID3DSHADER_DEPTH_H


#include "NiMemObject.h"
#include "../../../../include/NiDX9AdditionalDepthStencilBufferData.h"
enum D3DFORMAT
{
    D3DFMT_UNKNOWN = 0
};
class NiPixelFormat;
class Ni2DBuffer;
struct DepthDesc;
struct DepthSurface
{
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
    virtual int __stdcall GetDesc(DepthDesc*);
};
struct DepthDesc
{
    unsigned int format;
    unsigned int type, usage, pool, multitype, multiquality, width, height;
};
struct DepthDevice
{
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
    virtual int __stdcall CheckDeviceFormat(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                                            unsigned int);
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
    virtual int __stdcall CreateDepthStencilSurface(unsigned int, unsigned int, unsigned int, unsigned int,
                                                    unsigned int, unsigned int, DepthSurface**, void*);
};
class NiD3DTextureData
{
  public:
    static D3DFORMAT ConvertPixelFormatToD3DFormat(const NiPixelFormat*);
};
NiPixelFormat* CreatePixelFormat(unsigned int);
char* GetHRESULTText(unsigned int);
extern DepthDevice* DAT_0126f0d8;
extern int DAT_011bf400;
extern char DAT_010ef1f0;

#endif
