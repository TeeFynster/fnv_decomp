#pragma once

#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
#include "NiPoint3.h"
#include "SL.h"
#include "StrMem.h"

class TESObjectREFR;
class TESObjectCELL;
class BGSEncounterZone;
class BGSTerrainManager;
class PointerPairData;
class WorldSpaceTarget;
class Actor;
class BSPortalGraph;
class TESClimate;
class TESWaterForm;
class TESImageSpace;
template <class T, unsigned int N> class BSSimpleArray;

// Both names call the inherited virtual at primary vtable slot 76.
#define GetStingerBlockFileNameHighPriority GetName

class TESWorldSpace : public TESForm, public TESFullName, public TESTexture
{
public:
    enum PARENT_USE_FLAG  // values: Xbox PDB TESWorldSpace::PARENT_USE_FLAG
    {
        PU_LAND = 0,
        PU_LOD = 1,
        PU_MAP = 2,
        PU_WATER = 3,
        PU_CLIMATE = 4,
        PU_IMAGESPACE = 5,
        PU_COUNT = 6
    };

    TESWorldSpace();
    virtual ~TESWorldSpace();
    virtual void vf78();
    virtual void vf79();

    void GetReferencesInArea(const NiPoint3&, float, const NiPoint3&, float,
                             bool (__cdecl*)(TESObjectREFR*, long), long);
    bool HasCell(TESObjectCELL*);
    TESObjectCELL* GetCellAtGridPosition(int, int);
    TESObjectCELL* GetCellByWorldPosition(const NiPoint3&);
    int GetCellAtGridCoord(int aiX, int aiY);
    TESObjectCELL* GetInteriorCell();
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG flag);
    TESWorldSpace* GetParentWorld(int);
    PointerPairData* GetWorldSpaceData();
    WorldSpaceTarget* FUN_00825c00();
    static int __cdecl BuildCellKey(short, short);
    static int GetKeyForWorldCoord(const NiPoint3& point);
    TESObjectCELL* GetCellByKey(unsigned int);
    TESObjectCELL* LookupCellByEditorID(const char* editorID);
    void GetCellAtPosition(NiPoint3&, bool);
    BGSEncounterZone* FindEncounterZone() const;
    BGSTerrainManager* GetWorldTerrainManager();
    bool GetSmallWorld();
    void* GetFieldD0();
    virtual char* GetName() const;
    int getFormType();
    bool CombatProcedureBeInCover_GetBehindCover();
    int NiAVObject_GetParent();
    bool CombatManager_GetWanttoHelpGroup(Actor*, Actor*);
    void CombatManager_AddSpectatorForCombatGroup(Actor*, Actor*);
    BSPortalGraph* TESPackage_GetOnChangeIdle();
    void BuildTeleportDoorList(BSSimpleArray<TESObjectREFR*, 1024>&);
    float GetFloatAt0xC8();
    bool SetDateTimeText(const char*);
    bool GetParentUseFlag(PARENT_USE_FLAG);
    void AddPersistentReference(TESObjectREFR*);
    TESObjectCELL* CreatePersistentCell();
    void SetHasRegions(bool);
    void SetFlagBit0(bool);
    void* GetOrCreateCellOffsetData(TESFile*);
    static bool IsFormIDOwnedByFile(unsigned int, TESFile*);
    void ClearWorldSpaceReferences();
    void SetWaterLODHeight(float);
    void SetDefaultLandHeight(float);
    void Projectile_SetPower(float);
    bool IsFlag4C20Set();
    void SetParent(TESWorldSpace*);
    void SetFieldD0(unsigned int);

    class ObjectPointer
    {
    public:
        ObjectPointer(int);
        ~ObjectPointer();
        void* node;
    };

    class BoundsPoint
    {
    public:
        BoundsPoint();
        float x;
        float y;
    };

    class CellList
    {
    public:
        CellList();
        ~CellList();
        unsigned int unk00;
    };

    class ReferenceMap
    {
    public:
        ReferenceMap(unsigned int);
        ~ReferenceMap();
        unsigned int unk00;
        unsigned int unk04;
        unsigned int unk08;
        unsigned int unk0C;
    };

    class CellOffsetMap
    {
    public:
        CellOffsetMap(int);
        ~CellOffsetMap();
        unsigned int unk00;
        unsigned int unk04;
        unsigned int unk08;
        unsigned int unk0C;
    };

    void InitializeData_00583070();
    void ClearData_00583180();
    void ClearCellMap();
    void FreeOffsetMap();
    void ClearAllLists();
    void DestroyMapEntries();
    void RemovePersistentRef(TESObjectREFR*);
    bool AddCell(TESObjectCELL*);
    void RemoveFromPersistentRefData(TESObjectREFR*);
    TESObjectCELL* GetOrCreateCell();
    TESClimate* GetClimate();
    TESWaterForm* GetLODWaterType();
    const char* GetWorldMapTextureName();
    PointerPairData* GetWorldMapData();
    TESObjectCELL* GetCellFromWorldCoord(const NiPoint3&);
    void RemoveCellFromMap(TESObjectCELL*);
    void AddCellReferences(TESObjectCELL*);
    void GetCurrentCellMarkerDataRefs(TESObjectREFR*);
    void AddToPersistentRefData(TESObjectREFR*);

    union
    {
        NiTPointerMap<unsigned int, TESObjectREFR*>* cellMap;
        NiTPointerMap<unsigned int, TESObjectREFR*>* pCellNavMeshInfoMap;
    };
    TESObjectCELL* m_pCell;
    CellList m_kFirstTreeComponent;
    union
    {
        BGSTerrainManager* terrain;
        void* m_pThirdTreePointer;
    };
    TESClimate* climate;
    void* imageSpace;
    TESImageSpace* data;
    unsigned char flags4C;
    unsigned char unk4D;
    unsigned short field4E;
    ReferenceMap m_kSecondTreeComponent;
    SL m_kThirdTreeComponent;
    void* m_pFourthTreePointer;
    ObjectPointer m_kFourthTreeComponent;
    TESWorldSpace* parent;
    TESWaterForm* water;
    TESWaterForm* lodWater;
    float field7c;
    unsigned char unk80[0x20];
    BoundsPoint m_kFirstPoint;
    BoundsPoint m_kEndPoint;
    CellOffsetMap OffsetDataMap;
    StrMem mapName;
    float fC8;
    float fCC;
    unsigned int fieldD0;
    TESTexture CanopyShadowTexture;
    TESTexture m_kLeafShadowTexture;
};
