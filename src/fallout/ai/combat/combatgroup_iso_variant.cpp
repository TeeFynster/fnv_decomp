// src/fallout/ai/combat/combatgroup_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/combat/combatgroup.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/fallout/ai/combat/combatgroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatgroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00985980_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    void* p10;
    void CopyFrom(FUN_00985980_shell* other);
};
struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct FUN_00986c40_shell
{
    char pad[0x18];
    ArrHelper arr;
    bool FUN_00986c40() const;
};
struct FUN_0096a2b0_stub
{
    void FUN_0096a2b0(int state);
};

struct FUN_009871c0_shell
{
    void FUN_009871c0(int state);
};
extern double _gModifierZero;
struct FUN_009871e0_shell
{
    bool __thiscall IsModifierZero();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_009877c0_shell : ArrSI
{
    unsigned int GetFlagsFromSubobject();
};
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_009877e0_shell
{
    void ClearGlobalObject();
};
struct FUN_00987800_shell
{
    char GetByteAtOffset154();
};
struct FUN_0098ebc0_obj
{
    void __thiscall GetElementAt(int a1);
};
struct FUN_00988770_shell
{
    void __thiscall ForwardToMember(int a1);
};
struct BSSimpleArray_NavMeshSearchNode
{
    void FUN_006dad90(unsigned int) const;
};
struct FUN_00988790_shell
{
    char pad[0x18];
    BSSimpleArray_NavMeshSearchNode m_aiIndexedValues;
    void FUN_00988790(unsigned int idx) const;
};
struct ActorCombatGroup
{
    void* __thiscall FUN_009865d0(int);
    unsigned char __thiscall GetByteAtOffset100(int);
};
void* __thiscall ActorCombatGroup::FUN_009865d0(int)
{
    return 0;
}
struct FUN_0098a310_shell
{
    int m_field;
    int __thiscall GetFieldOrZero(int param);
};
struct FUN_009865f0_stub
{
    int m_kPointA;
    int m_field;
    FUN_009865f0_stub* __thiscall FUN_009865f0(int param);
};
struct FUN_009865f0_shell
{
    int __thiscall FUN_009865f0(int a1);
};

struct FUN_0098a360_shell
{
    void __thiscall FUN_0098a360(int a1, int a2);
};
struct BSSimpleArray
{
    unsigned int& GetAt(int index);
};
struct FUN_0098de60_shell
{
    unsigned char pad[0x138];
    BSSimpleArray arr;  // +0x138
    int GetArrayItem(char index);
};
extern int DAT_0108d6f4;
struct FUN_0098ed30_class
{
    void* vtable;
    void FUN_0098fab0(int a, int b);
    void* FUN_0098ed30();
};
struct FUN_0098efa0_shell
{
    void* __thiscall FUN_0098efa0(int count);
};
extern "C" void* __cdecl Reallocate(void*, unsigned int);
struct FUN_0098efd0_shell
{
    void* __thiscall FUN_0098efd0(void* a, unsigned int b);
};
struct BGSLoadFormBuffer
{
    bool __thiscall ReadFormIdentifier(void*);
    void __thiscall ReadTypedData(void*, unsigned int);
};
struct FUN_00985a50_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    void* p10;
    void FUN_00985a50(BGSLoadFormBuffer* buffer, FUN_0098de60_shell* obj);
};
struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void* data, unsigned int size, int flags);
};
struct FUN_00985ae0_shell
{
    void __thiscall FUN_00985ae0(BGSSaveFormBuffer* buffer, int a1);
};
struct FUN_00985b10_shell
{
    void __thiscall FUN_00985b10(BGSLoadFormBuffer* buffer, int a2);
};
struct CombatTarget
{
    char m_data[0x68];
};
struct BSSimpleArray_CombatTarget_1024
{
    void* __pad;
    void* pBuffer;
    unsigned int __thiscall FUN_0098f7b0();
    void __thiscall FUN_0098f840(CombatTarget* pDest, unsigned int ItemUpdateArray);
    unsigned int __thiscall FUN_0098eec0(const CombatTarget* aValue);
};
extern int DAT_0108d708;
struct FUN_0098fbe0_shell
{
    void FUN_0098fbe0(int, int);
};
struct FUN_0098eff0_shell
{
    void* vtable;
    void* __thiscall FUN_0098eff0();
};
struct TESForm
{
    virtual ~TESForm()
    {}
};
struct Actor : public TESForm
{
    virtual ~Actor()
    {}
};
TESForm* __cdecl _ref_004839c0(unsigned int);
struct Holder00985930
{
    unsigned int m_data;
    void __thiscall FUN_00985930(int a1, int a2);
};
struct FUN_0098f560
{
    char data[16];
    ~FUN_0098f560();
};
struct FUN_009863b0
{
    char pad[24];
    FUN_0098f560 m18;
    FUN_0098f560 m28;
    ~FUN_009863b0();
};
struct FUN_009865b0_shell : ActorCombatGroup
{
    bool FUN_009865b0(int param);
};
struct FUN_00986950_shell
{
    void* p0;
    int a4;
    float f8;
    float fc;
    void* p10;
    void* __thiscall FUN_00986950(void* a1);
};
struct FUN_00986a80_shell : public FUN_009865f0_shell
{
    char __thiscall FUN_00986a80(int param);
};
struct FUN_009874b0_shell : ActorCombatGroup
{
    void __thiscall FUN_009874b0(int a1);
};
struct S_009874f0
{
    char pad[0x4A];
    short f4A;
};
struct FUN_009874f0_obj
{
    void __thiscall DecrementField4A(int);
};
struct ThreeInts_00989010
{
    int a;
    int b;
    int c;
};
struct StandIn_00989010
{
    ThreeInts_00989010 t;
    int v;
    void __thiscall SetTripleAndValue(ThreeInts_00989010* src, int val);
};
struct CombatTargetTimestamp
{
    int v;
};
CombatTargetTimestamp* __fastcall FUN_004300a0(CombatTargetTimestamp*);
struct MyClass
{
    int GetResultForArg(int arg);
    void UpdateTargetPerception(int a1, int a2, int* a3, CombatTargetTimestamp* a4, bool* a5, bool* a6);
};
struct Calendar
{
    unsigned int __thiscall GetDaysPassed();
};
struct TESAmmoInitCalls
{
    unsigned int __thiscall GetFieldBC();
};
struct FUN_009891d0_class
{
    char _pad[0x28];
    int m28;
    void __thiscall FUN_009891d0(TESAmmoInitCalls* p1, Calendar* p2);
};
struct Ref_997440
{
    int __thiscall FUN_00575650(void* a, Ref_997440* b, float c);
};
struct S989970
{
    void __thiscall FindClosestRef(int v);
    void __thiscall FUN_00989970(Ref_997440* p, float f);
};
struct B16
{
    int a;
    int b;
    int c;
    int d;
};
struct FUN_0098a340_shell
{
    int __thiscall FUN_0098a340(int a1);
};
struct FUN_0098a410_shell
{
    unsigned int __thiscall GetCount();
    void* __thiscall GetIntAt(int);
    void* FindByValue(unsigned int value);
};
extern int DAT_011f18b4[];
int __cdecl FUN_0098e980(int index);
struct CombatClusterMember
{
    void* pActor;
    unsigned int m_uiGoalFlags;
    float m_fClusterOffsetX;
    float m_fClusterOffsetY;
    void* pCluster;
};
struct BSSimpleArray_CombatMember_1024
{
    void* __pad;
    CombatClusterMember* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int __thiscall FUN_007881d0();
    unsigned int __thiscall FUN_0098fb40(CombatClusterMember* pDest, unsigned int ItemUpdateArray);
    unsigned int __thiscall AddCombatMember(const CombatClusterMember* aValue);
};
struct CTSHelper
{
    char _pad[8];
    float __thiscall GetElapsedTime();
};
struct FUN_00985bb0_Class
{
    char _pad[16];
    CTSHelper _ts;
    float _f18;
    float __thiscall FUN_00985bb0();
};
struct FUN_00986560_shell
{
    char pad[8];
    void __thiscall FUN_00986560(int a1);
};
struct FUN_0098ef10_shell
{
    void* __thiscall FUN_0098ef10(int a1);
    void __thiscall FUN_0098ef10(int a1, int a2);
};
struct FUN_009926e0_shell
{
    void __thiscall SwapAndDispatch(void* a, void* b);
};
extern void* BGSSaveLoadGlobalDataWorldspacePtr;
struct RefObj
{
    unsigned int __thiscall _ref_0084e3a0();
};
struct SearchNode
{
    RefObj* p;
};
struct MyArr : ArrSI
{
    SearchNode* __thiscall FUN_006dad90(unsigned int) const;
};
struct C00986670
{
    char pad[0x18];
    MyArr arr;
    SearchNode* __thiscall FUN_00986670(unsigned int);
};
struct FUN_00986b70_shell : ActorCombatGroup
{
    void __thiscall FUN_00986b70();
};
struct FUN_00986b70_helper : ActorCombatGroup
{
    void* GetIntAt(int);
    unsigned int GetCount();
};
struct Actor_vfn
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc(bool);
};
struct FUN_0098a2e0_shell
{
    char pad[0x14c];
    int m_kPointA;
    int m_kPointB;
    bool __thiscall FUN_0098a2e0();
};
struct CombatGroup_GetCount
{
    unsigned int __thiscall GetCount();
};
struct MyNode_0098a3c0
{
    int m0;
    int m1;
};
struct MyArr_0098a3c0
{
    MyNode_0098a3c0* __thiscall FUN_006dad90(unsigned int) const;
};
struct FUN_0098a3c0_shell
{
    char pad[0x18];
    MyArr_0098a3c0 arr;
    void __thiscall FUN_0098a3c0();
};
struct CombatSearchDoor
{
    char pad[0x0a];
    bool bReserved;
};
struct FUN_0098c590_shell
{
    CombatSearchDoor* FindParentSpaceNode(int param);
};
struct FUN_0098c780_shell
{
    void ClearReservedFlag(int param);
};
struct FUN_0098ed60_shell : GlobalObject_00869f00
{
    void __thiscall FUN_0098ed60();
};
struct S0098a4d0
{
    float __thiscall ComputeAverageRatio();
};
struct FUN_00990500_host
{
    S0098a4d0* p0;
    char pad[16];
    float f14;
    float __thiscall GetCachedValue();
};
struct ActorS
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool vfn_22c(int a);
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual bool vfn_2e8();
};
struct ActorX
{
    bool FUN_00437bd0();
};
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting403;
extern Setting_S originalRuntimeFloatSetting404;
extern Setting_S originalRuntimeFloatSetting405;
extern Setting_S originalRuntimeFloatSetting406;
extern Setting_S originalRuntimeFloatSetting407;
extern Setting_S originalRuntimeFloatSetting408;
extern Setting_S originalRuntimeFloatSetting409;
extern Setting_S originalRuntimeFloatSetting410;
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011cef50;
struct AvoidSphere
{
    float GetRadius() const;
};
struct Flt
{
    operator unsigned int();
};
struct RegionPoint
{
    float GetX();
};
extern float DAT_0108d540;
struct CombatMemberS
{
    ActorS* pActor;
    char pad04[0x44];
    unsigned short w48;
    unsigned short w4a;
};
struct CombatGroupS
{
    char pad00[0xd0];
    unsigned int ItemUpdateArray;
    Flt spSphere;
    bool FUN_00987220(CombatMemberS* pMember);
    void* FUN_00989880(ActorS* pActor, float fRadius);
};
struct FUN_0098de30_class
{
    unsigned char FUN_0098de30(unsigned int*);
};
struct FUN_009859c0_shell
{
    void __thiscall FUN_009859c0(BGSSaveFormBuffer* buffer, FUN_0098de30_class* obj);
};
struct SaveFormIDHelper
{
    void __thiscall SerializeFormData(void*, int);
};
struct ActorV
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual const char* V130();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void* V1d0();
};
struct BGSCameraPath
{
    int HasNameForWarning();
};
struct MobileObject
{
    const char* GetFullName();
};
struct FormIDStandIn
{
    unsigned int _ref_0084e3a0();
};
void FNV_Warning(const char*, ...);
struct S00986a80
{
    bool FUN_00986a80(ActorV*);
};
struct S00986aa0
{
    bool FUN_00986aa0(ActorV*);
};
struct S00992700
{
    void FUN_00992700(void*, ActorV*);
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011f1878;
int __cdecl FUN_005d8550(unsigned int);
struct P3
{
    float x, y, z;
    void Set(float, float, float);
};
struct RgbaColor
{
    float r, g, b, a;
};
void FUN_004b6360(void*, P3*, int);
struct FUN_0097f220_t
{
    void FUN_0097f220();
};
struct CombatGroup_009867d0
{
    unsigned int m_uiActorFormID;
    bool FUN_009867d0(ActorV* apActor);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct FUN_0098f040_shell
{
    CombatClusterMember* pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    virtual void v0();
    virtual CombatClusterMember* Allocate(unsigned int);
    void UpdateThreat(unsigned int, unsigned int);
    void FUN_0098f040(unsigned int auiNewSize, bool abFreeMemory);
};
struct FUN_00986500_shell : ActorCombatGroup
{
    void FUN_00986560(int i);
    void RemoveByTarget(int target);
};
struct FUN_0096a2b0_stub2
{
    CombatTarget* FUN_0096a2b0(int i);
};
struct _ref_0084e3a0_fn
{
    unsigned int __thiscall FUN_0084e3a0();
};
struct FUN_00986610_shell
{
    char pad[8];
    BSSimpleArray_CombatMember_1024 arr;
    void* FUN_00986610(unsigned int value);
};
struct XIdle;
struct XArr
{
    void SetAt(unsigned int, XIdle*);
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_00986b00_shell
{
    char pad[0x18];
    ArrSI arr;
    void CopyArrayTo(XArr* dst);
};
struct Sky
{
    int a;
    int b;
};
struct SkyObject
{
    void Update(Sky* a, int b);
};
struct FUN_00986bd0_shell : ActorCombatGroup
{
    Actor* GetIntAt(int);
    unsigned int GetCount();
    void FUN_00986bd0();
};
class CoordinateTriple
{
  public:
    void FUN_00527b70(void* pBuffer);
};
struct FUN_009a5f90_shell
{
    void SaveTimeStamp(void* pBuffer);
};
struct FUN_009856e0_shell
{
    Actor* pActor;
    int m_field;
    char pad[0x60];

    void __thiscall FUN_009856e0(BGSSaveFormBuffer* pBuffer, ActorCombatGroup* pGroup);
};
struct FUN_00527ba0_Class
{
    char pad[0x10];
    void __thiscall FUN_00527ba0(void* pBuffer);
};
struct CombatTimeStampLoadGame
{
    void __thiscall LoadGame(BGSLoadFormBuffer* pBuffer);
};
struct BGSLoadGameBufferVersion
{
    virtual unsigned char GetVersion();
};
struct FUN_00985800_shell
{
    void* pActor;
    int m4;
    FUN_00527ba0_Class m8;
    FUN_00527ba0_Class m18;
    FUN_00527ba0_Class m28;
    FUN_00527ba0_Class m38;
    char m48[2];
    char m4a[2];
    CombatTargetTimestamp m4c;
    CombatTargetTimestamp m50;
    CombatTargetTimestamp m54;
    CombatTargetTimestamp m58;
    CombatTargetTimestamp m5c;
    CombatTargetTimestamp m60;
    char m64;
    char m65;

    void __thiscall FUN_00985800(BGSLoadFormBuffer* pBuffer, ActorCombatGroup* pGroup);
};
double DAT_0101db88;
struct ImageSpaceEffectParam
{
    float f0;
    float f4;
    float f8;
    float fc;

    ImageSpaceEffectParam(float, float, float, float);
};
struct FUN_00985be0_shell : public FUN_00985bb0_Class
{
    ImageSpaceEffectParam* GetEffectColor(ImageSpaceEffectParam* result);
};
struct NiAVObject
{
};
void __cdecl FUN_004b6630(NiAVObject*);
struct ActorDispatchBase
{
    virtual NiAVObject* M001() = 0;
    virtual NiAVObject* M002() = 0;
    virtual NiAVObject* M003() = 0;
    virtual NiAVObject* M004() = 0;
    virtual NiAVObject* M005() = 0;
    virtual NiAVObject* M006() = 0;
    virtual NiAVObject* M007() = 0;
    virtual NiAVObject* M008() = 0;
    virtual NiAVObject* M009() = 0;
    virtual NiAVObject* M010() = 0;
    virtual NiAVObject* M011() = 0;
    virtual NiAVObject* M012() = 0;
    virtual NiAVObject* M013() = 0;
    virtual NiAVObject* M014() = 0;
    virtual NiAVObject* M015() = 0;
    virtual NiAVObject* M016() = 0;
    virtual NiAVObject* M017() = 0;
    virtual NiAVObject* M018() = 0;
    virtual NiAVObject* M019() = 0;
    virtual NiAVObject* M020() = 0;
    virtual NiAVObject* M021() = 0;
    virtual NiAVObject* M022() = 0;
    virtual NiAVObject* M023() = 0;
    virtual NiAVObject* M024() = 0;
    virtual NiAVObject* M025() = 0;
    virtual NiAVObject* M026() = 0;
    virtual NiAVObject* M027() = 0;
    virtual NiAVObject* M028() = 0;
    virtual NiAVObject* M029() = 0;
    virtual NiAVObject* M030() = 0;
    virtual NiAVObject* M031() = 0;
    virtual NiAVObject* M032() = 0;
    virtual NiAVObject* M033() = 0;
    virtual NiAVObject* M034() = 0;
    virtual NiAVObject* M035() = 0;
    virtual NiAVObject* M036() = 0;
    virtual NiAVObject* M037() = 0;
    virtual NiAVObject* M038() = 0;
    virtual NiAVObject* M039() = 0;
    virtual NiAVObject* M040() = 0;
    virtual NiAVObject* M041() = 0;
    virtual NiAVObject* M042() = 0;
    virtual NiAVObject* M043() = 0;
    virtual NiAVObject* M044() = 0;
    virtual NiAVObject* M045() = 0;
    virtual NiAVObject* M046() = 0;
    virtual NiAVObject* M047() = 0;
    virtual NiAVObject* M048() = 0;
    virtual NiAVObject* M049() = 0;
    virtual NiAVObject* M050() = 0;
    virtual NiAVObject* M051() = 0;
    virtual NiAVObject* M052() = 0;
    virtual NiAVObject* M053() = 0;
    virtual NiAVObject* M054() = 0;
    virtual NiAVObject* M055() = 0;
    virtual NiAVObject* M056() = 0;
    virtual NiAVObject* M057() = 0;
    virtual NiAVObject* M058() = 0;
    virtual NiAVObject* M059() = 0;
    virtual NiAVObject* M060() = 0;
    virtual NiAVObject* M061() = 0;
    virtual NiAVObject* M062() = 0;
    virtual NiAVObject* M063() = 0;
    virtual NiAVObject* M064() = 0;
    virtual NiAVObject* M065() = 0;
    virtual NiAVObject* M066() = 0;
    virtual NiAVObject* M067() = 0;
    virtual NiAVObject* M068() = 0;
    virtual NiAVObject* M069() = 0;
    virtual NiAVObject* M070() = 0;
    virtual NiAVObject* M071() = 0;
    virtual NiAVObject* M072() = 0;
    virtual NiAVObject* M073() = 0;
    virtual NiAVObject* M074() = 0;
    virtual NiAVObject* M075() = 0;
    virtual NiAVObject* M076() = 0;
    virtual NiAVObject* M077() = 0;
    virtual NiAVObject* M078() = 0;
    virtual NiAVObject* M079() = 0;
    virtual NiAVObject* M080() = 0;
    virtual NiAVObject* M081() = 0;
    virtual NiAVObject* M082() = 0;
    virtual NiAVObject* M083() = 0;
    virtual NiAVObject* M084() = 0;
    virtual NiAVObject* M085() = 0;
    virtual NiAVObject* M086() = 0;
    virtual NiAVObject* M087() = 0;
    virtual NiAVObject* M088() = 0;
    virtual NiAVObject* M089() = 0;
    virtual NiAVObject* M090() = 0;
    virtual NiAVObject* M091() = 0;
    virtual NiAVObject* M092() = 0;
    virtual NiAVObject* M093() = 0;
    virtual NiAVObject* M094() = 0;
    virtual NiAVObject* M095() = 0;
    virtual NiAVObject* M096() = 0;
    virtual NiAVObject* M097() = 0;
    virtual NiAVObject* M098() = 0;
    virtual NiAVObject* M099() = 0;
    virtual NiAVObject* M100() = 0;
    virtual NiAVObject* M101() = 0;
    virtual NiAVObject* M102() = 0;
    virtual NiAVObject* M103() = 0;
    virtual NiAVObject* M104() = 0;
    virtual NiAVObject* M105() = 0;
    virtual NiAVObject* M106() = 0;
    virtual NiAVObject* M107() = 0;
    virtual NiAVObject* M108() = 0;
    virtual NiAVObject* M109() = 0;
    virtual NiAVObject* M110() = 0;
    virtual NiAVObject* M111() = 0;
    virtual NiAVObject* M112() = 0;
    virtual NiAVObject* M113() = 0;
    virtual NiAVObject* M114() = 0;
    virtual NiAVObject* M115() = 0;
    virtual NiAVObject* M116() = 0;
};
struct ActorDispatch : ActorDispatchBase
{
    virtual NiAVObject* M117() = 0;
};
struct FUN_0098f1f0_caller
{
    void __thiscall RemoveEntries(unsigned int index, int flag);
};
struct FUN_009869a0_shell
{
    unsigned char pad00[0xEC];
    Actor* m_pActor;

    void FUN_009869a0(Actor* apActor);
};
struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3 operator+(const NiPoint3& other) const;
    NiPoint3 FUN_0053d280(float value) const;
};
struct B006815c0 : public NiPoint3
{
    B006815c0();
};
struct TESCombatStyle
{
    void UpdateCombatStyle() const;
};
struct P3OperatorMinusHelper
{
    P3 operator-(const P3& other) const;
};
extern float _DAT_010162c0;
struct FUN_00989eb0_shell
{
    void __thiscall UpdateBoundsFromActors(B006815c0* points, int index);
    void __thiscall FUN_00989eb0(NiPoint3* result);
};
struct FUN_0098a390_shell
{
    char pad[0x18];
    MyArr m_aiIndexedValues;
    void __thiscall SetElementValue(unsigned int a1, unsigned int a2);
};
struct PathingSolution
{
    unsigned int __thiscall GetVirtualNodeCount();
};
namespace identity {
struct ActorCombatGroup
{
    unsigned int __thiscall GetCount();
    Actor* __thiscall GetIntAt(int index);
};

struct FUN_009871c0_shell
{
    S_009874f0* __thiscall FUN_009871c0(int index);
};
}
struct ActorVirtual
{
    virtual void f000();
    virtual void f001();
    virtual void f002();
    virtual void f003();
    virtual void f004();
    virtual void f005();
    virtual void f006();
    virtual void f007();
    virtual void f008();
    virtual void f009();
    virtual void f010();
    virtual void f011();
    virtual void f012();
    virtual void f013();
    virtual void f014();
    virtual void f015();
    virtual void f016();
    virtual void f017();
    virtual void f018();
    virtual void f019();
    virtual void f020();
    virtual void f021();
    virtual void f022();
    virtual void f023();
    virtual void f024();
    virtual void f025();
    virtual void f026();
    virtual void f027();
    virtual void f028();
    virtual void f029();
    virtual void f030();
    virtual void f031();
    virtual void f032();
    virtual void f033();
    virtual void f034();
    virtual void f035();
    virtual void f036();
    virtual void f037();
    virtual void f038();
    virtual void f039();
    virtual void f040();
    virtual void f041();
    virtual void f042();
    virtual void f043();
    virtual void f044();
    virtual void f045();
    virtual void f046();
    virtual void f047();
    virtual void f048();
    virtual void f049();
    virtual void f050();
    virtual void f051();
    virtual void f052();
    virtual void f053();
    virtual void f054();
    virtual void f055();
    virtual void f056();
    virtual void f057();
    virtual void f058();
    virtual void f059();
    virtual void f060();
    virtual void f061();
    virtual void f062();
    virtual void f063();
    virtual void f064();
    virtual void f065();
    virtual void f066();
    virtual void f067();
    virtual void f068();
    virtual void f069();
    virtual void f070();
    virtual void f071();
    virtual void f072();
    virtual void f073();
    virtual void f074();
    virtual void f075();
    virtual void f076();
    virtual void f077();
    virtual void f078();
    virtual void f079();
    virtual void f080();
    virtual void f081();
    virtual void f082();
    virtual void f083();
    virtual void f084();
    virtual void f085();
    virtual void f086();
    virtual void f087();
    virtual void f088();
    virtual void f089();
    virtual void f090();
    virtual void f091();
    virtual void f092();
    virtual void f093();
    virtual void f094();
    virtual void f095();
    virtual void f096();
    virtual void f097();
    virtual void f098();
    virtual void f099();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual int GetID();
};
extern Actor* _g_thePlayer;
struct FUN_0098cf70_shell
{
    void CountActorsPerNode();
};
struct BSSimpleArrayActor
{
    void __thiscall Clear(bool);
};
struct FUN_0098fa00_shell
{
    void __thiscall FUN_0098fa00(unsigned int, unsigned int);
};
struct AllocationBase
{
    virtual void Anchor()
    {}
    virtual CombatTarget* Allocate(unsigned int)
    {
        return 0;
    }
};
struct FUN_0098ed80_shell : public AllocationBase
{
    CombatTarget* m_buffer;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void __thiscall FUN_0098ed80(unsigned int, bool);
};
struct GlobalObject_0040e0b0
{
    float* Float();
};
struct TimeoutTimer
{
    bool CheckTimer();
};
struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float value);
};
struct InnerObj
{
    bool FUN_0097ef30();
};
struct FUN_0097fa50_Class
{
    bool FUN_0097fa50();
};
struct FUN_00986150_shell
{
    void FUN_00986150();
    void RecountActors();
    void FUN_0098d030();
    void UpdateChoiceSelection();
    void FUN_0098a580();
    void FUN_0098c870();
    void UpdateGroups();
    unsigned int GetCount();
};
extern Setting_S originalRuntimeFloatSetting487;
extern Setting_S originalRuntimeFloatSetting488;
extern Setting_S originalRuntimeFloatSetting493;
extern GlobalObject_0040e0b0 g_011ceb44;
extern double _DAT_01012060;
struct Pair8
{
    int a;
    int b;
};
struct Obj8
{
    int m0;
    int m4;
    Obj8();
    void* operator new(unsigned int size, void* where);
    void operator delete(void* p, void* where);
};
struct Walker8
{
    void __thiscall ConstructArray(Pair8* arr, unsigned int count);
};
struct EventVector
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
    void FUN_0097ede0();
};
struct TimeStamp
{
    unsigned int value;
    void FUN_004300a0();
};
struct TimeValue
{
    float value;
    void FUN_00435de0(float time);
};
float __cdecl FUN_00435dd0();
extern float DAT_0108d540;
struct EventSource
{
    EventVector FUN_00575650();
};
struct EventRecord
{
    EventSource* source;
    unsigned int status;
    EventVector primary;
    EventVector secondary;
    EventVector tertiary;
    EventVector quaternary;
    unsigned short type;
    unsigned short subtype;
    TimeValue initialTime;
    TimeValue previousTime;
    TimeStamp start;
    TimeValue timeNow;
    TimeStamp last;
    TimeValue endTime;
    unsigned char started;
    unsigned char ended;
    EventRecord* Init(EventSource* src, unsigned short eventType);
};
struct CombatStamp_985520
{
    float fTime;
    float __thiscall GetTime();
};
struct Block16_985520
{
    int a;
    int b;
    int c;
    int d;
};
struct CombatMemberData_985520
{
    void* pActor;
    int iValue04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Block16_985520 m18;
    Block16_985520 m28;
    Block16_985520 m38;
    unsigned short w48;
    unsigned short w4A;
    CombatStamp_985520 m4C;
    CombatStamp_985520 m50;
    CombatStamp_985520 m54;
    CombatStamp_985520 m58;
    CombatStamp_985520 m5C;
    CombatStamp_985520 m60;
    unsigned char b64;
    unsigned char b65;

    void __thiscall MergeCombatData(CombatMemberData_985520* pOther);
};
struct TimeInput
{
    float __thiscall FUN_00527a40(FUN_00985bb0_Class* owner);
};
extern float _DAT_0108d5a0;
extern double _DAT_0108d598;
extern double _DAT_01020758;
float __cdecl FUN_0040ebd0(float value, float limit);
struct CombatClock : FUN_00985bb0_Class
{
    float __thiscall GetAdjustedTime(TimeInput* timeInput);
};
struct BSSimpleArrayForCall : BSSimpleArray
{
    void __thiscall CopyItemsTo(BSSimpleArrayForCall* other);
};
struct FUN_00986740_shell
{
    void* unk00;
    void* unk04;
    BSSimpleArrayForCall arr;

    void __thiscall FUN_00986740(FUN_00986740_shell* other);
};
void __thiscall BSSimpleArrayForCall::CopyItemsTo(BSSimpleArrayForCall* other)
{}
struct FUN_00986760_sub
{
    unsigned int __thiscall FUN_0044ddc0(int flag);
    unsigned int __thiscall FUN_0044ddc0();
    void* __thiscall FUN_0096a2b0(int i);
};
struct FUN_00986760_arg
{
    void __thiscall FUN_006f2290(unsigned int v);
    void __thiscall FUN_0047a110(int i, void* p);
};
struct FUN_00986760_cls
{
    char pad[8];
    FUN_00986760_sub m_08;
    void __thiscall FUN_00986760(int a1);
};
struct Actor_987820;
struct Ctrl_987820
{
    void FUN_00980a30(Actor_987820* apTarget);
};
struct Actor_987820
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual struct Ctrl_987820* v266();
};
struct Group_987820
{
    unsigned int GetCount();
    Actor_987820* GetAt(int idx);
    void RemoveByTarget(Actor_987820* apTarget);
    void FUN_00987820(Actor_987820* apTarget);
};
struct ResultQuad
{
    unsigned int x, y, z, w;
};
struct ResultLookup
{
    void* FUN_009871c0(int);
};
struct ResultTimer
{
    float FUN_00435e00();
};
struct ResultQuery
{
    bool TryGetQuadForState(int state, ResultQuad* output, float threshold);
};
float __cdecl FUN_00435dd0();
struct B989230Stamp
{
    B989230Stamp(float fTime);

    unsigned int m_uiEventId;
};
struct B989230Quad
{
    float x;
    float y;
    float z;
    float w;
};
class B989230Ref
{
  public:
    B989230Quad FUN_00575650();
};
struct B989230Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    B989230Quad m_kPathOffset;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    B989230Stamp m_kStamp;
};
class B989230Tracker
{
  public:
    B989230Entry* FUN_009865d0(B989230Ref* pkRef);
    void UpdateEntryFromRef(int iUnused, B989230Ref* pkRef);
};
struct AvoidVector
{
    float x, y, z;
};
struct AvoidPosition
{
    AvoidVector point;
    unsigned space;
    float FUN_00527a40(const AvoidPosition&);
    AvoidVector& FUN_006815c0();
};
struct AvoidActor
{
    AvoidPosition FUN_00575650();
};
struct AvoidanceVectorData
{
    float x, y, z, r0, r1, r2, r3, r4, r5;
    AvoidanceVectorData(const AvoidVector&);
};
struct PathingAvoidNodeArray
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    static void* operator new(unsigned);
    PathingAvoidNodeArray();
    void AppendNode(const AvoidanceVectorData&, float, float);
};
struct AvoidSetting
{
    float* FUN_00403e20();
};
extern AvoidSetting DAT_011cea50, DAT_011ceb2c, DAT_011ce900;
struct AvoidWork
{
    unsigned FUN_005a4320();
    AvoidActor* FUN_00968630(unsigned);
    PathingAvoidNodeArray* BuildAvoidNodes(AvoidActor*, PathingAvoidNodeArray*);
};
struct B9897F0Quad
{
    float x;
    float y;
    float z;
    float w;
};
class B9897F0Ref
{
  public:
    B9897F0Quad FUN_00575650();
};
class B9897F0Point
{
  public:
    float GetSquaredDistance(const B9897F0Quad& kOther);
};
class B9897F0List
{
  public:
    unsigned int GetCount();
    B9897F0Ref* GetAt(unsigned int uiIndex);
    B9897F0Ref* FUN_009897f0(B9897F0Point* pkPoint, float fRadius, B9897F0Ref* pkExclude);
};
// Builds a 16 byte result block from the actor, then hands it to the group
// helper together with the radius and the actor.
struct LocalResult16
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};
// Actor side: fills the caller supplied result block and returns its address.
struct ActorRef00989880
{
    int __thiscall FUN_00575650(void* pResult);
};
// Group side: takes the result block, the radius and the actor.
struct GroupRef00989880
{
    void* __thiscall FUN_009897f0(int aResult, float aRadius, ActorS* pActor);
};
extern NiPoint3 NiPoint3_ZERO;
extern "C" void* _alloca(unsigned int size);
float __cdecl FUN_004579e0(float v);
class NiPoint3_ext
{
  public:
    float x;
    float y;
    float z;
    NiPoint3_ext& operator+=(const NiPoint3& other);
    NiPoint3 operator-(const NiPoint3& other) const;
    float Dot(const NiPoint3& other) const;
};
class NiPoint3_helper
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator*(float s) const;
};
struct FUN_004941c0_shell
{
    float x;
    float y;
    float z;
    NiPoint3* ScaleByInverse(float s);
};
struct FUN_00457910_shell
{
    float x;
    float y;
    float z;
    float FUN_00457910();
};
struct ActorPos
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
    virtual void v064();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
};
struct FUN_005a4320_shell : FUN_00986b70_helper
{
    unsigned int FUN_005a4320();
    ActorPos* FUN_00968630(unsigned int);
};
struct Grp_Call2 : FUN_005a4320_shell
{
    bool FUN_009899a0();
};
struct Tag_00989e20_cls
{
    int unk00;
    void FUN_004a7290();
};
struct Helper_00989e20_cls
{
    void FUN_00439ef0(Tag_00989e20_cls* p0, NiPoint3* p1);
    NiPoint3* FUN_00439e90(NiPoint3* p0, NiPoint3* p1, NiPoint3* p2);
};
struct Vec_00989e20_cls
{
    NiPoint3* FUN_0053d280(float value) const;
};
struct Blk_00989e20_cls
{
    int a0;
    Tag_00989e20_cls t;
    int a8;
    int ac;
};
struct FUN_00989e20_cls
{
    void ExpandBounds(B006815c0* arr, int n);
    void FUN_00989e20(NiPoint3* out);
};
struct BoundsVector
{
    float x, y, z;
    float& FUN_004a51b0(unsigned int axis);
};
struct BoundsActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const BoundsVector& GetBoundsPoint();
};
extern bool DAT_0108d57c[8][3];
struct BoundsGroup
{
    unsigned int FUN_00990890();
    BoundsActor* GetIntAt(unsigned int index);
    void ExpandBounds(BoundsVector* points, bool append);
};
struct SearchNodeArrayOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    MyArr_0098a3c0 nodes;
};
struct FUN_0098a4d0_sub
{
    virtual int Slot0(int arg);
    virtual void Slot1();
    virtual void Slot2();
    virtual double Slot3(int arg);
};
struct FUN_0098a4d0_item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    FUN_0098a4d0_sub sub;
};
struct FUN_0098a4d0_class : FUN_0098a410_shell
{
    float ComputeAverageRatio();
};
struct Pt3
{
    float x;
    float y;
    float z;
    float w;
};
struct PosObj
{
    bool IsEqual(const PosObj* other);
};
struct TileObj
{
    bool CheckItem(void* item, int a, int b);
};
struct MgrObj
{
    TileObj* GetTile();
};
struct ItemObj
{
    float GetScore();
    unsigned int GetID();
    PosObj* GetPosObj();
    float GetDistance(Pt3* pos);
};
struct ActorObj
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual MgrObj* GetMgr();
    Pt3 GetPos();
};
struct ItemList
{
    unsigned int GetCount();
    ItemObj* GetAt(unsigned int i);
    ItemObj* FindBestItem(ActorObj* actor, unsigned char thresh, ItemObj* target);
};
struct CombatEntryObj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void* vfn_428();
    bool FUN_008b3840(struct Probe16* p);
};
struct Probe16
{
    int a, b, c;
    void FUN_006815c0();
};
struct RefTarget
{
    bool FUN_00981420();
};
struct CombatGroupTarget
{
    void AddItem(Probe16* p);
};
struct CombatSearchCls
{
    unsigned int FUN_00990890();
    CombatEntryObj* GetIntAt(int i);
    bool CheckOtherEntriesForTarget(CombatEntryObj* a1, CombatGroupTarget* a2);
};
struct FUN_0098cb30_inner
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
    virtual void v00A();
    virtual void v00B();
    virtual void v00C();
    virtual void v00D();
    virtual void v00E();
    virtual void v00F();
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
    virtual void v01A();
    virtual void v01B();
    virtual void v01C();
    virtual void v01D();
    virtual void v01E();
    virtual void v01F();
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
    virtual void v02A();
    virtual void v02B();
    virtual void v02C();
    virtual void v02D();
    virtual void v02E();
    virtual void v02F();
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
    virtual void v03A();
    virtual void v03B();
    virtual void v03C();
    virtual void v03D();
    virtual void v03E();
    virtual void v03F();
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
    virtual void v04A();
    virtual void v04B();
    virtual void v04C();
    virtual void v04D();
    virtual void v04E();
    virtual void v04F();
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
    virtual void v05A();
    virtual void v05B();
    virtual void v05C();
    virtual void v05D();
    virtual void v05E();
    virtual void v05F();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06A();
    virtual void v06B();
    virtual void v06C();
    virtual void v06D();
    virtual void v06E();
    virtual void v06F();
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
    virtual void v07A();
    virtual void v07B();
    virtual void v07C();
    virtual void v07D();
    virtual void v07E();
    virtual void v07F();
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
    virtual void v08A();
    virtual void v08B();
    virtual void v08C();
    virtual void v08D();
    virtual void v08E();
    virtual void v08F();
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
    virtual void v09A();
    virtual void v09B();
    virtual void v09C();
    virtual void v09D();
    virtual void v09E();
    virtual void v09F();
    virtual void v0A0();
    virtual void v0A1();
    virtual void v0A2();
    virtual void v0A3();
    virtual void v0A4();
    virtual void v0A5();
    virtual void v0A6();
    virtual void v0A7();
    virtual void v0A8();
    virtual void v0A9();
    virtual void v0AA();
    virtual void v0AB();
    virtual void v0AC();
    virtual void v0AD();
    virtual void v0AE();
    virtual void v0AF();
    virtual void v0B0();
    virtual void v0B1();
    virtual void v0B2();
    virtual void v0B3();
    virtual void v0B4();
    virtual void v0B5();
    virtual void v0B6();
    virtual void v0B7();
    virtual void v0B8();
    virtual void v0B9();
    virtual void v0BA();
    virtual void v0BB();
    virtual void v0BC();
    virtual void v0BD();
    virtual void v0BE();
    virtual void v0BF();
    virtual void v0C0();
    virtual void v0C1();
    virtual void v0C2();
    virtual void v0C3();
    virtual void v0C4();
    virtual void v0C5();
    virtual void v0C6();
    virtual void v0C7();
    virtual void v0C8();
    virtual void v0C9();
    virtual void v0CA();
    virtual void v0CB();
    virtual void v0CC();
    virtual void v0CD();
    virtual void v0CE();
    virtual void v0CF();
    virtual void v0D0();
    virtual void v0D1();
    virtual void v0D2();
    virtual void v0D3();
    virtual void v0D4();
    virtual void v0D5();
    virtual void v0D6();
    virtual void v0D7();
    virtual void v0D8();
    virtual void v0D9();
    virtual void v0DA();
    virtual void v0DB();
    virtual void v0DC();
    virtual void v0DD();
    virtual void v0DE();
    virtual void v0DF();
    virtual void v0E0();
    virtual void v0E1();
    virtual void v0E2();
    virtual void v0E3();
    virtual void v0E4();
    virtual void v0E5();
    virtual void v0E6();
    virtual void v0E7();
    virtual void v0E8();
    virtual void v0E9();
    virtual void v0EA();
    virtual void v0EB();
    virtual void v0EC();
    virtual void v0ED();
    virtual void v0EE();
    virtual void v0EF();
    virtual void v0F0();
    virtual void v0F1();
    virtual void v0F2();
    virtual void v0F3();
    virtual void v0F4();
    virtual void v0F5();
    virtual void v0F6();
    virtual void v0F7();
    virtual void v0F8();
    virtual void v0F9();
    virtual void v0FA();
    virtual void v0FB();
    virtual void v0FC();
    virtual void v0FD();
    virtual void v0FE();
    virtual void v0FF();
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
    virtual int v10A();
};
struct FUN_0098cb30_obj
{
    FUN_0098cb30_inner* m_pInner;
    int unk04;
    int unk08;
    float m_iThirdValue;
};
struct FUN_0098cb30_res
{
    FUN_0098cb30_res* FUN_00586150();
    float FUN_00453700();
    bool FUN_00981990();
};
struct FUN_0098cb30_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float m_c0;
    unsigned int FUN_00990890();
    FUN_0098cb30_obj* FUN_00988790(unsigned int idx);
    float GetModifierSum(FUN_0098cb30_inner* a1);
};
extern double _gModifierZero;
class B8EB30Group;
class B8EB30GroupInfo
{
  public:
    B8EB30Group* GetGroup();
};
class B8EB30Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void vfn310();
    virtual void vfn314();
    virtual void vfn318();
    virtual void vfn31C();
    virtual void vfn320();
    virtual void vfn324();
    virtual void vfn328();
    virtual void vfn32C();
    virtual void vfn330();
    virtual void vfn334();
    virtual void vfn338();
    virtual void vfn33C();
    virtual void vfn340();
    virtual void vfn344();
    virtual void vfn348();
    virtual void vfn34C();
    virtual void vfn350();
    virtual void vfn354();
    virtual void vfn358();
    virtual void vfn35C();
    virtual void vfn360();
    virtual void vfn364();
    virtual void vfn368();
    virtual void vfn36C();
    virtual void vfn370();
    virtual void vfn374();
    virtual void vfn378();
    virtual void vfn37C();
    virtual void vfn380();
    virtual void vfn384();
    virtual void vfn388();
    virtual void vfn38C();
    virtual void vfn390();
    virtual void vfn394();
    virtual void vfn398();
    virtual void vfn39C();
    virtual void vfn3A0();
    virtual void vfn3A4();
    virtual void vfn3A8();
    virtual void vfn3AC();
    virtual void vfn3B0();
    virtual void vfn3B4();
    virtual void vfn3B8();
    virtual void vfn3BC();
    virtual void vfn3C0();
    virtual void vfn3C4();
    virtual void vfn3C8();
    virtual void vfn3CC();
    virtual void vfn3D0();
    virtual void vfn3D4();
    virtual void vfn3D8();
    virtual void vfn3DC();
    virtual void vfn3E0();
    virtual void vfn3E4();
    virtual void vfn3E8();
    virtual void vfn3EC();
    virtual void vfn3F0();
    virtual void vfn3F4();
    virtual void vfn3F8();
    virtual void vfn3FC();
    virtual void vfn400();
    virtual void vfn404();
    virtual void vfn408();
    virtual void vfn40C();
    virtual void vfn410();
    virtual void vfn414();
    virtual void vfn418();
    virtual void vfn41C();
    virtual void vfn420();
    virtual void vfn424();
    virtual B8EB30GroupInfo* GetGroupInfo();
};
extern B8EB30Actor* g_thePlayer;
class B8EB30Group
{
  public:
    void UpdateBase();
    unsigned int GetCount();
    B8EB30Actor* GetAt(int iIndex);
    void RemoveMemberAt(B8EB30Actor* pkActor);
    void RemoveActorsNotInGroup(void* pvUnused);
};
class B98EBC0Array
{
  public:
    int* FUN_006bf670(int iIndex);
    int* GetElementAt(int iIndex);
};
struct SimpleArrayRemove
{
    virtual ~SimpleArrayRemove();
    virtual void* Allocate(unsigned int ItemUpdateArray);

    void** pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;

    void Clear(bool bFree);
    bool FUN_006f3170();
    unsigned int FUN_00869600();
    void FUN_0042fb60(void* pDest, void* pSrc, unsigned int ItemUpdateArray);
    void FUN_0072ba80(void* pStart, unsigned int ItemUpdateArray);
    void FUN_006a8500();

    void FUN_0098ebe0(unsigned int uiStart, unsigned int ItemUpdateArray, bool bShrink);
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct RemovalOperations
{
    void FUN_0072ba80(void*, unsigned int);
    void FUN_0098f960(void*, void*, unsigned int);
};
struct RemovalArray : RemovalOperations
{
    void* unk00;
    char* unk04;
    unsigned int unk08;
    void FUN_0098ef10(unsigned int first, unsigned int count);
};
void* operator new(unsigned int uiSize, void* pvWhere);
void operator delete(void* pvMem, void* pvWhere);
class C98F840Element
{
  public:
    C98F840Element();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
};
class C98F840Allocator
{
  public:
    void FUN_0098f840(C98F840Element* pkElements, unsigned int ItemUpdateArray);
};
struct FUN_009d3390_sub
{
    int unk00;
    unsigned char CallA();
    unsigned char CallB();
};
struct FUN_009d3390_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_009d3390_sub m14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    unsigned char m74;

    unsigned char FUN_009d3390();
};
struct Member08
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member08();
};
struct Member18
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member18();
};
struct SharedList
{
    unsigned int unk00;
    unsigned int unk04;
    ~SharedList();
};
struct Member110
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member110();
};
struct Member120
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member120();
};
struct Member138
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member138();
    unsigned int FUN_0044ddc0();
    char*& FUN_006a7ad0(unsigned int);
};
struct CombatManager
{
    void SwapAndDispatch(void*, void*);
    void FUN_008d0600(void*, void*);
};
extern CombatManager* g_011f1958;
struct FUN_00985f90
{
    unsigned int unk000;
    unsigned int unk004;
    Member08 member08;
    Member18 member18;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    SharedList memberd4;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    Member110 member110;
    Member120 member120;
    SharedList member130;
    Member138 member138;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    SharedList member158;
    unsigned int FUN_005a4320();
    void* FUN_00968630(unsigned int);
    unsigned int FUN_00990890();
    void* GetIntAt(unsigned int);
    void RebuildDebugVisuals(bool);
    ~FUN_00985f90();
};
struct ActorMergeData;
struct MergeActor : ActorV
{
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void SetCombatGroup(ActorMergeData* group);
    unsigned int FUN_0084e3a0();
};
struct MergeTarget
{
    MergeActor* actor;
    void MergeCombatData(MergeTarget* other);
};
struct MergeMember
{
    MergeActor* actor;
    void CopyFrom(MergeMember* other);
};
struct MergeTargets : ArrSI
{
    unsigned int unk00, unk04, unk08, unk0c;
    MergeTarget* FUN_0096a2b0(unsigned int index);
};
struct MergeMembers : ArrSI
{
    MergeMember* FUN_006dad90(unsigned int index);
};
struct MergeEntries
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int FUN_007cb2e0(int& entry);
};
struct ActorMergeData
{
    unsigned int unk00, unk04;
    MergeTargets targets;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    MergeEntries entries;
    unsigned int unk148, unk14c, unk150;
    char state;
    MergeTargets* FUN_00413f40();
    MergeMembers* FUN_00500940();
    bool FUN_009866d0(MergeActor* actor);
    bool FUN_009867d0(MergeActor* actor);
    bool FUN_00986410(MergeActor* actor);
    MergeMember* FUN_009865f0(MergeActor* actor);
    MergeTarget* FUN_009865d0(MergeActor* actor);
    char GetFlagsFromSubobject();
    int GetArrayItem(unsigned char index);
    void ClearGlobalObject();
    char GetByteAtOffset154();
    bool MergeFrom(ActorMergeData* other);
};
struct DebugPoint
{
    float x, y, z;
};
struct DebugColor
{
    float r, g, b, a;
    DebugColor(float, float, float, float);
};
struct DebugMaterial
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DebugMaterial();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void FUN_0049ed90(bool);
};
struct DebugUpdate
{
    float time;
    int flags, unk08;
    DebugUpdate(float, int, int);
};
struct DebugNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(DebugNode*, bool);
    virtual void v56();
    virtual void v57();
    virtual void Detach(DebugNode*);
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    DebugNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    DebugNode* FUN_009611e0();
    void FUN_004bc1f0(float, float, float);
    void FUN_00440460(const DebugPoint&);
    void FUN_00439410(DebugMaterial*);
    void FUN_00a5a040();
    void FUN_00a59c60(const DebugUpdate&);
};
struct DebugNodePtr
{
    DebugNode* ptr;
    DebugNode* FUN_00559450();
    void FUN_0066b0d0(DebugNode*);
};
void* FUN_00aa13e0(unsigned int);
void FUN_00aa13f0(void*);
__forceinline void* DebugNode::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugNode::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
__forceinline void* DebugMaterial::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugMaterial::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct DebugDetach
{
    void FUN_0087ac60();
};
bool FUN_008c7aa0();
DebugDetach* __stdcall FUN_004537b0(DebugNode*);
struct DebugScene
{
    DebugNode* FUN_00524cf0();
};
struct DebugGroup;
struct DebugActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const DebugPoint& Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual DebugGroup* Group();
    unsigned int FUN_00575ca0();
    DebugScene* FUN_008d6f30();
    float FUN_008be1b0();
};
extern DebugActor* DAT_011dea3c;
extern DebugActor* DAT_011dea24;
struct DebugSetting
{
    bool* FUN_00408d60();
};
extern DebugSetting DAT_011f1824, DAT_011f1858, DAT_011f1814;
extern bool DAT_011a4d34;
extern float DAT_011a4d2c;
struct DebugSearchPoint
{
    const DebugPoint& FUN_006815c0();
    unsigned int FUN_0084e3a0();
    DebugColor GetEffectColor();
};
struct DebugMember
{
    DebugActor* actor;
    int unk04, unk08, unk0c;
    DebugSearchPoint* point;
};
struct DebugPair
{
    DebugActor* first;
    DebugActor* second;
    char unk08;
    bool blue, green;
    char unk0b;
};
struct DebugPoints
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    DebugSearchPoint*& FUN_006a7ad0(unsigned int);
};
struct DebugPairs
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    DebugPair* FUN_006a7af0(unsigned int);
};
struct DebugBuilder
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    DebugBuilder(DebugPoint, float);
    static void* operator new(unsigned int);
    static void operator delete(void*);
    DebugNode* CreateSortAdjustNode();
};
__forceinline void* DebugBuilder::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugBuilder::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct DebugBuilderPtr
{
    DebugBuilder* ptr;
    DebugBuilderPtr(DebugBuilder*);
    ~DebugBuilderPtr();
    DebugBuilder* FUN_00559450();
};
struct DebugSearch
{
    float FUN_00508050();
    DebugPoint GetLocationAndReturn();
    void UpdateNavMeshes(DebugBuilderPtr&);
};
struct DebugSearchPtr
{
    DebugSearch* ptr;
    DebugSearch* FUN_00559450();
};
const DebugColor& FUN_005d8550(int);
DebugNode* FUN_00c5a0f0(const DebugPoint&, const DebugPoint&, float, float, const DebugColor*, const DebugColor*);
DebugNode* FUN_00c58f00(float, int, const DebugColor*);
DebugNode* FUN_00c58d30(float, float, float, int, int, const DebugColor*);
DebugNode* FUN_00c56680(float, int, int, const DebugColor*);
void AttachLightingPropertyRecursive(DebugNode*);
void FUN_00b57e30(DebugNode*, int, int);
struct DebugGroup
{
    unsigned int id;
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
    DebugSearchPtr search;
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
    DebugPairs pairs;
    DebugNodePtr searchNode;
    bool searchDirty;
    char unk135, unk136, unk137;
    DebugPoints points;
    int unk148, unk14c, unk150, unk154;
    DebugNodePtr debug;
    unsigned int FUN_00990890();
    DebugMember* FUN_00988790(unsigned int);
    DebugActor* GetIntAt(unsigned int);
    unsigned int FUN_00988750();
    DebugSearchPoint* ForwardToMember(unsigned int);
    void RebuildDebugVisuals(bool);
};
namespace CombatAssessment {
struct Actor;
struct Point;
struct PositionData;
typedef PositionData Position;
struct Target;
struct Group;
struct SenseData;
typedef SenseData Sense;
struct Hit;
extern float DAT_0108d540;
float __cdecl FUN_00435dd0();
float __cdecl FUN_0040ebd0(float, float);
struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011cd45c, DAT_011ce9b4;
struct Time
{
    int value;
    void FUN_00435de0(float);
    float FUN_006a7f50();
    float FUN_00435e00();
};

struct Point
{
    float x, y, z;
};
struct PositionData
{
    Point point;
    int cell;
    void FUN_0097ede0();
    float FUN_00527a40(Position*);
    void SetTripleAndValue(Point*, void*);
    int FUN_0084e3a0();
};
typedef PositionData Position;
struct SenseData
{
    int unk00;
    int unk04;
    int score;
    Point point;
    Time time;
    bool detected;
    char unk1d;
    bool visible;
    char unk1f;
    int score20;
    void FUN_0066e590();
};
typedef SenseData Sense;
struct Target
{
    int unk00;
    int score;
    Position lastKnown;
    Position search;
    Position seen;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    short state;
    short unk4a;
    Time seenTime;
    Time activeTime;
    Time updateTime;
    Time alertTime;
    Time hitTime;
    Time cooldown;
    unsigned char visibleCount;
    unsigned char detectedCount;
    short unk66;
};
struct Hit
{
    int unk00;
    Point point;
    Time time;
};
struct Process
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
    virtual Hit* vf8(Actor*);
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
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual Sense* v504(Actor*, int);
};
struct DetectionViewData
{
    bool FUN_0099a360();
};
struct CombatState
{
    Actor* FUN_004030b0();
    DetectionViewData* FUN_00586150(Actor*, Actor*);
};
struct Actor
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
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual CombatState* v428();
    virtual void* v42c();
    Process* FUN_008d8520();
    int FUN_00931850();
    void FUN_00575650(Position*);
    void* FUN_00575ca0();
    void* FUN_005d43c0();
};
extern Actor* DAT_011dea3c;
void __cdecl MarkBaseExtraListScriptEvent(void*, void*, int);
struct Manager
{
    void TryStartDialogue(Actor*, Actor*, int, int, int, int);
};
extern Manager* DAT_011f1708;
struct Group
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    short state;
    Target* FUN_009865d0(Actor*);
    unsigned int FUN_00990890();
    Actor* GetIntAt(unsigned int);
    bool FUN_0097ef30();
    void StoreRecord(Position*, float, int);
    void UpdateTargetPerception(Actor*, Actor*, int*, Time*, bool*, bool*);
};
// @fnv 0x009887b0
void Group::UpdateTargetPerception(Actor* selected, Actor* subject, int* result, Time* timestamp, bool* visible,
                                   bool* detected)
{
    Time temp4Local2;
    Time temp3Local31;
    Time temp2Local6;
    Time temp1Local7;
    Time temp0Local20;
    Sense* reusedLocal18;
    float strengthLocal6;
    Position impactLocal48;
    Hit* hitLocal9;
    Actor* member2Local23;
    unsigned int index2Local31;
    CombatState* stateLocal7;
    int scoreLocal7;
    Position originLocal30;
    Position destinationLocal23;
    Actor* memberLocal19;
    Sense* senseLocal1;
    Sense fallbackLocal15;
    unsigned int indexLocal5;
    Actor* bestLocal4;
    Position nearestLocal9;
    Position currentLocal8;
    Time newestLocal2;
    unsigned int countLocal20;
    int maximumLocal6;
    bool missingLocal40;
    int highestLocal52;
    int previousLocal5;
    Target* targetLocal40;

    *visible = false;
    *detected = false;
    *result = -100;
    temp0Local20.FUN_00435de0(-DAT_0108d540);
    *timestamp = temp0Local20;
    targetLocal40 = FUN_009865d0(subject);
    if (targetLocal40)
    {
        previousLocal5 = targetLocal40->score;
        if (targetLocal40->updateTime.FUN_006a7f50() < FUN_00435dd0())
        {
            maximumLocal6 = -100;
            highestLocal52 = -100;
            missingLocal40 = false;
            if (!targetLocal40->search.FUN_0084e3a0())
                missingLocal40 = true;
            bestLocal4 = 0;
            targetLocal40->detectedCount = 0;
            targetLocal40->visibleCount = 0;
            nearestLocal9.FUN_0097ede0();
            newestLocal2.FUN_00435de0(-DAT_0108d540);
            countLocal20 = FUN_00990890();
            for (indexLocal5 = 0; indexLocal5 < countLocal20; indexLocal5++)
            {
                memberLocal19 = GetIntAt(indexLocal5);
                senseLocal1 = memberLocal19->FUN_008d8520()->v504(subject, 0);
                fallbackLocal15.FUN_0066e590();
                if (memberLocal19->FUN_00931850() && subject->FUN_00931850())
                {
                    memberLocal19->FUN_00575650(&originLocal30);
                    subject->FUN_00575650(&destinationLocal23);
                    if (originLocal30.FUN_00527a40(&destinationLocal23) < 67108864.0)
                    {
                        fallbackLocal15.score = 1;
                        senseLocal1 = &fallbackLocal15;
                    }
                }
                if (senseLocal1)
                {
                    if (senseLocal1->visible)
                        targetLocal40->visibleCount++;
                    if (senseLocal1->detected)
                        targetLocal40->detectedCount++;
                    if (memberLocal19 == selected)
                    {
                        *visible = senseLocal1->visible;
                        *detected = senseLocal1->detected;
                    }
                    scoreLocal7 = senseLocal1->score;
                    if (senseLocal1->score20 != 0x7fffffff)
                    {
                        if (highestLocal52 < senseLocal1->score20)
                            highestLocal52 = senseLocal1->score20;
                        if (scoreLocal7 == (int)*DAT_011cd45c.FUN_00403e20() + 1 &&
                            senseLocal1->score20 > *DAT_011cd45c.FUN_00403e20())
                            scoreLocal7 = (int)*DAT_011cd45c.FUN_00403e20();
                    }
                    stateLocal7 = memberLocal19->v428();
                    if (!stateLocal7 || stateLocal7->FUN_004030b0() != subject ||
                        stateLocal7->FUN_00586150(memberLocal19, subject)->FUN_0099a360())
                    {
                        if (senseLocal1 && scoreLocal7 > maximumLocal6)
                        {
                            maximumLocal6 = scoreLocal7;
                            bestLocal4 = memberLocal19;
                        }
                    }
                    else
                    {
                        if (previousLocal5 > maximumLocal6)
                        {
                            maximumLocal6 = previousLocal5;
                            bestLocal4 = memberLocal19;
                        }
                    }
                    if (missingLocal40 && senseLocal1->time.FUN_006a7f50() > newestLocal2.FUN_006a7f50())
                    {
                        nearestLocal9.SetTripleAndValue(&senseLocal1->point, memberLocal19->FUN_00575ca0());
                        newestLocal2 = senseLocal1->time;
                    }
                }
            }
            if (maximumLocal6 <= (int)*DAT_011cd45c.FUN_00403e20() && targetLocal40->cooldown.FUN_00435e00() < 1.0)
                maximumLocal6 = (int)(*DAT_011cd45c.FUN_00403e20() + 1.0);
            if (FUN_0097ef30() && previousLocal5 <= 0 && maximumLocal6 > 0)
            {
                if (targetLocal40->activeTime.FUN_006a7f50() != -DAT_0108d540)
                    DAT_011f1708->TryStartDialogue(bestLocal4, subject, 4, 9, 1, 0);
                else
                {
                    for (index2Local31 = 0; index2Local31 < countLocal20; index2Local31++)
                    {
                        member2Local23 = GetIntAt(index2Local31);
                        if (member2Local23 != DAT_011dea3c)
                            MarkBaseExtraListScriptEvent(member2Local23->v42c(), member2Local23->FUN_005d43c0(), 0x8000);
                    }
                    DAT_011f1708->TryStartDialogue(bestLocal4, subject, 4, 3, 1, 0);
                }
            }
            targetLocal40->score = maximumLocal6;
            {
                temp1Local7.FUN_00435de0(FUN_00435dd0());
                targetLocal40->updateTime = temp1Local7;
            }
            subject->FUN_00575650(&currentLocal8);
            if (maximumLocal6 > 0)
            {
                temp2Local6.FUN_00435de0(FUN_00435dd0());
                targetLocal40->activeTime = temp2Local6;
            }
            if (targetLocal40->activeTime.FUN_00435e00() < *DAT_011ce9b4.FUN_00403e20())
                targetLocal40->search = currentLocal8;
            else if (missingLocal40)
                targetLocal40->search = nearestLocal9;
            if (maximumLocal6 > (int)*DAT_011cd45c.FUN_00403e20())
            {
                {
                    temp3Local31.FUN_00435de0(FUN_00435dd0());
                    targetLocal40->alertTime = temp3Local31;
                }
                targetLocal40->lastKnown = currentLocal8;
                targetLocal40->state = this->state;
            }
            if (targetLocal40->detectedCount)
            {
                targetLocal40->seen = currentLocal8;
                {
                    temp4Local2.FUN_00435de0(FUN_00435dd0());
                    targetLocal40->seenTime = temp4Local2;
                }
            }
            if (highestLocal52 > *DAT_011cd45c.FUN_00403e20() && FUN_0097ef30())
            {
                hitLocal9 = subject->FUN_008d8520()->vf8(subject);
                if (hitLocal9 && hitLocal9->time.FUN_00435e00() < 5.0 &&
                    hitLocal9->time.FUN_006a7f50() > targetLocal40->hitTime.FUN_006a7f50())
                {
                    strengthLocal6 = 0;
                    if (highestLocal52 > 0)
                        strengthLocal6 = FUN_0040ebd0((float)(highestLocal52 / 20.0), 5.0f) + 55.0;
                    else
                        strengthLocal6 = (highestLocal52 - (int)*DAT_011cd45c.FUN_00403e20()) / 2.0 + 40.0;
                    impactLocal48.FUN_0097ede0();
                    impactLocal48.SetTripleAndValue(&hitLocal9->point, subject->FUN_00575ca0());
                    StoreRecord(&impactLocal48, strengthLocal6, 0);
                    targetLocal40->hitTime = hitLocal9->time;
                }
            }
        }
        else
        {
            reusedLocal18 = selected ? selected->FUN_008d8520()->v504(subject, 0) : 0;
            if (reusedLocal18)
            {
                *visible = reusedLocal18->visible;
                *detected = reusedLocal18->detected;
            }
        }
        *result = targetLocal40->score;
        *timestamp = targetLocal40->activeTime;
    }
}
}
template <class T> class SettingT;
class GameSettingCollection;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting382;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting383;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting384;
float& __fastcall FUN_00403e20(float* pValue);
extern float DAT_010162c0;
struct Pos9892
{
    float x;
    float y;
    float z;

    Pos9892 FUN_00439e90(const Pos9892& kOther) const;
    Pos9892 FUN_00439ef0(const Pos9892& kOther) const;
    Pos9892 FUN_0053d280(float fScale) const;
    float FUN_004a7290() const;
};
struct FUN_006915d0
{
    float m_af[9];

    FUN_006915d0(const Pos9892& kPos);
};
struct AvoidArray9892 : PathingAvoidNodeArray
{
    void AppendNode(const FUN_006915d0& kNode, float fA, float fB);
};
struct AvoidMember9892
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
    virtual void v064();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pos9892* GetPos();
};
struct FUN_009892a0_shell
{
    unsigned int FUN_005a4320();
    AvoidMember9892* FUN_00968630(unsigned int uiIndex);
    PathingAvoidNodeArray* FUN_009892a0(AvoidMember9892* pActor, const Pos9892* pTarget, float fRadius,
                                        PathingAvoidNodeArray* pAvoidArray, AvoidMember9892* pIgnore);
};
namespace CombatRegion {
struct Actor;
struct Group;
struct Vec
{
    float x, y, z;
    Vec();
};
struct Point
{
    float x, y, z;
    float FUN_00435e00();
    float FUN_006a7f50();
};
struct Target
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
    unsigned short unk48, flags;
    unsigned int unk4c;
    Point point;
};
struct Location
{
    unsigned int unk00, unk04, unk08, unk0c;
    bool FUN_00527a00();
    bool FUN_00527990(unsigned int*, unsigned int*);
    void* FUN_006815c0();
    void* FUN_0084e3a0();
};
struct Timer
{
    unsigned int unk00, unk04;
    bool FUN_008d7f80();
    void FUN_0097f220();
    void FUN_008d7f40(float);
};
struct Region
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Region(const Vec&, unsigned int, unsigned int);
    Region(Actor*);
    ~Region();
    bool FUN_006dd6f0(int);
    void FUN_006f4ed0(void*);
    bool FUN_0098ad70();
};
struct RegionArray
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    RegionArray(unsigned int, int, int);
    ~RegionArray();
    void FUN_006cf1b0(const Region&);
    unsigned int FUN_0044ddc0();
};
struct FloatArray
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    FloatArray(unsigned int, int, int);
    ~FloatArray();
    void AppendFloat(const float&);
};
struct Shape
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

    Shape();
    static __forceinline void* operator new(unsigned int);
    static __forceinline void operator delete(void*)
    {}
    float FUN_004a7bd0();
    void Reset();
    void FUN_006e0320(const Region&, float);
    void FUN_0098adb0(float);
};
void* FUN_00aa13e0(unsigned int);
__forceinline void* Shape::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
struct ShapePtr
{
    Shape* value;
    Shape* FUN_00559450();
    void FUN_0066b0d0(Shape*);
};
struct Actor
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
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual float Heading(int);
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual Group* ActorCombatGroup();
    bool FUN_008b3b90();
    bool FUN_008b3bf0();
    void* FUN_00575ca0();
};
struct Setting
{
    float* FUN_00403e20();
};
extern Setting DAT_011ce9b4, DAT_011ce528, DAT_011cf870, DAT_011cf42c, DAT_011ce43c;
extern double DAT_0106d508;
extern float DAT_0108d540;
extern Actor* DAT_011dea3c;
struct Manager
{
    void TryStartDialogue(Actor*, Group*, int, int, int, int);
};
extern Manager* DAT_011f1708;
bool FUN_006d6f80(unsigned int, unsigned int, const Vec&, Vec&);
float FUN_004b1480(float);
void BuildPathNodeHolder(ShapePtr*, RegionArray*, FloatArray*);
unsigned int FUN_00944460(unsigned int, unsigned int);
struct Group
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
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int generation;
    ShapePtr shape;
    Timer updateTimer;
    Timer refreshTimer;
    unsigned int unke8;
    Actor* focus;
    Location location;
    Vec position;
    float radius;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned char changed;
    unsigned char unk135;
    unsigned short unk136;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int capacity;
    unsigned int count;
    unsigned int FUN_005a4320();
    bool FUN_0097ef30();
    void FUN_0098bae0();
    Target* FUN_009871c0(unsigned int);
    void FUN_0098add0();
    bool UpdateAndCheckChanged();
    unsigned int FUN_00990890();
    Actor* GetIntAt(unsigned int);
    Target* FUN_009865d0(Group*);
    void FUN_0098a580();
};
// @fnv 0x0098a580
void Group::FUN_0098a580()
{
    if (capacity)
    {
        unsigned int total = FUN_005a4320();
        bool fullSlot14 = false;
        if (!total || count >= capacity)
            fullSlot14 = true;
        if (FUN_0097ef30())
        {
            if (fullSlot14)
                FUN_0098bae0();
            else
            {
                for (unsigned int index = 0; index < total; index++)
                {
                    Target* target = FUN_009871c0(index);
                    if (target->point.FUN_00435e00() < *DAT_011ce9b4.FUN_00403e20())
                    {
                        FUN_0098bae0();
                        break;
                    }
                }
            }
        }
        else if (!fullSlot14)
        {
            unsigned int farCountSlot0 = 0;
            unsigned int flaggedSlot0 = 0;
            for (unsigned int index = 0; index < total; index++)
            {
                Target* target = FUN_009871c0(index);
                if (target->point.FUN_00435e00() >= *DAT_011ce528.FUN_00403e20())
                    farCountSlot0++;
                if (target->flags)
                    flaggedSlot0++;
            }
            if (flaggedSlot0 && farCountSlot0 == total)
                FUN_0098add0();
        }
    }
    if (FUN_0097ef30())
    {
        if (focus && (focus->FUN_008b3b90() || !focus->FUN_008b3bf0()))
            focus = 0;
        if (updateTimer.FUN_008d7f80())
        {
            if (shape.FUN_00559450() && shape.FUN_00559450()->FUN_004a7bd0() > DAT_0106d508)
            {
                shape.FUN_00559450()->Reset();
                generation++;
                refreshTimer.FUN_0097f220();
            }
            bool refreshSlot1 = false;
            if (refreshTimer.FUN_008d7f80())
            {
                refreshSlot1 = UpdateAndCheckChanged();
                refreshTimer.FUN_008d7f40(*DAT_011cf870.FUN_00403e20());
            }
            if (location.FUN_00527a00())
            {
                if (!shape.FUN_00559450() || refreshSlot1)
                {
                    unsigned int endSlot0 = 0;
                    unsigned int start = 0;
                    if (location.FUN_00527990(&start, &endSlot0))
                    {
                        Vec selected;
                        if (FUN_006d6f80(endSlot0, start, position, selected))
                        {
                            Region region(selected, start, endSlot0);
                            if (region.FUN_006dd6f0(0))
                            {
                                region.FUN_006f4ed0(location.FUN_006815c0());
                                if (!shape.FUN_00559450())
                                    shape.FUN_0066b0d0(new Shape);
                                shape.FUN_00559450()->FUN_006e0320(region, radius);
                                shape.FUN_00559450()->FUN_0098adb0(*DAT_011cf42c.FUN_00403e20());
                                changed = 1;
                            }
                        }
                    }
                }
            }
            else if (shape.FUN_00559450())
                shape.FUN_0066b0d0(0);
            if (shape.FUN_00559450())
            {
                unsigned int memberCount = FUN_00990890();
                RegionArray regionsSlot11(memberCount, 0, 0);
                FloatArray headingsSlot11(memberCount, 0, 0);
                for (unsigned int memberIndex = 0; memberIndex < memberCount; memberIndex++)
                {
                    Actor* member = GetIntAt(memberIndex);
                    if (member->FUN_00575ca0() != location.FUN_0084e3a0())
                        continue;
                    Region memberRegionSlot0(member);
                    if (memberRegionSlot0.FUN_0098ad70())
                    {
                        regionsSlot11.FUN_006cf1b0(memberRegionSlot0);
                        headingsSlot11.AppendFloat(FUN_004b1480(member->Heading(0)));
                    }
                }
                if (regionsSlot11.FUN_0044ddc0())
                {
                    float previous = shape.FUN_00559450()->FUN_004a7bd0();
                    BuildPathNodeHolder(&shape, &regionsSlot11, &headingsSlot11);
                    if (previous != shape.FUN_00559450()->FUN_004a7bd0())
                        changed = 1;
                }
            }
            updateTimer.FUN_008d7f40(*DAT_011ce43c.FUN_00403e20());
            unsigned int actorCountSlot3 = FUN_00990890();
            unsigned int chosenSlot40 = FUN_00944460(0, actorCountSlot3);
            Actor* actor = GetIntAt(chosenSlot40);
            Group* otherSlot37 = actor->ActorCombatGroup();
            if (actor != DAT_011dea3c && otherSlot37)
            {
                Target* target = FUN_009865d0(otherSlot37);
                if (target && target->point.FUN_006a7f50() != -DAT_0108d540)
                    DAT_011f1708->TryStartDialogue(actor, otherSlot37, 4, 1, 0, 0);
                else
                    DAT_011f1708->TryStartDialogue(actor, otherSlot37, 4, 0, 0, 0);
            }
        }
    }
}
}
// Recount the group's members: how many are flagged, and how many are alive versus not.
class CE80Process
{
  public:
    bool IsFlagged();
    bool IsAlive();
};
class CE80Actor
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual void Unk1D0();
    virtual void Unk1D4();
    virtual void Unk1D8();
    virtual void Unk1DC();
    virtual void Unk1E0();
    virtual void Unk1E4();
    virtual void Unk1E8();
    virtual void Unk1EC();
    virtual void Unk1F0();
    virtual void Unk1F4();
    virtual void Unk1F8();
    virtual void Unk1FC();
    virtual void Unk200();
    virtual void Unk204();
    virtual void Unk208();
    virtual void Unk20C();
    virtual void Unk210();
    virtual void Unk214();
    virtual void Unk218();
    virtual void Unk21C();
    virtual void Unk220();
    virtual void Unk224();
    virtual void Unk228();
    virtual void Unk22C();
    virtual void Unk230();
    virtual void Unk234();
    virtual void Unk238();
    virtual void Unk23C();
    virtual void Unk240();
    virtual void Unk244();
    virtual void Unk248();
    virtual void Unk24C();
    virtual void Unk250();
    virtual void Unk254();
    virtual void Unk258();
    virtual void Unk25C();
    virtual void Unk260();
    virtual void Unk264();
    virtual void Unk268();
    virtual void Unk26C();
    virtual void Unk270();
    virtual void Unk274();
    virtual void Unk278();
    virtual void Unk27C();
    virtual void Unk280();
    virtual void Unk284();
    virtual void Unk288();
    virtual void Unk28C();
    virtual void Unk290();
    virtual void Unk294();
    virtual void Unk298();
    virtual void Unk29C();
    virtual void Unk2A0();
    virtual void Unk2A4();
    virtual void Unk2A8();
    virtual void Unk2AC();
    virtual void Unk2B0();
    virtual void Unk2B4();
    virtual void Unk2B8();
    virtual void Unk2BC();
    virtual void Unk2C0();
    virtual void Unk2C4();
    virtual void Unk2C8();
    virtual void Unk2CC();
    virtual void Unk2D0();
    virtual void Unk2D4();
    virtual void Unk2D8();
    virtual void Unk2DC();
    virtual void Unk2E0();
    virtual void Unk2E4();
    virtual void Unk2E8();
    virtual void Unk2EC();
    virtual void Unk2F0();
    virtual void Unk2F4();
    virtual void Unk2F8();
    virtual void Unk2FC();
    virtual void Unk300();
    virtual void Unk304();
    virtual void Unk308();
    virtual void Unk30C();
    virtual void Unk310();
    virtual void Unk314();
    virtual void Unk318();
    virtual void Unk31C();
    virtual void Unk320();
    virtual void Unk324();
    virtual void Unk328();
    virtual void Unk32C();
    virtual void Unk330();
    virtual void Unk334();
    virtual void Unk338();
    virtual void Unk33C();
    virtual void Unk340();
    virtual void Unk344();
    virtual void Unk348();
    virtual void Unk34C();
    virtual void Unk350();
    virtual void Unk354();
    virtual void Unk358();
    virtual void Unk35C();
    virtual void Unk360();
    virtual void Unk364();
    virtual void Unk368();
    virtual void Unk36C();
    virtual void Unk370();
    virtual void Unk374();
    virtual void Unk378();
    virtual void Unk37C();
    virtual void Unk380();
    virtual void Unk384();
    virtual void Unk388();
    virtual void Unk38C();
    virtual void Unk390();
    virtual void Unk394();
    virtual void Unk398();
    virtual void Unk39C();
    virtual void Unk3A0();
    virtual void Unk3A4();
    virtual void Unk3A8();
    virtual void Unk3AC();
    virtual void Unk3B0();
    virtual void Unk3B4();
    virtual void Unk3B8();
    virtual void Unk3BC();
    virtual void Unk3C0();
    virtual void Unk3C4();
    virtual void Unk3C8();
    virtual void Unk3CC();
    virtual void Unk3D0();
    virtual void Unk3D4();
    virtual void Unk3D8();
    virtual void Unk3DC();
    virtual void Unk3E0();
    virtual void Unk3E4();
    virtual void Unk3E8();
    virtual void Unk3EC();
    virtual void Unk3F0();
    virtual void Unk3F4();
    virtual void Unk3F8();
    virtual void Unk3FC();
    virtual void Unk400();
    virtual void Unk404();
    virtual void Unk408();
    virtual void Unk40C();
    virtual void Unk410();
    virtual void Unk414();
    virtual void Unk418();
    virtual void Unk41C();
    virtual void Unk420();
    virtual void Unk424();
    virtual CE80Process* GetProcess();
};
class CE80Group
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    unsigned int m_uiFlagged;
    unsigned int m_uiAlive;
    unsigned int m_uiOther;

    unsigned int GetCount();
    CE80Actor* GetAt(int iIndex);
    void RecountActors();
};
struct LoadBuf
{
    virtual unsigned char Version();
    unsigned int FUN_00864a60();
    void FUN_00864980(void*, unsigned int);
    void FUN_008648e0(void*);
    unsigned int FUN_008648a0();
};
struct LoadPair
{
    int x, y;
    void FUN_009a5f20(LoadBuf*);
};
struct LoadRef
{
    int x;
    void FUN_009a5ff0(LoadBuf*);
};
struct LoadItem
{
    int x00, x04, x08, x0c, x10;
    LoadItem();
    void FUN_00985b10(LoadBuf*, void*);
};
struct LoadNode
{
    void FUN_00985800(LoadBuf*, void*);
};
struct MemberNode
{
    void FUN_00985a50(LoadBuf*, void*);
};
struct LoadExtra
{
    int x00, x04, x08, x0c;
    LoadRef ref;
    int id;
    int value;
    void FUN_00527ba0(LoadBuf*);
};
struct TESObjectREFR : TESForm
{
};
struct ParentNode
{
    TESObjectREFR* a;
    TESObjectREFR* b;
    char c, d, e;
};
struct LoadAnim
{
    int x00;
    int x04;
    int x08;
    int x0c;
    int x10;
    int x14;
    int x18;
    int x1c;
    int x20;
    int x24;
    int x28;
    int x2c;
    int x30;
    int x34;
    int x38;
    int x3c;
    int x40;
    int x44;
    int x48;
    int x4c;
    int x50;
    LoadAnim();
    static void* operator new(unsigned int);
    void FUN_006e0d20(LoadBuf*);
};
struct LoadPtr
{
    LoadAnim* p;
    LoadPtr& operator=(LoadAnim*);
    operator LoadAnim*() const;
};
struct ArrItems
{
    int x0, x4, x8, xc;
    void SetSize(unsigned int, bool);
    LoadItem*& FUN_006a7ad0(unsigned int);
};
struct ArrNodes
{
    int x0, x4, x8, xc;
    void FUN_0098ed80(unsigned int, bool);
    LoadNode* FUN_0096a2b0(unsigned int);
};
struct ArrMembers
{
    int x0, x4, x8, xc;
    void FUN_0098f040(unsigned int, bool);
    MemberNode* FUN_006dad90(unsigned int) const;
};
struct ArrExtra
{
    int x0, x4, x8, xc;
    void FUN_0098f2f0(unsigned int, bool);
    LoadExtra* GetElementAt(unsigned int);
};
struct ArrParents
{
    int x0, x4, x8, xc;
    void FUN_006a8890(unsigned int, bool);
    ParentNode& GetAt(int);
};
struct LoadHandle
{
    int x0, x4, x8, xc;
    void FUN_00527ba0(LoadBuf*);
};
struct GroupLoad
{
    int unk000;
    int unk004;
    ArrNodes nodes;
    ArrMembers members;
    int strategy;
    char flag;
    char unk02d;
    char unk02e;
    char unk02f;
    LoadPair pair30;
    LoadPair pair38;
    int unk040;
    LoadRef ref44;
    LoadPair pair48;
    LoadPair pair50;
    LoadPair timers[10];
    LoadPair paira8;
    LoadPair pairb0;
    LoadPair pairb8;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    unsigned int active;
    LoadPtr anim;
    LoadPair paird8;
    LoadPair paire0;
    LoadRef refe8;
    int unk0ec;
    LoadHandle handle;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    ArrExtra extras;
    ArrParents parents;
    int unk130;
    char loaded;
    char unk135;
    char unk136;
    char unk137;
    ArrItems items;
    int unk148;
    int unk14c;
    int unk150;
    char flag154;
    void FUN_0098e3d0(LoadBuf* buffer);
};
struct UpdateOwner;
struct UpdateElement
{
    unsigned int data;
    void FUN_00985930(unsigned int, UpdateOwner*);
};
struct UpdateArray
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    UpdateElement* FUN_0096a2b0(unsigned int);
    UpdateElement* FUN_006dad90(unsigned int);
    void FUN_0098ef10(unsigned int, unsigned int);
    void RemoveEntries(unsigned int, unsigned int);
};
struct UpdateManager
{
    void FUN_00992a50(unsigned int, UpdateOwner*);
};
extern UpdateManager* DAT_011f1958;
extern const unsigned int DAT_01183028, DAT_011846d4;
void* FUN_00ec43fb(void*, int, const void*, const void*, int);
struct UpdateOwner
{
    int unk00, unk04;
    UpdateArray first, second;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    union
    {
        unsigned int id;
        Actor* actor;
    } reference;
    bool FUN_0097ef30();
    void RecountActors();
    void UpdateElements(unsigned int);
};
struct CFUN98fb40Elem
{
    void* pActor;
    unsigned int m_uiGoalFlags;
    float m_fClusterOffsetX;
    float m_fClusterOffsetY;
    void* pCluster;

    CFUN98fb40Elem();
};
struct CFUN98fb40Owner
{
    void __thiscall FUN_0098fb40(CombatClusterMember* pDest, unsigned int ItemUpdateArray);
};
struct ScoreValue
{
    int value;
    ScoreValue(float x);
    ScoreValue();
    float FUN_006a7f50();
    float FUN_00435e00();
};
struct PoseData
{
    float a, b, c;
    int d;
    int FUN_0084e3a0();
    float FUN_00527a40(const PoseData*);
};
struct MovementPose;
struct OtherState
{
    ScoreValue GetValue98();
    bool FUN_0097ee90();
    bool IsModifierZero();
    bool HasItemWithinRadius(const PoseData*, float);
};
struct MovementPose
{
    float FUN_00639aa0();
    PoseData* GetValue98();
};
struct ConditionFlag
{
    bool FUN_0076b610();
};
struct ConfigSwitch
{
    unsigned char* FUN_00408d60();
};
extern ConfigSwitch DAT_011f1840;
extern float DAT_0108d540, DAT_0101ff50, DAT_0108d660, DAT_011a4d78, DAT_011a4d74;
extern float DAT_011a4d70, DAT_011a4d6c, DAT_011a4d68, DAT_011a4d64, DAT_011a4d60;
extern float DAT_011f18b0, DAT_01032adc, DAT_011a4d5c, DAT_011a4d58, DAT_011a4d54, DAT_011a4d50;
extern double DAT_01012060, DAT_01023128, DAT_0108d658, DAT_0101db88;
struct ActorSelect
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
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual int GetDistanceValue();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool GetFirstCondition(int);
    virtual bool GetSecondCondition();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual ActorSelect* GetTarget();
    int FUN_004030b0();
    OtherState* FUN_00586150();
    MovementPose* FUN_00980070();
    int FUN_00567d90();
    bool FUN_00566950();
    bool IsHostileTo(ActorSelect*, int, int*, int);
    void FUN_00575650(PoseData*);
    bool FUN_008a6650(int);
};
struct CandidateLink
{
    ActorSelect* actor;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned short unk48;
    unsigned short threshold;
    int unk4c, unk50, unk54;
    ScoreValue timestamp;
};
extern bool __cdecl FUN_009a9630(ActorSelect*);
extern bool __cdecl IsWithinAimLimits(ActorSelect*, int, float, float);
extern bool __cdecl FUN_009a96f0(ActorSelect*, PoseData*);
extern float __cdecl FUN_0040ebd0(float, float);
extern float __cdecl FUN_00404010(float, float);
struct ActorPicker
{
    int unk00;
    int unk04;
    ConditionFlag condition;
    int unk0c;
    void FUN_009869a0(ActorSelect*);
    int FUN_005a4320();
    CandidateLink* FUN_009871c0(unsigned int);
    void UpdateTargetPerception(ActorSelect*, ActorSelect*, int*, ScoreValue*, bool*, bool*);
    ActorSelect* SelectActor(ActorSelect*);
};
struct B989700Entry
{
    B9897F0Ref* m_pkRef;
    bool IsElapsedTimeBelowSetting();
};
struct B989700List
{
    unsigned int FUN_005a4320();
    B989700Entry* FUN_009871c0(unsigned int uiIndex);
    B9897F0Ref* FindRefInRadius(B9897F0Point* pkPoint, float fRadius, bool bCheck);
};
struct B9898B0Group
{
    unsigned int FUN_00990890();
    B9897F0Ref* GetIntAt(unsigned int uiIndex);
    B9897F0Ref* FindClosestRef(B9897F0Point* pkPoint, B9897F0Ref* pkExclude, float fRadius);
};
struct AssessmentSub
{
    float GetFirstLightParameter();
    float FUN_00453700();
};
struct AssessmentProcess
{
    bool FUN_00981990();
    AssessmentSub* FUN_00586150();
};
struct AssessmentActor : FUN_0098cb30_inner
{
    float FUN_008be600();
    float GetModifiedDamagePerSecond(float);
    bool FUN_008a6650(int);
};
struct TargetAssessmentEntry
{
    AssessmentActor* actor;
    int unk04;
    float unk08;
    float unk0C;
};
struct TargetAssessmentGroup
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float unkC0;
    float unkC4;
    float unkC8;
    float unkCC;

    unsigned int FUN_00990890();
    TargetAssessmentEntry* FUN_00988790(unsigned int idx);
    unsigned int FUN_005a4320();
    AssessmentActor* FUN_00968630(unsigned int idx);

    void FUN_0098c870();
};
void __cdecl FUN_005b5e40(const char* fmt, ...);
struct ActQ
{
    virtual void v000(), v001(), v002(), v003(), v004(), v005(), v006(), v007(), v008(), v009(), v010(), v011(), v012(),
        v013(), v014(), v015(), v016(), v017(), v018(), v019(), v020(), v021(), v022(), v023(), v024(), v025(), v026(),
        v027(), v028(), v029(), v030(), v031(), v032(), v033(), v034(), v035(), v036(), v037(), v038(), v039(), v040(),
        v041(), v042(), v043(), v044(), v045(), v046(), v047(), v048(), v049(), v050(), v051(), v052(), v053(), v054(),
        v055(), v056(), v057(), v058(), v059(), v060(), v061(), v062(), v063(), v064(), v065(), v066(), v067(), v068(),
        v069(), v070(), v071(), v072(), v073(), v074(), v075();
    virtual const char* GetNameQ();
    void* FUN_00474cb0();
    const char* FUN_0055d520();
    unsigned int FUN_0084e3a0();
};
struct TgtQ
{
    int unk[26];
    TgtQ* Init(ActQ* pActor, int iVal);
};
struct TgtLstQ
{
    int unk00;
    void FUN_0098eec0(TgtQ* pTarget);
};
struct GrpQ;
struct UpdQ
{
    void FUN_009926c0(GrpQ* pGroup, ActQ* pActor);
};
struct GrpQ
{
    int unk00, unk04;
    TgtLstQ kTargets;
    char pad[0xc4];
    int unkD0;
    bool FUN_009865b0(ActQ*);
    bool FUN_009866d0(ActQ*);
    bool FUN_00986a80(ActQ*);
    bool FUN_00986410(ActQ* pActor);
};
struct Owner_9862e0;
struct Target_9862e0
{
    virtual void v0();
    virtual void v4(Owner_9862e0* owner, void* ctx);
    int FUN_00726070();
};
struct CombatCtx
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    CombatCtx(Owner_9862e0* owner);
    ~CombatCtx();
};
struct Owner_9862e0
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
    Target_9862e0* m28;
    bool m2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int m40;
    TimeValue m44;
    void FUN_0098a3c0();
    void FUN_009862e0(Target_9862e0* target);
};
extern const float DAT_01012054;
struct FUN_00906f60
{
    int a;
    int b;
    FUN_00906f60();
};
struct Member08_985d10
{
    int a, b, c, d;
    Member08_985d10();
    ~Member08_985d10();
};
struct Member18_985d10
{
    int a, b, c, d;
    Member18_985d10();
    ~Member18_985d10();
};
struct Member44_985d10
{
    int a;
    Member44_985d10();
};
struct MemberD4_985d10
{
    void* p;
    MemberD4_985d10(void*);
    ~MemberD4_985d10();
};
struct MemberE8_985d10
{
    float f;
    MemberE8_985d10(float);
};
struct MemberF0_985d10
{
    int a, b, c, d;
    MemberF0_985d10();
};
struct Member110_985d10
{
    int a, b, c, d;
    Member110_985d10();
    ~Member110_985d10();
};
struct Member120_985d10
{
    int a, b, c, d;
    Member120_985d10();
    ~Member120_985d10();
};
struct Member138_985d10
{
    int a, b, c, d;
    Member138_985d10();
    ~Member138_985d10();
};
struct FUN_00985d10
{
    int m_00;
    int m_04;
    Member08_985d10 m_08;
    Member18_985d10 m_18;
    int m_28;
    bool m_2c;
    FUN_00906f60 m_30;
    FUN_00906f60 m_38;
    int m_40;
    Member44_985d10 m_44;
    FUN_00906f60 m_48;
    FUN_00906f60 m_50;
    FUN_00906f60 m_58[10];
    FUN_00906f60 m_a8;
    FUN_00906f60 m_b0;
    FUN_00906f60 m_b8;
    float m_c0;
    float m_c4;
    float m_c8;
    float m_cc;
    int m_d0;
    MemberD4_985d10 m_d4;
    FUN_00906f60 m_d8;
    FUN_00906f60 m_e0;
    MemberE8_985d10 m_e8;
    int m_ec;
    MemberF0_985d10 m_f0;
    NiPoint3 m_100;
    float m_10c;
    Member110_985d10 m_110;
    Member120_985d10 m_120;
    MemberD4_985d10 m_130;
    bool m_134;
    Member138_985d10 m_138;
    int m_148;
    int m_14c;
    int m_150;
    char m_154;
    MemberD4_985d10 m_158;

    FUN_00985d10(int a1);
};
struct AvoidNode9894 : AvoidanceVectorData
{
    AvoidNode9894(const NiPoint3& arPos, float afR, float afHeight);
};
struct AvoidArray9894 : PathingAvoidNodeArray
{
    void AddNode(const AvoidanceVectorData& arNode);
};
struct FUN_00989490_shell
{
    float GetBoundsSq(NiPoint3* apCenter);
    PathingAvoidNodeArray* __thiscall FUN_00989490(int a1, int a2, int a3, PathingAvoidNodeArray* apArray);
};

struct FUN_0096a330_shell
{
    void __thiscall GetEntryAt(int state);
};

// @fnv 0x0096a2b0
void FUN_0096a2b0_stub::FUN_0096a2b0(int state)
{
    reinterpret_cast<FUN_0096a330_shell*>(this)->GetEntryAt(state);
}

unsigned int __fastcall _ref_0084e3a0(unsigned int);

// @fnv 0x009865f0
int FUN_009865f0_shell::FUN_009865f0(int a1)
{
    return (int)((C00986670*)this)->FUN_00986670(_ref_0084e3a0(a1));
}
