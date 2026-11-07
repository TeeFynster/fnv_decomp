#include "../../../../../../../include/hkArray.h"

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ddcdd0
// src: HAVOK_LIB 0x00ddcdd0
unsigned int hkpMeshWeldingUtility_modifyCombinedEdgesBitcode(unsigned int auiValue, unsigned int auiIndex, unsigned int auiFieldValue)
{
    return (auiValue & ~(0x1f << (auiIndex * 5))) | (auiFieldValue << (auiIndex * 5));
}

// @fnv 0x00ddcdf0
int __cdecl ExtractBitField(unsigned short ausValue, char acShiftIndex)
{
    return (ausValue >> (acShiftIndex * 5)) & 0x1f;
}

struct DDCC60BaseObject
{
    virtual ~DDCC60BaseObject()
    {}
};

struct DDCC60ReferencedObject : DDCC60BaseObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct DDCC60Action
{
    virtual ~DDCC60Action()
    {}

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DDCC60Listener
{
    virtual ~DDCC60Listener()
    {}
};

struct DDCC60World
{
    __declspec(nothrow) void removeListener(DDCC60Listener* listener);
    __declspec(nothrow) void removeReference();
};

struct FUN_00ddcc60 : DDCC60ReferencedObject, DDCC60Action, DDCC60Listener
{
    DDCC60World* m_pOwningWorld;

    virtual ~FUN_00ddcc60();
};

// If the world pointer is set, removes this listener and reference from it, then clears the pointer.
// @fnv 0x00ddcc60
FUN_00ddcc60::~FUN_00ddcc60()
{
    if (m_pOwningWorld)
    {
        m_pOwningWorld->removeListener(this);
        m_pOwningWorld->removeReference();
        m_pOwningWorld = 0;
    }
}

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00ddcc60();
    CpuObject* DestroyOrFree(unsigned int flags);
};
// Calls FUN_00ddcc60, then if flags has bit 1 set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00ddcd70
CpuObject* CpuObject::DestroyOrFree(unsigned int flags)
{
    FUN_00ddcc60();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, size);
    }
    return this;
}

extern double DAT_010cd5a8;
extern double DAT_0101ff40;
// Scans 31 candidate angles computed from index and returns the first index whose candidate is >= angle, decremented when angle is positive and not equal.
// @fnv 0x00ddce10
int FindAngleIndex(float angle)
{
    int index = 0;
    float candidate;
    while (index < 31)
    {
        candidate = (float)((double)index * DAT_010cd5a8 - DAT_0101ff40);
        if (candidate >= angle)
        {
            if (angle > 0.0f && candidate != angle)
                --index;
            return index;
        }
        ++index;
    }
    return index;
}

int __cdecl hkString_strCmp(const char* pcA, const char* pcB);

class __declspec(novtable) BDDCCB0ReferencedObject
{
  public:
    BDDCCB0ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual ~BDDCCB0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class BDDCCB0ProcessContext
{
  public:
    virtual ~BDDCCB0ProcessContext();
    virtual const char* getType();
};

class BDDCCB0WorldAddedListener;

class BDDCCB0PhysicsContext : public BDDCCB0ReferencedObject, public BDDCCB0ProcessContext
{
  public:
    void AddWorldAddedListener(BDDCCB0WorldAddedListener* pkListener);
    void RetainReference();
};



class BDDCCB0Process
{
  public:
    BDDCCB0Process(bool bSelectable) : m_bSelectable(bSelectable)
    {}
    virtual ~BDDCCB0Process();

    bool m_bSelectable;
    void* m_pkProcessHandler;
    void* m_pkDisplayHandler;
    void* m_pkInStream;
    void* m_pkOutStream;
};

class BDDCCB0WorldAddedListener
{
  public:
    virtual ~BDDCCB0WorldAddedListener();
};

class FUN_00ddccb0_cls : public BDDCCB0ReferencedObject, public BDDCCB0Process, public BDDCCB0WorldAddedListener
{
  public:
    FUN_00ddccb0_cls(const hkArrayBase<BDDCCB0ProcessContext*>& kContexts) throw();
    virtual ~FUN_00ddccb0_cls();

    BDDCCB0PhysicsContext* m_pkContext;
};

// @fnv 0x00ddccb0
FUN_00ddccb0_cls::FUN_00ddccb0_cls(const hkArrayBase<BDDCCB0ProcessContext*>& kContexts) throw()
    : BDDCCB0Process(true), m_pkContext(0)
{
    int iSize = kContexts.GetLogicalSize();
    for (int i = 0; i < iSize; i++)
    {
        if (hkString_strCmp("Physics", kContexts[i]->getType()) == 0)
        {
            m_pkContext = static_cast<BDDCCB0PhysicsContext*>(kContexts[i]);
            break;
        }
    }

    if (m_pkContext)
    {
        m_pkContext->AddWorldAddedListener(this);
        m_pkContext->RetainReference();
    }
}

struct Item
{
    int unk00;
    int unk04;
    float unk08;
};

struct Flag
{
    bool value;
    Flag(bool v) : value(v)
    {}
};

// Compares unk08 of two Item objects and returns a Flag holding whether the first is less than the second.
// @fnv 0x00ddcda0
// src: GUESS 0x00ddcda0 (confidence: low)
Flag __cdecl Object_CompareField08_00ddcda0(Item* apLeft, Item* apRight)
{
    bool r;
    if (apLeft->unk08 < apRight->unk08)
        r = true;
    else
        r = false;
    return Flag(r);
}

#include <math.h>
struct DDCE80Point
{
    float x;
    float y;
    float z;
};

struct DDCE80Bool
{
    char m_cBooleanValue;

    DDCE80Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

inline float DDCE80Fabs(float r)
{
    return (float)fabs(r);
}

inline bool DDCE80IsNearlyEqual(float d)
{
    if (DDCE80Fabs(d) < 0.001f)
        return true;
    return false;
}

// Returns true when the z components of the two points are not nearly equal.
// @fnv 0x00ddce80
DDCE80Bool __cdecl AreZDiffering(const DDCE80Point& a, const DDCE80Point& b)
{
    return DDCE80Bool(!DDCE80IsNearlyEqual(a.z - b.z));
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00ddd040 {
extern "C" double __cdecl fabs(double);
extern double DAT_0103c7c8;
struct S_V
{
    __m128 q;
};
struct S_P
{
    const S_V* p;
    const S_V* val() const
    {
        return p;
    }
};
// Computes the dot product of the first three components of two vectors, takes its absolute value, and stores 1 in out if below DAT_0103c7c8, else 0.
// @fnv 0x00ddd040
unsigned char* __cdecl IsDotProductBelowThreshold(unsigned char* out, S_P a, S_P b)
{
    __m128 x1 = a.val()->q;
    __m128 x2 = b.val()->q;
    x2 = _mm_mul_ps(x1, x2);
    __m128 vSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    vSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), vSum);
    float d;
    _mm_store_ss(&d, vSum);
    d = (float)fabs(d);
    unsigned char r;
    if (d < DAT_0103c7c8)
    {
        r = 1;
    }
    else
    {
        r = 0;
    }
    *(volatile unsigned char*)out = r;
    return out;
}
}  // namespace fnv_00ddd040

struct FUN_00ddcc40
{
    virtual ~FUN_00ddcc40();
};

// @fnv 0x00ddcc40
FUN_00ddcc40::~FUN_00ddcc40()
{}

struct Base1
{
// @fnv 0x00ddcd50
    virtual void FUN_00ddcd50();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct Base2
{
    virtual void FUN_00ddcd50();
};
struct Derived : Base1, Base2
{
    Derived();
    virtual void FUN_00ddcd50();
};
Derived::Derived()
{}

// FUN_00ddcd60 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00ddcd60
{
    A1_00ddcd60();
    virtual void AdjustThisAndForward_00ddcd60();
    char pad[0x04];
};
struct A2_00ddcd60
{
    A2_00ddcd60();
    virtual void AdjustThisAndForward_00ddcd60();
};
struct Own_00ddcd60 : A1_00ddcd60, A2_00ddcd60
{
    Own_00ddcd60();
    virtual void key_fn();
// @fnv 0x00ddcd60
// src: GUESS 0x00ddcd60 (confidence: low)
    void AdjustThisAndForward_00ddcd60();
};
Own_00ddcd60::Own_00ddcd60()
{}
void Own_00ddcd60::key_fn()
{}
Own_00ddcd60* make_00ddcd60()
{
    static Own_00ddcd60 o;
    return &o;
}
