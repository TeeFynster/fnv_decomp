#include "../../../../include/NiTArray.h"
#include "../../../../include/Explosion.h"
#include "../../../../include/bhkLiquidAction.h"
#include "../../../../include/BSFadeNode.h"
#include "../../../../include/BSOcclusionPlane.h"
#include "../../../../include/NavMeshPtr.h"
#include "../../../../include/hkMemoryAllocator.h"
// HavokAllocatorContext_explosion: local type (was include/HavokAllocatorContext.h, which had no evidence of one real class); no method of it is bound to a named game function
class HavokMemoryRouter;
class hkMemoryAllocator;

class HavokAllocatorContext_explosion
{
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    union
    {
        HavokMemoryRouter* m_router;
        hkMemoryAllocator* m_alloc;
    };
};

// src/fallout/ai/combat/explosion_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/fallout/ai/combat/explosion_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/ai/combat/explosion_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/ai/combat/explosion.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/ai/combat/explosion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/explosion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl _Deallocate(void*);
extern NiRTTI g_01268420;
struct FUN_009afc30_shell
{
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};
struct FUN_009afbb0_shell
{
    virtual ~FUN_009afbb0_shell();
    void* FUN_009afbb0(unsigned int flags);
    void ForwardCall_009afc10();
};
extern "C" void __cdecl Object_UpdateFields_009afbe0(void*);
struct FUN_00621100_shell
{
    void __thiscall SetVtable(void);
};
struct FUN_009afc10_shell
{
    void __thiscall ForwardCall_009afc10();
};
struct FUN_009afc50_shell
{
    char m_auiShapeKeys[0x14];
    NavMeshPtr m_navMeshPtr;
    NavMesh* hkpFixedBufferCdPointCollector_getHits();
};
struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM g_memoryManager;
void __cdecl FUN_00cbc740();
struct FUN_00cbd4e0_shell
{
    char m_auiShapeKeys[0x14];
    void* FUN_00cbd4e0(unsigned char flag);
};
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct FUN_00cbc650_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
};
struct FUN_00cbc650_cls
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual FUN_00cbc650_obj* vGet(FUN_00cbc650_obj* volatile* pp);
    void bhkUnaryAction_LoadBinary(FUN_00cbc650_obj* a);
    void bhkLiquidAction_LoadBinary(FUN_00cbc650_obj* volatile a1);
};
struct FUN_00cbc6a0_Data
{
    volatile unsigned int unk00;
    volatile unsigned int unk04;
    volatile unsigned int unk08;
    volatile unsigned int unk0C;
    volatile unsigned int unk10;
    volatile unsigned int unk14;
};
struct FUN_00cbc6a0_Class
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void bhkLiquidAction_SaveBinary(unsigned char* arg);
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual FUN_00cbc6a0_Data* vf45(int* value);
    void __thiscall bhkUnaryAction_SaveBinary(unsigned char* arg);
};
extern __declspec(thread) int g_memoryContext;
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
void* __cdecl Object_DispatchCommandFour(unsigned int size);
struct FUN_00cbca20_class
{
    void __thiscall bhkUnaryAction_CopyMembers(bhkLiquidAction* obj, int flags);
    bhkLiquidAction* __thiscall bhkLiquidAction_CreateClone(int flags);
};
extern "C" HavokAllocatorContext_explosion* __cdecl hkMemoryRouter_getInstance();
struct HavokObj;
struct DynCastHelper2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* unk18;
};
struct DynCastHelper1
{
    int unk00;
    int unk04;
    DynCastHelper2* unk08;
};
struct DynCastObj
{
    DynCastHelper1* __thiscall DynamicCast(const void* rtti);
};
struct GarbageCollectorObjectPtr
{
    DynCastObj* m_ptr;
    int m_unk04;
};
extern const void* DAT_01267b70;
extern const void* g_012043f8;
GarbageCollectorObjectPtr* __cdecl bhkWorldObject_GetProperty(GarbageCollectorObjectPtr* out, void* obj, const void* rtti);
struct ArgStruct
{
    int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
};
struct TargetClass
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf8c(HavokObj* obj);
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vfbc(ArgStruct* arg);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;

    void bhkLiquidAction_SetTargetObject(void* p);
    void bhkLiquidAction_Init(ArgStruct* arg);
};
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    return SetAtGrow(m_usSize, element);
}

typedef NiTArray<char*, NiTMallocInterface<char*> > NiViewerStringArray;
class FUN_00cbd650_base
{
  public:
    void bhkUnaryAction_GetViewerStrings(NiViewerStringArray* pkStrings);
};
class FUN_00cbd650_cls : public FUN_00cbd650_base
{
  public:
    void bhkLiquidAction_GetViewerStrings(NiViewerStringArray* pkStrings);
};
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
extern const char* DAT_01268420;
inline void* operator new(size_t, void* p)
{
    return p;
}
struct SmallAlignedState
{
    unsigned int unk00;
    void* unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    SmallAlignedState() : unk00(0), unk04(0), unk08(5000.0f), unk0c(15.0f), unk10(64.0f), unk14(15.0f)
    {}
};
struct StateAllocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int bytes);
};
extern StateAllocator DAT_011f6238;
struct StateOwner
{
    unsigned int unk00;
    unsigned int unk04;
    void* unk08;
    SmallAlignedState* unk0c;
    unsigned int unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    void __thiscall bhkUnaryAction_CopyCinfo(SmallAlignedState* state);
    SmallAlignedState* bhkLiquidAction_CreateCinfo(bool* created);
};

#include <xmmintrin.h>
#include "../../../../include/AutoMemContext.h"
#include "../../../../include/NiPoint3.h"
struct Upd;
struct Obj;
struct Sub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Obj* V0c();
    virtual void* V10();
};
struct Chain
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void* V0c();
};
struct Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual Chain* V0c();
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
    virtual void v50();
    virtual void v51();
    virtual void Vd0(Obj* a, int b, int c, int d, int e);
    virtual void v53();
    virtual void Vd8(Obj* a, int b);
    virtual void Vdc(void* a, int b);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
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
    virtual void* V130();
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
    virtual void V1c8();
    virtual void v115();
    virtual Obj* V1d0();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* V1f4();
    void __thiscall NiAVObject_SetScale(float a);
    void __thiscall NiAVObject_SetTranslate(NiPoint3* a);
    void __thiscall SetRotate_0043fa80(void* a);
    void* __thiscall FUN_00a5bdd0(void* a);
    void* __thiscall NiObjectNET_GetControllers();
    bool __thiscall bhkWorld_QDebugDisplay();
    void __thiscall Update(Upd* a);
};
struct SoundFile
{
    char* __thiscall Get();
};
struct Proj
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
    SoundFile name;
    int __thiscall GetFormEditorIDLength();
    void* __thiscall GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};
struct Cell
{
    Obj* __thiscall TESObjectCELL_GetbhkWorld();
};
struct SettingColl
{
    int* __thiscall Int();
};
extern SettingColl g_011d0fe4;
extern char DAT_0108f1a8;
extern char DAT_0108f16c;
struct FixedStr
{
};
FixedStr* __cdecl FixedStrings_QSpecialIdle_AreaEffect();
struct Eyes
{
    float __thiscall Len();
};
struct Handler
{
    Eyes* __thiscall Get();
};
struct TObj
{
    Eyes* __thiscall GetTranslate_0043c490();
};
Obj* __cdecl BSUtilities_GetObjectByName(Obj* a, void* b);
void __cdecl Warning_005b5e40(const char* fmt, ...);
void* __cdecl _ref_0084e3a0(Proj* a);
struct Local70
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    void __thiscall Ctor6815c0();
    void __thiscall FUN_00a59780(float a, float b, float c);
};
struct Extra
{
    void __thiscall BSXFlags_SetFlags(int a, int b);
};
const FixedStr& __cdecl BSXFlags_Tag();
struct FloatConfiguredObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    FloatConfiguredObject(float);
    ~FloatConfiguredObject();
};
void* __cdecl Object_DispatchCommandFour(unsigned int n);
struct BigObj
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
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
    BigObj(int);
    void* __thiscall FUN_00a5ecb0(int a);
    void __thiscall NiAVObject_SetTranslate_004bc1f0(float a, float b, float c);
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Vdc(void* a, int b);
};
void* __cdecl FUN_00476c00();
struct Rnd
{
    float __thiscall F();
    float __thiscall F(float a);
};
struct PathReq
{
    void __thiscall SetGridPosition(float a);
};
struct InitObj
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    InitObj(void*);
    void* __thiscall Init(void* a);
    void __thiscall bhkNiCollisionObject_SetWorldObject(void* a);
};
struct Sphere
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sphere(float, bool);
    void* __thiscall Ctor(float a, int b);
};
struct __declspec(align(16)) Big
{
    __m128 unk00;
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
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Big();
    void __thiscall PathingRequestClosePoint_SetMinDistance(float a);
    void __thiscall PathingRequestLOS_SetIgnoreLocationRadius(float a);
    void __thiscall bhkRigidBodyCinfo_SetMotionType(int a);
    void __thiscall PathingRequestCoveredMove_SetAttackerHealth(float a);
    void __thiscall bhkRigidBodyCinfo_SetCollisionFilter(void* a);
    void __thiscall bhkRigidBodyCinfo_SetShape(void* a);
    ~Big();
};
struct FilterValue
{
    void* __thiscall Modelloader_GetReferencedThis();
};
struct Temp622
{
    int unk00;
    FilterValue* __thiscall Ctor(int a, void* b, int c);
};
void* __cdecl bhkCollisionFilter_GetNewSystemGroup();
void* __cdecl Modelloader_GetReferencedThis(void* a);
struct Body
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Body(Big*);
    void* __thiscall FUN_0056d380(Big* a);
    void __thiscall bhkNiCollisionObject_SetWorldObject(void* a);
    void* __thiscall Bipedanim_GetReferenceFlagsOrZero();
    void __thiscall bhkRigidBody_AddActCon(void* a);
};
struct Acc
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
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
    Acc();
    void* __thiscall Ctor();
    void __thiscall BSMultiBoundNode_SetCullingMode(int a);
};
struct S1fc
{
    int unk00;
    void __thiscall Ctor();
    void* m04;
    float fa, fb, fc, fd;
};
extern float DAT_011a57fc;
extern float DAT_011a5800;
extern float DAT_011a5804;
extern float DAT_011a5808;
extern float DAT_011a580c;
extern float DAT_011a5810;
struct Upd
{
    float time;
    bool updateControllers;
    bool isMultithreaded;
    int flags;
    void __thiscall Ctor(float a, int b, int c);
};
struct NodeU
{
    void __thiscall Update(Upd* a);
};
void* __cdecl TESObjectCELL_GetbhkWorld(void* a);
void __cdecl bhkWorld_UpdatePosition(Obj* a, int b, int c);
bool __cdecl TESObjectREFR_HasAddonFlags(void* a);
void __cdecl TESObjectREFR_AddMasterParticleAddonNodes(void* a);
bool __cdecl bhkWorld_QDebugDisplay(void* a);
void __cdecl EnsureLightingProperty(Obj* a);
struct Ctrl
{
    int __thiscall NiNode_GetAtChecked(int a);
    void* __thiscall FUN_0043b4a0(int a);
    void* __thiscall GetNext();
    void* __thiscall NiControllerManager_GetSequenceByName(FixedStr* a);
    void __thiscall FUN_0048fef0(float a);
    void __thiscall FUN_0047aab0(void* a, int b, int c, float d, float e, int f);
    void __thiscall FUN_0047aa40(int a);
};
struct Seq
{
    float __thiscall GetEndKeyTime_00508100();
    void __thiscall Free();
};
extern void* g_011f36ac;
bool __cdecl NiObject_IsKindOf(void* rtti, void* a);
void __cdecl NiTimeController_StartAnimations(Obj* a);
extern float DAT_01016970;
// @fnv 0x009ad670
// src: COMMUNITY 0x009ad670
void Explosion::Init3D()
{
    GenerateNiNode(false);
    Obj* obj = (Obj*)GetNiNode();
    if (obj)
    {
        float scale = 1.0f;
        if (IsNotCulled())
        {
            Chain* node = obj->V0c();
            BSFadeNode* fade = node ? (BSFadeNode*)((Sub*)node)->V10() : 0;
            if (fade)
                fade->SetRange(DAT_01016970, DAT_01016970);
        }
        if (*g_011d0fe4.Int() == 0)
        {
            TObj* named = (TObj*)BSUtilities_GetObjectByName(obj, &DAT_0108f1a8);
            if (named)
            {
                scale = Explosion_GetRadius() / named->GetTranslate_0043c490()->Len();
            }
            else
            {
                const char* name;
                if (FUN_004181e0()->GetFormEditorIDLength())
                {
                    Obj* base = (Obj*)FUN_004181e0();
                    name = (const char*)base->V130();
                }
                else
                    name = FUN_004181e0()->name.Get();
                Warning_005b5e40(&DAT_0108f16c, FUN_004181e0()->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), name);
                scale = 1.0f;
            }
        }
        obj->NiAVObject_SetScale(scale);
        obj->NiAVObject_SetTranslate(static_cast<const Explosion*>(this)->GetPos());
        NiPoint3 angles = *FUN_00430830();
        Local70 rotation;
        rotation.Ctor6815c0();
        rotation.FUN_00a59780(angles.z, angles.y, angles.x);
        obj->SetRotate_0043fa80(&rotation);
        if (*g_011d0fe4.Int() > 1)
        {
            ((PathReq*)FUN_004181e0())->SetGridPosition(DAT_011a5810);
            f3DLifetime = DAT_011a580c;
            NiPoint3 position = *static_cast<const Explosion*>(this)->GetPos();
            void* extra = obj->FUN_00a5bdd0((void*)&BSXFlags_Tag());
            if (extra)
            {
                Extra* flags = (Extra*)extra;
                flags->BSXFlags_SetFlags(0x10, 1);
            }
            for (int i = 0; i < *g_011d0fe4.Int(); ++i)
            {
                FloatConfiguredObject guard(1.0f);
                BigObj* node = new BigObj(0);
                node->NiAVObject_SetTranslate_004bc1f0((float)(((Rnd*)FUN_00476c00())->F() * 10.0),
                                   (float)(((Rnd*)FUN_00476c00())->F() * 10.0),
                                   (float)(((Rnd*)FUN_00476c00())->F() * 10.0 + 32.0));
                InitObj* collision = new InitObj(node);
                Sphere* shape = new Sphere(8.0f, 1);
                Big info;
                info.PathingRequestClosePoint_SetMinDistance(5.0f);
                info.PathingRequestLOS_SetIgnoreLocationRadius(0.0f);
                info.bhkRigidBodyCinfo_SetMotionType(1);
                info.PathingRequestCoveredMove_SetAttackerHealth(1.0f);
                Temp622 filter;
                info.bhkRigidBodyCinfo_SetCollisionFilter(filter.Ctor(4, bhkCollisionFilter_GetNewSystemGroup(), 0)->Modelloader_GetReferencedThis());
                info.bhkRigidBodyCinfo_SetShape(shape);
                Body* body = new Body(&info);
                collision->bhkNiCollisionObject_SetWorldObject(body);
                obj->Vdc(node, 1);
                Acc* accumulator = new Acc;
                accumulator->BSMultiBoundNode_SetCullingMode(0xe);
                node->Vdc(accumulator, 1);
                S1fc actionInfo;
                actionInfo.Ctor();
                actionInfo.m04 = body->Bipedanim_GetReferenceFlagsOrZero();
                actionInfo.fa = DAT_011a5808;
                actionInfo.fb = DAT_011a5804;
                actionInfo.fc = DAT_011a5800;
                actionInfo.fd = DAT_011a57fc;
                bhkLiquidAction* action = new bhkLiquidAction(&actionInfo);
                body->bhkRigidBody_AddActCon(action);
            }
            if (FUN_008d6f30() && FUN_008d6f30()->TESObjectCELL_GetbhkWorld())
            {
                FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
                bhkWorld_UpdatePosition(obj, 1, 1);
                Upd update;
                update.Ctor(0.0f, 0, 0);
                obj->Update(&update);
                Obj* world = (Obj*)FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
                world->Vd0(obj, 1, 1, 0, 1);
            }
        }
        if (FUN_008d6f30() && FUN_008d6f30()->TESObjectCELL_GetbhkWorld())
        {
            FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
            bhkWorld_UpdatePosition(obj, 1, 1);
            Upd update;
            update.Ctor(0.0f, 0, 0);
            obj->Update(&update);
            Obj* world = (Obj*)FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
            world->Vd0(obj, 1, 1, 0, 1);
        }
        if (obj->V0c() && TESObjectREFR_HasAddonFlags(obj->V0c()))
            TESObjectREFR_AddMasterParticleAddonNodes(obj->V0c());
        if (FUN_008d6f30() && FUN_008d6f30()->TESObjectCELL_GetbhkWorld() && FUN_008d6f30()->TESObjectCELL_GetbhkWorld()->bhkWorld_QDebugDisplay())
        {
            Obj* world = (Obj*)FUN_008d6f30()->TESObjectCELL_GetbhkWorld();
            world->Vd8(obj, 1);
            EnsureLightingProperty(obj);
        }
        Ctrl* ctrl = (Ctrl*)obj->NiObjectNET_GetControllers();
        if (!ctrl)
        {
            Ctrl* node = (Ctrl*)obj->V0c();
            if (node && node->NiNode_GetAtChecked(0))
                ctrl = (Ctrl*)((Obj*)node->FUN_0043b4a0(0))->NiObjectNET_GetControllers();
        }
        Ctrl* manager = 0;
        while (ctrl)
        {
            if (NiObject_IsKindOf(&g_011f36ac, ctrl))
            {
                manager = ctrl;
                break;
            }
            ctrl = (Ctrl*)ctrl->GetNext();
        }
        Seq* sequence;
        if (manager && (sequence = (Seq*)manager->NiControllerManager_GetSequenceByName(FixedStrings_QSpecialIdle_AreaEffect())) != 0)
        {
            manager->FUN_0048fef0(0.0f);
            manager->FUN_0047aab0(sequence, 0, 0, 1.0f, 0.0f, 0);
            manager->FUN_0047aa40(1);
            sequence->Free();
            if (BGSProjectile_GetMuzzleFlashDuration() < sequence->GetEndKeyTime_00508100())
                bhkCharacterControllerCinfo_SetAcrobatics(sequence->GetEndKeyTime_00508100());
        }
        else
            NiTimeController_StartAnimations(obj);
    }
}
