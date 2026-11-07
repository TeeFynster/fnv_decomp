
// src/havok/common/scenedata/attributes/hkxattributegroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxattributegroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkRefVariant.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkxAttribute.h"

__forceinline void* __cdecl operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}

void hkMemUtil_memMove(void* pvDst, void* pvSrc, unsigned int uiNumBytes) throw();

inline hkStringPtr::~hkStringPtr() throw()
{
    Object_UpdateFields_00cb0c00();
}

// The shared hkStringPtr omits the copy constructor at 0x00cb0bd0.
// Call its existing entry point with the original thiscall ABI.
void CopyConstructAttributeName() throw();
typedef void (__thiscall* AttributeNameCopyConstructor)(hkStringPtr*, const hkStringPtr&);

inline hkRefVariant::hkRefVariant(const hkRefVariant& kOther) throw()
{
    if (kOther.m_pRetainedObject)
        kOther.m_pRetainedObject->addReference();
    m_pRetainedObject = kOther.m_pRetainedObject;
}

inline hkRefVariant::~hkRefVariant() throw()
{
    if (m_pRetainedObject)
        m_pRetainedObject->removeReference();
    m_pRetainedObject = 0;
}

template <typename T> __forceinline void hkDestructE5CD(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}

__forceinline hkxAttribute* CopyConstructAttribute(hkxAttribute* destination, const hkxAttribute& source)
{
    reinterpret_cast<AttributeNameCopyConstructor>(&CopyConstructAttributeName)(&destination->m_name, source.m_name);
    if (source.m_uiFilterValue.m_pRetainedObject)
        source.m_uiFilterValue.m_pRetainedObject->addReference();
    destination->m_uiFilterValue.m_pRetainedObject = source.m_uiFilterValue.m_pRetainedObject;
    return destination;
}

__forceinline void hkConstructWithArrayE5CD(hkxAttribute* t, int n, const hkxAttribute* s)
{
    for (int i = 0; i < n; ++i)
    {
        hkxAttribute* destination = t + i;
        if (destination)
            CopyConstructAttribute(destination, s[i]);
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCapacity = getCapacity();
    if (iCapacity < n)
    {
        int iCap2 = 2 * iCapacity;
        int iNewSize = (n < iCap2) ? iCap2 : n;
        hkArrayUtil::_reserve(kAlloc, this, iNewSize, sizeof(T));
    }
}

// Replaces iNumDel elements at iIndex with iNumToInsert copies of pkInsert, growing the array if needed and shifting the tail.
// @fnv 0x00e5cdb0
template <>
void hkArrayBase<hkxAttribute>::_spliceInto(hkMemoryAllocator& kAlloc, int iIndex, int iNumDel, const hkxAttribute* pkInsert,
                              int iNumToInsert)
{
    int iNewSize = m_iElementCount + iNumToInsert - iNumDel;
    int iNumToMove = m_iElementCount - iIndex - iNumDel;
    if (iNewSize > getCapacity())
        GrowArrayCapacity(kAlloc, iNewSize);
    hkDestructE5CD(m_data + iIndex, iNumDel);
    hkMemUtil_memMove(m_data + iIndex + iNumToInsert, m_data + iIndex + iNumDel, iNumToMove * sizeof(hkxAttribute));
    hkConstructWithArrayE5CD(m_data + iIndex, iNumToInsert, pkInsert);
    m_iElementCount = iNewSize;
}

// Adapted from unverified 2026-10-25 attempts by two prior contributors.
struct NameReference
{
    unsigned int encoded;
    int hkStringPtr_getLength();
};
struct TextWriter
{
    void** virtualMethods;
};
extern "C" const char str_010c9308[];
typedef void(__thiscall* WriteMethod)(TextWriter*, const char*, int);
struct AttributeFormatter
{
    int unknown00;
    int unknown04;
    TextWriter* output;
    AttributeFormatter* WriteName(NameReference* name);
};
// Writes the string at the encoded address when encoded is nonzero; otherwise writes str_010c9308, then returns this.
// @fnv 0x00cc05a0
AttributeFormatter* AttributeFormatter::WriteName(NameReference* name)
{
    if (name->encoded & ~1u)
    {
        const char* text = (const char*)(name->encoded & ~1u);
        void** methods = output->virtualMethods;
        int length = name->hkStringPtr_getLength();
        ((WriteMethod)methods[4])(output, text, length);
    }
    else
    {
        TextWriter* writer = output;
        ((WriteMethod)writer->virtualMethods[4])(writer, str_010c9308, 6);
    }
    return this;
}

#include <xmmintrin.h>
struct __declspec(align(16)) HMat4
{
    __m128 c0, c1, c2, c3;
};
struct MatrixHolder
{
    int type;
    int flags;
    HMat4* matrix;
};
struct AttrLookup
{
    MatrixHolder* CallWithGlobalObject(const char* name);
    int GetAttributeMatrix(const char* name, bool verbose, HMat4* result);
};
struct MessageBuilder
{
    int storage;
    int length;
    int capacity;
    void FUN_00cb1600(char* buffer, unsigned int size);
    MessageBuilder* ProcessAndReturnValue_00cc01c0(const char*);
    MessageBuilder* WriteName(AttrLookup*);
    void FUN_00cc00e0();
};
struct AssertHandler
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void assertFailure(int enabled, unsigned int code, void* msg, const char* source, unsigned int line);
};
extern "C" AssertHandler* DAT_01268360;
extern "C" char DAT_010ecd74[];
extern "C" char DAT_010eccfc[];
extern "C" char DAT_010ecd0c[];
extern "C" char DAT_010eccc8[];
// Copies the named attribute's matrix into result when found; if missing, optionally reports an assertion failure and returns 1.
// @fnv 0x00e5cc00
int AttrLookup::GetAttributeMatrix(const char* apAttributeName, bool verbose, HMat4* result)
{
    MatrixHolder* attribute = CallWithGlobalObject(apAttributeName);
    if (attribute)
    {
        __m128* source = reinterpret_cast<__m128*>(attribute->matrix);
        __m128* output = reinterpret_cast<__m128*>(result);
        output[0] = source[0];
        output[1] = source[1];
        output[2] = source[2];
        output[3] = source[3];
        return 0;
    }
    if (verbose)
    {
        __declspec(align(16)) void* scratch[0x80];
        MessageBuilder message;
        message.FUN_00cb1600(reinterpret_cast<char*>(scratch), 0x200);
        message.ProcessAndReturnValue_00cc01c0(DAT_010ecd74)
            ->ProcessAndReturnValue_00cc01c0(apAttributeName)
            ->ProcessAndReturnValue_00cc01c0(DAT_010eccfc)
            ->WriteName(this)
            ->ProcessAndReturnValue_00cc01c0(DAT_010ecd0c);
        DAT_01268360->assertFailure(1, 0xabbaab81, scratch, DAT_010eccc8, 0xc4);
        message.FUN_00cc00e0();
    }
    return 1;
}

// Default construction entry point at 0x00e3f8e0; this is passed in ECX.
void __fastcall ConstructAttribute(hkxAttribute* destination);

struct Allocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct ElemArray
{
    hkxAttribute* data;
    int size;
    int capacityAndFlags;

    void __thiscall SpliceArray_Thunk(int alloc, int zero, hkxAttribute* src, int n);
};

struct S00e5cce0_Class
{
    int unk00;
    ElemArray arr;

    void __thiscall UpdateState_00cb0c30(const S00e5cce0_Class& o);
    S00e5cce0_Class& __thiscall CopyArrayAndReplaceElements(const S00e5cce0_Class& o);
};

void __cdecl hkArrayUtil__reserve(int alloc, ElemArray* a, int bytes, int elemSize);
Allocator* __cdecl hkMemoryRouter_getInstance(void);

static __forceinline void destructElems(hkxAttribute* data, int n)
{
    for (int i = 0; i < n; i++)
    {
        hkxAttribute& e = data[i];
        if (e.m_uiFilterValue.m_pRetainedObject != 0)
        {
            e.m_uiFilterValue.m_pRetainedObject->removeReference();
        }
        e.m_uiFilterValue.m_pRetainedObject = 0;
        e.m_name.Object_UpdateFields_00cb0c00();
    }
}

static __forceinline void constructElems(hkxAttribute* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (&p[i] != 0)
        {
            ConstructAttribute(&p[i]);
        }
    }
}

// Calls FUN_00cb0c30(o), destroys existing elements, then copies o.arr via FUN_00e5cec0 and returns *this.
// @fnv 0x00e5cce0
// src: GUESS 0x00e5cce0 (confidence: medium)
S00e5cce0_Class& __thiscall S00e5cce0_Class::CopyArrayAndReplaceElements(const S00e5cce0_Class& aOther)
{
    UpdateState_00cb0c30(aOther);
    ElemArray& s = arr;
    Allocator* pAllocator = hkMemoryRouter_getInstance();
    int alloc = pAllocator->unk10;
    int n = 0;
    int iCapacity = s.capacityAndFlags & 0x3fffffff;
    if (iCapacity < n)
    {
        int iNewCapacity = iCapacity + iCapacity;
        hkArrayUtil__reserve(alloc, &s, n < iNewCapacity ? iNewCapacity : n, 8);
    }

    destructElems(s.data, s.size);
    constructElems(s.data + s.size, 0 - s.size);
    s.size = 0;

    int iCount = aOther.arr.size;
    if (iCount != 0)
    {
        hkxAttribute* src = aOther.arr.data;
        int a = hkMemoryRouter_getInstance()->unk10;
        s.SpliceArray_Thunk(a, 0, src, iCount);
    }
    return *this;
}
