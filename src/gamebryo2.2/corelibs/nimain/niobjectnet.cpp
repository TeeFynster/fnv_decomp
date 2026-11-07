// gamebryo2.2/corelibs/nimain/niobjectnet.cpp: NiObjectNET, ShortArray, MorphTarget, bhkSphereShape and more (26 functions)

#include <stddef.h>
#include <string.h>

#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiGlobalStringTable.h"
#include "NiRefObject_inline.h"

#include "niobjectnet_decls.h"
#include "../../../../include/NiNode.h"

#include "../../../../include/BSFadeNode.h"
#include "../../../../include/MemoryManager.h"
#include "../../../../include/NiShader.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern char* _EmptyFS;


inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}


// @fnv 0x00a5bba0
bool NiObjectNET::ResizeExtraData(unsigned short usCapacity)
{
    if (usCapacity == 0)
        return false;

    EnterCriticalSection(&g_NiObjectNETExtraDataLock);

    if (m_usMaxSize == 0)
    {
        m_usMaxSize = usCapacity;
        m_ppkExtra = (NiExtraData**)_NiMalloc(usCapacity * sizeof(NiExtraData*));
        m_usExtraDataSize = 0;
        LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
        return true;
    }

    m_usMaxSize = usCapacity;
    NiExtraData** pNewExtraData = (NiExtraData**)_NiMalloc(usCapacity * sizeof(NiExtraData*));
    fnv_zlib_memcpy(pNewExtraData, m_ppkExtra, m_usExtraDataSize * sizeof(NiExtraData*));
    NiFree(m_ppkExtra);
    m_ppkExtra = pNewExtraData;
    LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
    return true;
}

// @fnv 0x00a5c080
void NiObjectNET::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);

    if (kStream.m_uiNifFileVersion < 0x14010001)
        kStream.ReadFixedString(m_kName);
    else
        kStream.ReadStringTableEntry(m_kName);

    if (kStream.m_uiNifFileVersion < 0x0500000B)
    {
        kStream.ResetStreamState();
        kStream.ResetStreamState();
    }
    else
    {
        kStream.ReadUnsignedInteger();
        kStream.ResetStreamState();
    }
}

#pragma optimize("", off)
// @fnv 0x0043b480
unsigned int NiNode::GetNumChildren()
{
    return m_kChildren.GetSize();
}
#pragma optimize("", on)

// Calls NiObject::ProcessClone, then ProcessClone on each extra data entry and on the time controller.
// @fnv 0x00a5b8f0
void NiObjectNET::ProcessClone(CloningProcess& kProcess)
{
    NiObject::ProcessClone(kProcess);

    for (unsigned short i = 0; i < m_usExtraDataSize; ++i)
    {
        NiExtraData* pExtraData = m_ppkExtra[i];
        if (pExtraData)
            pExtraData->ProcessClone(kProcess);
    }

    NiTimeController* pController = m_spControllers;
    if (pController)
        pController->ProcessClone(kProcess);
}

// Links the object's extra data list and time controller from the stream, handling both legacy and current stream versions.
// @fnv 0x00a5c0e0
void NiObjectNET::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);

    if (kStream.m_uiNifFileVersion < 0x0500000B)
    {
        m_ppkExtra = (NiExtraData**)kStream.GetLoadedObject();
    }
    else
    {
        unsigned int ItemUpdateArray = kStream.GetLinkID();
        ResizeExtraData((unsigned short)ItemUpdateArray);

        while (ItemUpdateArray > 0)
        {
            AddExtraData((NiExtraData*)kStream.GetLoadedObject());
            --ItemUpdateArray;
        }
    }

    NiTimeController* pController = (NiTimeController*)kStream.GetLoadedObject();
    if (m_spControllers != pController)
    {
        if (m_spControllers)
            m_spControllers->DecRefCount();

        m_spControllers = pController;

        if (m_spControllers)
            m_spControllers->IncRefCount();
    }
}

// Assigns pInterpolator to the interpolator field, releasing the old one and adding a reference to the new one.
// @fnv 0x00a5c000
void NiMorphData::MorphTarget::SetTargetInterpolator(NiInterpolator* pInterpolator)
{
    if (m_spTargetInterpolator.m_pObject != pInterpolator)
    {
        if (m_spTargetInterpolator.m_pObject)
            m_spTargetInterpolator.m_pObject->NiRefObject::DecRefCount();

        m_spTargetInterpolator.m_pObject = pInterpolator;

        if (m_spTargetInterpolator.m_pObject)
            m_spTargetInterpolator.m_pObject->NiRefObject::IncRefCount();
    }
}

#pragma optimize("", off)
// Sets the flags on this object by calling FUN_00439360 with mask 0x1c00 and shift 10.
// @fnv 0x004393e0
void NiObjectNET::SetFlags(unsigned short flags)
{
    SetField_00439360(flags, 0x1c00, 10);
}
#pragma optimize("", on)

// @fnv 0x00a5c400
void NiObjectNET::AddController(NiTimeController* controller)
{
    if (controller)
    {
        NiTimeController* next = m_spControllers;
        if (controller->m_spNextController.m_pObject != next)
        {
            if (controller->m_spNextController.m_pObject)
                controller->m_spNextController.m_pObject->DecRefCount();
            controller->m_spNextController.m_pObject = next;
            if (controller->m_spNextController.m_pObject)
                controller->m_spNextController.m_pObject->IncRefCount();
        }
        if (m_spControllers != controller)
        {
            if (m_spControllers)
                m_spControllers->DecRefCount();
            m_spControllers = controller;
            if (m_spControllers)
                m_spControllers->IncRefCount();
        }
    }
}

#pragma optimize("", off)
// Increments DAT_01268280 and passes the radius, converted via FUN_004a3e90 when convert is set, to FUN_0056ea00.
// @fnv 0x0056e950
bhkSphereShape::bhkSphereShape(float radius, bool convert)
{
    DAT_01268280 = DAT_01268280 + 1;
    bhkSphereShape_Init(convert ? NI2HK_004a3e90(radius) : radius);
}
#pragma optimize("", on)

// @fnv 0x00a5c050
// src: GAMEBRYO_LIB 0x00a5c050
void NiObjectNET::RemoveAllControllers()
{
    if (m_spControllers)
    {
        m_spControllers->DecRefCount();
        m_spControllers = NULL;
    }
}

// Looks up extra data by name on the target NiAVObject and updates the cached reference, adjusting ref counts when it changes.
// @fnv 0x00a57240
void NiObjectNET::RefreshExtraData()
{
    NiAVObject* target = *(NiAVObject**)((char*)this + 0x2c);
    NiFixedString& name = *(NiFixedString*)((char*)this + 0x38);
    NiExtraData*& cached = *(NiExtraData**)((char*)this + 0x3c);
    NiExtraData* data = target->GetExtraData(name);
    if (cached != data)
    {
        if (cached)
            cached->DecRefCount();
        cached = data;
        if (cached)
            cached->IncRefCount();
    }
}

extern NiFixedString EmptyFS;

// @fnv 0x00a5b950
void __fastcall AssignFixedString(char* pThis, int, char** ppkName)
{
    char* pcNewName = *ppkName;
    if (*reinterpret_cast<char**>(pThis + 8) != pcNewName)
    {
        if (pcNewName != *reinterpret_cast<char**>(&EmptyFS))
            InterlockedIncrement(reinterpret_cast<volatile long*>(pcNewName - 8));
        char* pcOldName = *reinterpret_cast<char**>(pThis + 8);
        if (pcOldName != *reinterpret_cast<char**>(&EmptyFS))
            InterlockedDecrement(reinterpret_cast<volatile long*>(pcOldName - 8));
        *reinterpret_cast<char**>(pThis + 8) = pcNewName;
    }
}

struct FUN_00a5bfa0_shell : public NiObjectNET
{
    void ClearExtraData();
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);

struct NiExtraDataDeleteProxy : public NiObjectNET
{
    void DeleteExtraData(unsigned short);
};

// Under the extra-data lock, deletes all extra data entries, frees the extra data array, and resets the count and max size.
// @fnv 0x00a5bfa0
void FUN_00a5bfa0_shell::ClearExtraData()
{
    EnterCriticalSection(&g_NiObjectNETExtraDataLock);
    for (short i = static_cast<short>(m_usExtraDataSize) - 1; i >= 0; --i)
    {
        reinterpret_cast<NiExtraDataDeleteProxy*>(this)->DeleteExtraData(static_cast<unsigned short>(i));
    }
    NiFree(m_ppkExtra);
    m_ppkExtra = 0;
    m_usMaxSize = 0;
    m_usExtraDataSize = 0;
    LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
}

extern int DAT_0109b23c;

// @fnv 0x00a5c760
// src: GUESS 0x00a5c760 (confidence: low)
void __fastcall Object_UpdateFields_00a5c760(void** pThis)
{
    *pThis = &DAT_0109b23c;
    NiFree(pThis[1]);
}

extern char const* const g_011f3e6c_arg1;
// @fnv 0x00a57290
// src: COMMUNITY 0x00a57290
char const* const* __cdecl NiExtraDataController_GetRTTI()
{
    return &g_011f3e6c_arg1;
}

struct VStream
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual bool RegisterFixedString(NiFixedString*);
};
struct VExtra
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void RegisterStreamables(VStream*);
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual bool IsGeometryController();
};
struct NiObjectBase
{
    bool RegisterStreamables(NiStream*);
};
// @fnv 0x00a5c180
// src: XBOX_PDB 0x00a5c180
bool __fastcall NiObjectNET_RegisterStreamables(void* thisp, int, NiStream* kStream)
{
    char* self = reinterpret_cast<char*>(thisp);
    VStream* stream = reinterpret_cast<VStream*>(kStream);
    if (!reinterpret_cast<NiObjectBase*>(thisp)->RegisterStreamables(kStream))
        return false;
    if (!stream->RegisterFixedString(reinterpret_cast<NiFixedString*>(self + 8)))
        return false;
    for (unsigned short i = 0; i < *reinterpret_cast<unsigned short*>(self + 0x14); i++)
    {
        VExtra* pkExtra = (*reinterpret_cast<VExtra***>(self + 0x10))[i];
        if (pkExtra && pkExtra->IsGeometryController())
            pkExtra->RegisterStreamables(stream);
    }
    VExtra* pController = *reinterpret_cast<VExtra**>(self + 0xc);
    if (pController)
        pController->RegisterStreamables(stream);
    return true;
}

namespace fnv_00a5c5b0 {
struct VExtra
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual bool IsGeometryController();
};
struct VCtrl
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual bool IsStreamableC();
    char pad[0x2c - 0];
    VCtrl* next;
};
struct VOut
{
    char p0[4];
    unsigned int pos;
    char p1[4];
    unsigned int(__cdecl* write)(VOut*, void*, unsigned int, const unsigned int&, unsigned int);
};
struct VStream
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void SaveLinkID(void*);
    char pad[0x250 - 4];
    VOut* out;
    void WriteObjectLink(NiFixedString*);
};
struct NiObjSave
{
    void SaveBinaryX();
};
// @fnv 0x00a5c5b0
void __fastcall SaveNiObjectLinks(char* self, int, VStream* kStream)
{
    reinterpret_cast<NiObject*>(self)->NiObject::LinkObject(*reinterpret_cast<NiStream*>(kStream));
    kStream->WriteObjectLink(reinterpret_cast<NiFixedString*>(self + 8));
    unsigned int uiStreamableExtraCount = 0;
    unsigned short i;
    for (i = 0; i < *reinterpret_cast<unsigned short*>(self + 0x14); i++)
    {
        VExtra* pkExtra = (*reinterpret_cast<VExtra***>(self + 0x10))[i];
        if (pkExtra->IsGeometryController())
            uiStreamableExtraCount++;
    }
    VOut* out = kStream->out;
    out->pos += out->write(out, &uiStreamableExtraCount, 4, 4, 1);
    unsigned short j;
    for (j = 0; j < *reinterpret_cast<unsigned short*>(self + 0x14); j++)
    {
        VExtra* pkExtra = (*reinterpret_cast<VExtra***>(self + 0x10))[j];
        if (pkExtra->IsGeometryController())
            kStream->SaveLinkID(pkExtra);
    }
    VCtrl* pkController = *reinterpret_cast<VCtrl**>(self + 0xc);
    while (pkController && !pkController->IsStreamableC())
        pkController = pkController->next;
    kStream->SaveLinkID(pkController);
}
}  // namespace fnv_00a5c5b0

class NiBinaryExtraData;
namespace fnv_00a5c290 {
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a5c290_shell : public NiObjectNET
{
    void NiObjectNET_CopyMembers(NiObjectNET*, CloningProcess*);
};

extern "C" unsigned int __cdecl strlen(const char*);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* _EmptyFS;
int strcpy_s(char*, unsigned int, const char*);
void NiFree(void*);
struct FUN_00a5d450_holder
{
    void CreateVertexBufferSet(NiBinaryExtraData*, CloningProcess*);
};
struct FUN_00a5b950_holder
{
    void AssignFixedString(const NiFixedString&);
};
struct RefView_a5c290
{
    virtual void v00();
    virtual void DeleteThis();
    long m_uiRefCount;
};
struct VObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual VObj* MakeClone(CloningProcess&);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual bool IsCloneable();
};

// Clones the object's name, extra data and time controller onto pkDest according to the cloning flags in kCloning.
// @fnv 0x00a5c290
// src: XBOX_PDB 0x00a5c290
void FUN_00a5c290_shell::NiObjectNET_CopyMembers(NiObjectNET* pkDest, CloningProcess* kCloning)
{
    char* pcSuffixedName;
    int iNameLen;
    ((FUN_00a5d450_holder*)this)->CreateVertexBufferSet((NiBinaryExtraData*)pkDest, kCloning);

    if (kCloning->m_eCloneCopyMode == 1)
    {
        char* pcName = m_kName.m_kHandle;
        if (pkDest->m_kName.m_kHandle != pcName)
        {
            if (pcName != _EmptyFS)
                InterlockedIncrement((long*)(pcName - 8));
            if (pkDest->m_kName.m_kHandle != _EmptyFS)
                InterlockedDecrement((long*)(pkDest->m_kName.m_kHandle - 8));
            pkDest->m_kName.m_kHandle = pcName;
        }
    }
    else if (kCloning->m_eCloneCopyMode == 2)
    {
        if (m_kName.m_kHandle)
        {
            iNameLen = strlen(m_kName.m_kHandle) + 2;
            pcSuffixedName = (char*)_NiMalloc(iNameLen);
            strcpy_s(pcSuffixedName, iNameLen, m_kName.m_kHandle);
            pcSuffixedName[iNameLen - 2] = kCloning->m_bExactType;
            pcSuffixedName[iNameLen - 1] = 0;
            char* kName;
            if (!pcSuffixedName)
                kName = _EmptyFS;
            else
                kName = NiGlobalStringTable::AddString(pcSuffixedName);
            char* kArg = kName;
            ((FUN_00a5b950_holder*)pkDest)->AssignFixedString(reinterpret_cast<const NiFixedString&>(kArg));
            if (kName != _EmptyFS)
                InterlockedDecrement((long*)(kName - 8));
            NiFree(pcSuffixedName);
        }
    }

    for (unsigned short i = 0; i < m_usExtraDataSize; i++)
    {
        NiExtraData* pkExtra = m_ppkExtra[i];
        if (pkExtra && ((VObj*)pkExtra)->IsCloneable())
            pkDest->AddExtraData((NiExtraData*)((VObj*)pkExtra)->MakeClone(*kCloning));
    }

    NiTimeController* pkCtrl = m_spControllers;
    if (pkCtrl)
    {
        NiTimeController* pkNew = (NiTimeController*)((VObj*)pkCtrl)->MakeClone(*kCloning);
        if (pkDest->m_spControllers != pkNew)
        {
            RefView_a5c290* pkOld = (RefView_a5c290*)pkDest->m_spControllers;
            if (pkOld && InterlockedDecrement(&pkOld->m_uiRefCount) == 0)
                pkOld->DeleteThis();
            pkDest->m_spControllers = pkNew;
            if (pkNew)
                InterlockedIncrement(&((RefView_a5c290*)pkNew)->m_uiRefCount);
        }
    }
}
}  // namespace fnv_00a5c290

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ControllerPointerProxy
{
    NiTimeController* m_pObject;
    void FUN_00a5f860(NiTimeController* replacement);
    void FUN_0045cec0();
};
struct ControllerLinkProxy
{
    void FUN_00a67260(NiTimeController* replacement);
};
struct ControllerOwner : NiObjectNET
{
    void NiObjectNET_RemoveController(NiTimeController* controller);
};
// Removes controller from the owner's controller list, unlinking it and releasing references, or does nothing if it is not present.
// @fnv 0x00a5c480
// src: GAMEBRYO_LIB 0x00a5c480
void ControllerOwner::NiObjectNET_RemoveController(NiTimeController* controller)
{
    if (!controller || !m_spControllers)
        return;
    NiTimeController* current = m_spControllers;
    if (current == controller)
    {
        volatile long* refCount = reinterpret_cast<volatile long*>(&controller->m_uiRefCount);
        InterlockedIncrement(refCount);
        reinterpret_cast<ControllerPointerProxy*>(&m_spControllers)->FUN_00a5f860(controller->m_spNextController.m_pObject);
        NiTimeController* following = controller->m_spNextController.m_pObject;
        if (following)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&following->m_uiRefCount)) == 0)
                following->DeleteThis();
            controller->m_spNextController.m_pObject = 0;
        }
        if (InterlockedDecrement(refCount) == 0)
            controller->DeleteThis();
        return;
    }
    NiTimeController* following = current->m_spNextController.m_pObject;
    while (following && following != controller)
    {
        current = following;
        following = following->m_spNextController.m_pObject;
    }
    if (following)
    {
        ControllerPointerProxy retainedProxy = {controller};
        InterlockedIncrement(reinterpret_cast<volatile long*>(&controller->m_uiRefCount));
        reinterpret_cast<ControllerLinkProxy*>(current)->FUN_00a67260(controller->m_spNextController.m_pObject);
        NiTimeController* tail = controller->m_spNextController.m_pObject;
        if (tail)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&tail->m_uiRefCount)) == 0)
                tail->DeleteThis();
            controller->m_spNextController.m_pObject = 0;
        }
        retainedProxy.FUN_0045cec0();
    }
}

// Deleting destructor of an NiObjectNET-style object: drop extra data, the controller and the name, then free.

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class C7B0RefObject
{
  public:
    virtual void Unk00();
    virtual void DeleteThis();

    long m_lRefCount;

    void DecRefCount()
    {
        if (::InterlockedDecrement(&m_lRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class C7B0Pointer
{
  public:
    __forceinline ~C7B0Pointer()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};

class C7B0Object
{
  public:
    virtual ~C7B0Object() throw();

    int unk04;
};

class C7B0ObjectNET : public C7B0Object
{
  public:
    __forceinline virtual ~C7B0ObjectNET() throw()
    {
        DeleteExtraData();
    }

    static void operator delete(void* pvMem, unsigned int uiSize);

    void DeleteExtraData() throw();
    C7B0ObjectNET* DestroyObject(unsigned int uiFlags);

    NiFixedString m_kName;
    C7B0Pointer<C7B0RefObject> m_spController;
    int unk10;
    int unk14;
};

// Runs the C7B0ObjectNET destructor and, when uiFlags has bit 0 set, frees the object, returning this.
// @fnv 0x00a5c7b0
C7B0ObjectNET* C7B0ObjectNET::DestroyObject(unsigned int uiFlags)
{
    this->C7B0ObjectNET::~C7B0ObjectNET();
    if (uiFlags & 1)
        C7B0ObjectNET::operator delete(this, sizeof(C7B0ObjectNET));
    return this;
}

namespace fnv_00a5c820 {
extern int DAT_0109b2d4;
void* _NiMalloc_00aa1070(unsigned int);

struct ShortArray
{
    void* m_ppVirtualMethodTable;
    unsigned short* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    ShortArray()
    {
        m_usMaxSize = 0;
        m_usGrowBy = 1;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
        m_ppVirtualMethodTable = &DAT_0109b2d4;
    }
    void NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(unsigned int);
    void SetEntry(unsigned int, const unsigned short&);
    unsigned short GetAt(unsigned int u) const
    {
        return m_pBase[u];
    }
    void Add(const unsigned short& x)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(index + m_usGrowBy);
        SetEntry(index, x);
    }
};

// src: COMMUNITY 0x00a5b790
void ShortArray::NiTArray_unsigned_short_NiTMallocInterface_unsigned_short_SetSize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;
    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != 0)
            {
                m_pBase[i] = 0;
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }
    unsigned short* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = (unsigned short*)_NiMalloc_00aa1070(m_usMaxSize * sizeof(unsigned short));
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = 0;
    }
    else
    {
        m_pBase = 0;
    }
    NiFree(pSaveBase);
}
void ShortArray::SetEntry(unsigned int uiIndex, const unsigned short& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != 0)
            m_usESize++;
    }
    else
    {
        if (element != 0)
        {
            if (m_pBase[uiIndex] == 0)
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != 0)
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}
struct EqObject
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool Equal(EqObject*);
};

struct VExtra
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool IsGeometryController();
};
struct NetEqual : NiObjectNET
{
    bool NiObjectNET_IsEqual(NiObjectNET*);
    bool IsSameAs(NiObject*);
};
struct CountController : NiTimeController
{
    unsigned int NiTimeController_ItemsInList();
};

// Compares two NiObjectNET objects by checking name handle, geometry controller extra data, and time controller lists for equality.
// @fnv 0x00a5c820
// src: XBOX_PDB 0x00a5c820
bool NetEqual::NiObjectNET_IsEqual(NiObjectNET* other)
{
    if (!IsSameAs(other))
        return false;
    if (m_kName.m_kHandle != other->m_kName.m_kHandle)
        return false;
    ShortArray first, second;
    unsigned short countA;
    for (countA = 0; countA < m_usExtraDataSize; ++countA)
        if (((VExtra*)m_ppkExtra[countA])->IsGeometryController())
            first.Add(countA);
    for (countA = 0; countA < other->m_usExtraDataSize; ++countA)
        if (((VExtra*)other->m_ppkExtra[countA])->IsGeometryController())
            second.Add(countA);
    if (first.m_usSize != second.m_usSize)
    {
        NiFree(second.m_pBase);
        NiFree(first.m_pBase);
        return false;
    }
    for (unsigned short j = 0; j < first.m_usSize; ++j)
    {
        EqObject* o1 = (EqObject*)m_ppkExtra[first.m_pBase[j]];
        EqObject* o2 = (EqObject*)other->m_ppkExtra[second.m_pBase[j]];
        if (!o1->Equal(o2))
        {
            NiFree(second.m_pBase);
            NiFree(first.m_pBase);
            return false;
        }
    }
    NiTimeController* pOtherController = other->m_spControllers;
    NiTimeController* pController = m_spControllers;
    unsigned int i = pController ? ((CountController*)pController)->NiTimeController_ItemsInList() : 0;
    unsigned int uiOtherControllerCount = pOtherController ? ((CountController*)pOtherController)->NiTimeController_ItemsInList() : 0;
    if (i != uiOtherControllerCount)
        goto fail;
    while (pController && pOtherController)
    {
        if (!((EqObject*)pController)->Equal((EqObject*)pOtherController))
        {
            NiFree(second.m_pBase);
            NiFree(first.m_pBase);
            return false;
        }
        pController = pController->m_spNextController.m_pObject;
        pOtherController = pOtherController->m_spNextController.m_pObject;
    }
    NiFree(second.m_pBase);
    NiFree(first.m_pBase);
    return true;
fail:
    NiFree(second.m_pBase);
    NiFree(first.m_pBase);
    return false;
}
}  // namespace fnv_00a5c820

extern char g_ExtraTypeA5;
struct LinkExtraA5
{
    virtual ~LinkExtraA5();
    virtual void DeleteThis();
    virtual const void* GetRTTI() const;
    LinkExtraA5*& GetNextExtraData();
    void ClearNextExtraData();
};
struct LinkBaseA5
{
    virtual ~LinkBaseA5();
    unsigned int m_iObjectReferenceCount;
    void LinkObject(NiStream& stream);
};
struct LinkObjectA5 : LinkBaseA5
{
    void* m_name;
    void* m_controllers;
    LinkExtraA5** m_extra;
    unsigned short m_iElementCount;
    unsigned short m_pRayCursor;
    bool AddExtraData(LinkExtraA5* extra);
    void DeleteExtraData(unsigned short index);
    void RemoveExtraDataByName(unsigned short index)
    {
        void(__stdcall * leaveLock)(void*) = LeaveCriticalSection;
        void(__stdcall * enterLock)(void*) = EnterCriticalSection;
        enterLock(&g_NiObjectNETExtraDataLock);
        if (index < m_iElementCount)
            DeleteExtraData(index);
        leaveLock(&g_NiObjectNETExtraDataLock);
    }
    void NiObjectNET_PostLinkObject(NiStream& stream);
};
inline bool IsExactTypeA5(const void* type, const LinkExtraA5* object)
{
    bool result = false;
    if (object)
        result = object->GetRTTI() == type;
    return result;
}
// Links the object from the stream, transfers the old-version extra-data chain, and removes entries whose RTTI pointer equals g_ExtraTypeA5.
// @fnv 0x00a5c6a0
// src: XBOX_PDB 0x00a5c6a0
void LinkObjectA5::NiObjectNET_PostLinkObject(NiStream& stream)
{
    LinkBaseA5::LinkObject(stream);
    if (stream.m_uiNifFileVersion < 0x0500000b)
    {
        LinkExtraA5* extra = reinterpret_cast<LinkExtraA5*>(m_extra);
        if (extra)
        {
            m_extra = 0;
            while (extra)
            {
                LinkExtraA5* next = extra->GetNextExtraData();
                extra->ClearNextExtraData();
                AddExtraData(extra);
                extra = next;
            }
        }
    }
    for (unsigned int i = 0; i < m_iElementCount; ++i)
    {
        LinkExtraA5* extra = m_extra[(unsigned short)i];
        if (IsExactTypeA5(&g_ExtraTypeA5, extra))
        {
            RemoveExtraDataByName((unsigned short)i);
            i = (unsigned int)-1;
        }
    }
}

struct StrArray
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int uiMaxSize);
    void FUN_0096ae90(unsigned int uiIndex, char*& element);
    void SetAtGrow(unsigned int uiIndex, char*& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_0096ad30(uiIndex + m_usGrowBy);
        FUN_0096ae90(uiIndex, element);
    }
    void Add(char*& element)
    {
        SetAtGrow(m_usSize, element);
    }
};
extern int DAT_011f4304;
char* NiViewerStrings_NiGetViewerString_Title(int);
char* NiGetViewerString_00a7d5e0(const char*, ...);
struct S
{
    void* vtbl;
    int unk04;
    int unk08;
    int GetUnk08() const
    {
        return unk08;
    }
    void AppendCameraPathEntries(StrArray* arr);
    void NiObjectNET_GetViewerStrings(StrArray* arr);
};
// Appends camera path entries, a string from DAT_011f4304, and a formatted m_kName string to the given StrArray.
// @fnv 0x00a5ca80
// src: XBOX_PDB 0x00a5ca80
void S::NiObjectNET_GetViewerStrings(StrArray* apArray)
{
    AppendCameraPathEntries(apArray);
    char* str = NiViewerStrings_NiGetViewerString_Title(DAT_011f4304);
    apArray->Add(str);
    str = NiGetViewerString_00a7d5e0("m_kName", GetUnk08());
    apArray->Add(str);
}

#include <string.h>
struct FUN_00a5bca0_shell : public NiObjectNET
{
    bool SetExtraDataName(NiExtraData*);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern char* _EmptyFS;
struct NamedObj
{
    void SetName(const ::NiFixedString&) throw();
};
class NiTexture;
struct Holder
{
    bool NiObjectNET_AddExtraData(NiTexture*);
};
struct RTTIName
{
    const char* m_pcName;
};
struct RTTISource
{
    virtual void V0();
    virtual void V1();
    virtual const RTTIName* GetRTTI() const;
};
int NiSprintf(char*, unsigned int, const char*, ...);
char* FUN_00ec7750(const char*, const char*);
char* CopyFilePath(char*, unsigned int, const char*, unsigned int);
int _strcat_s(char*, unsigned int, const char*);
void NiFree(void*);

// When the shader filename is empty, derives a name from RTTI and an index, sets it, then returns FUN_00a5ba40's result.
// @fnv 0x00a5bca0
bool FUN_00a5bca0_shell::SetExtraDataName(NiExtraData* pkExtra)
{
    if (!pkExtra)
        return false;
    if (!((NiShader*)pkExtra)->GetFilename().m_kHandle)
    {
        const char* pcRTTI = ((RTTISource*)pkExtra)->GetRTTI()->m_pcName;
        if (pcRTTI && strlen(pcRTTI))
        {
            char pcSuffix[6];
            NiSprintf(pcSuffix, 6, "ED%03d", *(unsigned short*)((char*)this + 0x14));
            const char* pcSubstr = FUN_00ec7750(pcRTTI, "ExtraData");
            unsigned int uiStrLength = 0;
            if (pcSubstr > pcRTTI)
                uiStrLength = pcSubstr - pcRTTI;
            unsigned int uiLen = uiStrLength + strlen(pcSuffix) + 1;
            char* pcGeneratedKey = (char*)_NiMalloc(uiLen);
            CopyFilePath(pcGeneratedKey, uiLen, pcRTTI, uiStrLength);
            _strcat_s(pcGeneratedKey, uiLen, pcSuffix);
            ((NamedObj*)pkExtra)->SetName(::NiFixedString(static_cast<const char*>(pcGeneratedKey)));
            NiFree(pcGeneratedKey);
        }
    }
    return ((Holder*)this)->NiObjectNET_AddExtraData((NiTexture*)pkExtra);
}

struct FUN_00a5be90_shell : public NiObjectNET
{
    bool DeleteExtraDataByKey(const NiFixedString& kKey);
};

// Binary-searches m_ppkExtra using filename pointer ordering and deletes an entry when its filename pointer equals kKey.
// @fnv 0x00a5be90
bool FUN_00a5be90_shell::DeleteExtraDataByKey(const NiFixedString& kKey)
{
    if (m_usExtraDataSize == 0)
        return false;

    EnterCriticalSection(&g_NiObjectNETExtraDataLock);

    if ((const char*)kKey == _EmptyFS)
    {
        LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
        return false;
    }

    short sLow = 0;
    short sHigh = m_usExtraDataSize - 1;
    short sMiddle;
    int dtCompare;

    while (sLow <= sHigh)
    {
        sMiddle = (sLow + sHigh) >> 1;
        dtCompare = (const char*)kKey - (const char*)((NiShader*)m_ppkExtra[sMiddle])->GetFilename();
        if (dtCompare == 0)
        {
            ((NiExtraDataDeleteProxy*)this)->DeleteExtraData(sMiddle);
            LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
            return true;
        }
        if (dtCompare > 0)
        {
            sLow = sMiddle + 1;
        }
        else
        {
            sHigh = sMiddle - 1;
        }
    }

    LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
    return false;
}

extern ::MemoryManager g_memoryManager;
struct FUN_00a5c780
{
    void* m_pData;
    virtual ~FUN_00a5c780();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// Frees the m_pData buffer held by the object via NiFree.
// @fnv 0x00a5c780
FUN_00a5c780::~FUN_00a5c780()
{
    NiFree(m_pData);
}

