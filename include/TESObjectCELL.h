#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "ExtraDataList.h"

class Actor;
class CellPoint3;
struct Ref54;
struct Destination54;
struct MaskTexture;
struct RotationPoint;
class NiPick;
struct CellFileStub;
struct G2;
struct FileH;
struct CellFormGroupRecord;
class AObj;
class P2Obj;
class SeenData_Stub;
class GO;
class Helper62d0;
class BSExtraData;
class TESActorBase;
class BGSAcousticSpace;
class BGSLightingTemplate;
class BGSEncounterZone;
class BGSPerkEntry;
class BSPortalGraph;
class BoundNodeV;
class CellLightingTemplate;
class ExteriorCellData;
class ExtraDataList;
class FormRecordHeader;
class InteriorCellData;
class ImpactSwap;
class NiColor;
class NavMeshCollection;
class NiAVObject;
class NiNode;
class RefX;
class RefV;
class ReferenceCollectorDC;
class TESGlobal;
class TESFileGroup;
class TESObjectLAND;
class TESObjectREFR;
class TESRegionList;
class TESWaterForm;
class TESWorldSpace;
class bhkWorld;
struct FormGroupQuery;
template <class T, unsigned int N> class BSSimpleArray;

class ActorReferenceArray
{
public:
    struct ActorReferenceSetupData;
};

class TESObjectCELL : public TESForm, public TESFullName
{
public:
    unsigned char formData[0xBC];

    TESObjectCELL();
    virtual ~TESObjectCELL();
    virtual void ClearData();

    bool IsCellInterior() const;
    bool IsInterior();
    bool HasWater() const;  // 0x004518e0 (Xbox debug PDB TESObjectCELL::HasWater)
    bool IsPointInCell(const NiPoint3& point);
    bool IsActorTrespassing(Actor* actor);
    bool IsOutdoorCell();
    bool IsCellPersistent();
    int GetCellGridX();
    int GetCellGridY();
    void SetExteriorCellCoordinates(int x, int y);
    TESWorldSpace* GetParentWorldSpace();
    TESObjectLAND* GetLandscape();
    void SetLandscape(TESObjectLAND* landscape);
    NavMeshCollection* GetNavMeshArray();
    void SetNavMeshArray(NavMeshCollection* navMeshes);
    void AddReference(TESObjectREFR* reference, bool persistent);
    void AddReference(RefX* reference, bool persistent);
    void RemoveReference(TESObjectREFR* reference);
    void RemoveNonPersistentRefs();
    void AddStaticRefsToList(BSSimpleList<const char*>* list);
    void AppendCellReferences(BSSimpleArray<TESObjectREFR*, 1024>& references);
    bool GetReferencesInArea(const NiPoint3& position, float radius,
                             const NiPoint3& rotation, float angle,
                             bool (__cdecl* callback)(TESObjectREFR*, long), long context);
    void CellRefLockEnter();
    void CellRefLockLeave();
    void ClearCellReferenceList();
    void CollectCellReferences(ReferenceCollectorDC* collector);
    unsigned int CountReferencesWithFormType30();
    void Detach(bool detach);
    void SetDetachTime(unsigned int time, bool force);
    TESRegionList* GetRegionList(bool create);
    BGSAcousticSpace* GetAcousticSpace();
    BGSEncounterZone* FindEncounterZone() const;
    TESWaterForm* GetAssociatedWaterForm();
    TESForm* GetOwner();
    unsigned char GetField24();
    unsigned char GetFakeExterior();
    NiNode* __thiscall GetSelectedValue(unsigned int index);
    void ClearAudioMarkers();
    ExteriorCellData* GetExteriorData();
    InteriorCellData* GetInteriorData();
    bool HasCellExtraData();
    ExtraDataList* GetExtraDataList();
    void SetFlag40(bool value);
    void ResetCellData();
    void SetLightingTemplate(void* value);
    CellLightingTemplate* GetLightingTemplate();
    int GetCellStandValue();
    float GetInteriorLightValue();
    NiAVObject* GetCellChildAt(int index);
    NiAVObject* GetDynamicNode();
    bool IsFormTypeBelowThreshold(FormGroupQuery* group);
    bool MatchForm(void* form);
    void BuildParentGroupForm(FormRecordHeader* outGroupForm, TESFileGroup* parentGroup);

    char* TESObjectCELL_GetCellName();
    unsigned char TESDataHandler_GetSaveLoadGame();
    bool SavesBefore(FormGroupQuery* group);
    unsigned int GetGroupBlockKey();
    unsigned int GetGroupSubBlockKey();
    void TESObjectCELL_SetInterior(bool value);
    bool TESObjectCELL_GetTempPublic();
    void* PlayerCharacter_GetCurrentRegion();
    void AddActivatingRef(TESObjectREFR* reference);
    BoundNodeV* TESObjectCELL_GetMultiBoundNode(RefV* reference);
    BSPortalGraph* GetPortalGraph();
    NiNode* Get3D_00545cb0();
    void* FUN_00546c20();
    void __thiscall SetDetachTime_0();
    void GetInteriorLocalMapTexture(void* data, unsigned int flags, Helper62d0* out);
    void TESObjectCELL_TakeInteriorLocalMapPicture(void* data, unsigned int flags, GO* out);
    void __thiscall SetImageSpace_00547750(int value);
    TESWaterForm* Actor_GetRadiationLevel();
    void FillBarterContainer(Ref54* actor, Destination54* destination);
    void SaveGameTest();
    void SetGridDataByte(int x, int y, MaskTexture** cache, int index, unsigned char value);
    void ComputeCellRotationCenter(RotationPoint& center);
    void ComputeCellRotationCenter(NiPoint3& center);
    void ComputeCellRotationCenter(NiPoint3* center);
    void AddFurnitureToList(G2* list);
    bool TESDataHandler_FormGroupLoadsInGame(FileH* file, CellFormGroupRecord* record);
    void TESObjectCELL_GetCOCPlacementInfo(RotationPoint& position, RotationPoint& rotation);
    void TESObjectCELL_GetCOCPlacementInfo(CellPoint3* position, CellPoint3* rotation);
    void TESObjectCELL_GetCOCPlacementInfo(NiPoint3* position, NiPoint3* rotation);
    void TESObjectCELL_DetermineCOCPlacement(NiPoint3* position, NiPoint3* rotation);
    bool FUN_00550200(NiPoint3* position);
    bool LoadAllTempData();
    RefX* CreateLootBagAtRef(RefX* reference);
    void TESObjectCELL_FillLootBag(RefX* reference);
    void TESObjectCELL_SetHasTempData(bool active);
    bool FUN_005516c0();
    unsigned char NavMeshRender_GetDraw();
    void AdjustCoordForNorthRotation(NiPoint3& position, NiPoint3& rotation, bool interior);
    void QueueReferences(bool active);
    void RemoveObstaclesAndDoors();
    bool GetLightingTemplateInheritanceFlag(int mask);
    void RemoveAutoWaterReferenceFromReferencesCurrentWater(TESObjectREFR* reference);
    BSSimpleList<BGSPerkEntry*>* GetRefList_009604f0();

    void* GetExteriorData_005445d0();
    void* GetInteriorData_00544600();
    bool GetHideLand(unsigned int bit);
    void GetDataDirectionalColor(NiColor* color);
    unsigned int GetDataDirectionalXY();
    unsigned int GetDirectionalZ();
    void GetDataFogColor(NiColor* color);
    void RegisterReferenceInCell(TESObjectREFR* reference);
    TESGlobal* GetOwnershipGlobal();
    unsigned int GetDetachTime();
    BGSAcousticSpace* GetAcousticSpace_00547590();
    ImpactSwap* GetImpactSwap();
    NiNode* GetLightMarkerNode();
    NiNode* GetActorNode();
    void AttachSounds(bool attach);
    void SetWorldSpace(TESWorldSpace* world);
    void SetTempDataOffset_0054de80(int value);
    unsigned int GetInteriorOffset();
    bool GetHasTempData();
    void SetAltered_00552900(bool altered);
    void SetupMopp();
    void RevertBGS_00555a50(BGSLoadFormBuffer* buffer);
    void SetLightingTemplate_00558b60(BGSLightingTemplate* lightingTemplate);
    bool GetLightingTemplateInheritanceFlag(unsigned int mask);
    void RemoveAutoWaterReferenceFromReferencesCurrentWater(int mask);
    void ActivateAllSubmergedReferencesIslands();
    BSPortalGraph* GetPortalGraph_009d9f20();
    void IOManager_Pause();
    void PerformCellNodeAttach(TESObjectREFR* reference, NiNode* parent);
    bool FindInFileFast(TESFile* file);
    void UpdateNavMeshObstacles();
    void AttachOrphanedChildren();
    bool RunScripts_0054c740(bool, bool);
    void RecalcLeveledActorBases(bool);
    void LoadGame_00555740(BGSLoadFormBuffer* buffer);
    bool CheckWaterHeight(void* data, float* height);
    void UpdateCellExtraData(BSExtraData* value, bool flag);
    int GetCanopyShadowMask(int, int);
    void AddReference_0(TESObjectREFR* reference);
    void LockAndProcessPerks();
    void FUN_00541ac0();
    void TESObjectCELL_CellRefLockLeave();
    void* GetRefList_009604f0(unsigned char flag);
    void ChangeProcessLevel(unsigned char flag);
    void ForceLODFadeIn();
    bool IsActorCellOwner(Actor* actor);
    bool TESObjectCELL_GetAttached();                     // 0x00450ff0 (HighProcess::Update 0x008eeec0)
    int TESObjectCELL_GetOwnershipRank();
    bool IsOwnedBy_00546ee0(TESActorBase* actorBase);
    void InitLoadGameBGS_005559d0(BGSLoadFormBuffer* buffer);
    void Save_00541ce0();
    bool Compare_00543c50(TESForm* form);

    bool PickChildNodes(NiPick* pick, int a2, int a3, float a4, char mask);
    NiAVObject* ChildNodeAt(int index);
    bool SaveCellToFile(CellFileStub* file);
    bool SaveCellToFile(TESFile* file);
    void SaveReferences(CellFileStub* file);
    bool FUN_00460340();
    bool TestObjectAgainstRoom(AObj* p1, P2Obj* p2, int p3,
                      unsigned char* p4, unsigned char p5);
    void Prepare();
    bool IsAttached();
    void AddSpaceRef(RefX* reference);
    bool IsInteriorCell();
    void ProcessCellRefs();
    void UpdateCell();
    SeenData_Stub* FUN_00555bc0();
    unsigned short GetSaveSize_00554b90(unsigned int flags);

    static void InitializeCell();
    static unsigned int InitializeTESResources(
        ActorReferenceArray::ActorReferenceSetupData& setup, bool, bool, bool);
    static bhkWorld* GetExteriorbhkWorld();
};

