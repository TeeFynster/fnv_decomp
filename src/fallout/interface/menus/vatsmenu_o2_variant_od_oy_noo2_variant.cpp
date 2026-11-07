
// src/fallout/interface/menus/vatsmenu_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /GF /Oy- (unit src/fallout/interface/menus/vatsmenu_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/interface/menus/vatsmenu_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/menus/vatsmenu.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "vatsmenu_decls.h"
#include "../../../../include/Menu.h"
#include "../../../../include/AnimIdle.h"
#include "../../../../include/GameTimerRecord.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TESObjectREFR.h"
struct ItemListElement;
struct ItemList
{
    ItemListElement** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ItemListContainer
{
    char pad[8];
    ItemList items;
    ~ItemListContainer();
};
struct TargetList
{
    ItemListContainer** FUN_006815c0();
    void FUN_0063f7b0();
};
struct GlobalObject2_0096a2d0
{
    int x;
};
extern GlobalObject2_0096a2d0 g_011db150;
void VATSMenu_ClearTargetList();
struct FUN_007ebd30_This
{
    char pad[0x374];
    float fValue;
    float __thiscall FUN_007ebd30();
};
extern int DAT_011db0d4;
void __cdecl VATSMenu_SetHeadingReached(int a1);
// Exe 0x007f68a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct VatsmenuOffset08View
{
    unsigned int GetFlags();
};
extern int DAT_011f2250;
struct Caller007efa10
{
    void __thiscall UpdateQueueEntry(int a1, int a2, int a3);
};
struct FUN_007ef710_This
{
    char _pad[0xF8];
    bool m_bFirstFlag;
    bool __thiscall HandleKey(int aiKey);
};
struct FUN_0070ec70_This
{
    int __thiscall InterfaceManager_GetMouseWheel();
};
void* __cdecl InterfaceManager_GetSingleton();
struct FUN_007ef760_Owner
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int, int);
    void __thiscall DoWheelMove_007ef760(int aiID, Tile* apTarget);
};
struct Vec2Tmp
{
    float x;
    float y;
    Vec2Tmp DivideBy(float) const;
};
struct VatsTargetEntryList
{
    bool FUN_008256d0();
    ItemListContainer** FUN_006815c0();
    VatsTargetEntryList* FUN_00726070();
};
struct StandIn
{
    VatsTargetEntryList* FindListEntryForTarget(TESObjectREFR* apTarget);
};
void __cdecl _FNV_Warning(char const*);
void __cdecl _FUN_007037e0();
void __cdecl ShutdownVats();
Tile* VATSMenu_VatsMenuRenderTemplate(Tile* apParent, char const* axName);
Tile* __cdecl FindNamedTile(Tile*, char const*);
void __cdecl _FNV_Warning(char const*);
void __cdecl _FUN_007037e0();
void __cdecl ShutdownVats();
Tile* __cdecl VATSMenu_VatsMenuGetTileByName(Tile* a1, char const* a2);
extern GameTimerRecord g_timeGlobal;
struct DAT_Pointee_7f4bb0
{
    char pad[0x10F];
    unsigned char flag;
    char pad2[4];
    int t;
};
bool VATSMenu_SelectLeftHeld();
// Exe 0x007f68a0: unit-local ListBox view; declarations and layout are preserved.
struct VatsListCallView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* v5(int);
    int GetFilteredCount(int);
    Tile* ListBox_unsigned_int_GetLastItem();
};


struct __declspec(align(16)) B006815c0
{
    char pad[16];
    B006815c0();
};

B006815c0* __cdecl NI2HK(B006815c0* a1, const NiPoint3& a2);

class Class_007f68a0
{
  public:
    void ForwardToSubObject(B006815c0* a1);
    void bhkPickData_SetLength(const NiPoint3& pt);
};

// @fnv 0x007f68a0
// src: XBOX_PDB 0x007f68a0
void Class_007f68a0::bhkPickData_SetLength(const NiPoint3& pt)
{
    B006815c0 vec;
    ForwardToSubObject(NI2HK(&vec, pt));
}

struct Quest007f6af0
{
    float QueuedModel_GetOverriddenVisualDistance();
};
struct Light007f6af0
{
    float TESCombatStyle_GetWeaponMinRangeMult();
};
struct Anim007f6af0
{
    void MapScreenToRay(int, int, NiPoint3*, NiPoint3*, int);
};
struct Node007f6af0
{
    Anim007f6af0* FUN_006629f0();
};
Node007f6af0* Main_GetWorldSceneGraph();
extern float DAT_011a0b74;
struct Filter007f6af0
{
    int field_00;
    Filter007f6af0()
    {}
    Filter007f6af0(int);
    void CFilter_SetLayer(int);
    void CFilter_SetGroup(unsigned);
    unsigned CFilter_GetGroup();
};
struct Hit007f6af0
{
    int field_00[20];
    void* field_50;
    int field_54[3];
    Hit007f6af0* hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(Hit007f6af0*);
};
struct Hits007f6af0
{
    int FUN_00726070();
    Hit007f6af0* GetEntryAt(int);
};
struct Response007f6af0
{
    Hits007f6af0* GetVoiceFilePath();
};
struct __declspec(align(16)) Collector007f6af0
{
    int field_00[198];
    Collector007f6af0();
    virtual ~Collector007f6af0();
};
struct __declspec(align(16)) Ray007f6af0
{
    char field_00[176];
    Ray007f6af0();
    void bhkPickData_SetFilter(int);
    void bhkPickData_SetFrom(NiPoint3*);
    void bhkPickData_SetLength(NiPoint3 const&);
    void bhkPickData_SetAllCollector(Collector007f6af0*);
    Response007f6af0* DialoguePackage_GetCurrentDialogItem();
};
struct World007f6af0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(Ray007f6af0*);
};
struct PlayerFilter007f6af0
{
    int field_00;
    unsigned CFilter_GetGroup();
};
struct Player007f6af0
{
    void FUN_00931ed0(PlayerFilter007f6af0*);
    void* GetTarget();
};
extern Player007f6af0* DAT_011dea3c;
World007f6af0* __fastcall TESObjectCELL_GetbhkWorld(void*);
void FUN_00c82870(int, unsigned __int64);
void* GetAVObjectForCollidable(void*);
TESObjectREFR* TESObjectREFR_FindReferenceFor3D(void*);
extern ItemListContainer* DAT_011f21cc;
struct Owner007f6af0
{
    char field_00[0x10e];
    unsigned char field_10e;
    void UpdateLimbHighlight();
};
// @fnv 0x007f6af0
// src: XBOX_PDB 0x007f6af0
bool __fastcall VATSMenu_PickNewTarget(Owner007f6af0* self)
{
    if (self->field_10e)
        return false;
    float distance = DAT_011a0b74;
    NiPoint3 origin;
    NiPoint3 direction;
    Main_GetWorldSceneGraph()->FUN_006629f0()->MapScreenToRay((int)((Light007f6af0*)InterfaceManager_GetSingleton())->TESCombatStyle_GetWeaponMinRangeMult(),
                                                   (int)((Quest007f6af0*)InterfaceManager_GetSingleton())->QueuedModel_GetOverriddenVisualDistance(), &origin,
                                                   &direction, 0);
    Ray007f6af0 ray;
    unsigned int mask = 0x140;
    FUN_00c82870(0x27, mask);
    PlayerFilter007f6af0 playerFilter;
    DAT_011dea3c->FUN_00931ed0(&playerFilter);
    Filter007f6af0 filter(0);
    filter.CFilter_SetLayer(0x27);
    filter.CFilter_SetGroup(playerFilter.CFilter_GetGroup());
    ray.bhkPickData_SetFilter(filter.field_00);
    ray.bhkPickData_SetFrom(&origin);
    ray.bhkPickData_SetLength(direction * distance);
    Collector007f6af0 collector;
    ray.bhkPickData_SetAllCollector(&collector);
    World007f6af0* world = TESObjectCELL_GetbhkWorld(DAT_011dea3c->GetTarget());
    world->v50(&ray);
    int unused = 0;
    for (int i = 0; i < ray.DialoguePackage_GetCurrentDialogItem()->GetVoiceFilePath()->FUN_00726070(); ++i)
    {
        Hit007f6af0 hit;
        hit.hkpWorldRayCastOutput_hkpWorldRayCastOutput_00696c30(ray.DialoguePackage_GetCurrentDialogItem()->GetVoiceFilePath()->GetEntryAt(i));
        void* object = GetAVObjectForCollidable(hit.field_50);
        TESObjectREFR* ref = TESObjectREFR_FindReferenceFor3D(object);
        if (object)
        {
            VatsTargetEntryList* entry = ((StandIn*)self)->FindListEntryForTarget(ref);
            if (entry && *(ItemListContainer**)*entry->FUN_006815c0() == DAT_011f21cc)
            {
                return false;
            }
            else if (entry)
            {
                VATSMenu_SetHeadingReached(0);
                self->UpdateLimbHighlight();
                DAT_011f21cc = *(ItemListContainer**)*entry->FUN_006815c0();
                return true;
            }
            ref = 0;
        }
    }
    return false;
}
