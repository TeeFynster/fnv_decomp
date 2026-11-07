#include "../../../include/Actor.h"
#include "../../../include/TESCreature.h"
#include "../../../include/TESObjectWEAP.h"
#include "../../../include/NiPoint3.h"
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../../include/NiPoint3.h"
#include "../../../include/BSAudio.h"
#include "../../../include/BGSImpactData.h"
#include "../../../include/AutoMemHelper.h"
#include "../../../include/BSSoundHandle.h"
#include "../../../include/TESBoundObject.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESSound.h"

// src/fallout/audio/impactmixer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/audio/impactmixer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_011dd878;

// @fnv 0x00839da0
// src: COMMUNITY 0x00839da0
bool ImpactMixer_GetGunshotsInitialized()
{
    return (DAT_011dd878 & 2) != 0;
}

extern int DAT_011dd878;

// @fnv 0x00839dc0
// src: COMMUNITY 0x00839dc0
void ImpactMixer_SetGunshotsInitialized(bool abSet)
{
    int tmp;
    if (abSet)
        tmp = DAT_011dd878 | 2;
    else
        tmp = DAT_011dd878 & 0xfffffffd;
    DAT_011dd878 = tmp;
}

extern int DAT_011a17f8[0x24];

// @fnv 0x0083a910
int GetTypeValue(int aiType)
{
    if (aiType <= 0 || aiType >= 0x24)
        return 0;
    return DAT_011a17f8[aiType];
}

// @fnv 0x00acbb70
// src: COMMUNITY 0x00acbb70
void* __thiscall TESCreature::Return_0()
{
    return 0;
}

struct FUN_008397d0_shell
{
    unsigned char GetByteAt7C6();
};

// @fnv 0x008397d0
unsigned char FUN_008397d0_shell::GetByteAt7C6()
{
    return ((unsigned char*)this)[0x7c6];
}

// @fnv 0x00837520
// src: XBOX_PDB 0x00837520
void ImpactMixer_PlayHitSound()
{
    AutoMemHelper tempMemContext(0xB, 1, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp",
                                 0x10F);
}

extern int DAT_01000000;
struct DummyFlags
{
    int FUN_00621270(int);
};
struct FUN_00838750_shell
{
    bool bhkCharacterController_GetOnStairs();
};
// Calls FUN_00621270 on the DummyFlags sub-object at offset 0x410 with DAT_01000000 and returns whether the result is non-zero.
// @fnv 0x00838750
// src: COMMUNITY 0x00838750
bool FUN_00838750_shell::bhkCharacterController_GetOnStairs()
{
    return ((DummyFlags*)((char*)this + 0x410))->FUN_00621270((int)&DAT_01000000) != 0;
}

struct FUN_00541570_shell
{
    char _pad[0x1c];
    unsigned char m_0x1c;
    unsigned int GetField1C();
};
// @fnv 0x00541570
unsigned int FUN_00541570_shell::GetField1C()
{
    return m_0x1c;
}

void __cdecl ImpactMixer_SetGunshotsInitialized(bool b);
extern float DAT_01016970;
// If the init check fails, calls FUN_00839dc0(true), then zeroes two ints and sets a float from DAT_01016970 for each of 20 slots.
// @fnv 0x00839d30
void __cdecl InitializeSlots()
{
    if (ImpactMixer_GetGunshotsInitialized())
    {
        return;
        goto initialize;
    }
    ImpactMixer_SetGunshotsInitialized(true);
initialize:
    for (int i = 0; i < 20; ++i)
    {
        *(int*)((char*)&DAT_011dd878 + 0x188 + i * 0x24) = 0;
        *(int*)((char*)&DAT_011dd878 + 0x18c + i * 0x24) = 0;
        *(float*)((char*)&DAT_011dd878 + 0x190 + i * 0x24) = DAT_01016970;
    }
}

struct FUN_0063a3c0_cls
{
    int unk00;
    int unk04;

    void BaseRelease();
    FUN_0063a3c0_cls* FUN_0063a3c0(unsigned int auiFlags);
    static void operator delete(void* apMemory) throw();
};

// Releases the base object and, if bit 0 of auiFlags is set, deletes this instance, then returns this.
// @fnv 0x0063a3c0
FUN_0063a3c0_cls* FUN_0063a3c0_cls::FUN_0063a3c0(unsigned int auiFlags)
{
    BaseRelease();
    if (auiFlags & 1)
    {
        operator delete(this);
    }
    return this;
}

struct BGSImpactDataEntry
{
    BGSImpactData* pkImpact;
    int unk04[9];
};
extern BGSImpactDataEntry g_akImpactData_011dd670[];

struct TESWorldSpace;
struct FootstepActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual bool IsActor();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* Get3D();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const NiPoint3& GetPos();

    bool IsSwimming_005a2030();
    float TESObjectREFR_GetRelevantWaterHeight();
    bool GetByteAt7C6();
    bool PlayerCharacter_IsActually3rdPerson();
};
extern FootstepActor* g_player_011dea3c;

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
// NiPoint3 preserves the trivial copies used for this unit's by-value positions.
bool __cdecl FUN_0082eca0(BGSImpactData* pkImpact, NiPoint3 kPos, float fScale);
extern float g_fFootstepRand_0101e2bc;

static const char s_szBabyLand[] = "FSTBabyLand";
extern const char g_szFootstepEnd[] = "";

// Resolves the footstep material and impact data for an actor, adjusts the position, and plays the corresponding first- or third-person footstep sound.
// @fnv 0x008391b0
void __cdecl PlayFootstepImpact(FootstepActor* pActor, int iMaterial)
{
    BSSoundHandle kHandle_;
    BGSImpactData* pImpactX = 0;
    BGSImpactData* pImpact_ = 0;
    NiPoint3 kPosOut = reinterpret_cast<const NiPoint3&>(pActor->GetPos());
    FootstepCell* pCell_ = g_TES_011dea10->FUN_005f36f0();
    FootstepActor* pActorRef4 = 0;
    if (pActor->IsActor())
        pActorRef4 = pActor;
    else
        return;

    if (!pCell_)
        pCell_ = g_dataHandler_011c3f2c->FUN_00461bc0(kPosOut.x, kPosOut.y, g_TES_011dea10->FUN_004fd3e0(0));

    if (pActor->IsActor() && pCell_)
    {
        if ((pCell_->FUN_00425fd0() && pCell_->FUN_004518e0()) || !pCell_->FUN_00425fd0())
        {
            if (!pActorRef4->IsSwimming_005a2030() && pActorRef4->TESObjectREFR_GetRelevantWaterHeight() > kPosOut.z)
                iMaterial = 8;
        }
    }

    if (iMaterial == 0x24 && !pCell_->FUN_00425fd0() && pCell_->TESObjectCELL_GetLand())
    {
        NavQueryResult kResult_2;
        pCell_->TESObjectCELL_GetLand()->TESObjectLAND_GetCoordData(&kResult_2, reinterpret_cast<NiPoint3*>(&kPosOut), 1);
        MaterialRecord* pMaterialTmp = pCell_->TESObjectCELL_GetLand()->TESObjectLAND_GetMainTexture_0053a630(kResult_2.unk18, kResult_2.unk3c);
        if (pMaterialTmp)
        {
            float m_fGlyphExtent = 0.0f;
            iMaterial = pMaterialTmp->GetField1C();
            if (pCell_->TESObjectCELL_GetLandHeight(reinterpret_cast<NiPoint3*>(&kPosOut), &m_fGlyphExtent))
                kPosOut.z = m_fGlyphExtent;
        }
    }

    int iIndexZ = GetTypeValue(iMaterial);
    pImpactX = g_akImpactData_011dd670[iIndexZ].pkImpact;
    if (pActor == g_player_011dea3c && g_player_011dea3c->GetByteAt7C6())
        pImpactX = g_dataHandler_011c3f2c->FUN_004616c0(s_szBabyLand);

    bool bPlayerFirstPerson7 = false;
    if (pActor == g_player_011dea3c && !g_player_011dea3c->PlayerCharacter_IsActually3rdPerson())
        bPlayerFirstPerson7 = true;

    if (bPlayerFirstPerson7)
    {
        int iSound = 0x4109;
        if (pImpactX)
        {
            kHandle_ = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(pImpactX->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), static_cast<unsigned int>(iSound)));
            kHandle_.SetVolume(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
        if (pImpact_)
        {
            kHandle_ = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(pImpact_->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), static_cast<unsigned int>(iSound)));
            kHandle_.SetVolume(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
    }
    else
    {
        if (!FUN_0082eca0(pImpactX, kPosOut, 1.0f) && !FUN_0082eca0(pImpact_, kPosOut, 1.0f))
            return;
        int iSound2 = 0x410a;
        if (pImpactX)
        {
            kHandle_ = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(pImpactX->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), static_cast<unsigned int>(iSound2)));
            kHandle_.SetPosition(kPosOut.x, kPosOut.y, kPosOut.z);
            kHandle_.SetObjectToFollow(reinterpret_cast<NiAVObject*>(pActor->Get3D()));
            kHandle_.SetVolume(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
        if (pImpact_)
        {
            kHandle_ = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->GetSoundHandleByFormID_00ad73b0(pImpact_->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), static_cast<unsigned int>(iSound2)));
            kHandle_.SetPosition(kPosOut.x, kPosOut.y, kPosOut.z);
            kHandle_.SetObjectToFollow(reinterpret_cast<NiAVObject*>(pActor->Get3D()));
            kHandle_.SetVolume(0.95f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
            kHandle_.Play(0);
        }
    }
}

namespace fnv_00839ab0 {

struct DataHandlerFootstep
{
    BGSImpactData* FUN_004616c0(const char* pEditorID);
};
extern DataHandlerFootstep* g_dataHandler_011c3f2c;

extern unsigned char g_bFootstepsInit_011dd85c;
extern BGSImpactData* g_aapkFootstepImpacts_011dd650[13][10];
extern const char* g_apszFootstepTypes_011a18bc[10];
extern int g_aiMaterialFallback_011a17c4[13];

const char* __cdecl ImpactMixer_GetMaterialSoundName(int iMaterial);
int __cdecl BSsprintf(char* pBuffer, unsigned int uiSize, const char* pFormat, ...);

static const char s_szFootstepFormat[] = "FST%s%s";
static const char s_szDefaultFootstep[] = "FSTConcSolidWalkR";
extern const char g_szFootstepInitEnd[] = "";

// Builds each material/type footstep impact name, looks it up via the data handler with fallbacks, and stores the result in g_aapkFootstepImpacts_011dd650.
// @fnv 0x00839ab0
void __cdecl InitFootstepImpacts()
{
    if (g_bFootstepsInit_011dd85c)
        return;
    else
        g_bFootstepsInit_011dd85c = 1;

    char acNameLoc[0x104];
    int iUnusedLoc = 0;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            BSsprintf(acNameLoc, 0x103, s_szFootstepFormat, ImpactMixer_GetMaterialSoundName(i), g_apszFootstepTypes_011a18bc[j]);
            g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(acNameLoc);
            if (!g_aapkFootstepImpacts_011dd650[i][j] && g_aiMaterialFallback_011a17c4[i] != 13)
            {
                BSsprintf(acNameLoc, 0x103, s_szFootstepFormat, ImpactMixer_GetMaterialSoundName(g_aiMaterialFallback_011a17c4[i]),
                             g_apszFootstepTypes_011a18bc[j]);
                g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(acNameLoc);
                if (!g_aapkFootstepImpacts_011dd650[i][j] &&
                    g_aiMaterialFallback_011a17c4[g_aiMaterialFallback_011a17c4[i]] != 13)
                {
                    BSsprintf(acNameLoc, 0x103, s_szFootstepFormat,
                                 ImpactMixer_GetMaterialSoundName(g_aiMaterialFallback_011a17c4[g_aiMaterialFallback_011a17c4[i]]),
                                 g_apszFootstepTypes_011a18bc[j]);
                    g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(acNameLoc);
                }
            }
            if (!g_aapkFootstepImpacts_011dd650[i][j])
                g_aapkFootstepImpacts_011dd650[i][j] = g_dataHandler_011c3f2c->FUN_004616c0(s_szDefaultFootstep);
        }
    }
}
}  // namespace fnv_00839ab0

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

// Maps a material type and two size values to a material name string via DAT_011c3f2c->FUN_004616c0, returning the resulting id.
// @fnv 0x00839e00
// src: XBOX_PDB 0x00839e00
int __cdecl ImpactMixer_GetSoundForType(int aiMaterialType, float afSizeA, float afSizeB)
{
    int result = 0;

    switch (aiMaterialType)
    {
    case 0:
    case 15:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneStatic);
        }
        else if (afSizeA < *DAT_011dd9c8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneSmall);
        }
        else if (afSizeA < *DAT_011dd9b0.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CStoneLarge);
        }
        break;
    case 2:
        if (afSizeA < *DAT_011dd918.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CEarthSmall);
        }
        else if (afSizeA < *DAT_011dd9bc.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CEarthMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CEarthLarge);
        }
        break;
    case 4:
        if (afSizeA < DAT_01034208)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGrassSmall);
        }
        else if (afSizeA < DAT_01073568)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGrassMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGrassLarge);
        }
        break;
    case 5:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            if (afSizeA < DAT_01032980)
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalStaticL);
            }
            else if (afSizeA < *DAT_011dd8f4.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSmallL);
            }
            else if (afSizeA < *DAT_011dd8cc.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalMediumL);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalLargeL);
            }
        }
        else
        {
            if (afSizeA < DAT_01032980)
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalStaticH);
            }
            else if (afSizeA < *DAT_011dd8f4.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSmallH);
            }
            else if (afSizeA < *DAT_011dd8cc.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalMediumH);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalLargeH);
            }
        }
        break;
    case 9:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodStatic);
        }
        else if (afSizeA < *DAT_011dd930.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodSmall);
        }
        else if (afSizeA < *DAT_011dd9d8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodLarge);
        }
        break;
    case 1:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericClothL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericClothH);
        }
        break;
    case 6:
        result = DAT_011c3f2c->FUN_004616c0(kStr_COrganicSmall);
        break;
    case 7:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            if (afSizeA < *DAT_011dd9a0.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinSmallL);
            }
            else if (afSizeA < *DAT_011dd924.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinMediumL);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinLargeL);
            }
        }
        else
        {
            if (afSizeA < *DAT_011dd9a0.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinSmallH);
            }
            else if (afSizeA < *DAT_011dd924.Setting_Float_00403e20())
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinMediumH);
            }
            else
            {
                result = DAT_011c3f2c->FUN_004616c0(kStr_PHYSkinLargeH);
            }
        }
        break;
    case 3:
        if (afSizeA < DAT_01034208)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGlassSmall);
        }
        else if (afSizeA < DAT_01015a38)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGlassMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CGlassLarge);
        }
        break;
    case 8:
        if (afSizeA < DAT_01034208)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodSmall);
        }
        else if (afSizeA < DAT_01015a38)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_CWoodLarge);
        }
        break;
    case 13:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYChain);
        break;
    case 10:
        result = DAT_011c3f2c->FUN_004616c0(kStr_CSpecialHeavyStone);
        break;
    case 11:
        result = DAT_011c3f2c->FUN_004616c0(kStr_CSpecialHeavyMetal);
        break;
    case 12:
        result = DAT_011c3f2c->FUN_004616c0(kStr_CSpecialHeavyWood);
        break;
    case 16:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowStatic);
        }
        else if (afSizeA < *DAT_011dd8f4.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowSmall);
        }
        else if (afSizeA < *DAT_011dd8cc.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalHollowLarge);
        }
        break;
    case 17:
        if (afSizeA < DAT_01032980)
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetStatic);
        }
        else if (afSizeA < *DAT_011dd8f4.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetSmall);
        }
        else if (afSizeA < *DAT_011dd8cc.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetMedium);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYGenericMetalSheetLarge);
        }
        break;
    case 18:
        break;
    case 19:
        result = 0;
        break;
    case 20:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalBodyL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalBodyH);
        }
        break;
    case 21:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalSolidL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalSolidH);
        }
        break;
    case 22:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalHollowL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYVehicleMetalHollowH);
        }
        break;
    case 23:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBarrelL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBarrelH);
        }
        break;
    case 24:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBottleL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBottleH);
        }
        break;
    case 25:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYCanSodaL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYCanSodaH);
        }
        break;
    case 26:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponPistolL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponPistolH);
        }
        break;
    case 27:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponRifleL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYWeaponRifleH);
        }
        break;
    case 28:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYShoppingCartL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYShoppingCartH);
        }
        break;
    case 29:
        if (afSizeB < *DAT_011dd8e8.Setting_Float_00403e20())
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYLunchboxL);
        }
        else
        {
            result = DAT_011c3f2c->FUN_004616c0(kStr_PHYLunchboxH);
        }
        break;
    case 30:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBabyRattle);
        break;
    case 31:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYRubberBall);
        break;
    case 14:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYBottlecaps);
        break;
    case 32:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYChainlink);
        break;
    case 33:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYTile);
        break;
    case 34:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYCarpet);
        break;
    case 35:
        result = DAT_011c3f2c->FUN_004616c0(kStr_PHYTumbleweed);
        break;
    }
    return result;
}


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
bool FUN_0082eca0(TESSound* sound, NiPoint3 pos, float volume);

// @fnv 0x0083a930
void PlayWeaponImpactSound(TESObjectREFR* ref, int type)
{
    AutoMemHelper ctx(0xb, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 0x6a3);
    NiPoint3 pos = reinterpret_cast<const NiPoint3&>(*static_cast<const TESObjectREFR*>(ref)->GetPos());
    float value = *DAT_011dd900.Setting_Float_00403e20();
    bool bUnused = false;
    Actor* actor = dynamic_cast<Actor*>(ref);
    if (actor && actor->FUN_008d8520())
    {
        BSSoundHandle sound;
        S_0083a930_EntryData* entry = reinterpret_cast<S_0083a930_Process*>(actor->FUN_008d8520())->GetWeaponInfo();
        TESBoundObject* invObject = entry ? entry->FUN_0044ddc0() : 0;
        TESObjectWEAP* weapon = invObject ? dynamic_cast<TESObjectWEAP*>(invObject) : 0;
        if (weapon)
        {
            TESSound* snd = 0;
            switch (type)
            {
            case 9:
                snd = weapon->GetField238();
                break;
            case 10:
                snd = weapon->GetField23C();
                break;
            }
            if (!snd || !FUN_0082eca0(snd, pos, 1.0f))
                return;
            bool sneaking = actor->FUN_004997b0();
            if (actor == DAT_011dea3c)
            {
                sound = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(snd->TESSound_GetFilename(), 0x80004101, reinterpret_cast<unsigned int>(snd)));
            }
            else
            {
                sound = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(snd->TESSound_GetFilename(), 0x4102, reinterpret_cast<unsigned int>(snd)));
                sound.SetPosition(pos.x, pos.y, pos.z);
                sound.SetObjectToFollow(reinterpret_cast<NiAVObject*>(ref->GetNiNode()));
            }
            if (sneaking)
                sound.SetVolume(DAT_010231a8);
            else
                sound.SetVolume(1.0f);
            sound.Play(false);
        }
    }
}

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

struct ListenerOps
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual const NiPoint3& GetPosition();
};
// The shared header lacks this getter; __fastcall supplies its this pointer in ECX.
ListenerOps* __fastcall GetAudioListener(BSAudio* audio);

struct SoundOps
{
    unsigned char GetField45();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
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
// These no-argument actor queries are not declared by the shared header.
// __fastcall passes the actor in ECX, matching their member-call convention.
bool __fastcall IsFootstepRunning(Actor* actor);
bool __fastcall HasPowerArmorFootsteps(Actor* actor);
bool __fastcall HasArmorFootsteps(Actor* actor);


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
// Selects a footstep sound for the given foot from the cell material and actor state, then plays it at the actor position or in first person.
// @fnv 0x00837cc0
void PlayFootstepSound(FootstepActor* apActor, int foot)
{
    bool pos;
    SoundOps* memory;
    float armor;
    AutoMemHelper range(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 735);
    if (Interface_IsInMenuMode())
        return;
    NiPoint3 firstPerson = reinterpret_cast<const NiPoint3&>(apActor->GetPos());
    BSSoundHandle primary;
    BSSoundHandle secondary;
    memory = 0;
    SoundOps* sound = 0;
    pos = false;
    float distance = *DAT_011dd900.Setting_Float_00403e20();
    if (Main_GetSceneIsComplex())
        distance /= 2.0;
    armor = 0.0f;
    if (GetAudioListener(BSAudio::BSAudio_QInstance()))
    {
        NiPoint3 delta = reinterpret_cast<const NiPoint3&>(GetAudioListener(BSAudio::BSAudio_QInstance())->GetPosition());
        delta.Subtract(firstPerson);
        armor = delta.FUN_00457990();
        if (delta.FUN_00457990() > distance)
            return;
    }
    if (apActor->IsActor())
    {
        Actor* actorOps =
            reinterpret_cast<Actor*>(dynamic_cast<Actor*>(reinterpret_cast<TESObjectREFR*>(apActor)));
        if (actorOps->HasHealth(false))
            return;
        if (actorOps->IsCreature())
        {
            TESBoundObject* base = reinterpret_cast<TESBoundObject*>(reinterpret_cast<Actor*>(apActor)->BGSSaveFormBuffer_GetForm());
            TESCreature* creature = dynamic_cast<TESCreature*>(base);
            SoundOps* creatureSound = creature->PickCreatureSound(foot);
            memory = creatureSound;
            if (memory && armor <= memory->GetField45() * 100)
            {
                primary = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0(memory->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), static_cast<unsigned int>(266)));
            }
            primary.SetPosition(firstPerson.x, firstPerson.y, firstPerson.z);
            if (creature->Return_0())
                primary.SetObjectToFollow(reinterpret_cast<NiAVObject*>(creature->Return_0()));
            primary.SetVolume(0.98f);
            primary.Play(0);
        }
        else
        {
            int materialIndex = 0;
            FootstepCell* cell = g_TES_011dea10->FUN_005f36f0();
            if (!cell)
                cell =
                    g_dataHandler_011c3f2c->FUN_00461bc0(firstPerson.x, firstPerson.y, g_TES_011dea10->FUN_004fd3e0(0));
            bool soundType = false;
            bool movingActor = false;
            if (!actorOps->IsSwimming_005a2030() && cell && firstPerson.z < actorOps->GetRelevantWaterHeight() &&
                ((cell->FUN_00425fd0() && cell->FUN_004518e0()) || !cell->FUN_00425fd0()))
                soundType = true;
            Actor* material = actorOps;
            if (reinterpret_cast<SkinOps*>(material->FUN_009306d0())->bhkCharacterController_GetOnStairs())
                movingActor = true;
            if (!g_TES_011dea10->FUN_005f36f0() && cell && cell->TESObjectCELL_GetLand())
            {
                MaterialRecord* result;
                FootstepQuery height;
                reinterpret_cast<NavOps*>(cell->TESObjectCELL_GetLand())->TESObjectLAND_GetCoordData(&height, reinterpret_cast<NiPoint3*>(&firstPerson), 1);
                result = cell->TESObjectCELL_GetLand()->TESObjectLAND_GetMainTexture_0053a630(height.materialKind, height.triangle);
                float record = 0.0f;
                materialIndex = 0;
                if (soundType)
                    materialIndex = 8;
                else if (material && reinterpret_cast<SkinOps*>(material->FUN_009306d0()) &&
                         reinterpret_cast<SkinOps*>(material->FUN_009306d0())->material.FUN_0059bb30() != 36)
                    materialIndex = reinterpret_cast<SkinOps*>(material->FUN_009306d0())->material.FUN_0059bb30();
                else if (result)
                {
                    materialIndex = result->GetField1C();
                    if (cell->TESObjectCELL_GetLandHeight(reinterpret_cast<NiPoint3*>(&firstPerson), &record))
                        firstPerson.z = record;
                }
            }
            else
            {
                if (soundType)
                    materialIndex = 8;
                else if (material && reinterpret_cast<SkinOps*>(material->FUN_009306d0()))
                    materialIndex = reinterpret_cast<SkinOps*>(material->FUN_009306d0())->material.FUN_0059bb30();
            }
            if (foot > 1)
                foot -= 2;
            int special = foot == 0;
            int water = 0;
            if (actorOps->FUN_004997b0())
                special = foot ? 4 : 5;
            else if (movingActor)
                special = foot ? 6 : 7;
            else if (IsFootstepRunning(actorOps))
                special = foot ? 2 : 3;
            water = GetTypeValue(materialIndex);
            memory = DAT_011dd650[water].sounds[special];
            if (HasPowerArmorFootsteps(actorOps))
            {
                if (!DAT_011dd860 || !DAT_011dd864)
                {
                    DAT_011dd864 =
                        reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorPowerRightName));
                    DAT_011dd860 =
                        reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorPowerLeftName));
                }
                sound = foot ? DAT_011dd860 : DAT_011dd864;
            }
            else if (HasArmorFootsteps(actorOps))
            {
                if (!DAT_011dd868 || !DAT_011dd86c)
                {
                    DAT_011dd86c = reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorRightName));
                    DAT_011dd868 = reinterpret_cast<SoundOps*>(g_dataHandler_011c3f2c->FUN_004616c0(armorLeftName));
                }
                sound = foot ? DAT_011dd868 : DAT_011dd86c;
            }
            if (apActor == g_player_011dea3c && !g_player_011dea3c->PlayerCharacter_IsActually3rdPerson())
                pos = true;
            if (pos)
            {
                unsigned int flags = 0x4109;
                if (memory)
                {
                    primary = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(memory->TESSound_GetFilename(), flags, reinterpret_cast<unsigned int>(memory)));
                    primary.SetVolume(*DAT_011dd988.Setting_Float_00403e20());
                    primary.Play(0);
                }
                if (sound)
                {
                    secondary = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(sound->TESSound_GetFilename(), flags, reinterpret_cast<unsigned int>(sound)));
                    secondary.SetVolume(*DAT_011dd988.Setting_Float_00403e20());
                    secondary.Play(0);
                }
            }
            else
            {
                unsigned int flags = 0x410a;
                if (memory && armor <= memory->GetField45() * 100)
                {
                    primary = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(memory->TESSound_GetFilename(), flags, reinterpret_cast<unsigned int>(memory)));
                    primary.SetPosition(firstPerson.x, firstPerson.y, firstPerson.z - 128.0);
                    if (apActor->Get3D())
                        primary.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apActor->Get3D()));
                    primary.SetVolume(FUN_00476b70(0.9f, 1.0f));
                    primary.Play(0);
                }
                if (sound && armor <= sound->GetField45() * 100)
                {
                    secondary = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(sound->TESSound_GetFilename(), flags, reinterpret_cast<unsigned int>(sound)));
                    secondary.SetPosition(firstPerson.x, firstPerson.y, firstPerson.z - 128.0);
                    if (apActor->Get3D())
                        secondary.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apActor->Get3D()));
                    secondary.SetVolume(1.0 - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
                    secondary.Play(0);
                }
            }
        }
    }
}





// The shared header lacks this getter; __fastcall supplies its this pointer in ECX.
unsigned int __fastcall GetWeaponBlockSound(TESObjectWEAP* weapon);

float BSMIN(float a, float b);
float BSMAX_00404010(float a, float b);

// @fnv 0x008397f0
void PlayBlockSound(int aUnused, TESObjectWEAP* pObject, float x0, float y0, float z0, float x1, float y1,
                    float z1)
{
    BSSoundHandle p;
    if (pObject != 0 && GetWeaponBlockSound(pObject) != 0)
    {
        p = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->BSAudio_GetSoundHandleByFilename(((TESSound*)GetWeaponBlockSound(pObject))->TESSound_GetFilename(), 0x182,
                                                          GetWeaponBlockSound(pObject)));
    }
    else
    {
        int weaponType = (pObject != 0) ? pObject->FUN_00446390() : -1;
        switch (weaponType)
        {
        case -1:
            p = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->GetSoundHandleByEditorID("WPNBlockHand", 0x182));
            break;
        default:
            p = *reinterpret_cast<BSSoundHandle*>(&BSAudio::GetSingleton()->GetSoundHandleByEditorID("WPNBlockMelee", 0x182));
            break;
        }
    }
    NiPoint3 v;
    v.x = (float)(BSMIN(x0, x1) + (BSMAX_00404010(x0, x1) - BSMIN(x0, x1)) / 2.0);
    v.y = (float)(BSMIN(y0, y1) + (BSMAX_00404010(y0, y1) - BSMIN(y0, y1)) / 2.0);
    v.z = (float)(BSMIN(z0, z1) + (BSMAX_00404010(z0, z1) - BSMIN(z0, z1)) / 2.0);
    p.SetPosition(v.x, v.y, v.z);
    p.Play(false);
}

extern SoundOps* DAT_011dd870;
extern SoundOps* DAT_011dd874;
// Plays a footstep or jump sound for ref, choosing the material sound and optional armor/jump sound based on the surface and actor state.
// @fnv 0x00838780
// src: XBOX_PDB 0x00838780
void __cdecl ImpactMixer_PlayJump(TESObjectREFR* apRefr)
{
    AutoMemHelper memCtx5(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp", 941);
    if (Interface_IsInMenuMode())
        return;
    NiPoint3 pos20 = reinterpret_cast<const NiPoint3&>(*static_cast<const TESObjectREFR*>(apRefr)->GetPos());
    BSSoundHandle handle12;
    BSSoundHandle handle6;
    SoundOps* impact1 = 0;
    SoundOps* second9 = 0;
    bool isBaby9 = false;
    float scale2 = *DAT_011dd900.Setting_Float_00403e20();
    if (Main_GetSceneIsComplex())
        scale2 /= 2.0;
    float distBX = 0.0f;
    if (GetAudioListener(BSAudio::BSAudio_QInstance()))
    {
        NiPoint3 vec = reinterpret_cast<const NiPoint3&>(GetAudioListener(BSAudio::BSAudio_QInstance())->GetPosition());
        vec.Subtract(pos20);
        distBX = vec.FUN_00457990();
        if (scale2 < vec.FUN_00457990())
            return;
    }
    if (((FootstepActor*)apRefr)->IsActor())
    {
        Actor* pActor = (Actor*)dynamic_cast<Actor*>(apRefr);
        if (pActor->HasHealth(false))
            return;
        if (pActor->IsCreature())
        {
            TESBoundObject* bolt6 = reinterpret_cast<TESBoundObject*>(((Actor*)apRefr)->BGSSaveFormBuffer_GetForm());
            TESCreature* creature6 = dynamic_cast<TESCreature*>(bolt6);
            SoundOps* csnd = creature6->PickCreatureSound(0x14);
            impact1 = csnd;
            if (impact1)
            {
                if ((float)(impact1->GetField45() * 100) >= distBX)
                {
                    handle12 = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0(impact1->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), static_cast<unsigned int>(0x10a)));
                }
            }
            handle12.SetPosition(pos20.x, pos20.y, pos20.z);
            if (creature6->Return_0())
                handle12.SetObjectToFollow(reinterpret_cast<NiAVObject*>(creature6->Return_0()));
            handle12.SetVolume(0.98f);
            handle12.Play(0);
        }
        else
        {
            int material6 = 0;
            FootstepCell* cell8 = g_TES_011dea10->FUN_005f36f0();
            if (!cell8)
                cell8 = g_dataHandler_011c3f2c->FUN_00461bc0(pos20.x, pos20.y, g_TES_011dea10->FUN_004fd3e0(0));
            bool flagWater6 = false;
            bool local2 = false;
            if (!pActor->IsSwimming_005a2030())
            {
                if (cell8 && pos20.z < pActor->GetRelevantWaterHeight())
                {
                    if ((cell8->FUN_00425fd0() && cell8->FUN_004518e0()) || !cell8->FUN_00425fd0())
                        flagWater6 = true;
                }
            }
            Actor* pq = pActor;
            if (reinterpret_cast<SkinOps*>(pq->FUN_009306d0())->bhkCharacterController_GetOnStairs())
                local2 = true;
            if (!g_TES_011dea10->FUN_005f36f0() && cell8 && cell8->TESObjectCELL_GetLand())
            {
                FootstepQuery query4;
                cell8->TESObjectCELL_GetLand()->TESObjectLAND_GetCoordData((NavQueryResult*)&query4, (NiPoint3*)&pos20, 1);
                MaterialRecord* localA = cell8->TESObjectCELL_GetLand()->TESObjectLAND_GetMainTexture_0053a630(query4.materialKind, query4.triangle);
                float heightStepB = 0.0f;
                material6 = 0;
                if (flagWater6)
                    material6 = 8;
                else if (pq && reinterpret_cast<SkinOps*>(pq->FUN_009306d0()) && reinterpret_cast<SkinOps*>(pq->FUN_009306d0())->material.FUN_0059bb30() != 0x24)
                    material6 = reinterpret_cast<SkinOps*>(pq->FUN_009306d0())->material.FUN_0059bb30();
                else if (localA)
                {
                    material6 = localA->GetField1C();
                    if (cell8->TESObjectCELL_GetLandHeight((NiPoint3*)&pos20, &heightStepB))
                        pos20.z = heightStepB;
                }
            }
            else
            {
                if (flagWater6)
                    material6 = 8;
                else if (pq && reinterpret_cast<SkinOps*>(pq->FUN_009306d0()))
                    material6 = reinterpret_cast<SkinOps*>(pq->FUN_009306d0())->material.FUN_0059bb30();
            }
            int idx11 = 9;
            int typeY = 0;
            typeY = GetTypeValue(material6);
            impact1 = DAT_011dd650[typeY].sounds[idx11];
            if (HasPowerArmorFootsteps(pActor))
            {
                if (!DAT_011dd874)
                    DAT_011dd874 = (SoundOps*)g_dataHandler_011c3f2c->FUN_004616c0("FSTJumpPower");
                second9 = DAT_011dd870;
            }
            else if (HasArmorFootsteps(pActor))
            {
                if (!DAT_011dd870)
                    DAT_011dd870 = (SoundOps*)g_dataHandler_011c3f2c->FUN_004616c0("FSTJumpArmor");
                second9 = DAT_011dd870;
            }
            if (apRefr == (TESObjectREFR*)g_player_011dea3c)
            {
                if (!g_player_011dea3c->PlayerCharacter_IsActually3rdPerson())
                    isBaby9 = true;
            }
            if (isBaby9)
            {
                int flags = 0x4109;
                if (impact1)
                {
                    handle12 = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(impact1->TESSound_GetFilename(), flags, reinterpret_cast<unsigned int>(impact1)));
                    handle12.SetVolume(*DAT_011dd988.Setting_Float_00403e20());
                    handle12.Play(0);
                }
                if (second9)
                {
                    handle6 = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(second9->TESSound_GetFilename(), flags, reinterpret_cast<unsigned int>(second9)));
                    handle6.SetVolume(*DAT_011dd988.Setting_Float_00403e20());
                    handle6.Play(0);
                }
            }
            else
            {
                int flags2 = 0x410a;
                if (!FUN_0082eca0((TESSound*)impact1, pos20, 1.0f) && !FUN_0082eca0((TESSound*)second9, pos20, 1.0f))
                    return;
                if (impact1)
                {
                    if ((float)(impact1->GetField45() * 100) >= distBX)
                    {
                        handle12 = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(impact1->TESSound_GetFilename(), flags2, reinterpret_cast<unsigned int>(impact1)));
                        handle12.SetPosition(pos20.x, pos20.y, (float)(pos20.z - 128.0));
                        if (apRefr->GetNiNode())
                            handle12.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apRefr->GetNiNode()));
                        handle12.SetVolume(FUN_00476b70(0.9f, 1.0f));
                        handle12.Play(0);
                    }
                }
                if (second9)
                {
                    if ((float)(second9->GetField45() * 100) >= distBX)
                    {
                        handle6 = *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->BSAudio_GetSoundHandleByFilename(second9->TESSound_GetFilename(), flags2, reinterpret_cast<unsigned int>(second9)));
                        handle6.SetPosition(pos20.x, pos20.y, (float)(pos20.z - 128.0));
                        if (apRefr->GetNiNode())
                            handle6.SetObjectToFollow(reinterpret_cast<NiAVObject*>(apRefr->GetNiNode()));
                        handle6.SetVolume(1.0f - FUN_00476b70(0.0f, g_fFootstepRand_0101e2bc));
                        handle6.Play(0);
                    }
                }
            }
        }
    }
}

namespace ImpactSound {

typedef NiPoint3 ImpactPoint;

struct ImpactMemContext
{
    int iOldContext;
    ImpactMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~ImpactMemContext();
};

struct ImpactTimer
{
    int iData;
    ImpactTimer();
    ~ImpactTimer();
    void BSCriticalSection_Enter(const char* apName);
    void FUN_004538c0();
};

struct ImpactFormType
{
    int iData;
    ImpactFormType();
    int CFilter_GetLayer();
};

struct ImpactObject
{
    float FUN_0062ab20();
    ImpactFormType bhkWorldObject_GetCollisionFilter();
};

struct ImpactData
{
    ImpactPoint kPos;
    float fImpulse;
    int iUnk10;
    char cMaterialA;
    char cMaterialB;
    short sUnk16;
    unsigned int uiKey;
    ImpactObject* pObjectA;
    ImpactObject* pObjectB;
};

struct ImpactSoundForm
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct ImpactDataHandler
{
    ImpactSoundForm* FUN_004616c0(const char* apEditorID);
};


struct ImpactHistory
{
    bool FUN_00853130(unsigned int auiKey, unsigned int& arTime);
    void FUN_00844700(unsigned int auiKey, unsigned int auiTime);
    void* FUN_004b9ba0();
    void FUN_006b7f20(void*& arIter, unsigned int& arKey, int& arTime);
    bool RemoveKey(unsigned int auiKey);
    void FUN_00438af0();
};

struct ImpactIntSetting
{
    int* Setting_Int();
};

struct ImpactClock
{
    unsigned int FUN_00825c00();
};

extern ImpactHistory DAT_011dd948;
extern ImpactIntSetting DAT_011dd968;
extern ImpactClock DAT_011f6394;
extern ImpactPoint DAT_011dd958;
extern ImpactDataHandler* DAT_011c3f2c;
extern const double DAT_010179e0;

ImpactSoundForm* __cdecl ImpactMixer_GetSoundForType(int aiMaterial, float afMass, float afImpulse);
bool __cdecl FloatEQ(float afValue, float afTarget, float afRange);
bool __cdecl FUN_0082eca0(ImpactSoundForm* apForm, ImpactPoint akPos, float afScale);

static const char kCollisionSourcePath[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Audio\\ImpactMixer.cpp";
static const char s_szTimerName[] = "ImpactMixer::PlayCollisionSound";
static const char s_szShotgun[] = "PHYCasingShotgun";
static const char s_szPistol[] = "PHYCasingPistol";
static const char s_szRifle[] = "PHYCasingRifle";

// Selects impact sounds from collision materials and object masses, adjusts frequency and volume from impulse, and prunes impact history.
// @fnv 0x00837550
// src: XBOX_PDB 0x00837550
void ImpactMixer_PlayCollisionSound(ImpactData* apImpact)
{
    ImpactMemContext kMemContext(0xb, true, kCollisionSourcePath, 0x234);
    if (apImpact->pObjectA == apImpact->pObjectB && apImpact->pObjectA)
        return;
    static ImpactTimer s_kTimer;
    s_kTimer.BSCriticalSection_Enter(s_szTimerName);
    float fScaledImpulseRes = apImpact->fImpulse * 0.014287499710917473;
    float fWaterLevelItem = apImpact->fImpulse / DAT_010179e0;
    unsigned int uiFlagsTmp = 0;
    if (apImpact->cMaterialA == 0x24 && apImpact->cMaterialB == 6)
        fWaterLevelItem *= 4.0;
    {
        float fMassASample = apImpact->pObjectA ? apImpact->pObjectA->FUN_0062ab20() : 5.0f;
        float fMassOfB = apImpact->pObjectB ? apImpact->pObjectB->FUN_0062ab20() : 5.0f;
        bool bCasingVal = false;
        ImpactSoundForm* pSoundA = 0;
        ImpactSoundForm* pSoundBNew = 0;
        if ((apImpact->pObjectA && apImpact->pObjectA->bhkWorldObject_GetCollisionFilter().CFilter_GetLayer() == 0x19) ||
            (apImpact->pObjectB && apImpact->pObjectB->bhkWorldObject_GetCollisionFilter().CFilter_GetLayer() == 0x19))
            bCasingVal = true;
        if (!bCasingVal)
        {
            pSoundA = ImpactMixer_GetSoundForType(apImpact->cMaterialA, fMassASample, apImpact->fImpulse);
            pSoundBNew = ImpactMixer_GetSoundForType(apImpact->cMaterialB, fMassOfB, apImpact->fImpulse);
        }
        else
        {
            uiFlagsTmp = 0x80;
            float fMass = fMassASample > fMassOfB ? fMassASample : fMassOfB;
            if (fMass < 1.0)
                pSoundA = DAT_011c3f2c->FUN_004616c0(s_szShotgun);
            else if (FloatEQ(fMass, 2.0f, 0.25f))
                pSoundA = DAT_011c3f2c->FUN_004616c0(s_szPistol);
            else
                pSoundA = DAT_011c3f2c->FUN_004616c0(s_szRifle);
            pSoundBNew = 0;
        }
        if (!FUN_0082eca0(pSoundA, apImpact->kPos, 1.0f) && !FUN_0082eca0(pSoundBNew, apImpact->kPos, 1.0f))
        {
            s_kTimer.FUN_004538c0();
            return;
        }
        BSSoundHandle kHandleAResult;
        BSSoundHandle kHandleB;
        unsigned int uiNow = DAT_011f6394.FUN_00825c00();
        unsigned int uiLastTime = 0;
        if (DAT_011dd948.FUN_00853130(apImpact->uiKey, uiLastTime) &&
            uiNow - uiLastTime < (unsigned int)*DAT_011dd968.Setting_Int())
        {
            s_kTimer.FUN_004538c0();
            return;
        }
        else
        {
            DAT_011dd948.FUN_00844700(apImpact->uiKey, uiNow);
        }
        if (pSoundA && !(apImpact->cMaterialA == 7 && apImpact->cMaterialB == 7))
            kHandleAResult =
                *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0(pSoundA->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), uiFlagsTmp | 2 | 0x100 | 0x4000));
        if (pSoundBNew && !(apImpact->cMaterialA == 7 && apImpact->cMaterialB == 7))
            kHandleB =
                *reinterpret_cast<BSSoundHandle*>(&BSAudio::BSAudio_QInstance()->GetSoundHandleByFormID_00ad73b0(pSoundBNew->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), uiFlagsTmp | 2 | 0x100 | 0x4000));
        unsigned int uiFrequencyVal =
            (unsigned int)((1.0 - (apImpact->fImpulse / 400.0 > 1.0 ? 1.0 : apImpact->fImpulse / 400.0)) * 3000.0);
        float fVolumeLoc = uiFrequencyVal < 0x5dc ? 1.0 : (uiFrequencyVal - 4500.0) / -3000.0;
        if (pSoundA)
        {
            kHandleAResult.SetPriority(0xff);
            kHandleAResult.SetPosition(apImpact->kPos.x, apImpact->kPos.y, apImpact->kPos.z);
            kHandleAResult.SetStaticAttenuation(uiFrequencyVal);
            kHandleAResult.SetModFrequency(fVolumeLoc);
            kHandleAResult.Play(false);
        }
        if (pSoundBNew)
        {
            kHandleB.SetPriority(0xff);
            kHandleB.SetPosition(apImpact->kPos.x, apImpact->kPos.y, apImpact->kPos.z);
            kHandleB.SetStaticAttenuation(uiFrequencyVal);
            kHandleB.SetModFrequency(fVolumeLoc);
            kHandleB.Play(false);
        }
        DAT_011dd958 = apImpact->kPos;
    }
    int iMaxAge = *DAT_011dd968.Setting_Int() * 4;
    void* pIter = DAT_011dd948.FUN_004b9ba0();
    int iNowCur = DAT_011f6394.FUN_00825c00();
    unsigned int uiVisited = 0;
    while (pIter)
    {
        uiVisited++;
        unsigned int uiEntryKeyVal;
        int iEntryTime;
        DAT_011dd948.FUN_006b7f20(pIter, uiEntryKeyVal, iEntryTime);
        if (iNowCur - iEntryTime > iMaxAge)
        {
            DAT_011dd948.RemoveKey(uiEntryKeyVal);
            pIter = DAT_011dd948.FUN_004b9ba0();
        }
        if (uiVisited > 0x100)
        {
            DAT_011dd948.FUN_00438af0();
            pIter = 0;
        }
    }
    s_kTimer.FUN_004538c0();
}

}
