
// src/havok/physics/dynamics/collide/hkpsimpleconstraintcontactmgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/hkpsimpleconstraintcontactmgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00cfcf80 FUN_00cfcf80: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" {
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
void _mm_store_ss(float*, LocalM128);
void _mm_stream_ps(float*, LocalM128);
}

#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkContactPoint.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMatrix3.h"
#include "../../../../../include/hkMatrix4.h"
#include "../../../../../include/hkBaseObject.h"
#include "../../../../../include/hkpConstraintData.h"
#include "../../../../../include/hkpConstraintInstance.h"
#include "../../../../../include/hkpConstraintOwner.h"
#include "../../../../../include/hkpEntity.h"
#include "../../../../../include/hkSmallArray.h"
#include "../../../../../include/hkpSimpleContactConstraintAtom.h"
#include "../../../../../include/hkpSimpleConstraintContactMgr.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkpConstraintInfo.h"

// The contact-data base has reference storage at +4 and user data at +8 (12 bytes total).
__forceinline hkpConstraintData::~hkpConstraintData() throw() {}

typedef float hkReal;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

// Methods absent from the shared header use explicit-this helpers. The unused EDX
// parameter preserves the original thiscall stack arguments without a local manager class.
// @fnv 0x00cfd3f0
char* __fastcall GetSimpleContactPoint(hkpSimpleConstraintContactMgr* mgr, void*, unsigned short index)
{
    return (char*)mgr->m_kSimpleContactConstraintData.m_pAtom + 0x30 + (unsigned char)mgr->m_kSimpleContactConstraintData.m_kAtoms.m_data[index] * 32;
}

// @fnv 0x00cfcc70
int __fastcall ReserveSimpleContactPoints(hkpSimpleConstraintContactMgr* mgr, void*, int value) {
    hkpSimpleContactConstraintAtom* data = mgr->m_kSimpleContactConstraintData.m_pAtom;
    int field4 = data->m_usNumContactPoints;
    int limit = data->m_usMaxNumContactPointProperties;
    int current = mgr->m_uiContactPointCount;

    field4 += value;
    current += field4;
    limit -= 2;

    if (current > limit)
        return 1;

    mgr->m_uiContactPointCount = static_cast<unsigned short>(
        static_cast<unsigned char>(
            static_cast<unsigned char>(mgr->m_uiContactPointCount) +
            static_cast<unsigned char>(value)));
    return 0;
}

extern "C" void __cdecl ProcessCollisionEvent(void*, void*, float, void*);

// @fnv 0x00cfce30
// src: HAVOK_LIB 0x00cfce30
void __stdcall hkpSimpleConstraintContactMgr_confirmToi(void* a1, float a2, void* a3)
{
    unsigned char* p = (unsigned char*)a1;
    void* eax = *(void**)(p + 0xc);
    void* esi = *(void**)((unsigned char*)eax + 8);
    if ((p[0x27] & 8) == 0)
    {
        unsigned char al = *(unsigned char*)((unsigned char*)eax + 0xe8);
        void* edx = *(void**)(p + 0x10);
        if (al == 5 || al == 4)
        {
            unsigned char bl = *(unsigned char*)((unsigned char*)edx + 0xe8);
            if (bl == 5 || bl == 4)
                return;
        }
        ProcessCollisionEvent(esi, a1, a2, a3);
    }
}

// @fnv 0x00cfd410
unsigned char* __fastcall GetSimpleContactProperties(hkpSimpleConstraintContactMgr* mgr, void*, unsigned short index) {
    unsigned char* pIndices = mgr->m_kSimpleContactConstraintData.m_kAtoms.m_data;
    unsigned int value = pIndices[index];

    if (value == 0xff)
        return 0;

    unsigned char* base = reinterpret_cast<unsigned char*>(mgr->m_kSimpleContactConstraintData.m_pAtom);
    short signedValue = static_cast<short>(value);

    return base + 0x30
        + (*(reinterpret_cast<unsigned short*>(base + 6)) << 5)
        + (*(reinterpret_cast<unsigned char*>(base + 0xa)) * signedValue);
}

struct FUN_00cfda50_class {
    void FUN_00cfda50();
};

extern int DAT_010cc984;
extern int _DAT_0102e388;

void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(void*, void*, int);

// @fnv 0x00cfd720
__declspec(noinline) void __fastcall DestroySimpleContactManager(hkpSimpleConstraintContactMgr* mgr) {
    *(void**)mgr = (void*)&DAT_010cc984;
    if (mgr->m_kSimpleContactConstraintData.m_pAtom->m_usNumContactPoints != 0) {
        hkpWorldOperationUtil_removeConstraintImmediately(mgr->m_pOwningWorld, &mgr->m_pHavokConstraint, 1);
    }
    mgr->m_pHavokConstraint.m_kActorEntries[0] = 0;
    mgr->m_pHavokConstraint.m_kActorEntries[1] = 0;
    mgr->m_pHavokConstraint.m_data = 0;
    mgr->m_pHavokConstraint.hkpConstraintInstance::~hkpConstraintInstance();
    reinterpret_cast<FUN_00cfda50_class*>(&mgr->m_kSimpleContactConstraintData)->FUN_00cfda50();
    *(void**)mgr = (void*)&_DAT_0102e388;
}

struct FUN_00cfd7d0_class {
    unsigned char* m_00;
    unsigned int m_04;
    void DecrementBytesAboveValue(unsigned int value);
};

// For each byte in m_00 up to m_04, if the byte is not 0xff and greater than value, decrements it by one.
// @fnv 0x00cfd7d0
void FUN_00cfd7d0_class::DecrementBytesAboveValue(unsigned int auiThreshold)
{
    for (int i = (int)m_04 - 1; i >= 0; --i) {
        unsigned char c = m_00[i];
        if (c != 0xff && (int)c > (int)auiThreshold)
            --m_00[i];
    }
}

struct FUN_00cfdae0_class
{
	unsigned int m_00;
	unsigned short m_iElementCount;

	void FUN_00cfda50();
	FUN_00cfdae0_class* Destroy(unsigned char flags);
};

// @fnv 0x00cfdae0
FUN_00cfdae0_class* FUN_00cfdae0_class::Destroy(unsigned char flags)
{
	FUN_00cfda50();

	if (flags & 1)
	{
		hkMemoryRouter& manager = hkMemoryRouter::getInstance();
		unsigned short size = m_iElementCount;
		manager.heap().blockFree(this, size);
	}

	return this;
}

// @fnv 0x00cfccb0
void __fastcall ForwardSimpleContactVf40(hkpSimpleConstraintContactMgr* mgr, void* forwardedArg) {
    hkpSimpleContactConstraintData* data = &mgr->m_kSimpleContactConstraintData;
    reinterpret_cast<void (__fastcall*)(hkpSimpleContactConstraintData*, void*)>(
        (*reinterpret_cast<void***>(data))[16])(data, forwardedArg);
}

// FUN_00cfd660 : a forwarding member  (add ecx, 0x20 ; jmp <base impl>)
extern int g_sink_00cfd660;
struct First_00cfd660 {
    First_00cfd660();
    virtual void f0();
    char pad[0x1c];
};
struct Base_00cfd660 {
    Base_00cfd660();
    void target();
};
struct Derived_00cfd660 : First_00cfd660, Base_00cfd660 {
    void hkpSimpleConstraintContactMgr_getAllContactPointIds();
};
__declspec(noinline) void Base_00cfd660::target() { g_sink_00cfd660 = 1; }
// @fnv 0x00cfd660
// src: HAVOK_SRC 0x00cfd660
void Derived_00cfd660::hkpSimpleConstraintContactMgr_getAllContactPointIds() { Base_00cfd660::target(); }

extern int DAT_01268798;

// @fnv 0x00cfdad0
// src: COMMUNITY 0x00cfdad0
int* __cdecl hkpSimpleConstraintContactMgr_getClassType()
{
    return &DAT_01268798;
}

// @fnv 0x00cfcc60
char* __fastcall GetSimpleContactConstraint(hkpSimpleConstraintContactMgr* mgr, void*)
{
    return reinterpret_cast<char*>(&mgr->m_pHavokConstraint);
}

// Forwards all six arguments to the virtual method at +0x44 on the contact-data subobject.
// @fnv 0x00cfccc0
void __fastcall ForwardSimpleContactVf44(hkpSimpleConstraintContactMgr* mgr, void*, int aiArg1, float afArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6) {
    hkpSimpleContactConstraintData* data = &mgr->m_kSimpleContactConstraintData;
    reinterpret_cast<void (__thiscall*)(hkpSimpleContactConstraintData*, int, float, int, int, int, int)>(
        (*reinterpret_cast<void***>(data))[17])(data, aiArg1, afArg2, aiArg3, aiArg4, aiArg5, aiArg6);
}

struct ContactRecord {
    unsigned short flags;
    unsigned short reserved;
    void* secondInput;
    unsigned short* firstContact;
    unsigned short* secondContact;
    void* optional;
    void* owner;
    void* firstInput;
};
void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(void* handler, ContactRecord* record);
void __cdecl hkpEntityCallbackUtil_fireContactPointRemovedInternal(unsigned short* contact, ContactRecord* record);
// Builds and dispatches a ContactRecord, then processes each stored contact whose flag at index 0x102 is set.
// @fnv 0x00cfccf0
void __fastcall ProcessSimpleContactPair(hkpSimpleConstraintContactMgr* mgr, void*, void* firstInput, void* secondInput) {
    unsigned short* first = reinterpret_cast<unsigned short*>(mgr->m_pHavokConstraint.m_kActorEntries[0]);
    unsigned short* second = reinterpret_cast<unsigned short*>(mgr->m_pHavokConstraint.m_kActorEntries[1]);
    ContactRecord record;
    record.flags = 0xffff;
    record.secondInput = secondInput;
    record.firstContact = first;
    record.secondContact = second;
    record.owner = mgr;
    record.firstInput = firstInput;
    hkpWorldCallbackUtil_fireContactPointRemoved(mgr->m_pOwningWorld, &record);
    if (first[0x102]) hkpEntityCallbackUtil_fireContactPointRemovedInternal(first, &record);
    if (second[0x102]) hkpEntityCallbackUtil_fireContactPointRemovedInternal(second, &record);
}

// No shared hkpConstraintInfo definition is available yet.

// Shared m_pConstraintInternal names this record; its schema/result/temp counters are at +0x14/+0x16/+0x18.
struct ConstraintRuntimeInfo {
    char m_acUnk00[0x14];
    hkUint16 m_iSchemaByteSize;
    hkUint16 m_iSolverResultCount;
    hkUint16 m_iSolverElementTemporaryCount;
};

// The shared owner names the first word of its embedded hkpConstraintInfo only.
inline void hkpConstraintOwner::subConstraintInfo(hkpConstraintInstance* pkConstraint, hkpConstraintInfo& kDelta)
{
    hkpConstraintInfo& kInfo = reinterpret_cast<hkpConstraintInfo&>(m_iMaxSchemaSize);
    kInfo.m_iSchemaByteSize -= kDelta.m_iSchemaByteSize;
    kInfo.m_iSolverResultCount -= kDelta.m_iSolverResultCount;
    kInfo.m_iSolverElementTemporaryCount -= kDelta.m_iSolverElementTemporaryCount;
    ConstraintRuntimeInfo* pkInternal = pkConstraint->m_pConstraintInternal;
    pkInternal->m_iSolverResultCount = hkUint16(pkInternal->m_iSolverResultCount - kDelta.m_iSolverResultCount);
    pkInternal->m_iSolverElementTemporaryCount = hkUint16(pkInternal->m_iSolverElementTemporaryCount - kDelta.m_iSolverElementTemporaryCount);
    pkInternal->m_iSchemaByteSize = hkUint16(pkInternal->m_iSchemaByteSize - kDelta.m_iSchemaByteSize);
}

inline PhysicsMaterial* hkpSimpleContactConstraintAtom::getContactPointPropertiesStream(int i)
{
    return reinterpret_cast<PhysicsMaterial*>(reinterpret_cast<hkUint8*>(this + 1) +
        m_usMaxNumContactPoints * 0x20 + i * m_ucContactPointPropertiesStriding);
}

void __cdecl hkpSimpleContactConstraintAtom_RemoveContactPointAndShift(hkpSimpleContactConstraintAtom* pkAtom, int iIndex);
hkpSimpleContactConstraintAtom* __cdecl ShrinkBlockIfSparse(hkpSimpleContactConstraintAtom* pkAtom, int iNumFreeElemsLeft, hkBool& bAtomReallocated);
void __cdecl ReplaceEntry(hkpConstraintInstance* pkConstraint, hkpSimpleContactConstraintAtom* pkOldAtom, hkpSimpleContactConstraintAtom* pkNewAtom, int iNewSize);

inline hkpContactPointPropertiesCFD* hkpSimpleContactConstraintData::GetContactPointProperties(hkUint16 id)
{
    int iIndex = m_kAtoms.m_data[id];
    if (iIndex == 0xff)
        return 0;
    return reinterpret_cast<hkpContactPointPropertiesCFD*>(m_pAtom->getContactPointPropertiesStream(static_cast<hkInt16>(iIndex)));
}

// @fnv 0x00cfd200
// src: HAVOK_LIB 0x00cfd200
int hkpSimpleContactConstraintData::freeContactPoint(hkpConstraintOwner& kConstraintOwner, hkUint16 uiId)
{
    int iIndex = m_kAtoms.m_data[uiId];
    hkpSimpleContactConstraintAtom* pkAtom = m_pAtom;
    m_kAtoms.m_data[uiId] = 0xff;
    hkpConstraintInfo kConInfo;
    kConInfo.clear();
    hkpSimpleContactConstraintAtom* pkOldAtom = m_pAtom;
    hkBool bAtomReallocated = false;
    const int iNumContactPoints = pkAtom->m_usNumContactPoints;
    if (iNumContactPoints == 2)
        kConInfo.add(0x20, 1, 1);
    if (iNumContactPoints & 1)
        kConInfo.add(0x30, 1, 1);
    else
        kConInfo.add(0x40, 1, 1);

    hkpSimpleContactConstraintAtom_RemoveContactPointAndShift(pkAtom, iIndex);
    reinterpret_cast<hkUint8*>(pkAtom->getContactPointPropertiesStream(static_cast<hkInt16>(iIndex)))[0xf] &= ~2;
    pkAtom = ShrinkBlockIfSparse(m_pAtom, 1, bAtomReallocated);
    m_pAtom = pkAtom;
    ((FUN_00cfd7d0_class*)&m_kAtoms)->DecrementBytesAboveValue(iIndex);

    if (m_pHavokConstraint->m_pConstraintInternal)
        kConstraintOwner.subConstraintInfo(m_pHavokConstraint, kConInfo);
    if (bAtomReallocated) {
        ReplaceEntry(m_pHavokConstraint, pkOldAtom, m_pAtom, m_pAtom->m_usSizeOfAllAtoms);
        m_iAtomSize = m_pAtom->m_usSizeOfAllAtoms;
    }
    pkAtom->m_infoFlags |= 5;
    return iNumContactPoints - 1;
}

class hkpWorldCFD;

// No shared removed-event definition is available yet.
struct hkpContactPointRemovedEvent {
    hkUint16 m_usContactPointId;
    hkpContactPointPropertiesCFD* m_pContactPointProperties;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    int m_iUnknownValue;
    hkpSimpleConstraintContactMgr* m_pContactMgr;
    hkpConstraintOwner* m_pConstraintOwner;

    hkpContactPointRemovedEvent(hkUint16 id, hkpSimpleConstraintContactMgr* pkMgr, hkpConstraintOwner* pkOwner, hkpContactPointPropertiesCFD* pkProps, hkpEntity* pkA, hkpEntity* pkB)
        : m_usContactPointId(id), m_pContactPointProperties(pkProps), m_pEntityA(pkA), m_pEntityB(pkB), m_pContactMgr(pkMgr), m_pConstraintOwner(pkOwner) {}
};

void __cdecl hkpWorldCallbackUtil_fireContactPointRemoved(hkpWorldCFD* pkWorld, hkpContactPointRemovedEvent& kEvent) throw();
void __cdecl hkpEntityCallbackUtil_fireContactPointRemovedInternal(hkpEntity* pkEntity, hkpContactPointRemovedEvent& kEvent) throw();

// @fnv 0x00cfd320
// src: HAVOK_LIB 0x00cfd320
void hkpSimpleConstraintContactMgr::removeContactPointImpl_00cfd320(hkUint16 cpId, hkpConstraintOwner& kOwner) throw()
{
    hkpEntity* pkEntityA = m_pHavokConstraint.m_kActorEntries[0];
    hkpEntity* pkEntityB = m_pHavokConstraint.m_kActorEntries[1];
    hkpContactPointRemovedEvent kEvent(cpId, this, &kOwner, m_kSimpleContactConstraintData.GetContactPointProperties(cpId), pkEntityA, pkEntityB);
    hkpWorldCallbackUtil_fireContactPointRemoved(reinterpret_cast<hkpWorldCFD*>(m_pOwningWorld), kEvent);
    if (pkEntityA->m_kContactListeners.m_iElementCount)
        hkpEntityCallbackUtil_fireContactPointRemovedInternal(pkEntityA, kEvent);
    if (pkEntityB->m_kContactListeners.m_iElementCount)
        hkpEntityCallbackUtil_fireContactPointRemovedInternal(pkEntityB, kEvent);
    if (m_kSimpleContactConstraintData.freeContactPoint(kOwner, cpId) == 0)
        kOwner.removeConstraintFromCriticalLockedIsland(&m_pHavokConstraint);
}

class hkWorldCFD4;

class FUN_00cfd450 : public hkReferencedObject {
public:
    FUN_00cfd450(hkWorldCFD4* pkWorld);
    virtual ~FUN_00cfd450();

    hkWorldCFD4* m_pOwningWorld;
};

// @fnv 0x00cfd450
FUN_00cfd450::FUN_00cfd450(hkWorldCFD4* pkWorld)
{
    m_pOwningWorld = pkWorld;
}

extern int DAT_010cc984;

struct ContactData;
struct ContactCache
{
    unsigned int unk00;
    unsigned short mode04;
    unsigned short unk06;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    void FUN_00d92f20(ContactData* data, const unsigned char* first, const unsigned char* second);
};

struct ContactData
{
    unsigned int unk00;
    unsigned short mode04;
    unsigned short unk06;
    ContactCache* cache08;
    ContactCache* cache0C;
    unsigned int unk10;
    const unsigned char* first14;
    const unsigned char* second18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int flags34;

    void hkpConstraintInstance_hkpConstraintInstance(int enabled);
    void SetActive(unsigned short index);
};

// Initialises the contact manager: sets state, wires the cache and data pointers, looks up a table entry from the two types and applies it via SetActive.
// @fnv 0x00cfd670
hkpSimpleConstraintContactMgr* __fastcall InitSimpleContactManager(hkpSimpleConstraintContactMgr* mgr, void*, const unsigned char* first,
                                                                 const unsigned char* second,
                                                                 const unsigned char* third)
{
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&mgr->unk04) + 2) = 1;
    mgr->unk08 = 0;
    *reinterpret_cast<void**>(mgr) = &DAT_010cc984;
    reinterpret_cast<ContactCache*>(&mgr->m_kSimpleContactConstraintData)->FUN_00d92f20(reinterpret_cast<ContactData*>(&mgr->m_pHavokConstraint), second, third);
    reinterpret_cast<ContactData*>(&mgr->m_pHavokConstraint)->hkpConstraintInstance_hkpConstraintInstance(1);

    mgr->m_pHavokConstraint.m_kActorEntries[0] = reinterpret_cast<hkpEntity*>(const_cast<unsigned char*>(second));
    mgr->m_pHavokConstraint.m_data = &mgr->m_kSimpleContactConstraintData;
    mgr->m_pHavokConstraint.m_kActorEntries[1] = reinterpret_cast<hkpEntity*>(const_cast<unsigned char*>(third));
    mgr->m_pHavokConstraint.m_uiUniqueId = 0xffffffff;
    mgr->m_pOwningWorld = reinterpret_cast<hkpWorld*>(const_cast<unsigned char*>(first));
    mgr->m_usNextProcessCallbackDelay = 0;
    mgr->m_uiContactPointCount = 0;
    mgr->m_kSimpleContactConstraintData.m_usMemSizeAndFlags = 0;
    mgr->m_pHavokConstraint.m_usMemSizeAndFlags = 0;

    const unsigned char* table = *reinterpret_cast<const unsigned char* const*>(first + 0x80);
    int firstType = static_cast<signed char>(second[0x2a]);
    int secondType = static_cast<signed char>(third[0x2a]);
    int tableIndex = static_cast<signed char>(table[0x1bb0 + firstType * 10 + secondType]);
    unsigned short result = *reinterpret_cast<const unsigned short*>(table + 0x1c5c + tableIndex * 64);
    reinterpret_cast<ContactData*>(&mgr->m_pHavokConstraint)->SetActive(result);
    return mgr;
}

struct OffsetDescriptor {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char relativeOffset;
};

struct FUN_00cfd780_class {
    void* unk00;
    void* unk04;
    void* m_08;
    hkpSimpleConstraintContactMgr* AllocateContactObject(OffsetDescriptor* first, OffsetDescriptor* second, int unused);
};
// @fnv 0x00cfd780
hkpSimpleConstraintContactMgr* FUN_00cfd780_class::AllocateContactObject(OffsetDescriptor* first, OffsetDescriptor* second, int unused)
{
    void* relativeFirst = (char*)first + first->relativeOffset;
    void* relativeSecond = (char*)second + second->relativeOffset;
    hkMemoryRouter& manager = hkMemoryRouter::getInstance();
    hkpSimpleConstraintContactMgr* pContactObject = (hkpSimpleConstraintContactMgr*)manager.heap().blockAlloc(128);
    *reinterpret_cast<unsigned short*>(&pContactObject->unk04) = 128;
    // Invoke the explicit-this constructor with the original ECX/stack calling convention.
    return reinterpret_cast<hkpSimpleConstraintContactMgr* (__thiscall*)(hkpSimpleConstraintContactMgr*, void*, void*, void*)>(
        InitSimpleContactManager)(pContactObject, m_08, relativeFirst, relativeSecond);
}

namespace fnv_00cfd9f0 {

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T>
__forceinline void constructWithCopyCFD9(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

}  // namespace fnv_00cfd9f0

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <class T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& kAlloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        fnv_00cfd9f0::ResizeAudioStream(&kAlloc, this, sizeof(T));
    fnv_00cfd9f0::constructWithCopyCFD9(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}

namespace fnv_00cfd9f0 {

// distinct from hkArrayBase: mask filtering method 0x00cfd9f0 appends indices whose mask byte is not 0xff.
class hkpShapeKeyMaskCFD9 {
public:
    hkUint8* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void hkpDynamicsCpIdMgr_getAllUsedIds(hkArray<hkUint16>& kIndicesOut) const;
};

// Appends each index whose mask byte is not 0xff to kIndicesOut.
// @fnv 0x00cfd9f0
// src: HAVOK_LIB 0x00cfd9f0
void hkpShapeKeyMaskCFD9::hkpDynamicsCpIdMgr_getAllUsedIds(hkArray<hkUint16>& kIndicesOut) const
{
    for (int i = 0; i < m_iElementCount; i++) {
        if (m_data[i] != 0xff)
            kIndicesOut.pushBack((hkUint16)i);
    }
}
}  // namespace fnv_00cfd9f0

// Calls the destructor, then releases this allocation through the router heap when flags bit 0 is set.
// @fnv 0x00cfdb10
int __fastcall DeleteSimpleContactManager(hkpSimpleConstraintContactMgr* mgr, void*, unsigned char flags) {
    DestroySimpleContactManager(mgr);

    if ((flags & 1) != 0) {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        router.heap().blockFree(mgr, *reinterpret_cast<unsigned short*>(&mgr->unk04));
    }

    return (int)mgr;
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct ContactCallDescriptor {
    int kind;
    void* firstManager;
    void* secondManager;
    void* owner;
    int reservedStatus;
    void* sourceTail;
    void* sourceContact;
    unsigned char state0, state1, state2, state3;
    void* sourceHeader;
    void* forwardedArgument;
    void* sourceProperties;
    int statusA, statusB;
};
struct ContactSource {
    void* unk00;
    int unk04, unk08;
    void* firstManager;
    void* secondManager;
    int unk14, member18, unk1c, unk20, unk24, unk28, member2c;
    int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,member50;
};
extern "C" void __cdecl hkpWorldCallbackUtil_fireContactPointCallback(void*, ContactCallDescriptor*);
extern "C" void __cdecl hkpEntityCallbackUtil_fireContactPointCallbackInternal(void*, int*);
// @fnv 0x00cfcd70
void __fastcall ProcessSimpleContactContext(hkpSimpleConstraintContactMgr* mgr, void*, ContactSource* source, void* other)
{
    ContactCallDescriptor info;
    info.owner = mgr;
    info.kind = 2;
    info.firstManager = source->firstManager;
    info.secondManager = source->secondManager;
    info.reservedStatus = 0;
    info.sourceTail = &source->member50;
    info.sourceContact = &source->member18;
    info.state0 = 0;
    info.state1 = 0;
    info.state2 = 0;
    info.sourceHeader = &source->unk04;
    info.forwardedArgument = other;
    info.sourceProperties = &source->member2c;
    info.statusA = 0;
    info.statusB = 0;
    void* first = source->firstManager;
    hkpWorldCallbackUtil_fireContactPointCallback(*(void**)((char*)first + 8), &info);
    info.kind = 0;
    if (*(unsigned short*)((char*)source->firstManager + 0x204) != 0)
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(source->firstManager, &info.kind);
    info.kind = 1;
    if (*(unsigned short*)((char*)source->secondManager + 0x204) != 0)
        hkpEntityCallbackUtil_fireContactPointCallbackInternal(source->secondManager, &info.kind);
}

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

template <class T, class Allocator>
void hkStatisticsCollector::addArray(const char* pcName, const hkArray<T, Allocator>& kArray)
{
    if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_reportInplaceAllocations) {
        int iAllocated = hkStatisticsCollector_getAllocatedSize(kArray.begin(), kArray.getCapacity() * sizeof(T));
        AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
    }
}

// The pointer at +0x3c is a contact atom: +2 is its allocation size, not an agent count.
// Reports the hkpSimpleConstraintContactMgr object to the statistics collector, dispatching the atom and contact ID array.
// @fnv 0x00cfd5e0
// src: HAVOK_LIB 0x00cfd5e0
void hkpSimpleConstraintContactMgr::calcContentStatistics_00cfd5e0(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw()
{
    pkCollector->beginObject("hkpSimpleConstraintContactMgr");
    pkCollector->DispatchWithMode("ContactAtom", m_kSimpleContactConstraintData.m_pAtom, m_kSimpleContactConstraintData.m_pAtom->m_usSizeOfAllAtoms, 0);
    pkCollector->addArray("ContactIds", m_kSimpleContactConstraintData.m_kAtoms);
    pkCollector->endObject();
}

int __cdecl RoundUpToBucketSize(int iType) throw();

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& kAlloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

struct hkBlockCFDA {
    unsigned short unk00;
    unsigned short m_type;
};

class FUN_00cfda50 : public hkpConstraintData {
public:
    hkArray<char> m_buffer;
    int unk18, unk1C, unk20, unk24;
    hkBlockCFDA* m_block;

    virtual ~FUN_00cfda50() throw();
};

// Releases m_block through the shared router heap using its rounded-up bucket size.
// @fnv 0x00cfda50
FUN_00cfda50::~FUN_00cfda50() throw()
{
    hkBlockCFDA* pkBlock = m_block;
    if (pkBlock) {
        int iSize = RoundUpToBucketSize(pkBlock->m_type);
        hkMemoryRouter::getInstance().heap().blockFree(pkBlock, iSize);
    }
}

typedef unsigned short hkContactPointId;
typedef unsigned long hkUlong;

__forceinline float hkVector4::dot3scalar(const hkVector4& b) const
{
    LocalM128 p = _mm_mul_ps(m_vComponents, b.m_vComponents);
    LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
    y = _mm_add_ss(y, p);
    LocalM128 z = _mm_shuffle_ps(p, p, 0xaa);
    LocalM128 d = _mm_add_ss(z, y);
    float r;
    _mm_store_ss(&r, d);
    return r;
}

struct hkContactPt
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
    float getDistance() const { return m_vSeparatingNormal.m_vComponents.m128_f32[3]; }
};

struct hkCPProperties
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    unsigned int m_uiUserData;
    unsigned char m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned short m_usFlags;
    float m_unk10;
    float getRestitution() const { return m_fElasticity * (1.0f / 128.0f); }
};

struct hkProcessCollisionInputStub
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068;unsigned char unk06c;
    char m_flag6d;
};

struct hkProcessCollisionOutputStub
{
    void* m_unk00;
    hkpConstraintOwner* m_pConstraintOwner;
};



struct hkRigidBodyStub
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c; unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17c; unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18c; unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19c; unsigned int unk1a0; unsigned int unk1a4; unsigned int unk1a8; unsigned int unk1ac; unsigned int unk1b0; unsigned int unk1b4; unsigned int unk1b8; unsigned int unk1bc; unsigned int unk1c0; unsigned int unk1c4; unsigned int unk1c8; unsigned int unk1cc; unsigned int unk1d0; unsigned int unk1d4; unsigned int unk1d8; unsigned int unk1dc; unsigned int unk1e0; unsigned int unk1e4; unsigned int unk1e8; unsigned int unk1ec; unsigned int unk1f0; unsigned int unk1f4; unsigned int unk1f8; unsigned int unk1fc;
    hkSmallArray<void*> m_kContactListeners;

    void hkpRigidBody_getPointVelocity(const hkVector4& p, hkVector4& vecOut) const;
    float ProcessAndReturnValue_00cac860() const;
};

struct hkContactPointAddedEventStub
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    int m_iResultCode;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    unsigned short m_unk30;
    unsigned short m_usNextProcessCallbackDelay;

    hkContactPointAddedEventStub(hkContactPointId id, void* mgr, const hkProcessCollisionInputStub* input,
        hkProcessCollisionOutputStub* output, const hkCdBodyStub* a, const hkCdBodyStub* b, hkContactPt* cp,
        const hkGskCacheStub* gskCache, hkCPProperties* cpProp, float projectedVelocity);
};

void __cdecl hkpWorldCallbackUtil_fireContactPointAdded(void* world, hkContactPointAddedEventStub& event);
void __cdecl hkpEntityCallbackUtil_fireContactPointAddedInternal(hkRigidBodyStub* entity, hkContactPointAddedEventStub& event);

template <class T>
inline T* hkSelectOther(T* a, T* pairA, T* pairB)
{
    return (T*)(hkUlong(a) ^ hkUlong(pairA) ^ hkUlong(pairB));
}

// @fnv 0x00cfcf80
// src: HAVOK_SRC 0x00cfcf80
hkContactPointId hkpSimpleConstraintContactMgr::addContactPointImpl(const hkCdBodyStub& a, const hkCdBodyStub& b,
    const hkProcessCollisionInputStub& input, hkProcessCollisionOutputStub& output,
    const hkGskCacheStub* contactCache, hkContactPt& cp)
{
    int numContactPoints = m_kSimpleContactConstraintData.m_pAtom->m_usNumContactPoints;
    if (m_uiContactPointCount + numContactPoints > m_kSimpleContactConstraintData.m_pAtom->m_usMaxNumContactPointProperties - 2)
    {
        return 0xffff;
    }

    if (numContactPoints == 0)
    {
        output.m_pConstraintOwner->addConstraintToCriticalLockedIsland((hkpConstraintInstance*)&m_pHavokConstraint);
    }

    hkCPProperties* cpi;
    hkContactPointId id;
    {
        hkContactPt* dcp;
        hkpConstraintOwner* owner = output.m_pConstraintOwner;
        id = m_kSimpleContactConstraintData.allocateContactPoint(*owner, &dcp, &cpi);
        *dcp = cp;
    }

    hkRigidBodyStub* rbA = setContactPointProperties(a, b, 10000, cpi);
    hkRigidBodyStub* rbB = hkSelectOther(rbA, reinterpret_cast<hkRigidBodyStub*>(m_pHavokConstraint.m_kActorEntries[0]), reinterpret_cast<hkRigidBodyStub*>(m_pHavokConstraint.m_kActorEntries[1]));

    hkVector4 velA;
    hkVector4 velB;
    rbA->hkpRigidBody_getPointVelocity(cp.m_vContactPosition, velA);
    rbB->hkpRigidBody_getPointVelocity(cp.m_vContactPosition, velB);

    hkVector4 relVel;
    relVel.setSub4(velA, velB);
    float projectedVel = relVel.dot3scalar(cp.m_vSeparatingNormal);

    cpi->m_fAccumulatedImpulse = 0.0f;
    cpi->m_uiUserData = 0;

    hkContactPointAddedEventStub event(id, this, &input, &output, &a, &b, &cp, contactCache, cpi, projectedVel);
    hkpWorldCallbackUtil_fireContactPointAdded(m_pOwningWorld, event);
    if (rbA->m_kContactListeners.getSize())
    {
        hkpEntityCallbackUtil_fireContactPointAddedInternal(rbA, event);
    }
    if (rbB->m_kContactListeners.getSize())
    {
        hkpEntityCallbackUtil_fireContactPointAddedInternal(rbB, event);
    }

    if (event.m_iResultCode == 1)
    {
        removeContactPointImpl(id, output.m_pConstraintOwner);
        return 0xffff;
    }

    m_usNextProcessCallbackDelay = event.m_usNextProcessCallbackDelay;

    if (input.m_flag6d && cpi->getRestitution() == 0.0f
        && rbA->m_kContactListeners.getSize() <= 0 && rbB->m_kContactListeners.getSize() <= 0)
    {
        float invMassB = rbB->ProcessAndReturnValue_00cac860();
        float invMassSum = rbA->ProcessAndReturnValue_00cac860() + invMassB;
        float f = 1.0f / (invMassSum + 1e-10f);
        cpi->m_fAccumulatedImpulse = f * -0.2f * projectedVel;
        cpi->m_fImpulseLimit = 0.0f;
        cpi->m_unk10 = cp.getDistance();
    }
    else
    {
        output.m_pConstraintOwner->addCallbackRequest(m_kSimpleContactConstraintData.m_pHavokConstraint, 1);
    }
    return id;
}

#include <math.h>
struct hkUFloat8q {
    unsigned char m_uiFilterValue;
    hkUFloat8q& operator=(const float& fv);
};

struct hkpMaterialq {
    int m_eResponseType;
    hkReal m_fSlipAngle;
    hkReal m_fElasticity;
};

struct RigidBodyq {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88;
    hkpMaterialq m_iMaterialIndex;
};

struct CdBodyQ;
struct CollidableQ {
    int unk00; int unk04; int unk08; int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const { return (void*)((char*)this + m_iOwnerOffset); }
};

struct CdBodyQ {
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    CdBodyQ* m_parent;
    const CdBodyQ* getParent() const { return m_parent; }
    const CollidableQ* getRootCollidable() const { const CdBodyQ* r = this; while (r->m_parent) r = r->m_parent; return reinterpret_cast<const CollidableQ*>(r); }
};

struct ContactPropsQ {
    int unk00; int unk04; int unk08;
    hkUFloat8q m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned char m_usFlags;
    unsigned char m_flags;
    int unk10;
    int m_aiContactData[1];
    void setRestitution(hkReal r) { m_fElasticity = (unsigned char)fnv_FloatToInt((float)(r * 128.0)); }
};

struct CollisionFilterInfoQ {
    int unk00; int unk04;
    unsigned char m_numA;
    unsigned char m_numB;
};

// @fnv 0x00cfd800
// src: HAVOK_LIB 0x00cfd800
hkRigidBodyStub* hkpSimpleConstraintContactMgr::setContactPointProperties(const hkCdBodyStub& bodyAInput, const hkCdBodyStub& bodyBInput, int maxNum, hkCPProperties* properties)
{
    const CdBodyQ& a = reinterpret_cast<const CdBodyQ&>(bodyAInput);
    const CdBodyQ& b = reinterpret_cast<const CdBodyQ&>(bodyBInput);
    ContactPropsQ* cpi = reinterpret_cast<ContactPropsQ*>(properties);
    RigidBodyq* rba = reinterpret_cast<RigidBodyq*>(m_pHavokConstraint.m_kActorEntries[0]);
    RigidBodyq* rbb = reinterpret_cast<RigidBodyq*>(m_pHavokConstraint.m_kActorEntries[1]);
    cpi->m_fSlipAngle = sqrt(rbb->m_iMaterialIndex.m_fSlipAngle * rba->m_iMaterialIndex.m_fSlipAngle);
    cpi->setRestitution(sqrt(rbb->m_iMaterialIndex.m_fElasticity * rba->m_iMaterialIndex.m_fElasticity));
    cpi->m_usFlags = 0;

    void* bodyA = a.getRootCollidable()->getOwner();

    CollisionFilterInfoQ* info = reinterpret_cast<CollisionFilterInfoQ*>(m_kSimpleContactConstraintData.m_pAtom);
    int numB = info->m_numB;
    int numA = info->m_numA;
    int* ext = cpi->m_aiContactData;
    if (numA + numB == 0) return reinterpret_cast<hkRigidBodyStub*>(bodyA);

    const CdBodyQ* first;
    const CdBodyQ* second;
    if (bodyA == rba) { first = &a; second = &b; }
    else { first = &b; second = &a; bodyA = rbb; }

    if (numA >= maxNum) numA = maxNum;
    int rem = maxNum - numA;
    if (numB >= rem) numB = rem;

    int* dest = &ext[numA];
    if (first->m_uiCollisionShapeKey == -1 && first->m_parent) first = first->m_parent;
    {
        for (int i = 0; first && i < numA; i++) {
            ext[i] = first->m_uiCollisionShapeKey;
            first = first->m_parent;
        }
    }
    if (second->m_uiCollisionShapeKey == -1 && second->m_parent) second = second->m_parent;
    {
        for (int i = 0; second && i < numB; i++) {
            dest[i] = second->m_uiCollisionShapeKey;
            second = second->m_parent;
        }
    }
    return reinterpret_cast<hkRigidBodyStub*>(bodyA);
}

inline hkContactPoint& hkContactPoint::operator=(const hkContactPoint& cp)
{
    m_vContactPosition.m_vComponents = cp.m_vContactPosition.m_vComponents;
    m_vSeparatingNormal.m_vComponents = cp.m_vSeparatingNormal.m_vComponents;
    return *this;
}

namespace fnv_00cfd950 {

static __forceinline void memCpy4(void* dst, const void* src, int numWords)
{
    const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    for (int i = 0; i < numWords; i++)
    {
        *(dst32++) = *(src32++);
    }
}

// Removes the contact point at iIndex from pkAtom by shifting later contact points and their properties down and decrementing m_usNumContactPoints.
// @fnv 0x00cfd950
// src: GUESS 0x00cfd950 (confidence: high)
void __cdecl hkpSimpleContactConstraintAtom_RemoveContactPointAndShift(hkpSimpleContactConstraintAtom* pkAtom, int iIndex)
{
    int numContactPoints = pkAtom->m_usNumContactPoints - 1;
    pkAtom->m_usNumContactPoints = hkUint16(numContactPoints);
    hkContactPoint* cp = reinterpret_cast<hkContactPoint*>(pkAtom + 1) + iIndex;
    int striding = pkAtom->m_ucContactPointPropertiesStriding;
    hkUint8* cpp = reinterpret_cast<hkUint8*>(reinterpret_cast<hkContactPoint*>(pkAtom + 1) + pkAtom->m_usMaxNumContactPoints)
        + hkInt16(iIndex) * hkInt16(striding);

    for (int i = iIndex; i < numContactPoints; i++)
    {
        cp[0] = cp[1];
        hkUint8* nextCpp = cpp + striding;
        memCpy4(cpp, nextCpp, striding >> 2);
        cp++;
        cpp = nextCpp;
    }
}
}  // namespace fnv_00cfd950

struct Obj { unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c; unsigned unk150; unsigned unk154; unsigned unk158; unsigned unk15c; unsigned unk160; unsigned unk164; unsigned unk168; unsigned unk16c; unsigned unk170; unsigned unk174; unsigned unk178; unsigned unk17c; unsigned unk180; unsigned unk184; unsigned unk188; unsigned unk18c; unsigned unk190; unsigned unk194; unsigned unk198; unsigned unk19c; unsigned unk1a0; unsigned unk1a4; unsigned unk1a8; unsigned unk1ac; unsigned unk1b0; unsigned unk1b4; unsigned unk1b8; unsigned unk1bc; unsigned unk1c0; unsigned unk1c4; unsigned unk1c8; unsigned unk1cc; unsigned unk1d0; unsigned unk1d4; unsigned unk1d8; unsigned unk1dc; unsigned unk1e0; unsigned unk1e4; unsigned unk1e8; unsigned unk1ec; unsigned unk1f0; unsigned unk1f4; unsigned unk1f8; unsigned unk1fc; unsigned unk200; unsigned short m204; };
struct EventBase { int a1; int a2; int z18; int u1c; int a6; int a7; int a7b; float f; int result; void* self; EventBase(int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9, void* owner) : a1(a1), a2(a2), z18(0), a6(a6), a7(a7), a7b(a9), f(*a8), self(owner) {} };
struct Ctx : EventBase { int a3; int* a4; float a5; Ctx(int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9, void* owner) : EventBase(a1,a2,a3,a4,a5,a6,a7,a8,a9,owner) , a3(a3), a4(a4), a5(a5) {} };
void __cdecl hkpWorldCallbackUtil_fireContactPointAdded(void*, Ctx*);
void __cdecl hkpEntityCallbackUtil_fireContactPointAddedInternal(Obj*, Ctx*);
// Dispatches an event to the world and bodies with listeners; a rejected event calls virtual slot 8, otherwise the projected velocity is updated.
// @fnv 0x00cfce80
int __fastcall ProcessSimpleContactEvent(hkpSimpleConstraintContactMgr* mgr, void*, int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9) {
    Obj* o = reinterpret_cast<Obj*>(mgr->setContactPointProperties(*reinterpret_cast<const hkCdBodyStub*>(a1), *reinterpret_cast<const hkCdBodyStub*>(a2), 7, reinterpret_cast<hkCPProperties*>(a9)));
    Obj* p = (Obj*)((unsigned)o ^ (unsigned)mgr->m_pHavokConstraint.m_kActorEntries[0] ^ (unsigned)mgr->m_pHavokConstraint.m_kActorEntries[1]);
    Ctx c(a1,a2,a3,a4,a5,a6,a7,a8,a9,mgr);
    c.result = 0;
    hkpWorldCallbackUtil_fireContactPointAdded(mgr->m_pOwningWorld, &c);
    if (o->m204) hkpEntityCallbackUtil_fireContactPointAddedInternal(o, &c);
    if (p->m204) hkpEntityCallbackUtil_fireContactPointAddedInternal(p, &c);
    if (c.result == 1) reinterpret_cast<void (__thiscall*)(hkpSimpleConstraintContactMgr*, int, int)>((*reinterpret_cast<void***>(mgr))[8])(mgr, a4[1], a9);
    else *a8 = c.f;
    return c.result;
}

struct CfdInfoItem {
    LocalM128 m_v0;
    LocalM128 m_v1;
    unsigned char* m_table;
    int unk24;
    int unk28;
    int unk2c;
};

struct CfdSolver {
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(void* data, int flags);
};

struct CfdInfo {
    CfdInfoItem* m_kRayEnd;
    CfdSolver* m_pSolver;
    int unk08;
    int unk0c;
    CfdInfoItem m_items[1];
};

struct CfdEntity {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_motionOffset;
};

struct CfdBody {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4;
    unsigned short unk0a8;
    unsigned short m_uiItemCount;
    int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8;
    int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8;
    int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108;
    int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128;
    int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148;
    int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168;
    int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188;
    int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8;
    int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8;
    int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8;
    int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200;
    unsigned short m_numJac;
};

template <class T> inline T CfdMin(T a, T b) { return a < b ? a : b; }

struct CfdParams {
    CfdEntity* m_kPointA;
    CfdEntity* m_kPointB;
    int unk08;
    CfdInfo* m_info;
    void* m_ptrs[256];
    hkpSimpleConstraintContactMgr* m_pOwnerObject;
};

extern "C" void __cdecl NotifyShapeSetListeners(void* a, CfdParams* p);
extern "C" void __cdecl hkpEntityCallbackUtil_fireContactProcessInternal(void* a, CfdParams* p);

// When the callback delay expires, dispatches the contact event; then updates the delay and streams the contact vectors into the atom.
// @fnv 0x00cfd470
void __fastcall ProcessSimpleContactPoints(hkpSimpleConstraintContactMgr* mgr, void*, CfdEntity* apEntityA, CfdEntity* apEntityB, int unused, CfdInfo* info)
{
    int newCount = mgr->m_usNextProcessCallbackDelay;
    if (newCount-- == 0) {
        CfdBody* bodyA = (CfdBody*)((char*)apEntityA + apEntityA->m_motionOffset);
        CfdBody* bodyB = (CfdBody*)((char*)apEntityB + apEntityB->m_motionOffset);
        newCount = CfdMin(bodyA->m_uiItemCount, bodyB->m_uiItemCount);
        CfdParams params;
        params.m_kPointA = apEntityA;
        params.m_kPointB = apEntityB;
        params.m_info = info;
        params.m_pOwnerObject = mgr;
        CfdInfoItem* end = info->m_kRayEnd;
        void** out = params.m_ptrs;
        for (CfdInfoItem* pItem = info->m_items; pItem < end; pItem++) {
            int idx = pItem->m_table[(int)mgr->m_kSimpleContactConstraintData.m_kAtoms.m_data];
            void* ptr;
            if (idx == 0xff) {
                ptr = 0;
            } else {
                hkpSimpleContactConstraintAtom* h = mgr->m_kSimpleContactConstraintData.m_pAtom;
                ptr = (char*)h + (short)idx * h->m_ucContactPointPropertiesStriding + h->m_usMaxNumContactPoints * 32 + 0x30;
            }
            *out++ = ptr;
        }
        NotifyShapeSetListeners(mgr->m_pOwningWorld, &params);
        if (bodyA->m_numJac != 0) hkpEntityCallbackUtil_fireContactProcessInternal(bodyA, &params);
        if (bodyB->m_numJac != 0) hkpEntityCallbackUtil_fireContactProcessInternal(bodyB, &params);
        info->m_pSolver->method14(mgr->m_kSimpleContactConstraintData.m_pHavokConstraint, 8);
    }
    mgr->m_usNextProcessCallbackDelay = newCount;
    CfdInfoItem* end = info->m_kRayEnd;
    for (CfdInfoItem* pItem = info->m_items; pItem < end; pItem++) {
        float* dst = (float*)((char*)mgr->m_kSimpleContactConstraintData.m_pAtom + pItem->m_table[(int)mgr->m_kSimpleContactConstraintData.m_kAtoms.m_data] * 32 + 0x30);
        _mm_stream_ps(dst, pItem->m_v0);
        _mm_stream_ps(dst + 4, pItem->m_v1);
    }
}
