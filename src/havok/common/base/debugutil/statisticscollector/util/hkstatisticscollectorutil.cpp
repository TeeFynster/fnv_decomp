
// src/havok/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkClass.h"
#include "../../../../../../../include/hkClassMember.h"
#include "../../../../../../../include/hkStringPtr.h"

// These getters are absent from the shared headers. Their ECX argument uses
// the same register convention as the original zero-argument member calls.
int __fastcall GetObjectSize(const hkClass* klass);
const hkClass* __fastcall GetParent(const hkClass* klass);
int __fastcall GetCArraySize(const hkClassMember* member);

inline hkClassMember::Type hkClassMember::getType() const
{
    return static_cast<Type>(m_type);
}

extern "C" int __cdecl hkString_strLen(const char* s);

class Hasher
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
    virtual int Hash(const char* s, int len);
};

struct Audio
{
    char pad[0x10];
    Hasher* hasher;
    Hasher& GetHasher()
    {
        return *hasher;
    }
};

extern "C" Audio* __cdecl hkMemoryRouter_getInstance();

class Handler
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Emit(int kind, int a, const char* s, int len, int hash);
};

// If s is non-null, computes its length plus one, hashes it via the audio hasher, and emits it through h with kind 1 and *a.
// @fnv 0x00cf5fe0
extern "C" void __cdecl EmitStringWithHash(int* pValue, const char* pString, Handler* pHandler)
{
    if (pString)
    {
        int len = hkString_strLen(pString) + 1;
        int hash = hkMemoryRouter_getInstance()->GetHasher().Hash(pString, len);
        pHandler->Emit(1, *pValue, pString, len, hash);
    }
}

struct Destination
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void WriteDirect(void*, unsigned int, int);
    virtual void WriteFormatted(const hkClass*, void*, unsigned int, int);
};
// @fnv 0x00cf6030
void __cdecl WriteToDestination(void* data, unsigned int size, const hkClass* format, Destination* destination)
{
    unsigned int originalSize = size;
    if (originalSize)
    {
        if (format->GetLastNodeFlag())
            destination->WriteDirect(data, originalSize, 0);
        else
            destination->WriteFormatted(format, data, originalSize, 0);
    }
}

namespace fnv_00cf6080 {
struct S_00cf6080_Allocator
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void* vfn_2C(void* p, int numBytes);
};
struct S_00cf6080_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00cf6080_Allocator* unk10;
    S_00cf6080_Allocator* heap()
    {
        return unk10;
    }
};
S_00cf6080_Router* hkMemoryRouter_getInstance();

struct S_00cf6080_Listener
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14(int type, int a, void* p, int numBytes, void* result);
};

// @fnv 0x00cf6080
// src: HAVOK_LIB 0x00cf6080
void hkStatisticsCollectorUtil__addArrayData(int a, void* p, int aiOldCount, int newCount, int elemSize, S_00cf6080_Listener* listener)
{
    void* result = hkMemoryRouter_getInstance()->heap()->vfn_2C(p, newCount * elemSize);
    listener->vfn_14(3, a, p, aiOldCount * elemSize, result);
}
}  // namespace fnv_00cf6080

struct TypeInfo
{
    unsigned char m_ucKind;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    short m_sValue;
};

TypeInfo* __cdecl hkClassMember_getClassMemberTypeProperties(int aiType);

// Reads the type from apThing, looks up its TypeInfo, and returns m_sValue if positive, else the result of FUN_00d470d0 for kind 0x19, otherwise -1.
// @fnv 0x00cf61c0
__declspec(noinline) int __cdecl GetThingValue(const hkClassMember* apThing)
{
    unsigned char ucType = apThing->m_eSubtype;
    if (ucType == 0)
        return -1;

    TypeInfo* pInfo = hkClassMember_getClassMemberTypeProperties(ucType);
    short sValue = pInfo->m_sValue;
    if (sValue > 0)
        return sValue;

    if (pInfo->m_ucKind == 0x19)
        return GetObjectSize(apThing->GetClass());

    return -1;
}

__declspec(nothrow) hkBool __cdecl GetFlagByState(const hkClassMember* s);

// Calls FUN_00d46f70 for a count, then GetFlagByState on each shape from FUN_00d46f80, returning false on the first failure and true otherwise.
// @fnv 0x00cf6330
// src: HAVOK_LIB 0x00cf6330
hkBool __cdecl hkStatisticsCollectorUtil__isClassSimple(const hkClass* apContainer)
{
    int n = apContainer->GetNumDeclaredMembers();
    for (int i = 0; i < n; i++)
    {
        if (!GetFlagByState(&apContainer->GetDeclaredMember(i)))
            return false;
    }
    return true;
}

// FUN_00cf60d0 - 69 bytes at 0x00cf60d0
//
// The function forwards to one of two virtual slots of its last argument,
// choosing between them on the flag byte that the walker writes through the
// pointer it is handed.  The walker returns the very pointer it was given, so
// the test reads the byte through the returned pointer.


struct FNV_C60d0_Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* a0, void* a1, int flag);
    virtual void v4(const hkClass* a0, void* a1, void* a2, int flag);
};

// @fnv 0x00cf60d0
// src: HAVOK_LIB 0x00cf60d0
extern "C" void __cdecl hkStatisticsCollectorUtil__addObjectContents(void* pA0, void* pA1, const hkClass* pWalker, FNV_C60d0_Sink* pSink)
{
    void* p = pA1;
    if (p)
    {
        if (pWalker->GetLastNodeFlag())
        {
            pSink->v3(pA0, p, 1);
        }
        else
        {
            pSink->v4(pWalker, pA0, p, 1);
        }
    }
}

void* __cdecl hkStatisticsCollectorUtil__addObjectContents(void* context, const void* a, const void* b, const void* c);

// @fnv 0x00cf6120
void* __cdecl CallWithNullContext(const void* a, const void* b, const void* c)
{
    return hkStatisticsCollectorUtil__addObjectContents(0, a, b, c);
}

struct SpawnedObject
{
    int CalleeA(int aiArg);
};

void __cdecl CalleeB_00cf60d0(int aiA, int aiB, int aiC, int aiD);

// Calls CalleeA on the object at aiSecond with aiFirst; if it returns nonzero, passes 0, aiFirst, the result and aiSecond to CalleeB_00cf60d0.
// @fnv 0x00cf6140
void __cdecl CallObjectMethodAndDispatch(int aiFirst, int aiSecond)
{
    SpawnedObject* pObj = (SpawnedObject*)aiSecond;
    int result = pObj->CalleeA(aiFirst);
    if (result != 0)
    {
        CalleeB_00cf60d0(0, aiFirst, result, aiSecond);
    }
}

extern hkClass DAT_01268748;

// @fnv 0x00cf6170
// src: HAVOK_LIB 0x00cf6170
unsigned char* hkStatisticsCollectorUtil_hasContents(unsigned char* result, const hkClass* object)
{
    if (object != 0)
    {
        do
        {
            if (object == &DAT_01268748)
                break;

            if (object->GetNumDeclaredMembers() > 0)
            {
                *result = 1;
                return result;
            }

            object = GetParent(object);
        } while (object != 0);
    }

    *result = 0;
    return result;
}

unsigned char* hkStatisticsCollectorUtil__isClassSimple(const hkClass** where, const hkClass* node);

// @fnv 0x00cf6380
// src: HAVOK_LIB 0x00cf6380
unsigned char* hkStatisticsCollectorUtil_isClassSimple(unsigned char* pResult, const hkClass* pStartNode)
{
    const hkClass* cur = pStartNode;
    do
    {
        unsigned char* flag = hkStatisticsCollectorUtil__isClassSimple(&pStartNode, cur);
        if (*flag == 0)
        {
            *pResult = 0;
            return pResult;
        }
        cur = GetParent(cur);
    } while (cur != 0);
    *pResult = 1;
    return pResult;
}

hkBool __cdecl hkStatisticsCollectorUtil_isClassSimple(const hkClass& pClassInfo);

struct CF63C0Writer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void writeObjectWithVtable(void* context, const void* object, bool recurse);
    virtual void WriteObjectWithClass(const hkClass& pClassInfo, void* context, const void* object, bool recurse);
};

// @fnv 0x00cf63c0
void __cdecl WriteObjectArray(void* context, const hkClass& pClassInfo, const void* data, int count,
                              CF63C0Writer& writer)
{
    if (count)
    {
        if (!hkStatisticsCollectorUtil_isClassSimple(pClassInfo))
        {
            const char* cur = static_cast<const char*>(data);
            int size = GetObjectSize(&pClassInfo);
            if (pClassInfo.GetLastNodeFlag())
            {
                for (int i = 0; i < count; i++)
                {
                    writer.writeObjectWithVtable(context, cur, true);
                    cur += size;
                }
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    writer.WriteObjectWithClass(pClassInfo, context, cur, true);
                    cur += size;
                }
            }
        }
    }
}

void __cdecl WriteReflectedMembers(void* a, const hkClass* b, void* c);

// If a1 is non-null, walks the linked list starting at a2, calling WriteReflectedMembers(a1, p, a3) for each node.
// @fnv 0x00cf6920
// src: HAVOK_LIB 0x00cf6920
void __cdecl hkStatisticsCollectorUtil_addClassContentsAll(void* a1, const hkClass* apNode, void* apArg)
{
    if (a1 == 0)
        return;
    const hkClass* p = apNode;
    do
    {
        WriteReflectedMembers(a1, p, apArg);
        p = GetParent(p);
    } while (p != 0);
}

// Candidate for GetFlagByState  (0x00cf62b0, 80 bytes)
//
// The original:
//   mov ecx,[esp+8]            ; the object
//   mov ax,word [ecx+0x10]     ; a 16-bit flag field
//   shr ax,9 / test al,1 / jne  -> set *out = 1
//   movzx eax,byte [ecx+0xc]   ; a byte "type" field
//   dec eax / cmp eax,0x20 / ja -> set *out = 0
//   movzx edx,byte [eax+map] / jmp [edx*4+jt]   (33-case two level switch)
//   ... 3 clusters: *out=1, *out=0, and one that calls a helper.
//
// The helper at 0x00d86910 is a __thiscall member that returns the dword at
// this+4; it must be a real call (not inlined) so that `this` stays in ECX.

extern "C" void __cdecl FUN_cf62b0_next(unsigned char* out, const hkClass* node);

// @fnv 0x00cf62b0
unsigned char* GetFlagByState(unsigned char* pucOut, const hkClassMember* pObj)
{
    bool bFlagSet = ((pObj->m_flags >> 9) & 1) != 0;
    if (bFlagSet)
    {
        *pucOut = 1;
        return pucOut;
    }

    unsigned int uiStateIndex = (unsigned int)pObj->m_type - 1;
    switch (uiStateIndex)
    {
    case 0:
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
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 20:
    case 23:
    case 29:
    case 30:
    case 31:
        *pucOut = 1;
        return pucOut;

    case 18:
    case 19:
    case 21:
    case 22:
    case 25:
    case 26:
    case 27:
    case 28:
    case 32:
        *pucOut = 0;
        return pucOut;

    case 24:
        FUN_cf62b0_next(pucOut, pObj->GetClass());
        return pucOut;

    default:
        *pucOut = 0;
        return pucOut;
    }
}

struct Writer64;

struct Pair64
{
    void* data;
    int count;
};
struct Homogeneous64
{
    const hkClass* pClassInfo;
    void* data;
    int count;
};
struct Variant64
{
    void* object;
    const hkClass* pClassInfo;
};
struct Array64
{
    void* data;
    int count;
    int capacity;
};
struct Access64
{
    void* data;
    const hkClassMember* member;
    Access64(void*, const hkClassMember*);
    char** hkClassMemberAccessor_asCstring(int);
    const char* hkClassMemberAccessor_asStringPtr(int);
    Pair64* hkClassMemberAccessor_asSimpleArray(int);
    Homogeneous64* hkClassMemberAccessor_asHomogeneousArray(int);
};
struct Writer64
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Begin(const char*);
    virtual void End();
    int unk04, unk08, unk0c;
    unsigned char includeStorage;
    void EmitString(const char*, const char*);
};
int __cdecl MemberSize64(const hkClassMember*);
void __cdecl EmitStringWithHash(const hkClassMember*, const char*, Writer64*);
void __cdecl hkStatisticsCollectorUtil__addArrayData(const char*, void*, int, int, int, Writer64*);
void __cdecl hkStatisticsCollectorUtil__addArrayContents(const hkClassMember*, void*, int, Writer64*);
void __cdecl WriteObjectArray(const char*, const hkClass*, void*, int, Writer64*);
void __cdecl WriteToDestination(const char*, void*, const hkClass*, Writer64*);
void __cdecl hkStatisticsCollectorUtil__addObjectContents(const char*, void*, const hkClass*, Writer64*);
int __cdecl GetThingValue(const hkClassMember*);

// @fnv 0x00cf6580
void __cdecl WriteReflectedMembers(void* base, const hkClass* apMeta, Writer64* writer)
{
    if (!base)
        return;
    int count = apMeta->GetNumDeclaredMembers();
    for (int i = 0; i < count; ++i)
    {
        const hkClassMember* m = &apMeta->GetDeclaredMember(i);
        if (((unsigned char)(m->m_flags >> 9) & 1) != 0)
            continue;
        switch (m->m_type)
        {
        case 29: {
            Access64 value(base, m);
            int n = GetCArraySize(m);
            if (n <= 1)
                EmitStringWithHash(m, *value.hkClassMemberAccessor_asCstring(0), writer);
            else
                for (int j = 0; j < n; ++j)
                    EmitStringWithHash(m, *value.hkClassMemberAccessor_asCstring(j), writer);
            break;
        }
        case 33: {
            Access64 value(base, m);
            int n = GetCArraySize(m);
            if (n <= 1)
            {
                const char* name = m->m_name;
                writer->EmitString(name, value.hkClassMemberAccessor_asStringPtr(0));
            }
            else
                for (int j = 0; j < n; ++j)
                {
                    const char* name = m->m_name;
                    writer->EmitString(name, value.hkClassMemberAccessor_asStringPtr(j));
                }
            break;
        }
        case 22: {
            Array64* a = (Array64*)((char*)base + m->m_offset);
            if ((a->capacity & 0x80000000u) && !writer->includeStorage)
                break;
            int length = a->count;
            int capacity = a->capacity & 0x3fffffff;
            int size = GetThingValue(m);
            if (size < 0)
                break;
            bool pointers = m->m_eSubtype == 20;
            const char* name;
            if (pointers)
            {
                writer->Begin(m->m_name);
                name = "array";
            }
            else
                name = m->m_name;
            hkStatisticsCollectorUtil__addArrayData(name, a->data, length, capacity, size, writer);
            hkStatisticsCollectorUtil__addArrayContents(m, a->data, length, writer);
            if (pointers)
                writer->End();
            break;
        }
        case 26: {
            Access64 value(base, m);
            Pair64 a = *value.hkClassMemberAccessor_asSimpleArray(0);
            void* data = a.data;
            int length = a.count;
            int size = GetThingValue(m);
            if (size < 0)
                break;
            writer->Begin(m->m_name);
            hkStatisticsCollectorUtil__addArrayData(m->m_name, data, length, length, size, writer);
            hkStatisticsCollectorUtil__addArrayContents(m, data, length, writer);
            writer->End();
            break;
        }
        case 27: {
            Access64 value(base, m);
            Homogeneous64 a = *value.hkClassMemberAccessor_asHomogeneousArray(0);
            const hkClass* itemClass = a.pClassInfo;
            void* data = a.data;
            int length = a.count;
            if (length > 0 && itemClass && data)
            {
                writer->Begin(m->m_name);
                const char* name = m->m_name;
                hkStatisticsCollectorUtil__addArrayData(name, data, length, length, GetObjectSize(itemClass), writer);
                WriteObjectArray(m->m_name, itemClass, data, length, writer);
                writer->End();
            }
            break;
        }
        case 20:
            if (m->m_eSubtype == 25)
            {
                void* data = *(void**)((char*)base + m->m_offset);
                const char* name = m->m_name;
                WriteToDestination(name, data, m->GetClass(), writer);
            }
            break;
        case 28: {
            Variant64* a = (Variant64*)((char*)base + m->m_offset);
            if (a->object && a->pClassInfo)
                WriteToDestination(m->m_name, a->object, a->pClassInfo, writer);
            break;
        }
        case 25: {
            const char* name = m->m_name;
            void* data = (char*)base + m->m_offset;
            hkStatisticsCollectorUtil__addObjectContents(name, data, m->GetClass(), writer);
            break;
        }
        }
    }
}


struct StringArrayAccessor
{
    void* m_pTargetObject;
    const hkClassMember* m_kMemberDescriptor;

    StringArrayAccessor(const void* object, const hkClassMember* member);
    const char*& GetStringPointerAt(int index);
    hkStringPtr& GetStringPtr(int index);
};

int __cdecl hkString_strCmp(const char* a, const char* b);

// Finds the declared member named "name" in pClassInfo and returns its string value, or "unnamed" when the pointer is null.
// @fnv 0x00cf6210
// src: HAVOK_LIB 0x00cf6210
static __declspec(noinline) const char* _findObjectName(const void* object, const hkClass& pClassInfo)
{
    const int n = pClassInfo.GetNumDeclaredMembers();
    for (int i = 0; i < n; i++)
    {
        const hkClassMember& member = pClassInfo.GetDeclaredMember(i);
        const char* name = member.m_name;
        if (hkString_strCmp(name, "name") != 0)
            continue;
        StringArrayAccessor accessor(object, &member);
        switch (member.getType())
        {
        case 0x1d: {
            const char* s = accessor.GetStringPointerAt(0);
            if (&pClassInfo)
                return s ? s : "unnamed";
            return s ? s : "unnamed";
        }
        case 0x21: {
            const char* s = (const char*)((unsigned int)accessor.GetStringPtr(0).m_pcText & ~1u);
            return s ? s : "unnamed";
        }
        }
    }
    return 0;
}

const void* volatile g_obj;
const hkClass* volatile g_klass;
const char* volatile g_out;
void caller_cf6210()
{
    g_out = _findObjectName(g_obj, *g_klass);
}

extern const char DAT_01094398[];
extern const char DAT_010cc458[];
int __cdecl hkString_strCmp(const char*, const char*);
struct TaggedString64
{
    unsigned int bits;
};
// src: HAVOK_LIB 0x00cf6210
static __declspec(noinline) const char* _findObjectName(const hkClass* pClassInfo, void* object)
{
    if (!pClassInfo)
        return 0;
    int count = pClassInfo->GetNumDeclaredMembers();
    for (int i = 0; i < count; ++i)
    {
        const hkClassMember* m = &pClassInfo->GetDeclaredMember(i);
        if (hkString_strCmp(m->m_name, DAT_01094398) == 0)
        {
            Access64 access(object, m);
            switch (m->m_type)
            {
            case 0x21: {
                TaggedString64* slot = (TaggedString64*)access.hkClassMemberAccessor_asStringPtr(0);
                const char* name = (const char*)(slot->bits & ~1u);
                return name ? name : DAT_010cc458;
            }
            case 0x1d: {
                const char* name = *access.hkClassMemberAccessor_asCstring(0);
                return name ? name : DAT_010cc458;
            }
            }
        }
    }
    return 0;
}

// Processes each element according to member subtype, calling the corresponding writer or helper for recognized subtypes.
// @fnv 0x00cf6460
// src: HAVOK_LIB 0x00cf6460
void __cdecl hkStatisticsCollectorUtil__addArrayContents(const hkClassMember* member, void* elements, int count, Writer64* writer)
{
    if (count <= 0)
        return;
    switch (member->m_eSubtype)
    {
    case 0x14: {
        const hkClass* meta = member->GetClass();
        if (!meta)
            return;
        for (int i = 0; i < count; ++i)
        {
            const char* name = _findObjectName(meta, ((void**)elements)[i]);
            if (!name)
                name = member->m_name;
            WriteToDestination(name, ((void**)elements)[i], meta, writer);
        }
        return;
    }
    case 0x19: {
        const hkClass* meta = member->GetClass();
        if (!meta)
            return;
        WriteObjectArray(member->m_name, meta, elements, count, writer);
        return;
    }
    case 0x1d:
        for (int i = 0; i < count; ++i)
            EmitStringWithHash(member, ((const char**)elements)[i], writer);
        return;
    case 0x21: {
        for (int i = 0; i < count; ++i)
            writer->EmitString(member->m_name, (const char*)((const char**)elements + i));
        return;
    }
    }
}
