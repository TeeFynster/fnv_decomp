#include "../../../include/BSAudio.h"
#include "../../../include/Actor.h"
#include "../../../include/MemoryManager.h"
#include "../../../include/TESCreature.h"
#include "../../../include/TESObjectWEAP.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BGSImpactData.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../../include/TESForm.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/TESSound.h"

// src/fallout/audio/impactmixer_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout/audio/impactmixer.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/audio/impactmixer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/audio/impactmixer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_011dd878;
bool ImpactMixer_GetGunshotsInitialized();
extern int DAT_011dd878;
void ImpactMixer_SetGunshotsInitialized(bool b);
extern int DAT_011a17f8[0x24];
int GetTypeValue(int aiType);
void ImpactMixer_PlayHitSound();
extern int DAT_01000000;
struct DummyFlags
{
    int FUN_00621270(int);
};
struct FUN_00838750_shell
{
    bool bhkCharacterController_GetOnStairs();
};
struct FUN_00541570_shell
{
    char _pad[0x1c];
    unsigned char m_0x1c;
    unsigned int GetField1C();
};
void __cdecl ImpactMixer_SetGunshotsInitialized(bool b);
extern float DAT_01016970;
void __cdecl InitializeSlots();
struct FUN_0063a3c0_cls
{
    int unk00;
    int unk04;

    void BaseRelease();
    FUN_0063a3c0_cls* FUN_0063a3c0(unsigned int auiFlags);
    static void operator delete(void* apMemory) throw();
};
struct BGSSoundDescriptor;
struct BGSImpactDataEntry
{
    BGSImpactData* pkImpact;
    int unk04[9];
};
extern BGSImpactDataEntry g_akImpactData_011dd670[];
struct TESWorldSpace;
extern Actor* g_player_011dea3c;
struct MaterialRecord
{
    int GetField1C();
};
struct NavQueryResult
{
    int unk00[6];
    unsigned char unk18;
    unsigned char unk19;
    unsigned short unk1a;
    int unk1c[8];
    unsigned short unk3c;
    unsigned short unk3e;
    int unk40[4];
    NavQueryResult();
};
struct CellNavInfo
{
    void TESObjectLAND_GetCoordData(NavQueryResult* pkResult, NiPoint3* pkPos, int iFlag);
    MaterialRecord* TESObjectLAND_GetMainTexture_0053a630(unsigned char ucA, unsigned short usB);
};
struct FootstepCell
{
    bool FUN_00425fd0();
    bool FUN_004518e0();
    CellNavInfo* TESObjectCELL_GetLand();
    bool TESObjectCELL_GetLandHeight(NiPoint3* pkPos, float* pfHeight);
};
struct TESStandIn
{
    FootstepCell* FUN_005f36f0();
    TESWorldSpace* FUN_004fd3e0(int iUnk);
};
extern TESStandIn* g_TES_011dea10;
struct DataHandlerStandIn
{
    FootstepCell* FUN_00461bc0(float fX, float fY, TESWorldSpace* pkWorld);
    BGSImpactData* FUN_004616c0(const char* pEditorID);
};
extern DataHandlerStandIn* g_dataHandler_011c3f2c;
int __cdecl GetTypeValue(int iMaterial);
float __cdecl FUN_00476b70(float fMin, float fScaledValue);
bool __cdecl FUN_0082eca0(BGSImpactData* pkImpact, NiPoint3 kPos, float fScale);
extern float g_fFootstepRand_0101e2bc;
static const char s_szBabyLand[] = "FSTBabyLand";
extern const char g_szFootstepEnd[] = "";
void __cdecl PlayFootstepImpact(Actor* pActor, int iMaterial);
struct SetObj
{
    float* Setting_Float_00403e20();
};
struct StrObj
{
    int FUN_004616c0(const char* s);
};
extern SetObj DAT_011dd9c8;
extern SetObj DAT_011dd9b0;
extern SetObj DAT_011dd918;
extern SetObj DAT_011dd9bc;
extern SetObj DAT_011dd8e8;
extern SetObj DAT_011dd8f4;
extern SetObj DAT_011dd8cc;
extern SetObj DAT_011dd930;
extern SetObj DAT_011dd9d8;
extern SetObj DAT_011dd9a0;
extern SetObj DAT_011dd924;
extern StrObj* DAT_011c3f2c;
extern double DAT_01032980;
extern double DAT_01034208;
extern double DAT_01015a38;
extern double DAT_01073568;
static const char kStr_CStoneStatic[] = "CStoneStatic";
static const char kStr_CStoneSmall[] = "CStoneSmall";
static const char kStr_CStoneMedium[] = "CStoneMedium";
static const char kStr_CStoneLarge[] = "CStoneLarge";
static const char kStr_CEarthSmall[] = "CEarthSmall";
static const char kStr_CEarthMedium[] = "CEarthMedium";
static const char kStr_CEarthLarge[] = "CEarthLarge";
static const char kStr_CGrassSmall[] = "CGrassSmall";
static const char kStr_CGrassMedium[] = "CGrassMedium";
static const char kStr_CGrassLarge[] = "CGrassLarge";
static const char kStr_PHYGenericMetalStaticL[] = "PHYGenericMetalStaticL";
static const char kStr_PHYGenericMetalSmallL[] = "PHYGenericMetalSmallL";
static const char kStr_PHYGenericMetalMediumL[] = "PHYGenericMetalMediumL";
static const char kStr_PHYGenericMetalLargeL[] = "PHYGenericMetalLargeL";
static const char kStr_PHYGenericMetalStaticH[] = "PHYGenericMetalStaticH";
static const char kStr_PHYGenericMetalSmallH[] = "PHYGenericMetalSmallH";
static const char kStr_PHYGenericMetalMediumH[] = "PHYGenericMetalMediumH";
static const char kStr_PHYGenericMetalLargeH[] = "PHYGenericMetalLargeH";
static const char kStr_CWoodStatic[] = "CWoodStatic";
static const char kStr_CWoodSmall[] = "CWoodSmall";
static const char kStr_CWoodMedium[] = "CWoodMedium";
static const char kStr_CWoodLarge[] = "CWoodLarge";
static const char kStr_PHYGenericClothL[] = "PHYGenericClothL";
static const char kStr_PHYGenericClothH[] = "PHYGenericClothH";
static const char kStr_COrganicSmall[] = "COrganicSmall";
static const char kStr_PHYSkinSmallL[] = "PHYSkinSmallL";
static const char kStr_PHYSkinMediumL[] = "PHYSkinMediumL";
static const char kStr_PHYSkinLargeL[] = "PHYSkinLargeL";
static const char kStr_PHYSkinSmallH[] = "PHYSkinSmallH";
static const char kStr_PHYSkinMediumH[] = "PHYSkinMediumH";
static const char kStr_PHYSkinLargeH[] = "PHYSkinLargeH";
static const char kStr_CGlassSmall[] = "CGlassSmall";
static const char kStr_CGlassMedium[] = "CGlassMedium";
static const char kStr_CGlassLarge[] = "CGlassLarge";
static const char kStr_PHYChain[] = "PHYChain";
static const char kStr_CSpecialHeavyStone[] = "CSpecialHeavyStone";
static const char kStr_CSpecialHeavyMetal[] = "CSpecialHeavyMetal";
static const char kStr_CSpecialHeavyWood[] = "CSpecialHeavyWood";
static const char kStr_PHYGenericMetalHollowStatic[] = "PHYGenericMetalHollowStatic";
static const char kStr_PHYGenericMetalHollowSmall[] = "PHYGenericMetalHollowSmall";
static const char kStr_PHYGenericMetalHollowMedium[] = "PHYGenericMetalHollowMedium";
static const char kStr_PHYGenericMetalHollowLarge[] = "PHYGenericMetalHollowLarge";
static const char kStr_PHYGenericMetalSheetStatic[] = "PHYGenericMetalSheetStatic";
static const char kStr_PHYGenericMetalSheetSmall[] = "PHYGenericMetalSheetSmall";
static const char kStr_PHYGenericMetalSheetMedium[] = "PHYGenericMetalSheetMedium";
static const char kStr_PHYGenericMetalSheetLarge[] = "PHYGenericMetalSheetLarge";
static const char kStr_PHYVehicleMetalBodyL[] = "PHYVehicleMetalBodyL";
static const char kStr_PHYVehicleMetalBodyH[] = "PHYVehicleMetalBodyH";
static const char kStr_PHYVehicleMetalSolidL[] = "PHYVehicleMetalSolidL";
static const char kStr_PHYVehicleMetalSolidH[] = "PHYVehicleMetalSolidH";
static const char kStr_PHYVehicleMetalHollowL[] = "PHYVehicleMetalHollowL";
static const char kStr_PHYVehicleMetalHollowH[] = "PHYVehicleMetalHollowH";
static const char kStr_PHYBarrelL[] = "PHYBarrelL";
static const char kStr_PHYBarrelH[] = "PHYBarrelH";
static const char kStr_PHYBottleL[] = "PHYBottleL";
static const char kStr_PHYBottleH[] = "PHYBottleH";
static const char kStr_PHYCanSodaL[] = "PHYCanSodaL";
static const char kStr_PHYCanSodaH[] = "PHYCanSodaH";
static const char kStr_PHYWeaponPistolL[] = "PHYWeaponPistolL";
static const char kStr_PHYWeaponPistolH[] = "PHYWeaponPistolH";
static const char kStr_PHYWeaponRifleL[] = "PHYWeaponRifleL";
static const char kStr_PHYWeaponRifleH[] = "PHYWeaponRifleH";
static const char kStr_PHYShoppingCartL[] = "PHYShoppingCartL";
static const char kStr_PHYShoppingCartH[] = "PHYShoppingCartH";
static const char kStr_PHYLunchboxL[] = "PHYLunchboxL";
static const char kStr_PHYLunchboxH[] = "PHYLunchboxH";
static const char kStr_PHYBabyRattle[] = "PHYBabyRattle";
static const char kStr_PHYRubberBall[] = "PHYRubberBall";
static const char kStr_PHYBottlecaps[] = "PHYBottlecaps";
static const char kStr_PHYChainlink[] = "PHYChainlink";
static const char kStr_PHYTile[] = "PHYTile";
static const char kStr_PHYCarpet[] = "PHYCarpet";
static const char kStr_PHYTumbleweed[] = "PHYTumbleweed";
int __cdecl ImpactMixer_GetSoundForType(int type, float fA, float fB);
struct Point3;
class TESSound;
struct S_0083a930_EntryData
{
    TESBoundObject* FUN_0044ddc0();
};
struct S_0083a930_Process
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual S_0083a930_EntryData* GetWeaponInfo();  // +0x148
};
struct S_0083a930_Setting
{
    float* Setting_Float_00403e20();
};
extern S_0083a930_Setting DAT_011dd900;
extern Actor* DAT_011dea3c;
extern const float DAT_010231a8;
bool FUN_0082eca0(TESSound* sound, Point3 pos, float volume);
void PlayWeaponImpactSound(TESObjectREFR* ref, int type);
struct FootstepQuery
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char materialKind;
    unsigned char unk19;
    unsigned short unk1a;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    unsigned short triangle;
    unsigned short unk3e;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    FootstepQuery();
};
struct NavOps
{
    void TESObjectLAND_GetCoordData(FootstepQuery*, NiPoint3*, int);
};
extern const char armorPowerRightName[];
extern const char armorPowerLeftName[];
extern const char armorRightName[];
extern const char armorLeftName[];
bool Interface_IsInMenuMode();
bool Main_GetSceneIsComplex();
struct PointOps : NiPoint3
{
    NiPoint3& Subtract(const NiPoint3&);
    float FUN_00457990();
};
struct ListenerOps
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual const NiPoint3& GetPosition();
};
struct SoundOps
{
    unsigned char GetField45();
    BGSSoundDescriptor* GetHavokWorldObjectCountInSceneGraph_0084e3a0(int);
    const char* TESSound_GetFilename();
};
struct MaterialOps
{
    int FUN_0059bb30();
};
struct SkinOps
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    MaterialOps material;
    bool bhkCharacterController_GetOnStairs();
};
extern S_0083a930_Setting DAT_011dd988;
extern SoundOps* DAT_011dd860;
extern SoundOps* DAT_011dd864;
extern SoundOps* DAT_011dd868;
extern SoundOps* DAT_011dd86c;
struct FootstepEntry
{
    SoundOps* sounds[10];
};
extern FootstepEntry DAT_011dd650[];
void PlayFootstepSound(Actor* ref, int foot);
float BSMIN(float a, float b);
float BSMAX_00404010(float a, float b);
void PlayBlockSound(int aUnused, TESObjectWEAP* a1, float x0, float y0, float z0, float x1, float y1, float z1);

inline void* operator new(unsigned int, void* location)
{
    return location;
}
inline void operator delete(void*, void*)
{}
inline void* operator new[](unsigned int, void* location)
{
    return location;
}
inline void operator delete[](void*, void*)
{}
extern MemoryManager DAT_011f6238;
inline void* operator new[](unsigned int size)
{
    return DAT_011f6238.Game_DoHeapAlloc(size);
}
void operator delete[](void* memory);
// The original's point type here is NiPoint3: operator- 0x439ef0, Cross 0x4b3800, Unitize 0x4a0c10 and operator+
// 0x439e90 are called; the constructor, operator+ and operator*(float) are expanded inline under /Ob1.
__forceinline NiPoint3::NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
{}
__forceinline NiPoint3 NiPoint3::operator+(const NiPoint3& o) const
{
    return NiPoint3(o.x + x, o.y + y, o.z + z);
}
__forceinline NiPoint3 NiPoint3::operator*(float s) const
{
    return NiPoint3(s * x, s * y, s * z);
}
// Inline in the original too (their frame slots are reserved), but /Ob1 leaves them as calls.
inline NiPoint3 NiPoint3::operator-(const NiPoint3& other) const
{
    const NiPoint3* self = this;
    return NiPoint3(self->x - other.x, self->y - other.y, self->z - other.z);
}
inline NiPoint3 NiPoint3::Cross(const NiPoint3& axis) const
{
    const NiPoint3* self = this;
    return NiPoint3(self->y * axis.z - self->z * axis.y, self->z * axis.x - self->x * axis.z,
                    self->x * axis.y - self->y * axis.x);
}

struct FilterData
{
    unsigned int collisionLayer;
    unsigned int group;
    unsigned int flags;
    unsigned int subsystem;

    static __forceinline void* operator new[](unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    static void operator delete[](void*);
};
extern void __stdcall FUN_00401050(void* storage, unsigned int elementSize, unsigned int count,
                                   void(__cdecl* constructor)(void*));
extern void __cdecl FUN_004a7800(void* value);
extern void* __cdecl FUN_00ec44d0(void* target, const void* source, unsigned int bytes);
extern unsigned char DAT_010c2c38;
extern void* __cdecl Object_DispatchCommandFour(unsigned int bytes);
struct FilterArray
{
    FilterData values[8];
    static __forceinline void* operator new(unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    static void operator delete(void*);
    __forceinline FilterArray()
    {
        FUN_00401050(values, 16, 8, FUN_004a7800);
    }
};
struct CollisionShape
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
};
struct CollisionGenerator : CollisionShape
{
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    static __forceinline void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
    static void operator delete(void*);
    CollisionGenerator(unsigned int count, NiPoint3* vertices, int unused, FilterData* _filters, int a, int b, int c,
                       int d, void* data);
};
// @fnv 0x00c55d50
// src: COMMUNITY 0x00c55d50
CollisionShape* __cdecl BSTestObjects_CreateBox(NiPoint3* start, NiPoint3* end, float forwardExtent, float backwardExtent,
                                     float upExtent, float downExtent, FilterData* nearFilter, FilterData* farFilter)
{
    NiPoint3* verticesX;
    verticesX = new NiPoint3[8];
    NiPoint3 directionX = *start - *end;
    NiPoint3 verticalAxisB(0.0f, 0.0f, 1.0f);
    NiPoint3 crossVal2 = directionX.Cross(verticalAxisB);
    crossVal2.z = 0.0f;
    crossVal2.Unitize();
    NiPoint3 forwardVectorB = crossVal2 * forwardExtent;
    NiPoint3 reverseVector2 = crossVal2 * (-backwardExtent);
    NiPoint3 offset(0.0f, 0.0f, upExtent);
    NiPoint3 below2(0.0f, 0.0f, -downExtent);
    verticesX[0] = offset + (reverseVector2 + *end);
    verticesX[1] = offset + (forwardVectorB + *end);
    verticesX[2] = below2 + (reverseVector2 + *end);
    verticesX[3] = below2 + (forwardVectorB + *end);
    verticesX[4] = offset + (reverseVector2 + *start);
    verticesX[5] = offset + (forwardVectorB + *start);
    verticesX[6] = below2 + (reverseVector2 + *start);
    verticesX[7] = (forwardVectorB + *start).FUN_00439e90(below2);
    FilterData* _filters = 0;
    if (nearFilter || farFilter)
    {
        _filters = reinterpret_cast<FilterData*>(new FilterArray);
        if (nearFilter && !farFilter)
            farFilter = nearFilter;
        else if (farFilter && !nearFilter)
            nearFilter = farFilter;
        for (unsigned int indexC = 0; indexC < 4; ++indexC)
            _filters[indexC] = *farFilter;
        for (unsigned int index7 = 4; index7 < 8; ++index7)
            _filters[index7] = *nearFilter;
    }
    unsigned short* pData6 = new unsigned short[36];
    FUN_00ec44d0(pData6, &DAT_010c2c38, 0x48);
    CollisionGenerator* shape2 = new CollisionGenerator(8, verticesX, 0, _filters, 0, 0, 0, 12, pData6);
    shape2->slot0e8();
    return shape2;
}
