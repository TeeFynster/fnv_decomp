#include "../../../../../include/hkArray.h"
// src/havok/common/serialize/copier/hkobjectcopier_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/serialize/copier/hkobjectcopier.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


#include "fnv_asm_helpers.h"
#include "../../../../../include/Pair.h"
int __stdcall hkObjectCopier_areMembersCompatible(const void* a, const void* b);
int __cdecl Object_ComputeValue_00e049c0(int a, int b);
extern int DAT_0102e388;
struct Object {
    int* vtable;
    void SetVirtualTable_00e03160();
};
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
struct E04A00Registry {
    int unk00;
    int unk04;
    int unk08;
    E04A00EntryArray m_entries;

    void AddEntry(void* a, void* b, void* c, void* d);
};
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
static int Object_ProcessAndReturnValue_00e03100(Obj* apObj);
int keep_alive(Obj* p);
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
struct Writer {
    void write(const void* data, int elemSize, int count);
};
extern "C" unsigned int* __cdecl FNV_e03300_arena();
static void WriteUIntArray(const unsigned int* data, int count, Writer* pWriter, int elemSize);
void e03300_driver(Writer* w, int elemSize, const unsigned int* data, int count);
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
// src: GUESS 0x00e03360 (confidence: low)
__declspec(noinline) static void Object_UpdateFields_00e03360(VObj* p, int n)
{
    int k = FUN_00e03360_ext1(n);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext2(p);
    FUN_00e03360_ext1(k);
    FUN_00e03360_ext1(k);
}
static int AppendListEntry(Ctx* ctx, List* list, int a, int b);
int keep_alive2(Ctx* ctx, List* list, int a, int b);
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
{ // local form of hkArray: 0x00e03460 needs the original inline/out-of-line helper split; shared replacement changes bytes.
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
static void __cdecl Object_UpdateFields_00e03360(Reader* obj, int n);
void keep_alive_b11425(Reader* obj, int a, int b);
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
static void Hkobjectcopier_WriteSwappedDataByType(unsigned int a, unsigned int b, unsigned int type, Target* obj, void* p);
void target_driver(unsigned int type, unsigned int count, unsigned int size, void* data, Target* target);

extern "C" void _ReadWriteBarrier();
struct S00e03ea0_Schema;

struct S00e03ea0_Member {
    void* m_name;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_subType;
    unsigned short unk0e;
    unsigned short m_flags;
    unsigned short m_offset;

    int getOffset() const { return m_offset; }
    int FUN_00d86980();
    S00e03ea0_Schema* getClass();
    int GetTagValue();
};

struct S00e03ea0_Schema {
    const char* FUN_00d46d40();
    int FUN_00d46f00();
    S00e03ea0_Member* getMember(int i);
    S00e03ea0_Member* FUN_00d46fe0(void* name);
    int FUN_00d470d0();
};

struct S00e03ea0_Writer {
    VObj* hkOArchive_getStreamWriter();
    void hkOArchive_writeRaw(void* p, int size);
    void WriteSwapped(const void* p, int size, int n);
};

struct S00e03ea0_Scr4 {
    int a;
    int b;
    int c;
    int d;
};


struct S00e03ea0_Pair {
    void* m_object;
    void* m_class;
};

struct RootPair {
    int offset;
    const char* name;
    RootPair(int where, const char* what) : offset(where), name(what) {}
};
struct S00e03ea0_PairArrayLocalForm { // local form of hkArray: 0x00e03ea0 needs the original inline/out-of-line helper split; shared replacement changes bytes.
    RootPair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(E04A00Allocator& alloc, const RootPair& e)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(RootPair));
        RootPair* slot = m_data + m_iElementCount;
        slot->offset = e.offset;
        slot->name = e.name;
        m_iElementCount++;
    }

    void pushBack(const RootPair& e) { _pushBack(hkMemoryRouter_getInstance().heap(), e); }
};

struct S00e03ea0_Out {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00e03ea0_PairArrayLocalForm m_pairs;

    void AppendPair(int at, int data);
    void AddEntry(int at, void* obj, void* cls, int n);
};

struct S00e03ea0_Array {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct S00e03ea0_VArray {
    S00e03ea0_Schema* m_class;
    char* m_data;
    int m_iElementCount;
};

struct S00e03ea0_Ostream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    void ProcessAndReturnValue_00cc01c0(const char* s);
    void FUN_00cc00e0();
};

struct S00e03ea0_Error {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int level, unsigned int id, const char* text, const char* file, int line);
};

struct S00e03ea0_Locals {
    S00e03ea0_Ostream osDefault;
    S00e03ea0_Ostream os13;
    int s21[2];
    int s14[2];
    int s1d[2];
    S00e03ea0_Scr4 s1c;
    char buf[512];
};
extern int DAT_0126cae8;
extern const char DAT_010ea4b0[];
extern const char DAT_010ea448[];
extern const char DAT_010ea3c8[];

// src: GUESS 0x00e03100 (confidence: low)
__declspec(noinline) static int Object_ProcessAndReturnValue_00e03100(Obj* p)
{
    int n = p->m();
    return n ? p->m() : 1;
}

__declspec(noinline) static void WriteUIntArray(const unsigned int* data, int count, Writer* w, int elemSize)
{
    if (elemSize == 4) { w->write(data, elemSize, count); return; }
    {
        unsigned int* arena = FNV_e03300_arena();
        unsigned int mark = *arena;
        *arena = mark + ((count * 8 + 127) & ~127u);
        Pair* converted = (Pair*)mark;
        for (int i = 0; i < count; ++i) {
            converted[i].a = data[i];
            converted[i].b = 0;
        }
        w->write(converted, elemSize, count);
        *FNV_e03300_arena() = mark;
    }
}

__declspec(noinline) static int AppendListEntry(Ctx* ctx, List* list, int a, int b)
{
    Object_UpdateFields_00e03360(ctx->hkOArchive_getStreamWriter(), 2);
    VObj* target = ctx->hkOArchive_getStreamWriter()->v20();
    E04A00Allocator& alloc = hkMemoryRouter_getInstance().heap();
    if (list->m_uiItemCount == (int)(list->m_iCapacityState & 0x3fffffff))
        ResizeAudioStream(&alloc, list, sizeof(ListEntry));
    ListEntry* entry = list->m_data + list->m_uiItemCount;
    entry->m_key = b;
    entry->m_uiFilterValue = target;
    ++list->m_uiItemCount;
    ctx->hkOArchive_writeRaw(a, hkString_strLen(a) + 1);
    return 0;
}

extern const char str_010ea3e4[];
// src: GUESS 0x00e03170 (confidence: medium)
__declspec(noinline) static void Hkobjectcopier_WriteSwappedDataByType(Target* w, unsigned int count, unsigned int stride, unsigned int kind, void* data)
{
    switch (kind) {
    case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        count *= stride >> 2;
        stride = 4;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 32:
        w->WriteSwapped(data, stride, count);
        break;
    default:
        char text[512];
        S00e03ea0_Ostream diagnostic;
        diagnostic.FUN_00cb1600(text, sizeof(text));
        diagnostic.ProcessAndReturnValue_00cc01c0(str_010ea3e4);
        if (DAT_01268360->v3(3, 0x747e1e03, text, DAT_010ea3c8, 0xfb))
            __debugbreak();
        diagnostic.FUN_00cc00e0();
    }
}

struct S00e03ea0_Ser {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual int v10(S00e03ea0_Member* type, S00e03ea0_Member* member);
    int unk04;
    unsigned char m_srcPtrSize;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char m_dstPtrSize;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    unsigned char m_flags;

    void hkObjectCopier_saveExtras(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                      S00e03ea0_Schema* dstClass, int dst, S00e03ea0_Out* out, int depth);
    void hkObjectCopier_saveBody(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                      S00e03ea0_Schema* dstClass);
};

static __forceinline void fixedPointerLoop(S00e03ea0_Ser*& self, char* s, S00e03ea0_Member* member, S00e03ea0_Writer* writer, int dst, S00e03ea0_Out* out, int count, int stride, int& j) {
            for (; j < count; j++) {
                void* p = *(void**)s;
                if (p) {
                    int off = self->m_dstPtrSize * j + member->getOffset();
                    if (member->m_subType == 2)
                        AppendListEntry((Ctx*)writer, (List*)out, (int)p, (int)(dst + off));
                    else
                        out->AddEntry(dst + off, p, member->getClass(), 0);
                }
                s += stride;
            }
}
// @fnv 0x00e03ea0
// src: XBOX_PDB 0x00e03ea0
void S00e03ea0_Ser::hkObjectCopier_saveExtras(char* src, S00e03ea0_Schema* srcClass, S00e03ea0_Writer* writer,
                                 S00e03ea0_Schema* dstClass, int dst, S00e03ea0_Out* out, int depth)
{
    S00e03ea0_Ser* self = this;
    S00e03ea0_Locals sc;
    char* buf = sc.buf;

    if (depth == 0) {
        RootPair p(dst, dstClass->FUN_00d46d40());
        out->m_pairs.pushBack(p);
    }
    depth++;

    for (int i = 0; i < dstClass->FUN_00d46f00(); i++) {
        S00e03ea0_Member* member = dstClass->getMember(i);
        void* memberName = member->m_name;
        S00e03ea0_Member* type = srcClass->FUN_00d46fe0(memberName);
        if (!type)
            continue;
        char* s = src + type->getOffset();
        if (!self->v10(type, member))
            continue;
        if ((self->m_flags & 2) && (member->m_flags & 0x400))
            continue;

        switch (member->m_type) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
        case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        case 21: case 24: case 30: case 31: case 32:
            break;
        case 0x1d: {
            void* p = *(void**)s;
            if (p)
                AppendListEntry((Ctx*)writer, (List*)out, (int)p, (int)(dst + member->getOffset()));
            break;
        }
        case 0x21: {
            unsigned int p = *(unsigned int*)s;
            if (p & ~1u)
                AppendListEntry((Ctx*)writer, (List*)out, (int)(p & ~1u), (int)(dst + member->getOffset()));
            break;
        }
        case 0x14: {
            int count = Object_ComputeValue_00e049c0(Object_ProcessAndReturnValue_00e03100((Obj*)type), Object_ProcessAndReturnValue_00e03100((Obj*)member));
            int stride = type->FUN_00d86980() / Object_ProcessAndReturnValue_00e03100((Obj*)type);
            int j=0;
            fixedPointerLoop(self, s, member, writer, dst, out, count, stride, j);
            break;
        }
        case 0x16: case 0x17: case 0x1a: {
            S00e03ea0_Array* arr = (S00e03ea0_Array*)s;
            if (arr->m_iElementCount == 0)
                break;
            unsigned char sub = member->m_subType;
            if (sub == 0)
                break;
            if (sub == 0x14) {
                out->AppendPair(dst + member->getOffset(), (int)writer->hkOArchive_getStreamWriter()->v20());
                Pair& scratch = reinterpret_cast<Pair&>(sc.s14);
                scratch.a = 0;
                scratch.b = 0;
                int stride = type->GetTagValue();
                int j=0; if (j < arr->m_iElementCount) { int off=0; do {
                    void* condition = *(void**)((char*)arr->m_data + off);
                    void* volatile p = condition;
                    if (condition) {
                        VObj* r = writer->hkOArchive_getStreamWriter();
                        out->AddEntry((int)r->v20(), p, type->getClass(), 0);
                    }
                    writer->hkOArchive_writeRaw(&scratch, self->m_dstPtrSize);
                    off += stride;
                } while (++j < arr->m_iElementCount); }
            } else if (sub == 0x1d) {
                out->AppendPair(dst + member->getOffset(), (int)writer->hkOArchive_getStreamWriter()->v20());
                Pair& scratch = reinterpret_cast<Pair&>(sc.s1d);
                scratch.a = 0;
                scratch.b = 0;
                int d = (int)writer->hkOArchive_getStreamWriter()->v20();
                if (arr->m_iElementCount > 0) {
                    S00e03ea0_Ser* loopSelf = self;
                    int j = 0; do { writer->hkOArchive_writeRaw(&scratch, loopSelf->m_dstPtrSize); } while (++j < arr->m_iElementCount);
                }
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    void** e = (void**)arr->m_data + j;
                    if (*e) { _ReadWriteBarrier(); AppendListEntry((Ctx*)writer, (List*)out, (int)*e, d + self->m_dstPtrSize * j); }
                }
            } else if (sub == 0x21) {
                out->AppendPair(dst + member->getOffset(), (int)writer->hkOArchive_getStreamWriter()->v20());
                Pair& scratch = reinterpret_cast<Pair&>(sc.s21);
                scratch.a = 0;
                scratch.b = 0;
                int d = (int)writer->hkOArchive_getStreamWriter()->v20();
                if (arr->m_iElementCount > 0) {
                    S00e03ea0_Ser* loopSelf = self;
                    int j = 0; do { writer->hkOArchive_writeRaw(&scratch, loopSelf->m_dstPtrSize); } while (++j < arr->m_iElementCount);
                }
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    unsigned int e = ((unsigned int*)arr->m_data)[j];
                    if (e & ~1u)
                        AppendListEntry((Ctx*)writer, (List*)out, (int)(e & ~1u), (int)(d + self->m_dstPtrSize * j));
                }
            } else if (sub == 0x19) {
                int d = (int)writer->hkOArchive_getStreamWriter()->v20();
                out->AppendPair(dst + member->getOffset(), d);
                S00e03ea0_Schema* sc = type->getClass();
                S00e03ea0_Schema* dc = member->getClass();
                if (sc && dc) {
                    char* data = (char*)arr->m_data;
                    for (int j = 0; j < arr->m_iElementCount; j++)
                        self->hkObjectCopier_saveBody(data + sc->FUN_00d470d0() * j, sc, writer, dc);
                    for (int j = 0; j < arr->m_iElementCount; j++)
                        self->hkObjectCopier_saveExtras(data + sc->FUN_00d470d0() * j, sc, writer, dc,
                                     d + dc->FUN_00d470d0() * j, out, depth);
                }
            } else if (sub == 0x1c) {
                int d = (int)writer->hkOArchive_getStreamWriter()->v20();
                out->AppendPair(dst + member->getOffset(), d);
                S00e03ea0_Scr4& scratch = sc.s1c;
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    scratch.a = 0;
                    scratch.b = 0;
                    scratch.c = 0;
                    scratch.d = 0;
                    writer->WriteSwapped(&scratch, self->m_dstPtrSize, 2);
                }
                for (int j = 0; j < arr->m_iElementCount; j++) {
                    int off = self->m_dstPtrSize * j * 2;
                    if (((S00e03ea0_Pair*)arr->m_data)[j].m_object)
                        out->AddEntry(d + off, ((S00e03ea0_Pair*)arr->m_data)[j].m_object, ((S00e03ea0_Pair*)arr->m_data)[j].m_class, 0);
                    void* c = ((S00e03ea0_Pair*)arr->m_data)[j].m_class;
                    if (c)
                        out->AddEntry(d + off + self->m_dstPtrSize, c, &DAT_0126cae8, 0);
                }
            } else {
                VObj* stream = writer->hkOArchive_getStreamWriter();
                int off = member->getOffset();
                out->AppendPair(dst + off, (int)stream->v20());
                if (member->m_subType == 0x1e) {
                    const unsigned int* rawData = (const unsigned int*)arr->m_data;
                    int rawCount = arr->m_iElementCount;
                    
                    
                    WriteUIntArray(rawData, rawCount, (Writer*)*(S00e03ea0_Writer* volatile const*)&writer, self->m_dstPtrSize);
                }
                else {
                    Hkobjectcopier_WriteSwappedDataByType((Target*)writer, arr->m_iElementCount, member->GetTagValue(), member->m_subType, arr->m_data);
                }
            }
            break;
        }
        case 0x1b: {
            S00e03ea0_VArray* arr = (S00e03ea0_VArray*)s;
            S00e03ea0_Schema* c = arr->m_class;
            if (!c)
                break;
            out->AddEntry(dst + member->getOffset(), c, &DAT_0126cae8, 1);
            int d = (int)writer->hkOArchive_getStreamWriter()->v20();
            out->AppendPair(dst + self->m_dstPtrSize + member->getOffset(), d);
            char* data = arr->m_data;
            for (int j = 0; j < arr->m_iElementCount; j++)
                self->hkObjectCopier_saveBody(data + c->FUN_00d470d0() * j, c, writer, c);
            for (int j = 0; j < arr->m_iElementCount; j++)
                self->hkObjectCopier_saveExtras(data + c->FUN_00d470d0() * j, c, writer, c,
                             d + c->FUN_00d470d0() * j, out, depth);
            break;
        }
        case 0x19: {
            S00e03ea0_Schema* sc = type->getClass();
            S00e03ea0_Schema* dc = member->getClass();
            if (!sc || !dc)
                break;
            int d = dst + member->getOffset();
            int n = Object_ProcessAndReturnValue_00e03100((Obj*)type);
            int count = Object_ComputeValue_00e049c0(n, Object_ProcessAndReturnValue_00e03100((Obj*)member));
            for (int j = 0; j < count; j++) {
                char* ss = s + sc->FUN_00d470d0() * j;
                self->hkObjectCopier_saveExtras(ss, sc, writer, dc, d + dc->FUN_00d470d0() * j, out, depth);
            }
            break;
        }
        case 0x1c: {
            int n = Object_ProcessAndReturnValue_00e03100((Obj*)type);
            int count = Object_ComputeValue_00e049c0(n, Object_ProcessAndReturnValue_00e03100((Obj*)member));
            for (int j = 0; j < count; j++) {
                unsigned char ptrSize = self->m_srcPtrSize;
                void* o = *(void**)(s + j * ptrSize * 2);
                void* c = *(void**)(s + (j * 2 + 1) * ptrSize);
                if (o)
                    out->AddEntry(dst + member->getOffset() + self->m_dstPtrSize * j * 2, o, c, 0);
                if (c)
                    out->AddEntry(dst + member->getOffset() + self->m_dstPtrSize * (j * 2 + 1), c, &DAT_0126cae8, 0);
            }
            break;
        }
        case 0x13: {
            S00e03ea0_Ostream& os = sc.os13;
            os.FUN_00cb1600(buf, 0x200);
            os.ProcessAndReturnValue_00cc01c0(DAT_010ea4b0);
            if (DAT_01268360->v3(3, 0x641e3e05, buf, DAT_010ea3c8, 0x39e))
                __debugbreak();
            os.FUN_00cc00e0();
            break;
        }
        default: {
            S00e03ea0_Ostream& os = sc.osDefault;
            os.FUN_00cb1600(buf, 0x200);
            os.ProcessAndReturnValue_00cc01c0(DAT_010ea448);
            if (DAT_01268360->v3(3, 0x641e3e05, buf, DAT_010ea3c8, 0x3a3))
                __debugbreak();
            os.FUN_00cc00e0();
            break;
        }
        }
        Object_UpdateFields_00e03360(writer->hkOArchive_getStreamWriter(), 0x10);
    }
}

struct ZeroClass {
    int FUN_00d470d0() const;
};
struct ZeroMember {
    const char* m_name;
    ZeroClass* m_class;
    void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    void* m_pCustomAttributes;
    int type() const { return m_type; }
    int FUN_00d86980() const;
    const ZeroClass& FUN_00d86910() const;
};
struct ZeroArchive {
    int hkOArchive_writeRaw(const void* data, int size);
    void hkOArchive_write32u(unsigned int value);
};
static __declspec(noinline) int Object_ProcessAndReturnValue_00e03100(Obj* p);
extern const char str_010ea424[];
struct ZeroCopier {
    void* m_ppVirtualMethodTable;
    short m_usAllocationSize;
    short m_iObjectReferenceCount;
    unsigned char m_inputPointerSize;
    unsigned char m_inputLittleEndian;
    unsigned char m_inputTailPadding;
    unsigned char m_inputEmptyBase;
    unsigned char m_outputPointerSize;
    unsigned char m_outputLittleEndian;
    unsigned char m_outputTailPadding;
    unsigned char m_outputEmptyBase;
    unsigned int m_flags;
    unsigned char m_bStreamResult;
    void hkObjectCopier_writeZero(ZeroArchive& archive, const ZeroMember& member);
};
// @fnv 0x00e03460
// src: XBOX_PDB 0x00e03460
void ZeroCopier::hkObjectCopier_writeZero(ZeroArchive& archive, const ZeroMember& member)
{
    int bytes = 0;
    switch (member.type()) {
    case 1: case 2: case 3: case 4: case 5: case 6:
    case 7: case 8: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17: case 18:
    case 24: case 31: case 32:
        bytes = member.FUN_00d86980();
        break;
    case 20: case 21: case 30:
        bytes = m_outputPointerSize * Object_ProcessAndReturnValue_00e03100((Obj*)&member);
        break;
    case 22: case 23: case 26: case 27:
        if (member.type() == 27)
            bytes += m_outputPointerSize;
        bytes += m_outputPointerSize;
        bytes += 4;
        if (member.type() == 22) {
            char header[12] = {0};
            archive.hkOArchive_writeRaw(header, bytes);
            archive.hkOArchive_write32u(0x80000000u);
            return;
        }
        break;
    case 25: {
        const ZeroClass& pClassInfo = member.FUN_00d86910();
        bytes = pClassInfo.FUN_00d470d0() * Object_ProcessAndReturnValue_00e03100((Obj*)&member);
        break;
    }
    case 28:
        bytes = 2 * m_outputPointerSize * Object_ProcessAndReturnValue_00e03100((Obj*)&member);
        break;
    default: {
        unsigned int report[128];
        DiagnosticWriter stream;
        stream.FUN_00cb1600(report, sizeof(report));
        stream.ProcessAndReturnValue_00cc01c0(str_010ea424);
        if (DAT_01268360->v3(3, 0x5ef4e5a4u, (char*)report, str_010ea3c8, 168))
            __debugbreak();
        stream.FUN_00cc00e0();
        break;
    }
    }
    LocalCharArray zero(bytes);
    zero.SetSizeAndGrow(bytes);
    archive.hkOArchive_writeRaw(zero.m_data, bytes);
    zero.destroyLocal();
}
