
// src/havok/common/base/reflection/hkclassmember.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassmember.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkClassMember.h"
#include "../../../../../include/hkCustomAttributes.h"


// @fnv 0x00d86960
const hkVariant* hkClassMember::FUN_00d86960(const char* name) const throw()
{
    if (m_pCustomAttributes)
        return m_pCustomAttributes->getAttribute(name);
    return 0;
}

extern char DAT_011b6ab0;

// @fnv 0x00d868a0
char* __cdecl FUN_00d868a0(int index)
{
    return &DAT_011b6ab0 + index * 12;
}

int __cdecl FUN_00d86980();

// Stores v into p as a char, short or int depending on the size returned by FUN_00d86980.
// @fnv 0x00d86bc0
void __stdcall FUN_00d86bc0(int apTarget, int aiValue)
{
    switch (FUN_00d86980())
    {
    case 1:
        *(char*)apTarget = (char)aiValue;
        break;
    case 2:
        *(short*)apTarget = (short)aiValue;
        break;
    case 4:
        *(int*)apTarget = aiValue;
        break;
    default:
        break;
    }
}

// @fnv 0x00d868b0
static bool FUN_00d868b0(hkClassMember::Type aeType)
{
    return aeType >= 0 && (aeType < hkClassMember::TYPE_POINTER || aeType == hkClassMember::TYPE_VARIANT ||
                           aeType == hkClassMember::TYPE_ULONG || aeType == hkClassMember::TYPE_CSTRING ||
                           aeType == hkClassMember::TYPE_HALF || aeType == hkClassMember::TYPE_STRINGPTR);
}

void dummy(hkClassMember::Type x)
{
    FUN_00d868b0(x);
}

// @fnv 0x00d86910
__declspec(noinline) const hkClass* hkClassMember::GetClass() const
{
    return this->m_class;
}

// @fnv 0x00d86920
const hkClass* hkClassMember::FUN_00d86920() const throw()
{
    return m_class;
}

// Missing zero-argument methods use ECX-only helpers, matching the original member-call convention.
// @fnv 0x00d86930
hkClassEnum* __fastcall GetMemberEnum(const hkClassMember* member)
{
    return member->m_pClassEnum;
}

struct FUN_00dba990_Obj
{
    int FUN_00dba990();
};

// The shared header lacks the setter; this call type supplies its original ECX this argument.
typedef void (__thiscall* MemberValueSetter)(hkClassMember*, int, int);

// @fnv 0x00dc1bf0
unsigned int __stdcall FUN_00dc1bf0(int aiArg, int pMember, int pSource, int aiUnused)
{
    hkClassMember* member = (hkClassMember*)pMember;
    unsigned int type = member->m_type;

    switch (type)
    {
    case 0x18:
        if (member->m_pClassEnum != 0)
        {
            int result = ((FUN_00dba990_Obj*)pSource)->FUN_00dba990();
            ((MemberValueSetter)&FUN_00d86bc0)(member, aiArg, result);
        }
        return 0;
    case 0x1f:
        if (member->m_pClassEnum != 0)
        {
            ((MemberValueSetter)&FUN_00d86bc0)(member, aiArg, ((FUN_00dba990_Obj*)pSource)->FUN_00dba990());
        }
        return 0;
    }
    return 1;
}

struct NativeTypePropertyD86A
{
    int m_type;
    const char* m_name;
    short m_iElementCount;
    short m_usFlags;
};

int __fastcall GetNumMembers(const hkClass* klass);

// Returns the memory alignment of this class member, derived from its type, struct member alignments, or explicit ALIGN_8/ALIGN_16 flags.
// @fnv 0x00d86a90
int __fastcall GetMemberAlignment(const hkClassMember* member)
{
    int type = member->m_type;
    if (type == hkClassMember::TYPE_ENUM || type == hkClassMember::TYPE_FLAGS)
        type = member->m_eSubtype;

    int align;
    if (type == hkClassMember::TYPE_STRUCT)
    {
        int structAlign = 1;
        for (int i = 0; i < GetNumMembers(member->m_class); i++)
        {
            if (GetMemberAlignment(&member->m_class->FUN_00d46f20(i)) > structAlign)
                structAlign = GetMemberAlignment(&member->m_class->FUN_00d46f20(i));
        }
        align = structAlign;
    }
    else
    {
        align = ((const NativeTypePropertyD86A*)&DAT_011b6ab0)[type].m_usFlags;
    }

    if (member->m_flags & (hkClassMember::ALIGN_8 | hkClassMember::ALIGN_16))
    {
        int required = (bool)((member->m_flags >> 8) & 1) ? 16 : 8;
        if (required > align)
            align = required;
    }
    return align;
}

struct TypeDescription
{
    const char* name;
    const char* displayName;
    int size;
};
extern TypeDescription DAT_011b6ab4[];
extern const char str_010d3a74[];
struct TypeNameOutput
{
    void FUN_00d61c10(const char*);
};
extern void __cdecl FUN_00d61d00(TypeNameOutput*, const char*, const char*, const char*);
// Writes the selected type name to output, calling FUN_00d61d00 with that name and detail when detail is non-null.
// @fnv 0x00d868e0
static __declspec(noinline) void FUN_00d868e0(TypeNameOutput* output, const char* detail, int type)
{
    if (!detail)
        output->FUN_00d61c10(DAT_011b6ab4[type].name);
    else
        FUN_00d61d00(output, str_010d3a74, DAT_011b6ab4[type].name, detail);
}
void formatTypeName(TypeNameOutput* output, const char* detail, int type)
{
    FUN_00d868e0(output, detail, type);
}

// @fnv 0x00d86940
__declspec(noinline) int hkClassMember::FUN_00d86940() const throw()
{
    return m_iArraySize;
}

struct TypeProps_d869
{
    int m_type;
    const char* m_name;
    short m_iElementCount;
    short m_usFlags;
};

int __fastcall GetObjectSize(const hkClass* klass);

static inline const TypeProps_d869* typeProps_d869()
{
    return (const TypeProps_d869*)&DAT_011b6ab0;
}

// For handled types, multiplies the selected type-property value or referenced class alignment by the member count; otherwise returns -1.
// @fnv 0x00d86980
int __fastcall GetMemberSize(const hkClassMember* member)
{
    int size = -1;
    switch (member->m_type)
    {
    case hkClassMember::TYPE_BOOL:
    case hkClassMember::TYPE_CHAR:
    case hkClassMember::TYPE_INT8:
    case hkClassMember::TYPE_UINT8:
    case hkClassMember::TYPE_INT16:
    case hkClassMember::TYPE_UINT16:
    case hkClassMember::TYPE_INT32:
    case hkClassMember::TYPE_UINT32:
    case hkClassMember::TYPE_INT64:
    case hkClassMember::TYPE_UINT64:
    case hkClassMember::TYPE_REAL:
    case hkClassMember::TYPE_VECTOR4:
    case hkClassMember::TYPE_QUATERNION:
    case hkClassMember::TYPE_MATRIX3:
    case hkClassMember::TYPE_ROTATION:
    case hkClassMember::TYPE_QSTRANSFORM:
    case hkClassMember::TYPE_MATRIX4:
    case hkClassMember::TYPE_TRANSFORM:
    case hkClassMember::TYPE_POINTER:
    case hkClassMember::TYPE_FUNCTIONPOINTER:
    case hkClassMember::TYPE_ARRAY:
    case hkClassMember::TYPE_SIMPLEARRAY:
    case hkClassMember::TYPE_HOMOGENEOUSARRAY:
    case hkClassMember::TYPE_VARIANT:
    case hkClassMember::TYPE_CSTRING:
    case hkClassMember::TYPE_ULONG:
    case hkClassMember::TYPE_HALF:
    case hkClassMember::TYPE_STRINGPTR: {
        int nelem = member->FUN_00d86940() ? member->FUN_00d86940() : 1;
        size = nelem * typeProps_d869()[member->m_type].m_iElementCount;
    }
    break;
    case hkClassMember::TYPE_ENUM:
    case hkClassMember::TYPE_FLAGS: {
        int nelem = member->FUN_00d86940() ? member->FUN_00d86940() : 1;
        size = nelem * typeProps_d869()[member->m_eSubtype].m_iElementCount;
    }
    break;
    case hkClassMember::TYPE_STRUCT: {
        int nelem = member->FUN_00d86940() ? member->FUN_00d86940() : 1;
        size = nelem * GetObjectSize(member->GetClass());
    }
    break;
    case hkClassMember::TYPE_ZERO:
    case hkClassMember::TYPE_INPLACEARRAY:
        break;
    }
    return size;
}
