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
    bool FUN_00546da0(Actor* actor);
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

    char* FUN_00451cb0();
    unsigned char FUN_00542d20();
    bool FUN_005434d0(FormGroupQuery* group);
    unsigned int FUN_005441b0();
    unsigned int FUN_00544210();
    void FUN_00544300(bool value);
    bool FUN_00544420();
    void* FUN_005454d0();
    void FUN_005455c0(TESObjectREFR* reference);
    BoundNodeV* FUN_00545960(RefV* reference);
    BSPortalGraph* GetPortalGraph();
    NiNode* FUN_00545cb0();
    void* FUN_00546c20();
    void __thiscall FUN_00546c70();
    void FUN_0054e750(void* data, unsigned int flags, Helper62d0* out);
    void FUN_0054f500(void* data, unsigned int flags, GO* out);
    void __thiscall FUN_00547750(int value);
    TESWaterForm* FUN_00547770();
    void FUN_0054b260(Ref54* actor, Destination54* destination);
    void FUN_0054b5b0();
    void SetGridDataByte(int x, int y, MaskTexture** cache, int index, unsigned char value);
    void ComputeCellRotationCenter(RotationPoint& center);
    void ComputeCellRotationCenter(NiPoint3& center);
    void ComputeCellRotationCenter(NiPoint3* center);
    void FUN_0054ca00(G2* list);
    bool FUN_004695a0(FileH* file, CellFormGroupRecord* record);
    void FUN_0054cfd0(RotationPoint& position, RotationPoint& rotation);
    void FUN_0054cfd0(CellPoint3* position, CellPoint3* rotation);
    void FUN_0054cfd0(NiPoint3* position, NiPoint3* rotation);
    void FUN_0054d090(NiPoint3* position, NiPoint3* rotation);
    bool FUN_00550200(NiPoint3* position);
    bool FUN_00550340();
    RefX* FUN_00551180(RefX* reference);
    void FUN_005512f0(RefX* reference);
    void FUN_00551440(bool active);
    bool FUN_005516c0();
    unsigned char FUN_00552bb0();
    void FUN_00555b10(NiPoint3& position, NiPoint3& rotation, bool interior);
    void FUN_005571a0(bool active);
    void FUN_005576c0();
    bool FUN_00558b80(int mask);
    void FUN_00558ba0(TESObjectREFR* reference);
    BSSimpleList<BGSPerkEntry*>* FUN_009604f0();

    void* FUN_005445d0();
    void* FUN_00544600();
    bool FUN_00544590(unsigned int bit);
    void FUN_00544890(NiColor* color);
    unsigned int FUN_00544910();
    unsigned int FUN_00544970();
    void FUN_00544a30(NiColor* color);
    void RegisterReferenceInCell(TESObjectREFR* reference);
    TESGlobal* FUN_00546aa0();
    unsigned int FUN_00546af0();
    BGSAcousticSpace* FUN_00547590();
    ImpactSwap* GetImpactSwap();
    NiNode* FUN_005495d0();
    NiNode* FUN_0054a050();
    void FUN_0054b950(bool attach);
    void FUN_0054de10(TESWorldSpace* world);
    void FUN_0054de80(int value);
    unsigned int FUN_0054deb0();
    bool FUN_00551420();
    void FUN_00552900(bool altered);
    void FUN_005535f0();
    void FUN_00555a50(BGSLoadFormBuffer* buffer);
    void FUN_00558b60(BGSLightingTemplate* lightingTemplate);
    bool FUN_00558b80(unsigned int mask);
    void FUN_00558ba0(int mask);
    void FUN_00558c90();
    BSPortalGraph* FUN_009d9f20();
    void FUN_00c3e310();
    void FUN_005496b0(TESObjectREFR* reference, NiNode* parent);
    bool FUN_00550280(TESFile* file);
    void UpdateNavMeshObstacles();
    void AttachOrphanedChildren();
    bool FUN_0054c740(bool, bool);
    void RecalcLeveledActorBases(bool);
    void FUN_00555740(BGSLoadFormBuffer* buffer);
    bool CheckWaterHeight(void* data, float* height);
    void UpdateCellExtraData(BSExtraData* value, bool flag);
    int FUN_005477f0(int, int);
    void FUN_00548740(TESObjectREFR* reference);
    void LockAndProcessPerks();
    void FUN_00541ac0();
    void FUN_00541ae0();
    void* FUN_009604f0(unsigned char flag);
    void FUN_0054af40(unsigned char flag);
    void FUN_00557ae0();
    bool FUN_00546ca0(Actor* actor);
    bool FUN_00450ff0();                     // 0x00450ff0 (HighProcess::Update 0x008eeec0)
    int FUN_00546ac0();
    bool FUN_00546ee0(TESActorBase* actorBase);
    void FUN_005559d0(BGSLoadFormBuffer* buffer);
    void FUN_00541ce0();
    bool FUN_00543c50(TESForm* form);

    bool PickChildNodes(NiPick* pick, int a2, int a3, float a4, char mask);
    NiAVObject* ChildNodeAt(int index);
    bool SaveCellToFile(CellFileStub* file);
    bool SaveCellToFile(TESFile* file);
    void FUN_00542040(CellFileStub* file);
    bool FUN_00460340();
    bool FUN_005497c0(AObj* p1, P2Obj* p2, int p3,
                      unsigned char* p4, unsigned char p5);
    void Prepare();
    bool IsAttached();
    void AddSpaceRef(RefX* reference);
    bool IsInteriorCell();
    void ProcessCellRefs();
    void UpdateCell();
    SeenData_Stub* FUN_00555bc0();
    unsigned short FUN_00554b90(unsigned int flags);

    static void InitializeCell();
    static unsigned int InitializeTESResources(
        ActorReferenceArray::ActorReferenceSetupData& setup, bool, bool, bool);
    static bhkWorld* GetExteriorbhkWorld();
};

