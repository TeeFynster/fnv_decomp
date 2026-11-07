#include "../../../../../../include/Pair.h"
#include "../../../../../../include/hkOstream.h"
#include "../../../../../../include/hkHomogeneousArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkClass.h"
#include "../../../../../../include/hkClassMember.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkVariant.h"
#include "../../../../../../include/hkVtableClassRegistry.h"
#include "../../../../../../include/hkError.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/Index.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkDataArrayNative.h"
#include "../../../../../../include/hkDataClassNative.h"
#include "../../../../../../include/hkHalf.h"

inline Pair::Pair() throw()
{}

inline hkClassMember::Type hkClassMember::getType() const
{
    return static_cast<Type>(m_type);
}

template <typename AllocatorType>
inline AllocatorType& GetRouterHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<AllocatorType*>(router.m_heap);
}

// src/havok/common/serialize/data/native/hkdataobjectnative.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/native/hkdataobjectnative.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dbb610
// src: HAVOK_LIB 0x00dbb610
void __stdcall hkDataWorldNative_getType(int* p)
{
    *p = 0;
}

struct FUN_00dbb490_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    hkReferencedObject* m_8;
    void SetReferencedObject(hkReferencedObject* p);
};

// @fnv 0x00dbb490
void FUN_00dbb490_class::SetReferencedObject(hkReferencedObject* apObject)
{
    if (apObject)
        apObject->addReference();
    if (m_8)
        m_8->removeReference();
    m_8 = apObject;
}

namespace fnv_00dbb4c0 {
struct FUN_00dbb4c0_class
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    hkReferencedObject* m_pObject;
    void SetObject(hkReferencedObject* object);
};
// @fnv 0x00dbb4c0
void FUN_00dbb4c0_class::SetObject(hkReferencedObject* object)
{
    if (object)
        object->addReference();
    if (m_pObject)
        m_pObject->removeReference();
    m_pObject = object;
}
}  // namespace fnv_00dbb4c0

struct FUN_00dbbb20_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    void* m_10;
    int __thiscall hkDataObjectNative_isValid(int a);
};

struct FUN_00d46f00_Class
{
    int __thiscall FUN_00d46f00();
};

// @fnv 0x00dbbb20
// src: XBOX_PDB 0x00dbbb20
int __thiscall FUN_00dbbb20_Class::hkDataObjectNative_isValid(int a)
{
    return (a < ((FUN_00d46f00_Class*)m_10)->FUN_00d46f00()) ? 1 : 0;
}

// @fnv 0x00dbbc50
// src: HAVOK_LIB 0x00dbbc50
int __thiscall hkDataArrayNative::asVec(int a)
{
    return m_0C + a * m_14;
}

// @fnv 0x00dbbc60
// src: XBOX_PDB 0x00dbbc60
int __thiscall hkDataArrayNative::asString(int aiIndex)
{
    switch (m_18)
    {
    case 0x1d:
        return *(int*)((char*)m_0C + m_14 * aiIndex);
    case 0x21:
        return (*(int*)((char*)m_0C + m_14 * aiIndex)) & 0xfffffffe;
    default:
        return 0;
    }
}

// @fnv 0x00d873b0
__declspec(noinline) Pair::Pair(int aiFirst, int aiSecond)
{
    a = aiFirst;
    b = aiSecond;
}

// @fnv 0x00dbb920
const char* hkDataClassNative::getName() const
{
    return m_0C->getName();
}

namespace fnv_00dbb940 {

struct FUN_00d46d50_s
{
    hkClass* FUN_00d46d50();
};

struct FUN_00dbb940_VirtualClass
{
    virtual void FUN_00dbb940_0() = 0;
    virtual void FUN_00dbb940_1() = 0;
    virtual void FUN_00dbb940_2() = 0;
    virtual void FUN_00dbb940_3() = 0;
    virtual void FUN_00dbb940_4() = 0;
    virtual void FUN_00dbb940_5() = 0;
    virtual void FUN_00dbb940_6() = 0;
    virtual void FUN_00dbb940_7() = 0;
    virtual void FUN_00dbb940_8() = 0;
    virtual hkDataClassImpl* FUN_00dbb940_9(char const* name) = 0;
};

}  // namespace fnv_00dbb940

// @fnv 0x00dbb940
hkDataClassImpl* hkDataClassNative::getParent() const
{
    hkClass* parent = reinterpret_cast<fnv_00dbb940::FUN_00d46d50_s*>(m_0C)->FUN_00d46d50();

    if (parent)
    {
        return reinterpret_cast<fnv_00dbb940::FUN_00dbb940_VirtualClass*>(m_10)->FUN_00dbb940_9(parent->getName());
    }
    else
    {
        return 0;
    }
}

// @fnv 0x00dbb9d0
int hkDataClassNative::getNumDeclaredMembers() const
{
    return m_0C->GetNumDeclaredMembers();
}

namespace fnv_00dbba80 {

struct FUN_00dbba80_Manager
{
    virtual void FUN_00dbba80_0() = 0;
    virtual void FUN_00dbba80_1() = 0;
    virtual void FUN_00dbba80_2() = 0;
    virtual void FUN_00dbba80_3() = 0;
    virtual void FUN_00dbba80_4() = 0;
    virtual void FUN_00dbba80_5() = 0;
    virtual void FUN_00dbba80_6() = 0;
    virtual void FUN_00dbba80_7() = 0;
    virtual void FUN_00dbba80_8() = 0;
    virtual hkClass* GetVariantValue(char const* name) = 0;
};

struct FUN_00dbba80_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    hkClass* m_10;
    FUN_00dbba80_Manager* m_14;

    hkClass* __thiscall GetNamedClass();
};

// If m_10 is set, looks up its name through m_14 and returns the resulting hkClass; otherwise returns 0.
// @fnv 0x00dbba80
hkClass* __thiscall FUN_00dbba80_Class::GetNamedClass()
{
    if (m_10)
        return m_14->GetVariantValue(m_10->getName());

    return 0;
}
}  // namespace fnv_00dbba80

namespace fnv_00dbbc20 {
// Slots 0..9 dispatch data-world class lookup; this is not an hkClass layout.
struct DataWorldClassLookup
{
    virtual int FUN_00dbbc20_1();
    virtual int FUN_00dbbc20_2();
    virtual int FUN_00dbbc20_3();
    virtual int FUN_00dbbc20_4();
    virtual int FUN_00dbbc20_5();
    virtual int FUN_00dbbc20_6();
    virtual int FUN_00dbbc20_7();
    virtual int FUN_00dbbc20_8();
    virtual int FUN_00dbbc20_9();
    virtual int FUN_00dbbc20_10(char const* name);

};

struct FUN_00dbbc20_Class : DataWorldClassLookup
{
    int m_04;
    int m_08;
    DataWorldClassLookup* m_0C;
    void* m_10;
    int m_14;
    int m_18;
    int m_1C;
    hkClass* m_20;

    int hkDataArrayNative_getClass();
};

// If m_20 is set, returns the result of calling FUN_00dbbc20_10 on m_0C with m_20's name; otherwise returns 0.
// @fnv 0x00dbbc20
// src: XBOX_PDB 0x00dbbc20
int FUN_00dbbc20_Class::hkDataArrayNative_getClass()
{
    if (m_20)
        return m_0C->FUN_00dbbc20_10(m_20->getName());

    return 0;
}
}  // namespace fnv_00dbbc20

// Reads the element at index from the array data pointer and returns it as an int, interpreting it according to the element type in m_18.
// @fnv 0x00dbbcf0
int hkDataArrayNative::GetElementAsInt(int index)
{
    int* p = (int*)(m_0C + m_14 * index);
    switch (m_18 - 1)
    {
    case 0:
        return *(signed char*)p;
    case 1:
        return *(signed char*)p;
    case 2:
        return *(signed char*)p;
    case 3:
        return *(unsigned char*)p;
    case 4:
        return *(signed short*)p;
    case 5:
        return *(unsigned short*)p;
    case 6:
        return *(int*)p;
    case 7:
        return *(int*)p;
    case 8:
        return *(int*)p;
    case 9:
        return *(int*)p;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
        return 0;
    case 29:
        return *(int*)p;
    default:
        return 0;
    }
}

// @fnv 0x00dbbd70
__int64 __thiscall hkDataArrayNative::GetEntry64(int aiIndex)
{
    return *reinterpret_cast<__int64*>(m_0C + m_14 * aiIndex);
}

// Retrieves the shape at index a from the container m_0c and passes it with b to GetMemberInfo.
// @fnv 0x00dbbfa0
void hkDataClassNative::getDeclaredMemberInfo(int a, hkDataClassMemberInfo& b) const
{
    GetMemberInfo(reinterpret_cast<const Shape*>(&m_0c->GetDeclaredMember(a)), b);
}

struct FUN_00d46f20_Class
{
    const Shape* __thiscall getMember(int i) const;
};

// @fnv 0x00dbbfd0
void hkDataClassNative::getMemberInfo(int aiArg1, hkDataClassMemberInfo& aiArg2) const
{
    GetMemberInfo(reinterpret_cast<FUN_00d46f20_Class*>(m_0c)->getMember(aiArg1), aiArg2);
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00dbc640_class
{
    int m_00;
    unsigned short m_04;

    void __thiscall FUN_00dbb3f0();

    FUN_00dbc640_class* __thiscall FUN_00dbc640(int flags);
};

FUN_00dbc640_class* FUN_00dbc640_class::FUN_00dbc640(int flags)
{
    this->FUN_00dbb3f0();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockFree(this, this->m_04);
    }

    return this;
}

struct FUN_00d47120_Class
{
    int __thiscall getDescribedVersion() const;
};

// @fnv 0x00dbb930
int hkDataClassNative::getVersion() const
{
    return reinterpret_cast<const FUN_00d47120_Class*>(m_0C)->getDescribedVersion();
}

struct FUN_00d47080_Class
{
    int __thiscall FindIndexByName(const char* name) const;
};

// @fnv 0x00dbb9e0
int hkDataClassNative::getDeclaredMemberIndexByName(const char* name) const
{
    return reinterpret_cast<FUN_00d47080_Class*>(m_0C)->FindIndexByName(name);
}

// @fnv 0x00dbb9f0
int hkDataClassNative::getNumMembers() const
{
    return reinterpret_cast<FUN_00d46f00_Class*>(m_0C)->FUN_00d46f00();
}

struct ClassMemberLookup
{
    int __thiscall FUN_00d47030(const char* name) const;
};

// @fnv 0x00dbba00
int hkDataClassNative::getMemberIndexByName(const char* param_1) const
{

    ClassMemberLookup* target = reinterpret_cast<ClassMemberLookup*>(m_0C);
    return target->FUN_00d47030(param_1);
}

// @fnv 0x00dbba40
// src: GUESS 0x00dbba40 (confidence: high)
__int64 __stdcall Object_ReturnZero_00dbba40(int)
{
    return 0;
}

// @fnv 0x00dc9520
// src: GUESS 0x00dc9520 (confidence: low)
int __stdcall Object_ComputeValue_00dc9520(unsigned int arg0)
{
    return (int)(arg0 + 1u);
}

// @fnv 0x00dbb120
// src: GUESS 0x00dbb120 (confidence: high)
int __stdcall Object_ReturnZero_00dbb120(int arg0)
{
    return 0;
}

// @fnv 0x00dbb130
// src: GUESS 0x00dbb130 (confidence: high)
int __stdcall Hkdataobjectnative_ReturnZero(int a, int b)
{
    return 0;
}

struct FUN_00d87790_Result
{
    unsigned char value;
};
struct FUN_00d87790_Obj
{
    void __thiscall FUN_00d87790(FUN_00d87790_Result);
};
struct FUN_00dbb360_Global
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual hkReferencedObject* vf10();
    virtual hkReferencedObject* vf14();
};
extern FUN_00dbb360_Global* DAT_01268b08;
extern int DAT_010d6518[];
struct FUN_00dbb360_Class
{
    int m_00;
    unsigned short m_04, m_06;
    hkReferencedObject* m_08;
    hkReferencedObject* m_0C;
    FUN_00d87790_Obj m_10;
    int m_14, m_18, m_1C, m_20, m_24;
    FUN_00dbb360_Class* __thiscall Initialize();
};
// Initializes the object's fields, resets m_10, and stores referenced objects obtained from DAT_01268b08's vf14 and vf10.
// @fnv 0x00dbb360
FUN_00dbb360_Class* __thiscall FUN_00dbb360_Class::Initialize()
{
    FUN_00d87790_Result result;
    m_06 = 1;
    result.value = 0;
    m_00 = (int)DAT_010d6518;
    *reinterpret_cast<hkReferencedObject* volatile*>(&m_08) = 0;
    *reinterpret_cast<hkReferencedObject* volatile*>(&m_0C) = 0;
    m_10.FUN_00d87790(result);
    m_24 = 0;
    m_20 = 0;
    hkReferencedObject* p = DAT_01268b08->vf14();
    if (p)
        p->addReference();
    if (m_0C)
        m_0C->removeReference();
    m_0C = p;
    p = DAT_01268b08->vf10();
    if (p)
        p->addReference();
    if (m_08)
        m_08->removeReference();
    m_08 = p;
    return this;
}

namespace hkRouterDBB5 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}

class hkRefObjDBB5
{
  public:
    virtual ~hkRefObjDBB5() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB5() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB5* b = static_cast<hkRefObjDBB5*>(GetRouterHeap<hkMemoryAllocator>(hkRouterDBB5::hkMemoryRouter_getInstance()).blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};


class hkStringFnDBB5
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};

struct hkNameDescDBB5
{
    const char* m_name;
    int m_len;
};

class hkLibDBB5;

// Native object reference state at 0x08; this is the 12-byte object-implementation base.
class NativeObjectReferenceBase : public hkRefObjDBB5
{
  public:
    int m_08;

    NativeObjectReferenceBase() throw() : m_08(0)
    {}
    virtual ~NativeObjectReferenceBase() throw();
};

class hkNodeDBB5 : public NativeObjectReferenceBase
{
  public:
    Pair m_name;
    hkLibDBB5* m_pOwnerObject;

    hkNodeDBB5() throw()
    {}
    virtual ~hkNodeDBB5() throw();
};

class hkNodeRefDBB5
{
  public:
    void hkDataObject_hkDataObject(hkNodeDBB5* node) throw();
    hkNodeDBB5* m_node;
};

class hkLibDBB5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB5* m_pStringFunctions;

    hkNodeRefDBB5 CreateNode(const hkNameDescDBB5& desc);
};

// @fnv 0x00dbb5a0
hkNodeRefDBB5 hkLibDBB5::CreateNode(const hkNameDescDBB5& aNameDesc)
{
    hkNodeDBB5* node = new hkNodeDBB5();
    int len = aNameDesc.m_len;
    if (!len)
        len = m_pStringFunctions->strLen(aNameDesc.m_name);
    node->m_name.Pair::Pair(reinterpret_cast<int>(aNameDesc.m_name), len);
    node->m_pOwnerObject = this;
    hkNodeRefDBB5 r;
    r.hkDataObject_hkDataObject(node);
    return r;
}

extern hkError* DAT_01268360;


// Class registry lookup uses slot 4; the data-world lookup uses slot 9.
class ClassRegistryDispatch
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};

// World state stores registry pointers at 0x08/0x0c and native contents at 0x20.
class NativeWorldContents
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    ClassRegistryDispatch* m_pkWorld;
    hkVtableClassRegistry* m_pkVtableRegistry;
    int m_aiUnk10[4];
    void* m_pvObject;
    void* m_pkClass;

    ClassRegistryDispatch* getWorld() const
    {
        return m_pkWorld;
    }
    void SetContents(void* pvObject, hkClass& kClass);
};

// Stores pvObject and resolves its class through the world/vtable registry, reporting an error and clearing pvObject if the class is not registered.
// @fnv 0x00dbb730
void NativeWorldContents::SetContents(void* pvObject, hkClass& kClass)
{
    m_pvObject = pvObject;
    void* pvClass;
    if (kClass.GetLastNodeFlag().m_cBooleanValue)
    {
        ClassRegistryDispatch* pkWorld = m_pkWorld;
        const hkClass* pkClass = m_pkVtableRegistry->GetClassFromVirtualInstance(pvObject);
        pvClass = !pkClass ? 0 : pkWorld->GetClassFromName(pkClass->getName());
    }
    else
        pvClass = getWorld()->GetClassFromName(kClass.getName());
    m_pkClass = pvClass;
    if (!m_pkClass)
    {
        unsigned int auiReportBuf[0x80];
        unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
        hkOstream& kReportStream = *reinterpret_cast<hkOstream*>(streamStorage);
        kReportStream.FUN_00cb1600(auiReportBuf, sizeof(auiReportBuf));
        kReportStream.ProcessAndReturnValue_00cc01c0("Cannot set contents with object at 0x")
            .operator<<(pvObject)
            .ProcessAndReturnValue_00cc01c0(". Class '")
            .ProcessAndReturnValue_00cc01c0(kClass.getName())
            .ProcessAndReturnValue_00cc01c0("' is not registered in the hkDataWorldNative. Ignore it.");
        DAT_01268360->message(1, 0x1800473b, (char*)auiReportBuf, ".\\Data\\Native\\hkDataObjectNative.cpp", 0x2fc);
        kReportStream.FUN_00cc00e0();
        m_pvObject = 0;
    }
}

int __cdecl hkString_strCmp(int, int);


// @fnv 0x00dbb970
hkBool hkDataClassNative::isSuperClass(const hkDataClassImpl* pkNode) const
{
    while (pkNode)
    {
        if (hkString_strCmp((int)pkNode->getName(), (int)getName()) == 0)
            return true;
        pkNode = pkNode->getParent();
    }
    return false;
}

// @fnv 0x00dbba20
hkHalf __stdcall MakeZeroHalf(int a)
{
    return hkHalf(0.0f);
}

struct FUN_00d871a0_Data
{
    int memberData;
    int key;
    void ProcessAndReturnValue_00d871a0(void* value, int argument);
    const char* ComputeValue_00d871e0(const int* argument);
};
struct FUN_00dbbae0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int hkDataObjectNative_hasMember(int argument);
};
// @fnv 0x00dbbae0
// src: XBOX_PDB 0x00dbbae0
int FUN_00dbbae0_Class::hkDataObjectNative_hasMember(int iKey)
{
    FUN_00d871a0_Data lookup;
    lookup.ProcessAndReturnValue_00d871a0(&unk0C, iKey);
    return *lookup.ComputeValue_00d871e0(&iKey) != 0;
}

class hkOwnerDBBB;

struct hkRefDBBB
{
    hkOwnerDBBB* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDBBB(hkOwnerDBBB* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};

class hkOwnerDBBB
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8(int iKey);

    hkRefDBBB MakeRef(int iKey);
};

// Constructs and returns an hkRefDBBB holding this owner and the value from V8(iKey).
// @fnv 0x00dbbb40
hkRefDBBB hkOwnerDBBB::MakeRef(int iKey)
{
    return hkRefDBBB(this, V8(iKey));
}

// Reads a value at m_0C + m_14*index, as float when m_18==11, as sign-extended short shifted left 16 when m_18==32, else 0.0f.
// @fnv 0x00dbbca0
// src: XBOX_PDB 0x00dbbca0
float hkDataArrayNative::asReal(int index)
{
    volatile float& fValue = *reinterpret_cast<volatile float*>(&index);
    if (m_18 != 11)
    {
        if (m_18 != 32)
        {
            fValue = 0.0f;
            return fValue;
        }
        index = int(*reinterpret_cast<short*>(m_0C + m_14 * index)) << 16;
        return fValue;
    }
    fValue = *reinterpret_cast<float*>(m_0C + m_14 * index);
    return fValue;
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

struct hkClassMemberTypeDBBD
{
    int unk00;
    int unk04;
    short m_iElementCount;
};

hkClassMemberTypeDBBD* __cdecl hkClassMember_getClassMemberTypeProperties(int iType);

struct hkArrayBaseDBBD
{
    void* m_data;
    int m_iElementCount;
};

// Keep allocation inline so callers store the Havok allocation size before construction.
inline void* hkDataArrayNative::operator new(unsigned int nbytes)
{
    void* memory = GetRouterHeap<hkMemoryAllocator>(hkMemoryRouter_getInstance()).blockAlloc(nbytes);
    reinterpret_cast<unsigned short*>(memory)[2] = static_cast<unsigned short>(nbytes);
    return memory;
}

// @fnv 0x00dbbd90
hkDataArrayNative* hkDataArrayNative::GetElement(int iIndex)
{
    const int& tupleCount = m_28;
    void* pvAddr = reinterpret_cast<char*>(m_0C) + m_14 * iIndex;
    if (tupleCount)
    {
        int iStride = hkClassMember_getClassMemberTypeProperties(m_18)->m_iElementCount;
        return new hkDataArrayNative(m_08, pvAddr, tupleCount, iStride, m_18, m_1c, 0);
    }
    hkArrayBaseDBBD* pkArray = static_cast<hkArrayBaseDBBD*>(pvAddr);
    return new hkDataArrayNative(m_08, pkArray->m_data, pkArray->m_iElementCount, 0, 0, 0, 0);
}

struct FUN_00d46f20_Map
{
    int* getMember(int iKey);
};

struct FUN_00dbbe30_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00d46f20_Map* m_map;

    int GetValueForKey(int iKey);
};

// @fnv 0x00dbbe30
int FUN_00dbbe30_cls::GetValueForKey(int iKey)
{
    return *m_map->getMember(iKey);
}

namespace fnv_00dbbe50 {
class hkBaseDBBE
{
  public:
    virtual ~hkBaseDBBE() throw()
    {}
};

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();

class hkObjdbbe50 : public hkBaseDBBE
{
  public:
    hkObjdbbe50* FUN_00dbbe50(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        GetRouterHeap<hkMemoryAllocator>(hkMemoryRouter_getInstance()).blockFree(p, static_cast<hkObjdbbe50*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Destroys the base object and, when bit 0 of uiFlags is set, frees this object through the heap allocator.
// @fnv 0x00dbbe50
hkObjdbbe50* hkObjdbbe50::FUN_00dbbe50(unsigned int uiFlags) throw()
{
    this->hkBaseDBBE::~hkBaseDBBE();
    if (uiFlags & 1)
        hkObjdbbe50::operator delete(this);
    return this;
}
}  // namespace fnv_00dbbe50


namespace fnv_00dbbe80 {
struct hkDataWorld
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};

struct FUN_00d871a0
{
    void* m_object;
    const void* m_pObjectTypeInfo;
    FUN_00d871a0(void* pvObject, const char* pcMember) throw();
    const char** hkClassMemberAccessor_asCstring(int iIndex) throw();
};

}  // namespace fnv_00dbbe80

struct hkMemberInfo
{
    const char* m_name;
    const void* m_pOwnerObject;
    int m_type;
    void* m_valueClass;
    int m_arrayCount;
};

namespace fnv_00dbbe80 {
extern const char* DAT_011b7958;
int __cdecl GetShapeTypeFlags(int iType, int iSubType, const hkClass* pkClass, int iCount) throw();

}  // namespace fnv_00dbbe80

// Fills kInfo from kMember: copies the name, sets the owner, and resolves type, value class and array count, using the world to look up the class name.
// @fnv 0x00dbbe80
void hkDataClassNative::GetMemberInfo(const hkClassMember& kMember, hkMemberInfo& kInfo) const throw()
{
    using namespace fnv_00dbbe80;
    kInfo.m_name = kMember.m_name;
    kInfo.m_pOwnerObject = this;
    if (kMember.flagsAllAreSet(0x400))
    {
        kInfo.m_type = 0;
        kInfo.m_valueClass = 0;
        kInfo.m_arrayCount = 0;
        return;
    }
    int iSubType = kMember.m_eSubtype;
    int iType = kMember.m_type;
    kInfo.m_type = GetShapeTypeFlags(iType, iSubType, kMember.getClass(), kMember.getCstyleArraySize());
    if (kMember.getClass())
    {
        void* pvAttr = const_cast<hkVariant*>(kMember.getAttribute_00d86960(DAT_011b7958));
        if (pvAttr)
        {
            FUN_00d871a0 kAccess(pvAttr, "typeName");
            kInfo.m_valueClass = reinterpret_cast<fnv_00dbbe80::hkDataWorld*>(m_pOwningWorld)->GetClassFromName(*kAccess.hkClassMemberAccessor_asCstring(0));
        }
        else
        {
            kInfo.m_valueClass = reinterpret_cast<fnv_00dbbe80::hkDataWorld*>(m_pOwningWorld)->GetClassFromName(kMember.getClass()->getName());
        }
    }
    else
    {
        kInfo.m_valueClass = 0;
    }
    kInfo.m_arrayCount = kMember.getCstyleArraySize();
}

// The accessors at 0x00d871a0..0x00d87370 operate on object/member pairs.
class hkClassMemberAccessor
{
  public:
    void* m_pTargetObject;
    const hkClassMember* m_kMemberDescriptor;

    hkClassMemberAccessor(void* obj, void* name) throw()
    {
        ProcessAndReturnValue_00d871a0(obj, name);
    }
    void ProcessAndReturnValue_00d871a0(void* obj, void* name) throw();
    hkClassMember* hkClassMemberAccessor_getClassMember() throw();
    unsigned int* hkClassMemberAccessor_asCstring(int i) throw();
    unsigned int* hkClassMemberAccessor_asStringPtr(int i) throw();

    void ProcessAndReturnValue_00d871a0(hkVariant& kObject, const hkClassMember* pkMember) throw();
    hkClassMemberAccessor(hkVariant& kObject, const hkClassMember* pkMember)
    {
        ProcessAndReturnValue_00d871a0(kObject, pkMember);
    }

    const hkClassMember& hkClassMemberAccessor_getClassMember() const throw();
    signed char& ComputeValue_00d872e0(int iIndex) throw();
    unsigned char& GetFilterValueWithOffset(int iIndex) throw();
    short& Object_ComputeValue_00d872c0(int iIndex) throw();
    unsigned short& GetElementPointer2(int iIndex) throw();
    int& GetElementPointer_00d87270(int iIndex) throw();
    unsigned int& ComputeValue_00d87280(int iIndex) throw();
    __int64& Hkclassmemberaccessor_GetElementPointer8(int iIndex) throw();
    unsigned __int64& ComputeValue_00d872a0(int iIndex) throw();
    unsigned long& GetElementPointer_00d872b0(int iIndex) throw();
};

class hkObjDBC3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    char m_data[4];

    unsigned int GetMemberValue(void* name);
};

// Builds an hkClassMemberAccessor from m_data and name, then returns the member's pointer value or its flags value with bit 0 cleared, or 0 for other types.
// @fnv 0x00dbc310
unsigned int hkObjDBC3::GetMemberValue(void* name)
{
    hkClassMemberAccessor v(m_data, name);
    switch (v.hkClassMemberAccessor_getClassMember()->getType())
    {
    case hkClassMember::TYPE_CSTRING:
        return *v.hkClassMemberAccessor_asCstring(0);
    case hkClassMember::TYPE_STRINGPTR:
        return *v.hkClassMemberAccessor_asStringPtr(0) & ~1u;
    }
    return 0;
}



class hkDataObjectNative
{
  public:
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    hkVariant m_object;

    __int64 GetMemberValueAsInt64(const hkClassMember* pkHandle) throw();
};

// @fnv 0x00dbc370
__int64 hkDataObjectNative::GetMemberValueAsInt64(const hkClassMember* pkHandle) throw()
{
    hkClassMemberAccessor kAccessor(m_object, pkHandle);
    const hkClassMember& kMember = static_cast<const hkClassMemberAccessor&>(kAccessor).hkClassMemberAccessor_getClassMember();
    hkClassMember::Type eType = kMember.getType();
    while (1)
    {
        switch (eType)
        {
        case hkClassMember::TYPE_BOOL:
        case hkClassMember::TYPE_CHAR:
        case hkClassMember::TYPE_INT8:
            return kAccessor.ComputeValue_00d872e0(0);
        case hkClassMember::TYPE_UINT8:
            return kAccessor.GetFilterValueWithOffset(0);
        case hkClassMember::TYPE_INT16:
            return kAccessor.Object_ComputeValue_00d872c0(0);
        case hkClassMember::TYPE_UINT16:
            return kAccessor.GetElementPointer2(0);
        case hkClassMember::TYPE_INT32:
            return kAccessor.GetElementPointer_00d87270(0);
        case hkClassMember::TYPE_UINT32:
            return kAccessor.ComputeValue_00d87280(0);
        case hkClassMember::TYPE_INT64:
            return kAccessor.Hkclassmemberaccessor_GetElementPointer8(0);
        case hkClassMember::TYPE_UINT64:
            return kAccessor.ComputeValue_00d872a0(0);
        case hkClassMember::TYPE_ULONG:
            return kAccessor.GetElementPointer_00d872b0(0);
        case hkClassMember::TYPE_ENUM:
        case hkClassMember::TYPE_FLAGS:
            eType = static_cast<hkClassMember::Type>(kMember.m_eSubtype);
            break;
        default:
            return 0;
        }
    }
}

struct FUN_00dba490_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;

    void FreeArrayStorageAndReset();
};

// Gets a heap, conditionally frees m_0C using a size derived from m_14, then resets m_0C and m_14.
// @fnv 0x00dba490
// src: GUESS 0x00dba490 (confidence: medium)
void FUN_00dba490_class::FreeArrayStorageAndReset()
{
    hkMemoryRouter* result = _D1A0E0GetMemoryRouter();
    hkMemoryAllocator* heap = reinterpret_cast<hkMemoryAllocator*>(result->m_heap);
    int value = m_14;
    m_10 = 0;
    if ((value & 0x80000000) == 0)
    {
        heap->bufFree((void*)m_0C, (value & 0x3fffffff) * 16);
    }
    m_0C = 0;
    m_14 = (int)0x80000000;
}

namespace hkRouterDBB6 {
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}




class hkStringFnDBB6
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};

struct hkNameDescDBB6
{
    const char* m_name;
    int m_len;
};

class hkLibDBB6;



class hkNodeDBB6 : public NativeObjectReferenceBase
{
  public:
    Pair m_name;
    hkLibDBB6* m_pOwnerObject;

    hkNodeDBB6() throw()
    {}
    virtual ~hkNodeDBB6() throw();
};

class hkNodeRefDBB6
{
  public:
    void hkDataObject_hkDataObject(hkNodeDBB6* node) throw();
    hkNodeDBB6* m_node;
};

class hkLibDBB6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB6* m_pStringFunctions;

    int unk10[4];
    Pair m_name;

    hkNodeRefDBB6 hkDataWorldNative_getContents();
};

// Allocates a new hkNodeDBB6, copies m_name into it, sets m_pOwnerObject to this, and returns it wrapped in an hkNodeRefDBB6.
// @fnv 0x00dbb620
// src: HAVOK_SRC 0x00dbb620
hkNodeRefDBB6 hkLibDBB6::hkDataWorldNative_getContents()
{
    hkNodeDBB6* node = new hkNodeDBB6();
    node->m_name.Imath_Vec2_int_Vec2_int(m_name);
    node->m_pOwnerObject = this;
    hkNodeRefDBB6 r;
    r.hkDataObject_hkDataObject(node);
    return r;
}

// Returns 0.0f.
// @fnv 0x00dbba10
// src: GUESS 0x00dbba10 (confidence: high)
float __stdcall Hkdataobjectnative_ReturnZero_00dbba10(void* pArg)
{
    return 0.0f;
}

struct FUN_00d470f0_Obj
{
    unsigned char* __thiscall GetLastNodeFlag(unsigned char* flag);
};

struct FUN_00dbba50_Obj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    FUN_00d470f0_Obj* m_10;

    hkVariant* __thiscall GetHandle(hkVariant* __restrict handle);
};

// @fnv 0x00dbba50
hkVariant* FUN_00dbba50_Obj::GetHandle(hkVariant* __restrict handle)
{
    int first = m_0C;
    unsigned char flag;
    handle->m_object = (void*)first;
    FUN_00d470f0_Obj* reg = m_10;
    unsigned char* text = reg->GetLastNodeFlag(&flag);
    handle->m_class = reinterpret_cast<const hkClass*>(((*text != 0) - 1) & (int)(unsigned int)reg);
    return handle;
}

struct FUN_00d871a0
{
    int m_00;
    int m_04;
    FUN_00d871a0(void* pair, int x);
    void* hkClassMemberAccessor_getAddress();
};

struct FUN_00dbbb60_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void* __thiscall hkDataObjectNative_asVec(int a, int b);
};

// Constructs a FUN_00d871a0 with m_0c and a, then returns the result of FUN_00d87200.
// @fnv 0x00dbbb60
// src: XBOX_PDB 0x00dbbb60
void* FUN_00dbbb60_cls::hkDataObjectNative_asVec(int a, int aiUnused)
{
    FUN_00d871a0 t(&this->m_0c, a);
    return t.hkClassMemberAccessor_getAddress();
}

struct StreamDBC5C0;
struct AccessorDBC5C0
{
    AccessorDBC5C0(StreamDBC5C0* pkStream, int iIndex);
    const hkClassMember* GetDesc();
    const float* hkClassMemberAccessor_asReal(int iComponent);
    const short* hkClassMemberAccessor_asHalf(int iComponent);
    int m_iA;
    int m_iB;
};
struct StreamDBC5C0
{
    int unk00;
};
struct VertexDataDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    StreamDBC5C0 m_kVertexStream;
    float GetFloat(int iIndex);
};

// Reads component 0 at iIndex as float bits for types 0xb or 0x20; returns 0.0f otherwise.
// @fnv 0x00dbc5c0
float VertexDataDBC5C0::GetFloat(int iIndex)
{
    AccessorDBC5C0 kAccessor(&m_kVertexStream, iIndex);
    union
    {
        float f;
        int i;
    } uValue;
    int iType = kAccessor.GetDesc()->m_type;
    switch (iType)
    {
    case 0xb:
        uValue.f = *kAccessor.hkClassMemberAccessor_asReal(0);
        break;
    case 0x20:
        uValue.i = *kAccessor.hkClassMemberAccessor_asHalf(0) << 16;
        break;
    default:
        uValue.f = 0.0f;
        break;
    }
    return uValue.f;
}

extern "C" int __cdecl Vsnprintf(char* pcBuffer, unsigned int uSize, const char* pcFormat, ...);
extern const char str_010a5824[];
extern "C" int __cdecl hkString_strLen(const char* s);
// This helper dispatches slot 0; hkStreamWriter::write is at slot 4.
struct TextWriteDispatch
{
    virtual void write(const char* s, int len) throw();
};
// src: HAVOK_LIB 0x00cc0080
static __declspec(noinline) void writeString(TextWriteDispatch* pkWriter, const char* pcString)
{
    if (pcString == 0)
        pkWriter->write("(null)", 6);
    else
        pkWriter->write(pcString, hkString_strLen(pcString));
}
// @fnv 0x00cc0120
hkOstream& hkOstream::operator<<(const void* pvPointer)
{
    int buffer[2506];
    Vsnprintf((char*)buffer, 0x2728u, str_010a5824, pvPointer);
    writeString(reinterpret_cast<TextWriteDispatch*>(m_pStreamWriter), (const char*)buffer);
    return *this;
}

void DbbExtern(void*);

struct DbbOwner
{
    int unk00;
    int unk04;
    void __thiscall SetNativeDataObjectFromPair(int a, int b);
};

// src: XBOX_PDB 0x00dbb260
static __declspec(noinline) void hkNativeDataObjectImplCreate(Pair* p, DbbOwner* self)
{
    for (int i = 0; i < self->unk00; i++)
    {
        DbbExtern(self);
        p->a += self->unk04 + i;
        p->b -= i;
    }
}

// Stores the two input integers into a Pair and passes it to FUN_00dbb260 for in-place modification.
// @fnv 0x00dbb4f0
// src: GUESS 0x00dbb4f0 (confidence: medium)
void DbbOwner::SetNativeDataObjectFromPair(int aiFirst, int aiSecond)
{
    Pair p;
    p.a = aiFirst;
    p.b = aiSecond;
    hkNativeDataObjectImplCreate(&p, this);
}

struct Input680
{
    void* hkDataClass_getName();
};
struct Size680
{
    int FUN_00d470d0();
};
struct Dispatch680
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void RunFourthVirtual();
    virtual void* v4(void* a);
    virtual void q5();
    virtual void RunSeventhVirtualOperation();
    virtual void* v7(void* a);
    virtual void q8();
    virtual void* q9(const char* s);
};
struct Manager680
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual Dispatch680* RunFourthVirtual();
};
typedef void(__cdecl* Callback680)(void*, int);
struct CallbackEntry680
{
    void* object;
    Callback680 callback;
};
struct Resolved680
{
    int unk00;
    int unk04;
    int unk08;
    hkClass* descriptor;
};
struct Node680
{
    void* vtable;
    unsigned short size;
    unsigned short refs;
    int unk08;
    Pair name;
    Dispatch680* owner;
};
extern const char DAT_010d64bc[], DAT_010d64d0[], DAT_010d64dc[], DAT_010d6394[];
extern int DAT_010d6334;
extern "C" void hkString_memSet(void*, int, int);

// src: XBOX_PDB 0x00dbb260
static __declspec(noinline) Node680* hkNativeDataObjectImplCreate(Pair* p, Dispatch680* o)
{
    if (p->b)
    {
        Resolved680* r = (Resolved680*)o->q9(reinterpret_cast<hkClass*>(p->b)->getName());
        if (r)
        {
            p->b = reinterpret_cast<int>(r->descriptor);
        }
        else
        {
            char buffer[512];
            unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
            hkOstream& stream = *reinterpret_cast<hkOstream*>(streamStorage);
            stream.FUN_00cb1600(buffer, 512);
            stream.ProcessAndReturnValue_00cc01c0(DAT_010d64bc)
                .operator<<(reinterpret_cast<void*>(p->a))
                .ProcessAndReturnValue_00cc01c0(DAT_010d64d0)
                .ProcessAndReturnValue_00cc01c0(reinterpret_cast<hkClass*>(p->b)->getName())
                .ProcessAndReturnValue_00cc01c0(DAT_010d64dc);
            DAT_01268360->message(1, 0x1800473a, buffer, DAT_010d6394, 0x2c7);
            stream.FUN_00cc00e0();
            p->a = 0;
            p->b = 0;
        }
    }
    Node680* e = (Node680*)GetRouterHeap<hkMemoryAllocator>(hkRouterDBB6::hkMemoryRouter_getInstance()).blockAlloc(24);
    e->refs = 0;
    e->unk08 = 0;
    e->size = 24;
    e->vtable = &DAT_010d6334;
    e->name.Imath_Vec2_int_Vec2_int(*p);
    e->owner = o;
    return e;
}
struct Owner680
{
    int unk00;
    int unk04;
    Dispatch680* dispatch;
    void hkDataWorldNative_newObject(Input680* input);
};
struct RawDispatch680;
typedef void*(__thiscall* DispatchFn680)(RawDispatch680*, void*);
struct DispatchTable680
{
    DispatchFn680 q0, q1, q2, RunFourthVirtual, v4, q5, RunSeventhVirtualOperation, v7;
};
struct RawDispatch680
{
    DispatchTable680* table;
};
// Allocates a block using the first dispatch result's size, invokes an available callback, then passes the block and second result to FUN_00dbb260.
// @fnv 0x00dbb680
// src: HAVOK_SRC 0x00dbb680
void Owner680::hkDataWorldNative_newObject(Input680* input)
{
    RawDispatch680* pRawDispatch = (RawDispatch680*)dispatch;
    Pair p;
    DispatchFn680* firstSlot = &pRawDispatch->table->v4;
    void* r2 = (*firstSlot)(pRawDispatch, input->hkDataClass_getName());
    int size = ((Size680*)r2)->FUN_00d470d0();
    p.a = reinterpret_cast<int>(GetRouterHeap<hkMemoryAllocator>(hkRouterDBB6::hkMemoryRouter_getInstance()).blockAlloc(size));
    p.b = reinterpret_cast<int>(r2);
    if (p.a)
    {
        hkString_memSet(reinterpret_cast<void*>(p.a), 0, ((Size680*)r2)->FUN_00d470d0());
        RawDispatch680* d = (RawDispatch680*)((Manager680*)DAT_01268b08)->RunFourthVirtual();
        DispatchFn680* secondSlot = &d->table->v7;
        CallbackEntry680* pCallbackEntry = (CallbackEntry680*)(*secondSlot)(d, input->hkDataClass_getName());
        if (pCallbackEntry && pCallbackEntry->callback)
            pCallbackEntry->callback(reinterpret_cast<void*>(p.a), 0);
    }
    hkNativeDataObjectImplCreate(&p, (Dispatch680*)this);
}

void __cdecl ResizeAudioStream(void* allocator, void* array, int elemSize) throw();
void* __fastcall FUN_00d47280(void* item) throw();

template <typename T> __forceinline void constructWithCopyRange(T* p, int n, const T& t) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}


#include "../../../../../../include/hkArray.h"
// ~hkArray (clearAndDeallocate) through the memory router's heap, as this unit spells it.
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
    void* alloc = router->m_heap;
    int cap = this->m_iCapacityState;
    this->m_iElementCount = 0;
    if ((cap & int(0x80000000)) == 0)
    {
        ((hkMemoryAllocator*)alloc)->bufFree(this->m_data, (cap & 0x3FFFFFFF) * sizeof(T));
    }
}
// hkArray::pushBack as this unit spells it: the router is fetched first, its heap read only when the array grows.
template <typename T> static __forceinline void pushBackRouterHeap(hkArray<T>& a, const T& item) throw()
{
    hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
    if (a.m_iElementCount == (a.m_iCapacityState & 0x3FFFFFFF))
    {
        ResizeAudioStream(router->m_heap, &a, sizeof(T));
    }
    constructWithCopyRange(a.m_data + a.m_iElementCount, 1, item);
    a.m_iElementCount++;
}

struct TargetClass
{
    virtual void t0() throw();
    virtual void t1() throw();
    virtual void t2() throw();
    virtual void t3() throw();
    virtual void t4() throw();
    virtual void getDeclaredMembers(hkArray<hkClass*>* out) throw();
};

struct FUN_00dbb840_class
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void v8() throw();
    virtual hkClass* getMemberHandle(const char* name) throw();

    int unk04;
    TargetClass* m_class;

    void hkDataWorldNative_findAllClasses(hkArray<hkClass*>& out) throw();
};

// @fnv 0x00dbb840
// src: HAVOK_SRC 0x00dbb840
void FUN_00dbb840_class::hkDataWorldNative_findAllClasses(hkArray<hkClass*>& out) throw()
{
    int i = 0;
    TargetClass* cls = this->m_class;
    if (!cls)
        return;
    hkArray<hkClass*> declaredMembers;
    cls->getDeclaredMembers(&declaredMembers);
    for (; i < declaredMembers.getSize(); ++i)
    {
        if (*(char*)FUN_00d47280(declaredMembers[i]) & 1)
        {
            continue;
        }
        hkClass* handle = this->getMemberHandle(declaredMembers[i]->getName());
        pushBackRouterHeap(out, handle);
    }
}

struct ClassDBC0
{
    const hkClassMember* FUN_00d46fe0(int index);
};
// Looks up a member by index, computes a type code, and constructs a new hkDataArrayNative from selected fields.
// @fnv 0x00dbc0c0
// src: XBOX_PDB 0x00dbc0c0
hkDataArrayNative* hkDataArrayNative::swizzleObjectMember(int index)
{
    const hkClassMember* member = reinterpret_cast<ClassDBC0*>(m_1c)->FUN_00d46fe0(index);
    char* data = reinterpret_cast<char*>(m_0C) + member->m_offset;
    unsigned char type = member->m_type;
    index = type == 0x18 || type == 0x1f ? (int)member->m_eSubtype : (int)type;
    return new hkDataArrayNative(m_08, data, m_10, m_14, index, reinterpret_cast<int>(member->getClass()),
                            member->getCstyleArraySize());
}

struct S00dbc150_ClassDef
{
    int FUN_00d470d0();
};


struct S00dbc150_Pair
{
    void* m_data;
    const hkClassMember* m_kMemberDescriptor;

    S00dbc150_Pair(void* obj, const char* name)
    {
        ProcessAndReturnValue_00d871a0(obj, name);
    }
    void ProcessAndReturnValue_00d871a0(void* obj, const char* name);
    void* hkClassMemberAccessor_getAddress();
    const hkClassMember* hkClassMemberAccessor_getClassMember();
};

struct S00dbc150_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_14;

    hkDataArrayNative* hkDataObjectNative_asArray(const char* name);
};

// Resolves a named member on this object, determines its type, tuple size, and class, and returns a new hkDataArrayNative descriptor.
// @fnv 0x00dbc150
// src: XBOX_PDB 0x00dbc150
hkDataArrayNative* S00dbc150_Obj::hkDataObjectNative_asArray(const char* name)
{
    S00dbc150_Pair pair(&this->unk0c, name);
    const hkClassMember* member = pair.hkClassMemberAccessor_getClassMember();
    hkArrayBaseDBBD out;
    int tupleSize;
    int subType;
    S00dbc150_ClassDef* classDef;

    switch (member->m_type)
    {
    case 27: {
        hkHomogeneousArray* pArray = (hkHomogeneousArray*)pair.hkClassMemberAccessor_getAddress();
        out.m_data = pArray->m_data;
        out.m_iElementCount = pArray->m_iElementCount;
        S00dbc150_ClassDef* cls = reinterpret_cast<S00dbc150_ClassDef*>(const_cast<hkClass*>(((hkHomogeneousArray*)pair.hkClassMemberAccessor_getAddress())->m_class));
        classDef = cls;
        if (cls)
        {
            tupleSize = cls->FUN_00d470d0();
            subType = 25;
        }
        else
        {
            tupleSize = 0;
            goto ZERO_SUBTYPE;
        }
        break;
    }
    case 22:
    case 26: {
        hkArrayBaseDBBD* pArray = (hkArrayBaseDBBD*)pair.hkClassMemberAccessor_getAddress();
        out.m_data = pArray->m_data;
        out.m_iElementCount = pArray->m_iElementCount;
        S00dbc150_ClassDef* cls = reinterpret_cast<S00dbc150_ClassDef*>(const_cast<hkClass*>(member->getClass()));
        classDef = cls;
        subType = member->m_eSubtype;
        hkClassMemberTypeDBBD* pTypeInfo = hkClassMember_getClassMemberTypeProperties(subType);
        tupleSize = pTypeInfo->m_iElementCount;
        if (!subType)
        {
            return new hkDataArrayNative(this->m_14, 0, 0, 0, 0, 0, 0);
        }
        if (tupleSize == -1)
        {
            tupleSize = cls->FUN_00d470d0();
        }
        break;
    }
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
    case 18:
    case 20:
    case 25:
    case 30:
    case 32: {
        out.m_data = pair.hkClassMemberAccessor_getAddress();
        int c = pair.hkClassMemberAccessor_getClassMember()->getCstyleArraySize();
        subType = member->m_type;
        out.m_iElementCount = c;
        S00dbc150_ClassDef* cls = reinterpret_cast<S00dbc150_ClassDef*>(const_cast<hkClass*>(member->getClass()));
        classDef = cls;
        if (subType == 25)
        {
            tupleSize = cls->FUN_00d470d0();
        }
        else
        {
            tupleSize = hkClassMember_getClassMemberTypeProperties(subType)->m_iElementCount;
        }
        break;
    }
    default:
        out.m_data = 0;
        out.m_iElementCount = 0;
        classDef = 0;
        tupleSize = 0;
    ZERO_SUBTYPE:
        subType = 0;
        break;
    }

    return new hkDataArrayNative(this->m_14, out.m_data, out.m_iElementCount, tupleSize, subType, (int)classDef, 0);
}

int __cdecl GetShapeTypeFlags(int a, int b, int c, int d);

// @fnv 0x00dbbb90
hkDataArrayNative::hkDataArrayNative(int ai0c, void* ai10, int ai14, int ai18, int ai1c, int ai20, int ai28) throw()
{
    reinterpret_cast<short*>(this)[3] = 0;
    m_04 = 0;
    m_08 = ai0c;
    m_0C = reinterpret_cast<int>(ai10);
    m_10 = ai14;
    m_14 = ai18;
    m_18 = ai1c;
    m_1c = ai20;
    m_28 = ai28;
    int r = GetShapeTypeFlags(0x16, ai1c, ai20, ai28);
    m_24 = (r > 0x10) ? (r - 0x10) : 0x10;
}

extern "C" void _ReadWriteBarrier();
struct VariantC4D0
{
    int m_00;
    int m_04;
    void ProcessAndReturnValue_00d871a0(void* obj, int name);
    int* hkClassMemberAccessor_getClassMember();
    int* hkClassMemberAccessor_asVariant(int a);
    void* hkClassMemberAccessor_getAddress();
    char* hkClassMemberAccessor_asPointer(int a);
};
extern "C" int dummy_call(int a);
// src: XBOX_PDB 0x00dbb140
static __declspec(noinline) __int64 getVariantWithMostDerivedClass(int x, int* obj, int y, int z)
{
    int* a[3];
    a[0] = &x;
    a[1] = &y;
    a[2] = &z;
    int g1 = *a[1];
    int t1 = dummy_call(g1);
    g1 = g1 + t1;
    int g2 = *a[2];
    int t2 = dummy_call(g2);
    g2 = g2 + t2;
    if (!obj)
        return *a[0];
    return *a[0] + *obj + g1 + g2;
}
struct TailC4D0
{
    int hkNativeDataObjectImplCreate();
};
static __declspec(noinline) void CopyPair(Pair& value, const Pair& other)
{
    value.a = other.a;
    value.b = other.b;
}

struct NativeC4D0
{
    int m_00, m_04, m_08;
    Pair value;
    int* world;
};
struct FoundClassC4D0
{
    int m_00, m_04, m_08;
    int classValue;
};
struct WorldC4D0
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual FoundClassC4D0* GetClassFromName(const char* name);
};
extern NativeC4D0* allocateNativeC4D0();
extern void warnNativeC4D0(int, int);
// src: XBOX_PDB 0x00dbb260
static __declspec(noinline) int hkNativeDataObjectImplCreate(Pair* r, int* blk)
{
    if (r->b)
    {
        FoundClassC4D0* c = ((WorldC4D0*)blk)->GetClassFromName(((hkClass*)r->b)->getName());
        if (c)
            r->b = c->classValue;
        else
        {
            warnNativeC4D0(r->a, r->b);
            r->a = 0;
            r->b = 0;
        }
    }
    NativeC4D0* p = allocateNativeC4D0();
    p->m_00 = 0;
    p->m_04 = 0;
    p->m_08 = 0;
    CopyPair(p->value, *r);
    p->world = blk;
    return (int)p;
}
struct FUN_00dbc4d0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int* m_14;

    int __thiscall hkDataObjectNative_asObject(int name);
};
// Looks up a member by name, extracts its value based on type, and returns a native object via FUN_00dbb260.
// @fnv 0x00dbc4d0
// src: XBOX_PDB 0x00dbc4d0
int FUN_00dbc4d0_Class::hkDataObjectNative_asObject(int name)
{
    const hkClassMember* member;
    VariantC4D0 v;
    v.ProcessAndReturnValue_00d871a0(&m_0C, name);
    member = (const hkClassMember*)v.hkClassMemberAccessor_getClassMember();
    Pair result;
    result.a = 0;
    result.b = 0;
    _ReadWriteBarrier();
    int type = member->m_type;
    switch (type)
    {
    case 0x14: {
        int b2 = m_14[2];
        int b3 = m_14[3];
        unsigned __int64 r = getVariantWithMostDerivedClass(reinterpret_cast<int>(member->getClass()), *(int**)v.hkClassMemberAccessor_asPointer(0), b3, b2);
        result.a = (int)r;
        result.b = (int)(r >> 32);
        break;
    }
    case 0x19: {
        int b2 = m_14[2];
        int b3 = m_14[3];
        unsigned __int64 r = getVariantWithMostDerivedClass(reinterpret_cast<int>(member->getClass()), (int*)v.hkClassMemberAccessor_getAddress(), b3, b2);
        result.a = (int)r;
        result.b = (int)(r >> 32);
        break;
    }
    case 0x1c: {
        int* p = v.hkClassMemberAccessor_asVariant(0);
        result.a = p[0];
        _ReadWriteBarrier();
        result.b = p[1];
        break;
    }
    default:
        return 0;
    }
    if (result.a != 0 && result.b != 0)
    {
        return hkNativeDataObjectImplCreate(&result, m_14);
    }
    return 0;
}

hkClass* volatile inputClass;
hkVtableClassRegistry* volatile inputRegistry;
ClassRegistryDispatch* volatile inputWorld;
void* volatile inputObject;
void* volatile outputObject;
void* volatile outputClass;
extern hkError* DAT_01268360;

static __forceinline void* CreateDataObjectFromNativeInstance(void* object, hkVtableClassRegistry* registry,
                                                              ClassRegistryDispatch* world)
{
    void* pClassInfo = const_cast<hkClass*>(registry->GetClassFromVirtualInstance(object));
    if (pClassInfo)
    {
        pClassInfo = world->GetClassFromName(((hkClass*)pClassInfo)->getName());
    }
    return pClassInfo;
}

// Creates a hkVariant, using the resolved class for virtual classes and the given class otherwise.
// @fnv 0x00dbb140
// src: XBOX_PDB 0x00dbb140
static __declspec(noinline) hkVariant
    getVariantWithMostDerivedClass(unsigned int akClass, void* object, hkVtableClassRegistry* registry, ClassRegistryDispatch* world)
{
    hkClass* pClass = (hkClass*)akClass;
    hkVariant result = {0, 0};
    if (pClass && object)
    {
        if (pClass->GetLastNodeFlag().m_cBooleanValue)
        {
            void* pMostDerivedClass = CreateDataObjectFromNativeInstance(object, registry, world);
            if (pMostDerivedClass)
            {
                result.m_class = static_cast<const hkClass*>(pMostDerivedClass);
                result.m_object = object;
            }
            else
            {
                unsigned int buffer[128];
                unsigned int streamStorage[sizeof(hkOstream) / sizeof(unsigned int)];
                hkOstream& stream = *reinterpret_cast<hkOstream*>(streamStorage);
                stream.FUN_00cb1600(buffer, 512);
                stream.ProcessAndReturnValue_00cc01c0("Could not find the most derived class for virtual object ")
                    .ProcessAndReturnValue_00cc01c0(pClass->getName())
                    .ProcessAndReturnValue_00cc01c0(" at ")
                    .operator<<(object)
                    .ProcessAndReturnValue_00cc01c0(". The object is replaced with HK_NULL.");
                DAT_01268360->message(1, 0x3476d70f, (char*)buffer, ".\\Data\\Native\\hkDataObjectNative.cpp", 55);
                stream.FUN_00cc00e0();
                return result;
            }
        }
        else
        {
            result.m_class = pClass;
            result.m_object = object;
        }
    }
    return result;
}

void nativeCaller()
{
    hkVariant result = getVariantWithMostDerivedClass((unsigned int)inputClass, inputObject, inputRegistry, inputWorld);
    outputObject = result.m_object;
    outputClass = const_cast<hkClass*>(result.m_class);
}

namespace fnv_00dbb520 {
extern int DAT_010d62fc;
struct Source
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void* vf10(void*);
};
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct Record
{
    void* type;
    unsigned short byteSize;
    unsigned short flags;
    unsigned int state;
    void* reference;
    void* owner;
};
struct Object
{
    int a, b;
    Source* source;
    int d;
    Index index;
    Record* __thiscall hkDataWorldNative_findClass(void*);
};
// Looks up a record by key in the index, or allocates a new 20-byte record, stores the source reference, and inserts it into the index.
// @fnv 0x00dbb520
// src: HAVOK_SRC 0x00dbb520
Record* Object::hkDataWorldNative_findClass(void* key)
{
    void* reference;
    if (key)
    {
        Record* existing = (Record*)index.GetValue(key, 0);
        if (existing)
            return existing;
        reference = source->vf10(key);
    }
    else
        reference = 0;
    hkMemoryRouter* router = hkMemoryRouter_getInstance();
    Record* record = (Record*)reinterpret_cast<hkMemoryAllocator*>(router->m_heap)->blockAlloc(20);
    record->byteSize = 20;
    record->flags = 0;
    record->state = 0;
    record->type = &DAT_010d62fc;
    record->reference = reference;
    record->owner = this;
    index.unk(key, record);
    return record;
}
}  // namespace fnv_00dbb520

struct NativeMemberReferenceDBBA
{
    int object;
    int name;

    NativeMemberReferenceDBBA(int owner, int memberName) : object(owner), name(memberName)
    {}
};

struct C_dbbab0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;

    NativeMemberReferenceDBBA __thiscall hkDataObjectNative_accessByName(int param_1);
};

// Calls FUN_00d871a0 on m_0C with param_1, then returns a NativeMemberReferenceDBBA pairing this object with param_1.
// @fnv 0x00dbbab0
// src: XBOX_PDB 0x00dbbab0
NativeMemberReferenceDBBA C_dbbab0::hkDataObjectNative_accessByName(int aiMemberName)
{
    FUN_00d871a0 member(&m_0C, aiMemberName);
    return NativeMemberReferenceDBBA((int)this, aiMemberName);
}
