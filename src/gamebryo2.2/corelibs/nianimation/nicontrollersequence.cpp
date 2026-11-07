#include "../../../../include/NiFixedString.h"
#include "../../../../include/NiGlobalStringTable.h"
#include "../../../../include/NiControllerSequence.h"
#include "../../../../include/NiBinaryStream.h"
#include "../../../../include/NiStream.h"
#include "../../../../include/NiObject.h"
#include "../../../../include/NiRefObject.h"
#include "../../../../include/NiStringPalette.h"
#include "../../../../include/NiTextKeyExtraData.h"
#include "../../../../include/NiNode.h"
#include "../../../../include/NiMultiTargetTransformController.h"

inline NiFixedString& NiFixedString::operator=(const NiFixedString& other)
{
    char* handle = other.m_kHandle;
    if (m_kHandle != handle)
    {
        NiGlobalStringTable::IncRefCount(handle);
        NiGlobalStringTable::DecRefCount(m_kHandle);
        m_kHandle = handle;
    }
    return *this;
}

inline NiFixedString& NiFixedString::operator=(const char* text)
{
    if (m_kHandle != text)
    {
        char* old = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(text);
        NiGlobalStringTable::DecRefCount(old);
    }
    return *this;
}

inline NiFixedString& NiFixedString::operator=(char* const& text)
{
    return operator=(static_cast<const char*>(text));
}

inline NiFixedString::operator const char*() const
{
    return m_kHandle;
}

// src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const char* const g_011c7d74_arg1;

// @fnv 0x00a31730
// src: COMMUNITY 0x00a31730
const char* const* __cdecl NiControllerSequence_GetRTTI()
{
    return &g_011c7d74_arg1;
}


extern "C" void __cdecl __Dummy_00b6fef0(void*, unsigned int);

// @fnv 0x00a35820
void* NiControllerSequence::FUN_00a35820(unsigned int flags)
{
    ProcessState_00a35640();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x74);
    return this;
}


// Walks the linked list at offset 0x58 from arg and returns false if this is found in it, true otherwise.
// @fnv 0x00a30580
bool __thiscall NiControllerSequence::IsNotInChain(void* pStart)
{
    void* next = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(pStart) + 0x58);
    if (next == 0)
        return true;
    do
    {
        if (next == this)
            return false;
        next = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(next) + 0x58);
    } while (next != 0);
    return true;
}

void __cdecl ReleaseObjectArray(void*);
struct MM_00a34450
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM_00a34450 g_memoryManager;
extern int DAT_01096620;
struct FUN_00a34450_shell
{
    void* __thiscall FUN_00a34450(unsigned int);
};
// @fnv 0x00a34450
void* __thiscall FUN_00a34450_shell::FUN_00a34450(unsigned int auiFlags)
{
    void* p = *(void**)((char*)this + 4);
    *(void**)this = (void*)&DAT_01096620;
    ReleaseObjectArray(p);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

inline void NiBinaryStream::Write(void* pv, unsigned int uiBytes)
{
    unsigned int uiComponentSize = uiBytes;
    *reinterpret_cast<unsigned int*>((char*)this + 4) += (*reinterpret_cast<NIBINARYSTREAM_WRITEFN*>((char*)this + 12))(this, pv, uiBytes, &uiComponentSize, 1);
}
inline void NiBinaryStream::ReadScalar(void* pv, unsigned int uiBytes)
{
    unsigned int uiComponentSize = uiBytes;
    *reinterpret_cast<unsigned int*>((char*)this + 4) += (*reinterpret_cast<NIBINARYSTREAM_READFN*>((char*)this + 8))(this, pv, uiBytes, &uiComponentSize, 1);
}
static inline NiBinaryStream* SequenceReadStream(NiStream& stream)
{
    return *reinterpret_cast<NiBinaryStream**>((char*)&stream + 0x24c);
}
static inline unsigned int SequenceStreamVersion(const NiStream& stream)
{
    return *reinterpret_cast<const unsigned int*>((const char*)&stream + 0xd8);
}
static inline NiBinaryStream* SequenceSaveStream(NiStream& stream)
{
    return *reinterpret_cast<NiBinaryStream**>((char*)&stream + 0x250);
}
static inline void RegisterSequenceString(NiStream& stream, char*& value)
{
    (*(void (__thiscall**)(NiStream*, char*&))(*(char**)&stream + 0x20))(&stream, value);
}
static inline unsigned int& SequenceStreamCount(NiStream& stream)
{
    return *(unsigned int*)((char*)&stream + 4);
}

// Interpolator and ID-tag records used by the shared sequence declaration.
struct NiControllerSequence__InterpArrayItem
{
    void* m_spControllerInterpolator;
    void* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned char m_ucBlendIndex;
    unsigned char m_ucArrayItemID;
    unsigned char m_auiShapeKeys[2];
};
struct NiControllerSequence__IDTag
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
    void ResetStrings();
};

// Links the object to the stream, then writes the name, interpolation array items with their ID tags, scalar fields and the linked object list.
// @fnv 0x00a33bf0
void NiControllerSequence::SaveToStream(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    kStream.SerializeString((const char*)&m_kName);
    SequenceSaveStream(kStream)->Write(&m_uiNumControlledBlocks, 4);
    SequenceSaveStream(kStream)->Write(&m_uiNumIDTags, 4);
    unsigned int ui;
    for (ui = 0; ui < m_uiNumControlledBlocks; ui++)
    {
        NiControllerSequence__InterpArrayItem& kItem = m_pInterpArray[ui];
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(kItem.m_spControllerInterpolator));
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(kItem.m_pkController));
        SequenceSaveStream(kStream)->Write(&kItem.m_ucArrayItemID, 1);
        NiControllerSequence__IDTag& kTag = m_pkIDTags[ui];
        kStream.SerializeString((const char*)&kTag.m_kAVObjectName);
        kStream.SerializeString((const char*)&kTag.m_kPropertyType);
        kStream.SerializeString((const char*)&kTag.m_kCtlrType);
        kStream.SerializeString((const char*)&kTag.m_kCtlrID);
        kStream.SerializeString((const char*)&kTag.m_kInterpolatorID);
    }
    SequenceSaveStream(kStream)->Write(&m_fWeight, 4);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_spTextKeyData.m_pObject));
    SequenceSaveStream(kStream)->Write(&m_eAnimationCycleType, 4);
    SequenceSaveStream(kStream)->Write(&m_fFrequency, 4);
    SequenceSaveStream(kStream)->Write(&m_fFirstKeyTime, 4);
    SequenceSaveStream(kStream)->Write(&m_fLastKeyTime, 4);
    kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pkOwnerManager));
    kStream.SerializeString((const char*)&m_kAccumulationRootName);
    SequenceSaveStream(kStream)->Write(&m_usNumAnimNotes, 2);
    for (unsigned short usIndex = 0; usIndex < m_usNumAnimNotes; usIndex++)
        kStream.SaveLinkID(reinterpret_cast<const NiObject*>(m_pkAnimNotes[usIndex].m_pObject));
}

struct FUN_00a2e420_shell
{
    unsigned char NiControllerManager_StopTransSourceSequence(float);
};

extern float DAT_01015f5c;
extern double DAT_010241b0;

// Starts an ease-out with the given time and transition flag, or finishes it by updating the accumulated time and resetting state.
// @fnv 0x00a35030
unsigned char NiControllerSequence::SetEaseOut(float fEaseOutTime, bool bTransition)
{
    if (!*(void**)((char*)this + 0x44))
        return 0;
    if (fEaseOutTime > 0.0f)
    {
        *(float*)((char*)this + 0x4c) = DAT_01015f5c;
        *(float*)((char*)this + 0x50) = fEaseOutTime;
        *(unsigned int*)((char*)this + 0x44) = bTransition ? 4 : 3;
        return 1;
    }
    if (*(float*)((char*)this + 0x34) != DAT_010241b0)
        *(float*)((char*)this + 0x48) = *(float*)((char*)this + 0x38) / *(float*)((char*)this + 0x28) -
                                        *(float*)((char*)this + 0x34) + *(float*)((char*)this + 0x48);
    if (*(unsigned int*)((char*)this + 0x44) == 5 && *(void**)((char*)this + 0x40))
        ((FUN_00a2e420_shell*)*(void**)((char*)this + 0x40))->NiControllerManager_StopTransSourceSequence(0.0f);
    *(float*)((char*)this + 0x54) = DAT_01015f5c;
    *(unsigned int*)((char*)this + 0x44) = 0;
    *(void**)((char*)this + 0x58) = 0;
    ((NiControllerSequence*)this)->NiControllerSequence_DetachInterpolators();
    return 1;
}


// @fnv 0x00a30900
// src: COMMUNITY 0x00a30900
void NiControllerSequence::AttachInterpolators(char cDefaultPriority)
{
    unsigned int ui;
    NiControllerSequence__InterpArrayItem* kItem;

    for (ui = 0; ui < *(unsigned int*)((char*)this + 0xc); ++ui)
    {
        kItem = (NiControllerSequence__InterpArrayItem*)(*(unsigned int*)((char*)this + 0x14) + ui * 0x10);
        if (kItem->m_spControllerInterpolator && kItem->m_pkBlendInterpolator)
        {
            unsigned int ucPriority;
            if (kItem->m_ucArrayItemID == 0xff)
                ucPriority = (unsigned int)cDefaultPriority;
            else
                ucPriority = kItem->m_ucArrayItemID;
            kItem->m_ucBlendIndex = ((unsigned char(__thiscall*)(void*, void*, float, unsigned int, float)) *
                                     (void**)(*(unsigned int*)kItem->m_pkBlendInterpolator + 0xdc))(
                kItem->m_pkBlendInterpolator, kItem->m_spControllerInterpolator, *(float*)((char*)this + 0x1c),
                ucPriority, 1.0f);
        }
    }
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};


// @fnv 0x00a326c0
// src: EXE 0x00a326c0
void* __cdecl NiControllerSequence_CreateObject()
{
    void* p = A51BF0Base::operator new(0x74);
    if (p)
        return reinterpret_cast<NiControllerSequence*>(p)->FUN_00a316a0();
    return 0;
}

extern char DAT_01096584;
extern void* _EmptyFS;
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct FUN_00a31500_shell
{
    void __thiscall NiControllerSequence_InterpArrayItem_Free(int);
};

struct FUN_00a315b0_shell
{
    void __thiscall NiControllerSequence_IDTag_Free(int);
};

struct FUN_00a31740_shell
{
    void __thiscall FUN_00a31740(int);
};


// @fnv 0x00a35640
// src: GUESS 0x00a35640 (confidence: low)
void NiControllerSequence::ProcessState_00a35640()
{
    *reinterpret_cast<void**>(this) = &DAT_01096584;

    if (*reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x44) != 0)
    {
        reinterpret_cast<NiControllerSequence*>(this)->SetEaseOut(0.0f, false);
    }

    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x14) != 0)
    {
        reinterpret_cast<FUN_00a31500_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x14))
            ->NiControllerSequence_InterpArrayItem_Free(3);
    }

    if (*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18) != 0)
    {
        reinterpret_cast<FUN_00a315b0_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18))
            ->NiControllerSequence_IDTag_Free(3);
    }

    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(this) + 0x70) > 0 &&
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c) != 0)
    {
        reinterpret_cast<FUN_00a31740_shell*>(*reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x6c))
            ->FUN_00a31740(3);
    }

    int(__stdcall * pDecrementRef)(void*) = DAT_00fdf1c4;

    void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x64);
    if (p != 0)
    {
        if (pDecrementRef(reinterpret_cast<char*>(p) + 4) == 0)
        {
            reinterpret_cast<NiRefObject*>(p)->DeleteThis();
        }
    }

    void* pString = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x5c);
    if (pString != _EmptyFS)
    {
        pDecrementRef(reinterpret_cast<char*>(pString) - 8);
    }

    p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x20);
    if (p != 0)
    {
        if (pDecrementRef(reinterpret_cast<char*>(p) + 4) == 0)
        {
            reinterpret_cast<NiRefObject*>(p)->DeleteThis();
        }
    }

    pString = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x8);
    if (pString != _EmptyFS)
    {
        pDecrementRef(reinterpret_cast<char*>(pString) - 8);
    }

    reinterpret_cast<NiRefObject*>(this)->NiRefObject::~NiRefObject();
}

extern "C" unsigned int __cdecl strlen(const char* s);
void __cdecl FUN_00a305b0(char* out, unsigned int size, const char* fmt, const char* a, const char* b, const char* c);
void __cdecl FUN_00ec65a6(char* c, unsigned int b, const char* a);

struct FUN_00a307c0_entry
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_00a307c0_item
{
    const char* name;
    const char* ctrl;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
};


// @fnv 0x00a307c0
void NiControllerSequence::GetEntryText(unsigned int uiIndex, char* out)
{
    if (out == 0)
    {
        return;
    }
    if (((FUN_00a307c0_entry*)m_pInterpArray)[uiIndex].unk00 == 0)
    {
        *out = 0;
    }
    else
    {
        FUN_00a307c0_item* item = &((FUN_00a307c0_item*)m_pkIDTags)[uiIndex];
        const char* name = item->name;
        unsigned int nameLen = strlen(name) + 1;
        const char* ctrl = item->ctrl;
        if (ctrl != 0)
        {
            const char* propStr = ctrl ? "PROP\n" : 0;
            unsigned int propLen = strlen(propStr);
            unsigned int ctrlLen = strlen(ctrl);
            unsigned int total = ctrlLen + propLen + nameLen + 1;
            FUN_00a305b0(out, total, "%s\n%s%s", name, "PROP\n", ctrl);
        }
        else
        {
            FUN_00ec65a6(out, nameLen, name);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* Addend);


// Deactivates the sequence when needed, then releases the item controllers.
// @fnv 0x00a30880
void NiControllerSequence::ReleaseItems()
{
    if (m_eAnimationState != 0)
    {
        NiControllerSequence* pBase = this;
        pBase->Deactivate(0.0f, false);
    }

    unsigned int uiIndex = 0;

    if (m_uiNumControlledBlocks > uiIndex)
    {
        do
        {
            NiRefObject** ppRefObject = (NiRefObject**)&m_pInterpArray[uiIndex].m_pkController;
            NiRefObject* pRefObject = *ppRefObject;

            if (pRefObject != 0)
            {
                if (InterlockedDecrement((long*)&pRefObject->m_uiRefCount) == 0)
                    pRefObject->DeleteThis();

                *ppRefObject = 0;
            }

            m_pInterpArray[uiIndex].m_pkBlendInterpolator = 0;
        } while (++uiIndex < m_uiNumControlledBlocks);
    }
}

extern "C" double __cdecl fmod(double, double);

// Advances the sequence's accumulated time by frequency times the delta, wraps it into [begin,end] when cycleType is 0, and optionally stores the new state.
// @fnv 0x00a30970
// src: XBOX_PDB 0x00a30970
float NiControllerSequence::ComputeScaledTime_00a30970(float time, bool update)
{
    float accumulated = m_fWeightAdjustedLastTime;
    float delta;
    if (m_fLastTime == DAT_010241b0)
    {
        accumulated = 0.0f;
        delta = time;
    }
    else
    {
        delta = time - m_fLastTime;
    }
    accumulated += m_fFrequency * delta;
    float scaled = accumulated;
    if (m_eAnimationCycleType == 0)
    {
        float duration = m_fLastKeyTime - m_fFirstKeyTime;
        if (duration != 0.0f)
        {
            scaled -= m_fFirstKeyTime;
            if (scaled == duration)
                scaled = m_fLastKeyTime;
            else
                scaled = (float)fmod(scaled, duration) + m_fFirstKeyTime;
            if (scaled < m_fFirstKeyTime)
                scaled += duration;
        }
        else
        {
            scaled = m_fFirstKeyTime;
        }
    }
    if (scaled > m_fLastKeyTime)
        scaled = m_fLastKeyTime;
    else if (scaled < m_fFirstKeyTime)
        scaled = m_fFirstKeyTime;
    if (update)
    {
        m_fWeightAdjustedLastTime = accumulated;
        m_fLastTime = time;
        m_fScaledLastTime = scaled;
    }
    return scaled;
}


bool __stdcall MatchesTextKeys(void* arg);
// @fnv 0x00a30c80
// src: COMMUNITY 0x00a30c80
bool NiControllerSequence::CanSyncTo(void* arg)
{
    if (arg)
    {
        void* linked = *reinterpret_cast<void**>(static_cast<char*>(arg) + 0x58);
        if (linked)
        {
            if (linked == this)
                goto failure;
            typedef unsigned __int64 (__thiscall NiControllerSequence::*ChainQuery)(void*);
            unsigned __int64 result = (this->*reinterpret_cast<ChainQuery>(&NiControllerSequence::IsNotInChain))(linked);
            if (!static_cast<unsigned char>(result))
                goto failure;
            arg = reinterpret_cast<void*>(static_cast<unsigned int>(result >> 32));
        }
        if (MatchesTextKeys((NiControllerSequence*)arg))
            return true;
    }
failure:
    return false;
}

struct FUN_00a30cc0_target
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual bool V23(void* pOther);
};

struct FUN_00a30cc0_cls
{
    FUN_00a30cc0_target* m_pKey0;
    FUN_00a30cc0_target* m_pKey4;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char unk0C;
    unsigned char m_bFlag0D;

    unsigned char Equals(FUN_00a30cc0_cls* other);
};

// Compares two objects' key pointers via V23 and returns whether both keys match and m_bFlag0D is equal.
// @fnv 0x00a30cc0
unsigned char FUN_00a30cc0_cls::Equals(FUN_00a30cc0_cls* other)
{
    if ((m_pKey0 != 0 && other->m_pKey0 == 0) || (m_pKey0 == 0 && other->m_pKey0 != 0) ||
        (m_pKey0 != 0 && other->m_pKey0 != 0 && !m_pKey0->V23(other->m_pKey0)))
        return false;
    FUN_00a30cc0_target* a = m_pKey4;
    if ((a != 0 && other->m_pKey4 == 0) || (m_pKey4 == 0 && other->m_pKey4 != 0) ||
        (a != 0 && other->m_pKey4 != 0 && !a->V23(other->m_pKey4)))
        return false;
    return m_bFlag0D == other->m_bFlag0D;
}

struct ItemView
{
    NiObject* interpolator;
    NiObject* controller;
    void* blend;
    unsigned int settings;
};
struct TagView
{
    char* object;
    char* property;
    char* type;
    char* controller;
    char* interpolator;
};

// @fnv 0x00a30ea0
// src: XBOX_PDB 0x00a30ea0
bool NiControllerSequence::RegisterStreamables_00a30ea0(NiStream& stream)
{
    if (!NiObject::RegisterStreamables(stream))
        return false;
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; i++)
    {
        ItemView& item = ((ItemView*)m_pInterpArray)[i];
        if (item.interpolator)
            item.interpolator->RegisterStreamables(stream);
        NiObject* controller = item.controller;
        if (controller)
            controller->RegisterStreamables(stream);
        TagView& tag = ((TagView*)m_pkIDTags)[i];
        RegisterSequenceString(stream, tag.object);
        RegisterSequenceString(stream, tag.property);
        RegisterSequenceString(stream, tag.type);
        RegisterSequenceString(stream, tag.controller);
        RegisterSequenceString(stream, tag.interpolator);
    }
    NiObject* textKeys = m_spTextKeyData.m_pObject;
    if (textKeys)
        textKeys->RegisterStreamables(stream);
    RegisterSequenceString(stream, m_kName.m_kHandle);
    RegisterSequenceString(stream, m_kAccumulationRootName.m_kHandle);
    for (unsigned short j = 0; j < m_usNumAnimNotes; j++)
        ((NiObject**)m_pkAnimNotes)[j]->RegisterStreamables(stream);
    return true;
}


extern void* _EmptyFS;


struct FUN_00a312d0
{
    NiFixedString m_kAVObjectName;
    NiFixedString m_kPropertyType;
    NiFixedString m_kCtlrType;
    NiFixedString m_kCtlrID;
    NiFixedString m_kInterpolatorID;
    __forceinline ~FUN_00a312d0() {}
    __declspec(nothrow) void ClearIdentifiers();
    FUN_00a312d0(const NiFixedString& a, const NiFixedString& b, const NiFixedString& c, const NiFixedString& d, const NiFixedString& e);
};

// @fnv 0x00a312d0
FUN_00a312d0::FUN_00a312d0(const NiFixedString& akAVObjectName, const NiFixedString& akPropertyType, const NiFixedString& akCtlrType,
                           const NiFixedString& akCtlrID, const NiFixedString& akInterpolatorID)
{
    ClearIdentifiers();
    m_kAVObjectName = akAVObjectName;
    m_kPropertyType = akPropertyType;
    m_kCtlrType = akCtlrType;
    m_kCtlrID = akCtlrID;
    m_kInterpolatorID = akInterpolatorID;
}

extern int DAT_0109b220;
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct S_00aa4060_Class
{
    void MemoryManager_Deallocate(void* apMemory);
};
extern S_00aa4060_Class DAT_011f6238;

struct FUN_00a315b0_Elem
{
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;
};

class FUN_00a315b0_Base
{
  public:
    void NiControllerSequence_IDTag_Destroy();
};

class FUN_00a315b0_cls
{
  public:
    char* m_00;
    char* m_04;
    char* m_08;
    char* m_0c;
    char* m_10;

    FUN_00a315b0_cls* NiControllerSequence_IDTag_Free(unsigned char acFlags);
};

// @fnv 0x00a315b0
// src: COMMUNITY 0x00a315b0
FUN_00a315b0_cls* FUN_00a315b0_cls::NiControllerSequence_IDTag_Free(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        int i = ((int*)this)[-1];
        FUN_00a315b0_Elem* e = (FUN_00a315b0_Elem*)((char*)this + i * 20);
        i = i - 1;
        char* base = (char*)this - 4;
        if (i >= 0)
        {
            int(__stdcall * pRelease)(void*) = DAT_00fdf1c4;
            do
            {
                e = (FUN_00a315b0_Elem*)((char*)e - 20);
                if ((int)e->m_10 != DAT_0109b220)
                {
                    pRelease(e->m_10 - 8);
                }
                if ((int)e->m_0c != DAT_0109b220)
                {
                    pRelease(e->m_0c - 8);
                }
                if ((int)e->m_08 != DAT_0109b220)
                {
                    pRelease(e->m_08 - 8);
                }
                if ((int)e->m_04 != DAT_0109b220)
                {
                    pRelease(e->m_04 - 8);
                }
                if ((int)e->m_00 != DAT_0109b220)
                {
                    pRelease(e->m_00 - 8);
                }
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            DAT_011f6238.MemoryManager_Deallocate(base);
        }
        return (FUN_00a315b0_cls*)base;
    }

    ((FUN_00a315b0_Base*)this)->NiControllerSequence_IDTag_Destroy();
    if (acFlags & 1)
    {
        DAT_011f6238.MemoryManager_Deallocate(this);
    }
    return this;
}

struct a31740_Mem
{
    void __thiscall _DeallocateAlias(void*);
};

extern a31740_Mem g_memMgr31740;

struct FUN_00a31740_cls
{
    NiRefObject* m_pReference;

    void* FUN_00a31740(unsigned char acFlags);
};

// Releases the referenced objects (decrementing refcounts and calling Release at zero) and optionally deallocates this or the array block based on acFlags.
// @fnv 0x00a31740
void* FUN_00a31740_cls::FUN_00a31740(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        NiRefObject** p = (NiRefObject**)this + i;
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = p - 1;
                NiRefObject* e = *p;
                if (e != 0 && InterlockedDecrement((long volatile*)(long volatile*)&e->m_uiRefCount) == 0)
                {
                    e->DeleteThis();
                }
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            g_memMgr31740._DeallocateAlias(base);
        }
        return base;
    }

    NiRefObject* e = m_pReference;
    if (e != 0 && InterlockedDecrement((long volatile*)(long volatile*)&e->m_uiRefCount) == 0)
    {
        e->DeleteThis();
    }
    if (acFlags & 1)
    {
        g_memMgr31740._DeallocateAlias(this);
    }
    return this;
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);

struct FUN_00a317e0_interp
{
    void* m_spControllerInterpolator;
    void* unk04;
    void* unk08;
    void* unk0C;
    void __thiscall ReleaseReferencedObjectsAndResetFlags();
};

struct FUN_00a317e0_tag
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void __thiscall ResetStrings();
};


// @fnv 0x00a317e0
__declspec(noalias) void __thiscall NiControllerSequence::AssignInterpolatorRef(int index, NiRefObject** output)
{
    NiRefObject* pNewRef = reinterpret_cast<NiRefObject*>(m_pInterpArray[index].m_spControllerInterpolator);

    if (pNewRef)
        DAT_00fdf1c0((int*)&pNewRef->m_uiRefCount);

    reinterpret_cast<FUN_00a317e0_interp*>(m_pInterpArray + index)->ReleaseReferencedObjectsAndResetFlags();

    reinterpret_cast<FUN_00a317e0_tag*>(m_pkIDTags + index)->ResetStrings();

    NiRefObject* old = *output;
    int(__stdcall * pfnDecrementRef)(void*) = DAT_00fdf1c4;

    if (old != pNewRef)
    {
        if (old)
        {
            if (pfnDecrementRef((long*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
        }

        *output = pNewRef;

        if (pNewRef)
            DAT_00fdf1c0((int*)&pNewRef->m_uiRefCount);
    }

    if (pNewRef)
    {
        if (pfnDecrementRef((int*)&pNewRef->m_uiRefCount) == 0)
            pNewRef->DeleteThis();
    }
}

namespace fnv_00a328b0 {
extern char* DAT_0109b220;
}


// Computes the sequence offset and optionally sets each controller time.
// @fnv 0x00a328b0
// src: XBOX_PDB 0x00a328b0
void NiControllerSequence::SetPhase(float time, bool setControllerTimes)
{
    float currentTime = time + m_fFirstKeyTime;
    if (setControllerTimes)
    {
        unsigned int index = 0;
        if (index < m_uiNumControlledBlocks)
        {
            do
            {
                NiControllerSequence__IDTag& tag = m_pkIDTags[index];
                void* controller = m_pInterpArray[index].m_pkController;
                if (controller && tag.m_kCtlrType != fnv_00a328b0::DAT_0109b220 &&
                    (!tag.m_kCtlrType || tag.m_kCtlrType[2] != 'T' || tag.m_kCtlrType[7] != 'f'))
                {
                    *reinterpret_cast<float*>(static_cast<char*>(controller) + 0x10) = time;
                }
                ++index;
            } while (index < m_uiNumControlledBlocks);
        }
    }
    m_fSequenceOffset = currentTime;
}


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);

struct SlotEntry
{
    NiRefObject* m_pEntryObject;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned char m_unk0c;
    unsigned char m_flag0d;
    unsigned char m_unk0e;
    unsigned char m_unk0f;
};

struct SlotInfo
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    void NiControllerSequence_IDTag_Operator_Set(unsigned int value);
};


// @fnv 0x00a32bc0
int NiControllerSequence::AssignSlot(NiRefObject* apRef, unsigned int auiValue, unsigned char aucFlag)
{
    unsigned int count = m_uiNumControlledBlocks;
    unsigned int idx = 0;
    for (; idx < count; ++idx)
    {
        if (((SlotEntry*)m_pInterpArray)[idx].m_pEntryObject == 0)
        {
            break;
        }
    }
    if (idx == count)
    {
        if (!NiControllerSequence_ReallocateArrays())
        {
            return -1;
        }
    }
    SlotEntry* slot = &((SlotEntry*)m_pInterpArray)[idx];
    if (slot->m_pEntryObject != apRef)
    {
        NiRefObject* old = slot->m_pEntryObject;
        if (old != 0)
        {
            if (InterlockedDecrement((long*)&old->m_uiRefCount) == 0)
            {
                old->DeleteThis();
            }
        }
        slot->m_pEntryObject = apRef;
        if (apRef != 0)
        {
            InterlockedIncrement((long*)&apRef->m_uiRefCount);
        }
    }
    ((SlotInfo*)m_pkIDTags)[idx].NiControllerSequence_IDTag_Operator_Set(auiValue);
    ((SlotEntry*)m_pInterpArray)[idx].m_flag0d = aucFlag;
    return idx;
}

struct FUN_00a34480_obj
{
    virtual void V00();
    virtual void V01();
    virtual FUN_00a34480_obj* V02();
    FUN_00a34480_obj* m_pNext;
    unsigned short m_word08;
    unsigned short unk0a;
    float m_f0c;
};

extern int DAT_011f36b4;


// Walks the linked list from a2's V02() looking for DAT_011f36b4; if found, merges m_word24 into a2->m_word08, copies m_f28 to a2->m_f0c and calls AssignControllers.
// The shared AddFromOld entry point returns void. Keep the original boolean
// result in this free entry point while using the shared sequence layout.
// @fnv 0x00a34480
bool __fastcall AddSequenceFromOld(NiControllerSequence* sequence, void*, void* a1, SeqController* controller)
{
    FUN_00a34480_obj* pNode = (FUN_00a34480_obj*)controller;
    FUN_00a34480_obj* cur = 0;
    if (a1 != 0)
    {
        if (pNode != 0)
        {
            cur = pNode->V02();
            if (cur != 0)
            {
                do
                {
                    if (cur == (FUN_00a34480_obj*)&DAT_011f36b4)
                    {
                        goto found;
                    }
                    cur = cur->m_pNext;
                } while (cur != 0);
            }
        }
    }
    return false;

found:
    unsigned short flags = (unsigned short)((unsigned short)sequence->m_eAnimationCycleType + (unsigned short)sequence->m_eAnimationCycleType);
    flags = (unsigned short)(flags | (pNode->m_word08 & 0xfff9));
    pNode->m_word08 = flags;
    pNode->m_f0c = sequence->m_fFrequency;
    pNode->m_word08 = (unsigned short)(pNode->m_word08 & 0xffef);
    return sequence->AssignControllers(a1, (NiInterpController*)pNode);
}

extern void* DAT_011f36dc;
extern char DAT_01044a7c, DAT_01096678, DAT_0105ac84, DAT_0109666c;
extern char DAT_01096664, DAT_01044c94, DAT_01044c90, DAT_0109665c;
extern char DAT_01096654, DAT_010477f4, DAT_01096648, DAT_0109663c;
extern char DAT_01096630, DAT_01096624;

struct OutputArray
{
    void* unk00;
    void** data;
    unsigned short capacity;
    unsigned short length;
    unsigned short populated;
    unsigned short growth;
    void FUN_0096ad30(unsigned int capacity);
    void FUN_0096ae90(unsigned int index, void** value);
    void Append(void* value)
    {
        unsigned int index = length;
        if (index >= capacity)
            FUN_0096ad30(index + growth);
        FUN_0096ae90(index, &value);
    }
};

struct ControlItem
{
    void* unk00;
    void* unk04;
    void* unk08;
    unsigned char unk0c;
    unsigned char priority;
    unsigned short unk0e;
};
struct TagItem
{
    const char* first;
    const char* second;
    const char* third;
    const char* fourth;
    const char* fifth;
};

void* __cdecl NiViewerStrings_NiGetViewerString_Title(void*);
void* __cdecl FormatStringWithType(const char*, void*);
void* __cdecl NiGetViewerString_00a7d510(const char*, unsigned int);
void* __cdecl NiGetViewerString_00a7d550(const char*, float);
void* __cdecl NiTimeController_GetViewerString(const char*, void*);
int __cdecl FUN_00a305b0(char*, unsigned int, const char*, ...);
void* __cdecl NiGetViewerString_00a7d5e0(const char*, const char*);

struct Position
{
    unsigned int i;
    unsigned int tagOffset;
};


// Appends the sequence's base data and per-item key/value entries built from each tag and control priority to the output array.
// @fnv 0x00a34540
void NiControllerSequence::AddViewerStrings(NiViewerStringsArray* strings)
{
    OutputArray* output = (OutputArray*)strings;
    NiObject::AddViewerStrings(strings);
    output->Append(NiViewerStrings_NiGetViewerString_Title(DAT_011f36dc));
    output->Append(FormatStringWithType(&DAT_01044a7c, (void*)m_eAnimationState));
    output->Append(NiGetViewerString_00a7d510(&DAT_01096678, m_uiNumControlledBlocks));
    output->Append(NiGetViewerString_00a7d550(&DAT_0105ac84, m_fWeight));
    output->Append(NiTimeController_GetViewerString(&DAT_0109666c, (void*)m_eAnimationCycleType));
    output->Append(NiGetViewerString_00a7d550(&DAT_01096664, m_fFrequency));
    output->Append(NiGetViewerString_00a7d550(&DAT_01044c94, m_fFirstKeyTime));
    output->Append(NiGetViewerString_00a7d550(&DAT_01044c90, m_fLastKeyTime));
    output->Append(NiGetViewerString_00a7d550(&DAT_0109665c, m_fLastTime));
    output->Append(NiGetViewerString_00a7d550(&DAT_01096654, m_fSequenceOffset));
    output->Append(NiGetViewerString_00a7d550(&DAT_010477f4, m_fStartTime));
    output->Append(NiGetViewerString_00a7d550(&DAT_01044c90, m_fEndTime));
    output->Append(NiGetViewerString_00a7d550(&DAT_01096648, m_fWeightAdjustedLastTime));
    output->Append(NiGetViewerString_00a7d550(&DAT_0109663c, m_fScaledLastTime));
    Position pos;
    pos.i = 0;
    if (pos.i < m_uiNumControlledBlocks)
    {
        char key[128];
        char val[256];
        unsigned int controlOffset = 0;
        pos.tagOffset = 0;
        do
        {
            TagItem* tag = (TagItem*)((char*)m_pkIDTags + pos.tagOffset);
            ControlItem* ctrl = (ControlItem*)((char*)m_pInterpArray + controlOffset);
            FUN_00a305b0(key, sizeof(key), &DAT_01096630, pos.i);
            FUN_00a305b0(val, sizeof(val), &DAT_01096624, tag->first, tag->third, ctrl->priority);
            void* entry = NiGetViewerString_00a7d5e0(key, val);
            unsigned int index = output->length;
            if (index >= output->capacity)
                output->FUN_0096ad30(index + output->growth);
            if (index >= output->length)
            {
                output->length = index + 1;
                if (entry)
                    output->populated++;
            }
            else if (entry)
            {
                if (!output->data[index])
                    output->populated++;
            }
            else if (output->data[index])
            {
                output->populated--;
            }
            output->data[index] = entry;
            pos.tagOffset += sizeof(TagItem);
            controlOffset += sizeof(ControlItem);
            ++pos.i;
        } while (pos.i < m_uiNumControlledBlocks);
    }
}

static const float g_fSeqNegInfinity = -3.402823466e+38f;


struct SeqPtrArray
{
    unsigned int AddSeq(NiControllerSequence* const& pkSeq);
};

struct SeqOwner
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
    SeqPtrArray m_kPlayingSequences;
};


__forceinline bool NiControllerSequence::SetState(int state)
{
    bool inactive = m_eAnimationState == INACTIVE;
    m_eAnimationState = (AnimState)state;
    if (inactive)
        ((SeqOwner*)m_pkOwnerManager)->m_kPlayingSequences.AddSeq(this);
    return inactive;
}

// @fnv 0x00a34f20
bool NiControllerSequence::StartSequence(char m_ucRegionPriority, bool bStartOver, float fWeight, float fEaseInTime,
                              NiControllerSequence* pkTimeSyncSeq, bool bTransition)
{
    if (m_eAnimationState != 0)
        return false;

    m_pkTimeSyncSequence = 0;
    if (pkTimeSyncSeq)
    {
        NiControllerSequence* pkPartner = pkTimeSyncSeq->m_pkTimeSyncSequence;
        if (pkPartner)
        {
            if (pkPartner == this || !CanSyncWithSequence(pkPartner))
                return false;
        }
        if (SetTimeSyncSequence(pkTimeSyncSeq))
            m_pkTimeSyncSequence = pkTimeSyncSeq;
        else
            return false;
    }

    m_fWeight = fWeight;
    SetAnimationCycleType(m_ucRegionPriority);

    if (fEaseInTime > 0.0f)
    {
        if (bTransition)
            SetState(5);
        else
            SetState(2);
        m_fStartTime = g_fSeqNegInfinity;
        m_fEndTime = fEaseInTime;
    }
    else
    {
        SetState(1);
        m_fStartTime = 0.0f;
    }

    if (bStartOver)
        m_fSequenceOffset = g_fSeqNegInfinity;
    m_fLastTime = g_fSeqNegInfinity;
    return true;
}


static float NEG_FLT_MAX = -3.402823466e+38f;

// @fnv 0x00a351d0
bool NiControllerSequence::CrossFadeTo(NiControllerSequence* pkDestSequence, float fDuration, int iPriority, float fSourceWeight,
                          float fDestWeight)
{
    Deactivate(0.0f, true);
    if (Activate((char)iPriority, false, fSourceWeight, fDuration, pkDestSequence, true) &&
        pkDestSequence->m_eAnimationState == 0)
    {
        pkDestSequence->m_fWeight = fDestWeight;
        pkDestSequence->m_pkTimeSyncSequence = 0;
        pkDestSequence->SetPriorityStub((char)iPriority);
        if (fDuration > 0.0f)
        {
            pkDestSequence->SetState(5);
            pkDestSequence->m_fStartTime = NEG_FLT_MAX;
            pkDestSequence->m_fEndTime = fDuration;
        }
        else
        {
            pkDestSequence->SetState(1);
            pkDestSequence->m_fStartTime = 0.0f;
        }
        pkDestSequence->m_fSequenceOffset = NEG_FLT_MAX;
        pkDestSequence->m_fLastTime = NEG_FLT_MAX;
        SetState(6);
        return true;
    }
    return false;
}


struct SomeObjectB3718
{
    virtual void V00();
    virtual void V01();
    virtual void V02(void* pv, unsigned int ItemUpdateArray, int iFlag);
};

struct HolderB3718
{
    SomeObjectB3718* m_pEntryObject;
};

extern HolderB3718* DAT_011f6080;

// @fnv 0x00aa10f0
// src: GAMEBRYO_LIB 0x00aa10f0
void __cdecl _NiFree_00aa10f0(void* pv)
{
    if (pv != 0)
    {
        DAT_011f6080->m_pEntryObject->V02(pv, 9, -1);
    }
}

struct FUN_00a30750_shell
{
    char* m_kPointA[5];
    void NiControllerSequence_IDTag_Destroy();
};

extern int EmptyFS;

// @fnv 0x00a30750
// src: COMMUNITY 0x00a30750
void FUN_00a30750_shell::NiControllerSequence_IDTag_Destroy()
{
    char* p;
    p = m_kPointA[4];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[3];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[2];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[1];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
    p = m_kPointA[0];
    if (p != (char*)EmptyFS)
        InterlockedDecrement((long*)(p - 8));
}

struct TCEq
{
    bool IsSameAs(NiObject* other);
};
struct SeqTagCmp
{
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    bool equal(const SeqTagCmp& x) const
    {
        return a == x.a && b == x.b && c == x.c && d == x.d && e == x.e;
    }
};
extern "C" int __cdecl FUN_00aa1360(const char* a, const char* b);
struct SeqTK
{
    NiObject* p;
    operator NiObject*() const
    {
        return p;
    }
    NiObject* operator->() const
    {
        return p;
    }
};

// Compares this sequence with another field by field, including interpolators, tags, text keys and owner, returning true only if all match.
// @fnv 0x00a30fb0
// src: XBOX_PDB 0x00a30fb0
unsigned char NiControllerSequence::IsEqual_00a30fb0(NiControllerSequence* other)
{
    if (!((TCEq*)this)->IsSameAs((NiObject*)other))
        return false;
    if (m_kName.m_kHandle != other->m_kName.m_kHandle && FUN_00aa1360(m_kName.m_kHandle, other->m_kName.m_kHandle))
        return false;
    if (m_uiNumControlledBlocks != other->m_uiNumControlledBlocks || m_uiNumIDTags != other->m_uiNumIDTags)
        return false;
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
    {
        if (!((FUN_00a30cc0_cls*)&m_pInterpArray[i])->Equals((FUN_00a30cc0_cls*)&other->m_pInterpArray[i]))
            return false;
        if (!((SeqTagCmp*)m_pkIDTags)[i].equal(((SeqTagCmp*)other->m_pkIDTags)[i]))
            return false;
    }
    if (m_fWeight != other->m_fWeight)
        return false;
    if (((*(SeqTK*)&m_spTextKeyData) && !(*(SeqTK*)&other->m_spTextKeyData)) || (!(*(SeqTK*)&m_spTextKeyData) && (*(SeqTK*)&other->m_spTextKeyData)))
        return false;
    if ((*(SeqTK*)&m_spTextKeyData) && (*(SeqTK*)&other->m_spTextKeyData) && !((const NiObject*)(*(SeqTK*)&m_spTextKeyData))->IsEqual((*(SeqTK*)&other->m_spTextKeyData)))
        return false;
    if (m_eAnimationCycleType != other->m_eAnimationCycleType)
        return false;
    if (m_fFrequency != other->m_fFrequency || m_fFirstKeyTime != other->m_fFirstKeyTime || m_fLastKeyTime != other->m_fLastKeyTime)
        return false;
    if ((m_pkOwnerManager && !other->m_pkOwnerManager) || (!m_pkOwnerManager && other->m_pkOwnerManager))
        return false;
    if (m_pkOwnerManager && other->m_pkOwnerManager && !((const NiObject*)m_pkOwnerManager)->IsEqual((NiObject*)other->m_pkOwnerManager))
        return false;
    return m_kAccumulationRootName.m_kHandle == other->m_kAccumulationRootName.m_kHandle;
}

extern const char str_01020fd4[];
extern const char str_01020fc8[];
extern const char str_01020fc0[];
extern const char str_01020fb8[];
extern const char str_01020fac[];
extern const char str_01020fa0[];
extern const char str_01020f94[];
extern const char str_0109655c[];
struct S_00a31140_Allocator
{
    void* __thiscall Game_DoHeapAlloc(unsigned int);
};
extern "C" void __cdecl FUN_00ec623a(void*, const char*, const char*, const char*);
// @fnv 0x00a31140
void* __cdecl FormatStringWithType(const char* pcText, void* arg2)
{
    void* esi = ((S_00a31140_Allocator&)DAT_011f6238).Game_DoHeapAlloc((unsigned int)strlen(pcText) + 0x20);
    const char* eax = 0;
    switch ((unsigned int)arg2)
    {
    case 0:
        eax = str_01020fd4;
        break;
    case 1:
        eax = str_01020fc8;
        break;
    case 2:
        eax = str_01020fc0;
        break;
    case 3:
        eax = str_01020fb8;
        break;
    case 4:
        eax = str_01020fac;
        break;
    case 5:
        eax = str_01020fa0;
        break;
    case 6:
        eax = str_01020f94;
        break;
    default:
        break;
    }
    FUN_00ec623a(esi, str_0109655c, pcText, eax);
    return esi;
}

// Copy a group of five ref-counted fixed strings (the ref count sits 8 bytes before the text).

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);


class A1400StringGroup
{
  public:
    NiFixedString m_kName0;
    NiFixedString m_kName1;
    NiFixedString m_kName2;
    NiFixedString m_kName3;
    NiFixedString m_kName4;

    A1400StringGroup& NiControllerSequence_IDTag_Operator_Set(const A1400StringGroup& kOther);
};

// Assigns each of the five fixed-string members from kOther and returns *this.
// @fnv 0x00a31400
// src: COMMUNITY 0x00a31400
A1400StringGroup& A1400StringGroup::NiControllerSequence_IDTag_Operator_Set(const A1400StringGroup& kOther)
{
    m_kName0 = kOther.m_kName0;
    m_kName1 = kOther.m_kName1;
    m_kName2 = kOther.m_kName2;
    m_kName3 = kOther.m_kName3;
    m_kName4 = kOther.m_kName4;
    return *this;
}

struct IDTagA33a50
{
    char* m_kAVObjectName;
    char* m_kPropertyType;
    char* m_kCtlrType;
    char* m_kCtlrID;
    char* m_kInterpolatorID;
    void ReadFromStream(void* streamObject, unsigned int& uiPaletteLink);
};

// @fnv 0x00a33a50
void IDTagA33a50::ReadFromStream(void* streamObject, unsigned int& uiPaletteLink)
{
    NiStream& kStream = *static_cast<NiStream*>(streamObject);
    if (SequenceStreamVersion(kStream) < 0x0A010071)
    {
        kStream.ReadFixedString((NiFixedString&)m_kAVObjectName);
        kStream.ReadFixedString((NiFixedString&)m_kPropertyType);
        kStream.ReadFixedString((NiFixedString&)m_kCtlrType);
        kStream.ReadFixedString((NiFixedString&)m_kCtlrID);
        kStream.ReadFixedString((NiFixedString&)m_kInterpolatorID);
    }
    else if (SequenceStreamVersion(kStream) < 0x14010001)
    {
        uiPaletteLink = (unsigned int)kStream.DeserializeObject();
        unsigned int uiAVObjectNameOffset = 0;
        unsigned int uiPropertyTypeOffset = 0;
        unsigned int uiCtlrTypeOffset = 0;
        unsigned int uiCtlrIDOffset = 0;
        unsigned int uiInterpolatorIDOffset = 0;
        SequenceReadStream(kStream)->ReadScalar(&uiAVObjectNameOffset, 4);
        SequenceReadStream(kStream)->ReadScalar(&uiPropertyTypeOffset, 4);
        SequenceReadStream(kStream)->ReadScalar(&uiCtlrTypeOffset, 4);
        SequenceReadStream(kStream)->ReadScalar(&uiCtlrIDOffset, 4);
        SequenceReadStream(kStream)->ReadScalar(&uiInterpolatorIDOffset, 4);
        m_kAVObjectName = (char*)uiAVObjectNameOffset;
        m_kPropertyType = (char*)uiPropertyTypeOffset;
        m_kCtlrType = (char*)uiCtlrTypeOffset;
        m_kCtlrID = (char*)uiCtlrIDOffset;
        m_kInterpolatorID = (char*)uiInterpolatorIDOffset;
    }
    else
    {
        kStream.ReadStringTableEntry((NiFixedString&)m_kAVObjectName);
        kStream.ReadStringTableEntry((NiFixedString&)m_kPropertyType);
        kStream.ReadStringTableEntry((NiFixedString&)m_kCtlrType);
        kStream.ReadStringTableEntry((NiFixedString&)m_kCtlrID);
        kStream.ReadStringTableEntry((NiFixedString&)m_kInterpolatorID);
    }
}

struct UpdateActiveArray
{
    void FindOrAdd(NiControllerSequence* const& sequence);
};
struct UpdateNote
{
    int unk00;
    int unk04;
    int unk08;
    float time;
};
struct UpdateNoteManager
{
    void DispatchByKey(UpdateNote* note);
};
struct UpdateOwner
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
    UpdateActiveArray active;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    UpdateNoteManager* noteManager;
};

// @fnv 0x00a34ba0
// src: XBOX_PDB 0x00a34ba0
void NiControllerSequence::Update_00a34ba0(float time, bool update)
{
    if (m_eAnimationState == 0)
    {
        m_sAnimNotesExtraDataIndex = -1;
        return;
    }
    if (m_fSequenceOffset == g_fSeqNegInfinity)
        m_fSequenceOffset = -time;
    if (m_fStartTime == g_fSeqNegInfinity)
    {
        m_fStartTime = time;
        m_fEndTime += time;
    }
    float ease = 1.0f;
    float transition = 1.0f;
    switch (m_eAnimationState)
    {
    case 2:
        if (m_fEndTime > time)
        {
            if (m_fStartTime > time)
                time = m_fStartTime;
            ease = (time - m_fStartTime) / (m_fEndTime - m_fStartTime);
        }
        else
        {
            m_eAnimationState = ANIMATING;
            m_fStartTime = 0.0f;
        }
        break;
    case 5:
        if (m_fEndTime > time)
        {
            if (m_fStartTime > time)
                time = m_fStartTime;
            transition = (time - m_fStartTime) / (m_fEndTime - m_fStartTime);
        }
        else
        {
            if (m_fDestinationFrame != g_fSeqNegInfinity)
            {
                m_fSequenceOffset = m_fDestinationFrame - time;
                m_fDestinationFrame = DAT_01015f5c;
            }
            m_eAnimationState = ANIMATING;
            m_fStartTime = 0.0f;
        }
        break;
    case 3:
        if (m_fEndTime > time)
        {
            if (m_fStartTime > time)
                time = m_fStartTime;
            ease = (m_fEndTime - time) / (m_fEndTime - m_fStartTime);
        }
        else
        {
            Deactivate(0.0f, false);
            return;
        }
        break;
    case 6: {
        float partnerTime = m_pkTimeSyncSequence->GetMorphedTime(this, time + m_fSequenceOffset);
        partnerTime /= m_pkTimeSyncSequence->m_fFrequency;
        m_pkTimeSyncSequence->m_fSequenceOffset = partnerTime - time;
        SetState(4);
    }
    case 4:
        if (m_fEndTime > time)
        {
            if (m_fStartTime > time)
                time = m_fStartTime;
            transition = (m_fEndTime - time) / (m_fEndTime - m_fStartTime);
        }
        else
        {
            Deactivate(0.0f, true);
            return;
        }
        break;
    case 1:
        m_fStartTime = m_fScaledLastTime;
        break;
    }
    float fOldScaledTime = m_fScaledLastTime;
    if (update)
    {
        float localTime;
        if (m_fDestinationFrame != g_fSeqNegInfinity)
            localTime = m_fDestinationFrame;
        else if (m_pkTimeSyncSequence)
        {
            if (m_pkTimeSyncSequence->m_fLastTime != time + m_pkTimeSyncSequence->m_fSequenceOffset)
                m_pkTimeSyncSequence->Update_00a34ba0(time, false);
            localTime = GetMorphedTime(m_pkTimeSyncSequence, time + m_pkTimeSyncSequence->m_fSequenceOffset);
            localTime /= m_fFrequency;
        }
        else
            localTime = time + m_fSequenceOffset;
        NiControllerSequence_SetInterpsWeightAndTime(m_fWeight * transition, ease, ComputeScaledTime_00a30970(localTime, true));
        if (((UpdateNote**)m_pkAnimNotes))
        {
            if (fOldScaledTime > m_fScaledLastTime)
                m_sAnimNotesExtraDataIndex = -1;
            for (short i = m_sAnimNotesExtraDataIndex + 1; i < m_usNumAnimNotes; ++i)
            {
                if (!(((UpdateNote**)m_pkAnimNotes)[i]->time < localTime))
                    break;
                m_sAnimNotesExtraDataIndex = i;
                ((UpdateOwner*)m_pkOwnerManager)->noteManager->DispatchByKey(((UpdateNote**)m_pkAnimNotes)[i]);
            }
        }
    }
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
static inline void RetainSequenceRef(NiRefObject* object)
{
    InterlockedIncrement((long volatile*)&object->m_uiRefCount);
}
static inline void ReleaseSequenceRef(NiRefObject* object)
{
    if (InterlockedDecrement((long volatile*)&object->m_uiRefCount) == 0)
        object->DeleteThis();
}

struct NiPointerRef
{
    NiRefObject* m_pObject;
    void operator=(NiRefObject* p)
    {
        NiRefObject* pOld = m_pObject;
        NiRefObject* pNew = p;
        if (pOld != pNew)
        {
            if (pOld)
                ReleaseSequenceRef(pOld);
            m_pObject = pNew;
            if (pNew)
                RetainSequenceRef(pNew);
        }
    }
};

struct NiItem
{
    unsigned int m0;
    NiPointerRef object4;
    unsigned int m8;
    unsigned int mc;
};


// @fnv 0x00a326e0
void NiControllerSequence::LinkSequenceSource(NiStream* source)
{
    NiObject::LinkObject(*(NiStream*)source);
    if (SequenceStreamVersion(*source) < 0x0a010068)
    {
        (*(NiPointerRef*)&m_spTextKeyData) = (NiRefObject*)source->GetLoadedObject();
        unsigned int i = 0;
        if (i < m_uiNumControlledBlocks)
        {
            do
            {
                ((NiItem*)m_pInterpArray)[i].object4 = (NiRefObject*)source->GetLoadedObject();
                ++i;
            } while (i < m_uiNumControlledBlocks);
        }
    }
    else
    {
        (*(NiPointerRef*)&m_spTextKeyData) = (NiRefObject*)source->GetLoadedObject();
        (*(NiRefObject**)&m_pkOwnerManager) = (NiRefObject*)source->GetLoadedObject();
        if (SequenceStreamCount(*source) > 0x15 && SequenceStreamCount(*source) < 0x1d)
        {
            (NiRefObject*)source->GetLoadedObject();
            (*(NiPointerRef**)&m_pkAnimNotes) = 0;
            m_usNumAnimNotes = 0;
        }
        if (SequenceStreamCount(*source) > 0x1c)
        {
            unsigned short i = 0;
            if (i < m_usNumAnimNotes)
            {
                do
                {
                    (*(NiPointerRef**)&m_pkAnimNotes)[i] = (NiRefObject*)source->GetLoadedObject();
                    ++i;
                } while (i < m_usNumAnimNotes);
            }
        }
    }
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct A33950Object
{
    NiRefObject* first;
    NiRefObject* second;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;
    unsigned char flag0d;
    void LoadFromStream(void* streamObject);
};

// @fnv 0x00a33950
void A33950Object::LoadFromStream(void* streamObject)
{
    NiStream* stream = static_cast<NiStream*>(streamObject);
    NiRefObject* next = (NiRefObject*)stream->DeserializeObject();
    NiRefObject* previous = first;
    if (previous != next)
    {
        if (previous && InterlockedDecrement((long volatile*)&previous->m_uiRefCount) == 0)
            previous->DeleteThis();
        first = next;
        if (next)
            DAT_00fdf1c0((void*)(long volatile*)&next->m_uiRefCount);
    }

    next = (NiRefObject*)stream->DeserializeObject();
    previous = second;
    if (previous != next)
    {
        if (previous && InterlockedDecrement((long volatile*)&previous->m_uiRefCount) == 0)
            previous->DeleteThis();
        second = next;
        if (next)
            DAT_00fdf1c0((void*)(long volatile*)&next->m_uiRefCount);
    }

    if (SequenceStreamVersion(*stream) < 0x0a01006f)
    {
        unsigned short oldValue;
        (NiRefObject*)stream->DeserializeObject();
        SequenceReadStream(*stream)->ReadScalar(&oldValue, 2);
    }
    if (SequenceStreamCount(*stream) > 0)
        SequenceReadStream(*stream)->ReadScalar(&flag0d, 1);
}

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int size);


// @fnv 0x00a344f0
NiObject* NiControllerSequence::MakeClone(CloningProcess& cloning)
{
    void* p = Object_DispatchCommandFour(0x74);
    void* result = p ? ((NiControllerSequence*)p)->FUN_00a316a0() : 0;
    NiControllerSequence_CopyMembers((NiControllerSequence*)result, (int)&cloning);
    return (NiObject*)result;
}

extern const float DAT_010141cc;


// @fnv 0x00a350d0
// src: XBOX_PDB 0x00a350d0
bool NiControllerSequence::StartBlend(NiControllerSequence* pkTarget, float fTime, float m_fTimeout, int iPriority, float fSeqWeight,
                                    float fTargetWeight, NiControllerSequence* pkPartner)
{
    Deactivate(0.0f, true);

    if (fTime <= 0.0f)
        fTime = DAT_010141cc;

    if (pkTarget->m_eAnimationState != 0 || m_eAnimationState != 0)
        return false;

    m_fWeight = fSeqWeight;
    m_pkTimeSyncSequence = 0;

    SetAnimationCycleType((char)iPriority);
    SetState(1);

    m_fStartTime = 0.0f;
    m_fLastTime = DAT_01015f5c;

    if (!pkTarget->StartSequence((char)iPriority, false, fTargetWeight, fTime, pkPartner, true))
        return false;

    Deactivate(fTime, true);

    m_fDestinationFrame = m_fScaledLastTime / m_fFrequency;
    pkTarget->m_fDestinationFrame = m_fTimeout / pkTarget->m_fFrequency;
    return true;
}


struct SeqIDTagOffsets
{
    NiFixedString m_kAVObjectName;
    NiFixedString m_kPropertyType;
    NiFixedString m_kCtlrType;
    NiFixedString m_kCtlrID;
    NiFixedString m_kInterpolatorID;
    void LoadFromPalette(NiStringPalette* pkPalette, int iUnused);
};

// Resolves five string offsets against pkPalette->m_pString, assigning each to the matching NiFixedString field when the offset is not -1.
// @fnv 0x00a30d40
void SeqIDTagOffsets::LoadFromPalette(NiStringPalette* pkPalette, int iUnused)
{
    int iAVObjectNameOffset = (int)m_kAVObjectName.m_kHandle;
    int iPropertyTypeOffset = (int)m_kPropertyType.m_kHandle;
    int iCtlrTypeOffset = (int)m_kCtlrType.m_kHandle;
    int iCtlrIDOffset = (int)m_kCtlrID.m_kHandle;
    int iInterpolatorIDOffset = (int)m_kInterpolatorID.m_kHandle;
    char* pcNullHandle = NiGlobalStringTable::ms_pcEmptyString;
    NiFixedString* apkOffsets[5] = {&m_kAVObjectName, &m_kPropertyType, &m_kCtlrType, &m_kCtlrID, &m_kInterpolatorID};
    for (int i = 0; i < 5; i++)
        apkOffsets[i]->m_kHandle = pcNullHandle;

    if (iAVObjectNameOffset != -1)
        m_kAVObjectName = pkPalette->m_pString + iAVObjectNameOffset;
    if (iPropertyTypeOffset != -1)
        m_kPropertyType = pkPalette->m_pString + iPropertyTypeOffset;
    if (iCtlrTypeOffset != -1)
        m_kCtlrType = pkPalette->m_pString + iCtlrTypeOffset;
    if (iCtlrIDOffset != -1)
        m_kCtlrID = pkPalette->m_pString + iCtlrIDOffset;
    if (iInterpolatorIDOffset != -1)
        m_kInterpolatorID = pkPalette->m_pString + iInterpolatorIDOffset;

    NiGlobalStringTable::DecRefCount(pcNullHandle);
}


struct A31500Item
{
    NiRefObject* m_spControllerInterpolator;
    NiRefObject* m_pkController;
    void* m_pkBlendInterpolator;
    unsigned int m_uiValue1;

    static void Release(NiRefObject* pkObject)
    {
        if (pkObject && InterlockedDecrement((long*)&pkObject->m_uiRefCount) == 0)
            pkObject->DeleteThis();
    }

    void ReleaseRefs();
    A31500Item* NiControllerSequence_InterpArrayItem_Free(unsigned char m_ucEntryType);
};

// Releases references for this item or preceding items, conditionally calls another function, and returns this or the count address.
// @fnv 0x00a31500
// src: COMMUNITY 0x00a31500
A31500Item* A31500Item::NiControllerSequence_InterpArrayItem_Free(unsigned char m_ucEntryType)
{
    if (m_ucEntryType & 2)
    {
        int* piItemCount = reinterpret_cast<int*>(this) - 1;
        int iItemCount = *piItemCount;
        A31500Item* pkItem = this + iItemCount;
        while (--iItemCount >= 0)
        {
            --pkItem;
            Release(pkItem->m_pkController);
            Release(pkItem->m_spControllerInterpolator);
        }
        if (m_ucEntryType & 1)
            DAT_011f6238.MemoryManager_Deallocate(piItemCount);
        return reinterpret_cast<A31500Item*>(piItemCount);
    }
    ReleaseRefs();
    if (m_ucEntryType & 1)
        DAT_011f6238.MemoryManager_Deallocate(this);
    return this;
}

struct Rtti31910
{
    const char* name;
    Rtti31910* parent;
};
struct Node31910;
struct Blend31910
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags;
};
struct BlendTransform31910
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char flags;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct MorphItem31910
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
    const char* name;
};
struct Morph31910
{
    int unk00;
    int unk04;
    int unk08;
    MorphItem31910* items;
    unsigned int count;
};
struct Node31910
{
    virtual void V00();
    virtual void V01();
    virtual Rtti31910* GetRTTI();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual Node31910* FindObject(const void*);
    virtual void V36();
    virtual void V37();
    virtual void SetTarget(Node31910*);
    long refCount;
    union
    {
        const char* name;
        unsigned short flags08;
    };
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int flags30;

    Node31910* NiObjectNET_GetController(const void*);
    void NiObjectNET_RemoveController(Node31910*);
    unsigned int FUN_00dbbc10();
};
struct NiSingleInterpControllerBase : Node31910
{
    NiSingleInterpControllerBase();
};
struct MorphController31910 : NiSingleInterpControllerBase
{
    BlendTransform31910* blends;
    Node31910** targets;
    unsigned short count;
    unsigned short unk3e;
    unsigned short FindIndexByValue(Node31910*);
    unsigned short BSMultiTargetTreadTransfController_AddInterpolatorTarget(Node31910*, unsigned short, MorphItem31910*);
    void SetSlotEntry(unsigned short, Node31910*, unsigned short, MorphItem31910*);
    Blend31910* FUN_00a358a0(unsigned short);
    MorphController31910* FUN_00a36070(unsigned short, unsigned short);
};
struct Owner31910
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
    Node31910* root;
    Node31910* controller;
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
    unsigned char skipAccum;
};
struct Entry31910
{
    Morph31910* interpolator;
    Node31910* controller;
    Blend31910* blend;
    unsigned char index;
    unsigned char priority;
    unsigned short unk0e;
};

extern Rtti31910 DAT_011f36bc, DAT_011f36e4, DAT_011f4a04, g_011f36ec;
extern unsigned int DAT_011f36c8, DAT_011f36d0;
extern const char* DAT_011f36c4;
extern const char* DAT_011f36cc;
extern const char DAT_01096564, DAT_0101e460;
extern unsigned short DAT_01096320;
extern void* DAT_01096444;
char* __cdecl FUN_00a5b690(const char*);
void __cdecl FUN_00fdad60();
void __cdecl FUN_00fdad80();
extern "C" int __cdecl atexit(void(__cdecl*)());
void* __cdecl Object_DispatchCommandFour(unsigned int);
// The shared NiInterpController has no explicit constructor declaration.
// Initialize that base through the original constructor before the shared fields.
void* __fastcall NiInterpController_NiInterpController(void*);
static inline NiMultiTargetTransformController* ConstructMultiTargetController(
    NiMultiTargetTransformController* controller, unsigned short count)
{
    NiInterpController_NiInterpController(controller);
    *reinterpret_cast<void**>(controller) = &DAT_01096444;
    controller->m_usNumInterps = 0;
    controller->m_pkBlendInterpolators = 0;
    controller->m_ppTargetObjects = 0;
    controller->AllocateStorage(count);
    return controller;
}
void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
static bool IsKind31910(Node31910* node, Rtti31910* type)
{
    Rtti31910* rtti = node->GetRTTI();
    while (rtti)
    {
        if (rtti == type)
            return true;
        rtti = rtti->parent;
    }
    return false;
}
static void Retain31910(Node31910* p)
{
    if (p)
        InterlockedIncrement(&p->refCount);
}
static void Release31910(Node31910* p)
{
    if (p && !InterlockedDecrement(&p->refCount))
        p->V01();
}
struct ControllerPtr31910
{
    MorphController31910* p;
    ControllerPtr31910(MorphController31910* v) : p(v)
    {
        Retain31910(p);
    }
    operator MorphController31910*() const
    {
        return p;
    }
    MorphController31910* operator->() const
    {
        return p;
    }
    ControllerPtr31910& operator=(MorphController31910* v)
    {
        if (p != v)
        {
            Release31910(p);
            p = v;
            Retain31910(p);
        }
        return *this;
    }
};
static void Assign31910(Node31910*& dst, Node31910* src)
{
    if (dst != src)
    {
        Release31910(dst);
        dst = src;
        Retain31910(src);
    }
}
static const char* MorphType31910()
{
    if (!(DAT_011f36c8 & 1))
    {
        DAT_011f36c8 |= 1;
        DAT_011f36c4 = FUN_00a5b690(&DAT_01096564);
        atexit(FUN_00fdad60);
    }
    return DAT_011f36c4;
}
static __forceinline unsigned short FindTarget31910(NiMultiTargetTransformController* c, Node31910* node)
{
    for (unsigned short i = 0; i < c->m_usNumInterps; ++i)
        if (c->m_ppTargetObjects[i] == (NiAVObject*)node)
            return i;
    return DAT_01096320;
}
static __forceinline unsigned short AddTarget31910(NiMultiTargetTransformController* c, Node31910* node)
{
    for (unsigned short i = 0; i < c->m_usNumInterps; ++i)
        if (!c->m_ppTargetObjects[i])
        {
            c->m_ppTargetObjects[i] = (NiAVObject*)node;
            node->flags30 |= 0x80;
            return i;
        }
    return DAT_01096320;
}
// @fnv 0x00a31910
// src: COMMUNITY 0x00a31910
bool NiControllerSequence::ResolveTransformInterpolators(NiAVObject* targetObject, NiAVObject* rootObject, int unused)
{
    Node31910* target = (Node31910*)targetObject;
    Node31910* root = (Node31910*)rootObject;
    bool spMorphController;
    spMorphController = false;
    NiMultiTargetTransformController* ctrl = (NiMultiTargetTransformController*)target->NiObjectNET_GetController(&DAT_011f36bc);
    Retain31910((Node31910*)ctrl);
    MorphController31910* pMorphCtrl = (MorphController31910*)target->NiObjectNET_GetController(&DAT_011f36e4);
    Retain31910(pMorphCtrl);
    unsigned short uiMorphEntries = 0, usMorphTargetCount = 0;
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; i++)
    {
        TagItem& v = ((TagItem*)m_pkIDTags)[i];
        if (v.third != (const char*)DAT_0109b220 && MorphType31910() == v.third)
        {
            usMorphTargetCount += (unsigned short)((Entry31910*)m_pInterpArray)[i].interpolator->count;
            ++uiMorphEntries;
        }
    }
    if (!ctrl || (!pMorphCtrl && uiMorphEntries))
    {
        unsigned short usExistingTargets = 0;
        Node31910* morphIndex = 0;
        if (root)
        {
            morphIndex = IsKind31910(root, &DAT_011f4a04) ? root : 0;
        }
        if (morphIndex)
            usExistingTargets = (unsigned short)(morphIndex->FUN_00dbbc10() - usMorphTargetCount);
        else
            for (unsigned int i = 0; m_uiNumControlledBlocks > i; i++)
            {
                const char* cnt;
                cnt = ((TagItem*)m_pkIDTags)[i].third;
                if (cnt != (const char*)DAT_0109b220 && cnt && cnt[2] == 'T' && cnt[7] == 'f')
                    usExistingTargets++;
            }
        if (!usExistingTargets && !uiMorphEntries)
        {
            Release31910(pMorphCtrl);
            Release31910((Node31910*)ctrl);
            return false;
        }
        if (usExistingTargets && !ctrl)
        {
            MorphController31910* tag;
            tag = (MorphController31910*)Object_DispatchCommandFour(0x40);
            if (tag)
            {
                ctrl = ConstructMultiTargetController((NiMultiTargetTransformController*)tag, usExistingTargets);
                Retain31910((Node31910*)ctrl);
            }
            ctrl->SetTarget((NiObjectNET*)target);
            ctrl->m_uiObjectFlags |= 0x20;
            spMorphController = true;
            if (target == ((Owner31910*)m_pkOwnerManager)->root)
            {
                target->NiObjectNET_RemoveController((Node31910*)ctrl);
                Assign31910((Node31910*&)ctrl->m_spNextController.m_pObject, ((Owner31910*)m_pkOwnerManager)->controller);
                Assign31910(((Owner31910*)m_pkOwnerManager)->controller, (Node31910*)ctrl);
            }
        }
        if (uiMorphEntries && !pMorphCtrl)
        {
            MorphController31910* tag = (MorphController31910*)Object_DispatchCommandFour(0x44);
            if (tag)
            {
                tag = tag->FUN_00a36070(uiMorphEntries, usMorphTargetCount);
                if (tag)
                {
                    pMorphCtrl = tag;
                    Retain31910(pMorphCtrl);
                }
            }
            pMorphCtrl->SetTarget(target);
            pMorphCtrl->flags08 |= 0x20;
            spMorphController = true;
            if (target == ((Owner31910*)m_pkOwnerManager)->root)
            {
                target->NiObjectNET_RemoveController(pMorphCtrl);
                Assign31910((Node31910*&)pMorphCtrl->flags30, ((Owner31910*)m_pkOwnerManager)->controller);
                Assign31910(((Owner31910*)m_pkOwnerManager)->controller, pMorphCtrl);
            }
        }
    }
    int idx = 0;
    if (!(DAT_011f36d0 & 1))
    {
        DAT_011f36d0 |= 1;
        DAT_011f36cc = FUN_00a5b690(&DAT_0101e460);
        atexit(FUN_00fdad80);
    }
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; i++)
    {
        Entry31910& entry = ((Entry31910*)m_pInterpArray)[i];
        TagItem& v = ((TagItem*)m_pkIDTags)[i];
        if (v.third != (const char*)DAT_0109b220 && v.third && v.third[2] == 'T' && v.third[7] == 'f')
        {
            Node31910* spTransformController = root->FindObject(&v);
            if (!spTransformController || ((*(Node31910**)&m_pkAccumulationRoot) == spTransformController && ((Owner31910*)m_pkOwnerManager)->skipAccum))
                continue;
            Node31910* z = spTransformController->NiObjectNET_GetController(&g_011f36ec);
            unsigned short s = FindTarget31910(ctrl, spTransformController);
            if (s == DAT_01096320)
            {
                s = AddTarget31910(ctrl, spTransformController);
                if (s == DAT_01096320)
                    continue;
            }
            else
            {
                ctrl->m_ppTargetObjects[s] = (NiAVObject*)spTransformController;
                spTransformController->flags30 |= 0x80;
            }
            if (spTransformController->name != DAT_011f36cc)
                spTransformController->NiObjectNET_RemoveController(z);
            Assign31910(entry.controller, (Node31910*)ctrl);
            entry.blend = (Blend31910*)&ctrl->m_pkBlendInterpolators[s];
            entry.blend->flags |= 1;
        }
        else if (v.third != (const char*)DAT_0109b220 && MorphType31910() == v.third)
        {
            Morph31910* interp = entry.interpolator;
            volatile unsigned int s;
            for (unsigned int j = 0; j < interp->count; j++)
            {
                MorphItem31910* item = &interp->items[j];
                Node31910* spTransformController = root->FindObject(&item->name);
                unsigned short usMorphSlot = pMorphCtrl->FindIndexByValue(spTransformController);
                if (usMorphSlot == DAT_01096320)
                    s = pMorphCtrl->BSMultiTargetTreadTransfController_AddInterpolatorTarget(spTransformController, idx, item);
                else
                    pMorphCtrl->SetSlotEntry(usMorphSlot, spTransformController, idx, item);
            }
            Assign31910(entry.controller, pMorphCtrl);
            entry.blend = pMorphCtrl->FUN_00a358a0(idx);
            entry.blend->flags |= 1;
            idx += 1;
        }
    }
    Release31910(pMorphCtrl);
    Release31910((Node31910*)ctrl);
    return spMorphController;
}

struct TimedTextEntry
{
    float m_fTime;
    char* m_kText;

    float GetTime() const
    {
        return m_fTime;
    }
    const char* GetText() const
    {
        return m_kText;
    }
};

extern const char* ms_kMorphTextKey;
extern int ms_iMorphTextKeyLength;
int __cdecl NiStrnicmp(const char*, const char*, unsigned int);
int __cdecl FUN_00aa1360(const char*, const char*);

// Interpolates between matching key times in this sequence using surrounding morph-key times from the partner sequence.
// @fnv 0x00a32010
float NiControllerSequence::GetMorphedTime(NiControllerSequence* pkPartnerSequence, float fFrameTime)
{
    TimedTextEntry* pkNextKey = 0;
    float fPartnerTime = pkPartnerSequence->ComputeScaledTime_00a30970(fFrameTime, false);

    unsigned int uiNumPartnerKeys;
    TimedTextEntry* pkPartnerKeys = ((NiTextKeyExtraData*)pkPartnerSequence->m_spTextKeyData.m_pObject)->GetKeys(uiNumPartnerKeys);

    TimedTextEntry* pkFirstKey = 0;
    TimedTextEntry* pkPrevKey = 0;
    TimedTextEntry* pkLastKey = 0;
    unsigned int ui;
    for (ui = 0; ui < uiNumPartnerKeys; ui++)
    {
        const char* pcText = pkPartnerKeys[ui].GetText();
        if (pcText && NiStrnicmp(pcText, ms_kMorphTextKey, ms_iMorphTextKeyLength) == 0)
        {
            pkLastKey = &pkPartnerKeys[ui];
            if (!pkFirstKey)
                pkFirstKey = &pkPartnerKeys[ui];

            if (pkPartnerKeys[ui].GetTime() < fPartnerTime)
                pkPrevKey = &pkPartnerKeys[ui];
            else if (!pkNextKey)
                pkNextKey = &pkPartnerKeys[ui];
        }
    }

    bool bHasKeyPair = false;
    float fRatio;
    if (pkNextKey && pkPrevKey)
    {
        float fPriorKeyTime = pkPrevKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (pkNextKey->GetTime() - fPriorKeyTime);
    }
    else if (!pkNextKey)
    {
        float fPriorKeyTime = pkPrevKey->GetTime();
        float fNextTime = pkPartnerSequence->m_fLastKeyTime - pkPartnerSequence->m_fFirstKeyTime + pkFirstKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (fNextTime - fPriorKeyTime);
        pkNextKey = pkFirstKey;
        bHasKeyPair = true;
    }
    else
    {
        float fPriorKeyTime = pkPartnerSequence->m_fFirstKeyTime - pkPartnerSequence->m_fLastKeyTime + pkLastKey->GetTime();
        fRatio = (fPartnerTime - fPriorKeyTime) / (pkNextKey->GetTime() - fPriorKeyTime);
        pkPrevKey = pkLastKey;
    }

    unsigned int uiNumKeys;
    TimedTextEntry* pkKeys = ((NiTextKeyExtraData*)m_spTextKeyData.m_pObject)->GetKeys(uiNumKeys);

    bool bFoundPrev = (pkPrevKey == 0);
    bool bFoundNext = (pkNextKey == 0);
    TimedTextEntry* pkMatchPrev = 0;
    TimedTextEntry* pkMatchNext = 0;
    for (ui = 0; ui < uiNumKeys; ui++)
    {
        if (bFoundPrev && bFoundNext)
            break;

        if (!bFoundPrev && FUN_00aa1360(pkKeys[ui].GetText(), pkPrevKey->GetText()) == 0)
        {
            pkMatchPrev = &pkKeys[ui];
            bFoundPrev = true;
        }
        if (!bFoundNext && FUN_00aa1360(pkKeys[ui].GetText(), pkNextKey->GetText()) == 0)
        {
            pkMatchNext = &pkKeys[ui];
            bFoundNext = true;
        }
    }

    float fNextTime = 0.0f;
    float fPriorKeyTime = 0.0f;
    if (pkMatchPrev == pkMatchNext)
    {
        fPriorKeyTime = pkMatchPrev->GetTime();
        fNextTime = pkMatchNext->GetTime();
        if (bHasKeyPair)
            fNextTime += m_fLastKeyTime - m_fFirstKeyTime;
        else
            fPriorKeyTime -= m_fLastKeyTime - m_fFirstKeyTime;
    }
    else
    {
        if (pkMatchNext)
            fNextTime = pkMatchNext->GetTime();
        if (pkMatchPrev)
            fPriorKeyTime = pkMatchPrev->GetTime();
        if (fPriorKeyTime > fNextTime)
            fNextTime += m_fLastKeyTime - m_fFirstKeyTime;
    }

    float fTime = fPriorKeyTime + (fNextTime - fPriorKeyTime) * fRatio;
    if (fTime < m_fFirstKeyTime)
        fTime += m_fLastKeyTime - m_fFirstKeyTime;
    else if (fTime > m_fLastKeyTime)
        fTime -= m_fLastKeyTime - m_fFirstKeyTime;
    return fTime;
}

struct CloneMap
{
    bool FUN_00a53c30(NiObject* const key, NiObject*& val) const;
};
struct CloneContext
{
    CloneMap* map;
};

struct ClonePointer
{
    NiObject* object;
    operator NiObject*() const
    {
        return object;
    }
    bool operator==(const NiObject* other) const
    {
        return object == other;
    }
    NiObject* operator->() const
    {
        return object;
    }
    void Assign(NiObject* other)
    {
        NiObject* old = object;
        if (old != other)
        {
            if (old && !InterlockedDecrement((long*)&old->m_uiRefCount))
                old->DeleteThis();
            object = other;
            if (other)
                InterlockedIncrement((long*)&other->m_uiRefCount);
        }
    }
    void Assign(const ClonePointer& ptr)
    {
        NiObject* old = object;
        if (old != ptr.object)
        {
            if (old && !InterlockedDecrement((long*)&old->m_uiRefCount))
                old->DeleteThis();
            NiObject* next = ptr.object;
            object = next;
            if (next)
                InterlockedIncrement((long*)&next->m_uiRefCount);
        }
    }
    void AssignRef(NiObject* const& other)
    {
        NiObject* old = object;
        if (old != other)
        {
            if (old && !InterlockedDecrement((long*)&old->m_uiRefCount))
                old->DeleteThis();
            NiObject* next = other;
            object = next;
            if (next)
                InterlockedIncrement((long*)&next->m_uiRefCount);
        }
    }
};
struct CloneItem
{
    ClonePointer interpolator;
    ClonePointer controller;
    void* blend;
    unsigned char index, priority, unk0e, unk0f;
    void FUN_00a5f860(void*);
    void FUN_00c663d0(const CloneItem&);
};

// Calls FUN_00a5d430, processes or looks up item objects, then assigns mapped or original pointers to the copy's fields.
// @fnv 0x00a32470
void NiControllerSequence::ProcessClone(CloningProcess& cloning)
{
    CloneContext& context = (CloneContext&)cloning;
    NiObject::ProcessClone(cloning);
    NiObject* clone = 0;
    context.map->FUN_00a53c30((NiObject*)this, clone);
    NiControllerSequence* copy = (NiControllerSequence*)clone;
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
    {
        if (((CloneItem*)m_pInterpArray)[i].interpolator == 0)
            continue;
        CloneItem& item = ((CloneItem*)m_pInterpArray)[i];
        if (!(*(void**)&m_pkOwnerManager))
        {
            ((CloneItem*)m_pInterpArray)[i].interpolator->ProcessClone((CloningProcess&)context);
            NiObject* controller = ((CloneItem*)m_pInterpArray)[i].controller;
            if (controller)
                controller->ProcessClone((CloningProcess&)context);
        }
        else
        {
            NiObject* interp = item.interpolator;
            if (!m_eAnimationState)
                interp->ProcessClone((CloningProcess&)context);
            else
            {
                bool found = context.map->FUN_00a53c30(interp, clone);
                CloneItem& dest = ((CloneItem*)copy->m_pInterpArray)[i];
                if (found)
                    dest.FUN_00a5f860(clone);
                else
                    dest.FUN_00c663d0(((CloneItem*)m_pInterpArray)[i]);
            }
            if (context.map->FUN_00a53c30(((CloneItem*)m_pInterpArray)[i].controller, clone))
            {
                NiObject* old = ((CloneItem*)copy->m_pInterpArray)[i].controller;
                ClonePointer* volatile dest = &((CloneItem*)copy->m_pInterpArray)[i].controller;
                NiObject* next = *(NiObject* volatile*)&clone;
                if (old != next)
                {
                    if (old)
                    {
                        if (!InterlockedDecrement((long*)&old->m_uiRefCount))
                            old->DeleteThis();
                        next = *(NiObject* volatile*)&clone;
                    }
                    dest->object = next;
                    if (next)
                        InterlockedIncrement((long*)&next->m_uiRefCount);
                }
            }
            else
                ((CloneItem*)copy->m_pInterpArray)[i].controller.Assign(((CloneItem*)m_pInterpArray)[i].controller);
            if (context.map->FUN_00a53c30((NiObject*)((CloneItem*)m_pInterpArray)[i].blend, clone))
                ((CloneItem*)copy->m_pInterpArray)[i].blend = clone;
            else
                ((CloneItem*)copy->m_pInterpArray)[i].blend = ((CloneItem*)m_pInterpArray)[i].blend;
        }
    }
    if (context.map->FUN_00a53c30((NiObject*)(*(void**)&m_pkOwnerManager), clone))
        (*(void**)&copy->m_pkOwnerManager) = clone;
    else
        (*(void**)&copy->m_pkOwnerManager) = (*(void**)&m_pkOwnerManager);
    if (context.map->FUN_00a53c30((NiObject*)(*(void**)&m_pkTimeSyncSequence), clone))
        (*(void**)&copy->m_pkTimeSyncSequence) = clone;
    else
        (*(void**)&copy->m_pkTimeSyncSequence) = (*(void**)&m_pkTimeSyncSequence);
    if (context.map->FUN_00a53c30((NiObject*)(*(void**)&m_pkAccumulationRoot), clone))
        (*(void**)&copy->m_pkAccumulationRoot) = clone;
    else
        (*(void**)&copy->m_pkAccumulationRoot) = (*(void**)&m_pkAccumulationRoot);
}

struct Ctl43c
{
    void NiControllerSequence_InterpArrayItem_Free(int iFlags);
    void NiControllerSequence_IDTag_Free(int iFlags);
};


// Releases each ref returned by pkSrc->AssignInterpolatorRef, calls both controller methods, then invokes the base handler.


// @fnv 0x00a343c0
void NiControllerSequence::ClearInterpolatorRefs(NiControllerSequence* pkSrc, int iArg)
{
    for (unsigned int i = 0; i < pkSrc->m_uiNumControlledBlocks; i++)
    {
        NiRefObject* pObj = 0;
        pkSrc->AssignInterpolatorRef((int)i, &pObj);
        if (pObj)
            pObj->DecRefCount();
    }
    if (pkSrc->m_pInterpArray)
        ((Ctl43c*)pkSrc->m_pInterpArray)->NiControllerSequence_InterpArrayItem_Free(3);
    if (pkSrc->m_pkIDTags)
        ((Ctl43c*)pkSrc->m_pkIDTags)->NiControllerSequence_IDTag_Free(3);
    NiControllerSequence_CopyMembers(pkSrc, iArg);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

class GlobalObjectO2_00a7b610
{
};
extern GlobalObjectO2_00a7b610 g_011f36dc;

inline void NiNode::IncRefCount() throw()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiNode::DecRefCount() throw()
{
    if (!InterlockedDecrement((long*)&m_uiRefCount))
        DeleteThis();
}
template <class T> NiPointer<T>::NiPointer() { m_pObject = 0; }
template <class T> NiPointer<T>::NiPointer(T* pkNew) throw()
{
    m_pObject = pkNew;
    if (m_pObject != 0) m_pObject->IncRefCount();
}
template <class T> NiPointer<T>::~NiPointer() throw()
{
    if (m_pObject != 0) m_pObject->DecRefCount();
}
template <class T> NiPointer<T>& NiPointer<T>::operator=(T* pkNew) throw()
{
    if (m_pObject != pkNew)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = pkNew;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}
template <class T> NiPointer<T>& NiPointer<T>::operator=(const NiPointer& kSrc)
{
    if (m_pObject != kSrc.m_pObject)
    {
        if (m_pObject != 0) m_pObject->DecRefCount();
        m_pObject = kSrc.m_pObject;
        if (m_pObject != 0) m_pObject->IncRefCount();
    }
    return *this;
}

typedef NiPointer<NiNode> NiPtrNode;
typedef NiPointer<NiObject> LegacyPtr;

static inline unsigned int SequenceStreamObjectCount(NiStream& stream)
{
    return *(unsigned int*)((char*)&stream + 0x228);
}
static inline NiObject** SequenceStreamObjects(NiStream& stream)
{
    return *(NiObject***)((char*)&stream + 0x220);
}

struct S00a35700_NodeRef
{
    NiNode* p;
    S00a35700_NodeRef& operator=(NiNode* object);
};

extern "C" void __cdecl GetGPUProgram(NiStream*, unsigned int, LegacyPtr*, unsigned int) throw();
extern "C" void __cdecl ConvertOldSequence(NiObject*, S00a35700_NodeRef*) throw();

// Retrieves a NiNode by index from a NiStream, using version-specific lookup, and assigns it to the output pointer with a reference count adjustment.
// @fnv 0x00a35700
// src: XBOX_PDB 0x00a35700
void __cdecl NiControllerSequence_CreateSequenceFromFile(void* streamObject, unsigned int index, NiPtrNode& out)
{
    NiStream* stream = static_cast<NiStream*>(streamObject);
    if (index >= SequenceStreamObjectCount(*stream))
    {
        out = 0;
        return;
    }
    NiNode* const null = 0;
    S00a35700_NodeRef a;
    a.p = null;
    if (SequenceStreamVersion(*stream) < 0x5000000)
    {
        LegacyPtr b = (NiObject*)0;
        GetGPUProgram(stream, index, &b, 0);
        ConvertOldSequence(b.m_pObject, &a);
    }
    else
    {
        NiObject* value = SequenceStreamObjects(*stream)[index];
        a = value == 0 ? null : (NiNode*)value->DynamicCast((const void*)&g_011f36dc);
    }
    NiNode* p = a.p;
    out = p;
    if (p)
        p->DecRefCount();
}

struct ActiveArray
{
    void** items;
    unsigned int capacity;
    unsigned int size;
    void NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(unsigned int);
    unsigned int Find(void* const& key) const
    {
        for (unsigned int i = 0; i < size; ++i)
            if (items[i] == key)
                return i;
        return (unsigned int)-1;
    }
    unsigned int FindOrAdd(void* const& key);
};
// Returns the index of key in items, or appends it (growing the array if full) and returns the new index.
// @fnv 0x00e7ec00
unsigned int ActiveArray::FindOrAdd(void* const& key)
{
    unsigned int i = Find(key);
    if (i != (unsigned int)-1)
        return i;
    if (size == capacity)
        NiTSet_NiScreenGeometryData_ScreenElement_NiTMallocInterface_NiScreenGeometryData_ScreenElement_Add(capacity > 0 ? capacity * 2 : 1);
    unsigned int index = size;
    items[index] = key;
    ++size;
    return index;
}

#include <windows.h>
namespace fnv_00a30640 {

extern char* EmptyFS;


// For each non-null handle, assigns AddString(0)'s result and decrements the old handle's count when it differs from a global handle.
} // namespace fnv_00a30640

// @fnv 0x00a30640
void NiControllerSequence__IDTag::ResetStrings()
{
    char* old = m_kAVObjectName;
    if (old != 0)
    {
        m_kAVObjectName = NiGlobalStringTable::AddString(0);
        if (old != fnv_00a30640::EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kPropertyType;
    if (old != 0)
    {
        m_kPropertyType = NiGlobalStringTable::AddString(0);
        if (old != fnv_00a30640::EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kCtlrType;
    if (old != 0)
    {
        m_kCtlrType = NiGlobalStringTable::AddString(0);
        if (old != fnv_00a30640::EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kCtlrID;
    if (old != 0)
    {
        m_kCtlrID = NiGlobalStringTable::AddString(0);
        if (old != fnv_00a30640::EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }

    old = m_kInterpolatorID;
    if (old != 0)
    {
        m_kInterpolatorID = NiGlobalStringTable::AddString(0);
        if (old != fnv_00a30640::EmptyFS)
            InterlockedDecrement((LONG*)(old - 8));
    }
}


int __cdecl NiStrnicmp(const char*, const char*, const char*);
extern const char* g_kTextKeyA;
extern const char* g_kTextKeyB;

inline TimedTextEntry* NiTextKeyExtraData::GetKeys(unsigned int& uiNumKeys) const
{
    uiNumKeys = m_uiNumKeys;
    return m_pKeys;
}


// Returns true when both sequences have eligible text keys and each eligible key occurs in the other sequence.
// @fnv 0x00a30ab0
bool NiControllerSequence::MatchesTextKeys(NiControllerSequence* pkOther)
{
    NiTextKeyExtraData* pkKeys = m_spTextKeyData.m_pObject;
    NiTextKeyExtraData* pkOtherKeys;
    if (!pkKeys || !(pkOtherKeys = pkOther->m_spTextKeyData.m_pObject))
        return false;

    unsigned int uiNumOther = pkOtherKeys->m_uiNumKeys;
    TimedTextEntry* pOther = pkOtherKeys->m_pKeys;
    unsigned int uiNumKeys = pkKeys->m_uiNumKeys;
    TimedTextEntry* pKeys = pkKeys->m_pKeys;

    bool bFound = false;
    unsigned int i;
    for (i = 0; i < uiNumOther; i++)
    {
        const char* pcText = pOther[i].m_kText;
        if (!NiStrnicmp(pcText, g_kTextKeyA, g_kTextKeyB))
        {
            bFound = true;
            bool bMatch = false;
            for (unsigned int j = 0; j < uiNumKeys; j++)
            {
                if (strcmp(pcText, pKeys[j].m_kText) == 0)
                {
                    bMatch = true;
                    break;
                }
            }
            if (!bMatch)
                goto fail;
        }
    }
    if (!bFound)
        goto fail;
    bFound = false;
    for (i = 0; i < uiNumKeys; i++)
    {
        const char* pcText = pKeys[i].m_kText;
        if (!NiStrnicmp(pcText, g_kTextKeyA, g_kTextKeyB))
        {
            bFound = true;
            bool bMatch = false;
            for (unsigned int j = 0; j < uiNumOther; j++)
            {
                if (strcmp(pcText, pOther[j].m_kText) == 0)
                {
                    bMatch = true;
                    break;
                }
            }
            if (!bMatch)
                goto fail;
        }
    }
    if (!bFound)
        goto fail;
    return true;
fail:
    return false;
}

struct StaticKeyB5652
{
    StaticKeyB5652(int v) throw()
    {
        m_00 = v;
    }
    ~StaticKeyB5652() throw()
    {}
    unsigned int m_00;
};

extern unsigned int g_sequenceEntryKeyInit;
extern StaticKeyB5652 g_sequenceEntryKey;
void __cdecl DestroySequenceEntryKey();

class FUN_00a32940_cls
{
  public:
    unsigned int unk00;
    NiRefObject** m_04;
    unsigned short unk08;
    unsigned short m_0a;
    unsigned short m_0c;
    void SetEntry(unsigned int idx, NiRefObject** a2);
};

// Stores a NiRefObject pointer at index idx in m_04, updating m_0a, m_0c and reference counts as needed.
// @fnv 0x00a32940
void FUN_00a32940_cls::SetEntry(unsigned int uiIndex, NiRefObject** apNewStub)
{
    if (!(g_sequenceEntryKeyInit & 1))
    {
        g_sequenceEntryKeyInit |= 1;
        g_sequenceEntryKey.m_00 = 0;
        atexit(DestroySequenceEntryKey);
    }
    if (uiIndex >= m_0a)
    {
        m_0a = (unsigned short)(uiIndex + 1);
        if ((unsigned int)*apNewStub == g_sequenceEntryKey.m_00)
        {
        }
        else
        {
            m_0c++;
        }
    }
    else
    {
        if ((unsigned int)*apNewStub != g_sequenceEntryKey.m_00)
        {
            if ((unsigned int)m_04[uiIndex] == g_sequenceEntryKey.m_00)
            {
                m_0c++;
            }
        }
        else
        {
            if ((unsigned int)m_04[uiIndex] != g_sequenceEntryKey.m_00)
            {
                m_0c--;
            }
        }
    }
    NiRefObject** slot = &m_04[uiIndex];
    NiRefObject* old = *slot;
    if (old != *apNewStub)
    {
        if (old != 0)
        {
            if (InterlockedDecrement((long*)&old->m_uiRefCount) == 0)
            {
                old->DeleteThis();
            }
        }
        NiRefObject* pNewStub = *apNewStub;
        *slot = pNewStub;
        if (pNewStub != 0)
        {
            InterlockedIncrement((long*)&pNewStub->m_uiRefCount);
        }
    }
}

struct BindObj;
struct BindCtrl;
struct Blend;
// Exe 0x00a32c70: read-only Gamebryo property pointer access.
typedef NiPointer<BindObj> ObjPtr;
template <> inline NiPointer<BindObj>::operator BindObj*() const { return m_pObject; }
template <> inline BindObj* NiPointer<BindObj>::operator->() const { return m_pObject; }

struct PropLink
{
    PropLink* next;
    int unk04;
    ObjPtr object;
};
inline ObjPtr& NextProperty(PropLink*& pos)
{
    ObjPtr& value = pos->object;
    pos = pos->next;
    return value;
}
struct BindObj
{
    virtual void V0();
    virtual void V1();
    virtual const char** GetType();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual BindObj* Find(const char** name);
    virtual void V36();
    virtual void V37();
    virtual void SetTarget(BindObj* obj);
    virtual void V39();
    virtual void Update(bool*, int, bool*);
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual unsigned short FindIndex(const char*);
    virtual void V48();
    virtual Blend* GetBlend(unsigned short);
    virtual void SetBlend(Blend*, unsigned short);
    virtual bool Supports(BindObj*);
    virtual const char* GetID();
    virtual void V53();
    virtual void V54();
    virtual Blend* MakeBlend(unsigned short, bool, bool, float, int);
    void NiObjectNET_RemoveController(BindCtrl*);
    int refs;
    unsigned short flags;
    unsigned short unk0a;
    BindCtrl* controllers;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    PropLink* properties;
    int unk28;
    int unk2c;
    BindCtrl* next;
};
struct BindCtrl : BindObj
{
    void FUN_00a67260(BindCtrl*);
};
struct Blend
{
    Blend* FUN_00653290(const void*);
};
extern const int DAT_011f36fc;
extern int DAT_0109b220;

struct BindOwner
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
    BindObj* target;
    BindCtrl* program;
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
    bool managerFlag;
    int unk6c;
    int unk70;
    int unk74;
    BindObj* root;
};
struct CtrlPtr
{
    BindCtrl* ptr;
    void FUN_0066b0d0(BindCtrl*);
};
struct BindItem
{
    BindObj* interpolator;
    CtrlPtr controller;
    Blend* blend;
    unsigned int settings;
};
struct BindTag
{
    const char* object;
    const char* property;
    const char* type;
    const char* id;
    const char* interpolator;
};

// Resolves interpolators, objects, and controllers for each BindItem, creating blends and updating the owner's target.
// @fnv 0x00a32c70
// src: XBOX_PDB 0x00a32c70
bool NiControllerSequence::StoreTargets(bool abUpdate)
{
    BindObj* root = ((BindOwner*)m_pkOwnerManager)->root;
    if (m_kAccumulationRootName.m_kHandle != (const char*)DAT_0109b220)
        (*(BindObj**)&m_pkAccumulationRoot) = root->Find((const char**)&m_kAccumulationRootName.m_kHandle);
    abUpdate = Attach(abUpdate, (NiAVObject*)root, false);
    for (unsigned int index = 0; index < m_uiNumControlledBlocks; ++index)
    {
        BindObj* interpolator = ((BindItem*)m_pInterpArray)[index].interpolator;
        if (!interpolator)
            continue;
        BindTag& tag = ((BindTag*)m_pkIDTags)[index];
        if (!interpolator->Supports(root) || ((BindItem*)m_pInterpArray)[index].blend)
            continue;
        BindObj* object = root->Find(&tag.object);
        if (object && tag.property)
        {
            PropLink* link = object->properties;
            while (link)
            {
                BindObj* property = NextProperty(link);
                const char* propertyType = tag.property;
                if (!strcmp(*property->GetType(), propertyType))
                {
                    object = property;
                    break;
                }
            }
        }
        if (!object)
        {
            if (*(const unsigned short*)tag.object == 0x2323)
                m_bHasAnimNotes = true;
            continue;
        }
        BindCtrl* controller = object->controllers;
        while (controller)
        {
            const char* controllerType = tag.type;
            if (!strcmp(*controller->GetType(), controllerType))
            {
                const char* id = controller->GetID();
                if ((!id && !tag.id) || (id && tag.id && !strcmp(id, tag.id)))
                    break;
            }
            controller = controller->next;
        }
        if (!controller)
        {
            controller = ((BindItem*)m_pInterpArray)[index].controller.ptr;
            if (!controller)
                continue;
            controller->SetTarget(object);
            abUpdate = true;
            if (object == ((BindOwner*)m_pkOwnerManager)->target)
            {
                object->NiObjectNET_RemoveController(controller);
                controller->FUN_00a67260(((BindOwner*)m_pkOwnerManager)->program);
                ((BindCtrl*)((BindOwner*)m_pkOwnerManager))->FUN_00a67260(controller);
            }
        }
        const char* interpolatorName = tag.interpolator;
        unsigned short interpIndex = controller->FindIndex(interpolatorName);
        if (interpIndex == DAT_01096320)
            continue;
        {
            Blend* blend = controller->GetBlend(interpIndex);
            if (!blend)
                blend = 0;
            else
                blend = blend->FUN_00653290(&DAT_011f36fc);
            bool special = false;
            if ((*(BindObj**)&m_pkAccumulationRoot) == object && ((BindOwner*)m_pkOwnerManager)->managerFlag)
                special = true;
            if (!blend)
            {
                blend = controller->MakeBlend(interpIndex, true, special, 0.0f, 2);
                controller->SetBlend(blend, interpIndex);
                if (!blend)
                    continue;
            }
            controller->flags |= 0x20;
            ((BindItem*)m_pInterpArray)[index].controller.FUN_0066b0d0(controller);
            ((BindItem*)m_pInterpArray)[index].blend = blend;
        }
    }
    if (abUpdate)
    {
        bool result;
        ((BindOwner*)m_pkOwnerManager)->target->Update(&result, 1, &abUpdate);
    }
    return true;
}

extern int DAT_011f49e0;
extern char DAT_01096614;

struct Controller33130
{
    virtual void V00();
    virtual void V01();
    virtual const char** V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual unsigned short V45();
    virtual const char* V46(unsigned int);
    virtual void V47();
    virtual void V48();
    virtual NiRefObject* V49(unsigned int);
    virtual void V50();
    virtual void V51();
    virtual const char* V52();
    int refs;
};
static void Release33130(char* h)
{
    if (h != (char*)DAT_0109b220)
        InterlockedDecrement((long*)(h - 8));
}
static void Assign33130(NiFixedString& dst, const char* value)
{
    char* h = !value ? (char*)DAT_0109b220 : NiGlobalStringTable::AddString(value);
    if (dst.m_kHandle != h)
    {
        char* old = dst.m_kHandle;
        if (h != (char*)DAT_0109b220)
            InterlockedIncrement((long*)(h - 8));
        Release33130(old);
        dst.m_kHandle = h;
    }
    Release33130(h);
}
// Parses objectName into property and controller IDs, then for each controller slot assigns an interpolator and stores a reference to the controller.
// @fnv 0x00a33130
bool NiControllerSequence::AssignControllers(void* apObjectName, NiInterpController* apController)
{
    char objectName[260];
    char propertyName[260];
    char controllerID[260];
    FUN_00ec65a6(objectName, 260, (const char*)apObjectName);
    propertyName[0] = 0;
    controllerID[0] = 0;
    char* split = strchr(objectName, '\n');
    if (split)
    {
        FUN_00ec65a6(propertyName, 260, split + 1);
        *split = 0;
        split = strchr(propertyName, '\n');
        FUN_00ec65a6(controllerID, 260, split + 1);
        *split = 0;
    }
    Controller33130* controller = (Controller33130*)apController;
    for (unsigned int i = 0; (unsigned short)i < controller->V45(); ++i)
    {
        const NiFixedString& empty = *(const NiFixedString*)&DAT_011f49e0;
        // The original explicitly manages this temporary's lifetime without unwind cleanup.
        void* tagStorage[sizeof(FUN_00a312d0) / sizeof(void*)];
        ::new (tagStorage) FUN_00a312d0(empty, empty, empty, empty, empty);
        FUN_00a312d0& tag = *reinterpret_cast<FUN_00a312d0*>(tagStorage);
        Assign33130(tag.m_kAVObjectName, objectName);
        if (strcmp(propertyName, "PROP") == 0)
            Assign33130(tag.m_kPropertyType, controllerID);
        Assign33130(tag.m_kCtlrType, *controller->V02());
        Assign33130(tag.m_kCtlrID, controller->V52());
        Assign33130(tag.m_kInterpolatorID, controller->V46(i));
        NiRefObject* interpolator = controller->V49(i);
        int index = ((NiControllerSequence*)this)->AssignSlot(interpolator, (unsigned int)&tag, 255);
        if (index == -1)
        {
            tag.~FUN_00a312d0();
            return false;
        }
        NiRefObject*& slot = *(NiRefObject**)&((NiControllerSequence*)this)->m_pInterpArray[index].m_pkController;
        if (slot != (NiRefObject*)controller)
        {
            NiRefObject* old = slot;
            if (old && !InterlockedDecrement((long*)&old->m_uiRefCount))
                old->DeleteThis();
            slot = (NiRefObject*)controller;
            InterlockedIncrement((long*)&slot->m_uiRefCount);
        }
        tag.~FUN_00a312d0();
    }
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

extern "C" void* __cdecl Object_DispatchCommandFour(unsigned int);


namespace a3 {
extern NiFixedString DAT_011f49e0;
}

template <class T> struct SeqPtr
{

    T* m_pObject;

    SeqPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject != 0)
            m_pObject->IncRefCount();
    }

    ~SeqPtr()
    {
        if (m_pObject != 0)
            m_pObject->DecRefCount();
    }

    SeqPtr& operator=(T* p)

    {

        if (m_pObject != p)
        {

            if (m_pObject != 0)
                m_pObject->DecRefCount();

            m_pObject = p;

            if (m_pObject != 0)
                m_pObject->IncRefCount();
        }

        return *this;
    }

    SeqPtr& operator=(const SeqPtr& p)
    {
        return operator=(p.m_pObject);
    }

    T* operator->() const
    {
        return m_pObject;
    }

    operator T*() const
    {
        return m_pObject;
    }
};

struct SeqController
{

    void* vtbl;

    int unk04;

    unsigned short m_uiObjectFlags;

    unsigned short unk0A;

    float m_fFrequency;

    float m_fPhase;

    float m_fLoKeyTime;

    float m_fHiKeyTime;
};

inline NiRefObject::NiRefObject() {}
inline void NiRefObject::IncRefCount()
{
    InterlockedIncrement((long*)&m_uiRefCount);
}
inline void NiRefObject::DecRefCount()
{
    if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
        DeleteThis();
}
inline void NiRefObject::DecRef()
{
    if (!InterlockedDecrement((long*)&m_uiRefCount))
        DeleteThis();
}

struct OldSequence
{

    void* vtbl;

    int unk04;

    const char* m_pcName;

    int unk0C;

    void** m_ppObjects;

    unsigned short unk14;

    unsigned short m_usElementCount;

    int unk18;

    int unk1C;

    SeqController** m_ppControllers;

    int unk24;

    int unk28;

    SeqPtr<NiTextKeyExtraData> m_spTextKeyData;
};


// Allocates a NiControllerSequence, copies name and controller data from pkOld, and assigns the result to spOut.
// @fnv 0x00a349e0
void __cdecl ConvertOldSequence(OldSequence* pkOld, SeqPtr<NiControllerSequence>& spOut) throw()

{

    void* pvRaw = Object_DispatchCommandFour(0x74);

    unsigned int ItemUpdateArray = pvRaw != 0 ? pkOld->m_usElementCount : 0;

    SeqPtr<NiControllerSequence> spSeq = ::new (pvRaw) NiControllerSequence(NiFixedString(pkOld->m_pcName), ItemUpdateArray, ItemUpdateArray);

    bool bFirst = true;

    for (unsigned int i = 0; i < pkOld->m_usElementCount; i++)
    {

        void* pkObject = pkOld->m_ppObjects[i];

        SeqController* pkCtlr = pkOld->m_ppControllers[i];

        if (pkObject && pkCtlr)
        {

            if (bFirst)
            {

                int eType = (pkCtlr->m_uiObjectFlags >> 1) & 3;

                if (eType != 2 && eType != 0)

                    eType = 0;

                spSeq->m_eAnimationCycleType = (NiTimeController__CycleType)eType;

                spSeq->m_fFrequency = pkCtlr->m_fFrequency;

                bFirst = false;

                spSeq->m_fFirstKeyTime = pkCtlr->m_fLoKeyTime;

                spSeq->m_fLastKeyTime = pkCtlr->m_fHiKeyTime;
            }

            spSeq->AddFromOld(pkObject, pkCtlr);
        }
    }

    spSeq->m_spTextKeyData = pkOld->m_spTextKeyData.m_pObject;

    spSeq->m_kAccumulationRootName = a3::DAT_011f49e0;

    spOut = spSeq;
}

extern "C" void _ReadWriteBarrier(void);
struct S00a32fa0_Ctl
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual unsigned short GetTargetIndex(const FUN_00a312d0& tag);
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual NiRefObject* GetInterpolator(unsigned short index);
};

struct S00a32fa0_SP
{
    NiRefObject* m_p;
    S00a32fa0_SP& operator=(const S00a32fa0_SP& o)
    {
        if (m_p != o.m_p)
        {
            NiRefObject* old = m_p;
            if (old && InterlockedDecrement((long*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
            m_p = o.m_p;
            if (m_p)
                InterlockedIncrement((long*)&m_p->m_uiRefCount);
        }
        return *this;
    }
    S00a32fa0_SP& operator=(NiRefObject* p)
    {
        if (m_p != p)
        {
            if (m_p)
                m_p->DecRef();
            m_p = p;
            if (m_p)
                InterlockedIncrement((long*)&m_p->m_uiRefCount);
        }
        return *this;
    }
    void Drop()
    {
        NiRefObject* old = m_p;
        _ReadWriteBarrier();
        if (old && InterlockedDecrement((long*)&old->m_uiRefCount) == 0)
            old->DeleteThis();
    }
};
struct S00a32fa0_Item
{
    NiRefObject* interpolator;
    S00a32fa0_SP controller;
    void* blend;
    unsigned char blendIndex;
    unsigned char priority;
    unsigned char pad0e;
    unsigned char pad0f;
};
struct S00a32fa0_Tag
{
    char* m_kPointA[5];
};


extern int DAT_011f49e0;
extern unsigned short DAT_01096320;

// Copies cycleType, frequency, beginTime, endTime and interpolator slots from this sequence into destination, optionally clearing destination slots first.
// @fnv 0x00a32fa0
// src: COMMUNITY 0x00a32fa0
void NiControllerSequence::PopulatePoseSequence(NiControllerSequence* destination, int, int, bool remove)
{
    if (remove)
    {
        for (unsigned int i = 0; i < destination->m_uiNumControlledBlocks; ++i)
        {
            S00a32fa0_SP object = {0};
            ((NiControllerSequence*)destination)->AssignInterpolatorRef(i, &object.m_p);
            object.Drop();
            _ReadWriteBarrier();
        }
    }
    if (m_eAnimationCycleType == 2 || m_eAnimationCycleType == 0)
        destination->m_eAnimationCycleType = m_eAnimationCycleType;
    destination->m_fFrequency = m_fFrequency;
    destination->m_fFirstKeyTime = m_fFirstKeyTime;
    destination->m_fLastKeyTime = m_fLastKeyTime;
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
    {
        S00a32fa0_Item& item = ((S00a32fa0_Item*)m_pInterpArray)[i];
        S00a32fa0_Ctl* controller = (S00a32fa0_Ctl*)item.controller.m_p;
        if (item.interpolator && controller)
        {
            const FUN_00a312d0* info = (FUN_00a312d0*)&m_pkIDTags[i];
            unsigned short index = controller->GetTargetIndex(*info);
            if (index != DAT_01096320)
            {
                NiRefObject* interpolator = controller->GetInterpolator(index);
                S00a32fa0_Tag tag;
                unsigned int newIndex = destination->AssignSlot(
                    interpolator,
                    (unsigned int)new (&tag)
                        FUN_00a312d0((NiFixedString&)DAT_011f49e0, (NiFixedString&)DAT_011f49e0, (NiFixedString&)DAT_011f49e0,
                                     (NiFixedString&)DAT_011f49e0, (NiFixedString&)DAT_011f49e0),
                    0xff);
                ((FUN_00a30750_shell*)&tag)->NiControllerSequence_IDTag_Destroy();
                S00a32fa0_Item& newItem = ((S00a32fa0_Item*)destination->m_pInterpArray)[newIndex];
                newItem.blend = item.blend;
                newItem.controller = item.controller;
                newItem.priority = item.priority;
            }
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class S00a31880_FUN_00a31880_cls
{
  public:
    NiRefObject* m_00;
    NiRefObject* m_04;
    unsigned int m_08;
    unsigned char m_0c;
    unsigned char m_0d;

    S00a31880_FUN_00a31880_cls* CopyRetainedFields(S00a31880_FUN_00a31880_cls* src);
};

// Copies reference-counted pointers and plain fields from src, managing ref counts for the two NiRefObject pointers.
// @fnv 0x00a31880
// src: GUESS 0x00a31880 (confidence: medium)
S00a31880_FUN_00a31880_cls* S00a31880_FUN_00a31880_cls::CopyRetainedFields(S00a31880_FUN_00a31880_cls* src)
{
    NiRefObject* pOldRef0 = m_00;
    if (pOldRef0 != src->m_00)
    {
        if (pOldRef0 != 0)
        {
            ReleaseSequenceRef(pOldRef0);
        }
        m_00 = src->m_00;
        if (m_00 != 0)
        {
            RetainSequenceRef(m_00);
        }
    }
    NiRefObject* pOldRef1 = m_04;
    if (pOldRef1 != src->m_04)
    {
        if (pOldRef1 != 0)
        {
            ReleaseSequenceRef(pOldRef1);
        }
        m_04 = src->m_04;
        if (m_04 != 0)
        {
            RetainSequenceRef(m_04);
        }
    }
    m_08 = src->m_08;
    m_0c = src->m_0c;
    m_0d = src->m_0d;
    return this;
}
