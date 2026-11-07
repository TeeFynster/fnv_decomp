
// src/havok/unplaced/focollisionlistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/focollisionlistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/GO.h"
#include "../../../include/Actor.h"

extern int DAT_0104dd5c;
struct FUN_006234d0
{
    void __thiscall SetVtableAndProcessState_006234f0();
    ~FUN_006234d0();
};
// @fnv 0x006234d0
FUN_006234d0::~FUN_006234d0()
{
    *(int*)this = (int)&DAT_0104dd5c;
    SetVtableAndProcessState_006234f0();
}

extern int DAT_0104dd7c;

struct FUN_006234f0_class
{
    void SetVtableAndProcessState_006234f0();
};

// @fnv 0x006234f0
// src: GUESS 0x006234f0 (confidence: low)
void FUN_006234f0_class::SetVtableAndProcessState_006234f0()
{
    *reinterpret_cast<int**>(this) = &DAT_0104dd7c;
}

extern int DAT_0104dd7c;

struct FUN_00623570_class
{
    int __fastcall hkpContactListener_hkpContactListener();
};

// @fnv 0x00623570
// src: EXE 0x00623570
int __fastcall FUN_00623570_class::hkpContactListener_hkpContactListener()
{
    *reinterpret_cast<int**>(this) = &DAT_0104dd7c;
    return reinterpret_cast<int>(this);
}

struct FUN_00623590_class
{
    void __thiscall FUN_006235c0();
    void* __thiscall FUN_00623590(unsigned int flags);
};
// Calls FUN_006235c0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x00623590
void* __thiscall FUN_00623590_class::FUN_00623590(unsigned int flags)
{
    FUN_006235c0();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern "C" void __cdecl Deallocate(void*);
struct FUN_00623820_class
{
    void __thiscall FUN_00623850();
    void* __thiscall FUN_00623820(unsigned int flags);
};
// @fnv 0x00623820
void* __thiscall FUN_00623820_class::FUN_00623820(unsigned int flags)
{
    FUN_00623850();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct FUN_0042f760
{
    ~FUN_0042f760();
};
struct FUN_00623850
{
    GO a;
    int b;
    FUN_0042f760 c;
    ~FUN_00623850();
};
// Empty destructor for the structure; destroys its members GO and FUN_0042f760.
// @fnv 0x00623850
FUN_00623850::~FUN_00623850()
{}

struct FUN_00623510_class
{
    void* FUN_00623510(unsigned int flags);
};
// @fnv 0x00623510
void* FUN_00623510_class::FUN_00623510(unsigned int flags)
{
    ((FUN_006234d0*)this)->SetVtableAndProcessState_006234f0();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern int DAT_011cc224;

struct SubMember
{
    int m_i00;

    ~SubMember();
};

struct BaseObject
{
    virtual void v00();

    ~BaseObject();
};

struct FUN_006235c0 : BaseObject
{
    SubMember m_kSub;

    void ProcessPendingRequests();

    ~FUN_006235c0();
};

// Clears DAT_011cc224 to 0 and then calls ProcessPendingRequests before the object is destroyed.
// @fnv 0x006235c0
FUN_006235c0::~FUN_006235c0()
{
    DAT_011cc224 = 0;
    ProcessPendingRequests();
}

struct SmartRef
{
    void* Modelloader_GetReferencedThis();
};
struct Request
{
    SmartRef subject;
    float amount;
    SmartRef source;
};
struct RequestList
{
    bool FUN_008256d0();
    Request** FUN_006815c0();
    void FUN_0063f7b0();
};
struct Reference
{
    void* Bipedanim_GetReferenceFlagsOrZero();
};
struct Form
{
    void* FUN_0044ddc0();
};
Form* FUN_004b5a20(void*);
Actor* TESObjectREFR_FindReferenceFor3D(void*);
bool AILinearTaskThreadManager_ShouldQueue3DTask();
struct ActorSystem
{
    void QueueDamageTask(Actor*, float, int);
};
ActorSystem* FUN_004537b0();
extern Actor* g_thePlayer;
struct Processor
{
    unsigned int flags;
    RequestList requests;
    void ProcessRequests();
};
// Drains the request list, applying each positive-amount request to its resolved actor and deleting the request.
// @fnv 0x00623640
void Processor::ProcessRequests()
{
    RequestList* pRequests = &requests;
    while (pRequests && !pRequests->FUN_008256d0())
    {
        Request* item = *pRequests->FUN_006815c0();
        pRequests->FUN_0063f7b0();
        if (item->subject.Modelloader_GetReferencedThis() && item->amount > 0.0)
        {
            void* form = static_cast<Reference*>(item->subject.Modelloader_GetReferencedThis())->Bipedanim_GetReferenceFlagsOrZero();
            Form* ref = form ? FUN_004b5a20(form) : 0;
            void* actor = ref ? ref->FUN_0044ddc0() : 0;
            Actor* base = actor ? TESObjectREFR_FindReferenceFor3D(actor) : 0;
            if (base)
            {
                base->vfn_164(reinterpret_cast<int>(item->source.Modelloader_GetReferencedThis()));
                if (!AILinearTaskThreadManager_ShouldQueue3DTask())
                    base->DamageObject(item->amount, false);
                else
                    FUN_004537b0()->QueueDamageTask(base, item->amount, 0);
                if (base->FUN_00477ba0() && item->source.Modelloader_GetReferencedThis() &&
                    static_cast<SmartRef*>(item->source.Modelloader_GetReferencedThis())->Modelloader_GetReferencedThis() == g_thePlayer)
                    g_thePlayer->SetEffectValue(10, 8.0f, 0);
            }
        }
        delete reinterpret_cast<FUN_00623850*>(item);
    }
}

struct S_006240f0_Form
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
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
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual bool IsActor();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual int GetKind();
};
struct S_006240f0_Char : S_006240f0_Form
{
    void HandleContactHit(int a);
};
struct S_006240f0
{
    void ApplyToCharacter(S_006240f0_Form* form, int arg);
};

// If form is an actor of kind 3, casts it to a character and calls HandleContactHit with arg.
// @fnv 0x006240f0
void S_006240f0::ApplyToCharacter(S_006240f0_Form* form, int arg)
{
    if (form && form->IsActor())
    {
        Actor* actor = (Actor*)form;
        if (((S_006240f0_Form*)actor)->GetKind() == 3)
        {
            S_006240f0_Char* pChar = (S_006240f0_Char*)actor;
            pChar->HandleContactHit(arg);
        }
    }
}

struct HitForm
{
    float hkpRigidBody_getMass();
};
struct HitRefTarget;
HitRefTarget* __cdecl bhkEntity_Getbhk(HitForm* pkForm);
float __cdecl NiAbs_00408820(float f);
float __cdecl ComputeDistanceFactor(float fScale, float fAmount);

struct HitActor
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void* GetHandle();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual bool IsDead();

    bool TESForm_GetDestructible();
    bool FUN_00477ba0();
};

struct HitSetting
{
    float* Setting_Float_00403e20();
};
extern HitSetting g_s_011ce75c;

template <class T> struct HitPtr
{
    T* m_pObject;
    HitPtr& FUN_0066b0d0(T* pObject);
};
struct HitHandle
{
    int m_iHandle;
    void AssignRetainedObject(void* pkHandle);
};
struct HitEntry
{
    HitPtr<HitRefTarget> m_spReferencedObject;
    float m_fAmount;
    HitHandle m_kSource;
    HitEntry* FUN_00623bd0();
    HitEntry();
    void* operator new(unsigned int uiSize);
    void operator delete(void* pvMem);
};
struct HitList
{
    void FUN_005ae3d0(HitEntry* const& pkEntry);
};

struct HitTrackerImpl
{
    int unk00;
    HitList m_kEntries;
    void AddHitEntries(float fAmount, HitForm* pkFormA, HitForm* pkFormB, HitActor* pkActorA, HitActor* pkActorB);
};

// @fnv 0x006238b0
void HitTrackerImpl::AddHitEntries(float fAmount, HitForm* pkFormA, HitForm* pkFormB, HitActor* pkActorA,
                                   HitActor* pkActorB)
{
    float fAbs = NiAbs_00408820(fAmount);
    if (fAbs < *g_s_011ce75c.Setting_Float_00403e20())
        return;
    if (pkActorA && pkActorA->TESForm_GetDestructible() && !pkActorA->FUN_00477ba0() && !pkActorA->IsDead() &&
        (!pkActorB || !pkActorB->IsDead()))
    {
        float fScaleX = pkFormB->hkpRigidBody_getMass();
        if (fScaleX == 0.0)
            fScaleX = 10000.0f;
        float fValueVal2 = ComputeDistanceFactor(fScaleX, fAbs);
        if (fValueVal2 > 0.0)
        {
            HitEntry* pkEntry = new HitEntry;
            pkEntry->m_spReferencedObject.FUN_0066b0d0(bhkEntity_Getbhk(pkFormA));
            pkEntry->m_fAmount = fValueVal2;
            pkEntry->m_kSource.AssignRetainedObject(pkActorB ? pkActorB->GetHandle() : 0);
            m_kEntries.FUN_005ae3d0(pkEntry);
        }
    }
    if (pkActorB && pkActorB->TESForm_GetDestructible() && !pkActorB->FUN_00477ba0() && !pkActorB->IsDead() &&
        (!pkActorA || !pkActorA->IsDead()))
    {
        float fScale2 = pkFormA->hkpRigidBody_getMass();
        if (fScale2 == 0.0)
            fScale2 = 10000.0f;
        float fSecondFunctionValue = ComputeDistanceFactor(fScale2, fAbs);
        if (fSecondFunctionValue > 0.0)
        {
            HitEntry* pkEntry2 = new HitEntry;
            pkEntry2->m_spReferencedObject.FUN_0066b0d0(bhkEntity_Getbhk(pkFormB));
            pkEntry2->m_fAmount = fSecondFunctionValue;
            pkEntry2->m_kSource.AssignRetainedObject(pkActorA ? pkActorA->GetHandle() : 0);
            m_kEntries.FUN_005ae3d0(pkEntry2);
        }
    }
}

struct BaseNoVtable
{
    unsigned int unk00;

    BaseNoVtable(int value);
    ~BaseNoVtable();
};

struct SubHelper
{
    unsigned int unk00;

    SubHelper(int value);
    ~SubHelper();
    void AssignRetainedObject(int value);
};

struct FUN_00623bd0 : BaseNoVtable
{
    float m_04;
    SubHelper m_08;

    FUN_00623bd0();
    void FUN_0066b0d0(int value);
};

// Initializes the base and helper subobjects with 0, calls FUN_0066b0d0(0), sets m_04 to 0.0f and calls FUN_0042f780(0) on m_08.
// @fnv 0x00623bd0
FUN_00623bd0::FUN_00623bd0() : BaseNoVtable(0), m_08(0)
{
    FUN_0066b0d0(0);
    m_04 = 0.0f;
    m_08.AssignRetainedObject(0);
}

struct RequestEntry
{
    void* FUN_00623820(unsigned int flags);
};

// @fnv 0x00623c50
void FUN_006235c0::ProcessPendingRequests()
{
    while (!((RequestList*)&m_kSub)->FUN_008256d0())
    {
        Request* b = *((RequestList*)&m_kSub)->FUN_006815c0();
        Request* a = b;
        a ? ((RequestEntry*)a)->FUN_00623820(1) : 0;
        ((RequestList*)&m_kSub)->FUN_0063f7b0();
    }
}

// ProcessHit: thiscall, one stack arg, /MT /Od /GS /EHsc

extern float DAT_01017870;
extern double DAT_01012070;
extern int DAT_011cc270;

struct Ctx_623cb0
{
    void BGSPrimitive_EvaluateValue_006240d0();
    int m_00;
    int m_04;
    int m_08;
};

struct Key_623cb0
{
    void FUN_008c71b0(void* v);
    int CFilter_GetGroup();
    unsigned char CFilter_QBipLayer();
    int CFilter_GetBipedPart();
    void* m_00;
};

struct Gen_623cb0
{
    void* GetLastNode();
    float hkContactPointMaterial_getFriction();
    int hkpCollidable_getType();
    void* hkpCollidable_getCollisionFilterInfo();
    float FUN_00450410();
};

struct Rec_623cb0
{
    void* m_00;
    void* m_04;
    int m_08;
    int m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    float m_1c;
    int m_20;
};

// Stores two signed-byte results from FUN_0062b150; shared Pair instead has two int fields and methods.
struct CollisionBodyResults
{
    signed char a;
    signed char b;
};

struct Owner_623cb0
{
    int m_00;
    void ProcessHit(Rec_623cb0* a1);
    void AddHitEntries(float f, void* a, void* b, void* c, void* d);
};

unsigned char TESHavokUtilities_GetMaterial(void* obj, void* ctx);
void FUN_00458620(Ctx_623cb0* ctx, void* req);
float HK2NI(float v);
float NiAbs_00408820(float v);
void ImpactMixer_PlayCollisionSound(Ctx_623cb0* ctx);
void* hkpGetRigidBody(void* obj);

// Does nothing if a1->m_20 is set; unless early checks return, calls AddHitEntries with a1->m_1c and the two nodes, then ApplyToCharacter for both.
// @fnv 0x00623cb0
void Owner_623cb0::ProcessHit(Rec_623cb0* apHitRecord)
{
    void* node;
    Form* item;
    void* entry;
    Actor* cell3;
    Actor* hold;
    void* cat;
    void* keyTmp;
    void* key2;
    void* cell2;
    Form* idx;
    Ctx_623cb0 ctx2;
    float cur;
    float extra;
    CollisionBodyResults fval;
    int count;
    void* mid;
    void* node1;

    if (apHitRecord->m_20 != 0)
    {
        return;
    }
    ctx2.BGSPrimitive_EvaluateValue_006240d0();
    cur = NiAbs_00408820(HK2NI(apHitRecord->m_1c));
    keyTmp = ((Gen_623cb0*)apHitRecord->m_00)->GetLastNode();
    entry = ((Gen_623cb0*)apHitRecord->m_04)->GetLastNode();

    if (cur >= ((Gen_623cb0*)&DAT_011cc270)->FUN_00450410() && cur >= DAT_01012070)
    {
        if (keyTmp != 0 && entry != 0)
        {
            Key_623cb0 key1;
            Key_623cb0 key8;
            key1.FUN_008c71b0(((Gen_623cb0*)keyTmp)->hkpCollidable_getCollisionFilterInfo());
            key8.FUN_008c71b0(((Gen_623cb0*)entry)->hkpCollidable_getCollisionFilterInfo());
            if (key1.CFilter_GetGroup() == key8.CFilter_GetGroup())
            {
                if (key1.CFilter_QBipLayer())
                {
                    return;
                }
            }
            else if (key1.CFilter_QBipLayer())
            {
                if (key1.CFilter_GetBipedPart() == 0x11)
                {
                    return;
                }
            }
            else if (key8.CFilter_QBipLayer())
            {
                if (key8.CFilter_GetBipedPart() == 0x11)
                {
                    return;
                }
            }
        }
        FUN_00458620(&ctx2, ((RequestList*)apHitRecord->m_10)->FUN_006815c0());
        extra = apHitRecord->m_18 ? ((Gen_623cb0*)((char*)apHitRecord->m_18 + 8))->hkContactPointMaterial_getFriction() : DAT_01017870;
        fval.a = TESHavokUtilities_GetMaterial(apHitRecord->m_00, &ctx2);
        fval.b = TESHavokUtilities_GetMaterial(apHitRecord->m_04, &ctx2);
        mid = 0;
        node1 = 0;
        if (keyTmp != 0 && ((Gen_623cb0*)keyTmp)->hkpCollidable_getType() == 1)
        {
            void* src = hkpGetRigidBody(keyTmp);
            if (src != 0)
            {
                mid = bhkEntity_Getbhk((HitForm*)src);
            }
        }
        if (entry != 0 && ((Gen_623cb0*)entry)->hkpCollidable_getType() == 1)
        {
            void* src = hkpGetRigidBody(entry);
            if (src != 0)
            {
                node1 = bhkEntity_Getbhk((HitForm*)src);
            }
        }
        count = (fval.a + 1) * (fval.b + 1);
        ImpactMixer_PlayCollisionSound(&ctx2);
    }

    node = hkpGetRigidBody(keyTmp);
    item = node ? FUN_004b5a20(node) : 0;
    cat = item ? item->FUN_0044ddc0() : 0;
    cell3 = cat ? TESObjectREFR_FindReferenceFor3D(cat) : 0;
    cell2 = hkpGetRigidBody(entry);
    idx = cell2 ? FUN_004b5a20(cell2) : 0;
    key2 = idx ? idx->FUN_0044ddc0() : 0;
    hold = key2 ? TESObjectREFR_FindReferenceFor3D(key2) : 0;
    AddHitEntries(apHitRecord->m_1c, node, cell2, cell3, hold);
    ((S_006240f0*)this)->ApplyToCharacter((S_006240f0_Form*)cell3, (int)apHitRecord);
    ((S_006240f0*)this)->ApplyToCharacter((S_006240f0_Form*)hold, (int)apHitRecord);
}

struct FUN_00623540 : FUN_006234d0
{
    virtual ~FUN_00623540();
};
// @fnv 0x00623540
FUN_00623540::~FUN_00623540()
{}
