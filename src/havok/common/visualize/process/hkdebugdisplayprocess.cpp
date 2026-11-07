
// src/havok/common/visualize/process/hkdebugdisplayprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkdebugdisplayprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern volatile int DAT_01269cdc;
struct Target
{
    void* volatile vptr;
};
struct Thunk
{
    void InvokeVirtualSlot15(int, int, int, int, int);
};
typedef void(__thiscall* VirtualTarget)(Target*, int, int, int, int, int);
// @fnv 0x00ddc920
void Thunk::InvokeVirtualSlot15(int a, int b, int c, int d, int e)
{
    Target* target = *(Target**)((char*)this - 8);
    void* volatile* table = (void* volatile*)target->vptr;
    volatile int& fifth = e;
    fifth = DAT_01269cdc;
    VirtualTarget call = (VirtualTarget)table[15];
    call(target, a, b, c, d, e);
}

struct Owner
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void forward(unsigned int, unsigned int, unsigned int, float, float, float, unsigned int);
};
// Exe 0x00ddc9c0: unit-local Interface view; declarations and layout are preserved.
struct HkdebugdisplayprocessInterfaceView
{
    void ForwardToOwner(unsigned int, unsigned int, unsigned int, float, float, float, unsigned int);
};
// Retrieves the Owner pointer stored 8 bytes before this Interface and forwards all seven arguments to its forward method.
// @fnv 0x00ddc9c0
void HkdebugdisplayprocessInterfaceView::ForwardToOwner(unsigned int a, unsigned int b, unsigned int c, float d, float e, float f,
                               unsigned int g)
{
    Owner* owner = *(Owner**)((char*)this - 8);
    owner->forward(a, b, c, d, e, f, g);
}

namespace fnv_00ddca90 {
extern int g_callbackContext;
struct Target
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual int invoke(int, int, int, int, int);
};
struct Adapter
{
    int InvokeTarget(int, int, int, int, int);
};
struct AdapterHeader
{
    Target* target;
    unsigned int flags;
};
// @fnv 0x00ddca90
int Adapter::InvokeTarget(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int context)
{
    AdapterHeader* header = reinterpret_cast<AdapterHeader*>(reinterpret_cast<char*>(this) - sizeof(AdapterHeader));
    return header->target->invoke(aiArg1, aiArg2, aiArg3, aiArg4, g_callbackContext);
}
}  // namespace fnv_00ddca90

extern char DAT_010d7ed0;
extern char DAT_010d7eb0;
extern char DAT_010d7e5c;
extern char DAT_010d7cfc;
extern char DAT_010d1508;
extern char DAT_0102e388;
class ProcessManager
{
  public:
    void RemoveListener(void* process);
};
extern ProcessManager* DAT_012681e0;
class Process
{
  public:
    void* vftable;
    int unk04;
    void* baseVftable;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* listenerVftable;
    void SetVtableAndProcessState_00ddcb50();
};
// @fnv 0x00ddcb50
// src: GUESS 0x00ddcb50 (confidence: low)
void Process::SetVtableAndProcessState_00ddcb50()
{
    vftable = &DAT_010d7ed0;
    baseVftable = &DAT_010d7eb0;
    listenerVftable = &DAT_010d7e5c;
    DAT_012681e0->RemoveListener(&listenerVftable);
    listenerVftable = &DAT_010d7cfc;
    baseVftable = &DAT_010d1508;
    vftable = &DAT_0102e388;
}

struct S_00ddcb90_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};

struct S_00ddcb90_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddcb90_Allocator* m_pStreamAllocator;
    S_00ddcb90_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00ddcb90_Router* hkMemoryRouter_getInstance();

struct S_00ddcb90_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    virtual ~S_00ddcb90_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddcb90_RefObj* b = static_cast<S_00ddcb90_RefObj*>(hkMemoryRouter_getInstance()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};

struct S_00ddcb90_Base2
{
    virtual void v0();
};

struct S_00ddcb90_Obj : S_00ddcb90_RefObj, S_00ddcb90_Base2
{
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    S_00ddcb90_Obj() throw();
};

// Allocates and constructs a new S_00ddcb90_Obj via its operator new and returns it as S_00ddcb90_Base2.
// @fnv 0x00ddcb90
// src: HAVOK_LIB 0x00ddcb90
S_00ddcb90_Base2* hkDebugDisplayProcess_create()
{
    return new S_00ddcb90_Obj();
}

namespace fnv_00ddcbe0 {
extern int DAT_01269cdc;
// @fnv 0x00ddcbe0
// src: GUESS 0x00ddcbe0 (confidence: low)
int Object_GetDAT_01269cdc_00ddcbe0()
{
    return DAT_01269cdc;
}
}  // namespace fnv_00ddcbe0

namespace fnv_00ddcc10 {
struct Process;
struct Allocator
{
    virtual void First();
    virtual void Second();
    virtual void Release(Process*, unsigned short);
};
struct ProcessServices
{
    int a, b, c, d;
    Allocator* allocator;
};
ProcessServices* __cdecl hkMemoryRouter_getInstance();
struct Process
{
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    void SetVtableAndProcessState_00ddcb50();
    Process* hkDebugDisplayProcess_Destroy(unsigned char flags);
};
// Calls FUN_00ddcb50, and if flags has bit 0 set, releases this process with size unk04 through the allocator from FUN_00c85750; returns this.
// @fnv 0x00ddcc10
// src: COMMUNITY 0x00ddcc10
Process* Process::hkDebugDisplayProcess_Destroy(unsigned char flags)
{
    SetVtableAndProcessState_00ddcb50();
    if (flags & 1)
    {
        ProcessServices* services = hkMemoryRouter_getInstance();
        unsigned short size = unk04;
        Allocator* allocator = services->allocator;
        allocator->Release(this, size);
    }
    return this;
}
}  // namespace fnv_00ddcc10

extern unsigned int g_01269cdc;

struct TargetIface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int vslot3(int a, int b, unsigned int c);
};

struct OwnerHolder
{
    TargetIface* m_target;
    unsigned int unk04;
};

class S_00ddc960_cls
{
  public:
    int ForwardToTarget(int a, int b, unsigned int c);
    unsigned int unk00;
    unsigned int unk04;
};

// @fnv 0x00ddc960
int S_00ddc960_cls::ForwardToTarget(int aiArg1, int aiArg2, unsigned int c)
{
    OwnerHolder* h = (OwnerHolder*)((char*)this - 8);
    return h->m_target->vslot3(aiArg1, aiArg2, g_01269cdc);
}

// ForwardToDelegate - a forwarding member of a secondary base.
//
// The original code is exactly:
//     00ddca50  8b 49 f8           mov ecx, dword ptr [ecx - 8]
//     00ddca53  8b 01              mov eax, dword ptr [ecx]
//     00ddca55  8b 15 dc 9c 26 01  mov edx, dword ptr [0x1269cdc]
//     00ddca5b  89 54 24 18        mov dword ptr [esp + 18h], edx
//     00ddca5f  8b 40 28           mov eax, dword ptr [eax + 28h]
//     00ddca62  ff e0              jmp eax
//
// so the member is
//     Sink* ForwardToDelegate(int, int, int, int, int, int)
// and it does nothing but forward its arguments to the eleventh virtual of
// the delegate object, with the last argument replaced by the value of the
// global at 0x1269cdc:
//
//   * [ecx-8] is the delegate pointer, which lives in the primary base of
//     the object; this member belongs to a *secondary* base, so its 'this'
//     pointer points eight bytes past the start of the object;
//   * the delegate's first word is its vtable pointer and the target is
//     the virtual in slot 0x28 (the eleventh one);
//   * the value of the global is written into the outgoing sixth argument
//     slot and the call is then a tail call (jmp), so the callee sees the
//     global instead of the original sixth argument.
//
// The forwarder returns what the delegate returns, which is what makes the
// call a tail jump.

// Stand-in for the object the delegate points at.  The eleventh virtual is
// the one the forwarder calls; the ones before it only pad the vtable.
struct Sink
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual Sink* f10(int, int, int, int, int, int);
};

// The global the sixth argument is replaced with (uninitialised, so it
// lives in .bss just like the original one at 0x1269cdc).
int g_1269cdc;

// Primary base of the forwarding object: the delegate plus padding, so
// that the secondary base below starts eight bytes into the object.
struct ForwarderBase
{
    Sink* m_delegate;
    int unk04;
};

// Secondary base: the interface that carries the forwarding virtual.
struct ForwarderInterface
{
    virtual Sink* ForwardToDelegate(int, int, int, int, int, int);
};

struct Forwarder : public ForwarderBase, public ForwarderInterface
{
};

// @fnv 0x00ddca50
Sink* ForwarderInterface::ForwardToDelegate(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6)
{
    // The delegate pointer is stored in the primary base, which ends right
    // where this secondary base sub-object begins.
    Sink* d = *(Sink**)((char*)this - sizeof(ForwarderBase));
    return d->f10(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, g_1269cdc);
}

// FUN_00ddcad0: thiscall forwarder. The owner pointer lives 8 bytes before this;
// the single stack argument is forwarded to the owner's vtable slot 0x40 via a tail jump.

class FUN_00ddcad0_owner
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40(int a);
};

class FUN_00ddcad0_cls
{
  public:
    void hkDebugDisplayProcess_sendMemStatsDump(int a);
};

// @fnv 0x00ddcad0
// src: HAVOK_LIB 0x00ddcad0
void FUN_00ddcad0_cls::hkDebugDisplayProcess_sendMemStatsDump(int a)
{
    FUN_00ddcad0_owner* owner = *(FUN_00ddcad0_owner**)((char*)this - 8);
    owner->v40(a);
}

struct S_00ddc8e0_Owner
{
    virtual void v0();
    virtual int v1(int a, int b, int c, int d);
};
struct S_00ddc8e0_Cls
{
    int unk00;
    int unk04;
    int ForwardToOwnerVirtual(int a, int b, int c, int d);
};
// @fnv 0x00ddc8e0
int S_00ddc8e0_Cls::ForwardToOwnerVirtual(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    S_00ddc8e0_Owner* pOwner = *(S_00ddc8e0_Owner**)((char*)this - 8);
    return pOwner->v1(aiArg1, aiArg2, aiArg3, DAT_01269cdc);
}

struct SinkDDCA
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual SinkDDCA* f8(int, int, int, int);
};

struct ForwarderDDCA;

struct ForwarderBaseDDCA
{
    SinkDDCA* m_delegate;
    int unk04;
};

struct ForwarderInterfaceDDCA
{
    SinkDDCA* hkDebugDisplayProcess_displayPoint(int a, int b, int c, int d);
};

struct ForwarderDDCA : public ForwarderBaseDDCA, public ForwarderInterfaceDDCA
{
};

// @fnv 0x00ddca10
// src: HAVOK_LIB 0x00ddca10
SinkDDCA* ForwarderInterfaceDDCA::hkDebugDisplayProcess_displayPoint(int aArg1, int aArg2, int aArg3, int aArg4)
{
    SinkDDCA* pkDelegate =
        reinterpret_cast<ForwarderBaseDDCA*>(reinterpret_cast<char*>(this) - sizeof(ForwarderBaseDDCA))->m_delegate;
    return pkDelegate->f8(aArg1, aArg2, aArg3, DAT_01269cdc);
}

// FUN_00ddcbf0: MSVC adjustor thunk for a secondary base at offset 0x20.
// Derived overrides a virtual that both bases declare; the second base's vtable slot
// is a thunk that moves `this` back by sizeof(PrimaryBase) and jumps to the override.

struct PrimaryBase
{
    virtual void FUN_00ddcbf0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00ddcbf0();
};

struct SpawnedObject : PrimaryBase, SecondaryBase
{
    SpawnedObject();
// @fnv 0x00ddcbf0
    virtual void FUN_00ddcbf0();
};

SpawnedObject::SpawnedObject()
{}

namespace fnv_00ddcc00 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00ddcc00();
    int unk04;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00ddcc00();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ddcc00
// src: GUESS 0x00ddcc00 (confidence: low)
    virtual void AdjustThisAndForward_00ddcc00();
};

Derived::Derived()
{}
}  // namespace fnv_00ddcc00

namespace fnv_00ddc900 {
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08(int a, int b, int c, unsigned int d);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddc900_cls
{
  public:
    void hkDebugDisplayProcess_addGeometryInstance(int a, int b, int c, unsigned int d);
};

// @fnv 0x00ddc900
// src: HAVOK_LIB 0x00ddc900
void FUN_00ddc900_cls::hkDebugDisplayProcess_addGeometryInstance(int a, int b, int c, unsigned int d)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&d = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int, unsigned int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x8);
    fn(t, a, b, c, d);
}
}  // namespace fnv_00ddc900

namespace fnv_00ddc940 {
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
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
    virtual void v38(int a, int b, int c, unsigned int d);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddc940_cls
{
  public:
    void hkDebugDisplayProcess_displayGeometry(int a, int b, int c, unsigned int d);
};

// @fnv 0x00ddc940
// src: HAVOK_LIB 0x00ddc940
void FUN_00ddc940_cls::hkDebugDisplayProcess_displayGeometry(int aiArg1, int aiArg2, int aiArg3, unsigned int d)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&d = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int, unsigned int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x38);
    fn(t, aiArg1, aiArg2, aiArg3, d);
}
}  // namespace fnv_00ddc940

namespace fnv_00ddc980 {
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(int a, int b, int c);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddc980_cls
{
  public:
    void hkDebugDisplayProcess_updateGeometry(int a, int b, int c);
};

// @fnv 0x00ddc980
// src: HAVOK_LIB 0x00ddc980
void FUN_00ddc980_cls::hkDebugDisplayProcess_updateGeometry(int aArg1, int aArg2, int aArg3)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&aArg3 = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x10);
    fn(t, aArg1, aArg2, aArg3);
}
}  // namespace fnv_00ddc980

namespace fnv_00ddc9a0 {
extern unsigned int DAT_01269cdc;
class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14(int a, unsigned int b);
};
class FUN_00ddc9a0_cls
{
  public:
    void hkDebugDisplayProcess_removeGeometry(int a, unsigned int b);
};
// @fnv 0x00ddc9a0
// src: HAVOK_LIB 0x00ddc9a0
void FUN_00ddc9a0_cls::hkDebugDisplayProcess_removeGeometry(int aiArg, unsigned int auiParam)
{
    FNVTarget* t = *(FNVTarget**)((char*)this - 8);
    void** pVTable = *(void***)t;
    *(volatile unsigned int*)&auiParam = DAT_01269cdc;
    void* volatile* slot = (void* volatile*)&pVTable[5];
    ((void(__thiscall*)(FNVTarget*, int, unsigned int)) * slot)(t, aiArg, auiParam);
}
}  // namespace fnv_00ddc9a0

namespace fnv_00ddca30 {
// Thiscall container-of forwarder: the holder pointer lives at this-8, the global
// DAT_01269cdc is written over the 5th stack argument, and the call is tail-jumped
// through vtable slot +0x24 of the target object.
extern unsigned int DAT_01269cdc;

class FNVTarget
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24(int a, int b, int c, int d, unsigned int e);
};

struct FNVHolder
{
    FNVTarget* m_target;
};

class FUN_00ddca30_cls
{
  public:
    void hkDebugDisplayProcess_displayLine(int a, int b, int c, int d, unsigned int e);
};

// @fnv 0x00ddca30
// src: HAVOK_LIB 0x00ddca30
void FUN_00ddca30_cls::hkDebugDisplayProcess_displayLine(int aiArg1, int aiArg2, int aiArg3, int aiArg4, unsigned int auArg5)
{
    FNVHolder* h = (FNVHolder*)((char*)this - 8);
    FNVTarget* t = h->m_target;
    void* vp = *(void**)t;
    unsigned int dat = DAT_01269cdc;
    *(unsigned int volatile*)&auArg5 = dat;
    typedef void(__thiscall * SlotFn)(FNVTarget*, int, int, int, int, unsigned int);
    SlotFn fn = (SlotFn) * (void* volatile*)((char*)vp + 0x24);
    fn(t, aiArg1, aiArg2, aiArg3, aiArg4, auArg5);
}
}  // namespace fnv_00ddca30

struct VirtualReceiver
{
    virtual int method0(int, int, int);
    virtual int method1(int, int, int);
    virtual int method2(int, int, int);
    virtual int method3(int, int, int);
    virtual int method4(int, int, int);
    virtual int method5(int, int, int);
    virtual int method6(int, int, int);
    virtual int method7(int, int, int);
    virtual int method8(int, int, int);
    virtual int method9(int, int, int);
    virtual int method10(int, int, int);
    virtual int method11(int, int, int);
    virtual int method12(int, int, int);
    virtual int method13(int, int, int);
};
struct WrapperObject
{
    int __thiscall hkDebugDisplayProcess_displayAnnotation(int first, int second, int third);
};
// @fnv 0x00ddcab0
// src: HAVOK_LIB 0x00ddcab0
int WrapperObject::hkDebugDisplayProcess_displayAnnotation(int first, int second, int third)
{
    VirtualReceiver* receiver = *(VirtualReceiver**)((char*)this - 8);
    return receiver->method13(first, second, DAT_01269cdc);
}

namespace fnv_00ddcaf0 {
extern char DAT_010d1508[];
extern char DAT_010d7cfc[];
extern char DAT_010d7ed0[];
extern char DAT_010d7eb0[];
extern char DAT_010d7e5c[];
extern char DAT_01269cdc[];
extern char DAT_012681e0[];

class GlobalDispatcher
{
  public:
    void Dispatch(void* arg);
};

class FUN_00ddcaf0_cls
{
  public:
    void* m_vtbl;
    unsigned char unk04[2];
    unsigned short m_06;
    void* m_08;
    unsigned char m_0c;
    unsigned char unk0d[0x13];
    void* m_20;

    void Helper();
    FUN_00ddcaf0_cls* hkDebugDisplayProcess_hkDebugDisplayProcess();
};

// Initializes m_06, m_0c, m_08, m_20, and m_vtbl, calls Helper if DAT_01269cdc is zero, then dispatches m_20 via GlobalDispatcher.
// @fnv 0x00ddcaf0
// src: HAVOK_LIB 0x00ddcaf0
FUN_00ddcaf0_cls* FUN_00ddcaf0_cls::hkDebugDisplayProcess_hkDebugDisplayProcess()
{
    unsigned char flag = 1;
    m_06 = 1;
    unsigned char* pFlag = (unsigned char*)&m_0c;
    *(void* volatile*)&m_08 = DAT_010d1508;
    *(volatile unsigned char*)pFlag = flag;
    *(void* volatile*)&m_20 = DAT_010d7cfc;
    m_vtbl = DAT_010d7ed0;
    m_08 = DAT_010d7eb0;
    *(void* volatile*)&m_20 = DAT_010d7e5c;
    if (*(int*)DAT_01269cdc == 0)
    {
        Helper();
    }
    ((GlobalDispatcher*)*(void**)DAT_012681e0)->Dispatch(&m_20);
    return this;
}
}  // namespace fnv_00ddcaf0

namespace fnv_00ddcbc0 {
void* __cdecl hkDebugDisplayProcess_create();

struct S_00ddcbc0_Factory
{
    void* hkProcessFactory_registerProcess(const char* name, void*(__cdecl* createFn)());
};

extern "C" S_00ddcbc0_Factory* DAT_01269cd0;
extern "C" void* DAT_01269cdc;

// @fnv 0x00ddcbc0
// src: COMMUNITY 0x00ddcbc0
void hkDebugDisplayProcess_registerProcess()
{
    DAT_01269cdc = DAT_01269cd0->hkProcessFactory_registerProcess("Debug Display", hkDebugDisplayProcess_create);
}
}  // namespace fnv_00ddcbc0

template <class T> class HavokElementArray;
class hkVector4;
class hkQsTransform;

struct BehaviorReceiver : TargetIface
{
    virtual void vslot4();
    virtual void vslot5();
    virtual void vslot6();
    virtual int DisplayBehaviorGraph(const HavokElementArray<int>& words, const HavokElementArray<int>& values,
                                     const HavokElementArray<int>& quads, const HavokElementArray<hkVector4>& vectors,
                                     const HavokElementArray<char*>& nodes, const HavokElementArray<int>& states,
                                     const HavokElementArray<int>& transitions, const HavokElementArray<hkQsTransform>& poses);
};

struct BehaviorForwarder
{
    int hkDebugDisplayProcess_updateBehavior(const HavokElementArray<int>& words, const HavokElementArray<int>& values, const HavokElementArray<int>& quads,
                     const HavokElementArray<hkVector4>& vectors, const HavokElementArray<char*>& nodes,
                     const HavokElementArray<int>& states, const HavokElementArray<int>& transitions,
                     const HavokElementArray<hkQsTransform>& poses);
};

// @fnv 0x00ddca00
// src: HAVOK_LIB 0x00ddca00
int BehaviorForwarder::hkDebugDisplayProcess_updateBehavior(const HavokElementArray<int>& words, const HavokElementArray<int>& values,
                                    const HavokElementArray<int>& quads, const HavokElementArray<hkVector4>& vectors,
                                    const HavokElementArray<char*>& nodes, const HavokElementArray<int>& states,
                                    const HavokElementArray<int>& transitions, const HavokElementArray<hkQsTransform>& poses)
{
    OwnerHolder* owner = reinterpret_cast<OwnerHolder*>(reinterpret_cast<char*>(this) - sizeof(OwnerHolder));
    return static_cast<BehaviorReceiver*>(owner->m_target)
        ->DisplayBehaviorGraph(words, values, quads, vectors, nodes, states, transitions, poses);
}

struct TextReceiver : TargetIface
{
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual int displayText(const char* text, int color, int id, int tag);
};

struct TextEntry
{
    void* vftable;
    int hkDebugDisplayProcess_displayText(const char* text, int color, int id, int tag);
};

struct TextForwarder : OwnerHolder, TextEntry
{
};

// @fnv 0x00ddca70
// src: HAVOK_LIB 0x00ddca70
int TextEntry::hkDebugDisplayProcess_displayText(const char* text, int color, int id, int tag)
{
    __assume(this != 0);
    TextForwarder& owner = static_cast<TextForwarder&>(*this);
    TextReceiver* receiver = static_cast<TextReceiver*>(owner.m_target);
    return receiver->displayText(text, color, id, g_01269cdc);
}

struct ImmediateReceiver : TargetIface
{
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
    virtual int GetTypeItem();
};

struct ImmediateForwarder
{
    int hkDebugDisplayProcess_holdImmediate();
};

struct ImmediateOwner : OwnerHolder
{
    ImmediateForwarder m_interface;
};

// @fnv 0x00ddcae0
// src: HAVOK_LIB 0x00ddcae0
int ImmediateForwarder::hkDebugDisplayProcess_holdImmediate()
{
    ImmediateOwner* owner = reinterpret_cast<ImmediateOwner*>(reinterpret_cast<char*>(this) - sizeof(OwnerHolder));
    return static_cast<ImmediateReceiver*>(owner->m_target)->GetTypeItem();
}
