
// src/havok/common/base/object/hkreferencedobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/object/hkreferencedobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkReferencedObjectLock.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/NiStream.h"
#include "../../../../../include/NiBinaryStream.h"

// @fnv 0x00c903b0
__declspec(noinline) void __fastcall ReleaseUnserializedReference(hkReferencedObject* object)
{
    if (object->m_usMemSizeAndFlags)
    {
        --object->m_sReferenceCount;
        if (!object->m_sReferenceCount)
            ((void(__thiscall*)(void*, int))(*(void***)object)[0])(object, 1);
    }
}

// @fnv 0x00c903a0
__declspec(noinline) void __fastcall AddUnserializedReference(hkReferencedObject* object)
{
    if (object->m_usMemSizeAndFlags)
        object->m_sReferenceCount++;
}

extern int DAT_012681d4;
// @fnv 0x00c90410
// src: HAVOK_LIB 0x00c90410
void __cdecl hkReferencedObject_setLockMode(int v)
{
    *(int*)(*(int**)(void*)&DAT_012681d4 + 2) = v;
}

extern int DAT_0102e388;

// @fnv 0x00c903d0
// src: GUESS 0x00c903d0 (confidence: low)
int* __cdecl hkReferencedObject_GetDAT0102e388Address()
{
    return &DAT_0102e388;
}

struct DDCC60World
{
    void removeReference();
};
struct RefObj
{
    void RetainReference();
};
struct FUN_00cd29c0_class
{
    void hkpWorldObject_setAiObjectData(RefObj*);
};
// @fnv 0x00cd29c0
// src: HAVOK_LIB 0x00cd29c0
void FUN_00cd29c0_class::hkpWorldObject_setAiObjectData(RefObj* object)
{
    object->RetainReference();
    DDCC60World* pOldWorld = *reinterpret_cast<DDCC60World**>(reinterpret_cast<unsigned char*>(this) + 0x84);
    if (pOldWorld)
        pOldWorld->removeReference();
    *reinterpret_cast<RefObj**>(reinterpret_cast<unsigned char*>(this) + 0x84) = object;
}

struct FUN_00cdf6e0_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    char m_auiShapeKeys[4];
    hkReferencedObject* m_pObject;
    void SetReferencedObject(hkReferencedObject* pObject);
};

// @fnv 0x00cdf6e0
void FUN_00cdf6e0_class::SetReferencedObject(hkReferencedObject* pObject)
{
    hkReferencedObject* pNewRef = pObject;
    if (pNewRef)
        pNewRef->addReference();
    hkReferencedObject* pOldRef = m_pObject;
    if (pOldRef)
        pOldRef->removeReference();
    m_pObject = pObject;
}

namespace fnv_00d47750 {
struct RefObj
{
    void FUN_00c90510();
};

struct FUN_00d47750_class
{
    RefObj* m_pObject;

    FUN_00d47750_class* AssignObject(RefObj** pObject);
};

// @fnv 0x00d47750
FUN_00d47750_class* FUN_00d47750_class::AssignObject(RefObj** pObject)
{
    RefObj* object = *pObject;
    if (object)
        object->FUN_00c90510();

    m_pObject = object;
    return this;
}
}  // namespace fnv_00d47750

namespace fnv_00dee6f0 {
struct RefObj
{
    void FUN_00c90510();
};
struct RefObj2
{
    void FUN_00c905b0();
};
struct FUN_00dee6f0_class
{
    void* m_pVTable;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    RefObj* m_pObject;
    void hkpPointToPathConstraintData_setPath(RefObj* pObject);
};
// @fnv 0x00dee6f0
// src: COMMUNITY 0x00dee6f0
void FUN_00dee6f0_class::hkpPointToPathConstraintData_setPath(RefObj* pNewObject)
{
    if (pNewObject)
        pNewObject->FUN_00c90510();
    if (m_pObject)
        ((RefObj2*)m_pObject)->FUN_00c905b0();
    m_pObject = pNewObject;
}
}  // namespace fnv_00dee6f0

namespace fnv_00e3e840 {
struct FUN_00d1df70
{
    void RetainReference();
};

struct DDCC60World : public FUN_00d1df70
{
    void removeReference();
};

struct FUN_00e3e840_data
{
    DDCC60World* m_pWorld;
    int m_value0;
    int m_value1;
};

struct FUN_00e3e840_result
{
    DDCC60World* m_pWorld;

    void AssignObject(int* value);
};

struct FUN_00e5c4d0_class
{
    void FindOrCreateEntryReference(FUN_00e3e840_data* data, int key);
};

struct FUN_00e3e840_class
{
    void* m_pUnknown0;
    void* m_pUnknown1;
    unsigned char* m_pItems;
    int m_uiItemCount;

    FUN_00e3e840_result* FindWorldByKey(FUN_00e3e840_result* result, int key);
};

// @fnv 0x00e3e840
FUN_00e3e840_result* FUN_00e3e840_class::FindWorldByKey(FUN_00e3e840_result* result, int key)
{
    FUN_00e3e840_data data;

    if (key != 0)
    {
        int index = 0;

        if (m_uiItemCount > 0)
        {
            int offset = 0;

            do
            {
                reinterpret_cast<FUN_00e5c4d0_class*>(m_pItems + offset)->FindOrCreateEntryReference(&data, key);

                if (data.m_pWorld)
                {
                    data.m_pWorld->RetainReference();
                    result->m_pWorld = data.m_pWorld;
                    if (data.m_pWorld)
                        data.m_pWorld->removeReference();
                    return result;
                }

                data.m_pWorld = 0;
                ++index;
                offset += 16;
            } while (index < m_uiItemCount);
        }
    }

    data.m_value0 = 0;
    data.m_value1 = 0;
    result->AssignObject(&data.m_value0);
    return result;
}
}  // namespace fnv_00e3e840

extern int DAT_012681d4;

// @fnv 0x00c90480
// src: COMMUNITY 0x00c90480
int __cdecl hkReferencedObject_getLockMode()
{
    return *(int*)(DAT_012681d4 + 8);
}

struct ThreadMode_9bf0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int m_currentMode;
};
__declspec(thread) ThreadMode_9bf0 tls_9bf0;
struct Object_9bf0
{
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct Owner_9bf0
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    Object_9bf0* m_object;
    void UpdateState_00c89bf0(Object_9bf0* next);
};
struct RestoreMode_9bf0
{
    unsigned int original;
    RestoreMode_9bf0() : original(tls_9bf0.m_currentMode)
    {
        tls_9bf0.m_currentMode = 0x10;
    }
    ~RestoreMode_9bf0()
    {
        tls_9bf0.m_currentMode = original;
    }
};
// @fnv 0x00c89bf0
// src: GUESS 0x00c89bf0 (confidence: low)
void Owner_9bf0::UpdateState_00c89bf0(Object_9bf0* apObject)
{
    RestoreMode_9bf0 scoped;
    if (apObject)
        apObject->FUN_00c90510();
    if (m_object)
        m_object->FUN_00c905b0();
    m_object = apObject;
}

namespace hkRouterC904 {
// Shared router layout: the heap allocator used by 0x00c85750 is at +0x10.
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance() throw();
}


inline void* hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkRouterC904::hkMemoryRouter_getInstance().heap().blockAlloc(nbytes));
    b->m_usMemSizeAndFlags = (unsigned short)nbytes;
    return b;
}

// @fnv 0x00c903e0
void CreateAndInitObj()
{
    new hkReferencedObjectLock();
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long index, void* value);
extern int DAT_012681d4;
extern int DAT_012681d8;

// Increments the TLS-guarded counter if the TLS slot holds the sentinel, otherwise enters the critical section, resets the counter to 1 and sets the TLS slot.
// @fnv 0x00c90490
void __cdecl EnterTlsGuard()
{
    hkReferencedObjectLock* st = reinterpret_cast<hkReferencedObjectLock*>(DAT_012681d4);
    if ((int)TlsGetValue(DAT_012681d8) == 0x23df4554)
    {
        st->m_lLockCount++;
        return;
    }
    EnterCriticalSection(&st->m_kCriticalSection);
    st->m_lLockCount = 1;
    TlsSetValue(DAT_012681d8, (void*)0x23df4554);
}

extern int DAT_012681d4;

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long dwTlsIndex, void* pvValue);

// @fnv 0x00c905b0
void hkReferencedObject::removeReference() const
{
    if (m_usMemSizeAndFlags != 0)
    {
        if (m_sReferenceCount == 1)
        {
            m_sReferenceCount = 0;
            delete this;
            return;
        }
        hkReferencedObjectLock* pkLock = reinterpret_cast<hkReferencedObjectLock*>(DAT_012681d4);
        const unsigned long& kTls = reinterpret_cast<const unsigned long*>(&DAT_012681d4)[1];
        if (pkLock->m_multiThreaded == 1 && TlsGetValue(kTls) != reinterpret_cast<void*>(0x23df4554))
        {
            if (TlsGetValue(kTls) == reinterpret_cast<void*>(0x23df4554))
            {
                pkLock->m_lLockCount++;
            }
            else
            {
                EnterCriticalSection(&pkLock->m_kCriticalSection);
                pkLock->m_lLockCount = 1;
                TlsSetValue(kTls, reinterpret_cast<void*>(0x23df4554));
            }
            m_sReferenceCount--;
            if (--pkLock->m_lLockCount <= 0)
            {
                TlsSetValue(kTls, 0);
                LeaveCriticalSection(&pkLock->m_kCriticalSection);
            }
        }
        else
        {
            m_sReferenceCount--;
        }
    }
}

struct ObjectRef
{
    void FUN_00c90510();
    void FUN_00c905b0();
};
extern __declspec(thread) int g_threadFlag;
struct ThreadFlagGuard
{
    int previousFlag;
    ThreadFlagGuard() : previousFlag(g_threadFlag)
    {
        g_threadFlag = 16;
    }
    ~ThreadFlagGuard()
    {
        g_threadFlag = previousFlag;
    }
};
struct FUN_00ca9b40_class
{
    void** m_pVTable;
    short m_uiObjectFlags;
    short m_uCount;
    int m_extraneousState;
    ObjectRef* m_pObject;
    void UpdateFields_00ca9b40(ObjectRef* pObject);
};
// @fnv 0x00ca9b40
// src: GUESS 0x00ca9b40 (confidence: low)
void FUN_00ca9b40_class::UpdateFields_00ca9b40(ObjectRef* pObject)
{
    ThreadFlagGuard guard;
    if (pObject)
        pObject->FUN_00c90510();
    if (m_pObject)
        m_pObject->FUN_00c905b0();
    m_pObject = pObject;
}

struct DeviceCallback
{
    int unk00;
    int m_total;
    int(__cdecl* m_callback)(DeviceCallback*, void*, int, int*, int);
    __forceinline void Process(void* p)
    {
        int size = 4;
        m_total += m_callback(this, p, 4, &size, 1);
    }
};
struct Resource
{
    void FUN_00c905b0();
};
struct DeviceOwner;
struct DeviceSubobject
{
    void hkpBridgeConstraintAtom_init(DeviceOwner*);
};
struct DeviceOwner
{
    int unk00, unk04, unk08, unk0c;
    DeviceSubobject m_subobject;
    int unk14, unk18, m_payload;
    void UpdateFields_00ca9b40(Resource*);
};
struct InputObject
{
    DeviceCallback* GetCallback() const
    {
        return *reinterpret_cast<DeviceCallback* const*>(reinterpret_cast<const char*>(this) + 0x24c);
    }
};
Resource* __cdecl bhkConstraintManager_LoadBinary(InputObject*);
struct FUN_00ca9ce0_class
{
    int unk00;
    DeviceOwner* m_pOwnerObject;
    void hkConstraintCinfo_LoadBinary(InputObject*);
    void ProcessInput(InputObject*);
};
// @fnv 0x00ca9ce0
void FUN_00ca9ce0_class::ProcessInput(InputObject* input)
{
    hkConstraintCinfo_LoadBinary(input);
    DeviceOwner* owner = m_pOwnerObject;
    Resource* resource = bhkConstraintManager_LoadBinary(input);
    owner->UpdateFields_00ca9b40(resource);
    owner->m_subobject.hkpBridgeConstraintAtom_init(owner);
    resource->FUN_00c905b0();
    DeviceCallback* callback = input->GetCallback();
    callback->Process(&owner->m_payload);
}

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

template <class T> struct hkRefPtrE3EE
{
    T* m_pRetainedObject;

    hkRefPtrE3EE(const hkRefPtrE3EE& rp) throw()
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtrE3EE() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
    }
    void operator=(T* e) throw()
    {
        if (e)
            e->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = e;
    }
    void operator=(const hkRefPtrE3EE& rp) throw()
    {
        if (this != &rp)
            *this = rp.m_pRetainedObject;
    }
};

struct HeapEntryE3EE
{
    hkRefPtrE3EE<FUN_00d1df70> m_object;
    int m_primary;
    int m_secondary;
};

struct HeapLessE3EE
{
    bool operator()(const HeapEntryE3EE& kA, const HeapEntryE3EE& kB) const
    {
        return kB.m_primary > kA.m_primary || (kA.m_primary == kB.m_primary && kA.m_secondary < kB.m_secondary);
    }
};

// Restores the heap property by sifting the entry at index k down through the array using cmpLess.
// @fnv 0x00e3eec0
void __cdecl SiftDownHeap(HeapEntryE3EE* apEntries, int aiIndex, int aiCount, HeapLessE3EE aCompare)
{
    HeapEntryE3EE entryTemp = apEntries[aiIndex - 1];
    while (aiIndex <= aiCount / 2)
    {
        int child = 2 * aiIndex;
        if ((child < aiCount) && aCompare(apEntries[child - 1], apEntries[child]))
            child++;
        if (aCompare(entryTemp, apEntries[child - 1]))
        {
            apEntries[aiIndex - 1] = apEntries[child - 1];
            aiIndex = child;
        }
        else
        {
            break;
        }
    }
    apEntries[aiIndex - 1] = entryTemp;
}

struct Ref_00c89b60
{
    void __thiscall FUN_00c90510();
    void __thiscall FUN_00c905b0();
};

struct Tls_00c89b60
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
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
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
};

extern __declspec(thread) Tls_00c89b60 tls_00c89b60;

struct Scope_00c89b60
{
    int saved;
    Scope_00c89b60()
    {
        saved = tls_00c89b60.unk2b4;
        tls_00c89b60.unk2b4 = 0x10;
    }
    ~Scope_00c89b60()
    {
        tls_00c89b60.unk2b4 = saved;
    }
};

struct Obj_00c89b60
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Ref_00c89b60* m_pReference;
    void __thiscall SetRetainedReference(Ref_00c89b60* r);
};

// Sets m_pReference to r, calling FUN_00c90510 on the new reference and FUN_00c905b0 on the old one if present.
// @fnv 0x00c89b60
// src: GUESS 0x00c89b60 (confidence: medium)
void __thiscall Obj_00c89b60::SetRetainedReference(Ref_00c89b60* apReference)
{
    Scope_00c89b60 s;
    if (apReference)
        apReference->FUN_00c90510();
    if (m_pReference)
        m_pReference->FUN_00c905b0();
    m_pReference = apReference;
}

namespace hkSingletonC904 {
extern hkReferencedObjectLock* DAT_012681d4;
}

static inline void replaceInstanceC904(hkReferencedObjectLock* p)
{
    if (hkSingletonC904::DAT_012681d4)
        ReleaseUnserializedReference(hkSingletonC904::DAT_012681d4);
    hkSingletonC904::DAT_012681d4 = p;
}

// Sets the singleton lock mode, creating the lock first if DAT_012681d4 is null.
// @fnv 0x00c90420
// src: HAVOK_LIB 0x00c90420
void __cdecl hkReferencedObject_lockInit(int value)
{
    if (!hkSingletonC904::DAT_012681d4)
    {
        hkReferencedObjectLock* p = new hkReferencedObjectLock();
        p->m_multiThreaded = value;
        replaceInstanceC904(p);
    }
    else
    {
        hkSingletonC904::DAT_012681d4->m_multiThreaded = value;
    }
}

extern int DAT_012681d4;
extern int DAT_012681d8;
extern int(__stdcall* DAT_00fdf044)(int);
extern int(__stdcall* DAT_00fdf04c)(int, int);
extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);

// @fnv 0x00c90510
void hkReferencedObject::addReference() const
{
    if (!m_usMemSizeAndFlags)
        return;

    int* state = (int*)DAT_012681d4;
    int one = 1;

    if (state[2] == one)
    {
        int(__stdcall * getValue)(int) = DAT_00fdf044;
        int value = getValue(DAT_012681d8);

        if (value != 0x23df4554)
        {
            value = getValue(DAT_012681d8);

            int(__stdcall * setValue)(int, int) = DAT_00fdf04c;

            if (value == 0x23df4554)
            {
                state[3] += one;
            }
            else
            {
                DAT_00fdf05c(state + 6);
                state[3] = one;
                setValue(DAT_012681d8, 0x23df4554);
            }

            m_sReferenceCount += one;
            --state[3];

            if (state[3] <= 0)
            {
                setValue(DAT_012681d8, 0);
                DAT_00fdf100(state + 6);
            }

            return;
        }
    }

    m_sReferenceCount += one;
}

namespace fnv_00cc49b0 {
extern __declspec(thread) int tlsMode;
struct ShortPair
{
    int first;
    int second;
};
struct ByteFlag
{
    unsigned char value;
    ByteFlag(bool v) : value(v)
    {}
    ByteFlag(const ByteFlag& other) : value(other.value)
    {}
};
struct FUN_00c90510_class
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
    virtual void vf24(ByteFlag flag, ShortPair* output);
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct FUN_00cc49b0_class;
struct FUN_00d21ce0_class
{
    int unk0c, unk10, unk14;
    void hkpBridgeConstraintAtom_init(FUN_00cc49b0_class* parent);
};
struct FUN_00cc49b0_class
{
    int unk00, unk04, unk08;
    FUN_00d21ce0_class subobject;
    FUN_00c90510_class* owner;
    unsigned short state;
    unsigned short substate;
    void ahkpBreakableConstraintData_SetChild(FUN_00c90510_class* value);
};
struct ScopedThreadState
{
    int previous;
    ScopedThreadState()
    {
        previous = tlsMode;
        tlsMode = 16;
    }
    ~ScopedThreadState()
    {
        tlsMode = previous;
    }
};
// Retains value if present, releases owner if present, assigns value, copies two values from vf24, and calls subobject.FUN_00d21ce0(this).
// @fnv 0x00cc49b0
// src: XBOX_PDB 0x00cc49b0
void FUN_00cc49b0_class::ahkpBreakableConstraintData_SetChild(FUN_00c90510_class* apOwner)
{
    ScopedThreadState thread;
    if (apOwner)
        apOwner->FUN_00c90510();
    if (owner)
        owner->FUN_00c905b0();
    owner = apOwner;
    ShortPair result;
    owner->vf24(ByteFlag(true), &result);
    state = (unsigned short)result.first;
    substate = (unsigned short)result.second;
    subobject.hkpBridgeConstraintAtom_init(this);
}
}  // namespace fnv_00cc49b0

// Inline stream operations used by this unit accompany the shared declarations.
inline NiBinaryStream* NiStream::GetBinaryStream()
{
    return *reinterpret_cast<NiBinaryStream**>(reinterpret_cast<char*>(this) + 0x24c);
}

template <class T> inline void NiBinaryStream::Read(T& value)
{
    unsigned int uiSize = sizeof(T);
    unsigned int& position = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4);
    position += (*reinterpret_cast<ReadFunction*>(reinterpret_cast<char*>(this) + 8))(this, &value, sizeof(T), &uiSize, 1);
}

// Stream state has layer/flags at +0x20/+0x24, unlike hkpWorldObject's collidable at +0x10.
class WorldObjectStreamState
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int m_iLayer;
    unsigned char m_ucFlags;

    void ahkpBreakableConstraintData_SetChild(hkReferencedObject* pkShape) throw();
};

class FUN_00d53200_class
{
  public:
    virtual ~FUN_00d53200_class();
    void hkConstraintCinfo_LoadBinary(NiStream& kStream);
};

hkReferencedObject* __cdecl bhkConstraintManager_LoadBinary(NiStream& kStream) throw();

// This loader's state pointer is at +0x4; bhkWorldObject's inherited Havok pointer is at +0x8.
class WorldObjectStreamLoader : public FUN_00d53200_class
{
  public:
    WorldObjectStreamState* m_pPointer;

    void hkBreakableConstraintCinfo_LoadBinary(NiStream& kStream);
};

// Reads a shape, attaches it to the hkpWorldObject, and deserializes its layer and flags from the stream.
// @fnv 0x00cc4e10
// src: XBOX_PDB 0x00cc4e10
void WorldObjectStreamLoader::hkBreakableConstraintCinfo_LoadBinary(NiStream& kStream)
{
    hkConstraintCinfo_LoadBinary(kStream);
    WorldObjectStreamState* pkObject = m_pPointer;
    hkReferencedObject* pkShape = bhkConstraintManager_LoadBinary(kStream);
    pkObject->ahkpBreakableConstraintData_SetChild(pkShape);
    pkShape->removeReference();
    kStream.GetBinaryStream()->Read(pkObject->m_iLayer);
    kStream.GetBinaryStream()->Read(pkObject->m_ucFlags);
}

struct RcObject
{
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct SortEntry
{
    RcObject* object;
    int key;
    int value;
};
void __cdecl SiftDownHeap(SortEntry* entries, int index, int count, int compare);
// Sorts an array of SortEntry in place using a heap sort, sifting down to build the heap and then extracting elements.
// @fnv 0x00e3eff0
void __cdecl HeapSort(SortEntry* entries, int count, int compare)
{
    int remaining = count;
    int index = count / 2;
    while (index > 0)
    {
        SiftDownHeap(entries, index, count, compare);
        --index;
    }
    if (remaining >= 1)
    {
        SortEntry* last = &entries[remaining - 1];
        do
        {
            if (entries->object)
                entries->object->FUN_00c90510();
            SortEntry copyEntry = *entries;
            if (entries != last)
            {
                RcObject* GetObject = last->object;
                if (GetObject)
                    GetObject->FUN_00c90510();
                if (entries->object)
                    entries->object->FUN_00c905b0();
                entries->object = GetObject;
            }
            entries->key = last->key;
            entries->value = last->value;
            if (last != &copyEntry)
            {
                if (copyEntry.object)
                    copyEntry.object->FUN_00c90510();
                if (last->object)
                    last->object->FUN_00c905b0();
                last->object = copyEntry.object;
            }
            last->key = copyEntry.key;
            last->value = copyEntry.value;
            --remaining;
            --last;
            SiftDownHeap(entries, 1, remaining, compare);
            if (copyEntry.object)
                copyEntry.object->FUN_00c905b0();
        } while (remaining >= 1);
    }
}

struct Resource_e3eb
{
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();
};

template <class T> struct hkRefPtr_e3eb
{
    T* m_pRetainedObject;
    hkRefPtr_e3eb() throw() : m_pRetainedObject(0)
    {}
    hkRefPtr_e3eb(T* const& e) throw()
    {
        if (e)
            e->FUN_00c90510();
        m_pRetainedObject = e;
    }
    hkRefPtr_e3eb(const hkRefPtr_e3eb& rp) throw()
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
    ~hkRefPtr_e3eb() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = 0;
    }
};

struct Container_e3eb
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    Resource_e3eb* m_resource;
    int unk1C, unk20, unk24;
    Container_e3eb** m_children;
    int m_numChildren;
    hkRefPtr_e3eb<Resource_e3eb> FindResourceRecursively(Resource_e3eb* target) throw();
};

// Recursively searches this container and its children for the given Resource_e3eb, returning a reference-counted pointer to it or an empty reference.
// @fnv 0x00e3eb10
// src: GUESS 0x00e3eb10 (confidence: high)
hkRefPtr_e3eb<Resource_e3eb> Container_e3eb::FindResourceRecursively(Resource_e3eb* apResource) throw()
{
    if (m_resource == apResource)
        return hkRefPtr_e3eb<Resource_e3eb>(m_resource);
    for (int i = 0; i < m_numChildren; i++)
    {
        hkRefPtr_e3eb<Resource_e3eb> found = m_children[i]->FindResourceRecursively(apResource);
        if (found.m_pRetainedObject)
            return found;
    }
    return hkRefPtr_e3eb<Resource_e3eb>();
}

struct E5C4Obj
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

struct E5C4Ref
{
    E5C4Obj* p;
    E5C4Ref(const E5C4Ref& o)
    {
        if (o.p != 0)
        {
            o.p->FUN_00c90510();
        }
        p = o.p;
    }
};

struct E5C4Key
{
    E5C4Obj* p;
    E5C4Ref* AssignObject(int* tmp);
};

struct E5C4Entry
{
    int key;
    E5C4Ref val;
};

struct E5C4Foo
{
    int unk0;
    E5C4Entry* d;
    int FindEntryIndex(E5C4Obj* k);
    E5C4Ref FindOrCreateEntryReference(E5C4Key k);
};

// Looks up an entry by key in d; if missing, assigns a new object via k.AssignObject, then returns a copy of the stored E5C4Ref.
// @fnv 0x00e5c4d0
// src: GUESS 0x00e5c4d0 (confidence: medium)
E5C4Ref E5C4Foo::FindOrCreateEntryReference(E5C4Key akKey)
{
    int bCreated = 0;
    volatile int tmp[2];
    tmp[0] = 0;
    int i = FindEntryIndex(((volatile E5C4Key&)akKey).p);
    tmp[0] = 0;
    tmp[1] = 0;
    E5C4Ref* slot;
    if (i < 0)
    {
        bCreated = 1;
        slot = akKey.AssignObject((int*)tmp);
    }
    else
    {
        slot = &d[i].val;
    }
    E5C4Ref r(*slot);
    if ((bCreated & 1) != 0 && akKey.p != 0)
    {
        akKey.p->FUN_00c905b0();
    }
    return r;
}

extern "C" void _ReadWriteBarrier(void);
volatile int S00e3eba0_sink;
__declspec(noinline) void __fastcall FUN_00c90510(void* self)
{
    S00e3eba0_sink = (int)self;
}
__declspec(noinline) void __fastcall FUN_00c905b0(void* self)
{
    S00e3eba0_sink = (int)self + 1;
}
struct S00e3eba0_class
{
    void** m_pVTable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_pShape;
    int unk1C;
    int unk20;
    int unk24;
    S00e3eba0_class** m_items;
    int m_uiItemCount;
    void ReplaceObject(hkReferencedObject* oldObject, hkReferencedObject* GetObject);
};
// If m_pShape equals oldObject, replaces it with GetObject; then recursively applies the operation to every item in m_items.
// @fnv 0x00e3eba0
void S00e3eba0_class::ReplaceObject(hkReferencedObject* oldObject, hkReferencedObject* apNewObject)
{
    if (m_pShape == (void*)oldObject)
    {
        _ReadWriteBarrier();
        if (m_pShape != (void*)apNewObject)
        {
            if (apNewObject)
                FUN_00c90510(apNewObject);
            if (m_pShape)
                FUN_00c905b0(m_pShape);
            m_pShape = apNewObject;
        }
    }
    for (int i = 0; i < m_uiItemCount; i++)
        m_items[i]->ReplaceObject(oldObject, apNewObject);
}

// Calls FUN_00c903b0 for each strided item, acquiring the critical section when multi-threaded mode is enabled and TLS lacks the marker.
// @fnv 0x00c90740
// src: HAVOK_LIB 0x00c90740
void __cdecl hkReferencedObject_removeReferences(void* items, int count, int stride)
{
    hkReferencedObjectLock* guard = (hkReferencedObjectLock*)DAT_012681d4;
    if (guard->m_multiThreaded != 0 && TlsGetValue(DAT_012681d8) != (void*)0x23df4554)
    {
        if (TlsGetValue(DAT_012681d8) == (void*)0x23df4554)
            ++guard->m_lLockCount;
        else
        {
            EnterCriticalSection(&guard->m_kCriticalSection);
            guard->m_lLockCount = 1;
            TlsSetValue(DAT_012681d8, (void*)0x23df4554);
        }
        if (count > 0)
        {
            char* item = (char*)items;
            do
            {
                ReleaseUnserializedReference(*((hkReferencedObject**)item));
                item += stride;
            } while (--count);
        }
        if (--guard->m_lLockCount <= 0)
        {
            TlsSetValue(DAT_012681d8, 0);
            LeaveCriticalSection(&guard->m_kCriticalSection);
        }
    }
    else
    {
        if (count > 0)
        {
            int remaining = count;
            int step = *(volatile int*)&stride;
            char* item = (char*)items;
            do
            {
                ReleaseUnserializedReference(*((hkReferencedObject**)item));
                item += step;
            } while (--remaining);
        }
    }
}

// Calls FUN_00c903a0 on each object, acquiring the critical section when multi-threaded mode is enabled and TLS lacks the marker.
// @fnv 0x00c90670
// src: HAVOK_LIB 0x00c90670
void __cdecl hkReferencedObject_addReferences(const void* objects, int numObjects, int stride)
{
    hkReferencedObjectLock* lock = (hkReferencedObjectLock*)DAT_012681d4;
    if (lock->m_multiThreaded && (unsigned int)TlsGetValue(DAT_012681d8) != 0x23df4554)
    {
        if ((unsigned int)TlsGetValue(DAT_012681d8) == 0x23df4554)
        {
            lock->m_lLockCount++;
        }
        else
        {
            EnterCriticalSection(&lock->m_kCriticalSection);
            lock->m_lLockCount = 1;
            TlsSetValue(DAT_012681d8, (void*)0x23df4554);
        }
        for (int i = 0; i < numObjects; ++i)
        {
            AddUnserializedReference(*(hkReferencedObject**)objects);
            objects = (const char*)objects + stride;
        }
        --lock->m_lLockCount;
        if (lock->m_lLockCount <= 0)
        {
            TlsSetValue(DAT_012681d8, 0);
            LeaveCriticalSection(&lock->m_kCriticalSection);
        }
    }
    else
    {
        for (int i = 0; i < numObjects; ++i)
        {
            AddUnserializedReference(*(hkReferencedObject**)objects);
            objects = (const char*)objects + stride;
        }
    }
}

// Decrements the lock count and, when it is nonpositive, clears the TLS slot and leaves the critical section.
// @fnv 0x00c904e0
// src: HAVOK_LIB 0x00c904e0
void __cdecl hkReferencedObject_unlockAll()
{
    hkReferencedObjectLock* lock = reinterpret_cast<hkReferencedObjectLock*>(DAT_012681d4);
    lock->m_lLockCount = lock->m_lLockCount - 1;
    if (lock->m_lLockCount <= 0)
    {
        TlsSetValue(DAT_012681d8, 0);
        LeaveCriticalSection(&lock->m_kCriticalSection);
    }
}
