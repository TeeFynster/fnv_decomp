
// src/fallout/magic/magiccaster_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF (unit src/fallout/magic/magiccaster_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magiccaster_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magiccaster.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "../../../include/NiPoint3.h"
#include "../../../include/Setting.h"

#include <xmmintrin.h>
struct __declspec(align(16)) BoundShape
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    __m128 low, high;
    BoundShape();
    ~BoundShape();
};
struct PhantomShape
{
    int field00, field04, field08, field0c, field10, field14;
    PhantomShape(BoundShape* bounds);
    ~PhantomShape();
    void bhkWorldObject_Add(void* form);
    struct ListEntries* FUN_00818110();
    void bhkPhantom_Remove();
};
struct ListEntries
{
    int FUN_00726070();
    int* NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(int at);
};
struct TargetInterface
{
    void** vtable;
    int unused04;
    int unused08;
    int unused0c;
    int unused10;
    int unused14;
    int unused18;
    int unused1c;
    int unused20;
    int unused24;
    int unused28;
    int unused2c;
    int unused30;
    int unused34;
    int unused38;
    int unused3c;
    int unused40;
    int unused44;
    int unused48;
    int unused4c;
    int unused50;
    int unused54;
    int unused58;
    int unused5c;
    int unused60;
    int unused64;
    int unused68;
    int unused6c;
    int unused70;
    int unused74;
    int unused78;
    int unused7c;
    int unused80;
    int unused84;
    int unused88;
    int unused8c;
    int unused90;
    int origin94;
    bool GetGhost_008ace90();
    float TESObjectREFR_GetDistanceFromPoint(NiPoint3* point);
    struct TargetInterface** FUN_006815c0();
    TargetInterface* FUN_00726070();
};
typedef bool(__thiscall* TargetAvailable)(TargetInterface*);
typedef int(__thiscall* TargetActive)(TargetInterface*);
typedef bool(__thiscall* TargetDisabled)(TargetInterface*, int);
struct RangeManager
{
    struct TimeObject* FUN_00825c00();
    int FUN_00404420();
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    int FUN_00404390();
    int FUN_004044d0();
};
struct TimeObject
{
    bool IsFlagSet_00403e60(unsigned int flags);
    float FUN_00639b20();
};
struct ListHandle
{
    void* TESObjectCELL_GetbhkWorld();
};
struct Master
{
    int reserved;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    void MagicCaster_DoExplosion(NiPoint3 center, ListHandle* item, void* filter, RangeManager* source, TargetInterface* first,
                      float scale, float strength);
    TargetInterface* FUN_00815410();
    bool CheckHealthDamageKill(int* origin, void* filter);
    void MagicCaster_ExplodeRigidBody(TargetInterface* selected, NiPoint3 location, RangeManager* source, float attenuation);
    void ApplyExplosion(TargetInterface* selected, NiPoint3 location, RangeManager* source, float attenuation);
};
extern TargetInterface* DAT_011dea3c;
extern Setting originalRuntimeFloatSetting1112;
extern const double DAT_01012060;
extern const double DAT_01011588;
extern void* __stdcall bhkCollisionFilter_GetNewSystemGroup(int which);
struct FormRef;
struct MediaSelector
{
    int field00;
    FormRef* CFilter_CFilter(int type, void* context);
};
struct FormRef
{
    int Modelloader_GetReferencedThis();
};
extern int __cdecl hkpGetRigidBody(int object);
extern float __cdecl CalcEffectCost(float value, int area, int duration, int magnitude, bool special);
extern int __cdecl FUN_00ec62c0();
extern void __cdecl NI2HK(NiPoint3* destination, NiPoint3* source);
extern int* __cdecl Setting_Float_00403e20(unsigned int);
extern void* __cdecl SetComponents(float, float, float);

// @fnv 0x00817b90
// src: XBOX_PDB 0x00817b90
void Master::MagicCaster_DoExplosion(NiPoint3 center, ListHandle* item, void* filter, RangeManager* source, TargetInterface* first,
                          float scale, float strength)
{
    if (source->FUN_00825c00()->IsFlagSet_00403e60(0x20000000))
    {
        float range = (double)source->FUN_00404420() * *originalRuntimeFloatSetting1112.Setting_Float_00403e20() * strength;
        if (range > DAT_01012060)
        {
            float attenuation = CalcEffectCost(source->FUN_00825c00()->FUN_00639b20(), source->FUN_00404420(),
                                               (int)(source->FUN_004044d0() * scale),
                                               (int)(source->FUN_00404390() * scale), source->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 2);
            float size = (float)(range * DAT_01011588);
            BoundShape space;
            NI2HK((NiPoint3*)&space.low, &center.FUN_00439e90(NiPoint3(-size, -size, -size)));
            NI2HK((NiPoint3*)&space.high, &center.FUN_00439e90(NiPoint3(size, size, size)));
            MediaSelector obj;
            space.field00 = obj.CFilter_CFilter(0x29, bhkCollisionFilter_GetNewSystemGroup(0))->Modelloader_GetReferencedThis();
            PhantomShape results(&space);
            void* world = item->TESObjectCELL_GetbhkWorld();
            results.bhkWorldObject_Add(world);
            ListEntries* entries = results.FUN_00818110();
            for (int i = 0; i < entries->FUN_00726070(); ++i)
            {
                int target = hkpGetRigidBody(*entries->NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(i));
                if (target)
                {
                    MagicCaster_ExplodeRigidBody((TargetInterface*)target, center, source, attenuation);
                }
            }

            results.bhkPhantom_Remove();
            TargetInterface* node = first;
            TargetInterface* skip = FUN_00815410();
            while (node && *node->FUN_006815c0())
            {
                TargetInterface* current = *node->FUN_006815c0();
                TargetInterface* candidate = ((TargetAvailable)current->vtable[64])(current) ? current : 0;
                if (candidate)
                    if (candidate && candidate != skip && ((TargetActive)candidate->vtable[116])(candidate))
                    {
                        float distance = candidate->TESObjectREFR_GetDistanceFromPoint(&center);
                        if (distance <= range && !((TargetDisabled)candidate->vtable[139])(candidate, 0) &&
                            !candidate->GetGhost_008ace90())
                        {
                            if (CheckHealthDamageKill(candidate ? &candidate->origin94 : 0, filter))
                            {
                                ApplyExplosion(candidate, center, source, attenuation);
                            }
                        }
                    }
                node = node->FUN_00726070();
            }
            if (DAT_011dea3c && DAT_011dea3c != skip && ((TargetActive)DAT_011dea3c->vtable[116])(DAT_011dea3c))
            {
                float distance = DAT_011dea3c->TESObjectREFR_GetDistanceFromPoint(&center);
                if (distance <= range && !((TargetDisabled)DAT_011dea3c->vtable[139])(DAT_011dea3c, 0) &&
                    !DAT_011dea3c->GetGhost_008ace90())
                {
                    if (CheckHealthDamageKill(DAT_011dea3c ? &DAT_011dea3c->origin94 : 0, filter))
                    {
                        ApplyExplosion(DAT_011dea3c, center, source, attenuation);
                    }
                }
            }
        }
    }
}
