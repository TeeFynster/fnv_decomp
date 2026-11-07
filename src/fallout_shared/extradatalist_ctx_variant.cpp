
// extradatalist_ctx_variant.cpp: context variant of src/fallout_shared/extradatalist.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// Use the shared extra-data base while retaining the packet's support templates.
#include "../../include/BSExtraData.h"
#include "../../include/BaseExtraList.h"
#include "../../include/layout_support.h"
#include "ExtraContainerChanges.h"
#include "InventoryChanges.h"
#include "game_constants.h"

// These support types are already supplied by the packet's generated headers.
#pragma include_alias("NiPoint3.h", "../../include/NiPoint3.h")
#pragma include_alias("NiAVObject.h", "../../include/layout_support.h")
#pragma include_alias("MagicTarget.h", "../../include/layout_support.h")
#pragma include_alias("TESForm.h", "../../include/TESForm.h")
#pragma include_alias("BaseFormComponent.h", "../../include/BaseFormComponent.h")
#pragma include_alias("TESFullName.h", "../../include/TESFullName.h")
#pragma include_alias("TESTexture.h", "../../include/TESTexture.h")
#include "../../include/BGSPrimitive.h"
#include "../../include/ExtraAction.h"
#include "../../include/ExtraActivateRef.h"
#include "../../include/ExtraAmmo.h"
#include "../../include/ExtraAudioBuoyMarker.h"
#include "../../include/ExtraAudioMarker.h"
#include "../../include/ExtraCell3D.h"
#include "../../include/ExtraCharge.h"
#include "../../include/ExtraCollisionData.h"
#include "../../include/ExtraCount.h"
#include "../../include/ExtraDecalRefs.h"
#include "../../include/ExtraDistantData.h"
#include "../../include/ExtraEditorRefMoveData.h"
#include "../../include/ExtraEmittanceSource.h"
#include "../../include/ExtraEnableStateParent.h"
#include "../../include/ExtraEncounterZone.h"
#include "../../include/ExtraFactionChanges.h"
#include "../../include/ExtraFollower.h"
#include "../../include/ExtraFollowerSwimBreadcrumbs.h"
#include "../../include/ExtraGlobal.h"
#include "../../include/ExtraHealth.h"
#include "../../include/ExtraHealthPerc.h"
#include "../../include/ExtraLevCreaModifier.h"
#include "../../include/ExtraLeveledItem.h"
#include "../../include/ExtraLinkedRef.h"
#include "../../include/ExtraLitWaterRefs.h"
#include "../../include/ExtraLock.h"
#include "../../include/ExtraMapMarker.h"
#include "../../include/ExtraMerchantContainer.h"
#include "../../include/ExtraMultiBound.h"
#include "../../include/ExtraMultiBoundRef.h"
#include "../../include/ExtraOcclusionPlaneRefData.h"
#include "../../include/ExtraOriginalReference.h"
#include "../../include/ExtraOwnership.h"
#include "../../include/ExtraPackage.h"
#include "../../include/ExtraPackageStartLocation.h"
#include "../../include/ExtraPatrolRefData.h"
#include "../../include/ExtraPoison.h"
#include "../../include/ExtraPortal.h"
#include "../../include/ExtraPortalRefData.h"
#include "../../include/ExtraPrimitive.h"
#include "../../include/ExtraRadiation.h"
#include "../../include/ExtraRadioData.h"
#include "../../include/ExtraRadius.h"
#include "../../include/ExtraRagDollData.h"
#include "../../include/ExtraRandomTeleportMarker.h"
#include "../../include/ExtraRank.h"
#include "../../include/ExtraReferencePointer.h"
#include "../../include/ExtraReflectedRefs.h"
#include "../../include/ExtraReflectorRefs.h"
#include "../../include/ExtraRefractionProperty.h"
#include "../../include/ExtraRoom.h"
#include "../../include/ExtraRoomRefData.h"
#include "../../include/ExtraRunOncePacks.h"
#include "../../include/ExtraSayTopicInfoOnceADay.h"
#include "../../include/ExtraScale.h"
#include "../../include/ExtraScript.h"
#include "../../include/ExtraSeed.h"
#include "../../include/ExtraSpecialRenderFlags.h"
#include "../../include/ExtraTeleport.h"
#include "../../include/ExtraTimeLeft.h"
#include "../../include/ExtraTresPassPackage.h"
#include "../../include/ExtraUses.h"
#include "../../include/ExtraWaterLightRefs.h"
#include "../../include/ExtraWeaponModFlags.h"
#include "../../include/ExtraXTarget.h"
#include "../../include/TESWorldSpace.h"
#pragma include_alias("NiAVObject.h", "NiAVObject.h")
// Keep the packet's inline support templates separate from the scene graph declarations.
#include "../../include/BSMultiBoundNode.h"
#pragma include_alias("NiPoint3.h", "NiPoint3.h")
#pragma include_alias("MagicTarget.h", "MagicTarget.h")
#pragma include_alias("TESForm.h", "TESForm.h")
#pragma include_alias("BaseFormComponent.h", "BaseFormComponent.h")
#pragma include_alias("TESFullName.h", "TESFullName.h")
#pragma include_alias("TESTexture.h", "TESTexture.h")

void* memcpy(void* apDest, const void* apSrc, unsigned int auiSize);

class BGSPortal;
class BGSAcousticSpace;
class BGSEncounterZone;
class BGSMusicType;
class TESClimate;
class TESImageSpace;
class TESGlobal;
class TESFaction;
class TESWaterForm;
class Script;
class ScriptLocals;
class TESTopicInfo;
class BSMultiBoundRoom;
class BSOcclusionShape;
class BSPortal;
class CanopyShadowMaskData;
class RagDollData;
class LevCreaModifierData;
class RadioData;

int Warning(const char* format, ...);

class NiRefCounted
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiCell3DNode : public NiRefCounted
{
};
class NiCanopyTexture : public NiRefCounted
{
};
class BSRoomNode : public NiRefCounted
{
};
class BSOcclusionShapeNode : public NiRefCounted
{
};
class BSPortalNode : public NiRefCounted
{
};

// The original out-of-line byte accessor (0x004f1540) takes its object in ECX.
// Keep that call while the shared BSExtraData header has no GetType declaration.
unsigned char __fastcall GetExtraDataType(BSExtraData* apExtra);

struct LockExtraData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LockExtraData();
};

struct TeleportableReference
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    TeleportableReference();
    void Copy(TeleportableReference* apSource);
};

struct MapMarkerData
{
    int unk00, unk04, unk08, unk0C, unk10;
    MapMarkerData();
    void Copy(MapMarkerData* apSource);
};

struct MediaLocation
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    MediaLocation();
    void Copy(MediaLocation* apSource);
};

struct TwoIntegerValues
{
    int unk00, unk04;
    TwoIntegerValues();
    void Copy(TwoIntegerValues* apSource);
};

struct ImpactSwap
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C, unk030, unk034,
        unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060, unk064, unk068, unk06C,
        unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0, unk0A4,
        unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC,
        unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114,
        unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C,
        unk150, unk154, unk158;
    ImpactSwap();
    void Copy(ImpactSwap* apSource);
};

struct Point3Offset
{
    int unk00, unk04, unk08;
    Point3Offset();
    void Copy(Point3Offset* apSource);
};

struct PatrolRefData
{
    int unk00, unk04, unk08, unk0C, unk10;
    PatrolRefData();
    void Copy(PatrolRefData* apSource);
};

struct PatrolReferenceData
{
    TESObjectREFR* m_pPatrolReferences[4];
    PatrolReferenceData();
};

struct PortalRefData
{
    TESObjectREFR* pRooms[2];
};

struct RoomRefData
{
    int unk00;
    int unk04;
    BSSimpleList<TESObjectREFR*> kLinkedRooms;
    unsigned char bIsMaster;
};

struct CollisionData
{
    unsigned int GetCollisionLayer() const;
    void SetCollisionLayer(unsigned int auiLayer);
    unsigned int uiCollisionLayer;
    CollisionData();
};

struct PackageReference
{
    TESPackage* pPackage;
    unsigned char bPickResultFound;
};

struct FactionRankData
{
    TESFaction* pFaction;
    char m_ucRank;
};

struct CanopyShadowMaskData
{
    int unk00;
    int unk04;
};


class ExtraHotkey : public BSExtraData
{
  public:
    unsigned char cKey;
};
class ExtraHeadTrackTarget : public BSExtraData
{
  public:
    TESObjectREFR* pTarget;
};
class ExtraWaterType : public BSExtraData
{
  public:
    TESWaterForm* m_pWaterForm;
};
class ExtraMusicType : public BSExtraData
{
  public:
    BGSMusicType* pMusic;
};
class ExtraAcousticSpace : public BSExtraData
{
  public:
    BGSAcousticSpace* m_pPathingCell;
};
class ExtraCanopyShadowMask : public BSExtraData
{
  public:
    int iMask;
    NiPointer<NiCanopyTexture> spTexture;
    int unk14;
    int unk18;
};
class ExtraClimate : public BSExtraData
{
  public:
    TESClimate* pClimateData;
};
class ExtraImageSpace : public BSExtraData
{
  public:
    TESImageSpace* m_pImageSpace;
};
class ExtraImpactSwap : public BSExtraData
{
  public:
    ImpactSwap* pSwap;
};
class ExtraMultiBoundMarkerData : public BSExtraData
{
  public:
    Point3Offset* pData;
};
class ExtraOcclusionShape : public BSExtraData
{
  public:
    NiPointer<BSOcclusionShapeNode> pShape;
};

// The shared render-flags class has no default constructor declaration.
// Supply only the construction entry point while inheriting its checked layout.
class ConstructibleExtraSpecialRenderFlags : public ExtraSpecialRenderFlags
{
  public:
    ConstructibleExtraSpecialRenderFlags();
};

#include "../../include/ExtraDataList.h"

// @fnv 0x004103d0
// src: XBOX_PDB 0x004103d0
void ExtraDataList::AddExtraCopy(BSExtraData* apExtra)
{
    if (!apExtra || !AttachExtraData(apExtra))
        return;

    BSSimpleList<PackageReference*>* pIter = 0;
    switch (GetExtraDataType(apExtra))
    {
    case 0x4C: {
        ExtraEditorRefMoveData* pMoveData = (ExtraEditorRefMoveData*)GetExtraData(0x4C);
        if (!pMoveData)
        {
            pMoveData = new ExtraEditorRefMoveData(0);
            AddExtra(pMoveData);
        }
        ExtraEditorRefMoveData* pSource = (ExtraEditorRefMoveData*)apExtra;
        pMoveData->kOldLocation = pSource->kOldLocation;
        pMoveData->kRealLocation = pSource->kRealLocation;
        pMoveData->kRealAngle = pSource->kRealAngle;
        break;
    }
    case 0x0E:
        GetLocalData(((ExtraAction*)apExtra)->eAction);
        break;
    case 0x21:
        SetOwnership((TESForm*)((ExtraOwnership*)apExtra)->pOwner);
        break;
    case 0x22:
        SetGlobalForm(((ExtraGlobal*)apExtra)->pGlobalForm);
        break;
    case 0x23:
        SetRank(((ExtraRank*)apExtra)->m_iRank);
        break;
    case 0x24:
        SetCount(((ExtraCount*)apExtra)->iCount);
        break;
    case 0x6E: {
        ExtraAmmo* pAmmo = (ExtraAmmo*)apExtra;
        SetAmmoExtra(reinterpret_cast<TESForm*>(pAmmo->pAmmo), pAmmo->iCount);
        break;
    }
    case 0x16:
        SetEquippedState(true, false);
        break;
    case 0x4A:
        SetHotKey(((ExtraHotkey*)apExtra)->cKey);
        break;
    case 0x17:
        SetEquippedState(true, true);
        break;
    case 0x31:
        SetSeedIndex(((ExtraSeed*)apExtra)->seed);
        break;
    case 0x2F:
        SetLeveledItem(((ExtraLeveledItem*)apExtra)->iIndex);
        SetLevelItemExtraFlag(((ExtraLeveledItem*)apExtra)->m_bIsLeveledItem);
        break;
    case 0x25:
        SetHealth((((ExtraHealth*)apExtra)->fHealthPercent));
        break;
    case 0x7A:
        SetHealthPerc((((ExtraHealthPerc*)apExtra)->m_fHealthPercentage));
        break;
    case 0x26:
        SetUses(((ExtraUses*)apExtra)->m_ucUses);
        break;
    case 0x27:
        SetTimeLeft((((ExtraTimeLeft*)apExtra)->fTime));
        break;
    case 0x28:
        SetCharge((((ExtraCharge*)apExtra)->m_fCharge));
        break;
    case 0x0D:
        SetScript(((ExtraScript*)apExtra)->pScript);
        AssignScriptLocals(((ExtraScript*)apExtra)->m_pLocals);
        break;
    case 0x30:
        SetScale(((ExtraScale*)apExtra)->fScale);
        break;
    case 0x2A: {
        LockExtraData* pLock = new LockExtraData;
        memcpy(pLock, ((ExtraLock*)apExtra)->pLock, sizeof(LockExtraData));
        SetLockData(pLock);
        break;
    }
    case 0x68:
        SetRadioData((int*)((ExtraRadioData*)apExtra)->unk0C);
        break;
    case 0x2B: {
        TeleportableReference* pTeleport = new TeleportableReference;
        pTeleport->Copy(((ExtraTeleport*)apExtra)->data);
        SetTeleportData(pTeleport);
        break;
    }
    case 0x2C: {
        MapMarkerData* pTeleportMarker = new MapMarkerData;
        pTeleportMarker->Copy(((ExtraMapMarker*)apExtra)->data);
        SetMapMarkerPtr(pTeleportMarker);
        break;
    }
    case 0x90: {
        MediaLocation* pAudio = new MediaLocation;
        pAudio->Copy(((ExtraAudioMarker*)apExtra)->pAudioData);
        SetAudioMarkerPtr(pAudio);
        break;
    }
    case 0x91: {
        TwoIntegerValues* pBuoy = new TwoIntegerValues;
        pBuoy->Copy((TwoIntegerValues*)((ExtraAudioBuoyMarker*)apExtra)->unk0C);
        SetAudioBuoyMarkerPtr(pBuoy);
        break;
    }
    case 0x18: {
        TESWorldSpace* pWorld = dynamic_cast<TESWorldSpace*>((TESForm*)((ExtraPackageStartLocation*)apExtra)->loc);
        TESObjectCELL* m_pOwningCell = dynamic_cast<TESObjectCELL*>((TESForm*)((ExtraPackageStartLocation*)apExtra)->loc);
        RelocateTo(pWorld, m_pOwningCell, (NiPoint3*)((ExtraPackageStartLocation*)apExtra)->pos,
                   *(float*)&((ExtraPackageStartLocation*)apExtra)->unk1C);
        break;
    }
    case 0x14:
        SetRagDollDataFromCopy(((ExtraRagDollData*)apExtra)->m_pRagDollData);
        break;
    case 0x13:
        SetWeaponModFlags(&((ExtraDistantData*)apExtra)->kDistantData);
        break;
    case 0x1D: {
        BSSimpleList<Actor*>* pFollowerIter = ((ExtraFollower*)apExtra)->list;
        while (pFollowerIter && pFollowerIter->GetItem())
        {
            Actor* pFollower = pFollowerIter->GetItem();
            SetCombatOpponent(pFollower);
            pFollowerIter = pFollowerIter->GetNext();
        }
        break;
    }
    case 0x46:
        SetHeadTrackTargetExtra(((ExtraHeadTrackTarget*)apExtra)->pTarget);
        break;
    case 0x3F:
        SetPoison((TESForm*)((ExtraPoison*)apExtra)->poison);
        break;
    case 0x02:
        SetCell3D(((ExtraCell3D*)apExtra)->m_pController);
        break;
    case 0x03:
        SetWaterType(((ExtraWaterType*)apExtra)->m_pWaterForm);
        break;
    case 0x07:
        SetMusicType(((ExtraMusicType*)apExtra)->pMusic);
        break;
    case 0x81:
        SetAcousticSpace(((ExtraAcousticSpace*)apExtra)->m_pPathingCell);
        break;
    case 0x0A: {
        CanopyShadowMaskData* pMaskData;
        SetCanopyShadowMaskData(((ExtraCanopyShadowMask*)apExtra)->iMask, ((ExtraCanopyShadowMask*)apExtra)->spTexture,
                                &pMaskData);
        pMaskData->unk04 = ((ExtraCanopyShadowMask*)apExtra)->unk18;
        pMaskData->unk00 = ((ExtraCanopyShadowMask*)apExtra)->unk14;
        break;
    }
    case 0x08:
        SetClimate(((ExtraClimate*)apExtra)->pClimateData);
        break;
    case 0x59:
        SetImageSpace(((ExtraImageSpace*)apExtra)->m_pImageSpace);
        break;
    case 0x8C: {
        ImpactSwap* pSwap = new ImpactSwap;
        pSwap->Copy(((ExtraImpactSwap*)apExtra)->pSwap);
        SetImpactSwapData(pSwap);
        break;
    }
    case 0x1C:
        SetActivateRef(((ExtraReferencePointer*)apExtra)->ref);
        break;
    // The third package byte follows unk19 in the shared class's tail padding.
    case 0x19:
        SetPackageOverride((TESPackage*)((ExtraPackage*)apExtra)->package, ((ExtraPackage*)apExtra)->unk10,
                           (int)((ExtraPackage*)apExtra)->form14, (unsigned char)((ExtraPackage*)apExtra)->unk18,
                           (unsigned char)((ExtraPackage*)apExtra)->unk19, ((unsigned char*)&((ExtraPackage*)apExtra)->unk19)[1]);
        break;
    case 0x1A:
        SetActivePackage((TESPackage*)((ExtraTresPassPackage*)apExtra)->package);
        break;
    case 0x1B:
        pIter = (BSSimpleList<PackageReference*>*)((ExtraRunOncePacks*)apExtra)->list;
        while (pIter)
        {
            PackageReference* pRunOnce = pIter->GetItem();
            if (pRunOnce)
            {
                TESPackage* pPackage = pRunOnce->pPackage;
                unsigned char bPickResultFound = pRunOnce->bPickResultFound;
                SetPackageDoneState(pPackage, bPickResultFound);
            }
            pIter = pIter->GetNext();
        }
        break;
    case 0x20:
        SetEnableStateChildren(((ExtraOriginalReference*)apExtra)->m_pWorldReferenceInfo);
        break;
    case 0x37:
        SetEnableStateParentRef(((ExtraEnableStateParent*)apExtra)->pParent);
        SetEnableStateParentFlags(((ExtraEnableStateParent*)apExtra)->cFlags);
        break;
    case 0x3B:
        SetRandomTeleportMarker(((ExtraRandomTeleportMarker*)apExtra)->pTeleportMarker);
        break;
    case 0x51:
        SetLinkedRef(((ExtraLinkedRef*)apExtra)->m_pLinkedReference);
        break;
    case 0x53: {
        ExtraActivateRef* m_pFourthReference = (ExtraActivateRef*)GetExtraData(0x53);
        if (!m_pFourthReference)
        {
            m_pFourthReference = new ExtraActivateRef;
            AddExtra(m_pFourthReference);
        }
        m_pFourthReference->Copy(reinterpret_cast<BSExtraDataEx*>(apExtra));
        break;
    }
    case 0x57: {
        ExtraDecalRefs* pDecalRefs = (ExtraDecalRefs*)GetExtraData(0x57);
        if (!pDecalRefs)
        {
            pDecalRefs = new ExtraDecalRefs;
            AddExtra(pDecalRefs);
        }
        pDecalRefs->Copy(reinterpret_cast<BSExtraDataEx*>(apExtra));
        break;
    }
    case 0x65: {
        ExtraReflectedRefs* pReflectedRefs = (ExtraReflectedRefs*)GetExtraData(0x65);
        if (!pReflectedRefs)
        {
            pReflectedRefs = new ExtraReflectedRefs;
            AddExtra(pReflectedRefs);
        }
        pReflectedRefs->Copy(apExtra);
        break;
    }
    case 0x66: {
        ExtraReflectorRefs* pReflectorRefs = (ExtraReflectorRefs*)GetExtraData(0x66);
        if (!pReflectorRefs)
        {
            pReflectorRefs = new ExtraReflectorRefs;
            AddExtra(pReflectorRefs);
        }
        pReflectorRefs->Copy(apExtra);
        break;
    }
    case 0x85: {
        ExtraLitWaterRefs* pLitWaterRefs = (ExtraLitWaterRefs*)GetExtraData(0x85);
        if (!pLitWaterRefs)
        {
            pLitWaterRefs = new ExtraLitWaterRefs;
            AddExtra(pLitWaterRefs);
        }
        pLitWaterRefs->Copy(reinterpret_cast<BSExtraDataEx*>(apExtra));
        break;
    }
    case 0x84: {
        ExtraWaterLightRefs* pWaterLightRefs = (ExtraWaterLightRefs*)GetExtraData(0x84);
        if (!pWaterLightRefs)
        {
            pWaterLightRefs = new ExtraWaterLightRefs;
            AddExtra(pWaterLightRefs);
        }
        pWaterLightRefs->Copy(reinterpret_cast<BSExtraDataEx*>(apExtra));
        break;
    }
    case 0x3C:
        SetMerchantContainer(((ExtraMerchantContainer*)apExtra)->pContainer);
        break;
    case 0x44:
        SetXTarget(((ExtraXTarget*)apExtra)->pTarget);
        break;
    // These shared classes reserve the payload as alignment padding after BSExtraData.
    case 0x74:
        SetEncounterZone(*(BGSEncounterZone**)((char*)(ExtraEncounterZone*)apExtra + sizeof(BSExtraData)));
        break;
    case 0x67:
        SetEmittanceSource(((ExtraEmittanceSource*)apExtra)->pSource);
        break;
    case 0x63:
        SetMultiBoundRef(((ExtraMultiBoundRef*)apExtra)->m_pReference);
        break;
    case 0x62: {
        Point3Offset* pNewData = 0;
        Point3Offset* pSrcData = ((ExtraMultiBoundMarkerData*)apExtra)->pData;
        if (pSrcData)
        {
            pNewData = new Point3Offset;
            pNewData->Copy(pSrcData);
        }
        SetExtraRecord(pNewData);
        break;
    }
    case 0x1E:
        SetLevCreaModifier(((ExtraLevCreaModifier*)apExtra)->m_iModifier);
        break;
    case 0x48:
        SetRefractionAmount(true, ((ExtraRefractionProperty*)apExtra)->fRefraction);
        break;
    case 0x3E:
        SetCannotWear(true);
        break;
    case 0x55:
        break;
    case 0x5C:
        SetRadius(((ExtraRadius*)apExtra)->fRadius);
        break;
    // ExtraRadiation likewise stores its float in the shared class's tail padding.
    case 0x5D:
        SetRadiation(*(float*)((char*)(ExtraRadiation*)apExtra + sizeof(BSExtraData)));
        break;
    case 0x5E: {
        UpdateExtraDataListExtension();
        ExtraFactionChanges* pChanges = GetFactionChangesExtra();
        BSSimpleList<FactionRankData*>* pRankIter = (BSSimpleList<FactionRankData*>*)((ExtraFactionChanges*)apExtra)->m_pFactionChanges;
        while (pRankIter && pRankIter->GetItem())
        {
            FactionRankData* pRank = pRankIter->GetItem();
            if (pRank)
                pChanges->AddToFaction(pRank->pFaction, pRank->m_ucRank);
            pRankIter = pRankIter->GetNext();
        }
        break;
    }
    case 0x5A:
        SetPortalRefData(apExtra);
        break;
    case 0x6B: {
        BGSPrimitive* pSrcPrimitive = ((ExtraPrimitive*)apExtra)->m_pPrimitive;
        BGSPrimitive* pNewPrimitive = BGSPrimitive::Copy(pSrcPrimitive);
        AddPrimitive(pNewPrimitive);
        break;
    }
    case 0x61:
        SetMultiBound(((ExtraMultiBound*)apExtra)->m_kMultiBoundNode);
        break;
    case 0x79:
        SetRoomNode(((ExtraRoom*)apExtra)->m_pRoomNode);
        break;
    case 0x6F: {
        PatrolRefData* pPatrol = new PatrolRefData;
        pPatrol->Copy(((ExtraPatrolRefData*)apExtra)->pData);
        SetPatrolRefData(pPatrol);
        break;
    }
    case 0x71:
        SetOcclusionShape(((ExtraOcclusionShape*)apExtra)->pShape);
        break;
    case 0x76: {
        PatrolReferenceData* pPlaneData = new PatrolReferenceData;
        ExtraOcclusionPlaneRefData* pOcclusionExtra = (ExtraOcclusionPlaneRefData*)apExtra;
        PatrolReferenceData* pSrcLinkedRefs = pOcclusionExtra->pData;
        for (int i = 0; i < 4; i++)
            pPlaneData->m_pPatrolReferences[i] = pSrcLinkedRefs->m_pPatrolReferences[i];
        SetRoomRefData(pPlaneData);
        break;
    }
    case 0x77: {
        ExtraPortalRefData* pPortalRefExtra = (ExtraPortalRefData*)apExtra;
        PortalRefData* pPortalRefData = (PortalRefData*)pPortalRefExtra->pData;
        for (int j = 0; j < 2; j++)
            SetRoomLinkedRoomRef(j, pPortalRefData->pRooms[j]);
        break;
    }
    case 0x7B: {
        ExtraRoomRefData* pRefExtra = (ExtraRoomRefData*)apExtra;
        RoomRefData* pRoomRefData = pRefExtra->pData;
        BSSimpleList<TESObjectREFR*>* pRoomLinkIter = &pRoomRefData->kLinkedRooms;
        while (pRoomLinkIter && pRoomLinkIter->GetItem())
        {
            AddRoomLinkedRoomRef(pRoomLinkIter->GetItem());
            pRoomLinkIter = pRoomLinkIter->GetNext();
        }
        SetRoomIsMaster(pRoomRefData->bIsMaster != 0);
        break;
    }
    case 0x72: {
        CollisionData* pCollision = new CollisionData;
        pCollision->SetCollisionLayer(((ExtraCollisionData*)apExtra)->m_pCollisionData->GetCollisionLayer());
        SetCollisionData(pCollision);
        break;
    }
    case 0x73: {
        BSSimpleList<TESTopicInfo*>* pInfoIter = (BSSimpleList<TESTopicInfo*>*)((ExtraSayTopicInfoOnceADay*)apExtra)->pList;
        while (pInfoIter && pInfoIter->GetItem())
        {
            SetExtraSayTopicInfoOnceADayExtra(pInfoIter->GetItem());
            pInfoIter->GetNext();
        }
        break;
    }
    case 0x78: {
        BSPortalNode* pPortalNode = apExtra ? ((ExtraPortal*)apExtra)->m_pPortalNode : NiPointer<BSPortalNode>(0);
        SetPortalNode(pPortalNode);
        break;
    }
    case 0x80:
        SetIgnoredBySandbox(true);
        break;
    case 0x8B: {
        ExtraFollowerSwimBreadcrumbs* pDstBreadcrumbs = GetFollowerSwimBreadcrumbsExtra();
        ExtraFollowerSwimBreadcrumbs* pSrcBreadcrumbs = (ExtraFollowerSwimBreadcrumbs*)apExtra;
        pDstBreadcrumbs->kLastPos = pSrcBreadcrumbs->kLastPos;
        pDstBreadcrumbs->iLastCell = pSrcBreadcrumbs->iLastCell;
        pDstBreadcrumbs->iCount = pSrcBreadcrumbs->iCount;
        pDstBreadcrumbs->kBreadcrumbs.RemoveAll();
        for (BSSimpleList<FollowerSwimBreadcrumb*>* pCrumbIter = &pSrcBreadcrumbs->kBreadcrumbs; pCrumbIter;
             pCrumbIter = pCrumbIter->GetNext())
        {
            if (pCrumbIter->GetItem())
                pDstBreadcrumbs->kBreadcrumbs.AddTail(pCrumbIter->GetItem());
        }
        break;
    }
    case 0x8D:
        if (((ExtraWeaponModFlags*)apExtra)->IsModActive(1))
            RemoveExtraByType(1);
        if (((ExtraWeaponModFlags*)apExtra)->IsModActive(2))
            RemoveExtraByType(2);
        if (((ExtraWeaponModFlags*)apExtra)->IsModActive(4))
            RemoveExtraByType(4);
        break;
    case 0x92: {
        ExtraSpecialRenderFlags* pRenderFlags = (ExtraSpecialRenderFlags*)GetExtraData(0x92);
        if (!pRenderFlags)
        {
            pRenderFlags = new ConstructibleExtraSpecialRenderFlags;
            AddExtra((BSExtraData*)pRenderFlags);
        }
        pRenderFlags->Copy_00438330(apExtra);
        break;
    }
    default:
        Warning("AI: No Copy function available for Extra Data type %i.", GetExtraDataType(apExtra));
        break;
    }
}
