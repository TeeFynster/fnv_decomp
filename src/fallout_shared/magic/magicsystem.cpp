// fallout_shared/magic/magicsystem.cpp: MagicSystem (2 functions)

#include "magicsystem_decls.h"
#include "../../../include/Setting.h"

// @fnv 0x0040ca50
void MagicSystem::InitializeMagicSystem()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Magic\\MagicSystem.cpp", 0x12e);

    DAT_011c3538 = dynamic_cast<TESSound*>(GetFormByID(0x12c));
    if (!DAT_011c3538)
    {
        DAT_011c3538 = new TESSound;
        DAT_011c3538->SetRefID(0x12c, true);
        DAT_011c3538->SetEditorID_AtRuntime("MagicFailureSoundAlteration");
        DAT_011c3538->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3538);
    }

    DAT_011c353c = dynamic_cast<TESSound*>(GetFormByID(0x12d));
    if (!DAT_011c353c)
    {
        DAT_011c353c = new TESSound;
        DAT_011c353c->SetRefID(0x12d, true);
        DAT_011c353c->SetEditorID_AtRuntime("MagicFailureSoundConjuration");
        DAT_011c353c->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c353c);
    }

    DAT_011c3540 = dynamic_cast<TESSound*>(GetFormByID(0x12e));
    if (!DAT_011c3540)
    {
        DAT_011c3540 = new TESSound;
        DAT_011c3540->SetRefID(0x12e, true);
        DAT_011c3540->SetEditorID_AtRuntime("MagicFailureSoundDestruction");
        DAT_011c3540->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3540);
    }

    DAT_011c3544 = dynamic_cast<TESSound*>(GetFormByID(0x12f));
    if (!DAT_011c3544)
    {
        DAT_011c3544 = new TESSound;
        DAT_011c3544->SetRefID(0x12f, true);
        DAT_011c3544->SetEditorID_AtRuntime("MagicFailureSoundIllusion");
        DAT_011c3544->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3544);
    }

    DAT_011c3548 = dynamic_cast<TESSound*>(GetFormByID(0x130));
    if (!DAT_011c3548)
    {
        DAT_011c3548 = new TESSound;
        DAT_011c3548->SetRefID(0x130, true);
        DAT_011c3548->SetEditorID_AtRuntime("MagicFailureSoundMysticism");
        DAT_011c3548->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3548);
    }

    DAT_011c354c = dynamic_cast<TESSound*>(GetFormByID(0x131));
    if (!DAT_011c354c)
    {
        DAT_011c354c = new TESSound;
        DAT_011c354c->SetRefID(0x131, true);
        DAT_011c354c->SetEditorID_AtRuntime("MagicFailureSoundRestoration");
        DAT_011c354c->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c354c);
    }

    DAT_011c3550 = dynamic_cast<TESSound*>(GetFormByID(0x138));
    if (!DAT_011c3550)
    {
        DAT_011c3550 = new TESSound;
        DAT_011c3550->SetRefID(0x138, true);
        DAT_011c3550->SetEditorID_AtRuntime("MagicEnchantDrawSoundAlteration");
        DAT_011c3550->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3550);
    }

    DAT_011c3554 = dynamic_cast<TESSound*>(GetFormByID(0x139));
    if (!DAT_011c3554)
    {
        DAT_011c3554 = new TESSound;
        DAT_011c3554->SetRefID(0x139, true);
        DAT_011c3554->SetEditorID_AtRuntime("MagicEnchantDrawSoundConjuration");
        DAT_011c3554->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3554);
    }

    DAT_011c3558 = dynamic_cast<TESSound*>(GetFormByID(0x13a));
    if (!DAT_011c3558)
    {
        DAT_011c3558 = new TESSound;
        DAT_011c3558->SetRefID(0x13a, true);
        DAT_011c3558->SetEditorID_AtRuntime("MagicEnchantDrawSoundDestruction");
        DAT_011c3558->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3558);
    }

    DAT_011c355c = dynamic_cast<TESSound*>(GetFormByID(0x13b));
    if (!DAT_011c355c)
    {
        DAT_011c355c = new TESSound;
        DAT_011c355c->SetRefID(0x13b, true);
        DAT_011c355c->SetEditorID_AtRuntime("MagicEnchantDrawSoundIllusion");
        DAT_011c355c->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c355c);
    }

    DAT_011c3560 = dynamic_cast<TESSound*>(GetFormByID(0x13c));
    if (!DAT_011c3560)
    {
        DAT_011c3560 = new TESSound;
        DAT_011c3560->SetRefID(0x13c, true);
        DAT_011c3560->SetEditorID_AtRuntime("MagicEnchantDrawSoundMysticism");
        DAT_011c3560->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3560);
    }

    DAT_011c3564 = dynamic_cast<TESSound*>(GetFormByID(0x13d));
    if (!DAT_011c3564)
    {
        DAT_011c3564 = new TESSound;
        DAT_011c3564->SetRefID(0x13d, true);
        DAT_011c3564->SetEditorID_AtRuntime("MagicEnchantDrawSoundRestoration");
        DAT_011c3564->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3564);
    }

    DAT_011c3568 = dynamic_cast<TESSound*>(GetFormByID(0x13e));
    if (!DAT_011c3568)
    {
        DAT_011c3568 = new TESSound;
        DAT_011c3568->SetRefID(0x13e, true);
        DAT_011c3568->SetEditorID_AtRuntime("MagicEnchantHitSoundAlteration");
        DAT_011c3568->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3568);
    }

    DAT_011c356c = dynamic_cast<TESSound*>(GetFormByID(0x13f));
    if (!DAT_011c356c)
    {
        DAT_011c356c = new TESSound;
        DAT_011c356c->SetRefID(0x13f, true);
        DAT_011c356c->SetEditorID_AtRuntime("MagicEnchantHitSoundConjuration");
        DAT_011c356c->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c356c);
    }

    DAT_011c3570 = dynamic_cast<TESSound*>(GetFormByID(0x140));
    if (!DAT_011c3570)
    {
        DAT_011c3570 = new TESSound;
        DAT_011c3570->SetRefID(0x140, true);
        DAT_011c3570->SetEditorID_AtRuntime("MagicEnchantHitSoundDestruction");
        DAT_011c3570->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3570);
    }

    DAT_011c3574 = dynamic_cast<TESSound*>(GetFormByID(0x141));
    if (!DAT_011c3574)
    {
        DAT_011c3574 = new TESSound;
        DAT_011c3574->SetRefID(0x141, true);
        DAT_011c3574->SetEditorID_AtRuntime("MagicEnchantHitSoundIllusion");
        DAT_011c3574->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3574);
    }

    DAT_011c3578 = dynamic_cast<TESSound*>(GetFormByID(0x142));
    if (!DAT_011c3578)
    {
        DAT_011c3578 = new TESSound;
        DAT_011c3578->SetRefID(0x142, true);
        DAT_011c3578->SetEditorID_AtRuntime("MagicEnchantHitSoundMysticism");
        DAT_011c3578->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c3578);
    }

    DAT_011c357c = dynamic_cast<TESSound*>(GetFormByID(0x143));
    if (!DAT_011c357c)
    {
        DAT_011c357c = new TESSound;
        DAT_011c357c->SetRefID(0x143, true);
        DAT_011c357c->SetEditorID_AtRuntime("MagicEnchantHitSoundRestoration");
        DAT_011c357c->SetAltered(false);
        g_dataHandler->hkpMotion_getLinearVelocity()->AddHead(DAT_011c357c);
    }

    DAT_011c3580 = dynamic_cast<TESEffectShader*>(GetFormByID(0x144));
    if (!DAT_011c3580)
    {
        DAT_011c3580 = new TESEffectShader;
        if (DAT_011c3580)
        {
            DAT_011c3580->SetRefID(0x144, true);
            DAT_011c3580->SetEditorID_AtRuntime("effectAbsorb");
            DAT_011c3580->SetAltered(false);
            g_dataHandler->TESDataHandler_GetEffectShaders()->AddHead(DAT_011c3580);
        }
    }

    DAT_011c3584 = dynamic_cast<TESEffectShader*>(GetFormByID(0x145));
    if (!DAT_011c3584)
    {
        DAT_011c3584 = new TESEffectShader;
        if (DAT_011c3584)
        {
            DAT_011c3584->SetRefID(0x145, true);
            DAT_011c3584->SetEditorID_AtRuntime("effectReflect");
            DAT_011c3584->SetAltered(false);
            g_dataHandler->TESDataHandler_GetEffectShaders()->AddHead(DAT_011c3584);
        }
    }

    DAT_011c3588 = dynamic_cast<TESEffectShader*>(GetFormByID(0x146));
    if (!DAT_011c3588)
    {
        DAT_011c3588 = new TESEffectShader;
        if (DAT_011c3588)
        {
            DAT_011c3588->SetRefID(0x146, true);
            DAT_011c3588->SetEditorID_AtRuntime("LifeDetected");
            DAT_011c3588->SetAltered(false);
            g_dataHandler->TESDataHandler_GetEffectShaders()->AddHead(DAT_011c3588);
        }
    }

    DAT_011c358c = dynamic_cast<SpellItem*>(GetFormByID(0x147));
    if (!DAT_011c358c)
    {
        DAT_011c358c = new SpellItem;
        if (DAT_011c358c)
        {
            DAT_011c358c->SetRefID(0x147, true);
            DAT_011c358c->SetEditorID_AtRuntime("spPipBoyLight");
            DAT_011c358c->SetAltered(false);
            g_dataHandler->FUN_0087eaa0()->AddHead(DAT_011c358c);
        }
    }

    EffectSettingCollection::InitializeEffectSettings();
}

extern Setting originalRuntimeFloatSetting9;

// @fnv 0x0040df70
float GetOriginalRuntimeFloatSetting9()
{
    return *originalRuntimeFloatSetting9.Float();
}
