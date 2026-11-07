#include "../../../../../../../include/Transform.h"
#include "../../../../../../../include/hkArray.h"

// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtree/hkpbvtreeagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_d2f5a0_Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(int a);
};
struct S_d2f5a0_Entry {
    int unk0; int unk4;
    S_d2f5a0_Obj* m_obj;
};
typedef hkArrayBase<S_d2f5a0_Entry> S_d2f5a0_Array;
struct S_d2f5a0 {
    int unk0; int unk4; int unk8;
    S_d2f5a0_Array m_aiIndexedValues;
    void hkpBvTreeAgent_invalidateTim(int a);
};
struct TargetObject {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(Transform* apTransform, float afAmount, void* apContext);
};
struct Holder {
    TargetObject* m_pFlagTarget;
    int unk04;
    void* m_pData;
};
struct ValueSource {
    int unk00;
    int unk04;
    float m_fAmount;
};
void __cdecl ApplyTransformToTarget(Holder* apFirst, Holder* apSecond, ValueSource* apValue, void* apContext);
struct Allocator {
    virtual void* release();
    virtual void* allocate(int size);
};
struct Global { int unk00; int unk04; int unk08; int unk0c; Allocator* allocator; };
struct Built { int field00; short field04; int field08; void __thiscall FUN_00d2f980(int); };
extern "C" Global* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkpBvTreeAgent_createShapeBvAgent(int arg1, int arg2, int arg3, int arg4);
void __cdecl hkpBvTreeAgent_staticLinearCast(void* apFirst, void* apSecond, void* apThird,
                          void* apFourth, void* apFifth);
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
struct D2FA00Allocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct D2FA00MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D2FA00Allocator* m_pStreamAllocator;

    D2FA00Allocator& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt { extern "C" D2FA00MemoryRouter& __cdecl hkMemoryRouter_getInstance(); }
class D2FA00ReferencedObject {
public:
    static void* operator new(unsigned int nbytes)
    {
        D2FA00ReferencedObject* b = static_cast<D2FA00ReferencedObject*>(fnvc_adapt::hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(nbytes));
b->m_usMemSizeAndFlags = (unsigned short)nbytes;
return b;
}
    static void operator delete(void* p);
virtual ~D2FA00ReferencedObject();
unsigned short m_usMemSizeAndFlags;
short m_sReferenceCount;
};
class D2FA00Agent : public D2FA00ReferencedObject {
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
class D2FA00ShapeAgent : public D2FA00Agent {
public:
    D2FA00ShapeAgent(void* mgr) : D2FA00Agent(mgr) {}
    virtual ~D2FA00ShapeAgent();
};
D2FA00Agent* __cdecl hkpBvTreeAgent_createBvTreeShapeAgent(const void* bodyA, const void* bodyB, const void* input, void* mgr);
extern char str_010ce9a4[];
extern char str_010ce9ac[];
extern "C" void* __cdecl hkStatisticsCollector_getAllocatedSize(void* apBuffer, int aiCount);
struct S_00d2f8f0_Elem {
    int unk00;
    int unk04;
    int unk08;
};
struct S_00d2f8f0_Array {
    S_00d2f8f0_Elem* m_pEntries;
    int m_iArrayLength;

    S_00d2f8f0_Elem* begin() const { return m_pEntries; }
    S_00d2f8f0_Elem* end() const { return m_pEntries + m_iArrayLength; }
};
struct S_00d2f8f0_ArgVtbl {
    void* unk00;
    void* unk04;
    void* unk08;
    void (__thiscall *unk0c)(void*, char*, int, int);
    void* unk10;
    void (__thiscall *unk14)(void*, int, char*, void*, int, void*);
};
struct S_00d2f8f0_Arg {
    S_00d2f8f0_ArgVtbl* m_pVtbl;
    int unk04;
    int unk08;
    int unk0c;
    char m_bFlag10;
};
struct S_00d2f8f0 {
    int unk00;
    int unk04;
    int unk08;
    S_00d2f8f0_Array m_aiIndexedValues;
    int m_iFlags;

    void WriteToStream(S_00d2f8f0_Arg* apStream, int aiUnused);
};
class ListenerD2F5 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual void vf1C(void* pArg);
};
struct EntryD2F5 {
    int unk00;
    int unk04;
    ListenerD2F5* m_pkListener;
};
class OwnerD2F5 {
public:
    virtual ~OwnerD2F5();

    int unk04[2];
    hkArray<EntryD2F5> m_entries;

    void hkpBvTreeAgent_cleanup(void* pArg);
};
#include <xmmintrin.h>
class SlotObj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Eval(void* out, float f, void* box);
};
struct SlotRef {
    SlotObj* m_ent;
    unsigned int unk04;
    unsigned int m_08;
};
__declspec(align(16)) struct SlotTemp {
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
    void Init(unsigned int a, unsigned int b);
};
__declspec(align(16)) struct SlotTemp2 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void Build(unsigned int a, void* b);
};
struct SlotParam {
    unsigned int unk00;
    unsigned int unk04;
    float m_08;
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
};
struct SlotBox {
    __m128 lo;
    __m128 hi;
};
void hkpBvTreeAgent_calcAabbLinearCast(SlotRef* a, SlotRef* b, SlotParam* p, SlotBox* box);
class SolBool {
    char state;
public:
    SolBool() {}
    SolBool(bool x):state((char)x) {}
    operator bool() const { return state!=0; }
};
template<class T> class SolField {
    T data;
public:
    __forceinline T operator->() const { return data; }
    __forceinline operator T() const { return val(); }
    __forceinline T val() const { return data; }
};
struct SolVec {
    __m128 q;
    __forceinline SolVec& operator=(const SolVec& r) {q=r.q;return *this;}
};
struct SolBox {
    SolVec low,high;
    SolBool contains(const SolBox& rhs) const {
        __m128 lo=_mm_cmple_ps(low.q,rhs.low.q);
        __m128 hi=_mm_cmple_ps(rhs.high.q,high.q);
        return (_mm_movemask_ps(_mm_and_ps(lo,hi))&7)==7;
    }
};
struct __declspec(align(16)) SolTransform {
    float m00,m04,m08,m0c,m10,m14,m18,m1c,m20,m24,m28,m2c,m30,m34,m38,m3c;
    void hkTransform_setMulInverseMul(const SolTransform&,const SolTransform&);
    inline void SetMulInverse(const SolTransform& a,const SolTransform& b) {hkTransform_setMulInverseMul(a,b);}
};
template<class T> struct SolArray;
struct SolContainer;
enum SolKind {SolKindInvalid=-1,SolKindLast=31};
template<class E,class I> class SolEnum {
    I data;
public:
    __forceinline operator E() const {return static_cast<E>(data);}
};
struct SolShape {
    virtual void v00();
    unsigned short GetAllocationSize,refs;
    int user;
    SolEnum<SolKind,unsigned> type;
    virtual void v04(); virtual void v08(); virtual void v0c();
    virtual const SolContainer* GetShapeContainer() const;
    virtual void v14(); virtual void v18();
    virtual void getAabb(const SolTransform&,float,SolBox&) const;
    __forceinline SolKind getType() const;
};
struct __declspec(align(16)) SolAlignedShape:SolShape {};
__forceinline SolKind SolShape::getType() const {return static_cast<const SolAlignedShape*>(this)->type;}
struct SolTreeShape:SolShape {
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void GetAabbHits(const SolBox&,SolArray<unsigned>&) const;
};
struct __declspec(align(16)) SolBuffer { unsigned data[128]; };
struct SolContainer {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10();
    virtual const SolShape* GetShapeForKey(unsigned,SolBuffer&) const;
};
struct SolBody {
    const SolShape* shape;
    unsigned key;
    const SolTransform* motion;
    const SolBody* parent;
    __forceinline SolBody(const SolBody* p):parent(p) {motion=p->motion;}
    __forceinline const SolTransform& getTransform() const {return *motion;}
    __forceinline const SolShape* getShape() const {return shape;}
    __forceinline void SetCollisionShapeAndKey(const SolShape* s,unsigned k) {shape=s;key=k;}
};
struct SolInput;
struct SolShapeFilter {
    virtual void v00();
    virtual SolBool IsCollisionEnabled(const SolInput&,const SolBody&,const SolBody&,const SolContainer&,unsigned) const;
};
struct SolReferenced {
    virtual void v00();
    unsigned short size,refs;
};
struct SolPairFilter {virtual void v00();};
struct SolFilter:SolReferenced,SolPairFilter,SolShapeFilter {
    virtual SolBool IsCollisionEnabled(const SolInput&,const SolBody&,const SolBody&,const SolContainer&,unsigned) const;
};
struct SolOwner;
struct SolManager;
struct SolAgent {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();
    virtual void v10();virtual void v14();virtual void v18();
    virtual void cleanup(SolOwner&);
    unsigned short GetAllocationSize,refs;
    SolManager* m_pContactManager;
};
typedef SolAgent* (__cdecl *SolFactory)(const SolBody&,const SolBody&,const SolInput&,SolManager*);
struct SolFactoryRecord {SolFactory create;void* u04;void* u08;void* u0c;void* u10;};
struct SolDispatcher;
struct SolInput {
    SolField<SolDispatcher*> m_pCollisionDispatcher;
    SolField<int> weld;
    SolField<float> tolerance;
    SolField<const SolFilter*> m_iFilter;
    SolField<const void*> convexFilter;
    mutable SolField<int> predictive;
    float getTolerance() const {return tolerance;}
};
struct SolDispatcher {
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

unsigned char regular[32][32];
unsigned char predictive[32][32];
SolFactoryRecord functions[32];
enum Prediction {NoPrediction,UsePrediction};
__forceinline SolFactory find(SolKind a,SolKind b,const Prediction& predictiveFlag) const {
    int kind=(predictiveFlag ? predictive : regular)[a][b];
    return functions[kind].create;
}
__forceinline SolAgent* getNewCollisionAgent(const SolBody& a,const SolBody& b,const SolInput& input,SolManager* mgr) const {
    const SolKind firstKind=a.getShape()->getType();
    const SolKind secondKind=b.getShape()->getType();
    Prediction prediction=static_cast<Prediction>((int)input.predictive.val());
    SolFactory f=find(firstKind,secondKind,prediction);
    return f(a,b,input,mgr);
}
};
struct SolHeap {
    virtual void v00();virtual void v04();virtual void v08();virtual void v0c();
    virtual void freeBuffer(void*,int);
    virtual void v14();virtual void v18();virtual void v1c();virtual void v20();
    virtual bool CanAllocateBytes(int);
};
struct SolStack {
    char* cursor;
    __forceinline void* allocate(int n,const char*) {char* p=cursor;cursor+=n;return p;}
    __forceinline void deallocate(void* p) {cursor=(char*)p;}
};
struct SolRouter {
    SolStack local;
    int u04,u08,u0c;
    SolHeap* heapPtr;
    static SolRouter& GetMonitorStream() {return *reinterpret_cast<SolRouter*>(hkMemoryRouter_getInstance());}
    SolHeap& heap() {return *heapPtr;}
    SolStack& stack() {return local;}
};
struct SolHeapSource {SolHeap& get(const void*) {return SolRouter::GetMonitorStream().heap();}};
template<class T> __forceinline void SolFreeStack(T* p) {SolRouter::GetMonitorStream().stack().deallocate(p);}
extern void __cdecl hkArrayUtil__reserve(SolHeap&,void*,int,int);
extern void __cdecl hkMemUtil_memMove(void*,const void*,int);
extern void __cdecl hkSetOutOfMemoryState(int);
extern char DAT_011b4284,DAT_01268ad4;
struct SolSortState {};
extern void __cdecl QuickSortRange(unsigned*,int,int,SolSortState);
struct SolPlace;
inline void* operator new(unsigned int,SolPlace* p) {return p;}
struct SolPodTag {};
struct SolClassTag {};
template<class T> struct SolTypeTag {typedef SolClassTag Type;};
template<> struct SolTypeTag<unsigned> {typedef SolPodTag Type;};
namespace SolArrayOps {
    template<class T> __forceinline void construct(T*,int,SolPodTag) {}
    template<class T> __forceinline void construct(T* p,int n,SolClassTag) {for(int i=0;i<n;++i) ::new(reinterpret_cast<SolPlace*>(p+i)) T;}
    template<class T> __forceinline void destroy(T*,int,SolPodTag) {}
    template<class T> __forceinline void destroy(T* p,int n,SolClassTag) {for(int i=0;i<n;++i) p[i].~T();}
    template<class T> __forceinline void copy(T* d,const T* p,int n) {for(int i=0;i<n;++i) d[i]=p[i];}
    template<class T> __forceinline void constructFrom(T* d,int n,const T* p,SolClassTag) {
        for(int i=0;i<n;++i) ::new(reinterpret_cast<SolPlace*>(d+i)) T(p[i]);
    }
    __forceinline void move(void* d,const void* p,int n) {hkMemUtil_memMove(d,p,n);}
    __forceinline void copyBytes(void* d,const void* p,int n) {
        for(int i=0;i<n;i+=4) *reinterpret_cast<unsigned*>((char*)d+i)=*reinterpret_cast<const unsigned*>((const char*)p+i);
    }
}
template<class T> struct SolArrayBase {
    T* data;
    int count;
    int capacity;
    __forceinline SolArrayBase():data(0),count(0),capacity(0x80000000) {}
    __forceinline SolArrayBase(T* p,int n,int c):data(p),count(n),capacity(c|0x80000000) {}
    inline T* begin() {return data;}
    inline T* end() {return data+count;}
    inline int GetLogicalSize() const {return count;}
    inline int getCapacity() const {return capacity&0x3fffffff;}
    __forceinline void reserveWith(SolHeap& heap,int n) {
        int available=getCapacity();
        if(available<n) {
            int twice=2*available;
            int target=n<twice?twice:n;
            hkArrayUtil__reserve(heap,this,target,sizeof(T));
        }
    }
    __forceinline void setSizeWith(SolHeap& heap,int n) {
        reserveWith(heap,n);
        SolArrayOps::destroy(data+n,count-n,typename SolTypeTag<T>::Type());
        SolArrayOps::construct(data+count,n-count,typename SolTypeTag<T>::Type());
        count=n;
    }
    __forceinline T* expandWith(SolHeap& heap,int at,int n) {
        int total=n+count;
        int shifted=count-at;
        if(total>getCapacity()) reserveWith(heap,total);
        SolArrayOps::move(data+at+n,data+at,shifted*sizeof(T));
        SolArrayOps::construct(data+at,n,typename SolTypeTag<T>::Type());
        count=total;
        return data+at;
    }
    __forceinline void removeAtAndCopy(int at) {
        SolArrayOps::destroy(data+at,1,typename SolTypeTag<T>::Type());
        --count;
        SolArrayOps::copyBytes(data+at,data+at+1,(count-at)*sizeof(T));
    }
    __forceinline void clear() {SolArrayOps::destroy(data,count,typename SolTypeTag<T>::Type()); count=0;}
    __forceinline void release(SolHeap& heap) {
        clear();
        if((capacity&0x80000000)==0) heap.freeBuffer(data,getCapacity()*sizeof(T));
        data=0;capacity=0x80000000;
    }
    __forceinline void assignWith(SolHeap& heap,const SolArrayBase& rhs,SolClassTag) {
        int old=count;
        int total=rhs.GetLogicalSize();
        int common=total>old?old:total;
        reserveWith(heap,total);
        SolArrayOps::destroy(data+total,old-total,SolClassTag());
        SolArrayOps::copy(data,rhs.data,common);
        SolArrayOps::constructFrom(data+common,total-common,rhs.data+common,SolClassTag());
        count=total;
    }
};
template<class T> struct SolArray:SolArrayBase<T> {
    __forceinline SolArray() {}
    __forceinline SolArray(T* p,int n,int c):SolArrayBase<T>(p,n,c) {}
    __forceinline ~SolArray() {this->release(SolHeapSource().get(this));}
    __forceinline void SetSizeAndGrow(int n) {this->setSizeWith(SolHeapSource().get(this),n);}
    __forceinline T* expandAt(int at,int n) {return this->expandWith(SolHeapSource().get(this),at,n);}
    __forceinline SolArray& operator=(const SolArray& rhs) {this->assignWith(SolHeapSource().get(this),rhs,typename SolTypeTag<T>::Type());return *this;}
};
template<class T,int N> struct SolFixedArray:SolArray<T> {
    T storage[N];
    __forceinline SolFixedArray(int n=0):SolArray<T>(storage,n,N) {}
};
template<class T> struct SolLocalArray:SolArray<T> {
    T* localMemory;
    __forceinline SolLocalArray(int n) {
        this->data=static_cast<T*>(SolRouter::GetMonitorStream().stack().allocate((n*sizeof(T)+127)&~127,0));
        this->capacity=n|0x80000000;
        localMemory=this->data;
    }
    __forceinline ~SolLocalArray() {
        if(localMemory==this->data) this->clear();
        SolFreeStack(localMemory);
    }
};
extern D2FA00Agent* __cdecl hkpNullAgent_getNullAgent();
struct SolNull {
    static D2FA00Agent* getNullAgentOriginal() {return hkpNullAgent_getNullAgent();}
    static SolAgent* GetNullAgent() {return reinterpret_cast<SolAgent*>(getNullAgentOriginal());}
};
namespace SolAlgorithm {
    __forceinline void sort(unsigned* p,int n,SolSortState state) {if(n>1) QuickSortRange(p,0,n-1,state);}
    __forceinline void quickSort(unsigned* p,int n) {sort(p,n,SolSortState());}
}
struct SolEntry {
    unsigned m_key;
    int userInfo;
    SolAgent* m_pCollisionAgent;
    unsigned& GetIteratorKey() {return m_key;}
    void setKey(unsigned& k) {m_key=k;}
};
struct SolUpdater:SolAgent {
    SolArray<SolEntry> m_kEntries;
    SolBox m_kBoundingBox;
    void hkpBvTreeAgent_prepareCollisionPartners(const SolBody&,const SolBody&,const SolInput&,SolOwner&);
};
struct SolChildState {
    const SolContainer* container;
    SolBody child;
    SolBuffer scratch;
    SolChildState(const SolBody& parent):child(&parent) {}
    inline const SolBody* getChild(const SolBody&,const SolInput&,unsigned k) {
        child.SetCollisionShapeAndKey(container->GetShapeForKey(k,scratch),k);
        return &child;
    }
    inline const SolContainer* GetShapeContainer() { return container; }
};
template<class E> struct SolMerge {
 static __forceinline void slow(SolArray<E>& entries,SolArray<unsigned>& keys,const SolBody& first,const SolBody& second,
                         const SolInput& value,SolManager* owner,SolOwner& context,SolChildState& w) {
    E* old=entries.begin();
    E* oldEnd=entries.end();
    unsigned* key=keys.begin();
    unsigned* keyEnd=keys.end();
    SolLocalArray<E> output(keys.GetLogicalSize());
    output.SetSizeAndGrow(keys.GetLogicalSize());
    const SolContainer* container=w.GetShapeContainer();
    E* out=output.begin();
    while (old!=oldEnd && key!=keyEnd) {
        if (*key==old->GetIteratorKey()) {
            *out=*old;
            ++out; ++old; ++key;
            continue;
        }
        if (*key<old->GetIteratorKey()) {
            const SolBody* a=&first;
            const SolBody* b=&second;
            const SolBody* modified=w.getChild(second,value,*key);
            if (value.m_iFilter->IsCollisionEnabled(value,*a,*b,*container,*key))
                out->m_pCollisionAgent=value.m_pCollisionDispatcher->getNewCollisionAgent(*a,*modified,value,owner);
            else out->m_pCollisionAgent=SolNull::GetNullAgent();
            out->setKey(*key);
            ++out; ++key;
            continue;
        }
        if(old->m_pCollisionAgent) old->m_pCollisionAgent->cleanup(context);
        ++old;
    }
    while(old!=oldEnd) {
        if(old->m_pCollisionAgent) old->m_pCollisionAgent->cleanup(context);
        ++old;
    }
    while(key!=keyEnd) {
        const SolBody* a=&first;
        const SolBody* b=&second;
        const SolBody* modified=w.getChild(second,value,*key);
        if(value.m_iFilter->IsCollisionEnabled(value,*a,*b,*container,*key))
            out->m_pCollisionAgent=value.m_pCollisionDispatcher->getNewCollisionAgent(*a,*modified,value,owner);
        else out->m_pCollisionAgent=SolNull::GetNullAgent();
        out->setKey(*key);
        ++out; ++key;
    }
    entries=output;
 }
 static __forceinline void fast(SolArray<E>& entries,SolArray<unsigned>& keys,const SolBody& first,const SolBody& second,
                         const SolInput& value,SolManager* owner,SolOwner& context,SolChildState& w) {
    {
        E* entry=entries.begin();
        E* end=entries.end();
        unsigned* hit=keys.begin();
        unsigned* hitEnd=keys.end();
        for(;entry!=end;++entry) {
            if(hit!=hitEnd && entry->GetIteratorKey()==*hit) {++hit;continue;}
            for(hit=keys.begin();hit!=hitEnd;++hit) {
                if(entry->GetIteratorKey()==*hit) {++hit;goto found;}
            }
            entry->m_pCollisionAgent->cleanup(context);
            entries.removeAtAndCopy(int(entry-entries.begin()));
            --entry;--end;
found:;
        }
    }
    const SolContainer* container=w.GetShapeContainer();
    if(keys.GetLogicalSize()!=entries.GetLogicalSize()) {
        E* entry=entries.begin();
        E* end=entries.end();
        unsigned* hit=keys.begin();
        unsigned* hitEnd=keys.end();
        for(;hit!=hitEnd;++hit) {
            if(entry!=end && entry->GetIteratorKey()==*hit) {++entry;continue;}
            int at=int(hit-keys.begin());
            entry=entries.expandAt(at,1);
            const SolBody* a=&first;
            const SolBody* b=&second;
            const SolBody* modified=w.getChild(second,value,*hit);
            if(value.m_iFilter->IsCollisionEnabled(value,*a,*b,*container,*hit))
                entry->m_pCollisionAgent=value.m_pCollisionDispatcher->getNewCollisionAgent(*a,*modified,value,owner);
            else entry->m_pCollisionAgent=SolNull::GetNullAgent();
            entry->m_key=*hit;
            end=entries.end();
            ++entry;
        }
    }
 }
};

#include <xmmintrin.h>

extern "C" {
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
}




typedef float RealD3;
typedef unsigned int UInt32D3;
typedef unsigned int KeyD3;

template <class T>
class PadD3
{
	public:
		__forceinline PadD3() {}
		__forceinline PadD3( T e ) : m_kStorage( e ) {}
		__forceinline void operator=( T e ) { m_kStorage = e; }
		__forceinline T val() const { return m_kStorage; }
		__forceinline T operator->() const { return m_kStorage; }
		__forceinline operator T() const { return val(); }
	private:
		T m_kStorage;
};

class BoolD3
{
	public:
		inline BoolD3() {}
		inline BoolD3( bool b ) { m_cBooleanValue = static_cast<char>( b ); }
		inline operator bool() const { return m_cBooleanValue != 0; }
		inline BoolD3& operator=( bool e ) { m_cBooleanValue = static_cast<char>( e ); return *this; }
		inline BoolD3 operator==( bool e ) const { return static_cast<int>( m_cBooleanValue ) == static_cast<int>( e ); }
		inline BoolD3 operator!=( bool e ) const { return static_cast<int>( m_cBooleanValue ) != static_cast<int>( e ); }
	private:
		char m_cBooleanValue;
};

class SRealD3
{
	public:
		SRealD3( const __m128& x ) : m_vValue( x ) {}
		SRealD3( RealD3 x ) { m_vValue = _mm_load_ss( &x ); }
		SRealD3() {}
		operator RealD3() const { RealD3 s; _mm_store_ss( &s, m_vValue ); return s; }
		__forceinline __m128 broadcast() const { return _mm_shuffle_ps( m_vValue, m_vValue, 0 ); }
		__forceinline const __m128& getQuad() const { return m_vValue; }
	private:
		__m128 m_vValue;
};

class VCompD3
{
	public:
		enum MaskD3
		{
			MASK_NONE = 0, MASK_X = 1, MASK_Y = 2, MASK_XY = 3,
			MASK_Z = 4, MASK_XZ = 5, MASK_YZ = 6, MASK_XYZ = 7,
			MASK_W = 8, MASK_XW = 9, MASK_YW = 10, MASK_XYW = 11,
			MASK_ZW = 12, MASK_XZW = 13, MASK_YZW = 14, MASK_XYZW = 15
		};
		__forceinline void setAnd( const VCompD3& a, const VCompD3& b ) { m_uiMask = _mm_and_ps( a.m_uiMask, b.m_uiMask ); }
		__forceinline int allAreSet( MaskD3 m ) const { return ( _mm_movemask_ps( m_uiMask ) & m ) == m; }
		__m128 m_uiMask;
};

extern const __declspec(align(16)) UInt32D3 DAT_010c44d0[4];

class Mat3D3;
class RotD3;
class XformD3;

class Vec4D3
{
	public:
		__forceinline void operator=( const Vec4D3& v );
		__forceinline void operator=( const __m128& v );
		__forceinline void setAll3( RealD3 a );
		__forceinline void setZero4();
		__forceinline void add4( const Vec4D3& v );
		__forceinline void sub4( const Vec4D3& v );
		__forceinline void setAdd4( const Vec4D3& a, const Vec4D3& b );
		__forceinline void setSub4( const Vec4D3& a, const Vec4D3& b );
		__forceinline void mul4( const SRealD3& s );
		__forceinline void setMul4( const SRealD3& r, const Vec4D3& v );
		__forceinline void addMul4( const SRealD3& r, const Vec4D3& v );
		__forceinline void setCross( const Vec4D3& a, const Vec4D3& b );
		__forceinline VCompD3 compareLessThanEqual4( const Vec4D3& a ) const;
		__forceinline void setNeg4( const Vec4D3& v );
		__forceinline void setMin4( const Vec4D3& a, const Vec4D3& b );
		__forceinline void setMax4( const Vec4D3& a, const Vec4D3& b );
		__forceinline void rotInvDir( const RotD3& r, const Vec4D3& b );
		__forceinline void xformInvPos( const XformD3& a, const Vec4D3& b );
		__forceinline RealD3& operator()( int i );
		__forceinline const RealD3& operator()( int i ) const;
		__forceinline __m128& getQuad();
		__forceinline const __m128& getQuad() const;
	private:
		__m128 m_vComponents;
};

// local form of hkMatrix3: 0x00d302d0 needs inline construction/column access; shared form gives 3337 bytes vs exe 3185.
class Mat3D3
{
	public:
		__forceinline Mat3D3() {}
		__forceinline const Vec4D3& getColumn( int i ) const { return ( &m_kColumn0 )[i]; }
	protected:
		Vec4D3 m_kColumn0;
		Vec4D3 m_kColumn1;
		Vec4D3 m_kColumn2;
};

class RotD3 : public Mat3D3
{
	public:
};

class XformD3
{
	public:
		__forceinline XformD3() {}
		__forceinline const RotD3& getRotation() const { return m_rotation; }
		__forceinline const Vec4D3& getTranslation() const { return m_vTranslation; }
		void hkTransform_setMulInverseMul( const XformD3& a, const XformD3& b );
	protected:
		RotD3 m_rotation;
		Vec4D3 m_vTranslation;
};

inline __m128& Vec4D3::getQuad() { return m_vComponents; }
inline const __m128& Vec4D3::getQuad() const { return m_vComponents; }
inline void Vec4D3::operator=( const Vec4D3& v ) { m_vComponents = v.m_vComponents; }
inline void Vec4D3::operator=( const __m128& v ) { getQuad() = v; }
inline void Vec4D3::setAll3( RealD3 a ) { m_vComponents = _mm_set_ps1( a ); }
inline void Vec4D3::setZero4() { m_vComponents = _mm_setzero_ps(); }
inline void Vec4D3::add4( const Vec4D3& v ) { m_vComponents = _mm_add_ps( m_vComponents, v.m_vComponents ); }
inline void Vec4D3::sub4( const Vec4D3& v ) { m_vComponents = _mm_sub_ps( m_vComponents, v.m_vComponents ); }
inline void Vec4D3::setAdd4( const Vec4D3& a, const Vec4D3& b ) { m_vComponents = _mm_add_ps( a.m_vComponents, b.m_vComponents ); }
inline void Vec4D3::setSub4( const Vec4D3& a, const Vec4D3& b ) { m_vComponents = _mm_sub_ps( a.m_vComponents, b.m_vComponents ); }
inline void Vec4D3::mul4( const SRealD3& s ) { m_vComponents = _mm_mul_ps( s.broadcast(), m_vComponents ); }
inline void Vec4D3::setMul4( const SRealD3& r, const Vec4D3& v ) { m_vComponents = _mm_mul_ps( r.broadcast(), v.m_vComponents ); }
inline void Vec4D3::addMul4( const SRealD3& r, const Vec4D3& v ) { m_vComponents = _mm_add_ps( m_vComponents, _mm_mul_ps( r.broadcast(), v.m_vComponents ) ); }
inline void Vec4D3::setCross( const Vec4D3& a, const Vec4D3& b )
{
	__m128 c0;
	c0 = _mm_mul_ps( _mm_shuffle_ps( a.m_vComponents, a.m_vComponents, 0xc9 ), _mm_shuffle_ps( b.m_vComponents, b.m_vComponents, 0xd2 ) );
	__m128 c1;
	c1 = _mm_mul_ps( _mm_shuffle_ps( a.m_vComponents, a.m_vComponents, 0xd2 ), _mm_shuffle_ps( b.m_vComponents, b.m_vComponents, 0xc9 ) );
	m_vComponents = _mm_sub_ps( c0, c1 );
}
inline VCompD3 Vec4D3::compareLessThanEqual4( const Vec4D3& a ) const { VCompD3 m; m.m_uiMask = _mm_cmple_ps( m_vComponents, a.m_vComponents ); return m; }
inline void Vec4D3::setNeg4( const Vec4D3& v ) { m_vComponents = _mm_xor_ps( v.m_vComponents, *(const __m128*)&DAT_010c44d0 ); }
inline void Vec4D3::setMin4( const Vec4D3& a, const Vec4D3& b ) { m_vComponents = _mm_min_ps( a.getQuad(), b.getQuad() ); }
inline void Vec4D3::setMax4( const Vec4D3& a, const Vec4D3& b ) { m_vComponents = _mm_max_ps( a.getQuad(), b.getQuad() ); }
inline void Vec4D3::rotInvDir( const RotD3& r, const Vec4D3& b )
{
	__m128 c0 = r.getColumn( 0 ).m_vComponents;
	__m128 c1 = r.getColumn( 1 ).m_vComponents;
	__m128 c2 = r.getColumn( 2 ).m_vComponents;
	{
		__m128 lo, hi;
		lo = _mm_unpacklo_ps( c0, c1 );
		hi = _mm_shuffle_ps( _mm_unpackhi_ps( c0, c1 ), c2, 0xe4 );
		c0 = _mm_movelh_ps( lo, c2 );
		c1 = _mm_shuffle_ps( _mm_movehl_ps( c0, lo ), c2, 0xd4 );
		c2 = hi;
	}
	const __m128 b0 = _mm_shuffle_ps( b.m_vComponents, b.m_vComponents, 0x00 );
	const __m128 r0 = _mm_mul_ps( c0, b0 );
	const __m128 b1 = _mm_shuffle_ps( b.m_vComponents, b.m_vComponents, 0x55 );
	const __m128 r1 = _mm_mul_ps( c1, b1 );
	const __m128 b2 = _mm_shuffle_ps( b.m_vComponents, b.m_vComponents, 0xaa );
	const __m128 r2 = _mm_mul_ps( c2, b2 );
	m_vComponents = _mm_add_ps( _mm_add_ps( r0, r1 ), r2 );
}
inline void Vec4D3::xformInvPos( const XformD3& a, const Vec4D3& b )
{
	Vec4D3 t0; t0.setSub4( b, a.getTranslation() );
	rotInvDir( a.getRotation(), t0 );
}
inline RealD3& Vec4D3::operator()( int i ) { return reinterpret_cast<RealD3*>( &m_vComponents )[i]; }
inline const RealD3& Vec4D3::operator()( int i ) const { return reinterpret_cast<const RealD3*>( &m_vComponents )[i]; }

class AabbD3
{
	public:
		AabbD3() {}
		__forceinline BoolD3 contains( const AabbD3& other ) const;
		Vec4D3 m_kMinimumCorner;
		Vec4D3 m_kMaximumCorner;
};

inline BoolD3 AabbD3::contains( const AabbD3& other ) const
{
	VCompD3 mincomp = m_kMinimumCorner.compareLessThanEqual4( other.m_kMinimumCorner );
	VCompD3 maxcomp = other.m_kMaximumCorner.compareLessThanEqual4( m_kMaximumCorner );
	VCompD3 both; both.setAnd( mincomp, maxcomp );
	return both.allAreSet( VCompD3::MASK_XYZ ) != 0;
}

// local form of hkSweptTransform: 0x00d302d0 needs inline swept-time and vector access; shared form gives 3329 bytes vs exe 3185.
class SweptD3
{
	public:
		__forceinline SweptD3() {}
		__forceinline RealD3 getInvDeltaTime() const;
		Vec4D3 m_vCenterOfMass0;
		Vec4D3 m_vCenterOfMass1;
		Vec4D3 m_qRotation0;
		Vec4D3 m_qRotation1;
		Vec4D3 m_vCenterOfMassLocal;
};

inline RealD3 SweptD3::getInvDeltaTime() const { return m_vCenterOfMass1( 3 ); }

class MotionStateD3
{
	public:
		inline const SweptD3& getSweptTransform() const { return m_kSweptTransform; }
	protected:
		XformD3 m_kMotionTransform;
		SweptD3 m_kSweptTransform;
	public:
		Vec4D3 m_kDeltaAngle;
		RealD3 m_fObjectRadius;
		RealD3 m_fLinearDamping;
		RealD3 m_fAngularDamping;
};

namespace SweptUtilD3
{
	__forceinline void __cdecl calcTimInfo( const MotionStateD3& ms0, const MotionStateD3& ms1, RealD3 deltaTime, Vec4D3& timOut );
}

inline void __cdecl SweptUtilD3::calcTimInfo( const MotionStateD3& ms0, const MotionStateD3& ms1, RealD3 deltaTime, Vec4D3& timOut )
{
	const SweptD3& st0 = ms0.getSweptTransform();
	const SweptD3& st1 = ms1.getSweptTransform();
	Vec4D3 diff0; diff0.setSub4( st0.m_vCenterOfMass0, st0.m_vCenterOfMass1 );
	Vec4D3 diff1; diff1.setSub4( st1.m_vCenterOfMass1, st1.m_vCenterOfMass0 );
	RealD3 f0 = deltaTime * st0.getInvDeltaTime();
	RealD3 f1 = deltaTime * st1.getInvDeltaTime();
	timOut.setMul4( f0, diff0 );
	timOut.addMul4( f1, diff1 );
	timOut( 3 ) = f0 * ms0.m_kDeltaAngle( 3 ) * ms0.m_fObjectRadius + f1 * ms1.m_kDeltaAngle( 3 ) * ms1.m_fObjectRadius;
}

class ShapeD3;

enum ShapeTypeD3 { SHAPE_INVALID = 0, SHAPE_MAX = 32 };

template <typename E, typename S>
class EnumD3
{
	public:
		EnumD3() {}
		EnumD3( E e ) { m_kStorage = static_cast<S>( e ); }
		operator E() const { return static_cast<E>( m_kStorage ); }
		void operator=( E e ) { m_kStorage = static_cast<S>( e ); }
	private:
		S m_kStorage;
};


#include "../../../../../../../include/hkpCdBody.h"


inline const hkTransform& hkpCdBody::getTransform() const { return *reinterpret_cast<const hkTransform*>( m_pMotionState ); }
inline const hkMotionState* hkpCdBody::GetMotionState() const { return static_cast<const hkMotionState*>( m_pMotionState ); }
inline const hkpShape* hkpCdBody::getShape() const { return m_pCollisionShape; }
inline void hkpCdBody::SetCollisionShapeAndKey( const hkpShape* shape, KeyD3 key ) { m_pCollisionShape = shape; m_uiCollisionShapeKey = key; }
inline hkpCdBody::hkpCdBody( const hkpCdBody* parent ) { m_parent = parent; m_pMotionState = parent->m_pMotionState; }

class AllocatorD3
{
	public:
		virtual ~AllocatorD3();
		virtual void* AllocateMemoryBlock( int numBytes ) = 0;
		virtual void ReleaseBlock( void* p, int numBytes ) = 0;
		virtual void* AllocateBufferWithSize( int& reqNumBytesInOut );
		virtual void ReturnMemory( void* p, int numBytes );
		template <typename T>
		inline T* _bufAlloc( int& reqNumInOut )
		{
			const int SIZE_ELEM = sizeof( T );
			int n = reqNumInOut * SIZE_ELEM;
			void* p = AllocateBufferWithSize( n );
			reqNumInOut = n / SIZE_ELEM;
			return static_cast<T*>( p );
		}
		template <typename T>
		inline void _bufFree( void* p, int numElem )
		{
			const int SIZE_ELEM = sizeof( T );
			ReturnMemory( p, numElem * SIZE_ELEM );
		}
};

__forceinline long __cdecl byteDiff( const void* base, const void* pntr )
{
	return long( pntr ) - long( base );
}

template <typename T>
__forceinline T* __cdecl byteAdd( T* base, long offset )
{
	return reinterpret_cast<T*>( reinterpret_cast<char*>( base ) + offset );
}

struct StackMemD3
{
	public:
		__forceinline void* allocateStack( int numBytes, const char* what );
		__forceinline void deallocateStack( void* p );
		__forceinline int getFreeStackSize() { return int( byteDiff( m_next, m_kRayEnd ) ); }
	protected:
		PadD3<void*> m_next;
		PadD3<void*> m_kRayStart;
		PadD3<void*> m_kRayEnd;
};

inline void* StackMemD3::allocateStack( int numBytes, const char* what )
{
	if ( numBytes > getFreeStackSize() )
	{
	}
	void* current = m_next;
	m_next = byteAdd( current, numBytes );
	return current;
}

inline void StackMemD3::deallocateStack( void* p )
{
	m_next = p;
}

class RouterD3
{
	public:
		static RouterD3& __cdecl hkMemoryRouter_getInstance();
		inline StackMemD3& stack() { return m_aiEntries; }
		inline AllocatorD3& heap() { return *m_pStreamAllocator; }
	protected:
		StackMemD3 m_aiEntries;
		AllocatorD3* m_pTemp;
		AllocatorD3* m_pStreamAllocator;
		AllocatorD3* m_pDebugAllocator;
		AllocatorD3* m_pSolver;
		AllocatorD3* m_pGlobal;
		void* m_ulUserData;
};

template <typename T> struct SizeOfD3 { enum { val = sizeof( T ) }; };

template <typename T>
__forceinline T* __cdecl allocStack( int n, const char* what = 0 )
{
	RouterD3& mem = RouterD3::hkMemoryRouter_getInstance();
	return static_cast<T*>( mem.stack().allocateStack( ( ( n * SizeOfD3<T>::val ) + ( 128 - 1 ) ) & ( ~( 128 - 1 ) ), what ) );
}

template <typename T>
__forceinline void __cdecl freeStack( T* ptr )
{
	RouterD3::hkMemoryRouter_getInstance().stack().deallocateStack( static_cast<void*>( ptr ) );
}

struct HeapAllocD3
{
	AllocatorD3& get( const void* ) { return RouterD3::hkMemoryRouter_getInstance().heap(); }
};


template <bool B> struct TraitBoolD3 { };
typedef TraitBoolD3<true> IsPodTagD3;
typedef TraitBoolD3<false> IsClassTagD3;
template <typename T> struct PodTraitD3 { typedef IsClassTagD3 type; };
template <> struct PodTraitD3<unsigned int> { typedef IsPodTagD3 type; };

class ArrayUtilD3
{
	public:
		static void __cdecl hkArrayUtil__reserve( AllocatorD3& a, void* arr, int reqElem, int sizeElem );
		template <typename T>
		static __forceinline void __cdecl construct( T* t, int n, IsPodTagD3 ) {}
		template <typename T>
		static __forceinline void __cdecl construct( T* t, int n, IsClassTagD3 )
		{
			for ( int i = 0; i < n; ++i )
			{
				::new ( reinterpret_cast<SolPlace*>( t + i ) ) T;
			}
		}
		template <typename T>
		static __forceinline void __cdecl constructWithArray( T* t, int n, const T* tcopy, IsClassTagD3 )
		{
			for ( int i = 0; i < n; ++i )
			{
				::new ( reinterpret_cast<SolPlace*>( t + i ) ) T( tcopy[i] );
			}
		}
		template <typename T>
		static __forceinline void __cdecl destruct( T* t, int n, IsPodTagD3 ) {}
		template <typename T>
		static __forceinline void __cdecl destruct( T* t, int n, IsClassTagD3 )
		{
			for ( int i = 0; i < n; ++i )
			{
				static_cast<T*>( t )[i].~T();
			}
		}
};

void __cdecl hkMemUtil_memMove( void* dst, const void* src, int nbytes );

template <unsigned int A> struct AlignTypeD3 { typedef UInt32D3 type; };

namespace MemUtilD3
{
	template <unsigned int ELEMENTALIGN>
	__forceinline void CopyRegion( void* dst, const void* src, int n )
	{
		typedef typename AlignTypeD3<ELEMENTALIGN>::type CopyType;
		for ( int i = 0, j = 0; i < n; i += sizeof( CopyType ), ++j )
		{
			static_cast<CopyType*>( dst )[j] = static_cast<const CopyType*>( src )[j];
		}
	}
}

template <typename T>
class ArrayBaseD3LocalForm
{ // local form of hkArray: 0x00d302d0 needs the original constructor stores; shared base construction changes bytes.
	public:
		__forceinline ArrayBaseD3LocalForm() : m_data( 0 ), m_iElementCount( 0 ), m_iCapacityState( DONT_DEALLOCATE_FLAG ) {}
		__forceinline ArrayBaseD3LocalForm( T* buffer, int size, int capacity ) : m_data( buffer ), m_iElementCount( size ), m_iCapacityState( capacity | DONT_DEALLOCATE_FLAG ) {}
		__forceinline ~ArrayBaseD3LocalForm() {}
		__forceinline T& operator[]( int i ) { return m_data[i]; }
		__forceinline int GetLogicalSize() const { return m_iElementCount; }
		__forceinline int getCapacity() const { return ( m_iCapacityState & static_cast<int>( CAPACITY_MASK ) ); }
		__forceinline void clear();
		__forceinline void _clearAndDeallocate( AllocatorD3& alloc );
		__forceinline void removeAtAndCopy( int index );
		__forceinline void GrowArrayCapacity( AllocatorD3& alloc, int n );
		__forceinline void _setSize( AllocatorD3& alloc, int size );
		__forceinline T* _expandAt( AllocatorD3& alloc, int index, int numToInsert );
		__forceinline T* begin() { return m_data; }
		__forceinline T* end() { return m_data + m_iElementCount; }
		static __forceinline void __cdecl copy( T* dst, const T* src, int n );
	protected:
		__forceinline ArrayBaseD3LocalForm<T>& copyFromArray( AllocatorD3& alloc, const ArrayBaseD3LocalForm<T>& src, IsPodTagD3 );
		__forceinline ArrayBaseD3LocalForm<T>& copyFromArray( AllocatorD3& alloc, const ArrayBaseD3LocalForm<T>& src, IsClassTagD3 );
	public:
		enum
		{
			CAPACITY_MASK = int( 0x3FFFFFFF ),
			FLAG_MASK = int( 0xC0000000 ),
			DONT_DEALLOCATE_FLAG = int( 0x80000000 ),
			FORCE_SIGNED = -1
		};
	protected:
		T* m_data;
		int m_iElementCount;
		int m_iCapacityState;
};

template <typename T>
inline void ArrayBaseD3LocalForm<T>::clear()
{
	ArrayUtilD3::destruct( m_data, m_iElementCount, typename PodTraitD3<T>::type() );
	m_iElementCount = 0;
}

template <typename T>
inline void ArrayBaseD3LocalForm<T>::_clearAndDeallocate( AllocatorD3& alloc )
{
	clear();
	if ( ( m_iCapacityState & DONT_DEALLOCATE_FLAG ) == 0 )
	{
		alloc._bufFree<T>( m_data, getCapacity() );
	}
	m_data = 0;
	m_iCapacityState = DONT_DEALLOCATE_FLAG;
}

template <typename T>
inline void ArrayBaseD3LocalForm<T>::removeAtAndCopy( int index )
{
	ArrayUtilD3::destruct( &m_data[index], 1, typename PodTraitD3<T>::type() );
	m_iElementCount--;
	MemUtilD3::CopyRegion<4>( m_data + index, m_data + index + 1, ( m_iElementCount - index ) * sizeof( T ) );
}

template <typename T>
inline void ArrayBaseD3LocalForm<T>::GrowArrayCapacity( AllocatorD3& alloc, int n )
{
	const int capacity = getCapacity();
	if ( capacity < n )
	{
		int cap2 = 2 * capacity;
		int newSize = ( n < cap2 ) ? cap2 : n;
		ArrayUtilD3::hkArrayUtil__reserve( alloc, this, newSize, sizeof( T ) );
	}
}

template <typename T>
inline void ArrayBaseD3LocalForm<T>::_setSize( AllocatorD3& alloc, int n )
{
	GrowArrayCapacity( alloc, n );
	ArrayUtilD3::destruct( m_data + n, m_iElementCount - n, typename PodTraitD3<T>::type() );
	ArrayUtilD3::construct( m_data + m_iElementCount, n - m_iElementCount, typename PodTraitD3<T>::type() );
	m_iElementCount = n;
}

template <typename T>
inline T* ArrayBaseD3LocalForm<T>::_expandAt( AllocatorD3& alloc, int index, int numtoinsert )
{
	const int newsize = numtoinsert + m_iElementCount;
	const int numtomove = m_iElementCount - index;
	if ( newsize > getCapacity() )
	{
		GrowArrayCapacity( alloc, newsize );
	}
	hkMemUtil_memMove( m_data + index + numtoinsert, m_data + index, numtomove * sizeof( T ) );
	ArrayUtilD3::construct( m_data + index, numtoinsert, typename PodTraitD3<T>::type() );
	m_iElementCount = newsize;
	return m_data + index;
}

template <typename T>
inline void __cdecl ArrayBaseD3LocalForm<T>::copy( T* dst, const T* src, int n )
{
	for ( int i = 0; i < n; ++i )
	{
		dst[i] = src[i];
	}
}

template <typename T>
inline ArrayBaseD3LocalForm<T>& ArrayBaseD3LocalForm<T>::copyFromArray( AllocatorD3& alloc, const ArrayBaseD3LocalForm<T>& a, IsPodTagD3 )
{
	if ( getCapacity() < a.GetLogicalSize() )
	{
		if ( ( m_iCapacityState & DONT_DEALLOCATE_FLAG ) == 0 )
		{
			alloc._bufFree<T>( m_data, getCapacity() );
		}
		int n = a.GetLogicalSize();
		m_data = alloc._bufAlloc<T>( n );
		m_iCapacityState = n;
	}
	m_iElementCount = a.GetLogicalSize();
	copy( m_data, a.m_data, m_iElementCount );
	return *this;
}

template <typename T>
inline ArrayBaseD3LocalForm<T>& ArrayBaseD3LocalForm<T>::copyFromArray( AllocatorD3& alloc, const ArrayBaseD3LocalForm<T>& a, IsClassTagD3 )
{
	int oldSize = m_iElementCount;
	int newSize = a.GetLogicalSize();
	int copiedSize = newSize > oldSize ? oldSize : newSize;
	GrowArrayCapacity( alloc, newSize );
	ArrayUtilD3::destruct( m_data + newSize, oldSize - newSize, IsClassTagD3() );
	copy( m_data, a.m_data, copiedSize );
	ArrayUtilD3::constructWithArray( m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize, IsClassTagD3() );
	m_iElementCount = newSize;
	return *this;
}

template <typename T, typename A = HeapAllocD3>
class ArrayD3 : public ArrayBaseD3LocalForm<T>
{
	public:
		__forceinline ArrayD3() : ArrayBaseD3LocalForm<T>() {}
		__forceinline ~ArrayD3() { ClearAndRelease(); }
		__forceinline ArrayD3( T* buffer, int size, int capacity ) : ArrayBaseD3LocalForm<T>( buffer, size, capacity ) {}
		__forceinline ArrayD3& operator=( const ArrayBaseD3LocalForm<T>& a ) { this->copyFromArray( A().get( this ), a, typename PodTraitD3<T>::type() ); return *this; }
		__forceinline ArrayD3& operator=( const ArrayD3& a ) { this->copyFromArray( A().get( this ), a, typename PodTraitD3<T>::type() ); return *this; }
		__forceinline void ClearAndRelease() { ArrayBaseD3LocalForm<T>::_clearAndDeallocate( A().get( this ) ); }
		__forceinline void SetSizeAndGrow( int size ) { ArrayBaseD3LocalForm<T>::_setSize( A().get( this ), size ); }
		__forceinline T* expandAt( int i, int n ) { return ArrayBaseD3LocalForm<T>::_expandAt( A().get( this ), i, n ); }
};

template <typename T, unsigned N, typename A = HeapAllocD3>
class InplaceArrayD3 : public ArrayD3<T, A>
{
	public:
		explicit __forceinline InplaceArrayD3( int size = 0 ) : ArrayD3<T, A>( m_kStorage, size, N ) {}
		__forceinline ~InplaceArrayD3() {}
	protected:
		T m_kStorage[N];
};

template <typename T>
class LocalArrayD3 : public ArrayD3<T>
{
	public:
		__forceinline LocalArrayD3( int capacity )
		{
			this->m_data = allocStack<T>( capacity );
			this->m_iCapacityState = capacity | ArrayD3<T>::DONT_DEALLOCATE_FLAG;
			m_pStackAllocation = this->m_data;
		}
		__forceinline BoolD3 wasReallocated() const { return m_pStackAllocation != this->m_data; }
		__forceinline ~LocalArrayD3()
		{
			if ( !wasReallocated() )
			{
				ArrayD3<T>::clear();
			}
			freeStack<T>( m_pStackAllocation );
		}
		T* m_pStackAllocation;
};

namespace AlgoD3
{
	template <typename T>
	class lessD3
	{
		public:
			__forceinline int operator()( const T& a, const T& b ) { return ( a < b ); }
	};
	void __cdecl QuickSortRange( KeyD3* pArr, int d, int h, lessD3<KeyD3> cmpLess );
	template <typename T, typename L>
	__forceinline void __cdecl quickSort( T* pArr, int iSize, L cmpLess );
	template <typename T>
	__forceinline void __cdecl quickSort( T* pArr, int iSize ) { quickSort( pArr, iSize, lessD3<T>() ); }
	template <typename T, typename L>
	inline void __cdecl quickSort( T* pArr, int iSize, L cmpLess )
	{
		if ( iSize > 1 )
		{
			int low = 0;
			int high = iSize - 1;
			QuickSortRange( pArr, low, high, cmpLess );
		}
	}
}

class MonitorD3;

template <typename T>
struct TlsSlotD3
{
	__forceinline T getData() const { return (T)(unsigned long)TlsGetValue( m_slotID ); }
	unsigned long m_slotID;
};

extern TlsSlotD3<MonitorD3*> DAT_0126835c;

class MonitorD3
{
	public:
		static MonitorD3& GetMonitorStream() { return *DAT_0126835c.getData(); }
		__forceinline char* __cdecl GetStreamEnd() { return m_kRayEnd.val(); }
		__forceinline char* __cdecl getCapacityMinus16() { return m_pCurrentCommand.val(); }
		__forceinline BoolD3 __cdecl memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
		__forceinline void __cdecl setEnd( char* ptr ) { m_kRayEnd = ptr; }
		PadD3<char*> m_kRayStart;
		PadD3<char*> m_kRayEnd;
		PadD3<char*> m_pRayCursor;
		PadD3<char*> m_pCurrentCommand;
		BoolD3 m_bFlag;
		struct CommandD3
		{
			const char* m_pCommandName;
		};
		struct TimerCommandD3 : public CommandD3
		{
			UInt32D3 m_uiStartTicks;
			UInt32D3 m_uiEndTicks;
			__forceinline void setTime();
		};
		struct TimerBeginListCommandD3 : public TimerCommandD3
		{
			const char* m_pFirst;
		};
};

inline void MonitorD3::TimerCommandD3::setTime()
{
	UInt32D3 ticks;
	__asm {
		rdtsc
		mov dword ptr[ticks], eax
	}
	m_uiStartTicks = ticks;
}

class RefObjectD3
{
	public:
		virtual ~RefObjectD3() {}
		unsigned short m_usMemSizeAndFlags;
		short m_sReferenceCount;
};

typedef __declspec(align(16)) char ShapeBufferD3[512];

class ShapeContainerD3
{
	public:
		virtual ~ShapeContainerD3() {}
		virtual int GetNumChildShapes() const;
		virtual KeyD3 GetFirstKey() const = 0;
		virtual KeyD3 GetNextShapeKey( KeyD3 oldKey ) const = 0;
		virtual UInt32D3 GetFilterInfoForKey( KeyD3 key ) const;
		virtual const ShapeD3* GetShapeForKey( KeyD3 key, ShapeBufferD3& buffer ) const = 0;
};

class ShapeD3 : public RefObjectD3
{
	public:
		__forceinline ShapeTypeD3 getType() const;
		__forceinline void getAabb( const XformD3& localToWorld, RealD3 tolerance, AabbD3& out ) const { CalculateAabb( localToWorld, tolerance, out ); }
		virtual const void* getClassType() const;
		virtual void calcContentStatistics( void* collector, const void* cls ) const;
		virtual RealD3 getMaximumProjection( const Vec4D3& direction ) const;
		virtual const ShapeContainerD3* GetShapeContainer() const { return 0; }
		virtual bool isConvex() const { return false; }
		virtual int CalcSizeForSpu( const void* input, int spuBufferSizeLeft ) const;
	protected:
		virtual void CalculateAabb( const XformD3& localToWorld, RealD3 tolerance, AabbD3& out ) const = 0;
	public:
		UInt32D3 m_ulUserData;
		EnumD3<ShapeTypeD3, UInt32D3> m_type;
};

class __declspec(align(16)) AlignedShape : public ShapeD3
{
	AlignedShape();
};

inline ShapeTypeD3 ShapeD3::getType() const { return static_cast<const AlignedShape*>( this )->m_type; }

class TriShapeD3 : public ShapeD3
{
	public:
		__forceinline const Vec4D3& getVertex( int i ) const { return ( &m_kVertexA )[i]; }
		UInt32D3 unk10;
		UInt32D3 unk14;
		UInt32D3 unk18;
		UInt32D3 unk1c;
		Vec4D3 m_kVertexA;
		Vec4D3 m_kVertexB;
		Vec4D3 m_kVertexC;
};

class BvTreeShapeD3 : public ShapeD3
{
	public:
		virtual void IntersectRayWithShape() const;
		virtual void CastRayWithCollector() const;
		virtual void CastRayBundle() const;
		virtual void GetObbHits() const = 0;
		virtual void GetAabbHits( const AabbD3& aabb, ArrayD3<KeyD3>& hits ) const = 0;
		virtual const ShapeContainerD3* GetShapeContainer() const = 0;
};

struct CollisionInputD3;
struct ProcessInputD3;
struct ProcessOutputD3;
class ConstraintOwnerD3;
class ContactMgrD3;
class AgentD3;

class CCFilterD3
{
	public:
		virtual ~CCFilterD3() {}
};

class SCFilterD3
{
	public:
		virtual BoolD3 IsCollisionEnabled( const CollisionInputD3& input, const hkpCdBody& a, const hkpCdBody& b, const ShapeContainerD3& bContainer, KeyD3 bKey ) const = 0;
		virtual BoolD3 IsCollisionEnabled( const CollisionInputD3& input, const hkpCdBody& a, const hkpCdBody& b, const ShapeContainerD3& cA, const ShapeContainerD3& m_ucPackageByte, KeyD3 kA, KeyD3 kB ) const = 0;
};

class FilterD3 : public RefObjectD3, public CCFilterD3, public SCFilterD3
{
	public:
		virtual BoolD3 IsCollisionEnabled( const CollisionInputD3& input, const hkpCdBody& a, const hkpCdBody& b, const ShapeContainerD3& bContainer, KeyD3 bKey ) const = 0;
		virtual BoolD3 IsCollisionEnabled( const CollisionInputD3& input, const hkpCdBody& a, const hkpCdBody& b, const ShapeContainerD3& cA, const ShapeContainerD3& m_ucPackageByte, KeyD3 kA, KeyD3 kB ) const = 0;
};

class DispatcherD3
{
	public:
		typedef AgentD3* ( __cdecl *CreateFuncD3 )( const hkpCdBody& collA, const hkpCdBody& collB, const CollisionInputD3& env, ContactMgrD3* mgr );
		struct AgentFuncsD3
		{
			CreateFuncD3 m_pCreateFunc;
			void* m_pQueryPenetrationsFunc;
			void* m_pGetPenetrationsFunc;
			void* m_pLinearCastFunc;
			BoolD3 m_bIsFlipped;
			BoolD3 m_bIsPredictive;
			AgentFuncsD3() : m_bIsFlipped( false ), m_bIsPredictive( false ) {}
		};
		enum IsAgentPredictiveD3 { IS_NOT_PREDICTIVE, IS_PREDICTIVE };
		__forceinline CreateFuncD3 getCollisionAgentCreationFunction( ShapeTypeD3 typeA, ShapeTypeD3 typeB, IsAgentPredictiveD3 predictive ) const
		{
			int idx = ( predictive ? m_agent3TypeMap : m_agent2TypeMap )[typeA][typeB];
			return m_agent2Funcs[idx].m_pCreateFunc;
		}
		__forceinline AgentD3* getNewCollisionAgent( const hkpCdBody& collA, const hkpCdBody& collB, const CollisionInputD3& environment, ContactMgrD3* mgr ) const;
		UInt32D3 unk000;
		UInt32D3 unk004;
		UInt32D3 unk008;
		UInt32D3 unk00c;
		UInt32D3 unk010;
		UInt32D3 unk014;
		UInt32D3 unk018;
		UInt32D3 unk01c;
		UInt32D3 unk020;
		UInt32D3 unk024;
		UInt32D3 unk028;
		UInt32D3 unk02c;
		UInt32D3 unk030;
		UInt32D3 unk034;
		UInt32D3 unk038;
		UInt32D3 unk03c;
		UInt32D3 unk040;
		UInt32D3 unk044;
		UInt32D3 unk048;
		UInt32D3 unk04c;
		UInt32D3 unk050;
		UInt32D3 unk054;
		UInt32D3 unk058;
		UInt32D3 unk05c;
		UInt32D3 unk060;
		UInt32D3 unk064;
		UInt32D3 unk068;
		UInt32D3 unk06c;
		UInt32D3 unk070;
		UInt32D3 unk074;
		UInt32D3 unk078;
		UInt32D3 unk07c;
		UInt32D3 unk080;
		UInt32D3 unk084;
		UInt32D3 unk088;
		UInt32D3 unk08c;
		UInt32D3 unk090;
		UInt32D3 unk094;
		UInt32D3 unk098;
		UInt32D3 unk09c;
		UInt32D3 unk0a0;
		UInt32D3 unk0a4;
		UInt32D3 unk0a8;
		UInt32D3 unk0ac;
		UInt32D3 unk0b0;
		UInt32D3 unk0b4;
		UInt32D3 unk0b8;
		UInt32D3 unk0bc;
		UInt32D3 unk0c0;
		UInt32D3 unk0c4;
		UInt32D3 unk0c8;
		UInt32D3 unk0cc;
		UInt32D3 unk0d0;
		UInt32D3 unk0d4;
		UInt32D3 unk0d8;
		UInt32D3 unk0dc;
		UInt32D3 unk0e0;
		UInt32D3 unk0e4;
		UInt32D3 unk0e8;
		UInt32D3 unk0ec;
		UInt32D3 unk0f0;
		UInt32D3 unk0f4;
		UInt32D3 unk0f8;
		UInt32D3 unk0fc;
		UInt32D3 unk100;
		UInt32D3 unk104;
		UInt32D3 unk108;
		UInt32D3 unk10c;
		UInt32D3 unk110;
		UInt32D3 unk114;
		UInt32D3 unk118;
		UInt32D3 unk11c;
		UInt32D3 unk120;
		UInt32D3 unk124;
		UInt32D3 unk128;
		UInt32D3 unk12c;
		UInt32D3 unk130;
		UInt32D3 unk134;
		UInt32D3 unk138;
		UInt32D3 unk13c;
		UInt32D3 unk140;
		UInt32D3 unk144;
		UInt32D3 unk148;
		UInt32D3 unk14c;
		UInt32D3 unk150;
		UInt32D3 unk154;
		UInt32D3 unk158;
		UInt32D3 unk15c;
		UInt32D3 unk160;
		UInt32D3 unk164;
		UInt32D3 unk168;
		UInt32D3 unk16c;
		UInt32D3 unk170;
		UInt32D3 unk174;
		UInt32D3 unk178;
		UInt32D3 unk17c;
		UInt32D3 unk180;
		UInt32D3 unk184;
		UInt32D3 unk188;
		UInt32D3 unk18c;
		UInt32D3 unk190;
		UInt32D3 unk194;
		UInt32D3 unk198;
		UInt32D3 unk19c;
		__declspec(align(16)) unsigned char m_agent2TypeMap[32][32];
		unsigned char m_agent3TypeMap[32][32];
		AgentFuncsD3 m_agent2Funcs[64];
};

struct CollisionInputD3
{
	PadD3<DispatcherD3*> m_pCollisionDispatcher;
	PadD3<int> m_collisionQuality;
	PadD3<RealD3> m_fScalar;
	PadD3<const FilterD3*> m_iFilter;
	PadD3<const void*> m_pConvexListCollisionFilter;
	mutable PadD3<int> m_bCreatePredictiveAgents;
	struct Aabb32InfoD3
	{
		Vec4D3 m_kAabbMin;
		Vec4D3 m_kAabbMaximum;
		Vec4D3 m_kAabbScale;
	};
	Aabb32InfoD3 m_aiValues;
};

inline AgentD3* DispatcherD3::getNewCollisionAgent( const hkpCdBody& collA, const hkpCdBody& collB, const CollisionInputD3& environment, ContactMgrD3* mgr ) const
{
	const ShapeTypeD3 typeA = reinterpret_cast<const ShapeD3*>(collA.getShape())->getType();
	const ShapeTypeD3 typeB = reinterpret_cast<const ShapeD3*>(collB.getShape())->getType();
	DispatcherD3::IsAgentPredictiveD3 predictive = static_cast<DispatcherD3::IsAgentPredictiveD3>( (int)environment.m_bCreatePredictiveAgents.val() );
	CreateFuncD3 f = getCollisionAgentCreationFunction( typeA, typeB, predictive );
	return f( collA, collB, environment, mgr );
}


#include "../../../../../../../include/hkStepInfo.h"


struct QualityInfoD3
{
	RealD3 m_fMinimumCollisionSeparation;
	RealD3 m_fMinimumExtraSeparation;
	RealD3 m_fMaximumExtraSeparation;
	RealD3 m_fTimeOfImpactSeparation;
	PadD3<int> m_iQualityInfoValue10;
};

struct ProcessInputD3 : public CollisionInputD3
{
	hkStepInfo m_pStepInfo;
	mutable PadD3<QualityInfoD3*> m_pCollisionQualityInfo;
};

struct ProcessOutputD3
{
	void* m_pAlignedPairData;
	PadD3<ConstraintOwnerD3*> m_pConstraintOwner;
};

class AgentD3 : public RefObjectD3
{
	public:
		virtual const void* getClassType() const;
		virtual void calcContentStatistics( void* collector, const void* cls ) const;
		virtual void getPenetrations( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInputD3& input, void* collector ) = 0;
		virtual void getClosestPoints( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInputD3& input, void* collector ) = 0;
		virtual void linearCast( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const void* input, void* collector, void* startCollector ) = 0;
		virtual void ProcessAgent( const hkpCdBody& a, const hkpCdBody& b, const ProcessInputD3& input, ProcessOutputD3& result ) = 0;
		virtual void cleanup( ConstraintOwnerD3& info ) = 0;
		ContactMgrD3* m_pContactManager;
};

class NullAgentD3 : public AgentD3
{
	public:
		static NullAgentD3* __cdecl hkpNullAgent_getNullAgent();
};

class DispatchHelperD3
{
	public:
		DispatchHelperD3( const hkpCdBody& body ) : m_pBodyB( &body )
		{
		}
		__forceinline const hkpCdBody* getBodyB( const hkpCdBody& cIn, const CollisionInputD3& input, KeyD3 key )
		{
			m_pBodyB.SetCollisionShapeAndKey(reinterpret_cast<const hkpShape*>(m_shapeContainerB->GetShapeForKey( key, m_kShapeBufferB )), key );
			return &m_pBodyB;
		}
		__forceinline const ShapeContainerD3* getShapeContainerB()
		{
			return m_shapeContainerB;
		}
		const ShapeContainerD3* m_shapeContainerB;
		hkpCdBody m_pBodyB;
		ShapeBufferD3 m_kShapeBufferB;
};

template <class KEYD3, class ENTRYD3, class HELPERD3>
class DispatchUtilD3
{
	public:
		static __forceinline void __cdecl update( ArrayD3<ENTRYD3>& entries, ArrayD3<KEYD3>& keys, const hkpCdBody& cA, const hkpCdBody& m_ucPackageByte,
			const CollisionInputD3& input, ContactMgrD3* mgr, ConstraintOwnerD3& constraintOwner, HELPERD3& base );
		static __forceinline void __cdecl fastUpdate( ArrayD3<ENTRYD3>& entries, ArrayD3<KEYD3>& hitList, const hkpCdBody& cA, const hkpCdBody& m_ucPackageByte,
			const CollisionInputD3& input, ContactMgrD3* mgr, ConstraintOwnerD3& constraintOwner, HELPERD3& base );
};

template <class KEYD3, class ENTRYD3, class HELPERD3>
void __cdecl DispatchUtilD3<KEYD3, ENTRYD3, HELPERD3>::update( ArrayD3<ENTRYD3>& entries, ArrayD3<KEYD3>& keys, const hkpCdBody& cA, const hkpCdBody& m_ucPackageByte,
	const CollisionInputD3& input, ContactMgrD3* mgr, ConstraintOwnerD3& constraintOwner, HELPERD3& base )
{
	ENTRYD3* oldEntriesItr = entries.begin();
	ENTRYD3* oldEntriesEnd = entries.end();

	KEYD3* newKeysItr = keys.begin();
	KEYD3* newKeysEnd = keys.end();

	LocalArrayD3<ENTRYD3> newEntries( keys.GetLogicalSize() );
	newEntries.SetSizeAndGrow( keys.GetLogicalSize() );

	const ShapeContainerD3* shapeContainer = base.getShapeContainerB();

	ENTRYD3* newEntriesItr = newEntries.begin();

	while ( oldEntriesItr != oldEntriesEnd && newKeysItr != newKeysEnd )
	{
		if ( *newKeysItr == oldEntriesItr->GetIteratorKey() )
		{
			*newEntriesItr = *oldEntriesItr;
			newEntriesItr++;
			oldEntriesItr++;
			newKeysItr++;
			continue;
		}
		if ( *newKeysItr < oldEntriesItr->GetIteratorKey() )
		{
			const hkpCdBody& bodyA = cA;
			const hkpCdBody& bodyB = m_ucPackageByte;
			const hkpCdBody& modifiedB = *base.getBodyB( m_ucPackageByte, input, *newKeysItr );
			if ( input.m_iFilter->IsCollisionEnabled( input, bodyA, bodyB, *shapeContainer, *newKeysItr ) )
			{
				newEntriesItr->m_pCollisionAgent = input.m_pCollisionDispatcher->getNewCollisionAgent( bodyA, modifiedB, input, mgr );
			}
			else
			{
				newEntriesItr->m_pCollisionAgent = NullAgentD3::hkpNullAgent_getNullAgent();
			}
			newEntriesItr->setKey( *newKeysItr );
			newEntriesItr++;
			newKeysItr++;
			continue;
		}
		if ( oldEntriesItr->m_pCollisionAgent )
		{
			oldEntriesItr->m_pCollisionAgent->cleanup( constraintOwner );
		}
		oldEntriesItr++;
	}

	while ( oldEntriesItr != oldEntriesEnd )
	{
		if ( oldEntriesItr->m_pCollisionAgent )
		{
			oldEntriesItr->m_pCollisionAgent->cleanup( constraintOwner );
		}
		oldEntriesItr++;
	}

	while ( newKeysItr != newKeysEnd )
	{
		const hkpCdBody& bodyA = cA;
		const hkpCdBody& bodyB = m_ucPackageByte;
		const hkpCdBody& modifiedB = *base.getBodyB( m_ucPackageByte, input, *newKeysItr );
		if ( input.m_iFilter->IsCollisionEnabled( input, bodyA, bodyB, *shapeContainer, *newKeysItr ) )
		{
			newEntriesItr->m_pCollisionAgent = input.m_pCollisionDispatcher->getNewCollisionAgent( bodyA, modifiedB, input, mgr );
		}
		else
		{
			newEntriesItr->m_pCollisionAgent = NullAgentD3::hkpNullAgent_getNullAgent();
		}
		newEntriesItr->setKey( *newKeysItr );
		newEntriesItr++;
		newKeysItr++;
	}

	entries = newEntries;
}

template <class KEYD3, class ENTRYD3, class HELPERD3>
void __cdecl DispatchUtilD3<KEYD3, ENTRYD3, HELPERD3>::fastUpdate( ArrayD3<ENTRYD3>& entries, ArrayD3<KEYD3>& hitList, const hkpCdBody& cA, const hkpCdBody& m_ucPackageByte,
	const CollisionInputD3& input, ContactMgrD3* mgr, ConstraintOwnerD3& constraintOwner, HELPERD3& base )
{
	{
		ENTRYD3* itr = entries.begin();
		ENTRYD3* end = entries.end();
		KEYD3* lastHit = hitList.begin();
		KEYD3* endHitList = hitList.end();

		for ( ; itr != end; itr++ )
		{
			if ( lastHit != endHitList && itr->GetIteratorKey() == *lastHit )
			{
				lastHit++;
				continue;
			}
			for ( lastHit = hitList.begin(); lastHit != endHitList; lastHit++ )
			{
				if ( itr->GetIteratorKey() == *lastHit )
				{
					lastHit++;
					goto hitFound;
				}
			}
			itr->m_pCollisionAgent->cleanup( constraintOwner );
			entries.removeAtAndCopy( int( itr - entries.begin() ) );
			itr--;
			end--;
hitFound:
			;
		}
	}

	const ShapeContainerD3* shapeContainer = base.getShapeContainerB();

	if ( hitList.GetLogicalSize() != entries.GetLogicalSize() )
	{
		ENTRYD3* lastHit = entries.begin();
		ENTRYD3* end = entries.end();
		KEYD3* hitItr = hitList.begin();
		KEYD3* endHitList = hitList.end();

		for ( ; hitItr != endHitList; hitItr++ )
		{
			if ( lastHit != end && lastHit->GetIteratorKey() == *hitItr )
			{
				lastHit++;
				continue;
			}
			int index = int( hitItr - hitList.begin() );
			lastHit = entries.expandAt( index, 1 );

			const hkpCdBody& bodyA = cA;
			const hkpCdBody& bodyB = m_ucPackageByte;
			const hkpCdBody& modifiedB = *base.getBodyB( m_ucPackageByte, input, *hitItr );
			if ( input.m_iFilter->IsCollisionEnabled( input, bodyA, bodyB, *shapeContainer, *hitItr ) )
			{
				lastHit->m_pCollisionAgent = input.m_pCollisionDispatcher->getNewCollisionAgent( bodyA, modifiedB, input, mgr );
			}
			else
			{
				lastHit->m_pCollisionAgent = NullAgentD3::hkpNullAgent_getNullAgent();
			}
			lastHit->m_key = *hitItr;
			end = entries.end();
			lastHit++;
		}
	}
}

enum ResultD3 { RES_SUCCESS = 0, RES_FAILURE = 1 };

class BvTreeAgentD3 : public AgentD3
{
	public:
		void hkpBvTreeAgent_processCollision( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ProcessInputD3& input, ProcessOutputD3& result );
		static __forceinline ResultD3 __cdecl BuildCollisionHitList( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const XformD3& bTa,
			const Vec4D3& linearTimInfo, const ProcessInputD3& input, AabbD3* cachedAabb, ArrayD3<KeyD3>& hitListOut );
	protected:
		__forceinline void prepareCollisionPartnersProcess( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ProcessInputD3& input, ConstraintOwnerD3& constraintOwner );
		struct EntryInfoD3
		{
			KeyD3 m_key;
			int m_iValueAtOffset4;
			AgentD3* m_pCollisionAgent;
			KeyD3& GetIteratorKey() { return m_key; }
			void setKey( KeyD3& key ) { m_key = key; }
		};
		ArrayD3<EntryInfoD3> m_kEntries;
		AabbD3 m_kBoundingBox;
};



inline ResultD3 __cdecl BvTreeAgentD3::BuildCollisionHitList( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const XformD3& bTa,
	const Vec4D3& linearTimInfo, const ProcessInputD3& input, AabbD3* cachedAabb, ArrayD3<KeyD3>& hitListOut )
{
	AabbD3 aabb;
	{
		const MotionStateD3* msA = reinterpret_cast<const MotionStateD3*>(bodyA.GetMotionState());
		const MotionStateD3* msB = reinterpret_cast<const MotionStateD3*>(bodyB.GetMotionState());

		Vec4D3 timInfo;
		timInfo.rotInvDir( reinterpret_cast<const XformD3&>(bodyB.getTransform()).getRotation(), linearTimInfo );

		Vec4D3 aabbExtents;
		if ( input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val() )
		{
			RealD3 secOrdErrA = ( msA->m_kDeltaAngle(3) + msB->m_kDeltaAngle(3) ) * msA->m_fObjectRadius;
			RealD3 secOrdErrB = msB->m_kDeltaAngle(3) * msB->m_kDeltaAngle(3) * msB->m_fObjectRadius;
			RealD3 checkEpsilon = input.m_fScalar * 0.5 + ( secOrdErrA + secOrdErrB );
			reinterpret_cast<const ShapeD3*>(bodyA.getShape())->getAabb( bTa, checkEpsilon, aabb );

			Vec4D3 massCenterAinB;
			{
				Vec4D3 radius4; radius4.setAll3( input.m_fScalar * 0.5 + msA->m_fObjectRadius + secOrdErrB );
				massCenterAinB.xformInvPos( reinterpret_cast<const XformD3&>(bodyB.getTransform()), msA->getSweptTransform().m_vCenterOfMass1 );
				Vec4D3 maxR; maxR.setAdd4( massCenterAinB, radius4 );
				Vec4D3 minR; minR.setSub4( massCenterAinB, radius4 );
				aabb.m_kMinimumCorner.setMax4( aabb.m_kMinimumCorner, minR );
				aabb.m_kMaximumCorner.setMin4( aabb.m_kMaximumCorner, maxR );
			}
			aabbExtents.setSub4( aabb.m_kMaximumCorner, aabb.m_kMinimumCorner );
			{
				if ( msB->m_kDeltaAngle(3) > 0.0 )
				{
					Vec4D3 relPos; relPos.setSub4( massCenterAinB, msB->getSweptTransform().m_vCenterOfMassLocal );
					Vec4D3 offsetOut; offsetOut.setCross( relPos, msB->m_kDeltaAngle );
					RealD3 f = input.m_pStepInfo.m_fTimeStep * msB->getSweptTransform().getInvDeltaTime();
					timInfo.addMul4( f, offsetOut );
				}
				Vec4D3 zero; zero.setZero4();
				Vec4D3 minPath; minPath.setMin4( zero, timInfo );
				Vec4D3 maxPath; maxPath.setMax4( zero, timInfo );
				aabb.m_kMinimumCorner.add4( minPath );
				aabb.m_kMaximumCorner.add4( maxPath );
			}
		}
		else
		{
			RealD3 checkEpsilon = input.m_fScalar * 0.5;
			reinterpret_cast<const ShapeD3*>(bodyA.getShape())->getAabb( bTa, checkEpsilon, aabb );
			aabbExtents.setSub4( aabb.m_kMaximumCorner, aabb.m_kMinimumCorner );
		}

		if ( cachedAabb )
		{
			if ( cachedAabb->contains( aabb ) )
			{
				return RES_FAILURE;
			}
			Vec4D3 zero; zero.setZero4();
			Vec4D3 minPath; minPath.setMin4( zero, timInfo );
			Vec4D3 maxPath; maxPath.setMax4( zero, timInfo );

			Vec4D3 expand4; expand4.setAll3( input.m_fScalar * 0.5 );
			aabb.m_kMinimumCorner.sub4( expand4 );
			aabb.m_kMaximumCorner.add4( expand4 );

			RealD3 maxExpand = 0.4f;
			RealD3 framesLookAhead = -2.0f;
			Vec4D3 minExtentPath; minExtentPath.setMul4( framesLookAhead, maxPath );
			Vec4D3 maxExtentPath; maxExtentPath.setMul4( framesLookAhead, minPath );
			Vec4D3 maxExpand4; maxExpand4.setMul4( maxExpand, aabbExtents );
			maxExtentPath.setMin4( maxExtentPath, maxExpand4 );
			Vec4D3 minExpand4; minExpand4.setNeg4( maxExpand4 );
			minExtentPath.setMax4( minExtentPath, minExpand4 );
			aabb.m_kMinimumCorner.add4( minExtentPath );
			aabb.m_kMaximumCorner.add4( maxExtentPath );
			*cachedAabb = aabb;
		}
	}
	const BvTreeShapeD3* bvB = static_cast<const BvTreeShapeD3*>( reinterpret_cast<const ShapeD3*>(bodyB.getShape()) );
	bvB->GetAabbHits( aabb, hitListOut );
	return RES_SUCCESS;
}

inline void BvTreeAgentD3::prepareCollisionPartnersProcess( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ProcessInputD3& input, ConstraintOwnerD3& constraintOwner )
{
	ResultD3 prepareSuccessfull;
	InplaceArrayD3<KeyD3,128> hitList;
	{
		XformD3 bTa;
		{
			const XformD3& wTb = reinterpret_cast<const XformD3&>(bodyB.getTransform());
			const XformD3& wTa = reinterpret_cast<const XformD3&>(bodyA.getTransform());
			bTa.hkTransform_setMulInverseMul( wTb, wTa );
		}
		Vec4D3 linearTimInfo;
		{
			const MotionStateD3* msA = reinterpret_cast<const MotionStateD3*>(bodyA.GetMotionState());
			const MotionStateD3* msB = reinterpret_cast<const MotionStateD3*>(bodyB.GetMotionState());
			SweptUtilD3::calcTimInfo( *msA, *msB, input.m_pStepInfo.m_fTimeStep, linearTimInfo );
		}
		AabbD3* cachedAabb = ( reinterpret_cast<const BoolD3&>(DAT_011b4284) ) ? &m_kBoundingBox : 0;
		prepareSuccessfull = BuildCollisionHitList( bodyA, bodyB, bTa, linearTimInfo, input, cachedAabb, hitList );
	}

	if ( prepareSuccessfull != RES_SUCCESS )
	{
		return;
	}

	{
		const BvTreeShapeD3* bvB = static_cast<const BvTreeShapeD3*>( reinterpret_cast<const ShapeD3*>(bodyB.getShape()) );
		const ShapeContainerD3* shapeContainer = bvB->GetShapeContainer();
		DispatchHelperD3 helper( bodyB );
		helper.m_shapeContainerB = shapeContainer;

		if ( reinterpret_cast<const BoolD3&>(DAT_01268ad4) )
		{
			DispatchUtilD3<KeyD3, EntryInfoD3, DispatchHelperD3>::fastUpdate( m_kEntries, hitList, bodyA, bodyB, input, m_pContactManager, constraintOwner, helper );
		}
		else
		{
			AlgoD3::quickSort( hitList.begin(), hitList.GetLogicalSize() );
			DispatchUtilD3<KeyD3, EntryInfoD3, DispatchHelperD3>::update( m_kEntries, hitList, bodyA, bodyB, input, m_pContactManager, constraintOwner, helper );
		}
	}
}

// @fnv 0x00d302d0
// src: HAVOK_SRC 0x00d302d0
void BvTreeAgentD3::hkpBvTreeAgent_processCollision( const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ProcessInputD3& input, ProcessOutputD3& result )
{
	{
		MonitorD3& mStream = MonitorD3::GetMonitorStream();
		if ( mStream.memoryAvailable() )
		{
			MonitorD3::TimerBeginListCommandD3* h = reinterpret_cast<MonitorD3::TimerBeginListCommandD3*>( mStream.GetStreamEnd() );
			h->m_pCommandName = "LtBvTree";
			h->m_pFirst = "StQueryTree";
			h->setTime();
			mStream.setEnd( (char*)( h + 1 ) );
		}
	}

	prepareCollisionPartnersProcess( bodyA, bodyB, input, *result.m_pConstraintOwner.val() );

	EntryInfoD3* itr = m_kEntries.begin();
	EntryInfoD3* end = m_kEntries.end();

	hkpCdBody modifiedBodyB( &bodyB );

	{
		MonitorD3& mStream = MonitorD3::GetMonitorStream();
		if ( mStream.memoryAvailable() )
		{
			MonitorD3::TimerCommandD3* h = reinterpret_cast<MonitorD3::TimerCommandD3*>( mStream.GetStreamEnd() );
			h->m_pCommandName = "StNarrowPhase";
			h->setTime();
			mStream.setEnd( (char*)( h + 1 ) );
		}
	}
	const BvTreeShapeD3* bvB = static_cast<const BvTreeShapeD3*>( reinterpret_cast<const ShapeD3*>(bodyB.getShape()) );
	const ShapeContainerD3* shapeContainer = bvB->GetShapeContainer();
	ShapeBufferD3 shapeBuffer;
	while ( itr != end )
	{
		const ShapeD3* shape = shapeContainer->GetShapeForKey( itr->m_key, shapeBuffer );
		modifiedBodyB.SetCollisionShapeAndKey(reinterpret_cast<const hkpShape*>(shape), itr->m_key );

		if ( 0 )
		{
			const TriShapeD3* t = static_cast<const TriShapeD3*>( shape );
			Vec4D3 offset = reinterpret_cast<const XformD3&>(bodyB.getTransform()).getTranslation();
			Vec4D3 a; a.setAdd4( t->getVertex(0), offset );
			Vec4D3 b; b.setAdd4( t->getVertex(1), offset );
			Vec4D3 c; c.setAdd4( t->getVertex(2), offset );
			Vec4D3 center; center.setAdd4( a, b );
			center.add4( c );
			center.mul4( 1.0f / 3.0f );
		}

		itr->m_pCollisionAgent->ProcessAgent( bodyA, modifiedBodyB, input, result );
		itr++;
	}
	{
		MonitorD3& mStream = MonitorD3::GetMonitorStream();
		if ( mStream.memoryAvailable() )
		{
			MonitorD3::TimerCommandD3* h = reinterpret_cast<MonitorD3::TimerCommandD3*>( mStream.GetStreamEnd() );
			h->m_pCommandName = "lt";
			h->setTime();
			mStream.setEnd( (char*)( h + 1 ) );
		}
	}
}
