#include "../../../include/ActiveEffect.h"
#include "../../../include/Actor.h"
#include "../../../include/EffectSetting.h"
#include "../../../include/GameSettingCollection.h"
#include "../../../include/LightEffect.h"
#include "../../../include/MagicTarget.h"
#include "../../../include/NiAdditionalGeometryData.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiPointLight.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PlayerCharacter.h"
#include "../../../include/ShadowSceneNode.h"
#include "../../../include/TESObjectLIGH.h"

// src/fallout/magic/lighteffect_decl_variant.cpp - declaration variant for 0x0080ee50.

// LightEffect.h does not declare the nonvirtual light-removal routine at 0x0080ed60.
// Its sole argument uses ECX, matching the original no-argument member call.
void __fastcall RemoveLightEffect(LightEffect* effect);

// @fnv 0x0080ee50
// src: XBOX_PDB 0x0080ee50
void LightEffect_AttachBestLightEffect(MagicTarget* target)
{
    if (!target)
        return;
    LightEffect* strongest = 0;
    BSSimpleList<ActiveEffect*>* node = target->GetActiveEffectList();
    while (node && !node->IsEmpty())
    {
        ActiveEffect* effect = node->GetItem();
        if (effect && effect->GetEffectSetting()->GetArchetype() == 13 && !effect->IsDone())
        {
            LightEffect* light = dynamic_cast<LightEffect*>(effect);
            if (!strongest || strongest->GetFloatAtOffset1C() < light->GetFloatAtOffset1C())
            {
                if (strongest)
                    RemoveLightEffect(strongest);
                strongest = light;
            }
            else
            {
                RemoveLightEffect(light);
            }
        }
        node = node->GetNext();
    }
    if (strongest)
        strongest->AttachLightEffect();
}
