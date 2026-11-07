// fallout/ai/camerashake.cpp: FileFinder, CamerashakeInterfaceView (4 functions)

#include "camerashake_decls.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/OSGlobals.h"
// Clears DAT_011dfecc, builds the CameraShake.nif path, and if it exists loads it via g_modelLoader and sets its name.
// @fnv 0x008d1820
void InitializeCameraShake()
{
    char path[260];
    DAT_011dfecc = 0;
    sprintf_s(path, 260, "%s\\Characters\\CameraShake.nif", "Meshes");
    if (FileFinder::Exist(path, 0, 0, -1))
    {
        DAT_011dfecc = g_modelLoader->LoadFile(path, 0, true, false, false, false);
        DAT_011dfecc->NiAVObject::SetName(NiFixedString(static_cast<const char*>(path)));
    }
}

struct ModelLoader_target
{
    void ModelLoader_ReleaseFile(const char*);
};
// If DAT_011dfecc is set, passes its GetName() string to g_modelLoader's FUN_0045a5e0 and clears DAT_011dfecc.
// @fnv 0x008d1920
// src: GUESS 0x008d1920 (confidence: medium)
void Object_ProcessAndClearModelPath()
{
    if (DAT_011dfecc)
    {
        ((ModelLoader_target*)g_modelLoader)->ModelLoader_ReleaseFile((const char*)DAT_011dfecc->GetName());
        DAT_011dfecc = 0;
    }
}

class SettingFloat
{
  public:
    float* Float();
};

struct Controls
{
    void Controls_Rumble(float afLeft, float afRight, int aiDuration, int aiArg3, int aiArg4, int aiArg5, int aiArg6);
};

// Exe 0x008d1960: unit-local CamerashakeInterfaceView view used by this matched implementation.
struct CamerashakeInterfaceView
{
    static bool IsSaveLoadActive();
};

NiNode* Main_GetWorldSceneGraph();
NiAVObject* __fastcall BSSceneGraph_GetCameraRoot(NiNode* apNode);

extern SettingFloat originalRuntimeFloatSetting1063;
extern SettingFloat originalRuntimeFloatSetting1065;
extern SettingFloat originalRuntimeFloatSetting1066;
extern SettingFloat originalRuntimeFloatSetting1067;
extern SettingFloat g_011d064c;
extern SettingFloat g_011d09dc;
extern SettingFloat g_011d0b3c;
extern OSGlobals* g_osGlobals;
extern float DAT_011dfed4;
extern float DAT_011dfed8;

// @fnv 0x008d1960
void UpdateDistanceFade(float afMult, const NiPoint3& arPos)
{
    if (DAT_011dfecc && afMult > 0.0)
    {
        float fdelta;
        float fFadeDelta;
        float fFadeStart;
        NiPoint3 cameraPos = BSSceneGraph_GetCameraRoot(Main_GetWorldSceneGraph())->GetTranslate_0043c490();
        fdelta = static_cast<const NiPoint3&>(cameraPos - arPos).Length();
        fFadeStart = *originalRuntimeFloatSetting1066.Float() * afMult;
        fFadeDelta = *originalRuntimeFloatSetting1067.Float() * afMult;
        if (fFadeStart < *originalRuntimeFloatSetting1065.Float())
            fFadeStart = *originalRuntimeFloatSetting1065.Float();
        if (fFadeStart + fFadeDelta > fdelta)
        {
            if (fdelta > fFadeStart)
                afMult = (1.0f - (fdelta - fFadeStart) / fFadeDelta) * afMult;
            if (afMult > 1.0)
                afMult = 1.0f;
            else if (afMult < *g_011d09dc.Float())
                afMult = *g_011d09dc.Float();
            DAT_011dfed4 = afMult;
            DAT_011dfed8 = *originalRuntimeFloatSetting1063.Float();
            if (!CamerashakeInterfaceView::IsSaveLoadActive())
            {
                Controls* pcontrols = reinterpret_cast<Controls*>(g_osGlobals->Main_GetControls());
                pcontrols->Controls_Rumble(DAT_011dfed4 * *g_011d0b3c.Float(), DAT_011dfed4 * *g_011d0b3c.Float(),
                                        (int)(DAT_011dfed8 * 1000.0 * *g_011d064c.Float()), 0, 0, 0, 0);
            }
        }
    }
}

struct MatrixView
{
    float entries[9];
    MatrixView FUN_004b45b0() const;
    MatrixView FUN_0043f8d0(const MatrixView&) const;
};
struct ControllerView
{
    float FUN_0047c860();
};
struct TimeView
{
    float FUN_0084d030();
};
extern TimeView DAT_011f6394;
extern SettingFloat g_011d08b0;
// Advances a camera shake timer, samples the camera controller matrix into output, and returns the current shake amount.
// @fnv 0x008d1b30
float UpdateCameraShake(float time, MatrixView* output)
{
    if (DAT_011dfecc && DAT_011dfed4 != 0.0 && DAT_011dfed8 != 0.0)
    {
        ControllerView* second = reinterpret_cast<ControllerView*>(DAT_011dfecc->GetControllers());
        float position = second->FUN_0047c860();
        NiUpdateData first(position, true, false);
        DAT_011dfecc->NiAVObject_Update(first);
        MatrixView controller = reinterpret_cast<MatrixView&>(DAT_011dfecc->NiAVObject_GetRotate_006a9540());
        NiUpdateData old(time, true, false);
        DAT_011dfecc->NiAVObject_Update(old);
        *output = controller.FUN_004b45b0().FUN_0043f8d0(reinterpret_cast<MatrixView&>(DAT_011dfecc->NiAVObject_GetRotate_006a9540()));
        DAT_011dfed8 -= DAT_011f6394.FUN_0084d030();
        if (DAT_011dfed8 < 0.0)
        {
            DAT_011dfed8 = 0.0f;
            DAT_011dfed4 = 0.0f;
        }
        else if (DAT_011dfed8 < *g_011d08b0.Float())
            return DAT_011dfed4 * DAT_011dfed8 / *g_011d08b0.Float();
    }
    else if (DAT_011dfed8 != 0.0 || DAT_011dfed4 != 0.0)
    {
        DAT_011dfed8 = 0.0f;
        DAT_011dfed4 = 0.0f;
    }
    return DAT_011dfed4;
}
