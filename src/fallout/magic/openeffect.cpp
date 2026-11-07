
#include "../../../include/NonActorMagicTarget.h"
#include "../../../include/TESObjectREFR.h"

// src/fallout/magic/openeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/openeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_008260b0
{
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
    virtual void Install(FUN_008260b0*);
    float value04;
    void* object08;
    void* object0c;
    bool flag10, flag11, flag12, flag13;
    int unk14, unk18;
    float value1c, value20;
    int unk24;
    void* object28;
    int unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    FUN_008260b0(void*, void*, void*);
    FUN_008260b0* CloneAndInstall();
};
// Allocates a new FUN_008260b0 from object28, object08 and object0c, installs it, and returns it.
// @fnv 0x008260e0
FUN_008260b0* FUN_008260b0::CloneAndInstall()
{
    FUN_008260b0* result = new FUN_008260b0(object28, object08, object0c);
    Install(result);
    return result;
}

int __cdecl FUN_00430b40(int value);

// TESObjectREFR's shared header does not yet declare the lock-level accessor at 0x005691b0.
struct S_00826190_Ref
{
    int TESObjectREFR_GetLockLevel();
};

struct S_00826190_Effect
{
    MagicTarget* FUN_0059bb30();
    float GetFloatAtOffset1C();
    void OpenEffect_Start();
};

// @fnv 0x00826190
// src: XBOX_PDB 0x00826190
void S_00826190_Effect::OpenEffect_Start()
{
    NonActorMagicTarget* target = dynamic_cast<NonActorMagicTarget*>(FUN_0059bb30());
    if (!target || !target->GetMagicTargetReference())
    {
        return;
    }
    void* pLock = target->GetMagicTargetReference()->GetLock();
    int a = FUN_00430b40((int)GetFloatAtOffset1C());
    int lockLevel = FUN_00430b40(reinterpret_cast<S_00826190_Ref*>(target->GetMagicTargetReference())->TESObjectREFR_GetLockLevel());
    if (pLock && a >= lockLevel)
    {
        target->GetMagicTargetReference()->Unlock();
    }
}
