// Unit declarations for default-object initialization.
#ifndef FNV_TESDATAHANDLER_DEFAULTS_H
#define FNV_TESDATAHANDLER_DEFAULTS_H


namespace ActorValue { void LoadActorValueDefinitions(); }
class CameraPathManager
{
  public:
    void UpdateCameraPaths();
    void InitializeCameraPaths();
};
class TESGlobalMap
{
  public:
    void SetAt(const char*, TESGlobal*);
};
namespace MagicSystem { void InitializeMagicSystem(); }
void CreateDefaultTopics();
void BGSEquipType_GenerateDefaultMenuIcons();
void RegisterEffectSetting(EffectSetting*);
template <class T> unsigned int BSStringLength(const T*);
extern BGSExplosion* DAT_011ca284;
extern TESObjectWEAP* DAT_011ca288;
extern TESEyes* DAT_011cb600;
extern TESObjectACTI* DAT_011ca27c;
extern TESObjectACTI* DAT_011ca280;
extern BGSVoiceType* DAT_011cb298;
extern BGSVoiceType* DAT_011cb29c;
extern TESWaterForm* DAT_011ca53c;
extern TESObjectSTAT* DAT_011ca26c;
extern TESBoundObject* g_pLockpickItem;
extern TESObjectSTAT* DAT_011ca220;
extern TESObjectSTAT* DAT_011ca230;
extern TESObjectSTAT* DAT_011ca234;
extern TESObjectSTAT* DAT_011ca238;
extern TESObjectSTAT* DAT_011ca23c;
extern TESObjectSTAT* DAT_011ca240;
extern TESObjectSTAT* DAT_011ca244;
extern TESObjectSTAT* DAT_011ca248;
extern TESObjectSTAT* DAT_011ca24c;
extern TESObjectSTAT* DAT_011ca224;
extern TESObjectSTAT* DAT_011ca228;
extern TESObjectSTAT* DAT_011ca22c;
extern TESObjectSTAT* DAT_011ca250;
extern TESObjectSTAT* DAT_011ca254;
extern TESObjectDOOR* DAT_011ca258;
extern TESObjectSTAT* DAT_011ca25c;
extern TESObjectSTAT* DAT_011ca260;
extern TESObjectSTAT* DAT_011ca264;
extern TESFaction* DAT_011cb550;
extern TESObjectCONT* DAT_011c3f40;
extern TESObjectWEAP* DAT_011ca278;
extern TESForm* DAT_011cb96c;
extern CameraPathManager* DAT_011ca700;
extern TESGlobalMap* DAT_011c54c8;
extern TESGlobal* DAT_011c3f3c;
#endif
