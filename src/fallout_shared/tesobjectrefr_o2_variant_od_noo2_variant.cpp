#include "../../include/NiTArray.h"

// src/fallout_shared/tesobjectrefr_o2_variant_od_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/fallout_shared/tesobjectrefr_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/tesobjectrefr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectrefr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "tesobjectrefr_decls.h"
#include "../../include/NiRTTI.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/NiObject.h"
#include "../../include/ProjectileListener.h"
#include "../../include/bhkAabbPhantom.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/bhkWorldObject.h"
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
struct FUN_0056e2d0
{
    virtual ~FUN_0056e2d0();
};
extern const void* vftable_FUN_0056e2d0;
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
template <class T, class A> struct DebugPrimitiveArray
{
    void* vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, T& element);
    unsigned int SetAtGrow(unsigned int uiIndex, T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    __forceinline unsigned int Add(T element)
    {
        return SetAtGrow(m_usSize, element);
    }
};
typedef DebugPrimitiveArray<char*, NiTMallocInterface<char*> > DebugStrArray;
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
    static void operator delete(void*);
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
struct SphereScalingMethod : bhkSphereShape
{
    void __thiscall bhkBoxShape_CopyMembers(void* first, ArgB* second);
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
    static void operator delete(void* pvMem);

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

    unsigned int m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
extern const char* DAT_0126823c;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct HkResult_c6b
{
    int m_00;
    int m_04;
    HkResult_c6b();
};
struct HkFlags_c6b
{
    int m_iFlags;
    HkFlags_c6b(int i) : m_iFlags(i)
    {}
};
struct HkWorld_c6b
{
    HkResult_c6b hkpWorldObject_removeProperty(const void* apKey);
    void AddEntry(const void* apKey, void* apListener, HkFlags_c6b kFlags);
};
extern char DAT_01267b70[];
struct World_c6b
{
    virtual void v00();
    virtual void DeleteThis();
    volatile long m_lRefCount;
    HkWorld_c6b* m_pkWorld;
    void Lock();
    void Unlock();
};
struct FUN_00c6b980_cls
{
    int unk00, unk04, unk08, unk0c;
    World_c6b* m_spWorld;
    void bhkNiCollisionObject_SetWorldObject(World_c6b* apWorld);
};
extern int DAT_011f4280;
struct S_00c85c10_pair
{
    int unk00;
    int unk04;
};
struct S_00c85c10_flag
{
    int unk00;
    S_00c85c10_flag() : unk00(0)
    {}
};
struct S_00c85c10_entry
{
    int* value;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_00c85c10_data
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
    S_00c85c10_entry* entries;
    int count;

    void hkpWorldObject_removeProperty(int* result, int* value);
    void AddEntry(int* value, int* result, S_00c85c10_flag flag);
};
struct S_00c85c10
{
    void* unk00;
    void* unk04;
    S_00c85c10_data* unk08;

    void bhkWorldObject_SetAVObject(int* result, int* value);
};
struct ActionC68bf0
{
    bool bhkWorld_Remove(void* owner);
};
struct LinkedObjectC9d590
{
    ActionC68bf0* GetAction() const
    {
        return *reinterpret_cast<ActionC68bf0* const*>(reinterpret_cast<const char*>(this) + 0x350);
    }
};
struct ActionOwnerC9d590
{
    virtual void slot0(), slot1(), slot2(), slot3(), slot4(), slot5(), slot6(), slot7();
    virtual void slot8(), slot9(), slot10(), slot11(), slot12(), slot13(), slot14(), slot15();
    virtual void slot16(), slot17(), slot18(), slot19(), slot20(), slot21(), slot22(), slot23();
    virtual void slot24(), slot25(), slot26(), slot27(), slot28(), slot29(), slot30(), slot31();
    virtual void slot32(), slot33(), slot34(), slot35(), slot36();
    virtual LinkedObjectC9d590* ResolveLinkedObject();
    int unk4;
    void* handle;
    bool bhkEntity_Remove();
};
struct ObjectCA06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ObjectCA06();
};
ObjectCA06* __cdecl bhkSphereShape_CreateObject();
extern const char* DAT_01268288;
struct FUN_00ca0ac0_class : SphereShape
{
    void bhkSphereShape_GetViewerStrings(ViewerStringArray* strings);
};
extern int DAT_012686d0;
struct FUN_00cd2de0 : FUN_00c84c50
{
    virtual ~FUN_00cd2de0();
    void bhkSerializable_Kill();
};
extern int DAT_01268f8c;
struct FUN_00d54e60 : FUN_00c84c50
{
    virtual ~FUN_00d54e60();
    void bhkSerializable_Kill();
};

#include <xmmintrin.h>
struct TmpObj
{
    __m128 v;
    TmpObj();
};

int __cdecl NI2HK(TmpObj* out, int a);

struct VtblHolder
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(int a);
};

struct FUN_005610f0_cls : VtblHolder
{
    void bhkRigidBody_SetNiPosition(int a1);
};

// @fnv 0x005610f0
// src: COMMUNITY 0x005610f0
void FUN_005610f0_cls::bhkRigidBody_SetNiPosition(int a1)
{
    __declspec(align(16)) TmpObj tmp;
    this->v55(NI2HK(&tmp, a1));
}
