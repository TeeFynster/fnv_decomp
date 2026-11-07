// fallout_shared/tesworldspace_packet_rtti2_tesworldspace.h: declares TESForm, TESObjectREFR, TESObjectCELL, TESFile, TESRegion and more
#ifndef TESWORLDSPACE_PACKET_H
#define TESWORLDSPACE_PACKET_H

class TESWorldSpace;
class BGSTerrainManager;
class TESFile;
class TESObjectREFR;
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
    bool IsTemporary() const;
    bool IsConstantGlobal();
};
class TESObjectREFR : public TESForm
{
};
template <class T, int N> class BSSimpleArray
{
  public:
    char data[16];
};
class TESObjectCELL
{
  public:
    char pad[0x24];
    unsigned char flags;
    bool IsCellInterior() const;
    void AddReference(TESObjectREFR*, bool);
    void AppendCellReferences(BSSimpleArray<TESObjectREFR*, 1024>&);
};
template <class T> class BSStringT
{
  public:
    bool Set(const T*, unsigned int);
};
template <class K, class V> class NiTPointerMap
{
  public:
    bool GetAt(K, V&) const;
};
class TESFile
{
  public:
    TESFile* GetThreadSafeRootFile();
};
class TESRegion : public TESForm
{
  public:
    char pad[0x20];
    TESWorldSpace* world;
    void AssignWorldSpace(TESWorldSpace*);
};
class TESDataHandler
{
  public:
    bool LoadDescriptionForForm();
};
extern TESDataHandler* g_dataHandler;
extern NiTPointerMap<unsigned int, TESObjectREFR*>* DAT_011c40b0;
class TESWorldSpace
{
  public:
    virtual ~TESWorldSpace();  // the original class is polymorphic (rtti_variants.py)
  public:
    enum PARENT_USE_FLAG
    {
        USE_LAND = 1
    };
    char pad0[0x30];
    NiTPointerMap<unsigned int, TESObjectREFR*>* cellMap;
    char pad34[8];
    BGSTerrainManager* terrain;
    char pad40[0xC];
    unsigned char flags4C;
    char pad4D[1];
    unsigned short field4E;
    char pad50[0x20];
    TESWorldSpace* parent;
    char pad74[0x4c];
    BSStringT<char> mapName;
    char padC1[7];
    float fC8;
    float fCC;
    unsigned int fieldD0;
    bool SetDateTimeText(const char*);
    BGSTerrainManager* GetWorldTerrainManager();
    TESWorldSpace* GetParentWorld(PARENT_USE_FLAG);
    bool GetParentUseFlag(PARENT_USE_FLAG);
    TESObjectCELL* GetCellByKey(unsigned int);
    void AddPersistentReference(TESObjectREFR*);
    TESObjectCELL* CreatePersistentCell();
    void SetHasRegions(bool);
    static bool IsFormIDOwnedByFile(unsigned int, TESFile*);
    void ClearWorldSpaceReferences();
    TESObjectCELL* GetCellAtGridPosition(int, int);
    static int BuildCellKey(short, short);
    void SetWaterLODHeight(float);
    void SetDefaultLandHeight(float);
    void Projectile_SetPower(float);
    bool GetSmallWorld();
    bool IsFlag4C20Set();
    void SetParent(TESWorldSpace*);
    void SetFieldD0(unsigned int);
    TESObjectCELL* GetInteriorCell();
    void BuildTeleportDoorList(BSSimpleArray<TESObjectREFR*, 1024>&);
};
class Tile;
class InterfaceManager
{
  public:
    char pad[0x9C];
    Tile* pTile;
    Tile* CombatController_GetCombatState();
};
#endif
class TESSound;
class TESQuest;
class TESEffectShader;
class BGSAcousticSpace
{
  public:
    void SetNightSound(TESSound*);
};
class TESObjectACTI
{
  public:
    void SetLoopingSound(TESSound*);
};
class EffectSetting
{
  public:
    void SetEffectShader(TESEffectShader*);
};
class TESFullName
{
  public:
    void SetFullName(const char*);
};
extern "C" void* memset(void*, int, unsigned int);
extern float DAT_01031920;
extern const char DAT_010187a0[];
int Warning(const char*, ...);
