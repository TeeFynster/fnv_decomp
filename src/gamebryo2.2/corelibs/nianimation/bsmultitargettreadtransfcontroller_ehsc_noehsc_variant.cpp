
// src/gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "bsmultitargettreadtransfcontroller_decls.h"
#include "../../../../include/NiQuaternion.h"
#include "../../../../include/NiPoint3.h"
#include "../../../../include/NiQuatTransform.h"
#include "../../../../include/NiInterpController.h"
struct FUN_00a35950_shell : public BSMultiTargetTreadTransfController
{
    void* BSMultiTargetTreadTransfController_GetRTTI();
};
extern int g_011f36e4;
struct FUN_00a35e90_shell : public BSMultiTargetTreadTransfController
{
    char* BSMultiTargetTreadTransfController_GetInterpolatorID(unsigned short);
};
struct FUN_00a35fc0_shell
{
    void __thiscall SetSlotValue(unsigned short idx, void* val);
};
struct FUN_00a35910_shell
{
    unsigned short __thiscall FindIndexByValue(unsigned short a);
};
struct Inner_00a35f30
{
    char _pad[8];
    void* h;
};
struct Link_00a35f30
{
    char _pad2[4];
    Inner_00a35f30* p;
};
struct Arg_00a35f30
{
    void* h;
};
struct This_00a35f30
{
    char _pad[0x38];
    unsigned short num;
    Link_00a35f30** links;
};
struct Holder_00a35f30
{
    unsigned short FindLinkIndex(const Arg_00a35f30& arName);
};
struct FUN_00a35f70_struct
{
    void __thiscall SetSlotEntry(unsigned short, void*, unsigned short, void*);
};
struct S_00a36050
{
    void __thiscall ProcessEntries_00a35960();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
struct Interp00a358b0
{
    virtual void D00() = 0;
    virtual void D01() = 0;
    virtual void D02() = 0;
    virtual void D03() = 0;
    virtual void D04() = 0;
    virtual void D05() = 0;
    virtual void D06() = 0;
    virtual void D07() = 0;
    virtual void D08() = 0;
    virtual void D09() = 0;
    virtual void D10() = 0;
    virtual void D11() = 0;
    virtual void D12() = 0;
    virtual void D13() = 0;
    virtual void D14() = 0;
    virtual void D15() = 0;
    virtual void D16() = 0;
    virtual void D17() = 0;
    virtual void D18() = 0;
    virtual void D19() = 0;
    virtual void D20() = 0;
    virtual void D21() = 0;
    virtual void D22() = 0;
    virtual void D23() = 0;
    virtual void D24() = 0;
    virtual void D25() = 0;
    virtual void D26() = 0;
    virtual void D27() = 0;
    virtual void D28() = 0;
    virtual void D29() = 0;
    virtual void D30() = 0;
    virtual void D31() = 0;
    virtual void D32() = 0;
    virtual void D33() = 0;
    virtual void D34() = 0;
    virtual void D35() = 0;
    virtual void D36() = 0;
    virtual void D37() = 0;
    virtual void D38() = 0;
    virtual void D39() = 0;
    virtual void D40() = 0;
    virtual void D41() = 0;
    virtual void D42() = 0;
    virtual void D43() = 0;
    virtual void D44() = 0;
    virtual void D45() = 0;
    virtual void D46() = 0;
    virtual void D47() = 0;
    virtual void D48() = 0;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime) = 0;
    char _pad[48];
};
struct Ctrl00a358b0
{
    char _0[52];
    Interp00a358b0* m_base;
    unsigned short m_num;
    void __thiscall BSMultiTargetTreadTransfController_GuaranteeTimeRange(float afStartTime, float afEndTime);
};
// Stand-in for NiInterpolator: the virtual used at vtable offset 0xB8 (index 46)
// takes no stack arguments (this-> in ecx only).
struct InterpStub_00a2fac0
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual bool IsCorrectType() = 0;  // +0xB8
};
bool __stdcall NiMultiTargetTransformController_InterpolatorIsCorrectType(InterpStub_00a2fac0* apInterpolator, unsigned short ausIndex);
// FUN_00a35900 : BSMultiTargetTreadTransfController entry getter.
// Returns &m_pEntries[usIndex]; the stride is sizeof(TreadEntry) = 0x34.
struct FUN_00a35900_cls
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    TreadEntry* m_pEntries;
    TreadEntry* BSMultiTargetTreadTransfController_GetBlendInterpolator(unsigned short usIndex, int aParam1, int aParam2, int aParam3, int aParam4);
};
extern char DAT_01096694;
void* __cdecl Object_DispatchCommandFour(unsigned int size) throw();
struct TreadInterpolator : NiInterpController
{
    unsigned int unk34;
    unsigned short unk38;
    unsigned short unk3a;
    unsigned int unk3c;
    unsigned short unk40;
    unsigned short unk42;

    static void* operator new(unsigned int size) throw()
    {
        return Object_DispatchCommandFour(size);
    }
    TreadInterpolator() throw()
    {
        *reinterpret_cast<void**>(this) = &DAT_01096694;
        unk34 = 0;
        unk38 = 0;
        unk40 = 0;
        unk3c = 0;
    }
};
struct TreadController
{
    TreadInterpolator* __thiscall CreateInterpolator(unsigned int index);
    void __thiscall BSMultiTargetTreadTransfController_CopyMembers(TreadInterpolator* interp, unsigned int index);
};
struct TreadElem_00a35b90
{
    char unk00[0x34];
    void __thiscall Dtor();
};
void __cdecl FreeArr_00a35b90(void* apMemory, unsigned int aiSize);
void __cdecl FreeObj_00a35b90(void* apMemory, unsigned int aiSize);
struct FUN_00a35b90_cls
{
    char unk00[0x34];

    void* Destroy(unsigned int acFlags);
};
struct Entry_00a35fe0
{
    unsigned short unk00;
    void* unk04;
    void* unk08;
};
struct Target_00a35fe0
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
    unsigned int unk30;
};
struct FUN_00a35fe0_shell
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
    Entry_00a35fe0** unk3C;
    unsigned short unk40;

    unsigned short __thiscall BSMultiTargetTreadTransfController_AddInterpolatorTarget(Target_00a35fe0* target, unsigned short id, void* value);
};
extern unsigned short DAT_01096320;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
inline unsigned int NiAtomicIncrement(unsigned int& v)
{
    return InterlockedIncrement((long*)&v);
}
inline unsigned int NiAtomicSubtract(unsigned int& v)
{
    return InterlockedDecrement((long*)&v);
}
class RefObj
{
  public:
    virtual ~RefObj();
    virtual void DeleteThis();
    void IncRefCount()
    {
        NiAtomicIncrement(m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!NiAtomicSubtract(m_uiRefCount))
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};
template <class T> class SmartPtr
{
  public:
    SmartPtr(T* p = 0) throw() : m_pObject(p)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }
    ~SmartPtr() throw()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    SmartPtr& operator=(const SmartPtr& ptr) throw()
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};
struct Entry
{
    RefObj* m_p;
    int m_04, m_08, m_0c;
    void Clear() throw();
};
struct Entry2
{
    int m_00, m_04, m_08, m_0c, m_10;
    void Clear() throw();
};
struct Holder
{
    int m_00, m_04, m_08, m_0c, m_10;
    Entry* m_14;
    Entry2* m_18;
    void AssignInterpolatorRef(unsigned int idx, SmartPtr<RefObj>& out) throw();
    void NiControllerSequence_RemoveInterpolator_0(unsigned int idx);
};
void Holder::AssignInterpolatorRef(unsigned int idx, SmartPtr<RefObj>& out) throw()
{
    SmartPtr<RefObj> sp = m_14[idx].m_p;
    m_14[idx].Clear();
    m_18[idx].Clear();
    out = sp;
}
struct NiStream;
extern void __cdecl LoadBinary(NiStream*);
void __cdecl BSMultiTargetTreadTransfController_LoadBinary(NiStream* stream);
struct Mat112
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};
extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;
struct Blend112
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
    virtual bool Update(float, void*, NiQuatTransform&);
    int field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28, field2c;
    float weight;
};
struct Node112
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c, field20, field24, field28, field2c;
    unsigned flags;
    unsigned char Active() const
    {
        return flags >> 1;
    }
    Mat112 matrix;
    NiPoint3 position;
};
// 0x00a35c00 blends two poses in this 0x3C-byte record; include/Data.h holds 0x10 bytes of skill/category data.
struct TreadPosePair
{
    NiPoint3 position0;
    NiQuaternion rotation0;
    float scale0;
    NiPoint3 position1;
    NiQuaternion rotation1;
};
struct Link112
{
    unsigned short index;
    Node112* node;
    TreadPosePair* data;
};
struct Controller112
{
    int field00, field04;
    unsigned short flags;
    unsigned char Active() const
    {
        return flags >> 3;
    }
    unsigned short field0a;
    int field0c, field10, field14, field18, field1c, field20, field24, field28, field2c, field30;
    Blend112* blends;
    unsigned short count, field3a;
    Link112** links;
    unsigned short linkCount;
    void BSMultiTargetTreadTransfController_Update(float* time);
};

struct ArrayCount
{
    unsigned int value;
    ArrayCount(unsigned int count) : value(count)
    {}
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct MemoryManagerAllocHelper
{
    void* Allocate(unsigned int);
};
extern MemoryManagerAllocHelper DAT_011f6238;
__forceinline void* __cdecl operator new(unsigned int n)
{
    return DAT_011f6238.Allocate(n);
}
void* __cdecl FUN_00aa1420(unsigned int);
struct SNAEntry
{
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Allocate(n);
    }
    static void* operator new[](unsigned int s, ArrayCount count)
    {
        if (count.value == 0)
            return ::operator new(4);
        return FUN_00aa1420(s);
    }
    static void operator delete[](void*, unsigned int);
};
struct FUN_00a42f60 : SNAEntry
{
    long refs;
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
    __declspec(nothrow) FUN_00a42f60();
    virtual ~FUN_00a42f60();
};
struct NodeA35
{
    static void* operator new(unsigned int n)
    {
        return DAT_011f6238.Allocate(n);
    }
    int a;
    int b;
    int c;
};
void* __cdecl _NiMalloc_00aa1070(unsigned int);
void* __cdecl FUN_00ec61c0(void*, int, unsigned int);
struct TargetA35
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
    FUN_00a42f60* entries;
    unsigned short count;
    NodeA35** nodes;
    unsigned short nodeCount;
    void BSMultiTargetTreadTransfController_AllocateStorage(unsigned short, unsigned short);
};
// @fnv 0x00a35a80
// src: XBOX_PDB 0x00a35a80
void TargetA35::BSMultiTargetTreadTransfController_AllocateStorage(unsigned short n, unsigned short m)
{
    count = n;
    nodeCount = m;
    if (n)
    {
        entries = new (ArrayCount(n)) FUN_00a42f60[n];
        for (unsigned short i = 0; i < n; ++i)
            InterlockedIncrement(&entries[i].refs);
        nodes = (NodeA35**)_NiMalloc_00aa1070(sizeof(NodeA35*) * m);
        FUN_00ec61c0(nodes, 0, sizeof(NodeA35*) * m);
        for (unsigned short i = 0; i < m; ++i)
            nodes[i] = new NodeA35();
    }
}
