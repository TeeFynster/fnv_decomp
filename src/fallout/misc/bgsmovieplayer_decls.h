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


NiRenderer* FUN_004bc3f0();
NiRenderer* FUN_0043c4b0();


BSAudio* FUN_00453a70();
extern unsigned char DAT_011de714;

bool FUN_004de070();
bool FUN_004de080();
float FUN_004de0e0();
float FUN_004de0f0();
unsigned int FUN_004dc1f0();
unsigned int FUN_004dc200();

// InputManager (declared by OSGlobals.h, no shared definition): what g_osGlobals->FUN_00877720 returns here, not the
// hotkey wheel: 0x00a23010 copies the key-state globals (0x011f35a8.. to 0x011f35b8..), 0x00a24660 tests a control
class InputManager
{
  public:
    void FUN_00a23010();
    int FUN_00a24660(unsigned int, bool);
};

#include "../../../include/OSGlobals.h"

extern OSGlobals* g_osGlobals;



#endif
