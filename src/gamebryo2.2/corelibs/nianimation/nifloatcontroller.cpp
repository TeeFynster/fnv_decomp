// BaseHack_nifloatcontroller: local type (was include/BaseHack.h, which had no evidence of one real class); its methods are 0x00a57130 NiExtraDataController::SaveBinary, 0x00a6d730 NiTimeController::SaveBinary, 0x00c31b80 NiPSysVolumeEmitter::IsEqual
class NiObject;
struct NiStream;

class BaseHack_nifloatcontroller
{
public:
    void __thiscall FUN_00a6d730(NiStream&);
    bool FUN_00c31b80(NiObject*);
};
#include "../../../../include/NiFloatController.h"
#include "../../../../include/NiFloatData.h"
#include "../../../../include/StrArr.h"
#include "../../../../include/NiStream.h"

// src/gamebryo2.2/corelibs/nianimation/nifloatcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00a57970
// src: XBOX_PDB 0x00a57970
void NiFloatController::LoadBinary_00a57970(NiStream& stream)
{
    NiTimeController::LoadBinary(stream);
    stream.ResetStreamState();
}

// Calls ProcessClone on this and, if the pointer at offset 0x38 is set, on that object too.
// @fnv 0x00a57a40
// src: XBOX_PDB 0x00a57a40
void NiFloatController::ProcessClone_00a57a40(CloningProcess& kCloning)
{
    NiTimeController::ProcessClone(kCloning);
    NiFloatData* pData = m_spFloatData;
    if (pData)
        pData->ProcessClone(kCloning);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FakeObj543
{
    virtual void F00();
    virtual void DeleteThis();
    long m_ref;
};
// Links the object obtained from the stream into the field at offset 0x38, releasing the previous object and incrementing the new one's reference count.
// @fnv 0x00a57a70
// src: XBOX_PDB 0x00a57a70
void NiFloatController::LinkObject_00a57a70(NiStream& kStream)
{
    NiTimeController::LinkObject(kStream);
    FakeObj543* pkObj = (FakeObj543*)kStream.GetLoadedObject();
    FakeObj543* pOld = (FakeObj543*)m_spFloatData;
    if (pOld != pkObj)
    {
        if (pOld)
        {
            if (InterlockedDecrement((long volatile*)&pOld->m_ref) == 0)
                pOld->DeleteThis();
        }
        m_spFloatData = (NiFloatData*)pkObj;
        if (pkObj)
            InterlockedIncrement((long volatile*)&pkObj->m_ref);
    }
}

extern char const* const g_011f3f58_arg1;
char* __cdecl _FUN_00a7d330(char const*);
// Calls FUN_00a6d830, gets a string via _FUN_00a7d330, grows the array if full, then stores the string at the current size index.
// @fnv 0x00a57bb0
void NiFloatController::AppendString(StrArr* pStrArr)
{
    FUN_00a6d830(pStrArr);
    char* psz = _FUN_00a7d330(g_011f3f58_arg1);
    unsigned int uiSize = *(unsigned short*)((char*)pStrArr + 0xa);
    unsigned int uiCapacity = *(unsigned short*)((char*)pStrArr + 8);
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowBy = *(unsigned short*)((char*)pStrArr + 0xe);
        pStrArr->SetSize(uiSize + uiGrowBy);
    }
    pStrArr->SetAt(uiSize, psz);
}

// Reads key count, key type and key size from m_spFloatData into the out parameters and returns its key array, or zeroes them and returns null if absent.
// @fnv 0x00a579f0
TimedAnimationKey* NiFloatController::GetFloatKeys(unsigned int& uiNumKeys, NiAnimationKey::KeyType& eKeyType,
                                                    unsigned char& ucKeySize)
{
    NiFloatData* pkData = m_spFloatData;
    if (pkData)
    {
        uiNumKeys = pkData->m_uiNumKeys;
        eKeyType = pkData->m_eRequestType;
        ucKeySize = pkData->m_ucKeyDataSize;
        return pkData->m_pKeyArray;
    }
    uiNumKeys = 0;
    eKeyType = (NiAnimationKey::KeyType)0;
    ucKeySize = 0;
    return 0;
}

// @fnv 0x00a57ad0
// src: XBOX_PDB 0x00a57ad0
bool NiFloatController::RegisterStreamables_00a57ad0(NiStream& stream)
{
    if (!NiTimeController::RegisterStreamables(stream))
        return false;
    m_spFloatData->RegisterStreamables(stream);
    return true;
}

// @fnv 0x00a57b00
// src: XBOX_PDB 0x00a57b00
void __thiscall NiFloatController::SaveBinary_00a57b00(NiStream& stream)
{
    ((BaseHack_nifloatcontroller*)this)->FUN_00a6d730(stream);
    stream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spFloatData));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
// @fnv 0x00a57b50
void NiFloatController::CopyInterpTo(NiFloatController* pkDest, void* pkProc)
{
    FUN_00a6cfe0(pkDest, pkProc);
    NiFloatData* pkSrc = m_spFloatData;
    if (pkSrc)
    {
        NiFloatData* pkClone = (NiFloatData*)pkSrc->MakeClone(*(CloningProcess*)pkProc);
        NiFloatData* pkOld = pkDest->m_spFloatData;
        if (pkOld != pkClone)
        {
            if (pkOld && InterlockedDecrement((volatile long*)&pkOld->m_uiRefCount) == 0)
                pkOld->DeleteThis();
            pkDest->m_spFloatData = pkClone;
            if (pkClone)
                InterlockedIncrement((volatile long*)&pkClone->m_uiRefCount);
        }
    }
}

// Preserve the original smart pointer release and cleanup while the shared member is a raw pointer.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

class A57990RefObject
{
  public:
    virtual ~A57990RefObject() throw();
    virtual void DeleteThis() throw();
    unsigned int m_uiRefCount;

    void IncRefCount() throw()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

template <class T> class A57990Pointer
{
  public:
    T* m_pObject;

    ~A57990Pointer() throw()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }
    A57990Pointer& operator=(T* pObject) throw()
    {
        if (m_pObject != pObject)
        {
            if (m_pObject != 0)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

// Destructor that clears the smart pointer member, releasing its referenced object.
// @fnv 0x00a57990
NiFloatController::~NiFloatController()
{
    A57990Pointer<A57990RefObject>& reference =
        reinterpret_cast<A57990Pointer<A57990RefObject>&>(m_spFloatData);
    struct ReferenceCleanup
    {
        A57990Pointer<A57990RefObject>& reference;
        ~ReferenceCleanup() throw()
        {
            reference.~A57990Pointer<A57990RefObject>();
        }
    } cleanup = { reference };
    reference = 0;
}

// Compare the controller base and the referenced float data.
// @fnv 0x00a57b20
// src: XBOX_PDB 0x00a57b20
bool NiFloatController::IsEqual_00a57b20(NiFloatController* other)
{
    if (!NiTimeController_IsEqual(other))
    {
        return false;
    }
    NiFloatData* pInterface = m_spFloatData;
    NiFloatData* pOtherInterface = other->m_spFloatData;
    unsigned char bResult = static_cast<const NiObject*>(pInterface)->IsEqual(pOtherInterface);
    if (bResult != 0)
    {
        return true;
    }
    return false;
}
