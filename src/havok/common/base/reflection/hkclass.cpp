
// src/havok/common/base/reflection/hkclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkClassEnum.h"
#include "../../../../../include/hkClassMember.h"
#include "../../../../../include/hkCustomAttributes.h"
#include "../../../../../include/hkVariant.h"
#include "../../../../../include/hkResult.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStreamWriter.h"
#include "../../../../../include/hkpActionListener.h"
#include "../../../../../include/hkpConstraintListener.h"
#include "../../../../../include/hkpEntityListener.h"
#include "../../../../../include/hkpPhantomListener.h"
#include "../../../../../include/hkpWorldPostSimulationListener.h"

// Free declarations cover methods that the shared headers do not declare yet.
// An unused EDX argument leaves the remaining arguments on the original thiscall stack.
const hkClassEnum* __fastcall GetMemberEnum(const hkClassMember* member);
int __fastcall GetMemberSize(const hkClassMember* member);
int __fastcall ReadMemberSignedValue(const hkClassMember* member, void*, const void* value);
typedef int (__thiscall *MemberValueReader)(const hkClassMember*, const void*);
void __fastcall SerializeEnum(const hkClassEnum* descriptor, void*, void* stream);
typedef void (__thiscall *EnumSerializer)(const hkClassEnum*, void*);
void __fastcall SerializeClass(const hkClass* descriptor, void*, void* stream);
typedef void (__thiscall *ClassSerializer)(const hkClass*, void*);
int __fastcall GetDefaultValue(const hkClass* cls, void*, int index, char** value, const hkClassMember** member);

// @fnv 0x00d46f80
__declspec(noinline) const hkClassMember& hkClass::GetDeclaredMember(int aiIndex) const
{
    return m_kDeclaredMembers.m_data[aiIndex];
}

// @fnv 0x00d47260
const hkVariant* __fastcall GetAttribute(const hkClass* cls, void*, const char* name)
{
    if (cls->m_pCustomAttributes)
        return cls->m_pCustomAttributes->FindEntry(name);
    return 0;
}

// @fnv 0x00d472a0
hkClass* __fastcall InitializeClass(hkClass* cls, void*, unsigned int auiValue0, unsigned int auiValue1, unsigned int auiValue2,
                           unsigned int auiUnused, unsigned int auiValue3, unsigned int auiValue4,
                           unsigned int auiValue5, unsigned int auiValue6, unsigned int auiValue7,
                           unsigned int auiValue8, unsigned int auiValue9, unsigned int auiValue10,
                           unsigned int auiValue11)
{
    cls->m_name = reinterpret_cast<char*>(auiValue0);
    cls->m_parent = reinterpret_cast<hkClass*>(auiValue1);
    cls->m_iObjectSize = auiValue2;
    cls->m_iNumImplementedInterfaces = auiValue3;
    cls->m_kDeclaredEnums.m_data = reinterpret_cast<hkClassEnum*>(auiValue4);
    cls->m_kDeclaredEnums.m_iElementCount = auiValue5;
    cls->m_kDeclaredMembers.m_data = reinterpret_cast<hkClassMember*>(auiValue6);
    cls->m_kDeclaredMembers.m_iElementCount = auiValue7;
    cls->m_pDefaultObject = reinterpret_cast<void*>(auiValue8);
    cls->m_pCustomAttributes = reinterpret_cast<hkCustomAttributes*>(auiValue9);
    cls->m_flags = auiValue10;
    cls->m_iDescribedVersion = auiValue11;
    return cls;
}

// @fnv 0x00d46f00
__declspec(noinline) unsigned int __fastcall GetNumMembers(const hkClass* cls)
{
    const hkClass* parent = cls->m_parent;
    unsigned int total = cls->m_kDeclaredMembers.m_iElementCount;
    while (parent)
    {
        total += parent->m_kDeclaredMembers.m_iElementCount;
        parent = parent->m_parent;
    }
    return total;
}

int __cdecl hkString_strCmp(const char*, const char*);

// Scans the container's members by index and returns the first whose name matches the given string, or 0 if none match.
// @fnv 0x00d46f90
const hkClassMember* __fastcall FindDeclaredMemberByName(const hkClass* self, void*, const char* name)
{
    int i = 0;
    if (self->GetNumDeclaredMembers() > 0)
    {
        do
        {
            const hkClassMember* member = &self->GetDeclaredMember(i);
            const char* pcMemberName = member->m_name;
            if (!hkString_strCmp(pcMemberName, name))
                return member;
            ++i;
        } while (i < self->GetNumDeclaredMembers());
    }
    return 0;
}

// Scans entries by index and returns the first whose first field matches name via FUN_00cb0fa0, or 0 if none match.
// @fnv 0x00d46fe0
__declspec(noinline) const hkClassMember* __fastcall FindMemberByName(const hkClass* cls, void*, const char* name)
{
    for (int i = 0; i < (int)GetNumMembers(cls); i++)
    {
        const hkClassMember* m = &cls->getMember(i);
        if (hkString_strCmp(m->m_name, name) == 0)
            return m;
    }
    return 0;
}

// Scans entries by index, comparing each entry's name string to name, and returns the first matching index or -1.
// @fnv 0x00d47080
int __fastcall FindDeclaredMemberIndexByName(const hkClass* cls, void*, const char* name)
{
    int i = 0;
    if (cls->GetNumDeclaredMembers() > 0)
    {
        do
        {
            if (hkString_strCmp(cls->GetDeclaredMember(i).m_name, name) == 0)
                return i;
            ++i;
        } while (i < cls->GetNumDeclaredMembers());
    }
    return -1;
}

// @fnv 0x00d471a0
int __fastcall HasDeclaredDefault(const hkClass* cls, void*, int aiIndex)
{
    const int* offsets = static_cast<const int*>(cls->m_pDefaultObject);
    if (offsets && offsets[aiIndex] >= 0)
        return 1;
    return 0;
}

struct FUN_00d87150_class
{
    int m_offset;
    const hkClassMember* m_kMemberDescriptor;

    void InitBitOffset(int baseOffset, const hkClass* cls, const char* name);
};

// Stores the member descriptor and adds its byte offset to baseOffset when found.
// @fnv 0x00d87150
void FUN_00d87150_class::InitBitOffset(int baseOffset, const hkClass* apClass, const char* name)
{
    m_offset = 0;
    // This undeclared shared-class method takes ECX plus one stack argument.
    typedef const hkClassMember* (__thiscall *MemberLookup)(const hkClass*, const char*);
    m_kMemberDescriptor = reinterpret_cast<MemberLookup>(FindMemberByName)(apClass, name);
    if (m_kMemberDescriptor)
        m_offset = baseOffset + m_kMemberDescriptor->m_offset;
}

// @fnv 0x00d470e0
void __fastcall SetObjectSize(hkClass* cls, void*, int value)
{
    cls->m_iObjectSize = value;
}

// 00d46d40: trivial __thiscall getter returning the first dword of the object
// (m_name at offset 0 of the Havok class node).
// @fnv 0x00d46d40
const char* hkClass::getName() const
{
    return m_name;
}

// @fnv 0x00d46d50
__declspec(noinline) const hkClass* __fastcall GetParent(const hkClass* cls)
{
    return cls->m_parent;
}

// @fnv 0x00d46f60
const hkClassMember* __fastcall GetInheritedMember(const hkClass* cls, void*, int a1)
{
    return &cls->getMember(a1);
}

// @fnv 0x00d46f70
__declspec(noinline) int hkClass::GetNumDeclaredMembers() const
{
    return m_kDeclaredMembers.m_iElementCount;
}

// @fnv 0x00d470d0
int __fastcall GetObjectSize(const hkClass* cls)
{
    return cls->m_iObjectSize;
}

// FUN_00d47120: 4-byte inline getter, __thiscall, reads this+0x2C.
// Neighbours use hkClass layout (m_parent@0x04, declaredMembers@0x18, defaults@0x20,
// sizeof == 0x30), so +0x2C is m_iDescribedVersion.

// The shared class has no version getter; this leaf uses the same ECX-only ABI.
// @fnv 0x00d47120
int __fastcall GetDescribedVersion(const hkClass* cls)
{
    return cls->m_iDescribedVersion;
}

inline bool GetDeclaredDefaultAddress(const hkClass* cls, int index, const char*& value)
{
    if (cls->m_pDefaultObject)
    {
        int off = static_cast<const int*>(cls->m_pDefaultObject)[index];
        if (off >= 0)
        {
            value = static_cast<const char*>(cls->m_pDefaultObject) + off;
            return true;
        }
    }
    return false;
}

// Writes the declared member's default value, returning success or failure.
// @fnv 0x00d47210
hkResult __fastcall WriteDeclaredDefaultValue(const hkClass* cls, void*, int index, hkStreamWriter* writer)
{
    const char* name;
    if (GetDeclaredDefaultAddress(cls, index, name))
    {
        writer->write(name, GetMemberSize(&cls->m_kDeclaredMembers.m_data[index]));
        return HK_SUCCESS;
    }
    return HK_FAILURE;
}

int __fastcall GetNumDeclaredEnums(const hkClass* cls);
const hkClassEnum* __fastcall GetDeclaredEnum(const hkClass* cls, void*, int index);

// @fnv 0x00d47300
const hkClassEnum* __fastcall FindDeclaredEnumByName(const hkClass* cls, void*, const char* name)
{
    for (int i = 0; i < GetNumDeclaredEnums(cls); i++)
    {
        typedef const hkClassEnum* (__thiscall *EnumAt)(const hkClass*, int);
        const hkClassEnum* entry = reinterpret_cast<EnumAt>(GetDeclaredEnum)(cls, i);
        if (hkString_strCmp(entry->m_name, name) == 0)
            return entry;
    }
    return 0;
}

struct SmallFlag
{
    unsigned char v;
    SmallFlag(bool flag) : v(flag ? 1 : 0)
    {}
    SmallFlag(const SmallFlag& rhs) : v(rhs.v)
    {}
};
// Really hkOArchive (vftable 0x010d14f8, ctor 0x00d60830, dtor 0x00d60590, FUN_00d60900 = hkOArchive::write16). 0x00d47490 has no
// EH frame although this unit is /EHsc and hkclass has no /EHs-c- variant unit, so this view keeps the explicit destructor call.
struct hkOArchive_ExplicitDtorView
{
    unsigned int unk00, unk04, unk08, unk0c;
    void __thiscall hkOArchive_InitializeWriterWithByteSwap(void* stream, SmallFlag swap);
    void __thiscall WriteInt(int value);
    void __thiscall FUN_00d60900(unsigned short value);
    int __thiscall hkOArchive_writeRaw(const void* data, int bytes);
    void __thiscall ReleaseReference_00d60590();
};
// 0x00d868a0 indexes 12-byte native-type properties at 0x011b6ab0, not hkTypeInfo objects.
struct NativeTypeProperties
{
    int m_type;
    const char* m_name;
    short m_size;
    short m_alignment;
};
NativeTypeProperties* __cdecl hkClassMember_getClassMemberTypeProperties(unsigned int which);
int __cdecl hkString_strLen(const char* str);
// @fnv 0x00d47490
__declspec(noinline) void __fastcall SerializeClass(const hkClass* cls, void*, void* stream)
{
    hkOArchive_ExplicitDtorView out;
    out.hkOArchive_InitializeWriterWithByteSwap(stream, SmallFlag(false));
    out.WriteInt(cls->m_iNumImplementedInterfaces);
    for (int enumIndex = 0; enumIndex < cls->m_kDeclaredEnums.m_iElementCount; ++enumIndex)
    {
        reinterpret_cast<EnumSerializer>(SerializeEnum)(&cls->m_kDeclaredEnums.m_data[enumIndex], stream);
    }
    out.WriteInt(cls->m_kDeclaredEnums.m_iElementCount);
    for (int memberIndex = 0; memberIndex < cls->m_kDeclaredMembers.m_iElementCount; ++memberIndex)
    {
        const hkClassMember& member = cls->m_kDeclaredMembers.m_data[memberIndex];
        hkClassMember info = member;
        if (info.m_type == 0x18 || info.m_type == 0x1f)
        {
            unsigned short typeWidth = hkClassMember_getClassMemberTypeProperties(info.m_eSubtype)->m_size;
            info.m_flags ^= typeWidth * 8;
            info.m_eSubtype = 0;
        }
        unsigned short altType = 0;
        if (info.m_flags & 0x400)
        {
            info.m_flags ^= 0x400;
            if (info.m_eSubtype != 0)
                altType = info.m_eSubtype;
            info.m_eSubtype = info.m_type;
            info.m_type = 0x13;
        }
        if (info.m_class && member.m_type != 0x14 && member.m_eSubtype != 0x14)
        {
            const hkClass* parentClass = member.getClass();
            while (parentClass)
            {
                reinterpret_cast<ClassSerializer>(SerializeClass)(parentClass, stream);
                parentClass = GetParent(parentClass);
            }
        }
        if (info.m_pClassEnum)
            reinterpret_cast<EnumSerializer>(SerializeEnum)(GetMemberEnum(&member), stream);
        out.hkOArchive_writeRaw(info.m_name, hkString_strLen(info.m_name));
        out.FUN_00d60900(info.m_type);
        out.FUN_00d60900(info.m_eSubtype);
        if (altType != 0)
            out.FUN_00d60900(altType);
        out.FUN_00d60900(info.m_iArraySize);
        out.FUN_00d60900(info.m_flags);
    }
    out.WriteInt(cls->m_kDeclaredMembers.m_iElementCount);
    out.ReleaseReference_00d60590();
}

struct FUN_00db7870
{
    void* vfptr;
    int unk04;
    int unk08;
    FUN_00db7870(int);
    unsigned int ComputeValue_00db7860();
};

// Computes a CRC over this class and, unless SIGNATURE_LOCAL is set, over its parent chain, returning the CRC value.
// @fnv 0x00d47690
unsigned int __fastcall ComputeSignature(const hkClass* cls, void*, int signatureFlags)
{
    FUN_00db7870 crc(0);
    bool recurse = !(signatureFlags & hkClass::SIGNATURE_LOCAL);
    for (const hkClass* c = cls; c;)
    {
        reinterpret_cast<ClassSerializer>(SerializeClass)(c, &crc);
        if (!recurse)
        {
            break;
        }
        c = GetParent(c);
    }
    return crc.ComputeValue_00db7860();
}

void __cdecl hkString_memCpy(void* dst, const void* src, int n);

struct ReflectionTypeTag
{
    int m_type;
};

// This tagged value has a 64-byte payload at +0x10; shared hkVariant is only two pointers.
struct ReflectionValueStorage
{
    unsigned int m_type;
    int unk04;
    int unk08;
    int unk0C;
    union
    {
        char m_data[0x40];
        struct
        {
            union
            {
                const void* m_value;
                int m_enumValue;
            };
            const void* m_descriptor;
        };
    };

    __declspec(noinline) int SetData(const void* src, unsigned int type);
    int SetData(void* src, ReflectionTypeTag type);
};

// Looks up the type info for type, and if its size is at most 0x40, stores type and copies that many bytes from src into m_data, returning 0; otherwise returns 1.
// @fnv 0x00d476e0
__declspec(noinline) int ReflectionValueStorage::SetData(const void* src, unsigned int type)
{
    NativeTypeProperties* info = hkClassMember_getClassMemberTypeProperties(type);
    if ((unsigned short)info->m_size <= 0x40)
    {
        m_type = type;
        hkString_memCpy(m_data, src, info->m_size);
        return 0;
    }
    return 1;
}

// @fnv 0x00d86b30
unsigned int __fastcall GetMemberSubtype(const hkClassMember* member)
{
    return member->m_eSubtype;
}

// @fnv 0x00d46cf0
const hkVariant* hkCustomAttributes::FindEntry(const char* pcName) const
{
    for (int i = 0; i < m_iElementCount; i++)
    {
        if (hkString_strCmp(m_data[i].m_name, pcName) == 0)
            return &m_data[i].m_value;
    }
    return 0;
}

// Resolves a member index across the hkClass parent chain.
// @fnv 0x00d46f20
// src: HAVOK_LIB 0x00d46f20
__declspec(noinline) const hkClassMember& hkClass::getMember(int aiIndex) const
{
    const hkClass* pNode = this;
    int iOffset = aiIndex - GetNumMembers(this);
    if (this != 0)
    {
        do
        {
            iOffset += pNode->m_kDeclaredMembers.m_iElementCount;
            if (iOffset >= 0)
                return pNode->m_kDeclaredMembers.m_data[iOffset];
            pNode = pNode->m_parent;
        } while (pNode != 0);
    }
    return this->m_kDeclaredMembers.m_data[0];
}

// The old enum view calls hkClass::GetNumMembers (0x00d46f00) and its 24-byte member accessor (0x00d46f20).
// Returns the inherited member index matching name, or -1.
// @fnv 0x00d47030
int __fastcall FindMemberIndexByName(const hkClass* cls, void*, const char* name)
{
    for (int i = 0; i < (int)GetNumMembers(cls); i++)
    {
        if (hkString_strCmp(cls->getMember(i).m_name, name) == 0)
            return i;
    }
    return -1;
}

static __declspec(noinline) hkClass* FUN_00d46d50(hkClass* node)
{
    return node->m_parent;
}

class ResultPtr
{
  public:
    char* p;
    ResultPtr(char* pp) : p(pp)
    {}
};

// Follows parent links, updating lastNode, then writes whether lastNode->m_iNumImplementedInterfaces is non-zero through out.p.
// @fnv 0x00d470f0
static __declspec(noinline) char* __stdcall GetLastNodeFlag(hkClass* apStartNode, hkClass* lastNode, ResultPtr out)
{
    hkClass* next = FUN_00d46d50(apStartNode);
    while (next)
    {
        lastNode = next;
        apStartNode = next;
        next = FUN_00d46d50(apStartNode);
    }
    char* dst = out.p;
    *dst = (lastNode->m_iNumImplementedInterfaces != 0);
    return dst;
}

static volatile int g_pad;
static volatile char* g_charptr;
void ZNegotiate(hkClass* n)
{
    g_charptr = GetLastNodeFlag(n, n, ResultPtr((char*)&g_pad));
}

int __fastcall LookupDefaultAddress(const hkClass*, void*, const char*, int*, const hkClassMember**);

// Writes a member's default value using its reflected size.
// @fnv 0x00d471c0
int __fastcall WriteDefaultValue(const hkClass* cls, int, const char* memberIndex, hkStreamWriter* target)
{
    int value;
    const hkClassMember* p;
    typedef int (__thiscall *RawDefaultLookup)(const hkClass*, const char*, int*, const hkClassMember**);
    int result = reinterpret_cast<RawDefaultLookup>(LookupDefaultAddress)(cls, memberIndex, &value, &p);
    if (result == 0)
        target->write(reinterpret_cast<const void*>(value), GetMemberSize(p));
    return result;
}

class FUN_00def160 : public hkReferencedObject,
                     public hkpEntityListener,
                     public hkpConstraintListener,
                     public hkpActionListener,
                     public hkpPhantomListener
{
  public:
    virtual ~FUN_00def160();

    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};

hkpWorldPostSimulationListener::~hkpWorldPostSimulationListener() throw()
{}

class FUN_00d87bf0 : public FUN_00def160, public hkpWorldPostSimulationListener
{
  public:
    virtual ~FUN_00d87bf0();
};

// @fnv 0x00d87bf0
FUN_00d87bf0::~FUN_00d87bf0()
{}

// @fnv 0x00d47280
unsigned int* __fastcall GetFlags(hkClass* cls)
{
    return &cls->m_flags;
}

struct S00d47350_Res
{
    int value;
};

struct Outs
{
    void** pobj;
    const hkClassMember** pm;
};
// One pointer passed to the 0x00d47130 default lookup; Data.h instead defines a 16-byte record.
struct DefaultValueAddress
{
    void* p;
};
S00d47350_Res __fastcall FUN_00d47130(const hkClass* self, DefaultValueAddress obj, Outs r);

// Uses the member returned by FUN_00d47130 to populate output according to the member's type.
// @fnv 0x00d47350
// src: HAVOK_LIB 0x00d47350
S00d47350_Res __fastcall hkClass_getDefault(const hkClass* self, int, void* data, ReflectionValueStorage* output)
{
    const hkClassMember* holder;
    Outs r;
    r.pm = &holder;
    r.pobj = &data;
    DefaultValueAddress dsData;
    dsData.p = data;
    S00d47350_Res result = FUN_00d47130(self, dsData, r);
    if (result.value != 0)
        return result;
    const hkClassMember* member = *(const hkClassMember* volatile*)&holder;
    unsigned char type = member->m_type;
    if (type == 0x14)
    {
        const void* d = member->getClass();
        output->m_type = 0x14;
        output->m_value = data;
        output->m_descriptor = d;
        return result;
    }
    if (type == 0x18)
    {
        const void* descriptor = GetMemberEnum(member);
        int enumValue = reinterpret_cast<MemberValueReader>(ReadMemberSignedValue)(member, data);
        output->m_enumValue = enumValue;
        output->m_descriptor = descriptor;
        output->m_type = 0x18;
        return result;
    }
    S00d47350_Res resFallback;
    ReflectionTypeTag tag;
    tag.m_type = type;
    resFallback.value = output->SetData(data, tag);
    return resFallback;
}

#include <string.h>
namespace fnv_00cb0fa0 {
// Returns the result of comparing two null-terminated strings using strcmp.
// @fnv 0x00cb0fa0
// src: HAVOK_LIB 0x00cb0fa0
int __cdecl hkString_strCmp(const char* pcA, const char* pcB)
{
    return strcmp(pcA, pcB);
}
}  // namespace fnv_00cb0fa0

// Walks the parent chain to locate the node containing the offset, then resolves the member pointer and value from m_pDefaultObject.
// @fnv 0x00d47130
__declspec(noinline) int __fastcall GetDefaultValue(const hkClass* cls, void*, int offset, char** value, const hkClassMember** member)
{
    const hkClass* node = cls;
    offset -= GetNumMembers(node);
    while (node != 0)
    {
        offset += node->m_kDeclaredMembers.m_iElementCount;
        if (offset >= 0)
            break;
        node = node->m_parent;
    }
    if (node != 0)
    {
        if (node->m_pDefaultObject != 0)
        {
            int relative = static_cast<const int*>(node->m_pDefaultObject)[offset];
            if (relative >= 0)
            {
                *value = reinterpret_cast<char*>(node->m_pDefaultObject) + relative;
                *member = node->m_kDeclaredMembers.m_data + offset;
                return 0;
            }
        }
    }
    return 1;
}

// Reads the value of the member at iIndex from m_pData into kOut, dispatching on the member's type for class, enum, or generic data.
// @fnv 0x00d473f0
hkResult __fastcall ReadDeclaredDefaultValue(const hkClass* cls, void*, int iIndex, ReflectionValueStorage& kOut)
{
    const char* m_pData = static_cast<const char*>(cls->m_pDefaultObject);
    if (m_pData)
    {
        int iOffset = ((const int*)m_pData)[iIndex];
        if (iOffset >= 0)
        {
            const void* pvAddr = static_cast<const char*>(cls->m_pDefaultObject) + iOffset;
            const hkClassMember& kMember = cls->m_kDeclaredMembers.m_data[iIndex];
            hkResult res = HK_SUCCESS;
            unsigned char ucType = kMember.m_type;

            if (ucType == 0x14)
            {
                const hkClass* pkClass = kMember.getClass();
                pvAddr = *(const void* const*)pvAddr;
                kOut.m_descriptor = pkClass;
                kOut.m_value = pvAddr;
                kOut.m_type = 0x14;
            }
            else if (ucType == 0x18)
            {
                const hkClassEnum* pkEnum = GetMemberEnum(&kMember);
                int iValue = reinterpret_cast<MemberValueReader>(ReadMemberSignedValue)(&kMember, pvAddr);
                kOut.m_descriptor = pkEnum;
                kOut.m_value = (const void*)iValue;
                kOut.m_type = 0x18;
            }
            else
            {
                int t = (int)kMember.m_type;
                res = static_cast<hkResult>(kOut.SetData(pvAddr, t));
            }

            return res;
        }
    }

    return HK_FAILURE;
}

int __fastcall WriteDefaultValueAddress(const hkClass* cls, void*, int index, int stream);
typedef int (__thiscall *DefaultWriter)(const hkClass*, int, int);

// src: GUESS 0x00e03100 (confidence: low)
static __declspec(noinline) int Object_ProcessAndReturnValue_00e03100(const hkClassMember* node)
{
    if (node->getCstyleArraySize())
        return node->getCstyleArraySize();
    return 1;
}

// @fnv 0x00e03240
// src: GUESS 0x00e03240 (confidence: low)
int __cdecl hkClass_ProcessEntries_00e03240(const hkClass* holder, const hkClassMember* node, int value, int flags)
{
    int result = reinterpret_cast<DefaultWriter>(WriteDefaultValueAddress)(holder, value, flags);

    if (node->m_type != 0x19)
        return result;

    const hkClass* childHolder = node->getClass();
    if (!childHolder)
        return result;

    int rounds = Object_ProcessAndReturnValue_00e03100(node);
    if (rounds <= 0)
        return result;

    int outerCount = rounds;
    do
    {
        for (int index = 0; index < (int)GetNumMembers(childHolder); ++index)
        {
            const hkClassMember* child = &childHolder->getMember(index);

            if (!hkClass_ProcessEntries_00e03240(childHolder, child, index, flags))
                result = 0;
        }
    } while (--outerCount);

    return result;
}
