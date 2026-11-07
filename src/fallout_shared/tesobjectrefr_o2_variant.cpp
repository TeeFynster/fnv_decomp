#include "../../include/NiTArray.h"

// src/fallout_shared/tesobjectrefr_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectrefr.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesobjectrefr_decls.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiObject.h"
#include "../../include/ProjectileListener.h"
#include "../../include/bhkAabbPhantom.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkSphereShape.h"
#include "../../include/bhkWorldObject.h"
#include "../../include/hkReferencedObject.h"
#include "../../include/hkArray.h"
#include "../../include/hkpCollidable.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpWorldObject.h"
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

// @fnv 0x00c9d600
// src: XBOX_PDB 0x00c9d600
void FUN_00c9c240_holder::bhkEntity_Deactivate()
{
    if (this && m8)
        ((FUN_00c9c240_holder*)m8)->FUN_00c9c240();
}

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
struct FUN_00c6d190
{
    bhkRefObject base;
    int fc;
    int f10;
    unsigned char f14;
    FUN_00c6d190();
};
// @fnv 0x00c6d190
FUN_00c6d190::FUN_00c6d190()
{
    *(const void**)this = &DAT_01030394;
    fc = 0;
    f10 = 0;
    ++DAT_0126810c;
    *(const void**)this = &DAT_0103078c;
    ++DAT_01268238;
    *(const void**)this = &DAT_010306b4;
    ++DAT_01268208;
    f14 = 0;
    *(const void**)this = &vftable_FUN_0056e2d0;
    ++DAT_0126822c;
    f14 = 0;
}

// @fnv 0x00c876a0
// src: XBOX_PDB 0x00c876a0
__declspec(noinline) void ProjectileListener::bhkSerializable_Kill()
{
    typedef void(__thiscall * Fn)(void*, int);
    if (m_pHavokObject != 0)
        ((Fn)(*(void***)this)[0x8c / 4])(this, 0);
    ((Fn)(*(void***)this)[0xa4 / 4])(this, 1);
}

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
// @fnv 0x00c9d4c0
// src: XBOX_PDB 0x00c9d4c0
void FUN_00c9d4c0_holder::bhkEntity_Kill()
{
    void* p = m8;
    if (p)
    {
        if (*(void**)((char*)p + 0x210))
            ((hkReferencedObject*)*(void**)((char*)p + 0x210))->removeReference();
        *(void**)((char*)p + 0x210) = 0;
    }
    FUN_00c9c240();
}

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
// @fnv 0x00c9d5d0
// src: XBOX_PDB 0x00c9d5d0
void Holder00c9d5d0::bhkEntity_UpdateCFilter()
{
    CallRet* p = GetRet();
    if (p)
        p->hkpWorld_updateCollisionFilterOnEntity(unk8, 0, 1);
}

extern int DAT_01268238;
struct FUN_00c9f3b0 : bhkWorldObject
{
    virtual ~FUN_00c9f3b0();
};
// @fnv 0x00c9f3b0
FUN_00c9f3b0::~FUN_00c9f3b0()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    --DAT_01268238;
}

struct WorldHolder
{
    void UpdatePhantom(void* a, int b);
};
// @fnv 0x00c9f460
// src: XBOX_PDB 0x00c9f460
void bhkAabbPhantom::bhkPhantom_UpdateCFilter()
{
    WorldHolder* w = GetWorld();
    if (w)
        w->UpdatePhantom(m_pHavokObject, 1);
}

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
// @fnv 0x00c9fb70
// src: XBOX_PDB 0x00c9fb70
void __fastcall bhkConvexShape_CopyCinfo(MyObj* _this, int, OutS* _out)
{
    _this->bhkShape_CopyCinfo(_out);
    if (_this && _this->p8)
    {
        volatile float v = _this->p8->f10;
        _out->f4 = v;
        return;
    }
    volatile float u = DAT_010c72bc;
    _out->f4 = u;
}

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
// @fnv 0x00ca0740
// src: XBOX_PDB 0x00ca0740
void __thiscall bhkSphereShape::CopyMembers_00ca0740(void* a, ArgB* b)
{
    unsigned int tmp;
    RetV* r = reinterpret_cast<RetV*>(slotB4((char*)&tmp + 3));
    r->f4 *= b->f10;
    bhkSphereShape::bhkShape_CopyMembers(a, b);
}

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
// @fnv 0x00cb3070
// src: XBOX_PDB 0x00cb3070
void S_00cb3070::bhkRigidBodyT_LoadBinary(int a)
{
    bhkRigidBody_LoadBinary(a);
    v44(&a);
}

struct MM
{
    void Deallocate(void* p);
    void FUN_00cb2ff0();
    void* FUN_00cb30a0(unsigned int);
};
extern MM _g_memoryManager;
// @fnv 0x00cb30a0
void* MM::FUN_00cb30a0(unsigned int f)
{
    FUN_00cb2ff0();
    if (f & 1)
    {
        if (this)
        {
            char* b = (char*)this - *(unsigned char*)((char*)this - 1);
            _g_memoryManager.Deallocate(b);
        }
    }
    return this;
}

namespace fnv_00cb3860 {
extern int DAT_010302bc;
extern int DAT_01030394;
extern int DAT_010c879c;
extern int DAT_0126810c;
extern unsigned int DAT_012681bc;
extern int DAT_012681fc;
extern int DAT_012683c0;
extern const void* vftable_bhkLiquidAction;
struct FUN_00cb3860
{
    bhkRefObject base;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    FUN_00cb3860();
};
// @fnv 0x00cb3860
FUN_00cb3860::FUN_00cb3860()
{
    *(const void**)this = &DAT_01030394;
    m10 = 0;
    mC = 0;
    ++DAT_0126810c;
    *(const void**)this = &DAT_010302bc;
    ++DAT_012681fc;
    *(const void**)this = &vftable_bhkLiquidAction;
    m14 = 0;
    m18 = 0;
    ++DAT_012681bc;
    m10 = 0;
    *(const void**)this = &DAT_010c879c;
    ++DAT_012683c0;
}
}  // namespace fnv_00cb3860

extern int DAT_012681fc;
struct FUN_00c9d620_holder : bhkWorldObject
{
    FUN_00c9d620_holder();
    ~FUN_00c9d620_holder();
};
// @fnv 0x00c9d620
FUN_00c9d620_holder::~FUN_00c9d620_holder()
{
    void* p = m_pHavokObject;
    if (p)
    {
        void* q = *(void**)((char*)p + 0x210);
        if (q)
            ((hkReferencedObject*)q)->removeReference();
        *(void**)((char*)p + 0x210) = 0;
    }
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    --DAT_012681fc;
}

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
// @fnv 0x00c9fb00
FUN_00c9fb00::~FUN_00c9fb00()
{
    bhkSerializable_Kill();
    --DAT_01268250;
}

extern int DAT_012680f8;
extern int DAT_01268250;
extern int DAT_0126825c;
extern int DAT_01268274;
extern void* DAT_0103093c;
extern void* DAT_01030a24;
extern void* DAT_01030b0c;
extern void* DAT_01030bf4;
struct FUN_00c9fde0
{
    bhkRefObject base;
    int fc;
    int f10;
    FUN_00c9fde0();
};
// @fnv 0x00c9fde0
FUN_00c9fde0::FUN_00c9fde0()
{
    fc = 0;
    f10 = 0;
    *(const void**)this = &DAT_01030bf4;
    DAT_012680f8 += 1;
    *(const void**)this = &DAT_01030b0c;
    DAT_01268274 += 1;
    *(const void**)this = &DAT_01030a24;
    DAT_01268250 += 1;
    *(const void**)this = &DAT_0103093c;
    DAT_0126825c += 1;
}

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

// @fnv 0x00c9f5a0
// src: EXE 0x00c9f5a0
void* bhkAabbPhantom_CreateObject()
{
    return new Object_00c9f5a0;
}

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

// @fnv 0x00c84c50
FUN_00c84c50::~FUN_00c84c50()
{
    bhkSerializable_Kill();
    --DAT_012680f8;
}

extern int DAT_0126810c;

// @fnv 0x00c85790
bhkWorldObject::~bhkWorldObject()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    DAT_0126810c--;
}

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

// @fnv 0x00c85900
// src: XBOX_PDB 0x00c85900
void WorldObjectView::bhkWorldObject_CopyMembers(int a, int b)
{
    ScopedMode mode;
    unsigned char used;
    CollisionResult* result = GetResult(&used);
    result->state = 0;
    CollisionRecord*& nextRecord = result->record;
    CollisionRecord* record = nextRecord;
    if (record)
    {
        CollisionHandler* handler = record->handler;
        if (handler && !handler->IsAllowed(b))
        {
            CollisionValue* value = handler->Find(b);
            result->record = value ? value->record : 0;
        }
    }
    result->enabled = 0;
    bhkSerializable_CopyMembers(a, b);
}



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

void __fastcall AppendHavokViewerStrings(bhkRefObject*, void*, DebugStrArray*);

static __forceinline hkCdBodyStub* GetWorldObjectBody(bhkWorldObject* object)
{
    return (hkWorldObjStub*)object->m_pHavokObject;
}

// @fnv 0x00c86190
// src: XBOX_PDB 0x00c86190
void __fastcall bhkWorldObject_GetViewerStrings(bhkWorldObject* object, void*, DebugStrArray* arr)
{
    HeapContextGuard guard(0x10);
    typedef void (__thiscall* AppendStrings)(bhkRefObject*, DebugStrArray*);
    ((AppendStrings)AppendHavokViewerStrings)(object, arr);
    arr->Add(MakeDebugHeader(g_debugHeaderName));
    hkCdBodyStub* b = GetWorldObjectBody(object);
    DebugHelper_c849b0 helper(b ? b->unk1C : 0);
    helper.Fill(arr);
    if (object->m_pHavokObject)
    {
        hkCdBodyStub* body = GetWorldObjectBody(object);
        if (body)
        {
            hkShapeStub* shape = body->m_pCollisionShape;
            if (shape)
            {
                NiObject* niShape = shape->userData;
                if (niShape)
                {
                    char buf[0x80];
                    SprintfS(buf, 0x80, "%s: 0x%8X", niShape->GetRTTI()->m_pcName, niShape);
                    arr->Add(MakeDebugLine("Shape", buf));
                }
            }
        }
    }
}

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

// @fnv 0x00c8bed0
FUN_00c8bed0_cls::~FUN_00c8bed0_cls()
{
    this->unk08();
    DAT_012681b0--;
}

struct FUN_00c9eb30 : FUN_00c9f3b0
{
    virtual ~FUN_00c9eb30();
};

// @fnv 0x00c9eb30
FUN_00c9eb30::~FUN_00c9eb30()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    --DAT_01268208;
}

namespace fnv_00c9eec0 {
struct FUN_00c9eb30 : bhkWorldObject
{
    virtual ~FUN_00c9eb30();
};

struct FUN_00c9eec0 : FUN_00c9eb30
{
    virtual ~FUN_00c9eec0();
};

// @fnv 0x00c9eec0
FUN_00c9eec0::~FUN_00c9eec0()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    --DAT_0126822c;
}
}  // namespace fnv_00c9eec0

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

// @fnv 0x00c9efa0
// src: XBOX_PDB 0x00c9efa0
bhkRefObject* FUN_00c9efa0_cls::bhkSimpleShapePhantom_CreateClone(unsigned int flag)
{
    TlsGuard_t guard;
    bhkSerializable_CloneCritLock();
    FUN_00c6d190* p = new FUN_00c6d190;
    this->bhkWorldObject_CopyMembers(p, flag);
    bhkSerializable_CloneCritUnlock();
    return &p->base;
}

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
// @fnv 0x00c9f1e0
// src: XBOX_PDB 0x00c9f1e0
void S_00c9f1e0_Obj::bhkSimpleShapePhantom_GetFixedClosestPoints(S_00c9f1e0_Range* r)
{
    S_00c9f1e0_World* w = GetWorld()->world;
    S_00c9f1e0_Disp* d = w->disp;
    S_00c9f1e0_Ctx* c = ctx;
    S_00c9f1e0_Base2* b = 0;
    if (c)
        b = c;
    for (int i = c->count - 1; i >= 0; --i)
    {
        if (r->end == r->begin)
            break;
        S_00c9f1e0_Elem** slot = &c->items[i];
        unsigned char t = d->types[b->shape->type + 13][(*slot)->shape->type];
        d->funcs[t].fn(b, *slot, w, r);
    }
}

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

// @fnv 0x00c9f270
// src: XBOX_PDB 0x00c9f270
void C9F270Object::bhkSimpleShapePhantom_GetViewerStrings(C9F270StrArray* pkStrings)
{
    C9F270MemContext kContext(0x10);
    GetViewerStringsBase(pkStrings);
    pkStrings->Add(NiViewerStrings_NiGetViewerString_Title(g_pcC9F270ClassName));
}

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
// @fnv 0x00c9f320
// src: XBOX_PDB 0x00c9f320
void FUN_00c9f320_object::bhkAabbPhantom_KillCinfo(char release)
{
    TlsGuard guard;
    if (release)
    {
        ReleaseObject* object = (ReleaseObject*)unk0c;
        if (object)
        {
            object->DestroyObject(1);
        }
        unk0c = 0;
    }
}

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
// @fnv 0x00c9f420
// src: XBOX_PDB 0x00c9f420
bool FUN_00c9f420_Class::bhkPhantom_Remove()
{
    bool result = false;
    LinkedObject* linked = ResolveLinkedObject();
    PhysicsAction* action = linked ? linked->GetAction() : 0;
    if (action)
        result = action->bhkWorld_Remove_00c68cb0(handle);
    return result;
}

void __cdecl bhkSerializable_CloneCritLock();
void __cdecl bhkSerializable_CloneCritUnlock();
struct ProjectileCreator
{
    void __thiscall bhkWorldObject_CopyMembers(Object_00c9f5a0* projectile, int mode);
    Object_00c9f5a0* __thiscall bhkAabbPhantom_CreateClone(int mode);
};
// @fnv 0x00c9f640
// src: XBOX_PDB 0x00c9f640
Object_00c9f5a0* ProjectileCreator::bhkAabbPhantom_CreateClone(int mode)
{
    bhkSerializable_CloneCritLock();
    Object_00c9f5a0* projectile = new Object_00c9f5a0;
    bhkWorldObject_CopyMembers(projectile, mode);
    bhkSerializable_CloneCritUnlock();
    return projectile;
}

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
// @fnv 0x00c9f890
// src: XBOX_PDB 0x00c9f890
void Receiver::bhkAabbPhantom_Init(Input* input)
{
    ThreadFlagGuard tlsGuard;
    FUN_00cf2cb0* packet = new FUN_00cf2cb0(&input->payload, input->tag);
    dispatch(packet);
    FUN_00c905b0(packet);
    finish(input);
}

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

// @fnv 0x00c9f970
// src: XBOX_PDB 0x00c9f970
void FUN_00c9f970_cls::bhkAabbPhantom_GetViewerStrings(BC9F970StringArray* pkArray)
{
    BC9F970AllocTagScope kScope(0x10);
    bhkPhantom_GetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcC9F970Name);
    pkArray->Add(pcName);
}

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

// @fnv 0x00c9fc50
// src: XBOX_PDB 0x00c9fc50
void SphereShape::bhkConvexShape_GetViewerStrings(ViewerStringArray* apViewerStrings)
{
    MemContextGuard guard;
    BaseGetViewerStrings(apViewerStrings);
    apViewerStrings->Add(CreateDebugString(g_01268254.m_pcName));
    apViewerStrings->Add(CreateDebugString("Radius", GetRadius() * DAT_011b15c0));
}

extern int DAT_0126825c;

class FUN_00c9fd70_cls : public FUN_00c9fb00
{
  public:
    virtual ~FUN_00c9fd70_cls();
    void bhkSerializable_Kill();
};

// @fnv 0x00c9fd70
FUN_00c9fd70_cls::~FUN_00c9fd70_cls()
{
    bhkSerializable_Kill();
    --DAT_0126825c;
}

struct SphereScaleFields
{
    unsigned int m_00, m_04, m_08, m_0c;
    float m_10, m_14, m_18, m_1c;
};
struct SphereScalingMethod : bhkSphereShape
{
    void __thiscall bhkBoxShape_CopyMembers(void* first, ArgB* second);
};
// @fnv 0x00c9fea0
// src: XBOX_PDB 0x00c9fea0
void SphereScalingMethod::bhkBoxShape_CopyMembers(void* first, ArgB* second)
{
    char flag;
    SphereScaleFields* result = reinterpret_cast<SphereScaleFields*>(slotB4(&flag));
    float scale = second->f10;
    volatile float& initial = result->m_10;
    result->m_10 = initial * scale;
    result->m_14 *= scale;
    result->m_18 *= scale;
    result->m_1c *= scale;
    bhkSphereShape::bhkShape_CopyMembers(first, second);
}

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

// @fnv 0x00ca0090
// src: XBOX_PDB 0x00ca0090
void* FUN_00ca0090_cls::bhkBoxShape_CreateCinfo(unsigned char* out)
{
    TlsGuard_ca0090 guard;
    bool GetObjectKind = (m0C == 0);
    *out = GetObjectKind;
    if (GetObjectKind)
    {
        unsigned char* raw = (unsigned char*)reinterpret_cast<MemMgr_ca0090*>(&DAT_011f6238)->Game_DoHeapAlloc(0x30);
        unsigned char adj = (unsigned char)(0x10 - ((unsigned int)raw & 0xf));
        raw[adj - 1] = adj;
        *(unsigned int*)(raw + adj) = 0;
        volatile float* p = (volatile float*)(raw + adj);
        p[1] = DAT_010c72bc;
        volatile float* v = (volatile float*)(raw + adj + 0x10);
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 0.0f;
        v[3] = 0.0f;
        v[0] = 1.0f;
        v[1] = 1.0f;
        v[2] = 1.0f;
        m0C = (void*)(raw + adj);
        if (m08 != 0)
        {
            bhkConvexShape_CopyCinfo(m0C);
            void* q = (m08 != 0) ? (void*)((char*)m08 + 0x20) : (void*)&DAT_01267e30;
            reinterpret_cast<Sub_ca0090*>((char*)raw + adj + 0x10)->SetQuaternionComponentsFromVector(q);
        }
    }
    return m0C;
}

namespace fnv_00ca0410 {
extern __declspec(thread) int g_tlsMemContext;

struct MemContextGuard
{
    int iOld;
    MemContextGuard(int iNew)
    {
        iOld = g_tlsMemContext;
        g_tlsMemContext = iNew;
    }
    ~MemContextGuard()
    {
        g_tlsMemContext = iOld;
    }
};

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    void Add(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
    }
};

struct HalfExtentVec
{
    float x, y, z, w;
};

struct PhantomPoint3
{
    float x, y, z;
    char* FormatToBuffer(const char* pcPrefix);
};

PhantomPoint3 ConvertHalfExtent(const HalfExtentVec& v);
extern HalfExtentVec g_zeroHalfExtent;

struct AabbHavokObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    HalfExtentVec halfExtent;
};

char* NiGetViewerStringName(const char* pcName);
extern const char* g_aabbPhantomRttiName;

struct ShapePhantomBase
{
    int unk00;
    int unk04;
    AabbHavokObj* m_pHavok;
    void GetViewerStringsBase(ViewerStrings* apViewerStrings);
};

struct AabbPhantomVS : ShapePhantomBase
{
    void bhkBoxShape_GetViewerStrings(ViewerStrings* apViewerStrings);
};

// @fnv 0x00ca0410
// src: XBOX_PDB 0x00ca0410
void AabbPhantomVS::bhkBoxShape_GetViewerStrings(ViewerStrings* apViewerStrings)
{
    MemContextGuard guard(0x10);
    GetViewerStringsBase(apViewerStrings);
    apViewerStrings->Add(NiGetViewerStringName(g_aabbPhantomRttiName));
    AabbHavokObj* pObj = this ? m_pHavok : 0;
    const HalfExtentVec& v = pObj ? pObj->halfExtent : g_zeroHalfExtent;
    PhantomPoint3 kPt;
    kPt = ConvertHalfExtent(v);
    apViewerStrings->Add(kPt.FormatToBuffer("Half Extent"));
}
}  // namespace fnv_00ca0410

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

// @fnv 0x00ca0540
FUN_00ca0540::~FUN_00ca0540()
{
    Shutdown();
    --ms_uiInstances;
}

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

// @fnv 0x00ca05b0
// src: XBOX_PDB 0x00ca05b0
void FUN_00ca05b0_cls::bhkSphereRepShape_GetViewerStrings(BCA05B0StringArray* pkArray)
{
    BCA05B0AllocTagScope kScope(0x10);
    bhkShape_GetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCA05B0Name);
    pkArray->Add(pcName);
}

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

// @fnv 0x00ca0660
FUN_00ca0660::~FUN_00ca0660()
{
    this->unk08();
    DAT_01268280--;
}

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

// @fnv 0x00ca0840
// src: XBOX_PDB 0x00ca0840
CA0840Output* CA0840Constraint::bhkSphereShape_CreateCinfo(bool* pbCreated)
{
    CA0840MemContext kContext(0x10);
    *pbCreated = m_pkOutput == 0;
    if (*pbCreated)
    {
        m_pkOutput = new CA0840Output;
        if (m_pkWorld)
            SetOutput(m_pkOutput);
    }
    return m_pkOutput;
}

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

// @fnv 0x00caacf0
FUN_00caacf0::~FUN_00caacf0()
{
    Shutdown();
    --ms_uiInstances;
}

extern int DAT_012683c8;

// @fnv 0x00cb3060
// src: COMMUNITY 0x00cb3060
void* bhkRigidBodyT_GetRTTI()
{
    return &DAT_012683c8;
}

namespace fnv_00cb3a40 {
void bhkSerializable_CloneCritLock();
void bhkSerializable_CloneCritUnlock() throw();
extern __declspec(thread) int threadMode;
struct MemoryAllocator
{
    void* Game_DoHeapAlloc(unsigned int bytes);
};
extern MemoryAllocator DAT_011f6238;
struct FUN_00cb3860
{
    FUN_00cb3860();
    static __forceinline unsigned char* align(unsigned char* memory)
    {
        unsigned char mod = (unsigned char)(unsigned int)memory;
        mod &= 15;
        unsigned char offset = 16;
        offset -= mod;
        memory += offset;
        memory[-1] = offset;
        return memory;
    }
    static void* operator new(unsigned int)
    {
        return align((unsigned char*)DAT_011f6238.Game_DoHeapAlloc(0x50));
    }
};
struct ThreadRouterScope
{
    int previousMode;
    ThreadRouterScope() : previousMode(threadMode)
    {
        threadMode = 16;
    }
    ~ThreadRouterScope() throw()
    {
        bhkSerializable_CloneCritUnlock();
        threadMode = previousMode;
    }
};
struct World
{
    virtual void m00();
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05();
    virtual void m06();
    virtual void m07();
    virtual void m08();
    virtual void m09();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(int active);
    void bhkRigidBodyT_CopyMembers(FUN_00cb3860* object, int flags);
    FUN_00cb3860* bhkRigidBodyT_CreateClone(int flags);
};
// @fnv 0x00cb3a40
// src: XBOX_PDB 0x00cb3a40
FUN_00cb3860* World::bhkRigidBodyT_CreateClone(int flags)
{
    ThreadRouterScope threadScope;
    bhkSerializable_CloneCritLock();
    m63(0);
    FUN_00cb3860* obj = new FUN_00cb3860;
    bhkRigidBodyT_CopyMembers(obj, flags);
    m63(1);
    return obj;
}
}  // namespace fnv_00cb3a40

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

// @fnv 0x00cc2350
FUN_00cc2350::~FUN_00cc2350()
{
    Release();
    --g_iCC2350Count;
}

extern int DAT_01268660;

struct FUN_00cca8d0 : FUN_00c9fb00
{
    virtual ~FUN_00cca8d0();
    void bhkSerializable_Kill();
};

// @fnv 0x00cca8d0
FUN_00cca8d0::~FUN_00cca8d0()
{
    bhkSerializable_Kill();
    --DAT_01268660;
}

extern int DAT_0126868c;

struct FUN_00ccd080 : FUN_00c9fb00
{
    int unk04;
    virtual ~FUN_00ccd080();
};

// @fnv 0x00ccd080
FUN_00ccd080::~FUN_00ccd080()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    DAT_0126868c--;
}

extern int DAT_0126869c;

struct FUN_00ccdbc0 : FUN_00c9fb00
{
    void bhkSerializable_Kill();
    virtual ~FUN_00ccdbc0();
};

// @fnv 0x00ccdbc0
FUN_00ccdbc0::~FUN_00ccdbc0()
{
    bhkSerializable_Kill();
    --DAT_0126869c;
}

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

// @fnv 0x00cce900
FUN_00cce900::~FUN_00cce900()
{
    Release();
    --g_iCCE900Count;
}

struct FUN_00ccf4f0_cls : FUN_00c9fb00
{
    int unk04;
    virtual ~FUN_00ccf4f0_cls();
};

// @fnv 0x00ccf4f0
FUN_00ccf4f0_cls::~FUN_00ccf4f0_cls()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
}

extern int DAT_012686c0;

class FUN_00ccf740_cls : public FUN_00c9fb00
{
  public:
    virtual ~FUN_00ccf740_cls();
    void bhkSerializable_Kill();
};

// @fnv 0x00ccf740
FUN_00ccf740_cls::~FUN_00ccf740_cls()
{
    bhkSerializable_Kill();
    --DAT_012686c0;
}


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

// @fnv 0x00c9ef30
// src: EXE 0x00c9ef30
NiObject* NiControllerC9E::bhkSimpleShapePhantom_CreateObject()
{
    return new NiControllerC9E;
}

extern const char* DAT_0126823c;
// @fnv 0x00c9f480
// src: XBOX_PDB 0x00c9f480
void FUN_00c9f970_cls::bhkPhantom_GetViewerStrings(BC9F970StringArray* pkArray)
{
    TlsGuard_t kGuard;
    typedef void (__thiscall* AppendStrings)(bhkWorldObject*, DebugStrArray*);
    ((AppendStrings)bhkWorldObject_GetViewerStrings)((bhkWorldObject*)this, (DebugStrArray*)pkArray);
    pkArray->Add(NiViewerStrings_NiGetViewerString_Title(DAT_0126823c));
}

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
// @fnv 0x00c6b980
// src: XBOX_PDB 0x00c6b980
void FUN_00c6b980_cls::bhkNiCollisionObject_SetWorldObject(World_c6b* apWorld)
{
    if (m_spWorld == apWorld)
        return;
    World_c6b* pkOld = m_spWorld;
    if (pkOld)
    {
        HkWorld_c6b* pkHk = pkOld->m_pkWorld;
        if (pkHk)
        {
            pkOld->Lock();
            pkHk->hkpWorldObject_removeProperty(DAT_01267b70);
            pkOld->Unlock();
        }
    }
    if (m_spWorld != apWorld)
    {
        if (m_spWorld)
        {
            World_c6b* p = m_spWorld;
            if (InterlockedDecrement(&p->m_lRefCount) == 0)
                p->DeleteThis();
        }
        m_spWorld = apWorld;
        if (m_spWorld)
            InterlockedIncrement(&m_spWorld->m_lRefCount);
    }
    World_c6b* pkNew = m_spWorld;
    if (pkNew)
    {
        HkFlags_c6b kFlags(0);
        HkWorld_c6b* pkHk = pkNew->m_pkWorld;
        if (pkHk)
        {
            pkNew->Lock();
            pkHk->AddEntry(DAT_01267b70, this, kFlags);
            pkNew->Unlock();
        }
    }
}

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

// @fnv 0x00c85c10
// src: XBOX_PDB 0x00c85c10
void S_00c85c10::bhkWorldObject_SetAVObject(int* result, int* value)
{
    S_00c85c10_pair local;

    if (value == 0)
    {
        value = &DAT_011f4280;
    }

    S_00c85c10_data* data = unk08;

    if (data != 0)
    {
        int count = data->count;
        int i = 0;
        if (count > 0)
        {
            S_00c85c10_entry* entry = data->entries;
            do
            {
                if (entry->value == value)
                {
                    if (unk08 != 0)
                    {
                        unk08->hkpWorldObject_removeProperty(&local.unk00, value);
                    }
                    break;
                }
                ++entry;
                ++i;
            } while (i < count);
        }
    }

    if (result != 0)
    {
        data = unk08;
        S_00c85c10_flag flag;
        if (data != 0)
        {
            data->AddEntry(value, result, flag);
        }
    }
}

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

// @fnv 0x00c9d590
// src: XBOX_PDB 0x00c9d590
bool ActionOwnerC9d590::bhkEntity_Remove()
{
    bool result = false;
    LinkedObjectC9d590* obj = ResolveLinkedObject();
    ActionC68bf0* action = obj ? obj->GetAction() : 0;
    if (action)
        result = action->bhkWorld_Remove(handle);
    return result;
}

struct ObjectCA06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ObjectCA06();
};
// @fnv 0x00ca06d0
// src: EXE 0x00ca06d0
ObjectCA06* __cdecl bhkSphereShape_CreateObject()
{
    return new ObjectCA06;
}

extern const char* DAT_01268288;

struct FUN_00ca0ac0_class : SphereShape
{
    void bhkSphereShape_GetViewerStrings(ViewerStringArray* strings);
};

// @fnv 0x00ca0ac0
// src: XBOX_PDB 0x00ca0ac0
void FUN_00ca0ac0_class::bhkSphereShape_GetViewerStrings(ViewerStringArray* strings)
{
    TlsGuard_t context;
    bhkConvexShape_GetViewerStrings(strings);
    char* text = NiViewerStrings_NiGetViewerString_Title(DAT_01268288);
    strings->Add(text);
}

extern int DAT_012686d0;

struct FUN_00cd2de0 : FUN_00c84c50
{
    virtual ~FUN_00cd2de0();
    void bhkSerializable_Kill();
};
// @fnv 0x00cd2de0
FUN_00cd2de0::~FUN_00cd2de0()
{
    bhkSerializable_Kill();
    --DAT_012686d0;
}

extern int DAT_01268f8c;

struct FUN_00d54e60 : FUN_00c84c50
{
    virtual ~FUN_00d54e60();
    void bhkSerializable_Kill();
};

// @fnv 0x00d54e60
FUN_00d54e60::~FUN_00d54e60()
{
    bhkSerializable_Kill();
    --DAT_01268f8c;
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
struct LoadStream
{
    int unk00;
    unsigned int version;
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
    unsigned char unk1e4;
    unsigned char endian;
    void Prepare();
};
struct LoadedData
{
    unsigned int flags;
    int unk04;
    int unk08;
    void* data;
    int count;
    int capacity;
};
struct ReleaseAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Free(void*, unsigned int);
};
struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ReleaseAllocator* m_pStreamAllocator;
    ReleaseAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
MemRouter* MemRouter_getInstance();
struct LoadObject
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
    virtual void* GetHavokClass();
    virtual void v43();
    virtual void v44();
    virtual LoadedData* GetHavokData(int* piSize);
    void LoadBase(LoadStream*);
    void bhkWorldObject_LoadBinary(LoadStream*);
};
void SwapHavokObjectEndian(LoadedData* pkData, void* pkClass, void** ppkArrayData);
// @fnv 0x00c85f20
// src: XBOX_PDB 0x00c85f20
void LoadObject::bhkWorldObject_LoadBinary(LoadStream* stream)
{
    TlsGuard_t guard;
    stream->Prepare();
    LoadBase(stream);

    int iSize;
    LoadedData* data = GetHavokData(&iSize);
    if (stream->endian != 1)
    {
        void* pkClass = GetHavokClass();
        SwapHavokObjectEndian(data, pkClass, &data->data);
    }

    // hkArray::ClearAndRelease
    ReleaseAllocator& alloc = MemRouter_getInstance()->heap();
    data->count = 0;
    if ((data->capacity & 0x80000000) == 0)
        alloc.Free(data->data, (data->capacity & 0x3fffffff) * 8);
    data->data = 0;
    data->capacity = 0x80000000;

    if (stream->endian != 1)
        data->flags = _byteswap_ulong(data->flags);
    if (stream->version < 9 && (data->flags & 0x20))
        data->flags = (data->flags & ~0x20) | 0x8000;
    unsigned int kind = data->flags & 0x7f;
    if (kind == 8 || kind == 0x1d)
        data->flags &= ~0x4000;
}

struct ThreadState
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
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
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int tag;
};
extern __declspec(thread) ThreadState tlsState;
struct TagScope
{
    unsigned int old;
    TagScope(unsigned int tag)
    {
        old = tlsState.tag;
        tlsState.tag = tag;
    }
    ~TagScope()
    {
        tlsState.tag = old;
    }
};

struct FreeAllocator : Allocator
{
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
};
struct RefLink
{
    unsigned int unk00, unk04;
    RefLink* ref;
};
struct Pair8
{
    int a, b;
};
// hkArray::clearAndDeallocate through the pool's allocator.
template <class T> static __forceinline void ClearAndRelease(hkArrayBase<T>& a, Pool* pool)
{
    FreeAllocator& alloc = *static_cast<FreeAllocator*>(pool->allocator);
    a.m_iElementCount = 0;
    if ((a.m_iCapacityState & 0x80000000) == 0)
        alloc.ReturnMemory(a.m_data, a.getCapacity() * sizeof(T));
    a.m_data = 0;
    a.m_iCapacityState = 0x80000000;
}
struct Info
{
    unsigned int value;
    RefLink* link;
    unsigned int unk08;
    hkArray<Pair8> arr;
};
void __cdecl bhkStream_SwapHKArray(Info*, int, hkArray<Pair8>*);
struct Stream86060
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
    virtual void WriteRef(void*);
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
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
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned char mode;
};
struct Obj86060
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
    virtual void Release(void*);
    virtual int Kind();
    virtual void vac();
    virtual void vb0();
    virtual Info* GetInfo(void**);
    void SaveSerializeData(Stream86060&);
    void bhkWorldObject_SaveBinary(Stream86060&);
};
// @fnv 0x00c86060
// src: XBOX_PDB 0x00c86060
void Obj86060::bhkWorldObject_SaveBinary(Stream86060& stream)
{
    TagScope scope(16);
    void* handle;
    Info* info = GetInfo(&handle);
    if (stream.mode != 1)
    {
        int kind = Kind();
        bhkStream_SwapHKArray(info, kind, &info->arr);
        info->value = _byteswap_ulong(info->value);
    }
    ClearAndRelease(info->arr, hkMemoryRouter_getInstance());
    RefLink* ref = info->link;
    ref = ref ? ref->ref : 0;
    stream.WriteRef(ref);
    SaveSerializeData(stream);
    Release(handle);
}

extern int DAT_01268244;


// @fnv 0x00c9f530
bhkAabbPhantom::~bhkAabbPhantom()
{
    reinterpret_cast<ProjectileListener*>(this)->bhkSerializable_Kill();
    DAT_01268244--;
}

struct Arg
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    unsigned char unk1e4;
    unsigned char m1e5;
};

struct Rec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    volatile unsigned int m20;
    volatile unsigned int m24;
    volatile unsigned int m28;
    volatile unsigned int m2c;
    volatile unsigned int m30;
    volatile unsigned int m34;
    volatile unsigned int m38;
    volatile unsigned int m3c;
};

struct FUN_00c9f700_cls
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
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual Rec* GetRec(Arg** pp);
    void bhkWorldObject_LoadBinary(Arg* a);
    void bhkAabbPhantom_LoadBinary(Arg* volatile a);
};

// @fnv 0x00c9f700
// src: XBOX_PDB 0x00c9f700
void FUN_00c9f700_cls::bhkAabbPhantom_LoadBinary(Arg* volatile a)
{
    Arg* p = a;
    bhkWorldObject_LoadBinary(p);
    Rec* r = GetRec((Arg**)&a);
    if (p->m1e5 != 1)
    {
        r->m30 = _byteswap_ulong(r->m30);
        r->m34 = _byteswap_ulong(r->m34);
        r->m38 = _byteswap_ulong(r->m38);
        r->m3c = _byteswap_ulong(r->m3c);
        r->m20 = _byteswap_ulong(r->m20);
        r->m24 = _byteswap_ulong(r->m24);
        r->m28 = _byteswap_ulong(r->m28);
        r->m2c = _byteswap_ulong(r->m2c);
    }
}

// Save: on big-endian streams, byte-swap the Havok object's two vectors in place around the base save.

struct C9F770Vector
{
    unsigned long x;
    unsigned long y;
    unsigned long z;
    unsigned long w;
};

inline void C9F770Swap(unsigned long& ulValue)
{
    ulValue = _byteswap_ulong(ulValue);
}

inline void C9F770SwapVector(C9F770Vector& kVector)
{
    C9F770Swap(kVector.x);
    C9F770Swap(kVector.y);
    C9F770Swap(kVector.z);
    C9F770Swap(kVector.w);
}

struct C9F770HavokData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    C9F770Vector m_kPivotA;
    C9F770Vector m_kPivotB;
};

class C9F770Stream
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
    unsigned char m_ucEndian;
};

class C9F770Constraint
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual C9F770HavokData* GetHavokData(bool* pbOwned);

    void SaveBaseBinary(C9F770Stream& kStream);
    void bhkAabbPhantom_SaveBinary(C9F770Stream& kStream);
};

// @fnv 0x00c9f770
// src: XBOX_PDB 0x00c9f770
void C9F770Constraint::bhkAabbPhantom_SaveBinary(C9F770Stream& kStream)
{
    bool bIsValid;
    C9F770HavokData* pkData = GetHavokData(&bIsValid);
    if (kStream.m_ucEndian != 1)
    {
        C9F770SwapVector(pkData->m_kPivotB);
        C9F770SwapVector(pkData->m_kPivotA);
    }
    SaveBaseBinary(kStream);
    if (kStream.m_ucEndian != 1)
    {
        C9F770SwapVector(pkData->m_kPivotB);
        C9F770SwapVector(pkData->m_kPivotA);
    }
}

struct Arg_00c9fbc0
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
    unsigned char unk1e4;
    unsigned char unk1e5;
};

struct Rec_00c9fbc0
{
    int unk0;
    unsigned int unk4;
};

struct Cls_00c9fbc0
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual Rec_00c9fbc0* GetRec(Arg_00c9fbc0*& a);
    void bhkShape_LoadBinary(Arg_00c9fbc0* a);
    void bhkConvexShape_LoadBinary(Arg_00c9fbc0* a1);
};

// @fnv 0x00c9fbc0
// src: XBOX_PDB 0x00c9fbc0
void Cls_00c9fbc0::bhkConvexShape_LoadBinary(Arg_00c9fbc0* a1)
{
    Arg_00c9fbc0* volatile* pa = &a1;
    Arg_00c9fbc0* a = *pa;
    bhkShape_LoadBinary(a);
    if (a->unk1e5 != 1)
    {
        Rec_00c9fbc0* r = GetRec(a1);
        unsigned int* p = &r->unk4;
        *p = _byteswap_ulong(*p);
    }
}

struct C9FC00Stream
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
    unsigned char m_ucEndian;
};

struct C9FC00Data
{
    int unk00;
    unsigned long m_ulValue;
};

class C9FC00Object
{
  public:
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual C9FC00Data* GetData(bool* pbValid);

    void SaveBinaryBase(C9FC00Stream& kStream);
    void bhkConvexShape_SaveBinary(C9FC00Stream& kStream);
};

// @fnv 0x00c9fc00
// src: XBOX_PDB 0x00c9fc00
void C9FC00Object::bhkConvexShape_SaveBinary(C9FC00Stream& kStream)
{
    bool bValid;
    C9FC00Data* pkData = GetData(&bValid);
    if (kStream.m_ucEndian != 1)
        pkData->m_ulValue = _byteswap_ulong(pkData->m_ulValue);
    SaveBinaryBase(kStream);
    if (kStream.m_ucEndian != 1)
        pkData->m_ulValue = _byteswap_ulong(pkData->m_ulValue);
}

struct FUN_00c9ff00_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
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

struct FUN_00c9ff00_cls
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
    virtual volatile unsigned int* vGet(void* pp);
    void bhkConvexShape_LoadBinary(FUN_00c9ff00_arg* a);
    void bhkBoxShape_LoadBinary(FUN_00c9ff00_arg* a1);
};

// @fnv 0x00c9ff00
// src: XBOX_PDB 0x00c9ff00
void FUN_00c9ff00_cls::bhkBoxShape_LoadBinary(FUN_00c9ff00_arg* volatile a1)
{
    FUN_00c9ff00_arg* obj = a1;
    bhkConvexShape_LoadBinary(obj);
    if (obj->m_1e5 != 1)
    {
        volatile unsigned int* p = vGet((void*)&a1) + 4;
        p[0] = _byteswap_ulong(p[0]);
        p[1] = _byteswap_ulong(p[1]);
        p[2] = _byteswap_ulong(p[2]);
        p[3] = _byteswap_ulong(p[3]);
    }
}

struct FUN_00c9ff50_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
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
};

struct FUN_00c9ff50_cls
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
    virtual volatile unsigned int* vGet(unsigned char* out);
    void bhkConvexShape_SaveBinary(FUN_00c9ff50_arg* a);
    void bhkBoxShape_SaveBinary(FUN_00c9ff50_arg* a1);
};

// @fnv 0x00c9ff50
// src: XBOX_PDB 0x00c9ff50
void FUN_00c9ff50_cls::bhkBoxShape_SaveBinary(FUN_00c9ff50_arg* a1)
{
    unsigned int tmp;
    volatile unsigned int* p = vGet((unsigned char*)&tmp + 3);
    if (a1->unk1E4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
    }
    bhkConvexShape_SaveBinary(a1);
    if (a1->unk1E4 != 1)
    {
        p[4] = _byteswap_ulong(p[4]);
        p[5] = _byteswap_ulong(p[5]);
        p[6] = _byteswap_ulong(p[6]);
        p[7] = _byteswap_ulong(p[7]);
    }
}

struct FUN_0094dbb0
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    FUN_0094dbb0();
    static void* operator new(unsigned int size)
    {
        return Object_DispatchCommandFour(size);
    }
};
struct CA0780Owner
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
    virtual void vf22();
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
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49(FUN_0094dbb0* object, unsigned int argument);
    FUN_0094dbb0* bhkSphereShape_CreateClone(unsigned int argument);
};
// @fnv 0x00ca0780
// src: XBOX_PDB 0x00ca0780
FUN_0094dbb0* CA0780Owner::bhkSphereShape_CreateClone(unsigned int argument)
{
    TlsGuard_t guard;
    bhkSerializable_CloneCritLock();
    FUN_0094dbb0* object = new FUN_0094dbb0;
    vf49(object, argument);
    bhkSerializable_CloneCritUnlock();
    return object;
}

extern int DAT_012682cc;

struct FUN_00ca4da0 : FUN_00c84c50
{
    virtual ~FUN_00ca4da0();
    void bhkSerializable_Kill();
};

// @fnv 0x00ca4da0
FUN_00ca4da0::~FUN_00ca4da0()
{
    bhkSerializable_Kill();
    DAT_012682cc--;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

extern int DAT_012681bc;
extern int DAT_012683c0;




// These helpers retain the unit's inlined Havok access path.  The shared
// bhkWorldObject declaration supplies the object layout and constructor.
void __fastcall SetHavokWorldObject(bhkWorldObject*, void*, hkReferencedObject*);
void __fastcall CheckHavokWorldObject(bhkWorldObject*, void*);

extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

inline bhkSerializable::bhkSerializable()
{}

inline bhkWorldObject::bhkWorldObject()
{
    _ReadWriteBarrier();
    pInfo = 0;
    iFlags = 0;
    _ReadWriteBarrier();
    ++DAT_0126810c;
}

static __forceinline NiObject* GetWorldObjectShape(bhkWorldObject* object)
{
    hkpWorldObject* pkObject = (hkpWorldObject*)object->m_pHavokObject;
    if (pkObject)
    {
        typedef void (__thiscall* CheckObject)(bhkWorldObject*);
        ((CheckObject)CheckHavokWorldObject)(object);
        const hkpCollidable* pkCollidable = &pkObject->m_kCollidable;
        ((CheckObject)CheckHavokWorldObject)(object);
        if (pkCollidable)
        {
            const hkpShape* pkShape = pkCollidable->m_pCollisionShape;
            if (pkShape)
                return reinterpret_cast<NiObject*>(pkShape->m_ulUserData);
        }
    }
    return 0;
}

struct bhkEntityBase : bhkWorldObject
{
    bhkEntityBase()
    {
        ++DAT_012681fc;
    }
};

struct bhkRigidBodyBase : bhkEntityBase
{
    int unk14;
    int unk18;
    bhkRigidBodyBase()
    {
        unk14 = 0;
        unk18 = 0;
        ++DAT_012681bc;
    }
    ~bhkRigidBodyBase();
};

struct FUN_00cb38c0 : bhkRigidBodyBase
{
    FUN_00cb38c0(bhkRigidBodyBase* pkSource);
    virtual ~FUN_00cb38c0();
};

// @fnv 0x00cb38c0
FUN_00cb38c0::FUN_00cb38c0(bhkRigidBodyBase* pkSource)
{
    ++DAT_012683c0;
    hkpWorldObject* pkObject = (hkpWorldObject*)pkSource->m_pHavokObject;
    pkObject->addReference();
    NiObject* pkShape = GetWorldObjectShape(pkSource);
    if (pkShape)
        InterlockedIncrement((volatile long*)&pkShape->m_uiRefCount);
    typedef void (__thiscall* SetObject)(bhkWorldObject*, hkReferencedObject*);
    ((SetObject)(*(void***)pkSource)[35])(pkSource, 0);
    ((SetObject)SetHavokWorldObject)(this, pkObject);
    if (InterlockedDecrement((volatile long*)&pkShape->m_uiRefCount) == 0)
        pkShape->DeleteThis();
    pkObject->removeReference();
}

struct FUN_00cbe9f0_Target;
struct FUN_00c85c80_Class
{
    int bhkWorldObject_GetAVObject(int a);
};
struct S00cbe9f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00cbe9f0_Target* m18;
    unsigned char m1c;

    void bhkSimpleShapePhantom_Init(const void* a);
    void bhkWorldObject_SetAVObject(int a, int b);
    void bhkCollisionBox_Init(int a1, FUN_00cbe9f0_Target* a2);
};

// @fnv 0x00cbe9f0
// src: XBOX_PDB 0x00cbe9f0
void S00cbe9f0_cls::bhkCollisionBox_Init(int a1, FUN_00cbe9f0_Target* a2)
{
    m1c = 0;
    bhkSimpleShapePhantom_Init((const void*)a1);
    m18 = a2;
    if (a2 == 0)
        return;
    FUN_00c85c80_Class* p = *(FUN_00c85c80_Class**)((char*)a2 + 0x594);
    bhkWorldObject_SetAVObject(p ? p->bhkWorldObject_GetAVObject(0) : 0, 0);
}

extern "C" unsigned short __cdecl _byteswap_ushort(unsigned short);
struct FUN_00c9d4f0_obj
{
    unsigned char unk00[0x1e5];
    unsigned char m_1e5;
};

struct FUN_00c9d4f0_cls
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
    virtual unsigned char* vGet(unsigned char* pp);
    void bhkWorldObject_LoadBinary(FUN_00c9d4f0_obj* p);
    void bhkEntity_LoadBinary(FUN_00c9d4f0_obj* p);
};

// @fnv 0x00c9d4f0
// src: XBOX_PDB 0x00c9d4f0
void FUN_00c9d4f0_cls::bhkEntity_LoadBinary(FUN_00c9d4f0_obj* p)
{
    bhkWorldObject_LoadBinary(p);
    if (p->m_1e5 != 1)
    {
        unsigned char flag;
        unsigned char* b = vGet(&flag);
        unsigned short* w = (unsigned short*)(b + 0x1a);
        *w = _byteswap_ushort(*w);
    }
}

struct FUN_00c9d530_arg
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
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    unsigned char m1E4;
};
struct FUN_00c9d530_cls
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual unsigned char* GetRef(unsigned char* flag);
    void bhkWorldObject_SaveBinary(FUN_00c9d530_arg* a);
    void bhkEntity_SaveBinary(FUN_00c9d530_arg* a1);
};

// @fnv 0x00c9d530
// src: XBOX_PDB 0x00c9d530
void FUN_00c9d530_cls::bhkEntity_SaveBinary(FUN_00c9d530_arg* a1)
{
    unsigned char flag;
    unsigned char* r = GetRef(&flag);
    FUN_00c9d530_arg* a = a1;
    if (a->m1E4 != 1)
    {
        unsigned short* p = (unsigned short*)(r + 0x1a);
        *p = _byteswap_ushort(*p);
    }
    bhkWorldObject_SaveBinary(a);
    if (a->m1E4 != 1)
    {
        unsigned short* p = (unsigned short*)(r + 0x1a);
        *p = _byteswap_ushort(*p);
    }
}

#include <stdio.h>
extern __declspec(thread) int allocationContext;
struct AllocationScope
{
    int old;
    AllocationScope() : old(allocationContext)
    {
        allocationContext = 16;
    }
    ~AllocationScope()
    {
        allocationContext = old;
    }
};
struct StringArray
{
    void* vfptr;
    char** data;
    unsigned short capacity, size, used, growth;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growth);
        SetAt(index, value);
    }
};
extern const char* DAT_01268200;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString(const char*, bool);
char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);
struct Body
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
    void* island;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char motionType;
    bool* isActive_00c9bff0(bool*);
};
struct Object
{
    void* vfptr;
    int unk04;
    Body* body;
    void bhkWorldObject_GetViewerStrings(StringArray*);
    bool IsActive()
    {
        bool active;
        if (!this || !body)
            return false;
        return *body->isActive_00c9bff0(&active) != 0;
    }
    bool IsFixed()
    {
        if (!this || !body)
            return false;
        return body->motionType == 5;
    }
    void* GetIsland()
    {
        return this && body ? body->island : 0;
    }
    void bhkEntity_GetViewerStrings(StringArray* strings);
};
// @fnv 0x00c9d6b0
// src: XBOX_PDB 0x00c9d6b0
void Object::bhkEntity_GetViewerStrings(StringArray* strings)
{
    AllocationScope scope;
    bool active;
    bhkWorldObject_GetViewerStrings(strings);
    strings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_01268200));
    strings->Add(NiGetViewerString("Active", (this && body) ? (*body->isActive_00c9bff0(&active) ? true : false) : false));
    strings->Add(NiGetViewerString("Fixed", (this && body) ? (body->motionType == 5 ? true : false) : false));
    char buffer[64];
    _snprintf(buffer, 64, "0x%08X", GetIsland());
    strings->Add(NiGetViewerString_00a7d5e0("SimIsland", buffer));
}

struct S_00ca09e0_Inner
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    float unk10;
};
struct S_00ca09e0_Shape
{
    void AssignFixedString(char** s);
};
struct S_00ca09e0_Target
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
    virtual void v55(S_00ca09e0_Shape* s, int f);
};
S_00ca09e0_Shape* __cdecl BSTestObjects_CreateSphere(float a, int b, int c, int d);
char* __cdecl FUN_00a5b690(const char* s);
extern char* _EmptyFS;
struct S_00ca09e0_Str
{
    char* p;
    S_00ca09e0_Str(const char* s)
    {
        p = FUN_00a5b690(s);
    }
    ~S_00ca09e0_Str()
    {
        if (p != _EmptyFS)
            InterlockedDecrement((long*)(p - 8));
    }
};
extern float DAT_011b15c8;
struct S_00ca09e0_Obj
{
    int unk0;
    int unk4;
    S_00ca09e0_Inner* unk8;
    void bhkSphereShape_BuildDisplayGeometry(S_00ca09e0_Target* a, int b);
};
// @fnv 0x00ca09e0
// src: XBOX_PDB 0x00ca09e0
void S_00ca09e0_Obj::bhkSphereShape_BuildDisplayGeometry(S_00ca09e0_Target* a, int b)
{
    S_00ca09e0_Shape* s = BSTestObjects_CreateSphere(((this && unk8) ? unk8->unk10 : DAT_010c72bc) * DAT_011b15c8, 10, 10, 0);
    if (s)
    {
        static S_00ca09e0_Str name("bhkSphereShape");
        s->AssignFixedString(&name.p);
        a->v55(s, 1);
    }
}

extern __declspec(thread) int DAT_012722b4;

struct S00ca0900_Guard
{
    int previous;
    S00ca0900_Guard()
    {
        previous = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00ca0900_Guard()
    {
        DAT_012722b4 = previous;
    }
};

struct S00ca0900_Arg
{
    int unk00;
    float unk04;
};

struct S00ca0900_Shape
{
    unsigned int unk00;
    unsigned short m_usMemSizeAndFlags;
    static void* operator new(unsigned int size)
    {
        Pool* pool = hkMemoryRouter_getInstance();
        S00ca0900_Shape* p = (S00ca0900_Shape*)pool->allocator->Allocate(0x20);
        p->m_usMemSizeAndFlags = 0x20;
        return p;
    }
    static void operator delete(void*);
    S00ca0900_Shape(float radius);
};

extern "C" void __fastcall FUN_00c905b0(FUN_00cf2cb0*);

struct S00ca0900_cls
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
    virtual void SetShape(S00ca0900_Shape* shape);
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
    virtual void Finish(S00ca0900_Arg* arg);
    void bhkSphereShape_Init_00ca0900(S00ca0900_Arg* arg);
};

// @fnv 0x00ca0900
// src: XBOX_PDB 0x00ca0900
void S00ca0900_cls::bhkSphereShape_Init_00ca0900(S00ca0900_Arg* arg)
{
    S00ca0900_Guard guard;
    S00ca0900_Shape* shape = new S00ca0900_Shape(arg->unk04);
    SetShape(shape);
    FUN_00c905b0((FUN_00cf2cb0*)shape);
    Finish(arg);
}

namespace fnv_00cb3b20 {
extern __declspec(thread) unsigned int tlsMode;
extern void* DAT_012683c8;
extern const char str_010c88a8[];
extern const char str_010c889c[];
void* NiViewerStrings_NiGetViewerString_Title(void*);
struct OutputList
{
    void* field_00;
    void* field_04;
    unsigned short capacity_08, count_0a, field_0c, growth_0e;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, void**);
    void append(void* value)
    {
        unsigned int index = count_0a;
        if (index >= capacity_08)
            FUN_0096ad30(index + growth_0e);
        FUN_0096ae90(index, &value);
    }
};
struct RotationValue
{
    float w, x, y, z;
    void* FUN_00a6e190(const char*);
};
struct PositionValue
{
    float x, y, z;
    void* GetViewerString_00a59af0(const char*);
};
void FUN_00458620(PositionValue*, const void*);
struct ModeScope
{
    unsigned int saved;
    ModeScope() : saved(tlsMode)
    {
        tlsMode = 16;
    }
    ~ModeScope()
    {
        tlsMode = saved;
    }
};
struct Target
{
    enum
    {
        RotationOffset = 0x20,
        PositionOffset = 0x30
    };
    void bhkRigidBody_GetViewerStrings(OutputList*);
    void bhkRigidBodyT_GetViewerStrings(OutputList*);
};
// @fnv 0x00cb3b20
// src: XBOX_PDB 0x00cb3b20
void Target::bhkRigidBodyT_GetViewerStrings(OutputList* out)
{
    ModeScope scope;
    bhkRigidBody_GetViewerStrings(out);
    out->append(NiViewerStrings_NiGetViewerString_Title(DAT_012683c8));
    const float* rotation = reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + RotationOffset);
    RotationValue value;
    value.x = rotation[0];
    value.y = rotation[1];
    value.z = rotation[2];
    value.w = rotation[3];
    PositionValue position;
    FUN_00458620(&position, reinterpret_cast<const char*>(this) + PositionOffset);
    out->append(value.FUN_00a6e190(str_010c88a8));
    out->append(position.GetViewerString_00a59af0(str_010c889c));
}
}  // namespace fnv_00cb3b20

struct B00c9fde0
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    B00c9fde0();
};
// @fnv 0x00c9fe30
// src: COMMUNITY 0x00c9fe30
B00c9fde0* __cdecl bhkBoxShape_CreateObject()
{
    return new B00c9fde0;
}

struct S00cb39d0_S_00aa3e40
{
    void* __thiscall Game_DoHeapAlloc(int size);
};

struct S00cb39d0_S_00cb3860
{
    S00cb39d0_S_00cb3860();
};

void* __cdecl operator new(unsigned int size, S00cb39d0_S_00aa3e40& manager, unsigned int allocationSize)
{
    unsigned char* ptr = static_cast<unsigned char*>(manager.Game_DoHeapAlloc(allocationSize));
    unsigned int address = reinterpret_cast<unsigned int>(ptr);
    unsigned char alignment = static_cast<unsigned char>(0x10 - (address & 0x0f));
    ptr += alignment;
    ptr[-1] = alignment;
    return ptr;
}

void __cdecl operator delete(void* ptr, S00cb39d0_S_00aa3e40& manager, unsigned int allocationSize)
{}

// @fnv 0x00cb39d0
// src: EXE 0x00cb39d0
void __cdecl bhkRigidBodyT_CreateObject(void* arg0, void* arg1, void* arg2, void* arg3)
{
    new (*(S00cb39d0_S_00aa3e40*)&DAT_011f6238, 0x50) S00cb39d0_S_00cb3860();
}

struct ShapeViewerFields
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int collisionFlags;

    unsigned int Layer() const
    {
        return collisionFlags & 0x1f;
    }
    void bhkShape_GetViewerStrings(BCA05B0StringArray* output);
};

extern const char DAT_010c59cc[];
extern "C" const char* DAT_01268100;
char* __cdecl NiGetViewerString_00a7d4d0(const char*, unsigned int);

// @fnv 0x00c851c0
// src: XBOX_PDB 0x00c851c0
void ShapeViewerFields::bhkShape_GetViewerStrings(BCA05B0StringArray* output)
{
    TlsGuard_ca0090 context;
    DebugStrArray* strings = reinterpret_cast<DebugStrArray*>(output);
    typedef void (__thiscall* AppendStrings)(bhkRefObject*, DebugStrArray*);
    ((AppendStrings)AppendHavokViewerStrings)((bhkRefObject*)this, strings);
    strings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_01268100));
    strings->Add(NiGetViewerString_00a7d4d0(DAT_010c59cc, reinterpret_cast<ShapeViewerFields*>(this)->Layer()));
}

struct Q00c9fde0
{
    void* m_pVtable;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    Q00c9fde0();
};
struct C9FFD0Owner
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
    virtual void vf22();
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
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49(Q00c9fde0* object, unsigned int argument);
    Q00c9fde0* bhkBoxShape_CreateClone(unsigned int argument);
};
// @fnv 0x00c9ffd0
// src: XBOX_PDB 0x00c9ffd0
Q00c9fde0* C9FFD0Owner::bhkBoxShape_CreateClone(unsigned int argument)
{
    TlsGuard_t guard;
    bhkSerializable_CloneCritLock();
    Q00c9fde0* object = new Q00c9fde0;
    vf49(object, argument);
    bhkSerializable_CloneCritUnlock();
    return object;
}
