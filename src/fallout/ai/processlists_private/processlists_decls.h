// Unit-private declarations for the new processlists.cpp matches.
// Placeholders live here so they can be renamed later in one place.
#ifndef FNV_PROCESSLISTS_PRIVATE_DECLS_H
#define FNV_PROCESSLISTS_PRIVATE_DECLS_H
#include "../../../../include/SETTING_VALUE.h"

// Placeholder carrier for canonical binding ?IsUnk28Set@FOPipboyManager@@QAE_NXZ.

// Exe 0x00408d60: shared Setting::Bool reads value at +4 and preserves its null fallback.

class INISettingCollection;

#include "../../../../include/SettingT.h"

// Placeholder globals.
extern int DAT_01202800;
extern MobileObject* DAT_011e0e38;

// 0x00c68f00 canonical binding: ?SetWorldActive@bhkWorld@@QAEX_N@Z
void ProcessPendingItems();

extern float DAT_011e0e2c;
extern double DAT_0108c160;
extern "C" int FNV_IsNaN(double);
extern "C" int FNV_Finite(double);
// No checked include/Crime.h exists yet; keep its method declarations together.
class Crime
{
  public:
    void Crime_InitLoadGame(BGSLoadGameBuffer*);
    TESObjectREFR* GetTarget();
};
int MinInt(int, int);
// 0x00975cf0 resets global state; it does not use a NiTMap instance.
void BSTempEffect_RemoveAllDecals();
namespace bsrandom_singleton {
class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
};
}
void BGSDecalNode_RemoveAllDecals();
void BGSDecalManager_RemoveAllDecals();
class MagicShaderHitEffect;
class NiAVObject;
class GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_011dc804;
bool NiObject_IsKindOf(const NiRTTI*, NiAVObject*);
#endif
