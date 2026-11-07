#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../include/hkAabb.h"
#include "../../include/NiNode.h"
#include "../../include/StrArr.h"
#include "../../include/hkVector4.h"
#include "../../include/bhkRefObject.h"
#include "../../include/bhkRigidBody.h"
#include "../../include/hkVector4.h"
#include "../../include/NiBound.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiStream.h"
#include "../../include/NiTPrimitiveArray.h"
#include "../../include/NiTransform.h"
#include "../../include/NiObject.h"
#include "../../include/NiRefObject.h"
#include "../../include/NiBinaryStream.h"
#include "../../include/NiPointer.h"
#include "../../include/NiTPointerList.h"
#include "../../include/NiTListItem.h"
#include "../../include/hkTransform.h"
#include "../../include/hkAabb.h"
#include "../../include/hkpShape.h"
#include "../../include/hkpCdBody.h"

inline const NiRTTI* NiRTTI::GetBaseRTTI() const { return m_pBaseRTTI; }

inline const hkpShape* hkpCdBody::getShape() const { return m_pCollisionShape; }

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Calls FUN_00c859e0, reads a count from the stream, then reads that many NiObjects and passes each non-null one to FUN_00c8ef80.
// @fnv 0x00c8f3c0
// src: XBOX_PDB 0x00c8f3c0
void bhkRigidBody::LinkObject_00c8f3c0(NiStream* stream)
{
    bhkWorldObject_LinkObject(stream);
    unsigned int count = stream->GetLinkID();
    for (unsigned int i = 0; i < count; ++i)
    {
        NiObject* obj = stream->GetLoadedObject();
        if (obj)
            bhkRigidBody_AddActCon(obj);
    }
}

char* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);

// Appends the MOTION type name string matching type (DYNAMIC, SPHERE, BOX, KEYFRAMED, FIXED, THIN BOX, else INVALID) to arr.
// @fnv 0x00c8ee20
void __cdecl AddMotionTypeName(StrArr* arr, int type)
{
    char* s;
    switch (type)
    {
    case 1:
        s = NiGetViewerString_00a7d5e0("MOTION", "DYNAMIC");
        ((NiTPrimitiveArray<unsigned int>*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 2:
        s = NiGetViewerString_00a7d5e0("MOTION", "SPHERE");
        ((NiTPrimitiveArray<unsigned int>*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 3:
        s = NiGetViewerString_00a7d5e0("MOTION", "BOX");
        ((NiTPrimitiveArray<unsigned int>*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 4:
        s = NiGetViewerString_00a7d5e0("MOTION", "KEYFRAMED");
        ((NiTPrimitiveArray<unsigned int>*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 5:
        s = NiGetViewerString_00a7d5e0("MOTION", "FIXED");
        ((NiTPrimitiveArray<unsigned int>*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    case 6:
        s = NiGetViewerString_00a7d5e0("MOTION", "THIN BOX");
        ((NiTPrimitiveArray<unsigned int>*)arr)->AddFirstEmpty((unsigned int&)s);
        break;
    default:
        s = NiGetViewerString_00a7d5e0("MOTION", "INVALID");
        {
            unsigned int i = arr->m_usSize;
            if (i >= arr->m_usMaxSize)
                arr->SetSize(i + arr->m_usGrowBy);
            arr->SetAt(i, s);
        }
        break;
    }
}

// @fnv 0x00c8eb00
// src: XBOX_PDB 0x00c8eb00
void __thiscall bhkRigidBody::Remove_00c8eb00()
{
    iFlags &= 0xffffff77;
    ProcessListNodes();
    bhkEntity_Remove();
}

struct LinkedRecord
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct RigidLinkSource
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual LinkedRecord* GetLinkedRecord();

    unsigned int unk04;
    LinkedRecord* unk08;

    unsigned int GetLinkedRecordValue();
};

// Returns unk08 of the record from GetLinkedRecord when unk08 and its unk08 are set, otherwise 0.
// @fnv 0x00c89a00
unsigned int RigidLinkSource::GetLinkedRecordValue()
{
    unsigned int result = 0;
    if (unk08 && unk08->unk08)
    {
        LinkedRecord* record = GetLinkedRecord();
        if (record)
            result = record->unk08;
    }
    return result;
}

struct S_00c8d440_Arg
{
    bool unk00;
    S_00c8d440_Arg(bool b)
    {
        unk00 = b;
    }
    S_00c8d440_Arg(const S_00c8d440_Arg& o)
    {
        unk00 = o.unk00;
    }
};

struct S_00c8d440_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned int id, S_00c8d440_Arg arg);
};

extern S_00c8d440_Target* DAT_01268360;

// @fnv 0x00c8d440
// src: XBOX_PDB 0x00c8d440
void __stdcall bhkRigidBody_SetHavokAssertState(bool flag)
{
    S_00c8d440_Target* t = DAT_01268360;
    t->v4(0xf043d534, S_00c8d440_Arg(flag));
    t->v4(0xf02e32e1, S_00c8d440_Arg(flag));
    t->v4(0xf02e32e2, S_00c8d440_Arg(flag));
    t->v4(0xf02132df, S_00c8d440_Arg(flag));
}

struct NativeData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float factor18, factor1c;
    unsigned int unk20;
    void* lastUpdate;
    int count;
};
struct NativeThing
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
    virtual NativeData* GetData();
    unsigned int unk04;
    void* world;
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
    unsigned char motionType;
};
extern NiRTTI DAT_01267b70;
struct NativeLink
{
    NativeThing* object;
    unsigned int category;
};
NativeLink* bhkWorldObject_GetProperty(NativeLink*, NativeThing*, const NiRTTI*);
extern unsigned char DAT_011afe59;
struct BodyUpdate
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void Reset();
    unsigned int unk04;
    NativeThing* native;
    unsigned int unk0c;
    unsigned int flags;
    unsigned char IsDisabled() const
    {
        return (flags >> 6) & 1;
    }
    bool bhkWorldObject_Add(void*);
    void Object_DoNothing();
    void UpdateMatchingNodes(void*);
    void* bhkWorldObject_GethkWorld();
    bool InWorld()
    {
        NativeThing* body = native;
        if (!body)
            return false;
        Object_DoNothing();
        bool inWorld = body->world != 0;
        Object_DoNothing();
        return inWorld;
    }
    int MotionType() const
    {
        return native ? native->motionType : 0;
    }
    bool IsMoving() const
    {
        int motion = MotionType();
        return motion > 0 && (motion <= 3 || motion == 6);
    }
    bool UpdateBody(void*);
};
// @fnv 0x00c8db50
bool BodyUpdate::UpdateBody(void* update)
{
    NativeLink link;
    NativeThing* object = bhkWorldObject_GetProperty(&link, this ? native : 0, &DAT_01267b70)->object;
    NativeData* data = object ? object->GetData() : 0;
    bool bUnitScale = data && data->factor18 == 1.0f && data->factor1c == 1.0f;
    if ((!bUnitScale || data->count > 0 || DAT_011afe59) && !IsDisabled())
    {
        bool result = bhkWorldObject_Add(update);
        if (result || (InWorld() && IsMoving()))
        {
            if ((!bUnitScale || data->count > 0) && !IsDisabled())
                UpdateMatchingNodes(update);
        }
        if (data)
            data->lastUpdate = update;
        return result;
    }
    else
    {
        if (bhkWorldObject_GethkWorld())
            Reset();
        if (data)
            data->lastUpdate = update;
        return true;
    }
}

namespace fnv_00c8dcb0 {
struct S_c8dcb0_Res
{
    struct S_c8dcb0_Obj* p;
    int hi;
};
struct S_c8dcb0_Obj
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
    virtual S_c8dcb0_Obj* v15();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24;
};
extern int DAT_01267b70;
S_c8dcb0_Res* __cdecl bhkWorldObject_GetProperty(S_c8dcb0_Res*, int, int*);
struct S_c8dcb0_Base
{
    int unk00;
    int unk04;
    int unk08;
    bool bhkWorldObject_Add(int a);
    void UpdateMatchingNodes(int a);
    bool bhkRigidBody_ForceAdd(int a);
};
// Calls FUN_00c85810(a); if true calls UpdateMatchingNodes(a), then looks up an object by unk08 and sets its unk24 to a via v15().
// @fnv 0x00c8dcb0
// src: XBOX_PDB 0x00c8dcb0
bool S_c8dcb0_Base::bhkRigidBody_ForceAdd(int aiValue)
{
    bool r = bhkWorldObject_Add(aiValue);
    if (r)
        UpdateMatchingNodes(aiValue);
    int key = this ? unk08 : 0;
    S_c8dcb0_Res res;
    S_c8dcb0_Obj* o = bhkWorldObject_GetProperty(&res, key, &DAT_01267b70)->p;
    if (o)
    {
        S_c8dcb0_Obj* t = o->v15();
        if (t)
            t->unk24 = aiValue;
    }
    return r;
}
}  // namespace fnv_00c8dcb0

// src: XBOX_PDB 0x00c8cce0
bool __cdecl bhkRigidBody_IsMotionTypeDynamic(int* type)
{
    bool result = false;
    if (*type > 0 && (*type <= 3 || *type == 6))
        result = true;
    return result;
}

union C8Flags
{
    unsigned int raw;
    struct
    {
        unsigned int type : 7;
        unsigned int rest : 25;
    };
};

struct C8Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C8Flags flags;
};

struct C8Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8Base base;
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
    unsigned char state;
    void Setup(int, bool, int);
};

struct C8Owner
{
    int unk00;
    int unk04;
    C8Obj* obj;
    void Toggle();
    void Apply(C8Flags);
    float GetValue();
    bool SetState(int state);
};

static inline bool IsSpecial(unsigned int t)
{
    return t == 8 || t == 0x1d;
}

// @fnv 0x00c8dd10
bool C8Owner::SetState(int state)
{
    bool result = false;
    C8Obj* o = obj;
    if (o)
    {
        C8Base* b = &o->base;
        C8Flags flags;
        flags.raw = b ? b->flags.raw : 0;
        int iCurrent = o->state;
        if (IsSpecial(flags.type))
        {
            C8Flags newFlags = flags;
            bool hit = bhkRigidBody_IsMotionTypeDynamic(&state);
            newFlags.type = hit ? 0x1d : 8;
            if (state != iCurrent)
            {
                Toggle();
                o->base.flags = newFlags;
                o->Setup(state, true, 0);
                Toggle();
            }
            else
            {
                Apply(newFlags);
            }
            result = true;
        }
        else if (iCurrent != state)
        {
            bool skip = false;
            switch (iCurrent)
            {
            case 4:
            case 5:
                if (bhkRigidBody_IsMotionTypeDynamic(&state) && GetValue() == 0.0f)
                    skip = true;
                break;
            }
            if (!skip)
            {
                Toggle();
                o->Setup(state, true, 0);
                Toggle();
                result = true;
            }
        }
    }
    return result;
}

struct BhkrigidbodyListNodeView;

struct ObjBase
{
    virtual void v00();
    virtual void v04();
    virtual BhkrigidbodyListNodeView* v08();
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
    int Helper1();
    int Helper2();
};

// Exe 0x00c8e770: unit-local ListNode view; declarations and layout are preserved.
struct BhkrigidbodyListNodeView
{
    ObjBase* m_00;
    BhkrigidbodyListNodeView* m_04;
};

extern char DAT_0126818c;
extern char DAT_01268158;

// Walks the m_14 list; for each node with an ObjBase, checks its v08 list for DAT_0126818c/DAT_01268158 and calls Helper1/Helper2, invoking vA0 if nonzero.
// @fnv 0x00c8e770
void bhkRigidBody::ProcessListNodes()
{
    BhkrigidbodyListNodeView* n = reinterpret_cast<BhkrigidbodyListNodeView*>(&m_kSerializableList);
    while (n)
    {
        if (n->m_04 == 0 && n->m_00 == 0)
            return;
        ObjBase* o = n->m_00;
        if (o)
        {
            int r = 0;
            BhkrigidbodyListNodeView* p = o->v08();
            if (p)
            {
                for (; p; p = p->m_04)
                {
                    if (p == (BhkrigidbodyListNodeView*)&DAT_0126818c)
                    {
                        r = o->Helper1();
                        goto L_070;
                    }
                }
            }
            p = o->v08();
            if (p)
            {
                for (; p; p = p->m_04)
                {
                    if (p == (BhkrigidbodyListNodeView*)&DAT_01268158)
                    {
                        r = o->Helper2();
                        goto L_070;
                    }
                }
            }
            goto L_080;
        L_070:
            if (r)
                o->vA0();
        }
    L_080:
        n = n->m_04;
    }
}

class C8EC60Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual const NiRTTI* GetRTTI() const;
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void ResetWorldObject();

    bool IsKindOfType(const NiRTTI& kRTTI) const
    {
        for (const NiRTTI* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }
};

class C8EC60Constraint : public C8EC60Object
{
  public:
    static const NiRTTI ms_kRTTI;

    void* GetConstraint();
};

class C8EC60RefObject : public C8EC60Object
{
  public:
    static const NiRTTI ms_kRTTI;

    void* GetReferencedData();
};

class C8EC60Iterator
{
  public:
    C8EC60Object* m_pkCurrent;

    void Next();
};

class C8EC60World
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C8EC60Iterator m_kIterator;

    C8EC60Iterator* GetIterator()
    {
        return &m_kIterator;
    }
    void bhkRigidBody_RemoveActionConstraints();
};

// Iterates the world's objects and calls ResetWorldObject on constraints and ref objects that hold a non-null constraint or referenced data.
// @fnv 0x00c8ec60
// src: COMMUNITY 0x00c8ec60
void C8EC60World::bhkRigidBody_RemoveActionConstraints()
{
    C8EC60Iterator* pkIter = GetIterator();
    while (pkIter && pkIter->m_pkCurrent)
    {
        C8EC60Object* pkObject = pkIter->m_pkCurrent;
        if (pkObject->IsKindOfType(C8EC60Constraint::ms_kRTTI))
        {
            if (static_cast<C8EC60Constraint*>(pkObject)->GetConstraint())
                pkObject->ResetWorldObject();
        }
        else if (pkObject->IsKindOfType(C8EC60RefObject::ms_kRTTI))
        {
            if (static_cast<C8EC60RefObject*>(pkObject)->GetReferencedData())
                pkObject->ResetWorldObject();
        }
        pkIter->Next();
    }
}

extern int DAT_0126810c;
extern int DAT_012681fc;
extern int DAT_012681bc;

void* __cdecl Object_DispatchCommandFour(unsigned int size);

struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
};

struct Pair8
{
    unsigned int a;
    unsigned int b;
    Pair8()
    {
        a = 0;
        b = 0;
    }
};

struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    Pair8 m_0c;
    ChainA_cls()
    {
        DAT_0126810c += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012681fc += 1;
    }
};

struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    unsigned int m_14;
    unsigned int m_18;
    SpawnedObject()
    {
        m_14 = 0;
        m_18 = 0;
        DAT_012681bc += 1;
    }
};

// Allocates and constructs a new SpawnedObject, incrementing the three global counters in its constructors, and returns it.
// @fnv 0x00c8ed70
// src: EXE 0x00c8ed70
SpawnedObject* __cdecl bhkRigidBody_CreateObject()
{
    return new SpawnedObject();
}

struct HavokShape
{
    void bhkRigidBody_Fix();
    void bhkRigidBody_UnFix(void* context);
};
struct HavokLookup
{
    void* ReportDiagnostic;
    void* unused4;
    void* unused8;
    void* unusedC;
    HavokShape* shape;
};
struct HavokProperty
{
    HavokLookup* FUN_00653290(const void* key);
};
struct HavokObject
{
    virtual void Virt0();
    virtual void Virt1();
    virtual void Virt2();
    virtual NiNode* GetCellChildAt();

    unsigned int referenceCount;
    void* extraData;
    void* userData;
    void* collisionData;
    void* owner;
    void* source;
    HavokProperty* property;

    void FUN_00a68bf0();
};

extern char DAT_012043f8;
// @fnv 0x00c8f210
void __cdecl ApplyHavokOperation(HavokObject* object, int operation, void* context)
{
    if (object != 0)
    {
        object->FUN_00a68bf0();
        HavokProperty* property = object->property;
        if (property != 0)
        {
            HavokLookup* lookup = property->FUN_00653290(&DAT_012043f8);
            if (lookup != 0 && lookup->shape != 0)
            {
                if ((char)operation)
                    lookup->shape->bhkRigidBody_Fix();
                else
                    lookup->shape->bhkRigidBody_UnFix(context);
            }
        }
        NiNode* node = object->GetCellChildAt();
        if (node)
        {
            for (unsigned int index = 0; index < node->m_kChildren.m_usSize; ++index)
                ApplyHavokOperation(((HavokObject**)node->m_kChildren.m_pBase)[index], operation, context);
        }
    }
}

struct CloningProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float scale;
};

struct CloneNode
{
    NiObject* data;
    CloneNode* next;
};

struct hkWorldObjSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int flags;
};

struct hkWorldObjStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkWorldObjSub sub;
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
    hkWorldObjSub* GetSub()
    {
        return this ? &sub : 0;
    }
};
static inline unsigned int GetWFlags(hkWorldObjStub* w)
{
    hkWorldObjSub* s = w ? &w->sub : 0;
    return s ? s->flags : 0;
}
static inline bool WFlag13(hkWorldObjStub* w)
{
    return (GetWFlags(w) >> 13) & 1;
}

struct ScaledBody
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
    float m70[12];
    float vA0[4];
    float fB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    char unkD4;
    void Scale(float s);
};

__declspec(noinline) void ScaledBody::Scale(float s)
{
    float s2 = s * s;
    this->vA0[0] *= s;
    this->vA0[1] *= s;
    this->vA0[2] *= s;
    this->vA0[3] *= s;
    float* p = m70;
    for (int i = 0; i < 3; i++)
    {
        p[0] *= s2;
        p[4] *= s2;
        p[8] *= s2;
        p++;
    }
    this->fB0 *= s;
}

struct RigidBodyS
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual void VB0();
    virtual ScaledBody* GetBodyStub(bool* out);
    virtual void VB8();
    virtual void VBC();
    virtual void VC0();
    virtual void UpdateStub();
    int unk04;
    hkWorldObjStub* unk08;
    int unk0C;
    unsigned int unk10;
    CloneNode list;

    void BaseCopyMembers(RigidBodyS* dest, CloningProcess* c);
    void LockStub();
    unsigned int GetFlagsW()
    {
        return GetWFlags(unk08);
    }
    unsigned int GetFlagsWith(unsigned int bit)
    {
        unsigned int f = GetFlagsW() | bit;
        return f;
    }
    void SetFlagsW(unsigned int f)
    {
        hkWorldObjStub* w = unk08;
        if (!w)
            return;
        LockStub();
        hkWorldObjSub* s = w->GetSub();
        LockStub();
        if (s)
            s->flags = f;
    }
    bool Flag9() const
    {
        return (unk10 >> 9) & 1;
    }
    void AddClonedStub(NiObject*);
    void CopyBodyToClone(RigidBodyS* dest, CloningProcess* c);
};

// Copies body members into dest, scales the body stub when c->scale != 1, sets unk28 from unk08->unk210, and clones list nodes into dest.
// @fnv 0x00c8f2a0
void RigidBodyS::CopyBodyToClone(RigidBodyS* dest, CloningProcess* c)
{
    bool b;
    ScaledBody* body = GetBodyStub(&b);
    if (Flag9())
        body->unkD4 = 1;
    float s = c->scale;
    if (s != 1.0f)
        body->Scale(s);
    body->unk28 = unk08->unk210;
    BaseCopyMembers(dest, c);
    dest->unk10 = (dest->unk10 | unk10) & 0xfffffc07;
    CloneNode* n = &list;
    if (WFlag13(unk08) || c->scale != 1.0f)
    {
        dest->SetFlagsW(dest->GetFlagsWith(0x2000));
        dest->UpdateStub();
    }
    for (; n && n->data; n = n->next)
        reinterpret_cast<bhkRigidBody*>(dest)->bhkRigidBody_AddActCon(n->data->MakeClone(*c));
}

extern __declspec(thread) unsigned int hkThreadMemoryFlags;

struct ThreadFlagsGuard
{
    unsigned int saved;
    ThreadFlagsGuard()
    {
        saved = hkThreadMemoryFlags;
        hkThreadMemoryFlags = 0x10;
    }
    ~ThreadFlagsGuard()
    {
        hkThreadMemoryFlags = saved;
    }
};

void LockWorldStub();
void UnlockWorldStub();

extern unsigned int g_iRefObjectCountA;
extern int g_iSerializableCount;
extern int g_iLiquidActionCount;

// CreateAndAddLiquidAction (0x00c8f400) allocates 0x1c bytes and inlines this constructor chain. The object is a
// bhkRigidBody, not a bhkLiquidAction (0x40): after the out-of-line bhkRefObject ctor 0x00c87c30 it installs the
// bhkWorldObject (0x01030394), bhkEntity (0x010302bc) and bhkRigidBody (0x010301b4) vftables and bumps their instance
// counters (0x0126810c, 0x012681fc, 0x012681bc). Kept local under descriptive names: the shared bhkWorldObject/
// bhkEntity/bhkRigidBody headers have no inline counting constructors.
struct bhkRefObjectBase

{

    virtual ~bhkRefObjectBase();

    int refCount;

    int unk08;

    bhkRefObjectBase();

    static void* operator new(unsigned int size);

    static void operator delete(void* p);

};

struct bhkRefObjectLvl : bhkRefObjectBase

{

    struct LinkPair

    {

        void* unk0C;

        void* unk10;

        LinkPair() : unk0C(0), unk10(0)

        {}

    } links;

    bhkRefObjectLvl()

    {

        ++g_iRefObjectCountA;

    }

};

struct bhkSerializableLvl : bhkRefObjectLvl

{

    bhkSerializableLvl()

    {

        ++g_iSerializableCount;

    }

};

struct bhkRigidBodyInline : bhkSerializableLvl

{

    int unk14;

    int unk18;

    bhkRigidBodyInline()

    {

        unk14 = 0;

        unk18 = 0;

        ++g_iLiquidActionCount;

    }

};

// The shared class has no clone entry point; explicit ECX and an unused EDX preserve its thiscall ABI.
// Creates a rigid-body clone using the inline constructor chain, while locking and unlocking the world.
// @fnv 0x00c8f400
bhkRigidBody* __fastcall CloneRigidBody(bhkRigidBody* source, void*, CloningProcess* process)
{
    ThreadFlagsGuard guard;
    LockWorldStub();
    source->vf63(false);
    bhkRigidBodyInline* action = new bhkRigidBodyInline;
    ((RigidBodyS*)source)->CopyBodyToClone((RigidBodyS*)action, process);
    source->vf63(true);
    UnlockWorldStub();
    return (bhkRigidBody*)action;
}

extern __declspec(thread) int g_tlsMemContext;

struct ScopedMemoryContext
{
    int iOldContext;
    ScopedMemoryContext(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    ~ScopedMemoryContext()
    {
        g_tlsMemContext = iOldContext;
    }
};

struct GlobalObject_004ee810
{
    void BSSimpleList_NiPointer_bhkAction_RemoveAll();
};

struct FUN_00c9d4c0_holder
{
    void bhkEntity_Kill();
};

struct Shell_c8da40 : public FUN_00c9d4c0_holder
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    GlobalObject_004ee810 uTmpnk;

    void bhkRigidBody_Kill();
};

// Switches to memory context 0x10, calls FUN_004ee920 on uTmpnk, then calls FUN_00c9d4c0.
// @fnv 0x00c8da40
// src: XBOX_PDB 0x00c8da40
void Shell_c8da40::bhkRigidBody_Kill()
{
    ScopedMemoryContext kContext(0x10);
    uTmpnk.BSSimpleList_NiPointer_bhkAction_RemoveAll();
    bhkEntity_Kill();
}

extern char DAT_0126818c;
extern char DAT_01268628;
class C8DAC0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual const NiRTTI* GetRTTI() const;
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void Update(void* pvContext);
};
inline bool C8DAC0IsKindOf(const NiRTTI& kRTTI, const C8DAC0Object* pkObject)
{
    if (!pkObject)
        return false;
    for (const NiRTTI* pkRTTI = pkObject->GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
    {
        if (pkRTTI == &kRTTI)
            return true;
    }
    return false;
}
struct C8DAC0Node
{
    C8DAC0Object* m_pPointer;
    C8DAC0Node* m_pkNext;
};
class C8DAC0Owner
{
  public:
    virtual ~C8DAC0Owner();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiValue1;
    C8DAC0Node m_kHead;

    unsigned int GetField(unsigned int uiMask, unsigned int uiPos) const
    {
        return (m_uiValue1 & uiMask) >> uiPos;
    }

    void UpdateMatchingNodes(void* pvContext);
};
// @fnv 0x00c8dac0
void C8DAC0Owner::UpdateMatchingNodes(void* pvContext)
{
    bool bFilterByKind = (bool)(GetField(4, 2) & 1);
    for (C8DAC0Node* pkNode = &m_kHead; pkNode; pkNode = pkNode->m_pkNext)
    {
        if (!pkNode->m_pPointer)
            break;
        bool bMatch = bFilterByKind &&
                      C8DAC0IsKindOf(reinterpret_cast<const NiRTTI&>(DAT_0126818c), pkNode->m_pPointer) &&
                      C8DAC0IsKindOf(reinterpret_cast<const NiRTTI&>(DAT_01268628), pkNode->m_pPointer);
        if (!bFilterByKind || bMatch)
            pkNode->m_pPointer->Update(pvContext);
    }
}

// Define the known helper from the preserved surrounding source.
struct LiquidBase
{
    virtual ~LiquidBase();
    unsigned int refCount, unk08, unk0c, unk10;
};
struct LiquidLink
{
    ~LiquidLink();
};
struct FUN_00c8e9c0 : LiquidBase
{
    LiquidLink link;
    void bhkRigidBody_Kill();
    virtual ~FUN_00c8e9c0();
};
// Destructor that calls FUN_00c8da40 and decrements g_iLiquidActionCount.
// @fnv 0x00c8e9c0
FUN_00c8e9c0::~FUN_00c8e9c0()
{
    bhkRigidBody_Kill();
    --g_iLiquidActionCount;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);
extern __declspec(thread) int g_iAllocTagC8E;
struct AllocTagScopeC8E
{
    int m_iSaved;

    AllocTagScopeC8E(int aiAllocationTag)
    {
        m_iSaved = g_iAllocTagC8E;
        g_iAllocTagC8E = aiAllocationTag;
    }
    ~AllocTagScopeC8E()
    {
        g_iAllocTagC8E = m_iSaved;
    }
};

extern const NiRTTI g_kGeometryRTTIC8E;
extern const NiRTTI g_kNodeRTTIC8E;

NiTListItem<NiPointer<NiObject> >* __cdecl NewListItemC8E(NiObject* pkObject);

template <>
inline __declspec(noinline) void NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiObject> >::AddTail(
    const NiPointer<NiObject>& spRetainedObject)
{
    NiTListItem<NiPointer<NiObject> >* pkItem = NewListItemC8E(spRetainedObject.m_pObject);
    pkItem->m_pkNext = 0;
    pkItem->m_pkPrev = m_pkTail;
    if (m_pkTail)
        m_pkTail->m_pkNext = pkItem;
    else
        m_pkHead = pkItem;
    m_pkTail = pkItem;
    m_kItemCount.m_uiCount++;
}

inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long volatile*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline bool NiObject::IsKindOfType(const NiRTTI* pkType) const
{
    for (const NiRTTI* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->GetBaseRTTI())
    {
        if (pkRTTI == pkType)
            return true;
    }
    return false;
}
template <class T> inline NiPointer<T>::NiPointer(T* pObject) : m_pObject(pObject)
{
    if (m_pObject != 0)
        m_pObject->IncRefCount();
}
template <class T> inline NiPointer<T>::~NiPointer()
{
    if (m_pObject != 0)
        m_pObject->DecRefCount();
}

// 0x00c8ef80 appends to a 12-byte NiTPointerList at +0x14. Keep this owner view:
// bhkRigidBody::m_kSerializableList is an 8-byte BSSimpleList, so that shared member
// cannot represent this function's head/tail/count operations.
class SerializableObjectListOwner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    NiTPointerList<NiPointer<NiObject> > m_kThirdFollowingStreamField;

    void bhkRigidBody_AddActCon(NiObject* pkObject);
};
// Adds pkObject to the object list if it is a geometry or node, using an allocation tag scope of 0x10.
// @fnv 0x00c8ef80
// src: XBOX_PDB 0x00c8ef80
void SerializableObjectListOwner::bhkRigidBody_AddActCon(NiObject* pkObject)
{
    AllocTagScopeC8E kScope(0x10);
    if (pkObject && (pkObject->IsKindOfType(&g_kGeometryRTTIC8E) || pkObject->IsKindOfType(&g_kNodeRTTIC8E)))
        m_kThirdFollowingStreamField.AddTail(pkObject);
}

struct LinkNode
{
    NiRefObject* m_pEntryObject;
    LinkNode* m_pNext;
    void Release();
};

struct LinkNodePool
{
    void Free(LinkNode*);
};
extern LinkNodePool g_linkNodePool;

class FUN_00c88990_cls
{
  public:
    NiRefObject* m_pEntryObject;
    LinkNode* m_pNext;
    void PopAndRelease();
};

// @fnv 0x00c88990
void FUN_00c88990_cls::PopAndRelease()
{
    LinkNode* node = m_pNext;
    if (node != 0)
    {
        m_pNext = node->m_pNext;
        NiRefObject* pOldObject = m_pEntryObject;
        if (pOldObject != node->m_pEntryObject)
        {
            if (pOldObject != 0)
            {
                if (InterlockedDecrement((long volatile*)&pOldObject->m_uiRefCount) == 0)
                    pOldObject->DeleteThis();
            }
            m_pEntryObject = node->m_pEntryObject;
            if (m_pEntryObject != 0)
                InterlockedIncrement((long volatile*)&m_pEntryObject->m_uiRefCount);
        }

        node->m_pNext = 0;
        node->Release();
        g_linkNodePool.Free(node);
    }
    else
    {
        NiRefObject* obj = m_pEntryObject;
        if (obj != 0)
        {
            if (InterlockedDecrement((long volatile*)&obj->m_uiRefCount) == 0)
                obj->DeleteThis();
            m_pEntryObject = 0;
        }
    }
}

// Recursively visits child nodes, calling FUN_00c8ec60 on the linked shape found via FUN_00653290 on each object's property when present.
// @fnv 0x00c8ecf0
// src: COMMUNITY 0x00c8ecf0
void __cdecl bhkRigidBody_RemoveAllActionConstraints(HavokObject* object)
{
    if (!object)
        return;

    if (object->property)
    {
        HavokLookup* link = object->property->FUN_00653290(&DAT_012043f8);
        if (link && link->shape)
            reinterpret_cast<C8EC60World*>(link->shape)->bhkRigidBody_RemoveActionConstraints();
    }

    NiNode* node = object->GetCellChildAt();
    if (node)
    {
        for (unsigned int i = 0; i < node->m_kChildren.m_usSize; ++i)
            bhkRigidBody_RemoveAllActionConstraints(((HavokObject**)node->m_kChildren.m_pBase)[i]);
    }
}

#include <xmmintrin.h>

extern hkVector4 DAT_01267e30;
namespace c8d {
struct Body
{
    char pad[0x170];
    hkVector4 m_kPos;
};
struct Ent
{
    int unk;
    int unkCur;
    Body* m_pPhysicsBody;
    hkVector4 GetCenterOfMassLocal_00c8d200();
};
// Returns the physics body's m_kPos, or the global DAT_01267e30 vector when this or the body pointer is null.
// @fnv 0x00c8d200
// src: XBOX_PDB 0x00c8d200
hkVector4 Ent::GetCenterOfMassLocal_00c8d200()
{
    const hkVector4* p;
    if (this && m_pPhysicsBody)
        p = &m_pPhysicsBody->m_kPos;
    else
        p = &DAT_01267e30;
    return *p;
}
}

inline hkVector4::hkVector4(const hkVector4& o) : m_vComponents(o.m_vComponents) {}
inline void hkVector4::operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; }

extern hkVector4 g_zero;

struct Inner
{
    char pad0[0x140];
    hkVector4 m_vec;
};

struct Outer
{
    char pad0[8];
    Inner* m_pChildAtom;
    hkVector4 GetVec() const;
};

// Returns m_pChildAtom->m_vec when m_pChildAtom is non-null, otherwise returns g_zero.
// @fnv 0x00c8d240
hkVector4 Outer::GetVec() const
{
    const hkVector4* p = (this && m_pChildAtom) ? &m_pChildAtom->m_vec : &g_zero;
    return *p;
}

extern hkTransform DAT_01268370;

struct EntityBase_c8d3
{
    int unk00, unk04, unk08, unk0c;
};

struct Entity_c8d3 : public EntityBase_c8d3, public hkpCdBody
{
};

class WorldObject_c8d3
{
  public:
    int unk00;
    int unk04;
    Entity_c8d3* m_pkEntity;

    void Object_DoNothing();
    void GetAabb(hkAabb& kOut);
};

// Fills kOut from the entity shape's getAabb (global transform DAT_01268370, tolerance 0.001), or a +-0.001 box around zero when there is no shape.
// @fnv 0x00c8d390
void WorldObject_c8d3::GetAabb(hkAabb& kOut)
{
    hkpCdBody* pkBody = 0;
    if (this)
    {
        Entity_c8d3* pkEntity = m_pkEntity;
        if (pkEntity)
        {
            Object_DoNothing();
            pkBody = static_cast<hkpCdBody*>(pkEntity);
            Object_DoNothing();
        }
    }
    const hkpShape* pkShape = pkBody ? pkBody->getShape() : 0;
    if (pkShape)
    {
        pkShape->CalculateAabb(DAT_01268370, 0.001f, kOut);
    }
    else
    {
        kOut.m_kMinimumCorner.m_vComponents = _mm_setr_ps(-0.001f, -0.001f, -0.001f, 0.0f);
        kOut.m_kMaximumCorner.m_vComponents = _mm_setr_ps(0.001f, 0.001f, 0.001f, 0.0f);
    }
}

namespace fnv_00c8d510 {

struct OldCinfo
{
    int m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_uiCollisionFilterData;
    char m_eCollisionResponse;
    char unk29;
    unsigned short m_usProcessContactCallbackDelay;
    int unk2C;
    hkVector4 m_vContactPosition;
    hkVector4 m_rotation;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_inertiaRow0;
    hkVector4 m_inertiaRow1;
    hkVector4 m_inertiaRow2;
    hkVector4 m_kCenterOfMass1;
    float m_fViscosityFriction;
    float m_fLinearDamping;
    float m_fAngularDamping;
    float m_fSlipAngle;
    float m_fElasticity;
    float m_fSurfaceFriction;
    float m_fRestitution;
    float m_fAllowedPenetrationDepth;
    signed char m_bFlag;
    char m_bEnableDeactivation;
    char m_qualityType2;
    signed char m_iAutoRemoveLevel;
};

struct BhkRigidBody
{
    int m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_shape2;
    int m_uiCollisionFilterData;
    int unk28;
    char m_eCollisionResponse;
    char unk2D;
    unsigned short m_usProcessContactCallbackDelay;
    hkVector4 m_vContactPosition;
    hkVector4 m_rotation;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_inertiaRow0;
    hkVector4 m_inertiaRow1;
    hkVector4 m_inertiaRow2;
    hkVector4 m_kCenterOfMass1;
    float m_fViscosityFriction;
    float m_fLinearDamping;
    float m_fAngularDamping;
    float m_fGravityFactor;
    float m_fSlipAngle;
    float m_fElasticity;
    float m_fSurfaceFriction;
    float m_fRestitution;
    float m_fAllowedPenetrationDepth;
    char m_bFlag;
    char m_bRigidBodyFlag;
    char m_bEnableDeactivation;
    char m_iAutoRemoveLevel;

    BhkRigidBody& FromOldCinfo(const OldCinfo& src);
};

// Copies collision and motion fields from src, remapping motion, deactivation, and quality values into BhkRigidBody fields.
// @fnv 0x00c8d510
BhkRigidBody& BhkRigidBody::FromOldCinfo(const OldCinfo& src)
{
    m_fGravityFactor = 1.0f;
    unk28 = 0;
    m_shape2 = m_pCollisionShape = src.m_pCollisionShape;
    m_uiCollisionFilterData = src.m_uiCollisionFilterData;
    m_eCollisionResponse = src.m_eCollisionResponse;
    m_usProcessContactCallbackDelay = src.m_usProcessContactCallbackDelay;
    m_vContactPosition = src.m_vContactPosition;
    m_rotation = src.m_rotation;
    m_kTranslationalVelocity = src.m_kTranslationalVelocity;
    m_kAngularVelocity = src.m_kAngularVelocity;
    m_inertiaRow0 = src.m_inertiaRow0;
    m_inertiaRow1 = src.m_inertiaRow1;
    m_inertiaRow2 = src.m_inertiaRow2;
    m_kCenterOfMass1 = src.m_kCenterOfMass1;
    m_fViscosityFriction = src.m_fViscosityFriction;
    m_fLinearDamping = src.m_fLinearDamping;
    m_fAngularDamping = src.m_fAngularDamping;
    m_fSlipAngle = src.m_fSlipAngle;
    m_fElasticity = src.m_fElasticity;
    m_fSurfaceFriction = src.m_fSurfaceFriction;
    m_fRestitution = src.m_fRestitution;
    m_fAllowedPenetrationDepth = src.m_fAllowedPenetrationDepth;
    unsigned int motion = src.m_bFlag;
    if (motion >= 5)
        motion -= 2;
    else if (motion >= 3)
        motion--;
    m_bFlag = (char)motion;
    m_bRigidBodyFlag = src.m_bEnableDeactivation == 2;
    m_bEnableDeactivation = src.m_qualityType2;
    int quality = src.m_iAutoRemoveLevel;
    if (quality < 3)
        quality--;
    m_iAutoRemoveLevel = (char)quality;
    return *this;
}
}  // namespace fnv_00c8d510

struct BuildSettings
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
    float fB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    float fC4;
    float fC8;
    unsigned int unkCC;
    float fD0;
    signed char motionType, response, quality, solver;
    unsigned char unkD8, unkD9, callback, unkDB;
};
struct FUN_00ca8c90;
struct BodyAllocator
{
    virtual void unused();
    virtual FUN_00ca8c90* Allocate(unsigned int size);
};
struct BodyMemory
{
    unsigned int unk00, unk04, unk08, unk0C;
    BodyAllocator* allocator;
    void* AllocateBody(unsigned int size)
    {
        return allocator->Allocate(size);
    }
};
BodyMemory* hkMemoryRouter_getInstance();
struct FUN_00ca8c90
{
    unsigned int unk00;
    unsigned short allocationSize, references;
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
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    FUN_00ca8c90(void* settings);
    void hkpRigidBody_setMotionType(int motion, int activate, int extra);
    void FUN_00c905b0();
    static void* operator new(unsigned int size)
    {
        FUN_00ca8c90* p = (FUN_00ca8c90*)hkMemoryRouter_getInstance()->AllocateBody(size);
        p->allocationSize = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};
struct BodyMotion
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    unsigned char unk18, unk19, quality;
};
struct BodyNative
{
    unsigned int unk00, unk04, unk08, unk0C;
    BodyMotion motion;
};

extern float DAT_012677bc;
extern float DAT_012677c0;
extern float DAT_011b0c48;
struct BodyBuild
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void SetBody(FUN_00ca8c90* body);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void FinishBuild(BuildSettings* settings);
    unsigned int unk04;
    BodyNative* native;
    void Object_DoNothing();
    void GetAabb(hkAabb* bounds);
    float bhkRigidBody_GethkMaxLinearVelocity();
    BodyMotion* GetMotion()
    {
        BodyNative* p = native;
        if (!p)
            return 0;
        Object_DoNothing();
        BodyMotion* result = p ? &p->motion : 0;
        Object_DoNothing();
        return result;
    }
    void ConfigureBody(BuildSettings* settings);
};
// Clamps BuildSettings fields, allocates a body via operator new, sets motion and solver, adjusts quality from bounds, then calls FinishBuild.
// @fnv 0x00c8d650
void BodyBuild::ConfigureBody(BuildSettings* settings)
{
    ThreadFlagsGuard guard;
    int savedMotion = 8;
    if (settings->fD0 <= 1.1920928955078125e-7f || settings->fD0 > 0.20000000298023224)
        settings->fD0 = 0.15f;
    if (settings->fC8 < 1000.0)
        settings->fC8 = 1000.0f;
    if (settings->fC4 >= 1.9900000095367432)
        settings->fC4 = 1.98f;
    if (settings->fB0 != 0.0f)
    {
        int motion = settings->motionType;
        bool special = motion == 4 || motion == 5;
        if (special)
        {
            savedMotion = motion;
            settings->motionType = 1;
            settings->solver = 4;
        }
        else if (settings->solver == -1)
        {
            settings->solver = 4;
        }
    }
    else if (settings->motionType == 5)
    {
        settings->solver = 0;
    }
    if (settings->quality >= 5 || settings->quality <= 0)
        settings->quality = 2;
    settings->callback = 3;
    settings->unk20 = settings->unk00;
    settings->unk24 = settings->unk04;
    FUN_00ca8c90* body = new FUN_00ca8c90(&settings->unk20);
    if (savedMotion != 8)
    {
        settings->motionType = (signed char)savedMotion;
        body->hkpRigidBody_setMotionType(savedMotion, 1, 0);
    }
    SetBody(body);
    body->FUN_00c905b0();
    int motion = settings->motionType;
    if (motion > 0 && (motion <= 3 || motion == 6) && settings->motionType > 0)
    {
        BodyMotion* nativeMotion = GetMotion();
        if (nativeMotion)
        {
            // Preserve the original aligned SIMD temporary storage.
            __m128 boundsStorage[2];
            GetAabb(reinterpret_cast<hkAabb*>(boundsStorage));
            __m128 extent = _mm_sub_ps(boundsStorage[1], boundsStorage[0]);
            int axis;
            if (extent.m128_f32[0] > extent.m128_f32[1])
                axis = extent.m128_f32[1] > extent.m128_f32[2] ? 2 : 1;
            else
                axis = extent.m128_f32[0] > extent.m128_f32[2] ? 2 : 0;
            if (!(extent.m128_f32[axis] > DAT_012677bc))
            {
                float scale = bhkRigidBody_GethkMaxLinearVelocity();
                scale *= DAT_011b0c48;
                if (!(scale < DAT_012677c0))
                {
                    if (settings->solver == 2)
                    {
                        nativeMotion->quality = 4;
                        settings->solver = 4;
                    }
                }
                else
                {
                    nativeMotion->quality = 2;
                    settings->solver = 2;
                }
            }
            else
            {
                nativeMotion->quality = 2;
                settings->solver = 2;
            }
        }
    }
    FinishBuild(settings);
}

struct Matrix
{
    __m128 columns[4];
};
struct Receiver
{
    void setTransformedPos_00c7f640(Matrix*, const __m128*);
};
struct BodySlot
{
    void* body;
    __forceinline void* getBody()
    {
        if (this)
            return body;
        return 0;
    }
};
struct CollisionOwner
{
    void* vtable;
    void* unk04;
    void* node;
    void Object_DoNothing();
    void DispatchCollision(Receiver*);
    __forceinline BodySlot* GetSlot()
    {
        char* base = (char*)node;
        if (base)
        {
            Object_DoNothing();
            base += 16;
            Object_DoNothing();
            if (base)
                return (BodySlot*)base;
        }
        return 0;
    }
};
extern float DAT_0104ffb8;
extern float DAT_01011d78;
extern float DAT_01017d00;
// Gets a matrix via virtual slot 61, then passes it to the body slot's virtual 7 if present, otherwise to target and target+16 with fixed vectors.
// @fnv 0x00c8e670
void CollisionOwner::DispatchCollision(Receiver* target)
{
    __m128 second, first;
    __declspec(align(16)) Matrix source;
    typedef void(__thiscall * GetSource)(CollisionOwner*, Matrix*);
    ((GetSource)((void**)vtable)[61])(this, &source);
    BodySlot* slot = GetSlot();
    void* body = slot ? slot->getBody() : 0;
    if (body)
    {
        typedef void(__thiscall * Dispatch)(void*, Matrix*, float, Receiver*);
        ((Dispatch)((void**)*(void* volatile*)body)[7])(body, &source, DAT_01017d00, target);
    }
    else
    {
        first = _mm_setr_ps(DAT_0104ffb8, DAT_0104ffb8, DAT_0104ffb8, DAT_01011d78);
        second = _mm_setr_ps(DAT_01017d00, DAT_01017d00, DAT_01017d00, DAT_01011d78);
        target->setTransformedPos_00c7f640(&source, &first);
        ((Receiver*)((char*)target + 16))->setTransformedPos_00c7f640(&source, &second);
    }
}

inline void hkVector4::Interpolate(const hkVector4& oldValue, const hkVector4& newValue, float factor)
{
    extern const __m128 DAT_010ec7f0;
    __m128 weight = _mm_set1_ps(factor);
    m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, weight), oldValue.m_vComponents),
                       _mm_mul_ps(weight, newValue.m_vComponents));
}

namespace fnv_00c8e800 {

extern NiRTTI DAT_012043f8;
struct Node;
struct Collision;
struct Object
{
    virtual void Slot0();
    virtual void Slot1();
    virtual const NiRTTI* GetRTTI();
    virtual Node* GetAsNode();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    Collision* collision;
};
extern const __m128 DAT_010ec7f0;

struct Body
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void GetNavMeshData(hkVector4* out);
    float FUN_0062ab20();
};
struct Collision : Object
{
};
struct CollisionBody : Object
{
};
struct Node : Object
{
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
    Object** children;
    unsigned short capacity;
    unsigned short count;
};
struct CollisionData
{
    virtual void Slot0();
    virtual void Slot1();
    virtual const NiRTTI* GetRTTI();
    unsigned int unk04, unk08, unk0c;
    Body* body;
};
extern const __m128 DAT_010ec7f0;
inline bool IsKindOfType(Collision* object)
{
    const NiRTTI* type = object->GetRTTI();
    while (type)
    {
        if (type == &DAT_012043f8)
            return true;
        type = type->m_pBaseRTTI;
    }
    return false;
}
// Recursively walks a node's children, then adds the collision body's mass to total and blends center toward the body's nav-mesh data by the mass ratio.
// @fnv 0x00c8e800
// hkVector4 has constructors in the shared header; retain the original stack cookie.
#pragma strict_gs_check(push, on)
void __cdecl AccumulateCenterOfMass(Object* object, hkVector4* center, float* total)
{
    if (!object)
        return;
    Node* node = object->GetAsNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->count; ++i)
            AccumulateCenterOfMass(node->children[i], center, total);
    }
    Collision* collision = object->collision;
    if (!collision)
        return;
    CollisionData* data = IsKindOfType(collision) ? reinterpret_cast<CollisionData*>(collision) : 0;
    if (!data)
        return;
    Body* body = data->body;
    if (!body)
        return;
    float mass = body->FUN_0062ab20();
    hkVector4 next;
    body->GetNavMeshData(&next);
    *total += mass;
    float factor = mass / *total;
    center->Interpolate(*center, next, factor);
}
#pragma strict_gs_check(pop)
}  // namespace fnv_00c8e800

extern const float g_fConst01011d78;

void AccumulateCenterOfMass(void* a, __m128* v, float* f);

// Calls AccumulateCenterOfMass with a broadcast of g_fConst01011d78, then stores the resulting __m128 into out and the float result into pf.
// @fnv 0x00c8e940
void __cdecl GetScalarAndVector(void* a, __m128* out, float* pf)
{
    float f = 0.0f;
    __m128 v = _mm_setr_ps(g_fConst01011d78, g_fConst01011d78, g_fConst01011d78, g_fConst01011d78);
    AccumulateCenterOfMass(a, &v, &f);
    *out = v;
    *pf = f;
}

inline unsigned int NiBinaryStream::Read(void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiSize = 4;
    unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, &uiSize, 1);
    m_uiAbsoluteCurrentPos += uiRead;
    return uiRead;
}

class RigidBody_c8ea
{
  public:
    unsigned int m_uiValue1;
    void SwapEndian();
};

class WorldObject_c8ea
{
  public:
    virtual void v00();
    void bhkEntity_LoadBinary(char* pkStream);
    float FUN_0062ab20();
};

struct LoadStream_c8ea
{
    void NiStream_ReadMultipleLinkIDs();
};

class Entity_c8ea : public WorldObject_c8ea
{
  public:
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
    virtual char* GetRigidBody(int* piIndex);

    int unk04, unk08, unk0c;
    int m_iSlotCount;

    void bhkRigidBody_LoadBinary(char* pkStream);
};

// Calls FUN_00c9d4f0, swaps the rigid body's endianness unless a stream byte is 1, clamps a float to 1000, may set a type byte, and reads m_iSlotCount.
// @fnv 0x00c8ea30
// src: XBOX_PDB 0x00c8ea30
void Entity_c8ea::bhkRigidBody_LoadBinary(char* pkStream)
{
    bhkEntity_LoadBinary(pkStream);
    char* pkBody;
    {
        int iIndex;
        pkBody = GetRigidBody(&iIndex);
    }
    if (*(unsigned char*)(pkStream + 0x1e5) != 1)
        ((RigidBody_c8ea*)pkBody)->SwapEndian();
    if (*(float*)(pkBody + 0xc8) > 1000.0)
        *(float*)(pkBody + 0xc8) = 1000.0f;
    if (*(float*)(pkBody + 0xb0) == 0.0f && FUN_0062ab20() == 0.0f)
    {
        unsigned int uiType = ((RigidBody_c8ea*)pkBody)->m_uiValue1 & 0x7f;
        if (uiType != 2 && uiType != 0x1c)
            *(unsigned char*)(pkBody + 0xd4) = 5;
        if (uiType == 0xe)
            *(unsigned char*)(pkBody + 0xd4) = 4;
    }
    ((LoadStream_c8ea*)pkStream)->NiStream_ReadMultipleLinkIDs();
    (*(NiBinaryStream**)(pkStream + 0x24c))->Read(&m_iSlotCount, 4);
}

extern "C" void _ReadWriteBarrier(void);

class Constraint_eb20
{
  public:
    virtual ~Constraint_eb20();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void SetWorld(int iWorld);
    virtual void RegisterWithWorld();

    bool IsKindOfType(const NiRTTI& kRTTI) const
    {
        for (const NiRTTI* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }

    unsigned int GetLinkedRecordValue();
};

struct ConstraintList_eb20
{
    Constraint_eb20* m_pkItem;
    ConstraintList_eb20* m_pkNext;
    void PopAndRelease();
};

struct WorldData_eb20
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
    int m_iWorld;
};

struct RefObject_eb20
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiValue1;
    ConstraintList_eb20 m_kConstraints;

    void* bhkWorldObject_GethkWorld();
    int GetWorld()
    {
        WorldData_eb20* pkData = (WorldData_eb20*)bhkWorldObject_GethkWorld();
        return pkData ? pkData->m_iWorld : 0;
    }
    unsigned char IsInWorld() const
    {
        return (m_uiValue1 >> 2) & 1;
    }
    void bhkRigidBody_UnFix(bool bSetWorld);
};

extern "C" __declspec(thread) int tls_iMemContext_eb20;
struct MemContextGuard_eb20
{
    int m_iOldContext;
    MemContextGuard_eb20(int aiMemoryContext)
    {
        m_iOldContext = tls_iMemContext_eb20;
        tls_iMemContext_eb20 = aiMemoryContext;
    }
    ~MemContextGuard_eb20()
    {
        tls_iMemContext_eb20 = m_iOldContext;
    }
};

extern char DAT_0126818c;

// If in a world, registers linked constraints and pops them, sets the world on the others when bSetWorld is true, then clears the in-world bit.
// @fnv 0x00c8eb20
// src: XBOX_PDB 0x00c8eb20
void RefObject_eb20::bhkRigidBody_UnFix(bool bSetWorld)
{
    MemContextGuard_eb20 kGuard(0x10);
    if (IsInWorld())
    {
        int iWorld = GetWorld();
        _ReadWriteBarrier();
        if (iWorld)
        {
            ConstraintList_eb20* pkNode = &m_kConstraints;
            if (pkNode)
            {
                do
                {
                    Constraint_eb20* pkItem = pkNode->m_pkItem;
                    if (!pkItem)
                        break;
                    Constraint_eb20* pkConstraint =
                        pkItem->IsKindOfType(reinterpret_cast<const NiRTTI&>(DAT_0126818c)) ? pkItem : 0;
                    if (pkConstraint)
                    {
                        if (pkConstraint->GetLinkedRecordValue())
                        {
                            pkConstraint->RegisterWithWorld();
                            m_kConstraints.PopAndRelease();
                        }
                        else
                        {
                            pkNode = pkNode->m_pkNext;
                            if (bSetWorld)
                                pkConstraint->SetWorld(iWorld);
                        }
                    }
                } while (pkNode);
            }
            m_uiValue1 &= ~4u;
        }
    }
}

extern "C" unsigned long __readfsdword(unsigned long);
extern unsigned int DAT_0126fd98;
extern const float DAT_01017870;
struct TlsBlock
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
};
extern __declspec(thread) TlsBlock g_tlsBlock;
struct MemScope
{
    TlsBlock* block;
    int saved;
    MemScope()
    {
        unsigned int index = *(volatile unsigned int*)&DAT_0126fd98;
        block = ((TlsBlock**)__readfsdword(0x2c))[index];
        saved = block->unk2b4;
        block->unk2b4 = 16;
    }
    ~MemScope()
    {
        block->unk2b4 = saved;
    }
};

extern const unsigned char* const g_01268310_arg1;
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual const NiRTTI* type();
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
    virtual void attach(void*);
    virtual void detach();
    bool isType(const NiRTTI* p)
    {
        const NiRTTI* r = type();
        while (r)
        {
            if (r == p)
                return true;
            r = r->m_pBaseRTTI;
        }
        return false;
    }
};
struct Node
{
    Obj* object;
    Node* next;
};
struct IntegerTriple
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
    void* unk350;
};

Obj* __cdecl bhkFixedConstraint_FixConstraint(Obj*, float);
struct ParentData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c;
};
struct Parent
{
    int unk00, unk04, unk08, unk0c;
    ParentData data;
    ParentData* GetSub()
    {
        return this ? &data : 0;
    }
};
struct Target
{
    int unk00, unk04;
    Parent* parent;
    int unk0c;
    unsigned int flags;
    Node list;
    void* getOwner()
    {
        IntegerTriple* data = (IntegerTriple*)((bhkRefObject*)this)->bhkRefObject::GetReferencedData();
        return data ? data->unk350 : 0;
    }
    unsigned char getFlag()
    {
        return (unsigned char)(flags >> 2);
    }
    __forceinline unsigned int getBits()
    {
        ParentData* s = parent ? parent->GetSub() : 0;
        return s ? s->unk1c : 0;
    }
    void bhkRigidBody_Fix();
};
// Replaces each matching object in the list with the result of FUN_00cc81c0, attached to the owner, then sets flag value 4.
// @fnv 0x00c8f080
// src: XBOX_PDB 0x00c8f080
void Target::bhkRigidBody_Fix()
{
    MemScope scope;
    if (getFlag() & 1)
        return;
    IntegerTriple* data = (IntegerTriple*)((bhkRefObject*)this)->bhkRefObject::GetReferencedData();
    void* owner;
    if (data)
        *(void* volatile*)&owner = data->unk350;
    else
        *(void* volatile*)&owner = 0;
    if (!owner)
        return;
    Node* node = &list;
    while (node)
    {
        Obj* object = node->object;
        if (!object)
            break;
        bool valid = object->isType((const NiRTTI*)&g_01268310_arg1);
        node = node->next;
        Obj* body = valid ? object : 0;
        if (body)
        {
            float scale = 1.0f;
            unsigned int bits = getBits();
            unsigned int kind = bits & 0x7f;
            if (kind == 8 || kind == 29)
            {
                unsigned int sub = (bits >> 8) & 31;
                if (sub == 17 || (sub >= 21 && sub <= 22))
                    scale = DAT_01017870;
            }
            Obj* replacement = bhkFixedConstraint_FixConstraint(body, scale);
            if (replacement)
            {
                ((bhkRigidBody*)this)->bhkRigidBody_AddActCon((NiObject*)replacement);
                body->detach();
                replacement->attach(owner);
            }
        }
    }
    flags |= 4;
}
