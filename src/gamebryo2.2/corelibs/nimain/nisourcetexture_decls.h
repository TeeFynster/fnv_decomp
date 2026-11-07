// gamebryo2.2/corelibs/nimain/nisourcetexture_decls.h: local function and call-shim declarations
#ifndef FNV_NISOURCETEXTURE_DECLS_H
#define FNV_NISOURCETEXTURE_DECLS_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "../../../../include/NiRenderer.h"

extern unsigned int DAT_011c16bc;
void FUN_00a47350();
void FUN_00a5b690();
bool __cdecl NiFile_Access(const char*, int);
extern "C" void __fastcall __security_check_cookie(unsigned int);

#define FNV_NIMEMOBJECT_H
#include "../../../../include/NiMemObject.h"

extern NiFixedString EmptyFS;
extern bool DAT_011f4448;
extern bool DAT_011a9594;
extern bool DAT_011f4780;

void NiStandardizeFilePath(NiFixedString*);
void NiImageConverter_ConvertFilenameToPlatformSpecific_(void*, void*);
void FUN_00a47350();
void NiStream_LoadCStringAsFixedString();
void FUN_00a64700();
void FUN_00a5b690();
void ReadLinkID();
void FUN_00a636f0();
void FUN_00a636b0();
void FUN_00a633d0();
void FUN_00a2e750();
void NiTexture_SetTexture();

class NiFixedStringCallShim
{
  public:
    NiFixedStringCallShim& operator=(const char*);
};

class NiFileAccessCallShim
{
  public:
    static bool Access(const char*, NiFile::OpenMode);
};

class NiSourceTexture;
class NiSourceTextureDeleteVCall
{
  public:
    virtual void Delete(unsigned int) = 0;
};

class NiFileVCall
{
  public:
    virtual void Delete(unsigned int) = 0;
};

class NiSourceTextureVCall
{
  public:
    virtual void vfn_000() = 0;
    virtual void vfn_004() = 0;
    virtual void vfn_008() = 0;
    virtual void vfn_00c() = 0;
    virtual void vfn_010() = 0;
    virtual void vfn_014() = 0;
    virtual void vfn_018() = 0;
    virtual void vfn_01c() = 0;
    virtual void vfn_020() = 0;
    virtual void vfn_024() = 0;
    virtual void vfn_028() = 0;
    virtual void vfn_02c() = 0;
    virtual void vfn_030() = 0;
    virtual void vfn_034() = 0;
    virtual void vfn_038() = 0;
    virtual void vfn_03c() = 0;
    virtual void vfn_040() = 0;
    virtual void vfn_044() = 0;
    virtual void vfn_048() = 0;
    virtual void vfn_04c() = 0;
    virtual void vfn_050() = 0;
    virtual void vfn_054() = 0;
    virtual void vfn_058() = 0;
    virtual void vfn_05c() = 0;
    virtual void vfn_060() = 0;
    virtual void vfn_064() = 0;
    virtual void vfn_068() = 0;
    virtual void vfn_06c() = 0;
    virtual void vfn_070() = 0;
    virtual void vfn_074() = 0;
    virtual void vfn_078() = 0;
    virtual void vfn_07c() = 0;
    virtual void vfn_080() = 0;
    virtual void vfn_084() = 0;
    virtual void vfn_088() = 0;
    virtual void vfn_08c() = 0;
    virtual void vfn_090() = 0;
    virtual void vfn_094() = 0;
    virtual void vfn_098() = 0;
    virtual void vfn_09c() = 0;
    virtual void vfn_0a0() = 0;
    virtual void vfn_0a4() = 0;
    virtual void DestroyAppPixelData() = 0;
    virtual bool vfn_0ac() = 0;
};

#endif
