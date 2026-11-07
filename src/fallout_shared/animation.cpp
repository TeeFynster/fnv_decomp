#include "../../include/Setting.h"
// 0x00408d60 returns the setting value at +4 (or a fallback byte for null this).

// fallout_shared/animation.cpp: TESAnimGroup, Animation, AnimSequenceMultiple, TaskQueueInterface and more (156 functions)

#include "../../include/Actor.h"
#include "../../include/ANIM_GROUP_ENUM.h"
#include "../../include/BSAnimGroupSequence.h"
#include "../../include/BSSoundHandle.h"
#include "../../include/MapEntryCount.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiTextKeyExtraData.h"
#include "../../include/Setting.h"
#include "../../include/NiUpdateData.h"
#include "../../include/AnimSequenceMultiple.h"
#include "../../include/AnimSequenceSingle.h"
#include "../../include/TESDataHandler.h"
#include "../../include/TESBoundObject.h"
#include "../../include/NiTriBasedGeom.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BGSCameraShot.h"
#include "../../include/BGSSaveLoadGame.h"
#include "../../include/GO.h"
#include "../../include/GameTimerRecord.h"
#include "../../include/LowProcess.h"
#include "../../include/MagicCaster.h"
#include "../../include/NP.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiBlendAccumTransformInterpolator.h"
#include "../../include/NiInterpolator.h"
#include "../../include/NiObject.h"
#include "../../include/NiQuatTransform.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiTimeController.h"
#include "../../include/PathingRequest.h"
#include "../../include/PlayerCharacter.h"
#include "../../include/Script.h"
#include "../../include/StrMem.h"
#include "../../include/TES.h"
#include "../../include/TESActorBaseData.h"
#include "../../include/TESAnimGroup.h"
#include "../../include/TESChallenge.h"
#include "../../include/TESIdleForm.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/hkpCharacterContext.h"
#include "../../include/AutoMemContext.h"



#include "../../include/MEM_CONTEXT.h"

namespace fnv_004965d0 {
extern "C" char DAT_0101dcd8;
extern "C" char DAT_0101dccc;
extern "C" char DAT_0101dcc4;
extern "C" char DAT_011c3f2c;
extern "C" char DAT_011c3b3c;

struct ItemPad4965
{
    virtual void p0();
    char pad[20];
};
struct ItemBase4965
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
};
struct Item4965 : ItemPad4965, ItemBase4965
{
};
struct Container4965
{
    void* FindNthMatchingItem(void*, int);
};
struct Loader4965
{
    void* InsertIdle(void*, void*, int, void*);
    void* LoadKFModel(void*);
};
struct Manager4965
{
    void* GetStringAtOffset();
};
struct Anim4965
{
    Manager4965* GetControllerManager_00496940();
};


extern "C" int __cdecl BSStringT_char_SPrintF(void*, const char*, ...);
extern "C" void* __cdecl BipedAnim_LoadAndAttachAddOn(void*, void*, int, void*, int);
extern "C" void __cdecl AddObjectToPaletteRecursive(void*, void*);
extern "C" int __fastcall QueuedChildren_AddFinishedChild(void*);

struct RefKF4965
{
    void* p;
    RefKF4965(void*);
    ~RefKF4965();
    void* UpdateState_0044b070(void*);
    void* Modelloader_GetReferencedThis();
};
struct RefSol4965
{
    void* p;
    RefSol4965();
    RefSol4965(void*);
    ~RefSol4965();
    void Reset(void*);
    void* Modelloader_GetReferencedThis();
};

}  // namespace fnv_004965d0


// LocalAnimIdle: unit-local AnimIdle with its 0x38-byte layout (RTTI object size 0x38): the ctor 0x004965d0 constructs the smart-pointer members through out-of-line ctors (fnv_004965d0::RefKF4965/RefSol4965); the shared AnimIdle declares no data members
class LocalAnimIdle : public NiRefObject
{
  public:
    enum PLAY_TYPE_ENUM { PlayDefault = 2 };
    LocalAnimIdle(TESIdleForm*, int, int, Actor*, bool, Animation*);
    virtual ~LocalAnimIdle();
    void IncRefCount();
    void DecRefCount();
    int GetSection();
    unsigned int GetFlags();
    BSAnimGroupSequence* GetControllerSequence();
    void Loaded(KFModel*);
    void SetTranslate(const NiPoint3&);
    void SetRotate(const void*);
    int ready;
    void* fieldc;
    fnv_004965d0::RefKF4965 model;
    void* field14;
    fnv_004965d0::RefSol4965 solution;
    fnv_004965d0::Item4965* items[2];
    fnv_004965d0::RefSol4965 sols[2];
    fnv_004965d0::Item4965* source;
    int field30;
    Actor* actor;
};

// Actor.h lacks these three non-virtual operations (0x008a73e0, 0x008a5eb0, 0x00496960); this extension adds no layout.
struct AnimationActorOperations : public Actor
{
    void SetAnimAction(int aiAction, const void* apSequence);
    void ClearQueuedAttack();
    void SetByteAt14E(unsigned char value);
};

class AnimationVector
{
public:
    float x, y, z;
    AnimationVector();
    static const AnimationVector ZERO;
};

class AnimationMotionVector
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    AnimationMotionVector operator+(const AnimationMotionVector& point) const;
    AnimationMotionVector operator-(const AnimationMotionVector& point) const;
    AnimationMotionVector operator*(float scalar) const;
    AnimationMotionVector& operator+=(const AnimationMotionVector& point)
    {
        x += point.x;
        y += point.y;
        z += point.z;
        return *this;
    }
    AnimationMotionVector& operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }
    float Dot(const AnimationMotionVector& point) const
    {
        return x * point.x + y * point.y + z * point.z;
    }
    float Length() const;
    void Unitize();
    static const AnimationMotionVector ZERO;
    float GetLengthSquared();
    AnimationMotionVector CrossProduct(const AnimationMotionVector& point) const;
};

template <class T> class AnimationList
{
  public:
    T m_item;
    AnimationList<T>* m_pkNext;
    AnimationList();
    AnimationList(T& item);
    ~AnimationList();
    T& GetItem();
    AnimationList<T>* GetNext();
    bool IsEmpty();
    void AddTail(T& item);
    void AddTail(const T& item);
    void Remove(const T& item);
    bool IsInList(T& item);
    void AddHead(T& item);
    void RemoveHead();
    void RemoveAll();
    void Sort(int(__cdecl* compare)(T, T));
};

template <class K, class V> class NiTMapItem;
template <class K, class V> class AnimationSequenceMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    NiTMapItem<K, V>** m_ppkHashTable;
    MapEntryCount m_kItemCount;
    AnimationSequenceMap(unsigned int hashSize);
    bool GetAt(K key, V& result) const;
    void SetAt(K key, V value);
    void RemoveAll();
};

template <class T> class AnimationPointer
{
  public:
    T* m_pObject;
    AnimationPointer();
    AnimationPointer(T*);
    ~AnimationPointer();
    operator T*() const;
    T* operator->() const;
    AnimationPointer& operator=(T*);
    AnimationPointer& operator=(const AnimationPointer&);
};

class AnimSequenceBase;
class IdleReplayDelayEntry;
class AnimationNodeAccess : public NiNode
{
  public:
    const NiFixedString& GetName() const;
    void NiAVObject_SetSelectiveUpdate(bool);
    void SetRotate_0043fa80(void*);
    void Update(const NiUpdateData&);
};
#include "../../include/NiMemObject.h"
// TESObjectREFR non-virtual (0x00490310) the canonical header does not declare yet.
class TESObjectREFR_AnimationExt : public TESObjectREFR
{
  public:
    NiAVObject* TESObjectREFR_GetActorBone(NiNode*, const char*);
};
struct Root490;
// No shared KFModel.h is available yet; all KFModel views use this declaration.
class KFModel
{
  public:
    void* GetControllerSequence();
    Root490* GetRoot();
    operator const char*() const;
    void AcquireReference();
};
// No shared ModelLoader.h is available yet; all loader views use this declaration.
class ModelLoader
{
  public:
    KFModel* LoadKF(const char*);
    void NewItem(void*);
};
extern ModelLoader* g_modelLoader;
extern const char* DAT_01199bcc[];
extern char DAT_011a9448;
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern "C" void* memset(void*, int, unsigned int);
int Warning(const char*, ...);
#include "../../include/ANIM_GROUP_ACTION.h"
// No shared Animation.h is available yet; retain the canonical per-file layout.
class Animation
{
  public:
    unsigned char m_uiObjectFlags;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESObjectREFR* m_pAttachedReference;           // +0x4, 4 bytes
    AnimationPointer<NiNode> m_acHeaderData;        // +0x8, 4 bytes
    NiNode* m_pObjectNode;                 // +0xC, 4 bytes
    AnimationVector m_kNodeTranslation;             // +0x10, 12 bytes
    AnimationVector m_kRootTranslation;        // +0x1C, 12 bytes
    NiAVObject* m_acNodeName[8];  // +0x28, 32 bytes
    float m_fAnimationAmount;                   // +0x48, 4 bytes
    unsigned short group[8];            // +0x4C, 16 bytes
    ANIM_GROUP_ACTION action[8];        // +0x5C, 32 bytes
    int m_acTargetName[8];                   // +0x7C, 32 bytes
    unsigned short usReloadGroup[8];        // +0x9C, 16 bytes
    int m_acAnimationName[8];                   // +0xAC, 32 bytes
    char m_cState;                   // +0xCC, 1 bytes
    bool m_bIsPlaying;                     // +0xCD, 1 bytes
    unsigned char layoutPaddingCE[2];
    float time;                                                          // +0xD0, 4 bytes
    float m_fTimeOffset;                                                      // +0xD4, 4 bytes
    AnimationPointer<NiControllerManager> m_acReservedBytes;                            // +0xD8, 4 bytes
    AnimationSequenceMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;  // +0xDC, 4 bytes
    BSAnimGroupSequence* m_pChildTile[8];                            // +0xE0, 32 bytes
    BSAnimGroupSequence* m_pCurrentSequence;                          // +0x100, 4 bytes
    AnimationList<KFModel*> kfModelList;                                  // +0x104, 8 bytes
    float m_fMovementRate;                                                  // +0x10C, 4 bytes
    float m_fCombatAnimationRate;                                                // +0x110, 4 bytes
    float m_fEquipAnimationRate;                                       // +0x114, 4 bytes
    float m_fReloadAnimationRate;                                             // +0x118, 4 bytes
    float m_fAnimationTimeScale;                                              // +0x11C, 4 bytes
    char m_cSkipNextBlend;                                                 // +0x120, 1 bytes
    unsigned char layoutPadding121[1];
    unsigned short m_usQueuedGroup;                    // +0x122, 2 bytes
    AnimationPointer<LocalAnimIdle> LocalInput;                       // +0x124, 4 bytes
    AnimationPointer<LocalAnimIdle> LocalStateValue;                 // +0x128, 4 bytes
    AnimationPointer<LocalAnimIdle> LocalOutput[2];   // +0x12C, 8 bytes
    AnimationList<IdleReplayDelayEntry*> m_acTrailingData;  // +0x134, 8 bytes

    Animation();
    bool Init(AnimationList<const char*>*, NiNode*, TESObjectREFR*, bool);
    void SpecialIdleFree(bool, bool);
    void AssignControllerManager(AnimationPointer<LocalAnimIdle>&);
    void BlendOut(int, bool);
    bool IsAnimationLoaded();
    bool AddAnimation(KFModel*, bool);
    void UpdateFlags(unsigned char, unsigned char, unsigned char);
    NiControllerManager* GetControllerManager_00496940();
    bool SpecialIdleReplace_0();
    bool SpecialIdlePlay_0();
    BSAnimGroupSequence* Animation_PlayGroup(unsigned int, int, int, int);
};

// @fnv 0x00498910
void Animation::SpecialIdleFree(bool freeQueued, bool immediate)
{
    if (LocalInput)
    {
        int section = LocalInput->GetSection();
        switch (section)
        {
        case 21:
            section = 4;
            break;
        case 20:
            section = 1;
            break;
        }
        if (LocalInput->GetControllerSequence() && m_pChildTile[section] == LocalInput->GetControllerSequence())
        {
            if (immediate)
                m_pChildTile[section] = 0;
            else
            {
                switch (LocalInput->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)static_cast<const NiControllerSequence*>(LocalInput->GetControllerSequence())->GetName());
                    return;
                }
                BlendOut(LocalInput->GetSection(), false);
            }
        }
        if (!immediate && !LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!immediate && !LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
            AssignControllerManager(LocalInput);
    }
    if (freeQueued && LocalStateValue)
    {
        int queuedSection = LocalStateValue->GetSection();
        switch (queuedSection)
        {
        case 21:
            queuedSection = 4;
            break;
        case 20:
            queuedSection = 1;
            break;
        }
        if (LocalStateValue->GetControllerSequence() &&
            m_pChildTile[queuedSection] == LocalStateValue->GetControllerSequence())
        {
            if (immediate)
                m_pChildTile[queuedSection] = 0;
            else
            {
                switch (LocalStateValue->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)static_cast<const NiControllerSequence*>(LocalStateValue->GetControllerSequence())->GetName());
                    return;
                }
                BlendOut(queuedSection, false);
            }
        }
        if (!immediate && !LocalOutput[0])
        {
            LocalOutput[0] = LocalStateValue;
            LocalStateValue = 0;
        }
        else if (!immediate && !LocalOutput[1])
        {
            LocalOutput[1] = LocalStateValue;
            LocalStateValue = 0;
        }
        else
            AssignControllerManager(LocalStateValue);
    }
    else
    {
        LocalInput = LocalStateValue;
        LocalStateValue = 0;
    }
}

// Validates files, root and actor, loads KF models into the animation list, creates the controller manager and optionally activates the first sequence.
// @fnv 0x0048ffd0
bool Animation::Init(AnimationList<const char*>* files, NiNode* root, TESObjectREFR* actor, bool activate)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 568);
    if (!files || !root || !actor)
        return false;
    m_pAttachedReference = actor;
    AnimSequenceBase* pSequence;
    if (m_pOwnerReference && m_pOwnerReference->GetAt(0, pSequence))
        return false;
    bool bIsCreature = actor->GetObjectReference()->GetFormType() == 42;
    m_acHeaderData = root;
    for (int i = 0; i <= 7; ++i)
        if (DAT_01199bcc[i])
            m_acNodeName[i] =
                static_cast<TESObjectREFR_AnimationExt*>(actor)->TESObjectREFR_GetActorBone(root, DAT_01199bcc[i]);
    static_cast<AnimationNodeAccess*>((NiNode*)m_acHeaderData)->NiAVObject_SetSelectiveUpdate(false);
    m_acReservedBytes = new NiControllerManager(m_acHeaderData, true);
    bool bQueue = IsAnimationLoaded();
    while (!files->IsEmpty())
    {
        const char* file = files->GetItem();
        KFModel* model = g_modelLoader->LoadKF(file);
        if (model && model->GetControllerSequence())
            AddAnimation(model, bQueue);
        delete file;
        files->RemoveHead();
    }
    if (m_pObjectNode)
        static_cast<AnimationNodeAccess*>(m_pObjectNode)->SetRotate_0043fa80(&DAT_011a9448);
    delete files;
    bool m_bHeaderParsed = m_pOwnerReference->GetAt(0, pSequence);
    if (m_bHeaderParsed && activate)
    {
        BSAnimGroupSequence* anim = pSequence->GetSequenceAtIndex(-1);
        if (anim)
        {
            anim->Activate(100, true, 1.0f, 0.0f, 0, false);
            NiUpdateData update(0.0f, true, false);
            m_acHeaderData->Update(update);
            anim->Deactivate(0.0f, false);
        }
    }
    return m_bHeaderParsed;
}
// @fnv 0x0048f810
Animation::Animation() : m_acHeaderData(0), m_acReservedBytes(0), LocalInput(0), LocalStateValue(0)
{
    m_acHeaderData = 0;
    m_pObjectNode = 0;
    m_kNodeTranslation = AnimationVector::ZERO;
    m_kRootTranslation = AnimationVector::ZERO;
    m_fAnimationAmount = 0.0f;
    m_cState = -1;
    m_cSkipNextBlend = 0;
    UpdateFlags(0, 255, 0);
    m_pAttachedReference = 0;
    m_pCurrentSequence = 0;
    time = 0.0f;
    m_acReservedBytes = 0;
    LocalInput = 0;
    LocalStateValue = 0;
    LocalOutput[0] = 0;
    LocalOutput[1] = 0;
    m_pOwnerReference = new AnimationSequenceMap<unsigned short, AnimSequenceBase*>(101);
    memset(m_acNodeName, 0, 32);
    memset(m_pChildTile, 0, 32);
    memset(group, 255, 16);
    memset(usReloadGroup, 255, 16);
    memset(action, -1, 32);
    memset(m_acTargetName, -1, 32);
    memset(m_acAnimationName, -1, 32);
    m_fMovementRate = 1.0f;
    m_fCombatAnimationRate = 1.0f;
    m_fEquipAnimationRate = 1.0f;
    m_fReloadAnimationRate = 1.0f;
    m_fAnimationTimeScale = 1.0f;
    m_usQueuedGroup = 255;
    m_bIsPlaying = false;
}

struct FUN_0048ef40_shell : public AnimSequenceBase
{
    void SetVirtualTable_0048ef40();
};

extern int DAT_0101d8e8;

// @fnv 0x0048ef40
// src: GUESS 0x0048ef40 (confidence: low)
void FUN_0048ef40_shell::SetVirtualTable_0048ef40()
{
    *(int**)this = &DAT_0101d8e8;
}

namespace fnv_0048f010 {

typedef char _sizecheck_AnimSequenceSingle[sizeof(AnimSequenceSingle) == 8 ? 1 : -1];


// NiTMapView: unit-local view (declares only what 0x0048f010 calls), not the shared NiTMap; renamed so no local type keeps the shared name
template <typename K, typename V> struct NiTMapView
{
    void NewItem(void*);
};
class CombatThreatRecord;

struct WaitableObject
{
    void NiRefObject_IncRefCount();
};

}  // namespace fnv_0048f010

// @fnv 0x0048f010
void AnimSequenceSingle::AssignSequence(BSAnimGroupSequence* apSeq, bool abReleaseModelLoader)
{
    if (pForwardSequence)
    {
        if (abReleaseModelLoader)
        {
            ((fnv_0048f010::NiTMapView<unsigned int, fnv_0048f010::CombatThreatRecord*>*)g_modelLoader)
                ->NewItem((void*)(const char*)((NiAVObject*)pForwardSequence)->GetName());
        }
        ((NiAVObject*)pForwardSequence)->DecRefCount();
    }
    pForwardSequence = apSeq;
    if (pForwardSequence)
    {
        ((fnv_0048f010::WaitableObject*)pForwardSequence)->NiRefObject_IncRefCount();
    }
}


extern int DAT_0101d908;

struct GlobalObject_0048f200
{
    int pad[3];
    GlobalObject_0048f200();
};


struct FUN_0048f1b0
{
    void* m_ppVirtualMethodTable;
    FUN_0048f1b0();
    ~FUN_0048f1b0();
};

// The shared class has no converting constructor with base-lifetime cleanup.
struct FUN_0048f0c0 : public FUN_0048f1b0
{
    void* m_pSingleSequence;
    FUN_0048f0c0(AnimSequenceSingle* apSingleSeq);
    void FUN_0048f3a0(BSAnimGroupSequence*, bool);
};

// @fnv 0x0048f0c0
FUN_0048f0c0::FUN_0048f0c0(AnimSequenceSingle* apSingleSeq)
{
    m_ppVirtualMethodTable = &DAT_0101d908;
    m_pSingleSequence = new GlobalObject_0048f200;
    FUN_0048f3a0(apSingleSeq->GetSequenceAtIndex(-1), true);
    typedef void (__thiscall *AssignSlot)(AnimSequenceSingle*, BSAnimGroupSequence*, bool);
    reinterpret_cast<AssignSlot>((*reinterpret_cast<void***>(apSingleSeq))[1])(apSingleSeq, 0, false);
    // The shared sequence base exposes slot zero without a deleting-destructor signature.
    delete reinterpret_cast<NiObject*>(apSingleSeq);
}

extern int DAT_0101d8e8;

// @fnv 0x0048f1b0
// src: GUESS 0x0048f1b0 (confidence: low)
int* __fastcall Animation_UpdateState_0048f1b0(int* pThis)
{
    *pThis = (int)&DAT_0101d8e8;
    return pThis;
}

void __fastcall NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char_NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char(void* pThis);

// @fnv 0x0048f200
// src: GUESS 0x0048f200 (confidence: low)
void* __fastcall Object_ProcessAndReturnValue_0048f200(void* pThis)
{
    NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char_NiTPointerListBase_DFALL_NiTListItem_BSStringT_char_BSStringT_char(pThis);
    return pThis;
}

struct TESObjectREFR;
struct SequenceListHead48
{
    unsigned int Modelloader_GetReferencedThis() const;
};
struct FUN_006317a0_struct
{
    int AddEight(int);
};
template <class T> struct NiTPointerList_SV
{
    void* DereferenceIfNotNull(void*) const;
};


typedef char _sizecheck_AnimSequenceMultiple[sizeof(AnimSequenceMultiple) == 8 ? 1 : -1];


struct WaitableObject
{
    void NiRefObject_IncRefCount();
};
struct ST_0048f3a0
{
    void NiTPointerListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_AddTail(BSAnimGroupSequence**);
};
// Calls a function on seq, then passes seq by address to a function on the object at this+4.
// @fnv 0x0048f3a0
void AnimSequenceMultiple::AssignSequence(BSAnimGroupSequence* seq, bool b)
{
    ((WaitableObject*)seq)->NiRefObject_IncRefCount();
    (*(ST_0048f3a0**)((char*)this + 4))->NiTPointerListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_AddTail(&seq);
}

class TaskQueueInterface
{
  public:
    void SetTaskFlagDWord(bool, unsigned int);
    void NiAVObject_SetSelectiveUpdate(bool);
};

// @fnv 0x004902f0
// src: XBOX_PDB 0x004902f0
void TaskQueueInterface::NiAVObject_SetSelectiveUpdate(bool bUpdate)
{
    SetTaskFlagDWord(bUpdate, 2);
}

struct FUN_00490310_shell : public TESObjectREFR
{
    NiAVObject* TESObjectREFR_GetActorBone(NiAVObject*, NiFixedString*);
};

NiAVObject* __cdecl BSUtilities_GetObjectByName_00c4b310(NiAVObject*, NiFixedString*, int);

// @fnv 0x00490310
// src: XBOX_PDB 0x00490310
NiAVObject* FUN_00490310_shell::TESObjectREFR_GetActorBone(NiAVObject* apRoot, NiFixedString* apSearch)
{
    return BSUtilities_GetObjectByName_00c4b310(apRoot, apSearch, 1);
}

namespace fnv_00490d90 {
struct AnimationManagerRootAccess : public NiControllerManager
{
    NiAVObject* NiControllerManager_GetAccumRoot();
};

class GlobalObject_004aff00
{
  public:
    unsigned int GetSize(void);
};

// BSSimpleArrayView: unit-local view (declares only what 0x00490d90 calls), not the shared BSSimpleArray; renamed so no local type keeps the shared name
template <class T, unsigned int N> class BSSimpleArrayView
{
  public:
    T& GetAt(unsigned int);
};

// BSStringTView: unit-local view (declares only what 0x00490d90 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> class BSStringTView
{
  public:
    operator const char*(void) const;
};



// @fnv 0x00490d90
// src: COMMUNITY 0x00490d90
NiAVObject* AnimationManagerRootAccess::NiControllerManager_GetAccumRoot()
{
    if (m_bUseCumulativeAnimation)
    {
        for (unsigned int uiIndex = 0;
             uiIndex < reinterpret_cast<GlobalObject_004aff00*>(&m_kSequences)->GetSize();
             ++uiIndex)
        {
            if (reinterpret_cast<const BSStringTView<char>&>(
                    reinterpret_cast<BSSimpleArrayView<unsigned int, 1024>*>(&m_kSequences)
                        ->GetAt(uiIndex))
                    .
                    operator const char*())
            {
                return reinterpret_cast<NiAVObject*>(
                    const_cast<TESChallenge*>(
                        reinterpret_cast<const TESChallenge*>(reinterpret_cast<const BSStringTView<char>&>(
                                                                  reinterpret_cast<BSSimpleArrayView<unsigned int, 1024>*>(
                                                                      &m_kSequences)
                                                                      ->GetAt(uiIndex))
                                                                  .
                                                                  operator const char*()))
                        ->GetInterval());
            }
        }
    }
    return 0;
}
}  // namespace fnv_00490d90


typedef char _sizecheck_AnimSequenceSingle[sizeof(AnimSequenceSingle) == 8 ? 1 : -1];


void __fastcall Animation_UpdateState_0048f1b0(void* pThis);
extern int DAT_0101d8c8;

// @fnv 0x00490e10
void* __fastcall ConstructAnimSequenceSingle(AnimSequenceSingle* pThis)
{
    Animation_UpdateState_0048f1b0(pThis);
    *reinterpret_cast<void**>(pThis) = &DAT_0101d8c8;
    pThis->pForwardSequence = 0;
    return pThis;
}

namespace fnv_00490e40 {

// BSStringTView: unit-local view (declares only what 0x00490e40 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> class BSStringTView
{
  public:
    operator const T*() const;
};

}  // namespace fnv_00490e40

// @fnv 0x00490e40
BSAnimGroupSequence* LocalAnimIdle::GetControllerSequence()
{
    return (BSAnimGroupSequence*)(const char*)*(fnv_00490e40::BSStringTView<char>*)((char*)this + 0x18);
}


namespace fnv_00490f80 {
// BSStringTView: unit-local view (declares only what 0x00490f80 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> class BSStringTView
{
  public:
    operator const T*() const;
};

// @fnv 0x00490f80
// src: XBOX_PDB 0x00490f80
const char* __fastcall PlayerCharacter_GetInventory3D(char* pThis)
{
    return *(const BSStringTView<char>*)(pThis + 0x69c);
}
}  // namespace fnv_00490f80




struct _FakeNiNode
{
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};

// Recursively checks whether apAVObject or any descendant is a NiTriBasedGeom with a skin instance, returning true if found.
// @fnv 0x004910d0
// src: XBOX_PDB 0x004910d0
bool __cdecl Animation_FindSkinnedNode(NiAVObject* apAVObject)
{
    bool bretVal = false;
    if (!apAVObject)
        return bretVal;

    NiTriBasedGeom* pGeom = reinterpret_cast<NiTriBasedGeom*>(apAVObject->IsGeometry());
    if (pGeom && pGeom->GetSkinInstance())
        return true;

    NiNode* pnode = reinterpret_cast<NiAVObject*>(apAVObject)->IsSceneNode();
    if (pnode)
    {
        for (unsigned int n = 0; n < reinterpret_cast<_FakeNiNode*>(pnode)->FUN_0043b480(); ++n)
        {
            NiAVObject* pChildObject = reinterpret_cast<_FakeNiNode*>(pnode)->FUN_0043b4a0(n);
            if (pChildObject)
            {
                bretVal = Animation_FindSkinnedNode(pChildObject);
                if (bretVal)
                    return bretVal;
            }
        }
    }
    return bretVal;
}



// @fnv 0x00493750
// src: COMMUNITY 0x00493750
int __fastcall GetByte10(const TESAnimGroup* apHelper)
{
    return (char)apHelper->sType;
}

float __fastcall GetSequenceEndTime(const void*);
int __fastcall GetAnimGroupWeaponType(TESAnimGroup*);

struct AnimationSequenceTimingAccess : public NiControllerSequence
{
    float NiControllerSequence_GetPhase();
};




// @fnv 0x00493770
// src: XBOX_PDB 0x00493770
float AnimationSequenceTimingAccess::NiControllerSequence_GetPhase()
{
    return GetSequenceEndTime(this) - ((NiControllerSequence*)this)->NiPSysSpawnModifier_GetLifeSpan();
}

namespace fnv_004937a0 {
struct AnimationSequenceInterpolatorAccess : public NiControllerSequence
{
    NiInterpolator* NiControllerSequence_GetInterpolatorAt(unsigned int);
};

// @fnv 0x004937a0
// BSStringTView: unit-local view (declares only what 0x004937a0 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> class BSStringTView
{
  public:
    operator const T*() const;
};
// src: COMMUNITY 0x004937a0
NiInterpolator* AnimationSequenceInterpolatorAccess::NiControllerSequence_GetInterpolatorAt(unsigned int i)
{
    return (NiInterpolator*)(const char*)*(BSStringTView<char>*)((char*)(*(char**)((char*)this + 0x14)) + (i << 4));
}
}  // namespace fnv_004937a0

namespace fnv_00493800 {


struct FUN_00493800_impl : public Animation
{
    float Animation_GetTime(BGSCameraShot* apSequence);
};

// @fnv 0x00493800
// src: XBOX_PDB 0x00493800
float FUN_00493800_impl::Animation_GetTime(BGSCameraShot* apSequence)
{
    return GetSequenceEndTime(apSequence) + *(float*)((char*)this + 0xd0);
}
}  // namespace fnv_00493800

struct FUN_00493830_shell : public Animation
{
    bool Animation_GetAnimsLoading();
};

bool __fastcall _ref_008256d0(void* pThis);

// @fnv 0x00493830
// src: XBOX_PDB 0x00493830
bool FUN_00493830_shell::Animation_GetAnimsLoading()
{
    return !_ref_008256d0(reinterpret_cast<char*>(this) + 0x104);
}

struct FUN_00493860_shell : public Animation
{
    void Animation_SetMoved(bool);
};

struct ST_00493860
{
    void SetFlag(bool, bool);
};
// @fnv 0x00493860
// src: XBOX_PDB 0x00493860
void FUN_00493860_shell::Animation_SetMoved(bool f)
{
    ((ST_00493860*)this)->SetFlag(f, true);
}

struct FUN_00493b90_shell : public Animation
{
    bool Animation_GetMoved();
};

struct FUN_00493990_helper
{
    bool HasFlag(int);
};

// @fnv 0x00493b90
// src: XBOX_PDB 0x00493b90
bool FUN_00493b90_shell::Animation_GetMoved()
{
    return ((FUN_00493990_helper*)this)->HasFlag(1);
}

struct FUN_004941c0_shell : public AnimationVector
{
    AnimationVector* ScaleByInverse(float);
};

// Multiplies x, y and z by the reciprocal of fScalar and returns this.
// @fnv 0x004941c0
AnimationVector* FUN_004941c0_shell::ScaleByInverse(float fScalar)
{
    float fReciprocal = 1.0f / fScalar;
    x *= fReciprocal;
    y *= fReciprocal;
    z *= fReciprocal;
    return this;
}

namespace fnv_00494210 {
// BSStringTView: unit-local view (declares only what 0x00494210 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> struct BSStringTView
{
    operator const char*() const;
};
struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};
struct FUN_00494210_item
{
    char pad[4];
    BSStringTView<char> s;
    char pad2[0xb];
};
struct FUN_00494210_cls
{
    char pad[0x14];
    FUN_00494210_item* items;
    unsigned int GetItemIconFormID(unsigned int i);
};
// @fnv 0x00494210
unsigned int FUN_00494210_cls::GetItemIconFormID(unsigned int uiIndex)
{
    if (items[uiIndex].s.operator const char*())
        return ((BGSMessageInitAccess*)items[uiIndex].s.operator const char*())->GetIconFormID();
    return 0;
}
}  // namespace fnv_00494210

struct NiStream;
struct blob32
{
    char b[32];
};

typedef char _sizecheck_NiQuatTransform[sizeof(NiQuatTransform) == 32 ? 1 : -1];


extern float DAT_0101d890;

// Returns whether m_kTranslate.x differs from the negation of DAT_0101d890.
// @fnv 0x004942c0
bool NiQuatTransform::IsTranslateXNotNegatedConstant()
{
    return x != -DAT_0101d890;
}

struct FUN_00494300_shell : public Animation
{
    short Animation_GetGroupSpeed(unsigned short);
};



struct AnimSequenceBase_vtable
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual bool vfn_c();
    virtual BSAnimGroupSequence* vfn_10(int);
};

TESAnimGroup* __fastcall FUN_0048f7f0(const BSAnimGroupSequence*);

// @fnv 0x00494300
// src: COMMUNITY 0x00494300
short FUN_00494300_shell::Animation_GetGroupSpeed(unsigned short asAnimGroup)
{
    AnimSequenceBase* panimSeq;
    TESAnimGroup* panimGroup;

    if (!m_pOwnerReference->GetAt(asAnimGroup, panimSeq))
        return 0;

    if (reinterpret_cast<AnimSequenceBase_vtable*>(panimSeq)->vfn_c())
    {
        if (!reinterpret_cast<AnimSequenceBase_vtable*>(panimSeq)->vfn_10(-1))
        {
            return 0;
        }
        else
        {
            panimGroup = FUN_0048f7f0(reinterpret_cast<AnimSequenceBase_vtable*>(panimSeq)->vfn_10(-1));
        }
    }
    else
    {
        return 0;
    }

    return panimGroup->GetAnimationSpeed();
}

struct FUN_004946a0_shell : public Animation
{
    void Animation_AddGroup(TESAnimGroup*);
};



struct FUN_00493d50_helper
{
    void CheckAnimGroupMovement(TESAnimGroup*);
};

// @fnv 0x004946a0
// src: COMMUNITY 0x004946a0
void FUN_004946a0_shell::Animation_AddGroup(TESAnimGroup* pAnimGroup)
{
    if (!pAnimGroup)
        return;

    if (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x4e) == 0xff &&
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x9e) == 0xff &&
        reinterpret_cast<TESActorBaseData*>(pAnimGroup)->GetAnimGroupType_0047d3b0() == 0)
    {
        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x9e) =
            reinterpret_cast<TESActorBaseData*>(pAnimGroup)->GetAnimGroupType_0047d3b0();
    }

    reinterpret_cast<FUN_00493d50_helper*>(this)->CheckAnimGroupMovement(pAnimGroup);
}

struct FUN_00494710_shell : public Animation
{
    bool Animation_GroupLoaded(unsigned short);
};

// @fnv 0x00494710
// src: XBOX_PDB 0x00494710
bool FUN_00494710_shell::Animation_GroupLoaded(unsigned short ausGroupIndex)
{
    AnimSequenceBase* panimSeq;
    return m_pOwnerReference->GetAt(ausGroupIndex, panimSeq);
}

// @fnv 0x00495460
float __fastcall GetFloatAtOffset1C(char* pThis)
{
    return *(float*)(pThis + 0x1c);
}

struct AnimationSequenceWeightAccess : public NiControllerSequence
{
    void NiControllerSequence_SetSequenceWeight(float);
};

// Stores the given value at offset 0x1c and clamps it to a minimum of 0.0 if negative.
// @fnv 0x00495480
// src: XBOX_PDB 0x00495480
void AnimationSequenceWeightAccess::NiControllerSequence_SetSequenceWeight(float afValue)
{
    m_fWeight = afValue;
    if (m_fWeight < 0.0)
    {
        m_fWeight = 0.0f;
    }
}

// Returns the larger of the two bytes at offsets 0x29 and 0x2a of pThis.
// @fnv 0x004954e0
unsigned char __fastcall GetMaxOfTwoBytes(unsigned char* pThis)
{
    return pThis[0x2a] > pThis[0x29] ? pThis[0x2a] : pThis[0x29];
}

// Returns the larger of the bytes at offsets 0x2b and 0x29 of pThis.
// @fnv 0x00495520
unsigned char __fastcall GetMaxByte(unsigned char* pThis)
{
    return pThis[0x2b] > pThis[0x29] ? pThis[0x2b] : pThis[0x29];
}



extern Setting g_01267c30;

// @fnv 0x00495580
// src: XBOX_PDB 0x00495580
unsigned char bhkRagdollController_QFootIK()
{
    return *g_01267c30.FUN_00408d60();
}

class NiMatrix3;
struct RagdollAnimationData;
struct bhkConstraint;
struct bhkPoseArray;
struct bhkRagdollController;
struct bhkRigidBody;
struct bhkShapePhantom;
struct bhkWorld;
struct RigidBodyShape;
struct hkQsTransform;
struct hkVector4;
struct hkaFootPlacementIkSolver;
struct SkeletonPoseData;
struct FirstForwardDeclaredType;
struct hkaRagdollInstance;
struct SecondForwardDeclaredType;
struct hkaSkeleton;
struct RagdollController;
struct hkpConstraintMotor;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};

// @fnv 0x004955a0
// src: COMMUNITY 0x004955a0
bool __fastcall bhkRagdollController_GetsFootIKActive(bhkRagdollController* pThis)
{
    return *((bool*)pThis + 0x222);
}



class GlobalObject_004aff00
{
  public:
    unsigned int GetSize(void);
};

// @fnv 0x00495d00
// src: XBOX_PDB 0x00495d00
unsigned int NiControllerManager::GetSequenceCount_00495d00()
{
    return ((GlobalObject_004aff00*)&m_kSequences)->GetSize();
}




namespace fnv_00495d20 {
// BSStringTView: unit-local view (declares only what 0x00495d20 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <typename T> class BSStringTView
{
  public:
    operator const char*() const;
};

// BSSimpleArrayView: unit-local view (declares only what 0x00495d20 calls), not the shared BSSimpleArray; renamed so no local type keeps the shared name
template <typename T, unsigned int N> class BSSimpleArrayView
{
  public:
    T& GetAt(unsigned int);
};

}  // namespace fnv_00495d20

// Returns the controller sequence stored at the given index in the array at offset 0x34, reinterpreted as a NiControllerSequence pointer.
// @fnv 0x00495d20
// src: XBOX_PDB 0x00495d20
NiControllerSequence* NiControllerManager::GetSequenceAt_00495d20(unsigned int uiIndex)
{
    return (NiControllerSequence*)(const char*)reinterpret_cast<fnv_00495d20::BSStringTView<char>&>(
        reinterpret_cast<fnv_00495d20::BSSimpleArrayView<unsigned int, 1024>*>(&m_kSequences)->GetAt(uiIndex));
}


// @fnv 0x00495f30
// src: XBOX_PDB 0x00495f30
TimedTextEntry* NiTextKeyExtraData::GetKeys_00495f30(unsigned int* uiNumKeys)
{
    *uiNumKeys = m_uiNumKeys;
    return m_pKeys;
}

namespace fnv_00496080 {
struct FUN_00496080_shell : public Animation
{
    void Animation_ClearGroup(int, float);
};

int __cdecl Interface_GetMenuModeType();

// BSStringTView: unit-local view (declares only what 0x00496080 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <typename T> class BSStringTView
{
  public:
    operator const char*() const;
};




// @fnv 0x00496080
// src: XBOX_PDB 0x00496080
void FUN_00496080_shell::Animation_ClearGroup(int aeSection, float afEaseOutTime)
{
    int esection = aeSection;
    switch (esection)
    {
    case 20:
        if (Interface_GetMenuModeType() != 1)
        {
            Animation_ClearGroup(7, afEaseOutTime);
            if (!*reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x120))
                Animation_ClearGroup(0, afEaseOutTime);
        }
        Animation_ClearGroup(1, afEaseOutTime);
    case 21:
        if (Interface_GetMenuModeType() != 1)
            Animation_ClearGroup(2, afEaseOutTime);
        Animation_ClearGroup(3, afEaseOutTime);
    case 4:
        Animation_ClearGroup(5, afEaseOutTime);
        Animation_ClearGroup(6, afEaseOutTime);
        esection = 4;
        break;
    }

    if (*reinterpret_cast<BSStringTView<char>*>(reinterpret_cast<char*>(this) + 0xd8) && esection < 8 &&
        reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0xe0)[esection] &&
        reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0xe0)[esection]->GetState())
    {
        if (reinterpret_cast<TESChallenge**>(reinterpret_cast<char*>(this) + 0xe0)[esection]->GetThreshold())
        {
            reinterpret_cast<NiControllerManager*>(
                const_cast<char*>(static_cast<const char*>(
                    *reinterpret_cast<BSStringTView<char>*>(reinterpret_cast<char*>(this) + 0xd8))))
                ->StopSequence(reinterpret_cast<NiControllerSequence*>(
                                   reinterpret_cast<TESChallenge**>(reinterpret_cast<char*>(this) + 0xe0)[esection]
                                       ->GetThreshold()),
                               afEaseOutTime);
        }
        reinterpret_cast<NiControllerManager*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringTView<char>*>(reinterpret_cast<char*>(this) + 0xd8))))
            ->StopSequence(reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0xe0)[esection],
                           afEaseOutTime);
        if (esection == 1)
            *reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0x100) =
                reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0xe0)[esection];
    }

    reinterpret_cast<NiControllerSequence**>(reinterpret_cast<char*>(this) + 0xe0)[esection] = 0;
    reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x4c)[esection] = 0xff;
    reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x9c)[esection] = 0xff;
    reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x5c)[esection] = -1;
}
}  // namespace fnv_00496080

struct FUN_00496280_shell : public Animation
{
    void Animation_ZeroGlobalTransform();
};

void __fastcall Animation_ClearAccumRootTranslate(void*);
void* __cdecl DynamicCastByRTTI(const void*, void*);
extern char const* const g_011f36ec_arg1;
extern int g_011f371c;



class Model
{
  public:
    NiNode* GetObject3D(void);
};





class FakeVtable_00496280
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void* vc4(int);
};

// @fnv 0x00496280
// src: XBOX_PDB 0x00496280
void FUN_00496280_shell::Animation_ZeroGlobalTransform()
{
    if (*(NiNode**)((char*)this + 0xc) == 0)
        return;

    Animation_ClearAccumRootTranslate(this);
    (*(NiNode**)((char*)this + 0xc))->SetRotate_0043fa80(&DAT_011a9448);
    (*(NiAVObject**)((char*)this + 0xc))->SetEffectColor((const NiPoint3&)AnimationVector::ZERO);

    NiTimeController* pTimeController = (NiTimeController*)((*(Model**)((char*)this + 0xc))->GetObject3D());
    while (pTimeController)
    {
        FakeVtable_00496280* pinter = (FakeVtable_00496280*)DynamicCastByRTTI(&g_011f36ec_arg1, pTimeController);
        if (pinter)
        {
            void* pinter2 = pinter->vc4(0);
            if (pinter2)
            {
                NiBlendAccumTransformInterpolator* pBlendInterpolator =
                    (NiBlendAccumTransformInterpolator*)DynamicCastByRTTI(&g_011f371c, pinter2);
                if (pBlendInterpolator)
                {
                    pBlendInterpolator->ResetAccumulation();
                }
            }
        }
        pTimeController = pTimeController->GetNext();
    }
}



// @fnv 0x00496420
void NiQuatTransform::SetScale(float fScale)
{
    scale = fScale;
    SetScaleValid(true);
}


struct FUN_004964d0_shell : public Animation
{
    void Animation_ClearAccumRootTranslate();
};

// Sets the AnimationVector at offset 0x1c of this Animation object to AnimationVector::ZERO.
// @fnv 0x004964d0
// src: XBOX_PDB 0x004964d0
void FUN_004964d0_shell::Animation_ClearAccumRootTranslate()
{
    *reinterpret_cast<AnimationVector*>(reinterpret_cast<char*>(this) + 0x1c) = AnimationVector::ZERO;
}

struct FUN_00496550_shell : public Animation
{
    float GetMinBlendValue(NiNode*);
};

float __cdecl GetFloatProperty(NiNode*, int);
struct Calendar
{
    unsigned int GetDaysPassed();
};

// @fnv 0x00496550
float FUN_00496550_shell::GetMinBlendValue(NiNode* apNode)
{
    float fMinBlend = 1.0f;
    if (apNode != 0)
    {
        float fblendValue = GetFloatProperty(apNode, 0);
        if (fblendValue < fMinBlend)
            fMinBlend = fblendValue;
        if (apNode != m_pObjectNode)
        {
            fblendValue = GetMinBlendValue((NiNode*)((Calendar*)apNode)->GetDaysPassed());
            if (fblendValue < fMinBlend)
                fMinBlend = fblendValue;
        }
    }
    return fMinBlend;
}

extern long volatile DAT_011f4400;
extern int vftable_NiRefObject;
void __cdecl FinishScriptRunLock(void*);
// Sets the object's vtable to vftable_NiRefObject and calls FinishScriptRunLock on DAT_011f4400.
// @fnv 0x00496910
// src: GUESS 0x00496910 (confidence: medium)
void __fastcall Animation_ResetVtableAndFinishScriptRunLock(int** apObject)
{
    *apObject = &vftable_NiRefObject;
    FinishScriptRunLock((void*)&DAT_011f4400);
}

namespace fnv_00496940 {


// BSStringTView: unit-local view (declares only what 0x00496940 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <typename T> class BSStringTView
{
  public:
    operator const char*() const;
};

}  // namespace fnv_00496940

// @fnv 0x00496940
// src: XBOX_PDB 0x00496940
NiControllerManager* Animation::GetControllerManager_00496940()
{
    return (NiControllerManager*)(const char*)*(fnv_00496940::BSStringTView<char>*)((char*)this + 0xd8);
}

void __fastcall FUN_004969b0(void*);

struct FUN_00496980_caller
{
    void* FUN_00496980(unsigned int flags);
};

// Calls FUN_004969b0 on this, then frees this with NiMemObject::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00496980
void* FUN_00496980_caller::FUN_00496980(unsigned int flags)
{
    FUN_004969b0(this);
    if (flags & 1)
    {
        NiMemObject::operator delete(this, 0x38);
    }
    return this;
}

namespace fnv_00496fe0 {
// BSStringTView: unit-local view (declares only what 0x00496fe0 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> struct BSStringTView
{
    operator const char*() const;
};
struct FUN_00496fe0_tgt
{
    void Actor_SetAnimAction(int, const char*);
};
struct FUN_00496fe0_cls
{
    char pad0[8];
    int state;
    int kind;
    char pad1[8];
    AnimationPointer<NiNode> node;
    char pad2[0x34 - 0x1c];
    FUN_00496fe0_tgt* tgt;
    bool AnimIdle_PlayAnim(NiNode* n);
};
// @fnv 0x00496fe0
// src: COMMUNITY 0x00496fe0
bool FUN_00496fe0_cls::AnimIdle_PlayAnim(NiNode* apNode)
{
    if (state != 1)
        return false;
    node = apNode;
    state = 2;
    if (kind == 3)
        tgt->Actor_SetAnimAction(0xd, ((BSStringTView<char>*)&node)->operator const char*());
    return true;
}
}  // namespace fnv_00496fe0

struct FUN_004974a0_shell : public Animation
{
    void Animation_SkipNextBlend();
};

// @fnv 0x004974a0
// src: XBOX_PDB 0x004974a0
void FUN_004974a0_shell::Animation_SkipNextBlend()
{
    *reinterpret_cast<char*>(reinterpret_cast<char*>(this) + 0x120) = 1;
}

struct ActiveEffect;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiColor;
struct NiFormArray;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESClass;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct FileEntryList;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00497f20_shell : public Animation
{
    void Animation_SpecialIdleAuto(TESIdleForm*, Actor*, int, int);
};




void __fastcall FUN_004965d0(void* pThis, int, TESIdleForm*, int, int, Actor*, int, Animation*);
void __fastcall SpecialIdlePlay_0(Animation* pThis);


struct VTable0x390
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390(TESIdleForm*);
};

// @fnv 0x00497f20
// src: XBOX_PDB 0x00497f20
void FUN_00497f20_shell::Animation_SpecialIdleAuto(TESIdleForm* apIdleForm, Actor* apActor, int aeSection, int aeType)
{
    AutoMemContext tempMemContext((MEM_CONTEXT)0x33, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x129d);
    int etype = aeType;
    switch (aeSection)
    {
    case 0:
    case 1:
    case 0x14:
        etype = 3;
        break;
    }
    *(AnimationPointer<NiNode>*)((char*)this + 0x128) =
        (NiNode*)new LocalAnimIdle(apIdleForm, aeSection, etype, apActor, 0, this);
    ((VTable0x390*)((TES*)apActor)->GetLogDate())->v390(apIdleForm);
    ::SpecialIdlePlay_0(this);
}

class bhkWorldObject;
namespace fnv_00498170 {


// BSStringTView: unit-local view (declares only what 0x00498170 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <typename T> class BSStringTView
{
  public:
    operator const T*() const;
};



struct TESObjectREFR_GetFlags_Helper
{
    unsigned int GetFlags();
};

}  // namespace fnv_00498170

// @fnv 0x00498170
// src: COMMUNITY 0x00498170
bool Animation::SpecialIdleReplace_0()
{
    if (reinterpret_cast<fnv_00498170::BSStringTView<char>*>(&LocalStateValue)->operator const char*() &&
        reinterpret_cast<fnv_00498170::TESObjectREFR_GetFlags_Helper*>(
            const_cast<char*>(reinterpret_cast<fnv_00498170::BSStringTView<char>*>(&LocalStateValue)->operator const char*()))
                ->GetFlags() == 1 &&
        AddAnimation(
            reinterpret_cast<KFModel*>(
                reinterpret_cast<bhkCollisionObject*>(
                    const_cast<char*>(reinterpret_cast<fnv_00498170::BSStringTView<char>*>(&LocalStateValue)->operator const char*()))
                    ->GetWorldObject()),
            false))
    {
        reinterpret_cast<AnimationPointer<NiNode>*>(&LocalStateValue)->operator=(0);
        return true;
    }
    return false;
}


struct FUN_00498910_shell : public Animation
{
    void Animation_SpecialIdleFree(bool, bool);
};

// @fnv 0x00498910
// src: XBOX_PDB 0x00498910
void FUN_00498910_shell::Animation_SpecialIdleFree(bool abFreeQueued, bool abForceDelete)
{
    if (LocalInput)
    {
        int esection = LocalInput->GetSection();
        switch (esection)
        {
        case 0x15:
            esection = 4;
            break;
        case 0x14:
            esection = 1;
            break;
        }
        if (LocalInput->GetControllerSequence() && m_pChildTile[esection] == LocalInput->GetControllerSequence())
        {
            if (abForceDelete)
            {
                m_pChildTile[esection] = 0;
            }
            else
            {
                switch (LocalInput->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)static_cast<const NiControllerSequence*>(LocalInput->GetControllerSequence())->GetName());
                    return;
                }
                BlendOut(LocalInput->GetSection(), false);
            }
        }
        if (!abForceDelete && !LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!abForceDelete && !LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
        {
            AssignControllerManager(LocalInput);
        }
    }
    if (abFreeQueued && LocalStateValue)
    {
        int esection = LocalStateValue->GetSection();
        switch (esection)
        {
        case 0x15:
            esection = 4;
            break;
        case 0x14:
            esection = 1;
            break;
        }
        if (LocalStateValue->GetControllerSequence() &&
            m_pChildTile[esection] == LocalStateValue->GetControllerSequence())
        {
            if (abForceDelete)
            {
                m_pChildTile[esection] = 0;
            }
            else
            {
                switch (LocalStateValue->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)static_cast<const NiControllerSequence*>(LocalStateValue->GetControllerSequence())->GetName());
                    return;
                }
                BlendOut(esection, false);
            }
        }
        if (!abForceDelete && !LocalOutput[0])
        {
            LocalOutput[0] = LocalStateValue;
            LocalStateValue = 0;
        }
        else if (!abForceDelete && !LocalOutput[1])
        {
            LocalOutput[1] = LocalStateValue;
            LocalStateValue = 0;
        }
        else
        {
            AssignControllerManager(LocalStateValue);
        }
    }
    else
    {
        LocalInput = LocalStateValue;
        LocalStateValue = 0;
    }
}

namespace fnv_00498cf0 {
struct FUN_00498cf0_shell : public Animation
{
    BSAnimGroupSequence* Animation_SpecialIdleGetSequence();
};

// BSStringTView: unit-local view (declares only what 0x00498cf0 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> class BSStringTView
{
  public:
    operator const T*() const;
};

// @fnv 0x00498cf0
// src: XBOX_PDB 0x00498cf0
BSAnimGroupSequence* FUN_00498cf0_shell::Animation_SpecialIdleGetSequence()
{
    if (!*(BSStringTView<char>*)((char*)this + 0x124))
        return 0;
    return ((LocalAnimIdle*)(const char*)*(BSStringTView<char>*)((char*)this + 0x124))->GetControllerSequence();
}
}  // namespace fnv_00498cf0

struct FUN_00498ea0_wrap
{
    bool impl(BSAnimGroupSequence* pSequence);
};

// Checks the four LocalAnimIdle pointers at offsets 0x124-0x130 and returns true if any of their sequences equals pSequence.
// @fnv 0x00498ea0
bool FUN_00498ea0_wrap::impl(BSAnimGroupSequence* pSequence)
{
    if (*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x124) != 0)
    {
        if (((LocalAnimIdle*)*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x124))->GetControllerSequence() == pSequence)
            return true;
    }
    if (*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x128) != 0)
    {
        if (((LocalAnimIdle*)*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x128))->GetControllerSequence() == pSequence)
            return true;
    }
    if (*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x12c) != 0)
    {
        if (((LocalAnimIdle*)*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x12c))->GetControllerSequence() == pSequence)
            return true;
    }
    if (*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x130) != 0)
    {
        if (((LocalAnimIdle*)*(AnimationPointer<LocalAnimIdle>*)((char*)this + 0x130))->GetControllerSequence() == pSequence)
            return true;
    }
    return false;
}

namespace fnv_00498f80 {
// BSStringTView: unit-local view (declares only what 0x00498f80 calls), not the shared BSStringT; renamed so no local type keeps the shared name
template <class T> struct BSStringTView
{
    int x;
    operator const char*() const;
};
struct FUN_00498f80_flags
{
    unsigned int GetFlags();
};
struct FUN_00498f80_cls
{
    char pad[0x124];
    BSStringTView<char> a;
    BSStringTView<char> b;
    bool Animation_SpecialIdleWorking();
};
// @fnv 0x00498f80
// src: XBOX_PDB 0x00498f80
bool FUN_00498f80_cls::Animation_SpecialIdleWorking()
{
    if (a.operator const char*())
    {
        if (((LocalAnimIdle*)a.operator const char*())->GetControllerSequence() == 0)
        {
            if (((FUN_00498f80_flags*)a.operator const char*())->GetFlags() == 3)
                return false;
            return true;
        }
        else
        {
            switch (((LocalAnimIdle*)a.operator const char*())->GetControllerSequence()->GetState())
            {
            case 2:
            case 5:
                return true;
            }
        }
    }
    if (b.operator const char*())
    {
        if (((LocalAnimIdle*)b.operator const char*())->GetControllerSequence() == 0)
        {
            return true;
        }
        else
        {
            switch (((LocalAnimIdle*)b.operator const char*())->GetControllerSequence()->GetState())
            {
            case 2:
            case 5:
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_00498f80

struct FUN_0049bb20_cls : public NiMemObject
{
    void FUN_004eeb00();
    void* FUN_0049bb20(unsigned int f);
};
// Calls FUN_004eeb00, then if bit 0 of f is set frees this with operator delete and returns this.
// @fnv 0x0049bb20
void* FUN_0049bb20_cls::FUN_0049bb20(unsigned int auiFlags)
{
    FUN_004eeb00();
    if (auiFlags & 1)
        NiMemObject::operator delete(this, 0x78);
    return this;
}


// @fnv 0x00508100
// src: XBOX_PDB 0x00508100
float NiControllerSequence::GetEndKeyTime_00508100()
{
    return m_fLastKeyTime;
}

// The section-priority accessor is not declared by the shared header.
struct AnimGroupSectionAccess : public TESAnimGroup
{
    unsigned char GetSectionPriority(int aeSection);
};

// @fnv 0x00508d90
unsigned char AnimGroupSectionAccess::GetSectionPriority(int aeSection)
{
    return m_ucSectionPriorities[aeSection];
}


// @fnv 0x00639aa0
// src: XBOX_PDB 0x00639aa0
float NiControllerSequence::TESCombatStyle_GetTargetingFOV()
{
    return m_fSequenceOffset;
}

struct FUN_006d2c40_dummy
{
    float m_func();
};

// @fnv 0x006d2c40
float __fastcall GetFieldB4Float(char* pObject)
{
    return *(float*)(pObject + 0xb4);
}

class ActiveEffect;
class Actor;
class BSExtraData;
class EffectItem;
class MagicItem;
class MagicProjectile;
class MagicTarget;
class SpellItem;
class TESObjectCELL;
class hkpRigidBody;
namespace fnv_00825c00 {
struct MagicEffectCollection;
struct blob12
{
    char b[12];
};

typedef char _sizecheck_BSTimer[sizeof(GameTimerRecord) == 32 ? 1 : -1];

typedef char _sizecheck_MagicCaster[sizeof(MagicCaster) == 12 ? 1 : -1];


}  // namespace fnv_00825c00

// @fnv 0x00825c00
unsigned int GameTimerRecord::GetTime()
{
    return m_uiFirstTimerValue;
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0048efc0(unsigned int flags);
};
// @fnv 0x0048efc0
void* DelStandIn::FUN_0048efc0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

int __cdecl strcpy_s(char*, unsigned int, const char*);
struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
    void NiRefObject_DecRefCount();
};

struct FUN_0048ef40
{
    virtual ~FUN_0048ef40();
};
struct FUN_0048ee70 : public FUN_0048ef40
{
    SeqObj* pForwardSequence;
    ~FUN_0048ee70();
};
// @fnv 0x0048ee70
FUN_0048ee70::~FUN_0048ee70()
{
    char seqFilename[260];
    if (pForwardSequence)
    {
        strcpy_s(seqFilename, 260, pForwardSequence->GetName());
        pForwardSequence->NiRefObject_DecRefCount();
        ((ModelLoader*)g_modelLoader)->NewItem(seqFilename);
    }
}

namespace fnv_0048f450 {

typedef char _sizecheck_AnimSequenceMultiple[sizeof(AnimSequenceMultiple) == 8 ? 1 : -1];


// Exe 0x0048f450: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct AnimationOffset08View
{
    unsigned int GetFlags();
};
struct Flt
{
    operator unsigned int() const;
};
struct FUN_006317a0_struct
{
    int* AddEight(int);
};
struct NiTPointerList_TESObjectREFR
{
    void* DereferenceIfNotNull(void*) const;
};
unsigned int __cdecl DialogueRandom();
struct SeqListT : public AnimationOffset08View, public Flt, public FUN_006317a0_struct, public NiTPointerList_TESObjectREFR
{
};
}  // namespace fnv_0048f450

// Returns the BSAnimGroupSequence at aiSequenceIndex, or a random one when the index is -1 or out of range, by walking the list.
// @fnv 0x0048f450
BSAnimGroupSequence* AnimSequenceMultiple::GetSequenceAtIndex(char aiSequenceIndex)
{
    BSAnimGroupSequence* pForwardSequence;
    void* listIt;
    int iTargetIndex;
    if (aiSequenceIndex != -1 && (unsigned int)aiSequenceIndex < ((fnv_0048f450::AnimationOffset08View*)m_pSingleSequence)->GetFlags())
        iTargetIndex = aiSequenceIndex;
    else
        iTargetIndex = fnv_0048f450::DialogueRandom() % ((fnv_0048f450::AnimationOffset08View*)m_pSingleSequence)->GetFlags();
    listIt = (void*)(unsigned int)*(fnv_0048f450::Flt*)m_pSingleSequence;
    while (listIt)
    {
        pForwardSequence = *(BSAnimGroupSequence**)((fnv_0048f450::FUN_006317a0_struct*)m_pSingleSequence)->AddEight((int)listIt);
        if (iTargetIndex-- == 0)
            return pForwardSequence;
        listIt = ((fnv_0048f450::NiTPointerList_TESObjectREFR*)m_pSingleSequence)->DereferenceIfNotNull(listIt);
    }
    return 0;
}


namespace fnv_00493d50 {
struct FUN_00493d50_shell : public Animation
{
    void CheckAnimGroupMovement(TESAnimGroup*);
};

struct AnimSequenceBase_Helper
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual class LocalAnimIdle* vfn_04(int);
};



struct Flt
{
    int m;
    operator unsigned int() const;
};









struct AnimIdle_Helper : public NiControllerSequence
{
    unsigned int Deallocate();
    int GetItemIconFormID(unsigned int);
    NiInterpolator* NiControllerSequence_GetInterpolatorAt(unsigned int);
};

struct Animation_Layout
{
    char pad_00[0x08];
    Flt m_acHeaderData;  // +0x08
    char pad_0c[0xcc];
    Flt m_acReservedBytes;                                                       // +0xd8
    AnimationSequenceMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;  // +0xdc
};






// The speed setter is not declared by the shared header.
struct AnimGroupMovementAccess : public TESAnimGroup
{
    void SetSpeed(AnimationVector*);
};

struct NiFixedString_access
{
    operator const char*() const;
};

struct NiPoint3_sub : public AnimationVector
{
    AnimationVector operator-(const AnimationVector&) const;
};



struct FUN_004941c0_shell
{
    AnimationVector* ScaleByInverse(float);
};

struct AnimGroupInfo
{
    const char* name;
    unsigned char bNoMove;
    int pad_08;
    unsigned int moveType;
    int pad_10[5];
};

extern AnimGroupInfo DAT_011977d8[];
extern const char* DAT_01197794[];
extern const char* DAT_011977a4[];
extern double _gModifierZero;

// @fnv 0x00493d50
void FUN_00493d50_shell::CheckAnimGroupMovement(TESAnimGroup* apAnimGroup)
{
    unsigned short sanimGroup = ((TESActorBaseData*)apAnimGroup)->GetAnimGroupType_0047d3b0();
    unsigned int eanimGroup = apAnimGroup->GetType();
    AnimSequenceBase* panimSeq;
    if (!((Animation_Layout*)this)->m_acReservedBytes ||
        !((Animation_Layout*)this)->m_pOwnerReference->GetAt(sanimGroup, panimSeq))
        return;
    if (eanimGroup == 1 || eanimGroup == 2)
        return;
    NiAVObject* pbip01 = ((fnv_00490d90::AnimationManagerRootAccess*)(unsigned int)((Animation_Layout*)this)->m_acReservedBytes)->NiControllerManager_GetAccumRoot();
    if (!pbip01)
    {
        Warning("ANIMATION: Could not find AccumRoot in animation '%s'.",
                (const char*)((
                    const NiFixedString_access&)(((NiAVObject*)(unsigned int)((Animation_Layout*)this)->m_acHeaderData)
                                                     ->GetName())));
        return;
    }
    bool bcheckForMovement = false;
    int estart = 0;
    int estop = 1;
    if (((AnimSequenceBase_Helper*)panimSeq)->vfn_04(-1) && !DAT_011977d8[eanimGroup].bNoMove)
    {
        switch (DAT_011977d8[eanimGroup].moveType)
        {
        case 0:
        case 1:
            estart = 0;
            estop = 1;
            bcheckForMovement = true;
            break;
        case 2:
            estart = 0;
            estop = 3;
            bcheckForMovement = true;
            break;
        case 5:
            estart = 0;
            estop = 4;
            bcheckForMovement = true;
            break;
        case 6:
            estart = 0;
            estop = 2;
            bcheckForMovement = true;
            break;
        case 7:
            estart = 0;
            estop = 4;
            bcheckForMovement = true;
            break;
        case 8:
            estart = 0;
            estop = 3;
            bcheckForMovement = true;
            break;
        case 9:
            estart = 0;
            estop = 3;
            bcheckForMovement = true;
            break;
        }
    }
    if (bcheckForMovement)
    {
        AnimationPointer<LocalAnimIdle> spseq(((AnimSequenceBase_Helper*)panimSeq)->vfn_04(-1));
        AnimationVector interpDelta = AnimationVector::ZERO;
        for (unsigned int n = 0; n < ((AnimIdle_Helper*)(unsigned int)(*(Flt*)&spseq))->Deallocate(); ++n)
        {
            if (((AnimIdle_Helper*)(unsigned int)(*(Flt*)&spseq))->GetItemIconFormID(n) ==
                ((TESChallenge*)(unsigned int)(*(Flt*)&spseq))->GetInterval())
            {
                NiInterpolator* pinterp = ((AnimIdle_Helper*)(unsigned int)(*(Flt*)&spseq))->NiControllerSequence_GetInterpolatorAt(n);
                float fstartTime = ((NiControllerSequence*)(unsigned int)(*(Flt*)&spseq))->NiPSysSpawnModifier_GetLifeSpan();
                float fstopTime = ((NiControllerSequence*)(unsigned int)(*(Flt*)&spseq))->GetEndKeyTime_00508100();
                NiQuatTransform quatStart;
                NiQuatTransform quatStop;
                pinterp->UpdateTransform(fstartTime, 0, quatStart);
                pinterp->UpdateTransform(fstopTime, 0, quatStop);
                if (quatStart.IsTranslateXNotNegatedConstant() && quatStop.IsTranslateXNotNegatedConstant())
                {
                    AnimationVector delta = ((const NiPoint3_sub&)quatStop.GetTranslate()) - ((const NiPoint3_sub&)quatStart.GetTranslate());
                    ((FUN_004941c0_shell*)&delta)->ScaleByInverse(fstopTime - fstartTime);
                    ((AnimGroupMovementAccess*)apAnimGroup)->SetSpeed(&delta);
                }
                break;
            }
        }
    }
    switch (TESAnimGroup::GetType(sanimGroup))
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        if (apAnimGroup->GetAnimationSpeed() == _gModifierZero)
        {
            Warning("ANIMATION: AnimGroup '%s%s%s' for '%s' was exported with 'Animate in Place' from MAX.\r\n",
                    DAT_01197794[apAnimGroup->GetMoveAnimGroup()], DAT_011977a4[GetAnimGroupWeaponType(apAnimGroup)],
                    DAT_011977d8[apAnimGroup->GetType()].name,
                    (const char*)((
                        const NiFixedString_access&)(((NiAVObject*)(unsigned int)((Animation_Layout*)this)->m_acHeaderData)
                                                         ->GetName())));
        }
        break;
    }
}
}  // namespace fnv_00493d50

int __cdecl GetType(unsigned short);
struct AnimGroupInfo
{
    int iType;
    int rest[8];
};
extern AnimGroupInfo DAT_011977e0[];
struct SeqIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual bool IsSingleSeq();
    virtual SeqIface* GetSequenceAtIndex(int);
    SeqIface* FindObjectByNameVariant(void*, int);
};
struct FUN_004948c0_shell : public Animation
{
    SeqIface* GetSequenceForGroup(unsigned short, int);
    SeqIface* Animation_StartGroup(SeqIface*, unsigned short, int);
};
// Looks up the sequence base for a group, resolves its type when type is -1, picks a single or multiple sequence, and passes it to FUN_004949a0.
// @fnv 0x004948c0
SeqIface* FUN_004948c0_shell::GetSequenceForGroup(unsigned short group, int type)
{
    AnimSequenceBase* pSeqBase;
    SeqIface* pseqX;
    SeqIface* pSeqMultiple;
    int iType;
    if (group == 0xff || !m_pOwnerReference->GetAt(group, pSeqBase))
        return 0;
    iType = type;
    if (iType == -1)
        iType = DAT_011977e0[GetType(group)].iType;
    switch (iType)
    {
    case 5:
    case 6:
        if (!((SeqIface*)pSeqBase)->IsSingleSeq())
        {
            pSeqMultiple = (SeqIface*)pSeqBase;
            pseqX = pSeqMultiple->FindObjectByNameVariant(*(void**)((char*)this + 0xf0), iType);
            break;
        }
    default:
        pseqX = ((SeqIface*)pSeqBase)->GetSequenceAtIndex(-1);
    }
    return Animation_StartGroup(pseqX, group, type);
}

namespace fnv_00495740 {
struct FUN_00495740_shell : public Animation
{
    unsigned short ResolveAnimGroup(unsigned short, bool);
};



extern PlayerCharacter* g_thePlayer;
struct AnimGroupInfo
{
    const char* name;
    bool supportsVariants;
    int sequenceType;
    int keyType;
    int unk10;
    int unk14[4];
};
extern AnimGroupInfo DAT_011977d8[];
int __cdecl TESAnimGroup_GetWeapon(unsigned short);

// Resolves an animation group to an available sequence group, recursing through variant and iron-sights fallbacks and returning 0 when none is found.
// @fnv 0x00495740
unsigned short FUN_00495740_shell::ResolveAnimGroup(unsigned short asAnimGroup, bool abRecursive)
{
    AnimSequenceBase* panimSeq;
    unsigned short sreturnGroup;
    unsigned short stestGroup;

    if (((Animation*)this)->m_pOwnerReference->GetAt(asAnimGroup, panimSeq) && panimSeq->GetSequenceAtIndex(-1))
        return asAnimGroup;

    if (asAnimGroup & 0x8000)
    {
        sreturnGroup = ResolveAnimGroup(asAnimGroup & 0x7fff, true);
        if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff) ||
            (TESAnimGroup::IsIronSightsAction(asAnimGroup) && (sreturnGroup & 0xff) == ((asAnimGroup - 3) & 0xff)))
            return sreturnGroup;
    }

    if (((Animation*)this)->m_pAttachedReference == g_thePlayer && (Animation*)this == g_thePlayer->GetAnimation(true) &&
        (asAnimGroup & 0x7000))
    {
        switch (DAT_011977d8[asAnimGroup & 0xff].sequenceType)
        {
        case 4:
        case 5:
        case 6:
            sreturnGroup = ResolveAnimGroup(asAnimGroup & 0xfff, true);
            if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff) ||
                (TESAnimGroup::IsIronSightsAction(asAnimGroup) && (sreturnGroup & 0xff) == ((asAnimGroup - 3) & 0xff)))
                return sreturnGroup;
        }
    }

    if (TESAnimGroup::IsIronSightsAction(asAnimGroup))
        return ResolveAnimGroup(asAnimGroup - 3, true);

    switch (DAT_011977d8[TESAnimGroup::GetType(asAnimGroup)].sequenceType)
    {
    case 5:
    case 6:
        return 0;
    }

    if (asAnimGroup & 0xf00)
    {
        switch (TESAnimGroup_GetWeapon(asAnimGroup))
        {
        case 3:
            if (((Animation*)this)->m_pOwnerReference->GetAt(asAnimGroup & 0xf0ff | 0x200, panimSeq) &&
                panimSeq->GetSequenceAtIndex(-1))
                return asAnimGroup & 0xf0ff | 0x200;
            break;
        case 2:
        case 4:
            break;
        default:
            if (((Animation*)this)->m_pOwnerReference->GetAt(asAnimGroup & 0xf0ff | 0x400, panimSeq) &&
                panimSeq->GetSequenceAtIndex(-1))
                return asAnimGroup & 0xf0ff | 0x400;
        }
        if (((Animation*)this)->m_pOwnerReference->GetAt(asAnimGroup & 0xf0ff, panimSeq) &&
            panimSeq->GetSequenceAtIndex(-1))
            return asAnimGroup & 0xf0ff;
    }

    if (asAnimGroup & 0x8000)
    {
        sreturnGroup = ResolveAnimGroup(asAnimGroup & 0x7fff, true);
        if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff))
            return sreturnGroup;
    }

    if (asAnimGroup && 0x7f00)
    {
        stestGroup = 0xff;
        switch (TESAnimGroup::GetType(asAnimGroup))
        {
        case 7:
            stestGroup = asAnimGroup & 0x7f00 | 3;
            break;
        case 8:
            stestGroup = asAnimGroup & 0x7f00 | 4;
            break;
        case 9:
            stestGroup = asAnimGroup & 0x7f00 | 5;
            break;
        case 10:
            stestGroup = asAnimGroup & 0x7f00 | 6;
        }
        if (stestGroup != 0xff)
        {
            sreturnGroup = ResolveAnimGroup(stestGroup, true);
            if ((sreturnGroup & 0xff) == (stestGroup & 0xff))
                return sreturnGroup;
        }
    }

    if (abRecursive)
        return 0;

    if (asAnimGroup & 0x7000)
    {
        sreturnGroup = ResolveAnimGroup(asAnimGroup & 0xfff, true);
        if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff))
            return sreturnGroup;
    }

    if (asAnimGroup & 0xff)
    {
        stestGroup = asAnimGroup & 0x7f00;
        return ResolveAnimGroup(stestGroup, false);
    }
    return 0;
}
}  // namespace fnv_00495740

namespace fnv_004969b0 {
struct EBase
{
    int pad;
    virtual ~EBase();
};

struct KFModel;
struct KFP
{
    KFModel* p;
    ~KFP();
};
struct FUN_004969b0;
void __cdecl DetachObjectModels(FUN_004969b0*);
struct FUN_004969b0 : public EBase
{
    int eFlags;
    int eType;
    KFP m_kActorValueData;
    int m_iSectionIndex;
    NP pForwardSequence;
    int m_iSectionValues[2];
    NP m_kSectionEntries[2];
    ~FUN_004969b0();
};
// @fnv 0x004969b0
FUN_004969b0::~FUN_004969b0()
{
    DetachObjectModels(this);
}
}  // namespace fnv_004969b0

struct AnimationIdleStateAccess : public LocalAnimIdle
{
    void AnimIdle_Update(Animation*);
};

struct Flt
{
    operator unsigned int() const;
};
struct HA
{
    int GetAnimAction();
    void Actor_SetAnimAction(int, int);
};
// @fnv 0x00497040
// src: COMMUNITY 0x00497040
void AnimationIdleStateAccess::AnimIdle_Update(Animation* apAnimation)
{
    if (*(int*)((char*)this + 8) == 2)
    {
        if (!(unsigned int)*(Flt*)((char*)this + 0x18) ||
            ((unsigned int)*(Flt*)((char*)this + 0x18),
             ((NiControllerSequence*)(unsigned int)*(Flt*)((char*)this + 0x18))->GetState()) == 0)
        {
            *(int*)((char*)this + 8) = 3;
            if (*(HA**)((char*)this + 0x34) && (*(HA**)((char*)this + 0x34))->GetAnimAction() == 0xd)
                (*(HA**)((char*)this + 0x34))->Actor_SetAnimAction(-1, 0);
            if (*(int*)((char*)this + 0xc) == 2 || *(int*)((char*)this + 0xc) == 3)
            {
                if (apAnimation)
                    apAnimation->SpecialIdleFree(true, false);
            }
        }
    }
}

namespace fnv_0049bca0 {
struct FUN_0049bca0_shell : public Animation
{
    void Animation_UpdateBipOnly(float, AnimationVector*, bool);
};

struct FUN_00440460_S
{
    void NiAVObject_SetTranslate(const AnimationVector*);
};
struct FUN_004efe80_S
{
    void UpdateControllers();
};
struct Flt
{
    FUN_004efe80_S* Modelloader_GetReferencedThis(float, FUN_00440460_S*);
};
// @fnv 0x0049bca0
// src: XBOX_PDB 0x0049bca0
void FUN_0049bca0_shell::Animation_UpdateBipOnly(float afTime, AnimationVector* apTranslate, bool abControllers)
{
    if ((*(FUN_00440460_S**)((char*)this + 0xc)))
        (*(FUN_00440460_S**)((char*)this + 0xc))->NiAVObject_SetTranslate((AnimationVector*)((char*)this + 0x1c));
    ((Flt*)((char*)this + 8))->Modelloader_GetReferencedThis(afTime, (*(FUN_00440460_S**)((char*)this + 0xc)))->UpdateControllers();
    if ((*(FUN_00440460_S**)((char*)this + 0xc)))
    {
        if (apTranslate)
        {
            *apTranslate = *reinterpret_cast<AnimationVector*>(((TESDataHandler*)(*(FUN_00440460_S**)((char*)this + 0xc)))->GetTESEyesList());
        }
        (*(FUN_00440460_S**)((char*)this + 0xc))->NiAVObject_SetTranslate(&AnimationVector::ZERO);
    }
}
}  // namespace fnv_0049bca0

struct AnimSequenceBase;
struct MapItem
{
    MapItem* m_pkNext;
    unsigned short m_key;
    AnimSequenceBase* m_val;
};
struct MapBase
{
    virtual ~MapBase();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short k1, unsigned short k2);
    virtual void SetValue(MapItem* pkItem, unsigned short key, AnimSequenceBase* val);
    virtual void ClearValue(MapItem* pkItem);
    virtual MapItem* NewItem();
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    void SetOrInsert(unsigned short key, AnimSequenceBase* val);
};

// Looks up the key in the hash bucket; updates the existing item's value, or allocates a new item, inserts it at the bucket head and increments the count.
// @fnv 0x0049c170
void MapBase::SetOrInsert(unsigned short key, AnimSequenceBase* val)
{
    unsigned int uiIndex = this->KeyToHashIndex(key);
    MapItem* pkItem = this->m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (this->IsKeysEqual(key, pkItem->m_key))
        {
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = this->NewItem();
    this->SetValue(pkItem, key, val);
    pkItem->m_pkNext = this->m_ppkHashTable[uiIndex];
    this->m_ppkHashTable[uiIndex] = pkItem;
    this->m_uiCount++;
}

void __cdecl FinishScriptRunLock(void*);

// If the counter at p+0x10 is positive, calls FinishScriptRunLock on that field.
// @fnv 0x0043bac0
void __fastcall FinishScriptRunLockIfActive(void* p)
{
    if (*(int*)((char*)p + 0x10) > 0)
        FinishScriptRunLock((char*)p + 0x10);
}

extern float DAT_0101d890;

// @fnv 0x004954c0
void __fastcall SetNegatedGlobal(void* thisPtr)
{
    *(float*)((char*)thisPtr + 0x48) = -DAT_0101d890;
}

struct FUN_00497280_shell
{
    unsigned int fieldAt124;
    unsigned int GetFieldAt124();
};

// @fnv 0x00497280
unsigned int FUN_00497280_shell::GetFieldAt124()
{
    return *(unsigned int*)((char*)this + 0xDC);
}

extern NiFixedString* DAT_011c61bc;

// @fnv 0x00499b70
// src: XBOX_PDB 0x00499b70
NiFixedString* __cdecl FixedStrings_QMagicNode()
{
    return DAT_011c61bc;
}

extern NiFixedString* DAT_011c61c0;

// @fnv 0x00499b80
// src: COMMUNITY 0x00499b80
NiFixedString* __cdecl get_g_SpecialIdle_Cast()
{
    return DAT_011c61c0;
}

bool __fastcall _ref_008256d0(void* pThis);

struct FUN_00726070_standin
{
    FUN_00726070_standin* FUN_00726070();
};

// @fnv 0x0049bd30
int __fastcall GetListCount(void* pThis)
{
    int count = 0;
    if (!_ref_008256d0((char*)pThis + 0x104))
    {
        FUN_00726070_standin* list = (FUN_00726070_standin*)((char*)pThis + 0x104);
        while (list)
        {
            ++count;
            list = list->FUN_00726070();
        }
    }
    return count;
}


typedef char _sizecheck_NiRTTI[sizeof(NiRTTI) == 8 ? 1 : -1];



// @fnv 0x00653270
// src: XBOX_PDB 0x00653270
NiObject* __cdecl NiObject_DynamicCast(NiRTTI const* pkRTTI, NiObject* pkObject)
{
    if (!pkObject)
        return 0;
    return pkObject->DynamicCast(pkRTTI);
}

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct FileListNode
{
    const char** GetItem();
    AnimationList<const char*>* GetNext();
};
struct FUN_00490330_t : public Animation
{
    void Animation_AddSpecialAnimations(AnimationList<const char*>* apFileList, const char* apPath);
};

// Builds a path from apPath, "SpecialAnims" and each file name, loads the KF model and adds it as an animation.
// @fnv 0x00490330
// src: COMMUNITY 0x00490330
void FUN_00490330_t::Animation_AddSpecialAnimations(AnimationList<const char*>* apFileList, const char* apPath)
{
    AnimationList<const char*>* pfileList;
    if (!apFileList)
        return;
    pfileList = apFileList;
    while (pfileList)
    {
        KFModel* pkfModel;
        char message[260];
        const char* pfilename;
        bool bqueueAnims;
        pfilename = *((FileListNode*)pfileList)->GetItem();
        _sprintf_s(message, 260, "%s\\%s\\%s", apPath, "SpecialAnims", pfilename);
        pkfModel = g_modelLoader->LoadKF(message);
        bqueueAnims = IsAnimationLoaded();
        if (pkfModel)
            AddAnimation(pkfModel, bqueueAnims);
        pfileList = ((FileListNode*)pfileList)->GetNext();
    }
}

namespace fnv_004955c0 {
struct FUN_00496080_t
{
    void Animation_ClearGroup(int, float);
};
struct FUN_00494710_shell
{
    bool Animation_GroupLoaded(unsigned short);
};
struct SeqIface;
struct FUN_004948c0_shell
{
    SeqIface* Animation_StartGroup(SeqIface*, unsigned short, int);
};
struct FUN_004955c0_t : public Animation
{
    void Animation_ForceSection(int aeSequenceType, unsigned short ausGroup, int aeAction, float afTime, bool abFlag);
};

// @fnv 0x004955c0
// src: XBOX_PDB 0x004955c0
void FUN_004955c0_t::Animation_ForceSection(int aeSequenceType, unsigned short ausGroup, int aeAction, float afTime, bool abFlag)
{
    int iSlot = aeSequenceType;
    switch (iSlot)
    {
    case 0x14:
        iSlot = 1;
        break;
    case 0x15:
        iSlot = 4;
        break;
    }
    if (aeAction == -1)
    {
        ((FUN_00496080_t*)this)->Animation_ClearGroup(aeSequenceType, 0.0f);
        if (ausGroup != 0xff)
        {
            AnimSequenceBase* pAnimSeqBase;
            if (m_pOwnerReference->GetAt(ausGroup, pAnimSeqBase))
            {
                if (pAnimSeqBase->GetSequenceAtIndex(abFlag))
                {
                    m_pChildTile[iSlot] = pAnimSeqBase->GetSequenceAtIndex(abFlag);
                    ((NiControllerManager*)(NiControllerManager*)m_acReservedBytes)
                        ->ActivateControllerSequence(m_pChildTile[iSlot], 0, false, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
                }
            }
        }
    }
    else
    {
        if (((FUN_00494710_shell*)this)->Animation_GroupLoaded(ausGroup))
        {
            AnimSequenceBase* pBase;
            if (m_pOwnerReference->GetAt(ausGroup, pBase))
            {
                BSAnimGroupSequence* pSequence = pBase->GetSequenceAtIndex(abFlag);
                ((FUN_004948c0_shell*)this)->Animation_StartGroup((SeqIface*)pSequence, ausGroup, aeSequenceType);
            }
            action[iSlot] = (ANIM_GROUP_ACTION)aeAction;
        }
    }
    group[iSlot] = ausGroup;
    time = afTime;
}
}  // namespace fnv_004955c0


// No shared VATS.h exists; the global at 0x011f2250 and its command accessor at 0x009c71c0 identify VATS.
class VATS
{
  public:
    unsigned int GetFlags();
    void* GetTarget();
    int FUN_0044ddc0();
    float GetTargetUpdateMult();
};
extern VATS DAT_011f2250;
struct FUN_00498d30_t : public Animation
{
    bool HasIdleForm(TESIdleForm* apIdleForm);
};

// @fnv 0x00498d30
bool FUN_00498d30_t::HasIdleForm(TESIdleForm* apIdleForm)
{
    if (LocalInput && ((Script*)(LocalAnimIdle*)LocalInput)->GetText() == (void*)apIdleForm &&
        ((LocalAnimIdle*)LocalInput)->GetFlags() != 1)
        return true;
    if (LocalStateValue && ((Script*)(LocalAnimIdle*)LocalStateValue)->GetText() == (void*)apIdleForm &&
        ((LocalAnimIdle*)LocalStateValue)->GetFlags() != 1)
        return true;
    if (LocalOutput[0])
    {
        if (((Script*)(LocalAnimIdle*)LocalOutput[0])->GetText() == (void*)apIdleForm)
            return true;
        else if (DAT_011f2250.GetFlags() == 4 && ((LocalAnimIdle*)LocalOutput[0])->GetControllerSequence())
            return true;
    }
    if (LocalOutput[1])
    {
        if (((Script*)(LocalAnimIdle*)LocalOutput[1])->GetText() == (void*)apIdleForm)
            return true;
        else if (DAT_011f2250.GetFlags() == 4 && ((LocalAnimIdle*)LocalOutput[1])->GetControllerSequence())
            return true;
    }
    return false;
}

extern Setting g_011cfcec;

float __cdecl BSTimer_QGlobalTimeMultiplierTarget();
struct CameraShotHelper
{
    bool IsInitialized();
    float GetField4C();
};

// @fnv 0x009c8d60
// src: XBOX_PDB 0x009c8d60
float VATS::GetTargetUpdateMult()
{
    float fMultiplier = 1.0f;
    if (*(int*)((char*)this + 8) == 4)
    {
        if (*(CameraShotHelper**)((char*)this + 0x10) && !(*(CameraShotHelper**)((char*)this + 0x10))->IsInitialized())
            fMultiplier = 1.0f;
        else if (*(CameraShotHelper**)((char*)this + 0x10) &&
                 (*(CameraShotHelper**)((char*)this + 0x10))->GetField4C() > 0.0)
            fMultiplier = (*(CameraShotHelper**)((char*)this + 0x10))->GetField4C();
        else
            fMultiplier = *g_011cfcec.Float();
    }
    fMultiplier = BSTimer_QGlobalTimeMultiplierTarget() / hkpCharacterContext::GetReferenceTimeStep() * fMultiplier;
    return fMultiplier;
}

struct FUN_0048ef90_shell
{
    unsigned int __thiscall AnimSequenceSingle_GetSequenceToPlay(unsigned int dummy);
};

// @fnv 0x0048ef90
// src: COMMUNITY 0x0048ef90
unsigned int __thiscall FUN_0048ef90_shell::AnimSequenceSingle_GetSequenceToPlay(unsigned int dummy)
{
    return *(unsigned int*)((char*)this + 4);
}

struct FUN_0048efb0_shell
{
    char AnimSequenceSingle_GetSequenceIndex(int arg1);
};

// @fnv 0x0048efb0
// src: XBOX_PDB 0x0048efb0
char FUN_0048efb0_shell::AnimSequenceSingle_GetSequenceIndex(int arg1)
{
    return -1;
}

struct FUN_00493880_shell
{
    unsigned char m_flags;
    void SetFlag(bool set, unsigned char mask);
};

// Sets or clears the bits of m_flags selected by mask, according to set.
// @fnv 0x00493880
void FUN_00493880_shell::SetFlag(bool set, unsigned char mask)
{
    if (set)
        m_flags |= mask;
    else
        m_flags &= ~mask;
}

struct FUN_00493990_shell
{
    bool HasFlag(unsigned char aFlag);
};

// @fnv 0x00493990
bool FUN_00493990_shell::HasFlag(unsigned char aFlag)
{
    return (*reinterpret_cast<unsigned char*>(this) & aFlag) != 0;
}

namespace fnv_004939b0 {
struct ST_00493860
{
    void SetFlag(bool, int);
    void Animation_SetDelayUpdateScenegraph(bool argument0);
};

void ST_00493860::SetFlag(bool, int)
{}

// @fnv 0x004939b0
// src: XBOX_PDB 0x004939b0
void ST_00493860::Animation_SetDelayUpdateScenegraph(bool argument0)
{
    SetFlag(argument0, 2);
}
}  // namespace fnv_004939b0

struct FUN_00495560_shell
{
    int m_01c4;
    int GetFieldAt(int index);
};

// @fnv 0x00495560
int FUN_00495560_shell::GetFieldAt(int index)
{
    return *(int*)((char*)this + 0x1c4 + index * 4);
}



extern float DAT_0101d890;

// If abFlag is false, stores the negated DAT_0101d890 into the float at this+0x1c.
// @fnv 0x004964a0
void NiQuatTransform::SetScaleValid(bool abFlag)
{
    if (!abFlag)
        scale = -DAT_0101d890;
}



// @fnv 0x00496960
void AnimationActorOperations::SetByteAt14E(unsigned char value)
{
    *reinterpret_cast<unsigned char*>(&m_bThirdBooleanFlagAfterActorBase) = value;
}



struct FUN_004970e0_shell
{
    GO m_GO;
    void AssignGO(void* p);
};

// @fnv 0x004970e0
void FUN_004970e0_shell::AssignGO(void* apValue)
{
    ((GO*)((char*)this + 0x18))->operator=(apValue);
}

struct FUN_0049bd90_shell : KFModel
{
    void Animation_RemoveObject(void* a1);
};

struct FUN_004f05c0_shell
{
    void ApplyFlagsToEntries(void* a1);
};

void FUN_004f05c0_shell::ApplyFlagsToEntries(void* a1)
{}

// @fnv 0x0049bd90
// src: COMMUNITY 0x0049bd90
void FUN_0049bd90_shell::Animation_RemoveObject(void* a1)
{
    void* seq = GetControllerSequence();
    if (seq)
        ((FUN_004f05c0_shell*)seq)->ApplyFlagsToEntries(a1);
}



// This entry point calls slot 0x04 with the assignment signature.
// @fnv 0x0048f080
// src: XBOX_PDB 0x0048f080
bool AnimSequenceSingle::RemoveSequence(BSAnimGroupSequence* apSeq, bool abReleaseModelLoader)
{
    if (pForwardSequence == apSeq)
    {
        typedef void (__thiscall *AssignSlot)(AnimSequenceSingle*, BSAnimGroupSequence*, bool);
        reinterpret_cast<AssignSlot>((*reinterpret_cast<void***>(this))[1])(this, 0, abReleaseModelLoader);
        return true;
    }
    return false;
}

void __cdecl _Deallocate(void*);
// @fnv 0x0048f1d0
void* AnimSequenceMultiple::ScalarDeletingDestructor(unsigned int flags)
{
    this->~AnimSequenceMultiple();
    if (flags & 1)
        _Deallocate(this);
    return this;
}



void __cdecl _Deallocate(void*);
struct S48f370
{
    void ForwardCall_0054da00();
    void* FUN_0048f370(unsigned int);
};
// Calls FUN_0054da00 on this, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0048f370
void* S48f370::FUN_0048f370(unsigned int flags)
{
    this->ForwardCall_0054da00();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ThisStub
{
    void UpdateAnimationForRef(void* apRef);
    void Animation_UpdateSceneGraphNoController();
    void Animation_UpdateMovement(void* apRef);
};
// Calls UpdateAnimationForRef with apRef, then calls FUN_00493bd0.
// @fnv 0x00493900
// src: XBOX_PDB 0x00493900
void ThisStub::Animation_UpdateMovement(void* apRef)
{
    UpdateAnimationForRef(apRef);
    Animation_UpdateSceneGraphNoController();
}

struct C00493930
{
    bool Animation_GetDelayUpdateScenegraph();
    void Animation_SetDelayUpdateScenegraph(int);
    void Animation_UpdateSceneGraphNoController();
    bool Animation_UpdateQueuedScenegraph();
};
// If FUN_00493970 succeeds, calls FUN_00493bd0 and FUN_004939b0(0), then returns true; otherwise returns false.
// @fnv 0x00493930
// src: XBOX_PDB 0x00493930
bool C00493930::Animation_UpdateQueuedScenegraph()
{
    if (Animation_GetDelayUpdateScenegraph())
    {
        Animation_UpdateSceneGraphNoController();
        Animation_SetDelayUpdateScenegraph(0);
        return true;
    }
    return false;
}

extern float DAT_0101d890;

// If b is false, sets field0 to the negation of DAT_0101d890.
// @fnv 0x00496440
void NiQuatTransform::SetTranslateValid(bool b)
{
    if (!b)
        x = -DAT_0101d890;
}

struct Modifier
{
    void SetValue(float);
};
extern float DAT_0101d890;

// If flag is false, sets the modifier's value to the negation of DAT_0101d890.
// @fnv 0x00496470
void NiQuatTransform::SetRotateValid(bool flag)
{
    if (!flag)
        ((Modifier*)&qx)->SetValue(-DAT_0101d890);
}

struct EBase
{
    ~EBase();
};
void __cdecl _delete(void*, unsigned int);
struct FUN_004968e0_shell : EBase
{
    void* FUN_004968e0(unsigned int);
};
// Runs the base destructor, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004968e0
void* FUN_004968e0_shell::FUN_004968e0(unsigned int flags)
{
    this->EBase::~EBase();
    if (flags & 1)
        _delete(this, 8);
    return this;
}

namespace fnv_00498230 {
struct Flt
{
    operator unsigned int() const;
};

struct HA
{
    void Actor_SetAnimAction(int, void*);
};
bool __fastcall SpecialIdlePlay_0(void*);
struct Holder
{
    bool Animation_SpecialIdlePlay(void*);
};
// @fnv 0x00498230
// src: XBOX_PDB 0x00498230
bool Holder::Animation_SpecialIdlePlay(void* apActor)
{
    if (SpecialIdlePlay_0(this))
    {
        ((LowProcess*)(unsigned int)*(Flt*)((char*)this + 0x124))->LowProcess::SetCurrentBoundObject(static_cast<TESObject*>(apActor));
        ((HA*)apActor)
            ->Actor_SetAnimAction(0xD, ((LocalAnimIdle*)(unsigned int)*(Flt*)((char*)this + 0x124))->GetControllerSequence());
        return true;
    }
    return false;
}
}  // namespace fnv_00498230

namespace fnv_004985b0 {
struct Flt
{
    operator unsigned int() const;
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct FUN_004985b0_Owner
{
    bool IsFlaggedAsTwo();
};
// @fnv 0x004985b0
bool FUN_004985b0_Owner::IsFlaggedAsTwo()
{
    if ((unsigned int)*(Flt*)((char*)this + 0x124) == 0)
        return 0;
    return ((TESObjectREFR_GetFlags_Helper*)(unsigned int)*(Flt*)((char*)this + 0x124))->CallGetFlags() == 2;
}
}  // namespace fnv_004985b0

struct S_0049c050
{
    void NiTMapBase_NiTPointerAllocator_unsigned_int_unsigned_short_AnimSequenceBase_NiTMapBase(int);
    void* Construct(int);
};
extern int DAT_0101ded0;
// Calls FUN_0049c100 with a, stores the address of DAT_0101ded0 into this, and returns this.
// @fnv 0x0049c050
void* S_0049c050::Construct(int a)
{
    NiTMapBase_NiTPointerAllocator_unsigned_int_unsigned_short_AnimSequenceBase_NiTMapBase(a);
    *(void**)this = (void*)&DAT_0101ded0;
    return this;
}

void __cdecl _Deallocate(void*);
struct Holder_49c080
{
    void FUN_0049c510();
    void* FUN_0049c080(unsigned int);
};
// Calls FUN_0049c510, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0049c080
void* Holder_49c080::FUN_0049c080(unsigned int flags)
{
    FUN_0049c510();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct AnimationFormList
{
    void* Find(TESForm* const&, void*);
    TESForm* RemoveNode(void**);
    TESForm* FindOrSelf(TESForm* const&);
};
// @fnv 0x0049c0b0
TESForm* AnimationFormList::FindOrSelf(TESForm* const& form)
{
    void* ptr = Find(form, 0);
    return ptr ? RemoveNode(&ptr) : form;
}

struct FUN_004bc1f0_S
{
    void NiAVObject_SetTranslate_004bc1f0(float, float, float);
};
extern float const g_011da6a4_arg1;
struct S00739970
{
    unsigned char _pad[0x0DBC];
    FUN_004bc1f0_S* _p;
    void BlackJackMenu_SetSideHandVisibility(bool);
};
// Calls FUN_004bc1f0 on _p with zero x/y and a z of g_011da6a4_arg1 when b is false, or 0.0 when b is true.
// @fnv 0x00739970
// src: XBOX_PDB 0x00739970
void S00739970::BlackJackMenu_SetSideHandVisibility(bool b)
{
    if (!b)
    {
        _p->NiAVObject_SetTranslate_004bc1f0(0.0f, 0.0f, g_011da6a4_arg1);
    }
    else
    {
        _p->NiAVObject_SetTranslate_004bc1f0(0.0f, 0.0f, 0.0f);
    }
}

namespace fnv_00921e30 {
struct Flt
{
    operator unsigned int() const;
};
struct StandIn
{
    char _pad[0x124];
    Flt m_kHandle;
    BSAnimGroupSequence* Animation_GetSpecialIdleSequence();
};
// @fnv 0x00921e30
// src: XBOX_PDB 0x00921e30
BSAnimGroupSequence* StandIn::Animation_GetSpecialIdleSequence()
{
    return m_kHandle ? ((LocalAnimIdle*)(unsigned int)m_kHandle)->GetControllerSequence() : 0;
}
}  // namespace fnv_00921e30




// @fnv 0x004937c0
bool __fastcall IsAimAnimGroup(TESAnimGroup* group)
{
    return TESAnimGroup::IsAimAnimation(group->sType);
}


namespace fnv_004937e0 {


// @fnv 0x004937e0
bool __fastcall IsAnimGroupActionValid(TESAnimGroup* group)
{
    return TESAnimGroup::IsActionTypeValid(group->sType);
}
}  // namespace fnv_004937e0

namespace fnv_00493970 {
struct FUN_00493990_shell
{
    bool HasFlag(unsigned char);
    bool Animation_GetDelayUpdateScenegraph();
};

// @fnv 0x00493970
// src: XBOX_PDB 0x00493970
bool FUN_00493990_shell::Animation_GetDelayUpdateScenegraph()
{
    return HasFlag(2);
}
}  // namespace fnv_00493970

extern "C" void* _NiMalloc(unsigned int);
extern int DAT_0101def0;
struct FUN_0049c100_shell
{
    void* vft;
    int count;
    void* data;
    int unused;
    FUN_0049c100_shell* NiTMapBase_NiTPointerAllocator_unsigned_int_unsigned_short_AnimSequenceBase_NiTMapBase(int n);
};
// Sets the vtable, stores n in count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x0049c100
// src: EXE 0x0049c100
FUN_0049c100_shell* FUN_0049c100_shell::NiTMapBase_NiTPointerAllocator_unsigned_int_unsigned_short_AnimSequenceBase_NiTMapBase(int aiCount)
{
    vft = (void*)&DAT_0101def0;
    count = aiCount;
    unused = 0;
    unsigned int uiSize = count * 4;
    data = _NiMalloc(uiSize);
    memset(data, 0, count * 4);
    return this;
}

namespace fnv_00495d50 {
struct Flt
{
    unsigned char _d[0x18];
    operator unsigned int() const;
};
struct Holder_00495d50
{
    unsigned char _pad0[0xE];
    unsigned char f0E;
    unsigned char f0F;
    unsigned char _pad10[4];
    Flt* p14;
    unsigned int v18;
    unsigned int GetValueForIndex(unsigned char);
};
// Returns v18 when f0E is 1 and a equals f0F, otherwise converts p14[a] to unsigned int.
// @fnv 0x00495d50
unsigned int Holder_00495d50::GetValueForIndex(unsigned char a)
{
    if (f0E == 1 && a == f0F)
        return v18;
    return (unsigned int)p14[a];
}
}  // namespace fnv_00495d50

struct SeqHack
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual BSAnimGroupSequence* GetSeq(int);
};
struct GrpHack
{
    TESAnimGroup* FUN_0048f7f0();
};
struct HackAnim
{
    char _pad[0xdc];
    AnimationSequenceMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;
    TESAnimGroup* Animation_LookupGroup(unsigned short asGroup);
};
// Looks up the sequence for asGroup in the map and returns the anim group from its sequence, or null if not found.
// @fnv 0x00496500
// src: COMMUNITY 0x00496500
TESAnimGroup* HackAnim::Animation_LookupGroup(unsigned short asGroup)
{
    AnimSequenceBase* panimSeq;
    if (m_pOwnerReference->GetAt(asGroup, panimSeq))
    {
        return ((GrpHack*)((SeqHack*)panimSeq)->GetSeq(-1))->FUN_0048f7f0();
    }
    return 0;
}

struct FakeRef
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool Virt(int);
};
struct FakeAnim
{
    unsigned short __thiscall GetSerializedSize(void* apRef);
};
// Returns 2 plus the animation's size for apRef when apAnimation is set and apRef's Virt(0) check fails.
// @fnv 0x0049aa20
unsigned short GetAnimationSize(void* apRef, void* apAnimation)
{
    unsigned short usSize = 0;
    usSize += 2;
    if (apAnimation)
    {
        if (!((FakeRef*)apRef)->Virt(0))
        {
            usSize += ((FakeAnim*)apAnimation)->GetSerializedSize(apRef);
        }
    }
    return usSize;
}

namespace fnv_00490e60 {
struct FUN_00490e60_shell : public Animation
{
    bool ShouldQueueAnimations();
};

struct Flt
{
    operator unsigned int();
};
struct _FUN_00822510_Class
{
    bool operator==(int) const;
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
    int PlayerCharacter_GetInventory3D();
};
struct GlobalObject_0045cfe0
{
    int* Int();
};

struct AIThreadManager
{
    static TESObjectREFR* IsConditionMet();
};
// Exe 0x00490e60: unit-local Interface view; declarations and layout are preserved.
struct AnimationInterfaceView
{
    enum enumMenus
    {
        kMenu_Dummy = 0
    };
    static bool IsSaveLoadActive();
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct FUN_00451530_shell
{
    bool TES_CellTestRunning();
};
extern PC_00605d70* g_thePlayer;
extern GlobalObject_0045cfe0 g_011c5778;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern FUN_00451530_shell* g_TES;

// @fnv 0x00490e60
bool FUN_00490e60_shell::ShouldQueueAnimations()
{
    bool bqueueAnims = false;
    bqueueAnims = true;
    if (!g_thePlayer || !g_thePlayer->GetNode(false) || !*g_011c5778.Int())
    {
        bqueueAnims = false;
    }
    else if ((NiNode*)(unsigned int)*(Flt*)((char*)this + 8) == g_thePlayer->GetNode(false) ||
             (NiNode*)(unsigned int)*(Flt*)((char*)this + 8) == g_thePlayer->GetNode(true) ||
             *(const _FUN_00822510_Class*)((char*)this + 8) == g_thePlayer->PlayerCharacter_GetInventory3D())
    {
        if (!AnimationInterfaceView::IsMenuActive((AnimationInterfaceView::enumMenus)0x40c, 0))
            bqueueAnims = false;
    }
    else if (g_BGSSaveLoadGame->IsLoading())
    {
        bqueueAnims = false;
    }
    else if (*(TESObjectREFR**)((char*)this + 4) == AIThreadManager::IsConditionMet())
    {
        bqueueAnims = false;
    }
    else if (AnimationInterfaceView::IsSaveLoadActive())
    {
        bqueueAnims = false;
    }
    else if (g_TES->TES_CellTestRunning())
    {
        bqueueAnims = false;
    }
    return bqueueAnims;
}
}  // namespace fnv_00490e60

namespace fnv_0048f720 {
struct Flt
{
    operator unsigned int();
};
struct FUN_006317a0_struct
{
    int AddEight(int);
};
struct AnimationFormList
{
    void* DereferenceIfNotNull(void*);
};

}  // namespace fnv_0048f720

// Walks the sequence list from the head, returning the zero-based index of apSeq or -1 if it is not found.
// @fnv 0x0048f720
char AnimSequenceMultiple::ContainsSequence(BSAnimGroupSequence* apSeq)
{
    void* listIt = (void*)(unsigned int)*(fnv_0048f720::Flt*)m_pSingleSequence;
    char iIndex = 0;
    while (listIt)
    {
        BSAnimGroupSequence* pSequence =
            *(BSAnimGroupSequence**)((fnv_0048f720::FUN_006317a0_struct*)m_pSingleSequence)->AddEight((int)listIt);
        if (apSeq == pSequence)
            return iIndex;
        ++iIndex;
        listIt = ((fnv_0048f720::AnimationFormList*)m_pSingleSequence)->DereferenceIfNotNull(listIt);
    }
    return -1;
}


namespace fnv_00497100 {
struct Flt
{
    operator unsigned int();
};
struct FUN_004efb10_shell
{
    unsigned short GetSaveSize_004efb10();
};
struct FUN_00497100_shell
{
    unsigned short AnimIdle_GetSaveSize();
};
// Computes a size: sums 4+4+4+1, and if the field at offset 0x18 is nonzero adds its FUN_004efb10 result plus 1.
// @fnv 0x00497100
// src: COMMUNITY 0x00497100
unsigned short FUN_00497100_shell::AnimIdle_GetSaveSize()
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    v += 4;
    v += 1;
    if ((unsigned int)*(Flt*)((char*)this + 0x18))
        v += (unsigned short)(unsigned short)((FUN_004efb10_shell*)((unsigned int)*(Flt*)((char*)this + 0x18)))
                 ->GetSaveSize_004efb10() +
             1;
    return v;
}
}  // namespace fnv_00497100

namespace fnv_004981f0 {


struct Crime
{
    TESObjectREFR* GetTarget();
};

struct FUN_004981f0_shell
{
    bool Animation_SpecialIdleLoaded();
};

// Returns true if the GO at offset 0x124 is nonzero and its Crime target equals 1, otherwise false.
// @fnv 0x004981f0
// src: XBOX_PDB 0x004981f0
bool FUN_004981f0_shell::Animation_SpecialIdleLoaded()
{
    if (!((GO*)((char*)this + 0x124))->operator unsigned int())
        return false;
    return (unsigned int)((Crime*)((GO*)((char*)this + 0x124))->operator unsigned int())->GetTarget() == 1;
}
}  // namespace fnv_004981f0

// The shared base has no nontrivial destructor, so it cannot emit this cleanup region.
namespace fnv_0048f220 {
int __cdecl strcpy_s(char*, unsigned int, const char*);
struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
    void NiRefObject_DecRefCount();
};

struct FUN_0048ef40
{
    virtual ~FUN_0048ef40();
};

struct SeqNameList
{
    void* GetHeadPos();
    SeqObj*& GetAt(void* pos);
    void* GetNextPos(void* pos);
    ~SeqNameList();
};

struct FUN_0048f220 : public FUN_0048ef40
{
    SeqNameList* pList;
    virtual ~FUN_0048f220();
};

// Iterates the sequence name list, copies each entry's name, calls FUN_00401970 on it, passes the name to g_modelLoader->NewItem, then deletes the list.
// @fnv 0x0048f220
FUN_0048f220::~FUN_0048f220()
{
    if (pList)
    {
        void* pos = pList->GetHeadPos();
        while (pos)
        {
            SeqObj* pForwardSequence = pList->GetAt(pos);
            char acName[260];
            strcpy_s(acName, 260, pForwardSequence->GetName());
            pForwardSequence->NiRefObject_DecRefCount();
            ((ModelLoader*)g_modelLoader)->NewItem(acName);
            pos = pList->GetNextPos(pos);
        }
        delete pList;
    }
}
}  // namespace fnv_0048f220

struct S_00490400_Anim : public Animation
{
    bool ShouldQueueAnimations();
    void Animation_AddAnimationsFromList(AnimationList<const char*>* apFileList);
};

// Loads each path in the list as a KF model, adds it as an animation with a flag from ShouldQueueAnimations, then frees the paths and the list.
// @fnv 0x00490400
// src: XBOX_PDB 0x00490400
void S_00490400_Anim::Animation_AddAnimationsFromList(AnimationList<const char*>* apFileList)
{
    if (!apFileList)
        return;
    {
        AutoMemContext kContextX((MEM_CONTEXT)0x33, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x2ee);
        bool bFlag = this->ShouldQueueAnimations();
        while (!apFileList->IsEmpty())
        {
            const char* pcPath7 = apFileList->GetItem();
            KFModel* m_kModelObjectsItem = g_modelLoader->LoadKF(pcPath7);
            this->AddAnimation(m_kModelObjectsItem, bFlag);
            delete pcPath7;
            apFileList->RemoveHead();
        }
        delete apFileList;
    }
}

extern "C" int __cdecl _strnicmp(const char* pcA, const char* pcB, unsigned int ItemUpdateArray);
extern "C" int __cdecl tolower(int c);
unsigned int BSStringLength(const char* pcString);

// No shared NiTextKey.h exists; the 8-byte time/text record matches the Xbox type.
class NiTextKey
{
  public:
    float m_fTime;
    NiFixedString m_kText;
    const NiFixedString& GetText() const;
    float GetTime() const;
};

struct AnimSequenceStub
{
    int unk00[60];
    NiControllerSequence* m_pkSequence;
    char Animation_FindSwitchKey(float* pfTime);
};

// Scans the sequence's text keys for one starting with "a:" and returns the lowercased character after the prefix, optionally storing its time.
// @fnv 0x00495e40
// src: XBOX_PDB 0x00495e40
char AnimSequenceStub::Animation_FindSwitchKey(float* pfOutTime)
{
    const char* pcPrefixVal = "a:";
    if (!m_pkSequence)
        return 0;
    NiTextKeyExtraData* _pkTextKeys = m_pkSequence->GetName_00700300();
    unsigned int kUiNumKeys;
    NiTextKey* pkKeys6 = reinterpret_cast<NiTextKey*>(_pkTextKeys->GetKeys_00495f30(&kUiNumKeys));
    unsigned int uiPrefixLen = BSStringLength(pcPrefixVal);
    if (!uiPrefixLen)
        return 0;
    for (unsigned int i4 = 0; i4 < kUiNumKeys; i4++)
    {
        const char* pcText9 = pkKeys6[i4].GetText();
        if (pcText9 && !_strnicmp(pcText9, pcPrefixVal, uiPrefixLen))
        {
            if (pfOutTime)
                *pfOutTime = pkKeys6[i4].GetTime();
            return tolower(pcText9[uiPrefixLen]);
        }
    }
    return 0;
}


#include "../../include/NiPointer.h"
using ::NiPointer;

struct SaveLoadStub
{
    void Read(void* apData, unsigned int auiSize);
    void SetVersion(unsigned int auiVersion);
};
extern SaveLoadStub* g_TESSaveLoadGame;

unsigned short BSAnimGroupSequence_GetSequenceSaveSize();

struct AnimGroupStub
{
    unsigned int GetType();
};

struct GroupSeqStub
{
    AnimGroupStub* GetAnimGroup();
    void SetTime(float afTime);
};



struct SeqBaseStub
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual GroupSeqStub* GetSequenceAtIndex(int);
};

struct SeqMapStub
{
    bool GetAt(unsigned short key, SeqBaseStub*& result) const;
};

struct AnimStub
{
    bool AddAnimation(KFModel* apModel, bool abFlag);
    SeqMapStub* GetSequenceMap();
    void Animation_SkipNextBlend();
    GroupSeqStub* Animation_StartGroup(GroupSeqStub* apSeq, unsigned short asGroup, int aiFlag);
};

struct QueuedAnimStub
{
    int unk00;
    int unk04;
    int iState;
    int unk0C;
    NiPointer<KFModel> m_pRenderedNodeEntry;
    int unk14;
    NiPointer<GroupSeqStub> pListSequence;

    void LoadQueuedAnim(float afTime, AnimStub* apAnimation);
};

// @fnv 0x004972a0
void QueuedAnimStub::LoadQueuedAnim(float afTime, AnimStub* apAnimation)
{
    g_TESSaveLoadGame->Read(&iState, 4);
    g_TESSaveLoadGame->Read(&unk0C, 4);
    g_TESSaveLoadGame->Read(&unk14, 4);
    unsigned char bHasModel;
    g_TESSaveLoadGame->Read(&bHasModel, 1);
    if (bHasModel)
    {
        unsigned char cIndex;
        g_TESSaveLoadGame->Read(&cIndex, 1);
        if (apAnimation->AddAnimation(m_pRenderedNodeEntry, false))
        {
            if (iState == 2)
            {
                SeqBaseStub* pSeqBase;
                if (apAnimation->GetSequenceMap()->GetAt(((AnimGroupStub*)static_cast<KFModel*>(m_pRenderedNodeEntry)->GetControllerSequence())->GetType(),
                                                         pSeqBase))
                {
                    apAnimation->Animation_SkipNextBlend();
                    pListSequence =
                        apAnimation->Animation_StartGroup(pSeqBase->GetSequenceAtIndex(cIndex),
                                                  ((AnimGroupStub*)static_cast<KFModel*>(m_pRenderedNodeEntry)->GetControllerSequence())->GetType(), unk14);
                }
            }
            else if (iState == 0)
            {
                iState = 1;
            }
            else if (iState == 3)
            {
                SeqBaseStub* pSeqBase2 = 0;
                if (apAnimation->GetSequenceMap()->GetAt(((AnimGroupStub*)static_cast<KFModel*>(m_pRenderedNodeEntry)->GetControllerSequence())->GetType(),
                                                         pSeqBase2))
                {
                    pListSequence = pSeqBase2->GetSequenceAtIndex(cIndex);
                }
            }
        }
        if (pListSequence)
        {
            static_cast<GroupSeqStub*>(pListSequence)->SetTime(afTime);
        }
        g_TESSaveLoadGame->SetVersion(BSAnimGroupSequence_GetSequenceSaveSize());
    }
    else if (iState == 0)
    {
        iState = 1;
    }
}

struct ActiveManager
{
    unsigned char __thiscall TESSaveLoadGame_UseSaveGameBlocks();
    struct MessageInfo* __thiscall FUN_004fd3e0();
};
extern "C" ActiveManager* DAT_011de45c;
struct ParameterObject
{
    int __thiscall FUN_0055b980();
    unsigned short __thiscall AnimIdle_GetSaveSize();
};
struct StringManager
{
    const unsigned char* __thiscall FUN_00408d60();
};
extern "C" StringManager DAT_011de4e8;
struct MessageInfo
{
    int id;
    unsigned char kind;
};
struct MessageProvider
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual int GetDisplayValue();
};
extern "C" MessageProvider* __cdecl TESForm_GetFormByNumericID(int);
int __cdecl ProgramFlow(const char*, ...);
extern "C" const char DAT_01012cb0[];
extern "C" const char DAT_01012c78[];
extern "C" const char DAT_0101d930[];
// Computes a message size by summing fixed and variable field sizes, then logs the total with the message id and display value.
// @fnv 0x004974c0
unsigned short __cdecl GetMessageSize(void* unused, ParameterObject* param)
{
    unsigned short count = 0;
    unsigned short usInitialSize = count;
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        count += 4;
        count += 2;
    }
    count += 4;
    if (param != 0 && param->FUN_0055b980())
    {
        count += 2;
        count += param->AnimIdle_GetSaveSize();
    }
    if (*DAT_011de4e8.FUN_00408d60())
    {
        MessageInfo* message = DAT_011de45c->FUN_004fd3e0();
        if (message)
        {
            MessageProvider* provider = TESForm_GetFormByNumericID(message->id);
            ProgramFlow(DAT_01012cb0, count - usInitialSize, message->id, provider->GetDisplayValue(),
                         *(int*)((char*)message + 5), 0x11f3, DAT_0101d930);
        }
        else
        {
            ProgramFlow(DAT_01012c78, count - usInitialSize, 0x11f3, DAT_0101d930);
        }
    }
    return count;
}

struct FUN_0049bdc0_shell : Animation
{
    void SetAnimationAmount(float amount);
    void Animation_ClearGroup(int, float);
    void Animation_PlayGroup(unsigned short, int, int, int);
};
// @fnv 0x0049bdc0
void FUN_0049bdc0_shell::SetAnimationAmount(float amount)
{
    if (amount == 0.0)
    {
        if (m_pChildTile[3])
        {
            m_pChildTile[3]->Update(0.0f, true);
            Animation_ClearGroup(3, 0.0f);
        }
    }
    else
    {
        if (!m_pChildTile[3])
        {
            Animation_PlayGroup(0xe1, 1, -1, -1);
            if (m_pChildTile[3])
            {
                m_pChildTile[3]
                    ->Update(m_pChildTile[3]->NiPSysSpawnModifier_GetLifeSpan() + time, true);
            }
        }
        if (m_pChildTile[3] && m_pChildTile[3]->GetState() == 1)
        {
            float delta =
                m_pChildTile[3]->GetEndKeyTime_00508100() - m_pChildTile[3]->NiPSysSpawnModifier_GetLifeSpan();
            m_fTimeOffset = m_pChildTile[3]->NiPSysSpawnModifier_GetLifeSpan() + delta * amount;
            m_pChildTile[3]->SetSequenceTime(m_fTimeOffset - time, true);
        }
    }
}

struct Seq_48f3d0
{
    void NiRefObject_DecRefCount();
};
struct List_48f3d0
{
    void FindOrSelf(Seq_48f3d0* const& item);
    bool NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty();
    void* FUN_0048f370(int flags);
};
struct C48F3D0
{
    int unk00;
    List_48f3d0* pList;
    bool AnimSequenceMultiple_RemoveSequence(Seq_48f3d0* pForwardSequence, bool b);
};
// @fnv 0x0048f3d0
// src: XBOX_PDB 0x0048f3d0
bool C48F3D0::AnimSequenceMultiple_RemoveSequence(Seq_48f3d0* pItem, bool abUnused)
{
    pItem->NiRefObject_DecRefCount();
    pList->FindOrSelf(pItem);
    if (pList->NiTListBase_DFALL_NiTListItem_BSAnimGroupSequence_const_BSAnimGroupSequence_const_IsEmpty())
    {
        List_48f3d0* a = pList;
        List_48f3d0* p = a;
        p ? p->FUN_0048f370(1) : 0;
        pList = 0;
        return true;
    }
    return false;
}

struct BNFixedString
{
    operator const char*() const;
};

struct BNObject
{
    BNFixedString& GetName();
};

struct BNObjectList
{
    void* GetHeadPos();
    BNObject*& GetAt(void* apPos);
    void* GetNextPos(void* apPos);
};

extern "C" char* __cdecl strrchr(const char* apString, int aiChar);
void __cdecl BNStrcpy(char* apDest, const char* apSrc);
char* __cdecl BNStrcat(char* apDest, const char* apSrc);
char* __cdecl BNStrchr(char* apString, int aiChar);
int __cdecl BNStricmp(const char* apString1, const char* apString2);

struct BNLookup
{
    int unk00;
    BNObjectList* m_pObjectList;

    BNObject* FindObjectByNameVariant(BNObject* apObject, int aiVariant);
};

// @fnv 0x0048f500
BNObject* BNLookup::FindObjectByNameVariant(BNObject* apObject, int aiVariant)
{
    void* pPosVal = m_pObjectList->GetHeadPos();
    char* pName3 = strrchr(apObject->GetName(), '\\');
    char* pSuffix4;
    char acBufferX[260];

    if (!pName3)
        return 0;

    switch (aiVariant)
    {
    case 5:
        BNStrcpy(acBufferX, pName3);
        pSuffix4 = BNStrchr(acBufferX, '_');
        if (pSuffix4)
        {
            BNStrcpy(pSuffix4, "Up");
            pSuffix4 = BNStrchr(pName3, '_');
            BNStrcat(acBufferX, pSuffix4);
        }
        else
            BNStrcat(acBufferX, "Up");
        pName3 = acBufferX;
        break;
    case 6:
        BNStrcpy(acBufferX, pName3);
        pSuffix4 = BNStrchr(acBufferX, '_');
        if (pSuffix4)
        {
            BNStrcpy(pSuffix4, "Down");
            pSuffix4 = BNStrchr(pName3, '_');
            BNStrcat(acBufferX, pSuffix4);
        }
        else
            BNStrcat(acBufferX, "Down");
        pName3 = acBufferX;
        break;
    }

    while (pPosVal)
    {
        BNObject* pObject = m_pObjectList->GetAt(pPosVal);
        char* pObjectName = strrchr(pObject->GetName(), '\\');
        if (pObjectName && !BNStricmp(pObjectName, pName3))
            return pObject;
        pPosVal = m_pObjectList->GetNextPos(pPosVal);
    }
    return 0;
}

struct Group490
{
    int GetType();
    unsigned short GetCode();
};
struct Root490;

struct GroupPtr490
{
    Group490* value;
    GroupPtr490(Group490*);
    ~GroupPtr490();
    operator Group490*() const;
};
struct String490
{
    String490(const char*);
    ~String490();
    operator const char*() const;
    const char* value;
};
struct Root490
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual Root490* Find(const String490&);
    String490& GetName();
    int GetState();
    int GetKind();
};
struct Seq490 : Root490
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    Seq490(Group490*, Root490*);
    unsigned int GetCount();
    void GetTarget(unsigned int, char*);
    Group490* GetAnimGroup();
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
};
struct Base490
{
    virtual ~Base490();
    virtual void Set(Seq490*, bool);
    virtual bool Remove(Seq490*, bool);
    virtual bool IsSingle();
    virtual Seq490* Get(int);
};
struct Single490 : Base490
{
    Single490();
    Seq490* sequence;
};
struct Multiple490 : Base490
{
    Multiple490(Single490*);
    void* list;
};
struct Map490
{
    bool GetAt(unsigned short, Base490*&) const;
    void SetAt(unsigned short, Base490*);
    void Erase(unsigned short);
};
struct Manager490
{
    void Remove(Seq490*);
    bool Add(Seq490*, int*, bool);
    Root490* GetAccum();
};
struct ManagerPtr490
{
    Manager490* value;
    operator Manager490*() const;
};
struct RootPtr490
{
    Root490* value;
    operator Root490*() const;
};
struct Idle490
{
    Seq490* GetControllerSequence();
};
struct IdlePtr490
{
    Idle490* value;
    operator Idle490*() const;
};
struct List490
{
    void* head;
    void* tail;
    void AddTail(KFModel*&);
};
struct Context490
{
    int old;
    Context490(int, bool, const char*, int);
    ~Context490();
};
struct Info490
{
    unsigned char multiple;
    unsigned char u01;
    unsigned short u02;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
};
extern Info490 DAT_011977dc[];
extern int DAT_011c7d74;
extern int DAT_011f49e0;
extern const char DAT_0101d930[];
extern const char DAT_0101da38[];
extern const char DAT_0101d9a8[];
extern const char DAT_0101d970[];
void Warning490(const char*, ...);
bool Menu490(int, unsigned int);
bool Cast490(const void*, Root490*);
void Toggle490(bool);
struct Anim490
{
    int unk00;
    int unk04;
    RootPtr490 root;
    Root490* accum;
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
    unsigned short groups[8];
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
    ManagerPtr490 manager;
    Map490* map;
    Seq490* current[8];
    Seq490* last;
    List490 models;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    IdlePtr490 idle;
    IdlePtr490 queued;
    int unk134;
    void UpdateGroup(Group490*);
    bool AddModel(KFModel* model, bool queue);
};
// Adds a model's animation sequence to the manager, queuing it or replacing the current sequence for its group, with warnings on failure.
// @fnv 0x00490500
bool Anim490::AddModel(KFModel* model, bool queue)
{
    GroupPtr490 group(((Group490*)model->GetControllerSequence()));
    if (!(Group490*)group)
        return false;
    int groupTypeTmp = ((Group490*)group)->GetType();
    unsigned short code = ((Group490*)group)->GetCode();
    if (groupTypeTmp == 255)
    {
        if (model->GetRoot())
            Warning490(DAT_0101da38, (const char*)model->GetRoot()->GetName(), (const char*)*model);
        return false;
    }
    Context490 memContext(51, true, DAT_0101d930, 794);
    Base490* base = 0;
    if (!map->GetAt(code, base))
    {
        base = new Single490;
        map->SetAt(code, base);
    }
    if (base->IsSingle() && base->Get(-1))
    {
        if (DAT_011977dc[groupTypeTmp].multiple)
        {
            map->Erase(code);
            Single490* single = (Single490*)base;
            base = new Multiple490(single);
            map->SetAt(code, base);
        }
        else
        {
            if (base->Get(-1)->GetAnimGroup() == ((Group490*)model->GetControllerSequence()))
                return true;
            bool remove = true;
            if ((Idle490*)idle && ((Idle490*)idle)->GetControllerSequence() == base->Get(-1))
                remove = false;
            else if ((Idle490*)queued && ((Idle490*)queued)->GetControllerSequence() == base->Get(-1))
                remove = false;
            if (remove)
            {
                if (base->Get(-1) == last)
                    last = 0;
                ((Manager490*)manager)->Remove(base->Get(-1));
            }
            Seq490* old = base->Get(-1);
            if (old)
            {
                for (int index = 0; index < 8; index++)
                {
                    if (current[index] == old)
                    {
                        current[index] = 0;
                        groups[index] = 0;
                    }
                }
            }
            if (last && base->Get(-1) == last)
                last = 0;
            base->Set(0, true);
        }
    }
    if (queue && !Menu490(1036, 0) && groupTypeTmp != 23 && groupTypeTmp != 0 && groupTypeTmp != 224)
    {
        model->AcquireReference();
        models.AddTail(model);
    }
    else
    {
        Root490* original4 = model->GetRoot();
        if (groupTypeTmp >= 3 && groupTypeTmp <= 16 && original4->GetState() == 2)
        {
            map->Erase(code);
            delete base;
            return false;
        }
        Seq490* seq = 0;
        bool aCompatible = Cast490(&DAT_011c7d74, original4);
        if (aCompatible && original4->GetKind() == 1)
            seq = (Seq490*)original4;
        else
            seq = new Seq490(((Group490*)model->GetControllerSequence()), original4);
        base->Set(seq, true);
        bool added = ((Manager490*)manager)->Add(seq, &DAT_011f49e0, true);
        if (!added)
        {
            bool removed = false;
            Warning490(DAT_0101d9a8, (const char*)seq->GetName(), (const char*)((Root490*)root)->GetName());
            Toggle490(true);
            for (unsigned int target = 0; target < seq->GetCount(); target++)
            {
                char* name = 0;
                seq->GetTarget(target, name);
                if (!((Root490*)root)->Find(String490(name)))
                    Warning490(DAT_0101d970, name);
                delete name;
            }
            Toggle490(false);
            if (seq)
            {
                if (seq == last)
                    last = 0;
                ((Manager490*)manager)->Remove(seq);
                removed = base->Remove(seq, true);
            }
            if (base && removed)
            {
                map->Erase(code);
                delete base;
            }
            return false;
        }
        else
        {
            if (!accum)
                accum = ((Manager490*)manager)->GetAccum();
            UpdateGroup(((Group490*)model->GetControllerSequence()));
        }
    }
    return true;
}

typedef AnimationMotionVector AnimPoint3;

class IdleReplayDelayEntry
{
  public:
    TESIdleForm* m_pIdleForm;
    float m_fDelay;
};

struct AnimGroupInfoStub
{
    bool IsReloadStart();
    bool IsReloadLoop();
    float GetActionTime(int aiAction);
    bool HasMoveData();
    unsigned int GetGroupType();
    AnimPoint3 GetMoveVector();
    unsigned char GetSectionPriority(int aiSection);
    void UpdateSounds(TESObjectREFR* apRef, float afOldTime, float afNewTime, BSAnimGroupSequence* apSeq);
};

struct InterpStub
{
    void* GetInterpolator(int aiIndex);
};

struct SeqStub : public BSAnimGroupSequence
{
    AnimGroupInfoStub* GetAnimGroup() const;
    float GetLastTime(int aiUnused);
    void SetTime(float afTime);
    float GetEaseTime(float afTime);
    void* GetOwner();
    float GetEndKeyTime();
    float GetBeginKeyTime();
    void* GetInterpolator(int aiIndex);
    unsigned char GetPriority(const char* apName, unsigned int* apIndex);
};

struct BlendStub
{
    int GetHighPriority() const;
};

struct ControllerStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual BlendStub* GetInterpolator(int aiIndex);
};

struct AccumRootStub
{
    ControllerStub* GetController(const NiRTTI* apRTTI);
    const NiFixedString& GetName() const;
    bool IsCulled();
};

struct BoneStub
{
    const NiFixedString& GetName() const;
};

struct WeaponStub
{
    int GetWeaponType();
};



struct IdleStub
{
    BSAnimGroupSequence* GetIdleSequence();
    TESForm* GetIdleForm();
    int IsFinished();
    int GetIdleState();
    void SetIdleState(unsigned int auiState);
    void Update(Animation* apAnimation);
};

struct PlayerStub
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void QueueReloadGroup(unsigned short asGroup, bool abFlag);
    Animation* GetAnimationEx(bool abThirdPerson);
};

struct TimeGlobalStub
{
    float GetTimeMult();
};
struct IntSettingStub
{
    unsigned int* Int();
};
class GlobalObject_0044f440
{
  public:
    float* Float();
};
class GlobalObjectO2_00a7b610
{
};

struct TESAnimGroupActionEntry
{
    int iSequenceType;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

extern TimeGlobalStub g_timeGlobal;
extern IntSettingStub g_011c5778;
extern GlobalObject_0044f440 g_011c5724;
extern unsigned int DAT_011c56e8;
extern bool DAT_011e0783;
extern PlayerCharacter* g_thePlayer;
extern TESAnimGroupActionEntry DAT_011977e4[];
extern "C" const NiRTTI g_011f36ec;
extern GlobalObjectO2_00a7b610 g_011f36fc;
bool __fastcall IsWeaponReloadType(int aiType);
bool __cdecl IsVATSCameraActive();

struct FUN_00491180_shell : public Animation
{
    bool HasQueuedSequences();
    BSAnimGroupSequence* PlayGroupEx(unsigned short asGroup, int aeFlags, int aiLoops, int aeSection);
    BSAnimGroupSequence* GetSectionSequence(int aeSection);
    void* PlayNextGroup(unsigned short asGroup, int aiFlags);
    float GetSequenceTime(BSAnimGroupSequence* apSeq);
    void ResetMovement(bool abFlag);
    void ResetLoop();
    void UpdateAccumRoot(float afTime, AnimationVector* apTranslate, bool abFlag);
    void Animation_Update(TESObjectREFR* apRef, float afDelta, float afTime);
};

// Advances animation sequences, handles queued groups, reload actions, idle cleanup, movement accumulation and sound updates for the reference.
// @fnv 0x00491180
// src: XBOX_PDB 0x00491180
void FUN_00491180_shell::Animation_Update(TESObjectREFR* apRef, float afDelta, float afTime)
{
    float fTimeMultiplier = g_timeGlobal.GetTimeMult() * m_fEquipAnimationRate;
    if (HasQueuedSequences())
    {
        for (; DAT_011c56e8 < *g_011c5778.Int(); DAT_011c56e8++)
        {
            KFModel* m_kModelObjectsItem = kfModelList.GetItem();
            AddAnimation(m_kModelObjectsItem, false);
            FinishScriptRunLockIfActive(m_kModelObjectsItem);
            kfModelList.RemoveHead();
            if (!HasQueuedSequences())
                break;
        }
    }
    else if (m_usQueuedGroup != 0xff)
    {
        BSAnimGroupSequence* pWeaponSeq = m_pChildTile[4];
        switch (action[4])
        {
        case 1:
        case 2:
            if (pWeaponSeq && !((SeqStub*)pWeaponSeq)->GetAnimGroup()->IsReloadStart() &&
                ((SeqStub*)pWeaponSeq)->GetAnimGroup()->IsReloadLoop())
                break;
        case 3:
            if (((Actor*)m_pAttachedReference)->IsWeaponDrawn())
            {
                PlayGroupEx(m_usQueuedGroup, 1, -1, -1);
                if (apRef == g_thePlayer)
                    ((PlayerStub*)g_thePlayer)->QueueReloadGroup(m_usQueuedGroup, true);
                Actor* pReloader = (Actor*)apRef;
                bool bSpecial = false;
                if (pReloader->GetCurrentAIProcess())
                {
                    int iWeaponType =
                        pReloader->GetCurrentAIProcess()->GetActiveWeapon()
                            ? ((WeaponStub*)pReloader->GetCurrentAIProcess()->GetActiveWeapon())->GetWeaponType()
                            : 0;
                    if (IsWeaponReloadType(iWeaponType))
                        bSpecial = true;
                }
                if (bSpecial)
                    ((AnimationActorOperations*)pReloader)->SetAnimAction(0x11, m_pChildTile[4]);
                else
                    ((AnimationActorOperations*)pReloader)->SetAnimAction(9, m_pChildTile[4]);
            }
        default:
            m_usQueuedGroup = 0xff;
        }
    }

    if (!m_acTrailingData.IsEmpty())
    {
        AnimationList<IdleReplayDelayEntry*>* pNode = &m_acTrailingData;
        while (pNode)
        {
            IdleReplayDelayEntry* pDelay = pNode->GetItem();
            pDelay->m_fDelay = pDelay->m_fDelay - afDelta;
            if (pDelay->m_fDelay <= 0.0)
            {
                if (pNode == &m_acTrailingData)
                    pNode = 0;
                else
                    pNode = pNode->GetNext();
                m_acTrailingData.Remove(pDelay);
                delete pDelay;
                if (!pNode && !m_acTrailingData.IsEmpty())
                    pNode = &m_acTrailingData;
            }
            else
            {
                pNode = pNode->GetNext();
            }
        }
    }

    Actor* pRefActor = 0;
    if (apRef && apRef->IsActor())
        pRefActor = (Actor*)apRef;

    for (int iIdle = 0; iIdle < 2; iIdle++)
    {
        if (LocalOutput[iIdle])
        {
            if (((IdleStub*)(LocalAnimIdle*)LocalOutput[iIdle])->GetIdleSequence())
            {
                if (((IdleStub*)(LocalAnimIdle*)LocalOutput[iIdle])->GetIdleSequence()->GetState() == 1)
                {
                    Warning("'%s' is trying to free a special idle '%s' sequence '%s' that is animating.",
                            m_pAttachedReference->GetName(),
                            ((IdleStub*)(LocalAnimIdle*)LocalOutput[iIdle])->GetIdleForm()->GetName(),
                            (const char*)((IdleStub*)(LocalAnimIdle*)LocalOutput[iIdle])
                                ->GetIdleSequence()
                                ->GetName());
                    LocalOutput[iIdle] = 0;
                }
                else if (((IdleStub*)(LocalAnimIdle*)LocalOutput[iIdle])->GetIdleSequence()->GetState() == 0)
                {
                    AssignControllerManager(LocalOutput[iIdle]);
                }
            }
            else if (((IdleStub*)(LocalAnimIdle*)LocalOutput[iIdle])->IsFinished())
            {
                AssignControllerManager(LocalOutput[iIdle]);
            }
        }
    }

    if (!m_acHeaderData)
        return;

    ResetMovement(false);
    m_kNodeTranslation.x = 0.0f;
    m_kNodeTranslation.y = 0.0f;

    if (m_cState == 0x14)
    {
        float fTime = (afTime == -1.0) ? time : afTime;
        NiUpdateData kUpdData(fTime, false, false);
        ((NiNode*)m_acHeaderData)->Update(kUpdData);
        return;
    }

    float fTimeStep = afDelta;
    int iGroup = 0xff;
    int iNextGroupType;
    BSAnimGroupSequence* apSequences[8];
    bool bTalks;
    float afPrevTimes[8];
    int i;
    for (i = 0; i < 8; i++)
    {
        iGroup = GetType(group[i]);
        iNextGroupType = GetType(usReloadGroup[i]);
        if (iGroup == 0xff && iNextGroupType != 0xff)
        {
            m_acTargetName[i] = m_acAnimationName[i];
            PlayNextGroup(usReloadGroup[i], -1);
            usReloadGroup[i] = iNextGroupType = 0xff;
            iGroup = GetType(group[i]);
        }
        BSAnimGroupSequence* pForwardSequence = GetSectionSequence(i);
        apSequences[i] = pForwardSequence;
        afPrevTimes[i] = 0.0f;
        if (iGroup == 0xff || !pForwardSequence)
            continue;
        afPrevTimes[i] = ((SeqStub*)pForwardSequence)->GetEaseTime(time);
    }

    if (afTime != -1.0)
    {
        time = afTime;
        NiUpdateData kUpdateData(time, true, false);
        ((NiNode*)m_acHeaderData)->Update(kUpdateData);
        return;
    }

    fTimeStep = fTimeStep * m_fEquipAnimationRate;
    time = time + fTimeStep;

    for (i = 0; i < 8; i++)
    {
        SeqStub* pSequence = (SeqStub*)GetSectionSequence(i);
        bool bUpdate = true;
        iGroup = GetType(group[i]);
        iNextGroupType = GetType(usReloadGroup[i]);
        if (iGroup == 0xff || !pSequence)
            continue;
        if (i == 3)
            bUpdate = false;
        switch (m_cState)
        {
        case 0x17:
            if (i != 7 && i != 0)
                bUpdate = false;
            break;
        case 0x14:
            bUpdate = false;
            break;
        case 0x15:
            switch (i)
            {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                bUpdate = false;
            }
            break;
        case 4:
            switch (i)
            {
            case 4:
            case 5:
            case 6:
                bUpdate = false;
            }
            break;
        default:
            if (i == m_cState)
                bUpdate = false;
        }

        if (!bUpdate)
        {
            pSequence->SetTime(pSequence->GetLastTime(0) - fTimeStep);
        }
        else if (pSequence->GetState() == 1)
        {
            if (iGroup >= 3 && iGroup <= 0x10)
                pSequence->SetTime(pSequence->GetLastTime(0) + (fTimeStep * m_fMovementRate - fTimeStep));
            else if (iGroup == 0x18 || iGroup == 0x19)
                pSequence->SetTime(pSequence->GetLastTime(0) + (fTimeStep * m_fAnimationTimeScale - fTimeStep));
            else if (iGroup >= 0x18 && iGroup <= 0xa8)
                pSequence->SetTime(pSequence->GetLastTime(0) + (fTimeStep * m_fCombatAnimationRate - fTimeStep));
            else if (iGroup >= 0xb1 && iGroup <= 0xc7)
                pSequence->SetTime(pSequence->GetLastTime(0) + (fTimeStep * m_fReloadAnimationRate - fTimeStep));
        }

        if (bUpdate && pSequence->GetState() == 1)
        {
            switch (DAT_011977e4[iGroup].iSequenceType)
            {
            case 5:
                if (action[i] < 4 &&
                    GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 4 && GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(4))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        PlayNextGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 3:
            case 4:
            case 6:
            case 10:
                if (action[i] < 2 &&
                    GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 2 && GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(2))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        PlayNextGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                        if (pRefActor &&
                            (DAT_011977e4[iGroup].iSequenceType == 3 || DAT_011977e4[iGroup].iSequenceType == 4))
                        {
                            BaseProcess* pProcess = pRefActor->GetCurrentAIProcess();
                            if (pProcess)
                            {
                                if ((Actor*)pRefActor != (Actor*)g_thePlayer)
                                    pProcess->AddPostAnimAction((BaseProcess::PostAnimAction)0x4000);
                                else
                                    ((AnimationActorOperations*)pRefActor)->ClearQueuedAttack();
                            }
                        }
                    }
                }
                break;
            case 7:
                if (action[i] < 4 &&
                    GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 4 && GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(4))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        PlayNextGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 8:
                if (action[i] < 3 &&
                    GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 3 && GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(3))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        PlayNextGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 9:
                if (action[i] < 3 &&
                    GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 2 && pRefActor && pRefActor->GetCurrentAIProcess() &&
                    ((pRefActor->GetCurrentAIProcess()->GetSustainedFire() && pRefActor->GetAnimAction_008a7570() == 2) ||
                     (m_pAttachedReference == g_thePlayer && DAT_011f2250.GetFlags() == 4 &&
                      DAT_011f2250.GetTarget())) &&
                    pSequence->GetAnimGroup()->GetActionTime(2) >= afPrevTimes[i])
                {
                    float fLoopTime =
                        pSequence->GetAnimGroup()->GetActionTime(2) - pSequence->GetAnimGroup()->GetActionTime(1);
                    while (GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i]))
                    {
                        pSequence->SetTime(pSequence->GetLastTime(0) - fLoopTime);
                        afPrevTimes[i] = afPrevTimes[i] - fLoopTime;
                    }
                    action[i] = (ANIM_GROUP_ACTION)(action[i] - 1);
                }
                if (DAT_011e0783 && action[i] == 1 && pSequence->GetAnimGroup()->GetActionTime(2) >= afPrevTimes[i])
                {
                    float fLoopTime =
                        pSequence->GetAnimGroup()->GetActionTime(2) - pSequence->GetAnimGroup()->GetActionTime(1);
                    pSequence->SetTime(pSequence->GetLastTime(0) + fLoopTime);
                    afPrevTimes[i] = afPrevTimes[i] + fLoopTime;
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                }
                if (action[i] == 3 && GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(3))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        PlayNextGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 2:
                while (action[i] < 3 &&
                       GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i]))
                {
                    switch (action[i])
                    {
                    case 0:
                        action[i] = (ANIM_GROUP_ACTION)1;
                        break;
                    case 1:
                        action[i] = (ANIM_GROUP_ACTION)2;
                        break;
                    case 2:
                        action[i] = (ANIM_GROUP_ACTION)3;
                        break;
                    }
                }
                if (iNextGroupType != 0xff)
                {
                    if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(3))
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        PlayNextGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                }
                else if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(2) && m_acTargetName[i])
                {
                    ResetLoop();
                    action[i] = (ANIM_GROUP_ACTION)1;
                    float fLoopTime =
                        pSequence->GetAnimGroup()->GetActionTime(2) - pSequence->GetAnimGroup()->GetActionTime(1);
                    pSequence->SetTime(pSequence->GetLastTime(0) - fLoopTime);
                    afPrevTimes[i] = afPrevTimes[i] - fLoopTime;
                    if (m_acTargetName[i] != -1 && m_acTargetName[i] < 0xff)
                        m_acTargetName[i] = m_acTargetName[i] - 1;
                }
                else if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(3))
                {
                    if (((IdleStub*)(LocalAnimIdle*)LocalInput)->GetIdleState() == 1)
                        ((IdleStub*)(LocalAnimIdle*)LocalInput)->SetIdleState(3);
                    else
                        BlendOut(i, false);
                }
                break;
            case 0:
            case 1:
                if (!pSequence->GetOwner())
                {
                    while (action[i] < 1 &&
                           GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i]))
                    {
                        switch (action[i])
                        {
                        case 0:
                            action[i] = (ANIM_GROUP_ACTION)1;
                            break;
                        case 1:
                            action[i] = (ANIM_GROUP_ACTION)1;
                            break;
                        }
                    }
                    if (iNextGroupType != 0xff)
                    {
                        if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(1))
                        {
                            m_acTargetName[i] = m_acAnimationName[i];
                            PlayNextGroup(usReloadGroup[i], -1);
                            usReloadGroup[i] = iNextGroupType = 0xff;
                        }
                    }
                    else if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(1) && m_acTargetName[i])
                    {
                        action[i] = (ANIM_GROUP_ACTION)0;
                        float fLoopTime = pSequence->GetEndKeyTime() - pSequence->GetBeginKeyTime();
                        pSequence->SetTime(pSequence->GetLastTime(0) - fLoopTime);
                        if (m_acTargetName[i] != -1)
                            m_acTargetName[i] = m_acTargetName[i] - 1;
                    }
                    else if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(1))
                    {
                        BlendOut(i, false);
                    }
                }
                else
                {
                    if (action[i] == 0 &&
                        GetSequenceTime(pSequence) > pSequence->GetAnimGroup()->GetActionTime(action[i]))
                        action[i] = (ANIM_GROUP_ACTION)1;
                    if (iNextGroupType != 0xff)
                    {
                        if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(1))
                        {
                            if (i != 1 || (pRefActor->GetActorStateFlags() & 0xf))
                            {
                                m_acTargetName[i] = m_acAnimationName[i];
                                PlayNextGroup(usReloadGroup[i], -1);
                            }
                            else
                            {
                                BlendOut(i, false);
                            }
                            usReloadGroup[i] = iNextGroupType = 0xff;
                        }
                    }
                    else if (GetSequenceTime(pSequence) >= pSequence->GetAnimGroup()->GetActionTime(1))
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            }
        }
    }

    if (m_pObjectNode)
    {
        AnimPoint3 kOld = (AnimPoint3&)m_kRootTranslation;
        bool bUseMoveData = false;
        AnimPoint3 kMoveDelta = (const AnimPoint3&)AnimationVector::ZERO;
        if (pRefActor->IsMoving_004938e0())
        {
            unsigned short usMoveFlags = (unsigned short)pRefActor->GetActorStateFlags();
            if (m_pChildTile[1] && (usMoveFlags & 0xf))
            {
                int iType = 0;
                if (((SeqStub*)m_pChildTile[1])->GetAnimGroup()->HasMoveData())
                    bUseMoveData = true;
                switch (((SeqStub*)m_pChildTile[1])->GetAnimGroup()->GetGroupType())
                {
                case 0xe3:
                    bUseMoveData = true;
                    break;
                default:
                    switch (m_pChildTile[1]->GetState())
                    {
                    case 2:
                    case 5:
                        bUseMoveData = true;
                    }
                }
                ControllerStub* pController = ((AccumRootStub*)m_pObjectNode)->GetController(&g_011f36ec);
                ControllerStub* pMgr = pController;
                BlendStub* pBlendInterpolator = pMgr->GetInterpolator(0);
                if (pBlendInterpolator)
                {
                    BlendStub* pBlend = pBlendInterpolator;
                    if (pBlend)
                    {
                        int iHighPriority = pBlend->GetHighPriority();
                        void* pSeqInterp = ((SeqStub*)m_pChildTile[1])->GetInterpolator(0);
                        pBlend = (BlendStub*)NiObject_DynamicCast((const NiRTTI*)&g_011f36fc, (NiObject*)pSeqInterp);
                        if (((SeqStub*)m_pChildTile[1])->GetPriority(((AccumRootStub*)m_pObjectNode)->GetName(), 0) <
                            iHighPriority)
                            bUseMoveData = false;
                    }
                }
                if (bUseMoveData)
                {
                    if (usMoveFlags & 0x200)
                    {
                        if (usMoveFlags & 1)
                            iType = 7;
                        else if (usMoveFlags & 2)
                            iType = 8;
                        else if (usMoveFlags & 4)
                            iType = 9;
                        else if (usMoveFlags & 8)
                            iType = 10;
                    }
                    else if (usMoveFlags & 0xff00)
                    {
                        if (usMoveFlags & 1)
                            iType = 3;
                        else if (usMoveFlags & 2)
                            iType = 4;
                        else if (usMoveFlags & 4)
                            iType = 5;
                        else if (usMoveFlags & 8)
                            iType = 6;
                    }
                    if (iType == ((SeqStub*)m_pChildTile[1])->GetAnimGroup()->GetGroupType())
                    {
                        kMoveDelta = ((SeqStub*)m_pChildTile[1])->GetAnimGroup()->GetMoveVector() *
                                     fTimeMultiplier * *g_011c5724.Float() * m_fMovementRate;
                    }
                    else
                    {
                        unsigned short usMoveGroup = pRefActor->Actor_GetAnimGroup(iType, 0, 0, 0);
                        iType = GetType(usMoveGroup);
                        if (iType)
                        {
                            AnimSequenceBase* pSeqBase;
                            if (m_pOwnerReference->GetAt(usMoveGroup, pSeqBase))
                            {
                                SeqStub* pMoveSeq = (SeqStub*)pSeqBase->GetSequenceAtIndex(-1);
                                if (pMoveSeq)
                                    kMoveDelta = pMoveSeq->GetAnimGroup()->GetMoveVector() * fTimeMultiplier *
                                                 *g_011c5724.Float() * m_fMovementRate;
                            }
                        }
                    }
                }
            }
        }
        UpdateAccumRoot(time, &m_kRootTranslation, true);
        if (bUseMoveData)
        {
            m_kNodeTranslation.x = kMoveDelta.x;
            m_kNodeTranslation.y = kMoveDelta.y;
        }
        else
        {
            AnimPoint3 kTranslateDelta = (AnimPoint3&)m_kRootTranslation - kOld;
            m_kNodeTranslation.x = kTranslateDelta.x;
            m_kNodeTranslation.y = kTranslateDelta.y;
        }
        m_kNodeTranslation.x = ((Actor*)apRef)->TESObjectREFR_GetScale_00567400() * m_kNodeTranslation.x;
        m_kNodeTranslation.y = ((Actor*)apRef)->TESObjectREFR_GetScale_00567400() * m_kNodeTranslation.y;
        if (!bUseMoveData && !m_pChildTile[1] && m_pCurrentSequence && m_pCurrentSequence->GetState())
        {
            m_kNodeTranslation.y = 0.0f;
            m_kNodeTranslation.x = 0.0f;
        }
        if (m_pCurrentSequence && !m_pCurrentSequence->GetState())
            m_pCurrentSequence = 0;
    }

    bTalks = false;
    if (pRefActor && pRefActor->GetCurrentAIProcess())
        bTalks = pRefActor->GetCurrentAIProcess()->IsDetectionEnabled();
    if (!bTalks)
    {
        if (!((AccumRootStub*)(NiNode*)m_acHeaderData)->IsCulled() ||
            (this == ((PlayerStub*)g_thePlayer)->GetAnimationEx(true) && IsVATSCameraActive()))
        {
            for (i = 0; i < 8; i++)
            {
                switch (m_cState)
                {
                case 0x17:
                    if (i != 7 && i != 0)
                        continue;
                    break;
                case 0x14:
                    continue;
                    break;
                case 0x15:
                    switch (i)
                    {
                    case 2:
                    case 3:
                    case 4:
                        continue;
                    }
                    break;
                default:
                    if (i == m_cState)
                        continue;
                }
                SeqStub* pForwardSequence = (SeqStub*)GetSectionSequence(i);
                if (pForwardSequence && apSequences[i] == pForwardSequence &&
                    (pForwardSequence->GetState() == 1 || pForwardSequence->GetState() == 2 || pForwardSequence->GetState() == 5))
                {
                    bool bPlaySounds = true;
                    if (DAT_01199bcc[i])
                    {
                        if (m_acNodeName[i])
                        {
                            BSAnimGroupSequence* pBest = 0;
                            unsigned char ucMaxPriority = 0;
                            for (int iSection = 0; iSection < 8; iSection++)
                            {
                                if (m_pChildTile[iSection] && m_acNodeName[i] &&
                                    (const char*)((BoneStub*)m_acNodeName[i])->GetName())
                                {
                                    unsigned char ucPriority =
                                        ((SeqStub*)m_pChildTile[iSection])->GetAnimGroup()->GetSectionPriority(i);
                                    if (ucPriority > ucMaxPriority)
                                    {
                                        pBest = m_pChildTile[iSection];
                                        ucMaxPriority = ucPriority;
                                    }
                                }
                            }
                            if (!pBest || pBest != pForwardSequence)
                                bPlaySounds = false;
                        }
                    }
                    else
                    {
                        bPlaySounds = false;
                    }
                    if (bPlaySounds)
                    {
                        float fNewTime = pForwardSequence->GetEaseTime(time);
                        if (-DAT_0101d890 != fNewTime && -DAT_0101d890 != afPrevTimes[i] && fNewTime != afPrevTimes[i])
                            pForwardSequence->GetAnimGroup()->UpdateSounds(apRef, afPrevTimes[i], fNewTime, pForwardSequence);
                    }
                }
            }
        }
    }

    if (LocalInput)
        ((IdleStub*)(LocalAnimIdle*)LocalInput)->Update(this);
    if (m_cSkipNextBlend)
        m_cSkipNextBlend = 0;
    m_cState = -1;
}

struct AnimRoot3D
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
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void UpdateNode(NiUpdateData&, unsigned int);
    NiTimeController* GetControllers() const;
    void SetControllers(NiTimeController*);
};
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011c3ea4;
extern char DAT_011e07a8;

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

struct AnimSwap
{
    int unk00;
    int unk04;
    AnimationPointer<AnimRoot3D> m_pRootNode;
    AnimRoot3D* pOther;
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
    float fTime;
    bool Animation_GetDelayUpdateScenegraph();
    void Animation_SetDelayUpdateScenegraph(int);
    void Animation_UpdateSceneGraphNoController();
};

// If both animation roots exist, temporarily detaches their controllers, updates the first node with fTime, then restores the controllers.
// @fnv 0x00493bd0
// src: XBOX_PDB 0x00493bd0
void AnimSwap::Animation_UpdateSceneGraphNoController()
{
    if (!m_pRootNode || !pOther)
        return;
    if (*g_011c3ea4.Int() > 1 && !DAT_011e07a8 && !Animation_GetDelayUpdateScenegraph() && !g_BGSSaveLoadGame->IsLoading())
    {
        Animation_SetDelayUpdateScenegraph(1);
        return;
    }
    NiUpdateData kUpdate(fTime, true, false);
    AnimationPointer<NiTimeController> spCtrlA(m_pRootNode->GetControllers());
    AnimationPointer<NiTimeController> spCtrlB2(pOther->GetControllers());
    m_pRootNode->SetControllers(0);
    pOther->SetControllers(0);
    m_pRootNode->UpdateNode(kUpdate, 0);
    m_pRootNode->SetControllers(spCtrlA);
    pOther->SetControllers(spCtrlB2);
}

namespace AnimationBlend {
struct BlendAnimation;
struct BlendSequence;
struct BlendString
{
    const char* FUN_0043b1b0();
};
struct BlendObject
{
    BlendString* FUN_00413f40();
};
struct BlendGroup
{
    int FUN_005f2420();
    signed char IsUnk28Set();
    unsigned char GetMaxByte();
    unsigned char GetMaxOfTwoBytes();
    int GetMoveAnimGroup();
};
struct BlendGroupPtr
{
    BlendGroup* value;
    BlendGroupPtr(BlendGroup*);
    ~BlendGroupPtr();
    BlendGroup* Modelloader_GetReferencedThis();
};
struct BlendNodePtr
{
    BlendObject* value;
    BlendObject* Modelloader_GetReferencedThis();
    bool FUN_00822510(BlendObject*);
};
struct BlendSequence
{
    BlendString* FUN_00413f40();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void Deactivate(float, int);
    int FUN_008041a0();
    float GetFloatAtOffset1C();
    void NiControllerSequence_SetSequenceWeight(float);
    void* FUN_0059bb30();
    void SetNegatedGlobal();
    BlendGroup* FUN_0048f7f0();
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    bool CanSyncTo(BlendSequence*);
    void SetPhase(float, int);
};
struct BlendProcess
{
    int FUN_0045cd60();
    BlendSequence* GetFieldAt(int);
};
struct BlendRagdoll
{
    bool bhkRagdollController_GetsFootIKActive();
    void UpdateBoneLocalTransforms();
};
struct BlendActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
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
    BlendRagdoll* ragdoll;
    BlendAnimation* FUN_00950a60(int);
    BlendProcess* FUN_008d8520();
    BlendObject* PlayerCharacter_Get3D_00950bb0(int);
    BlendObject* PlayerCharacter_GetInventory3D();
};
struct BlendManager
{
    void FUN_0047aab0(BlendSequence*, int, int, float, float, int);
    void CallFUN_00a351d0(BlendSequence*, BlendSequence*, float, int, float, float);
    bool NiControllerManager_CrossFade(BlendSequence*, BlendSequence*, float, int, int, float, int);
    void NiControllerManager_BlendFromPose(BlendSequence*, float, float, int, int);
    void FUN_0047b220(BlendSequence*, float);
};
struct BlendManagerPtr
{
    BlendManager* value;
    BlendManager* Modelloader_GetReferencedThis();
};
struct BlendSettings
{
    const float* Setting_Float_00403e20();
};
extern BlendSettings DAT_011c56fc, DAT_011c5740, DAT_011c5724;
struct BlendGame
{
    bool FUN_0047c850();
};
extern BlendGame* DAT_011de45c;
extern VATS DAT_011f2250;
struct BlendMain
{
    bool TES_CellTestRunning();
};
extern BlendMain* DAT_011dea10;
extern BlendActor* DAT_011dea3c;
extern const double DAT_0101db88, DAT_01011588, DAT_01016408;
extern const float DAT_01016248;
extern const char DAT_0101dc58[], DAT_0101dbe8[], DAT_0101db90[];
struct BlendGroupInfo
{
    int section, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
extern BlendGroupInfo DAT_011977e0[];
int FUN_005f2440(unsigned short);
bool FUN_005f2630(unsigned short);
bool FUN_005f2540(unsigned short);
bool Interface_IsInMenuMode();
bool Interface_IsInPipboyMenu();
bool Interface_IsMenuIDVisible(int, int);
bool bhkRagdollController_QFootIK();
void Warning_005b5e40(const char*, ...);
struct BlendAnimation
{
    int unk00;
    BlendActor* actor;
    BlendNodePtr node;
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
    unsigned short groups[8];
    int flags[8];
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
    BlendManagerPtr manager;
    int unkdc;
    BlendSequence* sequences[16];
    signed char force;
    bool FUN_00498ea0(BlendSequence*);
    void Animation_ClearGroup(int, float);
    BlendSequence* Animation_StartGroup(BlendSequence*, unsigned short, int);
};
// @fnv 0x004949a0
// src: XBOX_PDB 0x004949a0
BlendSequence* BlendAnimation::Animation_StartGroup(BlendSequence* apSequence, unsigned short group, int aiRequestedSection)
{
    if (FUN_00498ea0(apSequence))
        return 0;
    int type4 = FUN_005f2440(group);
    int section3 = aiRequestedSection;
    BlendActor* owner2 = actor;
    if (section3 == -1)
        section3 = DAT_011977e0[type4].section;
    int originalSection = section3;
    switch (section3)
    {
    case 20:
        section3 = 1;
        break;
    case 21:
        section3 = 4;
        break;
    }
    BlendSequence* previous2 = sequences[section3];
    int previousType = FUN_005f2440(groups[section3]);
    bool synchronize = false;
    int state = 0;
    if (previous2)
        state = previous2->FUN_008041a0();
    if (!apSequence || group == 255)
        return 0;
    if (apSequence)
    {
        if (section3 == 4 || section3 == 5 || section3 == 6)
        {
            if (actor == DAT_011dea3c && this == DAT_011dea3c->FUN_00950a60(1))
            {
                apSequence->NiControllerSequence_SetSequenceWeight(section3 == 4 ? 1.0f : 0.0f);
            }
            else
            {
                BlendProcess* process = actor->FUN_008d8520();
                bool reset = true;
                if ((FUN_005f2630((unsigned short)type4) || FUN_005f2540((unsigned short)type4)) && process &&
                    process->FUN_0045cd60() <= 1)
                {
                    BlendProcess* highProcess = process;
                    BlendSequence* priorA = highProcess->GetFieldAt(section3 - 4);
                    if (priorA)
                    {
                        apSequence->NiControllerSequence_SetSequenceWeight(priorA->GetFloatAtOffset1C());
                        reset = false;
                    }
                }
                if (reset && (section3 == 5 || section3 == 6))
                    apSequence->NiControllerSequence_SetSequenceWeight(0.0f);
            }
        }
        if (apSequence->FUN_008041a0() == 3)
            apSequence->Deactivate(0.0f, 0);
        if (((apSequence->FUN_008041a0() != 0 && !apSequence->FUN_0059bb30()) ||
             (apSequence->FUN_008041a0() == 1 && apSequence == previous2)) &&
            (!Interface_IsInMenuMode() || apSequence->FUN_008041a0() == 1))
        {
            flags[section3] = 0;
            apSequence->SetNegatedGlobal();
            return apSequence;
        }
        if (Interface_IsInMenuMode() && node.Modelloader_GetReferencedThis() == DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(0) && !DAT_011de45c->FUN_0047c850() &&
            !DAT_011f2250.FUN_0044ddc0())
        {
        }
        else if (Interface_IsInPipboyMenu() && node.Modelloader_GetReferencedThis() == DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(1) && type4 == 1 &&
                 aiRequestedSection == 0 && previous2)
        {
            Animation_ClearGroup(originalSection, 0.0f);
            previous2 = 0;
            force = 1;
        }
        else if (previous2 && section3 == 2)
        {
            int priorType = previous2->FUN_0048f7f0()->FUN_005f2420();
            if (type4 == 226 || (type4 == 240 && priorType >= 230 && priorType <= 235))
            {
                Animation_ClearGroup(originalSection, 0.0f);
                previous2 = 0;
            }
        }
        else if (state && previous2)
        {
            if (state != 1)
            {
                if (actor != DAT_011dea3c && section3 == 1)
                    return 0;
                Animation_ClearGroup(originalSection, 0.0f);
                previous2 = 0;
            }
            else if (originalSection != section3 || force || apSequence->FUN_008041a0() != 0)
            {
                Animation_ClearGroup(originalSection, 0.0f);
            }
            else if (originalSection == 4 && (type4 <= 25 || type4 > 212) && !FUN_005f2630((unsigned short)type4))
            {
                Animation_ClearGroup(5, 0.0f);
                Animation_ClearGroup(6, 0.0f);
            }
        }
        groups[section3] = group;
        sequences[section3] = apSequence;
        if ((!Interface_IsInMenuMode() || node.Modelloader_GetReferencedThis() != DAT_011dea3c->PlayerCharacter_Get3D_00950bb0(0)) && apSequence && previous2)
        {
            BlendGroupPtr newGroup3(apSequence->FUN_0048f7f0());
            BlendGroupPtr oldGroup(previous2->FUN_0048f7f0());
            if (oldGroup.Modelloader_GetReferencedThis()->IsUnk28Set() &&
                oldGroup.Modelloader_GetReferencedThis()->IsUnk28Set() == newGroup3.Modelloader_GetReferencedThis()->IsUnk28Set())
            {
                if (previous2->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == apSequence->GetHavokWorldObjectCountInSceneGraph_0084e3a0())
                {
                    if (apSequence->CanSyncTo(previous2))
                        synchronize = true;
                    else
                        Warning_005b5e40(DAT_0101dc58, previous2->FUN_00413f40()->FUN_0043b1b0(),
                                     apSequence->FUN_00413f40()->FUN_0043b1b0(),
                                     node.Modelloader_GetReferencedThis()->FUN_00413f40()->FUN_0043b1b0());
                }
                else
                    Warning_005b5e40(DAT_0101dbe8, previous2->FUN_00413f40()->FUN_0043b1b0(), previous2->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                                 apSequence->FUN_00413f40()->FUN_0043b1b0(), apSequence->GetHavokWorldObjectCountInSceneGraph_0084e3a0(),
                                 node.Modelloader_GetReferencedThis()->FUN_00413f40()->FUN_0043b1b0());
            }
            if (synchronize && apSequence == previous2)
            {
                Warning_005b5e40(DAT_0101db90, previous2->FUN_00413f40()->FUN_0043b1b0(),
                             node.Modelloader_GetReferencedThis()->FUN_00413f40()->FUN_0043b1b0());
                synchronize = false;
            }
        }
        float duration = *DAT_011c56fc.Setting_Float_00403e20();
        unsigned char priority = 0;
        if (previous2)
            priority = previous2->FUN_0048f7f0()->GetMaxByte();
        if (apSequence->FUN_0048f7f0()->GetMaxOfTwoBytes() > priority)
            priority = apSequence->FUN_0048f7f0()->GetMaxOfTwoBytes();
        if (priority)
            duration = priority / DAT_0101db88;
        if ((Interface_IsInMenuMode() && node.FUN_00822510(DAT_011dea3c->PlayerCharacter_GetInventory3D())) || Interface_IsMenuIDVisible(1036, 0))
            duration = *DAT_011c5740.Setting_Float_00403e20();
        if (type4 >= 177 && type4 <= 199 && previous2 && owner2 != DAT_011dea3c && duration < DAT_01011588)
        {
            switch (apSequence->FUN_0048f7f0()->GetMoveAnimGroup())
            {
            case 1:
                if (previous2->FUN_0048f7f0()->GetMoveAnimGroup() != 1)
                    duration = DAT_01016248;
                break;
            default:
                if (previous2->FUN_0048f7f0()->GetMoveAnimGroup() == 1)
                    duration = DAT_01016248;
                break;
            }
        }
        if (FUN_005f2540((unsigned short)previousType) && type4 >= 173 && type4 <= 199 && owner2 == DAT_011dea3c)
            duration = 0.0f;
        if (force)
            duration = 0.0f;
        duration /= *DAT_011c5724.Setting_Float_00403e20();
        apSequence->SetPhase(0.0f, 0);
        if (!previous2 && (section3 == 5 || section3 == 6))
            manager.Modelloader_GetReferencedThis()->FUN_0047aab0(apSequence, 0, 1, apSequence->GetFloatAtOffset1C(), duration, 0);
        else if (duration < DAT_01016408)
            manager.Modelloader_GetReferencedThis()->FUN_0047aab0(apSequence, 0, 1, apSequence->GetFloatAtOffset1C(), 0.0f, 0);
        else if (synchronize)
            manager.Modelloader_GetReferencedThis()->CallFUN_00a351d0(previous2, apSequence, duration, 0,
                                                     previous2->GetFloatAtOffset1C(), apSequence->GetFloatAtOffset1C());
        else
        {
            bool blended = false;
            if (previous2 && previous2->FUN_008041a0())
                blended = manager.Modelloader_GetReferencedThis()->NiControllerManager_CrossFade(previous2, apSequence, duration, 0, 1,
                                                               apSequence->GetFloatAtOffset1C(), 0);
            if (!blended)
            {
                if (DAT_011dea10->TES_CellTestRunning())
                    manager.Modelloader_GetReferencedThis()->FUN_0047aab0(apSequence, 0, 1, 1.0f, 0.0f, 0);
                else
                {
                    if (actor && actor->IsActor())
                    {
                        BlendActor* blendActor = actor;
                        if (bhkRagdollController_QFootIK() && blendActor->ragdoll && blendActor->ragdoll->bhkRagdollController_GetsFootIKActive())
                            blendActor->ragdoll->UpdateBoneLocalTransforms();
                    }
                    manager.Modelloader_GetReferencedThis()->NiControllerManager_BlendFromPose(apSequence, 0.0f, duration, 0, 0);
                }
            }
        }
        if (previous2 && previous2 != apSequence)
        {
            switch (previous2->FUN_008041a0())
            {
            case 1:
            case 2:
            case 5:
                manager.Modelloader_GetReferencedThis()->FUN_0047b220(previous2, 0.0f);
                break;
            }
        }
    }
    flags[section3] = 0;
    return apSequence;
}

}

// GetSequenceForKey : Animation::GetSequenceForKey(BSAnimGroupSequence*, unsigned short)
//
// The original (149 bytes, unoptimised build) is:
//
//   push ebp / mov ebp,esp / sub esp,0x10
//   mov [ebp-0x10],ecx            <- the "this" home
//   movzx eax,word [ebp+0xc]      <- the unsigned short argument
//   cmp eax,0xff / je <ret0>      <- the "||" short circuit: the invalid key
//   lea ecx,[ebp-8] / push ecx    <- &out of the map lookup
//   movzx edx,word [ebp+0xc] / push edx
//   mov eax,[ebp-0x10] / mov ecx,[eax+0xdc] / call GetAt
//   ...
//
// so the class member at +0xdc is the animation-sequence map and the map's
// value is the sequence object the following virtual call is made on.
//
// The two early exits (the invalid key and the failed map lookup) share ONE
// "return 0" block in the original; the short-circuit "||" of the two tests
// is what makes cl 15.00.30729.01 emit that single block.

struct FNV_SeqMapStandIn
{
    bool GetAt(unsigned short key, SeqIface*& result) const;
};

struct FNV_AnimationOwner : public Animation
{
    BSAnimGroupSequence* GetSequenceForKey(BSAnimGroupSequence* pSequence, unsigned short usKey);
};

// @fnv 0x00495da0
BSAnimGroupSequence* FNV_AnimationOwner::GetSequenceForKey(BSAnimGroupSequence* pSequence, unsigned short usKey)
{
    SeqIface* pFound;
    if (usKey == 0xff || !((FNV_SeqMapStandIn*)m_pOwnerReference)->GetAt(usKey, pFound))
        return 0;

    SeqIface* _pUse = 0;
    if (!pFound->IsSingleSeq())
        _pUse = pFound;

    if (!_pUse)
        return 0;

    SeqIface* pSeqObj = _pUse->FindObjectByNameVariant(pSequence, -1);
    if (!pSeqObj)
        return 0;

    return (BSAnimGroupSequence*)((FUN_004948c0_shell*)this)->Animation_StartGroup(pSeqObj, usKey, -1);
}

struct SequenceRef
{
    signed char* FUN_0043b1b0();
};
struct TrackEntry
{
    void* controller;
    void* interpolationData;
    SequenceRef* FUN_00717e50();
    float AStarSearch_EvaluateValue_006a7f50();
};
struct SequenceInterface : BSAnimGroupSequence
{
    float FUN_00598040();
};
unsigned int __cdecl BSstrlen(int actionId);
int __cdecl FUN_00ec7ec0(signed char* sequenceData, int actionId, unsigned int trackCount);
char __cdecl FUN_00ec67aa(int character);

struct AnimationInterface : Animation
{
    char Animation_FindNextNoteKey(int sequenceIndex, int actionId, float* outTime);
};
// @fnv 0x00495f50
// src: COMMUNITY 0x00495f50
char AnimationInterface::Animation_FindNextNoteKey(int sequenceIndex, int actionId, float* outTime)
{
    if (outTime != 0)
        *outTime = 0.0f;

    if (m_pChildTile[sequenceIndex] == 0 || actionId == 0)
        return 0;

    unsigned int entries;
    float tracks = static_cast<SequenceInterface*>(m_pChildTile[sequenceIndex])->FUN_00598040();
    NiTextKeyExtraData* sequenceTime = m_pChildTile[sequenceIndex]->GetName_00700300();
    TrackEntry* key = reinterpret_cast<TrackEntry*>(sequenceTime->GetKeys_00495f30(&entries));
    unsigned int trackCount = BSstrlen(actionId);
    if (!trackCount)
        return 0;

    for (unsigned int i = 0; i < static_cast<unsigned int>(entries); ++i)
    {
        signed char* object = key[i].FUN_00717e50()->FUN_0043b1b0();
        if (object != 0 && FUN_00ec7ec0(object, actionId, trackCount) == 0 && tracks <= key[i].AStarSearch_EvaluateValue_006a7f50())
        {
            if (outTime != 0)
                *outTime = key[i].AStarSearch_EvaluateValue_006a7f50();
            return FUN_00ec67aa(object[trackCount]);
        }
    }
    return 0;
}

class IdleAnimGroupAccess498
{
  public:
    unsigned int FUN_005f2420();
};

class IdleReplayDelayAccess498
{
  public:
    TESIdleForm* idle;
    float delay;
};
class IdleModelAccess : public KFModel
{
  public:
    IdleAnimGroupAccess498* FUN_005585e0();
};
class AnimIdleAccess : public LocalAnimIdle
{
  public:
    int FUN_0044ddc0();
    IdleModelAccess* bhkNiCollisionObject_GetWorldObject();
    TESIdleForm* FUN_0055b980();
    void AnimIdle_PlayAnim(BSAnimGroupSequence*);
    void FUN_00403550(int);
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};


struct IdleLogName
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual const char* Name();
};
struct IdleLogDword
{
    unsigned char b0, b1, b2, b3;
};
struct IdleLog
{
    unsigned int id;
    unsigned char kind;
    IdleLogDword flags;
    unsigned char index;
};
struct IdleStream
{
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_LoadGameDataOLD(void*, unsigned int);
    IdleLog* BGSProjectile_GetExplosion();
    bool FUN_008df040();
    unsigned int FUN_00825c00();
    bool FUN_00857aa0(void*, unsigned int);
    void FUN_00857bd0(unsigned int);
};
struct FUN_004965d0 : NiMemObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    FUN_004965d0(TESIdleForm*, int, int, Actor*, int, Animation*);
    void LoadQueuedAnim(float, Animation*);
};
typedef struct FUN_004965d0 IdleLoadTask;
extern TESForm* __cdecl TESForm_GetFormByNumericID(unsigned int);
extern void __cdecl Warning_005b5e40(const char*, ...);
extern const char DAT_0101d930[], DAT_01015718[], DAT_010156a8[], DAT_0101dcec[], DAT_01015588[], DAT_01015500[],
    DAT_010154a0[], DAT_01015440[];
// Reads an idle block from the stream, creates an IdleLoadTask for the matching TESIdleForm and logs block-size mismatches.
// @fnv 0x004977e0
IdleLoadTask* __cdecl LoadIdleAnimation(Actor* actor, Animation* animation, float time)
{
    AutoMemContext context4((MEM_CONTEXT)51, true, DAT_0101d930, 0x1218);
    IdleLoadTask* result2 = 0;
    unsigned short blockSize4 = 0;
    unsigned int start = 0;
    if (((IdleStream*)DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int magic;
        ((IdleStream*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&magic, 4);
        if (magic != 0x424c4f4b)
        {
            IdleLog* log = ((IdleStream*)DAT_011de45c)->BGSProjectile_GetExplosion();
            if (log)
            {
                IdleLogName* name = (IdleLogName*)TESForm_GetFormByNumericID(log->id);
                Warning_005b5e40(DAT_01015718, DAT_0101d930, 0x121c, log->id, name->Name(), log->index,
                             *(unsigned int*)&log->flags);
            }
            else
                Warning_005b5e40(DAT_010156a8, DAT_0101d930, 0x121c, ((IdleStream*)DAT_011de45c)->FUN_008df040());
        }
        start = ((IdleStream*)DAT_011de45c)->FUN_00825c00();
        ((IdleStream*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&blockSize4, 2);
    }
    unsigned int id4;
    bool present4 = ((IdleStream*)DAT_011de45c)->FUN_00857aa0(&id4, 4);
    if (id4 || present4)
    {
        unsigned short size;
        ((IdleStream*)DAT_011de45c)->TESSaveLoadGame_LoadGameDataOLD(&size, 2);
        TESIdleForm* idle = 0;
        if (id4)
            idle = dynamic_cast<TESIdleForm*>(TESForm_GetFormByNumericID(id4));
        if (idle)
        {
            result2 = new IdleLoadTask(idle, 7, 1, actor, 1, 0);
            result2->LoadQueuedAnim(time, animation);
        }
        else
        {
            Warning_005b5e40(DAT_0101dcec, id4, ((IdleLogName*)actor)->Name());
            ((IdleStream*)DAT_011de45c)->FUN_00857bd0(size);
        }
    }
    if (((IdleStream*)DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int position = ((IdleStream*)DAT_011de45c)->FUN_00825c00();
        IdleLog* logEndA = ((IdleStream*)DAT_011de45c)->BGSProjectile_GetExplosion();
        if (logEndA)
        {
            IdleLogName* nameEnd = (IdleLogName*)TESForm_GetFormByNumericID(logEndA->id);
            if (position > start + blockSize4)
                Warning_005b5e40(DAT_01015588, position - (start + blockSize4), DAT_0101d930, 0x1237, logEndA->id,
                             nameEnd->Name(), logEndA->index, *(unsigned int*)&logEndA->flags);
            else if (position < start + blockSize4)
                Warning_005b5e40(DAT_01015500, start + blockSize4 - position, DAT_0101d930, 0x1237, logEndA->id,
                             nameEnd->Name(), logEndA->index, *(unsigned int*)&logEndA->flags);
        }
        else
        {
            if (position > start + blockSize4)
                Warning_005b5e40(DAT_010154a0, position - (start + blockSize4), DAT_0101d930, 0x1237,
                             ((IdleStream*)DAT_011de45c)->FUN_008df040());
            else if (position < start + blockSize4)
                Warning_005b5e40(DAT_01015440, start + blockSize4 - position, DAT_0101d930, 0x1237,
                             ((IdleStream*)DAT_011de45c)->FUN_008df040());
        }
    }
    return result2;
}

extern "C" const char DAT_0101dd28[];

struct FUN_00497ca0_shell : public Animation
{
    void Animation_SpecialIdleQueue(TESIdleForm*, int);
};

// @fnv 0x00497ca0
// src: XBOX_PDB 0x00497ca0
void FUN_00497ca0_shell::Animation_SpecialIdleQueue(TESIdleForm* a1, int a2)
{
    AutoMemContext ctx(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true, DAT_0101d930, 4701);
    if (LocalInput)
    {
        int section = LocalInput->GetSection();
        switch (section)
        {
        case 21:
            section = 4;
            break;
        case 20:
            section = 1;
            break;
        }
        if (LocalInput->GetControllerSequence())
        {
            if (m_pChildTile[section] == LocalInput->GetControllerSequence())
            {
                switch (LocalInput->GetControllerSequence()->GetState())
                {
                case 2:
                case 5:
                    Warning(DAT_0101dd28, (const char*)static_cast<const NiControllerSequence*>(LocalInput->GetControllerSequence())->GetName());
                    return;
                default:
                    break;
                }
                BlendOut(LocalInput->GetSection(), false);
            }
        }
        if (!LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
        {
            AssignControllerManager(LocalInput);
        }
    }
    LocalInput = (LocalAnimIdle*)new LocalAnimIdle(a1, a2, 1, (Actor*)m_pAttachedReference, 0, 0);
}

namespace fnv_00498030 {

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct AnimationFinish
{
    void SpecialIdleReplace_0();
};
struct WorkerAnimation : Animation
{
    void Animation_SpecialIdleReplace(TESIdleForm*, Actor*, int);
};
// @fnv 0x00498030
// src: COMMUNITY 0x00498030
void WorkerAnimation::Animation_SpecialIdleReplace(TESIdleForm* idle, Actor* actor, int section)
{
    AutoMemContext h(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true,
                     "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 4797);
    Animation* p = this;
    if (!g_BGSSaveLoadGame->IsLoading())
    {
        LocalStateValue = (LocalAnimIdle*)new LocalAnimIdle(idle, section, 0, actor, 0, this);
    }
    else
    {
        LocalStateValue = (LocalAnimIdle*)new LocalAnimIdle(idle, section, 0, actor, 1, 0);
    }
    ((AnimationFinish*)p)->SpecialIdleReplace_0();
}
}  // namespace fnv_00498030

namespace fnv_00499080 {
struct FUN_00499080_shell : public Animation
{
    void Animation_ClearBlendInterps();
};

void __fastcall ClearItemField2(NiObject* object);
extern NiRTTI DAT_011c7d74;

// @fnv 0x00499080
// src: COMMUNITY 0x00499080
void FUN_00499080_shell::Animation_ClearBlendInterps()
{
    if (!m_acReservedBytes)
        return;
    unsigned int sequenceCount = m_acReservedBytes->GetSequenceCount_00495d00();

    for (unsigned int index = 0; index < sequenceCount; ++index)
    {
        NiControllerSequence* sequence =
            ((NiControllerManager*)(NiControllerManager*)m_acReservedBytes)->GetSequenceAt_00495d20(index);
        NiObject* matchingObject = NiObject_DynamicCast(&DAT_011c7d74, (NiObject*)sequence);
        if (matchingObject)
        {
            ClearItemField2(matchingObject);
        }
    }
    while (((FUN_00493830_shell*)this)->Animation_GetAnimsLoading())
    {
        KFModel* model = kfModelList.GetItem();
        FinishScriptRunLockIfActive(model);
        FinishScriptRunLockIfActive(model);
        kfModelList.RemoveHead();
    }
}
}  // namespace fnv_00499080

extern NiRTTI DAT_011f3714;
extern NiRTTI DAT_011f36bc;
struct S_00499160_Node;

struct S_00499160_Mgr
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8(int a, int b);
};
struct S_00499160_Seq
{
    void __thiscall ClearInterpolators();
};

struct S_00499160_Node
{
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int i);
};

// @fnv 0x00499160
// src: XBOX_PDB 0x00499160
void __cdecl Animation_ClearControllersInterpolators(NiAVObject* obj)
{
    if (!obj)
        return;
    NiTimeController* c = obj->GetControllers();
    while (c)
    {
        S_00499160_Mgr* m = (S_00499160_Mgr*)NiObject_DynamicCast(&DAT_011f3714, (NiObject*)c);
        if (m)
        {
            m->vfn_c8(0, 0);
        }
        else
        {
            S_00499160_Seq* s = (S_00499160_Seq*)NiObject_DynamicCast(&DAT_011f36bc, (NiObject*)c);
            if (s)
                s->ClearInterpolators();
        }
        c = c->GetNext();
    }
    S_00499160_Node* node = (S_00499160_Node*)obj->IsSceneNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); i++)
        {
            NiAVObject* child = node->FUN_0043b4a0(i);
            Animation_ClearControllersInterpolators(child);
        }
    }
}

struct ResetRoot
{
    void* GetController(const void*);
    void ReplaceControllers(void*);
};
struct ResetSequence
{
    unsigned int Priority();
    void Attach(ResetRoot*, unsigned int);
    void Detach();
    NiFixedStr& GetName();
    bool Activate(ResetRoot*);
};
struct ResetPalette
{
    void Clear();
};
struct ResetManager
{
    void* Palette();
    void SetTime(float);
    unsigned int Count();
    ResetSequence* Sequence(unsigned int);
    void Start(void*, int, int, float, float, int);
};
ResetPalette* __cdecl CastPalette(const void*, void*);
extern int resetPaletteRTTI, resetControllerRTTI, resetOtherRTTI;
template <class T> struct ResetPointer
{
    T* value;
    operator T*() const;
};
struct ResetAnimation
{
    int unk00;
    int unk04;
    ResetPointer<ResetRoot> root;
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
    ResetPointer<ResetManager> manager;
    int unkdc;
    void* currentSequences[8];
    void Animation_ReloadTargets(bool attach);
};
// @fnv 0x00499240
// src: XBOX_PDB 0x00499240
void ResetAnimation::Animation_ReloadTargets(bool attach)
{
    if (!(ResetManager*)manager)
        return;
    void* paletteVal = ((ResetManager*)manager)->Palette();
    if (paletteVal)
    {
        ResetPalette* castPalette3 = CastPalette(&resetPaletteRTTI, paletteVal);
        if (castPalette3)
            castPalette3->Clear();
    }
    void* controller5 = ((ResetRoot*)root)->GetController(&resetControllerRTTI);
    void* otherController = ((ResetRoot*)root)->GetController(&resetOtherRTTI);
    if (controller5)
        ((ResetRoot*)root)->ReplaceControllers(controller5);
    if (otherController)
        ((ResetRoot*)root)->ReplaceControllers(otherController);
    ((ResetManager*)manager)->SetTime(0.0f);
    unsigned int priority2 = 0;
    for (unsigned int first4 = 0; first4 < ((ResetManager*)manager)->Count(); ++first4)
    {
        ResetSequence* seqFirst4 = ((ResetManager*)manager)->Sequence(first4);
        if (seqFirst4 && seqFirst4->Priority() > priority2)
            priority2 = seqFirst4->Priority();
    }
    for (unsigned int second7 = 0; second7 < ((ResetManager*)manager)->Count(); ++second7)
    {
        ResetSequence* seqSecond3 = ((ResetManager*)manager)->Sequence(second7);
        if (seqSecond3)
        {
            if (attach)
            {
                if (!((ResetRoot*)root)->GetController(&resetControllerRTTI) && priority2)
                    seqSecond3->Attach((ResetRoot*)root, priority2);
                if (*(const unsigned short*)(const char*)seqSecond3->GetName() != 0x5f5f)
                    seqSecond3->Activate((ResetRoot*)root);
            }
            else
            {
                seqSecond3->Detach();
                seqSecond3->Attach((ResetRoot*)root, priority2);
            }
        }
    }
    for (int section = 0; section < 8; ++section)
    {
        if (currentSequences[section])
            ((ResetManager*)manager)->Start(currentSequences[section], 0, 0, 1.0f, 0.0f, 0);
    }
}

namespace fnv_004994f0 {
struct FUN_004994f0_shell : Animation
{
    void Animation_BlendOut(int section, bool restoreAction);
    void Animation_ClearGroup(int section, float timeTmp);
};
struct BlendActor : Actor
{
    bool IsSneaking();
    void PlayAnimationSequence(int group, Animation* animation);
};
bool __fastcall IsWeaponDrawn(Actor*);
int __fastcall GetAnimAction_008a7570(Actor*);
bool __fastcall TESDataHandler_GetClearingData(TESDataHandler*);
float* __fastcall Setting_Float_00403e20(void*);
struct BlendGroup : TESAnimGroup
{
    int GetMoveAnimGroup();
    ANIM_GROUP_ENUM GetType() const;
};
bool __cdecl IsIronSightsAction(ANIM_GROUP_ENUM);
extern Actor* g_thePlayer;
extern "C" TESDataHandler* DAT_011c3f2c;
extern "C" int DAT_011c56fc;
extern "C" int DAT_011c5724;
extern AnimationVector NiPoint3_ZERO;
// @fnv 0x004994f0
// src: XBOX_PDB 0x004994f0
void FUN_004994f0_shell::Animation_BlendOut(int section, bool restoreAction)
{
    int kIndex = section;
    switch (section)
    {
    case 20:
        kIndex = 1;
        break;
    case 21:
        kIndex = 4;
        break;
    }
    BlendActor* actor = static_cast<BlendActor*>(m_pAttachedReference);
    if (kIndex == 1)
        m_kNodeTranslation = NiPoint3_ZERO;
    BSAnimGroupSequence* sequence_ = m_pChildTile[kIndex];
    float timeTmp = 0.0f;
    if (sequence_ && !m_cSkipNextBlend)
    {
        timeTmp = *Setting_Float_00403e20(&DAT_011c56fc);
        char frames = GetMaxByte(reinterpret_cast<unsigned char*>(FUN_0048f7f0(sequence_)));
        if (frames)
            timeTmp = frames / 30.0;
        timeTmp /= *Setting_Float_00403e20(&DAT_011c5724);
    }
    bool allowed = true;
    bool _overrideFlag = false;
    bool aChanged = false;
    if (m_pAttachedReference && (kIndex == 4 || section == 20) && IsWeaponDrawn(actor) && !TESDataHandler_GetClearingData(DAT_011c3f2c))
    {
        if (restoreAction && GetAnimAction_008a7570(actor) == 2 && actor->GetProcess()->GetActorProcessTime())
            _overrideFlag = true;
        else
            aChanged = true;
        if (kIndex == 4)
        {
            allowed = false;
            if ((GetAnimAction_008a7570(actor) == 9 || GetAnimAction_008a7570(actor) == 17) && actor != g_thePlayer && timeTmp < 0.5)
            {
                switch (static_cast<BlendGroup*>(FUN_0048f7f0(sequence_))->GetMoveAnimGroup())
                {
                case 1:
                    if (!actor->IsSneaking())
                        timeTmp = 0.5f;
                    break;
                default:
                    if (actor->IsSneaking())
                        timeTmp = 0.5f;
                    break;
                }
            }
            Animation_ClearGroup(5, timeTmp);
            Animation_ClearGroup(6, timeTmp);
        }
    }
    if (allowed)
        Animation_ClearGroup(section, timeTmp);
    if (_overrideFlag)
    {
        ANIM_GROUP_ENUM group =
            static_cast<BlendGroup*>(FUN_0048f7f0(actor->GetProcess()->GetActorProcessTime()))->GetType();
        if (IsIronSightsAction(group))
            group = static_cast<ANIM_GROUP_ENUM>(group - 3);
        actor->PlayAnimationSequence(group, this);
    }
    else if (aChanged)
    {
        actor->PlayAnimationSequence(17, this);
    }
}
}  // namespace fnv_004994f0

struct SequenceSize : BSAnimGroupSequence
{
    unsigned short GetSaveSize_004efb10();
};
struct SaveVersion : ActiveManager
{
    unsigned char FUN_008df040();
};


struct SceneObject;
struct SceneResult
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual SceneObject* GetNode();
};
struct ManagerView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual SceneResult* Find(NiFixedString*);
};
struct ControllerView
{
    ManagerView* GetStringAtOffset();
};

struct SceneProperty
{
    NiObject* NiObjectNET_GetControllers();
};
struct SceneObject
{
    SceneProperty* NiNode_GetAtChecked(unsigned int);
};
struct SequenceController : NiObject
{
    SequenceSize* NiControllerManager_GetSequenceByName(NiFixedString*);
};
extern NiRTTI DAT_011f36ac;
struct MessageRecord
{
    int id;
    unsigned char kind;
    unsigned char parameter[4];
};
// Accumulates the serialized byte size of the animation, including group sequences, idle data, and an optional scene sequence, and logs the total when enabled.
// @fnv 0x004997f0
unsigned short FakeAnim::GetSerializedSize(void* apRef)
{
    unsigned short p = 0;
    unsigned short i = p;
    if (DAT_011de45c->TESSaveLoadGame_UseSaveGameBlocks())
    {
        p += 4;
        p += 2;
    }
    p += 4;
    p += 4;
    p += 12;
    p += 4;
    p += 1;
    p += 1;
    char h;
    for (h = 0; h < 8; ++h)
    {
        if (((Animation*)this)->group[h] != 255 && ((Animation*)this)->group[h] != 65535)
        {
            p += 2;
            p += 4;
            p += 4;
            p += 2;
            p += 4;
            p += 1;
            if (((Animation*)this)->m_pChildTile[h])
                p += ((SequenceSize*)((Animation*)this)->m_pChildTile[h])->GetSaveSize_004efb10();
        }
    }
    Actor* a = 0;
    if (apRef && ((TESObjectREFR*)apRef)->IsActor())
        a = (Actor*)apRef;
    if ((LocalAnimIdle*)((Animation*)this)->LocalStateValue)
        p += GetMessageSize(a, (ParameterObject*)(LocalAnimIdle*)((Animation*)this)->LocalStateValue);
    else
        p += GetMessageSize(a, (ParameterObject*)(LocalAnimIdle*)((Animation*)this)->LocalInput);
    p += 1;
    if (((SaveVersion*)DAT_011de45c)->FUN_008df040() >= 64)
        p += 1;
    if (a->GetSelectedMagicItem())
    {
        SceneResult* result = ((ManagerView*)((Animation*)this)->GetControllerManager_00496940()->GetStringAtOffset())->Find(FixedStrings_QMagicNode());
        if (result)
        {
            SceneObject* node = result->GetNode();
            if (node)
            {
                SceneProperty* pSceneProperty = node->NiNode_GetAtChecked(0);
                if (pSceneProperty)
                {
                    NiObject* object = pSceneProperty->NiObjectNET_GetControllers();
                    SequenceController* controller = (SequenceController*)NiObject_DynamicCast(&DAT_011f36ac, object);
                    if (controller)
                    {
                        SequenceSize* sequence = controller->NiControllerManager_GetSequenceByName(get_g_SpecialIdle_Cast());
                        if (sequence)
                        {
                            p += sequence->GetSaveSize_004efb10();
                            p += 4;
                        }
                    }
                }
            }
        }
    }
    if (*DAT_011de4e8.FUN_00408d60())
    {
        MessageRecord* message = (MessageRecord*)DAT_011de45c->FUN_004fd3e0();
        if (message)
        {
            MessageProvider* provider = TESForm_GetFormByNumericID(message->id);
            ProgramFlow(DAT_01012cb0, p - i, message->id, provider->GetDisplayValue(),
                         *(unsigned int*)message->parameter, 5560, DAT_0101d930);
        }
        else
        {
            ProgramFlow(DAT_01012c78, p - i, 5560, DAT_0101d930);
        }
    }
    return p;
}

namespace fnv_00499b90 {
struct PaddedByte
{
    unsigned char b00, b01, b02, b03, b04;
    unsigned char value;
};
extern char DAT_011f36ac;
extern char UNK_0101ddc8;
extern char UNK_0101d930;
extern char UNK_0101536c;
extern char UNK_010153a0;
extern char UNK_01015318;

void __cdecl AnimIdle_SaveAnimIdle(void* pA, unsigned int uB, void* pC, float fD);
void* __cdecl NiObject_DynamicCast(void* pKey, unsigned int uVal);
void* __cdecl TESForm_GetFormByNumericID(unsigned int uVal);
struct Stream_00499b90
{
    unsigned int FUN_00825c00();
    bool TESSaveLoadGame_UseSaveGameBlocks();
    void TESSaveLoadGame_SaveGameDataOLD(const void* pSrc, unsigned int uSize);
    unsigned char FUN_008df040();
    unsigned int FUN_004fd3e0();
};
struct Detect_00499b90
{
    unsigned char* FUN_00408d60();
};
struct Lookup_00499b90
{
    bool Lookup(unsigned short usId, void** ppOut);
};
struct Elem_00499b90
{
    void SaveGameTES_004efb20(float fVal);
};
struct Span_00499b90
{
    unsigned int Modelloader_GetReferencedThis();
};
struct Root_00499b90
{
    void* GetControllerManager_00496940();
};
struct NodeMgr_00499b90
{
    void* GetStringAtOffset();
};
struct Chan_00499b90
{
    int NiNode_GetAtChecked(unsigned int uA);
};
struct Bc_00499b90
{
    int NiNode_GetAtChecked(unsigned int uA);
};
struct Chan2_00499b90
{
    unsigned int NiObjectNET_GetControllers();
};
struct Chan3_00499b90
{
    unsigned int NiControllerManager_GetSequenceByName(unsigned int uVal);
};
struct Anim_00499b90
{
    float ActorPackage_GetPackageStartTime();
};
struct OutObj_00499b90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual char FUN_0018(unsigned int uVal);
};
struct ChnObj_00499b90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int FUN_000c();
};
struct NodeObj_00499b90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int FUN_0034();
    void* FUN_00726070();
};
struct MemObj_00499b90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void* v8c(NiFixedString*);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual unsigned int FUN_0130();
};
struct Class2_00499b90
{
    unsigned int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void* v8c(NiFixedString*);
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool FUN_0100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual unsigned int FUN_0130();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    NodeObj_00499b90 m_88;
};
struct Holder_00499b90
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float f10[3];
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned short f4c[8];
    unsigned int f5c[8];
    unsigned int f7c[8];
    unsigned short f9c[8];
    unsigned int fac[8];
    char fcc;
    char unkcd, unkce, unkcf;
    unsigned int fd0;
    unsigned int unkd4;
    unsigned int unkd8;
    void* fdc;
    void* fe0[8];
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    char f120;
    char unk121, unk122, unk123;
    void* f124;
    void* f128;
    void WriteToStream(Class2_00499b90* param_2);
};
// Serializes the holder's fields and per-slot data to the stream, writing a KOLB block header and patching its length afterwards.
// @fnv 0x00499b90
void Holder_00499b90::WriteToStream(Class2_00499b90* pClass2)
{
    unsigned short lengthA5;
    unsigned int uStart7;
    unsigned int uMark2;
    char cb_;
    char bMask7;
    unsigned char bFlagVal;
    Class2_00499b90* pPi14;
    void __cdecl Warning_005b5e40(void*, ...);
    lengthA5 = 0;
    uMark2 = 0;
    uStart7 = ((Stream_00499b90*)DAT_011de45c)->FUN_00825c00();
    if (*((Detect_00499b90*)&DAT_011de4e8)->FUN_00408d60() != '\0')
    {
        uStart7 = ((Stream_00499b90*)DAT_011de45c)->FUN_00825c00();
    }
    if (((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int uKolb;
        uKolb = 0x424c4f4b;
        ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&uKolb, 4);
        uMark2 = ((Stream_00499b90*)DAT_011de45c)->FUN_00825c00();
        ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&lengthA5, 2);
    }
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->unk10c, 4);
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->unk110, 4);
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(this->f10, 0xc);
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->unk48, 4);
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->fcc, 1);
    bMask7 = 0;
    for (cb_ = 0; (char)cb_ < 8; cb_++)
    {
        if (this->f4c[cb_] != 0xff && this->f4c[cb_] != 0xffff)
        {
            bMask7 |= 1 << cb_;
        }
    }
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&bMask7, 1);
    for (cb_ = 0; (char)cb_ < 8; cb_++)
    {
        if (this->f4c[cb_] != 0xff && this->f4c[cb_] != 0xffff)
        {
            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->f4c[cb_], 2);
            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->f5c[cb_], 4);
            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->f7c[cb_], 4);
            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->f9c[cb_], 2);
            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->fac[cb_], 4);
            unsigned char bId;
            void* pOut;
            bId = 0xff;
            if (((Lookup_00499b90*)this->fdc)->Lookup(this->f4c[cb_], &pOut))
            {
                bId = (unsigned char)((OutObj_00499b90*)pOut)->FUN_0018((unsigned int)this->fe0[cb_]);
            }
            if (this->fe0[cb_] == 0)
            {
                Warning_005b5e40(&UNK_0101ddc8, pClass2->FUN_0130(), pClass2->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), (int)cb_, (int)this->f4c[cb_],
                             this->f5c[cb_]);
                bId = 0xfe;
            }
            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&bId, 1);
            if (this->fe0[cb_] != 0)
            {
                ((Elem_00499b90*)this->fe0[cb_])->SaveGameTES_004efb20(*(float*)&this->fd0);
            }
        }
    }
    pPi14 = 0;
    if (pClass2 != 0)
    {
        if (pClass2->FUN_0100())
        {
            pPi14 = pClass2;
        }
    }
    if (((Span_00499b90*)&this->f128)->Modelloader_GetReferencedThis() != 0)
    {
        AnimIdle_SaveAnimIdle(pPi14, ((Span_00499b90*)&this->f128)->Modelloader_GetReferencedThis(), ((void*)this), *(float*)&this->fd0);
    }
    else
    {
        AnimIdle_SaveAnimIdle(pPi14, ((Span_00499b90*)&this->f124)->Modelloader_GetReferencedThis(), ((void*)this), *(float*)&this->fd0);
    }
    ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&this->f120, 1);
    bFlagVal = 0;
    if (pPi14->m_88.FUN_0034() != 0)
    {
        void* pV;
        pV = ((Class2_00499b90*)((NodeMgr_00499b90*)((Root_00499b90*)((void*)this))->GetControllerManager_00496940())
                  ->GetStringAtOffset())
                 ->v8c(FixedStrings_QMagicNode());
        if (pV != 0)
        {
            int iVar;
            iVar = ((ChnObj_00499b90*)pV)->FUN_000c();
            if (iVar != 0)
            {
                Chan_00499b90* p38;
                p38 = (Chan_00499b90*)((Bc_00499b90*)iVar)->NiNode_GetAtChecked(0);
                if (p38 != 0)
                {
                    unsigned int u38;
                    unsigned int u3c3;
                    u38 = ((Chan2_00499b90*)p38)->NiObjectNET_GetControllers();
                    u3c3 = (unsigned int)NiObject_DynamicCast(&DAT_011f36ac, u38);
                    if (u3c3 != 0)
                    {
                        unsigned int u40;
                        u40 = ((Chan3_00499b90*)u3c3)->NiControllerManager_GetSequenceByName((unsigned int)get_g_SpecialIdle_Cast());
                        if (u40 != 0)
                        {
                            bFlagVal = 1;
                            if (((Stream_00499b90*)DAT_011de45c)->FUN_008df040() >= 0x40)
                            {
                                ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&bFlagVal, 1);
                            }
                            ((Elem_00499b90*)u40)->SaveGameTES_004efb20(*(float*)&this->fd0);
                            float f44;
                            void* pSequence3;
                            pSequence3 = pPi14->m_88.FUN_00726070();
                            f44 = 0.0f;
                            if (pSequence3 != 0)
                            {
                                f44 = ((Anim_00499b90*)pSequence3)->ActorPackage_GetPackageStartTime();
                            }
                            ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&f44, 4);
                        }
                    }
                }
            }
        }
    }
    if (((Stream_00499b90*)DAT_011de45c)->FUN_008df040() >= 0x40 && bFlagVal == 0)
    {
        ((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_SaveGameDataOLD(&bFlagVal, 1);
    }
    if (*((Detect_00499b90*)&DAT_011de4e8)->FUN_00408d60() != '\0')
    {
        unsigned int u50_2;
        unsigned int u4c4;
        u50_2 = ((Stream_00499b90*)DAT_011de45c)->FUN_00825c00();
        u4c4 = ((Stream_00499b90*)DAT_011de45c)->FUN_004fd3e0();
        if (u4c4 != 0)
        {
            MemObj_00499b90* p54;
            p54 = (MemObj_00499b90*)TESForm_GetFormByNumericID(*(unsigned int*)u4c4);
            ProgramFlow((const char*)&UNK_010153a0, (int)(u50_2 - uStart7), *(unsigned int*)u4c4, p54->FUN_0130(),
                         *reinterpret_cast<const unsigned int*>(&((const PaddedByte*)u4c4)->value), 0x1628,
                         &UNK_0101d930);
        }
        else
        {
            ProgramFlow((const char*)&UNK_0101536c, (int)(u50_2 - uStart7), 0x1628, (unsigned int)&UNK_0101d930);
        }
    }
    if (((Stream_00499b90*)DAT_011de45c)->TESSaveLoadGame_UseSaveGameBlocks())
    {
        unsigned int u58;
        unsigned int u5c;
        u58 = ((Stream_00499b90*)DAT_011de45c)->FUN_00825c00();
        u5c = uMark2;
        if (u58 > u5c + 0xffff)
        {
            Warning_005b5e40(&UNK_01015318, (unsigned int)&UNK_0101d930, 0x1628);
        }
        *(unsigned short*)uMark2 = (unsigned short)(u58 - u5c);
    }
}
}  // namespace fnv_00499b90

namespace fnv_0049bb70 {
class IdleReplayDelayEntry
{
};


struct ReplayDelayNode
{
    IdleReplayDelayEntry** FUN_006815c0();
    ReplayDelayNode* FUN_00726070();
    void FUN_00470470();
};

struct FUN_0049bb70_shell : public FUN_00496280_shell
{
    void Animation_ClearGroup(int, float);
    void RemoveItemFromMap(AnimationPointer<LocalAnimIdle>*);
    void Animation_Revert(int);
};

// @fnv 0x0049bb70
// src: XBOX_PDB 0x0049bb70
void FUN_0049bb70_shell::Animation_Revert(int aiUnused)
{
    m_cSkipNextBlend = 0;
    Animation_ClearGroup(20, 0.0f);
    Animation_ZeroGlobalTransform();
    if (LocalInput)
    {
        RemoveItemFromMap(&LocalInput);
    }
    LocalInput = 0;
    if (LocalStateValue)
    {
        RemoveItemFromMap(&LocalStateValue);
    }
    LocalStateValue = 0;
    m_pChildTile[7] = 0;
    Animation_ClearGroup(7, 0.0f);
    if (m_acReservedBytes)
    {
        ((NiControllerManager*)(NiControllerManager*)m_acReservedBytes)->FUN_0048fef0(0.0f);
    }
    ReplayDelayNode* pIter = (ReplayDelayNode*)&m_acTrailingData;
    while (pIter)
    {
        IdleReplayDelayEntry* pDelay = *pIter->FUN_006815c0();
        delete pDelay;
        pIter = pIter->FUN_00726070();
    }
    ((ReplayDelayNode*)&m_acTrailingData)->FUN_00470470();
}
}  // namespace fnv_0049bb70

namespace fnv_0049bf10 {
extern const double _gModifierZero;

struct TimeGlobal
{
    unsigned int GetMilliseconds();
};
extern TimeGlobal g_timeGlobal;



// @fnv 0x0049bf10
void SetSequenceProgress(float afPercent, NiControllerManager* apManager, NiControllerSequence* apSequence)
{
    if (!apManager || !apSequence)
        return;

    if (afPercent == _gModifierZero)
    {
        if (apSequence->GetState() == 1)
        {
            apSequence->SetSequenceTime(0.0f, true);
            apSequence->Update(0.0f, true);
        }
    }
    else
    {
        if (apSequence->GetState() == 0)
        {
            apManager->FUN_0047aa40(true);
            apManager->ActivateControllerSequence(apSequence, 0, false, 1.0f, 0.0f, static_cast<NiControllerSequence*>(0));
            apSequence->Update(g_timeGlobal.GetMilliseconds() / 1000.0 + apSequence->NiPSysSpawnModifier_GetLifeSpan(), true);
        }
        if (apSequence->GetState() == 1)
        {
            float fScaleMultiplier = apSequence->GetEndKeyTime_00508100() - apSequence->NiPSysSpawnModifier_GetLifeSpan();
            float fTime2 = apSequence->NiPSysSpawnModifier_GetLifeSpan() + fScaleMultiplier * afPercent;
            apSequence->SetSequenceTime(fTime2 - g_timeGlobal.GetMilliseconds() / 1000.0f, true);
        }
    }
}
}  // namespace fnv_0049bf10

namespace fnv_004939d0 {
extern TESObjectREFR* g_thePlayer;



struct AnimNode_Vtable
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual PathingRequest* vfn_10();
};

struct FUN_00493b90_shell
{
    bool Animation_GetMoved();
};

struct FUN_00493860_shell
{
    void Animation_SetMoved(bool);
};

struct FUN_004f8960_shell
{
    int GameSettingCollection_File();
};

struct FUN_00493bb0_shell
{
    bool Actor_IsInCombat();
};

struct FUN_008b0140_shell
{
    void SetVisibilityMask(bool, int);
};

struct FUN_0084e3a0_shell
{
    int GetHavokWorldObjectCountInSceneGraph_0084e3a0();
};

struct FUN_00b63680_shell
{
    bool CheckVolumeState(unsigned int, bool);
};

struct FUN_00b7b930_Ctx;
FUN_00b7b930_Ctx* __cdecl BSShaderManager_GetAccumulator();

class _FakeNiNode : public NiNode
{
  public:
    NiAVObject* FUN_0043b4a0(unsigned int);
};

struct FUN_0043c490_shell
{
    AnimationVector& GetTranslate_0043c490();
};

struct FUN_004f0040_shell
{
    void UpdateControls(float);
};

class AnimationShell : public Animation
{
  public:
    void UpdateAnimationForRef(TESObjectREFR* apRef);
};

// @fnv 0x004939d0
void AnimationShell::UpdateAnimationForRef(TESObjectREFR* apRef)
{
    if (!m_acHeaderData || !m_pObjectNode)
        return;

    if (reinterpret_cast<FUN_00493b90_shell*>(this)->Animation_GetMoved())
        return;

    bool bOther = apRef != g_thePlayer;
    bool bNearLimit2 = false;

    NiNode* pNode5 = apRef->GetNiNode();
    PathingRequest* pReq = pNode5 ? reinterpret_cast<AnimNode_Vtable*>(pNode5)->vfn_10() : 0;

    if (bOther && (reinterpret_cast<FUN_004f8960_shell*>(apRef)->GameSettingCollection_File() == 1 ||
                   reinterpret_cast<FUN_00493bb0_shell*>(apRef)->Actor_IsInCombat()))
    {
        bOther = false;
    }
    else if (pReq && pReq->GetFieldB4Float() <= 0.0)
    {
        bNearLimit2 = true;
    }

    reinterpret_cast<FUN_008b0140_shell*>(apRef)->SetVisibilityMask(true, 1);

    FUN_00b7b930_Ctx* pCtx5 = BSShaderManager_GetAccumulator();
    if (pCtx5 && reinterpret_cast<FUN_00b63680_shell*>(pCtx5)->CheckVolumeState(
                     reinterpret_cast<FUN_0084e3a0_shell*>(apRef)->GetHavokWorldObjectCountInSceneGraph_0084e3a0(), false))
    {
        reinterpret_cast<FUN_008b0140_shell*>(apRef)->SetVisibilityMask(false, 2);
    }
    else
    {
        reinterpret_cast<FUN_008b0140_shell*>(apRef)->SetVisibilityMask(true, 2);
    }

    if (pReq && pReq->GetFieldB4Float() < 0.00001f)
    {
        reinterpret_cast<FUN_008b0140_shell*>(apRef)->SetVisibilityMask(false, 4);
    }
    else
    {
        reinterpret_cast<FUN_008b0140_shell*>(apRef)->SetVisibilityMask(true, 4);
    }

    float fOldZ =
        reinterpret_cast<FUN_0043c490_shell*>(static_cast<_FakeNiNode*>(m_pObjectNode)->FUN_0043b4a0(0))->GetTranslate_0043c490().z;

    reinterpret_cast<FUN_004f0040_shell*>((NiNode*)m_acHeaderData)->UpdateControls(time);

    m_kNodeTranslation.z = reinterpret_cast<FUN_0043c490_shell*>(static_cast<_FakeNiNode*>(m_pObjectNode)->FUN_0043b4a0(0))
                          ->GetTranslate_0043c490()
                          .z -
                      fOldZ;

    reinterpret_cast<FUN_00493860_shell*>(this)->Animation_SetMoved(true);
}
}  // namespace fnv_004939d0

class FUN_0048f810
{
  public:
    FUN_0048f810();

    void UpdateFlags(unsigned char ucArg0, unsigned char ucArg1, unsigned char ucArg2);

    unsigned char m_uiObjectFlags;
    TESObjectREFR* m_pAttachedReference;
    AnimationPointer<NiNode> m_acHeaderData;
    NiNode* m_pObjectNode;
    AnimationVector m_kNodeTranslation;
    AnimationVector m_kRootTranslation;
    NiAVObject* m_acNodeName[8];
    float m_fAnimationAmount;
    unsigned short group[8];
    ANIM_GROUP_ACTION action[8];
    int m_acTargetName[8];
    unsigned short usReloadGroup[8];
    int m_acAnimationName[8];
    char m_cState;
    bool m_bIsPlaying;
    float time;
    float m_fTimeOffset;
    AnimationPointer<NiControllerManager> m_acReservedBytes;
    AnimationSequenceMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;
    BSAnimGroupSequence* m_pChildTile[8];
    BSAnimGroupSequence* m_pCurrentSequence;
    AnimationList<KFModel*> kfModelList;
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    unsigned short m_usQueuedGroup;
    AnimationPointer<LocalAnimIdle> LocalInput;
    AnimationPointer<LocalAnimIdle> LocalStateValue;
    AnimationPointer<LocalAnimIdle> LocalOutput[2];
    AnimationList<IdleReplayDelayEntry*> m_acTrailingData;
};

typedef char AnimationSizeCheck[sizeof(FUN_0048f810) == 0x13c ? 1 : -1];

// @fnv 0x0048f810
FUN_0048f810::FUN_0048f810() : m_acHeaderData(0), m_acReservedBytes(0), LocalInput(0), LocalStateValue(0)
{
    m_acHeaderData = 0;
    m_pObjectNode = 0;
    m_kNodeTranslation = AnimationVector::ZERO;
    m_kRootTranslation = AnimationVector::ZERO;
    m_fAnimationAmount = 0.0f;
    m_cState = -1;
    m_cSkipNextBlend = 0;
    UpdateFlags(0, 0xff, 0);
    m_pAttachedReference = 0;
    m_pCurrentSequence = 0;
    time = 0.0f;
    m_acReservedBytes = 0;
    LocalInput = 0;
    LocalStateValue = 0;
    LocalOutput[0] = 0;
    LocalOutput[1] = 0;
    m_pOwnerReference = new AnimationSequenceMap<unsigned short, AnimSequenceBase*>(101);
    memset(m_acNodeName, 0, sizeof(m_acNodeName));
    memset(m_pChildTile, 0, sizeof(m_pChildTile));
    memset(group, 0xff, sizeof(group));
    memset(usReloadGroup, 0xff, sizeof(usReloadGroup));
    memset(action, -1, sizeof(action));
    memset(m_acTargetName, -1, sizeof(m_acTargetName));
    memset(m_acAnimationName, -1, sizeof(m_acAnimationName));
    m_fMovementRate = 1.0f;
    m_fCombatAnimationRate = 1.0f;
    m_fEquipAnimationRate = 1.0f;
    m_fReloadAnimationRate = 1.0f;
    m_fAnimationTimeScale = 1.0f;
    m_usQueuedGroup = 0xff;
    m_bIsPlaying = false;
}

namespace fnv_00496a50 {
template <int N> struct Slots496 : Slots496<N - 1>
{
    virtual void pad(Slots496<N>*);
};
template <> struct Slots496<0>
{
};
struct Process496 : Slots496<250>
{
    virtual void* get();
};
struct Manager496
{
    void* GetStringAtOffset();
};
struct Anim496
{
    Manager496* GetControllerManager_00496940();
    void Animation_RemoveObject(void*);
};

struct Node496 : Slots496<58>
{
    virtual void remove(void*);
};
struct Object496
{
    Node496* NiAVObject_GetParent();
    void ValidateTargets();
};
struct Ref496
{
    void* value;
    Object496* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void*);
};
struct Queue496
{
    static Queue496* FUN_004537b0();
    void TaskQueueInterface_QueueSSNRemoveObject(void*, int);
    void TaskQueueInterface_QueueNodeDetach(void*);
};
struct Shadow496
{
    void RemoveObject_00b5b1c0(void*);
};
bool AILinearTaskThreadManager_ShouldQueue3DTask();
Shadow496* FUN_00450b80(unsigned);
void RecurseAndRemoveObjectsFromPalette(void*, void*);


// Pending idle record: count +0x08, object refs +0x24, actor +0x34; Data is a 0x10-byte record.
struct PendingIdleRecord
{
    char pad[8];
    int count;
    char pad2[12];
    Ref496 root;
    TESIdleForm* models[2];
    Ref496 objects[2];
    char pad3[8];
    Actor* actor;
};
struct Loader496
{
    void ModelLoader_ReleaseFile(const char*);
    void ModelLoader_CancelAnimIdle(PendingIdleRecord*);
};
struct Save496
{
    bool FUN_0047c850();
};
extern "C" char DAT_011c3b3c;
extern "C" char DAT_011de45c;
struct Target496
{
    static void DetachObjectModels(PendingIdleRecord* data);
};
// @fnv 0x00496a50
void Target496::DetachObjectModels(PendingIdleRecord* data)
{
    if (!data)
        return;
    for (int i = 0; i < 2; ++i)
    {
        if (data->objects[i].Modelloader_GetReferencedThis())
        {
            if (data->actor)
            {
                if (AILinearTaskThreadManager_ShouldQueue3DTask())
                    Queue496::FUN_004537b0()->TaskQueueInterface_QueueSSNRemoveObject(data->objects[i].Modelloader_GetReferencedThis(), 0);
                else
                    FUN_00450b80(0)->RemoveObject_00b5b1c0(data->objects[i].Modelloader_GetReferencedThis());
                void* anim = ((Anim496*)data->actor->GetAnimData())->GetControllerManager_00496940()->GetStringAtOffset();
                void* copy7 = anim;
                RecurseAndRemoveObjectsFromPalette(data->objects[i].Modelloader_GetReferencedThis(), copy7);
                Anim496* manager5 = ((Anim496*)data->actor->GetAnimData());
                if (manager5)
                    manager5->Animation_RemoveObject(data->objects[i].Modelloader_GetReferencedThis());
            }
            if (AILinearTaskThreadManager_ShouldQueue3DTask())
                Queue496::FUN_004537b0()->TaskQueueInterface_QueueNodeDetach(data->objects[i].Modelloader_GetReferencedThis());
            else
            {
                Node496* nodeB = data->objects[i].Modelloader_GetReferencedThis()->NiAVObject_GetParent();
                nodeB->remove(data->objects[i].Modelloader_GetReferencedThis());
            }
            (*(Loader496**)&DAT_011c3b3c)->ModelLoader_ReleaseFile(data->models[i]->GetModelFilePath());
            data->objects[i].FUN_0066b0d0(0);
            if (data->root.Modelloader_GetReferencedThis())
                data->root.Modelloader_GetReferencedThis()->ValidateTargets();
        }
    }
    if (!data->count)
        (*(Loader496**)&DAT_011c3b3c)->ModelLoader_CancelAnimIdle(data);
    if (!(*(Save496**)&DAT_011de45c)->FUN_0047c850() && data->actor && data->actor->GetAnimAction_008a7570() == 13)
    {
        Process496* process = (Process496*)data->actor->FUN_008d8520();
        if (process->get() == data->root.Modelloader_GetReferencedThis())
            ((AnimationActorOperations*)data->actor)->SetAnimAction(-1, 0);
    }
    data->actor = 0;
}
}  // namespace fnv_00496a50



class SeqBase0
{
  public:
    int a0, a4, a8, aC, a10, a14;
};
class SeqBase18
{
  public:
    int b0;
};
class SeqX : public SeqBase0, public SeqBase18
{
};
class SeqPtr
{
  public:
    SeqX* m_p;
    SeqPtr& FUN_0066b0d0(SeqX*);
    SeqX* Modelloader_GetReferencedThis() const;
};
class StrX
{
  public:
    void* m_p;
    const char* Modelloader_GetReferencedThis() const;
};

class KFPtr
{
  public:
    KFModel* m_p;
    KFPtr& UpdateState_0044b070(KFModel*);
};

SeqX* BipedAnim_LoadAndAttachAddOn(SeqX*, SeqBase18*, int, Actor*, int);
void AddObjectToPaletteRecursive(SeqX*, void*);
class FUN_00496cd0_cls
{
  public:
    virtual ~FUN_00496cd0_cls();
    int unk04;
    int m_uiImageSpaceModifierCount;
    int iType;
    KFPtr m_pRenderedNodeEntry;
    int unk14;
    StrX kName;
    SeqX* apSeq[2];
    SeqPtr aspSeq[2];
    int unk2C;
    Animation* pAnim;
    Actor* pActor;
    void InitFromModel(KFModel* m_kModelObjectsItem);
};
// @fnv 0x00496cd0
void FUN_00496cd0_cls::InitFromModel(KFModel* m_kModelObjectsItem)
{
    AutoMemContext kContext(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp",
                             0x1101);
    m_pRenderedNodeEntry.UpdateState_0044b070(m_kModelObjectsItem);
    if (m_kModelObjectsItem)
    {
        for (int i = 0; i < 2; i++)
        {
            if (apSeq[i] && pActor)
            {
                aspSeq[i].FUN_0066b0d0(BipedAnim_LoadAndAttachAddOn(apSeq[i], apSeq[i], -1, pActor, 0));
                void* pMgr = ((Animation*)pActor->GetAnimData())->GetControllerManager_00496940()->GetStringAtOffset();
                void* pAnimMgrCopy = pMgr;
                AddObjectToPaletteRecursive(aspSeq[i].Modelloader_GetReferencedThis(), pAnimMgrCopy);
                ((AnimationActorOperations*)pActor)->SetByteAt14E(true);
            }
        }
        m_kModelObjectsItem->AcquireReference();
        m_uiImageSpaceModifierCount = 1;
        if (pActor && (iType == 2 || iType == 3))
        {
            Animation* pkAnim = pAnim;
            if (!pkAnim)
                pkAnim = ((Animation*)pActor->GetAnimData());
            if (!pkAnim)
            {
                delete this;
                return;
            }
            if (pkAnim->SpecialIdlePlay_0())
            {
                if (iType == 3)
                    ((AnimationActorOperations*)pActor)->SetAnimAction(0xd, kName.Modelloader_GetReferencedThis());
            }
            else
            {
                pkAnim->SpecialIdleFree(true, false);
            }
        }
        else if (pActor && iType == 0)
        {
            Animation* pkAnim = pAnim;
            if (!pkAnim)
                pkAnim = ((Animation*)pActor->GetAnimData());
            if (!pkAnim)
            {
                delete this;
                return;
            }
            if (pkAnim->SpecialIdleReplace_0())
                return;
        }
    }
    else
    {
        m_uiImageSpaceModifierCount = 0;
    }
}

struct Node
{
    Node* bhkNiCollisionObject_GetWorldObject();
    Node* FUN_005585e0();
    unsigned short GetAnimGroupType_0047d3b0();
    void* FUN_00490e40();
    unsigned FUN_00825c00();
    void ReleaseObject(void*);
};
struct Ref
{
    void* p;
    Ref(int);
    ~Ref();
    Node* Modelloader_GetReferencedThis();
    void FUN_0066b0d0(void*);
    bool FUN_00822510(void*);
};
struct Item
{
    virtual ~Item();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int);
};
// Exe 0x00498670: unit-local Map view; declarations and layout are preserved.
struct AnimationMapView
{
    bool Lookup(unsigned short, Item*&);
    void FUN_0049c250(unsigned short);
};
void __cdecl DetachObjectModels(Node*);
struct Target
{
    char pad[0xcd];
    unsigned char flag;
    char pad2[10];
    Ref ref;
    AnimationMapView* map;
    void* values[8];
    void* current;
    void Animation_ClearGroup(unsigned, float);
    void RemoveItemFromMap(Ref* arg);
};
// Looks up the map entry for the node's key, clears the matching value slot, updates current and the ref, then removes and deletes the item.
// @fnv 0x00498670
void Target::RemoveItemFromMap(Ref* apRef)
{
    Node* world = apRef->Modelloader_GetReferencedThis()->bhkNiCollisionObject_GetWorldObject();
    Item* item5 = 0;
    unsigned short key5 = 255;
    Ref hold3(0);
    if (world && world->FUN_005585e0())
    {
        key5 = world->FUN_005585e0()->GetAnimGroupType_0047d3b0();
        map->Lookup(key5, item5);
        if (item5 && item5->v4(-1) != apRef->Modelloader_GetReferencedThis()->FUN_00490e40())
        {
            item5 = 0;
        }
        else
        {
            if (values[apRef->Modelloader_GetReferencedThis()->FUN_00825c00()] == apRef->Modelloader_GetReferencedThis()->FUN_00490e40())
                Animation_ClearGroup(apRef->Modelloader_GetReferencedThis()->FUN_00825c00(), 0.0f);
        }
    }
    if (!item5)
        hold3.FUN_0066b0d0(apRef->Modelloader_GetReferencedThis()->FUN_00490e40());
    if (!flag)
    {
        if (item5)
        {
            if (item5->v4(-1) == current)
                current = 0;
            ref.Modelloader_GetReferencedThis()->ReleaseObject(item5->v4(-1));
        }
        else if (hold3.Modelloader_GetReferencedThis())
        {
            if (hold3.FUN_00822510(current))
                current = 0;
            ref.Modelloader_GetReferencedThis()->ReleaseObject(hold3.Modelloader_GetReferencedThis());
        }
    }
    DetachObjectModels(apRef->Modelloader_GetReferencedThis());
    apRef->FUN_0066b0d0(0);
    if (item5)
    {
        map->FUN_0049c250(key5);
        delete item5;
        item5 = 0;
    }
    if (!hold3.Modelloader_GetReferencedThis() && !item5)
        map->FUN_0049c250(key5);
}

namespace fnv_00494390 {
struct MotionPoint
{
    float x, y, z;
};
extern const MotionPoint DAT_011f426c;
struct MotionMatrix
{
    float m[3][3];
};
struct MotionRoot
{
    const MotionMatrix& NiAVObject_GetRotate_006a9540();
};
struct RootHandle
{
    MotionRoot* value;
    MotionRoot* Modelloader_GetReferencedThis();
};
struct MotionGroup
{
    int FUN_005f2420();
    float FUN_005f4c70();
};
struct MotionSequence
{
    MotionGroup* FUN_0048f7f0();
    int FUN_008041a0();
};
struct TimeGlobal
{
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
struct MotionActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int getType();
    virtual void slot134();
    virtual bool disabled();
    bool IsMoving_004938e0();
    float TESObjectREFR_GetScale_00567400();
};
void NiMatrix3_TransformVertices(const MotionMatrix*, const MotionPoint*, int, const MotionPoint*, MotionPoint*);
struct MovementAnimation
{
    unsigned int flags;
    MotionActor* owner;
    RootHandle root;
    void* accumRoot;
    MotionPoint movement, accumTranslation;
    void* soundBones[8];
    float looking;
    unsigned short groups[8];
    int actions[8], loops[8];
    unsigned short nextGroups[8];
    int m_acAnimationName[8];
    char skip, shutdown, unkce, unkcf;
    float time, lipTime;
    void* manager;
    void* sequenceMap;
    MotionSequence* sequences[8];
    MotionSequence* lastMovement;
    AnimationList<KFModel*> models;
    float moveSpeed, attackSpeed, globalTimeMultiplier;
    bool GetMovement(MotionPoint*, MotionActor*, bool, bool);
};
// Builds a movement vector, limits its components under a sequence condition, optionally removes Z, and rotates it.
// @fnv 0x00494390
bool MovementAnimation::GetMovement(MotionPoint* apMovement, MotionActor* actor, bool rotate, bool removeZ)
{
    float alternate, speed2, limitVal, scale4;
    if (!root.Modelloader_GetReferencedThis())
        return false;
    float deltaTime7 = g_timeGlobal.FUN_0084d030() * globalTimeMultiplier;
    const MotionPoint zero3 = DAT_011f426c;
    MotionPoint origin3 = zero3;
    MotionPoint delta3 = movement;
    MotionMatrix rotation5 = root.Modelloader_GetReferencedThis()->NiAVObject_GetRotate_006a9540();
    if (!actor->disabled() && actor->IsMoving_004938e0() && sequences[1] &&
        sequences[1]->FUN_0048f7f0()->FUN_005f2420() >= 3 && sequences[1]->FUN_0048f7f0()->FUN_005f2420() <= 16)
    {
        speed2 = sequences[1]->FUN_0048f7f0()->FUN_005f4c70() * moveSpeed * deltaTime7 * owner->TESObjectREFR_GetScale_00567400();
        if (sequences[4] && sequences[4]->FUN_008041a0() == 1)
        {
            alternate = sequences[4]->FUN_0048f7f0()->FUN_005f4c70() * attackSpeed * deltaTime7 * owner->TESObjectREFR_GetScale_00567400();
            if (alternate > speed2)
                speed2 = alternate;
        }
        limitVal = speed2 * 4.0;
        if (speed2 > 0.0)
        {
            if (delta3.x > limitVal)
                delta3.x = speed2;
            if (delta3.y > limitVal)
                delta3.y = speed2;
            if (delta3.z > limitVal)
                delta3.z = speed2;
            if (delta3.x < -limitVal)
                delta3.x = -speed2;
            if (delta3.y < -limitVal)
                delta3.y = -speed2;
            if (delta3.z < -limitVal)
                delta3.z = -speed2;
        }
    }
    if (actor)
    {
        switch (actor->getType())
        {
        case 3:
        case 5:
        case 8:
        case 10: {
            scale4 = actor->TESObjectREFR_GetScale_00567400();
            delta3.x /= scale4;
            delta3.y /= scale4;
            break;
        }
        default:
            break;
        }
    }
    if (removeZ)
        delta3.z = 0.0f;
    if (rotate)
        NiMatrix3_TransformVertices(&rotation5, &origin3, 1, &delta3, apMovement);
    else
        *apMovement = delta3;
    return true;
}
}  // namespace fnv_00494390

namespace fnv_00494740 {

struct AnimGroupInfo
{
    const char* pName;
    bool bVariants;
    int m_iSectionIndex;
    int eKeyType;
    int iFlags;
    int iBlend;
    int iBlendIn;
    int iBlendOut;
    int iSoundPriority;
};
extern AnimGroupInfo DAT_011977d8[];
struct SeqIface;
struct FUN_004948c0_shell
{
    SeqIface* GetSequenceForGroup(unsigned short, int);
};
struct FUN_0049bca0_t
{
    void Animation_UpdateBipOnly(float, bool, bool);
};
struct FUN_00494740_t : public Animation
{
    BSAnimGroupSequence* Animation_PlayGroup(unsigned short asNewGroup, int aeFlags, int aiLoops, int aeSection);
};

// Resolves the group type and section, then updates stored group data or retrieves a sequence according to key type and flags.
// @fnv 0x00494740
// src: XBOX_PDB 0x00494740
BSAnimGroupSequence* FUN_00494740_t::Animation_PlayGroup(unsigned short asNewGroup, int aeFlags, int aiLoops, int aeSection)
{
    int iGroupType = TESAnimGroup::GetType(asNewGroup);
    int esection = aeSection == -1 ? DAT_011977d8[iGroupType].m_iSectionIndex : aeSection;
    BSAnimGroupSequence* pretSeq = 0;
    switch (esection)
    {
    case 0x14:
        esection = 1;
        break;
    case 0x15:
        esection = 4;
        break;
    }
    if (iGroupType == 0xff)
        return pretSeq;
    switch (DAT_011977d8[iGroupType].eKeyType)
    {
    case 0:
    case 1:
    case 2:
        switch (aeFlags)
        {
        case 0:
            usReloadGroup[esection] = asNewGroup;
            m_acAnimationName[esection] = aiLoops;
            break;
        case 1:
            usReloadGroup[esection] = 0xff;
            m_acTargetName[esection] = aiLoops;
            pretSeq = (BSAnimGroupSequence*)((FUN_004948c0_shell*)this)->GetSequenceForGroup(asNewGroup, aeSection);
            ((FUN_0049bca0_t*)this)->Animation_UpdateBipOnly(time, false, true);
            break;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        pretSeq = (BSAnimGroupSequence*)((FUN_004948c0_shell*)this)->GetSequenceForGroup(asNewGroup, aeSection);
        ((FUN_0049bca0_t*)this)->Animation_UpdateBipOnly(time, false, true);
        break;
    }
    return pretSeq;
}
}  // namespace fnv_00494740

namespace fnv_00495be0 {
struct BoneStub
{
    const NiFixedString& GetName() const;
};

struct SeqStub : public BSAnimGroupSequence
{
    unsigned char GetPriority(const char* apName, unsigned int* apIndex);
};

int __cdecl GetType(unsigned short asGroup);

struct PriorityAnimation : public Animation
{
    bool IsHighestPriority();
};

// Returns true if the sequence in slot 1 has the highest priority among all active sequences for the given bone name.
// @fnv 0x00495be0
bool PriorityAnimation::IsHighestPriority()
{
    if (!m_pChildTile[1])
        return false;
    if (!m_acNodeName[1])
        return false;
    const char* name = ((BoneStub*)m_acNodeName[1])->GetName();
    switch (GetType(group[1]))
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14: {
        BSAnimGroupSequence* best = 0;
        unsigned char maxPriority = 0;
        for (int section = 0; section < 8; section++)
        {
            if (m_pChildTile[section])
            {
                unsigned char priority = ((SeqStub*)m_pChildTile[section])->GetPriority(name, 0);
                if (priority > maxPriority)
                {
                    best = m_pChildTile[section];
                    maxPriority = priority;
                }
                else if (priority == maxPriority && section == 1)
                {
                    best = m_pChildTile[section];
                    maxPriority = priority;
                }
            }
        }
        if (best == m_pChildTile[1])
            return true;
        break;
    }
    }
    return false;
}
}  // namespace fnv_00495be0

namespace fnv_00497180 {
namespace save497 {
struct S49Obj
{
    void SaveGameTES_004efb20(float value);
};
struct S49Checker
{
    virtual void z_000();
    virtual void z_001();
    virtual void z_002();
    virtual void z_003();
    virtual void z_004();
    virtual void z_005();
    virtual char Check18(S49Obj* obj);
};
struct S49Result
{
    bool Lookup();
};
struct S49Key
{
    int FUN_005f2420();
};
struct S49Base
{
    S49Key* FUN_005585e0();
};
struct S49Map
{
    S49Result* FUN_00497280(int key, S49Checker** found);
};
template <class T> struct S49Ptr
{
    T* p;
    T* Modelloader_GetReferencedThis();
};
struct S49Save
{
    void TESSaveLoadGame_SaveGameDataOLD(void* data, int size);
};
struct S49Entry
{
    int unk00;
    int unk04;
    int iA;
    int iB;
    S49Ptr<S49Base> kBase;
    int iC;
    S49Ptr<S49Obj> kObj;
    void AnimIdle_SaveGameTES(float value, S49Map* map);
};
}
using namespace save497;
extern S49Save* DAT_011de45c;

// Writes iA, iB, iC, and an object flag; if an object exists, writes a checker result or -1, then calls kObj's FUN_004efb20.
// @fnv 0x00497180
// src: COMMUNITY 0x00497180
void S49Entry::AnimIdle_SaveGameTES(float value, S49Map* map)
{
    bool bHasObj;
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&iA, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&iB, 4);
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&iC, 4);
    bHasObj = false;
    if (kObj.Modelloader_GetReferencedThis())
    {
        bHasObj = true;
    }
    DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&bHasObj, 1);
    if (bHasObj)
    {
        char cCheckResult = -1;
        S49Checker* pChecker;
        if (map->FUN_00497280(kBase.Modelloader_GetReferencedThis()->FUN_005585e0()->FUN_005f2420(), &pChecker)->Lookup())
        {
            cCheckResult = pChecker->Check18(kObj.Modelloader_GetReferencedThis());
        }
        DAT_011de45c->TESSaveLoadGame_SaveGameDataOLD(&cCheckResult, 1);
        kObj.Modelloader_GetReferencedThis()->SaveGameTES_004efb20(value);
    }
}
}  // namespace fnv_00497180

// Calls the virtual destructor of the object and frees its memory when the low bit of flags is set, returning the original pointer.
// @fnv 0x0048ef60
void* FUN_0048ef60(void* apThis, unsigned int flags)
{
    struct FUN_0048ef40_shell
    {
        virtual ~FUN_0048ef40_shell()
        {}
    };
    FUN_0048ef40_shell* self = static_cast<FUN_0048ef40_shell*>(apThis);
    self->~FUN_0048ef40_shell();
    if (flags & 1)
        operator delete(apThis);
    return apThis;
}

// Initializes item model and solution refs, loads KF model via idle or direct load, and adds objects to palette if model is valid.
// @fnv 0x004965d0
LocalAnimIdle::LocalAnimIdle(TESIdleForm* apItem, int apField14, int apFieldC, Actor* apActor, bool abLoadDirect,
                   Animation* aiField30)
    : model(0), solution(0), sols()
{
    using namespace fnv_004965d0;
    solution.Reset(0);
    field14 = (void*)apField14;
    fieldc = (void*)apFieldC;
    source = (fnv_004965d0::Item4965*)apItem;
    for (int i = 0; i < 2; ++i)
    {
        items[i] = (Item4965*)(*(Container4965**)&DAT_011c3f2c)->FindNthMatchingItem(apItem, i);
        sols[i].Reset(0);
    }
    field30 = (int)aiField30;
    actor = apActor;
    StrMem strModelPath;
    BSStringT_char_SPrintF(&strModelPath, &DAT_0101dcc4, &DAT_0101dccc, ((ItemBase4965*)((char*)apItem + 24))->v5());
    if (!abLoadDirect)
    {
        model.UpdateState_0044b070((*(Loader4965**)&DAT_011c3b3c)->InsertIdle(strModelPath.GetText(), this, 0, apActor));
    }
    else
    {
        model.UpdateState_0044b070((*(Loader4965**)&DAT_011c3b3c)->LoadKFModel(strModelPath.GetText()));
    }
    if (model.Modelloader_GetReferencedThis())
    {
        for (int j = 0; j < 2; ++j)
        {
            if (items[j] && apActor)
            {
                sols[j].Reset(BipedAnim_LoadAndAttachAddOn(items[j], (ItemBase4965*)items[j], -1, apActor, 0));
                void* manager = ((Anim4965*)apActor->GetAnimData())
                                    ->GetControllerManager_00496940()
                                    ->GetStringAtOffset();
                void* pointer = manager;
                AddObjectToPaletteRecursive(sols[j].Modelloader_GetReferencedThis(), pointer);
                ((AnimationActorOperations*)apActor)->SetByteAt14E(true);
            }
        }
        if (!abLoadDirect)
            QueuedChildren_AddFinishedChild(model.Modelloader_GetReferencedThis());
        ready = 1;
    }
    else
    {
        ready = 0;
    }
}


class TESForm;
namespace fnv_004975e0 {

struct SaveFormInfo
{
    unsigned int refID;
};

struct SaveLoadGame
{
    char* GetBufferPos();
    bool IsSaving();
    void WriteData(void* apData, int aiSize);
    void WriteRefID(void* apData, int aiSize);
    SaveFormInfo* GetCurrentForm();
};
extern SaveLoadGame* g_TESSaveLoadGame;

struct BoolSetting
{
    unsigned char* Bool();
};
extern BoolSetting g_011de4e8;

struct SaveRef
{
    unsigned int GetRefID();
};

struct SaveForm
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* GetDescription();
};
SaveForm* LookupFormByID(unsigned int auiID);

struct SavedAnim
{
    SaveRef* GetTarget();
    unsigned short GetSaveGroup();
    void SaveState(float afTime, int aiState);
};

void SaveGameDebugPrint(const char* apFormat, ...);
void LogWarning(const char* apFormat, ...);

// Writes the animation save block to the save buffer, including the target refID, save group, and animation state, then patches the block size.
// @fnv 0x004975e0
// src: COMMUNITY 0x004975e0
void AnimIdle_SaveAnimIdle(void* apUnused, SavedAnim* apAnim, int aiState, float afTime)
{
    unsigned short usBlockSize4 = 0;
    char* pSizePos8 = 0;
    char* pStart4 = g_TESSaveLoadGame->GetBufferPos();
    if (*g_011de4e8.Bool())
        pStart4 = g_TESSaveLoadGame->GetBufferPos();
    if (g_TESSaveLoadGame->IsSaving())
    {
        int iTag5 = 0x424c4f4b;
        g_TESSaveLoadGame->WriteData(&iTag5, 4);
        pSizePos8 = g_TESSaveLoadGame->GetBufferPos();
        g_TESSaveLoadGame->WriteData(&usBlockSize4, 2);
    }
    unsigned int uiRefID4 = 0;
    if (apAnim && apAnim->GetTarget())
        uiRefID4 = apAnim->GetTarget()->GetRefID();
    g_TESSaveLoadGame->WriteRefID(&uiRefID4, 4);
    if (uiRefID4)
    {
        unsigned short usGroup = apAnim->GetSaveGroup();
        g_TESSaveLoadGame->WriteData(&usGroup, 2);
        apAnim->SaveState(afTime, aiState);
    }
    if (*g_011de4e8.Bool())
    {
        char* pEnd6 = g_TESSaveLoadGame->GetBufferPos();
        SaveFormInfo* pInfo2 = g_TESSaveLoadGame->GetCurrentForm();
        if (pInfo2)
        {
            SaveForm* pForm = LookupFormByID(pInfo2->refID);
            SaveGameDebugPrint("SaveGame(): %-5i for form %08X %s with flags %08X ending at line %i in file %s",
                               pEnd6 - pStart4, pInfo2->refID, pForm->GetDescription(),
                               *(unsigned int*)((char*)pInfo2 + 5), 0x120e,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp");
        }
        else
        {
            SaveGameDebugPrint("SaveGame(): %-5i ending at line %i in file %s", pEnd6 - pStart4, 0x120e,
                               "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp");
        }
    }
    if (g_TESSaveLoadGame->IsSaving())
    {
        char* pCur5 = g_TESSaveLoadGame->GetBufferPos();
        {
            char* pSize4 = pSizePos8;
            if (pCur5 > pSize4 + 0xffff)
                LogWarning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x120e);
            *(unsigned short*)pSizePos8 = pCur5 - pSize4;
        }
    }
}
}  // namespace fnv_004975e0

// May free an idle, add a model, obtain a sequence, and pass it to an idle method.
// @fnv 0x00498290
// src: COMMUNITY 0x00498290
bool Animation::SpecialIdlePlay_0()
{
    if ((LocalAnimIdle*)LocalStateValue)
    {
        if (static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalStateValue)->FUN_0044ddc0() == 1)
            SpecialIdleFree(false, true);
        else
            return false;
    }
    if ((LocalAnimIdle*)LocalInput && static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_0044ddc0() == 1)
    {
        IdleModelAccess* pkModel = static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->bhkNiCollisionObject_GetWorldObject();
        if (pkModel && AddAnimation(pkModel, false) && pkModel->FUN_005585e0())
        {
            BSAnimGroupSequence* pkSequence = 0;
            if (!static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetSection() &&
                static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->bhkNiCollisionObject_GetWorldObject()->FUN_005585e0()->FUN_005f2420() ==
                    1)
            {
                pkSequence = Animation_PlayGroup(pkModel->FUN_005585e0()->FUN_005f2420(), 1, -1,
                                          static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetSection());
            }
            else
            {
                pkSequence =
                    Animation_PlayGroup(pkModel->FUN_005585e0()->FUN_005f2420(), 1,
                                 static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_0055b980()->GetRandomValue(),
                                 static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetSection());
            }
            if (pkSequence)
            {
                if (static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_0055b980()->GetField3C() > 0.0)
                {
                    IdleReplayDelayAccess498* pDelay = new IdleReplayDelayAccess498;
                    pDelay->idle = static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_0055b980();
                    pDelay->delay = static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_0055b980()->GetField3C();
                    m_acTrailingData.AddTail(reinterpret_cast<IdleReplayDelayEntry*&>(pDelay));
                }
                static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->AnimIdle_PlayAnim(pkSequence);
                return true;
            }
            else
            {
                static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_00403550(3);
                if (static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 2 ||
                    static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 3)
                    SpecialIdleFree(true, false);
            }
        }
        else
        {
            static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->FUN_00403550(3);
            if (static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 2 ||
                static_cast<AnimIdleAccess*>((LocalAnimIdle*)LocalInput)->GetHavokWorldObjectCountInSceneGraph_0084e3a0() == 3)
                SpecialIdleFree(true, false);
        }
    }
    return false;
}

// Iterates m_pSingleSequence's list and returns the first BSAnimGroupSequence whose group matches apAnimGroup, or null.
// @fnv 0x0048f790
BSAnimGroupSequence* AnimSequenceMultiple::GetControllerSequence(TESAnimGroup* apAnimGroup)
{
    void* listIt;
    listIt = (void*)((SequenceListHead48*)m_pSingleSequence)->Modelloader_GetReferencedThis();
    while (listIt != 0)
    {
        BSAnimGroupSequence* pseq;
        pseq = *(BSAnimGroupSequence**)((FUN_006317a0_struct*)m_pSingleSequence)->AddEight((int)listIt);
        if (::FUN_0048f7f0(pseq) == apAnimGroup)
            return pseq;
        listIt = ((NiTPointerList_SV<TESObjectREFR*>*)m_pSingleSequence)->DereferenceIfNotNull(listIt);
    }
    return 0;
}
