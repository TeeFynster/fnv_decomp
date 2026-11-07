// src/fallout/ai/actor_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESBoundObject). The skeleton of src/fallout/ai/actor.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// The legacy utility header has an unguarded smart pointer template.
#include "mobileobject_topicinfo.h"  // first: its shared headers include <windows.h> before layout_support.h
#include "layout_support.h"

#include "../../../include/MiddleHighProcess.h"
#include "../../../include/NiCamera.h"
#include "../../../include/NiControllerSequence.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/BGSEquipType.h"
#include "../../../include/BGSPickupPutdownSounds.h"

#include "../../../include/Actor.h"

struct PickupSoundActorView : public Actor
{
    char* __thiscall Actor_GetPickUpSoundName(::TESBoundObject*, bool, bool);
};

struct PickupSoundVirtualView
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual char* s76();
};
struct PickupPutdownSoundView
{
    void* FUN_00726070();
    void* FUN_0044ddc0();
};
struct PickupAlchemySoundView
{
    void* GetFieldC8();
};
int __fastcall _FNV_GetFormType(void* pThis);
// @fnv 0x008adcf0
// src: XBOX_PDB 0x008adcf0
char* __thiscall PickupSoundActorView::Actor_GetPickUpSoundName(::TESBoundObject* apobjREFR, bool abPickUp, bool abUse)
{
    const char* soundname;
    {
        BGSPickupPutdownSounds* ppickupPutdownSound;
        {
            int eformType;
            {
                AlchemyItem* ping;
                if (!apobjREFR)
                    return 0;
                ppickupPutdownSound = dynamic_cast<BGSPickupPutdownSounds*>(apobjREFR);
                soundname = 0;
                if (!abUse && abPickUp && ppickupPutdownSound &&
                    ((PickupPutdownSoundView*)ppickupPutdownSound)->FUN_00726070())
                {
                    return ((PickupSoundVirtualView*)((PickupPutdownSoundView*)ppickupPutdownSound)->FUN_00726070())
                        ->s76();
                }
                else if (!abUse && !abPickUp && ppickupPutdownSound &&
                         ((PickupPutdownSoundView*)ppickupPutdownSound)->FUN_0044ddc0())
                {
                    return ((PickupSoundVirtualView*)((PickupPutdownSoundView*)ppickupPutdownSound)->FUN_0044ddc0())
                        ->s76();
                }
                eformType = apobjREFR ? ::_FNV_GetFormType(apobjREFR) : 0;
                switch (eformType)
                {
                case 0x2f:
                    if (!abUse)
                    {
                    }
                    else
                    {
                        ping = (AlchemyItem*)apobjREFR;
                        return ((PickupAlchemySoundView*)ping)->GetFieldC8()
                                   ? ((PickupSoundVirtualView*)((PickupAlchemySoundView*)ping)->GetFieldC8())->s76()
                                   : 0;
                    }
                    break;
                case 0x28:
                    switch (BGSEquipType::GetEquipType((TESForm*)apobjREFR))
                    {
                    case 0:
                        return abPickUp ? "UIItemGunsBigUp" : "UIItemGunsBigDown";
                    case 2:
                        return abPickUp ? "UIItemGunsSmallUp" : "UIItemGunsSmallDown";
                    case 3:
                        return abPickUp ? "UIItemMeleeUp" : "UIItemMeleeDown";
                    }
                    break;
                }
                return abPickUp == true ? "UIItemGenericUp" : "UIItemGenericDown";
            }
        }
    }
}
