
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "nitarray.inl"
#include "../../../../include/StrArr.h"

inline unsigned int AddViewerString(StrArr* array, char* const& element)
{
    unsigned int index = array->m_usSize;
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, element);
    return index;
}

inline unsigned int SetViewerStringAtGrow(StrArr* array, unsigned int index, char* const& element)
{
    if (index >= array->m_usMaxSize)
        array->SetSize(index + array->m_usGrowBy);
    array->SetAt(index, const_cast<char*&>(element));
    return index;
}

struct FUN_00cc6540_Class
{
    unsigned char m_auiShapeKeys[4];
    void* m_pUserData;

    void hkConstraintCinfo_GetViewerStrings(StrArr* array);
    void hkRagdollLimitsConstraintCinfo_GetViewerStrings(StrArr* array);
};

char* __cdecl NiGetViewerString_00a7d550(char const* name, float value);

// @fnv 0x00cc6540
// src: XBOX_PDB 0x00cc6540
void FUN_00cc6540_Class::hkRagdollLimitsConstraintCinfo_GetViewerStrings(StrArr* array)
{
    hkConstraintCinfo_GetViewerStrings(array);

    unsigned char* data = static_cast<unsigned char*>(m_pUserData);
    if (data)
    {
        char* value = NiGetViewerString_00a7d550("ConeMinAngle", *reinterpret_cast<float*>(data + 0xa0));
        unsigned int index = array->m_usSize;
        unsigned int size = array->m_usMaxSize;
        if (index >= size)
            array->SetSize(index + array->m_usGrowBy);
        array->SetAt(index, value);

        value = NiGetViewerString_00a7d550("PlaneMinAngle", *reinterpret_cast<float*>(data + 0xb0));
        index = array->m_usSize;
        size = array->m_usMaxSize;
        if (index >= size)
            array->SetSize(index + array->m_usGrowBy);
        array->SetAt(index, value);

        value = NiGetViewerString_00a7d550("PlaneMaxAngle", *reinterpret_cast<float*>(data + 0xb4));
        index = array->m_usSize;
        size = array->m_usMaxSize;
        if (index >= size)
            array->SetSize(index + array->m_usGrowBy);
        array->SetAt(index, value);

        value = NiGetViewerString_00a7d550("TwistMinAngle", *reinterpret_cast<float*>(data + 0x88));
        index = array->m_usSize;
        size = array->m_usMaxSize;
        if (index >= size)
            array->SetSize(index + array->m_usGrowBy);
        array->SetAt(index, value);

        value = NiGetViewerString_00a7d550("TwistMaxAngle", *reinterpret_cast<float*>(data + 0x8c));
        index = array->m_usSize;
        size = array->m_usMaxSize;
        if (index >= size)
            array->SetSize(index + array->m_usGrowBy);
        array->SetAt(index, value);
    }
}

namespace fnv_00cf46e0 {

struct GlobalObjectO2_00a7b610
{
    unsigned char _pad[0x2b4];
    unsigned int m_02b4;
};

extern __declspec(thread) GlobalObjectO2_00a7b610 g_tls_object;
extern GlobalObjectO2_00a7b610* g_01268740;

char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);

struct TLSGuard
{
    unsigned int saved;

    TLSGuard() : saved(g_tls_object.m_02b4)
    {
        g_tls_object.m_02b4 = 0x10;
    }

    ~TLSGuard()
    {
        g_tls_object.m_02b4 = saved;
    }
};

// @fnv 0x00cf46e0
// src: XBOX_PDB 0x00cf46e0
void __stdcall bhkSpringDamperConstraintMotor_GetViewerStrings(StrArr* array)
{
    TLSGuard guard;
    char* value = _FUN_00a7d330(g_01268740);
    unsigned int index = array->m_usSize;

    if (index >= array->m_usMaxSize)
        array->SetSize(static_cast<unsigned int>(index + array->m_usGrowBy));

    array->SetAt(index, value);
}
}  // namespace fnv_00cf46e0

// Keep the index-returning variant local; shared AddFirstEmpty returns void.
// The explicit ECX receiver and unused EDX argument preserve the original member ABI.
// @fnv 0x00a5b4b0
// src: COMMUNITY 0x00a5b4b0
int __fastcall NiTPrimitiveArray_DWORD_AddFirstEmpty(StrArr* array, void*, char*& value)
{
    if (value == 0)
        return -1;
    unsigned short i = 0;
    for (; i < array->m_usSize; i++)
    {
        if (array->m_pBase[i] == 0)
        {
            array->m_pBase[i] = value;
            array->m_usESize++;
            return i;
        }
    }
    unsigned int count = array->m_usSize;
    if (count >= array->m_usMaxSize)
        array->SetSize(array->m_usGrowBy + count);
    array->SetAt(count, value);
    return count;
}

extern __declspec(thread) int g_iC8AD40AllocTag;

struct BC8AD40AllocTagScope
{
    int m_iSaved;

    BC8AD40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC8AD40AllocTag;
        g_iC8AD40AllocTag = aiAllocationTag;
    }
    ~BC8AD40AllocTagScope()
    {
        g_iC8AD40AllocTag = m_iSaved;
    }
};

extern const char* g_pcC8AD40Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class FUN_00c8ad40_cls
{
  public:
    void C8AD40BaseGetViewerStrings(StrArr* pkArray);
    void bhkBinaryAction_GetViewerStrings(StrArr* pkArray);
};

// @fnv 0x00c8ad40
// src: XBOX_PDB 0x00c8ad40
void FUN_00c8ad40_cls::bhkBinaryAction_GetViewerStrings(StrArr* pkArray)
{
    BC8AD40AllocTagScope kScope(0x10);
    C8AD40BaseGetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcC8AD40Name);
    AddViewerString(pkArray, pcName);
}

namespace fnv_00cc31c0 {
extern __declspec(thread) int g_iCC31C0MemContext;

class CC31C0MemContext
{
  public:
    CC31C0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC31C0MemContext;
        g_iCC31C0MemContext = aiMemoryContext;
    }
    ~CC31C0MemContext()
    {
        g_iCC31C0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

extern const char* g_pcCC31C0ClassName;
extern "C" char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcName);

class CC31C0Object
{
  public:
    void GetViewerStringsBase(StrArr* pkStrings);
    void bhkSpringAction_GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00cc31c0
// src: XBOX_PDB 0x00cc31c0
void CC31C0Object::bhkSpringAction_GetViewerStrings(StrArr* pkStrings)
{
    CC31C0MemContext kContext(0x10);
    GetViewerStringsBase(pkStrings);
    AddViewerString(pkStrings, NiViewerStrings_NiGetViewerString_Title(g_pcCC31C0ClassName));
}
}  // namespace fnv_00cc31c0

struct ViewerObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void* GetType();
};
const char* __cdecl TypeName(void*);
char* __cdecl MakeViewerString(const char*, const char*);
char* __cdecl NiGetViewerString_00a7d4d0(const char*, int);
int __cdecl FormatViewer(char*, unsigned int, const char*, ...);
struct ViewerConstraint
{
    int unk00;
    ViewerObject* object;
    int priority;
    void* entityA;
    void* entityB;
    void hkConstraintCinfo_GetViewerStrings(StrArr* array);
};
// @fnv 0x00c8a560
// src: XBOX_PDB 0x00c8a560
void ViewerConstraint::hkConstraintCinfo_GetViewerStrings(StrArr* array)
{
    BC8AD40AllocTagScope scope(16);
    char* text;
    char buffer[32];
    if (object)
    {
        text = MakeViewerString("Type", TypeName(object->GetType()));
        AddViewerString(array, text);
    }
    FormatViewer(buffer, 32, "0x%8X", entityA);
    text = MakeViewerString("hkpEntityA", buffer);
    AddViewerString(array, text);
    FormatViewer(buffer, 32, "0x%8X", entityB);
    text = MakeViewerString("hkpEntityB", buffer);
    AddViewerString(array, text);
    text = NiGetViewerString_00a7d4d0("ePriority", priority);
    AddViewerString(array, text);
}

// Appends this class name to the viewer strings after the base entries, under the Havok allocation tag.

extern __declspec(thread) int g_iCC4740AllocTag;

struct BCC4740AllocTagScope
{
    int m_iSaved;

    BCC4740AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = aiAllocationTag;
    }
    ~BCC4740AllocTagScope()
    {
        g_iCC4740AllocTag = m_iSaved;
    }
};

extern const char* g_pcCC4740Name;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* pcString);

class CC4740Base
{
  public:
    void GetViewerStrings(StrArr* pkArray);
};

class CC4740Derived : public CC4740Base
{
  public:
    void bhkAngularDashpotAction_GetViewerStrings(StrArr* pkArray);
};

// @fnv 0x00cc4740
// src: XBOX_PDB 0x00cc4740
void CC4740Derived::bhkAngularDashpotAction_GetViewerStrings(StrArr* pkArray)
{
    BCC4740AllocTagScope kScope(0x10);
    CC4740Base::GetViewerStrings(pkArray);
    char* pcName = NiViewerStrings_NiGetViewerString_Title(g_pcCC4740Name);
    AddViewerString(pkArray, pcName);
}

extern __declspec(thread) int g_iCC4740AllocTag;
struct CF4520AllocTagScope
{
    int saved;
    CF4520AllocTagScope(int tag)
    {
        saved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = tag;
    }
    ~CF4520AllocTagScope()
    {
        g_iCC4740AllocTag = saved;
    }
};
extern const char* DAT_01268738;
char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char* name);
// @fnv 0x00cf4520
// src: XBOX_PDB 0x00cf4520
void __stdcall bhkVelocityConstraintMotor_GetViewerStrings(StrArr* array)
{
    CF4520AllocTagScope tag(16);
    char* element = NiViewerStrings_NiGetViewerString_Title(DAT_01268738);
    AddViewerString(array, element);
}

extern __declspec(thread) int g_iCCCFD0AllocTag;
struct BCCCFD0AllocTagScope
{
    int m_iSaved;

    BCCCFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCCFD0AllocTag;
        g_iCCCFD0AllocTag = aiAllocationTag;
    }
    ~BCCCFD0AllocTagScope()
    {
        g_iCCCFD0AllocTag = m_iSaved;
    }
};

extern const char* g_pcCCCFD0Name;

class CCCFD0Base
{
  public:
    void GetViewerStrings(StrArr* pkStrings);
};

class CCCFD0Derived : public CCCFD0Base
{
  public:
    void bhkExtendedMeshShape_GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00cccfd0
// src: XBOX_PDB 0x00cccfd0
void CCCFD0Derived::bhkExtendedMeshShape_GetViewerStrings(StrArr* pkStrings)
{
    BCCCFD0AllocTagScope kScope(0x10);
    CCCFD0Base::GetViewerStrings(pkStrings);
    AddViewerString(pkStrings, NiViewerStrings_NiGetViewerString_Title(g_pcCCCFD0Name));
}

extern "C" void _ReadWriteBarrier();
struct CAA010Inner
{
    virtual void OpA();
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void OpF();
    virtual void OpG();
    virtual void OpH();
    virtual void* GetHandle();
};

struct CAA010Shell
{
    virtual void Activate(int flag);
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void PassArray(StrArr* array);
    void SetChildObject(CAA010Inner* inner);
};

struct CAA010Data
{
    int unk00;
    int unk04;
    int unk08;
    CAA010Inner* m_obj;
    int unk10;
    int unk14;
    int unk18;
    float m_f;
};

extern __declspec(thread) int g_caa010TlsTag;

struct CAA010TagScope
{
    int m_iSaved;
    CAA010TagScope(int aiAllocationTag)
    {
        m_iSaved = g_caa010TlsTag;
        g_caa010TlsTag = aiAllocationTag;
    }
    ~CAA010TagScope()
    {
        g_caa010TlsTag = m_iSaved;
    }
};

CAA010Shell* __cdecl CreateSaver(void* p);

struct CAA010This
{
    int unk00;
    void* m_pUserData;
    void hkConstraintCinfo_GetViewerStrings(StrArr* array);
    CAA010Inner* GetObj()
    {
        return m_pUserData ? ((CAA010Data*)m_pUserData)->m_obj : 0;
    }
    void hkMalleableConstraintCinfo_GetViewerStrings(StrArr* array);
};

// @fnv 0x00caa010
// src: XBOX_PDB 0x00caa010
void CAA010This::hkMalleableConstraintCinfo_GetViewerStrings(StrArr* array)
{
    CAA010TagScope scope(16);
    hkConstraintCinfo_GetViewerStrings(array);
    SetViewerStringAtGrow(array, array->m_usSize, NiGetViewerString_00a7d550("Strength", m_pUserData ? ((CAA010Data*)m_pUserData)->m_f : 0.0f));
    CAA010Inner* inner = GetObj();
    _ReadWriteBarrier();
    if (inner)
    {
        CAA010Shell* shell = CreateSaver(inner->GetHandle());
        if (shell)
        {
            shell->SetChildObject(inner);
            shell->PassArray(array);
            shell->Activate(1);
            return;
        }
        return;
    }
}

extern const char* DAT_01268730;
// @fnv 0x00cf4300
// src: XBOX_PDB 0x00cf4300
void __stdcall bhkPositionConstraintMotor_GetViewerStrings(StrArr* pkArray)

{

    CF4520AllocTagScope scope(16);

    char* pcElement = NiViewerStrings_NiGetViewerString_Title(DAT_01268730);

    AddViewerString(pkArray, pcElement);
}
