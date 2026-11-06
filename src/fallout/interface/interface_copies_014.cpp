
// Provisional build file (plan B2): exact copies of the interface recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
#include "interface_packet.h"
#include "../../../include/BSSystemUtility.h"
#include "../../../include/EffectSetting.h"

class TESWorldSpace;

// Exe 0x00a25fc0: unit-local InterfaceInterfaceView view used by this matched implementation.
class InterfaceInterfaceView
{
  public:
    static const char* GetInterfaceName();
    static float GetFirstInterfaceFloat();
    static float UpdateInterfaceState();
    static float GetThirdInterfaceFloat();
    static float GetFourthInterfaceFloat();
    static bool IsInterfaceOpen();
    static float GetInterfaceFloat();
    static Tile* GetPrimaryInterfaceTile();
    static Tile* GetSecondaryInterfaceTile();
    static NiNode* GetInterfaceNode();
    static bool IsAnyMenuOpen();

    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
    static bool IsInterfaceActive();
};

const char kMeshesFolder[] = "Meshes";

struct Twin_00a25fc0 : public InterfaceInterfaceView
{
    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
};
// @fnv 0x00a25fc0
bool Twin_00a25fc0::IsWorldSpaceEnabled(TESWorldSpace* apSpace)
{
    (void)apSpace;
    return false;
}

struct Twin_00af4390 : public InterfaceInterfaceView
{
    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
};
// @fnv 0x00af4390
bool Twin_00af4390::IsWorldSpaceEnabled(TESWorldSpace* apSpace)
{
    (void)apSpace;
    return false;
}

struct Twin_00c3c230 : public InterfaceInterfaceView
{
    static bool IsWorldSpaceEnabled(TESWorldSpace* apSpace);
};
// @fnv 0x00c3c230
bool Twin_00c3c230::IsWorldSpaceEnabled(TESWorldSpace* apSpace)
{
    (void)apSpace;
    return false;
}
