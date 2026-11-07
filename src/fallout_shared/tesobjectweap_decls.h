#include "../../include/SettingT.h"
#include "../../include/SETTING_VALUE.h"
// fallout_shared/tesobjectweap_decls.h: declares TESFullName, TESTexture, TESIcon, TESScriptableForm, TESHealthForm and more
#ifndef TESOBJECTWEAP_DECLS_H
#define TESOBJECTWEAP_DECLS_H

#include "layout_support.h"
class SpellItem;
class Script;
class MagicItem;
class BSFileEntry;
class TESLandTexture;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
class NiAVObject;
class QueuedFile;
#include "BaseFormComponent.h"
#include "../../include/TESForm.h"

#include "layout_support.h"
class BGSAmmoForm;
class BGSBipedModelList;
class BGSClipRoundsForm;
class BGSDestructibleObjectForm;
class BGSEquipType;
class BGSImpactDataSet;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSPreloadable;
class BGSProjectile;
class BGSRepairItemList;
class BSFileEntry;
class CollisionComponent;
class EnchantmentItem;
class ShortPoint3;
class WeaponProperties;
class WeaponCriticalData;
class WeaponVATSData;
class TESAttackDamageForm;
class TESBoundObject__BOUND_DATA;
class TESEffectShader;
class TESEnchantableForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectIMOD;
class TESFormList;
class TESObjectSTAT;
class TESObjectWEAP;
class FileEntryList;
class TESValueForm;
class TESWeightForm;
class DistantTreeTextureInfo;
enum WEAPONHITBEHAVIOR
{
    WEAPONHITBEHAVIOR_WHB_NORMAL = 0,
    WEAPONHITBEHAVIOR_WHB_DISMEMBER_ONLY = 1,
    WEAPONHITBEHAVIOR_WHB_EXPLODE_ONLY = 2,
    WEAPONHITBEHAVIOR_WHB_NO_DISMEMBER_OR_EXPLODE = 3
};
enum WEAPON_RUMBLE_PATTERN
{
    WEAPON_RUMBLE_PATTERN_RUMBLE_CONSTANT = 0,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SQUARE = 1,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_TRIANGLE = 2,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SAWTOOTH = 3,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PATTERN_COUNT = 4
};
#include "../../include/WEAPON_MOD_EFFECT.h"
#include "../../include/TESFullName.h"
#include "../../include/TESTexture.h"
#include "../../include/TESIcon.h"
#include "../../include/TESScriptableForm.h"
#include "../../include/TESHealthForm.h"
#include "../../include/TESObject.h"
#include "../../include/ShortPoint3.h"
#include "../../include/TESBoundObject__BOUND_DATA.h"
#include "../../include/TESBoundObject.h"
#include "../../include/FileEntryList.h"
#include "../../include/TESModel.h"
#include "../../include/TESModelTextureSwap.h"
#include "../../include/TESEnchantableForm.h"
#include "../../include/TESValueForm.h"
#include "../../include/TESWeightForm.h"
#include "../../include/TESAttackDamageForm.h"
#include "../../include/BGSAmmoForm.h"
#include "../../include/BGSClipRoundsForm.h"
#include "../../include/BGSDestructibleObjectForm.h"
#include "../../include/BGSRepairItemList.h"
#include "../../include/BGSEquipType.h"
#include "../../include/BGSPreloadable.h"
#include "../../include/BGSMessageIcon.h"
#include "../../include/BGSBipedModelList.h"
#include "../../include/BGSPickupPutdownSounds.h"
#include "../../include/WeaponProperties.h"
#include "../../include/WeaponCriticalData.h"
#include "../../include/WeaponVATSData.h"
#include "../../include/TESObjectWEAP.h"
class TESFileFormVersion : public TESFile
{
  public:
    unsigned short GetFormVersion();
};
class TESFileChunkData16 : public TESFile
{
  public:
    bool GetChunkData(unsigned short*);
};

#include "../../include/TESAmmo.h"
#include "../../include/BGSProjectile.h"
#include "../../include/BGSImpactDataSet.h"
#include "../../include/TESEffectShader.h"
#include "../../include/SpellItem.h"
#include "../../include/TESSound.h"
#include "../../include/TESObjectSTAT.h"
#include "../../include/TESObjectIMOD.h"
class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int, class QueuedFile*, int, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;
#include "../../include/TES.h"
class TESFormInitFlag : public TESForm
{
  public:
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int);
};
#include "../../include/BGSImpactData.h"
namespace ActorValue
{
    bool IsSkill(Index);
}
bool ActorValue_IsResistance(ActorValue__Index);
int Warning(const char*, ...);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);


class INISettingCollection;

extern SettingT<INISettingCollection> DAT_011c94d0;
#endif
