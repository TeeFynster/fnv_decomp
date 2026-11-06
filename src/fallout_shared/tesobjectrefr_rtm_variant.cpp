
// src/fallout_shared/tesobjectrefr_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/tesobjectrefr.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "tesobjectrefr_decls.h"
#include "../../include/BSExtraData.h"
#include "../../include/NonActorMagicTarget.h"
GarbageCollectorUpdateState* FUN_00446ef0();
void* FUN_0056a8c0();
void FUN_005743f0();
void FUN_00575c90(unsigned char value);
float FUN_005790b0();
float FUN_005790d0();
void FUN_0057acc0(unsigned int index);

struct ExtraList
{
    BSExtraData* FUN_00410220(int type);
    void AddExtraData(BSExtraData* p);
};
bool __cdecl FUN_00576040(int x);
class Owner
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int flag);
    int FUN_007af430();
    ExtraList* FUN_005d43c0();
    MagicTarget* FUN_00575f30();
};
// @fnv 0x00575f30
MagicTarget* Owner::FUN_00575f30()
{
    NonActorMagicTarget* p = 0;
    if (FUN_00576040(FUN_007af430()))
    {
        p = dynamic_cast<NonActorMagicTarget*>(FUN_005d43c0()->FUN_00410220(0x33));
        if (!p)
        {
            p = new NonActorMagicTarget(this);
            FUN_005d43c0()->AddExtraData(p);
            v18(0x80000000);
        }
    }
    return p;
}
