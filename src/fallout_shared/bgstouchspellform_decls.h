// fallout_shared/bgstouchspellform_decls.h: declares TESObjectWithEditorID and unit helpers
#ifndef FNV_BGSTOUCHSPELLFORM_DECLS_H
#define FNV_BGSTOUCHSPELLFORM_DECLS_H


#include "layout_support.h"
#include "../../include/TESForm.h"

class TESObjectWithEditorID
{
  public:
    virtual void vfn_0x000();
    virtual void vfn_0x004();
    virtual void vfn_0x008();
    virtual void vfn_0x00c();
    virtual void vfn_0x010();
    virtual void vfn_0x014();
    virtual void vfn_0x018();
    virtual void vfn_0x01c();
    virtual void vfn_0x020();
    virtual void vfn_0x024();
    virtual void vfn_0x028();
    virtual void vfn_0x02c();
    virtual void vfn_0x030();
    virtual void vfn_0x034();
    virtual void vfn_0x038();
    virtual void vfn_0x03c();
    virtual void vfn_0x040();
    virtual void vfn_0x044();
    virtual void vfn_0x048();
    virtual void vfn_0x04c();
    virtual void vfn_0x050();
    virtual void vfn_0x054();
    virtual void vfn_0x058();
    virtual void vfn_0x05c();
    virtual void vfn_0x060();
    virtual void vfn_0x064();
    virtual void vfn_0x068();
    virtual void vfn_0x06c();
    virtual void vfn_0x070();
    virtual void vfn_0x074();
    virtual void vfn_0x078();
    virtual void vfn_0x07c();
    virtual void vfn_0x080();
    virtual void vfn_0x084();
    virtual void vfn_0x088();
    virtual void vfn_0x08c();
    virtual void vfn_0x090();
    virtual void vfn_0x094();
    virtual void vfn_0x098();
    virtual void vfn_0x09c();
    virtual void vfn_0x0a0();
    virtual void vfn_0x0a4();
    virtual void vfn_0x0a8();
    virtual void vfn_0x0ac();
    virtual void vfn_0x0b0();
    virtual void vfn_0x0b4();
    virtual void vfn_0x0b8();
    virtual void vfn_0x0bc();
    virtual void vfn_0x0c0();
    virtual void vfn_0x0c4();
    virtual void vfn_0x0c8();
    virtual void vfn_0x0cc();
    virtual void vfn_0x0d0();
    virtual void vfn_0x0d4();
    virtual void vfn_0x0d8();
    virtual void vfn_0x0dc();
    virtual void vfn_0x0e0();
    virtual void vfn_0x0e4();
    virtual void vfn_0x0e8();
    virtual void vfn_0x0ec();
    virtual void vfn_0x0f0();
    virtual void vfn_0x0f4();
    virtual void vfn_0x0f8();
    virtual void vfn_0x0fc();
    virtual void vfn_0x100();
    virtual void vfn_0x104();
    virtual void vfn_0x108();
    virtual void vfn_0x10c();
    virtual void vfn_0x110();
    virtual void vfn_0x114();
    virtual void vfn_0x118();
    virtual void vfn_0x11c();
    virtual void vfn_0x120();
    virtual void vfn_0x124();
    virtual void vfn_0x128();
    virtual void vfn_0x12c();
    virtual const char* GetEditorID();
};

TESForm* GetFormByID(unsigned int formID);
int Warning(const char* format, ...);

#endif
