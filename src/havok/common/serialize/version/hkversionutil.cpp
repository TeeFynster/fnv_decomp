
// src/havok/common/serialize/version/hkversionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/MemoryManager.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkClassMember.h"


extern "C" void __cdecl VisitObjectList(int, int);

struct FUN_00db7a80_Class
{
    int __pad0;
    int __pad1;
    int __pad2;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void EnsureInitialized();
};

// @fnv 0x00db7a80
void FUN_00db7a80_Class::EnsureInitialized()
{
    if (!m_iFourthElementInteger)
    {
        VisitObjectList(m_kPointB, m_iThirdValue);
        m_iFourthElementInteger = 1;
    }
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct Object
{
    void SetVirtualTable_00e03160();
};

struct FUN_00e049d0_Class : Object
{
    unsigned int m_auiShapeKeys;
    unsigned short m_type;

    FUN_00e049d0_Class* FUN_00e049d0(int flags);
};

// @fnv 0x00e049d0
FUN_00e049d0_Class* FUN_00e049d0_Class::FUN_00e049d0(int flags)
{
    Object::SetVirtualTable_00e03160();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short type = m_type;
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(this, type);
    }

    return this;
}

extern "C" char str_010cf830[];

// @fnv 0x00dc0fb0
// src: XBOX_PDB 0x00dc0fb0
void* __cdecl hkVersionUtil_getCurrentVersion()
{
    return &str_010cf830;
}

// These getters are absent from the shared headers; a single fastcall argument
// preserves the ECX receiver of each original zero-argument member call.
int __fastcall GetMemberSize(const hkClassMember* member);
const hkClass* __fastcall GetMemberClass(const hkClassMember* member) throw();
const char* __fastcall GetClassName(const hkClass* klass) throw();

struct FUN_00d871a0
{
    int m_00;
    int m_04;

    FUN_00d871a0(void*, int);
    bool& ComputeValue_00d871e0(bool&);
    void* GetValue();
    hkClassMember* hkClassMemberAccessor_getClassMember();
};

extern "C" void* __cdecl hkString_memCpy(void*, const void*, unsigned int);

// @fnv 0x00dc0fc0
// src: XBOX_PDB 0x00dc0fc0
void __cdecl hkVersionUtil_renameMember(void* a1, int a2, void* a3, int a4)
{
    FUN_00d871a0 obj1(a1, a2);
    FUN_00d871a0 obj2(a3, a4);
    bool b;
    if (obj1.ComputeValue_00d871e0(b) && obj2.ComputeValue_00d871e0(b))
    {
        hkString_memCpy(obj2.GetValue(), obj1.GetValue(), GetMemberSize(obj2.hkClassMemberAccessor_getClassMember()));
    }
}

extern hkClass g_01268748;

int __cdecl hkString_strCmp(const char* pcA, const char* pcB) throw();

class hkVersionCheckDC11
{
  public:
    int hkObjectCopier_areMembersCompatible(const hkClassMember* pkOld, const hkClassMember* pkNew) throw();
    int IsMemberCompatible(const hkClassMember* pkOld, const hkClassMember* pkNew) throw();
};

// Returns 1 if the old class member is compatible with the new one by type/subtype, cstring-to-stringptr, or variant-to-pointer conversion; otherwise 0.
// @fnv 0x00dc1100
int hkVersionCheckDC11::IsMemberCompatible(const hkClassMember* pkOld, const hkClassMember* pkNew) throw()
{
    bool bTypeCompatible = (pkOld->m_type == pkNew->m_type) || (pkOld->m_type == hkClassMember::TYPE_SIMPLEARRAY &&
                                                                pkNew->m_type == hkClassMember::TYPE_ARRAY);
    bool bCStringToStringPtr =
        (pkOld->m_type == hkClassMember::TYPE_CSTRING && pkNew->m_type == hkClassMember::TYPE_STRINGPTR);
    bool bVariantToPtr =
        (pkOld->m_type == hkClassMember::TYPE_VARIANT && pkNew->m_type == hkClassMember::TYPE_POINTER &&
         pkNew->m_eSubtype == hkClassMember::TYPE_STRUCT && GetMemberClass(pkNew) &&
         hkString_strCmp(GetClassName(&g_01268748), GetClassName(pkNew->GetClass())) == 0);
    bool bSubTypeCompatible =
        (pkOld->m_eSubtype == pkNew->m_eSubtype) || (pkOld->m_eSubtype == hkClassMember::TYPE_CSTRING &&
                                                     pkNew->m_eSubtype == hkClassMember::TYPE_STRINGPTR);
    bool bSubVariantToPtr =
        (pkOld->m_eSubtype == hkClassMember::TYPE_VARIANT && pkNew->m_eSubtype == hkClassMember::TYPE_POINTER &&
         GetMemberClass(pkNew) && hkString_strCmp(GetClassName(&g_01268748), GetClassName(pkNew->GetClass())) == 0);

    if (hkObjectCopier_areMembersCompatible(pkOld, pkNew) || bCStringToStringPtr || bVariantToPtr ||
        (bTypeCompatible && (bSubTypeCompatible || bSubVariantToPtr)))
        return 1;
    return 0;
}

class hkMemoryAllocatorDC12;

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

void __cdecl ProcessObjectArray(void* const* ppvList, int iFlags) throw();

class hkPointerMapDC12
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkPointerMapDC12() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~hkPointerMapDC12() throw()
    {
        Object_DoNothing();
    }

    void EnsureCapacity(hkMemoryAllocatorDC12& kAlloc, int iNumElems) throw();
    void ProcessArgument(hkMemoryAllocatorDC12& kAlloc) throw();
    void Object_DoNothing() throw();
};

class hkVisitorDC12
{
  public:
    int unk00;

    hkVisitorDC12() throw()
    {
        hkStructureLayout_hkStructureLayout();
    }
    void hkStructureLayout_hkStructureLayout() throw();
    void UpdateState_00dc1bb0(void* pvObject, hkPointerMapDC12& kDone, int iFlags) throw();
};

// @fnv 0x00dc1230
extern "C" void __cdecl VisitObjectList(int apvList, int iFlags)
{
    void* const* ppvList = reinterpret_cast<void* const*>(apvList);
    ProcessObjectArray(ppvList, iFlags);
    hkVisitorDC12 kVisitor;
    hkPointerMapDC12 kDone;
    kDone.EnsureCapacity(reinterpret_cast<hkMemoryAllocatorDC12&>(hkMemoryRouter_getInstance().heap()), 0);
    for (int i = 0; ppvList[i]; i++)
        kVisitor.UpdateState_00dc1bb0(ppvList[i], kDone, 1);
    kDone.ProcessArgument(reinterpret_cast<hkMemoryAllocatorDC12&>(hkMemoryRouter_getInstance().heap()));
}

class FUN_00d27520
{
  public:
    void FUN_00d27520_dtor() throw();
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    char m_overflowed;
};

class FUN_00d274c0 : public FUN_00d27520
{
  public:
    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, hkBool bMemoryIsString) throw();
    int hkBufferedStreamWriter_seek(int offset, int whence) throw();
};

class SetDC10
{
  public:
    int FUN_00d46fe0(int key) throw();
};

class SectionsDC10
{
  public:
    int FUN_00d470d0() throw();
    int FUN_00d46f00() throw();
    hkClassMember* getMember(int i) throw();
    void InvokeTarget(int i, FUN_00d27520* pkWriter) throw();
};

// Writes entries from pkSections whose key is not in pkSet to pvBuf via a FUN_00d274c0 writer.
// @fnv 0x00dc1070
// src: XBOX_PDB 0x00dc1070
void __cdecl hkVersionUtil_copyDefaults(void* apvBuffer, SetDC10* pkSet, SectionsDC10* pkSections)
{
    FUN_00d274c0 kWriter(apvBuffer, pkSections->FUN_00d470d0(), false);
    for (int i = 0; i < pkSections->FUN_00d46f00(); i++)
    {
        hkClassMember* pkEntry = pkSections->getMember(i);
        int key = reinterpret_cast<int>(pkEntry->m_name);
        if (!pkSet->FUN_00d46fe0(key))
        {
            int iOffset = pkEntry->m_offset;
            kWriter.hkBufferedStreamWriter_seek(iOffset, 0);
            pkSections->InvokeTarget(i, &kWriter);
        }
    }
    kWriter.FUN_00d27520_dtor();
}

struct S00dc15a0_Buffer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int* indices, unsigned int size);
};

struct S00dc15a0_Params
{
    void* unk00;
    int unk04;
};

struct S00dc15a0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
};

namespace fnvc_adapt {
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
}
extern "C" void __cdecl hkArrayUtil__reserve(S00dc15a0_Buffer* buffer, int** indices, int size, int elementSize);

// src: GUESS 0x00dc12c0 (confidence: low)
static __declspec(noinline) int Object_ComputeValue_00dc12c0(S00dc15a0_Params* params, int value, int flags, S00dc15a0_Array* arr)
{
    arr->m_iElementCount = (int)&params + (int)&value + (int)&flags;
    return arr->m_capFlags;
}

// Builds an array containing 0..count-1, passes it to FUN_00dc12c0, and returns that call's result.
// @fnv 0x00dc15a0
// src: GUESS 0x00dc15a0 (confidence: medium)
int __cdecl Object_BuildIndexArrayAndDispatch(S00dc15a0_Params* params, int value, int flags)
{
    S00dc15a0_Array arr;
    int count = params->unk04;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000000;

    hkMemoryRouter* router = fnvc_adapt::hkMemoryRouter_getInstance();
    S00dc15a0_Buffer* heap = reinterpret_cast<S00dc15a0_Buffer*>(router->m_temp);
    int iCurrentCap = arr.m_capFlags & 0x3fffffff;
    if (iCurrentCap < count)
    {
        int newCap = iCurrentCap + iCurrentCap;
        if (count >= newCap)
            newCap = count;
        hkArrayUtil__reserve(heap, &arr.m_data, newCap, 4);
    }

    int index = 0;
    arr.m_iElementCount = count;
    if (params->unk04 > 0)
    {
        do
        {
            arr.m_data[index] = index;
            ++index;
        } while (index < params->unk04);
    }

    int result = Object_ComputeValue_00dc12c0(params, value, flags, &arr);

    router = fnvc_adapt::hkMemoryRouter_getInstance();
    S00dc15a0_Buffer* heap2 = reinterpret_cast<S00dc15a0_Buffer*>(router->m_temp);
    arr.m_iElementCount = 0;
    if ((arr.m_capFlags & 0x80000000) == 0)
    {
        heap2->vf10(arr.m_data, (arr.m_capFlags & 0x3fffffff) * 4);
    }

    return result;
}

// Four-byte layout rules copied by the object-copier constructor at 0x00e03120.
struct StructureLayoutRules
{
    char m_ucBytesInPointer;
    char m_bLittleEndian;
    char m_bReusePaddingOptimization;
    char m_bEmptyBaseClassOptimization;
};

struct hkFlagsDC10
{
    int m_kStorage;
    hkFlagsDC10(int i) : m_kStorage(i)
    {}
};

namespace FUN_00e03120 {
class hkObjectCopier
{
  public:
    hkObjectCopier(const StructureLayoutRules& kSrc, const StructureLayoutRules& kDst, hkFlagsDC10 kFlags);
    virtual void CopyContents();
    int unk04, unk08, unk0C;
};
}

namespace FUN_00dc1040 {
class PackfileObjectCopier : public FUN_00e03120::hkObjectCopier
{
  public:
    PackfileObjectCopier(const StructureLayoutRules& kSrc, const StructureLayoutRules& kDst);
    virtual void CopyContents();
};

// @fnv 0x00dc1040
PackfileObjectCopier::PackfileObjectCopier(const StructureLayoutRules& kSrc, const StructureLayoutRules& kDst)
    : FUN_00e03120::hkObjectCopier(kSrc, kDst, 0)
{}
}
