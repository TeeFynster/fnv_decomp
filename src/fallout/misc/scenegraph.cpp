#include "../../../include/BGSCameraPath.h"
#include "../../../include/BGSTerrainManager.h"
#include "../../../include/BSSceneGraph.h"
#include "../../../include/SceneGraph.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
#include "../../../include/Sky.h"
#include "../../../include/TES.h"
#include "../../../include/TESObjectCELL.h"
#include "../../../include/TESWorldSpace.h"
// fallout/misc/scenegraph.cpp: SceneGraph, StandIn (5 functions)

class NiRTTI;



// @fnv 0x00878640
const NiRTTI* SceneGraph::GetRTTI() const
{
    return &ms_kRTTI;
}

extern int DAT_01083b5c;

struct Base_00c517b0
{
    void FUN_00c517b0(char*, bool, void*);
};

struct Wrapper_00878610 : Base_00c517b0
{
    void* SceneGraph_SceneGraph(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera);
};

// @fnv 0x00878610
// src: EXE 0x00878610
void* Wrapper_00878610::SceneGraph_SceneGraph(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera)
{
    FUN_00c517b0(apSceneGraphName, abMenuSceneGraph, apCamera);
    *(int**)this = &DAT_01083b5c;
    return this;
}

struct FUN_008786b0_shell : public SceneGraph
{
    float SceneGraph_GetFarDistance();
};

extern TES* g_TES;
extern SettingT_GameSettingCollection_ g_01203120;
extern SettingT_GameSettingCollection_ g_0120312c;
extern SettingT_GameSettingCollection_ g_01203138;
extern float DAT_01083c64;
extern float DAT_010c26d8;
extern double _gModifierZero;

float __cdecl LinearInterpolate(float, float, float, float, float);

// @fnv 0x008786b0
// src: XBOX_PDB 0x008786b0
float FUN_008786b0_shell::SceneGraph_GetFarDistance()
{
    float ffar;
    if (*((bool*)this + 0xb8))
    {
        ffar = DAT_01083c64;
    }
    else if (!g_TES || !g_TES->GetHitSound() || g_TES->GetHitSound()->GetWorldTerrainManager()->FUN_00454b70())
    {
        if (g_TES && ((BGSCameraPath*)g_TES)->GetPrevPath() && g_TES->GetLogDate()->Sky_GetMode() == 1)
        {
            ffar = ((TESObjectCELL*)((BGSCameraPath*)g_TES)->GetPrevPath())->GetInteriorLightValue();
            if (ffar <= _gModifierZero || ffar > DAT_010c26d8)
            {
                ffar = DAT_010c26d8;
            }
        }
        else
        {
            ffar = DAT_010c26d8;
        }
    }
    else
    {
        float ffarMax;
        if (g_TES && ((BGSCameraPath*)g_TES)->GetPrevPath() && g_TES->GetLogDate()->Sky_GetMode() == 1)
        {
            ffarMax = ((TESObjectCELL*)((BGSCameraPath*)g_TES)->GetPrevPath())->GetInteriorLightValue();
            if (ffarMax <= _gModifierZero || ffarMax > g_0120312c.Float()->f)
            {
                ffarMax = g_0120312c.Float()->f;
            }
        }
        else
        {
            ffarMax = g_0120312c.Float()->f;
        }
        ffar = LinearInterpolate(g_01203120.Float()->f, ffarMax, 0.0f, 1.0f, g_01203138.Float()->f);
    }
    return ffar;
}

struct StandIn
{
    void __thiscall SetVtableAndProcessState_00878690();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00878690, then frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00878650
void* StandIn::DestroyIfFlagged(unsigned int flags)
{
    this->SetVtableAndProcessState_00878690();
    if (flags & 1)
        _delete(this, 0xC0);
    return this;
}

extern int DAT_01083b5c;

struct FUN_00878690_shell
{
    void SetVtableAndProcessState_00878690();
    void FUN_00c51df0();
};

// @fnv 0x00878690
// src: GUESS 0x00878690 (confidence: low)
void FUN_00878690_shell::SetVtableAndProcessState_00878690()
{
    *(int*)this = (int)&DAT_01083b5c;
    FUN_00c51df0();
}
