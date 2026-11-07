#include <xmmintrin.h>
typedef ::__m128 LocalM128;
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkResult.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#include <cstddef>
// Preserve the unit's intrinsic layout: the SDK union's arrays enable /GS.
#define _INCLUDED_MM2


typedef ::__m128 LocalM128;
extern "C"{
using ::_mm_add_ss;
using ::_mm_add_ps;
using ::_mm_sub_ss;
using ::_mm_sub_ps;
using ::_mm_mul_ss;
using ::_mm_mul_ps;
using ::_mm_rsqrt_ss;
using ::_mm_andnot_ps;
using ::_mm_cmpeq_ss;
using ::_mm_shuffle_ps;
using ::_mm_set_ss;
using ::_mm_load_ss;};

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
typedef std::size_t hk_size_t;

#include "../../../../../../../include/FinishingFlag.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkColor.h"
#include "../../../../../../../include/hkBuiltinTypeRegistry.h"
#include "../../../../../../../include/hkClass.h"
#include "../../../../../../../include/hkVtableClassRegistry.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"

#include "../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpMaxSizeMotion.h"
#include "../../../../../../../include/hkpPhantomListener.h"
#include "../../../../../../../include/hkpPhysicsContext.h"
#include "../../../../../../../include/hkpRigidBody.h"
#include "../../../../../../../include/hkpWorldObject.h"

#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkContactPoint.h"
#include "../../../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../../../include/hkProcess.h"
#include "../../../../../../../include/hkProcessContext.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkStringPtr.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpAction.h"
#include "../../../../../../../include/hkpActionListener.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpConstraintListener.h"
#include "../../../../../../../include/hkpEntityListener.h"
#include "../../../../../../../include/hkpKeyframedRigidMotion.h"
#include "../../../../../../../include/hkpLinkedCollidable.h"
#include "../../../../../../../include/hkpMaterial.h"
#include "../../../../../../../include/hkpMotion.h"
#include "../../../../../../../include/hkpUnaryAction.h"
#include "../../../../../../../include/hkpVehicleData.h"
#include "../../../../../../../include/hkpVehicleInstance.h"
#include "../../../../../../../include/hkpVehicleWheelCollide.h"
#include "../../../../../../../include/hkpWorldDeletionListener.h"
#include "../../../../../../../include/hkpPhysicsContextWorldListener.h"
#include "../../../../../../../include/hkpWorldPostSimulationListener.h"
#include "../../../../../../../include/hkpWorldViewerBase.h"


// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl D625A0MemMove(void* dst, const void* src, unsigned int nbytes);

extern char d_010d17d0;
char *Hkpvehicleviewer_GetD010d17d0Address();
struct ItemSink;
typedef void (__thiscall* ProcessFn)(ItemSink* apThis, void* apItem);
struct ItemSinkVtbl {
    void* fn00;
    ProcessFn Process;
};
struct ItemSink {
    ItemSinkVtbl* m_pVtbl;
};
struct ItemHolder {
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
    void** m_ppItems;
    int m_iArrayLength;
};
struct FUN_00d634e0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ItemSink m_kSink;
    ItemHolder* m_pHolder;

    void ProcessItems();
};
struct HeadPart {
    virtual void h00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct OurPart {
    virtual void o00();

    int m_i04;

    void RegisterAndNotify(struct Registry* apRegistry);
};
struct NotifyTarget {
    virtual void v00();
    virtual void Notify(void* apItem);
};
struct SecondTarget {
    virtual void w00();
};
struct Container : HeadPart, OurPart, NotifyTarget, SecondTarget {
};
struct ItemList {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void** m_ppItems;
    int m_iArrayLength;

    void FUN_00c905b0();
};
struct Registry {
    void hkpWorld_addActionListener(NotifyTarget* apTarget);
    void hkpWorld_addWorldPostSimulationListener(SecondTarget* apTarget);
    ItemList* hkpWorld_getWorldAsOneSystem();
};
struct Factory {
    void* hkProcessFactory_registerProcess(const char*, void*);
};
extern void* DAT_01268fcc;
extern Factory* DAT_01269cd0;
extern const char DAT_010d17c4;
extern void AllocAndInitObject();
void __cdecl Object_UpdateFields_00d63da0();
extern int g_D63DC0Value;
int __cdecl Object_GetG_D63DC0Value_00d63dc0();
// PassMembersToTarget - forwarding stub for a "container of" style object.
//
// `this` points at a sub-object that lives 0x20 bytes into a bigger object;
// the code recovers the owner pointer (this - 0x20) and passes it on to the
// two Target methods, which are called with the owner as their `this`.
struct Target {
    void hkpWorld_removeActionListener(void* apArg);
    void ClearValue(void* apArg);
};
struct FUN_00d63480_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void PassMembersToTarget(Target* apTarget);
};
// FUN_00d63c50 - the constructor of the Havok vehicle viewer
// (hkpVehicleViewer).
//
// The base class constructor (hkpWorldViewerBase) is called first with the
// argument that was passed in; afterwards the vtable pointer of the two
// listener bases and the vtable pointers of the viewer's own five base
// sub-objects are stored, and the last three members are initialised.
struct FUN_00d63c50 : public hkpWorldViewerBase {
    FUN_00d63c50(const hkArray<hkProcessContext*>& contexts);
    int* volatile m_vtbl28;   // +0x28
    int* volatile m_vtbl2c;   // +0x2c
    volatile int m_30;        // +0x30
    volatile int m_34;        // +0x34
    volatile int m_38;        // +0x38
};
// the vftables of the class and of its bases
extern int DAT_010cb1d4;
extern int DAT_010ccf7c;
extern int DAT_010d1854;
extern int DAT_010d1834;
extern int DAT_010d1824;
extern int DAT_010d1814;
extern int DAT_010d1804;
void* __cdecl hkMemoryRouter_getInstance() throw();
struct S_D { virtual ~S_D() throw() {} };
struct S_E { virtual ~S_E() throw() {} };
struct S_Arr
{
    void** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void clear() throw()
    {
        hkMemoryAllocator& heap = ((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0) heap.bufFree(m_data, (m_cap & 0x3fffffff) * (int)sizeof(void*));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
struct FUN_00d63cb0 : hkpWorldViewerBase, S_D, S_E
{
    S_Arr m30;
    virtual ~FUN_00d63cb0() throw();
};

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem) throw();

class VehicleViewerD635 {
public:
    void AddVehicle(hkReferencedObject* pkObj);

    int unk00, unk04;
    hkArray<hkReferencedObject*> m_ppVehicles;
};
// VC9 adjustor thunk: dual-slot override + static global forces
// [thunk]: TO::FUN_00d63dd0`adjustor{32}' = sub ecx,0x20; jmp TO::FUN_00d63dd0
struct Prim {
    virtual void FUN_00d63dd0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
};
struct B1 {
    virtual void FUN_00d63dd0();
};
struct TO : Prim, B1 {
// @fnv 0x00d63dd0
    virtual void FUN_00d63dd0();
};
static TO g_thunk;
// sub ecx,8; jmp Destroy
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (8 = vptr + one int field).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d63de0();
    int unk04;
};
struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d63de0();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d63de0
// src: GUESS 0x00d63de0 (confidence: low)
    virtual void AdjustThisAndForward_00d63de0();
};
Derived::Derived()
{
}
struct Parent;
struct FirstBase {
    virtual Parent* FUN_00d63df0(unsigned int flags)=0;
    unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
};
struct Receiver {
    virtual Parent* FUN_00d63df0(unsigned int flags)=0;
};
struct Parent : FirstBase,Receiver {
    Parent();
// @fnv 0x00d63df0
    virtual Parent* FUN_00d63df0(unsigned int flags);
};
Parent::Parent() {}
// FUN_00d63e00 : MSVC this-adjusting thunk  (sub ecx, 0x2c ; jmp <impl>)
struct A1_00d63e00 {
    A1_00d63e00();
    virtual void AdjustThisAndForward_00d63e00();
    char pad[0x28];
};
struct A2_00d63e00 {
    A2_00d63e00();
    virtual void AdjustThisAndForward_00d63e00();
};
struct Own_00d63e00 : A1_00d63e00, A2_00d63e00 {
    Own_00d63e00();
    virtual void key_fn();
// @fnv 0x00d63e00
// src: GUESS 0x00d63e00 (confidence: low)
    void AdjustThisAndForward_00d63e00();
};
Own_00d63e00::Own_00d63e00() { }
void Own_00d63e00::key_fn() { }
Own_00d63e00* make_00d63e00() { static Own_00d63e00 o; return &o; }



// Inline definitions stay in this unit to preserve the original code generation.
inline hkSimdReal::hkSimdReal() {}
// Select scalar construction without the shared header's ambiguous overloads.
__forceinline hkSimdReal scalarComponent(float value)
{
hkSimdReal result;
reinterpret_cast<LocalM128&>(result)=_mm_load_ss(&value);
return result;
}
__forceinline const LocalM128& hkSimdReal::getQuad() const
{
return reinterpret_cast<const LocalM128&>(*this);
}
__forceinline LocalM128 hkSimdReal::broadcast() const
{
return _mm_shuffle_ps(getQuad(),getQuad(),0);
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable()
{
return getEnd()<getCapacityMinus16();
}
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end=ptr; }

extern "C" void __cdecl __debugbreak(void);

typedef hkUint16 hkObjectIndex;__forceinline hkLong __cdecl hkGetByteOffset(const void*base,const void*pntr)
{
return hkLong(pntr)-hkLong(base);
}
template<typename TYPE>
__forceinline TYPE*__cdecl hkAddByteOffset(TYPE*base,hkLong offset)
{
return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset);
}

class hkClass;

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
extern hkThreadLocalData<hkMonitorStream*> DAT_0126835c;
return *DAT_0126835c.getData();
}
template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};
__forceinline void*hkStackMemory::allocateStack(int numBytes,const char*what)
{
void*current=m_next;
m_next=hkAddByteOffset(current,numBytes);
return current;
}
__forceinline void hkStackMemory::deallocateStack(void*p)
{
;
m_next=p;
}

__forceinline hkMemoryRouter& __cdecl hkMemoryRouter::getInstance()
{
return *static_cast<hkMemoryRouter*>(::hkMemoryRouter_getInstance());
}

template<typename TYPE>
__forceinline TYPE*__cdecl hkAllocateStack(int n,const char*what=0)
{
hkMemoryRouter&mem=hkMemoryRouter::getInstance();
return static_cast<TYPE*>(mem.stack().allocateStack((((n*TypeSizeConstant<TYPE>::val)+((128)-1))&(~((128)-1))),what));
}
template<typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE*ptr)
{
hkMemoryRouter::getInstance().stack().deallocateStack(static_cast<void*>(ptr));
}

template<class TYPE>
class ReferenceCountedPointer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
private:
TYPE*m_pRetainedObject;};
template<typename T>
class ResizableArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
enum
{
CAPACITY_MASK=hkUint16(0x3fff),
FLAG_MASK=hkUint16(0xC000),
DONT_DEALLOCATE_FLAG=hkUint16(0x8000),
LOCKED_FLAG=hkUint16(0x4000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
public:
ResizableArray(FinishingFlag f){}
};
typedef LocalM128 hkQuadReal;
typedef const hkVector4&hkVector4Parameter;

typedef const hkSimdReal&hkSimdRealParameter;
extern const LocalM128 DAT_010c71e0;

inline hkQuadReal&hkVector4::getQuad()
{
return m_vComponents;
}
inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setMul4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
inline void hkVector4::addMul4(const hkVector4&x,const hkVector4&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&x,const hkVector4&y)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4::setCross(const hkVector4& v0,const hkVector4& v1)
{
hkQuadReal cross0=_mm_mul_ps(
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,0xd2),
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,0xc9));
hkQuadReal cross1=_mm_mul_ps(
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,0xc9),
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,0xd2));
m_vComponents=_mm_sub_ps(cross0,cross1);
}
inline hkSimdReal hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
__declspec(align(16)) hkSimdReal result;
reinterpret_cast<LocalM128&>(result)=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);
return result;}
__forceinline LocalM128 lengthInverse3(const hkVector4& v)
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=v.dot3(v).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);
}
inline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3(*this);
lenInv=_mm_shuffle_ps(lenInv,lenInv,0);
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline void hkVector4::broadcast(int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(m_vComponents,m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
}
inline void hkVector4::setBroadcast(const hkVector4&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion&quat,const hkVector4&direction)
{
hkVector4 minusHalf;minusHalf.getQuad()=reinterpret_cast<const LocalM128&>(DAT_010c71e0);
hkVector4 qreal;
qreal.setBroadcast(quat.getImag(),3);
hkVector4 q2minus1;
q2minus1.setAddMul4(minusHalf,qreal,qreal);
hkVector4 ret;
ret.setMul4(direction,q2minus1);
hkVector4 imagDotDir;
imagDotDir.getQuad()=quat.getImag().dot3(direction).getQuad();
imagDotDir.broadcast(0);
ret.addMul4(imagDotDir,quat.getImag());
hkVector4 imagCrossDir;
imagCrossDir.setCross(quat.getImag(),direction);
ret.addMul4(qreal,imagCrossDir);
this->setAdd4(ret,ret);}
inline const hkVector4&hkQuaternion::getImag()const
{
return *reinterpret_cast<const hkVector4*>(this);
}
inline hkQuaternion::hkQuaternion(const hkVector4&axis,hkReal angle)
{
hkQuaternion_setAxisAngle(axis,angle);
}

inline const hkVector4&hkContactPoint::getPosition()const
{
return m_vContactPosition;
}
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};

class hkDisplayGeometry;
// Keep the recipe's method name while overriding the shared callback.
class VehicleViewerPostSimulationListener : public hkpWorldPostSimulationListener
{
public:
virtual void step_00d63680(hkpWorld* world)=0;
virtual void postSimulationCallback(hkpWorld* world) { step_00d63680(world); }
};
class hkpVehicleViewer:
public hkpWorldViewerBase,
public hkpActionListener,
public VehicleViewerPostSimulationListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;hkMemoryRouter::getInstance().heap().blockFree(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
static hkProcess*__cdecl create(const hkArray<hkProcessContext*>&contexts);
static void __cdecl RegisterViewer();
virtual int GetOperationType(){return (int)::DAT_01268fcc;}
virtual void init();
static inline const char*__cdecl getName(){return "Vehicles";}
protected:
hkpVehicleViewer(const hkArray<hkProcessContext*>&contexts);
virtual ~hkpVehicleViewer() throw();
virtual void WorldAddedCallback(hkpWorld*world);
virtual void WorldRemovedCallback(hkpWorld*world);
virtual void step_00d63680(hkpWorld*world);
virtual void ActionAddedCallback(hkpAction*action);
virtual void ActionRemovedCallback(hkpAction*action);
protected:
static int m_ucOperationType;
static const int ms_iProcessTag;
hkArray<class hkpVehicleInstance*>m_ppVehicles;
};

template<typename T>
class PointerArrayView
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline T&operator[](int i);protected:
__forceinline PointerArrayView(){}
hkPadSpu<T*>m_data;};
template<typename T>
class HkDynamicArray:public PointerArrayView<T>
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline HkDynamicArray(int n,const char*what=0);
__forceinline ~HkDynamicArray();};
template<typename T>
__forceinline HkDynamicArray<T>::HkDynamicArray(int capacity,const char*what)
{
this->m_data=hkAllocateStack<T>(capacity);
;
}
template<typename T>
__forceinline HkDynamicArray<T>::~HkDynamicArray()
{
hkDeallocateStack(this->m_data.val());
}
template<typename T>
__forceinline T&PointerArrayView<T>::operator[](int i)
{
;
return m_data[i];
}
// @fnv 0x00d63680
// src: EXE 0x00d63680
void hkpVehicleViewer::step_00d63680(hkpWorld*world)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "hkpVehicleViewer::step";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock14;
const int numVehicles=m_ppVehicles.m_iElementCount;
const int numWheelSegments=12;
for(int i=0;i<numVehicles;i++)
{
const hkpVehicleInstance*vehicle=m_ppVehicles.m_data[i];
const int numWheels=vehicle->m_kWheelInfoArray.m_iElementCount;
HkDynamicArray<hkVector4>centerPoint(numWheels);
for(int w=0;w<numWheels;w++)
{
const hkpVehicleData::WheelComponentParams&wheelParam=vehicle->m_data->m_kWheelParams.m_data[w];
const hkpVehicleInstance::WheelInfo&wheel=reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(vehicle->m_kWheelInfoArray.m_data)[w];
const hkVector4&contactPoint=wheel.m_vContactPoint.getPosition();
const hkVector4&hardPoint=wheel.m_vContactPointVelocity;
const int collidableId=(wheel.m_pUserData)?(int)(hkUlong)(static_cast<const hkpCollidable*>(&wheel.m_pUserData->m_kCollidable)):0;
reinterpret_cast<hkDebugDisplayHandler*>(unk10)->DisplayLine(contactPoint,hardPoint,(wheel.m_pUserData)? hkColor::RED:hkColor::ROSYBROWN,collidableId,(int)::DAT_01268fcc);
centerPoint[w].setAddMul4(contactPoint,wheel.m_vHardPointWs,scalarComponent(-wheelParam.m_fSphereRadius));
{
hkVector4 spoke;spoke=wheel.m_vHardPointWs;
hkQuaternion spokeRotation(wheel.m_vSuspensionDirectionWs,-wheel.m_fSpinAngle);
spoke.SetRotatedDirection(spokeRotation,spoke);
spoke.normalize3();
spoke.mul4(scalarComponent(wheelParam.m_fSphereRadius));
hkVector4 start;start.setAdd4(centerPoint[w],spoke);
hkVector4 end;end.setSub4(centerPoint[w],spoke);
reinterpret_cast<hkDebugDisplayHandler*>(unk10)->DisplayLine(start,end,(wheel.m_pUserData)? hkColor::WHITESMOKE:hkColor::ROSYBROWN,collidableId,(int)::DAT_01268fcc);
}
hkVector4 spokes[numWheelSegments];
// Select the reference overload to retain the original inlining.
(spokes[0].*static_cast<void (hkVector4::*)(const hkSimdReal&,const hkVector4&)>(&hkVector4::setMul4))(scalarComponent(wheelParam.m_fSphereRadius),wheel.m_vHardPointWs);
hkQuaternion spokeRotation(wheel.m_vSuspensionDirectionWs,360.0 / numWheelSegments*0.017453292f);
for(int s=1;s<numWheelSegments+2;s++)
{
if(s<numWheelSegments)
{
spokes[s].SetRotatedDirection(spokeRotation,spokes[s-1]);
}
if(s<=numWheelSegments)
{
spokes[s-1].add4(centerPoint[w]);
}
if(s>=2)
{
reinterpret_cast<hkDebugDisplayHandler*>(unk10)->DisplayLine(spokes[(s-2)% numWheelSegments],spokes[(s-1)% numWheelSegments],(wheel.m_pUserData)? hkColor::WHITESMOKE:hkColor::ROSYBROWN,collidableId,(int)::DAT_01268fcc);
}
}
}
const int numAxles=vehicle->m_data->m_kNumWheelsPerAxle.m_iElementCount;
for(int axle=0;axle<numAxles;axle++)
{
hkVector4 a;
hkVector4 b;
bool firstTimeThrough=true;
const int totalWheelsOnThisAxle=vehicle->m_data->m_kNumWheelsPerAxle.m_data[axle];
int wheelsFoundOnThisAxle=0;
for(int w=0;w<numWheels;w++)
{
const hkpVehicleData::WheelComponentParams&wheelParam=vehicle->m_data->m_kWheelParams.m_data[w];
const hkpVehicleInstance::WheelInfo&wheel=reinterpret_cast<const hkpVehicleInstance::WheelInfo*>(vehicle->m_kWheelInfoArray.m_data)[w];
const int collidableId=(wheel.m_pUserData)?(int)(hkUlong)(static_cast<const hkpCollidable*>(&wheel.m_pUserData->m_kCollidable)):0;
if(wheelParam.m_iAxle !=axle)continue;
wheelsFoundOnThisAxle++;
a=b;
b=centerPoint[w];
if(firstTimeThrough)
{
firstTimeThrough=false;
}
else
{
reinterpret_cast<hkDebugDisplayHandler*>(unk10)->DisplayLine(a,b,hkColor::YELLOWGREEN,collidableId,(int)::DAT_01268fcc);
}
if(wheelsFoundOnThisAxle==totalWheelsOnThisAxle)break;
}
}
}
}
