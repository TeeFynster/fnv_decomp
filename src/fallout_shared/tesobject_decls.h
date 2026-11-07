#include "../../include/InterfaceManager.h"
// fallout_shared/tesobject_decls.h: the shared classes tesobject.cpp works on, plus its unit-local helper views
#ifndef FNV_TESOBJECT_DECLS_H
#define FNV_TESOBJECT_DECLS_H

#include "../../include/NiTexturingProperty.h"
#include "../../include/TESObject.h"
#include "../../include/TESBoundObject.h"
#include "../../include/TESBoundAnimObject.h"
#include "../../include/TESBoundTreeObject.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/TESFile.h"
#include "../../include/TESForm.h"
#include "../../include/TESModel.h"
#include "../../include/TESCreature.h"
#include "../../include/TESObjectDOOR.h"
#include "../../include/TESObjectLIGH.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESSound.h"
#include "../../include/TESChallenge.h"
#include "../../include/BSAudio.h"
#include "../../include/BGSAcousticSpace.h"
#include "../../include/BGSCameraPath.h"
#include "../../include/BGSDehydrationStage.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiNode.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSXFlags.h"
#include "../../include/NiExtraData.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiFixedString.h"
#include "../../include/NiUpdateData.h"
#include "../../include/SettingT_GameSettingCollection_.h"

class TESFormList;
class SpellItem;
class TESIdleForm;
class BGSPerkEntry;
class TESObjectSTAT;
class CloningProcess;

// Three shorts (ShortPoint3); 0x0050e8b0 copies one.
class TESBoundPoint
{
  public:
    short a[3];
    void SetComponents(const TESBoundPoint&);
};
const TESBoundPoint& GetActorValueShortVector();
// View of TESBoundObject's 12-byte bound data (TESBoundObject__BOUND_DATA, +0x24) with its constructor (0x0050e9c0)
// and endian swap (0x0050ed30) as members.
class TESObjectBound
{
  public:
    TESBoundPoint min, max;
    void TESBoundObject_BOUND_DATA_BOUND_DATA();
    void TESBoundObject_BOUND_DATA_SwapEndian();
};
// The skeleton/biped data the reference keeps through vftable slots 0x7A/0x7C (0x2b4 bytes).
class BipedAnim
{
  public:
    char data[0x2b4];
    BipedAnim(TESObjectREFR*, NiNode*);
    void InitBoneSlots(NiNode*);
};
// Calls 0x7A (get) and 0x7C (set, pointer argument) of TESObjectREFR's vftable.
class TESObjectREFRBipedSlots
{
  public:
    virtual void refrSlot0();
    virtual void refrSlot1();
    virtual void refrSlot2();
    virtual void refrSlot3();
    virtual void refrSlot4();
    virtual void refrSlot5();
    virtual void refrSlot6();
    virtual void refrSlot7();
    virtual void refrSlot8();
    virtual void refrSlot9();
    virtual void refrSlot10();
    virtual void refrSlot11();
    virtual void refrSlot12();
    virtual void refrSlot13();
    virtual void refrSlot14();
    virtual void refrSlot15();
    virtual void refrSlot16();
    virtual void refrSlot17();
    virtual void refrSlot18();
    virtual void refrSlot19();
    virtual void refrSlot20();
    virtual void refrSlot21();
    virtual void refrSlot22();
    virtual void refrSlot23();
    virtual void refrSlot24();
    virtual void refrSlot25();
    virtual void refrSlot26();
    virtual void refrSlot27();
    virtual void refrSlot28();
    virtual void refrSlot29();
    virtual void refrSlot30();
    virtual void refrSlot31();
    virtual void refrSlot32();
    virtual void refrSlot33();
    virtual void refrSlot34();
    virtual void refrSlot35();
    virtual void refrSlot36();
    virtual void refrSlot37();
    virtual void refrSlot38();
    virtual void refrSlot39();
    virtual void refrSlot40();
    virtual void refrSlot41();
    virtual void refrSlot42();
    virtual void refrSlot43();
    virtual void refrSlot44();
    virtual void refrSlot45();
    virtual void refrSlot46();
    virtual void refrSlot47();
    virtual void refrSlot48();
    virtual void refrSlot49();
    virtual void refrSlot50();
    virtual void refrSlot51();
    virtual void refrSlot52();
    virtual void refrSlot53();
    virtual void refrSlot54();
    virtual void refrSlot55();
    virtual void refrSlot56();
    virtual void refrSlot57();
    virtual void refrSlot58();
    virtual void refrSlot59();
    virtual void refrSlot60();
    virtual void refrSlot61();
    virtual void refrSlot62();
    virtual void refrSlot63();
    virtual void refrSlot64();
    virtual void refrSlot65();
    virtual void refrSlot66();
    virtual void refrSlot67();
    virtual void refrSlot68();
    virtual void refrSlot69();
    virtual void refrSlot70();
    virtual void refrSlot71();
    virtual void refrSlot72();
    virtual void refrSlot73();
    virtual void refrSlot74();
    virtual void refrSlot75();
    virtual void refrSlot76();
    virtual void refrSlot77();
    virtual void refrSlot78();
    virtual void refrSlot79();
    virtual void refrSlot80();
    virtual void refrSlot81();
    virtual void refrSlot82();
    virtual void refrSlot83();
    virtual void refrSlot84();
    virtual void refrSlot85();
    virtual void refrSlot86();
    virtual void refrSlot87();
    virtual void refrSlot88();
    virtual void refrSlot89();
    virtual void refrSlot90();
    virtual void refrSlot91();
    virtual void refrSlot92();
    virtual void refrSlot93();
    virtual void refrSlot94();
    virtual void refrSlot95();
    virtual void refrSlot96();
    virtual void refrSlot97();
    virtual void refrSlot98();
    virtual void refrSlot99();
    virtual void refrSlot100();
    virtual void refrSlot101();
    virtual void refrSlot102();
    virtual void refrSlot103();
    virtual void refrSlot104();
    virtual void refrSlot105();
    virtual void refrSlot106();
    virtual void refrSlot107();
    virtual void refrSlot108();
    virtual void refrSlot109();
    virtual void refrSlot110();
    virtual void refrSlot111();
    virtual void refrSlot112();
    virtual void refrSlot113();
    virtual void refrSlot114();
    virtual void refrSlot115();
    virtual void refrSlot116();
    virtual void refrSlot117();
    virtual void refrSlot118();
    virtual void refrSlot119();
    virtual void refrSlot120();
    virtual void refrSlot121();
    virtual BipedAnim* GetBipedAnim();
    virtual void refrSlot123();
    virtual void SetBipedAnim(BipedAnim*);
};
class TESFormList
{
  public:
    unsigned int m_uiObjectCount;
    TESObject* m_pFirstObject;
    TESObject* m_pSecondObject;
    void* pOwner;
    TESObject* TESObjectList_lnk_GetNext(TESObject*);
    TESObject* GetTerrainMinLevel(TESObject*);
    TESObject* AddToObjectList(TESObject* object);
    TESObject* InsertObjectAfter(TESObject* object, TESObject* after);
};

extern BSSimpleList<BGSPerkEntry*>* g_dataHandler;

int BSstricmp(const char*, const char*);
extern TESObjectDOOR* DAT_011ca258;
extern TESObjectSTAT* DAT_011ca220;
extern TESObjectSTAT* DAT_011ca250;
extern TESObjectSTAT* DAT_011ca25c;
extern TESObjectSTAT* DAT_011ca260;
extern TESObjectSTAT* DAT_011ca254;
extern TESObjectSTAT* DAT_011ca224;
extern TESObjectSTAT* DAT_011ca26c;
extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;
extern TESObjectSTAT* DAT_011ca24c;
extern TESObjectSTAT* DAT_011ca230;
extern TESObjectSTAT* DAT_011ca264;
extern TESObjectSTAT* DAT_011ca228;
extern TESObjectSTAT* DAT_011ca22c;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class SceneObjectLookup
{
  public:
    static NiAVObject* GetObjectByName(NiAVObject*, const char*);
};
class GlobalObject_00a7b610
{
};
extern GlobalObject_00a7b610 g_011dfeac;
const NiFixedString& BSXFlags_Tag();
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting35;
// 0x3c bytes (TESObjectDOOR::Create3DModel pushes 0x3c before the constructor 0x008d15d0).
class TESObjectDoorController : public NiTimeController
{
  public:
    unsigned int unk34;
    unsigned int unk38;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    TESObjectDoorController();
    void MagicShaderHitEffect_SetLifeTime(float);
};
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
class NiTexture;
class CloningProcess
{
  public:
    unsigned int a, b, c, d, e, f, g;
    CloningProcess(float);
    ~CloningProcess();
};
class NiLight;

#endif
