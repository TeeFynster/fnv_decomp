
// src/fallout_shared/pathfinding/pathingdebuggeometry_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/pathfinding/pathingdebuggeometry.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/pathfinding/pathingdebuggeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingdebuggeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// FUN_00574400 - TESObjectREFR method, /Od /Oy- frame 0x44
struct Ref;
struct ExtraList;
struct Proc;
struct ObjX;
struct MagicSub
{
    void FUN_00824970();
};
struct Ref
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vt4c(int a);
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtc8(int a);
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual bool vtfc();
    virtual bool vt100();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vt1cc(int a, int b);
    virtual void vtbl116();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual void vtbl125();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void vtbl128();
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual void vtbl133();
    virtual void vtbl134();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual void vtbl139();
    virtual void vtbl140();
    virtual void vtbl141();
    virtual void vtbl142();
    virtual void vtbl143();
    virtual void vtbl144();
    virtual void vtbl145();
    virtual void vtbl146();
    virtual void vtbl147();
    virtual void vtbl148();
    virtual void vtbl149();
    virtual void vtbl150();
    virtual void vtbl151();
    virtual void vtbl152();
    virtual void vtbl153();
    virtual void vtbl154();
    virtual void vtbl155();
    virtual void vtbl156();
    virtual void vtbl157();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void vtbl161();
    virtual void vt288();
    virtual void vtbl163();
    virtual void vtbl164();
    virtual void vtbl165();
    virtual void vtbl166();
    virtual void vtbl167();
    virtual void vtbl168();
    virtual void vtbl169();
    virtual void vtbl170();
    virtual void vtbl171();
    virtual void vtbl172();
    virtual void vtbl173();
    virtual void vtbl174();
    virtual void vtbl175();
    virtual void vtbl176();
    virtual void vtbl177();
    virtual void vtbl178();
    virtual void vtbl179();
    virtual void vtbl180();
    virtual void vtbl181();
    virtual void vtbl182();
    virtual void vtbl183();
    virtual void vtbl184();
    virtual void vtbl185();
    virtual bool vt2e8();
    virtual void vtbl187();
    virtual void vtbl188();
    virtual void vtbl189();
    virtual void vtbl190();
    virtual void vt2fc();
    bool FUN_00440da0();
    ExtraList* BSFile_GetDevice();
    void TESObjectREFR_CleanUpTraps();
    void TESForm_SetDisabled(int a);
    Proc* FUN_008d8520();
    void ApplyActorSpells();
    Ref* FUN_008d6f30();
    bool TESObjectREFR_HasScript();
    bool GetTargeted();
    void PlayerCharacter_RemoveActorFromPlayercombatList(Ref* a);
    void PlayerCharacter_RemovePerceivedActor(Ref* a);
    void PlayerCharacter_CheckForQuestTargetUpdate(Ref* a);
    int FUN_00931850();
    bool MobileObject_IsTalkingActivator();
    void Actor_EndInterruptPackage(int a);
    void Actor_GetOutofFurnitureQuick();
    void FUN_00407800(Proc* a);
    void TESObjectREFR_SetLoadedDataFlag(unsigned int a, bool b);
    void* TESObjectREFR_GetEnableStateChildList();
    bool FUN_0056aa70();
    void TESForm_SetDisableFade(int a);
    void TESObjectREFR_Enable();
    void TESObjectREFR_MarkAsDeleted();
    void TESObjectREFR_AttachSound(bool a);
    Ref* BGSSaveFormBuffer_GetForm();
    void TESObjectREFR_Disable();
    void DoDeathStuff();
    void TESObjectCELL_AddScriptedRef(Ref* a);
    bool TESForm_GetHasSpokenFlag();
};
struct ExtraList
{
    Ref* ExtraDataList_GetAshPileRef();
    bool ExtraDataList_ShouldPopInWhenEnabledByParent();
    void* ExtraDataList_GetDroppedItemList();
    void ExtraDataList_SetItemDropper(Ref* a);
};
struct Iter
{
    bool FUN_008256d0();
    Ref** FUN_006815c0();
    Iter* FUN_00726070();
    void FUN_0063f7b0();
};
struct Proc
{
    virtual void* vt000(int a);
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual void vtbl116();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual void vtbl125();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void vtbl128();
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual void vtbl133();
    virtual void vtbl134();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual int vt22c();
    virtual void vtbl140();
    virtual void vtbl141();
    virtual void vtbl142();
    virtual void vtbl143();
    virtual void vtbl144();
    virtual void vtbl145();
    virtual void vtbl146();
    virtual void vtbl147();
    virtual void vtbl148();
    virtual void vtbl149();
    virtual void vtbl150();
    virtual void vtbl151();
    virtual void vtbl152();
    virtual void vtbl153();
    virtual void vtbl154();
    virtual void vtbl155();
    virtual void vtbl156();
    virtual void vtbl157();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void vtbl161();
    virtual void vtbl162();
    virtual void vtbl163();
    virtual void vtbl164();
    virtual void vtbl165();
    virtual void vtbl166();
    virtual void vtbl167();
    virtual void vtbl168();
    virtual void vtbl169();
    virtual void vtbl170();
    virtual void vtbl171();
    virtual void vtbl172();
    virtual void vtbl173();
    virtual void vtbl174();
    virtual void vtbl175();
    virtual void vtbl176();
    virtual void vtbl177();
    virtual void vtbl178();
    virtual void vtbl179();
    virtual void vtbl180();
    virtual void vtbl181();
    virtual void vtbl182();
    virtual void vtbl183();
    virtual void vtbl184();
    virtual void vtbl185();
    virtual void vtbl186();
    virtual void vtbl187();
    virtual void vtbl188();
    virtual void vtbl189();
    virtual void vtbl190();
    virtual void vtbl191();
    virtual void vtbl192();
    virtual void vtbl193();
    virtual void vtbl194();
    virtual void vtbl195();
    virtual void vtbl196();
    virtual void vtbl197();
    virtual void vtbl198();
    virtual void vtbl199();
    virtual void vtbl200();
    virtual void vtbl201();
    virtual void vtbl202();
    virtual void vtbl203();
    virtual void vtbl204();
    virtual void vtbl205();
    virtual void vtbl206();
    virtual void vtbl207();
    virtual void vtbl208();
    virtual void vtbl209();
    virtual void vtbl210();
    virtual void vtbl211();
    virtual void vtbl212();
    virtual void vtbl213();
    virtual void vtbl214();
    virtual void vtbl215();
    virtual void vtbl216();
    virtual void vtbl217();
    virtual void vtbl218();
    virtual void vtbl219();
    virtual void vtbl220();
    virtual void vtbl221();
    virtual void vtbl222();
    virtual void vtbl223();
    virtual void vtbl224();
    virtual void vtbl225();
    virtual void vtbl226();
    virtual void vtbl227();
    virtual void vtbl228();
    virtual void vtbl229();
    virtual void vtbl230();
    virtual void vtbl231();
    virtual void vtbl232();
    virtual void vtbl233();
    virtual void vtbl234();
    virtual void vtbl235();
    virtual void vtbl236();
    virtual void vtbl237();
    virtual void vtbl238();
    virtual void vtbl239();
    virtual void vtbl240();
    virtual void vtbl241();
    virtual void vtbl242();
    virtual void vtbl243();
    virtual void vtbl244();
    virtual void vtbl245();
    virtual void vtbl246();
    virtual void vtbl247();
    virtual void vtbl248();
    virtual void vtbl249();
    virtual void vtbl250();
    virtual void vtbl251();
    virtual void vtbl252();
    virtual void vtbl253();
    virtual void vtbl254();
    virtual void vtbl255();
    virtual void vtbl256();
    virtual void vtbl257();
    virtual void vtbl258();
    virtual void vtbl259();
    virtual void vtbl260();
    virtual void vtbl261();
    virtual void vtbl262();
    virtual void vtbl263();
    virtual void vtbl264();
    virtual void vtbl265();
    virtual void vtbl266();
    virtual void vtbl267();
    virtual void vtbl268();
    virtual void vtbl269();
    virtual void vtbl270();
    virtual void vtbl271();
    virtual void vtbl272();
    virtual void vtbl273();
    virtual void vtbl274();
    virtual void vtbl275();
    virtual void vtbl276();
    virtual void vtbl277();
    virtual void vtbl278();
    virtual void vtbl279();
    virtual void vtbl280();
    virtual void vtbl281();
    virtual void vtbl282();
    virtual void vtbl283();
    virtual void vtbl284();
    virtual void vtbl285();
    virtual void vtbl286();
    virtual void vtbl287();
    virtual void vtbl288();
    virtual void vtbl289();
    virtual void vtbl290();
    virtual void vtbl291();
    virtual void vtbl292();
    virtual void vtbl293();
    virtual void vtbl294();
    virtual void vtbl295();
    virtual void vtbl296();
    virtual void vtbl297();
    virtual void vtbl298();
    virtual void vtbl299();
    virtual void vtbl300();
    virtual void vtbl301();
    virtual void vtbl302();
    virtual void vtbl303();
    virtual void vtbl304();
    virtual void vtbl305();
    virtual ObjX* vt4c8();
    virtual void vtbl307();
    virtual int vt4d0(int a);
};
struct ObjX
{
    void TESObjectREFR_SetMarkerUsed(int a);
    ObjX* FUN_00586170();
    void FUN_006fcfa0();
};
struct Tes
{
    ObjX* FUN_004fd3e0(Ref* a, int b);
};
struct GlobalObj
{
    void RemoveActor(Ref* a);
    void ProcessLists_RemoveReference(Ref* a, int b);
    void ProcessLists_NullOutTargetRef(Ref* a, int b);
};
extern Ref* DAT_011dea3c;
extern Ref* DAT_011ca27c;
extern Ref* DAT_011ca280;
extern Tes* DAT_011dea10;
extern GlobalObj DAT_011e0e80;
void __cdecl ArrowProjectile_DeleteAttachedArrows(Ref* a, int b);
int __cdecl ArrowProjectile_GetArrowCount();
void __cdecl FalloutRadio_DisableNPCRadio(Ref* a);
struct ObjectResolver
{
    int unk00;
};
// Exe 0x00c59200: unit-local ListNode view; declarations and layout are preserved.
struct PathingdebuggeometryListNodeView
{
    bool Probe();
    ObjectResolver* GetData();
    void Unlink(ObjectResolver* data);
    PathingdebuggeometryListNodeView* Next();
};
struct EventTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c(int a, int b);
};
extern PathingdebuggeometryListNodeView DAT_011db150;
extern int DAT_011f21cc;
extern int DAT_011db0d4;
void Callee_007ebd50();
void __cdecl VATSMenu_RemoveTarget(int a1);

struct PointJack
{
    float x, y, z;
    PointJack()
    {}
    PointJack(float a, float b, float c) : x(a), y(b), z(c)
    {}
    static void* operator new[](unsigned int n);
};
struct ColorJack
{
    float r, g, b, a;
    ColorJack() : r(0), g(0), b(0), a(0)
    {}
    static void* operator new[](unsigned int n);
};
struct MatrixJack
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct PoolJack
{
    void* Allocate(unsigned int);
};
extern PoolJack DAT_011f6238;
extern PointJack DAT_011f426c;
extern MatrixJack DAT_011a9448;
extern ColorJack DAT_012032f8, DAT_01203308, DAT_01203318;
extern char* DAT_0109b220;
char* __cdecl InternJack(const char*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long*);
struct NameJack
{
    char* p;
    NameJack(const char* text)
    {
        if (!text)
            p = DAT_0109b220;
        else
            p = InternJack(text);
    }
    ~NameJack()
    {
        if (p == DAT_0109b220)
        {
        }
        else
        {
            long* q = (long*)(p - 8);
            InterlockedDecrement(q);
        }
    }
};
inline void* operator new[](unsigned int n)
{
    return DAT_011f6238.Allocate(n);
}
inline void* PointJack::operator new[](unsigned int n)
{
    return DAT_011f6238.Allocate(n);
}
inline void* ColorJack::operator new[](unsigned int n)
{
    return DAT_011f6238.Allocate(n);
}
struct JackGeometry
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30;
    MatrixJack matrix;
    PointJack position;
    unsigned int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    unsigned int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0;
    static void* operator new(unsigned int);
    static void operator delete(void*);
    JackGeometry(int, PointJack*, ColorJack*, int, int, int, char*);
    void SetName(const NameJack&);
};
// @fnv 0x00c59200
// src: XBOX_PDB 0x00c59200
JackGeometry* __cdecl BSTestObjects_CreateCoordinateJack(float scale)
{
    PointJack* positions = new PointJack[6];
    positions[0] = PointJack(0, 0, 0);
    positions[1] = PointJack(scale, 0, 0);
    positions[2] = PointJack(0, 0, 0);
    positions[3] = PointJack(0, scale, 0);
    positions[4] = PointJack(0, 0, 0);
    positions[5] = PointJack(0, 0, scale);
    ColorJack* colors = new ColorJack[6];
    colors[0] = DAT_012032f8;
    colors[1] = DAT_012032f8;
    colors[2] = DAT_01203308;
    colors[3] = DAT_01203308;
    colors[4] = DAT_01203318;
    colors[5] = DAT_01203318;
    char* flags3 = new char[6];
    flags3[0] = 1;
    flags3[1] = 0;
    flags3[2] = 1;
    flags3[3] = 0;
    flags3[4] = 1;
    flags3[5] = 0;
    JackGeometry* result9 = new JackGeometry(6, positions, colors, 0, 0, 0, flags3);
    result9->position = DAT_011f426c;
    result9->matrix = DAT_011a9448;
    result9->SetName(NameJack("BSTestObjects Coordinate Jack"));
    return result9;
}
