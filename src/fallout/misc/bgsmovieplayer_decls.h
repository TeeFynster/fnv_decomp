// fallout/misc/bgsmovieplayer_decls.h: declares Direct3DDeviceInterface, OSGlobals, BGSMoviePlayer
#ifndef FNV_BGSMOVIEPLAYER_DECLS_H
#define FNV_BGSMOVIEPLAYER_DECLS_H

#include "../../../include/BSAudio.h"


class Direct3DDeviceInterface
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual int __stdcall TestCooperativeLevel();
};


NiRenderer* Renderer_GetNIRenderer();
NiRenderer* NiXenonRenderer_GetRenderer();


BSAudio* BSAudio_QInstance();
extern unsigned char DAT_011de714;

bool is_bEyeFinity();
bool IsEyefinity();
float Get_1280_();
float Get_720_();
unsigned int Renderer_GetScreenWidth();
unsigned int Renderer_GetScreenHeight();

// InputManager (declared by OSGlobals.h, no shared definition): what g_osGlobals->FUN_00877720 returns here, not the
// hotkey wheel: 0x00a23010 copies the key-state globals (0x011f35a8.. to 0x011f35b8..), 0x00a24660 tests a control
class InputManager
{
  public:
    void Controls_UpdateValues();
    int Controls_GetUserAction(unsigned int, bool);
};

#include "../../../include/OSGlobals.h"

extern OSGlobals* g_osGlobals;



#endif
