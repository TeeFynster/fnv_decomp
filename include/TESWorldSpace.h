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
    bool FUN_0099a3e0();
    int FUN_009611e0();
    bool FUN_00992530(Actor*, Actor*);
    void FUN_00992480(Actor*, Actor*);
    BSPortalGraph* FUN_006698d0();
    void FUN_00588270(BSSimpleArray<TESObjectREFR*, 1024>&);
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
    void FUN_00584150(float);
    void FUN_00586110(float);
    void FUN_00586130(float);
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

    void FUN_00583070();
    void FUN_00583180();
    void FUN_005877e0();
    void FUN_00588c80();
    void ClearAllLists();
    void DestroyMapEntries();
    void FUN_00588030(TESObjectREFR*);
    bool FUN_00587670(TESObjectCELL*);
    void FUN_00587e40(TESObjectREFR*);
    TESObjectCELL* GetOrCreateCell();
    TESClimate* FUN_00585fe0();
    TESWaterForm* FUN_005860c0();
    const char* FUN_00586440();
    PointerPairData* FUN_00586400();
    TESObjectCELL* FUN_00587550(const NiPoint3&);
    void RemoveCellFromMap(TESObjectCELL*);
    void AddCellReferences(TESObjectCELL*);
    void FUN_005884e0(TESObjectREFR*);
    void FUN_00587d10(TESObjectREFR*);

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
