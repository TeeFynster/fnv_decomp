#include "../../include/NiTArray.h"

// src/bshavok/bhkcollisionobject_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bshavok/bhkcollisionobject_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "bhkcollisionobject_decls.h"
#include "../../include/WeaponObject.h"
#include "../../include/BSFadeNode.h"
#include "../../include/Mat3.h"
#include "../../include/NiPoint3.h"
#include "../../include/hkVector4.h"

// @fnv 0x0056d5b0
const NiRTTI* bhkCollisionObject::GetRTTI() const
{
    return &ms_kRTTI;
}

// @fnv 0x0043b610
bhkCollisionObject* bhkCollisionObject::GetFromNiAVObject(NiAVObject* object)
{
    const char* collision = reinterpret_cast<BGSBodyPart*>(object)->GetPartName();
    return reinterpret_cast<bhkCollisionObject*>(
        DynamicCastByRTTI(const_cast<NiRTTI*>(&ms_kRTTI), reinterpret_cast<NiNode*>(const_cast<char*>(collision))));
}

// @fnv 0x004b5a20
bhkCollisionObject* bhkCollisionObject::GetFromRigidBody(const hkpRigidBody* body)
{
    NiAVObject* collision = NiShader::DynamicCast(reinterpret_cast<NiAVObject*>(const_cast<hkpRigidBody*>(body)));
    return reinterpret_cast<bhkCollisionObject*>(
        DynamicCastByRTTI(const_cast<NiRTTI*>(&ms_kRTTI), reinterpret_cast<NiNode*>(collision)));
}

void* __fastcall NiRTTI_UpdateState_00c6b910(void*);
extern int DAT_0103046c;
struct MyType
{
    // This collision object shares the allocator, not the BSFadeNode layout.
    static void* __cdecl operator new(unsigned int size)
    {
        return BSFadeNode::operator new(size);
    }
    char d[0x14];
    MyType()
    {
        NiRTTI_UpdateState_00c6b910(this);
        *(void**)this = (void*)&DAT_0103046c;
    }
};
// @fnv 0x00c65830
// src: EXE 0x00c65830
void* bhkCollisionObject_CreateObject()
{
    return new MyType;
}

void __cdecl SetNiPoint3FromHkVector4(void*, hkVector4 const&);
extern int _NiPoint3_ZERO;
extern int DAT_011f4270;
extern int DAT_011f4274;
extern float DAT_01267e30;
// @fnv 0x00c65ef0
void* WeaponObject::GetTranslation(void* a1)
{
    void* p = *(void**)((char*)this + 0x10);
    if (p)
    {
        void* q = *(void**)((char*)p + 8);
        const hkVector4* r;
        if (q)
            r = (const hkVector4*)((char*)q + 0x1B0);
        else
            r = (const hkVector4*)&DAT_01267e30;
        SetNiPoint3FromHkVector4(a1, *r);
        return a1;
    }
    ((int*)a1)[0] = _NiPoint3_ZERO;
    ((int*)a1)[1] = DAT_011f4270;
    ((int*)a1)[2] = DAT_011f4274;
    return a1;
}

struct AudioTlsState
{
    char pad[0x2b4];
    int m_uiMemoryContext;
};

extern __declspec(thread) AudioTlsState g_threadData;

struct ScopedMemoryContext
{
    int oldVal;
    ScopedMemoryContext(int newVal)
    {
        oldVal = g_threadData.m_uiMemoryContext;
        g_threadData.m_uiMemoryContext = newVal;
    }
    ~ScopedMemoryContext()
    {
        g_threadData.m_uiMemoryContext = oldVal;
    }
};

struct FUN_00c659d0_shell : bhkCollisionObject
{
    void bhkNiCollisionObject_CopyMembers(MyType*, void*);
    MyType* bhkCollisionObject_CreateClone(void* param);
};

// @fnv 0x00c659d0
// src: XBOX_PDB 0x00c659d0
MyType* FUN_00c659d0_shell::bhkCollisionObject_CreateClone(void* param)
{
    ScopedMemoryContext scope(0x10);
    MyType* obj = new MyType;
    bhkNiCollisionObject_CopyMembers(obj, param);
    return obj;
}

struct FUN_00c65890_Tgt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_flags;
};

struct FUN_00c65890_Callee
{
    void Tail();
};

struct FUN_00c65890_cls
{
    int unk00;
    int unk04;
    FUN_00c65890_Callee* m_08;
    int unk0c;
    FUN_00c65890_Tgt* m_10;
    void bhkCollisionObject_UpdateWorldData(int param);
    void UpdateState(int param);
};

// @fnv 0x00c65890
// src: XBOX_PDB 0x00c65890
void FUN_00c65890_cls::bhkCollisionObject_UpdateWorldData(int param)
{
    FUN_00c65890_Tgt* tgt = m_10;
    if (tgt != 0)
    {
        unsigned int flags = tgt->m_flags;
        flags >>= 6;
        if (((unsigned char)flags & 1) != 0)
        {
            FUN_00c65890_Callee* p = m_08;
            if (p != 0)
            {
                p->Tail();
            }
            return;
        }
    }
    UpdateState(param);
}

struct CollisionNode
{
    int unk00;
    int unk04;
    unsigned char* status;
};
struct CollisionState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    CollisionNode* node;
    bool bhkCollisionObject_QKeyframe();
};
// @fnv 0x00c659a0
// src: XBOX_PDB 0x00c659a0
bool CollisionState::bhkCollisionObject_QKeyframe()
{
    if (node)
    {
        unsigned char* status = node->status;
        unsigned int kind = status ? status[0xE8] : 4;
        return kind == 4 || kind == 5;
    }
    return false;
}

struct SpinLock_c65f40
{
    int owner;
    int count;
    void Lock(const char* name);
    void Unlock()
    {
        if (--count == 0)
            owner = 0;
    }
};
extern SpinLock_c65f40 g_lock_c65f40;

char __cdecl bhkRigidBody_IsMotionTypeDynamic(int* type);

inline bool Check(int t)
{
    return bhkRigidBody_IsMotionTypeDynamic(&t) != 0;
}

struct WorldObj_c65f40
{
    void Update();
};

struct HkObj_c65f40
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
    unsigned char motionType;
};

struct RTTI_c65f40;
extern RTTI_c65f40 rtti_c65f40;

struct RigidBody_c65f40
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    int unk04;
    HkObj_c65f40* hkObj;
    int GetType();
    void Refresh();
    virtual bool SetMotion(int type);
};

struct NiObj_c65f40
{
    RigidBody_c65f40* Cast(const RTTI_c65f40* rtti);
};

struct ColObj_c65f40
{
    void* vtbl;
    int unk04;
    int unk08;
    unsigned short flags;
    short unk0E;
    RigidBody_c65f40* body;
    void bhkCollisionObject_SetMotionType(int type, NiObj_c65f40* obj, bool update);
};

// @fnv 0x00c65f40
// src: XBOX_PDB 0x00c65f40
void ColObj_c65f40::bhkCollisionObject_SetMotionType(int type, NiObj_c65f40* obj, bool update)
{
    RigidBody_c65f40* rb;
    int t;
    if (!obj || (rb = obj->Cast(&rtti_c65f40)) == 0)
    {
        rb = body;
        if (!rb)
            return;
    }
    int cur = rb->hkObj ? rb->hkObj->motionType : 5;
    if (cur == type)
        return;
    if (type == 1 && bhkRigidBody_IsMotionTypeDynamic(&cur))
        return;
    g_lock_c65f40.Lock(0);
    bool ok = rb->SetMotion(type);
    g_lock_c65f40.Unlock();
    if (!ok)
        return;
    if (Check(rb->hkObj ? rb->hkObj->motionType : 5))
        flags |= 8;
    else
        flags &= ~8;
    if (update)
    {
        t = rb->GetType();
        if (bhkRigidBody_IsMotionTypeDynamic(&t))
        {
            WorldObj_c65f40* w = (WorldObj_c65f40*)rb->hkObj;
            if (w)
            {
                rb->Refresh();
                w->Update();
                rb->Refresh();
            }
        }
    }
}

struct TlsBlock
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
    int m_uiMemoryContext;
};
extern __declspec(thread) TlsBlock g_tlsBlock;

struct MemContextGuard
{
    int oldVal;
    MemContextGuard(int newVal)
    {
        oldVal = g_tlsBlock.m_uiMemoryContext;
        g_tlsBlock.m_uiMemoryContext = newVal;
    }
    ~MemContextGuard()
    {
        g_tlsBlock.m_uiMemoryContext = oldVal;
    }
};

template <class T, class A> inline unsigned int NiTArray<T, A>::Add(const T& element)
{
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
typedef NiTArray<char*, NiTMallocInterface<char*> > ViewerStrings;

struct RttiStub
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};
extern RttiStub g_collisionRtti;

char* __cdecl NiGetViewerStringA(const char* pcName);
char* __cdecl NiGetViewerStringB(const char* pcName, bool bValue);

class CollisionParent
{
  public:
    void ParentViewerStrings(ViewerStrings* apViewerStrings);
};

class CollisionObj : public CollisionParent
{
  public:
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    bool GetUseVel() const
    {
        return (m_usFlags & 0x20) && !(bool)((m_usFlags >> 6) & 1);
    }
    void bhkCollisionObject_AddViewerStrings(ViewerStrings* apViewerStrings);
};

// @fnv 0x00c66060
// src: XBOX_PDB 0x00c66060
void CollisionObj::bhkCollisionObject_AddViewerStrings(ViewerStrings* apViewerStrings)
{
    MemContextGuard guard(0x10);
    ParentViewerStrings(apViewerStrings);
    apViewerStrings->Add(NiGetViewerStringA(g_collisionRtti.GetName()));
    apViewerStrings->Add(NiGetViewerStringB("bUseVel", GetUseVel()));
}

struct Xform
{
    Mat3 m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
struct Quat
{
    float w, x, y, z;
    void NiQuaternion_ToRotation(Mat3& a1) const;
};
struct HkEntity
{
    int unk00;
    int unk04;
    int* unk08;
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
    unsigned char unkE8;
};

struct SceneObj
{
    void FUN_00a68bf0();
};

struct BhkBody
{
    int unk00;
    int unk04;
    HkEntity* pNode08;
    void bhkRigidBody_GetRotation(Quat& a1);
    void bhkRigidBody_GetPosition(NiPoint3& a1);
};

struct CollObj
{
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46(const Xform& a1);
    int unk04;
    SceneObj* pObj08;
    int unk0C;
    BhkBody* pBody10;
    void bhkCollisionObject_hktoNiTransform();
};

// @fnv 0x00c65a80
// src: XBOX_PDB 0x00c65a80
void CollObj::bhkCollisionObject_hktoNiTransform()
{
    BhkBody* pBody = pBody10;
    if (pBody == 0)
        return;
    HkEntity* pNode = pBody->pNode08;
    if (pNode == 0)
        return;
    if (pNode->unkE8 == 5 && pNode->unk08 != 0)
    {
        if (pObj08 != 0)
            pObj08->FUN_00a68bf0();
        return;
    }
    Quat q;
    // The body getters fill the transform without calling Mat3/NiPoint3 constructors.
    void* transformStorage[sizeof(Xform) / sizeof(void*)];
    Xform& t = *reinterpret_cast<Xform*>(transformStorage);
    pBody->bhkRigidBody_GetRotation(q);
    q.NiQuaternion_ToRotation(t.m_kOrientation);
    pBody->bhkRigidBody_GetPosition(t.m_kTranslation);
    s46(t);
}
