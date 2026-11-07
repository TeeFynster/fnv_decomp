
// gamebryo2.2/corelibs/nimain/nitimecontroller.cpp
// NiTimeController: base timing/update functionality for animation controllers.
// FNV 2.2 branch revision (thread-local scale cache, legacy flag conversion,
// geometry consistency fixup on attach/link).
#include "../../../../include/NiTMapBase.h"
#include "../../../../include/NiTMapItem.h"
#include "nitimecontroller.h"
#include "nitimecontroller_decls.h"

// Clones the base NiObject, then recursively clones the next controller in the chain if one exists.
// @fnv 0x00a6d0c0
void NiTimeController::ProcessClone(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    NiTimeController* pkNext = GetNext();
    if (pkNext)
        pkNext->ProcessClone(kCloning);
}
//---------------------------------------------------------------------------
// @fnv 0x00a6d450
void NiTimeController::SetTarget(NiObjectNET* pkTarget)
{
    if (m_pkTarget == pkTarget)
        return;

    IncRefCount();

    if (m_pkTarget)
    {
        if (m_pkTarget->GetControllers())
            m_pkTarget->ReplaceControllers(this);
    }

    m_pkTarget = pkTarget;

    if (m_pkTarget)
    {
        NiTimeController* pkControl = m_pkTarget->GetControllers();
        while (pkControl)
        {
            if (pkControl == this)
            {
                DecRefCount();
                return;
            }
            pkControl = pkControl->GetNext();
        }
        m_pkTarget->AddController(this);
        if (IsGeometryController())
        {
            NiGeometry* pkGeometry = (NiGeometry*)m_pkTarget;
            pkGeometry->GetModelData()->SetDataConsistency(NiGeometryData::MUTABLE);
        }
    }

    DecRefCount();
}
//---------------------------------------------------------------------------
// @fnv 0x00a6d500
void NiTimeController::LinkObject(NiStream& kStream)
{
    // FNV 2.2 NiPointer assignment order: release the old object before
    // retaining the new one (matches the original refcount sequence).
    NiTimeController* pkNext = (NiTimeController*)kStream.GetLoadedObject();
    if (m_spNextController.m_pObject != pkNext)
    {
        if (m_spNextController.m_pObject)
            m_spNextController.m_pObject->DecRefCount();
        m_spNextController.m_pObject = pkNext;
        if (m_spNextController.m_pObject)
            m_spNextController.m_pObject->IncRefCount();
    }
    m_pkTarget = (NiObjectNET*)kStream.GetLoadedObject();

    if (kStream.GetFileVersion() < 0x0A000110)
    {
        if (IsGeometryController() && m_pkTarget)
        {
            NiGeometry* pkGeometry = (NiGeometry*)m_pkTarget;
            pkGeometry->GetModelData()->SetDataConsistency(NiGeometryData::MUTABLE);
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

extern int DAT_011a9bd0;
extern int DAT_011a9bd4;
extern int DAT_011a9bd8;
extern int DAT_011a9bdc;

// Copies the four globals DAT_011a9bd0 through DAT_011a9bdc into p[0..3] and returns p.
// @fnv 0x00a29690
int* __cdecl CopyGlobalsToBuffer(int, int, int, int* pDest)
{
    pDest[0] = DAT_011a9bd0;
    pDest[1] = DAT_011a9bd4;
    pDest[2] = DAT_011a9bd8;
    pDest[3] = DAT_011a9bdc;
    return pDest;
}


// @fnv 0x00a6cc80
// src: GAMEBRYO_LIB 0x00a6cc80
bool __fastcall NiTimeController_IsEqual(NiTimeController* pThis, int edx, NiObject* pkObject)
{
    NiTimeController* pkControl = (NiTimeController*)pkObject;
    if (pThis->IsSameAs(pkObject) && pThis->m_uiObjectFlags == pkControl->m_uiObjectFlags &&
        pThis->m_fFrequency == pkControl->m_fFrequency && pThis->m_fPhase == pkControl->m_fPhase &&
        pThis->m_fLoKeyTime == pkControl->m_fLoKeyTime && pThis->m_fHiKeyTime == pkControl->m_fHiKeyTime)
    {
        if ((pThis->m_pkTarget && !pkControl->m_pkTarget) || (!pThis->m_pkTarget && pkControl->m_pkTarget))
            return false;
        return true;
    }
    return false;
}


// @fnv 0x00a6cd00
// src: XBOX_PDB 0x00a6cd00
unsigned int __fastcall NiTimeController_ItemsInList(NiTimeController* p, int edx)
{
    unsigned int n = 0;
    while (p)
    {
        ++n;
        p = p->m_spNextController.m_pObject;
    }
    return n;
}

extern const float DAT_01015f5c;

// @fnv 0x00a6cd10
void __fastcall InitStartTime(NiTimeController* p, int edx, float fTime)
{
    p->m_uiObjectFlags |= 8;
    p->m_fLastTime = DAT_01015f5c;
    if (p->m_uiObjectFlags & 1)
        p->m_fStartTime = fTime;
}


// Registers the object's streamables with kStream, then registers the streamables of the stored NiObject if present; returns false if the base registration fails.
// @fnv 0x00a6d0f0
// src: XBOX_PDB 0x00a6d0f0
bool __fastcall NiTimeController_RegisterStreamables(NiTimeController* p, int edx, NiStream& kStream)
{
    if (!p->NiObject::RegisterStreamables(kStream))
        return false;
    NiObject* n = p->m_spNextController.m_pObject;
    if (n)
        n->RegisterStreamables(kStream);
    return true;
}

// Stops a time controller: clears the ACTIVE flag and applies the
// negative-infinity sentinel (-FLT_MAX) to the last time and, for
// init-type controllers, to the start time as well.
static const float kNegInfinity = -3.402823466e+38f;



// @fnv 0x00a6cd30
void NiTimeController::Stop()
{
    m_uiObjectFlags &= 0xfff7;
    m_fLastTime = kNegInfinity;
    if (m_uiObjectFlags & 1)
    {
        m_fStartTime = kNegInfinity;
    }
}

extern "C" char DAT_011f4280;

struct TCRtti
{
    unsigned int unk00;
    TCRtti* m_pkBase;
};

class TCBase
{
  public:
    virtual ~TCBase()
    {}
    virtual void v01();
    virtual const TCRtti* GetRTTI() const;
    virtual unsigned int v03();
};

struct TCListNode
{
    TCListNode* m_pNext;
    unsigned int unk04;
    struct TCAV* m_pInventoryEntryData;
};

struct TCAV : TCBase
{
    unsigned int unk04;
    unsigned int unk08;
    NiPointer<NiTimeController> m_pControllers;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    TCListNode* m_pList24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    TCAV** m_ppChildren;
    unsigned short unkA4;
    unsigned short m_usChildCount;
};

// @fnv 0x00a6d390
void __cdecl StartControllersRecursive(TCAV* p, float fTime)
{
    NiTimeController* c = p->m_pControllers.m_pObject;
    while (c != 0)
    {
        c->Start(fTime);
        c = c->m_spNextController.m_pObject;
    }
    const TCRtti* r = p->GetRTTI();
    if (r != 0)
    {
        do
        {
            if (r == (const TCRtti*)&DAT_011f4280)
                goto L_0048;
            r = r->m_pkBase;
        } while (r != 0);
    }
    goto L_0076;
L_0048: {
    TCListNode* node = p->m_pList24;
    if (node != 0)
    {
        do
        {
            TCAV** pp = &node->m_pInventoryEntryData;
            TCAV* item = *pp;
            node = node->m_pNext;
            if (*pp != 0 && (*pp)->m_pControllers.m_pObject != 0)
                StartControllersRecursive(*pp, fTime);
        } while (node != 0);
    }
}
L_0076:
    if (p->v03() != 0)
    {
        unsigned int i = 0;
        if (i < p->m_usChildCount)
        {
            do
            {
                TCAV** arr = p->m_ppChildren;
                TCAV* child = arr[i];
                if (child != 0)
                    StartControllersRecursive(child, fTime);
                i++;
            } while (i < p->m_usChildCount);
        }
    }
}

namespace fnv_00a6d2d0 {
class TCTimeNode;

struct TCChainLink
{
    unsigned int unk00;
    TCChainLink* m_pNext;
};

struct TCListLink
{
    TCListLink* m_pNext;
    unsigned int unk04;
    TCTimeNode* m_pInventoryEntryData;
};

inline TCTimeNode* const& GetNextItem(TCListLink*& pos)
{
    TCTimeNode* const& element = pos->m_pInventoryEntryData;
    pos = pos->m_pNext;
    return element;
}

class TCTimeNode
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual TCChainLink* Slot02();
    virtual unsigned int Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35(float fValue);

    unsigned int unk04;
    unsigned int unk08;
    TCTimeNode* m_pChildObject;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    TCListLink* m_pEntries;
    unsigned int unk28;
    unsigned int unk2C;
    TCTimeNode* m_pNext;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    TCTimeNode** m_ppItems;
    unsigned short unkA4;
    unsigned short m_usItemCount;
};

extern int DAT_011f4280;

// @fnv 0x00a6d2d0
// src: XBOX_PDB 0x00a6d2d0
void __cdecl NiTimeController_StartAnimations(TCTimeNode* obj)
{
    TCTimeNode* p = obj->m_pChildObject;
    while (p != 0)
    {
        p->Slot35(DAT_01015f5c);
        p = p->m_pNext;
    }

    TCChainLink* n = obj->Slot02();
    TCListLink* pListLink = 0;
    TCListLink* next = 0;
    TCTimeNode* item = 0;
    if (n == 0)
        goto after_list;
scan:
    if (n == reinterpret_cast<TCChainLink*>(&DAT_011f4280))
        goto found;
    n = n->m_pNext;
    if (n != 0)
        goto scan;
    goto after_list;
found:
    pListLink = obj->m_pEntries;
    if (pListLink == 0)
        goto after_list;
    do
    {
        item = GetNextItem(pListLink);
        if (item != 0 && item->m_pChildObject != 0)
            NiTimeController_StartAnimations(item);
    } while (pListLink != 0);

after_list:
    if (obj->Slot03() != 0)
    {
        for (unsigned int i = 0; i < obj->m_usItemCount; ++i)
        {
            item = obj->m_ppItems[i];
            if (item != 0)
                NiTimeController_StartAnimations(item);
        }
    }
}
}  // namespace fnv_00a6d2d0


// Loads a time controller from a stream: base object, flags, frequency, phase, key times, and version-dependent flag fixups.
// @fnv 0x00a6d5e0
void NiTimeController::LoadBinary(NiStream& kIn)
{
    NiObject::LoadBinary(kIn);
    kIn.ResetStreamState();
    ReadBinaryValue(kIn, m_uiObjectFlags);
    ReadBinaryValue(kIn, m_fFrequency);
    ReadBinaryValue(kIn, m_fPhase);
    ReadBinaryValue(kIn, m_fLoKeyTime);
    ReadBinaryValue(kIn, m_fHiKeyTime);
    kIn.ResetStreamState();
    if (kIn.GetFileVersion() < 0x0A000101)
    {
        unsigned short preserved = m_uiObjectFlags;
        m_uiObjectFlags &= 0xFFF0;
        m_uiObjectFlags *= 2;
        m_uiObjectFlags |= preserved & 0xF;
    }
    if (kIn.GetFileVersion() < 0x0A000103)
    {
        kIn.m_usNiTimeControllerFlags = m_uiObjectFlags;
        m_uiObjectFlags &= 0x001F;
    }
    if (kIn.GetFileVersion() < 0x0A01006D)
        m_uiObjectFlags &= 0xFFDF;
    m_uiObjectFlags = (m_uiObjectFlags & 0xFF7F) | 0x40;
}




template <class T> inline void BinarySave_a6d730(NiBinaryStream& binary, T* value, unsigned int count = 1)
{
    unsigned int size = sizeof(T);
    binary.BinaryWrite(value, sizeof(T) * count, &size, 1);
}
template <class T> inline void Save_a6d730(NiStream& stream, T& value)
{
    BinarySave_a6d730(*stream.m_pkOstr, &value, 1);
}

// @fnv 0x00a6d730
inline bool CanSaveController(NiTimeController* controller)
{
    typedef bool (__thiscall* Query)(NiTimeController*);
    return reinterpret_cast<Query>((*reinterpret_cast<void***>(controller))[43])(controller);
}
void __fastcall SaveTimeController(NiTimeController* controller, int, NiStream& stream)
{
    controller->NiObject::SaveBinary(stream);
    NiTimeController* next = controller->m_spNextController.m_pObject;
    while (next && !CanSaveController(next))
        next = next->m_spNextController.m_pObject;
    stream.SaveLinkID(next);
    Save_a6d730(stream, controller->m_uiObjectFlags);
    Save_a6d730(stream, controller->m_fFrequency);
    Save_a6d730(stream, controller->m_fPhase);
    Save_a6d730(stream, controller->m_fLoKeyTime);
    Save_a6d730(stream, controller->m_fHiKeyTime);
    stream.SaveLinkID(controller->m_pkTarget);
}

extern const char* DAT_011f49e4;

char* __cdecl NiViewerStrings_NiGetViewerString_Title(const char*);
char* __cdecl NiGetViewerString_00a7d550(const char*, float);
char* __cdecl NiGetViewerString_00a7d5a0(const char*, void*);
char* __cdecl BuildAppTimeOrInitString(const char*, int);
char* __cdecl NiTimeController_GetViewerString(const char*, int);
char* __cdecl NiGetViewerString(const char*, bool);

#include "../../../../include/NiTPrimitiveArray.h"
// Gamebryo NiTArray.inl: the original inlines Add (SetAtGrow) and calls SetSize / SetAt out of line
template <class T, class TAlloc> inline unsigned int NiTArray<T, TAlloc>::Add(const T& element)
{
    unsigned int uiSize = m_usSize;
    if (uiSize >= m_usMaxSize)
        SetSize(uiSize + m_usGrowBy);
    SetAt(uiSize, element);
    return uiSize;
}





// @fnv 0x00a6d830
void __fastcall GetTimeControllerViewerStrings(NiTimeController* controller, int, NiViewerStringsArray* pkViewerStrings)
{
    pkViewerStrings->Add(NiViewerStrings_NiGetViewerString_Title(DAT_011f49e4));
    pkViewerStrings->Add(NiGetViewerString_00a7d550("m_fFrequency", controller->m_fFrequency));
    pkViewerStrings->Add(NiGetViewerString_00a7d550("m_fPhase", controller->m_fPhase));
    pkViewerStrings->Add(NiGetViewerString_00a7d550("m_fLoKeyTime", controller->m_fLoKeyTime));
    pkViewerStrings->Add(NiGetViewerString_00a7d550("m_fHiKeyTime", controller->m_fHiKeyTime));
    pkViewerStrings->Add(NiGetViewerString_00a7d550("m_fStartTime", controller->m_fStartTime));
    pkViewerStrings->Add(NiGetViewerString_00a7d550("m_fLastTime", controller->m_fLastTime));
    pkViewerStrings->Add(NiGetViewerString_00a7d5a0("m_pkTarget", controller->m_pkTarget));
    int iAnimType = controller->m_uiObjectFlags & 1;
    pkViewerStrings->Add(BuildAppTimeOrInitString("anim type", iAnimType));
    int iCycleType = (controller->m_uiObjectFlags >> 1) & 3;
    pkViewerStrings->Add(NiTimeController_GetViewerString("cycle type", iCycleType));
    bool bActive = (controller->m_uiObjectFlags >> 3) & 1;
    pkViewerStrings->Add(NiGetViewerString("Active", bActive));
    bool bBack = (controller->m_uiObjectFlags >> 4) & 1;
    pkViewerStrings->Add(NiGetViewerString("Play Backwards", bBack));
}

// @fnv 0x00a29680
// src: GUESS 0x00a29680 (confidence: high)
void __cdecl Object_DoNothing()
{}



// When active and time changed or force-update is set, it may return true if scaled time matches; otherwise it deactivates and returns false.
// @fnv 0x00a36250
// src: XBOX_PDB 0x00a36250
bool NiTimeController::DontDoUpdate(float fTime)
{
    if (GetControllerActive(this))
    {
        if (m_fLastTime != fTime || GetControllerForceUpdate(this))
        {
            if (GetControllerComputeScaledTime(this))
            {
                float fScaledTime = ComputeScaledTime(fTime);
                if (m_fControllerTime == fScaledTime && !GetControllerForceUpdate(this))
                    return true;
                m_fControllerTime = fScaledTime;
            }
            SetControllerActive(false);
            return false;
        }
    }
    return true;
}

extern const float DAT_01015f5c;
extern "C" int DAT_011a8400;
extern "C" int DAT_011a8404;
extern "C" int DAT_011a8408;
extern "C" int DAT_011f3704;
extern "C" int DAT_011f3708;
extern "C" int DAT_011f370c;
extern "C" int DAT_011f3710;
extern "C" float DAT_01096b8c;

struct Card9
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    int a8;
};
extern "C" Card9 DAT_011a9448;

union Fld
{
    int i;
    float f;
};

class FUN_00a362f0_cls
{
  public:
    float m_f00;
    Fld m_f04;
    Fld m_f08;
    Fld m_f0c;
    Fld m_f10;
    Fld m_f14;
    Fld m_f18;
    Fld m_f1c;
    Fld m_f20;
    Fld m_f24;
    Fld m_f28;
    Fld m_f2c;
    Fld m_f30;
    Fld m_f34;
    Fld m_f38;
    Fld m_f3c;
    Fld m_f40;
    Card9 m_aiIndexedValues;
    void* InitializeFields_00a362f0();
};

// Initializes all fields of FUN_00a362f0_cls with global constants and returns this.
// @fnv 0x00a362f0
// src: GUESS 0x00a362f0 (confidence: low)
void* FUN_00a362f0_cls::InitializeFields_00a362f0()
{
    volatile float* __restrict p = (volatile float*)this;

    m_f04.i = DAT_011a8400;
    m_f08.i = DAT_011a8404;
    m_f0c.i = DAT_011a8408;
    m_f10.i = DAT_011f3704;
    m_f14.i = DAT_011f3708;
    m_f18.i = DAT_011f370c;
    m_f1c.i = DAT_011f3710;
    m_f20.f = DAT_01096b8c;
    m_f24.i = DAT_011a8400;
    m_f28.i = DAT_011a8404;
    m_f2c.i = DAT_011a8408;
    m_f30.i = DAT_011f3704;
    m_f34.i = DAT_011f3708;
    m_f38.i = DAT_011f370c;
    m_f3c.i = DAT_011f3710;
    m_f40.f = DAT_01096b8c;

    p[0] = DAT_01015f5c;
    p[1] = DAT_01015f5c;
    p[5] = DAT_01015f5c;
    p[8] = DAT_01015f5c;
    p[9] = DAT_01015f5c;
    p[13] = DAT_01015f5c;
    m_f40.f = DAT_01015f5c;

    m_aiIndexedValues = DAT_011a9448;
    return this;
}

#include <string.h>
void* __cdecl _NiMalloc(unsigned int);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
// Allocates strlen(pcPrefix)+12 bytes; for eType 0 or 1, formats the prefix with APP_TIME or APP_INIT and returns the buffer.
// @fnv 0x00a6d120
char* __cdecl BuildAppTimeOrInitString(const char* pcPrefix, int eType)
{
    unsigned int uiLen = (unsigned int)strlen(pcPrefix) + 12;
    char* pcString = (char*)_NiMalloc(uiLen);
    switch (eType)
    {
    case 0:
        NiSprintf(pcString, uiLen, "%s = APP_TIME", pcPrefix);
        break;
    case 1:
        NiSprintf(pcString, uiLen, "%s = APP_INIT", pcPrefix);
        break;
    }
    return pcString;
}

void* __cdecl _NiMalloc(unsigned int);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
// Allocates a buffer, formats pcPrefix with LOOP, REVERSE, CLAMP, or UNKNOWN!!! based on eType, and returns it.
// @fnv 0x00a6d190
// src: XBOX_PDB 0x00a6d190
char* __cdecl NiTimeController_GetViewerString(const char* pcPrefix, int eType)
{
    unsigned int uiLen = (unsigned int)strlen(pcPrefix) + 11;
    char* pcString = (char*)_NiMalloc(uiLen);
    switch (eType)
    {
    case 0:
        NiSprintf(pcString, uiLen, "%s = LOOP", pcPrefix);
        break;
    case 1:
        NiSprintf(pcString, uiLen, "%s = REVERSE", pcPrefix);
        break;
    case 2:
        NiSprintf(pcString, uiLen, "%s = CLAMP", pcPrefix);
        break;
    default:
        NiSprintf(pcString, uiLen, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }
    return pcString;
}



template <class TPARENT, class TKEY, class TVAL> bool NiTMapBase<TPARENT, TKEY, TVAL>::GetAt(TKEY key, TVAL& val) const
{
    unsigned int uiIndex = KeyToHashIndex(key);
    NiTMapItem<TKEY, TVAL>* pkItem = m_ppkHashTable[uiIndex];
    while (pkItem)
    {
        if (IsKeysEqual(pkItem->m_key, key))
        {
            val = pkItem->m_val;
            return true;
        }
        pkItem = pkItem->m_pkNext;
    }
    return false;
}

class CloningProcess
{
  public:
    NiTMapBase<NiTPointerAllocator<unsigned int>, NiObject*, NiObject*>* m_pCloneMap;
};





// @fnv 0x00a6cfe0
void __fastcall CopyTimeControllerMembers(NiTimeController* controller, int, NiTimeController* pkDest, CloningProcess& kCloning)
{
    controller->NiObject::CreateVertexBufferSet(pkDest, kCloning);
    pkDest->m_uiObjectFlags = controller->m_uiObjectFlags;
    pkDest->m_fFrequency = controller->m_fFrequency;
    pkDest->m_fPhase = controller->m_fPhase;
    pkDest->m_fLoKeyTime = controller->m_fLoKeyTime;
    pkDest->m_fHiKeyTime = controller->m_fHiKeyTime;
    pkDest->m_fStartTime = controller->m_fStartTime;
    pkDest->m_fLastTime = controller->m_fLastTime;
    pkDest->m_fWeightAdjustedLastTime = controller->m_fWeightAdjustedLastTime;

    if (controller->m_pkTarget)
    {
        NiObject* pkClone;
        bool bFound = kCloning.m_pCloneMap->GetAt(controller->m_pkTarget, pkClone);
        if (bFound && controller->m_pkTarget->GetRTTI() == pkClone->GetRTTI())
        {
            pkDest->m_pkTarget = (NiObjectNET*)pkClone;
        }
        else
        {
            pkDest->m_pkTarget = 0;
        }
    }

    NiObject* pkNext = (NiObject*)controller->m_spNextController.m_pObject;
    if (pkNext)
        pkDest->m_spNextController = (NiTimeController*)pkNext->MakeClone(kCloning);
}

namespace ScaledTimeMath {
extern "C" double __cdecl fmod(double, double);
inline float Remainder(float value, float span)
{
    volatile float result = (float)fmod((double)value, (double)span);
    return result;
}
inline float AddLowKey(double remainder, float lowKey)
{
    return (float)(remainder + lowKey);
}
}



__declspec(thread) float ts_fLastScaledTime = 0.0f;
__declspec(thread) unsigned int ts_uiLastCycleType = 3;
__declspec(thread) float ts_fLastTime = 0.0f;
__declspec(thread) float ts_fLastLoKeyTime = 0.0f;
__declspec(thread) float ts_fLastHiKeyTime = 0.0f;

// Computes a scaled time from fTime using frequency, phase, and cycle type, caching the result in thread-local storage when inputs are unchanged.
// @fnv 0x00a6cd60
float NiTimeController::ComputeScaledTime(float fTime)
{
    if (m_fStartTime == -3.402823466e+38F)
        m_fStartTime = fTime;

    float fMoveElapsedTime;
    if (m_fLastTime == -3.402823466e+38F)
    {
        m_fWeightAdjustedLastTime = 0.0f;
        if (m_uiObjectFlags & 1)
            fMoveElapsedTime = 0.0f;
        else
            fMoveElapsedTime = fTime;
    }
    else
    {
        fMoveElapsedTime = fTime - m_fLastTime;
    }

    m_fWeightAdjustedLastTime += m_fFrequency * fMoveElapsedTime;
    float fScaledTime = m_fWeightAdjustedLastTime + m_fPhase;
    m_fLastTime = fTime;

    unsigned short uFlags = m_uiObjectFlags;
    unsigned int uiCycleType = (uFlags >> 1) & 3;

    if (ts_fLastHiKeyTime == m_fHiKeyTime && ts_fLastLoKeyTime == m_fLoKeyTime && ts_fLastTime == fScaledTime &&
        ts_uiLastCycleType == uiCycleType)
        return ts_fLastScaledTime;

    ts_fLastHiKeyTime = m_fHiKeyTime;
    ts_uiLastCycleType = uiCycleType;
    ts_fLastLoKeyTime = m_fLoKeyTime;
    ts_fLastTime = fScaledTime;

    if (m_fHiKeyTime != -3.402823466e+38F && m_fLoKeyTime != 3.402823466e+38F)
    {
        switch (uiCycleType)
        {
        case 0: {
            float fSpan = m_fHiKeyTime - m_fLoKeyTime;
            if (fSpan != 0.0f)
            {
                fScaledTime = ScaledTimeMath::AddLowKey(ScaledTimeMath::Remainder(fScaledTime - m_fLoKeyTime, fSpan),
                                                        m_fLoKeyTime);
                if (fScaledTime < m_fLoKeyTime)
                    fScaledTime += fSpan;
            }
            else
            {
                fScaledTime = m_fLoKeyTime;
            }
            break;
        }
        case 1: {
            float fSpan = m_fHiKeyTime - m_fLoKeyTime;
            if (fSpan != 0.0f)
            {
                float fTwoSpan = 2.0f * fSpan;
                fScaledTime = ScaledTimeMath::Remainder(fScaledTime, fTwoSpan);
                if (fScaledTime < 0.0f)
                    fScaledTime += fTwoSpan;
                fScaledTime = (fScaledTime > fSpan ? fTwoSpan - fScaledTime : fScaledTime) + m_fLoKeyTime;
            }
            else
            {
                fScaledTime = m_fLoKeyTime;
            }
            break;
        }
        }
    }

    if (fScaledTime > m_fHiKeyTime)
        fScaledTime = m_fHiKeyTime;
    else if (fScaledTime < m_fLoKeyTime)
        fScaledTime = m_fLoKeyTime;

    if ((unsigned char)(uFlags >> 4) & 1)
        fScaledTime = m_fHiKeyTime - (fScaledTime - m_fLoKeyTime);

    ts_fLastScaledTime = fScaledTime;
    return fScaledTime;
}

