
// src/fallout/interface/fopipboymanager_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x007f8720: the skeleton of src/fallout/interface/fopipboymanager.cpp
// with declarations corrected to what the original code does (fopipboymanager_decls.h: FOPipboyManager += bool FUN_007f8720(bool press, bool release, float& x, float& y, int& button); NiAVObject* FUN_007fa950();; fopipboymanager_decls.h: class NiPoint3 { public: float x,y,z; NiPoint3(flo -> class NiPoint3 { public: float x,y,z; NiPoint3(flo; fopipboymanager_de). Move the function to its real unit once
// that unit declares it this way.

#include "../../../include/FOPipboyManager.h"
#include "../../../include/NiCamera.h"
#include "../../../include/NiPick.h"
#include "../../../include/NiPoint2.h"
#include "../../../include/SceneGraph.h"

// Exe 0x007f8720: unit-local FopipboymanagerInterfaceView view used by this matched implementation.
class FopipboymanagerInterfaceView
{
  public:
    float TESCombatStyle_GetWeaponMinRangeMult();
    float QueuedModel_GetOverriddenVisualDistance();  // declared for the original code (decl_variants.py)
  public:
    unsigned char interfaceState[0x174];
    FOPipboyManager* pPipboyManager;
    FOPipboyManager* GetPipboyManager();
    static FopipboymanagerInterfaceView* InterfaceManager_GetSingleton();
    NiNode* GetRoot();
};

// Preserve the original out-of-line point construction; the shared NiPoint3
// default constructor is force-inlined. This adds no storage to the ray points.
class PipboyRayPoint : public NiPoint3
{
  public:
    PipboyRayPoint();
};

// The Pip-Boy uses the legacy camera accessor at 0x006629f0, which
// differs from the GetCamera entry point declared by the shared header.
class PipboySceneGraph : public SceneGraph
{
  public:
    NiCamera* FUN_006629f0();
};

SceneGraph* Main_GetWorldSceneGraph();
bool InterfaceManager_IsInPipboyMenu();
bool FUN_00717920();
double InterfaceManager_GetRealScreenHeight();
extern int DAT_011a0ba0;
// @fnv 0x007f8720
// src: COMMUNITY 0x007f8720
bool FOPipboyManager::CheckOrangeButtonsClicked(bool press, bool release, float& x, float& y, int& button)
{
    bool result = false;
    FopipboymanagerInterfaceView* ui = FopipboymanagerInterfaceView::InterfaceManager_GetSingleton();
    if (!SkyObject_GetNiNode() || !(NiAVObject*)m_cPipBoyButtonAvailability[0] ||
        !(NiAVObject*)m_cPipBoyButtonAvailability[1] || !(NiAVObject*)m_cPipBoyButtonAvailability[2])
        return false;
    if (InterfaceManager_IsInPipboyMenu() && FUN_00717920() && (NiNode*)m_pPipBoyObject0)
    {
        PipboyRayPoint origin;
        PipboyRayPoint c;
        NiPick b(0, 8);
        b.SetByteAtOffset17(true);
        b.SetTarget_00705fc0(SkyObject_GetNiNode());
        b.FUN_006ecd40(0);
        b.SetByteAtOffset30(true);
        NiCamera* a = static_cast<PipboySceneGraph*>(Main_GetWorldSceneGraph())->FUN_006629f0();
        a->MapScreenToRay((int)ui->TESCombatStyle_GetWeaponMinRangeMult(), (int)ui->QueuedModel_GetOverriddenVisualDistance(), origin, c, false);
        if (b.FUN_00e98e20(origin, c, false))
        {
            unsigned int firstIndex = 0;
            NiPick::Record* hit = b.FUN_00500940()->ProcessArray_GetItem(firstIndex);
            if (hit && hit->AnimatingText_GetFullText() == SkyObject_GetNiNode())
            {
                NiPoint2 horizontal = *hit->FUN_00891170();
                float scale = InterfaceManager_GetRealScreenHeight();
                float uv = scale * (double)1.333333f;
                x = horizontal.x * uv;
                y = horizontal.y * scale;
                result = true;
            }
        }
        if (press || release)
        {
            int selected = -1;
            b.FUN_006ecd40(0);
            b.SetByteAtOffset30(false);
            for (int i = 0; i < 3; i++)
            {
                b.SetTarget_00705fc0(m_cPipBoyButtonAvailability[i]);
                static_cast<PipboySceneGraph*>(Main_GetWorldSceneGraph())->FUN_006629f0()->MapScreenToRay((int)ui->TESCombatStyle_GetWeaponMinRangeMult(), (int)ui->QueuedModel_GetOverriddenVisualDistance(), origin,
                                                               c, false);
                if (b.FUN_00e98e20(origin, c, false))
                {
                    unsigned int hit = 0;
                    NiPick::Record* hitIndex = b.FUN_00500940()->ProcessArray_GetItem(hit);
                    if (hitIndex)
                    {
                        if (press)
                            DAT_011a0ba0 = i;
                        else
                            selected = i;
                    }
                }
            }
            if (release && selected == DAT_011a0ba0)
            {
                button = selected + 1;
                DAT_011a0ba0 = -1;
            }
        }
    }
    return result;
}
