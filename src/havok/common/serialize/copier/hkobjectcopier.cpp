#include "../../../../../include/hkArray.h"
// havok/common/serialize/copier/hkobjectcopier.cpp: Object, Host (12 functions)

#include "fnv_asm_helpers.h"
#include "../../../../../include/Pair.h"
// src/havok/common/serialize/copier/hkobjectcopier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/copier/hkobjectcopier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Compares byte 0xc of two entries and returns 1 if equal and byte 0xd also matches or byte 0xc is 0x18, otherwise 0.
// @fnv 0x00e032d0
// src: HAVOK_SRC 0x00e032d0
int __stdcall hkObjectCopier_areMembersCompatible(const void* a, const void* b)
{
    const unsigned char* pa = static_cast<const unsigned char*>(a);
    const unsigned char* pb = static_cast<const unsigned char*>(b);
    if (pa[0xc] == pb[0xc] && (pa[0xd] == pb[0xd] || pa[0xc] == 0x18))
        return 1;
    return 0;
}

// @fnv 0x00e049c0
// src: GUESS 0x00e049c0 (confidence: low)
int __cdecl Object_ComputeValue_00e049c0(int a, int b)
{
    return a < b ? a : b;
}

extern int DAT_0102e388;
struct Object {
    int* vtable;
    void SetVirtualTable_00e03160();
};
// @fnv 0x00e03160
// src: GUESS 0x00e03160 (confidence: low)
void Object::SetVirtualTable_00e03160() {
    vtable = &DAT_0102e388;
}

struct E04A00Allocator;

struct E04A00MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    E04A00Allocator* m_pStreamAllocator;

    E04A00Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" E04A00MemoryRouter& __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct E04A00Entry {
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
};

typedef hkArray<E04A00Entry> E04A00EntryArray;
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
return reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap());
}
template<> __forceinline void hkArrayBase<E04A00Entry>::_pushBack(hkMemoryAllocator& sharedAlloc, E04A00Entry const& e)
{
E04A00Allocator& alloc = reinterpret_cast<E04A00Allocator&>(sharedAlloc);

        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(E04A00Entry));
        m_data[m_iElementCount] = e;
        m_iElementCount++;
    
}


struct E04A00Registry {
    int unk00;
    int unk04;
    int unk08;
    E04A00EntryArray m_entries;

    void AddEntry(void* a, void* b, void* c, void* d);
};

// Builds an entry from the four arguments and appends it to m_entries via the registry's allocator.
// @fnv 0x00e04a00
void E04A00Registry::AddEntry(void* a, void* b, void* c, void* d)
{
    E04A00Entry e;
    e.m_kPointA = a;
    e.m_kPointB = b;
    e.m_iThirdValue = c;
    e.m_iFourthElementInteger = d;
    m_entries.pushBack(e);
}

// FUN_00e03100
//
// The object pointer reaches this function in ESI (the compiler passes the
// argument of the internal-linkage function in the callee-saved register),
// and the accessor at 0xd86940 returns the signed short stored at +0x0e of
// the object.  The value is tested once and, when it is not zero, the
// accessor is called a second time (as a tail call) to produce the result;
// when it is zero the function returns 1.
class Obj {
public:
    int m();
};

// @fnv 0x00e03100
// src: GUESS 0x00e03100 (confidence: low)
static int Object_ProcessAndReturnValue_00e03100(Obj* apObj) {
    if (apObj->m()) {
        return apObj->m();
    }
    return 1;
}

// The internal-linkage function above is only called from here, so that the
// compiler keeps it (and gives it the register argument convention).
int keep_alive(Obj* p) {
    int r = p->m();
    return Object_ProcessAndReturnValue_00e03100(p) + r;
}

struct FUN_00e03120 {
    virtual ~FUN_00e03120();
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    bool unk14;

    FUN_00e03120(const int* param1, const int* param2, int param3);
};

// Initializes the object from two int pointers and a third int, setting unk14 by comparing the second byte of the two stored ints.
// @fnv 0x00e03120
FUN_00e03120::FUN_00e03120(const int* piFirst, const int* piSecond, int aiValue)
    : unk06(1)
{
    unk08 = *piFirst;
    unk0C = *piSecond;
    unk10 = aiValue;
    unk14 = ((char*)&unk08)[1] != ((char*)&unk0C)[1];
}

struct Writer {
    void write(const void* data, int elemSize, int count);
};

extern "C" unsigned int* __cdecl FNV_e03300_arena();

// Writes count unsigned ints to w; when elemSize is not 4, widens each into a Pair (a=data[i], b=0) from arena memory and writes that instead.
// @fnv 0x00e03300
static __declspec(noinline) void WriteUIntArray(const unsigned int* data, int count,
                                             Writer* pWriter, int elemSize)
{
    if (elemSize == 4) {
        pWriter->write(data, elemSize, count);
        return;
    }
    unsigned int* pArena = FNV_e03300_arena();
    unsigned int base = *pArena;
    *pArena = base + (((unsigned int)count * 8 + 0x7f) & 0xffffff80u);
    Pair* pPairs = (Pair*)base;
    for (int i = 0; i < count; i++) {
        pPairs[i].a = data[i];
        pPairs[i].b = 0;
    }
    pWriter->write(pPairs, elemSize, count);
    *FNV_e03300_arena() = base;
}

void e03300_driver(Writer* w, int elemSize, const unsigned int* data, int count)
{
    WriteUIntArray(data, count, w, elemSize);
}

// AppendListEntry
//
// The routine is an internal-linkage (static) helper of its module, so MSVC
// 2008 /O2 specialises it: its two pointer parameters arrive in callee-saved
// registers (the manager in EBX, the entry list in ESI) instead of on the
// stack, while the two integer arguments keep their stack slots.  Keeping the
// function static and calling it from exactly one place is what produces that
// convention.
//
// The first object pointer is handed to the module-local helper below, which
// is itself internal-linkage, so its arguments arrive in EDI (the pointer) and
// EAX (the integer).  That is why the caller materialises the constant 2 in
// EAX and lets the pointer stay in EDI across the call.

struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual VObj* v20();
};

struct Ctx
{
    VObj* hkOArchive_getStreamWriter();
    void hkOArchive_writeRaw(int a, int b);
};

struct ListEntry
{
    int m_key;
    void* m_uiFilterValue;
};

struct List
{
    ListEntry* m_data;
    int m_uiItemCount;
    unsigned int m_iCapacityState;
};

int __cdecl hkString_strLen(int);
int __cdecl FUN_00e03360_ext1(int);
int __cdecl FUN_00e03360_ext2(VObj* p);

// Module-local helper: the manager hands it the object it just looked up
// together with a mode value.
// src: GUESS 0x00e03360 (confidence: low)
__declspec(noinline) static void Object_UpdateFields_00e03360(VObj* p, int n)
{
    int k = FUN_00e03360_ext1(n);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext1(k);
    FUN_00e03360_ext1(k);
}

// @fnv 0x00e03e20
static int AppendListEntry(Ctx* ctx, List* list, int a, int b)
{
    VObj* value = ctx->hkOArchive_getStreamWriter();
    Object_UpdateFields_00e03360(value, 2);
    value = ctx->hkOArchive_getStreamWriter()->v20();
    E04A00MemoryRouter& router = hkMemoryRouter_getInstance();
    if (list->m_uiItemCount == (int)(list->m_iCapacityState & 0x3fffffffu))
    {
        ResizeAudioStream(router.m_pStreamAllocator, list, 8);
    }
    ListEntry& entry = list->m_data[list->m_uiItemCount];
    entry.m_key = b;
    entry.m_uiFilterValue = value;
    list->m_uiItemCount++;
    ctx->hkOArchive_writeRaw(a, hkString_strLen(a) + 1);
    return 0;
}

// The helper above is only called from here, which keeps the register
// calling convention the original module was built with.
int keep_alive2(Ctx* ctx, List* list, int a, int b)
{
    return AppendListEntry(ctx, list, a, b);
}

struct Scratch16 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void hkOArchive_InitializeWriterWithByteSwap(unsigned int a, unsigned int b);
    unsigned char* ForwardValueToObject(unsigned int* out);
    void ReleaseReference_00d60590();
};
struct FUN_00e04920_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned char m_flag14;
    unsigned int hkObjectCopier_saveBody(unsigned int a, unsigned int b, Scratch16* scratch, unsigned int c);
    unsigned int hkObjectCopier_saveExtras(unsigned int a, unsigned int b, Scratch16* scratch,
                                unsigned int c, unsigned int d, unsigned int e, unsigned int f);
    int hkObjectCopier_copyObject(unsigned int a1, unsigned int a2, unsigned int a3,
                     unsigned int a4, unsigned int a5);
};

// Calls FUN_00e036b0 and FUN_00e03ea0 with a scratch object, then returns whether the byte from ForwardValueToObject is zero.
// @fnv 0x00e04920
// src: HAVOK_SRC 0x00e04920
int FUN_00e04920_cls::hkObjectCopier_copyObject(unsigned int a1, unsigned int a2,
                                   unsigned int a3, unsigned int a4, unsigned int a5)
{
    Scratch16 scratch;
    VObj* original = reinterpret_cast<VObj*>(a3);
    scratch.hkOArchive_InitializeWriterWithByteSwap(a3, static_cast<unsigned int>(m_flag14));
    unsigned int uiIntermediate = hkObjectCopier_saveBody(a1, a2, &scratch, a4);
    Object_UpdateFields_00e03360(original, 16);
    hkObjectCopier_saveExtras(a1, a2, &scratch, a4, uiIntermediate, a5, 0);
    Object_UpdateFields_00e03360(original, 16);
    unsigned char* status = scratch.ForwardValueToObject(&a1);
    unsigned int success = (*status == 0);
    scratch.ReleaseReference_00d60590();
    return success;
}

// FUN_00e03360: module-local helper (custom register convention: n in EAX, obj in EDI).
// lets the object fill it, then frees it.

struct HeapAlloc
{
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void a0c();
    virtual void ReleaseBlock(void* p, int size);
};

struct MemRouter
{
    char* m_stackCur;
    int unk04;
    int unk08;
    int unk0C;
    HeapAlloc* m_pStreamAllocator;
};

inline MemRouter& Router() { return reinterpret_cast<MemRouter&>(hkMemoryRouter_getInstance()); }
void __cdecl hkArrayUtil__reserve(HeapAlloc* alloc, void* arr, int cap, int elemSize);
extern "C" void* __cdecl FUN_00ec61c0(void* dst, int val, int n);

static __forceinline void Construct(char* p, int c)
{
    for (int i = 0; i < c; ++i)
        p[i] = 0;
}
static __forceinline void Zero(char* p, int c)
{
    FUN_00ec61c0(p, 0, c);
}

struct Reader
{
    virtual void r00();
    virtual void r04();
    virtual void r08();
    virtual void r0c();
    virtual void read(char* buf, int n);
    virtual void r14();
    virtual void r18();
    virtual void r1c();
    virtual int GetReadOffset();
};

struct CharArrayLocalForm
{ // local form of hkArray: 0x00e03360 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    CharArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline void destroy(HeapAlloc* h)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            h->ReleaseBlock(m_data, m_iCapacityState & 0x3fffffff);
    }
    __forceinline void reserve(HeapAlloc* h, int n)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap + cap;
            hkArrayUtil__reserve(h, this, n < c2 ? c2 : n, 1);
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(Router().m_pStreamAllocator, n);
        Construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
};

struct LocalCharArray : CharArrayLocalForm
{
    char* m_localMem;

    LocalCharArray(int n)
    {
        MemRouter& r = Router();
        char* p = r.m_stackCur;
        r.m_stackCur = p + ((n + 0x7f) & ~0x7f);
        m_data = p;
        m_iCapacityState = n | 0x80000000;
        m_localMem = p;
    }
    __forceinline void destroyLocal()
    {
        char* mem = m_localMem;
        if (mem == m_data)
            m_iElementCount = 0;
        Router().m_stackCur = mem;
        destroy(Router().m_pStreamAllocator);
    }
};

// Gets the reader offset and, when the computed mask is nonzero, reads n minus that mask bytes into a local buffer.
// @fnv 0x00e03360
// src: GUESS 0x00e03360 (confidence: low)
static __declspec(noinline) void __cdecl Object_UpdateFields_00e03360(Reader* apReader, int aiCount)
{
    int align = apReader->GetReadOffset();
    LocalCharArray buf(aiCount);
    buf.SetSizeAndGrow(aiCount);
    int iMisalign = (aiCount - 1) & align;
    if (iMisalign != 0)
        apReader->read(buf.m_data, aiCount - iMisalign);
    buf.destroyLocal();
}

void keep_alive_b11425(Reader* obj, int a, int b)
{
    Object_UpdateFields_00e03360(obj, a);
    Object_UpdateFields_00e03360(obj, b + a);
}

struct DiagnosticWriter {
    void* vtbl;                                            // +0
    int unk04;                                             // +4
    void* p;                                               // +8
    void FUN_00cb1600(void* buf, int size);                // (this,buf,size), ret 8
    void ProcessAndReturnValue_00cc01c0(const char* msg);                    // (this,msg), ret 4
    void FUN_00cc00e0();                                   // (this), ret
};

struct Target {
    void WriteSwapped(const void* p, unsigned int n, unsigned int m);              // (this,void*,int,int)
};

struct AssertMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a, unsigned int b, char* c, const char* d, int e);
};

extern AssertMgr* DAT_01268360;
extern const char str_010ea3e4[];
extern const char str_010ea3c8[];

// Calls WriteSwapped for listed type values, adjusting its integer arguments for cases 12 through 18; other values enter the diagnostic path.
// @fnv 0x00e03170
// src: GUESS 0x00e03170 (confidence: medium)
static __declspec(noinline) void Hkobjectcopier_WriteSwappedDataByType(unsigned int a, unsigned int aiSize, unsigned int type, Target* apTarget, void* apData)
{
    switch (type - 1) {
    case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        aiSize >>= 2;
        a *= aiSize;
        aiSize = 4;
        /* fall through */
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 9: case 10: case 31:
        apTarget->WriteSwapped(apData, aiSize, a);
        return;
    case 19: case 20: case 21: case 22: case 24: case 25: case 26: case 27: case 29:
        goto fail;
    default:
fail:
    {
        unsigned int buf[128];
        DiagnosticWriter w;
        w.FUN_00cb1600(buf, 0x200);
        w.ProcessAndReturnValue_00cc01c0(str_010ea3e4);
        if (DAT_01268360->v3(3, 0x747e1e03u, (char*)buf, str_010ea3c8, 0xfb))
            __debugbreak();
        w.FUN_00cc00e0();
        return;
    }
    }
}

void target_driver(unsigned int type, unsigned int count, unsigned int size, void* data, Target* target)
{
    Hkobjectcopier_WriteSwappedDataByType(count, size, type, target, data);
}

namespace fnv_00e036b0 {
extern "C" void _ReadWriteBarrier();
struct Item {
    int f00; int f04; int f08;
    unsigned char type; unsigned char f0d; unsigned char f0e; unsigned char f0f;
    unsigned short f10; unsigned short f12;
    int getName() const { return f00; }
    int FUN_00d86980();
    int getCstyleArraySize();
    void* FUN_00d86930();
    void* getClass();
    int ReadSignedValueBySize(int a);
};
struct EbpObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int v1c(int a, int b);
    virtual int v20();
};
struct ExitObj {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual int v1c(int a);
};
struct HObj {
    int Lookup(int a, void* b);
    int hkClassEnum_getValueOfName(int a, void* b);
    int CollectMatchingEntries(int a, void* b, void* c);
};
struct Inner {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(int a, int b);
};
struct InnerHolder { int f00; int f04; int f08; int f0c; Inner* f10; };
struct Chain {
    Chain* ProcessAndReturnValue_00cc01c0(const void* s, void* a);
    Chain* ProcessAndReturnValue_00cc01c0();
    void FUN_00cc00e0();
};
struct StrBuf {
    char* data; int size; int capacity;
    void FUN_00cb1600(void* a, int n);
};
struct StreamObj {
    EbpObj* hkOArchive_getStreamWriter();
    void WriteInt(int a);
    void FUN_00d60900(int a);
    void FUN_00d605b0(int a);
    void WriteSwapped(const void* data, unsigned int size, unsigned int count);
    void hkOArchive_writeRaw(const void* data, unsigned int size);
    StreamObj* FUN_00d46fe0(int v);
    void* FUN_00d46d40();
};
struct DescriptorList {
    int unk00; int unk04; int unk08;
    int FUN_00d46f00();
    Item* getMember(int i);
    int FUN_00d470d0();
};
struct Host {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(Item* a, Item* b);
    int f04; int f08;
    unsigned char f0c; unsigned char f0d; unsigned char f0e; unsigned char f0f;
    int f10;
    StreamObj* FUN_00d46fe0(int v);
    void hkObjectCopier_writeZero(StreamObj* a, Item* it);
    int hkObjectCopier_saveBody(StreamObj* p0, StreamObj* p1, StreamObj* p2, DescriptorList* p3);
};
extern int DAT_01044c28;
extern int DAT_010ea4ac;
extern int DAT_010ea47c;
extern int DAT_010ea3c8;
extern int DAT_010ea448;
int __cdecl Object_ComputeValue_00e049c0(int a, int b);
int __cdecl hkClass_ProcessEntries_00e03240(DescriptorList* a, Item* it, int i, int e);

// src: GUESS 0x00e03100 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00e03100(Item* p) {
    if (p->getCstyleArraySize()) return p->getCstyleArraySize();
    return 1;
}

extern const char str_010ea3e4[];


struct DiagnosticWriterOrig {
    void* vtbl;
    int unk04;
    void* p;
    void FUN_00cb1600(void* buf, int size);
    DiagnosticWriterOrig* ProcessAndReturnValue_00cc01c0(const void* msg);
    void FUN_00cc00e0();
};
static DiagnosticWriterOrig& wch(DiagnosticWriter& w) { return *(DiagnosticWriterOrig*)&w; }

// src: GUESS 0x00e03170 (confidence: medium)
static __declspec(noinline) void Hkobjectcopier_WriteSwappedDataByType(Target* obj, unsigned int type, unsigned int size, unsigned int count, void* data) {
    switch (type) {
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        count = count * (size / 4);
        size = 4;
        goto output;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 32:
    output:
        obj->WriteSwapped(data, size, count);
        return;
    default: {
        unsigned int storage[128];
        DiagnosticWriter w;
        w.FUN_00cb1600(storage, sizeof(storage));
        w.ProcessAndReturnValue_00cc01c0((const char*)str_010ea3e4);
        if (DAT_01268360->v3(3, 0x747e1e03, (char*)storage, (const char*)&DAT_010ea3c8, 0xfb)) __debugbreak();
        w.FUN_00cc00e0();
        return;
    }
    }
}

static __declspec(noinline) void WriteUIntArray(int count, const unsigned int* data, Writer* w, int elemSize) {
    if (elemSize == 4) {
        w->write(data, elemSize, count);
        return;
    }
    {
        unsigned int* arena = FNV_e03300_arena();
        unsigned int saved = *arena;
        *arena += (count * 8 + 127) & ~127;
        Pair* output = (Pair*)saved;
        for (int index = 0; index < count; ++index) {
            output[index].a = data[index];
            output[index].b = 0;
        }
        w->write(output, elemSize, count);
        *FNV_e03300_arena() = saved;
    }
}

struct PointerValue { int valid; int pointer; int object; };

struct LookupResult { int value; };
struct ValueArray { int* data; int size; int capacity; };
struct Scratch { DiagnosticWriter bad; int out[2]; int pair[2]; int pair2[2]; int buf4[4]; DiagnosticWriter missing; };
// Iterates descriptor items, compares matching items, dispatches by type, and writes values through the supplied stream.
// @fnv 0x00e036b0
// src: XBOX_PDB 0x00e036b0
int Host::hkObjectCopier_saveBody(StreamObj* apSourceStream, StreamObj* apLookupStream, StreamObj* apOutputStream, DescriptorList* apDescriptorList)
{
    struct State0 { void* flagh2; int base; int index; int out40; } state0;
    struct State1 { EbpObj* ebp; int flagq; void* flagh1; LookupResult lookup; } state1;
    struct Work { int local20; int acc; ValueArray values; } work;
    unsigned int storage[128];
    Scratch scratch;
    
    
    state1.ebp = apOutputStream->hkOArchive_getStreamWriter();
    state0.base = state1.ebp->v20();
    for (state0.index = 0; state0.index < apDescriptorList->FUN_00d46f00(); state0.index++) {
        Item* pItem = apDescriptorList->getMember(state0.index);
        state1.ebp->v1c((int)pItem->f12 + state0.base, 0);
        if (pItem->f10 & 0x400) {
            int fl = this->f10;
            if (fl & 2) {
                this->hkObjectCopier_writeZero(apOutputStream, pItem);
                continue;
            }
            if (fl & 1) {
                hkClass_ProcessEntries_00e03240(apDescriptorList, pItem, state0.index, (int)state1.ebp);
                continue;
            }
        }
        {
            Item* nb = (Item*)apLookupStream->FUN_00d46fe0(pItem->getName());
            if (nb && this->v10(nb, pItem)) {
            int iSourceOffset = (int)nb->f12 + (int)apSourceStream;
            switch (pItem->type - 1) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
            case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
            case 16: case 17: case 31: {
                int x = Object_ProcessAndReturnValue_00e03100(nb);
                int y = Object_ProcessAndReturnValue_00e03100(pItem);
                int v = pItem->FUN_00d86980();
                Hkobjectcopier_WriteSwappedDataByType((Target*)apOutputStream, pItem->type, v / y, Object_ComputeValue_00e049c0(x,y), (void*)iSourceOffset);
                break;
            }
            case 29: {
                int x = Object_ProcessAndReturnValue_00e03100(nb);
                int y = Object_ProcessAndReturnValue_00e03100(pItem);
                int r = Object_ComputeValue_00e049c0(x, y);
                WriteUIntArray(r, (const unsigned int*)iSourceOffset, (Writer*)apOutputStream, (int)this->f0c);
                break;
            }
            case 23: {
                if (nb->f08 == 0) break;
                if (pItem->f08 == 0) break;
                int denominator = Object_ProcessAndReturnValue_00e03100(nb);
                int u = Object_ProcessAndReturnValue_00e03100(pItem);
                int iCount = Object_ComputeValue_00e049c0(*(volatile int*)&denominator, u);
                void* h1 = nb->FUN_00d86930();
                void* h2 = pItem->FUN_00d86930();
                int v = nb->FUN_00d86980();
                int iStep = v / denominator;
                if (iCount <= 0) break;
                
                
                do {
                    int r86 = nb->ReadSignedValueBySize(iSourceOffset);
                    work.local20 = 0;
                    LookupResult* __restrict pLookupResult = &state1.lookup;
                    int iResult = ((HObj*)h1)->Lookup(r86, pLookupResult);
                    if (iResult == 0) {
                        ((HObj*)h2)->hkClassEnum_getValueOfName(pLookupResult->value, &work.local20);
                    }
                    switch (iStep) {
                    case 1: apOutputStream->FUN_00d605b0(work.local20); break;
                    case 2: apOutputStream->FUN_00d60900(work.local20); break;
                    case 4: apOutputStream->WriteInt(work.local20); break;
                    }
                    iSourceOffset += iStep;
                    iCount--;
                } while (iCount != 0);
                break;
            }
            case 18: break;
            case 19: case 20: case 28: case 32: {
                int count;
                int rawCount = Object_ProcessAndReturnValue_00e03100(pItem);
                scratch.pair[0] = 0; scratch.pair[1] = 0;
                if (rawCount <= 0) break;
                count = rawCount;
                do {
                    apOutputStream->hkOArchive_writeRaw(scratch.pair, (int)this->f0c);
                    count--;
                } while (count != 0);
                break;
            }
            case 21: case 25: case 26: {
                StreamObj* pStream = apOutputStream;
                int ebpInt = iSourceOffset;
                if (pItem->type == 0x1b) {
                    scratch.pair2[0] = 0; scratch.pair2[1] = 0;
                    pStream->WriteSwapped(scratch.pair2, (int)this->f0c, 1);
                    if (((PointerValue*)ebpInt)->valid != 0) {
                        ebpInt = ((PointerValue*)ebpInt)->object;
                    } else {
                        
                        scratch.missing.FUN_00cb1600(storage, 0x200);
                        wch(scratch.missing).ProcessAndReturnValue_00cc01c0((const void*)&DAT_010ea47c)
                          ->ProcessAndReturnValue_00cc01c0((const void*)apLookupStream->FUN_00d46d40())
                          ->ProcessAndReturnValue_00cc01c0((const void*)&DAT_010ea4ac)
                          ->ProcessAndReturnValue_00cc01c0((const void*)nb->getName())
                          ->ProcessAndReturnValue_00cc01c0((const void*)&DAT_01044c28);
                        DAT_01268360->v3(1, 0xabba5a55, (char*)storage, (const char*)&DAT_010ea3c8, 0x1b8);
                        scratch.missing.FUN_00cc00e0();
                        ebpInt = 0;
                    }
                } else if (pItem->f0d == 0) {
                    ebpInt = 0;
                } else {
                    ebpInt = ((PointerValue*)ebpInt)->pointer;
                }
                {
                    scratch.out[0] = 0; scratch.out[1] = 0;
                    pStream->WriteSwapped(scratch.out, (int)this->f0c, 1);
                    pStream->WriteInt(ebpInt);
                    if (pItem->type == 0x16) {
                        ebpInt |= 0x80000000;
                        pStream->WriteInt(ebpInt);
                    }
                }
                break;
            }
            case 24: {
                void* h1 = nb->getClass();
                void* h2 = pItem->getClass();
                if (!h1) break;
                if (!h2) break;
                int iRemaining = Object_ComputeValue_00e049c0(Object_ProcessAndReturnValue_00e03100(nb), Object_ProcessAndReturnValue_00e03100(pItem));
                int k = 0;
                if (iRemaining <= 0) break;
                do {
                    int v = ((DescriptorList*)h1)->FUN_00d470d0();
                    const char* pElementData = (const char*)iSourceOffset + v * k;
                    this->hkObjectCopier_saveBody((StreamObj*)pElementData, (StreamObj*)h1, apOutputStream, (DescriptorList*)h2);
                    k++;
                } while (k < iRemaining);
                break;
            }
            case 27: {
                scratch.buf4[0] = 0; scratch.buf4[1] = 0; scratch.buf4[2] = 0; scratch.buf4[3] = 0;
                int rawCount = Object_ComputeValue_00e049c0(Object_ProcessAndReturnValue_00e03100(nb), Object_ProcessAndReturnValue_00e03100(pItem));
                if (rawCount <= 0) break;
                int iRemaining = rawCount;
                do {
                    apOutputStream->WriteSwapped(scratch.buf4, (int)this->f0c, 2);
                    iRemaining--;
                } while (iRemaining != 0);
                break;
            }
            case 30: {
                if (nb->f08 == 0) break;
                if (pItem->f08 == 0) break;
                int denominator = Object_ProcessAndReturnValue_00e03100(nb);
                int u = Object_ProcessAndReturnValue_00e03100(pItem);
                int iCount = Object_ComputeValue_00e049c0(*(volatile int*)&denominator, u);
                state1.flagh1 = nb->FUN_00d86930();
                state0.flagh2 = pItem->FUN_00d86930();
                int v = nb->FUN_00d86980();
                state1.flagq = v / denominator;
                int cur = iSourceOffset;
                if (iCount <= 0) break;
                int remaining = iCount;
                do {
                    int r86 = nb->ReadSignedValueBySize(cur);
                    
                    work.values.data = 0; work.values.size = 0; work.values.capacity = 0x80000000;
                    work.acc = 0;
                    ((HObj*)state1.flagh1)->CollectMatchingEntries(r86, &work.values, &work.acc);
                    int iOrValue = 0;
                    int iValueIndex = 0;
                    while (iValueIndex < work.values.size) {
                        
                        int* __restrict outputValue = &state0.out40;
                        int iLookupResult = ((HObj*)state0.flagh2)->hkClassEnum_getValueOfName(work.values.data[iValueIndex], outputValue);
                        if (iLookupResult == 0) iOrValue |= *outputValue;
                        else work.acc |= *outputValue;
                        iValueIndex++;
                    }
                    if (work.acc != 0) {
                        int iAccumulated = 0;
                        ((HObj*)state0.flagh2)->CollectMatchingEntries(work.acc, &work.values, &iAccumulated);
                        iOrValue |= iAccumulated;
                    }
                    switch (state1.flagq) {
                    case 1: apOutputStream->FUN_00d605b0(iOrValue); break;
                    case 2: apOutputStream->FUN_00d60900(iOrValue); break;
                    case 4: apOutputStream->WriteInt(iOrValue); break;
                    }
                    cur += state1.flagq;
                    {
                        HeapAlloc& heap = *reinterpret_cast<HeapAlloc*>(&hkMemoryRouter_getInstance().heap());
                        work.values.size = 0;
                        if ((work.values.capacity & 0x80000000) == 0)
                            heap.ReleaseBlock(work.values.data, (work.values.capacity & 0x3fffffff) * 4);
                    }
                    work.values.data = 0;
                    work.values.capacity = 0x80000000;
                    remaining--;
                } while (remaining != 0);
                break;
            }
            case 22: default: {
                
                        scratch.bad.FUN_00cb1600(storage, 0x200);
                scratch.bad.ProcessAndReturnValue_00cc01c0((const char*)&DAT_010ea448);
                int iResult = DAT_01268360->v3(3, 0x641e3e03, (char*)storage, (const char*)&DAT_010ea3c8, 0x225);
                if (iResult) __debugbreak();
                scratch.bad.FUN_00cc00e0();
                break;
            }
            }
            } else {
                hkClass_ProcessEntries_00e03240(apDescriptorList, pItem, state0.index, (int)state1.ebp);
            }
        }
    }
    {
        EbpObj* e2 = apOutputStream->hkOArchive_getStreamWriter();
        e2->v1c(apDescriptorList->FUN_00d470d0() + state0.base, 0);
    }
    return state0.base;
}
}  // namespace fnv_00e036b0
