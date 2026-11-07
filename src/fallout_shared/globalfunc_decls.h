#include "../../include/PathingGraphNode.h"
#include "../../include/SettingT.h"
// Private declarations for fallout_shared/globalfunc_o2_nood_variant.cpp.
#ifndef FNV_GLOBALFUNC_DECLS_H
#define FNV_GLOBALFUNC_DECLS_H

#include "../../include/ActorMover.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSSysInfoSystemUtility.h"
#include "../../include/EffectSetting.h"
#include "../../include/NiBound.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiNode.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiProperty.h"
#include "../../include/NiTexture.h"
#include "../../include/NiTimeController.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/SettingT.h"
#include "../../include/TES.h"
#include "../../include/TESRecipe.h"
#include "../../include/TESTopicInfoData.h"
#include "../../include/bhkWorld.h"

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class BipedNodeNames
{
  public:
    static void InitializeMultiBounds();
};
extern NiFixedString* DAT_011c61a4;
extern NiFixedString* DAT_011c61a8;
extern NiFixedString* DAT_011c61ac;
extern NiFixedString* DAT_011c61b0;
extern NiFixedString* DAT_011c61b4;
extern NiFixedString* DAT_011c61b8;
extern NiFixedString* DAT_011c61bc;
extern NiFixedString* DAT_011c61c0;
extern NiFixedString* DAT_011c61c4;
extern NiFixedString* DAT_011c61c8;
extern NiFixedString* DAT_011c61cc;
extern NiFixedString* DAT_011c61d0;
extern NiFixedString* DAT_011c61d4;
extern NiFixedString* DAT_011c61d8;
extern NiFixedString* DAT_011c61dc;
extern NiFixedString* DAT_011c61e0;
extern NiFixedString* DAT_011c61e4;
extern NiFixedString* DAT_011c61e8;
extern NiFixedString* DAT_011c61ec;
extern NiFixedString* DAT_011c61f0;
extern NiFixedString* DAT_011c61f4;
extern NiFixedString* DAT_011c61f8;
extern NiFixedString* DAT_011c61fc;
extern NiFixedString* DAT_011c6200;
extern NiFixedString* DAT_011c6204;
extern NiFixedString* DAT_011c6208;
extern NiFixedString* DAT_011c620c;
extern NiFixedString* DAT_011c6210;
extern NiFixedString* DAT_011c6214;
extern NiFixedString* DAT_011c6218;
extern NiFixedString* DAT_011c621c;
extern NiFixedString* DAT_011c6220;
extern NiFixedString* DAT_011c6224;
extern NiFixedString* DAT_011c6228;
extern NiFixedString* DAT_011c622c;
extern NiFixedString* DAT_011c6230;
extern NiFixedString* DAT_011c6234;
extern NiFixedString* DAT_011c6238;
extern NiFixedString* DAT_011c623c;
extern NiFixedString* DAT_011c6240;
extern NiFixedString* DAT_011c6244;
extern NiFixedString* DAT_011c6248;
extern NiFixedString* DAT_011c624c;
extern NiFixedString* DAT_011c6250;
extern NiFixedString* DAT_011c6254;
extern NiFixedString* DAT_011c6258;
extern NiFixedString* DAT_011c625c;
extern NiFixedString* DAT_011c6260;
extern NiFixedString* DAT_011c6264;
extern NiFixedString* DAT_011c6268;
extern NiFixedString* DAT_011c626c;
extern NiFixedString* DAT_011c6270;
extern NiFixedString* DAT_011c6274;
extern NiFixedString* DAT_011c6278;
#include "../../include/LANGUAGE.h"
int GetIsControllerConnected_();
LANGUAGE GetConfiguredLanguage();
const char* LocateString(const char*, const char*);
template <class T> unsigned int BSStringLength(const T*);
int strcat_s(char*, unsigned int, const char*);
extern "C" int memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" unsigned int strlen(const char*);
extern const char* DAT_01189038[4];
extern const char* DAT_01188f84[5];

class NiSourceTexture;
class NiRTTI;
extern TES* g_TES;
extern NiRTTI DAT_011f444c;
bool NiObject_IsKindOf(const NiRTTI*, NiAVObject*);

class TESTopic;
template <class T> class BSSimpleList;
extern NiNode* DAT_011c6328;
extern NiControllerManager* DAT_011c6324;
extern NiRTTI DAT_011f36ac;
const NiFixedString& BSXFlags_Tag();
const NiFixedString& get_g_EditorMarker();
const NiFixedString& get_g_EditorMarker0();
const NiFixedString& get_g_EditorMarker1();
const NiFixedString& get_g_EditorMarker2();
int BSstricmp(const char*, const char*);
extern "C" int _strnicmp(const char*, const char*, unsigned int);

extern NiRTTI DAT_012024e0;
int BSSM_ShaderPropertyIsLighting(NiProperty*);
class TESObjectLIGH;

extern "C" float logf(float);
struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
    void* pUserData;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};
class NiCollisionObject;
void GetCollisionObjectByIndex(NiCollisionObject*, CollisionObjectCountContext*);
void bhkWorld_DoObjectRec(NiAVObject*, CollisionObjectCountContext*,
                  void (*)(NiCollisionObject*, CollisionObjectCountContext*));

class RecipeCraftingInfo
{
  public:
    int m_iRequiredLevel, m_iSkill, CategoryID, SubCategoryID;
};
class INISettingCollection;
extern SettingT<INISettingCollection> DAT_011d5a30;
extern bool DAT_012677a3;
#endif
