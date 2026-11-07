#include "../../../include/TES.h"
#include "../../../include/Actor.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/LoadedAreaBound.h"

// src/havok/unplaced/loadedareabound.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/loadedareabound.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Calls FUN_006270f0, then deletes this with size 0x44 when flags has bit 0 set, and returns this.
// @fnv 0x006270c0
void* LoadedAreaBound::FUN_006270c0(unsigned int flags)
{
    this->FUN_006270f0();
    if (flags & 1)
        operator delete(this, 0x44);
    return this;
}

struct Refr;
struct ObjA
{
    bool FUN_00509420();
    bool FUN_005093f0();
};
struct Refr
{
    int TESObjectREFR_GetSpace();
    bool TESObjectREFR_IsFurniture();
    Refr* FUN_0067f390();
    int PackageLocation_GetLocType();
    void* TESObjectREFR_GetOwner();
    bool TESObjectREFR_IsAnOwner(Actor* a, bool b);
    ObjA* BGSSaveFormBuffer_GetForm();
    int TESObjectREFR_GetFirstFreeMarkerIndex(bool b);
    bool TESObjectREFR_GetMarkerAtIndex(int a, int b);
};
struct Obj44
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual int v008();
    Refr* FUN_009f3390();
};
struct Proc
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual void vtbl116();
    virtual void vtbl117();
    virtual void vtbl118();
    virtual void vtbl119();
    virtual void vtbl120();
    virtual void vtbl121();
    virtual void vtbl122();
    virtual void vtbl123();
    virtual void vtbl124();
    virtual void vtbl125();
    virtual void vtbl126();
    virtual void vtbl127();
    virtual void vtbl128();
    virtual void vtbl129();
    virtual void vtbl130();
    virtual void vtbl131();
    virtual void vtbl132();
    virtual void vtbl133();
    virtual void vtbl134();
    virtual void vtbl135();
    virtual void vtbl136();
    virtual void vtbl137();
    virtual void vtbl138();
    virtual void vtbl139();
    virtual void vtbl140();
    virtual void vtbl141();
    virtual void vtbl142();
    virtual void vtbl143();
    virtual void vtbl144();
    virtual void vtbl145();
    virtual void vtbl146();
    virtual void vtbl147();
    virtual void vtbl148();
    virtual void vtbl149();
    virtual void vtbl150();
    virtual void vtbl151();
    virtual void vtbl152();
    virtual void vtbl153();
    virtual void vtbl154();
    virtual void vtbl155();
    virtual void vtbl156();
    virtual Obj44* v274();
    virtual void vtbl158();
    virtual void vtbl159();
    virtual void vtbl160();
    virtual void v284(int a);
    virtual void v288(Actor* a, int b);
    virtual void vtbl163();
    virtual void vtbl164();
    virtual void vtbl165();
    virtual void vtbl166();
    virtual void vtbl167();
    virtual void vtbl168();
    virtual void vtbl169();
    virtual void vtbl170();
    virtual void vtbl171();
    virtual void vtbl172();
    virtual void vtbl173();
    virtual void vtbl174();
    virtual void vtbl175();
    virtual void vtbl176();
    virtual void vtbl177();
    virtual void vtbl178();
    virtual void vtbl179();
    virtual void vtbl180();
    virtual void vtbl181();
    virtual void vtbl182();
    virtual void vtbl183();
    virtual void vtbl184();
    virtual void vtbl185();
    virtual void vtbl186();
    virtual void vtbl187();
    virtual void vtbl188();
    virtual void vtbl189();
    virtual void vtbl190();
    virtual void vtbl191();
    virtual void vtbl192();
    virtual void vtbl193();
    virtual void vtbl194();
    virtual void vtbl195();
    virtual void vtbl196();
    virtual void vtbl197();
    virtual void vtbl198();
    virtual void vtbl199();
    virtual void vtbl200();
    virtual void vtbl201();
    virtual void vtbl202();
    virtual void vtbl203();
    virtual void vtbl204();
    virtual void vtbl205();
    virtual void vtbl206();
    virtual void vtbl207();
    virtual void vtbl208();
    virtual void vtbl209();
    virtual void vtbl210();
    virtual void vtbl211();
    virtual void vtbl212();
    virtual void vtbl213();
    virtual void vtbl214();
    virtual void vtbl215();
    virtual void vtbl216();
    virtual void vtbl217();
    virtual void vtbl218();
    virtual void vtbl219();
    virtual void vtbl220();
    virtual void vtbl221();
    virtual void vtbl222();
    virtual void vtbl223();
    virtual void vtbl224();
    virtual void vtbl225();
    virtual void vtbl226();
    virtual void vtbl227();
    virtual void vtbl228();
    virtual void vtbl229();
    virtual void vtbl230();
    virtual void vtbl231();
    virtual void vtbl232();
    virtual void vtbl233();
    virtual void vtbl234();
    virtual void vtbl235();
    virtual void vtbl236();
    virtual void vtbl237();
    virtual void vtbl238();
    virtual void vtbl239();
    virtual void vtbl240();
    virtual void vtbl241();
    virtual void vtbl242();
    virtual void vtbl243();
    virtual void vtbl244();
    virtual void vtbl245();
    virtual void vtbl246();
    virtual void vtbl247();
    virtual void vtbl248();
    virtual void vtbl249();
    virtual void vtbl250();
    virtual void vtbl251();
    virtual void vtbl252();
    virtual void vtbl253();
    virtual void vtbl254();
    virtual void vtbl255();
    virtual void vtbl256();
    virtual void vtbl257();
    virtual void vtbl258();
    virtual void vtbl259();
    virtual void vtbl260();
    virtual void vtbl261();
    virtual void vtbl262();
    virtual void vtbl263();
    virtual void vtbl264();
    virtual void vtbl265();
    virtual void vtbl266();
    virtual void vtbl267();
    virtual void vtbl268();
    virtual void vtbl269();
    virtual void vtbl270();
    virtual void vtbl271();
    virtual void vtbl272();
    virtual void vtbl273();
    virtual void vtbl274();
    virtual void vtbl275();
    virtual void vtbl276();
    virtual void vtbl277();
    virtual void vtbl278();
    virtual void vtbl279();
    virtual void vtbl280();
    virtual void vtbl281();
    virtual void vtbl282();
    virtual void vtbl283();
    virtual void vtbl284();
    virtual void vtbl285();
    virtual void vtbl286();
    virtual void vtbl287();
    virtual void vtbl288();
    virtual void vtbl289();
    virtual void vtbl290();
    virtual void vtbl291();
    virtual void vtbl292();
    virtual void vtbl293();
    virtual void vtbl294();
    virtual void vtbl295();
    virtual void vtbl296();
    virtual void vtbl297();
    virtual void vtbl298();
    virtual void vtbl299();
    virtual void vtbl300();
    virtual void vtbl301();
    virtual void vtbl302();
    virtual void vtbl303();
    virtual void vtbl304();
    virtual void vtbl305();
    virtual void vtbl306();
    virtual void vtbl307();
    virtual void vtbl308();
    virtual int v4d4();
    virtual void vtbl310();
    virtual void vtbl311();
    virtual void vtbl312();
    virtual void vtbl313();
    virtual void vtbl314();
    virtual void vtbl315();
    virtual void vtbl316();
    virtual void vtbl317();
    virtual void vtbl318();
    virtual void vtbl319();
    virtual void vtbl320();
    virtual void vtbl321();
    virtual void vtbl322();
    virtual void vtbl323();
    virtual void vtbl324();
    virtual Refr* v514();
    Refr* FUN_0045cd60();
};
struct Pkg
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual bool v13c(Actor* a, int b, float c, int e);
    int FUN_0041ca90();
};
struct TopicArr
{
    unsigned int ProcessArray_GetProcessLevelTail(unsigned int a);
    Actor* ProcessArray_GetItem(unsigned int i);
};
struct MgrNode
{
    bool FUN_008256d0();
    Refr** FUN_006815c0();
    void RemoveMatchingItem(Refr** pp);
    MgrNode* FUN_00726070();
};
struct IOMgr
{
    void LoadQueuedPriority(int a);
};
extern TES* DAT_011dea10;
extern IOMgr* DAT_01202d98;
void* __fastcall TESObjectREFR_GetWorldSpace(Actor* a);
void __cdecl FUN_006d6f80(void* a, void* b, NiPoint3* c, NiPoint3* d);
struct ThisCls
{
    int m_00;
    TopicArr m_04;
    void ProcessLists_PlaceActorsinBedsOrChairs();
};
// @fnv 0x00972d30
// src: XBOX_PDB 0x00972d30
void ThisCls::ProcessLists_PlaceActorsinBedsOrChairs()
{
    bool resultFlag;
    {
        MgrNode* iter = DAT_011dea10->TES_GetBedChairList();
        Refr* currentReference;
        currentReference = 0;
        ObjA* chosen;
        chosen = 0;
        {
            resultFlag = 0;
            Actor* b;
            b = 0;
            int slot;
            for (slot = 0; slot < m_04.ProcessArray_GetProcessLevelTail(0); slot++)
            {
                Actor* j;
                b = m_04.ProcessArray_GetItem(slot);
                j = 0;
                if (!!b)
                {
                    if (b->IsActor())
                        j = b;
                }
                if (j != 0)
                {
                    if (!j->HasHealth(false))
                    {
                        if (j->IsCharacter())
                        {
                            if (!j->IsMoving_004938e0())
                            {
                                if (!j->FUN_008a3b30())
                                {
                                    if (j->GetSitSleepState() == 0)
                                    {
                                        if (((Proc*)j->FUN_008d8520())->FUN_0045cd60() != 0)
                                            continue;
                                        {
                                            j->FUN_008c3c40(0, 0);
                                            int pObj4 = (int)j->TESObjectREFR_GetSpace();
                                            Refr* accepted = 0;
                                            bool visible = false;
                                            bool _x = false;
                                            Refr* refr38;
                                            Refr* found = j->Actor_GetCurrentPackageLocation();
                                            refr38 = j->Actor_GetCurrentPackageTarget();
                                            Pkg* tmp26 = (Pkg*)j->FUN_009344a0();
                                            if (!!tmp26)
                                            {
                                                if (tmp26->FUN_0041ca90() == 13)
                                                {
                                                    Obj44* p5c;
                                                    p5c = ((Proc*)j->FUN_008d8520())->v274();
                                                    if (0 != p5c)
                                                    {
                                                        if (p5c->v008() == 13)
                                                        {
                                                            Obj44* tmp78;
                                                            tmp78 = p5c;
                                                            refr38 = (Refr*)tmp78->FUN_009f3390();
                                                        }
                                                    }
                                                }
                                            }
                                            Refr* q = 0;
                                            if (found != 0)
                                                q = found->FUN_0067f390();
                                            if (found != 0)
                                            {
                                                if (found->PackageLocation_GetLocType() == 6)
                                                    q = (Refr*)j->TESObjectREFR_GetLinkedRef();
                                            }
                                            if (!q)
                                            {
                                                q = j->FUN_008d8520() ? ((Proc*)j->FUN_008d8520())->v514() : 0;
                                            }
                                            long _object;
                                            _object = ((Proc*)j->FUN_008d8520())->v4d4();
                                            unsigned int idx13 = -1;
                                            if (refr38 != 0 && refr38->TESObjectREFR_IsFurniture() &&
                                                refr38->TESObjectREFR_GetSpace() == pObj4)
                                            {
                                                accepted = refr38;
                                                chosen = accepted->BGSSaveFormBuffer_GetForm();
                                                if (chosen->FUN_00509420())
                                                    visible = true;
                                                idx13 = accepted->TESObjectREFR_GetFirstFreeMarkerIndex(true);
                                                if (idx13 == -1 || !accepted->TESObjectREFR_GetMarkerAtIndex(idx13, _object))
                                                {
                                                    accepted = 0;
                                                    _x = true;
                                                }
                                            }
                                            else if (q != 0 && q->TESObjectREFR_IsFurniture() && q->TESObjectREFR_GetSpace() == pObj4)
                                            {
                                                accepted = q;
                                                chosen = accepted->BGSSaveFormBuffer_GetForm();
                                                if (chosen->FUN_00509420())
                                                    visible = true;
                                                idx13 = accepted->TESObjectREFR_GetFirstFreeMarkerIndex(true);
                                                if (idx13 == -1 || !accepted->TESObjectREFR_GetMarkerAtIndex(idx13, _object))
                                                {
                                                    accepted = 0;
                                                    _x = true;
                                                }
                                            }
                                            else if (tmp26 != 0 && tmp26->FUN_0041ca90() == 4 &&
                                                     tmp26->v13c(j, 0, -1.0f, 0))
                                            {
                                                if (!j->Actor_IsSleeping())
                                                {
                                                    ((Proc*)j->FUN_008d8520())->v284(1);
                                                }
                                                while (0 != iter && !iter->FUN_008256d0() && accepted == 0)
                                                {
                                                    currentReference = *iter->FUN_006815c0();
                                                    bool flag49 = false;
                                                    if (currentReference->TESObjectREFR_GetSpace() == pObj4)
                                                    {
                                                        if (currentReference->TESObjectREFR_GetOwner() == 0 ||
                                                            currentReference->TESObjectREFR_IsAnOwner(j, true))
                                                        {
                                                            chosen = currentReference->BGSSaveFormBuffer_GetForm();
                                                            if (chosen->FUN_00509420())
                                                            {
                                                                idx13 = currentReference->TESObjectREFR_GetFirstFreeMarkerIndex(true);
                                                                if (idx13 == -1 ||
                                                                    !currentReference->TESObjectREFR_GetMarkerAtIndex(idx13, _object))
                                                                {
                                                                    iter->RemoveMatchingItem(&currentReference);
                                                                    iter = DAT_011dea10->TES_GetBedChairList();
                                                                    flag49 = true;
                                                                }
                                                                else
                                                                {
                                                                    accepted = currentReference;
                                                                    visible = true;
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (!flag49)
                                                        iter = iter->FUN_00726070();
                                                }
                                            }
                                            else if (tmp26 != 0 && tmp26->FUN_0041ca90() == 3 &&
                                                     tmp26->v13c(j, 0, -1.0f, 0))
                                            {
                                                if (j->Actor_GetBestFoodItem() != 0)
                                                {
                                                    if (!j->IsEating())
                                                    {
                                                        ((Proc*)j->FUN_008d8520())->v288(j, 1);
                                                        j->Unk_80(1);
                                                    }
                                                    while (iter != 0 && !iter->FUN_008256d0() && accepted == 0)
                                                    {
                                                        currentReference = *iter->FUN_006815c0();
                                                        bool flag4a = false;
                                                        if (currentReference->TESObjectREFR_GetSpace() == pObj4 &&
                                                            currentReference != 0)
                                                        {
                                                            if (currentReference->TESObjectREFR_GetOwner() == 0 ||
                                                                currentReference->TESObjectREFR_IsAnOwner(j, true))
                                                            {
                                                                chosen = currentReference->BGSSaveFormBuffer_GetForm();
                                                                if (chosen->FUN_005093f0())
                                                                {
                                                                    idx13 = currentReference->TESObjectREFR_GetFirstFreeMarkerIndex(true);
                                                                    if (idx13 == -1 ||
                                                                        !currentReference->TESObjectREFR_GetMarkerAtIndex(idx13, _object))
                                                                    {
                                                                        iter->RemoveMatchingItem(&currentReference);
                                                                        iter = DAT_011dea10->TES_GetBedChairList();
                                                                        flag4a = true;
                                                                    }
                                                                    else
                                                                    {
                                                                        accepted = currentReference;
                                                                        visible = false;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        if (!flag4a)
                                                            iter = iter->FUN_00726070();
                                                    }
                                                }
                                            }
                                            if (accepted != 0 && j->GetNiNode() != 0)
                                            {
                                                resultFlag = j->Actor_PutActorInChairBedQuick(accepted, _object, idx13, visible);
                                            }
                                            else if (_x)
                                            {
                                                NiPoint3* _origin;
                                                _origin = (NiPoint3*)static_cast<const MobileObject*>(j)->GetPos();
                                                NiPoint3 pt = *_origin;
                                                FUN_006d6f80(TESObjectREFR_GetWorldSpace(j), j->FUN_008d6f30(), _origin, &pt);
                                                j->TESObjectREFR_SetLocationOnReference(&pt);
                                                j->TESObjectREFR_Update3DPosition();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (resultFlag)
                DAT_01202d98->LoadQueuedPriority(0);
        }
        DAT_011dea10->ClearList();
    }
}

#include <xmmintrin.h>
struct FUN_00437c10
{
    FUN_00437c10();
    __m128 m_00;
    __m128 m_10;
};

struct CF845
{
    CF845(void* p);
    int CFilter_GetLayer();
    int unk;
};

TESObjectREFR* __cdecl TESHavokUtilities_FindCollidableRef(void* p);

struct PickedObj
{
    bool FUN_005609f0();
};

struct Arg1
{
    PickedObj* hkAabb_contains(char* flag, FUN_00437c10* t);
    int hkAabb_overlaps(FUN_00437c10* t);
};

struct ItemObj
{
    void* TESDataHandler_GetWorldSpaceList();
    const char* operator_str();
    void* FUN_007d6bb0();
    void* hkpCollidable_getCollisionFilterInfo();
};

struct Arg2Item
{
    ItemObj* pItem;
};

struct Arg2
{
    int FUN_00726070();
    Arg2Item* NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(int i);
};

struct TargetObj
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
    virtual void vfunc_0x3c(void* effectList, FUN_00437c10* t);
};

struct Arg3
{
    TargetObj* FUN_006286d0();
};

struct FUN_00628df0_class
{
    void ProcessEntries_00628df0(Arg1* a1, Arg2* a2, Arg3* a3);
    void LoadedAreaBound_WarpActor(TESObjectREFR* r);
};

// For each a2 item with a string, calls a3's target vfunc_0x3c; if the a1 checks fail and the item type is 0x1e, passes its REFR to FUN_006295e0.
// @fnv 0x00628df0
// src: GUESS 0x00628df0 (confidence: low)
void FUN_00628df0_class::ProcessEntries_00628df0(Arg1* a1, Arg2* apItems, Arg3* apTarget)
{
    FUN_00437c10 tmp;
    for (int i = 0; i < apItems->FUN_00726070(); ++i)
    {
        ItemObj* p38 = (ItemObj*)apItems->NiTSet_NiControllerSequence_NiTMallocInterface_NiControllerSequence_GetAt(i)->pItem->TESDataHandler_GetWorldSpaceList();
        if (p38->operator_str())
        {
            TargetObj* pTarget = apTarget->FUN_006286d0();
            pTarget->vfunc_0x3c(p38->FUN_007d6bb0(), &tmp);
            char flag;
            if (!a1->hkAabb_contains(&flag, &tmp)->FUN_005609f0() || !a1->hkAabb_overlaps(&tmp))
            {
                CF845 filter(p38->hkpCollidable_getCollisionFilterInfo());
                if (filter.CFilter_GetLayer() == 0x1e)
                {
                    TESObjectREFR* refr = TESHavokUtilities_FindCollidableRef(p38);
                    if (refr && refr->IsActor())
                    {
                        TESObjectREFR* pRefr = refr;
                        this->LoadedAreaBound_WarpActor(pRefr);
                    }
                }
            }
        }
    }
}
