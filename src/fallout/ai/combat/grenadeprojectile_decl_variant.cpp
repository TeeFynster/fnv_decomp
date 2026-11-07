// src/fallout/ai/combat/grenadeprojectile_decl_variant.cpp

#include "../../../../include/BGSProjectile.h"
#include "../../../../include/GrenadeProjectile.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiTransform.h"
#include "../../../../include/Projectile.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/TESSaveLoadGame.h"

// FUN_009b4740 (0x009b4740) reads impact position at +0x04 and normal at +0x10.
class GrenadeImpactDataLayout
{
  public:
    void* unk00;
    NiPoint3 position;
    NiPoint3 normal;
};

extern TESSaveLoadGame* DAT_011de45c;
void bhkWorld_UpdatePosition(NiAVObject*, bool, bool);
void NiPoint3_UnitizeVector(NiPoint3*);
void TESHavokUtilities_AddVelocity(NiAVObject*, const NiPoint3&, bool);

// @fnv 0x009b4740
// src: GUESS 0x009b4740 (confidence: low)
bool __fastcall Object_ProcessAndReturnValue_009b4740(GrenadeProjectile* projectile)
{
    if (!projectile->kImpacts.IsEmpty())
    {
        NiNode* node1 = projectile->GetNiNode();
        GrenadeImpactDataLayout* impact = reinterpret_cast<GrenadeImpactDataLayout*>(projectile->kImpacts.GetItem());
        if (!DAT_011de45c->FUN_0047c850())
        {
            bhkWorld_UpdatePosition(node1, true, false);
            node1->NiAVObject_SetTranslate(impact->position + impact->normal * node1->GetHeadTail());
            NiUpdateData update0(0.0f, false, false);
            node1->Update(update0);
            NiPoint3 velocity6 = NiPoint3::ZERO;
            NiPoint3 forward1;
            node1->NiAVObject_GetWorldRotate().m_Rotate.GetCol(1, forward1);
            forward1 *= -1.0f;
            NiPoint3_UnitizeVector(&forward1);
            NiPoint3_UnitizeVector(&impact->normal);
            float dot0 = impact->normal.Dot(forward1);
            NiPoint3 deflection = 2.0f * (dot0 * impact->normal - forward1);
            velocity6 = forward1 + deflection;
            velocity6 *= projectile->GetProjectileBase()->GetFloatAtOffset68();
            if (projectile->GetProjectileBase()->GetFloatAtOffsetB0() > 0.0)
                velocity6 *= projectile->GetProjectileBase()->GetFloatAtOffsetB0();
            TESHavokUtilities_AddVelocity(node1, velocity6, true);
        }
    }
    return true;
}
