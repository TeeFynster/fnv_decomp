#pragma once

#include "TESForm.h"
#include "TESChildCell.h"
#include "ExtraDataList.h"
#include "PlacedObjectInfo.h"
#include "NiPoint3.h"
#include "NiPoint3.h"

class Actor;
class AnimData;
class Animation;
class BGSAcousticSpace;
class BGSEncounterZone;
class BGSLoadFormBuffer;
class Base1;
class Biped;
class BipedAnim;
class BSExtraData;
class ExtraLock;
class ExtraRadioData;
class InventoryStackRecord;
class LLD_Point3;
class LockExtraData;
class MagicCaster;
class MapMarkerData;
class Matrix;
class NiAVObject;
class NiNode;
class NiPoint3;
class ParentCellStub;
class PathingRequest;
class NiPoint3;
class Script;
class ScriptLocals;
class TeleportableReference;
class TESBoundObject;
class TESGlobal;
class TESModel;
class TESSound;
class CellDataNode;
class TESObjectCELL;
class TESObjectWEAP;
class TESTopic;
class TESWorldSpace;
class FurnitureMark;
class NiMatrix3;
class ValidBip01Names;
struct NiPoint3;

namespace ScriptAnimation {
class Idle;
struct ResultList;
}

enum OBJECT_ACTION;
enum RADIO_RANGE_TYPE;

class TESObjectREFR : public TESForm, public TESChildCell
{
public:
    TESSound* m_pSoundForm;          // +0x1C
    PlacedObjectInfo data;           // +0x20
    float m_fObjectScale;            // +0x3C
    TESObjectCELL* m_pOwningCell;    // +0x40
    ExtraDataList m_kExtraDataCollection;  // +0x44
    CellDataNode* m_pRenderData;     // +0x64

    virtual bool GetStartingPosition(NiPoint3* location, NiPoint3* angle, TESForm** space, TESForm* defaultSpace);  // 0x4E
    virtual ScriptAnimation::ResultList PlayIdle(ScriptAnimation::Idle* idle, Actor* target, int, int, int, int, bool);  // 0x4F
    virtual void vfn_140();  // 0x50
    virtual void DamageObject(float, bool);  // 0x51
    virtual bool CastShadows(void);  // 0x52
    virtual void Unk_53(void);  // 0x53
    virtual void Unk_54(void);  // 0x54
    virtual void Unk_55(void);  // 0x55
    virtual void Unk_56(void);  // 0x56
    virtual void Unk_57(void);  // 0x57
    virtual void vfn_160(InventoryStackRecord*, int, bool);  // 0x58
    virtual void vfn_164(int);  // 0x59
    virtual void vfn_168(int);  // 0x5A
    virtual const NiPoint3 vfn_16c();  // 0x5B
    virtual NiPoint3 GetEditorPosition();  // 0x5C (0x170)
    virtual void Unk_5D(void);  // 0x5D
    virtual void Unk_5E(void);  // 0x5E
    virtual TESObjectREFR* RemoveItem(TESForm* toRemove, ExtraDataList* extraList, unsigned int count, unsigned int unk3, unsigned int unk4, TESObjectREFR* destRef, unsigned int unk6, unsigned int unk7, unsigned int unk8, unsigned char unk9);  // 0x5F
    virtual void Unk_60(void);  // 0x60
    virtual void EquipItem(TESBoundObject*, int, ExtraDataList*, bool);  // 0x61
    virtual void Unk_62(void);  // 0x62
    virtual void Unk_63(void);  // 0x63
    virtual void AddItem(TESForm* item, ExtraDataList* xDataList, unsigned int Quantity);  // 0x64
    virtual void Unk_65(void);  // 0x65
    virtual MagicCaster* GetMagicCaster();  // 0x66
    virtual void Unk_67(void);  // 0x67
    virtual bool GetIsChildSize(bool checkHeight);  // 0x68
    virtual unsigned int GetActorUnk0148(void);  // 0x69
    virtual void SetActorUnk0148(unsigned int arg0);  // 0x6A
    virtual NiAVObject* vfn_1ac(bool);  // 0x6B
    virtual NiAVObject* vfn_1b0(bool);  // 0x6C
    virtual void Unk_6D(void);  // 0x6D
    virtual void Unk_6E(void);  // 0x6E
    virtual void Unk_6F(void);  // 0x6F
    virtual bool Unload3D();  // 0x70
    virtual void AnimateNiNode(void);  // 0x71
    virtual void GenerateNiNode(bool arg0);  // 0x72
    virtual void Set3D(NiNode* niNode, bool unloadArt);  // 0x73
    virtual NiNode* GetNiNode(void);  // 0x74
    virtual void Unk_75(void);  // 0x75
    virtual NiPoint3 GetMinimum();  // 0x76
    virtual NiPoint3 GetMaximum();  // 0x77
    virtual void Unk_78(void);  // 0x78
    virtual AnimData* GetAnimData(void);  // 0x79
    virtual ValidBip01Names* GetValidBip01Names(void);  // 0x7A
    virtual ValidBip01Names* CallGetValidBip01Names(void);  // 0x7B
    virtual void SetValidBip01Names(ValidBip01Names validBip01Names);  // 0x7C
    virtual NiPoint3* GetPos(void) const;  // 0x7D
    virtual void Unk_7E(unsigned int arg0);  // 0x7E
    virtual void vfn_01fc(bool);  // 0x7F
    virtual void Unk_80(unsigned int arg0);  // 0x80
    virtual void Unk_81(unsigned int arg0);  // 0x81
    virtual void Unk_82(void);  // 0x82
    virtual unsigned int Unk_83(void);  // 0x83
    virtual void Unk_84(unsigned int arg0);  // 0x84
    virtual int GetSitSleepState();  // 0x85
    virtual bool IsCharacter(void);  // 0x86
    virtual bool IsCreature();  // 0x87
    virtual bool IsExplosion() const;  // 0x88
    virtual bool IsProjectile() const;  // 0x89
    virtual void SetParentCell(TESObjectCELL*);  // 0x8A
    virtual bool HasHealth(bool);  // 0x8B
    virtual bool GetHasKnockedState();  // 0x8C
    virtual bool GetIsParalyzed();  // 0x8D
    virtual void Unk_8E(void);  // 0x8E
    virtual void Unk_8F(void);  // 0x8F

    enum
    {
        CHANGE_SCRIPT_VARIABLES = 1u << 31
    };

    int TESObjectREFR_GetLookingAtLocation(int a1);
    Base1* ZoneEntry_GetZoneEntry_0(int a);

    ScriptLocals* GetReferenceLocals();
    TESObjectCELL* GetParentCell();
    TESBoundObject* GetObjectReference();
    ExtraDataList* GetExtraData();
    void Revert(BGSLoadFormBuffer* buffer);
    const NiPoint3& GetAngleOnReference() const;
    TESWorldSpace* GetParentWorldSpace() const;
    void RelocateTo(TESWorldSpace* worldSpace, TESObjectCELL* cell, const NiPoint3& location, float angle);
    bool IsLimbMissing(int limb);
    TESObjectREFR* GetLinkedRef();
    float TESObjectREFR_GetDistanceFromReference(TESObjectREFR* ref, int a, int b);
    TESWorldSpace* GetParentWorldSpace();
    BGSEncounterZone* FindEncounterZone();
    ExtraRadioData* GetExtraRadioData();
    NiAVObject* Get3DSimple();
    void TESObjectREFR_SetTargeted(int flag);
    int GetFormEditorIDLength();
    const char* GetFullName();
    PathingRequest* GetOrFallback(Actor* actor);
    TESObjectCELL* GetTarget(void* query);
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    void SetLocationOnReference(const NiPoint3&);
    float GetLightLevelAtPoint(const NiPoint3&);
    void IsBoundItem();
    float GetScale();
    void SetScale(float);
    Biped* GetBipedComponent();
    void SetReferenceFlag(bool);
    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);
    void Disable();
    bool MobileObject_IsTalkingActivator();
    LockExtraData* GetLock();
    bool CanBeUsed(Actor*, bool);
    int IsLocked();
    void Lock();
    void Unlock();
    void TESObjectREFR_SetTargeted(bool);
    const NiPoint3* FUN_00430830();
    TESForm* GetOwner();
    bool TESObjectREFR_IsFurniture();
    void TESObjectREFR_RunScript();
    float GetDistanceToReference(TESObjectREFR*, bool, bool);
    static void SetParentCellAndWorldspace(TESObjectREFR*, TESObjectCELL*, TESWorldSpace*);
    void TESObjectREFR_SetAngleOnReferenceX(float);
    void SetFlags(unsigned int);
    void Actor_MoveActorAndFollowers(NiPoint3&, float, TESObjectCELL*, TESWorldSpace*, unsigned char, unsigned char);
    TeleportableReference* Set3DObject();
    TESBoundObject* GetObjectReference() const;
    const ExtraDataList* GetExtra() const;
    BSExtraData* GetExtraData(unsigned char type) const;
    ExtraDataList* BSFile_GetDevice();
    unsigned int GetFlags();
    MapMarkerData* GetMapMarkerData();
    void ClearReferenceState(TESBoundObject*);
    int GetReferenceType();
    LockExtraData* TESObjectREFR_AddLock();
    void TESObjectREFR_AddLockChange();
    void ResetProjectileIdleAnimation();
    TESObjectCELL* GetTarget();
    float GetHealth();
    bool GetTargeted();
    bool TESObjectREFR_IsCellLoaded();
    void RestoreAnimation(BGSLoadFormBuffer*);
    bool GetReferencePersistence();
    const LLD_Point3& GetAngle() const;
    void SetReferencePosition(NiPoint3);
    void FUN_0046a010(int);
    void PostLoad();
    void Actor_SetEditorLocationForm(TESForm*);
    static TESObjectREFR* GetReferenceFromNiAVObject( NiAVObject*);
    void SetExtraDataString(TESObjectWEAP*);
    TESModel* GetTESModel();
    const char* GetModelFilePath();
    float GetBoundingRadius();
    bool GetAction(OBJECT_ACTION);
    void PerformAction(OBJECT_ACTION);
    void CloseReference(OBJECT_ACTION);
    void TESObjectREFR_SetLastFinishedSequence(const char*);
    TESObjectREFR();
    TESObjectREFR* GetExteriorRadioReference();
    float GetRadioStationRange();
    RADIO_RANGE_TYPE GetRadioRangeType();
    bool IsReferenceActive(bool);
    static bool ApplyReferenceExtraData(NiNode*);
    int GetReferenceLockLevel();
    TESGlobal* GetLockLevelGlobal();
    unsigned int GetReferenceLevel(bool allowShift);
    bool TESObjectREFR_GetRefPersists_005653d0();
    BGSAcousticSpace* GetAcousticSpace();
    static TESObjectREFR* GetReferenceFromNiAVObject(void* p);
    bool FUN_00440da0();
    bool FUN_00440d80();
    TESBoundObject* GetBase();
    bool IsDeleted();
    float GetRadius();
    bool TESForm_GetFireOff();
    NiPoint3* TESObjectREFR_GetLinkedDoorTeleportPosition();
    bool TESObjectREFR_GetMarkerUsed(int aiMarker, bool abFlag);   // 0x00567f80 (HighProcess::ProcessActivate 0x008e9640)
    bool TESObjectREFR_GetClosestFreeMarker(const NiPoint3*, int, int, FurnitureMark*, int*, int); // 0x005686b0
    TESForm* GetBaseObject();
    bool GetIsHiddenDoor();
    bool TESObjectREFR_GetInaccessible();
    bool Activate(TESObjectREFR*, bool, TESObjectREFR*, int);
    NiMatrix3 GetRotation();
    TESObjectREFR* TESObjectREFR_GetXTarget();
    TESWorldSpace* TESObjectREFR_GetWorldSpace();
    void FUN_00484490();
    void TESObjectREFR_AddBoundObjectItem(TESForm*, ExtraDataList*, int);
    void FUN_00571b50();
    bool TESObjectREFR_WearingObject(TESBoundObject*);
    void UpdateSpells(bool);
    static TESObjectREFR* CreateReference(unsigned char, bool);
    bool IsPersistentFlagSet();
    void SetPersistentFlag(bool);
    bool MustBeVisibleDistant();
    void TESObjectREFR_SetVisibleDistant(bool);
    void EquipObject(TESBoundObject*, int, ExtraDataList*, bool, bool, bool);
    bool GetIsUnconscious();
    int IsFleeing();
    bool IsBlocking();
    bool IsMovementActive();
    bool SetReferenceHeading(NiPoint3, bool);
    void SetReferenceState(TESTopic*, bool, bool);
    void Actor_StopAttack();
    void Actor_ForceIdleAnimation();
    void InitializeReference(TESObjectREFR*, TESBoundObject*, int);
    bool HasLeveledCreatureCalced();
    bool FUN_00477ba0();
    void FUN_00693ef0(bool);
    TESBoundObject* BGSSaveFormBuffer_GetForm();
    bool TESObjectREFR_HasTemp3D();
    bool TESObjectREFR_Is3DHighPriority();
    ExtraLock* FindExtraLock();
    void RefreshReference();
    void SetLocationOnReference(NiPoint3*);
    void SetReferenceAngle(float);
    bool IsCellInterior();
    void Get3D(NiNode* niNode, bool unloadArt);
    NiPoint3* GetPos();
    void TESObjectREFR_SetObjectReference(TESBoundObject*);
    void Enable();
    void TESObjectREFR_Disable();
    InventoryStackRecord* FindEntryForObject(TESBoundObject* object, unsigned int formID);
    Script* TESObjectREFR_GetScriptPointer();
    void TESObjectREFR_InitScript();
    const NiPoint3& TESObjectREFR_GetMultiBoundHalfExtent();
    Matrix TESObjectREFR_GetOrientation();
    float TESObjectREFR_GetScale_00567400();
    void Actor_InitiateSurfacePackage();
    ParentCellStub* GetParentCellStub();
    TESObjectCELL* GetParentCell() const;
    void Unk_4E(void);
    void Unk_50(void);
    void Unk_51(void);
    void Unk_58(void);
    void Unk_59(void);
    void Unk_5A(void);
    void Unk_5B(void);
    void Unk_61(void);
    void Unk_66(void);
    void Unk_6B(void);
    void Unk_6C(void);
    void Unk_70(void);
    void Unk_76(void);
    NiPoint3 GetDimensions();
    void Unk_7F(void);
    unsigned int Unk_85(void);
    bool Unk_87(void);
    bool Unk_88(void);
    void Unk_89(void);
    void Unk_8A(void);
    bool Unk_8B(bool arg0);
    bool Unk_8C(void);
    bool Unk_8D(void);
    virtual ~TESObjectREFR();
    NiAVObject* Get3D();
    NiNode* GetNiNode_v();
    BipedAnim* GetBipedAnim();
    void SetBipedAnim(BipedAnim*);
    Animation* GetAnimation() const;
    bool IsDead(bool);
    bool IsDead(bool) const;
    bool vfn_22c(bool);
    bool vfn_22c(bool, bool);
    bool vfn_230();
    bool vfn_234();
    bool vfn_218();
    bool vfn_21c();
    NiPoint3* vfn_1f4();
    Animation* vfn_1e4();
    void SetDeleted(bool);
    NiNode* GetWeaponNode(bool);
    NiNode* GetQuiverNode(bool);
};
