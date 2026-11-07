
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/Transform.h"

struct S_d2f5a0_Obj
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
    virtual void v9(int a);
};
struct S_d2f5a0_Entry
{
    int unk0;
    int unk4;
    S_d2f5a0_Obj* m_obj;
};
typedef hkArrayBase<S_d2f5a0_Entry> S_d2f5a0_Array;
struct S_d2f5a0
{
    int unk0;
    int unk4;
    int unk8;
    S_d2f5a0_Array m_aiIndexedValues;
    void hkpBvTreeAgent_invalidateTim(int a);
};
struct TargetObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(Transform* apTransform, float afAmount, void* apContext);
};
struct Holder
{
    TargetObject* m_pFlagTarget;
    int unk04;
    void* m_pData;
};
struct ValueSource
{
    int unk00;
    int unk04;
    float m_fAmount;
};
void __cdecl ApplyTransformToTarget(Holder* apFirst, Holder* apSecond, ValueSource* apValue, void* apContext);
struct Allocator
{
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* allocator;
};
struct Built
{
    int field00;
    short field04;
    int field08;
    void __thiscall FUN_00d2f980(int);
};
extern "C" Global* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkpBvTreeAgent_createShapeBvAgent(int arg1, int arg2, int arg3, int arg4);
void __cdecl hkpBvTreeAgent_staticLinearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth);
void __stdcall hkpBvTreeAgent_linearCast(void* apFirst, void* apSecond, void* apThird, void* apFourth, void* apFifth);
extern "C" void __cdecl hkpBvTreeAgent_staticGetClosestPoints(void* arg0, void* arg1, void* arg2, void* arg3);
// @fnv 0x00d315d0
// src: HAVOK_SRC 0x00d315d0
extern "C" void __stdcall hkpBvTreeAgent_getClosestPoints(void* arg0, void* arg1, void* arg2, void* arg3)
{
    hkpBvTreeAgent_staticGetClosestPoints(arg0, arg1, arg2, arg3);
}

void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA, void* apB, void* apC, void* apD);
void __stdcall hkpBvTreeAgent_getPenetrations(void* apA, void* apB, void* apC, void* apD);
struct D2FA00Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D2FA00MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2FA00Allocator* m_pStreamAllocator;

    D2FA00Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" D2FA00MemoryRouter& __cdecl hkMemoryRouter_getInstance();
}

class D2FA00ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b =
            static_cast<D2FA00ReferencedObject*>(fnvc_adapt::hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
    virtual ~D2FA00ReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class D2FA00Agent : public D2FA00ReferencedObject
{
  public:
    __declspec(nothrow) D2FA00Agent(void* mgr);

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
};
class D2FA00ShapeAgent : public D2FA00Agent
{
  public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr)
    {}
    virtual ~D2FA00ShapeAgent();
};
D2FA00Agent* __cdecl hkpBvTreeAgent_createBvTreeShapeAgent(const void* bodyA, const void* bodyB, const void* input, void* mgr);
extern char str_010ce9a4[];
extern char str_010ce9ac[];
extern "C" void* __cdecl hkStatisticsCollector_getAllocatedSize(void* apBuffer, int aiCount);
struct S_00d2f8f0_Elem
{
    int unk00;
    int unk04;
    int unk08;
};
struct S_00d2f8f0_Array
{
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const
    {
        return m_pEntries;
    }
    S_00d2f8f0_Elem* end() const
    {
        return m_pEntries + m_iArrayLength;
    }
};
struct S_00d2f8f0_ArgVtbl
{
    void* unk00;
    void* unk04;
    void* unk08;
    void(__thiscall* unk0c)(void*, char*, int, int);
    void* unk10;
    void(__thiscall* unk14)(void*, int, char*, void*, int, void*);
};
struct S_00d2f8f0_Arg
{
    S_00d2f8f0_ArgVtbl* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    char m_bFlag10;
};
struct S_00d2f8f0
{
    int unk00;
    int unk04;
    int unk08;
    S_00d2f8f0_Array m_aiIndexedValues;
    int m_iFlags;

    void WriteToStream(S_00d2f8f0_Arg* apStream, int aiUnused);
};
class ListenerD2F5
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* pArg);
};
struct EntryD2F5
{
    int unk00;
    int unk04;
    ListenerD2F5* m_pkListener;
};
class OwnerD2F5
{
  public:
    virtual ~OwnerD2F5();

    int unk04[2];
    hkArray<EntryD2F5> m_entries;

    void hkpBvTreeAgent_cleanup(void* pArg);
};

#include <windows.h>
unsigned __int64 __cdecl __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(unsigned int);

struct S312_Split
{
    const char* m_cmd;
    DWORD m_uiStartTicks;
    DWORD unk08;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile DWORD t = (DWORD)__rdtsc();
        m_uiStartTicks = t;
    }
};
struct S312_Cmd : S312_Split
{
    const char* m_pHeadNode;
};
struct S312_Stream
{
    DWORD unk00;
    char* m_kRayEnd;
    DWORD unk08;
    char* m_capMinus16;
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_capMinus16;
    }
};
inline S312_Stream& S312_getInstance()
{
    return *(S312_Stream*)TlsGetValue(DAT_0126835c);
}

struct S312_Shape
{
    void* vt;
    DWORD unk04, unk08;
    DWORD m_type;
};
struct S312_Body
{
    S312_Shape* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    S312_Body* m_parent;
    void SetCollisionShapeAndKey(S312_Shape* s, int k)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = k;
    }
};
struct S312_Aabb
{
    float m_kMinimumCorner[4];
    float m_kMaximumCorner[4];
};

struct S312_Container
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual S312_Shape* GetShapeForKey(int key, void* buf);
};
struct S312_Alloc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void free(void* p, int n);
    void ReturnMemory(int* p, int n)
    {
        free(p, n * sizeof(int));
    }
};
struct S312_Array
{
    int* m_data;
    int m_iElementCount;
    int m_capAndFlags;
};
inline void S312_dealloc(S312_Alloc* al, int* p, int n);
struct S312_InplaceArray : S312_Array
{
    int m_kStorage[128];
    S312_InplaceArray()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_capAndFlags = (int)0x80000080;
    }
    void ClearAndRelease(S312_Alloc& a)
    {
        m_iElementCount = 0;
        if ((m_capAndFlags & 0x80000000) == 0)
            a.ReturnMemory(m_data, m_capAndFlags & 0x3fffffff);
        m_data = 0;
        m_capAndFlags = (int)0x80000000;
    }
    ~S312_InplaceArray()
    {
        ClearAndRelease((S312_Alloc&)fnvc_adapt::hkMemoryRouter_getInstance().heap());
    }
};
struct S312_BvTree
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual S312_Container* GetShapeContainer();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void GetAabbHits(S312_Aabb* aabb, S312_Array* hits);
};
struct S312_Input;
struct S312_Filter
{
    virtual void v0();
    virtual bool* IsCollisionEnabled(bool* res, S312_Input* input, S312_Body* a, S312_Body* b, S312_Container* c,
                                     int key);
};
struct S312_FilterHolder
{
    DWORD unk0, unk4, unk8;
    S312_Filter m_iFilter;
};
typedef void(__cdecl* S312_Func)(S312_Body*, S312_Body*, S312_Input*, void*);
struct S312_Input
{
    unsigned char* m_pCollisionDispatcher;
    DWORD unk04, unk08;
    S312_FilterHolder* m_iFilter;
};
struct S312_Collector
{
    DWORD unk0;
    bool m_fHitDistance;
};

inline void S312_dealloc(S312_Alloc* al, int* p, int n)
{
    al->free(p, n * sizeof(int));
}

// @fnv 0x00d312f0
// src: HAVOK_LIB 0x00d312f0
void __cdecl hkpBvTreeAgent_staticGetPenetrations(void* apA, void* apB, void* apC, void* apD)
{
    S312_Body& bodyA = *(S312_Body*)apA;
    S312_Body& bodyB = *(S312_Body*)apB;
    S312_Input& input = *(S312_Input*)apC;
    S312_Collector& collector = *(S312_Collector*)apD;
    volatile DWORD t;
    {
        S312_Stream& ms = S312_getInstance();
        if (ms.memoryAvailable())
        {
            S312_Cmd* h = (S312_Cmd*)ms.m_kRayEnd;
            h->m_cmd = "LtBvTree";
            h->m_pHeadNode = "StQueryTree";
            _ReadWriteBarrier();
            t = (DWORD)__rdtsc();
            h->m_uiStartTicks = t;
            ms.m_kRayEnd = (char*)(h + 1);
        }
    }
    S312_Aabb aabb;
    ApplyTransformToTarget((Holder*)apA, (Holder*)apB, (ValueSource*)apC, &aabb);
    S312_BvTree* bvB = (S312_BvTree*)bodyB.m_pCollisionShape;
    S312_InplaceArray hitList;
    bvB->GetAabbHits(&aabb, &hitList);
    {
        S312_Stream& ms = S312_getInstance();
        if (ms.memoryAvailable())
        {
            S312_Split* h = (S312_Split*)ms.m_kRayEnd;
            h->m_cmd = "StNarrowPhase";
            _ReadWriteBarrier();
            t = (DWORD)__rdtsc();
            h->m_uiStartTicks = t;
            ms.m_kRayEnd = (char*)(h + 1);
        }
    }
    {
        int* itr;
        int* end;
        DWORD typeA = bodyA.m_pCollisionShape->m_type;
        itr = hitList.m_data;
        end = hitList.m_data + hitList.m_iElementCount;
        S312_Body modifiedBodyB;
        modifiedBodyB.m_parent = &bodyB;
        modifiedBodyB.m_pMotionState = bodyB.m_pMotionState;
        S312_Container* shapeContainer = bvB->GetShapeContainer();
        __declspec(align(16)) unsigned int shapeBuffer[128];
        while (itr != end)
        {
            bool res;
            if (*input.m_iFilter->m_iFilter.IsCollisionEnabled(&res, &input, &bodyA, &bodyB, shapeContainer, *itr))
            {
                S312_Shape* shape = shapeContainer->GetShapeForKey(*itr, shapeBuffer);
                modifiedBodyB.SetCollisionShapeAndKey(shape, *itr);
                unsigned char* d = input.m_pCollisionDispatcher;
                unsigned char idx = d[(typeA + 0xd) * 32 + shape->m_type];
                S312_Func f = *(S312_Func*)(d + idx * 20 + 0x9a4);
                f(&bodyA, &modifiedBodyB, &input, &collector);
                if (collector.m_fHitDistance)
                    break;
            }
            itr++;
        }
        {
            S312_Stream& ms = S312_getInstance();
            if (ms.memoryAvailable())
            {
                S312_Split* h = (S312_Split*)ms.m_kRayEnd;
                h->m_cmd = "lt";
                _ReadWriteBarrier();
                t = (DWORD)__rdtsc();
                h->m_uiStartTicks = t;
                ms.m_kRayEnd = (char*)(h + 1);
            }
        }
    }
}
