#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// Keep the unit's float-only SIMD intrinsic type for the original aliasing behavior.
#define _INCLUDED_MM2
// Exe 0x00d92900 FUN_00d92900: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float f0;
    float f1;
    float f2;
    float f3;
} __m128, LocalM128;
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);

#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkpConstraintOwner.h"
#include "../../../../../../include/hkpSimpleContactConstraintAtom.h"

// src/havok/physics/dynamics/constraint/contact/hkpsimplecontactconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/contact/hkpsimplecontactconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl hkpConstraintData_getConstraintInfoUtil(void* atom, unsigned short index, unsigned int arg);
struct FUN_00d927b0_class
{
    void hkpSimpleContactConstraintData_getConstraintInfo(unsigned int arg);
};
// @fnv 0x00d927b0
// src: HAVOK_LIB 0x00d927b0
void FUN_00d927b0_class::hkpSimpleContactConstraintData_getConstraintInfo(unsigned int arg)
{
    void* atom = *(void**)((char*)this + 0x28);
    hkpConstraintData_getConstraintInfoUtil(atom, *(unsigned short*)((char*)atom + 2), arg);
}

// @fnv 0x00d927d0
// src: HAVOK_LIB 0x00d927d0
void __stdcall hkpSimpleContactConstraintData_getRuntimeInfo(int, int* paiValues)
{
    paiValues[0] = 0;
    paiValues[1] = 0;
}

struct S_00d92690_Alloc
{
    virtual void* Alloc(int size);
    virtual void* Alloc2(int size);
    virtual void Free(void* p, int size);
};
struct S_00d92690_Mgr
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d92690_Alloc* unk10;
    S_00d92690_Alloc* GetAllocator()
    {
        return unk10;
    }
};

hkpSimpleContactConstraintAtom* AllocateBlock(int cap, int a, int b, int maxCap);
void hkpSimpleContactConstraintAtom_ProcessEntries_00d925b0(hkpSimpleContactConstraintAtom* dst, hkpSimpleContactConstraintAtom* src);
int RoundUpToBucketSize(int size);
S_00d92690_Mgr* hkMemoryRouter_getInstance();

// @fnv 0x00d92690
// src: HAVOK_LIB 0x00d92690
hkpSimpleContactConstraintAtom* hkpSimpleContactConstraintAtomUtil_expandOne(hkpSimpleContactConstraintAtom* apContainer, bool* grew)
{
    hkpSimpleContactConstraintAtom* result = apContainer;
    hkpSimpleContactConstraintAtom* pContainer = apContainer;
    int iCount = apContainer->m_usNumContactPoints;
    if (iCount >= apContainer->m_usMaxNumContactPoints)
    {
        int iNewCapacity = iCount > 2 ? iCount : 2;
        iNewCapacity *= 2;
        if (iNewCapacity >= apContainer->m_usMaxNumContactPointProperties)
            iNewCapacity = apContainer->m_usMaxNumContactPointProperties;
        result = AllocateBlock(iNewCapacity, apContainer->m_ucNumReservedContactPoints, apContainer->m_ucNumContactPointProperties, apContainer->m_usMaxNumContactPointProperties);
        hkpSimpleContactConstraintAtom_ProcessEntries_00d925b0(result, apContainer);
        int size = RoundUpToBucketSize(apContainer->m_usSizeOfAllAtoms);
        hkMemoryRouter_getInstance()->GetAllocator()->Free(apContainer, size);
        pContainer = result;
        *grew = true;
    }
    pContainer->m_usNumContactPoints = iCount + 1;
    int iElemSize = pContainer->m_ucContactPointPropertiesStriding;
    int* data = (int*)((char*)pContainer + pContainer->m_usMaxNumContactPoints * 32 + 0x30 + (short)iCount * (short)iElemSize);
    for (int i = (iElemSize >> 2) - 1; i >= 0; --i)
        *data++ = 0;
    return result;
}

// @fnv 0x00d92810
// src: GUESS 0x00d92810 (confidence: high)
int __cdecl hkpSimpleContactConstraintData_ReturnConstant_11()
{
    return 11;
}

// @fnv 0x00d92800
// src: XBOX_PDB 0x00d92800
void __stdcall hkpSimpleContactConstraintData_isValid(bool* p)
{
    *p = true;
}

extern unsigned char DAT_010cc934;

struct PacketResult
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned short state10;
    volatile unsigned short version12;
    void* volatile ptr14;
    void* volatile ptr18;
    void* ptr1c;
    void* ptr20;
    void* ptr24;
    void* ptr28;
    void* ptr2c;
};

struct FUN_00d92f20
{
    void* vtable;
    unsigned short unk04;
    unsigned short active06;
    unsigned int field08;
    void* field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    void* volatile context24;
    hkpSimpleContactConstraintAtom* buffer28;
    unsigned int size2c;

    FUN_00d92f20(void* atom, const unsigned char* first, const unsigned char* second);
};

// Initialises the object's vtable and fields, allocates a buffer sized from first[0xd1] and second[0xd1], and zeroes the packet result header fields.
// @fnv 0x00d92f20
FUN_00d92f20::FUN_00d92f20(void* atom, const unsigned char* first, const unsigned char* second)
{
    vtable = &DAT_010cc934;
    active06 = 1;
    field08 = 0;
    field0c = &field18;
    field10 = 0;
    field14 = 0x80000008;
    context24 = atom;

    unsigned int lenA = first[0xd1];
    unsigned int lenB = second[0xd1];
    unsigned int bytesPerEntry = (lenA + lenB) * 4 + 0x34;
    buffer28 = AllocateBlock(1, lenA, lenB, (unsigned short)(0x3400 / (int)bytesPerEntry));

    PacketResult* result = reinterpret_cast<PacketResult*>(buffer28);
    result->state10 = 0;
    result->version12 = 3;
    result->ptr14 = 0;
    result->ptr18 = 0;
    result->ptr1c = 0;
    result->ptr20 = 0;
    result->ptr24 = 0;
    result->ptr28 = 0;
    result->ptr2c = 0;

    size2c = buffer28->m_usSizeOfAllAtoms;
}

struct S_00d92fd0_Atom
{
    unsigned short type;
    unsigned short unk02;
    int unk04, unk08, unk0c, unk10;
    S_00d92fd0_Atom* next;
    void nullsub_31(int a, float b, int c, int d, int e, int f);
    void UpdateState_00d21d10(int a, float b, int c, int d, int e, int f);
    void CopyData_00d21fc0(int a, float b, int c, int d, int e, int f);
    void ProcessState_00d22260(int a, float b, int c, int d, int e, int f);
};
struct S_00d92fd0_Alloc : S_00d92690_Alloc
{
    virtual void v3();
    virtual void Free2(void* p, int size);
};
struct S_00d92fd0_Arr
{
    S_00d92fd0_Atom** data;
    int size;
    int cap;
    S_00d92fd0_Atom* local[16];
    S_00d92fd0_Arr()
    {
        data = local;
        size = 0;
        cap = 0x80000010;
    }
};
struct S_00d92fd0_Holder
{
    int unk00, unk04, unk08, unk0c;
    S_00d92fd0_Atom* head;
};
void __cdecl ResizeAudioStream(S_00d92690_Alloc* a, S_00d92fd0_Arr* arr, int elem);

struct S_00d92fd0_This
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    S_00d92fd0_Holder* holder;
    void DispatchAtomHandlers(int p1, float p2, int p3, int p4, int p5, int p6);
};

// Collects atoms from holder->head with type >= 0x17 into a temporary array, then dispatches each in reverse order to a handler chosen by type.
// @fnv 0x00d92fd0
void S_00d92fd0_This::DispatchAtomHandlers(int aiArg1, float afArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6)
{
    if (!holder->head)
        return;
    S_00d92fd0_Arr arr;
    S_00d92fd0_Atom* a = holder->head;
    while (a->type >= 0x17)
    {
        S_00d92690_Mgr* pMgr = hkMemoryRouter_getInstance();
        if (arr.size == (arr.cap & 0x3fffffff))
            ResizeAudioStream(pMgr->GetAllocator(), &arr, 4);
        arr.data[arr.size] = a;
        arr.size++;
        a = a->next;
    }
    for (int i = arr.size - 1; i >= 0; i--)
    {
        S_00d92fd0_Atom* x = arr.data[i];
        switch (x->type)
        {
        case 0x18:
            x->nullsub_31(aiArg1, afArg2, aiArg3, aiArg4, aiArg5, aiArg6);
            break;
        case 0x17:
            x->UpdateState_00d21d10(aiArg1, afArg2, aiArg3, aiArg4, aiArg5, aiArg6);
            break;
        case 0x1a:
            x->CopyData_00d21fc0(aiArg1, afArg2, aiArg3, aiArg4, aiArg5, aiArg6);
            break;
        case 0x1c:
            x->ProcessState_00d22260(aiArg1, afArg2, aiArg3, aiArg4, aiArg5, aiArg6);
            break;
        }
    }
    S_00d92fd0_Alloc* pAlloc = (S_00d92fd0_Alloc*)hkMemoryRouter_getInstance()->GetAllocator();
    arr.size = 0;
    if ((arr.cap & 0x80000000) == 0)
        pAlloc->Free2(arr.data, (arr.cap & 0x3fffffff) * 4);
}

extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(void*, void*, int);

struct FUN_00d93140_cls
{
    unsigned char* m_data;
    unsigned int m_len;
    unsigned int m_cap;
    unsigned int ReplaceOrAppendByte(unsigned char value);
};

// @fnv 0x00d93140
unsigned int FUN_00d93140_cls::ReplaceOrAppendByte(unsigned char value)
{
    int i = (int)m_len - 1;
    while (i >= 0)
    {
        if (m_data[i] == 0xff)
        {
            m_data[i] = value;
            return (unsigned int)i;
        }
        i--;
    }
    S_00d92690_Mgr* mgr = hkMemoryRouter_getInstance();
    if (m_len == (m_cap & 0x3fffffff))
    {
        ResizeAudioStream(mgr->unk10, this, 1);
    }
    unsigned char* slot = m_data + m_len;
    _ReadWriteBarrier();
    *slot = value;
    m_len++;
    return m_len - 1;
}

// @fnv 0x00d927f0
// src: GUESS 0x00d927f0 (confidence: high)
int __stdcall hkpSimpleContactConstraintData_ReturnZero(int arg)
{
    return 0;
}

struct FUN_00d92820_cls
{
    int unk00;
    char* hkpSimpleContactConstraintData_getSimpleConstraintContactMgr();
};

// @fnv 0x00d92820
// src: XBOX_PDB 0x00d92820
char* FUN_00d92820_cls::hkpSimpleContactConstraintData_getSimpleConstraintContactMgr()
{
    return (char*)this - 0x14;
}

struct hkNodeX
{
    unsigned short type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkNodeX* next;

    void ScaleInverseInertia(int a1, int a2, int a3, int a4, int a5);
    void SetGlobalVectors(int a1, int a2, int a3, int a4, int a5);
    void CopyMemory_00d21f50(int a1, int a2, int a3, int a4, int a5);
    void UpdateFields_00d22160(int a1, int a2, int a3, int a4, int a5);
};

struct hkHolderX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkNodeX* unk10;
};

struct hkClsX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    hkHolderX* unk24;

    void DispatchNodeCallbacks(int a1, int a2, int a3, int a4, int a5);
};

// Walks the hkNodeX list from the holder's unk10 while type is at least 0x17, calling a type-specific function for types 0x17, 0x18, 0x1A and 0x1C.
// @fnv 0x00d92830
void hkClsX::DispatchNodeCallbacks(int a1, int a2, int a3, int a4, int a5)
{
    hkHolderX* pHolder = unk24;
    if (pHolder->unk10 == 0)
        return;
    hkNodeX* node = pHolder->unk10;
    while (node->type >= 0x17)
    {
        switch (node->type)
        {
        case 0x18:
            node->ScaleInverseInertia(a1, a2, a3, a4, a5);
            break;
        case 0x17:
            node->SetGlobalVectors(a1, a2, a3, a4, a5);
            break;
        case 0x1A:
            node->CopyMemory_00d21f50(a1, a2, a3, a4, a5);
            break;
        case 0x1C:
            node->UpdateFields_00d22160(a1, a2, a3, a4, a5);
            break;
        }
        node = node->next;
    }
}

struct hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};
struct PhysicsMaterial
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    unsigned int m_ulUserData;
    unsigned char m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned char m_usFlags;
    unsigned char m_flags;
    void init()
    {
        m_fAccumulatedImpulse = 0.0f;
        m_fImpulseLimit = 0.0f;
        m_flags = 1;
    }
};

inline hkContactPoint* hkpSimpleContactConstraintAtom::getContactPoints()
{
    return reinterpret_cast<hkContactPoint*>(this + 1);
}

inline hkContactPoint* hkpSimpleContactConstraintAtom::getContactPoints() const
{
    return (hkContactPoint*)(this + 1);
}

inline PhysicsMaterial* hkpSimpleContactConstraintAtom::getContactPointPropertiesStream(int i)
{
    return reinterpret_cast<PhysicsMaterial*>(reinterpret_cast<char*>(getContactPoints()) +
                                              m_usMaxNumContactPoints * sizeof(hkContactPoint) +
                                              i * m_ucContactPointPropertiesStriding);
}

inline UInt32Value* hkpSimpleContactConstraintAtom::getContactPointPropertiesStream() const
{
    return (UInt32Value*)(getContactPoints() + m_usMaxNumContactPoints);
}

inline int hkpSimpleContactConstraintAtom::getContactPointPropertiesStriding() const
{
    return m_ucContactPointPropertiesStriding;
}

hkpSimpleContactConstraintAtom* hkpSimpleContactConstraintAtomUtil_expandOne(hkpSimpleContactConstraintAtom* atom, hkBool* atomReallocated);
void __cdecl ReplaceEntry(void* constraint, hkpSimpleContactConstraintAtom* oldAtom,
                          hkpSimpleContactConstraintAtom* newAtom, int newSize);

struct GenericConstraintAtomScheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
    void add(int schemaSize, int numSolverResults, int numSolverElemTemps)
    {
        m_iSchemaByteSize += schemaSize;
        m_iSolverResultCount += numSolverResults;
        m_iSolverElementTemporaryCount += numSolverElemTemps;
    }
};
// Exe 0x00d93140: opaque free-slot accessor on the byte IDs at data+0x0c.
struct ContactAtomIdsCallView { int ReplaceOrAppendByte(int index); };

#include "../../../../../../include/hkpSimpleContactConstraintData.h"

// Adds a contact point at index size, initializes its properties, updates constraint stats, and reallocates the atom if needed.
// @fnv 0x00d92df0
// src: HAVOK_LIB 0x00d92df0
int hkpSimpleContactConstraintData::allocateContactPoint(hkpConstraintOwner& constraintOwner, hkContactPoint** cpOut,
                                                 PhysicsMaterial** cpPropsOut)
{
    hkpSimpleContactConstraintAtom* atom = m_pAtom;
    atom->m_infoFlags |= 4;
    int size = atom->m_usNumContactPoints;

    hkpSimpleContactConstraintAtom* oldAtom = m_pAtom;
    hkBool atomReallocated = false;
    m_pAtom = hkpSimpleContactConstraintAtomUtil_expandOne(m_pAtom, &atomReallocated);
    hkpSimpleContactConstraintAtom* localAtom = m_pAtom;

    hkContactPoint* cp = &localAtom->getContactPoints()[size];
    PhysicsMaterial* cpp = localAtom->getContactPointPropertiesStream(size);
    PhysicsMaterial* pPrevProps = reinterpret_cast<PhysicsMaterial*>(reinterpret_cast<char*>(cpp) -
                                                                     localAtom->m_ucContactPointPropertiesStriding);
    PhysicsMaterial*& initTarget = cpp;
    initTarget->m_fAccumulatedImpulse = 0.0f;
    cpp->m_fImpulseLimit = 0.0f;
    cpp->m_flags = 1;
    if (size > 0 && (pPrevProps->m_flags & 2) == 0 && pPrevProps->m_usFlags == 0)
    {
        cpp->m_flags = 3;
    }
    *cpOut = cp;
    *cpPropsOut = cpp;

    {
        int newSize = size + 1;
        GenericConstraintAtomScheme info;
        info.clear();
        info.m_iMaxSchemaSize = 0xa0 + (newSize >> 1) * 0x70 + (newSize & 1) * 0x30;
        if (size == 1)
        {
            info.add(0x20, 1, 1);
        }
        if (newSize & 1)
        {
            info.add(0x30, 1, 1);
        }
        else
        {
            info.add(0x40, 1, 1);
        }
        constraintOwner.AccumulateStats(m_pHavokConstraint, info);
    }

    if (atomReallocated)
    {
        ReplaceEntry(m_pHavokConstraint, oldAtom, m_pAtom, localAtom->m_usSizeOfAllAtoms);
        m_iAtomSize = localAtom->m_usSizeOfAllAtoms;
    }
    return reinterpret_cast<ContactAtomIdsCallView*>(&m_kAtoms)->ReplaceOrAppendByte(size);
}

// Dispatch contact callbacks and prepare new contact solver state.

extern float DAT_01017870;   // 0.3f
extern float DAT_0104da48;   // HK_REAL_MAX
extern float DAT_010cc3b0;   // distance for disabled points
extern double DAT_010cc8d0;  // 1/128
extern double DAT_010cc8d8;  // -0.2
extern double DAT_0109cc78;  // 1e-10
extern double DAT_010d3dc0;  // -1.3
extern float DAT_010c7948[];

struct S00d92900_Config
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    float m_fContactRestingVelocity;
};
struct S00d92900_CollisionInput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    S00d92900_Config* m_pConfiguration;
};
struct S00d92900_World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    S00d92900_CollisionInput* m_pCollisionInput;
    const S00d92900_CollisionInput* getCollisionInput() const
    {
        return m_pCollisionInput;
    }
};
inline void hkContactPoint::setDistance(float d)
{
    m_vSeparatingNormal.w = d;
}

inline float hkContactPoint::getDistance() const
{
    return m_vSeparatingNormal.w;
}
struct S00d92900_Props
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    unsigned int m_ulUserData;
    unsigned char m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned char m_usFlags;
    unsigned char m_flags;
    float m_uiUserData;
    float getFriction() const
    {
        return DAT_010c7948[m_fSlipAngle];
    }
    float getRestitution() const
    {
        return (float)(m_fElasticity * DAT_010cc8d0);
    }
    float getMaxImpulsePerStep()
    {
        return DAT_010c7948[m_usFlags];
    }
    unsigned int* getStartOfExtendedUserData(const hkpSimpleContactConstraintAtom* atom)
    {
        return (unsigned int*)(this + 1);
    }
};
struct S00d92900_PropsStream
{
    S00d92900_Props* asProperties()
    {
        return (S00d92900_Props*)this;
    }
};

struct S00d92900_Event;
struct S00d92900_Bool
{
    char m_cBooleanValue;
    S00d92900_Bool()
    {}
    S00d92900_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct S00d92900_Body
{
    int unk00;
    int unk04;
    S00d92900_World* m_pOwningWorld;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    LocalM128 m_kInertiaAndMassInv;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    void* m_contactListenersData;
    unsigned short m_contactListenersSize;
    S00d92900_World* getWorld() const
    {
        return m_pOwningWorld;
    }
    float getMassInv() const
    {
        float r;
        _mm_store_ss(&r, _mm_shuffle_ps(m_kInertiaAndMassInv, m_kInertiaAndMassInv, 255));
        return r;
    }
};
struct S00d92900_CbReq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned short unk10;
    unsigned char m_ucCallbackRequest;
};
struct S00d92900_Instance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S00d92900_Body* m_kActorEntries[2];
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S00d92900_CbReq* m_pConstraintInternal;
    S00d92900_Body* getRigidBodyA() const
    {
        return m_kActorEntries[0];
    }
    S00d92900_Body* getRigidBodyB() const
    {
        return m_kActorEntries[1];
    }
};
struct S00d92900_Accum
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    hkVector4f m_com;
    const float* getCenterOfMassInWorld() const
    {
        return &m_com.x;
    }
};
struct S00d92900_QueryIn
{
    float m_fQueryInputValue;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S00d92900_Accum* m_pBodyA;
    S00d92900_Accum* m_pBodyB;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    S00d92900_Instance* m_pConstraintChainInstance;
};
struct S00d92900_Mgr;
struct S00d92900_Data
{
    S00d92900_Mgr* hkpSimpleContactConstraintData_getSimpleConstraintContactMgr();
};
// src: XBOX_PDB 0x00d92820
__declspec(noinline) S00d92900_Mgr* S00d92900_Data::hkpSimpleContactConstraintData_getSimpleConstraintContactMgr()
{
    return (S00d92900_Mgr*)((char*)this - 0x14);
}

struct S00d92900_CollisionEvent
{
    int m_pObservedSource;
    S00d92900_Body* m_apEntities[2];
    S00d92900_Mgr* m_pContactManager;
    S00d92900_CollisionEvent(int source, S00d92900_Body* bodyA, S00d92900_Body* bodyB, S00d92900_Mgr* mgr)
        : m_pObservedSource(source), m_pContactManager(mgr)
    {
        m_apEntities[0] = bodyA;
        m_apEntities[1] = bodyB;
    }
};
struct S00d92900_Event : S00d92900_CollisionEvent
{
    int m_type;
    hkContactPoint* m_vContactPoint;
    S00d92900_Props* m_pContactPointProperties;
    S00d92900_Bool m_bFullManifold;
    S00d92900_Bool m_bFirstCallback;
    S00d92900_Bool m_bLastCallback;
    float* m_pfSeparatingVelocity;
    float* m_pfRotationalNormal;
    unsigned int* m_puiKeyStorage;
    S00d92900_Accum* m_pVelocityAccumulatorA[2];
    S00d92900_Event(int source, S00d92900_Body* a, S00d92900_Body* b, S00d92900_Mgr* mgr, int type,
                    hkContactPoint* cp, S00d92900_Props* cpp, float* sepVel, float* rotNorm,
                    S00d92900_Bool fullManifold, S00d92900_Bool firstCallback, S00d92900_Bool lastCallback,
                    unsigned int* keyStorage, S00d92900_Accum* accA, S00d92900_Accum* accB)
        : S00d92900_CollisionEvent(source, a, b, mgr), m_type(type), m_vContactPoint(cp),
          m_pContactPointProperties(cpp), m_bFullManifold(fullManifold), m_bFirstCallback(firstCallback),
          m_bLastCallback(lastCallback), m_pfSeparatingVelocity(sepVel), m_pfRotationalNormal(rotNorm),
          m_puiKeyStorage(keyStorage)
    {
        m_pVelocityAccumulatorA[0] = accA;
        m_pVelocityAccumulatorA[1] = accB;
    }
};
struct S00d92900_CollideParams
{
    float m_fSlipAngle;
    float m_fElasticity;
    float m_usFlags;
    float m_fFirstAdditionalValue;
    float m_fSecondAdditionalValue;
    float m_fThirdAdditionalValue;
    S00d92900_Bool m_bCollisionOption;
};
struct S00d92900_Output
{
    float m_fContactImpulse;
};
struct __declspec(align(16)) S00d92900_BreachInfo
{
    unsigned short m_type;
    unsigned short m_usSecondaryField;
    S00d92900_Instance* m_pConstraintChainInstance;
    S00d92900_Props* m_kProperties;
    hkContactPoint* m_vContactPoint;
    void set(S00d92900_Instance* instance, S00d92900_Props* properties, hkContactPoint* cp, bool toi)
    {
        m_type = 1 + toi;
        m_usSecondaryField = true;
        m_pConstraintChainInstance = instance;
        m_vContactPoint = cp;
        m_kProperties = properties;
    }
};

extern float hkpSimpleContactConstraintUtil_calculateSeparatingVelocity(const S00d92900_Body* a, const S00d92900_Body* b, const float* comA, const float* comB,
                          const hkContactPoint* cp);
extern void hkpWorldCallbackUtil_fireContactPointCallback(S00d92900_World* world, S00d92900_Event& event);
extern void hkpEntityCallbackUtil_fireContactPointCallbackInternal(S00d92900_Body* entity, S00d92900_Event& event);
extern void hkMatrix3_setMul_ProcessEntries_00d9ee50(S00d92900_Data* data, const hkContactPoint& cp, S00d92900_CollideParams& params,
                         S00d92900_Body* rbA, S00d92900_Body* rbB, S00d92900_Accum* accA, S00d92900_Accum* accB,
                         S00d92900_Output& output);
extern void hkpWorldCallbackUtil_fireContactImpulseLimitBreached(S00d92900_World* world, const S00d92900_BreachInfo* info, int num);

static __forceinline void S00d92900_fireEntity(S00d92900_Body* entity, S00d92900_Event& event)
{
    if (entity->m_contactListenersSize)
    {
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(entity, event);
    }
}

static __forceinline float S00d92900_fselectGreaterZero(float testVar, float ifTrue, float ifFalse)
{
    return (testVar > 0.0f) ? ifTrue : ifFalse;
}

template <typename T> static __forceinline T* S00d92900_addByteOffset(T* base, int offset)
{
    return (T*)((char*)base + offset);
}

static __forceinline void dispatchContacts(S00d92900_Data* constraintData, const S00d92900_QueryIn* in,
                                           hkpSimpleContactConstraintAtom* atom, int type, int& bound)
{
    S00d92900_Instance* instance = in->m_pConstraintChainInstance;
    S00d92900_Body* rbA = instance->getRigidBodyA();
    S00d92900_Body* rbB = instance->getRigidBodyB();
    S00d92900_World* world = rbA->getWorld();
    S00d92900_Accum* accA = in->m_pBodyA;
    S00d92900_Accum* accB = in->m_pBodyB;
    S00d92900_Bool fireCallbacksForNewPoints = (instance->m_pConstraintInternal->m_ucCallbackRequest & 8) > 0;

    S00d92900_PropsStream* cpp = reinterpret_cast<S00d92900_PropsStream*>(atom->getContactPointPropertiesStream());
    S00d92900_PropsStream* prevCpp = 0;
    const int cppStriding = atom->getContactPointPropertiesStriding();
    hkContactPoint* cp = atom->getContactPoints();
    const int nA = atom->m_usNumContactPoints;
    __assume(nA >= 0);
    bound = nA - 1;

    for (int i = bound; i >= 0; cp++, prevCpp = cpp, cpp = S00d92900_addByteOffset(cpp, cppStriding), i--)
    {
        unsigned char& flags = cpp->asProperties()->m_flags;
        if (flags & 1)
        {
            float projectedVel = hkpSimpleContactConstraintUtil_calculateSeparatingVelocity(rbA, rbB, in->m_pBodyA->getCenterOfMassInWorld(),
                                              in->m_pBodyB->getCenterOfMassInWorld(), cp);
            {
                unsigned int* extendedUserData = cpp->asProperties()->getStartOfExtendedUserData(atom);
                S00d92900_Event event(2, rbA, rbB, constraintData->hkpSimpleContactConstraintData_getSimpleConstraintContactMgr(), type, cp, cpp->asProperties(),
                                      &projectedVel, 0, fireCallbacksForNewPoints, i == bound, i == 0, extendedUserData,
                                      accA, accB);
                hkpWorldCallbackUtil_fireContactPointCallback(world, event);
                event.m_pObservedSource = 0;
                S00d92900_fireEntity(rbA, event);
                event.m_pObservedSource = 1;
                S00d92900_fireEntity(rbB, event);
            }

            if (i < bound && prevCpp->asProperties()->m_usFlags != 0)
            {
                flags &= ~2;
            }

            if (flags & 8)
            {
                cp->setDistance(DAT_010cc3b0);
                cpp->asProperties()->m_fAccumulatedImpulse = 0.0f;
                cpp->asProperties()->m_fImpulseLimit = 0.0f;
                cpp->asProperties()->m_uiUserData = 0.0f;
            }
            else
            {
                const S00d92900_Config* config = world->getCollisionInput()->m_pConfiguration;
                const float restitution = cpp->asProperties()->getRestitution();
                const float minRestitution = DAT_01017870;
                if (projectedVel < -config->m_fContactRestingVelocity && restitution > minRestitution)
                {
                    S00d92900_CollideParams params;
                    params.m_fSlipAngle = cpp->asProperties()->getFriction();
                    params.m_fElasticity = restitution;
                    params.m_fSecondAdditionalValue = 0.0f;
                    params.m_fThirdAdditionalValue = 0.0f;
                    params.m_fFirstAdditionalValue = projectedVel;
                    params.m_usFlags = DAT_0104da48;
                    if (cpp->asProperties()->m_usFlags)
                    {
                        params.m_usFlags = cpp->asProperties()->getMaxImpulsePerStep();
                    }
                    S00d92900_Accum* bodyA = in->m_pBodyA;
                    S00d92900_Accum* bodyB = in->m_pBodyB;
                    S00d92900_Output output;
                    hkMatrix3_setMul_ProcessEntries_00d9ee50(constraintData, *cp, params, rbA, rbB, bodyA, bodyB, output);
                    S00d92900_Props* props = cpp->asProperties();
                    if (params.m_bCollisionOption)
                    {
                        S00d92900_BreachInfo bi;
                        bi.set(in->m_pConstraintChainInstance, props, cp, false);
                        hkpWorldCallbackUtil_fireContactImpulseLimitBreached(world, &bi, 1);
                    }
                    cpp->asProperties()->m_fAccumulatedImpulse = 0.0f;
                    cpp->asProperties()->m_uiUserData = 0.0f;
                }
                else
                {
                    float sumInvMass = rbA->getMassInv() + rbB->getMassInv();
                    float mass = 1.0f / (sumInvMass + DAT_0109cc78);
                    cpp->asProperties()->m_fAccumulatedImpulse =
                        mass * DAT_010cc8d8 * projectedVel * (1.0f + cpp->asProperties()->getRestitution());
                    float rhs = restitution * projectedVel * in->m_fQueryInputValue;
                    rhs = rhs * DAT_010d3dc0;
                    cpp->asProperties()->m_fImpulseLimit = rhs;
                    cpp->asProperties()->m_uiUserData =
                        S00d92900_fselectGreaterZero(restitution, cp->getDistance() + rhs, 0.0f);
                }
            }
            flags &= ~1;
        }
        else if (fireCallbacksForNewPoints)
        {
            unsigned int* extendedUserData = cpp->asProperties()->getStartOfExtendedUserData(atom);
            S00d92900_Event event(2, rbA, rbB, constraintData->hkpSimpleContactConstraintData_getSimpleConstraintContactMgr(), type, cp, cpp->asProperties(), 0, 0,
                                  true, i == bound, i == 0, extendedUserData, accA, accB);
            hkpWorldCallbackUtil_fireContactPointCallback(world, event);
            event.m_pObservedSource = 0;
            S00d92900_fireEntity(rbA, event);
            event.m_pObservedSource = 1;
            S00d92900_fireEntity(rbB, event);

            if (i < bound && prevCpp->asProperties()->m_usFlags != 0)
            {
                flags &= ~2;
            }
        }
    }
    instance->m_pConstraintInternal->m_ucCallbackRequest &= ~9;
}

// Wraps dispatchContacts to process contact points for a constraint atom, firing events and resolving collisions.
// @fnv 0x00d92900
// src: XBOX_PDB 0x00d92900
void hkSimpleContactConstraintData_fireCallbacks(S00d92900_Data* constraintData, const S00d92900_QueryIn* in, hkpSimpleContactConstraintAtom* atom, int type)
{
    int bound;
    dispatchContacts(constraintData, in, atom, type, bound);
}
