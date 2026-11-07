#include "../../../../../../../../include/hkAabbUint32.h"
#include <new>
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#include "../../../../../../../../include/LIST_ENTRY32.h"
#include "../../../../../../../../include/LIST_ENTRY64.h"
#include "../../../../../../../../include/hkKdTreeCastCollector.h"
#include "../../../../../../../../include/hkRotation.h"
#include "../../../../../../../../include/hkpFixedBufferCdPointCollector.h"
#include "../../../../../../../../include/hkAabb.h"
#include "../../../../../../../../include/hkJobType.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../../include/hkStepInfo.h"
#include "../../../../../../../../include/hkAabbTreeQueryUtils.h"
#include "../../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkp3AxisSweep.h"
#include "../../../../../../../../include/hkpBroadPhase.h"
#include "../../../../../../../../include/hkpBroadPhaseCastCollector.h"
#include "../../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../../include/hkpGroupFilter.h"
#include "../../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../../include/hkpRayShapeCollectionFilter.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpShapeCollectionFilter.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkMultiThreadCheck.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../../include/hkpCdPointCollector.h"
// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/collisionquery/cpu/hkpcpuworldgetclosestpointsjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00df6a30_Inner { int unk0; float unk4; };
struct S_00df6a30 {
    int unk0;
    int unk4;
    S_00df6a30_Inner* unk8;
    float EvaluateValue_00df6a30();
};
struct DF6B10Event {
    int unk00;
    int unk04;
    int unk08;
    void* m_kCollisionBody;
};
struct DF6B10Primary {
    virtual void vfunc00();
};
struct DF6B10Listener {
    virtual int HandleEvent(DF6B10Event* event);
};
struct DF6B10Object : DF6B10Primary, DF6B10Listener {
    int handleBody(void* body);

    virtual int HandleEvent(DF6B10Event* event);
};
struct FUN_00df6a40_inner
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
class FUN_00df6a40_cls
{
public:
    int m_00;
    int m_04;
    FUN_00df6a40_inner* m_08;

    bool* hkCpuWorldGetClosestPointsCollector_hasHit(bool* out);
};


struct DF6A60CdPointCollector {
    int unk00;
    float m_fEarlyOutDistance;
};
struct DF6A60LinearCastInput;
typedef void (__cdecl* DF6A60LinearCastFunc)(const hkpCollidable& bodyA, const hkpCollidable& bodyB, const DF6A60LinearCastInput& input, DF6A60CdPointCollector& collector);
struct DF6A60AgentFuncs {
    DF6A60LinearCastFunc m_pLinearCastFunc;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
};
struct DF6A60Dispatcher {
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
    unsigned char m_agent2TypeMap[64][32];
    int unk9A0;
    int unk9A4;
    DF6A60AgentFuncs m_agent2Funcs[1];

    DF6A60LinearCastFunc getLinearCastFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pLinearCastFunc;
    }
};
struct DF6A60LinearCastInput {
    const DF6A60Dispatcher* m_pCollisionDispatcher;
};


struct DF6A60CastCollector {
    int unk00;
    int unk04;
    int unk08;
    const hkpCollisionFilter* m_iFilter;
    DF6A60CdPointCollector* m_pPointCollector;
    const hkpCollidable* m_pCollidableA;
    int m_shapeTypeA;
    int unk1C;
    DF6A60LinearCastInput m_pRayCastInput;

    float LinearCastAgainst(const hkpCollidable* collidableB);
};
// GetHelperResultForOffset: thiscall member that forwards a byte-adjusted pointer to a
// sibling thiscall helper (the helper receives `this` in ecx and pops its
// single stack argument).
struct FUN_00df6af0_cls {
    float Helper(int value);
    float GetHelperResultForOffset(int a1, int a2);
};
struct SiblingCls_df6a60 {
    float Call(int a);
};
struct FUN_00df6b30_cls {
    unsigned char* hkCpuWorldGetClosestPointsCollector_addMidPhaseHit(unsigned char* out, int a);
};
extern float DAT_0104da48;
extern int DAT_0108f288;
extern "C" __declspec(dllimport) long __stdcall DAT_00fdf1ec(long volatile*, long);
struct CopyQuad { int x; int y; int z; int w; };
struct __declspec(align(16)) QueryPoint { CopyQuad parts[7]; };
struct QueryInput {
    const DF6A60Dispatcher* dispatcher;
    int unk04;
    float tolerance;
    int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C;
};
struct QueryCollector {
    int* table;
    float earlyOut;
    QueryPoint* base;
    QueryPoint* next;
    int capacity;
    int count;
    QueryCollector(QueryPoint* b, int c) : earlyOut(DAT_0104da48), base(b), next(b), capacity(c), count(0), table(&DAT_0108f288) {}
};
struct QueryJob {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    float tolerance;
};
struct PairCommand {
    const hkpCollidable* a;
    const hkpCollidable* b;
    QueryPoint* results;
    int capacity;
    int numResults;
    long volatile* sharedIndex;
    int unk18; int unk1C;
};
typedef void (__cdecl* QueryFunction)(const hkpCollidable&, const hkpCollidable&, const QueryInput&, QueryCollector&);
inline QueryPoint* allocateResults(PairCommand* command, const QueryCollector& collector)
{
    {
        int hits = collector.count;
        int start = DAT_00fdf1ec(command->sharedIndex, hits);
        if (start + hits <= command->capacity)
            return command->results + start;
        DAT_00fdf1ec(command->sharedIndex, -hits);
        return 0;
    }
}
void hkCpuPairGetClosestPointsImplementation(const QueryJob* job, const QueryInput* source, PairCommand* commands, int count);
// FUN_00df6db0 - base-class adjustment thunk (8 bytes):
//
//     sub ecx, 4
//     jmp  <the derived class' implementation of the overridden virtual>
//
// The secondary base sub-object starts four bytes into the derived object, so
// the vtable slot that the base contributes to the derived class holds an
// adjustor thunk: it moves `this` back to the derived object and tail-calls
// the derived implementation.  The implementation itself lives in another
// translation unit, so it is only declared here.
struct PrimaryBase {
    PrimaryBase();
    virtual void FUN_00df6db0(int flag);
};
struct SecondaryBase {
    SecondaryBase();
    virtual void FUN_00df6db0(int flag);
};
struct Derived : public PrimaryBase, public SecondaryBase {
    Derived();
// @fnv 0x00df6db0
    virtual void FUN_00df6db0(int flag);
};
PrimaryBase::PrimaryBase() {}
SecondaryBase::SecondaryBase() {}
Derived::Derived() : PrimaryBase(), SecondaryBase() {}
struct DF6DC0Primary {
    virtual void vfunc00();
    virtual void AdjustThisAndForward_00df6dc0();

    int unk04;
};
struct DF6DC0Secondary {
    virtual void AdjustThisAndForward_00df6dc0();
};
struct DF6DC0Object : DF6DC0Primary, DF6DC0Secondary {
    DF6DC0Object();

// @fnv 0x00df6dc0
// src: GUESS 0x00df6dc0 (confidence: low)
    virtual void AdjustThisAndForward_00df6dc0();
};
DF6DC0Object::DF6DC0Object()
{
}
struct S_00df6dd0_A { virtual ~S_00df6dd0_A() {} };
struct S_00df6dd0_B { virtual void Func(); ~S_00df6dd0_B() {} };
struct S_00df6dd0_C { virtual void Func2(); ~S_00df6dd0_C() {} };
struct FUN_00df6dd0 : S_00df6dd0_A, S_00df6dd0_B, S_00df6dd0_C {
    FUN_00df6dd0();
    virtual ~FUN_00df6dd0();
};
FUN_00df6dd0::~FUN_00df6dd0() {}

typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef signed int hkInt32;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;
class hkClass;
typedef int hkBool32;

class hkStatisticsCollector;
// hkTypeIsPod, hkArray, hkContainerHeapAllocator / hkContainerTempAllocator: include/hkArray.h

typedef __m128 hkQuadReal;

typedef const hkVector4&hkVector4Parameter;
inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}

__forceinline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getStart() { return m_start.val(); }
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable()
{
    return getEnd() < getCapacityMinus16();
}
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline hkpBroadPhaseCastCollector::~hkpBroadPhaseCastCollector() {}

__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
__forceinline hkAabb::hkAabb() {}
#include "../../../../../../../../include/hkAabbUint32.h"

class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;

__forceinline hkpShapeType hkpShape::getType()const
{
return static_cast<hkpShapeType>(*reinterpret_cast<const hkUint32*>(&m_type));
}
__forceinline void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
#include "../../../../../../../../include/hkpCollisionQualityInfo.h"
class hkpCollisionDispatcher;

class hkpConvexListFilter;
struct RealIntegerData;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
void setTolerance(hkReal t){m_fScalar=t;}
public:
hkPadSpu<hkpCollisionDispatcher*>m_pCollisionDispatcher;
hkPadSpu<hkBool32>m_collisionQuality;
hkPadSpu<hkReal>m_fScalar;
hkPadSpu<const hkpCollisionFilter*>m_iFilter;
hkPadSpu<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
mutable hkPadSpu<hkBool32>m_bCreatePredictiveAgents;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
__forceinline const hkpShape*hkpCollidable::getShape()const
{
return m_pCollisionShape;
}
struct ContactPointPair;
void hkpCdPointCollector::reset()
{
m_fEarlyOutDistance=3.40282e+38f;
}
hkpCdPointCollector::hkpCdPointCollector()
{
reset();
}
hkpCdPointCollector::~hkpCdPointCollector()
{
}
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkPadSpu<hkpCollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;
void*m_pCollisionFilter;
hkBool m_bEnableDeprecatedWelding;
RealIntegerData*m_pConfiguration;};struct ShapeSweepParameters:public CollisionAgentContext
{
inline ShapeSweepParameters();
hkVector4 m_path;
hkReal m_fMaxExtraPenetration;
hkReal m_fStartPointTolerance;
RealIntegerData*m_pConfiguration;};
ShapeSweepParameters::ShapeSweepParameters()
{
m_fMaxExtraPenetration=1.192092896e-07F;
}
extern "C"{
typedef unsigned long ULONG;
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef void*LPVOID;
extern "C"{
extern "C"{}
extern "C"{}
typedef void*PVOID;
typedef char CHAR;
typedef long LONG;
typedef wchar_t WCHAR;
typedef const WCHAR*LPCWSTR,*PCWSTR;
typedef unsigned __int64 ULONGLONG;
typedef union _ULARGE_INTEGER{
struct{
DWORD LowPart;
DWORD HighPart;
};
struct{
DWORD LowPart;
DWORD HighPart;
}u;
ULONGLONG QuadPart;
}ULARGE_INTEGER;
typedef struct _LUID{
DWORD LowPart;
LONG HighPart;
}LUID,*PLUID;
typedef struct _LIST_ENTRY{
struct _LIST_ENTRY*Flink;
struct _LIST_ENTRY*Blink;
}LIST_ENTRY,*PLIST_ENTRY,*PRLIST_ENTRY;


typedef struct _GUID{
unsigned long Data1;
unsigned short Data2;
unsigned short Data3;
unsigned char Data4[8];
}GUID;
extern "C"{
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
extern "C++"{}
}
extern "C"{}
typedef struct _WOW64_FLOATING_SAVE_AREA{
DWORD ControlWord;
DWORD StatusWord;
DWORD TagWord;
DWORD ErrorOffset;
DWORD ErrorSelector;
DWORD DataOffset;
DWORD DataSelector;
BYTE RegisterArea[80];
DWORD Cr0NpxState;
}WOW64_FLOATING_SAVE_AREA;
typedef struct _WOW64_CONTEXT{
DWORD ContextFlags;
DWORD Dr0;
DWORD Dr1;
DWORD Dr2;
DWORD Dr3;
DWORD Dr6;
DWORD Dr7;
WOW64_FLOATING_SAVE_AREA FloatSave;
DWORD SegGs;
DWORD SegFs;
DWORD SegEs;
DWORD SegDs;
DWORD Edi;
DWORD Esi;
DWORD Ebx;
DWORD Edx;
DWORD Ecx;
DWORD Eax;
DWORD Ebp;
DWORD Eip;
DWORD SegCs;
DWORD EFlags;
DWORD Esp;
DWORD SegSs;
BYTE ExtendedRegisters[512];
}WOW64_CONTEXT;
typedef DWORD ACCESS_MASK;
typedef struct _GENERIC_MAPPING{
ACCESS_MASK GenericRead;
ACCESS_MASK GenericWrite;
ACCESS_MASK GenericExecute;
ACCESS_MASK GenericAll;
}GENERIC_MAPPING;
typedef struct _LUID_AND_ATTRIBUTES{
LUID Luid;
DWORD Attributes;
}SID_AND_ATTRIBUTES,*PSID_AND_ATTRIBUTES;
typedef enum{
LT_DONT_CARE,
LT_LOWEST_LATENCY
}BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;
typedef struct _IMAGE_THUNK_DATA64{
union{
ULONGLONG ForwarderString;
ULONGLONG Function;
ULONGLONG Ordinal;
ULONGLONG AddressOfData;
}u1;
}IMAGE_THUNK_DATA64;
typedef struct _IMAGE_THUNK_DATA32{
union{
DWORD ForwarderString;
DWORD Function;
DWORD Ordinal;
DWORD AddressOfData;
}u1;
}IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;
typedef struct _OSVERSIONINFOA{
DWORD dwOSVersionInfoSize;
DWORD dwMajorVersion;
DWORD dwMinorVersion;
DWORD dwBuildNumber;
DWORD dwPlatformId;
CHAR szCSDVersion[128];
}OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;
typedef struct _OSVERSIONINFOEXA{
DWORD dwOSVersionInfoSize;
DWORD dwMajorVersion;
DWORD dwMinorVersion;
DWORD dwBuildNumber;
DWORD dwPlatformId;
CHAR szCSDVersion[128];
WORD wServicePackMajor;
WORD wServicePackMinor;
WORD wSuiteMask;
BYTE wProductType;
BYTE wReserved;
}OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;
typedef struct _OSVERSIONINFOEXW{
DWORD dwOSVersionInfoSize;
DWORD dwMajorVersion;
DWORD dwMinorVersion;
DWORD dwBuildNumber;
DWORD dwPlatformId;
WCHAR szCSDVersion[128];
WORD wServicePackMajor;
WORD wServicePackMinor;
WORD wSuiteMask;
BYTE wProductType;
BYTE wReserved;
}OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
typedef struct _RTL_CRITICAL_SECTION_DEBUG{
WORD Type;
WORD CreatorBackTraceIndex;
struct _RTL_CRITICAL_SECTION*CriticalSection;
LIST_ENTRY ProcessLocksList;
DWORD EntryCount;
DWORD ContentionCount;
DWORD Flags;
WORD CreatorBackTraceIndexHigh;
WORD SpareWORD;
}RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;
typedef struct _RTL_SRWLOCK{
PVOID Ptr;
}RTL_CONDITION_VARIABLE,*PRTL_CONDITION_VARIABLE;
typedef struct _ASSEMBLY_FILE_DETAILED_INFORMATION{
DWORD ulFlags;
DWORD ulFilenameLength;
DWORD ulPathLength;
PCWSTR lpFileName;
PCWSTR lpFilePath;
}TAPE_DRIVE_PROBLEM_TYPE;
extern "C"{
extern "C"{
typedef ULONG SAVEPOINT_ID,*PSAVEPOINT_ID;
typedef struct _TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT{
SAVEPOINT_ID SavepointId;
}TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT,*PTRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT;
typedef struct _TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT{
ULONG MarshalCookie;
GUID UOW;
}TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT,*PTRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT;}
}
}
typedef struct _RECTL
{
LONG left;
LONG top;
LONG right;
LONG bottom;
}RECTL,*PRECTL,*LPRECTL;
typedef struct tagPOINT
{
LONG x;
LONG y;
}FILETIME,*PFILETIME,*LPFILETIME;}
extern "C"{
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef struct _DCB{
DWORD DCBlength;
DWORD BaudRate;
DWORD fBinary:1;
DWORD fParity:1;
DWORD fOutxCtsFlow:1;
DWORD fOutxDsrFlow:1;
DWORD fDtrControl:2;
DWORD fDsrSensitivity:1;
DWORD fTXContinueOnXoff:1;
DWORD fOutX:1;
DWORD fInX:1;
DWORD fErrorChar:1;
DWORD fNull:1;
DWORD fRtsControl:2;
DWORD fAbortOnError:1;
DWORD fDummy2:17;
WORD wReserved;
WORD XonLim;
WORD XoffLim;
BYTE ByteSize;
BYTE Parity;
BYTE StopBits;
char XonChar;
char XoffChar;
char ErrorChar;
char EofChar;
char EvtChar;
WORD wReserved1;
}JIT_DEBUG_INFO,*LPJIT_DEBUG_INFO;
__declspec(dllimport)
LPVOID
__stdcall
TlsGetValue(
DWORD dwTlsIndex
);}
class PhysicsSimulationContext
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
CRITICAL_SECTION m_kCriticalSection;};
class BusyWaitingSemaphore
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
protected:
protected:void*m_pCompletionSemaphore;};
typedef BusyWaitingSemaphore hkSemaphoreBusyWait;
template<typename T>
class CapacityGrowingArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
inline void increaseCapacity();};
typedef hkUint8 hkJobSubType;
struct JobDescriptor
{__declspec(align(16))hkJobSubType m_ucSubType;};
struct JobQueueConstructionInfo
{};
class JobDispatcher
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum{JOB_QUEUE_ENTRY_SIZE=128};
struct JobQueueSlot:public JobDescriptor
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(JobQueueSlot));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
JobQueueSlot(){}
hkUchar m_data[JOB_QUEUE_ENTRY_SIZE-sizeof(JobDescriptor)];
};
struct Queue:public CapacityGrowingArray<JobQueueSlot>
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(Queue));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
};
enum WaitPolicy
{
WAIT_UNTIL_ALL_WORK_COMPLETE,
WAIT_INDEFINITELY
};
struct JobQueueWaitState
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(JobQueueWaitState));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
__declspec(align(16))hkInt16 m_sQueueCounts[HK_JOB_TYPE_MAX];
int m_iWaitCount;
WaitPolicy m_eWaitPolicy;
hkBool m_bWaiting;
hkUint16 m_auiThreadIds[2+2+1];
Queue m_kQueues[2+2+1+HK_JOB_TYPE_MAX];
};
enum JobPopFuncResult
{
POP_QUEUE_ENTRY,
DO_NOT_POP_QUEUE_ENTRY
};
enum NextJobWaitMode
{
WAIT_FOR_NEXT_JOB,
DO_NOT_WAIT_FOR_NEXT_JOB
};
enum JobStatus
{
JOB_INVALID=-1,
GOT_NEXT_JOB,
NO_JOBS_AVAILABLE,
ALL_JOBS_FINISHED,
JOBS_AVAILABLE_BUT_NOT_FOR_CURRENT_ELF,
};
public:
JobDispatcher(const JobQueueConstructionInfo&cinfo);
JobStatus GetNextJob(const JobQueueSlot*oldJob,JobQueueSlot&jobOut,NextJobWaitMode waitStatus=WAIT_FOR_NEXT_JOB);
public:
void releaseOneWaitingThread(JobQueueWaitState*data);
public:
__declspec(align(64))PhysicsSimulationContext m_pWorldLock;
public:
int iFirstInteger;};

template<typename BOUNDING_VOLUME, typename hkIdxType>
inline hkAabbTreeQueryUtils<BOUNDING_VOLUME, hkIdxType>::Collector::~Collector() {}

typedef hkUlong hkPrimitiveId;
class KdTreeNode
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
private:
struct Pair3Pool
{
__declspec(align(8))hkInt32 m_iPrimitiveStartIndex;
hkUint32 m_iNumPrimitives;
};};
struct FieldlessRecord
{};
class KdTree
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
protected:
void AllocateNodes(int numNodes);};inline hkKdTreeCastCollector::~hkKdTreeCastCollector() {}

class hkCpuWorldGetClosestPointsCollector:public hkpBroadPhaseCastCollector,
public hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::Collector,
public hkKdTreeCastCollector
{
protected:
hkReal ReleaseCollector(const hkpBroadPhaseHandle*broadphaseHandle,int castIndex);
virtual hkReal GetHitDistance(const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>::Node*leaf);
virtual hkBool ReportHit(hkPrimitiveId primId);
virtual hkBool DidHit();
virtual hkReal GetHitFraction();
public:
const hkpGroupFilter*m_iFilter;
hkpFixedBufferCdPointCollector*m_pPointCollector;
const hkpCollidable*m_kCollidable;
hkpShapeType m_iType;
ShapeSweepParameters m_pRayCastInput;};struct RootContactPoint;

struct CollisionQueryJobHeader
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
struct CollisionQueryJobBase:public JobDescriptor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
enum JobSubType
{
COLLISION_QUERY_MOPP_AABB,
COLLISION_QUERY_PAIR_GET_CLOSEST_POINTS,
COLLISION_QUERY_WORLD_GET_CLOSEST_POINTS,
COLLISION_QUERY_PAIR_LINEAR_CAST,
COLLISION_QUERY_WORLD_LINEAR_CAST,
COLLISION_QUERY_KD_TREE_AABB_QUERY_JOB,
COLLISION_QUERY_AABB_TREE_AABB_QUERY_JOB,
COLLISION_QUERY_JOB_END
};
protected:
__forceinline CollisionQueryJobBase(JobSubType subType,hkUint16 size);
public:
hkSemaphoreBusyWait*m_pCompletionSemaphore;
CollisionQueryJobHeader*m_pCollisionQueryJobHeader;
const GskAgentInput*m_pCollisionInput;};
struct ContactPointResultBuffer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
const hkpCollidable*m_kCollidable;
RootContactPoint*m_pResultBuffer;
int m_iResultCount;
hkUint32 m_iResultCapacity;};
struct ContactPointQueryJob:public CollisionQueryJobBase
{
public:
friend struct GskAgentTaskHelper;
enum{MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK=64};
public:
__forceinline ContactPointQueryJob(const GskAgentInput*input,CollisionQueryJobHeader*jobHeader,const ContactPointResultBuffer*commandArray,int numCommands,const hkpBroadPhase*broadphase,hkReal tolerance,hkSemaphoreBusyWait*semaphore,int numCommandsPerTask=MAXIMUM_NUMBER_OF_COMMANDS_PER_TASK);
protected:
__forceinline JobDispatcher::JobPopFuncResult popJobTask(ContactPointQueryJob&out);
public:
const hkpBroadPhase*m_pBroadPhaseRecord;
const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>*m_pQuantizedAabbTree;
const KdTree*m_pKdTree;
hkReal m_fScalar;
int m_iCommandCapacity;
const ContactPointResultBuffer*m_pCommands;
int m_iCommandCount;};inline hkpFixedBufferCdPointCollector::~hkpFixedBufferCdPointCollector() {}
__forceinline hkpFixedBufferCdPointCollector::hkpFixedBufferCdPointCollector(RootContactPoint*buffer,int capacity):hkpCdPointCollector()
{
m_pPointBuffer=buffer;
m_pPointBufferEnd=buffer;
m_pRayCursor=capacity;
m_iPointCount=0;
}
class BroadPhaseCastCollector;
hkpBroadPhase*__cdecl hk3AxisSweep32CreateBroadPhase(const hkVector4&worldMin,const hkVector4&worldMax,int numMarkers);







typedef hkPrimitiveId*hkPrimitiveIdIterator;
class KdTreeAabbQuery
{
public:
enum{DEFAULT_STACK_SIZE=128};
static void __cdecl queryAabbIterative(const KdTree*root,const hkAabb&aabb,hkKdTreeCastCollector*collector);
private:
static hkUint32 __cdecl CollectAabbHitsIntoBuffers(const KdTreeNode*root,const FieldlessRecord*projectedEntries,hkVector4Parameter scale,hkVector4Parameter offset,const hkAabb&aabb,int treeDepth,
hkArray<hkPrimitiveId>::Temp*hitArray,hkKdTreeCastCollector*collector,hkPrimitiveIdIterator*hitsOut,int maxHits);};

// @fnv 0x00df6b50
// src: XBOX_PDB 0x00df6b50
JobDispatcher::JobStatus __cdecl hkCpuWorldGetClosestPointsJob(JobDispatcher&jobQueue,JobDispatcher::JobQueueSlot&nextJobOut)
{
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "CollQueryWorldGetClosestPoints";h->setTime();mStream.setEnd((char*)(h+1));}};
const ContactPointQueryJob&worldGetClosestPointsJob=reinterpret_cast<ContactPointQueryJob&>(nextJobOut);
hkpFixedBufferCdPointCollector castCollector(0,1);
hkCpuWorldGetClosestPointsCollector broadPhaseCollector;
broadPhaseCollector.m_pRayCastInput.m_collisionQuality=false;
{
broadPhaseCollector.m_iFilter=static_cast<const hkpGroupFilter*>(worldGetClosestPointsJob.m_pCollisionInput->m_iFilter.val());
broadPhaseCollector.m_pPointCollector=&castCollector;
static_cast<CollisionAgentContext&>(broadPhaseCollector.m_pRayCastInput)=*worldGetClosestPointsJob.m_pCollisionInput;
broadPhaseCollector.m_pRayCastInput.m_pConfiguration=worldGetClosestPointsJob.m_pCollisionInput->m_pConfiguration;
}
const hkp3AxisSweep*broadphase=static_cast<const hkp3AxisSweep*>(worldGetClosestPointsJob.m_pBroadPhaseRecord);
const hkAabbTree<hkAabbTreeData::QuantizedAabb,hkUint16>*aabbTreeInt=worldGetClosestPointsJob.m_pQuantizedAabbTree;
const KdTree*kdTree=worldGetClosestPointsJob.m_pKdTree;
;
for(int i=0;i<worldGetClosestPointsJob.m_iCommandCount;i++)
{
ContactPointResultBuffer*command=const_cast<ContactPointResultBuffer*>(&worldGetClosestPointsJob.m_pCommands[i]);
::new(&castCollector)hkpFixedBufferCdPointCollector(command->m_pResultBuffer,command->m_iResultCount);
{
hkAabb aabb;
const hkpShape*shape=command->m_kCollidable->getShape();
const hkTransform&transform=*static_cast<const hkTransform*>(command->m_kCollidable->m_pMotionState);
hkReal restTolerance=worldGetClosestPointsJob.m_fScalar-worldGetClosestPointsJob.m_pCollisionInput->getTolerance()*0.5f;
shape->getAabb(transform,restTolerance,aabb);
broadPhaseCollector.m_kCollidable=command->m_kCollidable;
broadPhaseCollector.m_iType=shape->getType();
broadPhaseCollector.m_pRayCastInput.setTolerance(worldGetClosestPointsJob.m_fScalar);
if(broadphase)
{
broadphase->CollectAabbCastResults(aabb,&broadPhaseCollector);
}
if(aabbTreeInt)
{
hkAabbTreeQueryUtils<hkAabbTreeData::QuantizedAabb,hkUint16>::GetAabbHits(aabbTreeInt,aabb,&broadPhaseCollector);
}
if(kdTree)
{
KdTreeAabbQuery::queryAabbIterative(kdTree,aabb,&broadPhaseCollector);
}
}
command->m_iResultCapacity=castCollector.m_iPointCount;
}
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return jobQueue.GetNextJob(&nextJobOut,nextJobOut);
}
