#include "../../include/NiTArray.h"
#define FNV64_HKVECTOR4_LENGTHINVERSE4  // this unit defines hkVector4::lengthInverse4 (0x005612a0)

// src/fallout_shared/tesobjectrefr_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/fallout_shared/tesobjectrefr_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tesobjectrefr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectrefr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "tesobjectrefr_decls.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiMemObject.h"
#include "../../include/NiTransform.h"
#include "../../include/NiMatrix3.h"
// Constructor 0x0043d410 writes time and byte flags: this is NiUpdateData, not NiColor.
#include "../../include/NiUpdateData.h"
#include "../../include/TESForm.h"
#include "../../include/BGSPlaceableWater.h"
#include "../../include/hkQuaternion.h"
// Constructor 0x0056ded0 constructs a 0x40-byte transform, not the 0xB0-byte hkMotionState.
#include "../../include/hkTransform.h"
#include "../../include/hkSimdReal.h"
// Its 16-byte SIMD layout and dot4 call at 0x00561440 identify the former hkVector4X.
#include "../../include/NiObject.h"
#include "../../include/ProjectileListener.h"
#include "../../include/bhkAabbPhantom.h"
#include "../../include/bhkCharacterController.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiRTTI.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkVector4.h"
GarbageCollectorUpdateState* MemoryLevelManager_GetSingleton();
void* DecalData_GetDefaultDecalData();
void FalloutRadio_NewCellEntered();
void TESWaterSystem_SetPlayerForceUnderwater(unsigned char value);
float BSAudio_GetMinDialogDist();
float BSAudio_GetMaxDialogDist();
void CheckWithinMultiBoundTask_CancelAttachment(unsigned int index);
struct FUN_00c9c240_holder
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00c9c240();
    void bhkEntity_Deactivate();
};
extern int DAT_0126810c;
extern int DAT_01268208;
extern int DAT_0126822c;
extern int DAT_01268238;
extern const void* DAT_01030394;
extern const void* DAT_0103078c;
extern const void* DAT_010306b4;
struct FUN_00c6d190 : bhkRefObject
{
    FUN_00c6d190();
};
void bhkSerializable_Kill();
struct FUN_00c9d4c0_holder
{
    void* m0;
    void* m4;
    void* m8;
    void bhkEntity_Kill();
    void FUN_00c9c240();
    void bhkEntity_Deactivate();
};
struct CallRet
{
    void hkpWorld_updateCollisionFilterOnEntity(void* a, int b, int c);
};
struct Holder00c9d5d0
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual CallRet* GetRet();
    void* unk4;
    void* unk8;
    void bhkEntity_UpdateCFilter();
};
extern int DAT_01268238;
struct FUN_00c876a0_holder
{
    virtual ~FUN_00c876a0_holder();
    void bhkSerializable_Kill();
};
struct FUN_00c9f3b0 : FUN_00c876a0_holder
{
    virtual ~FUN_00c9f3b0();
};
struct WorldHolder
{
    void UpdatePhantom(void* a, int b);
};
extern float DAT_010c72bc;
struct InnerS
{
    char pad[16];
    float f10;
};
struct MyObj
{
    char pad[8];
    InnerS* p8;
    void __thiscall bhkShape_CopyCinfo(void* a);
};
struct OutS
{
    int i0;
    float f4;
};
void __fastcall bhkConvexShape_CopyCinfo(MyObj* _this, int, OutS* _out);
struct ArgB
{
    char _0[16];
    float f10;
};
struct RetV
{
    char _0[4];
    float f4;
};
struct S_00cb3070
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
    virtual void v43b();
    virtual void v44(int*);
    void bhkRigidBody_LoadBinary(int);
    void bhkRigidBodyT_LoadBinary(int);
};
struct MM
{
    void Deallocate(void* p);
    void FUN_00cb2ff0();
    void* FUN_00cb30a0(unsigned int);
};
extern MM _g_memoryManager;
extern int DAT_012681fc;
struct FUN_00c9d620_holder : FUN_00c876a0_holder
{
    void* m0;
    void* m4;
    void* m8;
    FUN_00c9d620_holder();
    ~FUN_00c9d620_holder();
};
extern int DAT_01268250;
struct FUN_0056e780_Class
{
    virtual ~FUN_0056e780_Class();
    void FUN_00ca0540();
};
struct FUN_00c9fb00 : FUN_0056e780_Class
{
    virtual ~FUN_00c9fb00();
};
extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_0126825c;
extern int DAT_01268274;
extern void* DAT_0103093c;
extern void* DAT_01030a24;
extern void* DAT_01030b0c;
extern void* DAT_01030bf4;
struct FUN_00c9fde0 : bhkRefObject
{
    FUN_00c9fde0();
};
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};
extern int DAT_01030864;
extern int DAT_01268244;
struct S_00cb79d0_Base
{
    void* vtbl;
    char pad[8];
    int f0c;
    int f10;
    unsigned char f14;

    S_00cb79d0_Base();
};
struct Object_00c9f5a0 : S_00cb79d0_Base, A51BF0Base
{
    Object_00c9f5a0() : S_00cb79d0_Base()
    {
        vtbl = (void*)&DAT_01030394;
        f0c = 0;
        f10 = 0;
        ++DAT_0126810c;
        vtbl = (void*)&DAT_0103078c;
        ++DAT_01268238;
        vtbl = (void*)&DAT_01030864;
        ++DAT_01268244;
        f14 = 0;
    }
};
void* bhkAabbPhantom_CreateObject();
struct FUN_00c877b0
{
    virtual ~FUN_00c877b0();
};
struct FUN_00c84c50 : FUN_00c877b0
{
    virtual ~FUN_00c84c50();
};
void bhkSerializable_Kill();
extern int DAT_012680f8;
extern int DAT_0126810c;
extern __declspec(thread) unsigned int g_havokThreadMode;
struct CollisionObject;
struct CollisionResult
{
    unsigned short kind;
    unsigned short enabled;
    struct CollisionRecord* record;
    unsigned int data08;
    unsigned int data0c;
    unsigned int state;
};
struct CollisionValue
{
    unsigned int data00;
    unsigned int data04;
    CollisionRecord* record;
};
struct CollisionRecord
{
    unsigned int data00;
    unsigned int data04;
    struct CollisionHandler* handler;
};
struct CollisionHandler
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
    virtual CollisionValue* Find(int target);
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
    virtual bool IsAllowed(int target);
};
struct ScopedMode
{
    unsigned int oldValue;
    ScopedMode() : oldValue(g_havokThreadMode)
    {
        g_havokThreadMode = 0x10;
    }
    ~ScopedMode()
    {
        g_havokThreadMode = oldValue;
    }
};
struct WorldObjectView
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
    virtual CollisionResult* GetResult(unsigned char* used);
    void bhkSerializable_CopyMembers(int a, int b);
    void bhkWorldObject_CopyMembers(int a, int b);
};
#include "../../include/NiTMallocInterface.h"
#include "../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl bodies this unit's original inlines (the shared NiTArray declares them):
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::SetAtGrow(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usMaxSize)
        SetSize(uiIndex + m_usGrowBy);
    SetAt(uiIndex, element);
    return uiIndex;
}
template <class T, class TAlloc> __forceinline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    T value = element;
    return SetAtGrow(m_usSize, value);
}
typedef NiTPrimitiveArray<char*> DebugStrArray;
struct hkShapeStub
{
    void* vtbl;
    int unk04;
    NiObject* userData;
};
struct hkCdBodyStub
{
    hkShapeStub* m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct hkObjHead
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
};
struct hkWorldObjStub : hkObjHead, hkCdBodyStub
{
};
struct DebugHelper_c849b0
{
    int value;
    DebugHelper_c849b0(int v) : value(v)
    {}
    void Fill(DebugStrArray* arr);
};
extern __declspec(thread) int tlsHeapContext;
struct HeapContextGuard
{
    int saved;
    HeapContextGuard(int ctx)
    {
        saved = tlsHeapContext;
        tlsHeapContext = ctx;
    }
    ~HeapContextGuard()
    {
        tlsHeapContext = saved;
    }
};
char* MakeDebugHeader(const char* name);
char* MakeDebugLine(const char* label, const char* value);
int SprintfS(char* buf, int size, const char* fmt, ...);
extern const char* g_debugHeaderName;
struct bhkBase_c878c0
{
    void* vtbl;
    int unk04;
    hkWorldObjStub* m_pObject;
    hkCdBodyStub* GetBody()
    {
        return m_pObject;
    }
    void BaseDebugInfo(DebugStrArray* arr);
};
extern int DAT_012681b0;
class FUN_00c8bed0_base_cls
{
  public:
    virtual void unk00();
    ~FUN_00c8bed0_base_cls();
    int unk04;
};
class FUN_00c8bed0_cls : public FUN_00c8bed0_base_cls
{
  public:
    virtual ~FUN_00c8bed0_cls();
    void unk08();
};
struct FUN_00c9eb30 : FUN_00c9f3b0
{
    virtual ~FUN_00c9eb30();
};
struct TlsBlock_t
{
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
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int m_2b4;
};
extern __declspec(thread) TlsBlock_t g_tlsBlock;
void* __cdecl Object_DispatchCommandFour(unsigned int size);
void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock();
struct TlsGuard_t
{
    int m_saved;

    TlsGuard_t()
    {
        m_saved = g_tlsBlock.m_2b4;
        g_tlsBlock.m_2b4 = 0x10;
    }

    ~TlsGuard_t()
    {
        g_tlsBlock.m_2b4 = m_saved;
    }
};
inline void* operator new(unsigned int n)
{
    return Object_DispatchCommandFour(n);
}
struct FUN_00c9efa0_cls
{
    void bhkWorldObject_CopyMembers(FUN_00c6d190* p, unsigned int flag);
    bhkRefObject* bhkSimpleShapePhantom_CreateClone(unsigned int flag);
};
struct S_00c9f1e0_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int type;
};
struct S_00c9f1e0_Elem
{
    S_00c9f1e0_Shape* shape;
};
struct S_00c9f1e0_Base1
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c9f1e0_Base2
{
    S_00c9f1e0_Shape* shape;
};
struct S_00c9f1e0_Range
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int begin;
    int end;
};
struct S_00c9f1e0_World;
typedef void(__cdecl* S_00c9f1e0_Fn)(S_00c9f1e0_Base2*, S_00c9f1e0_Elem*, S_00c9f1e0_World*, S_00c9f1e0_Range*);
struct S_00c9f1e0_Entry
{
    S_00c9f1e0_Fn fn;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_00c9f1e0_Disp
{
    unsigned char types[77][32];
    int unk9a0;
    int unk9a4;
    S_00c9f1e0_Entry funcs[32];
};
struct S_00c9f1e0_World
{
    S_00c9f1e0_Disp* disp;
};
struct S_00c9f1e0_Holder
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
    S_00c9f1e0_World* world;
};
struct S_00c9f1e0_Ctx : S_00c9f1e0_Base1, S_00c9f1e0_Base2
{
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
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_00c9f1e0_Elem** items;
    int count;
};
struct S_00c9f1e0_Obj
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
    virtual S_00c9f1e0_Holder* GetWorld();
    int unk04;
    S_00c9f1e0_Ctx* ctx;
    void bhkSimpleShapePhantom_GetFixedClosestPoints(S_00c9f1e0_Range* r);
};
extern __declspec(thread) int g_iC9F270MemContext;
class C9F270MemContext
{
  public:
    C9F270MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iC9F270MemContext;
        g_iC9F270MemContext = aiMemoryContext;
    }
    ~C9F270MemContext()
    {
        g_iC9F270MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
extern const char* g_pcC9F270ClassName;
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcName);
class C9F270StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
class C9F270Object
{
  public:
    void GetViewerStringsBase(C9F270StrArray* pkStrings);
    void bhkSimpleShapePhantom_GetViewerStrings(C9F270StrArray* pkStrings);
};
__declspec(thread) int tlsMode = 0x3b;
struct ReleaseObject
{
    void DestroyObject(int value);
};
struct FUN_00c9f320_object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void bhkAabbPhantom_KillCinfo(char release);
};
struct TlsGuard
{
    int previous;
    TlsGuard()
    {
        previous = tlsMode;
        tlsMode = 0x10;
    }
    ~TlsGuard()
    {
        tlsMode = previous;
    }
};
struct PhysicsAction
{
    bool __thiscall bhkWorld_Remove_00c68cb0(void* owner);
};
struct LinkedObject
{
    PhysicsAction* GetAction() const
    {
        return *reinterpret_cast<PhysicsAction* const*>(reinterpret_cast<const char*>(this) + 0x350);
    }
};
struct FUN_00c9f420_Class
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
    virtual LinkedObject* ResolveLinkedObject();
    int unk4;
    void* handle;
    bool bhkPhantom_Remove();
};
void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
struct ProjectileCreator
{
    void __thiscall bhkWorldObject_CopyMembers(Object_00c9f5a0* projectile, int mode);
    Object_00c9f5a0* __thiscall bhkAabbPhantom_CreateClone(int mode);
};
struct TLSBlock
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
    int value;
};
__declspec(thread) TLSBlock g_tls;
struct ThreadFlagGuard
{
    int previous;
    ThreadFlagGuard()
    {
        previous = g_tls.value;
        g_tls.value = 16;
    }
    ~ThreadFlagGuard()
    {
        g_tls.value = previous;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* Allocate(unsigned int);
};
struct Pool
{
    int unk0, unk4, unk8, unkc;
    Allocator* allocator;
};
extern "C" Pool* __cdecl hkMemoryRouter_getInstance();
struct FUN_00cf2cb0
{
    int unk0;
    unsigned short length;
    static void* operator new(unsigned int count)
    {
        Pool* pool = hkMemoryRouter_getInstance();
        FUN_00cf2cb0* p = (FUN_00cf2cb0*)pool->allocator->Allocate(224);
        p->length = 224;
        return p;
    }
    static void operator delete(void*, unsigned int);
    FUN_00cf2cb0(void* contents, int tag);
};
extern "C" void __fastcall FUN_00c905b0(FUN_00cf2cb0*);
struct Input
{
    int tag;
    int unk4, unk8, unkc, unk10, unk14, unk18, unk1c;
    int payload;
};
struct Receiver
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
    virtual void dispatch(void*);
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
    virtual void finish(void*);
    void bhkAabbPhantom_Init(Input* input);
};
extern __declspec(thread) int g_iC9F970AllocTag;
struct BC9F970AllocTagScope
{
    int m_iSaved;

    BC9F970AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC9F970AllocTag;
        g_iC9F970AllocTag = aiAllocationTag;
    }
    ~BC9F970AllocTagScope()
    {
        g_iC9F970AllocTag = m_iSaved;
    }
};

typedef NiTArray<char*, NiTMallocInterface<char*> > BC9F970StringArray;
extern const char* g_pcC9F970Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class FUN_00c9f970_cls
{
  public:
    void bhkPhantom_GetViewerStrings(BC9F970StringArray* pkArray);
    void bhkAabbPhantom_GetViewerStrings(BC9F970StringArray* pkArray);
};
struct MemContextTLS
{
    int unk2b4;
};
extern __declspec(thread) MemContextTLS g_memContextTLS;
struct MemContextGuard
{
    int iOld;
    MemContextGuard()
    {
        iOld = g_memContextTLS.unk2b4;
        g_memContextTLS.unk2b4 = 0x10;
    }
    ~MemContextGuard()
    {
        g_memContextTLS.unk2b4 = iOld;
    }
};
struct ViewerStringArray
{
    char** m_pBase;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
};
struct ViewerRTTI
{
    const char* m_pcName;
};
extern ViewerRTTI g_01268254;
char* CreateDebugString(const char* pcText);
char* CreateDebugString(const char* pcPrefix, float fValue);
extern float DAT_010c72bc;
extern float DAT_011b15c0;
struct SphereHkShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float fRadius;
};
struct SphereShapeBase
{
    void* vtbl;
    int unk04;
    void BaseGetViewerStrings(ViewerStringArray* apViewerStrings);
};
struct SphereShape : SphereShapeBase
{
    SphereHkShape* pHkShape;
    float GetRadius()
    {
        return (this && pHkShape) ? pHkShape->fRadius : DAT_010c72bc;
    }
    void bhkConvexShape_GetViewerStrings(ViewerStringArray* apViewerStrings);
};
extern int DAT_0126825c;
class FUN_00c9fd70_cls : public FUN_00c9fb00
{
  public:
    virtual ~FUN_00c9fd70_cls();
    void bhkSerializable_Kill();
};
struct SphereScaleFields
{
    unsigned int m_00, m_04, m_08, m_0c;
    float m_10, m_14, m_18, m_1c;
};
struct Tls_ca0090
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};
extern __declspec(thread) Tls_ca0090 g_tls_ca0090;
extern float DAT_010c72bc;
extern char DAT_011f6238;
extern char DAT_01267e30;
extern int DAT_0126fd98;
struct TlsGuard_ca0090
{
    unsigned int m_saved;
    TlsGuard_ca0090()
    {
        m_saved = g_tls_ca0090.m_2b4;
        g_tls_ca0090.m_2b4 = 0x10;
    }
    ~TlsGuard_ca0090()
    {
        g_tls_ca0090.m_2b4 = m_saved;
    }
};
struct MemMgr_ca0090
{
    void* Game_DoHeapAlloc(unsigned int size);
};
struct Sub_ca0090
{
    void SetQuaternionComponentsFromVector(void* a);
};
struct FUN_00ca0090_cls
{
    unsigned int unk00;
    unsigned int unk04;
    void* m08;
    void* m0C;
    void bhkConvexShape_CopyCinfo(void* a);
    void* bhkBoxShape_CreateCinfo(unsigned char* out);
};
class CA0540Base
{
  public:
    virtual ~CA0540Base();

    void Shutdown();
};
class FUN_00ca0540 : public CA0540Base
{
  public:
    virtual ~FUN_00ca0540();

    static unsigned int ms_uiInstances;
};
extern __declspec(thread) int g_iCA05B0AllocTag;
struct BCA05B0AllocTagScope
{
    int m_iSaved;

    BCA05B0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCA05B0AllocTag;
        g_iCA05B0AllocTag = aiAllocationTag;
    }
    ~BCA05B0AllocTagScope()
    {
        g_iCA05B0AllocTag = m_iSaved;
    }
};
typedef NiTArray<char*, NiTMallocInterface<char*> > BCA05B0StringArray;
extern const char* g_pcCA05B0Name;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);
class FUN_00ca05b0_cls
{
  public:
    void bhkShape_GetViewerStrings(BCA05B0StringArray* pkArray);
    void bhkSphereRepShape_GetViewerStrings(BCA05B0StringArray* pkArray);
};
extern int DAT_01268280;
class FUN_00ca0660_base
{
  public:
    virtual void unk00();
    ~FUN_00ca0660_base();
    int unk04;
};
class FUN_00ca0660 : public FUN_00ca0660_base
{
  public:
    virtual ~FUN_00ca0660();
    void unk08();
};
class CA0840Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern __declspec(thread) int g_iCA0840MemContext;
extern float DAT_010c72bc;
extern CA0840Heap g_memoryManager;
class CA0840MemContext
{
  public:
    CA0840MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCA0840MemContext;
        g_iCA0840MemContext = aiMemoryContext;
    }
    ~CA0840MemContext()
    {
        g_iCA0840MemContext = m_iPrevious;
    }

    int m_iPrevious;
};
class CA0840Output
{
  public:
    CA0840Output() : m_pkTarget(0), m_fValue(DAT_010c72bc)
    {}

    static void* operator new(unsigned int uiSize)
    {
        return g_memoryManager.Allocate(uiSize);
    }
    static void operator delete(void* pvMem, unsigned int);

    void* m_pkTarget;
    float m_fValue;
};
class CA0840Constraint
{
  public:
    int unk00;
    int unk04;
    void* m_pkWorld;
    CA0840Output* m_pkOutput;

    void SetOutput(CA0840Output* pkOutput);
    CA0840Output* bhkSphereShape_CreateCinfo(bool* pbCreated);
};
class CAACF0Base
{
  public:
    virtual ~CAACF0Base();

    void Shutdown();
};
class FUN_00caacf0 : public CAACF0Base
{
  public:
    virtual ~FUN_00caacf0();

    static unsigned int ms_uiInstances;
};
extern int DAT_012683c8;
void* bhkRigidBodyT_GetRTTI();
class CC2350Base
{
  public:
    virtual ~CC2350Base();
};
extern int g_iCC2350Count;
class FUN_00cc2350 : public CC2350Base
{
  public:
    void Release();

    virtual ~FUN_00cc2350();
};
extern int DAT_01268660;
struct FUN_00cca8d0 : FUN_00c9fb00
{
    virtual ~FUN_00cca8d0();
    void bhkSerializable_Kill();
};
extern int DAT_0126868c;
struct FUN_00ccd080 : FUN_00c9fb00
{
    int unk04;
    virtual ~FUN_00ccd080();
};
extern int DAT_0126869c;
struct FUN_00ccdbc0 : FUN_00c9fb00
{
    void bhkSerializable_Kill();
    virtual ~FUN_00ccdbc0();
};
class CCE900Base
{
  public:
    virtual ~CCE900Base();
};
extern int g_iCCE900Count;
class FUN_00cce900 : public CCE900Base
{
  public:
    void Release();

    virtual ~FUN_00cce900();
};
struct FUN_00ccf4f0_cls : FUN_00c9fb00
{
    int unk04;
    virtual ~FUN_00ccf4f0_cls();
};
extern int DAT_012686c0;
class FUN_00ccf740_cls : public FUN_00c9fb00
{
  public:
    virtual ~FUN_00ccf740_cls();
    void bhkSerializable_Kill();
};
class NiControllerC9E : public NiObject
{
  public:
    NiControllerC9E();

    static NiObject* bhkSimpleShapePhantom_CreateObject();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
extern const char* DAT_0126823c;

#include <xmmintrin.h>
class S00560c20_Value
{
  public:
    S00560c20_Value();  // FUN_006240d0
    __m128 m_vComponents;
};

class S00560c20_Target;
void __cdecl CopyModifierSettings(S00560c20_Target* pTarget, const S00560c20_Value* pValue);

class S00560c20_Object
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual const S00560c20_Value* vfD8(S00560c20_Value* pOut);
    void bhkRigidBody_GetRotation(S00560c20_Target* pTarget);
};

// @fnv 0x00560c20
// src: XBOX_PDB 0x00560c20
void S00560c20_Object::bhkRigidBody_GetRotation(S00560c20_Target* pTarget)
{
    S00560c20_Value kValue;
    CopyModifierSettings(pTarget, vfD8(&kValue));
}

class S00561150_Value
{
  public:
    S00561150_Value();  // FUN_006240d0
    void normalize_005611c0();
    __m128 m_vComponents;
};

class S00561150_Source;
void __cdecl NI2HK_00561500(S00561150_Value* pOut, const S00561150_Source* pSource);

class S00561150_Object
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0(const S00561150_Value* pValue);
    void bhkRigidBody_SetNiRotation(const S00561150_Source* pSource);
};

// @fnv 0x00561150
// src: COMMUNITY 0x00561150
void S00561150_Object::bhkRigidBody_SetNiRotation(const S00561150_Source* pSource)
{
    S00561150_Value kValue;
    NI2HK_00561500(&kValue, pSource);
    kValue.normalize_005611c0();
    vfE0(&kValue);
}

struct S005611e0_Vector
{
    __m128 m_vComponents;
    S005611e0_Vector* FUN_005612a0(S005611e0_Vector* pOut) const;  // inverse length, as a vector
    S005611e0_Vector* hkSimdReal_broadcast(S005611e0_Vector* pOut) const;  // broadcast x
    void hkVector4_normalize4();                                           // normalize3
};

// @fnv 0x005611e0
// src: COMMUNITY 0x005611e0
void S005611e0_Vector::hkVector4_normalize4()
{
    S005611e0_Vector kScale;
    S005611e0_Vector kInvLength;
    FUN_005612a0(&kInvLength)->hkSimdReal_broadcast(&kScale);
    m_vComponents = _mm_mul_ps(kScale.m_vComponents, m_vComponents);
}

struct S00561240_Vector
{
    __m128 m_vComponents;
    S00561240_Vector* hkSimdReal_broadcast(S00561240_Vector* pOut) const;  // broadcast x
};

// @fnv 0x00561240
// src: COMMUNITY 0x00561240
S00561240_Vector* S00561240_Vector::hkSimdReal_broadcast(S00561240_Vector* pOut) const
{
    pOut->m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
    return pOut;
}

typedef __m128 hkQuadReal;


// @fnv 0x005612a0
hkSimdReal hkVector4::lengthInverse4() const
{
    const hkQuadReal half = _mm_set_ss(0.5f);
    const hkQuadReal three = _mm_set_ss(3.0f);
    const hkQuadReal zero = _mm_set_ss(0.0f);
    const hkQuadReal len2 = dot4(*this).getQuad();
    const hkQuadReal equalsZero = _mm_cmpeq_ss(len2, zero);
    const hkQuadReal e = _mm_rsqrt_ss(len2);
    const hkQuadReal r = _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    return hkSimdReal(_mm_andnot_ps(equalsZero, r));
}

// @fnv 0x00561440
hkSimdReal hkVector4::dot4(const hkVector4& v) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
    __m128 sum = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
    __m128 swapped = _mm_shuffle_ps(sum, sum, 0xb1);
    return hkSimdReal(_mm_add_ps(sum, swapped));
}

struct AlignedLocal5615
{
    __m128 m_v;
    AlignedLocal5615();
};
void* NI2HK(AlignedLocal5615* local, int value);
struct Owner5615
{
    void bhkRigidBody_SetLinearVelocity_00561690(void* p);
    void bhkRigidBody_SetLinearVelocity(int value);
};
// @fnv 0x005615d0
// src: XBOX_PDB 0x005615d0
void Owner5615::bhkRigidBody_SetLinearVelocity(int value)
{
    AlignedLocal5615 local;
    bhkRigidBody_SetLinearVelocity_00561690(NI2HK(&local, value));
}


struct __declspec(align(16)) HKVector4
{
    __m128 m_vComponents;
    HKVector4();
};

void* __cdecl FUN_00553fc0(void* pFrom, const NiPoint3& vec);


// @fnv 0x00561630
// src: XBOX_PDB 0x00561630
void bhkCharacterController::bhkRigidBody_SetAngularVelocity(const NiPoint3& param_1)
{
    HKVector4 local;
    bhkRigidBody_SetAngularVelocity_005617c0(FUN_00553fc0(&local, param_1));
}

class S00561730_Comparison
{
  public:
    bool hkVector4Comparison_allAreSet(int mask) const;  // allAreSet
    __m128 m_uiMask;
};

class S00561730_Vector
{
  public:
    S00561730_Vector();                                                       // FUN_006815c0
    void hkVector4_setSub4(const S00561730_Vector* a, const S00561730_Vector* b);  // setSub4
    void hkVector4_setAbs4(const S00561730_Vector* v);                             // setAbs4
    void hkVector4_setAll(float f);
    S00561730_Comparison hkVector4_compareLessThanEqual4(const S00561730_Vector* v) const;  // compareLessThan4
    bool hkVector4_equals4(const S00561730_Vector* v, float epsilon) const;   // equals4
    __m128 m_vComponents;
};

// @fnv 0x00561730
// src: XBOX_PDB 0x00561730
bool S00561730_Vector::hkVector4_equals4(const S00561730_Vector* v, float epsilon) const
{
    S00561730_Vector kDiff;
    kDiff.hkVector4_setSub4(this, v);
    kDiff.hkVector4_setAbs4(&kDiff);
    S00561730_Vector kEpsilon;
    kEpsilon.hkVector4_setAll(epsilon);
    return kDiff.hkVector4_compareLessThanEqual4(&kEpsilon).hkVector4Comparison_allAreSet(0xf);
}

class S005620e0_Vector
{
  public:
    S005620e0_Vector();  // FUN_006815c0
    __m128 m_vComponents;
};

class S005620e0_Source;
const S005620e0_Vector* __cdecl NI2HK(S005620e0_Vector* pOut, const S005620e0_Source* pSource);

// The shared controller has no declaration for this vector setter yet.
class ControllerVectorSetter
{
  public:
    void bhkCharacterController_SetPosition(const S005620e0_Vector* pValue);
};

// @fnv 0x005620e0
// src: XBOX_PDB 0x005620e0
void bhkCharacterController::SetPosition_005620e0(void* pSource)
{
    S005620e0_Vector kValue;
    reinterpret_cast<ControllerVectorSetter*>(this)->bhkCharacterController_SetPosition(
        NI2HK(&kValue, static_cast<const S005620e0_Source*>(pSource)));
}

class S0056e810_Vector
{
  public:
    __m128 m_vComponents;
};

class S0056e810_Quaternion
{
  public:
    S0056e810_Quaternion& SetQuaternionComponentsFromVector(const S0056e810_Vector& v);  // set from vector
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};

class __declspec(align(16)) S0056e810_Rotation
{
  public:
    S0056e810_Rotation();  // FUN_0056e860
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S0056e810_Quaternion m_kQuat;
};

class S0056e810_Object
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0(const S0056e810_Rotation* pRotation);
    void bhkBoxShape_Init(const S0056e810_Vector& v);
};

// @fnv 0x0056e810
// src: XBOX_PDB 0x0056e810
void S0056e810_Object::bhkBoxShape_Init(const S0056e810_Vector& v)
{
    S0056e810_Rotation kRotationBasis;
    kRotationBasis.m_kQuat.SetQuaternionComponentsFromVector(v);
    vfB0(&kRotationBasis);
}








void __cdecl NI2HK(hkVector4& kOut, const NiPoint3& kIn);
void __cdecl NI2HK_00561500(hkQuaternion& kOut, const hkVector4& kIn);

class SceneNodeF14
{
  public:
    void SetScale(float fScale);
    void SetColor(const NiUpdateData& kColor);
    void GetRotation(hkVector4& kRot);
    void AttachController(void* pvCtlr);
};

class OwnerF14
{
  public:
    NiPoint3 GetNavMeshData();
};

class OwnerRootF14
{
  public:
    OwnerF14* GetOwner();
};

class SystemF14
{
  public:
    void AddObject(void* pvObject);
};

class SystemSrcF14
{
  public:
    SystemF14* GetSystem();
};

extern float g_fRadiusF14;

class ShapeF14
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pv);
    ShapeF14(const hkVector4& m_kPoint2, float fRadius);
    char m_acData[0x30];
};

class MaterialF14
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pv);
    MaterialF14();
    char m_acData[0x10];
};

class WrapperF14
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pv);
    WrapperF14(ShapeF14* pkShape, MaterialF14* pkMaterial);
    char m_acData[0x1c];
};

class BodyInfoF14
{
  public:
    BodyInfoF14();
    ~BodyInfoF14();
    void SetMotionType(int iType);
    void SetPosition(const hkVector4& kPos);
    void SetRotation(const hkQuaternion& kRot);
    unsigned int m_uiFilterInfo;
    WrapperF14* m_pkShape;
    __m128 m_akData[13];
};


class BodyF14 : public NiMemObject
{
  public:
    BodyF14(const BodyInfoF14& kInfo);
    void Attach(SceneNodeF14* pkNode, int iFlags);
    char m_acData[0x1c];
};

class BodyWrapF14 : public NiMemObject
{
  public:
    BodyWrapF14(SceneNodeF14* pkNode);
    void SetBody(BodyF14* pkBody);
    char m_acData[0x14];
};

class CtlrF14 : public NiMemObject
{
  public:
    CtlrF14();
    void SetMode(int iMode, int iValue);
    char m_acData[0x10];
};

class P107RefF14
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual SceneNodeF14* Get3D();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7a();
    virtual void v7b();
    virtual void v7c();
    virtual const NiPoint3* GetPos();
    OwnerRootF14* GetOwnerRoot();
    SystemSrcF14* GetSystemSrc();
    void SetScaleF14(float fScale);
    NiMatrix3 GetRotationMatrix();
    void TESObjectREFR_InitHavokForAcousticSpace();
};

// @fnv 0x0056f140
// src: XBOX_PDB 0x0056f140
void P107RefF14::TESObjectREFR_InitHavokForAcousticSpace()
{
    OwnerF14* pkOwner = GetOwnerRoot()->GetOwner();
    SystemF14* pkSystem = GetSystemSrc() ? GetSystemSrc()->GetSystem() : 0;
    if (pkSystem)
    {
        ShapeF14* pkShape = 0;
        hkTransform kMotion;
        hkVector4 m_kPoint2;
        SetScaleF14(1.0f);
        Get3D()->SetScale(1.0f);
        NiUpdateData kColor(0.0f, false, false);
        Get3D()->SetColor(kColor);
        NiTransform kXform;
        kXform.m_Rotate = GetRotationMatrix();
        kXform.m_Translate = *GetPos();
        kXform.m_fScale = 1.0f;
        const int iLayer = 0x15;
        NI2HK(m_kPoint2, pkOwner->GetNavMeshData());
        pkShape = new ShapeF14(m_kPoint2, g_fRadiusF14);
        MaterialF14* pkMaterial = new MaterialF14();
        WrapperF14* pkWrapper = new WrapperF14(pkShape, pkMaterial);
        BodyInfoF14 kInfo;
        kInfo.m_pkShape = pkWrapper;
        kInfo.SetMotionType(5);
        hkVector4 kPos;
        hkVector4 kRot;
        __declspec(align(16)) hkQuaternion kQuat;
        Get3D()->GetRotation(kRot);
        NI2HK(kPos, *GetPos());
        NI2HK_00561500(kQuat, kRot);
        kInfo.SetPosition(kPos);
        kInfo.SetRotation(kQuat);
        unsigned int uiFilterInfo = 0x50000;
        uiFilterInfo |= iLayer;
        kInfo.m_uiFilterInfo = uiFilterInfo;
        BodyF14* pkBody = new BodyF14(kInfo);
        BodyWrapF14* pkWrap = new BodyWrapF14(Get3D());
        CtlrF14* pkCtlr = new CtlrF14();
        pkCtlr->SetMode(2, 1);
        Get3D()->AttachController(pkCtlr);
        pkWrap->SetBody(pkBody);
        pkBody->Attach(Get3D(), 0);
        pkSystem->AddObject(pkBody);
    }
}

extern const NiPoint3 g_kUpVectorQ;


extern TESForm* g_pkArrowFormQ;
extern TESForm* g_pkGrenadeFormAQ;
extern TESForm* g_pkGrenadeFormBQ;


class NodeQ
{
  public:
    NiAVObject* GetObject();
};

class ProjectileStateQ
{
  public:
    virtual void vs000();
    virtual void vs004();
    virtual void vs008();
    virtual void vs00c();
    virtual void vs010();
    virtual void vs014();
    virtual void vs018();
    virtual void vs01c();
    virtual void vs020();
    virtual void vs024();
    virtual void vs028();
    virtual void vs02c();
    virtual void vs030();
    virtual void vs034();
    virtual void vs038();
    virtual void vs03c();
    virtual void vs040();
    virtual void vs044();
    virtual void vs048();
    virtual void vs04c();
    virtual void vs050();
    virtual void vs054();
    virtual void vs058();
    virtual void vs05c();
    virtual void vs060();
    virtual void vs064();
    virtual void vs068();
    virtual void vs06c();
    virtual void vs070();
    virtual void vs074();
    virtual void vs078();
    virtual void vs07c();
    virtual void vs080();
    virtual void vs084();
    virtual void vs088();
    virtual void vs08c();
    virtual void vs090();
    virtual int GetID();
};

class ControllerQ
{
  public:
    virtual void vc000();
    virtual void vc004();
    virtual void vc008();
    virtual void vc00c();
    virtual void vc010();
    virtual void vc014();
    virtual void vc018();
    virtual void vc01c();
    virtual void vc020();
    virtual void vc024();
    virtual void vc028();
    virtual void vc02c();
    virtual void vc030();
    virtual void vc034();
    virtual void vc038();
    virtual void vc03c();
    virtual void vc040();
    virtual void vc044();
    virtual void vc048();
    virtual void vc04c();
    virtual void vc050();
    virtual void vc054();
    virtual void vc058();
    virtual void vc05c();
    virtual void vc060();
    virtual void vc064();
    virtual void vc068();
    virtual void vc06c();
    virtual void vc070();
    virtual void vc074();
    virtual void vc078();
    virtual void vc07c();
    virtual void vc080();
    virtual void vc084();
    virtual void vc088();
    virtual void vc08c();
    virtual void vc090();
    virtual int GetID();
    virtual void vd098();
    virtual void vd09c();
    virtual void vd0a0();
    virtual void vd0a4();
    virtual void vd0a8();
    virtual void vd0ac();
    virtual void vd0b0();
    virtual void vd0b4();
    virtual void vd0b8();
    virtual void vd0bc();
    virtual void vd0c0();
    virtual void vd0c4();
    virtual void vd0c8();
    virtual void vd0cc();
    virtual void Detach(NiAVObject* pkRoot, int a, int b, int c, int d);
    virtual void Attach(NiAVObject* pkTarget, NiAVObject* pkRoot);
};

class ProcessQ
{
  public:
    ControllerQ* GetController();
};

class WaterStateQ
{
  public:
    int GetState();
};

class CharControllerQ
{
  public:
    WaterStateQ* GetWaterState();
};

class BodyQ
{
  public:
    const hkVector4* GetPosition();
    CharControllerQ* GetPhysicsCharacterController();
};

class BodyRefQ
{
  public:
    BodyQ* Get();
};

class SettingsQ
{
  public:
    bool IsEnabled();
};
extern SettingsQ* g_pkSettingsQ;

class ManagerQ
{
  public:
    void SetLocked(bool bLocked);
};
extern ManagerQ* g_pkManagerQ;

class ExtraListQ
{
  public:
    int IsFlagSet();
};

class CellQ
{
  public:
    bool IsLoaded();
    bool IsAttached();
};

class ListQ;
extern ListQ g_kWaterListQ;

NodeQ* __cdecl bhkUtilFunctions_FindCollisionObjectBFS(void* pvName, int iFlag);
BodyRefQ* __cdecl FindFirstCollisionObject(void* pvTarget);
void __cdecl bhkWorld_SetMotion(void* pvRoot, int a, int b, int c, int d);
void* __cdecl hkVector4_getZero();
void __cdecl TESHavokUtilities_AddVelocity(void* pvRoot, NiPoint3* pkPos, int iFlag);
bool __cdecl NiObject_IsKindOf(ListQ* pkList, void* pvRoot);

// Reference physics attachment view: cell at +0x40 and helpers 0x0056c8f0/0x0056f140 belong to TESObjectREFR, not Projectile.
class ReferencePhysicsAttachment
{
  public:
    virtual void vp000();
    virtual void vp004();
    virtual void vp008();
    virtual void vp00c();
    virtual void vp010();
    virtual void vp014();
    virtual void vp018();
    virtual void vp01c();
    virtual void vp020();
    virtual void vp024();
    virtual void vp028();
    virtual void vp02c();
    virtual void vp030();
    virtual void vp034();
    virtual void vp038();
    virtual void vp03c();
    virtual void vp040();
    virtual void vp044();
    virtual void vp048();
    virtual void vp04c();
    virtual void vp050();
    virtual void vp054();
    virtual void vp058();
    virtual void vp05c();
    virtual void vp060();
    virtual void vp064();
    virtual void vp068();
    virtual void vp06c();
    virtual void vp070();
    virtual void vp074();
    virtual void vp078();
    virtual void vp07c();
    virtual void vp080();
    virtual void vp084();
    virtual void vp088();
    virtual void vp08c();
    virtual void vp090();
    virtual void vp094();
    virtual void vp098();
    virtual void vp09c();
    virtual void vp0a0();
    virtual void vp0a4();
    virtual void vp0a8();
    virtual void vp0ac();
    virtual void vp0b0();
    virtual void vp0b4();
    virtual void vp0b8();
    virtual void vp0bc();
    virtual void vp0c0();
    virtual void vp0c4();
    virtual void vp0c8();
    virtual void vp0cc();
    virtual void vp0d0();
    virtual void vp0d4();
    virtual void vp0d8();
    virtual void vp0dc();
    virtual void vp0e0();
    virtual void vp0e4();
    virtual void vp0e8();
    virtual void vp0ec();
    virtual void vp0f0();
    virtual void vp0f4();
    virtual void vp0f8();
    virtual void vp0fc();
    virtual bool IsActor();
    virtual void vq104();
    virtual void vq108();
    virtual void vq10c();
    virtual void vq110();
    virtual void vq114();
    virtual void vq118();
    virtual void vq11c();
    virtual void vq120();
    virtual void vq124();
    virtual void vq128();
    virtual void vq12c();
    virtual void vq130();
    virtual void vq134();
    virtual void vq138();
    virtual void vq13c();
    virtual void vq140();
    virtual void vq144();
    virtual void vq148();
    virtual void vq14c();
    virtual void vq150();
    virtual void vq154();
    virtual void vq158();
    virtual void vq15c();
    virtual void vq160();
    virtual void vq164();
    virtual void vq168();
    virtual void vq16c();
    virtual void vq170();
    virtual void vq174();
    virtual void vq178();
    virtual void vq17c();
    virtual void vq180();
    virtual void vq184();
    virtual void vq188();
    virtual void vq18c();
    virtual void vq190();
    virtual void vq194();
    virtual void vq198();
    virtual void vq19c();
    virtual void vq1a0();
    virtual void vq1a4();
    virtual void vq1a8();
    virtual void vq1ac();
    virtual void vq1b0();
    virtual void vq1b4();
    virtual void vq1b8();
    virtual void vq1bc();
    virtual void vq1c0();
    virtual void vq1c4();
    virtual void vq1c8();
    virtual void vq1cc();
    virtual NiAVObject* Get3D();
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
    CellQ* m_pkCell;

    bool HasFlag(int iFlag);
    TESForm* GetBaseForm();
    void HandleArrow();
    void HandleGrenade();
    void HandleFlame();
    void HandleBeam();
    ExtraListQ* GetExtraList();
    ProcessQ* GetProcess();
    bool IsInWaterVolume();
    bool IsSubmerged();
    void SetSubmerged(int iFlag);
    void UpdateAttachment(NiAVObject* pkRoot);
    void Finish(int a, int b);

    void TESObjectREFR_InitHavok();
};

// The shared hkVector4 union hides the local vector from MSVC's /GS heuristic; retain this function's original cookie.
#pragma strict_gs_check(push, on)
// @fnv 0x005768b0
// src: XBOX_PDB 0x005768b0
void ReferencePhysicsAttachment::TESObjectREFR_InitHavok()
{
    if (m_pkCell && !m_pkCell->IsLoaded() && !m_pkCell->IsAttached())
        return;
    NiAVObject* pkRoot = Get3D();
    NiAVObject* pkTarget = pkRoot;
    if (pkRoot)
    {
        g_pkManagerQ->SetLocked(true);
        if (!HasFlag(1))
        {
            if (GetBaseForm()->GetFormType() == 0x23)
            {
                TESForm* pkBase = GetBaseForm();
                if (!static_cast<BGSPlaceableWater*>(pkBase)->BGSPlaceableWater_IsAutomaticWater())
                    HandleArrow();
            }
            else if (GetBaseForm() == g_pkArrowFormQ)
            {
                HandleGrenade();
            }
            else if (GetBaseForm()->GetFormType() == 0xe)
            {
                HandleFlame();
            }
            else if (GetExtraList()->IsFlagSet() && GetBaseForm()->GetFormType() == 0x15)
            {
                HandleBeam();
            }
        }
        void* pvName = pkRoot->IsSceneNode();
        NodeQ* pkNode = 0;
        if (!IsActor())
        {
            pkNode = bhkUtilFunctions_FindCollisionObjectBFS(pvName, 1);
            pkTarget = pkNode ? pkNode->GetObject() : pkTarget;
        }
        if (pkTarget)
        {
            ProcessQ* pkProcess = GetProcess();
            if (pkProcess)
            {
                ControllerQ* pkController = pkProcess->GetController();
                BodyRefQ* pkBodyRef = FindFirstCollisionObject(pkTarget);
                ProjectileStateQ* pkState = pkBodyRef ? (ProjectileStateQ*)pkBodyRef->Get() : 0;
                if (pkController)
                {
                    if (!pkState || pkState->GetID() != pkController->GetID())
                    {
                        pkController->Attach(pkTarget, pkRoot);
                        if (GetBaseForm() == g_pkGrenadeFormAQ || GetBaseForm() == g_pkGrenadeFormBQ)
                        {
                            BodyQ* pkBody = pkBodyRef ? pkBodyRef->Get() : 0;
                            hkVector4 kPos(*pkBody->GetPosition());
                            if (((g_pkSettingsQ->IsEnabled() || IsInWaterVolume()) && pkBody &&
                                 kPos.equals4(*static_cast<const hkVector4*>(hkVector4_getZero()), 0.001f)) ||
                                !IsSubmerged())
                                bhkWorld_SetMotion(pkRoot, 5, 1, 0, 1);
                        }
                        switch (GetBaseForm()->GetFormType())
                        {
                        case 0x20:
                        case 0x21:
                            bhkWorld_SetMotion(pkRoot, 5, 1, 0, 1);
                            break;
                        default:
                            if (IsSubmerged())
                            {
                                BodyQ* pkBody = pkBodyRef ? pkBodyRef->Get() : 0;
                                CharControllerQ* pkChar = pkBody ? pkBody->GetPhysicsCharacterController() : 0;
                                if (pkChar && pkChar->GetWaterState()->GetState() != 5 &&
                                    pkChar->GetWaterState()->GetState() != 4)
                                {
                                    NiPoint3 kIntersectionOffset = g_kUpVectorQ * -1.0f;
                                    TESHavokUtilities_AddVelocity(pkRoot, &kIntersectionOffset, 0);
                                }
                                SetSubmerged(0);
                            }
                            break;
                        }
                        UpdateAttachment(pkRoot);
                    }
                }
            }
        }
        else
        {
            if (NiObject_IsKindOf(&g_kWaterListQ, pkRoot))
            {
                ProcessQ* pkProcess = GetProcess();
                if (pkProcess)
                {
                    ControllerQ* pkController = pkProcess->GetController();
                    if (pkController)
                        pkController->Detach(pkRoot, 0, 0, 0, 0);
                }
            }
        }
        g_pkManagerQ->SetLocked(false);
    }
    Finish(1, 1);
}
#pragma strict_gs_check(pop)
