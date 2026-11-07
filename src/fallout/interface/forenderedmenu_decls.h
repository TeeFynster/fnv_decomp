// Supporting declarations for forenderedmenu_o2_variant.cpp.

#include <stddef.h>

#ifndef FNV_FORENDEREDMENU_DECLS_H
#define FNV_FORENDEREDMENU_DECLS_H

#include "../../../include/BSAudio.h"
#include "../../../include/BSShaderManager.h"
#include "../../../include/BSShaderAccumulator.h"
#include "../../../include/FOPipboyManager.h"
#include "../../../include/FORenderedMenu.h"
#include "../../../include/NiAlphaProperty.h"
#include "../../../include/NiGeometry.h"
#include "../../../include/NiNode.h"
#include "../../../include/NiObject.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NiPointLight.h"
#include "../../../include/NiProperty.h"
#include "../../../include/NiUpdateData.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/ShadowSceneNode.h"

class ShadowSceneNode;
class NiScreenElements;
class NiTexture;
class NiCamera;
class Tile;
class NiColor;

class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};

extern TimeGlobal g_timeGlobal;
extern bool g_burstSoundEnabled;
bool __cdecl RandomBoolean(float chance);

class ShadowSceneLight;
class NiLight;
ShadowSceneNode* FUN_00450b80(unsigned int);
struct NiRTTI;
extern NiRTTI DAT_011f4a98;
NiAVObject* NiDynamicCast(const NiRTTI*, NiAVObject*);
int Warning(const char*, ...);


#include "../../../include/SETTING_VALUE.h"
#include "../../../include/SettingT_GameSettingCollection_.h"
extern SettingT_GameSettingCollection_ DAT_011db44c;
extern SettingT_GameSettingCollection_ DAT_011db470;
extern SettingT_GameSettingCollection_ DAT_011db3d8;

unsigned int NiShadeProperty_GetType();
unsigned int NiMaterialProperty_GetType();
extern NiColor DAT_011f4998;
#endif
