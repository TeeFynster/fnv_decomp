
// src/fallout/magic/bhktelekinesislistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bhktelekinesislistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BSAudio.h"
#include "../../../include/hkpEntity.h"

#include "../../../include/bhkTelekinesisListener.h"

extern "C" void __cdecl _Deallocate(void*);

// Calls FUN_00807910, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x008078e0
void* bhkTelekinesisListener::Destroy(unsigned int flags)
{
    this->bhkTelekinesisListener::~bhkTelekinesisListener();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00807da0_shell
{
    unsigned short m_0006;
    int GetMaskedValue0x3fff();
};

// @fnv 0x00807da0
// src: GUESS 0x00807da0 (confidence: medium)
int FUN_00807da0_shell::GetMaskedValue0x3fff()
{
    return *(unsigned short*)((char*)this + 6) & 0x3fff;
}

void __cdecl bhkTelekinesisListener_Remove(void*, void*);
struct DelVirt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~DelVirt();
};
struct FUN_00807980_shell
{
    void bhkTelekinesisListener_entityDeletedCallback(void*);
};
// Calls FUN_00807cb0 on the object at this-4 with apEntity, then deletes that object as a DelVirt.
// @fnv 0x00807980
// src: COMMUNITY 0x00807980
void FUN_00807980_shell::bhkTelekinesisListener_entityDeletedCallback(void* apEntity)
{
    bhkTelekinesisListener_Remove((void*)((char*)this - 4), apEntity);
    delete (DelVirt*)((char*)this - 4);
}

struct FUN_008079e0_shell
{
    void bhkTelekinesisListener_Finish(hkpEntity*);
    void bhkTelekinesisListener_entityDeactivatedCallback(hkpEntity* entity);
};
// If the byte at offset 0x10 of this is set, calls FUN_00807a10 on the object at this-8 with entity.
// @fnv 0x008079e0
// src: COMMUNITY 0x008079e0
void FUN_008079e0_shell::bhkTelekinesisListener_entityDeactivatedCallback(hkpEntity* entity)
{
    if (*(unsigned char*)((char*)this + 0x10))
        ((FUN_008079e0_shell*)((char*)this - 8))->bhkTelekinesisListener_Finish(entity);
}

struct ITopic
{
    virtual void u0();
    virtual int u1(int);
};
BSAudio* __cdecl _FUN_00c85750();
// @fnv 0x00807bf0
int GetTopicResult(int aiValue)
{
    int result;
    {
        ITopic* topic = (ITopic*)_FUN_00c85750()->GetAudioBackendData();
        result = topic->u1(aiValue);
    }
    return result;
}

namespace fnv_00807c20 {
BSAudio* __cdecl _FUN_00c85750();
struct UnkTopic
{
    virtual void F0();
    virtual void F1();
    virtual void F2(void*, int);
};
// If a1 is non-null, gets an object from _FUN_00c85750 and calls its F2 with a1 and 16.
// @fnv 0x00807c20
// src: GUESS 0x00807c20 (confidence: low)
void Object_UpdateFields_00807c20(void* a1)
{
    if (a1 != 0)
    {
        void* v = _FUN_00c85750()->GetAudioBackendData();
        ((UnkTopic*)v)->F2(a1, 16);
    }
}
}  // namespace fnv_00807c20

struct FUN_00807d10
{
    char _00[8];
    FUN_00807d10();
    ~FUN_00807d10();
};
struct FUN_00807c50
{
    FUN_00807d10 m00;
    FUN_00807d10 m08;
    FUN_00807c50();
};
// Default constructor that default-constructs the two FUN_00807d10 members m00 and m08.
// @fnv 0x00807c50
FUN_00807c50::FUN_00807c50()
{}

// @fnv 0x00807cb0
// src: XBOX_PDB 0x00807cb0
void __cdecl bhkTelekinesisListener_Remove(char* listener, hkpEntity* entity)
{
    entity->RemoveContactListener(listener);
    entity->AddEntityListener(listener ? listener + 4 : 0);
    entity->RemoveEntityListener(listener ? listener + 8 : 0);
}

struct Unk_807d10
{
    Unk_807d10* InitializeFields();
};
// Initialises the object: writes 0 at offset 0, 0 at offset 4 and 0x8000 at offset 6, then returns this.
// @fnv 0x00807d10
// src: GUESS 0x00807d10 (confidence: medium)
Unk_807d10* Unk_807d10::InitializeFields()
{
    *(int*)this = 0;
    *(short*)((char*)this + 4) = 0;
    *(unsigned short*)((char*)this + 6) = 0x8000;
    return this;
}

struct FUN_00807d40_shell
{
    void ForwardCall_00807d40();
    void ProcessState_00807d60();
};
// @fnv 0x00807d40
// src: GUESS 0x00807d40 (confidence: low)
void FUN_00807d40_shell::ForwardCall_00807d40()
{
    ProcessState_00807d60();
}

int __cdecl Object_DispatchSizedBlock_00807dc0(int, int, int);
struct FUN_00807d60_shell
{
    void ProcessState_00807d60();
};
// If the high bit of the field at offset 6 is clear, calls FUN_00807dc0 with the int at offset 0, the result of FUN_00807da0, and 0x18.
// @fnv 0x00807d60
// src: GUESS 0x00807d60 (confidence: low)
void FUN_00807d60_shell::ProcessState_00807d60()
{
    if ((*(unsigned short*)((char*)this + 6) & 0x8000) == 0)
        Object_DispatchSizedBlock_00807dc0(*(int*)this, ((FUN_00807da0_shell*)this)->GetMaskedValue0x3fff(), 0x18);
}

namespace fnv_00807dc0 {
BSAudio* _FUN_00c85750();
struct Topic
{
    virtual void m0();
    virtual void m1();
    virtual void m2(int, int);
};
// Gets an object from _FUN_00c85750 and calls its virtual m2 with a and b*4.
// @fnv 0x00807dc0
// src: GUESS 0x00807dc0 (confidence: low)
void Object_DispatchSizedBlock_00807dc0(int aiArg1, int aiArg2)
{
    void* t = _FUN_00c85750()->GetAudioBackendData();
    ((Topic*)t)->m2(aiArg1, aiArg2 * 4);
}
}  // namespace fnv_00807dc0

// bhkTelekinesisListener's destructor is implicit: it destroys hkpEntityActivationListener (+0x08),
// hkpEntityListener (+0x04) and bhkContactListener (+0x00) without storing this class's vftables.
// It is emitted here because Destroy calls it.
// @fnv 0x00807910 (bhkTelekinesisListener::~bhkTelekinesisListener, implicit)

// ---------------------------------------------------------------------------
// GetOrCreate807c50 - the lazy "get or create" accessor of hkpEntity's
// extended listeners at +0x214.
//
// The original is an /Od /EHsc /GS member function:
//
//   push ebp / mov ebp,esp / push -1 / push <ehhandler> / mov eax,fs:[0]
//   push eax / sub esp,0x10 / <security cookie> / lea eax,[ebp-0xc]
//   mov fs:[0],eax / mov [ebp-0x18],ecx            <- the `this` home
//   ... if (this->m_214 == 0) { <allocate 0x10> ; <construct> ; this->m_214 = ... }
//   ... return this->m_214;
//
// The allocation and the construction are ONE new-expression: MSVC calls the
// class-scope allocation function with sizeof(FUN_00807c50) == 0x10, and then
// - only when the allocation did not return null - calls the constructor on the
// fresh memory and keeps ITS return value (the pointer) as the value of the
// new-expression.  Because FUN_00807c50 owns a sub-object with a non-trivial
// destructor, the new-expression needs an exception frame, which is where the
// `mov dword ptr [ebp-4],0` / `mov dword ptr [ebp-4],-1` state variable and
// the /GS cookie come from.
// ---------------------------------------------------------------------------

// The 8-byte sub-object of FUN_00807c50 (a non-trivial destructor is what
// forces the exception frame of the constructor and of the new-expression).
struct FNV_807d10
{
    int m_000;
    short m_004;
    short m_006;
    FNV_807d10();
    ~FNV_807d10();
};

// The 16-byte object that is allocated and constructed by the accessor.
struct FNV_807c50
{
    FNV_807d10 m_00;
    FNV_807d10 m_08;
    FNV_807c50();

    // The game's own heap helper; the class-scope allocation function is
    // what the original's "push 0x10 / call 0x807bf0" pair is.
    static void* operator new(unsigned int n)
    {
        return (void*)(long)GetTopicResult((int)n);
    }
};

// Returns the extended listeners, allocating them first if needed.
// Kept here because hkpEntity does not yet declare the accessor.
// @fnv 0x00807b50
FNV_807c50* __fastcall GetOrCreate807c50(hkpEntity* entity)
{
    if (entity->m_pExtendedListeners == 0)
    {
        entity->m_pExtendedListeners = reinterpret_cast<hkpEntityExtendedListeners*>(new FNV_807c50());
    }
    return reinterpret_cast<FNV_807c50*>(entity->m_pExtendedListeners);
}

namespace TelekinesisRemovalDetail {
struct ActivationArray
{
    unsigned int __thiscall GetShortAtOffset4();
    FUN_008079e0_shell*& __thiscall NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(unsigned int index);
};

extern "C" hkpEntity* __fastcall Bipedanim_GetReferenceFlagsOrZero(void* body);

extern "C" int DAT_0119d900;
extern "C" int DAT_011a0eac;

extern "C" void* __cdecl FNV_DynamicCast(void* object, unsigned long displacement, unsigned int sourceType,
                                         unsigned int targetType, unsigned int flags);

}

// Iterates activation listeners on the hkpEntity and calls FUN_00807a10 on any that are telekinesis shells.
// @fnv 0x00807ac0
// src: XBOX_PDB 0x00807ac0
void __cdecl bhkTelekinesisListener_RemoveTelekinesisListeners(void* body)
{
    using namespace TelekinesisRemovalDetail;
    hkpEntity* entity = Bipedanim_GetReferenceFlagsOrZero(body);
    {
        int index;
        for (index = 0; index < (int)reinterpret_cast<ActivationArray*>(
                                    GetOrCreate807c50(entity))
                                    ->GetShortAtOffset4();
             ++index)
        {
            FUN_008079e0_shell* listener =
                reinterpret_cast<ActivationArray*>(GetOrCreate807c50(entity))
                    ->NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt((unsigned int)index);
            {
                FUN_008079e0_shell* telekinesis = reinterpret_cast<FUN_008079e0_shell*>(
                    FNV_DynamicCast(listener, 0, reinterpret_cast<unsigned int>(&DAT_0119d900),
                                    reinterpret_cast<unsigned int>(&DAT_011a0eac), 0));
                if (telekinesis != 0)
                {
                    telekinesis->bhkTelekinesisListener_Finish(entity);
                    index = 0;
                }
            }
        }
    }
}

namespace TelekinesisFinishCurrent {
struct TelekinesisLodView
{
    void BSFadeNode_SetLODMultType(int);
};

struct TelekinesisFadeNodeView : public TelekinesisLodView
{
};

struct TelekinesisReferenceView
{
    virtual void v000() = 0;
    virtual void v001() = 0;
    virtual void v002() = 0;
    virtual void v003() = 0;
    virtual void v004() = 0;
    virtual void v005() = 0;
    virtual void v006() = 0;
    virtual void v007() = 0;
    virtual void v008() = 0;
    virtual void v009() = 0;
    virtual void v010() = 0;
    virtual void v011() = 0;
    virtual void v012() = 0;
    virtual void v013() = 0;
    virtual void v014() = 0;
    virtual void v015() = 0;
    virtual void v016() = 0;
    virtual void v017() = 0;
    virtual void v018() = 0;
    virtual void v019() = 0;
    virtual void v020() = 0;
    virtual void v021() = 0;
    virtual void v022() = 0;
    virtual void v023() = 0;
    virtual void v024() = 0;
    virtual void v025() = 0;
    virtual void v026() = 0;
    virtual void v027() = 0;
    virtual void v028() = 0;
    virtual void v029() = 0;
    virtual void v030() = 0;
    virtual void v031() = 0;
    virtual void v032() = 0;
    virtual void v033() = 0;
    virtual void v034() = 0;
    virtual void v035() = 0;
    virtual void v036() = 0;
    virtual void v037() = 0;
    virtual void v038() = 0;
    virtual void v039() = 0;
    virtual void v040() = 0;
    virtual void v041() = 0;
    virtual void v042() = 0;
    virtual void v043() = 0;
    virtual void v044() = 0;
    virtual void v045() = 0;
    virtual void v046() = 0;
    virtual void v047() = 0;
    virtual void v048() = 0;
    virtual void v049() = 0;
    virtual void v050() = 0;
    virtual void v051() = 0;
    virtual void v052() = 0;
    virtual void v053() = 0;
    virtual void v054() = 0;
    virtual void v055() = 0;
    virtual void v056() = 0;
    virtual void v057() = 0;
    virtual void v058() = 0;
    virtual void v059() = 0;
    virtual void v060() = 0;
    virtual void v061() = 0;
    virtual void v062() = 0;
    virtual void v063() = 0;
    virtual void v064() = 0;
    virtual void v065() = 0;
    virtual void v066() = 0;
    virtual void v067() = 0;
    virtual void v068() = 0;
    virtual void v069() = 0;
    virtual void v070() = 0;
    virtual void v071() = 0;
    virtual void v072() = 0;
    virtual void v073() = 0;
    virtual void v074() = 0;
    virtual void v075() = 0;
    virtual void v076() = 0;
    virtual void v077() = 0;
    virtual void v078() = 0;
    virtual void v079() = 0;
    virtual void v080() = 0;
    virtual void v081() = 0;
    virtual void v082() = 0;
    virtual void v083() = 0;
    virtual void v084() = 0;
    virtual void v085() = 0;
    virtual void v086() = 0;
    virtual void v087() = 0;
    virtual void v088() = 0;
    virtual void v089() = 0;
    virtual void v090() = 0;
    virtual void v091() = 0;
    virtual void v092() = 0;
    virtual void v093() = 0;
    virtual void v094() = 0;
    virtual void v095() = 0;
    virtual void v096() = 0;
    virtual void v097() = 0;
    virtual void v098() = 0;
    virtual void v099() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void* v116() = 0;
};

struct TelekinesisBodyView
{
    void bhkWorldObject_SetCollisionFilter(unsigned int);
};

struct TelekinesisFinishReceiver : ::bhkTelekinesisListener
{
    TelekinesisReferenceView* pRef;
    TelekinesisBodyView* pBody;
    unsigned int m_Filter;
    void bhkTelekinesisListener_Finish(::hkpEntity* entity);
};

extern "C" int DAT_01186044;
extern "C" int DAT_0119ba28;

// If pRef is set, casts its v116() result and calls FUN_00b4dec0(2) on success; then calls FUN_00626cb0, FUN_00807cb0, and deletes this receiver.
// @fnv 0x00807a10
// src: XBOX_PDB 0x00807a10
void TelekinesisFinishReceiver::bhkTelekinesisListener_Finish(::hkpEntity* entity)
{
    TelekinesisFadeNodeView* pavlod;
    void* pav;

    if (pRef)
    {
        pav = pRef->v116();

        pavlod = static_cast<TelekinesisFadeNodeView*>(::TelekinesisRemovalDetail::FNV_DynamicCast(
            pav, 0, reinterpret_cast<unsigned int>(&DAT_01186044), reinterpret_cast<unsigned int>(&DAT_0119ba28), 0));

        if (pavlod)
            pavlod->BSFadeNode_SetLODMultType(2);
    }

    pBody->bhkWorldObject_SetCollisionFilter(m_Filter);

    ::bhkTelekinesisListener_Remove(reinterpret_cast<char*>(this), entity);

    delete reinterpret_cast< ::DelVirt*>(this);
}

}
