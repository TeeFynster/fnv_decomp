#include "../../../../include/BSSoundHandle.h"
#include "../../../../include/BSAudio.h"
#include "../../../../include/Menu.h"
#include "../../../../include/RouletteMenu.h"
#include "../../../../include/NiAVObject.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/TESDataHandler.h"
#include "../../../../include/NiMatrix3.h"
#include "../../../../include/Tile.h"
#include "../../../../include/ActorValueOwner.h"
#include "../../../../include/Bound.h"
#include "../../../../include/GO.h"
#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiUpdateData.h"
#include "../../../../include/SL.h"
#include "../../../../include/Setting.h"
#include "../../../../include/SettingT_GameSettingCollection_.h"

// roulettemenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/roulettemenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
// src/fallout/interface/menus/roulettemenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/roulettemenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
int __cdecl RouletteMenu_GetMenuID_();
extern unsigned int __cdecl GetRandomNumberInRange(int, int);
struct B006815c0
{
    B006815c0();
};
struct FUN_007b8fa0
{
    SL s;
    B006815c0 b;
    FUN_007b8fa0();
};
struct ListX
{
    ~ListX();
};
extern double DAT_01076340;
struct Proc_S
{
    void* GetNext();
};
Proc_S* __cdecl _FUN_004b7210();
extern RouletteMenu* DAT_011da878;
void SetRouletteMenuTile();
struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, const char*);
};
extern double const DAT_01023128;
extern double DAT_01076360;
extern char DAT_011a9448;
extern double DAT_01070e78;
extern GO g_011da8a0;
extern int DAT_011da86c;
struct BSSimpleListTESRaceSize
{
    int GetSize();
    bool IsEmpty();
};
void __cdecl FUN_004d5c60(int);
struct FUN_00559450_shell
{
    void* Modelloader_GetReferencedThis();
};
struct FUN_0073ac90_shell
{
    int* NiTPointerListBase_NiTPointerAllocator_unsigned_int_Tile_GetHead();
};
struct FUN_006317a0_shell
{
    void** AddEight(void* a, int b, float c, int d);
};
struct FUN_007b52d0_shell
{
    void* DereferenceIfNotNull(void* a);
};
extern float DAT_0102caf8;
struct S_007bf7a0_Val
{
    float f;
    char a;
    char b;
    char c;
    char d;
    char e;
    S_007bf7a0_Val(float f, char a, char b);
};
struct S_007bf7a0_Inner
{
    void NiAVObject_Update(S_007bf7a0_Val* v);
};
struct S_007bf7a0_Holder
{
    S_007bf7a0_Inner* Modelloader_GetReferencedThis();
};
extern S_007bf7a0_Holder DAT_011da8a0;
struct SettingString
{
    const char* String();
};
extern SettingString g_011d3e08;
struct NamedForm
{
    const char* GetFullName();
};
struct RoulettePlayerStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    NamedForm fullName;
};
struct RouletteBetStandIn
{
    int unk00;
    int iAmount;
};
extern RouletteBetStandIn* DAT_011da87c;
extern RoulettePlayerStandIn* DAT_011da880;
extern int DAT_011da870;
int __cdecl BSsprintf(char* buffer, int size, const char* format, ...);
static const char kNameFormat[] = "%s %s";
namespace RouletteCleanup {
struct Scene;
struct MenuRef
{
    Setting* TESCasino_GetModel(int);
};
struct Cache
{
    void ModelLoader_ReleaseFile(const char*);
};
struct Player
{
    void SetLastAntiCheatTime();
};
struct Scene
{
    void DetachAllChildren_00572160();
};
struct Pointer
{
    Scene* value;
    Scene* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(Scene*);
    ~Pointer();
};
struct Renderer
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void Detach(Scene*);
    void RemoveAllLights();
};
Renderer* FUN_00450b80(int);
struct Animation
{
    bool FUN_008256d0();
    void FUN_00470470();
    ~Animation();
};
struct Base
{
    virtual ~Base();
};
struct Entry
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    ~Entry();
};
extern Player* DAT_011dea3c;
extern MenuRef* DAT_011da880;
extern Cache* DAT_011c3b3c;
extern Pointer DAT_011da8d0, DAT_011da8a0;
extern void* DAT_011da87c;
extern void* DAT_011da878;
extern const char DAT_01075ff8[], DAT_01075fc4[], DAT_01070944[];
void FUN_00406d30(char*, unsigned int, const char*);
unsigned int BSstrlen(const char*);
// The shared BetSlot lacks the nontrivial destructor required by this cleanup
// function, so retain its local layout until the shared header supports it.
struct FUN_007b9020 : Base
{
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    Entry entries[159];
    Animation* animation;
    unsigned int unk3e7c;
    unsigned int unk3e80;
    unsigned int unk3e84;
    unsigned int unk3e88;
    unsigned int unk3e8c;
    unsigned int unk3e90;
    unsigned int unk3e94;
    unsigned int unk3e98;
    unsigned int unk3e9c;
    unsigned int unk3ea0;
    unsigned int unk3ea4;
    unsigned int unk3ea8;
    unsigned int unk3eac;
    unsigned int unk3eb0;
    unsigned int unk3eb4;
    unsigned int unk3eb8;
    unsigned int unk3ebc;
    unsigned int unk3ec0;
    unsigned int unk3ec4;
    unsigned int unk3ec8;
    unsigned int unk3ecc;
    unsigned int unk3ed0;
    unsigned int unk3ed4;
    unsigned int unk3ed8;
    unsigned int unk3edc;
    unsigned int unk3ee0;
    unsigned int unk3ee4;
    unsigned int unk3ee8;
    unsigned int unk3eec;
    unsigned int unk3ef0;
    unsigned int unk3ef4;
    unsigned int unk3ef8;
    unsigned int unk3efc;
    unsigned int unk3f00;
    unsigned int unk3f04;
    unsigned int unk3f08;
    unsigned int unk3f0c;
    unsigned int unk3f10;
    Scene* table;
    Scene* wheel;
    Scene* ball;
    Scene* nodes[10];
    Scene* materials[10];
    Scene* camera;
    Scene* light;
    Scene* target;
    Pointer pointer;
    Scene* group;
    Scene* markers[3];
    virtual ~FUN_007b9020();
};
// @fnv 0x007b9020
FUN_007b9020::~FUN_007b9020()
{
    DAT_011dea3c->SetLastAntiCheatTime();
    DAT_011c3b3c->ModelLoader_ReleaseFile(DAT_011da880->TESCasino_GetModel(9)->Name());
    DAT_011c3b3c->ModelLoader_ReleaseFile(DAT_01075ff8);
    DAT_011c3b3c->ModelLoader_ReleaseFile(DAT_01075fc4);
    DAT_011c3b3c->ModelLoader_ReleaseFile(DAT_011da880->TESCasino_GetModel(6)->Name());
    char* extension = 0;
    char path[260];
    FUN_00406d30(path, 260, DAT_011da880->TESCasino_GetModel(6)->Name());
    for (unsigned int index = 0; index < BSstrlen(path); index++)
    {
        if (path[index] == '.')
        {
            extension = &path[index];
            break;
        }
    }
    if (extension)
    {
        FUN_00406d30(extension, 15, DAT_01070944);
        DAT_011c3b3c->ModelLoader_ReleaseFile(path);
    }
    DAT_011da8d0.FUN_0066b0d0(0);
    FUN_00450b80(1)->Detach(DAT_011da8a0.Modelloader_GetReferencedThis());
    FUN_00450b80(1)->RemoveAllLights();
    DAT_011da8a0.Modelloader_GetReferencedThis()->DetachAllChildren_00572160();
    DAT_011da8a0.FUN_0066b0d0(0);
    table = 0;
    wheel = 0;
    ball = 0;
    DAT_011da8d0.FUN_0066b0d0(0);
    camera = 0;
    light = 0;
    target = 0;
    pointer.FUN_0066b0d0(0);
    if (animation && !animation->FUN_008256d0())
        animation->FUN_00470470();
    delete animation;
    group = 0;
    for (int marker = 0; marker < 3; marker++)
        markers[marker] = 0;
    for (int element = 0; element < 10; element++)
    {
        nodes[element] = 0;
        materials[element] = 0;
    }
    if (!animation->FUN_008256d0())
        animation->FUN_00470470();
    animation = 0;
    DAT_011da87c = 0;
    DAT_011da880 = 0;
    DAT_011da878 = 0;
}
}
struct ModelPath
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual const char* Path();
};
struct PathOwner
{
    ModelPath* TESCasino_GetModel(int);
};
struct ModelLoader
{
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;
struct Controller
{
    void* NiControllerManager_GetSequenceByName(const NiFixedString&);
    void FUN_0048fef0(float);
};
struct NiRTTI;
extern NiRTTI DAT_011f36ac;
struct SceneHolder
{
    SceneHolder& operator=(NiNode*);
    NiNode* Modelloader_GetReferencedThis();
};
extern SceneHolder g_011da8d0;
NiNode* __cdecl BSUtilities_GetObjectByName(NiNode*, const char*);
NiNode* __cdecl FUN_00450b80(int);
void __cdecl NiTimeController_StartAnimations(NiNode*);
int __cdecl strcpy_s(char*, unsigned int, const char*);
struct FUN_00733f50
{
    int formID;
    int amount;
    int unk08;
    FUN_00733f50();
};
struct RouletteBetEntry
{
    int amount;
    int number;
    int strip;
};
struct BetList
{
    RouletteBetEntry** FUN_006815c0();
    BetList* FUN_00726070();
    bool FUN_008256d0();
    void FUN_00726c60(RouletteBetEntry*&);
    void FUN_005ae3d0(RouletteBetEntry*&);
};
struct BetGeometry
{
    NiPoint3 position;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50;
    int unk54, unk58, unk5c, unk60;
};

struct PlayerForRoulette
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
    ActorValueOwner av;
    BetList* PlayerCharacter_GetCasinoDataList();
    bool IsCasinoAntiCheat();
    int GetAntiCheatTimeRemaining();
    int FUN_00575610(void*);
};
extern PlayerForRoulette* DAT_011dea3c;
struct CasinoData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int limit;
};
struct CasinoForRoulette
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    CasinoData* TESCasino_GetData();
    void* TESCasino_GetChipType();
};
struct PlayerVirtual
{
    virtual ~PlayerVirtual();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown0a();
    virtual void unknown0b();
    virtual void unknown0c();
    virtual void unknown0d();
    virtual void unknown0e();
    virtual void unknown0f();
    virtual void unknown10();
    virtual void unknown11();
    virtual void unknown12();
    virtual void unknown13();
    virtual void unknown14();
    virtual void unknown15();
    virtual void unknown16();
    virtual void unknown17();
    virtual void unknown18();
    virtual void unknown19();
    virtual void unknown1a();
    virtual void unknown1b();
    virtual void unknown1c();
    virtual void unknown1d();
    virtual void unknown1e();
    virtual void unknown1f();
    virtual void unknown20();
    virtual void unknown21();
    virtual void unknown22();
    virtual void unknown23();
    virtual void unknown24();
    virtual void unknown25();
    virtual void unknown26();
    virtual void unknown27();
    virtual void unknown28();
    virtual void unknown29();
    virtual void unknown2a();
    virtual void unknown2b();
    virtual void unknown2c();
    virtual void unknown2d();
    virtual void unknown2e();
    virtual void unknown2f();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void unknown33();
    virtual void unknown34();
    virtual void unknown35();
    virtual void unknown36();
    virtual void unknown37();
    virtual void unknown38();
    virtual void unknown39();
    virtual void unknown3a();
    virtual void unknown3b();
    virtual void unknown3c();
    virtual void unknown3d();
    virtual void unknown3e();
    virtual void unknown3f();
    virtual void unknown40();
    virtual void unknown41();
    virtual void unknown42();
    virtual void unknown43();
    virtual void unknown44();
    virtual void unknown45();
    virtual void unknown46();
    virtual void unknown47();
    virtual void unknown48();
    virtual void unknown49();
    virtual void unknown4a();
    virtual void unknown4b();
    virtual const char* GetName();
};

struct InterfaceRoulette
{
    Tile* CombatController_GetCombatState(const char*);
};
extern SettingString g_011d2274, g_011d2d24, g_011d3abc, g_011d2424, g_011d3594, g_011d3804, g_011d3168, g_011d3300,
    g_011d41e0, g_011d2c1c, g_011d2820, g_011d3354, g_011d487c, g_011d33fc;
extern const char DAT_01076274[], DAT_01049638[], DAT_01025cc4[], DAT_01076254[], DAT_01076200[], DAT_010761e4[];
extern float DAT_010162c0, DAT_0101e704;
extern double DAT_010704f0, DAT_010704e8;
Menu* __cdecl Tile_GetMenuByClass(int);
bool __cdecl QueueUIMessage(const char*, int, const char*, const char*, float, bool);
void __cdecl Warning_005b5e40(const char*);
float __stdcall FUN_00a01530(int);
Tile* __cdecl Tile_GetTileByName(Tile*, const char*);
Tile* __cdecl RouletteMenu_Create(RoulettePlayerStandIn* casino, int bet, int arg3, int exchange);
struct RouletteEntry
{
    int amount;
    int id;
    int objectIndex;
};
struct RouletteEntryNode
{
    RouletteEntry** FUN_006815c0();
    void FUN_0063f7b0();
    RouletteEntryNode* FUN_00726070();
};

struct Member08
{
    Member08();
    ~Member08();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct List08
{
    int item, next;
    List08();
    ~List08();
};
int __cdecl Tile_AddUserTrait(const char*, int);
extern const char DAT_01071ba0[];
extern const char DAT_01071b94[];
extern const char DAT_01071b88[];
extern const char DAT_01071b7c[];
extern const char DAT_01071b70[];
extern const char DAT_01073cc0[];
extern const char DAT_01071b64[];
extern const char DAT_01073cb4[];
extern int DAT_011daf6c;
extern int DAT_011daf60;
extern int DAT_011daf58;
extern int DAT_011daf64;
extern int DAT_011daf68;
extern int DAT_011daf78;
extern int DAT_011daf5c;
extern int DAT_011daf70;
struct FUN_007e6780 : Menu
{
    Member08 member54;
    List08 list84;
    FUN_007e6780();
    virtual ~FUN_007e6780();
};
int __fastcall NiAVObject_GetWorldTranslate(int);
namespace bf {
struct Slot
{
    NiPoint3 m_kPos;
    char pad[0x64 - 0xc];
};
}
// @fnv 0x007bf390
// src: XBOX_PDB 0x007bf390
int RouletteMenu::GetBetIndex()
{
    int i;
    for (i = 0; i < 0x90; i++)
    {
        NiPoint3 v = ((const NiPoint3*)NiAVObject_GetWorldTranslate(m_iNode))->operator-(reinterpret_cast<bf::Slot*>(&unk006c)[i].m_kPos);
        float f = v.Length();
        if (f <= m_afRadius[0])
            break;
    }
    if (i == 0x90)
    {
        for (; i < 0x9f; i++)
        {
            NiPoint3 v2 = ((const NiPoint3*)NiAVObject_GetWorldTranslate(m_iNode))->operator-(reinterpret_cast<bf::Slot*>(&unk006c)[i].m_kPos);
            float f2 = v2.Length();
            if (f2 <= m_afRadius[i - 0x8f])
                break;
        }
    }
    return i;
}
extern unsigned char DAT_011f426c;
extern double DAT_0106b168;
extern SettingT_GameSettingCollection_ DAT_011d3f4c;
extern SettingT_GameSettingCollection_ DAT_011d4dbc;
extern SettingT_GameSettingCollection_ DAT_011d4b88;
extern SettingT_GameSettingCollection_ DAT_011d264c;
extern SettingT_GameSettingCollection_ DAT_011d2dcc;
extern SettingT_GameSettingCollection_ DAT_011d32f4;
extern SettingT_GameSettingCollection_ DAT_011d2694;
extern SettingT_GameSettingCollection_ DAT_011d1df0;
extern SettingT_GameSettingCollection_ DAT_011d40c0;
extern SettingT_GameSettingCollection_ DAT_011d2d30;
int __cdecl FUN_00406d30(char*, unsigned int, const char*);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
struct BoundRes
{
    NiPoint3* FUN_006815c0();
};
NiAVObject* __cdecl BSUtilities_GetObjectByName(NiAVObject*, char*);
struct SubObj
{
    int unk00;
    int unk04;
    void FUN_005ae3d0(const int&);
};
struct Entry
{
    SubObj sub;
    int flag;
    int n2;
    NiPoint3 p;
    char code[8];
    char name[64];
};

void* __cdecl fnv_zlib_memset(void*, int, int);

extern float DAT_0101e704;
// @fnv 0x007bed70
// src: XBOX_PDB 0x007bed70
bool RouletteMenu::SetBet(int number)
{
    if (unk3fe4 >= 10 || number >= 159 || number < 0 || !unk3fe8)
        return false;
    BetList* k = reinterpret_cast<BetList*>(unk3e78);
    while (k && *k->FUN_006815c0())
    {
        if ((*k->FUN_006815c0())->number == number)
            return false;
        k = k->FUN_00726070();
    }
    NiUpdateData b(0.0f, false, false);
    // Raw storage avoids the shared NiPoint3 constructors in this unoptimized context.
    float l[3];
    *reinterpret_cast<NiPoint3*>(l) = reinterpret_cast<BetGeometry*>(&unk006c)[number].position;
    unsigned int e = sizeof(RouletteBetEntry);
    void* j = operator new(e);
    RouletteBetEntry* ba = j ? (fnv_zlib_memset(j, 0, e), static_cast<RouletteBetEntry*>(j)) : 0;
    ba->amount = unk3fe8;
    ba->number = number;
    ba->strip = unk3fe0;
    if (!unk3e78 || reinterpret_cast<BetList*>(unk3e78)->FUN_008256d0())
        reinterpret_cast<BetList*>(unk3e78)->FUN_00726c60(ba);
    else
        reinterpret_cast<BetList*>(unk3e78)->FUN_005ae3d0(ba);
    SetBetChip();
    ++unk3fe4;
    ++unk3fe0;
    unk3fec += unk3fe8;
    BSAudio::GetSingleton()->BSAudio_GetSoundHandleByEditorName("GAMERouletteIncreaseBet", 0x121).Play(false);
    if (unk3fe0 >= 13)
        unk3fe0 = 3;
    while (!IsEyesListBelowThreshold(unk3fe0) && unk3fe4 < 10)
    {
        ++unk3fe0;
        if (unk3fe0 >= 13)
            unk3fe0 = 3;
    }
    float c[3];
    if (unk3fe4 < 10 && unk3fec < unk4000)
    {
        *reinterpret_cast<NiPoint3*>(c) = reinterpret_cast<NiNode*>(static_cast<unsigned int>(g_011da8a0))->FUN_0043b4a0(2)->GetTranslate_0043c490();
        reinterpret_cast<NiNode*>(static_cast<unsigned int>(g_011da8a0))
            ->FUN_0043b4a0(unk3fe0)
            ->NiAVObject_SetTranslate_004bc1f0(c[0], c[1], 0.0f);
        reinterpret_cast<NiNode*>(static_cast<unsigned int>(g_011da8a0))
            ->FUN_0043b4a0(unk3fe0 + 10)
            ->NiAVObject_SetTranslate_004bc1f0(c[0], c[1], 0.0f);
        SetBetChip();
    }
    if (unk3fec + unk3fe8 > unk3ff0)
    {
        unk3fe8 = unk3ff0 - unk3fec;
        reinterpret_cast<Tile*>(DAT_011da878->m_pMaxBetTile)->SetTraitFloat(DAT_011da86c, 1.0f);
        reinterpret_cast<Tile*>(DAT_011da878->m_pMaxBetTile)->FUN_00700320(DAT_011da86c, unk3fe8);
        DAT_011da878->ApplyValueToChain(6, DAT_0101e704);
    }
    return true;
}
