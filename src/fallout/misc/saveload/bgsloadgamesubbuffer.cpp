// fallout/misc/saveload/bgsloadgamesubbuffer.cpp: BGSLoadGameSubBuffer, LoadGameSubBufferQueue, SubBufferMap, Holder and more (20 functions)

#include "../../../../include/ActorPackageContext.h"
#include "../../../../include/BGSLoadFormBuffer.h"
#include "../../../../include/BGSLoadGameBuffer.h"
#include "../../../../include/BGSLoadGameSubBuffer.h"
#include "../../../../include/BGSReconstructFormsInAllFilesMap.h"
#include "../../../../include/ExtraDataList.h"
#include "../../../../include/MiddleHighProcess.h"
#include "../../../../include/MobileObject.h"
#include "../../../../include/PlayerCharacter.h"
#include "../../../../include/TESObjectREFR.h"
#include "../../../../include/TESRecipe.h"
#include "../../../../include/BGSSaveGameBuffer.h"
#include "../../../../include/BGSSaveFormBuffer.h"
#include "../../../../include/DummyPointerMap.h"
#include "../../../../include/NiTPointerMap.h"
#include "../../../../include/LockFreeMap.h"
#include "../../../../include/NiPointer.h"

#include "bgsloadgamesubbuffer_types_QUEUED_SUB_BUFFER_TYPE.h"
#include "bgsloadgamesubbuffer_types_BGSSaveLoadQueuedSubBufferMap.h"
#include "bgsloadgamesubbuffer_decls.h"

extern unsigned int __cdecl GetEncodedIntegerSize(unsigned int value);
extern void __cdecl WriteEncodedInteger(char* destination, unsigned int value);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

struct FUN_008659c0_Buffer;

// The shared reference layout is used throughout. These non-virtual save/load
// entry points are not declared by TESObjectREFR.h yet; this adapter adds no data.
class ReferenceSubBufferAccess : public TESObjectREFR
{
public:
    void LoadHavokData(BGSLoadFormBuffer* buffer);
    void SaveAnimation(void* buffer);
    void SaveHavokData(FUN_008659c0_Buffer* buffer);
};

typedef LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafeHashTableNode QueuedHashListNode;
typedef LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafePointer<QueuedHashListNode> QueuedMarkedPointer;

// @fnv 0x008655a0
void BGSLoadGameSubBuffer::LoadGame(BGSLoadGameBuffer* buffer)
{
    char* byteDestination;
    {
        unsigned int size;
        {
            unsigned int value = reinterpret_cast<BGSLoadFormBuffer*>(buffer)->ReadElementCount();
            if (value == 0)
                return;
            {
                unsigned int total;
                {
                    char* cursor;
                    size = GetEncodedIntegerSize(value);
                    total = value + size + 1;
                    cursor = new char[total];
                    reinterpret_cast<QuantityData*>(this)->SetQuantity((unsigned int)cursor);
                    byteDestination = cursor;
                    *byteDestination = buffer->GetVersion();
                    cursor++;
                    WriteEncodedInteger(cursor, value);
                    cursor += size;
                    memcpy(cursor, buffer->GetCombinedValue(), value);
                    reinterpret_cast<ActorPackageContext*>(buffer)->AddToProcedureIndex(value);
                }
            }
        }
    }
}

// Loads a queued sub-buffer, resolves the form key, and stores the loaded reference in the map for the given type.
// @fnv 0x008652f0
void LoadGameSubBufferQueue::ProcessSubBuffer(QUEUED_SUB_BUFFER_TYPE type, BGSLoadFormBuffer* buffer, TESForm* form)
{
    TESForm* key;
    {
        QueuedMarkedPointer subBuffer;
        reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->LoadGame(reinterpret_cast<BGSLoadGameBuffer*>(buffer));
        if (!(TESForm*)reinterpret_cast<NiPointer<TESForm>&>(subBuffer))
            return;
        key = form ? form : buffer->GetForm();
        reinterpret_cast<NiTPointerMap<unsigned int, TESObjectREFR*>*>(&m_kSubBuffersByType[type])
            ->SetAt((unsigned int)key, reinterpret_cast<TESObjectREFR*>(const_cast<QueuedHashListNode*>(subBuffer.pPointer)));
    }
}

// @fnv 0x00864e20
BGSLoadFormBuffer* BGSLoadGameSubBuffer::CreateFormBuffer(TESForm* form)
{
    BGSLoadFormBuffer* result = new BGSLoadFormBuffer;
    {
        unsigned int offset;
        {
            char* data = pBuffer;
            reinterpret_cast<TESRecipe*>(result)->SetSkill((int)form);
            result->ExtraDismemberedLimbs_SetEaten((unsigned char)*data);
            offset = 1;
            {
                unsigned int value;
                {
                    char* encoded = pBuffer + 1;
                    value = 0;
                    offset += ReadEncodedInteger(encoded, value);
                    result->SetBuffer(pBuffer, value + offset, offset);
                    pBuffer = 0;
                    return result;
                }
            }
        }
    }
}

// Resolves the form's load buffer and loads its queued animation for actors, or logs an error for non-references and actors without animation.
// @fnv 0x00864b00
void BGSLoadGameSubBuffer::RestoreAnimation(TESForm* form)
{
    BGSLoadFormBuffer* loadBuffer;
    {
        bool firstPerson = false;
        if (form == reinterpret_cast<TESForm*>(g_thePlayer->GetObjectReference()))
        {
            firstPerson = true;
            form = g_thePlayer;
        }
        loadBuffer = CreateFormBuffer(form);
        if (form->GetIsReference())
        {
            TESForm* reference = form;
            if (reference->IsActor())
            {
                Animation* animation = 0;
                if (reference == g_thePlayer)
                    animation = g_thePlayer->GetAnimation(firstPerson);
                else
                {
                    animation = reinterpret_cast<Animation*>(static_cast<TESObjectREFR*>(reference)->GetAnimData());
                }
                if (animation)
                    animation->Load(loadBuffer);
                else
                    LogWarning("ANIMATION: Actor '%s' %08X with queued animation does not have one to load",
                               form->GetName(), form->GetFormID());
            }
            else
                reinterpret_cast<TESObjectREFR*>(reference)->RestoreAnimation(loadBuffer);
        }
        else
            LogWarning("SAVELOAD: Form '%s' %08X with queued havok data is not a reference", form->GetName(),
                       form->GetFormID());
        delete reinterpret_cast<BGSLoadGameBuffer*>(loadBuffer);
    }
}

// Iterates the queued sub-buffer for the given type, loading or deferring each form, then clears the map.
// @fnv 0x00865390
void LoadGameSubBufferQueue::ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE eSubBufferType)
{
    void* pIterPos =
        reinterpret_cast<BGSReconstructFormsInAllFilesMap*>(&m_kSubBuffersByType[eSubBufferType])->GetFirstPos();
    while (pIterPos)
    {
        TESForm* form = 0;
        QueuedMarkedPointer subBuffer;
        {
            reinterpret_cast<QueuedMap*>(&m_kSubBuffersByType[eSubBufferType])->GetNextEntry(pIterPos, form, subBuffer);
            {
                unsigned char load = true;
                {
                    TESObjectREFR* actor;
                    {
                        TESObjectREFR* reference = 0;
                        actor = 0;
                        if (form->GetIsReference())
                        {
                            reference = reinterpret_cast<TESObjectREFR*>(form);
                            load = reinterpret_cast<unsigned int>(reference->Get3DSimple()) != 0;
                            if (reference->IsActor())
                                actor = reference;
                        }
                        if (load)
                        {
                            switch (eSubBufferType)
                            {
                            case 0:
                                reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->RestoreAnimation(form);
                                break;
                            case 1:
                                reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->ReadAnimationState(form);
                                break;
                            case 2:
                                reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->LoadHavokData(form);
                                break;
                            }
                        }
                        else
                        {
                            switch (eSubBufferType)
                            {
                            case 0:
                                if (actor)
                                    reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->DeleteBuffer();
                                else if (reference)
                                    reference->GetExtraData()->SetSavedAnimation(
                                        reinterpret_cast<char*>((TESForm*)reinterpret_cast<NiPointer<TESForm>&>(subBuffer)));
                                break;
                            case 1:
                                reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->DeleteBuffer();
                                break;
                            case 2:
                                if (reference)
                                    reference->GetExtraData()->SetSavedHavokData(
                                        reinterpret_cast<char*>((TESForm*)reinterpret_cast<NiPointer<TESForm>&>(subBuffer)));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(&m_kSubBuffersByType[eSubBufferType])->RemoveAll();
}

// @fnv 0x00864c50
void BGSLoadGameSubBuffer::ReadAnimationState(TESForm* form)
{
    BGSLoadFormBuffer* loadBuffer = CreateFormBuffer(form);
    if (form->GetIsReference())
    {
        TESForm* reference = form;
        if (reference->IsMobileObject())
        {
            MobileObject* mobile = reinterpret_cast<MobileObject*>(form);
            if (mobile->GetPhysicsCharacterController())
            {
                MiddleHighProcess* process = reinterpret_cast<MiddleHighProcess*>(
                    mobile->FUN_008d8520());
                TargetDoorController* saved = reinterpret_cast<TargetDoorController*>(process);
                reinterpret_cast<MiddleHighProcess*>(saved)->ReadAnimationState(loadBuffer);
            }
            else
                LogWarning("SAVELOAD: Mobile Object '%s' %08X with queued char controller does not have one to load",
                           form->GetName(), form->GetFormID());
        }
        else
            LogWarning("SAVELOAD: Reference '%s' %08X with queued char controller is not a mobile object",
                       form->GetName(), form->GetFormID());
    }
    else
        LogWarning("SAVELOAD: Form '%s' %08X with queued char controller is not a reference", form->GetName(),
                   form->GetFormID());
    delete reinterpret_cast<BGSLoadGameBuffer*>(loadBuffer);
}

// @fnv 0x00865360
void LoadGameSubBufferQueue::QueueAnimationAndCharController()
{
    ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE_QUEUED_SUB_BUFFER_ANIMATION);
    ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE_QUEUED_SUB_BUFFER_CHAR_CONTROLLER);
    ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE_QUEUED_SUB_BUFFER_HAVOK_DATA);
}

// Empty constructor for the class; performs no initialization.
// @fnv 0x008651d0
LoadGameSubBufferQueue::LoadGameSubBufferQueue()
{}

// @fnv 0x00865200
void NiTMap_TESForm___BGSLoadGameSubBuffer_Constructor(void)
{
    // this is in ecx (thiscall calling convention for MSVC)
    // The thunk constructs the NiTMap by calling the constructor with size 0x25 (37)
}

// 0x00865200 is the compiler-generated member constructor thunk for m_kSubBuffersByType
// (??_FNiTMap_TESForm___BGSLoadGameSubBuffer_@@QAEXXZ): the compiler builds the three
// queued-sub-buffer maps through it inside eh_vector_constructor_iterator, so it carries
// no @fnv annotation of its own.

struct SubBufferValue
{
    void* data;
};
struct SubBufferMapItem
{
    SubBufferMapItem* m_pkNext;
    TESForm* m_key;
    SubBufferValue m_val;
};
struct SubBufferMap
{
    virtual unsigned int Reserved();
    virtual unsigned int KeyToHashIndex(TESForm* key) const;
    unsigned int m_uiHashSize;
    SubBufferMapItem** m_ppkHashTable;
    void GetNextEntry(void*& pos, TESForm*& key, SubBufferValue& val) const;
};

// Reads the key and value from the item at pos, then advances pos to the next item in the chain or the next non-empty hash bucket, or null.
// @fnv 0x00865730
void SubBufferMap::GetNextEntry(void*& apPosition, TESForm*& key, SubBufferValue& aValue) const
{
    unsigned int i;
    SubBufferMapItem* pkItem = (SubBufferMapItem*)apPosition;
    key = pkItem->m_key;
    aValue = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        apPosition = pkItem->m_pkNext;
    }
    else
    {
        i = KeyToHashIndex(pkItem->m_key);
        for (i++; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                apPosition = pkItem;
                return;
            }
        }
        apPosition = 0;
    }
}

struct Holder
{
    void FUN_0085efc0(DummyPointerMap*, unsigned int, unsigned short);
    void TESSaveLoadGame_QueueAnimationLoad(TESForm*, unsigned short);
};
// Looks up the parent form's ID in the map at offset 0x58; if present, uses 0 instead, then passes the ID and type to FUN_0085efc0.
// @fnv 0x0085f010
// src: COMMUNITY 0x0085f010
void Holder::TESSaveLoadGame_QueueAnimationLoad(TESForm* apParentForm, unsigned short aeType)
{
    unsigned int uiExistingValue;
    unsigned int formID = apParentForm->GetFormID();
    if ((*(const DummyPointerMap**)((char*)this + 0x58))->GetAt(formID, uiExistingValue))
        formID = 0;
    FUN_0085efc0(*(DummyPointerMap**)((char*)this + 0x58), formID, aeType);
}

// Reads a size from the buffer, writes it to the save game buffer, then writes the following data of that size.
// @fnv 0x00865510
void BGSLoadGameSubBuffer::SaveGame(BGSSaveGameBuffer* apSaveGameBuffer)
{
    char* padvancedBuffer;
    unsigned int isize;
    padvancedBuffer = pBuffer + 1;
    isize = 0;
    padvancedBuffer += ReadEncodedInteger(padvancedBuffer, isize);
    apSaveGameBuffer->SaveVariableSizedValue(isize);
    apSaveGameBuffer->WriteAtOffset(padvancedBuffer, isize, 1);
}

struct FUN_00865660_This
{
    void* vtable;
    void NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer_NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer(unsigned int);
    FUN_00865660_This* Construct(unsigned int);
};
extern int DAT_01082288;
// Calls FUN_008656c0 with size, sets the vtable to DAT_01082288, and returns this.
// @fnv 0x00865660
FUN_00865660_This* FUN_00865660_This::Construct(unsigned int size)
{
    NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer_NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer(size);
    vtable = (void*)&DAT_01082288;
    return this;
}

struct Dummy00865690
{
    void* DestroyAndFreeIfFlagged(unsigned int);
};
// Destructs the NiTMap_TESForm___BGSLoadGameSubBuffer_ object and, if bit 0 of flags is set, frees it with operator delete; returns this.
// @fnv 0x00865690
void* Dummy00865690::DestroyAndFreeIfFlagged(unsigned int flags)
{
    ((NiTMap_TESForm___BGSLoadGameSubBuffer_*)this)
        ->NiTMap_TESForm___BGSLoadGameSubBuffer_::~NiTMap_TESForm___BGSLoadGameSubBuffer_();
    if (flags & 1)
        operator delete(this);
    return this;
}

// Loads queued havok data into the form if it is a reference, otherwise logs an error, then deletes the load buffer.
// @fnv 0x00864d80
void BGSLoadGameSubBuffer::LoadHavokData(TESForm* form)
{
    BGSLoadFormBuffer* buffer = CreateFormBuffer(form);
    if (form->GetIsReference())
    {
        TESForm* reference = form;
        reinterpret_cast<ReferenceSubBufferAccess*>(reference)->LoadHavokData(buffer);
    }
    else
        LogWarning("SAVELOAD: Form '%s' %08X with queued havok data is not a reference", form->GetName(),
                   form->GetFormID());
    delete reinterpret_cast<BGSLoadGameBuffer*>(buffer);
}

extern void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern int DAT_010822a8;
struct FUN_008656c0_This
{
    void* vtable;
    unsigned int m_uiCount;
    void* m_pItems;
    unsigned int m_uiSize;
    FUN_008656c0_This* NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer_NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes for m_pItems, zeroes them, and returns this.
// @fnv 0x008656c0
// src: COMMUNITY 0x008656c0
FUN_008656c0_This* FUN_008656c0_This::NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer_NiTMapBase_DFALL_NiTMapItem_TESForm_BGSLoadGameSubBuffer_TESForm_BGSLoadGameSubBuffer(unsigned int count)
{
    unsigned int uiBytes;
    vtable = (void*)&DAT_010822a8;
    m_uiCount = count;
    m_uiSize = 0;
    uiBytes = m_uiCount << 2;
    m_pItems = NiMalloc(uiBytes);
    memset(m_pItems, 0, m_uiCount << 2);
    return this;
}

struct VersionByte
{
    unsigned char cVersion;
};

// The legacy save-form declarations below use pointer-sized fields to preserve
// the original form-saving callers' /GS stack layout.

unsigned char BGSSaveFormBuffer::GetVersion()
{
    return 0;
}

// @fnv 0x00865120
void BGSLoadGameSubBuffer::RenderCopyData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    char* pbuffer;
    unsigned int isize;
    unsigned int isubBufferSize;
    unsigned int ivariableValueSize;
    VersionByte* pheader;

    isubBufferSize = reinterpret_cast<TESForm*>(apSaveGameBuffer)->GetFormID();
    if (isubBufferSize == 0)
        return;

    ivariableValueSize = GetEncodedIntegerSize(isubBufferSize);
    isize = isubBufferSize + ivariableValueSize + 1;

    this->pBuffer = new char[isize];
    pbuffer = this->pBuffer;
    pheader = reinterpret_cast<VersionByte*>(pbuffer);

    pheader->cVersion = apSaveGameBuffer->GetVersion();
    ++pbuffer;

    WriteEncodedInteger(pbuffer, isubBufferSize);

    pbuffer += ivariableValueSize;

    memcpy(pbuffer, reinterpret_cast<BSSimpleList<TESForm*>*>(apSaveGameBuffer)->BSSimpleList<TESForm*>::GetNext(),
           isubBufferSize);
}

// Destructor of the per-type save-game sub-buffer table: release every buffer in the three maps,
// empty them, then destroy the maps.

struct QueuedSubBufferValue
{
    char* m_pBuffer;

    void Init();
    void Free();
};

class QueuedSubBufferTable
{
  public:
    void* m_pVtbl;
    unsigned int m_uiHashSize;
    void** m_ppHashTable;
    unsigned int m_uiCount;

    ~QueuedSubBufferTable();
    void* GetFirstPos();
    void GetNext(void*& rkPos, TESForm*& rpkKey, QueuedSubBufferValue& rkVal) const;
    void RemoveAll();
};

class FUN_00865220
{
  public:
    QueuedSubBufferTable m_akMaps[3];

    ~FUN_00865220();
};

// Frees every queued sub-buffer value in each of the three maps, then removes all entries from each map.
// @fnv 0x00865220
FUN_00865220::~FUN_00865220()
{
    for (unsigned int i = 0; i < 3; i++)
    {
        void* pIterPos = m_akMaps[i].GetFirstPos();
        while (pIterPos)
        {
            TESForm* pkForm = 0;
            QueuedSubBufferValue kVal;
            kVal.Init();
            m_akMaps[i].GetNext(pIterPos, pkForm, kVal);
            kVal.Free();
        }
        m_akMaps[i].RemoveAll();
    }
}

// SaveAnimation: record the animation state of a reference into a save entry, or log that the form is not a reference.

class F4F20Param
{
  public:
    F4F20Param(int iValue);
    F4F20Param(const F4F20Param& rkOther);
    int m_iValue;
};

class F4F20Response
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;

    F4F20Response();
    ~F4F20Response();
    void Init(unsigned int auiFormId, F4F20Param kParam, int iFormType, int iCount);
    void SetSpeaker(TESForm* pkSpeaker);
};

class F4F20Counter
{
  public:
    int GetCount();
};

extern F4F20Counter* g_pF4F20Counter;

void __cdecl F4F20Log(const char* pcFormat, ...);

// @fnv 0x00864f20
void BGSLoadGameSubBuffer::SaveAnimation(TESForm* pkRef)
{
    if (pkRef->GetIsReference())
    {
        ReferenceSubBufferAccess* pkActor = static_cast<ReferenceSubBufferAccess*>(pkRef);
        F4F20Response kResponse;
        kResponse.Init(pkRef->GetFormID(), F4F20Param(4), pkRef->GetFormType(), g_pF4F20Counter->GetCount());
        kResponse.SetSpeaker(pkRef);
        pkActor->SaveAnimation(&kResponse);
        RenderCopyData(reinterpret_cast<BGSSaveFormBuffer*>(&kResponse));
    }
    else
    {
        F4F20Log("SAVELOAD: Form '%s' %08X passed to BGSLoadGameSubBuffer::SaveAnimation() is not a reference",
                 pkRef->GetName(), pkRef->GetFormID());
    }
}

extern "C" const char DAT_01082228[];
struct FUN_008c71b0
{
    unsigned int value;
    explicit FUN_008c71b0(unsigned int v);
    FUN_008c71b0(const FUN_008c71b0& other);
};
struct SaveContext_00851110
{
    void* GetConstant27();
};
extern "C" SaveContext_00851110* DAT_011de134;
struct FUN_008659c0_Buffer
{
    void* vtable;
    char* data;
    char* next;
    char* end;
    unsigned int capacity;
    unsigned int offset;
    TESForm* form;
    unsigned int flags;
    void* stream;
    FUN_008659c0_Buffer();
    ~FUN_008659c0_Buffer();
    void InitFormEntry(unsigned int formID, FUN_008c71b0 flags, TESBoundObject* base, void* context);
    void FUN_0050f9c0(TESForm* form);
};
// Saves a reference form to a sub-buffer, or logs a warning if the form is not a reference.
// @fnv 0x00865020
void BGSLoadGameSubBuffer::SaveFormState(TESForm* form)
{
    if (form->GetIsReference())
    {
        ReferenceSubBufferAccess* ref = static_cast<ReferenceSubBufferAccess*>(form);
        FUN_008659c0_Buffer buffer;
        buffer.InitFormEntry(form->GetFormID(), FUN_008c71b0(4), reinterpret_cast<TESBoundObject*>(form->FUN_00401170()),
                            DAT_011de134->GetConstant27());
        buffer.FUN_0050f9c0(form);
        ref->SaveHavokData(&buffer);
        RenderCopyData(reinterpret_cast<BGSSaveFormBuffer*>(&buffer));
    }
    else
    {
        LogWarning(DAT_01082228, form->GetName(), form->GetFormID());
    }
}
