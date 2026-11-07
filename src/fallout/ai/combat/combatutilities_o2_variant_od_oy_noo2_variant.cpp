#include "../../../../include/bhkFilter.h"
#include "../../../../include/BGSProjectile.h"
#include "../../../../include/GameSettingCollection.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/PathingRequest.h"
#include "../../../../include/SETTING_VALUE.h"

// src/fallout/ai/combat/combatutilities_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout/ai/combat/combatutilities_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/combatutilities_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/combatutilities.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/combatutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" float __cdecl NiCos(float);
float __cdecl CombatUtilities_ComputeProjectileTime(float a, float b, float c);
extern int DAT_011a558c;
char RotateSlot(char a1, char a2);
extern "C" double DAT_0103c348;
extern "C" int DAT_011a558c;
float ScaleCharToFloat(char arg);
struct FUN_009a9f00_shell
{
    void __thiscall SetFieldE0(float value);
};
extern "C" double _DAT_0103c348;
long __cdecl ScaleByRatio(float a);

// FUN_009a6e90 - trajectory raycast stepper, worker5 v1 one-pass transcription

struct FUN_00931ed0_shell
{
    bhkFilter* __thiscall FUN_00931ed0(void* p);
};
struct FUN_00553ee0_shell
{
    int __thiscall TESObjectCELL_Pick();
};
struct FUN_004a39f0_shell
{
    void __thiscall CFilter_SetLayer(int a);
};
struct FUN_0059ce80_shell
{
    void __thiscall CFilter_SetGroup(unsigned int a);
};
struct GlobalObject_008c71b0
{
    int m_val;
    GlobalObject_008c71b0(int a);
};
struct LockObj
{
    int __thiscall FUN_00483710();
};
struct hkpAllRayHitCollector;
struct FUN_004a3f70_shell
{
    void __thiscall bhkPickData_SetFilter(int value);
};
struct FUN_004a3fb0_shell
{
    void __thiscall bhkPickData_SetAllCollector(hkpAllRayHitCollector* p);
};
struct FUN_004a3da0_shell
{
    void __thiscall bhkPickData_SetFrom(void* p);
};
struct FUN_004a3eb0_shell
{
    void __thiscall bhkPickData_SetTo(void* p);
};

class FUN_004a3a70
{
  public:
    FUN_004a3a70();
    virtual ~FUN_004a3a70();
    union HitVec
    {
        float components[4];
        char bytes[16];
    };
    HitVec m_kHits[50];
    int m_tail0;
};
struct __declspec(align(16)) FUN_004a3c20_shell
{
    FUN_004a3c20_shell();
    float m_v[44];
};

extern LockObj DAT_011f1c7c;
extern GameSettingCollection DAT_011f1c4c;
extern GameSettingCollection DAT_011cfd7c;
extern int DAT_011dea24;
extern int DAT_011dea3c;
extern float DAT_011f1c00;
extern const double DAT_01011590;
extern "C" double gModifierZero;

float __cdecl NiASin_004b54c0(float a);
float __cdecl sin_004e44b0(float a);
float __cdecl tan_0057dd70(float a);
float cos(float a);
float __cdecl FUN_004b1550(NiPoint3* p);
int __cdecl TESObjectREFR_FindReferenceFor3D(int a);
int __cdecl Projectile_ProcessTargetPick(void* input, int a1, void* a2, float* frac, int a4, float maxFrac);

void __cdecl DrawDebugLine(NiPoint3* from, NiPoint3* to, int hit, float frac, int a4, int a5);

// @fnv 0x009a6e90
// src: XBOX_PDB 0x009a6e90
bool __cdecl CombatUtilities_CalculateProjectileLOS(void* a0, void* a1, float a2, float s0, float s1, float s2, float e0, float e1, float e2,
                          NiPoint3* outPt, int* outInt, float* outFrac)
{
    DAT_011f1c7c.FUN_00483710();
    GlobalObject_008c71b0 obj18(0);
    ((FUN_004a39f0_shell*)&obj18)->CFilter_SetLayer(6);
    int tmp1c;
    ((FUN_0059ce80_shell*)&obj18)
        ->CFilter_SetGroup((unsigned int)((FUN_00931ed0_shell*)a0)->FUN_00931ed0(&tmp1c)->CFilter_GetGroup());

    double d28;
    if (a1)
    {
        d28 = (double)(((BGSProjectile*)a1)->GetGravity_00966980() * DAT_011f1c00);
    }
    else
    {
        d28 = 0.0;
    }
    float v2c = (float)d28;
    int v30 = 0;
    int v34 = 0;

    FUN_004a3a70 obj360;
    FUN_004a3c20_shell obj410;
    ((FUN_004a3f70_shell*)&obj410)->bhkPickData_SetFilter(obj18.m_val);
    ((FUN_004a3fb0_shell*)&obj410)->bhkPickData_SetAllCollector((hkpAllRayHitCollector*)&obj360);

    NiPoint3 vecStart = *(NiPoint3*)&s0;
    NiPoint3 pos = *(NiPoint3*)&e0;
    float frac = 0.0f;
    unsigned int v430 = 1;
    unsigned int cnt = 1;

    if (v2c == gModifierZero)
    {
        ((FUN_004a3da0_shell*)&obj410)->bhkPickData_SetFrom(&vecStart);
        ((FUN_004a3eb0_shell*)&obj410)->bhkPickData_SetTo(&pos);
        v30 = ((FUN_00553ee0_shell*)((TESObjectREFR*)a0)->GetTarget(&obj410))->TESObjectCELL_Pick();
        v34 = Projectile_ProcessTargetPick(&obj410, 0, a1, &frac, 0, 3.4028234663852886e38f);
        if (*(unsigned char*)DAT_011f1c4c.Bool() &&
            (DAT_011dea24 == 0 || DAT_011dea24 == DAT_011dea3c || DAT_011dea24 == (int)a0))
        {
            DrawDebugLine(&vecStart, &pos, v34, frac, 0, 0);
        }
    }
    else
    {
        NiPoint3 diff = ((const NiPoint3*)&e0)->operator-(*(NiPoint3*)&s0);
        float v448 = NiASin_004b54c0(diff.z / ((const NiPoint3*)&diff)->Length());
        diff.z = 0.0f;
        float v44c = ((const NiPoint3*)&diff)->Length();
        float v450 = FUN_004b1550(&diff);
        float v454 = a2;
        if (v454 == gModifierZero)
        {
            v454 = ((const PathingRequest*)a1)->GetFloatAtOffset68();
        }
        cnt = (unsigned int)*(int*)&DAT_011cfd7c.Int()->f;
        float v464 = v44c / cnt;
        float v468 = sin_004e44b0(v450) * v464;
        float v46c = cos(v450) * v464;
        float v470 = tan_0057dd70(v448);
        float v474 = cos(v448);
        unsigned int i;
        for (i = 0; i < cnt; i++)
        {
            v430 = i + 1;
            pos = *(NiPoint3*)&s0;
            float t = (float)(v430 * v464);
            float v488 = t * v470 - v2c * t * t / (v454 * v454 * v474 * v474 * DAT_01011590);
            pos.x += v430 * v468;
            pos.y += v430 * v46c;
            pos.z += v488;
            ((FUN_004a3da0_shell*)&obj410)->bhkPickData_SetFrom(&vecStart);
            ((FUN_004a3eb0_shell*)&obj410)->bhkPickData_SetTo(&pos);
            v30 = ((FUN_00553ee0_shell*)((TESObjectREFR*)a0)->GetTarget(&obj410))->TESObjectCELL_Pick();
            v34 = Projectile_ProcessTargetPick(&obj410, 0, a1, &frac, 0, 3.4028234663852886e38f);
            if (*(unsigned char*)DAT_011f1c4c.Bool() &&
                (DAT_011dea24 == 0 || DAT_011dea24 == DAT_011dea3c || DAT_011dea24 == (int)a0))
            {
                DrawDebugLine(&vecStart, &pos, v34, frac, 0, 0);
            }
            if (v34)
                break;
            vecStart = pos;
        }
    }

    if (v34)
    {
        if (outInt)
        {
            *outInt = TESObjectREFR_FindReferenceFor3D(v34);
        }
        if (outPt)
        {
            *outPt = ((const NiPoint3*)&((const NiPoint3*)&((const NiPoint3*)&pos)->operator-(vecStart))->operator*(frac))
                         ->operator+(vecStart);
        }
        if (outFrac)
        {
            if (cnt == 1)
            {
                *outFrac = frac;
            }
            else
            {
                *outFrac = frac / cnt + (v430 - 1) / (float)cnt;
            }
        }
        DAT_011f1c7c.FUN_00483710();
        return true;
    }
    DAT_011f1c7c.FUN_00483710();
    return false;
}
