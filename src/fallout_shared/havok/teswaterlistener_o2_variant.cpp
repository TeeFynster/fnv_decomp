
// src/fallout_shared/havok/teswaterlistener_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/havok/teswaterlistener.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/fallout_shared/havok/teswaterlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/teswaterlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../include/BSOcclusionPlane.h"
#include "../../../include/BSThread.h"
#include "../../../include/ExtraDataList.h"
#include "../../../include/TESDataHandler.h"

struct FUN_0062e750_shell
{
    void* __thiscall FUN_0062e750(unsigned int flags);
    void __thiscall FUN_0062e860();
};
void __cdecl _Deallocate(void* p);
extern int DAT_011c7a3c;
void TESWaterSystem_SetCurrentWaterType(int value);
extern unsigned char DAT_011c7a5a;
void TESWaterSystem_SetCameraInPlaceableWater(unsigned char value);
extern float _DAT_011c7a5c;
void TESWaterSystem_SetCameraRelevantWaterHeight(float value);
unsigned int __cdecl GetOcclusionPlaneThreadID(BSOcclusionPlane* pPlane);
extern "C" float __cdecl ExpFloat(float);
float exp_00630aa0(float value);
extern "C" double __cdecl _exp(double);
float ExpFloat(float value);
extern float _gModifierZero;
float __cdecl SignOfFloat(float a);
struct FUN_005631e0_shell
{
    int __thiscall MaskWithField(int a);
    bool __thiscall IsNonZero(int a);
};
float __cdecl NI2HK_004a3e90(float);
struct FUN_0062e710_shell
{
    void __thiscall SetValueAt(float f, int a, int b);
};
struct BSSimpleList_Ragdoll
{
    void* __thiscall hkpMotion_getCenterOfMassInWorld();
};
struct FUN_006310c0_shell
{
    void __thiscall hkpRigidBody_getCenterOfMassInWorld();
};

struct FUN_00c9a460_shell
{
    void __thiscall AddObject(int a);
    void __thiscall bhkEntityListener_entityAddedCallback(int a);
};

// @fnv 0x00c9a600
// src: XBOX_PDB 0x00c9a600
void __thiscall FUN_00c9a460_shell::bhkEntityListener_entityAddedCallback(int a)
{
    int r = ((int(__thiscall*)(void*, int))(*reinterpret_cast<void***>(this))[9])(this, a);
    AddObject(r);
}
