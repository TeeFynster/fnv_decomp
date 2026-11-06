// fallout_shared/tesaiform_decls.h: shared game classes and auxiliary declarations

#include "../../include/ActiveEffect.h"
#include "../../include/Actor.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BSAudio.h"
#include "../../include/PackageList.h"
#include "../../include/PatrolActorPackageData.h"
#include "../../include/TESAIForm.h"
#include "../../include/TESForm.h"
class TESPackage;
class TESActorBase;
template <class T> class BSSimpleList;
struct PackedRecordData
{
    unsigned char m_ucField00;
    unsigned char m_ucField01;
    unsigned char m_ucField02;
    unsigned char m_ucField03;
    unsigned char m_ucField04;
    unsigned char pad[3];
    unsigned int m_uiField08;
    unsigned char m_ucField0C;
    unsigned char m_ucField0D;
    unsigned char m_ucField0E;
    bool m_bField0F;
    unsigned int m_uiField10;
};
class PerkEntryConditionSet;
#include "../../include/SETTING_VALUE.h"
#include "../../include/SettingT_GameSettingCollection_.h"
class GameSettingCollection;
#include "../../include/SettingT.h"
class GlobalObject_0040e0b0
{
  public:
    char opaque[16];
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting26, originalRuntimeFloatSetting27,
    originalRuntimeFloatSetting28;
extern GlobalObject_0040e0b0 g_011c52e4, g_011c52fc;
extern float DAT_011c52a8, DAT_011c52ac, DAT_011c52b0, DAT_011c52b4, DAT_011c52b8;
extern bool DAT_011c52c0;
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};
namespace ActorValue {
enum Index;
bool IsSkill(Index);
}