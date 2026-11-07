#ifndef FNV_NIPOINT3INTERPOLATOR_CREATE_H
#define FNV_NIPOINT3INTERPOLATOR_CREATE_H

class StateNode
{
  public:
    void ResetCameraState();
};
void ImageSpaceModifierInstance_Stop(ImageSpaceModifierInstanceDOF*);
#include "../../../../include/SettingT_GameSettingCollection_.h"
#include "../../../../include/OSGlobals.h"
#include "../../../../include/ShadowSceneNode.h"
extern SettingT_GameSettingCollection_ DAT_011ce424, DAT_011ce564, DAT_011ce6d8, DAT_011cf1f8;
ImageSpaceModifierInstanceDOF* ImageSpaceModifierInstanceRB_Trigger(float, float, float, float, float, NiPoint2*, float);
class VATS
{
  public:
    class LightTarget* VATS_GetVATSLight();
    void SetLight(NiPointLight*, bool);
    void SetCurrentTarget(class TESObjectREFR*);
};
class LightTarget
{
  public:
    class NiAVObject* ShadowSceneLight_GetLight();
};
class ShadowLightData* GetVATSEffect();
class ShadowLightData
{
  public:
    void FOVATSEffectManager_DisableScan();
};
class InputManager
{
  public:
    void Controls_ClearUserAction();
};
class GlobalObject_009c6a30
{
};
class TimeGlobal
{
};
extern GlobalObject_009c6a30 g_011f2250;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern OSGlobals* g_osGlobals;
ShadowSceneNode* FUN_00450b80(int);
class TemporaryEffect
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual ~TemporaryEffect();
};
extern TemporaryEffect* DAT_011f21e8;
extern TemporaryEffect* DAT_011f21ec;
extern TESObjectREFR* DAT_011f21cc;
extern PlayerCharacter* DAT_011f21f0;
extern int DAT_011f21b8, DAT_011f21c0, DAT_011f21c4, DAT_011f21c8, DAT_011f21dc;
extern bool DAT_011f21d0, DAT_011f21d2, DAT_011f21d3, DAT_011f21e4;
extern float DAT_011f21d4, DAT_011f21d8;
extern const float DAT_01016248;
void BSShaderManager_SetFullScreenMotionBlurVATS(bool);
#endif
